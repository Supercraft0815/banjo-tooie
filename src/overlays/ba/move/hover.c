#include "common.h"

void bamovehover_entrypoint_0(BtIntPtr arg0) 
{
}
/* extern */

void bamovehover_entrypoint_1(void *arg0) {
    s32 func_800EFA4C(s32, s32, s32, s32);
    s32 func_800EFD24(s32);
    func_800EFD24((*(s32 *)((s8 *)(arg0) + (0xC8))) + 0xAC);
    func_800EFD24((*(s32 *)((s8 *)(arg0) + (0xC8))) + 0xB8);
    func_800EFA4C((*(s32 *)((s8 *)(arg0) + (0xC8))) + 0x10, 0x41855556, 0x42055556, 0x42480000);
}    typedef struct { u8 pad0[0xC8]; s8 * unkC8; } Objhover_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void bamovehover_entrypoint_2(void *arg0) {
    f32 func_800D8FF8(void);
    void func_800EF174(f32[3], f32[3], f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F15F8(f32, f32, f32);
    f32 mlAbsF(f32);
    f32 delta;
    f32 velocity[3];
    f32 difference;
    f32 magnitude;
    f32 speed;
    f32 step;
    s32 i;

    delta = func_800D8FF8();
    func_800EF174((f32 *)(((Objhover_arg0 *)arg0)->unkC8 + 0xAC),
                 (f32 *)(((Objhover_arg0 *)arg0)->unkC8 + 0xB8), delta);
    for (i = 0; i < 3; i++) {
        difference = ((f32 *)(((Objhover_arg0 *)arg0)->unkC8 + 0xAC))[i]
                   - ((f32 *)(((Objhover_arg0 *)arg0)->unkC8 + 4))[i];
        magnitude = mlAbsF(difference);
        if (magnitude > 5.0f) {
            step = 220.0f * delta;
            speed = func_800F10B4(magnitude, 5.0f, 40.0f, 50.0f, 150.0f);
            if (difference > 0.0f) {
                velocity[i] = speed;
            } else {
                velocity[i] = -speed;
            }
            ((f32 *)(((Objhover_arg0 *)arg0)->unkC8 + 0x10))[i] =
                func_800F15F8(((f32 *)(((Objhover_arg0 *)arg0)->unkC8 + 0x10))[i], velocity[i], step);
        }
    }
    func_800EF174((f32 *)(((Objhover_arg0 *)arg0)->unkC8 + 4),
                 (f32 *)(((Objhover_arg0 *)arg0)->unkC8 + 0x10), delta);
}

/* extern */

void bamovehover_entrypoint_3(BT_IDO_ONLY(void *arg0) BT_PASS2(void *arg0, s32 bt_a1)) {
    s32 func_800EE7F8(s32);
    func_800EE7F8((*(s32 *)((s8 *)(arg0) + (0xC8))) + 172);
}

void bamovehover_entrypoint_4(u8 *arg0, BtIntPtr arg1) {
    s32 func_800EE7F8(s32);
    s32 func_800EFD24(s32);
    if (arg1 == 0) {
        func_800EFD24((*(s32 *)((s8 *)(arg0) + (0xC8))) + 0xB8);
        return;
    }
    func_800EE7F8((*(s32 *)((s8 *)(arg0) + (0xC8))) + 0xB8);
}
