#include "common.h"

void func_80800000_chmayafarmer(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _capod_entrypoint_2(BtIntPtr arg0, s32 arg1, s32 arg2);
    void _capod_entrypoint_7(s32 arg0, s32 arg1);
    void _capod_entrypoint_8(s32 arg0);
    s32 _gcdialogcamera_entrypoint_3(s32 *, f32);
    void _gcdialogcamera_entrypoint_4(BtIntPtr arg0);
    void _gcdialogcamera_entrypoint_5(BtIntPtr arg0);
    void _gcdialogcamera_entrypoint_8();
    extern s32 D_8080124C_chmayafarmer[4];

    switch (arg0->unk6C_0) {
        case 0:
            _capod_entrypoint_2(arg0->unk0, 8, 0);
        case 1:
            _capod_entrypoint_8(1);
            arg0->unk6C_0 = 2;
            _gcdialogcamera_entrypoint_3(D_8080124C_chmayafarmer, arg0->scale);
            _gcdialogcamera_entrypoint_4(arg0->position);
            _gcdialogcamera_entrypoint_5(arg0->rotation);
            _gcdialogcamera_entrypoint_8();
        case 2:
            _capod_entrypoint_7(arg1, arg2);
    }
}

void func_808000B0_chmayafarmer(Actor *arg0, s32 arg1, s32 arg2, Unk80132ED0 *arg3) {
    s32 _capod_entrypoint_2(BtIntPtr arg0, s32 arg1, s32 arg2);
    s32 _capod_entrypoint_6(BtIntPtr arg0, s32 arg1, s32 arg2);

    switch (arg0->unk6C_0) {
        case 0:
            _capod_entrypoint_2(arg0->unk0, 8, arg2);
        case 2:
            arg0->unk6C_0 = 1;
        case 1:
            _capod_entrypoint_6(arg3, arg1, arg2);
            break;
    }
}    typedef struct { u8 pad0[0x6C]; s32 unk6C; u32 unk70; } Objmayafarmer_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void func_80800138_chmayafarmer(void *arg0) {
    s32 _capod_entrypoint_3(s32, void *);
    if ((((Objmayafarmer_arg0 *)arg0)->unk6C) & 0x1FF) {
        _capod_entrypoint_3(0, arg0);
        (*(u16 *)((s8 *)(arg0) + (0x6E))) = (u16) ((*(u16 *)((s8 *)(arg0) + (0x6E))) & 0xFE00);
    }
}

void func_80800180_chmayafarmer(u8 *arg0, u32 arg1, s32 arg2) {
    struct Flags { u8 pad[0x74]; BT_BITFIELD_ORDER(u8 high : 1, u8 low : 6); u8 flag : 1; BT_BITFIELD_ORDER(u8 low : 6, u8 high : 1); };
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    arg2 |= 4;
    _subaddiedialog_entrypoint_11((((Actor *)arg0)->unk0), arg1, arg2, arg0 + 4, 0x2AU);
    ((struct Flags *)arg0)->flag = 1;
}

/* extern */

void func_808001CC_chmayafarmer(u8 *arg0, s32 arg1) {
    void func_80102424(Actor *, s32);
    func_80102424((Actor *) arg0, arg1);
    if (((Actor *) arg0)->unk70_10 == 4) {
        func_800FC660(0x10);
        func_80800180_chmayafarmer(arg0, 0xF07, 0xB);
        ((Actor *) arg0)->unk58 = 0.0f;
    }
}

