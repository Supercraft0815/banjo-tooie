#include "common.h"

void func_80105834(Actor *);
void func_80101870(Actor *, void *);
void *func_80107C2C(s32 *, s32, void *, s32, void *);
void func_80800028_chamazonstadiumguard(Actor *arg0);
void func_808002F4_chamazonstadiumguard(Actor* arg0);
void func_8080000C_chamazonstadiumguard(void *arg0);
s32 func_80800328_chamazonstadiumguard(Actor *arg0, s32 arg1, s32 arg2);

f32 D_808006B0_chamazonstadiumguard[] = {
    -6221.0f, -5709.0f
};

u32 D_808006B8_chamazonstadiumguard[] = {
    0x00000000, 0x00000000, 0x40E00000, 0x01990000,
    0x3F8CCCCD, 0x019A004A, 0x40800000, 0x019B0049,
    0x40800000, 0x019B0000, 0x40400000, 0x019C004A,
    0x40E00000, 0x01990249, 0x40E00000, 0x01990000,
    0x40E00000, 0x01990000
};

u32 D_80800700_chamazonstadiumguard[] = {
    0x015F0116, 0x06610001, (u32)D_808006B8_chamazonstadiumguard, (u32)func_80800028_chamazonstadiumguard,
    (u32)func_80105834, (u32)func_80101870, 0x1F400000, 0x00000000,
    0x00000000, 0x00000160, (u32)func_808002F4_chamazonstadiumguard, 0x00000000,
    0x00000000, (u32)func_8080000C_chamazonstadiumguard, (u32)func_80107C2C, 0x86006502,
    (u32)func_80800328_chamazonstadiumguard, 0x00000000
};

f32 D_80800748_chamazonstadiumguard[] = {
    -200.0f, -100.0f, -550.0f
};

f32 D_80800754_chamazonstadiumguard[] = {
    200.0f, 450.0f, -50.0f
};

s32 D_80800760_chamazonstadiumguard[] = {
    0x43660000, 0x43200000, 0x42C80000, 0x42C80000
};

s32 D_80800770_chamazonstadiumguard[] = {
    0x0059012C, 0x0F0A0000, 0xFFFFFFFF, 0x00000000,
    0x00300000, 0x000E0000, 0x04000000
};

s32 D_8080078C_chamazonstadiumguard[] = {
    0x0058012C, 0x0F090F0B, 0x00000201, 0x120E0000,
    0x00300000, 0x000E0000, 0x04000000
};

s32 D_808007A8_chamazonstadiumguard[] = {
    0x0000012C, 0x00000F0C, 0x00000080, 0x00000000,
    0x00300000, 0x000E0000, 0x07000000
};

u32 D_808007C4_chamazonstadiumguard[] = {
    0x00130564, 0x000D00F3, 0x010C0000
};

u32 D_808007D0_chamazonstadiumguard[] = {
    0x3F2E147B, 0x3F4CCCCD, 0x3F6B851F, 0xBF800000
};

void *func_80100094(Actor *, u32);

OSThread *chamazonstadiumguard_entrypoint_0(void)
{
    return (OSThread *) D_80800700_chamazonstadiumguard;
}

void func_8080000C_chamazonstadiumguard(void *arg0) {
    (*(f32 *)((s8 *)(arg0) + (0x28))) = (f32) (*(f32 *)((s8 *)(arg0) + (4)));
    (*(f32 *)((s8 *)(arg0) + (0x2C))) = (f32) (*(f32 *)((s8 *)(arg0) + (8)));
    (*(f32 *)((s8 *)(arg0) + (0x30))) = (f32) (*(f32 *)((s8 *)(arg0) + (0xC)));
}

