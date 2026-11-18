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

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) fxegg_entrypoint_0(s32 arg0, f32 arg1[3], f32 arg2) {
    BtIntPtr func_8080009C_fxegg(s32, s32, f32[3], f32);
    s16 *temp_v0;
    BtIntPtr sp18;

    temp_v0 = func_80800000_fxegg(arg0);
    sp18 = func_8080009C_fxegg(temp_v0[1], temp_v0[2], arg1, arg2);
    func_800BA75C(sp18, arg1);
    BT_NATIVE_ONLY(return) func_800BA22C(sp18, 5);
}

BtIntPtr func_8080009C_fxegg(s32 arg0, s32 arg1, f32 arg2[3], f32 arg3) {
    BtIntPtr func_800B5BE4(s32);
    void func_800BA670(BtIntPtr arg0, s32 asset_id);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    extern s32 D_80800574_fxegg[15];
    BtIntPtr sp24;
    BtIntPtr temp_v0;

    temp_v0 = func_800B5BE4(arg1);
    sp24 = temp_v0;
    func_800BA670(temp_v0, arg0);
    return func_800BABB8(sp24, arg2, arg2, arg3, D_80800574_fxegg);
}

void func_808000F8_fxegg(BtIntPtr arg0, f32 arg1[3], s32 arg2, f32 arg3) {
    void func_800BA3FC(BtIntPtr, s32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    extern s32 D_808005B0_fxegg[10];
    func_800BA3FC(arg0, arg2);
    func_800BABB8(arg0, arg1, 0, arg3, D_808005B0_fxegg);
}

/* extern */

BtIntPtr fxegg_entrypoint_1(f32 arg0[3], f32 arg1) {
    BtIntPtr func_800B5BE4(s32);
    BtIntPtr sp1C;

    sp1C = func_800B5BE4(0xC);
    func_808000F8_fxegg(sp1C, arg0, 0x9E5, arg1);
    return sp1C;
}

/* extern */

BtIntPtr fxegg_entrypoint_2(f32 arg0[3], f32 arg1) {
    BtIntPtr func_800B5BE4(s32);
    BtIntPtr sp1C;

    sp1C = func_800B5BE4(0xB);
    func_808000F8_fxegg(sp1C, arg0, 0x9E0, arg1);
    return sp1C;
}

void func_808001CC_fxegg(BtIntPtr arg0, f32 arg1[3], f32 arg2) {
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    extern s32 D_808005D8_fxegg[15];
    func_800BABB8(arg0, arg1, 0, arg2, D_808005D8_fxegg);
}

/* extern */

s32 fxegg_entrypoint_3(BtIntPtr arg0, s32 arg1) {
    BtIntPtr func_800B5BE4(s32);
    void func_808001CC_fxegg(BtIntPtr, f32[3], f32);
    s32 sp1C[2];
    BtIntPtr temp_v0;

    temp_v0 = func_800B5BE4(0x13);
    sp1C[1] = temp_v0;
    func_808001CC_fxegg(temp_v0, (f32 *) arg0, *(f32 *) &arg1);
    return sp1C[1];
}

/* extern */

BtIntPtr fxegg_entrypoint_4(f32 arg0[3], f32 arg1) {
    BtIntPtr func_800B5BE4(s32);
    BtIntPtr sp1C;

    sp1C = func_800B5BE4(0x21);
    func_808000F8_fxegg(sp1C, arg0, 0x9E4, arg1);
    return sp1C;
}

BtIntPtr fxegg_entrypoint_5(f32 arg0[3], f32 arg1[3], f32 arg2) {
    BtIntPtr _fxdlsmoke_entrypoint_0(f32 *);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    void func_800BA930(BtIntPtr, s16, s16, s16, s16, s16, s16);
    void func_800EFA20(void *, void *, f32);
    extern s32 D_80800614_fxegg[7];
    BtIntPtr sp34;
    f32 sp28[3];

    sp34 = _fxdlsmoke_entrypoint_0(arg0);
    if (arg1 != NULL) {
        func_800EFA20(sp28, arg1, 0.15f);
        func_800BA930(sp34, (s16)sp28[0], (s16)(sp28[1] + 60.0f), (s16)sp28[2],
                     (s16)sp28[0], (s16)(sp28[1] + 100.0f), (s16)sp28[2]);
    }
    func_800BABB8(sp34, arg0, arg0, arg2, D_80800614_fxegg);
    return sp34;
}

BtIntPtr fxegg_entrypoint_6(f32 arg0[3], f32 arg1, f32 arg2[3]) {
    BtIntPtr func_800B5BE4(s32);
    void func_800BA930(BtIntPtr, s16, s16, s16, s16, s16, s16);
    void func_800BA3FC(BtIntPtr, s32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    extern s32 D_80800630_fxegg[10];
    BtIntPtr sp2C;

    sp2C = func_800B5BE4(0x17);
    func_800BA930(sp2C, (s16)arg2[0], (s16)arg2[1], (s16)arg2[2], (s16)arg2[0], (s16)arg2[1], (s16)arg2[2]);
    func_800BA3FC(sp2C, 0x9E2);
    func_800BABB8(sp2C, arg0, 0, arg1, D_80800630_fxegg);
    return sp2C;
}

void func_80800410_fxegg(BtIntPtr arg0, f32 arg1[3], f32 arg2[3], s32 arg3, f32 arg4) {
    void func_800BA930(BtIntPtr, s16, s16, s16, s16, s16, s16);
    void func_800BA3FC(BtIntPtr, s32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    extern s32 D_80800658_fxegg[10];
    func_800BA930(arg0, (s16)arg2[0], (s16)arg2[1], (s16)arg2[2], (s16)arg2[0], (s16)arg2[1], (s16)arg2[2]);
    func_800BA3FC(arg0, arg3);
    func_800BABB8(arg0, arg1, 0, arg4, D_80800658_fxegg);
}

/* extern */

void fxegg_entrypoint_7(f32 arg0[3], f32 arg1[3], f32 arg2) {
    BtIntPtr func_800B5BE4(s32);
    func_80800410_fxegg(func_800B5BE4(0xB), arg0, arg1, 0x9E0, arg2);
}

/* extern */

void fxegg_entrypoint_8(f32 arg0[3], f32 arg1[3], f32 arg2) {
    BtIntPtr func_800B5BE4(s32);
    func_80800410_fxegg(func_800B5BE4(0xC), arg0, arg1, 0x9E5, arg2);
}
/* data_to_c.py: from asm/data/overlays/fx/egg.data.s */
s16 D_80800550_fxegg [18] BT_DATA(4, overlays_fx_egg, 0x0) = { 1, 1553, 5, 2, 1819, 38, 3, 1822, 40, 5, 1818, 37, 7, 1820, 39, 0, 0, 0 };
s32 D_80800574_fxegg[15] BT_DATA(4, overlays_fx_egg, 0x24) = { 1442816, 2229043, 67108915, 3342375, 26214800, 52429600, 2752512, 131456, 25165868, -13107000, -13107000, 26214600, 786472, 1834208, -52428800 };
s32 D_808005B0_fxegg[10] BT_DATA(4, overlays_fx_egg, 0x60) = { 786464, 1376281, 3342370, 16777472, 6684774, 2556304, 26215200, 52428843, 2621480, 18481152 };
s32 D_808005D8_fxegg[15] BT_DATA(4, overlays_fx_egg, 0x88) = { 1903054, 1446400, 3276802, 1376256, 10027042, 26804736, 20119961, 2818214, 10879003, 19661100, 1572864, 6400, 419430423, 8388890, 0 };
s32 D_80800614_fxegg[7] BT_DATA(4, overlays_fx_egg, 0xC4) = { 1376256, 3342370, 26804736, 46924697, 2818201, 11731226, 0 };
s32 D_80800630_fxegg[10] BT_DATA(4, overlays_fx_egg, 0xE0) = { 786444, 1376281, 3342370, 16777472, 6684774, 2556304, 26215200, 52428843, 4980812, 18481152 };
s32 D_80800658_fxegg[10] BT_DATA(4, overlays_fx_egg, 0x108) = { 786433, 1376281, 3342370, 16777472, 6684774, 2556304, 26215200, 52428843, 2621480, 18481152 };
