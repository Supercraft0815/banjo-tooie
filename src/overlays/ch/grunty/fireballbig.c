#include "common.h"

OSThread *chgruntyfireballbig_entrypoint_0(void)
{
    extern u8 D_80800680_chgruntyfireballbig[];

    return (OSThread *) D_80800680_chgruntyfireballbig;
}

void func_8080000C_chgruntyfireballbig(s16 *arg0) {
    void func_80109EEC(s16 *arg0, s32 arg1);
    (*(s32 *)((s8 *)(arg0) + (0x24))) = 0;
    func_80109EEC(arg0, 0x40);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/grunty/fireballbig/func_80800030_chgruntyfireballbig.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/grunty/fireballbig/func_808001B4_chgruntyfireballbig.s")

void func_8080034C_chgruntyfireballbig(u8 *arg0) {
    s32 _chlightfader_entrypoint_1(s32, f32, s32);
    s32 _subaddieaudioquick_entrypoint_2(u8 *, f32 *, s32 *);
    s32 func_800B53A4(s32);
    s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
    f32 func_800DC178(f32, f32);
    s32 func_800EE7F8(f32 *, f32 *);
    void func_800EEB9C(f32 *, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    s32 func_800FFAB0(u8 *);
    s32 func_8010A570(u8 *);
    extern s32 D_80800714_chgruntyfireballbig;
    extern s32 D_80800724_chgruntyfireballbig;
    f32 sp7C[3];
    f32 sp70[3];
    s32 temp_s5;
    s32 var_s1;

    func_8010A570(arg0);
    _subaddieaudioquick_entrypoint_2(arg0, (f32 *)(arg0 + 4), &D_80800714_chgruntyfireballbig);
    func_800EE7F8(sp7C, (f32 *)(arg0 + 4));
    sp7C[1] += -10.0f;
    temp_s5 = func_800B53A4(0xA);
    for (var_s1 = 0; var_s1 < 10; var_s1++) {
        func_800EEB9C(sp70, (f32) var_s1 * 36.0f, func_800DC178(60.0f, 80.0f));
        func_800EF04C(sp70, (f32 *)(arg0 + 4));
        func_800BABB8(temp_s5, sp70, sp7C, 1.0f, &D_80800724_chgruntyfireballbig);
    }
    if (*(s32 *)(arg0 + 0x24) != 0) {
        *(s32 *)(arg0 + 0x24) = _chlightfader_entrypoint_1(*(s32 *)(arg0 + 0x24), 1.5f, 2);
    }
    func_800FFAB0(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/grunty/fireballbig/func_808004C4_chgruntyfireballbig.s")

/* extern */

void func_80800590_chgruntyfireballbig(Actor *arg0) {
    f32 func_800EEB40(f32 *, f32 *);
    void func_800EEBF0(f32 *, f32 *, f32);
    f32 func_800EEF94(f32 *);
    void func_800F18FC(f32 *, f32 *, f32 *);
    void func_800F5A00(s32, f32 *);
    s32 func_800F6438(u32);
    f32 sp3C[3];
    f32 sp34[2];
    f32 distance;

    if (!arg0->unk64_20 && func_800F6438(arg0->unk6C_0)) {
        func_800F5A00(arg0->unk6C_0, sp3C);
        sp3C[1] += 50.0f;
        distance = func_800EEB40(arg0->position, sp3C);
        if (distance < (((f32 *)arg0->actorData)[0] * ((f32 *)arg0->actorData)[0])) {
            arg0->unk64_20 = 1;
            return;
        }
        func_800F18FC(arg0->position, sp3C, sp34);
        func_800EEBF0((f32 *)&arg0->actorData[4], sp34, func_800EEF94((f32 *)&arg0->actorData[4]));
    }
}
