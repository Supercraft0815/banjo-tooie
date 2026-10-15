#include "common.h"

OSThread *chlaundry_entrypoint_0(void)
{
    extern u8 D_80800400_chlaundry[];

    return (OSThread *) D_80800400_chlaundry;
}

/* extern */

f32 func_8080000C_chlaundry(Actor *arg0) {
    s32 func_800A940C(s32);
    f32 func_800C5190(s32);
    void *func_80100094(Actor *, u32);
    f32 temp_f0;
    f32 var_f2;

    temp_f0 = func_800C5190(func_800A940C(*(u8 *) func_80100094(arg0, 0)));
    var_f2 = temp_f0;
    if (temp_f0 > 2.0f) {
        var_f2 = 2.0f;
    }
    return var_f2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/laundry/func_80800058_chlaundry.s")

/* extern */

void func_80800218_chlaundry(Actor *arg0) {
    f32 func_800D8FF8(void);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    void func_80800058_chlaundry(Actor *, f32);
    void func_808003A0_chlaundry(u8 *volatile);
    f32 sp24;
    f32 sp20;
    struct {
        u8 unk0;
        u8 unk1;
        f32 unk4;
    } *sp1C;

    sp1C = func_80100094(arg0, 0);
    sp24 = sp1C->unk4;
    sp20 = func_800D8FF8();
    func_80800058_chlaundry(arg0, sp20);
    sp1C->unk4 = sp24 + sp20;
    if (sp1C->unk1 != 0) {
        func_808003A0_chlaundry((u8 *)arg0);
        func_800FFAB0(arg0);
    }
}

s32 func_80800288_chlaundry(s32 arg0, s32 arg1, s32 arg2) 
{
    return 0;
}
Actor *chlaundry_entrypoint_1(f32 *arg0, f32 *arg1, f32 *arg2, s32 arg3) {
    s32 func_800B5BE4(s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EE904(s32[3], f32[3]);
    void *func_800FAB50(f32 *, f32 *, f32 *, u32, f32);
    void *func_80100094(Actor *, u32);
    Actor *func_80108454(s32, s32 *, u32);
    extern s32 D_80800448_chlaundry;
    struct LaundryData {
        s8 unk0;
        s8 unk1;
        f32 unk4;
        f32 unk8;
        f32 unkC[3];
        f32 unk18;
    };
    struct LaundryActorData {
        f32 unk0[4];
        f32 unk10[3];
        f32 unk1C;
    };
    Actor *actor;
    f32 sp40[3];
    s32 sp34[3];
    struct LaundryData *sp30;

    func_800FAB50(arg0, arg1, sp40, 0x024200A1, 15.0f);
    func_800EE904(sp34, arg1);
    actor = func_80108454(0x162, sp34, 0);
    sp30 = func_80100094(actor, 0);
    func_800EE7F8(&sp30->unkC[0], &actor->position[0]);
    sp30->unk0 = arg3;
    sp30->unk1 = 0;
    sp30->unk4 = 0.0f;
    actor->scale = 0.5f;
    ((struct LaundryActorData *)&actor->actorData[0])->unk1C = -800.0f;
    sp30->unk8 = -22000.0f;
    func_800EE7F8(&((struct LaundryActorData *)&actor->actorData[0])->unk10[0], arg2);
    sp30->unk18 = 0.0f;
    func_800BABB8(func_800B5BE4(0x19), &actor->position[0], NULL, 1.0f, &D_80800448_chlaundry);
    return actor;
}

void func_808003A0_chlaundry(u8 *volatile arg0) { s32 func_8010D930(s32, s32, f32 *, s32 *); extern s32 D_8080048C_chlaundry; u8 *sp1C; sp1C = arg0 + 4; func_8010D930(0, -1, (f32 *)sp1C, &D_8080048C_chlaundry); _fxsparkle_entrypoint_1((s32)sp1C, 0xD); }
