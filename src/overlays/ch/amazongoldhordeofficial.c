#include "common.h"

OSThread *chamazongoldhordeofficial_entrypoint_0(void)
{
    extern ActorData D_80801240_chamazongoldhordeofficial[];

    return (OSThread *) D_80801240_chamazongoldhordeofficial;
}

void func_8080000C_chamazongoldhordeofficial(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    void func_8010A3E8(void *, f32);
    void _subaddieDll_entrypoint_10(s32, void *);
    s32 _gccubesearch_entrypoint_9(s32, Prop **, s32);
    Prop *_gccubesearch_entrypoint_1(u32, f32 *);
    void _gspropctrl_entrypoint_11(Prop *, f32 *);
    void _susubgame_entrypoint_0(BtIntPtr arg0, u8 *arg1, s32 arg2);
    void _susubgame_entrypoint_12(void *arg0, void *arg1);
    s32 func_80800DB4_chamazongoldhordeofficial(Actor *, s32);
    extern s32 D_808011C0_chamazongoldhordeofficial[];
    struct HordeInitData {
        u8 pad0[8];
        s16 unk8;
        s16 unkA;
        s16 x[15];
        s16 z[15];
        u8 count;
        u8 ids[15];
        u8 flags[15];
        u8 pad67[3];
        s16 unk6A;
        u32 subgame[1];
    };
    Prop *props[15];
    struct HordeInitData *data;
    s32 i;

    data = func_80100094(arg0, 0);
    func_8010A3E8(arg0, 0.65f);
    _subaddieDll_entrypoint_10(0x125, data);
    data->unk8 = -999;
    data->unk6A = 1;
    data->count = _gccubesearch_entrypoint_9(0x122, props, 15);
    for (i = 0; i < data->count; i++) {
        data->x[i] = props[i]->position[0];
        data->z[i] = props[i]->position[2];
        data->ids[i] = props[i]->unk6_7;
        data->flags[i] = props[i]->FlagOrRotation >> 1;
    }
    func_80800DB4_chamazongoldhordeofficial(arg0, -1);
    _gspropctrl_entrypoint_11(_gccubesearch_entrypoint_1(0x127, arg0->position), (f32 *)arg0->actorData);
    _susubgame_entrypoint_0(arg0, ((struct HordeInitData *)func_80100094(arg0, 0))->subgame, 0);
    _susubgame_entrypoint_12(((struct HordeInitData *)func_80100094(arg0, 0))->subgame, D_808011C0_chamazongoldhordeofficial);
}

