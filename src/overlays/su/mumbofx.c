#include "common.h"

void sumumbofx_entrypoint_0(Actor *arg0, u32 arg1, s32 arg2, s16 arg3) {
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    u32* func_80100074(Actor*, u32, u32);
    void* func_80100094(Actor*, u32);
    u8 *sp1C;
    u8 *temp_v0;

    func_80100074(arg0, arg1, (arg2 * 0x2C) + 0x64);
    temp_v0 = func_80100094(arg0, arg1);
    sp1C = temp_v0;
    (*(s32 *)((s8 *)(temp_v0) + (0))) = (s32) arg3;
    (*(s16 *)((s8 *)(temp_v0) + (0x58))) = (s16) arg2;
    func_800EE7F8(temp_v0 + 0x1C, arg0->position);
    (*(s8 *)((s8 *)(sp1C) + (0x63))) = 0;
}

void sumumbofx_entrypoint_1(Actor *arg0, u32 arg1) {
    void func_800FCA90(u32);
    void func_800FCAE0(u32, u32, u32);
    u32 *func_80100074(Actor *, u32, u32);
    void *func_80100094(Actor *, u32);
    void sumumbofx_entrypoint_13(void *);
    struct {
        u8 pad0[0x5E];
        s16 unk5E;
        u8 unk60;
        u8 unk61;
        u8 unk62;
    } *data;
    u8 state;

    data = func_80100094(arg0, arg1);
    if (data->unk5E != 0) {
        sumumbofx_entrypoint_13(data);
    }
    state = data->unk62;
    if ((state != 1) && (state == 2)) {
        func_800FCAE0(0x1C, 0, 0x4E20);
        func_800FCA90(0x1C);
    }
    func_80100074(arg0, arg1, 0);
}

/* extern */

void sumumbofx_entrypoint_2(u8 *arg0) {
    f32 func_800DC178(f32, f32);
    f32 temp_f0;
    s32 var_s1;
    u8 *var_s0;

    (*(s16 *)((s8 *)(arg0) + (0x5A))) = 0;
    (*(s16 *)((s8 *)(arg0) + (0x5C))) = 0;
    (*(u8 *)((s8 *)(arg0) + (0x60))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x60))) & 0xFF01);
    (*(s16 *)((s8 *)(arg0) + (0x5E))) = 0;
    (*(s8 *)((s8 *)(arg0) + (0x61))) = 0;
    (*(s8 *)((s8 *)(arg0) + (0x62))) = 2;
    (*(s32 *)((s8 *)(arg0) + (0x54))) = -1;
    var_s0 = arg0 + 0x64;
    var_s1 = 0;
    (*(f32 *)((s8 *)(arg0) + (0x10))) = 0.0f;
    (*(f32 *)((s8 *)(arg0) + (0x14))) = 0.0f;
    (*(f32 *)((s8 *)(arg0) + (0x18))) = 0.0f;
    (*(f32 *)((s8 *)(arg0) + (4))) = 0.0f;
    (*(f32 *)((s8 *)(arg0) + (0xC))) = 1.0f;
    if ((*(s16 *)((s8 *)(arg0) + (0x58))) > 0) {
        do {
            (*(f32 *)((s8 *)(var_s0) + (0x1C))) = 0.0f;
            temp_f0 = func_800DC178(0.4f, 0.8f);
            (*(f32 *)((s8 *)(var_s0) + (0x24))) = temp_f0;
            (*(f32 *)((s8 *)(var_s0) + (0x20))) = func_800DC178(0, temp_f0);
            (*(f32 *)((s8 *)(var_s0) + (0))) = func_800DC178(0.0f, 359.0f);
            (*(f32 *)((s8 *)(var_s0) + (4))) = 0.0f;
            (*(f32 *)((s8 *)(var_s0) + (0xC))) = func_800DC178(8.0f, 16.0f);
            (*(f32 *)((s8 *)(var_s0) + (8))) = func_800DC178(8.0f, 16.0f);
            var_s1 += 1;
            var_s0 += 0x2C;
        } while (var_s1 < (*(s16 *)((s8 *)(arg0) + (0x58))));
    }
}

