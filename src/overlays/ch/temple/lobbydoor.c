#include "common.h"

void func_808000B4_chtemplelobbydoor(s32);
void func_808000BC_chtemplelobbydoor(s32);
void func_808000E4_chtemplelobbydoor();
void func_8080000C_chtemplelobbydoor(BtIntPtr);
s32 func_80800248_chtemplelobbydoor(Actor *, s32, s32);
void func_80101870(Actor *, void *);
void func_80105834(Actor *);
void *func_80107C2C(s32 *, s32, void *, s32, void *);

BtFnWord D_808003A0_chtemplelobbydoor[] = {
    0x00AC02B5, 0x08490004, 0x00000000, (BtFnWord)func_808000BC_chtemplelobbydoor,
    (BtFnWord)func_80105834, (BtFnWord)func_80101870, 0x00000000, 0x00000000,
    0x00000000, 0x00020800, (BtFnWord)func_808000B4_chtemplelobbydoor, 0x00000000,
    0x00000000, (BtFnWord)func_8080000C_chtemplelobbydoor, (BtFnWord)func_80107C2C, 0x80002402,
    (BtFnWord)func_80800248_chtemplelobbydoor, 0x00000000,
};

s32 D_808003E8_chtemplelobbydoor = 0x190;

s16 D_808003EC_chtemplelobbydoor[] = {
    0x0F37, 0x0F38, 0x0000, 0x0101, 0x120A, 0x0000, 0x00B2, 0x0000,
    0x000A, 0x4000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000,
};

OSThread *chtemplelobbydoor_entrypoint_0(void)
{
    return (OSThread *) D_808003A0_chtemplelobbydoor;
}

/* extern */

void func_8080000C_chtemplelobbydoor(BtIntPtr arg0) {
    s32 _chdoormake_entrypoint_3(BtIntPtr, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_5(Actor *arg0, f32 arg1);
    void _chdoormake_entrypoint_8(Actor *arg0, u32 arg1);
    s32 func_800D035C(s32);
    s32 func_800EA090();
    s32 func_800F5410(BtIntPtr);
    void func_80101FDC(Actor *actor,u32 state);
    s32 sp24;
    s32 temp_t8;

    if ((func_800EA090() == 1) && ((sp24 = func_800D035C(5) < 0x14, temp_t8 = func_800F5410(0) ^ 1, (sp24 != 0)) || (temp_t8 != 0))) {
        func_80101FDC(arg0, 1);
    }
    if (_chdoormake_entrypoint_3(arg0, 0.0f, 90.0f, 180.0f, 8, -1) != 0) {
        _chdoormake_entrypoint_5(arg0, 1.5f);
        _chdoormake_entrypoint_8(arg0, 5);
    }
}

void func_808000B4_chtemplelobbydoor(s32 arg0) 
{
}
void func_808000BC_chtemplelobbydoor(s32 arg0)
{
    func_808000E4_chtemplelobbydoor();
    _chdoor_entrypoint_0(arg0);
}

void func_808000E4_chtemplelobbydoor(s32 arg0) {
    int func_800C6E38(s32);
    s32 _subaddiedialog_entrypoint_7(BtIntPtr, BtIntPtr, s32 *);
    s32 i;

    if (func_800C6E38(0x15)) {
        for (i = 0; i < 1; i = 1) {
            D_808003EC_chtemplelobbydoor[i] = 0xF39;
            D_808003EC_chtemplelobbydoor[i + 1] = 0xF39;
        }
    }
    _subaddiedialog_entrypoint_7(arg0, arg0 + 4, &D_808003E8_chtemplelobbydoor);
}

void func_80800134_chtemplelobbydoor(Actor *arg0, s32 arg1) {
    void _bsfirstp_entrypoint_18(s32 arg0, s32 arg1);
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    u32 func_8009E958(void);
    int func_800C6E38(s32);
    void func_800C9CD0(f32, BtIntPtr, s32, s32, f32 *, s16);
    s32 func_800DA298(s32);
    s32 func_800DA9E4(s32, s32);
    s32 func_800EA090(void);
    void func_800F49D4(BtIntPtr, void *, BtIntPtr);
    u32 func_800F54E4(void);
    void *func_80100094(Actor *, u32);
    s8 *sp24;

    sp24 = func_80100094(arg0, 0);
    *sp24 = 0;
    switch (func_800EA090()) {
        case 1:
            if (func_800C6E38(0x15) && func_8009E958() == 1 && !func_800DA9E4(0x6B8, 1)) {
                *sp24 = 1;
                _capod_entrypoint_13(arg0->unk0, NULL, 3, 0x2020);
                func_800F49D4(func_800F54E4(), _bsfirstp_entrypoint_18, 0);
            }
            break;
        case 2:
            if (!func_800DA298(0x36F)) {
                func_800C9CD0(0.8f, arg0->unk0, 0xF50, 2, NULL, 0xB2);
                _capod_entrypoint_13(arg0->unk0, NULL, 1, 0x2020);
            }
            break;
    }
}

s32 func_80800248_chtemplelobbydoor(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _capod_entrypoint_14(void);
    s32 _chdoor_entrypoint_1(Actor *, s32, BtIntPtr);
    u32 func_800F54E4(void);
    void func_800F7B9C(BtIntPtr arg0,u32 a1);
    s32 func_800F7F98(BtIntPtr, u32);
    void *func_80100094(Actor *, u32);
    s32 func_8010108C(Actor *, s32, BtIntPtr);
    u8 *data;
    s32 value;

    data = func_80100094(arg0, 0);
    switch (arg1) {
        case 0x49:
            func_80800134_chtemplelobbydoor(arg0, arg2);
            return 1;
        case 0x2E:
            switch (*(s16 *)&arg2) {
                case 0xF39:
                    func_8010108C(arg0, 7, 0);
                    return 1;
                case 0xF50:
                    func_800F7B9C(func_800F54E4(), 0x73);
                    func_800F7F98(func_800F54E4(), 0);
                    _capod_entrypoint_14();
                    func_800F7B9C(func_800F54E4(), 0x99);
                    return 1;
            }
        case 0x77:
            if (*data == 1) {
                value = arg2;
                *data = 0;
                func_800F7B9C(value, 0x73);
                _capod_entrypoint_14();
                func_800F7B9C(func_800F54E4(), 0x99);
                return 1;
            }
    }
    return _chdoor_entrypoint_1(arg0, arg1, arg2);
}
