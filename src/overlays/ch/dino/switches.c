#include "common.h"

struct SwitchEntry {
        u16 unk0;
        u16 flag;
        s32 unk4;
        u8 unk8[8];
        u16 map;
        u16 pad12;
    };

OSThread *chdinoswitches_entrypoint_0(void)
{
    extern u8 D_80800C30_chdinoswitches[];

    return (OSThread *) D_80800C30_chdinoswitches;
}

OSThread *chdinoswitches_entrypoint_1(void)
{
    extern u8 D_80800C78_chdinoswitches[];

    return (OSThread *) D_80800C78_chdinoswitches;
}

OSThread *chdinoswitches_entrypoint_2(void)
{
    extern u8 D_80800CC0_chdinoswitches[];

    return (OSThread *) D_80800CC0_chdinoswitches;
}

OSThread *chdinoswitches_entrypoint_3(void)
{
    extern u8 D_80800D08_chdinoswitches[];

    return (OSThread *) D_80800D08_chdinoswitches;
}

void func_80800030_chdinoswitches(Actor *arg0) {
    s32 _chswitch_entrypoint_7(Actor *, s32);
    void _chswitch_entrypoint_8(s32 *arg0, s32 arg1);
    void _chswitch_entrypoint_9(void *arg0);
    s32 func_800D0B68(u32, u32);
    s32 func_800DA298(s32);
    void func_800DA544(s32);
    void func_80103110(Actor *, u32);
    s32 func_80800108_chdinoswitches(u8 *arg0);
    extern struct SwitchEntry D_80800B20_chdinoswitches[];
    s32 sp24[1];
    struct SwitchEntry *sp20;

    arg0->actorData[0] = sp24[0] = func_80800108_chdinoswitches(arg0);
    if (arg0->actorData[0] == 4) {
        if (func_800DA298(0x676U) != 0 || func_800D0B68(0x18, 0) != 0) {
            func_800DA544(0xA10);
        }
    }
    sp20 = D_80800B20_chdinoswitches + sp24[0];
    _chswitch_entrypoint_7(arg0, sp20->flag);
    _chswitch_entrypoint_8(arg0, sp20->unk4);
    if (arg0->actorData[0] == 4) {
        if (func_800DA298(sp20->flag) != 0) {
            func_80103110(arg0, 0);
        }
    } else {
        _chswitch_entrypoint_9(arg0);
    }
}

s32 func_80800108_chdinoswitches(u8 *arg0) {
    s32 func_800EA05C(void);
    extern struct SwitchEntry D_80800B20_chdinoswitches[];
    s32 map;
    s32 index;

    map = func_800EA05C();
    for (index = 1; index < 12; index++) {
        if (map == D_80800B20_chdinoswitches[index].map && ((Actor *)arg0)->unk74_7 == D_80800B20_chdinoswitches[index].unk0) {
            return index;
        }
    }
    return 0;
}

void func_80800270_chdinoswitches(void *arg0) {
    s32 func_801032B0(Actor *actor,u16 id,u16 palette);
    extern u8 D_80800B28_chdinoswitches[];
    s32 index = *(s32 *)((u8 *)arg0 + 0x18);

    func_801032B0(arg0, *(u16 *)(D_80800B28_chdinoswitches + index * 0x14),
                  *(u16 *)((u8 *)*(void **)arg0 + 0x16));
}

