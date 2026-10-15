#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mole/y/func_80800000_chmoley.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mole/y/func_808000AC_chmoley.s")

/* extern */

s32 func_80800190_chmoley(Actor *arg0) {
    s32 func_80101DDC(Actor *);
    s32 func_80101E14(Actor *, f32);
    s32 func_801022E4(Actor *);
    struct anctrl_s *func_80104248(void *);

    if (func_80104248(arg0) == 0) {
        return 1;
    }
    switch (func_801022E4(arg0)) {
    case 0x2BC:
    case 0x2C8:
        return 1;
    case 0x2BF:
        if (func_80101E14(arg0, 0.0909f) != 0) {
            arg0->unk64_19 = 1;
        } else if (func_80101E14(arg0, 0.8295f) != 0) {
            arg0->unk64_19 = 0;
        }
        if (func_80101DDC(arg0)) {
            return 1;
        }
        break;
    default:
        if (func_80101E14(arg0, 0.999f)) {
            return 1;
        }
        break;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mole/y/func_80800274_chmoley.s")

void func_8080088C_chmoley(Actor* arg0) 
{
    if (func_80100094(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
void func_808008C0_chmoley(Actor *arg0) { void _suexpression_entrypoint_12(void *, f32, f32); f32 zero = 0.0f; arg0->scale = 0.5f; _suexpression_entrypoint_7(arg0, 1, 0x6F); _suexpression_entrypoint_12(func_80100094(arg0, 1), zero, zero); }

void chmoley_entrypoint_0(void *arg0, s32 arg1) {
    struct Fields {
        u8 pad[0x79];
        u8 upper : 4;
        u8 lower : 4;
    };
    ((struct Fields *)arg0)->upper = arg1;
}

/* extern */

void chmoley_entrypoint_1(Actor *arg0, s32 arg1) {
    void func_800FCA90(u32);
    void func_800FCAE0(u32, u32, u32);
    void func_80102424(Actor *, s32);

    if (arg1 != arg0->unk70_10) {
        if (arg0->unk70_10 == 5) {
            func_800FCAE0(0x3A, 0, 0x7D0);
            func_800FCA90(0x3A);
        }
        func_80102424(arg0, arg1);
        if (arg0->unk70_10 != 1) {
            if (arg0->unk70_10 != 5) {
                arg0->unk64_16 = 1;
                return;
            }
            func_800FCAE0(0x3A, -1, 0x7D0);
            return;
        }
        arg0->unk64_16 = 0;
    }
}

OSThread *chmoley_entrypoint_2(void)
{
    extern u8 D_80800C10_chmoley[];

    return (OSThread *) D_80800C10_chmoley;
}
