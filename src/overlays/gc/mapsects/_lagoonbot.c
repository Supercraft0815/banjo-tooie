#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/_lagoonbot/gcmapsects_lagoonbot_entrypoint_0.s")

void gcmapsects_lagoonbot_entrypoint_1(u8 *arg0) {
    f32 func_800136E4(f32);
    f32 func_80013728(f32);
    void func_800E39A8(s32, s32);
    u8 func_800E3E8C(void *, f32);
    extern s32 D_808002F4_gcmapsects_lagoonbot;
    f32 position[3];
    f32 rotation[3];
    u8 active;

    func_800E39A8((s32)position, (s32)rotation);
    rotation[0] = func_80013728(rotation[0]);
    rotation[1] = func_800136E4(rotation[1]);
    active = arg0[0x7E];
    if (active && ((position[1] < 8000.0f && rotation[0] < -20.0f) ||
                   (position[1] < 6000.0f && rotation[0] < 0.0f))) {
        active = arg0[0x7E] = 0;
    }
    if (active && position[1] < 4000.0f && rotation[0] >= 0.0f) {
        arg0[0x7E] = func_800E3E8C(&D_808002F4_gcmapsects_lagoonbot, 982.0f);
    }
}
