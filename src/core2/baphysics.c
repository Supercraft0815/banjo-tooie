#include "overlays/ba/physics.h"

s32 func_8009AD70() 
{
    return 0xF;
}    typedef struct { u8 pad0[0xC4]; u8 * unkC4; u8 * unkC8; } Objbaphysics_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

s32 func_8009AD78(void *arg0, s32 arg1) {
    return (((Objbaphysics_arg0 *)arg0)->unkC4)[arg1];
}

void func_8009AD88(BtIntPtr arg0) 
{
}
#if defined(BT_NATIVE) && !defined(BT_ILP32)
void func_8009AD90(u8 *arg0) {
    bzero(((PlayerState *)arg0)->physics_flags, 15);
}
#else
void func_8009AD90(u8 *arg0) {
    s32 var_v0;
    var_v0 = 3;
    (*(s8 *)((s8 *)((((Objbaphysics_arg0 *)arg0)->unkC4)) + (0))) = 0;
    (*(s8 *)((s8 *)((((Objbaphysics_arg0 *)arg0)->unkC4)) + (1))) = 0;
    (*(s8 *)((s8 *)((((Objbaphysics_arg0 *)arg0)->unkC4)) + (2))) = 0;
    do {
        *((((Objbaphysics_arg0 *)arg0)->unkC4) + var_v0) = 0;
        (*(s8 *)((s8 *)(((((Objbaphysics_arg0 *)arg0)->unkC4) + var_v0)) + (1))) = 0;
        (*(s8 *)((s8 *)(((((Objbaphysics_arg0 *)arg0)->unkC4) + var_v0)) + (2))) = 0;
        (((Objbaphysics_arg0 *)arg0)->unkC4)[var_v0 + 3] = 0;
        var_v0 += 4;
    } while (var_v0 != 0xF);
}

#endif

void func_8009ADF0(void *arg0, s32 arg1, s32 arg2) {
    (*(u8 **)((u8 *)arg0 + 0xC4))[arg1] = arg2;
}

s32 func_8009AE00() 
{
    return 0xC4;
}

