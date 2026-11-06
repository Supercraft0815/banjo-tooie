#include "common.h"

extern u32 D_80805498_chdragonbrothers[];
extern u32 D_808056F0_chdragonbrothers[];
void func_80101870(Actor *, void *);
void func_80105834(Actor *);
void *func_80107C2C(s32 *, s32, void *, s32, void *);
OSThread *func_80108ED0(void);
OSThread *func_80108EE8(void);
void func_80800070_chdragonbrothers();
void func_808003D8_chdragonbrothers(Actor* arg0);
s32 func_80801D40_chdragonbrothers(Actor *, s32, s32);
void func_80802574_chdragonbrothers(Actor *arg0);
void func_808034DC_chdragonbrothers(Actor *arg0, void *arg1);
void func_80803574_chdragonbrothers(Actor *arg0);
void func_808036E4_chdragonbrothers(s32 arg0);
void func_808038AC_chdragonbrothers(Actor *arg0);
s32 func_80803DC4_chdragonbrothers(Actor *arg0, s32 arg1, void *arg2);
void func_80803EFC_chdragonbrothers(void *arg0, s32 arg1);
void func_80803F4C_chdragonbrothers(Actor *arg0);
void func_808040A0_chdragonbrothers(s32 arg0);
void func_808040A8_chdragonbrothers(Actor *arg0);
void func_80804318_chdragonbrothers(s32 arg0, s32 arg1);
s32 func_80804350_chdragonbrothers(Actor *arg0, s32 arg1, Unk80132ED0 *arg2);
void func_8080449C_chdragonbrothers(Actor *arg0);
void func_808048A4_chdragonbrothers(s32 arg0);
void func_80804AA4_chdragonbrothers(Actor *arg0);
s32 func_80804C6C_chdragonbrothers(s32 arg0, s32 arg1, s32 arg2);
void func_80804C90_chdragonbrothers(s32 arg0, s32 arg1);
void func_80804CD0_chdragonbrothers(Actor *arg0);
void func_80804DB0_chdragonbrothers(s32 arg0);
void func_80804E1C_chdragonbrothers(Actor *arg0);

u32 D_808053A0_chdragonbrothers[] = {
    0x001304AD, 0x00164650, 0x000107D0, 0x13880000,
};

u32 D_808053B0_chdragonbrothers[] = {
    0x00130605, 0x000D00F3, 0x010C0016, 0x7FFF0001,
    0x1F402710, 0x00000000,
};

u32 D_808053C8_chdragonbrothers[] = {
    0x00130630, 0x000D00F3, 0x010C0016, 0x5DC00001,
    0x1F402710, 0x00000000,
};

u32 D_808053E0_chdragonbrothers[] = {
    0x00130600, 0x000D00F3, 0x010C0016, 0x5DC00001,
    0x13882710, 0x00000000, 0x0013049E, 0x000D00F3,
    0x010C0016, 0x46500001, 0x13881D4C, 0x00000000,
};

u32 D_80805410_chdragonbrothers[] = {
    0x00130416, 0x000A00C0, 0x00165DC0, 0x00011F40,
    0x27100000,
};

u32 D_80805424_chdragonbrothers[] = {
    0x001303FF, 0x000D00CC, 0x00E60019, 0x46505DC0,
    0x00011388, 0x27100000,
};

u32 D_8080543C_chdragonbrothers[] = {
    0x00130686, 0x00180002, 0x00000000,
};

u32 D_80805448_chdragonbrothers[] = {
    0x00130413, 0x000D00F3, 0x010C0016, 0x6D600001,
    0x27103A98, 0x00000000,
};

u32 D_80805460_chdragonbrothers[] = {
    0x00130601, 0x000D00F3, 0x010C0018, 0x00011388,
    0x27100000,
};

u32 D_80805474_chdragonbrothers[] = {
    0x00130603, 0x000D00F3, 0x010C0018, 0x00011388,
    0x27100000,
};

u32 D_80805488_chdragonbrothers[] = {
    0x001304CC, 0x00162EE0, 0x000109C4, 0x13880000,
};

u32 D_80805498_chdragonbrothers[] = {
    0x00000000, 0x00000000, 0x41400000, 0x04B60001,
    0x41400000, 0x04B60001, 0x3F800000, 0x03440044,
    0x41400000, 0x04B60001, 0x40A40000, 0x03440042,
    0x41400000, 0x04B60001, 0x3F956042, 0x035C0041,
    0x3FA53F7D, 0x03340042, 0x3F956042, 0x035C0041,
    0x3F956042, 0x035C0041, 0x3F553F7D, 0x03350042,
    0x3F553F7D, 0x03350002, 0x3F553F7D, 0x03360041,
    0x3F851EB8, 0x03420042, 0x41400000, 0x03460041,
    0x3FA872B0, 0x03430042, 0x3F28F5C3, 0x03370041,
    0x3F11EB85, 0x03470042, 0x404EB852, 0x03510042,
    0x4134CCCD, 0x03520042, 0x411AB852, 0x03530041,
    0x40400000, 0x035F0042, 0x3F07AE14, 0x03380241,
};

u32 D_80805558_chdragonbrothers[] = {
    0x00130604, 0x000D00F3, 0x010C0016, 0x7FFF0001,
    0x1F402710, 0x00000000,
};

f32 D_80805570_chdragonbrothers[] = {
    0.0f, 0.0f, 3100.0f,
};

u32 D_8080557C_chdragonbrothers[] = {
    0x00000000, 0x437A0000, 0x00000000,
};

u32 D_80805588_chdragonbrothers[] = {
    0x001D09CE, 0x00161200, 0x00320002, 0x00150000,
    0x00990022, 0x01990200, 0x01330199, 0x002B00A6,
    0x00A6001B, 0x012C0258, 0x00180000, 0x00001900,
    0x19000017, 0x00800000,
};

u32 D_808055C0_chdragonbrothers[] = {
    0x00130483, 0x02060007, 0x00164650, 0x000E0133,
    0x01700180, 0x00011388, 0x1D4C0000,
};

u32 D_808055DC_chdragonbrothers[] = {
    0x001D09DD, 0x00161200, 0x00150000, 0x004C0022,
    0x01990200, 0x01330199, 0x002B0040, 0x00A6001B,
    0x012C0258, 0x00170080, 0x00000000,
};

u32 D_80805608_chdragonbrothers[] = {
    0x00000000, 0x44BB8000, 0x430C0000,
};

u32 D_80805614_chdragonbrothers[] = {
    0x00000000, 0x00000000, 0x4541C000,
};

u32 D_80805620_chdragonbrothers[] = {
    0x43960000, 0x43AF0000, 0x437A0000, 0x42480000,
};

u32 D_80805630_chdragonbrothers[] = {
    0x43AF0000, 0x43480000, 0x43480000, 0x42480000,
};

u32 D_80805640_chdragonbrothers[] = {
    0x44480000, 0x437A0000, 0x437A0000, 0x44228000,
};

u32 D_80805650_chdragonbrothers[] = {
    0x00000000, 0x00000000, 0x45390000,
};

u32 D_8080565C_chdragonbrothers[] = {
    0x00000000, 0x00000000, 0x45390000,
};

u32 D_80805668_chdragonbrothers[] = {
    0x3D4CCCCD, 0x3E4CCCCD, 0x3E8A3D71, 0xBF800000,
};

u32 D_80805678_chdragonbrothers[] = {
    0x00130602, 0x02060007, 0x00164650, 0x000E00F3,
    0x010C0040, 0x00011388, 0x1D4C0000,
};

u32 D_80805694_chdragonbrothers[] = {
    0x3CF5C28F, 0x3E9EB852, 0x3F11EB85, 0x3F547AE1,
    0xBF800000,
};

u32 D_808056A8_chdragonbrothers[] = {
    0x002E0377, 0x07FC0003, (u32)D_80805498_chdragonbrothers, (u32)func_80802574_chdragonbrothers,
    (u32)func_80105834, (u32)func_808034DC_chdragonbrothers, 0x00000000, 0x00000000,
    0x00000000, 0x0008056C, (u32)func_808003D8_chdragonbrothers, (u32)func_80108EE8,
    0x00680000, (u32)func_80800070_chdragonbrothers, (u32)func_80107C2C, 0x80200002,
    (u32)func_80801D40_chdragonbrothers, 0x00000000,
};

u32 D_808056F0_chdragonbrothers[] = {
    0x00000000, 0x00000000, 0x3F700000, 0x03320044,
    0x3F700000, 0x03320044, 0x3F700000, 0x0332004A,
    0x3F000000, 0x03330044, 0x3E19999A, 0x03330002,
    0x3F700000, 0x03320092, 0x3F700000, 0x03320092,
    0x3F700000, 0x03320044, 0x3F700000, 0x03320044,
};

u32 D_80805740_chdragonbrothers[] = {
    0x00000000, 0x43840000, 0xC2EC0000,
};

u32 D_8080574C_chdragonbrothers[] = {
    0x002F0378, 0x08010001, (u32)D_808056F0_chdragonbrothers, (u32)func_808038AC_chdragonbrothers,
    (u32)func_80105834, (u32)func_80803EFC_chdragonbrothers, 0x00000000, 0x00000000,
    0x00000000, 0x00080C44, (u32)func_808036E4_chdragonbrothers, (u32)func_80108ED0,
    0x00000000, (u32)func_80803574_chdragonbrothers, (u32)func_80107C2C, 0x00000000,
    (u32)func_80803DC4_chdragonbrothers, 0x00000000,
};

u32 D_80805794_chdragonbrothers[] = {
    0x001305B8, 0x00180001, 0x04E209C4, 0x000D0133,
    0x014C0000,
};

u32 D_808057A8_chdragonbrothers[] = {
    0x001D09CE, 0x00161200, 0x00320002, 0x00150000,
    0x00990022, 0x01990200, 0x01330199, 0x002B00A6,
    0x00A6001B, 0x012C012C, 0x00180000, 0x00001900,
    0x19000017, 0x00800000,
};

u32 D_808057E0_chdragonbrothers[] = {
    0x001D09DD, 0x00161200, 0x00320002, 0x00150000,
    0x00990022, 0x01990200, 0x01330199, 0x002B00A6,
    0x00A6001B, 0x012C012C, 0x00170080, 0x00000000,
};

u32 D_80805810_chdragonbrothers[] = {
    0x001D09E0, 0x00161200, 0x000E0060, 0x00600015,
    0x00190099, 0x00220100, 0x01000066, 0x00660027,
    0xFE700190, 0xFCE00320, 0x002B004C, 0x00990000,
};

u32 D_80805840_chdragonbrothers[] = {
    0x001D09DD, 0x00161200, 0x000E0032, 0x00960015,
    0x004000A6, 0x00220199, 0x02000133, 0x0199002B,
    0x0040010C, 0x00170080, 0x002D0064, 0x012C0000,
};

u32 D_80805870_chdragonbrothers[] = {
    0x001D09DD, 0x00161200, 0x000E0032, 0x00960015,
    0x004000A6, 0x00220199, 0x02000133, 0x0199002B,
    0x0040010C, 0x00170080, 0x002D0064, 0x012C001F,
    0x40404000, 0x00000000,
};

u32 D_808058A8_chdragonbrothers[] = {
    0x00300379, 0x08150001, 0x00000000, (u32)func_808040A8_chdragonbrothers,
    (u32)func_80105834, (u32)func_80804318_chdragonbrothers, 0x00000000, 0x3F800000,
    0x00000000, 0x00001004, (u32)func_808040A0_chdragonbrothers, (u32)func_80108EE8,
    0x00000000, (u32)func_80803F4C_chdragonbrothers, (u32)func_80107C2C, 0x00000000,
    (u32)func_80804350_chdragonbrothers, 0x00000000,
};

u32 D_808058F0_chdragonbrothers[] = {
    0x000009D7, 0x09C109C0, 0x09C209C3, 0x09C40000,
};

u32 D_80805900_chdragonbrothers[] = {
    0x00130407, 0x000D0126, 0x01400016, 0x46500001,
    0x27103A98, 0x00000000,
};

u32 D_80805918_chdragonbrothers[] = {
    0x0710001D, 0x09D60015, 0x00020099, 0x00160200,
    0x001E0032, 0x0032000E, 0x006E0078, 0x00260000,
    0x0000FF9C, 0x00000000, 0x00640019, 0x00010001,
    0x00220099, 0x00CC0199, 0x0200002A, 0x000A000A,
    0x0080008C, 0x000F0000,
};

u32 D_80805960_chdragonbrothers[] = {
    0x0510001D, 0x09D60015, 0x00020099, 0x00160200,
    0x001E0032, 0x0032000E, 0x001E003C, 0x00260000,
    0x0000FF9C, 0x00000000, 0x00640019, 0x00000000,
    0x00220099, 0x00CC0200, 0x02CC002A, 0x00080008,
    0x00660066, 0x000F0000,
};

