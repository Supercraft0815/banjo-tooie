#include "core2/1E6F080.h"

s32 func_80095790()
{
    return 0xAC;
}

/* extern */

void func_80095798(void *arg0) {
    void func_80098590(f32 **, f32 *);
    f32 func_800985B8(f32 **);
    f32 func_8009864C(void *);
    f32 func_800F1DCC(f32, f32);
    s32 func_800F1E6C(f32 *, f32 *, f32 *);
    f32 mlAbsF(f32);
    void yaw_applyIdeal(PlayerState *);
    f32 yaw_get(PlayerState *);
    void yaw_setIdeal(PlayerState *, f32);
    f32 sp3C[3];
    f32 sp38;
    f32 temp_f0;
    f32 sp30;

    sp38 = func_800985B8(arg0);
    temp_f0 = func_8009864C(arg0);
    if (temp_f0 < (*(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x94)) + 0x7C))) {
        (*(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x94)) + 0x7C)) = temp_f0;
    }
    if ((*(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x94)) + 0x7C)) < sp38) {
        (*(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x94)) + 0x7C)) = sp38;
    }
    func_80098590(arg0, sp3C);
    func_800F1E6C((f32 *)((*(u8 **)((s8 *)(arg0) + (0x94))) + 0x78), sp3C, &sp30);
    if (mlAbsF(func_800F1DCC(sp30, yaw_get(arg0))) > 1.0f) {
        yaw_setIdeal(arg0, sp30);
        yaw_applyIdeal(arg0);
    }
}

void func_80095870(void *arg0, f32 *arg1, f32 *arg2) {
    *arg1 = (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x94)))) + (4)));
    *arg2 = (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x94)))) + (8)));
}

s32 func_8009588C(s32 *arg0)
{
    return ((s32 *)arg0[37])[5];
}

u32 func_80095898(s32 *arg0)
{
    return ((u8 *)arg0[37])[162];
}

/* extern */

s32 func_800958A4(PlayerState *arg0, f32 arg1, f32 arg2) {
    void func_8009C128(PlayerState *, f32[3]);
    void *func_800C6C94(f32[3], f32, f32[3], u32);
    s32 pad;
    f32 sp28[3];
    f32 sp1C[3];
    s32 var_v1;

    func_8009C128(arg0, sp28);
    sp28[1] += arg1;
    if (func_800C6C94(sp28, arg2, sp1C, (*(u32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x94)))) + (0x14)))) != 0) {
        var_v1 = 1;
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

void func_8009590C(PlayerState *arg0, f32 arg1) {
    void func_800C68A0(void *arg0, f32 arg1);
    if (arg1 == 0.0f) {
        func_800C68A0(*(*(void ***)((s8 *)(arg0) + (0x94))), 56.0f);
        return;
    }
    func_800C68A0(*(*(void ***)((s8 *)(arg0) + (0x94))), arg1);
}

void func_80095964(void *arg0, s32 arg1) {
    void func_80095A08(void *arg0, s32 arg1, s32 arg2);
    if (arg1 != 0) {
        func_80095A08(arg0, 8, 1);
        func_80095A08(arg0, 4, 0);
        return;
    }
    func_80095A08(arg0, 8, 0);
    func_80095A08(arg0, 4, 1);
}    typedef struct { u8 pad0[0x4]; f32 unk4; f32 unk8; u8 padC[0x58]; f32 unk64; f32 unk68; } Obj1E6F080_func_800959C8_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void func_800959C8(PlayerState *arg0, f32 arg1, f32 arg2) {
    void *temp_v0;

    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x94)))) + (0x64))) = arg1;
    temp_v0 = (*(void **)((s8 *)(arg0) + (0x94)));
    (((Obj1E6F080_func_800959C8_temp_v0 *)temp_v0)->unk4) = (f32) (((Obj1E6F080_func_800959C8_temp_v0 *)temp_v0)->unk64);
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x94)))) + (0x68))) = arg2;
    temp_v0 = (*(void **)((s8 *)(arg0) + (0x94)));
    (((Obj1E6F080_func_800959C8_temp_v0 *)temp_v0)->unk8) = (f32) (((Obj1E6F080_func_800959C8_temp_v0 *)temp_v0)->unk68);
}

void func_800959FC(s32 *arg0, s32 arg1) {
    ((s32 *) arg0[37])[5] = arg1;
}    typedef struct { u8 pad0[0x14]; s32 unk14; } Obj1E6F080_func_80095A08_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */ typedef struct { u8 pad0[0x14]; s32 unk14; } Obj1E6F080_func_80095A08_temp_v0_2; /* offsets.py genstruct: fields from raw offsets on temp_v0_2; rename once understood */

