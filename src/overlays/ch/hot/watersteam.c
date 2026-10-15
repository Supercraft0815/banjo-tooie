#include "common.h"

OSThread *chhotwatersteam_entrypoint_0(void)
{
    extern u8 D_80800240_chhotwatersteam[];

    return (OSThread *) D_80800240_chhotwatersteam;
}

/* extern */

void func_8080000C_chhotwatersteam(s32 *arg0) {
    s32 func_800FFA88(s32);
    s32 func_808001E8_chhotwatersteam();
    if (func_808001E8_chhotwatersteam() == 0) {
        func_800FFA88(*arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hot/watersteam/func_8080003C_chhotwatersteam.s")

s32 func_808000C4_chhotwatersteam(s32 arg0, s32 arg1, s32 arg2) 
{
    return 0;
}
/* extern */

void func_808000D8_chhotwatersteam(Actor *arg0) {
    struct SteamActorFlags {
        u8 pad0[0x70];
        u32 index : 7;
        u32 pad70 : 25;
    };
    s32 func_800CD08C(s32, u8 *);
    f32 func_800DC178(f32, f32);
    void func_80101FDC(Actor *, u32);
    s32 func_8080014C_chhotwatersteam(Actor *, f32 *);
    f32 sp24[3];

    func_800CD08C(((struct SteamActorFlags *)arg0)->index - 1, (u8 *)sp24);
    sp24[1] = arg0->position[1];
    if (func_8080014C_chhotwatersteam(arg0, sp24) != 0) {
        func_80101FDC(arg0, 2);
        arg0->unk58 = func_800DC178(0.3f, 0.4f);
    }
}

s32 func_8080014C_chhotwatersteam(Actor *arg0, f32 *arg1) {
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    s32 func_800E3E8C(f32 *, f32);
    void func_800EE7F8(f32 *, f32 *);
    extern s32 D_80800288_chhotwatersteam;
    f32 sp2C[3];
    f32 sp20[3];

    if (func_800E3E8C(arg1, 500.0f) != 0) {
        func_800EE7F8(sp2C, arg1);
        sp2C[1] -= 400.0f;
        func_800EE7F8(sp20, arg1);
        sp20[1] -= 20.0f;
        func_800BBCB8(sp20, sp2C, 1.0f, 1, &D_80800288_chhotwatersteam);
        return 1;
    }
    return 0;
}

/* extern */

s32 func_808001E8_chhotwatersteam(void *arg0) {
    s32 func_800DA298(s32);
    if (((u32)*(u16 *)((u8 *)arg0 + 0x76) >> 7) == 0x33) {
        return func_800DA298(0x31B) == 0;
    } else {
        return 1;
    }
}
