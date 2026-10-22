#include "common.h"

void func_80026BE0(ALVoice *arg0, s16 arg1, s32 arg2) {
    s32 *func_80021794(void);
    s32 func_80021928(s32);
    s32 func_8002B684(void *, s32, void *);
    extern s32 *D_800411F4;
    s32 *update;

    if (arg0->pvoice != NULL) {
        update = func_80021794();
        if (update == NULL) {
            return;
        }
        update[1] = *(s32 *)((u8 *)arg0->pvoice + 0x88) + D_800411F4[7];
        *(s16 *)(update + 2) = 0xB;
        update[3] = arg1;
        update[4] = func_80021928(arg2);
        update[0] = 0;
        func_8002B684(arg0->pvoice, 3, update);
    }
}
