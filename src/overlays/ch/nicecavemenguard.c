#include "ch/nicecavemenguard.h"

OSThread *chnicecavemenguard_entrypoint_0(void)
{
    extern u8 D_80800920_chnicecavemenguard[];

    return (OSThread *) D_80800920_chnicecavemenguard;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nicecavemenguard/func_8080000C_chnicecavemenguard.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nicecavemenguard/func_808000D4_chnicecavemenguard.s")

void func_80800388_chnicecavemenguard(Actor* arg0)
{
    func_8080080C_chnicecavemenguard(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nicecavemenguard/func_808003A8_chnicecavemenguard.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nicecavemenguard/func_808004FC_chnicecavemenguard.s")

void func_808005D4_chnicecavemenguard(Actor *arg0, s32 arg1, s32 arg2) {
    void func_80102424(Actor*, s32);
    if (arg1 != 0x17E8) {
        func_80102424(arg0, 1);
    }
}

void func_80800600_chnicecavemenguard(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/nicecavemenguard/func_80800608_chnicecavemenguard.s")

void func_80800730_chnicecavemenguard(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    extern u32 D_808009E8_chnicecavemenguard;
    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_808009E8_chnicecavemenguard, 0.0f);
}

void func_8080075C_chnicecavemenguard(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_4(s32, s32, s32 *, s32 *);
    struct AudioValues { s32 values[3]; };
    extern struct AudioValues D_808009F0_chnicecavemenguard;
    extern s32 D_808009FC_chnicecavemenguard;
    struct AudioValues sp1C;

    sp1C = D_808009F0_chnicecavemenguard;
    _subaddieaudioquick_entrypoint_4((s32)arg0, (s32)((s8 *)arg0 + 4), &D_808009FC_chnicecavemenguard, sp1C.values);
}

/* extern */

void func_808007A8_chnicecavemenguard(Actor *arg0) {
    s32 _suexpression_entrypoint_12(void *, s32, s32);
    s32 _suexpression_entrypoint_17(void *, s32);
    s32 _suexpression_entrypoint_7(Actor *, s32, s32);
    s32 temp_v0;

    if (func_80100094(arg0, 1U) == NULL) {
        _suexpression_entrypoint_7(arg0, 1, 0x96);
        temp_v0 = func_80100094(arg0, 1U);
        _suexpression_entrypoint_12(temp_v0, 0x42700000, 0x41700000);
        _suexpression_entrypoint_17(temp_v0, 0x320);
    }
}

void func_8080080C_chnicecavemenguard(Actor* arg0) 
{
    if (func_80100094(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
