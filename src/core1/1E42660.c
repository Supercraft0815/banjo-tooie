#include "common.h"

void func_8002AB30(ALVoice *arg0, u8 arg1) {
    s32 *func_80021794(void);
    s32 func_8002B684(void *, s32, void *);
    extern s32 *D_800411F4;
    s32 *update;

    if (arg0->pvoice != NULL) {
        update = func_80021794();
        if (update == NULL) {
            return;
        }
        update[1] = *(s32 *)((u8 *)arg0->pvoice + 0x88) + D_800411F4[7];
        *(s16 *)(update + 2) = 0x11;
        update[3] = arg1;
        update[0] = 0;
        func_8002B684(arg0->pvoice, 3, update);
    }
}

s32 func_8002ABE0(u8 *arg0, u32 *arg1) {
    u32 i;
    u32 minimum = -1U;
    s32 elapsed = *(s32 *)(arg0 + 0x10);
    struct Values { u8 pad[0x158]; s32 values[1]; };

    if (*(u32 *)(arg0 + 4) == 0) {
        return 0;
    }
    for (i = 0; i < *(u32 *)(*(u8 **)arg0 + 4); i++) {
        if ((*(u32 *)(arg0 + 4) >> i) & 1) {
            if (*(s32 *)(arg0 + 0x14) != 0) {
                ((struct Values *)arg0)->values[i] -= elapsed;
            }
            if ((u32)((struct Values *)arg0)->values[i] < minimum) {
                minimum = ((struct Values *)arg0)->values[i];
            }
        }
    }
    *(s32 *)(arg0 + 0x14) = 0;
    *arg1 = minimum;
    return 1;
}
