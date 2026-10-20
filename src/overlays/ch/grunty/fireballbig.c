#include "common.h"

OSThread *chgruntyfireballbig_entrypoint_0(void)
{
    extern u8 D_80800680_chgruntyfireballbig[];

    return (OSThread *) D_80800680_chgruntyfireballbig;
}

void func_8080000C_chgruntyfireballbig(s16 *arg0) {
    void func_80109EEC(s16 *arg0, s32 arg1);
    (*(s32 *)((s8 *)(arg0) + (0x24))) = 0;
    func_80109EEC(arg0, 0x40);
}

void func_80800030_chgruntyfireballbig(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    s32 func_8001210C(s32);
    void func_80018820(s32, f32, f32);
    void func_800C8CB8(s32, f32 *);
    void func_800C8E84(s32, u32 *);
    f32 func_800D8FF8(void);
    s32 func_800E15CC(s32, f32, f32);
    s32 func_800FFAB0(u8 *);
    s32 func_8010B990(Actor *, s32);
    void func_8080034C_chgruntyfireballbig(u8 *);
    void func_808004C4_chgruntyfireballbig(Actor *);
    void func_80800590_chgruntyfireballbig(Actor *);
    extern u32 D_808006C8_chgruntyfireballbig[];
    extern u32 D_808006E0_chgruntyfireballbig[][3];
    f32 delta;
    _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, D_808006C8_chgruntyfireballbig);
    switch (arg0->unk70_10) {
        case 1:
            func_808004C4_chgruntyfireballbig(arg0);
            break;
        case 2:
            func_80800590_chgruntyfireballbig(arg0);
            if (func_8010B990(arg0, 0x400007) & 0x20) {
                func_80018820(0, 1.2f, 0.22f);
                func_800E15CC(0, 24.0f, 0.84f);
                func_8080034C_chgruntyfireballbig((u8 *)arg0);
            } else {
                func_808004C4_chgruntyfireballbig(arg0);
            }
            break;
        case 3:
            delta = func_800D8FF8();
            func_808004C4_chgruntyfireballbig(arg0);
            arg0->position[1] -= ((f32 *)arg0->actorData)[2] * delta;
            ((f32 *)arg0->actorData)[2] += 800.0f * delta;
            if (arg0->position[1] <= ((f32 *)arg0->actorData)[1]) {
                func_800FFAB0((u8 *)arg0);
            }
            break;
    }
    if ((s32)arg0->actorData[3] != 0) {
        func_800C8CB8(arg0->actorData[3], arg0->position);
        func_800C8E84(arg0->actorData[3], D_808006E0_chgruntyfireballbig[func_8001210C(1)]);
    }
}

s32 func_808001B4_chgruntyfireballbig(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _chlightfader_entrypoint_1(s32, f32, s32);
    s32 _subaddieaudioquick_entrypoint_2(u8 *, f32 *, s32 *);
    void func_8080034C_chgruntyfireballbig(u8 *);
    s32 func_800C8A98(void);
    void func_800C8CB8(s32, f32 *);
    void func_800C8D4C(s32, f32 *);
    void func_800EF368(f32 *, f32);
    void func_800EFB24(void *, void *, void *);
    void func_800F5A00(s32, f32 *);
    f32 func_80101068(void);
    void func_80101FDC(Actor *, u32);
    void func_8010A590(Actor *);
    extern s32 D_808006F8_chgruntyfireballbig;
    extern f32 D_8080070C_chgruntyfireballbig[];
    f32 position[3];
    f32 *direction;

    switch (arg1) {
        case 0xA:
            arg0->unk6C_0 = (arg2 >> 16) & 0x1FF;
            ((f32 *)arg0->actorData)[0] = func_80101068();
            func_8010A590(arg0);
            func_80101FDC(arg0, 2);
            func_800F5A00(arg0->unk6C_0, position);
            direction = (f32 *)&arg0->actorData[4];
            position[1] += 50.0f;
            func_800EFB24(direction, position, arg0->position);
            func_800EF368(direction, (f32)(arg2 & 0xFFFF));
            _subaddieaudioquick_entrypoint_2((u8 *)arg0, arg0->position, &D_808006F8_chgruntyfireballbig);
            break;
        case 0x40:
            func_8080034C_chgruntyfireballbig((u8 *)arg0);
            break;
        case 0x95:
            arg0->actorData[3] = func_800C8A98();
            func_800C8CB8(arg0->actorData[3], arg0->position);
            func_800C8D4C(arg0->actorData[3], D_8080070C_chgruntyfireballbig);
            break;
        case 0x9B:
            func_80101FDC(arg0, 3);
            ((f32 *)arg0->actorData)[1] = (f32)arg2;
            ((f32 *)arg0->actorData)[2] = -150.0f;
            if ((s32)arg0->actorData[3] != 0) {
                arg0->actorData[3] = _chlightfader_entrypoint_1(arg0->actorData[3], 1.5f, 2);
            }
            break;
        default:
            return 0;
    }
    return 1;
}

