#include "common.h"

OSThread *chgruntyfireball_entrypoint_0(void)
{
    extern u8 D_80800480_chgruntyfireball[];

    return (OSThread *) D_80800480_chgruntyfireball;
}

void func_8080000C_chgruntyfireball(s16 *arg0) {
    void func_80109EEC(s16 *arg0, s32 arg1);
    (*(s32 *)((s8 *)(arg0) + (0x24))) = 0;
    func_80109EEC(arg0, 0x40);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/grunty/fireball/func_80800030_chgruntyfireball.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/grunty/fireball/func_80800130_chgruntyfireball.s")

void func_80800260_chgruntyfireball(u8 *arg0) {
    s32 _chlightfader_entrypoint_1(s32, f32, s32);
    s32 _subaddieaudioquick_entrypoint_2(u8 *, f32 *, s32 *);
    s32 func_800B53A4(s32);
    s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
    f32 func_800DC178(f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EEB9C(f32 *, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    s32 func_800FFAB0(u8 *);
    s32 func_8010A570(u8 *);
    extern s32 D_80800514_chgruntyfireball;
    extern s32 D_80800524_chgruntyfireball;
    f32 sp7C[3];
    f32 sp70[3];
    s32 temp_s5;
    s32 var_s1;

    func_8010A570(arg0);
    _subaddieaudioquick_entrypoint_2(arg0, (f32 *)(arg0 + 4), &D_80800514_chgruntyfireball);
    func_800EE7F8(sp7C, (f32 *)(arg0 + 4));
    sp7C[1] += -10.0f;
    temp_s5 = func_800B53A4(0xA);
    for (var_s1 = 0; var_s1 < 10; var_s1++) {
        func_800EEB9C(sp70, (f32) var_s1 * 36.0f, func_800DC178(60.0f, 80.0f));
        func_800EF04C(sp70, (f32 *)(arg0 + 4));
        func_800BABB8(temp_s5, sp70, sp7C, 1.0f, &D_80800524_chgruntyfireball);
    }
    if (*(s32 *)(arg0 + 0x24) != 0) {
        *(s32 *)(arg0 + 0x24) = _chlightfader_entrypoint_1(*(s32 *)(arg0 + 0x24), 1.5f, 2);
    }
    func_800FFAB0(arg0);
}

void func_808003D8_chgruntyfireball(f32 *arg0) {
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    void func_800EF368(f32 *, f32);
    extern s32 D_80800554_chgruntyfireball;
    extern s32 D_80800588_chgruntyfireball;
    f32 sp2C[3];
    func_800BBCB8(arg0 + 1, arg0 + 1, 1.0f, 1, &D_80800588_chgruntyfireball);
    func_800EE7F8(sp2C, arg0 + 10);
    func_800EF368(sp2C, 100.0f);
    func_800EF334(sp2C, -1.0f);
    func_800EF04C(sp2C, arg0 + 1);
    func_800BBCB8(sp2C, arg0 + 1, 0.8f, 1, &D_80800554_chgruntyfireball);
}