s32 func_808002B0_chdinoswitches(Actor *arg0, s32 arg1, s32 arg2) {
    typedef struct {
        u32 pad0[29];
        BT_BITFIELD_ORDER(u32 pad74_31 : 10, u32 pad74_0 : 21);
        u32 unk74_21 : 1;
        BT_BITFIELD_ORDER(u32 pad74_0 : 21, u32 pad74_31 : 10);
    } ActorFlags;
    s32 func_8010114C(BtIntPtr, s32, BtIntPtr);
    void func_80101074(void *);
    s32 _chswitch_entrypoint_10(BtIntPtr, s32, s32);
    s32 _subaddiefind_entrypoint_10(Actor *, s32, u32);
    s32 func_80800108_chdinoswitches(u8 *arg0);
    extern u8 D_80800B28_chdinoswitches[];
    extern u8 D_8011A270[];
    extern u8 D_8011A248[];
    s32 unused[2];
    Unk80132ED0 *sp1C;
    s32 index;
    s32 value;

    switch (arg1) {
    case 7:
        sp1C = arg0->unk3C;
        if (sp1C != NULL) {
            func_8010114C((BtIntPtr)sp1C, arg1, 0);
        }
        break;
    case 0x95:
        _subaddiefind_entrypoint_10(arg0, 0x364, arg0->unk74_7);
        func_80800270_chdinoswitches(arg0);
        return _chswitch_entrypoint_10((BtIntPtr)arg0, arg1, arg2);
    case 0x99:
        index = ((ActorFlags *)arg0)->unk74_21
                    ? arg0->actorData[0] : func_80800108_chdinoswitches(arg0);
        value = *(u16 *)(D_80800B28_chdinoswitches + index * 0x14);
        if (value == 0x7B8 || value == 0x7B9 || value == 0x942) {
            func_80101074(D_8011A270);
        } else {
            func_80101074(D_8011A248);
        }
        break;
    default:
        return _chswitch_entrypoint_10((BtIntPtr)arg0, arg1, arg2);
    }
    return 1;
}

s32 func_808003E8_chdinoswitches(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _chswitch_entrypoint_10(BtIntPtr, s32, s32);
    s32 _subaddiefind_entrypoint_10(Actor *, s32, u32);
    void func_800CE88C(s32, s32);
    void func_800CE8D8(s32, f32, s32);
    void func_800CE928(s32, BtIntPtr, BtIntPtr);
    s32 func_800CE95C();
    s32 func_800CEAA8(s32);
    s32 func_800D0B68(u32, u32);
    s32 func_800DA298(s32);
    s32 func_800F64A4(BtIntPtr, s32);
    void func_80101074(void *);
    s32 func_8010114C(BtIntPtr, s32, BtIntPtr);
    void func_80103110(Actor *, u32);
    void _chdinoswitches_entrypoint_4(s32, s32);
    extern u8 D_8011A248[];
    extern u16 D_80800B22_chdinoswitches[][10];
    BtIntPtr callback;
    Unk80132ED0 *temp;

    switch (arg1) {
    case 7:
        if (func_800D0B68(0x18, 0) == 0) {
            func_80103110(arg0, 0);
            func_8010114C((BtIntPtr)arg0->unk3C, 7, 0);
            func_800CE8D8(0, 35.0f, 0x23);
            func_800CE88C(0, 1);
            func_800CE928(0, (BtIntPtr)_chdinoswitches_entrypoint_4, 0);
        }
        break;
    case 0x91:
        if (func_800F64A4(arg2, 0x40000) != 0 &&
            func_800CEAA8(0) != 0 &&
            func_800CE95C(0) == (BtIntPtr)_chdinoswitches_entrypoint_4) {
            callback = (BtIntPtr)_chdinoswitches_entrypoint_4;
            func_800CE8D8(0, 35.0f, 0x23);
            func_800CE928(0, callback, 0);
        }
        return _chswitch_entrypoint_10((BtIntPtr)arg0, arg1, arg2);
    case 8:
        func_80103110(arg0, 1);
        break;
    case 0x99:
        func_80101074(D_8011A248);
        break;
    case 0xB7:
        if (!(arg2 & 0xFFFF) && ((arg2 >> 16) & 0xFFFF) == 0x18) {
            if (func_800CEAA8(0) != 0 &&
                func_800CE95C(0) == (BtIntPtr)_chdinoswitches_entrypoint_4) {
                func_800CE928(0, 0, 0);
                func_800CE88C(0, 0);
            }
            temp = arg0->unk3C;
            if (temp != NULL) {
                func_8010114C((BtIntPtr)temp, 7, 0);
            }
        }
        break;
    case 0x95:
        _subaddiefind_entrypoint_10(arg0, 0x364, arg0->unk74_7);
        _chswitch_entrypoint_10((BtIntPtr)arg0, arg1, arg2);
        if (func_800DA298(D_80800B22_chdinoswitches[arg0->actorData[0]][0]) != 0) {
            func_80103110(arg0, 0);
        }
        break;
    default:
        return _chswitch_entrypoint_10((BtIntPtr)arg0, arg1, arg2);
    }
    return 1;
}

