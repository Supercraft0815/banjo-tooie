#include "common.h"

extern u32 D_80801FF0_chlakemonster[];
void _chswitch_entrypoint_0();
void _chswitch_entrypoint_13();
void func_80101870(Actor *, void *);
void func_801018A4(Actor *, s32);
void func_80105834(Actor *);
void *func_80107C2C(s32 *, s32, void *, s32, void *);
void func_80800000_chlakemonster(s32 arg0);
void func_80800064_chlakemonster(Actor *arg0);
void func_80800C88_chlakemonster(Actor *arg0);
s32 func_808016B0_chlakemonster(Actor *arg0, s32 arg1, s32 arg2);
void func_80801834_chlakemonster(s16 *arg0);
void func_808018AC_chlakemonster(s32 arg0);
void func_80801A60_chlakemonster(void *arg0);
int func_80801E60_chlakemonster(Actor *arg0, s32 arg1, s32 arg2);
void func_80801EA8_chlakemonster(s32 arg0);
void func_80801EE4_chlakemonster(s32 arg0);
s32 func_80801EEC_chlakemonster(Actor *arg0, s32 arg1, s32 arg2);

u32 D_80801FF0_chlakemonster[] = {
    0x00000000, 0x00000000, 0x424C0000, 0x01690044,
    0x41880000, 0x01690042, 0x40F66666, 0x01FD0042,
    0x4019999A, 0x01FE0042, 0x40F66666, 0x01FD0084,
    0x424C0000, 0x01690044, 0x41880000, 0x01690002,
};

u32 D_80802030_chlakemonster[] = {
    0x0013054F, 0x000D00F3, 0x01000018, 0x000109C4,
    0x13880000,
};

u32 D_80802044_chlakemonster[] = {
    0x0013054E, 0x000D00F3, 0x01000018, 0x000109C4,
    0x13880000,
};

u32 D_80802058_chlakemonster[] = {
    0x00130551, 0x000D00CC, 0x00E60018, 0x000109C4,
    0x13880000, 0x001304EF, 0x00180001, 0x09C41388,
    0x00000000,
};

u32 D_8080207C_chlakemonster[] = {
    0x00130554, 0x00180001, 0x09C41388, 0x00000000,
};

u32 D_8080208C_chlakemonster[] = {
    0x00130550, 0x000D00D9, 0x00F30016, 0x3E800001,
    0x09C41388, 0x00000000,
};

u32 D_808020A4_chlakemonster[] = {
    0x00130550, 0x000D010F, 0x01280016, 0x3E800001,
    0x09C41388, 0x00000000,
};

u32 D_808020BC_chlakemonster[] = {
    0x001303ED, 0x000D0066, 0x00800016, 0x2EE00001,
    0x09C41388, 0x00000000,
};

u32 D_808020D4_chlakemonster[] = {
    0x00000000, 0xC4ED8000, 0x00000000,
};

u32 D_808020E0_chlakemonster[] = {
    0x001D09F3, 0x0020FFFF, 0xFEB4001B, 0xF254F254,
    0x00070001, 0x00150000, 0x00CC002B, 0x00800100,
    0x00161000, 0x00000000,
};

u32 D_80802108_chlakemonster[] = {
    0x001D09DD, 0x00160200, 0x80020022, 0x00800080,
    0x05800780, 0x00150033, 0x0080002B, 0x00190040,
    0x00000000,
};

u32 D_8080212C_chlakemonster[] = {
    0x001D09DD, 0x00160200, 0x80020022, 0x00000000,
    0x01CC0280, 0x00150000, 0x0080002B, 0x01990200,
    0x00000000,
};

u32 D_80802150_chlakemonster[] = {
    0x001D09DD, 0x00160200, 0x80020022, 0x00000000,
    0x00CC0180, 0x00150000, 0x004C002B, 0x01990200,
    0x00000000,
};

u32 D_80802174_chlakemonster[] = {
    0x00000004,
};

