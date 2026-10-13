#include "common.h"

OSThread *chboggyboy_entrypoint_0(void)
{
    extern u8 D_80800CB8_chboggyboy[];

    return (OSThread *) D_80800CB8_chboggyboy;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boggy/boy/func_8080000C_chboggyboy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boggy/boy/func_808000B8_chboggyboy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boggy/boy/func_80800570_chboggyboy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boggy/boy/func_808006C4_chboggyboy.s")

void func_808007F4_chboggyboy(Actor *arg0) {
    s32 _subaddiefx_entrypoint_1(Actor *, u8 *);
    void func_80800AD0_chboggyboy(Actor *);
    _subaddiefx_entrypoint_1(arg0, (u8 *)func_80100094(arg0, 0U) + 0x18);
    func_80800AD0_chboggyboy(arg0);
}

void func_8080082C_chboggyboy(Actor *arg0) {
    s16 _glsplinefind_entrypoint_0(u32, f32 *);
    void func_800EE940(void *, f32 *);
    void *sp24;
    f32 sp18[3];

    sp24 = func_80100094(arg0, 0U);
    ((s16 *)sp24)[3] = _glsplinefind_entrypoint_0(0x3A1U, sp18);
    func_800EE940(sp24, sp18);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boggy/boy/func_8080086C_chboggyboy.s")

void func_80800978_chboggyboy(Actor *arg0, s32 arg1) {
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 func_80102424(s32, s32);
    void *sp2C;
    struct Flags { u8 pad[0x16]; u8 high : 1; u8 flag : 1; u8 low : 6; };

    sp2C = func_80100094(arg0, 0);
    _subaddiedialog_entrypoint_11(arg0->unk0, 0x108A, 0xE, (f32 *)((s8 *)arg0 + 4), 0x3B);
    func_80102424((s32)arg0, 0xE);
    func_8010A570(arg0);
    ((struct Flags *)sp2C)->high = 1;
    ((struct Flags *)sp2C)->flag = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/boggy/boy/func_808009F4_chboggyboy.s")

/* extern */

void func_80800A64_chboggyboy(Actor *arg0) {
    s32 _suexpression_entrypoint_12(void *, s32, s32);
    s32 _suexpression_entrypoint_17(void *, s32);
    s32 _suexpression_entrypoint_7(Actor *, s32, s32);
    if (func_80100094(arg0, 1U) == NULL) {
        _suexpression_entrypoint_7(arg0, 1, 0x3B);
        _suexpression_entrypoint_12(func_80100094(arg0, 1U), 0x42700000, 0x41A00000);
        _suexpression_entrypoint_17(func_80100094(arg0, 1U), 0x3E8);
    }
}

/* extern */

void func_80800AD0_chboggyboy(Actor *arg0) {
    s32 _suexpression_entrypoint_8(Actor *, s32);
    if (func_80100094(arg0, 1U) != NULL) {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
