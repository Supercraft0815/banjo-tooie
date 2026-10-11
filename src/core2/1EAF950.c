#include "core2/1EAF950.h"

extern s32 D_8012BE70;

s32 func_800D6060(s32 arg0) {
    void aligned4_memmove(void *, void *, int);
    extern u8 D_8012B800[];
    extern s16 D_8012BE62;
    s32 mid;
    u32 size = 12;
    {
    u32 value;
    s32 high;
    s32 low;

    high = D_8012BE62 - 1;
    mid = 0;
    low = 0;
    while (high >= low) {
        mid = (high + low) >> 1;
        value = *(u32 *)(D_8012B800 + mid * size + 8);
        if ((s32)(value >> 18) < arg0) {
            low = mid + 1;
            if (low < D_8012BE62) {
                if (arg0 < (s32)(*(u32 *)(D_8012B800 + low * size + 8) >> 18)) {
                    mid = low;
                    break;
                }
            } else {
                mid = D_8012BE62;
                break;
            }
        } else {
            high = mid - 1;
            if (high >= 0) {
                if ((s32)(*(u32 *)(D_8012B800 + high * size + 8) >> 18) < arg0) {
                    break;
                }
            } else {
                mid = 0;
                break;
            }
        }
    }
    }
    if (mid < 0) {
        mid = 0;
    } else if (D_8012BE62 < mid) {
        mid = D_8012BE62;
    }
    if (mid < D_8012BE62) {
        s32 remaining = D_8012BE62 - mid;
        aligned4_memmove(D_8012B800 + mid * size + size, D_8012B800 + mid * size, remaining * size);
    }
    return mid;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D61B4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D6254.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D62E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D6378.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D6408.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D6550.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D66AC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D674C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D6B0C.s")

/* extern */

s32 func_800D6C34(void) {
    s32 func_800D6254();
    if (func_800D6254() != -1) {
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D6C64.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D6CEC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D6D68.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D6E54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D7050.s")

void func_800D70D0(s32 arg0) {
    s32 func_800D7050(s16, s32);
    extern s16 D_8011B910;
    func_800D7050(D_8011B910, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D70F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D7138.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D7184.s")

void func_800D71F4(s32 arg0) {
    s32 func_800D7184(s16, s32);
    extern s16 D_8011B910;
    func_800D7184(D_8011B910, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D721C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D725C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D731C.s")

void func_800D738C()
{
    func_800D58FC();
}

void func_800D73AC()
{
    func_800D59C0();
}

/* extern */

s32 func_800D73CC(void) {
    s32 func_800D6254();
    s32 var_v1;

    if (func_800D6254() == -1) {
        var_v1 = 0;
    } else {
        var_v1 = 1;
    }
    return var_v1;
}

void * func_800D7400(void) {
    return &D_8012BE70;
}

void func_800D740C(void)
{
    extern s32 D_8012BFFC;

    D_8012BFFC = 0;
}

void func_800D7418()
{
    _glsplineDll_entrypoint_0(&D_8012BE70);
}

void func_800D743C()
{
    _glsplineDll_entrypoint_1(&D_8012BE70);
}

void func_800D7460()
{
    func_800D743C();
    func_800D7418();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D7488.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D7520.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D7570.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D75DC.s")

f32 func_800D7708(s32 arg0, f32 arg1, s32 arg2) {
    void *func_800D7520(s32);
    f32 func_800C7AE4(void *, f32, f32);
    return func_800C7AE4(func_800D7520(arg0), arg1, 1.0f) / ((f32)arg2 / 4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D7754.s")

void func_800D7900(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D7908.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D7948.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D7DE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D7E38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D8070.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D8588.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D8648.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D8674.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAF950/func_800D86F0.s")

void func_800D8744(void) {
    f32 _glintrosyncDll_entrypoint_5();
    f32 func_800D8FF8();
    extern f32 D_8012C000;
    f32 var_f0;

    (*(f32 *)((s8 *)(&D_8012BE70) + (0x194))) = (f32) (*(f32 *)((s8 *)(&D_8012BE70) + (0x190)));
    if ((*(u8 *)((s8 *)(&D_8012BE70) + (0x1A8))) != 0) {
        var_f0 = _glintrosyncDll_entrypoint_5();
    } else {
        var_f0 = func_800D8FF8();
    }
    D_8012C000 = (*(f32 *)((s8 *)(&D_8012BE70) + (0x190))) + (var_f0 * 60.0f);
}

void func_800D87B0()
{
    _glsplineDll_entrypoint_2(&D_8012BE70);
}

void func_800D87D4(s32 *arg0, s32 arg1) {
    extern s32 D_8012BF70[];
    D_8012BF70[arg1] = *arg0;
}

s32 func_800D87EC(s32 arg0) {
    extern s32 D_8012BF70[];
    return ((s32 *)&D_8012BF70)[arg0];
}

void func_800D8800(void) {
}

void func_800D8808(s32 arg0) {
    extern s32 *D_8012C014;

    if (arg0 != 0) {
        ((s8 *)D_8012C014)[arg0 * 12 - 12] &= 0xFF7F;
    }
}
