#include "common.h"

OSThread *chgoldsnakehead_entrypoint_0(void)
{
    extern u8 D_80800508_chgoldsnakehead[];

    return (OSThread *) D_80800508_chgoldsnakehead;
}

OSThread *chgoldsnakehead_entrypoint_1(void)
{
    extern u8 D_80800550_chgoldsnakehead[];

    return (OSThread *) D_80800550_chgoldsnakehead;
}

OSThread *chgoldsnakehead_entrypoint_2(void)
{
    extern u8 D_80800598_chgoldsnakehead[];

    return (OSThread *) D_80800598_chgoldsnakehead;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gold/snakehead/func_80800024_chgoldsnakehead.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gold/snakehead/func_8080015C_chgoldsnakehead.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gold/snakehead/func_808002B4_chgoldsnakehead.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gold/snakehead/func_80800324_chgoldsnakehead.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gold/snakehead/func_808003A8_chgoldsnakehead.s")

/* extern */

void func_808003E0_chgoldsnakehead(Actor *arg0) {
    s32 _chdoormake_entrypoint_3(Actor*, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_8(void*, u32);
    s32 _chdoormake_entrypoint_9(Actor *, s32, s32, s32);
    if (_chdoormake_entrypoint_3(arg0, 0.0f, 90.0f, 200.0f, 0x41, 0x18B) != 0) {
        _chdoormake_entrypoint_8(arg0, 5U);
        _chdoormake_entrypoint_9(arg0, 0, 6, 0x10);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gold/snakehead/func_80800440_chgoldsnakehead.s")
