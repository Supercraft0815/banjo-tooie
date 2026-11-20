#include "core2/1E7D460.h"

s32 func_800A3B70() 
{
    return BT_IDO_ONLY(0x40) BT_NATIVE_ONLY(sizeof(FirstPersonCameraState));
}

/* extern */

void func_800A3B78(PlayerState *arg0, s32 arg1) {
    s32 func_801106A8(PlayerState *, s32);
    PlayerState *temp_v0;

    temp_v0 = func_800A4CA8(arg0);
    if (temp_v0 != NULL) {
        func_801106A8(temp_v0, arg1);
    }
}

s32 func_800A3BA8(BtIntPtr arg0, s32 arg1) {
    void func_80110CC0(BtIntPtr, f32, f32, f32, f32);
    void func_80115564(u8 *);
    PlayerState *player;
    u8 *data;

    player = func_800A4CA8((PlayerState *)arg0);
    if (player != NULL) {
        data = *(u8 **)(arg0 + 0x38);
        switch (data[2]) {
        case 1:
            func_80110CC0((BtIntPtr)player,
                *(f32 *)(data + 0x2C) * (f32)*(s32 *)(data + 8),
                *(f32 *)(data + 0x2C) * (f32)*(s32 *)(data + 0xC),
                *(f32 *)(data + 0x30) * (f32)*(s32 *)(data + 0x10),
                (f32)*(s16 *)(data + 0x34));
            break;
        case 2:
            func_80110CC0((BtIntPtr)player,
                *(f32 *)(data + 0x2C) * (f32)*(s32 *)(data + 0x14),
                *(f32 *)(data + 0x2C) * (f32)*(s32 *)(data + 0x18),
                *(f32 *)(data + 0x30) * (f32)*(s32 *)(data + 0x1C),
                (f32)*(s16 *)(data + 0x34));
            break;
        case 3:
            func_80110CC0((BtIntPtr)player,
                *(f32 *)(data + 0x2C) * (f32)*(s32 *)(data + 0x20),
                *(f32 *)(data + 0x2C) * (f32)*(s32 *)(data + 0x24),
                *(f32 *)(data + 0x30) * (f32)*(s32 *)(data + 0x28),
                (f32)*(s16 *)(data + 0x34));
            break;
        case 4:
            func_80110CC0((BtIntPtr)player,
                250.0f, 300.0f, 50.0f, (f32)*(s16 *)(data + 0x34));
            break;
        }
        if (arg1 != 0) {
            func_80115564((u8 *)player);
        }
    }
BT_NATIVE_ONLY(return 0;) }    typedef struct { u8 pad0[0x2]; u8 unk2; } Obj1E7D460_func_800A3D78_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

void func_800A3D78(u8 *arg0, s32 arg1, s32 arg2) {
    s32 func_800A3BA8(BtIntPtr, s32);
    u8 *temp_v0;

    temp_v0 = (*(u8 **)((s8 *)(arg0) + (0x38)));
    if (arg1 != (((Obj1E7D460_func_800A3D78_temp_v0 *)temp_v0)->unk2)) {
        (((Obj1E7D460_func_800A3D78_temp_v0 *)temp_v0)->unk2) = arg1;
        func_800A3BA8((BtIntPtr)arg0, arg2);
    }
}

u32 func_800A3DAC(void *arg0) {
    return *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 56) + 2);
}    typedef struct { u8 pad0[0x1]; u8 unk1; u8 pad2[0x1E]; s32 unk20; u8 pad24[0x10]; s16 unk34; u8 pad36[0x3]; u8 unk39; } Obj1E7D460_func_800A3DB8_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