u32 D_808059A8_chdragonbrothers[] = {
    0x0110001D, 0x09D60015, 0x000200CC, 0x00160200,
    0x001E0032, 0x00320019, 0x00000000, 0x002200CC,
    0x00CC0380, 0x0380002B, 0x00590059, 0x011A0000,
};

u32 D_808059D8_chdragonbrothers[] = {
    0x00130413, 0x00166590, 0x000D00F3, 0x010C0002,
    0x00000000,
};

u32 D_808059EC_chdragonbrothers[] = {
    0x00130483, 0x02060007, 0x00164650, 0x000E0133,
    0x01700180, 0x00011388, 0x1D4C0000,
};

u32 D_80805A08_chdragonbrothers[] = {
    0x0031037A, 0x09D70001, 0x00000000, (u32)func_80804AA4_chdragonbrothers,
    (u32)func_80105834, (u32)func_80804C90_chdragonbrothers, 0x00000000, 0x3F800000,
    0x00000000, 0x00000404, (u32)func_808048A4_chdragonbrothers, 0x00000000,
    0x00140000, (u32)func_8080449C_chdragonbrothers, (u32)func_80107C2C, 0x80000002,
    (u32)func_80804C6C_chdragonbrothers, 0x00000000,
};

u32 D_80805A50_chdragonbrothers[] = {
    0x43CF0000, 0xC3E60000, 0x45548000,
};

u32 D_80805A5C_chdragonbrothers[] = {
    0x0033037B, 0x08D80003, 0x00000000, (u32)func_80804E1C_chdragonbrothers,
    (u32)func_80105834, (u32)func_80101870, 0x00000000, 0x00000000,
    0x00000000, 0x000A0C04, (u32)func_80804DB0_chdragonbrothers, 0x00000000,
    0x00000000, (u32)func_80804CD0_chdragonbrothers, (u32)func_80107C2C, 0x80000802,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000,
};

void func_8010A590(Actor *);
void func_80102424(Actor *, s32);
void func_8010A570(Actor *);

/* extern */

void func_80800000_chdragonbrothers(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    u8 *data;
    s32 i;

    data = func_80100094(arg0, 0);
    for (i = 0; i < 4; i++) {
        if (data[i] != 2) {
            data[i] = arg1;
        }
    }
}

s32 _glcutDll_entrypoint_20(void);
s32 func_800EA05C(void);
s32 func_801032B0(Actor *, u16, u16);
s32 func_800DA298(s32);
void func_800D1000(u32, u32, f32 *, u32, Unk80132ED0 *);
s32 _chintrotext_entrypoint_2(s32);
void func_800FFAB0(Actor *);
s32 func_800D395C(void);
s32 _suexpression_entrypoint_7(Actor *, s32, s32);
void func_80800070_chdragonbrothers(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    void func_808012B4_chdragonbrothers(u8 *, s32);
    struct {
        u8 unk0[4];
        u8 unk4[4];
        u8 unk8[4];
        s32 unkC;
        s32 unk10;
        u8 pad14[12];
        s32 unk20;
        u8 pad24[49];
        u8 unk55;
        u8 pad56[2];
        u8 unk58;
        u8 unk59;
        u8 pad5A[2];
        u8 unk5C;
        u8 unk5D;
        u8 unk5E;
        u8 unk5F;
        u8 unk60;
    } *data;
    s32 cutscene;

    data = func_80100094(arg0, 0);
    cutscene = _glcutDll_entrypoint_20();
    data->unk20 = -1;
    arg0->unk74_7 = arg0->unk74_7 - 50;
    if (func_800EA05C() == 0x12B) {
        arg0->unk7A_8 = 0;
    } else {
        arg0->unk7A_8 = 1;
    }
    if (arg0->unk7A_8) {
        func_801032B0(arg0, 0x7FD, arg0->unk0->unk16);
    }
    data->unk8[1] = data->unk4[1] = data->unk0[1] = 0;
    data->unk8[2] = data->unk4[2] = data->unk0[2] = 0;
    data->unk8[3] = data->unk4[3] = data->unk0[3] = 0;
    data->unk8[0] = data->unk4[0] = data->unk0[0] = 0;
    data->unk5C = 8;
    data->unk10 = 4;
    if (!cutscene) {
        if (func_800DA298(0x1D5) && func_800DA298(0x1D6) &&
            ((arg0->unk7A_8 && func_800DA298(0x1D2)) ||
             (!arg0->unk7A_8 && !func_800DA298(0x1D2)))) {
            func_800D1000(0x3D, 1, D_80805570_chdragonbrothers, 0, arg0->unk0);
        }
        if ((arg0->unk7A_8 && func_800DA298(0x1D5)) ||
            (!arg0->unk7A_8 && func_800DA298(0x1D6))) {
            _chintrotext_entrypoint_2(1);
            func_800FFAB0(arg0);
            return;
        }
        if (func_800D395C()) {
            if (arg0->unk7A_8) {
                arg0->unk64_19 = 1;
            }
        } else if ((arg0->unk7A_8 && func_800DA298(0x1D6)) ||
                   (!arg0->unk7A_8 && func_800DA298(0x1D5))) {
            arg0->unk64_19 = 1;
        }
    }
    if (arg0->unk64_19) {
        data->unkC = 12;
    } else {
        data->unkC = 6;
    }
    data->unk58 = 0;
    data->unk59 = 0;
    data->unk5D = 0;
    data->unk5E = 0;
    data->unk60 = 0;
    data->unk5F = 0;
    data->unk55 = 0;
    _suexpression_entrypoint_7(arg0, 1, (s16)(arg0->unk7A_8 ? 0x75 : 0x76));
    if (cutscene) {
        func_808012B4_chdragonbrothers((u8 *)arg0, 1);
    } else {
        arg0->unk64_16 = 0;
        if ((arg0->unk7A_8 && func_800DA298(0x1D3)) ||
            (!arg0->unk7A_8 && func_800DA298(0x1D4))) {
            func_808012B4_chdragonbrothers((u8 *)arg0, 4);
        }
    }
}

void func_808003D8_chdragonbrothers(Actor* arg0) 
{
    _suexpression_entrypoint_8(arg0, 1);
}
s32 func_808003F8_chdragonbrothers(Actor *arg0) {
    switch (arg0->unk70_10) {
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
        return 1;
    default:
        return 0;
    }
}

/* extern */

s32 func_80800438_chdragonbrothers(Actor *arg0) {
    s32 _ncpod_entrypoint_17(s32, s32);
    s32 func_800F5EF8(s32);
    void *func_80100094(Actor *, u32);
    s32 *temp_v1;

    temp_v1 = func_80100094(arg0, 0);
    if (!arg0->unk74_29) {
        return 0;
    }
    _ncpod_entrypoint_17(func_800F5EF8(temp_v1[8]), 0);
    arg0->unk74_29 = 0;
    return 1;
}

/* extern */

void func_808004A4_chdragonbrothers(Actor *arg0, s32 arg1) {
    void func_800A516C(f32 *, f32 *, f32 *);
    void func_800A51C0();
    void func_800A5240();
    void func_800A526C();
    void func_800EE7F8(f32 *, f32 *);
    void func_800EEC30(f32 *, f32, f32, f32);
    void func_800EF334(f32 *, f32);
    s32 func_800F1EA4(f32[3], f32 *);
    void func_800F5A00(s32, f32 *);
    void func_800F5A2C(s32, s32, f32 *);
    void *func_80100094(Actor *, u32);
    s32 *temp_v0;
    f32 sp38[3];
    f32 sp2C[3];
    f32 sp20[3];

    temp_v0 = func_80100094(arg0, 0);
    if (arg1 != 0) {
        func_800F5A2C(temp_v0[8], 5, sp20);
        func_800EE7F8(sp38, sp20);
        func_800EF334(sp38, 1.25f);
        sp38[1] += 375.0f;
        func_800A516C(sp2C, sp20, sp38);
    } else {
        func_800F5A00(temp_v0[8], sp38);
        func_800F1EA4(sp38, &sp2C[1]);
        sp2C[2] = 0.0f;
        sp2C[0] = 0.0f;
        func_800EEC30(sp38, 0.0f, sp2C[1], 4500.0f);
        sp2C[1] = -sp2C[1];
    }
    func_800A5240(sp38);
    func_800A526C(sp2C);
    func_800A51C0();
    func_800A5240(sp38);
    func_800A526C(sp2C);
}

void func_808005A4_chdragonbrothers(void *arg0, s32 arg1) {
    f32 *position = arg0;

    switch (arg1) {
        case 0:
            position[0] = 5500.0f;
            position[1] = -10.0f;
            position[2] = 1200.0f;
            return;
        case 1:
            position[0] = 4750.0f;
            position[1] = -5.0f;
            position[2] = 650.0f;
            return;
        case 2:
            position[0] = 4000.0f;
            position[1] = 0.0f;
            position[2] = 300.0f;
            return;
    }
}

/* extern */

