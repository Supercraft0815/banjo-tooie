#include "common.h"

OSThread *changlerbossbubble_entrypoint_0(void)
{
    extern ActorData D_808005D0_changlerbossbubble[];

    return (OSThread *) D_808005D0_changlerbossbubble;
}                typedef struct { BtIntPtr unk0; u8 pad4[0x30]; f32 unk34; } Objbubble_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void func_8080000C_changlerbossbubble(void *arg0) {
    f32 func_800EC75C(void *data, f32 *center);
    void func_800EFD4C(s16 vec[3]);
    s32 sp1C[3];

    func_800EC75C((((Objbubble_arg0 *)arg0)->unk0), sp1C);
    func_800EFD4C((((Objbubble_arg0 *)arg0)->unk0) + 0x1E);
    (((Objbubble_arg0 *)arg0)->unk34) = 0.75f;
}

void func_80800054_changlerbossbubble(Actor *arg0) {
    void func_80015E80(s32, void *);
    f32 func_800D8FF8(void);
    s32 func_800D9078(f32 *);
    void func_800EFD4C(s16 vec[3]);
    s32 func_800F54F0(BtIntPtr);
    void func_800F7B9C(BtIntPtr, u32);
    s32 func_8010114C(BtIntPtr, s32, BtIntPtr);
    s32 func_8010B990(Actor *, s32);
    void func_80800334_changlerbossbubble(Actor *);
    void func_80800450_changlerbossbubble(u8 *);
    s32 buttons[6];
    s32 controller;
    typedef struct {
        f32 timer;
        s32 count;
    } BubbleData;
    BtIntPtr marker;

    arg0->unk58 += func_800D8FF8();
    func_800EFD4C((BtIntPtr)((s16 *)&arg0->unk0->unk1C + 1));
    goto dispatch;
dispatch:
    switch (arg0->unk70_10) {
        case 1:
            if (func_8010B990(arg0, 0x400007) & 0x20) {
                func_80800334_changlerbossbubble(arg0);
            }
            break;
        case 2:
            controller = func_800F54F0(arg0->unk6C_0);
            func_80800450_changlerbossbubble((u8 *)arg0);
            func_80015E80(controller, buttons);
            if (buttons[0] == 1 || buttons[1] == 1) {
                ((BubbleData *)arg0->actorData)->count++;
                if (((BubbleData *)arg0->actorData)->count >= 10) {
                    func_800F7B9C(arg0->unk6C_0, 0x70);
                    return;
                }
                func_800F7B9C(arg0->unk6C_0, 0x7B);
            }
            if (func_800D9078(&((BubbleData *)arg0->actorData)->timer)) {
                marker = (BtIntPtr)arg0->unk3C;
                if (marker != 0) {
                    func_8010114C(marker, 10, 0);
                }
            }
            break;
    }
}

/* extern */

s32 func_80800194_changlerbossbubble(s32 arg0) {
    s32 func_800F64A4(BtIntPtr, s32);
    s32 func_800F6D24(BtIntPtr);
    u8 func_800F8B88(void);
    if (func_800F64A4(arg0, 0xA01) == 0) {
        return 0;
    }
    if (func_800F6D24(arg0) == 0) {
        return 1;
    }
    if (func_800F8B88() == 3) {
        return 1;
    }
    return 0;
}

