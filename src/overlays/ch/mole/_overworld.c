#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mole/_overworld/func_80800000_chmole_overworld.s")

void func_808000F4_chmole_overworld(Actor* arg0) 
{
    _sumole_entrypoint_0(arg0, 0);
    arg0->unk74_7 = arg0->unk74_7 - 0x32;
    arg0->unk54 = arg0->unk74_7;
}
void func_80800160_chmole_overworld(s32 *arg0) {
    s32 _sumole_entrypoint_4();
    extern s32 D_80800190_chmole_overworld;
    _sumole_entrypoint_4(arg0, &D_80800190_chmole_overworld);
}

OSThread *chmole_overworld_entrypoint_0(void)
{
    extern u8 D_808001F0_chmole_overworld[];

    return (OSThread *) D_808001F0_chmole_overworld;
}
