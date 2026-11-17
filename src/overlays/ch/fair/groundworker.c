#include "common.h"

OSThread *chfairgroundworker_entrypoint_0(void)
{
    extern ActorData D_80800308_chfairgroundworker[];

    return (OSThread *) D_80800308_chfairgroundworker;
}

OSThread *chfairgroundworker_entrypoint_1(void)
{
    extern ActorData D_80800350_chfairgroundworker[];

    return (OSThread *) D_80800350_chfairgroundworker;
}

OSThread *chfairgroundworker_entrypoint_2(void)
{
    extern ActorData D_80800398_chfairgroundworker[];

    return (OSThread *) D_80800398_chfairgroundworker;
}

OSThread *chfairgroundworker_entrypoint_3(void)
{
    extern ActorData D_808003E0_chfairgroundworker[];

    return (OSThread *) D_808003E0_chfairgroundworker;
}

/* extern */

void func_80800030_chfairgroundworker(Actor *arg0) {
    s32 _sucoaster_entrypoint_0(void *, s32);
    void func_80102FDC(Actor *, f32);
    void func_8010A3E8(void *, f32);
    struct GroundworkerFlags { u32 : 15; u32 active : 1; u32 : 16; };
    _sucoaster_entrypoint_0(arg0, 0);
    func_80102FDC(arg0, arg0->scale * 0.85f);
    func_8010A3E8(arg0, 0.7f);
    ((struct GroundworkerFlags *)&arg0->pad94)->active = 1;
}

void func_80800098_chfairgroundworker(Actor *arg0) {
    void _chbadshad_entrypoint_3(Actor *arg0, void *arg1, s32 arg2, f32 arg3, s16 *arg4);
    s32 _sucoaster_entrypoint_2();
    extern s32 D_80800428_chfairgroundworker[2];
    _sucoaster_entrypoint_2();
    if (arg0->unk7C_12) {
        _chbadshad_entrypoint_3(arg0, (u8 *)arg0 + 4, 3, arg0->scale * 1.5294117f, D_80800428_chfairgroundworker);
    }
}

/* extern */

void func_808000FC_chfairgroundworker(BtIntPtr arg0, s32 arg1, s32 arg2) {
    s32 _sucoaster_entrypoint_21(Actor *arg0, s32 arg1, s32 arg2);
    void func_8080013C_chfairgroundworker();
    if (arg1 == 0xB6) {
        func_8080013C_chfairgroundworker();
    }
    _sucoaster_entrypoint_21(arg0, arg1, arg2);
}

