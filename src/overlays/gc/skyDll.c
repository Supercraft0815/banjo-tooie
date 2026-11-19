#include "core2/sky_state.h"

typedef struct { SkyMapConfig maps[43]; u32 padding; } SkyMapTable;

BtIntPtr func_80800000_gcskyDll(s32 arg0) {
    extern SkyMapTable D_80800510_gcskyDll;
    SkyMapConfig *p = D_80800510_gcskyDll.maps;
    while (p->map_id != 0) {
        if (arg0 == p->map_id) return (BtIntPtr)p;
        p++;
    }
    return (BtIntPtr)p;
}    typedef struct { u8 pad0[0x20]; s32 unk20; s32 unk24; } ObjskyDll_gcskyDll_entrypoint_0_var_s2; /* offsets.py genstruct: fields from raw offsets on var_s2; rename once understood */ typedef struct { u8 pad0[0x4]; s16 unk4; } ObjskyDll_gcskyDll_entrypoint_0_temp_s0; /* offsets.py genstruct: fields from raw offsets on temp_s0; rename once understood */ typedef struct { s32 unk0; u8 pad4[0x4]; s32 unk8; u8 padC[0x4]; s32 unk10; u8 pad14[0x4]; s32 unk18; } ObjskyDll_gcskyDll_entrypoint_0_var_s1; /* offsets.py genstruct: fields from raw offsets on var_s1; rename once understood */

void gcskyDll_entrypoint_0(BT_NATIVE_ONLY(SkyState *arg0) BT_IDO_ONLY(u8 *arg0))
{
  void _dbtex_entrypoint_1(void *data);
  void _glidmake_entrypoint_4(void* arg0);
  void func_800B23E0(void* arg0);
  s32 func_800D6CEC(s32 arg0);
  s32 func_800D70F8(s32 arg0, s32 arg1);
  s32 func_800D721C(s32 arg0, s32 arg1);
  s8 *new_var;
  void func_800DBFD8(void *data);
  s32 func_800EA05C();
  BtIntPtr func_80800000_gcskyDll(s32);
  BtIntPtr temp_a0;
  BtIntPtr temp_a0_2;
  BtIntPtr temp_a0_3;
  BtIntPtr temp_a0_4;
  BT_NATIVE_ONLY(BtIntPtr) BT_IDO_ONLY(int) temp_s4;
  s32 var_s3;
  u8 *temp_s0;
  u8 *var_s1;
  u8 *var_s2;
  temp_s4 = func_80800000_gcskyDll(func_800EA05C());
  var_s3 = 0;
  var_s1 = (u8 *)arg0;
  var_s2 = (u8 *)arg0;
  do
  {
     temp_a0 = (BtIntPtr)BT_DATA_FIELD(arg0->controllers[var_s3], ((ObjskyDll_gcskyDll_entrypoint_0_var_s1 *)var_s1)->unk0);
    if (temp_a0 != 0)
    {
      func_800DBFD8((void *)temp_a0);
      BT_DATA_FIELD(arg0->controllers[var_s3] = NULL, ((ObjskyDll_gcskyDll_entrypoint_0_var_s1 *)var_s1)->unk0 = 0);
    }
    temp_a0_2 = (BtIntPtr)BT_DATA_FIELD(arg0->handles[var_s3], ((ObjskyDll_gcskyDll_entrypoint_0_var_s1 *)var_s1)->unk8);
    if (temp_a0_2 != 0)
    {
      _glidmake_entrypoint_4((void *)temp_a0_2);
      BT_DATA_FIELD(arg0->handles[var_s3] = NULL, ((ObjskyDll_gcskyDll_entrypoint_0_var_s1 *)var_s1)->unk8 = 0);
    }
    temp_a0_3 = (BtIntPtr)BT_DATA_FIELD(arg0->textures[var_s3], ((ObjskyDll_gcskyDll_entrypoint_0_var_s1 *)var_s1)->unk18);
    if (temp_a0_3 != 0)
    {
      _dbtex_entrypoint_1((void *)temp_a0_3);
      BT_DATA_FIELD(arg0->textures[var_s3] = NULL, ((ObjskyDll_gcskyDll_entrypoint_0_var_s1 *)var_s1)->unk18 = 0);
    }
    temp_a0_4 = (BtIntPtr)BT_DATA_FIELD(arg0->vertices[var_s3][1], ((ObjskyDll_gcskyDll_entrypoint_0_var_s2 *)var_s2)->unk24);
    if (temp_a0_4 != 0)
    {
      func_800B23E0((void *)temp_a0_4);
      BT_DATA_FIELD(arg0->vertices[var_s3][1] = NULL, ((ObjskyDll_gcskyDll_entrypoint_0_var_s2 *)var_s2)->unk24 = 0);
    }
    BT_DATA_FIELD(arg0->vertices[var_s3][0] = NULL, ((ObjskyDll_gcskyDll_entrypoint_0_var_s2 *)var_s2)->unk20 = 0);
    temp_s0 = BT_DATA_FIELD((u8 *)(temp_s4 + var_s3 * 0x10), temp_s4 + (var_s3 * 0x10));
    if (BT_DATA_FIELD(arg0->models[var_s3], (((ObjskyDll_gcskyDll_entrypoint_0_var_s1 *)var_s1)->unk10)) != 0)
    {
      func_800D70F8(((ObjskyDll_gcskyDll_entrypoint_0_temp_s0 *)temp_s0)->unk4, 0);
      func_800D721C(((ObjskyDll_gcskyDll_entrypoint_0_temp_s0 *)temp_s0)->unk4, 0);
      func_800D6CEC(((ObjskyDll_gcskyDll_entrypoint_0_temp_s0 *)temp_s0)->unk4);
      new_var = (s8 *) var_s1;
      BT_DATA_FIELD(arg0->models[var_s3] = NULL, *((s32 *) (new_var + 0x10)) = 0);
    }
    var_s3 += 1;
    var_s1 += 4;
    var_s2 += 8;
  }
  while (var_s3 != 2);
}

