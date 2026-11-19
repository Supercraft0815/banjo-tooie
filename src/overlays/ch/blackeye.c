#include "common.h"

/* extern */
void *func_80100094(Actor *, u32);
s32 _suexpression_entrypoint_8(Actor *, s32);

void func_80800000_chblackeye(BtIntPtr arg0, BtIntPtr arg1) {
    void _subaddieaudioquick_entrypoint_2(Actor *arg0, f32 arg1[3], void *arg2);
    s32 func_800DA298(s32);
    if (func_800DA298(0) == 0) {
        _subaddieaudioquick_entrypoint_2(arg0, arg0 + 4, arg1);
    }
}

void func_8080003C_chblackeye(void *arg0) {
    void func_800C4B7C(s32);
    f32 func_800D8FF8();
    s32 func_800DC128(s32, s32);
    f32 func_800DC178(f32, f32);
    extern s32 D_80800E68_chblackeye[6];
    extern s32 D_80800E80_chblackeye[8];
    extern s16 D_80800EA0_chblackeye[];
    f32 sp24;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f2;

    temp_f0 = func_800D8FF8();
    sp24 = temp_f0;
    temp_f2 = (*(f32 *)((s8 *)(arg0) + (0x24)));
    if (temp_f2 > 0.0f) {
        (*(f32 *)((s8 *)(arg0) + (0x24))) = (f32) (temp_f2 - temp_f0);
    } else {
        func_800C4B7C(D_80800EA0_chblackeye[func_800DC128(0, 5)]);
        func_80800000_chblackeye((BtIntPtr) arg0, (BtIntPtr) D_80800E68_chblackeye);
        (*(f32 *)((s8 *)(arg0) + (0x24))) = func_800DC178(2.5f, 5.0f);
    }
    temp_f0_2 = (*(f32 *)((s8 *)(arg0) + (0x34)));
    if (temp_f0_2 > 0.0f) {
        (*(f32 *)((s8 *)(arg0) + (0x34))) = (f32) (temp_f0_2 - sp24);
        return;
    }
    func_80800000_chblackeye((BtIntPtr) arg0, (BtIntPtr) D_80800E80_chblackeye);
    (*(f32 *)((s8 *)(arg0) + (0x34))) = func_800DC178(2.5f, 5.0f);
}

void func_80800128_chblackeye(Actor *arg0, s32 arg1) {
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 func_800D0B68(u32, u32);
    s32 func_800DA9E4(s32, s32);
    s32 func_800DC128(s32, s32);
    extern f32 D_80800EAC_chblackeye[3];
    s16 var_a1;
    s32 sp28;

    sp28 = 4;
    if (func_800DA9E4(0xE4, 1) == 0) {
        var_a1 = 0x100C;
        sp28 = 0xC;
    } else if ((arg1 != 0) && (func_800D0B68(0x19, 7) == 0)) {
        var_a1 = arg0->unk6C_0 + 0x1010;
        sp28 = 0xC;
        if (arg0->unk6C_0 < 2U) {
            arg0->unk6C_0++;
        } else {
            arg0->unk6C_0 = 0;
        }
    } else {
        var_a1 = func_800DC128(0x100D, 0x1010);
    }
    _subaddiedialog_entrypoint_11(arg0->unk0, var_a1, sp28, D_80800EAC_chblackeye, 0x6E);
    arg0->unk74_30 = 1;
}

