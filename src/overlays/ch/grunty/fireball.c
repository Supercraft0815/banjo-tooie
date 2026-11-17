#include "common.h"

OSThread *chgruntyfireball_entrypoint_0(void)
{
    extern ActorData D_80800480_chgruntyfireball[];

    return (OSThread *) D_80800480_chgruntyfireball;
}    typedef struct { u8 pad0[0x24]; s32 unk24; } Objfireball_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_8080000C_chgruntyfireball(s16 *arg0) {
    void func_80109EEC(s16 *arg0, s32 arg1);
    (((Objfireball_arg0 *)arg0)->unk24) = 0;
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
    void func_8010D09C(BtIntPtr, f32 *, f32);
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
    BtIntPtr func_800B53A4(s32);
    BtIntPtr func_800BABB8(BtIntPtr, f32 *, f32 *, f32, s32 *);
    f32 func_800DC178(f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EEB9C(f32 *, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    s32 func_800FFAB0(u8 *);
    s32 func_8010A570(u8 *);
    extern s32 D_80800514_chgruntyfireball[4];
    extern s32 D_80800524_chgruntyfireball[12];
    f32 sp7C[3];
    f32 sp70[3];
    BtIntPtr temp_s5;
    s32 var_s1;

    func_8010A570(arg0);
    _subaddieaudioquick_entrypoint_2(arg0, (f32 *)(arg0 + 4), D_80800514_chgruntyfireball);
    func_800EE7F8(sp7C, (f32 *)(arg0 + 4));
    sp7C[1] += -10.0f;
    temp_s5 = func_800B53A4(0xA);
    for (var_s1 = 0; var_s1 < 10; var_s1++) {
        func_800EEB9C(sp70, (f32) var_s1 * 36.0f, func_800DC178(60.0f, 80.0f));
        func_800EF04C(sp70, (f32 *)(arg0 + 4));
        func_800BABB8(temp_s5, sp70, sp7C, 1.0f, D_80800524_chgruntyfireball);
    }
    if (*(s32 *)(arg0 + 0x24) != 0) {
        *(s32 *)(arg0 + 0x24) = _chlightfader_entrypoint_1(*(s32 *)(arg0 + 0x24), 1.5f, 2);
    }
    func_800FFAB0(arg0);
}

void func_808003D8_chgruntyfireball(f32 *arg0) {
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    void func_800EF368(f32 *, f32);
    extern s32 D_80800554_chgruntyfireball[13];
    extern s32 D_80800588_chgruntyfireball[22];
    f32 sp2C[3];
    func_800BBCB8(arg0 + 1, arg0 + 1, 1.0f, 1, D_80800588_chgruntyfireball);
    func_800EE7F8(sp2C, arg0 + 10);
    func_800EF368(sp2C, 100.0f);
    func_800EF334(sp2C, -1.0f);
    func_800EF04C(sp2C, arg0 + 1);
    func_800BBCB8(sp2C, arg0 + 1, 0.8f, 1, D_80800554_chgruntyfireball);
}
/* data_to_c.py: from asm/data/overlays/ch/grunty/fireball.data.s */
void func_80102EC0();
void func_8010A73C();
OSThread *func_80108ED0(void);
void func_80107C2C();
ActorData D_80800480_chgruntyfireball [1] BT_DATA(4, overlays_ch_grunty_fireball, 0x0) = { { 443, 1266, 1787, 1, 0, (void (*)(struct Actor *))func_80800030_chgruntyfireball, (void (*)(struct Actor *))func_80102EC0, (void (*)(long, long))func_8010A73C, 0, 0, 0, 0, 0, 4, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_8080000C_chgruntyfireball, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 2, (void (*)(struct Actor *, long, long))func_80800130_chgruntyfireball, 0 } };
u32 D_808004C8_chgruntyfireball [6] BT_DATA(4, overlays_ch_grunty_fireball, 0x48) = { 0x13052E, 0x180001, 0x3E81F40, 0xE00C0, 0xD90166, 0 };
u32 D_808004E0_chgruntyfireball [2] [ 3 ] BT_DATA(4, overlays_ch_grunty_fireball, 0x60) = { { 0xC0, 0xFF, 0x7C }, { 0xFF, 0xFF, 0xFF } };
s32 D_808004F8_chgruntyfireball [5] BT_DATA(4, overlays_ch_grunty_fireball, 0x78) = { 1246351, 1572877, 15925516, 66536, 524288000 };
f32 D_8080050C_chgruntyfireball [2] BT_DATA(4, overlays_ch_grunty_fireball, 0x8C) = { 350.0f, 550.0f };
s32 D_80800514_chgruntyfireball[4] BT_DATA(4, overlays_ch_grunty_fireball, 0x94) = { 1246353, 1572865, 65542000, 0 };
s32 D_80800524_chgruntyfireball[12] BT_DATA(4, overlays_ch_grunty_fireball, 0xA4) = { 1903073, 1376268, 10027042, 16777472, 6684774, 2556004, 6553800, 13107243, 5832844, 2949320, 19661082, 0 };
s32 D_80800554_chgruntyfireball[13] BT_DATA(4, overlays_ch_grunty_fireball, 0xD4) = { 1903073, 917554, 3932181, 1638553, 2228480, 16777318, 6684711, 6553700, 13107400, 2818112, 5832749, 13107500, 0 };
s32 D_80800588_chgruntyfireball[22] BT_DATA(4, overlays_ch_grunty_fireball, 0x108) = { 1903033, 1638401, 327707, 19989058, 2949129, 983054, 655380, 1443328, 2555636, -14221529, 14876877, 16187426, 30147072, 4194393, 1376281, 10027051, 6684800, 3080215, 1638425, 0, 238, 0 };
