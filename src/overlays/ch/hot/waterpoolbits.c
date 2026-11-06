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

s32 func_80800078_chhotwaterpoolbits(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _chswitch_entrypoint_10(s32, s32, s32);
    s32 _chswitch_entrypoint_9(s32);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 func_800DA298(s32);
    s32 func_80101180(s32, s32, s32);
    void func_80103110(Actor *, u32);

    if (arg1 == 7) {
        if (func_800DA298(0x31B) == 0) {
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x12B0, 0xF, arg0->position, 0);
        } else {
            func_80101180(0x428, arg1, 0);
            func_80101180(0x439, 0xA, 0x427);
            func_80103110(arg0, 0);
            _chswitch_entrypoint_9(arg0);
        }
    } else {
        return _chswitch_entrypoint_10(arg0, arg1, arg2);
    }
    return 1;
}

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
    void func_800F2E60(s32 *, s32 *);
    extern s32 D_80800A50_chhotwaterpoolbits;
    func_800F2E60((s32 *)(arg0 + 0x28), &D_80800A50_chhotwaterpoolbits);
    (*(f32 *)((s8 *)(arg0) + (0x1C))) = 0.0f;
    (*(f32 *)((s8 *)(arg0) + (0x18))) = 127.0f;
}

void func_8080024C_chhotwaterpoolbits(Actor *arg0) {
    s32 func_800D9078(f32 *arg0);
    f32 func_800F10B4(f32 value, f32 in_min, f32 in_max, f32 out_min, f32 out_max);
    f32 func_800F12D4(f32 a, f32 b, f32 c, f32 d, f32 e);
    void func_800F2E60(s32 arg0[3], s32 arg1[3]);
    int func_800F3214(void *arg0, void *arg1, void *arg2, f32 arg3);
    void func_800FFAB0(Actor *arg0);
    void func_80101FDC(Actor *arg0, u32 arg1);
    void func_80103110(Actor *arg0, u32 arg1);
    void func_80800528_chhotwaterpoolbits(s32 *arg0);
    extern s32 D_80800A50_chhotwaterpoolbits;
    extern s32 D_80800A5C_chhotwaterpoolbits[3];
    struct WaterData {
        f32 alpha;
        f32 height;
        int unused[2];
        int color[3];
    };
    f32 height;
    f32 alpha;

    switch (arg0->unk70_10) {
    case 2:
        if (func_800D9078(&arg0->unk58)) {
            func_80101FDC(arg0, 3);
            func_80103110(arg0, 0);
        }
        func_800F3214(((struct WaterData *)arg0->actorData)->color, &D_80800A50_chhotwaterpoolbits, D_80800A5C_chhotwaterpoolbits, func_800F10B4(arg0->unk58, 0.0f, 4.0f, 1.0f, 0.0f));
        ((struct WaterData *)arg0->actorData)->height = 0.0;
        break;
    case 3:
        func_800F2E60(((struct WaterData *)arg0->actorData)->color, D_80800A5C_chhotwaterpoolbits);
        ((struct WaterData *)arg0->actorData)->height = 0.0;
        ((struct WaterData *)arg0->actorData)->alpha = 100.0f;
        break;
    case 4:
        if (func_800D9078(&arg0->unk58)) {
            func_80101FDC(arg0, 3);
            func_80103110(arg0, 0);
        }
        height = func_800F12D4(arg0->unk58, 0.0f, 10.0f, -800.0f, 0.0f);
        ((struct WaterData *)arg0->actorData)->height = height;
        alpha = func_800F12D4(arg0->unk58, 0.0f, 10.0f, 100.0f, 127.0f);
        ((struct WaterData *)arg0->actorData)->alpha = alpha;
        func_800F2E60(((struct WaterData *)arg0->actorData)->color, D_80800A5C_chhotwaterpoolbits);
        break;
    case 5:
        func_800F2E60(((struct WaterData *)arg0->actorData)->color, D_80800A5C_chhotwaterpoolbits);
        ((struct WaterData *)arg0->actorData)->alpha = 100.0f;
        ((struct WaterData *)arg0->actorData)->height = -800.0f;
        func_800FFAB0(arg0);
        break;
    }
    func_80800528_chhotwaterpoolbits((s32 *)arg0);
}

