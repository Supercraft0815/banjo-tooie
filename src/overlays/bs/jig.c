#include "common.h"

s32 bsjig_entrypoint_0(s32 arg0) {
    return arg0 == 0x44;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/jig/bsjig_entrypoint_1.s")

/* extern */

void bsjig_entrypoint_2(void) {
    s32 _chjigsawdance_entrypoint_1(s32, s32);
    s32 func_800A32F8(s32);
    s32 func_800F53D0();
    s32 func_80106790(s32);
    s32 sp1C;
    s32 temp_v0;

    temp_v0 = func_800F53D0();
    sp1C = temp_v0;
    if (func_800A32F8(temp_v0) != 0) {
        _chjigsawdance_entrypoint_1(func_80106790(func_800A32F8(sp1C)), 4);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/jig/bsjig_entrypoint_3.s")

/* extern */

void bsjig_entrypoint_4(s32 arg0) {
    s32 _chjigsawdance_entrypoint_1(s32, s32);
    s32 func_800A32F8();
    s32 func_800A34D8(s32, s32);
    s32 func_80106790(s32);
    s32 temp_v0;

    temp_v0 = func_800A32F8();
    if (temp_v0 != 0) {
        _chjigsawdance_entrypoint_1(func_80106790(temp_v0), 5);
        func_800A34D8(arg0, 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/jig/bsjig_entrypoint_5.s")

s32 bsjig_entrypoint_6(s32 arg0) {
    extern s32 D_808005B0_bsjig[];
    return ((s32 *)&D_808005B0_bsjig)[arg0];
}

/* extern */

void bsjig_entrypoint_7(s32 arg0) {
    s32 func_80099AA8(s32);
    s32 func_80099B94(s32);
    s32 func_8009E6EC();
    if (func_8009E6EC() == 0x26) {
        func_80099B94(arg0);
        return;
    }
    func_80099AA8(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/jig/bsjig_entrypoint_8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/jig/bsjig_entrypoint_9.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/jig/bsjig_entrypoint_10.s")

s32 bsjig_entrypoint_11(s32 arg0) {
    extern s32 D_808005C0_bsjig[];
    return ((s32 *)&D_808005C0_bsjig)[arg0];
}
