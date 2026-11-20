#include "core2/actor_movement.h"
#include "core2/movement_collision.h"
#ifdef BT_NATIVE
#include BT_LP64_HEADER("native_world_grid.h")
#endif

s32 func_8010A980(Actor *arg0, f32 arg1[3], s32 arg2, s32 arg3) {
    void *func_800C6A7C(f32 *, f32 *, f32 *, u32);
    void func_800EE7F8(f32 *, f32 *);
    void func_8010A624(Actor *);
    u32 func_8010A654(Actor *, s32);
    u32 func_8010A698(Actor *);
    extern f32 D_80136F20[3];
    extern f32 D_80136F30[3];
    f32 sp3C[3];
    f32 sp30[3];
    s32 sp2C;
    void *sp28;

    sp2C = func_8010A698(arg0);
    func_8010A624(arg0);
    sp3C[0] = arg1[0];
    sp3C[1] = arg1[1] + 4.0f;
    sp3C[2] = arg1[2];
    sp30[0] = arg0->position[0];
    sp30[1] = arg0->position[1] + 4.0f;
    sp30[2] = arg0->position[2];
    sp28 = func_800C6A7C(sp3C, sp30, D_80136F30, arg0->unk14);
    func_800EE7F8(D_80136F20, sp30);
    func_8010A654(arg0, sp2C);
    return sp28 ? 1 : 0;
}

void func_8010AA54(s32 *arg0) {
    void func_800EE7F8();
    extern f32 D_80136F30[3];
    func_800EE7F8(arg0, &D_80136F30);
}

void func_8010AA78(s32 *arg0) {
    void func_800EE7F8();
    extern f32 D_80136F20[3];
    func_800EE7F8(arg0, &D_80136F20);
}

void func_8010AA9C(s32 *arg0) {
    void func_800EE7F8();
    extern f32 D_80136F40[3];
    func_800EE7F8(arg0, D_80136F40);
}

s32 func_8010AAC0(Actor *arg0, f32 *arg1, s32 arg2, s32 arg3) {
    void func_800D4584(void *, f32 *, f32 *, f32 *);
    f32 func_800EC708(Unk80132ED0 *);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EEAA4(f32 *, f32 *);
    void func_800EF410(f32 *, f32 *);
    void func_800EFB24(void *, void *, void *);
    f32 func_8010A40C(void *);
    void func_8010A624(Actor *);
    u32 func_8010A654(Actor *, s32);
    u32 func_8010A698(Actor *);

    extern f32 D_80136F30[3];
    MovementCollision state;
    f32 delta[3];
    s32 saved;
    s32 result;
    Actor **argAddress = (Actor **)&arg0;
    Actor *actor;
    f32 normal[3];
    s32 special;

    saved = func_8010A698(arg0);
    func_8010A624(arg0);
    state.radius = func_800EC708(((Actor *)arg0)->unk0);
    special = 0;
    if ((arg2 & 0xF000) == 0x1000 || (arg2 & 0xF000) == 0x3000 ||
        (arg2 & 0xF000) == 0x5000 || (arg2 & 0xF000) == 0x6000) {
        special = 1;
    }
    if (special) {
        state.radius *= 0.6f * func_8010A40C(arg0);
        if (state.radius * 1.25f < *(s16 *)&(actor = *argAddress)->unk0->unk20) {
            state.height = *(s16 *)&actor->unk0->unk20;
        } else {
            state.height = state.radius * 1.25f;
        }
    } else {
        state.radius *= 0.5f * func_8010A40C(arg0);
        if (state.radius * 1.25f < *(s16 *)&((Actor *)arg0)->unk0->unk20) {
            state.height = *(s16 *)&((Actor *)arg0)->unk0->unk20;
        } else {
            state.height = state.radius * 1.25f;
        }
    }
    actor = *argAddress;
    state.object = 0;
    state.onContact = NULL;
    state.resetContact = NULL;
    state.flags = actor->unk14;
    state.previous = 0;
    state.triangle = 0;
    state.contact = 0;
    state.blocked = 0;
    state.count = 0;
    state.flag = 0;
    func_800EFB24(delta, actor->position, (void *)arg1);
    func_800D4584(&state, (f32 *)arg1, actor->position, delta);
    result = state.count;
    if (state.count) {
        func_800EE7F8(D_80136F30, state.normal);
        if (!state.blocked) {
            func_800EF410(normal, delta);
            if (-0.9396926f < func_800EEAA4(state.normal, normal)) {
                result = 0;
            }
        }
    }
    func_8010A654(arg0, saved);
    return result ? 1 : 0;
}               typedef struct { u8 pad0[0x4]; f32 unk4; u8 pad8[0xC]; s32 unk14; u8 pad18[0x2C]; f32 unk44; f32 unk48; u8 pad4C[0x24]; u32 unk70; } Obj1EE4270_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

