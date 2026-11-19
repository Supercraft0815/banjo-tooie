#include "core2/sky_state.h"

BT_NATIVE_ONLY(extern SkyState D_80128770;) BT_IDO_ONLY(extern s32 D_80128770;)    typedef struct { u8 pad0[0x30]; s32 unk30; u8 pad34[0x100]; f32 unk134; } Obj1E995C0_D_80128770; /* offsets.py genstruct: fields from raw offsets on &D_80128770; rename once understood */

void func_800BFCD0(s32 arg0, s32 arg1) {
    BT_DATA_FIELD(D_80128770.render_switches[arg0], (*(s32 *)((s8 *)(&(&D_80128770)[arg0]) + (0x30)))) = arg1;
    if (BT_DATA_FIELD(D_80128770.render_switches[0], ((Obj1E995C0_D_80128770 *)&D_80128770)->unk30) < arg0) {
        BT_DATA_FIELD(D_80128770.render_switches[0], ((Obj1E995C0_D_80128770 *)&D_80128770)->unk30) = arg0;
    }
}

void func_800BFD00(void)
{
  void func_800DF744(s32 index,s32 value);
  BT_IDO_ONLY(extern s32 D_80128774;)
  s8 *new_var;
  s32 var_s0;
  var_s0 = 1;
  if (BT_DATA_FIELD(D_80128770.render_switches[0], ((Obj1E995C0_D_80128770 *)&D_80128770)->unk30) > 0)
  {
    new_var = BT_DATA_FIELD((s8 *)&D_80128770.render_switches[1], (s8 *)&D_80128774);
    do
    {
      new_var = (s8 *) new_var;
      func_800DF744(var_s0, BT_DATA_FIELD(D_80128770.render_switches[var_s0], *((s32 *) (new_var + 0x30))));
      var_s0 += 1;
      new_var += 4;
    }
    while (BT_DATA_FIELD(D_80128770.render_switches[0], ((Obj1E995C0_D_80128770 *)&D_80128770)->unk30) >= var_s0);
  }
}

/* extern */