void func_8009AE08(PlayerState *arg0)
{
  int func_8008E1C4(PlayerState *);
  f32 func_80094E98(PlayerState *);
  void func_800963C0(PlayerState *, f32 *);
  u32 func_80096518(PlayerState *);
  f32 func_800A3378(void *);
  f32 func_800D8FF8(void);
  void func_800EE7F8(f32 *, f32 *);
  f32 func_800EEAA4(f32 *, f32 *);
  void func_800EEB9C(f32 *, f32, f32);
  void func_800EF04C(f32 *, f32 *);
  void func_800EF334(f32 *, f32);
  void func_800EF3DC(f32 *, f32 *);
  void func_800EF410(f32 *, f32 *);
  void func_800EFA20(void *, void *, f32);
  f32 func_800F10B4(f32, f32, f32, f32, f32);
  s32 func_800F2168(u8 *, s32);
  extern f32 D_801252A0;
  f32 sp7C[3];
  f32 sp70[3];
  f32 sp64[3];
  f32 sp58[3];
  f32 sp4C[3];
  f32 sp40[3];
  f32 sp3C;
  f32 sp38;
  u8 *p;
  f32 new_var;
  p = *((u8 **) (((u8 *) arg0) + 0xC8));
  func_800EEB9C((f32 *) (p + 0x1C), *((f32 *) (p + 0x40)), (*((f32 *) (p + 0x50))) * (*((f32 *) (p + 0x3C))));
  sp64[0] = *((f32 *) ((*((u8 **) (((u8 *) arg0) + 0xC8))) + 0x10));
  sp64[1] = 0.0f;
  sp64[2] = *((f32 *) ((*((u8 **) (((u8 *) arg0) + 0xC8))) + 0x18));
  func_800EE7F8(sp58, (f32 *) ((*((u8 **) (((u8 *) arg0) + 0xC8))) + 0x1C));
  sp58[1] = 0.0f;
  if (func_80096518(arg0))
  {
    func_800963C0(arg0, sp4C);
    func_800EF410(sp40, sp58);
    sp3C = func_800EEAA4(sp40, sp4C);
    sp38 = func_800A3378(arg0);
    if (sp3C != 0.0f)
    {
      if (sp3C < 0.0f)
      {
        if (func_8008E1C4(arg0))
        {
          sp38 = func_800F10B4(sp38, 0.0f, 1.0f, sp3C * 0.5f, -1.0f);
        }
        else
        {
          sp38 = sp3C * 0.5f;
        }
        func_800EF334(sp58, 1.0f + sp38);
      }
      else
      {
        new_var = sp3C * 0.2f;
        func_800EF334(sp58, 1.0f + new_var);
      }
    }
  }
  func_800EFA20(sp7C, sp58, func_80094E98(arg0));
  func_800EFA20(sp70, sp64, func_80094E98(arg0));
  func_800EF3DC(sp7C, sp70);
  func_800EF334(sp7C, func_800D8FF8() * 30.0f);
  func_800EF04C((f32 *) ((*((u8 **) (((u8 *) arg0) + 0xC8))) + 0x10), sp7C);
  sp38 = func_800D8FF8();
  p = *((u8 **) (((u8 *) arg0) + 0xC8));
  *((f32 *) (p + 0x14)) += (*((f32 *) (p + 0x34))) * sp38;
  p = *((u8 **) (((u8 *) arg0) + 0xC8));
  if ((*((f32 *) (p + 0x14))) < (*((f32 *) (p + 0x38))))
  {
    *((f32 *) (p + 0x14)) = *((f32 *) (p + 0x38));
  }
  sp38 = func_800D8FF8();
  p = *((u8 **) (((u8 *) arg0) + 0xC8));
  func_800EFA20(p + 0x28, p + 0x10, sp38);
  p = *((u8 **) (((u8 *) arg0) + 0xC8));
  func_800EF04C((f32 *) (p + 4), (f32 *) (p + 0x28));
  func_800F2168((*((u8 **) (((u8 *) arg0) + 0xC8))) + 0x10, 0x38D1B717);
}

void func_8009B08C(u8 *arg0) {
    f32 func_800D8FF8(void);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    void func_800EFA20(void *, void *, f32);
    void func_800EFB24(void *, void *, void *);
    f32 sp2C[3];
    f32 sp28;
    u8 *temp_v0;

    sp28 = func_800D8FF8();
    temp_v0 = *(u8 **)(arg0 + 0xC8);
    func_800EFB24(sp2C, temp_v0 + 0x1C, temp_v0 + 0x10);
    func_800EF334(sp2C, *(f32 *)(*(u8 **)(arg0 + 0xC8) + 0x44) * sp28);
    if ((sp2C[0] * sp2C[0] + sp2C[1] * sp2C[1]) + sp2C[2] * sp2C[2] < 0.02f) {
        temp_v0 = *(u8 **)(arg0 + 0xC8);
        func_800EE7F8((f32 *)(temp_v0 + 0x10), (f32 *)(temp_v0 + 0x1C));
    } else {
        func_800EF04C((f32 *)(*(u8 **)(arg0 + 0xC8) + 0x10), sp2C);
    }
    temp_v0 = *(u8 **)(arg0 + 0xC8);
    func_800EFA20(temp_v0 + 0x28, temp_v0 + 0x10, sp28);
    temp_v0 = *(u8 **)(arg0 + 0xC8);
    func_800EF04C((f32 *)(temp_v0 + 4), (f32 *)(temp_v0 + 0x28));
}    typedef struct { u8 pad0[0x14]; f32 unk14; u8 pad18[0x1C]; f32 unk34; f32 unk38; } Objbaphysics_func_8009B170_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

