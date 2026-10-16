#include "common.h"

void *func_80100094(Actor *, u32);

OSThread *chstatueboss_entrypoint_0(void)
{
    extern u8 D_80802748_chstatueboss[];

    return (OSThread *) D_80802748_chstatueboss;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statueboss/func_8080000C_chstatueboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statueboss/func_80800298_chstatueboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statueboss/func_80800934_chstatueboss.s")

void func_80800B74_chstatueboss(Actor *arg0, s32 arg1)
{
  void func_800DF744(s32, s32);
  s32 func_80101870(s32, s32);
  s32 var_s0;
  u8 *var_s1;
  var_s1 = 1 + ((u8 *) func_80100094(arg0, 0U));
  var_s0 = 1;
  var_s1 += 0;
  do
  {
    func_800DF744(var_s0, *var_s1);
    var_s0 += 1;
    var_s1 += 1;
  }
  while (var_s0 != 0x16);
  func_80101870((s32) arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statueboss/func_80800BE0_chstatueboss.s")

void func_80800D30_chstatueboss(Actor *arg0) {
    extern s16 D_808025C0_chstatueboss[][6];
    s32 index;
    s32 i;
    s32 offset;
    u8 *data;

    data = func_80100094(arg0, 0U);
    index = *(s16 *)(data + 0x84);
    for (i = 0; D_808025C0_chstatueboss[index][i] != -1; i++) {
        offset = D_808025C0_chstatueboss[index][i];
        data[offset] = 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statueboss/func_80800DA8_chstatueboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statueboss/func_808010A0_chstatueboss.s")

s32 func_808011A0_chstatueboss(s32 arg0) {
    extern s16 D_808027D4_chstatueboss[];
    return ((s16 *)&D_808027D4_chstatueboss)[arg0];
}

void func_808011B4_chstatueboss(Actor *arg0) {
    f32 func_800136E4(f32);
    f32 func_800D8FF8(void);
    extern f32 D_80802630_chstatueboss[];
    extern f32 D_80802644_chstatueboss[];
    typedef struct {
        u8 pad[0x70];
        f32 angles[5];
        s16 index;
    } StatueData;
    int temp_v1;
    StatueData *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    for (temp_v1 = temp_v0->index; temp_v1 < 5; temp_v1++) {
        temp_v0->angles[temp_v1] += func_800D8FF8() * D_80802630_chstatueboss[temp_v1];
        temp_v0->angles[temp_v1] = func_800136E4(temp_v0->angles[temp_v1]);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statueboss/func_8080124C_chstatueboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statueboss/func_80801320_chstatueboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statueboss/func_80801448_chstatueboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statueboss/func_80801518_chstatueboss.s")

void func_80801640_chstatueboss(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    extern s16 D_80802624_chstatueboss[];
    s8 *data;
    s32 offset;

    data = func_80100094(arg0, 0U);
    offset = D_80802624_chstatueboss[arg1];
    data[offset] = (s8)arg2;
}

OSThread *chstatueboss_entrypoint_1(void)
{
    extern u8 D_808027E8_chstatueboss[];

    return (OSThread *) D_808027E8_chstatueboss;
}

s32 func_80801694_chstatueboss(Actor *arg0) {
    extern s16 D_808025C0_chstatueboss[][6];
    struct StatueBossData {
        u8 pad[0x84];
        s16 index;
    } *data;
    s32 i;
    s16 index;
    s32 offset;
    s32 flags;

    data = func_80100094(arg0, 0U);
    index = data->index;
    flags = 0;
    for (i = 0; D_808025C0_chstatueboss[index][i] != -1; i++) {
        offset = D_808025C0_chstatueboss[index][i];
        if (((u8 *)data)[offset] == 1) {
            flags |= 1 << (offset + 0x1F);
        }
    }
    return -1 ^ flags;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statueboss/func_80801724_chstatueboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statueboss/func_80801804_chstatueboss.s")

void func_80801A6C_chstatueboss(Actor *arg0, f32 arg1) {
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    void func_80018820(s32, f32, f32);
    s32 func_800E15CC(s32, f32, f32);
    extern u32 D_80802790_chstatueboss;
    if (_subaddieaudioquick_entrypoint_3(arg0, (f32 *) ((u8 *) arg0 + 4), &D_80802790_chstatueboss, arg1) != 0) {
        func_800E15CC(0, 20.0f, 0.8f);
        func_80018820(0, 3.0f, 0.25f);
    }
}

void func_80801AC4_chstatueboss(s32 arg0, s32 arg1) {
    s32 _subaddieaudioloop_entrypoint_4(Actor*, f32*, u32, u32*);
    extern u32 D_808027F8_chstatueboss;
    _subaddieaudioloop_entrypoint_4((Actor *) arg0, (f32 *) ((u8 *) arg0 + 4), arg1, &D_808027F8_chstatueboss);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statueboss/func_80801AF0_chstatueboss.s")

void func_80801C78_chstatueboss(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    extern s32 D_80802850_chstatueboss;
    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80802850_chstatueboss);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statueboss/func_80801CA0_chstatueboss.s")

void func_80801E24_chstatueboss(Actor *arg0, u32 arg1, u32 arg2) {
    void _capod_entrypoint_13(Unk80132ED0*, Unk80132ED0*, u32, u32);
    void _capod_entrypoint_14(void);
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    sp1C = temp_v0;
    if ((*(u8 *)((s8 *)(temp_v0) + (0x1CD))) != 0) {
        arg2 |= 0x2000;
        _capod_entrypoint_14();
    }
    _capod_entrypoint_13(arg0->unk0, NULL, arg1, arg2);
    (*(s8 *)((s8 *)(sp1C) + (0x1CD))) = 1;
}

void func_80801E90_chstatueboss(Actor *arg0) {
    void _capod_entrypoint_14(void);
    u8 *sp1C[1];
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    if ((*(u8 *)((s8 *)(temp_v0) + (0x1CD))) != 0) {
        sp1C[0] = temp_v0;
        _capod_entrypoint_14();
        temp_v0 = sp1C[0];
        (*(s8 *)((s8 *)(temp_v0) + (0x1CD))) = 0;
    }
}

void func_80801ECC_chstatueboss(Actor *arg0) {
    typedef struct {
        u8 pad0[0x84];
        s16 index;
        u8 pad86[0xA];
        f32 position[3];
        f32 yaw;
    } StatueBossData;
    s32 func_800DA298(s32);
    Actor *func_80108528(s32, f32[3], s32, Actor **);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    extern f32 D_8080264C_chstatueboss[];
    extern u8 D_80802668_chstatueboss[];
    StatueBossData *sp1C;
    Actor *sp18;
    StatueBossData *temp_v0;
    Actor *temp_v0_2;

    temp_v0 = func_80100094(arg0, 0U);
    sp1C = temp_v0;
    temp_v0_2 = func_80108528(0x448, temp_v0->position, (s32) temp_v0->yaw, &arg0);
    temp_v0_2->rotation[1] = sp1C->yaw;
    sp18 = temp_v0_2;
    if (func_800DA298(0x682) == 0) {
        *(f32 *)&sp18->actorData[3] = D_8080264C_chstatueboss[sp1C->index];
    } else {
        *(f32 *)&sp18->actorData[3] = 10000.0f;
    }
    _subaddieaudioquick_entrypoint_2(arg0, sp1C->position, D_80802668_chstatueboss);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statueboss/func_80801F74_chstatueboss.s")

void func_808020EC_chstatueboss(Actor *arg0) {
    void func_80102FDC(Actor*, f32);
    Actor* func_801084B0(s32, Actor**);
    u8 *sp1C;
    Actor *sp18;
    Actor *temp_v0;

    sp1C = func_80100094(arg0, 0U);
    temp_v0 = func_801084B0(0x44F, &arg0);
    sp18 = temp_v0;
    func_80102FDC(temp_v0, arg0->scale);
    (*(Unk80132ED0 **)((s8 *)(sp1C) + (0x8C))) = (Unk80132ED0 *) sp18->unk0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statueboss/func_80802144_chstatueboss.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/statueboss/func_80802268_chstatueboss.s")

void func_8080232C_chstatueboss(Actor *arg0) {
    s32 _subaddieskeleton_entrypoint_0(Actor *, s32, f32 *);
    void _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
    void func_800EF1B8(f32 *, f32, f32);
    f32 func_800F1DF4(f32 *, f32 *);
    f32 position[3];

    if (_subaddieskeleton_entrypoint_0(arg0, 0x1E, position)) {
        func_800EF1B8(position, func_800F1DF4(arg0->position, position), 80.0f);
        position[1] = arg0->position[1];
        _sudeflect_entrypoint_1(position, 300.0f, -50.0f, 250.0f, 2);
    }
    if (_subaddieskeleton_entrypoint_0(arg0, 0x10, position)) {
        func_800EF1B8(position, func_800F1DF4(arg0->position, position), 80.0f);
        position[1] = arg0->position[1];
        _sudeflect_entrypoint_1(position, 300.0f, -50.0f, 250.0f, 2);
    }
}
