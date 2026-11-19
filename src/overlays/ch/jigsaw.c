#include "common.h"
BT_NATIVE_ONLY(void func_80105834();)
/* extern */

void func_80800000_chjigsaw(Actor *arg0, void *arg1) {
    struct { u8 unk0[0x1A]; u16 unk1A; } *data = arg1;
    void _suautobaddies_entrypoint_3(void);
    void func_800D0BD4(s32, u32);
    s32 func_800DA298(s32);
    void func_80108B04(Actor *, u32);
    s32 func_8010A6B0(Actor *, u32);
    if ((func_8010A6B0(arg0, (u32)data->unk1A >> 5) != 0) && (func_800DA298(0x665) == 0)) {
        func_80108B04(arg0, 0);
        func_800D0BD4((s32)arg0->unk50, 1);
        _suautobaddies_entrypoint_3();
    }
}

void func_80800070_chjigsaw(Actor *arg0) {
    void func_800D05E4(s32, s32, BtIntPtr);
    void func_800D0778(s32, s32, f32 *);
    s32 func_800D0B68(u32, u32);
    void func_800FC6B0(u32);
    void func_800FFAB0(Actor *);
    if (func_800D0B68((s32)arg0->unk50, 1) != 0) {
        func_800FFAB0(arg0);
        return;
    }
    func_800D05E4((s32)arg0->unk50, 1, (BtIntPtr)arg0->unk0);
    if (arg0->unk58 != 0.0f) {
        func_800FC6B0(0x18);
    }
    func_800D0778((s32)arg0->unk50, 1, arg0->position);
}

/* extern */

void func_8080011C_chjigsaw(Actor *arg0) {
    f32 func_800D8FF8(void);
    f32 temp_f2;

    arg0->unk54 += func_800D8FF8() * 230.0f;
    temp_f2 = arg0->unk54;
    if (temp_f2 >= 360.0f) {
        arg0->unk54 = temp_f2 - 360.0f;
    }
}

/* extern */

void func_8080017C_chjigsaw(Actor *arg0) {
    void func_800C8B84(s32);
    void func_800D05E4(s32, s32, BtIntPtr);

    func_800D05E4((s32)arg0->unk50, 1, 0);
    if ((u32)arg0->unk6C_0 != 0) {
        func_800C8B84(arg0->unk6C_0);
    }
}

