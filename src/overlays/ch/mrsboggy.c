#include "ch/mrsboggy.h"

void func_80102EC0(s32);
void func_80800088_chmrsboggy(Actor *arg0);
void func_80101870(Actor *, void *);
void func_80800290_chmrsboggy(Actor* arg0);
void func_8080000C_chmrsboggy(BtIntPtr arg0);
void *func_80107C2C(s32 *, s32, void *, s32, void *);
s32 func_808002B0_chmrsboggy(Actor *arg0, s32 arg1, s32 arg2);

s32 D_80800A20_chmrsboggy[] = {
    0x00000001, 0x109A0100, 0x00000001, 0xFFFF0200,
    0x00000200, 0x110C0100, 0x00000200, 0xFFFF0200,
    0x00000400, 0x110D0100, 0x00000400, 0xFFFF0200,
    0xFFFEDFFF, 0x120B0300
};

s32 D_80800A58_chmrsboggy[] = {
    0x00000201, 0x109E0100, 0x00000201, 0x109E0200,
    0x00000400, 0x110E0100, 0x00000400, 0x110E0200,
    0xFFFEDFFF, 0x120B0300
};

u32 D_80800A80_chmrsboggy[] = {
    0x43570000, 0x43570000, 0x43570000, 0x42D70000
};

u32 D_80800A90_chmrsboggy[] = {
    0x00000000, 0x00000000, 0x41200000, 0x00FF0001,
    0x41200000, 0x00FF0001, 0x3FA66666, 0x01020002,
    0x3FA66666, 0x01030001, 0x40A00000, 0x01010002,
    0x40066666, 0x03EE0001, 0x40066666, 0x03EE0001,
    0x3F4CCCCD, 0x01040001
};

BtFnWord D_80800AD8_chmrsboggy[] = {
    0x0191013F, 0x06B70001, (BtFnWord)D_80800A90_chmrsboggy, (BtFnWord)func_80102EC0,
    (BtFnWord)func_80800088_chmrsboggy, (BtFnWord)func_80101870, 0x05DC0000, 0x3FE00000,
    0x00000000, 0x40040121, (BtFnWord)func_80800290_chmrsboggy, 0x00000000,
    0x00000000, (BtFnWord)func_8080000C_chmrsboggy, (BtFnWord)func_80107C2C, 0x84107416,
    (BtFnWord)func_808002B0_chmrsboggy, 0x00000000
};

s32 D_80800B20_chmrsboggy[] = {
    0x008B0000, 0x012C003E, 0x0000000E, 0x063C0700
};

s32 D_80800B30_chmrsboggy[] = {
    0x008B0000, 0x012C003E, 0x0000000E, 0x063C0200
};

OSThread *chmrsboggy_entrypoint_0(void)
{

    return (OSThread *) D_80800AD8_chmrsboggy;
}

/* extern */

void func_8080000C_chmrsboggy(BtIntPtr arg0) {
    s32 func_800DA298(s32);
    void func_800DA524(s32);
    s32 func_800DA980(s32, s32);
    s32 func_800FFAB0(BtIntPtr);
    void func_80102424(Actor *, s32);
    s32 func_80105A9C(BtIntPtr, s32);
    s32 func_80105BAC(BtIntPtr);
    if (func_800DA980(0x8C, 3) == 3) {
        if (func_800DA298(0x1CD) != 0) {
            func_800FFAB0(arg0);
            return;
        }
        func_800DA524(0x8B);
        func_80102424(arg0, 6);
        goto block_4;
    }
block_4:
    func_80105A9C(arg0, 0x43AF0000);
    func_80105BAC(arg0);
}

