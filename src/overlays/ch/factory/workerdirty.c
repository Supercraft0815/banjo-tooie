#include "ch/factory/workerdirty.h"
#include "su/baddiedialog_descriptor.h"
void func_80800394_chfactoryworkerdirty(Actor *arg0);
void func_80105834(Actor *);
void func_80101870(Actor *, void *);
void func_80800340_chfactoryworkerdirty(Actor* arg0);
void func_8080025C_chfactoryworkerdirty(Actor *arg0);
#ifndef BT_NATIVE
void *func_80107C2C(s32 *, s32, void *, s32, void *);
#endif
s32 func_808008A4_chfactoryworkerdirty(Actor *arg0, s32 arg1, s32 arg2);

u32 D_80800ED0_chfactoryworkerdirty[] = {
    0x00000000, 0x00000000, 0x40BCCCCD, 0x035D0001,
    0x3FF33333, 0x0123000A, 0x3DF5C28F, 0x014B0001,
    0x402CCCCD, 0x035E0001
};

BtFnWord D_80800EF8_chfactoryworkerdirty[] = {
    0x027E0170, 0x08020001, (BtFnWord)D_80800ED0_chfactoryworkerdirty, (BtFnWord)func_80800394_chfactoryworkerdirty,
    (BtFnWord)func_80105834, (BtFnWord)func_80101870, 0x07D00000, 0x3F800000,
    0x00000000, 0x40000120, (BtFnWord)func_80800340_chfactoryworkerdirty, 0x00000000,
    0x00140000, (BtFnWord)func_8080025C_chfactoryworkerdirty, (BtFnWord)func_80107C2C, 0x80002412,
    (BtFnWord)func_808008A4_chfactoryworkerdirty, 0x00000000
};

OSThread *chfactoryworkerdirty_entrypoint_0(void)
{
    return (OSThread *) D_80800EF8_chfactoryworkerdirty;
}

void func_8080000C_chfactoryworkerdirty(Actor* arg0)
{
    func_80108B04(arg0,1);
}

/* extern */

void func_8080002C_chfactoryworkerdirty(Actor *arg0) {
    s32 func_8010114C(BtIntPtr, s32, BtIntPtr);
    s32 *sp1C;
    s32 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    sp1C = temp_v0;
    func_8010114C(*temp_v0, 0x2C, 0);
    *sp1C = 0;
}

void func_80800068_chfactoryworkerdirty(s32 *arg0, s32 arg1, s32 arg2) {
    s32 func_8010114C(BtIntPtr, s32, BtIntPtr);
    s16 packed[2];

    if (*arg0 != 0) {
        packed[0] = arg1;
        packed[1] = arg2;
        func_8010114C(*arg0, 0x21, *(s32 *)&packed[0]);
    }
}

int func_808000AC_chfactoryworkerdirty(Actor *arg0, s32 arg1) {
    s32 _glcutDll_entrypoint_20();
    void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
    void func_80102424(Actor *, s32);
    s32 func_801032B0(Actor *, u16, u16);
    void func_80800AF8_chfactoryworkerdirty();
    extern s16 D_80800F80_chfactoryworkerdirty[7];
    struct {
        s32 unk0;
        s32 unk4;
        f32 unk8;
        f32 unkC;
        u8 unk10;
    } *data;
    u8 state;

    data = func_80100094(arg0, 0U);
    switch (arg1) {
    case 3:
        func_8080000C_chfactoryworkerdirty(arg0);
        func_801032B0(arg0, 0x83B, arg0->unk0->unk16);
        func_80102424(arg0, 2);
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800F80_chfactoryworkerdirty);
        break;
    case 4:
        func_80800068_chfactoryworkerdirty(&data->unk0, 1, 1);
        break;
    case 5:
        func_80800068_chfactoryworkerdirty(&data->unk0, 1, 2);
        break;
    case 6:
        func_80800068_chfactoryworkerdirty(&data->unk0, 1, 3);
        break;
    case 7:
    case 8:
        func_80102424(arg0, 4);
        func_801032B0(arg0, 0x803, arg0->unk0->unk16);
        state = data->unk10;
        if (state != 1) {
            if (state == 6) {
                func_8080002C_chfactoryworkerdirty(arg0);
                data->unk8 = 8.0f;
                data->unkC = 0.0f;
                func_80800AF8_chfactoryworkerdirty(arg0);
                arg0->unk74_30 = 0;
            }
        } else {
            if (_glcutDll_entrypoint_20() != 0) {
                data->unk8 = 8.0f;
                data->unkC = 0.0f;
            } else {
                data->unk8 = 0.0f;
            }
            arg0->unk74_30 = 1;
            func_801032B0(arg0, 0x803, arg0->unk0->unk16);
        }
        break;
    }
    data->unk10 = arg1; BT_NATIVE_ONLY(return 0;)
}

