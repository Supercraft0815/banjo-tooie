#include "common.h"

OSThread *chseaweedbaddy_entrypoint_0(void)
{
    extern u8 D_80800EB4_chseaweedbaddy[];

    return (OSThread *) D_80800EB4_chseaweedbaddy;
}

OSThread *chseaweedbaddy_entrypoint_1(void)
{
    extern u8 D_80800EFC_chseaweedbaddy[];

    return (OSThread *) D_80800EFC_chseaweedbaddy;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/seaweedbaddy/func_80800018_chseaweedbaddy.s")

void func_8080043C_chseaweedbaddy(Actor *arg0) {
    void _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
    _sudeflect_entrypoint_1(arg0->position, arg0->scale * 120.0f, arg0->scale * 100.0f, 0.0f, 0xA);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/seaweedbaddy/func_80800498_chseaweedbaddy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/seaweedbaddy/func_80800554_chseaweedbaddy.s")

void func_8080065C_chseaweedbaddy(Actor *arg0) {
    f32 func_800DC0C0(void);
    s32 func_80101EE4(Actor *, f32);
    void func_80102FDC(Actor*, f32);
    func_80102FDC(arg0, arg0->scale * 0.7f);
    func_80101EE4(arg0, func_800DC0C0());
}

/* extern */

void func_808006A8_chseaweedbaddy(s32 arg0, s32 arg1) {
    s32 func_800DF744(s32, s32);
    s32 func_80101870(s32, s32);
    func_800DF744(1, 0);
    func_800DF744(2, 0);
    func_800DF744(3, 1);
    func_800DF744(4, 0);
    func_800DF744(5, 1);
    func_80101870(arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/seaweedbaddy/func_80800710_chseaweedbaddy.s")

/* extern */

void func_808007E4_chseaweedbaddy(u8 *arg0, s32 arg1) {
    struct Flags {
        unsigned int : 29;
        unsigned int active : 1;
        unsigned int : 2;
    };
    void func_80800710_chseaweedbaddy(u8 *, s32);
    if (!((struct Flags *)(arg0 + 0x78))->active &&
        (((u32)*(u16 *)(arg0 + 0x72) >> 10) != 4)) {
        func_80800710_chseaweedbaddy(arg0, 4);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/seaweedbaddy/func_8080082C_chseaweedbaddy.s")

/* extern */

s32 func_80800910_chseaweedbaddy(Actor *arg0) {
    s32 _subaddierouteDll_entrypoint_4(Actor *);
    Unk80132ED0 *_suchase_entrypoint_0(void);
    s32 func_8010C668(Actor *, f32 *, f32, f32);
    s32 func_8010C9FC(f32 *, s32, s32, s32);
    union FlowerBaddieActor {
        Actor actor;
        struct {
            u32 reserved[25];
            u32 : 2;
            u32 blocked : 1;
            u32 : 29;
        } flags;
    };

    if (((union FlowerBaddieActor *)arg0)->flags.blocked) {
        return 0;
    }
    if (_subaddierouteDll_entrypoint_4(arg0) == 0) {
        return 0;
    }
    if (func_8010C9FC(arg0->position, 0x3E8, 0x1F4, -0x32) == 0) {
        return 1;
    }
    if (func_8010C668(arg0, arg0->position, 1000.0f, -200.0f) == 0) {
        return 1;
    }
    return _suchase_entrypoint_0() != arg0->unk0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/seaweedbaddy/func_808009BC_chseaweedbaddy.s")

void func_80800BCC_chseaweedbaddy(Actor *arg0) {
    void _chexploder_entrypoint_10(Actor *, s32 *);
    s32 _chexploder_entrypoint_14(Actor *, s32);
    s32 _chexploder_entrypoint_6(Actor *, f32, f32);
    s32 _chexploder_entrypoint_9(Actor *, s32, s32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800FFAB0(Actor *);
    void *func_80101080(void);
    void func_80103DFC(Actor *, f32 *);
    Actor *func_80106790(Unk80132ED0 *);
    s32 func_80107070(Actor *, s32);
    extern s32 D_80800F5C_chseaweedbaddy;
    extern s32 D_80800F90_chseaweedbaddy;
    extern s32 D_80800F9C_chseaweedbaddy;
    f32 sp30[4];
    Actor *temp_v0;

    temp_v0 = func_80106790(func_80101080());
    _chexploder_entrypoint_9(temp_v0, 1, 0);
    _chexploder_entrypoint_9(temp_v0, 2, 0);
    _chexploder_entrypoint_9(temp_v0, 3, 0);
    _chexploder_entrypoint_9(temp_v0, 4, 1);
    _chexploder_entrypoint_9(temp_v0, 5, 0);
    _chexploder_entrypoint_10(temp_v0, &D_80800F9C_chseaweedbaddy);
    _chexploder_entrypoint_6(temp_v0, 500.0f, 600.0f);
    _chexploder_entrypoint_14(temp_v0, 3);
    func_80103DFC(arg0, sp30);
    func_800BBCB8(sp30, sp30, arg0->scale, 4, &D_80800F5C_chseaweedbaddy);
    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80800F90_chseaweedbaddy);
    if (func_80107070(arg0, 3) == 0) {
        func_800FFAB0(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/seaweedbaddy/func_80800CE0_chseaweedbaddy.s")
