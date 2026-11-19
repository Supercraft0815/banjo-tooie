typedef struct {
    f32 time, value;
} FrameCurveKey;

FrameCurveKey D_80123500[2] BT_DATA(4, frame_cache_settings, 0) = {{0, 0}, {1, 1}};
s32 D_80123510 BT_DATA(4, frame_cache_settings, 16) = 0;
s32 D_80123514[2] BT_DATA(4, frame_cache_settings, 20) = {79, 47};
s32 D_8012351C[2] BT_DATA(4, frame_cache_settings, 28) = {47, 0};
u32 D_80123524 BT_DATA(4, frame_cache_settings, 36) = 0;

#if defined(BT_NATIVE) && !defined(BT_ILP32)
#include "freelist.h"
typedef FreeList *FrameCurveList;
#define FRAME_RETAIL(declaration)
#define FRAME_VIEW(native, retail) native
static u16 bank_halfword(const void *address) {
    const u8 *bytes = address;
    return ((u16)bytes[0] << 8) | bytes[1];
}
static u32 bank_word(const void *address) {
    const u8 *bytes = address;
    return ((u32)bank_halfword(bytes) << 16) | bank_halfword(bytes + 2);
}
#else
typedef s32 FrameCurveList;
#define FRAME_RETAIL(declaration) declaration
#define FRAME_VIEW(native, retail) retail
#endif
