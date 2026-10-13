#include "common.h"

OSThread *chhoneyb_entrypoint_0(void)
{
    extern u8 D_80801020_chhoneyb[];

    return (OSThread *) D_80801020_chhoneyb;
}

OSThread *chhoneyb_entrypoint_1(void)
{
    extern u8 D_80801068_chhoneyb[];

    return (OSThread *) D_80801068_chhoneyb;
}

void func_80800018_chhoneyb(Actor *arg0, u32 arg1, u32 arg2) {
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0*, u32, u32, f32*, u32);
    _subaddiedialog_entrypoint_11(arg0->unk0, arg1, arg2, arg0->position, 0x9BU);
    func_80102424(arg0, 2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/honeyb/func_80800058_chhoneyb.s")

/* extern */

void func_8080011C_chhoneyb(void *arg0) {
    s32 func_8008FC28();
    s32 func_80090708(s32);
    s32 func_800FC6B0(s32);
    s32 temp_v0;

    func_80090708(2);
    func_80102424(arg0, 3);
    (*(f32 *)((s8 *)(arg0) + (0x34))) = 1.0f;
    (*(f32 *)((s8 *)(arg0) + (0x58))) = 0.25f;
    temp_v0 = func_8008FC28();
    (*(s32 *)((s8 *)(arg0) + (0x30))) = temp_v0;
    (*(s32 *)((s8 *)(arg0) + (0x24))) = (s32) ((*(s32 *)((s8 *)(arg0) + (0x28))) + temp_v0);
    (*(u8 *)((s8 *)(arg0) + (0x74))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x74))) & 0xFFBF);
    func_800FC6B0(0xA);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/honeyb/func_80800194_chhoneyb.s")

/* extern */

void func_80800240_chhoneyb(s32 arg0) {
    s32 _suexpression_entrypoint_20();
    s32 _suexpression_entrypoint_8(s32, s32);
    s32 _susubgame_entrypoint_2(s32, s32);
    s32 _susubgame_entrypoint_4(s32, s32);
    s32 func_80100094(s32, s32);
    if (_suexpression_entrypoint_20() != 0) {
        _suexpression_entrypoint_8(arg0, 0);
    }
    if (_susubgame_entrypoint_2(arg0, func_80100094(arg0, 1)) != 0) {
        _susubgame_entrypoint_4(arg0, func_80100094(arg0, 1));
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/honeyb/func_808002AC_chhoneyb.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/honeyb/func_8080062C_chhoneyb.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/honeyb/func_80800680_chhoneyb.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/honeyb/func_80800744_chhoneyb.s")

/* extern */

s32 func_80800920_chhoneyb(u8 *arg0, s32 arg1, s32 arg2) {
    s32 func_80800BD8_chhoneyb();
    s32 var_v0;

    if (arg1 == 0x1520) {
        return func_80800BD8_chhoneyb();
    }
    if (arg1 == 0x151B) {
        return (*(s32 *)((s8 *)(arg0) + (0x28)));
    } else {
        return -1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/honeyb/func_80800968_chhoneyb.s")

void func_80800B2C_chhoneyb(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_4(Actor*, f32*, u32, u32*);
    extern u32 D_808010D0_chhoneyb;
    _subaddieaudioloop_entrypoint_4(arg0, (f32 *) ((u8 *) arg0 + 4), 1U, &D_808010D0_chhoneyb);
}

void func_80800B58_chhoneyb()
{
    func_800D1A04(0x49);
}

s32 func_80800B78_chhoneyb()
{
    s32 _gcextra_entrypoint_0();
    return _gcextra_entrypoint_0();
}

/* extern */

s32 func_80800B98_chhoneyb(s32 arg0) {
    s32 _gcextra_entrypoint_1();
    if ((arg0 <= 0) || (_gcextra_entrypoint_1() < arg0)) {
        return -1;
    }
    return (arg0 * 2) - 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/honeyb/func_80800BD8_chhoneyb.s")

void func_80800C0C_chhoneyb(void) {
    func_80800B98_chhoneyb(func_80800B78_chhoneyb() + 1);
}

void func_80800C34_chhoneyb(u8 *arg0) {
    void func_8010A3E8(void *arg0, f32 arg1);
    func_8010A3E8(arg0, 0.7f);
}

void func_80800C58_chhoneyb()
{
    func_8010C964();
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/honeyb/func_80800C78_chhoneyb.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/honeyb/chhoneyb_entrypoint_2.s")
