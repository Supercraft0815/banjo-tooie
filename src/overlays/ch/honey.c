#include "common.h"

f32 func_80800000_chhoney(void) {
    extern u8 D_8012762C;
    switch (D_8012762C) {
    case 19:
        return 1.0f;
    case 16:
        return 0.7999878f;
    case 15:
        return 0.59999084f;
    case 18:
        return 0.3999939f;
    case 20:
        return 0.2999878f;
    case 21:
        return 0.19999695f;
    case 22:
        return 0.099990845f;
    case 23:
        return 0.07499695f;
    case 24:
        return 0.049987793f;
    case 25:
        return 0.049987793f;
    case 26:
        return 0.7999878f;
    default:
        return 0.0f;
    }
}

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

/* extern */

void func_80800754_chhoney(Actor *arg0) {
    void _fxtwinkle_entrypoint_0(f32 *);
    void _subaddieskeleton_entrypoint_0(Actor *, s32, f32 *);
    f32 func_800DC178(f32, f32);
    int func_800DC298(f32);
    void func_800EF214(f32 *, f32, f32, f32);
    f32 sp60[4];
    f32 temp_f20;
    s32 var_s1;
    u32 temp_t7;

    temp_t7 = arg0->unk0->unk24 >> 22;
    if ((temp_t7 != 0x55) && ((temp_t7 == 0x22B) || (temp_t7 == 0x22C))) {
        var_s1 = 0;
        if (arg0->unk7C_12) {
            do {
                if (func_800DC298(0.03f) != 0) {
                    _subaddieskeleton_entrypoint_0(arg0, 1, sp60);
                    temp_f20 = func_800DC178(0.0f, 360.0f);
                    func_800EF214(sp60, temp_f20, func_800DC178(0.0f, 360.0f), 50.0f);
                    _fxtwinkle_entrypoint_0(sp60);
                }
                var_s1 += 1;
            } while (var_s1 != 4);
        }
    }
}

void func_80800870_chhoney(Actor *arg0, s32 arg1) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_800C4B64(f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    extern s32 D_80801028_chhoney;
    if ((*(f32 *)((s8 *)(arg0) + (0x30))) <= 0.0f) {
        func_800C4B64(func_800F10B4((f32) arg1, 1.0f, 10.0f, 0.8f, 1.5f));
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80801028_chhoney);
        (*(f32 *)((s8 *)(arg0) + (0x30))) = 0.1f;
    }
}

/* extern */

void func_808008F8_chhoney(Actor *arg0, s32 arg1) {
    s32 func_8008FC00();
    s32 func_8008FC28();
    s32 func_8008FC70(s32);
    f32 func_800D8FF8();
    s32 func_800DC128(s32, s32);
    f32 temp_f0;
    s32 temp_s0;
    s32 temp_s1;
    s32 var_a1;

    temp_f0 = func_800D8FF8();
    arg0->unk58 -= temp_f0;
    ((f32 *)arg0->actorData)[6] -= temp_f0;
    if (arg0->unk58 <= 0.0f) {
        temp_s1 = func_8008FC28() + 1;
        temp_s0 = func_8008FC00();
        var_a1 = func_800DC128(1, temp_s1);
        if (var_a1 == temp_s0) {
            do {
                var_a1 = func_800DC128(1, temp_s1);
            } while (var_a1 == temp_s0);
        }
        func_8008FC70(var_a1);
        func_80800870_chhoney(arg0, var_a1);
        arg0->unk58 = ((f32 *)arg0->actorData)[5];
    }
}

void func_808009BC_chhoney(Actor *arg0) {
    s32 func_8008FC00();
    s32 func_8008FC28();
    s32 func_8008FC70(s32);
    f32 func_800D8FF8(void);
    f32 dt;
    s32 next;

    dt = func_800D8FF8();
    arg0->unk58 -= dt;
    ((f32 *)arg0->actorData)[6] -= dt;
    if (arg0->unk58 <= 0.0f) {
        next = func_8008FC00() + 1;
        if (func_8008FC28() < next) {
            next = 1;
        }
        func_8008FC70(next);
        func_80800870_chhoney(arg0, next);
        arg0->unk58 = ((f32 *)arg0->actorData)[5];
    }
}

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
    void func_80800754_chhoney(Actor *);
    void func_808008F8_chhoney(Actor *, s32);
    void func_808009BC_chhoney(Actor *);
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

/* extern */

s32 func_80800EB0_chhoney(Actor *arg0) {
    void _subaddiefade_entrypoint_3(Actor *);
    u8 func_800D9078(f32 *);
    s32 func_800EA068(s32);
    if (arg0->unk7A_5 || arg0->unk64_17) {
        return 0;
    }
    if (func_800EA068(2) != 0) {
        return 0;
    }
    if (func_800D9078((f32 *)&arg0->actorData[4]) && arg0->unk64_16) {
        _subaddiefade_entrypoint_3(arg0);
        return 1;
    }
    return 0;
}

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
