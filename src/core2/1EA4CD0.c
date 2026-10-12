#include "common.h"

u8 func_800CB3E0(s32 arg0) {
    extern u8 D_8012AB71[];
    return D_8012AB71[(arg0 * 3) * 16];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA4CD0/func_800CB3FC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA4CD0/func_800CB45C.s")

s32 func_800CB4D0(s32 arg0, s32 arg1, s32 arg2) {
    extern u8 D_8012AB70[];
    void *temp_v1;

    temp_v1 = D_8012AB70 + arg0 * 0x30;
    if ((*(u8 *)((s8 *)(temp_v1) + (1))) == 0) {
        (*(u8 *)((s8 *)(temp_v1) + (1))) = 1U;
        (*(s32 *)((s8 *)(temp_v1) + (4))) = arg1;
        (*(s16 *)((s8 *)(temp_v1) + (2))) = arg2;
        return 1;
    }
    return 0;
}

s16 func_800CB518(s32 arg0) {
    extern s16 D_8012AB72[][24];
    return D_8012AB72[arg0][0];
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA4CD0/func_800CB534.s")

/* extern */

void func_800CB598(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_800CB534(s32, s32, s32);
    s32 func_800CB698(s32, s32);
    func_800CB698(arg0, 4);
    func_800CB534(arg0, arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA4CD0/func_800CB5D4.s")

void func_800CB610(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA4CD0/func_800CB618.s")

s32 func_800CB698(s32 arg0, s32 arg1) {
    extern u8 D_8012AB71[];
    D_8012AB71[(arg0 * 3) * 16] = arg1;
}

void func_800CB6B4(s32 arg0, f32 *arg1, f32 arg2, s32 arg3) {
    extern u8 D_8012AB70[];
    struct Entry { f32 pad[7]; f32 vector[3]; f32 value; s16 flag; s16 tail; };
    func_800EE7F8(((struct Entry *)D_8012AB70)[arg0].vector, arg1);
    ((struct Entry *)D_8012AB70)[arg0].value = arg2;
    ((struct Entry *)D_8012AB70)[arg0].flag = arg3;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA4CD0/func_800CB70C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA4CD0/func_800CB764.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EA4CD0/func_800CB7C4.s")
