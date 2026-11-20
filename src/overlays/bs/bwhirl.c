#include "common.h"
#if defined(BT_NATIVE)
struct anctrl_s;
struct player_state_s;
#endif
#ifdef BT_NATIVE
#include "core2/particle_script.h"
#endif
#ifdef BT_NATIVE
#include "overlays/ba/anim_smooth.h"
#endif
BT_NATIVE_ONLY(struct player_state_s; void _bsrest_entrypoint_14(struct player_state_s *);) typedef struct player_state_s PlayerState;
struct anctrl_s;
#include "bs_script.h"
void func_80800000_bsbwhirl(void *arg0) {
    *(s32 *)((u8 *)arg0 + 0x160) = 0;
}

void func_80800008_bsbwhirl(PlayerState *arg0) {
    f32 func_80092B8C(PlayerState *, f32 *);
    f32 func_80092BE8(PlayerState *);
    void func_8009C128(PlayerState *, f32[3]);
    s8 func_800BF8E4(void);
    s32 func_800C8A98();
    void func_800C8CB8(s32, f32[3]);
    void func_800C8E54(s32, f32, f32);
    void func_800C8E84(s32 id,u32 *color);
    void func_800C8F64(s32, s32);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    extern s32 D_80800F50_bsbwhirl[3];
    f32 sp34[3];
    f32 sp28[3];
    f32 sp24;

    if (func_800BF8E4() > 0) {
        if ((*(s32 *)((s8 *)(arg0) + (0x160))) == 0) {
            (*(s32 *)((s8 *)(arg0) + (0x160))) = func_800C8A98();
            func_800C8E54((*(s32 *)((s8 *)(arg0) + (0x160))), 80.0f, 350.0f);
            func_800C8F64((*(s32 *)((s8 *)(arg0) + (0x160))), 0xB);
            func_800C8E84((*(s32 *)((s8 *)(arg0) + (0x160))), D_80800F50_bsbwhirl);
        }
        sp24 = func_80092B8C(arg0, sp28);
        func_8009C128(arg0, sp34);
        func_800EF04C(sp34, sp28);
        func_800EF1B8(sp34, func_80092BE8(arg0), sp24);
        sp34[1] += sp24;
        func_800C8CB8((*(s32 *)((s8 *)(arg0) + (0x160))), sp34);
    }
}

void func_808000D8_bsbwhirl(PlayerState *arg0) {
    s32 _chlightfader_entrypoint_1(s32, f32, s32);
    s32 temp_a3;

    temp_a3 = (*(s32 *)((s8 *)(arg0) + (0x160)));
    if (temp_a3 != 0) {
        (*(s32 *)((s8 *)(arg0) + (0x160))) = _chlightfader_entrypoint_1(temp_a3, 0.25f, 2);
    }
}

void func_80800114_bsbwhirl(PlayerState *arg0) {
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    int bastick_getZone(PlayerState *);
    f32 bastick_getZonePosition(PlayerState *);
    f32 func_800F1214(f32, f32, f32);
    f32 sp1C;

    sp1C = bastick_getZonePosition(arg0);
    if (bastick_getZone(arg0) == 0) {
        baphysics_set_target_horizontal_velocity(arg0, 0.0f);
        return;
    }
    baphysics_set_target_horizontal_velocity(arg0, func_800F1214(sp1C, 80.0f, 425.0f));
}

void func_8080017C_bsbwhirl(PlayerState *volatile arg0) {
    void bastick_resetZones(PlayerState *);
    s32 bs_getNextState(PlayerState *);
    void func_8008CA4C(PlayerState *, s32);
    void func_800A0CF4(PlayerState *, s32);
    void func_800FC74C(u32);
    s32 nextState;

    nextState = bs_getNextState(*(PlayerState **)&arg0);
    if ((nextState != 0x1B) && (nextState != 0x1C) && (nextState != 0x1D) && (nextState != 0x1E) && (nextState != 0xA4) && (nextState != 0xA5)) {
        bastick_resetZones(arg0);
        func_800A0CF4(arg0, 0);
        func_800FC74C(0xD);
        func_808000D8_bsbwhirl(arg0);
    }
    func_8008CA4C(arg0, 1);
}

