#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/move/goto/func_80800000_bamovegoto.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/move/goto/bamovegoto_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/move/goto/bamovegoto_entrypoint_1.s")

f32 bamovegoto_entrypoint_2(void *arg0) {
    return *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 200) + 116);
}

/* extern */

void bamovegoto_entrypoint_3(void *arg0) {
    s32 func_800EEAD4(s32, s32);
    s32 temp_v0;

    temp_v0 = (*(s32 *)((s8 *)(arg0) + (0xC8)));
    func_800EEAD4(temp_v0 + 0x58, temp_v0 + 0x64);
}

s32 bamovegoto_entrypoint_4(void *arg0) {
    return (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xC8)))) + (0x54))) == 6;
}

void bamovegoto_entrypoint_5(s32 arg0)
{
    func_80800000_bamovegoto(arg0,0);
}

void bamovegoto_entrypoint_6(void *arg0) {
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xC8)))) + (0x54))) = 0;
}

void bamovegoto_entrypoint_7(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 200) + 112) = arg1;
}

void bamovegoto_entrypoint_8(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 200) + 120) = arg1;
}

void bamovegoto_entrypoint_9(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 200) + 85) = arg1;
}

void bamovegoto_entrypoint_10(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 200) + 86) = arg1;
}

void bamovegoto_entrypoint_11(void *arg0, s32 arg1, s32 arg2) {
    (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xC8)))) + (0x80))) = arg1;
    (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xC8)))) + (0x7C))) = arg2;
}

/* extern */

