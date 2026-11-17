#include "common.h"

OSThread *chjujubagfx_entrypoint_0(void)
{
    extern ActorData D_80800470_chjujubagfx[];

    return (OSThread *) D_80800470_chjujubagfx;
}

void *func_80100094(Actor *, u32);
void func_80101FDC(Actor *, u32);
void func_800DA524(s32);     

void func_8080000C_chjujubagfx(Actor *arg0, s32 arg1) {
    void _sumumbofx_entrypoint_0(Actor *arg0, u32 arg1, s32 arg2, s16 arg3);
    void _sumumbofx_entrypoint_2(void *);
    void _sumumbofx_entrypoint_24(void *, f32);
    void _sumumbofx_entrypoint_4(void *);
    void _sumumbofx_entrypoint_3(void *, f32);
    void _sumumbofx_entrypoint_15(void *, f32);
    void _sumumbofx_entrypoint_23(void *, f32);
    void _sumumbofx_entrypoint_19(void *, s32);
    void _sumumbofx_entrypoint_16(void *, f32);
    void *data;

    func_80101FDC(arg0, arg1);
    switch (arg1) {
        case 2:
            _sumumbofx_entrypoint_0(arg0, 1, 10, 0x9E4);
            data = func_80100094(arg0, 1);
            _sumumbofx_entrypoint_2(data);
            _sumumbofx_entrypoint_24(data, 0.15f);
            _sumumbofx_entrypoint_4(data);
            _sumumbofx_entrypoint_3(data, 360.0f);
            _sumumbofx_entrypoint_15(data, 0.5f);
            _sumumbofx_entrypoint_23(data, 0.0f);
            _sumumbofx_entrypoint_19(data, 0);
            break;
        case 4:
            func_800DA524(0x9F3);
            _sumumbofx_entrypoint_16(func_80100094(arg0, 1), 0.5f);
            arg0->unk64_20 = 1;
            break;
    }
}                 typedef struct { u8 pad0[0x3C]; s32 unk3C; u8 pad40[0x25]; u8 unk65; } Objjujubagfx_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void func_80800100_chjujubagfx(u8 *arg0) {
    s32 *_subaddiefind_entrypoint_0(BtIntPtr, s32, s32, s32);
    void func_8008FE94(s32 arg0,f32* arg1);
    s32 func_8010D278();
    void func_8080000C_chjujubagfx(Actor *, s32);
    if (func_8010D278() != 0xD) {
        (((Objjujubagfx_arg0 *)arg0)->unk3C) = (s32) *_subaddiefind_entrypoint_0(arg0 + 4, 0x190, -1, 0);
    } else {
        func_8008FE94(1, arg0 + 4);
    }
    (((Objjujubagfx_arg0 *)arg0)->unk65) = (u8) ((((Objjujubagfx_arg0 *)arg0)->unk65) & 0xFFEF);
    func_8080000C_chjujubagfx(arg0, 2);
}

/* extern */

