#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/powerhut/chpowerhut_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/powerhut/chpowerhut_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/powerhut/chpowerhut_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/powerhut/chpowerhut_entrypoint_3.s")

/* extern */

void func_80800400_chpowerhut(s32 arg0) {
    s16 _chmumbopad_entrypoint_0(s32);
    s32 _sumumbofx_entrypoint_0(s32, s32, s32, s16);
    s32 _sumumbofx_entrypoint_15(s32, s32);
    s32 _sumumbofx_entrypoint_2(s32);
    s32 _sumumbofx_entrypoint_20(s32, s32);
    s32 _sumumbofx_entrypoint_24(s32, s32);
    void *func_80100094(Actor *, u32);
    s32 sp1C;
    s32 temp_v0;

    _sumumbofx_entrypoint_0(arg0, 1, 0x14, _chmumbopad_entrypoint_0(3));
    temp_v0 = func_80100094(arg0, 1);
    sp1C = temp_v0;
    _sumumbofx_entrypoint_2(temp_v0);
    _sumumbofx_entrypoint_24(sp1C, 0x40100000);
    _sumumbofx_entrypoint_15(sp1C, 0x40400000);
    _sumumbofx_entrypoint_20(sp1C, 0x40400000);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/powerhut/func_8080047C_chpowerhut.s")

s32 func_808005F4_chpowerhut(Actor *arg0) {
    s32 _sumumbofx_entrypoint_1(void *, s32);
    f32 _sumumbofx_entrypoint_22(u8 *);
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    void func_800DA524(s32);
    void func_800DA544(s32);
    u16 *data;
    s32 result = 0;

    if (_sumumbofx_entrypoint_22(func_80100094(arg0, 1)) < 0.05f) {
        data = func_80100094(arg0, 0);
        if (*data != 0) {
            *data -= 1;
            return 0;
        }
        _sumumbofx_entrypoint_1(arg0, 1);
        func_80101FDC(arg0, 5);
        func_800DA524(0x9DE);
        func_800DA544(0x9DF);
        result = 1;
        return result;
    }
    return result;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/powerhut/func_80800698_chpowerhut.s")

void func_80800870_chpowerhut(s32 arg0) {
    s32 func_8001210C(s32);
    s32 func_800BBCB8(s32, s32, s32, s32, s32 *);
    extern s32 D_808009C0_chpowerhut;
    s32 temp_a0;

    if (func_8001210C(3) == 0) {
        temp_a0 = arg0 + 0x18;
        func_800BBCB8(temp_a0, temp_a0, 0x3F800000, 2, &D_808009C0_chpowerhut);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/powerhut/chpowerhut_entrypoint_4.s")
