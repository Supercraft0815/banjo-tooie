#include "ch/factory/linkgrill.h"
#include "core2/switch_animations.h"
/* extern */

void func_80800000_chfactorylinkgrill(Actor *arg0) {
    s32 _gccubesearch_entrypoint_10(s32, u32, Actor *);

    arg0->unk79_4 = _gccubesearch_entrypoint_10(0x3E8, arg0->pad6C_21, arg0);
    if (func_800DA298(arg0->unk79_4 + 0x1C0) != 0) {
        func_800FFAB0(arg0);
    }
}

int func_8080006C_chfactorylinkgrill(Actor *arg0, s32 arg1, s32 arg2) {
    void _chskeletonexplode_entrypoint_7(Actor *, f32 *);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    extern s32 D_80800200_chfactorylinkgrill[17];
    extern s32 D_80800244_chfactorylinkgrill[3];
    f32 *position;

    switch (arg1) {
        case 0x40:
            func_800DA544(arg0->unk79_4 + 0x1C0);
            position = arg0->position;
            _chskeletonexplode_entrypoint_7(arg0, position);
            _subaddieaudioquick_entrypoint_2(arg0, position, D_80800244_chfactorylinkgrill);
            func_800BBCB8(position, position, 1.0f, 5, D_80800200_chfactorylinkgrill);
            return 1;
        case 0xF:
            func_800FFAB0(arg0);
            return 1;
        default:
            return 0;
    }
}

OSThread *chfactorylinkgrill_entrypoint_0(void)
{
    extern ActorData D_80800250_chfactorylinkgrill[];

    return (OSThread *) D_80800250_chfactorylinkgrill;
}

void func_80800124_chfactorylinkgrill(s32 arg0)
{
    _chswitch_entrypoint_7(arg0,FLAG_1D9_UNK);
    _chswitch_entrypoint_9(arg0);
}

void func_80800150_chfactorylinkgrill(s32 arg0, s32 arg1, s32 arg2) {
    s32 _chswitch_entrypoint_10(BtIntPtr, s32, s32);
    s32 func_80101180(s32, s32, BtIntPtr);
    if (arg1 == 7) {
        func_80101180(0x3FA, 7, 0);
    }
    _chswitch_entrypoint_10(arg0, arg1, arg2);
}

OSThread *chfactorylinkgrill_entrypoint_1(void)
{
    extern ActorData D_80800298_chfactorylinkgrill[];

    return (OSThread *) D_80800298_chfactorylinkgrill;
}

void func_808001B0_chfactorylinkgrill(Actor *arg0) {
    s32 _chdoormake_entrypoint_0(Actor *arg0, f32 arg1, u32 arg2, s32 arg3);
    void _chdoormake_entrypoint_5(Actor*, f32);
    void _chdoormake_entrypoint_8(void*, u32);
    _chdoormake_entrypoint_0(arg0, -90.0f, 0U, 0x1D9);
    _chdoormake_entrypoint_5(arg0, 1.5f);
    _chdoormake_entrypoint_8(arg0, 2U);
}

OSThread *chfactorylinkgrill_entrypoint_2(void)
{
    extern ActorData D_808002E0_chfactorylinkgrill[];

    return (OSThread *) D_808002E0_chfactorylinkgrill;
}
/* data_to_c.py: from asm/data/overlays/ch/factory/linkgrill.data.s */
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
OSThread *func_80108ED0(void);
void func_80107C2C();

void _chswitch_entrypoint_6();
void _chdoor_entrypoint_0();
s32 _chdoor_entrypoint_1(Actor *arg0, s32 arg1, BtIntPtr arg2);
s32 D_80800200_chfactorylinkgrill[17] BT_DATA(4, overlays_ch_factory_linkgrill, 0x0) = { 1903069, 2819584, 134217762, 33555072, 100665344, 1376256, 2490393, 7, 2949100, 1376236, 1310760, 1310752, 1616928896, 720876, -3211284, 1310770, 1310720 };
s32 D_80800244_chfactorylinkgrill[3] BT_DATA(4, overlays_ch_factory_linkgrill, 0x44) = { 1246368, 1469792, 0 };
ActorData D_80800250_chfactorylinkgrill [1] BT_DATA(4, overlays_ch_factory_linkgrill, 0x50) = { { 284, 1000, 2177, 1, 0, 0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 16384, 3072, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_80800000_chfactorylinkgrill, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 11280, (void (*)(struct Actor *, long, long))func_8080006C_chfactorylinkgrill, 0 } };
ActorData D_80800298_chfactorylinkgrill [1] BT_DATA(4, overlays_ch_factory_linkgrill, 0x98) = { { 835, 1009, 2185, 1, (void *)BT_DATA_FIELD(D_8011A220, (u8 *)D_8011A1BC + 0x64), (void (*)(struct Actor *))_chswitch_entrypoint_6, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 16384, 2056, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_80800124_chfactorylinkgrill, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 11282, (void (*)(struct Actor *, long, long))func_80800150_chfactorylinkgrill, 0 } };
ActorData D_808002E0_chfactorylinkgrill [1] BT_DATA(4, overlays_ch_factory_linkgrill, 0xE0) = { { 172, 1018, 2183, 1, (void *)BT_DATA_FIELD(D_8011A220, (u8 *)D_8011A1BC + 0x64), (void (*)(struct Actor *))_chdoor_entrypoint_0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 163840000, 0, 0, 0, 16384, 3072, 0, 0, 0, 0, (void (*)(struct Actor *))func_808001B0_chfactorylinkgrill, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 9234, (void (*)(struct Actor *, long, long))_chdoor_entrypoint_1, 0 } };