void func_80800200_bsbwhirl(u8 *arg0) {
    f32 func_800136E4(f32);
    void func_8009BB24(void *, f32 *);
    void func_8009C128(PlayerState *, f32[3]);
    BtIntPtr func_800B5BE4(s32);
    s32 func_800BA22C(BtIntPtr, s32);
    BT_IDO_ONLY(s32 func_800BA930(BtIntPtr, s16, s32, s16, s32, s32, s32);) BT_NATIVE_ONLY(void func_800BA930(BtIntPtr, s16, s16, s16, s16, s16, s16);)
    BT_IDO_ONLY(BtIntPtr func_800BABB8(BtIntPtr, f32 *, BtIntPtr, s32, s32 *);)
    void func_800EF04C(f32 *, f32 *);
    s32 func_800EFCD8(f32 *, f32, s32);
    f32 yaw_get(u8 *);
    extern s32 D_80800F5C_bsbwhirl[15];
    f32 temp_f2;
    f32 sp60[3];
    f32 sp54[3];
    f32 sp48[3];
    f32 sp3C[3];
    BtIntPtr sp38;

    func_8009C128((PlayerState *)arg0, sp3C);
    func_800EFCD8(sp60, yaw_get(arg0), 0x42400000);
    sp60[1] = 0.0f;
    func_800EF04C(sp3C, sp60);
    sp38 = func_800B5BE4(0xE);
    func_800BABB8(sp38, BT_NATIVE_ONLY((f32 *))(sp3C), 0, BT_DATA_FIELD(1.0f, 0x3F800000), BT_NATIVE_ONLY((s16 *))D_80800F5C_bsbwhirl);
    func_8009BB24(arg0, sp60);
    func_800EFCD8(sp54, (*(f32 *)((s8 *)(arg0) + (0x170))), 0x437A0000);
    func_800EFCD8(sp48, (*(f32 *)((s8 *)(arg0) + (0x170))) + 45.0f, 0x437A0000);
    sp54[1] = 0.0f;
    sp48[1] = 0.0f;
    func_800EF04C(sp54, sp60);
    func_800EF04C(sp48, sp60);
    if (sp48[0] < sp54[0]) {
        temp_f2 = sp48[0];
        sp48[0] = sp54[0];
        sp54[0] = temp_f2;
    }
    if (sp48[2] < sp54[2]) {
        temp_f2 = sp48[2];
        sp48[2] = sp54[2];
        sp54[2] = temp_f2;
    }
    (*(f32 *)((s8 *)(arg0) + (0x170))) = func_800136E4((*(f32 *)((s8 *)(arg0) + (0x170))) + 45.0f);
    func_800BA930(sp38, (s16) (s32) sp54[0], 0xFA, (s16) (s32) sp54[2], (s32) sp48[0], 0xFA, (s32) sp48[2]);
    func_800BA22C(sp38, 2);
}

/* extern */

s32 func_808003A8_bsbwhirl(PlayerState *arg0, s32 arg1) {
    int bakey_pressed(PlayerState *, int);
    int bakey_released(PlayerState *, int);
    int bastick_getZone(PlayerState *);
    s32 player_inWater(PlayerState *);
    int player_isStable(PlayerState *);
    s32 var_s1;

    var_s1 = arg1;
    if (bastick_getZone(arg0) > 0) {
        var_s1 = 0x1C;
    }
    if (bakey_released(arg0, 1) != 0) {
        var_s1 = 0x1E;
    }
    if ((bakey_pressed(arg0, 8) != 0) && (player_isStable(arg0) != 0)) {
        var_s1 = 0x1D;
    }
    if (player_inWater(arg0) != 0) {
        var_s1 = 0x2D;
    }
    return var_s1;
}

