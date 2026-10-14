#include "common.h"

OSThread *chhellterskeltermouth_entrypoint_0(void)
{
    extern u8 D_80800330_chhellterskeltermouth[];

    return (OSThread *) D_80800330_chhellterskeltermouth;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hellterskeltermouth/func_8080000C_chhellterskeltermouth.s")

/* extern */

void func_808001BC_chhellterskeltermouth(Actor *arg0) {
    s32 func_800DA298(s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_80101FDC(Actor *, u32);
    void func_80102FE8(void *, s32);
    void func_80103110(Actor *, u32);
    void func_8010A590(Actor *);
    func_800EE7F8((f32 *)arg0->actorData, arg0->position);
    func_800EE7F8((f32 *)&arg0->actorData[4], arg0->position);
    ((f32 *)arg0->actorData)[5] -= 350.0f;
    if (func_800DA298(0xA4) != 0) {
        func_8010A590(arg0);
        func_80102FE8(arg0, 0);
        func_80101FDC(arg0, 4);
        arg0->unk58 = 2.5f;
        return;
    }
    func_80103110(arg0, 0);
}

/* extern */

s32 func_80800258_chhellterskeltermouth(Actor *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    void func_80101FDC(Actor *, u32);
    void func_80102FE8(void *, s32);
    void func_80103110(Actor *, u32);
    void func_8010A590(Actor *);
    s32 result;
    if (arg1 == 0xA) {
        _capod_entrypoint_13(arg0->unk0, NULL, 0x1A, 0x2010);
        func_8010A590(arg0);
        func_80103110(arg0, 1);
        func_80102FE8(arg0, 0);
        func_80101FDC(arg0, 4);
        arg0->unk58 = 2.5f;
        result = 1;
    } else {
        return 0;
    }
    return result;
}

void func_808002E4_chhellterskeltermouth(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_4(Actor*, f32*, u32, u32*);
    extern u32 D_80800384_chhellterskeltermouth;
    _subaddieaudioloop_entrypoint_4(arg0, (f32 *) ((u8 *) arg0 + 4), 1U, &D_80800384_chhellterskeltermouth);
}
