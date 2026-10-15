#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/gcmapsects_entrypoint_0.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/func_8080035C_gcmapsects.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/func_808003F4_gcmapsects.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/gcmapsects_entrypoint_3.s")

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
    s32 func_8080035C_gcmapsects(void *, s32);
    s32 func_808003F4_gcmapsects(void *, s32);
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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/gcmapsects_entrypoint_4.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/func_80801174_gcmapsects.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/gcmapsects_entrypoint_7.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/func_80801640_gcmapsects.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/func_80801724_gcmapsects.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/gcmapsects_entrypoint_15.s")

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
  s32 func_80801640_gcmapsects();
  u8 temp_v0;
  func_80801640_gcmapsects();
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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/gcmapsects_entrypoint_18.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/gcmapsects_entrypoint_19.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/gcmapsects_entrypoint_23.s")

int gcmapsects_entrypoint_24(void *arg0) {
    return (*(u8 *)((s8 *)arg0 + 0x82) != 0) &&
           ((*(s16 *)((s8 *)arg0 + 0x74) + 1) == 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/gcmapsects_entrypoint_25.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/mapsects/gcmapsects_entrypoint_26.s")

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