void func_80800150_chamazongoldhordeofficial(Actor *arg0) {
    void _subaddieDll_entrypoint_12(void *, s16 *);
    s32 _subaddieaudioquick_entrypoint_4(Actor *arg0, f32 *arg1, void *arg2, f32 *arg3);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    s32 _sudeflect_entrypoint_0(f32 *arg0, f32 arg1, f32 arg2, s32 arg3);
    void _suexpression_entrypoint_10(u32 *, Unk80132ED0 *, BtUIntPtr);
    void _susubgame_entrypoint_6(Actor *, void *, s32, s32, BtIntPtr);
    void func_8008F8B0(void);
    void func_8008F8D8(s32);
    void func_8008F904(s32 *, Unk80132ED0 *);
    void func_8008F990(f32 *, f32);
    s32 func_8008FE14(void);
    void func_800902E4(f32 *, f32, s32, Actor **);
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(void) func_80090768(f32 *);
    s32 func_80090818(void);
    f32 func_800D8FF8(void);
    void func_800DA544(s32 index);
    void func_800EEB9C(f32 *, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    BtIntPtr func_800F54E4(void);
    s32 func_800F56AC(BtIntPtr);
    f32 func_800F5F7C(BtIntPtr);
    s32 func_800F64A4(BtIntPtr, s32);
    void *func_80100094(Actor *, u32);
    s32 func_80101DDC(Actor *);
    void func_80102424(Actor *, s32);
    void func_80102924(void *, f32);
    void func_80102B2C(Actor *, f32);
    s32 func_80102CF4(Actor *, s32);
    f32 func_8010CD28(Actor *);
    void func_8010CEAC(Actor *);
    void func_80800A84_chamazongoldhordeofficial(Actor *);
    s32 func_80800C60_chamazongoldhordeofficial(BtIntPtr);
    void func_80800E18_chamazongoldhordeofficial(Actor *);
    void func_80800E64_chamazongoldhordeofficial(Actor *);
    void func_80800E94_chamazongoldhordeofficial(Actor *);
    int func_80800F40_chamazongoldhordeofficial(Actor *, s32, s32);
#ifdef BT_NATIVE
    void func_8010D5DC(void);
#else
    extern s32 func_8010D5DC;
#endif
    extern u32 D_80801288_chamazongoldhordeofficial[3];
    extern u32 D_80801294_chamazongoldhordeofficial[3];
    extern u32 D_808012A0_chamazongoldhordeofficial[7];
    extern u32 D_808012BC_chamazongoldhordeofficial[5];
    struct HordeUpdateData {
        u8 pad0[8];
        s16 unk8;
        s16 unkA;
        s16 x[15];
        s16 z[15];
        u8 count;
        u8 ids[15];
        u8 flags[15];
        u8 index;
        u8 pad68[2];
        s16 unk6A;
        u32 subgame[1];
    };
    struct HordeUpdateData *data;
    BtIntPtr character;
    f32 offset[3];
    f32 position[3];

    data = func_80100094(arg0, 0);
    _suexpression_entrypoint_10(func_80100094(arg0, 1), arg0->unk0, 0);
    _sudeflect_entrypoint_0(arg0->position, 150.0f, 150.0f, 10);
    switch (arg0->unk70_10) {
        case 1:
            func_80800E64_chamazongoldhordeofficial(arg0);
            if (data->unk8 == -999) {
                _subaddieDll_entrypoint_12(data, &data->unk8);
            }
            if (func_80800F40_chamazongoldhordeofficial(arg0, data->unk8, data->unkA)) {
                func_80800E18_chamazongoldhordeofficial(arg0);
            }
            func_80800C60_chamazongoldhordeofficial((BtIntPtr)arg0);
            break;
        case 2:
            func_80800E64_chamazongoldhordeofficial(arg0);
            if (func_80800F40_chamazongoldhordeofficial(arg0, data->x[data->index], data->z[data->index])) {
                func_80102424(arg0, 3);
            }
            func_80800C60_chamazongoldhordeofficial((BtIntPtr)arg0);
            break;
        case 3:
            func_80800E64_chamazongoldhordeofficial(arg0);
            func_80102924(arg0, data->flags[data->index] * 2);
            func_80102B2C(arg0, func_800D8FF8() * 180.0f);
            if (func_80102CF4(arg0, 0x41200000)) {
                func_80102424(arg0, 4);
            }
            func_80800C60_chamazongoldhordeofficial((BtIntPtr)arg0);
            break;
        case 4:
            _subaddieaudioquick_entrypoint_4(arg0, arg0->position, D_80801288_chamazongoldhordeofficial, D_808012A0_chamazongoldhordeofficial);
            _subaddieaudioquick_entrypoint_4(arg0, arg0->position, D_80801294_chamazongoldhordeofficial, D_808012BC_chamazongoldhordeofficial);
            func_80800A84_chamazongoldhordeofficial(arg0);
            if (func_80101DDC(arg0)) {
                func_80102424(arg0, 5);
            }
            func_80800C60_chamazongoldhordeofficial((BtIntPtr)arg0);
            break;
        case 5:
            func_80800E64_chamazongoldhordeofficial(arg0);
            func_80102924(arg0, data->flags[data->index] * 2 + data->unk6A * 120);
            func_80102B2C(arg0, func_800D8FF8() * 630.0f);
            if (func_80102CF4(arg0, 0x41200000)) {
                if (data->unk6A == 1) {
                    data->unk6A = -1;
                } else {
                    data->unk6A = 1;
                }
                func_80102424(arg0, 1);
            }
            func_80800C60_chamazongoldhordeofficial((BtIntPtr)arg0);
            break;
        case 6:
            func_80800C60_chamazongoldhordeofficial((BtIntPtr)arg0);
            func_80800E94_chamazongoldhordeofficial(arg0);
            break;
        case 7:
            func_8010CEAC(arg0);
            break;
        case 9:
            func_8010CEAC(arg0);
            break;
        case 10:
            character = func_800F54E4();
            func_8010CEAC(arg0);
            if (!arg0->unk64_19 && func_800F5F7C(character) < 10.0f && func_800F56AC(character) != 0x12 && func_800F64A4(character, 1)) {
                func_800EEB9C(offset, func_8010CD28(arg0), 400.0f);
                func_800EF04C(offset, arg0->position);
                func_8008F8B0();
                func_8008F904(&func_8010D5DC, arg0->unk0);
                func_8008F8D8(1);
                func_8008F990(offset, 300.0f);
                _susubgame_entrypoint_6(arg0, ((struct HordeUpdateData *)func_80100094(arg0, 0))->subgame, 0x12, 0x60, 0);
                func_80102424(arg0, 7);
                arg0->unk64_19 = 1;
            }
            break;
        case 11:
            func_8010CEAC(arg0);
            func_80800E94_chamazongoldhordeofficial(arg0);
            func_800902E4(arg0->position, 500.0f, 0x1D9, &arg0);
            if (func_8008FE14() == 0x1D9 && func_80090818()) {
                func_800EEB9C(position, func_8010CD28(arg0), 200.0f);
                func_800EF04C(position, arg0->position);
                func_80090768(position);
                func_800DA544(0x5A);
                _subaddiedialog_entrypoint_11(arg0->unk0, 0xF2D, 0xE, arg0->position, 0x31);
                func_80102424(arg0, 6);
            }
            break;
    }
}

void *_func_unused(void);
void *func_80100094(Actor *, u32);
void func_80800630_chamazongoldhordeofficial(Actor *arg0) { BT_NATIVE_ONLY(u8 _susubgame_entrypoint_2(BtIntPtr, u8 *);) _suexpression_entrypoint_8(arg0, 1); if (_susubgame_entrypoint_2(BT_NATIVE_ONLY((BtIntPtr)) arg0, (BT_IDO_ONLY(BtIntPtr) BT_NATIVE_ONLY(u8 *))func_80100094(arg0, 0) + 0x6C) != 0) { _susubgame_entrypoint_4(arg0, (BtIntPtr)func_80100094(arg0, 0) + 0x6C); } }

/* extern */

void func_80800690_chamazongoldhordeofficial(Actor *arg0) {
    void _gspropctrl_entrypoint_11(Prop*, f32[3]);
    s32 _gspropctrl_entrypoint_12(BtIntPtr);
    Prop *_gccubesearch_entrypoint_15(u32, u32, f32 *, Actor *);
    Prop *sp1C;
    sp1C = _gccubesearch_entrypoint_15(arg0->unk6C_9, arg0->pad6C_21, arg0->position, arg0);
    _gspropctrl_entrypoint_11(sp1C, arg0->position);
    arg0->rotation[1] = (f32) _gspropctrl_entrypoint_12((BtIntPtr) sp1C);
}

s32 func_808006F8_chamazongoldhordeofficial(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _capod_entrypoint_14(void);
    void _gcdialogcamera_entrypoint_3(f32 *arg0, f32 arg1);
    void _gcdialogcamera_entrypoint_5(BtIntPtr arg0);
    s32 _glcutDll_entrypoint_20(void);
    void _glcutDll_entrypoint_6(u32, u32);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    void *_suexpression_entrypoint_7(Actor *arg0, s32 arg1, s16 arg2);
    void _suexpression_entrypoint_12(void *arg0, f32 arg1, f32 arg2);
    s32 _susubgame_entrypoint_3(Actor *, void *, u32, u32);
    s32 _susubgame_entrypoint_5(BtIntPtr arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4);
    void _susubgame_entrypoint_6(Actor *, void *, s32, s32, BtIntPtr);
    void func_8008F8B0(void);
    void func_8008F8D8(s32);
    void func_8008F904(s32 *, Unk80132ED0 *);
    void func_8008F990(f32 *, f32);
    s32 func_8008FD48(void);
    void func_800904C8(s32);
    s32 func_800DA298(s32);
    s32 func_800EA090(void);
    void func_800EEB9C(f32 *, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);
    void func_80108B04(Actor *, u32);
    f32 func_8010CD28(Actor *);
    void func_80800690_chamazongoldhordeofficial(Actor *);
    int func_80800C18_chamazongoldhordeofficial(void);
    void func_80800CD8_chamazongoldhordeofficial(Actor *, s32, s32);
    void func_80800E18_chamazongoldhordeofficial(Actor *);
    void func_80801060_chamazongoldhordeofficial(Actor *);
    extern s32 D_808011C0_chamazongoldhordeofficial[];
#ifdef BT_NATIVE
    void func_8010D5DC(void);
#else
    extern s32 func_8010D5DC;
#endif
    f32 sp3C[3];
    f32 sp30[3];

    switch (arg1) {
        default:
            return 0;
        case 0x3D:
            func_80801060_chamazongoldhordeofficial(arg0);
            return 1;
        case 0x2E:
            func_80800CD8_chamazongoldhordeofficial(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
            return 1;
        case 0xB:
            if (arg2 == 4) {
                _capod_entrypoint_14();
                _glcutDll_entrypoint_6(0x119, 0x34);
                return 4;
            }
            return 3;
        case 0x52:
            func_800EFA4C(sp3C, 0.0f, func_8010CD28(arg0), 0.0f);
            _gcdialogcamera_entrypoint_3(D_808011C0_chamazongoldhordeofficial, arg0->scale);
            _gcdialogcamera_entrypoint_5(sp3C);
            return 1;
        case 0x57:
            return _susubgame_entrypoint_3(arg0, (u8 *)func_80100094(arg0, 0) + 0x6C, arg2 & 0xFFFF, (arg2 & 0xFFFF0000) >> 16);
        case 0x95:
            _suexpression_entrypoint_7(arg0, 1, 0x31);
            _suexpression_entrypoint_12(func_80100094(arg0, 1), 80.0f, 10.0f);
            if (func_800DA298(0x5A) || _glcutDll_entrypoint_20()) {
                func_80102424(arg0, 6);
                if (!_glcutDll_entrypoint_20()) {
                    func_80108B04(arg0, 0);
                }
                if (!func_800DA298(0x59C) && !_glcutDll_entrypoint_20()) {
                    _susubgame_entrypoint_5(arg0, (u8 *)func_80100094(arg0, 0) + 0x6C, 3, 1, 0x2000);
                    _subaddiedialog_entrypoint_11(*(Unk80132ED0 **)arg0, 0xF59, 0xE, &arg0->position[0], 0x31);
                }
            } else if (func_80800C18_chamazongoldhordeofficial() && func_8008FD48() == 1) {
                func_80800690_chamazongoldhordeofficial(arg0);
                func_80102424(arg0, 0xA);
            } else if (func_800EA090() == 1 && !func_800DA298(0x59C) && func_8008FD48() == 1) {
                func_80800690_chamazongoldhordeofficial(arg0);
                func_800EEB9C(sp30, arg0->rotation[1], 300.0f);
                func_800EF04C(sp30, &arg0->position[0]);
                func_8008F8B0();
                func_8008F904(&func_8010D5DC, *(Unk80132ED0 **)arg0);
                func_8008F8D8(1);
                func_8008F990(sp30, 300.0f);
                _susubgame_entrypoint_6(arg0, (u8 *)func_80100094(arg0, 0) + 0x6C, 0xF, 0x60, 0);
                func_80102424(arg0, 9);
            } else {
                func_80800E18_chamazongoldhordeofficial(arg0);
            }
            break;
        case 0x32:
            func_800904C8(0x8D);
            if (((u32)*(u16 *)((u8 *)arg0 + 0x72) >> 10) == 9) {
                _subaddiedialog_entrypoint_11(*(Unk80132ED0 **)arg0, 0xF0D, 0xE, &arg0->position[0], 0x31);
            } else {
                func_80102424(arg0, 0xB);
            }
            break;
    }
    return 1;
}

void func_80800A84_chamazongoldhordeofficial(Actor *arg0) {
    s32 _subaddieskeleton_entrypoint_2(Unk80132ED0 *, s32, f32 *);
    f32 func_800136E4(f32);
    void func_800BA22C(BtIntPtr, s32);
    void func_800BA670(BtIntPtr, s32);
    void func_800BA994(u8 *, s16, s16, s16, s16, s16, s16);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    s32 func_80101E14(Actor *, f32);
    extern s16 D_808012D0_chamazongoldhordeofficial[];
    extern f32 D_808012DC_chamazongoldhordeofficial[];
    extern s16 D_808012F4_chamazongoldhordeofficial[];
    extern s32 D_808012FC_chamazongoldhordeofficial[];
    f32 angles[2];
    f32 position[3];
    u32 i;
    BtIntPtr emitter;

    if (arg0->unk7C_12) {
        for (i = 0; i < 6; i++) {
            if (func_80101E14(arg0, D_808012DC_chamazongoldhordeofficial[i])) {
                _subaddieskeleton_entrypoint_2(arg0->unk0, D_808012D0_chamazongoldhordeofficial[i], position);
                angles[0] = func_800136E4(arg0->rotation[1] + 180.0f - 45.0f);
                angles[1] = func_800136E4(angles[0] + 90.0f);
                for (i = 0; D_808012F4_chamazongoldhordeofficial[i] != -1; i++) {
                    emitter = func_800BABB8(0, position, NULL, 1.0f, D_808012FC_chamazongoldhordeofficial);
                    func_800BA994((u8 *)emitter, 0x118, (s16)(s32)angles[0], 0x258, 0x140, (s32)angles[1], 0x320);
                    func_800BA670(emitter, D_808012F4_chamazongoldhordeofficial[i]);
                    func_800BA22C(emitter, 2);
                }
                break;
            }
        }
    }
}

int func_80800C18_chamazongoldhordeofficial(void) {
    BtIntPtr func_800F54E4(); s32 func_800F640C(BtIntPtr,s32); s32 func_8008FE14();
    return func_800F640C(func_800F54E4(), 0x1D9) || func_8008FE14() == 0x1D9;
}

s32 func_80800C60_chamazongoldhordeofficial(BtIntPtr arg0) {
    s32 _subaddiedialog_entrypoint_7(BtIntPtr, BtIntPtr, s32 *);
    s32 func_800DA298(s32);
    BtIntPtr func_800F54E4();
    s32 func_800F56AC(BtIntPtr);
    extern s32 D_80801324_chamazongoldhordeofficial[7];
    extern s32 D_80801340_chamazongoldhordeofficial[7];
    if (func_800F56AC(func_800F54E4()) == 0x12) {
        return 0;
    }
    if (func_800DA298(0x5A) != 0) {
        return _subaddiedialog_entrypoint_7(arg0, arg0 + 4, D_80801340_chamazongoldhordeofficial);
    }
    return _subaddiedialog_entrypoint_7(arg0, arg0 + 4, D_80801324_chamazongoldhordeofficial);
}

void func_80800CD8_chamazongoldhordeofficial(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    void func_800D1000(u32 arg0, u32 arg1, f32* arg2, u32 arg3, Unk80132ED0* arg4);
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    void func_800DA544(s32 index);
    void _glcutDll_entrypoint_6(u32, u32);
    void func_80800E18_chamazongoldhordeofficial(Actor *);
    switch (arg1) {
        case 0xF2D:
            _susubgame_entrypoint_4(arg0, (BtIntPtr)((u8 *)func_80100094(arg0, 0) + 0x6C));
            func_800D1000(5, 1, NULL, 1, 0);
            _capod_entrypoint_13(arg0->unk0, NULL, 4, 0x2830);
            return;
        case 0xF0D:
        case 0xF59:
            _susubgame_entrypoint_4(arg0, (BtIntPtr)((u8 *)func_80100094(arg0, 0) + 0x6C));
            func_800DA544(0x59C);
            _glcutDll_entrypoint_6(0xB8, 0xD);
            return;
        default:
            func_80800E18_chamazongoldhordeofficial(arg0);
        case 0xF2E:
            return;
    }
}

 s32 func_80800DB4_chamazongoldhordeofficial(Actor *arg0, s32 arg1) {
    u8 *temp_s0;
    s32 temp_v0;
    temp_s0 = func_80100094(arg0, 0);
    do {
        temp_v0 = func_800DC128(0, temp_s0[0x48] - 1);
        temp_s0[0x67] = temp_v0;
    } while (arg1 == (temp_v0 & 0xFF));
    *(f32 *)&arg0->actorData[3] = 700.0f; BT_NATIVE_ONLY(return temp_v0;)
}    typedef struct { u8 pad0[0x8]; s16 unk8; } Objamazongoldhordeofficial_func_80800E18_chamazongoldhordeofficial_sp1C; /* offsets.py genstruct: fields from raw offsets on sp1C; rename once understood */ typedef struct { u8 pad0[0x67]; u8 unk67; } Objamazongoldhordeofficial_func_80800E18_chamazongoldhordeofficial_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

void func_80800E18_chamazongoldhordeofficial(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    void func_80102424(Actor*, s32);
    s32 func_80800DB4_chamazongoldhordeofficial(Actor *, s32);
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    sp1C = temp_v0;
    func_80800DB4_chamazongoldhordeofficial(arg0, (((Objamazongoldhordeofficial_func_80800E18_chamazongoldhordeofficial_temp_v0 *)temp_v0)->unk67));
    func_80102424(arg0, 2);
    (((Objamazongoldhordeofficial_func_80800E18_chamazongoldhordeofficial_sp1C *)sp1C)->unk8) = -0x3E7;
}

s32 _subaddieaudioquick_entrypoint_4(Actor *arg0, f32 *arg1, void *arg2, f32 *arg3);

void func_80800E64_chamazongoldhordeofficial(Actor *arg0) {
    extern u32 D_808011D0_chamazongoldhordeofficial[4];
    extern u32 D_8080135C_chamazongoldhordeofficial[3];
    _subaddieaudioquick_entrypoint_4(arg0, arg0->position, D_808011D0_chamazongoldhordeofficial, D_8080135C_chamazongoldhordeofficial);
}

void func_80800E94_chamazongoldhordeofficial(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 _glcutDll_entrypoint_20();
    s32 func_80101E14(Actor *, f32);
    void *func_80100094(Actor *, u32);
    extern u32 D_808011D0_chamazongoldhordeofficial[4];
    extern u32 D_80801368_chamazongoldhordeofficial[6];
    extern u32 D_80801380_chamazongoldhordeofficial[4];
    struct HordeData {
        u8 pad[0x68];
        u8 counter;
    } *data;
    _subaddieaudioquick_entrypoint_4(arg0, arg0->position, D_808011D0_chamazongoldhordeofficial, D_80801368_chamazongoldhordeofficial);
    if (func_80101E14(arg0, 0.5f)) {
        data = func_80100094(arg0, 0U);
        data->counter++;
        if ((_glcutDll_entrypoint_20() ? 1 : 5) < data->counter) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80801380_chamazongoldhordeofficial);
            data->counter = 0;
        }
    }
}

