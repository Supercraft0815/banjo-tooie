#include "common.h"

OSThread *chcheatopage_entrypoint_0(void)
{
    extern u8 D_80800330_chcheatopage[];

    return (OSThread *) D_80800330_chcheatopage;
}

/* extern */
void func_8080000C_chcheatopage(Actor *arg0) { s32 func_80103110(void *, s32); func_80103110(arg0, 0); func_8010A5B0(arg0, func_800DA298(0x666) == 0); if (arg0->unk64_20) { func_800FC660(0x77); arg0->unk64_20 = 0; } }

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eatopage/func_80800070_chcheatopage.s")

/* extern */

s32 func_80800124_chcheatopage(Actor *arg0, s32 arg1, s32 arg2) {
    void func_80800194_chcheatopage(Actor *, s32);
    switch (arg1) {
        case 0x3E:
            func_80800194_chcheatopage(arg0, arg2);
            return 1;
        case 0x13:
            *(s32 *)&arg0->unk50 = *(s32 *)&arg2;
            break;
        case 0x14:
            arg0->unk64_20 = 1;
            break;
        default:
            return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/eatopage/func_80800194_chcheatopage.s")

/* extern */

void func_808002A0_chcheatopage(void *arg0) {
    s32 func_80101870();
    s32 func_80103110(void *, s32);
    func_80101870();
    if ((((struct { unsigned int : 19; unsigned int active : 1; unsigned int : 12; } *)((s8 *)arg0 + 0x7C))->active) && (((u32) (*(u16 *)((s8 *)(arg0) + (0x72))) >> 0xA) == 1)) {
        func_80103110(arg0, 1);
    }
}

int func_808002F0_chcheatopage(Actor *arg0) {
    extern u8 D_80800378_chcheatopage[1];
    s32 index;
    for (index = 0; index < sizeof(D_80800378_chcheatopage); index++) {
        if (D_80800378_chcheatopage[index] == *(u32 *)&arg0->unk50) return 1;
    }
    return 0;
}