void bamovegoto_entrypoint_12(void *arg0) {
    s32 func_800EE7F8(s32);
    func_800EE7F8((*(s32 *)((s8 *)(arg0) + (0xC8))) + 100);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/move/goto/bamovegoto_entrypoint_13.s")

void bamovegoto_entrypoint_14(void *arg0) {
    void baphysics_set_target_horizontal_velocity(void *, f32);
    void func_8009BA9C(void *, f32 *);
    void func_8009C128(void *, f32 *);
    f32 func_800D8FF8(void);
    s32 func_800EE7F8();
    f32 func_800EEF94(f32 *);
    f32 func_800EEFFC(f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    void func_800EF368(f32 *, f32);
    void func_800EFA20(void *, void *, f32);
    void func_800EFB24(void *, void *, void *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F1214(f32, f32, f32);
    f32 progress;
    f32 blend;
    f32 diff[3];
    f32 oldpos[3];
    f32 dt;
    f32 velocity[3];
    f32 value;
    u8 *state;

    state = *(u8 **)((u8 *)arg0 + 0xC8);
    switch (state[0x54]) {
    case 2:
        func_8009C128(arg0, (f32 *)(state + 0x58));
        state = *(u8 **)((u8 *)arg0 + 0xC8);
        if (*(f32 *)(state + 0x78) != 0.0f) {
            func_800EFB24(diff, state + 0x64, state + 0x58);
            value = func_800EEFFC(diff);
            state = *(u8 **)((u8 *)arg0 + 0xC8);
            *(f32 *)(state + 0x70) = value / *(f32 *)(state + 0x78);
        }
        state = *(u8 **)((u8 *)arg0 + 0xC8);
        *(f32 *)(state + 0x74) = 0.0;
        func_8009BA9C(arg0, 0);
        baphysics_set_target_horizontal_velocity(arg0, 0.0f);
        func_80800000_bamovegoto(arg0, 3);
        break;
    case 3:
        value = func_800D8FF8();
        state = *(u8 **)((u8 *)arg0 + 0xC8);
        *(f32 *)(state + 0x74) += value;
        state = *(u8 **)((u8 *)arg0 + 0xC8);
        progress = func_800F10B4(*(f32 *)(state + 0x74), 0.0,
                               *(f32 *)(state + 0x70), 0.0, 1.0f);
        state = *(u8 **)((u8 *)arg0 + 0xC8);
        if (*(f32 (**)(void *, f32))(state + 0x80) != 0) {
            blend = (*(f32 (**)(void *, f32))(state + 0x80))(arg0, progress);
        } else {
            blend = progress;
        }
        state = *(u8 **)((u8 *)arg0 + 0xC8);
        func_800EE7F8((s32)oldpos, (s32)(state + 4));
        state = *(u8 **)((u8 *)arg0 + 0xC8);
        *(f32 *)(*(u8 **)((u8 *)arg0 + 0xC8) + 4) =
            func_800F1214(blend, *(f32 *)(state + 0x58), *(f32 *)(state + 0x64));
        state = *(u8 **)((u8 *)arg0 + 0xC8);
        *(f32 *)(*(u8 **)((u8 *)arg0 + 0xC8) + 8) =
            func_800F1214(blend, *(f32 *)(state + 0x5C), *(f32 *)(state + 0x68));
        state = *(u8 **)((u8 *)arg0 + 0xC8);
        *(f32 *)(*(u8 **)((u8 *)arg0 + 0xC8) + 0xC) =
            func_800F1214(blend, *(f32 *)(state + 0x60), *(f32 *)(state + 0x6C));
        state = *(u8 **)((u8 *)arg0 + 0xC8);
        if (*(void (**)(void *, f32 *, f32))(state + 0x7C) != 0) {
            (*(void (**)(void *, f32 *, f32))(state + 0x7C))(arg0, (f32 *)(state + 4), progress);
        }
        state = *(u8 **)((u8 *)arg0 + 0xC8);
        func_800EFB24(state + 0x10, state + 4, oldpos);
        func_800EF334((f32 *)(*(u8 **)((u8 *)arg0 + 0xC8) + 0x10), 1.0f / func_800D8FF8());
        baphysics_set_target_horizontal_velocity(arg0,
            func_800EEF94((f32 *)(*(u8 **)((u8 *)arg0 + 0xC8) + 0x10)));
        if (progress == 1.0f) {
            func_80800000_bamovegoto(arg0, 6);
        }
        break;
    case 4:
        func_8009C128(arg0, (f32 *)(state + 0x58));
        func_80800000_bamovegoto(arg0, 5);
        break;
    case 5:
        dt = func_800D8FF8();
        state = *(u8 **)((u8 *)arg0 + 0xC8);
        func_800EFB24(velocity, state + 0x64, state + 4);
        velocity[1] = 0.0f;
        if (func_800EEFFC(velocity) <= *(f32 *)(*(u8 **)((u8 *)arg0 + 0xC8) + 0x78) * dt) {
            func_80800000_bamovegoto(arg0, 6);
        } else {
            func_800EF368(velocity, *(f32 *)(*(u8 **)((u8 *)arg0 + 0xC8) + 0x78));
        }
        *(f32 *)(*(u8 **)((u8 *)arg0 + 0xC8) + 0x10) = velocity[0];
        *(f32 *)(*(u8 **)((u8 *)arg0 + 0xC8) + 0x18) = velocity[2];
        state = *(u8 **)((u8 *)arg0 + 0xC8);
        if (state[0x56] != 0) {
            *(f32 *)(state + 0x14) += *(f32 *)(state + 0x34) * dt;
            state = *(u8 **)((u8 *)arg0 + 0xC8);
            if (*(f32 *)(state + 0x14) < *(f32 *)(state + 0x38)) {
                *(f32 *)(state + 0x14) = *(f32 *)(state + 0x38);
            }
        }
        state = *(u8 **)((u8 *)arg0 + 0xC8);
        func_800EFA20(state + 0x28, state + 0x10, dt);
        baphysics_set_target_horizontal_velocity(arg0,
            func_800EEF94((f32 *)(*(u8 **)((u8 *)arg0 + 0xC8) + 0x10)));
        state = *(u8 **)((u8 *)arg0 + 0xC8);
        func_800EF04C((f32 *)(state + 4), (f32 *)(state + 0x28));
        break;
    case 0:
    case 1:
    case 6:
        break;
    }
}
