// Banjo-Tooie's n_audio ABI, from the dispatch table at DMEM 0x10.
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "mixer.h"
#include "guest.h"

static BtMixerWrite *deferred;
// Both filter entry points issue a store from a partly overwritten vector. These lanes survive tasks.
static int16_t scratch29[8], scratch30[8];

enum { BASE = 0x500, FRAME = 0x170, PARAM = 0xfa0 };

static int16_t sample(const uint8_t *d, unsigned a) {
    return (int16_t)((unsigned)d[a & 0xfff] << 8 | d[(a + 1) & 0xfff]);
}

static void put(uint8_t *d, unsigned a, int value) {
    d[a & 0xfff] = (uint8_t)((uint16_t)value >> 8);
    d[(a + 1) & 0xfff] = (uint8_t)value;
}

static void load_vector(int16_t v[8], const uint8_t *d, unsigned a) {
    unsigned n = (16 - (a & 15)) / 2;
    for (unsigned i = 0; i < n; i++) v[i] = sample(d, a + 2 * i);
}

static unsigned word(const uint8_t *d, unsigned a) {
    return (uint32_t)(uint16_t)sample(d, a) << 16 | (uint16_t)sample(d, a + 2);
}

static void put_word(uint8_t *d, unsigned a, unsigned value) {
    put(d, a, value >> 16);
    put(d, a + 2, value);
}

static int16_t clamp(int64_t v) {
    return v < -32768 ? -32768 : v > 32767 ? 32767 : (int16_t)v;
}

// SP hardware rounds both addresses down and byte counts up to eight.
static void transfer(uint8_t *d, uint8_t *ram, unsigned a, unsigned g, unsigned size, int save) {
    a &= 0xff8;
    g &= 0xfffff8;
    size = (size + 7) & ~7u;
    if (save && deferred) {
        if (size > sizeof deferred->bytes || deferred->size) bt_fatal("unexpected mixer DMA write (%u)", size);
        deferred->address = g;
        deferred->size = size;
        for (unsigned i = 0; i < size; i++) deferred->bytes[i] = d[(a + i) & 0xfff];
        return;
    }
    for (unsigned i = 0; i < size; i++) {
        unsigned di = (a + i) & 0xfff, ri = (g + i) & 0xffffff;
        if (save)
            ram[ri] = d[di];
        else
            d[di] = ram[ri];
    }
}

static void adpcm(uint8_t *d, uint8_t *ram, uint32_t cmd, uint32_t arg) {
    unsigned in = BASE + ((arg >> 12) & 15), out = BASE + (arg & 0xfff);
    unsigned bytes = (arg >> 16) & 0xfff, flags = arg >> 28;
    if (flags & 1) {
        for (unsigned i = 0; i < 32; i++) d[(out + i) & 0xfff] = 0;
    } else {
        transfer(d, ram, out, flags & 2 ? word(d, 0xffc) : cmd, 32, 0);
    }
    int prev2 = sample(d, out + 28), prev1 = sample(d, out + 30);
    for (unsigned block = 0; block < bytes; block += 32) {
        unsigned header = d[in++ & 0xfff], book = 0x400 + (header & 15) * 32;
        unsigned scale = header >> 4;
        out += 32;
        for (unsigned group = 0; group < 2; group++) {
            int delta[8];
            for (unsigned i = 0; i < 8; i++) {
                unsigned packed = d[(in + i / 2) & 0xfff];
                int nibble = (int)((i & 1 ? packed : packed >> 4) & 15);
                delta[i] = ((nibble ^ 8) - 8) * (1 << (scale < 12 ? scale : 12));
                (group ? scratch29 : scratch30)[i] = (int16_t)delta[i];
            }
            in += 4;
            for (unsigned i = 0; i < 8; i++) {
                int64_t sum = (int64_t)delta[i] * 2048 + (int64_t)sample(d, book + 2 * i) * prev2 +
                              (int64_t)sample(d, book + 16 + 2 * i) * prev1;
                for (unsigned j = 0; j < i; j++) sum += (int64_t)sample(d, book + 16 + 2 * (i - j - 1)) * delta[j];
                put(d, out + group * 16 + i * 2, clamp((int32_t)(uint32_t)sum >> 11));
            }
            prev2 = sample(d, out + group * 16 + 12);
            prev1 = sample(d, out + group * 16 + 14);
        }
    }
    transfer(d, ram, out, cmd, 32, 1);
}

