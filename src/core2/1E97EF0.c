#include "common.h"

struct Entry { s32 value; u8 padding[40]; };
extern struct Entry D_801285B4[];

extern s32 D_801285B0;
extern s32 D_80128728;
extern s32 D_8012872C;
extern s32 D_80128760;


#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E97EF0/func_800BE600.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E97EF0/func_800BE7F8.s")

/* extern */

void func_800BE9B0(void) {
    s32 _gcmapsects_entrypoint_17(s32 *);
    if ((*(u8 *)((s8 *)(&D_801285B0) + (0x77))) != 0) {
        _gcmapsects_entrypoint_17(&D_801285B0);
    }
}

/* extern */

void func_800BE9E4(s32 arg0) {
    s32 _gcmapsects_entrypoint_18(s32 *, s32);
    s32 func_800BE7F8(s32, s32);
    func_800BE7F8(arg0, 0);
    if ((*(u8 *)((s8 *)(&D_801285B0) + (0x77))) != 0) {
        _gcmapsects_entrypoint_18(&D_801285B0, arg0);
    }
}

/* extern */

void func_800BEA24(s32 arg0) {
    s32 _gcmapsects_entrypoint_19(s32 *, s32);
    s32 func_800BE7F8(s32, s32);
    func_800BE7F8(arg0, 1);
    if ((*(u8 *)((s8 *)(&D_801285B0) + (0x77))) != 0) {
        _gcmapsects_entrypoint_19(&D_801285B0, arg0);
    }
}

void func_800BEA64(f32 *arg0) {
    func_800BE600(arg0, 0x20020);
}

s32 func_800BEA88(s32 arg0) {
    return D_801285B4[arg0].value;
}

/* extern */

s32 func_800BEAAC(s32 arg0, s32 arg1) {
    extern u8 D_80128627;
    s32 _gcmapsects_entrypoint_6(s32 *, s32, s32);
    if (D_80128627 != 0) {
        return _gcmapsects_entrypoint_6(&D_801285B0, arg0, arg1);
    }
    return 0;
}

/* extern */

void func_800BEAF4(void) {
    s32 _gcmapsects_entrypoint_8(s32 *);
    if ((*(u8 *)((s8 *)(&D_801285B0) + (0x77))) != 0) {
        _gcmapsects_entrypoint_8(&D_801285B0);
    }
}

s32 func_800BEB28(s32 arg0) {
    extern struct Entry D_801285BC[];
    return D_801285BC[arg0].value;
}

s32 func_800BEB4C()
{
    return D_80128760;
}

void func_800BEB58(s32 arg0) {
    *(s32 *)((u8 *)&D_80128760 + 0) = arg0;
}

s32 func_800BEB64(s32 arg0) {
    struct Entry {
        s32 pad[4];
        s32 values[6];
        u8 pad28;
        u8 index;
        u8 pad2A[2];
    } *entry;

    entry = &((struct Entry *)&D_801285B0)[arg0];
    return entry->values[entry->index];
}

s32 func_800BEB98(s32 arg0) {
    struct Entry { s32 value; s32 pad[10]; };
    extern struct Entry D_801285C4[];
    return D_801285C4[arg0].value != 0 ? 2 : 1;
}

void func_800BEBD4(s32 arg0) {
    u8 *func_800B27A0(u8 *arg0);
    func_800B27A0(*(u8 **)((u8 *)&D_801285B0 + 0xC + arg0 * 44));
}

s32 func_800BEC10()
{
    return D_80128728;
}

s32 func_800BEC1C()
{
    return D_8012872C;
}

s32 func_800BEC28(s32 arg0) {
    struct Entry { s32 value; u8 padding[40]; };
    extern struct Entry D_801285D0[];
    return D_801285D0[arg0].value;
}

void func_800BECE0(s32 *arg0, s32 *arg1);
void func_800BEC4C(s32 *arg0, s32 *arg1, s32 arg2) { extern s8 D_801285B3; s8 *var_v0; s32 *var_v1; s32 *var_a0; s8 *end; func_800BECE0(arg0, arg1); func_800E37E8(arg0, arg1, arg2); end = &D_801285B3; var_v0 = (s8 *)&D_801285B0; var_v1 = arg0; var_a0 = arg1; do { *var_v1 += var_v0[0x5E]; var_v0++; var_v1++; *var_a0 += var_v0[0x60]; var_a0++; if (var_v0 == end) break; } while (1); }

f32 func_800BECCC(void) {
    extern s32 D_80128734;
    return (f32) D_80128734;
}

void func_800BECE0(s32 *arg0, s32 *arg1) {
    void func_800EE830(s32 dst[3], s32 src[3]);
    extern s32 D_80128730;
    extern s32 D_8012873C;
    func_800EE830(arg0, &D_80128730);
    func_800EE830(arg1, &D_8012873C);
}

