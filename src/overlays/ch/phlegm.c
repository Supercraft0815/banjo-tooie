#include "common.h"

OSThread *chphlegm_entrypoint_0(void)
{
    extern ActorData D_80800B58_chphlegm[];

    return (OSThread *) D_80800B58_chphlegm;
}

OSThread *chphlegm_entrypoint_1(void)
{
    extern ActorData D_80800BA0_chphlegm[];

    return (OSThread *) D_80800BA0_chphlegm;
}

OSThread *chphlegm_entrypoint_2(void)
{
    extern ActorData D_80800BE8_chphlegm[];

    return (OSThread *) D_80800BE8_chphlegm;
}

void func_80800024_chphlegm(Actor *arg0) {
    int func_800DC298(f32);
    void func_8010A570(Actor *);

    if (func_800DC298(0.5f)) {
        arg0->unk50 = 600.0f;
    } else {
        arg0->unk50 = -600.0f;
    }
    if (func_800DC298(0.5f)) {
        arg0->unk54 = 50.0f;
    } else {
        arg0->unk54 = -50.0f;
    }
    if (arg0->unk64_20) {
        func_8010A570(arg0);
    }
}

void func_808000C4_chphlegm(Actor *arg0) {
    void _subaddiefade_entrypoint_3(Actor *);
    f32 func_800136E4(f32);
    f32 func_800D8FF8(void);
    f32 func_800EEF94(f32 *);
    void func_800FFAB0(Actor *);
    void func_80101FDC(Actor *, u32);
    void func_80108B04(Actor *, u32);
    void func_8010A570(Actor *);
    s32 func_8010B990(Actor *, s32);
    void func_80800748_chphlegm(Actor *, f32, s32);
    void func_808007EC_chphlegm(u8 *, s32);
    s32 sp2C;
    f32 sp28;
    s32 sp24;

    switch (arg0->unk70_10) {
        case 1:
            sp2C = func_8010B990(arg0, 0x404007);
            sp28 = func_800D8FF8();
            if (arg0->unk64_20) { sp24 = 0x95C; } else { sp24 = 0x95D; }
            func_808007EC_chphlegm((u8 *)arg0, sp24);
            arg0->rotation[0] = func_800136E4(arg0->rotation[0] + sp28 * arg0->unk50);
            arg0->rotation[1] = func_800136E4(arg0->rotation[1] + sp28 * arg0->unk54);
            if (sp2C & 0x28) {
                func_80800748_chphlegm(arg0, -20.0f, sp24);
                func_8010A570(arg0);
                func_80101FDC(arg0, 2);
                _subaddiefade_entrypoint_3(arg0);
                if (arg0->unk64_20) {
                    func_80108B04(arg0, 0);
                }
            }
            if (!arg0->unk64_19 && (arg0->position[1] < -2000.0f || func_800EEF94(arg0->position) > 20000.0f)) {
                func_800FFAB0(arg0);
            }
            break;
        case 2:
            arg0->position[1] -= arg0->scale * func_800D8FF8() * 25.0f;
            break;
    }
}

s32 func_8080026C_chphlegm(Actor *arg0, s32 arg1, Unk80132ED0 *arg2) {
    void func_800FFAB0(Actor *);
    void func_80102FDC(Actor *, f32);
    s32 func_80103140(Actor *, u32, u16);
    Actor *func_801084B0(BtIntPtr, Actor **);
    void func_8010A570(Actor *);
    void func_80800748_chphlegm(Actor *, f32, s32);
    switch (arg1) {
        case 0x3D:
            func_80102FDC(func_801084B0(0x399, &arg0), arg0->scale);
            break;
        case 0x40: {
            Unk80132ED0 **event = &arg2;
            Unk80132ED0 *sp18 = *event;
            func_8010A570(arg0);
            func_80800748_chphlegm(arg0, 0.0f, 0x95D);
            if (sp18->unk24 >> 22) {
                func_800FFAB0(arg0);
            }
            break;
        }
        case 0x95:
            func_80103140(arg0, (u16)(arg0->unk64_20 ? 0x6DC : 0x876), 0);
            break;
        default:
            return 0;
    }
    return 1;
}

/* extern */

void func_80800354_chphlegm(Actor *arg0) {
    f32 func_800DC178(f32, f32);
    f32 func_8010CD28(Actor *);
    f32 temp_f0;

    temp_f0 = func_8010CD28(arg0);
    arg0->unk54 = temp_f0;
    arg0->rotation[1] = temp_f0;
    *(f32 *)&arg0->actorData[3] = arg0->scale * 150.0f;
    arg0->unk58 = func_800DC178(0.8f, 1.0f);
}

