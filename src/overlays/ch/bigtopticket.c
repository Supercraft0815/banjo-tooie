#include "common.h"

OSThread *chbigtopticket_entrypoint_0(void)
{
    extern u8 D_80800120_chbigtopticket[];

    return (OSThread *) D_80800120_chbigtopticket;
}

void func_8080000C_chbigtopticket(s32 arg0) 
{
}
void func_80800014_chbigtopticket(u8 *arg0) {
    f32 func_800D8FF8(void);
    s32 func_80103110(void *, u32);
    (*(f32 *)((s8 *)(arg0) + (0x48))) = (f32) ((*(f32 *)((s8 *)(arg0) + (0x48))) - (func_800D8FF8() * 175.0f));
    func_80103110(arg0, 0U);
}

/* extern */

void func_80800058_chbigtopticket(void *arg0) {
    s32 func_80101870();
    s32 func_80103110(void *, u32);
    func_80101870();
    func_80103110(arg0, (u32) ((*(s32 *)((s8 *)(arg0) + (0x7C))) << 0x13) >> 0x1F);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bigtopticket/func_8080008C_chbigtopticket.s")