void func_80800088_chmrsboggy(Actor *arg0) {
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, u32, u32, f32 *, s16);
    s32 _subaddiedialog_entrypoint_8(BtIntPtr, void *, s32 *, s32 *, s32);
    s32 _subaddiedialog_entrypoint_9(BtIntPtr, s32, s32 *, s32);
    Actor *_subaddiefind_entrypoint_2(s32, BtIntPtr);
    s32 _sudeflect_entrypoint_1(f32 *arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4);
    void _suexpression_entrypoint_10(u32 *, Unk80132ED0 *, BtUIntPtr);
    BtIntPtr _suexpression_entrypoint_20();
    s32 func_800DA980(s32, s32);
    u32 func_800F54E4(void);
    void func_800F82D4(BtIntPtr, s32);
    s32 func_800FFAB0(BtIntPtr);
    s32 func_80101DDC(Actor *);
    void func_80102424(Actor *, s32);
    s32 func_80105230(Actor *, f32 *);
    void func_80105834(Actor *);
    s32 func_80105A5C(Actor *);
    void func_80800568_chmrsboggy(void *);
    void func_80800790_chmrsboggy(void *);
    void func_808007CC_chmrsboggy(Actor *, s32, s32);
    void func_80800878_chmrsboggy(Actor *, s32, s32, Unk80132ED0 *);
    void func_80800910_chmrsboggy(Actor *, s32, s32);
    f32 *sp28;
    s32 temp_v0;

    sp28 = arg0->position;
    _sudeflect_entrypoint_1(sp28, 200.0f, 0.0f, 100.0f, 10);
    if (_suexpression_entrypoint_20(arg0) != 0) {
        _suexpression_entrypoint_10(_suexpression_entrypoint_20(arg0), arg0->unk0, 0);
    }
    switch (arg0->unk70_10) {
    case 1:
        func_80800568_chmrsboggy(arg0);
        break;
    case 6:
        temp_v0 = _subaddiedialog_entrypoint_8(arg0, sp28, D_80800B20_chmrsboggy, D_80800A58_chmrsboggy, 5);
        if (temp_v0 != 0 && _subaddiedialog_entrypoint_9(arg0, temp_v0, D_80800A58_chmrsboggy, 5) != 3) {
            func_808007CC_chmrsboggy(arg0, 3, 0);
        }
        break;
    case 3:
        if (func_80101DDC(arg0) != 0) {
            func_80102424(arg0, 4);
        }
        break;
    case 5:
        if (func_80101DDC(arg0) != 0) {
            func_800F82D4(func_800F54E4(), 0);
            if (func_800DA980(0x8C, 3) == 3) {
                func_80800910_chmrsboggy(arg0, 0x4B, 0x10);
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x109E, 0x4E, sp28, 0x3E);
                func_80102424(arg0, 7);
            } else {
                func_80800878_chmrsboggy(arg0, 0xE, 0x31, _subaddiefind_entrypoint_2(0x142, 0)->unk0);
                func_80102424(arg0, 1);
            }
        }
        break;
    case 8:
        func_80105834(arg0);
        func_80105230(arg0, 0);
        if (func_80105A5C(arg0) != 0) {
            func_80800790_chmrsboggy(arg0);
            func_800FFAB0(arg0);
        }
        break;
    }
}

void func_80800290_chmrsboggy(Actor* arg0)
{
    func_80800548_chmrsboggy(arg0);
}

s32 func_808002B0_chmrsboggy(Actor *arg0, s32 arg1, s32 arg2) { u32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, u32, u32, f32 *, s16); void func_80102424(Actor *, s32); void _gcdialogcamera_entrypoint_3(f32 *, f32); s32 _glsplinefind_entrypoint_0(s32 arg0, f32 arg1[3]); void func_800DA524(s32); void func_800DA544(s32); s32 func_800DA980(s32 startIndex, s32 length); u32 func_800F54E4(void); void func_800F82D4(BtIntPtr arg0,s32 arg1); void func_808004F4_chmrsboggy(BtIntPtr arg0); void func_808005D8_chmrsboggy(Actor *arg0, s32 arg1, s32 arg2); s32 func_8080070C_chmrsboggy(BtIntPtr arg0, s32 arg1, s32 arg2); s32 func_80800738_chmrsboggy(void *arg0, s32 arg1, s32 arg2); void func_80800790_chmrsboggy(void *arg0); void func_808007CC_chmrsboggy(Actor *arg0, s32 arg1, s32 arg2); s32 func_80800990_chmrsboggy(void); const s16 *payload = (const s16 *)&arg2; switch ((int)arg1) { case 46: func_808005D8_chmrsboggy(arg0, payload[0], payload[1]); break; case 48: return func_8080070C_chmrsboggy((BtIntPtr)arg0, payload[0], payload[1]); case 49: if (arg0->unk70_10 == 2) { return 0; } func_800DA544(0x8B); func_80102424(arg0, 3); func_808007CC_chmrsboggy(arg0, 3, 1); _subaddiedialog_entrypoint_11(arg0->unk0, 0x109D, 6, arg0->position, 0x3E); func_800F82D4(func_800F54E4(), 2); break; case 41: func_808004F4_chmrsboggy((BtIntPtr)arg0); break; case 42: func_80800548_chmrsboggy(arg0); break; case 0x52: _gcdialogcamera_entrypoint_3(D_80800A80_chmrsboggy, arg0->scale); break; case 0x57: return func_80800738_chmrsboggy(arg0, arg2 & 0xFFFF, (u32)(arg2 & 0xFFFF0000) >> 16); case 0x4F: func_80800790_chmrsboggy(arg0); break; case 0xB8: return func_80800990_chmrsboggy() ? 0x109C : 0x109B; case 0x95: arg0->actorData[5] = _glsplinefind_entrypoint_0(0x357, (f32 *)arg0->actorData); break; case 35: if (func_800DA980(0x8C, 3) == 3) { func_800DA524(0x8B); func_80102424(arg0, 6); } break; default: return 0; } return 1; }

