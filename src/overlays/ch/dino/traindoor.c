#include "common.h"

/* extern */

void func_80800000_chdinotraindoor(Actor *arg0) {
    s32 _chdoormake_entrypoint_12(Actor *, s32, s32);
    s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_5(Actor *, f32);
    void _chdoormake_entrypoint_6(Actor *, s32);
    void _chdoormake_entrypoint_8(void *, u32);
    s32 _chdoormake_entrypoint_9(Actor *, s32, s32, s32);
    s32 _glcutDll_entrypoint_19(s32);
    s32 func_800DA298(s32);
    void func_800EFD24(f32 *);
    void func_800FFAB0(Actor *);
    void func_80103014(u8 *);
    f32 var_f0;

    var_f0 = arg0->rotation[1];
    if (arg0->unk74_7 == 0x32) {
        var_f0 += 180.0f;
    }
    func_800EFD24(arg0->position);
    func_80103014((u8 *)arg0);
    if (_chdoormake_entrypoint_3(arg0, var_f0, 0.0f, arg0->scale * 600.0f, 0x20, 0x164) != 0) {
        _chdoormake_entrypoint_5(arg0, 3.5f);
        _chdoormake_entrypoint_6(arg0, 0x40800000);
        _chdoormake_entrypoint_12(arg0, 0, 0x3C);
        if (arg0->unk74_7 == 0x32) {
            _chdoormake_entrypoint_8(arg0, 5);
            _chdoormake_entrypoint_9(arg0, 0, 0xA, 0x910);
        }
    }
    if ((func_800DA298(0x164) != 0) && (_glcutDll_entrypoint_19(0x3C) == 0)) {
        func_800FFAB0(arg0);
    }
}

void func_80800120_chdinotraindoor(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _chdoor_entrypoint_1(BtIntPtr, s32, BtIntPtr);
    void func_800FFAB0(Actor *);
    s32 func_80103140(Actor *, u32, u16);

    switch (arg1) {
        case 0x95:
            func_80103140(arg0, (u16)(arg0->unk74_7 == 0x32 ? 0x949 : 0x94A), 0);
            break;
        case 0x9D:
            func_800FFAB0(arg0);
            break;
    }
    _chdoor_entrypoint_1((BtIntPtr)arg0, arg1, arg2);
}

OSThread *chdinotraindoor_entrypoint_0(void)
{
    extern ActorData D_808001D0_chdinotraindoor[];

    return (OSThread *) D_808001D0_chdinotraindoor;
}
/* data_to_c.py: from asm/data/overlays/ch/dino/traindoor.data.s */
void _chdoor_entrypoint_0();
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
ActorData D_808001D0_chdinotraindoor [1] BT_DATA(4, overlays_ch_dino_traindoor, 0x0) = { { 172, 1179, -1, 1, 0, (void (*)(struct Actor *))_chdoor_entrypoint_0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 3072, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800000_chdinotraindoor, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 11266, (void (*)(struct Actor *, long, long))func_80800120_chdinotraindoor, 0 } };
