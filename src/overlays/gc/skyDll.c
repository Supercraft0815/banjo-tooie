#include "common.h"

s32 func_80800000_gcskyDll(s32 arg0) {
    extern s16 D_80800510_gcskyDll[];
    s16 *p = D_80800510_gcskyDll;
    while (*p != 0) {
        if (arg0 == *p) return (s32) p;
        p += 18;
    }
    return (s32) p;
}

void gcskyDll_entrypoint_0(u8 *arg0)
{
  s32 _dbtex_entrypoint_1(s32);
  s32 _glidmake_entrypoint_4(s32);
  s32 func_800B23E0(s32);
  s32 func_800D6CEC(s16);
  s32 func_800D70F8(s16, s32);
  s32 func_800D721C(s16, s32);
  s8 *new_var;
  s32 func_800DBFD8(s32);
  s32 func_800EA05C();
  s32 func_80800000_gcskyDll(s32);
  s32 temp_a0;
  s32 temp_a0_2;
  s32 temp_a0_3;
  s32 temp_a0_4;
  int temp_s4;
  s32 var_s3;
  u8 *temp_s0;
  u8 *var_s1;
  u8 *var_s2;
  temp_s4 = func_80800000_gcskyDll(func_800EA05C());
  var_s3 = 0;
  var_s1 = arg0;
  var_s2 = arg0;
  do
  {
    temp_a0 = *((s32 *) (((s8 *) var_s1) + 0));
    if (temp_a0 != 0)
    {
      func_800DBFD8(temp_a0);
      *((s32 *) (((s8 *) var_s1) + 0)) = 0;
    }
    temp_a0_2 = *((s32 *) (((s8 *) var_s1) + 8));
    if (temp_a0_2 != 0)
    {
      _glidmake_entrypoint_4(temp_a0_2);
      *((s32 *) (((s8 *) var_s1) + 8)) = 0;
    }
    temp_a0_3 = *((s32 *) (((s8 *) var_s1) + 0x18));
    if (temp_a0_3 != 0)
    {
      _dbtex_entrypoint_1(temp_a0_3);
      *((s32 *) (((s8 *) var_s1) + 0x18)) = 0;
    }
    temp_a0_4 = *((s32 *) (((s8 *) var_s2) + 0x24));
    if (temp_a0_4 != 0)
    {
      func_800B23E0(temp_a0_4);
      *((s32 *) (((s8 *) var_s2) + 0x24)) = 0;
    }
    *((s32 *) (((s8 *) var_s2) + 0x20)) = 0;
    temp_s0 = temp_s4 + (var_s3 * 0x10);
    if ((*((s32 *) (((s8 *) var_s1) + 0x10))) != 0)
    {
      func_800D70F8(*((s16 *) (((s8 *) temp_s0) + 4)), 0);
      func_800D721C(*((s16 *) (((s8 *) temp_s0) + 4)), 0);
      func_800D6CEC(*((s16 *) (((s8 *) temp_s0) + 4)));
      new_var = (s8 *) var_s1;
      *((s32 *) (new_var + 0x10)) = 0;
    }
    var_s3 += 1;
    var_s1 += 4;
    var_s2 += 8;
  }
  while (var_s3 != 2);
}

