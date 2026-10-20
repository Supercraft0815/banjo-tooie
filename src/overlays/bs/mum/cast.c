#include "overlays/bs/mum/cast.h"

#ifndef NONMATCHINGS
s32 func_80800000_bsmumcast(PlayerState *self, s32);
s32 func_80800000_bsmumcast(PlayerState *self, s32 arg1) {
    void func_8009EAA0(s32);
    void func_800FC6B0(u32);
    void func_800FCA90(u32);
    void func_800FCAE0(u32, u32, u32);

    self->unk15C.word = arg1;
    switch (arg1) {
    case 0:
        break;
    case 1:
        baanim_playForDuration_onceSmooth(self, 0xFC, 3.0f);
        func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 3, BA_PHYSICS_3_LOCKED_ROTATION);
        func_8009BA9C(self, NULL);
        baphysics_set_target_horizontal_velocity(self, 0.0f);
        break;
    case 2:
        baanim_playForDuration_loopSmooth(self, 0x4A1, 1.71f);
        func_8009EAA0(1);
        func_800FC6B0(0x60);
        func_800DA544(FLAG3_9DE_UNK);
        break;
    case 3:
        func_800DA3B8(FLAG3_9DF_UNK, 0);
        baanim_playForDuration_onceSmooth(self, 0xFB, 3.0f);
        func_8009DB04(self, 0x3FE, 1.0f, 0x7FFF);
        func_800FCAE0(0x60, 0, 0x708);
        func_800FCA90(0x60);
        func_8009EAA0(0);
        break;
    case 4:
        baanim_playForDuration_onceStartingAt(self, 0xFC, 3.0f, 0.9999f);
        func_8009FFD8(self, BAANIM_UPDATE_1_NORMAL, YAW_TYPE_1_DEFAULT, 2, BA_PHYSICS_3_LOCKED_ROTATION);
        func_8009BA9C(self, NULL);
        baphysics_set_target_horizontal_velocity(self, 0.0f);
        func_800A0DAC(self, 0);
        func_800A0DA0(self, 1);
        break;
    }
}
#else
// Decomp failure
#endif

void bsmumcast_entrypoint_0(PlayerState *self) {
    func_8008E95C(self);
    func_800A0DA0(self, 0);
    func_800A0DAC(self, 1);
    _bsmum_entrypoint_1(self);
}

void bsmumcast_entrypoint_1(PlayerState *self) {
    f32 sp24[3];

    _bsmum_entrypoint_2(self);
    func_8008E944(self);
    func_80099A7C(self, sp24);
    func_800A00CC(self, sp24);
    self->unk15C.word = 0;
    if (func_8009EA20() != 0) {
        func_80800000_bsmumcast(self, 4);
        return;
    }
    func_80800000_bsmumcast(self, 1);
}

#ifndef NONMATCHINGS
void bsmumcast_entrypoint_2(PlayerState *self) {
    switch (func_8009E6EC(self)) {
        case 0x15:
        case 0x1C:
        case 0x1D:
        case 0x1E:
        case 0x25:
        case 0x43:
            break;
        default:
            func_80099B94(self);
            break;
    }
}
#else
// Decomp failure
#endif

#ifndef NONMATCHINGS
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/mum/cast/bsmumcast_entrypoint_3.s")
#else
// Decomp failure
#endif

s32 bsmumcast_entrypoint_4(s32 idx) {
    return D_808004A0_bsmumcast[idx];
}
