#include "common.h"

#ifdef BT_NATIVE
#include "native_vertex_cache.h"
#include "native_palette.h"
void *glpackvtx_entrypoint_0(void *arg0, const void *arg1, s32 *arg2) {
#else
void *glpackvtx_entrypoint_0(void *arg0, s32 arg1, s32 *arg2) {
    s32 _dbpalette_entrypoint_0(s32, s32, s32 *);
#endif
    void *func_800B2190(void *);
    u32 func_800B2344(void *);
    void *heap_alloc(s32);
    u32 size;
    u8 *result;
    s16 zero;
    u32 count;
    s32 tint;
    u8 *end;
#ifdef BT_NATIVE
    s32 color[4];
#else
    s32 color[3];
#endif
    u8 *dst;
    u8 *src;

    count = func_800B2344(arg0);
    result = heap_alloc(count * 10);
    end = result + count * 10;
    src = func_800B2190(arg0);
    for (dst = result; dst < end; dst += 10) {
        if (arg1 != 0) {
            _dbpalette_entrypoint_0(arg1, *(u16 *)(src + 6) & 0x1FF, color);
            dst[6] = (u8)((s32)(src[12] * color[0]) >> 8);
            dst[7] = (u8)((s32)(src[13] * color[1]) >> 8);
            dst[8] = (u8)((s32)(src[14] * color[2]) >> 8);
        } else {
            dst[6] = src[12];
            dst[7] = src[13];
            dst[8] = src[14];
        }
#ifdef BT_NATIVE
        dst[9] = 0;
#endif
        src += 16;
        if (arg2 != NULL && (arg2[0] != 255 || arg2[1] != 255 || arg2[2] != 255)) {
            dst[6] = (u8)((s32)(dst[6] * arg2[0]) >> 8);
            dst[7] = (u8)((s32)(dst[7] * arg2[1]) >> 8);
            dst[8] = (u8)((s32)(dst[8] * arg2[2]) >> 8);
        }
        ((s16 *)dst)[2] = 0;
        zero = ((s16 *)dst)[2];
        ((s16 *)dst)[1] = zero;
        ((s16 *)dst)[0] = zero;
    }
    return result;
}

/* extern */

#ifdef BT_NATIVE
void glpackvtx_entrypoint_1(void *data) {
    void heap_free(void *);
    heap_free(data);
}
#else
void glpackvtx_entrypoint_1(void) {
    s32 heap_free();
    heap_free();
}

#endif