void func_80800224_chblackeye(Actor *arg0) {
    void func_800EF04C(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    void func_800EF934(f32 *, f32 *, f32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    f32 *position[5];
    Actor *var_v0;
    f32 temp;
    s32 var_v1;

    func_800EFA4C((f32 *)arg0->actorData, -250.0f, 0.0f, -200.0f);
    func_800EFA4C((f32 *)&arg0->actorData[4], 250.0f, 450.0f, -950.0f);
    func_800EF334((f32 *)arg0->actorData, arg0->scale);
    func_800EF334((f32 *)&arg0->actorData[4], arg0->scale);
    func_800EF934((f32 *)arg0->actorData, (f32 *)arg0->actorData, arg0->rotation[1]);
    func_800EF934((f32 *)&arg0->actorData[4], (f32 *)&arg0->actorData[4], arg0->rotation[1]);
    position[0] = arg0->position;
    func_800EF04C((f32 *)&arg0->actorData[4], position[0]);
    func_800EF04C((f32 *)arg0->actorData, position[0]);
    var_v1 = 0;
    var_v0 = arg0;
    do {
        var_v1 += 4;
        if (((f32 *)var_v0->actorData)[0] < ((f32 *)var_v0->actorData)[4]) {
            temp = ((f32 *)var_v0->actorData)[4];
            ((f32 *)var_v0->actorData)[4] = ((f32 *)var_v0->actorData)[0];
            ((f32 *)var_v0->actorData)[0] = temp;
        }
        var_v0 = (Actor *)((u8 *)var_v0 + 4);
    } while (var_v1 != 0xC);
}

void func_80800314_chblackeye(Actor *arg0, s32 arg1) {
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    void func_80102424(Actor *, s32);
    f32 *saved[2];
    f32 *data;

    func_80102424(arg0, arg1);
    data = (f32 *)arg0->actorData;
    switch (arg1) {
        case 1:
            func_800EE7F8(saved[0] = data, arg0->position);
            func_800EF1B8(saved[0], arg0->rotation[1] + 180.0f, arg0->scale * 350.0f);
            return;
        case 2:
        case 3:
            func_80800224_chblackeye(arg0);
            return;
    }
}

/* extern */

void func_808003C0_chblackeye(Actor *arg0) {
    s32 func_800D0B68(u32, u32);
    void func_80800314_chblackeye(Actor *, s32);
    arg0->unk64_20 = 1;
    arg0->unk64_19 = func_800D0B68(0x19, 7);
    if (!arg0->unk64_19) {
        func_80800314_chblackeye(arg0, 1);
        return;
    }
    func_80800314_chblackeye(arg0, 3);
}

void func_80800444_chblackeye(Actor* arg0) 
{
    if (func_80100094(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
void func_80800478_chblackeye(void *arg0) {
    BtIntPtr func_800B53A4(s32);
    void func_800BA4D0(s16 *, s16);
    void func_800BA6B0(u8 *, s16, s16, s16, s16, s16, s16);
    void func_800BA7C4(void *, f32, f32);
    void func_800BA7FC(void *, f32, f32);
    void func_800BA994(u8 *, s16, s16, s16, s16, s16, s16);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    void func_800DBEFC(s32 *, s32, f32 *);
    extern s32 D_80800EB8_chblackeye[10];
    f32 sp3C[3];
    s16 temp_f8;
    BtIntPtr temp_v0;

    temp_v0 = func_800B53A4(4);
    temp_f8 = (s32) (((Actor *)arg0)->scale * -5.0f);
    func_800BA6B0((u8 *)temp_v0, temp_f8, -10, temp_f8, (s16) (((Actor *)arg0)->scale * 5.0f), -15, (s16) (((Actor *)arg0)->scale * 5.0f));
    func_800BA4D0((s16 *)temp_v0, (s16) (s32) (((Actor *)arg0)->scale * 350.0f));
    func_800BA7C4((void *)temp_v0, ((Actor *)arg0)->scale * 0.06f, ((Actor *)arg0)->scale * 0.1f);
    func_800BA7FC((void *)temp_v0, ((Actor *)arg0)->scale * 0.03f, ((Actor *)arg0)->scale * 0.03f);
    func_800BA994((u8 *)temp_v0, 25, (s16) (((Actor *)arg0)->rotation[1] + 155.0f), 25, 45, (s16) (((Actor *)arg0)->rotation[1] + 205.0f), 75);
    func_800DBEFC(((Actor *)arg0)->unk0->unk4, 4, sp3C);
    func_800BABB8(temp_v0, sp3C, NULL, 1.0f, D_80800EB8_chblackeye);
}

void func_8080061C_chblackeye(void *arg0) {
    BtIntPtr func_800B53A4(s32);
    void func_800BA4D0(s16 *, s16);
    void func_800BA6B0(u8 *, s16, s16, s16, s16, s16, s16);
    void func_800BA7C4(void *, f32, f32);
    void func_800BA7FC(void *, f32, f32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    void func_800DBEFC(s32 *, s32, f32 *);
    extern s32 D_80800E10_chblackeye[4];
    extern s32 D_80800EE0_chblackeye[14];
    f32 sp3C[3];
    s16 temp_f8;
    BtIntPtr temp_v0;

    temp_v0 = func_800B53A4(0xA);
    temp_f8 = (s32) (((Actor *)arg0)->scale * -30.0f);
    func_800BA6B0((u8 *)temp_v0, temp_f8, 0, temp_f8, (s16) (((Actor *)arg0)->scale * 30.0f), 0, (s16) (((Actor *)arg0)->scale * 30.0f));
    func_800BA4D0((s16 *)temp_v0, (s16) (s32) (((Actor *)arg0)->scale * 350.0f));
    func_800BA7C4((void *)temp_v0, ((Actor *)arg0)->scale * 0.06f, ((Actor *)arg0)->scale * 0.1f);
    func_800BA7FC((void *)temp_v0, ((Actor *)arg0)->scale * 0.03f, ((Actor *)arg0)->scale * 0.03f);
    func_800DBEFC(((Actor *)arg0)->unk0->unk4, 4, sp3C);
    func_800BABB8(temp_v0, sp3C, NULL, 1.0f, D_80800EE0_chblackeye);
    func_80800000_chblackeye((BtIntPtr) arg0, (BtIntPtr) D_80800E10_chblackeye);
}

void func_80800774_chblackeye(Actor *arg0) {
    s32 pad[2];
    BtIntPtr func_800BBCB8(s32 *, s32 *, f32, s32, s32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    void func_800EF934(f32 *, f32 *, f32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    extern s32 D_80800E20_chblackeye[12];
    extern s32 D_80800F18_chblackeye[21];
    extern s32 D_80800F6C_chblackeye[19];
    f32 sp2C;

    func_800EFA4C(&sp2C, 0.0f, 40.0f, -800.0f);
    func_800EF334(&sp2C, arg0->scale);
    func_800EF934(&sp2C, &sp2C, arg0->rotation[1]);
    func_800EF04C(&sp2C, arg0->position);
    func_800BBCB8(&sp2C, &sp2C, 1.0f, 3, D_80800F18_chblackeye);
    func_800BBCB8(&sp2C, &sp2C, 1.0f, 1, D_80800F6C_chblackeye);
    func_80800000_chblackeye((BtIntPtr) arg0, (BtIntPtr) D_80800E20_chblackeye);
    (*(u8 *)((s8 *)(arg0) + (0x65))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x65))) & 0xFFEF);
}

void func_80800838_chblackeye(Actor *arg0) {
    typedef union {
        Actor actor;
        struct {
            u8 pad[0x70];
            BT_BITFIELD_ORDER(u32 pad70_4 : 28, u32 pad70_0 : 3);
            u32 active : 1;
            BT_BITFIELD_ORDER(u32 pad70_0 : 3, u32 pad70_4 : 28);
        } flags;
    } BlackeyeActor;
    s32 _subaddiedialog_entrypoint_4(f32 *, s32, s32);
    void _suexpression_entrypoint_10(u32 *, Unk80132ED0 *, BtUIntPtr);
    s32 func_8008FA60(s32, s32);
    void func_8008FA94(f32 *, f32 *);
    s32 func_8008FB10(f32 *, f32, f32, f32);
    f32 func_800D8FF8(void);
    void func_800DBEFC(s32 *, s32, f32 *);
    s32 func_80101DDC(Actor *);
    s32 func_80101E14(Actor *, f32);
    s32 func_80101E4C(Actor *, f32 *);
    f32 func_80101F24(Actor *);
    s32 func_8010CAC0(f32 *, u32);
    extern s32 D_80800E00_chblackeye[4];
    extern s32 D_80800E50_chblackeye[4];
    extern s32 D_80800E60_chblackeye[2];
    extern f32 D_80800FB8_chblackeye[];
    extern f32 D_80800FF8_chblackeye[];
    extern f32 D_80801004_chblackeye[];
    extern f32 D_8080101C_chblackeye[];
    extern f32 D_80801024_chblackeye[];
    f32 sp44;
    f32 sp38[3];
    f32 sp2C[3];

    if (((BlackeyeActor *)arg0)->flags.active) {
        _suexpression_entrypoint_10(func_80100094(arg0, 1), arg0->unk0, 0);
        func_8080003C_chblackeye(arg0);
        switch (arg0->unk70_10) {
            case 1:
                if (arg0->unk7C_12 && func_80101E4C(arg0, D_80800FB8_chblackeye)) {
                    func_8080061C_chblackeye(arg0);
                }
                if (func_80101E4C(arg0, D_80800FF8_chblackeye)) {
                    func_80800000_chblackeye((BtIntPtr)arg0, (BtIntPtr)D_80800E00_chblackeye);
                } else if (func_80101E4C(arg0, D_80801004_chblackeye)) {
                    func_80800000_chblackeye((BtIntPtr)arg0, (BtIntPtr)D_80800E50_chblackeye);
                }
                func_8008FB10((f32 *)arg0->actorData, arg0->scale * 600.0f, 0.0f, arg0->scale * 250.0f);
                break;
            case 2:
                sp44 = func_80101F24(arg0);
                if (func_80101E4C(arg0, D_8080101C_chblackeye)) {
                    func_80800000_chblackeye((BtIntPtr)arg0, (BtIntPtr)D_80800E00_chblackeye);
                } else if (func_80101E4C(arg0, D_80801024_chblackeye)) {
                    func_80800000_chblackeye((BtIntPtr)arg0, (BtIntPtr)D_80800E50_chblackeye);
                } else if (func_80101E14(arg0, 0.04f)) {
                    func_80800000_chblackeye((BtIntPtr)arg0, (BtIntPtr)D_80800E60_chblackeye);
                } else if (func_80101DDC(arg0)) {
                    func_80800314_chblackeye(arg0, 3);
                } else if (func_80101E14(arg0, 0.815f)) {
                    func_80800774_chblackeye(arg0);
                }
                if (arg0->unk7C_12 && sp44 > 0.73f && sp44 < 0.83f) {
                    func_80800478_chblackeye(arg0);
                }
                func_8008FA94((f32 *)&arg0->actorData[4], (f32 *)arg0->actorData);
                break;
            case 3:
                func_8008FA94((f32 *)&arg0->actorData[4], (f32 *)arg0->actorData);
                break;
        }
        if (arg0->unk7C_12) {
            func_800DBEFC(arg0->unk0->unk4, 4, sp38);
            func_8008FB10(sp38, 10.0f, -50.0f, 50.0f);
        }
        if (!arg0->unk74_30 && func_8010CAC0(arg0->position, 500) && func_8008FA60(1, 0)) {
            sp2C[0] = arg0->position[0];
            sp2C[1] = arg0->position[1] + 100.0f;
            sp2C[2] = arg0->position[2];
            if (_subaddiedialog_entrypoint_4(sp2C, 500, 0)) {
                func_80800128_chblackeye(arg0, 1);
            } else if (arg0->unk58 <= 0.0f) {
                func_80800128_chblackeye(arg0, 0);
            }
        }
        if (arg0->unk58 > 0.0f && !arg0->unk74_30) {
            arg0->unk58 -= func_800D8FF8();
        }
    }
}

s32 func_80800BC4_chblackeye(Actor *arg0, s32 arg1, s32 arg2) {
    void _gcdialogcamera_entrypoint_3(u32 *, f32);
    void _gcdialogcamera_entrypoint_4(f32 *);
    s32 _suexpression_entrypoint_12(void *, s32, s32);
    BtIntPtr _suexpression_entrypoint_7(Actor *, s32, s32);
    void func_800D0BD4(s32, u32);
    BT_IDO_ONLY(void func_800D175C(s32, s32);) BT_NATIVE_ONLY(s32 func_800D175C(s32, s32);)
    void func_800DF744(s32, s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    void func_800FC660(u32);
    s32 func_801015D0(Actor *);
    extern u32 D_8080102C_chblackeye[4];
    extern u32 D_8080103C_chblackeye[4];
    f32 sp34[3];
    f32 sp28[3];

    switch (arg1) {
        case 0x29:
            _suexpression_entrypoint_7(arg0, 1, 0x6E);
            _suexpression_entrypoint_12(func_80100094(arg0, 1), 0x42700000, 0x41700000);
            break;
        case 0x2A:
            _suexpression_entrypoint_8(arg0, 1);
            break;
        case 0x2E:
            arg0->unk74_30 = 0;
            if (*(s16 *)&arg2 == 0x1012) {
                func_800D175C(0x4E, 2);
                func_800D0BD4(0x19, 7);
                func_800D0BD4(0x1A, 7);
                func_800FC660(0xE);
                arg0->unk64_19 = 1;
                func_80800314_chblackeye(arg0, 2);
            }
            arg0->unk58 = 25.0f;
            break;
        case 0x52:
            switch (arg0->unk70_10) {
                case 1:
                case 2:
                    func_800EE7F8(sp34, arg0->position);
                    func_800EF1B8(sp34, arg0->rotation[1], -150.0f);
                    _gcdialogcamera_entrypoint_3(D_8080102C_chblackeye, arg0->scale);
                    _gcdialogcamera_entrypoint_4(sp34);
                    break;
                case 3:
                    func_800EE7F8(sp28, arg0->position);
                    func_800EF1B8(sp28, arg0->rotation[1], -450.0f);
                    _gcdialogcamera_entrypoint_3(D_8080103C_chblackeye, arg0->scale);
                    _gcdialogcamera_entrypoint_4(sp28);
                    break;
            }
            break;
        case 0x1F:
            func_801015D0(arg0);
            func_800DF744(3, arg0->unk64_20);
            func_800DF744(4, 1);
            break;
        default:
            return 0;
    }
    return 1;
}

OSThread *chblackeye_entrypoint_0(void)
{
    extern ActorData D_8080104C_chblackeye[];

    return (OSThread *) D_8080104C_chblackeye;
}
/* data_to_c.py: from asm/data/overlays/ch/blackeye.data.s */
extern u8 D_80800DE0_chblackeye[];
void func_80105834(Actor*);
void func_801018A4();
void func_80107C2C();
u8 D_80800DE0_chblackeye[32] BT_DATA(4, overlays_ch_blackeye, 0x0) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0x8C, 0x00, 0x00, 0x01, 0x51, 0x00, 0x41, 0x41, 0x10, 0x00, 0x00, 0x01, 0x52, 0x00, 0x42, 0x40, 0xB9, 0x99, 0x9A, 0x01, 0x53, 0x00, 0x41 };
s32 D_80800E00_chblackeye[4] BT_DATA(4, overlays_ch_blackeye, 0x20) = { 1246529, 852211, 17563672, 0 };
s32 D_80800E10_chblackeye[4] BT_DATA(4, overlays_ch_blackeye, 0x30) = { 1246525, 852211, 17563672, 0 };
s32 D_80800E20_chblackeye[12] BT_DATA(4, overlays_ch_blackeye, 0x40) = { 1246533, 852211, 17563672, 0, 1246531, 852134, 12582936, 0, 1246528, 1572864, 1246526, 1572864 };
s32 D_80800E50_chblackeye[4] BT_DATA(4, overlays_ch_blackeye, 0x70) = { 1246530, 852211, 17563670, 1441792000 };
s32 D_80800E60_chblackeye[2] BT_DATA(4, overlays_ch_blackeye, 0x80) = { 1246527, 1572864 };
s32 D_80800E68_chblackeye[6] BT_DATA(4, overlays_ch_blackeye, 0x88) = { 2162701, 14221555, 1644400, 458752001, 6553850, 0 };
s32 D_80800E80_chblackeye[8] BT_DATA(4, overlays_ch_blackeye, 0xA0) = { 1246342, 852160, 14221333, 786636, 3342361, 393223000, 65636, 16384000 };
s16 D_80800EA0_chblackeye [6] BT_DATA(4, overlays_ch_blackeye, 0xC0) = { 1344, 1067, 1368, 1369, 1367, 0 };
f32 D_80800EAC_chblackeye[3] BT_DATA(4, overlays_ch_blackeye, 0xCC) = { -728.0f, 0.0f, -2621.0f };
s32 D_80800EB8_chblackeye[10] BT_DATA(4, overlays_ch_blackeye, 0xD8) = { 1903066, 2162687, -21757925, -32702964, 458753, 1376256, 13369387, 33554944, 1445888, 68812800 };
s32 D_80800EE0_chblackeye[14] BT_DATA(4, overlays_ch_blackeye, 0x100) = { 1903066, 2162687, -21757908, -5898090, -5898150, 26214490, 1833708, -85196793, 65557, 204, 2818560, 33554454, 268438042, 0 };
s32 D_80800F18_chblackeye[21] BT_DATA(4, overlays_ch_blackeye, 0x138) = { 1902324, 720946, 3276800, 46, 210, 42598400, 18350880, 2490368, 65406, 0, 8519713, 5898240, 34, 7536793, 7536793, 1376256, 13369387, 33554944, 3145932, 1470464, 0 };
s32 D_80800F6C_chblackeye[19] BT_DATA(4, overlays_ch_blackeye, 0x18C) = { 1902325, 720946, 3276800, 46, 60, 42598400, 9831200, 2490368, -8519680, 130, 34, 7536793, 7536793, 1376256, 13369387, 33554944, 3145932, 1470464, 0 };
f32 D_80800FB8_chblackeye [16] BT_DATA(4, overlays_ch_blackeye, 0x1D8) = { 0.59f, 0.76f, 0.83f, 0.9f, -1.0f, 0.274f, 0.304f, 0.338f, 0.377f, 0.397f, 0.42f, 0.465f, 0.504f, 0.65f, 0.67f, -1.0f };
f32 D_80800FF8_chblackeye [3] BT_DATA(4, overlays_ch_blackeye, 0x218) = { 0.43f, 0.53f, -1.0f };
f32 D_80801004_chblackeye [6] BT_DATA(4, overlays_ch_blackeye, 0x224) = { 0.46f, 0.56f, -1.0f, 0.4444f, 0.4905f, -1.0f };
f32 D_8080101C_chblackeye [2] BT_DATA(4, overlays_ch_blackeye, 0x23C) = { 0.64f, -1.0f };
f32 D_80801024_chblackeye [2] BT_DATA(4, overlays_ch_blackeye, 0x244) = { 0.73f, -1.0f };
u32 D_8080102C_chblackeye[4] BT_DATA(4, overlays_ch_blackeye, 0x24C) = { 0x444E4000, 0x41F00000, 0x43480000, 0x43FA0000 };
u32 D_8080103C_chblackeye[4] BT_DATA(4, overlays_ch_blackeye, 0x25C) = { 0x442DC000, 0x43FA0000, 0x43960000, 0x43ADC000 };
ActorData D_8080104C_chblackeye [1] BT_DATA(4, overlays_ch_blackeye, 0x26C) = { { 738, 797, 1748, 1, (void *)D_80800DE0_chblackeye, (void (*)(struct Actor *))func_80800838_chblackeye, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_801018A4, 163840000, 0, 0, 0, 0, 7528, (void (*)(struct Actor *))func_80800444_chblackeye, 0, 0, 0, (void (*)(struct Actor *))func_808003C0_chblackeye, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1026, (void (*)(struct Actor *, long, long))func_80800BC4_chblackeye, 0 } };
