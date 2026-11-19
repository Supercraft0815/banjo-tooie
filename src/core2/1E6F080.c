#include "core2/1E6F080.h"
#include "core2/movement_collision.h"

s32 func_80095790()
{
    return sizeof(PlayerCollisionState);
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
    if (temp_f0 < ((PlayerState *)arg0)->collisionState->position[1]) {
        ((PlayerState *)arg0)->collisionState->position[1] = temp_f0;
    }
    if (((PlayerState *)arg0)->collisionState->position[1] < sp38) {
        ((PlayerState *)arg0)->collisionState->position[1] = sp38;
    }
    func_80098590(arg0, sp3C);
    func_800F1E6C(((PlayerState *)arg0)->collisionState->position, sp3C, &sp30);
    if (mlAbsF(func_800F1DCC(sp30, yaw_get(arg0))) > 1.0f) {
        yaw_setIdeal(arg0, sp30);
        yaw_applyIdeal(arg0);
    }
}

void func_80095870(void *arg0, f32 *arg1, f32 *arg2) {
    *arg1 = ((PlayerState *)arg0)->collisionState->response.height;
    *arg2 = ((PlayerState *)arg0)->collisionState->response.radius;
}

s32 func_8009588C(s32 *arg0)
{
    return ((PlayerState *)arg0)->collisionState->response.flags;
}

