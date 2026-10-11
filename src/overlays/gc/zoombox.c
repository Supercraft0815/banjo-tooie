#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/func_80800000_gczoombox.s")

void func_808000C4_gczoombox(void *arg0) {
    if ((*(u16 *)((s8 *)(arg0) + (0x142))) != 0) {
        (*(u16 *)((s8 *)(arg0) + (0x142))) = 0U;
    }
}

void func_808000DC_gczoombox(void *arg0) {
    if ((*(u16 *)((s8 *)(arg0) + (0x140))) != 0) {
        (*(u16 *)((s8 *)(arg0) + (0x140))) = 0U;
    }
    func_808000C4_gczoombox(arg0);
}

/* extern */

void gczoombox_entrypoint_0(void *arg0) {
    s32 func_800D52B0();
    s32 func_80800000_gczoombox(void *);
    s32 heap_free(void *);
    if (arg0 != NULL) {
        func_800D52B0();
        func_80800000_gczoombox(arg0);
        func_808000DC_gczoombox(arg0);
        heap_free(arg0);
    }
}

void func_8080014C_gczoombox(u8 * arg0, u8 * arg1, s32 arg2, s32 arg3){
     int i;
     for(i = arg2; i < arg3; i++){
          arg1[i - arg2] = arg0[i];
     }
}

void func_808001D4_gczoombox(u8 *arg0, s32 size){
     s32 i;

     for(i = 0; i< size; i++){
          arg0[i] = 0;
     }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/func_80800228_gczoombox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/func_80800294_gczoombox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/func_808002E4_gczoombox.s")

void func_80800358_gczoombox(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)arg0 + 496) = arg1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/func_80800364_gczoombox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/func_808003D8_gczoombox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/func_80800470_gczoombox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/func_808004D0_gczoombox.s")

int func_808005F0_gczoombox(u8 arg0, u8 arg1){
    if(arg1 == 0){
        return arg0 == '.' || arg0 == '!' || arg0 == ',' || arg0 == '-' || arg0 == '?';
    }
    else{
        return arg0 == '\1' || arg0 == '4' || arg0 == '@' || arg0 == 'B';
    }
}

void gczoombox_entrypoint_1()
{
    func_800E7188();
}

