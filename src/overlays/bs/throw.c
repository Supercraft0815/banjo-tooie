#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/throw/bsthrow_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/throw/bsthrow_entrypoint_1.s")

/* extern */

void bsthrow_entrypoint_2(void *self) {
    s32 bastatetimer_set(void *, s32, f32);
    s32 bs_getNextState(void *);
    (*(s32 *)((s8 *)(self) + 0x15C)) = 0;
    if (bs_getNextState(self) == 1) {
        bastatetimer_set(self, 0, 0.14f);
        bastatetimer_set(self, 1, 0.28f);
    }
}

s32 bsthrow_entrypoint_3(s32 arg0) {
    extern s32 D_808002F0_bsthrow[];
    return ((s32 *)&D_808002F0_bsthrow)[arg0];
}

/* extern */

void bsthrow_entrypoint_4(void *arg0) {
    s32 func_8008E9AC(void *);
    s32 func_8008F6B8(void *, s32);
    s32 func_80099B94(void *);
    s32 func_8009E6EC();
    s32 func_8009E830(void *, s32);
    s32 temp_v0;

    temp_v0 = func_8009E6EC();
    switch (temp_v0) {
    case 18:
        if ((*(s32 *)((s8 *)(arg0) + (0x15C))) == 0) {
            func_8008F6B8(arg0, func_8008E9AC(arg0));
            return;
        }
        func_8009E830(arg0, 1);
        return;
    case 21:
    case 28:
    case 29:
    case 30:
    case 37:
        func_8009E830(arg0, 1);
        return;
    default:
        func_80099B94(arg0);
        return;
    }
}
