#include "common.h"

void chdoor_entrypoint_0(s32 arg0)
{
    func_80800028_chdoor();
    func_8080050C_chdoor(arg0);
}
int func_80800028_chdoor(u8 *arg0) {
    s32 _glcutDll_entrypoint_19(s32);
    u8 func_800D9078(f32 *);
    s32 func_800DA298(s32);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    void *func_80100094(Actor *, u32);
    s32 func_8010108C();
    void func_8080032C_chdoor(u8 *, f32);
    void func_8080069C_chdoor(u8 *, s32);
    void func_80800754_chdoor(u8 *);
    void func_808008A0_chdoor(u8 *);
    void func_80800B14_chdoor(u8 *, s32);
    u8 *data;

    data = func_80100094(arg0, 0);
    switch ((u32)*(u16 *)(arg0 + 0x72) >> 10) {
    case 1:
        if (*(s32 *)data & 4) {
            if (func_800DA298(*(s16 *)(data + 4))) {
                func_80800754_chdoor(arg0);
            }
        } else {
            s32 cutscene = data[0x20];
            if (cutscene && _glcutDll_entrypoint_19(cutscene)) {
                func_80800754_chdoor(arg0);
            }
        }
        break;
    case 2:
        if (func_800D9078((f32 *)(arg0 + 0x58))) {
            func_80800B14_chdoor(arg0, 3);
        }
        break;
    case 3: {
        f32 oldOpen;
        s32 openDone;
        oldOpen = *(f32 *)(arg0 + 0x58);
        openDone = func_800D9078((f32 *)(arg0 + 0x58));
        func_8080032C_chdoor(arg0, func_800F12D4(*(f32 *)(arg0 + 0x58), 0.0f,
            (f32)*(s16 *)(data + 0xA) * 0.00390625f, 1.0f, 0.0f));
        if (oldOpen >= 0.2f && *(f32 *)(arg0 + 0x58) < 0.2f) {
            func_8080069C_chdoor(arg0, 1);
        }
        if (openDone) {
            func_80800B14_chdoor(arg0, 4);
            func_8010108C(arg0, 0x9D, 0);
        }
        break;
    }
    case 4:
        if (*(s32 *)data & 2) {
            if (*(s32 *)data & 4) {
                if (!func_800DA298(*(s16 *)(data + 4))) {
                    func_808008A0_chdoor(arg0);
                }
            } else {
                s32 cutscene = data[0x28];
                if (cutscene && _glcutDll_entrypoint_19(cutscene)) {
                    func_808008A0_chdoor(arg0);
                }
            }
            if (*(s32 *)data & 0x400) {
                func_808008A0_chdoor(arg0);
            }
        }
        break;
    case 5:
        if (func_800D9078((f32 *)(arg0 + 0x58))) {
            func_80800B14_chdoor(arg0, 6);
        }
        break;
    case 6: {
        f32 fraction;
        f32 oldClose;
        s32 closeDone;
        oldClose = *(f32 *)(arg0 + 0x58);
        closeDone = func_800D9078((f32 *)(arg0 + 0x58));
        fraction = func_800F12D4(*(f32 *)(arg0 + 0x58), 0.0f,
            (f32)*(s16 *)(data + 0xA) * 0.00390625f, 0.0f, 1.0f);
        func_8080032C_chdoor(arg0, fraction);
        if (oldClose >= 0.2f && *(f32 *)(arg0 + 0x58) < 0.2f) {
            func_8080069C_chdoor(arg0, 0);
        }
        if (closeDone) {
            func_80800B14_chdoor(arg0, 1);
            func_8010108C(arg0, 0x9E, 0);
        }
        break;
    }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/door/func_8080032C_chdoor.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/door/func_8080050C_chdoor.s")

void func_808005E4_chdoor(Actor *arg0, s32 arg1) {
    struct DoorSoundData {
        u8 pad[0x34];
        s16 opening;
        s16 closing;
        s16 sound;
        s16 volume;
        s16 pitch;
    };
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_800C4B64(f32);
    void func_800C4B70(s32);
    void func_800C4B7C(s32);
    void *func_80100094(Actor *, u32);
    extern s32 D_808015B0_chdoor;
    struct DoorSoundData *temp_v0;
    struct DoorSoundData *sp1C;

    temp_v0 = func_80100094(arg0, 0);
    if (temp_v0->sound != 0 && ((arg1 != 0 && temp_v0->opening != 0) || (arg1 == 0 && temp_v0->closing != 0))) {
        sp1C = temp_v0;
        func_800C4B7C(temp_v0->sound);
        func_800C4B70(sp1C->volume);
        func_800C4B64((f32)sp1C->pitch * 0.00390625f);
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_808015B0_chdoor);
    }
}

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
    void *func_80100094(Actor *, u32);
    void func_80101FDC(u8 *, s32);
    void func_80103110(u8 *, s32);
    void func_80800FC0_chdoor(u8 *, s32);
    void func_808005E4_chdoor(Actor *, s32);
    void func_80801330_chdoor(Actor *, s32);
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

void func_80801330_chdoor(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    void func_800DA3B8(s32, s32);
    struct DoorData {
        s32 flags;
        s16 index;
    };
    s32 temp_v1;
    s32 var_a1;
    s32 var_a1_2;
    struct DoorData *data;

    data = func_80100094(arg0, 0);
    if (data->index != -1 && (temp_v1 = data->flags, (temp_v1 & 0x20) == 0)) {
        var_a1 = arg1 != 0 ? 1 : 0;
        if (temp_v1 & 0x10) {
            if (var_a1 != 0) {
                var_a1_2 = 0;
            } else {
                var_a1_2 = 1;
            }
            func_800DA3B8(data->index, var_a1_2);
            return;
        }
        func_800DA3B8(data->index, var_a1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/door/func_808013C0_chdoor.s")