void func_8080025C_chfactoryworkerdirty(Actor *arg0) {
    s32 _glcutDll_entrypoint_20(void);
    s32 func_800D0B68(u32, u32);
    void func_800D1000(u32, u32, f32 *, u32, Unk80132ED0 *);
    void func_800EEB9C(f32[3], f32, f32);
    void func_800EF04C(f32 *, f32 *);
    int func_808000AC_chfactoryworkerdirty(Actor *, s32);
    s32 func_808009E4_chfactoryworkerdirty(void);
    s32 func_80800A14_chfactoryworkerdirty(BtIntPtr);
    int func_80800AB4_chfactoryworkerdirty(BtIntPtr);
    struct {
        s32 unk0;
        u8 pad4[0xC];
        s8 unk10;
    } *data;
    f32 sp28[3];

    data = func_80100094(arg0, 0U);
    data->unk10 = 1;
    data->unk0 = 0;
    if (func_808009E4_chfactoryworkerdirty() != 0 &&
        func_80800A14_chfactoryworkerdirty((BtIntPtr)arg0) != 0 &&
        _glcutDll_entrypoint_20() == 0 && func_800D0B68(0x36, 1) == 0) {
        func_800EEB9C(sp28, arg0->rotation[1], 100.0f);
        func_800EF04C(sp28, arg0->position);
        func_800D1000(0x36, 1, sp28, 3, NULL);
    }
    if (_glcutDll_entrypoint_20() != 0) {
        func_808000AC_chfactoryworkerdirty(arg0, 8);
    } else if (func_80800AB4_chfactoryworkerdirty((BtIntPtr)arg0) != 0) {
        func_808000AC_chfactoryworkerdirty(arg0, 7);
    }
    arg0->unk54 = arg0->rotation[1];
}

void func_80800340_chfactoryworkerdirty(Actor* arg0)
{
    func_80100094(arg0,0);
    func_80800DB4_chfactoryworkerdirty(arg0);
}

void func_8080036C_chfactoryworkerdirty(BtIntPtr arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, void *);
    extern s16 D_80800F90_chfactoryworkerdirty[8];
    _subaddieaudioquick_entrypoint_2((Actor *)arg0, (f32 *)(arg0 + 4), D_80800F90_chfactoryworkerdirty);
}

