#include "common.h"

OSThread *chklungoleave_entrypoint_0(void)
{
    extern u8 D_80800130_chklungoleave[];

    return (OSThread *) D_80800130_chklungoleave;
}

/* extern */

void func_8080000C_chklungoleave(Actor *arg0) {
    void func_80105A9C(Actor*, f32);
    s32 func_80105BAC(Actor *);
    func_80105A9C(arg0, 300.0f);
    func_80105BAC(arg0);
}

void func_80800038_chklungoleave(s32 arg0)
{
    func_80105834();
    func_808000F0_chklungoleave(arg0);
}
/* extern */

s32 func_80800060_chklungoleave(Actor *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    s32 _glcutDll_entrypoint_19(u32);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    void func_800FFAB0(Actor *);
    switch (arg1) {
    case 0x95:
        if (_glcutDll_entrypoint_19(0x5B) != 0) {
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x162E, 0x44, arg0->position, 0xAB);
            _capod_entrypoint_13(arg0->unk0, NULL, 6, 0x2911);
        } else {
            func_800FFAB0(arg0);
        }
        break;
    default:
        return 0;
    }
    return 1;
}

int func_808000F0_chklungoleave(s32 arg0) { s32 func_80105230(); extern s32 D_80800178_chklungoleave; func_80105230(arg0, &D_80800178_chklungoleave); }
