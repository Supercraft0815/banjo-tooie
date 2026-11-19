#include "common.h"
#include "core2/baddie_states.h"

OSThread *chdiggerground_entrypoint_0(void)
{
    extern ActorData D_80800408_chdiggerground[];

    return (OSThread *) D_80800408_chdiggerground;
}

/* extern */

void func_8080000C_chdiggerground(Actor *arg0) {
    void _sucoaster_entrypoint_2(Actor *arg0);
    void *func_80100094(Actor *, u32);
    s32 func_8010108C();
    void func_808000C4_chdiggerground(Actor *);
    if (arg0->unk64_20) {
        if (func_80100094(arg0, 0) == 0) {
            func_808000C4_chdiggerground(arg0);
            func_8010108C(arg0, 0x95, 0);
        }
        _sucoaster_entrypoint_2(arg0);
    }
}

/* extern */

void func_80800070_chdiggerground(Actor *arg0) {
    void func_80101FDC(Actor*, u32);
    void func_8010A3E8(void *arg0, f32 arg1);
    void func_808000C4_chdiggerground(Actor *);
    if (((u32) (*(u32 *)((s8 *)(arg0) + (0x6C))) >> 0x15) != 0) {
        func_80101FDC(arg0, 1U);
        func_808000C4_chdiggerground(arg0);
        arg0->unk64_20 = 1;
    }
    func_8010A3E8(arg0, 0.75f);
}

/* extern */

void func_808000C4_chdiggerground(Actor *arg0) {
    void _subaddieDll_entrypoint_1(Actor *arg0);
    s32 _sucoaster_entrypoint_0(void *, s32);
    s32 _sucoaster_entrypoint_10(Actor *, s32);
    s32 func_800D9058(f32);
    int func_800DC298(f32);
    void func_8010A590(Actor *);

    _subaddieDll_entrypoint_1(arg0);
    if (_sucoaster_entrypoint_0(arg0, 0) != 0) {
        _sucoaster_entrypoint_10(arg0, func_800DC298(0.65f) ? 3 : 2);
        if (arg0->pad6C_21 == 0) {
            arg0->unk6C_0 = func_800D9058(1.5f);
        }
        arg0->unk64_24 = 1;
        func_8010A590(arg0);
    }
}

/* extern */

s32 func_80800168_chdiggerground(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _sucoaster_entrypoint_21(Actor *, s32, s32);
    void *func_80100094(Actor *, u32);
    void func_80800214_chdiggerground(Actor *);
    if (func_80100094(arg0, 0U) == NULL) {
        return 0;
    }
    if (arg1 == 0xB6) {
        func_80800214_chdiggerground(arg0);
    }
    return _sucoaster_entrypoint_21(arg0, arg1, arg2);
}

/* extern */

void func_808001C8_chdiggerground(Actor *arg0, u8 *arg1) {
    void* func_80100094(Actor*, u32);
    void func_80101870(Actor* arg0, void* arg1);
    void _sucoaster_entrypoint_20();
    if (func_80100094(arg0, 0U) == NULL) {
        func_80101870(arg0, arg1);
        return;
    }
    _sucoaster_entrypoint_20(arg0, arg1);
}

void func_80800214_chdiggerground(Actor *arg0) {
    BtIntPtr func_800B53A4(s32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EEB9C(f32[3], f32, f32);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    extern s32 D_80800450_chdiggerground[12];
    BtIntPtr temp_s2;
    f32 sp78[3];
    f32 sp6C[3];
    f32 sp60[3];
    s32 var_s0;

    func_800EE7F8(sp6C, arg0->position);
    func_800EF1B8(sp6C, arg0->rotation[1], arg0->scale * 80.0f);
    func_800EE7F8(sp60, sp6C);
    sp60[1] -= 10.0f;
    temp_s2 = func_800B53A4(8);
    for (var_s0 = 0; var_s0 != 8; var_s0++) {
        func_800EEB9C(sp78, (f32)var_s0 * 45.0f, 20.0f);
        func_800EF04C(sp78, sp6C);
        func_800BABB8(temp_s2, sp78, sp60, 1.0f, D_80800450_chdiggerground);
    }
}
/* data_to_c.py: from asm/data/overlays/ch/digger/ground.data.s */
extern u8 D_80800370_chdiggerground[];
void func_80105834(Actor*);
void _sucoaster_entrypoint_1();
OSThread *_sucoasterhit_entrypoint_0(void);
void func_80107C2C();
u8 D_80800370_chdiggerground[152] BT_DATA(4, overlays_ch_digger_ground, 0x0) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0xB0, 0x00, 0x00, 0x01, 0xE7, 0x00, 0x01, 0x40, 0xB0, 0x00, 0x00, 0x01, 0xE7, 0x00, 0x01, 0x3F, 0xC0, 0x00, 0x00, 0x01, 0xE6, 0x00, 0x01, 0x3F, 0x80, 0x00, 0x00, 0x01, 0xE8, 0x00, 0x01, 0x3F, 0xC0, 0x00, 0x00, 0x01, 0xE6, 0x00, 0x01, 0x3F, 0xC0, 0x00, 0x00, 0x01, 0xE6, 0x00, 0x01, 0x3F, 0x80, 0x00, 0x00, 0x01, 0xE9, 0x00, 0x02, 0x3F, 0x80, 0x00, 0x00, 0x01, 0xE8, 0x00, 0x01, 0x3F, 0x80, 0x00, 0x00, 0x03, 0xDF, 0x00, 0x02, 0x3F, 0x80, 0x00, 0x00, 0x01, 0xE8, 0x00, 0x01, 0x3F, 0x00, 0x00, 0x00, 0x03, 0xE0, 0x00, 0x02, 0x3F, 0x8C, 0xCC, 0xCD, 0x01, 0xEA, 0x00, 0x02, 0x3F, 0x8C, 0xCC, 0xCD, 0x01, 0xEA, 0x00, 0x84, 0x40, 0xB0, 0x00, 0x00, 0x01, 0xE7, 0x00, 0x01, 0x3F, 0xC0, 0x00, 0x00, 0x01, 0xE6, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0xB0, 0x00, 0x00, 0x01, 0xE7, 0x00, 0x01, 0x3F, 0x80, 0x00, 0x00, 0x01, 0xE8, 0x00, 0x01 };
ActorData D_80800408_chdiggerground [1] BT_DATA(4, overlays_ch_digger_ground, 0x98) = { { 418, 305, 1649, 4, (void *)D_80800370_chdiggerground, (void (*)(struct Actor *))func_8080000C_chdiggerground, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_808001C8_chdiggerground, 196608000, 1065353216, 0, 0, 17157, 800, (void (*)(struct Actor *))_sucoaster_entrypoint_1, (BtIntPtr)_sucoasterhit_entrypoint_0, 0, 0, (void (*)(struct Actor *))func_80800070_chdiggerground, (void (*)(void *, long, void *, long, void *))func_80107C2C, -31694, 20511, (void (*)(struct Actor *, long, long))func_80800168_chdiggerground, (BtIntPtr)&D_80124550[0] } };
s32 D_80800450_chdiggerground[12] BT_DATA(4, overlays_ch_digger_ground, 0xE0) = { 1903080, 2818201, 13369378, 4980838, 1638438, 1376256, 8388647, -6488164, 6553700, 2949345, 19661082, 0 };