s32 func_8010ACE0(Actor *arg0, f32 *arg1, s32 arg2, s32 arg3) {
    s32 func_800CC6CC(s32, s32);
    s32 func_8010AAC0(Actor *, f32 *, s32, s32);
    u32 temp_v0;
    u32 temp_v1;

    temp_v0 = BT_DATA_FIELD(arg0->flags70, ((Obj1EE4270_arg0 *)arg0)->unk70);
    temp_v1 = temp_v0 >> 0x19;
    if ((temp_v1 != 0) && (func_800CC6CC(temp_v1 - 1, ((u32) (temp_v0 << 0x16) >> 0x1A) - 1) == 0)) {
        return 0;
    }
    return func_8010AAC0(arg0, arg1, arg2, arg3);
}

s32 func_8010AD4C(Actor *arg0, f32 arg1[3], s32 arg2, BT_NATIVE_ONLY(s32 flags) BT_IDO_ONLY(f32 arg3)) {
    s32 *func_800BF340(f32 *, f32 *, f32 *, s32, f32);
    f32 func_800EC708(Unk80132ED0 *);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_8010A40C(void *);

    extern f32 D_80136F20[3];
    extern f32 D_80136F30[3];
    BT_NATIVE_ONLY(f32 height;)
    f32 sp3C[1];
    s32 *sp38;
    f32 sp34;
    f32 temp_f2;

    sp34 = func_800EC708(*(Unk80132ED0 **)arg0);
    temp_f2 = func_8010A40C(arg0) * (sp34 * 0.666f);
    sp3C[0] = temp_f2;
    arg1[1] = arg1[1] + temp_f2;
    arg0->position[1] = arg0->position[1] + temp_f2;
    sp38 = func_800BF340(arg1, arg0->position, D_80136F30, arg0->unk14, temp_f2);
    func_800EE7F8(D_80136F20, arg0->position);
    BT_NATIVE_ONLY(height) BT_IDO_ONLY(arg3) = sp3C[0];
    arg1[1] = arg1[1] - BT_NATIVE_ONLY(height) BT_IDO_ONLY(arg3);
    arg0->position[1] = arg0->position[1] - BT_NATIVE_ONLY(height) BT_IDO_ONLY(arg3);
    if (sp38 != 0) {
        arg2 = 1;
    } else {
        arg2 = 0;
    }
    return (int)arg2;
}

/* extern */

s32 func_8010AE30(Actor *arg0, f32 arg1[3], s32 arg2, BT_NATIVE_ONLY(s32 flags) BT_IDO_ONLY(f32 arg3)) {
    s32 func_800CC6CC(s32, s32);
    s32 func_8010AD4C(Actor *, f32 *, s32, BT_NATIVE_ONLY(s32) BT_IDO_ONLY(f32));
    u32 temp_v0;
    u32 temp_v1;

    temp_v0 = BT_DATA_FIELD(arg0->flags70, ((Obj1EE4270_arg0 *)arg0)->unk70);
    temp_v1 = temp_v0 >> 0x19;
    if ((temp_v1 != 0) && (func_800CC6CC(temp_v1 - 1, ((u32) (temp_v0 << 0x16) >> 0x1A) - 1) == 0)) {
        return 0;
    }
    return func_8010AD4C(arg0, arg1, arg2, BT_NATIVE_ONLY(flags) BT_IDO_ONLY(arg3));
}

s32 func_8010AE9C(Actor *arg0, f32 arg1[3], s32 arg2, BT_NATIVE_ONLY(s32 flags) BT_IDO_ONLY(f32 arg3)) {
    void *func_800BF0E0(f32 *a,f32 *b,f32 radius,f32 *out,s32 flags,u32 mode);
    f32 func_800EC708(Unk80132ED0 *);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_8010A40C(void *);

    extern f32 D_80136F20[3];
    extern f32 D_80136F30[3];
    BT_NATIVE_ONLY(f32 height;)
    f32 sp3C[1];
    BtIntPtr sp38;
    f32 sp34;
    f32 temp_f2;

    sp34 = func_800EC708(*(Unk80132ED0 **)arg0);
    temp_f2 = func_8010A40C(arg0) * (sp34 * 0.666f);
    sp3C[0] = temp_f2;
    arg1[1] = arg1[1] + temp_f2;
    arg0->position[1] = arg0->position[1] + temp_f2;
    sp38 = func_800BF0E0(arg1, arg0->position, temp_f2, D_80136F30, 3, arg0->unk14);
    func_800EE7F8(D_80136F20, arg0->position);
    BT_NATIVE_ONLY(height) BT_IDO_ONLY(arg3) = sp3C[0];
    arg1[1] = arg1[1] - BT_NATIVE_ONLY(height) BT_IDO_ONLY(arg3);
    arg0->position[1] = arg0->position[1] - BT_NATIVE_ONLY(height) BT_IDO_ONLY(arg3);
    if (sp38 != 0) {
        arg2 = 1;
    } else {
        arg2 = 0;
    }
    return (int)arg2;
}

/* extern */

