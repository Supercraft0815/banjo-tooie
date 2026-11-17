#include "common.h"

void func_80800000_chstatictorch(Actor *arg0, void *arg1) {
    void func_80101870(Actor *, void *);
    OSThread *func_80104130(void);
    void func_800DBEFC(s32 *, s32, BtIntPtr);
    void *func_80100094(Actor *, u32);
    void _suflamefx_entrypoint_3(void *arg0, BtIntPtr arg1);

    func_80101870(arg0, arg1);
    if (arg0->unk7C_12) {
        func_800DBEFC((s32 *)func_80104130(), 5, (BtIntPtr)arg0->actorData);
        ((f32 *)arg0->actorData)[1] += 10.0f;
        if (func_80100094(arg0, 1) != NULL) {
            _suflamefx_entrypoint_3(func_80100094(arg0, 1), arg1);
        }
    }
}

/* extern */

void func_80800090_chstatictorch(Actor *arg0) {
    void _suflamefx_entrypoint_2(void *arg0, f32 *arg1);
    s32 func_8008FB10(f32 *arg0, f32 arg1, f32 arg2, f32 arg3);
    void *func_80100094(Actor *, u32);
    void func_80800140_chstatictorch(Actor *);
    func_8008FB10((BtIntPtr) arg0->position, 40.0f, 0.0f, 1.0f);
    _suflamefx_entrypoint_2(func_80100094(arg0, 1U), arg0->actorData);
    func_80800140_chstatictorch(arg0);
}

void func_808000E4_chstatictorch(s32 arg0) 
{
}
/* extern */

void func_808000EC_chstatictorch(Actor *arg0) {
    s32 func_800C2FDC(u8 index);
    void* func_80100094(Actor*, u32);
    void _suflamefx_entrypoint_1(Actor *arg0, u32 arg1);
    u8 temp_a0;

    if (func_80100094(arg0, 1U) != NULL) {
        _suflamefx_entrypoint_1(arg0, 1);
    }
    temp_a0 = arg0->unk5F;
    if (temp_a0 != 0) {
        func_800C2FDC(temp_a0);
        arg0->unk5F = 0;
    }
}

void func_80800140_chstatictorch(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_4(Actor*, f32*, u32, u32*);
    extern u32 D_80800230_chstatictorch[6];
    _subaddieaudioloop_entrypoint_4(arg0,
        arg0->unk7C_12 ? (f32 *)((u8 *)arg0 + 0x18) : arg0->position,
        1U, D_80800230_chstatictorch);
}

s32 func_80800180_chstatictorch(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    void _suflamefx_entrypoint_0(Actor *arg0, u32 arg1, s32 arg2, s16 arg3);
    void _suflamefx_entrypoint_7(u8 *arg0, f32 *arg1, f32 arg2, f32 arg3, f32 arg4, u8 arg5, f32 arg6);
    s32 result;
    if (arg1 == 0x95) {
        _suflamefx_entrypoint_0(arg0, 1, 0xF, 0x9EB);
        _suflamefx_entrypoint_7(func_80100094(arg0, 1U), arg0->position,
            0.4f, 0.5f, 11.0f, 3, 0.95f);
        result = 1;
    } else {
        return 0;
    }
    return result;
}

OSThread *chstatictorch_entrypoint_0(void)
{
    extern ActorData D_80800248_chstatictorch[];

    return (OSThread *) D_80800248_chstatictorch;
}
/* data_to_c.py: from asm/data/overlays/ch/statictor.data.s */
void func_80105834(Actor*);
void func_80107C2C();
u32 D_80800230_chstatictorch[6] BT_DATA(4, overlays_ch_statictor, 0x0) = { 0x130483, 0x162710, 0xE0133, 0x1700180, 0x101F4, 0x5DC0000 };
ActorData D_80800248_chstatictorch [1] BT_DATA(4, overlays_ch_statictor, 0x18) = { { 526, 686, 1652, 1, 0, (void (*)(struct Actor *))func_80800090_chstatictorch, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80800000_chstatictorch, 0, 0, 0, 0, 0, 35, (void (*)(struct Actor *))func_808000EC_chstatictorch, 0, 0, 0, (void (*)(struct Actor *))func_808000E4_chstatictorch, (void (*)(void *, long, void *, long, void *))func_80107C2C, 0, 0, (void (*)(struct Actor *, long, long))func_80800180_chstatictorch, 0 } };
