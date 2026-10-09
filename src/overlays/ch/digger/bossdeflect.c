#include "common.h"

OSThread *chdiggerbossdeflect_entrypoint_0(void)
{
    extern u8 D_80800040_chdiggerbossdeflect[];

    return (OSThread *) D_80800040_chdiggerbossdeflect;
}

void func_8080000C_chdiggerbossdeflect(void *arg0) {
    (*(s16 *)((s8 *)(arg0) + (0x62))) = 0x1F4;
    (*(s16 *)((s8 *)(arg0) + (0x6A))) = 0x1F4;
    (*(s16 *)((s8 *)(arg0) + (0x68))) = 0x1F4;
}

void func_80800020_chdiggerbossdeflect(s32 arg0) 
{
}
s32 func_80800028_chdiggerbossdeflect(s32 arg0, s32 arg1, s32 arg2) {
    return 0;
}