/* extern */

void chdinoswitches_entrypoint_4(s32 arg0, s32 arg1) {
    void _glcutDll_entrypoint_6(u32, u32);
    Actor *_subaddiefind_entrypoint_11(s32, s32);
    s32 func_800DA298(s32);
    void func_800DA524(s32);
    s32 func_800EA05C();
    s32 func_8010108C();
    s32 func_80101180(s32, s32, BtIntPtr);
    void func_80103110(Actor *, u32);
    Actor *sp1C;
    Actor *sp18;

    if (func_800EA05C() == 0x112) {
        sp1C = _subaddiefind_entrypoint_11(0x364, 0x35);
        sp18 = _subaddiefind_entrypoint_11(0x433, 0x35);
        func_80101180(0x433, 8, 0);
        func_8010108C(sp1C, 8, 0);
        func_80103110(sp18, 1);
        return;
    }
    if (func_800DA298(0xA3A) == 0) {
        _glcutDll_entrypoint_6(0x112, 0x37);
        return;
    }
    func_800DA524(0xA10);
    func_800DA524(0x676);
}

void func_80800714_chdinoswitches(Actor *arg0) {
    s32 func_800DA298(s32);
    void func_80101EE4(Actor *, f32);
    void func_80102424(Actor *, s32);
    void func_80109EEC(s16 *, s32);
    void func_8010A570(Actor *);
    s32 func_80800108_chdinoswitches(u8 *arg0);
    extern u16 D_80800B22_chdinoswitches[][10];
    s32 temp_v0;

    temp_v0 = func_80800108_chdinoswitches(arg0);
    arg0->actorData[0] = temp_v0;
    if (func_800DA298(D_80800B22_chdinoswitches[temp_v0][0]) != 0) {
        func_80102424(arg0, 3);
        func_80101EE4(arg0, 0.3f);
        func_8010A570(arg0);
    }
    if (arg0->actorData[0] == 3) {
        func_80109EEC(arg0, 0x44);
    }
}

void func_808007A0_chdinoswitches(Actor *arg0) {
#ifndef BT_NATIVE
    void func_800DA544(GameFlag);
#endif
    s32 func_8010114C(BtIntPtr, s32, BtIntPtr);
    s32 func_80101E14(Actor *, f32);
    void func_80101EE4(Actor *, f32);
    void func_80102424(Actor *, s32);
    void func_80103110(Actor *, u32);
    extern u16 D_80800B22_chdinoswitches[][10];
    BtIntPtr temp_a0;

    if (arg0->unk70_10 == 2 && func_80101E14(arg0, 0.3f) != 0) {
        func_800DA544(D_80800B22_chdinoswitches[arg0->actorData[0]][0]);
        func_80102424(arg0, 3);
        func_80101EE4(arg0, 0.3f);
        func_80103110(arg0, 0);
        temp_a0 = (BtIntPtr)arg0->unk3C;
        if (temp_a0 != 0) {
            func_8010114C(temp_a0, 7, 0);
        }
    }
}

