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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/idgoldhorde/func_8080015C_chidgoldhorde.s")
