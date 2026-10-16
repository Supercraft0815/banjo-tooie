#include "common.h"

OSThread *chvandoor_entrypoint_0(void)
{
    extern u8 D_80800640_chvandoor[];

    return (OSThread *) D_80800640_chvandoor;
}

void func_8080000C_chvandoor(Actor *arg0) {
    s32 _subaddieDll_entrypoint_0(Actor *);
    s32 func_800DA298(s32);
    void func_800DA524(s32);
    s32 func_800EA05C();
    void func_800EE7F8(f32 *, f32 *);
    u32 func_800F54E4(void);
    s32 func_800F64A4(s32, s32);
    void func_8010A800(Actor *, s32);
    void func_80800388_chvandoor(Actor *, s32);
    s32 sp2C;

    sp2C = arg0->unk74_7 + 0xA08;
    func_800EE7F8((f32 *)&arg0->actorData[0], arg0->position);
    func_800EE7F8((f32 *)&arg0->actorData[4], arg0->position);
    ((f32 *)arg0->actorData)[5] += arg0->scale * 300.0f;
    *(s32 *)&arg0->unk50 = sp2C;
    if (func_800F64A4(func_800F54E4(), 0x8000) == 0) {
        func_800DA524(sp2C);
    }
    if (func_800DA298(sp2C) != 0) {
        func_80800388_chvandoor(arg0, 3);
        func_800EE7F8(arg0->position, (f32 *)&arg0->actorData[4]);
    } else {
        func_80800388_chvandoor(arg0, 1);
    }
    func_8010A800(arg0, 0);
    if (func_800EA05C() == 0xE7) {
        _subaddieDll_entrypoint_0(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/vandoor/func_80800104_chvandoor.s")

/* extern */

s32 func_80800280_chvandoor(Actor *arg0, s32 arg1, s32 arg2) {
    f32 func_800EEB40(f32 *, f32 *);
    void func_800F5A00(s32, f32 *);
    s32 func_80101180(s32, s32, s32);
    void func_80800388_chvandoor(Actor *, s32);
    f32 sp1C[3];

    switch (arg1) {
    case 0x19:
        if (arg0->unk70_10 == 1) {
            func_800F5A00(arg2, sp1C);
            if (func_800EEB40(sp1C, arg0->position) < 250000.0f) {
                func_80101180(0x3CC, 7, arg0->unk74_7);
            }
        }
        break;
    case 7:
        if (arg2 != arg0->unk74_7) {
            return 0;
        }
        func_80800388_chvandoor(arg0, 2);
        break;
    case 8:
        if (arg2 != arg0->unk74_7) {
            return 0;
        }
        func_80800388_chvandoor(arg0, 4);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800388_chvandoor(Actor *arg0, s32 arg1) {
    void func_80101FDC(Actor *, u32);
    void func_80103110(Actor *, u32);
    void func_800DA524(s32);
    void func_800DA544(s32);

    func_80101FDC(arg0, arg1);
    switch (arg1) {
    case 1:
        func_80103110(arg0, 0);
        func_800DA524(*(s32 *)&arg0->unk50);
        break;
    case 2:
        func_80103110(arg0, 1);
        arg0->unk58 = 2.0f;
        func_800DA544(*(s32 *)&arg0->unk50);
        break;
    case 3:
        func_80103110(arg0, 1);
        break;
    case 4:
        arg0->unk58 = 2.0f;
        break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/vandoor/func_8080044C_chvandoor.s")
