#include "common.h"

/* extern */

void func_80800000_chhumba(s32 *arg0, s32 arg1) {
    s32 _capod_entrypoint_2(s32, s32, s32);
    _capod_entrypoint_2(*arg0, 9, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/humba/func_80800028_chhumba.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/humba/func_808000D4_chhumba.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/humba/func_8080015C_chhumba.s")

/* extern */

void func_808001E4_chhumba(Actor *arg0) {
    s32 _capod_entrypoint_3(s32);
    s32 func_800DA298(s32);
    if ((func_800DA298(0x9C7) != 0) && (arg0->unk74_7 != 0)) {
        _capod_entrypoint_3(0);
        arg0->unk74_7 = 0;
    }
}

void func_80800238_chhumba(u8 *arg0, f32 *arg1) {
    void func_800EFA4C(f32[3], f32, f32, f32);
    func_800EFA4C(arg1, 0.0f, (*(f32 *)((s8 *)(arg0) + (0x38))) * 5.0f * -50.0f, 0.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/humba/func_80800294_chhumba.s")

void func_80800338_chhumba(u8 *arg0, s32 arg1, s32 arg2) {
    struct Flags { u8 pad[0x74]; u8 high : 1; u8 flag : 1; u8 low : 6; };
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0*, u32, u32, f32*, u32);
    arg2 |= 4;
    _subaddiedialog_entrypoint_11(*(Unk80132ED0 **)arg0, arg1, arg2, (f32 *)(arg0 + 4), 0x40U);
    ((struct Flags *)arg0)->flag = 1;
}

s32 func_80800384_chhumba(u8 *arg0) {
    s32 func_800EA05C();
    extern s32 D_80802648_chhumba;
    if (func_800EA05C() == 0x122) {
        return 0x13;
    }
    return ((s32 *)(&D_80802648_chhumba))[((*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF)];
}

s32 func_808003CC_chhumba(u8 *arg0) {
    s32 func_800EA05C();
    extern s16 D_8080266E_chhumba[];
    if (func_800EA05C() == 0x122) {
        return 0x11AA;
    }
    return D_8080266E_chhumba[((*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF)];
}

/* extern */

s32 func_80800414_chhumba(void *arg0) {
    s32 func_800EA05C();
    if (func_800EA05C() == 0x122) {
        return 0x346;
    }
    return ((*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF) + 0x346;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/humba/func_80800450_chhumba.s")

s32 func_8080071C_chhumba(s32 arg0) {
    s32 func_800EA05C();
    s32 map;

    map = func_800EA05C();
    switch (map) {
        case 0xB6:
            return 1;
        case 0xD5:
            return 3;
        case 0xE9:
            return 2;
        case 0x11E:
        case 0x122:
            return 5;
        case 0x120:
            return 4;
        case 0x11F:
            return 6;
        case 0x135:
            return 7;
        case 0x140:
            return 8;
        case 0x157:
            return 9;
        default:
            return 0;
    }
}

s32 func_808007EC_chhumba(s32 arg0) {
    return 1;
}

/* extern */

void func_808007F8_chhumba(Actor *arg0) {
    void func_800D175C(s32, s32);
    void func_800DA544(GameFlag);
    func_800DA544(arg0->unk6C_0 + 0xD5);
    if (arg0->unk74_29) {
        func_800D175C(0x54, -func_808007EC_chhumba((s32) arg0));
    } else {
        func_800D175C(0x48, -func_808007EC_chhumba((s32) arg0));
    }
    arg0->unk64_20 = 1;
}

/* extern */

void func_80800878_chhumba(void *arg0) {
    s32 func_800DA298(s32);
    func_800DA298(((*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF) + 0xD5);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/humba/func_808008A0_chhumba.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/humba/func_80800934_chhumba.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/humba/func_80800A50_chhumba.s")

/* extern */

s32 func_80800B40_chhumba(u8 *arg0) {
    s32 func_8008F8B0();
    void func_8008F8D8(s32);
    void func_8008F904(void*, s32);
    void func_8008F938(s32);
    extern s32 func_8010D5DC;
    s32 func_8008F9F8(u8 *, s32);
    s32 func_8080015C_chhumba(u8 *, s32, s32, s32);
    func_8080015C_chhumba(arg0, 0, 0x60, 0);
    func_8008F8B0();
    func_8008F8D8(1);
    func_8008F938(1);
    func_8008F904(&func_8010D5DC, *(s32 *)arg0);
    func_8008F9F8(arg0 + 0x28, 0x43480000);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/humba/func_80800BA8_chhumba.s")

s32 func_80800C20_chhumba(u8 *arg0) {
    s32 func_800F1EA4(f32[3], f32 *);
    s32 func_800F20BC(f32, f32, s32);
    void func_8010D254(f32*);
    f32 sp24;
    f32 sp18[3];

    (void)&arg0;
    func_8010D254(&sp18);
    func_800F1EA4(&sp18, &sp24);
    if (func_800F20BC(0.0f, sp24, 0x40A00000) == 0) {
        return 1;
    }
    return 0;
}

/* extern */

void func_80800C6C_chhumba(s32 *arg0) {
    s32 func_8008F8B0();
    void func_8008F8D8(s32);
    void func_8008F904(void*, s32);
    void func_8008F938(s32);
    void func_8008F990(s32, f32);
    extern s32 func_8010D5DC;
    s32 func_80800BA8_chhumba(s32 *, s32 *);
    s32 pad[2];
    s32 sp1C;

    func_80800BA8_chhumba(arg0, &sp1C);
    func_8008F8B0();
    func_8008F8D8(1);
    func_8008F938(1);
    func_8008F904(&func_8010D5DC, *arg0);
    func_8008F990((s32) &sp1C, 300.0f);
}

void func_80800CC8_chhumba(Actor *volatile arg0) {
    void func_8008FB10(s32, f32, f32, f32);
    extern s32 D_80802694_chhumba;
    f32 temp_f0;

    temp_f0 = arg0->scale;
    func_8008FB10((s32) &D_80802694_chhumba, temp_f0 * 1600.0f, temp_f0 * 72.0f, temp_f0 * 350.0f);
}

/* extern */

s32 func_80800D2C_chhumba(s32 arg0) {
    s32 func_800DA9E4(s32, s32);
    void func_80800338_chhumba(u8 *, s32, s32);
    if (func_800DA9E4(0xE2, 1) == 0) {
        func_80800338_chhumba(arg0, 0x11B5, 0xF);
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/humba/func_80800D74_chhumba.s")

void func_80800E44_chhumba(u8 *arg0, s32 arg1) {
    s32 _fxsplash25d_entrypoint_0(f32 *);
    s32 _fxsplash_entrypoint_1(f32 *);
    s32 _subaddieaudioquick_entrypoint_2(u8 *, u8 *, s32 *);
    s32 func_8008FD48(void);
    Unk80132ED0 *func_8008FDEC(void);
    s32 func_80090658(s32);
    s32 func_80090708(s32);
    s32 func_80090768(f32 *);
    s32 func_800907EC(s32);
    s32 func_8009EA2C(void);
    void func_8009EAAC(s32);
    s32 func_800DA9E4(s32, s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800FC660(u32);
    void func_800FC6B0(u32);
    void func_80101FDC(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    s32 func_80800028_chhumba(u8 *, s32, s32);
    s32 func_808000D4_chhumba(u8 *, s32, s32, Unk80132ED0 *);
    s32 func_8080015C_chhumba(u8 *, s32, s32, s32);
    void func_808001E4_chhumba(Actor *);
    s32 func_80800294_chhumba(u8 *, s32);
    void func_80800338_chhumba(u8 *, s32, s32);
    s32 func_80800384_chhumba(u8 *);
    s32 func_808003CC_chhumba(u8 *);
    void func_808007F8_chhumba(Actor *);
    s32 func_80800B40_chhumba(u8 *);
    s32 func_80800C20_chhumba(u8 *);
    void func_80800C6C_chhumba(s32 *);
    extern s32 D_80802590_chhumba;
    f32 sp34[3];
    Actor *sp30;
    f32 sp24[3];

    switch (((Actor *)arg0)->unk70_10) {
        case 2:
            break;
        case 3:
            func_80800294_chhumba(arg0, 0);
            break;
        case 5:
        case 6:
            func_80800238_chhumba(arg0, sp34);
            func_80090658(0);
            _fxsplash_entrypoint_1(sp34);
            _fxsplash25d_entrypoint_0(sp34);
            _subaddieaudioquick_entrypoint_2(arg0, arg0 + 4, &D_80802590_chhumba);
            func_808007F8_chhumba(arg0);
            func_800FC660(0xE);
            func_80800338_chhumba((s32)arg0, 0x11B4, 0xF);
            break;
    }
    func_80101FDC((Actor *)arg0, arg1);
    switch (((Actor *)arg0)->unk70_10) {
        case 2:
            func_80800B40_chhumba(arg0);
            return;
        case 3:
            func_80800028_chhumba(arg0, 3, 1);
            func_80800294_chhumba(arg0, 1);
            return;
        case 18:
            if (func_80800C20_chhumba(arg0) != 0) {
                func_80800C6C_chhumba(arg0);
                return;
            }
            func_80800E44_chhumba(arg0, 4);
            return;
        case 4:
            func_80090658(1);
            return;
        case 5:
            func_80800238_chhumba(arg0, sp24);
            func_80090768(sp24);
            ((Actor *)arg0)->unk3C = func_8008FDEC();
            sp30 = func_80106790(((Actor *)arg0)->unk3C);
            func_800EE7F8((f32 *)sp30->actorData, sp24);
            sp30->unk74_30 = 1;
            func_808000D4_chhumba(arg0, 0xE, 9, ((Actor *)arg0)->unk3C);
            return;
        case 6:
            func_808000D4_chhumba(arg0, 0xE, 9, ((Actor *)arg0)->unk3C);
            return;
        case 8:
            func_80090658(1);
            func_8080015C_chhumba(arg0, 2, 0x60, 0);
            return;
        case 9:
            ((Actor *)arg0)->unk58 = 4.0f;
            func_800FC6B0(0xC);
            if (((Actor *)arg0)->unk74_29 && func_8009EA2C() == 0) {
                func_8009EAAC(1);
                func_800907EC(func_8008FD48());
                return;
            }
            func_800907EC(func_80800384_chhumba(arg0));
            return;
        case 11:
            func_80090658(0);
            if (func_800DA9E4(func_80800414_chhumba(arg0), 1) == 0) {
                if (((Actor *)arg0)->unk74_29) {
                    func_80090708(2);
                    func_80800338_chhumba((s32)arg0, func_808003CC_chhumba(arg0), 3);
                    return;
                }
                func_80800338_chhumba((s32)arg0, func_808003CC_chhumba(arg0), 0xB);
                return;
            }
            if (func_80800D2C_chhumba((s32)arg0) == 0) {
                func_808001E4_chhumba(arg0);
                func_80800E44_chhumba(arg0, 0xC);
                return;
            }
            return;
        case 13:
            func_80090658(1);
            func_8080015C_chhumba(arg0, 5, 0x60, 0);
            return;
        case 14:
            ((Actor *)arg0)->unk58 = 4.0f;
            func_800FC6B0(0xC);
            if (((Actor *)arg0)->unk74_29 && func_8009EA2C() != 0) {
                func_8009EAAC(0);
                func_800907EC(func_8008FD48());
                return;
            }
            func_800907EC(1);
            return;
        case 16:
            func_80090658(0);
            if (func_800DA9E4(0x1D1, 1) == 0) {
                func_80800338_chhumba((s32)arg0, 0x11B6, 0xF);
                return;
            }
            func_808001E4_chhumba(arg0);
            func_80800E44_chhumba(arg0, 7);
            return;
        case 17:
            if (func_800DA9E4(0x505, 1) == 0) {
                func_80800B40_chhumba(arg0);
            }
            return;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/humba/func_80801260_chhumba.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/humba/func_8080138C_chhumba.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/humba/func_8080144C_chhumba.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/humba/func_808015DC_chhumba.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/humba/func_80801DB0_chhumba.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/humba/func_80801F74_chhumba.s")

void func_808021F4_chhumba(Actor* arg0) 
{
    if (func_80100094(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
OSThread *chhumba_entrypoint_0(void)
{
    extern u8 D_80802738_chhumba[];

    return (OSThread *) D_80802738_chhumba;
}

/* extern */

void func_80802234_chhumba(void *arg0) {
    s32 func_800EA05C();
    if (func_800EA05C() == 0x122) {
        (*(f32 *)((s8 *)(arg0) + (0x38))) = 2.0f;
        return;
    }
    (*(f32 *)((s8 *)(arg0) + (0x38))) = 1.0f;
}

OSThread *chhumba_entrypoint_1(void)
{
    extern u8 D_80802780_chhumba[];

    return (OSThread *) D_80802780_chhumba;
}
