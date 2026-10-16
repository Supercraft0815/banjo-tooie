#include "core2/1EDB4D0.h"

struct anctrl_s;
struct anctrl_s *func_80104248(void *);

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDB4D0/func_80101BE0.s")

/* extern */

void func_80101CDC(Actor *arg0, f32 arg1) {
    s32 anctrl_setDuration(struct anctrl_s *, f32);
    struct anctrl_s *temp_v0;

    temp_v0 = func_80104248(arg0);
    if (temp_v0 != 0) {
        anctrl_setDuration(temp_v0, arg1);
    }
}

/* extern */

f32 func_80101D0C(Actor *arg0) {
    f32 func_8008B2AC(struct anctrl_s *);
    struct anctrl_s *temp_v0;

    temp_v0 = func_80104248(arg0);
    if (temp_v0 != 0) {
        return func_8008B2AC(temp_v0);
    }
    return 0.0f;
}

/* extern */

void func_80101D4C(Actor *arg0) {
    s32 anctrl_setPlaybackType(struct anctrl_s *, s32);
    struct anctrl_s *temp_v0;

    temp_v0 = func_80104248(arg0);
    if (temp_v0 != 0) {
        anctrl_setPlaybackType(temp_v0, 1);
    }
}

/* extern */

void func_80101D7C(Actor *arg0) {
    s32 anctrl_setPlaybackType(struct anctrl_s *, s32);
    struct anctrl_s *temp_v0;

    temp_v0 = func_80104248(arg0);
    if (temp_v0 != 0) {
        anctrl_setPlaybackType(temp_v0, 2);
    }
}

/* extern */

void func_80101DAC(Actor *arg0, f32 arg1) {
    s32 func_8008B4A8(struct anctrl_s *, f32);
    struct anctrl_s *temp_v0;

    temp_v0 = func_80104248(arg0);
    if (temp_v0 != 0) {
        func_8008B4A8(temp_v0, arg1);
    }
}

/* extern */

s32 func_80101DDC(Actor *arg0) {
    s32 anctrl_isStopped(struct anctrl_s *);
    struct anctrl_s *temp_v0;

    temp_v0 = func_80104248(arg0);
    if (temp_v0 == 0) {
        return 0;
    }
    return anctrl_isStopped(temp_v0);
}

/* extern */

s32 func_80101E14(Actor *arg0, f32 arg1) {
    s32 anctrl_isAt(struct anctrl_s *, f32);
    struct anctrl_s *temp_v0;

    temp_v0 = func_80104248(arg0);
    if (temp_v0 == 0) {
        return 0;
    }
    return anctrl_isAt(temp_v0, arg1);
}

s32 func_80101E4C(Actor *arg0, f32 *arg1) {
    f32 *var_s0 = arg1;
    s32 var_s1 = 0;

    while (-1.0f != *var_s0) {
        if (func_80101E14(arg0, *var_s0) != 0) {
            return var_s1 + 1;
        }
        var_s1++;
        var_s0++;
    }
    return 0;
}

/* extern */

void func_80101EE4(Actor *arg0, f32 arg1) {
    s32 func_8008B10C(struct anctrl_s *, f32);
    s32 func_8008B2DC(struct anctrl_s *, f32);
    struct anctrl_s *temp_v0;

    temp_v0 = func_80104248(arg0);
    if (temp_v0 != 0) {
        func_8008B10C(temp_v0, arg1);
        func_8008B2DC(temp_v0, arg1);
    }
}

/* extern */
f32 func_80101F24(Actor *arg0) {
    f32 anctrl_getAnimTimer(struct anctrl_s *);
    struct anctrl_s *temp_v0;

    temp_v0 = func_80104248(arg0);
    if (temp_v0 != 0) {
        return anctrl_getAnimTimer(temp_v0);
    }
    return 0.0f;
}

