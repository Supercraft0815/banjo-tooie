#include "core2/1EA9160.h"

extern s32 D_8011AE60;

void func_800CF870(s32 arg0) {
    *(s32 *)((u8 *)&D_8011AE60 + 0) = arg0;
}

s32 func_800CF87C()
{
    return D_8011AE60;
}

s32 func_800CF888(s32 arg0, s32 arg1) {
    extern s16 D_8011AE64[][2];
    extern s16 D_8011AE6C[][2];
    s32 i;

    i = 0;
    do {
        if (arg0 == D_8011AE64[i][0] && arg1 == D_8011AE64[i][1]) {
            return 1;
        }
        i++;
    } while (D_8011AE6C != &D_8011AE64[i]);
    return 0;
}

s32 func_800CF8D0(s32 arg0, s32 arg1) {
    extern s16 D_8011AE6C[][2];
    extern s16 D_8011AE74[][2];
    s32 i;

    i = 0;
    do {
        if (arg0 == D_8011AE6C[i][0] && arg1 == D_8011AE6C[i][1]) {
            return 1;
        }
        i++;
    } while (D_8011AE74 != &D_8011AE6C[i]);
    return 0;
}

s32 func_800CF918(s32 arg0, s32 arg1) {
    extern s16 D_8011AE74[][2];
    extern s16 D_8011AE76;
    extern s16 D_8011AE84[][8];
    s16 (*entry)[8];
    s32 i;

    i = 1;
    if (arg0 == D_8011AE74[0][0] && arg1 == D_8011AE76) {
        return 0;
    }
    i = 1;
    entry = D_8011AE84;
loop:
        if (arg0 == entry[0][0] && arg1 == entry[0][1]) {
            return i;
        }
        if (arg0 == entry[1][0] && arg1 == entry[1][1]) {
            return i + 1;
        }
        if (arg0 == entry[2][0] && arg1 == entry[2][1]) {
            return i + 2;
        }
        if (arg0 == entry[3][0] && arg1 == entry[3][1]) {
            return i + 3;
        }
        i += 4;
        entry += 4;
    if (i != 9) {
        goto loop;
    }
    return -1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800CF9E4.s")

void func_800CFA70(s32 arg0, s32 arg1)
{
    func_800CF918(arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800CFA90.s")

void func_800CFBC8(Actor *arg0, u32 arg1, s32 arg2, s32 arg3) {
    void _subaddieDll_entrypoint_4(Actor *, u32);
    s32 func_8010108C(Actor *, s32, s32);

    func_8010108C(arg0, 0x13, arg1);
    if (func_800CF888(arg1, arg2) != 0) {
        _subaddieDll_entrypoint_4(arg0, 1);
    }
    if (func_800CF8D0(arg1, arg2) != 0) {
        func_8010108C(arg0, 0x12, 1);
    }
    if (func_800CF918(arg1, arg2) != -1) {
        func_8010108C(arg0, 0x55, 1);
    }
}

s32 func_800CFC5C(s32 arg0) {
    if ((arg0 -= D_8011AE60) >= 0 && arg0 < 0xA) {
        return arg0;
    }
    return -1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800CFC8C.s")

s32 func_800CFFBC(u32 arg0, s32 arg1) {
    if (((s32) arg0 >= func_800D0820(arg1)) && (func_800D0894(arg1) >= (s32) arg0)) {
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D0018.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D035C.s")

/* extern */

s32 func_800D046C(u8 *arg0, s32 arg1, s32 arg2) {
    s32 func_800DAC78(u8 *, s32);
    return func_800DAC78(arg0, func_800D0A80(arg1, arg2));
}

s32 func_800D04A0(s32 arg0, s32 arg1) {
    s32 var_s0;
    s32 var_s2;

    var_s2 = 0;
    var_s0 = func_800D0820(arg1);
    if (func_800D0894(arg1) >= var_s0) {
        do {
            if (func_800D046C(arg0, var_s0, arg1) == 1) {
                var_s2 += 1;
            }
            var_s0 += 1;
        } while (func_800D0894(arg1) >= var_s0);
    }
    return var_s2;
}

void func_800D053C(u32 arg0, u32 arg1) { s32 func_800CFC5C(s32); s32 func_800EA05C(); extern s16 D_8012B190[]; s32 temp_v0; if (arg1 == 1) { temp_v0 = func_800CFC5C(arg0); if (temp_v0 != -1) { *(s16 *)((u8 *)D_8012B190 + temp_v0 * 0x14) = func_800EA05C(); } } }

void func_800D0594(s32 arg0, s32 arg1, s32 arg2) { s32 func_800CFC5C(s32); extern s16 D_8012B190[]; s32 temp_v0; if (arg1 == 1) { temp_v0 = func_800CFC5C(arg0); if (temp_v0 != -1) { *(s16 *)((u8 *)D_8012B190 + temp_v0 * 0x14) = *(s16 *)((u8 *)&arg2 + 2); } } }

void func_800D05E4(s32 arg0, s32 arg1, s32 arg2) { s32 func_800CFC5C(s32); extern s32 D_8012B18C[]; s32 temp_v0; if (arg1 == 1) { temp_v0 = func_800CFC5C(arg0); if (temp_v0 != -1) { *(s32 *)((u8 *)D_8012B18C + temp_v0 * 0x14) = arg2; } } }

 s32 func_800D0634(u32 arg0, u32 arg1) { extern s32 D_8012B18C[]; s32 temp_v0; if (arg1 == 1) { temp_v0 = func_800CFC5C(arg0); if (temp_v0 != -1) { return *(s32 *)((u8 *)D_8012B18C + temp_v0 * 0x14); } } return 0; }

s16 func_800D0684(s32 arg0, s32 arg1) { s32 func_800CFC5C(s32); extern s16 D_8012B190[]; s32 temp_v0; if (arg1 == 1) { temp_v0 = func_800CFC5C(arg0); if (temp_v0 != -1) { return *(s16 *)((u8 *)D_8012B190 + temp_v0 * 0x14); } } return 0; }

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D06D4.s")

void func_800D0778(s32 arg0, s32 arg1, f32 *arg2) { s32 func_800CFC5C(s32); extern f32 D_8012B180[][5]; s32 temp_v0; if (arg1 == 1) { temp_v0 = func_800CFC5C(arg0); if (temp_v0 != -1) { func_800EE7F8(D_8012B180[temp_v0], arg2); } } }

void func_800D07CC(s32 arg0, s32 arg1, f32 *arg2) { s32 func_800CFC5C(s32); extern f32 D_8012B180[][5]; s32 temp_v0; if (arg1 == 1) { temp_v0 = func_800CFC5C(arg0); if (temp_v0 != -1) { func_800EE7F8(arg2, D_8012B180[temp_v0]); } } }

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D0820.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D0894.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D0908.s")

s32 func_800D0A80(s32 arg0, s32 arg1) {
    extern s32 D_8011AF04[];
    return D_8011AF04[arg1] + arg0 - 1;
}

/* extern */

s32 func_800D0A9C(u32 arg0, u32 arg1) {
    s32 _glcutDll_entrypoint_20();
    s32 func_800D395C();
    s32 func_800DA298(s32);
    s32 temp_v0;

    temp_v0 = func_800D0908((s32) arg0, (s32) arg1);
    if (temp_v0 == 0) {
        return 1;
    }
    return ((func_800DA298(temp_v0) != 0) || (_glcutDll_entrypoint_20() != 0) || (func_800D395C() != 0)) ? 1 : 0;
}

/* extern */

void func_800D0B08(s32 arg0, s32 arg1) {
    s32 func_800DA544(s32);
    s32 temp_v0;

    temp_v0 = func_800D0908(arg0, arg1);
    if (temp_v0 != 0) {
        func_800DA544(temp_v0);
    }
}

/* extern */

void func_800D0B38(s32 arg0, s32 arg1) {
    s32 func_800DA524(s32);
    s32 temp_v0;

    temp_v0 = func_800D0908(arg0, arg1);
    if (temp_v0 != 0) {
        func_800DA524(temp_v0);
    }
}

/* extern */

s32 func_800D0B68(u32 arg0, u32 arg1) {
    s32 _glcutDll_entrypoint_20();
    s32 func_800D395C();
    s32 func_800DA298(s32);
    s32 temp_v0;

    temp_v0 = func_800D0A80((s32) arg0, (s32) arg1);
    if (temp_v0 == 0) {
        return -1;
    }
    return ((func_800DA298(temp_v0) != 0) || (_glcutDll_entrypoint_20() != 0) || (func_800D395C() != 0)) ? 1 : 0;
}

/* extern */

void func_800D0BD4(s32 arg0, u32 arg1) {
    s32 func_800D24E8(s32, s32, s32);
    s32 func_800DA544(s32);
    s32 func_80101238(s32, s32);
    s32 temp_v0;

    temp_v0 = func_800D0A80(arg0, (s32) arg1);
    if (temp_v0 != 0) {
        func_800DA544(temp_v0);
        if (arg1 != 0) {
            if (arg1 != 1) {
                if (arg1 == 6) {
                    func_800D24E8(0xD0, func_800D035C(6), 0);
                }
            } else {
                func_800D24E8(0xD6, func_800D035C(1), 0);
                goto block_6;
            }
        } else {
block_6:
            func_80101238(0xB7, (arg0 << 0x10) | (arg1 & 0xFFFF));
        }
    }
}

/* extern */

void func_800D0C78(u32 arg0, u32 arg1, u32 arg2) {
    s32 func_800FC660(s32);
    if (arg1 == 1) {
        func_800D0B08((s32) arg0, (s32) arg1);
        func_800D0BD4((s32) arg0, arg1);
        if (arg2 == 0) {
            func_800FC660(5);
        }
    }
}

u8 func_800D0CC8(s32 arg0) {
    extern u8 D_8011AB3E[];
    return D_8011AB3E[arg0 * 3];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D0CE0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D0DAC.s")

void func_800D0F9C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5)
{
    f32 temp;
    f32 sp18[3];
    sp18[0] = (f32)arg1;
    sp18[1] = (f32)arg2;
    sp18[2] = (f32)arg3;
    func_800D0DAC(arg0, sp18, arg4, arg5);
}

void func_800D1000(u32 arg0, u32 arg1, f32* arg2, u32 arg3, Unk80132ED0* arg4)
{
    s32 sp44[3];
    s32 temp;
    f32 sp34[3];
    if ((func_800D0A9C(arg0, arg1) == 0) && (func_800D0B68(arg0, arg1) == 0))
    {
        func_800D0B08(arg0, arg1);
        func_800D053C(arg0, arg1);
        if (arg2 != NULL)
        {
            func_800EE904(sp44, arg2);
        }
        else
        {
            func_800D07CC(arg0, arg1, sp34);
            func_800EE904(sp44, sp34);
        }
        _chbaddiesetup_entrypoint_6(&func_800D0F9C, (arg0 << 0x10) | (arg1 & 0xFFFF), sp44[0], sp44[1], sp44[2], arg3, arg4);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA9160/func_800D10D4.s")

/* extern */

void func_800D119C(u32 arg0, u32 arg1) {
    s32 func_800FFA88(s32);
    if ((func_800D0B68(arg0, arg1) == 0) && (func_800D0A9C(arg0, arg1) != 0)) {
        if (arg1 == 1) {
            func_800FFA88(func_800D0634(arg0, 1U));
            func_800D05E4((s32) arg0, 1, 0);
        }
        func_800D0B38(arg0, arg1);
    }
}

/* extern */

void func_800D1218(u32 arg0, u32 arg1, f32 *arg2) {
    s32 func_80106790(s32);
    s32 temp_v0;

    temp_v0 = func_800D0634(arg0, arg1);
    if (temp_v0 != 0) {
        func_800EE7F8(arg2, func_80106790(temp_v0) + 4);
    }
}

void func_800D1254(u32 arg0, u32 arg1, f32 *arg2) {
    s32 func_80103014(s32);
    s32 func_80106790(s32);
    s32 sp18[2];
    s32 temp_v0;
    s32 temp_v0_2;

    temp_v0 = func_800D0634(arg0, arg1);
    if (temp_v0 != 0) {
        temp_v0_2 = func_80106790(temp_v0);
        sp18[0] = temp_v0_2;
        func_800EE7F8(temp_v0_2 + 4, arg2);
        func_80103014(sp18[0]);
    }
}

s32 func_800D129C(u32 arg0) {
    extern u8 D_8011AB40[];
    s32 var_s1;
    s32 var_s2;
    u8 *var_s0;

    var_s2 = 0;
    var_s1 = func_800D0820(0);
    if (func_800D0894(0) >= var_s1) {
        var_s0 = (var_s1 * 3) + D_8011AB40;
        do {
            if (arg0 == var_s0[-2]) {
                var_s2 += 1;
            }
            var_s1 += 1;
            var_s0 += 3;
        } while (func_800D0894(0) >= var_s1);
    }
    return var_s2;
}

u32 func_800D1338(u32 JinjoColor) {
    extern u8 D_8011AB40[];
    s32 var_s0;
    u32 var_s2;
    u8 *var_s1;

    var_s2 = 0;
    var_s0 = func_800D0820(0);
    if (func_800D0894(0) >= var_s0) {
        var_s1 = (var_s0 * 3) + D_8011AB40;
        do {
            if ((JinjoColor == (*(u8 *)((s8 *)(var_s1) + (-2)))) && (func_800D0B68((u32) var_s0, 0U) != 0)) {
                var_s2 += 1;
            }
            var_s0 += 1;
            var_s1 += 3;
        } while (func_800D0894(0) >= var_s0);
    }
    return var_s2;
}

s32 func_800D13E8(s32 arg0, s32 arg1) {
    extern u8 D_8011AD08[];
    s32 var_s1;
    u8 *var_s0;

    if (arg0 == 6) {
        var_s1 = func_800D0820(arg0);
        if (func_800D0894(arg0) >= var_s1) {
            var_s0 = (var_s1 * 2) + D_8011AD08;
loop_3:
            if (arg1 == var_s0[-2]) {
                return var_s1 - 1;
            }
            var_s0 += 2;
            var_s1 += 1;
            if (func_800D0894(arg0) < var_s1) {
                goto block_6;
            }
            goto loop_3;
        }
    }
block_6:
    return 0;
}
