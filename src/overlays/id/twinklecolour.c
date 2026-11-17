#include "common.h"

void idtwinklecolour_entrypoint_0(s32 arg0, s16 *arg1, s32 arg2, u8 *arg3) {
    s16 func_800DC214(s16, s16);
    struct Entry {
        f32 value;
        s16 pos[3];
        u8 active;
        s8 step;
        u8 colour;
        u8 available;
        u8 pad[6];
    };
    struct State {
        u8 pad[0xE];
        s16 pos[3];
        s32 radius;
        s16 unknown[4];
        s16 index;
        s16 count;
        struct Entry *entries;
    };
    s32 distance;
    s32 i;
    s32 delta[3];

    if (((struct State *)arg3)->entries[((struct State *)arg3)->index].available) {
        for (i = 0; i < 3; i++) {
            delta[i] = arg1[i] - ((s16 *)(arg3 + 0xE))[i];
        }
        distance = delta[0] * delta[0] + delta[1] * delta[1] + delta[2] * delta[2];
        if (distance <= ((struct State *)arg3)->radius) {
            for (i = 0; i < ((struct State *)arg3)->count; i++) {
                if (((struct State *)arg3)->entries[i].pos[0] == arg1[0] && ((struct State *)arg3)->entries[i].pos[1] == arg1[1] && ((struct State *)arg3)->entries[i].pos[2] == arg1[2]) {
                    return;
                }
            }
            ((struct State *)arg3)->entries[((struct State *)arg3)->index].pos[0] = arg1[0];
            ((struct State *)arg3)->entries[((struct State *)arg3)->index].pos[1] = arg1[1];
            ((struct State *)arg3)->entries[((struct State *)arg3)->index].pos[2] = arg1[2];
            ((struct State *)arg3)->entries[((struct State *)arg3)->index].value = 0.0f;
            ((struct State *)arg3)->entries[((struct State *)arg3)->index].step = 10;
            ((struct State *)arg3)->entries[((struct State *)arg3)->index].active = 1;
            ((struct State *)arg3)->entries[((struct State *)arg3)->index].available = 0;
            ((struct State *)arg3)->entries[((struct State *)arg3)->index].colour = func_800DC214(0, 1);
        }
    }
}        

void idtwinklecolour_entrypoint_1(s32 arg0, void *arg1, s32 arg2, void *arg3) {
    if ((*(s16 *)((s8 *)(arg3) + (0x1E))) == (*(s16 *)((s8 *)(arg3) + (0x1C)))) {
        (*(s16 *)((s8 *)(arg3) + (0xE))) = (s16) (*(s16 *)((s8 *)(arg1) + (0)));
        (*(s16 *)((s8 *)(arg3) + (0x10))) = (s16) (*(s16 *)((s8 *)(arg1) + (2)));
        (*(s16 *)((s8 *)(arg3) + (0x12))) = (s16) (*(s16 *)((s8 *)(arg1) + (4)));
    }
    (*(s16 *)((s8 *)(arg3) + (0x1C))) = (s16) ((*(s16 *)((s8 *)(arg3) + (0x1C))) + 1);
}

