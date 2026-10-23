#include "common.h"

/* extern */

void func_80800000_chlakemonster(s32 arg0) {
    s32 _glcutDll_entrypoint_20();
    void func_800EFA4C(f32 *, f32, f32, f32);
    s32 func_80801494_chlakemonster(s32, s32);
    func_800EFA4C((f32 *)(arg0 + 4), 0.0f, -3050.0f, 0.0f);
    if (_glcutDll_entrypoint_20() != 0) {
        func_80801494_chlakemonster(arg0, 7);
        return;
    }
    func_80801494_chlakemonster(arg0, 1);
}

void func_80800064_chlakemonster(Actor *arg0) {
    u32 func_800FDC28(u32);
    u32* func_80100074(Actor*, u32, u32);
    func_80100074(arg0, 0U, 0U);
    func_800FDC28(0U);
}

void func_80800090_chlakemonster(Actor *arg0, f32 arg1[3], f32 arg2[3], s32 arg3) {
    s32 func_800B53A4(s32);
    void func_800BA1D0(s32, f32[3], f32[3], s32);
    void func_800BA7C4(void *, f32, f32);
    void func_800BA7FC(void *, f32, f32);
    void func_800BA994(u8 *, s16, s16, s16, s16, s16, s16);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    extern s32 D_808020E0_chlakemonster;
    f32 scale;
    f32 rotation;
    s32 emitter;

    emitter = func_800B53A4(arg3);
    scale = arg0->scale;
    func_800BA7C4(emitter, scale * 0.02f, scale * 0.15f);
    scale = arg0->scale;
    func_800BA7FC(emitter, scale * 0.05f, scale * 0.1f);
    rotation = arg0->rotation[1];
    func_800BA994(emitter, -45, (s16)(s32)(rotation - 25.0f), 25, -25, (s32)(rotation + 25.0f), 75);
    func_800BABB8(emitter, arg0->position, NULL, 1.0f, &D_808020E0_chlakemonster);
    func_800BA1D0(emitter, arg1, arg2, arg3);
}

void func_808001C0_chlakemonster(Actor *arg0) {
    s32 func_800B53A4(s32);
    void func_800BA22C(s32, s32);
    void func_800BA994(u8 *, s16, s16, s16, s16, s16, s16);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF214(f32 *, f32, f32, f32);
    void *func_80100094(Actor *, u32);
    extern s32 D_80802108_chlakemonster;
    struct {
        u8 pad[0x1C];
        f32 unk1C;
        f32 unk20;
    } *data;
    s32 emitter;
    f32 position[3];

    data = func_80100094(arg0, 0);
    emitter = func_800B53A4(2);
    func_800EE7F8(position, (f32 *)&arg0->actorData[4]);
    func_800EF214(position, data->unk20, data->unk1C - 30.0f, 150.0f);
    func_800BABB8(emitter, position, NULL, 1.0f, &D_80802108_chlakemonster);
    func_800BA994(emitter, (s16)(s32)(data->unk20 - 10.0f), (s16)(s32)(data->unk1C - 10.0f), (s16)(s32)(arg0->scale * 150.0f), (s32)(data->unk20 + 10.0f), (s32)(data->unk1C + 10.0f), (s32)(arg0->scale * 300.0f));
    func_800BA22C(emitter, 2);
}

void func_808002FC_chlakemonster(Actor *arg0) {
    s32 func_800B53A4(s32);
    void func_800BA22C(s32, s32);
    void func_800BA994(u8 *, s16, s16, s16, s16, s16, s16);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    void *func_80100094(Actor *, u32);
    extern s32 D_8080212C_chlakemonster;
    s32 emitter;
    struct {
        u8 pad[0x1C];
        f32 unk1C;
        f32 unk20;
    } *data;

    emitter = func_800B53A4(6);
    data = func_80100094(arg0, 0);
    func_800BABB8(emitter, (f32 *)&arg0->actorData[4], NULL, 1.0f, &D_8080212C_chlakemonster);
    func_800BA994(emitter, (s16)(s32)(data->unk20 - 10.0f), (s16)(s32)(data->unk1C - 10.0f), (s16)(s32)(arg0->scale * 100.0f), (s32)(data->unk20 + 10.0f), (s32)(data->unk1C + 10.0f), (s32)(arg0->scale * 200.0f));
    func_800BA22C(emitter, 6);
}

