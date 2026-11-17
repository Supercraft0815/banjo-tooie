#include "common.h"

s32 func_80800000_chstoneballcoach(Actor *arg0, s32 arg1, s32 arg2) {
    void _gcdialogcamera_entrypoint_3(f32 *arg0, f32 arg1);
    void func_800DF744(s32, s32);
    s32 func_801015D0(Actor *);
    extern s32 D_808003B8_chstoneballcoach[4];
    switch (arg1) {
    case 0x52:
        _gcdialogcamera_entrypoint_3(D_808003B8_chstoneballcoach, arg0->scale);
        break;
    case 0x2E:
        arg0->unk70_10 = 1;
        break;
    case 0x1F:
        func_801015D0(arg0);
        func_800DF744(3, 1);
        break;
    default:
        return 0;
    }
    return 1;
}

/* extern */

void func_80800090_chstoneballcoach(Actor *arg0, s32 arg1, s32 arg2) {
    s32 func_800C05B8(s32, s32, f32 *, Unk80132ED0 *, BtIntPtr, s32, s16);
    if (arg1 != 0) {
        func_800C05B8(arg1, arg2, arg0->position, arg0->unk0, 0, 0, 0x34);
        arg0->unk70_10 = 2;
        arg0->unk74_30 = 1;
    }
}

/* extern */

void func_80800100_chstoneballcoach(void *arg0) {
    s32 func_80102B2C(void *, s32);
    s32 func_80102CF4(void *, s32);
    f32 func_8010CD28();
    (((Actor *)arg0)->unk54) = func_8010CD28();
    if (func_80102CF4(arg0, 0x3F800000) == 0) {
        func_80102B2C(arg0, 0x3F800000);
    }
}

void func_80800140_chstoneballcoach(Actor *arg0) {
    s32 _subaddiedialog_entrypoint_6(f32 *, s32, s32, s32, s32);
    s32 func_80016B30(s32, s32);
    s32 func_8008FA60(s32, s32);
    s32 func_80090080();
    s32 func_80090128();
    s32 func_80090178(s32);
    s32 func_800DA298(s32);
    s32 func_800DA9E4(s32, s32);
    void func_8010C820(BtIntPtr arg0, s32 arg1, s32 arg2);
    s32 func_8010CAC0(f32 *, s32);
    extern f32 D_808003C8_chstoneballcoach[3];
    s32 var_a3;
    s32 sp28;

    if (func_80090128() != 0) {
        func_8010C820(arg0, 0x8C, 0x1E);
        func_80800100_chstoneballcoach(arg0);
    }
    if (arg0->unk70_10 == 1) {
        if (func_80090178(0x80) != 0) {
            if (func_8010CAC0(D_808003C8_chstoneballcoach, 0x96) != 0) {
                if (func_800DA9E4(0x428, 1) == 0) {
                    func_80800090_chstoneballcoach(arg0, 0xF23, 6);
                }
            } else if ((func_8010CAC0(arg0->position, 0xC8) != 0) && (func_8008FA60(0x80, 0) != 0)) {
                sp28 = 6;
                var_a3 = 0;
                if (func_800DA9E4(arg0->unk74_7 + 0x3F3, 1) == 0) {
                    if (func_800DA298(0x5F) != 0) {
                        var_a3 = arg0->unk74_7 + 0xEF8;
                    } else if (func_800DA298(0x5E) != 0) {
                        var_a3 = arg0->unk74_7 + 0xEF5;
                    } else {
                        var_a3 = arg0->unk74_7 + 0xEF2;
                    }
                    sp28 = 0xE;
                } else {
                    if ((func_80090080() != 0) && (func_80016B30(0, 1) != 0)) {
                        if (func_800DA298(0x5F) != 0) {
                            var_a3 = arg0->unk74_7 + 0xF18;
                        } else if (func_800DA298(0x5E) != 0) {
                            var_a3 = arg0->unk74_7 + 0xF15;
                        } else {
                            var_a3 = arg0->unk74_7 + 0xF12;
                        }
                        sp28 = 0xE;
                    }
                }
                func_80800090_chstoneballcoach(arg0, var_a3, sp28);
            }
        } else if (_subaddiedialog_entrypoint_6(arg0->position, (s32) arg0->rotation[1], 0x96, 0x46, 6) != 0) {
            func_80800090_chstoneballcoach(arg0, arg0->unk74_7 + 0xF21, 0xE);
        }
    }
}

/* extern */

void func_8080035C_chstoneballcoach(Actor *arg0) {
    f32 func_800DC0C0(void);
    void func_80101EE4(Actor *, f32);
    func_80101EE4(arg0, func_800DC0C0());
}

OSThread *chstoneballcoach_entrypoint_0(void)
{
    extern ActorData D_808003D4_chstoneballcoach[];

    return (OSThread *) D_808003D4_chstoneballcoach;
}
/* data_to_c.py: from asm/data/overlays/ch/stoneballcoa.data.s */
extern u8 D_808003A0_chstoneballcoach[];
void func_80105834(Actor*);
void func_801018A4();
void func_80107C2C();
u8 D_808003A0_chstoneballcoach[24] BT_DATA(4, overlays_ch_stoneballcoa, 0x0) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x80, 0x00, 0x00, 0x00, 0x7B, 0x00, 0x00, 0x40, 0x80, 0x00, 0x00, 0x00, 0x7B, 0x00, 0x00 };
s32 D_808003B8_chstoneballcoach[4] BT_DATA(4, overlays_ch_stoneballcoa, 0x18) = { 1126170624, 1120403456, 1120403456, 1109393408 };
f32 D_808003C8_chstoneballcoach[3] BT_DATA(4, overlays_ch_stoneballcoa, 0x28) = { -1200.0f, -350.0f, -350.0f };
ActorData D_808003D4_chstoneballcoach [1] BT_DATA(4, overlays_ch_stoneballcoa, 0x34) = { { 599, 371, 1654, 1, (void *)D_808003A0_chstoneballcoach, (void (*)(struct Actor *))func_80800140_chstoneballcoach, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_801018A4, 0, 0, 0, 0, 8, 4, 0, 0, 0, 0, (void (*)(struct Actor *))func_8080035C_chstoneballcoach, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 2, (void (*)(struct Actor *, long, long))func_80800000_chstoneballcoach, 0 } };
