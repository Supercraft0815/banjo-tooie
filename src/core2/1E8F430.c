#include "core2/1E8F430.h"

extern s32 D_801282B4;

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8F430/func_800B5B40.s")

void func_800B5B88(void) {
    s8 func_800B5758(s32);
    extern s32 D_8011A5C2;
    extern s32 D_80128151;
    extern s32 D_80128179;
    s8 *var_s0;
    s8 *var_s1;
    s8 *var_s2;
    s8 temp_v0;

    var_s0 = (s8 *) &D_80128151; var_s1 = (s8 *) &D_8011A5C2; var_s2 = (s8 *) &D_80128179;
    do {
        temp_v0 = func_800B5758((s32) (*(u8 *)(var_s1 + 1)));
        var_s0 += 1;
        var_s1 += 2;
        var_s0[-1] = temp_v0;
    } while (var_s0 != var_s2);
}

s32 func_800B5BE4(s32 arg0) {
    void *func_800B56D0(u8);
    extern u8 D_80128150[];
    return (s32) func_800B56D0(D_80128150[arg0]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8F430/func_800B5C10.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8F430/func_800B5C7C.s")

void func_800B5DD4()
{
    func_800B5C7C(0x8);
}

void func_800B5DF4(void) {
}

void func_800B5DFC(void) {
}

void func_800B5E04(void) {
    s32 vector_free(s32);
    extern s32 D_80128180;
    if (D_80128180 != 0) {
        vector_free(D_80128180);
        D_80128180 = 0;
    }
}

void func_800B5E3C(void) {
    s32 vector_defrag(s32);
    extern s32 D_80128180;
    if (D_80128180 != 0) {
        D_80128180 = vector_defrag(D_80128180);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8F430/func_800B5E74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8F430/func_800B5FE4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8F430/func_800B60C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8F430/func_800B62CC.s")

void func_800B7174(u8 *arg0) {
    struct Input { union { struct { s16 value; u16 rest; } halves; struct { unsigned int pad : 16; unsigned int nibble : 4; unsigned int rest : 12; } nib; struct { unsigned int pad : 20; unsigned int flag11 : 1; unsigned int pad2 : 1; unsigned int flag9 : 1; unsigned int rest : 9; } bits; } data; };
    struct Output { u8 pad[0x1C]; s8 f1c, f1d, f1e, f1f, f20, f21; s16 f22; u8 pad24[4]; s16 f28, f2a; };
    extern s32 D_80128180;
    extern s32 D_801281A4;
    void func_800F2EBC(void *, void *);
    struct Output *out = (struct Output *)&D_80128180;
    struct Input *in = (struct Input *)(arg0 + 4);
    out->f1d = 0;
    out->f1c = 0;
    out->f1f = 0;
    out->f20 = (u32)(u16)(in->data.halves.rest & 0xFFFF) >> 12;
    out->f22 = in->data.halves.value;
    out->f21 = in->data.bits.flag11;
    out->f1e = in->data.bits.flag9;
    out->f2a = 0;
    out->f28 = out->f2a;
    func_800F2EBC(&D_801281A4, arg0 + 0x10);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8F430/func_800B71F4.s")

void func_800B7448(Gfx **arg0) {
    void func_800B62CC(Gfx **, u8, f32 *, f32 *, f32);
    void func_800B7174(u8 *);
    s32 func_800B71F4(Gfx **, u8 *);
    void func_800B7A98(void);
    s32 func_800D35BC(u32);
    s32 func_800D3724(u32);
    s32 func_800E7188(u8 *);
    void func_800E7694(void);
    void func_800E76A4(Gfx **, s32);
    s32 func_800E7778(Gfx **, s32);
    s32 func_800E7828(Gfx **, s32 *);
    s32 func_800E7988(Gfx **, s32);
    s32 func_800E79E8(Gfx **);
    s32 func_800E7A4C(Gfx **);
    u32 vector_begin(s32);
    s32 vector_clear(s32);
    u32 vector_end(s32);
    s32 vector_size(s32);
    extern s32 D_8011A620;
    extern s32 D_80128180;
    struct FlagWord { u32 upper : 16; u32 font : 4; u32 bit11 : 1; u32 highlight : 1; u32 lower : 10; };
    s32 var_s0;
    f32 sp88;
    f32 sp84;
    u32 temp_s0;
    s32 temp_s3;
    u32 sp78;
    f32 temp_f14;
    f32 temp_f20;
    u32 var_s1;

    if (((*(s32 *)((s8 *)(&D_80128180) + (0))) != 0) && (vector_size((*(s32 *)((s8 *)(&D_80128180) + (0)))) > 0)) {
        func_800E79E8(arg0);
        func_800E7988(arg0, 0);
        temp_s0 = vector_begin((*(s32 *)((s8 *)(&D_80128180) + (0))));
        sp78 = vector_end((*(s32 *)((s8 *)(&D_80128180) + (0))));
        var_s1 = temp_s0;
        if (temp_s0 < sp78) {
            do {
                (*(s32 *)((s8 *)(&D_80128180) + (4))) = func_800D3724(((struct FlagWord *)(var_s1 + 4))->font);
                if ((*(s32 *)((s8 *)(&D_80128180) + (4))) != 0) {
                    sp88 = (f32) (*(s16 *)((s8 *)(var_s1) + (0)));
                    sp84 = (f32) (*(s16 *)((s8 *)(var_s1) + (2)));
                    if (((struct FlagWord *)(var_s1 + 4))->highlight) {
                        temp_s3 = func_800D35BC(((struct FlagWord *)(var_s1 + 4))->font);
                        temp_f20 = (f32) ((func_800E7188((*(u8 **)((s8 *)(var_s1) + (0xC)))) - 1) * temp_s3);
                        func_800E7828(arg0, &D_8011A620);
                        func_800E7778(arg0, 0);
                        func_800E76A4(arg0, 2);
                        temp_f14 = (f32) (temp_s3 / 2);
                        gDPFillRectangle((*arg0)++,
                            sp88 - temp_f14 > 1.0f ? sp88 - temp_f14 - 1.0f : 0.0f,
                            sp84 - temp_f14 > 1.0f ? sp84 - temp_f14 - 1.0f : 0.0f,
                            sp88 + temp_f20 + temp_f14 > 0.0f ? sp88 + temp_f20 + temp_f14 : 0.0f,
                            temp_f14 + sp84 + 1.0f > 0.0f ? temp_f14 + sp84 + 1.0f : 0.0f);
                        func_800E7694();
                    }
                    func_800B71F4(arg0, (u8 *) var_s1);
                    func_800B7174((u8 *) var_s1);
                    for (var_s0 = 0; ((*(u8 **)((s8 *)var_s1 + 0xC))[var_s0] != 0) || (*(u8 *)((s8 *)&D_80128180 + 0x1D) != 0) || (*(u8 *)((s8 *)&D_80128180 + 0x1C) != 0); var_s0++) {
                        func_800B62CC(arg0, (*(u8 **)((s8 *)var_s1 + 0xC))[var_s0], &sp88, &sp84, *(f32 *)((s8 *)var_s1 + 8));
                        if (*(s32 *)((s8 *)&D_80128180 + 4) == 0) {
                            break;
                        }
                    }
                }
                var_s1 += 0x14;
            } while (var_s1 < sp78);
        }
        func_800E7A4C(arg0);
        vector_clear((*(s32 *)((s8 *)(&D_80128180) + (0))));
    }
    func_800B7A98();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8F430/func_800B798C.s")

void func_800B7A98(void) {
    extern s32 D_80128180;
    u8 *ptr = (u8 *)&D_80128180;
    ptr[12] = ptr[13] = ptr[14] = ptr[15] = 0xFF;
    ptr[19] = 0;
    ptr[16] = ptr[19];
    ptr[18] = ptr[16];
    ptr[17] = 0;
    *(s16 *)(ptr + 20) = -0x7FFF;
    *(f32 *)(ptr + 24) = 1.0f;
}

void func_800B7ADC(s32 arg0) {
    extern s8 D_8012818F;
    *(s8 *)((u8 *)&D_8012818F + 0) = arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8F430/func_800B7AE8.s")

void func_800B7B2C(s32 arg0) {
    extern s16 D_80128194;
    *(s16 *)((u8 *)&D_80128194 + 0) = arg0;
}

void func_800B7B38(s32 arg0) {
    extern s8 D_80128191;
    *(s8 *)((u8 *)&D_80128191 + 0) = arg0;
}

void func_800B7B44(s32 arg0) {
    extern s8 D_80128193;
    if (arg0 != 0) {
        D_80128193 = 1;
        return;
    }
    D_80128193 = 0;
}

void func_800B7B68(s32 arg0) {
    extern s8 D_80128192;
    if (arg0 != 0) {
        D_80128192 = 1;
        return;
    }
    D_80128192 = 0;
}

void func_800B7B8C(s32 arg0, s32 arg1, s32 arg2) {
    extern s32 D_80128180;
    *(u8 *)((s8 *)&D_80128180 + 0xC) = arg0;
    *(u8 *)((s8 *)&D_80128180 + 0xD) = arg1;
    *(u8 *)((s8 *)&D_80128180 + 0xE) = arg2;
}

void func_800B7BA4(f32 arg0) {
    extern f32 D_80128198;
    *(f32 *)((u8 *)&D_80128198 + 0) = arg0;
}

void func_800B7BB0(void) {
    s32 _fxleaves_entrypoint_1(s32);
    s32 _fxrain_entrypoint_1(s32);
    s32 func_800B956C();
    extern s32 D_80127128;
    extern s32 D_801282B0;
    if (D_801282B0 != 0) {
        _fxleaves_entrypoint_1(D_801282B0);
    }
    if (D_801282B4 != 0) {
        _fxrain_entrypoint_1(D_801282B4);
    }
    if (D_80127128 != 0) {
        func_800B956C();
    }
}

s32 func_800B7C10(void) {
    extern s32 D_801282B0;
    s32 _fxleaves_entrypoint_4(s32);

    if (D_801282B0 == 0) {
        D_801282B0 = _fxleaves_entrypoint_4(0x32);
    }
    return D_801282B0;
}

s32 func_800B7C54(void) {
    extern s32 D_801282B4;
    s32 _fxrain_entrypoint_5(s32);

    if (D_801282B4 == 0) {
        D_801282B4 = _fxrain_entrypoint_5(0x1E);
    }
    return D_801282B4;
}

s32 func_800B7C98()
{
    return D_801282B4;
}

void func_800B7CA4()
{
    func_800B9038();
}

void func_800B7CC4(void) {
    s32 _fxleaves_entrypoint_3(s32);
    s32 _fxrain_entrypoint_4(s32);
    s32 func_800B8FEC();
    extern s32 D_801282B0;
    if (D_801282B0 != 0) {
        _fxleaves_entrypoint_3(D_801282B0);
    }
    if (D_801282B4 != 0) {
        _fxrain_entrypoint_4(D_801282B4);
    }
    func_800B8FEC();
}

void func_800B7D14(void) {
    extern s32 D_801282B0;
    (*(s32 *)((s8 *)(&D_801282B0) + (0))) = 0;
    (*(s32 *)((s8 *)(&D_801282B0) + (4))) = 0;
}

void func_800B7D28(void) {
    s32 _fxleaves_entrypoint_5(s32);
    s32 _fxrain_entrypoint_7(s32);
    s32 func_800B90C8();
    extern s32 D_801282B0;
    if (D_801282B0 != 0) {
        _fxleaves_entrypoint_5(D_801282B0);
    }
    if (D_801282B4 != 0) {
        _fxrain_entrypoint_7(D_801282B4);
    }
    func_800B90C8();
}

void func_800B7D78(void) {
    s32 _fxleaves_entrypoint_6(s32);
    s32 _fxrain_entrypoint_8(s32);
    s32 func_800B90E8();
    extern s32 D_801282B0;
    if (D_801282B0 != 0) {
        _fxleaves_entrypoint_6(D_801282B0);
    }
    if (D_801282B4 != 0) {
        _fxrain_entrypoint_8(D_801282B4);
    }
    func_800B90E8();
}

void func_800B7DC8(void) {
    s32 _fxleaves_entrypoint_0(s32);
    s32 _fxleaves_entrypoint_6(s32);
    s32 _fxrain_entrypoint_0(s32);
    s32 _fxrain_entrypoint_8(s32);
    s32 func_800B8FE0();
    s32 func_800B90E8();
    extern s32 D_801282B0;
    if (D_801282B0 != 0) {
        _fxleaves_entrypoint_0(D_801282B0);
        _fxleaves_entrypoint_6(D_801282B0);
    }
    if (D_801282B4 != 0) {
        _fxrain_entrypoint_0(D_801282B4);
        _fxrain_entrypoint_8(D_801282B4);
    }
    func_800B8FE0();
    func_800B90E8();
}

void func_800B7E38(void) {
    s32 _fxleaves_entrypoint_7(s32);
    s32 _fxrain_entrypoint_9(s32);
    s32 func_800B9170();
    extern s32 D_80127128;
    extern s32 D_801282B0;
    if (D_801282B0 != 0) {
        _fxleaves_entrypoint_7(D_801282B0);
    }
    if (D_801282B4 != 0) {
        _fxrain_entrypoint_9(D_801282B4);
    }
    if (D_80127128 != 0) {
        func_800B9170();
    }
}
