#include "common.h"

void gcmapsects_entrypoint_0(s16 arg0, s16 arg1, f32 *arg2, f32 *arg3, f32 *arg4, f32 arg5) {
    void *func_800BF704(void);
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EEAD4(f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    void func_800EF3DC(f32 *, f32 *);
    extern f32 D_808029B0_gcmapsects[3];
    struct Section {
        f32 position[3];
        f32 minimum[3];
        f32 maximum[3];
        f32 center[3];
        f32 radius;
        f32 value;
        u8 color[8];
        s16 id0, id1;
        s32 unk44, unk48;
        u8 flag7 : 1;
        u8 flag6 : 1;
        u8 flag5 : 1;
        u8 flag4 : 1;
        u8 flag3 : 1;
        u8 flag2 : 1;
        u8 flag1 : 1;
        u8 flag0 : 1;
        u8 pad4D[3];
        s32 unk50, unk54;
    };
    struct MapSections {
        u8 pad0[0x68];
        struct Section *sections;
        u8 pad6C[0xB];
        u8 count;
    } *map;
    s32 index;

    map = func_800BF704();
    index = map->count;
    func_800EE7F8(map->sections[index].position, arg2);
    func_800EE7F8(map->sections[index].minimum, arg3);
    func_800EE7F8(map->sections[index].maximum, arg4);
    func_800EF3DC(map->sections[index].minimum, D_808029B0_gcmapsects);
    func_800EF04C(map->sections[index].maximum, D_808029B0_gcmapsects);
    func_800EE780(map->sections[index].center, map->sections[index].minimum, map->sections[index].maximum);
    func_800EF334(map->sections[index].center, 0.5f);
    map->sections[index].radius = func_800EEAD4(map->sections[index].center, map->sections[index].minimum);
    map->sections[index].id0 = arg0;
    map->sections[index].id1 = arg1;
    map->sections[index].color[0] = 255;
    map->sections[index].color[1] = 255;
    map->sections[index].color[2] = 255;
    map->sections[index].color[3] = 255;
    map->sections[index].color[4] = 255;
    map->sections[index].color[5] = 255;
    map->sections[index].color[6] = 255;
    map->sections[index].color[7] = 255;
    map->sections[index].flag7 = 0;
    map->sections[index].flag6 = 0;
    map->sections[index].flag5 = 0;
    map->sections[index].flag4 = 0;
    map->sections[index].flag3 = 1;
    map->sections[index].flag0 = 1;
    map->sections[index].unk44 = 0;
    map->sections[index].unk48 = 0;
    map->sections[index].value = arg5;
    map->sections[index].unk50 = 0;
    map->sections[index].unk54 = 0;
    map->count++;
}

/* extern */

void func_80800250_gcmapsects(void *arg0, s32 arg1) {
    s32 _dbtex_entrypoint_0(s32);
    s32 func_800B27FC(s32);
    s32 func_800D674C(s32);
    s32 func_800D6CEC(s32);
    s32 sp24;
    s32 temp_s0;
    s32 temp_v0_2;
    s32 temp_v0_4;
    s32 temp_v0;
    s32 temp_v0_3;
    void *var_v1;

    temp_s0 = arg1 * 0x58;
    var_v1 = (*(s32 *)((s8 *)(arg0) + (0x68))) + temp_s0;
    if ((*(s32 *)((s8 *)(var_v1) + (0x44))) == 0) {
        temp_v0 = (*(u16 *)((s8 *)(var_v1) + (0x40)));
        if (temp_v0 != 0) {
            temp_v0_2 = func_800D674C(temp_v0 & 0xFFFFFFFF);
            sp24 = temp_v0_2;
            if (func_800B27FC(temp_v0_2) != 0) {
                (*(s32 *)((s8 *)(((*(s32 *)((s8 *)(arg0) + (0x68))) + temp_s0)) + (0x44))) = _dbtex_entrypoint_0(func_800B27FC(sp24));
            }
            func_800D6CEC((*(u16 *)((s8 *)(((*(s32 *)((s8 *)(arg0) + (0x68))) + temp_s0)) + (0x40))));
            var_v1 = (*(s32 *)((s8 *)(arg0) + (0x68))) + temp_s0;
        }
    }
    if ((*(s32 *)((s8 *)(var_v1) + (0x48))) == 0) {
        temp_v0_3 = (*(u16 *)((s8 *)(var_v1) + (0x42)));
        if (temp_v0_3 != 0) {
            temp_v0_4 = func_800D674C(temp_v0_3 & 0xFFFFFFFF);
            sp24 = temp_v0_4;
            if (func_800B27FC(temp_v0_4) != 0) {
                (*(s32 *)((s8 *)(((*(s32 *)((s8 *)(arg0) + (0x68))) + temp_s0)) + (0x48))) = _dbtex_entrypoint_0(func_800B27FC(sp24));
            }
            func_800D6CEC((*(u16 *)((s8 *)(((*(s32 *)((s8 *)(arg0) + (0x68))) + temp_s0)) + (0x42))));
        }
    }
}

void func_8080035C_gcmapsects(void *arg0, s32 arg1) {
    s32 _dbtex_entrypoint_1(s32);
    struct Section { u8 pad[0x44]; s32 first; s32 second; u8 end[0xC]; };
    struct Map { u8 pad[0x68]; struct Section *sections; };

    if (((struct Map *)arg0)->sections[arg1].first != 0) {
        _dbtex_entrypoint_1(((struct Map *)arg0)->sections[arg1].first);
        ((struct Map *)arg0)->sections[arg1].first = 0;
    }
    if (((struct Map *)arg0)->sections[arg1].second != 0) {
        _dbtex_entrypoint_1(((struct Map *)arg0)->sections[arg1].second);
        ((struct Map *)arg0)->sections[arg1].second = 0;
    }
}

void func_808003F4_gcmapsects(void *arg0, s32 arg1)
{
  s32 _glidmake_entrypoint_4(s32);
  s32 _idworldmake_entrypoint_2(s32);
  s32 func_800D6CEC(s32);
  s32 func_800D70F8(s32, s32);
  s32 func_800D73CC(s32);
  s32 func_800E4AF0(s32);
  s32 func_800E4BB8(s32);
  struct Section
  {
    u8 pad[0x40];
    u16 first;
    u16 second;
    s32 textures[2];
    u32 flag80 : 1;
    u32 flag40 : 1;
    u32 flag20 : 1;
    u32 flag10 : 1;
    u32 rest : 28;
    s32 objects[2];
  };
  struct Map
  {
    u8 pad[0x68];
    struct Section *sections;
  };
  struct Map *map = arg0;
  s32 i;
  u16 second;
  map->sections[arg1].flag20 = 0;
  map->sections[arg1].flag80 = 0;
  if (map->sections[arg1].flag10)
  {
    func_800D70F8(map->sections[arg1].first, 0);
    map->sections[arg1].flag10 = 0;
  }
  if (func_800D73CC(map->sections[arg1].first))
  {
    func_800D6CEC(map->sections[arg1].first);
  }
  second = map->sections[arg1].second;
  if (second && func_800D73CC(second))
  {
    func_800D70F8(map->sections[arg1].second, 0);
    func_800D6CEC(map->sections[arg1].second);
  }
  if (func_800E4AF0(map->sections[arg1].first))
  {
    func_800E4BB8(map->sections[arg1].first);
  }
  for (i = 0; i < 2; i++)
  {
    if (map->sections[arg1].objects[i])
    {
      _idworldmake_entrypoint_2(map->sections[arg1].objects[i]);
      _glidmake_entrypoint_4(map->sections[arg1].objects[i]);
      map->sections[arg1].objects[i] = 0;
    }
  }

}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/func_808005D0_gcmapsects.s")

void gcmapsects_entrypoint_1(s16 arg0, s32 arg1) {
    void *func_800BF704(void);
    struct { u8 pad[0x4C]; u8 other : 4; u8 flag : 1; u8 rest : 3; } *temp_v1;

    temp_v1 = (*(s32 *)((s8 *)(func_800BF704()) + (0x68))) + (arg0 * 0x58);
    temp_v1->flag = arg1;
}

void gcmapsects_entrypoint_2(s16 arg0, s32 arg1) {
    void *func_800BF704(void);
    struct { u8 pad[0x4C]; u8 other : 7; u8 flag : 1; } *temp_v1;

    temp_v1 = (*(s32 *)((s8 *)(func_800BF704()) + (0x68))) + (arg0 * 0x58);
    temp_v1->flag = arg1;
}

void gcmapsects_entrypoint_3(s16 arg0, s16 arg1) {
    void *func_800BF704(void);
    struct Section { u8 pad[0x38]; u8 neighbor : 8; };
    struct Map { u8 pad[0x68]; u8 *sections; };
    s32 i;
    struct Map *map;

    map = func_800BF704();
    for (i = 0; i < 4; i++) {
        if (((struct Section *)(map->sections + arg0 * 0x58 + i))->neighbor == 0xFF) {
            ((struct Section *)(map->sections + arg0 * 0x58 + i))->neighbor = arg1;
            break;
        }
    }

    for (i = 0; i < 4; i++) {
        if (((struct Section *)(map->sections + arg1 * 0x58 + i))->neighbor == 0xFF) {
            ((struct Section *)(map->sections + arg1 * 0x58 + i))->neighbor = arg0;
            break;
        }
    }
}

/* extern */

void func_80800A08_gcmapsects(void *arg0, s32 arg1) {
    void func_800D5B24(void);
    s32 func_800D674C(s32);
    s32 func_800D70F8(s32, s32);
    s32 func_800D73CC(s32);
    s32 func_800DB9B0();
    s32 var_s0;
    s32 var_s2;
    u16 temp_v0;
    u16 temp_v0_2;
    struct Section {
        u8 pad[0x4C];
        u32 flag0 : 1;
        u32 flag1 : 1;
        u32 active : 1;
        u32 loaded : 1;
        u32 rest : 28;
    } *temp_v1, *temp_v1_2;

    var_s2 = 0;
    if ((s32) (*(u8 *)((s8 *)(arg0) + (0x77))) > 0) {
        var_s0 = 0;
        do {
            temp_v1 = (*(s32 *)((s8 *)(arg0) + (0x68))) + var_s0;
            if (temp_v1->active || (arg1 != 0)) {
                temp_v0 = *(u16 *)((s8 *)temp_v1 + 0x40);
                if ((temp_v0 != 0) && (func_800D73CC(temp_v0 & 0xFFFFFFFFU) == 0)) {
                    func_800D5B24();
                    func_800D674C((*(u16 *)((s8 *)(((*(s32 *)((s8 *)(arg0) + (0x68))) + var_s0)) + (0x40))));
                    func_800D70F8((*(u16 *)((s8 *)(((*(s32 *)((s8 *)(arg0) + (0x68))) + var_s0)) + (0x40))), 1);
                    temp_v1_2 = (*(s32 *)((s8 *)(arg0) + (0x68))) + var_s0;
                    temp_v1_2->loaded = 1;
                }
                temp_v0_2 = *(u16 *)((s8 *)(*(s32 *)((s8 *)arg0 + 0x68) + var_s0) + 0x42);
                if ((temp_v0_2 != 0) && (func_800D73CC(temp_v0_2 & 0xFFFFFFFFU) == 0)) {
                    func_800D5B24();
                    func_800D674C((*(u16 *)((s8 *)(((*(s32 *)((s8 *)(arg0) + (0x68))) + var_s0)) + (0x42))));
                    func_800D70F8((*(u16 *)((s8 *)(((*(s32 *)((s8 *)(arg0) + (0x68))) + var_s0)) + (0x42))), 1);
                }
            }
            func_80800250_gcmapsects(arg0, var_s2);
            var_s2 += 1;
            var_s0 += 0x58;
        } while (var_s2 < (s32) (*(u8 *)((s8 *)(arg0) + (0x77))));
    }
    if (func_800DB9B0() == 0) {
        (*(s8 *)((s8 *)(arg0) + (0x78))) = 1;
    }
}

/* extern */

void func_80800B58_gcmapsects(void *arg0) {
    s32 func_800D674C(s32);
    s32 func_800D70F8(s32, s32);
    s32 func_800D73CC(s32);
    s32 func_800E488C(s32);
    struct Section {
        u8 pad[0x40];
        u16 id;
        u8 pad42[0xA];
        u32 flag0 : 1;
        u32 flag1 : 1;
        u32 active : 1;
        u32 loaded : 1;
        u32 rest : 28;
    } *section;
    s32 var_s0;
    s32 var_s2;

    var_s0 = 0;
    var_s2 = 0;
    if (*(u8 *)((u8 *)arg0 + 0x77) > 0) {
        do {
            section = (void *)(*(u8 **)((u8 *)arg0 + 0x68) + var_s0);
            if (section->active && func_800D73CC(section->id) == 0) {
                if (func_800E488C(((struct Section *)(*(u8 **)((u8 *)arg0 + 0x68) + var_s0))->id) != 0) {
                    func_800D674C(((struct Section *)(*(u8 **)((u8 *)arg0 + 0x68) + var_s0))->id);
                    func_800D70F8(((struct Section *)(*(u8 **)((u8 *)arg0 + 0x68) + var_s0))->id, 1);
                    section = (void *)(*(u8 **)((u8 *)arg0 + 0x68) + var_s0);
                    section->loaded = 1;
                } else {
                    section = (void *)(*(u8 **)((u8 *)arg0 + 0x68) + var_s0);
                    section->flag0 = 0;
                    section = (void *)(*(u8 **)((u8 *)arg0 + 0x68) + var_s0);
                    section->flag1 = 0;
                }
            }
            var_s2 += 1;
            var_s0 += 0x58;
        } while (var_s2 < *(u8 *)((u8 *)arg0 + 0x77));
    }
}

/* extern */

void func_80800C54_gcmapsects(void *arg0) {
    void func_8080035C_gcmapsects(void *, s32);
    void func_808003F4_gcmapsects(void *, s32);
    s32 var_s0;

    var_s0 = 0;
    if ((s32) (*(u8 *)((s8 *)(arg0) + (0x77))) > 0) {
        do {
            func_808003F4_gcmapsects(arg0, var_s0);
            func_8080035C_gcmapsects(arg0, var_s0);
            var_s0 += 1;
        } while (var_s0 < (s32) (*(u8 *)((s8 *)(arg0) + (0x77))));
    }
}

/* extern */

s32 gcmapsects_entrypoint_4(f32 arg0[3]) {
    void *func_800BF704(void);
    int func_800EFED0(f32 min[3], f32 max[3], f32 vec[3]);
    u8 *temp_v0_2;
    s32 var_s0;
    s32 var_s1;
    s32 temp_v1;
    void *temp_v0;

    temp_v0 = func_800BF704();
    temp_v1 = (*(u8 *)((s8 *)(temp_v0) + (0x77)));
    if (temp_v1 == 0) {
        return -1;
    }
    var_s1 = 0;
    if ((s32) temp_v1 > 0) {
        var_s0 = 0;
loop_4:
        temp_v0_2 = (*(u8 **)((s8 *)(temp_v0) + (0x68))) + var_s0;
        if (func_800EFED0((f32 *)(temp_v0_2 + 0xC), (f32 *)(temp_v0_2 + 0x18), arg0) != 0) {
            return var_s1;
        }
        var_s1 += 1;
        var_s0 += 0x58;
        if (var_s1 >= (s32) (*(u8 *)((s8 *)(temp_v0) + (0x77)))) {
            goto block_7;
        }
        goto loop_4;
    }
block_7:
    return -1;
}

/* extern */

u32 gcmapsects_entrypoint_5(s32 arg0) {
    void *func_800BF704();
    void *temp_v0;

    if (arg0 == -1) {
        return 1U;
    }
    temp_v0 = func_800BF704();
    if ((*(u8 *)((s8 *)(temp_v0) + (0x77))) == 0) {
        return 1U;
    }
    return (u32) ((*(s32 *)((s8 *)(((*(s32 *)((s8 *)(temp_v0) + (0x68))) + (arg0 * 0x58))) + (0x4C))) * 2) >> 0x1F;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/func_80800DC8_gcmapsects.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/gcmapsects_entrypoint_6.s")

s32 func_80801174_gcmapsects(void *arg0, s32 arg1) {
    s32 func_800E3D0C(f32 *, f32 *);
    s32 func_800E3E8C(f32 *, f32);
    struct section {
        u8 pad0[0xC];
        f32 min[3];
        f32 max[3];
        f32 point[3];
        f32 radius;
        u8 pad34[4];
        u8 adjacent[4];
        u8 pad3C[0x10];
        u32 visible : 1;
        u32 flag : 1;
        u32 tested : 1;
        u32 unused : 1;
        u32 special : 1;
        u32 unused2 : 2;
        u32 special2 : 1;
        u32 rest : 24;
        u8 pad50[8];
    };
    struct map {
        u8 pad0[0x68];
        struct section *sections;
        u8 pad6C[0xF];
        u8 special;
        u8 pad7C[2];
        u8 special2;
    };
    s32 i;

    if (((struct map *)arg0)->sections[arg1].visible) {
        return 1;
    }
    if (func_800E3E8C(((struct map *)arg0)->sections[arg1].point, ((struct map *)arg0)->sections[arg1].radius)) {
        if (func_800E3D0C(((struct map *)arg0)->sections[arg1].min, ((struct map *)arg0)->sections[arg1].max)) {
            ((struct map *)arg0)->sections[arg1].visible = 1;
            ((struct map *)arg0)->sections[arg1].tested = 1;
            if (((struct map *)arg0)->sections[arg1].special) {
                ((struct map *)arg0)->special = 1;
            }
            if (((struct map *)arg0)->sections[arg1].special2) {
                ((struct map *)arg0)->special2 = 1;
            }
            for (i = 0; i != 4; i++) {
                if (((struct map *)arg0)->sections[arg1].adjacent[i] == 0xFF) {
                    break;
                }
                ((struct map *)arg0)->sections[((struct map *)arg0)->sections[arg1].adjacent[i]].visible = 1;
                ((struct map *)arg0)->sections[((struct map *)arg0)->sections[arg1].adjacent[i]].tested = 1;
            }
            return 1;
        }
    }
    return 0;
}

/* extern */

s32 func_80801320_gcmapsects(void *arg0, s32 arg1, f32 arg2[3]) {
    s32 func_800EFFB4(f32 point[3], f32 radius, f32 center[3]);
    struct section {
        u8 pad0[0x24];
        f32 point[3];
        f32 radius;
        u8 pad34[0x18];
        u32 high : 1;
        u32 flag : 1;
        u32 tested : 1;
        u32 rest : 29;
        u8 pad50[8];
    };
    struct map {
        u8 pad0[0x68];
        struct section *sections;
    };
    if (((struct map *)arg0)->sections[arg1].flag) {
        return 1;
    }
    if (func_800EFFB4(((struct map *)arg0)->sections[arg1].point, ((struct map *)arg0)->sections[arg1].radius, arg2)) {
        ((struct map *)arg0)->sections[arg1].tested = 1;
        ((struct map *)arg0)->sections[arg1].flag = 1;
        return 1;
    }
    return 0;
}

void func_808013C0_gcmapsects(void *arg0, s32 arg1)
{
  struct section
  {
    u8 pad0[0x3C];
    u8 neighbors[4];
    u8 pad40[0xC];
    u32 high : 1;
    u32 flag : 1;
    u32 rest : 30;
    u8 pad50[8];
  };
  struct map
  {
    u8 pad0[0x68];
    struct section *sections;
  };
  struct section *temp_v0;
  s32 var_v1;
  u8 temp_a2;
  struct section *temp_a3;
  temp_v0 = 0;
  var_v1 = 0;
  if (((struct map *) arg0)->sections[arg1].flag)
  {
    do
    {
      temp_v0 = *((struct section * volatile *) (((u8 *) arg0) + 0x68));
      temp_a2 = temp_v0[arg1].neighbors[var_v1];
      if (temp_a2 == 0xFF)
      {
        break;
      }
      var_v1 += 1;
      ;
      (&temp_v0[temp_a2])->high = 0;
      if ((!var_v1) && (!var_v1))
      {
      }
    }
    while (var_v1 != 4);
  }
}

s32 gcmapsects_entrypoint_7(f32 arg0[3]) {
    void *func_800BF704(void);
    int func_800EFED0(f32 min[3], f32 max[3], f32 vec[3]);
    s32 func_800EFFB4(f32 point[3], f32 radius, f32 center[3]);
    u8 *map;
    u8 *section;
    s32 index;
    s32 offset;

    map = func_800BF704();
    index = *(s16 *)(map + 0x74);
    if (index != -1) {
        section = *(u8 **)(map + 0x68) + index * 0x58;
        if (func_800EFED0((f32 *)(section + 0xC), (f32 *)(section + 0x18), arg0)) {
            return index;
        }
    }
    index = 0;
    offset = 0;
    if (map[0x77] > 0) {
        do {
            section = *(u8 **)(map + 0x68) + offset;
            if (func_800EFFB4((f32 *)(section + 0x24), *(f32 *)(section + 0x30), arg0)) {
                section = *(u8 **)(map + 0x68) + offset;
                if (func_800EFED0((f32 *)(section + 0xC), (f32 *)(section + 0x18), arg0)) {
                    return index;
                }
            }
            index++;
            offset += 0x58;
        } while (index < map[0x77]);
    }
    return -1;
}

void gcmapsects_entrypoint_8(void *arg0) {
    *(u8 *)((u8 *)arg0 + 0x78) = 0;
}

/* extern */

void func_80801554_gcmapsects(void *arg0) {
    void func_8008FE68(f32 *);
    s32 func_80090128();
    s32 func_80800DC8_gcmapsects(void *, s32, f32 *);
    s32 temp_v0;
    f32 sp38[3];
    s32 var_s3;
    s32 var_s0;

    func_8008FE68(sp38);
    if (func_80090128() != 0) {
        if ((*(u8 *)((s8 *)(arg0) + (0x80))) == 0) {
            var_s3 = -1;
            var_s0 = 0;
            if ((s32) (*(u8 *)((s8 *)(arg0) + (0x77))) > 0) {
                do {
                    temp_v0 = func_80800DC8_gcmapsects(arg0, var_s0, sp38);
                    if (temp_v0 != -1) {
                        var_s3 = temp_v0;
                    }
                    var_s0 += 1;
                } while (var_s0 < (s32) (*(u8 *)((s8 *)(arg0) + (0x77))));
            }
            (*(s16 *)((s8 *)(arg0) + (0x74))) = var_s3;
            (*(s8 *)((s8 *)(arg0) + (0x82))) = 1;
            return;
        }
        var_s0 = 0;
        if ((s32) (*(u8 *)((s8 *)(arg0) + (0x77))) > 0) {
            do {
                func_80801320_gcmapsects(arg0, var_s0, sp38);
                var_s0 += 1;
            } while (var_s0 < (s32) (*(u8 *)((s8 *)(arg0) + (0x77))));
        }
    }
}

void func_80801640_gcmapsects(void *arg0) {
    void func_800E3980(f32 *);
    s32 func_80800DC8_gcmapsects(void *, s32, f32 *);
    s32 func_80801174_gcmapsects(void *, s32);
    f32 sp30[4];
    s32 i;

    func_800E3980(sp30);
    if ((*(u8 *)((s8 *)arg0 + 0x80)) == 0) {
        for (i = 0; i < (s32)(*(u8 *)((s8 *)arg0 + 0x77)); i++) {
            func_80800DC8_gcmapsects(arg0, i, sp30);
        }
    } else {
        for (i = 0; i < (s32)(*(u8 *)((s8 *)arg0 + 0x77)); i++) {
            func_80801174_gcmapsects(arg0, i);
            func_80801320_gcmapsects(arg0, i, sp30);
        }
        for (i = 0; i < (s32)(*(u8 *)((s8 *)arg0 + 0x77)); i++) {
            func_808013C0_gcmapsects(arg0, i);
        }
    }
}

void func_80801724_gcmapsects(void *arg0, s32 arg1) {
    void func_800F4CC0(s32);
    void func_800F4CEC(s32, u32);
    u32 func_800F54E4(void);
    u8 *ptr = arg0;

    switch (ptr[0x7F]) {
    case 1:
        break;
    case 2:
        func_800F4CC0(func_800F54E4());
        break;
    }
    ptr[0x7F] = arg1;
    switch (ptr[0x7F]) {
    case 1:
        break;
    case 2:
        func_800F4CEC(func_800F54E4(), 0x77);
        break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/gcmapsects_entrypoint_9.s")

void gcmapsects_entrypoint_10(s32 arg0) {
    void *func_800BF704();
    void* heap_alloc(s32 size);
    u8 *temp_v0;
    u8 *sp1C;

    temp_v0 = func_800BF704();
    if (arg0 != 0) {
        (*(s8 *)((s8 *)(temp_v0) + (0x76))) = (s8) arg0;
        sp1C = temp_v0;
        (*(u8 **)((s8 *)(sp1C) + (0x68))) = heap_alloc((arg0 & 0xFF) * 0x58);
    }
}

/* extern */

void gcmapsects_entrypoint_11(s32 arg0, s32 arg1) {
    void *func_800BF704();
    void *temp_v0;

    temp_v0 = func_800BF704();
    (*(s8 *)((s8 *)(temp_v0) + (0x79))) = (s8) arg0;
    (*(s8 *)((s8 *)(temp_v0) + (0x7D))) = (s8) arg1;
}

/* extern */

void gcmapsects_entrypoint_12(s32 arg0) {
    void *func_800BF704();
    (*(s32 *)((s8 *)(func_800BF704()) + (0x6C))) = arg0;
}

/* extern */

void gcmapsects_entrypoint_13(s32 arg0) {
    void *func_800BF704();
    (*(s8 *)((s8 *)(func_800BF704()) + (0x80))) = (s8) arg0;
}

/* extern */

void gcmapsects_entrypoint_14(s32 arg0) {
    void *func_800BF704();
    (*(s8 *)((s8 *)(func_800BF704()) + (0x81))) = (s8) arg0;
}

void gcmapsects_entrypoint_15(void *arg0) {
    s32 func_800EA05C();
    s32 i;
    s32 offset;
    struct EntryFlags {
        u8 pad[0x4C];
        u32 active : 1;
        u32 enabled : 1;
        u32 visible : 1;
        u32 unused : 2;
        u32 saved : 1;
    } *entry;

    *(s32 *)((u8 *)arg0 + 0x68) = 0;
    *((u8 *)arg0 + 0x77) = 0;
    *((u8 *)arg0 + 0x76) = 0;
    *((u8 *)arg0 + 0x78) = 0;
    *((u8 *)arg0 + 0x7C) = 0;
    *((u8 *)arg0 + 0x7B) = 1;
    *((u8 *)arg0 + 0x7E) = 1;
    *((u8 *)arg0 + 0x7A) = 1;
    *((u8 *)arg0 + 0x7F) = 3;
    *(s16 *)((u8 *)arg0 + 0x74) = -1;
    *((u8 *)arg0 + 0x82) = 0;
    *(s32 *)((u8 *)arg0 + 0x6C) = 0;
    *((u8 *)arg0 + 0x79) = 0;
    *((u8 *)arg0 + 0x7D) = 0;
    *((u8 *)arg0 + 0x80) = 0;
    *((u8 *)arg0 + 0x81) = 0;
    *(f32 *)((u8 *)arg0 + 0x70) = 0.0f;
    switch (func_800EA05C()) {
        case 0x1A7:
            _gcmapsects_lagoontop_entrypoint_0();
            *((u8 *)arg0 + 0x83) = 1;
            break;
        case 0x1A8:
            _gcmapsects_lagoonmid_entrypoint_0();
            *((u8 *)arg0 + 0x83) = 1;
            break;
        case 0x1A9:
            _gcmapsects_lagoonbot_entrypoint_0();
            *((u8 *)arg0 + 0x83) = 1;
            break;
    }
    if (*((u8 *)arg0 + 0x77) != 0) {
        func_80801724_gcmapsects(arg0, 1);
    }
    i = 0;
    if (*((u8 *)arg0 + 0x77) > 0) {
        offset = 0;
        do {
            i++;
            entry = (struct EntryFlags *)(*(u8 **)((u8 *)arg0 + 0x68) + offset);
            entry->active = 0;
            entry = (struct EntryFlags *)(*(u8 **)((u8 *)arg0 + 0x68) + offset);
            entry->enabled = 1;
            entry = (struct EntryFlags *)(*(u8 **)((u8 *)arg0 + 0x68) + offset);
            entry->saved = entry->visible;
            entry = (struct EntryFlags *)(*(u8 **)((u8 *)arg0 + 0x68) + offset);
            entry->visible = *((u8 *)arg0 + 0x83);
            offset += 0x58;
        } while (i < *((u8 *)arg0 + 0x77));
    }
    func_80800A08_gcmapsects(arg0, *((u8 *)arg0 + 0x83));
}

/* extern */

void gcmapsects_entrypoint_16(void *arg0) {
    s32 heap_free(s32, void *);
    if (((*(u8 *)((s8 *)(arg0) + (0x77))) != 0) || ((*(u8 *)((s8 *)(arg0) + (0x76))) != 0)) {
        func_80800C54_gcmapsects(arg0);
        heap_free((*(s32 *)((s8 *)(arg0) + (0x68))), arg0);
        (*(s32 *)((s8 *)(arg0) + (0x68))) = 0;
        (*(u8 *)((s8 *)(arg0) + (0x77))) = 0U;
        (*(u8 *)((s8 *)(arg0) + (0x76))) = 0U;
        (*(s8 *)((s8 *)(arg0) + (0x78))) = 0;
        (*(s8 *)((s8 *)(arg0) + (0x7B))) = 1;
        (*(s8 *)((s8 *)(arg0) + (0x7E))) = 1;
        (*(s8 *)((s8 *)(arg0) + (0x7C))) = 0;
        (*(s8 *)((s8 *)(arg0) + (0x7F))) = 3;
        (*(f32 *)((s8 *)(arg0) + (0x70))) = 0.0f;
    }
}

void gcmapsects_entrypoint_17(void *arg0)
{
  s32 func_800BF4DC(s32, u8, void *);
  s32 func_800BFF28();
  u8 *new_var;
  s32 func_800BFF4C();
  void func_80801640_gcmapsects(void *);
  u8 temp_v0;
  func_80801640_gcmapsects(arg0);
  ;
  if ((*((u8 *) (((s8 *) arg0) + 0x7A))) != (*((u8 *) (((s8 *) arg0) + 0x7B))))
  {
    if ((*((u8 *) (((s8 *) arg0) + 0x7B))) != 0)
    {
      if (1)
      {
        func_800BFF4C();
      }
    }
    else
    {
      func_800BFF28();
    }
    *((u8 *) (((s8 *) arg0) + 0x7A)) = (u8) (*(new_var = (u8 *) (((s8 *) arg0) + 0x7B)));
  }
  func_800BF4DC(1, *((u8 *) (((s8 *) arg0) + 0x7E)), arg0);
}

void gcmapsects_entrypoint_18(u8 *arg0, s32 arg1) {
    s32 func_800B2840(s32);
    void func_800BF774(void);
    s32 func_800D62E4(s32);
    s32 func_800D674C(s32);
    s32 func_800D731C(s32);
    void *func_800DE448(f32 *, f32 *, f32, f32 *, s32);
    f32 func_800DF428(f32);
    void func_800DF440(s32);
    void func_800DF4B0(s32);
    void func_800DF7DC(s32);
    void func_800DF7E8(u8);
    void func_800DF818(s32);
    void func_800DF830(s32);
    struct Section {
        f32 position[16];
        u16 asset;
        u8 pad42[2];
        s32 textures;
        u8 pad48[4];
        u32 flag : 1;
        u32 rest : 31;
        u8 pad50[8];
    };
    s32 i;
    s32 asset;
    s32 vertices;
    s32 animated;
    u8 animatedId;
    s32 assetId;
    struct Section *section;

    for (i = 0; i < arg0[0x77]; i++) {
        section = &(*(struct Section **)(arg0 + 0x68))[i];
        if (!section->flag) {
            continue;
        }
        assetId = section->asset;
        if (!assetId) {
            continue;
        }
        asset = func_800D674C(assetId);
        if (!asset) {
            continue;
        }
        vertices = func_800B2840(asset);
        func_800BF774();
        func_800DF830(1);
        animated = func_800D731C(assetId);
        animatedId = animated;
        if (animated) {
            func_800DF7E8(animatedId);
        }
        func_800DF7DC((*(struct Section **)(arg0 + 0x68))[i].textures);
        func_800DF818(vertices);
        func_800DF440(0);
        func_800DF428(29999.0f);
        func_800DF4B0(2);
        if (!func_800DE448((*(struct Section **)(arg0 + 0x68))[i].position, NULL, 1.0f, NULL, asset)) {
            func_800D62E4((*(struct Section **)(arg0 + 0x68))[i].asset);
        }
    }
}

void gcmapsects_entrypoint_19(u8 *arg0, s32 arg1) {
    s32 func_800B2840(s32);
    void func_800BF774(void);
    s32 func_800D62E4(s32);
    s32 func_800D674C(s32);
    void *func_800DE448(f32 *, f32 *, f32, f32 *, s32);
    f32 func_800DF428(f32);
    void func_800DF440(s32);
    void func_800DF4B0(s32);
    void func_800DF7DC(s32);
    void func_800DF818(s32);
    void func_800DF830(s32);
    struct Section {
        u8 pad0[0x42];
        u16 asset;
        u8 pad44[4];
        s32 textures;
        u32 flag : 1;
        u32 rest : 31;
        u8 pad50[8];
    };
    s32 i;
    s32 asset;
    s32 vertices;
    struct Section *section;

    for (i = 0; i < arg0[0x77]; i++) {
        section = &(*(struct Section **)(arg0 + 0x68))[i];
        if (!section->flag) {
            continue;
        }
        if (!section->asset) {
            continue;
        }
        asset = func_800D674C(section->asset);
        if (!asset) {
            continue;
        }
        vertices = func_800B2840(asset);
        func_800BF774();
        func_800DF830(2);
        func_800DF440(0);
        func_800DF428(29999.0f);
        func_800DF7DC((*(struct Section **)(arg0 + 0x68))[i].textures);
        func_800DF818(vertices);
        func_800DF4B0(2);
        if (!func_800DE448((f32 *)&(*(struct Section **)(arg0 + 0x68))[i], NULL, 1.0f, NULL, asset)) {
            func_800D62E4((*(struct Section **)(arg0 + 0x68))[i].asset);
        }
    }
}

/* extern */

s32 gcmapsects_entrypoint_20(u8 *arg0, f32 *arg1, f32 *arg2, s16 (**arg3)[3], s32 arg4, f32 arg5) {
    s32 func_800AD2C8(void *, void *, f32 *, f32 *, f32 *, s16 (**)[3], s32, f32);
    u8 *func_800B2720(u8 *);
    s32 func_800B2840(s32);
    s32 func_800D674C(s32);
    struct Section {
        u8 pad0[0x40];
        u16 asset;
        u8 pad42[0xA];
        u32 unused : 1;
        u32 flag : 1;
        u32 rest : 30;
        u8 pad50[8];
    };
    s32 sp3C;
    u8 *sp38;
    s32 temp_v0;
    s32 asset_id;
    struct Section *sections;
    s32 offset;
    s32 i;
    u8 count;
    struct Section *section;

    count = arg0[0x77];
    i = 0;
    offset = 0;
    if (count > 0) {
        sections = *(struct Section **)(arg0 + 0x68);
        section = sections;
        do {
            i++;
            if (section->flag) {
                asset_id = section->asset;
                temp_v0 = func_800D674C(asset_id);
                sp3C = temp_v0;
                sp38 = func_800B2720(sp3C);
                return func_800AD2C8(sp38, func_800B2840(sp3C), arg1, arg2,
                    (f32 *)(*(u8 **)(arg0 + 0x68) + offset), arg3, arg4, arg5);
            }
            offset += 0x58;
            section++;
        } while (i < arg0[0x77]);
    }
    return 0;
}

/* extern */

s32 gcmapsects_entrypoint_21(u8 *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 arg4) {
    s32 func_800AD894(void *, void *, f32 *, f32 *, f32 *, f32 *, f32);
    u8 *func_800B2720(u8 *);
    s32 func_800B2840(s32);
    s32 func_800D674C(s32);
    struct Section {
        u8 pad0[0x40];
        u16 asset;
        u8 pad42[0xA];
        u32 unused : 1;
        u32 flag : 1;
        u32 rest : 30;
        u8 pad50[8];
    };
    s32 sp3C;
    u8 *sp38;
    s32 temp_v0;
    s32 asset_id;
    struct Section *sections;
    s32 offset;
    s32 i;
    u8 count;
    struct Section *section;

    count = arg0[0x77];
    i = 0;
    offset = 0;
    if (count > 0) {
        sections = *(struct Section **)(arg0 + 0x68);
        section = sections;
        do {
            i++;
            if (section->flag) {
                asset_id = section->asset;
                temp_v0 = func_800D674C(asset_id);
                sp3C = temp_v0;
                sp38 = func_800B2720(sp3C);
                return func_800AD894(sp38, func_800B2840(sp3C), arg1, arg2, arg3,
                    (f32 *)(*(u8 **)(arg0 + 0x68) + offset), arg4);
            }
            offset += 0x58;
            section++;
        } while (i < arg0[0x77]);
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/gcmapsects_entrypoint_22.s")

s32 gcmapsects_entrypoint_23(u8 *arg0, f32 *arg1, f32 *arg2, f32 arg3, f32 *arg4, s32 arg5, s32 arg6) {
    s32 func_800AC848(s32, s32, f32 *, f32 *, f32, f32 *, f32 *, f32, f32 *, s32, s32);
    u8 *func_800B2720(u8 *);
    s32 func_800B2840(s32);
    void func_800BEB58(s32);
    s32 func_800D62E4(s32);
    s32 func_800D674C(s32);
    struct Section {
        u8 pad0[0x40];
        u16 asset;
        u8 pad42[0xA];
        u32 unused : 1;
        u32 flag : 1;
        u32 rest : 30;
    } *section;
    s32 result = 0;
    s32 list;
    s32 asset;
    s32 i;
    s32 offset;

    if (arg0[0x77] == 0) {
        return 0;
    }
    func_800BEB58(0);
    for (i = 0, offset = 0; i < arg0[0x77]; i++, offset += 0x58) {
        section = (struct Section *)(*(u8 **)(arg0 + 0x68) + offset);
        if (section->flag) {
            asset = func_800D674C(section->asset);
            if (asset != 0) {
                func_800D62E4(((struct Section *)(*(u8 **)(arg0 + 0x68) + offset))->asset);
                list = func_800B2720(asset);
                result = func_800AC848(list, func_800B2840(asset),
                    (f32 *)(*(u8 **)(arg0 + 0x68) + offset), 0, 1.0f,
                    arg1, arg2, arg3, arg4, arg5, arg6);
                if (result != 0) {
                    func_800BEB58(asset);
                    break;
                }
            }
        }
    }
    return result;
}

int gcmapsects_entrypoint_24(void *arg0) {
    return (*(u8 *)((s8 *)arg0 + 0x82) != 0) &&
           ((*(s16 *)((s8 *)arg0 + 0x74) + 1) == 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/gcmapsects_entrypoint_25.s")

void *gcmapsects_entrypoint_26(u8 *arg0, f32 *arg1, f32 arg2, f32 *arg3, u32 arg4) {
    void *func_800AD1AC(u16 *, u16 *, f32 *, f32 *, f32, f32 *, f32, f32 *, u32);
    u8 *func_800B2720(u8 *);
    s32 func_800B2840(s32);
    void func_800BEB58(s32);
    s32 func_800D62E4(s32);
    s32 func_800D674C(s32);
    struct Section {
        u8 pad0[0x40];
        u16 asset;
        u8 pad42[0xA];
        u32 unused : 1;
        u32 flag : 1;
        u32 rest : 30;
    } *section;
    void *result = 0;
    void *list;
    s32 asset;
    s32 i;
    s32 offset;

    if (arg0[0x77] == 0) {
        return 0;
    }
    func_800BEB58(0);
    for (i = 0, offset = 0; i < arg0[0x77]; i++, offset += 0x58) {
        section = (struct Section *)(*(u8 **)(arg0 + 0x68) + offset);
        if (section->flag) {
            asset = func_800D674C(section->asset);
            if (asset != 0) {
                func_800D62E4(((struct Section *)(*(u8 **)(arg0 + 0x68) + offset))->asset);
                list = func_800B2720(asset);
                result = func_800AD1AC(list, func_800B2840(asset),
                    (f32 *)(*(u8 **)(arg0 + 0x68) + offset), 0, 1.0f,
                    arg1, arg2, arg3, arg4);
                if (result != 0) {
                    func_800BEB58(asset);
                    break;
                }
            }
        }
    }
    return result;
}

/* extern */

s32 gcmapsects_entrypoint_27(s32 arg0) {
    void *func_800BF704(void);
    s32 func_800D62E4(s32);
    s32 func_800D6B0C(s32);
    void *map;
    s32 temp_t7;

    if ((*(u8 *)((s8 *)(map = func_800BF704()) + (0x77))) == 0) {
        return 0;
    }
    temp_t7 = arg0 * 0x58;
    if (((u32) (*(u32 *)((s8 *)(((*(s32 *)((s8 *)(map) + (0x68))) + temp_t7)) + (0x4C))) >> 0x1F) != 0) {
        if (func_800D6B0C((*(u16 *)((s8 *)(((*(s32 *)((s8 *)(map) + (0x68))) + temp_t7)) + (0x40)))) != 0) {
            func_800D62E4((*(u16 *)((s8 *)(((*(s32 *)((s8 *)(map) + (0x68))) + temp_t7)) + (0x40))));
            return 1;
        }
    }
    return 0;
}
