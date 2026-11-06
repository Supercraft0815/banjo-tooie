// RSP interpreter for audio tasks: runs the game's own audio microcode (n_aspMain, embedded from
// the extracted ROM assets) instead of reimplementing its commands. It covers the scalar and
// vector instructions that microcode uses; anything else stops with its encoding.
#include <string.h>
#include "guest.h"

static const u8 ucode_text[] = {
#embed "../../../../assets/core1/n_aspMain.textbin.bin"
};
static const u8 ucode_data[] = {
#embed "../../../../assets/core1/n_aspMain.rodatabin.bin"
};

static u8 dmem[0x1000], imem[0x1000];
static u32 r[32];
static u16 vr[32][8];          // lane i = DMEM bytes 2i, 2i+1 of a vector load (big-endian)
static s64 acc[8];             // 48-bit accumulator, sign-extended
static u16 vco, vcc;           // carry (low 8) / not-equal (high 8); compare (low 8) / clip (high 8)
static u8 vce;
static u32 sp_mem, sp_dram;    // DMA registers
static u8 esel[16][8];         // element selection: lane i of vt[e] reads vt[esel[e][i]]

#define DM(a) dmem[(a) & 0xFFF]
static u32 ld32(u32 a) { return (u32)DM(a) << 24 | DM(a + 1) << 16 | DM(a + 2) << 8 | DM(a + 3); }
static u16 ld16(u32 a) { return (u16)(DM(a) << 8 | DM(a + 1)); }
static void st32(u32 a, u32 v) { DM(a) = (u8)(v >> 24); DM(a + 1) = (u8)(v >> 16); DM(a + 2) = (u8)(v >> 8); DM(a + 3) = (u8)v; }
static void st16(u32 a, u32 v) { DM(a) = (u8)(v >> 8); DM(a + 1) = (u8)v; }
static u8 vget(int v, int b) { u16 e = vr[v][b >> 1 & 7]; return b & 1 ? (u8)e : (u8)(e >> 8); }
static void vset(int v, int b, u8 x) {
    u16 *e = &vr[v][b >> 1];
    *e = b & 1 ? (u16)((*e & 0xFF00) | x) : (u16)((*e & 0x00FF) | x << 8);
}

// SP DMA; len = (bytes - 1) | (count - 1) << 12 | skip << 20, like SP_RD_LEN/SP_WR_LEN.
static void dma(u32 len, int to_dram) {
    u32 n = ((len & 0xFFF) | 7) + 1, count = (len >> 12 & 0xFF) + 1, skip = len >> 20 & 0xFF8;
    u32 mem = sp_mem & 0xFF8, dram = sp_dram & 0xFFFFF8;
    u8 *sp = sp_mem & 0x1000 ? imem : dmem;
    if (sp == imem) bt_fatal("audio microcode loads an IMEM overlay (MP3 decoding), not supported");
    for (u32 c = 0; c < count; c++, dram += n + skip) {
        for (u32 i = 0; i < n; i++, mem = (mem + 1) & 0xFFF) {
            u32 g = 0x80000000u | ((dram + i) & 0xFFFFFF);
            if ((u64)g + 1 > bt_inst.w2c_memory.size) bt_fatal("audio DMA outside guest memory: %08x", g);
            if (to_dram) bt_mem[g] = sp[mem]; else sp[mem] = bt_mem[g];
        }
    }
}

static s16 sat16(s32 v) { return v < -32768 ? -32768 : v > 32767 ? 32767 : (s16)v; }
static s64 sx48(s64 a) { return (s64)((u64)a << 16) >> 16; }
static u16 acc_hi(int i) { return (u16)sat16((s32)(acc[i] >> 16)); }  // acc[47:16], saturated
static u16 acc_lo(int i) { s64 v = acc[i] >> 16; return v < -32768 ? 0 : v > 32767 ? 0xFFFF : (u16)acc[i]; }
static u16 acc_un(int i) { s64 v = acc[i] >> 16; return v < 0 ? 0 : v > 32767 ? 0xFFFF : (u16)v; }
static void set_lo(int i, u16 v) { acc[i] = (acc[i] & ~(s64)0xFFFF) | v; }

