#include "common.h"

OSThread *chvandoor_entrypoint_0(void)
{
    extern ActorData D_80800640_chvandoor[];

    return (OSThread *) D_80800640_chvandoor;
}

void func_8080000C_chvandoor(Actor *arg0) {
    void _subaddieDll_entrypoint_0(void *arg0);
    s32 func_800DA298(s32);
    void func_800DA524(s32);
    s32 func_800EA05C();
    void func_800EE7F8(f32 *, f32 *);
    u32 func_800F54E4(void);
    s32 func_800F64A4(BtIntPtr, s32);
    void func_8010A800(Actor *, s32);
    void func_80800388_chvandoor(Actor *, s32);
    s32 sp2C;

    sp2C = arg0->unk74_7 + 0xA08;
    func_800EE7F8((f32 *)&arg0->actorData[0], arg0->position);
    func_800EE7F8((f32 *)&arg0->actorData[4], arg0->position);
    ((f32 *)arg0->actorData)[5] += arg0->scale * 300.0f;
    *(s32 *)&arg0->unk50 = sp2C;
    if (func_800F64A4(func_800F54E4(), 0x8000) == 0) {
        func_800DA524(sp2C);
    }
    if (func_800DA298(sp2C) != 0) {
        func_80800388_chvandoor(arg0, 3);
        func_800EE7F8(arg0->position, (f32 *)&arg0->actorData[4]);
    } else {
        func_80800388_chvandoor(arg0, 1);
    }
    func_8010A800(arg0, 0);
    if (func_800EA05C() == 0xE7) {
        _subaddieDll_entrypoint_0(arg0);
    }
}