f32 func_8080063C_chdragonbrothers(Actor *arg0) {
    void func_8008FFBC(s32);
    f32 func_800EF030(void *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F1DCC(f32, f32);
    void *func_80100094(Actor *, u32);
    f32 sp3C;
    f32 sp38;
    f32 sp28[4];

    sp3C = ((f32 *)func_80100094(arg0, 0))[6];
    sp38 = func_800F1DCC(sp3C, ((f32 *)arg0->actorData)[0]) * 20.0f;
    func_8008FFBC((s32)sp28);
    sp28[1] = func_800EF030(sp28);
    sp38 *= func_800F10B4(sp28[1], 0.0f, 5000.0f, 0.0f, 1.0f);
    return sp3C + sp38;
}

s32 func_808006C8_chdragonbrothers(Actor *arg0) {
    s32 _ncpod_entrypoint_8(s32, s32, s32);
    s32 func_80016B30(s32, s32);
    s32 func_80016B54(s32, s32);
    void func_800C3FC0(s32, f32, s32);
    f32 func_800D8FF8(void);
    void func_800EFCD8(f32 *, f32, f32);
    f32 func_800F1DCC(f32, f32);
    void func_800F5A00(s32, f32 *);
    s32 func_800F5EF8(s32);
    void *func_80100094(Actor *, u32);
    void *func_80110024(s16 *);
    f32 dt;
    f32 sp60[3];
    f32 sp5C;
    f32 sp50[3];
    f32 sp44[3];
    u8 *data;
    s32 i;

    data = func_80100094(arg0, 0);
    dt = func_800D8FF8();
    if (arg0->unk74_29) {
        func_800F5A00(((s32 *)data)[8], sp60);
        sp5C = func_8080063C_chdragonbrothers(arg0);
        ((f32 *)data)[17] += (func_800F1DCC(sp5C, ((f32 *)data)[15]) - ((f32 *)data)[17]) * 0.085f;
        ((f32 *)data)[16] += ((f32 *)data)[17];
        if (func_80016B54(0, 0) == 0 && func_80016B30(0, 3) == 1) {
            switch (data[0x55]) {
                case 2:
                    data[0x55] = 1;
                    func_800C3FC0(0x488, 1.0f, 12000);
                    break;
                case 1:
                    data[0x55] = 0;
                    func_800C3FC0(0x488, 1.0f, 12000);
                    break;
                case 0:
                    data[0x55] = 2;
                    func_800C3FC0(0x487, 1.0f, 12000);
                    break;
            }
            func_808005A4_chdragonbrothers(data + 0x30, data[0x55]);
        }
        for (i = 0; i < 3; i++) {
            ((f32 *)data)[i + 9] += (((f32 *)data)[i + 12] - ((f32 *)data)[i + 9]) * dt * 5.0f;
        }
        func_800EFCD8(sp50, ((f32 *)data)[16], ((f32 *)data)[9]);
        sp50[1] = ((f32 *)data)[11];
        sp44[0] = ((f32 *)data)[10];
        sp44[1] = ((f32 *)data)[16];
        sp44[2] = 0.0f;
        _ncpod_entrypoint_8((s32)func_80110024((s16 *)func_800F5EF8(((s32 *)data)[8])), (s32)sp50, (s32)sp44);
        ((f32 *)data)[15] = sp5C;
    }
}

void func_808008C8_chdragonbrothers(Actor *arg0) {
    s32 _ncpod_entrypoint_16(s32, s32, s32, s32);
    void func_800A5144();
    f32 func_800F1DF4(f32 *, f32 *);
    void func_800F5A00(s32, f32 *);
    s32 func_800F5EF8(s32);
    void *func_80100094(Actor *, u32);
    void func_808005A4_chdragonbrothers(void *, s32);
    s32 func_808006C8_chdragonbrothers(Actor *);
    u8 *temp_s0;
    f32 sp28[3];

    temp_s0 = func_80100094(arg0, 0);
    if (!arg0->unk74_29) {
        func_800F5A00(((s32 *)temp_s0)[8], sp28);
        ((f32 *)temp_s0)[15] = ((f32 *)temp_s0)[16] = func_800F1DF4(((f32 *)D_8080557C_chdragonbrothers), sp28);
        ((f32 *)temp_s0)[17] = 0.0f;
        ((f32 *)temp_s0)[18] = 0.0f;
        func_808005A4_chdragonbrothers(temp_s0 + 0x24, temp_s0[0x55]);
        func_808005A4_chdragonbrothers(temp_s0 + 0x30, temp_s0[0x55]);
        _ncpod_entrypoint_16(func_800F5EF8(((s32 *)temp_s0)[8]), (s32)arg0->unk0, 3, 0x804);
        arg0->unk74_29 = 1;
        func_808006C8_chdragonbrothers(arg0);
        func_800A5144();
    }
}

void func_8080098C_chdragonbrothers(Actor *arg0, s32 arg1, s32 arg2) {
    void _gcdialogcamera_entrypoint_6(Unk80132ED0 *);
    void _gcdialogcamera_entrypoint_8(void);
    s32 _ncpod_entrypoint_12(s32, s32);
    s32 _ncpod_entrypoint_16(s32, s32, s32, s32);
    s32 _ncpod_entrypoint_21(s32, s32, s32);
    s32 _ncpod_entrypoint_25(s32, s32);
    s32 func_800F5EF8(s32);
    void *func_80100094(Actor *, u32);
    void *func_80110024(s16 *);
    u8 *data;

    data = func_80100094(arg0, 0);
    switch (data[0x5F]) {
        case 0:
            func_80800438_chdragonbrothers(arg0);
            _ncpod_entrypoint_16(func_800F5EF8(((s32 *)data)[8]), (s32)arg0->unk0, 3, 0);
        case 1:
            _ncpod_entrypoint_12(func_80110024(func_800F5EF8(((s32 *)data)[8])), 1);
            data[0x5F] = 2;
            _gcdialogcamera_entrypoint_6(arg0->unk0);
            _gcdialogcamera_entrypoint_8();
            _ncpod_entrypoint_25(func_80110024(func_800F5EF8(((s32 *)data)[8])), 0);
        case 2:
            _ncpod_entrypoint_21(func_800F5EF8(((s32 *)data)[8]), arg1, arg2);
            break;
    }
}

void func_80800A80_chdragonbrothers(Actor *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 _ncpod_entrypoint_16(s32, s32, s32, s32);
    s32 _ncpod_entrypoint_20(s32, s32, s32, s32);
    s32 func_800F5EF8(s32);
    void *func_80100094(Actor *, u32);
    u8 *sp1C;

    sp1C = func_80100094(arg0, 0);
    switch (sp1C[0x5F]) {
        case 0:
            func_80800438_chdragonbrothers(arg0);
            _ncpod_entrypoint_16(func_800F5EF8(((s32 *)sp1C)[8]), (s32)arg0->unk0, 3, 0);
        case 2:
            sp1C[0x5F] = 1;
        case 1:
            _ncpod_entrypoint_20(func_800F5EF8(((s32 *)sp1C)[8]), arg3, arg1, arg2);
            break;
    }
}

/* extern */

void func_80800B34_chdragonbrothers(Actor *arg0, s32 arg1) {
    s32 _ncpod_entrypoint_17(s32, s32);
    s32 func_800F5EF8(s32);
    void *func_80100094(Actor *, u32);
    void func_808008C8_chdragonbrothers(Actor *);
    u8 *sp1C;
    s32 pad;

    sp1C = func_80100094(arg0, 0);
    if (sp1C[0x5F] != 0) {
        _ncpod_entrypoint_17(func_800F5EF8(((s32 *)sp1C)[8]), 0);
        sp1C[0x5F] = 0;
        if (arg1 != 0) {
            func_808008C8_chdragonbrothers(arg0);
        }
    }
}

/* extern */

void func_80800B9C_chdragonbrothers(u8 *arg0, s32 arg1, f32 *arg2) {
    void func_80090708(s32);
    void func_80090734(s32, f32 *);
    if (arg1 != 0) {
        if (arg0[0x64] == 0) {
            func_80090734(1, arg2);
        }
    } else if (arg0[0x64] != 0) {
        func_80090708(0);
    }
    arg0[0x64] = arg1;
}

void func_80800C08_chdragonbrothers(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    s32 _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
    s32 func_8001210C(s32);
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    f32 func_80101F24(Actor *);
    f32 temp_f0;
    f32 sp28[3];

    temp_f0 = func_80101F24(arg0);
    if (!(temp_f0 < 0.1f) && !(temp_f0 > 0.9f) && arg0->unk7C_12 && (func_8001210C(7) != 0)) {
        _subaddieskeleton_entrypoint_2(arg0->unk0, 4, sp28);
        if (!arg0->unk7A_8) {
            sp28[1] += 100.0f;
            func_800BBCB8(sp28, NULL, arg0->scale, 1, &(*(s32 *)D_80805588_chdragonbrothers));
            _subaddieaudioloop_entrypoint_4(arg0, sp28, 1, &(*(u32 *)D_808055C0_chdragonbrothers));
            return;
        }
        sp28[1] += 200.0f;
        func_800BBCB8(sp28, NULL, arg0->scale, 1, &(*(s32 *)D_808055DC_chdragonbrothers));
    }
}

void func_80800D20_chdragonbrothers(u8 *arg0, s16 arg1, s32 arg2) {
    s32 func_800C05B8(s32, s32, f32*, Unk80132ED0*, s32, s32, s16);
    s32 var_v0;
    Actor *actor = (Actor *)arg0;

    arg2 |= 6;
    if (actor->unk7A_8) {
        var_v0 = 0x75;
    } else {
        var_v0 = 0x76;
    }
    func_800C05B8(arg1, arg2, actor->position, actor->unk0, 0, 0, var_v0);
    actor->unk74_30 = 1;
}

void func_80800D98_chdragonbrothers(u8 *arg0, s32 arg1) {
    s32 _gcfrontend_entrypoint_9(s32);
    s32 _plsu_entrypoint_1(s32);
    s32 func_800DA298(s32);
    s32 func_800DA524(s32);
    s32 func_800DA544(s32);
    s32 func_800DA9E4(s32, s32);
    void *func_80100094(Actor *, u32);
    void func_8080098C_chdragonbrothers(Actor *, s32, s32);
    void func_80800A80_chdragonbrothers(Actor *, s32, s32, s32);
    void func_80800B9C_chdragonbrothers(u8 *, s32, f32 *);
    void func_80800D20_chdragonbrothers(u8 *, s16, s32);
    u8 *data;
    s16 introText;
    s16 text;

    data = func_80100094(arg0, 0);
    if (*(s32 *)(data + 0x10) == 4) {
        *(s32 *)(data + 0x20) = _plsu_entrypoint_1(1);
    }
    *(s32 *)(data + 0x10) = arg1;
    switch (arg1) {
    case 1:
        _gcfrontend_entrypoint_9((arg0[0x7A] & 1) ? 0x29 : 0x2A);
        if (arg0[0x7A] & 1) {
            if (func_800DA9E4(0x1D3, 1) == 0) {
                if (func_800DA298(0x1D6)) {
                    introText = 0x129C;
                } else if (func_800DA298(0x1D4)) {
                    introText = 0x129A;
                } else {
                    introText = 0x1296;
                }
            } else {
                introText = 0x1298;
            }
        } else {
            if (func_800DA9E4(0x1D4, 1) == 0) {
                if (func_800DA298(0x1D5)) {
                    introText = 0x129D;
                } else if (func_800DA298(0x1D3)) {
                    introText = 0x129B;
                } else {
                    introText = 0x1297;
                }
            } else {
                introText = 0x1299;
            }
        }
        if (introText != 0) {
            func_80800D20_chdragonbrothers(arg0, introText, 1);
        }
        break;
    case 5:
        data[0x58] = 3;
        func_80800B9C_chdragonbrothers(data, 1, arg0 + 4);
        func_80800A80_chdragonbrothers(arg0, 2, 0x420, 0);
        break;
    case 6:
        func_80800D20_chdragonbrothers(arg0, (arg0[0x7A] & 1) ? 0x12A5 : 0x12A6, 1);
        func_8080098C_chdragonbrothers(arg0, 2, 1);
        break;
    case 3:
        if (arg0[0x7A] & 1) {
            if (func_800DA298(0x1D6)) {
                func_800DA544(0x1D2);
                text = 0x12A3;
            } else {
                text = 0x12A1;
            }
        } else {
            if (func_800DA298(0x1D5)) {
                func_800DA524(0x1D2);
                text = 0x12A4;
            } else {
                text = 0x12A2;
            }
        }
        func_8080098C_chdragonbrothers(arg0, 2, 1);
        func_80800D20_chdragonbrothers(arg0, text, 1);
        break;
    case 8:
        func_800FDC28(0);
        data[0x58] = 1;
        if (func_800D395C()) {
            func_80800A80_chdragonbrothers(arg0, 0x14, 0x420, 0);
        } else {
            func_80800A80_chdragonbrothers(arg0, 0x14, 0x400, 0);
        }
        break;
    case 11:
        *(f32 *)(arg0 + 0x58) = 3.0f;
        break;
    case 12:
        func_80800A80_chdragonbrothers(arg0, 0x1D, 0x430, 0);
        break;
    case 13:
        func_80800B9C_chdragonbrothers(data, 1, arg0 + 4);
        func_80800D20_chdragonbrothers(arg0, (arg0[0x7A] & 1) ? 0x12AE : 0x12AF, 1);
        break;
    case 14:
    case 15:
        data[0x5B]++;
    case 16:
    case 17:
        *(f32 *)(arg0 + 0x58) = 0.0f;
        break;
    }
}

/* extern */

s32 func_8080110C_chdragonbrothers(s32 arg0, f32 arg1, f32 arg2, s32 arg3) {
    f32 func_800F2094(f32, f32);
    s32 temp_cond;
    s32 var_s0;

    var_s0 = 0;
loop_1:
    temp_cond = func_800F2094((f32) var_s0, arg1) < 10.0f;
    var_s0 += 0x5A;
    if (temp_cond) {
        return 0;
    }
    if (var_s0 == 0x168) {
        if (func_800F2094(arg2, arg1) < 5.0f) {
            return 0;
        }
        return 1;
    }
    goto loop_1;
}

f32 func_808011C0_chdragonbrothers(u8 *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    struct DragonData { u8 pad[0x18]; f32 angle; };
    f32 test;
    f32 step;
    f32 base;
    f32 angle;
    s32 done;

    angle = ((struct DragonData *)func_80100094((Actor *)arg0, 0))->angle;
    step = 1.0f;
    done = 0;
    if (arg1 != 0) {
        base = angle;
    } else {
        base = ((Actor *)arg0)->rotation[1];
    }
    do {
        if (arg1 == 0) {
            test = base + step;
            if (func_8080110C_chdragonbrothers((s32)arg0, test, angle, arg1)) {
                return test;
            }
        }
        test = base - step;
        if (func_8080110C_chdragonbrothers((s32)arg0, test, angle, arg1)) {
            return test;
        }
        step += 1.0f;
    } while (done == 0);
    return base;
}

void func_808012B4_chdragonbrothers(u8 *arg0, s32 arg1) {
    s32 _chintrotext_entrypoint_1(s32, s32, s32, s32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 func_800DA298(s32);
    s32 func_800DA544(s32);
    s32 func_800DA9E4(s32, s32);
    void func_800EF04C(f32 *, f32 *);
    void func_800EFCD8(f32 *, f32, f32);
    f32 func_800F1DCC(f32, f32);
    void *func_80100094(Actor *, u32);
    void func_80800A80_chdragonbrothers(Actor *, s32, s32, s32);
    void func_80800B9C_chdragonbrothers(u8 *, s32, f32 *);
    void func_80800D20_chdragonbrothers(u8 *, s16, s32);
    f32 func_808011C0_chdragonbrothers(u8 *, s32);
    struct Flags { u32 pad : 12; u32 flag : 1; u32 rest : 19; };
    struct State { u16 state : 6; u16 rest : 10; };
    struct Count { u8 count : 4; u8 rest : 4; };
    struct Mode { u16 rest : 7; u16 mode : 9; };
    struct ByteFlags { u8 upper : 3; u8 flag4 : 1; u8 middle : 3; u8 flag0 : 1; };
    u8 *data;
    s32 flag;
    f32 vec[3];

    data = func_80100094(arg0, 0);
    switch (((struct State *)(arg0 + 0x72))->state) {
    case 3:
    case 4:
        ((struct ByteFlags *)(arg0 + 0x65))->flag0 = 1;
        break;
    case 5:
        func_80800B9C_chdragonbrothers(data, 0, arg0 + 4);
        break;
    case 6:
        func_80800B9C_chdragonbrothers(data, 0, arg0 + 4);
        func_80800000_chdragonbrothers(arg0, 1);
        data[0x5A] = 0;
        data[0x59] = 1;
        break;
    case 23:
        ((struct ByteFlags *)(arg0 + 0x65))->flag4 = 0;
        break;
    case 15:
    case 20:
    case 21:
        data[0x5A] = 0;
        break;
    case 16:
    case 17:
        data[0x54] = 0;
        break;
    }
    func_80102424(arg0, arg1);
    switch (((struct State *)(arg0 + 0x72))->state) {
    case 5:
        func_80800A80_chdragonbrothers(arg0, 0, 0x420, 0);
        func_800FDC28(1);
        if (arg0[0x7A] & 1) {
            if (!func_800DA298(0x1D3)) {
                _chintrotext_entrypoint_1(0x18B9, 9, 1, 0);
            }
        } else {
            if (!func_800DA298(0x1D4)) {
                _chintrotext_entrypoint_1(0x18B9, 10, 1, 0);
            }
        }
        break;
    case 6:
        func_80800A80_chdragonbrothers(arg0, 5, 0x420, 0);
        func_80800B9C_chdragonbrothers(data, 1, arg0 + 4);
        func_80101EE4(arg0, 0x3F000000);
        data[0x5A] = 1;
        break;
    case 8:
        ((struct Count *)(arg0 + 0x79))->count--;
        break;
    case 9:
        if (((struct Flags *)(arg0 + 0x64))->flag) {
            *(f32 *)(arg0 + 0x58) = 0.0f;
        } else {
            *(f32 *)(arg0 + 0x58) = 0.5f;
        }
        break;
    case 10:
        if (((struct Flags *)(arg0 + 0x64))->flag) {
            *(f32 *)(arg0 + 0x58) = 1.0f;
        } else {
            *(f32 *)(arg0 + 0x58) = 2.0f;
        }
        break;
    case 11:
        flag = (arg0[0x7A] & 1) ? 0x406 : 0x407;
        ((struct Mode *)(arg0 + 0x6E))->mode = 1;
        if (((struct Flags *)(arg0 + 0x64))->flag) {
            *(f32 *)(arg0 + 0x58) = 1.5f;
        } else {
            *(f32 *)(arg0 + 0x58) = 3.0f;
        }
        data[0x5D] = 1;
        if (!func_800DA9E4(flag, 1)) {
            func_80800D98_chdragonbrothers(arg0, 12);
        }
    case 12:
        _subaddieaudioquick_entrypoint_2(arg0, arg0 + 4, &(*(s32 *)D_80805558_chdragonbrothers));
        break;
    case 14:
        func_8010A570(arg0);
        func_80800000_chdragonbrothers(arg0, 0);
        if (!func_800DA298((arg0[0x7A] & 1) ? 0x404 : 0x405)) {
            func_80800B9C_chdragonbrothers(data, 1, arg0 + 4);
            func_80800A80_chdragonbrothers(arg0, 12, 0x420, 0);
        }
        *(f32 *)(arg0 + 0x54) = func_808011C0_chdragonbrothers(arg0, 1);
        data[0x5E] = 0;
        break;
    case 16:
        ((struct Mode *)(arg0 + 0x6E))->mode = 0;
        func_8010A590(arg0);
        *(f32 *)(arg0 + 0x24) = 0.0f;
        data[0x54] = 1;
        break;
    case 17:
        if (((struct Flags *)(arg0 + 0x64))->flag) {
            *(f32 *)(arg0 + 0x34) = 45.0f;
        } else {
            *(f32 *)(arg0 + 0x34) = 30.0f;
        }
        *(f32 *)(arg0 + 0x1C) = 0.0f;
        if (func_800F1DCC(*(f32 *)(arg0 + 0x48), *(f32 *)(data + 0x18)) < 0.0f) {
            func_80800D98_chdragonbrothers(arg0, 16);
        } else {
            func_80800D98_chdragonbrothers(arg0, 14);
        }
        data[0x5B] = 0;
        data[0x54] = 1;
        break;
    case 19:
        func_8010A570(arg0);
        _subaddieaudioquick_entrypoint_2(arg0, arg0 + 4, &(*(s32 *)D_808053B0_chdragonbrothers));
        func_80800B9C_chdragonbrothers(data, 1, arg0 + 4);
        func_80800A80_chdragonbrothers(arg0, 9, 0x420, 0);
        func_800DA544((arg0[0x7A] & 1) ? 0x1D5 : 0x1D6);
        func_80800000_chdragonbrothers(arg0, 2);
        *(f32 *)(arg0 + 0x54) = func_808011C0_chdragonbrothers(arg0, 1);
        func_80800D98_chdragonbrothers(arg0, 10);
        break;
    case 20:
        data[0x59] = 0;
        data[0x5A] = 1;
        break;
    case 15:
    case 21:
        data[0x5A] = 1;
        break;
    case 22:
        ((struct ByteFlags *)(arg0 + 0x65))->flag4 = 1;
        *(f32 *)(arg0 + 0x48) = 0.0f;
        func_80800A80_chdragonbrothers(arg0, 24, 0x420, 0);
        break;
    case 23:
        func_80800D20_chdragonbrothers(arg0, (arg0[0x7A] & 1) ? 0x12CA : 0x12CB, 1);
        vec[1] = 1500.0f;
        func_800EFCD8(vec, *(f32 *)(arg0 + 0x48), -600.0f);
        func_800EF04C((f32 *)(arg0 + 4), vec);
        func_80800D98_chdragonbrothers(arg0, 7);
        break;
    case 2:
        ((struct ByteFlags *)(arg0 + 0x65))->flag0 = 0;
        break;
    }
}

/* extern */

void func_8080183C_chdragonbrothers(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s8 *data = func_80100094(arg0, 0U);

    if (arg0->unk64_19) {
        arg0->unk79_4 = 3;
    } else {
        arg0->unk79_4 = 3;
    }
    data[0x5E]++;
    func_8010A590((u8 *)arg0);
    func_808012B4_chdragonbrothers((u8 *)arg0, 8);
}

/* extern */

void func_808018BC_chdragonbrothers(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    void func_808012B4_chdragonbrothers(u8 *, s32);
    u32 *data = func_80100094(arg0, 0U);
    data[5] = 0;
    if (arg0->unk64_19) {
        arg0->unk79_4 = 4;
    } else {
        arg0->unk79_4 = 2;
    }
    func_808012B4_chdragonbrothers((u8 *)arg0, 0xE);
}

void func_80801924_chdragonbrothers(Actor *arg0, Actor *arg1) {
    void *func_80100094(Actor *, u32);
    struct {
        u8 state[4];
        u8 hits[4];
        s32 pad8;
        s32 remaining;
        s32 pad10;
        s32 count;
    } *data;
    u32 limit;

    data = func_80100094(arg0, 0);
    if (arg0->unk64_19) {
        limit = 3;
    } else {
        limit = 2;
    }
    if (arg0->unk6C_0 < limit) {
        data->remaining--;
        data->count++;
        if (data->remaining <= 0) {
            func_808012B4_chdragonbrothers((u8 *)arg0, 0x13);
            return;
        }
        data->hits[arg1->unk74_7]++;
        if (data->hits[arg1->unk74_7] >= 3) {
            data->state[arg1->unk74_7] = 2;
        }
        switch (arg0->unk70_10) {
        case 8:
        case 9:
        case 10:
            func_808012B4_chdragonbrothers((u8 *)arg0, 0xB);
            break;
        case 11:
        case 12:
        case 13:
            arg0->unk6C_0++;
            func_808012B4_chdragonbrothers((u8 *)arg0, 0xC);
            break;
        }
    }
}

s32 func_80801A4C_chdragonbrothers(void *arg0, f32 arg1) {
    f32 func_800D8FF8(void);
    Actor *actor = arg0;
    f32 dt;
    f32 limit;

    dt = func_800D8FF8();
    if (arg1 > 2.0f) {
        limit = arg1 * 15.5f;
        if (limit < actor->unk50) {
            actor->unk50 -= (actor->unk50 - arg1) * 0.006f * 60.0f;
        } else {
            actor->unk50 += arg1 * 0.015f * 60.0f;
            if (limit < actor->unk50) {
                actor->unk50 = limit;
            }
        }
    } else if (arg1 < -2.0f) {
        limit = arg1 * 15.5f;
        if (actor->unk50 < limit) {
            actor->unk50 -= (actor->unk50 - arg1) * 0.006f * 60.0f;
        } else {
            actor->unk50 += arg1 * 0.015f * 60.0f;
            if (actor->unk50 < limit) {
                actor->unk50 = limit;
            }
        }
    } else {
        actor->unk50 *= 0.9f;
    }
    if (actor->unk50 > 75.0f) {
        actor->unk50 = 75.0f;
    } else if (actor->unk50 < -75.0f) {
        actor->unk50 = -75.0f;
    }
    actor->rotation[1] += actor->unk50 * dt;
}

void func_80801C44_chdragonbrothers(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    f32 func_800F1DCC(f32, f32);
    s32 func_80801A4C_chdragonbrothers(void *, f32);
    s32 pad;
    f32 angle;
    f32 delta = 0.0f;
    f32 *data;

    data = func_80100094(arg0, 0);
    angle = data[6] + (f32)arg1;
    if (arg1 == 0) {
        delta = func_800F1DCC(angle, ((f32 *)arg0->actorData)[0]) * 10.0f;
    }
    data[7] = angle + delta;
    delta = func_800F1DCC(data[7], arg0->rotation[1]);
    arg0->unk54 = angle;
    func_80801A4C_chdragonbrothers(arg0, delta);
}

/* extern */

void func_80801CEC_chdragonbrothers(void *arg0) {
    f32 func_800F1DCC(f32, f32);
    s32 func_80801A4C_chdragonbrothers(void *, f32);
    func_80801A4C_chdragonbrothers(arg0, func_800F1DCC((*(f32 *)((s8 *)(arg0) + (0x54))), (*(f32 *)((s8 *)(arg0) + (0x48)))));
    func_80801A4C_chdragonbrothers(arg0, func_800F1DCC((*(f32 *)((s8 *)(arg0) + (0x54))), (*(f32 *)((s8 *)(arg0) + (0x48)))));
}

s32 func_80801D40_chdragonbrothers(Actor *arg0, s32 arg1, s32 arg2) {
    s32 func_800D0A9C(u32, u32);
    void func_800D1000(u32, u32, f32 *, u32, Unk80132ED0 *);
    int func_800DC298(f32);
    s32 func_800F6438(u32);
    void func_800F7B9C(s32, u32);
    Actor *func_80106790(Unk80132ED0 *);
    s32 _gcdialogcamera_entrypoint_3(s32 *, f32);
    void _gcdialogcamera_entrypoint_4(f32 *);
    void _gcfrontend_entrypoint_10(void);
    void _gcfrontend_entrypoint_11(void);
    s32 func_800DA9E4(s32, s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EEB9C(f32 *, f32, f32);
    void func_800EF1B8(f32 *, f32, f32);
    void func_800EF934(f32 *, f32 *, f32);
    f32 func_800F2094(f32, f32);
    u32 func_800F54E4(void);
    s32 func_800F6478(s32);
    int func_800F6AA4(s32);
    void *func_80100094(Actor *, u32);
    void *func_80101080(void);
    Actor *func_80108528(s32, f32 *, s32, Actor **);
    u8 *data;

    data = func_80100094(arg0, 0);
    switch (arg1) {
    default:
        return 0;
    case 0x96:
        data[0x63] = 1;
        if (!func_800D395C()) {
            return 0;
        }
        func_80800D20_chdragonbrothers((u8 *)arg0, 0xCEB, 0x40);
        break;
    case 0x9F:
        func_800FDC28(0);
        data[0x59] = 0;
        if (func_80800438_chdragonbrothers(arg0)) {
            func_808004A4_chdragonbrothers(arg0, 1);
        }
        break;
    case 0x3D: {
        Actor *actor;
        f32 pos[3];
        *(Vec3f *)pos = (*(Vec3f *)D_80805608_chdragonbrothers);
        func_800EF934(pos, pos, arg0->rotation[1]);
        actor = func_80108528(0x379, pos, (s32)arg0->rotation[1], &arg0);
        actor->unk64_19 = arg0->unk64_19;
        actor->unk3C = arg0->unk0;
        break;
    }
    case 0x54: {
        Actor *actor;
        actor = func_80106790((Unk80132ED0 *)arg2);
        if (((s32 *)data)[3] <= 0) {
            return 1;
        }
        ((s8 *)data)[8 + actor->unk74_7]--;
        if ((actor->unk79_4 == 2 && arg0->unk7A_8) ||
            (actor->unk79_4 == 3 && !arg0->unk7A_8)) {
            func_80801924_chdragonbrothers(arg0, actor);
        } else if (arg0->unk70_10 == 8 || arg0->unk70_10 == 9 ||
                   arg0->unk70_10 == 10 || arg0->unk70_10 == 13) {
            if (arg0->unk7A_8) {
                if (!func_800DA9E4(0x1D7, 1)) {
                    func_80800D20_chdragonbrothers((u8 *)arg0, 0x129E, 1);
                }
            } else if (!func_800DA9E4(0x1D8, 1)) {
                func_80800D20_chdragonbrothers((u8 *)arg0, 0x129F, 1);
            }
        }
        break;
    }
    case 0x3E:
        if (!arg0->unk64_16) {
            break;
        }
        if (((Unk80132ED0 *)arg2)->unk24 >> 22) {
            break;
        }
            switch (arg0->unk70_10) {
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
            case 16:
            case 17:
            case 18: {
                s32 flag;
                flag = func_800F54E4();
                if (func_800F6438(flag) && !func_800F6AA4(flag) && func_800F6478(flag)) {
                    func_800F7B9C(flag, 0x51);
                }
                break;
            }
            }
        break;
    case 0x2E: {
        s16 *dialog;
        dialog = (s16 *)&arg2;
        if (dialog[0] == 0xCEB) {
            if (dialog[1] == 1) {
                _gcfrontend_entrypoint_11();
            } else {
                _gcfrontend_entrypoint_10();
            }
            break;
        }
        switch (((s32 *)data)[4]) {
        case 7:
            return 1;
        case 1:
            switch (dialog[0]) {
            case 0x1296:
            case 0x1297:
            case 0x1298:
            case 0x1299:
            case 0x129A:
            case 0x129B:
            case 0x129C:
            case 0x129D:
                if (arg0->unk7A_8) {
                    func_800FDC28(8);
                } else {
                    func_800FDC28(9);
                }
                func_80800B34_chdragonbrothers(arg0, 1);
                func_808012B4_chdragonbrothers((u8 *)arg0, 10);
                break;
            default:
                return 1;
            }
            break;
        case 2:
            return 1;
        case 3:
            switch (dialog[0]) {
            case 0x12A1:
            case 0x12A2:
                func_808012B4_chdragonbrothers((u8 *)arg0, 22);
                goto dialog_done;
            case 0x12A3:
            case 0x12A4:
                goto dialog_done;
            }
            return 1;
        case 6:
            switch (dialog[0]) {
            case 0x12A5:
            case 0x12A6:
                func_808012B4_chdragonbrothers((u8 *)arg0, 16);
                func_80800B34_chdragonbrothers(arg0, 1);
                func_80800B9C_chdragonbrothers(data, 0, arg0->position);
                break;
            }
            break;
        case 12:
        case 13:
            switch (dialog[0]) {
            case 0x12AE:
            case 0x12AF:
                func_80800B34_chdragonbrothers(arg0, 1);
                func_80800B9C_chdragonbrothers(data, 0, arg0->position);
                break;
            default:
                return 1;
            }
            break;
        default:
            return 1;
        }
dialog_done:
        func_80800D98_chdragonbrothers((u8 *)arg0, 0);
        arg0->unk74_30 = 0;
        break;
    }
    case 0x2F:
        if (((s16 *)&arg2)[1] == 1 && !func_800D395C() && !func_800D0A9C(0x3D, 1)) {
            f32 pos[3];
            f32 angle;
            *(Vec3f *)pos = (*(Vec3f *)D_80805614_chdragonbrothers);
            angle = ((f32 *)data)[6];
            if (func_800F2094(0.0f, angle) < 10.0f) {
                func_800EEB9C(pos, (func_800DC298(0.5f) ? 4 : -4) + angle, 3100.0f);
            }
            func_800D1000(0x3D, 1, pos, 1, arg0->unk0);
        }
        break;
    case 0xD:
        func_80800A80_chdragonbrothers(arg0, 22, 0x400, (s32)func_80101080());
        break;
    case 0xB:
        switch (arg2) {
        case 0x1A:
            func_80800D98_chdragonbrothers((u8 *)arg0, 8);
            return 4;
        case 0x14:
            if (func_800D395C()) {
                _gcfrontend_entrypoint_10();
            } else {
                func_80800B34_chdragonbrothers(arg0, 0);
                func_80800B9C_chdragonbrothers(data, 0, arg0->position);
                func_808004A4_chdragonbrothers(arg0, 1);
            }
            return 4;
        case 0x16:
            func_808012B4_chdragonbrothers((u8 *)arg0, 22);
            return 4;
        default:
            return 3;
        }
    case 0x52:
        switch (arg0->unk70_10) {
        case 15: {
            f32 pos[3];
            func_800EE7F8(pos, arg0->position);
            func_800EF1B8(pos, arg0->rotation[1], arg0->scale * 650.0f);
            _gcdialogcamera_entrypoint_3(((s32 *)D_80805620_chdragonbrothers), arg0->scale);
            _gcdialogcamera_entrypoint_4(pos);
            break;
        }
        case 19: {
            f32 pos[3];
            func_800EE7F8(pos, arg0->position);
            func_800EF1B8(pos, arg0->rotation[1], arg0->scale * 600.0f);
            _gcdialogcamera_entrypoint_3(((s32 *)D_80805630_chdragonbrothers), arg0->scale);
            _gcdialogcamera_entrypoint_4(pos);
            break;
        }
        default:
            _gcdialogcamera_entrypoint_3(((s32 *)D_80805640_chdragonbrothers), arg0->scale);
            break;
        }
        break;
    }
    return 1;
}

/* extern */

int func_80802534_chdragonbrothers(s32 arg0) {
    s32 func_8008FA2C(s32, s32);
    return (func_80090248() != 0) && (func_8008FA2C(-1, 0) != 0);
}

void func_80802574_chdragonbrothers(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    s32 _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
    void _suexpression_entrypoint_9(u32 *);
    void _suexpression_entrypoint_10(u32 *, Unk80132ED0 *, u32);
    s32 func_8008FA2C(s32, s32);
#ifdef BT_NATIVE
    s32 func_80090178(s32);
#else
    s32 func_80090178(AllowedTransformation);
#endif
    s32 func_800C067C(s32);
    s32 func_800D2498(u32, s32, u32);
    f32 func_800D8FF8(void);
    s32 func_800DA298(s32);
    s32 func_800DA9E4(s32, s32);
    s32 func_800E1610(s32, f32, f32, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EEB9C(f32 *, f32, f32);
    f32 func_800EF030(void *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EFCD8(f32 *, f32, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F1DCC(f32, f32);
    s32 func_800F1EA4(f32 *, f32 *);
    f32 func_800F2094(f32, f32);
    void func_800F5A00(s32, f32 *);
    void *func_80100094(Actor *, u32);
    s32 func_80101DDC(Actor *);
    s32 func_80101E14(Actor *, f32);
    s32 func_80101E4C(Actor *, f32 *);
    void func_80108B04(Actor *, s32);
    s32 func_8010CB0C(f32 *, s32, s32, s32);
    struct DragonRotation { f32 previousAngle, unused, targetAngle, velocity; f32 unused10[3]; f32 magnitude; };
    f32 dt;
    struct DragonData {
        u8 pad0[0xC];
        s32 unkC;
        s32 state;
        s32 count;
        f32 angles[2];
        s32 player;
        u8 pad24[0x34];
        u8 flag58, flag59, flag5A, flag5B, flag5C, flag5D;
        s8 flag5E;
        u8 flag5F;
        s8 flag60;
        u8 flag61, flag62, flag63;
    } *data;
    f32 playerPos[3];
    f32 velocity[3];
    f32 soundPos[3];
    s32 limit;
    s32 sweepLimit;
    f32 loopPos[3];
    f32 impactPos[3];

    dt = func_800D8FF8();
    data = func_80100094(arg0, 0);
    if ((s32)arg0->unk70_10 >= 5 && data->flag63 == 0) { func_800F5A00(data->player, playerPos);
        func_800F1EA4(playerPos, data->angles);
        ((struct DragonRotation *)arg0->actorData)->previousAngle = ((struct DragonRotation *)arg0->actorData)->targetAngle;
        ((struct DragonRotation *)arg0->actorData)->targetAngle = data->angles[0];
        if (data->flag61 != 0) {
            if (func_80090178(0x10000)) {
                if (data->flag62 != 0) {
                    data->flag62 = 0;
                    func_80800438_chdragonbrothers(arg0);
                }
            } else if (data->flag62 == 0) {
                data->flag62 = 1;
                func_808008C8_chdragonbrothers(arg0);
            }
        }
        switch (arg0->unk70_10) {
        case 7: case 8: case 9: case 10: case 11: case 12:
        case 13: case 14: case 16: case 17: case 18:
            if (playerPos[1] < -200.0f || (playerPos[1] < -10.0f && func_800EF030(playerPos) > 10824100.0f)) {
                if (data->flag61 != 0) {
                    data->flag61 = 0;
                    func_80800438_chdragonbrothers(arg0);
                    func_808004A4_chdragonbrothers(arg0, 0);
                }
            } else if (data->flag61 == 0) {
                data->flag61 = 1;
                func_808008C8_chdragonbrothers(arg0);
            }
            break;
        }
    }
    if (arg0->unk70_10 == 23) {
        func_800EFCD8(velocity, arg0->rotation[1], 1000.0f * dt);
        velocity[1] = 800.0f * dt;
        func_800EF04C(arg0->position, velocity);
    } else {
        func_800EEB9C(arg0->position, arg0->rotation[1], 250.0f);
        arg0->position[1] = -200.0f;
    }
    if (arg0->unk7A_8) {
        if (data->flag5C == 2 && !func_800DA298(0x406)) {
            func_80800B9C_chdragonbrothers((u8 *)data, 1, arg0->position);
            data->flag5C = 10;
            func_800C067C(0x129E);
        }
    } else {
        if (data->flag5C == 3 && !func_800DA298(0x407)) {
            func_80800B9C_chdragonbrothers((u8 *)data, 1, arg0->position);
            data->flag5C = 10;
            func_800C067C(0x129F);
        }
    }
    switch (arg0->unk70_10) {
    case 3:
        switch (data->state) {
        case 4:
            if (func_8010CB0C(((f32 *)D_80805650_chdragonbrothers), 0x8FC, 10, -10) && func_8008FA2C(1, 0)) {
                func_80800D98_chdragonbrothers(arg0, 5);
            }
            break;
        case 5:
            if (data->flag58 == 2) {
                func_80800D98_chdragonbrothers(arg0, 0);
                func_808012B4_chdragonbrothers(arg0, 5);
            }
            break;
        }
        break;
    case 4:
        if (data->state == 4 && func_8010CB0C(((f32 *)D_8080565C_chdragonbrothers), 0x8FC, 10, -10) && func_8008FA2C(1, 0)) {
            data->flag58 = 3;
            func_80800D98_chdragonbrothers(arg0, 1);
            func_808012B4_chdragonbrothers(arg0, 6);
        }
        break;
    case 5:
        if (func_80101DDC(arg0)) {
            func_80800D98_chdragonbrothers(arg0, 1);
            func_808012B4_chdragonbrothers(arg0, 6);
        }
        func_80801C44_chdragonbrothers(arg0, 0);
        break;
    case 6:
        if (func_80101E4C(arg0, ((f32 *)D_80805668_chdragonbrothers))) {
            if (arg0->unk7C_12) {
                _subaddieskeleton_entrypoint_2(arg0->unk0, 4, soundPos);
            } else {
                func_800EE7F8(soundPos, arg0->position);
            }
            _subaddieaudioquick_entrypoint_2(arg0, soundPos, ((u32 *)D_808053C8_chdragonbrothers));
        }
        break;
    case 7:
        if (func_800F2094(arg0->rotation[1], data->angles[0]) < 10.0f) {
            func_8080183C_chdragonbrothers(arg0);
        }
        func_80801C44_chdragonbrothers(arg0, 0);
        break;
    case 8:
        func_80801C44_chdragonbrothers(arg0, 0);
        if (func_80101E14(arg0, 0.1f)) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, ((u32 *)D_808053E0_chdragonbrothers));
        } else if (func_80101E14(arg0, 0.25f)) {
            func_80108B04(arg0, 0);
        } else if (func_80101DDC(arg0)) {
            if ((s32)arg0->unk79_4 > 0) {
                func_808012B4_chdragonbrothers(arg0, 9);
            } else if (data->flag5D && data->flag5E == 3 && data->flag61) {
                func_808018BC_chdragonbrothers(arg0);
            } else {
                func_808012B4_chdragonbrothers(arg0, 10);
            }
        }
        break;
    case 9:
        if (arg0->unk58 > 0.0f) {
            arg0->unk58 -= func_800D8FF8();
        } else if (data->flag61 && !data->flag63) {
            func_808012B4_chdragonbrothers(arg0, 8);
        }
        func_80801C44_chdragonbrothers(arg0, 0);
        break;
    case 10:
        if (arg0->unk58 > 0.0f) {
            arg0->unk58 -= func_800D8FF8();
        } else if (data->flag61 && !data->flag63) {
            func_8080183C_chdragonbrothers(arg0);
        }
        func_80801C44_chdragonbrothers(arg0, 0);
        break;
    case 11: case 12:
        if (func_80101DDC(arg0)) {
            if (data->state == 12) {
                func_80800D98_chdragonbrothers(arg0, 13);
            }
            func_808012B4_chdragonbrothers(arg0, 13);
        }
        if (data->state == 0 && arg0->unk58 > 0.0f) {
            arg0->unk58 -= dt;
        }
        func_80801C44_chdragonbrothers(arg0, 0);
        break;
    case 13:
        func_80801C44_chdragonbrothers(arg0, 0);
        if (data->state == 0) {
            limit = arg0->unk64_19 ? 3 : 2;
            if ((arg0->unk6C_0 >= limit || data->count >= limit) &&
                (func_80802534_chdragonbrothers(arg0) || func_800DA298(arg0->unk7A_8 ? 0x404 : 0x405))) {
                func_808018BC_chdragonbrothers(arg0);
            } else if (arg0->unk58 > 0.0f) {
                arg0->unk58 -= dt;
            } else if (data->flag60 > 0) {
                func_80800000_chdragonbrothers(arg0, 0);
            } else if (func_80802534_chdragonbrothers(arg0) || func_800DA298(arg0->unk7A_8 ? 0x404 : 0x405)) {
                func_808018BC_chdragonbrothers(arg0);
            }
        }
        break;
    case 14:
        if (func_80101DDC(arg0)) {
            if (!func_800DA9E4(arg0->unk7A_8 ? 0x404 : 0x405, 1)) {
                func_808012B4_chdragonbrothers(arg0, 15);
                func_80800D98_chdragonbrothers(arg0, 6);
            } else {
                func_808012B4_chdragonbrothers(arg0, 16);
            }
        }
        func_80801CEC_chdragonbrothers(arg0);
        break;
    case 15:
        func_80801CEC_chdragonbrothers(arg0);
        break;
    case 16:
        if (func_80101DDC(arg0)) {
            func_808012B4_chdragonbrothers(arg0, 17);
        }
        func_80801CEC_chdragonbrothers(arg0);
        break;
    case 17:
        func_800EEB9C(loopPos, arg0->rotation[1], 2300.0f);
        _subaddieaudioloop_entrypoint_4(arg0, loopPos, 1, ((u32 *)D_80805678_chdragonbrothers));
        arg0->unk58 += dt;
        arg0->unk54 = data->angles[0];
        switch (data->state) {
        case 14:
            ((struct DragonRotation *)arg0->actorData)->velocity = func_800F10B4(arg0->unk58, 0.0f, arg0->unk64_19 ? 0.6499938965f : 1.299987793f, 0.0f, ((struct DragonRotation *)arg0->actorData)->magnitude);
            if ((arg0->unk64_19 ? 1.0f : 1.5f) < arg0->unk58 && func_800F1DCC(arg0->rotation[1], arg0->unk54) <= 0.0f) {
                func_80800D98_chdragonbrothers(arg0, 15);
            }
            break;
        case 15:
            ((struct DragonRotation *)arg0->actorData)->velocity = func_800F10B4(arg0->unk58, 0.0f, arg0->unk64_19 ? 0.4499969482f : 0.8499908447f, ((struct DragonRotation *)arg0->actorData)->magnitude, 0.0f);
            if ((arg0->unk64_19 ? 0.4499969482f : 0.8499908447f) < arg0->unk58) {
                func_80800D98_chdragonbrothers(arg0, 16);
            }
            break;
        case 16:
            ((struct DragonRotation *)arg0->actorData)->velocity = func_800F10B4(arg0->unk58, 0.0f, arg0->unk64_19 ? 0.6499938965f : 1.299987793f, 0.0f, -((struct DragonRotation *)arg0->actorData)->magnitude);
            if ((arg0->unk64_19 ? 1.0f : 1.5f) < arg0->unk58 && func_800F1DCC(arg0->rotation[1], arg0->unk54) >= 0.0f) {
                func_80800D98_chdragonbrothers(arg0, 17);
            }
            break;
        case 17:
            ((struct DragonRotation *)arg0->actorData)->velocity = func_800F10B4(arg0->unk58, 0.0f, arg0->unk64_19 ? 0.4499969482f : 0.8499908447f, -((struct DragonRotation *)arg0->actorData)->magnitude, 0.0f);
            if ((arg0->unk64_19 ? 0.4499969482f : 0.8499908447f) < arg0->unk58) {
                func_80800D98_chdragonbrothers(arg0, 14);
            }
            break;
        }
        arg0->rotation[1] -= ((struct DragonRotation *)arg0->actorData)->velocity * dt;
        if (data->flag5B > (arg0->unk64_19 ? 4 : 2) || data->flag63) {
            func_80800D98_chdragonbrothers(arg0, 0);
            func_808012B4_chdragonbrothers(arg0, 18);
        }
        break;
    case 18:
        func_80801C44_chdragonbrothers(arg0, 0);
        if (func_80101E14(arg0, 0.999f)) {
            func_808012B4_chdragonbrothers(arg0, 7);
            func_80800000_chdragonbrothers(arg0, 1);
        }
        break;
    case 19:
        func_80800C08_chdragonbrothers(arg0);
        func_80801CEC_chdragonbrothers(arg0);
        switch (data->state) {
        case 10:
            if (func_80101E14(arg0, 0.92f)) {
                func_800EEB9C(impactPos, arg0->rotation[1], 3100.0f);
                func_800E1610(2, 150.0f, 0.85f, impactPos);
                _subaddieaudioquick_entrypoint_2(arg0, impactPos, ((u32 *)D_80805410_chdragonbrothers));
            } else if (func_80101DDC(arg0)) {
                func_80800D98_chdragonbrothers(arg0, 3);
            }
            break;
        case 3:
            if (arg0->unk58 > 0.0f) {
                arg0->unk58 -= func_800D8FF8();
            } else {
                func_808012B4_chdragonbrothers(arg0, 20);
            }
            break;
        }
        break;
    case 20:
        if (func_80101DDC(arg0)) {
            func_808012B4_chdragonbrothers(arg0, 21);
        }
        break;
    case 22:
        if (func_80101E4C(arg0, ((f32 *)D_80805694_chdragonbrothers))) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, ((u32 *)D_80805424_chdragonbrothers));
        }
        if (func_80101DDC(arg0)) {
            func_808012B4_chdragonbrothers(arg0, 23);
            func_80800A80_chdragonbrothers(arg0, 26, 0x420, 0);
        }
        break;
    case 23:
        _subaddieaudioquick_entrypoint_3(arg0, arg0->position, ((u32 *)D_80805424_chdragonbrothers), 0.1f);
        switch (data->state) {
        case 7:
            break;
        case 8:
            if (data->flag58 == 0) {
                func_80800D98_chdragonbrothers(arg0, 9);
            }
            break;
        case 9:
            func_808012B4_chdragonbrothers(arg0, 2);
            func_80800D98_chdragonbrothers(arg0, 0);
            break;
        }
        break;
    }
    if (!data->flag5A) {
        _suexpression_entrypoint_9(func_80100094(arg0, 1));
    }
    _suexpression_entrypoint_10(func_80100094(arg0, 1), arg0->unk0, 0);
    func_808006C8_chdragonbrothers(arg0);
    if (data->flag59 == 1) {
        func_800D2498(arg0->unk7A_8 ? 0xF9 : 0xFA, data->unkC, 0);
    }
}

void func_808034DC_chdragonbrothers(Actor *arg0, void *arg1) {
    void func_800DF744(s32, s32);
    void func_80101870(Actor *, void *);

    if (arg0->unk64_20) {
        func_800DF744(3, 1);
        func_800DF744(4, 1);
        func_800DF744(5, 1);
    } else {
        func_800DF744(3, 0);
        func_800DF744(4, 0);
        func_800DF744(5, 0);
    }
    func_80101870(arg0, arg1);
}

OSThread *chdragonbrothers_entrypoint_0(void)
{
    return (OSThread *) ((u8 *)D_808056A8_chdragonbrothers);
}

void func_80803574_chdragonbrothers(Actor *arg0) {
    Actor *_subaddiefind_entrypoint_2(s32, s32);
    s32 func_800DA298(s32);
    s32 func_800EA05C();
    void func_800EE7F8(f32 *, f32 *);
    void func_800EFCD8(f32 *, f32, f32);
    void func_800FFAB0(Actor *);
    f32 *sp20;

    arg0->unk74_7 = (s32)arg0->unk74_7 - 50;
    sp20 = arg0->position;
    func_800EE7F8((f32 *)arg0->actorData, sp20);
    arg0->position[1] = ((f32 *)arg0->actorData)[1] - 310.0f;
    if (func_800EA05C() == 0x12B) {
        arg0->unk7A_8 = 0;
    } else {
        arg0->unk7A_8 = 1;
    }
    if ((arg0->unk7A_8 && func_800DA298(0x1D5)) ||
        (!arg0->unk7A_8 && func_800DA298(0x1D6))) {
        func_800FFAB0(arg0);
        return;
    }
    arg0->unk3C = _subaddiefind_entrypoint_2(0x377, 0)->unk0;
    func_800EFCD8(sp20, (s32)arg0->unk74_7 * 90, 2700.0f);
    arg0->rotation[1] = (s32)arg0->unk74_7 * 90;
}

void func_808036E4_chdragonbrothers(s32 arg0) 
{
}
void func_808036EC_chdragonbrothers(Actor *arg0, s32 arg1) {
    if (arg0->unk70_10 == 4) {
        func_8010A570(arg0);
    }
    func_80102424(arg0, arg1);
    switch (arg0->unk70_10) {
        case 2:
            ((f32 *)arg0->actorData)[3] = 200.0f;
            break;
        case 4:
            func_8010A590(arg0);
            break;
        case 5:
            arg0->unk58 = 0.0f;
            break;
        case 8:
            ((f32 *)arg0->actorData)[3] = 400.0f;
            break;
        case 9:
            ((f32 *)arg0->actorData)[3] = 400.0f;
            break;
    }
}

void func_808037B0_chdragonbrothers(Actor *arg0, u32 arg1) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    extern u32 D_8080543C_chdragonbrothers[];
    struct DragonData {
        u8 pad0[4];
        u8 count[4];
        s8 hits[4];
        u8 padC[0x50];
        s8 last;
    };
    Actor *actor[1];
    struct DragonData *data;
    Actor *parent;
    u8 *entry;

    parent = func_80106790(arg0->unk3C);
    if (parent) {} /* Preserve IDO register allocation. */
    data = func_80100094(actor[0] = parent, 0);
    entry = (void *)((u8 *)data + arg0->unk74_7);
    parent = actor[0];
    if ((entry[4] + ((s8 *)entry)[8] < 3) &&
        (arg0->unk70_10 == 4 || arg0->unk70_10 == 5) &&
        func_808003F8_chdragonbrothers(parent)) {
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_8080543C_chdragonbrothers);
        arg0->unk79_4 = arg1 - 0x26B;
        data->last = arg0->unk79_4;
        func_808036EC_chdragonbrothers(arg0, 5);
        data->hits[arg0->unk74_7]++;
    }
}

