#ifdef BT_NATIVE
#include "native_camera_db.h"
#define CAMERA_FIELD f32 *
#define CAMERA_BASE u8 *
#define CAMERA_VECTOR f32 *
#define CAMERA_PTR(offset) ((void *)(func_800A586C() + (offset)))
#else
#define CAMERA_FIELD s32
#define CAMERA_BASE s32
#define CAMERA_VECTOR s32
#define CAMERA_PTR(offset) (func_800A586C() + (offset))
#endif
#include "common.h"

/* extern */

CAMERA_FIELD func_80800000_cadbfunc(void) {
    CAMERA_BASE func_800A586C();
    u8 func_800A587C(void);
    s32 temp_v0;

    temp_v0 = func_800A587C();
    switch (temp_v0) {
    case 3:
        return CAMERA_PTR(0);
    case 1:
        return CAMERA_PTR(0);
    case 2:
        return CAMERA_PTR(0);
    case 5:
        return CAMERA_PTR(0);
    case 6:
        return CAMERA_PTR(0);
    case 8:
        return CAMERA_PTR(0);
    default:
        return 0;
    }
}

/* extern */

s32 cadbfunc_entrypoint_0(CAMERA_VECTOR arg0) {
#ifdef BT_NATIVE
    void func_800EE7F8(f32 *, f32 *);
#else
    s32 func_800EE7F8(s32, s32);
#endif
    CAMERA_FIELD func_80800000_cadbfunc();
    CAMERA_FIELD temp_v0;

    temp_v0 = func_80800000_cadbfunc();
    if (temp_v0 == 0) {
        return 0;
    }
    func_800EE7F8(arg0, temp_v0);
    return 1;
}

/* extern */

s32 cadbfunc_entrypoint_1(CAMERA_VECTOR arg0) {
#ifdef BT_NATIVE
    void func_800EE7F8(f32 *, f32 *);
#else
    s32 func_800EE7F8(s32, s32);
#endif
    CAMERA_FIELD func_80800000_cadbfunc();
    CAMERA_FIELD temp_v0;

    temp_v0 = func_80800000_cadbfunc();
    if (temp_v0 == 0) {
        return 0;
    }
    func_800EE7F8(temp_v0, arg0);
    return 1;
}

CAMERA_FIELD func_80800120_cadbfunc(void) {
    CAMERA_BASE func_800A586C(void);
    u8 func_800A587C(void);
    s32 temp_v0;

    temp_v0 = func_800A587C();
    switch (temp_v0) {
        case 2:
            return CAMERA_PTR(0xC);
        case 5:
            return CAMERA_PTR(0xC);
        case 6:
            return CAMERA_PTR(0xC);
        case 8:
            return CAMERA_PTR(0xC);
        default:
            return 0;
    }
}

/* extern */

s32 cadbfunc_entrypoint_2(CAMERA_VECTOR arg0) {
#ifdef BT_NATIVE
    void func_800EE7F8(f32 *, f32 *);
#else
    s32 func_800EE7F8(s32, s32);
#endif
    CAMERA_FIELD func_80800120_cadbfunc();
    CAMERA_FIELD temp_v0;

    temp_v0 = func_80800120_cadbfunc();
    if (temp_v0 == 0) {
        return 0;
    }
    func_800EE7F8(arg0, temp_v0);
    return 1;
}

/* extern */

s32 cadbfunc_entrypoint_3(CAMERA_VECTOR arg0) {
#ifdef BT_NATIVE
    void func_800EE7F8(f32 *, f32 *);
#else
    s32 func_800EE7F8(s32, s32);
#endif
    CAMERA_FIELD func_80800120_cadbfunc();
    CAMERA_FIELD temp_v0;

    temp_v0 = func_80800120_cadbfunc();
    if (temp_v0 == 0) {
        return 0;
    }
    func_800EE7F8(temp_v0, arg0);
    return 1;
}