void func_8009B170(u8 *arg0) {
    f32 func_800D8FF8(void);
    void func_800EF04C(f32 *, f32 *);
    void func_800EFA20(void *, void *, f32);
    f32 temp_f0;
    f32 temp_f2;
    u8 *temp_v0;

    temp_f0 = func_800D8FF8();
    temp_v0 = (*(u8 **)((s8 *)(arg0) + (0xC8)));
    (((Objbaphysics_func_8009B170_temp_v0 *)temp_v0)->unk14) += (((Objbaphysics_func_8009B170_temp_v0 *)temp_v0)->unk34) * temp_f0;
    temp_v0 = (*(u8 **)((s8 *)(arg0) + (0xC8)));
    temp_f2 = (((Objbaphysics_func_8009B170_temp_v0 *)temp_v0)->unk38);
    if ((((Objbaphysics_func_8009B170_temp_v0 *)temp_v0)->unk14) < temp_f2) {
        (((Objbaphysics_func_8009B170_temp_v0 *)temp_v0)->unk14) = temp_f2;
        temp_v0 = (*(u8 **)((s8 *)(arg0) + (0xC8)));
    }
    func_800EFA20(temp_v0 + 0x28, temp_v0 + 0x10, temp_f0);
    temp_v0 = (*(u8 **)((s8 *)(arg0) + (0xC8)));
    func_800EF04C((f32 *)(temp_v0 + 4), (f32 *)(temp_v0 + 0x28));
}    typedef struct { u8 pad0[0x8]; f32 unk8; u8 padC[0x8]; f32 unk14; u8 pad18[0x14]; f32 unk2C; u8 pad30[0x4]; f32 unk34; f32 unk38; } Objbaphysics_func_8009B1FC_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

void func_8009B1FC(void *arg0) {
    f32 func_800D8FF8(void);
    f32 temp_f0;
    f32 temp_f12;
    f32 var_f2;
    void *temp_v0;

    temp_f0 = func_800D8FF8();
    temp_v0 = (*(void **)((s8 *)(arg0) + (0xC8)));
    (((Objbaphysics_func_8009B1FC_temp_v0 *)temp_v0)->unk14) += (((Objbaphysics_func_8009B1FC_temp_v0 *)temp_v0)->unk34) * temp_f0;
    temp_v0 = (*(void **)((s8 *)(arg0) + (0xC8)));
    var_f2 = (((Objbaphysics_func_8009B1FC_temp_v0 *)temp_v0)->unk14);
    temp_f12 = (((Objbaphysics_func_8009B1FC_temp_v0 *)temp_v0)->unk38);
    if (var_f2 < temp_f12) {
        (((Objbaphysics_func_8009B1FC_temp_v0 *)temp_v0)->unk14) = temp_f12;
        temp_v0 = (*(void **)((s8 *)(arg0) + (0xC8)));
        var_f2 = (((Objbaphysics_func_8009B1FC_temp_v0 *)temp_v0)->unk14);
    }
    (((Objbaphysics_func_8009B1FC_temp_v0 *)temp_v0)->unk2C) = var_f2 * temp_f0;
    temp_v0 = (*(void **)((s8 *)(arg0) + (0xC8)));
    (((Objbaphysics_func_8009B1FC_temp_v0 *)temp_v0)->unk8) += (((Objbaphysics_func_8009B1FC_temp_v0 *)temp_v0)->unk2C);
}

