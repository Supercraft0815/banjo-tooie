#include "common.h"

OSThread *chhillbilly_entrypoint_0(void)
{
    extern u8 D_80800C60_chhillbilly[];

    return (OSThread *) D_80800C60_chhillbilly;
}

/* extern */

void func_8080000C_chhillbilly(void *arg0) {
    s32 _sucoaster_entrypoint_0(void *, s32);
    u8 *_sucoaster_entrypoint_3();
    void func_800EE940(s16 *dst, f32 *src);
    u8 *sp1C;
    f32 *volatile sp18;
    f32 *position;

    if (_sucoaster_entrypoint_0(arg0, 0xC) != 0) {
        sp1C = _sucoaster_entrypoint_3(arg0);
        func_800EE940((s16 *)(sp1C + 6), sp18 = (f32 *)((u8 *)arg0 + 4));
        position = sp18;
        func_800EE940((s16 *)sp1C, position);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hillbilly/func_80800064_chhillbilly.s")

/* extern */

void func_80800298_chhillbilly(Actor *arg0, u8 *arg1) { s32 _sucoaster_entrypoint_20(Actor *, u8 *); s32 var_a1; if ((u32)(arg0->unk0->unk28 << 18) >> 31) { var_a1 = 0; } else { var_a1 = 1; } func_800DF744(3, var_a1); _sucoaster_entrypoint_20(arg0, arg1); }

/* extern */

s32 func_808002F0_chhillbilly(f32 *arg0) {
    u8 *_sucoaster_entrypoint_3();
    void func_800EE88C(f32 *, s16 *);
    f32 func_800EFC7C(f32 *, f32 *);
    f32 sp1C[3];

    func_800EE88C(sp1C, (s16 *)(_sucoaster_entrypoint_3() + 6));
    return func_800EFC7C(arg0 + 1, sp1C) < 10000.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hillbilly/func_80800348_chhillbilly.s")

/* extern */

s32 func_808003C8_chhillbilly(u8 *arg0) {
    s32 _subaddiejoy_entrypoint_6(u8 *, s32);
    s32 _sucoaster_entrypoint_13();
    struct Flags {
        u8 pad[0x64];
        u32 : 2;
        u32 flag : 1;
        u32 : 29;
        u8 pad68[0xC];
        u8 : 7;
        u8 flag74 : 1;
    };
    if (((struct Flags *)arg0)->flag) {
        return _subaddiejoy_entrypoint_6(arg0, 0) == 1;
    }
    if (((struct Flags *)arg0)->flag74) {
        return 1;
    }
    return _sucoaster_entrypoint_13() == 1;
}

/* extern */

s32 func_8080042C_chhillbilly(u8 *arg0) {
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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hillbilly/func_8080046C_chhillbilly.s")

/* extern */

void func_808004D0_chhillbilly(Actor *arg0) { s32 _subaddieDll_entrypoint_3(Actor *); s32 _sucoaster_entrypoint_10(Actor *, s32); s32 _sucoaster_entrypoint_6(Actor *, f32, s32); s32 var_a2; if ((arg0->unk70_10 == 2) || (arg0->unk70_10 == 3) || (arg0->unk70_10 == 8)) { if (_subaddieDll_entrypoint_3(arg0) != 0) { var_a2 = 0x15; } else { var_a2 = 0xE; } _sucoaster_entrypoint_6(arg0, 200.0f, var_a2); _sucoaster_entrypoint_10(arg0, var_a2); } }

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hillbilly/func_80800540_chhillbilly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hillbilly/func_808006B4_chhillbilly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hillbilly/func_80800894_chhillbilly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hillbilly/func_80800944_chhillbilly.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/hillbilly/func_808009D8_chhillbilly.s")