void gcskyDll_entrypoint_1(BT_NATIVE_ONLY(SkyState *arg0) BT_IDO_ONLY(u8 *arg0)) { struct VertexListView; void *_dbtex_entrypoint_0(void *data); void *_glidmake_entrypoint_5(s32 arg0, f32 *arg1); BT_NATIVE_ONLY(void _idworldmake_entrypoint_0(void *arg0, s32 arg1);) BT_IDO_ONLY(void _idworldmake_entrypoint_0(s32 arg0, s32 arg1);) void func_800B2198(void *, void *, void *); void *func_800B2400(struct VertexListView *, s32); u8 *func_800B274C(u8 *); void *func_800B27FC(void *arg0); BtIntPtr func_800B2840(BtIntPtr); void func_800BFCD0(s32, s32); void func_800D5B24(void); BtIntPtr func_800D674C(s32); void func_800D70D0(s32); void func_800D71F4(s32); u8 *func_800DBFF8(void); s32 func_800EA05C(); f32 func_800EEF94(f32 *); void func_800EFD24(f32 *); f32 mlAbsF(f32); BtIntPtr entry; f32 extent[3]; s32 i; s32 j; BT_NATIVE_ONLY(s32 sky_index; SkyLayerConfig *layer;) s32 min[3]; s32 max[3]; u8 *p; u8 *pair; u8 *config; entry = func_80800000_gcskyDll(func_800EA05C()); func_800EFD24(extent); config = (u8 *)entry; p = (u8 *)arg0; pair = (u8 *)arg0; for (i = 0; i < 0x20; i += 0x10) { BT_NATIVE_ONLY(sky_index = i >> 4; layer = &((SkyMapConfig *)entry)->layers[sky_index];)
    BT_DATA_FIELD(arg0->handles[sky_index] = NULL, *(s32 *)(p + 8) = 0);
 
    BT_DATA_FIELD(arg0->models[sky_index] = NULL, *(s32 *)(p + 0x10) = 0);
 
    BT_DATA_FIELD(arg0->controllers[sky_index] = NULL, *(s32 *)p = 0);
 
    BT_DATA_FIELD(arg0->vertices[sky_index][0] = NULL, *(s32 *)(pair + 0x20) = 0);
 
    BT_DATA_FIELD(arg0->vertices[sky_index][1] = NULL, *(s32 *)(pair + 0x24) = 0);
 
    BT_DATA_FIELD(arg0->index[sky_index] = 0, *(s32 *)(p + 0x138) = 0);
 if (BT_DATA_FIELD(layer->asset_id, *(s16 *)(config + 4)) != 0) { BT_DATA_FIELD(arg0->models[sky_index] = (void *)func_800D674C(BT_DATA_FIELD(layer->asset_id, *(s16 *)(config + 4))), *(s32 *)(p + 0x10) = func_800D674C(BT_DATA_FIELD(layer->asset_id, *(s16 *)(config + 4)))); if (BT_DATA_FIELD(arg0->textures[sky_index], *(s32 *)(p + 0x18)) == 0) { BT_DATA_FIELD(arg0->textures[sky_index] = _dbtex_entrypoint_0(func_800B27FC(BT_DATA_FIELD(arg0->models[sky_index], *(s32 *)(p + 0x10)))), *(s32 *)(p + 0x18) = _dbtex_entrypoint_0(func_800B27FC(*(s32 *)(p + 0x10)))); } func_800D70D0(1); func_800D71F4(1); if (func_800B274C((u8 *)BT_DATA_FIELD(arg0->models[sky_index], *(u8 **)(p + 0x10)))) { BT_DATA_FIELD(arg0->handles[sky_index] = _glidmake_entrypoint_5(BT_DATA_FIELD(layer->asset_id, *(s16 *)(config + 4)), 0), *(s32 *)(p + 8) = _glidmake_entrypoint_5(BT_DATA_FIELD(layer->asset_id, *(s16 *)(config + 4)), 0)); _idworldmake_entrypoint_0(BT_DATA_FIELD(arg0->handles[sky_index], *(s32 *)(p + 8)), 3); } BT_DATA_FIELD(arg0->controllers[sky_index] = func_800DBFF8(), *(u8 **)p = func_800DBFF8()); BT_DATA_FIELD(arg0->vertices[sky_index][0] = (void *)func_800B2840((BtIntPtr)BT_DATA_FIELD(arg0->models[sky_index], *(s32 *)(p + 0x10))), *(s32 *)(pair + 0x20) = func_800B2840(*(s32 *)(p + 0x10))); func_800B2198(BT_DATA_FIELD(arg0->vertices[sky_index][0], *(void **)(pair + 0x20)), min, max); min[0] = mlAbsF(min[0]); min[1] = mlAbsF(min[1]); min[2] = mlAbsF(min[2]); max[0] = mlAbsF(max[0]); max[1] = mlAbsF(max[1]); max[2] = mlAbsF(max[2]); for (j = 0; j < 3; j++) { if (extent[j] < min[j]) extent[j] = min[j]; if (extent[j] < max[j]) extent[j] = max[j]; } BT_DATA_FIELD(arg0->scales[sky_index] = BT_DATA_FIELD(layer->scale, *(f32 *)(config + 8)), *(f32 *)(p + 0x128) = BT_DATA_FIELD(layer->scale, *(f32 *)(config + 8))); BT_DATA_FIELD(arg0->rates[sky_index] = BT_DATA_FIELD(layer->rate, *(f32 *)(config + 0xC)), *(f32 *)(p + 0x120) = BT_DATA_FIELD(layer->rate, *(f32 *)(config + 0xC))); if (BT_DATA_FIELD(layer->dynamic_vertices, *(s32 *)(config + 0x10))) { func_800D5B24(); BT_DATA_FIELD(arg0->vertices[sky_index][1] = func_800B2400(BT_DATA_FIELD(arg0->vertices[sky_index][0], *(struct VertexListView **)(pair + 0x20)), 1), *(void **)(pair + 0x24) = func_800B2400(*(struct VertexListView **)(pair + 0x20), 1)); } } p += 4; pair += 8; config += 0x10; } {
    s32 k;
    k = 0;
    p = (u8 *)arg0;
    for (; k < 0x3C; k++) {
        BT_DATA_FIELD(arg0->render_switches[k] = 1, *(s32 *)(p + 0x30) = 1);
        p += 4;
    }
    } func_800BFCD0(1, 1); BT_DATA_FIELD(arg0->distance = (s32)func_800EEF94(extent) + 0x64, *(f32 *)((u8 *)arg0 + 0x130) = (s32)func_800EEF94(extent) + 0x64); BT_DATA_FIELD(arg0->age = 0.0f, *(f32 *)((u8 *)arg0 + 0x134) = 0.0f); }    typedef struct { u8 pad0[0x4]; s16 unk4; } ObjskyDll_gcskyDll_entrypoint_2_var_s1; /* offsets.py genstruct: fields from raw offsets on var_s1; rename once understood */

