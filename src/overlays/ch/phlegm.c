#include "common.h"

OSThread *chphlegm_entrypoint_0(void)
{
    extern u8 D_80800B58_chphlegm[];

    return (OSThread *) D_80800B58_chphlegm;
}

OSThread *chphlegm_entrypoint_1(void)
{
    extern u8 D_80800BA0_chphlegm[];

    return (OSThread *) D_80800BA0_chphlegm;
}

OSThread *chphlegm_entrypoint_2(void)
{
    extern u8 D_80800BE8_chphlegm[];

    return (OSThread *) D_80800BE8_chphlegm;
}

void func_80800024_chphlegm(Actor *arg0) {
    int func_800DC298(f32);
    void func_8010A570(Actor *);

    if (func_800DC298(0.5f)) {
        arg0->unk50 = 600.0f;
    } else {
        arg0->unk50 = -600.0f;
    }
    if (func_800DC298(0.5f)) {
        arg0->unk54 = 50.0f;
    } else {
        arg0->unk54 = -50.0f;
    }
    if (arg0->unk64_20) {
        func_8010A570(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/phlegm/func_808000C4_chphlegm.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/phlegm/func_8080026C_chphlegm.s")

/* extern */

void func_80800354_chphlegm(Actor *arg0) {
    f32 func_800DC178(f32, f32);
    f32 func_8010CD28(Actor *);
    f32 temp_f0;

    temp_f0 = func_8010CD28(arg0);
    arg0->unk54 = temp_f0;
    arg0->rotation[1] = temp_f0;
    *(f32 *)&arg0->actorData[3] = arg0->scale * 150.0f;
    arg0->unk58 = func_800DC178(0.8f, 1.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/phlegm/func_808003B4_chphlegm.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/phlegm/func_808005E4_chphlegm.s")

/* extern */

void func_80800704_chphlegm(s32 arg0, s32 arg1) {
    s32 func_800DF744(s32, s32);
    s32 func_80101870(s32, s32);
    func_800DF744(3, 1);
    func_800DF744(4, 0);
    func_80101870(arg0, arg1);
}

void func_80800748_chphlegm(Actor *arg0, f32 arg1, s32 arg2) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 func_800B53A4(s32);
    void func_800BA3FC(s32, s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    void func_800EE7F8(f32 *, f32 *);
    extern s32 D_80800C5C_chphlegm;
    extern s32 D_80800C88_chphlegm;
    f32 sp2C[3];
    s32 sp28;

    func_800EE7F8(sp2C, arg0->position);
    sp2C[1] += arg0->scale * arg1;
    sp28 = func_800B53A4(10);
    func_800BA3FC(sp28, arg2);
    func_800BABB8(sp28, arg0->position, sp2C, arg0->scale, &D_80800C5C_chphlegm);
    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80800C88_chphlegm);
}

void func_808007EC_chphlegm(u8 *arg0, s32 arg1) {
    s32 func_800B53A4(s32);
    void func_800BA3FC(s32, s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    extern s32 D_80800C98_chphlegm;
    s32 sp24;
    s32 temp_v0;

    temp_v0 = func_800B53A4(2);
    sp24 = temp_v0;
    func_800BA3FC(temp_v0, arg1);
    func_800BABB8(sp24, arg0 + 4, NULL, (*(f32 *)((s8 *)(arg0) + (0x38))), &D_80800C98_chphlegm);
}

void func_80800848_chphlegm(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/phlegm/func_80800850_chphlegm.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/phlegm/func_808009DC_chphlegm.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/phlegm/func_80800A58_chphlegm.s")