void func_80800430_bsbwhirl(void *arg0, s32 *arg1)
{
  f32 new_var;
  void _chusefeather_entrypoint_1(s32 arg0, s32 arg1);
  void _suinv_entrypoint_0(s32* arg0, s32 failure, s32 success, s32 itemType, s32 amountToRemove);
  s32 func_8009DF18(void *, s32, s32, s32);
  f32 func_800D8FF8();
  new_var = func_800D8FF8();
  *((f32 *) (((s8 *) arg0) + 0x16C)) = (f32) ((*((f32 *) (((s8 *) arg0) + 0x16C))) + new_var);
  if ((*((f32 *) (((s8 *) arg0) + 0x16C))) > 2.0f)
  {
    *((f32 *) (((s8 *) arg0) + 0x16C)) = 0.0f;
    _suinv_entrypoint_0(arg1, 0x1E, -1, 0x47, 1);
    if ((*arg1) != 0x1E)
    {
      func_8009DF18(arg0, 0x3E9, 0x3F4CCCCD, 0x6D60);
      _chusefeather_entrypoint_1(*((s32 *) (((s8 *) arg0) + 0x184)), 1);
    }
  }
}

void bainput_enable(PlayerState *, int, s32);

void bsbwhirl_entrypoint_0(PlayerState *arg0) {
    void baanim_playForDuration_once(PlayerState *, int, f32);
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    void bastick_setZoneMax(PlayerState *, s32, f32);
    void func_8009D874(PlayerState *);
    void func_8009FFD8(PlayerState *, int, int, s32, int);
    void func_800A0CF4(PlayerState *, s32);
    void func_800FC660(u32);

    baanim_playForDuration_once(arg0, 0x22, 0.5f);
    func_8009FFD8(arg0, 1, 1, 1, 2);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    bastick_setZoneMax(arg0, 0, 0.03f);
    bastick_setZoneMax(arg0, 1, 1.0f);
    func_800A0CF4(arg0, 1);
    *(f32 *)((u8 *)arg0 + 0x170) = 0.0f;
    *(f32 *)((u8 *)arg0 + 0x16C) = 0.0f;
    func_800FC660(0xD);
    func_80800000_bsbwhirl(arg0);
    func_8009D874(arg0);
    bainput_enable(arg0, 1, 0);
}

/* extern */

void bsbwhirl_entrypoint_1(BT_NATIVE_ONLY(struct player_state_s *) BT_IDO_ONLY(BtIntPtr) arg0) {
    s32 anctrl_isStopped(BT_NATIVE_ONLY(struct anctrl_s *) BT_IDO_ONLY(BtIntPtr));
    #if defined(BT_NATIVE)
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    #else
    s32 baanim_getAnimCtrlPtr(BT_NATIVE_ONLY(struct player_state_s *) BT_IDO_ONLY(BtIntPtr));
    #endif
    void bs_setState(PlayerState *, int);
    s32 sp1C;

    sp1C = 0;
    bainput_enable((void *)arg0, 1, 1);
    if (anctrl_isStopped(baanim_getAnimCtrlPtr(arg0)) != 0) {
        sp1C = 0x1B;
    }
    func_80800008_bsbwhirl(arg0);
    bs_setState(arg0, sp1C);
}

/* extern */

void bsbwhirl_entrypoint_2(BtIntPtr arg0) { bainput_enable(arg0, 1, 1); func_8080017C_bsbwhirl(arg0); }


BsScript bsbwhirl_entrypoint_3(BsScriptType arg0) {
    extern BtIntPtr D_80800F98_bsbwhirl[];
    return (BsScript)D_80800F98_bsbwhirl[arg0];
}

/* extern */

void bsbwhirl_entrypoint_4(BtIntPtr arg0) {
    BT_IDO_ONLY(s32 baanim_playForDuration_loopSmooth(BtIntPtr, s32, s32);)
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    void func_8009FFD8(PlayerState *, int, int, s32, int);
    baanim_playForDuration_loopSmooth(arg0, 0x23, BT_IDO_ONLY(0x3F800000) BT_NATIVE_ONLY(1.0f));
    func_8009FFD8(arg0, 1, 1, 1, 2);
    baphysics_set_target_horizontal_velocity((void *)arg0, 0.0f);
}

