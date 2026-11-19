#include "common.h"
#include "memory.h"
u8 *func_80800000_glsavegame(void)
{
    return heap_alloc(0x1C0);
}

s32 func_80800020_glsavegame(s32 arg0, u8 *arg1) {
    s32 _glgamedata_entrypoint_4(u8 *);
    s32 _glgamedata_entrypoint_5(s32 *);
    void _glgamedata_entrypoint_6(u8 *arg0);
    s32 _glgamestore_entrypoint_0(s32, BtIntPtr);
    s32 attempts;
    s32 result;

    attempts = 3;
    do {
        result = _glgamestore_entrypoint_0(arg0, (BtIntPtr)arg1);
    } while (result != 0 && --attempts != 0);
    if (result == 0) {
        if (_glgamedata_entrypoint_5((s32 *)arg1) == 2) {
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

typedef struct {
    u8 *buffers[3];
    s8 map[3];
    s8 spareFile;
    u8 cacheActive;
    u8 unk11;
    s8 selectedSlot;
} SavegameCache;
extern SavegameCache D_80127618;
void glsavegame_entrypoint_0(void)
{
  void _glgamedata_entrypoint_6(u8 *arg0);
  void aligned4_memcpy(void* dst, void* src, int length);
  s32 func_80800020_glsavegame(s32, u8 *);

  s32 game_index;
  s32 file_index;
  s32 file_state[4];
  u8 *buffer;
  s32 result;
  s32 index;
  D_80127618.selectedSlot = -1;
  D_80127618.spareFile = -1;
  file_state[3] = 0;
  for (file_index = 0; file_index < 3; file_index++)
  {
    D_80127618.map[file_index] = -1;
    file_state[file_index] = 0;
    D_80127618.buffers[file_index] = func_80800000_glsavegame();
    _glgamedata_entrypoint_6(D_80127618.buffers[file_index]);
  }

  buffer = func_80800000_glsavegame();
  for (file_index = 0; file_index < 4; file_index++)
  {
    result = func_80800020_glsavegame(file_index, buffer);
    if (result == 0)
    {
      index = func_808000CC_glsavegame(buffer);
      if (D_80127618.map[index] == (-1))
      {
        D_80127618.map[index] = file_index;
        file_state[file_index] = 1;
        aligned4_memcpy((void *) D_80127618.buffers[index], (void *) buffer, 0x1C0);
      }
      else
      {
        result = 2;
      }
    }
    if (result != 0)
    {
      D_80127618.spareFile = file_index;
    }
  }

  heap_free(buffer);
  file_state[D_80127618.spareFile] = 1;
  for (game_index = 0; game_index < 3; game_index++)
  {
    for (file_index = 0; (file_index < 4) && (D_80127618.map[game_index] == (-1)); file_index++)
    {
      if (file_state[file_index] == 0)
      {
        file_state[file_index] = 1;
        D_80127618.map[game_index] = file_index;
      }
    }

  }

  index = 1;
  D_80127618.cacheActive = index;
  D_80127618.unk11 = index;
}

s32 func_808002E0_glsavegame(s32 arg0, u8 *arg1) {
    s32 _glgamestore_entrypoint_2(s32, BtIntPtr);
    s32 func_80800020_glsavegame(s32, u8 *);

    s32 count;
    s32 result;
    u8 *buffer;

    count = 3;
    buffer = func_80800000_glsavegame();
    do {
        result = _glgamestore_entrypoint_2(arg0, (BtIntPtr)arg1);
        if (result == 0) {
            func_80800020_glsavegame(arg0, buffer);
        }
        count--;
    } while (result != 0 && count != 0);
    heap_free(buffer);
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
  BT_IDO_ONLY(extern void *D_80127614;)

  u8 **var_s0;
  u8 **var_s1;
  u8 *temp_a0;
  var_s0 = BT_DATA_FIELD(D_80127618.buffers, (u8 **)&D_80127614 + 1); var_s1 = BT_DATA_FIELD(D_80127618.buffers + 3, (u8 **)&D_80127614 + 4); do {
    temp_a0 = *var_s0;
    if (temp_a0 != 0)
    {
      heap_free(temp_a0);
      *var_s0 = 0;
    }
    var_s0++;
  }
  while (var_s0 != var_s1);
  BT_DATA_FIELD(D_80127618.cacheActive, *((s8 *)&D_80127614 + 0x14)) = 0;
}

s32 glsavegame_entrypoint_2(s32 arg0) {
    BT_IDO_ONLY(extern void *D_80127614;)
    return BT_DATA_FIELD(D_80127618.buffers[arg0], ((u8 **)&D_80127614)[arg0 + 1])[0] != 0;
}

s32 glsavegame_entrypoint_3(void){
    int i;
    for(i = 0; i < 3; i++){
        if(glsavegame_entrypoint_2(i))
            return 1;
    }
    return 0;
}

u8 *glsavegame_entrypoint_4(s32 arg0) {
    BT_IDO_ONLY(extern void *D_80127614;)
    return BT_DATA_FIELD(D_80127618.buffers[arg0], ((u8 **)&D_80127614)[arg0 + 1]);
}

s32 glsavegame_entrypoint_5() 
{
    return 0x1;
}

void glsavegame_entrypoint_6(s8 *arg0) {
    BT_IDO_ONLY(extern void *D_80127614;)
    *arg0 = BT_DATA_FIELD(D_80127618.selectedSlot, *((s8 *)&D_80127614 + 0x16)) + 1;
}

void func_808004B8_glsavegame(s32 arg0) {
    BT_IDO_ONLY(extern void *D_80127614;)
    BT_DATA_FIELD(D_80127618.selectedSlot, *((s8 *)&D_80127614 + 0x16)) = arg0;
}

void func_808004C4_glsavegame(void) {
    BT_IDO_ONLY(extern void *D_80127614;)
    BT_DATA_FIELD(D_80127618.selectedSlot, *((s8 *)&D_80127614 + 0x16)) = (-1);
}

s32 glsavegame_entrypoint_7(s32 arg0) {
    void _glgamedata_entrypoint_1(void *);

    s32 result;
    s32 sp28;
    s32 sp24;
    u8 *sp20;

    sp20 = func_80800000_glsavegame();
    sp28 = D_80127618.map[arg0];
    sp24 = D_80127618.spareFile;
    func_808004B8_glsavegame(arg0);
    _glgamedata_entrypoint_1((void *)sp20);
    func_808004C4_glsavegame();
    result = func_808002E0_glsavegame(sp24, sp20);
    if (result == 0) {
        result = func_8080036C_glsavegame(sp28);
    }
    if (result == 0) {
        D_80127618.map[arg0] = sp24;
        D_80127618.spareFile = sp28;
    }
    heap_free(sp20);
    return result;
}

s32 glsavegame_entrypoint_8(s32 arg0) {
    s32 sp24;
    s32 temp_v0;
    u8 *sp1C;
    BT_IDO_ONLY(extern void *D_80127614;)
    extern s32 func_80800020_glsavegame(s32, u8 *);

    extern u8 *func_80800000_glsavegame(void);
    extern void _glgamedata_entrypoint_2(BtIntPtr);

    sp1C = func_80800000_glsavegame();
    temp_v0 = func_80800020_glsavegame(BT_DATA_FIELD(D_80127618.map[arg0], *((s8 *)&D_80127614 + 0x10 + arg0)), sp1C);
    sp24 = temp_v0;
    if (temp_v0 == 0) {
        _glgamedata_entrypoint_2((BtIntPtr)sp1C);
    }
    heap_free(sp1C);
    return sp24;
}

s32 glsavegame_entrypoint_9(s32 arg0) {
    void _glgamedata_entrypoint_6(u8 *arg0);
    s32 ret;
    s32 old;
    s32 current;

    old = D_80127618.map[arg0];
    current = D_80127618.spareFile;
    ret = func_8080036C_glsavegame(old);
    if (ret == 0) {
        D_80127618.map[arg0] = current;
        D_80127618.spareFile = old;
        if (D_80127618.cacheActive != 0) {
            _glgamedata_entrypoint_6(D_80127618.buffers[arg0]);
        }
    }
    return ret;
}

s32 glsavegame_entrypoint_10(volatile s32 arg0, volatile s32 arg1) {
    s32 func_80800020_glsavegame(s32, u8 *);
    void _glgamedata_entrypoint_1(void *);
    void _glgamedata_entrypoint_2(BtIntPtr);
    void aligned4_memcpy(void* dst, void* src, int length);

    u8 *temp_s2;
    SavegameCache *temp_s1;
    s32 saved1;
    s32 saved0;
    s32 var_s0;
    s8 *sp28;

    temp_s2 = func_80800000_glsavegame();
    temp_s1 = &D_80127618;
    var_s0 = temp_s1->map[arg1];
    sp28 = BT_DATA_FIELD(&temp_s1->map[arg0], (s8 *)temp_s1 + arg0);
    saved1 = BT_DATA_FIELD(*sp28, sp28[0xC]);
    saved0 = temp_s1->spareFile;
    var_s0 = func_80800020_glsavegame(var_s0, temp_s2);
    _glgamedata_entrypoint_2((BtIntPtr)temp_s2);
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
        temp_s1 = &D_80127618;
        BT_DATA_FIELD(*sp28, sp28[0xC]) = saved0;
        temp_s1->spareFile = saved1;
        if (temp_s1->cacheActive != 0) {
            aligned4_memcpy(temp_s1->buffers[arg0], temp_s1->buffers[arg1], 0x1C0);
        }
    }
    heap_free(temp_s2);
    return var_s0;
}

#ifdef BT_NATIVE
SavegameCache D_80127618 BT_DATA(4, bss_core2bss1_0_1, 0x5B8);
#endif
