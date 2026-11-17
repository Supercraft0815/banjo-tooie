#include "common.h"

OSThread *chtntdetonator_entrypoint_0(void)
{
    extern ActorData D_808006A8_chtntdetonator[];

    return (OSThread *) D_808006A8_chtntdetonator;
}

void func_8080000C_chtntdetonator(Actor *arg0 BT_PASS2(, s32 bt_a1) BT_PASS2(, s32 bt_a2) BT_PASS2(, s32 bt_a3)) {
    s32 _subaddiefade_entrypoint_14(BtIntPtr);
    void func_80102FDC(Actor*, f32);
    void func_8010A63C(Actor *arg0);
    func_80102FDC(arg0, arg0->scale * 0.5f);
    _subaddiefade_entrypoint_14((BtIntPtr) arg0);
    func_8010A63C((BtIntPtr) arg0);
}

void func_80800054_chtntdetonator(Actor *arg0) {
    f32 func_800D8FF8(void);
    void func_800FFAB0(Actor *);
    s32 func_8010108C(Actor *, s32, BtIntPtr);
    s32 func_80101DDC(Actor *);
    Actor *func_80106790(Unk80132ED0 *);
    void func_8080021C_chtntdetonator(Actor *);
    void func_808002D8_chtntdetonator(u8 *);
    void func_80800588_chtntdetonator(Actor *);
    Actor *other;
    Unk80132ED0 *marker;

    func_80800588_chtntdetonator(arg0);
    switch (arg0->unk70_10) {
        case 1:
            func_8080021C_chtntdetonator(arg0);
            break;
        case 2:
            arg0->unk50 += func_800D8FF8() * 40.0f;
            if (arg0->unk50 >= 14.0f) {
                arg0->unk50 = 0.0f;
            }
            if (func_80101DDC(arg0) != 0) {
                func_808002D8_chtntdetonator((u8 *)arg0);
                marker = arg0->unk3C;
                if (marker != NULL) {
                    other = func_80106790(marker);
                } else {
                    other = NULL;
                }
                if (other != NULL) {
                    func_8010108C(other, 5, 0);
                }
                func_800FFAB0(arg0);
            }
            break;
    }
}

/* extern */

