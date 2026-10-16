#include "common.h"

OSThread *chdiggerbossdoor_entrypoint_0(void)
{
    extern u8 D_80800430_chdiggerbossdoor[];

    return (OSThread *) D_80800430_chdiggerbossdoor;
}

void func_8080000C_chdiggerbossdoor(void *arg0) {
    s32 _capod_entrypoint_21(s32, s32, s32, s32);
    s32 func_800DA298(s32);
    s32 func_800EA090(void);
    u32 func_800F54E4(void);
    void func_800F8294(s32, f32 *);
    s32 func_8010108C(Actor *, s32, s32);
    void func_80800370_chdiggerbossdoor(s32 *);
    Actor *actor = arg0;

    *(f32 *)&actor->actorData[4] = 0.0f;
    if (func_800EA090() == 6) {
        *(f32 *)&actor->actorData[4] = -500.0f;
        if (func_800DA298(0x43) != 0) {
            func_80800370_chdiggerbossdoor(arg0);
            func_8010108C(actor, 7, 0);
            func_800F8294(func_800F54E4(), actor->position);
            _capod_entrypoint_21((s32)actor->unk0, 0, 0x55, 0x2010);
            actor->unk6C_0 = 1;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/digger/bossdoor/func_808000B0_chdiggerbossdoor.s")

/* extern */

void func_808002A8_chdiggerbossdoor(void *arg0) {
    s32 _capod_entrypoint_22();
    if ((*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF) {
        _capod_entrypoint_22();
        (*(u16 *)((s8 *)(arg0) + (0x6E))) = (u16) ((*(u16 *)((s8 *)(arg0) + (0x6E))) & 0xFE00);
    }
}

s32 func_808002E8_chdiggerbossdoor(void *arg0, s32 arg1, s32 arg2) {
    void func_80101FDC(Actor *, u32);
    void func_80800370_chdiggerbossdoor(s32 *);
    Actor *actor = arg0;
    s32 *data = &arg2;

    switch (arg1) {
        case 7:
            if (actor->unk70_10 == 1) {
                func_80101FDC(actor, 2);
                actor->unk58 = 6.0f;
            }
            break;
        case 0x95:
            func_80800370_chdiggerbossdoor(arg0);
            return 1;
        default:
            return 0;
    }
    return 1;
}

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
