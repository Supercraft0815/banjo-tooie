#include "common.h"

u32 func_800FE890(void);

s32 func_80800000_cothemedll(s32 arg0) {
    s32 func_800DA298(s32);
    extern s16 D_80800730_cothemedll[][3];
    extern s16 D_80800D34_cothemedll[][3];
    s32 var_s1;
    s32 var_a1;

    var_s1 = arg0;
    for (var_a1 = 0; D_80800D34_cothemedll[var_a1][0] != 0; var_a1++) {
        if ((var_s1 == D_80800D34_cothemedll[var_a1][0]) && (func_800DA298(D_80800D34_cothemedll[var_a1][2]) != 0)) {
            var_s1 = D_80800D34_cothemedll[var_a1][1];
        }
    }
    for (var_a1 = 0; D_80800730_cothemedll[var_a1][0] != 0; var_a1++) {
        if (var_s1 == D_80800730_cothemedll[var_a1][0]) {
            return var_a1;
        }
    }
    return 0;
}

void cothemedll_entrypoint_0(s32 arg0) {
    s32 func_80800000_cothemedll(s32);
    extern s16 D_80800732_cothemedll[];
    s32 temp_t7;
    if (func_800FE890() == 0) {
        temp_t7 = *(s16 *)((s8 *)D_80800732_cothemedll + func_80800000_cothemedll(arg0) * 6) >> 2;
        if (temp_t7 != -1) func_80016DA0(temp_t7, 1);
    }
}

s16 cothemedll_entrypoint_1(void) {
    s32 func_80800000_cothemedll();
    extern s16 D_80800734_cothemedll[];
    return *(s16 *)((s8 *)D_80800734_cothemedll + func_80800000_cothemedll() * 6);
}

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

void cothemedll_entrypoint_4(void *arg0, s32 arg1) {
    s32 func_800DA298(s32);
    void func_800FC2C4(s32, s32);
    u32 func_800FDC28(u32);
    void func_800FE3EC(void);
    s32 func_80800000_cothemedll(s32);
    extern s16 D_80800732_cothemedll[];
    s32 theme;
    (*(s8 *)((s8 *)(arg0) + (0x12))) = 1;
    if (func_800DA298(0x674) == 0) {
        func_800FDC28(0);
    }
    func_80800388_cothemedll(arg1);
    if (func_800FE890() == 0) {
        theme = *(s16 *)((s8 *)D_80800732_cothemedll + func_80800000_cothemedll(arg1) * 6);
        if (((theme >> 2) != (*(s16 *)((s8 *)(arg0) + (8)))) || ((*(u8 *)((s8 *)(arg0) + (0x41))) != 0)) {
            func_800FC2C4(0, 0x7D0);
            func_800FE3EC();
        } else {
            (*(s8 *)((s8 *)(arg0) + (0xE))) = 1;
        }
    }
    (*(u8 *)((s8 *)(arg0) + (0x41))) = 1U;
}

/* extern */

void func_80800524_cothemedll(void *arg0, s32 arg1) {
    s32 func_800FC884();
    s32 func_800FCCD4(s16);
    s32 func_800FE89C();
    s16 temp_a0;

    if (arg1 != 0) {
        func_800FC884();
    }
    temp_a0 = (*(s16 *)((s8 *)(arg0) + (8)));
    if ((temp_a0 != -1) && (func_800FCCD4(temp_a0) == 0)) {
        func_800FE89C();
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/co/themedll/cothemedll_entrypoint_5.s")
