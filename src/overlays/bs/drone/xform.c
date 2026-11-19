#include "common.h"

void func_80800000_bsdronexform(BtIntPtr arg0, s32 arg1, s32 arg2) {
    void func_800BA3FC(BtIntPtr arg0, s32 asset_id);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    extern s32 D_808011F0_bsdronexform[11];
    func_800BABB8(arg1, 0, 0, 1.0f, D_808011F0_bsdronexform);
    func_800BA3FC(arg1, arg2);
} typedef struct { u8 pad0[0x18C]; union { void * unk18C; s32 * unk18C_s32p; }; } Objxform_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void func_80800050_bsdronexform(void *arg0, BtIntPtr arg1, f32 arg2, f32 arg3) {
    void func_800BA7C4(void *, f32, f32);
    void func_800BA930(BtIntPtr, s16, s16, s16, s16, s16, s16);
    f32 temp_f0;
    s32 temp_f10;
    s32 temp_f6;

    temp_f6 = (s32) (arg2 * 30.0f);
    temp_f10 = (s32) (arg3 * 30.0f);
    func_800BA930(arg1, (s16) temp_f6, 0xA, (s16) temp_f10, (s16) temp_f6, 0xA, (s16) temp_f10);
    temp_f0 = (*(f32 *)((s8 *)((((Objxform_arg0 *)arg0)->unk18C)) + (0x14)));
    func_800BA7C4(arg1, temp_f0, temp_f0);
}

s32 func_808000E4_bsdronexform(void *arg0) {
    f32 func_80013788(void);
    f32 func_800137F4(f32);
    f32 func_800138D0(f32);
    f32 func_80013970(f32);
    void func_8008FE68(f32 *);
    void func_800BA22C(BtIntPtr, s32);
    void func_800BA75C(BtIntPtr, f32[3]);
    f32 func_800F0F9C(f32, f32);
    f32 func_800F1214(f32, f32, f32);
    f32 func_800F13C4(f32, f32);
    f32 angle;
    f32 phase;
    f32 cosine;
    f32 sine;
    f32 time;
    f32 pos[3];

    func_8008FE68(pos);
    time = *(f32 *)((u8 *)*&((Objxform_arg0 *)arg0)->unk18C + 8);
    phase = func_800F0F9C(time, 0.38f);
    sine = func_800137F4(360.0f * phase);
    cosine = func_80013788();
    pos[0] += sine * *(f32 *)((u8 *)*&((Objxform_arg0 *)arg0)->unk18C + 0x18);
    pos[1] += func_800F1214(func_800F0F9C(time, 1.14f), 0.0f, 130.0f);
    pos[2] += cosine * *(f32 *)((u8 *)*&((Objxform_arg0 *)arg0)->unk18C + 0x18);
    func_80800050_bsdronexform(arg0, (((Objxform_arg0 *)arg0)->unk18C_s32p)[1], sine, cosine);
    func_800BA75C((((Objxform_arg0 *)arg0)->unk18C_s32p)[1], pos);
    func_800BA22C((((Objxform_arg0 *)arg0)->unk18C_s32p)[1], 1);
    func_8008FE68(pos);
    angle = (1.0f - func_800F13C4(phase + 0.5f, 1.0f)) * 360.0f;
    pos[0] -= func_80013970(angle) * *(f32 *)((u8 *)*&((Objxform_arg0 *)arg0)->unk18C + 0x18);
    pos[1] += func_800F1214(func_800F0F9C(time, 1.14f), 130.0f, 0.0f);
    pos[2] -= func_800138D0(angle) * *(f32 *)((u8 *)*&((Objxform_arg0 *)arg0)->unk18C + 0x18);
    func_80800050_bsdronexform(arg0, (((Objxform_arg0 *)arg0)->unk18C_s32p)[0], sine, cosine);
    func_800BA75C((((Objxform_arg0 *)arg0)->unk18C_s32p)[0], pos);
    func_800BA22C((((Objxform_arg0 *)arg0)->unk18C_s32p)[0], 1); BT_NATIVE_ONLY(return 0;)
}

/* extern */

void func_808002CC_bsdronexform(void *arg0) {
    void func_800B5450(void *arg0);
    func_800B5450((*(s32 *)((s8 *)((((Objxform_arg0 *)arg0)->unk18C_s32p)) + (4))));
    func_800B5450(*(((Objxform_arg0 *)arg0)->unk18C_s32p));
}

/* extern */

