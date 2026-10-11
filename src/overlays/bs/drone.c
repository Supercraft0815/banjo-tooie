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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/bsdrone_entrypoint_3.s")
