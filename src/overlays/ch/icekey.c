#include "common.h"

s32 func_80800000_chicekey(Actor *arg0, s32 arg1, s32 arg2) {
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800D1844(s32);
    void func_800FC660(u32);
    void func_800FFA88(Unk80132ED0 *);
    extern s32 D_808000A0_chicekey[19];
    f32 *sp24[1];

    if (arg1 == 0x3E) {
        sp24[0] = arg0->position; func_800BBCB8(sp24[0], sp24[0], 1.0f, 0x14, D_808000A0_chicekey);
        func_800D1844(0x53);
        _subaddiedialog_entrypoint_11(arg0->unk0, 0x1550, 4, sp24[0], 0x6F);
        func_800FC660(0xE);
        func_800FFA88(arg0->unk0);
        return 1;
    }
    return 0;
}

OSThread *chicekey_entrypoint_0(void)
{
    extern ActorData D_808000EC_chicekey[];

    return (OSThread *) D_808000EC_chicekey;
}
/* data_to_c.py: from asm/data/overlays/ch/icekey.data.s */
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
OSThread *func_80108ED0(void);
void func_80107C2C();
s32 D_808000A0_chicekey[19] BT_DATA(4, overlays_ch_icekey, 0x0) = { 1903072, 1834208, -39321555, 13107550, 917504, 5242902, 268566567, 300, 500, 2228300, 4980825, 8388629, 204, 2818432, 50331652, 10027015, 262193, -4849714, 0 };
ActorData D_808000EC_chicekey [1] BT_DATA(4, overlays_ch_icekey, 0x4C) = { { 344, 1299, 1595, 1, 0, 0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 0, 0, (BtIntPtr)func_80108ED0, 0, 0, 0, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1024, (void (*)(struct Actor *, long, long))func_80800000_chicekey, 0 } };