void func_80800304_bsdronexform(void *arg0) {
    BtIntPtr func_800B53A4(s32);
    (*(s32 *)((s8 *)((((Objxform_arg0 *)arg0)->unk18C)) + (0))) = func_800B53A4(0x32);
    func_80800000_bsdronexform((BtIntPtr) arg0, (*(s32 *)((s8 *)((((Objxform_arg0 *)arg0)->unk18C)) + (0))), 0x6F7);
    (*(s32 *)((s8 *)((((Objxform_arg0 *)arg0)->unk18C)) + (4))) = func_800B53A4(0x32);
    func_80800000_bsdronexform((BtIntPtr) arg0, (*(s32 *)((s8 *)((((Objxform_arg0 *)arg0)->unk18C)) + (4))), 0x6F8);
    (*(f32 *)((s8 *)((((Objxform_arg0 *)arg0)->unk18C)) + (0x10))) = 0.0f;
    (*(f32 *)((s8 *)((((Objxform_arg0 *)arg0)->unk18C)) + (8))) = 0.0f;
    (*(f32 *)((s8 *)((((Objxform_arg0 *)arg0)->unk18C)) + (0xC))) = 1.0f;
    (*(f32 *)((s8 *)((((Objxform_arg0 *)arg0)->unk18C)) + (0x18))) = 55.0f;
    (*(f32 *)((s8 *)((((Objxform_arg0 *)arg0)->unk18C)) + (0x14))) = 0.35f;
    (*(s8 *)((s8 *)((((Objxform_arg0 *)arg0)->unk18C)) + (0x1C))) = 0;
}

void func_808003BC_bsdronexform(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*&((Objxform_arg0 *)arg0)->unk18C + 12) = arg1;
}

void func_808003CC_bsdronexform(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*&((Objxform_arg0 *)arg0)->unk18C + 24) = arg1;
}

void func_808003DC_bsdronexform(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*&((Objxform_arg0 *)arg0)->unk18C + 20) = arg1;
}

void func_808003EC_bsdronexform(BtIntPtr arg0, f32 arg1[3]) {
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    extern s32 D_8080121C_bsdronexform[11];
    extern s32 D_80801248_bsdronexform[11];
    extern s32 D_80801274_bsdronexform[17];
    extern s32 D_808012B8_bsdronexform[6];
    extern s32 D_808012D0_bsdronexform[8];
    extern s32 D_808012F0_bsdronexform[17];
    extern s32 D_80801334_bsdronexform[6];
    extern s32 D_8080134C_bsdronexform[9];
    func_800BABB8(0, arg1, 0, 1.0f, D_8080121C_bsdronexform);
    func_800BABB8(0, arg1, 0, 1.0f, D_80801248_bsdronexform);
    func_800BABB8(func_800BABB8(func_800BABB8(0, arg1, 0, 1.0f, D_80801274_bsdronexform), arg1, 0, 1.0f, D_808012B8_bsdronexform), arg1, 0, 1.0f, D_808012D0_bsdronexform);
    func_800BABB8(func_800BABB8(func_800BABB8(0, arg1, 0, 1.0f, D_808012F0_bsdronexform), arg1, 0, 1.0f, D_80801334_bsdronexform), arg1, 0, 1.0f, D_8080134C_bsdronexform);
}    typedef struct { u8 pad0[0x8]; f32 unk8; f32 unkC; f32 unk10; } Objxform_func_8080051C_bsdronexform_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

void func_8080051C_bsdronexform(void *arg0) {
    f32 func_800D8FF8(void);
    s32 func_808000E4_bsdronexform(void *);
    f32 delta;
    void *temp_v0;

    delta = func_800D8FF8();
    temp_v0 = (((Objxform_arg0 *)arg0)->unk18C);
    (((Objxform_func_8080051C_bsdronexform_temp_v0 *)temp_v0)->unk10) = (f32) ((((Objxform_func_8080051C_bsdronexform_temp_v0 *)temp_v0)->unk10) - delta);
    if ((*(f32 *)((s8 *)((((Objxform_arg0 *)arg0)->unk18C)) + (0x10))) < 0.0f) {
        do {
            func_808000E4_bsdronexform(arg0);
            temp_v0 = (((Objxform_arg0 *)arg0)->unk18C);
            (((Objxform_func_8080051C_bsdronexform_temp_v0 *)temp_v0)->unk8) += 0.017f * (((Objxform_func_8080051C_bsdronexform_temp_v0 *)temp_v0)->unkC);
            temp_v0 = (((Objxform_arg0 *)arg0)->unk18C);
            (((Objxform_func_8080051C_bsdronexform_temp_v0 *)temp_v0)->unk10) += 0.017f;
        } while ((*(f32 *)((s8 *)((((Objxform_arg0 *)arg0)->unk18C)) + (0x10))) < 0.0f);
    }
}

