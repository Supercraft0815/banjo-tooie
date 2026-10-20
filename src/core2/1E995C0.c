#include "common.h"

extern s32 D_80128770;

void func_800BFCD0(s32 arg0, s32 arg1) {
    (*(s32 *)((s8 *)(&(&D_80128770)[arg0]) + (0x30))) = arg1;
    if ((*(s32 *)((s8 *)(&D_80128770) + (0x30))) < arg0) {
        (*(s32 *)((s8 *)(&D_80128770) + (0x30))) = arg0;
    }
}

void func_800BFD00(void)
{
  s32 func_800DF744(s32, s32);
  extern s32 D_80128774;
  s8 *new_var;
  s32 var_s0;
  var_s0 = 1;
  if ((*((s32 *) (((s8 *) (&D_80128770)) + 0x30))) > 0)
  {
    new_var = &D_80128774;
    do
    {
      new_var = (s8 *) new_var;
      func_800DF744(var_s0, *((s32 *) (new_var + 0x30)));
      var_s0 += 1;
      new_var += 4;
    }
    while ((*((s32 *) (((s8 *) (&D_80128770)) + 0x30))) >= var_s0);
  }
}

/* extern */

void func_800BFD6C(s32 arg0, s32 arg1) {
    s32 _glid_entrypoint_5(s32, s32);
    s32 _glid_entrypoint_6(s32, s32);
    void *func_800DE448(f32 *, f32 *, f32, f32 *, s32);
    void func_800DF4B0(s32);
    void func_800DF738(s32);
    void func_800DF7DC(s32);
    void func_800DF818(s32);
    void func_800E3980(f32 *);
    void func_800E3C8C(f32, f32);
    void func_800E3CB8(f32 *, f32 *);
    void func_800E44FC(Gfx **);
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

    if (((struct RenderData *)&D_80128770)->models[0]) {
        func_800E3CB8(&near, &far);
        func_800E3C8C(5.0f, ((struct RenderData *)&D_80128770)->distance);
        func_800E3980(position);
        func_800E44FC(arg0);
        for (i = 0; i != 2; i++) {
            if (((struct RenderData *)&D_80128770)->models[i]) {
                rotation[0] = 0.0f;
                rotation[2] = 0.0f;
                rotation[1] = ((struct RenderData *)&D_80128770)->rates[i] * ((struct RenderData *)&D_80128770)->time;
                func_800BFD00();
                func_800DF738(((struct RenderData *)&D_80128770)->flags[i]);
                func_800DF7DC(((struct RenderData *)&D_80128770)->textures[i]);
                func_800DF818(((struct RenderData *)&D_80128770)->vertices[i][((struct RenderData *)&D_80128770)->index[i]]);
                func_800DF4B0(2);
                func_800DE448(position, rotation, ((struct RenderData *)&D_80128770)->scales[i], NULL, ((struct RenderData *)&D_80128770)->models[i]);
                if (((struct RenderData *)&D_80128770)->vertices[i][1] && func_800EA340()) {
                    if (((struct RenderData *)&D_80128770)->handles[i]) {
                        _glid_entrypoint_6(((struct RenderData *)&D_80128770)->handles[i], ((struct RenderData *)&D_80128770)->vertices[i][((struct RenderData *)&D_80128770)->index[i]]);
                    }
                    ((struct RenderData *)&D_80128770)->index[i] ^= 1;
                    if (((struct RenderData *)&D_80128770)->handles[i]) {
                        _glid_entrypoint_5(((struct RenderData *)&D_80128770)->handles[i], ((struct RenderData *)&D_80128770)->vertices[i][((struct RenderData *)&D_80128770)->index[i]]);
                    }
                }
            }
        }
        func_800E3C8C(near, far);
    }
}

void func_800BFF28()
{
    _gcskyDll_entrypoint_0(&D_80128770);
}

void func_800BFF4C()
{
    _gcskyDll_entrypoint_1(&D_80128770);
}

/* extern */

void func_800BFF70(void) {
    f32 func_800D8FF8();
    (*(f32 *)((s8 *)(&D_80128770) + 0x134)) += func_800D8FF8();
}

s32 func_800BFFA0(s32 arg0) {
    extern s32 D_80128778[];
    return ((s32 *)&D_80128778)[arg0];
}

/* extern */

s32 func_800BFFB4(s32 arg0, s32 arg1, f32 *arg2) {
    void func_800DBEFC(s32 *, s32, f32 *);
    s32 temp_a3;
    s32 var_v0;

    temp_a3 = (&D_80128770)[arg0];
    var_v0 = 0;
    if (temp_a3 != 0) {
        func_800DBEFC((s32 *)temp_a3, arg1, arg2);
        return 1;
    }
    return var_v0;
}

void func_800BFFF4(void) {
    s32 func_800DC060(s32);
    s32 func_800EE5D8(s32);
    extern s32 D_80128778[];
    s32 *var_s0;
    s32 temp_a0;

    var_s0 = &D_80128770; do {
        temp_a0 = var_s0[2];
        if (temp_a0 != 0) {
            var_s0[2] = func_800EE5D8(temp_a0);
        }
        temp_a0 = var_s0[0];
        if (temp_a0 != 0) {
            var_s0[0] = func_800DC060(temp_a0);
        }
        var_s0++;
    } while (var_s0 != D_80128778);
}

/* extern */

void func_800C0064(s32 arg0) {
    s32 _gcskyDll_entrypoint_2(s32 *, s32);
    _gcskyDll_entrypoint_2(&D_80128770, arg0);
}