s32 func_80800228_chmayafarmer(u8 *arg0, s32 arg1, s32 arg2) {
    struct FarmerState {
        u8 pad[0x74];
        BT_BITFIELD_ORDER(u32 flags : 16, u32 other : 7);
        u32 count : 9;
        BT_BITFIELD_ORDER(u32 other : 7, u32 flags : 16);
    };
    s32 _gcdialogcamera_entrypoint_3(s32 *, f32);
    s32 _suexpression_entrypoint_12(void *, s32, s32);
    BtIntPtr _suexpression_entrypoint_7(Actor *, s32, s32);
    void func_800C01A8(s16, s32);
    u32 func_800C07F4(void);
    s32 func_800CBC3C(u8 *);
    s32 func_800CD08C(s32, u8 *);
    s32 func_800D1000(s32, s32, s32 *, s32, BtIntPtr);
    s32 func_800DA544(s32);
    f32 func_800DC178(f32, f32);
    void *func_80100094(Actor *, u32);
    s32 *func_80108528(s32, u8 *, s32, u8 **);
    void func_80108B04(Actor *, u32);
    void func_80800000_chmayafarmer(Actor *, s32, s32);
    void func_808000B0_chmayafarmer(Actor *, s32, s32, Unk80132ED0 *);
    void func_808001CC_chmayafarmer(u8 *, s32);
    extern s32 D_8080125C_chmayafarmer[];
    extern u8 D_8080126C_chmayafarmer[];
    s32 count;
    s32 i;

    switch (arg1) {
        default:
            return 0;
        case 0x95:
            _suexpression_entrypoint_7((Actor *)arg0, 1, 0x2A);
            _suexpression_entrypoint_12(func_80100094((Actor *)arg0, 1), 0x42A00000, 0x41F00000);
            func_80108B04((Actor *)arg0, 0);
            break;
        case 0x11:
            if (((u32)*(u16 *)(arg0 + 0x72) >> 10) == 1) {
                func_808001CC_chmayafarmer(arg0, 3);
            }
            break;
        case 0x2E:
            arg0[0x74] &= 0xFFBF;
            if (*(s16 *)&arg2 != 0xF06) {
                if (*(s16 *)&arg2 == 0xF07) {
                    func_800C01A8(0x64, 0);
                    func_808000B0_chmayafarmer(arg0, 4, 0x2010, *(s32 *)arg0);
                    func_800D1000(4, 1, 0, 1, 0);
                }
            } else {
                func_80800138_chmayafarmer(arg0);
            }
            break;
        case 0x2F:
            if ((*(s16 *)&arg2 == 0xF06) && (func_800C07F4() == 0)) {
                func_800DA544(5);
            }
            break;
        case 0xB:
            switch (arg2) {
                case 0xF:
                    func_80800000_chmayafarmer(arg0, 2, 1);
                    return 4;
                case 4:
                    func_80800138_chmayafarmer(arg0);
                    return 4;
            }
            return 3;
        case 0x52:
            _gcdialogcamera_entrypoint_3(D_8080125C_chmayafarmer, *(f32 *)(arg0 + 0x38));
            break;
        case 0x40:
            ((struct FarmerState *)arg0)->count--;
            if ((s32)((struct FarmerState *)arg0)->count <= 0) {
                func_808001CC_chmayafarmer(arg0, 4);
            }
            break;
        case 0x3D:
            count = func_800CBC3C(D_8080126C_chmayafarmer);
            if ((s32)((struct FarmerState *)arg0)->count > 8) {
                ((struct FarmerState *)arg0)->count = 8;
            }
            for (i = 0; i < (s32)((struct FarmerState *)arg0)->count; i++) {
                func_800CD08C(count, D_8080126C_chmayafarmer);
                func_80108528(0x2F8, D_8080126C_chmayafarmer, (s32)func_800DC178(0.0f, 360.0f), &arg0)[15] = *(s32 *)arg0;
            }
            break;
    }
    return 1;
}

void func_80800520_chmayafarmer(Actor* arg0) 
{
    _suexpression_entrypoint_8(arg0, 1);
}
void func_80800540_chmayafarmer(Actor *arg0) {
#ifdef BT_NATIVE
    s32 func_80090178(s32);
#else
    s32 func_80090178(AllowedTransformation);
#endif
    s32 func_800DA9E4(s32, s32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 _subaddiedialog_entrypoint_3(f32 *, s32, s32, s32, s32);
    s32 _subaddiedialog_entrypoint_6(f32 *, s32, s32, s32, s32);
    void _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
    void _suexpression_entrypoint_10(u32 *, Unk80132ED0 *, BtUIntPtr);
    s32 _suexpression_entrypoint_12(void *, s32, s32);
    s32 func_800D0A9C(u32, u32);
    void *func_80100094(Actor *, u32);
    s32 func_80101E14(Actor *, f32);
    void func_8010D254(f32 *);
    extern u8 D_80801210_chmayafarmer[];
    extern u8 D_80801220_chmayafarmer[];
    f32 position[3];
    f32 *pos;

    func_8010D254(position);
    if (!arg0->unk64_19 && position[1] < 2000.0f) {
        arg0->unk64_16 = 0;
        return;
    }
    arg0->unk64_16 = 1;
    _suexpression_entrypoint_10(func_80100094(arg0, 1), arg0->unk0, 0);
    pos = arg0->position;
    _sudeflect_entrypoint_1(pos, 140.0f, 0.0f, 110.0f, 14);
    if (!arg0->unk74_30 && func_80090178(1) && !func_800D0A9C(4, 1)) {
        if (_subaddiedialog_entrypoint_3(pos, (s32)arg0->rotation[1], 350, 70, 6) && !func_800DA9E4(0x4D, 1)) {
            func_80800000_chmayafarmer(arg0, 2, 0);
            func_80800180_chmayafarmer((u8 *)arg0, 0xF06, 11);
        } else if (_subaddiedialog_entrypoint_6(pos, (s32)arg0->rotation[1], 350, 70, 6)) {
            func_80800180_chmayafarmer((u8 *)arg0, 0xF08, 11);
        }
    }
    switch (arg0->unk70_10) {
        case 1:
            if ((s32)arg0->unk74_7 <= 0) {
                func_808001CC_chmayafarmer((u8 *)arg0, 4);
            }
            break;
        case 3:
            arg0->unk54 *= 0.9f;
            if (func_80101E14(arg0, 0.06f) || func_80101E14(arg0, 0.8f)) {
                _subaddieaudioquick_entrypoint_2(arg0, pos, D_80801210_chmayafarmer);
            }
            if (func_80101E14(arg0, 0.999f)) {
                _suexpression_entrypoint_12(func_80100094(arg0, 1), 0x42A00000, 0x41F00000);
                if ((s32)arg0->unk74_7 <= 0) {
                    func_808001CC_chmayafarmer((u8 *)arg0, 4);
                } else {
                    func_808001CC_chmayafarmer((u8 *)arg0, 1);
                }
            }
            break;
        case 4:
            arg0->unk58 += 1.0f;
            if (arg0->unk58 > 120.0f) {
                func_808001CC_chmayafarmer((u8 *)arg0, 5);
            }
            if (func_80101E14(arg0, 0.75f)) {
                _subaddieaudioquick_entrypoint_2(arg0, pos, D_80801220_chmayafarmer);
            }
            break;
        case 5:
            if (func_80101E14(arg0, 0.75f)) {
                _subaddieaudioquick_entrypoint_2(arg0, pos, D_80801220_chmayafarmer);
            }
            break;
    }
}

/* extern */

void func_8080085C_chmayafarmer(void *arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 func_800D0A9C(u32, u32);
    Actor *actor = arg0;
    actor->scale = 0.375f;
    if (func_800D0A9C(4, 1) != 0) {
        actor->unk74_7 = 0;
        func_808001CC_chmayafarmer(arg0, 5);
    }
    if (_glcutDll_entrypoint_20() != 0) {
        actor->unk74_7 = 0;
        func_808001CC_chmayafarmer(arg0, 5);
        actor->unk64_19 = 1;
    }
}

OSThread *chmayafarmer_entrypoint_0(void)
{
    extern ActorData D_80801278_chmayafarmer[];

    return (OSThread *) D_80801278_chmayafarmer;
}

int func_808008F8_chmayafarmer(Actor *arg0, s32 arg1, BtIntPtr arg2) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_800EC398(s32 *, f32 *);
    void func_800EFCD8(f32 *, f32, f32);
    f32 func_800F1DF4(f32 *, f32 *);
    s32 func_8010114C(BtIntPtr, s32, BtIntPtr);
    void func_80102424(Actor *, s32);
    void func_8010A570(Actor *);
    extern s32 D_80801230_chmayafarmer[3];
    f32 sp2C[3];
    f32 angle;
    f32 *volatile sp24;

    if (arg1 == 0x40) {
        func_800EC398(arg2, sp2C);
        sp24 = arg0->position;
        angle = func_800F1DF4(sp2C, arg0->position);
        func_800EFCD8((f32 *)&arg0->actorData[4], angle, 25.0f);
        _subaddieaudioquick_entrypoint_2(arg0, sp24, D_80801230_chmayafarmer);
        func_80102424(arg0, 3);
        func_8010A570(arg0);
        func_8010114C(arg0->unk3C, arg1, arg2);
        arg1 = 1;
    } else {
        return 0;
    }
    return arg1;
}