void func_808038AC_chdragonbrothers(Actor *arg0) {
    f32 func_800D8FF8(void);
    s32 func_80101E14(Actor *, f32);
    s32 func_80101DDC(Actor *);
    void func_80108B04(Actor *, s32);
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    void func_808036EC_chdragonbrothers(Actor *, s32);
    typedef struct {
        f32 home[3];
        f32 speed;
    } DragonState;
    f32 dt;
    f32 target;
    u8 *data;
    u8 command;

    dt = func_800D8FF8();
    data = func_80100094(func_80106790(arg0->unk3C), 0);
    if (arg0->position[1] <= ((DragonState *)arg0->actorData)->home[1] - 450.0f) {
        arg0->unk64_16 = 0;
    } else {
        arg0->unk64_16 = 1;
    }
    if (arg0->position[1] <= ((DragonState *)arg0->actorData)->home[1] - 310.0f) {
        arg0->unk64_20 = 0;
    } else {
        arg0->unk64_20 = 1;
    }
    switch (arg0->unk70_10) {
    case 1:
        command = *(u8 *)((u32)data + arg0->unk74_7);
        if (command != 0) {
            if (command != 1) {
                if (command == 2) {
                    func_808036EC_chdragonbrothers(arg0, 9);
                }
            } else {
                func_808036EC_chdragonbrothers(arg0, 2);
            }
        }
        break;
    case 2:
        if (arg0->position[1] < ((DragonState *)arg0->actorData)->home[1]) {
            arg0->position[1] += ((DragonState *)arg0->actorData)->speed * dt;
            if (arg0->position[1] > ((DragonState *)arg0->actorData)->home[1] - 40.0f) {
                ((DragonState *)arg0->actorData)->speed *= 1.0f - 3.5f * dt;
            }
            _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, &(*(u32 *)D_808053A0_chdragonbrothers));
        } else {
            func_808036EC_chdragonbrothers(arg0, 3);
        }
        break;
    case 3:
        if (func_80101DDC(arg0)) {
            func_808036EC_chdragonbrothers(arg0, 4);
        }
        break;
    case 4:
        command = *(u8 *)((u32)data + arg0->unk74_7);
        if (command != 0) {
            if (command == 2) {
                func_808036EC_chdragonbrothers(arg0, 9);
            }
        } else {
            func_808036EC_chdragonbrothers(arg0, 6);
        }
        break;
    case 5:
        if (func_80101E14(arg0, 0.5f) && arg0->unk7C_12) {
            func_80108B04(arg0, arg0->unk79_4);
        }
        if (func_80101DDC(arg0)) {
            if (arg0->unk58 > 0.0f) {
                arg0->unk58 -= func_800D8FF8();
            } else {
                func_808036EC_chdragonbrothers(arg0, 4);
            }
        }
        break;
    case 6:
    case 7:
        if (func_80101DDC(arg0)) {
            command = *(u8 *)((u32)data + arg0->unk74_7);
            if (command != 0) {
                if (command == 2) {
                    func_808036EC_chdragonbrothers(arg0, 9);
                }
            } else {
                func_808036EC_chdragonbrothers(arg0, 8);
            }
        }
        break;
    case 8: {
        if (arg0->position[1] > ((DragonState *)arg0->actorData)->home[1] - 310.0f) {
            arg0->position[1] -= ((DragonState *)arg0->actorData)->speed * dt;
            if (arg0->position[1] > ((DragonState *)arg0->actorData)->home[1] - 75.0f) {
                ((DragonState *)arg0->actorData)->speed *= 1.0f + 1.5f * dt;
            }
            if (arg0->position[1] < ((DragonState *)arg0->actorData)->home[1] - 310.0f) {
                arg0->position[1] = ((DragonState *)arg0->actorData)->home[1] - 310.0f;
            }
            _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, &(*(u32 *)D_808053A0_chdragonbrothers));
        }
        command = *(u8 *)((u32)data + arg0->unk74_7);
        if (command != 1) {
            if (command == 2) {
                func_808036EC_chdragonbrothers(arg0, 9);
            }
        } else {
            func_808036EC_chdragonbrothers(arg0, 2);
        }
        break;
    }
    case 9:
        if (arg0->position[1] > ((DragonState *)arg0->actorData)->home[1] - 450.0f) {
            arg0->position[1] -= ((DragonState *)arg0->actorData)->speed * dt;
            if (arg0->position[1] > (((DragonState *)arg0->actorData)->home[1] - 450.0f) - 150.0f) {
                ((DragonState *)arg0->actorData)->speed *= 1.0f + 1.5f * dt;
            }
            if (arg0->position[1] < ((DragonState *)arg0->actorData)->home[1] - 450.0f) {
                arg0->position[1] = ((DragonState *)arg0->actorData)->home[1] - 450.0f;
            }
            _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, &(*(u32 *)D_808053A0_chdragonbrothers));
        }
        command = *(u8 *)((u32)data + arg0->unk74_7);
        if (command != 0) {
            if (command == 1) {
                func_808036EC_chdragonbrothers(arg0, 2);
            }
        } else {
            func_808036EC_chdragonbrothers(arg0, 6);
        }
        break;
    }
}

