#include "common.h"
struct anctrl_s; 
#include "overlays/ba/playerstate.h"
void func_80800000_bssub(BtIntPtr arg0) {
    func_8009FFD8(arg0, 0x1, 0x3, 0x3, 0xF);
}

f32 func_80800030_bssub(f32 arg0, f32 arg1) {
    return arg1 * 300.0f;
}

f32 func_80800048_bssub(f32 arg0, f32 arg1) {
    return -arg1 * 428.57144f;
}

/* extern */

void func_80800064_bssub(BtIntPtr arg0) {
    void _basub_entrypoint_15(void *arg0, s32 arg1);
    s32 bs_setState(BtIntPtr, s32);
    void func_800995B8(void *arg0, s32 arg1);
    s32 func_80099A58(BtIntPtr);
    void func_80099B94(void *arg0);
    s32 func_8009E6EC();
    s32 func_8009E830(BtIntPtr, s32);
    s32 temp_v0;

    temp_v0 = func_8009E6EC();
    switch (temp_v0) {
        case 0x85:
            _basub_entrypoint_15(arg0, func_80099A58(arg0));
            break;
        case 0x2D:
            func_800995B8(arg0, 3);
            func_8009E830(arg0, 2);
            bs_setState(arg0, 0x46);
            break;
        default:
            func_80099B94(arg0);
            break;
    }
}

