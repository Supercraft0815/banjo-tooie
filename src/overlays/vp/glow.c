#include "common.h"

/* extern */

u8 *vpglow_entrypoint_0(u8 *arg0, u8 *arg1) {
    void *heap_alloc(s32);
    u8 *temp_a0;
    u8 *temp_a1;
    u8 *temp_v0;
    u8 *var_v1;

    temp_v0 = heap_alloc(((*(s32 *)((s8 *)(arg0) + (0x14))) * 2) + 0xC);
    temp_a1 = ((*(s32 *)((s8 *)(arg0) + (0x14))) * 4) + arg1 + 0x14;
    (*(s32 *)((s8 *)(temp_v0) + (8))) = 0;
    (*(f32 *)((s8 *)(temp_v0) + (0))) = 0.5f;
    temp_a0 = arg1 + 0x14;
    var_v1 = temp_a0;
    (*(f32 *)((s8 *)(temp_v0) + (4))) = (f32) (((f32) (*(s32 *)arg1 % 100) + 1.0f) * 0.01f);
    if ((u32) temp_a0 < (u32) temp_a1) {
        do {
            if ((*(u16 *)((s8 *)(var_v1) + (2))) != 0) {
                (*(s16 *)((s8 *)((temp_v0 + ((*(s32 *)((s8 *)(temp_v0) + (8))) * 2))) + (0xC))) = (s16) ((s32) (var_v1 - temp_a0) >> 2);
                (*(s32 *)((s8 *)(temp_v0) + (8))) = (s32) ((*(s32 *)((s8 *)(temp_v0) + (8))) + 1);
            }
            var_v1 += 4;
        } while ((u32) var_v1 < (u32) temp_a1);
    }
    return temp_v0;
}

void vpglow_entrypoint_1(void* arg0) 
{
    heap_free(arg0);
}
/* extern */

void vpglow_entrypoint_2(u8 *arg0, u8 *arg1) {
    f32 func_800D8FF8(void);
    f32 delta;
    f32 temp_f12;
    f32 temp_f2;
    s16 *var_v1;
    s32 var_v0;
    u8 *base;

    delta = func_800D8FF8();
    temp_f2 = (*(f32 *)((s8 *)(arg0) + (4)));
    (*(f32 *)((s8 *)(arg0) + (0))) = (f32) ((*(f32 *)((s8 *)(arg0) + (0))) + (temp_f2 * delta));
    temp_f12 = (*(f32 *)((s8 *)(arg0) + (0)));
    if (temp_f12 >= 1.0f) {
        (*(f32 *)((s8 *)(arg0) + (0))) = 1.0f;
        (*(f32 *)((s8 *)(arg0) + (4))) = (f32) -temp_f2;
    } else if (temp_f12 < 0.3f) {
        (*(f32 *)((s8 *)(arg0) + (0))) = 0.3f;
        (*(f32 *)((s8 *)(arg0) + (4))) = (f32) -temp_f2;
    }
    base = arg1;
    base += *(s32 *)(arg1 + 0x1C);
    var_v0 = 0;
    if (*(s32 *)(arg0 + 8) > 0) {
        var_v1 = (s16 *)(arg0 + 0xC);
        do {
            *(s8 *)(base + *var_v1 * 0x14 + 3) = 1;
            var_v0++;
            var_v1++;
        } while (var_v0 < *(s32 *)(arg0 + 8));
    }
}

void vpglow_entrypoint_3(f32 *arg0, s16 arg1, Vtx *arg2, s32 arg3)
{
  Vtx *end = arg2 + arg3;
  f32 scale = *arg0;
  s32 more;
  if (arg2 < end)
  {
 do { for (;;) { arg2->v.cn[0] *= scale; arg2->v.cn[1] *= scale; arg2->v.cn[2] *= scale; arg2++; more = arg2 < end; if (!more) { return; } } } while (0);
  }
}
