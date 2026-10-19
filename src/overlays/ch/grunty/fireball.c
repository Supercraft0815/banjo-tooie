#include "common.h"

OSThread *chgruntyfireball_entrypoint_0(void)
{
    extern u8 D_80800480_chgruntyfireball[];

    return (OSThread *) D_80800480_chgruntyfireball;
}

void func_8080000C_chgruntyfireball(s16 *arg0) {
    void func_80109EEC(s16 *arg0, s32 arg1);
    (*(s32 *)((s8 *)(arg0) + (0x24))) = 0;
    func_80109EEC(arg0, 0x40);
}

void func_80800030_chgruntyfireball(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    s32 func_8001210C(s32);
    void func_80018820(s32, f32, f32);
    void func_800C8CB8(s32, f32 *);
    void func_800C8E84(s32, u32 *);
    s32 func_800E15CC(s32, f32, f32);
    s32 func_8010B990(Actor *, s32);
    void func_80800260_chgruntyfireball(u8 *);
    void func_808003D8_chgruntyfireball(f32 *);
    extern u32 D_808004C8_chgruntyfireball[];
    extern u32 D_808004E0_chgruntyfireball[][3];
    _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, D_808004C8_chgruntyfireball);
    switch (arg0->unk70_10) {
        case 1:
            func_808003D8_chgruntyfireball((f32 *)arg0);
            break;
        case 2:
            if (func_8010B990(arg0, 0x400007) & 0x20) {
                func_80018820(0, 1.0f, 0.18f);
                func_800E15CC(0, 22.0f, 0.8f);
                func_80800260_chgruntyfireball((u8 *)arg0);
            } else {
                func_808003D8_chgruntyfireball((f32 *)arg0);
            }
            break;
    }
    if ((s32)arg0->actorData[3] != 0) {
        func_800C8CB8((s32)arg0->actorData[3], arg0->position);
        func_800C8E84(arg0->actorData[3], D_808004E0_chgruntyfireball[func_8001210C(1)]);
    }
}

s32 func_80800130_chgruntyfireball(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _subaddieaudioquick_entrypoint_2(u8 *, f32 *, s32 *);
    s32 func_800C8A98(void);
    void func_800C8CB8(s32, f32 *);
    void func_800C8D4C(s32, f32 *);
    void func_800EF368(f32 *, f32);
    void func_800EFB24(void *, void *, void *);
    void func_80101FDC(Actor *, u32);
    void func_8010A590(Actor *);
    void func_8010D09C(s32, f32 *, f32);
    void func_80800260_chgruntyfireball(u8 *);
    extern s32 D_808004F8_chgruntyfireball[];
    extern f32 D_8080050C_chgruntyfireball[];
    f32 sp34[3];
    s32 pad[2];

    switch (arg1) {
        case 0xA:
            func_8010A590(arg0);
            func_80101FDC(arg0, 2);
            func_8010D09C((arg2 >> 16) & 0xFFFF, sp34, 0.0f);
            sp34[1] += 50.0f;
            func_800EFB24((f32 *)((u8 *)arg0 + 0x28), sp34, arg0->position);
            func_800EF368((f32 *)((u8 *)arg0 + 0x28), (f32)(arg2 & 0xFFFF));
            _subaddieaudioquick_entrypoint_2((u8 *)arg0, arg0->position, D_808004F8_chgruntyfireball);
            break;
        case 0x40:
            func_80800260_chgruntyfireball((u8 *)arg0);
            break;
        case 0x95:
            arg0->actorData[3] = func_800C8A98();
            func_800C8CB8(arg0->actorData[3], arg0->position);
            func_800C8D4C(arg0->actorData[3], D_8080050C_chgruntyfireball);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800260_chgruntyfireball(u8 *arg0) {
    s32 _chlightfader_entrypoint_1(s32, f32, s32);
    s32 _subaddieaudioquick_entrypoint_2(u8 *, f32 *, s32 *);
    s32 func_800B53A4(s32);
    s32 func_800BABB8(s32, f32 *, f32 *, f32, s32 *);
    f32 func_800DC178(f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EEB9C(f32 *, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    s32 func_800FFAB0(u8 *);
    s32 func_8010A570(u8 *);
    extern s32 D_80800514_chgruntyfireball;
    extern s32 D_80800524_chgruntyfireball;
    f32 sp7C[3];
    f32 sp70[3];
    s32 temp_s5;
    s32 var_s1;

    func_8010A570(arg0);
    _subaddieaudioquick_entrypoint_2(arg0, (f32 *)(arg0 + 4), &D_80800514_chgruntyfireball);
    func_800EE7F8(sp7C, (f32 *)(arg0 + 4));
    sp7C[1] += -10.0f;
    temp_s5 = func_800B53A4(0xA);
    for (var_s1 = 0; var_s1 < 10; var_s1++) {
        func_800EEB9C(sp70, (f32) var_s1 * 36.0f, func_800DC178(60.0f, 80.0f));
        func_800EF04C(sp70, (f32 *)(arg0 + 4));
        func_800BABB8(temp_s5, sp70, sp7C, 1.0f, &D_80800524_chgruntyfireball);
    }
    if (*(s32 *)(arg0 + 0x24) != 0) {
        *(s32 *)(arg0 + 0x24) = _chlightfader_entrypoint_1(*(s32 *)(arg0 + 0x24), 1.5f, 2);
    }
    func_800FFAB0(arg0);
}

void func_808003D8_chgruntyfireball(f32 *arg0) {
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    void func_800EF368(f32 *, f32);
    extern s32 D_80800554_chgruntyfireball;
    extern s32 D_80800588_chgruntyfireball;
    f32 sp2C[3];
    func_800BBCB8(arg0 + 1, arg0 + 1, 1.0f, 1, &D_80800588_chgruntyfireball);
    func_800EE7F8(sp2C, arg0 + 10);
    func_800EF368(sp2C, 100.0f);
    func_800EF334(sp2C, -1.0f);
    func_800EF04C(sp2C, arg0 + 1);
    func_800BBCB8(sp2C, arg0 + 1, 0.8f, 1, &D_80800554_chgruntyfireball);
}