s32 func_80803DC4_chdragonbrothers(Actor *arg0, s32 arg1, void *arg2) {
    void func_800EF934(f32 *, f32 *, f32);
    void func_800EE780(f32 *, f32 *, f32 *);
    Actor *func_801084B0(s32, Actor **);
    s32 _sueggmisc_entrypoint_0();
    s32 func_8010114C(s32, s32, s32);
    void func_808037B0_chdragonbrothers(Actor *, u32);
    Actor *actor;
    f32 sp20[3];
    Unk80132ED0 *sp1C;
    switch (arg1) {
        case 0x3D: {
            *(Vec3f *)sp20 = (*(Vec3f *)D_80805740_chdragonbrothers);
            func_800EF934(sp20, sp20, arg0->rotation[1]);
            actor = func_801084B0(0x37A, &arg0);
            actor->rotation[0] = 153.5f;
            actor->unk50 = 63.5f;
            actor->unk79_4 = arg0->unk79_4;
            actor->unk74_7 = arg0->unk74_7;
            func_800EE780(actor->position, arg0->position, sp20);
            return 1;
        }
        case 0x3E: {
            sp1C = (Unk80132ED0 *)&arg2;
            sp1C = *(void **)sp1C;
            if (_sueggmisc_entrypoint_0(sp1C)) {
                func_8010114C((s32)sp1C, 0x2C, 0);
                func_808037B0_chdragonbrothers(arg0, sp1C->unk24 >> 22);
                return 1;
            }
            break;
        }
        default:
            return 0;
    }
    return 1;
}

