#include "common.h"

OSThread *chtalontorpedoboulder_entrypoint_0(void)
{
    extern u8 D_808002B4_chtalontorpedoboulder[];

    return (OSThread *) D_808002B4_chtalontorpedoboulder;
}

/* extern */

void func_8080000C_chtalontorpedoboulder(Actor *arg0) {
    s32 func_800DA298(s32);
    void func_800FFAB0(Actor *);
    void func_80102FDC(Actor *, f32);
    s32 func_808001CC_chtalontorpedoboulder(u8 *);
    s32 temp_v0;

    temp_v0 = func_808001CC_chtalontorpedoboulder((u8 *)arg0);
    if ((temp_v0 != 0) && (func_800DA298(temp_v0) != 0)) {
        func_800FFAB0(arg0);
        return;
    }
    func_80102FDC(arg0, 2.0f * arg0->scale);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/talontorpedoboulder/func_80800070_chtalontorpedoboulder.s")

/* extern */

void func_80800194_chtalontorpedoboulder(s32 arg0, s32 arg1) {
    s32 func_800DF744(s32, s32);
    s32 func_80101870(s32, s32);
    func_800DF744(2, 1);
    func_80101870(arg0, arg1);
}

s32 func_808001CC_chtalontorpedoboulder(u8 *arg0) {
    s32 temp_v1;

    temp_v1 = ((u32) *(u16 *)(arg0 + 0x76) >> 7) - 0x32;
    if ((temp_v1 < 0) || (temp_v1 >= 5)) {
        return 0;
    }
    return temp_v1 + 0x3EF;
}

int func_808001F8_chtalontorpedoboulder(void *arg0) {
    extern s16 D_80800314_chtalontorpedoboulder[][2];
    extern s16 D_80800318_chtalontorpedoboulder[][2];
    int index = 0;
    int temp_v1;

    temp_v1 = ((u32)*(u16 *)((u8 *)arg0 + 0x76) >> 7) - 0x32;
loop_1:
    if (temp_v1 == D_80800314_chtalontorpedoboulder[index][0]) {
        return D_80800314_chtalontorpedoboulder[index][1];
    }
    index++;
    if (D_80800318_chtalontorpedoboulder != &D_80800314_chtalontorpedoboulder[index]) {
        goto loop_1;
    }
    return -1;
}