u32 D_80802178_chlakemonster[] = {
    0x00000009, 0x00000009, 0x0000000B, 0x0000000B,
    0x0000000A, 0x0000000A, 0x00000005, 0x00000005,
    0x00000007, 0x00000007, 0x00000008, 0x00000008,
    0x00000006, 0x00000006, 0x00000004,
};

u32 D_808021B4_chlakemonster[] = {
    0x3D71A9FC, 0x3ED1EB85, 0x3F47AE14, 0x3F70A3D7,
    0xBF800000,
};

u32 D_808021C8_chlakemonster[] = {
    0x3E75C28F, 0xBF800000,
};

u32 D_808021D0_chlakemonster[] = {
    0x3F1C28F6, 0x3F2B851F, 0x3F326E98, 0x3F400000,
    0xBF800000,
};

u32 D_808021E4_chlakemonster[] = {
    0x3CBC6A7F, 0xBF800000,
};

u32 D_808021EC_chlakemonster[] = {
    0x3F0CCCCD, 0x3F400000, 0xBF800000,
};

u32 D_808021F8_chlakemonster[] = {
    0x00000000, 0xC4ED8000, 0x00000000,
};

u32 D_80802204_chlakemonster[] = {
    0x02E50300, 0x06D50001, (u32)D_80801FF0_chlakemonster, (u32)func_80800C88_chlakemonster,
    (u32)func_80105834, (u32)func_801018A4, 0x00000000, 0x00000000,
    0x00000000, 0x0008046C, (u32)func_80800064_chlakemonster, 0x00000000,
    0x00000000, (u32)func_80800000_chlakemonster, (u32)func_80107C2C, 0x80800002,
    (u32)func_808016B0_chlakemonster, 0x00000000,
};

u32 D_8080224C_chlakemonster[] = {
    0x001D09D9, 0x00160004, 0x001B0096, 0x00960007,
    0x00010015, 0x000000CC, 0x0020FFFF, 0xFEFF002F,
    0x00400040, 0x00000000, 0x00190000, 0x0033002B,
    0x008000C0, 0x0022000C, 0x00190026, 0x0059002C,
    0xFFD80190, 0xFFD80028, 0x01F40028, 0x00000000,
};

u32 D_8080229C_chlakemonster[] = {
    0x001D09DD, 0x002A0000, 0x00190180, 0x01800015,
    0x003300B3, 0x00160200, 0x0020C4C4, 0xFF600022,
    0x008000C0, 0x01800280, 0x00000000,
};

u32 D_808022C8_chlakemonster[] = {
    0x02060013, 0x03EC000A, 0x00250016, 0x00000001,
    0x09C41388, 0x00000000,
};

u32 D_808022E0_chlakemonster[] = {
    0x02E60301, 0x074B0001, 0x00000000, (u32)func_80801A60_chlakemonster,
    (u32)func_80105834, (u32)func_80101870, 0x17700000, 0x00000000,
    0x00000000, 0x00000C00, (u32)func_808018AC_chlakemonster, 0x00000000,
    0x00000000, (u32)func_80801834_chlakemonster, (u32)func_80107C2C, 0x80080402,
    (u32)func_80801E60_chlakemonster, 0x00000000,
};

u32 D_80802328_chlakemonster[] = {
    0x02E70370, 0x094B0001, 0x8011A298, (u32)_chswitch_entrypoint_13,
    (u32)func_80105834, (u32)func_80101870, 0x00000000, 0x00000000,
    0x00000000, 0x00000808, (u32)func_80801EE4_chlakemonster, (u32)_chswitch_entrypoint_0,
    0x00000000, (u32)func_80801EA8_chlakemonster, (u32)func_80107C2C, 0x80080C00,
    (u32)func_80801EEC_chlakemonster, 0x00000000,
};

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
    func_800BABB8(emitter, arg0->position, NULL, 1.0f, &(*(s32 *)D_808020E0_chlakemonster));
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
    func_800BABB8(emitter, position, NULL, 1.0f, &(*(s32 *)D_80802108_chlakemonster));
    func_800BA994(emitter, (s16)(s32)(data->unk20 - 10.0f), (s16)(s32)(data->unk1C - 10.0f), (s16)(s32)(arg0->scale * 150.0f), (s32)(data->unk20 + 10.0f), (s32)(data->unk1C + 10.0f), (s32)(arg0->scale * 300.0f));
    func_800BA22C(emitter, 2);
}

