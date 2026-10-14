#include "common.h"

OSThread *chhotfloorsmoke_entrypoint_0(void)
{
    extern u8 D_808002D0_chhotfloorsmoke[];

    return (OSThread *) D_808002D0_chhotfloorsmoke;
}

/* extern */

void func_8080000C_chhotfloorsmoke(Actor *arg0) {
    s32 func_800EA05C();
    s32 temp_v0;

    arg0->unk64_20 = 1;
    temp_v0 = func_800EA05C();
    if (temp_v0 != 0xD1) {
        if (temp_v0 != 0x12B) {
            arg0->unk6C_0 = 0;
            return;
        }
        arg0->unk64_20 = 0;
        arg0->unk6C_0 = 2;
        return;
    }
    arg0->unk6C_0 = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hot/floorsmoke/func_80800090_chhotfloorsmoke.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hot/floorsmoke/func_808000FC_chhotfloorsmoke.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hot/floorsmoke/func_808001E8_chhotfloorsmoke.s")
