#include "common.h"

/* extern */

void func_80800000_chfantasybounce(s32 arg0) {
    s32 func_800EFA4C(s32, s32, s32, s32);
    func_800EFA4C(arg0 + 4, 0xC62C8A36, 0x4604CA00, 0xC6149236);
}

OSThread *chfantasybounce_entrypoint_0(void)
{
    extern u8 D_80800060_chfantasybounce[];

    return (OSThread *) D_80800060_chfantasybounce;
}

OSThread *chfantasybounce_entrypoint_1(void)
{
    extern u8 D_808000A8_chfantasybounce[];

    return (OSThread *) D_808000A8_chfantasybounce;
}