void sumumbofx_entrypoint_3(u8 *arg0, f32 arg1)
{
  f32 func_800DC178(f32, f32);
  f32 temp_f0;
  s32 var_s1;
  u8 *var_s0;
  var_s0 = arg0 + 0x64;
  var_s1 = 0;
  if ((*((s16 *) (((s8 *) arg0) + 0x58))) > 0)
  {
    do
    {
      temp_f0 = func_800DC178(0.4f, 0.8f);
      *((f32 *) (((s8 *) var_s0) + 0x24)) = temp_f0;
      *((f32 *) (((s8 *) var_s0) + 0x20)) = func_800DC178(0.0, temp_f0);
      *((f32 *) (((s8 *) var_s0) + 0)) = func_800DC178(0.0f, 359.0f);
      *((f32 *) (((s8 *) var_s0) + 4)) = func_800DC178(0.0f, arg1);
      *((f32 *) (((s8 *) var_s0) + 0xC)) = func_800DC178(8.0f, 16.0f);
      *((f32 *) (((s8 *) var_s0) + 8)) = func_800DC178(8.0f, 16.0f);
      var_s1 += 1;
      var_s0 += 0x2C;
    }
    while (var_s1 < (*((s16 *) (((s8 *) arg0) + 0x58))));
  }
}

void sumumbofx_entrypoint_4(u8 *arg0) {
    struct FlagByte {
        u8 unused : 7;
        u8 flag : 1;
    };
    s32 var_v1;
    u8 *var_v0;

    var_v0 = arg0 + 0x64;
    var_v1 = 0;
    (*(f32 *)((s8 *)(arg0) + (8))) = 0.0f;
    if ((*(s16 *)((s8 *)(arg0) + (0x58))) > 0) {
        do {
            (*(f32 *)((s8 *)(var_v0) + (0x28))) = 1.0f;
            var_v1 += 1;
            var_v0 += 0x2C;
            (*(f32 *)((s8 *)(arg0) + (8))) = (f32) ((*(f32 *)((s8 *)(arg0) + (8))) + 1.0f);
        } while (var_v1 < (*(s16 *)((s8 *)(arg0) + (0x58))));
    }
    if ((*(f32 *)((s8 *)(arg0) + (4))) != 1.0f) {
        (*(f32 *)((s8 *)(arg0) + (4))) = 1.0f;
        ((struct FlagByte *)(arg0 + 0x60))->flag = 1;
    }
}

void func_808003E4_sumumbofx(u8 *arg0, f32 arg1, f32 arg2) {
    void func_800EEB9C(f32[3], f32, f32);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    void func_8010D254(f32 *);
    f32 sp34[3];
    f32 sp28[3];

    func_8010D254(sp28);
    func_800EEB9C(sp34, *(f32 *)(arg0 + 0), arg2);
    sp34[1] = *(f32 *)(arg0 + 4) * 0.75f;
    while (arg1 < sp34[1]) {
        sp34[1] -= arg1;
    }
    func_800EF04C(sp34, sp28);
    func_800EF334(sp34, 1.0f - *(f32 *)(arg0 + 0x28));
    func_800EF334((f32 *)(arg0 + 0x10), *(f32 *)(arg0 + 0x28));
    func_800EF04C((f32 *)(arg0 + 0x10), sp34);
}

/* extern */