s32 func_80101F64(Actor *arg0, s32 arg1) {
    typedef struct {
        f32 duration;
        u16 index;
        u16 playback;
    } AnimationEntry;
    s32 func_80102394(Actor *);
    s32 anctrl_getIndex(struct anctrl_s *);
    s32 sp1C;
    s32 result;
    struct anctrl_s *temp_v0;

    sp1C = func_80102394(arg0);
    temp_v0 = func_80104248(arg0);
    if (temp_v0 == NULL) {
        return 1;
    }
    result = 1;
    if (sp1C != 0) {
        return anctrl_getIndex(temp_v0) != ((AnimationEntry *)sp1C)[arg1].index;
    }
    return result;
}

/* extern */

void func_80101FDC(Actor *arg0, u32 arg1) {
    s32 anctrl_start(struct anctrl_s *);
    s32 func_80101BE0(Actor *, u32);
    s32 func_80101F64();
    s32 sp1C;
    struct anctrl_s *temp_v0;

    sp1C = func_80101F64();
    if (func_80101BE0(arg0, arg1) != 0) {
        temp_v0 = func_80104248(arg0);
        if ((temp_v0 != 0) && (sp1C != 0)) {
            anctrl_start(temp_v0);
        }
    }
}

f32 func_8010203C(Actor *arg0, u32 arg1) {
    s32 func_80102394(Actor *);
    s32 temp_v0;

    temp_v0 = func_80102394(arg0);
    if (temp_v0 == 0) {
        return 0.0f;
    }
    return *(f32 *)(temp_v0 + (arg1 * 8));
}

/* extern */

void func_80102078(void *arg0, s32 arg1) {
    s32 func_8008B1C8(struct anctrl_s *, s32);
    struct anctrl_s *temp_v0;

    temp_v0 = func_80104248(arg0);
    if (temp_v0 != 0) {
        func_8008B1C8(temp_v0, arg1);
    }
}

/* extern */

void func_801020A8(Actor *arg0) {
    s32 func_8008B1C8(struct anctrl_s *, s32);
    struct anctrl_s *temp_v0;

    temp_v0 = func_80104248(arg0);
    if (temp_v0 != 0) {
        func_8008B1C8(temp_v0, 0x3E4CCCCD);
    }
}

/* extern */

void func_801020DC(void *arg0, s32 arg1) {
    void anctrl_setSmoothTransition(struct anctrl_s *, s32);
    s32 var_a1;
    struct anctrl_s *temp_v0;

    temp_v0 = func_80104248(arg0);
    if (temp_v0 != 0) {
        if (arg1 == 1) {
            var_a1 = 1;
        } else {
            var_a1 = 0;
        }
        anctrl_setSmoothTransition(temp_v0, var_a1);
    }
}

/* extern */

s32 func_80102128(Actor *arg0, s32 arg1, s32 arg2, f32 arg3, s32 arg4) {
    s32 func_8001210C(s32);
    s32 func_800DC298(f32);
    if ((func_8001210C(arg1) == arg2) && (func_800DC298(arg3) != 0)) {
        if (arg4 != -1) {
            func_80102424(arg0, arg4);
        }
        return 1;
    }
    return 0;
}

void func_80102190(void *arg0, s32 arg1) {
    struct Flags { u8 pad[0x74]; u8 upper:4; u8 flag:1; u8 lower:3; };
    struct Flags *p = arg0;
    if (arg1 != 0) {
        p->flag = 0;
        return;
    }
    p->flag = 1;
}

/* extern */

int func_801021BC(Actor *arg0, s32 arg1) {
    s32 func_80102394();
    s32 temp_v0;

    temp_v0 = func_80102394(arg0);
    return temp_v0 != 0 && *(u16 *)((s8 *)temp_v0 + arg1 * 8 + 4) != 0;
}

/* extern */

