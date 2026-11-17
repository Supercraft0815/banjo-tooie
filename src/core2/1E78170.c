#include "core2/1E78170.h"

s32 D_80127050[4];

extern s32 D_80127080;    typedef struct { f32 unk0; f32 unk4; f32 unk8; s8 unkC; u8 padD[0x3]; s16 unk10; s16 unk12; } Obj1E78170_D_80127040; /* offsets.py genstruct: fields from raw offsets on &D_80127040; rename once understood */ typedef struct { f32 unk0; f32 unk4; f32 unk8; s8 unkC; s8 unkD; s8 unkE; s8 unkF; s8 unk10; u8 pad11[0x7]; s32 unk18; } Obj1E78170_D_80127068; /* offsets.py genstruct: fields from raw offsets on &D_80127068; rename once understood */

void func_8009E880(void) {
    extern f32 D_80127040;
    extern f32 D_80127068;
    (((Obj1E78170_D_80127068 *)&D_80127068)->unkC) = 1;
    (((Obj1E78170_D_80127068 *)&D_80127068)->unkD) = 0;
    (((Obj1E78170_D_80127040 *)&D_80127040)->unkC) = 1;
    (((Obj1E78170_D_80127040 *)&D_80127040)->unk0) = 0.0f;
    (((Obj1E78170_D_80127040 *)&D_80127040)->unk4) = 0.0f;
    (((Obj1E78170_D_80127040 *)&D_80127040)->unk8) = 0.0f;
}

void func_8009E8B4(void)
{
    func_800C6E58();
}
void func_8009E8D4(void) {
    void func_800C6E60(void);
    u32 func_800D3B60(void);
    void func_8009EAE8(s32);
    extern f32 D_80127040;
    extern f32 D_80127068;

    func_800C6E60();
    (((Obj1E78170_D_80127040 *)&D_80127040)->unkC) = func_800D3B60();
    (((Obj1E78170_D_80127068 *)&D_80127068)->unk18) = 0;
    (((Obj1E78170_D_80127068 *)&D_80127068)->unkC) = 0;
    (((Obj1E78170_D_80127068 *)&D_80127068)->unkD) = 0;
    (((Obj1E78170_D_80127068 *)&D_80127068)->unkE) = 0;
    (((Obj1E78170_D_80127068 *)&D_80127068)->unkF) = 0;
    (((Obj1E78170_D_80127068 *)&D_80127068)->unk10) = 1;
    (((Obj1E78170_D_80127040 *)&D_80127040)->unk0) = 0.0f;
    (((Obj1E78170_D_80127040 *)&D_80127040)->unk4) = 0.0f;
    (((Obj1E78170_D_80127040 *)&D_80127040)->unk8) = 0.0f;
    (((Obj1E78170_D_80127068 *)&D_80127068)->unk0) = 0.0f;
    (((Obj1E78170_D_80127068 *)&D_80127068)->unk4) = 0.0f;
    (((Obj1E78170_D_80127068 *)&D_80127068)->unk8) = 0.0f;
    func_800DA524(FLAG_3EC_ABILITY_DRAGON_KAZOOIE);
    func_8009EAE8(0);
}    typedef struct { u8 unk0; } Obj1E78170_D_8012704C; /* offsets.py genstruct: fields from raw offsets on &D_8012704C; rename once understood */

u32 func_8009E958(void) {
    extern u8 D_8012704C;
    return *&((Obj1E78170_D_8012704C *)&D_8012704C)->unk0;
}    typedef struct { u8 unk0; } Obj1E78170_D_80127078; /* offsets.py genstruct: fields from raw offsets on &D_80127078; rename once understood */

u32 func_8009E964(void) {
    extern u8 D_80127078;
    return *&((Obj1E78170_D_80127078 *)&D_80127078)->unk0;
}    typedef struct { f32 unk0; } Obj1E78170_D_80127048; /* offsets.py genstruct: fields from raw offsets on &D_80127048; rename once understood */

f32 func_8009E970(void) {
    extern f32 D_80127048;
    return *&((Obj1E78170_D_80127048 *)&D_80127048)->unk0;
}

f32 func_8009E97C(void) {
    extern f32 D_80127040;
    return *&((Obj1E78170_D_80127040 *)&D_80127040)->unk0;
}    typedef struct { f32 unk0; } Obj1E78170_D_80127044; /* offsets.py genstruct: fields from raw offsets on &D_80127044; rename once understood */

f32 func_8009E988(void) {
    extern f32 D_80127044;
    return *&((Obj1E78170_D_80127044 *)&D_80127044)->unk0;
}    typedef struct { u8 unk0; } Obj1E78170_D_80127075; /* offsets.py genstruct: fields from raw offsets on &D_80127075; rename once understood */

