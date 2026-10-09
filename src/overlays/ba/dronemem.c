#include "common.h"

/* extern */

void badronemem_entrypoint_0(void *arg0, s32 arg1) {
    s32 heap_alloc(s32);
    (*(s32 *)((s8 *)(arg0) + (0x18C))) = heap_alloc(arg1);
}

/* extern */

void badronemem_entrypoint_1(void *arg0) {
    s32 heap_free(s32);
    heap_free((*(s32 *)((s8 *)(arg0) + (0x18C))));
    (*(s32 *)((s8 *)(arg0) + (0x18C))) = 0;
}

void badronemem_entrypoint_2(s32 arg0) 
{
}
void badronemem_entrypoint_3(void *arg0)
{
    *(u32 *) ((u8 *) arg0 + 0x18C) = 0;
}
