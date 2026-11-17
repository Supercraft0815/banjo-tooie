#include "common.h"

OSThread *chchompaslunch_entrypoint_0(void)
{
    extern ActorData D_808003E0_chchompaslunch[];

    return (OSThread *) D_808003E0_chchompaslunch;
}

void func_8080000C_chchompaslunch(Actor *arg0) {
    if (_glcutDll_entrypoint_20() == 0) {
        func_800FFAB0(arg0);
    }
    arg0->unk58 = 8.0f;
    arg0->unk6C_0 = func_800DC128(0, 3);
}

void func_80800070_chchompaslunch(Actor *arg0) {
    s32 func_800D9078(f32 *);
    s32 func_80101DDC(Actor *);
    void func_80102424(Actor *, s32);
    s32 func_80105230();
    void func_80800250_chchompaslunch(Actor *);
    void func_8080037C_chchompaslunch(Actor *);

    switch (arg0->unk70_10) {
        case 1:
            func_80800250_chchompaslunch(arg0);
            if (func_800D9078(&arg0->unk58) != 0) {
                func_80102424(arg0, 2);
            }
            break;
        case 2:
            func_8080037C_chchompaslunch(arg0);
            if (func_80101DDC(arg0) != 0) {
                func_80102424(arg0, 3);
            }
            break;
        case 3:
            func_80105230(arg0, 0);
            break;
    }
}

s32 func_80800118_chchompaslunch(Actor *arg0, s32 arg1, s32 arg2) {
    void func_8080017C_chchompaslunch(Actor *);
    s32 *data = &arg2;
    switch (arg1) {
        case 0x1F:
            func_8080017C_chchompaslunch(arg0);
            break;
        case 0xBC:
            func_800FFAB0(arg0);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_8080017C_chchompaslunch(Actor *arg0) {
    void func_800DF744(s32, s32);
    s32 func_801015D0(Actor *);
    extern s16 D_80800428_chchompaslunch[][6];



    func_801015D0(arg0);
    func_800DF744(4, D_80800428_chchompaslunch[arg0->unk6C_0][0]);
    func_800DF744(5, D_80800428_chchompaslunch[arg0->unk6C_0][1]);
    func_800DF744(6, D_80800428_chchompaslunch[arg0->unk6C_0][2]);
    func_800DF744(7, 0);
    func_800DF744(8, D_80800428_chchompaslunch[arg0->unk6C_0][3]);
}

void func_80800250_chchompaslunch(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_4(Actor *arg0, f32 *arg1, void *arg2, f32 *arg3);
    void func_800C301C(u8, s32);
    void func_800C3058(u8, s32);
    void func_800C31DC(u8, f32);
    void func_800C3BDC(u8);
    u8 func_800C4350(u8 index, f32 *position, s32 *command_list);
    f32 func_800DC178(f32, f32);
    s32 func_80101E14(Actor *, f32);
    extern u32 D_8080044C_chchompaslunch[3];
    extern u32 D_80800458_chchompaslunch[4];
    extern f32 D_80800468_chchompaslunch[];
    extern f32 D_80800478_chchompaslunch[];
    extern s16 D_80800488_chchompaslunch[];
    extern s16 D_80800490_chchompaslunch[];
    extern s32 D_80800498_chchompaslunch[3];
    s32 i;
    f32 *ptr;
    s32 offset;
    s32 result;

    if (arg0->unk5F == 0) {
        arg0->unk5F = func_800C4350(0, arg0->position, D_80800498_chchompaslunch);
    }
    ptr = D_80800468_chchompaslunch;
    i = 0;
    offset = 0;
    do {
    result = func_80101E14(arg0, *ptr);
    ptr++;
    if (result != 0) {
        func_800C301C(arg0->unk5F, D_80800488_chchompaslunch[i]);
        func_800C31DC(arg0->unk5F, *(f32 *)((u8 *)D_80800478_chchompaslunch + offset) + func_800DC178(-0.02f, 0.02f));
        func_800C3058(arg0->unk5F, D_80800490_chchompaslunch[i]);
        func_800C3BDC(arg0->unk5F);
        break;
    }
    i++;
    offset += 4;
    } while (i != 4);
    if (!arg0->unk6C_0) {
        _subaddieaudioquick_entrypoint_4(arg0, arg0->position, D_8080044C_chchompaslunch, D_80800458_chchompaslunch);
    }
}

void func_8080037C_chchompaslunch(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_3(Actor *arg0, f32 arg1[3], void *arg2, f32 arg3);
    extern u32 D_808004A4_chchompaslunch[7];
    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_808004A4_chchompaslunch, 0.0f);
}
/* data_to_c.py: from asm/data/overlays/ch/ompaslun.data.s */
extern u8 D_808003C0_chchompaslunch[];
void func_80102EC0();
void func_801018A4();
void func_80107C2C();
u8 D_808003C0_chchompaslunch[32] BT_DATA(4, overlays_ch_ompaslun, 0x0) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x80, 0x00, 0x00, 0x02, 0xEE, 0x00, 0x01, 0x3F, 0xB3, 0x33, 0x33, 0x02, 0xEF, 0x00, 0x02, 0x3F, 0x28, 0xF5, 0xC3, 0x02, 0xF0, 0x00, 0x01 };
ActorData D_808003E0_chchompaslunch [1] BT_DATA(4, overlays_ch_ompaslun, 0x20) = { { 344, 1281, 2030, 1, (void *)D_808003C0_chchompaslunch, (void (*)(struct Actor *))func_80800070_chchompaslunch, (void (*)(struct Actor *))func_80102EC0, (void (*)(long, long))func_801018A4, 0, 0, 0, 0, 0, 296, 0, 0, 0, 0, (void (*)(struct Actor *))func_8080000C_chchompaslunch, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1026, (void (*)(struct Actor *, long, long))func_80800118_chchompaslunch, 0 } };
s16 D_80800428_chchompaslunch [3] [ 6 ] BT_DATA(4, overlays_ch_ompaslun, 0x68) = { { 1, 1, 1, 3, 0, 0 }, { 2, 2, 2, 1, 0, 0 }, { 3, 2, 2, 2, 0, 0 } };
u32 D_8080044C_chchompaslunch[3] BT_DATA(4, overlays_ch_ompaslun, 0x8C) = { 0x130417, 0xD00C0, 0xD90000 };
u32 D_80800458_chchompaslunch[4] BT_DATA(4, overlays_ch_ompaslun, 0x98) = { 0x3F23D70A, 0x3F3AE148, 0x3F51EB85, 0xBF800000 };
f32 D_80800468_chchompaslunch [4] BT_DATA(4, overlays_ch_ompaslun, 0xA8) = { 0.0f, 0.23f, 0.32f, 0.42f };
f32 D_80800478_chchompaslunch [4] BT_DATA(4, overlays_ch_ompaslun, 0xB8) = { 0.9f, 1.1f, 1.05f, 1.0f };
s16 D_80800488_chchompaslunch [4] BT_DATA(4, overlays_ch_ompaslun, 0xC8) = { 1470, 1468, 1469, 1469 };
s16 D_80800490_chchompaslunch [4] BT_DATA(4, overlays_ch_ompaslun, 0xD0) = { 32000, 22000, 22000, 22000 };
s32 D_80800498_chchompaslunch[3] BT_DATA(4, overlays_ch_ompaslun, 0xD8) = { 50724865, 13110200, 458752 };
u32 D_808004A4_chchompaslunch[7] BT_DATA(4, overlays_ch_ompaslun, 0xE4) = { 0x1305B6, 0xD00F3, 0x10C0018, 0, 0, 0, 0 };
