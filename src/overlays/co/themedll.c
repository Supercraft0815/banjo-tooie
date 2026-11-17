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
    extern s16 D_80800730_cothemedll[][3];
    s32 temp_t7;
    if (func_800FE890() == 0) {
        temp_t7 = D_80800730_cothemedll[func_80800000_cothemedll(arg0)][1] >> 2;
        if (temp_t7 != -1) func_80016DA0(temp_t7, 1);
    }
}

s16 cothemedll_entrypoint_1(BT_PARAM_OR_VOID(s32 bt_a0)) {
    s32 func_80800000_cothemedll();
    extern s16 D_80800730_cothemedll[][3];
#ifdef BT_NATIVE
    return D_80800730_cothemedll[func_80800000_cothemedll(BT_NATIVE_ONLY(bt_a0))][2];
#else
    return D_80800730_cothemedll[func_80800000_cothemedll()][2];
#endif
}    typedef struct { u8 pad0[0x4]; f32 unk4; s16 unk8; s16 unkA; s16 unkC; s8 unkE; u8 padF[0x1]; u8 unk10; u8 unk11; s8 unk12; s8 unk13; s8 unk14; s8 unk15; u8 unk16; u8 pad17[0x5]; s32 unk1C; s16 unk20; s16 unk22; s16 unk24; u8 pad26[0x2]; s32 unk28; s32 unk2C; u8 pad30[0x11]; s8 unk41; } Objthemedll_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void cothemedll_entrypoint_2(void *arg0, s32 arg1) {
    void func_80016DF8(s32);
    s32 func_800DA9E4(s32, s32);
    void func_800FC74C(u32);
    s32 func_800FCCD4(s32);
    u32 func_800FDC28(u32);
    void func_800FEDC4(s32, s32, f32, f32);
    extern s16 D_80800730_cothemedll[][3];
    s32 track;
    s32 i;

    if (func_800FE890() == 0) {
        track = D_80800730_cothemedll[func_80800000_cothemedll(arg1)][1] >> 2;
        if (track != -1) {
            if (func_800FCCD4(track) != 0) {
                func_800FC74C(track);
            }
            func_80016DF8(track);
        }
    }
    if (func_800DA9E4(0x674, 0) == 0) {
        func_800FDC28(0);
    }
    if (func_800DA9E4(0x675, 0) == 0) {
        i = 0;
        do {
            func_800FEDC4(i, 0, 1.0f, 0.0f);
            i++;
        } while (i != 2);
    }
    ((Objthemedll_arg0 *)arg0)->unk41 = 1;
}    typedef struct { u8 pad0[0x2]; u16 unk2; } Objthemedll_cothemedll_entrypoint_3_temp_v0_2; /* offsets.py genstruct: fields from raw offsets on temp_v0_2; rename once understood */

