#include "core2/1E7BFA0.h"

s32 func_800A26B0() 
{
    return 0xC;
}

void func_800A26B8(PlayerState *arg0) {
    s32 _fxsplash_entrypoint_2(f32[3], f32);
    void func_80095870(void *, f32 *, f32 *);
    f32 func_800964DC(PlayerState *);
    void func_8009C128(PlayerState *, f32[3]);
    void func_8009FC34(PlayerState *, s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    extern s32 D_80119320[];
    f32 sp34[3];
    f32 sp30;
    f32 sp2C;
    f32 sp28;

    func_8009C128(arg0, sp34);
    sp30 = func_800964DC(arg0);
    func_80095870(arg0, &sp2C, &sp28);
    if (!((sp2C + sp28) < (sp30 - sp34[1]))) {
        sp34[1] = sp30;
        func_8009FC34(arg0, 1);
        func_800BABB8(_fxsplash_entrypoint_2(sp34, 25.0f), 0, 0, 1.0f, D_80119320);
    }
}

/* extern */

void func_800A275C(PlayerState *arg0, s32 arg1) {
    s32 _fxsplash_entrypoint_2(f32[3], f32);
    void func_8008FE94(s32, f32 *);
    f32 func_800964DC(PlayerState *);
    f32 func_8009BB5C(PlayerState *);
    void func_8009FC34(PlayerState *, s32);
    void func_800BA22C(s32, s32);
    void func_800BA930(s32, s16, s16, s16, s16, s16, s16);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 sp34[3];
    f32 sp30;
    s32 sp2C;

    func_8009FC34(arg0, 2);
    sp30 = func_800F10B4(func_8009BB5C(arg0), 0.0f, 500.0f, 70.0f, 250.0f);
    func_8008FE94((*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x124)))) + (4))), sp34);
    if (arg1 == 0) {
        sp34[1] = func_800964DC(arg0);
    }
    sp2C = _fxsplash_entrypoint_2(sp34, 8.0f);
    func_800BA930(sp2C, (s16) -sp30, 0x12C, (s16) -sp30, (s16) sp30, 0x15E, (s16) sp30);
    func_800BA22C(sp2C, 5);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7BFA0/func_800A2848.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7BFA0/func_800A2A00.s")

s32 func_800A2C84(PlayerState *arg0) {
    f32 func_800964DC(PlayerState *);
    s32 func_80096628(PlayerState *);
    void func_8009C128(PlayerState *, f32[3]);
    s32 _fxstep_entrypoint_5(s32, s32, f32);
    s32 _fxstep_entrypoint_6(s32, f32 *);
    f32 sp2C[3];
    s32 pad;
    s32 sp24;

    func_8009C128(arg0, sp2C);
    _fxstep_entrypoint_6(*(*(s32 **)((s8 *)(arg0) + (0x124))), sp2C);
    sp24 = func_80096628(arg0);
    pad = 0;
    return _fxstep_entrypoint_5(*(*(s32 **)((s8 *)(arg0) + (0x124))), sp24, func_800964DC(arg0)) + pad;
}

/* extern */

void func_800A2CE8(PlayerState *arg0, f32 arg1, s32 arg2) {
    s32 anctrl_isAt(s32, f32);
    s32 baanim_getAnimCtrlPtr();
    s32 func_800A2EEC(void *, s32);
    if (anctrl_isAt(baanim_getAnimCtrlPtr(), arg1) != 0) {
        func_800A2EEC(arg0, arg2);
    }
}

/* extern */

void func_800A2D2C(PlayerState *arg0, f32 arg1, s32 arg2) {
    s32 anctrl_isAt(s32, f32);
    s32 baanim_getAnimCtrlPtr();
    s32 func_800A2FCC(PlayerState *, s32);
    if (anctrl_isAt(baanim_getAnimCtrlPtr(), arg1) != 0) {
        func_800A2FCC(arg0, arg2);
    }
}

/* extern */