CAMERA_FIELD func_80800224_cadbfunc(void) {
    CAMERA_BASE func_800A586C(void);
    u8 func_800A587C(void);
    s32 temp_v0;

    temp_v0 = func_800A587C();
    switch (temp_v0) {
        case 1:
            return CAMERA_PTR(0x1C);
        case 3:
            return CAMERA_PTR(0x24);
        default:
            return 0;
    }
}

/* extern */

s32 cadbfunc_entrypoint_4(CAMERA_VECTOR arg0) {
#ifdef BT_NATIVE
    void func_800EE7F8(f32 *, f32 *);
#else
    s32 func_800EE7F8(s32, s32);
#endif
    CAMERA_FIELD func_80800224_cadbfunc();
    CAMERA_FIELD temp_v0;

    temp_v0 = func_80800224_cadbfunc();
    if (temp_v0 == 0) {
        return 0;
    }
    func_800EE7F8(arg0, temp_v0);
    return 1;
}

/* extern */

s32 cadbfunc_entrypoint_5(CAMERA_VECTOR arg0) {
#ifdef BT_NATIVE
    void func_800EE7F8(f32 *, f32 *);
#else
    s32 func_800EE7F8(s32, s32);
#endif
    CAMERA_FIELD func_80800224_cadbfunc();
    CAMERA_FIELD temp_v0;

    temp_v0 = func_80800224_cadbfunc();
    if (temp_v0 == 0) {
        return 0;
    }
    func_800EE7F8(temp_v0, arg0);
    return 1;
}

CAMERA_FIELD func_808002F8_cadbfunc(void) {
    CAMERA_BASE func_800A586C(void);
    u8 func_800A587C(void);
    s32 temp_v0;

    temp_v0 = func_800A587C();
    switch (temp_v0) {
        case 1:
            return CAMERA_PTR(0xC);
        case 3:
            return CAMERA_PTR(0xC);
        default:
            return 0;
    }
}    typedef struct { f32 unk0; f32 unk4; } Objdbfunc_cadbfunc_entrypoint_6_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

s32 cadbfunc_entrypoint_6(f32 *arg0, f32 *arg1) {
    CAMERA_FIELD func_808002F8_cadbfunc(void);
    CAMERA_FIELD temp_v0;

    temp_v0 = func_808002F8_cadbfunc();
    if (temp_v0 == 0) {
        return 0;
    }
    *arg0 = (((Objdbfunc_cadbfunc_entrypoint_6_temp_v0 *)temp_v0)->unk0);
    *arg1 = (((Objdbfunc_cadbfunc_entrypoint_6_temp_v0 *)temp_v0)->unk4);
    return 1;
}    typedef struct { f32 unk0; f32 unk4; } Objdbfunc_cadbfunc_entrypoint_7_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

s32 cadbfunc_entrypoint_7(f32 arg0, f32 arg1) {
    CAMERA_FIELD func_808002F8_cadbfunc(void);
    CAMERA_FIELD temp_v0;

    temp_v0 = func_808002F8_cadbfunc();
    if (temp_v0 == 0) {
        return 0;
    }
    (((Objdbfunc_cadbfunc_entrypoint_7_temp_v0 *)temp_v0)->unk0) = arg0;
    (((Objdbfunc_cadbfunc_entrypoint_7_temp_v0 *)temp_v0)->unk4) = arg1;
    return 1;
}

CAMERA_FIELD func_808003EC_cadbfunc(void) {
    CAMERA_BASE func_800A586C(void);
    u8 func_800A587C(void);
    s32 temp_v0;

    temp_v0 = func_800A587C();
    switch (temp_v0) {
        case 1:
            return CAMERA_PTR(0x14);
        case 3:
            return CAMERA_PTR(0x14);
        default:
            return 0;
    }
}    typedef struct { f32 unk0; f32 unk4; } Objdbfunc_cadbfunc_entrypoint_8_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

