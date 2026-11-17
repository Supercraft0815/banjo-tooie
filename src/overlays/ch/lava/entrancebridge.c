#include "common.h"

typedef struct { u8 pad0[0x58]; f32 unk58; } Objentrancebridge_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */ void func_80800000_chlavaentrancebridge(void *arg0) {
    (((Objentrancebridge_arg0 *)arg0)->unk58) = -2750.0f;
}

/* extern */

s32 func_80800010_chlavaentrancebridge(Actor *arg0, s32 arg1, s32 arg2) {
    s32 func_800DA298(s32);
    void func_80101FDC(Actor *, u32);
    switch (arg1) {
    case 0x95:
        if (func_800DA298(0x391) != 0) {
            func_80101FDC(arg0, 4);
        }
        break;
    case 0x60:
        func_80101FDC(arg0, 2);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_8080008C_chlavaentrancebridge(Actor *arg0) {
    BtIntPtr _idworld_entrypoint_3(s32);
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_80018820(s32, f32, f32);
    f32 func_800D8FF8(void);
    s32 func_800E15CC(s32, f32, f32);
    void func_800EDCEC(void *, f32);
    void func_80101FDC(Actor *, u32);
    extern u32 D_80800220_chlavaentrancebridge[];
    extern u32 D_80800228_chlavaentrancebridge[];
    void *sp34;
    void *sp30;
    f32 height;

    sp34 = (void *)_idworld_entrypoint_3(0x190);
    sp30 = (void *)_idworld_entrypoint_3(0x191);
    height = -2750.0f;
    switch (arg0->unk70_10) {
    case 2:
        _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, D_80800220_chlavaentrancebridge);
        arg0->unk58 += 450.0f * func_800D8FF8();
        if (arg0->unk58 >= 0.0f) {
            arg0->unk58 = 0.0f;
            func_80101FDC(arg0, 4);
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800228_chlavaentrancebridge);
            func_800E15CC(0, 20.0f, 0.85f);
            func_80018820(0, 1.0f, 0.4f);
        }
        height = arg0->unk58;
        break;
    case 4:
        height = 0.0f;
        break;
    }
    if (sp34 != NULL) {
        func_800EDCEC(sp34, height);
    }
    if (sp30 != NULL) {
        func_800EDCEC(sp30, height >= -1350.0f ? height : -1350.0f);
    }
}

OSThread *chlavaentrancebridge_entrypoint_0(void)
{
    extern ActorData D_80800230_chlavaentrancebridge[];

    return (OSThread *) D_80800230_chlavaentrancebridge;
}
/* data_to_c.py: from asm/data/overlays/ch/lava/entrancebridge.data.s */
void func_80105834(Actor*);
void func_8010A730();
void func_80107C2C();
u32 D_80800220_chlavaentrancebridge [2] BT_DATA(4, overlays_ch_lava_entrancebridge, 0x0) = { 0x1304AD, 0x20000 };
u32 D_80800228_chlavaentrancebridge [2] BT_DATA(4, overlays_ch_lava_entrancebridge, 0x8) = { 0x1304CC, 0x20000 };
ActorData D_80800230_chlavaentrancebridge [1] BT_DATA(4, overlays_ch_lava_entrancebridge, 0x10) = { { 344, 910, 0, 1, 0, (void (*)(struct Actor *))func_8080008C_chlavaentrancebridge, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_8010A730, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800000_chlavaentrancebridge, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 9218, (void (*)(struct Actor *, long, long))func_80800010_chlavaentrancebridge, 0 } };
