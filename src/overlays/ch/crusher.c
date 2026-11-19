#include "ch/crusher.h"
#ifdef BT_NATIVE
#include "core2/particle_script.h"
#endif
#include "core2/switch_animations.h"
s32 func_80800000_chcrusher(Actor *arg0, s32 arg1, s32 arg2) {
    Actor *func_80108474(u32, f32 *, s32);
    f32 position[3];
    s32 result;

    if (arg1 == 0x49) {
        position[0] = arg0->position[0];
        position[2] = arg0->position[2];
        position[1] = 0.0f;
        func_80108474(0x386, position, -0x5A);
        result = 1;
    } else {
        return 0;
    }
    return result;
}

OSThread *chcrusher_entrypoint_0(void)
{
    extern ActorData D_80800B98_chcrusher[];

    return (OSThread *) D_80800B98_chcrusher;
}

void func_80800068_chcrusher(Actor *arg0, u8 *arg1) {
    void func_800DBEFC(void *data,s32 index,f32 *out);
    void func_80101870(Actor* arg0, void* arg1);
    OSThread * func_80104130(void);
    func_80101870(arg0, arg1);
    if (((struct { BT_BITFIELD_ORDER(u32 unused : 19, u32 rest : 12); u32 active : 1; BT_BITFIELD_ORDER(u32 rest : 12, u32 unused : 19); } *)((u8 *)arg0 + 0x7C))->active) {
        func_800DBEFC(func_80104130(), 6, (BtIntPtr) arg0->actorData);
        func_800DBEFC(func_80104130(), 4, (BtIntPtr) &arg0->actorData[4]);
    }
}

void func_808000D4_chcrusher(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_80018820(s32, f32, f32);
    f32 func_800D8FF8(void);
    s32 func_800E1610(s32, f32, f32, f32 *);
    s32 func_80101E14(Actor *, f32);
    void func_80101FDC(Actor *, u32);
    void func_80800394_chcrusher(u8 *);
    void func_808003E4_chcrusher(void *);
    void func_80800508_chcrusher(Actor *);
    extern u32 D_80800B30_chcrusher[];
    extern f32 D_80800B48_chcrusher[][4];
    extern u32 D_80800BE0_chcrusher[];

    switch (arg0->unk70_10) {
        case 1:
            if (!func_800DA298(0x4FB)) {
                func_80101FDC(arg0, 3);
            }
            break;
        case 2:
            if (arg0->unk7C_12 && func_80101E14(arg0, 0.75f)) {
                func_80800394_chcrusher((u8 *)arg0);
            }
            if (func_80101E14(arg0, 0.9f)) {
                _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800B30_chcrusher);
                func_800E1610(2, 80.0f, 0.85f, arg0->position);
                func_80018820(0, 2.5f, 0.25f);
            }
            if (func_80101E14(arg0, 0.48f)) {
                if (func_800DA298(0x4FB)) {
                    func_80101FDC(arg0, 1);
                } else {
                    func_80101FDC(arg0, 3);
                    arg0->unk58 = 0.0f;
                }
            }
            break;
        case 3:
            arg0->unk64_20 = 0;
            arg0->unk58 += func_800D8FF8();
            if (D_80800B48_chcrusher[arg0->unk6C_0][(s32)((f32 *)arg0->actorData)[7]] <= arg0->unk58) {
                if ((s32)((f32 *)arg0->actorData)[7] < 3) {
                    ((f32 *)arg0->actorData)[7] += 1.0f;
                } else {
                    ((f32 *)arg0->actorData)[7] = 0.0f;
                }
                if (func_800DA298(0x4FB)) {
                    func_80101FDC(arg0, 1);
                } else {
                    func_80101FDC(arg0, 2);
                }
            }
            break;
    }
    if (arg0->unk7C_12 && !arg0->unk64_20 && arg0->unk70_10 == 2) {
        func_808003E4_chcrusher(arg0);
    }
    if (arg0->unk7C_12) {
        func_80800508_chcrusher(arg0);
    }
    _subaddieaudioloop_entrypoint_4(arg0, arg0->position, ((f32 *)arg0->actorData)[3] > 0.0f, D_80800BE0_chcrusher);
    if (((f32 *)arg0->actorData)[3] > 0.0f) {
        ((f32 *)arg0->actorData)[3] -= func_800D8FF8();
    }
}

void func_80800394_chcrusher(u8 *arg0) {
    BT_IDO_ONLY(BtIntPtr func_800BABB8(BtIntPtr, BtIntPtr, BtIntPtr, s32, s32 *);)
    extern s32 D_80800BF0_chcrusher[20];
    func_800BABB8(0, BT_NATIVE_ONLY((f32 *))(arg0 + 0x28), 0, BT_DATA_FIELD(1.0f, 0x3F800000), BT_NATIVE_ONLY((s16 *))D_80800BF0_chcrusher);
    (*(f32 *)((s8 *)(arg0) + (0x24))) = 0.3f;
}

