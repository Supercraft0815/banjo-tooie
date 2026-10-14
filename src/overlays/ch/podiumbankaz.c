#include "common.h"

/* extern */

void func_80800000_chpodiumbankaz(s32 arg0) {
    s32 _subaddiefade_entrypoint_1(s32, s32);
    s32 func_800C6E38(s32);
    if (func_800C6E38(0x1C) != 0) {
        _subaddiefade_entrypoint_1(arg0, 0xFF);
        return;
    }
    _subaddiefade_entrypoint_1(arg0, 0x87);
}

/* extern */

void func_80800044_chpodiumbankaz(Actor *arg0) {
    s32 _subaddiedialog_entrypoint_1(f32 *, u32, s32);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 func_800DA298(s32);
    s32 func_800DA544(s32);

    if (func_800DA298(0x4F4) == 0) {
        if ((_subaddiedialog_entrypoint_1(arg0->position, 0xFA, 0) != 0) && (_subaddiedialog_entrypoint_11(arg0->unk0, 0xD82, 0xE, arg0->position, 0) != 0)) {
            func_800DA544(0x4F4);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/podiumbankaz/func_808000B8_chpodiumbankaz.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/podiumbankaz/func_80800170_chpodiumbankaz.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/podiumbankaz/func_80800228_chpodiumbankaz.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/podiumbankaz/func_80800318_chpodiumbankaz.s")

void func_808003C4_chpodiumbankaz(s32 arg0, s32 arg1) {
    s32 _subaddiefade_entrypoint_1(s32, s32);
    if (arg1 == 0x1C) {
        _subaddiefade_entrypoint_1(arg0, 0xFF);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/podiumbankaz/func_808003EC_chpodiumbankaz.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/podiumbankaz/func_80800464_chpodiumbankaz.s")

OSThread *chpodiumbankaz_entrypoint_0(void)
{
    extern u8 D_80800500_chpodiumbankaz[];

    return (OSThread *) D_80800500_chpodiumbankaz;
}

OSThread *chpodiumbankaz_entrypoint_1(void)
{
    extern u8 D_80800548_chpodiumbankaz[];

    return (OSThread *) D_80800548_chpodiumbankaz;
}
