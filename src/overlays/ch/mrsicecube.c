#include "common.h"

OSThread *chmrsicecube_entrypoint_0(void)
{
    extern u8 D_8080099C_chmrsicecube[];

    return (OSThread *) D_8080099C_chmrsicecube;
}

OSThread *chmrsicecube_entrypoint_1(void)
{
    extern u8 D_808009E4_chmrsicecube[];

    return (OSThread *) D_808009E4_chmrsicecube;
}

/* extern */

void func_80800018_chmrsicecube(Actor *arg0) {
    s32 _glcutDll_entrypoint_20();
    void _subaddielink_entrypoint_0(void *);
    s32 func_800DA298(s32);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);
    u32 func_8010A5B0(Actor *, s32);
    void func_8010A800(Actor *, s32);
    u8 *sp24;
    s32 temp_v0;

    sp24 = func_80100094(arg0, 0);
    func_8010A800(arg0, 0);
    _subaddielink_entrypoint_0(sp24);
    temp_v0 = arg0->unk74_7 - 0x32;
    arg0->actorData[4] = temp_v0;
    if (temp_v0 == 0) {
        func_8010A5B0(arg0, func_800DA298(0x1C5));
        if (_glcutDll_entrypoint_20() != 0) {
            func_80102424(arg0, 7);
            return;
        }
        if (func_800DA298(0x378) != 0) {
            func_800FFAB0(arg0);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mrsicecube/func_808000BC_chmrsicecube.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mrsicecube/func_80800260_chmrsicecube.s")

/* extern */

void func_808003BC_chmrsicecube(Actor *arg0, s32 arg1) {
    Actor *_subaddielink_entrypoint_4(u8 *);
    void func_800DF744(s32, s32);
    s32 func_800E3E8C(f32 *, f32);
    void *func_80100094(Actor *, u32);
    s32 func_80101870(u8 *, s32);
    f32 func_80103FB8(Actor *);
    void func_8010A764(s32, s32);
    Actor *temp_v0;

    if (func_800E3E8C(arg0->position, func_80103FB8(arg0)) != 0) {
        temp_v0 = _subaddielink_entrypoint_4(func_80100094(arg0, 0));
        if (temp_v0 != 0) {
            func_8010A764(temp_v0, arg1);
        }
        func_800DF744(3, arg0->unk64_19);
        func_80101870(arg0, arg1);
    }
}

s32 *func_8080043C_chmrsicecube(u8 *arg0, s32 arg1, f32 *arg2) {
    s32 *_subaddiefind_entrypoint_0(s32, s32, s32, s32);
    void func_800EE7F8(f32 *, f32 *);
    s32 *temp_v0;

    temp_v0 = _subaddiefind_entrypoint_0((s32)(arg0 + 4), arg1, -1, 0);
    if (temp_v0 != NULL) {
        func_800EE7F8(arg2, (f32 *)(temp_v0 + 1));
    }
    return temp_v0;
}

Unk80132ED0 *func_8080048C_chmrsicecube(u8 *arg0, s32 arg1, f32 *arg2) {
    Prop *_gccubesearch_entrypoint_6(s32 *, f32 *);
    Unk80132ED0 *_subaddiefind_entrypoint_12(s32);
    void func_800EE88C(f32 *, s16 *);
    extern s32 D_80800A3C_chmrsicecube;
    Prop *prop;
    Unk80132ED0 *actor;

    D_80800A3C_chmrsicecube = arg1;
    prop = _gccubesearch_entrypoint_6(&D_80800A3C_chmrsicecube, (f32 *)(arg0 + 4));
    if (prop == NULL) {
        return NULL;
    }
    actor = _subaddiefind_entrypoint_12(*(u32 *)&prop->unk10 >> 21);
    if (actor != NULL) {
        func_800EE88C(arg2, prop->position);
    }
    return actor;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mrsicecube/func_80800508_chmrsicecube.s")

void func_80800634_chmrsicecube(s32 arg0) {
    s32 _subaddiedialog_entrypoint_8(s32, void *, s32 *, s32 *, s32);
    extern s32 D_808008F0_chmrsicecube;
    extern s32 D_80800A44_chmrsicecube;
    _subaddiedialog_entrypoint_8(arg0, (s8 *)arg0 + 4, &D_80800A44_chmrsicecube, &D_808008F0_chmrsicecube, 4);
}

void func_8080066C_chmrsicecube(u8 *arg0, u8 *arg1)
{
  void func_800EE7F8(f32 *, f32 *);
  func_800EE7F8((f32 *)arg1, (f32 *)(arg0 + 4));
  *((f32 *) (((s8 *) arg1) + 4)) += (*((f32 *) (((s8 *) arg0) + 0x38))) * 100.0f;
}

void func_808006C4_chmrsicecube(Actor *arg0) {
    void _chbounce_entrypoint_5(s32, void *);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    void _subaddielink_entrypoint_0(void *);
    Actor *_subaddielink_entrypoint_4(u8 *);
    void func_800DA544(s32);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    void func_80102190(void *, s32);
    s32 func_80102F74(Unk80132ED0 *, s32);
    void func_80103110(Actor *, u32);
    void func_8010A590(Actor *);
    u32 func_8010A654(void ***, s32);
    void func_80800818_chmrsicecube(u8 *);
    extern u16 D_80800912_chmrsicecube[][2];
    extern s32 D_80800A54_chmrsicecube;
    struct MrsIceCubeLinkData { s32 unk0; s32 unk4; s32 unk8; } *sp2C;
    struct MrsIceCubeFlags {
        u8 pad[0x74];
        u32 pad74_21 : 11;
        u32 unk74_20 : 1;
        u32 pad74_0 : 20;
    };
    Actor *temp_s0;
    s32 temp_v1;

    sp2C = func_80100094(arg0, 0);
    temp_s0 = _subaddielink_entrypoint_4(sp2C);
    temp_v1 = arg0->actorData[4];
    if (temp_v1 == 0) {
        _subaddiedialog_entrypoint_11(arg0->unk0, 0x12D3, 0x44, 0, 0xA7);
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80800A54_chmrsicecube);
        func_800DA544(0x378);
    }
    if (temp_s0 != NULL) {
        _subaddielink_entrypoint_0(sp2C);
        func_8010A590(temp_s0);
        func_8010A654(temp_s0, func_80102F74(temp_s0, 0x800));
        func_80102190(temp_s0, 0);
        func_80103110(temp_s0, func_80102F74(temp_s0, 0x80000800) == 0);
        temp_s0->unk64_24 = func_80102F74(temp_s0, 0x80000001);
        temp_s0->unk64_16 = 1;
        ((struct MrsIceCubeFlags *)temp_s0)->unk74_20 = sp2C->unk8;
        _chbounce_entrypoint_5(D_80800912_chmrsicecube[arg0->actorData[4]][0], temp_s0);
    }
    func_80800818_chmrsicecube(arg0);
    func_800FFAB0(arg0);
}

void func_80800818_chmrsicecube(u8 *arg0) {
    s32 pad[2];
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 func_800BBCB8(u8 *, u8 *, f32, s32, s32 *);
    s32 func_801094E0(u8 *, f32);
    extern s32 D_80800A64_chmrsicecube;
    extern s32 D_80800A74_chmrsicecube;
    u8 sp2C[3];

    func_8080066C_chmrsicecube(arg0, sp2C);
    func_800BBCB8(sp2C, arg0 + 4, (*(f32 *)((s8 *)(arg0) + (0x38))), 0xC, &D_80800A74_chmrsicecube);
    _subaddieaudioquick_entrypoint_2(arg0, sp2C, &D_80800A64_chmrsicecube);
    func_801094E0(sp2C, (*(f32 *)((s8 *)(arg0) + (0x38))) * 3.0f);
}

void func_80800898_chmrsicecube(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    extern u32 D_80800AB8_chmrsicecube;
    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80800AB8_chmrsicecube, 0.1f);
}