/* extern */

void gcskyDll_entrypoint_2(BT_NATIVE_ONLY(SkyState *arg0) BT_IDO_ONLY(BtIntPtr arg0), s32 arg1) {
    void *_dbtex_entrypoint_0(void *data);
    void *func_800B27FC(void *arg0);
    void func_800D5B24(void);
    BtIntPtr func_800D674C(s32);
    s32 var_s0;
    BtIntPtr var_s1;
    BtIntPtr temp_v0;


    temp_v0 = func_80800000_gcskyDll(arg1);
    var_s0 = 0;
    var_s1 = temp_v0;
    do {
        if (((ObjskyDll_gcskyDll_entrypoint_2_var_s1 *)var_s1)->unk4 != 0) {
            func_800D5B24();
            BT_NATIVE_ONLY(arg0->textures[var_s0] = _dbtex_entrypoint_0(func_800B27FC((void *)func_800D674C(((ObjskyDll_gcskyDll_entrypoint_2_var_s1 *)var_s1)->unk4)));)
            BT_IDO_ONLY((*(s32 *)((s8 *)((arg0 + (var_s0 * 4))) + (0x18))) = _dbtex_entrypoint_0(func_800B27FC(func_800D674C((((ObjskyDll_gcskyDll_entrypoint_2_var_s1 *)var_s1)->unk4))));)
        }
        var_s0 += 1;
        var_s1 += 0x10;
    } while (var_s0 != 2);
}

