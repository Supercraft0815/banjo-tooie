#include "common.h"

void func_80800000_gczoombox(void *arg0) {
    s32 func_800C2FDC(u8 index);
    void func_800FC74C(u32 track_id);
    s32 func_800FCCD4(s32 track_id);
    s32 i = 0;

    if (-1.0f == *(f32 *)((u8 *)arg0 + 0x14C)) {
        if (func_800FCCD4(((u8 *)arg0)[0x144])) {
            func_800FC74C(((u8 *)arg0)[0x144]);
        }
    } else {
        for (i = 0; i < 5; i++) {
            if (((u8 *)arg0)[0x144 + i]) {
                func_800C2FDC(((u8 *)arg0)[0x144 + i]);
                ((u8 *)arg0)[0x178]--;
            }
        }
    }
    for (i = 0; i < 5; i++) {
        ((u8 *)arg0)[0x144 + i] = 0;
    }
}

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
    int func_800D52B0(void);
    void func_80800000_gczoombox(void *);
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

void func_80800228_gczoombox(void *arg0) {
    u32 flag;
    s32 height;

    flag = (*(u32 *)((u8 *)arg0 + 0x1E4) << 12) >> 31;
    height = flag ? 15 : 12;
    *(f32 *)((u8 *)arg0 + 0x1A4) = *(s16 *)((u8 *)arg0 + 0x1B0) - height / 2;
    height = flag ? 15 : 12;
    *(f32 *)((u8 *)arg0 + 0x1A8) = height;
    *(f32 *)((u8 *)arg0 + 0x1A8) += *(f32 *)((u8 *)arg0 + 0x1A4);
}

void func_80800228_gczoombox(void *);

/* extern */

void func_80800294_gczoombox(void *arg0) {
    u32 temp_v0 = *(u32 *)((u8 *)arg0 + 0x1E4);

    if ((temp_v0 >> 31) && !((temp_v0 << 5) >> 31)) {
        (*(f32 *)((s8 *)(arg0) + (0x1A4))) = (f32) (*(s16 *)((s8 *)(arg0) + (0x1B0)));
        return;
    }
    func_80800228_gczoombox(arg0);
}

void func_808002E4_gczoombox(void *arg0) {
    struct {
        u8 pad0[0x171];
        s8 state;
        u8 pad172[0x2A];
        u8 unk19C;
        u8 pad19D;
        u8 unk19E;
        u8 pad19F[0x25];
        f32 unk1C4;
        u8 pad1C8[4];
        u8 unk1CC;
        u8 pad1CD[0x17];
        u32 flag31:1;
        u32 padFlags27:4;
        u32 flag26:1;
        u32 padFlags24:2;
        u32 flag23:1;
        u32 padFlags0:23;
    } *this = arg0;

    if (this->flag26 || this->flag31) {
        this->state = 3;
        this->unk1C4 = (u32)this->unk1CC / 60.0f;
    } else {
        this->state = 4;
    }
    this->unk19E = this->unk19C;
    this->flag23 = 0;
}

void func_80800358_gczoombox(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)arg0 + 496) = arg1;
}

/* extern */

f32 func_80800364_gczoombox(void *arg0) {
    f32 _glintrosyncDll_entrypoint_5(void);
    f32 func_800D8FF8(void);
    f32 sp1C;
    f32 var_f0;
    f32 var_f2;
    struct {
        u8 pad[0x1E4];
        u32 padFlags:29;
        u32 direction:1;
        u32 sync:1;
        u32 lastFlag:1;
        u8 pad1E8[4];
        f32 position;
        f32 duration;
    } *this = arg0;

    sp1C = (*(f32 *)((s8 *)(arg0) + (0x1EC)));
    if (this->sync) {
        var_f0 = _glintrosyncDll_entrypoint_5();
    } else {
        var_f0 = func_800D8FF8();
    }
    var_f2 = var_f0 / (*(f32 *)((s8 *)(arg0) + (0x1F0)));
    if (!this->direction) {
        var_f2 = -var_f2;
    }
    (*(f32 *)((s8 *)(arg0) + (0x1EC))) = (f32) ((*(f32 *)((s8 *)(arg0) + (0x1EC))) + var_f2);
    return sp1C;
}

int func_808003D8_gczoombox(void *arg0, f32 arg1, f32 arg2) {
    struct {
        u8 pad[0x1E4];
        u32 padFlags:29;
        u32 direction:1;
        u32 sync:1;
        u32 lastFlag:1;
        u8 pad1E8[4];
        f32 position;
        f32 duration;
    } *this = arg0;

    if (this->direction) {
        return arg1 <= arg2 && arg2 < this->position;
    }
    return arg2 <= arg1 && this->position < arg2;
}

