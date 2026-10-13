#include "common.h"

/* extern */

struct player_state_s;

void bsdronelook_entrypoint_0(struct player_state_s *arg0) {
    s32 _bafpctrl_entrypoint_13(struct player_state_s *, s32);
    void _bafpctrl_entrypoint_17(struct player_state_s *);
    s32 _bafpctrl_entrypoint_4(struct player_state_s *);
    s32 _bafpctrl_entrypoint_6(struct player_state_s *);
    s32 func_800A4EC8(void *);
    if (_bafpctrl_entrypoint_4(arg0) == 2) {
        _bafpctrl_entrypoint_13(arg0, 1);
    }
    if (_bafpctrl_entrypoint_6(arg0) != 0) {
        func_800A4EC8(arg0);
        _bafpctrl_entrypoint_17(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/look/bsdronelook_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/look/bsdronelook_entrypoint_2.s")

/* extern */

void bsdronelook_entrypoint_3(s32 arg0) {
    s32 _badata_entrypoint_34(s32);
    s32 _bafpctrl_entrypoint_4();
    s32 bs_setState(s32, s32);
    s32 func_800A3404(s32);
    s32 sp1C;

    sp1C = 0;
    if ((_bafpctrl_entrypoint_4() != 3) && (func_800A3404(arg0) == 0)) {
        sp1C = _badata_entrypoint_34(arg0);
    }
    bs_setState(arg0, sp1C);
}

/* extern */

void bsdronelook_entrypoint_4(void) {
    s32 func_80099B94();
    func_80099B94();
}
