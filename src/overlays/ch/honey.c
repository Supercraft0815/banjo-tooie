#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/honey/func_80800000_chhoney.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/honey/func_808000C4_chhoney.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/honey/func_80800244_chhoney.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/honey/func_80800328_chhoney.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/honey/func_8080046C_chhoney.s")

void func_80800634_chhoney(Actor *arg0) {
    s32 func_8010DCB4(s32);
    extern s32 D_80127194;

    D_80127194 -= 1;
    if (arg0->unk64_19) {
        func_8010DCB4(arg0->unk64_20 ? 2 : 3);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/honey/func_80800688_chhoney.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/honey/func_80800754_chhoney.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/honey/func_80800870_chhoney.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/honey/func_808008F8_chhoney.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/honey/func_808009BC_chhoney.s")

void func_80800A5C_chhoney(u8 *arg0) {
    struct HoneyFlags {
        u8 pad64[0x64];
        u32 :11;
        u32 mode:1;
        u32 valid:1;
        u32 :19;
        u8 pad70[8];
        u32 :16;
        u32 state:6;
        u32 :10;
        u32 pad74;
        u32 :28;
        u32 active:1;
        u32 :3;
    };
    struct HoneyMarker {
        u8 pad24[0x24];
        u32 id:10;
        u32 :22;
    };
    s32 _subaddieaudioloop_entrypoint_4(u8 *, u8 *, s32, s32 *);
    s32 func_80016B30(s32, s32);
    s32 func_8008FBE0(s32);
    s32 func_8008FC00();
    s32 func_8008FC28();
    s32 func_8008FC70(s32);
    s32 func_80090080();
    s32 func_80090708(s32);
    s32 func_800C3FC0(s32, f32, s32);
    s32 func_800CE88C(s32, s32);
    s32 func_800CEAD0(s32);
    f32 func_800D8FF8();
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    s32 func_800FA9F4(s32, s32);
    s32 func_800FFAB0(u8 *);
    s32 func_8010A570(u8 *);
    s32 func_8010A590(u8 *);
    s32 func_8010CAC0(u8 *, s32);
    s32 func_8010DC50(s32);
    s32 func_8010DCB4(s32);
    s32 func_808000C4_chhoney(u8 *, s32);
    s32 func_80800754_chhoney(u8 *);
    s32 func_808008F8_chhoney(u8 *, s32);
    s32 func_808009BC_chhoney(u8 *);
    s32 func_80800EB0_chhoney();
    extern s32 D_80801038_chhoney;
    f32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 temp_f4;
    s32 temp_v0;
    s32 temp_v1;
    s32 temp_v1_2;
    u32 temp_t6;
    u32 temp_t7;
    u32 temp_t8;
    u8 temp_t3;

    func_80800EB0_chhoney();
    if (((struct HoneyFlags *)arg0)->mode != ((struct HoneyFlags *)arg0)->active) {
        if (((struct HoneyFlags *)arg0)->active) {
            if (((struct HoneyFlags *)arg0)->valid) {
                func_8010DCB4(3);
            }
            func_8010DC50(2);
        } else {
            if (((struct HoneyFlags *)arg0)->valid) {
                func_8010DCB4(2);
            }
            func_8010DC50(3);
        }
        ((struct HoneyFlags *)arg0)->mode = ((struct HoneyFlags *)arg0)->active;
        ((struct HoneyFlags *)arg0)->valid = 1;
    }
    sp34 = func_800D8FF8();
    temp_v0 = func_8008FC28();
    sp30 = temp_v0;
    switch (((struct HoneyFlags *)arg0)->state) {
    case 1:
        if (temp_v0 == 0) {
            func_8010A570(arg0);
        } else {
            func_8010A590(arg0);
        }
        if ((((*(struct HoneyMarker **)arg0)->id == 0x22B) || ((*(struct HoneyMarker **)arg0)->id == 0x22C)) && (func_8010CAC0(arg0 + 4, 0x1F4) != 0) && (sp30 != 0)) {
            func_8008FBE0(1);
        }
        func_80800754_chhoney(arg0);
        return;
    case 7:
        func_8008FBE0(1);
        return;
    case 2:
        func_8008FBE0(1);
        func_808008F8_chhoney(arg0, 1);
        if ((func_80090080() != 0) && (func_80016B30(0, 1) != 0)) {
            func_800CE88C(6, 0);
            func_808000C4_chhoney(arg0, 5);
            return;
        }
        if (func_800CEAD0(6) != 0) {
            func_808000C4_chhoney(arg0, 5);
            return;
        }
    default:
        return;
    case 8:
        func_8008FBE0(1);
        return;
    case 3:
        func_8008FBE0(1);
        func_808009BC_chhoney(arg0);
        if ((func_80090080() != 0) && (func_80016B30(0, 1) != 0)) {
            func_800CE88C(6, 0);
            func_808000C4_chhoney(arg0, 5);
            return;
        }
        if (func_800CEAD0(6) != 0) {
            func_808000C4_chhoney(arg0, 5);
            return;
        }
        break;
    case 5:
        func_8008FBE0(1);
        func_800FA9F4(0, 1);
        (*(f32 *)((s8 *)(arg0) + (0x58))) = (f32) ((*(f32 *)((s8 *)(arg0) + (0x58))) + (sp34 * 4.0f));
        if ((*(f32 *)((s8 *)(arg0) + (0x58))) > 0.2f) {
            (*(f32 *)((s8 *)(arg0) + (0x24))) = (f32) ((*(f32 *)((s8 *)(arg0) + (0x24))) + 1.0f);
            if ((*(f32 *)((s8 *)(arg0) + (0x24))) > 10.0f) {
                func_808000C4_chhoney(arg0, 4);
            } else {
                func_808000C4_chhoney(arg0, 6);
            }
        }
        _subaddieaudioloop_entrypoint_4(arg0, arg0 + 4, 1, &D_80801038_chhoney);
        return;
    case 6:
        func_8008FBE0(1);
        func_800FA9F4(0, 2);
        (*(f32 *)((s8 *)(arg0) + (0x58))) = (f32) ((*(f32 *)((s8 *)(arg0) + (0x58))) + (sp34 * 4.0f));
        if ((*(f32 *)((s8 *)(arg0) + (0x58))) > 0.2f) {
            func_808000C4_chhoney(arg0, 5);
        }
        _subaddieaudioloop_entrypoint_4(arg0, arg0 + 4, 1, &D_80801038_chhoney);
        return;
    case 4:
        func_8008FBE0(1);
        (*(f32 *)((s8 *)(arg0) + (0x58))) = (f32) ((*(f32 *)((s8 *)(arg0) + (0x58))) - func_800D8FF8());
        if ((*(f32 *)((s8 *)(arg0) + (0x58))) <= 0.0f) {
            temp_v1_2 = func_8008FC00() + 1;
            temp_f4 = temp_v1_2;
            (*(f32 *)((s8 *)(arg0) + (0x58))) = 0.2f;
            sp2C = temp_v1_2;
            func_800C3FC0(0x66C, func_800F10B4((f32) temp_f4, 1.0f, 10.0f, 0.8f, 1.5f), 0x3E80);
            func_8008FC70(sp2C);
            if (sp2C == ((*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF)) {
                func_80090708(0);
                func_800FFAB0(arg0);
            }
        }
        break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/honey/func_80800EB0_chhoney.s")

OSThread *chhoney_entrypoint_0(void)
{
    extern u8 D_80801048_chhoney[];

    return (OSThread *) D_80801048_chhoney;
}

OSThread *chhoney_entrypoint_1(void)
{
    extern u8 D_80801090_chhoney[];

    return (OSThread *) D_80801090_chhoney;
}

OSThread *chhoney_entrypoint_2(void)
{
    extern u8 D_808010D8_chhoney[];

    return (OSThread *) D_808010D8_chhoney;
}
