#include "ch/lagoonentrygate.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lagoon/entrygate/func_80800000_chlagoonentrygate.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lagoon/entrygate/func_8080008C_chlagoonentrygate.s")

OSThread *chlagoonentrygate_entrypoint_0(void)
{
    extern u8 D_80800150_chlagoonentrygate[];

    return (OSThread *) D_80800150_chlagoonentrygate;
}
