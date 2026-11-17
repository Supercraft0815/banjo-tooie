#include "common.h"

void func_80106A20(void) {
}

void func_80106A28(void) {
    s32 func_800B3370(s32);
    extern s32 D_80136EF0;
    if (D_80136EF0 != 0) {
        func_800B3370(D_80136EF0);
        D_80136EF0 = 0;
    }
}

void func_80106A60(void) {
    s32 func_800B38E8(s32);
    extern s32 D_80136EF0;
    if (D_80136EF0 != 0) {
        D_80136EF0 = func_800B38E8(D_80136EF0);
    }
}

typedef struct {
    u8 pad0[0x60];
    s16 reference;
    u8 pad62[0x12];
    u32 pad74_26 : 6;
    u32 renderMode : 1;
    u32 pad74_7 : 18;
    u32 reverse : 1;
    u32 pad74_0 : 6;
    u32 pad78_8 : 24;
    u32 level : 2;
    u32 pad78_2 : 4;
    u32 color : 1;
    u32 pad78_0 : 1;
    u8 pad7C[0x18];
    u32 pad94 : 16;
    u32 special : 1;
    u32 pad94_0 : 15;
    u8 red, green, blue, alpha;
} ActorRenderState;

void func_80106A98(Actor *actor, BtIntPtr arg1) {
    u8 *func_800B27A0(u8 *);
    void func_800DF5D8(u32, u32, u32, s32);
    void func_800DF660(s32, s32, BtIntPtr, s32);
    void func_800DF720(BtIntPtr);
    BtIntPtr func_80100AC4(s16);
    BtIntPtr func_80106C4C(Actor *);
    BtIntPtr sp24;
    s32 var_a1;
    ActorRenderState *arg0 = (ActorRenderState *)actor;

    if (arg0->level != 0) {
        if (arg0->special) {
            func_800DF660(3, arg0->level, 0, arg0->alpha);
            func_800DF720(func_80100AC4(arg0->reference));
            return;
        }
        if (arg0->renderMode) {
            func_800DF660(2, arg0->level, 0, arg0->alpha);
            func_800DF720(func_80100AC4(arg0->reference));
            return;
        }
        sp24 = func_80106C4C(actor);
        if (func_800B27A0((u8 *)arg1) == NULL) {
            arg0->level = 0;
            arg0->reverse = 0;
            return;
        }
        if (sp24 != 0) {
            func_800DF660(1, 0, sp24, arg0->alpha);
        } else {
            if (arg0->reverse) {
                var_a1 = -(s32)arg0->level;
            } else {
                var_a1 = arg0->level;
            }
            func_800DF660(1, var_a1, 0, arg0->alpha);
        }
        func_800DF720(func_80100AC4(arg0->reference));
        return;
    }
    if (arg0->color) {
        func_800DF5D8(arg0->red, arg0->green, arg0->blue, arg0->alpha);
    }
}

s32 func_80106C08(void) {
    extern s32 D_80136EF0;
    void * func_800B3310(s32 capacity);

    if (D_80136EF0 == 0) {
        D_80136EF0 = func_800B3310(0x6);
    }
    return D_80136EF0;
}

BtIntPtr func_80106C4C(Actor *arg0) {
    void _subaddiefade_entrypoint_9(Actor *, s32 *);
    s32 func_800B3494(BtIntPtr, f32 *, f32);
    int func_800B36C0(BtIntPtr, f32 *, s32 *, f32);
    void func_800B37A4(u8 *, s32 *, s32 *);
    void func_800C8960(s32 *, f32 *);
    f32 func_80103F38(Actor *, f32 *);
    void func_80106D60(BtIntPtr, BtIntPtr, s32 *);
    void func_80106DA4(s32 *, s32 *);
    struct entry {
        f32 position[3];
        s32 value[3];
        f32 radius;
    };
    f32 sp64[3];
    s32 pad60;
    s32 sp5C;
    s32 sp50[3];
    BtIntPtr sp4C;
    s32 sp48;
    union {
        u32 value;
        struct {
            u32 pad25 : 25;
            u32 flag6 : 1;
            u32 pad4 : 4;
            u32 flag1 : 1;
            u32 flag0 : 1;
        } bits;
    } flags;
    f32 sp38[3];
    s32 sp2C[3];
    f32 radius;
    BtIntPtr handle;

    flags.value = arg0->pad7A_0;
    if (!flags.bits.flag1) {
        return 0;
    }
    _subaddiefade_entrypoint_9(arg0, sp50);
    handle = func_80106C08();
    func_80106D60((BtIntPtr)arg0, handle, sp50);
    sp5C = func_800B3494(handle, sp64, func_80103F38(arg0, sp64));
    func_800B37A4((u8 *)handle, &sp4C, &sp48);
    if (sp5C < (s32)arg0->pad7A_7) {
        flags.value = arg0->pad74_0;
        if (flags.bits.flag6) {
        func_800C8960(sp2C, sp38);
        func_80106DA4(sp2C, sp50);
        func_800B36C0(handle, sp38, sp2C, sp5C != 0 ? ((struct entry *)sp4C)->radius : 500.0f);
        }
    }
    return handle;
}

/* extern */

void func_80106D60(BtIntPtr arg0, BtIntPtr arg1, s32 *arg2) {
    void func_800B38A8();
    void func_800C87B8(s32 *);
    void func_80106DA4(s32 *, s32 *);
    s32 sp1C[3];

    func_800C87B8(sp1C);
    func_80106DA4(sp1C, arg2);
    func_800B38A8(arg1, sp1C);
}

void func_80106DA4(s32 *arg0, s32 *arg1) {
    s32 i;

    for (i = 0; i < 3; i++) {
        arg0[i] = (arg0[i] * arg1[i]) >> 8;
    }
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
s32 D_80136EF0 BT_DATA(4, bss_core2bss2_2_music_tail, 0x14D0);
#endif
