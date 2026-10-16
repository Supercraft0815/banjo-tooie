#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quicksandbaddy/func_80800000_chquicksandbaddy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quicksandbaddy/func_80800140_chquicksandbaddy.s")

/* extern */

f32 func_80800CC0_chquicksandbaddy(u8 *arg0) {
    f32 func_800C6920(s32, f32, f32, s32);
    f32 result;

    result = func_800C6920((s32) (arg0 + 4), 500.0f, -500.0f, 0);
    result += *(f32 *) (arg0 + 0x54);
    return result;
}

/* extern */

s32 func_80800CFC_chquicksandbaddy(Actor *arg0, f32 arg1[3], f32 arg2[3]) {
    void *func_800C6A7C(f32[3], f32[3], f32[3], u32);
    f32 func_800EEB40(f32 *, f32 *);
    f32 mlAbsF(f32);
    f32 sp1C[3];

    if (!arg0->unk64_20) {
        return 0;
    }
    if (func_800EEB40(arg1, arg2) > 4000000.0f) {
        return 0;
    }
    if (mlAbsF(arg2[1] - arg1[1]) > 500.0f) {
        return 0;
    }
    if (func_800C6A7C(arg1, arg2, sp1C, 0) != 0) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quicksandbaddy/func_80800DBC_chquicksandbaddy.s")

void chquicksandbaddy_entrypoint_0(s32 arg0, s32 arg1) {
    s32 func_8001210C(s32);
    s32 func_800B53A4(s32);
    s32 func_800BA22C(s32, s32);
    s32 func_800BAB80(s32, s32 *);
    s32 func_800BABB8(s32, s32, s32, s32, s32 *);
    f32 func_800DC0C0();
    s32 func_808010A0_chquicksandbaddy(void *);
    extern s32 D_80801370_chquicksandbaddy;
    extern s32 D_80801390_chquicksandbaddy;
    s32 sp24;
    s32 temp_v0;

    if ((func_800DC0C0() < 0.75f) && (func_808010A0_chquicksandbaddy(&D_80801390_chquicksandbaddy) != 0) && (func_8001210C(3) != 0)) {
        temp_v0 = func_800B53A4(1);
        sp24 = temp_v0;
        func_800BABB8(temp_v0, arg1, 0, 0x40000000, &D_80801370_chquicksandbaddy);
        func_800BAB80(sp24, &D_80801390_chquicksandbaddy);
        func_800BA22C(sp24, 1);
    }
}

void func_80800FC8_chquicksandbaddy(s32 arg0, f32 arg1, s32 arg2) {
    s32 func_800B53A4(s32);
    s32 func_800BA22C(s32, s32);
    s32 func_800BA4D0(s32, s16);
    s32 func_800BA544(s32, s32 *);
    s32 func_800BA714(s32, s32, s32);
    s32 func_800BAB80(s32, s32 *);
    s32 func_800BABB8(s32, s32, s32, s32, s32 *);
    s32 func_808010A0_chquicksandbaddy(void *);
    extern s32 D_80801394_chquicksandbaddy;
    extern s32 D_808013D4_chquicksandbaddy;
    extern s32 _chquicksandbaddy_entrypoint_0;
    s32 temp_v0;

    if (func_808010A0_chquicksandbaddy(&D_808013D4_chquicksandbaddy) != 0) {
        temp_v0 = func_800B53A4(arg2);
        func_800BABB8(temp_v0, arg0, arg0, 0x3F800000, &D_80801394_chquicksandbaddy);
        if (arg2 >= 2) {
            func_800BA714(temp_v0, 0x32, 0x64);
        }
        func_800BAB80(temp_v0, &D_808013D4_chquicksandbaddy);
        func_800BA4D0(temp_v0, (s16) (s32) arg1);
        func_800BA544(temp_v0, &_chquicksandbaddy_entrypoint_0);
        func_800BA22C(temp_v0, arg2);
    }
}

s32 func_808010A0_chquicksandbaddy(void *arg0) {
    s32 func_800EA05C();
    u8 *color = arg0;

    switch (func_800EA05C()) {
        case 0xB9:
        case 0xC4:
            color[0] = 0xC8;
            color[1] = 0xA0;
            color[2] = 0x32;
            return 1;
        case 0x100:
        case 0x10F:
        case 0x15C:
            color[0] = 0xB4;
            color[1] = 0xB4;
            color[2] = 0xB4;
            return 1;
        case 0x106:
            color[0] = 0x32;
            color[1] = 0xA0;
            color[2] = 0x32;
            return 1;
        default:
            return 0;
    }
}

/* extern */

s32 func_80801154_chquicksandbaddy(Actor *arg0, f32 *arg1) {
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EEB40(f32 *, f32 *);
    int func_800EEF24(f32 *);
    void *func_80100094(Actor *, u32);
    f32 (*volatile points)[3];
    f32 (*temp)[3];
    f32 *position;
    f32 (*p)[3];
    s32 i;
    s32 best;
    f32 distance;
    f32 d;

    temp = func_80100094(arg0, 1);
    best = -1;
    if (temp != NULL) {
        distance = 0.0f;
        i = 0;
        p = temp;
        points = temp;
do {
            if (func_800EEF24(*p)) {
            position = arg0->position;
            if (best != -1) {
                d = func_800EEB40(position, *p);
                if (d < distance) {
                    distance = d;
                    best = i;
                }
            } else {
                distance = func_800EEB40(position, *p);
                best = i;
            }
            i++;
            p++;
            } else {
                break;
            }
        } while (i != 3);
        if (best != -1) {
            func_800EE7F8(arg1, points[best]);
        }
        return best;
    }
    return -1;
}

OSThread *chquicksandbaddy_entrypoint_1(void)
{
    extern u8 D_808013D8_chquicksandbaddy[];

    return (OSThread *) D_808013D8_chquicksandbaddy;
}