void func_80800104_chvandoor(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    s32 func_800D9078(f32 *);
    void func_800EFE50(f32 *, f32 *, f32 *, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    s32 func_80101180(s32, s32, BtIntPtr);
    void func_80800388_chvandoor(Actor *, s32);
    s32 func_8080044C_chvandoor(Actor *);
    extern u32 D_80800688_chvandoor;
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 sp28;
    f32 *position;

    sp34 = 0;
    switch (arg0->unk70_10) {
    case 1:
        position = arg0->position;
        break;
    case 2:
        sp30 = func_800D9078(&arg0->unk58);
        position = arg0->position;
        func_800EFE50(position, (f32 *)&arg0->actorData[0], (f32 *)&arg0->actorData[4],
            func_800F10B4(arg0->unk58, 0.0f, 2.0f, 1.0f, 0.0f));
        if (sp30 != 0) {
            func_80800388_chvandoor(arg0, 3);
        }
        sp34 = sp30 == 0;
        break;
    case 3:
        if (func_8080044C_chvandoor(arg0) != 0) {
            func_80101180(0x3CC, 8, arg0->unk74_7);
        }
        position = arg0->position;
        break;
    case 4:
        sp28 = func_800D9078(&arg0->unk58);
        position = arg0->position;
        func_800EFE50(position, (f32 *)&arg0->actorData[0], (f32 *)&arg0->actorData[4],
            func_800F10B4(arg0->unk58, 0.0f, 2.0f, 0.0f, 1.0f));
        if (sp28 != 0) {
            func_80800388_chvandoor(arg0, 1);
        }
        sp34 = sp28 == 0;
        break;
    default:
        position = arg0->position;
        break;
    }
    _subaddieaudioloop_entrypoint_4(arg0, position, sp34, &D_80800688_chvandoor);
}

/* extern */

s32 func_80800280_chvandoor(Actor *arg0, s32 arg1, s32 arg2) {
    f32 func_800EEB40(f32 *, f32 *);
    void func_800F5A00(BtIntPtr, f32 *);
    s32 func_80101180(s32, s32, BtIntPtr);
    void func_80800388_chvandoor(Actor *, s32);
    f32 sp1C[3];

    switch (arg1) {
    case 0x19:
        if (arg0->unk70_10 == 1) {
            func_800F5A00(arg2, sp1C);
            if (func_800EEB40(sp1C, arg0->position) < 250000.0f) {
                func_80101180(0x3CC, 7, arg0->unk74_7);
            }
        }
        break;
    case 7:
        if (arg2 != arg0->unk74_7) {
            return 0;
        }
        func_80800388_chvandoor(arg0, 2);
        break;
    case 8:
        if (arg2 != arg0->unk74_7) {
            return 0;
        }
        func_80800388_chvandoor(arg0, 4);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800388_chvandoor(Actor *arg0, s32 arg1) {
    void func_80101FDC(Actor *, u32);
    void func_80103110(Actor *, u32);
    void func_800DA524(s32);
    void func_800DA544(s32);

    func_80101FDC(arg0, arg1);
    switch (arg1) {
    case 1:
        func_80103110(arg0, 0);
        func_800DA524(*(s32 *)&arg0->unk50);
        break;
    case 2:
        func_80103110(arg0, 1);
        arg0->unk58 = 2.0f;
        func_800DA544(*(s32 *)&arg0->unk50);
        break;
    case 3:
        func_80103110(arg0, 1);
        break;
    case 4:
        arg0->unk58 = 2.0f;
        break;
    }
}

s32 func_8080044C_chvandoor(Actor *arg0) {
    Actor *_subaddiefind_entrypoint_2(s32, s32 *);
    Actor *_subaddiefind_entrypoint_3(s32, s32 *);
    f32 func_800EEB40(f32 *, f32 *);
    void func_800F5A00(BtIntPtr, f32 *);
    BtIntPtr func_8010D290(s32);
    extern Actor *B_80800690_chvandoor[];
    extern Actor *B_80800694_chvandoor;
    f32 position[3];
    Actor *actor;
    s32 cursor;
    BtIntPtr player;
    s32 i;
    s32 j;
    s32 count;
    Actor *temp;

    player = func_8010D290(0x10000);
    count = 0;
    if (player == -1) {
        return 0;
    }
    func_800F5A00(player, position);
    for (actor = _subaddiefind_entrypoint_2(0x3CC, &cursor); actor != NULL;
         actor = _subaddiefind_entrypoint_3(0x3CC, &cursor)) {
        if (arg0->unk74_7 == actor->unk74_7) {
            B_80800690_chvandoor[count++] = actor;
        }
    }
    for (i = 1; i < count; i++) {
        j = i;
        if (j > 0 &&
            func_800EEB40(B_80800690_chvandoor[j]->position, position) <
            func_800EEB40(B_80800690_chvandoor[j - 1]->position, position)) {
            do {
                temp = B_80800690_chvandoor[j];
                B_80800690_chvandoor[j] = B_80800690_chvandoor[j - 1];
                B_80800690_chvandoor[j - 1] = temp;
                j--;
            } while (&B_80800690_chvandoor[j] >= &B_80800694_chvandoor &&
                     func_800EEB40(B_80800690_chvandoor[j]->position, position) <
                     func_800EEB40(B_80800690_chvandoor[j - 1]->position, position));
        }
    }
    if (arg0 != B_80800690_chvandoor[0]) {
        return 0;
    }
    return func_800EEB40(B_80800690_chvandoor[0]->position, position) > 2250000.0f;
}
/* data_to_c.py: from asm/data/overlays/ch/vandoor.data.s */
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
ActorData D_80800640_chvandoor [1] BT_DATA(4, overlays_ch_vandoor, 0x0) = { { 172, 972, 1957, 1, 0, (void (*)(struct Actor *))func_80800104_chvandoor, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 16384, 2048, 0, 0, 0, 0, (void (*)(struct Actor *))func_8080000C_chvandoor, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 11282, (void (*)(struct Actor *, long, long))func_80800280_chvandoor, 0 } };
u32 D_80800688_chvandoor BT_DATA(4, overlays_ch_vandoor, 0x48) = 0x130507;

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
Actor * B_80800690_chvandoor [ 1 ] BT_DATA(16, bss_ch_vandoor, 0x0);
Actor * B_80800694_chvandoor BT_DATA(4, bss_ch_vandoor, 0x4);
#endif
