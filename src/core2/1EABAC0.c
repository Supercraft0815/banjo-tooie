#include "core2/1EABAC0.h"
#include "hud_allocation.inc"
extern s16 D_8012B2C0[48];

u8 *func_800D21D0(s32 arg0) {
    extern HudDisplayItem D_8011AFB0[91];
    return BT_DATA_FIELD((u8 *)&D_8011AFB0[arg0 - 0xC0], (u8 *)&D_8011AFB0 + (arg0 * 12 - 0x900));
}

s32 func_800D21F0(s32 arg0, s32 arg1) {
    extern s16 D_8012B2C0[48];
    BtUIntPtr i;
    BtUIntPtr end;
    u8 value;

    i = (BtUIntPtr)D_8011B45C[arg1].slots;
    end = D_8011B45C[arg1].count + i;
    if (i < end) {
        do {
            value = *(u8 *)i;
            i++;
            if (arg0 == D_8012B2C0[value]) {
                return value;
            }
        } while (i < end);
    }
    return -1;
}

s32 func_800D225C(s32 arg0) {
    extern s16 D_8012B2C0[48];
    BtUIntPtr i;
    BtUIntPtr end;
    u8 value;

    i = (BtUIntPtr)D_8011B45C[arg0].slots;
    end = D_8011B45C[arg0].count + i;
    if (i < end) {
        do {
            value = *(u8 *)i;
            i++;
            if (D_8012B2C0[value] == -1) {
                return value;
            }
        } while (i < end);
    }
    return -1;
}

u8 func_800D22C8(s32 arg0) { BT_IDO_ONLY(extern struct D_8011B460_entry { u8 *ptr; u32 pad; } D_8011B460[];) return BT_DATA_FIELD(D_8011B45C[arg0].slots[0], D_8011B460[arg0].ptr[0]); }                     typedef struct { u8 unk0; u8 unk1; u8 unk2; u8 pad3[0x3]; s16 unk6; f32 unk8; } Obj1EABAC0_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

s32 func_800D22E0(u8 *arg0, u32 arg1) {
    s32 func_800FA708(u32, s32, s32, u32);
    void func_800FA9B4(s32, s32);
    extern s16 D_8012B2C0[48];
    s32 sp24;
    s32 temp_v0;
    s32 var_s0;
    u32 var_v0;

    sp24 = 0;
    var_v0 = func_800D21F0(arg1, (((Obj1EABAC0_arg0 *)arg0)->unk0));
    var_s0 = var_v0;
    if ((s32)var_v0 < 0) {
        var_v0 = func_800D225C((((Obj1EABAC0_arg0 *)arg0)->unk0));
        var_s0 = var_v0;
    }
    if ((s32)var_v0 < 0) {
        var_v0 = func_800D22C8((((Obj1EABAC0_arg0 *)arg0)->unk0));
        var_s0 = var_v0;
    }
    if ((s32)var_v0 >= 0) {
        temp_v0 = func_800FA708((s32) (((Obj1EABAC0_arg0 *)arg0)->unk8), var_s0, (((Obj1EABAC0_arg0 *)arg0)->unk1), (((Obj1EABAC0_arg0 *)arg0)->unk2));
        sp24 = temp_v0;
        if (temp_v0 != 0) {
            func_800FA9B4(var_s0, (((Obj1EABAC0_arg0 *)arg0)->unk6));
            D_8012B2C0[var_s0] = arg1;
        }
    }
    return sp24;
}

/* extern */

int func_800D2398(void *arg0, s32 arg1) {
    s32 func_800D21F0(s32, s32);
    s32 func_800FA8E8(s32 arg0, s32 arg1);
    s32 temp_v0;

    temp_v0 = func_800D21F0(arg1, (((Obj1EABAC0_arg0 *)arg0)->unk0));
    return temp_v0 >= 0 && func_800FA8E8(temp_v0, (((Obj1EABAC0_arg0 *)arg0)->unk1)) == 1;
}

/* extern */

int func_800D23E8(void *arg0, s32 arg1) {
    s32 func_800D21F0(s32, s32);
    int func_800FA874(s32 arg0, s32 arg1);
    s32 temp_v0;

    temp_v0 = func_800D21F0(arg1, (((Obj1EABAC0_arg0 *)arg0)->unk0));
    return temp_v0 >= 0 && func_800FA874(temp_v0, (((Obj1EABAC0_arg0 *)arg0)->unk1)) == 1;
}

void func_800D2438(void) { extern HudDisplayItem D_8011AFB0[91]; extern u8 D_8011B3F4[4]; extern s16 D_8012B2C0[48]; BT_IDO_ONLY(extern s32 D_8012B320;) BtUIntPtr end; BtUIntPtr ptr; end = (BtUIntPtr)BT_DATA_FIELD(D_8011AFB0 + 91, &D_8011B3F4);
    ptr = (BtUIntPtr)&D_8011AFB0; for (;;) { *(s16 *)(ptr + 4) = -1; *(s16 *)(ptr + 6) = 0; *(f32 *)(ptr + 8) = 0.0f; ptr += 12; if (ptr >= end) break; } end = (BtUIntPtr)BT_DATA_FIELD(D_8012B2C0 + 48, &D_8012B320); ptr = (BtUIntPtr)&D_8012B2C0; for (;;) { ptr += 8; *(s16 *)(ptr - 6) = -1; *(s16 *)(ptr - 4) = -1; *(s16 *)(ptr - 2) = -1; *(s16 *)(ptr - 8) = -1; if (ptr == end) break; } }    typedef struct { u8 pad0[0x4]; s16 unk4; s16 unk6; f32 unk8; } Obj1EABAC0_func_800D2498_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

