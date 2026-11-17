#include "common.h"

OSThread *chhotfloorsmoke_entrypoint_0(void)
{
    extern ActorData D_808002D0_chhotfloorsmoke[];

    return (OSThread *) D_808002D0_chhotfloorsmoke;
}

/* extern */

void func_8080000C_chhotfloorsmoke(Actor *arg0) {
    s32 func_800EA05C();
    s32 temp_v0;

    arg0->unk64_20 = 1;
    temp_v0 = func_800EA05C();
    if (temp_v0 != 0xD1) {
        if (temp_v0 != 0x12B) {
            arg0->unk6C_0 = 0;
            return;
        }
        arg0->unk64_20 = 0;
        arg0->unk6C_0 = 2;
        return;
    }
    arg0->unk6C_0 = 1;
}

void func_80800090_chhotfloorsmoke(Actor *arg0) {
    s32 func_800D9078(f32 *);
    void func_80101FDC(Actor *, u32);
    void func_808000FC_chhotfloorsmoke(Actor *);

    switch (arg0->unk70_10) {
    case 1:
        func_808000FC_chhotfloorsmoke(arg0);
        return;
    case 2:
        if (func_800D9078(&arg0->unk58) != 0) {
            func_80101FDC(arg0, 1);
        }
        return;
    }
}

void func_808000FC_chhotfloorsmoke(Actor *arg0) {
    void func_800CD08C(s32, f32 *);
    s32 func_800DA298(s32);
    f32 func_800DC178(f32, f32);
    void func_80101FDC(Actor *, u32);
    void func_808001E8_chhotfloorsmoke(Actor *, f32[3]);
    f32 sp34;
    f32 sp28[3];

    switch (arg0->unk6C_0) {
    case 1:
        if (func_800DA298(0x66F) == 0) {
            return;
        }
        sp34 = func_800DC178(1.0f, 1.5f);
        break;
    case 2:
        sp34 = func_800DC178(1.0f, 1.5f);
        break;
    default:
        sp34 = func_800DC178(2.0f, 3.0f);
        break;
    }
    func_800CD08C(arg0->unk70_25 - 1, sp28);
    sp28[1] = arg0->position[1];
    func_808001E8_chhotfloorsmoke(arg0, sp28);
    func_80101FDC(arg0, 2);
    arg0->unk58 = sp34;
}

void func_808001E8_chhotfloorsmoke(Actor *arg0, f32 arg1[3]) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    s32 func_800DA298(s32);
    s32 func_800E3E8C(f32 *, f32);
    void func_800EE7F8(f32 *, f32 *);
    extern s32 D_80800318_chhotfloorsmoke[];
    extern s32 D_80800350_chhotfloorsmoke[];
    extern s32 D_80800388_chhotfloorsmoke[];
    f32 sp34[3];
    f32 sp28[3];
    s32 *var_v0;

    if (func_800E3E8C(arg1, 500.0f) != 0) {
        func_800EE7F8(sp34, arg1);
        sp34[1] -= 400.0f;
        func_800EE7F8(sp28, arg1);
        sp28[1] -= 20.0f;
        if (arg0->unk6C_0 == 2) {
            var_v0 = D_80800350_chhotfloorsmoke;
        } else {
            var_v0 = D_80800318_chhotfloorsmoke;
        }
        func_800BABB8(0, sp28, sp34, 1.0f, var_v0);
    }
    if (arg0->unk64_20 && (func_800DA298(0x66F) == 0)) {
        _subaddieaudioquick_entrypoint_2(arg0, arg1, D_80800388_chhotfloorsmoke);
    }
}
/* data_to_c.py: from asm/data/overlays/ch/hot/floorsmoke.data.s */
void func_80105834(Actor*);
void func_8010A730();
void func_80107C2C();
ActorData D_808002D0_chhotfloorsmoke [1] BT_DATA(4, overlays_ch_hot_floorsmoke, 0x0) = { { 435, 806, 0, 1, 0, (void (*)(struct Actor *))func_80800090_chhotfloorsmoke, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_8010A730, 131072000, 0, 0, 0, 0, 1, 0, 0, 0, 0, (void (*)(struct Actor *))func_8080000C_chhotfloorsmoke, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1538, 0, 0 } };
s32 D_80800318_chhotfloorsmoke [14] BT_DATA(4, overlays_ch_hot_floorsmoke, 0x48) = { 202375197, 165478445, 65537200, 720896, 1310720, 24578, 2228377, 16777984, 58720277, 153, 2752512, 655616, 25165839, 0 };
s32 D_80800350_chhotfloorsmoke [14] BT_DATA(4, overlays_ch_hot_floorsmoke, 0x80) = { 68157469, 165478445, 6553800, 720896, 1310720, 32770, 2228377, 16777984, 58720277, 153, 2752512, 655616, 25165839, 0 };
s32 D_80800388_chhotfloorsmoke [10] BT_DATA(4, overlays_ch_hot_floorsmoke, 0xB8) = { 1246428, 852224, 21757973, 128, 6684673, 32770500, 0, 0, 0, 0 };
