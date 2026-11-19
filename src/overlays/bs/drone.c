#include "common.h"
#include "overlays/bs/drone.h"
#include "overlays/ba/drone.h"
#include "overlays/bs/drone/bubbled.h"
extern void _bsdronegoto_entrypoint_0(PlayerState *);
extern void _bsdronegoto_entrypoint_1(PlayerState *);
extern void _bsdronegoto_entrypoint_2(PlayerState *);
extern void _bsdronegoto_entrypoint_3(PlayerState *);
extern void _bsdronelook_entrypoint_1(PlayerState *);
extern void _bsdronelook_entrypoint_3(BtIntPtr arg0);
extern void _bsdronelook_entrypoint_0(PlayerState *);
extern void _bsdronelook_entrypoint_4(void);
extern void _bsdronesuckunder_entrypoint_1(PlayerState *);
extern void _bsdronesuckunder_entrypoint_3(PlayerState *);
extern void _bsdronesuckunder_entrypoint_0(s32 arg0);
extern void _bsdronesuckunder_entrypoint_2(BtIntPtr arg0);
extern void _bsdronexform_entrypoint_2(PlayerState *);
extern void _bsdronexform_entrypoint_3(PlayerState *);
extern void _bsdronexform_entrypoint_1(PlayerState *);
extern void func_80099AA8(PlayerState *);
extern void _bsdronevanish_entrypoint_0(PlayerState *);
extern void _bsdronevanish_entrypoint_1(PlayerState *);
extern void _bsdronevanish_entrypoint_2(PlayerState *);
extern void _bsdronebitten_entrypoint_1(PlayerState *);
extern void _bsdronebitten_entrypoint_3(PlayerState *);
extern void _bsdronebitten_entrypoint_0(s32 arg0);
extern void _bsdronebitten_entrypoint_7(PlayerState *);
extern void _bsdronebitten_entrypoint_9(PlayerState *);
extern void _bsdronebitten_entrypoint_6(PlayerState *);
extern void _bsdronebitten_entrypoint_8(PlayerState *);
extern void _bsdroneslide_entrypoint_0(PlayerState *);
extern void _bsdroneslide_entrypoint_1(PlayerState *);
extern void _bsdroneslide_entrypoint_2(BtIntPtr arg0);
extern void func_80099B94(PlayerState *);
extern void _bsdronejump_entrypoint_2(PlayerState *);
extern void _bsdronejump_entrypoint_4(BtIntPtr arg0);
extern void _bsdronejump_entrypoint_1(s32 arg0);
extern void _bsdronejump_entrypoint_3(PlayerState *);
extern void _bsdronefired_entrypoint_1(PlayerState *);
extern void _bsdronefired_entrypoint_3(BtIntPtr arg0);
extern void _bsdronefired_entrypoint_0(PlayerState *);
extern void _bsdronefired_entrypoint_2(PlayerState *);
extern void _bsdronewaitbabykaz_entrypoint_1(BtIntPtr arg0);
extern void _bsdronewaitbabykaz_entrypoint_3(s32 arg0);
extern void _bsdronewaitbabykaz_entrypoint_0(s32 arg0);
extern void _bsdronewaitbabykaz_entrypoint_2(PlayerState *);
extern void _bsdronefalldie_entrypoint_1(PlayerState *);
extern void _bsdronefalldie_entrypoint_3(PlayerState *);

int func_80800000_bsdrone(PlayerState *self) {
    int i;
    int type = _badrone_entrypoint_3(self);
    for (i = 0; D_80800180_bsdrone[i].type != 0; i++) {
        if (type == D_80800180_bsdrone[i].type) return i;
    }
    return 0;
}

void bsdrone_entrypoint_0(struct player_state_s *arg0) {

    _badrone_entrypoint_4(arg0);
    D_80800180_bsdrone[func_80800000_bsdrone(arg0)].init(arg0);
}

void bsdrone_entrypoint_1(struct player_state_s *arg0) {
    D_80800180_bsdrone[func_80800000_bsdrone(arg0)].update(arg0);
}

void bsdrone_entrypoint_2(struct player_state_s *arg0) {
    D_80800180_bsdrone[func_80800000_bsdrone(arg0)].end(arg0);
}

void bsdrone_entrypoint_3(struct player_state_s *arg0) {
    void (*temp_v1)(struct player_state_s *);
    temp_v1 = D_80800180_bsdrone[func_80800000_bsdrone(arg0)].interrupt;
    if (temp_v1 != NULL) {
        temp_v1(arg0);
    }
}
#include "drone_data.inc"
