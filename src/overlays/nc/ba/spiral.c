#include "nc/ba/spiral.h"

s32 ncbaspiral_entrypoint_0() 
{
    return 0x10;
}

void func_80800008_ncbaspiral(PlayerState* arg0, f32* arg1)
{
    func_80112524(arg0,arg1);
}

void func_80800028_ncbaspiral(PlayerState* arg0, f32* arg1)
{
    func_80112524(arg0,arg1);
}

/* extern */

void ncbaspiral_entrypoint_1(void *arg0) {
    s32 func_800EFD24(s32);
    void func_80111B8C(s32 *, f32, f32);
    void func_801124D0(s32, s32);
    void func_80115858(void *, s32);
    void func_80115870(void *, f32);
    func_80111B8C(arg0, 4.0f, 8.0f);
    func_801124D0(arg0, 1);
    func_80115858(arg0, 1);
    func_80115870(arg0, 5.0f);
    func_800EFD24((s32 *)((s8 *)(*(s32 **)((s8 *)(arg0) + (0x48))) + 4));
    *(*(s32 **)((s8 *)(arg0) + (0x48))) = -1;
}

void ncbaspiral_entrypoint_2(s32 arg0) 
{
}
/* extern */

void ncbaspiral_entrypoint_3(PlayerState *arg0) {
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EEBF0(f32 *, f32 *, f32);
    f32 func_800EEF94(f32 *);
    void func_800EFB24(void *, void *, void *);
    void func_800F1A88(f32 *, f32 *);
    s32 func_800F1E6C(f32 *, f32 *, f32 *);
    void func_80110790(s32, f32 *);
    void func_801107F0(void *, f32 *);
    void func_80110A68(s32, s32, s32);
    void func_80110F44(void *);
    s32 func_80111CC8(void *, f32 *);
    f32 func_80112C3C(void *, f32);
    void func_80112D08(void *, s32, f32, f32);
    s32 func_801138A0(void *);
    s32 func_801138F4(PlayerState *);
    f32 func_80115358(void *, f32);
    int func_80115580(void *, f32 *);
    f32 func_80115750(Actor *, f32);
    f32 sp54[3];
    f32 sp48[3];
    f32 sp3C[3];
    f32 sp30[3];
    f32 sp2C;
    f32 sp24[2];
    f32 sp20;

    func_80800028_ncbaspiral(arg0, sp54);
    func_801107F0(arg0, sp3C);
    func_800EFB24(sp48, sp3C, sp54);
    sp2C = func_800EEF94(sp48);
    func_800F1A88(sp48, sp24);
    sp2C = func_80115358(arg0, sp2C);
    sp24[0] = func_80115750(arg0, sp24[0]);
    func_800F1E6C(*(f32 **)((s8 *)arg0 + 0x48) + 1, sp54, &sp20);
    func_80112D08(arg0, 5, sp20 - 10.0f, sp20 + 10.0f);
    sp24[1] = func_80112C3C(arg0, sp24[1]);
    func_800EEBF0(sp48, sp24, sp2C);
    func_800EE780(sp3C, sp54, sp48);
    if ((func_80111CC8(arg0, sp3C) != 0) && ((func_801138A0(arg0) != 0) || (func_80115580(arg0, sp54) != 0)) && (func_801138F4(arg0) != 0)) {
        func_80110F44(arg0);
    }
    func_80800008_ncbaspiral(arg0, sp54);
    func_80110A68(arg0, sp30, sp54);
    func_80110790(arg0, sp30);
}

/* extern */

void ncbaspiral_entrypoint_4(void *arg0) {
    s32 func_800EE7F8(s32 *);
    func_800EE7F8(*(s32 **)((s8 *)arg0 + 0x48) + 1);
    *(*(s32 **)((s8 *)(arg0) + (0x48))) = -1;
}

/* extern */

void ncbaspiral_entrypoint_5(void *arg0, s32 arg1) {
    void _cadbfunc_entrypoint_24(s32 *);
    Prop *_gccubesearch_entrypoint_1(u32, f32[3]);
    void _gspropctrl_entrypoint_11(Prop *, f32[3]);
    s32 func_800A5800(s32);
    void func_801107B0(void *, f32 *);
    s32 sp2C;
    f32 sp1C[4];

    if (arg1 != *(*(s32 **)((s8 *)(arg0) + (0x48)))) {
        func_800A5800(arg1);
        _cadbfunc_entrypoint_24(&sp2C);
        func_801107B0(arg0, sp1C);
        _gspropctrl_entrypoint_11(_gccubesearch_entrypoint_1(sp2C + 0x1D1, sp1C), (f32 *)((*(s32 **)((s8 *)(arg0) + (0x48))) + 1));
        *(*(s32 **)((s8 *)(arg0) + (0x48))) = arg1;
    }
}
