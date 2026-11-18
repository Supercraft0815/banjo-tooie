#ifdef BT_ILP32
#include "gfx.h"
// Mark the existing RDPHALF_2 instruction. Its unused low bits carry the whole string's
// 4:3 anchor to the native renderer, without growing the guest display list.
static int native_glyph(Gfx **gfx, s32 x, s32 y, u8 ch, s32 anchor_x) {
    Gfx *before = *gfx;
    int advance = func_800B81CC(gfx, x, y, ch);
    if (widescreen_enabled && before != *gfx) {
        u32 third = anchor_x < SCREEN_WIDTH / 3 ? 0 : anchor_x > SCREEN_WIDTH * 2 / 3 ? 2 : 1;
        (*gfx)[-1].words.w0 |= 0x425400u | third;
    }
    return advance;
}
#else
#define native_glyph(gfx, x, y, ch, anchor) func_800B81CC(gfx, x, y, ch)
#endif