void func_808003B4_chphlegm(Actor *arg0) {
    s32 _subaddiefind_entrypoint_4(s32, u8 **, s32);
    f32 _subaddiejoy_entrypoint_9(void *, void *, s32);
    s32 _suchase_entrypoint_1(Actor *);
    void *func_800C6A7C(f32 *, f32 *, f32 *, u32);
    f32 func_800D8FF8(void);
    s32 func_800D90A4(f32 *);
    s32 func_800DA298(s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    f32 func_800F3780(f32, u8 *, s16);
    s32 func_80101DDC(Actor *);
    f32 func_80101F24(Actor *);
    void func_80102424(Actor *, s32);
    void func_80102BF8(void *, f32, f32, f32);
    void func_8010A590(Actor *);
    f32 func_8010CD28(Actor *);
    s32 func_8010D248(void);
    extern u8 D_80800C30_chphlegm[];
    typedef union {
        Actor actor;
        struct {
            u32 prefix[25];
            u32 unk64_31 : 1;
            u32 unk64_30 : 1;
        } flags;
    } PhlegmActor;
    f32 sp8C[3];
    f32 sp80[3];
    f32 sp74[3];
    f32 sp70;
    u8 *actors[10];
    s32 i;
    s32 remaining;
    s32 count;
    f32 speed;

    switch (arg0->unk70_10) {
        case 1:
            if (func_80101DDC(arg0)) {
                func_8010A590(arg0);
                func_80102424(arg0, 2);
            }
            break;
        case 2:
            if (func_8010D248()) {
                if (arg0->unk64_29) {
                    speed = _subaddiejoy_entrypoint_9(arg0, &arg0->unk54, 3);
                } else {
                    speed = 1.0f;
                    arg0->unk54 = func_8010CD28(arg0);
                }
                func_80102BF8(arg0, 0.15f, 120.0f, 360.0f);
                if (func_800DA298(0) && func_800D90A4(&arg0->unk58)) {
                    count = _subaddiefind_entrypoint_4(0x399, actors, 10);
                    remaining = count;
                    for (i = 0; i < count; i++) {
                        if (!((PhlegmActor *)actors[i])->flags.unk64_30) {
                            remaining--;
                        }
                    }
                    if (arg0->unk64_29 || remaining < 4 || _suchase_entrypoint_1(arg0)) {
                        sp70 = func_800D8FF8() * (*(f32 *)&arg0->actorData[3] * speed) * func_800F3780(func_80101F24(arg0), D_80800C30_chphlegm, 4);
                        func_800EE7F8(sp80, arg0->position);
                        func_800EF1B8(sp80, arg0->rotation[1], sp70);
                        sp80[1] -= 80.0f;
                        func_800EE7F8(sp8C, sp80);
                        sp8C[1] = arg0->position[1] + 100.0f;
                        if (func_800C6A7C(sp8C, sp80, sp74, arg0->unk14)) {
                            func_800EE7F8(arg0->position, sp80);
                        }
                    }
                }
            }
            break;
    }
}

s32 func_808005E4_chphlegm(Actor *arg0, s32 arg1, s32 *arg2) {
    extern Actor *_chbaddiesetup_entrypoint_10(s32 id, s32 x, s32 y, s32 z, s32 yaw);
    void _chbaddiesetup_entrypoint_5(void *, BtIntPtr, s32, s32, s32, s32);
    void _chexploder_entrypoint_10(Actor *, s32 *);
    void _chexploder_entrypoint_4(Actor *arg0, s16 *arg1, s32 arg2);
    void _chexploder_entrypoint_9(Actor *arg0, s32 arg1, s32 arg2);
    void _subaddiefade_entrypoint_3(Actor *);
    s32 _subaddiefind_entrypoint_9(s32);
    void *func_80101080(void);
    void func_80103DFC(Actor *, f32 *);
    Actor *func_80106790(Unk80132ED0 *);
    void func_80800748_chphlegm(Actor *, f32, s32);
    extern s32 D_80800C50_chphlegm[3];
    union { f32 f[3]; s32 w[3]; } sp2C;
    Actor *sp28;

    switch (arg1) {
        case 0x40:
            if (_subaddiefind_entrypoint_9(arg0->unk6C_9) == 1) {
                func_80103DFC(arg0, sp2C.f);
                _chbaddiesetup_entrypoint_5(_chbaddiesetup_entrypoint_10, 3, sp2C.w[0], sp2C.w[1], sp2C.w[2], *(s32 *)&arg0->rotation[1]);
            }
            func_80800748_chphlegm(arg0, -10.0f, 0x95C);
            _chexploder_entrypoint_4(arg0, *arg2 + 4, 0x1C);
            break;
        case 0x90:
            sp28 = func_80106790(func_80101080());
            _chexploder_entrypoint_9(sp28, 3, 0);
            _chexploder_entrypoint_9(sp28, 4, 1);
            _chexploder_entrypoint_10(sp28, D_80800C50_chphlegm);
            _subaddiefade_entrypoint_3(sp28);
            break;
        default:
            return 0;
    }
    return 1;
}

/* extern */

void func_80800704_chphlegm(BtIntPtr arg0, BtIntPtr arg1) {
    void func_800DF744(s32 index,s32 value);
    void func_80101870(Actor* arg0, void* arg1);
    func_800DF744(3, 1);
    func_800DF744(4, 0);
    func_80101870(arg0, arg1);
}

void func_80800748_chphlegm(Actor *arg0, f32 arg1, s32 arg2) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    BtIntPtr func_800B53A4(s32);
    void func_800BA3FC(BtIntPtr, s32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    void func_800EE7F8(f32 *, f32 *);
    extern s32 D_80800C5C_chphlegm[11];
    extern s32 D_80800C88_chphlegm[4];
    f32 sp2C[3];
    BtIntPtr sp28;

    func_800EE7F8(sp2C, arg0->position);
    sp2C[1] += arg0->scale * arg1;
    sp28 = func_800B53A4(10);
    func_800BA3FC(sp28, arg2);
    func_800BABB8(sp28, arg0->position, sp2C, arg0->scale, D_80800C5C_chphlegm);
    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800C88_chphlegm);
}