void func_80800394_chfactoryworkerdirty(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *arg0, f32 arg1[3], void *arg2);
    s32 _subaddieaudioquick_entrypoint_3(Actor *arg0, f32 arg1[3], void *arg2, f32 arg3);
    s32 _sudeflect_entrypoint_1(f32 *arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4);
    BtIntPtr func_800BBCB8(f32 *arg0, f32 *arg1, f32 arg2, s32 arg3, s32 *arg4);
    s32 func_800C0638(void);
    s32 func_800D9078(f32 *arg0);
    f32 func_800F10B4(f32 value, f32 in_min, f32 in_max, f32 out_min, f32 out_max);
    s32 func_80101DDC(Actor *arg0);
    s32 func_80101E14(Actor *arg0, f32 arg1);
    void func_80102424(Actor *arg0, s32 arg1);
    void func_8080061C_chfactoryworkerdirty(Actor *arg0);
    void func_80800700_chfactoryworkerdirty(Actor *arg0);
    void func_80800994_chfactoryworkerdirty(u8 *arg0);
    void func_80800C98_chfactoryworkerdirty(Actor *arg0);
    extern s16 D_80800F40_chfactoryworkerdirty[32];
    extern s16 D_80800FA0_chfactoryworkerdirty[8];
    extern s16 D_80800FB0_chfactoryworkerdirty[8];
    extern s16 D_80800FC0_chfactoryworkerdirty[8];
    struct {
        int unk0;
        int unk4;
        f32 unk8;
        f32 unkC;
        u8 unk10;
    } *data;
    int count;
    f32 amount;
    data = func_80100094(arg0, 0U);
    func_80800C98_chfactoryworkerdirty(arg0);
    if (arg0->unk70_10 == 2) {
        _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80800FA0_chfactoryworkerdirty, 0.5f);
        if (func_80101DDC(arg0) != 0) {
            func_80102424(arg0, 3);
        }
    }
    switch (data->unk10) {
    case 1:
        if (func_800C0638() == 0) {
            if (func_80101E14(arg0, 0.13f) != 0 || func_80101E14(arg0, 0.215f) != 0 || func_80101E14(arg0, 0.27f) != 0 || func_80101E14(arg0, 0.34f) != 0) {
                func_8080036C_chfactoryworkerdirty((BtIntPtr)arg0);
            }
            _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80800FB0_chfactoryworkerdirty, 0.4f);
        }
        _sudeflect_entrypoint_1(arg0->position, 120.0, 0.0f, 70.0f, 10);
        func_8080061C_chfactoryworkerdirty(arg0);
        break;
    case 2:
        _sudeflect_entrypoint_1(arg0->position, 120.0f, 0.0f, 70.0f, 10);
        break;
    case 3:
        func_808000AC_chfactoryworkerdirty(arg0, 4);
        break;
    case 7:
    case 8:
        if (func_800C0638() == 0 && func_80101E14(arg0, 0.46f) != 0) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800FC0_chfactoryworkerdirty);
        }
        if (data->unk8 > 0) {
            amount = func_800F10B4(data->unk8, 0, 8.0f, 0, 5.0f);
            data->unkC += amount;
            count = (s32)data->unkC;
            func_800BBCB8(arg0->position, NULL, 1.0f, count, (s32 *)D_80800F40_chfactoryworkerdirty);
            data->unkC -= count;
            func_800D9078(&data->unk8);
        }
        _sudeflect_entrypoint_1(arg0->position, 120.0f, 0.0f, 70.0f, 10);
        func_80800994_chfactoryworkerdirty((u8 *)arg0);
        func_80800700_chfactoryworkerdirty(arg0);
        break;
    }
}

void func_8080061C_chfactoryworkerdirty(Actor *arg0) {
#ifdef BT_NATIVE
    s32 func_80090178(s32);
#else
    s32 func_80090178(AllowedTransformation);
#endif
    s32 func_808009C0_chfactoryworkerdirty(void);
    u32 _subaddiedialog_entrypoint_7(Actor *, f32 *, subaddiedialog_UnkStruct0 *);
    void func_80090734(s32, f32 *);
    extern subaddiedialog_UnkStruct0 D_80800FD0_chfactoryworkerdirty;
    BT_IDO_ONLY(extern u16 D_80800FD4_chfactoryworkerdirty;)
    BT_IDO_ONLY(extern u16 D_80800FD6_chfactoryworkerdirty;)
    extern subaddiedialog_UnkStruct0 D_80800FEC_chfactoryworkerdirty;
    subaddiedialog_UnkStruct0 *dialog;

    if (func_80090178(0x40) != 0) {
        dialog = &D_80800FD0_chfactoryworkerdirty;
        if (func_808009C0_chfactoryworkerdirty() != 0) {
            BT_DATA_FIELD(D_80800FD0_chfactoryworkerdirty.unk4, D_80800FD4_chfactoryworkerdirty) = BT_DATA_FIELD(D_80800FD0_chfactoryworkerdirty.unk6, D_80800FD6_chfactoryworkerdirty);
        }
        arg0->unk74_30 = 0;
    } else {
        dialog = &D_80800FEC_chfactoryworkerdirty;
    }
    switch (_subaddiedialog_entrypoint_7(arg0, arg0->position, dialog)) {
            case 0:
                break;
            case 0x134C:
                func_80090734(1, arg0->position);
                func_808000AC_chfactoryworkerdirty(arg0, 2);
                break;
            case 0x134D:
                func_80090734(1, arg0->position);
                func_808000AC_chfactoryworkerdirty(arg0, 2);
                break;
            default:
                func_80090734(1, arg0->position);
                break;
    }
}