void func_80800470_gczoombox(void *arg0) {
    void gczoombox_entrypoint_17(void *);
    struct {
        u8 pad[0x170];
        s8 unk170;
        s8 state;
        u8 pad172[0x72];
        u32 a:15;
        u32 flag1:1;
        u32 b:11;
        u32 test:1;
        u32 c:1;
        u32 flag4:1;
        u32 d:2;
    } *this = arg0;
    this->state = 5;
    this->flag4 = 1;
    this->flag1 = 1;
    if (this->test) {
        func_80800358_gczoombox(arg0, 0.2f);
    }
    (*(u8 *)((u8 *)arg0 + 0x170)) = 0;
    gczoombox_entrypoint_17(arg0);
}

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

/* extern */

u8 func_808008F4_gczoombox(void *arg0, s32 arg1, s32 arg2) {
    void func_800C32C4(u8, s32);
    void func_800C3418(u8, s32);
    void func_800C34CC(u8, s32);
    u8 func_800C429C(s32, s32);
    u8 sp1F;
    s16 temp_v0_2;

    sp1F = func_800C429C(arg1, arg2) & 0xFF;
    func_800C3418(sp1F, 0);
    func_800C34CC(sp1F, 0);
    temp_v0_2 = (*(s16 *)((s8 *)(arg0) + (0x172)));
    if ((temp_v0_2 == 0x80) || (temp_v0_2 == 0xBB)) {
        func_800C32C4(sp1F, 0x40);
    }
    return sp1F;
}

void func_80800964_gczoombox(void *arg0) {
    typedef struct {
        u32 pad : 11;
        u32 enabled : 1;
        u32 rest : 20;
    } Flags;
    int func_800D52B0(void);
    int i;

    func_800D52B0();
    func_80800000_gczoombox(arg0);
    func_808000DC_gczoombox(arg0);
    for (i = 0; i < 8; i++) {
        ((void **)((u8 *)arg0 + 0x17C))[i] = NULL;
    }
    *(u8 *)((u8 *)arg0 + 0x171) = 0;
    *(u8 *)((u8 *)arg0 + 0x174) =
        ((Flags *)((u8 *)arg0 + 0x1E4))->enabled = 0;
}