void func_80095A08(void *arg0, s32 arg1, s32 arg2) {
    void *temp_v0;
    void *temp_v0_2;

    if (arg2 != 0) {
        temp_v0 = (*(void **)((s8 *)(arg0) + (0x94)));
        (((Obj1E6F080_func_80095A08_temp_v0 *)temp_v0)->unk14) = (s32) ((((Obj1E6F080_func_80095A08_temp_v0 *)temp_v0)->unk14) | arg1);
        return;
    }
    temp_v0_2 = (*(void **)((s8 *)(arg0) + (0x94)));
    (((Obj1E6F080_func_80095A08_temp_v0_2 *)temp_v0_2)->unk14) = (s32) ((((Obj1E6F080_func_80095A08_temp_v0_2 *)temp_v0_2)->unk14) & ~arg1);
}

void func_80095A40(PlayerState *arg0) {
    func_800959C8(arg0, 80.0f, 35.0f);
}

void func_80095A64(s32 *arg0) {
    arg0[20] = 0;
}

void func_80095A6C(s32 *arg0, s32 *arg1) {
    arg1[20] = (BtIntPtr) arg0;
}

/* extern */

void func_80095A74(void *arg0, s32 arg1) {
    s32 func_800EA05C();
    if (func_800EA05C() == 0xB8) {
        if (arg1 != 0) {
            func_80095A08(arg0, 8, 1);
            return;
        }
        func_80095A08(arg0, 8, 0);
    }
}    typedef struct { u8 pad0[0x94]; u8 * unk94; } Obj1E6F080_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_80095AD0(s32 *arg0) {
    void baflag_clear(PlayerState *, int);
    u8 *func_800C5A38(void);
    void func_800EFD24(f32 *);
    void func_80096254(s32 *, s32);
    u8 temp_v0;
    u8 *temp_v1;

    (((Obj1E6F080_arg0 *)arg0)->unk94)[0xA3] = 0;
    temp_v1 = ((Obj1E6F080_arg0 *)arg0)->unk94;
    temp_v0 = temp_v1[0xA3];
    temp_v1[0x54] = temp_v0;
    (((Obj1E6F080_arg0 *)arg0)->unk94)[0xA1] = temp_v0;
    (((Obj1E6F080_arg0 *)arg0)->unk94)[0x18] = temp_v0;
    (((Obj1E6F080_arg0 *)arg0)->unk94)[0x56] = temp_v0;
    (((Obj1E6F080_arg0 *)arg0)->unk94)[0xA0] = temp_v0;
    func_800959FC(arg0, 0x400005);
    **(u8 ***)((u8 *)arg0 + 0x94) = func_800C5A38();
    func_800EFD24((f32 *)(((Obj1E6F080_arg0 *)arg0)->unk94 + 0x90));
    func_800EFD24((f32 *)(((Obj1E6F080_arg0 *)arg0)->unk94 + 0x78));
    func_800EFD24((f32 *)(((Obj1E6F080_arg0 *)arg0)->unk94 + 0x84));
    func_800EFD24((f32 *)(((Obj1E6F080_arg0 *)arg0)->unk94 + 0x44));
    *(s32 *)(((Obj1E6F080_arg0 *)arg0)->unk94 + 0x1C) = 0;
    (((Obj1E6F080_arg0 *)arg0)->unk94)[0xA2] = 0;
    func_80095A40((PlayerState *)arg0);
    temp_v1 = ((Obj1E6F080_arg0 *)arg0)->unk94;
    *(f32 *)(temp_v1 + 4) = *(f32 *)(temp_v1 + 0x64);
    temp_v1 = ((Obj1E6F080_arg0 *)arg0)->unk94;
    *(f32 *)(temp_v1 + 8) = *(f32 *)(temp_v1 + 0x68);
    func_80096254(arg0, 1);
    func_8009590C((PlayerState *)arg0, 0.0f);
    *(s32 *)(((Obj1E6F080_arg0 *)arg0)->unk94 + 0x9C) = 0;
    func_800961AC((PlayerState *)arg0, 1);
    baflag_clear((PlayerState *)arg0, 1);
    baflag_clear((PlayerState *)arg0, 2);
    *(void (**)(s32 *, s32 *))(((Obj1E6F080_arg0 *)arg0)->unk94 + 0xC) = func_80095A6C;
    *(void (**)(s32 *))(((Obj1E6F080_arg0 *)arg0)->unk94 + 0x10) = func_80095A64;
    (((Obj1E6F080_arg0 *)arg0)->unk94)[0xA4] = 0;
}

