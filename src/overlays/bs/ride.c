#include "common.h"
struct player_state_s;
struct anctrl_s;
void func_80093230(struct player_state_s *, f32);

typedef struct player_state_s {
    /* 0x00 */ struct ba_alarm_s *alarm;
    /* 0x04 */ struct ba_anim_s *anim;
    /* 0x08 */ struct ba_attach_s *attach;
    /* 0x0C */ struct ba_unknown_c_s *unkC; // baavatar? from BK XBox debug strings?
    /* 0x10 */ struct ba_babykaz_s *babykaz;
    /* 0x14 */ struct ba_backpack_s *backpack;
    u8 pad18[0x4];
    /* 0x1C */ struct ba_bee_s *bee;
    /* 0x20 */ struct ba_unknown_20_s *unk20;
    /* 0x24 */ struct ba_boost_s *boost;
    /* 0x28 */ struct ba_bounce_s *bounce;
    /* 0x2C */ struct ba_unknown_2C_s *unk2C; //something with camera
    u8 pad30[0x4];
    /* 0x34 */ struct ba_buzz_s *buzz;
    u8 pad38[0x4];
    /* 0x3C */ struct ba_state_timer_list_s *state_timer; // clock?
    /* 0x40 */ struct ba_key_s *key; // controller?
    /* 0x44 */ struct ba_cough_s *cough;
    u8 pad48[0x38];
    /* 0x80 */ struct ba_flag_s *flag;
    u8 pad84[0x18];
    /* 0x9C */ struct ba_unk_9C* unk9C;
    u8 padA0[0x4];
    /* 0xA4 */ struct ba_input_s *input;
    u8 padA8[0x18];
    /* 0xC0 */ struct ba_unknown_C0_s *unkC0; // 1E72EA0
    u8 padC4[0x30];
    /* 0xF4 */ struct ba_roll_s *roll;
    /* 0xF8 */ struct ba_yaw_s *yaw;
    u8 padFC[0x24];
    /* 0x120 */ struct bs_state_s *state;
    u8 pad124[4];
    /* 0x128 */ struct ba_stick_s *stick;
    u8 pad12C[0x10];
    /* 0x13C */ struct ba_timer_s *timer;
    /* 0x140 */ struct ba_translate_s *translate;
    /* 0x144 */ struct ba_van_s *van;
    /* 0x148 */ struct ba_wandglow_s *wandglow;
    /* 0x14C */ struct ba_washer_s *washer;
    u8 pad150[0x4];
    /* 0x154 */ struct ba_wobble_s *wobble;
    u8 pad158[0x4];
    union {
        s32 word;
        u8 bytes[4];
    } unk15C; // Some sort of state
    union {
        s32 word;
        u8 bytes[4];
    } unk160;
    union {
        s32 word;
        u8 bytes[4];
    } unk164;
    union {
        s32 word;
        u8 bytes[4];
    } unk168;
    f32 unk16C;
    f32 unk170;
    f32 unk174;
    u8 pad178[0xC];
    s32 unk184;
    /* 0x188 */ struct bs_kazfly_s *kazfly;
} PlayerState;

void func_80800000_bsride(PlayerState *arg0) {
    Actor *_subaddiefind_entrypoint_2(s32, s32);
    void baphysics_set_target_horizontal_velocity(PlayerState *, f32);
    void func_800947EC(PlayerState *, s32, s32);
    void func_800961AC(PlayerState *, s32);
    s32 func_8009EA64(void);
    void func_8009FFD8();
    void func_800A34E4(void *, s32);

    arg0->unk15C.word = (s32)_subaddiefind_entrypoint_2(func_8009EA64(), 0)->unk0;
    baphysics_set_target_horizontal_velocity(arg0, 0.0f);
    func_800A34E4(arg0, 0);
    func_800961AC(arg0, 8);
    func_8009FFD8(arg0, 1, 1, 3, 7);
    func_800947EC(arg0, 1, 1);
}

void func_8080008C_bsride(struct player_state_s *arg0) {
    void func_800947EC(struct player_state_s *, s32, s32);
    void func_800A34E4(void *, s32);
    void func_800961AC(struct player_state_s *, s32);
    void baroll_setIdeal(struct player_state_s *, f32);
    void func_8009BF5C(struct player_state_s *, f32);
    *(s32 *)((u8 *)arg0 + 0x15C) = 0;
    func_800947EC(arg0, 1, 0);
    func_800A34E4(arg0, 1);
    func_800961AC(arg0, 1);
    baroll_setIdeal(arg0, 0.0f);
    func_8009BF5C(arg0, 0.0f);
}

s32 func_808000F0_bsride(s32 arg0) { func_8009EAE8(0); func_8080008C_bsride(arg0); }

/* extern */

void func_8080011C_bsride(s32 arg0) {
    s32 func_80099B94(s32);
    s32 func_8009E6EC();
    s32 func_8009E830(s32, s32);
    s32 func_808000F0_bsride(s32);
    if (func_8009E6EC() == 0x28) {
        func_808000F0_bsride(arg0);
        func_8009E830(arg0, 2);
        return;
    }
    func_80099B94(arg0);
}

void func_8080016C_bsride()
{
    void func_8080008C_bsride();
    func_8080008C_bsride();
}

/* extern */

