#include "common.h"

/* extern */

void func_80800000_chdeflect(BtIntPtr arg0) {
    s32 func_800C6E38(s32);
    void func_800FFAB0(Actor *actor);
    if (func_800C6E38(0x14) != 0) {
        func_800FFAB0(arg0);
    }
}    typedef struct { u8 pad0[0x38]; f32 unk38; } Objdeflect_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_80800034_chdeflect(u8 *arg0) {
    s32 _sudeflect_entrypoint_0(f32 *arg0, f32 arg1, f32 arg2, s32 arg3);
    _sudeflect_entrypoint_0(arg0 + 4, 0.0f, (((Objdeflect_arg0 *)arg0)->unk38) * 100.0f, 2);
}

OSThread *chdeflect_entrypoint_0(void)
{
    extern ActorData D_80800090_chdeflect[];

    return (OSThread *) D_80800090_chdeflect;
}
/* data_to_c.py: from asm/data/overlays/ch/deflect.data.s */
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
OSThread *func_80108ED0(void);
void func_80107C2C();
ActorData D_80800090_chdeflect [1] BT_DATA(4, overlays_ch_deflect, 0x0) = { { 344, 1333, 0, 1, 0, (void (*)(struct Actor *))func_80800034_chdeflect, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 131072000, 0, 0, 0, 0, 0, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_80800000_chdeflect, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1024, 0, 0 } };
