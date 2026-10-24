#include "common.h"

u32 *func_80100074(Actor *, u32, u32);

s32 func_80800000_chlagoonfish(Actor *arg0) {
    s32 func_800DC128(s32, s32);
    f32 func_800DC178(f32, f32);
    s32 func_800EE7F8();
    void func_800EF214(f32 *, f32, f32, f32);
    void *func_80100094(Actor *, u32);
    struct {
        f32 position[3];
        f32 rotation[3];
        f32 velocity[3];
        f32 scale;
        f32 unk28;
        s8 image;
        u8 pad2D[3];
    } *data;
    f32 pitch;
    f32 yaw;
    u32 i;

    func_80100074(arg0, 0, arg0->unk6C_0 * 0x30);
    data = func_80100094(arg0, 0);
    for (i = 0; i < arg0->unk6C_0; i++, data++) {
        func_800EE7F8(data->position, arg0->position);
        pitch = func_800DC178(-45.0f, 45.0f);
        yaw = func_800DC178(180.0f, 360.0f);
        func_800EF214(data->position, pitch, yaw, func_800DC178(50.0f, 250.0f));
        data->scale = func_800DC178(arg0->scale * 0.4f, arg0->scale);
        data->image = func_800DC128(0, 3);
        data->velocity[0] = func_800DC178(-400.0f, 400.0f);
        data->velocity[1] = func_800DC178(-400.0f, 400.0f);
        data->velocity[2] = func_800DC178(-400.0f, 400.0f);
        data->unk28 = 400.0f;
    }
}

/* extern */

void func_808001A0_chlagoonfish(Actor *arg0) {
    s32 _subaddiesect_entrypoint_1(Actor *);
    void func_800FFAB0(Actor *);
    s32 func_80800000_chlagoonfish(Actor *);
    void func_80800A44_chlagoonfish(Actor *, s32);
    s32 temp;

    temp = arg0->unk74_7;
    if (temp < 0x33) {
        func_800FFAB0(arg0);
        return;
    }
    arg0->unk6C_0 = temp - 0x32;
    func_80800000_chlagoonfish(arg0);
    func_80800A44_chlagoonfish(arg0, 1);
    ((f32 *)arg0->actorData)[3] = arg0->scale * 600.0f;
    ((f32 *)arg0->actorData)[7] = (f32) _subaddiesect_entrypoint_1(arg0);
}

void func_80800240_chlagoonfish(Actor *arg0) { func_80100074(arg0, 0U, 0U); }

void func_80800264_chlagoonfish(Actor *arg0)
{
    func_80800240_chlagoonfish(arg0);
}

/* extern */

void func_80800284_chlagoonfish(Actor *arg0) {
    void func_80102B2C(Actor *, f32);
    void func_80102B6C(u8 *, f32);
    s32 func_8010B990(Actor *, s32);
    void func_80800A44_chlagoonfish(Actor *, s32);
    func_80102B6C(arg0, 2.0f);
    func_80102B2C(arg0, 2.0f);
    if ((func_8010B990(arg0, 0x500106) & 0x24) && (arg0->unk70_10 != 2)) {
        func_80800A44_chlagoonfish(arg0, 2);
    }
}

/* extern */

typedef union {
    Actor actor;
    struct {
        u8 pad0[0x70];
        u32 unk70_25 : 7;
        u32 pad70_10 : 15;
        u32 unk70_4 : 6;
        u32 pad70_0 : 4;
    } fish;
} LagoonFishActor;