void func_808001D0_chjigsaw(BtIntPtr arg0)
{
    func_80105834();
    func_8080011C_chjigsaw(arg0);
}
void func_808001F8_chjigsaw(Actor *arg0) {
    typedef struct {
        BT_BITFIELD_ORDER(u32 unused : 28, u32 unused2 : 3);
        u32 attached : 1;
        BT_BITFIELD_ORDER(u32 unused2 : 3, u32 unused : 28);
    } JigsawFlags;
    s32 *_fxgenlist_entrypoint_1(void);
    void _fxtwinkle_entrypoint_0(f32 *);
    BtIntPtr func_800B5BE4(s32);
    void func_800BA22C(BtIntPtr, s32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    s32 *func_800BEF00(f32 *, f32 *, f32 *, s32);
    void func_800C8CB8(s32, f32 *);
    void func_800D0778(s32, s32, f32 *);
    f32 func_800D8FF8(void);
    f32 func_800DC0C0(void);
    f32 func_800DC178(f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF214(f32 *, f32, f32, f32);
    void func_80103DFC(Actor *, f32 *);
    union { u32 word; JigsawFlags bits; } flags;
    f32 dt;
    f32 start[3];
    f32 end[3];
    f32 normal[3];
    f32 sparkle[3];
    f32 angle;
    f32 pos[3];
    s32 i;
    BtIntPtr emitter;

    dt = func_800D8FF8();
    if (((JigsawFlags *)&arg0->unk78)->attached) {
        func_800D0778((s32)arg0->unk50, 1, arg0->position);
    } else if (arg0->unk64_19) {
        func_800EE7F8(start, arg0->position);
        start[1] += 100.0f;
        func_800EE7F8(end, arg0->position);
        end[1] -= 100.0f;
        if (func_800BEF00(start, end, normal, arg0->unk14)) {
            arg0->position[1] = end[1];
        } else {
            arg0->position[1] += ((f32 *)arg0->actorData)[7] * dt;
        }
    }
    if (arg0->unk7C_12) {
        for (i = 0; i != 4; i++) {
            if (func_800DC0C0() < 0.015f) {
                func_80103DFC(arg0, sparkle);
                angle = func_800DC178(0.0f, 360.0f);
                func_800EF214(sparkle, angle, func_800DC178(0.0f, 360.0f), 40.0f);
                _fxtwinkle_entrypoint_0(sparkle);
            }
        }
        if (arg0->unk58 > 0.0f) {
            if (func_800DC0C0() < 2.0f * (arg0->unk58 / 3.0f)) {
                emitter = func_800B5BE4(16);
                func_800BABB8(emitter, arg0->position, arg0->position, 1.0f, _fxgenlist_entrypoint_1());
                func_800BA22C(emitter, 1);
            }
            arg0->unk58 -= dt;
        }
    }
    if (arg0->unk70_10 == 1) {
        flags.word = *(u32 *)&arg0->unk78;
        if (flags.bits.attached && arg0->unk6C_0) {
            func_800EE7F8(pos, arg0->position);
            pos[1] += 100.0f;
            func_800C8CB8(arg0->unk6C_0, pos);
        }
        func_8080011C_chjigsaw(arg0);
    }
}

void func_808004A0_chjigsaw(Actor *arg0, s32 arg1) {
    void *func_800DE448(f32 *, f32 *, f32, f32 *, BtIntPtr);
    void func_800DF47C(s32, BtIntPtr);
    void func_800EFA4C(f32 *, f32, f32, f32);
    s32 func_80101970();
    BtIntPtr func_8010347C(Unk80132ED0 *);
    s32 func_801015D0(Actor *);
    f32 sp2C[3];

    func_800EFA4C(sp2C, 0.0f, arg0->unk54, 0.0f);
    func_80101970(arg0);
    func_800DF47C((BtIntPtr)func_801015D0, (BtIntPtr)arg0);
    func_800DE448(arg0->position, sp2C, arg0->scale, NULL, func_8010347C(arg0->unk0));
}

s32 func_80800518_chjigsaw(Actor *arg0, s32 arg1, void *arg2) {
    void _chjigsawcollect_entrypoint_1(Actor **, s32, s32);
    s32 func_800C8A98(void);
    void func_800C8CB8(s32, f32 *);
    void func_800CF9E4(s32, s32, s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800FFAB0(Actor *);
    f32 sp1C[3];

    switch (arg1) {
        case 0x3E:
            func_80800000_chjigsaw(arg0, arg2);
            break;
        case 0x12:
            arg0->unk64_19 = (BtIntPtr)arg2;
            break;
        case 0x13:
            arg0->unk50 = *(s32 *)&arg2;
            break;
        case 0x14:
            if (arg2 != 0) {
                arg0->unk58 = 3.0f;
            } else {
                arg0->unk58 = 0.0f;
            }
            break;
        case 0x3D:
            _chjigsawcollect_entrypoint_1(&arg0, (s32)arg0->unk50, arg0->unk70_0);
            func_800FFAB0(arg0);
            break;
        case 0x55:
            arg0->unk6C_0 = func_800C8A98();
            func_800CF9E4((s32)arg0->unk50, 1, arg0->unk6C_0);
            func_800EE7F8(sp1C, arg0->position);
            sp1C[1] += 100.0f;
            func_800C8CB8(arg0->unk6C_0, sp1C);
            break;
        default:
            return 0;
    }
    return 1;
}

OSThread *chjigsaw_entrypoint_0(void)
{
    extern ActorData D_80800770_chjigsaw[];

    return (OSThread *) D_80800770_chjigsaw;
}

/* extern */

void func_808006CC_chjigsaw(BtIntPtr arg0) {
    void _gcfrontend_entrypoint_9(s32 arg0);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    s32 _subaddiedialog_entrypoint_16();
    s32 func_800D395C();
    void func_800FFAB0(Actor *);
    if (func_800D395C() != 0) {
        func_800FFAB0(arg0);
        return;
    }
    if ((_subaddiedialog_entrypoint_16() != 0) && (_subaddiedialog_entrypoint_11(0, 0xD0A, 0, arg0 + 4, 0x6F) != 0)) {
        _gcfrontend_entrypoint_9(0x85);
        func_800FFAB0(arg0);
    }
}

OSThread *chjigsaw_entrypoint_1(void)
{
    extern ActorData D_808007B8_chjigsaw[];

    return (OSThread *) D_808007B8_chjigsaw;
}
/* data_to_c.py: from asm/data/overlays/ch/jigsaw.data.s */
OSThread *func_80108ED0(void);
void func_80107C2C();
void func_8010A730();
ActorData D_80800770_chjigsaw [1] BT_DATA(4, overlays_ch_jigsaw, 0x0) = { { 82, 543, 1552, 1, 0, (void (*)(struct Actor *))func_808001F8_chjigsaw, (void (*)(struct Actor *))func_808001D0_chjigsaw, (void (*)(long, long))func_808004A0_chjigsaw, 229376000, 1063675494, 0, 0, 32, 4, (void (*)(struct Actor *))func_8080017C_chjigsaw, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_80800070_chjigsaw, (void (*)(void *, long, void *, long, void *))func_80107C2C, -30720, 28676, (void (*)(struct Actor *, long, long))func_80800518_chjigsaw, 0 } };
ActorData D_808007B8_chjigsaw [1] BT_DATA(4, overlays_ch_jigsaw, 0x48) = { { 344, 1316, 0, 1, 0, (void (*)(struct Actor *))func_808006CC_chjigsaw, 0, (void (*)(long, long))func_8010A730, 0, 1063675494, 0, 0, 0, 4, 0, 0, 0, 0, 0, (void (*)(void *, long, void *, long, void *))func_80107C2C, 0, 0, 0, 0 } };