void cothemedll_entrypoint_3(void *arg0) {
    u32 func_80017764(s32);
    s32 func_800EA05C();
    s32 func_80800000_cothemedll(s32);
    extern s16 D_80800730_cothemedll[][3];
    extern s16 D_80800CB4_cothemedll[][2];
    s32 sp24;
    s32 sp20;
    s16 *var_v0;
    s16 temp_a0;
    s32 var_v1;
    s32 temp_v0;
    void *temp_v0_2;

    temp_v0 = func_800EA05C();
    sp24 = temp_v0;
    sp20 = func_80800000_cothemedll(temp_v0);
    (((Objthemedll_arg0 *)arg0)->unk41) = 0;
    (((Objthemedll_arg0 *)arg0)->unk28) = -1;
    (((Objthemedll_arg0 *)arg0)->unk2C) = -1;
    (((Objthemedll_arg0 *)arg0)->unk10) = 0xFF;
    (((Objthemedll_arg0 *)arg0)->unk11) = 0xFF;
    if (func_800FE890() != 2) {
        (((Objthemedll_arg0 *)arg0)->unk1C) = 0;
        (((Objthemedll_arg0 *)arg0)->unk22) = 0;
        (((Objthemedll_arg0 *)arg0)->unk20) = 0;
        (((Objthemedll_arg0 *)arg0)->unk12) = 0;
        (((Objthemedll_arg0 *)arg0)->unk13) = 0;
        (((Objthemedll_arg0 *)arg0)->unk14) = 1;
        (((Objthemedll_arg0 *)arg0)->unk15) = 1;
        (((Objthemedll_arg0 *)arg0)->unk4) = 1.0f;
        if ((((Objthemedll_arg0 *)arg0)->unk16) != 0) {
            temp_v0_2 = D_80800730_cothemedll[sp20];
            (((Objthemedll_arg0 *)arg0)->unkC) = (s16) ((((Objthemedll_cothemedll_entrypoint_3_temp_v0_2 *)temp_v0_2)->unk2) & 3);
            (((Objthemedll_arg0 *)arg0)->unk8) = (s16) ((s16) (((Objthemedll_cothemedll_entrypoint_3_temp_v0_2 *)temp_v0_2)->unk2) >> 2);
            if ((((Objthemedll_arg0 *)arg0)->unk8) != -1) {
                (((Objthemedll_arg0 *)arg0)->unkA) = func_80017764((((Objthemedll_arg0 *)arg0)->unk8));
            } else {
                (((Objthemedll_arg0 *)arg0)->unkA) = 0x4E20;
            }
            (((Objthemedll_arg0 *)arg0)->unk24) = 0;
            for (var_v1 = 0; D_80800CB4_cothemedll[var_v1][0] != -1; var_v1++) {
                if (sp24 == D_80800CB4_cothemedll[var_v1][0]) {
                    (((Objthemedll_arg0 *)arg0)->unk20) = D_80800CB4_cothemedll[var_v1][1];
                }
            }
        }
    }
}

/* extern */