s32 func_808002F8_chlagoonfish(LagoonFishActor *arg0) {
    s32 func_800CC338(f32 (*)[3], s32, s32);
    void func_800EEC30(f32 *, f32, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    f32 sp24[3];
    s32 result;

    func_800EEC30(sp24, arg0->actor.rotation[0], arg0->actor.rotation[1], 200.0f);
    func_800EF04C(sp24, arg0->actor.position);
    result = func_800CC338(&sp24, arg0->fish.unk70_25 - 1, arg0->fish.unk70_4 - 1);
    if (result != -1) {
        arg0->fish.unk70_4 = result + 1;
        return 1;
    }
    return 0;
}

void func_8080038C_chlagoonfish(Actor *arg0) {
    s32 func_8001210C(s32);
    void func_8008FE68(f32 *);
    void func_8008FFBC(f32 *);
    f32 func_800D8FF8(void);
    f32 func_800DC0C0(void);
    f32 func_800DC178(f32, f32);
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EF214(f32 *, f32, f32, f32);
    s32 func_800EFFB4(f32 *, f32, f32 *);
    f32 func_800F1828(f32 *, f32 *);
    void func_800F18FC(f32 *, f32 *, f32 *);
    f32 func_800F1DCC(f32, f32);
    f32 func_800F1DF4(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    void func_80800A44_chlagoonfish(Actor *, s32);
    f32 mlAbsF(f32);
    typedef struct {
        f32 position[3];
        f32 speed;
    } FishHome;
    struct {
        f32 position[3];
        f32 rotation[3];
        f32 velocity[3];
        f32 scale;
        f32 speed;
        s8 image;
        u8 pad2D[3];
    } *data;
    f32 player[3];
    f32 speed;
    f32 delta;
    s32 frame;
    u32 i;
    f32 rotation[3];
    f32 difference;
    f32 target[3];

    if (func_80100094(arg0, 0) == NULL) {
        func_80800000_chlagoonfish(arg0);
    }
    switch (arg0->unk70_10) {
        case 1:
            func_80800284_chlagoonfish(arg0);
            if (!func_808002F8_chlagoonfish((LagoonFishActor *)arg0)) {
                func_80800A44_chlagoonfish(arg0, 2);
            } else if (((FishHome *)arg0->actorData)->speed > 600.0f * arg0->scale) {
                ((FishHome *)arg0->actorData)->speed -= 5.0f * arg0->scale;
            }
            if (func_800DC0C0() < 0.2f) {
                arg0->unk50 += func_800DC178(-15.0f, 15.0f);
            }
            if (func_800DC0C0() < 0.2f) {
                arg0->unk54 += func_800DC178(-15.0f, 15.0f);
            }
            break;
        case 2:
            arg0->unk54 = func_800F1DF4(arg0->position, ((FishHome *)arg0->actorData)->position);
            arg0->unk50 = func_800F1828(arg0->position, ((FishHome *)arg0->actorData)->position);
            func_80800284_chlagoonfish(arg0);
            if (func_800EFFB4(((FishHome *)arg0->actorData)->position, 200.0f, arg0->position)) {
                if (func_808002F8_chlagoonfish((LagoonFishActor *)arg0)) {
                    func_80800A44_chlagoonfish(arg0, 1);
                }
            } else if (((FishHome *)arg0->actorData)->speed > 600.0f * arg0->scale) {
                ((FishHome *)arg0->actorData)->speed -= 15.0f * arg0->scale;
            }
            break;
    }
    delta = func_800D8FF8();
    frame = func_8001210C(1);
    data = func_80100094(arg0, 0);
    func_8008FFBC(player);
    speed = mlAbsF(player[0]) + mlAbsF(player[1]) + mlAbsF(player[2]);
    func_8008FE68(player);
    for (i = 0; i < arg0->unk6C_0; i++, data++) {
        func_800EF214(data->position, data->rotation[0], data->rotation[1], data->speed * delta);
        if ((frame && (i & 1)) || (!frame && !(i & 1))) {
            if (func_800EFFB4(data->position, speed * 0.5f, player)) {
                func_800F18FC(player, data->position, rotation);
                if (data->speed < 400.0f * arg0->scale) {
                    data->speed += 50.0f * arg0->scale;
                }
            } else {
                func_800EE780(target, arg0->position, data->velocity);
                func_800F18FC(data->position, target, rotation);
                if (data->speed > 400.0f * arg0->scale) {
                    data->speed -= 50.0f * arg0->scale;
                }
            }
            if (func_800DC0C0() < 0.02f) {
                data->velocity[0] = func_800DC178(-400.0f, 400.0f);
                data->velocity[1] = func_800DC178(-400.0f, 400.0f);
                data->velocity[2] = func_800DC178(-400.0f, 400.0f);
            }
            difference = func_800F1DCC(rotation[1], data->rotation[1]);
            if (difference > 1.0f) {
                if (data->rotation[2] < 8.0f) {
                    data->rotation[2] += 2.0f;
                }
                data->rotation[1] += data->rotation[2] * 0.5f;
                data->rotation[2] *= 0.9f;
            } else if (difference < -1.0f) {
                if (data->rotation[2] > -8.0f) {
                    data->rotation[2] -= 2.0f;
                }
                data->rotation[1] += data->rotation[2] * 0.5f;
                data->rotation[2] *= 0.9f;
            }
            difference = func_800F1DCC(rotation[0], data->rotation[0]);
            if (difference > 1.0f) {
                if (data->rotation[0] < 10.0f) {
                    data->rotation[0] += 1.0f;
                }
            } else if (difference < -1.0f) {
                if (data->rotation[0] > -10.0f) {
                    data->rotation[0] -= 1.0f;
                }
            }
        }
    }
}

void func_80800908_chlagoonfish(Actor *arg0, s32 arg1) {
    s32 func_800D674C(s32);
    void *func_800DE448(f32 *, f32 *, f32, f32 *, s32);
    void func_800DF830(s32);
    void *func_80100094(Actor *, u32);
    struct {
        f32 position[3];
        f32 rotation[3];
        u8 pad18[12];
        f32 scale;
        u32 unk28;
        u8 image;
        u8 pad2D[3];
    } *data;
    s32 i;
    s32 images[3];

    data = func_80100094(arg0, 0);
    if (data != NULL) {
        for (i = 0; i < 3; i++) {
            images[i] = func_800D674C(arg0->unk0->unk14 + i);
        }
        for (i = 0; i < arg0->unk6C_0; i++, data++) {
            if (images[data->image] != 0) {
                func_800DF830(1);
                func_800DE448(data->position, data->rotation, data->scale, NULL, images[data->image]);
            }
        }
    }
}

/* extern */

void func_808009FC_chlagoonfish(u8 *arg0) {
    s32 func_800CC63C(s32, s32);
    s32 func_800EE7F8(u8 *, s32);
    u32 temp_v0;

    temp_v0 = (*(u32 *)((s8 *)(arg0) + (0x70)));
    func_800EE7F8(arg0 + 0x18, func_800CC63C((temp_v0 >> 0x19) - 1, ((u32) (temp_v0 << 0x16) >> 0x1A) - 1));
}

void func_80800A44_chlagoonfish(Actor *arg0, s32 arg1) {
    f32 func_800DC178(f32, f32);
    void func_80101FDC(Actor *, u32);

    func_80101FDC(arg0, arg1);
    switch (arg1) {
        case 1:
            arg0->unk54 = arg0->rotation[1] + func_800DC178(-90.0f, 90.0f);
            arg0->unk50 = arg0->rotation[0] + func_800DC178(-90.0f, 90.0f);
            break;
        case 2:
            func_808009FC_chlagoonfish((u8 *)arg0);
            break;
    }
}

int func_80800AE0_chlagoonfish(Actor *arg0, s32 arg1, u8 *arg2) {
    s32 func_80103140(Actor *, u32, u16);
    extern u8 D_8012762C;
    switch (arg1) {
        case 0x95:
            if (D_8012762C == 0x15) {
                func_80103140(arg0, 0x698U, arg0->unk0->unk16);
            }
            break;
        default:
            return 0;
    }
    return 1;
}

OSThread *chlagoonfish_entrypoint_0(void)
{
    extern u8 D_80800B70_chlagoonfish[];

    return (OSThread *) D_80800B70_chlagoonfish;
}
