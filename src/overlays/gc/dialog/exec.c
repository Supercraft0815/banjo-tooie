#include "common.h"

s32 func_80800000_gcdialogexec(void *arg0, s32 arg1) {
    return arg1 == -1 ? 0 : ((u32)arg1 == ((u32)*(u16 *)((u8 *)arg0 + 0x12) >> 1));
}

/* extern */

void func_8080002C_gcdialogexec(u8 *arg0) {
    s32 _gczoombox_entrypoint_0(s32);
    s32 temp_a0;
    s32 var_s1;
    u8 *var_s0;

    var_s0 = arg0;
    var_s1 = 0;
    do {
        _gczoombox_entrypoint_0((*(s32 *)((s8 *)(var_s0) + (0x120))));
        var_s1 += 1;
        var_s0 += 4;
        (*(s32 *)((s8 *)(var_s0) + (0x11C))) = 0;
    } while (var_s1 != 2);
    temp_a0 = (*(s32 *)((s8 *)(arg0) + (0x12C)));
    if (temp_a0 != 0) {
        _gczoombox_entrypoint_0(temp_a0);
        (*(s32 *)((s8 *)(arg0) + (0x12C))) = 0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/dialog/exec/func_808000A0_gcdialogexec.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/dialog/exec/func_80800164_gcdialogexec.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/dialog/exec/func_808001DC_gcdialogexec.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/dialog/exec/func_808002E4_gcdialogexec.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/dialog/exec/func_80800350_gcdialogexec.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/dialog/exec/func_80800478_gcdialogexec.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/dialog/exec/func_8080052C_gcdialogexec.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/dialog/exec/func_8080064C_gcdialogexec.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/dialog/exec/func_80800A50_gcdialogexec.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/dialog/exec/func_80800D30_gcdialogexec.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/dialog/exec/func_80800F60_gcdialogexec.s")

s32 func_80801008_gcdialogexec(s32 arg0) {
    s32 result = 0xC8;
    return arg0 ? 0x1C : result;
}

s32 func_80801020_gcdialogexec(s32 arg0) {
    s32 result = 0;
    return arg0 ? 1 : result;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/dialog/exec/func_80801038_gcdialogexec.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/dialog/exec/func_808011A4_gcdialogexec.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/dialog/exec/func_80801268_gcdialogexec.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/dialog/exec/gcdialogexec_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/dialog/exec/gcdialogexec_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/dialog/exec/gcdialogexec_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/dialog/exec/gcdialogexec_entrypoint_3.s")

s32 gcdialogexec_entrypoint_4(s32 text_id, s32 arg1, f32 *pos, void *marker, void *callback, void *arg5) {
    s32 func_808011A4_gcdialogexec(s32, s32, f32 *, void *, void *, void *);
    return func_808011A4_gcdialogexec(text_id, arg1, pos, marker, callback, arg5);
}

void gcdialogexec_entrypoint_5()
{
    func_80800D30_gcdialogexec();
}

void gcdialogexec_entrypoint_6()
{
    func_80800A50_gcdialogexec();
}

void gcdialogexec_entrypoint_7()
{
    func_80800164_gcdialogexec();
}

void gcdialogexec_entrypoint_8(s32 arg0)
{
    func_80800A50_gcdialogexec(arg0,0x2);
}

void gcdialogexec_entrypoint_9()
{
    func_80800F60_gcdialogexec();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/dialog/exec/func_80801DB4_gcdialogexec.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/dialog/exec/func_80802020_gcdialogexec.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/dialog/exec/gcdialogexec_entrypoint_10.s")
