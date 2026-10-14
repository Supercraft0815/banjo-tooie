#include "common.h"

void subaddiedraw25d_entrypoint_0(void *arg0) {
    struct Flags {
        u8 pad[0x7E];
        u8 high : 3;
        u8 enabled : 1;
        u8 low : 4;
    };
    ((struct Flags *)arg0)->enabled = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/draw25d/subaddiedraw25d_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/draw25d/subaddiedraw25d_entrypoint_2.s")

/* extern */

void subaddiedraw25d_entrypoint_3(Actor *arg0) {
    struct Flags {
        u8 pad[0x70];
        u32 high : 11;
        u32 enabled : 1;
        u32 low : 20;
    };
    s32 func_800D2F20(void);
    void func_800E249C(s32);
    void func_800E24C0(s32);
    void *func_80100368(void *);
    u16 temp_a0;

    func_800E24C0(((struct Flags *)arg0)->enabled);
    temp_a0 = (*(u16 *)((s8 *)(func_80100368(arg0)) + (0x1A)));
    if (temp_a0 != 0) {
        func_800E249C(temp_a0);
        return;
    }
    if (!(arg0->unk0->unk10 & 1)) {
        func_800E249C(func_800D2F20());
    }
}
