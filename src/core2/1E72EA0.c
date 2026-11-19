#include "core2/1E72EA0.h"

s32 func_800995B0(void) {
    return sizeof(BaUnknownC0);
}

void func_800995B8(PlayerState *arg0, s32 arg1) {
    void func_8008FE68(f32 *);
    f32 func_80090010(void);
    void func_800A34AC(PlayerState *, f32[3]);
    void func_800A34CC(void *, s32);
    void func_800EC398(Unk80132ED0 *, f32 *);
    void func_800EFCD8(f32 *, f32, f32);
    f32 position[3];
    f32 offset[3];

    func_800A34CC(arg0, 1);
    switch (arg1) {
        case 0:
            func_800EC398(arg0->unkC0->unk14, position);
            func_800A34AC(arg0, position);
            break;
        case 1:
            func_800A34AC(arg0, arg0->unkC0->pad8);
            break;
        case 2:
            func_8008FE68(position);
            func_800EFCD8(offset, func_80090010(), 100.0f);
            offset[1] = 0.0f;
            position[0] += offset[0];
            position[1] += offset[1];
            position[2] += offset[2];
            func_800A34AC(arg0, position);
            func_800A34CC(arg0, arg0->unkC0->unk1C);
            break;
        case 3:
            func_800A34AC(arg0, arg0->unkC0->pad8);
            break;
    }
}

/* extern */

s32 func_800996E0(BtIntPtr arg0) {
    s32 func_800A1718();
    void func_800A17A8(PlayerState *, s32);
    s32 temp_v0;

    temp_v0 = func_800A1718();
    if (temp_v0 < 2) {
        func_800A17A8(arg0, -temp_v0);
        return 0;
    }
    func_800A17A8(arg0, 1 - temp_v0);
    return 1;
}

s32 func_80099730(PlayerState *arg0, s32 arg1) {
    void func_8009AD20(void *, s32);
    void func_800A17A8(PlayerState *, s32);
    s32 func_800A1718(PlayerState *);
    s32 _badata_entrypoint_20(PlayerState *);
    s32 _badata_entrypoint_26(PlayerState *);

    func_8009AD20(arg0, 0xD);
    func_800995B8(arg0, 2);
    if (arg1 != 0) {
        func_800996E0(arg0);
    } else {
        func_800A17A8(arg0, -1);
    }
    if (func_800A1718(arg0) != 0) {
        return _badata_entrypoint_26(arg0);
    }
    return _badata_entrypoint_20(arg0);
}

void func_800997BC(PlayerState *arg0) {
    void func_8009C128(PlayerState *, f32[3]);
    void func_800A17A8(PlayerState *, s32);
    void func_800A34AC(PlayerState *, f32[3]);
    void func_800EEB9C(f32[3], f32, f32);
    f32 yaw_get(PlayerState *);
    f32 offset[3];
    f32 position[3];

    func_8009C128(arg0, position);
    func_800EEB9C(offset, yaw_get(arg0), 100.0f);
    position[0] += offset[0];
    position[1] += offset[1];
    position[2] += offset[2];
    func_800A34AC(arg0, position);
    func_800A17A8(arg0, -1);
}

/* extern */

s32 func_80099840(PlayerState *arg0, s32 arg1) {
    s32 _badata_entrypoint_20(PlayerState *);
    s32 _badata_entrypoint_26(PlayerState *);
    s32 func_800A1718(PlayerState *);
    s32 temp_v0;
    s32 var_a0;

    temp_v0 = func_800A1718(arg0);
    var_a0 = arg1 == 0;
    if (var_a0 != 0) {
        var_a0 = temp_v0 != 0;
    }
    if (var_a0 != 0) {
        return _badata_entrypoint_26(arg0);
    }
    return _badata_entrypoint_20(arg0);
}

/* extern */

void func_8009989C(PlayerState *arg0, s32 arg1) {
    void func_800EE7F8(f32 *, f32 *);
    struct Saved { f32 x, y, vec[3]; s32 a, b, c, d, id; };
    s32 i;
    for (i = 0; i < 5; i++) {
        if (((struct Saved *)arg0->unkC0)[i + 1].id == arg1) return;
    }
    for (i = 0; i < 5; i++) {
        if (((struct Saved *)arg0->unkC0)[i + 1].id == 0) {
            ((struct Saved *)arg0->unkC0)[i + 1].id = arg1;
            ((struct Saved *)arg0->unkC0)[i + 1].b = arg0->unkC0->unk18;
            ((struct Saved *)arg0->unkC0)[i + 1].x = arg0->unkC0->unk0;
            ((struct Saved *)arg0->unkC0)[i + 1].y = arg0->unkC0->unk4;
            ((struct Saved *)arg0->unkC0)[i + 1].a = arg0->unkC0->unk14;
            func_800EE7F8(((struct Saved *)arg0->unkC0)[i + 1].vec, &arg0->unkC0->pad8[0]);
            return;
        }
    }
}

