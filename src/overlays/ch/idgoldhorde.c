#include "common.h"

OSThread *chidgoldhorde_entrypoint_0(void)
{
    extern u8 D_808001F0_chidgoldhorde[];

    return (OSThread *) D_808001F0_chidgoldhorde;
}

/* extern */

void func_8080000C_chidgoldhorde(Actor *arg0) {
    s16 _glidmake_entrypoint_3(s32, s16);
    s32 func_800BEA88(s32);
    void *func_80100094(Actor *, u32);
    struct {
        s16 unk0;
        s16 unk2;
        s32 unk4;
        f32 unk8;
    } *sp24;
    s32 pad[2];

    sp24 = func_80100094(arg0, 0);
    sp24->unk2 = _glidmake_entrypoint_3(func_800BEA88(0),
        (sp24->unk0 = arg0->unk74_7, sp24->unk0));
    sp24->unk8 = arg0->rotation[1] * 0.0027777778f;
    arg0->unk64_16 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/idgoldhorde/chidgoldhorde_entrypoint_1.s")

void func_8080015C_chidgoldhorde(Actor *arg0) {
    s32 _glid_entrypoint_3(s32, s16, s32 *, Unk80132ED0 *);
    s32 func_800BEA88(s32);
    f32 func_800DC0C0(void);
    s32 func_800DC128(s32, s32);
    void *func_80100094(Actor *, u32);
    extern s32 _chidgoldhorde_entrypoint_1;
    struct {
        s16 unk0;
        s16 unk2;
        s16 unk4;
        s16 unk6;
        f32 unk8;
    } *temp_s0;
    s32 sp20;

    temp_s0 = func_80100094(arg0, 0);
    if (func_800DC0C0() < temp_s0->unk8) {
        sp20 = func_800BEA88(0);
        temp_s0->unk4 = 0;
        temp_s0->unk6 = func_800DC128(0, temp_s0->unk2);
        _glid_entrypoint_3(sp20, temp_s0->unk0, &_chidgoldhorde_entrypoint_1, arg0->unk0);
    }
}
