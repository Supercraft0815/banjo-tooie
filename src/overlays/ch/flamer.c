#include "common.h"

OSThread *chflamer_entrypoint_0(void)
{
    extern u8 D_80800B20_chflamer[];

    return (OSThread *) D_80800B20_chflamer;
}

/* extern */

void func_8080000C_chflamer(Actor *arg0) {
    s32 func_800BF8E4();
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    sp1C = temp_v0;
    (*(s16 *)((s8 *)(temp_v0) + (0x16))) = 0;
    (*(s16 *)((s8 *)(temp_v0) + (0x18))) = 0;
    (*(s32 *)((s8 *)(temp_v0) + (0x1AC))) = 0;
    if (func_800BF8E4() > 0) {
        (*(s16 *)((s8 *)(sp1C) + (4))) = 0x190;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flamer/func_80800050_chflamer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flamer/func_80800434_chflamer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flamer/func_80800594_chflamer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flamer/chflamer_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flamer/chflamer_entrypoint_2.s")

Actor *func_80800738_chflamer(Actor *arg0) {
    struct LinkedActorFlags {
        u8 pad[0x74];
        u8 pad74_1 : 7;
        u8 unk74_0 : 1;
    };
    s32 _subaddielink_entrypoint_0(u8 *);
    Actor *_subaddielink_entrypoint_4(u8 *);
    u8 *sp1C;
    Actor *data;

    sp1C = func_80100094(arg0, 0U);
    data = _subaddielink_entrypoint_4(sp1C + 0x1B4);
    if (data != NULL) {
        ((struct LinkedActorFlags *)data)->unk74_0 = 0;
        func_8010108C(data, 0x2B, 0);
    }
    _subaddielink_entrypoint_0(sp1C + 0x1B4);
    arg0->unk70_10 = 3;
    return arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flamer/func_808007A8_chflamer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flamer/func_808008C0_chflamer.s")

void func_8080098C_chflamer(s32 arg0) {
    s32 _subaddieaudioloop_entrypoint_5(s32, s32, s32, s32, s32 *);
    extern s32 D_80800B68_chflamer;
    _subaddieaudioloop_entrypoint_5(arg0, arg0 + 4, 1, -1, &D_80800B68_chflamer);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flamer/func_808009C0_chflamer.s")