void func_808003E4_chcrusher(void *arg0) {
    struct CrusherFlags {
        u8 pad[0x65];
        BT_BITFIELD_ORDER(u8 unused : 3, u8 remaining : 4);
        u8 active : 1;
        BT_BITFIELD_ORDER(u8 remaining : 4, u8 unused : 3);
    };
    void func_8008FE94(s32, f32 *);
    s32 func_80090150(void);
    void func_800904C8(s32);
    f32 upper[3];
    f32 lower[3];
    f32 x;
    f32 z;
    f32 position[3];

    x = ((Actor *)arg0)->position[0] - *(f32 *)((u8 *)arg0 + 0x18);
    z = *(f32 *)((u8 *)arg0 + 0x20) - ((Actor *)arg0)->position[2];
    x += 25.0f;
    z += 25.0f;
    func_8008FE94(5, position);
    upper[0] = ((Actor *)arg0)->position[0] + x;
    lower[0] = ((Actor *)arg0)->position[0] - x;
    upper[1] = *(f32 *)((u8 *)arg0 + 0x1C);
    lower[1] = *(f32 *)((u8 *)arg0 + 0x1C) + 100.0f;
    upper[2] = ((Actor *)arg0)->position[2] + z;
    lower[2] = ((Actor *)arg0)->position[2] - z;
    if (position[2] < upper[2] && *(f32 *)((u8 *)arg0 + 0x1C) < position[1] &&
        position[0] < upper[0] && lower[0] < position[0]) {
        ((struct CrusherFlags *)arg0)->active = 1;
        if (func_80090150() != 0) {
            func_800904C8(0x59);
        }
    }
}

/* extern */

void func_80800508_chcrusher(Actor *arg0) {
    void func_8008FA94(BtIntPtr arg0,BtIntPtr arg1);
    void func_8010D254(f32 *);
    f32 upper[3];
    f32 lower[3];
    f32 x;
    f32 z;
    f32 position[3];

    z = ((f32 *)arg0->actorData)[2] - arg0->position[2];
    x = arg0->position[0] - ((f32 *)arg0->actorData)[0];
    z += 25.0f;
    func_8010D254(position);
    upper[0] = arg0->position[0] - x;
    lower[0] = arg0->position[0] + x;
    upper[1] = ((f32 *)arg0->actorData)[1];
    lower[1] = ((f32 *)arg0->actorData)[1] + 1000.0f;
    upper[2] = arg0->position[2] - z;
    lower[2] = arg0->position[2] + z;
    func_8008FA94(upper, lower);
}

void func_808005C0_chcrusher(s32 arg0) 
{
}
void func_808005C8_chcrusher(Actor *arg0) {
    void func_80101EE4(Actor *, f32);
    void func_80101FDC(Actor *, u32);

    switch (arg0->unk74_7) {
        default:
            arg0->unk6C_0 = 0;
            break;
        case 0x32:
            arg0->unk6C_0 = 0;
            break;
        case 0x33:
            arg0->unk6C_0 = 1;
            break;
        case 0x34:
            arg0->unk6C_0 = 2;
            break;
    }
    ((f32 *)arg0->actorData)[7] = 0.0f;
    arg0->position[2] = -365.0f;
    arg0->position[1] = 10.0f;
    func_80101FDC(arg0, 1);
    func_80101EE4(arg0, 0.48f);
}

/* extern */

s32 func_80800684_chcrusher(Actor *arg0, s32 arg1, s32 arg2) {
    void func_80090494(s32, f32 *);
    void func_8010D254(f32 *);

    if (arg1 == 0x3E) {
        if (arg0->unk70_10 == 2) {
            func_8010D254((f32 *)arg0->actorData);
            if (((f32 *)arg0->actorData)[2] < -50.0f) {
                ((f32 *)arg0->actorData)[0] =
                    ((f32 *)arg0->actorData)[0] - 50.0f;
                func_80090494(6, (f32 *)arg0->actorData);
            }
        }
        arg1 = 1;
    } else {
        return 0;
    }
    return arg1;
}

