#include "common.h"

/* extern */

void func_80800000_chwitchytents(s32 arg0) {
    s32 func_800EA05C();
    s32 func_8010A624(s32);
    if (func_800EA05C() == 0x124) {
        func_8010A624(arg0);
    }
}

OSThread *chwitchytents_entrypoint_0(void)
{
    extern u8 D_80800050_chwitchytents[];

    return (OSThread *) D_80800050_chwitchytents;
}

OSThread *chwitchytents_entrypoint_1(void)
{
    extern u8 D_80800098_chwitchytents[];

    return (OSThread *) D_80800098_chwitchytents;
}
