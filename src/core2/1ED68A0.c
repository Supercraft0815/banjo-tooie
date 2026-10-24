#include "core2/1ED68A0.h"

void func_800FCFB0(s32 arg0, s32 arg1, s32 *arg2, s32 arg3, f32 arg4) {
    typedef struct {
        s32 volume[2];
        s16 tempo[2];
    } MusicSettings;
    s32 func_80017764(s32);
    void func_800FC688(s32, s32);
    void func_800FC97C(s32, f32, f32);
    s32 func_800FCCD4(s32);
    s32 func_800FCDE0(s32, s32, f32);
    s32 func_800FCED0(s32, s32, f32);
    extern u8 D_801359D5;
    extern s32 D_80135A20[3];
    extern f32 D_80135A30[3];
    extern u8 D_80135A3C[3];
    extern s32 D_80135A40;

    if (arg1 == D_80135A20[arg0]) {
        if (arg3) {
            if (((MusicSettings *)arg2)->tempo[1] != -1) {
                func_800FCED0(arg1, 60000000 / ((MusicSettings *)arg2)->tempo[1], arg4);
            }
            func_800FCDE0(arg1, ((MusicSettings *)arg2)->volume[1], arg4);
        } else {
            if (((MusicSettings *)arg2)->tempo[0] != -1) {
                func_800FCED0(arg1, 60000000 / ((MusicSettings *)arg2)->tempo[0], arg4);
            }
            func_800FCDE0(arg1, ((MusicSettings *)arg2)->volume[0], arg4);
        }
        D_80135A3C[arg0] = 1;
        return;
    }
    if (D_80135A20[arg0] == 0) {
        D_80135A20[arg0] = arg1;
        if (!func_800FCCD4(arg1)) {
            func_800FC688(arg1, func_80017764(arg1));
            D_801359D5 = 1;
        }
        if (arg1 == 0x4B) {
            func_800FC97C(arg1, 0.125f, 1.0f);
        } else {
            func_800FC97C(arg1, 0.25f, 1.0f);
        }
        if (arg3) {
            if (((MusicSettings *)arg2)->tempo[1] != -1) {
                func_800FCED0(arg1, 60000000 / ((MusicSettings *)arg2)->tempo[1], arg4);
            }
            func_800FCDE0(arg1, ((MusicSettings *)arg2)->volume[1], arg4);
        } else {
            if (((MusicSettings *)arg2)->tempo[0] != -1) {
                func_800FCED0(arg1, 60000000 / ((MusicSettings *)arg2)->tempo[0], arg4);
            }
            func_800FCDE0(arg1, ((MusicSettings *)arg2)->volume[0], arg4);
        }
        D_80135A3C[arg0] = 1;
        D_80135A30[arg0] = arg4;
        if (D_80135A40 == -1) {
            D_80135A40 = 1;
            return;
        }
        D_80135A40++;
    }
}

