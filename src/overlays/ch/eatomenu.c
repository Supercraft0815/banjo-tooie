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

void *func_80100094(Actor *, u32);

void func_80800150_chcheatomenu(Actor *arg0, s32 arg1) {
    void *_gcnewoption_entrypoint_1(s32, s32);
    if ((u32) arg0->unk70_10 == 4) {
        _gcnewoption_entrypoint_1((s32) func_80100094(arg0, 0U), arg1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eatomenu/func_80800194_chcheatomenu.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eatomenu/func_80800364_chcheatomenu.s")

/* extern */

void func_80800428_chcheatomenu(s32 arg0, s32 arg1) {
    s32 _gcnewoption_entrypoint_21(s32, s32);
    s32 _gcnewoption_entrypoint_22(s32, s32);
    s32 _gcnewoption_entrypoint_23(s32, s32);
    s32 _gcnewoption_entrypoint_31(s32, s32, s16);
    s32 func_800D3DD0(s32);
    s32 func_800D3E14(s32);
    s32 func_800D3E40(s32);
    s16 func_800D3FC0(s32);
    s32 func_80800194_chcheatomenu(s32, s32, s32, s32);
    s32 var_s0;
    s32 var_s1;

    var_s0 = 0;
    var_s1 = 1;
    do {
        _gcnewoption_entrypoint_31(arg1, var_s0, func_800D3FC0(var_s1));
        if (func_800D3E14(var_s1) != 0) {
            if (func_800D3E40(var_s1) != 0) {
                _gcnewoption_entrypoint_21(arg1, var_s0);
            } else {
                _gcnewoption_entrypoint_22(arg1, var_s0);
            }
            func_80800194_chcheatomenu(arg0, arg1, var_s0, 0);
            goto block_8;
        }
        if (func_800D3DD0(var_s1) != 0) {
            _gcnewoption_entrypoint_23(arg1, var_s0);
            func_80800194_chcheatomenu(arg0, arg1, var_s0, 0);
block_8:
            var_s0 += 1;
        }
        var_s1 += 1;
    } while (var_s1 != 0xD);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eatomenu/func_8080052C_chcheatomenu.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eatomenu/func_8080058C_chcheatomenu.s")

void func_80800668_chcheatomenu(Actor *arg0) {
    void _gcnewoption_entrypoint_10(void *, u8);
    void _gcnewoption_entrypoint_11(void *);
    void _gcnewoption_entrypoint_4(Actor *, u32, s32 *, s32 *, s32);
    void _gcnewoption_entrypoint_8(void *, u32);
    void _gcnewoption_entrypoint_9(void *, u32);
    void func_80090708(s32);
    s32 func_800F1418(s32, s32);
    void func_80101FDC(Actor *, u32);
    s32 func_80800364_chcheatomenu(Actor *, void *);
    s32 func_80800800_chcheatomenu();
    extern s32 _gcnewoption_entrypoint_15;
    extern s32 _gcnewoption_entrypoint_35;
    s32 optionCounts[3];
    void *temp_s0;
    s32 visibleOptions;

    optionCounts[0] = func_80800800_chcheatomenu();
    _gcnewoption_entrypoint_4(arg0, 0, &_gcnewoption_entrypoint_15, &_gcnewoption_entrypoint_35, 0x1848);
    temp_s0 = func_80100094(arg0, 0);
    visibleOptions = func_800F1418(5, optionCounts[0]);
    _gcnewoption_entrypoint_8(temp_s0, visibleOptions);
    _gcnewoption_entrypoint_9(temp_s0, optionCounts[0]);
    _gcnewoption_entrypoint_10(temp_s0, 1);
    func_80800364_chcheatomenu(arg0, temp_s0);
    _gcnewoption_entrypoint_11(temp_s0);
    func_80101FDC(arg0, 4);
    func_80090708(2);
}

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
