#include "common.h"

OSThread *chhellterskeltermouth_entrypoint_0(void)
{
    extern u8 D_80800330_chhellterskeltermouth[];

    return (OSThread *) D_80800330_chhellterskeltermouth;
}

void func_8080000C_chhellterskeltermouth(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 func_800D9078(f32 *);
    void func_800EFE50(f32[3], f32[3], f32[3], f32);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    void func_80101FDC(Actor *, u32);
    void func_808002E4_chhellterskeltermouth(Actor *);
    extern u8 D_80800378_chhellterskeltermouth[];
    s32 sp3C;
    f32 t;
    s32 sp34;
    f32 *sp2C;

    switch (arg0->unk70_10) {
    case 1:
        break;
    case 2:
        sp3C = func_800D9078(&arg0->unk58);
        t = func_800F12D4(arg0->unk58, 0.0f, 2.5f, 1.0f, 0.0f);
        sp2C = arg0->position;
        func_800EFE50(sp2C, (f32 *)&arg0->actorData[4], (f32 *)arg0->actorData, t);
        if (sp3C != 0) {
            arg0->unk58 = 0.7f;
            func_80101FDC(arg0, 3);
            _subaddieaudioquick_entrypoint_2(arg0, sp2C, D_80800378_chhellterskeltermouth);
        }
        func_808002E4_chhellterskeltermouth(arg0);
        break;
    case 3:
        if (func_800D9078(&arg0->unk58) != 0) {
            arg0->unk58 = 2.5f;
            func_80101FDC(arg0, 4);
        }
        break;
    case 4:
        sp34 = func_800D9078(&arg0->unk58);
        t = func_800F12D4(arg0->unk58, 0.0f, 2.5f, 0.0f, 1.0f);
        sp2C = arg0->position;
        func_800EFE50(sp2C, (f32 *)&arg0->actorData[4], (f32 *)arg0->actorData, t);
        if (sp34 != 0) {
            arg0->unk58 = 0.7f;
            func_80101FDC(arg0, 5);
            _subaddieaudioquick_entrypoint_2(arg0, sp2C, D_80800378_chhellterskeltermouth);
        }
        func_808002E4_chhellterskeltermouth(arg0);
        break;
    case 5:
        if (func_800D9078(&arg0->unk58) != 0) {
            arg0->unk58 = 2.5f;
            func_80101FDC(arg0, 2);
        }
        break;
    }
}

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
