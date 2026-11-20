#include "common.h"

OSThread *chdinofoot_entrypoint_0(void)
{
    extern ActorData D_80800818_chdinofoot[];

    return (OSThread *) D_80800818_chdinofoot;
}                typedef struct { u8 pad0[0x38]; f32 unk38; u8 pad3C[0x1C]; f32 unk58; } Objfoot_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void func_8080000C_chdinofoot(void *arg0) {
    s32 _glcutDll_entrypoint_20();
    void _subaddiefade_entrypoint_12(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
    void func_80102424(Actor *, s32);
    void func_80102FDC(void *arg0, f32 arg1);
    if (_glcutDll_entrypoint_20() != 0) {
        func_80102424(arg0, 5);
        (((Objfoot_arg0 *)arg0)->unk58) = 1.4f;
    }
    _subaddiefade_entrypoint_12(arg0, 0x60, 0x80, 0x60);
    func_80102FDC(arg0, (((Objfoot_arg0 *)arg0)->unk38) * 4.0f);
}

void func_80800084_chdinofoot(Actor *arg0) {
    void _chbadshad_entrypoint_1(void *arg0, void *arg1, f32 arg2);
    void _chintrotext_entrypoint_1(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    void _subaddiefade_entrypoint_1(void *arg0, s32 arg1);
    s32 func_800D9078(f32 *);
    s32 func_800D90A4(f32 *);
    f32 func_800F3780(f32, u8 *, s16);
    u32 func_800F54E4(void);
    s32 func_800F6438(BtUIntPtr);
    s32 func_80101DDC(Actor *);
    s32 func_80101E14(Actor *, f32);
    f32 func_80101F24(Actor *);
    void func_80102424(Actor *, s32);
    void func_8010A570(Actor *);
    void func_8010A590(Actor *);
    void func_8010D09C(BtIntPtr, f32 *, f32);
    s32 func_80800480_chdinofoot(Actor *);
    s32 func_8080055C_chdinofoot(void *);
    s32 func_808006BC_chdinofoot(Actor *);
    extern u8 D_80800860_chdinofoot[];

    if (func_800F6438(func_800F54E4()) != 0) {
        func_8010D09C(func_800F54E4(), (f32 *)arg0->actorData, 0.79998779296875f);
        ((f32 *)arg0->actorData)[1] = arg0->position[1];
    }
    switch (arg0->unk70_10) {
    case 1:
        if (func_80800480_chdinofoot(arg0) == 0 && !arg0->unk64_20 && func_800D90A4(&arg0->unk58) != 0) {
            func_80102424(arg0, 3);
        }
        break;
    case 2:
        if (func_800D90A4(&arg0->unk58) != 0) {
            _chintrotext_entrypoint_1(0x18B9, 7, 1, 0);
            func_80102424(arg0, 4);
            func_8010A590(arg0);
        }
        break;
    case 3:
        if (arg0->unk64_20 || func_8080055C_chdinofoot(arg0) != 0) {
            func_80102424(arg0, 4);
            func_8010A590(arg0);
        }
        break;
    case 4:
        func_808006BC_chdinofoot(arg0);
        if (func_80101E14(arg0, 0.6f) != 0) {
            func_8010A570(arg0);
        }
        if (func_80101DDC(arg0) != 0) {
            func_80102424(arg0, 1);
            arg0->unk58 = 1.399993896f;
        }
        break;
    case 5:
        if (func_800D9078(&arg0->unk58) != 0) {
            func_80102424(arg0, 6);
        }
        break;
    case 6:
        func_808006BC_chdinofoot(arg0);
        if (func_80101DDC(arg0) != 0) {
            func_80102424(arg0, 5);
            arg0->unk58 = 1.4f;
        }
        break;
    }
    _subaddiefade_entrypoint_1((BtIntPtr)arg0, (s32)(func_800F3780(func_80101F24(arg0), D_80800860_chdinofoot, 4) * 255.0f));
    _chbadshad_entrypoint_1(arg0, arg0->position, 8.5f);
}

/* extern */

s32 func_808002A8_chdinofoot(Actor *arg0, s32 arg1, Unk80132ED0 *arg2) {
    u32 func_800FDC28(u32);
    void func_8080035C_chdinofoot(Actor *, Unk80132ED0 *);
    Unk80132ED0 **data = &arg2;
    s32 result;
    switch (arg1) {
        case 0x3F:
            func_8080035C_chdinofoot(arg0, *data);
            return 1;
        case 0xB:
            arg0->unk64_20 = 0;
            func_800FDC28(0);
            result = 3;
            break;
        default:
            return 0;
    }
    return result;
}

/* extern */

void func_80800310_chdinofoot(BtIntPtr arg0, BtIntPtr arg1) {
    s32 _subaddiefade_entrypoint_0();
    void _subaddiefade_entrypoint_1(void *arg0, s32 arg1);
    void func_80101870(Actor* arg0, void* arg1);
    s32 sp1C;

    sp1C = _subaddiefade_entrypoint_0(BT_NATIVE_ONLY((void *)arg0));
    _subaddiefade_entrypoint_1(arg0, 0xFF);
    func_80101870(arg0, arg1);
    _subaddiefade_entrypoint_1(arg0, sp1C);
}

/* extern */

void func_8080035C_chdinofoot(Actor *arg0, Unk80132ED0 *arg1) {
    u32 func_800F54E4(void);
    s32 func_800F79DC(BtIntPtr, s32, BtIntPtr);
    void func_800F7B9C(BtIntPtr arg0,u32 a1);
    f32 func_80101F24(Actor *);
    void func_8010A570(Actor *);
    if ((arg1->unk24 >> 22) == 0) {
        if ((arg0->unk70_10 == 4) && (func_80101F24(arg0) < 0.4f)) {
            func_800F7B9C(func_800F54E4(), 0x5A);
            func_8010A570(arg0);
            return;
        }
        func_800F79DC(func_800F54E4(), 0xA, arg0->unk0);
        func_8010A570(arg0);
    }
}

s32 func_80800408_chdinofoot(s32 arg0) {
    s32 func_8010D248(void);
    void func_8010D254(f32 *);
    f32 position[3];

    if (func_8010D248() == 0) {
        return 0;
    }
    func_8010D254(position);
    if ((position[2] > 3500.0f) || (position[2] < -4000.0f)) {
        return 0;
    }
    return 1;
}

s32 func_80800480_chdinofoot(Actor *arg0) {
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    s32 func_800DA298(s32);
    void func_800DA544(s32 index);
    u32 func_800F54E4(void);
    void func_800F5A00(BtIntPtr, f32 *);
    s32 func_800F6438(BtUIntPtr);
    s32 func_800F6478(BtIntPtr);
    u32 func_800FDC28(u32);
    void func_80102424(Actor *, s32);
    BtUIntPtr player;
    f32 position[3];

    player = func_800F54E4();
    if ((func_800F6438(player) == 0) || (func_800F6478(player) == 0)) {
        return 1;
    }
    if (func_800DA298(0xC5) == 0) {
        func_800F5A00(player, position);
        if (position[2] < 4500.0f) {
            func_800DA544(0xC5);
            arg0->unk64_20 = 1;
            func_80102424(arg0, 2);
            arg0->unk58 = 21.5f;
            _capod_entrypoint_13(arg0->unk0, NULL, 1, 0x10);
            func_800FDC28(1);
        }
        return 1;
    }
    return 0;
}

/* extern */

s32 func_8080055C_chdinofoot(void *arg0) {
    f32 func_800136E4(f32);
    f32 func_8010CD28(void *);
    s32 func_80800408_chdinofoot();
#ifdef BT_NATIVE
    if (((s32 (*)())func_80800408_chdinofoot)() != 0) {
#else
    if (func_80800408_chdinofoot() != 0) {
#endif
        (((Actor *)arg0)->position[0]) = (f32) (*(f32 *)((s8 *)(arg0) + (0x18)));
        (((Actor *)arg0)->position[2]) = (f32) (*(f32 *)((s8 *)(arg0) + (0x20)));
        (((Actor *)arg0)->rotation[1]) = func_800136E4(func_8010CD28(arg0) + 180.0f);
        return 1;
    }
    return 0;
}

void func_808005C4_chdinofoot(Actor *arg0) {
    s32 _glcutDll_entrypoint_20();
    f32 func_800D8FF8(void);
    f32 func_800EEB40(f32 *, f32 *);
    void func_800EF368(f32 *, f32);
    void func_800EFB24(void *, void *, void *);
    void func_800EFE50(f32 *, f32 *, f32 *, f32);
    u32 func_800F54E4(void);
    void func_800F5A00(BtIntPtr, f32 *);
    f32 difference[3];
    f32 player[3];
    f32 destination[3];

    if (!arg0->unk64_20 && _glcutDll_entrypoint_20() == 0) {
        func_800F5A00(func_800F54E4(), player);
        player[1] = -200.0f;
        func_800EFE50(destination, (f32 *)arg0->actorData, player, 0.5f);
        if (func_800EEB40(arg0->position, destination) > 10000.0f) {
            func_800EFB24(difference, destination, arg0->position);
            func_800EF368(difference, func_800D8FF8() * 500.0f);
            arg0->position[0] += difference[0];
            arg0->position[2] += difference[2];
        }
    }
}

s32 func_808006BC_chdinofoot(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 _subaddieaudioquick_entrypoint_3(Actor *arg0, f32 arg1[3], void *arg2, f32 arg3);
    void func_80018820(s32, f32, f32);
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    s32 func_800E15CC(s32, f32, f32);
    s32 func_80101E14(Actor *, f32);
    f32 func_80101F24(Actor *);
    void func_808005C4_chdinofoot(Actor *);
    extern u32 D_80800880_chdinofoot[4];
    extern s32 D_80800890_chdinofoot[4];
    extern s32 D_808008A0_chdinofoot[20];
    f32 *temp_s1;

    temp_s1 = arg0->position;
    _subaddieaudioquick_entrypoint_3(arg0, temp_s1, D_80800880_chdinofoot, 0.0f);
    if (func_80101F24(arg0) < 0.4f) {
        func_808005C4_chdinofoot(arg0);
    }
    if (func_80101E14(arg0, 0.4f) != 0) {
        _subaddieaudioquick_entrypoint_2(arg0, temp_s1, D_80800890_chdinofoot);
        func_800BBCB8(temp_s1, temp_s1, 1.0f, 6, D_808008A0_chdinofoot);
        func_800E15CC(0, 40.0f, 0.8f);
        func_80018820(0, 3.0f, 0.25f);
        return 1;
    }
    return 0;
}
/* data_to_c.py: from asm/data/overlays/ch/dino/foot.data.s */
extern u8 D_808007E0_chdinofoot[];
void func_80105834(Actor*);
OSThread *func_80108ED0(void);
void func_80107C2C();
u8 D_808007E0_chdinofoot[56] BT_DATA(4, overlays_ch_dino_foot, 0x0) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x97, 0x6C, 0x8B, 0x01, 0x6A, 0x00, 0x44, 0x3F, 0x97, 0x6C, 0x8B, 0x01, 0x6A, 0x00, 0x44, 0x3F, 0x97, 0x6C, 0x8B, 0x01, 0x6A, 0x00, 0x44, 0x3F, 0x97, 0x6C, 0x8B, 0x01, 0x6A, 0x00, 0x02, 0x3F, 0x97, 0x6C, 0x8B, 0x01, 0x6A, 0x00, 0x44, 0x3F, 0x97, 0x6C, 0x8B, 0x01, 0x6A, 0x00, 0x02 };
ActorData D_80800818_chdinofoot [1] BT_DATA(4, overlays_ch_dino_foot, 0x38) = { { 757, 866, 1747, 1, (void *)D_808007E0_chdinofoot, (void (*)(struct Actor *))func_80800084_chdinofoot, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80800310_chdinofoot, 0, 0, 0, 0, 0, 1056, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_8080000C_chdinofoot, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32640, 1168, (void (*)(struct Actor *, long, long))func_808002A8_chdinofoot, 0 } };
u8 D_80800860_chdinofoot [32] BT_DATA(4, overlays_ch_dino_foot, 0x80) = { 0, 0, 0, 0, 0, 0, 0, 0, 0x3E, 0x4C, 0xCC, 0xCD, 0x3F, 0x80, 0, 0, 0x3F, 0x66, 0x66, 0x66, 0x3F, 0x80, 0, 0, 0x3F, 0x80, 0, 0, 0, 0, 0, 0 };
u32 D_80800880_chdinofoot[4] BT_DATA(4, overlays_ch_dino_foot, 0xA0) = { 0x13054E, 0x18000D, 0xC000D9, 0x20000 };
s32 D_80800890_chdinofoot[4] BT_DATA(4, overlays_ch_dino_foot, 0xB0) = { 1246574, 1572877, 10027212, 131072 };
s32 D_808008A0_chdinofoot[20] BT_DATA(4, overlays_ch_dino_foot, 0xC0) = { 1903069, 2818560, 41943074, 50332672, 100665344, 1376281, 10027033, 7, 2621340, -6553500, 6553645, 13107500, 2082966, 1677721611, 13107600, 6553650, 0, 0, 0, 0 };
