#include "common.h"

/* extern */

void func_80800000_chmumbohealspell(s32 *arg0) {
    s32 func_800DA298(s32);
    s32 func_800EA05C();
    s32 func_800FFA88(s32);
    void func_80103110(void *, s32);
    if ((func_800DA298(0x15E) != 0) && (func_800EA05C() == 0x155)) {
        func_800FFA88(*arg0);
    } else if (func_800DA298(0x189) == 0) {
        func_800FFA88(*arg0);
    }
    func_80103110(arg0, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mumbo/healspell/func_80800074_chmumbohealspell.s")

s32 func_808003A8_chmumbohealspell(void *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_14(void);
    void func_80103110(void *, s32);
    void func_80800450_chmumbohealspell(void *, s32);

    switch (arg1) {
        case 0x4B:
            func_80800450_chmumbohealspell(arg0, 2);
            func_80103110(arg0, 1);
            return 1;
        case 0xB:
            if (arg2 == 0x10) {
                _capod_entrypoint_14();
                func_80800450_chmumbohealspell(arg0, 7);
                return 4;
            }
            return 3;
        case 0x49:
            if (arg2 == 0x71) {
                func_80800450_chmumbohealspell(arg0, 9);
                return 1;
            }
            return 0;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mumbo/healspell/func_80800450_chmumbohealspell.s")

void func_80800740_chmumbohealspell(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 _sumumbofx_entrypoint_6(void *, f32, f32, s32, s32, void *, void *, void *);
    struct HealSpellVector { s32 values[3]; };
    extern struct HealSpellVector D_808008DC_chmumbohealspell;
    extern struct HealSpellVector D_808008E8_chmumbohealspell;
    extern struct HealSpellVector D_808008F4_chmumbohealspell;
    struct HealSpellVector sp44 = D_808008DC_chmumbohealspell;
    struct HealSpellVector sp38 = D_808008E8_chmumbohealspell;
    struct HealSpellVector sp2C = D_808008F4_chmumbohealspell;

    _sumumbofx_entrypoint_6(func_80100094(arg0, 0), 1400.0f, 500.0f,
                          0, 60, &sp38, &sp2C, &sp44);
}

/* extern */

void func_80800800_chmumbohealspell(Actor *arg0, s32 arg1) {
    void* func_80100094(Actor*, u32);
    s32 _sumumbofx_entrypoint_8(u8 *, s32);
    s32 _sumumbofx_entrypoint_9(u8 *, s32);
    if (func_80100094(arg0, 0U) != NULL) {
        _sumumbofx_entrypoint_9(func_80100094(arg0, 0U), arg1);
        _sumumbofx_entrypoint_8(func_80100094(arg0, 0U), arg1);
    }
}

OSThread *chmumbohealspell_entrypoint_0(void)
{
    extern u8 D_80800900_chmumbohealspell[];

    return (OSThread *) D_80800900_chmumbohealspell;
}