void func_800BFD6C(BT_NATIVE_ONLY(void *arg0) BT_IDO_ONLY(BtIntPtr arg0), s32 arg1) {
    BT_NATIVE_ONLY(void _glid_entrypoint_5(void *arg0, void *arg1);) BT_IDO_ONLY(void _glid_entrypoint_5(s32 *arg0, s32 arg1);)
    BT_NATIVE_ONLY(void _glid_entrypoint_6(void *arg0, void *arg1);) BT_IDO_ONLY(void _glid_entrypoint_6(s32 *arg0, s32 arg1);)
    void *func_800DE448(f32 *, f32 *, f32, f32 *, BtIntPtr);
    void func_800DF4B0(s32);
    void func_800DF738(BtIntPtr);
    void func_800DF7DC(u8 *textures);
    void func_800DF818(BtIntPtr);
    void func_800E3980(f32 *);
    void func_800E3C8C(f32, f32);
    void func_800E3CB8(f32 *, f32 *);
    int func_800E44FC(void *frame);
    s32 func_800EA340(void);
    struct RenderData {
        s32 flags[2];
        s32 handles[2];
        s32 models[2];
        s32 textures[2];
        s32 vertices[2][2];
        u8 pad30[0xF0];
        f32 rates[2];
        f32 scales[2];
        f32 distance;
        f32 time;
        s32 index[2];
    };
    s32 i;
    f32 position[3];
    f32 rotation[3];
    f32 near;
    f32 far;

    if (BT_DATA_FIELD(D_80128770.models[0], ((struct RenderData *)&D_80128770)->models[0])) {
        func_800E3CB8(&near, &far);
        func_800E3C8C(5.0f, BT_DATA_FIELD(D_80128770.distance, ((struct RenderData *)&D_80128770)->distance));
        func_800E3980(position);
        func_800E44FC(arg0);
        for (i = 0; i != 2; i++) {
            if (BT_DATA_FIELD(D_80128770.models[i], ((struct RenderData *)&D_80128770)->models[i])) {
                rotation[0] = 0.0f;
                rotation[2] = 0.0f;
                rotation[1] = BT_DATA_FIELD(D_80128770.rates[i], ((struct RenderData *)&D_80128770)->rates[i]) * BT_DATA_FIELD(D_80128770.age, ((struct RenderData *)&D_80128770)->time);
                func_800BFD00();
                func_800DF738((BtIntPtr)BT_DATA_FIELD(D_80128770.controllers[i], ((struct RenderData *)&D_80128770)->flags[i]));
                func_800DF7DC((u8 *)BT_DATA_FIELD(D_80128770.textures[i], ((struct RenderData *)&D_80128770)->textures[i]));
                func_800DF818((BtIntPtr)BT_DATA_FIELD(D_80128770.vertices[i][D_80128770.index[i]], ((struct RenderData *)&D_80128770)->vertices[i][((struct RenderData *)&D_80128770)->index[i]]));
                func_800DF4B0(2);
                func_800DE448(position, rotation, BT_DATA_FIELD(D_80128770.scales[i], ((struct RenderData *)&D_80128770)->scales[i]), NULL, (BtIntPtr)BT_DATA_FIELD(D_80128770.models[i], ((struct RenderData *)&D_80128770)->models[i]));
                if (BT_DATA_FIELD(D_80128770.vertices[i][1], ((struct RenderData *)&D_80128770)->vertices[i][1]) && func_800EA340()) {
                    if (BT_DATA_FIELD(D_80128770.handles[i], ((struct RenderData *)&D_80128770)->handles[i])) {
                        _glid_entrypoint_6(BT_DATA_FIELD(D_80128770.handles[i], ((struct RenderData *)&D_80128770)->handles[i]), BT_DATA_FIELD(D_80128770.vertices[i][D_80128770.index[i]], ((struct RenderData *)&D_80128770)->vertices[i][((struct RenderData *)&D_80128770)->index[i]]));
                    }
                    BT_DATA_FIELD(D_80128770.index[i], ((struct RenderData *)&D_80128770)->index[i]) ^= 1;
                    if (BT_DATA_FIELD(D_80128770.handles[i], ((struct RenderData *)&D_80128770)->handles[i])) {
                        _glid_entrypoint_5(BT_DATA_FIELD(D_80128770.handles[i], ((struct RenderData *)&D_80128770)->handles[i]), BT_DATA_FIELD(D_80128770.vertices[i][D_80128770.index[i]], ((struct RenderData *)&D_80128770)->vertices[i][((struct RenderData *)&D_80128770)->index[i]]));
                    }
                }
            }
        }
        func_800E3C8C(near, far);
    }
}

void func_800BFF28()
{
    BT_NATIVE_ONLY(void _gcskyDll_entrypoint_0(SkyState *arg0);)
    _gcskyDll_entrypoint_0(&D_80128770);
}

void func_800BFF4C()
{
    BT_NATIVE_ONLY(void _gcskyDll_entrypoint_1(SkyState *arg0);)
    _gcskyDll_entrypoint_1(&D_80128770);
}

/* extern */

void func_800BFF70(void) {
    f32 func_800D8FF8();
    BT_DATA_FIELD(D_80128770.age, (((Obj1E995C0_D_80128770 *)&D_80128770)->unk134)) += func_800D8FF8();
}