typedef union {
    Actor actor;
    struct {
        u8 padding[0x70];
        BT_BITFIELD_ORDER(u32 group : 7, u32 unusedLow : 4);
        BT_BITFIELD_ORDER(u32 unused : 15, u32 point : 6);
        BT_BITFIELD_ORDER(u32 point : 6, u32 unused : 15);
        BT_BITFIELD_ORDER(u32 unusedLow : 4, u32 group : 7);
    } path;
} MayaFarmerActor;

void func_808009A0_chmayafarmer(Actor *arg0) {
    s32 _chbadshad_entrypoint_1(Actor *, f32 *, f32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void _subaddiefade_entrypoint_3(Actor *);
    s32 func_800DA9E4(s32, s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    s32 func_800EFFB4(f32 *, f32, f32 *);
    s32 func_8010114C(BtIntPtr, s32, BtIntPtr);
    s32 func_80101E14(Actor *, f32);
    void func_80102424(Actor *, s32);
    Actor *func_80106790(Unk80132ED0 *);
    void func_8010D254(f32 *);
    void func_80800D60_chmayafarmer(MayaFarmerActor *, Actor *);
    void func_80801040_chmayafarmer(Actor *);
    void func_808010DC_chmayafarmer(Actor *);
    extern s32 D_8080123C_chmayafarmer[4];
    Actor *sp44;
    f32 sp38[3];
    f32 sp2C[3];

    func_8010D254(sp38);
    if (sp38[1] < 2000.0f) {
        if (arg0->unk70_10 == 1 || arg0->unk70_10 == 2) {
            func_808010DC_chmayafarmer(arg0);
        }
        arg0->unk64_16 = 0;
        return;
    }
    arg0->unk64_16 = 1;
    sp44 = func_80106790(arg0->unk3C);
    if (func_800EFFB4(arg0->position, 500.0f, sp44->position)) {
        func_8010114C(arg0->unk3C, 0x11, 0);
    }
    switch (arg0->unk70_10) {
        case 1:
        case 2:
            if (func_800DA9E4(5, 0)) {
                func_808000B0_chmayafarmer(sp44, 0xF, 0x418, arg0->unk0);
            }
            func_80800D60_chmayafarmer((MayaFarmerActor *)arg0, sp44);
            func_800EF04C(arg0->position, (f32 *)&arg0->actorData[4]);
            func_808010DC_chmayafarmer(arg0);
            break;
        case 3:
            if (arg0->unk58 < arg0->position[1]) {
                func_80801040_chmayafarmer(arg0);
                func_808010DC_chmayafarmer(arg0);
            } else {
                ((f32 *)arg0->actorData)[5] = 0.0f;
                func_800EF04C(arg0->position, (f32 *)&arg0->actorData[4]);
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_8080123C_chmayafarmer);
                func_80102424(arg0, 4);
            }
            break;
        case 4:
            if (func_80101E14(arg0, 0.75f)) {
                _subaddiefade_entrypoint_3(arg0);
            }
            break;
    }
    func_800EE7F8(sp2C, arg0->position);
    sp2C[1] = 2608.0f;
    _chbadshad_entrypoint_1(arg0, sp2C, arg0->scale * 1.4f);
}



void func_80800B9C_chmayafarmer(MayaFarmerActor *arg0) {
    void *func_800CC63C(s32, s32);
    f32 func_800DC178(f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    struct {
        f32 position[3];
        s16 radius;
    } *sp24;
    f32 radius;
    f32 sp1C;
    f32 *volatile sp18;
    f32 *position;

    sp24 = func_800CC63C(arg0->path.group - 1, arg0->path.point - 1);
    position = arg0->actor.position;
    sp18 = position;
    func_800EE7F8(position, sp24->position);
    sp1C = func_800DC178(0.0f, 360.0f);
    radius = sp24->radius;
    func_800EF1B8(sp18, sp1C, func_800DC178(radius * 0.3f, radius));
    arg0->actor.unk58 = 2605.0f;
    arg0->actor.scale = 0.5f;
}

s32 func_80800C58_chmayafarmer(MayaFarmerActor *arg0) {
    s32 func_800CC338(f32 (*)[3], s32, s32);
    void func_800EEC30(f32 *, f32, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    f32 sp24[3];
    s32 result;

    func_800EEC30(sp24, arg0->actor.rotation[0], arg0->actor.rotation[1], 200.0f);
    func_800EF04C(sp24, arg0->actor.position);
    if (sp24[1] < arg0->actor.unk58 + 250.0f) {
        return 0;
    }
    result = func_800CC338(&sp24, arg0->path.group - 1, arg0->path.point - 1);
    if (result != -1) {
        arg0->path.point = result + 1;
        return 1;
    }
    return 0;
}

/* extern */

void func_80800D18_chmayafarmer(u8 *arg0) {
    void *func_800CC63C(s32, s32);
    void func_800EE7F8(f32 *, f32 *);
    u32 temp_v0;

    temp_v0 = (((Objmayafarmer_arg0 *)arg0)->unk70);
    func_800EE7F8(arg0 + 0x18, func_800CC63C((temp_v0 >> 0x19) - 1, ((u32) (temp_v0 << 0x16) >> 0x1A) - 1));
}

void func_80800D60_chmayafarmer(MayaFarmerActor *arg0, Actor *arg1) {
    f32 func_800DC0C0(void);
    f32 func_800DC178(f32, f32);
    void func_800EF4E4(f32 *, f32, f32, f32, f32, f32);
    f32 func_800F1828(f32 *, f32 *);
    f32 func_800F1DF4(f32 *, f32 *);
    void func_80102424(Actor *, s32);
    void func_80102B6C(u8 *, f32);
    s32 func_80102CF4(Actor *, s32);
    s32 func_80102D4C(u8 *, s32);

    switch (arg0->actor.unk70_10) {
    case 1:
        if (((f32 *)arg0->actor.actorData)[3] < 8.0f) {
            ((f32 *)arg0->actor.actorData)[3] += 1.0f;
        }
        if (func_80800C58_chmayafarmer(arg0) == 0) {
            func_80800D18_chmayafarmer(arg0->path.padding);
            func_80102424(&arg0->actor, 2);
        }
        if (func_800DC0C0() < 0.05f) {
            arg0->actor.unk50 = func_800DC178(-25.0f, 25.0f);
        }
        if (func_800DC0C0() < 0.05f) {
            arg0->actor.unk54 += func_800DC178(-90.0f, 90.0f);
        }
        break;
    case 2:
        if (func_80800C58_chmayafarmer(arg0) != 0) {
            func_80102424(&arg0->actor, 1);
        }
        if (((f32 *)arg0->actor.actorData)[3] > 6.0f) {
            ((f32 *)arg0->actor.actorData)[3] -= 2.0f;
        }
        arg0->actor.unk54 = func_800F1DF4(arg0->actor.position, (f32 *)arg0->actor.actorData);
        arg0->actor.unk50 = -func_800F1828(arg0->actor.position, (f32 *)arg0->actor.actorData);
        break;
    }
    if (func_80102CF4(&arg0->actor, 0x41800000) == 0) {
        if (arg0->actor.rotation[1] < arg0->actor.unk54) {
            if (arg0->actor.rotation[2] < 15.0f) {
                arg0->actor.rotation[2] += 1.0f;
            }
        } else {
            if (arg0->actor.rotation[2] > -15.0f) {
                arg0->actor.rotation[2] -= 1.0f;
            }
        }
    } else {
        arg0->actor.rotation[2] *= 0.75f;
    }
    if (arg1->unk6C_0 == 1) {
        ((f32 *)arg0->actor.actorData)[3] = 2.0f;
        arg0->actor.rotation[1] += arg0->actor.rotation[2] * 0.02f;
        arg0->actor.rotation[0] = 0.0f;
    } else {
        if (func_80102D4C(arg0->path.padding, 0x40000000) == 0) {
            func_80102B6C(arg0->path.padding, 2.0f);
        }
        arg0->actor.rotation[1] += arg0->actor.rotation[2] * 0.2f;
    }
    func_800EF4E4(&((f32 *)arg0->actor.actorData)[4], arg0->actor.rotation[0],
                 arg0->actor.rotation[1], 0.0f, 0.0f, ((f32 *)arg0->actor.actorData)[3]);
}

/* extern */

void func_80801040_chmayafarmer(Actor *arg0) {
    void func_800EF04C(f32 *, f32 *);
    void func_80102B2C(Actor *, f32);
    s32 func_80102CF4(Actor *, s32);
    int func_80102EC8(Actor *, f32 (*)[3]);
    if (func_80102EC8(arg0, &arg0->position) == 0) {
        ((f32 *)arg0->actorData)[6] = ((f32 *)arg0->actorData)[4] = 0.0f;
    }
    func_800EF04C(arg0->position, &((f32 *)arg0->actorData)[4]);
    ((f32 *)arg0->actorData)[5] -= 5.0f;
    if (arg0->position[1] < arg0->unk58) {
        arg0->position[1] = arg0->unk58;
    }
    if (func_80102CF4(arg0, 0x40C00000) == 0) {
        func_80102B2C(arg0, 4.0f);
    }
}

void func_808010DC_chmayafarmer(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_4(Actor*, f32*, u32, u32*);
    extern u32 D_808012E8_chmayafarmer[5];
    _subaddieaudioloop_entrypoint_4(arg0, &arg0->position[0], 1U, D_808012E8_chmayafarmer);
}

OSThread *chmayafarmer_entrypoint_1(void)
{
    extern ActorData D_808012FC_chmayafarmer[];

    return (OSThread *) D_808012FC_chmayafarmer;
}
/* data_to_c.py: from asm/data/overlays/ch/mayafarmer.data.s */
extern u8 D_808011E0_chmayafarmer[];
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
extern u8 D_808012C0_chmayafarmer[];
void func_80105834(Actor*);
OSThread *func_80108ED0(void);
u8 D_808011E0_chmayafarmer[48] BT_DATA(4, overlays_ch_mayafarmer, 0x0) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x40, 0x00, 0x00, 0x01, 0x97, 0x00, 0x01, 0x3F, 0x40, 0x00, 0x00, 0x01, 0x97, 0x00, 0x01, 0x40, 0xDC, 0xCC, 0xCD, 0x01, 0x9D, 0x00, 0x02, 0x3F, 0x66, 0x66, 0x66, 0x01, 0x98, 0x00, 0x01, 0x3F, 0x66, 0x66, 0x66, 0x01, 0x98, 0x00, 0x01 };
u8 D_80801210_chmayafarmer [16] BT_DATA(4, overlays_ch_mayafarmer, 0x30) = { 0, 0x13, 3, 0xFF, 0, 0xD, 0, 0xCC, 1, 0x66, 0, 0x16, 0x55, 0xF0, 0, 0 };
u8 D_80801220_chmayafarmer [16] BT_DATA(4, overlays_ch_mayafarmer, 0x40) = { 0, 0x13, 4, 2, 0, 0xA, 1, 0x99, 0, 0x16, 0x3E, 0x80, 0, 0, 0, 0 };
s32 D_80801230_chmayafarmer[3] BT_DATA(4, overlays_ch_mayafarmer, 0x50) = { 1246387, 1463792, 0 };
s32 D_8080123C_chmayafarmer[4] BT_DATA(4, overlays_ch_mayafarmer, 0x5C) = { 1246239, 655718, 1463792, 0 };
s32 D_8080124C_chmayafarmer[4] BT_DATA(4, overlays_ch_mayafarmer, 0x6C) = { 1142702080, 1136361472, 1132068864, 1135542272 };
s32 D_8080125C_chmayafarmer [4] BT_DATA(4, overlays_ch_mayafarmer, 0x7C) = { 1144750080, 1136361472, 1132068864, 1132068864 };
u8 D_8080126C_chmayafarmer [12] BT_DATA(4, overlays_ch_mayafarmer, 0x8C) = { 0x45, 0x52, 0x90, 0, 0x45, 0x3B, 0x80, 0, 0xC5, 0xB1, 0xC0, 0 };
ActorData D_80801278_chmayafarmer [1] BT_DATA(4, overlays_ch_mayafarmer, 0x98) = { { 560, 411, 1632, 1, (void *)D_808011E0_chmayafarmer, (void (*)(struct Actor *))func_80800540_chmayafarmer, 0, (void (*)(long, long))func_80101870, 229376000, 1084926635, 0, 0, 128, 352, (void (*)(struct Actor *))func_80800520_chmayafarmer, 0, 0, 0, (void (*)(struct Actor *))func_8080085C_chmayafarmer, (void (*)(void *, long, void *, long, void *))func_80107C2C, -31232, 25730, (void (*)(struct Actor *, long, long))func_80800228_chmayafarmer, 0 } };
u8 D_808012C0_chmayafarmer[40] BT_DATA(4, overlays_ch_mayafarmer, 0xE0) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x40, 0x00, 0x00, 0x01, 0x9E, 0x00, 0x01, 0x3F, 0x40, 0x00, 0x00, 0x01, 0x9E, 0x00, 0x01, 0x3E, 0xCC, 0xCC, 0xCD, 0x01, 0x9F, 0x00, 0x41, 0x3F, 0x66, 0x66, 0x66, 0x01, 0xA0, 0x00, 0x42 };
u32 D_808012E8_chmayafarmer[5] BT_DATA(4, overlays_ch_mayafarmer, 0x108) = { 0x13049B, 0x161388, 0xE00E6, 0x1190180, 0 };
ActorData D_808012FC_chmayafarmer [1] BT_DATA(4, overlays_ch_mayafarmer, 0x11C) = { { 701, 760, 1634, 1, (void *)D_808012C0_chmayafarmer, (void (*)(struct Actor *))func_808009A0_chmayafarmer, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 196608000, 0, 0, 0, 32, 13, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_80800B9C_chmayafarmer, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32224, 16512, (void (*)(struct Actor *, long, long))func_808008F8_chmayafarmer, 0 } };
