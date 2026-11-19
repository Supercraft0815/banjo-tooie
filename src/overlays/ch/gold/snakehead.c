#include "common.h"

OSThread *chgoldsnakehead_entrypoint_0(void)
{
    extern ActorData D_80800508_chgoldsnakehead[];

    return (OSThread *) D_80800508_chgoldsnakehead;
}

OSThread *chgoldsnakehead_entrypoint_1(void)
{
    extern ActorData D_80800550_chgoldsnakehead[];

    return (OSThread *) D_80800550_chgoldsnakehead;
}

OSThread *chgoldsnakehead_entrypoint_2(void)
{
    extern ActorData D_80800598_chgoldsnakehead[];

    return (OSThread *) D_80800598_chgoldsnakehead;
}

void func_80800024_chgoldsnakehead(Actor *arg0) {
    Prop *_gccubesearch_entrypoint_1(u32, f32[3]);
    void _gspropctrl_entrypoint_11(Prop *, f32[3]);
    Actor *_subaddiefind_entrypoint_2(s32, s32 *);
    Actor *_subaddiefind_entrypoint_3(s32, s32 *);
    s32 func_800DA298(s32);
    void func_800DA7A8(s32 startIndex, s32 set, s32 length);
    void func_800FFAB0(Actor *);
    void func_80103014(u8 *);
    struct SnakeFlags { BT_BITFIELD_ORDER(u32 : 18, u32  : 13); u32 enabled : 1; BT_BITFIELD_ORDER(u32 : 13, u32  : 18); };
    Prop *prop;
    f32 position[3];
    Actor *other;
    s32 iterator;

    prop = _gccubesearch_entrypoint_1(0x1EA, arg0->position);
    if (func_800DA298(0x18B)) {
        func_800FFAB0(arg0);
        return;
    }
    _gspropctrl_entrypoint_11(prop, position);
    if (position[2] <= arg0->position[2]) {
        other = _subaddiefind_entrypoint_2(0x10D, &iterator);
        while (other != NULL) {
            if (other->unk74_7 == arg0->unk74_7 && other != arg0) {
                break;
            }
            other = _subaddiefind_entrypoint_3(0x10D, &iterator);
        }
        arg0->position[0] = other->position[0];
        arg0->position[1] = other->position[1];
        arg0->position[2] = 2.0f * position[2] - other->position[2];
    }
    if ((s32)arg0->unk74_7 >= 0x33) {
        ((struct SnakeFlags *)&arg0->unk0->unk28)->enabled = 1;
    } else {
        ((struct SnakeFlags *)&arg0->unk0->unk28)->enabled = 0;
    }
    func_80103014((u8 *)arg0);
    func_800DA7A8(6, 0, 3);
}

void func_8080015C_chgoldsnakehead(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void _subaddiefade_entrypoint_3(Actor *);
    f32 func_800D8FF8(void);
    f32 func_800DC178(f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF214(f32 *, f32, f32, f32);
    void func_800FC63C(u32, u32);
    void func_80101FDC(Actor *actor,u32 state);
    void func_80102B2C(Actor *, f32);
    void func_80102B6C(u8 *, f32);
    extern u8 D_808004F0_chgoldsnakehead[];

    switch (arg0->unk70_10) {
    case 2:
        func_800FC63C(0xE, 0x7FBC);
        func_800EE7F8((f32 *)arg0->actorData, arg0->position);
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_808004F0_chgoldsnakehead);
        func_80101FDC(arg0, 3);
    case 3:
        arg0->unk50 = func_800DC178(-10.0f, 10.0f);
        arg0->unk54 = func_800DC178(-15.0f, 15.0f);
        func_80102B2C(arg0, 5.0f);
        func_80102B6C((u8 *)arg0, 5.0f);
        func_800EF214(arg0->position, arg0->rotation[0], arg0->rotation[1] + 90.0f, func_800DC178(50.0f, 250.0f) * func_800D8FF8());
        if (((f32 *)arg0->actorData)[0] + 125.0f < arg0->position[0]) {
            _subaddiefade_entrypoint_3(arg0);
        }
    case 1:
        return;
    }
}

void func_808002B4_chgoldsnakehead(Actor *arg0, u8 *arg1) { void func_800DF744(s32, s32); void func_80101870(Actor*, void*); func_800DF744(1, ((u32) (arg0->unk0->unk28 << 0x12) >> 0x1F) ? 0 : 1); func_800DF744(2, (s32) ((u32) (arg0->unk0->unk28 << 0x12) >> 0x1F)); func_80101870(arg0, arg1); }

/* extern */

