#include "common.h"

OSThread *chcaveofhorrorsdoors_entrypoint_0(void)
{
    extern ActorData D_808001C0_chcaveofhorrorsdoors[];

    return (OSThread *) D_808001C0_chcaveofhorrorsdoors;
}

/* extern */

void func_8080000C_chcaveofhorrorsdoors(BtIntPtr arg0 BT_PASS2(, s32 bt_a1) BT_PASS2(, s32 bt_a2) BT_PASS2(, s32 bt_a3)) {
    s32 _subaddiefade_entrypoint_14(BtIntPtr);
    s32 func_800DA298(s32);
    void func_800FFAB0(Actor *actor);
    void func_80109EEC(s16 *arg0, s32 arg1);
    void func_8010A63C(Actor *arg0);
    s32 func_808001A4_chcaveofhorrorsdoors(BtIntPtr);
    if (func_800DA298(func_808001A4_chcaveofhorrorsdoors(arg0)) != 0) {
        func_800FFAB0(arg0);
        return;
    }
    func_80109EEC(arg0, 0x40);
    _subaddiefade_entrypoint_14(arg0);
    func_8010A63C(arg0);
}

s32 func_8080006C_chcaveofhorrorsdoors(Actor *arg0, s32 arg1, volatile s32 arg2) {
    void _chexploder_entrypoint_3(void *, void *, u32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    BtUIntPtr func_800F54E4(void);
    s32 func_800F8300(BtIntPtr, s32, BtIntPtr);
    void func_80800144_chcaveofhorrorsdoors(BtIntPtr);
    f32 sp2C[3];

    switch (arg1) {
    case 0x40:
        func_800EE7F8(sp2C, arg0->position);
        sp2C[1] += 150.0f;
        func_800EF1B8(sp2C, arg0->rotation[1], -80.0f);
        _chexploder_entrypoint_3(arg0, sp2C, 7);
        if ((s32)arg0->unk74_7 < 0x34) {
            func_800F8300(func_800F54E4(), 2, (BtIntPtr)arg0->position);
        }
        break;
    case 0x90:
        func_80800144_chcaveofhorrorsdoors((BtIntPtr)arg0);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800144_chcaveofhorrorsdoors(BtIntPtr arg0) {
    void _chexploder_entrypoint_12(Actor *arg0, s32 arg1);
    void func_800C4AF0(f32 *arg0, void *arg1);
    void func_800DA544(s32 index);
    void func_800FFAB0(Actor *actor);
    BtIntPtr func_80101080();
    BtIntPtr func_80106790(BtIntPtr);
    s32 func_808001A4_chcaveofhorrorsdoors(BtIntPtr);
    extern s32 D_80800208_chcaveofhorrorsdoors[6];
    _chexploder_entrypoint_12(func_80106790(func_80101080()), 0x3C);
    func_800C4AF0(arg0 + 4, D_80800208_chcaveofhorrorsdoors);
    func_800DA544(func_808001A4_chcaveofhorrorsdoors(arg0));
    func_800FFAB0(arg0);
}    typedef struct { u8 pad0[0x76]; u16 unk76; } Objcaveofhorrorsdoors_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

s32 func_808001A4_chcaveofhorrorsdoors(BtIntPtr arg0) {
    return ((u32) (((Objcaveofhorrorsdoors_arg0 *)arg0)->unk76) >> 7) + 0x65;
}
/* data_to_c.py: from asm/data/overlays/ch/caveofhorrorsdoors.data.s */
void func_80102EC0();
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
OSThread *func_80108ED0(void);
void func_80107C2C();
ActorData D_808001C0_chcaveofhorrorsdoors [1] BT_DATA(4, overlays_ch_caveofhorrorsdoors, 0x0) = { { 410, 332, 1931, 1, 0, (void (*)(struct Actor *))func_80102EC0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 2, 0, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_8080000C_chcaveofhorrorsdoors, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 11280, (void (*)(struct Actor *, long, long))func_8080006C_chcaveofhorrorsdoors, 0 } };
s32 D_80800208_chcaveofhorrorsdoors[6] BT_DATA(4, overlays_ch_caveofhorrorsdoors, 0x48) = { 1246408, 655590, 1572865, 52433800, 0, 0 };
