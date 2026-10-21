#include "common.h"

struct player_state_s;

s32 baeggfire_entrypoint_0() 
{
    return 0x14;
}

s32 func_80800008_baeggfire(void *arg0, s32 arg1) {
    void *temp_v0;
    void *temp_v0_2;

    if (arg1 == 1) {
        temp_v0_2 = (*(void **)((s8 *)(arg0) + (0x6C)));
        (*(u8 *)((s8 *)(temp_v0_2) + (0x12))) = (u8) ((*(u8 *)((s8 *)(temp_v0_2) + (0x12))) + 1);
        return (s32) temp_v0_2;
    }
    temp_v0 = (*(void **)((s8 *)(arg0) + (0x6C)));
    (*(u8 *)((s8 *)(temp_v0) + (0x11))) = (u8) ((*(u8 *)((s8 *)(temp_v0) + (0x11))) + 1);
    return (s32) temp_v0;
}

void func_80800040_baeggfire(void *arg0) {
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x6C)))) + (0x12))) = 0;
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x6C)))) + (0x11))) = 0;
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x6C)))) + (0x13))) = 0;
}

/* extern */

void baeggfire_entrypoint_1(void) {
    void *func_800F53D0();
    s32 func_80800008_baeggfire(void *, s32);
    void *temp_v0;

    temp_v0 = func_800F53D0();
    (*(s8 *)((s8 *)((*(void **)((s8 *)(temp_v0) + (0x6C)))) + (0x13))) = 0;
    func_80800008_baeggfire(temp_v0, 0);
}

/* extern */

void baeggfire_entrypoint_2(void) {
    void *func_800F53D0();
    (*(s8 *)((s8 *)((*(void **)((s8 *)(func_800F53D0()) + (0x6C)))) + (0x13))) = 0;
}

void func_808000B8_baeggfire(void *arg0) {
    s32 _baeggsetup_entrypoint_10(void *);
    s32 _baeggsetup_entrypoint_8(void *, u8);
    s32 func_800C9DE4(f32, s32 *, s32);
    extern s32 _baeggfire_entrypoint_1;
    extern s32 _baeggfire_entrypoint_2;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v0_3;

    temp_v0 = (*(void **)((s8 *)(arg0) + (0x6C)));
    if ((*(u8 *)((s8 *)(temp_v0) + (0x13))) == 0) {
        if ((*(u8 *)((s8 *)(temp_v0) + (0x12))) != 0) {
            func_800C9DE4(0.25f, &_baeggfire_entrypoint_1, (*(s32 *)((s8 *)(arg0) + (0x184))));
            (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x6C)))) + (0x13))) = 1;
            _baeggsetup_entrypoint_10(arg0);
            temp_v0_2 = (*(void **)((s8 *)(arg0) + (0x6C)));
            (*(u8 *)((s8 *)(temp_v0_2) + (0x12))) = (u8) ((*(u8 *)((s8 *)(temp_v0_2) + (0x12))) - 1);
            return;
        }
        if ((*(u8 *)((s8 *)(temp_v0) + (0x11))) != 0) {
            func_800C9DE4(0.17f, &_baeggfire_entrypoint_2, (*(s32 *)((s8 *)(arg0) + (0x184))));
            (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x6C)))) + (0x13))) = 1;
            _baeggsetup_entrypoint_8(arg0, (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x6C)))) + (0x10))));
            temp_v0_3 = (*(void **)((s8 *)(arg0) + (0x6C)));
            (*(u8 *)((s8 *)(temp_v0_3) + (0x11))) = (u8) ((*(u8 *)((s8 *)(temp_v0_3) + (0x11))) - 1);
        }
    }
}

void func_80800180_baeggfire(void *arg0, s32 arg1) {
    typedef struct player_state_s PlayerState;
    s32 func_800944F8(PlayerState *arg0, s32 arg1);

    *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x6C) + 8) = arg1;
    switch (arg1) {
        case 1:
            *(f32 *)*(void **)((u8 *)arg0 + 0x6C) = 0.0f;
            *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x6C) + 4) = 0;
            *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x6C) + 0xC) = 0;
            break;
        case 2:
            if (func_800944F8(arg0, *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x6C) + 0x10))) {
                *(f32 *)*(void **)((u8 *)arg0 + 0x6C) = 0.15f;
            } else {
                *(f32 *)*(void **)((u8 *)arg0 + 0x6C) = 0.28f;
            }
            break;
        case 3:
            *(f32 *)*(void **)((u8 *)arg0 + 0x6C) = 0.2f;
            break;
        case 4:
            *(f32 *)*(void **)((u8 *)arg0 + 0x6C) = 0.5f;
            break;
    }
}

