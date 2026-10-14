#include "common.h"

/* extern */

s32 func_80800000_chgate1doors(Actor *arg0, s32 arg1, s32 arg2) {
    s32 func_800DA544(s32);
    void func_80103110(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    void func_8010A570(Actor *);
    Actor *sp1C;
    s32 result;

    if (arg1 == 0x40) {
        sp1C = func_80106790(arg0->unk3C);
        if ((s32)arg0->unk70_10 < 3) {
            func_80103110(arg0, 1);
        }
        if ((s32)sp1C->unk70_10 < 3) {
            func_80103110(sp1C, 1);
        }
        func_8010A570(arg0);
        func_8010A570(sp1C);
        func_800DA544(0xB1);
        result = 1;
    } else {
        return 0;
    }
    return result;
}

/* extern */

void func_808000A4_chgate1doors(Actor *arg0) {
    Actor *_subaddiefind_entrypoint_0(f32 *, s32, s32, s32);
    s32 func_800DA298(s32);
    void func_80101FDC(Actor *, u32);
    void func_8010A570(Actor *);
    Actor *temp_v0;

    if (func_800DA298(0xB1) != 0) {
        arg0->rotation[1] = 90.0f;
        func_8010A570(arg0);
        func_80101FDC(arg0, 3);
        return;
    }
    temp_v0 = _subaddiefind_entrypoint_0(arg0->position, 0x129, -1, 0);
    if (temp_v0 != NULL) {
        temp_v0->unk3C = arg0->unk0;
        arg0->unk3C = temp_v0->unk0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gate1doors/func_80800128_chgate1doors.s")

/* extern */

void func_808002B0_chgate1doors(Actor *arg0) {
    Actor *_subaddiefind_entrypoint_0(f32 *, s32, s32, s32);
    s32 func_800DA298(s32);
    void func_80101FDC(Actor *, u32);
    void func_8010A570(Actor *);
    Actor *temp_v0;

    if (func_800DA298(0xB1) != 0) {
        arg0->rotation[1] = -90.0f;
        func_8010A570(arg0);
        func_80101FDC(arg0, 3);
        return;
    }
    temp_v0 = _subaddiefind_entrypoint_0(arg0->position, 0x128, -1, 0);
    if (temp_v0 != NULL) {
        temp_v0->unk3C = arg0->unk0;
        arg0->unk3C = temp_v0->unk0;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/gate1doors/func_80800334_chgate1doors.s")

OSThread *chgate1doors_entrypoint_0(void)
{
    extern u8 D_808004B8_chgate1doors[];

    return (OSThread *) D_808004B8_chgate1doors;
}

OSThread *chgate1doors_entrypoint_1(void)
{
    extern u8 D_80800500_chgate1doors[];

    return (OSThread *) D_80800500_chgate1doors;
}
