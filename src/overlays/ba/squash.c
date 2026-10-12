#include "common.h"

s32 basquash_entrypoint_0() 
{
    return 0xC;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/squash/func_80800008_basquash.s")

void basquash_entrypoint_1(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/squash/basquash_entrypoint_2.s")

/* extern */

void basquash_entrypoint_3(void *arg0, s32 arg1) {
    s32 func_80800008_basquash(void *, s32);
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x11C)))) + (2))) = arg1;
    func_80800008_basquash(arg0, 2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/squash/func_80800140_basquash.s")

void func_80800260_basquash(void *arg0) {
    void *func_80092AD8(void *);
    s32 func_80092B80(void *);
    void func_800E0AF0(void *, f32);
    void func_800E0B8C(void *, u8, f32, f32, f32, f32);
    f32 func_800F0E00(f32, f32);
    f32 func_800F1198(f32, f32, f32, f32, f32);
    f32 sp44;
    f32 sp40;
    void *temp_v0;
    s32 sp38;
    s32 sp34;
    s32 sp30;
    s32 temp_v0_2;
    u8 temp_v0_3;

    sp30 = 0;
    sp34 = 0;
    sp38 = 0;
    temp_v0 = func_80092AD8(arg0);
    func_800E0AF0(temp_v0, 1);
    sp44 = func_800F0E00(func_800F1198(*(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x11C) + 8), 0.0f, 1.0f, 1, 0.08f), 0.08f);
    sp40 = 1 / sp44;
    temp_v0_2 = func_80092B80(arg0);
    switch (temp_v0_2) {                            
    case 0x607:                                     
    case 0x608:                                     
    case 0x61F:                                     
        sp38 = 1;
        break;
    case 0x61C:                                     
    case 0x83A:                                     
        sp34 = 1;
        break;
    case 0x60C:                                     
        sp30 = 1;
        break;
    }
    temp_v0_3 = *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x11C) + 2);
    switch (temp_v0_3) {                            
    case 1:                                         
        if (sp30 != 0) {
            func_800E0B8C(temp_v0, 0x43, 1.0f, 1.0f, sp44, 1.0f);
            return;
        }
        if (sp34 != 0) {
            func_800E0B8C(temp_v0, 0x6B, 1.0f, 1.0f, sp44, 1.0f);
            return;
        }
        if (sp38 != 0) {
            func_800E0B8C(temp_v0, 1, 1.0f, 1.0f, sp44, 1.0f);
            func_800E0B8C(temp_v0, 0x1C, 1.0f, 1.0f, sp40, 1.0f);
            func_800E0B8C(temp_v0, 0xE, 1.0f, 1.0f, sp40, 1.0f);
            return;
        }
        func_800E0B8C(temp_v0, 1, 1.0f, 1.0f, sp44, 1.0f);
        func_800E0B8C(temp_v0, 0x1C, 1.0f, 1.0f, sp40, 1.0f);
        func_800E0B8C(temp_v0, 0xE, 1.0f, 1.0f, sp40, 1.0f);
        return;
    case 2:                                         
        func_800E0B8C(temp_v0, 3, 1.0f, sp44, 1.0f, 1.0f);
        if ((sp38 != 0) || (sp34 != 0)) {
            func_800E0B8C(temp_v0, 0xA, 1.0f, sp40, sp44, 1.0f);
            func_800E0B8C(temp_v0, 0x18, 1.0f, sp40, sp44, 1.0f);
            func_800E0B8C(temp_v0, 0xE, 1.0f, sp40, sp44, 1.0f);
            func_800E0B8C(temp_v0, 0x1C, 1.0f, sp40, sp44, 1.0f);
        }
        return;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ba/squash/basquash_entrypoint_4.s")