OSThread *chcrusher_entrypoint_1(void)
{
    extern ActorData D_80800C40_chcrusher[];

    return (OSThread *) D_80800C40_chcrusher;
}
typedef struct { f32 v[3]; } CrusherVector;
void func_80800734_chcrusher(Actor *arg0) {

    extern CrusherVector D_80800C88_chcrusher;
    extern CrusherVector D_80800C94_chcrusher;
    extern u32 D_80800CA0_chcrusher[];
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    void func_8008FA94(BtIntPtr arg0,BtIntPtr arg1);
    void func_80101FDC(Actor *, u32);
    s32 flag;
    CrusherVector sp30;
    CrusherVector sp24;

    flag = func_800DA298(FLAG_4FB_UNK);
    if (arg0->unk74_7 == 0x32) {
        _subaddieaudioloop_entrypoint_4(arg0, arg0->position, flag, D_80800CA0_chcrusher);
        sp30 = D_80800C88_chcrusher;
        sp24 = D_80800C94_chcrusher;
        func_8008FA94(sp30.v, sp24.v);
    }
    switch (arg0->unk70_10) {
        case 1:
            if (flag != 0) {
                func_80101FDC(arg0, 2);
            }
            break;
        case 2:
            if (flag == 0) {
                func_80101FDC(arg0, 1);
            }
            arg0->rotation[2] += arg0->unk54;
            break;
    }
}

/* extern */

void func_80800838_chcrusher(Actor *arg0) {
    f32 func_800D8FF8(void);

    if (arg0->unk74_7 != 0x32) {
        arg0->unk54 = func_800D8FF8() * -240.0f;
        arg0->position[1] = 350.0f;
        arg0->rotation[2] += 22.5f;
        arg0->position[2] = -635.0f;
    } else {
        arg0->unk54 = func_800D8FF8() * 240.0f;
        arg0->position[1] = 100.0f;
        arg0->position[2] = -660.0f;
    }
    arg0->position[0] = -2350.0f;
}

OSThread *chcrusher_entrypoint_2(void)
{
    extern ActorData D_80800CC8_chcrusher[];

    return (OSThread *) D_80800CC8_chcrusher;
}

void func_808008FC_chcrusher(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    s32 func_80090248(void);
    void func_800907C0(f32 *);
    f32 func_800D8FF8(void);
    void func_80101CDC(Actor *, f32);
    void func_80101FDC(Actor *, u32);
    void func_8010D254(f32 *);
    extern u32 D_80800D10_chcrusher[];
    struct CrusherFlags {
        u8 pad0[0x74];
        BT_BITFIELD_ORDER(u32 pad74_28 : 4, u32 : 27);
        BT_BITFIELD_ORDER(u32 enabled : 1, u32 enabled : 1; u32 pad74_28 : 4);
    };
    s32 active;
    f32 position[3];

    active = func_800DA298(FLAG_4FB_UNK);
    _subaddieaudioloop_entrypoint_4(arg0, arg0->position, active, D_80800D10_chcrusher);
    switch (arg0->unk70_10) {
        case 1:
            if (active) {
                func_80101FDC(arg0, 2);
                ((struct CrusherFlags *)arg0)->enabled = 1;
            }
            break;
        case 2:
            if (!active) {
                func_80101FDC(arg0, 1);
                ((struct CrusherFlags *)arg0)->enabled = 0;
            }
            func_8010D254(position);
            if (func_80090248() && position[0] < 2000.0f &&
                position[0] > -2300.0f && position[2] < 0.0f) {
                if (func_800DA298(FLAG0_000_STATE_CANARY_MARY_CAGE_TRIGGER_DIALOG)) {
                    position[0] -= 144.0f * func_800D8FF8();
                } else {
                    position[0] -= 504.0f * func_800D8FF8();
                }
                func_800907C0(position);
            }
            if (func_800DA298(FLAG0_000_STATE_CANARY_MARY_CAGE_TRIGGER_DIALOG)) {
                func_80101CDC(arg0, 33.0f);
            } else {
                func_80101CDC(arg0, 9.428572f);
            }
            break;
    }
}

void func_80800A98_chcrusher(BtIntPtr arg0) {
    void func_800EFA4C(f32[3], f32, f32, f32);
    func_800EFA4C(arg0 + 4, 0.0f, -10.0f, 0.0f);
}

void func_80800ACC_chcrusher(s32 arg0) 
{
}
void func_80800AD4_chcrusher(s32 arg0)
{
    _chswitch_entrypoint_14(arg0,FLAG_4FB_UNK);
}

OSThread *chcrusher_entrypoint_3(void)
{
    extern ActorData D_80800D20_chcrusher[];

    return (OSThread *) D_80800D20_chcrusher;
}

OSThread *chcrusher_entrypoint_4(void)
{
    extern ActorData D_80800D68_chcrusher[];

    return (OSThread *) D_80800D68_chcrusher;
}
/* data_to_c.py: from asm/data/overlays/ch/crusher.data.s */
extern u8 D_80800B78_chcrusher[];
void func_80105834(Actor*);
void func_80107C2C();
void func_80101870 ( Actor * arg0 , void * arg1 );
void func_80108ED0();
extern u8 D_80800CB0_chcrusher[];

