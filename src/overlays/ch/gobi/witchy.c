#include "common.h"

OSThread *chgobiwitchy_entrypoint_0(void)
{
    extern u8 D_80800410_chgobiwitchy[];

    return (OSThread *) D_80800410_chgobiwitchy;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gobi/witchy/func_8080000C_chgobiwitchy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gobi/witchy/func_80800104_chgobiwitchy.s")

void func_808001C8_chgobiwitchy(Actor* arg0) 
{
    _suexpression_entrypoint_8(arg0, 1);
}
/* extern */

void func_808001E8_chgobiwitchy(Actor *arg0) {
    s32 func_800DA298(s32);
    void func_800FFAB0(Actor *);
    void func_80102FDC(Actor *, f32);
    void func_80105A9C(Actor *, f32);
    if (func_800DA298(0x97) != 0) {
        func_800FFAB0(arg0);
        return;
    }
    func_80105A9C(arg0, 500.0f);
    func_80102FDC(arg0, 0.25f);
    ((struct { u8 pad; u8 : 7; u8 flag : 1; } *)&arg0->pad94)->flag = 1;
}

/* extern */

void func_8080024C_chgobiwitchy(Actor *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    s32 _capod_entrypoint_22();
    void _suexpression_entrypoint_12(void *, f32, f32);
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    _capod_entrypoint_22();
    if (arg1 == 0x107B) {
        _suexpression_entrypoint_12(func_80100094(arg0, 1), 0.0f, 0.0f);
        func_80101FDC(arg0, 4);
        _capod_entrypoint_13(arg0->unk0, 0, 1, 0x2031);
        return;
    }
    func_80101FDC(arg0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gobi/witchy/func_808002DC_chgobiwitchy.s")
