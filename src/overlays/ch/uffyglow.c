#include "common.h"
typedef struct { f32 v[3]; } GlowVector;
void func_80800000_chchuffyglow(Actor *arg0, s32 arg1) {

    s32 _subaddiefade_entrypoint_0(Actor *);
    void func_8008B304(BtIntPtr);
    void * func_8008B4D4(void *arg0);
    void func_800D93A0(f32[4], f32[3]);
    void *func_800DE448(f32 *, f32 *, f32, f32 *, BtIntPtr);
    void func_800DF410(s32);
    void func_800DF41C(BtIntPtr);
    void func_800DF830(s32);
    void func_800DFF2C(u8 **, s32, f32[4]);
    void func_800DFFA0(s32 *, s32, BtIntPtr);
    void *func_80100094(Actor *, u32);
    void func_80102780(void *, void *);
    BtIntPtr func_8010347C(Unk80132ED0 *);
    struct anctrl_s *func_80104248(void *);
    extern GlowVector D_80800550_chchuffyglow;
    extern GlowVector D_8080055C_chchuffyglow;
    GlowVector sp7C = D_80800550_chchuffyglow;
    GlowVector sp70 = D_8080055C_chchuffyglow;
    f32 sp60[4];
    struct anctrl_s *temp_s0;
    BtIntPtr temp_s3;
    BtIntPtr temp_v0;
    s32 var_s0;
    BtIntPtr var_s1;
    BtIntPtr var_s2;

    temp_s0 = func_80104248(arg0);
    temp_s3 = (BtIntPtr)func_80100094(arg0, 0);
    func_80102780(arg0, sp70.v);
    func_8008B304((BtIntPtr)temp_s0);
    temp_v0 = func_8008B4D4(temp_s0);
    func_800DFFA0((s32 *)temp_v0, 3, temp_s3);
    var_s0 = 0;
    var_s1 = temp_s3 + 0xC;
    var_s2 = temp_s3 + 0x48;
    do {
        func_800DFFA0((s32 *)temp_v0, (var_s0 + 0x2A), var_s1);
        func_800D93A0(sp60, (f32 *)var_s2);
        func_800DFF2C((u8 **)temp_v0, (var_s0 + 0x2A), sp60);
        var_s0 += 1;
        var_s1 += 0xC;
        var_s2 += 0x10;
    } while (var_s0 != 5);
    func_800DF830(2);
    func_800DF410(_subaddiefade_entrypoint_0(arg0));
    func_800DF41C(temp_v0);
    func_800DE448(sp7C.v, sp70.v, arg0->scale, NULL, func_8010347C(arg0->unk0));
}
typedef struct { f32 v[5][3]; } GlowOffsets;
void func_80800180_chchuffyglow(Actor *arg0) {
    s32 _chchuffy_entrypoint_1(Unk80132ED0 *, f32 *, f32 *);
    s32 _subaddiefade_entrypoint_0(Actor *);
    void _subaddiefade_entrypoint_1(void *arg0, s32 arg1);
    f32 func_800D8FF8(void);
    void func_800E3980(f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    void func_800EF3DC(f32 *, f32 *);
    void func_800EF4E4(f32 *, f32, f32, f32, f32, f32);
    void func_800F18FC(f32 *, f32 *, f32 *);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);

    typedef struct { f32 positions[6][3]; f32 rotations[5][4]; } GlowData;

    extern GlowOffsets D_80800568_chchuffyglow;
    extern GlowVector D_808005A4_chchuffyglow;
    GlowOffsets sp84 = D_80800568_chchuffyglow;
    GlowVector sp78 = D_808005A4_chchuffyglow;
    GlowVector sp6C;
    s32 var_s2;
    GlowData *sp64;

    sp64 = func_80100094(arg0, 0);
    _chchuffy_entrypoint_1(arg0->unk3C, (f32 *)arg0->actorData, (f32 *)&arg0->actorData[4]);
    switch (arg0->unk70_10) {
    case 1:
        if (arg0->unk58 <= 0.0f) {
            if (_subaddiefade_entrypoint_0(arg0) < 0xFD) {
                _subaddiefade_entrypoint_1((BtIntPtr)arg0, _subaddiefade_entrypoint_0(arg0) + 3);
            } else {
                arg0->unk70_10 = 2;
            }
        } else {
            arg0->unk58 -= func_800D8FF8();
        }
        break;
    case 2:
        if (!arg0->unk64_20) {
            arg0->unk70_10 = 3;
        }
        break;
    case 3:
        if (_subaddiefade_entrypoint_0(arg0) >= 7) {
            _subaddiefade_entrypoint_1((BtIntPtr)arg0, _subaddiefade_entrypoint_0(arg0) - 7);
        } else {
            func_800FFAB0(arg0);
        }
        break;
    }
    arg0->unk64_20 = _chchuffy_entrypoint_1(arg0->unk3C, (f32 *)arg0->actorData, (f32 *)&arg0->actorData[4]);
    func_800EE7F8(sp64->positions[0], (f32 *)arg0->actorData);
    func_800EF334(sp64->positions[0], 1.0f / 150.0f);
    func_800EF3DC(sp64->positions[0], sp78.v);
    func_800E3980(sp6C.v);
    var_s2 = 0;
    do {
        func_800EF4E4(sp64->positions[var_s2 + 1], ((f32 *)arg0->actorData)[4], ((f32 *)arg0->actorData)[5], 0.0f, ((f32)var_s2 - 1.75f) * 750.0f, 0.0f);
        func_800F18FC((f32 *)arg0->actorData, sp6C.v, sp64->rotations[var_s2]);
        sp64->rotations[var_s2][1] += 90.0f;
        sp64->rotations[var_s2][2] = 180.0f - sp64->rotations[var_s2][0];
        sp64->rotations[var_s2][0] = 0.0f;
        func_800EF334(sp64->positions[var_s2 + 1], 1.0f / 150.0f);
        func_800EF3DC(sp64->positions[var_s2 + 1], sp84.v[var_s2]);
        var_s2++;
    } while (var_s2 != 5);
}