void func_808009E4_gczoombox(u8 *this, s32 arg1) {
    typedef struct {
        u32 pad : 20;
        u32 enabled : 1;
        u32 rest : 11;
    } Flags;
    f32 _suexpression_entrypoint_0(u8);
    f32 func_80027170(s32);
    void func_800C3058(u8, s32);
    void func_800C31DC(u8, f32);
    void func_800C3BDC(u8);
    s32 func_800C3CE8(u8);
    s32 func_800C3D78(u8);
    void func_800D527C(s32);
    void func_800D52CC(s32);
    s32 func_800DC214(s32, s32);
    f32 func_800DC264(f32, f32);
    s32 func_800EC370(s32, u8 *);
    void func_800FC6B0(u32);
    s32 func_800FCCD4(s32);
    s32 i;
    s32 current_sfx;
    f32 low;
    f32 pitch;
    f32 high;
    s32 sample_low;
    s32 sample_high;
    s32 count;
    f32 position[3];
    u8 *source;
    s32 initial_count;

    current_sfx = 0;
    if (this != NULL && (initial_count = this[0x178]) != 0 && ((Flags *)(this + 0x1E4))->enabled) {
        i = 0;
        if (*(f32 *)(this + 0x14C) == -1.0f) {
            if (func_800FCCD4(this[0x144]) == 0) {
                func_800FC6B0(this[0x144]);
            }
        } else {
            count = initial_count;
            if (initial_count > 0) {
                source = this;
                do {
                    if (func_800C3D78(source[0x144])) {
                        func_800C3CE8(source[0x144]);
                    }
                    count = this[0x178];
                    i++;
                    source++;
                } while (i < count);
            }
            if (count != 1) {
                do {
                    current_sfx = func_800DC214(0, this[0x178]);
                } while (current_sfx == this[0x1D3] || ((s16 *)(this + 0x160))[current_sfx] == 0);
            }
            this[0x1D3] = current_sfx;
            i = 6000;
            count = 0;
            low = 0.2f;
            high = 0.0f;
            if ((pitch = ((f32 *)(this + 0x14C))[current_sfx]) < -1.0f) {
                do {
                    low = (f32)func_800DC214(-12, 0);
                } while (low == -11.0f || low == -9.0f || low == -7.0f || low == -6.0f || low == -4.0f || low == -2.0f || low == -1.0f);
                pitch = ((f32 *)(this + 0x14C))[current_sfx];
                if (pitch < -2.0f) {
                    low -= pitch - -2.0f;
                }
                func_800C31DC((this + current_sfx)[0x144], func_80027170(low * 100.0f));
            } else {
                low = (pitch - low < 0.1f) ? 0.1f : pitch - low;
                if (low >= 2.0f) {
                    low = 1.99f;
                }
                high = (pitch - high < 2.0f) ? pitch - high : 2.0f;
                if (!(high > 0.1f)) {
                    high = 0.1f;
                }
                func_800C31DC((this + current_sfx)[0x144], func_800DC264(low, high));
            }
            if (*(s16 *)(this + 0x13A) == *(s16 *)(this + 0x172)) {
                if (func_808006B4_gczoombox(*(void **)(this + 0x130), *(s32 *)(this + 0x13C))) {
                    func_800EC370(*(s32 *)(this + 0x130), this + 0x134);
                    *(s16 *)(this + 0x136) += _suexpression_entrypoint_0(this[0x173]);
                }
                position[0] = *(s16 *)(this + 0x134);
                position[1] = *(s16 *)(this + 0x136);
                position[2] = *(s16 *)(this + 0x138);
                sample_low = (((s16 *)(this + 0x160))[current_sfx] - i < 0) ? 0 : ((s16 *)(this + 0x160))[current_sfx] - i;
                sample_high = (((s16 *)(this + 0x160))[current_sfx] - count < 0) ? 0 : ((s16 *)(this + 0x160))[current_sfx] - count;
                func_800C3058((this + current_sfx)[0x144], func_800DC214(sample_low, sample_high));
            } else {
                sample_low = (((s16 *)(this + 0x160))[current_sfx] - i < 0) ? 0 : ((s16 *)(this + 0x160))[current_sfx] - i;
                sample_high = (((s16 *)(this + 0x160))[current_sfx] - count < 0) ? 0 : ((s16 *)(this + 0x160))[current_sfx] - count;
                func_800C3058((this + current_sfx)[0x144], func_800DC214(sample_low, sample_high));
            }
            func_800C3BDC((this + current_sfx)[0x144]);
            func_800D52CC(*(s16 *)(this + 0x172));
            func_800D527C(current_sfx);
        }
    }
}

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

/* extern */

void func_80801424_gczoombox(void *arg0, s32 arg1) {
    s32 _fxdialog_entrypoint_0();
    void _fxdialog_entrypoint_1(s32, s32);
    void _fxdialog_entrypoint_2(f32);
    s32 _fxdialog_entrypoint_3(s32, f32, u8, s32);
    u8 direction;

    _fxdialog_entrypoint_0();
    _fxdialog_entrypoint_1((*(s16 *)((s8 *)(arg0) + (0x1AE))), (*(s16 *)((s8 *)(arg0) + (0x1B0))));
    _fxdialog_entrypoint_2((*(f32 *)((s8 *)(arg0) + (0x1DC))));
    if ((*(u8 *)((s8 *)arg0 + 0x1E4)) & 1) {
        direction = 2;
    } else {
        direction = 0;
    }
    _fxdialog_entrypoint_3(arg1, (216.0f * (*(f32 *)((s8 *)arg0 + 0x1DC))) * (*(f32 *)((s8 *)arg0 + 0x1EC)), direction, (*(s16 *)((s8 *)(arg0) + (0x1BC))));
}

/* extern */

void func_808014A8_gczoombox(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 arg5) {
    void _fxdialog_entrypoint_4(s32, s32, s32, f32, f32, s32, s32);
    struct {
        u8 pad[0x1DC];
        f32 scale;
    } *box = arg0;

    if ((*(s16 *)((s8 *)(arg0) + (0x172))) != 0x44) {
        _fxdialog_entrypoint_4(arg1, arg4, *(s8 *)((s8 *)arg0 + 0x1CF), (f32) arg2 * box->scale, (f32) arg3 * box->scale, (s32) (((f32) ((*(s16 *)((s8 *)(arg0) + (0x1BC))) * (*(s16 *)((s8 *)(arg0) + (0x1AC)))) * arg5) / 255.0f), (*(u8 *)((s8 *)(arg0) + (0x1E4))) & 1);
    }
}

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