u32 func_8009E994(void) {
    extern u8 D_80127075;
    return *&((Obj1E78170_D_80127075 *)&D_80127075)->unk0;
}

void func_8009E9A0(void) {
}

void func_8009E9A8(void) {
    extern void func_8009E9FC(f32);
    extern void func_8009EB0C(f32);
    func_8009E9FC(0.0f); func_8009EB0C(0.0f);
}

void func_8009E9D8(s32 arg0) {
    extern u8 D_8012704C;
    D_8012704C = arg0;
}

void func_8009E9E4(s32 arg0) {
    extern u8 D_80127078;
    D_80127078 = arg0;
}

void func_8009E9F0(f32 arg0) {
    extern f32 D_80127048;
    ((Obj1E78170_D_80127048 *)&D_80127048)->unk0 = arg0;
}

void func_8009E9FC(f32 arg0) {
    extern f32 D_80127040;
    ((Obj1E78170_D_80127040 *)&D_80127040)->unk0 = arg0;
}    typedef struct { f32 unk0; } Obj1E78170_D_80127070; /* offsets.py genstruct: fields from raw offsets on &D_80127070; rename once understood */

void func_8009EA08(f32 arg0) {
    extern f32 D_80127070;
    ((Obj1E78170_D_80127070 *)&D_80127070)->unk0 = arg0;
}    typedef struct { f32 unk0; } Obj1E78170_D_8012706C; /* offsets.py genstruct: fields from raw offsets on &D_8012706C; rename once understood */

f32 func_8009EA14(void) {
    extern f32 D_8012706C;
    return *&((Obj1E78170_D_8012706C *)&D_8012706C)->unk0;
}

u8 func_8009EA20(void) {
    extern u8 D_80127077;
    return D_80127077;
}

s32 func_8009EA2C()
{
    return func_800DA298(FLAG_3EC_ABILITY_DRAGON_KAZOOIE);
}    typedef struct { u8 unk0; } Obj1E78170_D_80127074; /* offsets.py genstruct: fields from raw offsets on &D_80127074; rename once understood */

u32 func_8009EA4C(void) {
    extern u8 D_80127074;
    return *&((Obj1E78170_D_80127074 *)&D_80127074)->unk0;
}

s32 func_8009EA58()
{
    return D_80127080;
}    typedef struct { s16 unk0; } Obj1E78170_D_8012707C; /* offsets.py genstruct: fields from raw offsets on &D_8012707C; rename once understood */

s32 func_8009EA64(void) {
    extern s16 D_8012707C;
    return *&((Obj1E78170_D_8012707C *)&D_8012707C)->unk0;
}    typedef struct { u8 unk0; } Obj1E78170_D_80127076; /* offsets.py genstruct: fields from raw offsets on &D_80127076; rename once understood */

u32 func_8009EA70(void) {
    extern u8 D_80127076;
    return *&((Obj1E78170_D_80127076 *)&D_80127076)->unk0;
}

f32 func_8009EA7C(void) {
    extern f32 D_80127068;
    return *&((Obj1E78170_D_80127068 *)&D_80127068)->unk0;
}

f32 func_8009EA88(void) {
    extern f32 D_80127070;
    return *&((Obj1E78170_D_80127070 *)&D_80127070)->unk0;
}

void func_8009EA94(f32 arg0) {
    extern f32 D_8012706C;
    ((Obj1E78170_D_8012706C *)&D_8012706C)->unk0 = arg0;
}

void func_8009EAA0(s32 arg0) {
    extern u8 D_80127077;
    D_80127077 = arg0;
}

void func_8009EAAC(s32 arg0) {
    func_800DA3B8(FLAG_3EC_ABILITY_DRAGON_KAZOOIE, arg0);
}

void func_8009EAD0(s32 arg0) {
    extern u8 D_80127074;
    D_80127074 = arg0;
}    typedef struct { s32 unk0; } Obj1E78170_D_80127080; /* offsets.py genstruct: fields from raw offsets on &D_80127080; rename once understood */

void func_8009EADC(s32 arg0) {
    ((Obj1E78170_D_80127080 *)&D_80127080)->unk0 = arg0;
}

void func_8009EAE8(s32 arg0) {
    extern s16 D_8012707C;
    ((Obj1E78170_D_8012707C *)&D_8012707C)->unk0 = arg0;
}

void func_8009EAF4(s32 arg0) {
    extern u8 D_80127076;
    D_80127076 = arg0;
}

void func_8009EB00(f32 arg0) {
    extern f32 D_80127068;
    ((Obj1E78170_D_80127068 *)&D_80127068)->unk0 = arg0;
}

void func_8009EB0C(f32 arg0) {
    extern f32 D_80127044;
    ((Obj1E78170_D_80127044 *)&D_80127044)->unk0 = arg0;
}

