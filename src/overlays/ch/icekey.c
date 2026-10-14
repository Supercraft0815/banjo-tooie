#include "common.h"

s32 func_80800000_chicekey(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800D1844(s32);
    void func_800FC660(u32);
    void func_800FFA88(Unk80132ED0 *);
    extern s32 D_808000A0_chicekey;
    f32 *sp24[1];

    if (arg1 == 0x3E) {
        sp24[0] = arg0->position; func_800BBCB8(sp24[0], sp24[0], 1.0f, 0x14, &D_808000A0_chicekey);
        func_800D1844(0x53);
        _subaddiedialog_entrypoint_11(arg0->unk0, 0x1550, 4, sp24[0], 0x6F);
        func_800FC660(0xE);
        func_800FFA88(arg0->unk0);
        return 1;
    }
    return 0;
}

OSThread *chicekey_entrypoint_0(void)
{
    extern u8 D_808000EC_chicekey[];

    return (OSThread *) D_808000EC_chicekey;
}
