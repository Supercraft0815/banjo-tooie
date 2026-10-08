#include "common.h"

s32 dbvtxnormal_entrypoint_0(s32 arg0, s32 arg1) {
    return (arg1 * 4) + arg0;
}

void dbvtxnormal_entrypoint_1(void* arg0) 
{
    heap_free(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/db/vtxnormal/dbvtxnormal_entrypoint_2.s")