void func_808002FC_chlakemonster(Actor *arg0) {
    s32 func_800B53A4(s32);
    void func_800BA22C(s32, s32);
    void func_800BA994(u8 *, s16, s16, s16, s16, s16, s16);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    void *func_80100094(Actor *, u32);
    s32 emitter;
    struct {
        u8 pad[0x1C];
        f32 unk1C;
        f32 unk20;
    } *data;

    emitter = func_800B53A4(6);
    data = func_80100094(arg0, 0);
    func_800BABB8(emitter, (f32 *)&arg0->actorData[4], NULL, 1.0f, &(*(s32 *)D_8080212C_chlakemonster));
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
    func_800BABB8(emitter, position, NULL, 1.0f, &(*(s32 *)D_80802150_chlakemonster));
    func_800BA994(emitter, (s16)(s32)((data->unk20 - 5.0f) - 15.0f), (s16)(s32)((data->unk1C - 5.0f) - 25.0f), (s16)(s32)(arg0->scale * 50.0f), (s32)((data->unk20 + 5.0f) - 15.0f), (s32)((data->unk1C + 5.0f) - 25.0f), (s32)(arg0->scale * 100.0f));
    func_800BA22C(emitter, 3);
    emitter = func_800B53A4(3);
    func_800DBEFC(arg0->unk0->unk4, 0xD, position);
    func_800BABB8(emitter, position, NULL, 1.0f, &(*(s32 *)D_80802150_chlakemonster));
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
    LakeData *sp3C;
    f32 sp30[3];
    f32 sp24[3];
    s32 sp20;

    sp3C = func_80100094(arg0, 0);
    sp20 = func_800DC128(4, 7);
    func_800DBEFC(arg0->unk0->unk4, ((s32 (*)[2])D_80802174_chlakemonster)[sp20][0], sp30);
    func_800DBEFC(arg0->unk0->unk4, ((s32 (*)[2])D_80802178_chlakemonster)[sp20][0], sp24);
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
    void *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    if (*(f32 *)((s8 *)temp_v0 + 0x24) <= 0.0f) {
        _subaddieaudioquick_entrypoint_2(arg0, (f32 *)&arg0->actorData[4], &(*(s32 *)D_80802030_chlakemonster));
        *(f32 *)((s8 *)temp_v0 + 0x24) = 2.5f;
    } else {
        *(f32 *)((s8 *)temp_v0 + 0x24) -= func_800D8FF8();
    }
}

