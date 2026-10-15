#include "common.h"

/* extern */

void func_80800000_chblackeye(s32 arg0, s32 arg1) {
    s32 _subaddieaudioquick_entrypoint_2(s32, s32, s32);
    s32 func_800DA298(s32);
    if (func_800DA298(0) == 0) {
        _subaddieaudioquick_entrypoint_2(arg0, arg0 + 4, arg1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/blackeye/func_8080003C_chblackeye.s")

void func_80800128_chblackeye(Actor *arg0, s32 arg1) {
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 func_800D0B68(u32, u32);
    s32 func_800DA9E4(s32, s32);
    s32 func_800DC128(s32, s32);
    extern f32 D_80800EAC_chblackeye;
    s16 var_a1;
    s32 sp28;

    sp28 = 4;
    if (func_800DA9E4(0xE4, 1) == 0) {
        var_a1 = 0x100C;
        sp28 = 0xC;
    } else if ((arg1 != 0) && (func_800D0B68(0x19, 7) == 0)) {
        var_a1 = arg0->unk6C_0 + 0x1010;
        sp28 = 0xC;
        if (arg0->unk6C_0 < 2U) {
            arg0->unk6C_0++;
        } else {
            arg0->unk6C_0 = 0;
        }
    } else {
        var_a1 = func_800DC128(0x100D, 0x1010);
    }
    _subaddiedialog_entrypoint_11(arg0->unk0, var_a1, sp28, &D_80800EAC_chblackeye, 0x6E);
    arg0->unk74_30 = 1;
}

void func_80800224_chblackeye(Actor *arg0) {
    void func_800EF04C(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    void func_800EF934(f32 *, f32 *, f32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    f32 *position[5];
    Actor *var_v0;
    f32 temp;
    s32 var_v1;

    func_800EFA4C((f32 *)arg0->actorData, -250.0f, 0.0f, -200.0f);
    func_800EFA4C((f32 *)&arg0->actorData[4], 250.0f, 450.0f, -950.0f);
    func_800EF334((f32 *)arg0->actorData, arg0->scale);
    func_800EF334((f32 *)&arg0->actorData[4], arg0->scale);
    func_800EF934((f32 *)arg0->actorData, (f32 *)arg0->actorData, arg0->rotation[1]);
    func_800EF934((f32 *)&arg0->actorData[4], (f32 *)&arg0->actorData[4], arg0->rotation[1]);
    position[0] = arg0->position;
    func_800EF04C((f32 *)&arg0->actorData[4], position[0]);
    func_800EF04C((f32 *)arg0->actorData, position[0]);
    var_v1 = 0;
    var_v0 = arg0;
    do {
        var_v1 += 4;
        if (((f32 *)var_v0->actorData)[0] < ((f32 *)var_v0->actorData)[4]) {
            temp = ((f32 *)var_v0->actorData)[4];
            ((f32 *)var_v0->actorData)[4] = ((f32 *)var_v0->actorData)[0];
            ((f32 *)var_v0->actorData)[0] = temp;
        }
        var_v0 = (Actor *)((u8 *)var_v0 + 4);
    } while (var_v1 != 0xC);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/blackeye/func_80800314_chblackeye.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/blackeye/func_808003C0_chblackeye.s")

void func_80800444_chblackeye(Actor* arg0) 
{
    if (func_80100094(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/blackeye/func_80800478_chblackeye.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/blackeye/func_8080061C_chblackeye.s")

void func_80800774_chblackeye(Actor *arg0) {
    s32 pad[2];
    s32 func_800BBCB8(s32 *, s32 *, f32, s32, s32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    void func_800EF934(f32 *, f32 *, f32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    extern s32 D_80800E20_chblackeye;
    extern s32 D_80800F18_chblackeye;
    extern s32 D_80800F6C_chblackeye;
    f32 sp2C;

    func_800EFA4C(&sp2C, 0.0f, 40.0f, -800.0f);
    func_800EF334(&sp2C, arg0->scale);
    func_800EF934(&sp2C, &sp2C, arg0->rotation[1]);
    func_800EF04C(&sp2C, arg0->position);
    func_800BBCB8(&sp2C, &sp2C, 1.0f, 3, &D_80800F18_chblackeye);
    func_800BBCB8(&sp2C, &sp2C, 1.0f, 1, &D_80800F6C_chblackeye);
    func_80800000_chblackeye((s32) arg0, (s32) &D_80800E20_chblackeye);
    (*(u8 *)((s8 *)(arg0) + (0x65))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x65))) & 0xFFEF);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/blackeye/func_80800838_chblackeye.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/blackeye/func_80800BC4_chblackeye.s")

OSThread *chblackeye_entrypoint_0(void)
{
    extern u8 D_8080104C_chblackeye[];

    return (OSThread *) D_8080104C_chblackeye;
}