void func_800FD2A0(f32 *arg0, s32 arg1) {
    extern s32 D_801359C0;
    extern u8 D_801359D1, D_80135A1E;
    extern s32 *D_80135A04;
    extern f32 D_80135A44;
    extern s32 D_80123E84, D_80123F68[], D_80123FC8[];
    extern s32 D_80124004[], D_80124010, D_8012401C[];
    extern s32 D_80124028[], D_80124034[], D_80124040[];
    extern s32 D_801241CC[], D_801241D8[];
    extern f32 D_801241E4[4], D_801241F4[3], D_80124200[3];
    extern f32 D_8012420C[3], D_80124218[3];
    extern f32 D_801261BC, D_801261C0, D_801261C4;
    s32 func_800CBBE0(s32);
    s32 _gcmapsects_entrypoint_7(f32 *);
    f32 func_800D8FF8(void);
    f32 func_800EEAD4(f32 *, f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    s32 func_800EFFB4(f32 *, f32, f32 *);
    void func_800FCFB0(s32, s32, s32 *, s32, f32);
    void func_800FEDC4(s32, s32, f32, f32);
    s32 section;
    f32 volume;

    switch (((s16 *)&D_801359C0)[0x10]) {
        case 1:
            switch (func_800CBBE0(((s32 *)&D_801359C0)[0xA])) {
                case 3:
                    if (arg0[0] < D_801241E4[2] ||
                        arg0[2] < D_801241E4[1] ||
                        D_801241E4[0] < arg0[0] ||
                        D_801241E4[3] < arg0[2]) {
                        section = 0;
                    } else {
                        s32 region;
                        region = D_801241E4[0] < arg0[0] + arg0[2] - D_801241E4[1] ? 1 : 2;
                        section = region;
                    }
                    if (section == 2) {
                        D_80135A04 = D_80123F68;
                    }
                    break;
                case 2:
                    if (arg0[1] > 2000.0f) {
                        func_800FCFB0(0, 0x4A, &D_80123E84, arg1, 1.75f);
                        D_80135A04 = D_80123FC8;
                    }
                    break;
            }
            break;
        case 7:
            func_800FEDC4(0, 1, 1.0f, 1.75f);
            break;
        case 12:
            func_800FEDC4(0, 2, 1.0f, 1.75f);
            func_800FEDC4(1, 3, 1.0f, 1.75f);
            break;
        case 13:
            func_800FEDC4(0, 2, 0.9f, 1.75f);
            func_800FEDC4(1, 3, 0.9f, 1.75f);
            break;
        case 14:
            volume = func_800F10B4(func_800EEAD4(arg0, D_801241F4), 2500.0f, 3500.0f, 0.8f, 0.0f);
            func_800FEDC4(0, 2, volume, 1.75f);
            func_800FEDC4(1, 3, volume, 1.75f);
            break;
        case 21:
            volume = func_800F10B4(func_800EEAD4(arg0, D_80124200), 2500.0f, 5000.0f, 1.0f, 0.0f);
            func_800FEDC4(0, 4, volume, 1.75f);
            break;
        case 23:
            func_800FEDC4(0, 2, 0.7f, 1.75f);
            func_800FEDC4(1, 3, 0.7f, 1.75f);
            break;
        case 20:
            volume = func_800F10B4(func_800EEAD4(arg0, D_8012420C), 2500.0f, 3500.0f, 0.5f, 0.0f);
            func_800FEDC4(0, 2, volume, 1.75f);
            break;
        case 17:
            section = _gcmapsects_entrypoint_7(arg0);
            if (section != -1) {
                D_801359D1 = section;
            }
            switch (((u8 *)&D_801359C0)[0x11]) {
                case 2:
                case 3:
                case 4:
                    func_800FCFB0(0, 0x4B, D_8012401C, arg1, 1.75f);
                    D_80135A04 = &D_80124010;
                    break;
            }
            break;
        case 18:
            section = _gcmapsects_entrypoint_7(arg0);
            if (section != -1) {
                D_801359D1 = section;
            }
            switch (((u8 *)&D_801359C0)[0x11]) {
                case 3:
                    if (arg1) {
                        func_800FCFB0(0, 0x4B, D_8012401C, arg1, 1.75f);
                    } else {
                        func_800FCFB0(0, 0x4B, D_80124004, arg1, 1.75f);
                    }
                    D_80135A04 = &D_80124010;
                    break;
                case 0:
                case 2:
                    func_800FCFB0(0, 0x4B, D_8012401C, arg1, 1.75f);
                    D_80135A04 = &D_80124010;
                    D_80135A1E = 0;
                    break;
                case 1:
                    if (D_80135A1E) {
                        func_800FCFB0(0, 0x4B, D_80124028, arg1, 1.75f);
                    } else {
                        func_800FCFB0(0, 0x4B, D_8012401C, arg1, 1.75f);
                    }
                    D_80135A04 = &D_80124010;
                    break;
            }
            break;
        case 19:
            section = _gcmapsects_entrypoint_7(arg0);
            if (section != -1) {
                D_801359D1 = section;
            }
            switch (((u8 *)&D_801359C0)[0x11]) {
                case 0:
                case 1:
                case 2:
                case 3:
                    if (arg1) {
                        func_800FCFB0(0, 0x4B, D_80124028, arg1, 1.75f);
                    } else {
                        func_800FCFB0(0, 0x4B, D_80124004, arg1, 1.75f);
                    }
                    D_80135A04 = &D_80124010;
                    D_80135A1E = 1;
                    break;
            }
            break;
        case 22:
            if (arg1) {
                func_800FCFB0(0, 0x4B, D_8012401C, arg1, 1.75f);
            } else {
                func_800FCFB0(0, 0x4B, D_80124004, arg1, 1.75f);
            }
            D_80135A04 = &D_80124010;
            break;
        case 5:
            if (!((u8 *)&D_801359C0)[0x40]) {
                func_800FCFB0(0, 0x4B, D_80124004, arg1, 1.75f);
            }
            D_80135A04 = &D_80124010;
            break;
        case 6:
            func_800FCFB0(0, 0x4B, D_80124040, arg1, 1.75f);
            D_80135A04 = &D_80124010;
            break;
        case 8:
            if (func_800DA298(0x9F0)) {
                func_800FCFB0(1, 0x50, &D_80123E84, arg1, 1.75f);
            } else {
                func_800FCFB0(0, 0x4F, &D_80123E84, arg1, 1.75f);
            }
            D_80135A04 = &D_80124010;
            break;
        case 9:
            func_800FCFB0(0, 0x4B, D_80124034, arg1, 1.75f);
            D_80135A04 = &D_80124010;
            break;
        case 10:
            func_800FCFB0(0, 0x4B, D_8012401C, arg1, 1.75f);
            D_80135A04 = &D_80124010;
            break;
        case 11:
            func_800FCFB0(0, 0x4B, D_80124028, arg1, 1.75f);
            D_80135A04 = &D_80124010;
            break;
        case 15:
            if (func_800DA298(0x360)) {
                f32 current;
                if (func_800EFFB4(arg0, 1750.0f, D_80124218)) {
                    current = D_80135A44;
                    if (current < 0.5f) {
                        D_80135A44 += func_800D8FF8();
                        current = D_80135A44;
                    }
                } else {
                    current = D_80135A44;
                    if (current > 0.0f) {
                        D_80135A44 -= func_800D8FF8();
                        current = D_80135A44;
                    }
                }
                if (current > 0.0f) {
                    if (current >= 0.5f) {
                        D_80135A04 = D_801241CC;
                    } else {
                        D_80135A04 = D_801241D8;
                    }
                }
            }
            break;
        case 16:
            if (D_80135A44 >= 1.0f) {
                func_800FCFB0(0, 0x8D, &D_80123E84, arg1, 1.75f);
            }
            D_80135A44 = 1.0f;
            break;
    }
}

void func_800FDBB8(s32 arg0) {
    void func_800FCFB0(s32, s32, s32 *, s32, f32);
    extern s32 D_80123E84;
    extern s32 D_80124010;
    extern s32 D_80124224[][2];
    extern u8 D_80135A00[];
    extern s32 *D_80135A04;
    s32 sp20;
    s32 temp_t9;
    s32 *temp_v0;

    temp_t9 = D_80124224[D_80135A00[0]][0];
    sp20 = temp_t9;
    if (temp_t9 != -1) {
        func_800FCFB0(temp_t9, D_80124224[D_80135A00[0]][1], &D_80123E84, arg0, 0.0f);
        D_80135A04 = &D_80124010;
    }
}

u32 func_800FDC28(u32 arg0) {
    extern s32 D_801359C0;
    extern u8 D_80135A10[];
    u32 result = (u32)&D_801359C0;
    if (arg0 != ((u8 *)result)[0x40]) {
        ((u8 *)result)[0x40] = arg0;
        if (!(arg0 & 0xFF)) {
            ((s8 *)result)[0x18] = 1;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED68A0/func_800FDC58.s")

void func_800FE3EC(void) {
    void func_800FCA90(u32);
    extern s16 D_801359C8;
    extern s32 D_80135A20[3];
    extern f32 D_80135A30[3];
    extern u8 D_80135A3C[3];
    extern s32 D_80135A40;
    u32 temp_a0;
    s32 var_s1;

    temp_a0 = D_801359C8;
    if (temp_a0 != -1U) {
        func_800FCA90(temp_a0);
    }
    if (D_80135A40 > 0) {
        for (var_s1 = 0; var_s1 < 3; var_s1++) {
            temp_a0 = D_80135A20[var_s1];
            if ((temp_a0 != 0) && (D_80135A3C[var_s1] != 0)) {
                func_800FCA90(temp_a0);
                D_80135A20[var_s1] = 0;
                D_80135A3C[var_s1] = 0;
                D_80135A30[var_s1] = 0.0f;
                D_80135A40 -= 1;
            }
        }
    }
}

s32 func_800FE4E4(void) {
    void func_800C77DC(s32);
    void func_800FC74C(u32);
    extern s16 D_801359C8;
    extern s8 D_801359D7;
    extern s8 D_80135A01;
    extern s32 D_80135A20[3];
    extern f32 D_80135A30[3];
    extern u8 D_80135A3C[3];
    extern s32 D_80135A40;
    u32 temp_a0;
    s32 var_s1;

    if ((u8) D_801359D7 != 0) {
        return 0;
    }
    func_800C77DC(1);
    func_800FDC28(0U);
    temp_a0 = D_801359C8;
    if (temp_a0 != -1U) {
        func_800FC74C(temp_a0);
    }
    if (D_80135A40 > 0) {
        for (var_s1 = 0; var_s1 < 3; var_s1++) {
            temp_a0 = D_80135A20[var_s1];
            if ((temp_a0 != 0) && (D_80135A3C[var_s1] != 0)) {
                func_800FC74C(temp_a0);
                D_80135A20[var_s1] = 0;
                D_80135A3C[var_s1] = 0;
                D_80135A30[var_s1] = 0.0f;
                D_80135A40 -= 1;
            }
        }
    }
    D_80135A01 = 1;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED68A0/func_800FE614.s")

void func_800FE6F8(s32 arg0) {
    extern u8 D_801359D6;
    if ((arg0 == 0) && (D_801359D6 != 0)) {
        func_800FE4E4();
    }
    D_801359D6 = (u8) arg0;
}

void func_800FE734(u32 arg0) {
    extern s8 D_801359D7;
    D_801359D7 = (s8) arg0;
}

void func_800FE740(void) {
    extern s32 D_801359C0;
    extern u8 D_80135A10[];
    s16 _cothemedll_entrypoint_1(s32);
    s32 _cothemedll_entrypoint_3(s32 *, s32);
    s32 func_800EA05C();
    extern s16 D_801359E2;
    extern s32 D_80135A08;
    extern f32 D_80135A0C;
    s32 sp1C[2];
    s32 temp_a1;

    temp_a1 = func_800EA05C();
    if (D_80135A10[6] != 0) {
        D_80135A10[6] = 0U;
    }
    D_80135A08 = 0;
    D_80135A0C = 0.0f;
    sp1C[1] = temp_a1; _cothemedll_entrypoint_3(&D_801359C0, temp_a1);
    D_801359E2 = _cothemedll_entrypoint_1(sp1C[1]);
}

s32 func_800FE7A8(s32 arg0) { extern s16 D_801359C8; extern s32 D_80135A20[]; extern u8 D_80135A3C[3]; extern s32 D_80135A40; s32 var_v0; u8 *var_v1; if (arg0 == D_801359C8) { return 1; } var_v0 = 0; var_v1 = D_80135A3C; if (D_80135A40 > 0) {
        for (; var_v0 < 3; var_v0++, var_v1++) {
            if ((*var_v1 != 0) && (arg0 == D_80135A20[var_v0])) {
                return 1;
            }
        }
    }
    return 0;
}

void func_800FE820(f32 arg0) {
    extern s32 D_801359C0;
    (*(u8 *)((s8 *)(&D_801359C0) + (0x10))) = 0xFF;
    (*(f32 *)((s8 *)(&D_801359C0) + (4))) = (f32) (1.0f / arg0);
}

void func_800FE844(u32 arg0) {
    extern s8 D_801359CE;
    D_801359CE = (s8) arg0;
}

void func_800FE850()
{
    func_800DA544(FLAG2_674_UNK);
}

void func_800FE870()
{
    func_800DA544(FLAG2_675_UNK);
}

u32 func_800FE890(void) {
    extern s8 D_801359CE;
    return *(u8 *)((u8 *)&D_801359CE + 0);
}

void func_800FE89C(void) {
    extern s8 D_801359CF;
    D_801359CF = 1;
}

void func_800FE8AC(void) {
    extern s8 D_801359D8;
    D_801359D8 = 1;
}

void func_800FE8BC(s32 arg0, s32 arg1) {
    s32 _cothemedll_entrypoint_5(s32 *, s32, s32);
    extern s32 D_801359C0;
    _cothemedll_entrypoint_5(&D_801359C0, arg0, arg1);
}

void func_800FE8EC(s32 arg0) {
    s32 _cothemedll_entrypoint_4(s32 *, s32);
    extern s32 D_801359C0;
    _cothemedll_entrypoint_4(&D_801359C0, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED68A0/func_800FE914.s")

void func_800FEC1C(f32 arg0) {
    extern f32 D_801359F0;
    *(f32 *)((u8 *)&D_801359F0 + 0) = arg0;
}

s32 func_800FEC28(s32 arg0) {
    extern u8 D_8012762C;
    if (arg0 == 0) {
        return D_8012762C == 0xD ? 7 : 0;
    }
    return arg0;
}
void func_800FEC60(u32 arg0) {
    extern f32 D_801359F0;
    extern s32 D_80123E60;
    extern u8 D_80135A10[];
    s32 temp_v0;
    u8 *temp_v1;
    temp_v0 = func_800FEC28((s32)arg0);
    temp_v1 = D_80135A10 + temp_v0;
    *temp_v1 = *temp_v1 + 1;
    if (temp_v0 == 3) {
        D_801359F0 = 1.0f;
    }
    D_80123E60 = 1;
}

void func_800FECB8(u32 arg0) {
    extern s32 D_80123E60;
    extern u8 D_80135A10[];
    s32 i;
    u8 *p;
    p = D_80135A10 + func_800FEC28((s32)arg0);
    *p = *p - 1;
    for (i = 0; i < 14; i++) {}
    D_80123E60 = 1;
}

void func_800FED0C(s32 arg0, s32 arg1) {
    extern s32 D_80123E60;
    extern u8 D_80135A10[];
    s32 index;
    u8 *p;
    switch (arg0) {
        case 2:
            index = 12;
            break;
        case 5:
        case 10:
        case 11:
        case 12:
        case 13:
        case 18:
        case 22:
        case 23:
        case 24:
        case 27:
        case 46:
        case 49:
        case 58:
        case 68:
        case 83:
        case 96:
        case 119:
        case 131:
            index = 13;
            break;
        case 43:
        case 104:
            index = 13;
            break;
        case 1:
        default:
            return;
    }
    p = D_80135A10 + index;
    *p = *p + arg1;
    D_80123E60 = 1;
}

void func_800FED70(s32 arg0)
{
    func_800FED0C(arg0,1);
}

s32 func_800FED90(s32 arg0) {
    s32 var_v0;

    func_800FED0C(arg0, -1);
    var_v0 = 2;
    while (var_v0 != 0xE) {
        var_v0 += 4;
    }
}

void func_800FEDC4(s32 arg0, s32 arg1, f32 arg2, f32 arg3) {
    u8 func_800C2E04(void);
    s32 func_800C2FDC(u8);
    void func_800C301C(u8, s32);
    void func_800C3058(u8, s32);
    void func_800C31DC(u8, f32);
    void func_800C330C(u8, s32);
    void func_800C33DC(u8, s32);
    void func_800C3648(u8, s32);
    void func_800C368C(u8, s32);
    void func_800C36F4(u8, s32);
    void func_800C3A40(u8, f32, f32, f32);
    void func_800C3BDC(u8);
    s32 func_800EA05C();
    extern s32 D_801359C0;
    extern s16 D_80123E5E;
    extern s32 D_80123E64;

    if (arg1 == *(s16 *)((u8 *)&D_801359C0 + arg0 * 2 + 0x36) && arg1 != 0) {
        func_800C3648(*((u8 *)&D_801359C0 + arg0 + 0x34), func_800EA05C());
        func_800C3058(*((u8 *)&D_801359C0 + arg0 + 0x34), (s32)(*(s16 *)((u8 *)&D_80123E5E + arg1 * 8) * arg2));
        return;
    }
    if (*((u8 *)&D_801359C0 + arg0 + 0x34) != 0) {
        if (arg3 != 0.0f) {
            func_800C3A40(*((u8 *)&D_801359C0 + arg0 + 0x34), 0.0f, 0.0f, arg3);
        } else {
            func_800C2FDC(*((u8 *)&D_801359C0 + arg0 + 0x34));
        }
        *((u8 *)&D_801359C0 + arg0 + 0x34) = 0;
    }
    if (arg1 != 0) {
        *((u8 *)&D_801359C0 + arg0 + 0x34) = func_800C2E04();
        func_800C330C(*((u8 *)&D_801359C0 + arg0 + 0x34), 3);
        func_800C301C(*((u8 *)&D_801359C0 + arg0 + 0x34), *(s16 *)((u8 *)&D_80123E64 + arg1 * 8 - 8));
        func_800C3058(*((u8 *)&D_801359C0 + arg0 + 0x34), (s32)(*(s16 *)((u8 *)&D_80123E64 + arg1 * 8 - 6) * arg2));
        func_800C31DC(*((u8 *)&D_801359C0 + arg0 + 0x34), *(f32 *)((u8 *)&D_80123E64 + arg1 * 8 - 4));
        func_800C36F4(*((u8 *)&D_801359C0 + arg0 + 0x34), 0xFF);
        func_800C368C(*((u8 *)&D_801359C0 + arg0 + 0x34), 0);
        func_800C33DC(*((u8 *)&D_801359C0 + arg0 + 0x34), 0);
        func_800C3BDC(*((u8 *)&D_801359C0 + arg0 + 0x34));
    }
    *(s16 *)((u8 *)&D_801359C0 + arg0 * 2 + 0x36) = arg1;
}

void func_800FEF94(s32 arg0, s32 arg1, s32 arg2, s32 *arg3, s16 *arg4) {
    extern s32 D_80123E84;
    u8 *temp_v0;
    u8 *temp_v0_2;

    if (arg2 != 0) {
        temp_v0 = (arg1 * 0xC) + (u8 *)&D_80123E84;
        *arg3 = (*(s32 *)((s8 *)(temp_v0) + (4)));
        *arg4 = (*(s16 *)((s8 *)(temp_v0) + (0xA)));
        return;
    }
    temp_v0_2 = (arg1 * 0xC) + (u8 *)&D_80123E84;
    *arg3 = (*(s32 *)((s8 *)(temp_v0_2) + (0)));
    *arg4 = (*(s16 *)((s8 *)(temp_v0_2) + (8)));
}

void func_800FF000(s32 arg0) {
    extern s32 D_801359C0;
    (*(s8 *)((s8 *)(&D_801359C0) + (0x13))) = (s8) arg0;
    (*(f32 *)((s8 *)(&D_801359C0) + (0))) = 0.2f;
}

void func_800FF01C(f32 arg0) {
    extern s32 D_801359C0;
    (*(s8 *)((s8 *)(&D_801359C0) + (0x13))) = 1;
    (*(s8 *)((s8 *)(&D_801359C0) + (0x14))) = 1;
    (*(f32 *)((s8 *)(&D_801359C0) + (0))) = arg0;
}

void func_800FF038(s32 arg0) {
    s32 _cothemedll_entrypoint_2(s32 *, s32);
    extern s32 D_801359C0;
    _cothemedll_entrypoint_2(&D_801359C0, arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED68A0/func_800FF060.s")
