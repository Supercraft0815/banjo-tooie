#include "common.h"

s32 func_80800000_glsavegame()
{
    return (s32)heap_alloc(0x1C0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/savegame/func_80800020_glsavegame.s")

 s32 func_808000CC_glsavegame(u8 *arg0) {
    extern s32 _glgamedata_entrypoint_3(u8 *, s32, s32 *, u32 *);
    s32 sp1C;
    u32 sp18;

    if (_glgamedata_entrypoint_3(arg0, 2, &sp1C, &sp18)) {
        return arg0[sp1C] - 1;
    }
    return -1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/savegame/glsavegame_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/savegame/func_808002E0_glsavegame.s")

/* extern */

s32 func_8080036C_glsavegame(s32 arg0) {
    s32 _glgamestore_entrypoint_4(s32);
    s32 temp_v0;
    s32 var_s0;

    var_s0 = 3;
loop_1:
    temp_v0 = _glgamestore_entrypoint_4(arg0);
    if (temp_v0 != 0) {
        var_s0 -= 1;
        if (var_s0 != 0) {
            goto loop_1;
        }
    }
    return temp_v0;
}

void glsavegame_entrypoint_1(void)
{
  extern void *D_80127614;
  s32 heap_free(s32);
  s32 *var_s0;
  s32 *var_s1;
  s32 temp_a0;
 var_s0 = ((s32 *) (&D_80127614)) + 1; var_s1 = ((s32 *) (&D_80127614)) + 4; do {
    temp_a0 = *var_s0;
    if (temp_a0 != 0)
    {
      heap_free(temp_a0);
      *var_s0 = 0;
    }
    var_s0++;
  }
  while (var_s0 != var_s1);
  *(((s8 *) (&D_80127614)) + 0x14) = 0;
}

s32 glsavegame_entrypoint_2(s32 arg0) {
    extern void *D_80127614;
    return ((u8 *)((void **)(&D_80127614))[arg0 + 1])[0] != 0;
}

s32 glsavegame_entrypoint_3(void){
    int i;
    for(i = 0; i < 3; i++){
        if(glsavegame_entrypoint_2(i))
            return 1;
    }
    return 0;
}

s32 glsavegame_entrypoint_4(s32 arg0) {
    extern void *D_80127614;
    return ((s32 *)&D_80127614)[arg0 + 1];
}

s32 glsavegame_entrypoint_5() 
{
    return 0x1;
}

void glsavegame_entrypoint_6(s8 *arg0) {
    extern void *D_80127614;
    *arg0 = (*(s8 *)((s8 *)(&D_80127614) + (0x16))) + 1;
}

void func_808004B8_glsavegame(s32 arg0) {
    extern void *D_80127614;
    *(s8 *)((u8 *)&D_80127614 + 22) = arg0;
}

void func_808004C4_glsavegame(void) {
    extern void *D_80127614;
    (*(s8 *)((s8 *)(&D_80127614) + (22))) = (-1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/savegame/glsavegame_entrypoint_7.s")

s32 glsavegame_entrypoint_8(s32 arg0) {
    s32 sp24;
    s32 temp_v0;
    s32 sp1C;
    extern void *D_80127614;
    extern s32 func_80800020_glsavegame(s8, s32);
    extern s32 heap_free(s32);
    extern s32 func_80800000_glsavegame(void);
    extern void _glgamedata_entrypoint_2(s32);

    sp1C = (s32)func_80800000_glsavegame();
    temp_v0 = func_80800020_glsavegame(*((s8 *)&D_80127614 + 0x10 + arg0), sp1C);
    sp24 = temp_v0;
    if (temp_v0 == 0) {
        _glgamedata_entrypoint_2(sp1C);
    }
    heap_free(sp1C);
    return sp24;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/savegame/glsavegame_entrypoint_9.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/savegame/glsavegame_entrypoint_10.s")
