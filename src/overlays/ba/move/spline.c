#include "common.h"

struct Unk800C7A68; typedef struct { u8 pad0[0xC8]; union { u8 * unkC8; void * unkC8_voidp; }; } Objspline_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void func_80800000_bamovespline(u8 *arg0) {
    f32 func_800D8840(s32);
    f32 func_800D8FF8(void);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EEB9C(f32 dst[3], f32 angle, f32 distance);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    void func_800EF3DC(f32 dst[3], f32 src[3]);
    void func_800EFA20(void *, void *, f32);
    s32 func_800F2168(u8 *, s32);
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];
    f32 sp28[3];
    u8 *temp_v0;

    temp_v0 = (((Objspline_arg0 *)arg0)->unkC8);
    func_800EEB9C((f32 *)(temp_v0 + 0x1C), *(f32 *)(temp_v0 + 0x40), *(f32 *)(temp_v0 + 0x3C));
    sp34[0] = *(f32 *)(*(u8 **)(arg0 + 0xC8) + 0x10);
    sp34[1] = 0.0f;
    sp34[2] = *(f32 *)(*(u8 **)(arg0 + 0xC8) + 0x18);
    func_800EE7F8(sp28, (f32 *)(*(u8 **)(arg0 + 0xC8) + 0x1C));
    sp28[1] = 0.0f;
    func_800EFA20(sp4C, sp28, func_800D8840(2));
    func_800EFA20(sp40, sp34, func_800D8840(2));
    func_800EF3DC(sp4C, sp40);
    func_800EF334(sp4C, func_800D8FF8() * 30.0f);
    func_800EF04C((f32 *)(*(u8 **)(arg0 + 0xC8) + 0x10), sp4C);
    func_800F2168((((Objspline_arg0 *)arg0)->unkC8) + 0x10, 0x38D1B717);
}

void func_808000F4_bamovespline(void *arg0, s32 arg1) {
    void func_8009C128(void *, f32[3]);
    switch (arg1) {
        case 2:
        case 4:
            break;
        case 1:
            (((Objspline_arg0 *)arg0)->unkC8)[0x91] = 0;
            (((Objspline_arg0 *)arg0)->unkC8)[0x92] = 0;
            *(f32 *)(((Objspline_arg0 *)arg0)->unkC8 + 0xA8) = 0.0f;
            break;
        case 3:
            func_8009C128(arg0, (f32 *)(((Objspline_arg0 *)arg0)->unkC8 + 0x9C));
            break;
    }
    (((Objspline_arg0 *)arg0)->unkC8)[0x90] = arg1;
}    typedef struct { u8 pad0[0x90]; u8 unk90; u8 pad91[0x3]; s16 unk94; } Objspline_bamovespline_entrypoint_0_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

