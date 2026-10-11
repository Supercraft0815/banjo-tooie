#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/fixpos/func_80800000_ncpodfixpos.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/fixpos/ncpodfixpos_entrypoint_0.s")

/* extern */

void ncpodfixpos_entrypoint_1(s16 arg0) {
    s32 func_8001B754(s16);
    func_8001B754(arg0);
}

/* extern */

void ncpodfixpos_entrypoint_2(s16 arg0) {
    s32 func_8001B798(s16);
    func_8001B798(arg0);
}

/* extern */

void func_80800118_ncpodfixpos(u8 *arg0, s32 arg1, s32 arg2) {
    s32 _cadbfunc_entrypoint_0(u8 *);
    s32 _cadbfunc_entrypoint_2(u8 *);
    s32 func_800A5800(s16);
    (*(s32 *)((s8 *)(arg0) + (0x3C))) = arg2;
    if (arg2 == 1) {
        func_800A5800((*(s16 *)((s8 *)(arg0) + (0x38))));
        _cadbfunc_entrypoint_0(arg0);
        _cadbfunc_entrypoint_2(arg0 + 0xC);
        (*(s8 *)((s8 *)(arg0) + (0x42))) = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/fixpos/ncpodfixpos_entrypoint_3.s")

void ncpodfixpos_entrypoint_4(u8 *arg0, u8 *arg1) {
    (*(u8 **)((s8 *)(arg0) + (0x18))) = arg1;
    (*(u32 *)((s8 *)(arg0) + (0x1C))) = (u32) (*(u16 *)((s8 *)(arg1) + (0x12))) >> 1;
}

void ncpodfixpos_entrypoint_5(s16 *arg0, s32 arg1) {
    arg0[22] = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/fixpos/func_808001A8_ncpodfixpos.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/pod/fixpos/ncpodfixpos_entrypoint_6.s")