void func_8009B27C(void *arg0) {
    f32 func_800136E4(f32);
    void func_80098590(f32 **, f32 *);
    f32 func_80098610(void **);
    u32 func_8009861C(void *);
    f32 func_80098628(void *);
    void func_800EEB9C(f32[3], f32, f32);
    f32 sp3C[3];
    f32 sp30[3];
    f32 unused;
    f32 temp_f2;
    u8 *temp_v0;

    func_80098590(arg0, sp30);
    *(f32 *)(*(u8 **)((u8 *)arg0 + 0xC8) + 4) = sp30[0];
    *(f32 *)(*(u8 **)((u8 *)arg0 + 0xC8) + 0xC) = sp30[2];
    if (func_8009861C(arg0) == 2) {
        temp_f2 = func_800136E4(func_80098610(arg0) + 180.0f);
        func_800EEB9C(sp3C, temp_f2, -func_80098628(arg0));
    } else {
        temp_f2 = yaw_get(arg0);
        func_800EEB9C(sp3C, temp_f2, -func_80098628(arg0));
    }
    temp_v0 = *(u8 **)((u8 *)arg0 + 0xC8);
    *(f32 *)(temp_v0 + 4) += sp3C[0];
    temp_v0 = *(u8 **)((u8 *)arg0 + 0xC8);
    *(f32 *)(temp_v0 + 8) += sp3C[1];
    temp_v0 = *(u8 **)((u8 *)arg0 + 0xC8);
    *(f32 *)(temp_v0 + 0xC) += sp3C[2];
    *(f32 *)(*(u8 **)((u8 *)arg0 + 0xC8) + 0x18) = 0.0f;
    temp_v0 = *(u8 **)((u8 *)arg0 + 0xC8);
    temp_f2 = *(f32 *)(temp_v0 + 0x18);
    *(f32 *)(temp_v0 + 0x10) = temp_f2;
    *(f32 *)(*(u8 **)((u8 *)arg0 + 0xC8) + 0x24) = temp_f2;
    *(f32 *)(*(u8 **)((u8 *)arg0 + 0xC8) + 0x1C) = temp_f2;
    func_8009B08C(arg0);
}

void func_8009B3B8(u8 *arg0) {
    f32 func_800D8FF8(void);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF04C(f32[3], f32[3]);
    void func_800EF334(f32 vec[3], f32 scale);

    func_800EE7F8((((PlayerState *)arg0)->unkC8) + 0x28, (((PlayerState *)arg0)->unkC8) + 0x10);
    func_800EF334((((PlayerState *)arg0)->unkC8) + 0x28, func_800D8FF8());
    func_800EF04C((((PlayerState *)arg0)->unkC8) + 4, (((PlayerState *)arg0)->unkC8) + 0x28);
}

void func_8009B414(PlayerState *arg0) {
    void func_8009C128(PlayerState *, f32[3]);
    void func_800EFB24(void *, void *, void *);
    f32 sp1C[3];
    BtIntPtr temp_v0;

    func_8009C128(arg0, sp1C);
    temp_v0 = arg0->unkC8;
    func_800EFB24(temp_v0 + 0x28, temp_v0 + 4, sp1C);
}    typedef struct { u8 pad0[0x8]; f32 unk8; u8 padC[0x3C]; f32 unk48; f32 unk4C; } Objbaphysics_func_8009B450_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void func_8009B450(void *arg0) {
    f32 func_80013970(f32);
    f32 func_800D8FF8(void);
    f32 func_800F0F9C(f32, f32);
    void *temp_v0;
    f32 temp_f0;

    temp_f0 = func_800D8FF8();
    temp_v0 = (*(void **)((s8 *)(arg0) + (0xC8)));
    (((Objbaphysics_func_8009B450_temp_v0 *)temp_v0)->unk4C) += temp_f0;
    temp_f0 = func_800F0F9C((*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xC8)))) + (0x4C))), 1.2f);
    temp_f0 *= 360.0f;
    temp_f0 = func_80013970(temp_f0);
    temp_f0 *= 5.0f;
    temp_v0 = (*(void **)((s8 *)(arg0) + (0xC8)));
    (((Objbaphysics_func_8009B450_temp_v0 *)temp_v0)->unk8) = temp_f0;
    (((Objbaphysics_func_8009B450_temp_v0 *)temp_v0)->unk8) += (((Objbaphysics_func_8009B450_temp_v0 *)temp_v0)->unk48);
}

