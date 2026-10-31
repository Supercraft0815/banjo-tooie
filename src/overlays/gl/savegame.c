#include "common.h"

s32 func_80800000_glsavegame()
{
    return (s32)heap_alloc(0x1C0);
}

s32 func_80800020_glsavegame(s32 arg0, s32 arg1) {
    s32 _glgamedata_entrypoint_4(s32);
    s32 _glgamedata_entrypoint_5(s32);
    s32 _glgamedata_entrypoint_6(s32);
    s32 _glgamestore_entrypoint_0(s32, s32);
    s32 attempts;
    s32 result;

    attempts = 3;
    do {
        result = _glgamestore_entrypoint_0(arg0, arg1);
    } while (result != 0 && --attempts != 0);
    if (result == 0) {
        if (_glgamedata_entrypoint_5(arg1) == 2) {
            result = 3;
        }
    }
    if (result == 0) {
        if (_glgamedata_entrypoint_4(arg1) == 0) {
            result = 3;
        }
    }
    if (result != 0) {
        _glgamedata_entrypoint_6(arg1);
    }
    return result;
}

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

s32 func_808002E0_glsavegame(s32 arg0, s32 arg1) {
    s32 _glgamestore_entrypoint_2(s32, s32);
    s32 func_80800020_glsavegame(s32, s32);
    void heap_free(void *);
    s32 count;
    s32 result;
    s32 buffer;

    count = 3;
    buffer = func_80800000_glsavegame();
    do {
        result = _glgamestore_entrypoint_2(arg0, arg1);
        if (result == 0) {
            func_80800020_glsavegame(arg0, buffer);
        }
        count--;
    } while (result != 0 && count != 0);
    heap_free((void *)buffer);
    return result;
}

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
  void heap_free(void *);
  s32 *var_s0;
  s32 *var_s1;
  s32 temp_a0;
 var_s0 = ((s32 *) (&D_80127614)) + 1; var_s1 = ((s32 *) (&D_80127614)) + 4; do {
    temp_a0 = *var_s0;
    if (temp_a0 != 0)
    {
      heap_free((void *)temp_a0);
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

s32 glsavegame_entrypoint_7(s32 arg0) {
    void _glgamedata_entrypoint_1(void *);
    void heap_free(void *);
    extern s8 D_80127618[];
    s32 result;
    s32 sp28;
    s32 sp24;
    s32 sp20;

    sp20 = func_80800000_glsavegame();
    sp28 = (D_80127618 + arg0)[0xC];
    sp24 = D_80127618[0xF];
    func_808004B8_glsavegame(arg0);
    _glgamedata_entrypoint_1((void *)sp20);
    func_808004C4_glsavegame();
    result = func_808002E0_glsavegame(sp24, sp20);
    if (result == 0) {
        result = func_8080036C_glsavegame(sp28);
    }
    if (result == 0) {
        (D_80127618 + arg0)[0xC] = sp24;
        D_80127618[0xF] = sp28;
    }
    heap_free((void *)sp20);
    return result;
}

s32 glsavegame_entrypoint_8(s32 arg0) {
    s32 sp24;
    s32 temp_v0;
    s32 sp1C;
    extern void *D_80127614;
    extern s32 func_80800020_glsavegame(s32, s32);
    extern void heap_free(void *);
    extern s32 func_80800000_glsavegame(void);
    extern void _glgamedata_entrypoint_2(s32);

    sp1C = (s32)func_80800000_glsavegame();
    temp_v0 = func_80800020_glsavegame(*((s8 *)&D_80127614 + 0x10 + arg0), sp1C);
    sp24 = temp_v0;
    if (temp_v0 == 0) {
        _glgamedata_entrypoint_2(sp1C);
    }
    heap_free((void *)sp1C);
    return sp24;
}

s32 glsavegame_entrypoint_9(s32 arg0) {
    extern s8 D_80127618[];
    s32 _glgamedata_entrypoint_6(s32);
    s32 ret;
    s32 old;
    s32 current;

    old = D_80127618[arg0 + 12];
    current = D_80127618[15];
    ret = func_8080036C_glsavegame(old);
    if (ret == 0) {
        D_80127618[arg0 + 12] = current;
        D_80127618[15] = old;
        if (((u8 *)D_80127618)[16] != 0) {
            _glgamedata_entrypoint_6(((s32 *)D_80127618)[arg0]);
        }
    }
    return ret;
}

s32 glsavegame_entrypoint_10(volatile s32 arg0, volatile s32 arg1) {
    extern s8 D_80127618[];
    s32 func_80800020_glsavegame(s32, s32);
    void _glgamedata_entrypoint_1(void *);
    void _glgamedata_entrypoint_2(s32);
    s32 aligned4_memcpy(void *, void *, s32);
    void heap_free(void *);
    s32 temp_s2;
    s8 *temp_s1;
    s32 saved1;
    s32 saved0;
    s32 var_s0;
    s8 *sp28;

    temp_s2 = func_80800000_glsavegame();
    temp_s1 = D_80127618;
    var_s0 = ((s8 *)temp_s1)[arg1 + 0xC];
    sp28 = &temp_s1[arg0];
    saved1 = sp28[0xC];
    saved0 = temp_s1[0xF];
    var_s0 = func_80800020_glsavegame(var_s0, temp_s2);
    _glgamedata_entrypoint_2(temp_s2);
    func_808004B8_glsavegame(arg0);
    _glgamedata_entrypoint_1((void *)temp_s2);
    func_808004C4_glsavegame();
    if (var_s0 == 0) {
        var_s0 = func_808002E0_glsavegame(saved0, temp_s2);
    }
    if (var_s0 == 0) {
        var_s0 = func_8080036C_glsavegame(saved1);
    }
    if (var_s0 == 0) {
        temp_s1 = D_80127618;
        sp28[0xC] = saved0;
        temp_s1[0xF] = saved1;
        if (*((u8 *)(temp_s1 + 0x10)) != 0) {
            aligned4_memcpy(((void **)temp_s1)[arg0], ((void **)temp_s1)[arg1], 0x1C0);
        }
    }
    heap_free((void *)temp_s2);
    return var_s0;
}