/* extern */

s32 gcskyDll_entrypoint_3(void) {
    s32 func_800EA05C();
    BtIntPtr func_80800000_gcskyDll(s32);
    return func_80800000_gcskyDll(func_800EA05C()) != 0;
}
/* data_to_c.py: from asm/data/overlays/gc/skyDll.data.s */
SkyMapTable D_80800510_gcskyDll BT_DATA(4, overlays_gc_skyDll, 0x0) = {{
    {0x190, 0, {{0xB3F, 0, 1.0f, 0.0f, 1}, {0}}},
    {0x198, 0, {{0xB3F, 0, 1.0f, 0.0f, 1}, {0}}},
    {0x193, 0, {{0x8C1, 0, 1.0f, 0.0f, 0}, {0}}},
    {0x18B, 0, {{0x8C1, 0, 1.0f, 0.0f, 0}, {0}}},
    {0x0A7, 0, {{0x8C1, 0, 1.0f, 0.0f, 0}, {0}}},
    {0x0A6, 0, {{0x8B6, 0, 1.0f, 0.0f, 0}, {0}}},
    {0x0A5, 0, {{0x8B6, 0, 1.0f, 0.0f, 0}, {0}}},
    {0x0A4, 0, {{0x8B6, 0, 1.0f, 0.0f, 0}, {0}}},
    {0x0A3, 0, {{0x8B6, 0, 1.0f, 0.0f, 0}, {0}}},
    {0x0A1, 0, {{0x8B6, 0, 1.0f, 0.0f, 0}, {0}}},
    {0x0A2, 0, {{0x8B6, 0, 1.0f, 0.0f, 0}, {0}}},
    {0x0B8, 0, {{0xB34, 0, 1.0f, 0.0f, 0}, {0}}},
    {0x0C4, 0, {{0xB34, 0, 1.0f, 0.0f, 0}, {0}}},
    {0x0B9, 0, {{0xB34, 0, 1.0f, 0.0f, 0}, {0}}},
    {0x0BB, 0, {{0xB34, 0, 1.0f, 0.0f, 0}, {0}}},
    {0x0D6, 0, {{0xB35, 0, 1.0f, 0.0f, 0}, {0}}},
    {0x124, 0, {{0xB35, 0, 1.0f, 0.0f, 0}, {0}}},
    {0x0DD, 0, {{0xB37, 0, 1.0f, 1.5f, 0}, {0}}},
    {0x0DE, 0, {{0xB37, 0, 1.0f, 1.5f, 0}, {0}}},
    {0x0DF, 0, {{0xB37, 0, 1.0f, 1.5f, 0}, {0}}},
    {0x0E0, 0, {{0xB37, 0, 1.0f, 1.5f, 0}, {0}}},
    {0x186, 0, {{0xB37, 0, 1.0f, 1.5f, 0}, {0}}},
    {0x0E6, 0, {{0xB38, 0, 1.0f, 1.0f, 0}, {0xB40, 0, 1.0f, 0.0f, 0}}},
    {0x13C, 0, {{0xB38, 0, 1.0f, 1.0f, 0}, {0xB40, 0, 1.0f, 0.0f, 0}}},
    {0x0E1, 0, {{0xB39, 0, 1.0f, 1.0f, 0}, {0}}},
    {0x13B, 0, {{0xB39, 0, 1.0f, 1.0f, 0}, {0}}},
    {0x1A7, 0, {{0xB36, 0, 1.0f, 0.0f, 0}, {0}}},
    {0x100, 0, {{0xB3A, 0, 1.0f, 0.0f, 1}, {0}}},
    {0x127, 0, {{0xB3B, 0, 1.0f, 0.0f, 0}, {0}}},
    {0x128, 0, {{0xB3C, 0, 1.0f, 0.0f, 0}, {0}}},
    {0x136, 0, {{0xB3D, 0, 1.0f, 0.0f, 0}, {0}}},
    {0x161, 0, {{0xB3D, 0, 1.0f, 0.0f, 0}, {0}}},
    {0x0AF, 0, {{0xB3E, 0, 1.0f, 0.0f, 0}, {0}}},
    {0x142, 0, {{0xB3F, 0, 1.0f, 0.0f, 1}, {0}}},
    {0x14F, 0, {{0xB3F, 0, 1.0f, 0.0f, 1}, {0}}},
    {0x152, 0, {{0xB3F, 0, 1.0f, 0.0f, 1}, {0}}},
    {0x154, 0, {{0xB3F, 0, 1.0f, 0.0f, 1}, {0}}},
    {0x155, 0, {{0xB3F, 0, 1.0f, 0.0f, 1}, {0}}},
    {0x15A, 0, {{0xB3F, 0, 1.0f, 0.0f, 1}, {0}}},
    {0x15C, 0, {{0xB3F, 0, 1.0f, 0.0f, 1}, {0}}},
    {0x0E7, 0, {{0xB41, 0, 1.0f, 0.0f, 1}, {0}}},
    {0x19A, 0, {{0x95E, 0, 1.0f, 0.0f, 0}, {0}}},
    {0}
}, 0};