s32 func_8010AF8C(Actor *arg0, f32 *arg1, s32 arg2, BT_NATIVE_ONLY(s32 flags) BT_IDO_ONLY(f32 arg3)) {
    s32 func_800CC6CC(s32, s32);
    s32 func_8010AE9C(Actor *, f32 *, s32, BT_NATIVE_ONLY(s32) BT_IDO_ONLY(f32));
    u32 temp_v0;
    u32 temp_v1;

    temp_v0 = BT_DATA_FIELD(arg0->flags70, ((Obj1EE4270_arg0 *)arg0)->unk70);
    temp_v1 = temp_v0 >> 0x19;
    if ((temp_v1 != 0) && (func_800CC6CC(temp_v1 - 1, ((u32) (temp_v0 << 0x16) >> 0x1A) - 1) == 0)) {
        return 0;
    }
    return func_8010AE9C(arg0, arg1, arg2, BT_NATIVE_ONLY(flags) BT_IDO_ONLY(arg3));
}

/* extern */

s32 func_8010AFF8(Actor *arg0, f32 *arg1, s32 arg2, s32 arg3) {
    void func_800EF214(f32 *, f32, f32, f32);
    f32 func_8010C4AC(void *);
    func_800EF214(arg0->position, arg0->rotation[0], arg0->rotation[1], func_8010C4AC(arg0));
    return 0;
}

/* extern */

s32 func_8010B040(Actor *arg0, f32 *arg1, s32 arg2, s32 arg3) {
    void func_800EF1B8(f32 *, f32, f32);
    f32 func_8010C4AC(void *);
    func_800EF1B8(arg0->position, arg0->rotation[1], func_8010C4AC(arg0));
    return 0;
}

s32 func_8010B088(Actor *arg0, f32 *arg1, s32 arg2, s32 arg3) {
    void func_800EF1B8(f32 *, f32, f32);
    f32 func_800D8FF8(void);
    f32 func_8010C4AC(void *);
    f32 sp18[2];

    sp18[0] = func_8010C4AC(arg0);
    func_800EF1B8(arg0->position, arg0->rotation[1], sp18[0] * func_800D8FF8());
    return 0;
}

s32 func_8010B0E0(Actor *arg0, f32 *arg1, s32 arg2, s32 arg3) {
    void func_800EF214(f32 *, f32, f32, f32);
    f32 func_800D8FF8(void);
    f32 func_8010C4AC(void *);
    f32 sp18[2];

    sp18[0] = func_8010C4AC(arg0);
    func_800EF214(arg0->position, arg0->rotation[0], arg0->rotation[1], sp18[0] * func_800D8FF8());
    return 0;
}

s32 func_8010B13C(Actor *arg0, f32 *arg1, s32 arg2, s32 arg3) {
    void func_800EF214(f32 *, f32, f32, f32);
    f32 func_8010C4AC(void *);
    func_800EF214(arg0->position, -(arg0->rotation[0]), arg0->rotation[1], func_8010C4AC(arg0));
    return 0;
}

s32 func_8010B190(Actor *arg0, f32 *arg1, s32 arg2, s32 arg3) {
    void func_800EF214(f32 *, f32, f32, f32);
    f32 func_800D8FF8(void);
    f32 func_8010C4AC(void *);
    f32 sp18[2];

    sp18[0] = func_8010C4AC(arg0);
    func_800EF214(arg0->position, -arg0->rotation[0], arg0->rotation[1], sp18[0] * func_800D8FF8());
    return 0;
}

s32 func_8010B1F4(Actor *arg0, f32 *arg1, s32 arg2, s32 arg3) {
    void func_800EE7F8(f32 *, f32 *);
    s32 *func_800BEF00(f32 *, f32 *, f32 *, s32);
    f32 func_800D8FF8(void);
    f32 func_800F13F0(f32, f32);
    void func_801045AC(Actor *arg0, f32 *arg1, f32 *arg2, s32 arg3);
    s32 func_8010C3E8(Actor *);
    f32 func_8010C460(Actor *);
    extern f32 D_80136F40[3];
    f32 sp44[3];
    f32 sp38[3];
    f32 sp34;
    f32 sp30;
    s32 *sp2C;

    sp34 = func_8010C460(arg0);
    sp30 = func_800D8FF8();
    func_800EE7F8(sp44, arg0->position);
    sp44[1] += sp34;
    func_800EE7F8(sp38, arg0->position);
    sp38[1] += func_800F13F0(*(f32 *)&arg0->actorData[7] * sp30, -200.0f);
    sp2C = func_800BEF00(sp44, sp38, D_80136F40, arg0->unk14);
    if (sp2C != NULL) {
        *(f32 *)&arg0->actorData[7] = 0.0f;
        func_800EE7F8(arg0->position, sp38);
        if (BT_DATA_FIELD(arg0->expression_handle, ((s16 *)&arg0->pad8C)[1]) != 0) {
            func_801045AC(arg0, D_80136F40, sp38, sp2C[2]);
        }
        return 1;
    }
    *(f32 *)&arg0->actorData[7] -= 1200.0f * sp30;
    arg0->position[1] += *(f32 *)&arg0->actorData[7];
    if (func_8010C3E8(arg0) != 0) {
        return -1;
    }
    return 0;
}