void func_800A3DB8(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 func_800A3BA8(BtIntPtr, s32);
    void func_800A59B8(s32, s32 *, s32 *, s32 *, s32 *, s32 *, s32 *, s32 *, s32 *, s32 *);
    u8 *temp_v0;

    temp_v0 = (*(u8 **)((s8 *)(arg0) + (0x38)));
    if ((arg1 != (((Obj1E7D460_func_800A3DB8_temp_v0 *)temp_v0)->unk1)) || (arg2 != (((Obj1E7D460_func_800A3DB8_temp_v0 *)temp_v0)->unk34)) || (arg3 != (((Obj1E7D460_func_800A3DB8_temp_v0 *)temp_v0)->unk39))) {
        (((Obj1E7D460_func_800A3DB8_temp_v0 *)temp_v0)->unk1) = (u8) arg1;
        temp_v0 = (*(u8 **)((s8 *)(arg0) + (0x38)));
        func_800A59B8((((Obj1E7D460_func_800A3DB8_temp_v0 *)temp_v0)->unk1), (s32 *)(temp_v0 + 8), (s32 *)(temp_v0 + 0xC), (s32 *)(temp_v0 + 0x10), (s32 *)(temp_v0 + 0x14), (s32 *)(temp_v0 + 0x18), (s32 *)(temp_v0 + 0x1C), (s32 *)(temp_v0 + 0x20), (s32 *)(temp_v0 + 0x24), (s32 *)(temp_v0 + 0x28));
        (*(s16 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x38)))) + (0x34))) = (s16) arg2;
        (*(u8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x38)))) + (0x39))) = (u8) arg3;
        if ((func_800A3DAC(arg0) == 3) && ((temp_v0 = (*(u8 **)((s8 *)(arg0) + (0x38))), ((((Obj1E7D460_func_800A3DB8_temp_v0 *)temp_v0)->unk20) == 0)) || ((((Obj1E7D460_func_800A3DB8_temp_v0 *)temp_v0)->unk39) != 0))) {
            func_800A3D78(arg0, 2, arg4);
            return;
        }
        func_800A3BA8((BtIntPtr)arg0, arg4);
    }
}

/* extern */

void func_800A3EC8(PlayerState *arg0, s32 arg1) {
    BT_IDO_ONLY(s32 func_80110D08(PlayerState *, u8, PlayerState *);) BT_NATIVE_ONLY(s32 func_80110D08(void *, s32);)
    if (arg1 != (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x38)))) + (7)))) {
        (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x38)))) + (7))) = arg1;
        BT_IDO_ONLY(func_80110D08(func_800A4CA8(arg0), (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x38)))) + (7))), arg0);) BT_NATIVE_ONLY(func_80110D08(func_800A4CA8(arg0), (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x38)))) + (7))));)
    }
}    typedef struct { u8 pad0[0x3A]; u8 unk3A; } Obj1E7D460_func_800A3F14_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

void func_800A3F14(PlayerState *arg0, s32 arg1) {
    void func_80090C28(PlayerState *, s32);
    u8 *temp_v0;

    temp_v0 = (*(void **)((s8 *)(arg0) + (0x38)));
    if (arg1 != temp_v0[6]) {
        switch (temp_v0[6]) {                          /* switch 1; irregular */
        case 5:                                     /* switch 1 */
            func_80090C28(arg0, 1);
            break;
        case 7:                                     /* switch 1 */
            func_800A3D78(arg0, (((Obj1E7D460_func_800A3F14_temp_v0 *)temp_v0)->unk3A), 1);
            (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x38)))) + (0x3A))) = 0;
            break;
        }
        switch (arg1) {                             /* switch 2; irregular */
        case 2:                                     /* switch 2 */
            func_800A3B78(arg0, 0x13);
            break;
        case 7:                                     /* switch 2 */
            func_800A3B78(arg0, 0x1A);
            (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x38)))) + (0x3A))) = func_800A3DAC(arg0);
            func_800A3D78(arg0, 4U, 1);
            break;
        case 8:                                     /* switch 2 */
            func_800A3B78(arg0, 0x18);
            break;
        case 6:                                     /* switch 2 */
            func_800A3B78(arg0, 2);
            break;
        }
        (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x38)))) + (6))) = (s8) arg1;
    }
} typedef struct { u8 pad0[0x38]; union { u8 * unk38; void * unk38_voidp; }; } Obj1E7D460_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void func_800A4030(void *arg0) {
    void func_800A4074(PlayerState *, s32);
    if ((*(u8 *)((s8 *)((((Obj1E7D460_arg0 *)arg0)->unk38_voidp)) + (6))) == 9) {
        func_800A4074(arg0, 9);
        return;
    }
    func_800A4074(arg0, 2);
}

