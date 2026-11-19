#include "common.h"

void func_80800000_chsmalltrexdoor(Actor *arg0) {
    void _chdoormake_entrypoint_2(Actor *, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_5(Actor *, f32);
    void _chdoormake_entrypoint_6(Actor *, s32);
    void _chdoormake_entrypoint_8(void *, u32);
    s32 *func_800BEF00(f32 *, f32 *, f32 *, s32);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EEAD4(f32 *, f32 *);
    s32 func_800F5410(BtIntPtr);
    u32 func_800F54E4(void);
    void func_800F5A00(BtIntPtr, f32 *);
    void func_80101FDC(Actor *, u32);
    f32 func_80103EAC(Actor *);
    f32 sp44[3];
    f32 sp38[3];

    if (func_800F5410(func_800F54E4()) == 0x12) {
        func_800F5A00(func_800F54E4(), sp44);
        if (func_800EEAD4(sp44, arg0->position) < 500.0f) {
            arg0->unk64_20 = 1;
            func_80101FDC(arg0, 4);
        }
    }
    func_800EE7F8(sp44, arg0->position);
    sp44[1] += 100.0f;
    arg0->position[1] -= 100.0f;
    func_800BEF00(sp44, arg0->position, sp38, 0);
    arg0->position[1] += func_80103EAC(arg0);
    _chdoormake_entrypoint_2(arg0, arg0->rotation[1] + 90.0f, 0.0f, arg0->scale * 200.0f, 10, -1);
    _chdoormake_entrypoint_5(arg0, 1.0f);
    _chdoormake_entrypoint_6(arg0, 0x3F000000);
    _chdoormake_entrypoint_8(arg0, 5);
}

/* extern */

void func_80800150_chsmalltrexdoor(Actor *arg0) {
    void _chdoor_entrypoint_0(BtIntPtr arg0);
    s32 func_800D90A4(f32 *);
    f32 func_800EEAD4(f32 *, f32 *);
    f32 func_800F1DF4(f32 *, f32 *);
    f32 func_800F2094(f32, f32);
    u32 func_800F54E4(void);
    void func_800F5A00(BtIntPtr, f32 *);
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
    s32 _chdoor_entrypoint_1(Actor *, s32, BtIntPtr);
    s32 func_800F52B8(BtIntPtr, Unk80132ED0 *);
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
    extern ActorData D_808002E0_chsmalltrexdoor[];

    return (OSThread *) D_808002E0_chsmalltrexdoor;
}
/* data_to_c.py: from asm/data/overlays/ch/smalltrexdoor.data.s */
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
ActorData D_808002E0_chsmalltrexdoor [1] BT_DATA(4, overlays_ch_smalltrexdoor, 0x0) = { { 172, 655, 2184, 1, 0, (void (*)(struct Actor *))func_80800150_chsmalltrexdoor, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 327680000, 0, 0, 0, 0, 2048, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800000_chsmalltrexdoor, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 25602, (void (*)(struct Actor *, long, long))func_80800244_chsmalltrexdoor, 0 } };
