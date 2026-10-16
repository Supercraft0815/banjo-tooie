#include "common.h"

s32 func_80800000_glintrosyncDll(s32 arg0) {
    extern s32 D_808004A0_glintrosyncDll;
    extern s32 D_808004A8_glintrosyncDll;
    extern s32 D_808004B0_glintrosyncDll;
    extern s32 D_808004B8_glintrosyncDll;
    s32 *var_v0;
    s32 var_v1;

    if (arg0 == D_808004A0_glintrosyncDll) {
        return 0;
    }
    if (arg0 == D_808004A8_glintrosyncDll) {
        return 1;
    }
    var_v0 = &D_808004B8_glintrosyncDll;
    var_v1 = 3;
    if (arg0 == D_808004B0_glintrosyncDll) {
        return 2;
    }
loop_7:
    if (arg0 == (*(s32 *)((s8 *)(var_v0) + (0)))) {
        return var_v1;
    }
    if (arg0 == (*(s32 *)((s8 *)(var_v0) + (8)))) {
        return var_v1 + 1;
    }
    if (arg0 == (*(s32 *)((s8 *)(var_v0) + (0x10)))) {
        return var_v1 + 2;
    }
    if (arg0 == (*(s32 *)((s8 *)(var_v0) + (0x18)))) {
        return var_v1 + 3;
    }
    var_v1 += 4;
    var_v0 += 8;
    if (var_v1 == 0xB) {
        return -1;
    }
    goto loop_7;
}

u32 func_808000BC_glintrosyncDll(s32 arg0) {
    extern f32 D_80127194;
    s32 var_a0;
    u32 temp_v0;

    temp_v0 = osGetCount();
    if (temp_v0 >= (*(u32 *)((s8 *)&D_80127194 + 0x43C))) {
        var_a0 = temp_v0 - (*(u32 *)((s8 *)&D_80127194 + 0x43C));
    } else {
        var_a0 = (0xFFFFFFFF - (*(u32 *)((s8 *)&D_80127194 + 0x43C))) + temp_v0 + 1;
    }
    return (u32)((f32)var_a0 * 0.021333333f);
}

/* extern */

void glintrosyncDll_entrypoint_0(s32 arg0) {
    extern f32 D_80127194;
    s32 func_80800000_glintrosyncDll(s32);
    (*(u32 *)((s8 *)(&D_80127194) + (0x43C))) = osGetCount();
    (*(s32 *)((s8 *)(&D_80127194) + (0x440))) = func_80800000_glintrosyncDll(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/introsyncDll/glintrosyncDll_entrypoint_1.s")

void glintrosyncDll_entrypoint_2(f32 arg0) {
    extern f32 D_80127194;
    *(f32 *)((u8 *)&D_80127194 + 1092) = arg0;
}

f32 glintrosyncDll_entrypoint_3(void) {
    extern f32 D_80127194;
    return *(f32 *)((u8 *)&D_80127194 + 1092);
}

void glintrosyncDll_entrypoint_4(f32 arg0) { extern f32 D_80127194; f32 temp_f0; f32 *temp_v0; temp_v0 = (f32 *)(u32)((u8 *)&D_80127194 + 0x43C); temp_f0 = temp_v0[2]; if ((temp_f0 < 364.5f) && ((temp_f0 + arg0) >= 364.5f)) { temp_v0[3] = 0.86f; } temp_v0[2] = temp_f0 + arg0; }

f32 glintrosyncDll_entrypoint_5(void) {
    s32 func_800C954C(void);
    f32 func_800D8FF8(void);
    f32 func_800D9004(void);
    extern f32 D_80127194;
    if (func_800C954C() != 0) {
        return *(f32 *)((u8 *)&D_80127194 + 0x448) * func_800D8FF8();
    }
    return *(f32 *)((u8 *)&D_80127194 + 0x448) * func_800D9004();
}

void glintrosyncDll_entrypoint_6(s32 arg0)
{
  struct IntroSyncEntry
  {
    s32 id;
    f32 value;
  };
  extern struct IntroSyncEntry D_808004F8_glintrosyncDll[27];
  extern f32 D_80127194;
  s32 _gcsectionDll_entrypoint_4(s32);
  struct IntroSyncEntry *entry;
  u8 *state;
  if (_gcsectionDll_entrypoint_4(arg0) == 0xD)
  {
    state = (u8 *) ((u32) (((u8 *) (&D_80127194)) + 0x43C));
    state[0x10] = 1;
  }
  else
  {
    state = (u8 *) ((u32) (((u8 *) (&D_80127194)) + 0x43C));
    state[0x10] = 0;
  }
 *((f32 *) (state + 0xC)) = 1.0f; if (state[0x10] != 0) { entry = D_808004F8_glintrosyncDll; do {
      if (arg0 == entry->id)
      {
        *((f32 *) (state + 0xC)) = entry->value;
        break;
      }
      entry++;
    }
    while (entry != ((struct IntroSyncEntry *) ((u32) (&D_808004F8_glintrosyncDll[27]))));
  }
}