s32 func_808006B4_gczoombox(void *arg0, s32 arg1) {
    return arg1 == -1 ? 0 : ((u32)arg1 == ((u32)*(u16 *)((u8 *)arg0 + 0x12) >> 1));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/func_808006E0_gczoombox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/func_808008F4_gczoombox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/func_80800964_gczoombox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/func_808009E4_gczoombox.s")

int func_80800E24_gczoombox(u8 arg0) {
    return arg0 >= 0x7F && arg0 < 0x88;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/func_80800E44_gczoombox.s")

void func_80800FE0_gczoombox(u8 *arg0)
{
  typedef struct 
  {
    u32 unused31 : 1;
    u32 first : 1;
    u32 second : 1;
    u32 unused28 : 4;
    u32 side : 1;
    u32 unused23 : 4;
    u32 style : 1;
    u32 unused18 : 1;
    u32 centered : 1;
    u32 unused16 : 1;
    u32 alternate : 1;
    u32 unused14 : 7;
    u8 increasing : 1;
    u32 unused6 : 5;
    u32 synced : 1;
    u32 unused0 : 1;
  } Flags;
  typedef struct 
  {
    u8 strings[4][0x30];
    u8 padC0[0xB2];
    s16 id;
    u8 pad174[0x30];
    f32 y0;
    f32 y1;
    s16 alpha;
    s16 x;
    s16 center;
    s16 unk1B2;
    u8 red;
    u8 green;
    u8 blue;
    u8 pad1B7[5];
    s16 opacity;
    u8 pad1BE[0x1E];
    f32 scale;
    f32 unk1E0;
    Flags flags;
    f32 pulse;
    u8 pad1EC[8];
    f32 width;
  } Box;
  f32 _glintrosyncDll_entrypoint_5(void);
  s32 func_800A8184(void);
  void func_800B798C(s32, s32, u8 *);
  void func_800B7A98(void);
  void func_800B7ADC(s32);
  void func_800B7B2C(s32);
  void func_800B7B38(s32);
  void func_800B7B8C(s32, s32, s32);
  f32 func_800D8FF8(void);
  void func_80800E44_gczoombox(u8 *, u8 *, u8 *);
  s32 colors[3];
  f32 alpha;
  s32 x;
  s32 height;
  f32 delta;
  f32 direction;
  alpha = ((Box *) arg0)->alpha / 255.0f;
  colors[0] = ((Box *) arg0)->red * alpha;
  colors[1] = ((Box *) arg0)->green * alpha;
  colors[2] = ((Box *) arg0)->blue * alpha;
  func_800B7A98();
  func_800B7B8C(colors[0], colors[1], colors[2]);
  func_800B7ADC(((Box *) arg0)->opacity);
  if (((Box *) arg0)->flags.alternate)
  {
    func_800B7B38(1);
  }
  else
    if (((Box *) arg0)->flags.style)
  {
    func_800B7B38(2);
  }
  if (((Box *) arg0)->id == 0x44)
  {
    x = ((f32) ((Box *) arg0)->x) + (4.0f * ((Box *) arg0)->scale);
 do { } while (0);
  }
  else
    if (((Box *) arg0)->flags.side)
  {
    if (func_800A8184() == 4)
    {
      x = ((f32) ((Box *) arg0)->x) - (((Box *) arg0)->width * (216.0f * ((Box *) arg0)->scale));
    }
    else
    {
      x = ((f32) (0x130 - ((Box *) arg0)->x)) + (8.0f * ((Box *) arg0)->scale);
    }
  }
  else
    if (((Box *) arg0)->flags.alternate)
  {
    x = ((f32) ((Box *) arg0)->x) + ((24.0f * ((Box *) arg0)->scale) + 8.0f);
  }
  else
  {
    x = ((f32) ((Box *) arg0)->x) + ((24.0f * ((Box *) arg0)->scale) + 4.0f);
  }
  if (((Box *) arg0)->flags.first)
  {
    if (((Box *) arg0)->flags.centered)
    {
      height = (((Box *) arg0)->flags.style) ? (15) : (12);
      func_800B7B2C(((Box *) arg0)->center - (height / 2));
    }
    func_80800E44_gczoombox(((Box *) arg0)->strings[0], ((Box *) arg0)->strings[2], ((Box *) arg0)->strings[0]);
    func_800B798C(x, ((Box *) arg0)->y0, ((Box *) arg0)->strings[2]);
  }
  if (((Box *) arg0)->flags.second)
  {
    func_800B7B2C(-0x7FFF);
    func_80800E44_gczoombox(((Box *) arg0)->strings[0], ((Box *) arg0)->strings[3], ((Box *) arg0)->strings[1]);
    func_800B798C(x, ((Box *) arg0)->y1, ((Box *) arg0)->strings[3]);
  }
 if (((Box *) arg0)->flags.increasing) { direction = 1.0f; } else { direction = -1.0f; } if (((Box *) arg0)->flags.synced) { delta = _glintrosyncDll_entrypoint_5(); } else { delta = func_800D8FF8(); } ((Box *) arg0)->pulse += (delta * 10.0f) * direction; if (((Box *) arg0)->pulse >= 4.0f) {
    ((Box *) arg0)->pulse = 3.999f;
    ((Box *) arg0)->flags.increasing ^= 1;
  }
  else
    if (((Box *) arg0)->pulse < 0.0f)
  {
    ((Box *) arg0)->pulse = 0;
    ((Box *) arg0)->flags.increasing ^= 1;
  }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/func_80801424_gczoombox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/func_808014A8_gczoombox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/func_8080156C_gczoombox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/gczoombox_entrypoint_2.s")

void func_80801B30_gczoombox(u8 *box) {
    void gczoombox_entrypoint_15(void *);
    box[0x171] = 8;
    gczoombox_entrypoint_15(box);
    *(f32 *)(box + 0x1E0) = 0.0f;
    if (box[0x1E4] & 1) {
        *(s16 *)(box + 0x1AE) = *(s16 *)(box + 0x1B2) + 0x8C;
    } else {
        *(s16 *)(box + 0x1AE) = *(s16 *)(box + 0x1B2) - 0x8C;
    }
}

void func_80801B90_gczoombox(u8 *box) {
    void gczoombox_entrypoint_16(void *);
    box[0x171] = 9;
    gczoombox_entrypoint_16(box);
    *(f32 *)(box + 0x1E0) = 0.0f;
}

u32 gczoombox_entrypoint_3(u8 *arg0) {
    return arg0[368];
}

void func_80801BD0_gczoombox(u8 *box, s32 state) {
    void (*callback)(s16, s32);
    if (state != box[0x170]) {
        box[0x170] = state;
        callback = *(void (**)(s16, s32))(box + 0x16C);
        if (callback != NULL) callback(*(s16 *)(box + 0x172), state);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/func_80801C0C_gczoombox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/gczoombox_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/func_80802B94_gczoombox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/func_80802BF4_gczoombox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/func_80802C80_gczoombox.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/gczoombox_entrypoint_5.s")

u32 gczoombox_entrypoint_6(u8 *arg0) {
    return arg0[376];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/gczoombox_entrypoint_7.s")

int gczoombox_entrypoint_8(u8 *box, char *text) {
    s32 gczoombox_entrypoint_7(u8 *, s32, char **);
    char *line;
    if ((box[0x177] & 4) || text == NULL) return 0;
    line = text;
    return gczoombox_entrypoint_7(box, 1, &line);
}

void gczoombox_entrypoint_9(void *arg0) {
    (*(u8 *)((s8 *)(arg0) + (0x177))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x177))) | 0x1);
}

void gczoombox_entrypoint_10(void *arg0) {
    (*(u8 *)((s8 *)(arg0) + (0x177))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x177))) | 0x10);
}