static void vector_op(u32 w) {
    int fn = w & 63, e = w >> 21 & 15, vt = w >> 16 & 31, vs = w >> 11 & 31, vd = w >> 6 & 31;
    s16 s[8], t[8];
    u16 d[8];
    for (int i = 0; i < 8; i++) { s[i] = (s16)vr[vs][i]; t[i] = (s16)vr[vt][esel[e][i]]; }
    switch (fn) {
#define MUL(set, expr, out) for (int i = 0; i < 8; i++) { acc[i] = sx48(set (expr)); d[i] = out(i); } break
    case 0x00: MUL(, (s64)s[i] * t[i] * 2 + 0x8000, acc_hi);                  // vmulf
    case 0x01: MUL(, (s64)s[i] * t[i] * 2 + 0x8000, acc_un);                  // vmulu
    case 0x04: MUL(, (s64)((u32)(u16)s[i] * (u16)t[i] >> 16), acc_lo);        // vmudl
    case 0x05: MUL(, (s64)s[i] * (u16)t[i], acc_hi);                          // vmudm
    case 0x06: MUL(, (s64)(u16)s[i] * t[i], acc_lo);                          // vmudn
    case 0x07: MUL(, (s64)s[i] * t[i] * 65536, acc_hi);                       // vmudh
    case 0x08: MUL(acc[i] +, (s64)s[i] * t[i] * 2, acc_hi);                   // vmacf
    case 0x09: MUL(acc[i] +, (s64)s[i] * t[i] * 2, acc_un);                   // vmacu
    case 0x0C: MUL(acc[i] +, (s64)((u32)(u16)s[i] * (u16)t[i] >> 16), acc_lo); // vmadl
    case 0x0D: MUL(acc[i] +, (s64)s[i] * (u16)t[i], acc_hi);                  // vmadm
    case 0x0E: MUL(acc[i] +, (s64)(u16)s[i] * t[i], acc_lo);                  // vmadn
    case 0x0F: MUL(acc[i] +, (s64)s[i] * t[i] * 65536, acc_hi);               // vmadh
#undef MUL
    case 0x10: case 0x11:                                                     // vadd, vsub (with carry)
        for (int i = 0; i < 8; i++) {
            s32 v = fn == 0x10 ? s[i] + t[i] + (vco >> i & 1) : s[i] - t[i] - (vco >> i & 1);
            set_lo(i, (u16)v); d[i] = (u16)sat16(v);
        }
        vco = 0; break;
    case 0x13:                                                                // vabs
        for (int i = 0; i < 8; i++) {
            s16 v = s[i] < 0 ? (s16)-t[i] : s[i] > 0 ? t[i] : 0;
            set_lo(i, (u16)v); d[i] = s[i] < 0 && t[i] == -32768 ? 0x7FFF : (u16)v;
        }
        break;
    case 0x14: case 0x15:                                                     // vaddc, vsubc
        vco = 0;
        for (int i = 0; i < 8; i++) {
            s32 v = fn == 0x14 ? (u16)s[i] + (u16)t[i] : (u16)s[i] - (u16)t[i];
            set_lo(i, (u16)v); d[i] = (u16)v;
            if (fn == 0x14 ? v > 0xFFFF : v < 0) vco |= 1 << i;
            if (fn == 0x15 && v != 0) vco |= 0x100 << i;
        }
        break;
    case 0x1D:                                                                // vsar
        for (int i = 0; i < 8; i++) d[i] = e == 8 ? (u16)(acc[i] >> 32) : e == 9 ? (u16)(acc[i] >> 16) : e == 10 ? (u16)acc[i] : 0;
        break;
    case 0x20: case 0x21: case 0x22: case 0x23:                               // vlt, veq, vne, vge
        vcc = 0;
        for (int i = 0; i < 8; i++) {
            int carry = vco >> i & 1, ne = vco >> (i + 8) & 1, c;
            if (fn == 0x20) c = s[i] < t[i] || (s[i] == t[i] && carry && ne);
            else if (fn == 0x21) c = s[i] == t[i] && !ne;
            else if (fn == 0x22) c = s[i] != t[i] || ne;
            else c = s[i] > t[i] || (s[i] == t[i] && !(carry && ne));
            vcc |= (u16)(c << i);
            d[i] = (u16)(c ? s[i] : t[i]); set_lo(i, d[i]);
        }
        vco = 0; break;
    case 0x27: for (int i = 0; i < 8; i++) { d[i] = (u16)(vcc >> i & 1 ? s[i] : t[i]); set_lo(i, d[i]); } break;  // vmrg
    case 0x28: for (int i = 0; i < 8; i++) { d[i] = (u16)(s[i] & t[i]); set_lo(i, d[i]); } break;
    case 0x29: for (int i = 0; i < 8; i++) { d[i] = (u16)~(s[i] & t[i]); set_lo(i, d[i]); } break;
    case 0x2A: for (int i = 0; i < 8; i++) { d[i] = (u16)(s[i] | t[i]); set_lo(i, d[i]); } break;
    case 0x2B: for (int i = 0; i < 8; i++) { d[i] = (u16)~(s[i] | t[i]); set_lo(i, d[i]); } break;
    case 0x2C: for (int i = 0; i < 8; i++) { d[i] = (u16)(s[i] ^ t[i]); set_lo(i, d[i]); } break;
    case 0x2D: for (int i = 0; i < 8; i++) { d[i] = (u16)~(s[i] ^ t[i]); set_lo(i, d[i]); } break;
    case 0x33: {                                                              // vmov: vd[de] = vt[e]
        int de = vs & 7;
        for (int i = 0; i < 8; i++) set_lo(i, (u16)t[i]);
        vr[vd][de] = (u16)t[de];
        return;
    }
    case 0x37: return;                                                        // vnop
    default: bt_fatal("audio microcode: vector op %02x not implemented (%08x)", fn, w);
    }
    memcpy(vr[vd], d, sizeof d);
}

