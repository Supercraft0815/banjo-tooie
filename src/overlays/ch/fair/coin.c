#include "common.h"

void func_80800000_chfaircoin(Actor *arg0) {
    f32 func_8001395C(f32);
    s32 func_800D9078(f32 *arg0);
    void func_800EFE50(f32 *, f32 *, f32 *, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_800FC660(u32);
    void func_800FFAB0(Actor *);
    f32 sp2C;
    f32 temp_f0;

    func_800D9078((f32 *)arg0->actorData + 3);
    temp_f0 = func_800F10B4(((f32 *)arg0->actorData)[3], arg0->unk58, 0.0f, 0.0f, 1.0f);
    sp2C = temp_f0;
    func_800EFE50(arg0->position, (f32 *)arg0->actorData + 4, (f32 *)arg0->actorData, temp_f0);
    arg0->position[1] += func_8001395C(sp2C * 3.1415927f) * 200.0f;
    if (((f32 *)arg0->actorData)[3] == 0.0f) {
        func_800FFAB0(arg0);
        func_800FC660(0xE);
    }
}    typedef struct { u8 pad0[0x24]; f32 unk24; u8 pad28[0x30]; f32 unk58; } Objcoin_chfaircoin_entrypoint_0_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

u8 *chfaircoin_entrypoint_0(BtIntPtr arg0, BtIntPtr arg1, f32 arg2) {
    void func_800C4AF0(f32 *arg0, void *arg1);
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    Actor *func_80108474(u32 arg0, f32 *arg1, s32 arg2);
    extern s32 D_80800150_chfaircoin[3];
    u8 *temp_v0;

    temp_v0 = func_80108474(0x166, arg0, 0);
    func_800EE7F8(temp_v0 + 0x18, arg1);
    func_800EE7F8(temp_v0 + 0x28, arg0);
    (((Objcoin_chfaircoin_entrypoint_0_temp_v0 *)temp_v0)->unk24) = arg2;
    (((Objcoin_chfaircoin_entrypoint_0_temp_v0 *)temp_v0)->unk58) = arg2;
    func_800C4AF0(0, D_80800150_chfaircoin);
    return temp_v0;
}

OSThread *chfaircoin_entrypoint_1(void)
{
    extern ActorData D_8080015C_chfaircoin[];

    return (OSThread *) D_8080015C_chfaircoin;
}
/* data_to_c.py: from asm/data/overlays/ch/fair/coin.data.s */
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
s32 D_80800150_chfaircoin[3] BT_DATA(4, overlays_ch_fair_coin, 0x0) = { 1246192, 1469792, 0 };
ActorData D_8080015C_chfaircoin [1] BT_DATA(4, overlays_ch_fair_coin, 0xC) = { { 632, 358, 2002, 1, 0, (void (*)(struct Actor *))func_80800000_chfaircoin, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 2, 0, 0 } };
