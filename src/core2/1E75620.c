#include "core2/1E75620.h"

s32 func_8009BD30() 
{
    return 0x1;
}

void func_8009BD38(void *arg0, s32 arg1) {
    *(s8 *)((u8 *)*(void **)((u8 *)arg0 + 212) + 0) = arg1;
}

u32 func_8009BD44(void *arg0) {
    return *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 212) + 0);
}

/* extern */

void func_8009BD50(void *arg0) {
    s32 bastatetimer_clear(void *, s32);
    *(*(s8 **)((s8 *)(arg0) + (0xD4))) = 0;
    func_8009BD38(arg0, 1);
    bastatetimer_clear(arg0, 4);
}

void func_8009BD88(PlayerState *arg0) {
    func_8009BDAC(arg0, 0.6f);
}

/* extern */

void func_8009BDAC(PlayerState *arg0, f32 arg1) {
    s32 bastatetimer_set(f32, s32, f32);
    bastatetimer_set(arg1, 4, arg1);
    func_8009BD38(arg0, 3);
}

void func_8009BDE4(s32 arg0) {
    s32 bastatetimer_isDone(s32, s32);
    if (bastatetimer_isDone(arg0, 4) != 0) {
        func_8009BD38((u8 *) arg0, 1);
    }
}
