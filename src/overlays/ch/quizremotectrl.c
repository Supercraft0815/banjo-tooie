#include "common.h"

void func_80800000_chquizremotectrl(Actor *arg0, s32 arg1) {
    switch (arg1) {
        case 1:
        case 3:
            break;
        case 0:
            arg0->unk54 = 0.0f;
            arg0->unk50 = 0.5f;
            break;
        case 2:
            arg0->unk54 = 1.0f;
            break;
    }
    arg0->unk79_4 = arg1;
}

void func_80800068_chquizremotectrl(Actor *arg0) {
    s32 func_800D90A4(f32 *);
    int func_800D91EC(f32 *, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);

    switch (arg0->unk79_4) {
        case 1:
            if (func_800D90A4(&arg0->unk50) != 0) {
                func_80800000_chquizremotectrl(arg0, 2);
            }
            arg0->unk54 = func_800F10B4(arg0->unk50, 0.5f, 0.0f, 0.0f, 1.0f);
            break;
        case 3:
            if (func_800D91EC(&arg0->unk50, 0.5f) != 0) {
                func_80800000_chquizremotectrl(arg0, 0);
            }
            arg0->unk54 = func_800F10B4(arg0->unk50, 0.0f, 0.5f, 1.0f, 0.0f);
            break;
    }
}

/* extern */

void func_8080012C_chquizremotectrl(s32 *arg0) {
    s32 _capod_entrypoint_13(s32, s32, s32, s32);
    s32 _capod_entrypoint_21(s32, s32, s32, s32);
    s32 _suquiz_entrypoint_26();
    s32 func_800A5854(s32);
    void func_80800000_chquizremotectrl(Actor *, s32);
    s32 sp1C;
    s32 temp_v0;
    s32 temp_v0_2;

    temp_v0 = _suquiz_entrypoint_26();
    sp1C = temp_v0;
    temp_v0_2 = func_800A5854(temp_v0);
    if (temp_v0_2 != 2) {
        if ((temp_v0_2 == 5) || (temp_v0_2 == 6) || (temp_v0_2 == 8)) {
            _capod_entrypoint_13(*arg0, 0, sp1C, 0x834);
        }
    } else {
        _capod_entrypoint_21(*arg0, 0, sp1C, 0x814);
    }
    func_80800000_chquizremotectrl((Actor *)arg0, 0);
}

void func_808001BC_chquizremotectrl(Actor *arg0, s32 arg1) {
    s32 _glglobalsettings_entrypoint_3();
    f32 _suquiz_entrypoint_8(s32);
    void _suquiz_entrypoint_25(void);
    void func_800FC660(u32);
    void func_800FC74C(u32);
    void func_80102424(Actor *, s32);
    s32 state;

    func_80102424(arg0, arg1);
    state = arg0->unk70_10;
    switch (state) {
        case 1:
            if (_glglobalsettings_entrypoint_3()) {
                ((f32 *)arg0->actorData)[3] = -300.0f;
            } else {
                ((f32 *)arg0->actorData)[3] = -500.0f;
            }
            func_800FC660(0x1E);
            ((f32 *)arg0->actorData)[7] = 1.0f;
            func_8080012C_chquizremotectrl((s32 *)arg0);
            break;
        case 2:
            func_800FC74C(0x1E);
            arg0->unk58 = _suquiz_entrypoint_8(0);
            func_80800000_chquizremotectrl(arg0, 1);
            break;
        case 3:
            func_800FC660(0x1D);
            ((f32 *)arg0->actorData)[7] = 1.0f;
            func_80800000_chquizremotectrl(arg0, 3);
            break;
        case 5:
            func_800FC74C(0x1D);
            _suquiz_entrypoint_25();
    }
}

/* extern */

void func_808002C8_chquizremotectrl(Actor *arg0) {
    s32 _suquiz_entrypoint_1();
    s32 _suquiz_entrypoint_5();
    s32 func_800D90A4(f32 *);
    void func_808001BC_chquizremotectrl(Actor *, s32);

    _suquiz_entrypoint_1();
    switch (arg0->unk70_10) {
    case 5:
        break;
    case 1:
        if (func_800D90A4((f32 *) &arg0->actorData[7]) != 0) {
            func_808001BC_chquizremotectrl(arg0, 2);
        }
        break;
    case 2:
        if ((func_800D90A4(&arg0->unk58) != 0) || (_suquiz_entrypoint_5() != 0)) {
            func_808001BC_chquizremotectrl(arg0, 3);
        }
        break;
    case 3:
        if (func_800D90A4((f32 *) &arg0->actorData[7]) != 0) {
            func_808001BC_chquizremotectrl(arg0, 4);
        }
        break;
    case 4:
        func_808001BC_chquizremotectrl(arg0, 5);
        break;
    }
    func_80800068_chquizremotectrl(arg0);
}

void func_808003A0_chquizremotectrl(s32 arg0) 
{
}
/* extern */

void func_808003A8_chquizremotectrl(Actor *arg0) {
    void func_800CEA38(s32, s32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_808001BC_chquizremotectrl(Actor *, s32);
    func_800CEA38(0, 1);
    func_800EFA4C(arg0->position, 0.0f, 0.0f, 0.0f);
    arg0->rotation[2] = 0.0f;
    arg0->rotation[0] = 0.0f;
    arg0->rotation[1] = 0.0f;
    func_808001BC_chquizremotectrl(arg0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/quizremotectrl/func_80800410_chquizremotectrl.s")

s32 func_808005E4_chquizremotectrl(s32 arg0, s32 arg1, s32 arg2) {
    if (arg1 == 0xB) {
        return 3;
    }
    return 0;
}

OSThread *chquizremotectrl_entrypoint_0(void)
{
    extern u8 D_80800668_chquizremotectrl[];

    return (OSThread *) D_80800668_chquizremotectrl;
}
