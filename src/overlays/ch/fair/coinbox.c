#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fair/coinbox/func_80800000_chfaircoinbox.s")

void func_8080001C_chfaircoinbox(u8 *arg0) {
    struct CoinboxData { u8 pad[0x76]; unsigned short index : 9; unsigned short rest : 7; };
    s32 func_800DA544(s32);
    extern s32 func_808002E4_chfaircoinbox[][2];
    func_800DA544(func_808002E4_chfaircoinbox[((struct CoinboxData *)arg0)->index][0]);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fair/coinbox/func_80800050_chfaircoinbox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fair/coinbox/func_808000A4_chfaircoinbox.s")

void func_8080016C_chfaircoinbox(s32 arg0) 
{
}
/* extern */

void func_80800174_chfaircoinbox(s32 arg0) {
    s32 func_800DA298(s32);
    s32 func_8010A63C();
    s32 func_80800050_chfaircoinbox(s32);
    s32 func_808000A4_chfaircoinbox(s32, s32);
    func_8010A63C();
    if (func_800DA298(func_80800050_chfaircoinbox(arg0)) != 0) {
        func_808000A4_chfaircoinbox(arg0, 4);
        return;
    }
    func_808000A4_chfaircoinbox(arg0, 1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fair/coinbox/func_808001C8_chfaircoinbox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fair/coinbox/func_80800264_chfaircoinbox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fair/coinbox/func_808002CC_chfaircoinbox.s")

/* extern */

s32 chfaircoinbox_entrypoint_0(Unk80132ED0 *arg0, f32 *arg1) {
    s32 func_800EE7F8(s32, s32);
    Actor *func_80106790(Unk80132ED0 *);
    func_800EE7F8((s32) arg1, (s32) ((u8 *) func_80106790(arg0) + 4));
    return 1;
}

/* extern */
void chfaircoinbox_entrypoint_1(Unk80132ED0 *arg0) {
    Actor *func_80106790(Unk80132ED0 *);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    Actor *actor;

    actor = func_80106790(arg0);
    _subaddiedialog_entrypoint_11((Unk80132ED0 *) actor->unk0, 0x10B8, 4, (f32 *) ((u8 *) actor + 4), 0x8C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fair/coinbox/func_808003C4_chfaircoinbox.s")

OSThread *chfaircoinbox_entrypoint_2(void)
{
    extern u8 D_808004C8_chfaircoinbox[];

    return (OSThread *) D_808004C8_chfaircoinbox;
}
