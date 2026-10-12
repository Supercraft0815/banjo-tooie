#include "common.h"

s32 dbvtxnormal_entrypoint_0(s32 arg0, s32 arg1) {
    return (arg1 * 4) + arg0;
}

void dbvtxnormal_entrypoint_1(void* arg0) 
{
    heap_free(arg0);
}
/* extern */

s32 dbvtxnormal_entrypoint_2(s32 arg0) {
    s32 aligned4_memcpy(void *, void *, s32);
    u32 func_800B2344(void *);
    u8 *func_800B27A0(u8 *);
    s32 func_800B2840(s32);
    s32 heap_alloc(s32);
    s32 result;
    s32 size;
    size = func_800B2344((void *)func_800B2840(arg0)) * 4;
    result = heap_alloc(size);

    aligned4_memcpy((void *)result, func_800B27A0((u8 *)arg0), size);
    return result;
}
