#include "common.h"

/* extern */

u8 *vpflicker_entrypoint_0(u8 *arg0, u8 *arg1) {
    void *heap_alloc(s32);
    u8 *temp_a0;
    u8 *temp_a1;
    u8 *var_v1;
    u8 *temp_v0;

    temp_v0 = heap_alloc(((*(s32 *)((s8 *)(arg0) + (0x14))) * 2) + 8);
    temp_a0 = arg1 + 0x14;
    temp_a1 = ((*(s32 *)((s8 *)(arg0) + (0x14))) * 4) + arg1 + 0x14;
    (*(s32 *)((s8 *)(temp_v0) + (4))) = 0;
    var_v1 = temp_a0;
    (*(f32 *)((s8 *)(temp_v0) + (0))) = 1.0f;
    if (temp_a0 < temp_a1) {
        do {
            if ((*(u16 *)((s8 *)(var_v1) + (2))) != 0) {
                (*(s16 *)((s8 *)((temp_v0 + ((*(s32 *)((s8 *)(temp_v0) + (4))) * 2))) + (8))) = (s16) ((s32) (var_v1 - temp_a0) >> 2);
                (*(s32 *)((s8 *)(temp_v0) + (4))) = (s32) ((*(s32 *)((s8 *)(temp_v0) + (4))) + 1);
            }
            var_v1 += 4;
        } while (var_v1 < temp_a1);
    }
    return temp_v0;
}

void vpflicker_entrypoint_1(void* arg0) 
{
    heap_free(arg0);
}
/* extern */

void vpflicker_entrypoint_2(f32 *arg0, u8 *arg1) {
    f32 func_800DC264(f32, f32);
    f32 temp_f2;
    s16 *var_v1;
    s16 temp_t8;
    s32 var_v0;
    u8 *base;

    temp_f2 = func_800DC264(-0.04f, 0.04f);
    *arg0 += temp_f2;
    temp_f2 = *arg0;
    if (temp_f2 > 1.0f) {
        *arg0 = 1.0f;
    } else {
        *arg0 = temp_f2;
    }
    temp_f2 = *arg0;
    if (temp_f2 < 0.8f) {
        *arg0 = 0.8f;
    } else {
        *arg0 = temp_f2;
    }
    base = arg1;
    base += *(s32 *)(arg1 + 0x1C);
    var_v1 = (s16 *)(arg0 + 2);
    for (var_v0 = 0; var_v0 < ((s32 *)arg0)[1]; var_v0++) {
        *(s8 *)(base + var_v1[var_v0] * 0x14 + 3) = 1;
    }
}

void vpflicker_entrypoint_3(f32 *arg0, s16 arg1, Vtx *arg2, s32 arg3)
{
  Vtx *end = arg2 + arg3;
  f32 scale = *arg0;
  s32 more;
  if (arg2 < end)
  {
 do { for (;;) { arg2->v.cn[0] *= scale; arg2->v.cn[1] *= scale; arg2->v.cn[2] *= scale; arg2++; more = arg2 < end; if (!more) { return; } } } while (0);
  }
}
