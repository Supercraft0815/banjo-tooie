#include "common.h"

OSThread *chjujubagfx_entrypoint_0(void)
{
    extern u8 D_80800470_chjujubagfx[];

    return (OSThread *) D_80800470_chjujubagfx;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jujubagfx/func_8080000C_chjujubagfx.s")

/* extern */

void func_80800100_chjujubagfx(u8 *arg0) {
    s32 *_subaddiefind_entrypoint_0(s32, s32, s32, s32);
    s32 func_8008FE94(s32, u8 *);
    s32 func_8010D278();
    s32 func_8080000C_chjujubagfx(u8 *, s32);
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
