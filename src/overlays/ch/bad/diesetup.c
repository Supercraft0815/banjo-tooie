#include "common.h"

s32 func_80800000_chbaddiesetup(void *arg0) {
    if ((*(s32 *)((s8 *)(arg0) + (0))) == 0) {
        return 0;
    }
    if ((*(u8 *)((s8 *)(arg0) + (4))) == 0x16) {
        return 0;
    }
    return 1;
}

void chbaddiesetup_entrypoint_0(s32 arg0) {
    void *func_800A5D60(void);
    Actor *actor;

    actor = func_800A5D60();
    if (func_80800000_chbaddiesetup(actor) != 0) {
        *(s32 *)((u8 *)actor->unk0 + (((u8 *)actor->position)[0] << 5)) = arg0;
        *(s32 *)((u8 *)actor->unk0 + (((u8 *)actor->position)[0] << 5) + 0x1C) = 0;
        ((u8 *)actor->position)[0]++;
    }
}

void chbaddiesetup_entrypoint_1(s32 arg0, s32 arg1) {
    void *func_800A5D60(void);
    Actor *actor;

    actor = func_800A5D60();
    if (func_80800000_chbaddiesetup(actor) != 0) {
        *(s32 *)((u8 *)actor->unk0 + (((u8 *)actor->position)[0] << 5)) = arg0;
        *(s32 *)((u8 *)actor->unk0 + (((u8 *)actor->position)[0] << 5) + 4) = arg1;
        *(s32 *)((u8 *)actor->unk0 + (((u8 *)actor->position)[0] << 5) + 0x1C) = 1;
        ((u8 *)actor->position)[0]++;
    }
}

void chbaddiesetup_entrypoint_2(s32 arg0, s32 arg1, s32 arg2) {
    void *func_800A5D60(void);
    Actor *actor;
    actor = func_800A5D60();
    if (func_80800000_chbaddiesetup(actor) != 0) {
        *(s32 *)((u8 *)actor->unk0 + (((u8 *)actor->position)[0] << 5)) = arg0;
        *(s32 *)((u8 *)actor->unk0 + (((u8 *)actor->position)[0] << 5) + 4) = arg1;
        *(s32 *)((u8 *)actor->unk0 + (((u8 *)actor->position)[0] << 5) + 8) = arg2;
        *(s32 *)((u8 *)actor->unk0 + (((u8 *)actor->position)[0] << 5) + 0x1C) = 2;
        ((u8 *)actor->position)[0]++;
    }
}

void chbaddiesetup_entrypoint_3(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    void *func_800A5D60(void);
    Actor *actor;
    actor = func_800A5D60();
    if (func_80800000_chbaddiesetup(actor) != 0) {
        *(s32 *)((u8 *)actor->unk0 + (((u8 *)actor->position)[0] << 5)) = arg0;
        *(s32 *)((u8 *)actor->unk0 + (((u8 *)actor->position)[0] << 5) + 4) = arg1;
        *(s32 *)((u8 *)actor->unk0 + (((u8 *)actor->position)[0] << 5) + 8) = arg2;
        *(s32 *)((u8 *)actor->unk0 + (((u8 *)actor->position)[0] << 5) + 0xC) = arg3;
        *(s32 *)((u8 *)actor->unk0 + (((u8 *)actor->position)[0] << 5) + 0x1C) = 3;
        ((u8 *)actor->position)[0]++;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bad/diesetup/chbaddiesetup_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bad/diesetup/chbaddiesetup_entrypoint_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bad/diesetup/chbaddiesetup_entrypoint_6.s")

void chbaddiesetup_entrypoint_7(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    f32 pos[3];
    pos[0] = *(f32 *)&arg1;
    pos[1] = *(f32 *)&arg2;
    pos[2] = *(f32 *)&arg3;
    func_80108474(*(s32 *)&arg0, pos, 0);
}

/* extern */

void chbaddiesetup_entrypoint_8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    void func_80108454(s32, s32 *, u32);
    s32 pos[3];

    pos[0] = *(s32 *)&arg1;
    pos[1] = *(s32 *)&arg2;
    pos[2] = *(s32 *)&arg3;
    func_80108454(*(s32 *)&arg0, pos, 0);
}

/* extern */

void chbaddiesetup_entrypoint_9(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    Actor *_chbounce_entrypoint_6(s32, f32 *);
    f32 pos[3];
    pos[0] = *(f32 *)&arg1;
    pos[1] = *(f32 *)&arg2;
    pos[2] = *(f32 *)&arg3;
    _chbounce_entrypoint_6(*(s32 *)&arg0, pos);
}

Actor *chbaddiesetup_entrypoint_10(s32 id, s32 x, s32 y, s32 z, s32 yaw) {
    void _chbounce_entrypoint_2(f32);
    Actor *_chbounce_entrypoint_6(s32, f32 *);
    f32 pos[3];
    pos[0] = *(f32 *)&x;
    pos[1] = *(f32 *)&y;
    pos[2] = *(f32 *)&z;
    _chbounce_entrypoint_2(*(f32 *)&yaw);
    return _chbounce_entrypoint_6(id, pos);
}
