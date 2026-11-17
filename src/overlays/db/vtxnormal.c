#include "common.h"

BtIntPtr dbvtxnormal_entrypoint_0(BtIntPtr arg0, s32 arg1) {
    return (arg1 * 4) + arg0;
}

void dbvtxnormal_entrypoint_1(void* arg0) 
{
    heap_free(arg0);
}
/* extern */

BtIntPtr dbvtxnormal_entrypoint_2(BtIntPtr arg0) {
    void aligned4_memcpy(void* dst, void* src, int length);
    u32 func_800B2344(void *);
    u8 *func_800B27A0(u8 *);
    BtIntPtr func_800B2840(BtIntPtr);
    BtIntPtr heap_alloc(s32);
    BtIntPtr result;
    s32 size;
    size = func_800B2344((void *)func_800B2840(arg0)) * 4;
    result = heap_alloc(size);

    aligned4_memcpy((void *)result, func_800B27A0((u8 *)arg0), size);
    return result;
}
