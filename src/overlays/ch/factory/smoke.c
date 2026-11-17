#include "common.h"

OSThread *chfactorysmoke_entrypoint_0(void)
{
    extern ActorData D_80800100_chfactorysmoke[];

    return (OSThread *) D_80800100_chfactorysmoke;
}    typedef struct { u8 pad0[0x58]; f32 unk58; } Objsmoke_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void func_8080000C_chfactorysmoke(void *arg0) {
    f32 func_800DC178(f32, f32);
    (((Objsmoke_arg0 *)arg0)->unk58) = func_800DC178(0.55f, 0.65f);
}

void func_80800044_chfactorysmoke(Actor *arg0) {
    s32 func_800D9078(f32 *);
    f32 func_800DC178(f32, f32);
    void func_808000A8_chfactorysmoke(BtIntPtr);

    if (arg0->unk70_10 == 1 && func_800D9078(&arg0->unk58)) {
        func_808000A8_chfactorysmoke((BtIntPtr)arg0);
        arg0->unk58 = func_800DC178(0.55f, 0.65f);
    }
}

void func_808000A8_chfactorysmoke(BtIntPtr arg0) {
    BtIntPtr func_800BBCB8(BtIntPtr, BtIntPtr, s32, s32, s32 *);
    extern s32 D_80800148_chfactorysmoke[26];
    func_800BBCB8(arg0 + 4, 0, 0x3F800000, 4, D_80800148_chfactorysmoke);
}
/* data_to_c.py: from asm/data/overlays/ch/factory/smoke.data.s */
void func_80105834(Actor*);
void func_8010A730();
void func_80107C2C();
ActorData D_80800100_chfactorysmoke [1] BT_DATA(4, overlays_ch_factory_smoke, 0x0) = { { 157, 981, 0, 1, 0, (void (*)(struct Actor *))func_80800044_chfactorysmoke, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_8010A730, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, (void (*)(struct Actor *))func_8080000C_chfactorysmoke, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1538, 0, 0 } };
s32 D_80800148_chfactorysmoke[26] BT_DATA(4, overlays_ch_factory_smoke, 0x48) = { 1903069, 1572864, 3942, 282329089, 0, 16384000, 350, 2949069, 29556671, 3932710, 4587531, 7143620, 0, 2064580, -1811939306, 33554471, 851994, 3211306, 2228800, 45090106, 108331029, 204, 2752512, 2490752, 29360128, 0 };