u32 func_80095898(s32 *arg0)
{
    return ((PlayerState *)arg0)->collisionState->flagA2;
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
    if (func_800C6C94(sp28, arg2, sp1C, ((PlayerState *)arg0)->collisionState->response.flags) != 0) {
        var_v1 = 1;
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

void func_8009590C(PlayerState *arg0, f32 arg1) {
    void func_800C68A0(void *arg0, f32 arg1);
    if (arg1 == 0.0f) {
        func_800C68A0(((PlayerState *)arg0)->collisionState->response.object, 56.0f);
        return;
    }
    func_800C68A0(((PlayerState *)arg0)->collisionState->response.object, arg1);
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
}

void func_800959C8(PlayerState *arg0, f32 arg1, f32 arg2) {
    void *temp_v0;

    ((PlayerState *)arg0)->collisionState->targetHeight = arg1;
    temp_v0 = ((PlayerState *)arg0)->collisionState;
    ((PlayerCollisionState *)temp_v0)->response.height = (f32) ((PlayerCollisionState *)temp_v0)->targetHeight;
    ((PlayerState *)arg0)->collisionState->targetRadius = arg2;
    temp_v0 = ((PlayerState *)arg0)->collisionState;
    ((PlayerCollisionState *)temp_v0)->response.radius = (f32) ((PlayerCollisionState *)temp_v0)->targetRadius;
}

void func_800959FC(s32 *arg0, s32 arg1) {
    ((PlayerState *)arg0)->collisionState->response.flags = arg1;
}

void func_80095A08(void *arg0, s32 arg1, s32 arg2) {
    void *temp_v0;
    void *temp_v0_2;

    if (arg2 != 0) {
        temp_v0 = ((PlayerState *)arg0)->collisionState;
        ((PlayerCollisionState *)temp_v0)->response.flags = (s32) (((PlayerCollisionState *)temp_v0)->response.flags | arg1);
        return;
    }
    temp_v0_2 = ((PlayerState *)arg0)->collisionState;
    ((PlayerCollisionState *)temp_v0_2)->response.flags = (s32) (((PlayerCollisionState *)temp_v0_2)->response.flags & ~arg1);
}

void func_80095A40(PlayerState *arg0) {
    func_800959C8(arg0, 80.0f, 35.0f);
}

void func_80095A64(MovementCollision *state) {
    state->contact = 0;
}

void func_80095A6C(BtUIntPtr actor, BtUIntPtr userdata) {
    ((MovementCollision *)userdata)->contact = actor;
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
}

void func_80095AD0(s32 *arg0) {
    void baflag_clear(PlayerState *, int);
    u8 *func_800C5A38(void);
    void func_800EFD24(f32 *);
    void func_80096254(s32 *, s32);
    u8 temp_v0;
    PlayerCollisionState *temp_v1;

    ((PlayerState *)arg0)->collisionState->flagA3 = 0;
    temp_v1 = ((PlayerState *)arg0)->collisionState;
    temp_v0 = temp_v1->flagA3;
    temp_v1->response.blocked = temp_v0;
    ((PlayerState *)arg0)->collisionState->flagA1 = temp_v0;
    ((PlayerState *)arg0)->collisionState->response.previous = temp_v0;
    ((PlayerState *)arg0)->collisionState->response.flag = temp_v0;
    ((PlayerState *)arg0)->collisionState->flagA0 = temp_v0;
    func_800959FC(arg0, 0x400005);
    ((PlayerState *)arg0)->collisionState->response.object = func_800C5A38();
    func_800EFD24(((PlayerState *)arg0)->collisionState->movement);
    func_800EFD24(((PlayerState *)arg0)->collisionState->position);
    func_800EFD24(((PlayerState *)arg0)->collisionState->oldPosition);
    func_800EFD24(((PlayerState *)arg0)->collisionState->response.normal);
    ((PlayerState *)arg0)->collisionState->response.triangle = 0;
    ((PlayerState *)arg0)->collisionState->flagA2 = 0;
    func_80095A40((PlayerState *)arg0);
    temp_v1 = ((PlayerState *)arg0)->collisionState;
    temp_v1->response.height = temp_v1->targetHeight;
    temp_v1 = ((PlayerState *)arg0)->collisionState;
    temp_v1->response.radius = temp_v1->targetRadius;
    func_80096254(arg0, 1);
    func_8009590C((PlayerState *)arg0, 0.0f);
    ((PlayerState *)arg0)->collisionState->mode = 0;
    func_800961AC((PlayerState *)arg0, 1);
    baflag_clear((PlayerState *)arg0, 1);
    baflag_clear((PlayerState *)arg0, 2);
    ((PlayerState *)arg0)->collisionState->response.onContact = func_80095A6C;
    ((PlayerState *)arg0)->collisionState->response.resetContact = func_80095A64;
    ((PlayerState *)arg0)->collisionState->flagA4 = 0;
}

/* extern */

void func_80095C10(void *arg0) {
    void func_800C5BA4(void* arg0);
    func_800C5BA4(((PlayerState *)arg0)->collisionState->response.object);
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
  void func_8009C0F8(PlayerState *, f32 *);
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
  self->collisionState->flagA4 = 1;
  self->collisionState->response.contact = 0;
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
    func_800C68E8(self->collisionState->response.object, 1, floorHeight);
  }
  else
  {
    func_800C68E8(self->collisionState->response.object, 0, floorHeight);
  }
  self->collisionState->flagA1 = 0;
  self->collisionState->response.blocked = 0;
  self->collisionState->response.count = 0;
  self->collisionState->response.triangle = 0;
  self->collisionState->response.previous = self->collisionState->response.flag;
  func_800CB840(1, self->unk184);
  self->collisionState->response.height = func_80095C34(self->collisionState->targetHeight, self->collisionState->response.height, 1.0f);
  self->collisionState->response.radius = func_80095C34(self->collisionState->targetRadius, self->collisionState->response.radius, 1.0f);
  switch (self->collisionState->mode)
  {
    case 1:
    case 3:
    case 4:
    case 9:
      func_8009C128(self, self->collisionState->position);
      func_8009C15C(self, self->collisionState->oldPosition);
      if (self->collisionState->mode == 3)
    {
      void *floor = self->collisionState->response.object;
      if (func_800C670C(floor))
      {
        f32 y = func_800C67D8(floor);
        f32 offset = func_800A0E58(self);
        if ((y - offset) < self->collisionState->position[1])
        {
          self->collisionState->position[1] = y - offset;
          self->collisionState->flagA1 = 1;
          baphysics_set_vertical_velocity(self, 1.0f);
        }
      }
    }
      func_800EFB24(self->collisionState->delta, self->collisionState->position, self->collisionState->oldPosition);
      func_800D4584(&self->collisionState->response, self->collisionState->oldPosition, self->collisionState->position, self->collisionState->delta);
      func_8009C0F8(self, self->collisionState->position);
      break;

    case 5:
      func_8009C128(self, self->collisionState->position);
      func_8009C15C(self, self->collisionState->oldPosition);
      func_800EFB24(self->collisionState->delta, self->collisionState->position, self->collisionState->oldPosition);
      func_800D4584(&self->collisionState->response, self->collisionState->oldPosition, self->collisionState->position, self->collisionState->delta);
      func_80095798(self);
      func_8009C0F8(self, self->collisionState->position);
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
      self->collisionState->response.blocked = 0;
      self->collisionState->response.count = 0;
      self->collisionState->response.flag = 0;
      break;

  }

  if (func_800C670C(self->collisionState->response.object))
  {
    groundHeight = func_800C67D8(self->collisionState->response.object);
    self->collisionState->flagA0 = self->collisionState->position[1] < groundHeight;
  }
  if (func_80096530(self))
  {
    self->collisionState->response.flag = 1;
  }
  if (self->collisionState->flagA0 && ((groundHeight = func_800C67D8(self->collisionState->response.object) - func_800A0E58(self), self->collisionState->position[1] < groundHeight)))
  {
    func_80096254((s32 *) self, 3);
    if (self->collisionState->response.flag && (baphysics_get_vertical_velocity(self) < 0.0f))
    {
      baphysics_set_vertical_velocity(self, -1.0f);
    }
  }
  else
    if (self->collisionState->response.flag)
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
  if (self->collisionState->flagA2)
  {
    func_8009C0F8(self, position);
  }
  func_800CB870();
  if (self->collisionState->response.blocked)
  {
    self->collisionState->flagA3 = func_800F1418(self->collisionState->flagA3 + 1, 3);
  }
  else
  {
    self->collisionState->flagA3 = 0;
  }
  func_8009C15C(self, previous);
  func_8009C128(self, current);
  func_800EFB24(self->collisionState->movement, current, previous);
  if (self->collisionState->response.triangle)
  {
    func_800FB508(&self->collisionState->triangleCopy, self->collisionState->response.triangle);
    self->collisionState->response.triangle = &self->collisionState->triangleCopy;
  }
  baflag_clear(self, 1);
  baflag_clear(self, 2);
  if (self->collisionState->response.contact && player_isStable(self))
  {
    func_8010114C(self->collisionState->response.contact, 0x91, self->unk184);
  }
}