void bsbwhirl_entrypoint_5(PlayerState *arg0) {
    s32 _badrone_entrypoint_25(PlayerState *);
    void bs_setState(PlayerState *, int);
    int func_8008E148(PlayerState *);
    s32 player_inWater(PlayerState *);
    s32 sp24;

    sp24 = 0;
    func_80800200_bsbwhirl(arg0);
    sp24 = func_808003A8_bsbwhirl(arg0, sp24);
    func_80800430_bsbwhirl(arg0, &sp24);
    func_80800008_bsbwhirl(arg0);
    if (func_8008E148(arg0) != 0) {
        sp24 = _badrone_entrypoint_25(arg0);
    }
    if (player_inWater(arg0) != 0) {
        sp24 = 0x4C;
    }
    bs_setState(arg0, sp24);
}

void bsbwhirl_entrypoint_6(PlayerState *arg0)
{
    func_8080017C_bsbwhirl(arg0);
}

BsScript bsbwhirl_entrypoint_7(BsScriptType arg0) {
    extern BtIntPtr D_80800FA8_bsbwhirl[];
    return (BsScript)D_80800FA8_bsbwhirl[arg0];
}

/* extern */

void bsbwhirl_entrypoint_8(BtIntPtr arg0) {
    BT_IDO_ONLY(s32 baanim_playForDuration_loopSmooth(BtIntPtr, s32, s32);)
    s32 func_8008C9F0(BtIntPtr, s32, s32, s32, f32);
    void func_8009FFD8(PlayerState *, int, int, s32, int);
    baanim_playForDuration_loopSmooth(arg0, 0x11, BT_IDO_ONLY(0x3F07AE14) BT_NATIVE_ONLY(0.53f));
    func_8008C9F0(arg0, 0x42A00000, 0x43D48000, 0x3F0F5C29, 0.4f);
    func_8009FFD8(arg0, 2, 1, 1, 2);
}

void bsbwhirl_entrypoint_9(PlayerState *arg0) {
    s32 _badrone_entrypoint_25(PlayerState *);
    int bakey_pressed(PlayerState *, int);
    int bakey_released(PlayerState *, int);
    int bastick_getZone(PlayerState *);
    void bs_setState(PlayerState *, int);
    int func_8008E148(PlayerState *);
    s32 func_8009BCD4(PlayerState *, f32);
    void func_800A2CE8(PlayerState *, f32, s32);
    s32 player_inWater(PlayerState *);
    int player_isStable(PlayerState *);
    s32 sp24;

    sp24 = 0;
    func_80800200_bsbwhirl(arg0);
    func_800A2CE8(arg0, 0.47f, 4);
    func_800A2CE8(arg0, 0.97f, 3);
    func_80800114_bsbwhirl(arg0);
    if ((bastick_getZone(arg0) == 0) && (func_8009BCD4(arg0, 1.0f) != 0)) {
        sp24 = 0x1B;
    }
    if (bakey_released(arg0, 1) != 0) {
        sp24 = 0x1E;
    }
    if ((bakey_pressed(arg0, 8) != 0) && (player_isStable(arg0) != 0)) {
        sp24 = 0x1D;
    }
    if (player_inWater(arg0) != 0) {
        sp24 = 0x4C;
    }
    func_80800430_bsbwhirl(arg0, &sp24);
    func_80800008_bsbwhirl(arg0);
    if (func_8008E148(arg0) != 0) {
        sp24 = _badrone_entrypoint_25(arg0);
    }
    bs_setState(arg0, sp24);
}

void bsbwhirl_entrypoint_10(PlayerState *arg0)
{
    func_8080017C_bsbwhirl(arg0);
}

BsScript bsbwhirl_entrypoint_11(BsScriptType arg0) {
    extern BtIntPtr D_80800FB8_bsbwhirl[];
    return (BsScript)D_80800FB8_bsbwhirl[arg0];
}

