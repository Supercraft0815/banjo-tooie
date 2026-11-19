#include "common.h"
#include "core2/switch_animations.h"
/* extern */

void func_80800000_chfantasytrashcanbits(Actor *arg0) {
    s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_5(Actor *, f32);
    void _chdoormake_entrypoint_8(void *, u32);
    void _chdoormake_entrypoint_9(Actor *arg0, s32 arg1, u16 arg2, s32 arg3);
    s32 func_800EA090(void);
    u32 func_800F54E4(void);
    s32 func_800F64A4(BtIntPtr, s32);
    s32 func_8010108C();
    void func_80101FDC(Actor *, u32);
    if (func_800EA090() == 0x11) {
        func_80101FDC(arg0, 4);
    } else {
        func_80101FDC(arg0, 1);
    }
    _chdoormake_entrypoint_3(arg0, arg0->rotation[1], 90.0f, arg0->scale * 325.0f, 0x80A, 0);
    _chdoormake_entrypoint_8(arg0, 2);
    _chdoormake_entrypoint_5(arg0, 2.0f);
    _chdoormake_entrypoint_9(arg0, 0, 7, 0x10);
    if ((func_800F64A4(func_800F54E4(), 0x400) == 0) && (arg0->unk70_10 == 4)) {
        func_8010108C(arg0, 8, 0);
    }
}

/* extern */

void func_808000EC_chfantasytrashcanbits(Actor *arg0) {
    void _chdoor_entrypoint_0(BtIntPtr arg0);
    void _subaddieDll_entrypoint_4(void *arg0, s32 arg1);
    f32 func_800EFC7C(void *, void *);
    u32 func_800F54E4(void);
    void func_800F5A00(BtIntPtr, f32 *);
    s32 func_8010108C();
    f32 sp2C[3];
    u32 temp_t6;

    temp_t6 = arg0->unk70_10;
    if (temp_t6 != 1) {
        if (temp_t6 == 4) {
            func_800F5A00(func_800F54E4(), sp2C);
            _subaddieDll_entrypoint_4(arg0, 1);
            if (func_800EFC7C(arg0->position, sp2C) > 4000000.0f) {
                func_8010108C(arg0, 8, 0);
            }
        }
    } else {
        _subaddieDll_entrypoint_4(arg0, 0);
    }
    _chdoor_entrypoint_0(arg0);
}

OSThread *chfantasytrashcanbits_entrypoint_0(void)
{
    extern ActorData D_80800240_chfantasytrashcanbits[];

    return (OSThread *) D_80800240_chfantasytrashcanbits;
}

/* extern */

void func_808001A8_chfantasytrashcanbits(BtIntPtr arg0) {
    s32 _chswitch_entrypoint_7(BtIntPtr, s32);
    void _chswitch_entrypoint_8(s32 *arg0, s32 arg1);
    _chswitch_entrypoint_7(arg0, 0x9FF);
    _chswitch_entrypoint_8(arg0, 0x400);
}

/* extern */

void func_808001D8_chfantasytrashcanbits(s32 arg0, s32 arg1, s32 arg2) {
    s32 _chswitch_entrypoint_10(BtIntPtr, s32, s32);
    s32 func_80101180(s32);
    if (arg1 == 7) {
        func_80101180(0x40C);
    }
    _chswitch_entrypoint_10(arg0, arg1, arg2);
}

OSThread *chfantasytrashcanbits_entrypoint_1(void)
{
    extern ActorData D_80800288_chfantasytrashcanbits[];

    return (OSThread *) D_80800288_chfantasytrashcanbits;
}
/* data_to_c.py: from asm/data/overlays/ch/fantasy/trashcanbits.data.s */
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
s32 _chdoor_entrypoint_1(Actor *arg0, s32 arg1, BtIntPtr arg2);

void _chswitch_entrypoint_6();
ActorData D_80800240_chfantasytrashcanbits [1] BT_DATA(4, overlays_ch_fantasy_trashcanbits, 0x0) = { { 172, 1036, 2252, 1, 0, (void (*)(struct Actor *))func_808000EC_chfantasytrashcanbits, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 163840000, 0, 0, 0, 0, 2048, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800000_chfantasytrashcanbits, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 9218, (void (*)(struct Actor *, long, long))_chdoor_entrypoint_1, 0 } };
ActorData D_80800288_chfantasytrashcanbits [1] BT_DATA(4, overlays_ch_fantasy_trashcanbits, 0x48) = { { 835, 1035, 1977, 1, (void *)BT_DATA_FIELD(D_8011A220, (u8 *)D_8011A1BC + 0x64), (void (*)(struct Actor *))_chswitch_entrypoint_6, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 2056, 0, 0, 0, 0, (void (*)(struct Actor *))func_808001A8_chfantasytrashcanbits, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 11266, (void (*)(struct Actor *, long, long))func_808001D8_chfantasytrashcanbits, 0 } };