void func_808007EC_chphlegm(u8 *arg0, s32 arg1) {
    BtIntPtr func_800B53A4(s32);
    void func_800BA3FC(BtIntPtr, s32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    extern s32 D_80800C98_chphlegm[11];
    BtIntPtr sp24;
    BtIntPtr temp_v0;

    temp_v0 = func_800B53A4(2);
    sp24 = temp_v0;
    func_800BA3FC(temp_v0, arg1);
    func_800BABB8(sp24, arg0 + 4, NULL, (((Actor *)arg0)->scale), D_80800C98_chphlegm);
}

void func_80800848_chphlegm(s32 arg0) 
{
}
void func_80800850_chphlegm(Actor *arg0) {
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    s32 func_80090150(void);
    s32 func_800C954C(void);
    s32 func_800D9078(f32 *);
    s32 func_800DA298(s32);
    void func_800DA544(s32 index);
    f32 func_800DC178(f32, f32);
    s32 func_800EFFB4(f32 *, f32, f32 *);
    BtUIntPtr func_800F54E4(void);
    s32 func_800F55FC(BtIntPtr);
    void func_80101FDC(Actor *, u32);
    void func_80108B04(Actor *, u32);
    void func_8010D254(f32 *);
    s32 sp34;

    func_8010D254((f32 *)arg0->actorData);
    switch (arg0->unk70_10) {
        case 1:
            if (func_800C954C() == 0) {
                func_80101FDC(arg0, 2);
            }
            break;
        case 2:
            sp34 = func_800F55FC(func_800F54E4());
            if (func_800DA298(0x1A6) == 0 &&
                func_800EFFB4(arg0->position, 1000.0f, (f32 *)arg0->actorData)) {
                func_800DA544(0x1A6);
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x1800, 4, NULL, 0x57);
            }
            if ((sp34 & 0x08000000) && func_80090150()) {
                if (func_800DA298(0x170) == 0) {
                    func_800DA544(0x170);
                    _subaddiedialog_entrypoint_11(arg0->unk0, 0x17FF, 4, NULL, 0x57);
                    func_80101FDC(arg0, 4);
                } else {
                    func_80108B04(arg0, 0);
                    func_80101FDC(arg0, 3);
                    arg0->unk58 = func_800DC178(3.0f, 4.0f);
                }
            }
            break;
        case 3:
            if (func_800D9078(&arg0->unk58)) {
                func_80101FDC(arg0, 2);
            }
            break;
    }
}

