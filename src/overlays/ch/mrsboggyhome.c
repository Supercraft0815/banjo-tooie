#include "common.h"

OSThread *chmrsboggyhome_entrypoint_0(void)
{
    extern u8 D_808001F0_chmrsboggyhome[];

    return (OSThread *) D_808001F0_chmrsboggyhome;
}

/* extern */

void func_8080000C_chmrsboggyhome(s32 arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 func_800DA298(s32);
    s32 func_800FFAB0(s32);
    s32 func_80102424(s32, s32);
    if (_glcutDll_entrypoint_20() != 0) {
        func_80102424(arg0, 3);
        return;
    }
    if (func_800DA298(0x1CD) == 0) {
        func_800FFAB0(arg0);
    }
}

/* extern */

void func_8080005C_chmrsboggyhome(Actor *arg0) {
    void _sudeflect_entrypoint_1(f32 *, f32, f32, f32, s32);
    void _suexpression_entrypoint_10(u32 *, Unk80132ED0 *, u32);
    u32 *_suexpression_entrypoint_20(Actor *);
    void func_80800174_chmrsboggyhome(s32);
    _sudeflect_entrypoint_1(arg0->position, 200.0f, 0.0f, 100.0f, 0xA);
    _suexpression_entrypoint_10(_suexpression_entrypoint_20(arg0), arg0->unk0, 0);
    if (arg0->unk70_10 == 1) {
        func_80800174_chmrsboggyhome(arg0);
    }
}

void func_808000D0_chmrsboggyhome(Actor* arg0) 
{
    _suexpression_entrypoint_8(arg0, 1);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mrsboggyhome/func_808000F0_chmrsboggyhome.s")

void func_80800174_chmrsboggyhome(s32 arg0) {
    s32 _subaddiedialog_entrypoint_8(s32, void *, s32 *, s32 *, s32);
    extern s32 D_808001B0_chmrsboggyhome;
    extern s32 D_80800238_chmrsboggyhome;
    _subaddiedialog_entrypoint_8(arg0, (s8 *)arg0 + 4, &D_80800238_chmrsboggyhome, &D_808001B0_chmrsboggyhome, 4);
}
