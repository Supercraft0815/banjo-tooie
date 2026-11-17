// Audio interface: AI buffers (big-endian s16 stereo) go to an SDL audio stream.
//   BT_MUTE=1     no audio device
//   BT_PCM=path   also write the output as raw s16le stereo (rate printed on stderr)
#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "guest.h"

#define VI_NTSC_CLOCK 48681812
static SDL_AudioStream *_Atomic stream;
static _Atomic u32 rate = 22050;
static FILE *pcm;
static u64 vclock_end;  // virtual clock: tick at which the audio handed over so far has played

static SDL_AudioSpec spec(void) { return (SDL_AudioSpec){ SDL_AUDIO_S16, 2, (int)rate }; }

// Main thread, after SDL_Init with SDL_INIT_AUDIO.
void bt_ai_open(void) {
    SDL_AudioSpec s = spec();
    SDL_AudioStream *st = SDL_OpenAudioDeviceStream(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, &s, NULL, NULL);
    if (!st) { fprintf(stderr, "bt_native: no audio: %s\n", SDL_GetError()); return; }
    SDL_ResumeAudioStreamDevice(st);
    stream = st;
    bt_ai_volume(bt_setting(BT_SET_VOLUME) / 10.0f);
}

void bt_ai_volume(float gain) {
    if (stream) SDL_SetAudioStreamGain(stream, gain);
}

// The N64 rounds the rate to a whole divider of the video clock; the game synthesizes at the result.
u32 w2c_env_ai_frequency(struct w2c_env *env, u32 freq) {
    u32 dac = (u32)((double)VI_NTSC_CLOCK / freq + .5);
    (void)env;
    rate = VI_NTSC_CLOCK / dac;
    SDL_AudioSpec s = spec();
    if (stream) SDL_SetAudioStreamFormat(stream, &s, NULL);
    return rate;
}

void w2c_env_ai_buffer(struct w2c_env *env, u32 buf, u32 size) {
    static s16 out[0x4000];
    (void)env;
    if (size > sizeof out) size = sizeof out;
    for (u32 i = 0; i < size / 2; i++) out[i] = (s16)gr16(buf + 2 * i);
    if (!pcm && getenv("BT_PCM")) {
        pcm = fopen(getenv("BT_PCM"), "wb");
        fprintf(stderr, "bt_native: PCM s16le stereo %u Hz to %s\n", rate, getenv("BT_PCM"));
    }
    if (pcm) fwrite(out, 1, size, pcm);
    if (bt_vclock_on) {
        u64 now = bt_vclock_ticks();
        if (vclock_end < now) vclock_end = now;
        vclock_end += (u64)size / 4 * 46875000u / rate;
    }
    // Faster than real time (BT_SPEED) the queue would only grow: drop beyond a quarter second
    // (rate frames * 4 bytes / 4).
    if (stream && SDL_GetAudioStreamQueued(stream) < (int)rate) SDL_PutAudioStreamData(stream, out, (int)size);
}

// Bytes left in the current AI buffer: what is queued beyond the device latency reserve.
u32 w2c_env_ai_length(struct w2c_env *env) {
    (void)env;
    if (bt_vclock_on) {  // playback follows the virtual clock, not the device
        u64 now = bt_vclock_ticks();
        return vclock_end > now ? (u32)((vclock_end - now) * rate / 46875000u) * 4 : 0;
    }
    if (!stream) return 0;
    int reserve = (512 << bt_setting(BT_SET_AUDIO_LATENCY)) * 4;  // stereo s16 frames beyond the visible queue
    int q = SDL_GetAudioStreamQueued(stream) - reserve;
    return q > 0 ? (u32)q & ~3u : 0;
}