void func_8009EB18(s32 arg0) {
    extern u8 D_80127075;
    D_80127075 = arg0;
}

void func_8009EB24(s16 arg0, s16 arg1)
{
  extern f32 D_80127040;
  extern u8 D_8012704C;
  void func_8009EC60(s16, s16);
  s32 *var_v0;
  BtUIntPtr end;
 do { var_v0 = (s32 *) (&D_8012704C); end = (BtUIntPtr) (&D_80127040); while (1) { var_v0[4] = var_v0[3]; var_v0--; if (((BtUIntPtr) var_v0) == end) { break; } } } while (0);
  *(((u8 *) (&D_80127040)) + 0x20) += 1;
  func_8009EC60(arg0, arg1);
}

void func_8009EB8C(s16 arg0, s16 arg1) {
    extern f32 D_80127040;
    void func_8009EC3C(void);
    void func_8009EC60(s16, s16);
    func_8009EC3C();
    *((u8 *)&D_80127040 + 0x20) += 1;
    func_8009EC60(arg0, arg1);
}

void func_8009EBD0(void) {
    extern f32 D_80127040;
    extern u8 D_8012704C;
    s32 i;

    for (i = 0; i < 3; i++) {
        ((s32 *)&D_80127040)[i + 4] = ((s32 *)&D_80127040)[i + 5];
    }
    *((u8 *)&D_80127040 + 0x20) -= 1;
}

s32 func_8009EC08(s16 *arg0, s16 *arg1) {
    extern f32 D_80127040;
    if ((((Obj1E78170_D_80127040 *)&D_80127040)->unk10) != 0) {
        *arg0 = (((Obj1E78170_D_80127040 *)&D_80127040)->unk10);
        *arg1 = (((Obj1E78170_D_80127040 *)&D_80127040)->unk12);
        return 1;
    }
    return 0;
}

void func_8009EC3C(void) {
    extern u8 D_80127060;
    s32 i;

    for (i = 0; i < 4; i++) {
        D_80127050[i] = 0;
    }
    D_80127060 = 0;
}

void func_8009EC60(s16 arg0, s16 arg1) {
    extern f32 D_80127040;
    (((Obj1E78170_D_80127040 *)&D_80127040)->unk10) = arg0;
    (((Obj1E78170_D_80127040 *)&D_80127040)->unk12) = arg1;
}    typedef struct { u8 unk0; } Obj1E78170_D_80127060; /* offsets.py genstruct: fields from raw offsets on &D_80127060; rename once understood */

u32 func_8009EC7C(void) {
    extern u8 D_80127060;
    return *&((Obj1E78170_D_80127060 *)&D_80127060)->unk0;
}

s32 func_8009EC88(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    extern f32 D_80127040;
    extern u8 D_80127060;
    s32 i;

    for (i = 0; i < D_80127060; i++) {
        if (arg0 == *(s16 *)((s8 *)&D_80127040 + i * 4 + 0x10) &&
            arg1 == *(s16 *)((s8 *)&D_80127040 + i * 4 + 0x12)) {
            *(s16 *)((s8 *)&D_80127040 + i * 4 + 0x10) = arg2;
            *(s16 *)((s8 *)&D_80127040 + i * 4 + 0x12) = arg3;
            return 1;
        }
    }
    return 0;
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
u8 D_80127060 BT_DATA(16, bss_core2bss1_0_1, 0x0);
f32 D_80127068 BT_DATA(4, bss_core2bss1_0_1, 0x8);
f32 D_8012706C BT_DATA(4, bss_core2bss1_0_1, 0xC);
f32 D_80127070 BT_DATA(4, bss_core2bss1_0_1, 0x10);
u8 D_80127074 BT_DATA(4, bss_core2bss1_0_1, 0x14);
u8 D_80127075 BT_DATA(4, bss_core2bss1_0_1, 0x15);
u8 D_80127076 BT_DATA(4, bss_core2bss1_0_1, 0x16);
u8 D_80127077 BT_DATA(4, bss_core2bss1_0_1, 0x17);
u8 D_80127078 BT_DATA(4, bss_core2bss1_0_1, 0x18);
s16 D_8012707C BT_DATA(4, bss_core2bss1_0_1, 0x1C);
s32 D_80127080 BT_DATA(4, bss_core2bss1_0_1, 0x20);
f32 D_80127040 BT_DATA(4, bss_core2bss1_sound_tail, 0x360);
f32 D_80127044 BT_DATA(4, bss_core2bss1_sound_tail, 0x364);
f32 D_80127048 BT_DATA(4, bss_core2bss1_sound_tail, 0x368);
u8 D_8012704C BT_DATA(4, bss_core2bss1_sound_tail, 0x36C);
#endif