static int frac_mul(int a, int b) {
    return clamp(((int64_t)a * b + 0x4000) >> 15);
}

static int mix_sample(int old, int src, int gain) {
    return clamp(((int64_t)old * 32767 + (int64_t)src * gain + 0x4000) >> 15);
}

static void envelope(uint8_t *d, uint8_t *ram, uint32_t cmd, uint32_t arg) {
    int init = cmd >> 16 & 1;
    load_vector(scratch30, d, 0xb0);
    if (!init) transfer(d, ram, PARAM, arg, 80, 0);
    for (unsigned ch = 0; ch < 2; ch++) {
        unsigned params = PARAM + 0x40 + ch * 6;
        int target = sample(d, params), step = sample(d, params + 2);
        unsigned frac_step = (uint16_t)sample(d, params + 4);
        int dry = sample(d, PARAM + 0x4c), wet = sample(d, PARAM + 0x4e);
        for (unsigned lane = 0; lane < 8; lane++) {
            unsigned state = PARAM + 32 * ch + 2 * lane;
            int gain = sample(d, state);
            unsigned frac = (uint16_t)sample(d, state + 16);
            if (init) {
                unsigned progress = (uint16_t)sample(d, 0xb0 + 2 * lane);
                int start = ch ? (int16_t)cmd : sample(d, PARAM + 0x50);
                int64_t acc = (int64_t)start * 65536 + (int64_t)progress * step + (progress * frac_step >> 16);
                gain = clamp(acc >> 16);
                frac = (acc >> 16) > 32767 ? 65535 : (acc >> 16) < -32768 ? 0 : (uint16_t)acc;
            }
            for (unsigned i = lane; i < FRAME / 2; i += 8) {
                if (!init || i != lane) {
                    frac += frac_step;
                    gain = clamp(gain + step + (int)(frac >> 16));
                    frac &= 65535;
                }
                if (step < 0 ? gain < target : gain > target) gain = target;
                int src = sample(d, BASE + i * 2);
                unsigned out = 0x9e0 + ch * FRAME + i * 2;
                put(d, out, mix_sample(sample(d, out), src ^ -(dry & 1), frac_mul(gain, dry)));
                out += FRAME * 2;
                put(d, out, mix_sample(sample(d, out), src ^ -(wet & 1), frac_mul(gain, wet)));
            }
            put(d, state, gain);
            put(d, state + 16, frac);
        }
    }
    load_vector(scratch29, d, 0x9e0 + FRAME - 16);
    transfer(d, ram, PARAM, arg, 80, 1);
}

static void resample(uint8_t *d, uint8_t *ram, uint32_t cmd, uint32_t arg) {
    load_vector(scratch29, d, 0x70);
    load_vector(scratch30, d, 0x60);
    unsigned base = 0x4f8 + (arg >> 2 & 0xfff);
    unsigned out = arg & 3 ? 0x670 : BASE;
    unsigned pitch = 2 * (arg >> 14 & 0xffff);
    unsigned phase = 0;
    if (!(arg >> 30)) {
        transfer(d, ram, PARAM, cmd, 16, 0);
        phase = (uint16_t)sample(d, PARAM + 8);
    }
    for (unsigned i = 0; i < 8; i++) d[(base + i) & 0xfff] = arg >> 30 ? 0 : d[PARAM + i];
    for (unsigned group = 0; group <= FRAME / 2; group += 8) {
        int result[8];
        for (unsigned lane = 0; lane < 8; lane++) {
            unsigned f = phase + (group + lane) * pitch;
            unsigned in = base + 2 * (f >> 16);
            unsigned table = 0xc0 + (f >> 10 & 63) * 8;
            put(d, 0xfb0 + lane * 2, in);
            put(d, 0xfc0 + lane * 2, table);
            int a = frac_mul(sample(d, in), sample(d, table));
            int b = frac_mul(sample(d, in + 2), sample(d, table + 2));
            int c = frac_mul(sample(d, in + 4), sample(d, table + 4));
            int e = frac_mul(sample(d, in + 6), sample(d, table + 6));
            result[lane] = clamp(clamp(a + b) + clamp(c + e));
        }
        if (group < FRAME / 2)
            for (unsigned lane = 0; lane < 8; lane++) put(d, out + 2 * (group + lane), result[lane]);
    }
    phase += FRAME / 2 * pitch;
    unsigned in = base + 2 * (phase >> 16);
    for (unsigned i = 0; i < 8; i++) d[PARAM + i] = d[(in + i) & 0xfff];
    put(d, PARAM + 8, phase);
    transfer(d, ram, PARAM, cmd, 16, 1);
}

