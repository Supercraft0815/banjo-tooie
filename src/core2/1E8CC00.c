#include "common.h"

void func_800B38C8();
void *heap_alloc(s32);
s32 func_800B3310(s32 arg0) {
    struct {
        s32 unk0[3];
        s32 count;
        u8 *start;
        u8 *end;
    } *ptr;
    ptr = heap_alloc(arg0 * 0x1C + 0x18);
    func_800B38C8(ptr);
    ptr->start = (u8 *)(ptr + 1);
    ptr->end = ptr->start + arg0 * 0x1C;
    ptr->count = arg0;
    return (s32)ptr;
}

void func_800B3370(void* arg0) 
{
    heap_free(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8CC00/func_800B3390.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E8CC00/func_800B3494.s")

void func_800EE830(s32 *, s32 *);

int func_800B36C0(s32 arg0, f32 *arg1, s32 *arg2, f32 arg3) {
    void func_800EE7F8(f32 *, f32 *);
    struct entry {
        f32 position[3];
        s32 value[3];
        f32 radius;
    };
    struct entry *sp1C[2];

    sp1C[1] = *(struct entry **)(arg0 + 0x10);
    if (sp1C[1] < *(struct entry **)(arg0 + 0x14)) {
        func_800EE7F8(sp1C[1]->position, arg1);
        func_800EE830((*(struct entry **)(arg0 + 0x10))->value, arg2);
        (*(struct entry **)(arg0 + 0x10))->radius = arg3;
        (*(struct entry **)(arg0 + 0x10))++;
        return 1;
    }
    return 0;
}

/* extern */

void func_800B3748(s32 arg0) {
    int func_800B36C0(s32, f32 *, s32 *, f32);
    s32 func_800C8960(s32 *, f32 *);
    f32 sp24[3];
    s32 pad[2];
    s32 sp18;

    func_800C8960(&sp18, sp24);
    func_800B36C0(arg0, sp24, &sp18, 500.0f);
}

s32 func_800B3784(u8 *arg0) { return ((*(s32 *)((s8 *)arg0 + 0x10) - (s32)arg0) - 0x18) / 28; }

void func_800B37A4(u8 *arg0, s32 *arg1, s32 *arg2) {
    *arg1 = arg0 + 0x18;
    *arg2 = (*(s32 *)((s8 *)(arg0) + (0x10)));
}

void func_800B37B8(s32 arg0, s32 *arg1) { func_800EE830(arg1, (s32 *)arg0); }

void func_800B37E4(s32 *arg0, s32 *arg1) {
    s32 aligned4_memcpy(void *, void *, s32);
    u8 *cursor;

    *(u8 **)((u8 *)arg0 + 0x10) = (u8 *)arg0 + 0x18;
    for (cursor = (u8 *)arg1 + 0x18;
         cursor < *(u8 **)((u8 *)arg1 + 0x10) &&
         *(u8 **)((u8 *)arg0 + 0x10) < *(u8 **)((u8 *)arg0 + 0x14);
         cursor += 0x1C) {
        aligned4_memcpy(*(u8 **)((u8 *)arg0 + 0x10), cursor, 0x1C);
        *(u8 **)((u8 *)arg0 + 0x10) += 0x1C;
    }
    func_800EE830(arg0, arg1);
}

void func_800B388C(u8 *arg0, s32 arg1) {
    (*(s32 *)((s8 *)(arg0) + (0x14))) = (s32) ((arg0 + 0x18) + (arg1 * 0x1C));
}

void func_800B38A8(s32 *arg0, s32 *arg1)
{
    func_800EE830(arg0, arg1);
}

void func_800B38C8()
{
    func_800C87B8();
}

void *func_800B38E8(u8 *arg0) {
    typedef struct { u8 data[28]; } Element;
    void *defrag(void *);
    s32 sp1C;
    s32 sp18;
    u8 *temp_v0;

    sp1C = (Element *)(*(u8 **)(arg0 + 0x10) - 0x18) - (Element *)arg0;
    sp18 = (Element *)(*(u8 **)(arg0 + 0x14) - 0x18) - (Element *)arg0;
    temp_v0 = defrag(arg0);
    if (temp_v0 != arg0) {
        arg0 = temp_v0;
        *(u8 **)(temp_v0 + 0x10) = sp1C * 0x1C + temp_v0 + 0x18;
        *(u8 **)(temp_v0 + 0x14) = sp18 * 0x1C + temp_v0 + 0x18;
    }
    return arg0;
}