void bamovespline_entrypoint_0(void *arg0, f32 *arg1) {
    void func_800C810C(void *, f32, f32 *, f32 *);
    void *func_800D7520(s32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    f32 sp20[4];
    void *temp_v0;

    temp_v0 = (((Objspline_arg0 *)arg0)->unkC8_voidp);
    if ((((Objspline_bamovespline_entrypoint_0_temp_v0 *)temp_v0)->unk90) == 4) {
        func_800C810C(func_800D7520((((Objspline_bamovespline_entrypoint_0_temp_v0 *)temp_v0)->unk94)), (*(f32 *)((s8 *)((((Objspline_arg0 *)arg0)->unkC8_voidp)) + (0x98))), arg1, sp20);
        return;
    }
    func_800EFA4C(arg1, 0.0f, 1.0f, 0.0f);
}    typedef struct { u8 pad0[0x90]; u8 unk90; u8 pad91[0x3]; s16 unk94; u8 pad96[0x12]; f32 unkA8; } Objspline_bamovespline_entrypoint_1_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

int bamovespline_entrypoint_1(void *arg0, f32 arg1) {
    struct Unk800C7A68 *sp34;
    f32 sp28[3];
    f32 sp1C[3];
    void *temp_v0;
    void *func_800D7520(s32);
    void func_800C7A68(struct Unk800C7A68 *, f32, f32 *);
    f32 func_800EEB40(f32 *, f32 *);

    temp_v0 = ((Objspline_arg0 *)arg0)->unkC8_voidp;
    if (((Objspline_bamovespline_entrypoint_1_temp_v0 *)temp_v0)->unk90 != 4) {
        return 0;
    }
    if (((Objspline_bamovespline_entrypoint_1_temp_v0 *)temp_v0)->unkA8 >= 0.0f) {
        return 0;
    }
    sp34 = func_800D7520(((Objspline_bamovespline_entrypoint_1_temp_v0 *)temp_v0)->unk94);
    func_800C7A68(sp34, *(f32 *)(((Objspline_arg0 *)arg0)->unkC8 + 0x98), sp28);
    func_800C7A68(sp34, 0.0f, sp1C);
    return func_800EEB40(sp28, sp1C) < arg1 * arg1;
}

u32 bamovespline_entrypoint_2(void *arg0) {
    return *(u8 *)((u8 *)*&((Objspline_arg0 *)arg0)->unkC8_voidp + 145);
}

u32 bamovespline_entrypoint_3(void *arg0) {
    return *(u8 *)((u8 *)*&((Objspline_arg0 *)arg0)->unkC8_voidp + 146);
}

s32 bamovespline_entrypoint_4(void *arg0) {
    return (*(u8 *)((s8 *)((((Objspline_arg0 *)arg0)->unkC8_voidp)) + (0x90))) == 4;
}

void bamovespline_entrypoint_5(BtIntPtr arg0) 
{
}
void bamovespline_entrypoint_6(void *arg0) { (*(s8 *)(((Objspline_arg0 *)arg0)->unkC8 + 0x90)) = 0; func_808000F4_bamovespline(arg0, 1); }

void bamovespline_entrypoint_7(void *arg0, s32 arg1) {
    *(s16 *)((u8 *)*&((Objspline_arg0 *)arg0)->unkC8_voidp + 148) = arg1;
}

void bamovespline_entrypoint_8(BtIntPtr arg0)
{
    func_808000F4_bamovespline(arg0,0x2);
}

void bamovespline_entrypoint_9(void *arg0, f32 arg1) {
    (*(f32 *)((s8 *)(((Objspline_arg0 *)arg0)->unkC8_voidp) + 0x98)) = arg1;
    func_808000F4_bamovespline(arg0, 4);
}

struct player_state_s;
void func_80800374_bamovespline(void *arg0) {
    void baphysics_set_target_yaw(struct player_state_s *, f32);
    f32 bastick_distance(struct player_state_s *);
    f32 bastick_getAngleRelativeToBanjo(struct player_state_s *);
    f32 func_800136E4(f32);
    void func_800C7A68(struct Unk800C7A68 *, f32, f32 *);
    void *func_800D7520(s32);
    f32 func_800D8FF8(void);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EEAD4(f32 *, f32 *);
    f32 func_800EEFFC(void *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    void func_800EF368(f32 *, f32);
    void func_800EFB24(void *, void *, void *);
    f32 func_800F1DCC(f32, f32);
    f32 func_800F1DF4(f32 *, f32 *);
    f32 mlAbsF(f32);
    f32 speed;
    f32 pad;
    f32 yaw;
    f32 diff;
    f32 next[3];
    f32 previous[3];
    void *spline;
    spline = func_800D7520(*(s16 *)(((Objspline_arg0 *)arg0)->unkC8 + 0x94));
    func_800EE7F8(previous, (f32 *)(((Objspline_arg0 *)arg0)->unkC8 + 0x9C));
    func_800C7A68(spline, *(f32 *)(((Objspline_arg0 *)arg0)->unkC8 + 0x98), next);
    yaw = func_800F1DF4(previous, next);
    if (bastick_distance(arg0) != 0.0f) {
        f32 stick_yaw;
        stick_yaw = bastick_getAngleRelativeToBanjo(arg0);
        if (mlAbsF(func_800F1DCC(yaw, stick_yaw)) < 90.0f) {
            baphysics_set_target_yaw(arg0, yaw);
        } else {
            baphysics_set_target_yaw(arg0, func_800136E4(yaw + 180.0f));
        }
    }
    func_80800000_bamovespline(arg0);
    diff = func_800F1DCC(yaw, *(f32 *)(((Objspline_arg0 *)arg0)->unkC8 + 0x40));
    *(s8 *)(((Objspline_arg0 *)arg0)->unkC8 + 0x92) = mlAbsF(diff) > 40.0f;
    speed = func_800EEFFC(((Objspline_arg0 *)arg0)->unkC8 + 0x10) * func_800D8FF8();
    *(f32 *)(((Objspline_arg0 *)arg0)->unkC8 + 0xA8) = speed;
    func_800EFB24(((Objspline_arg0 *)arg0)->unkC8 + 0x28, next, previous);
    func_800EF368((f32 *)(((Objspline_arg0 *)arg0)->unkC8 + 0x28), speed);
    if (mlAbsF(diff) > 90.0f) {
        func_800EF334((f32 *)(((Objspline_arg0 *)arg0)->unkC8 + 0x28), -1.0f);
    }
    func_800EF04C((f32 *)(((Objspline_arg0 *)arg0)->unkC8 + 4), (f32 *)(((Objspline_arg0 *)arg0)->unkC8 + 0x28));
    if (func_800EEAD4(next, previous) < func_800EEAD4((f32 *)(((Objspline_arg0 *)arg0)->unkC8 + 4), previous)) {
        func_808000F4_bamovespline(arg0, 4);
    }
}

struct player_state_s;
void func_8080057C_bamovespline(void *arg0) {
    void baphysics_set_target_yaw(struct player_state_s *, f32);
    f32 bastick_distance(struct player_state_s *);
    f32 bastick_getAngle(struct player_state_s *);
    f32 func_8009BB18(void *);
    void func_800C7A68(struct Unk800C7A68 *, f32, f32 *);
    f32 func_800C7FD4(u8 *, f32, f32);
    void *func_800D7520(s32);
    f32 func_800EEFFC(void *);
    void func_800EFB24(void *, void *, void *);
    f32 speed;
    f32 previous[3];
    void *spline;

    if (bastick_distance(arg0) != 0.0f) {
        baphysics_set_target_yaw(arg0, bastick_getAngle(arg0));
    }
    func_80800000_bamovespline(arg0);
    spline = func_800D7520(*(s16 *)(((Objspline_arg0 *)arg0)->unkC8 + 0x94));
    func_800C7A68(spline, *(f32 *)(((Objspline_arg0 *)arg0)->unkC8 + 0x98), previous);
    speed = func_800EEFFC(((Objspline_arg0 *)arg0)->unkC8 + 0x10);
    if (func_8009BB18(arg0) > 180.0f) {
        speed = -speed;
    }
    *(f32 *)(((Objspline_arg0 *)arg0)->unkC8 + 0x98) = func_800C7FD4(spline, *(f32 *)(((Objspline_arg0 *)arg0)->unkC8 + 0x98), speed);
    *(f32 *)(((Objspline_arg0 *)arg0)->unkC8 + 0xA8) = speed;
    (((Objspline_arg0 *)arg0)->unkC8)[0x91] = speed > 0.0f && 1.0f == *(f32 *)(((Objspline_arg0 *)arg0)->unkC8 + 0x98);
    (((Objspline_arg0 *)arg0)->unkC8)[0x92] = speed < 0.f && 0.00f == *(f32 *)(((Objspline_arg0 *)arg0)->unkC8 + 0x98);
    func_800C7A68(spline, *(f32 *)(((Objspline_arg0 *)arg0)->unkC8 + 0x98), (f32 *)(((Objspline_arg0 *)arg0)->unkC8 + 4));
    func_800EFB24(((Objspline_arg0 *)arg0)->unkC8 + 0x28, ((Objspline_arg0 *)arg0)->unkC8 + 4, previous);
}

void bamovespline_entrypoint_10(void *arg0) {
    void *func_800D7520(s32);
    f32 func_800C82CC(void *, f32 *);
    void func_8009C128(void *, f32[3]);
    f32 sp2C[3];
    s32 pad[2];
    switch ((((Objspline_arg0 *)arg0)->unkC8)[0x90]) {
    case 2:
        func_8009C128(arg0, sp2C);
        *(f32 *)(((Objspline_arg0 *)arg0)->unkC8 + 0x98) = func_800C82CC(func_800D7520(*(s16 *)(((Objspline_arg0 *)arg0)->unkC8 + 0x94)), sp2C);
        func_808000F4_bamovespline(arg0, 3);
        break;
    case 3:
        func_80800374_bamovespline(arg0);
        break;
    case 4:
        func_8080057C_bamovespline(arg0);
        break;
    }
}
