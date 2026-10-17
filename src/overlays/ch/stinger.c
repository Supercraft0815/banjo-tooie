#include "common.h"

void func_80800000_chstinger(Actor *arg0) {
    s32 func_800B5BE4(s32);
    void func_800BA22C(s32, s32);
    void func_800BA930(s32, s16, s16, s16, s16, s16, s16);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    f32 func_800DC178(f32, f32);
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EFA98(f32[3], f32[3], f32);
    extern s32 D_808007D0_chstinger[];
    extern s32 D_808007FC_chstinger[];
    extern s32 D_80800844_chstinger[];
    s32 sp5C;
    f32 sp50[3];
    f32 sp44[3];

    if (arg0->unk7C_12) {
        sp5C = func_800B5BE4(0x1B);
        sp5C = func_800BABB8(sp5C, arg0->position, arg0->position, 1.0f, D_808007D0_chstinger);
        func_800EFA98(sp50, (f32 *)&arg0->actorData[4], func_800DC178(-200.0f, -400.0f));
        func_800BA930(sp5C, (s16)sp50[0], (s16)sp50[1], (s16)sp50[2],
            (s16)sp50[0], (s16)sp50[1], (s16)sp50[2]);
        func_800BA22C(sp5C, 3);
        func_800EFA98(sp50, (f32 *)&arg0->actorData[4], -25.0f);
        func_800EE780(sp44, arg0->position, sp50);
        func_800BBCB8(sp44, NULL, 1.0f, 1, D_80800844_chstinger);
        func_800EF04C(sp44, sp50);
        sp5C = func_800B5BE4(8);
        func_800BABB8(sp5C, sp44, NULL, 1.0f, D_808007FC_chstinger);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stinger/func_8080015C_chstinger.s")

void func_80800218_chstinger(Actor *arg0) {
    void func_800F1A88(f32 *, f32 *);
    f32 sp18[2];

    func_800F1A88((f32 *)((s8 *)arg0 + 0x28), sp18);
    arg0->rotation[0] = -sp18[0];
    arg0->rotation[1] = sp18[1];
}

void func_8080025C_chstinger(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stinger/func_80800264_chstinger.s")

/* extern */

s32 func_808003B0_chstinger(s32 arg0) {
    s32 func_800EA068(s32);
    s32 func_800F7A7C(s32, s8, s32, s32, s32 *);
    s8 *func_80100094(s32, s32);
    s32 func_80800264_chstinger(s32, s32 *);
    s32 sp2C[3];
    s32 sp28;
    s32 temp_v0;

    if (func_800EA068(0x4000) != 0) {
        temp_v0 = func_80800264_chstinger(arg0, sp2C);
        sp28 = temp_v0;
        if (temp_v0 >= 0) {
            func_800F7A7C(sp28, *func_80100094(arg0, 0), 1, 3, sp2C);
            return 1;
        }
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stinger/func_80800420_chstinger.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stinger/chstinger_entrypoint_0.s")

s32 func_80800774_chstinger(Actor *arg0, s32 arg1, s32 arg2) {
    void func_80109EEC(s16*, s32);
    switch (arg1) {
        case 0x95:
            func_80109EEC((s16 *) arg0, 0x10);
            break;
        default:
            return 0;
    }
    return 1;
}

OSThread *chstinger_entrypoint_1(void)
{
    extern u8 D_80800870_chstinger[];

    return (OSThread *) D_80800870_chstinger;
}