void func_80102204(Actor *arg0) {
    struct Flags { u8 pad[0x70]; u8 upper:7; u8 flag:1; };
    void _dbanim_entrypoint_0(u8 *, s32, u8 *);
    void func_8008B304(s32);
    s32 func_8008B4D4(struct anctrl_s *);
    void func_800AE160(u8 **, u8 *, s32);
    u8 *func_800B26F0(u8 *);
    u8 *func_800B27E0(u8 *);
    void *func_800DF330(void);
    void func_800DF41C(s32);
    void func_800DF72C(s32);
    u8 *func_801039E4(Unk80132ED0 *);
    s32 func_80103CDC(u8 *, u8 *);
    s32 func_80103D00(void *, u8 *);
    u8 *sp2C;
    u8 *sp28;
    s32 sp24;
    u8 **sp20;
    s32 sp1C;
    struct anctrl_s *sp18;
    struct anctrl_s *temp_v0;

    temp_v0 = func_80104248(arg0);
    sp18 = temp_v0;
    if (temp_v0 != 0) {
        sp2C = func_801039E4(arg0->unk0);
        func_8008B304(sp18);
        sp24 = func_8008B4D4(sp18);
        sp20 = func_800DF330();
        sp1C = func_80103CDC(arg0, sp2C);
        sp28 = func_800B26F0(sp2C);
        func_800AE160(sp20, func_800B27E0(sp2C), sp24);
        _dbanim_entrypoint_0(sp28, sp1C, *sp20);
        if (((struct Flags *)arg0)->flag) {
            _dbanim_entrypoint_0(sp28, func_80103D00(arg0, sp2C), *sp20);
        }
        func_800DF41C(0);
        func_800DF72C(0);
    }
}

/* extern */

s32 func_801022E4(Actor *arg0) {
    s32 anctrl_getIndex(struct anctrl_s *);
    struct anctrl_s *temp_v0;

    temp_v0 = func_80104248(arg0);
    if (temp_v0 != 0) {
        return anctrl_getIndex(temp_v0);
    }
    return 0;
}

/* extern */

s32 func_80102320(Actor *arg0, f32 arg1, f32 arg2) {
    struct anctrl_s *temp_v0;
    f32 anctrl_getAnimTimer(struct anctrl_s *);
    f32 temp_f0;

    temp_v0 = func_80104248(arg0);
    if (temp_v0 != 0) {
        temp_f0 = anctrl_getAnimTimer(temp_v0);
        return (arg1 <= temp_f0) && (temp_f0 <= arg2) ? 1 : 0;
    }
    return 0;
}

/* extern */

s32 func_80102394(Actor *arg0) {
    typedef struct { u32 pad : 12; u32 flag : 1; u32 rest : 19; } Flags;
    void *func_80100368(void *);
    s32 func_80101080();
    s32 func_8010108C(Actor *, s32, s32);
    if (((Flags *)((s8 *)arg0 + 0x78))->flag) {
        func_8010108C(arg0, 0x99, 0);
        return func_80101080();
    }
    return (*(s32 *)((s8 *)(func_80100368(arg0)) + (8)));
}

/* extern */

u16 func_801023E4(s32 arg0, s32 arg1) {
    s32 func_80102394();
    s32 temp_v0;

    temp_v0 = func_80102394(arg0);
    if (temp_v0 == 0) {
        return 0U;
    }
    return *(u16 *)((s8 *)temp_v0 + arg1 * 8 + 6);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDB4D0/func_80102424.s")

/* extern */

s32 func_8010262C(Unk80132ED0 *arg0, u32 arg1) {
    s32 func_800AE080(s16);
    s32 func_800AE6BC(s32 *);
    void func_800AE6FC(s16 *, s16);
    s16 func_800E09B8(s32);
    s32 func_800E0A28(s16);
    void func_800E0ACC(void *);
    void func_800E0AF0(void *, f32);
    s32 model;
    s32 entry;
    s16 handle;
    s16 index;

    index = *(s16 *)&arg0->unk10;
    model = 0;
    if (index != 0 && arg1 != 0) {
        entry = func_800AE080(index);
        model = func_800AE6BC((s32 *)entry);
        if (model == 0) {
            handle = func_800E09B8(arg1);
            func_800AE6FC((s16 *)entry, handle);
            model = func_800E0A28(handle);
        }
        func_800E0ACC((void *)model);
        func_800E0AF0((void *)model, 1.0f);
    }
    return model;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDB4D0/func_801026CC.s")
