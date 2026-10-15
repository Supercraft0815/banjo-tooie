#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/smalltrexdoor/func_80800000_chsmalltrexdoor.s")

/* extern */

void func_80800150_chsmalltrexdoor(Actor *arg0) {
    s32 _chdoor_entrypoint_0();
    s32 func_800D90A4(f32 *);
    f32 func_800EEAD4(f32 *, f32 *);
    f32 func_800F1DF4(f32 *, f32 *);
    f32 func_800F2094(f32, f32);
    u32 func_800F54E4(void);
    void func_800F5A00(s32, f32 *);
    s32 func_8010108C();
    f32 sp2C[3];
    f32 sp28;

    if ((arg0->unk70_10 == 4) && (func_800D90A4((f32 *)&arg0->actorData[7]) != 0)) {
        func_800F5A00(func_800F54E4(), sp2C);
        sp28 = func_800F1DF4(arg0->position, sp2C);
        if (func_800EEAD4(sp2C, arg0->position) < 400.0f) {
            if (func_800F2094(arg0->rotation[1] - 90.0f, sp28) > 30.0f) {
                func_8010108C(arg0, 8, 0);
            }
        } else {
            func_8010108C(arg0, 8, 0);
        }
    }
    _chdoor_entrypoint_0(arg0);
}

/* extern */

void func_80800244_chsmalltrexdoor(Actor *arg0, s32 arg1, s32 arg2) {
    typedef struct {
        s32 unk0[7];
        f32 unk1C;
    } DoorData;
    s32 _chdoor_entrypoint_1(Actor *, s32, s32);
    s32 func_800F52B8(s32, Unk80132ED0 *);
    u32 func_800F54E4(void);
    if (((arg1 == 0x1D) || (arg1 == 0x1E)) && (func_800F52B8(func_800F54E4(), arg0->unk0) == 0x18)) {
        ((DoorData *)arg0->actorData)->unk1C = 4.0f;
        _chdoor_entrypoint_1(arg0, 7, 0);
        return;
    }
    _chdoor_entrypoint_1(arg0, arg1, arg2);
}

OSThread *chsmalltrexdoor_entrypoint_0(void)
{
    extern u8 D_808002E0_chsmalltrexdoor[];

    return (OSThread *) D_808002E0_chsmalltrexdoor;
}
