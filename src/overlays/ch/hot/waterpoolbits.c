#include "common.h"

OSThread *chhotwaterpoolbits_entrypoint_0(void)
{
    extern u8 D_80800930_chhotwaterpoolbits[];

    return (OSThread *) D_80800930_chhotwaterpoolbits;
}

OSThread *chhotwaterpoolbits_entrypoint_1(void)
{
    extern u8 D_80800978_chhotwaterpoolbits[];

    return (OSThread *) D_80800978_chhotwaterpoolbits;
}

OSThread *chhotwaterpoolbits_entrypoint_2(void)
{
    extern u8 D_808009C0_chhotwaterpoolbits[];

    return (OSThread *) D_808009C0_chhotwaterpoolbits;
}

OSThread *chhotwaterpoolbits_entrypoint_3(void)
{
    extern u8 D_80800A08_chhotwaterpoolbits[];

    return (OSThread *) D_80800A08_chhotwaterpoolbits;
}

/* extern */

void func_80800030_chhotwaterpoolbits(s32 arg0) {
    s32 _chswitch_entrypoint_7(s32, s32);
    s32 _chswitch_entrypoint_8(s32, s32);
    s32 _chswitch_entrypoint_9(s32);
    s32 sp1C;

    sp1C = _chswitch_entrypoint_7(arg0, 0x167);
    _chswitch_entrypoint_8(arg0, 0x200);
    if (sp1C != 0) {
        _chswitch_entrypoint_9(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hot/waterpoolbits/func_80800078_chhotwaterpoolbits.s")

/* extern */

void func_80800124_chhotwaterpoolbits(Actor *arg0) {
    s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_5(Actor *, f32);
    void _chdoormake_entrypoint_6(Actor *, s32);
    void _chdoormake_entrypoint_8(void *, u32);
    s32 _chdoormake_entrypoint_9(Actor *, s32, s32, s32);
    if (_chdoormake_entrypoint_3(arg0, 0.0f, 90.0f, 300.0f, 0x60, 0x167) != 0) {
        _chdoormake_entrypoint_5(arg0, 2.0f);
        _chdoormake_entrypoint_6(arg0, 0x3E19999A);
        _chdoormake_entrypoint_9(arg0, 0, 0xD, 0x10);
        _chdoormake_entrypoint_8(arg0, 0xD);
    }
}

/* extern */

s32 func_808001A8_chhotwaterpoolbits(s32 arg0, s32 arg1, s32 arg2) {
    s32 _capod_entrypoint_14();
    s32 _chdoor_entrypoint_1(s32);
    s32 _glcutDll_entrypoint_6(s32, s32);
    void func_800FFAB0(Actor *);
    if ((arg1 == 0xB) && (arg2 == 0xD)) {
        _capod_entrypoint_14();
        _glcutDll_entrypoint_6(0x1A7, 0x29);
        func_800FFAB0(arg0);
        return 4;
    }
    return _chdoor_entrypoint_1(arg0);
}

void func_80800204_chhotwaterpoolbits(u8 *arg0) {
    s32 func_800F2E60(s32, s32 *, u8 *);
    extern s32 D_80800A50_chhotwaterpoolbits;
    func_800F2E60(arg0 + 0x28, &D_80800A50_chhotwaterpoolbits, arg0);
    (*(f32 *)((s8 *)(arg0) + (0x1C))) = 0.0f;
    (*(f32 *)((s8 *)(arg0) + (0x18))) = 127.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hot/waterpoolbits/func_8080024C_chhotwaterpoolbits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hot/waterpoolbits/func_808003E0_chhotwaterpoolbits.s")

void func_80800528_chhotwaterpoolbits(s32 *arg0) {
    s32 _glid_entrypoint_0(s32, s32, s32 *, s32);
    s32 func_800BEA88(s32);
    extern s32 _chhotwaterpoolbits_entrypoint_4;
    s32 temp_v0;

    temp_v0 = func_800BEA88(1);
    if (temp_v0 != 0) {
        _glid_entrypoint_0(temp_v0, 0xA, &_chhotwaterpoolbits_entrypoint_4, *arg0);
    }
}

/* extern */

void chhotwaterpoolbits_entrypoint_4(s32 arg0, Vtx *arg1, Vtx *arg2, s32 arg3, Unk80132ED0 *arg4) {
    Actor *func_80106790(Unk80132ED0 *);
    struct WaterData {
        f32 alpha;
        f32 height;
        s32 unused[2];
        s32 color[3];
    };
    Actor *actor;
    Vtx *end;
    u32 alpha;
    s16 height;
    s32 i;

    actor = func_80106790(arg4);
    alpha = (u32)((struct WaterData *)actor->actorData)->alpha & 0xFF;
    height = (s16)(s32)((struct WaterData *)actor->actorData)->height;
    end = arg2 + arg3;
    while (arg2 < end) {
        for (i = 0; i != 3; i++) {
            arg2->v.cn[i] = (arg1->v.cn[i] * ((struct WaterData *)actor->actorData)->color[i]) >> 8;
        }
        arg2->v.cn[3] = alpha;
        arg2++;
        arg1++;
        arg2[-1].v.ob[1] = arg1[-1].v.ob[1] + height;
    }
}

void func_808006BC_chhotwaterpoolbits(Actor *arg0) {
    s32 func_800DA298(s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800FFAB0(Actor *);
    if ((arg0->unk74_7 == 0x33) && (func_800DA298(0x31B) != 0)) {
        func_800FFAB0(arg0);
        return;
    }
    func_800EE7F8((f32 *)arg0->actorData, arg0->position);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hot/waterpoolbits/func_80800718_chhotwaterpoolbits.s")

void chhotwaterpoolbits_entrypoint_5(Actor *arg0, f32 arg1) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    void func_800EE780(f32 *, f32 *, f32 *);
    u32 func_800F54E4(void);
    void func_800F5A00(s32, f32 *);
    void func_800F7620(s32, f32, f32, f32);
    extern s32 D_80800A88_chhotwaterpoolbits[];
    extern s32 D_80800AC0_chhotwaterpoolbits;
    extern f32 D_80800AD8_chhotwaterpoolbits[3];
    f32 sp34[3];
    f32 sp28[3];
    s32 sp24;
    s32 temp_v0;

    temp_v0 = func_800F54E4();
    sp24 = temp_v0;
    func_800F7620(temp_v0, 1.0f, 0.5f, 0.4f);
    func_800F5A00(sp24, sp28);
    func_800EE780(sp34, sp28, D_80800AD8_chhotwaterpoolbits);
    func_800BABB8(0, sp28, sp34, arg1, D_80800A88_chhotwaterpoolbits);
    _subaddieaudioquick_entrypoint_2(arg0, sp28, &D_80800AC0_chhotwaterpoolbits);
}
