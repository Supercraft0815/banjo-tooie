#include "common.h"

/* extern */

void func_80800000_chplatuegrill(void *arg0) {
    s32 _chdoormake_entrypoint_3(void *, s32, s32, f32, s32, s32);
    s32 _chdoormake_entrypoint_5(void *, s32);
    s32 _chdoormake_entrypoint_6(void *, s32);
    s32 _chdoormake_entrypoint_8(void *, s32);
    s32 _chdoormake_entrypoint_9(void *, s32, s32, s32);
    f32 func_80103EF4();
    _chdoormake_entrypoint_3(arg0, (*(s32 *)((s8 *)(arg0) + (0x48))), 0x42B40000, func_80103EF4() * 1.1f, 1, 0x3EA);
    _chdoormake_entrypoint_5(arg0, 0x40000000);
    _chdoormake_entrypoint_6(arg0, 0x40800000);
    _chdoormake_entrypoint_8(arg0, 2);
    _chdoormake_entrypoint_9(arg0, 0, 0x10, 0x10);
}

OSThread *chplatuegrill_entrypoint_0(void)
{
    extern u8 D_808001D0_chplatuegrill[];

    return (OSThread *) D_808001D0_chplatuegrill;
}

/* extern */

void func_808000A0_chplatuegrill(void *arg0) {
    s32 func_800DA298(s32);
    void func_80102424(Actor *, s32);
    if (func_800DA298(0x3EA) != 0) {
        (*(f32 *)((s8 *)(arg0) + (0x58))) = 0.0f;
        func_80102424(arg0, 2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/platuegrill/func_808000DC_chplatuegrill.s")

/* extern */

s32 func_80800148_chplatuegrill(Actor *arg0, s32 arg1, s32 arg2) {
    void func_800FC660(u32);
    void func_80102424(Actor *, s32);
    void func_80103110(Actor *, u32);
    if (arg1 == 0x40) {
        if (arg0->unk70_10 == 1) {
            func_80103110(arg0, 1);
            func_80102424(arg0, 3);
            func_800FC660(0xE);
        }
        return 1;
    }
    return 0;
}

OSThread *chplatuegrill_entrypoint_1(void)
{
    extern u8 D_80800238_chplatuegrill[];

    return (OSThread *) D_80800238_chplatuegrill;
}