void func_80800388_cothemedll(s32 arg0) {
    s32 func_800EA05C();
    void func_800FE870();
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
    extern s16 D_80800730_cothemedll[][3];
    s32 theme;
    (*(s8 *)((s8 *)(arg0) + (0x12))) = 1;
    if (func_800DA298(0x674) == 0) {
        func_800FDC28(0);
    }
    func_80800388_cothemedll(arg1);
    if (func_800FE890() == 0) {
        theme = D_80800730_cothemedll[func_80800000_cothemedll(arg1)][1];
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
    void func_800FC884(void);
    s32 func_800FCCD4(s32);
    void func_800FE89C(void);
    s16 temp_a0;

    if (arg1 != 0) {
        func_800FC884();
    }
    temp_a0 = (((Objthemedll_arg0 *)arg0)->unk8);
    if ((temp_a0 != -1) && (func_800FCCD4(temp_a0) == 0)) {
        func_800FE89C();
    }
}

void cothemedll_entrypoint_5(void *arg0, s32 arg1, s32 arg2) {
    void func_800FC348(u32, u32, u32);
    void func_800FEC60(u32);
    void func_800FECB8(u32);
    void **arg = &arg0;

    if (arg1 == 1) {
        func_800FC348(-1, 0xFA0, 4);
        func_800FECB8(2);
    }
    switch (arg2) {
        case 1:
            func_800FC348(0, 0xFA0, 4);
            func_800FEC60(2);
            break;
        case 0:
        case 2:
            if (*(u8 *)((s8 *)*arg + 0xE) == 0) {
                if (*(s16 *)((s8 *)*arg + 0xC) & 1) {
                    func_80800524_cothemedll(*arg, 0);
                } else {
                    func_80800524_cothemedll(*arg, 1);
                }
            } else {
                *(u8 *)((s8 *)*arg + 0xE) = 0;
            }
            break;
    }
}
/* data_to_c.py: from asm/data/overlays/co/themedll.data.s */
s16 D_80800730_cothemedll [235] [ 3 ] BT_DATA(4, overlays_co_themedll, 0x0) = { { 161, 493, 0 }, { 162, 493, 0 }, { 163, 493, 0 }, { 164, 493, 0 }, { 165, 493, 0 }, { 166, 493, 0 }, { 167, 493, 0 }, { 395, 500, 0 }, { 403, -4, 0 }, { 168, 493, 0 }, { 169, 493, 0 }, { 170, 493, 0 }, { 171, 493, 0 }, { 172, 493, 0 }, { 396, -4, 0 }, { 397, -4, 0 }, { 404, -4, 0 }, { 405, -4, 0 }, { 398, -4, 0 }, { 399, -4, 0 }, { 406, -4, 0 }, { 407, -4, 0 }, { 400, -4, 0 }, { 408, -4, 0 }, { 382, -4, 0 }, { 409, -4, 0 }, { 401, -4, 0 }, { 402, -4, 0 }, { 412, 520, 0 }, { 413, 520, 0 }, { 359, -4, 0 }, { 360, -4, 0 }, { 361, -4, 0 }, { 362, -4, 0 }, { 173, 208, 0 }, { 174, 201, 2 }, { 175, 201, 1 }, { 371, 204, 0 }, { 321, 201, 2 }, { 344, 412, 0 }, { 184, 229, 3 }, { 185, 229, 3 }, { 186, 229, 6 }, { 187, 229, 5 }, { 198, 229, 8 }, { 200, 229, 8 }, { 201, 229, 8 }, { 188, 229, 6 }, { 196, 229, 3 }, { 197, 229, 6 }, { 182, 220, 0 }, { 183, 104, 0 }, { 375, 229, 6 }, { 376, 229, 6 }, { 377, 229, 6 }, { 378, 229, 6 }, { 383, 229, 8 }, { 199, 249, 11 }, { 202, 249, 12 }, { 203, 249, 14 }, { 204, 249, 12 }, { 205, 249, 12 }, { 206, 249, 13 }, { 207, 249, 13 }, { 208, 249, 14 }, { 209, 249, 13 }, { 210, 249, 12 }, { 211, 249, 13 }, { 212, 249, 17 }, { 215, 249, 12 }, { 216, 249, 17 }, { 218, 249, 12 }, { 219, 249, 12 }, { 220, 532, 69 }, { 355, 249, 12 }, { 217, 104, 0 }, { 233, 220, 0 }, { 289, 249, 14 }, { 367, 249, 11 }, { 368, 249, 11 }, { 214, 257, 19 }, { 292, 257, 19 }, { 213, 220, 0 }, { 221, 257, 26 }, { 222, 257, 26 }, { 223, 257, 26 }, { 224, 257, 26 }, { 390, 257, 26 }, { 225, 257, 20 }, { 315, 257, 20 }, { 226, 257, 28 }, { 227, 257, 28 }, { 228, 257, 28 }, { 379, 257, 28 }, { 229, 257, 28 }, { 380, 257, 28 }, { 230, 257, 22 }, { 316, 257, 22 }, { 231, 257, 24 }, { 234, 257, 24 }, { 235, 257, 24 }, { 236, 257, 24 }, { 249, 257, 23 }, { 374, 104, 0 }, { 237, 277, 31 }, { 238, 277, 31 }, { 239, 104, 0 }, { 241, -4, 0 }, { 244, 277, 29 }, { 246, 277, 29 }, { 247, 277, 29 }, { 248, 277, 29 }, { 250, 277, 29 }, { 252, 277, 29 }, { 255, 277, 31 }, { 288, 220, 0 }, { 293, 277, 29 }, { 294, 277, 29 }, { 385, 277, 29 }, { 386, 277, 29 }, { 423, 277, 29 }, { 422, 277, 29 }, { 424, 277, 29 }, { 425, 277, 29 }, { 274, 329, 38 }, { 275, 296, 0 }, { 276, 329, 38 }, { 277, 329, 39 }, { 278, 329, 39 }, { 279, 329, 39 }, { 280, 329, 39 }, { 281, 329, 39 }, { 282, 329, 38 }, { 283, 329, 39 }, { 286, 220, 0 }, { 290, 220, 0 }, { 291, 329, 39 }, { 387, 329, 39 }, { 369, 104, 0 }, { 256, 253, 41 }, { 257, 253, 42 }, { 258, 253, 42 }, { 259, 253, 42 }, { 260, 253, 43 }, { 261, 253, 43 }, { 262, 253, 42 }, { 263, 253, 42 }, { 264, 253, 42 }, { 265, 253, 42 }, { 266, 253, 42 }, { 267, 253, 42 }, { 268, 253, 43 }, { 269, 253, 43 }, { 270, 253, 43 }, { 271, 253, 43 }, { 272, 253, 43 }, { 273, 253, 43 }, { 287, 220, 0 }, { 370, 104, 0 }, { 381, 253, 42 }, { 354, 537, 0 }, { 391, 253, 43 }, { 295, 261, 44 }, { 296, 261, 47 }, { 297, 261, 45 }, { 298, 261, 48 }, { 299, 261, 45 }, { 300, 261, 48 }, { 301, 261, 45 }, { 305, 309, 0 }, { 306, 261, 48 }, { 307, 261, 45 }, { 308, 104, 0 }, { 309, 220, 0 }, { 384, 260, 45 }, { 302, 260, 45 }, { 303, 260, 45 }, { 304, 260, 45 }, { 310, 349, 50 }, { 311, 349, 53 }, { 312, 349, 54 }, { 313, 349, 54 }, { 314, 349, 51 }, { 317, 349, 52 }, { 318, 104, 0 }, { 319, 104, 0 }, { 320, 220, 0 }, { 389, 349, 53 }, { 353, 349, 50 }, { 392, 349, 54 }, { 349, 469, 57 }, { 350, 469, 58 }, { 351, 505, 0 }, { 352, 469, 58 }, { 393, 505, 0 }, { 394, 469, 57 }, { 410, 469, 57 }, { 322, 357, 55 }, { 323, 392, 0 }, { 324, 369, 0 }, { 411, 373, 0 }, { 325, 361, 0 }, { 326, 361, 0 }, { 327, 361, 0 }, { 328, 361, 0 }, { 329, 361, 0 }, { 330, 361, 0 }, { 331, 361, 0 }, { 332, 361, 0 }, { 333, 361, 0 }, { 334, 361, 0 }, { 335, 353, 59 }, { 338, 353, 59 }, { 340, 353, 59 }, { 341, 353, 59 }, { 346, 353, 59 }, { 348, 353, 59 }, { 336, 508, 0 }, { 337, 377, 0 }, { 339, 381, 0 }, { 343, 220, 0 }, { 342, 104, 0 }, { 347, 201, 2 }, { 356, 537, 0 }, { 357, 532, 69 }, { 358, 229, 6 }, { 389, 348, 53 }, { -6, 257, 24 }, { -7, 249, 12 }, { -8, 253, 42 }, { -9, 329, 38 }, { -10, 353, 59 }, { -11, 261, 45 }, { -12, 261, 48 }, { 0, 0, 0 } };
s16 D_80800CB4_cothemedll [32] [ 2 ] BT_DATA(4, overlays_co_themedll, 0x584) = { { 214, 1 }, { 423, 17 }, { 422, 22 }, { 424, 18 }, { 425, 19 }, { 244, 5 }, { 246, 5 }, { 247, 5 }, { 250, 5 }, { 252, 5 }, { 248, 6 }, { 231, 7 }, { 241, 8 }, { 294, 11 }, { 293, 10 }, { 385, 9 }, { 386, 9 }, { 187, 13 }, { 184, 14 }, { 198, 12 }, { 200, 12 }, { 201, 12 }, { 302, 12 }, { 303, 12 }, { 304, 12 }, { 295, 20 }, { 384, 12 }, { 301, 23 }, { 349, 21 }, { 322, 15 }, { 341, 16 }, { -1, 0 } };
s16 D_80800D34_cothemedll [15] [ 3 ] BT_DATA(4, overlays_co_themedll, 0x604) = { { 208, -6, 1262 }, { 208, -7, 1261 }, { 208, -8, 1263 }, { 208, -9, 1264 }, { 208, -10, 1267 }, { 208, -11, 1266 }, { 208, -12, 1265 }, { 289, -6, 1262 }, { 289, -7, 1261 }, { 289, -8, 1263 }, { 289, -9, 1264 }, { 289, -10, 1267 }, { 289, -11, 1266 }, { 289, -12, 1265 }, { 0, 0, 0 } };
