#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/crusherboulder/func_80800000_chcrusherboulder.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/crusherboulder/func_80800100_chcrusherboulder.s")

/* extern */

void func_808001CC_chcrusherboulder(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    s32 _sumumbofx_entrypoint_5(u8 *, s32);
    s32 func_80800100_chcrusherboulder(u8 *, f32 *);
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 1U);
    sp1C = temp_v0;
    _sumumbofx_entrypoint_5(temp_v0, 0x40400000);
    func_80800100_chcrusherboulder(sp1C, arg0->position);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/crusherboulder/func_80800210_chcrusherboulder.s")

void func_80800338_chcrusherboulder(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 func_80800100_chcrusherboulder(u8 *, f32 *);
    void func_80800A1C_chcrusherboulder(Actor *, s32);
    void func_80800F38_chcrusherboulder(Actor *);
    f32 func_800D8FF8(void);
    f32 func_800DC0C0(void);
    f32 func_800DC178(f32, f32);
    s32 func_800DA298(s32);
    s32 func_800DA544(s32);
    f32 _sumumbofx_entrypoint_22(u8 *);
    s32 _sumumbofx_entrypoint_1(void *, s32);
    s32 func_8010A800(s32, s32);
    s32 _capod_entrypoint_13(s32, s32, s32, s32);
    s8 _subaddieaudioloop_entrypoint_7(u8, f32 *, u8, s32 *, s32);
    void func_800187B4(s32, f32, f32, f32);
    extern s32 D_808013A0_chcrusherboulder;
    u8 *sp3C;
    s8 sp3B;

    sp3C = func_80100094(arg0, 1U);
    switch (arg0->unk70_10) {
        case 1:
            break;
        case 2:
            func_80800100_chcrusherboulder(sp3C, arg0->position);
            if (arg0->position[1] > 5.0f) {
                arg0->position[1] -= 210.0f * func_800D8FF8();
            } else {
                arg0->unk64_20 = 0;
                arg0->unk58 = 0.0f;
                func_80800A1C_chcrusherboulder(arg0, 3);
            }
            break;
        case 3:
            func_80800100_chcrusherboulder(sp3C, arg0->position);
            arg0->position[1] = 15.0f;
            ((f32 *)arg0->actorData)[7] = 0.0f;
            if (func_800DA298(0x4FB)) {
                func_80800A1C_chcrusherboulder(arg0, 5);
            } else {
                func_80800A1C_chcrusherboulder(arg0, 4);
            }
            func_800DA544(0x4FD);
            func_800DA544(0x9DF);
            break;
        case 4:
            func_80800100_chcrusherboulder(sp3C, arg0->position);
            if (_sumumbofx_entrypoint_22(sp3C) <= 0.02f) {
                _sumumbofx_entrypoint_1(arg0, 1);
                func_8010A800((s32)arg0, 0);
                func_80800A1C_chcrusherboulder(arg0, 6);
            }
            break;
        case 6:
            if (func_800DA298(0x4FB)) {
                _capod_entrypoint_13((s32)arg0->unk0, 0, 4, 0x4030);
                func_80800A1C_chcrusherboulder(arg0, 7);
            }
            break;
        case 5:
            func_80800100_chcrusherboulder(sp3C, arg0->position);
            if (_sumumbofx_entrypoint_22(sp3C) <= 0.02f) {
                _sumumbofx_entrypoint_1(arg0, 1);
                func_8010A800((s32)arg0, 0);
                func_80800A1C_chcrusherboulder(arg0, 7);
            }
        case 7:
            if (arg0->position[0] < -2850.0f) {
                func_80800A1C_chcrusherboulder(arg0, 12);
            }
            if (arg0->position[0] < -1900.0f) {
                if (arg0->position[0] > -2350.0f) {
                    if (((f32 *)arg0->actorData)[7] < 500.0f) {
                        ((f32 *)arg0->actorData)[7] += 2.0f;
                    }
                } else if (((f32 *)arg0->actorData)[7] > 0.0f) {
                    ((f32 *)arg0->actorData)[7] -= 2.0f;
                }
                if (arg0->position[2] > -325.0f && func_800DC0C0() < 0.4f) {
                    arg0->position[2] -= func_800DC178(4.0f, 8.0f);
                    arg0->rotation[2] = -func_800DC178(2.0f, 8.0f);
                }
                if (arg0->position[2] < -375.0f && func_800DC0C0() < 0.4f) {
                    arg0->position[2] += func_800DC178(4.0f, 8.0f);
                    arg0->rotation[2] = func_800DC178(2.0f, 8.0f);
                }
                if (arg0->unk74_30) {
                    arg0->position[0] -= 144.0f * func_800D8FF8() * func_800DC178(0.2f, 0.3f);
                    sp3B = _subaddieaudioloop_entrypoint_7(((u8 *)arg0->actorData)[12], arg0->position, 1, &D_808013A0_chcrusherboulder, *(u32 *)((u8 *)arg0 + 0x70) & 1);
                    ((f32 *)arg0->actorData)[3] = *(f32 *)&sp3B;
                    if (func_800DC0C0() < 0.2f) {
                        arg0->unk74_30 = 0;
                    }
                } else {
                    arg0->position[0] -= 144.0f * func_800D8FF8() * func_800DC178(0.9f, 1.0f);
                    if (func_800DC0C0() < 0.2f) {
                        arg0->unk74_30 = 1;
                    }
                }
                func_80800F38_chcrusherboulder(arg0);
                if (!arg0->unk64_20) {
                    func_800187B4(0, 1.0f, 1.0f, 6.5f);
                    arg0->unk64_20 = 1;
                }
            } else {
                arg0->position[0] -= 144.0f * func_800D8FF8();
            }
            break;
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
            break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/crusherboulder/func_8080087C_chcrusherboulder.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/crusherboulder/func_808009C0_chcrusherboulder.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/crusherboulder/func_80800A1C_chcrusherboulder.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/crusherboulder/func_80800D3C_chcrusherboulder.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/crusherboulder/func_80800ED0_chcrusherboulder.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/crusherboulder/func_80800F38_chcrusherboulder.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/crusherboulder/func_80801064_chcrusherboulder.s")

void func_808010EC_chcrusherboulder(void) {
    s32 func_800BBCB8(s32 *, s32, s32, s32, s32 *);
    extern s32 D_80801464_chcrusherboulder;
    extern s32 D_80801470_chcrusherboulder;
    func_800BBCB8(&D_80801464_chcrusherboulder, 0, 0x3F800000, 3, &D_80801470_chcrusherboulder);
}

void func_80801128_chcrusherboulder(s32 arg0, s32 arg1) {
    s32 func_800BA22C(s32, s32);
    s32 func_800BA3FC(s32, s32);
    s32 func_800BABB8(s32, s32, s32, s32, s32 *);
    extern s32 D_808014BC_chcrusherboulder;
    s32 sp24;
    s32 temp_v0;

    temp_v0 = func_800BABB8(0, arg0, 0, 0x3F800000, &D_808014BC_chcrusherboulder);
    sp24 = temp_v0;
    func_800BA3FC(temp_v0, 0x9DD);
    func_800BA22C(sp24, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/crusherboulder/func_80801184_chcrusherboulder.s")

OSThread *chcrusherboulder_entrypoint_0(void)
{
    extern u8 D_808014EC_chcrusherboulder[];

    return (OSThread *) D_808014EC_chcrusherboulder;
}
