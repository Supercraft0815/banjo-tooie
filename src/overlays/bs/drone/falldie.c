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

void bsdronefalldie_entrypoint_0(s32 arg0) {
    s32 func_800961AC(s32, s32);
    s32 func_80092880(s32, s32);
    func_800961AC(arg0, 0x1);
    func_80092880(arg0, 0x1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/bs/drone/falldie/bsdronefalldie_entrypoint_1.s")

/* extern */

void bsdronefalldie_entrypoint_2(s32 arg0) {
    s32 func_80099AA8(s32);
    s32 func_8009E6EC();
    if (func_8009E6EC() != 0x91) {
        func_80099AA8(arg0);
    }
}

void bsdronefalldie_entrypoint_3(void *arg0) {
    s32 _badata_entrypoint_16(void);
    s32 func_800FCCD4(s32);

    switch (*(s32 *)((s8 *)arg0 + 0x190)) {
        case 1:
            if (func_800FCCD4(_badata_entrypoint_16()) == 0) {
                func_80800000_bsdronefalldie(arg0, 2);
            }
        case 2:
            return;
    }
}