void func_80800250_baeggfire(void *arg0) {
    typedef struct player_state_s PlayerState;
    s32 func_800944F8(PlayerState *, s32);
    s32 func_800944E0(PlayerState *, s32);
    s32 func_80094510(PlayerState *);
    void baeggfire_entrypoint_3(struct player_state_s *, f32 *, f32 *);
    void func_800EF368(f32 *, f32);
    void func_800EE780(f32 *, f32 *, f32 *);
    s32 _baeggsetup_entrypoint_6(void *, s32, f32 *, f32 *, f32 *);
    s32 _baeggcursor_entrypoint_8(void *);
    void func_800C6DA0(s32);
    f32 speed;
    f32 sp50[3];
    f32 sp44[3];
    f32 sp38[3];
    s32 count;
    s32 repeat;

    repeat = func_800944F8(arg0, *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x6C) + 0x10));
    if (*(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x6C) + 4) == 0) {
        *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x6C) + 0x10) = func_80094510(arg0);
    }
    count = func_800944E0(arg0, *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x6C) + 0x10));
    if (*(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x6C) + 4) == 0) {
        func_80800008_baeggfire(arg0, 1);
        if (count == 1) {
            func_80800180_baeggfire(arg0, 4);
        } else {
            func_80800180_baeggfire(arg0, 2);
        }
    } else if (repeat || *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x6C) + 4) < count - 1) {
        func_80800008_baeggfire(arg0, 0);
        func_80800180_baeggfire(arg0, 2);
    } else {
        func_80800008_baeggfire(arg0, 0);
        func_80800180_baeggfire(arg0, 4);
    }
    if (repeat) {
        *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x6C) + 4) = 1;
    } else {
        (*(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x6C) + 4))++;
    }
    *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x6C) + 0xC) = 0;
    baeggfire_entrypoint_3(arg0, sp50, sp44);
    func_800EF368(sp44, 100.0f);
    func_800EE780(sp38, sp50, sp44);
    if (*(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x6C) + 0x10) == 7) {
        speed = 5000.0f;
    } else {
        speed = 3000.0f;
    }
    func_800EF368(sp44, speed);
    _baeggsetup_entrypoint_6(arg0, *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 0x6C) + 0x10), sp50, sp38, sp44);
    _baeggcursor_entrypoint_8(arg0);
    func_800C6DA0(0x43);
}

void baeggfire_entrypoint_3(struct player_state_s *arg0, f32 *arg1, f32 *arg2) {
    typedef struct player_state_s PlayerState;
    u32 _baeggcursor_entrypoint_2(void *);
    void _baeggcursor_entrypoint_3(void *, f32 *, f32 *);
    int func_800A4C68(void *);
    void func_800A4CE8(PlayerState *, f32 *);
    void func_800C4E58(s32, f32 *, f32 *);
    void func_800C5008(s32, f32 *, f32 *);
    void func_800EF368(f32 *, f32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800EFB24(void *, void *, void *);
    f32 sp4C;
    f32 sp48;
    f32 sp40[2];
    f32 sp34[3];
    f32 sp28[3];

    if (_baeggcursor_entrypoint_2(arg0) != 1) {
        _baeggcursor_entrypoint_3(arg0, &sp48, &sp4C);
    } else {
        sp48 = 152.0f;
        sp4C = 114.0f;
    }
    func_800C5008(func_800A4C68(arg0), &sp48, sp40);
    func_800EFA4C(sp28, sp40[0], sp40[1], 100.0f);
    func_800C4E58(func_800A4C68(arg0), sp28, sp34);
    func_800A4CE8(arg0, arg1);
    func_800EFB24(arg2, sp34, arg1);
    func_800EF368(arg2, 1.0f);
}

void baeggfire_entrypoint_4(s32 arg0)
{
    func_8009E0AC(arg0,1);
}

void baeggfire_entrypoint_5(void *arg0) {
    void func_80800180_baeggfire(void *arg0, s32 arg1);
    (*(f32 *)((u8 *)*(void **)((u8 *)arg0 + 0x6C))) = 0.0f;
    (*(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x6C) + 0xC)) = 0;
    (*(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x6C) + 8)) = 0;
    func_80800180_baeggfire(arg0, 1);
    func_8009E0AC(arg0, 0);
    func_80800040_baeggfire(arg0);
}

void baeggfire_entrypoint_6(void *arg0) {
    s32 func_800D9078(f32 *arg0);
    void func_80800250_baeggfire(void *arg0);
    f32 *data;

    func_808000B8_baeggfire(arg0);
    data = *(f32 **)((u8 *)arg0 + 0x6C);
    switch (*(s32 *)((u8 *)data + 8)) {
        case 1:
            if (*(s32 *)((u8 *)data + 0xC) != 0) {
                func_80800250_baeggfire(arg0);
            }
            break;
        case 2:
            if (func_800D9078(data) != 0) {
                func_80800180_baeggfire(arg0, 3);
            }
            break;
        case 3:
            if (func_800D9078(data) != 0) {
                func_80800180_baeggfire(arg0, 1);
            }
            if (*(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x6C) + 0xC) != 0) {
                func_80800250_baeggfire(arg0);
            }
            break;
        case 4:
            if (func_800D9078(data) != 0) {
                func_80800180_baeggfire(arg0, 1);
            }
            break;
    }
}

void baeggfire_entrypoint_7(void *arg0) {
    (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x6C)))) + (0xC))) = 1;
}

s32 baeggfire_entrypoint_8(void *arg0) {
    return (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x6C)))) + (8))) >= 2;
}