void func_80800028_chamazonstadiumguard(Actor *arg0) {
    s32 _chbadshad_entrypoint_2(Actor *arg0, s32 arg1, f32 arg2, f32 *arg3);
    s32 _subaddieskeleton_entrypoint_2(Unk80132ED0 *arg0, s32 arg1, f32 *arg2);
    s32 _sudeflect_entrypoint_1(f32 *arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4);
    s32 _sudeflect_entrypoint_3(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
    void _sudeflect_entrypoint_4(s32 arg0, f32 *arg1);
    void _suexpression_entrypoint_10(void *arg0, Unk80132ED0 *arg1, f32 *arg2);
    int func_800DB9B0(void);
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    s32 func_80101DDC(Actor *arg0);
    void func_80102424(Actor *arg0, s32 arg1);
    s32 func_8010CAC0(f32 *arg0, s32 arg1);
    void func_80102078(void *arg0, s32 arg1);
    void func_801020DC(void *arg0, s32 arg1);
    void func_80103014(u8 *arg0);
    void func_80800530_chamazonstadiumguard(Actor *arg0);
    void func_808005CC_chamazonstadiumguard(s32 arg0);
    void func_80800620_chamazonstadiumguard(s32 arg0);
    void func_80800648_chamazonstadiumguard(Actor *arg0);
    s32 sp54 = 0;
    f32 sp48[3];
    f32 sp3C[3];
    f32 sp38;
    void *checkedExpression;
    void *expression;

    checkedExpression = func_80100094(arg0, 1);
    if (checkedExpression != 0) {
        expression = func_80100094(arg0, 1);
        _suexpression_entrypoint_10(expression, arg0->unk0, 0);
    }
    switch (arg0->unk70_10) {
    case 1:
        sp54 = 1;
        func_80800530_chamazonstadiumguard(arg0);
        func_80800648_chamazonstadiumguard(arg0);
        break;
    case 2:
        sp54 = 1;
        if (func_80101DDC(arg0)) {
            func_80102424(arg0, 3);
        }
        break;
    case 3:
        sp54 = 1;
        if (!func_8010CAC0(arg0->position, 500)) {
            func_80102078(arg0, 0x3F000000);
            func_80102424(arg0, 1);
        } else {
            func_808005CC_chamazonstadiumguard(arg0);
        }
        break;
    case 4:
        sp54 = 1;
        break;
    case 5:
        if (func_80101DDC(arg0)) {
            if (_subaddieskeleton_entrypoint_2(arg0->unk0, 4, sp48)) {
                arg0->position[0] = sp48[0];
                arg0->position[2] = sp48[2];
            } else {
                arg0->position[0] = D_808006B0_chamazonstadiumguard[0];
                arg0->position[2] = D_808006B0_chamazonstadiumguard[1];
            }
            func_80103014(arg0);
            func_801020DC(arg0, 0);
            func_80102424(arg0, 6);
        }
        break;
    case 6:
        func_80800620_chamazonstadiumguard(arg0);
        func_80800648_chamazonstadiumguard(arg0);
        if (!func_800DB9B0() && !func_8010CAC0(arg0->position, 3000) && !arg0->unk7C_12) {
            func_800EE7F8(arg0->position, (f32 *)&arg0->actorData[4]);
            func_80103014(arg0);
            func_80102424(arg0, 1);
        }
        break;
    case 7:
        func_80800648_chamazonstadiumguard(arg0);
        break;
    case 8:
        func_80800648_chamazonstadiumguard(arg0);
        break;
    }
    if (arg0->unk7C_12) {
        sp38 = (s32)arg0->unk70_10 >= 5 ? 0.8f : 1.0f;
        if (_chbadshad_entrypoint_2(arg0, 3, 2.5f, sp3C) &&
            (_sudeflect_entrypoint_1(sp3C, 350.0, 0.0f, sp38 * 160.0f, 10) & 2)) {
            _sudeflect_entrypoint_4(9, arg0->position);
        }
    }
    if (sp54) {
        _sudeflect_entrypoint_3((f32 *)&arg0->actorData[4], arg0->rotation,
            D_80800748_chamazonstadiumguard, D_80800754_chamazonstadiumguard, 2);
    }
}

void func_808002F4_chamazonstadiumguard(Actor* arg0) 
{
    if (func_80100094(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
s32 func_80800328_chamazonstadiumguard(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _gcdialogcamera_entrypoint_3(s32 *, f32);
    s32 _glcutDll_entrypoint_20(void);
    void _suexpression_entrypoint_12(void *, f32, f32);
    void *_suexpression_entrypoint_7(Actor *, u32, u32);
    s32 func_800EA090(void);
    void func_801020DC(void *, s32);
    void func_80102424(Actor *, s32);
    void func_80103014(u8 *);
    void func_80800488_chamazonstadiumguard(Actor *, s32, s32);

    switch (arg1) {
        case 0x2E:
            func_80800488_chamazonstadiumguard(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
            break;
        case 0x52:
            _gcdialogcamera_entrypoint_3(D_80800760_chamazonstadiumguard, arg0->scale);
            break;
        case 0x95:
            if (_glcutDll_entrypoint_20()) {
                func_80102424(arg0, 8);
            } else if (func_800EA090() == 4) {
                arg0->position[0] = D_808006B0_chamazonstadiumguard[0];
                arg0->position[2] = D_808006B0_chamazonstadiumguard[1];
                func_80103014(arg0);
                func_801020DC(arg0, 0);
                func_80102424(arg0, 6);
            }
            break;
        case 0x29:
            _suexpression_entrypoint_7(arg0, 1, 0x30);
            _suexpression_entrypoint_12(func_80100094(arg0, 1), 65.0f, 15.0f);
            break;
        case 0x2A:
            if (func_80100094(arg0, 1) != 0) {
                _suexpression_entrypoint_8(arg0, 1);
            }
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800488_chamazonstadiumguard(Actor *arg0, s32 arg1, s32 arg2) {
    void func_800C01A8(s16, s32);
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    void func_80102424(Actor *, s32);

    switch (arg1) {
        case 0xF0A:
            func_800C01A8(0x64, 0);
            _capod_entrypoint_13(arg0->unk0, NULL, 0x24, 0x2010);
            func_80102424(arg0, 5);
            return;
        case 0xF0C:
            func_80102424(arg0, 6);
            return;
        case 0xF09:
        case 0xF0B:
            func_80102424(arg0, 3);
            return;
    }
}

/* extern */

void func_80800530_chamazonstadiumguard(Actor *arg0) {
    s32 func_800DA298(GameFlag);
    void func_80102424(Actor *, s32);
    s32 func_8010CAC0(f32 *, s32);
    s32 func_8010D278();
    s32 func_8010D284();

    if ((func_8010CAC0(arg0->position, 0x1F4) != 0) && (func_8010D284() != 5) && (func_8010D284() != 0xA)) {
        if (func_8010D278() == 8) {
            func_80102424(arg0, func_800DA298(0x59) ? 5 : 2);
            return;
        }
        func_80102424(arg0, 2);
    }
}

void func_808005CC_chamazonstadiumguard(s32 arg0) {
    s32 _subaddiedialog_entrypoint_7(s32, s32, s32 *);
    s32 func_8010D278();
    if (func_8010D278() == 8) {
        _subaddiedialog_entrypoint_7(arg0, arg0 + 4, D_80800770_chamazonstadiumguard);
        return;
    }
    _subaddiedialog_entrypoint_7(arg0, arg0 + 4, D_8080078C_chamazonstadiumguard);
}

void func_80800620_chamazonstadiumguard(s32 arg0) {
    s32 _subaddiedialog_entrypoint_7(s32, s32, s32 *);
    _subaddiedialog_entrypoint_7(arg0, arg0 + 4, D_808007A8_chamazonstadiumguard);
}

void func_80800648_chamazonstadiumguard(Actor *arg0) {
    _subaddieaudioquick_entrypoint_4(arg0, arg0->position, D_808007C4_chamazonstadiumguard, D_808007D0_chamazonstadiumguard);
}