/* extern */

void func_80095C10(void *arg0) {
    void func_800C5BA4(void* arg0);
    func_800C5BA4(*(*(s32 **)((s8 *)(arg0) + (0x94))));
}

f32 func_80095C34(f32 arg0, f32 arg1, f32 arg2) {
    f32 func_800F13F0(f32, f32);
    f32 func_800F0E00(f32, f32);
    if (arg1 < arg0) {
        arg1 = func_800F13F0(arg0, arg1 + arg2);
    } else if (arg0 < arg1) {
        arg1 = func_800F0E00(arg0, arg1 - arg2);
    }
    return arg1;
}

void func_80095C94(PlayerState *self)
{
  void baflag_clear(PlayerState *, int);
  typedef struct
  {
    void *floor;
    f32 radius;
    f32 height;
    u8 pad0C[12];
    u8 previous;
    u8 pad19[3];
    void *triangle;
    u8 pad20[48];
    s32 contact;
    u8 flag54;
    u8 flag55;
    u8 flag56;
    u8 pad57;
    f32 delta[3];
    f32 targetRadius;
    f32 targetHeight;
    u8 triangleCopy[12];
    f32 position[3];
    f32 oldPosition[3];
    f32 movement[3];
    s32 mode;
    u8 flagA0;
    u8 flagA1;
    u8 flagA2;
    u8 flagA3;
    u8 flagA4;
  } Collision;
  typedef struct
  {
    u8 pad00[0x94];
    Collision *collision;
    u8 pad98[0xEC];
    s32 id;
  } PlayerView;
  s32 func_80091E80(u8 *, s32);
  s32 func_8008E454(void *);
  void func_8009C128(PlayerState *, f32 *);
  s32 func_800BEAAC(f32 *, f32 *);
  void func_800C68E8(s8 *, s32, f32);
  void func_800CB840(s32, BtIntPtr);
  void func_8009C15C(PlayerState *, f32 *);
  u8 func_800C670C(void *arg0);
  f32 func_800C67D8(f32 *);
  f32 func_800A0E58(void *);
  void baphysics_set_vertical_velocity(PlayerState *, f32);
  f32 baphysics_get_vertical_velocity(PlayerState *);
  void func_800EFB24(void *, void *, void *);
  void func_800D4584(void *, f32 *, f32 *, f32 *);
  void func_8009C0F8();
  void func_800978A4(PlayerState *);
  void func_80096768(PlayerState *);
  void _bahitspline_entrypoint_2(PlayerState *);
  s32 func_80096530(void *);
  void func_80096254(s32 *, s32);
  void func_80096260(PlayerState *);
  void func_800CB870(void);
  s32 func_800F1418(s32, s32);
  void func_800FB508(void *, void *);
  int player_isStable(PlayerState *);
  s32 func_8010114C(BtIntPtr, s32, BtIntPtr);
  f32 position[3];
  f32 current[3];
  f32 previous[3];
  f32 floorHeight;
  f32 groundHeight;
  ((PlayerView *) self)->collision->flagA4 = 1;
  ((PlayerView *) self)->collision->contact = 0;
  if (!func_80091E80((u8 *) self, 4))
  {
    return;
  }
  if (!func_8008E454(self))
  {
    return;
  }
  func_8009C128(self, position);
  if (func_800BEAAC(position, &floorHeight))
  {
    func_800C68E8(((PlayerView *) self)->collision->floor, 1, floorHeight);
  }
  else
  {
    func_800C68E8(((PlayerView *) self)->collision->floor, 0, floorHeight);
  }
  ((PlayerView *) self)->collision->flagA1 = 0;
  ((PlayerView *) self)->collision->flag54 = 0;
  ((PlayerView *) self)->collision->flag55 = 0;
  ((PlayerView *) self)->collision->triangle = 0;
  ((PlayerView *) self)->collision->previous = ((PlayerView *) self)->collision->flag56;
  func_800CB840(1, ((PlayerView *) self)->id);
  ((PlayerView *) self)->collision->radius = func_80095C34(((PlayerView *) self)->collision->targetRadius, ((PlayerView *) self)->collision->radius, 1.0f);
  ((PlayerView *) self)->collision->height = func_80095C34(((PlayerView *) self)->collision->targetHeight, ((PlayerView *) self)->collision->height, 1.0f);
  switch (((PlayerView *) self)->collision->mode)
  {
    case 1:
    case 3:
    case 4:
    case 9:
      func_8009C128(self, ((PlayerView *) self)->collision->position);
      func_8009C15C(self, ((PlayerView *) self)->collision->oldPosition);
      if (((PlayerView *) self)->collision->mode == 3)
    {
      void *floor = ((PlayerView *) self)->collision->floor;
      if (func_800C670C((BtIntPtr) floor))
      {
        f32 y = func_800C67D8(floor);
        f32 offset = func_800A0E58(self);
        if ((y - offset) < ((PlayerView *) self)->collision->position[1])
        {
          ((PlayerView *) self)->collision->position[1] = y - offset;
          ((PlayerView *) self)->collision->flagA1 = 1;
          baphysics_set_vertical_velocity(self, 1.0f);
        }
      }
    }
      func_800EFB24(((PlayerView *) self)->collision->delta, ((PlayerView *) self)->collision->position, ((PlayerView *) self)->collision->oldPosition);
      func_800D4584(((PlayerView *) self)->collision, ((PlayerView *) self)->collision->oldPosition, ((PlayerView *) self)->collision->position, ((PlayerView *) self)->collision->delta);
      func_8009C0F8(self, ((PlayerView *) self)->collision->position);
      break;

    case 5:
      func_8009C128(self, ((PlayerView *) self)->collision->position);
      func_8009C15C(self, ((PlayerView *) self)->collision->oldPosition);
      func_800EFB24(((PlayerView *) self)->collision->delta, ((PlayerView *) self)->collision->position, ((PlayerView *) self)->collision->oldPosition);
      func_800D4584(((PlayerView *) self)->collision, ((PlayerView *) self)->collision->oldPosition, ((PlayerView *) self)->collision->position, ((PlayerView *) self)->collision->delta);
      func_80095798(self);
      func_8009C0F8(self, ((PlayerView *) self)->collision->position);
      break;

    case 7:
      func_800978A4(self);
      break;

    case 8:
      func_80096768(self);
      break;

    case 10:
      _bahitspline_entrypoint_2(self);

    case 2:
    case 6:
      ((PlayerView *) self)->collision->flag54 = 0;
      ((PlayerView *) self)->collision->flag55 = 0;
      ((PlayerView *) self)->collision->flag56 = 0;
      break;

  }

  if (func_800C670C((BtIntPtr) ((PlayerView *) self)->collision->floor))
  {
    groundHeight = func_800C67D8(((PlayerView *) self)->collision->floor);
    ((PlayerView *) self)->collision->flagA0 = ((PlayerView *) self)->collision->position[1] < groundHeight;
  }
  if (func_80096530(self))
  {
    ((PlayerView *) self)->collision->flag56 = 1;
  }
  if (((PlayerView *) self)->collision->flagA0 && ((groundHeight = func_800C67D8(((PlayerView *) self)->collision->floor) - func_800A0E58(self), ((PlayerView *) self)->collision->position[1] < groundHeight)))
  {
    func_80096254((s32 *) self, 3);
    if (((PlayerView *) self)->collision->flag56 && (baphysics_get_vertical_velocity(self) < 0.0f))
    {
      baphysics_set_vertical_velocity(self, -1.0f);
    }
  }
  else
    if (((PlayerView *) self)->collision->flag56)
  {
    func_80096260(self);
    if ((baphysics_get_vertical_velocity(self) < 0.0f) && (!(func_80096628(self) & 0x8000)))
    {
      baphysics_set_vertical_velocity(self, -1.0f);
    }
  }
  else
  {
    func_80096254((s32 *) self, 1);
  }
  if (((PlayerView *) self)->collision->flagA2)
  {
    func_8009C0F8(self, position);
  }
  func_800CB870();
  if (((PlayerView *) self)->collision->flag54)
  {
    ((PlayerView *) self)->collision->flagA3 = func_800F1418(((PlayerView *) self)->collision->flagA3 + 1, 3);
  }
  else
  {
    ((PlayerView *) self)->collision->flagA3 = 0;
  }
  func_8009C15C(self, previous);
  func_8009C128(self, current);
  func_800EFB24(((PlayerView *) self)->collision->movement, current, previous);
  if (((PlayerView *) self)->collision->triangle)
  {
    func_800FB508(((PlayerView *) self)->collision->triangleCopy, ((PlayerView *) self)->collision->triangle);
    ((PlayerView *) self)->collision->triangle = ((PlayerView *) self)->collision->triangleCopy;
  }
  baflag_clear(self, 1);
  baflag_clear(self, 2);
  if (((PlayerView *) self)->collision->contact && player_isStable(self))
  {
    func_8010114C(((PlayerView *) self)->collision->contact, 0x91, ((PlayerView *) self)->id);
  }
}
