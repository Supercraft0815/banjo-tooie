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

s32 func_80800118_chchompaslunch(Actor *arg0, s32 arg1, s32 arg2) {
    void func_8080017C_chchompaslunch(Actor *);
    s32 *data = &arg2;
    switch (arg1) {
        case 0x1F:
            func_8080017C_chchompaslunch(arg0);
            break;
        case 0xBC:
            func_800FFAB0(arg0);
            break;
        default:
            return 0;
    }
    return 1;
}

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

void func_80800250_chchompaslunch(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_4(Actor *, f32 *, u32 *, u32 *);
    void func_800C301C(u8, s32);
    void func_800C3058(u8, s32);
    void func_800C31DC(u8, f32);
    void func_800C3BDC(u8);
    u8 func_800C4350(s32, f32[3], s32 *);
    f32 func_800DC178(f32, f32);
    s32 func_80101E14(Actor *, f32);
    extern u32 D_8080044C_chchompaslunch;
    extern u32 D_80800458_chchompaslunch;
    extern f32 D_80800468_chchompaslunch[];
    extern f32 D_80800478_chchompaslunch[];
    extern s16 D_80800488_chchompaslunch[];
    extern s16 D_80800490_chchompaslunch[];
    extern s32 D_80800498_chchompaslunch;
    s32 i;
    f32 *ptr;
    s32 offset;
    s32 result;

    if (arg0->unk5F == 0) {
        arg0->unk5F = func_800C4350(0, arg0->position, &D_80800498_chchompaslunch);
    }
    ptr = D_80800468_chchompaslunch;
    i = 0;
    offset = 0;
    do {
    result = func_80101E14(arg0, *ptr);
    ptr++;
    if (result != 0) {
        func_800C301C(arg0->unk5F, D_80800488_chchompaslunch[i]);
        func_800C31DC(arg0->unk5F, *(f32 *)((u8 *)D_80800478_chchompaslunch + offset) + func_800DC178(-0.02f, 0.02f));
        func_800C3058(arg0->unk5F, D_80800490_chchompaslunch[i]);
        func_800C3BDC(arg0->unk5F);
        break;
    }
    i++;
    offset += 4;
    } while (i != 4);
    if (!arg0->unk6C_0) {
        _subaddieaudioquick_entrypoint_4(arg0, arg0->position, &D_8080044C_chchompaslunch, &D_80800458_chchompaslunch);
    }
}

void func_8080037C_chchompaslunch(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    extern u32 D_808004A4_chchompaslunch;
    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_808004A4_chchompaslunch, 0.0f);
}
