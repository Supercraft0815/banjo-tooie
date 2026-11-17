#include "core2/1EEBA50.h"

s32 func_80112160() 
{
    return 0x34;
}

f32 func_80112168(s32 *arg0, f32 *arg1) {
    s32 func_80110840(s32 *);
    f32 func_800F5BC4(BtIntPtr, f32 *);
    void func_800F5A00(BtIntPtr, f32 *);
    void func_800EF04C(f32 *, f32 *);
    f32 sp2C;
    f32 sp20[3];
    s32 sp1C;

    sp1C = func_80110840(arg0);
    sp2C = func_800F5BC4(sp1C, arg1);
    func_800F5A00(sp1C, sp20);
    func_800EF04C(arg1, sp20);
    return sp2C;
}

void func_801121B8(PlayerState* arg0, f32* arg1)
{
    func_80112168(arg0,arg1);
}

/* extern */

void func_801121D8(s32 *arg0, f32 *arg1) {
    s32 func_80110840(s32 *);
    void func_800F5A00(BtIntPtr, f32 *);
    func_800F5A00(func_80110840(arg0), arg1);
}

void func_80112204(s32 *arg0, f32 *arg1) {
    s32 func_80110840(s32 *);
    void func_800F5470(s32, f32 *);
    f32 sp1C[3];

    func_80112168(arg0, arg1);
    func_800F5470(func_80110840(arg0), sp1C);
    arg1[0] = sp1C[0];
    arg1[2] = sp1C[2];
}

void func_80112250(s32 *arg0, f32 *arg1) {
    f32 func_80013728(f32);
    f32 func_800EEAD4(f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF368(f32 *, f32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_800F51F0(s32, f32 *, f32 *);
    BT_IDO_ONLY(f32 func_800F5AE0(s32);) BT_NATIVE_ONLY(s32 func_800F5AE0(s32); union { s32 bits; f32 value; } native_pitch;)
    void func_801107F0(void *, f32 *);
    s32 func_80110840(s32 *);
    f32 sp44[3];
    f32 sp38[3];
    f32 sp34;
    f32 sp30;
    f32 temp_f0;
    s32 sp28;

    sp28 = func_80110840(arg0);
    func_80112168(arg0, arg1);
    func_801107F0(arg0, sp38);
    sp34 = func_800EEAD4(sp38, arg1);
    func_800EFA4C(sp44, 0.0f, 200.0f, 0.0f);
    func_800F51F0(sp28, sp44, sp44);
    sp30 = func_800F10B4(sp34, 700.0f, 1500.0f, 100.0f, 200.0f);
    BT_NATIVE_ONLY(native_pitch.bits = func_800F5AE0(sp28);) temp_f0 = func_80013728(BT_IDO_ONLY(func_800F5AE0(sp28)) BT_NATIVE_ONLY(native_pitch.value));
    if (temp_f0 < 0.0f) {
        sp30 *= func_800F10B4(temp_f0, -30.0f, -60.0f, 1.0f, 0.0f);
    }
    func_800EF368(sp44, sp30);
    func_800EF04C(arg1, sp44);
}                 typedef struct { f32 unk0; u8 pad4[0x4]; f32 unk8; } Obj1EEBA50_arg1; /* offsets.py genstruct: fields from raw offsets on arg1; rename once understood */

void func_80112354(PlayerState *arg0, BtIntPtr arg1) {
    func_80112168(arg0, arg1);
    (((Obj1EEBA50_arg1 *)arg1)->unk0) = (f32) (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x30)))) + (0x28)));
    (((Obj1EEBA50_arg1 *)arg1)->unk8) = (f32) (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x30)))) + (0x30)));
}    typedef struct { u8 pad0[0x30]; s32 * unk30; } Obj1EEBA50_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_80112398(u8 *arg0) {
    void func_800EFD24(f32 vec[3]);
    void func_801124D0(BtIntPtr, s32);
    *(((Obj1EEBA50_arg0 *)arg0)->unk30) = 0;
    func_801124D0((BtIntPtr) arg0, 1);
    func_800EFD24((f32 *)(((Obj1EEBA50_arg0 *)arg0)->unk30) + 1);
}

void func_801123D4(PlayerState *arg0) {
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    u32 func_8010FFD0(u8 *);
    BtIntPtr func_80110898(s32 *);
    void func_80111F70(u8 *, u8 *, u8 *, void *, f32 *);
    f32 sp2C[3];

    switch (**(s32 **)((u8 *)arg0 + 0x30)) {
        case 1:
        case 5:
            func_801121B8(arg0, sp2C);
            break;
        case 4:
            func_801121D8((s32 *)arg0, sp2C);
            break;
        case 3:
            func_80112250((s32 *)arg0, sp2C);
            break;
        case 2:
            func_80112204((s32 *)arg0, sp2C);
            break;
        case 6:
            func_80112354(arg0, (BtIntPtr)sp2C);
            break;
    }
    if (func_8010FFD0((u8 *)func_80110898((s32 *)arg0))) {
        func_800EE7F8((f32 *)(*(u8 **)((u8 *)arg0 + 0x30) + 4), (BtIntPtr)sp2C);
    } else {
        func_80111F70((u8 *)arg0, (u8 *)sp2C,
            *(u8 **)((u8 *)arg0 + 0x30) + 4,
            *(u8 **)((u8 *)arg0 + 0x30) + 0x10,
            (f32 *)(*(u8 **)((u8 *)arg0 + 0x30) + 0x14));
    }
}

void func_801124D0(BtIntPtr arg0, s32 arg1) { BtIntPtr temp_a2; volatile s32 **temp_a1; temp_a2 = arg1; if (arg1 == 6) { temp_a1 = (volatile s32 **)((s8 *)(arg0) + 0x30); func_801121B8((PlayerState *) arg0, (f32 *)((s8 *)*temp_a1 + 0x28)); } **(s32 ***)((s8 *)(arg0) + 0x30) = temp_a2; }

s32 func_80112518(void *arg0) {
    return *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 48) + 0);
}

/* extern */

void func_80112524(PlayerState *arg0, f32 *arg1) {
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    func_800EE7F8(arg1, (arg0->unk30) + 4);
}

f32 func_80112550(PlayerState* arg0, f32* arg1)
{
    return func_80112168(arg0,arg1);
}

void func_80112570(u8 *arg0, BtIntPtr arg1, f32 arg2) {
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    func_800EE7F8((*(u8 **)((s8 *)(arg0) + (0x30))) + 0x18, arg1);
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x30)))) + (0x24))) = arg2;
}