void func_8080018C_bsride(s32 arg0) {
    s32 baanim_playForDuration_loopSmooth(s32, s32, s32);
    void func_8009C128(PlayerState *, f32[3]);
    void func_80800000_bsride(PlayerState *);
    func_80800000_bsride(arg0);
    baanim_playForDuration_loopSmooth(arg0, 0x256, 0x3F666666);
    func_8009C128(arg0, arg0 + 0x16C);
}

void func_808001CC_bsride(PlayerState *arg0) {
    void anctrl_setDuration(struct anctrl_s *, f32);
    struct anctrl_s *baanim_getAnimCtrlPtr(PlayerState *);
    void bs_setState(void *, s32);
    void func_8009C128(PlayerState *, f32[3]);
    f32 func_800D8FF8(void);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EEF94(f32 *);
    void func_800EFB24(void *, void *, void *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    s32 next_state;
    f32 distance;
    f32 duration;
    f32 delta[3];
    f32 position[3];

    next_state = 0;
    func_8009C128(arg0, position);
    func_800EFB24(delta, position, &arg0->unk16C);
    func_800EE7F8(&arg0->unk16C, position);
    distance = func_800EEF94(delta);
    duration = func_800F10B4(distance / func_800D8FF8(), 0.0f, 2000.0f, 0.9f, 0.22f);
    anctrl_setDuration(baanim_getAnimCtrlPtr(arg0), duration);
    if (arg0->unk15C.word == 0) {
        next_state = 0x2F;
    }
    bs_setState(arg0, next_state);
}

s32 bsride_entrypoint_0(s32 arg0) {
    extern s32 D_808009C0_bsride[];
    return ((s32 *)&D_808009C0_bsride)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ride/func_808002A0_bsride.s")

void func_808004AC_bsride(struct player_state_s *arg0) {
    func_80093230(arg0, 1.0f);
    func_8080008C_bsride(arg0);
}

/* extern */

void func_808004D8_bsride(struct player_state_s *arg0) {
    s32 baanim_playForDuration_loopSmooth(s32, s32, s32);
    void func_80800000_bsride(PlayerState *);
    func_80800000_bsride(arg0);
    baanim_playForDuration_loopSmooth(arg0, 0x281, 0x3F333333);
    func_80093230(arg0, 1.35f);
    (*(s32 *)((s8 *)(arg0) + (0x160))) = 0;
}

void func_80800524_bsride(struct player_state_s *arg0) {
    int baanim_isStopped(struct player_state_s *);
    s32 baanim_playForDuration_loopSmooth(s32, s32, s32);
    void bs_setState(void *, s32);
    s32 next_state;

    next_state = 0;
    if (*(s32 *)((s8 *)arg0 + 0x160) == 1) {
        if (baanim_isStopped(arg0)) {
            baanim_playForDuration_loopSmooth(arg0, 0x281, 0x3F333333);
            *(s32 *)((s8 *)arg0 + 0x160) = 0;
        }
    }
    if (*(s32 *)((s8 *)arg0 + 0x15C) == 0) {
        next_state = 0x2F;
    }
    bs_setState(arg0, next_state);
}

s32 bsride_entrypoint_1(s32 arg0) {
    extern s32 D_80800A70_bsride[];
    return ((s32 *)&D_80800A70_bsride)[arg0];
}

void func_808005B8_bsride()
{
    void func_8080008C_bsride();
    func_8080008C_bsride();
}

/* extern */

void func_808005D8_bsride(s32 arg0) {
    s32 baanim_playForDuration_loopSmooth(s32, s32, s32);
    void func_80800000_bsride(PlayerState *);
    func_80800000_bsride(arg0);
    baanim_playForDuration_loopSmooth(arg0, 0x83, 0x3FE66666);
}

/* extern */

void func_8080060C_bsride(void *arg0) {
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    void func_8008B10C(struct anctrl_s *, f32);
    void bs_setState(void *, s32);
    f32 _chhandcart_entrypoint_1(s32);
    struct anctrl_s *animCtrl;
    s32 next_state;

    animCtrl = baanim_getAnimCtrlPtr(arg0);
    next_state = 0;
    if ((*(s32 *)((s8 *)arg0 + 0x15C)) != 0) {
        func_8008B10C(animCtrl, _chhandcart_entrypoint_1(*(s32 *)((s8 *)arg0 + 0x15C)));
    } else {
        next_state = 0x2F;
    }
    bs_setState(arg0, next_state);
}

/* extern */

void func_8080066C_bsride(s32 arg0) {
    s32 func_80099B94(s32);
    s32 func_8009E6EC();
    s32 func_8009E830(s32, s32);
    s32 func_808000F0_bsride(s32);
    if (func_8009E6EC() == 0x28) {
        func_808000F0_bsride(arg0);
        func_8009E830(arg0, 2);
        return;
    }
    func_80099B94(arg0);
}

s32 bsride_entrypoint_2(s32 arg0) {
    extern s32 D_80800A80_bsride[];
    return ((s32 *)&D_80800A80_bsride)[arg0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ride/func_808006D0_bsride.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ride/func_80800798_bsride.s")

void func_8080084C_bsride(s32 arg0)
{
    func_808006D0_bsride(arg0,0);
    func_8080008C_bsride(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ride/func_80800878_bsride.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/ride/func_80800904_bsride.s")

s32 bsride_entrypoint_3(s32 arg0) {
    extern s32 D_80800A90_bsride[];
    return ((s32 *)&D_80800A90_bsride)[arg0];
}
