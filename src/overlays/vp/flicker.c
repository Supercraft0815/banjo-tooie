#include "common.h"

/* extern */

typedef struct { f32 unk0; s32 unk4; } Objflicker_vpflicker_entrypoint_0_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */ typedef struct { u8 pad0[0x14]; s32 unk14; } Objflicker_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */ typedef struct { u8 pad0[0x2]; u16 unk2; } Objflicker_vpflicker_entrypoint_0_var_v1; /* offsets.py genstruct: fields from raw offsets on var_v1; rename once understood */ u8 *vpflicker_entrypoint_0(u8 *arg0, u8 *arg1) {
    void *heap_alloc(s32);
    u8 *temp_a0;
    u8 *temp_a1;
    u8 *var_v1;
    u8 *temp_v0;

    temp_v0 = heap_alloc(((((Objflicker_arg0 *)arg0)->unk14) * 2) + 8);
    temp_a0 = arg1 + 0x14;
    temp_a1 = ((((Objflicker_arg0 *)arg0)->unk14) * 4) + arg1 + 0x14;
    (((Objflicker_vpflicker_entrypoint_0_temp_v0 *)temp_v0)->unk4) = 0;
    var_v1 = temp_a0;
    (((Objflicker_vpflicker_entrypoint_0_temp_v0 *)temp_v0)->unk0) = 1.0f;
    if (temp_a0 < temp_a1) {
        do {
            if ((((Objflicker_vpflicker_entrypoint_0_var_v1 *)var_v1)->unk2) != 0) {
                (*(s16 *)((s8 *)((temp_v0 + ((((Objflicker_vpflicker_entrypoint_0_temp_v0 *)temp_v0)->unk4) * 2))) + (8))) = (s16) ((s32) (var_v1 - temp_a0) >> 2);
                (((Objflicker_vpflicker_entrypoint_0_temp_v0 *)temp_v0)->unk4) = (s32) ((((Objflicker_vpflicker_entrypoint_0_temp_v0 *)temp_v0)->unk4) + 1);
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
