#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/co/themedll/func_80800000_cothemedll.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/co/themedll/cothemedll_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/co/themedll/cothemedll_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/co/themedll/cothemedll_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/co/themedll/cothemedll_entrypoint_3.s")

/* extern */

void func_80800388_cothemedll(s32 arg0) {
    s32 func_800EA05C();
    s32 func_800FE870();
    s32 temp_v0;

    temp_v0 = func_800EA05C();
    switch (temp_v0) {                              /* switch 1; irregular */
    case 0xB8:                                      /* switch 1 */
    case 0xBB:                                      /* switch 1 */
    case 0xC6:                                      /* switch 1 */
    case 0xC8:                                      /* switch 1 */
    case 0xC9:                                      /* switch 1 */
        switch (arg0) {                             /* switch 2 */
        case 0xB8:                                  /* switch 2 */
        case 0xBB:                                  /* switch 2 */
        case 0xC6:                                  /* switch 2 */
        case 0xC8:                                  /* switch 2 */
        case 0xC9:                                  /* switch 2 */
            func_800FE870();
            return;
        default:                                    /* switch 2 */
            return;
        }
        break;
    case 0x127:                                     /* switch 1 */
    case 0x12D:                                     /* switch 1 */
    case 0x12E:                                     /* switch 1 */
    case 0x12F:                                     /* switch 1 */
    case 0x130:                                     /* switch 1 */
        switch (arg0) {                             /* switch 3 */
        case 0x127:                                 /* switch 3 */
        case 0x12D:                                 /* switch 3 */
        case 0x12E:                                 /* switch 3 */
        case 0x12F:                                 /* switch 3 */
        case 0x130:                                 /* switch 3 */
            func_800FE870();
            break;
        }
        break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/co/themedll/cothemedll_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/co/themedll/func_80800524_cothemedll.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/co/themedll/cothemedll_entrypoint_5.s")