void func_80800484_chchuffyglow(s32 arg0) 
{
}
void func_8080048C_chchuffyglow(BtIntPtr arg0) {
    void _subaddiefade_entrypoint_1(void *arg0, s32 arg1);
    _subaddiefade_entrypoint_1(arg0, 0);
    ((Actor *)arg0)->unk58 = 5.0f;
    ((Actor *)arg0)->unk64_20 = 1;
}

/* extern */

void chchuffyglow_entrypoint_0(s32 arg0) {
    s32 *func_80106790();
    void *func_801084B0(BtIntPtr, s32 **);
    s32 *sp24;
    s32 pad[2];

    sp24 = func_80106790();
    (*(s32 *)((s8 *)(func_801084B0(0x30E, &sp24)) + (0x3C))) = (s32) *sp24;
}

OSThread *chchuffyglow_entrypoint_1(void)
{
    extern ActorData D_808005B0_chchuffyglow[];

    return (OSThread *) D_808005B0_chchuffyglow;
}
/* data_to_c.py: from asm/data/overlays/ch/uffyglow.data.s */
extern u8 D_80800530_chchuffyglow[];
void func_80105834(Actor*);
void func_80107C2C();
u8 D_80800530_chchuffyglow[32] BT_DATA(4, overlays_ch_uffyglow, 0x0) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4B, 0x18, 0x96, 0x80, 0x02, 0xCA, 0x00, 0x00, 0x4B, 0x18, 0x96, 0x80, 0x02, 0xCA, 0x00, 0x00, 0x4B, 0x18, 0x96, 0x80, 0x02, 0xCA, 0x00, 0x00 };
GlowVector D_80800550_chchuffyglow BT_DATA(4, overlays_ch_uffyglow, 0x20) = { { 0.0f, 0.0f, 0.0f } };
GlowVector D_8080055C_chchuffyglow BT_DATA(4, overlays_ch_uffyglow, 0x2C) = { { 0.0f, 0.0f, 0.0f } };
GlowOffsets D_80800568_chchuffyglow BT_DATA(4, overlays_ch_uffyglow, 0x38) = { { { 0.0f, -0.052f, 7.84f }, { 0.0f, -0.035f, 1.66f }, { 0.0f, -0.519f, -4.74f }, { 0.0f, -0.26f, -10.82f }, { 0.0f, -0.474f, -17.03f } } };
GlowVector D_808005A4_chchuffyglow BT_DATA(4, overlays_ch_uffyglow, 0x74) = { { 0.0f, 2.91f, 4.3f } };
ActorData D_808005B0_chchuffyglow [1] BT_DATA(4, overlays_ch_uffyglow, 0x80) = { { 723, 782, 1849, 1, (void *)D_80800530_chchuffyglow, (void (*)(struct Actor *))func_80800180_chchuffyglow, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80800000_chchuffyglow, 0, 0, 0, 0, 0, 5132, (void (*)(struct Actor *))func_80800484_chchuffyglow, 0, 152, 0, (void (*)(struct Actor *))func_8080048C_chchuffyglow, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 2, 0, 0 } };
