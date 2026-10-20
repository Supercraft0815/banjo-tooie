#include "common.h"

OSThread *chcrate_entrypoint_0(void)
{
    extern u8 D_80800410_chcrate[];

    return (OSThread *) D_80800410_chcrate;
}

OSThread *chcrate_entrypoint_1(void)
{
    extern u8 D_80800458_chcrate[];

    return (OSThread *) D_80800458_chcrate;
}

OSThread *chcrate_entrypoint_2(void)
{
    extern u8 D_808004A0_chcrate[];

    return (OSThread *) D_808004A0_chcrate;
}

/* extern */

void func_80800024_chcrate(s32 arg0) {
    s32 func_800DA298(s32);
    s32 func_800FFAB0(s32);
    s32 func_80800380_chcrate();
    s32 temp_v0;

    temp_v0 = func_80800380_chcrate();
    if ((temp_v0 != 0) && (func_800DA298(temp_v0) != 0)) {
        func_800FFAB0(arg0);
    }
}

s32 func_80800064_chcrate(Actor *arg0, s32 arg1, Unk80132ED0 *volatile arg2) {
    void func_800EC398(Unk80132ED0 *, f32 *);
    f32 func_800EC708(Unk80132ED0 *);
    s32 _chexploder_entrypoint_4(void *, s32, s32);
    void func_80800104_chcrate(Actor *);
    Unk80132ED0 *sp1C;

    switch (arg1) {
    case 0x40:
        sp1C = arg2;
        func_800EC398(sp1C, (f32 *)arg0->actorData);
        ((f32 *)arg0->actorData)[1] += func_800EC708(sp1C);
        _chexploder_entrypoint_4(arg0, (s32)(sp1C->unk0 + 1), 4);
        break;
    case 0x90:
        func_80800104_chcrate(arg0);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800104_chcrate(Actor *arg0) {
    void _chbaddiesetup_entrypoint_5(void *, s32, s32, s32, s32, s32);
    s32 _chexploder_entrypoint_12(Actor *, s32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    s32 func_800DA544(s32);
    s32 func_800FFAB0();
    void *func_80101080(void);
    void func_80101FDC(Actor *, u32);
    void func_80103110(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    void func_801096C8(Actor *, s32);
    void func_8010A570(Actor *);
    void func_8010A624(Actor *);
    s32 func_80800380_chcrate();
    extern s32 D_808004E8_chcrate;
    extern s32 D_808004F8_chcrate;
    extern s32 D_80800508_chcrate;
    extern void _chcrate_entrypoint_3(s32, s32, s32, s32, s32);
    Actor *sp4C;
    s32 sp48;
    s32 sp44[1];
    s32 sp40[1];
    s32 sp3C[1];
    s32 sp38[1];
    s32 sp34[1];

    sp4C = func_80106790(func_80101080());
    sp48 = func_80800380_chcrate(arg0);
    _chexploder_entrypoint_12(sp4C, 0x32);
    func_800BBCB8(arg0->position, (f32 *)arg0->actorData, arg0->scale, 10, &D_80800508_chcrate);
    func_801096C8(arg0, 0);
    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_808004E8_chcrate);
    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_808004F8_chcrate);
    if ((s32)arg0->unk74_7 >= 0x33) {
        sp44[0] = arg0->position[0];
        sp40[0] = arg0->position[1];
        sp3C[0] = arg0->position[2];
        sp38[0] = arg0->rotation[1];
        sp34[0] = arg0->unk74_7;
        _chbaddiesetup_entrypoint_5(_chcrate_entrypoint_3, sp44[0], sp40[0], sp3C[0], sp38[0], sp34[0]);
    } else if (sp48 != 0) {
        func_800DA544(sp48);
    }
    if (sp48 != 0) {
        func_800FFAB0(arg0);
        return;
    }
    func_80101FDC(arg0, 2);
    func_80103110(arg0, 0);
    func_8010A570(arg0);
    func_8010A624(arg0);
    arg0->unk64_16 = 0;
}

void chcrate_entrypoint_3(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 func_800D0B68(u32, u32);
    void func_800D1000(u32, u32, f32 *, u32, Unk80132ED0 *);
    Actor *func_80108474(u32, f32 *, s32);
    s16 func_808003AC_chcrate();
    f32 position[3];
    Actor *actor = NULL;

    position[0] = arg0;
    position[1] = arg1;
    position[2] = arg2;
    switch (arg4) {
    case 0x33:
    case 0x34:
    case 0x35:
    case 0x36:
    case 0x37:
    case 0x38:
    case 0x3A:
    case 0x3B:
        actor = func_80108474(func_808003AC_chcrate(arg4), position, arg3);
        actor->unk74_7 = 0x32;
        break;
    case 0x39:
        if (func_800D0B68(6, 2) == 0) {
            func_800D1000(6, 2, position, 3, NULL);
        }
        break;
    }
    if (actor != NULL) {
        struct CrateFlags {
            u8 pad[0x70];
            u32 pad70_18 : 14;
            u32 unk70_17 : 1;
            u32 pad70_0 : 17;
        };
        struct CrateFlags *flags = (void *)actor;
        flags->unk70_17 = 1;
    }
}

s32 func_80800380_chcrate(u8 *arg0) {
    struct CrateData { u8 pad[0x76]; unsigned short index : 9; unsigned short rest : 7; };
    s32 ret = 0;
    s32 temp;

    if (((struct CrateData *)arg0)->index < 0x32) {
        temp = 0x31 - ((struct CrateData *)arg0)->index;
        ret = temp + 0xA40;
        return ret;
    }
    return ret;
}

s16 func_808003AC_chcrate(s32 arg0) {
    extern s16 D_8080053C_chcrate[];
    s32 index;

    index = arg0 - 0x32;
    if (index > 0) {
        return D_8080053C_chcrate[index];
    }
    return 0;
}
