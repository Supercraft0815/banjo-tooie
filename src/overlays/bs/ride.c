#include "common.h"
struct player_state_s;
void func_80093230(struct player_state_s *, f32);

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ride/func_80800000_bsride.s")

void func_8080008C_bsride(struct player_state_s *arg0) {
    void func_800947EC(struct player_state_s *, s32, s32);
    void func_800A34E4(void *, s32);
    void func_800961AC(struct player_state_s *, s32);
    void baroll_setIdeal(struct player_state_s *, f32);
    void func_8009BF5C(struct player_state_s *, f32);
    *(s32 *)((u8 *)arg0 + 0x15C) = 0;
    func_800947EC(arg0, 1, 0);
    func_800A34E4(arg0, 1);
    func_800961AC(arg0, 1);
    baroll_setIdeal(arg0, 0.0f);
    func_8009BF5C(arg0, 0.0f);
}

s32 func_808000F0_bsride(s32 arg0) { func_8009EAE8(0); func_8080008C_bsride(arg0); }

/* extern */

void func_8080011C_bsride(s32 arg0) {
    s32 func_80099B94(s32);
    s32 func_8009E6EC();
    s32 func_8009E830(s32, s32);
    s32 func_808000F0_bsride(s32);
    if (func_8009E6EC() == 0x28) {
        func_808000F0_bsride(arg0);
        func_8009E830(arg0, 2);
        return;
    }
    func_80099B94(arg0);
}

void func_8080016C_bsride()
{
    void func_8080008C_bsride();
    func_8080008C_bsride();
}

/* extern */

void func_8080018C_bsride(s32 arg0) {
    s32 baanim_playForDuration_loopSmooth(s32, s32, s32);
    s32 func_8009C128(s32, s32);
    s32 func_80800000_bsride();
    func_80800000_bsride();
    baanim_playForDuration_loopSmooth(arg0, 0x256, 0x3F666666);
    func_8009C128(arg0, arg0 + 0x16C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ride/func_808001CC_bsride.s")

s32 bsride_entrypoint_0(s32 arg0) {
    extern s32 D_808009C0_bsride[];
    return ((s32 *)&D_808009C0_bsride)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ride/func_808002A0_bsride.s")

void func_808004AC_bsride(struct player_state_s *arg0) {
    func_80093230(arg0, 1.0f);
    func_8080008C_bsride(arg0);
}

/* extern */

void func_808004D8_bsride(struct player_state_s *arg0) {
    s32 baanim_playForDuration_loopSmooth(s32, s32, s32);
    s32 func_80800000_bsride();
    func_80800000_bsride();
    baanim_playForDuration_loopSmooth(arg0, 0x281, 0x3F333333);
    func_80093230(arg0, 1.35f);
    (*(s32 *)((s8 *)(arg0) + (0x160))) = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ride/func_80800524_bsride.s")

s32 bsride_entrypoint_1(s32 arg0) {
    extern s32 D_80800A70_bsride[];
    return ((s32 *)&D_80800A70_bsride)[arg0];
}

void func_808005B8_bsride()
{
    void func_8080008C_bsride();
    func_8080008C_bsride();
}

/* extern */

void func_808005D8_bsride(s32 arg0) {
    s32 baanim_playForDuration_loopSmooth(s32, s32, s32);
    s32 func_80800000_bsride();
    func_80800000_bsride();
    baanim_playForDuration_loopSmooth(arg0, 0x83, 0x3FE66666);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ride/func_8080060C_bsride.s")

/* extern */

void func_8080066C_bsride(s32 arg0) {
    s32 func_80099B94(s32);
    s32 func_8009E6EC();
    s32 func_8009E830(s32, s32);
    s32 func_808000F0_bsride(s32);
    if (func_8009E6EC() == 0x28) {
        func_808000F0_bsride(arg0);
        func_8009E830(arg0, 2);
        return;
    }
    func_80099B94(arg0);
}

s32 bsride_entrypoint_2(s32 arg0) {
    extern s32 D_80800A80_bsride[];
    return ((s32 *)&D_80800A80_bsride)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ride/func_808006D0_bsride.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ride/func_80800798_bsride.s")

void func_8080084C_bsride(s32 arg0)
{
    func_808006D0_bsride(arg0,0);
    func_8080008C_bsride(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ride/func_80800878_bsride.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ride/func_80800904_bsride.s")

s32 bsride_entrypoint_3(s32 arg0) {
    extern s32 D_80800A90_bsride[];
    return ((s32 *)&D_80800A90_bsride)[arg0];
}
