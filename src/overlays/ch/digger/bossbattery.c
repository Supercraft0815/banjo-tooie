#include "common.h"
#include "bossbattery_tables.h"
OSThread *chdiggerbossbattery_entrypoint_0(void)
{
    extern ActorData D_808002F0_chdiggerbossbattery;

    return (OSThread *)&D_808002F0_chdiggerbossbattery;
}

/* extern */

void func_8080000C_chdiggerbossbattery(Actor *arg0) {
    s32 func_800DA298(s32);
    f32 func_800DC178(f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EFD24(f32 *);
    void func_800FFAB0(Actor *);
    void func_80102FDC(Actor *, f32);
    func_800EE7F8((f32 *)arg0->actorData, arg0->position);
    func_800EFD24(arg0->position);
    func_80102FDC(arg0, 0.25f);
    arg0->unk58 = func_800DC178(1.5f, 3.0f);
    if (func_800DA298(arg0->unk74_7 + 0xA1D) != 0) {
        func_800FFAB0(arg0);
    }
}

void func_80800090_chdiggerbossbattery(Actor *arg0) {
    void _chelectricfence_entrypoint_1(Actor *, f32 *);
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    s32 func_800D9078(f32 *arg0);
    f32 func_800DC178(f32, f32);
    int func_800DC298(f32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);

    f32 sp2C[3];


    _subaddieaudioloop_entrypoint_4(arg0, (f32 *)arg0->actorData, 1, (u32 *)D_80800338_chdiggerbossbattery.audio);
    if (func_800D9078(&arg0->unk58) != 0) {
        func_800EE7F8(sp2C, (f32 *)arg0->actorData);
        func_800EF1B8(sp2C, (func_800DC298(0.5f) ? 1.0f : -1.0f) * 90.0f, 80.0f);
        sp2C[1] += 300.0f;
        _chelectricfence_entrypoint_1(arg0, sp2C);
        arg0->unk58 = func_800DC178(1.5f, 3.0f);
    }
}

s32 func_80800170_chdiggerbossbattery(Actor *arg0, s32 arg1, s32 arg2) {
    void _chexploder_entrypoint_3(void *, void *, u32);
    void _chexploder_entrypoint_9(Actor *arg0, s32 arg1, s32 arg2);
    void _chexploder_entrypoint_13(Actor *, u32);
    void _chexploder_entrypoint_15(Actor *, u32, f32);
    Actor *_subaddiefind_entrypoint_1(Actor *arg0, s32 arg1, s32 arg2, f32 *arg3);
    void func_800DA544(s32 index);
    void func_800DF744(s32, s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    void func_800FC660(u32);
    void *func_80101080(void);
    s32 func_801015D0(Actor *);
    s32 func_80103140(Actor *, u32, u16);
    Actor *func_80106790(Unk80132ED0 *);
    void func_8010A570(Actor *);
    void func_8010A624(Actor *);
    extern ActorData D_808002F0_chdiggerbossbattery;
    f32 sp2C[3];
    Actor *actor;
    switch (arg1) {
    case 0x40: {
        register Actor *battery;
        func_800EE7F8(sp2C, (f32 *)arg0->actorData);
        func_800EF1B8(sp2C, arg0->rotation[1], -400.0f);
        sp2C[1] -= 80.0f;
        func_800DA544(arg0->unk74_7 + 0xA1D);
        func_8010A624(arg0);
        _chexploder_entrypoint_3(arg0, sp2C, 0xC);
        func_800FC660(0xE);
        if ((battery = _subaddiefind_entrypoint_1(arg0, arg0->unk6C_9, -1, 0)) != NULL) {
            func_8010A570(battery);
        }
        break;
    }
    case 0x90:
        actor = func_80106790(func_80101080());
        _chexploder_entrypoint_9(actor, 1, 2);
        _chexploder_entrypoint_15(actor, 2, 1.0f);
        _chexploder_entrypoint_13(actor, 1);
        break;
    case 0x95:
        func_80103140(arg0, BT_DATA_FIELD(D_80800338_chdiggerbossbattery.model[arg0->unk74_7 - 50], ((u16 *)((u8 *)&D_808002F0_chdiggerbossbattery - 8))[arg0->unk74_7]), 0);
        break;
    case 0x1F:
        func_801015D0(arg0);
        func_800DF744(1, 1);
        break;
    default:
        return 0;
    }
    return 1;
}
#include "bossbattery_data.inc"
