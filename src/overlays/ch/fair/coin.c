#include "common.h"

void func_80800000_chfaircoin(Actor *arg0) {
    f32 func_8001395C(f32);
    u8 func_800D9078(f32 *);
    void func_800EFE50(f32 *, f32 *, f32 *, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_800FC660(u32);
    void func_800FFAB0(Actor *);
    f32 sp2C;
    f32 temp_f0;

    func_800D9078((f32 *)arg0->actorData + 3);
    temp_f0 = func_800F10B4(((f32 *)arg0->actorData)[3], arg0->unk58, 0.0f, 0.0f, 1.0f);
    sp2C = temp_f0;
    func_800EFE50(arg0->position, (f32 *)arg0->actorData + 4, (f32 *)arg0->actorData, temp_f0);
    arg0->position[1] += func_8001395C(sp2C * 3.1415927f) * 200.0f;
    if (((f32 *)arg0->actorData)[3] == 0.0f) {
        func_800FFAB0(arg0);
        func_800FC660(0xE);
    }
}

u8 *chfaircoin_entrypoint_0(s32 arg0, s32 arg1, f32 arg2) {
    s32 func_800C4AF0(s32, s32 *);
    s32 func_800EE7F8(u8 *, s32);
    u8 *func_80108474(s32, s32, s32);
    extern s32 D_80800150_chfaircoin;
    u8 *temp_v0;

    temp_v0 = func_80108474(0x166, arg0, 0);
    func_800EE7F8(temp_v0 + 0x18, arg1);
    func_800EE7F8(temp_v0 + 0x28, arg0);
    (*(f32 *)((s8 *)(temp_v0) + (0x24))) = arg2;
    (*(f32 *)((s8 *)(temp_v0) + (0x58))) = arg2;
    func_800C4AF0(0, &D_80800150_chfaircoin);
    return temp_v0;
}

OSThread *chfaircoin_entrypoint_1(void)
{
    extern u8 D_8080015C_chfaircoin[];

    return (OSThread *) D_8080015C_chfaircoin;
}
