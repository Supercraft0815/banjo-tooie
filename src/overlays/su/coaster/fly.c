#include "su/coasterfly.h"

OSThread *sucoasterfly_entrypoint_0(void)
{
    extern u8 D_80802280_sucoasterfly[];

    return (OSThread *) D_80802280_sucoasterfly;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/fly/sucoasterfly_entrypoint_1.s")

void sucoasterfly_entrypoint_2(Actor* arg0)
{
    func_80802128_sucoasterfly(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/fly/sucoasterfly_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/fly/sucoasterfly_entrypoint_4.s")

void func_80800EF0_sucoasterfly(Unk80132ED0 *arg0, u8 *arg1)
{
  Actor *func_80106790(Unk80132ED0 *);
  s32 func_808014AC_sucoasterfly(Actor *, s32);
  Actor *temp_a0;
  Actor *temp_v0;
  temp_v0 = func_80106790(arg0);
  temp_a0 = temp_v0;
  if (((((u32) ((*((u32 *) (((s8 *) arg1) + 0x24))) ^ 0)) >> 0x16) == 0) && (((((u16) (*((u16 *) (((s8 *) temp_v0) + 0x72)))) & 0xFFFFFFFF) >> 0xA) == 6))
  {
    func_808014AC_sucoasterfly(temp_a0, 7);
  }
}

/* extern */

void func_80800F44_sucoasterfly(Unk80132ED0 *arg0, s32 arg1) {
    int func_801021BC(Actor *, s32);
    Actor *func_80106790(Unk80132ED0 *);
    s32 func_808014AC_sucoasterfly(Actor *, s32);
    Actor *temp_v0;
    Actor *sp1C;
    u32 flags;

    temp_v0 = func_80106790(arg0);
    if (temp_v0->unk70_10 != 0xA) {
        flags = temp_v0->pad7A_0;
        if (((s32)(flags << 29) >> 31) == 0) {
        sp1C = temp_v0;
        if (func_801021BC(temp_v0, 0xA) != 0) {
            func_808014AC_sucoasterfly(sp1C, 0xA);
        }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/fly/func_80800FA8_sucoasterfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/fly/func_80801108_sucoasterfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/fly/func_808014AC_sucoasterfly.s")

void *func_80100094(Actor *, u32);

void func_8080181C_sucoasterfly(Actor *arg0) {
    f32 func_800F0E00(f32, f32);
    f32 func_800F15F8(f32, f32, f32);
    f32 func_80107C00(void);
    f32 *sp1C;
    volatile f32 sp18;
    f32 speed;
    f32 current;
    f32 initial;

    sp1C = func_80100094(arg0, 0);
    initial = sp1C[3];
    current = ((f32 *)arg0->actorData)[3];
    if (initial < current) {
        speed = func_800F0E00(current, 10.0f);
    } else {
        speed = initial;
    }
    sp18 = speed * 0.1f;
    ((f32 *)arg0->actorData)[3] = func_800F15F8(((f32 *)arg0->actorData)[3], sp1C[3], func_80107C00() * sp18);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/fly/func_808018BC_sucoasterfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/fly/func_808019A0_sucoasterfly.s")

/* extern */

void func_80801A80_sucoasterfly(s32 arg0) {
    s32 func_800F54E4();
    s32 func_800F5BF0(s32, s32);
    func_800F5BF0(func_800F54E4(), arg0 + 0x18);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/fly/func_80801AB0_sucoasterfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/fly/func_80801B90_sucoasterfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/fly/func_80801C44_sucoasterfly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/fly/func_80801CD0_sucoasterfly.s")

s32 func_80801DD0_sucoasterfly(Actor *arg0) {
    s32 _subaddiejoy_entrypoint_6(u8 *, s32);
    int func_800F20BC(f32, f32, f32);
    int func_801021BC(Actor *, s32);
    f32 func_8010CD28(Actor *);
    s32 func_808014AC_sucoasterfly(Actor *, s32);

    if (func_800F20BC(arg0->rotation[1], func_8010CD28(arg0), 20.0f) != 0 &&
        _subaddiejoy_entrypoint_6((u8 *)arg0, 1) == 1) {
        if (func_801021BC(arg0, 5) != 0) {
            func_808014AC_sucoasterfly(arg0, 5);
            return 1;
        }
        func_808014AC_sucoasterfly(arg0, 6);
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/coaster/fly/func_80801E5C_sucoasterfly.s")

s32 func_80801FE4_sucoasterfly(Actor *arg0, f32 *arg1, f32 arg2, f32 arg3) {
    s32 func_800BEF00(f32[3], f32[3], f32[3], s32);
    void func_800EE7F8(f32 *, f32 *);
    f32 sp34[3];
    f32 sp28[3];
    f32 sp1C[3];

    func_800EE7F8(sp34, arg0->position);
    func_800EE7F8(sp28, arg0->position);
    sp34[1] += arg2;
    sp28[1] += arg3;
    if (func_800BEF00(sp34, sp28, sp1C, arg0->unk14) != 0) {
        *arg1 = sp28[1];
        return 1;
    }
    return 0;
}

/* extern */

void func_80802080_sucoasterfly(Actor *arg0) {
    typedef struct {
        u8 pad0[0x11];
        u8 track;
    } CoasterFlyData;
    typedef struct {
        u8 pad0[2];
        union {
            s16 id;
            u8 bytes[2];
        } expression;
    } TrackData;
    void *_sucoasterflydata_entrypoint_1(u32);
    s32 _suexpression_entrypoint_1(u8);
    s32 _suexpression_entrypoint_12(void *, s32, s32);
    s32 _suexpression_entrypoint_17(void *, s32);
    s32 _suexpression_entrypoint_7(Actor *, s32, s32);
    s32 pad;
    TrackData *sp20;

    sp20 = _sucoasterflydata_entrypoint_1((u32)((CoasterFlyData *)func_80100094(arg0, 0U))->track >> 4);
    if ((func_80100094(arg0, 1U) == NULL) && (_suexpression_entrypoint_1(sp20->expression.bytes[1]) != 0)) {
        _suexpression_entrypoint_7(arg0, 1, sp20->expression.id);
        _suexpression_entrypoint_12(func_80100094(arg0, 1U), 0x42480000, 0x42200000);
        _suexpression_entrypoint_17(func_80100094(arg0, 1U), 0x7D0);
    }
}

void func_80802128_sucoasterfly(Actor* arg0) 
{
    if (func_80100094(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
void func_8080215C_sucoasterfly(Actor *arg0) {
    if (func_80100094(arg0, 1U) != NULL) {
        _suexpression_entrypoint_18(func_80100094(arg0, 1U), 1);
    }
}

u8 *sucoasterfly_entrypoint_5(Actor *arg0) {
    return (u8 *)func_80100094(arg0, 0U) + 0x1C;
}

void sucoasterfly_entrypoint_6()
{
    func_80101870();
}