void func_80800174_chjujubagfx(Actor *arg0) {
    void _sumumbofx_entrypoint_1(Actor *arg0, u32 arg1);
    if (func_80100094(arg0, 1U) != NULL) {
        _sumumbofx_entrypoint_1(arg0, 1);
    }
}
typedef struct { f32 v[3]; } Vec3;
void func_808001A8_chjujubagfx(Actor *arg0) {
    void _sumumbofx_entrypoint_14(u8 *arg0);
    void _sumumbofx_entrypoint_17(void *, f32);
    f32 _sumumbofx_entrypoint_21(void *);
    f32 _sumumbofx_entrypoint_22(u8 *);
    void _sumumbofx_entrypoint_7(u8 *arg0, f32 arg1, s32 arg2, s32 arg3, f32 *arg4, f32 *arg5, f32 *arg6);
    void _chnewmumbo_entrypoint_0(Actor *, f32 *);
    s32 func_800DA298(s32);
    Actor *func_80106790(Unk80132ED0 *);
    void func_8008FE94(s32 arg0,f32* arg1);
    void func_800FFAB0(Actor *);
    s32 func_8010D278();

    extern Vec3 D_808004B8_chjujubagfx;
    extern Vec3 D_808004C4_chjujubagfx;
    Vec3 sp4C = D_808004B8_chjujubagfx;
    Vec3 sp40 = D_808004C4_chjujubagfx;
    void *sp3C;
    s32 pad;

    sp3C = func_80100094(arg0, 1U);
    if (func_800DA298(0x9F3)) {
        func_8080000C_chjujubagfx(arg0, 4);
    }
    if (!arg0->unk64_20) {
        if (func_8010D278() != 0xD) {
            if (arg0->unk3C != NULL) {
                _chnewmumbo_entrypoint_0(func_80106790(arg0->unk3C), arg0->position);
            }
        } else {
            func_8008FE94(1, arg0->position);
        }
    }
    switch (arg0->unk70_10) {
        case 2:
            _sumumbofx_entrypoint_14(sp3C);
            _sumumbofx_entrypoint_7(sp3C, 28.0f, 0, 10, arg0->position, sp40.v, sp4C.v);
            if (_sumumbofx_entrypoint_21(sp3C) == 0.0f) {
                _sumumbofx_entrypoint_17(sp3C, 10.0f);
                func_8080000C_chjujubagfx(arg0, 3);
            }
            break;
        case 3:
            _sumumbofx_entrypoint_14(sp3C);
            _sumumbofx_entrypoint_7(sp3C, 28.0f, 0, 10, arg0->position, sp40.v, sp4C.v);
            break;
        case 4:
            _sumumbofx_entrypoint_14(sp3C);
            _sumumbofx_entrypoint_7(sp3C, 28.0f, 0, 10, arg0->position, sp40.v, sp4C.v);
            if (_sumumbofx_entrypoint_22(sp3C) < 0.05f) {
                func_800FFAB0(arg0);
            }
            break;
    }
}

void func_808003D4_chjujubagfx(Actor *arg0, s32 arg1) { void _sumumbofx_entrypoint_8(u8 *arg0, BtIntPtr arg1); _sumumbofx_entrypoint_8(func_80100094(arg0, 1U), arg1); }

void chjujubagfx_entrypoint_1(void) {
    Actor *func_80108474(u32 arg0, f32 *arg1, s32 arg2);
    void func_8010D254(f32*);
    f32 sp1C[3];

    func_8010D254(sp1C);
    func_80108474(0x2F9U, sp1C, 0);
}

void chjujubagfx_entrypoint_2(void) {
    s32 _chbaddiesetup_entrypoint_0(s32 *);
#ifndef BT_NATIVE
    extern s32 _chjujubagfx_entrypoint_1;
#endif
    _chbaddiesetup_entrypoint_0(&_chjujubagfx_entrypoint_1);
}
/* data_to_c.py: from asm/data/overlays/ch/jujubagfx.data.s */
void func_80105834(Actor*);
void func_80107C2C();
ActorData D_80800470_chjujubagfx [1] BT_DATA(4, overlays_ch_jujubagfx, 0x0) = { { 702, 761, 1599, 1, 0, (void (*)(struct Actor *))func_808001A8_chjujubagfx, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_808003D4_chjujubagfx, 327680000, 0, 0, 0, 0, 4, (void (*)(struct Actor *))func_80800174_chjujubagfx, 0, 0, 0, (void (*)(struct Actor *))func_80800100_chjujubagfx, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 2, 0, 0 } };
Vec3 D_808004B8_chjujubagfx BT_DATA(4, overlays_ch_jujubagfx, 0x48) = { { 0.0f, 0.0f, 0.0f } };
Vec3 D_808004C4_chjujubagfx BT_DATA(4, overlays_ch_jujubagfx, 0x54) = { { 0.0f, -14.0f, 0.0f } };