s32 func_8010B330(Actor *arg0, f32 *arg1, s32 arg2, s32 arg3) {
    void *func_800C6A7C(f32 *, f32 *, f32 *, u32);
    void func_800EE7F8(f32 *, f32 *);
    void func_801045AC(Actor *arg0, f32 *arg1, f32 *arg2, s32 arg3);
    f32 func_8010C460(Actor *);
    extern f32 D_80136F40[3];
    f32 sp3C[3];
    f32 sp30[3];
    f32 sp2C;
    s32 *temp_v0;

    sp2C = func_8010C460(arg0);
    func_800EE7F8(sp3C, arg0->position);
    sp3C[1] += sp2C;
    func_800EE7F8(sp30, arg0->position);
    sp30[1] -= 100.0f;
    temp_v0 = func_800C6A7C(sp3C, sp30, D_80136F40, arg0->unk14);
    if (temp_v0 != NULL) {
        *(f32 *)&arg0->actorData[7] = 0.0f;
        func_800EE7F8(arg0->position, sp30);
        if (BT_DATA_FIELD(arg0->expression_handle, ((s16 *)&arg0->pad8C)[1]) != 0) {
            func_801045AC(arg0, D_80136F40, sp30, temp_v0[2]);
        }
        return 1;
    }
    return 0;
}

