#include "common.h"

s16 *func_800B39D0(u8 *arg0, s32 arg1) {
    struct Record {
        s16 stride;
        s16 pad;
        u8 data[1];
    } *record = (struct Record *) arg0;

    return (s16 *) (record->data + arg1 * record->stride);
}

/* extern */

void func_800B39E8(void *arg0) {
    s16 *temp_v0;
    s16 *var_v0 = (s16 *)((u8 *)arg0 + 4);

    *(s16 *)((u8 *)arg0 + 6) = 0;
    if (*(s16 *)((u8 *)arg0 + 2) != 0) {
        *var_v0 = 1;
        temp_v0 = func_800B39D0(arg0, *var_v0);
        temp_v0[0] = 0;
        temp_v0[1] = *(s16 *)((u8 *)arg0 + 2) - 1;
        return;
    }
    *var_v0 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8D2C0/func_800B3A40.s")

/* extern */

void func_800B3B08(u8 *arg0, s32 arg1, s32 arg2) {
    s16 *func_800B39D0(u8 *, s32);
    s32 func_800B3A40(u8 *, s16 *, s32, s32);
    s16 *temp_v0;
    s16 *var_s0;
    s16 temp_a1;

    var_s0 = arg0 + 4;
    if ((*(s16 *)((s8 *)(arg0) + (4))) != 0) {
loop_1:
        temp_a1 = *var_s0;
        if (temp_a1 < (arg1 + arg2)) {
            temp_v0 = func_800B39D0(arg0, temp_a1);
            var_s0 = temp_v0;
            if (*temp_v0 != 0) {
                goto loop_1;
            }
        }
    }
    func_800B3A40(arg0, var_s0, arg1, arg2);
}

void func_800B3B8C(u8 *arg0, s16 *arg1, s16 *arg2, s32 arg3) { s16 *temp_v0; *arg2 += arg3; temp_v0 = func_800B39D0(arg0, *arg2); temp_v0[0] = arg1[0]; temp_v0[1] = arg1[1] - arg3; }

/* extern */

s16 *func_800B3BDC(u8 *arg0, s16 *arg1) { s16 *temp_v0; temp_v0 = func_800B39D0(arg0, *arg1); if (temp_v0[1] == 1) { *arg1 = temp_v0[0]; } else { func_800B3B8C(arg0, temp_v0, arg1, 1); } return temp_v0; }

s16 *func_800B3C40(u8 **arg0, s32 arg1, s32 arg2) { u8 *data; s32 old_count; s32 new_count; s16 *entry; s16 *result; data = *arg0; old_count = *(s16 *)(data + 2); new_count = old_count + arg2; data = heap_realloc(data, *(s16 *)data * new_count + 4); *(s16 *)(data + 2) = new_count; *arg0 = data; result = func_800B39D0(data, arg1); *result = old_count; entry = func_800B39D0(data, *result); entry[0] = 0; entry[1] = arg2; return result; }

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8D2C0/func_800B3CDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8D2C0/func_800B3EDC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8D2C0/func_800B3FD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8D2C0/func_800B4134.s")

void func_800B422C(u8 **arg0, s16 *arg1) { u8 *data; s32 count; data = *arg0; count = arg1[0]; if (count != 0) { func_800B3B08(data, count, arg1[1]); func_800B3EDC(arg0, 0xA); arg1[1] = 0; arg1[0] = arg1[1]; } }

void func_800B4290(void *arg0) {
    (*(s16 *)((s8 *)(arg0) + (2))) = 0;
    (*(s16 *)((s8 *)(arg0) + (0))) = (s16) (*(s16 *)((s8 *)(arg0) + (2)));
}

s32 func_800B42A0(u8 *arg0, s16 *arg1) {
    s32 value;
    s32 result;

    value = *arg1;
    if (value != 0) {
        result = (s32) func_800B39D0(arg0, value);
    } else {
        result = 0;
    }
    return result;
}

void func_800B42DC(void* arg0) 
{
    heap_free(arg0);
}
s16 *func_800B42FC(s32 size, s32 count) {
    void func_800B39E8(void *);
    s16 *ptr;
    count++;
    ptr = heap_alloc(size * count + 4);
    ptr[0] = size;
    ptr[1] = count;
    func_800B39E8(ptr);
    return ptr;
}

void func_800B4354(s32 arg0)
{
    func_800B3EDC(arg0,0);
}

s32 func_800B4374(s16 *arg0)
{
    return arg0[2];
}
