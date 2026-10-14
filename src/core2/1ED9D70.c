#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED9D70/func_80100480.s")

void func_8010052C(void) {
}

void func_80100534(void) {
    s32 func_8001211C(void);
    void heap_free(void *);
    extern s32 D_801243A0;
    extern s32 D_801243DC;
    s8 *var_s0;
    void *temp_a0;
    s32 temp_s2;

    temp_s2 = func_8001211C();
    var_s0 = (s8 *)&D_801243A0; do {
        temp_a0 = *(void **)(var_s0 + 8);
        if ((temp_a0 != 0) && ((temp_s2 - (*(s32 *)((s8 *)(var_s0) + (4)))) >= 0x1F)) {
            heap_free(temp_a0);
            (*(s32 *)((s8 *)(var_s0) + (8))) = 0;
            (*(s16 *)((s8 *)(var_s0) + (2))) = 0;
            (*(s32 *)((s8 *)(var_s0) + (4))) = 0;
        }
        var_s0 += 0xC;
    } while (var_s0 != (s8 *)&D_801243DC);
}

void func_801005B8(void)
{
  s32 defrag(s32);
  extern s32 D_801243A0;
  extern s32 D_801243DC;
  s32 (*var_s0)[3];
  s32 temp_a0;
 var_s0 = &D_801243A0; do {
    temp_a0 = var_s0[0][2];
    if (temp_a0 != 0)
    {
      var_s0[0][2] = defrag(temp_a0);
    }
    var_s0++;
  }
  while (var_s0 != ((s32 (*)[3]) (&D_801243DC)));
}

void func_80100610(void)
{
    void heap_free(void *);
    extern s32 D_801243A0;
    extern s32 D_801243DC;
    s32 (*var_s0)[3];
    void *temp_a0;
    var_s0 = &D_801243A0; do {
        temp_a0 = *(void **)&var_s0[0][2];
        if (temp_a0 != 0) {
            heap_free(temp_a0);
            var_s0[0][2] = 0;
            ((s16 *)var_s0)[1] = 0;
            var_s0[0][1] = 0;
        }
        var_s0++;
    } while (var_s0 != ((s32 (*)[3]) (&D_801243DC)));
}

void func_80100670()
{
    func_80100610();
}

typedef struct {
    s16 next_free;
    u8 data[];
} FreeListElement;

typedef struct {
    s16 element_size;
    s16 capacity;
    FreeListElement data[];
} FreeList;

FreeList *freelist_new(s32, s32);
void *freelist_next(FreeList **, s32 *);

void func_80100690(s32 *arg0) {
    FreeList *freelist_new(s32, s32);
    void *freelist_next(FreeList **, s32 *);
    extern FreeList *D_80135A60;
    if (D_80135A60 == 0) {
        D_80135A60 = freelist_new(0xC, 2);
    }
    freelist_next(&D_80135A60, arg0);
}

extern FreeList *D_80135A64;

void func_801006E0(s32 *arg0) {
    FreeList *volatile *list = &D_80135A64;
    if (D_80135A64 == 0) {
        *list = freelist_new(0xC, 2);
    }
    freelist_next(&D_80135A64, arg0);
}

int func_8010072C(s32 *arg0, u8 *arg1) {
    if (arg0 != NULL) {
        return arg0[0] == arg1[0] && arg0[1] == arg1[1] && arg0[2] == arg1[2];
    } else {
        return arg1[0] == 0xFF && arg1[1] == 0xFF && arg1[2] == 0xFF;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED9D70/func_801007B8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED9D70/func_80100938.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED9D70/func_801009C4.s")

s32 func_80100A74(s16 arg0, s32 arg1) { extern FreeList *D_80135A60; void *freelist_at(FreeList *, s32); s32 var_v1; u8 *temp_v0;
    temp_v0 = freelist_at(D_80135A60, arg0); if (temp_v0[9] != 0) { var_v1 = ((s32 *)temp_v0)[arg1]; } else { var_v1 = 0; } return var_v1; }

s32 func_80100AC4(s16 arg0) {
    void *freelist_at(FreeList *, s32);
    extern FreeList *D_80135A60;
    extern FreeList *D_80135A64;
    s32 var_v1;
    void *temp_v0;
    void *temp_v0_2;

    temp_v0 = freelist_at(D_80135A60, arg0);
    if ((*(u8 *)((s8 *)(temp_v0) + (8))) == 0) {
        return 0;
    }
    temp_v0_2 = freelist_at(D_80135A64, (s16) (*(u8 *)((s8 *)(temp_v0) + (8))));
    if ((*(u8 *)((s8 *)(temp_v0_2) + (8))) != 0) {
        var_v1 = (*(s32 *)((s8 *)(temp_v0_2) + (0)));
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

void func_80100B3C(void) {
    extern s32 D_80135A68;
    D_80135A68 = 0x3667;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED9D70/func_80100B4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED9D70/func_80100C74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED9D70/func_80100D24.s")

void func_80100E18(s16 arg0) {
    void *freelist_at(FreeList *, s32);
    extern FreeList *D_80135A60;
    (*(s8 *)((s8 *)(freelist_at(D_80135A60, arg0)) + (0xA))) = 2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED9D70/func_80100E54.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED9D70/func_80100F0C.s")
