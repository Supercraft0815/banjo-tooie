#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/gcmapsects_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/func_80800250_gcmapsects.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/func_8080035C_gcmapsects.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/func_808003F4_gcmapsects.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/func_808005D0_gcmapsects.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/gcmapsects_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/gcmapsects_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/gcmapsects_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/func_80800A08_gcmapsects.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/func_80800B58_gcmapsects.s")

/* extern */

void func_80800C54_gcmapsects(void *arg0) {
    s32 func_8080035C_gcmapsects(void *, s32);
    s32 func_808003F4_gcmapsects(void *, s32);
    s32 var_s0;

    var_s0 = 0;
    if ((s32) (*(u8 *)((s8 *)(arg0) + (0x77))) > 0) {
        do {
            func_808003F4_gcmapsects(arg0, var_s0);
            func_8080035C_gcmapsects(arg0, var_s0);
            var_s0 += 1;
        } while (var_s0 < (s32) (*(u8 *)((s8 *)(arg0) + (0x77))));
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/gcmapsects_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/gcmapsects_entrypoint_5.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/func_80800DC8_gcmapsects.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/gcmapsects_entrypoint_6.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/func_80801174_gcmapsects.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/func_80801320_gcmapsects.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/func_808013C0_gcmapsects.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/gcmapsects_entrypoint_7.s")

void gcmapsects_entrypoint_8(void *arg0) {
    *(u8 *)((u8 *)arg0 + 0x78) = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/func_80801554_gcmapsects.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/func_80801640_gcmapsects.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/func_80801724_gcmapsects.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/gcmapsects_entrypoint_9.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/gcmapsects_entrypoint_10.s")

/* extern */

void gcmapsects_entrypoint_11(s32 arg0, s32 arg1) {
    void *func_800BF704();
    void *temp_v0;

    temp_v0 = func_800BF704();
    (*(s8 *)((s8 *)(temp_v0) + (0x79))) = (s8) arg0;
    (*(s8 *)((s8 *)(temp_v0) + (0x7D))) = (s8) arg1;
}

/* extern */

void gcmapsects_entrypoint_12(s32 arg0) {
    void *func_800BF704();
    (*(s32 *)((s8 *)(func_800BF704()) + (0x6C))) = arg0;
}

/* extern */

void gcmapsects_entrypoint_13(s32 arg0) {
    void *func_800BF704();
    (*(s8 *)((s8 *)(func_800BF704()) + (0x80))) = (s8) arg0;
}

/* extern */

void gcmapsects_entrypoint_14(s32 arg0) {
    void *func_800BF704();
    (*(s8 *)((s8 *)(func_800BF704()) + (0x81))) = (s8) arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/gcmapsects_entrypoint_15.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/gcmapsects_entrypoint_16.s")

void gcmapsects_entrypoint_17(void *arg0)
{
  s32 func_800BF4DC(s32, u8, void *);
  s32 func_800BFF28();
  u8 *new_var;
  s32 func_800BFF4C();
  s32 func_80801640_gcmapsects();
  u8 temp_v0;
  func_80801640_gcmapsects();
  ;
  if ((*((u8 *) (((s8 *) arg0) + 0x7A))) != (*((u8 *) (((s8 *) arg0) + 0x7B))))
  {
    if ((*((u8 *) (((s8 *) arg0) + 0x7B))) != 0)
    {
      if (1)
      {
        func_800BFF4C();
      }
    }
    else
    {
      func_800BFF28();
    }
    *((u8 *) (((s8 *) arg0) + 0x7A)) = (u8) (*(new_var = (u8 *) (((s8 *) arg0) + 0x7B)));
  }
  func_800BF4DC(1, *((u8 *) (((s8 *) arg0) + 0x7E)), arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/gcmapsects_entrypoint_18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/gcmapsects_entrypoint_19.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/gcmapsects_entrypoint_20.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/gcmapsects_entrypoint_21.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/gcmapsects_entrypoint_22.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/gcmapsects_entrypoint_23.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/gcmapsects_entrypoint_24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/gcmapsects_entrypoint_25.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/gcmapsects_entrypoint_26.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/gcmapsects_entrypoint_27.s")
