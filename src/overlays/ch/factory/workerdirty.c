#include "ch/factory/workerdirty.h"

OSThread *chfactoryworkerdirty_entrypoint_0(void)
{
    extern u8 D_80800EF8_chfactoryworkerdirty[];

    return (OSThread *) D_80800EF8_chfactoryworkerdirty;
}

void func_8080000C_chfactoryworkerdirty(Actor* arg0)
{
    func_80108B04(arg0,1);
}

/* extern */

void func_8080002C_chfactoryworkerdirty(Actor *arg0) {
    s32 func_8010114C(s32, s32, s32);
    s32 *sp1C;
    s32 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    sp1C = temp_v0;
    func_8010114C(*temp_v0, 0x2C, 0);
    *sp1C = 0;
}

void func_80800068_chfactoryworkerdirty(s32 *arg0, s32 arg1, s32 arg2) {
    s32 func_8010114C(s32, s32, s32);
    s16 packed[2];

    if (*arg0 != 0) {
        packed[0] = arg1;
        packed[1] = arg2;
        func_8010114C(*arg0, 0x21, *(s32 *)&packed[0]);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/workerdirty/func_808000AC_chfactoryworkerdirty.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/workerdirty/func_8080025C_chfactoryworkerdirty.s")

void func_80800340_chfactoryworkerdirty(Actor* arg0)
{
    func_80100094(arg0,0);
    func_80800DB4_chfactoryworkerdirty(arg0);
}

void func_8080036C_chfactoryworkerdirty(s32 arg0) {
    s32 _subaddieaudioquick_entrypoint_2(s32, s32, s32 *);
    extern s32 D_80800F90_chfactoryworkerdirty;
    _subaddieaudioquick_entrypoint_2(arg0, arg0 + 4, &D_80800F90_chfactoryworkerdirty);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/workerdirty/func_80800394_chfactoryworkerdirty.s")

void func_8080061C_chfactoryworkerdirty(Actor *arg0) {
    s32 func_80090178(AllowedTransformation);
    s32 func_808009C0_chfactoryworkerdirty(void);
    s32 _subaddiedialog_entrypoint_7(Actor *, f32 *, s32 *);
    void func_80090734(s32, f32 *);
    extern s32 D_80800FD0_chfactoryworkerdirty;
    extern u16 D_80800FD4_chfactoryworkerdirty;
    extern u16 D_80800FD6_chfactoryworkerdirty;
    extern s32 D_80800FEC_chfactoryworkerdirty;
    s32 *dialog;

    if (func_80090178(0x40) != 0) {
        dialog = &D_80800FD0_chfactoryworkerdirty;
        if (func_808009C0_chfactoryworkerdirty() != 0) {
            D_80800FD4_chfactoryworkerdirty = D_80800FD6_chfactoryworkerdirty;
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
    s32 _subaddiedialog_entrypoint_7(Actor *, f32 *, s32 *);
    void func_80090734(s32, f32 *);
    extern s32 D_80801008_chfactoryworkerdirty;
    extern s16 D_8080100C_chfactoryworkerdirty;
    f32 *position[1];

    if (func_808009E4_chfactoryworkerdirty() != 0) {
        D_8080100C_chfactoryworkerdirty = 0x1350;
    } else if (func_80800A54_chfactoryworkerdirty() == 1) {
        D_8080100C_chfactoryworkerdirty = 0x134F;
    } else {
        D_8080100C_chfactoryworkerdirty = 0x134E;
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

s32 func_80800828_chfactoryworkerdirty(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_80800A54_chfactoryworkerdirty();
    if (arg1 == 0x134E) {
        return func_80800A54_chfactoryworkerdirty();
    }
    return 0;
}

/* extern */

void func_80800864_chfactoryworkerdirty(Actor *arg0) {
    s32 _subaddielink_entrypoint_1(void *, Unk80132ED0 *);
    void *sp1C;

    sp1C = func_80100094(arg0, 0U);
    _subaddielink_entrypoint_1(sp1C, func_801084B0(0x239, &arg0)->unk0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/workerdirty/func_808008A4_chfactoryworkerdirty.s")

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
}

s32 func_80800A04_chfactoryworkerdirty(s32 arg0) {
    return ((u32) (*(u16 *)((s8 *)(arg0) + (0x76))) >> 7) + (-50);
}

/* extern */

s32 func_80800A14_chfactoryworkerdirty(s32 arg0) {
    s32 func_80800A04_chfactoryworkerdirty(s32);
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

int func_80800AB4_chfactoryworkerdirty(s32 arg0) {
    s32 func_80800A04_chfactoryworkerdirty();
    return (func_808009E4_chfactoryworkerdirty() != 0) ||
           (func_800DA298(func_80800A04_chfactoryworkerdirty(arg0) + 0x42D) != 0);
}

/* extern */

void func_80800AF8_chfactoryworkerdirty(void) {
    s32 func_80800A04_chfactoryworkerdirty();
    func_800DA544(func_80800A04_chfactoryworkerdirty() + 0x42D);
    if (func_800DA564(FLAG_42D_PROGRESS_GI_SKIVVY_WASHED_OUTSIDE, 6) == 0x3F) {
        func_800DA544(FLAG_433_UNK);
    }
}

/* extern */

void func_80800B40_chfactoryworkerdirty(void) {
    s32 func_80800A04_chfactoryworkerdirty();
    func_800DA7A8(FLAG_42D_PROGRESS_GI_SKIVVY_WASHED_OUTSIDE, func_80800A04_chfactoryworkerdirty() + 1, 6);
}

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

void chfactoryworkerdirty_entrypoint_2(Unk80132ED0 *arg0, s32 arg1, f32 arg2) {
    void func_80101010(s32 arg0);
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
    s32 _suexpression_entrypoint_10(void *, Unk80132ED0 *, s32);
    s32 _suexpression_entrypoint_18(void *, s32);
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
    s32 _suexpression_entrypoint_7(Actor *, s32, s32);
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