void _chswitch_entrypoint_13();
void _chswitch_entrypoint_0();
u32 D_80800B30_chcrusher [6] BT_DATA(4, overlays_ch_crusher, 0x0) = { 0x1304CE, 0xD00E6, 0x1330016, 0x7D000001, 0x1F41388, 0 };
f32 D_80800B48_chcrusher [3] [ 4 ] BT_DATA(4, overlays_ch_crusher, 0x18) = { { 0.5f, 1.0f, 2.0f, 1.0f }, { 2.0f, 2.0f, 2.0f, 2.0f }, { 1.0f, 2.0f, 0.5f, 2.0f } };
u8 D_80800B78_chcrusher[32] BT_DATA(4, overlays_ch_crusher, 0x48) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4B, 0x18, 0x96, 0x80, 0x00, 0x87, 0x00, 0x00, 0x3F, 0x4C, 0xCC, 0xCD, 0x00, 0x87, 0x00, 0x00, 0x4B, 0x18, 0x96, 0x80, 0x00, 0x87, 0x00, 0x00 };
ActorData D_80800B98_chcrusher [1] BT_DATA(4, overlays_ch_crusher, 0x68) = { { 606, 378, 1667, 1, (void *)D_80800B78_chcrusher, (void (*)(struct Actor *))func_808000D4_chcrusher, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80800068_chcrusher, 0, 0, 0, 0, 4104, 14, (void (*)(struct Actor *))func_808005C0_chcrusher, 0, 0, 0, (void (*)(struct Actor *))func_808005C8_chcrusher, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32767, 2, (void (*)(struct Actor *, long, long))func_80800000_chcrusher, 0 } };
u32 D_80800BE0_chcrusher [4] BT_DATA(4, overlays_ch_crusher, 0xB0) = { 0x1304DC, 0x164E20, 0x101F4, 0x13880000 };
s32 D_80800BF0_chcrusher[20] BT_DATA(4, overlays_ch_crusher, 0xC0) = { 168820765, 165478425, 7, 720891, -327600, 327685, 44, -1900549, 13107230, 328080, 1769477, 655394, 51, 11731328, 2752524, 1638464, 8388629, 217, 1677852712, 7536640 };
ActorData D_80800C40_chcrusher [1] BT_DATA(4, overlays_ch_crusher, 0x110) = { { 608, 380, 1670, 1, 0, (void (*)(struct Actor *))func_80800734_chcrusher, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 136, 1028, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_80800838_chcrusher, (void (*)(void *, long, void *, long, void *))func_80107C2C, 0, 0, (void (*)(struct Actor *, long, long))func_80800684_chcrusher, 0 } };
CrusherVector D_80800C88_chcrusher BT_DATA(4, overlays_ch_crusher, 0x158) = { { -2300.0f, -50.0f, -675.0f } };
CrusherVector D_80800C94_chcrusher BT_DATA(4, overlays_ch_crusher, 0x164) = { { -2245.0f, 720.0f, -50.0f } };
u32 D_80800CA0_chcrusher [4] BT_DATA(4, overlays_ch_crusher, 0x170) = { 0x1304CB, 0x167D00, 0x101F4, 0x13880000 };
u8 D_80800CB0_chcrusher[24] BT_DATA(4, overlays_ch_crusher, 0x180) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4B, 0x18, 0x96, 0x80, 0x00, 0x8D, 0x00, 0x00, 0x41, 0x16, 0xDB, 0x6E, 0x00, 0x8D, 0x00, 0x00 };
ActorData D_80800CC8_chcrusher [1] BT_DATA(4, overlays_ch_crusher, 0x198) = { { 607, 379, 1668, 1, (void *)D_80800CB0_chcrusher, (void (*)(struct Actor *))func_808008FC_chcrusher, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 8, 1028, (void (*)(struct Actor *))func_80800ACC_chcrusher, 0, 0, 0, (void (*)(struct Actor *))func_80800A98_chcrusher, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32640, 2, 0, 0 } };
u32 D_80800D10_chcrusher [4] BT_DATA(4, overlays_ch_crusher, 0x1E0) = { 0x1304CD, 0x164650, 0x101F4, 0x13880000 };
ActorData D_80800D20_chcrusher [1] BT_DATA(4, overlays_ch_crusher, 0x1F0) = { { 8, 381, 1669, 1, (void *)BT_DATA_FIELD(D_8011A298, (u8 *)D_8011A270 + 0x28), (void (*)(struct Actor *))_chswitch_entrypoint_13, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 4104, 2060, 0, (BtIntPtr)_chswitch_entrypoint_0, 0, 0, (void (*)(struct Actor *))func_80800AD4_chcrusher, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32767, 2048, 0, 0 } };
ActorData D_80800D68_chcrusher [1] BT_DATA(4, overlays_ch_crusher, 0x238) = { { 344, 902, 1708, 1, 0, 0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 2, 4, 0, 0, 0, 0, 0, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 2050, 0, 0 } };
