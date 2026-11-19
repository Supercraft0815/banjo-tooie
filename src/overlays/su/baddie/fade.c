#include "su/baddiefade.h"

u32 subaddiefade_entrypoint_0(u8 *arg0) {
    return arg0[155];
}    typedef struct { u8 pad0[0x79]; u8 unk79; u8 pad7A[0x21]; s8 unk9B; } Objfade_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void subaddiefade_entrypoint_1(void *arg0, s32 arg1) {
    (((Objfade_arg0 *)arg0)->unk79) = (u8)((((Objfade_arg0 *)arg0)->unk79) & 0xFFFC);
    (((Objfade_arg0 *)arg0)->unk9B) = arg1;
}

void subaddiefade_entrypoint_2(void *arg0) {
    (((Objfade_arg0 *)arg0)->unk9B) = 0;
    (((Objfade_arg0 *)arg0)->unk79) = (u8) (((((Objfade_arg0 *)arg0)->unk79) & 0xFFFC) | 1);
}

void subaddiefade_entrypoint_3(void *arg0) {
    (((Objfade_arg0 *)arg0)->unk79) = (u8) (((((Objfade_arg0 *)arg0)->unk79) & 0xFFFC) | 2);
}

void subaddiefade_entrypoint_4(void *arg0) {
    (((Objfade_arg0 *)arg0)->unk79) = (u8) (((((Objfade_arg0 *)arg0)->unk79) & 0xFFFC) | 1);
}

void subaddiefade_entrypoint_5(void *arg0) {
    (((Objfade_arg0 *)arg0)->unk79) = (u8) (((((Objfade_arg0 *)arg0)->unk79) & 0xFFFC) | 3);
}

void subaddiefade_entrypoint_6(u8 *arg0, s32 arg1) {
    s32 temp_v0;
    s32 var_v1;
    s32 var_v1_2;

    temp_v0 = (*(u8 *)((s8 *)(arg0) + (0x9B))) + arg1;
    var_v1 = temp_v0 >= 0x100 ? 0xFF : temp_v0;
    if (var_v1 < 0) {
        (*(u8 *)((s8 *)(arg0) + (0x9B))) = 0U;
        return;
    }
    var_v1_2 = temp_v0 >= 0x100 ? 0xFF : temp_v0;
    (*(u8 *)((s8 *)(arg0) + (0x9B))) = (u8) var_v1_2;
}

/* extern */

void subaddiefade_entrypoint_7(Actor *arg0) {
    f32 func_800D8FF8(void);
    void func_800FFAB0(Actor *);
    s32 func_80107070(Actor *, s32);
    struct FadeFlags {
        u8 padding[0x74];
        BT_BITFIELD_ORDER(u32 upper : 27, u32 lower : 4);
        u32 timed : 1;
        BT_BITFIELD_ORDER(u32 lower : 4, u32 upper : 27);
        BT_BITFIELD_ORDER(u16 upper78 : 14, char : 0);
        BT_BITFIELD_ORDER(u16 state : 2, u16 state : 2; u16 upper78 : 14);
    };
    f32 dt;
    s32 alpha;

    if (((struct FadeFlags *)arg0)->timed) {
        dt = func_800D8FF8();
        ((f32 *)arg0->actorData)[1] += dt;
        if (((f32 *)arg0->actorData)[0] < ((f32 *)arg0->actorData)[1]) {
            ((f32 *)arg0->actorData)[1] = ((f32 *)arg0->actorData)[0];
        }
        switch (((struct FadeFlags *)arg0)->state) {
        case 1:
            if (0.0f != ((f32 *)arg0->actorData)[0]) {
                arg0->alpha = (s32)((((f32 *)arg0->actorData)[1] / ((f32 *)arg0->actorData)[0]) * 255.0f);
            } else {
                arg0->alpha = 255;
            }
            if (arg0->alpha == 255) {
                ((struct FadeFlags *)arg0)->state = 0;
                return;
            }
            break;
        case 2:
            if (0.0f != ((f32 *)arg0->actorData)[0]) {
                arg0->alpha = 255 - (s32)((((f32 *)arg0->actorData)[1] / ((f32 *)arg0->actorData)[0]) * 255.0f);
            } else {
                arg0->alpha = 0;
            }
            if (arg0->alpha == 0) {
                ((struct FadeFlags *)arg0)->state = 0;
                return;
            }
            break;
        }
    } else {
        switch (((struct FadeFlags *)arg0)->state) {
        case 1:
            alpha = arg0->alpha + 7;
            if (alpha >= 256) {
                arg0->alpha = 255;
            } else {
                arg0->alpha = alpha;
            }
            if (arg0->alpha == 255) {
                ((struct FadeFlags *)arg0)->state = 0;
                return;
            }
            return;
        case 2:
            alpha = arg0->alpha - 7;
            if (alpha < 0) {
                arg0->alpha = 0;
            } else {
                arg0->alpha = alpha;
            }
            if (arg0->alpha == 0 && func_80107070(arg0, 3) == 0) {
                func_800FFAB0(arg0);
                return;
            }
            break;
        case 3:
            alpha = arg0->alpha - 7;
            if (alpha < 0) {
                arg0->alpha = 0;
            } else {
                arg0->alpha = alpha;
            }
            if (arg0->alpha == 0) {
                ((struct FadeFlags *)arg0)->state = 0;
            }
            break;
        }
    }
}

