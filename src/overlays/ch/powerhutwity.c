#include "common.h"

OSThread *chpowerhutwitchy_entrypoint_0(void)
{
    extern ActorData D_80800B28_chpowerhutwitchy[];

    return (OSThread *) D_80800B28_chpowerhutwitchy;
}

OSThread *chpowerhutwitchy_entrypoint_1(void)
{
    extern ActorData D_80800B70_chpowerhutwitchy[];

    return (OSThread *) D_80800B70_chpowerhutwitchy;
}

OSThread *chpowerhutwitchy_entrypoint_2(void)
{
    extern ActorData D_80800BB8_chpowerhutwitchy[];

    return (OSThread *) D_80800BB8_chpowerhutwitchy;
}

OSThread *chpowerhutwitchy_entrypoint_3(void)
{
    extern ActorData D_80800C00_chpowerhutwitchy[];

    return (OSThread *) D_80800C00_chpowerhutwitchy;
}

void *func_80100094(Actor *, u32);

void func_80800030_chpowerhutwitchy(Actor *arg0) {
    s32 _chpowerhut_entrypoint_0(Actor *, s32 *);
    extern s32 D_80800B00_chpowerhutwitchy[5];
    _chpowerhut_entrypoint_0(arg0, D_80800B00_chpowerhutwitchy);
    (*(s8 *)((s8 *)(func_80100094(arg0, 0)) + (0x18))) = 0;
}

void func_80800068_chpowerhutwitchy(Actor *arg0) {
    s32 _chpowerhut_entrypoint_1(Actor *, s32 *);
    void func_800BF744(s32, s32);
    void func_8080024C_chpowerhutwitchy(s32 *);
    extern s32 D_80800B00_chpowerhutwitchy[5];
    u32 state;

    _chpowerhut_entrypoint_1(arg0, D_80800B00_chpowerhutwitchy);
    state = arg0->unk70_10;
    if (state != 1 && state != 2 && state == 3) {
        if (((s16 *)func_80100094(arg0, 0))[6] == 2) {
            func_800BF744(1, 0);
            func_800BF744(2, 1);
            func_800BF744(3, 0);
            func_800BF744(4, 1);
            func_800BF744(7, 0);
            func_800BF744(8, 1);
            ((s8 *)func_80100094(arg0, 0))[0x18] = 1;
        }
        if (((s16 *)func_80100094(arg0, 0))[6] == 3) {
            *(f32 *)&arg0->actorData[4] = ((f32 *)func_80100094(arg0, 0))[5];
            func_8080024C_chpowerhutwitchy((s32 *)arg0);
        }
    }
}

void func_80800168_chpowerhutwitchy(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _chpowerhut_entrypoint_3(Actor *, s32, s32, s32 *);
    s32 _glcutDll_entrypoint_20();
    void func_800BF744(s32, s32);
    s32 func_800DA298(s32);
    void func_8080024C_chpowerhutwitchy(s32 *);
    extern s32 D_80800B00_chpowerhutwitchy[5];
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
    _chpowerhut_entrypoint_3(arg0, arg1, arg2, D_80800B00_chpowerhutwitchy);
}

