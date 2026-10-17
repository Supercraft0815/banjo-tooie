#include "common.h"

s16 *func_80800000_fxegg(s32 arg0) {
    extern s16 D_80800550_fxegg[];
    s32 i;
    while (1) {
        for (i = 0; D_80800550_fxegg[i * 3]; i++) {
            if (arg0 == D_80800550_fxegg[i * 3]) {
                return &D_80800550_fxegg[i * 3];
            }
        }
        arg0 = 1;
    }
}

/* extern */

void fxegg_entrypoint_0(s32 arg0, f32 arg1[3], f32 arg2) {
    s32 func_8080009C_fxegg(s32, s32, f32[3], f32);
    s16 *temp_v0;
    s32 sp18;

    temp_v0 = func_80800000_fxegg(arg0);
    sp18 = func_8080009C_fxegg(temp_v0[1], temp_v0[2], arg1, arg2);
    func_800BA75C(sp18, arg1);
    func_800BA22C(sp18, 5);
}

s32 func_8080009C_fxegg(s32 arg0, s32 arg1, f32 arg2[3], f32 arg3) {
    s32 func_800B5BE4(s32);
    s32 func_800BA670(s32, s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    extern s32 D_80800574_fxegg;
    s32 sp24;
    s32 temp_v0;

    temp_v0 = func_800B5BE4(arg1);
    sp24 = temp_v0;
    func_800BA670(temp_v0, arg0);
    return func_800BABB8(sp24, arg2, arg2, arg3, &D_80800574_fxegg);
}

void func_808000F8_fxegg(s32 arg0, f32 arg1[3], s32 arg2, f32 arg3) {
    void func_800BA3FC(s32, s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    extern s32 D_808005B0_fxegg;
    func_800BA3FC(arg0, arg2);
    func_800BABB8(arg0, arg1, 0, arg3, &D_808005B0_fxegg);
}

/* extern */

s32 fxegg_entrypoint_1(f32 arg0[3], f32 arg1) {
    s32 func_800B5BE4(s32);
    s32 sp1C;

    sp1C = func_800B5BE4(0xC);
    func_808000F8_fxegg(sp1C, arg0, 0x9E5, arg1);
    return sp1C;
}

/* extern */

s32 fxegg_entrypoint_2(f32 arg0[3], f32 arg1) {
    s32 func_800B5BE4(s32);
    s32 sp1C;

    sp1C = func_800B5BE4(0xB);
    func_808000F8_fxegg(sp1C, arg0, 0x9E0, arg1);
    return sp1C;
}

void func_808001CC_fxegg(s32 arg0, f32 arg1[3], f32 arg2) {
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    extern s32 D_808005D8_fxegg;
    func_800BABB8(arg0, arg1, 0, arg2, &D_808005D8_fxegg);
}

/* extern */

s32 fxegg_entrypoint_3(s32 arg0, s32 arg1) {
    s32 func_800B5BE4(s32);
    void func_808001CC_fxegg(s32, f32[3], f32);
    s32 sp1C[2];
    s32 temp_v0;

    temp_v0 = func_800B5BE4(0x13);
    sp1C[1] = temp_v0;
    func_808001CC_fxegg(temp_v0, (f32 *) arg0, *(f32 *) &arg1);
    return sp1C[1];
}

/* extern */

s32 fxegg_entrypoint_4(f32 arg0[3], f32 arg1) {
    s32 func_800B5BE4(s32);
    s32 sp1C;

    sp1C = func_800B5BE4(0x21);
    func_808000F8_fxegg(sp1C, arg0, 0x9E4, arg1);
    return sp1C;
}

s32 fxegg_entrypoint_5(f32 arg0[3], f32 arg1[3], f32 arg2) {
    s32 _fxdlsmoke_entrypoint_0(f32 *);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    void func_800BA930(s32, s16, s16, s16, s16, s16, s16);
    void func_800EFA20(void *, void *, f32);
    extern s32 D_80800614_fxegg;
    s32 sp34;
    f32 sp28[3];

    sp34 = _fxdlsmoke_entrypoint_0(arg0);
    if (arg1 != NULL) {
        func_800EFA20(sp28, arg1, 0.15f);
        func_800BA930(sp34, (s16)sp28[0], (s16)(sp28[1] + 60.0f), (s16)sp28[2],
                     (s16)sp28[0], (s16)(sp28[1] + 100.0f), (s16)sp28[2]);
    }
    func_800BABB8(sp34, arg0, arg0, arg2, &D_80800614_fxegg);
    return sp34;
}

s32 fxegg_entrypoint_6(f32 arg0[3], f32 arg1, f32 arg2[3]) {
    s32 func_800B5BE4(s32);
    void func_800BA930(s32, s16, s16, s16, s16, s16, s16);
    void func_800BA3FC(s32, s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    extern s32 D_80800630_fxegg;
    s32 sp2C;

    sp2C = func_800B5BE4(0x17);
    func_800BA930(sp2C, (s16)arg2[0], (s16)arg2[1], (s16)arg2[2], (s16)arg2[0], (s16)arg2[1], (s16)arg2[2]);
    func_800BA3FC(sp2C, 0x9E2);
    func_800BABB8(sp2C, arg0, 0, arg1, &D_80800630_fxegg);
    return sp2C;
}

void func_80800410_fxegg(s32 arg0, f32 arg1[3], f32 arg2[3], s32 arg3, f32 arg4) {
    void func_800BA930(s32, s16, s16, s16, s16, s16, s16);
    void func_800BA3FC(s32, s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    extern s32 D_80800658_fxegg;
    func_800BA930(arg0, (s16)arg2[0], (s16)arg2[1], (s16)arg2[2], (s16)arg2[0], (s16)arg2[1], (s16)arg2[2]);
    func_800BA3FC(arg0, arg3);
    func_800BABB8(arg0, arg1, 0, arg4, &D_80800658_fxegg);
}

/* extern */

void fxegg_entrypoint_7(f32 arg0[3], f32 arg1[3], f32 arg2) {
    s32 func_800B5BE4(s32);
    func_80800410_fxegg(func_800B5BE4(0xB), arg0, arg1, 0x9E0, arg2);
}

/* extern */

void fxegg_entrypoint_8(f32 arg0[3], f32 arg1[3], f32 arg2) {
    s32 func_800B5BE4(s32);
    func_80800410_fxegg(func_800B5BE4(0xC), arg0, arg1, 0x9E5, arg2);
}