s32 func_80800200_changlerbossbubble(Actor *arg0, s32 arg1, void *arg2) {
    typedef struct {
        u8 pad0[0x18];
        u16 pad18;
        u16 id : 11;
        u16 rest : 5;
        u8 pad1C[8];
        u32 busy : 10;
        u32 rest2 : 22;
    } Other;
    s32 func_800F7BC8(BtIntPtr, s32, Unk80132ED0 *);
    f32 func_800F5BF0();
    void func_80800334_changlerbossbubble(Actor *);
    void func_8010A570(Actor *);
    void func_80101FDC(Actor *, s32);
    void func_80102FDC(Actor *, f32);
    Other *other;

    switch (arg1) {
    case 0x2C:
        func_80800334_changlerbossbubble(arg0);
        break;
    case 0x3E:
        other = *(Other **)&arg2;
        if (other->busy == 0 && func_80800194_changlerbossbubble(other->id) && func_800F7BC8(other->id, 0x6F, arg0->unk0) == 2) {
            func_8010A570(arg0);
            func_80101FDC(arg0, 2);
            *(f32 *)&arg0->actorData[0] = 3.0f;
            arg0->unk6C_0 = other->id;
            func_80102FDC(arg0, func_800F5BF0(arg0->unk6C_0, arg0->position) * 0.015f);
            break;
        }
        func_80800334_changlerbossbubble(arg0);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800334_changlerbossbubble(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    BtIntPtr func_800B53A4(s32);
    void func_800BA22C(BtIntPtr, s32);
    void func_800BA568(s16 *, s16);
    void func_800BA7C4(void *, f32, f32);
    void func_800BA7FC(void *, f32, f32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    s32 func_800DC128(s32, s32);
    void func_800FFA88(Unk80132ED0 *);
    extern s32 D_80800618_changlerbossbubble[20];
    extern s32 D_80800668_changlerbossbubble[6];
    s32 sp3C;
    f32 temp_f20;
    BtIntPtr temp_v0_2;

    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800668_changlerbossbubble);
    sp3C = func_800DC128(3, 4);
    temp_v0_2 = func_800B53A4(sp3C);
    temp_f20 = arg0->scale;
    func_800BABB8(temp_v0_2, arg0->position, arg0->position, 1.0f, D_80800618_changlerbossbubble);
    func_800BA568(temp_v0_2, (s16) (arg0->position[1] + 1000.0f));
    func_800BA7C4(temp_v0_2, 0.25f * temp_f20, 0.6f * temp_f20);
    func_800BA7FC(temp_v0_2, 0.1f * temp_f20, 0.2f * temp_f20);
    func_800BA22C(temp_v0_2, sp3C);
    func_800FFA88(arg0->unk0);
}

/* extern */

void func_80800450_changlerbossbubble(u8 *arg0) {
    f32 func_800F5BF0();
    func_800F5BF0((*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF, arg0 + 4, arg0);
}

/* extern */

void func_80800480_changlerbossbubble(Actor *arg0, BtIntPtr arg1) {
    s32 _chbubble_entrypoint_0(void *arg0, f32 *position, f32 *offset, f32 scale, f32 distance);
    f32 func_800138D0(f32);
    f32 func_80013970(f32);
    void func_800E3980(f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EEBF0(f32 *, f32 *, f32);
    void func_800EF04C(f32 *, f32 *);
    f32 func_800F13C4(f32, f32);
    void func_800F18FC(f32 *arg0, f32 *arg1, f32 *arg2);
    f32 sp44[3];
    f32 sp38[3];
    f32 sp30[2];

    func_800EE7F8(sp38, arg0->position);
    func_800E3980(sp44);
    func_800F18FC(sp38, sp44, sp30);
    func_800EEBF0(sp44, sp30, 75.0f);
    func_800EF04C(sp38, sp44);
    sp30[0] = func_80013970((func_800F13C4(arg0->unk58, *(f32 *)&arg0->actorData[7]) / *(f32 *)&arg0->actorData[7]) * 360.0f) * 0.1f + 1.0f;
    sp30[1] = func_800138D0((func_800F13C4(arg0->unk58, *(f32 *)&arg0->actorData[7]) / *(f32 *)&arg0->actorData[7]) * 360.0f) * 0.15f + 1.0f;
    arg0->unk7C_12 = _chbubble_entrypoint_0(arg1, sp38, sp30, arg0->scale, 0.0f);
}
/* data_to_c.py: from asm/data/overlays/ch/anglerboss/bubble.data.s */
void func_80105834(Actor*);
OSThread *func_80108ED0(void);
void func_80107C2C();
ActorData D_808005D0_changlerbossbubble [1] BT_DATA(4, overlays_ch_anglerboss_bubble, 0x0) = { { 681, 1120, 2507, 1, 0, (void (*)(struct Actor *))func_80800054_changlerbossbubble, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80800480_changlerbossbubble, 0, 0, 0, 0, 0, 4, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_8080000C_changlerbossbubble, (void (*)(void *, long, void *, long, void *))func_80107C2C, 0, 0, (void (*)(struct Actor *, long, long))func_80800200_changlerbossbubble, 0 } };
s32 D_80800618_changlerbossbubble[20] BT_DATA(4, overlays_ch_anglerboss_bubble, 0x48) = { 1903051, 1446400, 65536, 2293760, 50, 27, 9830600, 458753, 1376256, 13369358, 3276860, 2949220, 13107243, 25166464, 2052336, -16777169, 4194368, 0, 1638400, 3342336 };
s32 D_80800668_changlerbossbubble[6] BT_DATA(4, overlays_ch_anglerboss_bubble, 0x98) = { 1246385, 852211, 17563672, 0, 0, 0 };
