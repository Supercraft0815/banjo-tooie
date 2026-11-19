#include "common.h"
#include "core2/particle_colors.h"

void func_800B43E0(void) {
    extern u8 D_80127F00[3];
    u8 func_800B5758(s32);
    s32 i;
    for (i = 0; i < 3; i++) {
        D_80127F00[i] = func_800B5758(0x20);
    }
}

void func_800B4428(void) {
    extern u8 D_80127F00[3];
    void func_800B58D4(u8);
    s32 i;
    for (i = 0; i < 3; i++) {
        func_800B58D4(D_80127F00[i]);
    }
}

void func_800B4470(f32 position[3], f32 velocity[3], u8 color[4], s32 useDefaultDrawMode, f32 lifetime, f32 additionalYVelocity, s32 startingScale, s32 finalScale, s32 type) {
    extern u8 D_80127F00[3];
    extern u16 D_8011A5B0[];
    void *func_800B56D0(u8);
    void func_800BA22C(BtIntPtr, s32);
    void func_800BA3FC(BtIntPtr, s32);
    void func_800BA75C(BtIntPtr, f32[3]);
    void func_800BA930(BtIntPtr, s16, s16, s16, s16, s16, s16);

    void func_800BA594(void *, f32, f32);
    void func_800BA5A8(s16 *, s32);
    void func_800BA5B0(s16 *, s32, s32);
    void func_800BA5BC(void *, f32, f32);
    void func_800BA7C4(void *, f32, f32);
    void func_800BA7FC(void *, f32, f32);
    void func_800BA8F8(void *, f32, f32);
    void func_800EFA20(void *, void *, f32);
    s32 pad1;
    s32 pad2;
    s32 pad3;
    f32 velocity_range[3];
    s32 draw_mode;
    void *emitter;

    draw_mode = 0x228;
    emitter = func_800B56D0(D_80127F00[type]);
    func_800BA3FC(emitter, D_8011A5B0[type]);
    func_800BA594(emitter, 0.075f, 0.4f);
    func_800BA75C(emitter, position);
    if (velocity != NULL) {
        func_800EFA20(velocity_range, velocity, 30.0f);
    } else {
        velocity_range[0] = velocity_range[1] = velocity_range[2] = 0.0f;
    }
    if (additionalYVelocity != 0.0f) {
        velocity_range[1] += additionalYVelocity / lifetime;
    }
    func_800BA930(emitter, velocity_range[0], velocity_range[1], velocity_range[2],
        velocity_range[0], velocity_range[1], velocity_range[2]);
    if (color != NULL) {
        func_800BAB80(emitter, color);
    }
    if (useDefaultDrawMode == 0) {
        draw_mode = 0x238;
    }
    func_800BA5A8(emitter, draw_mode);
    func_800BA8F8(emitter, lifetime, lifetime);
    func_800BA7C4(emitter, startingScale / 175.0f, startingScale / 175.0f);
    func_800BA7FC(emitter, (startingScale + finalScale) / 175.0f, (startingScale + finalScale) / 175.0f);
    if (D_8011A5B0 == &D_8011A5B0[type]) {
        func_800BA5BC(emitter, 15.0f / lifetime, 15.0f / lifetime);
    } else {
        func_800BA5B0(emitter, 0, 0xC);
    }
    func_800BA22C(emitter, 1);
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
u8 D_80127F00 [ 3 ] BT_DATA(4, bss_core2bss1_0_2, 0x760);
#endif
