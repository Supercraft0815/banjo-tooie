#include "common.h"

/* extern */

void func_80800000_ncpoducam(u8 *arg0) {
    s32 func_800EFD24(s32);
    func_800EFD24(arg0 + 4);
    func_800EFD24(arg0 + 0x10);
    func_800EFD24(arg0 + 0x24);
    func_800EFD24(arg0 + 0x30);
    (*(s8 *)((s8 *)(arg0) + (0x63))) = 0;
    (*(f32 *)((s8 *)(arg0) + (0x50))) = 40.0f;
    (*(f32 *)((s8 *)(arg0) + (0x54))) = 1.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ucam/ncpoducam_entrypoint_0.s")

/* extern */

 void *ncpoducam_entrypoint_1(s16 arg0) {
    void *func_8001B798(s16);
    return func_8001B798(arg0);
}

/* extern */

void ncpoducam_entrypoint_2(u8 *arg0, s32 arg1, s32 arg2) {
    s32 func_8080145C_ncpoducam(s32, s32, s32);
    (*(s16 *)((s8 *)(arg0) + (0x58))) = arg2;
    func_8080145C_ncpoducam((s32)arg0, arg1, 1);
}

void ncpoducam_entrypoint_3(void *arg0, void *arg1) {
    (*(void **)((s8 *)(arg0) + (0x1C))) = arg1;
    (*(u32 *)((s8 *)(arg0) + (0x20))) = ((u32) (*(u16 *)((u8 *)arg1 + 0x12))) >> 1;
}

void ncpoducam_entrypoint_4(s16 *arg0, s32 arg1) {
    arg0[36] = arg1;
}

s32 ncpoducam_entrypoint_5(s16 *arg0) {
    return arg0[36];
}

void func_80800160_ncpoducam(u8 *arg0) {
    s32 func_8001B754(s16);
    s16 temp_a0;
    s16 temp_a1;

    temp_a1 = (*(s16 *)((s8 *)(arg0) + (0)));
    if (temp_a1 != 0) {
        func_8001B754(temp_a1);
        (*(s16 *)((s8 *)(arg0) + (0))) = 0;
    }
    temp_a0 = (*(s16 *)((s8 *)(arg0) + (2)));
    if (temp_a0 != 0) {
        func_8001B754(temp_a0);
        (*(s16 *)((s8 *)(arg0) + (2))) = 0;
    }
}

void ncpoducam_entrypoint_6(s16 arg0) {
    s32 func_8001B754(s16);
    func_80800160_ncpoducam(ncpoducam_entrypoint_1(arg0));
    func_8001B754(arg0);
}

s32 func_808001F0_ncpoducam(void *arg0, s32 arg1) {
    return arg1 == -1 ? 0 : ((u32)arg1 == ((u32)*(u16 *)((u8 *)arg0 + 0x12) >> 1));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ucam/func_8080021C_ncpoducam.s")

void func_808003A8_ncpoducam(u8 *arg0, s32 arg1) {
    void _cadbfunc_entrypoint_24(s32 *);
    Unk80132ED0 *_subaddiefind_entrypoint_12(s32);
    void _suspline_entrypoint_3(s32, s32, f32 *);
    f32 _suspline_entrypoint_4(s32, s32);
    void _suspline_entrypoint_5(s32, f32 *);
    f32 func_800136E4(f32);
    void *func_8001B798(s16);
    s32 func_800A5800(s16);
    s32 func_800EE7F8();
    void func_800EF04C(f32 *, f32 *);
    void func_800EF5A0(f32 *, f32 *, f32, f32, f32);
    void func_800EF6A8(f32 *, f32 *, f32, f32, f32);
    f32 func_800F1828(f32 *, f32 *);
    s32 func_800F18FC(f32 *, f32 *, f32 *);
    f32 func_800F1DCC(f32, f32);
    f32 func_800F1DF4(f32 *, f32 *);
    Actor *func_80106790(Unk80132ED0 *);
    s32 func_8080021C_ncpoducam(void *);
    f32 sp84[3];
    f32 sp78[3];
    f32 sp6C[3];
    f32 sp60[3];
    f32 sp54[3];
    f32 sp48[3];
    u8 *actor;
    s32 spline;
    s32 id;

    spline = func_8001B798(*(s16 *)arg0);
    _suspline_entrypoint_3(spline, 0, sp60);
    _suspline_entrypoint_3(spline, 2, sp54);
    _suspline_entrypoint_3(spline, 1, sp48);
    if (*(s16 *)(arg0 + 0x48) & 8) {
        if (func_808001F0_ncpoducam(*(void **)(arg0 + 0x1C), *(s32 *)(arg0 + 0x20))) {
            actor = (u8 *)func_80106790(*(Unk80132ED0 **)(arg0 + 0x1C));
        } else {
            actor = NULL;
        }
    } else {
        func_800A5800(*(s16 *)(arg0 + 0x58));
        _cadbfunc_entrypoint_24(&id);
        actor = (u8 *)_subaddiefind_entrypoint_12(id);
    }
    if (actor != NULL) {
        if (!(*(s16 *)(arg0 + 0x48) & 0x400) || arg0[0x63] == 0) {
            func_800EE7F8((f32 *)(arg0 + 0x30), (f32 *)(actor + 0x44));
            func_800EE7F8((f32 *)(arg0 + 0x24), (f32 *)(actor + 4));
            arg0[0x63] = 1;
        } else {
            *(f32 *)(arg0 + 0x30) += func_800F1DCC(*(f32 *)(actor + 0x44), *(f32 *)(arg0 + 0x30)) * 0.1f;
            *(f32 *)(arg0 + 0x34) += func_800F1DCC(*(f32 *)(actor + 0x48), *(f32 *)(arg0 + 0x34)) * 0.1f;
            *(f32 *)(arg0 + 0x38) += func_800F1DCC(*(f32 *)(actor + 0x4C), *(f32 *)(arg0 + 0x38)) * 0.1f;
            *(f32 *)(arg0 + 0x24) += (*(f32 *)(actor + 4) - *(f32 *)(arg0 + 0x24)) * 0.1f;
            *(f32 *)(arg0 + 0x28) += (*(f32 *)(actor + 8) - *(f32 *)(arg0 + 0x28)) * 0.1f;
            *(f32 *)(arg0 + 0x2C) += (*(f32 *)(actor + 0xC) - *(f32 *)(arg0 + 0x2C)) * 0.1f;
        }
    }
    func_800EE7F8((f32 *)(arg0 + 4), sp54);
    func_800EF6A8((f32 *)(arg0 + 4), (f32 *)(arg0 + 0x30), *(f32 *)(arg0 + 4), *(f32 *)(arg0 + 8), *(f32 *)(arg0 + 0xC));
    func_800EF04C((f32 *)(arg0 + 4), (f32 *)(arg0 + 0x24));
    if (!(*(s16 *)(arg0 + 0x48) & 1)) {
        func_800EE7F8(sp84, sp60);
        func_800EF6A8(sp84, (f32 *)(arg0 + 0x30), sp84[0], sp84[1], sp84[2]);
        func_800EF04C(sp84, (f32 *)(arg0 + 0x24));
        func_800EE7F8(sp78, sp60);
        func_800EF5A0(sp6C, sp48, 100.0f, 0.0f, 0.0f);
        func_800EF04C(sp78, sp6C);
        func_800EF6A8(sp78, (f32 *)(arg0 + 0x30), sp78[0], sp78[1], sp78[2]);
        func_800EF04C(sp78, (f32 *)(arg0 + 0x24));
        *(f32 *)(arg0 + 0x18) = func_800136E4(-func_800F1828(sp84, sp78));
        *(f32 *)(arg0 + 0x10) = -func_800136E4(func_800F1828(sp84, (f32 *)(arg0 + 4)));
        *(f32 *)(arg0 + 0x14) = func_800136E4(func_800F1DF4(sp84, (f32 *)(arg0 + 4)));
    }
    if (func_8080021C_ncpoducam(arg0)) {
        func_800F18FC((f32 *)(arg0 + 0x3C), (f32 *)(arg0 + 4), (f32 *)(arg0 + 0x10));
        *(f32 *)(arg0 + 0x10) = -*(f32 *)(arg0 + 0x10);
        *(f32 *)(arg0 + 0x18) = 0.0f;
    }
    *(f32 *)(arg0 + 0x50) = _suspline_entrypoint_4(spline, 0);
    if (arg1 == 0) {
        _suspline_entrypoint_5(spline, sp54);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ucam/func_80800704_ncpoducam.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ucam/func_808007D0_ncpoducam.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ucam/func_80800854_ncpoducam.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ucam/func_80800944_ncpoducam.s")

/* extern */

void func_80800A18_ncpoducam(u8 *arg0) {
    s32 _susplinet_entrypoint_17(s32);
    s32 _susplinet_entrypoint_7(s32, s32, u8 *);
    f32 _susplinet_entrypoint_8(s32, s32);
    void *func_8001B798(s16);
    s32 temp_v0;

    temp_v0 = func_8001B798((*(s16 *)((s8 *)(arg0) + (2))));
    _susplinet_entrypoint_17(temp_v0);
    _susplinet_entrypoint_7(temp_v0, 0, arg0 + 4);
    _susplinet_entrypoint_7(temp_v0, 1, arg0 + 0x10);
    (*(f32 *)((s8 *)(arg0) + (0x50))) = _susplinet_entrypoint_8(temp_v0, 0);
    (*(f32 *)((s8 *)(arg0) + (0x54))) = _susplinet_entrypoint_8(temp_v0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ucam/func_80800A94_ncpoducam.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ucam/func_80800B74_ncpoducam.s")

/* extern */

s32 func_80800CB8_ncpoducam(s16 arg0, s32 arg1) {
    s32 func_800A5800(s16);
    s32 _cadbfunc_entrypoint_16(s16 *);
    s32 var_s0;

    var_s0 = 0;
    if (arg0 != -1) {
        do {
            func_800A5800(arg0);
            _cadbfunc_entrypoint_16(&arg0);
            var_s0 += 1;
        } while (arg0 != -1);
    }
    return var_s0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ucam/func_80800D28_ncpoducam.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ucam/func_80800F64_ncpoducam.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ucam/func_80801274_ncpoducam.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ucam/func_8080145C_ncpoducam.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ucam/ncpoducam_entrypoint_7.s")

/* extern */

s32 ncpoducam_entrypoint_8(void *arg0, s32 arg1) {
    s32 _susplinet_entrypoint_4(void *, s32);
    void *func_8001B798(s16);
    u8 temp_v0;

    temp_v0 = (*(u8 *)((s8 *)(*(void **)&arg0) + (0x60)));
    if ((temp_v0 != 5) && (temp_v0 != 6) && (temp_v0 == 8)) {
        return _susplinet_entrypoint_4(func_8001B798((*(s16 *)((s8 *)(arg0) + (2)))), arg1);
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ucam/ncpoducam_entrypoint_9.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/ucam/ncpoducam_entrypoint_10.s")

/* extern */

void ncpoducam_entrypoint_11(s32 arg0) {
    s32 func_800EE7F8(s32);
    func_800EE7F8(arg0 + 0x3C);
}
