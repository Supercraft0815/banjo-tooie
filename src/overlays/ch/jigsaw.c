#include "common.h"

/* extern */

void func_80800000_chjigsaw(Actor *arg0, void *arg1) {
    struct { u8 unk0[0x1A]; u16 unk1A; } *data = arg1;
    s32 _suautobaddies_entrypoint_3();
    void func_800D0BD4(s32, u32);
    s32 func_800DA298(s32);
    void func_80108B04(Actor *, u32);
    s32 func_8010A6B0(Actor *, u32);
    if ((func_8010A6B0(arg0, (u32)data->unk1A >> 5) != 0) && (func_800DA298(0x665) == 0)) {
        func_80108B04(arg0, 0);
        func_800D0BD4((s32)arg0->unk50, 1);
        _suautobaddies_entrypoint_3();
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jigsaw/func_80800070_chjigsaw.s")

/* extern */

void func_8080011C_chjigsaw(Actor *arg0) {
    f32 func_800D8FF8(void);
    f32 temp_f2;

    arg0->unk54 += func_800D8FF8() * 230.0f;
    temp_f2 = arg0->unk54;
    if (temp_f2 >= 360.0f) {
        arg0->unk54 = temp_f2 - 360.0f;
    }
}

/* extern */

void func_8080017C_chjigsaw(Actor *arg0) {
    void func_800C8B84(s32);
    void func_800D05E4(s32, s32, s32);

    func_800D05E4((s32)arg0->unk50, 1, 0);
    if ((u32)arg0->unk6C_0 != 0) {
        func_800C8B84(arg0->unk6C_0);
    }
}

void func_808001D0_chjigsaw(s32 arg0)
{
    func_80105834();
    func_8080011C_chjigsaw(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jigsaw/func_808001F8_chjigsaw.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jigsaw/func_808004A0_chjigsaw.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/jigsaw/func_80800518_chjigsaw.s")

OSThread *chjigsaw_entrypoint_0(void)
{
    extern u8 D_80800770_chjigsaw[];

    return (OSThread *) D_80800770_chjigsaw;
}

/* extern */

void func_808006CC_chjigsaw(s32 arg0) {
    s32 _gcfrontend_entrypoint_9(s32);
    s32 _subaddiedialog_entrypoint_11(s32, s32, s32, s32, s32);
    s32 _subaddiedialog_entrypoint_16();
    s32 func_800D395C();
    s32 func_800FFAB0(s32);
    if (func_800D395C() != 0) {
        func_800FFAB0(arg0);
        return;
    }
    if ((_subaddiedialog_entrypoint_16() != 0) && (_subaddiedialog_entrypoint_11(0, 0xD0A, 0, arg0 + 4, 0x6F) != 0)) {
        _gcfrontend_entrypoint_9(0x85);
        func_800FFAB0(arg0);
    }
}

OSThread *chjigsaw_entrypoint_1(void)
{
    extern u8 D_808007B8_chjigsaw[];

    return (OSThread *) D_808007B8_chjigsaw;
}
