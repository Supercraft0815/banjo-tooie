#include "common.h"

/* extern */

void func_80800000_chfog(s32 arg0) {
    void func_800CF494(void);
    func_800CF494();
}

void func_80800020_chfog(Actor *arg0) {
    void func_800CF2D4(s32);
    s32 func_800DA298(s32);
    void func_800E3980(f32 *);
    s32 func_800EA05C(void);
    void func_800EFD24(f32 *);
    BtIntPtr func_800F54E4(void);
    s32 func_800F6438(BtUIntPtr);
    void func_800FFAB0(Actor *);
    void func_80101FDC(Actor *, u32);
    void _subaddiefade_entrypoint_2(void *arg0);
    struct FogData {
        f32 unk18;
        f32 unk1C;
        f32 unk20;
        f32 unk24;
        f32 unk28[3];
        f32 unk34;
    };

    func_800E3980(arg0->rotation);
    func_800EFD24(arg0->position);
    func_800EFD24(((struct FogData *)arg0->actorData)->unk28);
    ((struct FogData *)arg0->actorData)->unk18 = 1.0f;
    ((struct FogData *)arg0->actorData)->unk1C = 1.0f;
    switch (func_800EA05C()) {
        case 0x10D:
            if (!func_800DA298(0x1BD)) {
                func_800FFAB0(arg0);
            } else if (arg0->unk7A_5 && func_800F6438(func_800F54E4())) {
                ((struct FogData *)arg0->actorData)->unk34 = 0.0f;
                func_800CF2D4(4);
            }
            arg0->unk64_19 = 1;
            ((struct FogData *)arg0->actorData)->unk24 = 0.0f;
            break;
        case 0x138:
            func_800CF2D4(6);
            break;
        case 0x162:
            func_80101FDC(arg0, 2);
            _subaddiefade_entrypoint_2(arg0);
            func_800CF2D4(7);
            break;
        case 0x19A:
            func_80101FDC(arg0, 2);
            _subaddiefade_entrypoint_2(arg0);
            func_800CF2D4(8);
            arg0->unk74_17 = 0;
            break;
        default:
            func_800CF2D4(2);
            break;
    }
}

void func_80800174_chfog(Actor *arg0, Gfx **arg1) {
    s32 _subaddiefade_entrypoint_0(Actor *);
    Actor *_subaddiefind_entrypoint_2(s32, BtIntPtr);
    void *func_800DE448(f32 *, f32 *, f32, f32 *, BtIntPtr);
    void func_800DF410(s32);
    void func_800DF744(s32, s32);
    void func_800DF830(s32);
    void func_800E3BAC(f32 *);
    void func_800E3C30(f32 *);
    void func_800E3CE8(void);
    void func_800E41CC(void);
    void func_800E4208(void);
    int func_800E44FC(void *frame);
    s32 func_800EA05C(void);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800EFD24(f32 *);
    void func_80101074(void *);
    s32 func_8010114C(BtIntPtr, s32, BtIntPtr);
    void func_80101870(Actor *, void *);
    BtIntPtr func_8010347C(Unk80132ED0 *);
    f32 position[3];
    f32 rotation[3];
    s32 map;
    Actor *actor;
    Actor *other;

    map = func_800EA05C();
    switch (map) {
        case 0x10D:
            other = _subaddiefind_entrypoint_2(0x416, 0);
            if (other != NULL) {
                func_80101870(other, arg1);
            }
            func_800DF744(3, 1);
            break;
        case 0xDB:
            actor = _subaddiefind_entrypoint_2(0x176, 0);
            if (actor != NULL) {
                func_80101074(arg1);
                func_8010114C((BtIntPtr)actor->unk0, 0xAB, 0);
            }
            func_800DF744(3, 1);
            break;
        case 0x138:
            func_800DF744(3, 2);
            break;
        case 0x162:
            func_800DF744(3, 2);
            break;
        case 0x19A:
            func_800DF744(3, 3);
            break;
        default:
            func_800DF744(3, 1);
            break;
    }
    func_800E41CC();
    func_800EFA4C(position, 0.0f, 0.0f, 300.0f);
    func_800EFD24(rotation);
    func_800E3BAC(position);
    func_800E3C30(rotation);
    func_800E3CE8();
    func_800E44FC(arg1);
    rotation[0] = -90.0f;
    func_800DF410(_subaddiefade_entrypoint_0(arg0));
    func_800DF830(0);
    func_800DE448(arg0->position, rotation, 0.2f, NULL, func_8010347C(arg0->unk0));
    func_800E4208();
    func_800E44FC(arg1);
}    typedef struct { u8 pad0[0x72]; u16 unk72; } Objfog_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_8080032C_chfog(f32 *arg0) {
    f32 func_800DC0C0(void);
    void func_800E3B50(f32 *, f32 *, f32 *);
    void func_800E3980(f32 *);
    void func_800EFB24(void *, void *, void *);
    BtIntPtr func_800F54E4(void);
    s32 func_800F690C(BtIntPtr);
    void func_800EE7F8(f32 *, f32 *);
    s32 func_800D90A4(f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void _subaddiefade_entrypoint_1(void *arg0, s32 arg1);
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
    switch ((s32)((u32)*&((Objfog_arg0 *)arg0)->unk72 >> 10)) {
        case 1:
            if (((struct FogFlags *)((u8 *)arg0 + 0x64))->fading) {
                if (!func_800D90A4(&arg0[13])) {
                    _subaddiefade_entrypoint_1((BtIntPtr)arg0,
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
    void func_800CF494(void);
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
    extern ActorData D_80800A90_chfog[];

    return (OSThread *) D_80800A90_chfog;
}
/* data_to_c.py: from asm/data/overlays/ch/fog.data.s */
void func_80105834(Actor*);
void func_80107C2C();
ActorData D_80800A90_chfog [1] BT_DATA(4, overlays_ch_fog, 0x0) = { { 604, 376, 1676, 1, 0, (void (*)(struct Actor *))func_8080032C_chfog, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80800174_chfog, 0, 0, 0, 0, 2, 5124, (void (*)(struct Actor *))func_80800000_chfog, 0, 0, 0, (void (*)(struct Actor *))func_80800020_chfog, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1026, (void (*)(struct Actor *, long, long))func_808009F0_chfog, 0 } };