void func_80099970(PlayerState *arg0) {
    void func_8009ACF4(void *, f32);
    void func_8009AD04(void *, f32);
    void func_8009AD14(void *, BtIntPtr);
    void func_8009AD20(void *, s32);
    void func_8009AD44(PlayerState *, f32 *);
    s32 func_8009E7C8(PlayerState *, s32);
    s32 temp_a1;
    s32 offset;
    u8 *entry;

    entry = (u8 *)arg0->unkC0;
    offset = 0;
    do {
        if (*(s32 *)(entry + 0x4C) != 0) {
            func_8009ACF4(arg0, *(f32 *)(entry + 0x28));
            func_8009AD04(arg0, *(f32 *)((u8 *)arg0->unkC0 + offset + 0x2C));
            func_8009AD14(arg0, *(s32 *)((u8 *)arg0->unkC0 + offset + 0x3C));
            func_8009AD20(arg0, *(s32 *)((u8 *)arg0->unkC0 + offset + 0x40));
            func_8009AD44(arg0, (f32 *)((u8 *)arg0->unkC0 + offset + 0x30));
            entry = (u8 *)arg0->unkC0 + offset;
            temp_a1 = *(s32 *)(entry + 0x4C);
            *(s32 *)(entry + 0x4C) = 0;
            func_8009E7C8(arg0, temp_a1);
            return;
        }
        offset += 0x28;
        entry += 0x28;
    } while (offset != 0xC8);
}

f32 func_80099A34(PlayerState *self) {
    return self->unkC0->unk0;
}

f32 func_80099A40(PlayerState *self) {
    return self->unkC0->unk4;
}

BtIntPtr func_80099A4C(PlayerState *self) {
    return self->unkC0->unk14;
}

s32 func_80099A58(PlayerState *self) {
    return self->unkC0->unk18;
}

s32 func_80099A64(PlayerState *self) {
    return self->unkC0->unk1C;
}

s32 func_80099A70(PlayerState *self) {
    return self->unkC0->unk20;
}


void func_80099A7C(PlayerState *arg0, f32 *arg1) { void func_800EE7F8(f32 *, f32 *); func_800EE7F8(arg1, arg0->unkC0->pad8); return; }

void func_80099AA8(PlayerState *arg0) {
    s32 func_8009E6EC(PlayerState *);
    void func_8009E830(PlayerState *, s32);
    void bs_setState(PlayerState *, s32);
    s32 state = func_8009E6EC(arg0);

    switch (state) {
        case 0xF:
        case 0x13:
        case 0x26:
        case 0x2A:
        case 0x30:
            func_8009989C(arg0, state);
            break;
        case 0x27:
        case 0x31:
        case 0x32:
        case 0x33:
        case 0x4D:
        case 0x62:
        case 0x63:
        case 0x6B:
        case 0x6C:
        case 0x7C:
        case 0x7D:
        case 0x81:
        case 0x89:
        case 0x91:
        case 0x98:
        case 0x9A:
            func_80099B94(arg0);
            return;
    }
    func_8009E830(arg0, 1);
    bs_setState(arg0, 0);
}

/* extern */

s32 func_80099B54(PlayerState *arg0) {
    s32 _badata_entrypoint_33(PlayerState *);
    void func_8009EAE8(s32 arg0);
    void *func_80106790(BtIntPtr);
    func_8009EAE8((u32) ((*(s32 *)((s8 *)(func_80106790(func_80099A4C(arg0))) + (0x6C))) << 0xB) >> 0x14);
    return _badata_entrypoint_33(arg0);
}

/* extern */

