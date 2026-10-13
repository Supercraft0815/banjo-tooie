#include "common.h"

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
int func_80102EC8(ActorPathView *self, f32 (*positions)[3]) {
    s32 func_800CC338(f32 (*)[3], s32, s32);
    return self->index < 1 || func_800CC338(positions, self->index - 1, self->value - 1) != -1;
}

s32 func_80102F14(void *arg0) {
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
}

s32 func_80102F44(void *arg0) {
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
}

/* extern */

s32 func_80102F74(Unk80132ED0 *arg0, s32 arg1) {
    Actor* func_80100368(Unk80132ED0 *);
    s32 func_80102FA0(Actor *, s32);
    return func_80102FA0(func_80100368(arg0), arg1);
}

s32 func_80102FA0(Actor *arg0, s32 arg1) {
    s32 var_v0;
    s32 var_v1;

    if (arg1 & 0x80000000) {
        var_v0 = *(s32 *)((u8 *)arg0 + 0x3C);
    } else {
        var_v0 = *(s32 *)((u8 *)arg0 + 0x24);
    }
    if (var_v0 & 0x7FFFFFFF & arg1) {
        var_v1 = 1;
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

void func_80102FDC(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)arg0 + 56) = arg1;
}

void func_80102FE8(void *arg0, s32 arg1) {
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
}

/* extern */

void func_80103014(u8 *arg0) {
    s32 func_800EC124(void *, s32, void *, s32 *);
    func_800EC124(arg0 + 4, *(s32 *)arg0, arg0 + 0x44, (s32 *)arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDC7B0/func_80103040.s")

void func_80103110(void *arg0, s32 arg1) {
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
}