void func_80800324_chgoldsnakehead(BtIntPtr arg0, s32 arg1) {
    s32 func_800DA564(s32, s32);
    void func_800DA7A8(s32 startIndex, s32 set, s32 length);
    s32 func_80101180(s32, s32, BtIntPtr);
    void func_80101FDC(Actor *actor,u32 state);
    void func_80102FE8(void *arg0, s32 arg1);
    void func_80103110(void *arg0, s32 arg1);
    s32 func_8010A570();
    s32 sp1C;
    s32 temp_a1;

    func_8010A570();
    func_80101FDC(arg0, 2);
    func_80102FE8(arg0, 0);
    func_80103110(arg0, 1);
    temp_a1 = func_800DA564(6, 3) + 1;
    sp1C = temp_a1;
    func_800DA7A8(6, temp_a1, 3);
    if (sp1C == 6) {
        func_80101180(0x10E, 7, 0);
    }
}

s32 func_808003A8_chgoldsnakehead(s32 arg0, s32 arg1, volatile s32 arg2) {
    if (arg1 == 0x40) {
        func_80800324_chgoldsnakehead(arg0, *(s32 *)&arg2);
        return 1;
    }
    return 0;
}

/* extern */

void func_808003E0_chgoldsnakehead(Actor *arg0) {
    s32 _chdoormake_entrypoint_3(Actor*, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_8(void*, u32);
    BT_IDO_ONLY(s32 _chdoormake_entrypoint_9(Actor *, s32, s32, s32);) BT_NATIVE_ONLY(void _chdoormake_entrypoint_9(Actor *, s32, u16, s32);)
    if (_chdoormake_entrypoint_3(arg0, 0.0f, 90.0f, 200.0f, 0x41, 0x18B) != 0) {
        _chdoormake_entrypoint_8(arg0, 5U);
        _chdoormake_entrypoint_9(arg0, 0, 6, 0x10);
    }
}

void func_80800440_chgoldsnakehead(Actor *arg0) {
    s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_6(Actor *, s32);
    void _chdoormake_entrypoint_8(void *, u32);
    BT_IDO_ONLY(s32 _chdoormake_entrypoint_12(Actor *, s32, s32);) BT_NATIVE_ONLY(void _chdoormake_entrypoint_12(Actor *, s32, u16);)
    BT_IDO_ONLY(s32 _chdoormake_entrypoint_9(Actor *, s32, s32, s32);) BT_NATIVE_ONLY(void _chdoormake_entrypoint_9(Actor *, s32, u16, s32);)
    s32 _glcutDll_entrypoint_19(s32);
    s32 func_800DA298(s32);
    void func_800FFAB0(Actor *);

    if (_chdoormake_entrypoint_3(arg0, 0.0f, 90.0f, 200.0f, 0x60, 0x59C) != 0) {
        _chdoormake_entrypoint_6(arg0, 0x40400000);
        _chdoormake_entrypoint_8(arg0, 5U);
        _chdoormake_entrypoint_12(arg0, 0, 0xD);
        _chdoormake_entrypoint_9(arg0, 0, 0x2B, 0x2900);
    }
    if ((func_800DA298(0x59C) != 0) && (_glcutDll_entrypoint_19(0xD) == 0)) {
        func_800FFAB0(arg0);
    }
}
/* data_to_c.py: from asm/data/overlays/ch/gold/snakehead.data.s */
void func_80105834(Actor*);
OSThread *func_80108ED0(void);
void func_80107C2C();
void _chdoor_entrypoint_0();
void func_80101870 ( Actor * , void * );
s32 _chdoor_entrypoint_1(Actor *arg0, s32 arg1, BtIntPtr arg2);
u8 D_808004F0_chgoldsnakehead [24] BT_DATA(4, overlays_ch_gold_snakehead, 0x0) = { 0, 0x13, 3, 0xF1, 0, 0xD, 0, 0xCC, 1, 0, 0, 0x16, 0x6D, 0x60, 0, 1, 4, 0xE2, 0x13, 0x88, 0, 0, 0, 0 };
ActorData D_80800508_chgoldsnakehead [1] BT_DATA(4, overlays_ch_gold_snakehead, 0x18) = { { 341, 269, 1624, 1, 0, (void (*)(struct Actor *))func_8080015C_chgoldsnakehead, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_808002B4_chgoldsnakehead, 0, 0, 0, 0, 0, 2048, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_80800024_chgoldsnakehead, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 11264, (void (*)(struct Actor *, long, long))func_808003A8_chgoldsnakehead, 0 } };
ActorData D_80800550_chgoldsnakehead [1] BT_DATA(4, overlays_ch_gold_snakehead, 0x60) = { { 172, 270, 1623, 1, 0, (void (*)(struct Actor *))_chdoor_entrypoint_0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 2048, 0, 0, 0, 0, (void (*)(struct Actor *))func_808003E0_chgoldsnakehead, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 11266, (void (*)(struct Actor *, long, long))_chdoor_entrypoint_1, 0 } };
ActorData D_80800598_chgoldsnakehead [1] BT_DATA(4, overlays_ch_gold_snakehead, 0xA8) = { { 172, 1225, 1623, 1, 0, (void (*)(struct Actor *))_chdoor_entrypoint_0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 2048, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800440_chgoldsnakehead, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 11266, (void (*)(struct Actor *, long, long))_chdoor_entrypoint_1, 0 } };
