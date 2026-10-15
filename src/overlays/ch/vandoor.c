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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/vandoor/func_80800280_chvandoor.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/vandoor/func_80800388_chvandoor.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/vandoor/func_8080044C_chvandoor.s")
