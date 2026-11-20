#include "common.h"
#include "thrust_physics.h"
/* extern */

void func_80800000_bamovethrust(BtIntPtr arg0, f32 *arg1, f32 arg2) {
    void func_800EF4E4(f32[3], f32, f32, f32, f32, f32);
    BT_IDO_ONLY(f32 func_8009BFCC();)
    BT_IDO_ONLY(f32 yaw_get(BtIntPtr);)
    f32 sp24;

    sp24 = func_8009BFCC(BT_NATIVE_ONLY((PlayerState *)arg0));
    func_800EF4E4(arg1, sp24, yaw_get(BT_NATIVE_ONLY((PlayerState *))arg0), 0.0f, 0.0f, arg2);
}

void bamovethrust_entrypoint_0(BtIntPtr arg0) 
{
} typedef struct { u8 pad0[0xC8]; union { void * unkC8; u8 * unkC8_u8p; }; } Objthrust_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */
void bamovethrust_entrypoint_1(void *arg0) {
    BT_DATA_FIELD(THRUST_PHYSICS(arg0)->thrust, (*(f32 *)((s8 *)((((Objthrust_arg0 *)arg0)->unkC8)) + (0x8C)))) = 1.0f;
    BT_DATA_FIELD(THRUST_PHYSICS(arg0)->drag, (*(f32 *)((s8 *)((((Objthrust_arg0 *)arg0)->unkC8)) + (0x84)))) = 1.0f;
    BT_DATA_FIELD(THRUST_PHYSICS(arg0)->unk88, (*(f32 *)((s8 *)((((Objthrust_arg0 *)arg0)->unkC8)) + (0x88)))) = 1.0f;
}

void bamovethrust_entrypoint_2(void *arg0, f32 arg1) {
    func_80800000_bamovethrust((BtIntPtr) arg0, BT_DATA_FIELD(THRUST_PHYSICS(arg0)->velocity, (*(s32 *)((s8 *)(arg0) + (0xC8))) + 0x10), arg1);
}

void bamovethrust_entrypoint_3(void *arg0, f32 arg1) {
    BT_DATA_FIELD(THRUST_PHYSICS(arg0)->thrust, *(f32 *)((u8 *)*&((Objthrust_arg0 *)arg0)->unkC8 + 140)) = arg1;
}

void bamovethrust_entrypoint_4(void *arg0, f32 arg1) {
    BT_DATA_FIELD(THRUST_PHYSICS(arg0)->drag, *(f32 *)((u8 *)*&((Objthrust_arg0 *)arg0)->unkC8 + 132)) = arg1;
}

/* extern */

void bamovethrust_entrypoint_5(u8 *arg0) {
    f32 func_800D8FF8(void);
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    void func_800EFA20(void *, void *, f32);
    f32 temp_f0;
    f32 sp38[3];
    f32 sp2C[3];

    func_80800000_bamovethrust((BtIntPtr) arg0, sp38, BT_DATA_FIELD(THRUST_PHYSICS(arg0)->thrust, (*(f32 *)((s8 *)((((Objthrust_arg0 *)arg0)->unkC8_u8p)) + (0x8C)))));
    func_800EE7F8(sp2C, BT_DATA_FIELD(THRUST_PHYSICS(arg0)->velocity, (f32 *)((((Objthrust_arg0 *)arg0)->unkC8_u8p) + 0x10)));
    func_800EF334(sp2C, BT_DATA_FIELD(THRUST_PHYSICS(arg0)->drag, (*(f32 *)((s8 *)((((Objthrust_arg0 *)arg0)->unkC8_u8p)) + (0x84)))));
    func_800EE780(BT_DATA_FIELD(THRUST_PHYSICS(arg0)->velocity, (f32 *)((((Objthrust_arg0 *)arg0)->unkC8_u8p) + 0x10)), sp2C, sp38);
    temp_f0 = func_800D8FF8();
    BT_DATA_FIELD(THRUST_PHYSICS(arg0)->velocity[1], (*(f32 *)((*(u8 **)(arg0 + 0xC8)) + 0x14))) += BT_DATA_FIELD(THRUST_PHYSICS(arg0)->gravity, (*(f32 *)((*(u8 **)(arg0 + 0xC8)) + 0x34))) * temp_f0;
    if (BT_DATA_FIELD(THRUST_PHYSICS(arg0)->velocity[1], (*(f32 *)((*(u8 **)(arg0 + 0xC8)) + 0x14))) < BT_DATA_FIELD(THRUST_PHYSICS(arg0)->terminal_velocity, (*(f32 *)((*(u8 **)(arg0 + 0xC8)) + 0x38)))) {
        BT_DATA_FIELD(THRUST_PHYSICS(arg0)->velocity[1], (*(f32 *)((*(u8 **)(arg0 + 0xC8)) + 0x14))) = BT_DATA_FIELD(THRUST_PHYSICS(arg0)->terminal_velocity, (*(f32 *)((*(u8 **)(arg0 + 0xC8)) + 0x38)));
    }
    func_800EFA20(BT_DATA_FIELD(THRUST_PHYSICS(arg0)->displacement, (((Objthrust_arg0 *)arg0)->unkC8_u8p) + 0x28), BT_DATA_FIELD(THRUST_PHYSICS(arg0)->velocity, (((Objthrust_arg0 *)arg0)->unkC8_u8p) + 0x10), temp_f0);
    func_800EF04C(BT_DATA_FIELD(THRUST_PHYSICS(arg0)->position, (f32 *)((*(u8 **)(arg0 + 0xC8)) + 4)), BT_DATA_FIELD(THRUST_PHYSICS(arg0)->displacement, (f32 *)((*(u8 **)(arg0 + 0xC8)) + 0x28)));
}

f32 bamovethrust_entrypoint_6(void *arg0) {
    return BT_DATA_FIELD(THRUST_PHYSICS(arg0)->thrust, *(f32 *)((u8 *)*&((Objthrust_arg0 *)arg0)->unkC8 + 140));
}