void idtwinklecolour_entrypoint_2(s32 arg0, u8 *arg1, u8 *arg2, s32 arg3, u8 *arg4) {
    extern u8 D_80800970_idtwinklecolour[][3];
    u8 *end = arg1 + arg3 * 0x10;
    s32 i;
    u8 *entry;
    u8 *colour;
    f32 scale;
    s16 x;

    for (; arg1 < end; arg1 += 0x10, arg2 += 0x10) {
        i = 0;
        if (*(s16 *)(arg4 + 0x22) > 0) {
            x = *(s16 *)arg1;
            entry = *(u8 **)(arg4 + 0x24);
            do {
                if (x == *(s16 *)(entry + 4) &&
                    *(s16 *)(arg1 + 2) == *(s16 *)(entry + 6) &&
                    *(s16 *)(arg1 + 4) == *(s16 *)(entry + 8)) {
                    break;
                }
                i++;
                entry += 0x14;
            } while (i < *(s16 *)(arg4 + 0x22));
        }
        if (i != *(s16 *)(arg4 + 0x22)) {
            entry = *(u8 **)(arg4 + 0x24) + i * 0x14;
            scale = *(f32 *)entry;
            colour = D_80800970_idtwinklecolour[entry[0xC]];
            arg2[0xC] = arg1[0xC] + (colour[0] - arg1[0xC]) * scale;
            arg2[0xD] = arg1[0xD] + (colour[1] - arg1[0xD]) * scale;
            arg2[0xE] = arg1[0xE] + (colour[2] - arg1[0xE]) * scale;
        }
    }
}                typedef struct { u8 pad0[0xC]; s16 unkC; u8 padE[0x6]; s32 unk14; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; s16 unk20; s16 unk22; BtIntPtr unk24; } Objtwinklecolour_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_80800574_idtwinklecolour(void *arg0, BtIntPtr arg1, s32 arg2, s32 arg3) {
    void _glid_entrypoint_2(u8 *arg0, s32 arg1, s32 (*arg2)(s16, u8 *, u8 *, s32), BtIntPtr arg3);
    s16 func_800DC214(s16, s16);
#ifndef BT_NATIVE
    extern s32 _idtwinklecolour_entrypoint_0;
#endif
#ifndef BT_NATIVE
    extern s32 _idtwinklecolour_entrypoint_1;
#endif
    s16 temp_v0;       

    (((Objtwinklecolour_arg0 *)arg0)->unk1E) = func_800DC214(0, (((Objtwinklecolour_arg0 *)arg0)->unkC));
    (((Objtwinklecolour_arg0 *)arg0)->unk1C) = 0;
    (((Objtwinklecolour_arg0 *)arg0)->unk20) = (s16) arg3;
    _glid_entrypoint_2(arg1, arg2, &_idtwinklecolour_entrypoint_1, arg0);
    temp_v0 = func_800DC214((((Objtwinklecolour_arg0 *)arg0)->unk18), (((Objtwinklecolour_arg0 *)arg0)->unk1A));
    (((Objtwinklecolour_arg0 *)arg0)->unk14) = (s32) (temp_v0 * temp_v0);
    _glid_entrypoint_2(arg1, arg2, &_idtwinklecolour_entrypoint_0, arg0);
}

/* extern */

void idtwinklecolour_entrypoint_3(void *arg0) {
    void heap_free(void *memory);
    heap_free((((Objtwinklecolour_arg0 *)arg0)->unk24));
}

/* extern */

