#include "common.h"

void func_80102424(Actor *, s32);

void func_80800000_chfriendlystonehead(s32 arg0)
{
    func_80102424(arg0,1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/friendlystonehead/func_80800020_chfriendlystonehead.s")

/* extern */

void func_80800160_chfriendlystonehead(void **arg0, s32 arg1) {
    s32 func_800DF744(s32, u32);
    s32 func_80101870(void **, s32);
    func_800DF744(3, (u32) ((*(s32 *)((s8 *)(*arg0) + (0x28))) << 0x12) >> 0x1F);
    func_80101870(arg0, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/friendlystonehead/func_808001A8_chfriendlystonehead.s")

void func_80800238_chfriendlystonehead(Actor *arg0) {
    struct { u8 pad[0x28]; u32 : 18; u32 flag : 1; u32 : 13; } *flags;
    if (func_8010C9B0((f32 *) ((s8 *) arg0 + 4), 0x1F4) != 0) {
        func_80102424(arg0, 2);
        flags = (void *) arg0->unk0;
        flags->flag = 1;
    }
}

void func_80800284_chfriendlystonehead(Actor *arg0) {
    if (func_8010C9B0((f32 *) ((s8 *) arg0 + 4), 0x1F4) == 0) {
        func_80102424(arg0, 5);
    }
}

/* extern */

void func_808002BC_chfriendlystonehead(void *arg0) {
    s32 func_80102BF8(void *, s32, s32, s32);
    f32 func_8010CD28();
    (*(f32 *)((s8 *)(arg0) + (0x54))) = func_8010CD28();
    func_80102BF8(arg0, 0x3DCCCCCD, 0x40800000, 0x42F00000);
}

/* extern */

void func_808002F8_chfriendlystonehead(void) {
    s32 func_800DA524(s32);
    func_800DA524(0x425);
    func_800DA524(0x426);
    func_800DA524(0x427);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/friendlystonehead/func_80800328_chfriendlystonehead.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/friendlystonehead/func_80800444_chfriendlystonehead.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/friendlystonehead/func_80800540_chfriendlystonehead.s")

/* extern */

void func_80800680_chfriendlystonehead(s32 *arg0, s32 arg1) {
    s32 _capod_entrypoint_13(s32, s32, s32, s32);
    s32 func_800C01A8(s32, s32);
    func_800C01A8(0x6B, 0);
    _capod_entrypoint_13(*arg0, 0, arg1, 0x2010);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/friendlystonehead/func_808006C4_chfriendlystonehead.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/friendlystonehead/func_80800830_chfriendlystonehead.s")

OSThread *chfriendlystonehead_entrypoint_0(void)
{
    extern u8 D_808009B4_chfriendlystonehead[];

    return (OSThread *) D_808009B4_chfriendlystonehead;
}
