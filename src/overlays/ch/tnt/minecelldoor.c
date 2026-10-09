#include "common.h"

OSThread *chtntminecelldoor_entrypoint_0(void)
{
    extern u8 D_80800140_chtntminecelldoor[];

    return (OSThread *) D_80800140_chtntminecelldoor;
}

void func_8080000C_chtntminecelldoor(s32 arg0)
{
    _subaddiefade_entrypoint_14();
    func_8010A63C(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/tnt/minecelldoor/func_80800034_chtntminecelldoor.s")

/* extern */

void func_808000F4_chtntminecelldoor(s32 arg0) {
    s32 _chexploder_entrypoint_12(s32, s32);
    s32 _chexploder_entrypoint_13(s32, s32);
    s32 func_800DA544(s32);
    s32 func_80101080();
    s32 func_80106790(s32);
    s32 sp1C;
    s32 temp_v0;

    temp_v0 = func_80106790(func_80101080());
    sp1C = temp_v0;
    _chexploder_entrypoint_13(temp_v0, 1);
    _chexploder_entrypoint_12(sp1C, 0x3C);
    func_800DA544(0x85);
}
