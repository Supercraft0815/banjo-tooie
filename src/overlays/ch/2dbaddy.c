#include "common.h"

OSThread *ch2dbaddy_entrypoint_0(void)
{
    extern u8 D_80800A9C_ch2dbaddy[];

    return (OSThread *) D_80800A9C_ch2dbaddy;
}

/* extern */

void func_8080000C_ch2dbaddy(Actor *arg0) {
    s32 _sucoaster_entrypoint_0(void *, s32);
    u8 *_sucoaster_entrypoint_3();
    s32 func_800EE940();
    void func_80102FDC(Actor *, f32);
    void func_8010A3E8(void *, f32);
    void func_8010A570(Actor *);
    void func_80800850_ch2dbaddy();
    u8 *sp24;

    if (_sucoaster_entrypoint_0(arg0, 0xA) != 0) {
        func_8010A3E8(arg0, 0.55f);
        func_80102FDC(arg0, arg0->scale * 0.6f);
        sp24 = _sucoaster_entrypoint_3(arg0);
        func_80800850_ch2dbaddy(arg0);
        func_800EE940(sp24, arg0->position);
        arg0->unk64_16 = 0;
        func_8010A570(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/2dbaddy/func_808000A0_ch2dbaddy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/2dbaddy/func_808002A8_ch2dbaddy.s")

/* extern */

s32 func_808003C4_ch2dbaddy(f32 *arg0) {
    void func_800EE88C(f32 dst[3], s16 src[3]);
    f32 func_800EFC7C(f32 *, f32 *);
    u8 *_sucoaster_entrypoint_3();
    f32 sp1C[3];

    func_800EE88C(sp1C, (s16 *)_sucoaster_entrypoint_3());
    return func_800EFC7C(arg0 + 1, sp1C) < 10000.0f;
}

/* extern */

s32 func_8080041C_ch2dbaddy(u8 *arg0) {
    s32 _subaddiejoy_entrypoint_6(u8 *, s32);
    s32 _sucoaster_entrypoint_13();
    struct Flags {
        u8 pad[0x64];
        u32 : 2;
        u32 flag : 1;
        u32 : 29;
    };
    if (((struct Flags *)arg0)->flag) {
        return _subaddiejoy_entrypoint_6(arg0, 0) == 1;
    }
    return _sucoaster_entrypoint_13() == 1;
}

/* extern */

s32 func_80800468_ch2dbaddy(u8 *arg0) {
    s32 _subaddiejoy_entrypoint_6(u8 *, s32);
    struct Flags {
        u8 pad[0x64];
        u32 : 2;
        u32 flag : 1;
        u32 : 29;
    };

    if (((struct Flags *)arg0)->flag) {
        return _subaddiejoy_entrypoint_6(arg0, 0) == 1;
    } else {
        return 0;
    }
}

/* extern */

void func_808004A8_ch2dbaddy(Actor *arg0) {
    s32 _sucoaster_entrypoint_10(Actor *, s32);
    s32 func_80800700_ch2dbaddy(Actor *, s32);
    u32 temp_t6;

    temp_t6 = (u32) arg0->unk70_10;
    if (temp_t6 != 0x13) {
        if (temp_t6 == 0x15) {
            _sucoaster_entrypoint_10(arg0, 3);
        }
    } else {
        func_80800700_ch2dbaddy(arg0, 0x14);
    }
}

/* extern */

void func_808004F4_ch2dbaddy(Actor *arg0) { s32 _subaddieDll_entrypoint_3(Actor *); s32 _sucoaster_entrypoint_10(Actor *, s32); s32 _sucoaster_entrypoint_6(Actor *, f32, s32); s32 var_a2; if ((arg0->unk70_10 == 2) || (arg0->unk70_10 == 3) || (arg0->unk70_10 == 8)) { if (_subaddieDll_entrypoint_3(arg0) != 0) { var_a2 = 0x15; } else { var_a2 = 0xE; } _sucoaster_entrypoint_6(arg0, 200.0f, var_a2); _sucoaster_entrypoint_10(arg0, var_a2); } }

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/2dbaddy/func_80800564_ch2dbaddy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/2dbaddy/func_80800700_ch2dbaddy.s")

void func_80800820_ch2dbaddy(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    extern u32 D_80800AF4_ch2dbaddy;
    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80800AF4_ch2dbaddy, 0.1f);
}

void func_80800850_ch2dbaddy(void) {
    s32 func_800DC128(s32, s32);
    u8 *_sucoaster_entrypoint_3();
    extern s16 D_80800B00_ch2dbaddy[];
    u8 *sp1C;

    sp1C = _sucoaster_entrypoint_3();
    (*(s16 *)((s8 *)(sp1C) + (6))) = D_80800B00_ch2dbaddy[func_800DC128(0, 3)];
}
