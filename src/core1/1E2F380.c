#include "core2/1E2F380.h"

typedef struct {
    s32 unk0;
    s32 active;
    s32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    OSPfs pfs;
} Motor;
extern Motor D_8007B2D0[];

void func_80017850(s32 arg0) {
    extern u8 D_8007AEE8[];
    D_8007AEE8[arg0] = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2F380/func_80017864.s")

s32 func_800178C4(s32 arg0, s32 arg1, f32 arg2)
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
  u8 *func_80017810(s32);
  u32 func_800260B0(void *);
  void func_80026238(void *, u32, u8, s32);
  void func_800262DC(void *, u32, u8);
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
  } while ((u32) D_8007AEA0 != ((u32) &D_8007AE80[reset] ^ 0));

  return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2F380/func_80017D74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2F380/func_80017EC0.s")

void func_80017FC0(s32 arg0) {
    void func_80016934(s32);
    Motor *motor;

    motor = &D_8007B2D0[arg0];
    if (motor->active != 0) {
        func_80016934(4);
        motor->active = __osMotorAccess(&motor->pfs, 1) == 0;
        func_80016934(0);
    }
}

void func_80018028(s32 arg0) {
    void func_80016934(s32);
    Motor *motor;

    motor = &D_8007B2D0[arg0];
    if (motor->active != 0) {
        func_80016934(4);
        motor->active = __osMotorAccess(&motor->pfs, 0) == 0;
        func_80016934(0);
    }
}

void func_80018090(s32 arg0) {
    void func_80016934(s32);
    extern OSMesgQueue *D_8007AF0C;
    Motor *motor;

    motor = &D_8007B2D0[arg0];
    if (motor->active == 0) {
        func_80016934(4);
        motor->active = osMotorInit(D_8007AF0C, &motor->pfs, arg0) == 0;
        func_80016934(0);
    }
}

void func_80018108(s32 arg0) { void func_80016934(s32); extern OSMesgQueue *D_8007AF0C; Motor *motor; if (func_80016800(arg0) != 0) { func_80016934(4); motor = &D_8007B2D0[arg0]; motor->unk0 = osMotorInit(D_8007AF0C, &motor->pfs, arg0) == 0; func_80016934(0); } }

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2F380/func_8001817C.s")

/* extern */

void func_800183D4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    void func_800187B4(s32, f32, f32, f32);
    func_800187B4(arg0, (f32) arg1 / 524288.0f, (f32) arg2 / 524288.0f, (f32) arg3 / 524288.0f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2F380/func_80018444.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2F380/func_800184E8.s")

void func_8001862C(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2F380/func_80018634.s")

void func_80018704(s32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4) {
    extern f32 D_80041730;
    Motor *motor;

    if (arg3 != 0.0f) {
        motor = &D_8007B2D0[arg0];
        if (motor->unk0 != 0 && (arg4 != 0 || !(D_80041730 < motor->unkC - motor->unk10) || !(arg1 + arg2 < motor->unk18 + motor->unk14))) {
            motor->unkC = arg3;
            motor->unk14 = arg1;
            motor->unk10 = 0;
            motor->unk18 = arg2;
        }
    }
}

void func_800187B4(s32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    void func_80018704(s32, f32, f32, f32, s32);
    func_80018704(arg0, arg1, arg2, arg3, 0);
}

void func_800187E8(s32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    void func_80018704(s32, f32, f32, f32, s32);
    func_80018704(arg0, arg1, arg2, arg3, 1);
}

void func_80018820(s32 arg0, f32 arg1, f32 arg2) { func_800187B4(arg0, arg1, arg1, arg2); }

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2F380/func_80018854.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2F380/func_800189A8.s")