void gczoombox_entrypoint_11(void *arg0) {
    (*(u8 *)((s8 *)(arg0) + (0x177))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x177))) | 0x2);
}

void gczoombox_entrypoint_12(void *arg0) {
    (*(u8 *)((s8 *)(arg0) + (0x177))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x177))) | 0x8);
}

void gczoombox_entrypoint_13(void *arg0) {
    (*(u8 *)((s8 *)(arg0) + (0x177))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x177))) | 0x20);
}

void gczoombox_entrypoint_14(u8 *arg0) {
    s32 var_v0;
    u8 *var_v1;

    var_v0 = 0;
    var_v1 = arg0;
    do {
        var_v0 += 4;
        (*(s32 *)((s8 *)(var_v1) + (0x180))) = 0;
        (*(s32 *)((s8 *)(var_v1) + (0x184))) = 0;
        (*(s32 *)((s8 *)(var_v1) + (0x188))) = 0;
        var_v1 += 0x10;
        (*(s32 *)((s8 *)(var_v1) + (0x16C))) = 0;
    } while (var_v0 != 8);
    (*(s8 *)((s8 *)(arg0) + (0x174))) = 0;
    (*(s8 *)((s8 *)(arg0) + (0x175))) = 0;
    (*(u8 *)((s8 *)(arg0) + (0x177))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x177))) & 0xFB);
}

void gczoombox_entrypoint_15(void *arg0) {
    (*(u8 *)((s8 *)(arg0) + (0x177))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x177))) & 0xFE);
}

void gczoombox_entrypoint_16(void *arg0) {
    (*(u8 *)((s8 *)(arg0) + (0x177))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x177))) & 0xEF);
}

void gczoombox_entrypoint_17(void *arg0) {
    (*(u8 *)((s8 *)(arg0) + (0x177))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x177))) & 0xFD);
}

void gczoombox_entrypoint_18(void *arg0) {
    (*(u8 *)((s8 *)(arg0) + (0x177))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x177))) & 0xF7);
}

void gczoombox_entrypoint_19(void *arg0) {
    (*(u8 *)((s8 *)(arg0) + (0x177))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x177))) & 0xDF);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/gczoombox_entrypoint_20.s")

void gczoombox_entrypoint_21(void *arg0, s32 arg1) {
    struct Flags {
        u8 padding[0x1E5];
        u8 high : 5;
        u8 flag : 1;
        u8 low : 2;
    };
    if (arg1 != 0) {
        ((struct Flags *)arg0)->flag = 1;
    } else {
        ((struct Flags *)arg0)->flag = 0;
    }
}

u32 gczoombox_entrypoint_22(void *arg0) {
    return (u32) ((*(s32 *)((s8 *)(arg0) + (0x1E4))) << 0xD) >> 0x1F;
}