/* extern */

void subaddiefade_entrypoint_8(void *arg0, s32 arg1) {
    s32 func_800F0D90(s32 arg0, s32 arg1, s32 arg2);
    (((Objfade_arg0 *)arg0)->unk9B) = func_800F0D90(arg1, 0, 0xFF);
}

void subaddiefade_entrypoint_9(void *arg0, f32 *arg1) {
    void func_800F2EE0(void *arg0, void *arg1);
    func_800F2EE0(arg1, (u8 *)arg0 + 0x98);
}

void subaddiefade_entrypoint_10(void *arg0, f32 *arg1) {
    void func_800F2EFC(void *arg0, void *arg1);
    func_800F2EFC(arg1, (u8 *)arg0 + 0x98);
}

/* extern */

void subaddiefade_entrypoint_11(u8 *arg0, u8 *arg1) {
    void func_800F2F20(void *arg0, void *arg1);
    void func_80800450_subaddiefade();
    struct Flags {
        u8 padding[0x70];
        BT_BITFIELD_ORDER(u32 upper : 29, u32 lower : 2);
        u32 flag : 1;
        BT_BITFIELD_ORDER(u32 lower : 2, u32 upper : 29);
    };
    s32 sp1C[3];

    if (((struct Flags *)arg0)->flag) {
        func_80800450_subaddiefade(sp1C, arg1, arg0);
        func_800F2F20(arg0 + 0x98, sp1C);
        return;
    }
    func_800F2F20(arg0 + 0x98, arg1);
}

/* extern */

void subaddiefade_entrypoint_12(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    void func_800EFA88(void *, s32, s32, s32);
    s32 sp1C[3];

    func_800EFA88(sp1C, arg1, arg2, arg3);
    subaddiefade_entrypoint_11(arg0, (u8 *)sp1C);
}

/* extern */

void subaddiefade_entrypoint_13(u8 *arg0, u8 *arg1) {
    void func_800F2F20(void *arg0, void *arg1);
    void func_800F2F3C(void *arg0, void *arg1);
    void func_80800450_subaddiefade();
    struct Flags {
        u8 padding[0x70];
        BT_BITFIELD_ORDER(u32 upper : 29, u32 lower : 2);
        u32 flag : 1;
        BT_BITFIELD_ORDER(u32 lower : 2, u32 upper : 29);
    };
    s32 sp1C[3];

    if (((struct Flags *)arg0)->flag) {
        func_80800450_subaddiefade(sp1C, arg1, arg0);
        func_800F2F20(arg0 + 0x98, sp1C);
        return;
    }
    func_800F2F3C(arg0 + 0x98, arg1);
} 

void func_80800450_subaddiefade(s32 *arg0, u8 *arg1) {
    s32 temp_f16;

    temp_f16 = (s32) ((f32) ((*(s32 *)((s8 *)(arg1) + (0))) + (*(s32 *)((s8 *)(arg1) + (4))) + (*(s32 *)((s8 *)(arg1) + (8)))) / 3.0f);
    arg0[0] = temp_f16;
    arg0[1] = temp_f16;
    arg0[2] = temp_f16;
}

/* extern */

void subaddiefade_entrypoint_14(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    void func_800C87DC(void *, s32, s32, s32);
    s32 sp1C[3];

    func_800C87DC(sp1C, arg1, arg2, arg3);
    subaddiefade_entrypoint_11(arg0, (u8 *)sp1C);
}