void func_8009B4D0(void *arg0, BtIntPtr arg1) {
    void func_800EE7F8(f32 *, f32 *);
    func_800EE7F8(arg1, ((PlayerState *)arg0)->unkC8 + 0x28);
}

void func_8009B4FC(PlayerState *arg0) {
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800EFD24(f32 *);

    *(s32 *)(*(u8 **)((u8 *)arg0 + 0xC8)) = 0;
    *(f32 *)(*(u8 **)((u8 *)arg0 + 0xC8) + 0x50) = 1.0f;
    func_800EFA4C((f32 *)(*(u8 **)((u8 *)arg0 + 0xC8) + 0x10), 0.0f, -1.0f, 0.0f);
    func_800EFD24((f32 *)(*(u8 **)((u8 *)arg0 + 0xC8) + 0x1C));
    func_800EFD24((f32 *)(*(u8 **)((u8 *)arg0 + 0xC8) + 0x28));
    func_800EFD24((f32 *)(*(u8 **)((u8 *)arg0 + 0xC8) + 4));
    *(f32 *)(*(u8 **)((u8 *)arg0 + 0xC8) + 0x44) = 2.0f;
    func_8009BC34(arg0);
}

void func_8009B590(PlayerState *arg0) {
    void func_8009C128(PlayerState *, f32[3]);
    f32 func_800A3048(PlayerState *);
    f32 func_800136E4(f32);
    f32 bastick_distance(PlayerState *);
    f32 bastick_getAngleRelativeToBanjo(PlayerState *);
    void func_8009C0F8();
    void func_8009AE08(PlayerState *);
    void _bamovegoto_entrypoint_14(PlayerState *);
    void _bamoveledge_entrypoint_3(PlayerState *);
    void _bsfirstp_entrypoint_27(PlayerState *);
    void _bamovethrust_entrypoint_5(PlayerState *);
    void _bamovespline_entrypoint_10(PlayerState *);
    void _bamovehover_entrypoint_2(PlayerState *);
    f32 scale;

    func_8009C128(arg0, (f32 *)(*(u8 **)((u8 *)arg0 + 0xC8) + 4));
    scale = func_800A3048(arg0);
    *(f32 *)(*(u8 **)((u8 *)arg0 + 0xC8) + 0x50) *= scale;
    switch (*(s32 *)(*(u8 **)((u8 *)arg0 + 0xC8))) {
        case 0:
            break;
        case 12:
            _bamovegoto_entrypoint_14(arg0);
            break;
        case 11:
            func_8009B450(arg0);
            break;
        case 8:
            func_8009B3B8((u8 *)arg0);
            break;
        case 1:
            func_8009B170((u8 *)arg0);
            break;
        case 9:
            func_8009B08C((u8 *)arg0);
            break;
        case 2:
            baphysics_set_target_yaw(arg0, yaw_getIdeal(arg0));
            func_8009AE08(arg0);
            break;
        case 5:
            baphysics_set_target_yaw(arg0, func_800136E4(yaw_getIdeal(arg0) + 180.0f));
            func_8009AE08(arg0);
            break;
        case 3:
            func_8009AE08(arg0);
            break;
        case 13:
            _bamoveledge_entrypoint_3(arg0);
            break;
        case 6:
            if (bastick_distance(arg0) > 0.0f) {
                baphysics_set_target_yaw(arg0, bastick_getAngleRelativeToBanjo(arg0));
            }
            func_8009AE08(arg0);
            break;
        case 10:
            func_8009B27C(arg0);
            break;
        case 16:
            _bsfirstp_entrypoint_27(arg0);
            func_8009AE08(arg0);
            func_8009B414(arg0);
            break;
        case 17:
            _bsfirstp_entrypoint_27(arg0);
            func_8009B1FC(arg0);
            break;
        case 14:
            baphysics_set_target_yaw(arg0, yaw_get(arg0));
            func_8009AE08(arg0);
            break;
        case 15:
            _bamovethrust_entrypoint_5(arg0);
            break;
        case 18:
            _bamovespline_entrypoint_10(arg0);
            break;
        case 19:
            _bamovehover_entrypoint_2(arg0);
            break;
    }
    func_8009C0F8(arg0, (f32 *)(*(u8 **)((u8 *)arg0 + 0xC8) + 4));
    *(f32 *)(*(u8 **)((u8 *)arg0 + 0xC8) + 0x50) = 1.0f;
}    typedef struct { u8 pad0[0x10]; f32 unk10; u8 pad14[0x4]; f32 unk18; } Objbaphysics_func_8009B7C0_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void func_8009B7C0(PlayerState *arg0) {
    void *temp_v0;

    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xC8)))) + (0x18))) = 0.0f;
    temp_v0 = (*(void **)((s8 *)(arg0) + (0xC8)));
    (((Objbaphysics_func_8009B7C0_temp_v0 *)temp_v0)->unk10) = (f32) (((Objbaphysics_func_8009B7C0_temp_v0 *)temp_v0)->unk18);
}

