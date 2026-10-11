#include "common.h"

typedef struct { s32 unk0; void *unk1; } AssetReference;

extern s32 D_8012B7E8;

void func_800D5440(void *ptr){
    extern s32 D_8012B7F0;
    void *vector_end(void *);
    void *vector_begin(void *);
    void *vector_push_back(void **);
    void vector_clear(void *);
    void func_800D56C4(void *);

    AssetReference *start_ptr;
    AssetReference *end_ptr;
    AssetReference *iPtr;

    end_ptr = (AssetReference *) vector_end(((void **)&D_8012B7F0)[0]);
    start_ptr = (AssetReference *) vector_begin(((void **)&D_8012B7F0)[0]);

    for (iPtr = start_ptr; iPtr < end_ptr && ptr != iPtr->unk1; iPtr++);

    if (iPtr < end_ptr) {
        iPtr->unk0++;
    }
    else {
        iPtr = (AssetReference *) vector_push_back(&((void **)&D_8012B7F0)[0]);
        iPtr->unk0 = 1;
        iPtr->unk1 = ptr;
    }
}

int func_800D54F0(void *arg0) {
    extern s32 D_8012B7F0;
    void *vector_end(void *);
    void *vector_begin(void *);
    void *vector_push_back(void **);
    void vector_clear(void *);
    void func_800D56C4(void *);

    AssetReference *start_ptr;
    AssetReference *end_ptr;
    AssetReference *iPtr;
    s32 j;

    for(j = 0; j < 2; j++){
        end_ptr = (AssetReference *) vector_end(((void **)&D_8012B7F0)[j]);
        start_ptr = (AssetReference *) vector_begin(((void **)&D_8012B7F0)[j]);
        for(iPtr = start_ptr; iPtr < end_ptr && arg0 != iPtr->unk1; iPtr++){
        }
        if (iPtr < end_ptr){
            return 1;
        }
    }
    return 0;
}

void func_800D55A0(void) {
    s32 vector_new(s32, s32);
    extern s32 D_8012B7F0;
    extern s32 D_8012B7F4;
    D_8012B7F0 = vector_new(8, 0x10);
    D_8012B7F4 = vector_new(8, 0x10);
}

void func_800D55DC(void){
    extern s32 D_8012B7F0;
    void *vector_end(void *);
    void *vector_begin(void *);
    void *vector_push_back(void **);
    void vector_clear(void *);
    void func_800D56C4(void *);

    void *tmp_a0;
    AssetReference *iPtr;
    AssetReference *start_ptr;
    AssetReference *endPtr;
    int i;

    tmp_a0 = ((void **)&D_8012B7F0)[0];
    ((void **)&D_8012B7F0)[0] = ((void **)&D_8012B7F0)[1];
    ((void **)&D_8012B7F0)[1] = tmp_a0;

    endPtr = (AssetReference *) vector_end(((void **)&D_8012B7F0)[0]);
    start_ptr = (AssetReference *) vector_begin(((void **)&D_8012B7F0)[0]);
    for(iPtr = start_ptr; iPtr < endPtr; iPtr++){
        for(i = 0; i < iPtr->unk0; i++)
            func_800D56C4(iPtr->unk1);
    }

    vector_clear(((void **)&D_8012B7F0)[0]);
}

void func_800D5688(void) {
    s32 vector_defrag(s32);
    extern s32 D_8012B7F0;
    extern s32 D_8012B7F4;
    (*(s32 *)((s8 *)(&D_8012B7F0) + (0))) = vector_defrag((*(s32 *)((s8 *)(&D_8012B7F0) + (0))));
    D_8012B7F4 = vector_defrag((*(s32 *)((s8 *)(&D_8012B7F0) + (4))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAED30/func_800D56C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAED30/func_800D5804.s")

void func_800D58AC()
{
    func_800D5688();
}

void func_800D58CC(void) {
    func_8001A2B0();
    func_800D55DC();
    func_800D55DC();
}

s32 func_800D58FC(s32 arg0) {
    s32 rom_read_word(s32, u32 *);
    extern s32 D_8011B900;
    extern u32 D_8012B440;
    rom_read_word((s32)((u32 *)D_8011B900 + arg0), &D_8012B440);
    return D_8012B440 & 0xF;
}

s32 func_800D593C() 
{
    return 0x3666;
}

s32 func_800D5944()
{
    return D_8012B7E8;
}

s32 func_800D5950(s32 arg0) {
    s32 rom_read_word(s32, u32 *);
    extern s32 D_8011B900;
    extern u32 D_8012B440;
    extern u32 D_8012B444;
    s32 temp_v0[2];
    register s32 offset;

    offset = arg0 * 4;
    rom_read_word(D_8011B900 + offset, (temp_v0[1] = offset, &D_8012B440));
    offset = temp_v0[1];
    rom_read_word(D_8011B900 + offset + 4, &D_8012B444);
    return ((u32) D_8012B444 >> 6) - ((u32) D_8012B440 >> 6);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAED30/func_800D59C0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAED30/func_800D5A04.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAED30/func_800D5A6C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAED30/func_800D5AB4.s")

void func_800D5B24(void) {
    extern s8 D_8012B7E6;
    D_8012B7E6 = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAED30/func_800D5B34.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAED30/func_800D5D70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAED30/func_800D5DB8.s")

void func_800D5E28(s32 *arg0) {
    func_800D5440(*arg0);
    *arg0 = 0;
}

void func_800D5E54(s32 arg0)
{
    func_800D5440((void *)arg0);
}

void func_800D5E74(void) 
{
    func_800D55DC();
}

void func_800D5E94(s32 arg0)
{
    func_800D54F0((void *)arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAED30/func_800D5EB4.s")

void func_800D5FDC(s32 arg0) {
    *(s32 *)((u8 *)&D_8012B7E8 + 0) = arg0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EAED30/func_800D5FE8.s")
