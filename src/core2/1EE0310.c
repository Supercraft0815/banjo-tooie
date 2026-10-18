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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE0310/func_80106A98.s")

s32 func_80106C08(void) {
    extern s32 D_80136EF0;
    s32 func_800B3310(s32);

    if (D_80136EF0 == 0) {
        D_80136EF0 = func_800B3310(0x6);
    }
    return D_80136EF0;
}

s32 func_80106C4C(Actor *arg0) {
    void _subaddiefade_entrypoint_9(Actor *, s32 *);
    s32 func_800B3494(s32, f32 *, f32);
    int func_800B36C0(s32, f32 *, s32 *, f32);
    void func_800B37A4(u8 *, s32 *, s32 *);
    void func_800C8960(s32 *, f32 *);
    f32 func_80103F38(Actor *, f32 *);
    void func_80106D60(s32, s32, s32 *);
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
    s32 sp4C;
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
    s32 handle;

    flags.value = arg0->pad7A_0;
    if (!flags.bits.flag1) {
        return 0;
    }
    _subaddiefade_entrypoint_9(arg0, sp50);
    handle = func_80106C08();
    func_80106D60((s32)arg0, handle, sp50);
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

void func_80106D60(s32 arg0, s32 arg1, s32 *arg2) {
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