void baphysics_set_type(PlayerState *self, BaPhysicsType type) {
    void _bamoveledge_entrypoint_1(BtIntPtr arg0);
    void _bamoveledge_entrypoint_2(BtIntPtr arg0);
    void _bamovethrust_entrypoint_0(BtIntPtr arg0);
    void _bamovethrust_entrypoint_1(PlayerState *);
    void _bamovegoto_entrypoint_5(PlayerState *);
    void _bamovegoto_entrypoint_6(PlayerState *);
    void _bamovespline_entrypoint_5(BtIntPtr arg0);
    void _bamovespline_entrypoint_6(PlayerState *);
    void _bamovehover_entrypoint_0(BtIntPtr arg0);
    void _bamovehover_entrypoint_1(PlayerState *);
    BaPhysicsType old_type;

    if ((old_type = *(BaPhysicsType *)*(void **)((s8 *)self + 0xC8)) == type) {
        return;
    }
    {
        switch (old_type) {
            case 13: _bamoveledge_entrypoint_1(self); break;
            case 15: _bamovethrust_entrypoint_0(self); break;
            case 12: _bamovegoto_entrypoint_5(self); break;
            case 18: _bamovespline_entrypoint_5(self); break;
            case 19: _bamovehover_entrypoint_0(self); break;
        }
        *(s32 *)*(void **)((s8 *)self + 0xC8) = type;
        switch (type) {
            case 12: _bamovegoto_entrypoint_6(self); break;
            case 13: _bamoveledge_entrypoint_2(self); break;
            case 11:
                if (old_type != type) {
                    *(f32 *)((s8 *)*(void **)((s8 *)self + 0xC8) + 0x48) =
                        *(f32 *)((s8 *)*(void **)((s8 *)self + 0xC8) + 8);
                    *(f32 *)((s8 *)*(void **)((s8 *)self + 0xC8) + 0x4C) = 0.0f;
                }
                break;
            case 15: _bamovethrust_entrypoint_1(self); break;
            case 18: _bamovespline_entrypoint_6(self); break;
            case 19: _bamovehover_entrypoint_1(self); break;
        }
    }
}

void func_8009B94C(u8 *arg0, f32 *arg1) {
    void func_800EE7F8();
    void func_800EFD24(f32 vec[3]);
    if (arg1 != 0) {
        func_800EE7F8((((PlayerState *)arg0)->unkC8) + 0x1C);
        return;
    }
    func_800EFD24((((PlayerState *)arg0)->unkC8) + 0x1C);
}

/* extern */

void func_8009B98C(void *arg0, f32 *arg1) {
    void func_800EE7F8(f32 *, f32 *);
    func_800EE7F8((f32 *)(((Objbaphysics_arg0 *)arg0)->unkC8 + 4), arg1);
}

