#include "common.h"

void func_80800000_chsparkle(f32 *arg0) {
    BtIntPtr func_800B53A4(s32);
    void func_800BA3FC(BtIntPtr, s32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    s32 func_800DC128(s32, s32);
    f32 func_800DC178(f32, f32);
    void func_800E3980(f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EEB9C(f32[3], f32, f32);
    void func_800EF04C(f32 *, f32 *);
    void func_800F18FC(f32 *, f32 *, f32 *);
    extern s16 D_80800120_chsparkle[];
    extern s32 D_8080012C_chsparkle[];
    f32 sp54[3];
    f32 sp48[3];
    f32 sp3C[3];
    f32 sp34[2];
    s32 sp30;
    BtIntPtr sp2C;

    sp30 = func_800DC128(0, 5);
    sp2C = func_800B53A4(1);
    func_800BA3FC(sp2C, D_80800120_chsparkle[sp30]);
    func_800E3980(sp54);
    func_800EE7F8(sp48, arg0 + 1);
    sp48[1] -= 200.0f;
    func_800F18FC(arg0 + 1, sp54, sp34);
    func_800EEB9C(sp3C, sp34[1] + func_800DC178(-90.0f, 90.0f), 40.0f);
    func_800EF04C(sp3C, arg0 + 1);
    sp3C[1] += func_800DC178(0.0f, 120.0f);
    func_800BABB8(sp2C, sp3C, sp48, 1.0f, D_8080012C_chsparkle);
}

OSThread *chsparkle_entrypoint_0(void)
{
    extern ActorData D_80800164_chsparkle[];

    return (OSThread *) D_80800164_chsparkle;
}
/* data_to_c.py: from asm/data/overlays/ch/sparkle.data.s */
void func_80105834(Actor*);
void func_8010A730();
OSThread *func_80108ED0(void);
void func_80107C2C();
s16 D_80800120_chsparkle [6] BT_DATA(4, overlays_ch_sparkle, 0x0) = { 2530, 2531, 2534, 2538, 2532, 0 };
s32 D_8080012C_chsparkle [14] BT_DATA(4, overlays_ch_sparkle, 0xC) = { 2818150, 8388652, 50, 0, 6553600, 2621240, -13107000, 13107234, 4194380, 1638438, 1376307, 11730995, 131354, 0 };
ActorData D_80800164_chsparkle [1] BT_DATA(4, overlays_ch_sparkle, 0x44) = { { 344, 1238, 0, 1, 0, (void (*)(struct Actor *))func_80800000_chsparkle, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_8010A730, 0, 0, 0, 0, 0, 4, 0, (BtIntPtr)func_80108ED0, 0, 0, 0, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 2, 0, 0 } };