s32 func_808003E0_chhotwaterpoolbits(Actor *arg0, s32 arg1, s32 arg2) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 func_800DA298(s32);
    void func_800F2E60(s32 *, s32 *);
    void func_800FFAB0(Actor *);
    void func_80101FDC(Actor *, u32);
    void func_80103110(Actor *, u32);
    void func_80800528_chhotwaterpoolbits(s32 *);
    extern s32 D_80800A5C_chhotwaterpoolbits[3];
    extern s32 D_80800A68_chhotwaterpoolbits;
    struct WaterData {
        f32 alpha;
        f32 height;
        s32 unused[2];
        s32 color[3];
    };

    switch (arg1) {
        case 0xA:
            if (arg2 == 0x3E7) {
                func_80101FDC(arg0, 2);
                func_80103110(arg0, 1);
                arg0->unk58 = 4.0f;
            } else {
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80800A68_chhotwaterpoolbits);
                func_80101FDC(arg0, 4);
                func_80103110(arg0, 1);
                arg0->unk58 = 10.0f;
            }
            break;
        case 0x95:
            if (func_800DA298(0x167)) {
                func_800F2E60(((struct WaterData *)arg0->actorData)->color, D_80800A5C_chhotwaterpoolbits);
                ((struct WaterData *)arg0->actorData)->alpha = 100.0f;
                ((struct WaterData *)arg0->actorData)->height = -800.0f;
                func_800FFAB0(arg0);
            } else if (func_800DA298(0x31B)) {
                func_800F2E60(((struct WaterData *)arg0->actorData)->color, D_80800A5C_chhotwaterpoolbits);
                ((struct WaterData *)arg0->actorData)->height = 0.0f;
                ((struct WaterData *)arg0->actorData)->alpha = 100.0f;
                func_80101FDC(arg0, 3);
            }
            func_80800528_chhotwaterpoolbits((s32 *)arg0);
            return 1;
        default:
            return 0;
    }
    return 1;
}

void func_80800528_chhotwaterpoolbits(s32 *arg0) {
    s32 _glid_entrypoint_0(s32, s32, s32 *, s32);
    s32 func_800BEA88(s32);
#ifdef BT_NATIVE
    void chhotwaterpoolbits_entrypoint_4(s32 arg0, Vtx *arg1, Vtx *arg2, s32 arg3, Unk80132ED0 *arg4);
#else
    extern s32 _chhotwaterpoolbits_entrypoint_4;
#endif
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

void func_80800718_chhotwaterpoolbits(Actor *arg0) {
    void chhotwaterpoolbits_entrypoint_5(Actor *, f32);
    s32 func_800D9078(f32 *);
    void func_800EE7F8(f32 *, f32 *);
    u32 func_800F54E4(void);
    s32 func_800F5578(s32);
    s32 func_800F55FC(s32);
    f32 func_800F5628(s32);
    void func_800F5A00(s32, f32 *);
    s32 func_800F5C94(s32);
    s32 func_800F5D18(s32);
    s32 func_800F64A4(s32, s32);
    s32 func_800F6A38(s32);
    void func_800F7D90(s32, s32, void *, s32);
    void func_80101FDC(Actor *, u32);
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    s32 temp;
    f32 sp24[3];

    switch (arg0->unk70_10) {
    case 1:
        sp3C = func_800F54E4();
        if (func_800F6A38(sp3C)) {
            sp38 = func_800F5C94(sp3C);
            sp34 = func_800F5D18(sp3C);
            temp = func_800F64A4(sp3C, 2);
            if (sp38 != 0xC && sp38 != 0xE &&
                (sp34 != 0 || temp != 0) && func_800D9078(&arg0->unk58)) {
                func_800F7D90(sp3C, 0x52, arg0->actorData, 1);
                func_80101FDC(arg0, 2);
                chhotwaterpoolbits_entrypoint_5(arg0, 1.0f);
                arg0->unk58 = 1.0f;
            }
        } else {
            func_800F5A00(sp3C, sp24);
            sp24[1] = func_800F5628(sp3C);
            if (func_800F55FC(sp3C) & 0x08000000) {
                func_800EE7F8((f32 *)arg0->actorData, sp24);
            }
            arg0->unk58 = 0.04f;
        }
        break;
    case 2:
        if (func_800D9078(&arg0->unk58) &&
            func_800F5578(func_800F54E4()) > 0) {
            func_80101FDC(arg0, 1);
            arg0->unk58 = 0.04f;
        }
        break;
    }
}

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