void bsbwhirl_entrypoint_12(PlayerState *arg0) {
    void anctrl_reset(void *control);
    void anctrl_setDuration(void *arg0, f32 arg1);
    void anctrl_setIndex(void *arg0, s32 arg1);
    void anctrl_setPlaybackType(void *arg0, s32 arg1);
    void anctrl_setStart(struct anctrl_s *, f32);
    void anctrl_setSubrange(struct anctrl_s *, f32, f32);
    void anctrl_start(void *control);
    #if defined(BT_NATIVE)
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    #else
    s32 baanim_getAnimCtrlPtr(BtIntPtr);
    #endif
    void func_8008B1C8(struct anctrl_s *, f32);
    f32 baphysics_get_target_horizontal_velocity(PlayerState *);
    void baphysics_set_gravity(PlayerState *, f32);
    void baphysics_set_horizontal_velocity(PlayerState *, f32, f32);
    void baphysics_set_target_yaw(PlayerState *, f32);
    void baphysics_set_vertical_velocity(PlayerState *, f32);
    f32 bastick_distance(PlayerState *);
    f32 bastick_getAngleRelativeToBanjo(PlayerState *);
    f32 yaw_getIdeal(PlayerState *);
    void yaw_setIdeal(PlayerState *, f32);
    void func_8009D7A4(PlayerState *, f32, f32);
    void func_8009FFD8(PlayerState *, int, int, s32, int);
    s32 pad[2];
    f32 sp2C;
    BT_NATIVE_ONLY(struct anctrl_s *) BT_IDO_ONLY(BtIntPtr) control;

    control = baanim_getAnimCtrlPtr(arg0);
    anctrl_reset(control);
    anctrl_setIndex(control, 0x1B);
    anctrl_setDuration(control, 0.8f);
    func_8008B1C8(control, 0.134f);
    anctrl_setStart(control, 0.14f);
    anctrl_setSubrange(control, 0.0f, 0.4495f);
    anctrl_setPlaybackType(control, 1);
    anctrl_start(control);
    func_8009FFD8(arg0, 1, 1, 3, 6);
    if (bastick_distance(arg0) != 0.0f) {
        yaw_setIdeal(arg0, bastick_getAngleRelativeToBanjo(arg0));
    }
    baphysics_set_target_yaw(arg0, yaw_getIdeal(arg0));
    func_80800114_bsbwhirl(arg0);
    sp2C = yaw_getIdeal(arg0);
    baphysics_set_horizontal_velocity(arg0, sp2C, baphysics_get_target_horizontal_velocity(arg0));
    baphysics_set_vertical_velocity(arg0, 693.5f);
    baphysics_set_gravity(arg0, -1200.0f);
    func_8009D7A4(arg0, 0.91f, 1.09f);
    *(s32 *)((u8 *)arg0 + 0x15C) = 0;
}

void baphysics_reset_gravity();

void bsbwhirl_entrypoint_13(PlayerState *arg0) {
    s32 anctrl_isStopped(BT_NATIVE_ONLY(struct anctrl_s *) BT_IDO_ONLY(BtIntPtr));
    void anctrl_setDuration(void *arg0, f32 arg1);
    void anctrl_setPlaybackType(void *arg0, s32 arg1);
    void anctrl_setSubrange(struct anctrl_s *, f32, f32);
    #if defined(BT_NATIVE)
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    #else
    s32 baanim_getAnimCtrlPtr(BtIntPtr);
    #endif
    int bakey_released(PlayerState *, int);
    s32 player_inWater(PlayerState *);
    void bs_setState(PlayerState *, int);
    void func_8009BB24(void *, f32 *);
    void func_8009FE58(PlayerState *);
    s32 sp34;
    BT_NATIVE_ONLY(struct anctrl_s *) BT_IDO_ONLY(BtIntPtr) sp30;
    f32 sp24[3];

    sp34 = 0;
    sp30 = baanim_getAnimCtrlPtr(arg0);
    func_80800200_bsbwhirl(arg0);
    func_80800114_bsbwhirl(arg0);
    func_8009BB24(arg0, sp24);
    if (bakey_released(arg0, 8) && sp24[1] > 0.0f) {
        baphysics_reset_gravity(arg0);
    }
    switch (*(s32 *)((u8 *)arg0 + 0x15C)) {
    case 0:
        if (func_8008DF8C(arg0, 0x82)) {
            anctrl_setSubrange(sp30, 0.0f, 1.0f);
            anctrl_setDuration(sp30, 0.8f);
            anctrl_setPlaybackType(sp30, 1);
            *(s32 *)((u8 *)arg0 + 0x15C) = 1;
        }
        break;
    case 1:
        if (player_inWater(arg0)) {
            sp34 = 0x2D;
        }
        if (player_isStable(arg0)) {
            *(s32 *)((u8 *)arg0 + 0x15C) = 2;
            func_8009FE58(arg0);
        }
        break;
    case 2:
        if (anctrl_isStopped(sp30)) {
            sp34 = 0x1B;
        }
        sp34 = func_808003A8_bsbwhirl(arg0, sp34);
        break;
    }
    func_80800430_bsbwhirl(arg0, &sp34);
    func_80800008_bsbwhirl(arg0);
    if (func_8008DA24(arg0)) {
        sp34 = 0xA8;
    }
    if (player_inWater(arg0)) {
        sp34 = 0x4C;
    }
    bs_setState(arg0, sp34);
}

