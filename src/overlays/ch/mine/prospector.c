#include "common.h"

void func_80800024_chmineprospector(Actor *arg0);
void func_80105834(Actor *);
void func_80800340_chmineprospector(Actor *arg0, u8 *arg1);
void func_80800E00_chmineprospector(Actor *arg0);
void func_8080029C_chmineprospector(Actor *arg0);
void *func_80107C2C(s32 *, s32, void *, s32, void *);
s32 func_80800398_chmineprospector(Actor *arg0, s32 arg1, s32 arg2);
void func_80102EC0(s32);
void func_80101870(Actor *, void *);
void func_80800DF8_chmineprospector(s32 arg0);
void func_80800AF0_chmineprospector(Actor *arg0);
void func_80800BF4_chmineprospector(Actor *arg0);
s32 func_80800CD4_chmineprospector(Actor *arg0, s32 arg1, s32 arg2);

s32 D_80800F20_chmineprospector[] = {
    0x00000001, 0x0F8B0100, 0x00000001, 0x0F8D0200,
    0x00000200, 0x0FB80100, 0x00000200, 0x0FBA0200,
    0x00000400, 0x0FB90100, 0x00000400, 0x0F8D0200,
    0xFFFEDFFF, 0x120B0300
};

s32 D_80800F58_chmineprospector[] = {
    0x00000001, 0x0F8C0100, 0x00000001, 0x0F8E0200,
    0x00000200, 0x0FBB0100, 0x00000200, 0x0FBD0200,
    0x00000400, 0x0FBC0100, 0x00000400, 0x0FBE0200,
    0xFFFEDFFF, 0x120B0300
};

s32 D_80800F90_chmineprospector[] = {
    0x00000001, 0x0F8F0200, 0x00000200, 0x0F8F0200,
    0x00000400, 0x0F8F0200, 0xFFFEDFFF, 0x120B0300
};

u32 D_80800FB0_chmineprospector[] = {
    0x001304E4, 0x000D00C0, 0x00CC0000
};

s32 D_80800FBC_chmineprospector[] = {
    0x435C0000, 0x43340000, 0x43340000, 0x43200000
};

u32 D_80800FCC_chmineprospector[] = {
    0x00000000, 0x00000000, 0x40000000, 0x02A50009,
    0x40000000, 0x02A6000A, 0x41280000, 0x02A20009,
    0x40000000, 0x02A60092, 0x40266666, 0x02A3000A,
    0x40333333, 0x02A40009, 0x40333333, 0x02A40009,
    0x40333333, 0x02A40009
};

u32 D_80801014_chmineprospector[] = {
    0x00000000, 0x00000000, 0x3E99999A, 0x01DA0001,
    0x40066666, 0x01DB0001
};

BtFnWord D_8080102C_chmineprospector[] = {
    0x01950143, 0x07900001, (BtFnWord)D_80800FCC_chmineprospector, (BtFnWord)func_80800024_chmineprospector,
    (BtFnWord)func_80105834, (BtFnWord)func_80800340_chmineprospector, 0x00000000, 0x00000000,
    0x00000000, 0x40000122, (BtFnWord)func_80800E00_chmineprospector, 0x00000000,
    0x00140000, (BtFnWord)func_8080029C_chmineprospector, (BtFnWord)func_80107C2C, 0x82000592,
    (BtFnWord)func_80800398_chmineprospector, 0x00000000
};

BtFnWord D_80801074_chmineprospector[] = {
    0x01A60151, 0x07910001, 0x00000000, (BtFnWord)func_80102EC0,
    (BtFnWord)func_80105834, (BtFnWord)func_80101870, 0x00000000, 0x00000000,
    0x00000000, 0x40000800, 0x00000000, 0x00000000,
    0x00000000, (BtFnWord)func_80800DF8_chmineprospector, (BtFnWord)func_80107C2C, 0x80080C12,
    0x00000000, 0x00000000
};

BtFnWord D_808010BC_chmineprospector[] = {
    0x01A70152, 0x066D0001, (BtFnWord)D_80801014_chmineprospector, (BtFnWord)func_80102EC0,
    (BtFnWord)func_80800AF0_chmineprospector, (BtFnWord)func_80101870, 0x00000000, 0x3F800000,
    0x00000000, 0x40040120, (BtFnWord)func_80800E00_chmineprospector, 0x00000000,
    0x00000000, (BtFnWord)func_80800BF4_chmineprospector, (BtFnWord)func_80107C2C, 0x82000592,
    (BtFnWord)func_80800CD4_chmineprospector, 0x00000000
};