int func_80800F40_chamazongoldhordeofficial(Actor *arg0, s32 arg1, s32 arg2) {
    f32 func_800D8FF8(void);
    int func_800F0064(f32 *, f32, f32 *);
    void func_80102924(void *, f32);
    void func_80102B2C(Actor *, f32);
    s32 func_80102CF4(Actor *, s32);
    f32 func_80102D78(Actor *, f32 *);
    s32 func_8010B990(Actor *, s32);
    f32 target[3];
    f32 speed;
    int near;

    target[0] = arg1;
    target[1] = arg0->position[1];
    target[2] = arg2;
    if (func_800F0064(arg0->position, 200.0f, target)) {
        speed = func_800D8FF8() * 630.0f;
    } else {
        speed = func_800D8FF8() * 180.0f;
    }
    func_80102924(arg0, func_80102D78(arg0, target));
    func_80102B2C(arg0, speed);
    near = func_800F0064(arg0->position, 80.0f, target);
    if (!near) {
        func_8010B990(arg0, 0x201005);
    }
    return func_80102CF4(arg0, 0x41200000) && near;
}

/* extern */

void func_80801060_chamazongoldhordeofficial(Actor *arg0) {
    void func_800EEB9C(f32[3], f32, f32);
    void func_800EF04C(f32 *, f32 *);
    f32 func_800F1DCC(f32, f32);
    Actor *func_80108528(s32, f32[3], s32, Actor **);
    f32 sp1C[3];
    Actor *sp18;

    func_800EEB9C(sp1C, arg0->rotation[1], 200.0f);
    func_800EF04C(sp1C, arg0->position);
    sp18 = func_80108528(0x1D9, sp1C, 0, &arg0);
    sp18->rotation[1] = func_800F1DCC(arg0->rotation[1], 180.0f);
}
/* data_to_c.py: from asm/data/overlays/ch/amazongoldhordeofficial.data.s */
extern u8 D_808011E0_chamazongoldhordeofficial[];
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
s32 D_808011C0_chamazongoldhordeofficial [4] BT_DATA(4, overlays_ch_amazongoldhordeofficial, 0x0) = { 1130758144, 1125515264, 1120403456, 1120403456 };
u32 D_808011D0_chamazongoldhordeofficial[4] BT_DATA(4, overlays_ch_amazongoldhordeofficial, 0x10) = { 0x1304BC, 0xD00D9, 0x1260016, 0x3A980000 };
u8 D_808011E0_chamazongoldhordeofficial[96] BT_DATA(4, overlays_ch_amazongoldhordeofficial, 0x20) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x19, 0x99, 0x9A, 0x01, 0xB4, 0x00, 0x01, 0x3F, 0x19, 0x99, 0x9A, 0x01, 0xB4, 0x00, 0x01, 0x3F, 0x19, 0x99, 0x9A, 0x01, 0xB4, 0x00, 0x01, 0x40, 0xE0, 0x00, 0x00, 0x01, 0xB5, 0x00, 0x02, 0x3F, 0x19, 0x99, 0x9A, 0x01, 0xB4, 0x00, 0x01, 0x40, 0x40, 0x00, 0x00, 0x01, 0xB6, 0x00, 0x01, 0x40, 0xC3, 0x33, 0x33, 0x03, 0xE3, 0x00, 0x01, 0x3F, 0x33, 0x33, 0x33, 0x01, 0xD6, 0x00, 0x01, 0x40, 0xC3, 0x33, 0x33, 0x03, 0xE3, 0x00, 0x01, 0x40, 0xC3, 0x33, 0x33, 0x03, 0xE3, 0x00, 0x01, 0x40, 0xC3, 0x33, 0x33, 0x03, 0xE3, 0x00, 0x01 };
ActorData D_80801240_chamazongoldhordeofficial [1] BT_DATA(4, overlays_ch_amazongoldhordeofficial, 0x80) = { { 350, 277, 1643, 2, (void *)D_808011E0_chamazongoldhordeofficial, (void (*)(struct Actor *))func_80800150_chamazongoldhordeofficial, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 1073741824, 0, 0, 0, 352, (void (*)(struct Actor *))func_80800630_chamazongoldhordeofficial, 0, 132, 0, (void (*)(struct Actor *))func_8080000C_chamazongoldhordeofficial, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 130, (void (*)(struct Actor *, long, long))func_808006F8_chamazongoldhordeofficial, 0 } };
u32 D_80801288_chamazongoldhordeofficial[3] BT_DATA(4, overlays_ch_amazongoldhordeofficial, 0xC8) = { 0x1304B8, 0x167FF8, 0 };
u32 D_80801294_chamazongoldhordeofficial[3] BT_DATA(4, overlays_ch_amazongoldhordeofficial, 0xD4) = { 0x1304B9, 0x167FF8, 0 };
u32 D_808012A0_chamazongoldhordeofficial[7] BT_DATA(4, overlays_ch_amazongoldhordeofficial, 0xE0) = { 0x3E99999A, 0x3EBC6A7F, 0x3EE353F8, 0x3F051EB8, 0x3F19999A, 0x3F2B851F, 0xBF800000 };
u32 D_808012BC_chamazongoldhordeofficial[5] BT_DATA(4, overlays_ch_amazongoldhordeofficial, 0xFC) = { 0x3EBAE148, 0x3EE66666, 0x3F08F5C3, 0x3F1EB852, 0xBF800000 };
s16 D_808012D0_chamazongoldhordeofficial [6] BT_DATA(4, overlays_ch_amazongoldhordeofficial, 0x110) = { 4, 5, 4, 5, 4, 5 };
f32 D_808012DC_chamazongoldhordeofficial [6] BT_DATA(4, overlays_ch_amazongoldhordeofficial, 0x11C) = { 0.33f, 0.4f, 0.478f, 0.55f, 0.63f, 0.7f };
s16 D_808012F4_chamazongoldhordeofficial [4] BT_DATA(4, overlays_ch_amazongoldhordeofficial, 0x134) = { 1626, 1627, 1628, -1 };
s32 D_808012FC_chamazongoldhordeofficial [10] BT_DATA(4, overlays_ch_amazongoldhordeofficial, 0x13C) = { 34603035, -137562164, 2753280, 50332416, 50331669, 131074, 458754, 327680, 262297, 0 };
s32 D_80801324_chamazongoldhordeofficial[7] BT_DATA(4, overlays_ch_amazongoldhordeofficial, 0x164) = { 500, 3887, 513, 257425408, 3211264, 786432, 117440512 };
s32 D_80801340_chamazongoldhordeofficial[7] BT_DATA(4, overlays_ch_amazongoldhordeofficial, 0x180) = { 5898740, 3886, 513, 302514176, 3211264, 786432, 0 };
u32 D_8080135C_chamazongoldhordeofficial[3] BT_DATA(4, overlays_ch_amazongoldhordeofficial, 0x19C) = { 0x3ED70A3D, 0x3F6B851F, 0xBF800000 };
u32 D_80801368_chamazongoldhordeofficial[6] BT_DATA(4, overlays_ch_amazongoldhordeofficial, 0x1A8) = { 0x3E4CCCCD, 0x3EAE147B, 0x3EF5C28F, 0x3F23D70A, 0x3F4CCCCD, 0xBF800000 };
u32 D_80801380_chamazongoldhordeofficial[4] BT_DATA(4, overlays_ch_amazongoldhordeofficial, 0x1C0) = { 0x130612, 0xD010C, 0x1260000, 0 };