void func_800A4074(PlayerState *arg0, s32 arg1) {
    void _batimer_set(PlayerState *, s32, f32);
    void func_80090B98(PlayerState *);
    void func_800A5A4C(void);
    u8 *temp_v0;

    func_800A5A4C();
    func_80090B98(arg0);
    (*(u8 **)((u8 *)arg0 + 0x38))[0] = 0;
    (*(u8 **)((u8 *)arg0 + 0x38))[6] = 0;
    (*(u8 **)((u8 *)arg0 + 0x38))[3] = 0;
    (*(u8 **)((u8 *)arg0 + 0x38))[4] = 0;
    (*(u8 **)((u8 *)arg0 + 0x38))[5] = 0;
    *(f32 *)(*(u8 **)((u8 *)arg0 + 0x38) + 0x30) = 1.0f;
    temp_v0 = *(u8 **)((u8 *)arg0 + 0x38);
    *(f32 *)(temp_v0 + 0x2C) = *(f32 *)(temp_v0 + 0x30);
    func_800A3F14(arg0, arg1);
    (*(u8 **)((u8 *)arg0 + 0x38))[2] = 2;
    (*(u8 **)((u8 *)arg0 + 0x38))[1] = 0xFF;
    func_800A3DB8((u8 *)arg0, 0, 0, 0, 1);
    (*(u8 **)((u8 *)arg0 + 0x38))[7] = 0xFF;
    func_800A3EC8(arg0, 0);
    _batimer_set(arg0, 7, 0.5f);
    *(s16 *)(*(u8 **)((u8 *)arg0 + 0x38) + 0x36) = -1;
}

void func_800A4160(BtIntPtr arg0) 
{
}
/* extern */

void func_800A4168(PlayerState *arg0) {
    void func_800A4074(PlayerState *, s32);
    (*(s32 *)((s8 *)((((Obj1E7D460_arg0 *)arg0)->unk38)) + (0x3C))) = 0;
    func_800A4074(arg0, 2);
}

BT_IDO_ONLY(void func_800A4190(arg)) BT_NATIVE_ONLY(void func_800A4190(PlayerState *arg0)) {
    BT_IDO_ONLY(PlayerState *arg0 = (PlayerState *)arg;)
    s32 func_800A4D40(void *);
    s32 func_800F65D0(BtIntPtr);
    s32 func_8009CC68(PlayerState *);
    s32 func_800F3ED0(void *);
    f32 _batimer_get(void *, s32);
    int bainput_should_exit_first_person(PlayerState *);
    void func_8009DB04(PlayerState *, s32, f32, s32);
    void _batimer_set(PlayerState *, s32, f32);
    u8 *temp_v0;

    if (func_800A4D40(arg0) != 0 &&
        func_800F65D0(arg0->unk184) != 0 &&
        func_8009CC68(arg0) == 0 &&
        func_800F3ED0(arg0) != 4 &&
        _batimer_get(arg0, 7) == 0.0f &&
        bainput_should_exit_first_person(arg0) != 0) {
        temp_v0 = *(u8 **)((u8 *)arg0 + 0x38);
        if (temp_v0[4] == 0 && temp_v0[0x3B] == 0) {
            switch (temp_v0[2]) {
                case 1:
                    func_8009DB04(arg0, 0x488, 1.0f, 0x2EE0);
                    func_800A3D78((u8 *)arg0, 2, 1);
                    break;
                case 2:
                    if (*(s32 *)(temp_v0 + 0x20) != 0 && temp_v0[0x39] == 0) {
                        func_8009DB04(arg0, 0x488, 1.2f, 0x2EE0);
                        func_800A3D78((u8 *)arg0, 3, 1);
                    } else {
                        func_8009DB04(arg0, 0x487, 1.0f, 0x2EE0);
                        func_800A3D78((u8 *)arg0, 1, 1);
                    }
                    break;
                case 3:
                    func_8009DB04(arg0, 0x487, 1.0f, 0x2EE0);
                    func_800A3D78((u8 *)arg0, 1, 1);
                    break;
            }
            _batimer_set(arg0, 7, 0.4f);
        }
    }
}

