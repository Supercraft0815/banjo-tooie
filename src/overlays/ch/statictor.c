#include "common.h"

void func_80800000_chstatictorch(Actor *arg0, void *arg1) {
    void func_80101870(Actor *, void *);
    OSThread *func_80104130(void);
    void func_800DBEFC(s32 *, s32, s32);
    void *func_80100094(Actor *, u32);
    void _suflamefx_entrypoint_3(void *, void *);

    func_80101870(arg0, arg1);
    if (arg0->unk7C_12) {
        func_800DBEFC((s32 *)func_80104130(), 5, (s32)arg0->actorData);
        ((f32 *)arg0->actorData)[1] += 10.0f;
        if (func_80100094(arg0, 1) != NULL) {
            _suflamefx_entrypoint_3(func_80100094(arg0, 1), arg1);
        }
    }
}

/* extern */

void func_80800090_chstatictorch(Actor *arg0) {
    s32 _suflamefx_entrypoint_2(u8 *, u32 *);
    void func_8008FB10(s32, f32, f32, f32);
    void *func_80100094(Actor *, u32);
    void func_80800140_chstatictorch(Actor *);
    func_8008FB10((s32) arg0->position, 40.0f, 0.0f, 1.0f);
    _suflamefx_entrypoint_2(func_80100094(arg0, 1U), arg0->actorData);
    func_80800140_chstatictorch(arg0);
}

void func_808000E4_chstatictorch(s32 arg0) 
{
}
/* extern */

void func_808000EC_chstatictorch(Actor *arg0) {
    void func_800C2FDC(u8 id);
    void* func_80100094(Actor*, u32);
    s32 _suflamefx_entrypoint_1(Actor *, s32);
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
    extern u32 D_80800230_chstatictorch;
    _subaddieaudioloop_entrypoint_4(arg0,
        arg0->unk7C_12 ? (f32 *)((u8 *)arg0 + 0x18) : arg0->position,
        1U, &D_80800230_chstatictorch);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statictor/func_80800180_chstatictorch.s")

OSThread *chstatictorch_entrypoint_0(void)
{
    extern u8 D_80800248_chstatictorch[];

    return (OSThread *) D_80800248_chstatictorch;
}