/* extern */

void bsdronexform_entrypoint_0(s32 *arg0, s32 arg1) {
    void func_800DFF64(s32 *, s32, f32 *);
    f32 func_800F1074(f32, f32);
    struct player_state_s *func_800F53D0(BtIntPtr);
    f32 values[3];
    struct player_state_s *self;

    self = func_800F53D0(arg1);
    arg1 = 0;
    do {
        values[arg1] = (*(f32 **)((s8 *)self + 0x18C))[9] + ((*(f32 **)((s8 *)self + 0x18C))[9] * (*(f32 **)((s8 *)self + 0x18C))[10]) * func_800F1074((*(f32 **)((s8 *)self + 0x18C))[8] + ((f32)arg1 / 3.0f) * 0.5f, 0.5f);
        arg1++;
    } while (arg1 != 3);
    func_800DFF64(arg0, 3, values);
}

void func_8080069C_bsdronexform(BtIntPtr arg0)
{
    func_8008C9D8(arg0,0);
}

#ifndef BT_NATIVE
extern void _bsdronexform_entrypoint_0(s32, s32);
#endif
void func_808006BC_bsdronexform(void *arg0) {
    *(f32 *)((u8 *)*&((Objxform_arg0 *)arg0)->unk18C + 32) = 0.0f;
    *(f32 *)((u8 *)*&((Objxform_arg0 *)arg0)->unk18C + 36) = 1.0f;
    *(f32 *)((u8 *)*&((Objxform_arg0 *)arg0)->unk18C + 40) = 0.0f;
    func_8008C9D8(arg0, _bsdronexform_entrypoint_0);
}

void func_80800704_bsdronexform(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*&((Objxform_arg0 *)arg0)->unk18C + 40) = arg1;
}

void func_80800714_bsdronexform(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*&((Objxform_arg0 *)arg0)->unk18C + 36) = arg1;
}    typedef struct { u8 pad0[0x18C]; void * unk18C; } Objxform_func_80800724_bsdronexform_arg0_copy; /* offsets.py genstruct: fields from raw offsets on arg0_copy; rename once understood */

void func_80800724_bsdronexform(void *arg0) {
    f32 func_800D8FF8();
    void *arg0_copy;
    f32 temp_f0;

    arg0_copy = arg0;
    temp_f0 = func_800D8FF8();
    (*(f32 *)((s8 *)(((Objxform_func_80800724_bsdronexform_arg0_copy *)arg0_copy)->unk18C) + 0x20)) = temp_f0 + (*(f32 *)((s8 *)(((Objxform_func_80800724_bsdronexform_arg0_copy *)arg0_copy)->unk18C) + 0x20));
}