void func_80800404_chlakemonster(Actor *arg0) {
    s32 func_800B53A4(s32);
    void func_800BA22C(s32, s32);
    void func_800BA994(u8 *, s16, s16, s16, s16, s16, s16);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    void func_800DBEFC(void *, s32, f32 *);
    void *func_80100094(Actor *, u32);
    extern s32 D_80802150_chlakemonster;
    f32 position[3];
    s32 emitter;
    struct {
        u8 pad[0x1C];
        f32 unk1C;
        f32 unk20;
    } *data;

    emitter = func_800B53A4(3);
    data = func_80100094(arg0, 0);
    func_800DBEFC(arg0->unk0->unk4, 0xC, position);
    func_800BABB8(emitter, position, NULL, 1.0f, &D_80802150_chlakemonster);
    func_800BA994(emitter, (s16)(s32)((data->unk20 - 5.0f) - 15.0f), (s16)(s32)((data->unk1C - 5.0f) - 25.0f), (s16)(s32)(arg0->scale * 50.0f), (s32)((data->unk20 + 5.0f) - 15.0f), (s32)((data->unk1C + 5.0f) - 25.0f), (s32)(arg0->scale * 100.0f));
    func_800BA22C(emitter, 3);
    emitter = func_800B53A4(3);
    func_800DBEFC(arg0->unk0->unk4, 0xD, position);
    func_800BABB8(emitter, position, NULL, 1.0f, &D_80802150_chlakemonster);
    func_800BA994(emitter, (s16)(s32)((data->unk20 - 5.0f) - 15.0f), (s16)(s32)((data->unk1C - 5.0f) + 25.0f), (s16)(s32)(arg0->scale * 50.0f), (s32)((data->unk20 + 5.0f) - 15.0f), (s32)(data->unk1C + 5.0f + 25.0f), (s32)(arg0->scale * 100.0f));
    func_800BA22C(emitter, 3);
}