void gczoombox_entrypoint_4(u8 *box) {
    struct Flags {
            u32 b31:1; u32 b30:1; u32 b29:1; u32 b28:1;
            u32 b27:1; u32 b26:1; u32 b25:1; u32 b24:1;
            u32 b23:1; u32 b22:1; u32 b21:1; u32 b20:1;
            u32 b19:1; u32 b18:1; u32 b17:1; u32 b16:1;
            u32 b15:1; u32 b14:1; u32 b13:1; u32 b12:1;
            u32 b11:1; u32 b10:1; u32 b9:1; u32 b8:1;
            u32 b7:1; u32 b6:1; u32 b5:1; u32 b4:1;
            u32 b3:1; u32 b2:1; u32 b1:1; u32 b0:1;
    };
    struct Box {
        u8 text0[0x30];
        u8 text1[0x90];
        u8 text2[0xAA];
        u8 pad16A[0x48];
        s16 startX;
        u8 pad1B4[0x19];
        u8 speed;
    };
    void _gcaudiolist_entrypoint_1(s32, s16);
    s32 _gldialog_entrypoint_1();
    f32 _glintrosyncDll_entrypoint_5();
    void func_80015E80(s32, void *);
    void func_80015ECC(s32, void *);
    void func_80015F28(s32, void *);
    void func_80015F5C(s32, void *);
    s32 func_800C710C(s32);
    f32 func_800D8FF8(void);
    f32 func_800D9004(void);
    f32 func_800F3780(f32, u8 *, s16);
    s32 func_80101238(s32, s32);
    void func_80800228_gczoombox(void *);
    void func_80800294_gczoombox(void *);
    void func_808002E4_gczoombox(void *);
    f32 func_80800364_gczoombox(void *);
    int func_808003D8_gczoombox(void *, f32, f32);
    s32 func_808004D0_gczoombox(void *);
    void func_808006E0_gczoombox(void *, u8);
    void func_80800964_gczoombox(void *);
    s32 func_80801C0C_gczoombox(void *, u8 *);
    void gczoombox_entrypoint_14(u8 *);
    extern u8 D_80803E44_gczoombox[];
    s32 face[6];
    s32 side[3];
    f32 interval;
    f32 dt;
    f32 previousTime;
    f32 previousTime2;

    if (box == NULL) return;
    if (!((struct Flags *)(box + 0x1E4))->b10) {
        func_80015E80(0, face);
        func_80015F28(0, side);
        if (((struct Flags *)(box + 0x1E4))->b1) {
            dt = _glintrosyncDll_entrypoint_5();
        } else {
            dt = func_800D8FF8();
        }
    } else {
        func_80015ECC(0, face);
        func_80015F5C(0, side);
        dt = func_800D9004();
    }
    switch (box[0x171]) {
    case 1:
        if (box[0x19D]) {
            (*(u8 * *)(box + 0x1A0)) += box[0x19C] + 1;
        } else {
            (*(u8 * *)(box + 0x1A0)) = ((u8 **)(box + 0x17C))[box[0x175]];
            ((struct Flags *)(box + 0x1E4))->b19 = _gldialog_entrypoint_1((*(u8 * *)(box + 0x1A0)));
        }
        box[0x19C] = func_80801C0C_gczoombox(box, (*(u8 * *)(box + 0x1A0)));
        if (*(box[0x19C] + (*(u8 * *)(box + 0x1A0)))) {
            box[0x19D] = 1;
        } else {
            box[0x19D] = 0;
        }
        func_8080014C_gczoombox((*(u8 * *)(box + 0x1A0)), ((struct Box *)box)->text2, 0, box[0x19C]);
        ((struct Box *)box)->text2[box[0x19C]] = 0;
        if (!box[0x19D]) {
            box[0x175]++;
        }
        if (box[0x19D] || box[0x175] < box[0x174]) {
            ((struct Flags *)(box + 0x1E4))->b25 = 0;
            ((struct Flags *)(box + 0x1E4))->b31 = 0;
        } else {
            ((struct Flags *)(box + 0x1E4))->b25 = 1;
            ((struct Flags *)(box + 0x1E4))->b31 = 1;
        }
        if (((struct Flags *)(box + 0x1E4))->b27) {
            ((struct Flags *)(box + 0x1E4))->b26 = 1;
            ((struct Flags *)(box + 0x1E4))->b30 = 1;
            ((struct Flags *)(box + 0x1E4))->b29 = 0;
        } else {
            ((struct Flags *)(box + 0x1E4))->b26 = 0;
        }
        func_808006E0_gczoombox(box, box[0x19C]);
        box[0x171] = 2;
        (*(s8 *)(box + 0x1CE)) = box[0x19E] = 0;
        (*(f32 *)(box + 0x1D4)) = 0.0f;
        if (((struct Flags *)(box + 0x1E4))->b19) {
            box[0x19E] += 2;
        }
        ((struct Flags *)(box + 0x1E4))->b23 = 1;
        func_80800294_gczoombox(box);
        break;
    case 2:
        interval = (*(f32 *)(box + 0x1D8));
        if (((struct Flags *)(box + 0x1E4))->b19) {
            interval *= 1.5f;
        }
        if (((struct Flags *)(box + 0x1E4))->b4) {
            interval *= 0.01998901367f;
            ((struct Flags *)(box + 0x1E4))->b4 = 0;
        } else if (face[0] && ((struct Flags *)(box + 0x1E4))->b12) {
            interval *= 0.4499969482f;
        } else if (side[0] && ((struct Flags *)(box + 0x1E4))->b12) {
            interval *= 2;
        }
        (*(f32 *)(box + 0x1D4)) += dt;
        while (interval < (*(f32 *)(box + 0x1D4)) && box[0x19C] >= box[0x19E]) {
            box[0x19E]++;
            if (func_808005F0_gczoombox(((struct Box *)box)->text2[box[0x19E]], ((struct Flags *)(box + 0x1E4))->b19)) {
                (*(f32 *)(box + 0x1D4)) -= (face[0] && ((struct Flags *)(box + 0x1E4))->b12) ? 0.04999542236f : 0.09999084473f;
            }
            (*(f32 *)(box + 0x1D4)) -= interval;
        }
        if (((struct Flags *)(box + 0x1E4))->b26) {
            if (((struct Flags *)(box + 0x1E4))->b3) {
                (box + 0x30)[0] = 0xFD;
                (box + 0x30)[1] = 0x68;
                func_8080014C_gczoombox(((struct Box *)box)->text2, (box + 0x30) + 2, 0, box[0x19E]);
                (box + 0x30)[box[0x19E] + 2] = 0;
            } else {
                func_8080014C_gczoombox(((struct Box *)box)->text2, (box + 0x30), 0, box[0x19E]);
            }
            ((struct Flags *)(box + 0x1E4))->b29 = 1;
        } else {
            if (((struct Flags *)(box + 0x1E4))->b3) {
                ((u8 *)box)[0] = 0xFD;
                ((u8 *)box)[1] = 0x68;
                func_8080014C_gczoombox(((struct Box *)box)->text2, (u8 *)box + 2, 0, box[0x19E]);
                ((u8 *)box)[box[0x19E] + 2] = 0;
            } else {
                func_8080014C_gczoombox(((struct Box *)box)->text2, (u8 *)box, 0, box[0x19E]);
            }
            ((struct Flags *)(box + 0x1E4))->b27 = 1;
            ((struct Flags *)(box + 0x1E4))->b30 = 1;
        }
        if (box[0x19C] < box[0x19E]) {
            func_808002E4_gczoombox(box);
        }
        break;
    case 3:
        if ((face[0] && ((struct Flags *)(box + 0x1E4))->b12) || (*(f32 *)(box + 0x1C4)) < 0.0f) {
            box[0x171] = 4;
            (*(f32 *)(box + 0x1C8)) = 60.0f * dt * ((struct Box *)box)->speed;
        } else {
            (*(f32 *)(box + 0x1C4)) -= dt;
        }
        break;
    case 4:
        if (face[0] && ((struct Flags *)(box + 0x1E4))->b12) {
            (*(f32 *)(box + 0x1C8)) = 60.0f * dt * (((struct Box *)box)->speed + 2);
            ((struct Flags *)(box + 0x1E4))->b23 = 0;
        } else if (((struct Flags *)(box + 0x1E4))->b12 && side[0]) {
            (*(f32 *)(box + 0x1C8)) = 60.0f * dt * (((struct Box *)box)->speed - 1);
        }
        ((struct Flags *)(box + 0x1E4))->b17 = 0;
        if (((struct Flags *)(box + 0x1E4))->b26 || ((struct Flags *)(box + 0x1E4))->b31) {
            if (((struct Flags *)(box + 0x1E4))->b25) {
                if (((struct Flags *)(box + 0x1E4))->b6 && box[0x171] != 10 && ((struct Flags *)(box + 0x1E4))->b26) {
                    func_80101238(0x6D, 0);
                }
                gczoombox_entrypoint_14((u8 *)box);
                box[0x171] = 10;
            }
            if (!((struct Flags *)(box + 0x1E4))->b23 && !((struct Flags *)(box + 0x1E4))->b25) {
                (*(f32 *)(box + 0x1A4)) -= (*(f32 *)(box + 0x1C8));
                (*(f32 *)(box + 0x1A8)) -= (*(f32 *)(box + 0x1C8));
                ((struct Flags *)(box + 0x1E4))->b17 = 1;
            }
            if (!((struct Flags *)(box + 0x1E4))->b25 && (*(f32 *)(box + 0x1A4)) <= (*(s16 *)(box + 0x1B0)) - (3 * (((struct Flags *)(box + 0x1E4))->b19 ? 15 : 12)) / 2) {
                func_8080014C_gczoombox((box + 0x30), (u8 *)box, 0, 0x30);
                func_808001D4_gczoombox((box + 0x30), 0x30);
                func_80800228_gczoombox(box);
                ((struct Flags *)(box + 0x1E4))->b30 = 1;
                ((struct Flags *)(box + 0x1E4))->b29 = 0;
                box[0x171] = 1;
            }
        } else if (!((struct Flags *)(box + 0x1E4))->b23) {
            box[0x171] = 1;
        }
        break;
    case 10:
        func_80801BD0_gczoombox((u8 *)box, 3);
        if (box[0x177] & 8) {
            ((struct Flags *)(box + 0x1E4))->b27 = 0;
            func_808004D0_gczoombox(box);
        } else if (box[0x177] & 4) {
            box[0x170] = 0;
            ((struct Flags *)(box + 0x1E4))->b25 = 0;
            box[0x171] = 4;
        }
        break;
    case 5:
        previousTime = -1.0f;
        if (((struct Flags *)(box + 0x1E4))->b16) {
            previousTime = func_80800364_gczoombox(box);
            if (((struct Flags *)(box + 0x1E4))->b14) {
                (*(f32 *)(box + 0x1C0)) = 1.0f - (*(f32 *)(box + 0x1EC)) / (*(f32 *)(box + 0x1F4));
            }
        }
        if (((struct Flags *)(box + 0x1E4))->b11 && ((struct Flags *)(box + 0x1E4))->b16 && func_808003D8_gczoombox(box, previousTime, (*(f32 *)(box + 0x1F4)) * 0.1f)) {
            if (func_800C710C(0)) {
                _gcaudiolist_entrypoint_1(2, (*(s16 *)(box + 0x16A)));
            }
        }
        if (((struct Flags *)(box + 0x1E4))->b16 && func_808003D8_gczoombox(box, previousTime, (*(f32 *)(box + 0x1F4)))) {
            (*(f32 *)(box + 0x1EC)) = (*(f32 *)(box + 0x1F4));
            if (((struct Flags *)(box + 0x1E4))->b14) {
                func_808000C4_gczoombox(box);
            }
            ((struct Flags *)(box + 0x1E4))->b13 = 0;
            ((struct Flags *)(box + 0x1E4))->b14 = ((struct Flags *)(box + 0x1E4))->b13;
            ((struct Flags *)(box + 0x1E4))->b16 = 0;
        }
        if (!((struct Flags *)(box + 0x1E4))->b16) {
            func_80801BD0_gczoombox((u8 *)box, 2);
            if (box[0x177] & 4) {
                box[0x171] = 1;
            } else if (box[0x177] & 8) {
                func_808004D0_gczoombox(box);
            }
        }
        break;
    case 6:
        previousTime2 = -1.0f;
        if (((struct Flags *)(box + 0x1E4))->b16) {
            previousTime2 = func_80800364_gczoombox(box);
            if (((struct Flags *)(box + 0x1E4))->b14) {
                (*(f32 *)(box + 0x1C0)) = (*(f32 *)(box + 0x1EC)) / (*(f32 *)(box + 0x1F4));
            }
        }
        if (((struct Flags *)(box + 0x1E4))->b11 && ((struct Flags *)(box + 0x1E4))->b16 && func_808003D8_gczoombox(box, previousTime2, (*(f32 *)(box + 0x1F4)) * 0.9f)) {
            if (func_800C710C(1)) {
                _gcaudiolist_entrypoint_1(3, (*(s16 *)(box + 0x16A)));
            }
        }
        if (((struct Flags *)(box + 0x1E4))->b16 && (*(f32 *)(box + 0x1EC)) <= 0) {
            (*(f32 *)(box + 0x1EC)) = 0;
            if (((struct Flags *)(box + 0x1E4))->b14) {
                func_808000C4_gczoombox(box);
            }
            ((struct Flags *)(box + 0x1E4))->b13 = 0;
            ((struct Flags *)(box + 0x1E4))->b14 = ((struct Flags *)(box + 0x1E4))->b13;
            ((struct Flags *)(box + 0x1E4))->b16 = 0;
        }
        if (!((struct Flags *)(box + 0x1E4))->b16) {
            func_80801BD0_gczoombox((u8 *)box, 4);
            if (box[0x177] & 0x10) {
                func_80801B90_gczoombox((u8 *)box);
            } else if (box[0x177] & 2) {
                func_80800470_gczoombox(box);
            }
        }
        break;
    case 7:
        func_80800964_gczoombox(box);
        func_80801BD0_gczoombox((u8 *)box, 6);
        break;
    case 8:
        if ((*(f32 *)(box + 0x1E0)) == 0.0f) {
            ((struct Flags *)(box + 0x1E4))->b28 = 1;
        }
        if (((struct Flags *)(box + 0x1E4))->b11 && (*(f32 *)(box + 0x1E0)) == 0) {
            if (func_800C710C(2)) {
                _gcaudiolist_entrypoint_1(4, (*(s16 *)(box + 0x16A)));
            }
        }
        if (((struct Flags *)(box + 0x1E4))->b24) {
            (*(s16 *)(box + 0x1AE)) = func_800F3780((*(f32 *)(box + 0x1E0)), D_80803E44_gczoombox, 7) + ((struct Box *)box)->startX;
        } else {
            (*(s16 *)(box + 0x1AE)) = ((struct Box *)box)->startX - func_800F3780((*(f32 *)(box + 0x1E0)), D_80803E44_gczoombox, 7);
        }
        if ((*(f32 *)(box + 0x1E0)) >= 1.0f) {
            (*(s16 *)(box + 0x1AE)) = ((struct Box *)box)->startX;
            func_80801BD0_gczoombox((u8 *)box, 1);
            if (box[0x177] & 2) {
                func_80800470_gczoombox(box);
            } else if (box[0x177] & 0x10) {
                func_80801B90_gczoombox((u8 *)box);
            }
        } else {
            (*(f32 *)(box + 0x1E0)) += 5.0f * dt;
        }
        break;
    case 9:
        if (((struct Flags *)(box + 0x1E4))->b11 && (*(f32 *)(box + 0x1E0)) == 0) {
            if (func_800C710C(3)) {
                _gcaudiolist_entrypoint_1(5, (*(s16 *)(box + 0x16A)));
            }
        }
        if (((struct Flags *)(box + 0x1E4))->b24) {
            (*(s16 *)(box + 0x1AE)) = func_800F3780(1.0f - (*(f32 *)(box + 0x1E0)), D_80803E44_gczoombox, 7) + ((struct Box *)box)->startX;
        } else {
            (*(s16 *)(box + 0x1AE)) = ((struct Box *)box)->startX - func_800F3780(1.0f - (*(f32 *)(box + 0x1E0)), D_80803E44_gczoombox, 7);
        }
        if ((*(f32 *)(box + 0x1E0)) >= 1.0f) {
            ((struct Flags *)(box + 0x1E4))->b28 = 0;
            func_80801BD0_gczoombox((u8 *)box, 5);
            if (box[0x177] & 0x20) {
                box[0x171] = 7;
            } else if (box[0x177] & 1) {
                func_80801B30_gczoombox((u8 *)box);
            }
        } else {
            (*(f32 *)(box + 0x1E0)) += 5.0f * dt;
        }
        break;
    case 11:
        if (box[0x177] & 1) {
            func_80801B30_gczoombox((u8 *)box);
        }
        break;
    }
}