void func_8080013C_chfairgroundworker(Actor *arg0) {
    BtIntPtr func_800B53A4(s32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EEB9C(f32[3], f32, f32);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    extern s32 D_80800430_chfairgroundworker[16];
    BtIntPtr temp_s3;
    f32 sp60[3];
    f32 sp54[3];
    s32 var_s0;

    func_800EE7F8(sp54, arg0->position);
    func_800EF1B8(sp54, arg0->rotation[1], arg0->scale * 300.0f);
    temp_s3 = func_800B53A4(5);
    for (var_s0 = 0; var_s0 != 5; var_s0++) {
        func_800EEB9C(sp60, (f32)var_s0 * 72.0f, 5.0f);
        func_800EF04C(sp60, sp54);
        func_800BABB8(temp_s3, sp60, sp54, 1.0f, D_80800430_chfairgroundworker);
    }
}
/* data_to_c.py: from asm/data/overlays/ch/fair/groundworker.data.s */
extern u8 D_80800270_chfairgroundworker[];
void func_80105834(Actor*);
void _sucoaster_entrypoint_20();
void _sucoaster_entrypoint_1();
OSThread *_sucoasterhit_entrypoint_0(void);
void func_80107C2C();
u8 D_80800270_chfairgroundworker[152] BT_DATA(4, overlays_ch_fair_groundworker, 0x0) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0x29, 0x99, 0x9A, 0x00, 0xF9, 0x00, 0x01, 0x41, 0x29, 0x99, 0x9A, 0x00, 0xF9, 0x00, 0x01, 0x3F, 0xAA, 0x3D, 0x71, 0x00, 0xDE, 0x00, 0x01, 0x3F, 0x33, 0x33, 0x33, 0x00, 0xF8, 0x00, 0x01, 0x3F, 0xAA, 0x3D, 0x71, 0x00, 0xDE, 0x00, 0x01, 0x3F, 0xAA, 0x3D, 0x71, 0x00, 0xDE, 0x00, 0x01, 0x3F, 0xAE, 0x14, 0x7B, 0x00, 0xDF, 0x00, 0x02, 0x3F, 0x33, 0x33, 0x33, 0x00, 0xF8, 0x00, 0x01, 0x3F, 0xD5, 0xC2, 0x8F, 0x04, 0x28, 0x00, 0x02, 0x3F, 0x33, 0x33, 0x33, 0x00, 0xF8, 0x00, 0x01, 0x3F, 0x94, 0x7A, 0xE1, 0x04, 0x27, 0x00, 0x02, 0x3F, 0xD7, 0x0A, 0x3D, 0x00, 0xF7, 0x00, 0x02, 0x3F, 0xD7, 0x0A, 0x3D, 0x00, 0xF7, 0x00, 0x84, 0x41, 0x29, 0x99, 0x9A, 0x00, 0xF9, 0x00, 0x01, 0x3F, 0xAA, 0x3D, 0x71, 0x00, 0xDE, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0x29, 0x99, 0x9A, 0x00, 0xF9, 0x00, 0x01, 0x3F, 0x33, 0x33, 0x33, 0x00, 0xF8, 0x00, 0x01 };
ActorData D_80800308_chfairgroundworker [1] BT_DATA(4, overlays_ch_fair_groundworker, 0x98) = { { 400, 807, 1713, 1, (void *)D_80800270_chfairgroundworker, (void (*)(struct Actor *))func_80800098_chfairgroundworker, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))_sucoaster_entrypoint_20, 196608000, 0, 0, 0, 17157, 809, (void (*)(struct Actor *))_sucoaster_entrypoint_1, (BtIntPtr)_sucoasterhit_entrypoint_0, 0, 0, (void (*)(struct Actor *))func_80800030_chfairgroundworker, (void (*)(void *, long, void *, long, void *))func_80107C2C, -31694, 20509, (void (*)(struct Actor *, long, long))func_808000FC_chfairgroundworker, -2146286256 } };
ActorData D_80800350_chfairgroundworker [1] BT_DATA(4, overlays_ch_fair_groundworker, 0xE0) = { { 400, 808, 1715, 1, (void *)D_80800270_chfairgroundworker, (void (*)(struct Actor *))func_80800098_chfairgroundworker, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))_sucoaster_entrypoint_20, 196608000, 0, 0, 0, 17157, 809, (void (*)(struct Actor *))_sucoaster_entrypoint_1, (BtIntPtr)_sucoasterhit_entrypoint_0, 0, 0, (void (*)(struct Actor *))func_80800030_chfairgroundworker, (void (*)(void *, long, void *, long, void *))func_80107C2C, -31694, 20509, (void (*)(struct Actor *, long, long))func_808000FC_chfairgroundworker, -2146286256 } };
ActorData D_80800398_chfairgroundworker [1] BT_DATA(4, overlays_ch_fair_groundworker, 0x128) = { { 400, 809, 1714, 1, (void *)D_80800270_chfairgroundworker, (void (*)(struct Actor *))func_80800098_chfairgroundworker, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))_sucoaster_entrypoint_20, 196608000, 0, 0, 0, 17157, 809, (void (*)(struct Actor *))_sucoaster_entrypoint_1, (BtIntPtr)_sucoasterhit_entrypoint_0, 0, 0, (void (*)(struct Actor *))func_80800030_chfairgroundworker, (void (*)(void *, long, void *, long, void *))func_80107C2C, -31694, 20509, (void (*)(struct Actor *, long, long))func_808000FC_chfairgroundworker, -2146286256 } };
ActorData D_808003E0_chfairgroundworker [1] BT_DATA(4, overlays_ch_fair_groundworker, 0x170) = { { 400, 810, 1716, 1, (void *)D_80800270_chfairgroundworker, (void (*)(struct Actor *))func_80800098_chfairgroundworker, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))_sucoaster_entrypoint_20, 196608000, 0, 0, 0, 17157, 809, (void (*)(struct Actor *))_sucoaster_entrypoint_1, (BtIntPtr)_sucoasterhit_entrypoint_0, 0, 0, (void (*)(struct Actor *))func_80800030_chfairgroundworker, (void (*)(void *, long, void *, long, void *))func_80107C2C, -31694, 20509, (void (*)(struct Actor *, long, long))func_808000FC_chfairgroundworker, -2146286256 } };
s32 D_80800428_chfairgroundworker[2] BT_DATA(4, overlays_ch_fair_groundworker, 0x1B8) = { 786445, -65536 };
s32 D_80800430_chfairgroundworker[16] BT_DATA(4, overlays_ch_fair_groundworker, 0x1C0) = { 1903069, 2818201, 13369378, 4980838, 16777523, 1376256, 6684711, -6488164, 6553700, 1638400, 458802, 45, 9830650, 2154151, 1908408602, 0 };
