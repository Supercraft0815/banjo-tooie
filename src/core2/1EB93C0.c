#include "core2/1EB93C0.h"
#include "memory.h"

s16 func_8001B668(s32, s32);
void func_8001B754(s16);
void *func_8001B798(s16);

#define BONE_LIST_SIZE ((s32)(sizeof(BoneTransformList) + 0x6D * sizeof(BoneTransform)))

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

void func_800DFB40(BoneTransformList *arg0, s32 arg1, f32 *arg2) {
    void func_800D9600(void *arg0, void *arg1);
    func_800D9600(arg2, arg0->ptr + arg1);
}

void func_800DFB7C(BoneTransformList *arg0, s32 arg1, f32 *arg2, f32 *arg3, f32 *arg4) {
    void func_800D9600(void *arg0, void *arg1);
    void func_800EE7F8(f32 *, f32 *);
    u8 *sp18;
    u8 *transform;

    sp18 = (u8 *)arg0->ptr;
    transform = (u8 *)((uintptr_t)sp18 + arg1 * 0x28);
    sp18 = transform;
    func_800D9600(arg2, transform);
    func_800EE7F8(arg3, (f32 *)(transform + 0x10));
    func_800EE7F8(arg4, (f32 *)(transform + 0x1C));
}

void func_800DFBE0(BoneTransformList *arg0, s32 arg1, f32 *arg2) {
    void func_800EE7F8(f32 *, f32 *);
    func_800EE7F8(arg2, arg0->ptr[arg1].scale);
}

void func_800DFC20(BoneTransformList *arg0, s32 arg1, f32 *arg2) {
    void func_800EE7F8(f32 *, f32 *);
    func_800EE7F8(arg2, arg0->ptr[arg1].unk1C);
}

void func_800DFC60(void* arg0) 
{
    heap_free(arg0);
}
BoneTransformList *func_800DFC80(void) {
    BoneTransformList *temp_v0;

    temp_v0 = heap_alloc(BONE_LIST_SIZE);
    temp_v0->ptr = (BoneTransform *)(temp_v0 + 1);
    temp_v0->count = 0x6D;
    func_800DFAD0(temp_v0);
    return temp_v0;
}

/* extern */

void func_800DFCC0(s16 arg0) {
    func_8001B754(arg0);
}

/* extern */

BoneTransformList *func_800DFCE8(s16 arg0) {
    return func_8001B798(arg0);
}

/* extern */

s16 func_800DFD10(void) {
    s16 result;
    BoneTransformList *list;

    result = func_8001B668(1, BONE_LIST_SIZE);
    list = func_8001B798(result);
    list->ptr = (BoneTransform *)(list + 1);
    list->count = 0x6D;
    func_800DFAD0(list);
    return result;
}

void func_800DFD64(BoneTransformList *arg0, BoneTransformList *arg1, BoneTransformList *arg2, f32 arg3) {
    void func_800D9600(void *, void *);
    int func_800D97E8(f32[4], f32[4]);
    void func_800D9AD4(f32[4], f32[4], f32[4], f32);
    BoneTransform *end_ptr;
    BoneTransform *dst;
    BoneTransform *start;
    BoneTransform *end;

    dst = arg0->ptr;
    end_ptr = dst + arg0->count;
    start = arg1->ptr;
    end = arg2->ptr;
    for (; dst < end_ptr; dst++, start++, end++) {
        if (func_800D97E8(start->unk0, end->unk0)) {
            func_800D9600(dst->unk0, start->unk0);
        } else {
            func_800D9AD4(dst->unk0, start->unk0, end->unk0, arg3);
        }
        dst->scale[0] = start->scale[0] + (end->scale[0] - start->scale[0]) * arg3;
        dst->scale[1] = start->scale[1] + (end->scale[1] - start->scale[1]) * arg3;
        dst->scale[2] = start->scale[2] + (end->scale[2] - start->scale[2]) * arg3;
        dst->unk1C[0] = start->unk1C[0] + (end->unk1C[0] - start->unk1C[0]) * arg3;
        dst->unk1C[1] = start->unk1C[1] + (end->unk1C[1] - start->unk1C[1]) * arg3;
        dst->unk1C[2] = start->unk1C[2] + (end->unk1C[2] - start->unk1C[2]) * arg3;
    }
}

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

#ifdef BT_NATIVE
void func_800DFF2C(BoneTransformList *arg0, s32 arg1, f32 arg2[4]) {
#else
void func_800DFF2C(u8 **arg0, s32 arg1, f32 arg2[4]) {
#endif
    void func_800D9600(void *arg0, void *arg1);
    func_800D9600(((BoneTransformList *)arg0)->ptr + arg1, arg2);
}

/* extern */

void func_800DFF64(BoneTransformList *arg0, s32 arg1, f32 *arg2) {
    void func_800EE7F8(f32 *, f32 *);
    func_800EE7F8(arg0->ptr[arg1].scale, arg2);
}

/* extern */

void func_800DFFA0(BoneTransformList *arg0, s32 arg1, f32 *arg2) {
    void func_800EE7F8(f32 *, f32 *);
    BoneTransformList **base = &arg0;
    func_800EE7F8((*base)->ptr[arg1].unk1C, arg2);
}

void func_800DFFDC(BoneTransformList *arg0, s32 arg1, f32 *arg2) {
    void func_800D93A0(f32[4], f32[3]);
    f32 sp18[4];

    func_800D93A0(sp18, arg2);
    func_800DFF2C((void *)arg0, arg1, sp18);
}

/* extern */

BoneTransformList *func_800E0018(BoneTransformList *arg0) {
    BoneTransformList *temp_v0;

    temp_v0 = defrag(arg0);
    temp_v0->ptr = (BoneTransform *)(temp_v0 + 1);
    return temp_v0;
}

void func_800E0040(BoneTransformList *arg0) {
    arg0->ptr = (BoneTransform *)(arg0 + 1);
}