BT_IDO_ONLY(s32 func_800A4338(arg0)) BT_NATIVE_ONLY(s32 func_800A4338(PlayerState *self)) {
    typedef struct {
        u8 pad0[2];
        u8 mode;
        u8 saved;
        u8 desired;
        u8 flags;
        u8 pad6[0x30];
        s16 id;
        u8 active;
    } Camera;
    s32 func_80090E24(PlayerState *);
    s32 func_80090E30(PlayerState *);
    s32 func_800A5854(s32);
    s32 func_800A5904();
    BT_IDO_ONLY(s32 func_800A5800(s32);) BT_NATIVE_ONLY(u8 *func_800A5800(s32);)
    s32 bs_getCurrentState(PlayerState *);
    s32 func_8009CA70(PlayerState *, s32, s32);
    void func_800A3EC8(PlayerState *, s32);
    BT_IDO_ONLY(void func_800A4190();) BT_NATIVE_ONLY(void func_800A4190(PlayerState *);)
    s8 func_800A5B6C(void);
    s8 func_800A5B7C(void);
    f32 func_800A5B8C(void);
    u8 func_800A5B9C(void);
    u8 func_800A5BAC(void);
    u8 func_800A5BBC(void);
    u8 func_800A5BCC(void);
    void func_80110F44(PlayerState *);
    void func_80110D80(PlayerState *, s32);
    void func_80110D28(u8 *, s32);
    void func_80110D58(u8 *, f32);
    void func_801108A0(PlayerState *);
    void func_800CA628(f32 *, f32 *, f32 *);
    s32 _cadbfunc_entrypoint_0(f32 *arg0);
    s32 _cadbfunc_entrypoint_2(f32 *arg0);
    s32 _cadbfunc_entrypoint_22(s32 *arg0);
    s32 _cadbfunc_entrypoint_24(s32 *arg0);
    s32 _cadbfunc_entrypoint_26(s32 *arg0);
    s32 _cadbfunc_entrypoint_29(s32 arg0, s32 *arg1);
    s32 _cadbfunc_entrypoint_32(f32 *arg0);
    s32 _cadbfunc_entrypoint_34(s32 *arg0);
    void _ncbadolly_entrypoint_4(PlayerState *, s32);
    void _ncbafixpos_entrypoint_4(PlayerState *, s32);
    void _ncbaspiral_entrypoint_5(PlayerState *, s32);
    s32 id;
    BT_IDO_ONLY(PlayerState *self = (PlayerState *)arg0;)
    s32 mode;
    s32 flag;
    s32 value1;
    s32 value2;
    s32 forced;
    s32 transition;
    f32 speed;
    s32 type;
    s32 dollyEnabled;
    s32 fixedEnabled;
    f32 position[3];
    f32 rotation[3];
    u8 *floatCamera;

    id = func_80090E24(self);
    forced = 0;
    transition = func_80090E30(self);
    type = func_800A5854(id);

    if (id == -1 || !func_800A5904(id) ||
        ((*(Camera **)self->pad38)->active && type != 4)) {
        (*(Camera **)self->pad38)->desired = func_800A5B9C();
        if ((*(Camera **)self->pad38)->desired == 5) {
            forced = 1;
            (*(Camera **)self->pad38)->desired = 0;
        }
        type = func_800A5B7C();
        func_800A3DB8(self, 0, type, forced, transition);
        type = func_800A5BBC();
        func_800A3EC8(self, type);
        if ((*(Camera **)self->pad38)->desired) {
            func_800A3D78(self, (*(Camera **)self->pad38)->desired, transition);
        } else if ((*(Camera **)self->pad38)->active) {
            if ((*(Camera **)self->pad38)->saved) {
                func_800A3D78(self, (*(Camera **)self->pad38)->saved, transition);
            } else {
                func_80110F44(func_800A4CA8(self));
            }
        }
        (*(Camera **)self->pad38)->flags = func_800A5BAC();
        func_80110D80(func_800A4CA8(self), func_800A5BCC());
        func_80110D28((u8 *)func_800A4CA8(self), func_800A5B6C());
        floatCamera = (u8 *)func_800A4CA8(self);
        func_80110D58(floatCamera, func_800A5B8C());
        (*(Camera **)self->pad38)->active = 0;
        return 0;
    }
    transition = bs_getCurrentState(self);
    switch (type) {
    case 4:
        func_800A5800(id);
        _cadbfunc_entrypoint_26(&mode);
        if (!mode && (*(Camera **)self->pad38)->active &&
            id + 1 != (*(Camera **)self->pad38)->active &&
            (*(Camera **)self->pad38)->saved) {
            mode = (*(Camera **)self->pad38)->saved;
        }
        if (mode == 5) {
            forced = 1;
            mode = 0;
        }
        if (!mode && (*(Camera **)self->pad38)->mode == 4) {
            mode = 1;
        }
        if (!(*(Camera **)self->pad38)->active) {
            _cadbfunc_entrypoint_29(0x10, &flag);
            if (flag) {
                (*(Camera **)self->pad38)->saved = func_800A3DAC(self);
            } else {
                (*(Camera **)self->pad38)->saved = 0;
            }
        }
        if (mode) {
            func_800A3D78(self, mode, 0);
        }
        (*(Camera **)self->pad38)->desired = mode;
        _cadbfunc_entrypoint_22(&value1);
        _cadbfunc_entrypoint_24(&value2);
        func_800A3DB8(self, value2, value1, forced, 0);
        _cadbfunc_entrypoint_29(0x40, &flag);
        func_800A3EC8(self, flag);
        _cadbfunc_entrypoint_29(0x20, &flag);
        (*(Camera **)self->pad38)->flags = flag;
        _cadbfunc_entrypoint_29(0x80, &flag);
        func_80110D80(func_800A4CA8(self), flag);
        _cadbfunc_entrypoint_34(&value1);
        func_80110D28((u8 *)func_800A4CA8(self), value1);
        _cadbfunc_entrypoint_32(&speed);
        func_80110D58((u8 *)func_800A4CA8(self), speed);
        (*(Camera **)self->pad38)->active = id + 1;
        return 0;
    case 3:
        if (func_8009CA70(self, transition, 0x4000)) {
            dollyEnabled = 0;
            func_800A5800(id);
            _cadbfunc_entrypoint_29(4, &dollyEnabled);
            if (!dollyEnabled) {
                return 0;
            }
        }
        func_800A3B78(self, 0xD);
        _ncbadolly_entrypoint_4(func_800A4CA8(self), id);
        func_800A3F14(self, 4);
        return 1;
    case 1:
        if (func_8009CA70(self, transition, 0x4000)) {
            fixedEnabled = 0;
            func_800A5800(id);
            _cadbfunc_entrypoint_29(4, &fixedEnabled);
            if (!fixedEnabled) {
                return 0;
            }
        }
        func_800A3B78(self, 6);
        _ncbafixpos_entrypoint_4(func_800A4CA8(self), id);
        func_800A3F14(self, 4);
        return 1;
    case 2:
        if (id != (*(Camera **)self->pad38)->id) {
            func_800A5800(id);
            _cadbfunc_entrypoint_0(position);
            _cadbfunc_entrypoint_2(rotation);
            func_800CA628(func_800A4C48(self), position, rotation);
            func_801108A0(func_800A4CA8(self));
            (*(Camera **)self->pad38)->id = id;
        }
        return 0;
    case 7:
        func_800A3B78(self, 0x12);
        _ncbaspiral_entrypoint_5(func_800A4CA8(self), id);
        func_800A3F14(self, 4);
        func_800A4190(self);
        return 1;
    }
    return 0;
}

