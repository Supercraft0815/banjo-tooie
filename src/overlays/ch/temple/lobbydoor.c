#include "common.h"

OSThread *chtemplelobbydoor_entrypoint_0(void)
{
    extern u8 D_808003A0_chtemplelobbydoor[];

    return (OSThread *) D_808003A0_chtemplelobbydoor;
}

/* extern */

void func_8080000C_chtemplelobbydoor(s32 arg0) {
    s32 _chdoormake_entrypoint_3(s32, f32, f32, f32, s32, s32);
    s32 _chdoormake_entrypoint_5(s32, f32);
    s32 _chdoormake_entrypoint_8(s32, s32);
    s32 func_800D035C(s32);
    s32 func_800EA090();
    s32 func_800F5410(s32);
    s32 func_80101FDC(s32, s32);
    s32 sp24;
    s32 temp_t8;

    if ((func_800EA090() == 1) && ((sp24 = func_800D035C(5) < 0x14, temp_t8 = func_800F5410(0) ^ 1, (sp24 != 0)) || (temp_t8 != 0))) {
        func_80101FDC(arg0, 1);
    }
    if (_chdoormake_entrypoint_3(arg0, 0.0f, 90.0f, 180.0f, 8, -1) != 0) {
        _chdoormake_entrypoint_5(arg0, 1.5f);
        _chdoormake_entrypoint_8(arg0, 5);
    }
}

void func_808000B4_chtemplelobbydoor(s32 arg0) 
{
}
void func_808000BC_chtemplelobbydoor(s32 arg0)
{
    func_808000E4_chtemplelobbydoor();
    _chdoor_entrypoint_0(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/temple/lobbydoor/func_808000E4_chtemplelobbydoor.s")

void func_80800134_chtemplelobbydoor(Actor *arg0, s32 arg1) {
    void _bsfirstp_entrypoint_18(void);
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    u32 func_8009E958(void);
    int func_800C6E38(s32);
    void func_800C9CD0(f32, s32, s32, s32, f32 *, s16);
    s32 func_800DA298(s32);
    s32 func_800DA9E4(s32, s32);
    s32 func_800EA090(void);
    void func_800F49D4(s32, void *, s32);
    u32 func_800F54E4(void);
    void *func_80100094(Actor *, u32);
    s8 *sp24;

    sp24 = func_80100094(arg0, 0);
    *sp24 = 0;
    switch (func_800EA090()) {
        case 1:
            if (func_800C6E38(0x15) && func_8009E958() == 1 && !func_800DA9E4(0x6B8, 1)) {
                *sp24 = 1;
                _capod_entrypoint_13(arg0->unk0, NULL, 3, 0x2020);
                func_800F49D4(func_800F54E4(), _bsfirstp_entrypoint_18, 0);
            }
            break;
        case 2:
            if (!func_800DA298(0x36F)) {
                func_800C9CD0(0.8f, arg0->unk0, 0xF50, 2, NULL, 0xB2);
                _capod_entrypoint_13(arg0->unk0, NULL, 1, 0x2020);
            }
            break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/temple/lobbydoor/func_80800248_chtemplelobbydoor.s")