void func_800A2D70(void *arg0) {
    s32 _fxstep_entrypoint_0(s32);
    _fxstep_entrypoint_0(*(*(s32 **)((s8 *)(arg0) + (0x124))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7BFA0/func_800A2D94.s")

/* extern */

void func_800A2E18(PlayerState *arg0) {
    s32 _fxstep_entrypoint_8(s32, f32, f32);
    s32 bs_getCurrentState(PlayerState *);
    s32 func_8009CA70(PlayerState *, s32, s32);
    s16 func_8009CBDC(PlayerState *, s32);
    s32 sp24;
    void *temp_v0;
    void *temp_v0_2;

    sp24 = bs_getCurrentState(arg0);
    func_800A2C84(arg0);
    if ((func_8009CBDC(arg0, sp24) == 8) || (func_8009CA70(arg0, sp24, 0x40) != 0)) {
        temp_v0 = (*(void **)((s8 *)(arg0) + (0x124)));
        _fxstep_entrypoint_8((*(s32 *)((s8 *)(temp_v0) + (0))), 0.2f, (*(f32 *)((s8 *)(temp_v0) + (8))));
        return;
    }
    temp_v0_2 = (*(void **)((s8 *)(arg0) + (0x124)));
    _fxstep_entrypoint_8((*(s32 *)((s8 *)(temp_v0_2) + (0))), 0.0f, (*(f32 *)((s8 *)(temp_v0_2) + (8))));
}

/* extern */

void func_800A2EAC(void *arg0) {
    s32 _fxstep_entrypoint_9(s32);
    s32 func_800A2C84();
    func_800A2C84();
    _fxstep_entrypoint_9(*(*(s32 **)((s8 *)(arg0) + (0x124))));
}

void func_800A2EDC(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 292) + 8) = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7BFA0/func_800A2EEC.s")

/* extern */

void func_800A2F90(void *arg0, s32 arg1) {
    s32 _fxstep_entrypoint_2(s32, s32);
    s32 func_800A2EEC(void *, s32);
    _fxstep_entrypoint_2(*(*(s32 **)((s8 *)(arg0) + (0x124))), 0);
    func_800A2EEC(arg0, arg1);
}

s32 func_800A2FCC(PlayerState *arg0, s32 arg1) { func_800A2C84(arg0); (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x124)))) + (4))) = (s8) arg1; return _fxstep_entrypoint_12((*(s32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x124)))) + (0)))); }

/* extern */

void func_800A300C(void *arg0) {
    s32 func_800BC3F0(s32);
    *(*(s32 **)((s8 *)(arg0) + (0x124))) = func_800BC3F0(*(*(s32 **)((s8 *)(arg0) + (0x124))));
}

s32 func_800A3040() 
{
    return 0x58;
}

f32 func_800A3048(PlayerState *arg0) {
    s32 func_8008E40C(PlayerState *);
    s32 func_800D3E40(s32);
    extern f32 D_801194D0[];
    extern f32 D_80125560;
    if (func_800D3E40(7) == 0) {
        return 1.0f;
    }
    if (func_8008E40C(arg0) != 0) {
        return D_80125560;
    }
    return D_801194D0[*(u8 *)((s8 *)*(void **)((s8 *)arg0 + 0xA0) + 0x29)];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7BFA0/func_800A30B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7BFA0/func_800A3148.s")

void func_800A3200(PlayerState *arg0, f32 *arg1, f32 *arg2) {
    f32 _basnowball_entrypoint_4(PlayerState *);
    extern f32 D_80119430[][2];
    f32 temp_f0;
    s32 temp_v0;
    f32 *temp_v1;

    temp_v0 = (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xA0)))) + (0x29)));
    temp_v1 = D_80119430[temp_v0];
    *arg1 = temp_v1[0];
    *arg2 = temp_v1[1];
    if (temp_v0 == 2) {
        temp_f0 = _basnowball_entrypoint_4(arg0);
        *arg1 *= temp_f0;
        *arg2 *= temp_f0;
    }
}

TransformationId func_800A3274(PlayerState *self) {
    return (*(u8 **)((u8 *)self + 0xA0))[0x29];
}

u32 func_800A3280(void *arg0) {
    return *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 160) + 42);
}

f32 func_800A328C(void *arg0) {
    return *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 160) + 72);
}

/* extern */

