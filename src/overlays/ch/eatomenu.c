#include "common.h"

OSThread *chcheatomenu_entrypoint_0(void)
{
    extern u8 D_8080089C_chcheatomenu[];

    return (OSThread *) D_8080089C_chcheatomenu;
}

void func_8080000C_chcheatomenu(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eatomenu/func_80800014_chcheatomenu.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eatomenu/func_808000D4_chcheatomenu.s")

void func_80800150_chcheatomenu(Actor *arg0, s32 arg1) {
    void *_gcnewoption_entrypoint_1(s32, s32);
    if ((u32) arg0->unk70_10 == 4) {
        _gcnewoption_entrypoint_1((s32) func_80100094(arg0, 0U), arg1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eatomenu/func_80800194_chcheatomenu.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eatomenu/func_80800364_chcheatomenu.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eatomenu/func_80800428_chcheatomenu.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eatomenu/func_8080052C_chcheatomenu.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eatomenu/func_8080058C_chcheatomenu.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eatomenu/func_80800668_chcheatomenu.s")

void func_80800720_chcheatomenu(u8 *arg0) {
    s32 _capod_entrypoint_10(s32, s32 *);
    s32 _capod_entrypoint_11(s32, u8 *);
    s32 _capod_entrypoint_2(s32, s32, s32);
    s32 _capod_entrypoint_7(s32, s32);
    s32 _capod_entrypoint_8(s32);
    s32 _capod_entrypoint_9(s32, s32 *);
    s32 _gcdialogcamera_entrypoint_8();
    extern s32 D_80800880_chcheatomenu;
    extern s32 D_80800890_chcheatomenu;
    if (!((*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF)) {
        _capod_entrypoint_2((*(s32 *)((s8 *)(arg0) + (0))), 0x19, 0);
        _capod_entrypoint_8(1);
        _capod_entrypoint_9(0, &D_80800880_chcheatomenu);
        _capod_entrypoint_10(0, &D_80800890_chcheatomenu);
        _capod_entrypoint_11(0, arg0 + 0x44);
        _gcdialogcamera_entrypoint_8();
        _capod_entrypoint_7(3, 0);
        (*(u16 *)((s8 *)(arg0) + (0x6E))) = (u16) (((*(u16 *)((s8 *)(arg0) + (0x6E))) & 0xFE00) | 1);
    }
}

/* extern */

void func_808007B8_chcheatomenu(void *arg0) {
    s32 _capod_entrypoint_3(s32, void *);
    if ((*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF) {
        _capod_entrypoint_3(0, arg0);
        (*(u16 *)((s8 *)(arg0) + (0x6E))) = (u16) ((*(u16 *)((s8 *)(arg0) + (0x6E))) & 0xFE00);
    }
}

/* extern */

s32 func_80800800_chcheatomenu(void) {
    s32 func_800D3DD0(s32);
    s32 func_800D3E14(s32);
    s32 var_s0;
    s32 var_s1;

    var_s1 = 0;
    var_s0 = 1;
    do {
        if ((func_800D3DD0(var_s0) != 0) || (func_800D3E14(var_s0) != 0)) {
            var_s1 += 1;
        }
        var_s0 += 1;
    } while (var_s0 != 0xD);
    return var_s1;
}