void func_80800758_bsdronexform(void *arg0, s32 arg1) {
    struct player_state_s;
    void _badata_entrypoint_5(struct player_state_s *, s32 *, f32 *);
    void _batimer_set(struct player_state_s *, s32, f32);
    void baphysics_set_type(void *self, s32 type);
    void func_80092778(struct player_state_s *);
    void func_8009C128(struct player_state_s *, f32 *);
    f32 func_8009C150(struct player_state_s *);
    void func_8009DE38(struct player_state_s *, s32, f32);
    void func_8009DF18(struct player_state_s *, s32, f32, s32);
    s32 func_800A3274();
    u32 func_800A33F8(void *);
    void func_800A3410(struct player_state_s *, s32);
    f32 *func_800A4C48(struct player_state_s *);
    void func_800CA3F4(f32 *, f32 *, f32);
    void func_800D5034(s32 arg0, s32 arg1);
    s32 func_800E1610(s32, f32, f32, f32 *);
    void baanim_playForDuration_loopSmooth(void *, s32, f32);
    s32 animation;
    f32 duration;
    f32 position[3];

    *(s8 *)((u8 *)*&((Objxform_arg0 *)arg0)->unk18C + 0x32) = arg1;
    switch (arg1) {
    case 1:
        *(s8 *)((u8 *)*&((Objxform_arg0 *)arg0)->unk18C + 0x1C) = 1;
        *(f32 *)((u8 *)*&((Objxform_arg0 *)arg0)->unk18C + 0x2C) = func_8009C150(arg0);
        func_808003BC_bsdronexform(arg0, 0.28f);
        func_808003CC_bsdronexform(arg0, 180.0f);
        func_808003DC_bsdronexform(arg0, 0.04f);
        func_80800704_bsdronexform(arg0, 0.05f);
        baphysics_set_type(arg0, 7);
        _batimer_set(arg0, 0, 2.8f);
        func_8009DF18(arg0, 0x5D2, 1.0f, 20000);
        break;
    case 2:
        _batimer_set(arg0, 0, 0.5f);
        baphysics_set_type(arg0, 11);
        break;
    case 3:
        _batimer_set(arg0, 0, 0.05f);
        break;
    case 4:
        _batimer_set(arg0, 0, 0.8f);
        break;
    case 5:
        func_8009C128(arg0, position);
        position[1] += 30.0f;
        func_800CA3F4(func_800A4C48(arg0), position, 80.0f);
        func_808003EC_bsdronexform((BtIntPtr)arg0, position);
        _batimer_set(arg0, 0, 0.1f);
        break;
    case 6:
        func_8009C128(arg0, position);
        func_800E1610(2, 80.0f, 0.85f, position);
        func_8009DE38(arg0, 0x490, 1.0f);
        func_800D5034(func_800A3274(arg0), func_800A33F8(arg0));
        func_800A3410(arg0, func_800A33F8(arg0));
        func_80092778(arg0);
        _badata_entrypoint_5(arg0, &animation, &duration);
        baanim_playForDuration_loopSmooth(arg0, animation, duration);
        _batimer_set(arg0, 0, 0.1f);
        break;
    case 7:
        _batimer_set(arg0, 0, 0.8f);
        break;
    case 8:
        _batimer_set(arg0, 0, 1.0f);
        break;
    case 9:
        *(s8 *)((u8 *)*&((Objxform_arg0 *)arg0)->unk18C + 0x1C) = 0;
        _batimer_set(arg0, 0, 0.7f);
        baphysics_set_type(arg0, 7);
        break;
    }
}

/* extern */

void bsdronexform_entrypoint_1(BT_IDO_ONLY(void *) BT_NATIVE_ONLY(struct player_state_s *) arg0) {
    struct player_state_s;
    void _badronemem_entrypoint_1(void *arg0);
    void baflag_clear(struct player_state_s *, s32);
    void func_800961AC();
    void func_8009CEE8(void *);
    void func_800C59F0(s32, s32, s32);
    func_800961AC(arg0, 1);
    func_800C59F0(0xFF, 0xFF, 0xFF);
    func_808002CC_bsdronexform(arg0);
    func_8080069C_bsdronexform((BtIntPtr) arg0);
    func_8009CEE8(arg0);
    baflag_clear(arg0, 0x1B);
    _badronemem_entrypoint_1(arg0);
}

/* extern */

void bsdronexform_entrypoint_2(BT_IDO_ONLY(void *) BT_NATIVE_ONLY(struct player_state_s *) arg0) {
    struct player_state_s;
    void _badata_entrypoint_2(struct player_state_s *, s32 *, f32 *);
    void _badronemem_entrypoint_0(void *, s32);
    void baanim_playForDuration_loopSmooth(void *, s32, f32);
    void baflag_set(struct player_state_s *, s32);
    void baroll_setIdeal(struct player_state_s *, f32);
    void func_800961AC(struct player_state_s *, s32);
    void func_8009B94C(u8 *, f32 *);
    void func_8009BA9C(struct player_state_s *, f32 *);
    void func_8009BF5C(struct player_state_s *, f32);
    void func_8009FFD8(struct player_state_s *, s32, s32, s32, s32);
    s32 func_800A3274(struct player_state_s *);
    u32 func_800A33F8(void *);
    void func_80800758_bsdronexform(void *, s32);
    f32 sp2C;
    s32 sp28;

    _badronemem_entrypoint_0(arg0, 0x34);
    _badata_entrypoint_2(arg0, &sp28, &sp2C);
    baanim_playForDuration_loopSmooth(arg0, sp28, sp2C);
    func_8009FFD8(arg0, 1, 1, 3, 7);
    func_8009BA9C(arg0, 0);
    func_8009B94C(arg0, 0);
    func_8009BF5C(arg0, 0.0f);
    baroll_setIdeal(arg0, 0.0f);
    func_800961AC(arg0, 6);
    func_80800304_bsdronexform(arg0);
    func_808006BC_bsdronexform(arg0);
    (*(s8 *)((s8 *)((((Objxform_arg0 *)arg0)->unk18C)) + (0x31))) = func_800A3274(arg0);
    (*(s8 *)((s8 *)((((Objxform_arg0 *)arg0)->unk18C)) + (0x30))) = func_800A33F8(arg0);
    baflag_set(arg0, 0x1B);
    (*(s8 *)((s8 *)((((Objxform_arg0 *)arg0)->unk18C)) + (0x32))) = 0;
    func_80800758_bsdronexform(arg0, 1);
}

