#include "common.h"

OSThread *chpowerhutwitchy_entrypoint_0(void)
{
    extern u8 D_80800B28_chpowerhutwitchy[];

    return (OSThread *) D_80800B28_chpowerhutwitchy;
}

OSThread *chpowerhutwitchy_entrypoint_1(void)
{
    extern u8 D_80800B70_chpowerhutwitchy[];

    return (OSThread *) D_80800B70_chpowerhutwitchy;
}

OSThread *chpowerhutwitchy_entrypoint_2(void)
{
    extern u8 D_80800BB8_chpowerhutwitchy[];

    return (OSThread *) D_80800BB8_chpowerhutwitchy;
}

OSThread *chpowerhutwitchy_entrypoint_3(void)
{
    extern u8 D_80800C00_chpowerhutwitchy[];

    return (OSThread *) D_80800C00_chpowerhutwitchy;
}

void *func_80100094(Actor *, u32);

void func_80800030_chpowerhutwitchy(Actor *arg0) {
    s32 _chpowerhut_entrypoint_0(Actor *, s32 *);
    extern s32 D_80800B00_chpowerhutwitchy;
    _chpowerhut_entrypoint_0(arg0, &D_80800B00_chpowerhutwitchy);
    (*(s8 *)((s8 *)(func_80100094(arg0, 0)) + (0x18))) = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/powerhutwity/func_80800068_chpowerhutwitchy.s")

void func_80800168_chpowerhutwitchy(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _chpowerhut_entrypoint_3(Actor *, s32, s32, s32 *);
    s32 _glcutDll_entrypoint_20();
    void func_800BF744(s32, s32);
    s32 func_800DA298(s32);
    void func_8080024C_chpowerhutwitchy(s32 *);
    extern s32 D_80800B00_chpowerhutwitchy;
    u32 active;
    s32 initial;

    if (arg1 == 0x95) {
        initial = func_800DA298(0xEB) != 0;
        if (initial == 0) {
            initial = _glcutDll_entrypoint_20() != 0;
        }
        active = initial;
        initial = initial == 0;
        func_800BF744(1, initial);
        func_800BF744(2, active);
        initial = active < 1U;
        func_800BF744(3, initial);
        func_800BF744(4, active);
        func_800BF744(7, initial);
        func_800BF744(8, active);
        *(f32 *)&arg0->actorData[4] = ((f32 *)func_80100094(arg0, 0))[5];
        if (active == 0) {
            func_8080024C_chpowerhutwitchy((s32 *)arg0);
        }
    }
    _chpowerhut_entrypoint_3(arg0, arg1, arg2, &D_80800B00_chpowerhutwitchy);
}

void func_8080024C_chpowerhutwitchy(s32 *arg0) {
    s32 _glid_entrypoint_0(s32, s32, void (*)(void), s32);
    s32 func_800BEA88(s32);
    void _chpowerhutwitchy_entrypoint_4(void);
    s32 temp_v0;
    void (*callback)(void) = _chpowerhutwitchy_entrypoint_4;

    temp_v0 = func_800BEA88(0);
    _glid_entrypoint_0(temp_v0, 1, callback, *arg0);
    _glid_entrypoint_0(temp_v0, 2, callback, *arg0);
    _glid_entrypoint_0(temp_v0, 3, callback, *arg0);
    _glid_entrypoint_0(temp_v0, 6, callback, *arg0);
    temp_v0 = func_800BEA88(1);
    _glid_entrypoint_0(temp_v0, 1, callback, *arg0);
    _glid_entrypoint_0(temp_v0, 2, callback, *arg0);
    _glid_entrypoint_0(temp_v0, 6, callback, *arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/powerhutwity/chpowerhutwitchy_entrypoint_4.s")

void func_808005C8_chpowerhutwitchy(Actor *arg0) {
    s32 _chpowerhut_entrypoint_0(Actor *, s32 *);
    extern s32 D_80800B14_chpowerhutwitchy;
    _chpowerhut_entrypoint_0(arg0, &D_80800B14_chpowerhutwitchy);
    (*(s8 *)((s8 *)(func_80100094(arg0, 0)) + (0x18))) = 0;
    (*(s8 *)((s8 *)(func_80100094(arg0, 0)) + (0x19))) = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/powerhutwity/func_80800610_chpowerhutwitchy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/powerhutwity/func_8080073C_chpowerhutwitchy.s")

void func_80800890_chpowerhutwitchy(s32 *arg0) {
    s32 _glid_entrypoint_0(s32, s32, void (*)(void), s32);
    s32 func_800BEA88(s32);
    void _chpowerhutwitchy_entrypoint_5(void);
    s32 sp24;
    s32 temp_v0;
    s32 temp_v0_2;
    void (*callback)(void) = _chpowerhutwitchy_entrypoint_5;

    temp_v0 = func_800BEA88(0);
    sp24 = temp_v0;
    _glid_entrypoint_0(temp_v0, 4, callback, *arg0);
    _glid_entrypoint_0(sp24, 5, callback, *arg0);
    temp_v0_2 = func_800BEA88(1);
    sp24 = temp_v0_2;
    _glid_entrypoint_0(temp_v0_2, 4, callback, *arg0);
    _glid_entrypoint_0(sp24, 5, callback, *arg0);
}

void chpowerhutwitchy_entrypoint_5(s32 arg0, s32 arg1, s32 arg2, s32 arg3, Unk80132ED0 *arg4) {
    s32 func_800F2FD0(s32, s32, f32);
    Actor *func_80106790(Unk80132ED0 *);
    f32 temp_f20;
    temp_f20 = *(f32 *)&func_80106790(arg4)->actorData[4];
    switch (arg0) {
    case 4:
        if (arg3 > 0) {
            do {
                func_800F2FD0(arg2 + 0xC, arg1 + 0xC, temp_f20);
                arg3 -= 1;
                arg1 += 0x10;
                arg2 += 0x10;
            } while (arg3 > 0);
            return;
        }
        return;
    case 5:
        if (arg3 > 0) {
            do {
                func_800F2FD0(arg2 + 0xC, arg1 + 0xC, temp_f20);
                arg3 -= 1;
                arg1 += 0x10;
                arg2 += 0x10;
            } while (arg3 > 0);
        }
        break;
    }
}

/* extern */

void func_808009FC_chpowerhutwitchy(s32 arg0) {
    s32 _idworldmake_entrypoint_1(s32, s32, s32, s32);
    s32 func_800BEA88(s32);
    s32 func_800EA05C();
    if (func_800EA05C() == 0xD6) {
        _idworldmake_entrypoint_1(func_800BEA88(0), 0x89D, 4, 1);
    }
    (*(s8 *)((s8 *)(func_80100094(arg0, 0)) + (0x19))) = 1;
}

/* extern */

void func_80800A58_chpowerhutwitchy(Actor *arg0) {
    s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_6(Actor *, s32);
    void _chdoormake_entrypoint_8(void *, u32);
    f32 var_f0;
    s32 var_v1;

    var_f0 = -90.0f;
    var_v1 = 0;
    if (arg0->unk6C_9 == 0x39E) {
        var_f0 = 90.0f;
        var_v1 = 1;
    }
    if (_chdoormake_entrypoint_3(arg0, var_f0, 0.0f, 100.0f, 1, 0xEC) != 0) {
        _chdoormake_entrypoint_6(arg0, 0x3F400000);
        if (var_v1 != 0) {
            _chdoormake_entrypoint_8(arg0, 0x10);
        }
    }
}
