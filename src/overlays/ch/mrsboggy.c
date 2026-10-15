#include "ch/mrsboggy.h"

OSThread *chmrsboggy_entrypoint_0(void)
{
    extern u8 D_80800AD8_chmrsboggy[];

    return (OSThread *) D_80800AD8_chmrsboggy;
}

/* extern */

void func_8080000C_chmrsboggy(s32 arg0) {
    s32 func_800DA298(s32);
    s32 func_800DA524(s32);
    s32 func_800DA980(s32, s32);
    s32 func_800FFAB0(s32);
    s32 func_80102424(s32, s32);
    s32 func_80105A9C(s32, s32);
    s32 func_80105BAC(s32);
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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mrsboggy/func_80800088_chmrsboggy.s")

void func_80800290_chmrsboggy(Actor* arg0)
{
    func_80800548_chmrsboggy(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mrsboggy/func_808002B0_chmrsboggy.s")

/* extern */

void func_808004F4_chmrsboggy(s32 arg0) {
    s32 _suexpression_entrypoint_12(s32, s32, s32);
    s32 _suexpression_entrypoint_17(s32, s32);
    s32 _suexpression_entrypoint_20();
    s32 _suexpression_entrypoint_7(s32, s32, s32);
    s32 sp1C;
    s32 temp_v0;

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
    s32 _subaddiedialog_entrypoint_8(s32, void *, s32 *, s32 *, s32);
    s32 _subaddiedialog_entrypoint_9(s32, s32, s32 *, s32);
    s32 func_808007CC_chmrsboggy(void *, s32, s32);
    extern s32 D_80800A20_chmrsboggy;
    extern s32 D_80800B30_chmrsboggy;
    s32 temp_v0;

    temp_v0 = _subaddiedialog_entrypoint_8((s32)arg0, (s8 *)arg0 + 4, &D_80800B30_chmrsboggy, &D_80800A20_chmrsboggy, 7);
    if ((temp_v0 != 0) && (_subaddiedialog_entrypoint_9((s32)arg0, temp_v0, &D_80800A20_chmrsboggy, 7) != 3)) {
        func_808007CC_chmrsboggy(arg0, 3, 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mrsboggy/func_808005D8_chmrsboggy.s")

/* extern */

s32 func_8080070C_chmrsboggy(s32 arg0, s32 arg1, s32 arg2) { s32 func_80800990_chmrsboggy(void); return 3 - func_80800990_chmrsboggy(); }

/* extern */

s32 func_80800738_chmrsboggy(void *arg0, s32 arg1, s32 arg2) {
    s32 _gcdialogcamera_entrypoint_0(s32, s32);
    s32 func_808007CC_chmrsboggy(void *, s32, s32);
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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mrsboggy/func_808007CC_chmrsboggy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mrsboggy/func_80800878_chmrsboggy.s")

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
