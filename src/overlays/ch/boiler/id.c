#include "common.h"

OSThread *chboilerid_entrypoint_0(void)
{
    extern u8 D_80800D5C_chboilerid[];

    return (OSThread *) D_80800D5C_chboilerid;
}

void func_8080000C_chboilerid(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 func_800EA05C(void);
    s32 _subaddielink_entrypoint_0(u8 *);
    s32 func_80800C48_chboilerid(Actor *);
    s32 func_80800CB0_chboilerid(Actor *);
    void _mlwave_entrypoint_0(void *, f32, f32);
    s32 func_800DA524(s32);
    extern s16 D_80800D00_chboilerid[][15];
    Actor *data;
    s32 index;

    data = func_80100094(arg0, 0);
    *(s16 *)&data->pad5E = func_800EA05C();
    _subaddielink_entrypoint_0((u8 *)&data->pad60);
    func_80800C48_chboilerid(arg0);
    *(f32 *)&data->actorData[1] = 0.0f;
    index = func_80800CB0_chboilerid(data);
    _mlwave_entrypoint_0(data, 500.0f, (f32)D_80800D00_chboilerid[index][0]);
    _mlwave_entrypoint_0(&data->unk3C, 200.0f, (f32)D_80800D00_chboilerid[index][4]);
    _mlwave_entrypoint_0(&data->actorData[2], 300.0f, (f32)D_80800D00_chboilerid[index][8]);
    ((s16 *)&data->unk58)[0] = D_80800D00_chboilerid[index][13];
    ((s16 *)&data->unk58)[1] = D_80800D00_chboilerid[index][12];
    *(s16 *)&data->pad5C = D_80800D00_chboilerid[index][14];
    func_800DA524(0x66F);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boiler/id/func_80800128_chboilerid.s")

/* extern */
s32 func_808003AC_chboilerid(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    s32 _subaddielink_entrypoint_3(u8 *);
    if (arg1 == 0x95) {
        _subaddielink_entrypoint_3((u8 *)func_80100094(arg0, 0U) + 0x60);
        return 1;
    }
    return 0;
}

/* extern */

void func_808003EC_chboilerid(s32 arg0) {
    s32 func_800CF494();
    s32 func_800DA524(s32);
    func_800DA524(0x66F);
    func_800CF494();
}

/* extern */

void func_80800418_chboilerid(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    s32 _mlwave_entrypoint_1(u8 *);
    _mlwave_entrypoint_1(func_80100094(arg0, 0U));
}

void func_80800440_chboilerid(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 _mlwave_entrypoint_1(u8 *);
    _mlwave_entrypoint_1((u8 *)func_80100094(arg0, 0U) + 0x20);
}

void func_80800468_chboilerid(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 _mlwave_entrypoint_1(u8 *);
    _mlwave_entrypoint_1((u8 *)func_80100094(arg0, 0U) + 0x3C);
}

void chboilerid_entrypoint_1(s32 arg0, s16 *arg1, u32 arg2, s32 arg3, Unk80132ED0 *arg4) {
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    void func_80800700_chboilerid(s16 *, s16 *, u8 *);
    u32 temp_s3;
    u8 *temp_s2;

    temp_s2 = func_80100094(func_80106790(arg4), 0);
    temp_s3 = arg2 + arg3 * 0x10;
    if (arg2 < temp_s3) {
        do {
            func_80800700_chboilerid(arg1, (s16 *)arg2, temp_s2);
            arg2 += 0x10;
            arg1 += 8;
        } while (arg2 < temp_s3);
    }
}

void chboilerid_entrypoint_2(s32 arg0, s16 *arg1, u32 arg2, s32 arg3, Unk80132ED0 *arg4) {
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    void func_80800700_chboilerid(s16 *, s16 *, u8 *);
    void func_8080079C_chboilerid(s16 *, s16 *, u8 *);
    u32 temp_s3;
    u8 *temp_s2;

    temp_s2 = func_80100094(func_80106790(arg4), 0);
    temp_s3 = arg2 + arg3 * 0x10;
    if (arg2 < temp_s3) {
        do {
            func_80800700_chboilerid(arg1, (s16 *)arg2, temp_s2);
            func_8080079C_chboilerid(arg1, (s16 *)arg2, temp_s2);
            arg2 += 0x10;
            arg1 += 8;
        } while (arg2 < temp_s3);
    }
}

void chboilerid_entrypoint_3(s32 arg0, s16 *arg1, u32 arg2, s32 arg3, Unk80132ED0 *arg4) {
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    void func_8080079C_chboilerid(s16 *, s16 *, u8 *);
    u32 temp_s3;
    u8 *temp_s2;

    temp_s2 = func_80100094(func_80106790(arg4), 0);
    temp_s3 = arg2 + arg3 * 0x10;
    if (arg2 < temp_s3) {
        do {
            func_8080079C_chboilerid(arg1, (s16 *)arg2, temp_s2);
            arg2 += 0x10;
            arg1 += 8;
        } while (arg2 < temp_s3);
    }
}

void chboilerid_entrypoint_4(s32 arg0, s16 *arg1, u32 arg2, s32 arg3, Unk80132ED0 *arg4) {
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    void func_80800700_chboilerid(s16 *, s16 *, u8 *);
    void func_8080079C_chboilerid(s16 *, s16 *, u8 *);
    void func_80800918_chboilerid(s16 *, s16 *, s16 *);
    u32 temp_s3;
    u8 *temp_s2;

    temp_s2 = func_80100094(func_80106790(arg4), 0);
    temp_s3 = arg2 + arg3 * 0x10;
    if (arg2 < temp_s3) {
        do {
            func_80800700_chboilerid(arg1, (s16 *)arg2, temp_s2);
            func_8080079C_chboilerid(arg1, (s16 *)arg2, temp_s2);
            func_80800918_chboilerid(arg1, (s16 *)arg2, (s16 *)temp_s2);
            arg2 += 0x10;
            arg1 += 8;
        } while (arg2 < temp_s3);
    }
}

void func_80800700_chboilerid(s16 *arg0, s16 *arg1, u8 *arg2) {
    f32 _mlwave_entrypoint_4(u8 *, f32, f32, f32);
    void func_800EE88C(f32 *, s16 *);
    f32 func_800EEF94(f32 *);
    s32 func_800F2FD0(void *, void *, f32);
    void func_800F3320(void *, void *, void *, f32);
    extern s32 D_80800DFC_chboilerid;
    f32 sp24[3];
    s32 sp20;
    f32 sp1C;

    func_800EE88C(sp24, arg0);
    sp1C = _mlwave_entrypoint_4(arg2, func_800EEF94(sp24), 0.6f, 1.0f);
    func_800F3320(&sp20, arg0 + 6, &D_80800DFC_chboilerid, *(f32 *)(arg2 + 0x1C) * 0.6666667f);
    func_800F2FD0(arg1 + 6, &sp20, sp1C);
}

void func_8080079C_chboilerid(s16 *arg0, s16 *arg1, u8 *arg2) {
    void func_8080084C_chboilerid(u8 *, s16 *, f32 *);
    f32 sp18[2];

    func_8080084C_chboilerid(arg2, arg0, sp18);
    arg1[4] = (s32)((f32)arg0[4] + (f32)*(s16 *)(arg2 + 0x58) * sp18[0]);
    arg1[5] = (s32)((f32)arg0[5] + (f32)*(s16 *)(arg2 + 0x58) * sp18[1]);
}

void func_8080084C_chboilerid(u8 *arg0, s16 *arg1, f32 *arg2) {
    f32 func_800136D0(f32);
    f32 func_800138BC(f32);
    void func_800EE88C(f32 *, s16 *);
    f32 func_800EEF94(f32 *);
    f32 sp34;
    f32 ratio;
    f32 sp24[3];
    f32 scale;

    func_800EE88C(sp24, arg1);
    sp34 = func_800EEF94(sp24);
    scale = *(f32 *)(arg0 + 0x24) * ((f32)*(s16 *)(arg0 + 0x5A) * func_800138BC(func_800136D0((sp34 - *(f32 *)(arg0 + 0x20)) * *(f32 *)(arg0 + 0x24))));
    if (sp34 != 0.0f) {
        ratio = scale / sp34;
        arg2[0] = sp24[0] * ratio;
        arg2[1] = sp24[2] * ratio;
    } else {
        arg2[0] = sp24[0] * scale;
        arg2[1] = sp24[2] * scale;
    }
}

/* extern */

void func_80800918_chboilerid(s16 *arg0, s16 *arg1, s16 *arg2) {
    f32 _mlwave_entrypoint_4(u8 *, f32, f32, f32);
    void func_800EE88C(f32 *, s16 *);
    f32 func_800EEF94(f32 *);
    f32 sp24[3];
    f32 height;

    func_800EE88C(sp24, arg0);
    height = _mlwave_entrypoint_4((u8 *)arg2 + 0x3C, func_800EEF94(sp24), 0.0f, (f32)arg2[0x2E]);
    arg1[1] = arg0[1] + (s16) height;
}

void func_80800998_chboilerid(s32 arg0) 
{
}
void chboilerid_entrypoint_5(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    s32 func_80800CB0_chboilerid(Actor *);
    void _mlwave_entrypoint_3(void *, f32, f32);
    extern s16 D_80800D00_chboilerid[][15];
    Actor *data;
    s32 index;

    data = func_80100094(arg0, 0);
    if (arg0->unk70_10 != 1 && arg0->unk70_10 != 4) {
        index = func_80800CB0_chboilerid(data);
        _mlwave_entrypoint_3(data, (f32)D_80800D00_chboilerid[index][0], (f32)D_80800D00_chboilerid[index][1]);
        _mlwave_entrypoint_3(&data->unk3C, (f32)D_80800D00_chboilerid[index][4], (f32)D_80800D00_chboilerid[index][5]);
        _mlwave_entrypoint_3(&data->actorData[2], (f32)D_80800D00_chboilerid[index][8], (f32)D_80800D00_chboilerid[index][9]);
        ((s16 *)&data->unk58)[0] = D_80800D00_chboilerid[index][13];
        ((s16 *)&data->unk58)[1] = D_80800D00_chboilerid[index][12];
        *(s16 *)&data->pad5C = D_80800D00_chboilerid[index][14];
        func_80101FDC(arg0, 4);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boiler/id/chboilerid_entrypoint_6.s")

/* extern */

s32 func_80800C48_chboilerid(Actor *arg0) {
    Actor *_subaddiefind_entrypoint_0(f32 *, s32, s32, s32);
    s32 _subaddielink_entrypoint_0(u8 *);
    s32 _subaddielink_entrypoint_1(void *, Unk80132ED0 *);
    void *func_80100094(Actor *, u32);
    u8 *sp1C;
    Actor *temp_v0;

    sp1C = func_80100094(arg0, 0U);
    temp_v0 = _subaddiefind_entrypoint_0(arg0->position, 0x118, -1, 0);
    if (temp_v0 != NULL) {
        _subaddielink_entrypoint_1(sp1C + 0x60, temp_v0->unk0);
        return 1;
    }
    _subaddielink_entrypoint_0(sp1C + 0x60);
    return 0;
}

/* extern */
s32 func_80800CB0_chboilerid(Actor *arg0) {
    switch (*(s16 *)&arg0->pad5E) {
        case 0xD1: return 0;
        case 0xE7: return 1;
        default: return 2;
    }
}