void gczoombox_entrypoint_23(void *arg0, s32 arg1) {
    struct Flags {
        u8 pad[0x1E6];
        u8 unused : 4;
        u8 flag : 1;
        u8 rest : 3;
    };
    if (arg0 != NULL) {
        if (arg1 != 0) {
            ((struct Flags *)arg0)->flag = 1;
        } else {
            ((struct Flags *)arg0)->flag = 0;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/gczoombox_entrypoint_24.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/gczoombox_entrypoint_25.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/gczoombox_entrypoint_26.s")

void gczoombox_entrypoint_27(void *arg0, void *arg1) {
    if (arg0 != NULL) {
        (*(s8 *)((s8 *)(arg0) + (0x1B4))) = (s8) (*(s16 *)((s8 *)(arg1) + (0)));
        (*(s8 *)((s8 *)(arg0) + (0x1B5))) = (s8) (*(s16 *)((s8 *)(arg1) + (2)));
        (*(s8 *)((s8 *)(arg0) + (0x1B6))) = (s8) (*(s16 *)((s8 *)(arg1) + (4)));
    }
}

void gczoombox_entrypoint_28(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        (*(s16 *)((s8 *)(arg0) + (0x1BC))) = arg1;
    }
}

s16 gczoombox_entrypoint_29(void *arg0) {
    if (arg0 == NULL) {
        return 0xFF;
    }
    return (*(s16 *)((s8 *)(arg0) + (0x1BC)));
}

void gczoombox_entrypoint_30(void *arg0, s32 arg1) {
    if (arg0 != NULL) {
        (*(s16 *)((s8 *)(arg0) + (0x16A))) = arg1;
    }
}

void gczoombox_entrypoint_31(void *arg0) {
    *((u8 *) arg0 + 0x177) = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/gczoombox_entrypoint_32.s")

int gczoombox_entrypoint_33(u8 *box) {
    s32 func_808004D0_gczoombox(void *);
    void gczoombox_entrypoint_17(void *);
    if (box == NULL || box[0x171] == 0 || box[0x171] == 7 || box[0x171] == 9) return 0;
    if (box[0x171] == 6 && box[0x170] == 4) return 0;
    if (box[0x171] == 8) {
        box[0x1E5] &= ~1;
        box[0x171] = 6;
    } else if (box[0x171] != 6) {
        func_808004D0_gczoombox(box);
    }
    gczoombox_entrypoint_14(box);
    gczoombox_entrypoint_17(box);
    return 1;
}

/* extern */

s32 gczoombox_entrypoint_34(void *arg0) {
    s32 func_808004D0_gczoombox(void *);
    u8 temp_v0;

    if ((arg0 == NULL) || (temp_v0 = (*(u8 *)((s8 *)(arg0) + (0x171))), (temp_v0 == 0)) || (temp_v0 == 7) || (temp_v0 == 9)) {
        return 0;
    }
    gczoombox_entrypoint_10(arg0);
    gczoombox_entrypoint_13(arg0);
    func_808004D0_gczoombox(arg0);
    return 1;
}

/* extern */

void gczoombox_entrypoint_35(u8 *arg0, s32 arg1, s16 arg2, s32 arg3) {
    s32 func_800EC370(s32, u8 *);
    (*(s32 *)((s8 *)(arg0) + (0x130))) = arg1;
    (*(s16 *)((s8 *)(arg0) + (0x13A))) = arg2;
    (*(s32 *)((s8 *)(arg0) + (0x13C))) = arg3;
    func_800EC370(arg1, arg0 + 0x134);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/gczoombox_entrypoint_36.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/gczoombox_entrypoint_37.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/gczoombox_entrypoint_38.s")

int gczoombox_entrypoint_39(void *arg0) {
    return arg0 != NULL && *(u8 *)((s8 *)arg0 + 0x171) == 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/gczoombox_entrypoint_40.s")

void gczoombox_entrypoint_41(void *arg0, f32 arg1) {
    (*(f32 *)((s8 *)(arg0) + (0x1D8))) = (f32) (1.0f / arg1);
}

void gczoombox_entrypoint_42(void *arg0, f32 arg1) {
    func_80800358_gczoombox(arg0, arg1);
}

void gczoombox_entrypoint_43(void *arg0, s32 arg1) {
    struct Flags {
        u8 padding[0x1E7];
        u8 high : 1;
        u8 flag : 1;
        u8 low : 6;
    };
    if (arg1 != 0) {
        ((struct Flags *)arg0)->flag = 1;
        return;
    }
    ((struct Flags *)arg0)->flag = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/gczoombox_entrypoint_44.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/zoombox/gczoombox_entrypoint_45.s")