s32 func_800D2498(u32 itemDisplayUI, s32 value, u32 a2) {
    s32 func_800D22E0(u8 *, u32);
    u8 *temp_v0;

    temp_v0 = func_800D21D0((s32) itemDisplayUI);
    (((Obj1EABAC0_func_800D2498_temp_v0 *)temp_v0)->unk4) = (s16) value;
    (((Obj1EABAC0_func_800D2498_temp_v0 *)temp_v0)->unk8) = (f32) value;
    (((Obj1EABAC0_func_800D2498_temp_v0 *)temp_v0)->unk6) = (s16) a2;
    return func_800D22E0(temp_v0, itemDisplayUI);
}    typedef struct { u8 pad0[0x4]; s16 unk4; s16 unk6; f32 unk8; } Obj1EABAC0_func_800D24E8_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

s32 func_800D24E8(s32 arg0, s32 arg1, u32 arg2) {
    u8 *sp18;
    u8 *temp_v0;
    s32 result;

    temp_v0 = func_800D21D0(arg0);
    if ((((Obj1EABAC0_func_800D24E8_temp_v0 *)temp_v0)->unk4) < 0) {
        return func_800D2498((u32) arg0, arg1, arg2);
    }
    (((Obj1EABAC0_func_800D24E8_temp_v0 *)temp_v0)->unk4) = (s16) arg1;
    (((Obj1EABAC0_func_800D24E8_temp_v0 *)temp_v0)->unk6) = (s16) arg2;
    sp18 = temp_v0;
    result = func_800D22E0(temp_v0, (u32) arg0);
    if (result == 0) {
        (((Obj1EABAC0_func_800D24E8_temp_v0 *)temp_v0)->unk8) = (f32) (((Obj1EABAC0_func_800D24E8_temp_v0 *)temp_v0)->unk4);
    }
    return result;
}

void func_800D2574(void)
{
  f32 func_800D8FF8(void);
  int func_800FA874(s32 arg0, s32 arg1);
  s32 func_800FA8E8(s32 arg0, s32 arg1);
  extern HudDisplayItem D_8011AFB0[91];
  extern s16 D_8012B2C0[48];
  f32 delta;
  f32 current;
  f32 difference;
  f32 direction;
  f32 speed;
  f32 step;
  s32 item;
  s32 handle;
  s16 target;
  u8 *entry;
  s32 index;
  delta = func_800D8FF8();
 entry = (u8 *) (&D_8011AFB0); for (index = 0; index != 0x5B; index++, entry += 0xC) {
    item = index + 0xC0;
    handle = func_800D21F0(item, entry[0]);
    if (handle < 0) {
      continue;
    }
      if (func_800FA8E8(handle, entry[1]) != 1)
      {
        D_8012B2C0[handle] = -1;
        continue;
      }
      if (func_800FA874(handle, entry[1]) != 0)
      {
        current = *((f32 *) (entry + 8));
        target = *((s16 *) (entry - -4));
        difference = ((f32) target) - current;
        if (target != ((s32) current))
        {
          direction = (difference >= 0.0f) ? (1.0f) : (-1.0f);
          step = ((((difference < 8.0f) ? (8.0f) : (difference)) * delta) > 1.0f) ? (1.0f) : (((difference < 8.0f) ? (8.0f) : (difference)) * delta);
          speed = direction * step;
          *((f32 *) (entry + 8)) = current + speed;
          func_800D22E0(entry, item);
        }
      }
  }
}

void func_800D2748(s32 arg0, s32 arg1) {
    (*(s8 *)((s8 *)(func_800D21D0(arg0)) + (1))) = (s8) arg1;
}    typedef struct { u8 pad0[0x4]; s16 unk4; u8 pad6[0x2]; f32 unk8; } Obj1EABAC0_func_800D2770_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void func_800D2770(s32 arg0, s32 arg1) {
    u8 *temp_v0;

    temp_v0 = func_800D21D0(arg0);
    (((Obj1EABAC0_func_800D2770_temp_v0 *)temp_v0)->unk4) = (s16) arg1;
    (((Obj1EABAC0_func_800D2770_temp_v0 *)temp_v0)->unk8) = (f32) arg1;
}

s32 func_800D27A4(s32 arg0) {
    return (s32) (*(u8 *)((s8 *)(func_800D21D0(arg0)) + (1)));
}

s32 func_800D27C8(s32 arg0) {
    return func_800D21F0(arg0, (s32) *func_800D21D0(arg0));
}

int func_800D27F4(s32 arg0)
{
    return func_800D23E8(func_800D21D0(arg0),arg0);
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800D2820(s32 arg0)
{
    BT_NATIVE_ONLY(return) func_800D2398(func_800D21D0(arg0),arg0);
}

/* extern */

int func_800D284C(s32 a0) {
    s32 func_800FA818(s32, s32);
    u8 *sp1C;
    s32 temp_v0_2;
    u8 *temp_v0;

    temp_v0 = func_800D21D0((s32) a0);
    sp1C = temp_v0;
    temp_v0_2 = func_800D21F0((s32) a0, (s32) *temp_v0);
    return temp_v0_2 >= 0 && func_800FA818(temp_v0_2, sp1C[1]) == 1;
}

/* extern */

s32 func_800D28A0(s32 arg0) {
    void func_800FAA74(s32 arg0);
    s32 temp_v0;

    temp_v0 = func_800D21F0(arg0, (s32) *func_800D21D0(arg0));
    if (temp_v0 >= 0) {
        func_800FAA74(temp_v0);
        return 1;
    }
    return 0;
}

u32 func_800D28E8(s32 arg0) {
    return (u32) (*(u8 *)((s8 *)(func_800D21D0(arg0)) + (2)));
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
s16 D_8012B2C0[48] BT_DATA(4, bss_core2bss1_2, 0x30);
#endif