/* extern */

void func_80803EFC_chdragonbrothers(void *arg0, s32 arg1) {
    void func_800DF744(s32, s32);
    void func_80101870(Actor *, void *);
    func_800DF744(1, (u32) ((*(s32 *)((s8 *)(arg0) + (0x64))) << 0xB) >> 0x1F);
    func_80101870(arg0, arg1);
}

OSThread *chdragonbrothers_entrypoint_1(void)
{
    return (OSThread *) ((u8 *)D_8080574C_chdragonbrothers);
}

void func_80803F4C_chdragonbrothers(Actor *arg0) {
    f32 func_800DC178(f32, f32);
    s32 func_800EA05C();
    void func_800EEBF0(f32 *, f32 *, f32);
    f32 func_800F1828(f32 *, f32 *);
    void func_800F5A00(s32, f32 *);
    void *func_80100094(Actor *, u32);
    s32 func_801032B0(Actor *, u16, u16);
    Actor *func_80106790(Unk80132ED0 *);
    s32 *parentData;
    typedef struct {
        f32 values[3];
        f32 padC;
        f32 rotation[3];
    } DragonData;
    f32 speed;
    f32 position[3];

    parentData = func_80100094(func_80106790(arg0->unk3C), 0);
    arg0->unk74_7 = arg0->unk74_7 - 50;
    func_800F5A00(parentData[8], position);
    position[1] += 30.0f;
    arg0->rotation[0] = func_800F1828(arg0->position, position);
    func_800EEBF0(((DragonData *)arg0->actorData)->rotation, arg0->rotation, arg0->unk64_19 ? 6000.0f : 4000.0f);
    if (func_800EA05C() == 0x12B) {
        arg0->unk7A_8 = 0;
    } else {
        arg0->unk7A_8 = 1;
    }
    if (arg0->unk7A_8) {
        func_801032B0(arg0, 0x814, arg0->unk0->unk16);
    }
    ((DragonData *)arg0->actorData)->values[0] = func_800DC178(50.0f, 100.0f);
    ((DragonData *)arg0->actorData)->values[1] = func_800DC178(5.0f, 10.0f);
    ((DragonData *)arg0->actorData)->values[2] = func_800DC178(5.0f, 10.0f);
}

