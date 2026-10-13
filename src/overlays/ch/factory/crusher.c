#include "common.h"

OSThread *chfactorycrusher_entrypoint_0(void)
{
    extern u8 D_80800A50_chfactorycrusher[];

    return (OSThread *) D_80800A50_chfactorycrusher;
}

OSThread *chfactorycrusher_entrypoint_1(void)
{
    extern u8 D_80800A98_chfactorycrusher[];

    return (OSThread *) D_80800A98_chfactorycrusher;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/crusher/func_80800018_chfactorycrusher.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/crusher/func_80800150_chfactorycrusher.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/crusher/func_80800580_chfactorycrusher.s")

/* extern */

void func_8080067C_chfactorycrusher(s32 arg0, s32 arg1) {
    f32 sp1C[3];

    func_800E3980(sp1C);
    if (sp1C[2] > 2500.0f) {
        func_80101870(arg0, arg1);
    }
}

/* extern */

void func_808006CC_chfactorycrusher(Actor *arg0) {
    void func_800EE780(f32 dst[3], f32 a[3], f32 b[3]);
    u32 func_800F54E4(void);
    void* func_80100094(Actor*, u32);
    s32 func_800F4D18(u32, f32 *, f32 *);
    f32 *sp3C;
    f32 sp30[3];
    f32 sp24[3];

    sp3C = func_80100094(arg0, 0U);
    func_800EE780(sp30, sp3C, arg0->position);
    func_800EE780(sp24, sp3C + 3, arg0->position);
    func_800F4D18(func_800F54E4(), sp30, sp24);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/crusher/func_80800738_chfactorycrusher.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/crusher/func_80800800_chfactorycrusher.s")

/* extern */

void func_80800898_chfactorycrusher(void *arg0) {
    s32 func_80106790(s32);
    func_80106790((*(s32 *)((s8 *)(arg0) + (0x3C))));
}

void func_808008B8_chfactorycrusher(s32 arg0, f32 arg1) {
    void func_800EFE50(f32*, void*, void*, f32);
    func_800EFE50(arg0 + 4, arg0 + 0x18, arg0 + 0x28, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/crusher/func_808008F0_chfactorycrusher.s")

/* extern */

void func_80800984_chfactorycrusher(s32 arg0) {
    s32 _chswitch_entrypoint_7(s32, s32);
    s32 _chswitch_entrypoint_8(s32, s32);
    s32 _chswitch_entrypoint_9(s32);
    _chswitch_entrypoint_7(arg0, 0x329);
    _chswitch_entrypoint_8(arg0, 1);
    _chswitch_entrypoint_9(arg0);
}

/* extern */

s32 func_808009BC_chfactorycrusher(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _chswitch_entrypoint_10(s32, s32, s32);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0*, u32, u32, f32*, u32);
    void _chmrtannoy_entrypoint_0(void);
    if (arg1 == 7) {
        _chmrtannoy_entrypoint_0();
        _subaddiedialog_entrypoint_11(arg0->unk0, 0x1340U, 4U, arg0->position, 0xA3U);
        return 1;
    }
    return _chswitch_entrypoint_10((s32) arg0, arg1, arg2);
}