void idtwinklecolour_entrypoint_4(u8 *arg0, s32 arg1, BtIntPtr arg2, s32 arg3) {
    void _glidmake_entrypoint_2(BtIntPtr, s32, u8 *, u8 *);
    s16 _glidmake_entrypoint_3(s32 *arg0, s32 arg1);
    void *heap_alloc(s32);
    f32 sqrtf(f32);
    void bzero(void *, int);
    s16 delta[3];
    s32 i;
    s32 sum;

    sum = 0;
    _glidmake_entrypoint_2(arg2, arg3, arg0, arg0 + 6);
    *(s16 *)(arg0 + 0xC) = _glidmake_entrypoint_3(arg2, arg3);
    for (i = 0; i < 3; i++) {
        delta[i] = ((s16 *)arg0)[i + 3] - ((s16 *)arg0)[i];
        sum += delta[i] * delta[i];
    }
    sum = (s32)sqrtf((f32)sum);
    *(s16 *)(arg0 + 0x22) = arg1;
    *(s16 *)(arg0 + 0x1A) = (s32)((f32)sum * 0.25f);
    *(s16 *)(arg0 + 0x18) = (s32)((f32)*(s16 *)(arg0 + 0x1A) * 0.5f);
    if (*(s16 *)(arg0 + 0x22) <= 0 || *(s16 *)(arg0 + 0x22) >= 21) {
        *(s16 *)(arg0 + 0x22) = 5;
    }
    *(u8 **)(arg0 + 0x24) = heap_alloc(*(s16 *)(arg0 + 0x22) * 0x14);
    bzero(*(u8 **)(arg0 + 0x24), *(s16 *)(arg0 + 0x22) * 0x14);
    for (i = 0; i < *(s16 *)(arg0 + 0x22); i++) {
        (*(u8 **)(arg0 + 0x24))[i * 0x14 + 0xD] = 1;
        func_80800574_idtwinklecolour(arg0, arg2, arg3, i);
    }
}    typedef struct { f32 unk0; u8 pad4[0x7]; s8 unkB; } Objtwinklecolour_idtwinklecolour_entrypoint_5_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void idtwinklecolour_entrypoint_5(s16 *arg0, BtIntPtr arg1, s32 arg2)
{
  void _glid_entrypoint_0(u8 *arg0, s32 arg1, s32 (*arg2)(s16, u8 *, u8 *, s16, s32), BtIntPtr arg3);
  f32 func_800D8FF8(void);
  s32 func_800E3DC0(s16 *, s16 *);
#ifndef BT_NATIVE
  extern s32 _idtwinklecolour_entrypoint_2;
#endif
  f32 sp34;
  f32 temp_f0;
  BtIntPtr var_s0;
  s32 var_s1;
  u8 *temp_v0;
  sp34 = func_800D8FF8();
  if (func_800E3DC0(arg0, arg0 + 3) != 0)
  {
    var_s1 = 0;
 do { if ((((Objtwinklecolour_arg0 *)arg0)->unk22) > 0) { var_s0 = 0; do { temp_v0 = (((Objtwinklecolour_arg0 *)arg0)->unk24) + var_s0; ((Objtwinklecolour_idtwinklecolour_entrypoint_5_temp_v0 *)temp_v0)->unk0 += ((f32) (((Objtwinklecolour_idtwinklecolour_entrypoint_5_temp_v0 *)temp_v0)->unkB)) * sp34; temp_v0 = (((Objtwinklecolour_arg0 *)arg0)->unk24) + var_s0; temp_f0 = *((f32 *) temp_v0); if (temp_f0 >= 1.0f) { *((f32 *) temp_v0) = 1.0f; temp_v0 = (((Objtwinklecolour_arg0 *)arg0)->unk24) + var_s0; ((Objtwinklecolour_idtwinklecolour_entrypoint_5_temp_v0 *)temp_v0)->unkB = (s8) (-(((Objtwinklecolour_idtwinklecolour_entrypoint_5_temp_v0 *)temp_v0)->unkB)); } else if (temp_f0 < 0.0f) { *((f32 *) temp_v0) = 0.0f; *((s8 *) (((s8 *) ((((Objtwinklecolour_arg0 *)arg0)->unk24) + var_s0)) + 0xD)) = 1; } var_s1 += 1; var_s0 += 0x14; } while (var_s1 < (((Objtwinklecolour_arg0 *)arg0)->unk22)); var_s1 = 0; } _glid_entrypoint_0(arg1, arg2, &_idtwinklecolour_entrypoint_2, (BtIntPtr) arg0); } while (0);
    var_s0 = 0;
    if ((((Objtwinklecolour_arg0 *)arg0)->unk22) > 0)
    {
      do
      {
        if ((*((u8 *) (((s8 *) ((((Objtwinklecolour_arg0 *)arg0)->unk24) + var_s0)) + 0xD))) != 0)
        {
          func_80800574_idtwinklecolour(arg0, arg1, arg2, var_s1);
        }
        var_s1 += 1;
        var_s0 += 0x14;
      }
      while (var_s1 < (((Objtwinklecolour_arg0 *)arg0)->unk22));
    }
  }
}
/* data_to_c.py: from asm/data/overlays/id/twinklecolour.data.s */
u8 D_80800970_idtwinklecolour [5] [ 3 ] BT_DATA(4, overlays_id_twinklecolour, 0x0) = { { 0xFF, 0xFF, 0xFF }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } };
