#include "common.h"

OSThread *chtransparencypot_entrypoint_0(void)
{
    extern ActorData D_808001B0_chtransparencypot[];

    return (OSThread *) D_808001B0_chtransparencypot;
}    typedef struct { u8 pad0[0x38]; f32 unk38; } Objtransparencypot_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_8080000C_chtransparencypot(void *arg0) {
    (((Objtransparencypot_arg0 *)arg0)->unk38) = 0.5f;
}

void func_8080001C_chtransparencypot(Actor *arg0, s32 arg1) {
    void _subaddiefade_entrypoint_2(void *arg0);
    f32 func_800DC178(f32, f32);
    void func_80101FDC(Actor *, u32);
    void func_8010A570(Actor *);
    void func_8010A590(Actor *);
    f32 temp;

    if (arg1 != 1) {
        if (arg1 == 2) {
            arg0->unk64_16 = 0;
            func_8010A570(arg0);
            temp = arg0->rotation[1] * func_800DC178(0.5f, 1.0f);
            arg0->unk58 = temp;
        }
    } else {
        arg0->unk64_16 = 1;
        func_8010A590(arg0);
        _subaddiefade_entrypoint_2(arg0);
    }
    func_80101FDC(arg0, arg1);
}

/* extern */

void func_808000B8_chtransparencypot(Actor *arg0) {
    void func_8080001C_chtransparencypot(Actor *, s32);
    if ((arg0->unk70_10 == 2) && (func_800D9078(&arg0->unk58) != 0)) {
        func_8080001C_chtransparencypot(arg0, 1);
    }
}

/* extern */

s32 func_80800104_chtransparencypot(BtIntPtr arg0, s32 arg1, u8 *arg2) {
    void func_80800148_chtransparencypot(Actor *, u32);
    u8 **ptr = &arg2;
    switch (arg1) {
    case 0x3E:
        func_80800148_chtransparencypot((Actor *)arg0, (u32)*(u16 *)(*ptr + 0x1A) >> 5);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800148_chtransparencypot(Actor *arg0, u32 arg1) {
    void _fxsparkle_entrypoint_1(f32 *, u32);
    void func_800C4AF0(f32 *, void *);
    s32 func_800F7C0C(BtIntPtr, s32, f32);
    void func_8080001C_chtransparencypot(Actor *, s32);
    extern s32 D_808001F8_chtransparencypot[6];
    f32 rotation = arg0->rotation[1];

    func_800F7C0C(arg1, 0x67, rotation);
    _fxsparkle_entrypoint_1(arg0->position, 2U);
    func_800C4AF0(arg0->position, D_808001F8_chtransparencypot);
    func_8080001C_chtransparencypot(arg0, 2);
}
/* data_to_c.py: from asm/data/overlays/ch/transparencypot.data.s */
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
OSThread *func_80108ED0(void);
void func_80107C2C();
ActorData D_808001B0_chtransparencypot [1] BT_DATA(4, overlays_ch_transparencypot, 0x0) = { { 344, 699, 1702, 1, 0, (void (*)(struct Actor *))func_808000B8_chtransparencypot, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 256, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_8080000C_chtransparencypot, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 25600, (void (*)(struct Actor *, long, long))func_80800104_chtransparencypot, 0 } };
s32 D_808001F8_chtransparencypot[6] BT_DATA(4, overlays_ch_transparencypot, 0x48) = { 1246815, 1469792, 0, 0, 0, 0 };
