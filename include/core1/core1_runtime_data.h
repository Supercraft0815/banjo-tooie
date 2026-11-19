#ifndef CORE1_RUNTIME_DATA_H
#define CORE1_RUNTIME_DATA_H
#include <ultra64.h>
typedef struct {
    OSViMode video_modes[3];
    s32 frame_ready; u32 frame_padding[3];
    s16 reset_mode; u16 reset_padding[7];
    s32 thread_ready; u32 thread_padding[3];
    u16 music_volumes[168];
    s32 heap_used; u32 heap_padding[3];
    u32 inflate_crc1, inflate_crc2, inflate_padding[2], display_list_end[2];
    u16 debug_glyphs[3332];
    u8 thread_priorities[16];
} Core1RuntimeData;
extern Core1RuntimeData core1_runtime_data;
#ifdef BT_NATIVE
#define D_8003F4E0 (core1_runtime_data.video_modes[0])
#define D_8003F530 (core1_runtime_data.video_modes[1])
#define D_8003F5D0 (core1_runtime_data.frame_ready)
#define D_8003F5E0 (core1_runtime_data.reset_mode)
#define D_8003F5F0 (core1_runtime_data.thread_ready)
#define D_8003F600 (core1_runtime_data.music_volumes)
#define D_8003F750 (core1_runtime_data.heap_used)
#define D_8003F778 (core1_runtime_data.debug_glyphs)
#define D_80041180 (core1_runtime_data.thread_priorities)
#endif
#endif
