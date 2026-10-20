#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/magnet/func_80800000_chfactorymagnet.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/magnet/func_80800224_chfactorymagnet.s")

/* extern */

void func_8080083C_chfactorymagnet(s32 arg0) {
    Actor *_subaddiefind_entrypoint_2(s32, s32);
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    s32 func_800F4EC8(s32, s32 *, f32, f32, f32);
    u32 func_800F54E4(void);
    s32 sp24[3];

    func_800EE7F8(sp24, _subaddiefind_entrypoint_2(0x3FC, 0)->position);
    func_800F4EC8(func_800F54E4(), sp24, 500.0f, 0.0f, 200.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/magnet/func_80800898_chfactorymagnet.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/magnet/func_80800B20_chfactorymagnet.s")

/* extern */

void *func_80800E40_chfactorymagnet(Actor *arg0) {
    s16 _chmumbopad_entrypoint_0(s32);
    s32 _sumumbofx_entrypoint_0(Actor *, s32, s32, s16);
    s32 _sumumbofx_entrypoint_2(void *);
    s32 _sumumbofx_entrypoint_24(void *, s32);
    void _sumumbofx_entrypoint_25(void *, s32, s32 *);
    s32 _sumumbofx_entrypoint_28(void *, f32 *, f32, f32);
    void *func_80100094(Actor *, u32);
    void func_8010A800(Actor *, s32);
    void *temp_v0;
    s32 sp28[3];

    sp28[0] = 0;
    sp28[1] = 0;
    sp28[2] = 0;
    _sumumbofx_entrypoint_0(arg0, 0, 0x28, _chmumbopad_entrypoint_0(0xA));
    temp_v0 = func_80100094(arg0, 0);
    _sumumbofx_entrypoint_2(temp_v0);
    _sumumbofx_entrypoint_25(temp_v0, 0x8C, sp28);
    _sumumbofx_entrypoint_24(temp_v0, 0x3F266666);
    func_8010A800(arg0, 2);
    _sumumbofx_entrypoint_28(temp_v0, arg0->position, 2000.0f, 4000.0f);
    return temp_v0;
}

void func_80800EF0_chfactorymagnet(Actor *arg0, s32 arg1) {
    s32 _sumumbofx_entrypoint_8(u8 *, s32);
    s32 _sumumbofx_entrypoint_9(u8 *, s32);
    void func_800EFE50(f32 *, f32 *, f32 *, f32);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    void *func_80100094(Actor *, u32);
    void func_80101870(Actor *, void *);
    void func_808016A4_chfactorymagnet(Actor *, s32);
    void func_80801A9C_chfactorymagnet(s32, f32 *, f32 *);
    struct MagnetVector { f32 v[3]; };
    extern struct MagnetVector D_8080291C_chfactorymagnet;
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp3C;
    struct MagnetVector sp30;
    u8 *temp_s1;

    sp3C = func_800F12D4(arg0->unk58, 0.25f, 1.0f, 0.0f, 1.0f);
    sp30 = D_8080291C_chfactorymagnet;
    temp_s1 = func_80100094(arg0, 0);
    func_80801A9C_chfactorymagnet((s32)arg0, sp4C, sp40);
    func_800EFE50(arg0->position, sp4C, sp40, sp3C);
    if (temp_s1 != NULL) {
        _sumumbofx_entrypoint_9(temp_s1, arg1);
    }
    if (arg0->unk70_10 == 4) {
        func_808016A4_chfactorymagnet(arg0, arg1);
    }
    func_80101870(arg0, (void *)arg1);
    if (temp_s1 != NULL) {
        _sumumbofx_entrypoint_8(temp_s1, arg1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/magnet/func_80800FE8_chfactorymagnet.s")

/* extern */

s32 func_808012E4_chfactorymagnet(s32 arg0, f32 arg1) {
    Actor *_subaddiefind_entrypoint_2(s32, s32);
    s32 func_80090178(s32);
    f32 func_800EFC7C(void *, void *);
    u32 func_800F54E4(void);
    void func_800F5A00(s32, f32 *);
    f32 sp24[3];
    Actor *sp20;

    if (func_80090178(0x40) != 0) {
        sp20 = _subaddiefind_entrypoint_2(0x3FC, 0);
        func_800F5A00(func_800F54E4(), sp24);
        return func_800EFC7C(sp24, sp20->position) < arg1;
    }
    return 0;
}

/* extern */ void func_80801368_chfactorymagnet(u8 *arg0) { s32 func_800D90F8(u8 *, f32); s32 func_800D91EC(u8 *, f32); f32 func_800DC178(f32, f32); f32 temp_f0; s32 var_v0; temp_f0 = (*(f32 *)((s8 *)(arg0) + (0x1C))); if (temp_f0 < (*(f32 *)((s8 *)(arg0) + (0x58)))) { var_v0 = func_800D90F8(arg0 + 0x58, temp_f0); } else { var_v0 = func_800D91EC(arg0 + 0x58, temp_f0); } if (var_v0 != 0) { (*(f32 *)((s8 *)(arg0) + (0x1C))) = func_800DC178(0.0f, 1.0f); } }

/* extern */

void chfactorymagnet_entrypoint_0(s32 arg0, s32 arg1) {
    s32 _chmrtannoy_entrypoint_0();
    s32 func_800C05B8(s32, s32, s32, s32, s32, s32, s32);
    s32 func_800DA298(s32);
    s32 func_800DA524(s32);
    s32 func_800EA05C();
    func_800DA524(0xA06);
    if (func_800EA05C() != 0x107) {
        func_800DA524(0x9DE);
    }
    if (func_800DA298(0x1B8) == 0) {
        _chmrtannoy_entrypoint_0();
        func_800C05B8(0x1338, 4, 0, 0, 0, 0, 0xA3);
    }
}

void func_80801460_chfactorymagnet(Actor *arg0, s32 arg1) {
    s32 _sumumbofx_entrypoint_7(s32, f32, s32, s32, f32 *, s32, s32);
    void func_800EFE50(f32 *, f32 *, f32 *, f32);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    f32 func_80103EAC(Actor *);
    void func_80801A9C_chfactorymagnet(s32, f32 *, f32 *);
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];
    f32 sp30;

    sp30 = func_800F12D4(arg0->unk58, 0.25f, 1.0f, 0.0f, 1.0f);
    func_80801A9C_chfactorymagnet((s32)arg0, sp40, sp34);
    func_800EFE50(sp4C, sp40, sp34, sp30);
    _sumumbofx_entrypoint_7(arg1, func_80103EAC(arg0) * 0.6f, 0, 0x28, sp4C, 0, 0);
}

void func_80801508_chfactorymagnet(Actor *arg0, s32 arg1) {
    f32 func_800DC0C0(void);
    s32 func_800DC128(s32, s32);
    f32 func_800DC178(f32, f32);
    u32 func_800F54E4(void);
    void func_800F5A00(s32, f32 *);
    void *func_80100094(Actor *, u32);
    struct MagnetParticle {
        f32 position[3];
        f32 unkC;
        f32 unk10;
        f32 unk14;
        s8 unk18;
        s8 unk19;
    } *sp24, *particle;
    f32 value;

    sp24 = func_80100094(arg0, 1);
    if (func_800DC0C0() < 0.2f) {
        particle = sp24;
        particle += arg1;
        particle->unk19 = func_800DC128(0, 3);
        particle->unk14 = func_800DC0C0() * 0.15f + 0.35f;
        value = func_800DC178(1.0f, 3.0f);
        particle->unk10 = value;
        particle->unkC = value;
        if (func_800DC0C0() < 0.5f) { particle->unk18 = 1; } else { particle->unk18 = 2; }
        if (func_800DC0C0() < 0.2f) {
            func_800F5A00(func_800F54E4(), particle->position);
            particle->position[0] += func_800DC178(-100.0f, 100.0f);
            particle->position[1] += func_800DC178(0.0f, 200.0f);
        } else {
            particle->position[0] = func_800DC178(-2000.0f, 1500.0f);
            particle->position[1] = func_800DC178(0.0f, 1600.0f);
            particle->position[2] = func_800DC178(1200.0f, 1800.0f);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/magnet/func_808016A4_chfactorymagnet.s")

/* extern */

void func_808019F4_chfactorymagnet(Actor *arg0, f32 *arg1, f32 *arg2) {
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    f32 sp1C[3];

    func_800EFA4C(sp1C, (*&arg0)->scale * -195.0f, arg0->scale * 60.0f, arg0->scale * 390.0f);
    func_800EE780(arg1, arg0->position, sp1C);
    sp1C[0] = arg0->scale * 205.0f;
    func_800EE780(arg2, arg0->position, sp1C);
}

void func_80801A9C_chfactorymagnet(s32 arg0, f32 *arg1, f32 *arg2) {
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    extern f32 D_8080298C_chfactorymagnet;
    extern f32 D_80802998_chfactorymagnet;
    if (arg1 != NULL) {
        func_800EE7F8(arg1, &D_8080298C_chfactorymagnet);
    }
    if (arg2 != NULL) {
        func_800EE7F8(arg2, &D_80802998_chfactorymagnet);
    }
}

/* extern */

void func_80801AE8_chfactorymagnet(Actor *arg0) {
    s32 func_800C8A98();
    void func_800C8E54(s32, f32, f32);
    void func_800C8F64(s32, s32);
    void func_800C8FE0(s32, s32);
    void *func_80100094(Actor *, u32);
    void *temp_s0;

    temp_s0 = func_80100094(arg0, 1);
    (*(s32 *)((s8 *)(temp_s0) + (0x348))) = func_800C8A98();
    (*(s32 *)((s8 *)(temp_s0) + (0x34C))) = func_800C8A98();
    func_800C8E54((*(s32 *)((s8 *)(temp_s0) + (0x348))), 300.0f, 450.0f);
    func_800C8E54((*(s32 *)((s8 *)(temp_s0) + (0x34C))), 300.0f, 450.0f);
    func_800C8FE0((*(s32 *)((s8 *)(temp_s0) + (0x348))), 0);
    func_800C8FE0((*(s32 *)((s8 *)(temp_s0) + (0x34C))), 0);
    func_800C8F64((*(s32 *)((s8 *)(temp_s0) + (0x348))), 3);
    func_800C8F64((*(s32 *)((s8 *)(temp_s0) + (0x34C))), 3);
}

void func_80801B74_chfactorymagnet(Actor *arg0) {
    void func_800C8CB8(s32, f32[3]);
    void func_800C8FB0(s32, u32, u32, u32);
    void func_800C8FE0(s32, s32);
    s32 func_800DC128(s32, s32);
    void *func_80100094(Actor *, u32);
    typedef struct { f32 v[3]; } MagnetVector;
    typedef struct { u8 pad[0x348]; s32 first; s32 second; } MagnetData;
    extern MagnetVector D_808029A4_chfactorymagnet;
    extern MagnetVector D_808029B0_chfactorymagnet;
    MagnetVector sp3C = D_808029A4_chfactorymagnet;
    MagnetVector sp30 = D_808029B0_chfactorymagnet;
    MagnetData *data;

    data = func_80100094(arg0, 1);
    if (arg0->unk70_10 == 4) {
        func_800C8FE0(data->first, 1);
        func_800C8FE0(data->second, 1);
        func_800C8CB8(data->first, sp3C.v);
        func_800C8CB8(data->second, sp30.v);
        func_800C8FB0(data->first, func_800DC128(0xE6, 0x100), func_800DC128(0, 0x29), func_800DC128(0xE6, 0x100));
        func_800C8FB0(data->second, func_800DC128(0xE6, 0x100), func_800DC128(0, 0x29), func_800DC128(0xE6, 0x100));
    } else {
        func_800C8FE0(data->first, 0);
        func_800C8FE0(data->second, 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/magnet/func_80801CD8_chfactorymagnet.s")

void func_80801E84_chfactorymagnet(u8 *arg0) {
    s32 _sumumbofx_entrypoint_1(void *, s32);
    if ((*(s16 *)((s8 *)(arg0) + (0x82))) != 0) {
        _sumumbofx_entrypoint_1(arg0, 0);
    }
}

OSThread *chfactorymagnet_entrypoint_1(void)
{
    extern u8 D_80802A04_chfactorymagnet[];

    return (OSThread *) D_80802A04_chfactorymagnet;
}

void func_80801EBC_chfactorymagnet(Actor *arg0) {
    f32 func_80013970(f32);
    s32 func_800DA298(s32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    void func_800F4D74(s32, f32 *, f32, f32, f32);
    u32 func_800F54E4(void);
    f32 func_80103EF4(Actor *);
    Actor *func_80106790(Unk80132ED0 *);
    f32 sp3C[3];
    f32 sp38;
    f32 sine;
    u32 sp30;

    if (func_800DA298(0xA06) != 0) {
        sp38 = func_80103EF4(arg0) * 1.2f;
        func_800EFA4C(sp3C, arg0->position[0], arg0->position[1] + sp38 * 0.5f, arg0->position[2] - sp38);
        sp30 = func_800F54E4();
        sine = func_80013970(arg0->rotation[0]); func_800F4D74(sp30, sp3C, sp38, sp38 * 0.5f, sine * sp38 + sp38);
    }
    arg0->rotation[0] = func_800F12D4(func_80106790(arg0->unk3C)->unk58, 0.0f, 0.75f, 0.0f, 90.0f);
}

OSThread *chfactorymagnet_entrypoint_2(void)
{
    extern u8 D_80802A4C_chfactorymagnet[];

    return (OSThread *) D_80802A4C_chfactorymagnet;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/magnet/func_80801FB8_chfactorymagnet.s")

s32 func_808022D8_chfactorymagnet(Actor *arg0, s32 arg1, s32 arg2) {
    void func_800187B4(s32, f32, f32, f32);
    void func_800DF830(s32);
    s32 func_801015D0(Actor *);
    void func_80101FDC(Actor *, u32);

    switch (arg1) {
        case 0x1F:
            func_801015D0(arg0);
            func_800DF830(2);
            return 1;
        case 0xA:
            arg0->unk64_16 = 1;
            func_80101FDC(arg0, 2);
            func_800187B4(0, 1.0f, 2.0f, 0.5f);
            return 1;
        case 0x4F:
            func_80101FDC(arg0, 4);
            func_800187B4(0, 2.0f, 1.0f, 0.5f);
            return 1;
        default:
            return 0;
    }
}

OSThread *chfactorymagnet_entrypoint_3(void)
{
    extern u8 D_80802AB4_chfactorymagnet[];

    return (OSThread *) D_80802AB4_chfactorymagnet;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/magnet/func_80802390_chfactorymagnet.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/magnet/func_808025B4_chfactorymagnet.s")

void func_8080281C_chfactorymagnet(u8 *arg0) {
    void func_800C8B84(s32);
    s32 temp_a1;

    temp_a1 = (*(s32 *)((s8 *)(arg0) + (0x24)));
    if (temp_a1 != 0) {
        func_800C8B84(temp_a1);
    }
}

OSThread *chfactorymagnet_entrypoint_4(void)
{
    extern u8 D_80802B68_chfactorymagnet[];

    return (OSThread *) D_80802B68_chfactorymagnet;
}