void func_80800968_chlakemonster(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void *func_80100094(Actor *, u32);
    void *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    if (*(f32 *)((s8 *)temp_v0 + 0x28) <= 0.0f) {
        _subaddieaudioquick_entrypoint_2(arg0, (f32 *)&arg0->actorData[4], &(*(s32 *)D_80802044_chlakemonster));
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
        struct AnimTimes5 sp48 = (*(struct AnimTimes5 *)D_808021B4_chlakemonster);
        struct AnimTimes2 sp40 = (*(struct AnimTimes2 *)D_808021C8_chlakemonster);
        struct AnimTimes5 sp2C = (*(struct AnimTimes5 *)D_808021D0_chlakemonster);
        struct AnimTimes2 sp24 = (*(struct AnimTimes2 *)D_808021E4_chlakemonster);
        f32 sp20;

        sp20 = func_80101F24(arg0);
        if (func_80101E4C(arg0, sp2C.values) != 0) {
            _subaddieaudioquick_entrypoint_2(arg0, (f32 *)&arg0->actorData[4], &(*(s32 *)D_80802058_chlakemonster));
            sp5C->unk18 = 0.85f;
        } else if (func_80101E4C(arg0, sp40.values) != 0) {
            func_808008E8_chlakemonster(arg0);
            func_808001C0_chlakemonster(arg0);
        } else if (func_80101E4C(arg0, sp48.values) != 0) {
            func_80800968_chlakemonster(arg0);
        } else if (func_80101E4C(arg0, sp24.values) == 0) {
            if (func_80101E14(arg0, 0.965f) != 0) {
                _subaddieaudioquick_entrypoint_2(arg0, (f32 *)&arg0->actorData[4], &(*(s32 *)D_8080207C_chlakemonster));
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

void func_80800C88_chlakemonster(Actor *arg0) {
    s32 _chintrotext_entrypoint_1(s32, s32, s32, s32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 func_8008FD70(void);
    s32 func_80090248(void);
    s32 func_80090298(void);
    void func_80090590(s32, f32 *);
    void func_800906B0(f32 *);
    void func_80090708(s32);
    void func_800907C0(f32 *);
    void func_80090840(f32 *);
    void func_8009086C(s32);
    int func_800C6E38(s32);
    f32 func_800D8FF8(void);
    s32 func_800DA298(s32);
    s32 func_800DA544(s32);
    void func_800DBEFC(void *, s32, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EEB40(f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    void func_800EFB24(void *, void *, void *);
    f32 func_800F1828(f32 *, f32 *);
    f32 func_800F1DF4(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    s32 func_80101DDC(Actor *);
    s32 func_80101E14(Actor *, f32);
    s32 func_80101E4C(Actor *, f32 *);
    f32 func_80101F24(Actor *);
    s32 func_801022E4(Actor *);
    s32 func_8010CAC0(s32 *, s32);
    s32 func_8010CB84(s32 *, s32);
    s32 func_80801494_chlakemonster(s32, s32);
    struct {
        f32 position[3];
        f32 velocity[3];
        f32 unk18;
        f32 unk1C;
        f32 unk20;
        f32 unk24;
        f32 unk28;
        u8 pad2C[0x11];
        u8 unk3D;
        u8 unk3E;
        u8 unk3F;
    } *sp94;
    s32 sp90;
    f32 sp84[3];
    f32 sp78[3];
    f32 sp6C[3];
    f32 sp60[3];
    s32 sp5C;
    s32 sp58;
    s32 sp54;
    struct AnimTimes3 { f32 values[3]; };
    struct AnimTimes3 sp48;
    f32 sp3C[3];
    f32 sp38;
    f32 sp34;
    s32 sp30;

    sp94 = func_80100094(arg0, 0);
    sp90 = 0;
    if (sp94 != NULL) {
        if (arg0->unk7C_12) {
            func_800DBEFC(arg0->unk0->unk4, 8, sp84);
            func_800DBEFC(arg0->unk0->unk4, 11, sp78);
            if (12000.0f < func_800EEB40(sp84, sp78)) {
                if (sp94->unk3E == 0) sp94->unk3E = 10;
                sp90 = 1;
            }
            func_800DBEFC(arg0->unk0->unk4, 5, (f32 *)&arg0->actorData[4]);
            func_800DBEFC(arg0->unk0->unk4, 4, sp6C);
            func_800EF04C((f32 *)&arg0->actorData[4], sp6C);
            func_800EF334((f32 *)&arg0->actorData[4], 0.5f);
            if (sp94->unk3F != 0) {
                func_800EFB24(sp94->velocity, (f32 *)&arg0->actorData[4], sp94->position);
                func_800EE7F8(sp94->position, (f32 *)&arg0->actorData[4]);
                func_800EF334(sp94->velocity, 2.0f);
                func_800EF04C((f32 *)&arg0->actorData[4], sp94->velocity);
            } else {
                func_800EE7F8(sp94->position, (f32 *)&arg0->actorData[4]);
                sp94->unk3F = 1;
            }
            func_800DBEFC(arg0->unk0->unk4, 11, sp6C);
            func_800DBEFC(arg0->unk0->unk4, 8, sp60);
            func_800EF04C(sp6C, sp60);
            func_800EF334(sp6C, 0.5f);
            sp94->unk1C = func_800F1DF4((f32 *)&arg0->actorData[4], sp6C);
            sp94->unk20 = -func_800F1828((f32 *)&arg0->actorData[4], sp6C);
        }
        if (sp94->unk3E > 0) {
            sp94->unk3E--;
        }
    }
    switch (arg0->unk70_10) {
        case 1:
            if ((func_8010CAC0(&(*(s32 *)D_808020D4_chlakemonster), 0xBE) != 0) && (func_80090248() != 0)) {
                sp5C = 6;
                sp58 = func_8008FD70() == 1;
                sp54 = func_800C6E38(0x15);

                if (sp58 && sp54) {
                    if (func_800DA298(0x1B9) == 0) {
                        _chintrotext_entrypoint_1(0x18B9, 2, 1, 0);
                        func_800DA544(0x1B9);
                        sp5C = 2;
                    } else {
                        sp5C = 4;
                    }
                }
                func_80801494_chlakemonster((s32)arg0, sp5C);
            }
            break;
        case 2:
            if (func_80090298() != 0) {
                func_80090840((f32 *)&arg0->actorData[4]);
            }
            func_80800A14_chlakemonster(arg0, 0, sp90);
            if (arg0->unk7C_12 && (sp94->unk3D != 0)) {
                func_800907C0((f32 *)&arg0->actorData[4]);
            }
            break;
        case 3: {
            sp48 = (*(struct AnimTimes3 *)D_808021EC_chlakemonster);

            if (sp90 != 0) {
                func_8080064C_chlakemonster(arg0);
            }
            if (func_80101E14(arg0, 0.4f) != 0) {
                func_808008E8_chlakemonster(arg0);
                func_808001C0_chlakemonster(arg0);
            } else if (func_80101E4C(arg0, sp48.values) != 0) {
                func_80800968_chlakemonster(arg0);
                func_808001C0_chlakemonster(arg0);
            }
            if (func_80101DDC(arg0) != 0) {
                func_80801494_chlakemonster((s32)arg0, 5);
            }
            if (arg0->unk7C_12 && (sp94->unk3D != 0)) {
                func_800EE7F8(sp3C, (f32 *)&arg0->actorData[4]);
                sp3C[1] -= 275.0f;
                func_800906B0(sp3C);
                if (func_80101E14(arg0, 0.4f) != 0) {
                    func_80090708(0);
                    func_80090590(0x2F, ((f32 *)D_808021F8_chlakemonster));
                    func_8009086C(1);
                    sp94->unk3D = 0;
                }
            }
            break;
        }
        case 4:
            if (func_80090298() != 0) {
                func_80090840((f32 *)&arg0->actorData[4]);
            }
            if (sp90 != 0) {
                func_8080064C_chlakemonster(arg0);
            }
            if (func_80101E14(arg0, 0.07f) != 0) {
                func_80800968_chlakemonster(arg0);
            } else if (func_80101E14(arg0, 0.8f) != 0) {
                _subaddieaudioquick_entrypoint_2(arg0, (f32 *)&arg0->actorData[4], &(*(s32 *)D_8080207C_chlakemonster));
                sp94->unk3D = 1;
                func_8009086C(0);
            } else if (func_80101E14(arg0, 0.7f) != 0) {
                func_808008E8_chlakemonster(arg0);
            } else if (func_80101DDC(arg0) != 0) {
                func_808009CC_chlakemonster();
            }
            if (arg0->unk7C_12 && (sp94->unk3D != 0)) {
                func_800907C0((f32 *)&arg0->actorData[4]);
            }
            break;
        case 5:
            if (func_8010CB84(&(*(s32 *)D_808020D4_chlakemonster), 0xC8) == 0) {
                func_80801494_chlakemonster((s32)arg0, 1);
            }
            break;
        case 7:
            func_80800A14_chlakemonster(arg0, 1, sp90);
            break;
    }
    if (sp94 != NULL) {
        if (sp94->unk24 > 0.0f) {
            sp94->unk24 -= func_800D8FF8();
        }
        if (sp94->unk28 > 0.0f) {
            sp94->unk28 -= func_800D8FF8();
        }
        if (arg0->unk7C_12) {
            sp38 = func_800D8FF8();
            sp34 = func_80101F24(arg0);

            if ((sp94->unk24 <= 0.0f) && (sp94->unk28 <= 0.0f)) {
                sp30 = 0;

                switch (func_801022E4(arg0)) {
                    case 0x169:
                        if ((sp34 < 0.61f) || (sp34 > 0.77f)) {
                            sp30 = 1;
                        }
                        break;
                    case 0x1FD:
                    case 0x1FE:
                        sp30 = 1;
                        break;
                }
                if (sp30 != 0) {
                    if (sp94->unk18 > 0.0f) {
                        sp94->unk18 -= sp38;
                    } else {
                        sp94->unk18 = 2.5f;
                        if (arg0->unk64_19) {
                            _subaddieaudioquick_entrypoint_2(arg0, (f32 *)&arg0->actorData[4], &(*(s32 *)D_8080208C_chlakemonster));
                            if (sp90 != 0) {
                                func_808002FC_chlakemonster(arg0);
                            } else {
                                func_80800404_chlakemonster(arg0);
                            }
                            arg0->unk64_19 = 0;
                        } else {
                            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &(*(s32 *)D_808020A4_chlakemonster));
                            arg0->unk64_19 = 1;
                        }
                    }
                }
            }
        }
    }
}

void func_808013E8_chlakemonster(s32 *arg0) {
    s32 func_8008F8B0();
    s32 func_8008F8D8(s32);
    s32 func_8008F904(s32 *, s32);
    s32 func_8008F938(s32);
    s32 func_8008F964(s32 *);
    s32 func_8008F9C4(s32 *, s32);
    extern s32 func_8010D5DC;
    func_8008F8B0();
    func_8008F964(&(*(s32 *)D_808020D4_chlakemonster));
    func_8008F8D8(0);
    func_8008F938(1);
    func_8008F904(&func_8010D5DC, *arg0);
    func_8008F9C4(&(*(s32 *)D_808020D4_chlakemonster), 0x3F400000);
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
    return (OSThread *) ((u8 *)D_80802204_chlakemonster);
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
    func_800BABB8(sp2C, arg1, 0, 1.0f, &(*(s32 *)D_8080224C_chlakemonster));
    func_800BA1D0(sp2C, arg0, arg1, 6);
}

void chlakemonster_entrypoint_3(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    s32 func_800B53A4(s32);
    void func_800BA1D0(s32, f32[3], f32[3], s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    s32 sp24;
    s32 temp_v0;

    temp_v0 = func_800B53A4(3);
    sp24 = temp_v0;
    (*(f32 *)((s8 *)(arg1) + (4))) = (f32) ((*(f32 *)((s8 *)(arg1) + (4))) + 200.0f);
    (*(f32 *)((s8 *)(arg0) + (4))) = (f32) ((*(f32 *)((s8 *)(arg0) + (4))) + 200.0f);
    func_800BABB8(temp_v0, arg1, NULL, 1.0f, &(*(s32 *)D_8080229C_chlakemonster));
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
                _subaddieaudioquick_entrypoint_2(arg0, end, &(*(s32 *)D_808020BC_chlakemonster));
                *(f32 *)((u8 *)arg0 + 0x58) = func_800DC178(1.0f, 2.0f) * 0.15f;
            } else {
                *(f32 *)((u8 *)arg0 + 0x58) -= func_800D8FF8();
            }
        }
        if (*((u8 *)arg0 + 0x5F) == 0) {
            *((u8 *)arg0 + 0x5F) = func_800C4350(0, (s32)((u8 *)arg0 + 4), &(*(s32 *)D_808022C8_chlakemonster));
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
    return (OSThread *) ((u8 *)D_808022E0_chlakemonster);
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
    return (OSThread *) ((u8 *)D_80802328_chlakemonster);
}
