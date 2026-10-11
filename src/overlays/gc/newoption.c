#include "gc/newoption.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/func_80800000_gcnewoption.s")

s32 func_80800038_gcnewoption(void *arg0, s32 arg1) {
    s32 temp_v1;

    temp_v1 = arg1 - (*(s16 *)((s8 *)(arg0) + (8)));
    if (temp_v1 >= (*(s16 *)((s8 *)(arg0) + (2)))) {
        return -1;
    }
    if (temp_v1 < 0) {
        return -1;
    }
    return temp_v1;
}

s32 func_80800070_gcnewoption(void *arg0, s32 arg1) {
    return (*(s16 *)((s8 *)(arg0) + (8))) + arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_1.s")

int gcnewoption_entrypoint_2(void)
{
	return 0x260;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_6.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_7.s")

void gcnewoption_entrypoint_8(s16 *arg0, s32 arg1) {
    arg0[1] = arg1;
}

void gcnewoption_entrypoint_9(s16 *arg0, s32 arg1) {
    arg0[2] = arg1;
}

void gcnewoption_entrypoint_10(void *arg0, s32 arg1) {
    struct Fields {
        u8 padding[0x1C];
        u8 upper : 5;
        u8 value : 3;
    };
    ((struct Fields *)arg0)->value = arg1;
}

void gcnewoption_entrypoint_11(s16 *arg0) {
    *arg0 = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/func_80800D28_gcnewoption.s")

void func_8080103C_gcnewoption(u8 *arg0)
{
  s32 _gczoombox_entrypoint_0(s32);
  s16 var_v0;
  s32 temp_a0;
  s32 temp_a0_2;
  s32 var_s1;
  u8 *var_s0;
  var_v0 = *((s16 *) (((s8 *) arg0) + 2));
  var_s0 = arg0;
  var_s1 = 0;
  if (var_v0 > 0)
  {
    do
    {
      temp_a0 = *((s32 *) (((s8 *) var_s0) + 0x3C));
      if (temp_a0 != 0)
      {
        _gczoombox_entrypoint_0(temp_a0);
        *((s32 *) (((s8 *) var_s0) + 0x3C)) = 0;
        *((s8 *) (((s8 *) (arg0 + var_s1)) + 0x94)) = -1;
        var_v0 = *((s16 *) (((s8 *) arg0) + 2));
      }
      var_s1 += 1;
      var_s0 += 4;
    }
    while (var_s1 < var_v0);
  }
  temp_a0_2 = *((s32 *) (((s8 *) arg0) + 0x20));
  if (temp_a0_2 != 0)
  {
    _gczoombox_entrypoint_0(temp_a0_2);
    *((s32 *) (((s8 *) arg0) + 0x20)) = 0;
    var_v0 = 0xFF;
    *((s8 *) (((s8 *) arg0) + 0x24)) = var_v0;
  }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/func_808010E0_gcnewoption.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/func_80801114_gcnewoption.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/func_80801190_gcnewoption.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_12.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_13.s")

void gcnewoption_entrypoint_14(void *arg0, s16 arg1, s16 arg2, s16 arg3, f32 arg4) {
    (*(s16 *)((s8 *)(arg0) + (0x26))) = arg1;
    (*(s16 *)((s8 *)(arg0) + (0x28))) = arg2;
    (*(s16 *)((s8 *)(arg0) + (0x2A))) = arg3;
    (*(f32 *)((s8 *)(arg0) + (0x2C))) = arg4;
    (*(f32 *)((s8 *)(arg0) + (0x30))) = arg4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/func_808012C8_gcnewoption.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_15.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_16.s")

s32 gcnewoption_entrypoint_17(s32 arg0, s32 arg1) {
    return (*(s16 *)((s8 *)(arg0) + ((arg1 * 2) + 0xB0))) == 0;
}

s32 gcnewoption_entrypoint_18(s32 arg0, s32 arg1) {
    return ((s16 *)arg0)[arg1 + 0x58] == 1;
}

s32 gcnewoption_entrypoint_19(s32 arg0, s32 arg1) {
    return ((*(s16 *)((s8 *)(arg0) + ((arg1 * 2) + 0xB0))) + 1) == 0;
}

s16 gcnewoption_entrypoint_20(s32 arg0, s32 arg1) {
    return ((s16 *)arg0)[arg1 + 0x58];
}

void gcnewoption_entrypoint_21(s32 arg0, s32 arg1) {
    (*(s16 *)((s8 *)((arg0 + (arg1 * 2))) + (0xB0))) = 0;
}

void gcnewoption_entrypoint_22(s32 arg0, s32 arg1) {
    (*(s16 *)((s8 *)((arg0 + (arg1 * 2))) + (0xB0))) = 1;
}

void gcnewoption_entrypoint_23(s32 arg0, s32 arg1) {
    (*(s16 *)((s8 *)((arg0 + (arg1 * 2))) + (0xB0))) = -1;
}

void gcnewoption_entrypoint_24(s32 arg0, s32 arg1, s32 arg2) {
    (*(s16 *)((s8 *)((arg0 + (arg1 * 2))) + (0xB0))) = arg2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_25.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_26.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_27.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_28.s")

void gcnewoption_entrypoint_29(void *arg0, s32 arg1) {
    struct Flags {
        u8 padding[0x1D];
        u8 upper : 4;
        u8 flag : 1;
        u8 lower : 3;
    };
    ((struct Flags *)arg0)->flag = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_30.s")

void gcnewoption_entrypoint_31(s32 arg0, s32 arg1, s16 arg2) {
    (*(s16 *)((s8 *)((arg0 + (arg1 * 2))) + (0x1DC))) = arg2;
}

/* extern */

void gcnewoption_entrypoint_32(void *arg0, s16 arg1) {
    s32 _gczoombox_entrypoint_37(s32, s16);
    (*(s16 *)((s8 *)(arg0) + (0x236))) = arg1;
    _gczoombox_entrypoint_37((*(s32 *)((s8 *)(arg0) + (0x20))), arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_33.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/func_808019D0_gcnewoption.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/func_80801B5C_gcnewoption.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/func_80801E68_gcnewoption.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/func_808020C4_gcnewoption.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/func_808022E0_gcnewoption.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/func_8080241C_gcnewoption.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/func_80802534_gcnewoption.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/func_80802674_gcnewoption.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/func_808027DC_gcnewoption.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/func_80802998_gcnewoption.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/func_80802A9C_gcnewoption.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_35.s")

void gcnewoption_entrypoint_36(void *arg0) {
    struct Flags {
        u8 pad[0x1C];
        u8 upper : 3;
        u8 enabled : 1;
        u8 lower : 4;
    };
    ((struct Flags *)arg0)->enabled = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/func_80802B24_gcnewoption.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_37.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_38.s")

s32 gcnewoption_entrypoint_39(u8 *arg0)
{
  s32 _gczoombox_entrypoint_41(s32, s32);
  s32 func_80800000_gcnewoption(u8 *, s32);
  s32 func_80802A9C_gcnewoption(u8 *);
  s32 sp24;
  s16 temp_v0;
  temp_v0 = *((s16 *) (((s8 *) arg0) + 0));
  if ((temp_v0 == 5) || (temp_v0 == 9))
  {
    sp24 = func_80800000_gcnewoption(arg0, func_80800038_gcnewoption(arg0, (s32) (*((s16 *) (((s8 *) arg0) + 6)))));
    func_80802A9C_gcnewoption(arg0);
    *((s16 *) (((s8 *) arg0) + 0)) = 0xA;
    _gczoombox_entrypoint_41(*((s32 *) (((s8 *) (((0, arg0)) + (sp24 * 4))) + 0x3C)), 0x42340000);
    return 1;
  }
  return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_40.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_41.s")

void gcnewoption_entrypoint_42(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)arg0 + 24) = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_43.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/newoption/gcnewoption_entrypoint_44.s")

s32 gcnewoption_entrypoint_45(s16 *arg0) {
    return arg0[3];
}

void gcnewoption_entrypoint_46(s8 *arg0, s32 arg1) {
    arg0[592] = arg1;
}

s32 gcnewoption_entrypoint_47(void *arg0) {
    return (*(u8 *)((s8 *)(arg0) + (0x24))) == 3;
}

int gcnewoption_entrypoint_48(s16 *arg0) {
    return *arg0 >= 3 && *arg0 < 0xB;
}

void gcnewoption_entrypoint_49(void *arg0, s32 arg1) {
    struct Flags {
        u8 padding[0x1D];
        u8 upper : 6;
        u8 flag : 1;
        u8 lower : 1;
    };
    ((struct Flags *)arg0)->flag = arg1;
}