// Two feed-forward taps plus the symmetric second delay, then the two feedback taps.
// Each VMULF, doubled feedback contribution and VADD saturates separately.
static void iir(uint8_t *d, uint8_t *ram, uint32_t cmd, uint32_t arg) {
    unsigned out = BASE + (cmd & 0xffff);
    int x2 = 0, x1 = 0, y2 = 0, y1 = 0;
    if (!(cmd & 0x10000)) {
        transfer(d, ram, PARAM, arg, 8, 0);
        x2 = sample(d, PARAM);
        x1 = sample(d, PARAM + 2);
        y2 = sample(d, PARAM + 4);
        y1 = sample(d, PARAM + 6);
    }
    int b0 = sample(d, 0x400), b1 = sample(d, 0x402);
    int a1 = sample(d, 0x410), a2 = sample(d, 0x412);
    if (!word(d, 0x402)) { // IMEM 0x180c takes the short path straight to the state write.
        load_vector(scratch30, d, out);
        scratch29[7] = (int16_t)y1;
        for (unsigned i = 0; i < 8; i++) put(d, out - 16 + 2 * i, scratch29[i]);
        put(d, PARAM, x2);
        put(d, PARAM + 2, x1);
        put(d, PARAM + 4, scratch29[6]);
        put(d, PARAM + 6, y1);
        transfer(d, ram, PARAM, arg, 8, 1);
        return;
    }
    for (unsigned i = 0; i < FRAME; i += 2) {
        int x = sample(d, out + i);
        int in = clamp(clamp(frac_mul(x, b0) + frac_mul(x1, b1)) + frac_mul(x2, b0));
        int y = clamp(clamp(in + clamp(2 * frac_mul(y2, a2))) + clamp(2 * frac_mul(y1, a1)));
        put(d, out + i, y);
        x2 = x1;
        x1 = x;
        y2 = y1;
        y1 = y;
    }
    load_vector(scratch29, d, out + FRAME - 16);
    for (unsigned i = 0; i < 8; i++) scratch30[i] = frac_mul(sample(d, out + FRAME + 2 * i), b0);
    put(d, PARAM, x2);
    put(d, PARAM + 2, x1);
    put(d, PARAM + 4, y2);
    put(d, PARAM + 6, y1);
    transfer(d, ram, PARAM, arg, 8, 1);
}

