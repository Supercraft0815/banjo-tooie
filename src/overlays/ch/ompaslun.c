#include "common.h"

OSThread *chchompaslunch_entrypoint_0(void)
{
    extern u8 D_808003E0_chchompaslunch[];

    return (OSThread *) D_808003E0_chchompaslunch;
}

void func_8080000C_chchompaslunch(Actor *arg0) {
    if (_glcutDll_entrypoint_20() == 0) {
        func_800FFAB0(arg0);
    }
    arg0->unk58 = 8.0f;
    arg0->unk6C_0 = func_800DC128(0, 3);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/ompaslun/func_80800070_chchompaslunch.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/ompaslun/func_80800118_chchompaslunch.s")

void func_8080017C_chchompaslunch(Actor *arg0) {
    void func_800DF744(s32, s32);
    s32 func_801015D0(Actor *);
    extern s16 D_80800428_chchompaslunch[][6];
    extern s16 D_8080042A_chchompaslunch[][6];
    extern s16 D_8080042C_chchompaslunch[][6];
    extern s16 D_8080042E_chchompaslunch[][6];
    func_801015D0(arg0);
    func_800DF744(4, D_80800428_chchompaslunch[arg0->unk6C_0][0]);
    func_800DF744(5, D_8080042A_chchompaslunch[arg0->unk6C_0][0]);
    func_800DF744(6, D_8080042C_chchompaslunch[arg0->unk6C_0][0]);
    func_800DF744(7, 0);
    func_800DF744(8, D_8080042E_chchompaslunch[arg0->unk6C_0][0]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/ompaslun/func_80800250_chchompaslunch.s")

void func_8080037C_chchompaslunch(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    extern u32 D_808004A4_chchompaslunch;
    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_808004A4_chchompaslunch, 0.0f);
}
