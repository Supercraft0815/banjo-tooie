#include "common.h"

extern s32 D_80127110;

void func_800A5BE0()
{
    _chbaddieDll_entrypoint_0(&D_80127110);
}

/* extern */

void func_800A5C04(void) {
    s32 heap_alloc(s32);
    D_80127110 = heap_alloc(0x2C0);
}

/* extern */

void func_800A5C28(void) {
    s32 _chbaddieDll_entrypoint_1(s32 *);
    s32 _cosectionstor_entrypoint_4(s32);
    s32 _gccollectDll_entrypoint_4();
    s32 _subaddietaxi_entrypoint_4();
    s32 func_8001E204();
    s32 func_800BDCDC();
    s32 func_800EA05C();
    s32 func_800FFB74();
    s32 func_80108C14();
    _gccollectDll_entrypoint_4();
    _chbaddieDll_entrypoint_1(&D_80127110);
    _subaddietaxi_entrypoint_4();
    _cosectionstor_entrypoint_4(func_800EA05C());
    func_80108C14();
    func_800FFB74();
    if (func_8001E204() == 0) {
        func_800BDCDC();
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7F4D0/func_800A5C94.s")

/* extern */

void func_800A5CC4(void) {
    s32 _chbaddieDll_entrypoint_2(s32 *);
    s32 _subaddietaxi_entrypoint_3();
    _subaddietaxi_entrypoint_3();
    _chbaddieDll_entrypoint_2(&D_80127110);
}

void func_800A5CF0(s32 arg0) {
    extern s8 D_80127115;
    *(s8 *)((u8 *)&D_80127115 + 0) = arg0;
}

void func_800A5CFC()
{
    func_800FF62C();
}

void func_800A5D1C(void) {
    s32 _chbaddieDll_entrypoint_3(s32 *);
    s32 func_800FFB74();
    s32 func_8010D1E8();
    extern u8 D_80127114;
    if (D_80127114 != 0) {
        func_8010D1E8();
        _chbaddieDll_entrypoint_3(&D_80127110);
    }
    func_800FFB74();
}

void * func_800A5D60(void) {
    return &D_80127110;
}

/* extern */

void func_800A5D6C(void) {
    s32 defrag(s32);
    if (D_80127110 != 0) {
        D_80127110 = defrag(D_80127110);
    }
}
