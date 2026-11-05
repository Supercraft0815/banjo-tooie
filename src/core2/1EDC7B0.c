#include "common.h"
#ifdef BT_NATIVE
#include "native_actor.h"
#define ACTOR_SHADOW_SCALE(data) (((ActorData *)(data))->shadow_scale)
#else
#define ACTOR_SHADOW_SCALE(data) ((data)->scale)
#endif

typedef struct {
    u8 pad0[0x70];
    u32 index : 7;
    u32 reserved : 15;
    u32 value : 6;
    u32 flags : 4;
} ActorPathView;

void func_80102EC0(s32 arg0) 
{
}
#ifdef BT_NATIVE
int func_80102EC8(Actor *self, f32 (*positions)[3])
#else
int func_80102EC8(ActorPathView *self, f32 (*positions)[3])
#endif
{
    s32 func_800CC338(f32 (*)[3], s32, s32);
#ifdef BT_NATIVE
    return self->unk70_25 < 1 || func_800CC338(positions, self->unk70_25 - 1, ((self->pad70_1 >> 3) & 63) - 1) != -1;
#else
    return self->index < 1 || func_800CC338(positions, self->index - 1, self->value - 1) != -1;
#endif
}

s32 func_80102F14(void *arg0) {
#ifdef BT_NATIVE
    Actor *actor = arg0;
    if (actor->pad74_18 & 1) return 1;
    actor->pad74_18 |= 1;
    return 0;
#else
    struct Flags {
        u8 pad[0x74];
        u32 : 13;
        u32 flag : 1;
        u32 : 18;
    };
    struct Flags *flags = arg0;

    if (flags->flag) {
        return 1;
    }
    flags->flag = 1;
    return 0;
#endif
}

s32 func_80102F44(void *arg0) {
#ifdef BT_NATIVE
    Actor *actor = arg0;
    if (actor->unk79_2) return 1;
    actor->unk79_2 = 1;
    return 0;
#else
    struct Flags {
        u8 pad[0x78];
        u32 : 13;
        u32 flag : 1;
        u32 : 18;
    };
    struct Flags *flags = arg0;
    if (flags->flag) {
        return 1;
    }
    flags->flag = 1;
    return 0;
#endif
}

/* extern */

s32 func_80102F74(void *arg0, s32 arg1) {
    void *func_80100368(void *);
#ifndef BT_NATIVE
    s32 func_80102FA0(Actor *, s32);
#endif
    return func_80102FA0(func_80100368(arg0), arg1);
}

#ifdef BT_NATIVE
s32 func_80102FA0(ActorData *arg0, s32 arg1)
#else
s32 func_80102FA0(Actor *arg0, s32 arg1)
#endif
{
    s32 var_v0;
    s32 var_v1;

    if (arg1 & 0x80000000) {
#ifdef BT_NATIVE
        var_v0 = ((u32)(u16)arg0->unk3C << 16) | (u16)arg0->unk3E;
#else
        var_v0 = *(s32 *)((u8 *)arg0 + 0x3C);
#endif
    } else {
#ifdef BT_NATIVE
        var_v0 = ((u32)(u16)arg0->unk24 << 16) | (u16)arg0->unk26;
#else
        var_v0 = *(s32 *)((u8 *)arg0 + 0x24);
#endif
    }
    if (var_v0 & 0x7FFFFFFF & arg1) {
        var_v1 = 1;
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

void func_80102FDC(void *arg0, f32 arg1) {
#ifdef BT_NATIVE
    ((Actor *)arg0)->scale = arg1;
#else
    *(f32 *)((u8 *)arg0 + 56) = arg1;
#endif
}

void func_80102FE8(void *arg0, s32 arg1) {
#ifdef BT_NATIVE
    Actor *actor = arg0;
    actor->pad74_0 = (actor->pad74_0 & ~32u) | (arg1 != 0 ? 32 : 0);
#else
    struct Flags {
        u8 pad[0x77];
        u8 upper : 2;
        u8 flag : 1;
        u8 lower : 5;
    };
    if (arg1 != 0) {
        ((struct Flags *)arg0)->flag = 1;
    } else {
        ((struct Flags *)arg0)->flag = 0;
    }
#endif
}

/* extern */

void func_80103014(u8 *arg0) {
#ifdef BT_NATIVE
    void func_800EC124(f32 *, void *, f32 *);
    Actor *actor = (Actor *)arg0;
    func_800EC124(actor->position, actor->unk0, actor->rotation);
#else
    s32 func_800EC124(void *, s32, void *, s32 *);
    func_800EC124(arg0 + 4, *(s32 *)arg0, arg0 + 0x44, (s32 *)arg0);
#endif
}

void func_80103040(Actor *arg0) {
    struct ShadowFlags {
        u8 pad0[0x74];
        u32 : 11;
        u32 enabled : 1;
        u32 : 20;
    };
    typedef struct {
        u8 pad0[0x1C];
        f32 scale;
    } ActorCallbacks;
    void *func_80100368(void *);
    Actor *func_80106790(Unk80132ED0 *);
    s32 _chbadshad_entrypoint_1(Actor *, f32 *, f32);
    Actor *parent;
    ActorCallbacks *callbacks;
#ifdef BT_NATIVE
    Unk80132ED0 *marker;
#else
    s32 marker;
#endif

#ifdef BT_NATIVE
    if (arg0->pad74_18 & 4) {
#else
    if (((struct ShadowFlags *)arg0)->enabled) {
#endif
        if (arg0->unk7C_12) {
            callbacks = func_80100368(arg0);
            _chbadshad_entrypoint_1(arg0, arg0->position, arg0->scale * ACTOR_SHADOW_SCALE(callbacks));
            return;
        }
#ifdef BT_NATIVE
        marker = arg0->parent_marker;
        parent = marker ? func_80106790(marker) : NULL;
        if (parent && (parent->unk7C_12 || !parent->unk64_16)) {
#else
        marker = arg0->pad40;
        if (marker != 0 && ((parent = func_80106790(marker), parent->unk7C_12) || !parent->unk64_16)) {
#endif
            callbacks = func_80100368(arg0);
            _chbadshad_entrypoint_1(arg0, arg0->position, arg0->scale * ACTOR_SHADOW_SCALE(callbacks));
        }
    }
}

void func_80103110(void *arg0, s32 arg1) {
#ifdef BT_NATIVE
    Actor *actor = arg0;
    actor->pad7C_13 = (actor->pad7C_13 & ~2u) | (arg1 != 0 ? 2 : 0);
#else
    struct Flags {
        u8 padding[0x7E];
        u8 unused : 1;
        u8 flag : 1;
        u8 rest : 6;
    };
    if (arg1 != 0) {
        ((struct Flags *)arg0)->flag = 1;
    } else {
        ((struct Flags *)arg0)->flag = 0;
    }
#endif
}
