#include "common.h"

/* extern */

typedef struct { u8 pad0[0x188]; BtIntPtr unk188; } Objstatemem_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */ void bastatemem_entrypoint_0(void *arg0, s32 arg1) {
    BtIntPtr heap_alloc(s32);
    (((Objstatemem_arg0 *)arg0)->unk188) = heap_alloc(arg1);
}

/* extern */

void bastatemem_entrypoint_1(void *arg0) {
    void heap_free(void *memory);
    heap_free((((Objstatemem_arg0 *)arg0)->unk188));
    (((Objstatemem_arg0 *)arg0)->unk188) = 0;
}

void bastatemem_entrypoint_2(BtIntPtr arg0) 
{
}
void bastatemem_entrypoint_3(void* arg0)
{
    ((Objstatemem_arg0 *)arg0)->unk188 = 0;
}