void func_80099B94(PlayerState *arg0) {
    void func_8009AD20(void *, s32);
    void _bababykaz_entrypoint_14(PlayerState *);
    void _babounce_entrypoint_7(PlayerState *self, BtIntPtr arg1);
    void _bacough_entrypoint_4(PlayerState *, s32);
    s32 _badata_entrypoint_24(PlayerState *);
    s32 _badata_entrypoint_26(PlayerState *);
    s32 _badata_entrypoint_27(PlayerState *);
    s32 _badata_entrypoint_29(PlayerState *);
    s32 _badata_entrypoint_31(PlayerState *);
    s32 _badata_entrypoint_32(PlayerState *);
    s32 _badata_entrypoint_34(PlayerState *);
    s32 _badeathmatch_entrypoint_4(s32);
    s32 _badeathmatch_entrypoint_5(u8 *arg0, s32 arg1, s32 arg2);
    s32 _badrone_entrypoint_17(PlayerState *);
    s32 _badrone_entrypoint_18(PlayerState *, Unk80132ED0 *);
    s32 _badrone_entrypoint_19(PlayerState *);
    s32 _badrone_entrypoint_20(PlayerState *, f32 *, s32);
    s32 _badrone_entrypoint_21(PlayerState *);
    s32 _badrone_entrypoint_22(PlayerState *, f32 *);
    s32 _badrone_entrypoint_24(PlayerState *);
    s32 _badrone_entrypoint_26(PlayerState *);
    s32 _badrone_entrypoint_27(PlayerState *);
    s32 _badrone_entrypoint_28(PlayerState *);
    void _baduo_entrypoint_10(PlayerState *, s32);
    void _baduo_entrypoint_11(PlayerState *, s32);
    void _baduo_entrypoint_15(PlayerState *, f32 *);
    void _baduo_entrypoint_17(void *arg0, BtIntPtr arg1);
    void _baduo_entrypoint_18(PlayerState *arg0, BtIntPtr arg1);
    void _baduo_entrypoint_19(PlayerState *);
    void _baduo_entrypoint_20(PlayerState *arg0, BtIntPtr arg1, f32 arg2);
    void _baduo_entrypoint_7(PlayerState *, s32);
    void _baduo_entrypoint_8(PlayerState *, f32 *);
    void _baduo_entrypoint_9(PlayerState *, f32);
    void _bafpctrl_entrypoint_11(PlayerState *, s32, s32);
    void _bafpctrl_entrypoint_13(PlayerState *, s32);
    void _bafpctrl_entrypoint_19(PlayerState *);
    s32 _bafpctrl_entrypoint_4(PlayerState *);
    void _bainvisible_entrypoint_5(PlayerState *, f32);
    void _bashoes_entrypoint_12(PlayerState *, f32);
    void _basquash_entrypoint_3(PlayerState *, s32);
    void _basudie_entrypoint_0(PlayerState *);
    void _basudie_entrypoint_1(PlayerState *);
    void _bsfirstp_entrypoint_26(PlayerState *);
    s32 _gcegg_entrypoint_7(s32);
    s32 _plsu_entrypoint_1(s32);
    s16 _suegg_entrypoint_6(Unk80132ED0 *, f32 *, s32 *);
    void baflag_clear(PlayerState *, s32);
    s32 baflag_isTrue(PlayerState *, s32);
    void baflag_set(PlayerState *, s32);
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    s32 bs_getCurrentState(PlayerState *);
    void bs_setState(PlayerState *, s32);
    s32 func_8008D630(PlayerState *);
    s32 func_8008DAA8(PlayerState *);
    s32 func_8008DD70(PlayerState *);
    s32 func_8008DD90(PlayerState *);
    s32 func_8008E124(PlayerState *);
    s32 func_8008E23C(PlayerState *);
    s32 func_8008E974(PlayerState *);
    void func_8008ED88(void *arg0, BtIntPtr arg1, Unk80132ED0 *arg2);
    s32 func_8008FD48();
    void func_8009337C(PlayerState *, s32);
    void func_80094430(PlayerState *, f32);
    s32 func_80094574(void *arg0, s32 arg1);
    void func_800956B8(PlayerState *);
    void func_8009BA9C(PlayerState *, f32 *);
    s32 func_8009BD44(PlayerState *);
    s32 func_8009CA70(PlayerState *, s32, s32);
    s16 func_8009CBDC(PlayerState *arg0, s32 arg1);
    s32 func_8009CC68(PlayerState *);
    s32 func_8009E674(PlayerState *, s32);
    s32 func_8009E6EC(PlayerState *);
    s32 func_8009E71C(PlayerState *, s32);
    void func_8009E830(PlayerState *, s32);
    void func_8009EB24(s16, s16);
    void func_8009EBD0();
    s32 func_8009EC08(s16 *, s16 *);
    s32 func_8009F354(PlayerState *);
    void func_800A05DC(PlayerState *);
    void func_800A0CF4(PlayerState *, s32);
    s32 func_800A1718(PlayerState *);
    void func_800A17A8(PlayerState *, s32);
    s32 func_800A3274(PlayerState *);
    s32 func_800A3404(PlayerState *);
    void func_800A3410(PlayerState *, s32);
    void func_800A3544(PlayerState *, s32);
    void func_800A3904(PlayerState *, s32);
    void func_800A391C(PlayerState *, f32);
    s32 func_800A3970(PlayerState *, s32);
    s32 func_800A9420(s32);
    BT_IDO_ONLY(void func_800D175C(s32, s32);) BT_NATIVE_ONLY(s32 func_800D175C(s32, s32);)
    s32 func_800F40EC(PlayerState *);
    s32 func_800F64A4(BtIntPtr, s32);
    void func_800F7B9C(BtIntPtr, s32);
    void func_800F911C(s32);
    s32 func_8010114C(BtIntPtr, s32, BtIntPtr);
    void func_80101180(s32, s32, BtIntPtr);
    s32 player_inWater(PlayerState *);
    s32 player_isStable(PlayerState *);
    s32 var_s1;
    s32 sp68;
    BaUnknownC0 *temp_v0_10;
    BaUnknownC0 *temp_v0_11;
    BaUnknownC0 *temp_v0_5;
    s16 temp_v0_7;
    s32 temp_v0;
    f32 sp48[3];
    s32 sp44;
    BtIntPtr sp40;
    s16 sp3C[2];
    s16 sp38[2];
    s32 var_a1;
    s32 var_s2;

    var_s1 = 1;
    var_s2 = 0;
    sp68 = bs_getCurrentState(arg0);
    temp_v0 = func_8009E6EC(arg0);
    switch (temp_v0) {                              /* switch 1 */
    case 0x39:                                      /* switch 1 */
        baflag_set(arg0, 0x25);
        baflag_set(arg0, 0x2E);
        baflag_set(arg0, 0x24);
        var_s2 = _badrone_entrypoint_24(arg0);
        var_s1 = 2;
        goto block_180;
    case 0x5E:                                      /* switch 1 */
        baflag_set(arg0, 0x25);
        baflag_set(arg0, 0x3A);
        baflag_set(arg0, 0x24);
        _bafpctrl_entrypoint_11(arg0, 6, 1);
        var_s2 = _badrone_entrypoint_24(arg0);
        var_s1 = 2;
        goto block_180;
    case 0x69:                                      /* switch 1 */
        baflag_set(arg0, 0x24);
        if (func_8009E71C(arg0, 9) != 0) {
            baflag_set(arg0, 0x2F);
            baflag_set(arg0, 0x30);
            _bafpctrl_entrypoint_11(arg0, 0xE, 1);
            var_s1 = 2;
        } else {
            var_s2 = _badrone_entrypoint_24(arg0);
            var_s1 = 2;
        }
        goto block_180;
    case 0xA:                                       /* switch 1 */
        var_s1 = 2;
        var_s2 = _badrone_entrypoint_28(arg0);
        goto block_180;
    case 0x51:                                      /* switch 1 */
        if (func_8008DD90(arg0) == 0) {
            func_8009AD20(arg0, 1);
        case 0x6A:                                  /* switch 1 */
            temp_v0 = func_80099A58(arg0);
            if (temp_v0 != 0) {
                func_800A17A8(arg0, -temp_v0);
            }
            if (func_800A1718(arg0) == 0) {
                var_s2 = func_80099840(arg0, 1);
                var_s1 = 2;
            } else {
                var_s2 = _badrone_entrypoint_17(arg0);
                var_s1 = 2;
            }
        }
        goto block_180;
    case 0x52:                                      /* switch 1 */
        temp_v0 = func_80099A58(arg0);
        if (temp_v0 != 0) {
            func_800A17A8(arg0, -temp_v0);
        }
        if (func_800A1718(arg0) == 0) {
            var_s2 = func_80099840(arg0, 1);
            var_s1 = 2;
        } else {
            var_s2 = _badrone_entrypoint_20(arg0, arg0->unkC0->pad8, 2);
            var_s1 = 2;
        }
        goto block_180;
    case 0x6F:                                      /* switch 1 */
        var_s2 = _badrone_entrypoint_18(arg0, arg0->unkC0->unk14);
        var_s1 = 2;
        goto block_180;
    case 0x6B:                                      /* switch 1 */
        _bafpctrl_entrypoint_13(arg0, 0);
        if (func_800A3404(arg0) != 0) {
            func_8009337C(arg0, 1);
        }
        if ((func_8008DAA8(arg0) != 0) && (func_800A3274(arg0) != 0x11) && (func_8008DD70(arg0) == 0) && (func_800A9420(arg0->unk184) == 0)) {
            temp_v0 = _plsu_entrypoint_1(0x11);
            if (temp_v0 != -1) {
                func_800F7B9C(temp_v0, 0x94);
            }
        }
        var_s1 = 2;
        goto block_180;
    case 0x6C:                                      /* switch 1 */
        _bafpctrl_entrypoint_13(arg0, 1);
        if (func_800A3404(arg0) != 0) {
            func_8009337C(arg0, 0);
        }
        if ((func_8008E124(arg0) == 0) && (func_8009E674(arg0, 0x10) == 0) && (func_8009E674(arg0, 8) == 0) && (_bafpctrl_entrypoint_4(arg0) == 3)) {
            _bafpctrl_entrypoint_19(arg0);
        }
        var_s1 = 2;
        goto block_180;
    case 0x5D:                                      /* switch 1 */
        if (arg0->unkC0->unk18 != 0) {
            baflag_set(arg0, 0x39);
            var_s1 = 2;
        } else {
            baflag_clear(arg0, 0x39);
            var_s1 = 2;
        }
        goto block_180;
    case 0x2F:                                      /* switch 1 */
        var_s2 = _badrone_entrypoint_20(arg0, arg0->unkC0->pad8, 1);
        var_s1 = 2;
        goto block_180;
    case 0x92:                                      /* switch 1 */
        func_800A17A8(arg0, -1);
        var_s2 = _badrone_entrypoint_20(arg0, arg0->unkC0->pad8, 1);
        var_s1 = 2;
        goto block_180;
    case 0x24:                                      /* switch 1 */
        if (func_8008DD90(arg0) == 0) {
            func_800995B8(arg0, 0);
            var_s2 = _badata_entrypoint_27(arg0);
            var_s1 = 2;
        }
        goto block_180;
    case 0x23:                                      /* switch 1 */
        if (func_8008DD90(arg0) == 0) {
            func_800995B8(arg0, 1);
            var_s2 = _badata_entrypoint_27(arg0);
            var_s1 = 2;
        }
        goto block_180;
    case 0x2D:                                      /* switch 1 */
    case 0x98:                                      /* switch 1 */
        func_800995B8(arg0, 3);
        if ((player_inWater(arg0) != 0) && (func_8009E71C(arg0, 0xB) != 0)) {
            var_s2 = 0xA2;
            var_s1 = 2;
        } else {
            var_s2 = _badata_entrypoint_27(arg0);
            var_s1 = 2;
        }
        goto block_180;
    case 0x89:                                      /* switch 1 */
        _babounce_entrypoint_7(arg0, arg0->unkC0->unk14);
        var_s1 = 2;
        goto block_180;
    case 0x68:                                      /* switch 1 */
        func_800995B8(arg0, 3);
        var_s2 = _badrone_entrypoint_22(arg0, arg0->unkC0->pad8);
        var_s1 = 2;
        goto block_180;
    case 0x45:                                      /* switch 1 */
        if (func_800F64A4(arg0->unk184, 0x201) != 0) {
            var_s2 = 0x120;
            var_s1 = 2;
        } else {
            var_s2 = func_80099840(arg0, 1);
            var_s1 = 2;
        }
        goto block_180;
    case 0x57:                                      /* switch 1 */
        _bacough_entrypoint_4(arg0, 1);
        var_s1 = 2;
        goto block_180;
    case 0x56:                                      /* switch 1 */
        _bacough_entrypoint_4(arg0, 2);
        var_s1 = 2;
        goto block_180;
    case 0x44:                                      /* switch 1 */
        var_s2 = 0x11F;
        var_s1 = 2;
        goto block_180;
    case 0x13:                                      /* switch 1 */
        func_800A17A8(arg0, -0x3E7);
        /* fallthrough */
    case 0xB:                                       /* switch 1 */
        func_800997BC(arg0);
        var_s2 = func_80099840(arg0, 0);
        var_s1 = 2;
        goto block_180;
    case 0x26:                                      /* switch 1 */
        func_800A17A8(arg0, -0x3E7);
        _basudie_entrypoint_1(arg0);
        _basudie_entrypoint_0(arg0);
        var_s1 = 2;
        goto block_180;
    case 0x19:                                      /* switch 1 */
        var_s2 = func_8009F354(arg0);
        var_s1 = 2;
        goto block_180;
    case 0x11:                                      /* switch 1 */
        var_s2 = 0x54;
        var_s1 = 2;
        goto block_180;
    case 0x4D:                                      /* switch 1 */
        _bababykaz_entrypoint_14(arg0);
        var_s1 = 2;
        goto block_180;
    case 0x7C:                                      /* switch 1 */
        var_s2 = _badrone_entrypoint_19(arg0);
        var_s1 = 2;
        goto block_180;
    case 0x4C:                                      /* switch 1 */
        _baduo_entrypoint_15(arg0, arg0->unkC0->pad8);
        var_s1 = 2;
        goto block_180;
    case 0x3E:                                      /* switch 1 */
        _baduo_entrypoint_17(arg0, arg0->unkC0->pad8);
        var_s1 = 2;
        goto block_180;
    case 0x3C:                                      /* switch 1 */
        _baduo_entrypoint_18(arg0, arg0->unkC0->pad8);
        var_s1 = 2;
        goto block_180;
    case 0x3F:                                      /* switch 1 */
        temp_v0_5 = arg0->unkC0;
        _baduo_entrypoint_20(arg0, temp_v0_5->pad8, temp_v0_5->unk0);
        var_s1 = 2;
        goto block_180;
    case 0x5F:                                      /* switch 1 */
        func_80094430(arg0, arg0->unkC0->unk0);
        var_s1 = 2;
        goto block_180;
    case 0x2B:                                      /* switch 1 */
        baflag_set(arg0, 0x38);
        _bashoes_entrypoint_12(arg0, arg0->unkC0->unk0);
        if (func_8009CA70(arg0, sp68, 0x40) == 0) {
            var_s2 = func_8009F354(arg0);
        }
        var_s1 = 2;
        goto block_180;
    case 0x29:                                      /* switch 1 */
        baflag_set(arg0, 0x37);
        _bashoes_entrypoint_12(arg0, arg0->unkC0->unk0);
        if (func_8009CA70(arg0, sp68, 0x40) == 0) {
            var_s2 = func_8009F354(arg0);
        }
        var_s1 = 2;
        goto block_180;
    case 0x1A:                                      /* switch 1 */
        baflag_set(arg0, 0x10);
        _bashoes_entrypoint_12(arg0, arg0->unkC0->unk0);
        if (func_8009CA70(arg0, sp68, 0x40) == 0) {
            var_s2 = func_8009F354(arg0);
        }
        var_s1 = 2;
        goto block_180;
    case 0x1B:                                      /* switch 1 */
        baflag_set(arg0, 0xE);
        func_800A391C(arg0, arg0->unkC0->unk0);
        var_s2 = func_8009F354(arg0);
        var_s1 = 2;
        goto block_180;
    case 0x47:                                      /* switch 1 */
        sp40 = func_80099A4C(arg0);
        _suegg_entrypoint_6((Unk80132ED0 *)sp40, sp48, &sp44);
        func_8009AD20(arg0, _gcegg_entrypoint_7(sp44) + 2);
        if ((func_8009BD44(arg0) != 3) && (func_8008DD90(arg0) == 0)) {
            func_800995B8(arg0, 0);
            if (func_8010114C(sp40, 0x1C, arg0->unk184) != 1) {
                func_800A17A8(arg0, -1);
            }
            var_s2 = func_80099840(arg0, 0);
            var_s1 = 2;
        }
        goto block_180;
    case 0x1F:                                      /* switch 1 */
        if ((func_8009BD44(arg0) != 3) && (func_8008DD90(arg0) == 0) && (func_8008E974(arg0) != 0)) {
        case 0x31:                                  /* switch 1 */
            func_800995B8(arg0, 2);
            func_800A17A8(arg0, -1);
            var_s2 = func_80099840(arg0, 0);
            var_s1 = 2;
        }
        goto block_180;
    case 0x21:                                      /* switch 1 */
        if ((func_8009BD44(arg0) != 3) && (func_8008DD90(arg0) == 0)) {
        case 0x33:                                  /* switch 1 */
            func_800995B8(arg0, 0);
            if (func_8010114C((BtIntPtr) arg0->unkC0->unk14, 0x1C, arg0->unk184) != 1) {
                func_800A17A8(arg0, -1);
            }
            var_s2 = func_80099840(arg0, 0);
            var_s1 = 2;
        }
        goto block_180;
    case 0x4E:                                      /* switch 1 */
        if (func_8009BD44(arg0) != 3) {
            func_800995B8(arg0, 1);
            func_800A17A8(arg0, -func_80099A58(arg0));
            if ((arg0->unk158) != 0) {
                if (func_800A1718(arg0) == 0) {
                    func_80101180(0x2C4, 0x70, func_80099A70(arg0) | (arg0->unk184 * 0x10));
                }
                if (func_800A3274(arg0) == 6) {
                    var_s2 = _badata_entrypoint_26(arg0);
                    var_s1 = 2;
                } else {
                    var_s2 = func_80099840(arg0, 0);
                    var_s1 = 2;
                }
            } else {
                var_s2 = func_80099840(arg0, 0);
                var_s1 = 2;
            }
        }
        goto block_180;
    case 0x20:                                      /* switch 1 */
        if (func_8009BD44(arg0) != 3) {
            func_800995B8(arg0, 1);
            func_800A17A8(arg0, -1);
            var_s2 = func_80099840(arg0, 0);
            var_s1 = 2;
        }
        goto block_180;
    case 0x2E:                                      /* switch 1 */
        func_800995B8(arg0, 3);
        func_800A17A8(arg0, -1);
        var_s2 = func_80099840(arg0, 0);
        var_s1 = 2;
        goto block_180;
    case 0x91:                                      /* switch 1 */
        var_s2 = _badrone_entrypoint_21(arg0);
        var_s1 = 2;
        goto block_180;
    case 0x40:                                      /* switch 1 */
        _baduo_entrypoint_11(arg0, 1);
        var_s1 = 2;
        goto block_180;
    case 0x84:                                      /* switch 1 */
        if (func_800A3970(arg0, arg0->unkC0->unk18) != 0) {
            var_s1 = 2;
        }
        goto block_180;
    case 0x14:                                      /* switch 1 */
        var_s2 = 5;
        var_s1 = 2;
        goto block_180;
    case 0x60:                                      /* switch 1 */
        func_800F911C(1);
        _baduo_entrypoint_7(arg0, 1);
        func_800A0CF4(arg0, 1);
        func_800A3410(arg0, 1);
        func_800A3904(arg0, 1);
        goto block_180;
    case 0x35:                                      /* switch 1 */
        baflag_set(arg0, 0x1A);
        var_s2 = func_8009F354(arg0);
        var_s1 = 2;
        goto block_180;
    case 0x4:                                       /* switch 1 */
    case 0x5:                                       /* switch 1 */
        _baduo_entrypoint_10(arg0, 0);
        _baduo_entrypoint_11(arg0, 0);
        var_s1 = 2;
        goto block_180;
    case 0x3A:                                      /* switch 1 */
        if (func_8008E23C(arg0) != 0) {
            _baduo_entrypoint_11(arg0, 1);
            var_s1 = 2;
        } else {
            _baduo_entrypoint_8(arg0, arg0->unkC0->pad8);
            _baduo_entrypoint_9(arg0, arg0->unkC0->unk0 + 180.0f);
            _baduo_entrypoint_10(arg0, 1);
            var_s1 = 2;
        }
        goto block_180;
    case 0x3B:                                      /* switch 1 */
        if (func_8008E23C(arg0) != 0) {
            _baduo_entrypoint_11(arg0, 1);
            _baduo_entrypoint_8(arg0, arg0->unkC0->pad8);
            var_s1 = 2;
        }
        goto block_180;
    case 0x41:                                      /* switch 1 */
        _baduo_entrypoint_11(arg0, 0);
        var_s1 = 2;
        goto block_180;
    case 0x95:                                      /* switch 1 */
        func_8009EC08(sp3C, sp38);
        sp3C[1] = func_80099A58(arg0);
        temp_v0_7 = func_80099A64(arg0);
        sp38[1] = temp_v0_7;
        if ((sp3C[0] != sp3C[1]) || (sp38[0] != sp38[1])) {
            func_8009EB24(sp3C[1], sp38[1]);
        }
        var_s1 = 2;
        goto block_180;
    case 0x96:                                      /* switch 1 */
        func_8009EBD0();
        var_s1 = 2;
        goto block_180;
    case 0x97:                                      /* switch 1 */
        func_800A05DC(arg0);
        var_s1 = 2;
        goto block_180;
    case 0x27:                                      /* switch 1 */
        var_s2 = func_80099B54(arg0);
        var_s1 = 2;
        goto block_180;
    case 0x34:                                      /* switch 1 */
        var_s2 = _badrone_entrypoint_26(arg0);
        var_s1 = 2;
        goto block_180;
    case 0xC:                                       /* switch 1 */
        temp_v0 = func_8008FD48();
        var_a1 = !(temp_v0 == 1) && !(temp_v0 == 0xA);
        if ((func_8009CC68(arg0) == 0) && (var_a1 == 0) && (baflag_isTrue(arg0, 0xF) == 0) && (player_isStable(arg0) == 0)) {
            var_s2 = 0x4F;
            var_s1 = 2;
        }
        goto block_180;
    case 0x3D:                                      /* switch 1 */
        _baduo_entrypoint_19(arg0);
        var_s1 = 2;
        goto block_180;
    case 0x1E:                                      /* switch 1 */
        if (func_8008D630(arg0) != 0) {
            var_s1 = 2;
            var_s2 = _badata_entrypoint_29(arg0);
        }
        goto block_180;
    case 0x1D:                                      /* switch 1 */
        if (func_8008D630(arg0) != 0) {
            var_s1 = 2;
            var_s2 = _badata_entrypoint_31(arg0);
        }
        goto block_180;
    case 0x1C:                                      /* switch 1 */
        if (func_8008D630(arg0) != 0) {
            var_s1 = 2;
            var_s2 = _badata_entrypoint_32(arg0);
        }
        goto block_180;
    case 0x15:                                      /* switch 1 */
        var_s1 = 2;
        if (func_8009CBDC(arg0, sp68) == 9) {
            var_s2 = 0x24;
        } else {
            temp_v0 = func_800F40EC(arg0);
            switch (temp_v0) {                    /* switch 2 */
            case 1:                                 /* switch 2 */
                var_s2 = 0x2D;
                break;
            case 2:                                 /* switch 2 */
                var_s2 = 0x2B;
                break;
            case 0:                                 /* switch 2 */
                if (player_isStable(arg0) != 0) {
                    var_s2 = _badata_entrypoint_34(arg0);
                } else {
                    var_s2 = _badata_entrypoint_24(arg0);
                }
                break;
            }
        }
        baphysics_set_target_horizontal_velocity(arg0, 0);
        func_8009BA9C(arg0, 0);
        goto block_180;
    case 0x25:                                      /* switch 1 */
        var_s1 = 2;
        var_s2 = _badata_entrypoint_32(arg0);
        goto block_180;
    case 0x93:                                      /* switch 1 */
        _bafpctrl_entrypoint_19(arg0);
        var_s1 = 2;
        goto block_180;
    case 0x8A:                                      /* switch 1 */
        func_80094574(arg0, arg0->unkC0->unk18);
        var_s1 = 2;
        goto block_180;
    case 0x38:                                      /* switch 1 */
        var_s1 = 2;
        var_s2 = 0xB5;
        goto block_180;
    case 0x59:                                      /* switch 1 */
        _basquash_entrypoint_3(arg0, 1);
        var_s2 = func_80099730(arg0, 0);
        goto block_180;
    case 0x5A:                                      /* switch 1 */
        _basquash_entrypoint_3(arg0, 1);
        var_s2 = func_80099730(arg0, 1);
        goto block_180;
    case 0x9A:                                      /* switch 1 */
        _basquash_entrypoint_3(arg0, 1);
        goto block_180;
    case 0x5B:                                      /* switch 1 */
        _basquash_entrypoint_3(arg0, 2);
        var_s2 = func_80099730(arg0, 0);
        goto block_180;
    case 0x5C:                                      /* switch 1 */
        _basquash_entrypoint_3(arg0, 2);
        var_s2 = func_80099730(arg0, 1);
        goto block_180;
    case 0xF:                                       /* switch 1 */
        baflag_set(arg0, 6);
        var_s2 = func_8009F354(arg0);
        var_s1 = 2;
        goto block_180;
    case 0x30:                                      /* switch 1 */
        func_800A17A8(arg0, -0x3E7);
        baflag_set(arg0, 6);
        var_s2 = func_8009F354(arg0);
        var_s1 = 2;
        goto block_180;
    case 0x37:                                      /* switch 1 */
        var_s2 = _badrone_entrypoint_27(arg0);
        var_s1 = 2;
        goto block_180;
    case 0x2A:                                      /* switch 1 */
        var_s1 = 2;
        var_s2 = func_8009F354(arg0);
        baflag_set(arg0, 0x14);
        goto block_180;
    case 0x49:                                      /* switch 1 */
        baflag_set(arg0, 2);
        var_s1 = 2;
        goto block_180;
    case 0x4A:                                      /* switch 1 */
        baflag_set(arg0, 1);
        var_s1 = 2;
        goto block_180;
    case 0x61:                                      /* switch 1 */
        _bsfirstp_entrypoint_26(arg0);
        return;
    case 0x8B:                                      /* switch 1 */
        var_s2 = 0x42;
        var_s1 = 2;
        goto block_180;
    case 0x62:                                      /* switch 1 */
        func_800A3544(arg0, 1);
        func_8009337C(arg0, 0);
        var_s1 = 2;
        goto block_180;
    case 0x63:                                      /* switch 1 */
        func_800A3544(arg0, 0);
        func_8009337C(arg0, 1);
        var_s1 = 2;
        goto block_180;
    case 0x66:                                      /* switch 1 */
        temp_v0_10 = arg0->unkC0;
        func_8008ED88(arg0, temp_v0_10->pad8, temp_v0_10->unk14);
        var_s1 = 2;
        goto block_180;
    case 0x67:                                      /* switch 1 */
        _bainvisible_entrypoint_5(arg0, arg0->unkC0->unk0);
        var_s1 = 2;
        goto block_180;
    case 0x7D:                                      /* switch 1 */
        if ((arg0->unk158) != 0) {
            _badeathmatch_entrypoint_5(arg0, _badeathmatch_entrypoint_4(arg0->unkC0->unk18), arg0->unkC0->unk1C);
            var_s1 = 2;
        } else {
            temp_v0_11 = arg0->unkC0;
            func_800D175C(temp_v0_11->unk18, temp_v0_11->unk1C);
            var_s1 = 2;
        }
        goto block_180;
    case 0x8C:                                      /* switch 1 */
        func_800956B8(arg0);
        goto block_180;
    }
block_180:
    func_8009E830(arg0, var_s1);
    bs_setState(arg0, var_s2);
}


