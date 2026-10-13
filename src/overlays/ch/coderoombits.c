#include "common.h"

OSThread *chcoderoombits_entrypoint_0(void)
{
    extern u8 D_80801170_chcoderoombits[];

    return (OSThread *) D_80801170_chcoderoombits;
}

void func_8080000C_chcoderoombits(Actor *arg0) {
    u32* func_80100074(Actor*, u32, u32);
    s32 _susubgame_entrypoint_0(Actor *, u32 *, s32);
    s32 _susubgame_entrypoint_12(u32 *, s32 *);
    extern s32 D_80801308_chcoderoombits;
    u32 *sp1C;
    u32 *temp_v0;

    temp_v0 = func_80100074(arg0, 0U, 0x182U);
    sp1C = temp_v0;
    _susubgame_entrypoint_0(arg0, temp_v0, 1);
    _susubgame_entrypoint_12(sp1C, &D_80801308_chcoderoombits);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/func_80800058_chcoderoombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/func_8080033C_chcoderoombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/func_8080040C_chcoderoombits.s")

struct CodeRoomBit { s32 unk0; s32 unk4; u8 unk8[2]; u8 flag; };
extern struct CodeRoomBit D_808011F4_chcoderoombits[];
void *func_80100094(Actor *, u32);
s32 func_80800E28_chcoderoombits(Actor *);

void func_808004B8_chcoderoombits(Actor *arg0) {
    void *sp1C;
    struct CodeRoomBit *bit;
    s16 *room;

    sp1C = func_80100094(arg0, 0U);
    room = (s16 *)func_80100094(arg0, 0U) + 0xAA;
    bit = D_808011F4_chcoderoombits;
    if (bit->unk0 != 0) {
        do {
            *room = 0;
            bit++;
            room++;
        } while (bit->unk0 != 0);
    }
    *(u8 *)((u8 *)sp1C + 0x19) = 0;
    func_80800E28_chcoderoombits(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/func_8080052C_chcoderoombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/func_8080077C_chcoderoombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/func_8080091C_chcoderoombits.s")

void func_80800998_chcoderoombits(Actor *arg0) {
    struct CodeRoomBit *bit;
    s16 *room;

    room = (s16 *)func_80100094(arg0, 0) + 0xAA;
    bit = D_808011F4_chcoderoombits;
    if (bit->unk0 != 0) {
        do {
            if (bit->flag == 0) {
                *room = 0;
            }
            bit++;
            room += 1;
        } while (bit->unk0 != 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/chcoderoombits_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/func_80800B40_chcoderoombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/func_80800BF4_chcoderoombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/func_80800D90_chcoderoombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/func_80800E28_chcoderoombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/chcoderoombits_entrypoint_2.s")

s32 func_80800FDC_chcoderoombits(void) {
    s32 func_800D3E14(s32);
    s32 var_s0;
    s32 var_s1;
    s32 var_s2;

    var_s1 = 0;
    var_s0 = 1;
    var_s2 = 0xD;

    do {
        if (func_800D3E14(var_s0) != 0) {
            var_s1 += 1;
        }
        var_s0 += 1;
    } while (var_s0 != var_s2);
    return var_s1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/R_80801040_chcoderoombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/R_80801048_chcoderoombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/R_80801054_chcoderoombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/R_8080105C_chcoderoombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/R_80801068_chcoderoombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/R_80801074_chcoderoombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/R_8080107C_chcoderoombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/R_80801088_chcoderoombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/R_80801090_chcoderoombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/R_8080109C_chcoderoombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/R_808010A8_chcoderoombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/R_808010B4_chcoderoombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/R_808010C0_chcoderoombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/R_808010CC_chcoderoombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/R_808010D4_chcoderoombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/R_808010E0_chcoderoombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/R_808010EC_chcoderoombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/R_808010F4_chcoderoombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/R_80801100_chcoderoombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/R_80801108_chcoderoombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/R_8080111C_chcoderoombits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/coderoombits/R_80801128_chcoderoombits.s")
