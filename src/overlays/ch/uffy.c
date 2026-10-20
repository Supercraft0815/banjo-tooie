#include "common.h"

OSThread *chchuffy_entrypoint_0(void)
{
    extern u8 D_80802434_chchuffy[];

    return (OSThread *) D_80802434_chchuffy;
}

s32 func_8080000C_chchuffy(s32 arg0) {
    s32 rom_read_word(s32, u32 *);
    extern u32 D_808024B4_chchuffy[];
    s32 temp_v1;
    u32 sp28;
    u32 temp_a3;
    u32 temp_t7;

    temp_v1 = D_808024B4_chchuffy[arg0];
    temp_a3 = (temp_v1 & 0xFFFF) + 0xB0000000;
    temp_t7 = (temp_v1 & 0xFFFF0000) >> 16;
    if (temp_a3 & 2) {
        temp_a3 = (temp_a3 >> 2) << 2;
        rom_read_word(temp_a3, &sp28);
        temp_v1 = (sp28 & 0xFFFF0000) >> 16;
    } else {
        rom_read_word(temp_a3, &sp28);
        temp_v1 = sp28 & 0xFFFF;
    }
    if (temp_t7 != 0) {
        temp_t7 += 0xB0000000;
        if (temp_t7 & 2) {
            temp_t7 = (temp_t7 >> 2) << 2;
            rom_read_word(temp_t7, &sp28);
            temp_v1 += (sp28 & 0xFFFF0000) >> 16;
        } else {
            rom_read_word(temp_t7, &sp28);
            temp_v1 += sp28 & 0xFFFF;
        }
    }
    return temp_v1 + 0xA0;
}

struct Entry { s16 pad[2]; s16 value; s16 tail; };
extern struct Entry D_8080247C_chchuffy[];

s32 func_80800110_chchuffy(s32 arg0) {
    s32 func_800DA298(s32);
    s32 func_800EA05C();
    u32 i;

    switch (arg0) {
        case 4: {
            s32 map;
            map = func_800EA05C();
            for (i = 0; i != 7; i += 1) {
                if (func_8080000C_chchuffy(i) == map) {
                    break;
                }
            }
            break;
        }
        case 0:
        case 1: {
            s16 *var_s0;
            var_s0 = &D_8080247C_chchuffy[0].pad[arg0];
            for (i = 0; i != 7; i += 1, var_s0 += 4) {
                if (func_800DA298(*var_s0)) {
                    break;
                }
            }
            break;
        }
    }
    if (i >= 7U) {
        return -1U;
    }
    return i;
}

void func_808001DC_chchuffy(void) {
    void func_800DA524(GameFlag);
    void func_800DA544(GameFlag);
    s32 func_800EA05C();
    s32 func_8080000C_chchuffy(s32);
    struct Entry *var_s0;
    s32 temp_s2;
    s32 var_s1;

    temp_s2 = func_800EA05C();
    var_s0 = D_8080247C_chchuffy;
    var_s1 = 0;
    do {
        if (func_8080000C_chchuffy(var_s1) == temp_s2) {
            func_800DA544(var_s0->pad[0]);
            func_800DA524(var_s0->pad[1]);
        } else {
            func_800DA524(var_s0->pad[0]);
        }
        var_s1 += 1;
        var_s0++;
    } while (var_s1 != 7);
}

s32 func_80800264_chchuffy(void) {
    s32 func_800DA298(s32);
    s32 func_800EA05C();
    s32 func_8080000C_chchuffy(s32);
    s32 map;
    s32 i;

    map = func_800EA05C();
    for (i = 0; i != 7; i++) {
        if (func_8080000C_chchuffy(i) != map && func_800DA298(D_8080247C_chchuffy[i].pad[1])) {
            return 1;
        }
    }
    return 0;
}

struct ChuffyData {
    u8 pad[0x4C];
    f32 position[3];
    f32 rotation[3];
};