f32 func_80800B5C_bsdronexform(void *self, s32 id, f32 arg2, f32 arg3, f32 arg4) {
    f32 func_800F10B4(f32 value, f32 in_min, f32 in_max, f32 out_min, f32 out_max);
    f32 _batimer_get(void *, s32);
    return func_800F10B4(_batimer_get(self, id), arg2, 0.0f, arg3, arg4);
}

void bsdronexform_entrypoint_3(BT_IDO_ONLY(void *) BT_NATIVE_ONLY(struct player_state_s *) arg0)
{
  s32 _badata_entrypoint_34(void *);
  s32 _batimer_decrement(void *, s32);
  void bs_setState(void *self, s32 nextState);
  void func_8009C118(void *, f32);
  void func_800C59F0(s32, s32, s32);
  void func_8080051C_bsdronexform(void *);
  void func_80800758_bsdronexform(void *, s32);
  f32 func_80800B5C_bsdronexform(void *, s32, f32, f32, f32);
  s32 sp34;
  f32 sp30;
  f32 sp2C;
  f32 sp28;
  if ((*((u8 *) (((s8 *) (((Objxform_arg0 *)arg0)->unk18C)) + 0x1C))) != 0)
  {
    func_8080051C_bsdronexform(arg0);
  }
  func_80800724_bsdronexform(arg0);
  switch (*((u8 *) (((s8 *) (((Objxform_arg0 *)arg0)->unk18C)) + 0x32)))
  {
    case 1:
      sp34 = _batimer_decrement(arg0, 0);
      func_8009C118(arg0, (*((f32 *) (((u8 *) (((Objxform_arg0 *)arg0)->unk18C)) + 0x2C))) + func_80800B5C_bsdronexform(arg0, 0, 2.8f, 0.0f, 90.0f));
      func_808003BC_bsdronexform(arg0, func_80800B5C_bsdronexform(arg0, 0, 2.8f, 0.28f, 1.0f));
 func_808003CC_bsdronexform(arg0, func_80800B5C_bsdronexform(arg0, 0, 2.8f, 180.0f, 55.0f)); func_808003DC_bsdronexform(arg0, func_80800B5C_bsdronexform(arg0, 0, 2.8f, 0.04f, 0.35f)); func_80800714_bsdronexform(arg0, func_80800B5C_bsdronexform(arg0, 0, 2.8f, 1.0f, 0.8f)); func_80800704_bsdronexform(arg0, func_80800B5C_bsdronexform(arg0, 0, 2.8f, 0.05f, 0.4f)); sp28 = func_80800B5C_bsdronexform(arg0, 0, 2.8f, 255.0f, 200.0f); sp2C = func_80800B5C_bsdronexform(arg0, 0, 2.8f, 255.0f, 80.0f); sp30 = func_80800B5C_bsdronexform(arg0, 0, 2.8f, 255.0f, 80.0f); func_800C59F0((s32) sp28, (s32) sp2C, (s32) sp30); if (sp34 != 0) {
      func_80800758_bsdronexform(arg0, 2);
      return;
    }

    default:
      return;

    case 2:
      sp34 = _batimer_decrement(arg0, 0);
      func_80800704_bsdronexform(arg0, func_80800B5C_bsdronexform(arg0, 0, 0.5f, 0.4f, 0.6f));
      if (sp34 != 0)
    {
      func_80800758_bsdronexform(arg0, 3);
      return;
    }
      break;

    case 3:
      sp34 = _batimer_decrement(arg0, 0);
      func_80800714_bsdronexform(arg0, func_80800B5C_bsdronexform(arg0, 0, 0.05f, 0.8f, 1.2f));
      if (sp34 != 0)
    {
      func_80800758_bsdronexform(arg0, 4);
      return;
    }
      break;

    case 4:
      sp34 = _batimer_decrement(arg0, 0);
      func_80800714_bsdronexform(arg0, func_80800B5C_bsdronexform(arg0, 0, 0.8f, 1.2f, 0.09f));
      if (sp34 != 0)
    {
      func_80800758_bsdronexform(arg0, 5);
      return;
    }
      break;

    case 5:
      if (_batimer_decrement(arg0, 0) != 0)
    {
      func_80800758_bsdronexform(arg0, 6);
      return;
    }
      break;

    case 6:
      if (_batimer_decrement(arg0, 0) != 0)
    {
      func_80800758_bsdronexform(arg0, 7);
      return;
    }
      break;

    case 7:
      sp34 = _batimer_decrement(arg0, 0);
      func_80800714_bsdronexform(arg0, func_80800B5C_bsdronexform(arg0, 0, 0.8f, 0.09f, 1.0f));
      if (sp34 != 0)
    {
      func_80800758_bsdronexform(arg0, 8);
      return;
    }
      break;

    case 8:
      func_808003DC_bsdronexform(arg0, func_80800B5C_bsdronexform(arg0, 0, 1.0f, 0.35f, 0.03f));
      func_80800704_bsdronexform(arg0, func_80800B5C_bsdronexform(arg0, 0, 1.0f, 0.6f, 0.05f));
      sp28 = func_80800B5C_bsdronexform(arg0, 0, 1.0f, 200.0f, 255.0f);
      sp2C = func_80800B5C_bsdronexform(arg0, 0, 1.0f, 80.0f, 255.0f);
      sp30 = func_80800B5C_bsdronexform(arg0, 0, 1.0f, 80.0f, 255.0f);
      func_800C59F0((s32) sp28, (s32) sp2C, (s32) sp30);
      if (_batimer_decrement(arg0, 0) != 0)
    {
      func_80800758_bsdronexform(arg0, 9);
      return;
    }
      break;

    case 9:
      sp34 = _batimer_decrement(arg0, 0);
      func_8009C118(arg0, (*((f32 *) (((u8 *) (((Objxform_arg0 *)arg0)->unk18C)) + 0x2C))) + func_80800B5C_bsdronexform(arg0, 0, 0.7f, 90.0f, 0.0f));
      if (sp34 != 0)
    {
      bs_setState(arg0, _badata_entrypoint_34(arg0));
    }
      break;

  }

}
/* data_to_c.py: from asm/data/overlays/bs/drone/xform.data.s */
s32 D_808011F0_bsdronexform[11] BT_DATA(4, overlays_bs_drone_xform, 0x0) = { 2687003, -3211314, 1376358, 13369381, 458759, 2555904, 19660800, 19660843, 10879142, 1445888, 0 };
s32 D_8080121C_bsdronexform[11] BT_DATA(4, overlays_bs_drone_xform, 0x2C) = { 17825821, 163184661, 11731148, 1572864, 3072, 201326626, 53674803, 53674803, 2818252, 13369626, 0 };
s32 D_80801248_bsdronexform[11] BT_DATA(4, overlays_bs_drone_xform, 0x58) = { 17825821, 163053589, 1638604, 1572864, 3840, 251658274, 50332416, 50332416, 2818214, 10879258, 0 };
s32 D_80801274_bsdronexform[17] BT_DATA(4, overlays_bs_drone_xform, 0x84) = { 286261277, 165806124, -9830390, -9830250, 3276950, 1834958, -3276779, 153, 2228295, 5308423, 458791, 300, 300, 2818560, 33554454, 268437530, 0 };
s32 D_808012B8_bsdronexform[6] BT_DATA(4, overlays_bs_drone_xform, 0xC8) = { 2948820, 9895636, 19661000, 19660827, -9765014, 85590016 };
s32 D_808012D0_bsdronexform[8] BT_DATA(4, overlays_bs_drone_xform, 0xE0) = { 2949020, 720796, 6553615, 6553627, -45810364, 262246, 458755, 68812800 };
s32 D_808012F0_bsdronexform[17] BT_DATA(4, overlays_bs_drone_xform, 0x100) = { 286261277, 166002732, -3276740, -3276750, 9830450, 1834958, -3276779, 153, 2228295, 5308423, 458791, 300, 300, 2818560, 33554454, 268437530, 0 };
s32 D_80801334_bsdronexform[6] BT_DATA(4, overlays_bs_drone_xform, 0x144) = { 2948720, 9895536, 26214600, 26214427, -13041864, 85590016 };
s32 D_8080134C_bsdronexform[9] BT_DATA(4, overlays_bs_drone_xform, 0x15C) = { 2948920, 720696, 13107220, 13107227, -55640914, 262246, 458755, 68812800, 0 };