s32 sumumbofx_entrypoint_5(u8 *arg0, f32 arg1) {
    f32 func_800D8FF8(void);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    s32 var_a1;
    s32 var_t0;
    u8 *var_v0_2;

    var_t0 = 0;
    var_v0_2 = arg0 + 0x64;
    var_a1 = 0;
    (*(f32 *)((s8 *)(arg0) + (8))) = 0.0f;
    if ((*(s16 *)((s8 *)(arg0) + (0x58))) > 0) {
        do {
            if ((*(s16 *)((s8 *)(arg0) + (0x5A))) >= var_a1) {
                if ((*(f32 *)((s8 *)(var_v0_2) + (0x28))) < 0.98f) {
                    f32 temp_f2;
                    temp_f2 = (1.0f - (*(f32 *)((s8 *)(var_v0_2) + (0x28)))) * 0.075f;
                    (*(f32 *)((s8 *)(var_v0_2) + (0x28))) += temp_f2 < 0.02f ? 0.02f : temp_f2;
                } else {
                    (*(f32 *)((s8 *)(var_v0_2) + (0x28))) = 1.0f;
                    var_t0 += 1;
                }
            }
            var_a1 += 1;
            (*(f32 *)((s8 *)(arg0) + (8))) += (*(f32 *)((s8 *)(var_v0_2) + (0x28)));
            var_v0_2 += 0x2C;
        } while (var_a1 < (*(s16 *)((s8 *)(arg0) + (0x58))));
    }
    (*(s16 *)((s8 *)(arg0) + (0x5A))) = (s16) (s32) func_800F10B4((*(f32 *)((s8 *)(arg0) + (0x18))), 0.0f, arg1, 0.0f, (f32) (*(s16 *)((s8 *)(arg0) + (0x58))));
    (*(f32 *)((s8 *)(arg0) + (0x18))) += func_800D8FF8();
    if (var_t0 < (*(s16 *)((s8 *)(arg0) + (0x58)))) {
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/mumbofx/func_8080060C_sumumbofx.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/mumbofx/sumumbofx_entrypoint_6.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/mumbofx/sumumbofx_entrypoint_7.s")

void sumumbofx_entrypoint_8(u8 *arg0, s32 arg1) {
    s32 func_800D674C(s32);
    void func_800E24D8(s32);
    void func_800E2588(u32);
    s32 func_800E2594(s32, s32);
    s32 func_800E2720(s32, s32, s32, f32 *, f32 *, s32);
    void func_800E2A14(s32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    struct Vec { s32 x, y, z; };
    extern struct Vec D_808014D0_sumumbofx;
    struct Vec sp74;
    f32 sp68[3];
    f32 temp_f0;
    s32 temp_s0;
    s32 var_s1;
    u8 *var_s0;

    sp74 = D_808014D0_sumumbofx;
    *(s8 *)(arg0 + 0x61) = 1;
    temp_s0 = func_800D674C(*(s32 *)arg0);
    func_800E2588(2);
    func_800E2594(arg1, temp_s0);
    func_800E24D8(1);
    var_s0 = arg0 + 0x64;
    var_s1 = 0;
    if (*(s16 *)(arg0 + 0x58) > 0) {
        do {
            temp_f0 = *(f32 *)(var_s0 + 0x1C);
            if (temp_f0 > 0.005f) {
                func_800EFA4C(sp68, temp_f0, temp_f0, temp_f0);
                func_800E2720(arg1, 0, 0, (f32 *)(var_s0 + 0x10), sp68, (s32) ((*(f32 *)(arg0 + 4) * 127.0f) + 128.0f));
            }
            var_s1 += 1;
            var_s0 += 0x2C;
        } while (var_s1 < *(s16 *)(arg0 + 0x58));
    }
    func_800E2A14(arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/mumbofx/sumumbofx_entrypoint_9.s")

s32 sumumbofx_entrypoint_10(u8 *arg0) {
    return (s32) (255.0f - (((*(f32 *)((s8 *)(arg0) + (8))) / (f32) (*(s16 *)((s8 *)(arg0) + (0x58)))) * (*(f32 *)((s8 *)(arg0) + (4))) * 255.0f));
}

/* extern */

void sumumbofx_entrypoint_11(void *arg0) {
    s32 func_800C8CB8(s16);
    func_800C8CB8((*(s16 *)((s8 *)(arg0) + (0x5E))));
}

void func_80800F8C_sumumbofx(u8 *arg0) {
    s32 func_800C8E84(s32, s32 *);
    void func_800F3214(s32, s32, s32, f32);
    struct Vec { s32 x, y, z; };
    extern struct Vec D_808014DC_sumumbofx;
    s32 sp24[3];
    struct Vec sp18;

    sp18 = D_808014DC_sumumbofx;
    func_800F3214((s32) sp24, (s32) &sp18, (s32) (arg0 + 0x3C), *(f32 *) (arg0 + 4));
    func_800C8E84(*(s16 *)(arg0 + 0x5E), sp24);
}

/* extern */

void sumumbofx_entrypoint_12(u8 *arg0, s32 arg1, f32 *arg2, s32 *arg3) {
    void sumumbofx_entrypoint_11();
    func_800EE830((s32 *) (arg0 + 0x3C), arg3);
    (*(s16 *)((s8 *)(arg0) + (0x5E))) = func_800C8A98();
    func_80800F8C_sumumbofx(arg0);
    sumumbofx_entrypoint_11(arg0, arg1);
    func_800C8D4C((s32) (*(s16 *)((s8 *)(arg0) + (0x5E))), arg2);
}

/* extern */

void sumumbofx_entrypoint_13(void *arg0) {
    s32 func_800C8B84(s16);
    func_800C8B84((*(s16 *)((s8 *)(arg0) + (0x5E))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/mumbofx/sumumbofx_entrypoint_14.s")

void sumumbofx_entrypoint_15(void *arg0, f32 arg1) { void sumumbofx_entrypoint_20(void *, f32); arg0 = arg0; ((u8 *)arg0)[0x60] = (((u8 *)arg0)[0x60] & 0xFF01) | 2; sumumbofx_entrypoint_20(arg0, arg1); }

void sumumbofx_entrypoint_16(void *arg0, f32 arg1) { void sumumbofx_entrypoint_20(void *, f32); ((u8 *)arg0)[0x60] = (((u8 *)arg0)[0x60] & 0xFF01) | 4; sumumbofx_entrypoint_20(arg0, arg1); }

void sumumbofx_entrypoint_17(void *arg0, f32 arg1) {
    void sumumbofx_entrypoint_20(void *, f32);
    ((u8 *)arg0)[0x60] = ((u8 *)arg0)[0x60] & 0xFF01;
    sumumbofx_entrypoint_20(arg0, arg1);
}

void sumumbofx_entrypoint_18(void *arg0, f32 arg1) { void sumumbofx_entrypoint_20(void *, f32); ((u8 *)arg0)[0x60] = (((u8 *)arg0)[0x60] & 0xFF01) | 6; sumumbofx_entrypoint_20(arg0, arg1); }

void sumumbofx_entrypoint_19(s8 *arg0, s32 arg1) {
    arg0[98] = arg1;
}

void sumumbofx_entrypoint_20(void *arg0, f32 arg1) {
    (*(f32 *)((s8 *)(arg0) + (0x10))) = arg1;
    (*(f32 *)((s8 *)(arg0) + (0x14))) = arg1;
}

f32 sumumbofx_entrypoint_21(f32 *arg0)
{
    return arg0[4];
}

f32 sumumbofx_entrypoint_22(f32 *arg0) {
    return arg0[1];
}

void sumumbofx_entrypoint_23(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)arg0 + 4) = arg1;
}

void sumumbofx_entrypoint_24(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)arg0 + 12) = arg1;
}

/* extern */

void sumumbofx_entrypoint_25(u8 *arg0, s32 arg1, s32 arg2) {
    (*(s32 *)((s8 *)(arg0) + (0x54))) = arg1;
    func_800EE830(arg0 + 0x48, arg2);
}

f32 sumumbofx_entrypoint_26(void *arg0) {
    return 1.0f - ((*(f32 *)((s8 *)(arg0) + (0x10))) / (*(f32 *)((s8 *)(arg0) + (0x14))));
}

s32 sumumbofx_entrypoint_27(f32 *arg0) {
    s32 result;

    result = sumumbofx_entrypoint_21(arg0) <= 0.0f;
    return result;
}

void sumumbofx_entrypoint_28(u8 *arg0, f32 *arg1, f32 arg2, f32 arg3) {
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    (*(s8 *)((s8 *)(arg0) + (0x63))) = 1;
    func_800EE7F8(arg0 + 0x28, arg1);
    (*(f32 *)((s8 *)(arg0) + (0x34))) = (f32) (arg2 * arg2);
    (*(f32 *)((s8 *)(arg0) + (0x38))) = (f32) (arg3 * arg3);
}