/* extern */

void func_80802B94_gczoombox(u8 *arg0, s32 arg1) {
    s32 func_800AF5A0(s16 *arg0);
    s16 _gczoomboxdata_entrypoint_1(s32);
    s32 func_800D674C(s32);
    s16 temp_v0;

    if (arg1 != 0x44) {
        temp_v0 = _gczoomboxdata_entrypoint_1(arg1);
        (*(s16 *)((s8 *)arg0 + (0x140))) = temp_v0;
        (*(s8 *)((s8 *)arg0 + (0x1D1))) = func_800AF5A0(func_800D674C(temp_v0 & 0xFFFF));
        (*(s8 *)((s8 *)arg0 + (0x1CF))) = 0;
        return;
    }
    (*(s16 *)((s8 *)arg0 + (0x140))) = 0;
    (*(s8 *)((s8 *)arg0 + (0x1D1))) = 0;
}

void func_80802BF4_gczoombox(u8 *arg0) {
    void func_800C3528(u8 index, s32 enabled);
    void func_800C431C(u8 arg0, s32 arg1);
    s32 i;

    for (i = 0; i < arg0[0x178]; i++) {
        if (arg0[0x1E6] & 1) {
            func_800C431C((arg0 + i)[0x144], 0);
        }
        if (*(s32 *)(arg0 + 0x1E4) & 1) {
            func_800C3528((arg0 + i)[0x144], 1);
        }
    }
}

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