void func_800BED18(s32 *arg0, s32 *arg1) {
    void func_800EE830(s32 dst[3], s32 src[3]);
    extern s32 D_80128748;
    extern s32 D_80128754;
    func_800EE830(arg0, &D_80128748);
    func_800EE830(arg1, &D_80128754);
}

void func_800BED50(s32 arg0)
{
    func_800BE600(arg0,0x1F00);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E97EF0/func_800BED70.s")

/* extern */

s32 func_800BEE40(f32 *arg0, f32 *arg1, f32 *arg2, f32 arg3) {
    s32 _gcmapsects_entrypoint_21(s32 *, f32 *, f32 *, f32 *, f32);
    s32 func_800AD894(void *, void *, f32 *, f32 *, f32 *, f32 *, f32);
    void func_800EFD24(f32 *);
    f32 sp30[4];

    if ((*(u8 *)((s8 *)(&D_801285B0) + (0x2A))) != 0) {
        func_800EFD24(sp30);
        if (func_800AD894((*(void **)((s8 *)(&D_801285B0) + (0))), ((void **)&D_801285B0)[*(u8 *)((s8 *)&D_801285B0 + 0x29) + 4], arg0, arg1, arg2, sp30, arg3) != 0) {
            return 1;
        }
    }
    if ((*(u8 *)((s8 *)(&D_801285B0) + (0x77))) != 0) {
        return _gcmapsects_entrypoint_21(&D_801285B0, arg0, arg1, arg2, arg3);
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E97EF0/func_800BEF00.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E97EF0/func_800BF0E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E97EF0/func_800BF228.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E97EF0/func_800BF340.s")

int func_800BF3E4(void) {
    return (*(u16 *)((s8 *)&D_801285B0 + 0x5A) != 0 ||
            *(u8 *)((s8 *)&D_801285B0 + 0x77) != 0) &&
           *(u16 *)((s8 *)&D_801285B0 + 0x5C) != 0;
}

void func_800BF420()
{
    _gcmapDll_entrypoint_4(&D_801285B0);
}

void func_800BF444(void) {
    s32 _gcmapDll_entrypoint_3(s32 *);
    s32 func_800C6A28(s32 *, s32 *, s32 *, s32 (*)());
    extern s32 func_800BEF00;
    extern s32 func_800BF0E0;
    extern s32 func_800BF228;
    _gcmapDll_entrypoint_3(&D_801285B0);
    func_800C6A28(&func_800BEF00, &func_800BF0E0, &func_800BF228, func_800BEB4C);
}

void func_800BF48C(s32 arg0, s32 arg1, s32 arg2) {
    (*(s8 *)((s8 *)(&D_801285B0) + (0x85))) = arg0;
    (*(s8 *)((s8 *)(&D_801285B0) + (0x86))) = arg1;
    (*(s8 *)((s8 *)(&D_801285B0) + (0x87))) = arg2;
}

void func_800BF4A4(s32 arg0, s32 arg1) {
    void *temp_v0;

    temp_v0 = (arg0 * 0x2C) + (s8 *)&D_801285B0;
    if ((*(s32 *)((s8 *)(temp_v0) + (0))) != 0) {
        (*(s8 *)((s8 *)(temp_v0) + (0x2A))) = arg1;
    }
}

/* extern */

void func_800BF4DC(s32 arg0, s32 arg1) {
    s32 _idworldmake_entrypoint_5(s32);
    if (arg1 != *(u8 *)((s8 *)&D_801285B0 + arg0 * 0x2C + 0x2B)) {
        if (*(s32 *)((s8 *)&D_801285B0 + arg0 * 0x2C + 4) != 0) {
            _idworldmake_entrypoint_5(*(s32 *)((s8 *)&D_801285B0 + arg0 * 0x2C + 4));
        }
    }
    *(u8 *)((s8 *)&D_801285B0 + arg0 * 0x2C + 0x2B) = arg1;
}

void func_800BF544(s32 arg0, s32 arg1, s32 arg2) {
    s32 _idworldmake_entrypoint_6(s32, s32, s32);
    s32 temp_a3;

    temp_a3 = D_801285B4[arg0].value;
    if (temp_a3 != 0) {
        _idworldmake_entrypoint_6(temp_a3, arg1, arg2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E97EF0/func_800BF58C.s")

void func_800BF68C(void) {
    s32 _gcmapDll_entrypoint_1(s32 *);
    extern s8 D_80128634;
    _gcmapDll_entrypoint_1(&D_801285B0);
    D_80128634 = -1;
}

/* extern */

s32 func_800BF6B8(void) {
    s32 _gcmapsects_entrypoint_24(s32 *);
    s32 var_v0;

    var_v0 = 0;
    if ((*(u8 *)((s8 *)(&D_801285B0) + (0x77))) != 0) {
        if (_gcmapsects_entrypoint_24(&D_801285B0) != 0) {
            return 2;
        }
        var_v0 = 1;
        /* Duplicate return node #4. Try simplifying control flow for better match */
        return var_v0;
    }
    return var_v0;
}

void * func_800BF704(void) {
    return &D_801285B0;
}

/* extern */

void func_800BF710(void) {
    s32 _gcmapsects_entrypoint_9(s32 *);
    if ((*(u8 *)((s8 *)(&D_801285B0) + (0x77))) != 0) {
        _gcmapsects_entrypoint_9(&D_801285B0);
    }
}

void func_800BF744(s32 arg0, s32 arg1) {
    (*(s32 *)((s8 *)(&(&D_801285B0)[arg0]) + (0x88))) = arg1;
    if ((*(s32 *)((s8 *)(&D_801285B0) + (0x88))) < arg0) {
        (*(s32 *)((s8 *)(&D_801285B0) + (0x88))) = arg0;
    }
}

void func_800BF774(void) {
    void func_800DF744(s32, s32);
    s32 *var_s1;
    s32 var_s0;

    var_s0 = 1;
    if ((*(s32 *)((s8 *)(&D_801285B0) + (0x88))) > 0) {
        var_s1 = &D_801285B4;
        do {
            func_800DF744(var_s0, (*(s32 *)((s8 *)(var_s1) + (0x88))));
            var_s0 += 1;
            var_s1 += 1;
        } while ((*(s32 *)((s8 *)(&D_801285B0) + (0x88))) >= var_s0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E97EF0/func_800BF7E0.s")

u32 func_800BF8B0(void) {
    extern u8 D_80128627;
    return *(u8 *)((u8 *)&D_80128627 + 0);
}

/* extern */

void func_800BF8BC(s32 arg0) {
    s32 _gcmapDll_entrypoint_6(s32 *, s32);
    _gcmapDll_entrypoint_6(&D_801285B0, arg0);
}

s8 func_800BF8E4(void)
{
  s32 _dbvpl_entrypoint_0(s32, s32);
  extern s32 D_80128608;
  extern s8 D_80128634;
  s32 i;
  s8 var_v1;
  var_v1 = *((s8 *) (((s8 *) (&D_801285B0)) + 0x84));
  if (var_v1 == (-1))
  {
    *((s8 *) (((s8 *) (&D_801285B0)) + 0x84)) = 0;
    var_v1 = 0;
    i = 0;
    do
    {
      if ((*((s32 *) (((s8 *)&D_801285B0 + i * 0x2C) + 8))) != 0)
      {
        *((s8 *) (((s8 *) (&D_801285B0)) + 0x84)) = 1;
      }
      if (((*((s32 *) (((s8 *)&D_801285B0 + i * 0x2C) + 0x1C))) != 0) && (_dbvpl_entrypoint_0(*((s32 *) (((s8 *)&D_801285B0 + i * 0x2C) + 0x18)), 0) != 0))
      {
        *((s8 *) (((s8 *) (&D_801285B0)) + 0x84)) = 2;
      }
      i++;
    }
    while ((s8 *)&D_80128608 != (s8 *)&D_801285B0 + i * 0x2C);
    var_v1 = D_80128634;
  }
  return var_v1;
}

/* extern */

void func_800BF99C(s32 arg0, s32 arg1, s32 arg2) {
    s32 _idworldmake_entrypoint_7(s32, s32, s32);
    s32 _vpmodule_entrypoint_4(s32, s32, s32, s32);
    if (*(s32 *)((s8 *)&D_801285B0 + arg0 * 0x2C + 0x1C) != 0) {
        _vpmodule_entrypoint_4(*(s32 *)((s8 *)&D_801285B0 + arg0 * 0x2C + 0x1C), *(s32 *)((s8 *)&D_801285B0 + arg0 * 0x2C + 0x18), arg1, arg2);
    }
    if (*(s32 *)((s8 *)&D_801285B0 + arg0 * 0x2C + 4) != 0) {
        _idworldmake_entrypoint_7(*(s32 *)((s8 *)&D_801285B0 + arg0 * 0x2C + 4), arg1, arg2);
    }
}

s32 func_800BFA1C(f32 *arg0, s32 *var_a1) { extern struct Entry D_801285BC[]; s32 *end; s32 i = 0; f32 temp_f0; var_a1 = &D_801285B0; end = (s32 *)D_801285BC; while (1) { temp_f0 = arg0[i]; if (temp_f0 < (f32)(var_a1[96] - 100)) { return 0; } if ((f32)(var_a1[99] + 100) < temp_f0) { return 0; } var_a1++; i++; if (var_a1 == end) { break; } } return 1; }

u8 func_800BFAA4(void) {
    return (*(u8 *)((s8 *)(func_800BF704()) + (0x77)));
}
