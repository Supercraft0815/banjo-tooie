#include "common.h"

OSThread *changlerbossflare_entrypoint_0(void)
{
    extern u8 D_80800480_changlerbossflare[];

    return (OSThread *) D_80800480_changlerbossflare;
}

void func_8080000C_changlerbossflare(Actor *arg0) {
    struct FlareActorFields {
        u8 pad0[0x54];
        s32 unk54;
        u8 pad58[0x18];
        u32 pad70:31;
        u32 initialized:1;
    } *self = (void *)arg0;
    s32 _subaddieaudioquick_entrypoint_2(s32, s32, s32 *);
    s32 func_800C8A98(void);
    void func_8010A3E8(void *, f32);
    extern s32 D_808004C8_changlerbossflare;
    _subaddieaudioquick_entrypoint_2(arg0, (u8 *)arg0 + 4, &D_808004C8_changlerbossflare);
    func_8010A3E8(arg0, 0.3f);
    self->unk54 = func_800C8A98();
    self->initialized = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/flare/func_80800068_changlerbossflare.s")

/* extern */

s32 func_80800154_changlerbossflare(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_80800190_changlerbossflare();
    switch (arg1) {
    case 0x40:
        func_80800190_changlerbossflare(arg0);
        break;
    default:
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/flare/func_80800190_changlerbossflare.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/flare/func_8080021C_changlerbossflare.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/flare/func_808003A4_changlerbossflare.s")
