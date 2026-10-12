#include "common.h"

OSThread *ch2dbaddy_entrypoint_0(void)
{
    extern u8 D_80800A9C_ch2dbaddy[];

    return (OSThread *) D_80800A9C_ch2dbaddy;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/2dbaddy/func_8080000C_ch2dbaddy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/2dbaddy/func_808000A0_ch2dbaddy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/2dbaddy/func_808002A8_ch2dbaddy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/2dbaddy/func_808003C4_ch2dbaddy.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/2dbaddy/func_808004A8_ch2dbaddy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/2dbaddy/func_808004F4_ch2dbaddy.s")

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