s32 func_80800848_chdinoswitches(Actor *arg0, s32 arg1, s32 arg2) {
    void _gcaudiolist_entrypoint_0(s32 arg0);
    s32 _subaddiefind_entrypoint_10(Actor *, s32, u32);
    void func_80102424(Actor *, s32);
    void func_8010A570(Actor *);
    void func_80103110(Actor *, u32);

    switch (arg1) {
        case 0x40:
            _gcaudiolist_entrypoint_0(0);
            func_80102424(arg0, 2);
            func_8010A570(arg0);
            func_80103110(arg0, 1);
            break;
        case 0x95:
            _subaddiefind_entrypoint_10(arg0, 0x364, arg0->unk74_7);
            func_80800270_chdinoswitches(arg0);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_808008F0_chdinoswitches(Actor *arg0) {
    s32 func_80800108_chdinoswitches(u8 *arg0);
    s32 func_800D0B68(u32, u32);
    void func_800DA544(s32);
    s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_5(Actor *, f32);
    void _chdoormake_entrypoint_8(void *, u32);
    s32 _chdoormake_entrypoint_9(Actor *, s32, s32, s32);
    s32 _chdoormake_entrypoint_12(Actor *, s32, s32);
    s32 _chdoormake_entrypoint_10(void *, s32, s32);
    void func_8010A800(Actor *, s32);
    struct DoorEntry {
        u16 unk0;
        u16 flag;
        s32 unk4;
        u16 unk8;
        s16 event;
        u16 unkC;
        u16 door;
        u16 unk10;
        u16 doorFlag;
    };
    struct DoorEntry *entry;
    extern u8 D_80800B28_chdinoswitches[];
    s32 index;

    entry = (struct DoorEntry *)(D_80800B28_chdinoswitches - 8);
    index = func_80800108_chdinoswitches(arg0);
    arg0->actorData[0] = index;
    entry += index;
    if (index == 4 && func_800D0B68(0x18, 0)) {
        func_800DA544(entry->doorFlag);
    }
    if (_chdoormake_entrypoint_3(arg0, 0.0f, 90.0f,
                               arg0->scale * 350.0f, entry->door, entry->doorFlag)) {
        _chdoormake_entrypoint_5(arg0, 2.75f);
        _chdoormake_entrypoint_8(arg0, 0xE);
        if (entry->event != -1) {
            _chdoormake_entrypoint_9(arg0, 0, entry->event, 0x10);
        }
    }
    switch (arg0->actorData[0]) {
        case 3:
            func_8010A800(arg0, 0);
            break;
        case 4:
            _chdoormake_entrypoint_9(arg0, 1, 0x23, 0x810);
            _chdoormake_entrypoint_12(arg0, 1, 0x37);
            _chdoormake_entrypoint_10(arg0, 1, 0xA3A);
            _chdoormake_entrypoint_10(arg0, 0, 0xA23);
            break;
    }
}

void func_80800A48_chdinoswitches(void *arg0) {
    s32 func_80103140(Actor *actor,u32 id,u16 palette);
    extern u8 D_80800B2C_chdinoswitches[];
    s32 index = *(s32 *)((u8 *)arg0 + 0x18);

    func_80103140(arg0, *(u16 *)(D_80800B2C_chdinoswitches + index * 0x14),
                  *(u16 *)((u8 *)*(void **)arg0 + 0x16));
}

s32 func_80800A88_chdinoswitches(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _chdoor_entrypoint_1(BtIntPtr, s32, BtIntPtr);
    void _glcutDll_entrypoint_17(void);
    s32 _glcutDll_entrypoint_19(s32);

    switch (arg1) {
        case 0xB:
            if (arg0->actorData[0] == 4 && arg2 == 0x23 && _glcutDll_entrypoint_19(0x37) != 0) {
                _glcutDll_entrypoint_17();
            }
            return 3;
        case 0x95:
            func_80800A48_chdinoswitches(arg0);
        default:
            return _chdoor_entrypoint_1((BtIntPtr)arg0, arg1, arg2);
    }
}