BtIntPtr func_800BFFA0(s32 arg0) {
    BT_IDO_ONLY(extern s32 D_80128778[];)
#ifdef BT_NATIVE
    SkyState *state = &D_80128770;
    union { f32 f; u32 u; } bits;
    switch (arg0) {
        case 0: return (BtIntPtr)state->handles[0];
        case 1: return (BtIntPtr)state->handles[1];
        case 2: return (BtIntPtr)state->models[0];
        case 3: return (BtIntPtr)state->models[1];
        case 4: return (BtIntPtr)state->textures[0];
        case 5: return (BtIntPtr)state->textures[1];
        case 6: return (BtIntPtr)state->vertices[0][0];
        case 7: return (BtIntPtr)state->vertices[0][1];
        case 8: return (BtIntPtr)state->vertices[1][0];
        case 9: return (BtIntPtr)state->vertices[1][1];
        default: break;
    }
    if (arg0 >= 10 && arg0 < 70) return state->render_switches[arg0 - 10];
    if (arg0 >= 70 && arg0 < 72) { bits.f = state->rates[arg0 - 70]; return (s32)bits.u; }
    if (arg0 >= 72 && arg0 < 74) { bits.f = state->scales[arg0 - 72]; return (s32)bits.u; }
    if (arg0 == 74) { bits.f = state->distance; return (s32)bits.u; }
    if (arg0 == 75) { bits.f = state->age; return (s32)bits.u; }
    if (arg0 >= 76 && arg0 < 78) return state->index[arg0 - 76];
    return 0;
#else
    return ((s32 *)&D_80128778)[arg0];
#endif
}

/* extern */

s32 func_800BFFB4(s32 arg0, s32 arg1, f32 *arg2) {
    void func_800DBEFC(s32 *, s32, f32 *);
    BtIntPtr temp_a3;
    s32 var_v0;

    temp_a3 = (BtIntPtr)BT_DATA_FIELD(D_80128770.controllers[arg0], (&D_80128770)[arg0]);
    var_v0 = 0;
    if (temp_a3 != 0) {
        func_800DBEFC((s32 *)temp_a3, arg1, arg2);
        return 1;
    }
    return var_v0;
}

void func_800BFFF4(void) {
    void *func_800DC060(void *data);
    BtIntPtr func_800EE5D8(BtIntPtr);
    BT_IDO_ONLY(extern s32 D_80128778[];)
    s32 *var_s0;
    BtIntPtr temp_a0;
    BT_NATIVE_ONLY(s32 i;)

    BT_NATIVE_ONLY(for (i = 0; i != 2; i++) {)
    BT_NATIVE_ONLY(if (D_80128770.handles[i] != NULL) {)
    BT_NATIVE_ONLY(D_80128770.handles[i] = (void *)func_800EE5D8((BtIntPtr)D_80128770.handles[i]);)
    BT_NATIVE_ONLY(})
    BT_NATIVE_ONLY(if (D_80128770.controllers[i] != NULL) {)
    BT_NATIVE_ONLY(D_80128770.controllers[i] = func_800DC060(D_80128770.controllers[i]);)
    BT_NATIVE_ONLY(})
    BT_NATIVE_ONLY(})

    BT_IDO_ONLY(var_s0 = &D_80128770; do {)
        BT_IDO_ONLY(temp_a0 = var_s0[2];)
        BT_IDO_ONLY(if (temp_a0 != 0) {)
            BT_IDO_ONLY(var_s0[2] = func_800EE5D8(temp_a0);)
        BT_IDO_ONLY(})
        BT_IDO_ONLY(temp_a0 = var_s0[0];)
        BT_IDO_ONLY(if (temp_a0 != 0) {)
            BT_IDO_ONLY(var_s0[0] = func_800DC060((void *)temp_a0);)
        BT_IDO_ONLY(})
        BT_IDO_ONLY(var_s0++;)
    BT_IDO_ONLY(} while (var_s0 != D_80128778);)
}

/* extern */

void func_800C0064(s32 arg0) {
    BT_NATIVE_ONLY(void _gcskyDll_entrypoint_2(SkyState *arg0, s32 arg1);) BT_IDO_ONLY(void _gcskyDll_entrypoint_2(BtIntPtr arg0, s32 arg1);)
    _gcskyDll_entrypoint_2(&D_80128770, arg0);
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
SkyState D_80128770 BT_DATA(4, bss_core2bss1_0_2, 0xFD0);
#endif