void func_8080024C_chpowerhutwitchy(s32 *arg0) {
    void _glid_entrypoint_0(u8 *arg0, s32 arg1, s32 (*arg2)(s16, u8 *, u8 *, s16, s32), BtIntPtr arg3);
    void *func_800BEA88(s32 i);
#ifdef BT_NATIVE
    void chpowerhutwitchy_entrypoint_4(s32 arg0, Vtx *arg1, Vtx *arg2, s32 arg3, Unk80132ED0 *arg4);
#else
    void _chpowerhutwitchy_entrypoint_4(void);
#endif
    BtIntPtr temp_v0;
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

void chpowerhutwitchy_entrypoint_4(s32 arg0, Vtx *arg1, Vtx *arg2, s32 arg3, Unk80132ED0 *arg4) {
    Actor *func_80106790(Unk80132ED0 *);
    void func_800F2FD0(u8 *arg0, u8 *arg1, f32 scale);
    s32 func_800F3320(u8 *, u8 *, u8 *, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    extern u8 D_80800C48_chpowerhutwitchy[];
    f32 amount;
    f32 alpha;
    amount = *(f32 *)((u8 *)func_80106790(arg4) + 0x28);
    switch (arg0) {
    case 1:
        while (arg3 > 0) {
            func_800F2FD0(arg2->v.cn, arg1->v.cn, amount);
            arg3--; arg1++; arg2++;
        }
        break;
    case 2:
        while (arg3 > 0) {
            func_800F3320(arg2->v.cn, D_80800C48_chpowerhutwitchy, arg1->v.cn, amount);
            arg3--; arg1++; arg2++;
        }
        break;
    case 3:
        alpha = func_800F10B4(amount, 0.0f, 1.0f, 0.3f, 1.0f);
        for (; arg3 > 0; arg1++, arg3--, arg2++) {
            arg2->v.cn[3] = (u32)((f32)(u32)arg1->v.cn[3] * alpha);
        }
        break;
    case 6:
        for (; arg3 > 0; arg1++, arg3--, arg2++) {
            arg2->v.cn[3] = (u32)((f32)(u32)arg1->v.cn[3] * amount);
        }
        break;
    }
}

void func_808005C8_chpowerhutwitchy(Actor *arg0) {
    s32 _chpowerhut_entrypoint_0(Actor *, s32 *);
    extern s32 D_80800B14_chpowerhutwitchy[5];
    _chpowerhut_entrypoint_0(arg0, D_80800B14_chpowerhutwitchy);
    (*(s8 *)((s8 *)(func_80100094(arg0, 0)) + (0x18))) = 0;
    (*(s8 *)((s8 *)(func_80100094(arg0, 0)) + (0x19))) = 0;
}

void func_80800610_chpowerhutwitchy(Actor *arg0) {
    s32 _chpowerhut_entrypoint_1(Actor *, s32 *);
    void func_800BF744(s32, s32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_80800890_chpowerhutwitchy(s32 *);
    void func_808009FC_chpowerhutwitchy(BtIntPtr);
    extern s32 D_80800B14_chpowerhutwitchy[5];
    f32 sp2C;
    u32 state;

    _chpowerhut_entrypoint_1(arg0, D_80800B14_chpowerhutwitchy);
    state = arg0->unk70_10;
    if (state == 3 || state == 4) {
        if (((s16 *)func_80100094(arg0, 0))[6] == 2) {
            func_800BF744(5, 0);
            func_800BF744(6, 1);
            ((s8 *)func_80100094(arg0, 0))[0x18] = 1;
        }
        if (((u8 *)func_80100094(arg0, 0))[0x19] == 0) {
            sp2C = ((f32 *)func_80100094(arg0, 0))[5];
            if (((s16 *)func_80100094(arg0, 0))[6] == 4) {
                func_808009FC_chpowerhutwitchy((BtIntPtr)arg0);
            }
            if (((s16 *)func_80100094(arg0, 0))[6] == 3) {
                *(f32 *)&arg0->actorData[4] = func_800F10B4(sp2C, 0.0f, 1.0f, 0.3f, 1.0f);
                func_80800890_chpowerhutwitchy((s32 *)arg0);
            }
        }
    }
}

s32 func_8080073C_chpowerhutwitchy(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    s32 _capod_entrypoint_14(void);
    s32 _chpowerhut_entrypoint_3(Actor *, s32, s32, s32 *);
    s32 _glcutDll_entrypoint_20();
    void func_800BF744(s32, s32);
    s32 func_800DA298(s32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void *func_80100094(Actor *, u32);
    s32 func_80101180(s32, s32, BtIntPtr);
    void func_80800890_chpowerhutwitchy(s32 *);
    void func_808009FC_chpowerhutwitchy(BtIntPtr);
    extern s32 D_80800B14_chpowerhutwitchy[5];
    s32 sp24;

    switch (arg1) {
    case 0xB:
        if (arg2 == 0x31) {
            _capod_entrypoint_14();
            _capod_entrypoint_13(arg0->unk0, 0, 0x35, 0x2010);
            func_80101180(0x39E, 7, 0);
            func_80101180(0x39F, 7, 0);
            return 4;
        }
        return 3;
    case 0x95:
        sp24 = func_800DA298(0xEC) != 0 || _glcutDll_entrypoint_20() != 0;
        func_800BF744(5, !sp24);
        func_800BF744(6, sp24);
        *(f32 *)&arg0->actorData[4] = func_800F10B4(((f32 *)func_80100094(arg0, 0))[5], 0.0f, 1.0f, 0.3f, 1.0f);
        if (sp24 == 0) {
            func_80800890_chpowerhutwitchy((s32 *)arg0);
        } else {
            func_808009FC_chpowerhutwitchy((BtIntPtr)arg0);
        }
        break;
    }
    return _chpowerhut_entrypoint_3(arg0, arg1, arg2, D_80800B14_chpowerhutwitchy);
}

void func_80800890_chpowerhutwitchy(s32 *arg0) {
    void _glid_entrypoint_0(u8 *arg0, s32 arg1, s32 (*arg2)(s16, u8 *, u8 *, s16, s32), BtIntPtr arg3);
    void *func_800BEA88(s32 i);
#ifdef BT_NATIVE
    void chpowerhutwitchy_entrypoint_5(s32 arg0, BtIntPtr arg1, BtIntPtr arg2, s32 arg3, Unk80132ED0 *arg4);
#else
    void _chpowerhutwitchy_entrypoint_5(void);
#endif
    BtIntPtr sp24;
    BtIntPtr temp_v0;
    BtIntPtr temp_v0_2;
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

void chpowerhutwitchy_entrypoint_5(s32 arg0, BtIntPtr arg1, BtIntPtr arg2, s32 arg3, Unk80132ED0 *arg4) {
    void func_800F2FD0(u8 *arg0, u8 *arg1, f32 scale);
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

void func_808009FC_chpowerhutwitchy(BtIntPtr arg0) {
    void _idworldmake_entrypoint_1(BtIntPtr arg0, s32 arg1, volatile unsigned int arg2, s32 arg3);
    void *func_800BEA88(s32 i);
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
/* data_to_c.py: from asm/data/overlays/ch/powerhutwity.data.s */
void func_80105834(Actor*);
void _chpowerhut_entrypoint_2();
void func_80107C2C();
void _chdoor_entrypoint_0();
void func_80101870(Actor* arg0, void* arg1);
s32 _chdoor_entrypoint_1(Actor *arg0, s32 arg1, BtIntPtr arg2);
s32 D_80800B00_chpowerhutwitchy[5] BT_DATA(4, overlays_ch_powerhutwity, 0x0) = { 15400998, 1049176, 1103626240, 1088421888, 1090519040 };
s32 D_80800B14_chpowerhutwitchy[5] BT_DATA(4, overlays_ch_powerhutwity, 0x14) = { 15466545, 3146178, 1095761920, 1075838976, 1086324736 };
ActorData D_80800B28_chpowerhutwitchy [1] BT_DATA(4, overlays_ch_powerhutwity, 0x28) = { { 774, 924, -1, 1, 0, (void (*)(struct Actor *))func_80800068_chpowerhutwitchy, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))_chpowerhut_entrypoint_2, 196608000, 0, 0, 0, 0, 0, 0, 0, 28, 0, (void (*)(struct Actor *))func_80800030_chpowerhutwitchy, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 3074, (void (*)(struct Actor *, long, long))func_80800168_chpowerhutwitchy, 0 } };
ActorData D_80800B70_chpowerhutwitchy [1] BT_DATA(4, overlays_ch_powerhutwity, 0x70) = { { 775, 925, -1, 1, 0, (void (*)(struct Actor *))func_80800610_chpowerhutwitchy, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))_chpowerhut_entrypoint_2, 196608000, 0, 0, 0, 0, 0, 0, 0, 28, 0, (void (*)(struct Actor *))func_808005C8_chpowerhutwitchy, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 3074, (void (*)(struct Actor *, long, long))func_8080073C_chpowerhutwitchy, 0 } };
ActorData D_80800BB8_chpowerhutwitchy [1] BT_DATA(4, overlays_ch_powerhutwity, 0xB8) = { { 172, 926, 1947, 1, 0, (void (*)(struct Actor *))_chdoor_entrypoint_0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 2048, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800A58_chpowerhutwitchy, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 11266, (void (*)(struct Actor *, long, long))_chdoor_entrypoint_1, 0 } };
ActorData D_80800C00_chpowerhutwitchy [1] BT_DATA(4, overlays_ch_powerhutwity, 0x100) = { { 172, 927, 1948, 1, 0, (void (*)(struct Actor *))_chdoor_entrypoint_0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 2048, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800A58_chpowerhutwitchy, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 11266, (void (*)(struct Actor *, long, long))_chdoor_entrypoint_1, 0 } };
u8 D_80800C48_chpowerhutwitchy [5] BT_DATA(4, overlays_ch_powerhutwity, 0x148) = { 0x64, 0x64, 0x64, 0, 0 };