void bsbwhirl_entrypoint_14(BtIntPtr arg0)
{
    baphysics_reset_gravity();
    func_8080017C_bsbwhirl(arg0);
}
BsScript bsbwhirl_entrypoint_15(BsScriptType arg0) {
    extern BtIntPtr D_80800FC8_bsbwhirl[];
    return (BsScript)D_80800FC8_bsbwhirl[arg0];
}

/* extern */

void bsbwhirl_entrypoint_16(PlayerState *arg0) {
    void anctrl_reset(void *control);
    void anctrl_setDuration(void *arg0, f32 arg1);
    void anctrl_setIndex(void *arg0, s32 arg1);
    void anctrl_setPlaybackType(void *arg0, s32 arg1);
    void anctrl_setSmoothTransition(void *arg0, s32 arg1);
    void anctrl_start(void *control);
    #if defined(BT_NATIVE)
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    #else
    s32 baanim_getAnimCtrlPtr();
    #endif
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    void func_8008B188(void *arg0, s32 arg1);
    void func_8008CA4C(PlayerState *, s32);
    void func_8009D2D8(PlayerState *arg0, s32 arg1);
    void func_800FCAE0(u32 track_id, u32 volume, u32 duration);
    BT_NATIVE_ONLY(struct anctrl_s *) BT_IDO_ONLY(BtIntPtr) temp_v0;

    temp_v0 = baanim_getAnimCtrlPtr(arg0);
    anctrl_reset(temp_v0);
    anctrl_setSmoothTransition(temp_v0, 0);
    func_8008B188(temp_v0, 0);
    anctrl_setIndex(temp_v0, 0x22);
    anctrl_setDuration(temp_v0, 0.5f);
    anctrl_setPlaybackType(temp_v0, 1);
    anctrl_start(temp_v0);
    func_8008CA4C(arg0, 1);
    func_8009D2D8(arg0, 2);
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    func_800FCAE0(0xD, 0, 0xFA0);
}

/* extern */

void bsbwhirl_entrypoint_17(BT_NATIVE_ONLY(struct player_state_s *) BT_IDO_ONLY(BtIntPtr) arg0) {
    s32 anctrl_isStopped(BT_NATIVE_ONLY(struct anctrl_s *) BT_IDO_ONLY(BtIntPtr));
    #if defined(BT_NATIVE)
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    #else
    s32 baanim_getAnimCtrlPtr(BT_NATIVE_ONLY(BtIntPtr));
    #endif
    void bs_setState(PlayerState *, int);
    s32 sp1C;

    sp1C = 0;
    if (anctrl_isStopped(baanim_getAnimCtrlPtr(BT_NATIVE_ONLY(arg0))) != 0) {
        sp1C = 1;
    }
    func_80800008_bsbwhirl(arg0);
    bs_setState(arg0, sp1C);
}