f32 func_800A3298(PlayerState *arg0) {
    f32 func_800964DC();
    return (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xA0)))) + (0x48))) - func_800964DC();
}

/* Single line: IDO schedules this prologue by source line. */
void func_800A32C4(PlayerState *arg0, f32 arg1[3]) { s32 func_800EE7F8(); func_800EE7F8(arg1, *(s32 *)((u8 *)arg0 + 0xA0)); }

u32 func_800A32EC(void *arg0) {
    return *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 160) + 43);
}

s32 func_800A32F8(void *arg0) {
    return *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 160) + 68);
}

/* extern */

s32 func_800A3304(PlayerState *arg0) {
    s32 func_800F8B88();
    return func_800F8B88() == 1;
}

void func_800A3328(void *arg0, s32 arg1) {
    s32 func_800EE7F8();
    func_800EE7F8(arg1, (u8 *)*(void **)((u8 *)arg0 + 0xA0) + 0x2C);
}

u32 func_800A3354(void *arg0) {
    return *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 160) + 84);
}

u32 func_800A3360(void *arg0) {
    return *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 160) + 85);
}

u32 func_800A336C(void *arg0) {
    return *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 160) + 60);
}

f32 func_800A3378(void *arg0) {
    return *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 160) + 56) * (f32)1;
}

f32 func_800A3394(PlayerState *arg0) {
    return *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 160) + 36);
}

/* Single line: IDO schedules this prologue by source line. */
void func_800A33A0(PlayerState *arg0, f32 arg1[3]) { s32 func_800EE7F8(); func_800EE7F8(arg1, *(s32 *)((u8 *)arg0 + 0xA0) + 0xC); }

void func_800A33CC(void *arg0, f32 *arg1) { s32 func_800EE7F8(); func_800EE7F8(arg1, (u8 *)*(void **)((u8 *)arg0 + 0xA0) + 0x18); }

u32 func_800A33F8(void *arg0) {
    return *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 160) + 40);
}

u32 func_800A3404(void *arg0) {
    return *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 160) + 63);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7BFA0/func_800A3410.s")

void func_800A34A0(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 160) + 42) = arg1;
}

void func_800A34AC(PlayerState *arg0, f32 arg1[3]) {
    s32 func_800EE7F8();
    func_800EE7F8(*(void **)((u8 *)arg0 + 0xA0), arg1);
}

void func_800A34CC(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 160) + 43) = arg1;
}

void func_800A34D8(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 160) + 68) = arg1;
}

void func_800A34E4(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 160) + 60) = arg1;
}

/* extern */

void func_800A34F0(void *arg0) {
    s32 func_800EE7F8(s32);
    func_800EE7F8((*(s32 *)((s8 *)(arg0) + (0xA0))) + 0xC);
}

/* extern */

void func_800A3514(void *arg0) {
    s32 func_800EE7F8(s32);
    func_800EE7F8((*(s32 *)((s8 *)(arg0) + (0xA0))) + 0x18);
}

void func_800A3538(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 160) + 40) = arg1;
}

void func_800A3544(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 160) + 63) = arg1;
}

void func_800A3550(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 160) + 80) = arg1;
}

/* extern */

void func_800A355C(void *arg0) {
    s32 func_8008EF3C(void *, s32);
    f32 func_8009C150();
    s32 func_800F3ED0(void *);
    s32 player_inWater(PlayerState *);
    int player_isStable(PlayerState *);
    f32 sp24;
    s32 sp20;
    void *temp_v0;

    sp24 = func_8009C150();
    sp20 = func_800F3ED0(arg0);
    if ((player_isStable(arg0) != 0) || (player_inWater(arg0) != 0) || ((sp20 == 0xA) && (func_8008EF3C(arg0, 0) != 3)) || (sp20 == 5)) {
        func_800A3550(arg0, 1);
    } else {
        func_800A3550(arg0, 2);
    }
    temp_v0 = (*(void **)((s8 *)(arg0) + (0xA0)));
    if (((*(u8 *)((s8 *)(temp_v0) + (0x50))) != 2) || !(sp24 <= (*(f32 *)((s8 *)(temp_v0) + (0x4C))))) {
        (*(f32 *)((s8 *)(temp_v0) + (0x48))) = (f32) (*(f32 *)((s8 *)(temp_v0) + (0x4C)));
        (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xA0)))) + (0x4C))) = sp24;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7BFA0/func_800A3644.s")

