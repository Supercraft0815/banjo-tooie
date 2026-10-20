#include "common.h"

/* extern */

void func_80800000_chLagoonInnBlockedWall(Actor *arg0) {
    void _chexploder_entrypoint_3(void *, void *, u32);
    void _glcutDll_entrypoint_6(u32, u32);
    u8 func_800D9078(f32 *);
    s32 func_800DA544(s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    u32 func_800F54E4(void);
    void func_800F82D4(s32, s32);
    void func_800FFAB0(Actor *);

    switch (arg0->unk70_10) {
    case 3:
        if (func_800D9078(&arg0->unk58) != 0) {
            f32 sp24[3];
            func_800EE7F8(sp24, arg0->position);
            func_800EF1B8(sp24, arg0->rotation[1], -100);
            _chexploder_entrypoint_3(arg0, sp24, 3);
            func_800DA544(0x3A9);
        }
        break;
    case 2:
        if (func_800D9078(&arg0->unk58) != 0) {
            func_800F82D4(func_800F54E4(), 0);
            _glcutDll_entrypoint_6(0x1A7, 0x32);
            func_800FFAB0(arg0);
        }
        break;
    }
}

void func_808000C0_chLagoonInnBlockedWall()
{
    func_8010A63C();
}

s32 func_808000E0_chLagoonInnBlockedWall(Actor *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    void _chexploder_entrypoint_3(void *, void *, u32);
    s32 _glcutDll_entrypoint_19(s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    void func_800C4AF0(f32 *, void *);
    s32 func_800EA05C();
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    u32 func_800F54E4(void);
    void func_800F8300();
    void func_800FFAB0(Actor *);
    void func_80101FDC(Actor *, u32);
    void func_80103110(Actor *, u32);
    void func_8010A570(Actor *);
    extern s32 D_80800400_chLagoonInnBlockedWall[];
    extern s32 D_8080046C_chLagoonInnBlockedWall[];
    f32 sp34[3];

    switch (arg1) {
    case 0x49:
        if (_glcutDll_entrypoint_19(0x32)) {
            arg0->unk58 = 0.4f;
            func_80103110(arg0, 1);
            func_80101FDC(arg0, 3);
            _capod_entrypoint_13(arg0->unk0, NULL, 0x1C, 0x910);
            return 1;
        }
        break;
    case 5:
        func_8010A570(arg0);
        func_800EE7F8(sp34, arg0->position);
        func_800EF1B8(sp34, arg0->rotation[1], 100.0f);
        _chexploder_entrypoint_3(arg0, sp34, 3);
        func_800F8300(func_800F54E4(), 2, arg0->position);
        return 1;
    case 0x90:
        if (func_800EA05C() == 0xED) {
            func_80101FDC(arg0, 2);
            func_80103110(arg0, 1);
            arg0->unk58 = 0.8f;
        } else {
            func_800FFAB0(arg0);
        }
        func_800BABB8(0, arg0->position, arg0->position, arg0->scale, D_80800400_chLagoonInnBlockedWall);
        func_800C4AF0(arg0->position, D_8080046C_chLagoonInnBlockedWall);
        return 1;
    }
    return 0;
}

OSThread *chLagoonInnBlockedWall_entrypoint_0(void)
{
    extern u8 D_80800480_chLagoonInnBlockedWall[];

    return (OSThread *) D_80800480_chLagoonInnBlockedWall;
}

void func_8080025C_chLagoonInnBlockedWall(Actor *arg0, s32 arg1) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800FFAB0(Actor *);
    s32 func_80101180(s32, s32, s32);
    void func_80109704(s32, s32, s32, s32, f32, s32, s32, s32);
    extern s32 D_808004C8_chLagoonInnBlockedWall;
    extern s32 D_80800514_chLagoonInnBlockedWall;
    extern s32 D_80800528_chLagoonInnBlockedWall;
    extern s32 D_8080054C_chLagoonInnBlockedWall;
    f32 sp34[3];

    func_800EE7F8(sp34, arg0->position);
    sp34[1] += 80.0f;
    func_800BBCB8(sp34, NULL, arg0->scale * 1.2f, 8, &D_80800528_chLagoonInnBlockedWall);
    func_800BBCB8(sp34, NULL, arg0->scale * 1.2f, 0x10, &D_808004C8_chLagoonInnBlockedWall);
    func_800BBCB8(sp34, sp34, arg0->scale, 0xF, &D_8080054C_chLagoonInnBlockedWall);
    func_80109704((s32)arg0, 8, -0x28, 0xC8, 1.85f, 0xB4, 0x3C, 0x50);
    _subaddieaudioquick_entrypoint_2(arg0, sp34, &D_80800514_chLagoonInnBlockedWall);
    func_800FFAB0(arg0);
    func_80101180(0x488, 5, 0);
}

s32 func_80800398_chLagoonInnBlockedWall(s32 arg0, s32 arg1, volatile s32 arg2) {
    if (arg1 == 0x40) {
        func_8080025C_chLagoonInnBlockedWall(arg0, *(s32 *)&arg2);
        return 1;
    }
    return 0;
}

OSThread *chLagoonInnBlockedWall_entrypoint_1(void)
{
    extern u8 D_80800570_chLagoonInnBlockedWall[];

    return (OSThread *) D_80800570_chLagoonInnBlockedWall;
}