void func_808040A0_chdragonbrothers(s32 arg0) 
{
}
void func_808040A8_chdragonbrothers(Actor *arg0) {
    void _chexploder_entrypoint_3(void *, void *, u32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void _subaddiefade_entrypoint_3(Actor *);
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void *func_800C6A7C(f32 *, f32 *, f32 *, u32);
    f32 func_800D8FF8(void);
    s32 func_800E1610(s32, f32, f32, f32 *);
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EFA20(void *, void *, f32);
    typedef struct {
    f32 angularVelocity[3];
    f32 padC;
    f32 velocity[3];
    } DragonData;
    f32 dt;
    void *collision;
    f32 displacement[3];
    f32 position[3];
    f32 normal[3];
    f32 *pos[1];
    dt = func_800D8FF8();
    arg0->unk58 += dt;
    if (arg0->unk70_10 == 1) {
    func_800EFA20(displacement, ((DragonData *)arg0->actorData)->velocity, dt);
    pos[0] = arg0->position;
    func_800EE780(position, pos[0], displacement);
    collision = func_800C6A7C(pos[0], position, normal, 0x20020);
    func_800EE7F8(pos[0], position);
    if (collision != NULL) {
    _chexploder_entrypoint_3(arg0, position, 8);
    func_800E1610(2, 100.0f, 0.85f, position);
    if (arg0->unk7A_8) {
    _subaddieaudioquick_entrypoint_2(arg0, NULL, &(*(s32 *)D_80805794_chdragonbrothers));

    } else {
    _subaddieaudioquick_entrypoint_2(arg0, pos[0], &(*(s32 *)D_80805448_chdragonbrothers));
    }
    } else if (arg0->position[1] < -400.0f) {
    _subaddiefade_entrypoint_3(arg0);
    } func_800EFA20(position, ((DragonData *)arg0->actorData)->angularVelocity, dt);
    func_800EF04C(arg0->rotation, ((DragonData *)arg0->actorData)->angularVelocity);
    if (arg0->unk58 > 0.25f) {
    if (!arg0->unk7A_8) {
    func_800BBCB8(pos[0], NULL, arg0->scale, 1, &(*(s32 *)D_808057A8_chdragonbrothers));
    if (!arg0->unk64_20 && arg0->unk58 > 0.3f) {
    _subaddieaudioquick_entrypoint_2(arg0, pos[0], &(*(s32 *)D_80805460_chdragonbrothers));
    arg0->unk64_20 = 1;
    }
    } else {
    func_800BBCB8(pos[0], NULL, arg0->scale, 1, &(*(s32 *)D_808057E0_chdragonbrothers));
    func_800BBCB8(pos[0], NULL, arg0->scale, 2, &(*(s32 *)D_80805810_chdragonbrothers));
    if (!arg0->unk64_20 && arg0->unk58 > 0.3f) {
    _subaddieaudioquick_entrypoint_2(arg0, pos[0], &(*(s32 *)D_80805474_chdragonbrothers));
    arg0->unk64_20 = 1;
    }
    } }
    } }

/* extern */

void func_80804318_chdragonbrothers(s32 arg0, s32 arg1) {
    void func_800DF744(s32, s32);
    void func_80101870(Actor *, void *);
    func_800DF744(1, 1);
    func_80101870(arg0, arg1);
}

s32 func_80804350_chdragonbrothers(Actor *arg0, s32 arg1, Unk80132ED0 *arg2) {
    s32 _chexploder_entrypoint_9(Actor *, s32, s32);
    void _chexploder_entrypoint_13(s32, u32);
    void _chexploder_entrypoint_15(s32, u32, f32);
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    u32 func_800F54E4(void);
    void func_800F7B9C(s32, u32);
    void *func_80101080(void);
    Actor *func_80106790(Unk80132ED0 *);
    Actor *sp24;
    Unk80132ED0 **marker = &arg2;

    switch (arg1) {
        case 0xF:
        case 0x90:
            sp24 = func_80106790(func_80101080());
            _chexploder_entrypoint_9(sp24, 1, 2);
            _chexploder_entrypoint_13(sp24, 6);
            if (arg0->unk7A_8) {
                _chexploder_entrypoint_15(sp24, 2, 1.0f);
            } else {
                _chexploder_entrypoint_15(sp24, 4, 1.0f);
            }
            if (arg0->unk7A_8) {
                func_800BBCB8(arg0->position, arg0->position, arg0->scale, 6, &(*(s32 *)D_80805840_chdragonbrothers));
            } else {
                func_800BBCB8(arg0->position, arg0->position, arg0->scale, 6, &(*(s32 *)D_80805870_chdragonbrothers));
            }
            break;
        case 0x3E:
            if (((*marker)->unk24 >> 22) == 0) {
                func_800F7B9C(func_800F54E4(), 0x51);
            }
            break;
        default:
            return 0;
    }
    return 1;
}

OSThread *chdragonbrothers_entrypoint_2(void)
{
    return (OSThread *) ((u8 *)D_808058A8_chdragonbrothers);
}

void func_8080449C_chdragonbrothers(Actor *arg0) {
    Actor *_subaddiefind_entrypoint_2(s32, s32);
    s32 func_800AF5A0(s16 *);
    f32 func_800DC178(f32, f32);
    s32 func_800EA05C();
    void *func_800EC3E8(u8 *);
    void func_800EEBF0(f32 *, f32 *, f32);
    void *func_80100094(Actor *, u32);
    typedef struct {
        f32 values[3];
        f32 padC;
        f32 rotation[3];
    } DragonData;
    typedef struct {
        u32 pad : 21;
        u32 flag : 1;
        u32 rest : 10;
    } MarkerFlags;
    Actor *sp2C;
    struct {
        s32 unk0;
        f32 frame;
        s32 unk8;
        s32 frameCount;
    } *sp28;
    struct {
        u8 pad[0x60];
        s8 count;
    } *sp24;

    sp28 = func_80100094(arg0, 0);
    func_800EEBF0(((DragonData *)arg0->actorData)->rotation, arg0->rotation, 2500.0f);
    arg0->unk58 = 0.5f;
    func_8010A590(arg0);
    ((MarkerFlags *)&arg0->unk0->unk28)->flag = 1;
    sp2C = _subaddiefind_entrypoint_2(0x377, 0);
    sp24 = func_80100094(sp2C, 0);
    arg0->unk3C = sp2C->unk0;
    if (func_800EA05C() == 0x12B) {
        arg0->unk7A_8 = 0;
    } else {
        arg0->unk7A_8 = 1;
    }
    arg0->unk0->unk14 = ((s16 *)D_808058F0_chdragonbrothers)[arg0->unk79_4];
    ((DragonData *)arg0->actorData)->values[0] = func_800DC178(50.0f, 100.0f);
    ((DragonData *)arg0->actorData)->values[1] = func_800DC178(5.0f, 10.0f);
    ((DragonData *)arg0->actorData)->values[2] = func_800DC178(5.0f, 10.0f);
    sp28->frame = 0.0f;
    sp28->frameCount = func_800AF5A0(func_800EC3E8((u8 *)arg0->unk0));
    arg0->unk64_20 = 1;
    arg0->scale = 1.5f;
    sp24->count++;
}

/* extern */

void func_80804610_chdragonbrothers(Actor *arg0) {
    f32 func_800D8FF8(void);
    f32 func_800F13C4(f32, f32);
    void *func_80100094(Actor *, u32);
    struct {
        s32 unk0;
        f32 frame;
        s32 unk8;
        s32 frameCount;
    } *sp1C;
    struct {
        u8 unk0[10];
        u8 frame : 5;
        u8 unkA_5 : 3;
    } *temp_v0;
    f32 temp_f0;

    sp1C = func_80100094(arg0, 0);
    temp_f0 = func_800F13C4((func_800D8FF8() * 30.0f) + sp1C->frame, (f32) sp1C->frameCount);
    sp1C->frame = temp_f0;
    temp_v0 = (void *)arg0->unk0->unk0;
    temp_v0->frame = (s32) temp_f0 % sp1C->frameCount;
}

void func_808046CC_chdragonbrothers(Actor *arg0) {
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    s16 *_fxegg_entrypoint_1(f32 *, f32);
    s16 *_fxegg_entrypoint_2(f32 *, f32);
    s32 _fxegg_entrypoint_3(f32 *, f32);
    s16 *_fxegg_entrypoint_5(f32 *, f32 *, f32);
    s16 *_fxegg_entrypoint_6(f32 *, f32, f32 *);
    s32 func_8001210C(s32);
    void func_800BA5A8(s16 *, s32);
    f32 func_800D8FF8(void);
    f32 func_800DC0C0(void);
    void func_800EFA20(void *, void *, f32);
    void *func_80100094(Actor *, u32);
    s16 *emitter;
    f32 sp70[3];
    f32 interval;
    struct {
        f32 unk0;
        f32 unk4;
        f32 unk8;
        f32 unkC;
        f32 timer;
    } *data;
    f32 sp5C[3];

    data = func_80100094(arg0, 0);
    data->timer -= func_800D8FF8();
    interval = func_800F10B4(data->unk8, 0, 2.0f, 0.0333f, 0.1f);
    while (data->timer <= 0.0f) {
        emitter = NULL;
        data->timer += interval;
        func_800EE7F8(sp70, arg0->position);
        switch (arg0->unk79_4) {
            case 1:
            case 3:
            case 5:
                if (func_800DC0C0() < 0.5f) {
                    emitter = _fxegg_entrypoint_2(sp70, arg0->scale);
                } else {
                    emitter = _fxegg_entrypoint_1(sp70, arg0->scale);
                }
                break;
            case 7:
                func_800EFA20(sp5C, &arg0->actorData[4], 0.5f);
                emitter = _fxegg_entrypoint_6(arg0->position, arg0->scale, sp5C);
                break;
            case 4:
                emitter = _fxegg_entrypoint_5(arg0->position, (f32 *)&arg0->actorData[4], arg0->scale);
                break;
        }
        if (emitter != NULL) {
            func_800BA5A8(emitter, 0x200);
        }
    }
    if (arg0->unk79_4 == 2 && func_8001210C(1) == 0) {
        _fxegg_entrypoint_3(arg0->position, arg0->scale);
    }
}

void func_808048A4_chdragonbrothers(s32 arg0) 
{
}
s32 func_808048AC_chdragonbrothers(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 _subaddiecustomhits_entrypoint_2(Unk80132ED0 *, f32 *, f32, f32 *, s32);
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    s32 func_8010114C(s32, s32, s32);
    Actor *func_80106790(Unk80132ED0 *);
    void func_808049D4_chdragonbrothers(Actor *);
    f32 sp44[3];
    f32 sp38[3];
    Actor *sp34;
    struct {
        u8 pad0[8];
        s8 counts[88];
        s8 count;
    } *sp30;
    if (_subaddiecustomhits_entrypoint_2(arg0->unk3C, arg0->position, 90.0f, sp44, 0)) {
        sp34 = func_80106790(arg0->unk3C);
        sp30 = func_80100094(sp34, 0);
        func_800EE780(sp38, arg0->position, (f32 *)&arg0->actorData[4]);
        func_808049D4_chdragonbrothers(arg0);
        arg0->unk64_20 = 0;
        sp30->count = sp30->count - 1;
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &(*(s32 *)D_80805900_chdragonbrothers));
        func_800FFAB0(arg0);
        switch (sp34->unk70_10) {
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
            func_8010114C(arg0->unk3C, 0x54, arg0->unk0);
            break;
        default:
            if (sp30->counts[arg0->unk74_7] > 0) {
                sp30->counts[arg0->unk74_7] = sp30->counts[arg0->unk74_7] - 1;
            }
            break;
        }
        return 1;
    }
    return 0;
}

