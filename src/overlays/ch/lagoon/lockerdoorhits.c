#include "common.h"

void func_80800000_chlagoonlockerdoorhits(Actor *arg0) {
    s32 func_800DA298(s32);
    s32 func_800DA564(s32, s32);
    void func_800FFAB0(Actor *);
    void func_80103014(u8 *);
    extern s16 D_808003F8_chlagoonlockerdoorhits[];
    s32 sp1C;
    s16 *temp_v0;

    sp1C = arg0->unk74_7 - 0x33;
    if ((func_800DA298(0x3A8) != 0) && ((func_800DA564(0x3A4, 4) + 0x32) == (s32)arg0->unk74_7)) {
        func_800FFAB0(arg0);
        return;
    }
    temp_v0 = D_808003F8_chlagoonlockerdoorhits + sp1C * 3;
    arg0->position[0] = temp_v0[0] * 100.0f + 8500.0f;
    arg0->position[1] = temp_v0[1] * 100.0f + -8000.0f;
    arg0->position[2] = temp_v0[2] * 100.0f + -8200.0f;
    func_80103014(arg0);
}

s32 func_8080010C_chlagoonlockerdoorhits(Actor *arg0, s32 arg1, s32 arg2) {
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    void func_800C4AF0(f32 *, void *);
    void func_800DA3B8(s32, s32);
    void func_800FFAB0(Actor *);
    void func_808001B0_chlagoonlockerdoorhits(void);
    void func_8080022C_chlagoonlockerdoorhits(Actor *);
    extern s32 D_808003A0_chlagoonlockerdoorhits[];
    extern s32 D_808003CC_chlagoonlockerdoorhits;

    if (arg1 == 0x40) {
        func_800DA3B8(0x3A8, 1);
        func_800FFAB0(arg0);
        func_800C4AF0(arg0->position, &D_808003CC_chlagoonlockerdoorhits);
        func_800BABB8(0, arg0->position, arg0->position, arg0->scale, D_808003A0_chlagoonlockerdoorhits);
        func_808001B0_chlagoonlockerdoorhits();
        return 1;
    }
    if (arg1 == 0x95) {
        func_8080022C_chlagoonlockerdoorhits(arg0);
        return 1;
    }
    return 0;
}

/* extern */

void func_808001B0_chlagoonlockerdoorhits(void) {
    void func_800BF744(s32, s32);
    s32 func_800DA298(s32);
    s32 func_800DA564(s32, s32);
    s32 sp24[2];
    s32 sp1C;
    sp24[1] = func_800DA564(0x3A4, 4);
    func_800BF744((sp1C = sp24[1] * 2) + 9, func_800DA298(0x3A8) ? 0 : 1);
    func_800BF744(sp1C + 0xA, func_800DA298(0x3A8) ? 0 : 0xF);
}

void func_8080022C_chlagoonlockerdoorhits(Actor *arg0) {
    void func_800BF744(s32, s32);
    s32 func_800DA564(s32, s32);
    s32 func_800DA7A8(s32, s32, s32);
    s32 func_800DC090(void);
    s32 func_80103140(Actor *, u32, u16);
    void func_8010A590(Actor *);
    void func_808001B0_chlagoonlockerdoorhits(void);
    extern u16 D_808003E4_chlagoonlockerdoorhits[];
    extern u8 D_80800430_chlagoonlockerdoorhits[];
    s32 sp2C;
    s32 temp_v0;
    s32 var_s0;
    u8 *var_s2;
    s32 var_s1;

    sp2C = arg0->unk74_7 - 0x33;
    temp_v0 = func_800DA564(0x3A4, 4);
    var_s0 = temp_v0;
    if (temp_v0 == 0) {
        if ((temp_v0 == 0) || (temp_v0 >= 0xA)) {
            do {
loop_3:
                var_s0 = func_800DC090() & 0xF;
                func_800DA7A8(0x39F, func_800DC090() & 0x1F, 5);
                if (var_s0 == 0) {
                    goto loop_3;
                }
            } while (var_s0 >= 0xA);
        }
        func_800DA7A8(0x3A4, var_s0, 4);
    }
    temp_v0 = func_800DA564(0x39F, 5);
    var_s1 = 0xB; var_s2 = temp_v0 + D_80800430_chlagoonlockerdoorhits;
    var_s0 = 0xC;
    do {
        func_800BF744(var_s1, 1U);
        func_800BF744(var_s0, *var_s2);
        var_s0 += 2;
        var_s1 += 2;
        var_s2 += 1;
    } while (var_s0 != 0x1E);
    func_808001B0_chlagoonlockerdoorhits();
    temp_v0 = func_800DA564(0x3A4, 4) + 0x32;
    if (arg0->unk74_7 == temp_v0) {
        func_8010A590(arg0);
    }
    func_80103140(arg0, D_808003E4_chlagoonlockerdoorhits[sp2C], 0);
}

OSThread *chlagoonlockerdoorhits_entrypoint_0(void)
{
    extern u8 D_8080045C_chlagoonlockerdoorhits[];

    return (OSThread *) D_8080045C_chlagoonlockerdoorhits;
}
