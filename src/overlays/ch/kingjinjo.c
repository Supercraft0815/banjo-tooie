#include "common.h"

OSThread *chkingjinjo_entrypoint_0(void)
{
    extern u8 D_808011A8_chkingjinjo[];

    return (OSThread *) D_808011A8_chkingjinjo;
}

OSThread *chkingjinjo_entrypoint_1(void)
{
    extern u8 D_808011F0_chkingjinjo[];

    return (OSThread *) D_808011F0_chkingjinjo;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/kingjinjo/func_80800018_chkingjinjo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/kingjinjo/func_80800194_chkingjinjo.s")

s32 func_80800634_chkingjinjo(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _gcgoto_entrypoint_1(s32, s32);
    s32 _glcutDll_entrypoint_20(void);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    Actor *_subaddiefind_entrypoint_2(s32, s32);
    void _subaddiemarker_entrypoint_1(Actor *, s32, s32, f32 *, s32);
    void _subaddierouteDll_entrypoint_1(Actor *);
    s32 _suexpression_entrypoint_12(void *, s32, s32);
    s32 _suexpression_entrypoint_17(void *, s32);
    s32 _suexpression_entrypoint_7(Actor *, s32, s16);
    s32 func_800DA298(s32);
    s32 func_800DF744(s32, u32);
    void func_800F497C(s32);
    void func_800F49A8(s32, s32);
    void func_800F49D4(s32, void *, s32);
    void func_800F4A58(s32, s32, f32);
    s32 func_800F54E4(void);
    s32 func_801015D0(Actor *);
    void func_80102424(Actor *, s32);
    void func_801032B0(void *, u16, u16);
    void func_808009FC_chkingjinjo(void *, s16, s16);
    void func_80800B28_chkingjinjo(Actor *);
    s32 func_80800BBC_chkingjinjo(void *, s32, s32);
    void func_80800C60_chkingjinjo(Actor *, s32, s32);
    void func_80800CFC_chkingjinjo(Actor *, s32, s32);
    void func_8010D5DC(void);
    s32 expression_id;
    Actor *found;
    s32 expression;
    s32 pad0[2];
    f32 sp50[3];
    s32 sp4C;
    s32 pad1[3];
    f32 sp34[3];
    s32 sp30;

    switch (arg1) {
    case 0x2E:
        func_808009FC_chkingjinjo(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
        break;
    case 0x3F:
        if (((u32)*(u16 *)((u8 *)arg0 + 0x72) >> 10) != 7) {
            func_80102424(arg0, 7);
        }
        break;
    case 0x52:
        func_80800B28_chkingjinjo(arg0);
        break;
    case 0x95:
        found = _subaddiefind_entrypoint_2(0x147, 0);
        if (found != NULL) {
            *(s32 *)((u8 *)arg0 + 0x3C) = *(s32 *)found;
        } else {
            *(s32 *)((u8 *)arg0 + 0x3C) = 0;
        }
        if (func_800DA298(0x360) != 0) {
            func_801032B0(arg0, 0x897, *(u16 *)(*(u8 **)arg0 + 0x16));
            _subaddierouteDll_entrypoint_1(arg0);
        } else {
            if (func_800DA298(0x1A5) == 0 && func_800DA298(0x3B) == 0 && _glcutDll_entrypoint_20() == 0) {
                sp4C = func_800F54E4();
                _subaddiemarker_entrypoint_1(arg0, 0x154, 0x33, sp50, 1);
                func_800F497C(sp4C);
                func_800F49A8(sp4C, 1);
                func_800F49D4(sp4C, &func_8010D5DC, *(s32 *)arg0);
                func_800F4A58(sp4C, (s32)sp50, 300.0f);
                func_80800CFC_chkingjinjo(arg0, 5, 0x20);
                func_80102424(arg0, 1);
            }
            func_801032B0(arg0, 0x896, *(u16 *)(*(u8 **)arg0 + 0x16));
        }
        if (((u32)*(u16 *)((u8 *)arg0 + 0x72) >> 10) == 2) {
            sp30 = func_800F54E4();
            _subaddiemarker_entrypoint_1(arg0, 0x154, 0x34, sp34, 1);
            func_800F497C(sp30);
            func_800F49A8(sp30, 1);
            func_800F49D4(sp30, &func_8010D5DC, *(s32 *)arg0);
            func_800F4A58(sp30, (s32)sp34, 300.0f);
            func_80800CFC_chkingjinjo(arg0, 0x17, 0x2020);
        }
        expression = func_800DA298(0x360) != 0 ? 0xA5 : 0xAE;
        expression_id = _suexpression_entrypoint_7(arg0, 1, (s16)expression);
        _suexpression_entrypoint_12((void *)expression_id, 0x42700000, 0x41A00000);
        _suexpression_entrypoint_17((void *)expression_id, 0x5DC);
        break;
    case 0x57:
        return func_80800BBC_chkingjinjo(arg0, arg2 & 0xFFFF, (u32)(arg2 & 0xFFFF0000) >> 16);
    case 0xB:
        if (arg2 == 1) {
            func_80800C60_chkingjinjo(arg0, 3, 1);
            _subaddiedialog_entrypoint_11(*(Unk80132ED0 **)arg0, 0x1535, 6, (f32 *)((u8 *)arg0 + 4), 0xAE);
            return 4;
        }
        return 3;
    case 0x32:
        switch ((u32)*(u16 *)((u8 *)arg0 + 0x72) >> 10) {
        case 1:
            _subaddiedialog_entrypoint_11(*(Unk80132ED0 **)arg0, 0x14FD, 0xE, (f32 *)((u8 *)arg0 + 4), 0xAE);
            break;
        case 2:
            _gcgoto_entrypoint_1(0x142, 1);
            break;
        }
        break;
    case 0x1F:
        func_801015D0(arg0);
        func_800DF744(3, 0);
        break;
    default:
        return 0;
    }
    return 1;
}

/* extern */

void func_808009D0_chkingjinjo(s32 arg0) {
    s32 _suexpression_entrypoint_8(s32, s32);
    s32 func_80800C18_chkingjinjo();
    func_80800C18_chkingjinjo();
    _suexpression_entrypoint_8(arg0, 0x1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/kingjinjo/func_808009FC_chkingjinjo.s")

void func_80800AE4_chkingjinjo(s32 arg0, s32 *arg1) {
    s32 _subaddiedialog_entrypoint_7(s32, s32, s32 *);
    void func_80800C60_chkingjinjo(Actor *, s32, s32);
    s32 temp_v0;

    temp_v0 = _subaddiedialog_entrypoint_7(arg0, arg0 + 4, arg1);
    if ((temp_v0 != 0) && (temp_v0 != 0x1208)) {
        func_80800C60_chkingjinjo((Actor *) arg0, 3, 0);
    }
}

void func_80800B28_chkingjinjo(Actor *arg0) {
    void _gcdialogcamera_entrypoint_3(u32 *, f32);
    void _gcdialogcamera_entrypoint_4(f32 *);
    void _gcdialogcamera_entrypoint_5(f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    s32 func_801022E4(Actor *);
    extern u32 D_808012A0_chkingjinjo;
    extern u32 D_808012B0_chkingjinjo;
    f32 sp24[3];

    if (func_801022E4(arg0) == 0x3A9) {
        func_800EE7F8(sp24, arg0->position);
        func_800EF1B8(sp24, arg0->rotation[1], -50.0f);
        _gcdialogcamera_entrypoint_3(&D_808012A0_chkingjinjo, arg0->scale);
        _gcdialogcamera_entrypoint_4(sp24);
        _gcdialogcamera_entrypoint_5(arg0->rotation);
        return;
    }
    _gcdialogcamera_entrypoint_3(&D_808012B0_chkingjinjo, arg0->scale);
    _gcdialogcamera_entrypoint_4(arg0->position);
    _gcdialogcamera_entrypoint_5(arg0->rotation);
}

/* extern */

s32 func_80800BBC_chkingjinjo(void *arg0, s32 arg1, s32 arg2) {
    s32 _gcdialogcamera_entrypoint_0(s32, s32);
    void func_80800C60_chkingjinjo(Actor *, s32, s32);
    if (_gcdialogcamera_entrypoint_0(arg1, arg2) != 0) {
        if (((*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF) != 2) {
            func_80800C60_chkingjinjo(arg0, 2, 1);
        }
        return 2;
    }
    return 1;
}

s32 func_80800C18_chkingjinjo(void *arg0) {
    s32 _capod_entrypoint_3(s32, void *);
    if ((*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF) {
        _capod_entrypoint_3(0, arg0);
        (*(u16 *)((s8 *)(arg0) + (0x6E))) = (u16) ((*(u16 *)((s8 *)(arg0) + (0x6E))) & 0xFE00);
    }
}

void func_80800C60_chkingjinjo(Actor *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_2(Unk80132ED0 *, u32, s32);
    void _capod_entrypoint_7(s32, s32);
    s32 _capod_entrypoint_8(s32);
    void _gcdialogcamera_entrypoint_8(void);

    switch (arg0->unk6C_0) {
        case 0:
            _capod_entrypoint_2(arg0->unk0, 0x17, 0);
        case 1:
            _capod_entrypoint_8(1);
            arg0->unk6C_0 = 2;
            func_80800B28_chkingjinjo(arg0);
            _gcdialogcamera_entrypoint_8();
        case 2:
            _capod_entrypoint_7(arg1, arg2);
            break;
    }
}

void func_80800CFC_chkingjinjo(Actor *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_2(Unk80132ED0 *, u32, s32);
    void _capod_entrypoint_6(Unk80132ED0 *, s32, s32);

    switch (arg0->unk6C_0) {
        case 0:
            _capod_entrypoint_2(arg0->unk0, 0x17, arg2);
        case 2:
            arg0->unk6C_0 = 1;
        case 1:
            _capod_entrypoint_6(arg0->unk0, arg1, arg2);
            break;
    }
}

/* extern */

void func_80800D80_chkingjinjo(Actor *arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 func_800DA298(s32);
    void func_80102424(Actor *, s32);
    if (_glcutDll_entrypoint_20() != 0) {
        arg0->unk64_19 = 1;
        arg0->unk6C_0 = 1;
        return;
    }
    if ((func_800DA298(0x3B) != 0) && (func_800DA298(0x43) == 0)) {
        arg0->unk6C_0 = 1;
        return;
    }
    if (func_800DA298(0x360) != 0) {
        func_80102424(arg0, 2);
        arg0->unk64_19 = 0;
        arg0->unk6C_0 = 2;
        return;
    }
    arg0->unk64_19 = 1;
    arg0->unk6C_0 = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/kingjinjo/func_80800E58_chkingjinjo.s")

s32 func_80800F60_chkingjinjo(s32 arg0, s32 arg1, s32 arg2) 
{
    return 0;
}
/* extern */

void func_80800F74_chkingjinjo(void *arg0, s32 arg1) {
    s32 func_800DF744(s32, u32);
    s32 func_80101870(void *, s32);
    func_800DF744(3, (*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF);
    func_800DF744(4, (u32) ((*(s32 *)((s8 *)(arg0) + (0x64))) << 0xC) >> 0x1F);
    func_80101870(arg0, arg1);
}