static void vector_load(u32 w, int store) {
    int op = w >> 11 & 31, vt = w >> 16 & 31, e = w >> 7 & 15;
    static const u8 scale[6] = { 1, 2, 4, 8, 16, 16 };
    if (op > 5) bt_fatal("audio microcode: vector %s %d not implemented (%08x)", store ? "store" : "load", op, w);
    s32 off = (s32)(w << 25) >> 25;
    u32 a = (r[w >> 21 & 31] + (u32)(off * scale[op])) & 0xFFF;
    if (op == 5) {                                       // lrv/srv: the aligned block up to a, at the vector's end
        u32 n = a & 15, base = a & ~15u;
        for (u32 i = 0; i < n; i++) {
            u32 b = (u32)e + 16 - n + i;
            if (store) DM(base + i) = vget(vt, (int)(b & 15));
            else if (b < 16) vset(vt, (int)b, DM(base + i));
        }
        return;
    }
    u32 n = op == 4 ? 16 - (a & 15) : scale[op];         // lqv/sqv stop at the 16-byte boundary
    for (u32 i = 0; i < n; i++) {
        if (store) DM(a + i) = vget(vt, (e + (int)i) & 15);
        else if (e + i < 16) vset(vt, e + (int)i, DM(a + i));
    }
}

static u32 cop0_read(int reg) {
    (void)reg;  // DMA is synchronous: never busy or full; status, semaphore and DPC read 0.
    return 0;
}

static void cop0_write(int reg, u32 v) {
    switch (reg) {
    case 0: sp_mem = v; break;
    case 1: sp_dram = v; break;
    case 2: dma(v, 0); break;
    case 3: dma(v, 1); break;
    default: break;  // SP_STATUS signals, semaphore: nothing waits on them
    }
}