s32 cadbfunc_entrypoint_8(f32 *arg0, f32 *arg1) {
    CAMERA_FIELD func_808003EC_cadbfunc(void);
    CAMERA_FIELD temp_v0;

    temp_v0 = func_808003EC_cadbfunc();
    if (temp_v0 == 0) {
        return 0;
    }
    *arg0 = (((Objdbfunc_cadbfunc_entrypoint_8_temp_v0 *)temp_v0)->unk0);
    *arg1 = (((Objdbfunc_cadbfunc_entrypoint_8_temp_v0 *)temp_v0)->unk4);
    return 1;
}    typedef struct { f32 unk0; f32 unk4; } Objdbfunc_cadbfunc_entrypoint_9_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

s32 cadbfunc_entrypoint_9(f32 arg0, f32 arg1) {
    CAMERA_FIELD func_808003EC_cadbfunc(void);
    CAMERA_FIELD temp_v0;

    temp_v0 = func_808003EC_cadbfunc();
    if (temp_v0 == 0) {
        return 0;
    }
    (((Objdbfunc_cadbfunc_entrypoint_9_temp_v0 *)temp_v0)->unk0) = arg0;
    (((Objdbfunc_cadbfunc_entrypoint_9_temp_v0 *)temp_v0)->unk4) = arg1;
    return 1;
}

CAMERA_FIELD func_808004E0_cadbfunc(void) {
    CAMERA_BASE func_800A586C(void);
    u8 func_800A587C(void);
    s32 temp_v0;

    temp_v0 = func_800A587C();
    switch (temp_v0) {
        case 5:
            return CAMERA_PTR(0x18);
        case 6:
            return CAMERA_PTR(0x1C);
        default:
            return 0;
    }
}    typedef struct { f32 unk0; } Objdbfunc_cadbfunc_entrypoint_10_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

s32 cadbfunc_entrypoint_10(f32 *arg0) {
    CAMERA_FIELD func_808004E0_cadbfunc(void);
    CAMERA_FIELD temp_v0;

    temp_v0 = func_808004E0_cadbfunc();
    if (temp_v0 == 0) {
        return 0;
    }
    *arg0 = (((Objdbfunc_cadbfunc_entrypoint_10_temp_v0 *)temp_v0)->unk0);
    return 1;
}    typedef struct { f32 unk0; } Objdbfunc_cadbfunc_entrypoint_11_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

s32 cadbfunc_entrypoint_11(f32 arg0) {
    CAMERA_FIELD func_808004E0_cadbfunc(void);
    CAMERA_FIELD temp_v0;

    temp_v0 = func_808004E0_cadbfunc();
    if (temp_v0 == 0) {
        return 0;
    }
    (((Objdbfunc_cadbfunc_entrypoint_11_temp_v0 *)temp_v0)->unk0) = arg0;
    return 1;
}

CAMERA_FIELD func_808005B8_cadbfunc(void) {
    CAMERA_BASE func_800A586C(void);
    u8 func_800A587C(void);
    s32 temp_v0;

    temp_v0 = func_800A587C();
    switch (temp_v0) {
        case 5:
            return CAMERA_PTR(0x1C);
        case 6:
            return CAMERA_PTR(0x20);
        case 8:
            return CAMERA_PTR(0x1C);
        default:
            return 0;
    }
}

/* extern */

s32 cadbfunc_entrypoint_12(f32 *arg0) {
    CAMERA_FIELD func_808005B8_cadbfunc(void);
    CAMERA_FIELD temp_v0;

    temp_v0 = func_808005B8_cadbfunc();
    if (temp_v0 == 0) {
        return 0;
    }
    *arg0 = *(f32 *)temp_v0;
    return 1;
}

/* extern */

s32 cadbfunc_entrypoint_13(f32 arg0) {
    CAMERA_FIELD func_808005B8_cadbfunc(void);
    CAMERA_FIELD temp_v0;

    temp_v0 = func_808005B8_cadbfunc();
    if (temp_v0 == 0) {
        return 0;
    }
    *(f32 *)temp_v0 = arg0;
    return 1;
}