void func_8080034C_chgruntyfireballbig(u8 *arg0) {
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
    extern s32 D_80800714_chgruntyfireballbig;
    extern s32 D_80800724_chgruntyfireballbig;
    f32 sp7C[3];
    f32 sp70[3];
    s32 temp_s5;
    s32 var_s1;

    func_8010A570(arg0);
    _subaddieaudioquick_entrypoint_2(arg0, (f32 *)(arg0 + 4), &D_80800714_chgruntyfireballbig);
    func_800EE7F8(sp7C, (f32 *)(arg0 + 4));
    sp7C[1] += -10.0f;
    temp_s5 = func_800B53A4(0xA);
    for (var_s1 = 0; var_s1 < 10; var_s1++) {
        func_800EEB9C(sp70, (f32) var_s1 * 36.0f, func_800DC178(60.0f, 80.0f));
        func_800EF04C(sp70, (f32 *)(arg0 + 4));
        func_800BABB8(temp_s5, sp70, sp7C, 1.0f, &D_80800724_chgruntyfireballbig);
    }
    if (*(s32 *)(arg0 + 0x24) != 0) {
        *(s32 *)(arg0 + 0x24) = _chlightfader_entrypoint_1(*(s32 *)(arg0 + 0x24), 1.5f, 2);
    }
    func_800FFAB0(arg0);
}

void func_808004C4_chgruntyfireballbig(Actor *arg0) {
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    void func_800EF368(f32 *, f32);
    extern s32 D_80800754_chgruntyfireballbig;
    extern s32 D_80800788_chgruntyfireballbig;
    f32 sp2C[3];

    func_800BBCB8(arg0->position, arg0->position, arg0->scale * 1.2f, 1, &D_80800788_chgruntyfireballbig);
    func_800EE7F8(sp2C, (f32 *)&arg0->actorData[4]);
    func_800EF368(sp2C, 100.0f);
    func_800EF334(sp2C, -1.0f);
    func_800EF04C(sp2C, arg0->position);
    func_800BBCB8(sp2C, arg0->position, arg0->scale * 0.8f, 1, &D_80800754_chgruntyfireballbig);
}

/* extern */

void func_80800590_chgruntyfireballbig(Actor *arg0) {
    f32 func_800EEB40(f32 *, f32 *);
    void func_800EEBF0(f32 *, f32 *, f32);
    f32 func_800EEF94(f32 *);
    void func_800F18FC(f32 *, f32 *, f32 *);
    void func_800F5A00(s32, f32 *);
    s32 func_800F6438(u32);
    f32 sp3C[3];
    f32 sp34[2];
    f32 distance;

    if (!arg0->unk64_20 && func_800F6438(arg0->unk6C_0)) {
        func_800F5A00(arg0->unk6C_0, sp3C);
        sp3C[1] += 50.0f;
        distance = func_800EEB40(arg0->position, sp3C);
        if (distance < (((f32 *)arg0->actorData)[0] * ((f32 *)arg0->actorData)[0])) {
            arg0->unk64_20 = 1;
            return;
        }
        func_800F18FC(arg0->position, sp3C, sp34);
        func_800EEBF0((f32 *)&arg0->actorData[4], sp34, func_800EEF94((f32 *)&arg0->actorData[4]));
    }
}
