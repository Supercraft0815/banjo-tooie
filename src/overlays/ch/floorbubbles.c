#include "common.h"

void func_80800000_chfloorbubbles(Actor *arg0) {
    BtIntPtr func_800B53A4(s32);
    void func_800BA22C(BtIntPtr, s32);
    void func_800BA568(s16 *, s16);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    f32 func_800DC0C0(void);
    s32 func_800DC128(s32, s32);
    void *func_80100094(Actor *, u32);
    extern s32 D_80800270_chfloorbubbles[];
    f32 (*sp34)[3];
    s32 sp30;
    BtIntPtr sp2C;
    s32 temp_v0;
    BtIntPtr temp_v0_2;

    sp34 = func_80100094(arg0, 0);
    if (func_800DC0C0() < 0.1f) {
        temp_v0 = func_800DC128(0, 5);
        sp30 = temp_v0;
        temp_v0_2 = func_800B53A4(temp_v0);
        sp2C = temp_v0_2;
        func_800BABB8(temp_v0_2, sp34[arg0->unk6C_0], NULL, 1.0f, D_80800270_chfloorbubbles);
        func_800BA568((s16 *)sp2C, (s16) (s32) (*(f32 *)&arg0->actorData[1]));
        func_800BA22C(sp2C, sp30);
        if (func_800DC0C0() < 0.75f) {
            arg0->unk6C_0 = func_800DC128(0, 0xA);
        }
    }
}

/* extern */

void func_8080010C_chfloorbubbles(Actor *arg0) {
    s32 _subaddie3d_entrypoint_0(f32 *, f32, f32, f32 *);
    s32 _subaddie3d_entrypoint_1(f32 *, f32, f32, u32 *);
    f32 func_800DC178(f32, f32);
    void func_800EEB9C(f32 *, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    f32 temp_f20;
    f32 (*temp_v0)[3];
    s32 var_s1;

    temp_v0 = func_80100094(arg0, 0);
    for (var_s1 = 0; var_s1 < 10; var_s1++) {
        temp_f20 = func_800DC178(0.0f, 359.0f);
        func_800EEB9C(temp_v0[var_s1], temp_f20, func_800DC178(0.0f, (s32)arg0->unk74_7 * 10));
        func_800EF04C(temp_v0[var_s1], arg0->position);
        _subaddie3d_entrypoint_0(temp_v0[var_s1], 100.0f, -100.0f, &temp_v0[var_s1][1]);
    }
    _subaddie3d_entrypoint_1(arg0->position, 500.0f, 0.0f, &arg0->actorData[1]);
}

void func_80800244_chfloorbubbles(s32 arg0) 
{
}
OSThread *chfloorbubbles_entrypoint_0(void)
{
    extern ActorData D_808002CC_chfloorbubbles[];

    return (OSThread *) D_808002CC_chfloorbubbles;
}
/* data_to_c.py: from asm/data/overlays/ch/floorbubbles.data.s */
void func_80105834(Actor*);
void func_8010A730();
void func_80107C2C();
s32 D_80800270_chfloorbubbles [23] BT_DATA(4, overlays_ch_floorbubbles, 0x0) = { 1903065, 1445892, 2883584, 3276800, 70, 27, 9830600, 458753, 1376256, 13369387, 25166464, 720884, -6488076, 786432, 786464, -257, 2228254, 2490388, 1638447, 4194368, 0, 1638400, 3342336 };
ActorData D_808002CC_chfloorbubbles [1] BT_DATA(4, overlays_ch_floorbubbles, 0x5C) = { { 527, 687, 1652, 1, 0, (void (*)(struct Actor *))func_80800000_chfloorbubbles, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_8010A730, 163840000, 0, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800244_chfloorbubbles, 0, 120, 0, (void (*)(struct Actor *))func_8080010C_chfloorbubbles, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1538, 0, 0 } };
