#include "common.h"

/* extern */

typedef struct { u8 pad0[0x18C]; BtIntPtr unk18C; } Objdronemem_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */ void badronemem_entrypoint_0(void *arg0, s32 arg1) {
    BtIntPtr heap_alloc(s32);
    (((Objdronemem_arg0 *)arg0)->unk18C) = heap_alloc(arg1);
}

/* extern */

void badronemem_entrypoint_1(void *arg0) {
    void heap_free(void *memory);
    heap_free((((Objdronemem_arg0 *)arg0)->unk18C));
    (((Objdronemem_arg0 *)arg0)->unk18C) = 0;
}

void badronemem_entrypoint_2(BtIntPtr arg0) 
{
}
void badronemem_entrypoint_3(void *arg0)
{
    *(u32 *) ((u8 *) arg0 + 0x18C) = 0;
}