static void pole(uint8_t *d, uint8_t *ram, uint32_t cmd, uint32_t arg) {
    unsigned out = arg >> 24 ? 0x670 : BASE;
    int gain = (int16_t)cmd, coeff[8], previous[8] = {0};
    unsigned factor = (uint16_t)(gain * 4);
    for (unsigned i = 0; i < 8; i++) {
        coeff[i] = sample(d, 0x410 + 2 * i);
        put(d, 0x410 + 2 * i, (coeff[i] * (int64_t)factor) >> 16);
    }
    if (!((cmd << 2) & 0x10000)) {
        transfer(d, ram, PARAM, arg, 8, 0);
        for (unsigned i = 0; i < 4; i++) previous[i] = scratch30[i];
        for (unsigned i = 0; i < 4; i++) previous[4 + i] = sample(d, PARAM + 2 * i);
    }
    for (unsigned block = 0; block < FRAME; block += 16) {
        int samples[8], next[8];
        for (unsigned i = 0; i < 8; i++) samples[i] = sample(d, out + block + 2 * i);
        for (unsigned i = 0; i < 8; i++) {
            int64_t acc = (int64_t)coeff[i] * previous[7] + (int64_t)gain * samples[i];
            for (unsigned j = 0; j < i; j++) acc += (int64_t)sample(d, 0x410 + 2 * (i - j - 1)) * samples[j];
            next[i] = clamp((int32_t)(uint32_t)acc >> 14);
            scratch29[i] = (int16_t)acc;
        }
        for (unsigned i = 0; i < 8; i++) put(d, out + block - 16 + 2 * i, previous[i]);
        memcpy(previous, next, sizeof next);
    }
    for (unsigned i = 0; i < 8; i++) {
        scratch30[i] = previous[i];
        put(d, out + FRAME - 16 + 2 * i, previous[i]);
    }
    transfer(d, ram, out + FRAME - 8, arg, 8, 1);
}

static int mixer_command(uint8_t *d, uint8_t *ram, uint32_t cmd, uint32_t arg) {
    unsigned op = cmd >> 24, size = arg & 0xffff, a = BASE + (cmd & 0xffff), b = BASE + (arg >> 16);
    switch (op) {
    case 0: // n_audio gain command at IMEM 0xae8
        for (unsigned i = 0; i < FRAME; i += 2) {
            int v = clamp((int)sample(d, a + i) * (int16_t)arg);
            put(d, a + i, ((int64_t)v * (arg >> 16)) >> 16);
        }
        break;
    case 1:
        adpcm(d, ram, cmd, arg);
        break;
    case 2: // clear at least one 16-byte vector
        for (unsigned i = 0; i < (size ? (size + 15) & ~15u : 16); i++) d[(a + i) & 0xfff] = 0;
        break;
    case 3:
        envelope(d, ram, cmd, arg);
        break;
    case 4:
    case 6: // load / save
        transfer(d, ram, BASE + (cmd & 0xfff), arg, cmd >> 12 & 0xfff, op == 6);
        break;
    case 5:
        resample(d, ram, cmd, arg);
        break;
    case 8:
        put_word(d, 0xff4, arg & 0xffffff);
        put_word(d, 0xff0, cmd & 0xffffff);
        break;
    case 9: // set volume; the microcode falls through to the following parameter groups
        if (cmd & 0x40000) {
            if (cmd & 0x20000) {
                put(d, PARAM + 0x50, cmd);
                put_word(d, PARAM + 0x4c, arg);
            }
            put(d, PARAM + 0x46, cmd);
            put_word(d, PARAM + 0x48, arg);
        }
        put(d, PARAM + 0x40, cmd);
        put_word(d, PARAM + 0x42, arg);
        break;
    case 10: // two LDVs precede the two SDVs, including overlapping ranges
        for (unsigned i = 0; i < (size ? (size + 15) & ~15u : 16); i += 16) {
            uint8_t tmp[16];
            for (unsigned j = 0; j < 16; j++) tmp[j] = d[(a + i + j) & 0xfff];
            for (unsigned j = 0; j < 16; j++) d[(b + i + j) & 0xfff] = tmp[j];
        }
        break;
    case 11: { // The low halfword minus one goes directly to SP_RD_LEN.
        unsigned len = (cmd & 0xffff) - 1, n = ((len & 0xfff) | 7) + 1;
        unsigned count = (len >> 12 & 0xff) + 1, stride = n + (len >> 20 & 0xff8);
        for (unsigned i = 0; i < count; i++) transfer(d, ram, 0x400 + i * n, arg + i * stride, n, 0);
        break;
    }
    case 12: { // Both next vectors are fetched before the current eight samples are stored.
        unsigned dst = BASE + (arg & 0xffff);
        int16_t old[8] = {0}, mixed[8];
        scratch30[0] = (int16_t)cmd;
        load_vector(old, d, dst);
        load_vector(scratch29, d, b);
        for (unsigned i = 0; i < FRAME; i += 16) {
            for (unsigned j = 0; j < 8; j++) mixed[j] = mix_sample(old[j], scratch29[j], (int16_t)cmd);
            load_vector(old, d, dst + i + 16);
            load_vector(scratch29, d, b + i + 16);
            unsigned n = 16 - (dst & 15);
            for (unsigned j = 0; j < n; j++) {
                unsigned v = (uint16_t)mixed[j / 2];
                d[(dst + i + j) & 0xfff] = j & 1 ? v : v >> 8;
            }
        }
        break;
    }
    case 13:
        for (unsigned i = 0; i < FRAME; i += 2) {
            put(d, BASE + 2 * i, sample(d, 0x9e0 + i));
            put(d, BASE + 2 * i + 2, sample(d, 0xb50 + i));
        }
        break;
    case 14:
        if (!word(d, 0x400))
            pole(d, ram, cmd, arg);
        else
            iir(d, ram, cmd, arg);
        break;
    case 15:
        put_word(d, 0xffc, arg & 0xffffff);
        break;
    default:
        return 0;
    }
    return 1;
}

