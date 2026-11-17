#include "core2/1E2F380.h"

u32 D_8007AED0[6];
u8 D_8007AEE8[6];


void func_80017850(s32 arg0) {
    extern u8 D_8007AEE8[];
    D_8007AEE8[arg0] = 1;
}

void func_80017864(void) {
    extern u8 D_8007AE80[];
    extern u8 D_8007AEA0[];
    int index;
    index = 0;
    do {
        D_8007AE80[index++] = 0xFF;
    } while (&D_8007AE80[index] < D_8007AEA0);
    for (index = 0; index < 6; index++) {
        D_8007AEE8[index] = 1;
    }
}

s32 func_800178C4(BtIntPtr arg0, s32 arg1, f32 arg2)
{
  typedef struct 
  {
    u32 rate;
    u32 count;
  } Header;
  typedef struct 
  {
    Header *header;
  } Sequence;
  typedef struct 
  {
    u8 unk0[0xB];
    u8 duration;
    u8 unkC[0x2C];
  } Channel;
  typedef struct 
  {
    u8 unk0[0x18];
    Sequence *sequence;
    u8 unk1C[0x44];
    Channel *channels;
  } Player;
  u8 *func_80017810(BtIntPtr);
  u32 func_800260B0(void *);
  void func_80026238(BtIntPtr arg0, s32 arg1, volatile u8 arg2, volatile s32 arg3);
  void func_800262DC(BtIntPtr arg0, s32 arg1, u8 arg2);
  extern const f32 D_80041720;
  extern u8 D_8007AE80[];
  extern u8 D_8007AEA0[];
  extern u32 D_8007AED0[];
  extern u8 D_8007AEE8[];
  Player *player;
  u32 tempo;
  s32 i;
  u32 duration;
  u32 volume;
  u32 fadeTime;
  u32 immediate;
  u32 faded;
  u32 reset;
  u32 channelOffset;
  u32 *mask;
  s32 pad0;
  s32 pad1;
  player = (Player *) func_80017810(arg0);
  if (player == NULL)
  {
    return 0;
  }
  if (player->sequence != NULL)
  {
    tempo = func_800260B0(player);
    duration = ((arg2 * D_80041720) * player->sequence->header->rate) / tempo;
    if (duration == 0)
    {
      for (immediate = 0; immediate < player->sequence->header->count; immediate++)
      {
        if (D_8007AEE8[arg0] || ((arg1 & (1 << immediate)) != (D_8007AED0[arg0] & (1 << immediate))))
        {
          if (arg1 & (1U << immediate))
          {
            func_800262DC(player, immediate, D_8007AE80[immediate]);
          }
          else
          {
            func_800262DC(player, immediate, 0);
          }
        }
      }

      D_8007AED0[arg0] = arg1;
    }
    else
    {
      for (faded = 0; faded < player->sequence->header->count; faded++)
      {
        if (D_8007AEE8[arg0] || ((arg1 & (1 << faded)) != (D_8007AED0[arg0] & (1 << faded))))
        {
          channelOffset = faded * (sizeof(Channel));
          fadeTime = (u32) (arg2 * 10.0f);
          if (arg1 & (1U << faded))
          {
            volume = D_8007AE80[faded];
          }
          else
          {
            volume = 0;
          }
          ((Channel *) (((u8 *) player->channels) + channelOffset))->duration = fadeTime;
          func_80026238(player, faded, volume, 0);
        }
      }

      D_8007AED0[arg0] = arg1;
    }
    for (i = 0; i < player->sequence->header->count; i++)
    {
      D_8007AE80[i] = 0xFF;
    }

    return 1;
  }
  mask = &D_8007AED0[arg0];
  for (i = 0; (i ^ 0) < 0x20; i = ((u32) i) + 1U)
  {
    if (D_8007AEE8[arg0] || ((arg1 & (1 << i)) != ((*mask) & (1 << i))))
    {
      if (arg1 & (1U << i))
      {
        func_800262DC(player, i, D_8007AE80[i]);
      }
      else
      {
        func_800262DC(player, i, 0);
      }
    }
  }

  *mask = arg1;
  reset = 0;
  do
  {
    D_8007AE80[reset + 1] = 0xFF;
    D_8007AE80[reset + 2] = 0xFF;
    D_8007AE80[reset + 3] = 0xFF;
    D_8007AE80[reset] = 0xFF;
    reset += 4;
  } while ((BtUIntPtr) D_8007AEA0 != ((BtUIntPtr) &D_8007AE80[reset] ^ 0));

  return 0;
}