void gczoombox_entrypoint_20(void *arg0, f32 arg1, s32 arg2, s32 arg3, f32 arg4, s32 arg5, s32 arg6) {
    struct Flags {
        u8 pad[0x1E6];
        u8 high : 3;
        u8 flag10 : 1;
        u8 middle : 1;
        u8 flag4 : 1;
        u8 low : 2;
    };
    if (arg0 != NULL) {
        (*(s8 *)((s8 *)(arg0) + (0x1CC))) = arg2;
        (*(s8 *)((s8 *)(arg0) + (0x1CD))) = arg3;
        (*(f32 *)((s8 *)(arg0) + (0x1D8))) = (f32) (1.0f / arg1);
        func_80800358_gczoombox(arg0, arg4);
        if (arg5 != 0) {
            ((struct Flags *)arg0)->flag10 = 1;
        } else {
            ((struct Flags *)arg0)->flag10 = 0;
        }
        if (arg6 != 0) {
            ((struct Flags *)arg0)->flag4 = 1;
        } else {
            ((struct Flags *)arg0)->flag4 = 0;
        }
    }
}

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

/* extern */

void gczoombox_entrypoint_24(u8 *arg0, s32 arg1) {
    struct Flags { u8 rest : 7; u8 flag : 1; };
    void func_80802BF4_gczoombox(u8 *);
    if (arg1 != 0) {
        ((struct Flags *)(arg0 + 0x1E6))->flag = 1;
    } else {
        ((struct Flags *)(arg0 + 0x1E6))->flag = 0;
    }
    func_80802BF4_gczoombox(arg0);
}

