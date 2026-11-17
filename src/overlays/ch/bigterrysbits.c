#include "common.h"

OSThread *chbigterrysbits_entrypoint_0(void)
{
    extern ActorData D_80800380_chbigterrysbits[];

    return (OSThread *) D_80800380_chbigterrysbits;
}

OSThread *chbigterrysbits_entrypoint_1(void)
{
    extern ActorData D_808003C8_chbigterrysbits[];

    return (OSThread *) D_808003C8_chbigterrysbits;
}

OSThread *chbigterrysbits_entrypoint_2(void)
{
    extern ActorData D_80800410_chbigterrysbits[];

    return (OSThread *) D_80800410_chbigterrysbits;
}    typedef struct { u8 pad0[0x44]; f32 unk44; } Objbigterrysbits_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void func_80800024_chbigterrysbits(void *arg0) {
    s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_5(Actor *, f32);
    void _chdoormake_entrypoint_6(Actor *, s32);
    s32 _chdoormake_entrypoint_8(void *, s32);
    s32 _glcutDll_entrypoint_20();
    s32 func_800D395C();
    s32 func_800DA298(s32);
    BtIntPtr func_800F54E4();
    s32 func_800F64A4(BtIntPtr, s32);
    s32 func_8010108C(void *, s32, BtIntPtr);
    void func_80101FDC(Actor *, u32);
    void func_8010A800(Actor *, s32);
    s32 sp2C;
    s32 sp28;

    sp2C = func_800D395C();
    sp28 = func_800DA298(0x172);
    if ((func_800F64A4(func_800F54E4(), 0x1000) != 0) || (_glcutDll_entrypoint_20() != 0)) {
        func_80101FDC(arg0, 1);
    }
    (((Objbigterrysbits_arg0 *)arg0)->unk44) = -50.0f;
    func_8010A800(arg0, 0);
    if (_chdoormake_entrypoint_3(arg0, 0.0f, (((Objbigterrysbits_arg0 *)arg0)->unk44) + 90.0f, -400.0f, 0x802, -1) != 0) {
        _chdoormake_entrypoint_5(arg0, 3.0f);
        _chdoormake_entrypoint_6(arg0, 0x3F4CCCCD);
        _chdoormake_entrypoint_8(arg0, 0xE);
    }
    if ((_glcutDll_entrypoint_20() == 0) && (sp2C != 0) && (sp28 == 0)) {
        func_8010108C(arg0, 8, 0);
    }
}

/* extern */

void func_80800130_chbigterrysbits(BtIntPtr arg0) {
    s32 _glcutDll_entrypoint_20();
    void func_800FFAB0(Actor *);
    if (_glcutDll_entrypoint_20() != 0) {
        func_800FFAB0(arg0);
    }
}

/* extern */

void func_80800160_chbigterrysbits(Actor *arg0) {
    s32 _subaddieDll_entrypoint_6(Actor*, s32);
    void func_8080022C_chbigterrysbits(Actor *volatile);
    if (((((u32) (*(u16 *)((s8 *)(arg0) + (0x72)))) >> 0xA) == 2) && (_subaddieDll_entrypoint_6(arg0, 0xB) != 0)) {
        func_8080022C_chbigterrysbits(arg0);
    }
}

s32 func_808001A8_chbigterrysbits(Actor *arg0, s32 arg1, BtIntPtr arg2) {
    s32 _subaddieDll_entrypoint_5(Actor *arg0, Unk80132ED0 *arg1);
    void func_80103110(void *, s32);
    void func_80101FDC(Actor *, u32);
    void func_8080022C_chbigterrysbits(Actor *volatile);
    s32 *data = &arg2;
    switch (arg1) {
        case 0x3F:
            if (_subaddieDll_entrypoint_5(arg0, arg2) != 0) {
                func_80103110(arg0, 1);
                func_80101FDC(arg0, 2);
                return 1;
            }
            break;
        case 0x40:
            func_8080022C_chbigterrysbits(arg0);
            return 1;
        default:
            return 0;
    }
    return 1;
}