void func_800A380C(void *arg0) {
    extern f32 D_80125568;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xA0)))) + (0x38))) = (f32) D_80125568;
}

/* extern */

void func_800A3820(PlayerState *arg0) {
    void func_8009C128(PlayerState *, f32[3]);
    f32 func_8009C150(PlayerState *);
    u32 func_8009E958(void);
    void func_800EFD24(f32 *);
    f32 temp_f0;

    func_800EFD24((*(f32 **)((s8 *)(arg0) + (0xA0))));
    func_800EFD24((*(f32 **)((s8 *)(arg0) + (0xA0))) + 3);
    func_8009C128(arg0, (*(f32 **)((s8 *)(arg0) + (0xA0))) + 11);
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0xA0)))) + (0x3D))) = 0;
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0xA0)))) + (0x38))) = 0.0f;
    func_800A380C(arg0);
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0xA0)))) + (0x3C))) = 1;
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0xA0)))) + (0x40))) = 0.0f;
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0xA0)))) + (0x50))) = 0;
    temp_f0 = func_8009C150(arg0);
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0xA0)))) + (0x48))) = temp_f0;
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0xA0)))) + (0x4C))) = temp_f0;
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0xA0)))) + (0x29))) = 0;
    func_800A3410(arg0, func_8009E958());
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0xA0)))) + (0x54))) = 1;
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0xA0)))) + (0x55))) = 1;
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0xA0)))) + (0x3E))) = 1;
}

void func_800A38F0(PlayerState *arg0, s32 arg1, s32 arg2) {
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xA0)))) + (0x54))) = (s8) arg1;
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xA0)))) + (0x55))) = (s8) arg2;
}

void func_800A3904(PlayerState *arg0, s32 arg1) {
    (*(u8 **)((u8 *)arg0 + 0xA0))[0x3E] = arg1;
}

void func_800A3910(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 160) + 61) = arg1;
}

void func_800A391C(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 160) + 36) = arg1;
}

void func_800A392C(PlayerState *arg0, s32 arg1) {
    void func_8009C128(PlayerState *, f32[3]);
    s32 func_800C05B8(s32, s32, f32*, Unk80132ED0*, s32, s32, s16);
    f32 sp2C[3];

    func_8009C128(arg0, sp2C);
    func_800C05B8(arg1, 2, sp2C, NULL, 0, 0, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7BFA0/func_800A3970.s")

/* extern */

void func_800A3A80(PlayerState *arg0) {
    s32 baflag_clear(s32, s32);
    s32 func_80096568(void *, s32);
    void func_8009BD18(void *, f32);
    void func_8009C128(PlayerState *, f32[3]);
    s32 func_8009E71C(void *, s32);
    s32 func_800A3644(void *);
    u8 func_800D9078(f32 *);
    s32 player_inWater(PlayerState *);
    int player_isStable(PlayerState *);
    u8 *temp_v0;

    temp_v0 = (*(u8 **)((s8 *)(arg0) + (0xA0)));
    if ((*(f32 *)((s8 *)(temp_v0) + (0x40))) != 0.0f) {
        func_800D9078((f32 *)(temp_v0 + 0x40));
    }
    if (player_isStable(arg0) != 0) {
        func_8009C128(arg0, (f32 *)((*(u8 **)((s8 *)(arg0) + (0xA0))) + 0x2C));
    }
    if ((player_isStable(arg0) != 0) || (func_8009E71C(arg0, 0xA) != 0)) {
        baflag_clear(arg0, 5);
        baflag_clear(arg0, 0x12);
    }
    if (player_inWater(arg0) != 0) {
        baflag_clear(arg0, 5);
        baflag_clear(arg0, 0x12);
    }
    func_800A3644(arg0);
    func_800A355C(arg0);
    if (func_80096568(arg0, 0x600) != 0) {
        func_8009BD18(arg0, 0.75f);
    }
}