s32 func_80017D74(BtIntPtr arg0, s32 arg1, f32 arg2) {
    u8 *func_80017810(BtIntPtr);
    u32 func_800260B0(void *);
    void func_80026330(u8 *, s32);
    extern u8 D_8007AEA0[];
    extern s32 D_8007AEB8[];
    u8 *player;
    s32 current;
    s32 difference;

    player = func_80017810(arg0);
    if (*(s32 *)(player + 0x18) != 0) {
        if (arg1 == -1) {
            *(s32 *)(D_8007AEA0 + arg0 * 4) = -1;
            do { D_8007AEB8[arg0] = 0; } while (0);
            return 1;
        }
        if (arg1 != *(s32 *)(D_8007AEA0 + arg0 * 4)) {
            current = func_800260B0(player);
            if (arg2 == 0.0f) {
                func_80026330(player, arg1);
                *(s32 *)(D_8007AEA0 + arg0 * 4) = arg1;
                return 1;
            }
            difference = current < arg1 ? arg1 - current : current - arg1;
            *(s32 *)(D_8007AEA0 + arg0 * 4) = arg1;
            D_8007AEB8[arg0] = (s32)((f32)difference / (arg2 * 30.0f));
        }
        return 1;
    }
    *(s32 *)(D_8007AEA0 + arg0 * 4) = -1;
    do { D_8007AEB8[arg0] = 0; } while (0);
    return 0;
}

void func_80017EC0(s32 arg0) {
    int func_80017778(s32);
    u8 *func_80017810(BtIntPtr);
    u32 func_800260B0(void *);
    void func_80026330(u8 *, s32);
    extern u8 D_8007AEA0[];
    extern s32 D_8007AEB8[];
    u8 *player;
    s32 current;

    player = func_80017810(arg0);
    if (player != NULL && *(s32 *)(player + 0x18) != 0 &&
        D_8007AEB8[arg0] != 0 && !func_80017778(arg0)) {
        current = func_800260B0(player);
        if (current == (*(s32 *)(D_8007AEA0 + arg0 * 4))) {
            D_8007AEB8[arg0] = 0;
            return;
        }
        if (D_8007AEB8[arg0] + current < (*(s32 *)(D_8007AEA0 + arg0 * 4))) {
            current = (*(s32 *)(D_8007AEA0 + arg0 * 4)) < D_8007AEB8[arg0] + current ? (*(s32 *)(D_8007AEA0 + arg0 * 4)) : D_8007AEB8[arg0] + current;
        } else if ((*(s32 *)(D_8007AEA0 + arg0 * 4)) < current - D_8007AEB8[arg0]) {
            current = current - D_8007AEB8[arg0] < (*(s32 *)(D_8007AEA0 + arg0 * 4)) ? (*(s32 *)(D_8007AEA0 + arg0 * 4)) : current - D_8007AEB8[arg0];
        } else {
            D_8007AEB8[arg0] = 0;
            current = (*(s32 *)(D_8007AEA0 + arg0 * 4));
        }
        func_80026330(player, current);
    }
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
u8 D_8007AE80 [ 32 ] BT_DATA(16, bss_core1bss1_0_audio_tail, 0x0);
u8 D_8007AEA0 [ 24 ] BT_DATA(4, bss_core1bss1_0_audio_tail, 0x20);
s32 D_8007AEB8 [ 6 ] BT_DATA(4, bss_core1bss1_0_audio_tail, 0x38);
#endif