s32 func_808009DC_chphlegm(Actor *arg0, s32 arg1, s32 arg2) {
    void func_80101FDC(Actor *, u32);
    void func_80800A58_chphlegm(Actor *);
    s32 *data = &arg2;
    switch (arg1) {
        case 0x3D:
            func_80800A58_chphlegm(arg0);
            break;
        case 0x2E:
            func_80101FDC(arg0, 2);
            break;
        case 0x95:
            func_80101FDC(arg0, 1);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800A58_chphlegm(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_8008FE68(f32 *);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800DC178(f32, f32);
    Actor *func_80108528(s32, f32[3], s32, Actor **);
    void func_80102FDC(Actor *, f32);
    void func_800EFB24(void *, void *, void *);
    void func_800EF368(f32 *, f32);
    extern s32 D_80800CC4_chphlegm[5];
    extern f32 D_80800CD8_chphlegm[3];
    f32 sp44[3];
    f32 sp38[3];
    f32 sp2C[3];
    Actor *actor;

    _subaddieaudioquick_entrypoint_2(arg0, D_80800CD8_chphlegm, D_80800CC4_chphlegm);
    func_8008FE68(sp2C);
    func_800EE7F8(sp38, sp2C);
    func_800EE7F8(sp44, sp2C);
    sp44[1] += 2500.0f;
    actor = func_80108528(0x398, sp44, 0, &arg0);
    func_80102FDC(actor, func_800DC178(3.0f, 4.0f));
    func_800EFB24(&actor->actorData[4], sp38, sp44);
    func_800EF368((f32 *)&actor->actorData[4], 3500.0f);
    actor->unk64_19 = 1;
}
/* data_to_c.py: from asm/data/overlays/ch/phlegm.data.s */
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
OSThread *func_80108ED0(void);
void func_80107C2C();
extern u8 D_80800B40_chphlegm[];
void func_8010A730();
u8 D_80800B40_chphlegm[24] BT_DATA(4, overlays_ch_phlegm, 0x0) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x5E, 0xB8, 0x52, 0x01, 0xBC, 0x00, 0x02, 0x3F, 0x0C, 0xCC, 0xCD, 0x01, 0xBD, 0x00, 0x01 };
ActorData D_80800B58_chphlegm [1] BT_DATA(4, overlays_ch_phlegm, 0x18) = { { 763, 920, -1, 1, 0, (void (*)(struct Actor *))func_808000C4_chphlegm, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 29999, 1061997773, 0, 0, 20, 1028, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_80800024_chphlegm, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32704, 0, (void (*)(struct Actor *, long, long))func_8080026C_chphlegm, 0 } };
ActorData D_80800BA0_chphlegm [1] BT_DATA(4, overlays_ch_phlegm, 0x60) = { { 764, 921, 1757, 1, (void *)D_80800B40_chphlegm, (void (*)(struct Actor *))func_808003B4_chphlegm, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80800704_chphlegm, 0, 1061997773, 0, 0, 788, 1316, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_80800354_chphlegm, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32736, 15, (void (*)(struct Actor *, long, long))func_808005E4_chphlegm, 0 } };
ActorData D_80800BE8_chphlegm [1] BT_DATA(4, overlays_ch_phlegm, 0xA8) = { { 778, 928, 0, 1, 0, (void (*)(struct Actor *))func_80800850_chphlegm, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_8010A730, 0, 0, 229, 0, 0, 0, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800848_chphlegm, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1538, (void (*)(struct Actor *, long, long))func_808009DC_chphlegm, 0 } };
u8 D_80800C30_chphlegm [32] BT_DATA(4, overlays_ch_phlegm, 0xF0) = { 0, 0, 0, 0, 0x3F, 0x40, 0, 0, 0x3E, 0x99, 0x99, 0x9A, 0x3F, 0, 0, 0, 0x3F, 0x4C, 0xCC, 0xCD, 0x3F, 0x80, 0, 0, 0x3F, 0x80, 0, 0, 0x3F, 0x40, 0, 0 };
s32 D_80800C50_chphlegm[3] BT_DATA(4, overlays_ch_phlegm, 0x110) = { 4456517, 4587591, 4784127 };
s32 D_80800C5C_chphlegm[11] BT_DATA(4, overlays_ch_phlegm, 0x11C) = { 1310742, 394395682, 1638451, 786457, 2818201, 13369389, 39322400, 458752, 917514, 1313306, 0 };
s32 D_80800C88_chphlegm[4] BT_DATA(4, overlays_ch_phlegm, 0x148) = { 1246239, 131085, 15925516, 0 };
s32 D_80800C98_chphlegm[11] BT_DATA(4, overlays_ch_phlegm, 0x158) = { 1446400, 2228249, 3342348, 1638443, 4980838, 1376281, 10027022, 655390, 1834608, -19660262, 0 };
s32 D_80800CC4_chphlegm[5] BT_DATA(4, overlays_ch_phlegm, 0x184) = { 1246520, 131094, 1966080013, 15925516, 0 };
f32 D_80800CD8_chphlegm [ 3 ] BT_DATA(4, overlays_ch_phlegm, 0x198) = { 0.0f, 8000.0f, -1500.0f };
