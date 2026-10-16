#include "core2/1EB93C0.h"

typedef struct { f32 unk0[4]; f32 scale[3]; f32 unk1C[3]; } BoneTransform;
typedef struct { BoneTransform *ptr; s32 count; } BoneTransformList;

void func_800DFAD0(BoneTransformList *this) {
    BoneTransform *end_ptr;
    BoneTransform *i_ptr;

    i_ptr = this->ptr;
    end_ptr = i_ptr + this->count;
    for(i_ptr = i_ptr; i_ptr < end_ptr; i_ptr++){
        i_ptr->unk0[0] = i_ptr->unk0[1] = i_ptr->unk0[2] = 0.0f;
        i_ptr->unk0[3] = 1.0f;
        i_ptr->scale[0] = i_ptr->scale[1] = i_ptr->scale[2] = 1;
        i_ptr->unk1C[0] = i_ptr->unk1C[1] = i_ptr->unk1C[2] = 0.0f;
    }
}

void func_800DFB40(s32 *arg0, s32 arg1, u8 *arg2) {
    void func_800D9600(void *arg0, void *arg1);
    func_800D9600(arg2, *arg0 + (arg1 * 0x28));
}

void func_800DFB7C(BoneTransformList *arg0, s32 arg1, f32 *arg2, f32 *arg3, f32 *arg4) {
    void func_800D9600(void *arg0, void *arg1);
    void func_800EE7F8(f32 *, f32 *);
    u8 *sp18;
    u8 *transform;

    sp18 = (u8 *)arg0->ptr;
    transform = (u8 *)((u32)sp18 + arg1 * 0x28);
    sp18 = transform;
    func_800D9600(arg2, transform);
    func_800EE7F8(arg3, (f32 *)(transform + 0x10));
    func_800EE7F8(arg4, (f32 *)(transform + 0x1C));
}

void func_800DFBE0(s32 *arg0, s32 arg1, s32 arg2) {
    void func_800EE7F8(f32 *, f32 *);
    func_800EE7F8(arg2, *arg0 + (arg1 * 0x28) + 0x10);
}

void func_800DFC20(s32 *arg0, s32 arg1, s32 arg2) {
    void func_800EE7F8(f32 *, f32 *);
    func_800EE7F8(arg2, *arg0 + (arg1 * 0x28) + 0x1C);
}

void func_800DFC60(void* arg0) 
{
    heap_free(arg0);
}
BoneTransformList *func_800DFC80(void) {
    void *heap_alloc(s32 size);
    BoneTransformList *temp_v0;

    temp_v0 = heap_alloc(0x1110);
    temp_v0->ptr = (BoneTransform *)(temp_v0 + 1);
    temp_v0->count = 0x6D;
    func_800DFAD0(temp_v0);
    return temp_v0;
}

/* extern */

void func_800DFCC0(s16 arg0) {
    s32 func_8001B754(s16);
    func_8001B754(arg0);
}

/* extern */

s32 func_800DFCE8(s16 arg0) {
    s32 func_8001B798(s16);
    return func_8001B798(arg0);
}

/* extern */

s16 func_800DFD10(void) {
    s16 result;
    s32 func_8001B668(s32, s32);
    s32 func_8001B798(s16);
    s32 *list;

    result = func_8001B668(1, 0x1110);
    list = (s32 *)func_8001B798(result);
    list[0] = (s32)(list + 2);
    list[1] = 0x6D;
    func_800DFAD0((BoneTransformList *)list);
    return result;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB93C0/func_800DFD64.s")

void func_800DFEA8(BoneTransformList *arg0, BoneTransformList *arg1) {
    void func_800D9600(void *, void *);
    void func_800EE7F8(f32 *, f32 *);
    BoneTransform *src;
    BoneTransform *dst;
    BoneTransform *end;

    src = arg0->ptr;
    dst = arg1->ptr;
    end = src + arg0->count;
    if (src < end) {
        do {
            func_800D9600(dst->unk0, src->unk0);
            func_800EE7F8(dst->scale, src->scale);
            func_800EE7F8(dst->unk1C, src->unk1C);
            src++;
            dst++;
        } while (src < end);
    }
}

void func_800DFF2C(u8 **arg0, s32 arg1, f32 arg2[4]) {
    void func_800D9600(void *arg0, void *arg1);
    func_800D9600(*arg0 + (arg1 * 0x28), arg2);
}

/* extern */

void func_800DFF64(s32 *arg0, s32 arg1, f32 *arg2) {
    void func_800EE7F8(f32 *, f32 *);
    func_800EE7F8(*arg0 + (arg1 * 0x28) + 0x10, arg2);
}

/* extern */

void func_800DFFA0(s32 *arg0, s32 arg1, f32 *arg2) {
    void func_800EE7F8(f32 *, f32 *);
    s32 **base = &arg0;
    func_800EE7F8(**base + (arg1 * 0x28) + 0x1C, arg2);
}

void func_800DFFDC(s32 arg0, s32 arg1, f32 *arg2) {
    void func_800D93A0(f32[4], f32[3]);
    f32 sp18[4];

    func_800D93A0(sp18, arg2);
    func_800DFF2C(arg0, arg1, sp18);
}

/* extern */

void func_800E0018(void) {
    s32 *defrag();
    s32 *temp_v0;

    temp_v0 = defrag();
    *temp_v0 = (s32) temp_v0 + 8;
}

void func_800E0040(u32 *arg0) {
    arg0[0] = (u32) arg0 + 8;
}
