#include "core2/1E82660.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E82660/func_800A8D70.s")

void func_800A8E9C(void) {
    extern s16 D_801276D0;
    extern s16 D_801276F0;
    s32 func_8010FC38(u8 *);
    s16 *var_s0;
    s32 temp_a0;
    var_s0 = &D_801276D0; do { temp_a0 = *(s32 *)((u8 *)var_s0 + 0x58); if (temp_a0 != 0) { func_8010FC38((u8 *)temp_a0); } var_s0 += 2; } while (var_s0 != &D_801276F0);
}

void func_800A8EF0(s32 arg0, s32 arg1) {
    extern s16 D_801276D0;
    extern s16 D_801276F0;
    void func_8010FAEC(s32, void *);
    s32 *var_s0;
    void *temp_a1;

    var_s0 = (s32 *)&D_801276D0; do {
        temp_a1 = *(void **)((u8 *)var_s0 + 0x58);
        if ((temp_a1 != 0) && (arg1 == var_s0[6])) {
            func_8010FAEC(arg0, temp_a1);
        }
        var_s0++;
    } while (var_s0 != (s32 *)&D_801276F0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E82660/func_800A8F68.s")

/* extern */

s32 func_800A8FDC(void) {
    extern s16 D_801276D0;
    extern s16 D_801276D2;
    s32 func_800A877C(s16);
    s16 *ptr;
    func_800A877C(D_801276D2);
    ptr = &D_801276D0;
    return ptr[1]++;
}

s32 func_800A9010(void) {
    extern u8 D_801276D4;
    extern u8 D_801276D5;
    extern u8 D_801276D6;
    extern u8 D_801276D7;
    if (D_801276D4 == 0) {
        return 0;
    }
    if (D_801276D5 == 0) {
        return 1;
    }
    if (D_801276D6 == 0) {
        return 2;
    }
    if (D_801276D7 == 0) {
        return 3;
    }
    return -1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E82660/func_800A907C.s")

/* extern */

void func_800A91A8(s32 arg0) {
    extern s16 D_801276D0;
    s32 func_800A88C4();
    s16 temp_a0;

    if (arg0 >= 0) {
        temp_a0 = (*(s16 *)((s8 *)(&(&D_801276D0)[arg0]) + (8)));
        if (temp_a0 != -1) {
            func_800A88C4(temp_a0, (*(s32 *)((s8 *)&D_801276D0 + (arg0 * 4) + 0x38)), arg0);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E82660/func_800A91F4.s")

void func_800A92A8(s32 arg0, s32 arg1) {
    extern s16 D_801276D0;
    extern s16 D_801276F0;
    void func_8010FE00(void *, s32, s32);
    s32 *var_s0;
    s32 temp_a0;

    var_s0 = (s32 *)&D_801276D0; do {
        temp_a0 = var_s0[0x16];
        if (temp_a0 != 0) {
            func_8010FE00((void *)temp_a0, arg0, arg1);
        }
        var_s0++;
    } while (var_s0 != (s32 *)&D_801276F0);
}

void func_800A9318(s32 arg0) {
    extern s16 D_801276D0;
    extern s16 D_801276F0;
    s32 func_8010FE34(s32, s32);
    s32 *var_s0;
    s32 temp_a0;

    var_s0 = (s32 *)&D_801276D0; do {
        temp_a0 = var_s0[0x16];
        if (temp_a0 != 0) {
            func_8010FE34(temp_a0, arg0);
        }
        var_s0++;
    } while (var_s0 != (s32 *)&D_801276F0);
}

void func_800A9378(void) {
    extern s16 D_801276D0;
    s32 func_800A9420(s32);
    void func_80110164(u8 *);
    u8 **var_s1;
    s32 var_s0;

    var_s0 = 0; var_s1 = (u8 **)&D_801276D0; do {
        if ((var_s1[0x16] != 0) && (func_800A9420(var_s0) != 0)) {
            func_80110164(var_s1[0x16]);
        }
        var_s0 += 1;
        var_s1 += 1;
    } while (var_s0 != 8);
}

s32 func_800A93E4(s32 arg0) {
    extern s32 D_80127728[];
    return ((s32 *)&D_80127728)[arg0];
}

s32 func_800A93F8(s32 arg0) {
    extern s32 D_80127708[];
    return ((s32 *)&D_80127708)[arg0];
}

s32 func_800A940C(s32 arg0) {
    extern s32 D_801276E8[];
    return ((s32 *)&D_801276E8)[arg0];
}

s32 func_800A9420(s32 arg0) {
    extern s16 D_801276D0;
    s32 func_800A8984(s32);
    return *(s32 *)((u8 *)&D_801276D0 + arg0 * 4 + 0x38) ==
        func_800A8984(*(s32 *)((u8 *)&D_801276D0 + arg0 * 4 + 0x18));
}

s32 func_800A9460(void) {
    extern s16 D_801276D0;
    return *(s16 *)((u8 *)&D_801276D0 + 0);
}

s32 func_800A946C(void) {
    extern s16 D_801276D2;
    return *(s16 *)((u8 *)&D_801276D2 + 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E82660/func_800A9478.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E82660/func_800A9514.s")

void func_800A95C4(void) {
    extern s16 D_801276D0;
    extern s16 D_801276F0;
    s32 func_800A88C4();
    s32 func_800A8984(s32);
    void *func_800CA384(void *);
    void *func_80110068(void *, s32);
    s32 *var_s0;
    s32 *end;
    s32 old;
    void *temp;

    var_s0 = (s32 *)&D_801276D0; end = (s32 *)&D_801276F0;
    do {
        old = var_s0[14];
        if (old != 0) {
            var_s0[14] = (s32)func_800CA384((void *)var_s0[14]);
            if (var_s0[14] != old && func_800A8984(var_s0[6]) == old) {
                func_800A88C4(var_s0[6], var_s0[14]);
            }
        }
        temp = *(void **)(var_s0 + 22);
        if (temp != NULL) {
            *(void **)(var_s0 + 22) = func_80110068(temp, var_s0[14]);
        }
        var_s0++;
    } while (var_s0 != end);
}

s32 func_800A965C(void) {
    extern s16 D_801276D2;
    return 4 - D_801276D2;
}

s32 func_800A9670(s32 *arg0) { extern u8 D_801276D4; extern u8 D_801276D5; extern u8 D_801276D6; extern u8 D_801276D7; s32 var_v1; var_v1 = 0; if (D_801276D4 == 0) { *arg0 = 0; var_v1 = 1; } if (D_801276D5 == 0) { arg0[var_v1] = 1; var_v1 += 1; } if (D_801276D6 == 0) { arg0[var_v1] = 2; var_v1 += 1; } if (D_801276D7 == 0) { arg0[var_v1] = 3; var_v1 += 1; } return var_v1; }

s32 func_800A96F0(s32 arg0) {
    extern s16 D_801276D0;
    s16 *var_v0;
    s32 var_v1;

    var_v0 = &D_801276D0;
    var_v1 = 0;
    for (;;) {
        if (arg0 == var_v0[4]) return var_v1;
        if (arg0 == var_v0[5]) return var_v1 + 1;
        if (arg0 == var_v0[6]) return var_v1 + 2;
        if (arg0 == var_v0[7]) return var_v1 + 3;
        var_v1 += 4;
        var_v0 += 4;
        if (var_v1 == 8) return -1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E82660/func_800A9768.s")

/* extern */

void func_800A9800(void) {
    void func_800A9828(s32, s32, s32);
    func_800A9828(0, 0, 0);
}

void func_800A9828(s32 arg0, s32 arg1, s32 arg2) {
    void func_800A8D00(s32, s32);
    s32 func_800E7F60(void);
    extern s16 D_80127750;
    extern s16 D_80127752;
    extern s32 D_80127754;

    D_80127754 = arg0;
    if (arg1 != 0) {
        D_80127750 = arg1;
    } else {
        D_80127750 = 0x130;
    }
    if (arg2 != 0) {
        D_80127752 = arg2;
    } else {
        D_80127752 = 0xE4;
    }
    func_800E7F60();
    func_800A8D00(D_80127750, D_80127752);
}

s32 func_800A989C(void) {
    s32 func_80014F00(void);
    extern s32 D_80127754;
    s32 result;

    if (D_80127754 != 0) {
        result = D_80127754;
    } else {
        result = func_80014F00();
    }
    return result;
}