int chchuffy_entrypoint_1(Unk80132ED0 *marker, f32 *position, f32 *rotation) {
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800F1828(f32 *, f32 *);
    f32 func_800F1DF4(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    Actor *actor;
    struct ChuffyData *data;

    actor = func_80106790(marker);
    data = func_80100094(actor, 0);
    func_800EE7F8(position, &data->position[0]);
    rotation[0] = 90.0f - func_800F1828(&data->position[0], &data->rotation[0]);
    rotation[1] = func_800F1DF4(&data->position[0], &data->rotation[0]);
    rotation[2] = 0.0f;
    if ((s32)actor->unk70_10 < 4) {
        return 1;
    }
    return 0;
}

void func_80800398_chchuffy(Actor *actor) {
    f32 func_800F1828(f32 *, f32 *);
    f32 func_800F1DF4(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    void func_808013E8_chchuffy(Actor *, f32 *, f32 *);
    struct ChuffyData *data;
    f32 rotation[3];

    data = func_80100094(actor, 0);
    rotation[0] = 90.0f - func_800F1828(data->position, data->rotation);
    rotation[1] = func_800F1DF4(data->position, data->rotation);
    rotation[2] = 0.0f;
    func_808013E8_chchuffy(actor, data->position, rotation);
}

void func_80800410_chchuffy(Actor *actor, s32 index) {
    struct ParticleData {
        u8 pad0[0x14];
        f32 origin[3];
        u8 pad20[0x44];
        f32 position[10][3];
        u8 padDC[0x78];
        f32 velocity[10][3];
        f32 rotation[10][3];
        f32 scale[10];
        s8 kind[10];
        u8 pad276[6];
        s32 timer[10];
    };
    s32 func_800DC128(s32, s32);
    f32 func_800DC178(f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    struct ParticleData *data;

    data = func_80100094(actor, 0);
    data->velocity[index][0] = func_800DC178(-13.0f, 13.0f);
    data->velocity[index][1] = func_800DC178(10.0f, 20.0f);
    data->velocity[index][2] = func_800DC178(-13.0f, 13.0f);
    data->rotation[index][1] = func_800DC178(250.0f, 450.0f);
    func_800EE7F8(data->position[index], data->origin);
    data->position[index][2] += 25.0f;
    data->scale[index] = func_800DC178(0.2f, 0.4f);
    data->timer[index] = func_800DC128(0xB9, 0xFA);
    data->kind[index] = func_800DC128(0, 6);
}

/* extern */

void func_80800524_chchuffy(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    void func_80800410_chchuffy(Actor *, s32);
    s32 var_s0;
    Actor *actor;
    u32 *temp_v0;

    actor = arg0;
    (*(s32 *)((s8 *)(func_80100094(actor, 0U)) + (0x2A8))) = 0x9DD;
    for (var_s0 = 0; var_s0 < 10; var_s0++) {
        func_80800410_chchuffy(actor, var_s0);
    }
    temp_v0 = actor->unk0->unk0;
    (*(u8 *)((s8 *)(temp_v0) + (0xA))) = (u8) (((*(u8 *)((s8 *)(temp_v0) + (0xA))) & 0xFF07) | 0x18);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffy/func_8080059C_chchuffy.s")

void func_80800818_chchuffy(u8 *arg0, u32 arg1, s32 arg2) {
    struct Flags { u8 pad[0x74]; u8 high : 1; u8 flag : 1; u8 low : 6; };
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0*, u32, u32, f32*, u32);
    arg2 |= 4;
    _subaddiedialog_entrypoint_11((*(Unk80132ED0 **)((s8 *)(arg0) + (0))), arg1, arg2, arg0 + 4, 0x6FU);
    ((struct Flags *)arg0)->flag = 1;
}

s32 func_80800864_chchuffy(Actor *arg0, s32 arg1, Unk80132ED0 *arg2) {
    void _gcsectionskip_entrypoint_1(void *, s32, s32, u8, s32);
    s32 func_80090178(AllowedTransformation);
    Actor *func_80106790(Unk80132ED0 *);
    Actor *func_801084B0(s32, Actor **);
    Actor *other;

    switch (arg1) {
    case 0x3D:
        other = func_801084B0(0x316, &arg0);
        arg0->unk3C = other->unk0;
        other->unk3C = arg0->unk0;
        break;
    case 0x3E:
        if (arg0->unk3C != NULL) {
            other = func_80106790(arg0->unk3C);
            if ((arg2->unk24 >> 22) == 0) {
                switch ((arg0->unk0->unk18 << 11) >> 28) {
                case 1:
                    other->unk64_20 = 1;
                    if (func_80090178(1)) {
                        _gcsectionskip_entrypoint_1(NULL, 0, 0, 1, 0);
                    } else if (!arg0->unk74_30) {
                        func_80800818_chchuffy((u8 *)arg0, 0x121E, 0);
                    }
                    break;
                case 2:
                    other->unk64_19 = 1;
                    if (func_80090178(-1)) {
                        _gcsectionskip_entrypoint_1(NULL, 0, 0, 2, 0);
                    }
                    break;
                }
            }
        }
        break;
    default:
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffy/func_808009CC_chchuffy.s")

void func_80800EF4_chchuffy(Unk80132ED0 *arg0) { void _capod_entrypoint_13(Unk80132ED0*, Unk80132ED0*, u32, u32); s32 func_80800110_chchuffy(s32); s32 temp_v0; temp_v0 = func_80800110_chchuffy(4); if (D_8080247C_chchuffy[temp_v0].value != -1) { _capod_entrypoint_13(arg0->unk0, 0, D_8080247C_chchuffy[temp_v0].value, 0x2830); } }

void func_80800F54_chchuffy(Actor *arg0) {
    void _capod_entrypoint_13(Unk80132ED0*, Unk80132ED0*, u32, u32);
    s32 _chintrotext_entrypoint_2(s32);
    s32 func_80800110_chchuffy(s32);
    s32 temp_v0;

    temp_v0 = func_80800110_chchuffy(4);
    if (D_8080247C_chchuffy[temp_v0].tail != -1) {
        _capod_entrypoint_13(arg0->unk0, NULL, D_8080247C_chchuffy[temp_v0].tail, 0x2830U);
        _chintrotext_entrypoint_2(1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffy/func_80800FBC_chchuffy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffy/func_8080115C_chchuffy.s")

void func_8080130C_chchuffy(Actor *arg0) {
    typedef struct { f32 v[2]; } ChuffyPair;
    typedef struct { f32 v[3]; } ChuffyVector;
    s16 _chmumbopad_entrypoint_0(s32);
    s32 _sumumbofx_entrypoint_0(Actor *, s32, s32, s16);
    s32 _sumumbofx_entrypoint_2(void *);
    s32 _sumumbofx_entrypoint_24(void *, f32);
    s32 _sumumbofx_entrypoint_15(void *, f32);
    s32 _sumumbofx_entrypoint_12(void *, ChuffyVector *, ChuffyPair *, ChuffyVector *);
    void *func_80100094(Actor *, u32);
    extern ChuffyPair D_80802568_chchuffy;
    extern ChuffyVector D_80802570_chchuffy;
    extern ChuffyVector D_8080257C_chchuffy;
    void *sp3C;
    ChuffyPair sp34;
    ChuffyVector sp28;
    ChuffyVector sp1C;

    _sumumbofx_entrypoint_0(arg0, 1, 0x41, _chmumbopad_entrypoint_0(0));
    sp3C = func_80100094(arg0, 1);
    _sumumbofx_entrypoint_2(sp3C);
    _sumumbofx_entrypoint_24(sp3C, 2.25f);
    _sumumbofx_entrypoint_15(sp3C, 3.0f);
    sp34 = D_80802568_chchuffy;
    sp28 = D_80802570_chchuffy;
    sp1C = D_8080257C_chchuffy;
    _sumumbofx_entrypoint_12(sp3C, &sp28, &sp34, &sp1C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffy/func_808013E8_chchuffy.s")

/* extern */

void func_8080167C_chchuffy(s32 *arg0) {
    s32 _capod_entrypoint_14();
    s32 _glcutDll_entrypoint_19(s32);
    s32 _glcutDll_entrypoint_21();
    s32 func_800D9290();
    if (_glcutDll_entrypoint_19(0x72) != 0) {
        _capod_entrypoint_14();
        func_800D9290();
        _glcutDll_entrypoint_21();
        return;
    }
    *arg0 = 0xD0;
}

s32 func_808016D0_chchuffy(s32 arg0) {
    void _glcutDll_entrypoint_24(u32, u32, u32);
    s32 func_800DA298(s32);
    s32 func_800EA05C();
    s32 sp1C;

    sp1C = func_800EA05C();
    switch (sp1C) {
        case 0xEC:
            if (func_800DA298(0x98) && !func_800DA298(0x588) && !func_800DA298(0x8A)) {
                func_8080167C_chchuffy(&sp1C);
                _glcutDll_entrypoint_24(0xEA, sp1C, 0x1F);
                return 1;
            }
            break;
        case 0x114:
            if (func_800DA298(0x588)) {
                func_8080167C_chchuffy(&sp1C);
                _glcutDll_entrypoint_24(0x114, -1, 0x35);
                return 1;
            }
            if (func_800DA298(0x189) && func_800DA298(0x15E)) {
                func_8080167C_chchuffy(&sp1C);
                _glcutDll_entrypoint_24(0x114, -1, 0x38);
                return 1;
            }
            break;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffy/func_808017D4_chchuffy.s")

void func_808018F8_chchuffy(Actor *arg0) {
    s32 func_800DA298(s32);
    void func_800FFAB0(Actor *);
    s32 func_80800110_chchuffy(s32);
    s32 func_80800264_chchuffy();
    void func_808017D4_chchuffy(Actor *, s32);
    extern struct Entry D_8080247E_chchuffy[];
    s32 sp1C;
    s32 temp_v0;

    temp_v0 = func_80800110_chchuffy(4);
    sp1C = temp_v0;
    if (func_800DA298(D_8080247C_chchuffy[temp_v0].pad[0]) != 0) {
        if (func_80800264_chchuffy() != 0) {
            func_808017D4_chchuffy(arg0, 6);
            return;
        }
        func_808017D4_chchuffy(arg0, 5);
        return;
    }
    if (func_800DA298(D_8080247E_chchuffy[sp1C].pad[0]) != 0) {
        func_808017D4_chchuffy(arg0, 8);
        return;
    }
    func_800FFAB0(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffy/func_808019A4_chchuffy.s")

void func_80801B8C_chchuffy(Actor *arg0) {
    s32 func_800DA298(s32);
    s32 func_800EA05C();
    void *func_80100094(Actor *, u32);
    void func_80108B04(Actor *, u32);
    void func_808017D4_chchuffy(Actor *, s32);
    struct {
        u8 unk0;
        u8 unk1;
        u8 pad2[2];
        f32 unk4;
        u8 pad8[0x34];
        f32 unk3C;
        u8 pad40[8];
        f32 unk48;
    } *data;

    data = func_80100094(arg0, 0);
    data->unk1 = 0;
    data->unk3C = 0.0f;
    data->unk4 = 20000.0f;
    data->unk0 = 0;
    data->unk48 = 1.0f;
    func_80800524_chchuffy(arg0);
    if (func_800EA05C() == 0xD7) {
        if (func_80800110_chchuffy(0) == -1) {
            if (func_800DA298(0x95) == 0) {
                func_808017D4_chchuffy(arg0, 1);
            } else {
                func_808017D4_chchuffy(arg0, 5);
            }
        } else {
            func_808018F8_chchuffy(arg0);
        }
    } else {
        func_808018F8_chchuffy(arg0);
    }
    if (!arg0->unk64_17) {
        func_80108B04(arg0, 0);
    }
}

void func_80801C78_chchuffy(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 func_800C2FDC(u8);
    s32 _sumumbofx_entrypoint_1(void *, s32);
    u8 *data;

    data = func_80100094(arg0, 0);
    if (data[0] != 0) {
        func_800C2FDC(data[0]);
        data[0] = 0;
    }
    if (data[1] != 0) {
        func_800C2FDC(data[1]);
        data[1] = 0;
    }
    if (func_80100094(arg0, 1) != NULL) {
        _sumumbofx_entrypoint_1(arg0, 1);
    }
}

void func_80801CF8_chchuffy(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    extern s32 D_808025A0_chchuffy;
    func_800BBCB8((f32 *)((u8 *)func_80100094(arg0, 0) + 0x2C), 0, 1.0f, arg1, &D_808025A0_chchuffy);
}

void func_80801D3C_chchuffy(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    extern s32 D_808025E4_chchuffy;
    f32 *temp_a0;

    temp_a0 = (f32 *)((u8 *)func_80100094(arg0, 0) + 8);
    if (arg0->unk7C_12) {
        func_800BBCB8(temp_a0, 0, 1.0f, arg1, &D_808025E4_chchuffy);
    }
}

void func_80801D94_chchuffy(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    extern s32 D_80802630_chchuffy;
    Actor **actor = &arg0;
    func_800BBCB8((f32 *)((u8 *)func_80100094(*actor, 0) + 8), 0, 1.0f, arg1, &D_80802630_chchuffy);
}

void func_80801DDC_chchuffy(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    void func_800C3058(u8, s32);
    u8 func_800C4350(s32, f32[3], s32 *);
    extern s32 D_8080267C_chchuffy;
    struct {
        u8 pad0[0x14];
        f32 position[3];
        u8 pad20[0x1C];
        f32 sampleRate;
    } *data;

    data = func_80100094(arg0, 0);
    if (arg0->unk5F == 0) {
        arg0->unk5F = func_800C4350(0, data->position, &D_8080267C_chchuffy);
        return;
    }
    if (data->sampleRate > 2000.0f && arg0->unk7C_12) {
        func_800C3058(arg0->unk5F, (s32)data->sampleRate);
        func_800C4350(arg0->unk5F, data->position, NULL);
    }
    data->sampleRate -= 1000.0f;
}

void func_80801EAC_chchuffy(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    u8 _subaddieaudioloop_entrypoint_7(u8, u8 *, s32, s32 *, s32);
    extern s32 D_80802690_chchuffy;
    u8 *sp24;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    sp24 = temp_v0;
    *sp24 = _subaddieaudioloop_entrypoint_7(*temp_v0, temp_v0 + 0x20, 1, &D_80802690_chchuffy, (*(s32 *)((s8 *)(arg0) + (0x70))) & 1);
}

void func_80801F04_chchuffy(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    void func_800C3058(u8, s32);
    u8 func_800C4350(s32, f32[3], s32 *);
    extern s32 D_808023DC_chchuffy;
    struct {
        u8 unk0;
        u8 soundIndex;
        u8 pad2[2];
        f32 sampleRate;
        u8 pad8[0x18];
        f32 position[3];
    } *data;

    data = func_80100094(arg0, 0);
    if (data->soundIndex == 0) {
        data->soundIndex = func_800C4350(0, data->position, &D_808023DC_chchuffy);
    } else {
        func_800C3058(data->soundIndex, (s32)data->sampleRate);
        func_800C4350(data->soundIndex, data->position, NULL);
    }
}

/* extern */

void func_80801F84_chchuffy(s32 arg0) {
    s32 func_800EFD24(s32);
    func_800EFD24(arg0 + 0x4);
}

s32 func_80801FA4_chchuffy(Actor *arg0, s32 arg1, void *volatile arg2) {
    s32 func_800DA298(s32);
    s32 func_80103140(Actor *, u32, u16);
    u32 func_8010A5B0(Actor *, s32);
    void func_80802060_chchuffy(Actor *, void *);
    s32 text;

    switch (arg1) {
        case 0x95:
            if (func_800DA298(0x95)) {
                text = 0x87A;
            } else {
                text = 0x879;
            }
            func_80103140(arg0, text & 0xFFFF, arg0->unk0->unk16);
            func_8010A5B0(arg0, func_800DA298(0x95));
            break;
        case 0x2E:
            arg0->unk74_30 = 0;
            break;
        case 0x3E:
            func_80802060_chchuffy(arg0, arg2);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80802060_chchuffy(Actor *arg0, void *arg1) {
    Prop *_gccubesearch_entrypoint_6(s32 *, f32 *);
    void _gspropctrl_entrypoint_11(Prop *, f32[3]);
    void func_800EF1B8(f32 *, f32, f32);
    Unk80132ED0 *func_800F55D0(s32);
    void func_800F5A00(s32, f32 *);
    s32 func_800F6C5C(s32);
    void func_800F77E8(s32, f32 *);
    extern s32 D_808026A4_chchuffy;
    Prop *prop;
    f32 sp38[3];
    f32 sp2C[3];
    s32 sp28;
    f32 sp1C[3];
    struct ChuffyContact { u8 pad[0x1A]; u16 flags; };

    sp28 = (u32)((struct ChuffyContact *)arg1)->flags >> 5;
    if (func_800F6C5C(sp28) && func_800F55D0(sp28) == arg0->unk0) {
        func_800F5A00(sp28, sp38);
        prop = _gccubesearch_entrypoint_6(&D_808026A4_chchuffy, sp38);
        if (prop) {
            _gspropctrl_entrypoint_11(prop, sp2C);
        } else {
            chchuffy_entrypoint_1(arg0->unk3C, sp2C, sp1C);
            if (sp38[2] < sp2C[2]) {
                func_800EF1B8(sp2C, arg0->rotation[1] - 180.0f, 500.0f);
            } else {
                func_800EF1B8(sp2C, arg0->rotation[1], 500.0f);
            }
            sp2C[0] = sp38[0];
        }
        func_800F77E8(sp28, sp2C);
    }
}

void func_80802164_chchuffy(Actor *arg0) {
    void func_8008FA94(f32 *, f32 *);
    s32 func_80090178(AllowedTransformation);
    s32 func_800DA298(s32);
    int func_800DB9B0(void);
    int func_800F0064(f32 *, f32, f32 *);
    u32 func_800F54E4(void);
    void func_800F7F00(s32, s32, s32, f32, s32, s32, f32);
    u32 func_8010A654(void ***, s32);
    void func_8010D254(f32 *);
    extern f32 D_808026AC_chchuffy[];
    extern f32 D_808026B0_chchuffy;
    extern f32 D_808026B8_chchuffy[];
    extern f32 D_808026BC_chchuffy;
    extern f32 D_808026C4_chchuffy[];
    extern f32 D_808026D0_chchuffy[];
    extern f32 D_808026DC_chchuffy[];
    extern f32 D_808026E8_chchuffy[];
    f32 sp2C[3];

    func_8010A654(arg0, func_800DB9B0() == 0);
    if (func_800DA298(0x95)) {
        func_8010D254(sp2C);
        if (func_800F0064(sp2C, 130.0f, D_808026AC_chchuffy) &&
            D_808026B0_chchuffy < sp2C[1] && sp2C[1] <= D_808026BC_chchuffy) {
            func_800F7F00(func_800F54E4(), D_808026AC_chchuffy, D_808026B8_chchuffy, 80.0f, 2, 2, 0.0f);
        }
        if (arg0->unk64_20 && !func_80090178(1)) {
            func_8008FA94(D_808026C4_chchuffy, D_808026D0_chchuffy);
        }
        if (arg0->unk64_19 && !func_80090178(-1)) {
            func_8008FA94(D_808026DC_chchuffy, D_808026E8_chchuffy);
        }
    }
}

OSThread *chchuffy_entrypoint_2(void)
{
    extern u8 D_808026F4_chchuffy[];

    return (OSThread *) D_808026F4_chchuffy;
}
