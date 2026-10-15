#include "common.h"

OSThread *chwaspnestgame_entrypoint_0(void)
{
    extern u8 D_80801F80_chwaspnestgame[];

    return (OSThread *) D_80801F80_chwaspnestgame;
}

OSThread *chwaspnestgame_entrypoint_1(void)
{
    extern u8 D_80801FC8_chwaspnestgame[];

    return (OSThread *) D_80801FC8_chwaspnestgame;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waspnestgame/func_80800018_chwaspnestgame.s")

/* extern */

void func_808002EC_chwaspnestgame(Actor *arg0) {
    s32 _subaddiemarker_entrypoint_0(Actor *, s32, f32 *, s32);
    void _subaddiemarker_entrypoint_1(Actor *, s32, s32, f32 *, s32);
    s32 _susubgame_entrypoint_0(Actor *, u32 *, s32);
    s32 _susubgame_entrypoint_11(s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EFD24(f32 *);
    void *func_80100094(Actor *, u32);
    s32 var_s0;
    int var_s1;
    u8 *temp_s6;
    u8 *var_s1_2;
    u8 *var_s2;
    f32 sp58[3];
    u8 *var_s3;

    temp_s6 = func_80100094(arg0, 0);
    _subaddiemarker_entrypoint_0(arg0, 0x201, sp58, 1);
    func_800EE7F8((f32 *)arg0->actorData, sp58);
    for (var_s0 = 0; var_s0 * 12 < 24; var_s0++) {
        func_800EFD24((f32 *)(temp_s6 + var_s0 * 12));
        *(f32 *)(temp_s6 + 0x18 + var_s0 * 4) = -1.0f;
    }
    var_s0 = 0;
    var_s1_2 = temp_s6 + 0x3C;
    do {
        _subaddiemarker_entrypoint_1(arg0, 0x1C0, var_s0 + 0x33, sp58, 1);
        func_800EE7F8((f32 *)var_s1_2, sp58);
        var_s0 += 1;
        var_s1_2 += 12;
    } while (var_s0 != 3);
    _susubgame_entrypoint_0(arg0, (u32 *)(temp_s6 + 0x24), 0);
    _susubgame_entrypoint_11(0);
}

/* extern */

void func_80800400_chwaspnestgame(Actor *arg0) {
    s32 _susubgame_entrypoint_11(s32);
    s32 _susubgame_entrypoint_2(void *, void *);
    s32 _susubgame_entrypoint_4(void *, void *);
    u32 func_800FDC28(u32);
    void *func_80100094(Actor *, u32);
    u8 *temp_v0;
    s32 var_v1;

    temp_v0 = func_80100094(arg0, 0);
    for (var_v1 = 0; var_v1 < 2; var_v1++) {
        temp_v0[0x20 + var_v1] = 0;
    }
    _susubgame_entrypoint_11(0);
    if (_susubgame_entrypoint_2(arg0, temp_v0 + 0x24) != 0) {
        _susubgame_entrypoint_4(arg0, temp_v0 + 0x24);
    }
    func_800FDC28(0xC);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waspnestgame/func_8080047C_chwaspnestgame.s")

s32 func_80800724_chwaspnestgame(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    s32 func_800DA298(s32);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 _susubgame_entrypoint_3(Actor *, void *, u32, u32);
    void _susubgame_entrypoint_5(Actor *, void *, s32, s32, s32);
    void _susubgame_entrypoint_6(Actor *, void *, s32, s32, s32);
    void func_80800018_chwaspnestgame(Actor *, s32);
    void func_80800B80_chwaspnestgame(Actor *);
    void func_80800C7C_chwaspnestgame(Actor *, s32);
    void func_80800D7C_chwaspnestgame(Actor *, s32);
    s32 func_80800DE4_chwaspnestgame(Actor *, s32);
    s32 func_80800EB8_chwaspnestgame(void *, s32, s32);
    void func_80800F98_chwaspnestgame(Actor *, s32, s32);
    extern s16 D_80801F76_chwaspnestgame[];
    u8 *sp34;
    s32 sp30;
    s16 *sp2C;
    s32 sp28;

    sp34 = func_80100094(arg0, 0);
    switch (arg1) {
        case 0x95:
            if ((func_800D0A9C(0x4B, 1) && !func_800D0B68(0x4B, 1)) ||
                (func_800D0A9C(0x18, 4) && !func_800D0B68(0x18, 4))) {
                *(f32 *)((u8 *)arg0 + 0x58) = 0.5f;
                func_80101FDC(arg0, 5);
            } else {
                func_80090708(2);
                if (func_800D395C()) {
                    _susubgame_entrypoint_5(arg0, sp34 + 0x24, 5, 1, 0);
                    _subaddiedialog_entrypoint_11(*(Unk80132ED0 **)arg0, 0x144D, 6, 0, 0x99);
                } else if (func_800DA298(0x6E6)) {
                    _susubgame_entrypoint_5(arg0, sp34 + 0x24, 5, 1, 0);
                    sp28 = !func_800D0A9C(0x4B, 1);
                    _subaddiedialog_entrypoint_11(*(Unk80132ED0 **)arg0, -!func_800D0A9C(0x18, 4) - sp28 + 0x144B, 6, 0, 0x99);
                } else {
                    _susubgame_entrypoint_6(arg0, sp34 + 0x24, 8, 0x20, 0);
                    sp28 = !func_800D0A9C(0x4B, 1);
                    _subaddiedialog_entrypoint_11(*(Unk80132ED0 **)arg0, -!func_800D0A9C(0x18, 4) - sp28 + 0x1407, 6, 0, 0x99);
                    func_800DA544(0);
                    func_80108B04(arg0, 0);
                }
                func_80800018_chwaspnestgame(arg0, 1);
            }
            break;
        case 0x3D:
            if (arg2 > 0) {
                func_80800C7C_chwaspnestgame(arg0, arg2);
            } else if (arg2 < 0) {
                func_80800D7C_chwaspnestgame(arg0, -arg2);
            } else {
                func_80800B80_chwaspnestgame(arg0);
            }
            break;
        case 0x2E:
            sp2C = (s16 *)&arg2;
            func_80800F98_chwaspnestgame(arg0, sp2C[0], sp2C[1]);
            break;
        case 0x30:
            sp2C = (s16 *)&arg2;
            return func_80800EB8_chwaspnestgame(arg0, sp2C[0], sp2C[1]);
        case 0x2F:
            sp2C = (s16 *)&arg2;
            sp30 = sp2C[1];
            func_80101180(0x1E4, 0x45, 0);
            _susubgame_entrypoint_6(arg0, sp34 + 0x24, D_80801F76_chwaspnestgame[sp30], 0x20, 0);
            func_80108B04(arg0, -sp30);
            break;
        case 0xB:
            return func_80800DE4_chwaspnestgame(arg0, arg2);
        case 0x57:
            return _susubgame_entrypoint_3(arg0, sp34 + 0x24, arg2 & 0xFFFF, (u32)(arg2 & 0xFFFF0000) >> 16);
        case 0x96:
            if (!func_800D395C()) {
                return 0;
            }
            func_80101180(0x1E4, 0x45, 0);
            _subaddiedialog_entrypoint_11(*(Unk80132ED0 **)arg0, 0xCEB, 0x46, 0, 0x99);
            func_80101FDC(arg0, 3);
            break;
        default:
            return 0;
    }
    return 1;
}

Actor *func_80800AF8_chwaspnestgame(Actor *arg0, f32 *arg1, f32 *arg2, s32 arg3) {
    void func_800EE7F8(f32 *, f32 *);
    Actor *sp1C;
    Actor *temp_v0;
    extern u16 D_80801F70_chwaspnestgame[];

    temp_v0 = func_80108528(0x1E4, arg1, 0, &arg0);
    temp_v0->unk3C = arg0->unk0;
    sp1C = temp_v0;
    func_800EE7F8((f32 *)temp_v0->actorData, arg2);
    sp1C->unk6C_0 = arg3;
    func_80103140(sp1C, D_80801F70_chwaspnestgame[arg3], 0U);
    return sp1C;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waspnestgame/func_80800B80_chwaspnestgame.s")

/* extern */

void func_80800C00_chwaspnestgame(void *arg0, s32 arg1) {
    f32 func_800DC178(f32, f32);
    s32 func_800EF368(void *, s32);
    (*(f32 *)((s8 *)(arg0) + (0))) = func_800DC178(-100.0f, 100.0f);
    (*(f32 *)((s8 *)(arg0) + (4))) = func_800DC178(-100.0f, 100.0f);
    (*(f32 *)((s8 *)(arg0) + (8))) = func_800DC178(-100.0f, 100.0f);
    func_800EF368(arg0, arg1);
}

/* extern */

void func_80800C7C_chwaspnestgame(Actor *arg0, s32 arg1) {
    void func_800EE7B4(f32[3], f32[3], f32[3], f32);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF3DC(f32 *, f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    s32 func_800F0734(f32 *, f32 *, f32 *, f32, f32, f32 *, f32 *);
    s32 sp7C;
    f32 sp70[3];
    f32 sp64[3];
    f32 sp58[3];
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];
    f32 sp28[3];

    func_80800C00_chwaspnestgame(sp40, 0x43FA0000);
    sp40[1] += 1950.0f;
    func_80800C00_chwaspnestgame(sp34, 0x42C80000);
    func_800EE7B4(sp64, sp40, sp34, 100.0f);
    func_800EE7B4(sp70, sp40, sp34, -100.0f);
    func_800EFA4C(sp28, 0.0f, -600.0f, 0.0f);
    if (func_800F0734(sp70, sp64, sp28, 4000.0f, 5100.0f, sp58, sp4C) != 0) {
        func_800EF3DC(sp58, sp34);
        func_800EF04C(sp4C, sp34);
        func_80800AF8_chwaspnestgame(arg0, sp58, sp4C, arg1);
        arg0->actorData[7]++;
    }
}

/* extern */

void func_80800D7C_chwaspnestgame(Actor *arg0, s32 arg1) {
    void func_800EE7F8(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    s32 sp34;
    f32 sp28[3];
    f32 sp1C[3];

    func_800EE7F8(sp28, (f32 *)((u8 *)func_80100094(arg0, 0U) + arg1 * 0xC + 0x30));
    func_800EE7F8(sp1C, sp28);
    func_80800AF8_chwaspnestgame(arg0, sp28, sp1C, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waspnestgame/func_80800DE4_chwaspnestgame.s")

s32 func_80800EB8_chwaspnestgame(void *arg0, s32 arg1, s32 arg2) {
    s32 func_800D211C(s32);

    switch (arg1) {
        case 0x1405:
        case 0x1449:
            return arg2 ? 0x32 : 0x28;
        case 0x1406:
        case 0x144A:
            return 0x32;
        case 0x1409:
            return 0x3C;
        case 0x140E:
        case 0x144C:
            return *(s32 *)((u8 *)arg0 + 0x24);
        case 0x140F:
        case 0x1450:
            if (arg2 == 0) {
                return *(s32 *)((u8 *)arg0 + 0x24);
            }
        default:
            return func_800D211C(0x87);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waspnestgame/func_80800F98_chwaspnestgame.s")

/* extern */

void func_80801260_chwaspnestgame(Unk80132ED0 *arg0, s32 arg1) {
    void *func_80106790();
    void *temp_v0;

    temp_v0 = func_80106790(arg0);
    (*(s32 *)((s8 *)(temp_v0) + (0x24))) = (s32) ((*(s32 *)((s8 *)(temp_v0) + (0x24))) + arg1);
    (*(s32 *)((s8 *)(temp_v0) + (0x34))) = (s32) ((*(s32 *)((s8 *)(temp_v0) + (0x34))) - 1);
}

/* extern */

void func_8080129C_chwaspnestgame(void) {
    void *func_80106790();
    void *temp_v0;

    temp_v0 = func_80106790();
    (*(s32 *)((s8 *)(temp_v0) + (0x34))) = (s32) ((*(s32 *)((s8 *)(temp_v0) + (0x34))) - 1);
}

void func_808012C8_chwaspnestgame(s32 arg0) 
{
}
/* extern */

void func_808012D0_chwaspnestgame(void *arg0) {
    s32 func_80102BF8(void *, s32, s32, s32);
    f32 func_80102D78(void *, s32 *);
    s32 func_8010D600(s32 *);
    s32 sp1C[3];

    func_8010D600(sp1C);
    (*(f32 *)((s8 *)(arg0) + (0x54))) = func_80102D78(arg0, sp1C);
    func_80102BF8(arg0, 0x3DCCCCCD, 0x40800000, 0x43340000);
    func_808012C8_chwaspnestgame((s32) arg0);
}

void func_80801324_chwaspnestgame(f32 *arg0, f32 arg1, f32 arg2) {
    void func_800EF334(f32 vec[3], f32 scale);
    if (arg1 != 0.0f) {
        func_800EF334(arg0, arg2 / arg1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waspnestgame/func_80801364_chwaspnestgame.s")

/* extern */

void func_808014BC_chwaspnestgame(Actor *arg0, f32 *arg1) {
    f32 func_800D8FF8(void);
    f32 dt;
    struct {
        u32 unk0[4];
        f32 x;
        f32 y;
        f32 z;
    } *velocity;

    dt = func_800D8FF8();
    velocity = (void *)arg0->actorData;
    arg0->position[0] += velocity->x * dt + arg1[0] * dt * dt;
    arg0->position[1] += velocity->y * dt + arg1[1] * dt * dt;
    arg0->position[2] += velocity->z * dt + arg1[2] * dt * dt;
    velocity->x += arg1[0] * dt;
    velocity->y += arg1[1] * dt;
    velocity->z += arg1[2] * dt;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waspnestgame/func_80801590_chwaspnestgame.s")

/* extern */

s32 func_808017DC_chwaspnestgame(Actor *arg0, f32 arg1, s32 arg2) {
    s32 func_800BEF00(f32[3], f32[3], f32[3], s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    struct {
        f32 sp24[3];
        f32 sp30[3];
        f32 sp3C[3];
    } vectors;

    func_800EFA4C(vectors.sp3C, 0.0f, -arg1, 0.0f);
    func_800EE7F8(vectors.sp30, arg0->position);
    func_808014BC_chwaspnestgame(arg0, vectors.sp3C);
    return arg2 ? (func_800BEF00(vectors.sp30, arg0->position, vectors.sp24, 0x20020) ? 1 : 0) : 0;
}

/* extern */

void func_80801880_chwaspnestgame(Actor *arg0, f32 arg1, f32 arg2, f32 arg3) {
    f32 func_800138D0(f32);
    f32 func_80013970(f32);
    f32 func_800D8FF8(void);
    f32 temp_f0;
    struct Motion {
        f32 origin[3];
        f32 angle;
        f32 scale[3];
        f32 phase;
    };

    temp_f0 = func_800D8FF8();
    ((struct Motion *)arg0->actorData)->phase += arg2 * temp_f0;
    ((struct Motion *)arg0->actorData)->angle += arg3 * temp_f0;
    arg0->position[0] = ((struct Motion *)arg0->actorData)->origin[0] + (((struct Motion *)arg0->actorData)->scale[0] * arg1) * func_800138D0(((struct Motion *)arg0->actorData)->phase);
    arg0->position[2] = ((struct Motion *)arg0->actorData)->origin[2] + (((struct Motion *)arg0->actorData)->scale[2] * arg1) * func_800138D0(((struct Motion *)arg0->actorData)->phase);
    arg0->position[1] = ((struct Motion *)arg0->actorData)->origin[1] + (((struct Motion *)arg0->actorData)->scale[1] * arg1) * func_80013970(((struct Motion *)arg0->actorData)->angle);
}

/* extern */

void func_80801954_chwaspnestgame(s32 arg0) {
    s32 func_800DA298(s32);
    f32 func_800EEB40(s32, s32);
    s32 func_8010A570(s32);
    s32 func_80801364_chwaspnestgame(s32, s32);
    if (func_800EEB40(arg0 + 0x18, arg0 + 4) > 1.0f) {
        func_80801364_chwaspnestgame(arg0, 2);
    } else {
        func_80801364_chwaspnestgame(arg0, 1);
    }
    if (func_800DA298(0) != 0) {
        func_8010A570(arg0);
    }
}

/* extern */

void func_808019D4_chwaspnestgame(Actor *arg0) {
    s32 func_8010DCB4(s32);
    u32 temp_t6;

    temp_t6 = (u32) arg0->unk70_10;
    if ((temp_t6 == 2) || (temp_t6 == 5)) {
        func_8010DCB4(0xA);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waspnestgame/func_80801A10_chwaspnestgame.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waspnestgame/func_80801B9C_chwaspnestgame.s")

void func_80801CE4_chwaspnestgame(Actor *arg0) {
    void func_800F1A88(f32 *, f32 *);
    f32 sp18[2];

    func_800F1A88((f32 *)((s8 *)arg0 + 0x28), sp18);
    arg0->rotation[0] = -sp18[0];
    arg0->rotation[1] = sp18[1];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waspnestgame/func_80801D28_chwaspnestgame.s")
