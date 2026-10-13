#include "common.h"

int func_80800000_bsdrone(void) {
    typedef struct { u8 type; u8 padding[0x13]; } DroneState;
    s32 _badrone_entrypoint_3(void);
    extern DroneState D_80800180_bsdrone[];
    int i;
    int type = _badrone_entrypoint_3();
    for (i = 0; D_80800180_bsdrone[i].type != 0; i++) {
        if (type == D_80800180_bsdrone[i].type) return i;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/bsdrone_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/bsdrone_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/bsdrone_entrypoint_2.s")

void bsdrone_entrypoint_3(struct player_state_s *arg0) {
    extern struct {
        void (*callback)(struct player_state_s *);
        u8 padding[0x10];
    } D_80800190_bsdrone[];
    void (*temp_v1)(struct player_state_s *);

    temp_v1 = D_80800190_bsdrone[func_80800000_bsdrone()].callback;
    if (temp_v1 != NULL) {
        temp_v1(arg0);
    }
}
