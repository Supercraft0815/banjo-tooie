#include "common.h"

OSThread *chdrips_entrypoint_0(void)
{
    extern ActorData D_80800610_chdrips[];

    return (OSThread *) D_80800610_chdrips;
}

void chdrips_entrypoint_1(s32 arg0, BtIntPtr arg1)
{
  void _fxripple_entrypoint_0(s32 arg0, BtIntPtr arg1);
  void func_800C4140(u32 arg0, f32 *arg1, u32 arg2);
  f32 func_800DC178(f32, f32);
  func_800C4140(((((u32) (func_800DC178(1.0f, 1.4f) * 1023.0f)) << 13) << 8) + 0xBBD53, arg1, 0x05DC012C);
  _fxripple_entrypoint_0(0, arg1);
}

void chdrips_entrypoint_2(s32 arg0, f32 arg1[3]) {
    BtIntPtr func_800B53A4(s32);
    void func_800BA4D0(void *emitter, s16 min_y);
    void func_800BA6B0(u8 *, s16, s16, s16, s16, s16, s16);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    void func_800C4140(u32 arg0, f32 *arg1, u32 arg2);
    f32 func_800DC178(f32, f32);
    extern s32 D_80800658_chdrips[];
    BtIntPtr emitter;

    emitter = func_800B53A4(5);
    func_800BA6B0(emitter, -50, 0, -50, 50, 0, 50);
    func_800BA4D0(emitter, (s16)(s32)arg1[1]);
    func_800BABB8(emitter, arg1, 0, 1.0f, D_80800658_chdrips);
    func_800C4140((((u32)(func_800DC178(1.0f, 1.4f) * 1023.0f) << 13) << 8) + 0xBBD52, arg1, 0x05DC012C);
}

void func_80800260_chdrips(Actor *arg0) {
    BtIntPtr func_800B53A4(s32);
    void func_800BA22C(BtIntPtr, s32);
    void func_800BA4D0(void *emitter, s16 min_y);
    void func_800BA544(s32 *, BtIntPtr);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    s32 func_800DC128(s32, s32);
    int func_800DC298(f32);
    void *func_80100094(Actor *, u32);
    extern s32 D_80800698_chdrips[];
#ifndef BT_NATIVE
    extern s32 _chdrips_entrypoint_1;
#endif
#ifndef BT_NATIVE
    extern s32 _chdrips_entrypoint_2;
#endif
    BtIntPtr temp_v0;
    struct {
        f32 position[3];
        f32 size;
        u8 flag;
        u8 pad[3];
    } *temp_s0;

    if (func_800DC298(arg0->rotation[1] * 0.333f * 0.0027777778f) != 0) {
        temp_s0 = func_80100094(arg0, 0);
        temp_v0 = func_800B53A4(1);
        temp_s0 += arg0->unk6C_0;
        if (temp_s0->flag != 0) {
            func_800BA544(temp_v0, &_chdrips_entrypoint_1);
        } else {
            func_800BA544(temp_v0, &_chdrips_entrypoint_2);
        }
        func_800BA4D0(temp_v0, (s16) (s32) temp_s0->size);
        func_800BABB8(temp_v0, temp_s0->position, NULL, 1.0f, D_80800698_chdrips);
        func_800BA22C(temp_v0, 1);
        arg0->unk6C_0 = func_800DC128(0, arg0->unk74_7);
    }
}

void func_80800394_chdrips(Actor *arg0) {
    s32 _subaddie3d_entrypoint_0(f32 *, f32, f32, f32 *);
    s32 _subaddie3d_entrypoint_1(f32 *, f32, f32, f32 *);
    u32 func_800CC5F4(s32);
    void *func_800CC63C(s32, s32);
    s32 func_800DC128(s32, s32);
    f32 func_800DC178(f32, f32);
    void func_800EEB9C(f32 *, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    void func_800FFA88(Unk80132ED0 *);
    u32 *func_80100074(Actor *, u32, u32);
    void *func_80100094(Actor *, u32);
    struct {
        f32 position[3];
        f32 size;
        u8 flag;
        u8 pad[3];
    } *drip;
    struct {
        f32 position[3];
        s16 radius;
    } *point;
    f32 angle;
    f32 height;
    s32 count;
    s32 i;

    if (arg0->unk70_25 == 0) {
        func_800FFA88(arg0->unk0);
        return;
    }
    if ((s32)arg0->unk74_7 < 51) {
        arg0->unk74_7 = 60;
    }
    arg0->unk74_7 = (s32)arg0->unk74_7 - 50;
    func_80100074(arg0, 0, arg0->unk74_7 * sizeof(*drip));
    drip = func_80100094(arg0, 0);
    count = func_800CC5F4(arg0->unk70_25 - 1);
    for (i = 0; i < (s32)arg0->unk74_7; i++, drip++) {
        point = func_800CC63C(arg0->unk70_25 - 1, func_800DC128(0, count));
        angle = func_800DC178(0.0f, 359.0f);
        func_800EEB9C(drip->position, angle, func_800DC178(0.0f, point->radius));
        func_800EF04C(drip->position, point->position);
        if (!_subaddie3d_entrypoint_0(drip->position, 0.0f, -5000.0f, &drip->size)) {
            drip->size = point->position[1];
        }
        if (!_subaddie3d_entrypoint_1(drip->position, 0.0f, -5000.0f, &height)) {
            height = drip->size - 50.0f;
        }
        if (drip->size < height) {
            drip->size = height;
            drip->flag = 1;
        } else {
            drip->flag = 0;
        }
    }
}

void func_808005CC_chdrips(Actor *arg0) {
    u32* func_80100074(Actor*, u32, u32);
    func_80100074(arg0, 0U, 0U);
}
/* data_to_c.py: from asm/data/overlays/ch/drips.data.s */
void func_80105834(Actor*);
void func_8010A730();
void func_80107C2C();
ActorData D_80800610_chdrips [1] BT_DATA(4, overlays_ch_drips, 0x0) = { { 744, 881, 0, 1, 0, (void (*)(struct Actor *))func_80800260_chdrips, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_8010A730, 0, 0, 0, 0, 8, 5, (void (*)(struct Actor *))func_808005CC_chdrips, 0, 0, 0, (void (*)(struct Actor *))func_80800394_chdrips, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 514, 0, 0 } };
s32 D_80800658_chdrips [16] BT_DATA(4, overlays_ch_drips, 0x48) = { 1903066, 2162687, -21757925, -85132564, 458753, 1376256, 13369378, 327690, 327685, 2818560, 33554454, 268435500, -5898040, -5898150, 22937690, 85590016 };
s32 D_80800698_chdrips [10] BT_DATA(4, overlays_ch_drips, 0x88) = { 1903091, 2162687, -21757925, -45810364, 458753, 2228229, 655380, 1638400, 0, 0 };