void baphysics_set_target_horizontal_velocity(PlayerState *arg0, f32 vel) {
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xC8)))) + (0x3C))) = vel;
}

/* extern */

void baphysics_set_target_yaw(PlayerState *arg0, f32 target_yaw) {
    f32 func_800136E4(f32);
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xC8)))) + (0x40))) = func_800136E4(target_yaw);
}    typedef struct { u8 pad0[0x3C]; f32 unk3C; f32 unk40; } Objbaphysics_func_8009B9F0_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */ typedef struct { u8 pad0[0x10]; f32 unk10; u8 pad14[0x4]; f32 unk18; f32 unk1C; u8 pad20[0x4]; f32 unk24; } Objbaphysics_func_8009B9F0_temp_v0_2; /* offsets.py genstruct: fields from raw offsets on temp_v0_2; rename once understood */

/* extern */

void func_8009B9F0(PlayerState *arg0, f32 arg1) {
    void func_800EEB9C(f32[3], f32, f32);
    u8 *temp_v0;
    u8 *temp_v0_2;

    baphysics_set_target_horizontal_velocity(arg0, arg1);
    temp_v0 = (*(u8 **)((s8 *)(arg0) + (0xC8)));
    func_800EEB9C((f32 *)(temp_v0 + 0x1C), (((Objbaphysics_func_8009B9F0_temp_v0 *)temp_v0)->unk40), (((Objbaphysics_func_8009B9F0_temp_v0 *)temp_v0)->unk3C));
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0xC8)))) + (0x20))) = 0.0f;
    temp_v0_2 = (*(u8 **)((s8 *)(arg0) + (0xC8)));
    (((Objbaphysics_func_8009B9F0_temp_v0_2 *)temp_v0_2)->unk10) = (f32) (((Objbaphysics_func_8009B9F0_temp_v0_2 *)temp_v0_2)->unk1C);
    temp_v0_2 = (*(u8 **)((s8 *)(arg0) + (0xC8)));
    (((Objbaphysics_func_8009B9F0_temp_v0_2 *)temp_v0_2)->unk18) = (f32) (((Objbaphysics_func_8009B9F0_temp_v0_2 *)temp_v0_2)->unk24);
}

void baphysics_set_vertical_velocity(PlayerState *arg0, f32 arg1) {
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xC8)))) + (0x14))) = arg1;
}

void baphysics_set_horizontal_velocity(PlayerState *arg0, f32 yaw, f32 vel) {
    void func_800EEB9C(f32[3], f32, f32);
    func_800EEB9C((arg0->unkC8) + 0x10, yaw, vel);
}

void func_8009BA9C(PlayerState *arg0, f32 *arg1) {
    void func_800EE7F8();
    void func_800EFD24(f32 vec[3]);
    if (arg1 != NULL) {
        func_800EE7F8((arg0->unkC8) + 0x10);
        return;
    }
    func_800EFD24((arg0->unkC8) + 0x10);
}

f32 func_8009BADC(PlayerState *arg0) {
    return (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xC8)))) + (0x34)));
}

f32 func_8009BAE8(PlayerState *arg0) {
    return (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xC8)))) + (0x38)));
}

s32 func_8009BAF4(void *arg0) {
    return *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 200) + 0);
}

f32 baphysics_get_target_horizontal_velocity(PlayerState *arg0) {
    return (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xC8)))) + (0x3C)));
}

f32 func_8009BB0C(void *arg0) {
    return *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 200) + 32);
}

f32 func_8009BB18(void *arg0) {
    return *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 200) + 64);
}

/* Single line: IDO schedules this prologue by source line. */
#if defined(BT_NATIVE) && !defined(BT_ILP32)
void func_8009BB24(PlayerState *arg0, f32 arg1[3]) {
    void func_800EE7F8(f32 *, f32 *);
    func_800EE7F8(arg1, (f32 *)((u8 *)arg0->physics + 0x10));
}
#else
void func_8009BB24(PlayerState *arg0, f32 arg1[3]) { void func_800EE7F8(); func_800EE7F8(arg1, arg0->unkC8 + 0x10); }