u32 D_80801104_chmineprospector[] = {
    0x00130451, 0x00180000
};

s32 D_8080110C_chmineprospector = 0x00820000;

void *func_80100094(Actor *, u32);

OSThread *chmineprospector_entrypoint_0(void)
{
    return (OSThread *) D_8080102C_chmineprospector;
}

OSThread *chmineprospector_entrypoint_1(void)
{
    return (OSThread *) D_80801074_chmineprospector;
}

OSThread *chmineprospector_entrypoint_2(void)
{
    return (OSThread *) D_808010BC_chmineprospector;
}

void func_80800024_chmineprospector(Actor *arg0) {
    void _chbadshad_entrypoint_1(void *arg0, void *arg1, f32 arg2);
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, u32, u32, f32 *, s16);
    void _suexpression_entrypoint_10(void *, Unk80132ED0 *, f32 *);
    void _suexpression_entrypoint_18(s8 *arg0, s32 arg1);
    s32 func_8008FB10(f32 *arg0, f32 arg1, f32 arg2, f32 arg3);
    s32 func_800DA298(s32 index);
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    s32 func_80101DDC(Actor *arg0);
    s32 func_80102320(Actor *arg0, f32 arg1, f32 arg2);
    void func_80102424(Actor *arg0, s32 arg1);
    s32 func_80800540_chmineprospector(Actor *arg0, s32 *arg1, s32 arg2, s32 arg3);
    void func_808005F0_chmineprospector(Actor *arg0);
    void func_80800638_chmineprospector(Actor *arg0);
    void func_8080068C_chmineprospector(Actor *arg0);
    void func_808009B0_chmineprospector(Actor *arg0, s32 arg1, s32 arg2);
    f32 position[3];
    _suexpression_entrypoint_10(func_80100094(arg0, 1U), arg0->unk0, 0);
    func_800EE7F8(position, (f32 *)&arg0->actorData[4]);
    position[1] = arg0->position[1];
    func_8008FB10(position, 200.0f, -20.0f, (s32)arg0->unk70_10 < 5 ? 120.0f : 80.0f);
    if (arg0->unk7C_12) {
        _chbadshad_entrypoint_1(arg0, position, arg0->scale);
    }
    switch (arg0->unk70_10) {
    case 1:
        _suexpression_entrypoint_18(func_80100094(arg0, 1U), 1);
        func_808005F0_chmineprospector(arg0);
        if (func_800DA298(0x5C)) {
            func_80800540_chmineprospector(arg0, D_80800F58_chmineprospector, 7, 2);
        }
        else {
            func_80800540_chmineprospector(arg0, D_80800F20_chmineprospector, 7, 2);
        }
        break;
    case 2:
        if (func_80101DDC(arg0)) {
            func_80102424(arg0, 3);
        }
        break;
    case 3:
        if (!func_80102320(arg0, 0.38f, 0.8f)) {
            _suexpression_entrypoint_18(func_80100094(arg0, 1U), 1);
        }
        func_80800638_chmineprospector(arg0);
        break;
    case 4:
        if (func_80101DDC(arg0)) {
            func_80102424(arg0, 1);
        }
        break;
    case 5:
        if (func_80101DDC(arg0)) {
            func_808009B0_chmineprospector(arg0, 3, 1);
            _subaddiedialog_entrypoint_11(arg0->unk0, 0xF90, 0xE, (f32 *)&arg0->actorData[4], 0x3F);
            func_80102424(arg0, 7);
        }
        _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80801104_chmineprospector, 0.8f);
        break;
    case 6:
        func_8080068C_chmineprospector(arg0);
        func_80800540_chmineprospector(arg0, D_80800F90_chmineprospector, 4, 7);
        break;
    case 7:
        func_8080068C_chmineprospector(arg0);
        break;
    case 8:
        func_8080068C_chmineprospector(arg0);
        break;
    }
}

