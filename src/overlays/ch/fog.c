#include "common.h"

/* extern */

void func_80800000_chfog(s32 arg0) {
    s32 func_800CF494();
    func_800CF494();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fog/func_80800020_chfog.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fog/func_80800174_chfog.s")

void func_8080032C_chfog(f32 *arg0) {
    f32 func_800DC0C0(void);
    void func_800E3B50(f32 *, f32 *, f32 *);
    void func_800E3980(f32 *);
    void func_800EFB24(void *, void *, void *);
    s32 func_800F54E4(void);
    s32 func_800F690C(s32);
    void func_800EE7F8(f32 *, f32 *);
    s32 func_800D90A4(f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    s32 _subaddiefade_entrypoint_1(s32, s32);
    struct FogFlags {
        u32 unused : 12;
        u32 fading : 1;
        u32 rest : 19;
    };
    f32 roll;
    f32 pitch;
    f32 yaw;
    f32 position[3];
    f32 delta[3];
    s16 direction;

    if (func_800DC0C0() < 0.01f) {
        arg0[6] = -arg0[6];
    }
    if (func_800DC0C0() < 0.01f) {
        arg0[7] = -arg0[7];
    }
    if (arg0[6] == 1.0f) {
        if (arg0[10] < 0.15f) {
            arg0[10] += 0.05f;
        }
    } else {
        if (arg0[10] > -0.15f) {
            arg0[10] -= 0.05f;
        }
    }
    if (arg0[7] == 1.0f) {
        if (arg0[11] < 0.15f) {
            arg0[11] += 0.05f;
        }
    } else {
        if (arg0[11] > -0.15f) {
            arg0[11] -= 0.05f;
        }
    }
    if (arg0[1] < -200.0f && arg0[6] != 1.0f) {
        arg0[6] = 1.0f;
    } else if (arg0[1] > 200.0f && arg0[6] != -1.0f) {
        arg0[6] = -1.0f;
    } else {
        arg0[1] += arg0[10];
    }
    if (arg0[2] < -200.0f && arg0[7] != 1.0f) {
        arg0[7] = 1.0f;
    } else if (arg0[2] > 200.0f && arg0[7] != -1.0f) {
        arg0[7] = -1.0f;
    } else {
        arg0[2] += arg0[11];
    }
    direction = 0;
    func_800E3B50(&pitch, &yaw, &roll);
    func_800E3980(position);
    func_800EFB24(delta, position, &arg0[17]);
    if (func_800F690C(func_800F54E4()) == 0) {
        if (yaw > 135.0f && yaw < 225.0f) {
            if (delta[0] < -5.0f) {
                direction = 1;
            }
            if (delta[0] > 5.0f) {
                direction = -1;
            }
        }
        if (yaw > 315.0f || yaw < 45.0f) {
            if (delta[0] < -5.0f) {
                direction = -1;
            }
            if (delta[0] > 5.0f) {
                direction = 1;
            }
        }
        if (yaw > 45.0f && yaw < 135.0f) {
            if (delta[2] < -5.0f) {
                direction = 1;
            }
            if (delta[2] > 5.0f) {
                direction = -1;
            }
        }
        if (yaw > 225.0f && yaw < 315.0f) {
            if (delta[2] < -5.0f) {
                direction = -1;
            }
            if (delta[2] > 5.0f) {
                direction = 1;
            }
        }
    } else {
        if (arg0[21] < yaw) {
            direction = -1;
        }
        if (arg0[21] > yaw) {
            direction = 1;
        }
        if (arg0[20] > pitch) {
            delta[1] = -5.0f;
        }
        if (arg0[20] < pitch) {
            delta[1] = 5.0f;
        }
        arg0[21] = yaw;
        arg0[20] = pitch;
    }
    func_800EE7F8(&arg0[17], position);
    if (direction == 1) {
        arg0[6] = -1.0f;
        arg0[10] += (-5.0f - arg0[10]) * 0.5f;
    } else if (direction == -1) {
        arg0[6] = 1.0f;
        arg0[10] += (5.0f - arg0[10]) * 0.5f;
    } else if (arg0[10] > 0.15f || arg0[10] < 0.15f) {
        arg0[10] *= 0.8f;
    }
    if (delta[1] > 2.5f) {
        arg0[7] = -1.0f;
        arg0[11] += (-2.0f - arg0[11]) * 0.5f;
    } else if (delta[1] < -2.5f) {
        arg0[7] = 1.0f;
        arg0[11] += (2.0f - arg0[11]) * 0.5f;
    } else if (arg0[10] > 0.15f || arg0[10] < 0.15f) {
        arg0[10] *= 0.3f;
    }
    switch ((s32)((u32)*(u16 *)((u8 *)arg0 + 0x72) >> 10)) {
        case 1:
            if (((struct FogFlags *)((u8 *)arg0 + 0x64))->fading) {
                if (!func_800D90A4(&arg0[13])) {
                    _subaddiefade_entrypoint_1((s32)arg0,
                        (s32)func_800F10B4(arg0[13], 0.0f, 8.0f, 255.0f, 0.0f));
                }
            }
            break;
        case 2:
            break;
    }
}

s32 func_808009F0_chfog(Actor *arg0, s32 arg1, s32 arg2) {
    void _subaddiefade_entrypoint_3(Actor*);
    s32 func_800CF494();
    switch (arg1) {
    case 0x4F:
        _subaddiefade_entrypoint_3(arg0);
        func_800CF494();
        break;
    default:
        return 0;
    }
    return 1;
}

OSThread *chfog_entrypoint_0(void)
{
    extern u8 D_80800A90_chfog[];

    return (OSThread *) D_80800A90_chfog;
}
