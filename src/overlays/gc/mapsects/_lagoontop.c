#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/_lagoontop/gcmapsects_lagoontop_entrypoint_0.s")

void gcmapsects_lagoontop_entrypoint_1(u8 *arg0) {
    typedef struct {
        u8 pad[0x4C];
        u32 visible : 1;
        u32 active : 1;
        u32 remaining : 30;
        u8 tail[8];
    } Section;
    f32 func_800136E4(f32);
    f32 func_80013728(f32);
    void func_800E39A8(s32, s32);
    u8 func_800E3E8C(void *, f32);
    extern s32 D_80800720_gcmapsects_lagoontop;
    extern s32 D_8080072C_gcmapsects_lagoontop;
    extern s32 D_80800738_gcmapsects_lagoontop;
    extern s32 D_80800744_gcmapsects_lagoontop;
    f32 position[3];
    f32 rotation[3];
    u8 active;

    func_800E39A8((s32)position, (s32)rotation);
    rotation[0] = func_80013728(rotation[0]);
    rotation[1] = func_800136E4(rotation[1]);
    if ((*(Section **)(arg0 + 0x68))[1].visible) {
        if (position[1] < 5100.0f) {
            (*(Section **)(arg0 + 0x68))[1].visible = 0;
            (*(Section **)(arg0 + 0x68))[1].active = 0;
        }
        if (position[2] > -5800.0f && rotation[1] > 95.0f && rotation[1] < 240.0f) {
            (*(Section **)(arg0 + 0x68))[1].visible = 0;
            (*(Section **)(arg0 + 0x68))[1].active = 0;
        }
    }
    if ((*(Section **)(arg0 + 0x68))[0].visible) {
        if (position[1] < 4200.0f && rotation[0] < 0.0f) {
            (*(Section **)(arg0 + 0x68))[0].visible = 0;
        } else if (position[1] < 5050.0f && !func_800E3E8C(&D_80800720_gcmapsects_lagoontop, 1250.0f)) {
            (*(Section **)(arg0 + 0x68))[0].visible = 0;
            (*(Section **)(arg0 + 0x68))[0].active = 0;
        }
    }
    if ((*(Section **)(arg0 + 0x68))[4].visible && position[1] > 4300.0f) {
        (*(Section **)(arg0 + 0x68))[4].visible = 0;
        (*(Section **)(arg0 + 0x68))[4].active = 0;
    }
    if ((*(Section **)(arg0 + 0x68))[2].visible) {
        if (position[2] > 0.0f && rotation[1] > 160.0f && rotation[1] < 320.0f) {
            (*(Section **)(arg0 + 0x68))[2].visible = 0;
            (*(Section **)(arg0 + 0x68))[2].active = 0;
        } else if (position[1] > 5150.0f && !func_800E3E8C(&D_8080072C_gcmapsects_lagoontop, 1000.0f)) {
            (*(Section **)(arg0 + 0x68))[2].visible = 0;
            (*(Section **)(arg0 + 0x68))[2].active = 0;
        } else if (position[0] > -4700.0f && position[1] < 10000.0f) {
            (*(Section **)(arg0 + 0x68))[2].visible = 0;
            (*(Section **)(arg0 + 0x68))[2].active = 0;
        }
    }
    if ((*(Section **)(arg0 + 0x68))[4].visible) {
        if (position[2] > 4000.0f) {
            if (rotation[1] > 90.0f && rotation[1] < 270.0f) {
                (*(Section **)(arg0 + 0x68))[4].visible = 0;
                (*(Section **)(arg0 + 0x68))[4].active = 0;
            }
        } else if (!(*(Section **)(arg0 + 0x68))[4].active && !func_800E3E8C(&D_80800738_gcmapsects_lagoontop, 450.0f)) {
            (*(Section **)(arg0 + 0x68))[4].visible = 0;
            (*(Section **)(arg0 + 0x68))[4].active = 0;
        }
    }
    active = arg0[0x7E];
    if (active && ((position[1] < 8000.0f && rotation[0] < -20.0f) ||
                   (position[1] < 6000.0f && rotation[0] < 0.0f))) {
        active = arg0[0x7E] = 0;
    }
    if (active && position[1] < 4000.0f && rotation[0] >= 0.0f) {
        arg0[0x7E] = func_800E3E8C(&D_80800744_gcmapsects_lagoontop, 982.0f);
    }
    if ((*(Section **)(arg0 + 0x68))[0].active) {
        (*(Section **)(arg0 + 0x68))[1].active = 1;
    }
}