static void run(void) {
    u32 pc = 0x080, npc = 0x084;
    for (u64 steps = 0;; steps++) {
        u32 w = (u32)imem[pc] << 24 | imem[pc + 1] << 16 | imem[pc + 2] << 8 | imem[pc + 3];
        u32 next = (npc + 4) & 0xFFC;
        u32 op = w >> 26, rs = w >> 21 & 31, rt = w >> 16 & 31, rd = w >> 11 & 31, sa = w >> 6 & 31;
        s32 si = (s16)w;
        u32 br = (pc + 4 + (u32)(si << 2)) & 0xFFC;
        if (steps > 100000000) bt_fatal("audio microcode runs away at IMEM %03x", pc);
        switch (op) {
        case 0x00:
            switch (w & 63) {
            case 0x00: r[rd] = r[rt] << sa; break;
            case 0x02: r[rd] = r[rt] >> sa; break;
            case 0x03: r[rd] = (u32)((s32)r[rt] >> sa); break;
            case 0x04: r[rd] = r[rt] << (r[rs] & 31); break;
            case 0x06: r[rd] = r[rt] >> (r[rs] & 31); break;
            case 0x07: r[rd] = (u32)((s32)r[rt] >> (r[rs] & 31)); break;
            case 0x08: next = r[rs] & 0xFFC; break;
            case 0x09: next = r[rs] & 0xFFC; r[rd] = (pc + 8) & 0xFFC; break;
            case 0x0D: return;  // break: task done
            case 0x20: case 0x21: r[rd] = r[rs] + r[rt]; break;
            case 0x22: case 0x23: r[rd] = r[rs] - r[rt]; break;
            case 0x24: r[rd] = r[rs] & r[rt]; break;
            case 0x25: r[rd] = r[rs] | r[rt]; break;
            case 0x26: r[rd] = r[rs] ^ r[rt]; break;
            case 0x27: r[rd] = ~(r[rs] | r[rt]); break;
            case 0x2A: r[rd] = (s32)r[rs] < (s32)r[rt]; break;
            case 0x2B: r[rd] = r[rs] < r[rt]; break;
            default: bt_fatal("audio microcode: special %02x at IMEM %03x", w & 63, pc);
            }
            break;
        case 0x01:
            if (rt & 16) r[31] = (pc + 8) & 0xFFC;
            if ((rt & 1) ? (s32)r[rs] >= 0 : (s32)r[rs] < 0) next = br;
            break;
        case 0x02: next = w << 2 & 0xFFC; break;
        case 0x03: r[31] = (pc + 8) & 0xFFC; next = w << 2 & 0xFFC; break;
        case 0x04: if (r[rs] == r[rt]) next = br; break;
        case 0x05: if (r[rs] != r[rt]) next = br; break;
        case 0x06: if ((s32)r[rs] <= 0) next = br; break;
        case 0x07: if ((s32)r[rs] > 0) next = br; break;
        case 0x08: case 0x09: r[rt] = r[rs] + (u32)si; break;
        case 0x0A: r[rt] = (s32)r[rs] < si; break;
        case 0x0B: r[rt] = r[rs] < (u32)si; break;
        case 0x0C: r[rt] = r[rs] & (w & 0xFFFF); break;
        case 0x0D: r[rt] = r[rs] | (w & 0xFFFF); break;
        case 0x0E: r[rt] = r[rs] ^ (w & 0xFFFF); break;
        case 0x0F: r[rt] = w << 16; break;
        case 0x10:
            if (rs == 0) r[rt] = cop0_read(rd & 15);
            else if (rs == 4) cop0_write(rd & 15, r[rt]);
            break;
        case 0x12:
            if (rs & 16) { vector_op(w); break; }
            switch (rs) {
            case 0: { int e = w >> 7 & 15; r[rt] = (u32)(s16)(vget((int)rd, e) << 8 | vget((int)rd, (e + 1) & 15)); break; }
            case 2: r[rt] = rd == 0 ? (u32)(s16)vco : rd == 1 ? (u32)(s16)vcc : vce; break;
            case 4: { int e = w >> 7 & 15; vset((int)rd, e, (u8)(r[rt] >> 8)); if (e < 15) vset((int)rd, e + 1, (u8)r[rt]); break; }
            case 6: if (rd == 0) vco = (u16)r[rt]; else if (rd == 1) vcc = (u16)r[rt]; else vce = (u8)r[rt]; break;
            default: bt_fatal("audio microcode: cop2 %08x at IMEM %03x", w, pc);
            }
            break;
        case 0x20: r[rt] = (u32)(s8)DM(r[rs] + (u32)si); break;
        case 0x21: r[rt] = (u32)(s16)ld16(r[rs] + (u32)si); break;
        case 0x23: r[rt] = ld32(r[rs] + (u32)si); break;
        case 0x24: r[rt] = DM(r[rs] + (u32)si); break;
        case 0x25: r[rt] = ld16(r[rs] + (u32)si); break;
        case 0x28: DM(r[rs] + (u32)si) = (u8)r[rt]; break;
        case 0x29: st16(r[rs] + (u32)si, r[rt]); break;
        case 0x2B: st32(r[rs] + (u32)si, r[rt]); break;
        case 0x32: vector_load(w, 0); break;
        case 0x3A: vector_load(w, 1); break;
        default: bt_fatal("audio microcode: opcode %02x at IMEM %03x", op, pc);
        }
        r[0] = 0;
        pc = npc;
        npc = next;
    }
}