/* extern */

void func_808004F4_chmrsboggy(BtIntPtr arg0) {
    s32 _suexpression_entrypoint_12(BtIntPtr, s32, s32);
    s32 _suexpression_entrypoint_17(BtIntPtr, s32);
    BtIntPtr _suexpression_entrypoint_20();
    BtIntPtr _suexpression_entrypoint_7(BtIntPtr, s32, s32);
    BtIntPtr sp1C;
    BtIntPtr temp_v0;

    if (_suexpression_entrypoint_20() == 0) {
        temp_v0 = _suexpression_entrypoint_7(arg0, 1, 0x3E);
        sp1C = temp_v0;
        _suexpression_entrypoint_12(temp_v0, 0x42700000, 0x41A00000);
        _suexpression_entrypoint_17(sp1C, 0x3E8);
    }
}

void func_80800548_chmrsboggy(Actor* arg0) 
{
    _suexpression_entrypoint_8(arg0, 1);
}
void func_80800568_chmrsboggy(void *arg0) {
    s32 _subaddiedialog_entrypoint_8(BtIntPtr, void *, s32 *, s32 *, s32);
    s32 _subaddiedialog_entrypoint_9(BtIntPtr, s32, s32 *, s32);
    void func_808007CC_chmrsboggy(Actor *, s32, s32);
    s32 temp_v0;

    temp_v0 = _subaddiedialog_entrypoint_8((BtIntPtr)arg0, (s8 *)arg0 + 4, D_80800B30_chmrsboggy, D_80800A20_chmrsboggy, 7);
    if ((temp_v0 != 0) && (_subaddiedialog_entrypoint_9((BtIntPtr)arg0, temp_v0, D_80800A20_chmrsboggy, 7) != 3)) {
        func_808007CC_chmrsboggy(arg0, 3, 0);
    }
}

void func_808005D8_chmrsboggy(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _subaddieDll_entrypoint_4(void *, s32);
    s32 _subaddiedialog_entrypoint_9(BtIntPtr, s32, s32 *, s32);
    Actor *_subaddiefind_entrypoint_2(s32, BtIntPtr);
    s32 func_800D1000(s32, s32, f32 *, s32, BtIntPtr);
    void func_800DA524(s32);
    void func_800DA544(s32);
    void func_80102424(Actor *, s32);
    void func_80102FE8(void *, s32);
    void func_80800790_chmrsboggy(void *);
    void func_80800878_chmrsboggy(Actor *, s32, s32, Unk80132ED0 *);
    s32 temp_v0;

    if (arg1 == 0x109D) {
        func_80102424(_subaddiefind_entrypoint_2(0x142, 0), 0xE);
        func_80102424(arg0, 5);
        func_80800878_chmrsboggy(arg0, 0x99, 0x30, NULL);
        return;
    }
    temp_v0 = _subaddiedialog_entrypoint_9((BtIntPtr)arg0, arg1, D_80800A58_chmrsboggy, 5);
    if ((temp_v0 != 3) && (temp_v0 != 0)) {
        func_80102FE8(arg0, 0);
        func_80102424(arg0, 8);
        _subaddieDll_entrypoint_4(arg0, 1);
        func_800D1000(0x1B, 1, arg0->position, 0, 0);
        func_800DA544(0x1CD);
        func_800DA524(0xB8);
        func_800DA524(0xB9);
        func_800DA524(0xBA);
        func_800DA524(0x8B);
        func_80800878_chmrsboggy(arg0, 0xE, 0x31, NULL);
        return;
    }
    if (arg0->actorData[4] != 0) {
        func_80800790_chmrsboggy(arg0);
    }
    func_80102424(arg0, 1);
}

