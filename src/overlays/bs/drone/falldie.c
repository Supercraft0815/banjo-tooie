#include "common.h"

/* extern */

void func_80800000_bsdronefalldie(void *arg0, s32 arg1) {
    s32 _basudie_entrypoint_0();
    if (arg1 == 2) {
        _basudie_entrypoint_0();
    }
    (*(s32 *)((s8 *)(arg0) + (0x190))) = arg1;
}

/* extern */

void bsdronefalldie_entrypoint_0(BT_IDO_ONLY(BtIntPtr) BT_NATIVE_ONLY(struct player_state_s *) arg0) {
    void func_800961AC(void *arg0, s32 arg1);
    void func_80092880(void *arg0, s32 arg1);
    func_800961AC(arg0, 0x1);
    func_80092880(arg0, 0x1);
}

struct player_state_s;
struct anctrl_s;

void bsdronefalldie_entrypoint_1(struct player_state_s *arg0) {
    void _basudie_entrypoint_1(struct player_state_s *);
    struct anctrl_s *baanim_getAnimCtrlPtr(struct player_state_s *);
    void _badata_entrypoint_6(struct player_state_s *, s32 *, f32 *, f32 *, f32 *);
    void anctrl_reset(struct anctrl_s *);
    void anctrl_setIndex();
    void anctrl_setDuration(struct anctrl_s *, f32);
    void anctrl_setStart(struct anctrl_s *, f32);
    void anctrl_setSubrange(struct anctrl_s *, f32, f32);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_start(struct anctrl_s *);
    void func_8009FFD8();
    void func_800A0180(struct player_state_s *);
    void func_800A4DFC(struct player_state_s *, s32);
    void func_80098B4C(void *, s32);
    void func_800961AC(void *arg0, s32 arg1);
    void func_80092880(void *arg0, s32 arg1);
    struct anctrl_s *control;
    f32 end;
    f32 start;
    f32 duration;
    s32 index;

    _basudie_entrypoint_1(arg0);
    control = baanim_getAnimCtrlPtr(arg0);
    _badata_entrypoint_6(arg0, &index, &duration, &start, &end);
    if (start == end) {
        anctrl_reset(control);
        anctrl_setIndex(control, index);
        anctrl_setDuration(control, duration);
        anctrl_setStart(control, start);
        anctrl_setSubrange(control, start, end);
        anctrl_setPlaybackType(control, 1);
        anctrl_start(control);
    } else {
        anctrl_reset(control);
        anctrl_setIndex(control, index);
        anctrl_setDuration(control, duration);
        anctrl_setSubrange(control, start, end);
        anctrl_setPlaybackType(control, 4);
        anctrl_start(control);
    }
    func_8009FFD8(arg0, 1, 1, 3, 2);
    func_800961AC(arg0, 6);
    func_800A0180(arg0);
    func_800A4DFC(arg0, 5);
    func_80098B4C(arg0, 0);
    func_80092880(arg0, 0);
    *(s32 *)((s8 *)arg0 + 0x190) = 0;
    func_80800000_bsdronefalldie(arg0, 1);
}

/* extern */

void bsdronefalldie_entrypoint_2(BT_IDO_ONLY(BtIntPtr) BT_NATIVE_ONLY(struct player_state_s *) arg0) {
    void func_80099AA8(void *arg0);
    s32 func_8009E6EC();
    if (func_8009E6EC(BT_NATIVE_ONLY(arg0)) != 0x91) {
        func_80099AA8(arg0);
    }
}    typedef struct { u8 pad0[0x190]; s32 unk190; } Objfalldie_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void bsdronefalldie_entrypoint_3(BT_IDO_ONLY(void *) BT_NATIVE_ONLY(struct player_state_s *) arg0) {
    s32 _badata_entrypoint_16(void);
    s32 func_800FCCD4(s32);

    switch (((Objfalldie_arg0 *)arg0)->unk190) {
        case 1:
            if (func_800FCCD4(_badata_entrypoint_16()) == 0) {
                func_80800000_bsdronefalldie(arg0, 2);
            }
        case 2:
            return;
    }
}