// Known results for the semantics the microcode leans on: vmulf saturation and rounding, vsar
// accumulator slices, lqv/lrv split loads.
static void selfcheck(void) {
#define VOP(fn, vd, vs, vt, e) (0x4A000000u | (e) << 21 | (vt) << 16 | (vs) << 11 | (vd) << 6 | (fn))
    vr[1][0] = vr[2][0] = 0x8000; vr[1][1] = vr[2][1] = 0x4000;
    vector_op(VOP(0x00, 3, 1, 2, 0));                                  // vmulf $v3, $v1, $v2
    vector_op(VOP(0x1D, 4, 0, 0, 9));                                  // vsar $v4, acc mid
    vector_op(VOP(0x1D, 5, 0, 0, 10));                                 // vsar $v5, acc low
    int ok = vr[3][0] == 0x7FFF && vr[3][1] == 0x2000 && vr[4][0] == 0x8000 && vr[5][1] == 0x8000;
    for (int i = 0; i < 32; i++) dmem[i] = (u8)i;
    memset(vr[6], 0, 16);
    r[2] = 4;  vector_load(0xC8000000u | 2u << 21 | 6u << 16 | 4u << 11, 0);  // lqv $v6[0], 0($v0): bytes 0-11
    r[2] = 20; vector_load(0xC8000000u | 2u << 21 | 6u << 16 | 5u << 11, 0);  // lrv $v6[0], 0($v0): bytes 12-15
    ok = ok && vr[6][0] == 0x0405 && vr[6][5] == 0x0E0F && vr[6][6] == 0x1011 && vr[6][7] == 0x1213;
    if (!ok) bt_fatal("RSP interpreter self-check failed");
#undef VOP
}

// What rspboot does before jumping to the microcode: text to IMEM 0x080, data to DMEM 0, the
// OSTask to DMEM 0xFC0 with $at pointing at it. DMEM above the data persists between tasks.
void bt_rsp_audio(u32 task) {
    static int ready;
    if (!ready) {
        for (int e = 0; e < 16; e++)
            for (int i = 0; i < 8; i++)
                esel[e][i] = (u8)(e < 2 ? i : e < 4 ? (i & ~1) | (e & 1) : e < 8 ? (i & ~3) | (e & 3) : e & 7);
        selfcheck();
        ready = 1;
    }
    memcpy(imem + 0x080, ucode_text, sizeof ucode_text < 0xF80 ? sizeof ucode_text : 0xF80);
    memcpy(dmem, ucode_data, sizeof ucode_data);
    for (u32 i = 0; i < 64; i += 4) st32(0xFC0 + i, gr32(task + i));
    memset(r, 0, sizeof r);
    r[1] = 0xFC0;
    run();
}