s32 func_8010B410(Actor *arg0, f32 *arg1, s32 arg2, s32 arg3) {
    s32 *func_800BEF00(f32[3], f32[3], f32[3], s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_801045AC(Actor *arg0, f32 *arg1, f32 *arg2, s32 arg3);
    s32 func_8010C3E8(Actor *);
    f32 func_8010C460(Actor *);
    extern f32 D_80136F40[3];
    f32 sp3C[3];
    f32 sp30[3];
    f32 sp2C;
    s32 *temp_v0;

    sp2C = func_8010C460(arg0);
    func_800EE7F8(sp3C, arg0->position);
    sp3C[1] += sp2C;
    func_800EE7F8(sp30, arg0->position);
    sp30[1] -= 200.0f;
    temp_v0 = func_800BEF00(sp3C, sp30, D_80136F40, arg0->unk14);
    if (temp_v0 != NULL) {
        if (BT_DATA_FIELD(arg0->expression_handle, ((s16 *)&arg0->pad8C)[1]) != 0) {
            func_801045AC(arg0, D_80136F40, sp30, temp_v0[2]);
        }
        if (arg0->position[1] < sp30[1]) {
            arg0->position[1] = sp30[1] + 1.0f;
            return 1;
        }
    }
    if (func_8010C3E8(arg0) != 0) {
        return -1;
    }
    return 0;
}

s32 func_8010B514(Actor *arg0, f32 *arg1, s32 arg2, s32 arg3) {
    s32 *func_800BEF00(f32 *, f32 *, f32 *, s32);
    f32 func_800D8FF8(void);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800F13F0(f32, f32);
    void func_801045AC(Actor *arg0, f32 *arg1, f32 *arg2, s32 arg3);
    s32 func_8010C3E8(Actor *);
    f32 func_8010C460(Actor *);
    extern f32 D_80136F40[3];
    f32 sp44[3];
    f32 sp38[3];
    f32 sp34;
    f32 sp30;
    s32 *temp_v0;

    sp34 = func_8010C460(arg0);
    sp30 = func_800D8FF8();
    func_800EE7F8(sp44, arg0->position);
    sp44[1] += sp34;
    func_800EE7F8(sp38, arg0->position);
    sp38[1] += func_800F13F0(*(f32 *)&arg0->actorData[7] * sp30, -200.0f);
    *(f32 *)&arg0->actorData[7] -= 300.0f * sp30;
    temp_v0 = func_800BEF00(sp44, sp38, D_80136F40, arg0->unk14);
    if (temp_v0 != NULL) {
        arg0->position[1] += *(f32 *)&arg0->actorData[7];
        if (func_8010C3E8(arg0) != 0) {
            return -1;
        }
        *(f32 *)&arg0->actorData[7] = 0.0f;
        if (arg0->position[1] < sp38[1]) {
            *(f32 *)&arg0->actorData[7] = -50.0f;
            arg0->position[1] = sp38[1];
        }
        if (BT_DATA_FIELD(arg0->expression_handle, ((s16 *)&arg0->pad8C)[1]) != 0) {
            func_801045AC(arg0, D_80136F40, sp38, temp_v0[2]);
        }
        return 1;
    }
    arg0->position[1] += *(f32 *)&arg0->actorData[7];
    if (func_8010C3E8(arg0) != 0) {
        return -1;
    }
    return 0;
}

int func_8010B69C(Actor *arg0, f32 arg1[3], s32 arg2, s32 arg3) {
    f32 func_800BED50(f32 *, Actor *);
    f32 y = func_800BED50(arg0->position, arg0) - 130.0f;
    arg0->position[1] = (arg0->position[1] < y) ? arg0->position[1] : y;
    return y == arg0->position[1];
}

s32 func_8010B71C(Actor *arg0, f32 *arg1, s32 arg2, s32 arg3) {
    s32 *func_800BEF00(f32[3], f32[3], f32[3], s32);
    f32 func_800D8FF8(void);
    void func_801045AC(Actor *arg0, f32 *arg1, f32 *arg2, s32 arg3);
    f32 func_8010C460(Actor *);
    extern f32 D_80136F40[3];
    f32 sp34[3];
    f32 sp30;
    f32 sp2C;
    s32 *temp_v0;

    sp30 = func_8010C460(arg0);
    sp2C = func_800D8FF8();
    sp34[0] = arg0->position[0];
    sp34[1] = arg0->position[1] + sp30;
    sp34[2] = arg0->position[2];
    arg0->position[1] += *(f32 *)&arg0->actorData[5] * sp2C;
    temp_v0 = func_800BEF00(sp34, arg0->position, D_80136F40, arg0->unk14);
    if (temp_v0 != NULL) {
        *(f32 *)&arg0->actorData[5] = 0.0f;
        *(f32 *)&arg0->actorData[7] = 0.0f;
        if (BT_DATA_FIELD(arg0->expression_handle, ((s16 *)&arg0->pad8C)[1]) != 0) {
            func_801045AC(arg0, D_80136F40, arg0->position, temp_v0[2]);
        }
        return 1;
    }
    *(f32 *)&arg0->actorData[5] -= *(f32 *)&arg0->actorData[7] * sp2C;
    return 0;
}

typedef struct {
    s32 marker;
    f32 position[3];
    u8 pad10[0x60];
    BT_BITFIELD_ORDER(u32 path_index : 7, u32 pad70_0 : 4);
    BT_BITFIELD_ORDER(u32 pad70_10 : 15, u32 path_node : 6);
    BT_BITFIELD_ORDER(u32 path_node : 6, u32 pad70_10 : 15);
    BT_BITFIELD_ORDER(u32 pad70_0 : 4, u32 path_index : 7);
} ActorPath;

#ifdef BT_NATIVE
s32 func_8010B800(Actor *actor, f32 saved[3], s32 command, s32 flags) {
    s32 func_800CC338(f32 *, s32, s32);
    void func_800EE7F8(f32 *, f32 *);
    u32 path = actor->flags70 >> 25;
    if (path != 0) {
        s32 node = (actor->flags70 >> 4) & 0x3F;
        s32 next = func_800CC338(actor->position, path - 1, node - 1);
        if (next == -1) {
            func_800EE7F8(actor->position, saved);
            return 1;
        }
        actor->flags70 = (actor->flags70 & ~(0x3Fu << 4)) | (((u32)(next + 1) & 0x3F) << 4);
    }
    return 0;
}
#else
s32 func_8010B800(ActorPath *arg0, f32 arg1[3], s32 arg2, s32 arg3) {
    s32 func_800CC338(f32 *, s32, s32);
    void func_800EE7F8(f32 *, f32 *);
    s32 result;

    if (arg0->path_index != 0) {
        result = func_800CC338(arg0->position, arg0->path_index - 1, arg0->path_node - 1);
        if (result == -1) {
            func_800EE7F8(arg0->position, arg1);
            return 1;
        }
        arg0->path_node = result + 1;
        return 0;
    }
    return 0;
}
#endif

s32 func_8010B8A4(Actor *arg0, f32 *arg1, s32 arg2, s32 arg3) {
    f32 func_800D8FF8(void);
    void func_800EFA20(void *, void *, f32);
    void func_800EF04C(f32 *, f32 *);
    f32 delta;
    f32 scaled[3];

    delta = func_800D8FF8();
    *(f32 *)&arg0->actorData[5] += *(f32 *)&arg0->actorData[7] * delta;
    func_800EFA20(scaled, &arg0->actorData[4], delta);
    func_800EF04C(arg0->position, scaled);
    return 0;
}

/* extern */

s32 func_8010B910(Actor *arg0, f32 *arg1, s32 arg2, s32 arg3) {
    void func_800EF04C(f32 *, f32 *);
    func_800EF04C(arg0->position, (f32 *)&arg0->actorData[4]);
    return 0;
}

/* extern */

s32 func_8010B94C(Actor *arg0, f32 *arg1, s32 arg2, s32 arg3) {
    f32 func_800D8FF8();
    void func_800EF174(f32 dst[3], f32 src[3], f32 scale);
    func_800EF174(arg0->position, (f32 *)&arg0->actorData[4], func_800D8FF8());
    return 0;
}

s32 func_8010B990(Actor *arg0, s32 arg1) {
    void func_800EE7F8(f32 *, f32 *);
    void func_80104580(BT_NATIVE_ONLY(Actor *));

    s32 result;
    s32 i;
    s32 flags;
    f32 saved[3];
    s32 nibble;

    flags = 0;
    func_80104580(BT_NATIVE_ONLY(arg0));
    func_800EE7F8(saved, arg0->position);
    for (i = 0; i != 6; i++) {
        nibble = ((u32)arg1 >> (i << 2)) & 0xF;
        if (nibble != 0) {
            result = D_80124714[i][nibble](arg0, saved, arg1, flags);
            if (result == -1) {
                return 0;
            }
            if (result != 0) {
                flags |= result << i;
            }
        }
    }
    return flags;
}

s32 func_8010B990(Actor *, s32);

s32 func_8010BA80(Actor *volatile arg0, volatile s32 arg1, s32 arg2) { 
    void func_800EE7F8(f32 *, f32 *);
    s32 result;
    f32 saved[3];
    f32 *position;
    s32 *arg2_ptr = &arg2;

    position = arg0->position;
    func_800EE7F8(saved, position);
    result = func_8010B990(arg0, arg1);
    if (result & arg2) {
        func_800EE7F8(position, saved);
    }
    return result;
}

s32 func_8010BAEC(Actor *volatile arg0, volatile s32 arg1, s32 arg2) { 
    void func_800EE7F8(f32 *, f32 *);
    s32 result;
    f32 saved[3];
    f32 *position;
    s32 *arg2_ptr = &arg2;
    position = arg0->position;
    func_800EE7F8(saved, position);
    result = func_8010B990(arg0, arg1);
    if ((result & *arg2_ptr) != *arg2_ptr) {
        func_800EE7F8(position, saved);
    }
    return result;
}

s32 func_8010BB5C(Actor *arg0, BtIntPtr arg1, f32 *arg2, f32 arg3, f32 arg4, f32 arg5) {
    f32 func_800D8FF8(void);
    f32 func_800DC0C0(void);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF368(f32 *, f32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    f32 func_800F13F0(f32, f32);
    f32 sqrtf(f32);
    f32 delta[3];
    f32 pad[2];
    f32 amount;
    f32 distance;

    if (((f32 *)arg1)[1] < arg2[1] + arg4) {
        return 0;
    }
    if (arg2[1] + arg3 < ((f32 *)arg1)[1]) {
        return 0;
    }
    func_800EFA4C(delta, ((f32 *)arg1)[0] - arg2[0], 0.0f, ((f32 *)arg1)[2] - arg2[2]);
    distance = delta[0] * delta[0] + delta[1] * delta[1] + delta[2] * delta[2];
    if (arg5 * arg5 < distance) {
        return 0;
    }
    distance = sqrtf(distance);
    amount = func_800F13F0(func_800D8FF8() * 400.0f, arg5 - distance);
    if (distance == 0.0f) {
        distance = func_800DC0C0();
        func_800EFA4C(delta, distance, 0.0f, func_800DC0C0());
    }
    func_800EF368(delta, amount);
    func_800EF04C((f32 *)arg1, delta);
    return 1;
}

s32 func_8010BCC8(Actor *arg0, BtIntPtr arg1, Actor *arg2) {
    void func_800EE7F8(f32 *, f32 *);
    f32 func_8010A40C(void *);
    s32 func_8010BB5C(Actor *, BtIntPtr, f32 *, f32, f32, f32);
    f32 position[3];
    f32 height;
    f32 scale;

    if (BT_DATA_FIELD((u16)arg2->horizontal_radius, ((u16 *)&arg2->pad60)[1]) == 0) {
        return 0;
    }
    func_800EE7F8(position, arg2->position);
    position[1] += arg2->scale * (f32)BT_DATA_FIELD(arg0->model_y_min, ((s16 *)&arg0->pad88)[0]);
    height = (f32)(BT_DATA_FIELD(arg0->model_y_max, ((s16 *)&arg0->pad88)[1]) - BT_DATA_FIELD(arg0->model_y_min, ((s16 *)&arg0->pad88)[0])) * arg2->scale;
    scale = func_8010A40C(arg0);
    scale *= (f32)BT_DATA_FIELD((u16)arg2->horizontal_radius, ((u16 *)&arg2->pad60)[1]) * arg2->scale;
    return func_8010BB5C(arg0, arg1, position, height, -30.0f,
                       scale);
}

/* extern */

s32 func_8010BDB0(Actor *actor, f32 *arg1, s32 arg2, s32 arg3) {
#if defined(BT_NATIVE) && !defined(BT_ILP32)
    typedef NativeMarkerProp Entry;
    typedef NativeWorldCell *Cell;
#else
    typedef s32 Cell;
    typedef struct {
        u8 pad[0x70];
        BT_BITFIELD_ORDER(u32 : 15, u32  : 16);
        u32 collidable : 1;
        BT_BITFIELD_ORDER(u32 : 16, u32  : 15);
        BT_BITFIELD_ORDER(u32 : 7, char : 0);
        BT_BITFIELD_ORDER(u32 burning : 1, u32  : 24);
        BT_BITFIELD_ORDER(u32 : 24, u32 burning : 1; u32  : 7);
    } CollisionFlags;
    typedef struct {
        Unk80132ED0 *marker;
        s32 unused;
        u32 flags;
    } Entry;
    void _chflamer_entrypoint_1(void *, void *);
    s32 *func_800BE3F8(u8 *);
    BtIntPtr func_800E9E88(BtIntPtr);
    BtUIntPtr func_800E9EB4(s16 *);
#endif
    void _chflamer_entrypoint_1(void *, void *);
    s32 func_80102F74(void *, s32);
    Actor *func_80106790(Unk80132ED0 *);
    Actor *arg0;
    Actor *other;
    Unk80132ED0 *marker;
    Entry *entry;
    Entry *end;
    Cell *list;
    f32 *position;

    arg0 = actor;
    position = arg0->position;
    list = func_800BE3F8((void *)position);
    while (*list != 0) {
        entry = (Entry *)func_800E9E88(*list);
        end = (Entry *)func_800E9EB4((void *)*list);
        for (; entry < end; entry++) {
            if (!(entry->flags & 1)) {
                continue;
            }
            marker = entry->marker;
            if (!(BT_DATA_FIELD(marker->unk18 >> 16, ((u16 *)&marker->unk18)[0]) & 1) || marker == arg0->unk0) {
                continue;
            }
            other = func_80106790(marker);
            if (!BT_DATA_FIELD((other->flags70 >> 16) & 1u, ((CollisionFlags *)other)->collidable) || !func_8010BCC8(arg0, (BtIntPtr)position, other)) {
                continue;
            }
            if (BT_DATA_FIELD((other->flags74 >> 24) & 1u, ((CollisionFlags *)other)->burning) && !BT_DATA_FIELD((arg0->flags74 >> 24) & 1u, ((CollisionFlags *)arg0)->burning) && func_80102F74(arg0, 0x80020000)) {
                _chflamer_entrypoint_1(arg0, marker);
            }
            if (!BT_DATA_FIELD((other->flags74 >> 24) & 1u, ((CollisionFlags *)other)->burning) && BT_DATA_FIELD((arg0->flags74 >> 24) & 1u, ((CollisionFlags *)arg0)->burning) && func_80102F74(other, 0x80020000)) {
                _chflamer_entrypoint_1(other, arg0->unk0);
            }
            return 1;
        }
        list++;
    }
    return 0;
}

/* extern */

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_8010BF4C(Actor *arg0, BtIntPtr arg1, f32 arg2, s32 arg3, s32 arg4) { s32 func_80102844(Actor *arg0, f32 arg1, s32 arg2, f32 *arg3); *(f32 *)&arg0->actorData[3] = arg2; func_80102844(arg0, (f32) arg3, -1, arg1); BT_NATIVE_ONLY(return) func_8010B990(arg0, arg4); }

s32 func_8010BFA4(f32 *arg0, f32 *arg1, f32 *arg2, f32 arg3) {
    f32 func_800136E4(f32);
    f32 func_800138D0(f32);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EEF94(f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    void func_800EFB24(void *, void *, void *);
    f32 func_800F1DCC(f32, f32);
    f32 func_800F1DF4(f32 *, f32 *);
    int func_800F1EA4(f32 *, f32 *);
    f32 temp_f20;
    f32 var_f0;
    f32 sp44;
    f32 sp40;
    f32 sp34[3];
    f32 sp30;
    f32 pad;
    f32 sp28;

    func_800EFB24(sp34, arg0, arg1);
    if (func_800F1EA4(sp34, &sp40) == 0) {
        func_800EE7F8(arg0, arg1);
        return 0;
    }
    sp30 = arg1[1];
    temp_f20 = func_800F1DF4(arg1, arg2);
    sp44 = func_800F1DCC(sp40, temp_f20);
    func_800EE7F8(arg0, arg2);
    func_800EF1B8(arg0, temp_f20 + 180.0f, arg3 + 2.0f);
    if (sp44 > 0.0f) {
        var_f0 = 90.0f;
    } else {
        var_f0 = -90.0f;
    }
    temp_f20 = func_800136E4(temp_f20 + var_f0);
    sp28 = func_800EEF94(sp34);
    var_f0 = func_800F1DCC(sp40, temp_f20);
    var_f0 = func_800138D0(var_f0);
    func_800EF1B8(arg0, temp_f20, var_f0 * sp28);
    arg0[1] = sp30;
    return 1;
}

s32 func_8010C100(Actor *arg0, f32 *arg1, s32 arg2, s32 arg3) {
#if defined(BT_NATIVE) && !defined(BT_ILP32)
    typedef NativeMarkerProp Entry;
    typedef NativeWorldCell *Cell;
#else
    typedef s32 Cell;
    typedef struct {
        u8 pad[0x70];
        BT_BITFIELD_ORDER(u32 : 15, u32  : 16);
        u32 collidable : 1;
        BT_BITFIELD_ORDER(u32 : 16, u32  : 15);
        BT_BITFIELD_ORDER(u32 : 7, char : 0);
        BT_BITFIELD_ORDER(u32 burning : 1, u32  : 24);
        BT_BITFIELD_ORDER(u32 : 24, u32 burning : 1; u32  : 7);
    } CollisionFlags;
    typedef struct {
        Unk80132ED0 *marker;
        s32 unused;
        u32 flags;
    } Entry;
    void _chflamer_entrypoint_1(void *, void *);
    s32 *func_800BE3F8(u8 *);
    BtIntPtr func_800E9E88(BtIntPtr);
    BtUIntPtr func_800E9EB4(s16 *);
#endif
    void _chflamer_entrypoint_1(void *, void *);
    s32 func_80102F74(void *, s32);
    f32 func_80103F38(Actor *, f32 *);
    Actor *func_80106790(Unk80132ED0 *);
    f32 func_8010A40C(void *);
    s32 func_8010C2D8(Actor *, f32 *, f32, Actor *);

    f32 position[3];
    Actor *other;
    Unk80132ED0 *marker;
    Entry *entry;
    Entry *end;
    Cell *list;
    f32 radius;
    f32 scale;

    scale = func_80103F38(arg0, position);
    radius = func_8010A40C(arg0) * (0.7f * scale);
    list = func_800BE3F8((void *)arg0->position);
    while (*list != 0) {
        entry = (Entry *)func_800E9E88(*list);
        end = (Entry *)func_800E9EB4((void *)*list);
        for (; entry < end; entry++) {
            if (!(entry->flags & 1)) {
                continue;
            }
            marker = entry->marker;
            if (!(BT_DATA_FIELD(marker->unk18 >> 16, ((u16 *)&marker->unk18)[0]) & 1) || marker == arg0->unk0) {
                continue;
            }
            other = func_80106790(marker);
            if (!BT_DATA_FIELD((other->flags70 >> 16) & 1u, ((CollisionFlags *)other)->collidable) || !func_8010C2D8(arg0, position, radius, other)) {
                continue;
            }
            if (BT_DATA_FIELD((other->flags74 >> 24) & 1u, ((CollisionFlags *)other)->burning) && !BT_DATA_FIELD((arg0->flags74 >> 24) & 1u, ((CollisionFlags *)arg0)->burning) && func_80102F74(arg0, 0x80020000)) {
                _chflamer_entrypoint_1(arg0, marker);
            }
            if (!BT_DATA_FIELD((other->flags74 >> 24) & 1u, ((CollisionFlags *)other)->burning) && BT_DATA_FIELD((arg0->flags74 >> 24) & 1u, ((CollisionFlags *)arg0)->burning) && func_80102F74(other, 0x80020000)) {
                _chflamer_entrypoint_1(other, arg0->unk0);
            }
            return 1;
        }
        list++;
    }
    return 0;
}

s32 func_8010C2D8(Actor *arg0, f32 *arg1, f32 arg2, Actor *arg3) {
    f32 func_800EEFD4(f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF368(f32 *, f32);
    void func_800EFB24(void *, void *, void *);
    f32 func_80103F38(Actor *, f32 *);
    f32 func_8010A40C(void *);
    f32 sqrtf(f32);
    f32 sp34[3];
    f32 sp28[3];
    f32 sp24;
    f32 temp_f0;

    sp24 = func_80103F38(arg3, sp34) * func_8010A40C(arg3);
    func_800EFB24(sp28, arg1, sp34);
    temp_f0 = func_800EEFD4(sp28);
    if (temp_f0 < (sp24 + arg2) * (sp24 + arg2)) {
        func_800EF368(sp28, ((sp24 + arg2) + 4.0f) - sqrtf(temp_f0));
        func_800EF04C(arg0->position, sp28);
        return 1;
    }
    return 0;
}

s32 func_8010C3A8(Actor *arg0, u32 arg1, f32 arg2) {
    f32 sp18[2];
    f32 temp_f0;
    s32 result;

    temp_f0 = *(f32 *)&arg0->actorData[3];
    sp18[0] = temp_f0;
    *(f32 *)&arg0->actorData[3] = temp_f0 * arg2;
    result = func_8010B990(arg0, arg1);
    *(f32 *)&arg0->actorData[3] = sp18[0];
    return result;
}

/* extern */

s32 func_8010C3E8(Actor *arg0) {
    f32 func_800BECCC(void);
    void func_800FFAB0(Actor *);
    s32 func_8010108C(Actor *, s32, BtIntPtr);
    f32 temp_f12;
    s32 var_v0;

    temp_f12 = func_800BECCC() - 1000.0f;
    var_v0 = 0;
    if ((arg0->position[1]) < temp_f12) {
        (arg0->position[1]) = temp_f12;
        if (func_8010108C(arg0, 0x4D, 1) > 0) {
            return 0;
        }
        func_800FFAB0(arg0);
        var_v0 = 1;
        /* Duplicate return node #4. Try simplifying control flow for better match */
        return var_v0;
    }
    return var_v0;
}

f32 func_8010C460(Actor *arg0) {
    f32 func_80103F38(Actor *, f32 *);
    f32 value;

    value = func_80103F38(arg0, NULL) * 0.666f;
    if (value < 60.0f) {
        return 60.0f;
    }
    return value;
}






/* extern */

f32 func_8010C4AC(void *arg0) {
    s32 func_800D3E40(s32);
    if (func_800D3E40(8) != 0) {
        return (*(f32 *)&((Actor *)arg0)->actorData[3]) * 1.5f;
    }
    return (*(f32 *)&((Actor *)arg0)->actorData[3]);
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
f32 D_80136F20 [ 3 ] BT_DATA(4, bss_core2bss2_2_music_tail, 0x1500);
f32 D_80136F30 [ 3 ] BT_DATA(4, bss_core2bss2_2_music_tail, 0x1510);
f32 D_80136F40[3] BT_DATA(4, bss_core2bss2_2_music_tail, 0x1520);
#endif
