#include "common.h"

struct Slot { s32 *ptr; };
extern struct Slot D_80127198[];

void cosectionstor_entrypoint_0(void) {
    extern f32 D_80127194;
    s32 i;

    for (i = 1; i < 267; i++) {
        ((s32 *)&D_80127194)[i] = 0;
    }
}

void cosectionstor_entrypoint_1(void) {
    void heap_free(void *);
    extern f32 D_80127194;
    void **var_s0;
    void **end;
    void *temp_a0;

    var_s0 = (void **)(&D_80127194 + 1); end = (void **)(&D_80127194 + 267);
    do {
        temp_a0 = *var_s0;
        if (temp_a0 != 0) {
            heap_free(temp_a0);
            *var_s0 = 0;
        }
        var_s0++;
    } while (var_s0 != end);
}

void cosectionstor_entrypoint_2(void)
{
  BtIntPtr defrag(BtIntPtr);
  s32 *new_var;
  s32 *new_var2;
  extern f32 D_80127194;
  s32 *var_s0;
  s32 *var_s1;
  s32 temp_a0;
 do { var_s0 = (s32 *) ((&D_80127194) + 1); new_var = (new_var2 = (s32 *) ((&D_80127194) + 267)); var_s1 = new_var2; do { temp_a0 = *var_s0; if (temp_a0) { *var_s0 = defrag(temp_a0); } var_s0++; } while (var_s0 != var_s1); } while (0);
}

void cosectionstor_entrypoint_3(s32 arg0) {
    BtIntPtr _gccollectDll_entrypoint_6(void *, void *);
    u8 *_subaddiestore_entrypoint_0(u8 *, u8 *);
    s32 func_800DAA1C(void);
    void func_800FF44C(void);
    void *heap_alloc(s32);
    void heap_free(void *);

    s32 *temp_v0;
    s32 bits;
    s32 *count;
    s32 sp28;
    struct Slot *temp_s0;

    if (arg0 >= 0xA0) {
        arg0 -= 0xA0;
        func_800FF44C();
        temp_s0 = &D_80127198[(u32)arg0];
        temp_v0 = temp_s0->ptr;
        if (temp_v0 != NULL) {
            heap_free(temp_v0);
        }
        temp_v0 = heap_alloc(0x10);
        temp_s0->ptr = temp_v0;
        if (1) {} /* Preserve IDO register allocation. */
        bits = 0;
        count = temp_s0->ptr;
        *count = func_800DAA1C();
        bits += 0x20;
        sp28 = bits >> 5;
        temp_v0 = (s32 *)(uintptr_t)_gccollectDll_entrypoint_6(temp_s0->ptr, &sp28);
        temp_s0->ptr = temp_v0;
        temp_s0->ptr = (s32 *)_subaddiestore_entrypoint_0((u8 *)temp_s0->ptr,
            (u8 *)(temp_s0->ptr + (((s32)(((u32)sp28 << 5) + 0x7F) >> 7) * 4)));
    }
}

void cosectionstor_entrypoint_4(s32 arg0) {
    BtIntPtr _gccollectDll_entrypoint_7(void *, void *);
    void _subaddiestore_entrypoint_1(BtIntPtr, u8 *);
    void func_800DAA28(s32);
    void heap_free(void *);
    s32 *temp_v0;
    s32 bits;
    s32 sp24;

    if (arg0 >= 0xA0) {
        arg0 -= 0xA0;
        if (*(s32 *volatile *)&D_80127198[(u32)arg0].ptr != NULL) {
            temp_v0 = D_80127198[(u32)arg0].ptr;
            bits = 0;
            func_800DAA28(*temp_v0);
            sp24 = (bits += 0x20) >> 5;
            D_80127198[(u32)arg0].ptr = (s32 *)(uintptr_t)_gccollectDll_entrypoint_7(D_80127198[(u32)arg0].ptr, &sp24);
            _subaddiestore_entrypoint_1((BtIntPtr)D_80127198[(u32)arg0].ptr, (u8 *)(D_80127198[(u32)arg0].ptr + (((s32)(((u32)sp24 << 5) + 0x7F) >> 7) * 4)));
            heap_free(D_80127198[(u32)arg0].ptr);
            D_80127198[(u32)arg0].ptr = NULL;
        }
    }
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
struct Slot D_80127198 [ 270 ] BT_DATA(4, bss_core2bss1_0_1, 0x138);
#endif