void func_80800148_chtntdetonator(Actor *arg0, void *arg1) {
    BtIntPtr func_800D674C(s32);
    void func_800DBEFC(void *, s32, void *);
    void func_800E24D8(s32);
    void func_800E2588(u32);
    void func_800E2AA4(void *, BtIntPtr, s32, s32, void *, f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_80101870(Actor *, void *);
    OSThread *func_80104130(void);
    struct {
        s32 asset;
        f32 scale[3];
    } effect;

    func_80101870(arg0, arg1);
    if (arg0->unk7C_12) {
        func_800DBEFC(func_80104130(), 4, arg0->actorData);
        if (arg0->unk70_10 == 2) {
            effect.asset = func_800D674C(0x9C6);
            func_800EFA4C(effect.scale, 0.4f, 0.4f, 0.4f);
            func_800E2588(1);
            func_800E24D8(1);
            func_800E2AA4(arg1, effect.asset, (s32)arg0->unk50, 0, arg0->actorData, effect.scale);
        }
    }
}

void func_8080021C_chtntdetonator(Actor *arg0) {
    void func_800904F4(s32, Unk80132ED0 *);
    int func_800EEEA8(f32 vec[3]);
    f32 func_800EFC7C(void *, void *);
    void func_8010D254(f32 *);
    s32 func_8010D278();
    f32 position[3];

    if (func_8010D278() == 0xF) {
        if (func_800EEEA8((f32 *)arg0->actorData) == 0) {
            func_8010D254(position);
            if (func_800EFC7C(arg0->actorData, position) < 4900.0f) {
                if (position[1] < ((f32 *)arg0->actorData)[1] + 140.0f && ((f32 *)arg0->actorData)[1] + -50.0f < position[1]) {
                    func_800904F4(0x42, arg0->unk0);
                }
            }
        }
    }
}

void func_808002D8_chtntdetonator(u8 *arg0) {
    s32 *_fxgenlist_entrypoint_2(void);
    void func_80018820(s32, f32, f32);
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800C4AF0(f32 *, void *);
    s32 func_800E1610(s32, f32, f32, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_80800380_chtntdetonator(u8 *);
    void func_808003C0_chtntdetonator(u8 *);
    extern s32 D_808006F0_chtntdetonator[5];
    f32 position[3];

    func_800EE7F8(position, (f32 *)(arg0 + 4));
    position[1] += 270.0f;
    func_800BBCB8(position, NULL, 1.5f, 1, _fxgenlist_entrypoint_2());
    func_808003C0_chtntdetonator(arg0);
    func_80800380_chtntdetonator(arg0);
    func_800C4AF0((f32 *)(arg0 + 4), D_808006F0_chtntdetonator);
    func_800E1610(0, 30.0f, 0.9f, (f32 *)(arg0 + 4));
    func_80018820(0, 3.0f, 0.25f);
}    typedef struct { u8 pad0[0x38]; f32 unk38; } Objdetonator_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_80800380_chtntdetonator(u8 *arg0) {
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    extern s32 D_80800704_chtntdetonator[20];
    func_800BBCB8((f32 *)(arg0 + 4), NULL, (((Objdetonator_arg0 *)arg0)->unk38), 12, D_80800704_chtntdetonator);
}

void func_808003C0_chtntdetonator(u8 *arg0) {
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    extern s32 D_80800754_chtntdetonator[15];
    func_800BBCB8((f32 *)(arg0 + 4), NULL, (((Objdetonator_arg0 *)arg0)->unk38), 15, D_80800754_chtntdetonator);
}

s32 func_80800400_chtntdetonator(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    void _subaddieDll_entrypoint_4(void *arg0, s32 arg1);
    Actor *_subaddiefind_entrypoint_2(s32, BtIntPtr);
    int func_800EEEA8(f32 *);
    void func_80101010(f32 *);
    void func_80102424(Actor *, s32);
    Actor *func_80106790(Unk80132ED0 *);
    extern s16 D_80800790_chtntdetonator[];
    Actor *owner;
    s16 saved;
    s32 index;
    Unk80132ED0 *marker;
    s32 id;

    switch (arg1) {
    case 5:
        owner = arg0->unk3C ? func_80106790(arg0->unk3C) : NULL;
        id = -1;
        switch (owner->unk6C_9) {
        case 0x145:
            index = owner->unk74_7 - 50;
            id = D_80800790_chtntdetonator[index];
            break;
        case 0x14B:
            id = 0;
            break;
        case 0x14A:
            id = 0x41;
            break;
        }
        if (id != -1) {
            marker = NULL;
            if (owner->unk6C_9 == 0x145 && (index = owner->unk74_7 - 50) == 2) {
                saved = id;
                owner = _subaddiefind_entrypoint_2(0x2A3, 0);
                id = saved;
                if (owner != NULL) {
                    marker = owner->unk0;
                }
            }
            _capod_entrypoint_13(arg0->unk0, marker, id, 0x10);
        }
        func_80102424(arg0, 2);
        _subaddieDll_entrypoint_4(arg0, 1);
        break;
    case 6:
        func_80101010(func_800EEEA8((f32 *)arg0->actorData) ? arg0->position : (f32 *)arg0->actorData);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800588_chtntdetonator(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_4(Actor*, f32*, u32, u32*);
    extern u32 D_80800798_chtntdetonator[6];
    u32 temp_t7;

    temp_t7 = (u32)arg0->unk70_10 == 2;
    if ((temp_t7 != 0) || ((temp_t7 == 0) && (arg0->unk5F != 0))) {
        _subaddieaudioloop_entrypoint_4(arg0, (f32 *)((u8 *)arg0 + 0x18), temp_t7, D_80800798_chtntdetonator);
    }
}

/* extern */

s32 chtntdetonator_entrypoint_1(Actor *arg0, s32 arg1) {
    s32 _subaddiefind_entrypoint_7(Actor *, s32, s32);
    s32 func_800DA298(GameFlag);
    void func_800FFA88(Unk80132ED0 *);
    void func_800FFAB0(Actor *);
    Actor *func_80106790(Unk80132ED0 *);
    Actor *var_v1;

    if (func_800DA298(arg1) != 0) {
        if (_subaddiefind_entrypoint_7(arg0, 0x149, 0x320) != -1) {
            func_800FFA88(arg0->unk3C);
        }
        func_800FFAB0(arg0);
        return 0;
    }
    if (_subaddiefind_entrypoint_7(arg0, 0x149, 0x320) != 0) {
        var_v1 = func_80106790(arg0->unk3C);
    } else {
        var_v1 = NULL;
    }
    if (var_v1 != NULL) {
        var_v1->unk3C = arg0->unk0;
    }
    return 1;
}
/* data_to_c.py: from asm/data/overlays/ch/tnt/detonator.data.s */
extern u8 D_80800690_chtntdetonator[];
void func_80105834(Actor*);
void func_80107C2C();
u8 D_80800690_chtntdetonator[24] BT_DATA(4, overlays_ch_tnt_detonator, 0x0) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x80, 0x00, 0x00, 0x00, 0x9B, 0x00, 0x44, 0x3F, 0x80, 0x00, 0x00, 0x00, 0x9B, 0x00, 0x02 };
ActorData D_808006A8_chtntdetonator [1] BT_DATA(4, overlays_ch_tnt_detonator, 0x18) = { { 344, 329, 1697, 1, (void *)D_80800690_chtntdetonator, (void (*)(struct Actor *))func_80800054_chtntdetonator, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80800148_chtntdetonator, 52428800, 0, 0, 0, 0, 6, 0, 0, 0, 0, (void (*)(struct Actor *))func_8080000C_chtntdetonator, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32744, 9218, (void (*)(struct Actor *, long, long))func_80800400_chtntdetonator, 0 } };
s32 D_808006F0_chtntdetonator[5] BT_DATA(4, overlays_ch_tnt_detonator, 0x60) = { 1246227, 655590, 1572865, 81922500, 0 };
s32 D_80800704_chtntdetonator[20] BT_DATA(4, overlays_ch_tnt_detonator, 0x74) = { 1902243, 2948120, 26278936, 65536650, 65536010, -1310720, -1310700, 4915220, 1834208, -65535996, 10027015, 131115, 25166336, 1376294, 13369383, 13107400, 26214800, 2228377, 11731046, 8388608 };
s32 D_80800754_chtntdetonator[15] BT_DATA(4, overlays_ch_tnt_detonator, 0xC4) = { 1903074, 1445888, 262297, 458756, 1376256, 13369387, 25166336, 2228300, 5832742, 3342380, -16383600, -16383750, 39321850, 1833008, -78643200 };
s16 D_80800790_chtntdetonator [4] BT_DATA(4, overlays_ch_tnt_detonator, 0x100) = { 10, 12, 6, 14 };
u32 D_80800798_chtntdetonator[6] BT_DATA(4, overlays_ch_tnt_detonator, 0x108) = { 0x1304E2, 0x166D60, 0, 0, 0, 0 };