void func_80800700_chfactoryworkerdirty(Actor *arg0) {
    s32 func_808009E4_chfactoryworkerdirty(void);
    s32 func_80800A54_chfactoryworkerdirty(void);
    u32 _subaddiedialog_entrypoint_7(Actor *, f32 *, subaddiedialog_UnkStruct0 *);
    void func_80090734(s32, f32 *);
    extern subaddiedialog_UnkStruct0 D_80801008_chfactoryworkerdirty;
    BT_IDO_ONLY(extern s16 D_8080100C_chfactoryworkerdirty;)
    f32 *position[1];

    if (func_808009E4_chfactoryworkerdirty() != 0) {
        BT_DATA_FIELD(D_80801008_chfactoryworkerdirty.unk4, D_8080100C_chfactoryworkerdirty) = 0x1350;
    } else if (func_80800A54_chfactoryworkerdirty() == 1) {
        BT_DATA_FIELD(D_80801008_chfactoryworkerdirty.unk4, D_8080100C_chfactoryworkerdirty) = 0x134F;
    } else {
        BT_DATA_FIELD(D_80801008_chfactoryworkerdirty.unk4, D_8080100C_chfactoryworkerdirty) = 0x134E;
    }
    position[0] = arg0->position;
    if (_subaddiedialog_entrypoint_7(arg0, position[0], &D_80801008_chfactoryworkerdirty) != 0) {
        func_80090734(1, position[0]);
    }
}

void func_80800788_chfactoryworkerdirty(Actor *arg0, s32 arg1, s32 arg2) {
    void func_80090708(s32);
    void func_800904F4(s32, Unk80132ED0 *);
    void func_800D1000(u32, u32, f32 *, u32, Unk80132ED0 *);
    void func_80800B40_chfactoryworkerdirty();
    switch (arg1) {
    case 0x134C:
    case 0x134D:
        func_80090708(0);
        func_800904F4(0x65, arg0->unk0);
        return;
    case 0x1350:
        func_80800B40_chfactoryworkerdirty(arg0);
        func_80090708(0);
        func_800D1000(0x36, 1, arg0->position, 0, NULL);
        return;
    default:
        func_80090708(0);
        return;
    }
}

/* extern */

s32 func_80800828_chfactoryworkerdirty(BtIntPtr arg0, s32 arg1, s32 arg2) {
    s32 func_80800A54_chfactoryworkerdirty();
    if (arg1 == 0x134E) {
        return func_80800A54_chfactoryworkerdirty();
    }
    return 0;
}

/* extern */

void func_80800864_chfactoryworkerdirty(Actor *arg0) {
    void _subaddielink_entrypoint_1(u8 *arg0, u8 *arg1);
    void *sp1C;

    sp1C = func_80100094(arg0, 0U);
    _subaddielink_entrypoint_1(sp1C, func_801084B0(0x239, &arg0)->unk0);
}