// The dispatcher fetches up to 40 commands into 0x2c0, overwriting the previous batch.
void bt_mixer_audio(uint32_t task, const uint8_t *boot_data, unsigned boot_size, BtMixerOracle oracle) {
    static uint8_t d[4096];
    BtMixerWrite write;
    uint8_t *ram = bt_mem + 0x80000000u;
    memcpy(d, boot_data, boot_size);
    memcpy(d + 0xfc0, G(task), 64);
    unsigned src = word(d, 0xff0), bytes = word(d, 0xff4);
    if (!bytes || (bytes & 7)) bt_fatal("invalid n_audio command list size %u", bytes);
    put_word(d, 0, word(d, 0) + word(d, 0xfd0));
    put_word(d, 8, word(d, 8) + word(d, 0xfd0));
    put_word(d, 0xff8, word(d, 0xfd8));
    deferred = oracle ? &write : NULL;
    for (unsigned index = 0; bytes;) {
        unsigned batch = bytes < 0x140 ? bytes : 0x140;
        transfer(d, ram, 0x2c0, src, batch, 0);
        for (unsigned i = 0; i < batch; i += 8, index++) {
            unsigned cmd = word(d, 0x2c0 + i), arg = word(d, 0x2c4 + i);
            write.size = 0;
            if (!mixer_command(d, ram, cmd, arg))
                bt_fatal("n_audio command %u opcode %02x is unsupported", index, cmd >> 24);
            if (oracle) oracle(index, cmd, arg, d, &write);
        }
        src += batch;
        bytes -= batch;
    }
    deferred = NULL;
}

void bt_audio_task(uint32_t task) {
    static uint8_t boot[BT_AUDIO_DATA_BYTES];
    static int initialized, rsp, check;
    if (!initialized) {
        bt_rom_audio(0, boot);
        const char *mode = getenv("BT_AUDIO");
        check = getenv("BT_AUDIO_CHECK") && atoi(getenv("BT_AUDIO_CHECK"));
        rsp = mode && !strcmp(mode, "rsp");
#ifndef BT_AUDIO_DEBUG
        if (rsp || check) bt_fatal("BT_AUDIO=rsp and BT_AUDIO_CHECK require a BT_AUDIO_DEBUG=1 build");
#endif
        if (mode && strcmp(mode, "rsp") && strcmp(mode, "mixer")) bt_fatal("unknown BT_AUDIO mode: %s", mode);
        initialized = 1;
    }
#ifdef BT_AUDIO_DEBUG
    if (rsp || check) {
        bt_audio_oracle(task, check, boot);
        return;
    }
#endif
    bt_mixer_audio(task, boot, sizeof boot, NULL);
}
