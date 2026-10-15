#include "common.h"

/* extern */

s32 func_80800000_cadbfunc(void) {
    s32 func_800A586C();
    u8 func_800A587C(void);
    s32 temp_v0;

    temp_v0 = func_800A587C();
    switch (temp_v0) {
    case 3:
        return func_800A586C();
    case 1:
        return func_800A586C();
    case 2:
        return func_800A586C();
    case 5:
        return func_800A586C();
    case 6:
        return func_800A586C();
    case 8:
        return func_800A586C();
    default:
        return 0;
    }
}

/* extern */

s32 cadbfunc_entrypoint_0(s32 arg0) {
    s32 func_800EE7F8(s32, s32);
    s32 func_80800000_cadbfunc();
    s32 temp_v0;

    temp_v0 = func_80800000_cadbfunc();
    if (temp_v0 == 0) {
        return 0;
    }
    func_800EE7F8(arg0, temp_v0);
    return 1;
}

/* extern */

s32 cadbfunc_entrypoint_1(s32 arg0) {
    s32 func_800EE7F8(s32, s32);
    s32 func_80800000_cadbfunc();
    s32 temp_v0;

    temp_v0 = func_80800000_cadbfunc();
    if (temp_v0 == 0) {
        return 0;
    }
    func_800EE7F8(temp_v0, arg0);
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ca/dbfunc/func_80800120_cadbfunc.s")

/* extern */

s32 cadbfunc_entrypoint_2(s32 arg0) {
    s32 func_800EE7F8(s32, s32);
    s32 func_80800120_cadbfunc();
    s32 temp_v0;

    temp_v0 = func_80800120_cadbfunc();
    if (temp_v0 == 0) {
        return 0;
    }
    func_800EE7F8(arg0, temp_v0);
    return 1;
}

/* extern */

s32 cadbfunc_entrypoint_3(s32 arg0) {
    s32 func_800EE7F8(s32, s32);
    s32 func_80800120_cadbfunc();
    s32 temp_v0;

    temp_v0 = func_80800120_cadbfunc();
    if (temp_v0 == 0) {
        return 0;
    }
    func_800EE7F8(temp_v0, arg0);
    return 1;
}

s32 func_80800224_cadbfunc(void) {
    s32 func_800A586C(void);
    u8 func_800A587C(void);
    s32 temp_v0;

    temp_v0 = func_800A587C();
    switch (temp_v0) {
        case 1:
            return func_800A586C() + 0x1C;
        case 3:
            return func_800A586C() + 0x24;
        default:
            return 0;
    }
}

/* extern */

s32 cadbfunc_entrypoint_4(s32 arg0) {
    s32 func_800EE7F8(s32, s32);
    s32 func_80800224_cadbfunc();
    s32 temp_v0;

    temp_v0 = func_80800224_cadbfunc();
    if (temp_v0 == 0) {
        return 0;
    }
    func_800EE7F8(arg0, temp_v0);
    return 1;
}

/* extern */

s32 cadbfunc_entrypoint_5(s32 arg0) {
    s32 func_800EE7F8(s32, s32);
    s32 func_80800224_cadbfunc();
    s32 temp_v0;

    temp_v0 = func_80800224_cadbfunc();
    if (temp_v0 == 0) {
        return 0;
    }
    func_800EE7F8(temp_v0, arg0);
    return 1;
}

s32 func_808002F8_cadbfunc(void) {
    s32 func_800A586C(void);
    u8 func_800A587C(void);
    s32 temp_v0;

    temp_v0 = func_800A587C();
    switch (temp_v0) {
        case 1:
            return func_800A586C() + 0xC;
        case 3:
            return func_800A586C() + 0xC;
        default:
            return 0;
    }
}

/* extern */

s32 cadbfunc_entrypoint_6(f32 *arg0, f32 *arg1) {
    s32 func_808002F8_cadbfunc(void);
    s32 temp_v0;

    temp_v0 = func_808002F8_cadbfunc();
    if (temp_v0 == 0) {
        return 0;
    }
    *arg0 = (*(f32 *)((s8 *)(temp_v0) + (0)));
    *arg1 = (*(f32 *)((s8 *)(temp_v0) + (4)));
    return 1;
}

/* extern */

s32 cadbfunc_entrypoint_7(f32 arg0, f32 arg1) {
    s32 func_808002F8_cadbfunc(void);
    s32 temp_v0;

    temp_v0 = func_808002F8_cadbfunc();
    if (temp_v0 == 0) {
        return 0;
    }
    (*(f32 *)((s8 *)(temp_v0) + (0))) = arg0;
    (*(f32 *)((s8 *)(temp_v0) + (4))) = arg1;
    return 1;
}

s32 func_808003EC_cadbfunc(void) {
    s32 func_800A586C(void);
    u8 func_800A587C(void);
    s32 temp_v0;

    temp_v0 = func_800A587C();
    switch (temp_v0) {
        case 1:
            return func_800A586C() + 0x14;
        case 3:
            return func_800A586C() + 0x14;
        default:
            return 0;
    }
}

/* extern */

s32 cadbfunc_entrypoint_8(f32 *arg0, f32 *arg1) {
    s32 func_808003EC_cadbfunc(void);
    s32 temp_v0;

    temp_v0 = func_808003EC_cadbfunc();
    if (temp_v0 == 0) {
        return 0;
    }
    *arg0 = (*(f32 *)((s8 *)(temp_v0) + (0)));
    *arg1 = (*(f32 *)((s8 *)(temp_v0) + (4)));
    return 1;
}

/* extern */

s32 cadbfunc_entrypoint_9(f32 arg0, f32 arg1) {
    s32 func_808003EC_cadbfunc(void);
    s32 temp_v0;

    temp_v0 = func_808003EC_cadbfunc();
    if (temp_v0 == 0) {
        return 0;
    }
    (*(f32 *)((s8 *)(temp_v0) + (0))) = arg0;
    (*(f32 *)((s8 *)(temp_v0) + (4))) = arg1;
    return 1;
}

s32 func_808004E0_cadbfunc(void) {
    s32 func_800A586C(void);
    u8 func_800A587C(void);
    s32 temp_v0;

    temp_v0 = func_800A587C();
    switch (temp_v0) {
        case 5:
            return func_800A586C() + 0x18;
        case 6:
            return func_800A586C() + 0x1C;
        default:
            return 0;
    }
}

/* extern */

s32 cadbfunc_entrypoint_10(f32 *arg0) {
    s32 func_808004E0_cadbfunc(void);
    s32 temp_v0;

    temp_v0 = func_808004E0_cadbfunc();
    if (temp_v0 == 0) {
        return 0;
    }
    *arg0 = (*(f32 *)((s8 *)(temp_v0) + (0)));
    return 1;
}

/* extern */

s32 cadbfunc_entrypoint_11(f32 arg0) {
    s32 func_808004E0_cadbfunc(void);
    s32 temp_v0;

    temp_v0 = func_808004E0_cadbfunc();
    if (temp_v0 == 0) {
        return 0;
    }
    (*(f32 *)((s8 *)(temp_v0) + (0))) = arg0;
    return 1;
}

s32 func_808005B8_cadbfunc(void) {
    s32 func_800A586C(void);
    u8 func_800A587C(void);
    s32 temp_v0;

    temp_v0 = func_800A587C();
    switch (temp_v0) {
        case 5:
            return func_800A586C() + 0x1C;
        case 6:
            return func_800A586C() + 0x20;
        case 8:
            return func_800A586C() + 0x1C;
        default:
            return 0;
    }
}

/* extern */

s32 cadbfunc_entrypoint_12(f32 *arg0) {
    s32 func_808005B8_cadbfunc(void);
    s32 temp_v0;

    temp_v0 = func_808005B8_cadbfunc();
    if (temp_v0 == 0) {
        return 0;
    }
    *arg0 = *(f32 *)temp_v0;
    return 1;
}

/* extern */

s32 cadbfunc_entrypoint_13(f32 arg0) {
    s32 func_808005B8_cadbfunc(void);
    s32 temp_v0;

    temp_v0 = func_808005B8_cadbfunc();
    if (temp_v0 == 0) {
        return 0;
    }
    *(f32 *)temp_v0 = arg0;
    return 1;
}

s32 func_808006A8_cadbfunc(void) {
    s32 func_800A586C(void);
    u8 func_800A587C(void);
    s32 temp_v0;

    temp_v0 = func_800A587C();
    switch (temp_v0) {
        case 5:
            return func_800A586C() + 0x20;
        case 6:
            return func_800A586C() + 0x24;
        case 8:
            return func_800A586C() + 0x20;
        default:
            return 0;
    }
}

/* extern */

s32 cadbfunc_entrypoint_14(f32 *arg0) {
    s32 func_808006A8_cadbfunc(void);
    s32 temp_v0;

    temp_v0 = func_808006A8_cadbfunc();
    if (temp_v0 == 0) {
        return 0;
    }
    *arg0 = *(f32 *)temp_v0;
    return 1;
}

/* extern */

s32 cadbfunc_entrypoint_15(f32 arg0) {
    s32 func_808006A8_cadbfunc(void);
    s32 temp_v0;

    temp_v0 = func_808006A8_cadbfunc();
    if (temp_v0 == 0) {
        return 0;
    }
    *(f32 *)temp_v0 = arg0;
    return 1;
}

s16 *func_80800798_cadbfunc(void) {
    s32 func_800A586C(void);
    u8 func_800A587C(void);
    s32 temp_v0;

    temp_v0 = func_800A587C();
    switch (temp_v0) {
        case 5:
            return (s16 *)(func_800A586C() + 0x28);
        case 6:
            return (s16 *)(func_800A586C() + 0x30);
        case 8:
            return (s16 *)(func_800A586C() + 0x2C);
        default:
            return NULL;
    }
}

/* extern */

s32 cadbfunc_entrypoint_16(s16 *arg0) {
    s16 *func_80800798_cadbfunc();
    s16 *temp_v0;

    temp_v0 = func_80800798_cadbfunc();
    if (temp_v0 == NULL) {
        return 0;
    }
    *arg0 = *temp_v0;
    return 1;
}

/* extern */

s32 cadbfunc_entrypoint_17(s16 arg0) {
    s16 *func_80800798_cadbfunc();
    s16 *temp_v0;

    temp_v0 = func_80800798_cadbfunc();
    if (temp_v0 == NULL) {
        return 0;
    }
    *temp_v0 = arg0;
    return 1;
}

s32 func_80800888_cadbfunc(void) {
    s32 func_800A586C(void);
    u8 func_800A587C(void);
    s32 temp_v0;

    temp_v0 = func_800A587C();
    switch (temp_v0) {
        case 3:
            return func_800A586C() + 0x1C;
        case 6:
            return func_800A586C() + 0x18;
        default:
            return 0;
    }
}

/* extern */

s32 cadbfunc_entrypoint_18(f32 *arg0) {
    s32 func_80800888_cadbfunc(void);
    f32 *temp_v0;

    temp_v0 = func_80800888_cadbfunc();
    if (temp_v0 == NULL) {
        return 0;
    }
    *arg0 = *temp_v0;
    return 1;
}

/* extern */

s32 cadbfunc_entrypoint_19(f32 arg0) {
    s32 func_80800888_cadbfunc(void);
    f32 *temp_v0;

    temp_v0 = func_80800888_cadbfunc();
    if (temp_v0 == NULL) {
        return 0;
    }
    *temp_v0 = arg0;
    return 1;
}

/* extern */

f32 *func_80800960_cadbfunc(void) {
    s32 func_800A586C(void);
    u8 func_800A587C(void);
    if (func_800A587C() == 3) {
        return func_800A586C() + 0x20;
    }
    return NULL;
}

/* extern */

s32 cadbfunc_entrypoint_20(f32 *arg0) {
    f32 *func_80800960_cadbfunc();
    f32 *temp_v0;

    temp_v0 = func_80800960_cadbfunc();
    if (temp_v0 == NULL) {
        return 0;
    }
    *arg0 = *temp_v0;
    return 1;
}

/* extern */

s32 cadbfunc_entrypoint_21(f32 arg0) {
    f32 *func_80800960_cadbfunc();
    f32 *temp_v0;

    temp_v0 = func_80800960_cadbfunc();
    if (temp_v0 == NULL) {
        return 0;
    }
    *temp_v0 = arg0;
    return 1;
}

/* extern */

s32 *func_80800A1C_cadbfunc(void) {
    s32 func_800A586C(void);
    u8 func_800A587C(void);
    if (func_800A587C() == 4) {
        return func_800A586C();
    }
    return NULL;
}

/* extern */

s32 cadbfunc_entrypoint_22(s32 *arg0) {
    s32 *func_80800A1C_cadbfunc();
    s32 *temp_v0;

    temp_v0 = func_80800A1C_cadbfunc();
    if (temp_v0 == NULL) {
        return 0;
    }
    *arg0 = *temp_v0;
    return 1;
}

/* extern */

s32 cadbfunc_entrypoint_23(s32 arg0) {
    s32 *func_80800A1C_cadbfunc();
    s32 *temp_v0;

    temp_v0 = func_80800A1C_cadbfunc();
    if (temp_v0 == NULL) {
        return 0;
    }
    *temp_v0 = arg0;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ca/dbfunc/func_80800AD8_cadbfunc.s")

/* extern */

s32 cadbfunc_entrypoint_24(s32 *arg0) {
    s32 *func_80800AD8_cadbfunc();
    s32 *temp_v0;

    temp_v0 = func_80800AD8_cadbfunc();
    if (temp_v0 == NULL) {
        return 0;
    }
    *arg0 = *temp_v0;
    return 1;
}

/* extern */

s32 cadbfunc_entrypoint_25(s32 arg0) {
    s32 *func_80800AD8_cadbfunc();
    s32 *temp_v0;

    temp_v0 = func_80800AD8_cadbfunc();
    if (temp_v0 == NULL) {
        return 0;
    }
    *temp_v0 = arg0;
    return 1;
}

/* extern */

s32 *func_80800BE0_cadbfunc(void) {
    s32 func_800A586C(void);
    u8 func_800A587C(void);
    if (func_800A587C() == 4) {
        return func_800A586C() + 0xC;
    }
    return NULL;
}

/* extern */

s32 cadbfunc_entrypoint_26(s32 *arg0) {
    s32 *func_80800BE0_cadbfunc();
    s32 *temp_v0;

    temp_v0 = func_80800BE0_cadbfunc();
    if (temp_v0 == NULL) {
        return 0;
    }
    *arg0 = *temp_v0;
    return 1;
}

/* extern */

s32 cadbfunc_entrypoint_27(s32 arg0) {
    s32 *func_80800BE0_cadbfunc();
    s32 *temp_v0;

    temp_v0 = func_80800BE0_cadbfunc();
    if (temp_v0 == NULL) {
        return 0;
    }
    *temp_v0 = arg0;
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ca/dbfunc/func_80800C9C_cadbfunc.s")

/* extern */

s32 cadbfunc_entrypoint_28(s32 arg0, s32 arg1) {
    s32 *func_80800C9C_cadbfunc();
    s32 *temp_v0;

    temp_v0 = func_80800C9C_cadbfunc();
    if (temp_v0 == NULL) {
        return 0;
    }
    if (arg1 != 0) {
        *temp_v0 |= arg0;
    } else {
        *temp_v0 &= ~arg0;
    }
    return 1;
}

/* extern */

s32 cadbfunc_entrypoint_29(s32 arg0, s32 *arg1) {
    s32 *func_80800C9C_cadbfunc();
    s32 *temp_v0;

    temp_v0 = func_80800C9C_cadbfunc();
    if (temp_v0 == NULL) {
        return 0;
    }
    if (*temp_v0 & arg0) {
        *arg1 = 1;
    } else {
        *arg1 = 0;
    }
    return 1;
}

/* extern */

s32 cadbfunc_entrypoint_30(s32 *arg0) {
    s32 *func_80800C9C_cadbfunc();
    s32 *temp_v0;

    temp_v0 = func_80800C9C_cadbfunc();
    if (temp_v0 == NULL) {
        return 0;
    }
    *arg0 = *temp_v0;
    return 1;
}

/* extern */

s32 cadbfunc_entrypoint_31(s32 arg0) {
    s32 *func_80800C9C_cadbfunc();
    s32 *temp_v0;

    temp_v0 = func_80800C9C_cadbfunc();
    if (temp_v0 == NULL) {
        return 0;
    }
    *temp_v0 = arg0;
    return 1;
}

/* extern */

f32 *func_80800E80_cadbfunc(void) {
    s32 func_800A586C(void);
    u8 func_800A587C(void);
    if (func_800A587C() == 4) {
        return func_800A586C() + 0x10;
    }
    return NULL;
}

/* extern */

s32 cadbfunc_entrypoint_32(f32 *arg0) {
    f32 *func_80800E80_cadbfunc();
    f32 *temp_v0;

    temp_v0 = func_80800E80_cadbfunc();
    if (temp_v0 == NULL) {
        return 0;
    }
    *arg0 = *temp_v0;
    return 1;
}

/* extern */

s32 cadbfunc_entrypoint_33(f32 arg0) {
    f32 *func_80800E80_cadbfunc();
    f32 *temp_v0;

    temp_v0 = func_80800E80_cadbfunc();
    if (temp_v0 == NULL) {
        return 0;
    }
    *temp_v0 = arg0;
    return 1;
}

/* extern */

s32 *func_80800F3C_cadbfunc(void) {
    s32 func_800A586C(void);
    u8 func_800A587C(void);
    if (func_800A587C() == 4) {
        return func_800A586C() + 0x14;
    }
    return NULL;
}

/* extern */

s32 cadbfunc_entrypoint_34(s32 *arg0) {
    s32 *func_80800F3C_cadbfunc();
    s32 *temp_v0;

    temp_v0 = func_80800F3C_cadbfunc();
    if (temp_v0 == NULL) {
        return 0;
    }
    *arg0 = *temp_v0;
    return 1;
}

/* extern */

s32 cadbfunc_entrypoint_35(s32 arg0) {
    s32 *func_80800F3C_cadbfunc();
    s32 *temp_v0;

    temp_v0 = func_80800F3C_cadbfunc();
    if (temp_v0 == NULL) {
        return 0;
    }
    *temp_v0 = arg0;
    return 1;
}
