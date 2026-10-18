#include "common.h"

OSThread *chjujubagfx_entrypoint_0(void)
{
    extern u8 D_80800470_chjujubagfx[];

    return (OSThread *) D_80800470_chjujubagfx;
}

void *func_80100094(Actor *, u32);
void func_80101FDC(Actor *, u32);
void func_800DA524(s32);

void func_8080000C_chjujubagfx(Actor *arg0, s32 arg1) {
    s32 _sumumbofx_entrypoint_0(Actor *, s32, s32, s16);
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
}

/* extern */

void func_80800100_chjujubagfx(u8 *arg0) {
    s32 *_subaddiefind_entrypoint_0(s32, s32, s32, s32);
    s32 func_8008FE94(s32, u8 *);
    s32 func_8010D278();
    void func_8080000C_chjujubagfx(Actor *, s32);
    if (func_8010D278() != 0xD) {
        (*(s32 *)((s8 *)(arg0) + (0x3C))) = (s32) *_subaddiefind_entrypoint_0(arg0 + 4, 0x190, -1, 0);
    } else {
        func_8008FE94(1, arg0 + 4);
    }
    (*(u8 *)((s8 *)(arg0) + (0x65))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x65))) & 0xFFEF);
    func_8080000C_chjujubagfx(arg0, 2);
}

/* extern */

void func_80800174_chjujubagfx(Actor *arg0) {
    s32 _sumumbofx_entrypoint_1(Actor *, s32);
    if (func_80100094(arg0, 1U) != NULL) {
        _sumumbofx_entrypoint_1(arg0, 1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jujubagfx/func_808001A8_chjujubagfx.s")

void func_808003D4_chjujubagfx(Actor *arg0, s32 arg1) { void *_sumumbofx_entrypoint_8(u8 *, s32); _sumumbofx_entrypoint_8(func_80100094(arg0, 1U), arg1); }

void chjujubagfx_entrypoint_1(void) {
    void func_80108474(u32, f32*, s32);
    void func_8010D254(f32*);
    f32 sp1C[3];

    func_8010D254(sp1C);
    func_80108474(0x2F9U, sp1C, 0);
}

void chjujubagfx_entrypoint_2(void) {
    s32 _chbaddiesetup_entrypoint_0(s32 *);
    extern s32 _chjujubagfx_entrypoint_1;
    _chbaddiesetup_entrypoint_0(&_chjujubagfx_entrypoint_1);
}