/* extern */

void gczoombox_entrypoint_25(u8 *arg0, s32 arg1) {
    struct Flags { u8 rest : 7; u8 flag : 1; };
    void func_80802BF4_gczoombox(u8 *);
    if (arg1 != 0) {
        ((struct Flags *)(arg0 + 0x1E7))->flag = 1;
    } else {
        ((struct Flags *)(arg0 + 0x1E7))->flag = 0;
    }
    func_80802BF4_gczoombox(arg0);
}

void gczoombox_entrypoint_26(void *arg0, s32 arg1, f32 arg2, f32 arg3, s32 arg4) {
    struct Flags { u8 flag : 1; u8 rest : 7; };
    if (arg0 != NULL) {
        if ((*(u8 *)((s8 *)(arg0) + (0x1E4))) & 1) {
            (*(s16 *)((s8 *)(arg0) + (0x1B2))) = (s16) (0x130 - arg1);
            (*(s16 *)((s8 *)(arg0) + (0x1AE))) = (s16) (0x1BC - arg1);
        } else {
            (*(s16 *)((s8 *)(arg0) + (0x1B2))) = arg1;
            (*(s16 *)((s8 *)(arg0) + (0x1AE))) = (s16) (arg1 - 0x8C);
        }
        (*(f32 *)((s8 *)(arg0) + (0x1DC))) = arg2;
        (*(f32 *)((s8 *)(arg0) + (0x1F4))) = arg3;
        if (arg4 != 0) {
            ((struct Flags *)((s8 *)arg0 + 0x1E6))->flag = 1;
            return;
        }
        ((struct Flags *)((s8 *)arg0 + 0x1E6))->flag = 0;
    }
}

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

/* extern */

void gczoombox_entrypoint_38(u8 *arg0, s32 arg1) {
    void func_80800294_gczoombox(void *);
    if (arg0 != NULL) {
        (*(s16 *)((s8 *)(arg0) + (0x1B0))) = arg1;
        func_80800294_gczoombox(arg0);
    }
}

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

void gczoombox_entrypoint_44(void *arg0, s32 arg1) {
    struct Flags {
        u8 padding[0x1E7];
        u8 high : 2;
        u8 flag : 1;
        u8 low : 5;
    };
    if (arg1 != 0) {
        ((struct Flags *)arg0)->flag = 1;
        return;
    }
    ((struct Flags *)arg0)->flag = 0;
}

void gczoombox_entrypoint_45(void *arg0, s32 arg1) {
    struct Flags {
        u8 padding[0x1E7];
        u8 high : 3;
        u8 flag : 1;
        u8 low : 4;
    };
    if (arg1 != 0) {
        ((struct Flags *)arg0)->flag = 1;
        return;
    }
    ((struct Flags *)arg0)->flag = 0;
}