void func_8080022C_chbigterrysbits(Actor *volatile arg0) {
    void _chexploder_entrypoint_3(void *, void *, u32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_800DA544(s32);
    void func_800EE7F8(f32 *, f32 *);
    extern s32 D_80800458_chbigterrysbits[6];
    f32 sp1C[3];
    f32 *sp18;

    sp18 = arg0->position;
    func_800EE7F8(sp1C, sp18);
    sp1C[1] -= 80.0f;
    _chexploder_entrypoint_3(arg0, sp1C, 0xC);
    _subaddieaudioquick_entrypoint_2(arg0, sp18, D_80800458_chbigterrysbits);
    func_800DA544(0x173);
}

void func_8080029C_chbigterrysbits(Actor *arg0) {
    s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_5(Actor *, f32);
    void _chdoormake_entrypoint_6(Actor *, s32);
    s32 _glcutDll_entrypoint_20();
    s32 func_800D395C(void);
    s32 func_800DA298(s32);
    void func_800FFAB0(Actor *);
    void func_80101FDC(Actor *, u32);
    void func_8010A800(Actor *, s32);
    s32 sp2C;
    s32 sp28;

    sp2C = func_800DA298(0xE5);
    sp28 = func_800D395C();
    if (_glcutDll_entrypoint_20() != 0) {
        func_800FFAB0(arg0);
        return;
    }
    if (sp2C != 0 && sp28 == 0) {
        func_80101FDC(arg0, 4);
    }
    arg0->rotation[0] = -90.0f;
    func_8010A800(arg0, 0);
    if (_chdoormake_entrypoint_3(arg0, arg0->rotation[1], arg0->rotation[0] + 90.0f, -400.0f, 3, -1) != 0) {
        _chdoormake_entrypoint_5(arg0, 3.0f);
        _chdoormake_entrypoint_6(arg0, 0x3F4CCCCD);
    }
}
/* data_to_c.py: from asm/data/overlays/ch/bigterrysbits.data.s */
void _chdoor_entrypoint_0();
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
s32 _chdoor_entrypoint_1(Actor *arg0, s32 arg1, BtIntPtr arg2);
OSThread *func_80108ED0(void);
ActorData D_80800380_chbigterrysbits [1] BT_DATA(4, overlays_ch_bigterrysbits, 0x0) = { { 172, 1121, 1988, 4, 0, (void (*)(struct Actor *))_chdoor_entrypoint_0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 29999, 0, 0, 0, 0, 1024, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800024_chbigterrysbits, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 11266, (void (*)(struct Actor *, long, long))_chdoor_entrypoint_1, 0 } };
ActorData D_808003C8_chbigterrysbits [1] BT_DATA(4, overlays_ch_bigterrysbits, 0x48) = { { 767, 869, 1875, 1, 0, (void (*)(struct Actor *))func_80800160_chbigterrysbits, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 29999, 0, 371, 0, 0, 3072, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_80800130_chbigterrysbits, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 11264, (void (*)(struct Actor *, long, long))func_808001A8_chbigterrysbits, 0 } };
ActorData D_80800410_chbigterrysbits [1] BT_DATA(4, overlays_ch_bigterrysbits, 0x90) = { { 172, 1129, 1988, 1, 0, (void (*)(struct Actor *))_chdoor_entrypoint_0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 29999, 0, 0, 0, 0, 3072, 0, 0, 0, 0, (void (*)(struct Actor *))func_8080029C_chbigterrysbits, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 11266, (void (*)(struct Actor *, long, long))_chdoor_entrypoint_1, 0 } };
s32 D_80800458_chbigterrysbits[6] BT_DATA(4, overlays_ch_bigterrysbits, 0xD8) = { 1246452, 655564, 1469792, 66786, 524288000, 0 };