/* extern */

s32 func_8080070C_chmrsboggy(BtIntPtr arg0, s32 arg1, s32 arg2) { s32 func_80800990_chmrsboggy(void); return 3 - func_80800990_chmrsboggy(); }

/* extern */

s32 func_80800738_chmrsboggy(void *arg0, s32 arg1, s32 arg2) {
    s32 _gcdialogcamera_entrypoint_0(s32, s32);
    void func_808007CC_chmrsboggy(Actor *, s32, s32);
    if (_gcdialogcamera_entrypoint_0(arg1, arg2) != 0) {
        if ((*(s32 *)((s8 *)(arg0) + (0x28))) != 2) {
            func_808007CC_chmrsboggy(arg0, 2, 1);
        }
        return 2;
    }
    return 1;
}

/* extern */

void func_80800790_chmrsboggy(void *arg0) {
    s32 _capod_entrypoint_3(s32, void *);
    if ((*(s32 *)((s8 *)(arg0) + (0x28))) != 0) {
        _capod_entrypoint_3(0, arg0);
        (*(s32 *)((s8 *)(arg0) + (0x28))) = 0;
    }
}

void func_808007CC_chmrsboggy(Actor *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_2(Unk80132ED0 *, u32, s32);
    void _capod_entrypoint_7(s32, s32);
    s32 _capod_entrypoint_8(s32);
    void _gcdialogcamera_entrypoint_3(f32 *, f32);
    void _gcdialogcamera_entrypoint_4(f32 *);
    void _gcdialogcamera_entrypoint_5(f32 *);
    void _gcdialogcamera_entrypoint_8(void);

    switch (arg0->actorData[4]) {
        case 0:
            _capod_entrypoint_2(arg0->unk0, 0x12, 0);
        case 1:
        case 3:
            _capod_entrypoint_8(1);
            arg0->actorData[4] = 2;
            _gcdialogcamera_entrypoint_3(D_80800A80_chmrsboggy, arg0->scale);
            _gcdialogcamera_entrypoint_4(arg0->position);
            _gcdialogcamera_entrypoint_5(arg0->rotation);
            _gcdialogcamera_entrypoint_8();
        case 2:
            _capod_entrypoint_7(arg1, arg2);
            break;
    }
}

void func_80800878_chmrsboggy(Actor *arg0, s32 arg1, s32 arg2, Unk80132ED0 *arg3) {
    void _capod_entrypoint_2(Unk80132ED0 *, u32, s32);
    void _capod_entrypoint_6(Unk80132ED0 *, s32, s32);

    if (arg3 == NULL) {
        arg3 = arg0->unk0;
    }
    switch (arg0->actorData[4]) {
        case 0:
            _capod_entrypoint_2(arg0->unk0, 0x12, arg2);
        case 2:
        case 3:
            arg0->actorData[4] = 1;
        case 1:
            _capod_entrypoint_6(arg3, arg1, arg2);
            break;
    }
}

void func_80800910_chmrsboggy(Actor *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_2(Unk80132ED0 *, u32, s32);
    void _capod_entrypoint_20(Unk80132ED0 *, s32, s32);

    switch (arg0->actorData[4]) {
        case 0:
            _capod_entrypoint_2(arg0->unk0, 0x12, arg2);
        case 1:
        case 2:
            arg0->actorData[4] = 1;
        case 3:
            _capod_entrypoint_20(arg0->unk0, arg1, arg2);
            break;
    }
}

/* extern */

s32 func_80800990_chmrsboggy(void) {
    s32 func_800DA980(s32, s32);
    return func_800DA980(0x8C, 3);
}
