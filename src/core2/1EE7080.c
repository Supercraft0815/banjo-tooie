#include "common.h"

typedef struct { s8 flag; s32 value; } Entry; extern u8 D_80124730[13]; extern Entry D_80136F90[13][2]; 

void func_8010D790(void) { int i; u32 j; u8 *counts; int count; i = 0; j = 0; do { counts = &D_80124730[i]; count = *counts; j = 0; if (count > 0) { loop: j++; D_80136F90[i][(s32)j - 1].flag = 0; D_80136F90[i][(s32)j - 1].value = -1; count = D_80124730[i]; if ((s32)j < count) goto loop; } i++; } while (i != 13); }

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE7080/func_8010D7EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE7080/func_8010D89C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE7080/func_8010D930.s")

/* extern */

void func_8010DA30(u8 *arg0) {
    s32 func_800C2FDC(s32, u8 *, u8);
    u8 temp_a2;

    temp_a2 = (*(u8 *)((s8 *)(arg0) + (0)));
    if (temp_a2 != 0) {
        func_800C2FDC(temp_a2 & 0xFF, arg0, temp_a2);
        (*(u8 *)((s8 *)(arg0) + (0))) = 0;
    }
    (*(s32 *)((s8 *)(arg0) + (4))) = -1;
}

u8 *func_8010DA70(s32 arg0) { s32 i; s32 count; Entry *best; i = 0; best = (Entry *)((arg0 << 4) + (u8 *)D_80136F90); count = D_80124730[arg0]; if (count >= 2) { i = 8; do { if (((Entry *)((arg0 * 16 + i) + (u8 *)D_80136F90))->value < best->value) { best = (Entry *)((arg0 * 16 + i) + (u8 *)D_80136F90); } i += 8; } while (i < count * 8); } return (u8 *)best; }
