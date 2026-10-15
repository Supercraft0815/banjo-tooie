#include "common.h"

OSThread *chbottlesfamily_entrypoint_0(void)
{
    extern u8 D_80800DE0_chbottlesfamily[];

    return (OSThread *) D_80800DE0_chbottlesfamily;
}

OSThread *chbottlesfamily_entrypoint_1(void)
{
    extern u8 D_80800E28_chbottlesfamily[];

    return (OSThread *) D_80800E28_chbottlesfamily;
}

OSThread *chbottlesfamily_entrypoint_2(void)
{
    extern u8 D_80800E70_chbottlesfamily[];

    return (OSThread *) D_80800E70_chbottlesfamily;
}

void func_80800024_chbottlesfamily(Actor *arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 func_80102424(s32, s32);
    void func_80102FDC(Actor*, f32);
    func_80102FDC(arg0, arg0->scale / 3.0f);
    arg0->unk64_20 = 1;
    if (_glcutDll_entrypoint_20(arg0) != 0) {
        func_80102424((s32) arg0, 5);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bottles/family/func_80800080_chbottlesfamily.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bottles/family/func_80800124_chbottlesfamily.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bottles/family/func_808001B0_chbottlesfamily.s")

/* extern */

s32 func_8080046C_chbottlesfamily(Actor *arg0, s32 arg1) {
    void _subaddierouteDll_entrypoint_1(Actor*);
    s32 func_80800720_chbottlesfamily(Actor*);
    s32 ret;
    if (arg1 == 0x95) {
        func_80800720_chbottlesfamily(arg0);
        _subaddierouteDll_entrypoint_1(arg0);
        ret = 1;
    } else {
        return func_80800720_chbottlesfamily(arg0);
    }
    return ret;
}

s32 func_808004B4_chbottlesfamily(s32 arg0) {
    s32 func_800DA298(s32);
    s32 func_808009F0_chbottlesfamily(s32, s32 *);
    extern s32 D_80800F04_chbottlesfamily;
    extern s16 D_80800F08_chbottlesfamily;
    if (func_800DA298(0x3B) != 0) {
        return 0;
    }
    if (func_800DA298(0x1A5) != 0) {
        D_80800F08_chbottlesfamily = 0x1539;
    } else {
        D_80800F08_chbottlesfamily = 0x1501;
    }
    return func_808009F0_chbottlesfamily(arg0, &D_80800F04_chbottlesfamily);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bottles/family/func_80800520_chbottlesfamily.s")

void func_808005D0_chbottlesfamily(Actor *arg0) {
    extern u32 D_80800F20_chbottlesfamily;
    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80800F20_chbottlesfamily, 0x3DA3D70A);
}

/* extern */

void func_80800600_chbottlesfamily(s32 arg0) {
    s32 func_80102424(s32, s32);
    s32 _glcutDll_entrypoint_20();
    if (_glcutDll_entrypoint_20() != 0) {
        func_80102424(arg0, 5);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bottles/family/func_80800630_chbottlesfamily.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bottles/family/func_80800720_chbottlesfamily.s")

void func_8080086C_chbottlesfamily(Actor* arg0) 
{
    _suexpression_entrypoint_8(arg0, 1);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bottles/family/func_8080088C_chbottlesfamily.s")

/* extern */

void func_8080099C_chbottlesfamily(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_800C07F4();
    s32 func_80800CA4_chbottlesfamily(s32, s32, s32);
    if (((arg1 == 0x1501) || (arg1 == 0x1539)) && (arg2 == 1) && (func_800C07F4() == 0)) {
        func_80800CA4_chbottlesfamily(arg0, 4, 0x2020);
    }
}

s32 func_808009F0_chbottlesfamily(s32 arg0, s32 *arg1) {
    s32 _subaddiedialog_entrypoint_7(s32, s32, s32 *);
    s32 func_80800C08_chbottlesfamily(void *, s32, s32);
    s32 temp_v0;
    s32 var_v1;
    s32 sp1C;

    temp_v0 = _subaddiedialog_entrypoint_7(arg0, arg0 + 4, arg1);
    var_v1 = temp_v0;
    if ((temp_v0 != 0) && (temp_v0 != 0x1208)) {
        sp1C = temp_v0;
        func_80800C08_chbottlesfamily((u8 *) arg0, 3, 0);
        var_v1 = sp1C;
    }
    return var_v1 != 0;
}

 s32 func_80800A44_chbottlesfamily(Actor *arg0) { u32 temp_t7; temp_t7 = arg0->unk6C_9; switch (temp_t7) { case 0x43C: return 0xB0; case 0x43D: return 0xB1; default: return 0xAF; } }

void func_80800A84_chbottlesfamily(Actor *arg0) {
    s32 _gcdialogcamera_entrypoint_3(s32 *, f32);
    void _gcdialogcamera_entrypoint_4(f32 *);
    void _gcdialogcamera_entrypoint_5(f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    f32 func_8010CD28(Actor *);
    extern s32 D_80800F88_chbottlesfamily;
    extern s32 D_80800F98_chbottlesfamily;
    extern s32 D_80800FA8_chbottlesfamily;
    f32 sp2C[3];
    u32 temp_t7;

    temp_t7 = arg0->unk6C_9;
    if (temp_t7 != 0x43B) {
        if (temp_t7 != 0x43C) {
            if (temp_t7 == 0x43D) {
                _gcdialogcamera_entrypoint_3(&D_80800F88_chbottlesfamily, arg0->scale);
                _gcdialogcamera_entrypoint_5(arg0->rotation);
            }
        } else {
            func_800EFA4C(sp2C, 0.0f, func_8010CD28(arg0), 0.0f);
            _gcdialogcamera_entrypoint_3(&D_80800F98_chbottlesfamily, arg0->scale);
            _gcdialogcamera_entrypoint_5(sp2C);
        }
    } else {
        _gcdialogcamera_entrypoint_3(&D_80800FA8_chbottlesfamily, arg0->scale * 3.0f);
        _gcdialogcamera_entrypoint_5(arg0->rotation);
    }
    _gcdialogcamera_entrypoint_4(arg0->position);
}

/* extern */

s32 func_80800B64_chbottlesfamily(void *arg0, s32 arg1, s32 arg2) {
    s32 _gcdialogcamera_entrypoint_0(s32, s32);
    s32 func_80800C08_chbottlesfamily(void *, s32, s32);
    if (_gcdialogcamera_entrypoint_0(arg1, arg2) != 0) {
        if (((*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF) != 2) {
            func_80800C08_chbottlesfamily(arg0, 2, 1);
        }
        return 2;
    }
    return 1;
}

/* extern */

void func_80800BC0_chbottlesfamily(void *arg0) {
    s32 _capod_entrypoint_3(s32, void *);
    if ((*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF) {
        _capod_entrypoint_3(0, arg0);
        (*(u16 *)((s8 *)(arg0) + (0x6E))) = (u16) ((*(u16 *)((s8 *)(arg0) + (0x6E))) & 0xFE00);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bottles/family/func_80800C08_chbottlesfamily.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bottles/family/func_80800CA4_chbottlesfamily.s")
