#include "common.h"

void subaddiedraw25d_entrypoint_0(void *arg0) {
    struct Flags {
        u8 pad[0x7E];
        u8 high : 3;
        u8 enabled : 1;
        u8 low : 4;
    };
    ((struct Flags *)arg0)->enabled = 1;
}

void subaddiedraw25d_entrypoint_1(Actor *arg0, BtIntPtr arg1) {
    struct DrawFlags {
        u8 pad[0x78];
        union {
            struct {
                u16 upper : 14;
                u16 flags : 2;
            } half;
            struct {
                u32 next : 30;
                u32 tinted : 1;
                u32 low : 1;
            } word;
        } bits;
    };
    struct ModelFlags {
        u8 pad[8];
        u32 upper : 16;
        u32 index : 5;
        u32 middle : 5;
        u32 flag : 1;
        u32 low : 5;
    };
    s32 func_800AF5A8(s16 *);
    void func_800E24E4(BtIntPtr, BtIntPtr);
    void func_800E24F8(s32, s32, s32);
    void func_800E257C(s32);
    void func_800E2588(u32);
    void func_800E2C54(u8 *arg0, u8 *resource, s32 index, s32 flip, f32 *positionArg, f32 *rotation, f32 *scale);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void *func_80103AE4(Unk80132ED0 *marker);
    void subaddiedraw25d_entrypoint_3(Actor *);
    void _subaddiedraw25d_entrypoint_0(void *);
    f32 scale[3];
    f32 rotation[3];
    Unk80132ED0 *sp44;
    BtIntPtr sp40;
    struct ModelFlags *model;

    sp44 = arg0->unk0;
    sp40 = func_80103AE4(sp44);
    scale[0] = scale[1] = scale[2] = arg0->scale;
    func_800EFA4C(rotation, arg0->rotation[0], arg0->rotation[1], 0.0f);
    if (((struct DrawFlags *)arg0)->bits.half.flags) {
        func_800E257C(arg0->alpha);
        func_800E2588(1);
    } else if (func_800AF5A8(sp40) & 0xB00) {
        func_800E2588(1);
    } else {
        func_800E2588(3);
    }
    if (((struct DrawFlags *)arg0)->bits.word.tinted) {
        func_800E24F8(arg0->pad98, arg0->pad99, arg0->pad9A);
    }
    subaddiedraw25d_entrypoint_3(arg0);
    func_800E24E4(_subaddiedraw25d_entrypoint_0, arg0);
    model = sp44->unk0;
    func_800E2C54(arg1, sp40, model->index, model->flag, arg0->position, rotation, scale);
}

void subaddiedraw25d_entrypoint_2(Actor *arg0, s32 arg1) {
    struct DrawFlags {
        u8 pad[0x78];
        union {
            struct {
                u16 upper : 14;
                u16 flags : 2;
            } half;
            struct {
                u32 next : 30;
                u32 tinted : 1;
                u32 low : 1;
            } word;
        } bits;
    };
    struct ModelFlags {
        u8 pad[8];
        u32 upper : 16;
        u32 index : 5;
        u32 middle : 5;
        u32 flag : 1;
        u32 low : 5;
    };
    s32 func_800AF5A8(s16 *);
    void func_800E24E4(BtIntPtr, BtIntPtr);
    void func_800E24F8(s32, s32, s32);
    void func_800E257C(s32);
    void func_800E2588(u32);
    void func_800E2AA4(BtIntPtr, BtIntPtr, s32, s32, void *, f32 *);
    void *func_80103AE4(Unk80132ED0 *marker);
    void subaddiedraw25d_entrypoint_3(Actor *);
    void _subaddiedraw25d_entrypoint_0(void *);
    f32 scale[3];
    Unk80132ED0 *sp38;
    BtIntPtr sp34;
    struct ModelFlags *model;

    sp38 = arg0->unk0;
    sp34 = func_80103AE4(sp38);
    scale[0] = scale[1] = scale[2] = arg0->scale;
    if (((struct DrawFlags *)arg0)->bits.half.flags) {
        func_800E257C(arg0->alpha);
        func_800E2588(1);
    } else if (func_800AF5A8(sp34) & 0xB00) {
        func_800E2588(1);
    } else {
        func_800E2588(3);
    }
    if (((struct DrawFlags *)arg0)->bits.word.tinted) {
        func_800E24F8(arg0->pad98, arg0->pad99, arg0->pad9A);
    }
    subaddiedraw25d_entrypoint_3(arg0);
    func_800E24E4(_subaddiedraw25d_entrypoint_0, arg0);
    model = sp38->unk0;
    func_800E2AA4(arg1, sp34, model->index, model->flag, arg0->position, scale);
}

/* extern */

void subaddiedraw25d_entrypoint_3(Actor *arg0) {
    struct Flags {
        u8 pad[0x70];
        u32 high : 11;
        u32 enabled : 1;
        u32 low : 20;
    };
    s32 func_800D2F20(void);
    void func_800E249C(s32);
    void func_800E24C0(s32);
    void *func_80100368(void *);
    u16 temp_a0;

    func_800E24C0(((struct Flags *)arg0)->enabled);
    temp_a0 = (*(u16 *)((s8 *)(func_80100368(arg0)) + (0x1A)));
    if (temp_a0 != 0) {
        func_800E249C(temp_a0);
        return;
    }
    if (!(arg0->unk0->unk10 & 1)) {
        func_800E249C(func_800D2F20());
    }
}
