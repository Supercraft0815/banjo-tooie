#include "common.h"

#ifdef BT_NATIVE
#include "native_palette.h"
void dbpalette_entrypoint_0(const void *palette,s32 index,void *output) {
    const u8 *entry=(const u8 *)palette+index*4;
    s32 *color=output;
    for(int i=0;i<4;++i)color[i]=entry[3-i];
}
void dbpalette_entrypoint_1(void *palette,s32 index,s32 *color) {
    u8 *entry=(u8 *)palette+index*4;
    u32 packed=(u32)color[0]|(u32)color[1]<<8|(u32)color[2]<<16|(u32)color[3]<<24;
    for(int i=0;i<4;++i)entry[i]=packed>>((3-i)*8);
}
#else
void dbpalette_entrypoint_0(s32 arg0, s32 arg1, void *arg2) {
    u32 *temp_v0;

    temp_v0 = (u32 *) ((u8 *) arg0 + (arg1 * 4));
    (*(s32 *)((s8 *)(arg2) + (0))) = (s32) (*temp_v0 & 0xFF);
    (*(s32 *)((s8 *)(arg2) + (4))) = (s32) (((u32) *temp_v0 >> 8) & 0xFF);
    (*(s32 *)((s8 *)(arg2) + (8))) = (s32) (((u32) *temp_v0 >> 0x10) & 0xFF);
    (*(s32 *)((s8 *)(arg2) + (0xC))) = (s32) (((u32) *temp_v0 >> 0x18) & 0xFF);
}

void dbpalette_entrypoint_1(s32 arg0, s32 arg1, s32 *arg2) {
    s32 *temp_v0;
    temp_v0 = (s32 *) ((u8 *) arg0 + (arg1 * 4));
    *temp_v0 = 0;
    *temp_v0 = arg2[0];
    *temp_v0 = (arg2[1] << 8) | *temp_v0;
    *temp_v0 = (arg2[2] << 0x10) | *temp_v0;
    *temp_v0 = (arg2[3] << 0x18) | *temp_v0;
}
#endif
