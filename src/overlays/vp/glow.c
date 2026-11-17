#include "common.h"

/* extern */

typedef struct { f32 unk0; f32 unk4; s32 unk8; } Objglow_vpglow_entrypoint_0_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */ typedef struct { f32 unk0; f32 unk4; u8 pad8[0xC]; s32 unk14; } Objglow_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */ typedef struct { u8 pad0[0x2]; u16 unk2; } Objglow_vpglow_entrypoint_0_var_v1; /* offsets.py genstruct: fields from raw offsets on var_v1; rename once understood */ u8 *vpglow_entrypoint_0(u8 *arg0, u8 *arg1) {
    void *heap_alloc(s32);
    u8 *temp_a0;
    u8 *temp_a1;
    u8 *temp_v0;
    u8 *var_v1;

    temp_v0 = heap_alloc(((((Objglow_arg0 *)arg0)->unk14) * 2) + 0xC);
    temp_a1 = ((((Objglow_arg0 *)arg0)->unk14) * 4) + arg1 + 0x14;
    (((Objglow_vpglow_entrypoint_0_temp_v0 *)temp_v0)->unk8) = 0;
    (((Objglow_vpglow_entrypoint_0_temp_v0 *)temp_v0)->unk0) = 0.5f;
    temp_a0 = arg1 + 0x14;
    var_v1 = temp_a0;
    (((Objglow_vpglow_entrypoint_0_temp_v0 *)temp_v0)->unk4) = (f32) (((f32) (*(s32 *)arg1 % 100) + 1.0f) * 0.01f);
    if ((BtUIntPtr) temp_a0 < (BtUIntPtr) temp_a1) {
        do {
            if ((((Objglow_vpglow_entrypoint_0_var_v1 *)var_v1)->unk2) != 0) {
                (*(s16 *)((s8 *)((temp_v0 + ((((Objglow_vpglow_entrypoint_0_temp_v0 *)temp_v0)->unk8) * 2))) + (0xC))) = (s16) ((s32) (var_v1 - temp_a0) >> 2);
                (((Objglow_vpglow_entrypoint_0_temp_v0 *)temp_v0)->unk8) = (s32) ((((Objglow_vpglow_entrypoint_0_temp_v0 *)temp_v0)->unk8) + 1);
            }
            var_v1 += 4;
        } while ((BtUIntPtr) var_v1 < (BtUIntPtr) temp_a1);
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
    temp_f2 = (((Objglow_arg0 *)arg0)->unk4);
    (((Objglow_arg0 *)arg0)->unk0) = (f32) ((((Objglow_arg0 *)arg0)->unk0) + (temp_f2 * delta));
    temp_f12 = (((Objglow_arg0 *)arg0)->unk0);
    if (temp_f12 >= 1.0f) {
        (((Objglow_arg0 *)arg0)->unk0) = 1.0f;
        (((Objglow_arg0 *)arg0)->unk4) = (f32) -temp_f2;
    } else if (temp_f12 < 0.3f) {
        (((Objglow_arg0 *)arg0)->unk0) = 0.3f;
        (((Objglow_arg0 *)arg0)->unk4) = (f32) -temp_f2;
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
