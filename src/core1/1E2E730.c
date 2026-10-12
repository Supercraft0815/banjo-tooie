#include "common.h"

typedef struct {
    s16 volume;
    u8 unk2;
    u8 unk3;
    u8 pad4;
    u8 pending;
    u8 pad6[2];
    u8 cseq[0x1D8];
    u8 cseqp[0x18];
    s32 unk1F8;
    u8 pad1FC[0x10];
    s32 state;
    u8 pad210[0x5C];
    s16 track_id;
    s16 index_cpy;
    u8 pad270[4];
} MusicSlotView;

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2E730/func_80016C00.s")

/* extern */

void func_80016DA0(s32 arg0, s32 arg1) {
    s32 func_800D5B24();
    s32 func_800D674C(s32);
    s32 func_800D70D0(s32);
    s32 func_800D71F4(s32);
    s32 func_800D73CC(s32);
    s32 sp1C;
    s32 temp_a0;

    temp_a0 = arg0 + 0x1DDD;
    sp1C = temp_a0;
    if (func_800D73CC(temp_a0) == 0) {
        if (arg1 != 0) {
            func_800D5B24();
        }
        func_800D674C(sp1C);
        func_800D70D0(1);
        func_800D71F4(1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2E730/func_80016DF8.s")

void func_80016E7C(void) {
    s32 func_80016DF8(s32);
    extern u16 D_8007AE78;
    s32 var_s0;

    var_s0 = 0;
    if ((s32) D_8007AE78 > 0) {
        do {
            func_80016DF8(var_s0);
            var_s0 += 1;
        } while (var_s0 < (s32) D_8007AE78);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2E730/func_80016ED0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2E730/func_80017070.s")

s32 func_800170D4(u8 arg0) {
    extern s32 D_8007A1B0[][0x9D];
    return D_8007A1B0[arg0][0];
}

s16 func_80017108(u8 arg0) {
    extern s16 D_8007A20C;
    return *(s16 *)((u8 *)&D_8007A20C + arg0 * 0x274);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2E730/func_8001713C.s")

s32 func_80017210(u8 index) {
    typedef struct { s32 state; u8 pad[0x270]; } MusicSlotSeqp;
    extern MusicSlotSeqp D_8007A1AC[];
    return D_8007A1AC[index].state;
}

void func_80017244(void) {
    s32 func_80017210(u8 index);

    void func_80016ED0(u8, s32);
    int i;
    int still_running;
    volatile OSTime time;

    for (i = 0; i < 6; i++) {
        func_80016ED0(i, -1);
    }

    time = osGetTime();

    do {
        still_running = 0;
        for (i = 0; i < 6; i++) {
            if (func_80017210(i) != 0)
                still_running++;
        }
        osGetTime();
    } while(still_running);

}

void func_800172D4(u8 index, s32 track_id) {
    extern u16 D_8003F600[];
    extern s32 D_80079FA0;
    MusicSlotView *slots = (MusicSlotView *)&D_80079FA0;
    slots[index].index_cpy = track_id;
    slots[index].unk2 = 1;
    slots[index].pending = 1;
    slots[index].unk3 = 0;
    slots[index].volume =  D_8003F600[track_id];
}

void func_80017330(u8 index) {
    extern s32 D_80079FA0;
    MusicSlotView *slots = (MusicSlotView *)&D_80079FA0;
    s32 track_id = slots[index].track_id;

    if ((track_id == 0x10) || (track_id == 0x18)) {
        slots[index].unk2 = 1;
        slots[index].unk3 = 0;
        slots[index].index_cpy = slots[index].track_id;
    } else {
        slots[index].index_cpy = -1;
        slots[index].unk3 = 1;
        slots[index].unk2 = 1;
        slots[index].pending = 1;
        slots[index].volume = 0;
    }
}

void func_800173B0(u8 index, s16 volume) {
    extern s32 D_80079FA0;
    MusicSlotView *slots = (MusicSlotView *)&D_80079FA0;
    slots[index].unk3 = 1;
    slots[index].unk2 = 1;
    slots[index].pending = 1;
    slots[index].volume = volume;
    slots[index].index_cpy = slots[index].track_id;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2E730/func_80017404.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2E730/func_800174C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2E730/func_80017534.s")

s32 func_800175A0(u8 index) {
    s32 func_80025668(void *);
    extern s32 D_80079FA0;
    MusicSlotView *slots = (MusicSlotView *)&D_80079FA0;
    return func_80025668(slots[index].cseq);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2E730/func_800175F0.s")

u32 func_80017764(s32 arg0) {
    extern u16 D_8003F600[];
    return ((u16 *)&D_8003F600)[arg0];
}

int func_80017778(s32 index) {
    extern s32 D_80079FA0;
    u8 *slot = (u8 *)&D_80079FA0 + index * 0x274;
    return *(s32 *)(slot + 0x20C) == 0 && !slot[3];
}

int func_800177C4(s32 arg0) {
    extern s32 D_80079FA0;
    u8 *slot = (u8 *)&D_80079FA0 + arg0 * 0x274;
    return *(s32 *)(slot + 0x20C) == 0 && slot[3] != 0;
}

u8 *func_80017810(s32 arg0) {
    extern s32 D_80079FA0;
    return (u8 *)((arg0 * 0x274) + 0x1E0 + (s32)&D_80079FA0);
}

void func_80017840(void) {
}
