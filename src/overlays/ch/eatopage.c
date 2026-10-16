#include "common.h"

OSThread *chcheatopage_entrypoint_0(void)
{
    extern u8 D_80800330_chcheatopage[];

    return (OSThread *) D_80800330_chcheatopage;
}

/* extern */
void func_8080000C_chcheatopage(Actor *arg0) { void func_80103110(void *, s32); func_80103110(arg0, 0); func_8010A5B0(arg0, func_800DA298(0x666) == 0); if (arg0->unk64_20) { func_800FC660(0x77); arg0->unk64_20 = 0; } }

void func_80800070_chcheatopage(Actor *arg0) {
    f32 func_800D8FF8(void);
    s32 func_800D9078(f32 *);
    u32 func_800F54E4(void);
    void func_800F82D4(s32, s32);
    void func_800FFAB0(Actor *);
    void func_80103110(void *, s32);
    void _glcutDll_entrypoint_6(u32, u32);

    switch (arg0->unk70_10) {
        case 1:
            arg0->rotation[1] += 186.0f * func_800D8FF8();
            func_80103110(arg0, 0);
            break;
        case 2:
            if (func_800D9078(&arg0->unk58)) {
                func_800F82D4(func_800F54E4(), 0);
                func_800FFAB0(arg0);
                _glcutDll_entrypoint_6(0xAD, 1);
            }
            break;
    }
}

/* extern */

s32 func_80800124_chcheatopage(Actor *arg0, s32 arg1, s32 arg2) {
    void func_80800194_chcheatopage(Actor *, s32);
    switch (arg1) {
        case 0x3E:
            func_80800194_chcheatopage(arg0, arg2);
            return 1;
        case 0x13:
            *(s32 *)&arg0->unk50 = *(s32 *)&arg2;
            break;
        case 0x14:
            arg0->unk64_20 = 1;
            break;
        default:
            return 0;
    }
    return 1;
}

/* extern */

void func_80800194_chcheatopage(Actor *arg0, s32 arg1) {
    void _fxsparkle_entrypoint_1(f32 *, u32);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 func_800D035C(s32);
    void func_800D0BD4(s32, u32);
    void func_800D1844(s32);
    s32 func_800DA9E4(s32, s32);
    u32 func_800F54E4(void);
    void func_800F82D4(s32, s32);
    void func_800FFAB0(Actor *);
    void func_80101FDC(Actor *, u32);
    void func_80103110(void *, s32);
    void func_8010A570(Actor *);
    s32 func_8010A6B0(Actor *, s32);
    int func_808002F0_chcheatopage(Actor *);
    struct PageFlags {
        u8 pad[0x74];
        u32 : 11;
        u32 collected : 1;
        u32 : 20;
    };
    if (func_8010A6B0(arg0, (u32)((u16 *)arg1)[13] >> 5) != 0) {
        _fxsparkle_entrypoint_1(arg0->position, 0x14);
        func_800D1844(0x4A);
        func_800D0BD4(*(s32 *)&arg0->unk50, 4);
        func_800FC660(0x72);
        if (func_800D035C(4) == 5) {
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x114A, 4, 0, 0);
        }
        if ((func_808002F0_chcheatopage(arg0) == 0) && (func_800DA9E4(0x67, 1) == 0)) {
            func_800F82D4(func_800F54E4(), 2);
            func_8010A570(arg0);
            func_80101FDC(arg0, 2);
            arg0->unk58 = 0.75f;
            func_80103110(arg0, 1);
            arg0->unk64_16 = 0;
            ((struct PageFlags *)arg0)->collected = 0;
            return;
        }
        func_800FFAB0(arg0);
    }
}

/* extern */

void func_808002A0_chcheatopage(void *arg0) {
    s32 func_80101870();
    void func_80103110(void *, s32);
    func_80101870();
    if ((((struct { unsigned int : 19; unsigned int active : 1; unsigned int : 12; } *)((s8 *)arg0 + 0x7C))->active) && (((u32) (*(u16 *)((s8 *)(arg0) + (0x72))) >> 0xA) == 1)) {
        func_80103110(arg0, 1);
    }
}

int func_808002F0_chcheatopage(Actor *arg0) {
    extern u8 D_80800378_chcheatopage[1];
    s32 index;
    for (index = 0; index < sizeof(D_80800378_chcheatopage); index++) {
        if (D_80800378_chcheatopage[index] == *(u32 *)&arg0->unk50) return 1;
    }
    return 0;
}
