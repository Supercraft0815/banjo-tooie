#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/wandglow/func_80800000_chwandglow.s")

void func_808000E8_chwandglow(void *arg0) {
    (*(s32 (**)(s32, s32, void *))((s8 *)(arg0) + (0x30)))((*(s32 *)((s8 *)(arg0) + (0))), (*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF, arg0);
}

s32 func_8080011C_chwandglow(s32 arg0, s32 arg1) {
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 temp;
    struct StateBits {
        u8 pad[0x72];
        u8 state : 6;
        u8 other : 2;
    };

    switch (arg1) {
    case 2:
        *(f32 *)(arg0 + 0x28) = 0.4f;
        *(f32 *)(arg0 + 0x2C) = 0.0f;
        break;
    case 3:
        *(f32 *)(arg0 + 0x2C) = 1.0f;
        *(f32 *)(arg0 + 0x38) = 1.0f;
        break;
    case 4:
        *(f32 *)(arg0 + 0x38) = 1.0f;
        temp = func_800F10B4(*(f32 *)(arg0 + 0x2C), 0.0f, 1.0f, 0.0f, 0.3f);
        *(f32 *)(arg0 + 0x28) = temp;
        if (temp == 0.0f) {
            *(f32 *)(arg0 + 0x28) += 0.01f;
        }
        break;
    case 5:
        *(f32 *)(arg0 + 0x2C) = 0.0f;
        break;
    }
    ((struct StateBits *)arg0)->state = arg1;
}

void func_80800218_chwandglow(s32 arg0) {
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    u8 func_800D9078(f32 *);
    int func_800FFA88();
    struct StateBits {
        u8 pad[0x72];
        u16 state : 6;
        u16 other : 10;
    };

    switch (((struct StateBits *)arg0)->state) {
    case 2:
        *(f32 *)(arg0 + 0x2C) = func_800F10B4(*(f32 *)(arg0 + 0x28), 0.0f, 0.4f, 1, 0.0f);
        if (func_800D9078((f32 *)(arg0 + 0x28))) {
            func_8080011C_chwandglow(arg0, 3);
        }
        return;
    case 3:
        if (*(f32 *)(arg0 + 0x38) == 1.0f) {
            *(f32 *)(arg0 + 0x38) = 0.75f;
            return;
        } else {
            *(f32 *)(arg0 + 0x38) = 1.0f;
        }
        return;
    case 4:
        *(f32 *)(arg0 + 0x2C) = func_800F10B4(*(f32 *)(arg0 + 0x28), 0.0f, 0.3f, 0.0f, 1);
        if (func_800D9078((f32 *)(arg0 + 0x28))) {
            func_8080011C_chwandglow(arg0, 5);
        }
        break;
    case 5:
        func_800FFA88(*(s32 *)arg0);
        break;
    }
}

/* extern */

s32 chwandglow_entrypoint_0(s32 arg0, s32 arg1) {
    Actor *actor;
    f32 sp18[3];

    func_800F5A2C(arg0, 6, sp18);
    actor = func_80108474(0x164, sp18, 0);
    actor->unk6C_0 = arg0;
    actor->actorData[6] = arg1;
    func_8080011C_chwandglow((s32) actor, 2);
    return (s32)actor->unk0;
}

void chwandglow_entrypoint_1()
{
    func_800FFA88();
}

/* extern */

void chwandglow_entrypoint_2(void) {
    s32 func_8080011C_chwandglow(s32, s32);
    s32 func_80106790();
    func_8080011C_chwandglow(func_80106790(), 4);
}

OSThread *chwandglow_entrypoint_3(void)
{
    extern u8 D_80800410_chwandglow[];

    return (OSThread *) D_80800410_chwandglow;
}