CAMERA_FIELD func_808006A8_cadbfunc(void) {
    CAMERA_BASE func_800A586C(void);
    u8 func_800A587C(void);
    s32 temp_v0;

    temp_v0 = func_800A587C();
    switch (temp_v0) {
        case 5:
            return CAMERA_PTR(0x20);
        case 6:
            return CAMERA_PTR(0x24);
        case 8:
            return CAMERA_PTR(0x20);
        default:
            return 0;
    }
}

/* extern */

s32 cadbfunc_entrypoint_14(f32 *arg0) {
    CAMERA_FIELD func_808006A8_cadbfunc(void);
    CAMERA_FIELD temp_v0;

    temp_v0 = func_808006A8_cadbfunc();
    if (temp_v0 == 0) {
        return 0;
    }
    *arg0 = *(f32 *)temp_v0;
    return 1;
}

/* extern */

s32 cadbfunc_entrypoint_15(f32 arg0) {
    CAMERA_FIELD func_808006A8_cadbfunc(void);
    CAMERA_FIELD temp_v0;

    temp_v0 = func_808006A8_cadbfunc();
    if (temp_v0 == 0) {
        return 0;
    }
    *(f32 *)temp_v0 = arg0;
    return 1;
}

s16 *func_80800798_cadbfunc(void) {
    CAMERA_BASE func_800A586C(void);
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

CAMERA_FIELD func_80800888_cadbfunc(void) {
    CAMERA_BASE func_800A586C(void);
    u8 func_800A587C(void);
    s32 temp_v0;

    temp_v0 = func_800A587C();
    switch (temp_v0) {
        case 3:
            return CAMERA_PTR(0x1C);
        case 6:
            return CAMERA_PTR(0x18);
        default:
            return 0;
    }
}

/* extern */

s32 cadbfunc_entrypoint_18(f32 *arg0) {
    CAMERA_FIELD func_80800888_cadbfunc(void);
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
    CAMERA_FIELD func_80800888_cadbfunc(void);
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
    CAMERA_BASE func_800A586C(void);
    u8 func_800A587C(void);
    if (func_800A587C() == 3) {
        return CAMERA_PTR(0x20);
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
    CAMERA_BASE func_800A586C(void);
    u8 func_800A587C(void);
    if (func_800A587C() == 4) {
        return CAMERA_PTR(0);
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

s32 *func_80800AD8_cadbfunc(void) {
    CAMERA_BASE func_800A586C(void);
    u8 func_800A587C(void);
    s32 temp_v0;

    temp_v0 = func_800A587C();
    switch (temp_v0) {
        case 4:
            return (s32 *)(func_800A586C() + 8);
        case 6:
            return (s32 *)(func_800A586C() + 0x2C);
        case 7:
            return (s32 *)func_800A586C();
        case 8:
            return (s32 *)(func_800A586C() + 0x28);
        default:
            return NULL;
    }
}

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
    CAMERA_BASE func_800A586C(void);
    u8 func_800A587C(void);
    if (func_800A587C() == 4) {
        return CAMERA_PTR(0xC);
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

s32 *func_80800C9C_cadbfunc(void) {
    CAMERA_BASE func_800A586C(void);
    u8 func_800A587C(void);
    s32 temp_v0;

    temp_v0 = func_800A587C();
    switch (temp_v0) {
    case 4:
        return CAMERA_PTR(4);
    case 3:
        return CAMERA_PTR(0x30);
    case 1:
        return CAMERA_PTR(0x28);
    case 5:
        return CAMERA_PTR(0x24);
    case 6:
        return CAMERA_PTR(0x28);
    case 8:
        return CAMERA_PTR(0x24);
    default:
        return NULL;
    }
}

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
    CAMERA_BASE func_800A586C(void);
    u8 func_800A587C(void);
    if (func_800A587C() == 4) {
        return CAMERA_PTR(0x10);
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
    CAMERA_BASE func_800A586C(void);
    u8 func_800A587C(void);
    if (func_800A587C() == 4) {
        return CAMERA_PTR(0x14);
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