void func_8080064C_chlakemonster(Actor *arg0) {
    typedef struct {
        u8 unk0[0xC];
        f32 unkC[3];
        u8 unk18[0x26];
        u8 unk3E;
        u8 unk3F;
    } LakeData;
    void func_800DBEFC(void *, s32, f32 *);
    s32 func_800DC128(s32, s32);
    void func_800EF04C(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    void func_80800090_chlakemonster(Actor *, f32 *, f32 *, s32);
    extern s32 D_80802174_chlakemonster[][2];
    extern s32 D_80802178_chlakemonster[][2];
    LakeData *sp3C;
    f32 sp30[3];
    f32 sp24[3];
    s32 sp20;

    sp3C = func_80100094(arg0, 0);
    sp20 = func_800DC128(4, 7);
    func_800DBEFC(arg0->unk0->unk4, D_80802174_chlakemonster[sp20][0], sp30);
    func_800DBEFC(arg0->unk0->unk4, D_80802178_chlakemonster[sp20][0], sp24);
    if (sp3C->unk3F != 0) {
        func_800EF04C(sp30, sp3C->unkC);
        func_800EF04C(sp24, sp3C->unkC);
    }
    func_80800090_chlakemonster(arg0, sp30, sp24, func_800DC128(1, 3) + sp3C->unk3E);
}

s32 func_80800724_chlakemonster(Actor *arg0) {
    s32 _dbmorph_entrypoint_3(u8 *, u8 *, s32, u8, u8 *);
    u8 *func_800B2768(u8 *);
    s32 func_800B2840(s32);
    s32 func_800D674C(s32);
    void func_800E02F8(s16 *, f32, s32, s32, s32, f32 *);
    void *func_80100094(Actor *, u32);
    f32 func_80101F24(Actor *);
    u8 *func_801039E4(Unk80132ED0 *);
    s32 func_80103CB8(Actor *, u32);
    u8 *sp44;
    s16 sp42;
    struct {
        u8 pad[0x2C];
        f32 morph[1];
    } *sp3C;

    sp44 = func_801039E4(arg0->unk0);
    sp42 = 0;
    sp3C = func_80100094(arg0, 0);
    switch (arg0->unk70_10) {
        case 2: sp42 = 0x1F2; break;
        case 3: sp42 = 0x1F3; break;
        case 4: sp42 = 0x1F4; break;
    }
    if (sp42 != 0) {
        func_800E02F8(func_800D674C(sp42), func_80101F24(arg0), 0, 0x2A, 0x2D, sp3C->morph);
    }
    _dbmorph_entrypoint_3(func_800B2768(sp44), func_80103CB8(arg0, sp44), func_800B2840(sp44), 1, sp3C->morph);
}

/* extern */

void func_80800838_chlakemonster(Actor *arg0) {
    s32 _dbmorph_entrypoint_4(u8 *, u8 *, s32, u8, s32);
    s32 func_800AE080(s16);
    s32 func_800AE0E8(s16);
    u8 *func_800B2768(u8 *);
    s32 func_800B2840(s32);
    s32 func_801015D0(Actor *);
    u8 *func_801039E4(Unk80132ED0 *);
    s32 func_80103CB8(Actor *, u32);
    s32 func_80800724_chlakemonster(Actor *);
    s32 sp34;
    u8 *sp30;
    struct {
        u8 pad[0x17];
        u8 unused : 7;
        u8 active : 1;
    } *sp2C;
    s32 sp28;

    sp34 = func_801039E4(arg0->unk0);
    sp30 = func_800B2768(sp34);
    sp2C = func_80103CB8(arg0, sp34);
    sp28 = func_800B2840(sp34);
    func_80800724_chlakemonster(arg0);
    if (func_801015D0(arg0)) {
    }
    sp2C->active = 1;
    if (func_800AE0E8(*(s16 *)&arg0->unk0->unk10) != 0) {
        _dbmorph_entrypoint_4(sp30, sp2C, sp28, 1, func_800AE080(*(s16 *)&arg0->unk0->unk10));
    }
}

void func_808008E8_chlakemonster(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    f32 func_800D8FF8(void);
    void *func_80100094(Actor *, u32);
    extern s32 D_80802030_chlakemonster;
    void *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    if (*(f32 *)((s8 *)temp_v0 + 0x24) <= 0.0f) {
        _subaddieaudioquick_entrypoint_2(arg0, (f32 *)&arg0->actorData[4], &D_80802030_chlakemonster);
        *(f32 *)((s8 *)temp_v0 + 0x24) = 2.5f;
    } else {
        *(f32 *)((s8 *)temp_v0 + 0x24) -= func_800D8FF8();
    }
}

void func_80800968_chlakemonster(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void *func_80100094(Actor *, u32);
    extern s32 D_80802044_chlakemonster;
    void *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    if (*(f32 *)((s8 *)temp_v0 + 0x28) <= 0.0f) {
        _subaddieaudioquick_entrypoint_2(arg0, (f32 *)&arg0->actorData[4], &D_80802044_chlakemonster);
        *(f32 *)((s8 *)temp_v0 + 0x28) = 1.5f;
    }
}

/* extern */

void func_808009CC_chlakemonster(void) {
    s32 _gcgoto_entrypoint_1(s32, s32);
    s32 func_800DA544(s32);
    s32 func_800F54E4();
    s32 func_800F7C9C(s32, s32, s32, s32);
    func_800F7C9C(func_800F54E4(), 0x95, 0x116, 0xA);
    _gcgoto_entrypoint_1(0x123, 1);
    func_800DA544(0x6E8);
}

s32 func_8001210C(s32);

void func_80800A14_chlakemonster(Actor *arg0, s32 arg1, s32 arg2) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_80018820(s32, f32, f32);
    void func_8009086C(s32);
    void *func_80100094(Actor *, u32);
    s32 func_80101180(s32, s32, s32);
    s32 func_80101DDC(Actor *);
    s32 func_80101E14(Actor *, f32);
    s32 func_80101E4C(Actor *, f32 *);
    f32 func_80101F24(Actor *);
    extern s32 D_80802058_chlakemonster;
    extern s32 D_8080207C_chlakemonster;
    struct {
        u8 pad0[0x18];
        f32 unk18;
        u8 pad1C[0x21];
        s8 unk3D;
    } *sp5C;

    sp5C = func_80100094(arg0, 0);
    if (arg2 != 0) {
        func_8080064C_chlakemonster(arg0);
    }
    if (arg0->unk7C_12) {
        struct AnimTimes5 { f32 values[5]; };
        struct AnimTimes2 { f32 values[2]; };
        extern struct AnimTimes5 D_808021B4_chlakemonster;
        extern struct AnimTimes2 D_808021C8_chlakemonster;
        extern struct AnimTimes5 D_808021D0_chlakemonster;
        extern struct AnimTimes2 D_808021E4_chlakemonster;
        struct AnimTimes5 sp48 = D_808021B4_chlakemonster;
        struct AnimTimes2 sp40 = D_808021C8_chlakemonster;
        struct AnimTimes5 sp2C = D_808021D0_chlakemonster;
        struct AnimTimes2 sp24 = D_808021E4_chlakemonster;
        f32 sp20;

        sp20 = func_80101F24(arg0);
        if (func_80101E4C(arg0, sp2C.values) != 0) {
            _subaddieaudioquick_entrypoint_2(arg0, (f32 *)&arg0->actorData[4], &D_80802058_chlakemonster);
            sp5C->unk18 = 0.85f;
        } else if (func_80101E4C(arg0, sp40.values) != 0) {
            func_808008E8_chlakemonster(arg0);
            func_808001C0_chlakemonster(arg0);
        } else if (func_80101E4C(arg0, sp48.values) != 0) {
            func_80800968_chlakemonster(arg0);
        } else if (func_80101E4C(arg0, sp24.values) == 0) {
            if (func_80101E14(arg0, 0.965f) != 0) {
                _subaddieaudioquick_entrypoint_2(arg0, (f32 *)&arg0->actorData[4], &D_8080207C_chlakemonster);
                func_80018820(0, 2.0f, 0.25f);
                if (arg1 != 0) {
                    func_80101180(0x501, 0xBC, 0);
                } else {
                    sp5C->unk3D = 1;
                    func_8009086C(0);
                }
            } else if ((func_80101DDC(arg0) != 0) && (arg1 == 0)) {
                func_808009CC_chlakemonster();
            }
        }
        if ((sp20 > 0.24f) && (sp20 < 0.31f) && (func_8001210C(0xF) != 0)) {
            func_808001C0_chlakemonster(arg0);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lakemonster/func_80800C88_chlakemonster.s")

void func_808013E8_chlakemonster(s32 *arg0) {
    s32 func_8008F8B0();
    s32 func_8008F8D8(s32);
    s32 func_8008F904(s32 *, s32);
    s32 func_8008F938(s32);
    s32 func_8008F964(s32 *);
    s32 func_8008F9C4(s32 *, s32);
    extern s32 D_808020D4_chlakemonster;
    extern s32 func_8010D5DC;
    func_8008F8B0();
    func_8008F964(&D_808020D4_chlakemonster);
    func_8008F8D8(0);
    func_8008F938(1);
    func_8008F904(&func_8010D5DC, *arg0);
    func_8008F9C4(&D_808020D4_chlakemonster, 0x3F400000);
}

void func_80801448_chlakemonster(u8 *arg0, u32 arg1, s32 arg2) {
    struct Flags { u8 pad[0x74]; u8 high : 1; u8 flag : 1; u8 low : 6; };
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0*, u32, u32, f32*, u32);
    arg2 |= 7;
    _subaddiedialog_entrypoint_11((*(Unk80132ED0 **)((s8 *)(arg0) + (0))), arg1, arg2, (f32 *)(arg0 + 4), 0xB3U);
    ((struct Flags *)arg0)->flag = 1;
}

s32 func_80801494_chlakemonster(s32 arg0, s32 arg1) {
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    void func_80090658(s32);
    void func_80090708(s32);
    void func_8009086C(s32);
    int func_800C6E38(s32);
    s32 func_800F54E4(void);
    s32 func_800F7B9C(s32, s32);
    u32 func_800FDC28(u32);
    u32 *func_80100074(Actor *, u32, u32);
    void *func_80100094(Actor *, u32);
    void func_80101EE4(Actor *, f32);
    void func_80102424(Actor *, s32);
    struct {
        u8 pad0[0x18];
        f32 unk18;
        u8 pad1C[0x20];
        u8 unk3C;
        u8 unk3D;
        u8 unk3E;
    } *data;
    Actor *actor = (Actor *)arg0;

    data = func_80100094(actor, 0);
    switch (actor->unk70_10) {
        case 1:
            func_80100074(actor, 0, 0x40);
            data = func_80100094(actor, 0);
            data->unk3C = 0;
            data->unk3D = 0;
            data->unk3E = 0;
            data->unk18 = 0.0f;
            func_80090658(1);
            actor->unk64_16 = 1;
            break;
        case 2:
            func_800FDC28(0);
            break;
    }
    func_80102424(actor, arg1);
    switch (arg1) {
        case 0:
            break;
        case 7:
            func_80101EE4(actor, 0.35f);
            break;
        case 1:
            actor->unk64_16 = 0;
            func_80090658(0);
            func_80100074(actor, 0, 0);
            break;
        case 2:
            func_808013E8_chlakemonster((s32 *)actor);
            func_800FDC28(1);
            _capod_entrypoint_13(actor->unk0, NULL, 6, 0x20);
            break;
        case 3:
            _capod_entrypoint_13(actor->unk0, NULL, 8, 0x10);
            func_800F7B9C(func_800F54E4(), 0x96);
            data->unk3D = 1;
            func_8009086C(0);
            func_80090658(0);
            func_80090708(2);
            break;
        case 4:
            func_808013E8_chlakemonster((s32 *)actor);
            _capod_entrypoint_13(actor->unk0, NULL, 0xA, 0x20);
            break;
        case 5:
            actor->unk64_16 = 0;
            break;
        case 6:
            func_80090658(0);
            actor->unk64_16 = 0;
            if (!func_800C6E38(0x15)) {
                func_80801448_chlakemonster((u8 *)actor, 0x1819, 0);
            } else {
                func_80801448_chlakemonster((u8 *)actor, 0x180E, 0);
            }
            break;
    }
}

s32 func_808016B0_chlakemonster(Actor *arg0, s32 arg1, s32 arg2) {
    void func_80090708(s32);
    s32 func_800DA9E4(s32, s32);
    s32 func_80801494_chlakemonster(s32, s32);

    switch (arg1) {
        case 0x32:
            func_80090708(2);
            return 1;
        case 0x2E:
            arg0->unk74_30 = 0;
            if (*(s16 *)&arg2 == 0x180E) {
                func_80801494_chlakemonster(arg0, 5);
            }
            break;
        case 0x49:
            if (func_800DA9E4(0x6E8, 0)) {
                func_80801494_chlakemonster(arg0, 3);
            }
            break;
        case 0x1F:
            func_80800838_chlakemonster(arg0);
            return 1;
        default:
            return 0;
    }
    return 1;
}

OSThread *chlakemonster_entrypoint_0(void)
{
    extern u8 D_80802204_chlakemonster[];

    return (OSThread *) D_80802204_chlakemonster;
}

void func_80801790_chlakemonster();
void func_80801790_chlakemonster(Actor *arg0, u32 arg1) {
    struct Flags { u8 pad[0x7E]; u8 high : 1; u8 flag : 1; u8 low : 6; };
    void func_80101FDC(Actor *, u32);
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);

    func_80101FDC(arg0, arg1);
    switch (arg0->unk70_10) {
        case 1:
            arg0->position[1] = -1000.0f;
            break;
        case 3:
            ((struct Flags *)arg0)->flag = 0;
            arg0->position[1] = 0.0f;
            break;
        case 2:
            _capod_entrypoint_13(arg0->unk0, NULL, 0, 0x10);
            *(f32 *)&arg0->actorData[7] = 0.0f;
            arg0->unk50 = 50.0f;
            break;
    }
}

/* extern */

void func_80801834_chlakemonster(s16 *arg0) {
    s32 func_800DA298(s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_80801790_chlakemonster();

    func_800EE7F8((f32 *)(arg0 + 12), (f32 *)(arg0 + 2));
    func_800EFA4C((f32 *)(arg0 + 2), 0.0f, 0.0f, 0.0f);
    if (func_800DA298(0x187) != 0) {
        func_80801790_chlakemonster(arg0, 3);
        return;
    }
    func_80801790_chlakemonster(arg0, 1);
}

void func_808018AC_chlakemonster(s32 arg0) 
{
}
/* extern */

void chlakemonster_entrypoint_1(s32 arg0) {
    s32 _fxripple_entrypoint_0(s32);
    _fxripple_entrypoint_0(0);
}

void chlakemonster_entrypoint_2(f32 *arg0, f32 *arg1, s32 arg2, s32 arg3) {
    s32 func_800B53A4(s32);
    void func_800BA1D0(s32, f32 *, f32 *, s32);
    void func_800BA544(s32 *, s32);
    void func_800BA568(s16 *, s16);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    int func_800DC298(f32);
    extern s32 D_8080224C_chlakemonster;
    extern s32 _chlakemonster_entrypoint_1;
    s32 sp2C;
    s32 temp_v0;

    temp_v0 = func_800B53A4(6);
    sp2C = temp_v0;
    func_800BA568(temp_v0, (s16)(s32)*(f32 *)&arg3);
    func_800BA544(sp2C, &_chlakemonster_entrypoint_1);
    if (func_800DC298(0.5f) != 0) {
        *arg1 -= 100.0f;
        *arg0 -= 100.0f;
    } else {
        *arg1 += 100.0f;
        *arg0 += 100.0f;
    }
    func_800BABB8(sp2C, arg1, 0, 1.0f, &D_8080224C_chlakemonster);
    func_800BA1D0(sp2C, arg0, arg1, 6);
}

void chlakemonster_entrypoint_3(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    s32 func_800B53A4(s32);
    void func_800BA1D0(s32, f32[3], f32[3], s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    extern s32 D_8080229C_chlakemonster;
    s32 sp24;
    s32 temp_v0;

    temp_v0 = func_800B53A4(3);
    sp24 = temp_v0;
    (*(f32 *)((s8 *)(arg1) + (4))) = (f32) ((*(f32 *)((s8 *)(arg1) + (4))) + 200.0f);
    (*(f32 *)((s8 *)(arg0) + (4))) = (f32) ((*(f32 *)((s8 *)(arg0) + (4))) + 200.0f);
    func_800BABB8(temp_v0, arg1, NULL, 1.0f, &D_8080229C_chlakemonster);
    func_800BA1D0(sp24, arg0, arg1, 3);
}

void func_80801A60_chlakemonster(void *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void chlakemonster_entrypoint_2(f32 *, f32 *, s32, s32);
    s32 func_800C2FDC(u8);
    void func_800C3058(u8, s32);
    void func_800C31DC(u8, f32);
    u8 func_800C4350(s32, s32, s32 *);
    f32 func_800D8FF8(void);
    s32 func_800DC128(s32, s32);
    f32 func_800DC178(f32, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    extern s32 D_808020BC_chlakemonster;
    extern s32 D_808022C8_chlakemonster;
    f32 start[3];
    f32 end[3];

    switch ((u32)*(u16 *)((u8 *)arg0 + 0x72) >> 10) {
    case 1:
        break;
    case 2:
        if (*(f32 *)((u8 *)arg0 + 8) >= 0.0f) {
            func_80801790_chlakemonster(arg0, 3);
            return;
        }
        *(f32 *)((u8 *)arg0 + 8) += func_800D8FF8() * *(f32 *)((u8 *)arg0 + 0x50);
        *(f32 *)((u8 *)arg0 + 0x50) += 5.0f;
        if (func_8001210C(1)) {
            start[1] = *(f32 *)((u8 *)arg0 + 8) + -3050.0f;
            end[1] = start[1];
            switch (func_800DC128(0, 3)) {
            case 0:
                start[0] = 30.0f;
                start[2] = 735.0f;
                end[0] = 504.0f;
                end[2] = 1423.0f;
                chlakemonster_entrypoint_2(start, end, 0x42480000, 0xC53EA000);
                chlakemonster_entrypoint_3(start, end, 0x42480000, 0xC53EA000);
                break;
            case 1:
                end[0] = 504.0f;
                end[2] = 1423.0f;
                start[0] = -194.0f;
                start[2] = 2263.0f;
                chlakemonster_entrypoint_2(start, end, 0x42480000, 0xC53EA000);
                chlakemonster_entrypoint_3(start, end, 0x42480000, 0xC53EA000);
                break;
            case 2:
                start[0] = -194.0f;
                start[2] = 2263.0f;
                end[0] = 4.0f;
                end[2] = 3081.0f;
                chlakemonster_entrypoint_2(start, end, 0x42480000, 0xC53EA000);
                chlakemonster_entrypoint_3(start, end, 0x42480000, 0xC53EA000);
                break;
            }
            if (*(f32 *)((u8 *)arg0 + 0x58) <= 0.0f) {
                _subaddieaudioquick_entrypoint_2(arg0, end, &D_808020BC_chlakemonster);
                *(f32 *)((u8 *)arg0 + 0x58) = func_800DC178(1.0f, 2.0f) * 0.15f;
            } else {
                *(f32 *)((u8 *)arg0 + 0x58) -= func_800D8FF8();
            }
        }
        if (*((u8 *)arg0 + 0x5F) == 0) {
            *((u8 *)arg0 + 0x5F) = func_800C4350(0, (s32)((u8 *)arg0 + 4), &D_808022C8_chlakemonster);
        } else {
            if (*(f32 *)((u8 *)arg0 + 8) < -750.0f) {
                *(f32 *)((u8 *)arg0 + 0x34) = func_800F10B4(*(f32 *)((u8 *)arg0 + 8), -1000.0f, -850.0f, 0.0f, 32000.0f);
            }
            *(f32 *)((u8 *)arg0 + 0x54) = func_800F10B4(*(f32 *)((u8 *)arg0 + 8), -1000.0f, 0.0f, 0.05f, 1.0f);
            func_800C3058(*((u8 *)arg0 + 0x5F), (s32)*(f32 *)((u8 *)arg0 + 0x34));
            func_800C31DC(*((u8 *)arg0 + 0x5F), *(f32 *)((u8 *)arg0 + 0x54));
            func_800C4350(*((u8 *)arg0 + 0x5F), (s32)((u8 *)arg0 + 0x18), NULL);
        }
        break;
    case 3:
        if (*((u8 *)arg0 + 0x5F) != 0) {
            if (*(f32 *)((u8 *)arg0 + 0x34) > 500.0f) {
                *(f32 *)((u8 *)arg0 + 0x34) *= 0.7f;
                if (*(f32 *)((u8 *)arg0 + 0x54) > 0.05f) {
                    *(f32 *)((u8 *)arg0 + 0x54) *= 0.7f;
                }
                func_800C3058(*((u8 *)arg0 + 0x5F), (s32)*(f32 *)((u8 *)arg0 + 0x34));
                func_800C31DC(*((u8 *)arg0 + 0x5F), *(f32 *)((u8 *)arg0 + 0x54));
                func_800C4350(*((u8 *)arg0 + 0x5F), (s32)((u8 *)arg0 + 0x18), NULL);
            } else {
                func_800C2FDC(*((u8 *)arg0 + 0x5F));
                *((u8 *)arg0 + 0x5F) = 0;
            }
        }
        break;
    }
}

int func_80801E60_chlakemonster(Actor *arg0, s32 arg1, s32 arg2) {
    switch (arg1) {
        case 7:
            func_80801790_chlakemonster((s16 *) arg0, 2);
            break;
        default:
            return 0;
    }
    return 1;
}

OSThread *chlakemonster_entrypoint_4(void)
{
    extern u8 D_808022E0_chlakemonster[];

    return (OSThread *) D_808022E0_chlakemonster;
}

/* extern */

void func_80801EA8_chlakemonster(s32 arg0) {
    s32 _chswitch_entrypoint_14(s32, s32);
    s32 func_800DA298(s32);
    _chswitch_entrypoint_14(arg0, 0x187);
    if (func_800DA298(0x187) != 0) {
        func_8010A570(arg0);
    }
}

void func_80801EE4_chlakemonster(s32 arg0) 
{
}
s32 func_80801EEC_chlakemonster(Actor *arg0, s32 arg1, s32 arg2) {
    s32 func_80101180(s32, s32, s32);
    if (arg1 == 7) {
        func_80101180(0x301, 7, 0);
        func_8010A570(arg0);
    } else {
        return 0;
    }
    return 1;
}

OSThread *chlakemonster_entrypoint_5(void)
{
    extern u8 D_80802328_chlakemonster[];

    return (OSThread *) D_80802328_chlakemonster;
}
