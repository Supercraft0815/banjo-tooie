#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/gcmapsects_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/func_80800250_gcmapsects.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/func_8080035C_gcmapsects.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/func_808003F4_gcmapsects.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/func_808005D0_gcmapsects.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/gcmapsects_entrypoint_1.s")

void gcmapsects_entrypoint_2(s16 arg0, s32 arg1) {
    void *func_800BF704(void);
    struct { u8 pad[0x4C]; u8 other : 7; u8 flag : 1; } *temp_v1;

    temp_v1 = (*(s32 *)((s8 *)(func_800BF704()) + (0x68))) + (arg0 * 0x58);
    temp_v1->flag = arg1;
}

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

/* extern */

u32 gcmapsects_entrypoint_5(s32 arg0) {
    void *func_800BF704();
    void *temp_v0;

    if (arg0 == -1) {
        return 1U;
    }
    temp_v0 = func_800BF704();
    if ((*(u8 *)((s8 *)(temp_v0) + (0x77))) == 0) {
        return 1U;
    }
    return (u32) ((*(s32 *)((s8 *)(((*(s32 *)((s8 *)(temp_v0) + (0x68))) + (arg0 * 0x58))) + (0x4C))) * 2) >> 0x1F;
}

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

void gcmapsects_entrypoint_10(s32 arg0) {
    void *func_800BF704();
    void* heap_alloc(s32 size);
    u8 *temp_v0;
    u8 *sp1C;

    temp_v0 = func_800BF704();
    if (arg0 != 0) {
        (*(s8 *)((s8 *)(temp_v0) + (0x76))) = (s8) arg0;
        sp1C = temp_v0;
        (*(u8 **)((s8 *)(sp1C) + (0x68))) = heap_alloc((arg0 & 0xFF) * 0x58);
    }
}

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

/* extern */

void gcmapsects_entrypoint_16(void *arg0) {
    s32 heap_free(s32, void *);
    if (((*(u8 *)((s8 *)(arg0) + (0x77))) != 0) || ((*(u8 *)((s8 *)(arg0) + (0x76))) != 0)) {
        func_80800C54_gcmapsects(arg0);
        heap_free((*(s32 *)((s8 *)(arg0) + (0x68))), arg0);
        (*(s32 *)((s8 *)(arg0) + (0x68))) = 0;
        (*(u8 *)((s8 *)(arg0) + (0x77))) = 0U;
        (*(u8 *)((s8 *)(arg0) + (0x76))) = 0U;
        (*(s8 *)((s8 *)(arg0) + (0x78))) = 0;
        (*(s8 *)((s8 *)(arg0) + (0x7B))) = 1;
        (*(s8 *)((s8 *)(arg0) + (0x7E))) = 1;
        (*(s8 *)((s8 *)(arg0) + (0x7C))) = 0;
        (*(s8 *)((s8 *)(arg0) + (0x7F))) = 3;
        (*(f32 *)((s8 *)(arg0) + (0x70))) = 0.0f;
    }
}

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

int gcmapsects_entrypoint_24(void *arg0) {
    return (*(u8 *)((s8 *)arg0 + 0x82) != 0) &&
           ((*(s16 *)((s8 *)arg0 + 0x74) + 1) == 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/gcmapsects_entrypoint_25.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/gcmapsects_entrypoint_26.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/gcmapsects_entrypoint_27.s")