void func_8080029C_chmineprospector(Actor *arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 _subaddiemarker_entrypoint_0(Actor *, s32, f32 *, s32);
    s32 func_800DA298(s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_80102424(Actor *, s32);
    f32 marker[6];
    f32 *data;

    data = func_80100094(arg0, 0U);
    func_800EE7F8((f32 *)&arg0->actorData[4], arg0->position);
    if (_subaddiemarker_entrypoint_0(arg0, 0x152, marker, 1) != 0) {
        func_800EE7F8(data, marker);
        data[3] = marker[4];
    }
    if (_glcutDll_entrypoint_20() != 0) {
        func_80102424(arg0, 8);
        return;
    }
    if (func_800DA298(0x83) != 0) {
        func_80102424(arg0, 6);
    }
}

void func_80800340_chmineprospector(Actor *arg0, u8 *arg1) {
    void func_800DBEFC(s32 *, s32, BtIntPtr);
    void func_80101870(Actor* arg0, void* arg1);
    OSThread * func_80104130(void);
    func_80101870(arg0, arg1);
    if (arg0->unk7C_12) {
        func_800DBEFC((s32 *) func_80104130(), 4, (BtIntPtr) &arg0->actorData[4]);
        *(f32 *) &arg0->actorData[5] = arg0->position[1];
    }
}

s32 func_80800398_chmineprospector(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _gcdialogcamera_entrypoint_3(s32 *, f32);
    void _gcdialogcamera_entrypoint_4(f32 *);
    s32 _suexpression_entrypoint_12(void *, s32, s32);
    BtIntPtr _suexpression_entrypoint_7(Actor *, s32, s32);
    void func_800DA544(GameFlag);
    void func_80102424(Actor *, s32);
    void func_808006EC_chmineprospector(Actor *, s32, s32);
    void func_8080084C_chmineprospector(Actor *, s32, s32);
    void func_808008A4_chmineprospector(Actor *);
    s32 func_80800910_chmineprospector(Actor *, s32, s32);
    void func_80800970_chmineprospector(Actor *);

    s32 *data;

    switch (arg1) {
    case 0xB:
        if (arg2 == 8) {
            func_80800970_chmineprospector(arg0);
            return 4;
        }
        return 3;
    case 0x2E:
        func_808006EC_chmineprospector(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
        break;
    case 0x2F:
        func_8080084C_chmineprospector(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
        break;
    case 0x31:
        func_800DA544(0x83);
        func_80102424(arg0, 5);
        break;
    case 0x3D:
        func_808008A4_chmineprospector(arg0);
        break;
    case 0x52:
        _gcdialogcamera_entrypoint_3(D_80800FBC_chmineprospector, arg0->scale);
        _gcdialogcamera_entrypoint_4((f32 *)&arg0->actorData[4]);
        break;
    case 0x57:
        return func_80800910_chmineprospector(arg0, arg2 & 0xFFFF, (u32)(arg2 & 0xFFFF0000) >> 16);
    case 0x95:
        data = func_80100094(arg0, 0U);
        _suexpression_entrypoint_7(arg0, 1, 0x3F);
        _suexpression_entrypoint_12(func_80100094(arg0, 1U), 0x42700000, 0x41A00000);
        data[4] = 0;
        break;
    default:
        return 0;
    }
    return 1;
}

s32 func_80800540_chmineprospector(Actor *arg0, s32 *arg1, s32 arg2, s32 arg3) {
    s32 _subaddiedialog_entrypoint_8(BtIntPtr, void *, s32 *, s32 *, s32);
    s32 _subaddiedialog_entrypoint_9(BtIntPtr, s32, s32 *, s32);
    void func_808009B0_chmineprospector(Actor *, s32, s32);

    extern s8 D_8080111A_chmineprospector;
    s32 temp_v0;

    D_8080111A_chmineprospector = arg3;
    temp_v0 = _subaddiedialog_entrypoint_8((BtIntPtr)arg0, (u8 *)arg0 + 0x28, &D_8080110C_chmineprospector, arg1, arg2);
    if (temp_v0 == 0) {
        return 0;
    }
    switch (_subaddiedialog_entrypoint_9((BtIntPtr)arg0, temp_v0, arg1, arg2)) {
    case 1:
        func_808009B0_chmineprospector(arg0, 3, 0);
        break;
    case 2:
        func_808009B0_chmineprospector(arg0, 3, 1);
        break;
    }
    return 1;
}

void func_808005F0_chmineprospector(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
    s32 func_800DC298(f32);

    if (func_800DC298(0.2f) != 0) {
        _subaddieaudioquick_entrypoint_3(arg0, (f32 *) ((u8 *) arg0 + 0x28), D_80800FB0_chmineprospector, 0.8f);
    }
}

void func_80800638_chmineprospector(Actor *arg0) {

    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
    extern u32 D_8080111C_chmineprospector;
    f32 *sp1C[2];

    sp1C[1] = (f32 *) ((u8 *) arg0 + 0x28);
    _subaddieaudioquick_entrypoint_3(arg0, sp1C[1], &D_8080111C_chmineprospector, 0.03f);
    _subaddieaudioquick_entrypoint_3(arg0, sp1C[1], D_80800FB0_chmineprospector, 0.65f);
}

void func_8080068C_chmineprospector(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
    void _subaddieaudioquick_entrypoint_4(Actor*, f32*, u32*, u32*);
    s32 func_800DC298(f32);
    extern u32 D_80801128_chmineprospector;
    extern u32 D_80801134_chmineprospector;
    extern u32 D_80801144_chmineprospector;
    f32 * volatile sp1C;

    _subaddieaudioquick_entrypoint_4(arg0, sp1C = (f32 *) ((u8 *) arg0 + 0x28), &D_80801128_chmineprospector, &D_80801144_chmineprospector);
    if (func_800DC298(0.3f) != 0) {
        _subaddieaudioquick_entrypoint_3(arg0, sp1C, &D_80801134_chmineprospector, 0.5f);
    }
}

void func_808006EC_chmineprospector(Actor *arg0, s32 arg1, s32 arg2) {
    void func_80102424(Actor *, s32);
    void _glcutDll_entrypoint_6(u32, u32);
    s32 _subaddiedialog_entrypoint_10(s32);
    s32 _subaddiedialog_entrypoint_9(BtIntPtr, s32, s32 *, s32);
    s32 func_800D1000(s32, s32, s32 *, s32, BtIntPtr);
    void func_80800970_chmineprospector(Actor *);
    void func_80800A64_chmineprospector(Actor *, s32, s32);

    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;

    if (arg1 == 0xF90) {
        func_800D1000(0x10, 1, NULL, 1, 0);
        func_80800A64_chmineprospector(arg0, 8, 0x30);
        func_80102424(arg0, 6);
        return;
    }
    sp34 = _subaddiedialog_entrypoint_9((BtIntPtr)arg0, arg1, D_80800F20_chmineprospector, 7);
    sp30 = _subaddiedialog_entrypoint_9((BtIntPtr)arg0, arg1, D_80800F58_chmineprospector, 7);
    sp2C = _subaddiedialog_entrypoint_9((BtIntPtr)arg0, arg1, D_80800F90_chmineprospector, 4);
    if (_subaddiedialog_entrypoint_10(sp2C) != 0) {
        func_80800970_chmineprospector(arg0);
        func_80102424(arg0, 6);
        return;
    }
    if (sp34 == 1) {
        func_80800970_chmineprospector(arg0);
        func_80102424(arg0, 4);
        _glcutDll_entrypoint_6(0xB9, 0xC);
        return;
    }
    if (_subaddiedialog_entrypoint_10(sp30) == 0) {
        sp28 = arg0->unk70_10 == 7 ? 6 : 4;
        func_80800970_chmineprospector(arg0);
        func_80102424(arg0, sp28);
    }
}

void func_8080084C_chmineprospector(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _subaddiedialog_entrypoint_10(s32);
    s32 _subaddiedialog_entrypoint_9(BtIntPtr, s32, s32 *, s32);
    s32 func_80108B04(BtIntPtr, s32);
    void func_80800A64_chmineprospector(Actor *, s32, s32);

    if (_subaddiedialog_entrypoint_10(_subaddiedialog_entrypoint_9((BtIntPtr)arg0, arg1, D_80800F58_chmineprospector, 7)) != 0) {
        func_80800A64_chmineprospector(arg0, 1, 0x30);
        func_80108B04(arg0, 0);
    }
}

void func_808008A4_chmineprospector(Actor *arg0) {
    void func_80105A9C(Actor *, f32);
    Actor *func_80106790(Unk80132ED0 *);
    Actor *func_8010856C(s32, f32 *, f32 *);
    void func_80108944(Actor *, Actor *);
    Actor *sp2C;
    Unk80132ED0 *sp28;
    f32 *data;
    f32 sp1C[2];

    sp28 = arg0->unk0;
    data = func_80100094(arg0, 0U);
    sp1C[0] = 0.0f;
    sp1C[1] = data[3];
    sp2C = func_8010856C(0x152, data, sp1C);
    func_80108944(sp2C, func_80106790(sp28));
    func_80105A9C(sp2C, 450.0f);
}

s32 func_80800910_chmineprospector(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _gcdialogcamera_entrypoint_0(s32, s32);
    void *func_80100094(Actor *, u32);
    void func_808009B0_chmineprospector(Actor *, s32, s32);
    s32 *data;

    if (_gcdialogcamera_entrypoint_0(arg1, arg2) != 0) {
        data = func_80100094(arg0, 0U);
        if (data[4] != 2) {
            func_808009B0_chmineprospector(arg0, 2, 1);
        }
        return 2;
    }
    return 1;
}    typedef struct { u8 pad0[0x10]; s32 unk10; } Objprospector_func_80800970_chmineprospector_sp1C; /* offsets.py genstruct: fields from raw offsets on sp1C; rename once understood */ typedef struct { u8 pad0[0x10]; s32 unk10; } Objprospector_func_80800970_chmineprospector_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void func_80800970_chmineprospector(Actor *arg0) {
    void _capod_entrypoint_3(s32);
    void *temp_v0;
    void *sp1C;

    temp_v0 = func_80100094(arg0, 0);
    if (((Objprospector_func_80800970_chmineprospector_temp_v0 *)temp_v0)->unk10 != 0) {
        sp1C = temp_v0;
        _capod_entrypoint_3(0);
        ((Objprospector_func_80800970_chmineprospector_sp1C *)sp1C)->unk10 = 0;
    }
}

void func_808009B0_chmineprospector(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    void _capod_entrypoint_2(Unk80132ED0 *, u32, s32);
    void _capod_entrypoint_7(s32, s32);
    s32 _capod_entrypoint_8(s32);
    s32 _gcdialogcamera_entrypoint_3(s32 *, f32);
    void _gcdialogcamera_entrypoint_4(f32 *);
    void _gcdialogcamera_entrypoint_5(f32 *);
    void _gcdialogcamera_entrypoint_8(void);

    s32 *data;

    data = func_80100094(arg0, 0U);
    switch (data[4]) {
        case 0:
            _capod_entrypoint_2(arg0->unk0, 0xF, 0);
        case 1:
            _capod_entrypoint_8(1);
            data[4] = 2;
            _gcdialogcamera_entrypoint_3(D_80800FBC_chmineprospector, arg0->scale);
            _gcdialogcamera_entrypoint_4((f32 *)&arg0->actorData[4]);
            _gcdialogcamera_entrypoint_5(arg0->rotation);
            _gcdialogcamera_entrypoint_8();
        case 2:
            _capod_entrypoint_7(arg1, arg2);
            break;
    }
}

void func_80800A64_chmineprospector(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    void _capod_entrypoint_2(Unk80132ED0 *, u32, s32);
    void _capod_entrypoint_6(Unk80132ED0 *, s32, s32);
    s32 *data;

    data = func_80100094(arg0, 0U);
    switch (data[4]) {
        case 0:
            _capod_entrypoint_2(arg0->unk0, 0xF, arg2);
        case 2:
            data[4] = 1;
        case 1:
            _capod_entrypoint_6(arg0->unk0, arg1, arg2);
            break;
    }
}

void func_80800AF0_chmineprospector(Actor *arg0) {
    void _suexpression_entrypoint_10(void *, Unk80132ED0 *, f32 *);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, u32, u32, f32 *, s16);
    s32 func_8008FB10(f32 *, f32, f32, f32);
    s32 func_80101180(s32, s32, BtIntPtr);
    void func_80102424(Actor *, s32);
    void func_80105834(Actor *);
    s32 func_80105998(Actor *, f32);
    s32 func_80105A5C(Actor *);
    void func_80800D34_chmineprospector(Actor *);
    void func_80800D8C_chmineprospector(Actor *);
    register u32 state;
    f32 *volatile position;

    _suexpression_entrypoint_10(func_80100094(arg0, 1U), arg0->unk0, 0);
    func_8008FB10(position = arg0->position, 60.0f, 0.0f, 40.0f);
    state = arg0->unk70_10;
    switch (state) {
        case 1:
            func_80105834(arg0);
            if (func_80105998(arg0, 0.2f)) {
                _subaddiedialog_entrypoint_11(arg0->unk0, 0xF91, 6, position, 0x32);
            }
            if (func_80105998(arg0, 0.6f)) {
                func_80101180(0x143, 0x31, 0);
            }
            if (func_80105A5C(arg0)) {
                func_80102424(arg0, 2);
            }
            func_80800D34_chmineprospector(arg0);
            break;
        case 2:
            func_80800D8C_chmineprospector(arg0);
            break;
    }
}

/* extern */

void func_80800BF4_chmineprospector(Actor *arg0) {
    struct Unk800C7A68;
    s32 _glcutDll_entrypoint_20();
    void func_800C7A68(struct Unk800C7A68 *, f32, f32 *);
    void *func_800D7520(s32);
    s32 func_800DA298(s32);
    void func_800FFAB0(Actor *);
    void func_80102424(Actor *, s32);
    void *func_80105494(Actor *);
    void func_80105A9C(Actor *, f32);
    if ((func_800DA298(0x5C) == 0) && (_glcutDll_entrypoint_20() == 0)) {
        func_800FFAB0(arg0);
        return;
    }
    if ((func_800DA298(0x83) != 0) || (_glcutDll_entrypoint_20() != 0)) {
        func_800C7A68(func_800D7520((s32) (*(s32 *)func_80105494(arg0) << 0x15) >> 0x16), 0.999f, arg0->position);
        func_80102424(arg0, 2);
        goto block_8;
    }
    if (arg0->unk7A_5) {
        func_800FFAB0(arg0);
        return;
    }
block_8:
    func_80105A9C(arg0, 450.0f);
}

s32 func_80800CD4_chmineprospector(Actor *arg0, s32 arg1, s32 arg2) {
    BtIntPtr _suexpression_entrypoint_7(Actor *, s32, s32);
    s32 _suexpression_entrypoint_12(void *, s32, s32);
    if (arg1 == 0x95) {
        _suexpression_entrypoint_7(arg0, 1, 0x32);
        _suexpression_entrypoint_12(func_80100094(arg0, 1), 0x42700000, 0x41A00000);
    } else {
        return 0;
    }
    return 1;
}

void func_80800D34_chmineprospector(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32 *, u32 *);
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
    s32 func_800DC298(f32);
    extern s32 D_80801168_chmineprospector;
    extern s32 D_80801178_chmineprospector;
    f32 * volatile sp1C;

    _subaddieaudioquick_entrypoint_3(arg0, sp1C = &arg0->position[0], &D_80801168_chmineprospector, 0.5f);
    if (func_800DC298(0.1f) != 0) {
        _subaddieaudioquick_entrypoint_2(arg0, sp1C, &D_80801178_chmineprospector);
    }
}

void func_80800D8C_chmineprospector(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, void *, f32);
    void _subaddieaudioquick_entrypoint_4(Actor*, f32*, u32*, u32*);
    extern u32 D_80801184_chmineprospector;
    extern u32 D_80801194_chmineprospector;
    extern u32 D_808011A0_chmineprospector;
    extern u32 D_808011AC_chmineprospector;

    f32 * volatile temp_a1;

    _subaddieaudioquick_entrypoint_4(arg0, temp_a1 = &arg0->position[0], &D_80801184_chmineprospector, &D_808011AC_chmineprospector);
    _subaddieaudioquick_entrypoint_3(arg0, temp_a1, &D_80801194_chmineprospector, 0.75f);
    _subaddieaudioquick_entrypoint_3(arg0, temp_a1, &D_808011A0_chmineprospector, 0.6f);
}

void func_80800DF8_chmineprospector(s32 arg0) 
{
}
/* extern */

void func_80800E00_chmineprospector(Actor *arg0) {
    s32 _suexpression_entrypoint_8(Actor *, s32);
    if (func_80100094(arg0, 1U) != NULL) {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