void gcskyDll_entrypoint_1(u8 *arg0) { struct VertexListView; s32 _dbtex_entrypoint_0(s32); s32 _glidmake_entrypoint_5(s32, s32); s32 _idworldmake_entrypoint_0(s32, s32); void func_800B2198(void *, void *, void *); void *func_800B2400(struct VertexListView *, s32); u8 *func_800B274C(u8 *); s32 func_800B27FC(s32); s32 func_800B2840(s32); void func_800BFCD0(s32, s32); void func_800D5B24(void); s32 func_800D674C(s32); void func_800D70D0(s32); void func_800D71F4(s32); u8 *func_800DBFF8(void); s32 func_800EA05C(); f32 func_800EEF94(f32 *); void func_800EFD24(f32 *); f32 mlAbsF(f32); s32 entry; f32 extent[3]; s32 i; s32 j; s32 min[3]; s32 max[3]; u8 *p; u8 *pair; u8 *config; entry = func_80800000_gcskyDll(func_800EA05C()); func_800EFD24(extent); config = (u8 *)entry; p = arg0; pair = arg0; for (i = 0; i < 0x20; i += 0x10) { 
    *(s32 *)(p + 8) = 0;
 
    *(s32 *)(p + 0x10) = 0;
 
    *(s32 *)p = 0;
 
    *(s32 *)(pair + 0x20) = 0;
 
    *(s32 *)(pair + 0x24) = 0;
 
    *(s32 *)(p + 0x138) = 0;
 if (*(s16 *)(config + 4) != 0) { *(s32 *)(p + 0x10) = func_800D674C(*(s16 *)(config + 4)); if (*(s32 *)(p + 0x18) == 0) { *(s32 *)(p + 0x18) = _dbtex_entrypoint_0(func_800B27FC(*(s32 *)(p + 0x10))); } func_800D70D0(1); func_800D71F4(1); if (func_800B274C(*(u8 **)(p + 0x10))) { *(s32 *)(p + 8) = _glidmake_entrypoint_5(*(s16 *)(config + 4), 0); _idworldmake_entrypoint_0(*(s32 *)(p + 8), 3); } *(u8 **)p = func_800DBFF8(); *(s32 *)(pair + 0x20) = func_800B2840(*(s32 *)(p + 0x10)); func_800B2198(*(void **)(pair + 0x20), min, max); min[0] = mlAbsF(min[0]); min[1] = mlAbsF(min[1]); min[2] = mlAbsF(min[2]); max[0] = mlAbsF(max[0]); max[1] = mlAbsF(max[1]); max[2] = mlAbsF(max[2]); for (j = 0; j < 3; j++) { if (extent[j] < min[j]) extent[j] = min[j]; if (extent[j] < max[j]) extent[j] = max[j]; } *(f32 *)(p + 0x128) = *(f32 *)(config + 8); *(f32 *)(p + 0x120) = *(f32 *)(config + 0xC); if (*(s32 *)(config + 0x10)) { func_800D5B24(); *(void **)(pair + 0x24) = func_800B2400(*(struct VertexListView **)(pair + 0x20), 1); } } p += 4; pair += 8; config += 0x10; } {
    s32 k;
    k = 0;
    p = arg0;
    for (; k < 0x3C; k++) {
        *(s32 *)(p + 0x30) = 1;
        p += 4;
    }
    } func_800BFCD0(1, 1); *(f32 *)(arg0 + 0x130) = (s32)func_800EEF94(extent) + 0x64; *(f32 *)(arg0 + 0x134) = 0.0f; }

/* extern */

void gcskyDll_entrypoint_2(s32 arg0, s32 arg1) {
    s32 _dbtex_entrypoint_0(s32);
    s32 func_800B27FC(s32);
    void func_800D5B24(void);
    s32 func_800D674C(s32);
    s32 var_s0;
    s32 var_s1;
    s32 temp_v0;

    temp_v0 = func_80800000_gcskyDll(arg1);
    var_s0 = 0;
    var_s1 = temp_v0;
    do {
        if ((*(s16 *)((s8 *)(var_s1) + (4))) != 0) {
            func_800D5B24();
            (*(s32 *)((s8 *)((arg0 + (var_s0 * 4))) + (0x18))) = _dbtex_entrypoint_0(func_800B27FC(func_800D674C((*(s16 *)((s8 *)(var_s1) + (4))))));
        }
        var_s0 += 1;
        var_s1 += 0x10;
    } while (var_s0 != 2);
}

/* extern */

s32 gcskyDll_entrypoint_3(void) {
    s32 func_800EA05C();
    s32 func_80800000_gcskyDll(s32);
    return func_80800000_gcskyDll(func_800EA05C()) != 0;
}