s32 func_800A4878(PlayerState *arg0) {
    int bainput_func_80097B4C(PlayerState *);
    int bainput_should_rotate_camera_left(PlayerState *);
    int bainput_should_rotate_camera_right(PlayerState *);
    s32 func_8009CC68(PlayerState *);
    s32 func_800A4D40(void *);
    s32 func_800F65D0(BtIntPtr);
    s32 func_80110EFC();
    u8 *camera;

    camera = (u8 *)func_800A4CA8(arg0);
    if ((*(u8 **)((u8 *)arg0 + 0x38))[5] != 0) {
        return func_80110EFC(camera, 2);
    }
    if (func_800A4D40(arg0) == 0 || func_8009CC68(arg0) != 0 ||
        func_800F65D0(arg0->unk184) == 0 ||
        (*(u8 **)((u8 *)arg0 + 0x38))[0x3B] != 0) {
        return 0;
    }
    if (bainput_func_80097B4C(arg0) != 0) {
        return func_80110EFC(camera, 2);
    }
#ifdef BT_NATIVE
    {   // free camera setting: the stick turns the camera (1EE9AB0.c), C-Left/Right steps are off meanwhile
        s32 bt_camera_stick(void);
        BT_IDO_ONLY(if ((s8)bt_camera_stick() != 0) return 0;)
    }
#endif
    if (bainput_should_rotate_camera_left(arg0) != 0) {
        return func_80110EFC(camera, 0);
    }
    if (bainput_should_rotate_camera_right(arg0) != 0) {
        return func_80110EFC(camera, 1);
    }
    return 0;
}

s32 func_800A4978(PlayerState *arg0) {
    s32 func_800F40EC(PlayerState *);
    s32 state;
    u8 *data;

    if (func_800F40EC(arg0) != 2) {
        return 0;
    }
    switch (func_800A3274(arg0)) {
        case 0xB:
            data = (*(u8 **)((u8 *)arg0 + 0x38));
            state = 7;
            if (data[3] != 0) {
                data[3] = 4;
            }
            break;
        case 0xC:
            state = 8;
            break;
        default:
            state = 6;
            break;
    }
    func_800A3F14(arg0, state);
    func_800A4878(arg0);
    func_800A4190(arg0);
    return 1;
}

BT_IDO_ONLY(void func_800A4A14(BtIntPtr arg0)) BT_NATIVE_ONLY(void func_800A4A14(PlayerState *arg0)) { if (func_800A4338(BT_NATIVE_ONLY(arg0)) != 0) return; func_800A4190(arg0); func_800A4878(arg0); }

BT_IDO_ONLY(void func_800A4A4C(BtIntPtr arg0)) BT_NATIVE_ONLY(void func_800A4A4C(PlayerState *arg0))
{
    func_800A4190(BT_NATIVE_ONLY(arg0));
    func_800A4878(arg0);
}
void func_800A4A74(PlayerState *arg0) { if (func_800A4338(arg0) != 0) return; if (func_800A4978(arg0) != 0) return; func_800A4190(arg0); func_800A4878(arg0); func_800A3F14(arg0, 2); }

void func_800A4AD0(PlayerState *arg0) { if (_ncbaspline_entrypoint_8(func_800A4CA8(arg0))) func_800A3F14(arg0, 2); }

void func_800A4B08(PlayerState *arg0) {
    s32 _batimer_decrement(void *, s32);
    s32 func_800F65D0(BtIntPtr);
    s32 func_80090C34(PlayerState *);
    void func_80090C28(PlayerState *, s32);
    _batimer_decrement(arg0, 7);
    if (func_800F65D0(arg0->unk184)) {
        func_80090C34(arg0);
    }
    func_80090C28(arg0, 0);
    switch ((*(u8 **)((s8 *)arg0 + 0x38))[6]) {
        case 4:
            if (func_800A4338(arg0)) {
                return;
            }
            if ((*(u8 **)((s8 *)arg0 + 0x38))[0]) {
                func_800A3F14(arg0, 1);
                func_800A3B78(arg0, (*(u8 **)((s8 *)arg0 + 0x38))[0]);
            } else {
                func_800A3F14(arg0, 2);
            }
            break;
        case 1:
            func_800A4A14(arg0);
            break;
        case 3:
            func_800A4A4C(arg0);
            break;
        case 5:
            func_800A4AD0(arg0);
            break;
        case 0:
        case 9:
            break;
        default:
            if ((*(u8 **)((s8 *)arg0 + 0x38))[0]) {
                func_800A3F14(arg0, 1);
                func_800A3B78(arg0, (*(u8 **)((s8 *)arg0 + 0x38))[0]);
            } else {
                func_800A4A74(arg0);
            }
            break;
    }
    (*(u8 **)((s8 *)arg0 + 0x38))[0x3B] = 0;
}

/* extern */

f32 *func_800A4C48(PlayerState *arg0) {
    BtIntPtr func_800A93F8(s32 arg0);
    return func_800A93F8(arg0->unk184);
}

/* extern */

int func_800A4C68(void *arg0) {
    s32 func_800A940C(s32);
    return func_800A940C((((PlayerState *)arg0)->unk184));
}

/* extern */

s16 *func_800A4C88(void *arg0) {
    BtIntPtr func_800A93E4(BtIntPtr);
    return (s16 *)func_800A93E4((((PlayerState *)arg0)->unk184));
}

/* extern */

PlayerState *func_800A4CA8(PlayerState *arg0) {
    PlayerState *func_80110014(s16 *);
    PlayerState *var_v1;
    s16 *temp_v0;

    temp_v0 = func_800A4C88(arg0);
    if (temp_v0 != NULL) {
        var_v1 = func_80110014(temp_v0);
    } else {
        var_v1 = NULL;
    }
    return var_v1;
}

/* extern */

void func_800A4CE8(PlayerState *arg0, f32 *arg1) {
    void func_800CA7E4(f32 *, f32 *);
    func_800CA7E4(func_800A4C48(arg0), arg1);
}

/* extern */

void func_800A4D14(PlayerState *arg0, BtIntPtr arg1) {
    void func_800CA9D8(void *camera, f32 *rotation);
    func_800CA9D8(func_800A4C48(arg0), arg1);
}

s32 func_800A4D40(void *arg0) {
    s32 func_8010FAE4(s16 *);
    return func_8010FAE4(func_800A4C88(arg0)) == 2;
}

/* extern */

void func_800A4D6C(u8 *arg0, f32 arg1, f32 arg2) {
    s32 func_800A3BA8(BtIntPtr, s32);
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x38)))) + (0x2C))) = arg1;
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x38)))) + (0x30))) = arg2;
    func_800A3BA8((BtIntPtr)arg0, 1);
}

void func_800A4DA4(PlayerState *arg0, s32 arg1) {
    u8 temp_v0;

    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x38)))) + (0))) = (s8) arg1;
    temp_v0 = (*(u8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x38)))) + (6)));
    if ((temp_v0 != 4) && (temp_v0 != 5)) {
        func_800A3F14((BtIntPtr)arg0, 1);
        func_800A3B78(arg0, arg1);
    }
}

void func_800A4DFC(PlayerState *arg0, s32 arg1) {
    func_800A3F14((BtIntPtr)arg0, 3);
    func_800A3B78(arg0, arg1);
}

void func_800A4E30(PlayerState *arg0) {
    u8 temp_v0;

    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x38)))) + (0))) = 0;
    temp_v0 = (*(u8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x38)))) + (6)));
    if ((temp_v0 != 4) && (temp_v0 != 5)) {
        func_800A3F14((BtIntPtr)arg0, 2);
    }
}

void func_800A4E74(BtIntPtr arg0)
{
    func_800A3F14(arg0,0x5);
}

s32 func_800A4E94(void *arg0) { func_800A3F14((BtIntPtr)arg0, 9); BT_NATIVE_ONLY(return) func_80110BF0(func_800A4CA8(arg0)); }

s32 func_800A4EC8(void *arg0) { func_800A3F14((BtIntPtr)arg0, 2); BT_NATIVE_ONLY(return) func_80110C2C(func_800A4CA8(arg0)); }    typedef struct { u8 pad0[0x4]; u8 unk4; u8 pad5[0x3]; s32 unk8; } Obj1E7D460_func_800A4EFC_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

void func_800A4EFC(void *arg0, f32 arg1) {
    s32 func_80090E30(PlayerState *);
    f32 mlAbsF(f32);
    f32 sp34[3];
    s32 var_a3;
    f32 *var_v1;
    s32 var_v0;
    void *temp_v0;

    if (arg0 != NULL) {
        temp_v0 = (*(void **)((s8 *)(arg0) + (0x38)));
        if ((((Obj1E7D460_func_800A4EFC_temp_v0 *)temp_v0)->unk4) == 0) {
            sp34[0] = mlAbsF(arg1 - (f32) (((Obj1E7D460_func_800A4EFC_temp_v0 *)temp_v0)->unk8));
            sp34[1] = mlAbsF(arg1 - (f32) (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x38)))) + (0x14))));
            sp34[2] = mlAbsF(arg1 - (f32) (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x38)))) + (0x20))));
            var_a3 = 0;
            var_v0 = 1;
            var_v1 = &sp34[1];
            do {
                if (*var_v1 < sp34[var_a3]) {
                    var_a3 = var_v0;
                }
                var_v0 += 1;
                var_v1++;
            } while (var_v0 != 3);
            func_800A3D78(arg0, var_a3 + 1, func_80090E30(arg0));
        }
    }
}

/* extern */

BT_IDO_ONLY(void func_800A5004(void *arg0)) BT_NATIVE_ONLY(void func_800A5004(PlayerState *arg0)) {
    s32 func_800A4E94(void *);
    void * func_800CA334(void);
    if (BT_IDO_ONLY((*(s32 *)((s8 *)((((Obj1E7D460_arg0 *)arg0)->unk38_voidp)) + (0x3C))) == 0) BT_NATIVE_ONLY(FIRSTPERSON_CAMERA_HANDLE(arg0) == NULL)) {
        BT_IDO_ONLY((*(s32 *)((s8 *)((((Obj1E7D460_arg0 *)arg0)->unk38_voidp)) + (0x3C))) = func_800CA334();) BT_NATIVE_ONLY(FIRSTPERSON_CAMERA_HANDLE(arg0) = func_800CA334();)
        func_800A4E94(arg0);
    }
}

/* extern */

BT_IDO_ONLY(void func_800A5044(u8 *arg0)) BT_NATIVE_ONLY(void func_800A5044(PlayerState *arg0)) {
    s32 func_800A4EC8(void *);
    s32 func_800CA364(BtIntPtr);
    if (BT_IDO_ONLY((*(s32 *)((s8 *)((((Obj1E7D460_arg0 *)arg0)->unk38)) + (0x3C))) != 0) BT_NATIVE_ONLY(FIRSTPERSON_CAMERA_HANDLE_U8(arg0) != NULL)) {
        func_800A4EC8(arg0);
        func_800CA364(BT_IDO_ONLY((*(s32 *)((s8 *)((((Obj1E7D460_arg0 *)arg0)->unk38)) + (0x3C)))) BT_NATIVE_ONLY((BtIntPtr)FIRSTPERSON_CAMERA_HANDLE_U8(arg0)));
        BT_IDO_ONLY((*(s32 *)((s8 *)((((Obj1E7D460_arg0 *)arg0)->unk38)) + (0x3C))) = 0;) BT_NATIVE_ONLY(FIRSTPERSON_CAMERA_HANDLE_U8(arg0) = NULL;)
    }
}

BtIntPtr func_800A5090(void *arg0) {
    return BT_IDO_ONLY(*(s32 *)((u8 *)*(void **)((u8 *)arg0 + 56) + 60)) BT_NATIVE_ONLY(FIRSTPERSON_CAMERA_RESULT(arg0));
}

void func_800A509C(void *arg0) {
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x38)))) + (0x3B))) = 1;
}