s32 func_808008A4_chfactoryworkerdirty(Actor *arg0, s32 arg1, s32 arg2) {
    void _gcdialogcamera_entrypoint_3(f32 *, f32);
    s32 func_801022E4(Actor *);
    void func_80800D48_chfactoryworkerdirty(Actor *);
    extern f32 D_80801024_chfactoryworkerdirty[4];
    extern f32 D_80801034_chfactoryworkerdirty[4];

    switch (arg1) {
    case 0x3D:
        func_80800864_chfactoryworkerdirty(arg0);
        return 0;
    case 0x52:
        if (func_801022E4(arg0) == 0x35E) {
            _gcdialogcamera_entrypoint_3(D_80801024_chfactoryworkerdirty, arg0->scale);
            return 1;
        }
        _gcdialogcamera_entrypoint_3(D_80801034_chfactoryworkerdirty, arg0->scale);
        return 1;
    case 0x2E:
        func_80800788_chfactoryworkerdirty(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
        return 1;
    case 0x30:
        return func_80800828_chfactoryworkerdirty((BtIntPtr)arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
    case 0x29:
        func_80800D48_chfactoryworkerdirty(arg0);
        return 1;
    case 0x2A:
        func_80800DB4_chfactoryworkerdirty(arg0);
        return 1;
    default:
        return 0;
    }
}

void func_80800994_chfactoryworkerdirty(u8 *arg0) {
    void func_80102BF8(void *arg0, s32 arg1, f32 arg2, f32 arg3);
    func_80102BF8(arg0, 0x3E99999A, 3.0f, 300.0f);
}

s32 func_808009C0_chfactoryworkerdirty(void) {
    return func_800DA564(FLAG_42D_PROGRESS_GI_SKIVVY_WASHED_OUTSIDE, 6);
}

s32 func_808009E4_chfactoryworkerdirty()
{
    return func_800DA298(FLAG_433_UNK);
}    typedef struct { u8 pad0[0x76]; u16 unk76; } Objworkerdirty_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

s32 func_80800A04_chfactoryworkerdirty(BtIntPtr arg0) {
    return ((u32) (((Objworkerdirty_arg0 *)arg0)->unk76) >> 7) + (-50);
}

/* extern */

s32 func_80800A14_chfactoryworkerdirty(BtIntPtr arg0) {
    s32 func_80800A04_chfactoryworkerdirty(BtIntPtr);
    s32 sp1C;

    sp1C = func_800DA564(FLAG_42D_PROGRESS_GI_SKIVVY_WASHED_OUTSIDE, 6);
    return (func_80800A04_chfactoryworkerdirty(arg0) + 1) == sp1C;
}

s32 func_80800A54_chfactoryworkerdirty(void) {
    s32 i;
    s32 count = 0;
    s32 value;
    for (i = 0; i < 6; i++) {
        value = func_800DA298(i + 0x42D) == 0 ? 1 : 0;
        count += value;
    }
    return count;
}

int func_80800AB4_chfactoryworkerdirty(BtIntPtr arg0) {
    s32 func_80800A04_chfactoryworkerdirty();
    return (func_808009E4_chfactoryworkerdirty() != 0) ||
           (func_800DA298(func_80800A04_chfactoryworkerdirty(arg0) + 0x42D) != 0);
}

/* extern */

#ifdef BT_NATIVE
void func_80800AF8_chfactoryworkerdirty(s32 bt_a0) {
#else
void func_80800AF8_chfactoryworkerdirty(void) {
#endif
    s32 func_80800A04_chfactoryworkerdirty();
#ifdef BT_NATIVE
    func_800DA544(((s32 (*)())func_80800A04_chfactoryworkerdirty)() + 0x42D);
#else
    func_800DA544(func_80800A04_chfactoryworkerdirty() + 0x42D);
#endif
    if (func_800DA564(FLAG_42D_PROGRESS_GI_SKIVVY_WASHED_OUTSIDE, 6) == 0x3F) {
        func_800DA544(FLAG_433_UNK);
    }
}

/* extern */

#ifdef BT_NATIVE
void func_80800B40_chfactoryworkerdirty(s32 bt_a0) {
#else
void func_80800B40_chfactoryworkerdirty(void) {
#endif
    s32 func_80800A04_chfactoryworkerdirty();
#ifdef BT_NATIVE
    func_800DA7A8(FLAG_42D_PROGRESS_GI_SKIVVY_WASHED_OUTSIDE, ((s32 (*)())func_80800A04_chfactoryworkerdirty)() + 1, 6);
#else
    func_800DA7A8(FLAG_42D_PROGRESS_GI_SKIVVY_WASHED_OUTSIDE, func_80800A04_chfactoryworkerdirty() + 1, 6);
#endif
}
#include "workerdirty_tail_data.inc"
void chfactoryworkerdirty_entrypoint_1(Unk80132ED0 *arg0, s32 arg1) {
    Actor *actor;

    actor = func_80106790(arg0);
    switch (arg1) {
    case 1:
        func_808000AC_chfactoryworkerdirty(actor, 3);
        return;
    case 2:
        func_808000AC_chfactoryworkerdirty(actor, 5);
        return;
    case 3:
        func_808000AC_chfactoryworkerdirty(actor, 6);
        return;
    case 4:
        func_808000AC_chfactoryworkerdirty(actor, 7);
        return;
    }
}

/* extern */

void chfactoryworkerdirty_entrypoint_2(Unk80132ED0 *arg0, BtIntPtr arg1, f32 arg2) {
    void func_80101010(BtIntPtr arg0);
    void func_8010105C(f32 arg0);
    s32 *sp18[2];

    sp18[0] = func_80100094(func_80106790(arg0), 0U);
    func_80101010(arg1);
    func_8010105C(arg2);
    func_80800068_chfactoryworkerdirty(sp18[0], 3, 0);
}

/* extern */

void chfactoryworkerdirty_entrypoint_3(Unk80132ED0 *arg0, f32 arg1) {
    void func_8010105C(f32);
    s32 *sp18[2];

    sp18[0] = func_80100094(func_80106790(arg0), 0U);
    func_8010105C(arg1);
    func_80800068_chfactoryworkerdirty(sp18[0], 2, 0);
}

/* extern */

void func_80800C98_chfactoryworkerdirty(Actor *arg0) {
    void _suexpression_entrypoint_10(void *arg0, Unk80132ED0 *arg1, f32 *arg2);
    void _suexpression_entrypoint_18(s8 *arg0, s32 arg1);
    s32 func_801022E4(Actor *);
    s32 func_80102320(Actor *, s32, s32);
    if (func_80100094(arg0, 1U) != NULL) {
        if (func_801022E4(arg0) == 0x35D) {
            if (func_80102320(arg0, 0x3ECCCCCD, 0x3F400000) != 0) {
                _suexpression_entrypoint_18(func_80100094(arg0, 1U), 1);
            }
        } else {
            _suexpression_entrypoint_18(func_80100094(arg0, 1U), 1);
        }
        _suexpression_entrypoint_10(func_80100094(arg0, 1U), arg0->unk0, 0);
    }
}

/* extern */

void func_80800D48_chfactoryworkerdirty(Actor *arg0) {
    s32 _suexpression_entrypoint_12(void *, s32, s32);
    s32 _suexpression_entrypoint_17(void *, s32);
    BT_IDO_ONLY(BtIntPtr _suexpression_entrypoint_7(Actor *, s32, s32);) BT_NATIVE_ONLY(void *_suexpression_entrypoint_7(Actor *, s32, s16);)
    if (func_80100094(arg0, 1U) == NULL) {
        _suexpression_entrypoint_7(arg0, 1, 0x8F);
        _suexpression_entrypoint_12(func_80100094(arg0, 1U), 0x42700000, 0x41700000);
        _suexpression_entrypoint_17(func_80100094(arg0, 1U), 0x4B0);
    }
}

/* extern */

void func_80800DB4_chfactoryworkerdirty(Actor *arg0) {
    s32 _suexpression_entrypoint_8(Actor *, s32);
    if (func_80100094(arg0, 1U) != NULL) {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