void bsbwhirl_entrypoint_18(PlayerState *arg0)
{
    func_8080017C_bsbwhirl(arg0);
}

BsScript bsbwhirl_entrypoint_19(BsScriptType arg0) {
    extern BtIntPtr D_80800FD8_bsbwhirl[];
    return (BsScript)D_80800FD8_bsbwhirl[arg0];
}

void bsbwhirl_entrypoint_20(BT_NATIVE_ONLY(s32 bt_a0))
{
    _bsdrone_entrypoint_0(BT_NATIVE_ONLY(bt_a0));
}

void bsbwhirl_entrypoint_21(BtIntPtr arg0)
{
    func_80800200_bsbwhirl(arg0);
    func_80800008_bsbwhirl(arg0);
    _bsdrone_entrypoint_1(arg0);
}

#ifdef BT_NATIVE
struct player_state_s;
void _bsdrone_entrypoint_2(struct player_state_s *);
#endif

void bsbwhirl_entrypoint_22(BT_NATIVE_ONLY(struct player_state_s *) BT_IDO_ONLY(BtIntPtr) arg0)
{
    _bsdrone_entrypoint_2(BT_NATIVE_ONLY(arg0));
    func_8080017C_bsbwhirl(arg0);
}
BsScript bsbwhirl_entrypoint_23(BsScriptType arg0) {
    extern BtIntPtr D_80800FE8_bsbwhirl[];
    return (BsScript)D_80800FE8_bsbwhirl[arg0];
}

void bsbwhirl_entrypoint_24(BtIntPtr arg0)
{
    _bsrest_entrypoint_14(BT_NATIVE_ONLY((struct player_state_s *)arg0));
    func_8080017C_bsbwhirl(arg0);
}
void bsbwhirl_entrypoint_25(BT_NATIVE_ONLY(s32 bt_a0))
{
    _bsrest_entrypoint_16(BT_NATIVE_ONLY(bt_a0));
}

void bsbwhirl_entrypoint_26(PlayerState *arg0) {
    void func_80800200_bsbwhirl(u8 *arg0);
    void func_80800008_bsbwhirl(PlayerState *);
    s32 _bsrest_entrypoint_13(PlayerState *);
    s32 _bsrest_entrypoint_20(PlayerState *);
    void bs_setState(PlayerState *, int);
    s32 sp24;
    PlayerState *self;

    self = arg0;
    sp24 = 0;
    func_80800200_bsbwhirl(self);
    func_80800008_bsbwhirl(self);
    if (_bsrest_entrypoint_20(self) != 0) {
        sp24 = _bsrest_entrypoint_13(self);
    }
    bs_setState(self, sp24);
}

BsScript bsbwhirl_entrypoint_27(BsScriptType arg0) {
    extern BtIntPtr D_80800FF8_bsbwhirl[];
    return (BsScript)D_80800FF8_bsbwhirl[arg0];
}

void func_80800EA0_bsbwhirl(PlayerState *arg0, void (*arg1)(PlayerState *)) {
    s32 func_8009E6EC(PlayerState *);
    void func_8009E830(PlayerState *, s32);
    s32 temp_v0;

    temp_v0 = func_8009E6EC(arg0);
    if ((temp_v0 == 0x1F) || (temp_v0 == 0x20) || (temp_v0 == 0x21) || (temp_v0 == 0x4E) || (temp_v0 == 0x51) || (temp_v0 == 0x52)) {
        func_8009E830(arg0, 1);
        return;
    }
    arg1(arg0);
}

