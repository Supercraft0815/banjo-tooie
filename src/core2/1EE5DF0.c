#include "common.h"

extern s32 D_80136F60;
extern s32 D_80136F64;

s32 func_8010C500(void *arg0) {
    s32 func_800CC338(s32 *, s32, s32);
    extern s32 D_80136F50;
    u32 temp_v0;
    u32 temp_v1;

    temp_v0 = (*(u32 *)((s8 *)(arg0) + (0x70)));
    temp_v1 = temp_v0 >> 0x19;
    if (temp_v1 == 0) {
        return 1;
    }
    return (func_800CC338(&D_80136F50, temp_v1 - 1, ((u32) (temp_v0 << 0x16) >> 0x1A) - 1) + 1) != 0;
}

s32 func_8010C550(u8 *arg0, s32 arg1) {
    s32 func_800CC338(s32 *, s32, s32);
    void func_800F5A00(s32, f32[3]);
    f32 sp1C[3];
    u32 temp_v0;

    if (((u32) (*(u32 *)((s8 *)(arg0) + (0x70))) >> 0x19) == 0) {
        return 1;
    }
    func_800F5A00(arg1, sp1C);
    temp_v0 = (*(u32 *)((s8 *)(arg0) + (0x70)));
    return (func_800CC338((s32 *) sp1C, (temp_v0 >> 0x19) - 1, ((u32) (temp_v0 << 0x16) >> 0x1A) - 1) + 1) != 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE5DF0/func_8010C5C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE5DF0/func_8010C668.s")

s32 func_8010C710(s32 arg0) {
    extern s32 D_80136F50;
    f32 func_800EEAA4(f32 a[3], f32 b[3]);
    void func_800EFB24(void *arg0, void *arg1, void *arg2);
    f32 sp1C[3];
    f32 sp20;

    func_800EFB24(&sp1C, arg0 + 4, &D_80136F50);
    return (s32) func_800EEAA4(&sp1C, &sp1C);
}

/* extern */

s32 func_8010C754(void) {
    s32 func_8010C710();
    return (s32) sqrtf((f32) func_8010C710());
}

/* extern */

void func_8010C788(s32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    s32 _plsu_entrypoint_1(s32);
    s32 func_800F4EC8(s32, s32, f32, f32, f32);
    s32 func_800F54E4();
    s32 func_800F8B88();
    s32 sp24;
    s32 temp_v0;

    sp24 = func_800F54E4();
    arg3 -= 30.0f;
    if (func_800F8B88() == 3) {
        temp_v0 = _plsu_entrypoint_1(0xA);
        if (temp_v0 >= 0) {
            func_800F4EC8(temp_v0, arg0, arg1, arg2, arg3);
        }
    }
    func_800F4EC8(sp24, arg0, arg1, arg2, arg3);
}

/* extern */

void func_8010C820(s32 arg0, s32 arg1, s32 arg2) {
    func_8010C788(arg0 + 4, (f32) arg1, 0.0f, (f32) (arg2 + 0x1E));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE5DF0/func_8010C878.s")

/* extern */

void func_8010C908(s32 arg0, s32 arg1) {
    f32 func_8010A40C();
    s32 func_8010C878(s32, s32, f32);
    func_8010C878(arg0, arg1, func_8010A40C());
}

void func_8010C93C(s32 arg0, s32 arg1, f32 arg2) {
    s32 func_8010C878(s32, s32, f32);
    func_8010C878(arg0, arg1, arg2);
}

/* extern */

void func_8010C964(u8 *arg0) {
    void func_8008FB58(f32[3], f32, f32);
    f32 func_8010A40C();
    f32 func_80103F38(u8 *, f32 *);
    f32 sp24[3];
    s32 pad;
    f32 sp1C;

    sp1C = func_80103F38(arg0, sp24);
    func_8008FB58(sp24, 0.0f, func_8010A40C(arg0) * sp1C);
}

s32 func_8010C9B0(f32 *arg0, s32 arg1) {
    extern s32 D_80136F50;
    s32 func_800EFFB4(f32 *, f32, f32 *);
    if ((*(s16 *)((s8 *)(&D_80136F50) + (0xE))) == 0) {
        return 0;
    }
    return func_800EFFB4(arg0, (f32) arg1, (f32 *) &D_80136F50);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE5DF0/func_8010C9FC.s")

s32 func_8010CA74(f32 *arg0, s32 arg1) {
    extern s32 D_80136F50;
    s32 func_800F0064(f32 *, f32, f32 *);
    if ((*(s16 *)((s8 *)(&D_80136F50) + (0xE))) == 0) {
        return 0;
    }
    return func_800F0064(arg0, (f32) arg1, (f32 *) &D_80136F50);
}

s32 func_8010CAC0(f32 *arg0, s32 arg1) {
    extern s32 D_80136F50;
    s32 func_800EFFB4(f32 *, f32, f32 *);
    if ((*(s16 *)((s8 *)(&D_80136F50) + (0xC))) == 0) {
        return 0;
    }
    return func_800EFFB4(arg0, (f32) arg1, (f32 *) &D_80136F50);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE5DF0/func_8010CB0C.s")

 s32 func_8010CB84(f32 *arg0, s32 arg1) {
    extern s32 D_80136F50;
    s32 func_800F0064(f32 *, f32, f32 *);
    if ((*(s16 *)((s8 *)(&D_80136F50) + (0xC))) == 0) {
        return 0;
    }
    return func_800F0064(arg0, (f32) arg1, (f32 *) &D_80136F50);
}

f32 func_8010CBD0(s32 arg0, f32 *arg1) {
    void func_800F5A00(s32, f32[3]);
    func_800F5A00(arg0, arg1);
    arg1[1] += 60.0f;
    return 90.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE5DF0/func_8010CC10.s")

void func_8010CCE0(void)
{
    extern s32 D_80136F8C;

    D_80136F8C = 0;
}

s32 func_8010CCEC(void) {
    extern s32 D_80136F68;
    s32 temp_v0;

    if ((*(s32 *)((s8 *)(&D_80136F68) + (0x24))) >= (*(s32 *)((s8 *)(&D_80136F68) + (0x20)))) {
        return -1;
    }
    temp_v0 = *(&D_80136F68 + (*(s32 *)((s8 *)(&D_80136F68) + 0x24)));
    (*(s32 *)((s8 *)(&D_80136F68) + (0x24))) = (s32) ((*(s32 *)((s8 *)(&D_80136F68) + (0x24))) + 1);
    return temp_v0;
}

void func_8010CD28(s32 arg0) {
    s32 func_800F1DF4(s32, s32 *);
    extern s32 D_80136F50;
    func_800F1DF4(arg0 + 4, &D_80136F50);
}

f32 func_8010CD50(Actor *arg0, u32 arg1) {
    s32 func_800F1DF4(s32, s32 *);
    void func_800F5A00(s32, f32[3]);
    f32 sp1C[3];

    func_800F5A00(arg1, sp1C);
    func_800F1DF4((s32)arg0 + 4, (s32 *)sp1C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE5DF0/func_8010CD88.s")

void func_8010CE28(s32 arg0, f32 *arg1) {
    s32 func_800F18FC(s32, s32 *, f32 *);
    extern s32 D_80136F50;
    func_800F18FC(arg0 + 4, &D_80136F50, arg1);
    *arg1 = 360.0f - *arg1;
}

/* extern */

s32 func_8010CE70(u8 *arg0, s32 arg1, s32 arg2) { extern s32 D_80136F50; s32 func_80102844(u8 *, f32, s32, s32 *); return func_80102844(arg0, (f32) arg1, arg2, &D_80136F50); }

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE5DF0/func_8010CEAC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE5DF0/func_8010CEF8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE5DF0/func_8010CFBC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE5DF0/func_8010D09C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE5DF0/func_8010D12C.s")

/* extern */

s32 func_8010D1E8(void) {
    extern s32 D_80136F50;
    extern s16 D_80136F5C;
    extern s16 D_80136F5E;
    s32 func_8008FD48();
    s32 func_8008FE68(s32);
    s32 func_80090150(void);
    s32 func_8008FF6C();
    s16 func_80090128();
    s32 temp_v0;

    func_8008FE68((s32) &D_80136F50);
    D_80136F5C = func_80090128();
    D_80136F5E = func_80090150();
    D_80136F60 = func_8008FD48();
    temp_v0 = func_8008FF6C();
    D_80136F64 = temp_v0;
    return temp_v0;
}

s32 func_8010D23C(void) {
    extern s16 D_80136F5C;

    return D_80136F5C;
}

s32 func_8010D248(void) {
    extern s16 D_80136F5E;

    return D_80136F5E;
}

void func_8010D254(s32 *arg0) {
    s32 func_800EE7F8();
    extern s32 D_80136F50;
    func_800EE7F8(arg0, &D_80136F50);
}

s32 func_8010D278()
{
    return D_80136F60;
}

s32 func_8010D284()
{
    return D_80136F64;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE5DF0/func_8010D290.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE5DF0/func_8010D350.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE5DF0/func_8010D490.s")

void func_8010D5DC(s32 arg0,s32 arg1)
{
    func_8010114C(arg0,0x32,arg1);
}

/* extern */

void func_8010D600(s32 arg0) {
    s32 func_8008FE68(s32);
    s32 func_800E3980(s32);
    if (func_8010D23C() != 0) {
        func_8008FE68(arg0);
        return;
    }
    func_800E3980(arg0);
}

/* extern */

void func_8010D640(s32 arg0) {
    s32 func_8008FE68(s32);
    s32 func_800DB9B0();
    s32 func_800E3980(s32);
    if ((func_8010D23C() != 0) && (func_800DB9B0() == 0)) {
        func_8008FE68(arg0);
        return;
    }
    func_800E3980(arg0);
}

/* extern */

void func_8010D690(u8 *arg0) {
    f32 func_8010A40C(void *);
    f32 func_80103F38(u8 *, f32 *);
    s32 func_8010D6E0(u8 *, f32 *, f32, f32);
    f32 sp24[3];
    s32 pad;
    f32 sp1C;

    sp1C = func_80103F38(arg0, sp24);
    func_8010D6E0(arg0, sp24, 0.0f, func_8010A40C(arg0) * sp1C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE5DF0/func_8010D6E0.s")