#endif

f32 baphysics_get_vertical_velocity(PlayerState *arg0) {
    return (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xC8)))) + (0x14)));
}    typedef struct { u8 pad0[0x10]; f32 unk10; u8 pad14[0x4]; f32 unk18; } Objbaphysics_func_8009BB5C_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

f32 func_8009BB5C(PlayerState *arg0) {
    f32 temp_f0;
    f32 temp_f2;
    void *temp_v0;

    temp_v0 = (*(void **)((s8 *)(arg0) + (0xC8)));
    temp_f0 = (((Objbaphysics_func_8009BB5C_temp_v0 *)temp_v0)->unk18);
    temp_f2 = (((Objbaphysics_func_8009BB5C_temp_v0 *)temp_v0)->unk10);
    return sqrtf((temp_f0 * temp_f0) + (temp_f2 * temp_f2));
}

/* extern */

f32 func_8009BB94(PlayerState *arg0) {
    f32 func_800EEF94(f32 *);
    return func_800EEF94((f32 *)((s8 *)(*(void **)((s8 *)arg0 + 0xC8)) + 0x10));
}

f32 func_8009BBB8(PlayerState *arg0) {
    f32 sp1C;
    f32 temp_f0;
    f32 var_f12;

    sp1C = func_8009BB5C(arg0);
    temp_f0 = baphysics_get_target_horizontal_velocity(arg0);
    if (sp1C < temp_f0) {
        var_f12 = sp1C / temp_f0;
    } else {
        var_f12 = 1.0f;
    }
    return var_f12;
}

void func_8009BC08(void *arg0, f32 *arg1) {
    void func_800EE7F8();
    func_800EE7F8(arg1, *(s32 *)((u8 *)arg0 + 0xC8) + 0x4);
}

void func_8009BC34(PlayerState* arg0)
{
    baphysics_reset_gravity(arg0);
    baphysics_reset_terminal_velocity(arg0);
}
void func_8009BC5C(PlayerState *arg0, f32 arg1) {
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xC8)))) + (0x44))) = arg1;
}

void baphysics_reset_gravity(PlayerState *arg0) {
    extern f32 D_80117EF0;
    baphysics_set_gravity(arg0, D_80117EF0);
}

void baphysics_reset_terminal_velocity(PlayerState *arg0) {
    extern f32 D_80117EF4;
    baphysics_set_terminal_velocity(arg0, D_80117EF4);
}

void baphysics_set_gravity(PlayerState *arg0, f32 arg1) {
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xC8)))) + (0x34))) = arg1;
}

void baphysics_set_terminal_velocity(PlayerState *arg0, f32 arg1) {
    (*(f32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xC8)))) + (0x38))) = arg1;
}    typedef struct { u8 pad0[0x10]; f32 unk10; u8 pad14[0x4]; f32 unk18; } Objbaphysics_func_8009BCD4_temp_v1; /* offsets.py genstruct: fields from raw offsets on temp_v1; rename once understood */

s32 func_8009BCD4(PlayerState *arg0, f32 arg1) {
    f32 temp_f0;
    f32 temp_f2;
    f32 magnitude;
    u8 *temp_v1;

    temp_v1 = (*(u8 **)((s8 *)(arg0) + (0xC8)));
    temp_f0 = (((Objbaphysics_func_8009BCD4_temp_v1 *)temp_v1)->unk18);
    temp_f2 = (((Objbaphysics_func_8009BCD4_temp_v1 *)temp_v1)->unk10);
    magnitude = (temp_f0 * temp_f0) + (temp_f2 * temp_f2);
    return magnitude <= arg1 * arg1;
}

void func_8009BD18(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 200) + 80) = arg1;
}
