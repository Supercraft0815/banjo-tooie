#include "common.h"
#include "overlays/bs/drone.h"
#include "overlays/ba/drone.h"
#ifdef BT_NATIVE
#include "native_drone_states.h"
#endif

int func_80800000_bsdrone(PlayerState *self) {
#ifndef BT_NATIVE
    typedef struct { u8 type; u8 padding[0x13]; } DroneState;
    extern DroneState D_80800180_bsdrone[];
#endif
    int i;
    int type = _badrone_entrypoint_3(self);
    for (i = 0; D_80800180_bsdrone[i].type != 0; i++) {
        if (type == D_80800180_bsdrone[i].type) return i;
    }
    return 0;
}

void bsdrone_entrypoint_0(struct player_state_s *arg0) {
#ifndef BT_NATIVE
    extern struct {
        void (*callback)(struct player_state_s *);
        u8 padding[0x10];
    } D_80800184_bsdrone[];
#endif

    _badrone_entrypoint_4(arg0);
#ifdef BT_NATIVE
    D_80800180_bsdrone[func_80800000_bsdrone(arg0)].init(arg0);
#else
    D_80800184_bsdrone[func_80800000_bsdrone(arg0)].callback(arg0);
#endif
}

void bsdrone_entrypoint_1(struct player_state_s *arg0) {
#ifdef BT_NATIVE
    D_80800180_bsdrone[func_80800000_bsdrone(arg0)].update(arg0);
#else
    extern struct {
        void (*callback)(struct player_state_s *);
        u8 padding[0x10];
    } D_80800188_bsdrone[];

    D_80800188_bsdrone[func_80800000_bsdrone(arg0)].callback(arg0);
#endif
}

void bsdrone_entrypoint_2(struct player_state_s *arg0) {
#ifdef BT_NATIVE
    D_80800180_bsdrone[func_80800000_bsdrone(arg0)].end(arg0);
#else
    extern struct {
        void (*callback)(struct player_state_s *);
        u8 padding[0x10];
    } D_8080018C_bsdrone[];

    D_8080018C_bsdrone[func_80800000_bsdrone(arg0)].callback(arg0);
#endif
}

void bsdrone_entrypoint_3(struct player_state_s *arg0) {
#ifndef BT_NATIVE
    extern struct {
        void (*callback)(struct player_state_s *);
        u8 padding[0x10];
    } D_80800190_bsdrone[];
#endif
    void (*temp_v1)(struct player_state_s *);

#ifdef BT_NATIVE
    temp_v1 = D_80800180_bsdrone[func_80800000_bsdrone(arg0)].interrupt;
#else
    temp_v1 = D_80800190_bsdrone[func_80800000_bsdrone(arg0)].callback;
#endif
    if (temp_v1 != NULL) {
        temp_v1(arg0);
    }
}
