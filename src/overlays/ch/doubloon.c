#include "ch/doubloon.h"

typedef struct { u8 pad0[0x44]; f32 unk44; } Objdoubloon_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */ void func_80800000_chdoubloon(void *arg0) {
    (((Objdoubloon_arg0 *)arg0)->unk44) = 0.0f;
}

/* extern */

void func_8080000C_chdoubloon(BtIntPtr arg0) {
    void func_80103110(void *arg0, s32 arg1);
#ifdef BT_NATIVE
#ifdef BT_NATIVE
#ifdef BT_NATIVE
#ifdef BT_NATIVE
#ifdef BT_NATIVE
#ifdef BT_NATIVE
    s32 chdoubloon_entrypoint_1(Actor *arg0);
#else
    s32 chdoubloon_entrypoint_1(Actor *arg0);
#endif
#else
    s32 chdoubloon_entrypoint_1(Actor *arg0);
#endif
#else
    s32 chdoubloon_entrypoint_1(Actor *arg0);
#endif
#else
    s32 chdoubloon_entrypoint_1(Actor *arg0);
#endif
#else
    s32 chdoubloon_entrypoint_1(Actor *arg0);
#endif
#else
    s32 chdoubloon_entrypoint_1();
#endif
#ifdef BT_NATIVE
    ((s32 (*)())chdoubloon_entrypoint_1)();
#else
    chdoubloon_entrypoint_1();
#endif
    func_80103110(arg0, 0);
}

void chdoubloon_entrypoint_0(Actor *arg0, u8 *arg1) {
    struct Flags { u32 pad : 19; u32 active : 1; u32 rest : 12; };
    void func_80101870(Actor* arg0, void* arg1);
    void func_80103110(void *arg0, s32 arg1);
    func_80101870(arg0, arg1);
    if (((struct Flags *)((s8 *)arg0 + 0x7C))->active) {
        func_80103110((BtIntPtr) arg0, 1);
    }
}

s32 chdoubloon_entrypoint_1(Actor *arg0) {
    f32 func_800D8FF8(void);
    f32 func_800DC0C0(void);
    f32 func_800DC178(f32, f32);
    void func_800E3980(f32 *);
    void func_800EEC30(f32 *, f32, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    void func_800F18FC(f32 *, f32 *, f32 *);
    void _fxtwinkle_entrypoint_1(f32 *, s32);
    f32 sparkle[3];
    int i;
    f32 angles[2];
    f32 camera[3];

    arg0->rotation[1] += func_800D8FF8() * 300.0f;
    if (arg0->unk7C_12) {
        func_800E3980(camera);
        func_800F18FC(arg0->position, camera, angles);
        i = 0;
        do {
            if (func_800DC0C0() < 0.015f) {
                func_800EEC30(sparkle, angles[0] + func_800DC178(-90.0f, 90.0f),
                    angles[1] + func_800DC178(-90.0f, 90.0f), 30.0f);
                func_800EF04C(sparkle, arg0->position);
                sparkle[1] += 30.0f;
                _fxtwinkle_entrypoint_1(sparkle, 0x9E2);
            }
            i++;
        } while (i != 4);
    }
    BT_NATIVE_ONLY(return 0;)}

s32 func_808001D4_chdoubloon(Actor *arg0, s32 arg1, s32 arg2) {
    void _fxsparkle_entrypoint_1(f32 *, u32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 _sudialog_entrypoint_0(s32 arg0, s32 arg1);
    void func_800D0BD4(s32, u32);
    void func_800D1844(s32);
    void func_800FFAB0(Actor *);
    extern s32 D_80800290_chdoubloon[4];

    switch (arg1) {
        case 0x3E: {
            _sudialog_entrypoint_0(0x165, 4);
            func_800D0BD4(*(s32 *)&arg0->unk54, 7);
            func_800D1844(0x4E);
            _subaddieaudioquick_entrypoint_2(arg0, &arg0->position[0], D_80800290_chdoubloon);
            _fxsparkle_entrypoint_1(arg0->position, 0x13);
            func_800FFAB0(arg0);
            return 1;
        }
        case 0x13:
            *(s32 *)&arg0->unk54 = arg2;
            break;
        default:
            return 0;
    }
    return 1;
}

OSThread *chdoubloon_entrypoint_2(void)
{
    extern ActorData D_808002A0_chdoubloon[];

    return (OSThread *) D_808002A0_chdoubloon;
}
/* data_to_c.py: from asm/data/overlays/ch/doubloon.data.s */
void func_80105834(Actor*);
void _chdoubloon_entrypoint_0();
OSThread *func_80108ED0(void);
void func_80107C2C();
s32 D_80800290_chdoubloon[4] BT_DATA(4, overlays_ch_doubloon, 0x0) = { 1769491, 104071170, 1310742, 1835008000 };
ActorData D_808002A0_chdoubloon [1] BT_DATA(4, overlays_ch_doubloon, 0x10) = { { 308, 1253, 1984, 1, 0, (void (*)(struct Actor *))func_8080000C_chdoubloon, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))_chdoubloon_entrypoint_0, 3000, 0, 0, 0, 0, 4, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_80800000_chdoubloon, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 8192, (void (*)(struct Actor *, long, long))func_808001D4_chdoubloon, 0 } };
