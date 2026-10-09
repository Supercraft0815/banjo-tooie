#include "common.h"

/* extern */

void bastatemem_entrypoint_0(void *arg0, s32 arg1) {
    s32 heap_alloc(s32);
    (*(s32 *)((s8 *)(arg0) + (0x188))) = heap_alloc(arg1);
}

/* extern */

void bastatemem_entrypoint_1(void *arg0) {
    s32 heap_free(s32);
    heap_free((*(s32 *)((s8 *)(arg0) + (0x188))));
    (*(s32 *)((s8 *)(arg0) + (0x188))) = 0;
}

void bastatemem_entrypoint_2(s32 arg0) 
{
}
void bastatemem_entrypoint_3(void* arg0)
{
    *(s32*)((u8*)arg0 + 0x188) = 0;
}
