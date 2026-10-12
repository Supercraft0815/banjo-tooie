#include "common.h"

/* extern */

void func_80800000_chbeanstalkseed(void *arg0) {
    s32 func_800DA298(s32);
    s32 func_800FFA88(s32);
    if (func_800DA298(((u32) (*(u16 *)((s8 *)(arg0) + (0x76))) >> 7) + 0x33D) != 0) {
        func_800FFA88((*(s32 *)((s8 *)(arg0) + (0))));
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/beanstalkseed/func_8080003C_chbeanstalkseed.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/beanstalkseed/func_8080026C_chbeanstalkseed.s")

OSThread *chbeanstalkseed_entrypoint_0(void)
{
    extern u8 D_80800C00_chbeanstalkseed[];

    return (OSThread *) D_80800C00_chbeanstalkseed;
}

/* extern */

s32 func_80800328_chbeanstalkseed(void) {
    s32 func_800D1A04(s32);
    s32 func_800F54E4();
    s32 func_800F64A4(s32, s32);
    s32 func_800F66F0(s32);
    s32 func_800F6720(s32);
    s32 func_8010C500();
    if (func_8010C500() == 0) {
        return 0;
    }
    if (func_800D1A04(0x50) == 0) {
        return 0;
    }
    if (func_800F64A4(func_800F54E4(), 0x201) == 0) {
        return 0;
    }
    if (func_800F6720(func_800F54E4()) != 0) {
        return 0;
    }
    if (func_800F66F0(func_800F54E4()) != 0) {
        return 0;
    }
    return 1;
}

void func_808003D8_chbeanstalkseed(Actor *arg0) {
    s32 _subaddieDll_entrypoint_4(void *, s32);
    Actor *_subaddiefind_entrypoint_2(s32, s32);
    void _subaddieitem_entrypoint_0(s32, u32, s32, s32);
    void _subaddieitem_entrypoint_2(s32);
    s32 _subaddieitem_entrypoint_3(Actor *, f32 *, void *);
    f32 func_80013970(f32);
    void func_800C3F48(u32);
    s32 func_800D91EC(f32 *, f32);
    s32 func_800F0064(f32 *, f32, f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F13C4(f32, f32);
    s32 func_800F54E4(void);
    void func_800F7F50(s32, f32 *, f32 *, f32, s32, s32);
    s32 func_800FFA88(s32);
    u32 *func_80100074(Actor *, u32, u32);
    void *func_80100094(Actor *, u32);
    s32 func_801000D8(Actor *, s32, s32);
    void func_80101FDC(Actor *, u32);
    void func_8010C964(Actor *);
    void func_8010D254(f32 *);
    s32 func_80800328_chbeanstalkseed();
    void func_80800804_chbeanstalkseed(Actor *, s32);
    f32 remainder;
    f32 scale;
    s32 i;

    switch ((u32)*(u16 *)((u8 *)arg0 + 0x72) >> 10) {
    case 1: {
        s32 item;
        if (func_80800328_chbeanstalkseed(arg0) != 0) {
            item = func_801000D8(arg0, 1, 0x14);
            _subaddieitem_entrypoint_0(item, 0x481, 1000, 0);
            _subaddieitem_entrypoint_2(item);
            func_80101FDC(arg0, 2);
        }
        return;
    }
    case 2: {
        Actor *seed;
        if (_subaddieitem_entrypoint_3(arg0, (f32 *)((u8 *)arg0 + 4), func_80100094(arg0, 1)) != 0) {
            seed = _subaddiefind_entrypoint_2(0x481, 0);
            if (seed != NULL) {
                *(f32 *)((u8 *)arg0 + 0x48) = *(f32 *)((u8 *)seed + 0x48);
                func_800FFA88(*(s32 *)seed);
            }
            func_80800804_chbeanstalkseed(arg0, 3);
            func_80100074(arg0, 1, 0);
        }
        break;
    }
    case 3:
        func_8010C964(arg0);
        return;
    case 4: {
        f32 phase;
        if (func_800D91EC((f32 *)((u8 *)arg0 + 0x58), 6.0f) != 0) {
            func_80800804_chbeanstalkseed(arg0, 5);
            return;
        }
        scale = 0.00001f;
        for (i = 0; i < 8; i++) {
            if (*(f32 *)((u8 *)arg0 + 0x58) < 0.75f * (f32)i) {
                continue;
            }
            if (0.75f * (f32)(i + 1) < *(f32 *)((u8 *)arg0 + 0x58)) {
                scale += 0.125f;
            } else {
                phase = func_800F13C4(*(f32 *)((u8 *)arg0 + 0x58), 0.75f);
                scale += func_80013970(func_800F10B4(phase, 0.0f, 0.75f, 0.0f, 90.0f)) * 0.125f;
            }
        }
        *(f32 *)((u8 *)arg0 + 0x24) = *(f32 *)((u8 *)arg0 + 0x54);
        *(f32 *)((u8 *)arg0 + 0x54) = scale;
        *(f32 *)((u8 *)arg0 + 0x38) = func_800F10B4(*(f32 *)((u8 *)arg0 + 0x58), 0.0f, 6.0f, 0.0f, 1.0f) * scale;
        remainder = func_800F13C4(*(f32 *)((u8 *)arg0 + 0x24), 0.125f);
        if (func_800F13C4(*(f32 *)((u8 *)arg0 + 0x54), 0.125f) < remainder) {
            if (*(f32 *)((u8 *)arg0 + 0x58) < 5.8f) {
                func_800C3F48(((u16)(func_800F10B4(*(f32 *)((u8 *)arg0 + 0x58), 0.0f, 6.0f, 0.5f, 1.0f) * 1023.0f) << 21) + 0x1B5C1D);
                return;
            }
        }
        break;
    }
    case 5: {
        f32 position[3];
        func_8010D254(position);
        if (func_800F0064(position, *(f32 *)((u8 *)arg0 + 0x38) * 150.0f, (f32 *)((u8 *)arg0 + 4)) != 0 &&
            *(f32 *)((u8 *)arg0 + 8) < position[1] && position[1] <= *(f32 *)((u8 *)arg0 + 0x2C)) {
            _subaddieDll_entrypoint_4(arg0, 1);
            remainder = *(f32 *)((u8 *)arg0 + 0x38) * func_800F10B4(position[1], *(f32 *)((u8 *)arg0 + 8), *(f32 *)((u8 *)arg0 + 0x2C), 100.0f, 75.0f);
            func_800F7F50(func_800F54E4(), (f32 *)((u8 *)arg0 + 4), (f32 *)((u8 *)arg0 + 0x28), remainder, 1, 1);
            return;
        }
        _subaddieDll_entrypoint_4(arg0, 0);
        break;
    }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/beanstalkseed/func_80800804_chbeanstalkseed.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/beanstalkseed/func_80800950_chbeanstalkseed.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/beanstalkseed/func_80800A0C_chbeanstalkseed.s")

OSThread *chbeanstalkseed_entrypoint_1(void)
{
    extern u8 D_80800C54_chbeanstalkseed[];

    return (OSThread *) D_80800C54_chbeanstalkseed;
}
