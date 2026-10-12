#include "core2/1E7BFA0.h"

s32 func_800A26B0() 
{
    return 0xC;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7BFA0/func_800A26B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7BFA0/func_800A275C.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7BFA0/func_800A2E18.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7BFA0/func_800A3048.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7BFA0/func_800A30B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7BFA0/func_800A3148.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7BFA0/func_800A3200.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7BFA0/func_800A355C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7BFA0/func_800A3644.s")

void func_800A380C(void *arg0) {
    extern f32 D_80125568;
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xA0)))) + (0x38))) = (f32) D_80125568;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7BFA0/func_800A3820.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7BFA0/func_800A3A80.s")
