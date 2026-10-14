#include "common.h"

OSThread *chdiggerbossdoor_entrypoint_0(void)
{
    extern u8 D_80800430_chdiggerbossdoor[];

    return (OSThread *) D_80800430_chdiggerbossdoor;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/bossdoor/func_8080000C_chdiggerbossdoor.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/bossdoor/func_808000B0_chdiggerbossdoor.s")

/* extern */

void func_808002A8_chdiggerbossdoor(void *arg0) {
    s32 _capod_entrypoint_22();
    if ((*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF) {
        _capod_entrypoint_22();
        (*(u16 *)((s8 *)(arg0) + (0x6E))) = (u16) ((*(u16 *)((s8 *)(arg0) + (0x6E))) & 0xFE00);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/bossdoor/func_808002E8_chdiggerbossdoor.s")

void func_80800370_chdiggerbossdoor(s32 *arg0) {
    s32 _glid_entrypoint_0(s32, s32, s32 *, s32);
    s32 func_800BEA88(s32);
    extern s32 _chdiggerbossdoor_entrypoint_1;
    s32 temp_v0;

    temp_v0 = func_800BEA88(0);
    if (temp_v0 != 0) {
        _glid_entrypoint_0(temp_v0, 1, &_chdiggerbossdoor_entrypoint_1, *arg0);
    }
}

/* extern */

void chdiggerbossdoor_entrypoint_1(s32 arg0, Vtx *arg1, Vtx *arg2, s32 arg3, Unk80132ED0 *arg4) {
    Actor *func_80106790(Unk80132ED0 *);
    s16 offset;
    Vtx *end;

    offset = *(f32 *)&func_80106790(arg4)->actorData[4];
    end = arg1 + arg3;
    if (arg1 < end) {
        do {
            arg1++;
            arg2++;
            arg2[-1].v.ob[1] = arg1[-1].v.ob[1] + offset;
        } while (arg1 < end);
    }
}