struct player_state_s;
void func_808000F0_bssub(struct player_state_s *arg0) {
    f32 _bafpctrl_entrypoint_3(struct player_state_s *);
    void baroll_setAngularVelocity(struct player_state_s *, f32, f32);
    f32 func_8009BB94(struct player_state_s *);
    void func_8009BFE4(struct player_state_s *, f32, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F1214(f32, f32, f32);
    s32 player_inWater(struct player_state_s *);
    void yaw_setVelocityBounded(struct player_state_s *, f32, f32);
    f32 temp_f0;
    f32 sp48;
    f32 temp_f20;
    f32 var_f22;

    temp_f20 = func_800F10B4(func_8009BB94(arg0), 0.0f, 225.0f, 0.0f, 1.0f);
    if (player_inWater(arg0) != 0) {
        var_f22 = func_800F1214(temp_f20, 50.0f, 150.0f);
        sp48 = func_800F1214(temp_f20, 0.5f, 2.0f);
        baroll_setAngularVelocity(arg0, func_800F1214(temp_f20, 40.0f, 150.0f), func_800F1214(temp_f20, 0.6f, 3.0f));
        yaw_setVelocityBounded(arg0, 250.0f, 20.0f);
    } else {
        var_f22 = 250.0;
        sp48 = 2.8f;
        baroll_setAngularVelocity(arg0, 250.0f, 2.8f);
        yaw_setVelocityBounded(arg0, 300.0f, 3.0f);
    }
    temp_f0 = _bafpctrl_entrypoint_3(arg0);
    var_f22 *= func_800F10B4(temp_f0, 0.1f, 1.0f, temp_f0 * temp_f0, 1.0f);
    func_8009BFE4(arg0, var_f22, sp48);
}

void func_80800254_bssub(void *arg0)
{
  void _bamovethrust_entrypoint_3(struct player_state_s *, f32);
  void _bamovethrust_entrypoint_4(struct player_state_s *, f32);
  void _basub_entrypoint_11(BtIntPtr, f32);
  void _basub_entrypoint_12(void *, f32);
  void _basub_entrypoint_13(BtIntPtr, f32);
  f32 _basub_entrypoint_2(void *);
  s32 bakey_held(BtIntPtr, s32);
  void baphysics_set_gravity(struct player_state_s *, f32);
  void baphysics_set_terminal_velocity(struct player_state_s *, f32);
  void func_800914FC(struct player_state_s *, f32, s32);
  void func_8009C128(struct player_state_s *, f32[3]);
  f32 func_8009BFD8(void *);
  f32 yaw_get(void *);
  f32 yaw_getIdeal(struct player_state_s *);
  s32 player_inWater(struct player_state_s *);
  s32 player_isStable(void *);
  BtIntPtr func_800B5BE4(s32);
  void func_800BA22C(BtIntPtr, s32);
  f32 func_800A3048(BtIntPtr);
  void func_800BA77C(BtIntPtr arg0, s16 x, s16 y, s16 z);
  BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
  f32 func_800D8FF8(void);
  f32 func_800DC178(f32, f32);
  f32 func_800F0D50(f32, f32, f32);
  f32 func_800F10B4(f32, f32, f32, f32, f32);
  f32 func_800F1344(f32, f32, f32, f32, f32);
  f32 func_800F1DCC(f32, f32);
  f32 mlAbsF(f32);
  void func_808000F0_bssub(struct player_state_s *arg0);
  extern s32 D_808016E0_bssub[19];
  f32 sp5C;
  f32 sp58;
  f32 sp54;
  f32 sp50;
  f32 sp4C;
  s32 sp48;
  f32 sp3C[3];
  BtIntPtr sp38;
  f32 rate;
  f32 padding;
  f32 idealYaw;
  sp54 = func_800A3048((BtIntPtr) arg0) * 90;
  sp4C = func_800D8FF8();
  sp48 = player_inWater(arg0);
  if (sp48 != 0)
  {
    baphysics_set_gravity(arg0, 0.0f);
    baphysics_set_terminal_velocity(arg0, -4000.0f);
    _bamovethrust_entrypoint_4(arg0, 0.9f);
    _bamovethrust_entrypoint_3(arg0, ((PlayerState *)arg0)->unk16C);
  }
  else
  {
    baphysics_set_gravity(arg0, -1800.0f);
    baphysics_set_terminal_velocity(arg0, -4000.0f);
    _bamovethrust_entrypoint_4(arg0, 0.95f);
    _bamovethrust_entrypoint_3(arg0, (((PlayerState *)arg0)->unk16C) * 0.25f);
  }
  if (bakey_held((BtIntPtr) arg0, 8) || (_basub_entrypoint_2(arg0) != 0.0f))
  {
    sp5C = func_80800030_bssub(((PlayerState *)arg0)->unk16C, sp4C);
  }
  else
  {
    sp5C = func_80800048_bssub(((PlayerState *)arg0)->unk16C, sp4C);
  }
  if (_basub_entrypoint_2(arg0))
  {
    ((PlayerState *)arg0)->unk16C = func_800F0D50((((PlayerState *)arg0)->unk16C) + sp5C, 0.0f, _basub_entrypoint_2(arg0));
  }
  else
  {
    ((PlayerState *)arg0)->unk16C = func_800F0D50((((PlayerState *)arg0)->unk16C) + sp5C, 0.0f, sp54);
  }
  _basub_entrypoint_13(arg0, func_800F10B4(((PlayerState *)arg0)->unk16C, 0.0f, sp54, 200.0f, 1350.0f));
  sp50 = func_800F10B4(((PlayerState *)arg0)->unk16C, 0.0f, sp54, 0.8f, 1.1f);
  idealYaw = yaw_getIdeal(arg0);
  sp58 = func_800F1DCC(idealYaw, yaw_get(arg0));
  sp58 = mlAbsF(sp58);
  sp58 = func_800F10B4(sp58 / sp4C, 0.0f, 128.0f, 0.0, -0.12f);
  sp50 += sp58;
  if (sp48 == 0)
  {
    sp50 += 0.7f;
  }
  _basub_entrypoint_11(arg0, sp50);
  sp58 = func_8009BFD8(arg0);
  if (sp58 > 180.0f)
  {
    sp58 -= 360.0f;
  }
  _basub_entrypoint_12(arg0, func_800F1344(sp58, 0.0f, 85.0f, 0.0f, 60.0f));
  if (sp48 != 0)
  {
    if (_basub_entrypoint_2(arg0) != 0.0f)
    {
      func_800914FC((struct player_state_s *)arg0, 60.0f, 1);
    }
    else
    {
      rate = func_800F10B4(((PlayerState *)arg0)->unk16C, 0.0f, sp54, func_800DC178(1.0f, 3.0f), 40.0f);
      func_800914FC((struct player_state_s *)arg0, rate, 0);
    }
  }
  else
    if (((((PlayerState *)arg0)->unk16C) > 0.0f) && player_isStable(arg0))
  {
    func_8009C128(arg0, sp3C);
    sp38 = func_800B5BE4(8);
    func_800BABB8(sp38, sp3C, 0, 1.0f, D_808016E0_bssub);
    func_800BA77C(sp38, 0, 0, (s16) ((s32) func_800DC178(0.0f, 359.0f)));
    func_800BA22C(sp38, 1);
  }
  func_808000F0_bssub(arg0);
}

struct player_state_s;
void func_80800634_bssub(struct player_state_s *arg0) {
    f32 _bafpctrl_entrypoint_3(struct player_state_s *);
    void baroll_setIdeal(struct player_state_s *, f32);
    f32 bastick_getX(struct player_state_s *);
    f32 func_8009BB94(struct player_state_s *);
    f32 func_800D8FF8(void);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    s32 player_inWater(struct player_state_s *);
    f32 yaw_getIdeal(struct player_state_s *);
    void yaw_setIdeal(struct player_state_s *, f32);
    f32 sp3C;
    f32 pad[2];
    f32 sp30;
    f32 sp2C;
    f32 temp_f0;
    f32 var_f2;

    sp2C = bastick_getX(arg0);
    sp30 = func_800D8FF8();
    temp_f0 = func_800F10B4(func_8009BB94(arg0), 0.0f, 225.0f, 11.25f, 45.0f);
    baroll_setIdeal(arg0, func_800F10B4(sp2C, -1.0f, 1.0f, -temp_f0, temp_f0));
    if (player_inWater(arg0) != 0) {
        var_f2 = func_800F10B4(func_8009BB94(arg0), 0.0f, 225.0f, 42.666668f, 128.0f);
    } else {
        var_f2 = 300.0f;
    }
    sp3C = func_800F10B4(sp2C, -1.0f, 1.0f, var_f2, -var_f2) * sp30;
    sp3C *= _bafpctrl_entrypoint_3(arg0);
    yaw_setIdeal(arg0, yaw_getIdeal(arg0) + sp3C);
}

/* extern */

struct player_state_s;
void func_80800768_bssub(struct player_state_s *arg0) {
    f32 bastick_getY(struct player_state_s *);
    void func_8009BF5C(struct player_state_s *, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    s32 player_inWater(struct player_state_s *);
    f32 temp_f0;
    f32 var_f2;
    f32 var_f16;

    if (player_inWater(arg0) != 0) {
        var_f2 = 275.0f;
        var_f16 = 85.0f;
    } else {
        var_f2 = 325.0f;
        var_f16 = 30.0f;
    }
    temp_f0 = bastick_getY(arg0);
    if (temp_f0 < 0.0f) {
        func_8009BF5C(arg0, func_800F10B4(temp_f0, -1.0f, 0.0f, var_f2, 360.0f));
        return;
    }
    func_8009BF5C(arg0, func_800F10B4(temp_f0, 0.0f, 1.0f, 0.0f, var_f16));
}

void func_80800834_bssub(struct player_state_s *arg0) {
    void _basub_entrypoint_1(struct player_state_s *);
    void _basub_entrypoint_3(struct player_state_s *, f32, f32);
    void _basub_entrypoint_5(struct player_state_s *);
    void _basub_entrypoint_8(struct player_state_s *, f32);
    int bakey_pressed(struct player_state_s *, int);
    f32 func_8009BB94(struct player_state_s *);
    s32 func_800EA068(s32);
    if (bakey_pressed(arg0, 2) != 0) {
        _basub_entrypoint_1(arg0);
    }
    if (bakey_pressed(arg0, 1) != 0) {
        _basub_entrypoint_8(arg0, func_8009BB94(arg0));
    }
    if (bakey_pressed(arg0, 9) != 0) {
        if (func_800EA068(0x40) != 0) {
            _basub_entrypoint_3(arg0, 160.0f, 1.0f);
            return;
        }
        _basub_entrypoint_5(arg0);
    }
}

/* extern */

void func_808008D8_bssub(struct player_state_s *arg0) {
    s32 _bafpctrl_entrypoint_18(struct player_state_s *, s32);
    s32 _basub_entrypoint_9(struct player_state_s *);
    void baroll_resetAngularVelocity(struct player_state_s *);
    void baroll_setIdeal(struct player_state_s *, f32);
    void bastick_resetZones(struct player_state_s *);
    void func_800910BC(struct player_state_s *, s32);
    void func_80092864(struct player_state_s *, f32);
    void func_80093360(struct player_state_s *, f32);
    void func_800947EC(struct player_state_s *, s32, s32);
    void func_80095964(void *, s32);
    void func_80095A40(struct player_state_s *);
    void func_800961AC(struct player_state_s *, s32);
    void func_8009BC34(struct player_state_s *);
    void func_8009BF5C(struct player_state_s *, f32);
    void func_8009C000(struct player_state_s *);
    void func_8009E474(struct player_state_s *);
    s32 func_8009E74C(struct player_state_s *, s32);
    if (func_8009E74C(arg0, 0xF) == 0) {
        func_800947EC(arg0, 1, 0);
        func_800961AC(arg0, 1);
        func_8009BC34(arg0);
        func_8009BF5C(arg0, 0.0f);
        baroll_setIdeal(arg0, 0.0f);
        func_8009C000(arg0);
        baroll_resetAngularVelocity(arg0);
        bastick_resetZones(arg0);
        func_80095A40(arg0);
        func_80095964(arg0, 0);
        func_80093360(arg0, 0.0f);
        _basub_entrypoint_9(arg0);
        func_800910BC(arg0, 1);
        _bafpctrl_entrypoint_18(arg0, 0);
        func_8009E474(arg0);
        func_80092864(arg0, 1.0f);
    }
}

void func_808009B0_bssub(struct player_state_s *arg0) {
    s32 _bafpctrl_entrypoint_18(struct player_state_s *, s32);
    s32 _basub_entrypoint_10(struct player_state_s *);
    void baphysics_set_gravity(struct player_state_s *, f32);
    void baphysics_set_terminal_velocity(struct player_state_s *, f32);
    void bastick_setZoneMax(struct player_state_s *, s32, f32);
    void func_800910BC(struct player_state_s *, s32);
    void func_80092864(struct player_state_s *, f32);
    void func_80093360(struct player_state_s *, f32);
    void func_800947EC(struct player_state_s *, s32, s32);
    void func_80095964(void *, s32);
    void func_800959C8(struct player_state_s *, f32, f32);
    void func_800961AC(struct player_state_s *, s32);
    void func_8009BC5C(struct player_state_s *, f32);
    void func_8009E4AC(struct player_state_s *);
    void func_8009E55C(struct player_state_s *, s32, f32);
    s32 func_8009E77C(struct player_state_s *, s32);
    void func_808000F0_bssub(struct player_state_s *);

    if (func_8009E77C(arg0, 0xF) == 0) {
        _basub_entrypoint_10(arg0);
        arg0->unk170 = arg0->unk16C = 0.0f;
        baphysics_set_gravity(arg0, 0);
        baphysics_set_terminal_velocity(arg0, -399.99f);
        func_800961AC(arg0, 9);
        func_80095964(arg0, 1);
        func_8009BC5C(arg0, 2.0f);
        bastick_setZoneMax(arg0, 0, 0.12f);
        bastick_setZoneMax(arg0, 1, 1.0f);
        func_800959C8(arg0, 90.0f, 70.0f);
        func_8009E4AC(arg0);
        func_8009E55C(arg0, 0, 70.0f);
        func_8009E55C(arg0, 1, 0.0f);
        func_8009E55C(arg0, 2, 0.0f);
        func_80093360(arg0, 55.0f);
        func_800910BC(arg0, 4);
        func_808000F0_bssub(arg0);
        _bafpctrl_entrypoint_18(arg0, 1);
        func_800947EC(arg0, 1, 1);
        func_80092864(arg0, 2.0f);
    }
}

void func_80800AEC_bssub(BT_NATIVE_ONLY(BtIntPtr bt_a0))
{
    _basub_entrypoint_14(BT_NATIVE_ONLY(bt_a0));
}

#ifdef BT_NATIVE
void func_80800B0C_bssub(BtIntPtr bt_a0)
#else
void func_80800B0C_bssub()
#endif
{
    _baspin_entrypoint_1();
}

/* extern */

struct player_state_s;     

void func_80800B2C_bssub(BtIntPtr arg0) {
    void _bamovethrust_entrypoint_3(struct player_state_s *, f32);
    void _bamovethrust_entrypoint_4(struct player_state_s *, f32);
    void _baspin_entrypoint_2(struct player_state_s *, s32, f32, s32, s32);
    void _basub_entrypoint_11(BtIntPtr, f32);
    void _basub_entrypoint_13(BtIntPtr, f32);
    void _batimer_set(struct player_state_s *, s32, f32);
    void baanim_playForDuration_loopSmooth(struct player_state_s *, s32, f32);
    void func_800FC660(u32);
    baanim_playForDuration_loopSmooth(arg0, 0x12E, 6.0f);
    func_80800000_bssub(arg0);
    _bamovethrust_entrypoint_3(arg0, 0.0f);
    _bamovethrust_entrypoint_4(arg0, 0.9f);
    _basub_entrypoint_11(arg0, 0.6f);
    _basub_entrypoint_13(arg0, 1.0f);
    _baspin_entrypoint_2(arg0, 0x130, 1.8f, 3, 1);
    _batimer_set(arg0, 9, 1.8f);
    func_800FC660(0x19);
}

/* extern */

void func_80800BD8_bssub(void *arg0) {
    s32 _baspin_entrypoint_3();
    s32 _batimer_decrement(void *, s32);
    s32 func_80101180(s32, s32, BtIntPtr);
    _baspin_entrypoint_3();
    if (_batimer_decrement(arg0, 9) != 0) {
        func_80101180(0x2C4, 0x71, (((PlayerState *)arg0)->unk184));
    }
}

/* extern */
void func_80800C1C_bssub(void *arg0) {
    s32 _basudie_entrypoint_8(void *);
    if (((PlayerState *)arg0)->unk15C.word) {
        func_80800B0C_bssub(arg0);
    } else {
        _basudie_entrypoint_8(arg0);
    }
    func_808008D8_bssub(arg0);
}

s32 func_80800C60_bssub(struct player_state_s *arg0) {
    BtIntPtr _fxairbub_entrypoint_1(f32 *, f32, f32, f32);
    f32 func_800964DC(struct player_state_s *);
    void func_8009C128(struct player_state_s *, f32[3]);
    void func_8009D9D4(struct player_state_s *);
    void func_8009DB04(struct player_state_s *, s32, f32, s32);
    BtIntPtr func_800B53A4(s32);
    void func_800BA22C(BtIntPtr, s32);
    void func_800BA670(BtIntPtr, s32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    s32 player_inWater(struct player_state_s *);
    extern s32 D_8080172C_bssub[];
    extern s32 D_80801748_bssub[];
    extern s32 D_80801774_bssub[];
    extern s32 D_808017A0_bssub[];
    extern s32 D_808017CC_bssub[];
    extern s32 D_80801840_bssub[][2];
    s32 emitters[10];
    f32 position[3];
    s32 i;

    func_8009DB04(arg0, 0x413, 1, 0x7FFF);
    func_8009D9D4(arg0);
    func_8009C128(arg0, position);
    func_800BBCB8(position, 0, 1.0f, 1, D_808017A0_bssub);
    for (i = 0; i < 10; i++) {
        emitters[i] = func_800B53A4(D_80801840_bssub[i][0]);
        func_800BA670(emitters[i], D_80801840_bssub[i][1]);
        emitters[i] = func_800BABB8(emitters[i], position, position, 1.0f, D_8080172C_bssub);
    }
    if (player_inWater(arg0)) {
        func_800BABB8(_fxairbub_entrypoint_1(position, 100.0f, func_800964DC(arg0), 1.0f), position, position, 1.0f, D_808017CC_bssub);
        for (i = 0; i < 10; i++) {
            emitters[i] = func_800BABB8(emitters[i], position, position, 1.0f, D_80801748_bssub);
        }
    } else {
        for (i = 0; i < 10; i++) {
            emitters[i] = func_800BABB8(emitters[i], position, position, 1.0f, D_80801774_bssub);
        }
    }
    for (i = 0; i < 10; i++) {
        func_800BA22C(emitters[i], D_80801840_bssub[i][0]);
    } BT_NATIVE_ONLY(return 0;)
}

/* extern */

void func_80800E34_bssub(struct player_state_s *arg0) {
    s32 _bafpctrl_entrypoint_19(struct player_state_s *);
    s32 _basudie_entrypoint_9(struct player_state_s *, s32);
    s32 func_800EA068(s32);
    s32 func_80800C60_bssub(struct player_state_s *);
    s32 temp_v0;

    func_808009B0_bssub(arg0);
    temp_v0 = func_800EA068(0x40);
    (arg0->unk15C.word) = temp_v0;
    if (temp_v0 != 0) {
        func_80800B2C_bssub((BtIntPtr) arg0);
        return;
    }
    _bafpctrl_entrypoint_19(arg0);
    _basudie_entrypoint_9(arg0, 0x41F00000);
    func_80800C60_bssub(arg0);
}

/* extern */

void func_80800E98_bssub(void *arg0) {
    s32 _basudie_entrypoint_10(void *);
    func_80800AEC_bssub(BT_NATIVE_ONLY((BtIntPtr)arg0));
    if ((((PlayerState *)arg0)->unk15C.word) != 0) {
        func_80800BD8_bssub(arg0);
        return;
    }
    _basudie_entrypoint_10(arg0);
}

/* extern */

void func_80800EE0_bssub(s32 arg0) {
    s32 _basudie_entrypoint_11(s32);
    s32 bs_setState(BtIntPtr, s32);
    s32 func_80093370(s32, s32);
    f32 func_80099A34(BtIntPtr);
    s32 func_8009BDAC(s32, f32);
    s32 func_8009E6EC();
    s32 func_8009E830(BtIntPtr, s32);
    if (func_8009E6EC() == 0x83) {
        func_8009BDAC(arg0, func_80099A34(arg0));
        func_80093370(arg0, 1);
        bs_setState(arg0, 0x131);
        func_8009E830(arg0, 2);
        return;
    }
    _basudie_entrypoint_11(arg0);
}

s32 bssub_entrypoint_0(s32 arg0) {
    extern BtIntPtr D_80801890_bssub[];
    return ((s32 *)&D_80801890_bssub)[arg0];
}

void func_80800F70_bssub(BtIntPtr arg0)
{
    _bsdrone_entrypoint_2();
    func_808008D8_bssub(arg0);
}
void func_80800F98_bssub(BtIntPtr arg0)
{
    func_808009B0_bssub(arg0);
    _bsdrone_entrypoint_0(arg0);
}
void func_80800FC0_bssub(BtIntPtr arg0)
{
    func_80800AEC_bssub(BT_NATIVE_ONLY((BtIntPtr)arg0));
    func_80800254_bssub(arg0);
    _bsdrone_entrypoint_1(arg0);
}

s32 bssub_entrypoint_1(s32 arg0) {
    extern BtIntPtr D_808018A0_bssub[];
    return ((s32 *)&D_808018A0_bssub)[arg0];
}

void func_80801004_bssub(BtIntPtr arg0)
{
    func_80090A2C();
    func_808008D8_bssub(arg0);
}
/* extern */

void func_8080102C_bssub(struct player_state_s *arg0) {
    int anctrl_getIndex(struct anctrl_s *);
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    void baanim_playForDuration_loopSmooth(struct player_state_s *, s32, f32);
    void func_8008B1C8(struct anctrl_s *, f32);
    void func_8008C9F0(struct player_state_s *, f32, f32, f32, f32);
    void func_8008CA4C(struct player_state_s *, s32);
    f32 func_8009BB94(struct player_state_s *);
    struct anctrl_s *sp2C;
    s32 sp28;
    struct anctrl_s *temp_v0;

    temp_v0 = baanim_getAnimCtrlPtr(arg0);
    sp2C = temp_v0;
    sp28 = anctrl_getIndex(temp_v0);
    func_8008CA4C(arg0, 2);
    if (func_8009BB94(arg0) < 300.0f) {
        if (sp28 != 0x12E) {
            baanim_playForDuration_loopSmooth(arg0, 0x12E, 6.0f);
            func_8008B1C8(sp2C, 0.4f);
        }
        func_8008C9F0(arg0, 0.0f, 900.0f, 6.0f, 6.0f);
        return;
    }
    if (sp28 != 0x12F) {
        baanim_playForDuration_loopSmooth(arg0, 0x12F, 0.45f);
        func_8008B1C8(sp2C, 0.4f);
    }
    func_8008C9F0(arg0, 0.0f, 900.0f, 1.5f, 0.45f);
}

/* extern */

void func_80801130_bssub(struct player_state_s *self) {
    void baanim_setDurationRange(struct player_state_s *, f32, f32);
    void func_8008CA30(struct player_state_s *, f32);
    void func_800909CC(struct player_state_s *);
    func_808009B0_bssub(self);
    func_8080102C_bssub(self);
    baanim_setDurationRange(self, 0.3f, 10.0f);
    func_8008CA30(self, 1.0f);
    func_800909CC(self);
}

void func_80801188_bssub(struct player_state_s *arg0) {
    s32 bs_setState(BtIntPtr, s32);
    s32 sp24;

    sp24 = 0;
    func_80800AEC_bssub(BT_NATIVE_ONLY((BtIntPtr)arg0));
    func_8080102C_bssub(arg0);
    func_80800634_bssub(arg0);
    func_80800768_bssub(arg0);
    func_80800254_bssub(arg0);
    func_80800834_bssub(arg0);
    if (arg0->unk16C == 0.0f) {
        sp24 = 0x131;
    }
    bs_setState(arg0, sp24);
}

s32 bssub_entrypoint_2(s32 arg0) {
    extern BtIntPtr D_808018B0_bssub[];
    return ((s32 *)&D_808018B0_bssub)[arg0];
}

void func_8080121C_bssub(BtIntPtr arg0)
{
    _baspin_entrypoint_1();
    func_808008D8_bssub(arg0);
}
/* extern */

void func_80801244_bssub(BtIntPtr arg0) {
    void _baspin_entrypoint_2(struct player_state_s *, s32, f32, s32, s32);
    func_808009B0_bssub(arg0);
    _baspin_entrypoint_2(arg0, 0x130, 1.8f, 3, 1);
}

/* extern */

void func_80801284_bssub(BtIntPtr arg0) {
    s32 _baspin_entrypoint_3(BtIntPtr);
    s32 bs_setState(BtIntPtr, s32);
    void func_800914FC(struct player_state_s *, f32, s32);
    s32 sp1C;

    sp1C = 0;
    func_80800AEC_bssub(BT_NATIVE_ONLY((BtIntPtr)arg0));
    func_800914FC((struct player_state_s *)arg0, 40.0f, 0);
    if (_baspin_entrypoint_3(arg0) == 2) {
        sp1C = 0x131;
    }
    bs_setState(arg0, sp1C);
}

s32 bssub_entrypoint_3(s32 arg0) {
    extern BtIntPtr D_808018C0_bssub[];
    return ((s32 *)&D_808018C0_bssub)[arg0];
}

void func_808012F0_bssub(BtIntPtr arg0)
{
    _baspin_entrypoint_1();
    func_808008D8_bssub(arg0);
}
/* extern */

void func_80801318_bssub(BtIntPtr arg0) {
    void _baspin_entrypoint_2(struct player_state_s *, s32, f32, s32, s32);
    func_808009B0_bssub(arg0);
    _baspin_entrypoint_2(arg0, 0x130, 1.8f, 3, 1);
}

/* extern */

void func_80801358_bssub(BtIntPtr arg0) {
    s32 _baspin_entrypoint_3(BtIntPtr);
    s32 bs_setState(BtIntPtr, s32);
    void func_800914FC(struct player_state_s *, f32, s32);
    s32 sp1C;

    sp1C = 0;
    func_80800AEC_bssub(BT_NATIVE_ONLY((BtIntPtr)arg0));
    func_800914FC((struct player_state_s *)arg0, 40.0f, 0);
    if (_baspin_entrypoint_3(arg0) == 2) {
        sp1C = 0x131;
    }
    bs_setState(arg0, sp1C);
}

s32 bssub_entrypoint_4(s32 arg0) {
    extern BtIntPtr D_808018D0_bssub[];
    return ((s32 *)&D_808018D0_bssub)[arg0];
}

void func_808013C4_bssub(BtIntPtr arg0)
{
    _babounce_entrypoint_3();
    func_808008D8_bssub(arg0);
}
/* extern */

void func_808013EC_bssub(BtIntPtr arg0) {
    s32 _babounce_entrypoint_4(BtIntPtr, s32);
    s32 _babounce_entrypoint_5(BtIntPtr, s32, s32);
    func_808009B0_bssub(arg0);
    _babounce_entrypoint_4(arg0, 2);
    _babounce_entrypoint_5(arg0, 0x12E, 0x40C00000);
}

/* extern */

void func_80801428_bssub(BtIntPtr arg0) {
    s32 _babounce_entrypoint_9(BtIntPtr);
    s32 bs_setState(BtIntPtr, s32);
    void func_800914FC(struct player_state_s *, f32, s32);
    s32 sp1C;

    sp1C = 0;
    func_80800AEC_bssub(BT_NATIVE_ONLY((BtIntPtr)arg0));
    func_800914FC((struct player_state_s *)arg0, 40.0f, 0);
    if (_babounce_entrypoint_9(arg0) != 0) {
        sp1C = 0x131;
    }
    bs_setState(arg0, sp1C);
}

s32 bssub_entrypoint_5(s32 arg0) {
    extern BtIntPtr D_808018E0_bssub[];
    return ((s32 *)&D_808018E0_bssub)[arg0];
}

void func_80801490_bssub(BtIntPtr arg0)
{
    _bsrest_entrypoint_14();
    func_808008D8_bssub(arg0);
}
void func_808014B8_bssub(BtIntPtr arg0) {
    void func_8009BF5C(struct player_state_s *, f32);
    func_808009B0_bssub(arg0);
    func_8009BF5C(arg0, 0.0f);
    _bsrest_entrypoint_16(arg0);
    func_8009B94C((u8 *)arg0, 0);
    func_8009BA9C(arg0, NULL);
    (((PlayerState *)arg0)->unk16C) = 0.0f;
}

/* extern */

void func_80801518_bssub(s32 arg0) {
    s32 _badata_entrypoint_34(BtIntPtr);
    s32 _bsrest_entrypoint_20(BtIntPtr);
    s32 bs_setState(BtIntPtr, s32);
    s32 sp1C;

    sp1C = 0;
    func_80800AEC_bssub(BT_NATIVE_ONLY((BtIntPtr)arg0));
    if (_bsrest_entrypoint_20(arg0) != 0) {
        sp1C = _badata_entrypoint_34(arg0);
    }
    bs_setState(arg0, sp1C);
}

s32 bssub_entrypoint_6(s32 arg0) {
    extern BtIntPtr D_808018F0_bssub[];
    return ((s32 *)&D_808018F0_bssub)[arg0];
}

void func_80801578_bssub(BtIntPtr arg0)
{
    func_80090A2C();
    func_808008D8_bssub(arg0);
}
void func_808015A0_bssub(struct player_state_s *arg0) {
    int anctrl_getIndex(struct anctrl_s *);
    void anctrl_setDuration(struct anctrl_s *, f32);
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    void baanim_playForDuration_loopSmooth(struct player_state_s *, s32, f32);
    void func_800909CC(struct player_state_s *);
    struct anctrl_s *sp24;

    sp24 = baanim_getAnimCtrlPtr(arg0);
    func_808009B0_bssub(arg0);
    if (anctrl_getIndex(sp24) == 0x12E) {
        anctrl_setDuration(sp24, 6.0f);
    } else {
        baanim_playForDuration_loopSmooth(arg0, 0x12E, 6.0f);
    }
    func_800909CC(arg0);
    func_80800000_bssub(arg0);
}

void func_80801618_bssub(struct player_state_s *arg0) {
    s32 bs_setState(BtIntPtr, s32);
    s32 sp24;

    sp24 = 0;
    func_80800AEC_bssub(BT_NATIVE_ONLY((BtIntPtr)arg0));
    func_80800634_bssub(arg0);
    func_80800768_bssub(arg0);
    func_80800254_bssub(arg0);
    func_80800834_bssub(arg0);
    if (arg0->unk16C != 0.0f) {
        sp24 = 0x12C;
    }
    bs_setState(arg0, sp24);
}

s32 bssub_entrypoint_7(s32 arg0) {
    extern BtIntPtr D_80801900_bssub[];
    return ((s32 *)&D_80801900_bssub)[arg0];
}
/* data_to_c.py: from asm/data/overlays/bs/sub.data.s */
void _bsdrone_entrypoint_3();
s32 D_808016E0_bssub[19] BT_DATA(4, overlays_bs_sub, 0x0) = { 1903068, 655360, 0, 0, 44, -5242830, -5242800, 3276880, 1376276, 6684704, -252645296, 2228275, 6684876, 20119574, 268435480, 6, 0, 2818201, 11730944 };
s32 D_8080172C_bssub [7] BT_DATA(4, overlays_bs_sub, 0x4C) = { 1441794, 1376256, 11730974, 1966110, 262297, 458757, 0 };
s32 D_80801748_bssub [11] BT_DATA(4, overlays_bs_sub, 0x68) = { 2490518, 9830400, 16384250, 46, -5767168, 9830488, 23527674, 1834808, -6553557, 45286067, 0 };
s32 D_80801774_bssub [11] BT_DATA(4, overlays_bs_sub, 0x94) = { 2490768, 13107200, 58982900, 46, -6029312, 39387096, 23528224, 1833508, -91750357, 40239718, 0 };
s32 D_808017A0_bssub [11] BT_DATA(4, overlays_bs_sub, 0xC0) = { 1903062, 1376256, 4980758, 268435486, 1966110, 1638400, 34, 16777472, 67109888, 2818176, 8388608 };
s32 D_808017CC_bssub [29] BT_DATA(4, overlays_bs_sub, 0xEC) = { 786467, 2818560, 41943085, 1310760, 2228244, 1966115, 3146778, 786477, 2818432, 33554477, 3276870, 2228257, 2490414, 3802650, 786487, 2818304, 25165869, 4587600, 2228264, 3473472, 4982554, 786492, 2949200, 5898283, 8388864, 2228285, 4194378, 5834778, 0 };
s32 D_80801840_bssub [10] [ 2 ] BT_DATA(4, overlays_bs_sub, 0x160) = { { 1, 1809 }, { 1, 1810 }, { 1, 1811 }, { 3, 1812 }, { 4, 1813 }, { 2, 1814 }, { 1, 1815 }, { 1, 1816 }, { 1, 1817 }, { 1, 2403 } };
BtIntPtr D_80801890_bssub [4] BT_DATA(4, overlays_bs_sub, 0x1B0) = { (BtIntPtr)func_80800C1C_bssub, (BtIntPtr)func_80800E34_bssub, (BtIntPtr)func_80800E98_bssub, (BtIntPtr)func_80800EE0_bssub };
BtIntPtr D_808018A0_bssub [4] BT_DATA(4, overlays_bs_sub, 0x1C0) = { (BtIntPtr)func_80800F70_bssub, (BtIntPtr)func_80800F98_bssub, (BtIntPtr)func_80800FC0_bssub, (BtIntPtr)_bsdrone_entrypoint_3 };
BtIntPtr D_808018B0_bssub [4] BT_DATA(4, overlays_bs_sub, 0x1D0) = { (BtIntPtr)func_80801004_bssub, (BtIntPtr)func_80801130_bssub, (BtIntPtr)func_80801188_bssub, (BtIntPtr)func_80800064_bssub };
BtIntPtr D_808018C0_bssub [4] BT_DATA(4, overlays_bs_sub, 0x1E0) = { (BtIntPtr)func_8080121C_bssub, (BtIntPtr)func_80801244_bssub, (BtIntPtr)func_80801284_bssub, (BtIntPtr)func_80800064_bssub };
BtIntPtr D_808018D0_bssub [4] BT_DATA(4, overlays_bs_sub, 0x1F0) = { (BtIntPtr)func_808012F0_bssub, (BtIntPtr)func_80801318_bssub, (BtIntPtr)func_80801358_bssub, (BtIntPtr)func_80800064_bssub };
BtIntPtr D_808018E0_bssub [4] BT_DATA(4, overlays_bs_sub, 0x200) = { (BtIntPtr)func_808013C4_bssub, (BtIntPtr)func_808013EC_bssub, (BtIntPtr)func_80801428_bssub, (BtIntPtr)func_80800064_bssub };
BtIntPtr D_808018F0_bssub [4] BT_DATA(4, overlays_bs_sub, 0x210) = { (BtIntPtr)func_80801490_bssub, (BtIntPtr)func_808014B8_bssub, (BtIntPtr)func_80801518_bssub, (BtIntPtr)func_80800064_bssub };
BtIntPtr D_80801900_bssub [4] BT_DATA(4, overlays_bs_sub, 0x220) = { (BtIntPtr)func_80801578_bssub, (BtIntPtr)func_808015A0_bssub, (BtIntPtr)func_80801618_bssub, (BtIntPtr)func_80800064_bssub };
