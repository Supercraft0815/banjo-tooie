#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/onion/func_80800000_chfantasyonion.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/onion/func_808000BC_chfantasyonion.s")

/* extern */

void func_80800254_chfantasyonion(u8 *arg0) {
    s32 _plsu_entrypoint_3(s32);
    f32 func_80013970(f32);
    s32 func_80015178(u32);
    s32 func_80015184();
    s32 func_800C7A68(s32, f32, f32 *);
    s32 func_800D7520(s32);
    s32 func_800D90A4(u8 *);
    s32 func_800EE7F8(f32 *, f32 *);
    s32 func_800EF04C(f32 *, f32 *);
    s32 func_800EF3DC(f32 *, u8 *);
    s32 func_800EF934(f32 *, f32 *, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F1DF4(f32 *, f32 *);
    s32 func_800F54E4();
    s32 func_800F5A00(s32, f32 *);
    s32 func_800F5B38(s32, f32 *);
    s32 func_800F5C94(s32);
    s32 func_800F79DC(s32, s32, s32);
    s32 func_800F832C(s32, f32 *);
    s32 func_800F8418(s32, f32 *);
    s32 func_80102BAC(u8 *, s32, s32, s32);
    f32 func_80800000_chfantasyonion(u8 *);
    typedef struct {
        u8 pad[0x64];
        u32 : 11;
        u32 direction : 1;
        u32 locked : 1;
        u32 : 19;
        u8 pad68[8];
        u32 : 16;
        u32 state : 6;
        u32 : 10;
        u32 : 16;
        u32 duration : 9;
        u32 : 7;
        u32 : 8;
        u32 saved : 4;
        u32 : 20;
    } OnionBits;
    s32 sp6C;
    f32 sp60[3];
    f32 sp5C;
    f32 sp58;
    f32 sp4C[3];
    u32 sp48;
    f32 sp44;
    f32 sp38[3];
    f32 temp_f0;

    sp6C = _plsu_entrypoint_3((*(s32 *)((s8 *)(arg0) + (0))));
    if (sp6C != -1) {
        if ((-1.0f == (*(f32 *)((s8 *)(arg0) + (0x2C)))) && (0.0f == (*(f32 *)((s8 *)(arg0) + (0x30))))) {
            ((OnionBits *)arg0)->saved = func_80015184();
            func_80015178(4U);
            (*(f32 *)((s8 *)(arg0) + (0x30))) = 3.0f;
        }
        if (func_800F5C94(sp6C) != 0xC) {
            func_800F79DC(sp6C, 4, (*(s32 *)((s8 *)(arg0) + (0))));
            sp6C = -1;
        }
        if (sp6C != -1) {
            func_800F5A00(func_800F54E4(), sp60);
            func_800EF3DC(sp60, arg0 + 4);
            sp5C = (*(f32 *)((s8 *)(arg0) + (0x48)));
        }
    } else if (-1.0f != (*(f32 *)((s8 *)(arg0) + (0x2C)))) {
        func_80015178(((OnionBits *)arg0)->saved);
    }
    switch (((OnionBits *)arg0)->state) {
    case 1:
        break;
    case 2:
        sp48 = ((OnionBits *)arg0)->direction;
        func_800EE7F8(sp4C, (f32 *)(arg0 + 4));
        if (func_800D90A4(arg0 + 0x24) != 0) {
            if (!((OnionBits *)arg0)->locked) {
                ((OnionBits *)arg0)->direction = !((OnionBits *)arg0)->direction;
            }
            (*(f32 *)((s8 *)(arg0) + (0x24))) = (f32) ((s32)((OnionBits *)arg0)->duration / 10);
        }
        temp_f0 = (f32) ((s32)((OnionBits *)arg0)->duration / 10);
        if (((OnionBits *)arg0)->direction) {
            sp58 = func_800F10B4((*(f32 *)((s8 *)(arg0) + (0x24))), 0.0f, temp_f0, 0.0f, 1.0f);
        } else {
            sp58 = func_800F10B4((*(f32 *)((s8 *)(arg0) + (0x24))), 0.0f, temp_f0, 1.0f, 0.0f);
        }
        func_800C7A68(func_800D7520((s32) (*(f32 *)((s8 *)(arg0) + (0x34)))), sp58, (f32 *)(arg0 + 4));
        if (sp48 != 0) {
            (*(f32 *)(arg0 + 0x54)) = func_800F1DF4(sp4C, (f32 *)(arg0 + 4));
        } else {
            (*(f32 *)(arg0 + 0x54)) = func_800F1DF4((f32 *)(arg0 + 4), sp4C);
        }
        func_80102BAC(arg0, 0x3D4CCCCD, 0x3C23D70A, 0x40800000);
        break;
    }
    if (func_800D90A4(arg0 + 0x30) == 0) {
        sp44 = func_800F10B4((*(f32 *)((s8 *)(arg0) + (0x30))), 3.0f, 0.0f, 1.0f, 0.0f);
        temp_f0 = func_80013970(sp44 * 2160.0f);
        (*(f32 *)((s8 *)(arg0) + (8))) += temp_f0 * (20.0f * sp44);
    }
    if (sp6C != -1) {
        sp5C -= (*(f32 *)((s8 *)(arg0) + (0x48)));
        func_800F5B38(func_800F54E4(), sp38);
        sp38[1] -= sp5C;
        func_800F832C(func_800F54E4(), sp38);
        func_800EF934(sp60, sp60, -sp5C);
        func_800EF04C(sp60, (f32 *)(arg0 + 4));
        func_800F8418(func_800F54E4(), sp60);
    }
    (*(f32 *)((s8 *)(arg0) + (0x2C))) = (f32) sp6C;
    (*(f32 *)((s8 *)(arg0) + (0x28))) = func_80800000_chfantasyonion(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/onion/func_80800624_chfantasyonion.s")

/* extern */

void func_808006E0_chfantasyonion(void *arg0) {
    s32 func_800E87E0(s32, void *);
    s32 temp_v0;

    temp_v0 = (*(s32 *)((s8 *)(arg0) + (0x18)));
    if (temp_v0 != 0) {
        func_800E87E0(temp_v0 & 0xFF, arg0);
        (*(s32 *)((s8 *)(arg0) + (0x18))) = 0;
    }
}

OSThread *chfantasyonion_entrypoint_0(void)
{
    extern u8 D_80800754_chfantasyonion[];

    return (OSThread *) D_80800754_chfantasyonion;
}