void bsbwhirl_entrypoint_28(PlayerState *arg0) {
    void func_80099B94(PlayerState *);
    func_80800EA0_bsbwhirl(arg0, &func_80099B94);
}
/* data_to_c.py: from asm/data/overlays/bs/bwhirl.data.s */
void _bsbwhirl_entrypoint_2();
void _bsbwhirl_entrypoint_0();
void _bsbwhirl_entrypoint_1();
void _bsbwhirl_entrypoint_28();
void _bsbwhirl_entrypoint_6();
void _bsbwhirl_entrypoint_4();
void _bsbwhirl_entrypoint_5();
void _bsbwhirl_entrypoint_10();
void _bsbwhirl_entrypoint_8();
void _bsbwhirl_entrypoint_9();
void _bsbwhirl_entrypoint_14();
void _bsbwhirl_entrypoint_12();
void _bsbwhirl_entrypoint_13();
void _bsbwhirl_entrypoint_18();
void _bsbwhirl_entrypoint_16();
void _bsbwhirl_entrypoint_17();
void _bsbwhirl_entrypoint_22();
void _bsbwhirl_entrypoint_20();
void _bsbwhirl_entrypoint_21();
void _bsdrone_entrypoint_3();
void _bsbwhirl_entrypoint_24();
void _bsbwhirl_entrypoint_25();
void _bsbwhirl_entrypoint_26();
s32 D_80800F50_bsbwhirl[3] BT_DATA(4, overlays_bs_bwhirl, 0x0) = { 224, 224, 170 };
s32 D_80800F5C_bsbwhirl[15] BT_DATA(4, overlays_bs_bwhirl, 0xC) = { 1903074, 720886, 3342326, 655445, 655381, 131225, 2228300, 4980761, 1638439, 380, 440, 2818201, 10027035, -45810364, 0 };
BtIntPtr D_80800F98_bsbwhirl [4] BT_DATA(4, overlays_bs_bwhirl, 0x48) = { (BtIntPtr)_bsbwhirl_entrypoint_2, (BtIntPtr)_bsbwhirl_entrypoint_0, (BtIntPtr)_bsbwhirl_entrypoint_1, (BtIntPtr)_bsbwhirl_entrypoint_28 };
BtIntPtr D_80800FA8_bsbwhirl [4] BT_DATA(4, overlays_bs_bwhirl, 0x58) = { (BtIntPtr)_bsbwhirl_entrypoint_6, (BtIntPtr)_bsbwhirl_entrypoint_4, (BtIntPtr)_bsbwhirl_entrypoint_5, (BtIntPtr)_bsbwhirl_entrypoint_28 };
BtIntPtr D_80800FB8_bsbwhirl [4] BT_DATA(4, overlays_bs_bwhirl, 0x68) = { (BtIntPtr)_bsbwhirl_entrypoint_10, (BtIntPtr)_bsbwhirl_entrypoint_8, (BtIntPtr)_bsbwhirl_entrypoint_9, (BtIntPtr)_bsbwhirl_entrypoint_28 };
BtIntPtr D_80800FC8_bsbwhirl [4] BT_DATA(4, overlays_bs_bwhirl, 0x78) = { (BtIntPtr)_bsbwhirl_entrypoint_14, (BtIntPtr)_bsbwhirl_entrypoint_12, (BtIntPtr)_bsbwhirl_entrypoint_13, (BtIntPtr)_bsbwhirl_entrypoint_28 };
BtIntPtr D_80800FD8_bsbwhirl [4] BT_DATA(4, overlays_bs_bwhirl, 0x88) = { (BtIntPtr)_bsbwhirl_entrypoint_18, (BtIntPtr)_bsbwhirl_entrypoint_16, (BtIntPtr)_bsbwhirl_entrypoint_17, (BtIntPtr)_bsbwhirl_entrypoint_28 };
BtIntPtr D_80800FE8_bsbwhirl [4] BT_DATA(4, overlays_bs_bwhirl, 0x98) = { (BtIntPtr)_bsbwhirl_entrypoint_22, (BtIntPtr)_bsbwhirl_entrypoint_20, (BtIntPtr)_bsbwhirl_entrypoint_21, (BtIntPtr)_bsdrone_entrypoint_3 };
BtIntPtr D_80800FF8_bsbwhirl [6] BT_DATA(4, overlays_bs_bwhirl, 0xA8) = { (BtIntPtr)_bsbwhirl_entrypoint_24, (BtIntPtr)_bsbwhirl_entrypoint_25, (BtIntPtr)_bsbwhirl_entrypoint_26, (BtIntPtr)_bsbwhirl_entrypoint_28, 0, 0 };