/* extern */

void func_8009AB78(PlayerState *arg0) {
    void _bahold_entrypoint_4(BtIntPtr arg0);
    int baflag_isFalse(PlayerState *, s32);
    s32 bastatetimer_isDone(PlayerState *, s32);
    void bs_setState(PlayerState *, s32);
    s32 func_8008E9AC(void *);
    void func_8008F6B8(PlayerState *, s32);
    s32 func_8009E6EC(PlayerState *);
    void func_8009E830(PlayerState *, s32);
    s32 func_800A3274(PlayerState *);
    s32 sp2C;
    s32 sp28;
    s32 sp24;

    sp2C = func_800A3274(arg0);
    sp28 = 1;
    sp24 = 0;
    switch (func_8009E6EC(arg0)) {
        case 0x12:
            if ((baflag_isFalse(arg0, 0xF) != 0) && (bastatetimer_isDone(arg0, 0) != 0) && ((sp2C == 1) || (sp2C == 0xA))) {
                sp28 = 2;
                func_8008F6B8(arg0, func_8008E9AC(arg0));
            }
            break;
        case 8:
            sp24 = 0x3C;
            sp28 = 2;
            break;
        default:
            _bahold_entrypoint_4(arg0);
            func_80099B94(arg0);
            return;
    }
    bs_setState(arg0, sp24);
    func_8009E830(arg0, sp28);
} typedef struct { u8 pad0[0xC0]; union { void * unkC0; u8 * unkC0_u8p; }; } Obj1E72EA0_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void func_8009AC6C(u8 *arg0) {
    s32 func_800EFD24(u8 *, u8 *);
    s32 temp_v0;

    (*(s32 *)((s8 *)((((Obj1E72EA0_arg0 *)arg0)->unkC0_u8p)) + (0x18))) = 0;
    (*(s32 *)((s8 *)((((Obj1E72EA0_arg0 *)arg0)->unkC0_u8p)) + (0x14))) = 0;
    func_800EFD24((((Obj1E72EA0_arg0 *)arg0)->unkC0_u8p) + 8, arg0);
    {
        s32 i;
        for (i = 0; i < 5; i++) {
            *(s32 *)(*(u8 **)(arg0 + 0xC0) + 0x4C + i * 0x28) = 0;
        }
    }
}

void func_8009ACF4(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*&((Obj1E72EA0_arg0 *)arg0)->unkC0 + 0) = arg1;
}

void func_8009AD04(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 192) + 4) = arg1;
}

void func_8009AD14(void *arg0, BtIntPtr arg1) {
    *(s32 *)((u8 *)*&((Obj1E72EA0_arg0 *)arg0)->unkC0 + 20) = arg1;
}

void func_8009AD20(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)*&((Obj1E72EA0_arg0 *)arg0)->unkC0 + 24) = arg1;
}

void func_8009AD2C(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)*&((Obj1E72EA0_arg0 *)arg0)->unkC0 + 28) = arg1;
}

void func_8009AD38(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 192) + 32) = arg1;
}

/* extern */

void func_8009AD44(PlayerState *arg0, f32 *arg1) {
    void func_800EE7F8(f32 *, f32 *);
    func_800EE7F8(arg0->unkC0->pad8, arg1);
}
