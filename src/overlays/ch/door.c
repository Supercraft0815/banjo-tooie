#include "common.h"

void chdoor_entrypoint_0(s32 arg0)
{
    func_80800028_chdoor();
    func_8080050C_chdoor(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/door/func_80800028_chdoor.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/door/func_8080032C_chdoor.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/door/func_8080050C_chdoor.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/door/func_808005E4_chdoor.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/door/func_8080069C_chdoor.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/door/func_80800754_chdoor.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/door/func_808008A0_chdoor.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/door/func_808009F4_chdoor.s")

void func_80800B14_chdoor(u8 *arg0, s32 arg1) {
    struct DoorFlags {
        u32 unused : 6;
        u32 special : 1;
        u32 rest : 25;
    };
    struct DoorActorFlags {
        u8 unused : 7;
        u8 active : 1;
    };
    u8 *func_80100094(u8 *, s32);
    void func_80101FDC(u8 *, s32);
    void func_80103110(u8 *, s32);
    void func_80800FC0_chdoor(u8 *, s32);
    void func_808005E4_chdoor(u8 *, s32);
    void func_80801330_chdoor(u8 *, s32);
    s32 _subaddieaudioloop_entrypoint_2(u8 *);
    void func_800FC660(u32);
    void func_800FFAB0(u8 *);
    void func_8010A624(u8 *);
    void func_8010A63C(u8 *);
    s32 func_800E1610(s32, s32, s32, u8 *);
    void func_800E148C(s32, s32, s32);
    void func_80018820(s32, s32, s32);
    u8 *data;
    u32 state;
    s32 flag4;
    s32 flag8;

    data = func_80100094(arg0, 0);
    state = (u32)*(u16 *)(arg0 + 0x72) >> 10;
    if (*(s32 *)data & 4) {
        flag4 = 1;
    } else {
        flag4 = 0;
    }
    if (*(s32 *)data & 8) {
        flag8 = 1;
    } else {
        flag8 = 0;
    }
    if (((struct DoorFlags *)(data + 8))->special) {
        switch (state) {
        case 3:
            func_80101FDC(arg0, 6);
            func_80800FC0_chdoor(arg0, 1);
            *(f32 *)(arg0 + 0x58) = *(s16 *)(data + 0xA) * 0.00390625f;
            break;
        case 6:
            func_80101FDC(arg0, 3);
            if (*(s16 *)(data + 0xC) == 0) {
                func_80800FC0_chdoor(arg0, 0);
            }
            *(f32 *)(arg0 + 0x58) = *(s16 *)(data + 0xA) * 0.00390625f;
            break;
        }
        data[8] &= ~2;
        return;
    }
    func_80101FDC(arg0, arg1);
    switch (arg1) {
    case 1:
        _subaddieaudioloop_entrypoint_2(arg0);
        func_80103110(arg0, flag4 | flag8);
        func_80801330_chdoor(arg0, 0);
        if (*(s32 *)data & 0x100) {
            func_800E148C(func_800E1610(2, 0x42C80000, 0x3F59999A, arg0 + 4), 0x447A0000, 0x457A0000);
            func_80018820(0, 0x3F800000, 0x3ECCCCCD);
        }
        break;
    case 2:
        func_80800FC0_chdoor(arg0, 0);
        *(f32 *)(arg0 + 0x58) = *(s16 *)(data + 0xC) * 0.00390625f;
        func_80103110(arg0, 1);
        break;
    case 3:
        if (*(s32 *)data & 0x40) {
            func_800FC660(0x10);
        }
        if (*(s16 *)(data + 0xC) == 0) {
            func_80800FC0_chdoor(arg0, 0);
        }
        *(f32 *)(arg0 + 0x58) = *(s16 *)(data + 0xA) * 0.00390625f;
        func_808005E4_chdoor(arg0, 1);
        func_80103110(arg0, 1);
        func_80801330_chdoor(arg0, 1);
        break;
    case 4:
        _subaddieaudioloop_entrypoint_2(arg0);
        func_80103110(arg0, flag4 | flag8);
        if (*(s32 *)data & 0x800) {
            func_8010A624(arg0);
        }
        if (*(s32 *)data & 0x2000) {
            arg0[0x65] &= ~1;
        }
        if (*(s32 *)data & 1) {
            func_800FFAB0(arg0);
        }
        break;
    case 5:
        func_80800FC0_chdoor(arg0, 1);
        *(f32 *)(arg0 + 0x58) = *(s16 *)(data + 0xE) * 0.00390625f;
        func_80103110(arg0, 1);
        break;
    case 6:
        if (*(s32 *)data & 0x1000) {
            func_800FC660(0x17);
        }
        if (*(s16 *)(data + 0xE) == 0) {
            func_80800FC0_chdoor(arg0, 1);
        }
        if (*(s32 *)data & 0x800) {
            func_8010A63C(arg0);
        }
        if (*(s32 *)data & 0x2000) {
            ((struct DoorActorFlags *)(arg0 + 0x65))->active = 1;
        }
        *(f32 *)(arg0 + 0x58) = *(s16 *)(data + 0xA) * 0.00390625f;
        func_808005E4_chdoor(arg0, 0);
        func_80103110(arg0, 1);
        break;
    case 7:
        func_80800FC0_chdoor(arg0, 0);
        func_80103110(arg0, flag8);
        break;
    case 8:
        func_80800FC0_chdoor(arg0, 1);
        func_80103110(arg0, flag8);
        break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/door/func_80800FC0_chdoor.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/door/chdoor_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/door/func_80801330_chdoor.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/door/func_808013C0_chdoor.s")
