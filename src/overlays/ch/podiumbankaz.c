#include "common.h"

/* extern */

void func_80800000_chpodiumbankaz(BtIntPtr arg0) {
    void _subaddiefade_entrypoint_1(void *arg0, s32 arg1);
    s32 func_800C6E38(s32);
    if (func_800C6E38(0x1C) != 0) {
        _subaddiefade_entrypoint_1(arg0, 0xFF);
        return;
    }
    _subaddiefade_entrypoint_1(arg0, 0x87);
}

/* extern */

void func_80800044_chpodiumbankaz(Actor *arg0) {
    s32 _subaddiedialog_entrypoint_1(f32 *, u32, s32);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    s32 func_800DA298(s32);
    void func_800DA544(s32 index);

    if (func_800DA298(0x4F4) == 0) {
        if ((_subaddiedialog_entrypoint_1(arg0->position, 0xFA, 0) != 0) && (_subaddiedialog_entrypoint_11(arg0->unk0, 0xD82, 0xE, arg0->position, 0) != 0)) {
            func_800DA544(0x4F4);
        }
    }
}

void func_808000B8_chpodiumbankaz(Actor *arg0) {
    s32 func_800F6BE4(BtIntPtr);
    s32 func_800F7B9C(BtIntPtr, s32);
    void func_80101FDC(Actor *, u32);

    switch (arg0->unk70_10) {
        case 1:
            func_80800044_chpodiumbankaz(arg0);
            return;
        case 2:
            func_80101FDC(arg0, 3);
            return;
        case 3:
            if ((func_800F6BE4(arg0->unk79_4) == 0) ||
                (func_800F7B9C(arg0->unk79_4, 4) == 2)) {
                func_80101FDC(arg0, 1);
            }
            return;
    }
}

void func_80800170_chpodiumbankaz(Actor *arg0) {
    s32 func_800F6BE4(BtIntPtr);
    s32 func_800F7B9C(BtIntPtr, s32);
    void func_80101FDC(Actor *, u32);

    switch (arg0->unk70_10) {
        case 1:
            func_80800044_chpodiumbankaz(arg0);
            return;
        case 2:
            func_80101FDC(arg0, 3);
            return;
        case 3:
            if ((func_800F6BE4(arg0->unk79_4) == 0) ||
                (func_800F7B9C(arg0->unk79_4, 5) == 2)) {
                func_80101FDC(arg0, 1);
            }
            return;
    }
}

/* extern */

void func_80800228_chpodiumbankaz(Unk80132ED0 *arg0, s32 arg1) {
    s32 _sudeflect_entrypoint_1(f32 *arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4);
    s32 func_800C6E38(s32);
    s32 func_800F5410(BtIntPtr);
    void func_800F5A00(BtIntPtr, f32 *);
    s32 func_800F7D38(BtIntPtr, s32, void *, f32);
    void func_80101FDC(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    Actor *actor;
    s32 sp38;
    f32 sp2C[3];

    if (func_800C6E38(0x1C) != 0) {
        sp38 = func_800F5410(arg1);
        actor = func_80106790(arg0);
        if (((sp38 == 1) || (sp38 == 0xA)) &&
            ((actor->unk70_10 == 3) ||
             (func_800F7D38(arg1, 0x3A, actor->position, actor->rotation[1]) == 2))) {
            if (sp38 == 0xA) {
                func_800F5A00(arg1, sp2C);
                _sudeflect_entrypoint_1(sp2C, 125.0f, 0.0f, 40.0f, 0x1C);
            }
            actor->unk79_4 = arg1;
            func_80101FDC(actor, 2);
        }
    }
}

/* extern */

void func_80800318_chpodiumbankaz(Unk80132ED0 *arg0, s32 arg1) {
    s32 func_800C6E38(s32);
    s32 func_800F5410(BtIntPtr);
    s32 func_800F7CF4(BtIntPtr, s32, void *);
    void func_80101FDC(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    Actor *sp1C;
    s32 sp18;

    if (func_800C6E38(0x1C) != 0) {
        sp18 = func_800F5410(arg1);
        sp1C = func_80106790(arg0);
        if ((sp18 == 0xB) && ((sp1C->unk70_10 == 3) || (func_800F7CF4(arg1, 0x3B, sp1C->position) == 2))) {
            sp1C->unk79_4 = arg1;
            func_80101FDC(sp1C, 2);
        }
    }
}

void func_808003C4_chpodiumbankaz(BtIntPtr arg0, s32 arg1) {
    void _subaddiefade_entrypoint_1(void *arg0, s32 arg1);
    if (arg1 == 0x1C) {
        _subaddiefade_entrypoint_1(arg0, 0xFF);
    }
}

s32 func_808003EC_chpodiumbankaz(Actor *arg0, s32 arg1, s32 arg2) {
    s32 func_800DA298(s32);

    switch (arg1) {
        case 0x1A:
            func_808003C4_chpodiumbankaz((BtIntPtr)arg0, arg2);
            return 1;
        case 0x91:
            if (func_800DA298(0xA84) != 0) {
                func_80800228_chpodiumbankaz(arg0->unk0, arg2);
            }
            return 1;
        default:
            return 0;
    }
}

s32 func_80800464_chpodiumbankaz(Actor *arg0, s32 arg1, s32 arg2) {
    s32 func_800DA298(s32);

    switch (arg1) {
        case 0x1A:
            func_808003C4_chpodiumbankaz((BtIntPtr)arg0, arg2);
            return 1;
        case 0x91:
            if (func_800DA298(0xAC2) != 0) {
                func_80800318_chpodiumbankaz(arg0->unk0, arg2);
            }
            return 1;
        default:
            return 0;
    }
}

OSThread *chpodiumbankaz_entrypoint_0(void)
{
    extern ActorData D_80800500_chpodiumbankaz[];

    return (OSThread *) D_80800500_chpodiumbankaz;
}

OSThread *chpodiumbankaz_entrypoint_1(void)
{
    extern ActorData D_80800548_chpodiumbankaz[];

    return (OSThread *) D_80800548_chpodiumbankaz;
}
/* data_to_c.py: from asm/data/overlays/ch/podiumbankaz.data.s */
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
OSThread *func_80108ED0(void);
void func_80107C2C();
ActorData D_80800500_chpodiumbankaz [1] BT_DATA(4, overlays_ch_podiumbankaz, 0x0) = { { 617, 343, 2018, 1, 0, (void (*)(struct Actor *))func_808000B8_chpodiumbankaz, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 32768000, 0, 0, 0, 16384, 2068, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_80800000_chpodiumbankaz, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 9234, (void (*)(struct Actor *, long, long))func_808003EC_chpodiumbankaz, 0 } };
ActorData D_80800548_chpodiumbankaz [1] BT_DATA(4, overlays_ch_podiumbankaz, 0x48) = { { 616, 342, 2017, 1, 0, (void (*)(struct Actor *))func_80800170_chpodiumbankaz, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 32768000, 0, 0, 0, 16384, 2068, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_80800000_chpodiumbankaz, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 9234, (void (*)(struct Actor *, long, long))func_80800464_chpodiumbankaz, 0 } };
