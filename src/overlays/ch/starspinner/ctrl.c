#include "common.h"

OSThread *chstarspinnerctrl_entrypoint_0(void)
{
    extern u8 D_8080092C_chstarspinnerctrl[];

    return (OSThread *) D_8080092C_chstarspinnerctrl;
}

OSThread *chstarspinnerctrl_entrypoint_1(void)
{
    extern u8 D_80800974_chstarspinnerctrl[];

    return (OSThread *) D_80800974_chstarspinnerctrl;
}

void func_80800018_chstarspinnerctrl(s32 *arg0) {
    s32 _chpowerhut_entrypoint_0();
    extern s32 D_80800918_chstarspinnerctrl;
    _chpowerhut_entrypoint_0(arg0, &D_80800918_chstarspinnerctrl);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/starspinner/ctrl/func_8080003C_chstarspinnerctrl.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/starspinner/ctrl/func_80800184_chstarspinnerctrl.s")

void func_808002B4_chstarspinnerctrl(s32 *arg0) {
    s32 _glid_entrypoint_0(s32, s32, s32 *, s32);
    s32 func_800BEA88(s32);
    extern s32 _chstarspinnerctrl_entrypoint_2;
    _glid_entrypoint_0(func_800BEA88(0), 1, &_chstarspinnerctrl_entrypoint_2, *arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/starspinner/ctrl/chstarspinnerctrl_entrypoint_2.s")

/* extern */

void func_80800374_chstarspinnerctrl(Actor *arg0) {
    void func_8010A570(Actor*);
    s32 func_800DA298(s32);
    if (func_800DA298(0x679) != 0) {
        func_8010A570(arg0);
        arg0->unk64_20 = 1;
    }
}

void func_808003B8_chstarspinnerctrl(Actor *arg0) {
    s32 func_8001210C(s32);
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    extern s32 D_808009BC_chstarspinnerctrl;
    f32 sp24[3];

    if (arg0->unk64_20 && (func_8001210C(3) == 0)) {
        func_800EE7F8(sp24, arg0->position);
        func_800EF1B8(sp24, arg0->rotation[1], 40.0f);
        sp24[1] += 30.0f;
        func_800BBCB8(sp24, sp24, 0.8f, 1, &D_808009BC_chstarspinnerctrl);
    }
}

void func_8080044C_chstarspinnerctrl(Actor *arg0, s32 arg1) {
    void func_800DF744(s32, s32);
    s32 func_80101808(void *, s32 (*)(Actor *));
    s32 func_801015D0(Actor *);

    func_800DF744(1, arg0->unk64_20 ? 0 : 1);
    func_800DF744(2, arg0->unk64_20 ? 1 : 0);
    func_80101808(arg0, &func_801015D0);
}

/* extern */

s32 func_808004CC_chstarspinnerctrl(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 func_800DA544(s32);
    void func_800FC660(u32);
    void func_8010A570(Actor *);
    void func_80800554_chstarspinnerctrl(Actor *);
    s32 result;
    if (arg1 == 0x40) {
        func_8010A570(arg0);
        arg0->unk64_20 = 1;
        func_800DA544(0x679);
        func_80800554_chstarspinnerctrl(arg0);
        func_800FC660(0xE);
        _subaddiedialog_entrypoint_11(arg0->unk0, 0x10F4, 4, arg0->position, 0x22);
        result = 1;
    } else {
        return 0;
    }
    return result;
}

void func_80800554_chstarspinnerctrl(Actor *arg0) {
    void func_80018820(s32, f32, f32);
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800C4AF0(f32 *, void *);
    s32 func_800E1610(s32, f32, f32, f32 *);
    extern s32 D_80800A00_chstarspinnerctrl;
    extern s32 D_80800A50_chstarspinnerctrl;
    extern s32 D_80800A98_chstarspinnerctrl;
    extern s32 D_80800AA8_chstarspinnerctrl;
    f32 *temp_s0;

    temp_s0 = arg0->position;
    func_800BBCB8(temp_s0, NULL, 1.0f, 8, &D_80800A50_chstarspinnerctrl);
    func_800BBCB8(temp_s0, NULL, 1.0f, 0xC, &D_80800A00_chstarspinnerctrl);
    func_800C4AF0(temp_s0, &D_80800A98_chstarspinnerctrl);
    func_800C4AF0(temp_s0, &D_80800AA8_chstarspinnerctrl);
    func_800E1610(0, 10.0f, 0.9f, temp_s0);
    func_80018820(0, 2.0f, 0.25f);
}

s32 chstarspinnerctrl_entrypoint_3(s32 arg0, s32 arg1) {
    s32 _glcutDll_entrypoint_20();
    s32 func_800C8A98();
    s32 func_800C8CB8(s32, s32);
    s32 func_800C8D4C(s32, s32 *);
    s32 func_800C8E84(s32, s32 *);
    s32 func_800C8F64(s32, s32);
    s32 func_800DA298(s32);
    extern s32 D_808008E0_chstarspinnerctrl;
    extern s32 D_808008F4_chstarspinnerctrl;
    s32 temp_v0;

    if ((func_800DA298(0xEA) == 0) && (_glcutDll_entrypoint_20() == 0)) {
        return 0;
    }
    temp_v0 = func_800C8A98();
    func_800C8D4C(temp_v0, &D_808008E0_chstarspinnerctrl);
    func_800C8E84(temp_v0, &D_808008F4_chstarspinnerctrl);
    func_800C8CB8(temp_v0, arg1);
    func_800C8F64(temp_v0, 9);
    return temp_v0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/starspinner/ctrl/func_8080069C_chstarspinnerctrl.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/starspinner/ctrl/chstarspinnerctrl_entrypoint_4.s")
