#include "core2/1EDB4D0.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDB4D0/func_80101BE0.s")

/* extern */

void func_80101CDC(Actor *arg0, f32 arg1) {
    s32 anctrl_setDuration(s32, f32);
    s32 func_80104248();
    s32 temp_v0;

    temp_v0 = func_80104248(arg0);
    if (temp_v0 != 0) {
        anctrl_setDuration(temp_v0, arg1);
    }
}

/* extern */

f32 func_80101D0C(void) {
    f32 func_8008B2AC(s32);
    s32 func_80104248();
    s32 temp_v0;

    temp_v0 = func_80104248();
    if (temp_v0 != 0) {
        return func_8008B2AC(temp_v0);
    }
    return 0.0f;
}

/* extern */

void func_80101D4C(void) {
    s32 anctrl_setPlaybackType(s32, s32);
    s32 func_80104248();
    s32 temp_v0;

    temp_v0 = func_80104248();
    if (temp_v0 != 0) {
        anctrl_setPlaybackType(temp_v0, 1);
    }
}

/* extern */

void func_80101D7C(void) {
    s32 anctrl_setPlaybackType(s32, s32);
    s32 func_80104248();
    s32 temp_v0;

    temp_v0 = func_80104248();
    if (temp_v0 != 0) {
        anctrl_setPlaybackType(temp_v0, 2);
    }
}

/* extern */

void func_80101DAC(Actor *arg0, f32 arg1) {
    s32 func_8008B4A8(s32, f32);
    s32 func_80104248();
    s32 temp_v0;

    temp_v0 = func_80104248(arg0);
    if (temp_v0 != 0) {
        func_8008B4A8(temp_v0, arg1);
    }
}

/* extern */

s32 func_80101DDC(Actor *arg0) {
    s32 anctrl_isStopped(s32);
    s32 func_80104248();
    s32 temp_v0;

    temp_v0 = func_80104248(arg0);
    if (temp_v0 == 0) {
        return 0;
    }
    return anctrl_isStopped(temp_v0);
}

/* extern */

s32 func_80101E14(Actor *arg0, f32 arg1) {
    s32 anctrl_isAt(s32, f32);
    s32 func_80104248();
    s32 temp_v0;

    temp_v0 = func_80104248(arg0);
    if (temp_v0 == 0) {
        return 0;
    }
    return anctrl_isAt(temp_v0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDB4D0/func_80101E4C.s")

/* extern */

void func_80101EE4(Actor *arg0, f32 arg1) {
    s32 func_8008B10C(s32, f32);
    s32 func_8008B2DC(s32, f32);
    s32 func_80104248();
    s32 temp_v0;

    temp_v0 = func_80104248(arg0);
    if (temp_v0 != 0) {
        func_8008B10C(temp_v0, arg1);
        func_8008B2DC(temp_v0, arg1);
    }
}

/* extern */
f32 func_80101F24(Actor *arg0) {
    s32 func_80104248(Actor *);
    f32 anctrl_getAnimTimer(s32);
    s32 temp_v0;

    temp_v0 = func_80104248(arg0);
    if (temp_v0 != 0) {
        return anctrl_getAnimTimer(temp_v0);
    }
    return 0.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDB4D0/func_80101F64.s")

/* extern */

void func_80101FDC(Actor *arg0, u32 arg1) {
    s32 anctrl_start(s32);
    s32 func_80101BE0(Actor *, u32);
    s32 func_80101F64();
    s32 func_80104248(Actor *);
    s32 sp1C;
    s32 temp_v0;

    sp1C = func_80101F64();
    if (func_80101BE0(arg0, arg1) != 0) {
        temp_v0 = func_80104248(arg0);
        if ((temp_v0 != 0) && (sp1C != 0)) {
            anctrl_start(temp_v0);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDB4D0/func_8010203C.s")

/* extern */

void func_80102078(s32 arg0, s32 arg1) {
    s32 func_8008B1C8(s32, s32);
    s32 func_80104248();
    s32 temp_v0;

    temp_v0 = func_80104248(arg0);
    if (temp_v0 != 0) {
        func_8008B1C8(temp_v0, arg1);
    }
}

/* extern */

void func_801020A8(void) {
    s32 func_8008B1C8(s32, s32);
    s32 func_80104248();
    s32 temp_v0;

    temp_v0 = func_80104248();
    if (temp_v0 != 0) {
        func_8008B1C8(temp_v0, 0x3E4CCCCD);
    }
}

/* extern */

void func_801020DC(void *arg0, s32 arg1) {
    struct anctrl_s;
    s32 func_80104248();
    void anctrl_setSmoothTransition(struct anctrl_s *, s32);
    s32 var_a1;
    s32 temp_v0;

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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDB4D0/func_801021BC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDB4D0/func_80102204.s")

/* extern */

s32 func_801022E4(Actor *arg0) {
    s32 anctrl_getIndex(s32);
    s32 func_80104248(Actor *);
    s32 temp_v0;

    temp_v0 = func_80104248(arg0);
    if (temp_v0 != 0) {
        return anctrl_getIndex(temp_v0);
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDB4D0/func_80102320.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDB4D0/func_80102394.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDB4D0/func_801023E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDB4D0/func_80102424.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDB4D0/func_8010262C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDB4D0/func_801026CC.s")