void func_808049D4_chdragonbrothers(Actor *arg0) {
    s32 _fxegg_entrypoint_0(u32, f32 *, f32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    s32 func_8010D930(s32, s32, f32 *, s32 *);
    switch (arg0->unk79_4) {
    case 4:
        func_800BABB8(0, arg0->position, NULL, arg0->scale, &(*(s32 *)D_80805918_chdragonbrothers));
        func_800BABB8(0, arg0->position, NULL, arg0->scale, &(*(s32 *)D_80805960_chdragonbrothers));
        func_800BABB8(0, arg0->position, NULL, arg0->scale, &(*(s32 *)D_808059A8_chdragonbrothers));
        func_8010D930(6, -1, arg0->position, &(*(s32 *)D_808059D8_chdragonbrothers));
        break;
    default:
        _fxegg_entrypoint_0(arg0->unk79_4, arg0->position, arg0->scale);
        break;
    }
}

void func_80804AA4_chdragonbrothers(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    void _subaddiefade_entrypoint_3(Actor *);
    void *func_800C6A7C(f32 *, f32 *, f32 *, u32);
    f32 func_800D8FF8(void);
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EFA20(void *, void *, f32);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    struct { f32 unk0; f32 unk4; f32 timer; } *data;
    f32 dt;
    s32 pad;
    f32 step[3];
    f32 position[3];
    f32 normal[3];
    struct { u8 pad[0x60]; s8 count; } *parent;

    data = func_80100094(arg0, 0);
    dt = func_800D8FF8();
    data->timer += dt;
    if (arg0->unk70_10 == 1 && (arg0->unk58 > 0.0f || !func_808048AC_chdragonbrothers(arg0))) {
        func_800EE7F8((f32 *)arg0->actorData, arg0->position);
        func_800EFA20(step, &arg0->actorData[4], dt);
        func_800EE780(position, arg0->position, step);
        ((f32 *)arg0->actorData)[5] -= 25.0f;
        if (arg0->unk58 > 0.0f) {
            arg0->unk58 -= dt;
        } else if (func_800C6A7C(arg0->position, position, normal, 0x20020)) {
            func_808049D4_chdragonbrothers(arg0);
            func_800FFAB0(arg0);
        }
        func_800EE7F8(arg0->position, position);
        func_800EFA20(position, (f32 *)arg0->actorData, dt);
        func_800EF04C(arg0->rotation, (f32 *)arg0->actorData);
        func_80804610_chdragonbrothers(arg0);
        func_808046CC_chdragonbrothers(arg0);
        if (arg0->unk79_4 == 2) {
            _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, &(*(u32 *)D_808059EC_chdragonbrothers));
        }
        if (arg0->position[1] < -1000.0f) {
            parent = func_80100094(func_80106790(arg0->unk3C), 0);
            arg0->unk64_20 = 0;
            parent->count--;
            _subaddiefade_entrypoint_3(arg0);
        }
    }
}

s32 func_80804C6C_chdragonbrothers(s32 arg0, s32 arg1, s32 arg2) {
    if (arg1 != 0xF) {
        return 0;
    }
    return 1;
}

/* extern */

void func_80804C90_chdragonbrothers(s32 arg0, s32 arg1) {
    s32 _subaddiedraw25d_entrypoint_2(s32, s32);
    s32 func_800E24D8(s32);
    func_800E24D8(1);
    _subaddiedraw25d_entrypoint_2(arg0, arg1);
}

OSThread *chdragonbrothers_entrypoint_3(void)
{
    return (OSThread *) ((u8 *)D_80805A08_chdragonbrothers);
}

/* extern */

void func_80804CD0_chdragonbrothers(Actor *arg0) {
    Actor *_subaddiefind_entrypoint_2(s32, s32);
    s32 func_800DA298(s32);
    s32 func_800EA05C();
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_80103110(void *, s32);

    func_800EFA4C(arg0->position, 0.0f, -500.0f, 3150.0f);
    arg0->rotation[2] = 180.0f;
    arg0->scale = 1.68f;
    if (func_800EA05C() == 0x12B) {
        arg0->unk7A_8 = 0;
    } else {
        arg0->unk7A_8 = 1;
    }
    if ((arg0->unk7A_8 && !func_800DA298(0x1D5)) ||
        (!arg0->unk7A_8 && !func_800DA298(0x1D6))) {
        arg0->unk3C = _subaddiefind_entrypoint_2(0x377, 0)->unk0;
        func_80103110(arg0, 1);
    }
}

void func_80804DB0_chdragonbrothers(s32 arg0) 
{
}
void func_80804DB8_chdragonbrothers(Actor *arg0, u32 arg1) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_80101FDC(Actor *, u32);
    Actor **actor = &arg0;
    switch (arg0->unk70_10) {
        case 1:
            break;
        case 2:
        case 4:
            _subaddieaudioquick_entrypoint_2(*actor, ((f32 *)D_80805A50_chdragonbrothers), &(*(s32 *)D_80805488_chdragonbrothers));
            break;
    }
    func_80101FDC(*actor, arg1);
}

void func_80804E1C_chdragonbrothers(Actor *arg0) {
    f32 func_800D8FF8(void);
    Actor *func_80106790(Unk80132ED0 *);
    void *func_80100094(Actor *, u32);
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    s32 pad;
    u8 *data;
    f32 dt;

    dt = func_800D8FF8();
    if (arg0->unk3C != NULL) {
        data = func_80100094(func_80106790(arg0->unk3C), 0);
        switch (arg0->unk70_10) {
        case 1:
            if (data[0x58] == 1U) {
                func_80804DB8_chdragonbrothers(arg0, 2);
            }
            break;
        case 2:
            if (arg0->position[1] > -500.0f) {
                arg0->position[1] -= 150.0f * dt;
                _subaddieaudioloop_entrypoint_4(arg0, ((f32 *)D_80805A50_chdragonbrothers), 1, &(*(u32 *)D_808053A0_chdragonbrothers));
            } else {
                func_80804DB8_chdragonbrothers(arg0, 3);
                data[0x58] = 0;
            }
            break;
        case 3:
            if (data[0x58] == 3U) {
                func_80804DB8_chdragonbrothers(arg0, 4);
            }
            break;
        case 4:
            if (arg0->position[1] < -200.0f) {
                arg0->position[1] += 150.0f * dt;
                _subaddieaudioloop_entrypoint_4(arg0, ((f32 *)D_80805A50_chdragonbrothers), 1, &(*(u32 *)D_808053A0_chdragonbrothers));
            } else {
                func_80804DB8_chdragonbrothers(arg0, 1);
                data[0x58] = 2;
            }
            break;
        }
    }
}

OSThread *chdragonbrothers_entrypoint_4(void)
{
    return (OSThread *) ((u8 *)D_80805A5C_chdragonbrothers);
}
