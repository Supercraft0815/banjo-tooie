#include "common.h"

void func_80800000_chtorpedo(u8 *arg0, u8 *arg1)
{
  BtIntPtr _fxairbub_entrypoint_1(f32 *, f32, f32, f32);
  BtIntPtr _fxdlsmoke_entrypoint_0(u8 *);
  s32 *new_var;
  BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
  extern s32 D_808008F4_chtorpedo[9];
  extern s32 D_80800918_chtorpedo[14];
  f32 temp_f0;
  u8 *temp_s0;
  u8 *temp_s0_2;
  temp_f0 = ((Actor *)arg0)->position[1];
  temp_s0 = arg0 + 4;
  if ((((Actor *)arg0)->position[1]) < (*((f32 *) (((s8 *) arg1) + 0x24))))
  {
    temp_s0_2 = arg0 + 4;
 new_var = D_808008F4_chtorpedo; func_800BABB8(_fxairbub_entrypoint_1(temp_s0_2, 5.0f, (((Actor *)arg0)->position[1]) + 200.0f, 1.0f), temp_s0_2, 0, 1.0f, new_var); return;
  }
  func_800BABB8(_fxdlsmoke_entrypoint_0(temp_s0), temp_s0, 0, 1.0f, D_80800918_chtorpedo);
}    typedef struct { u8 pad0[0x24]; f32 unk24; s32 unk28; } Objtorpedo_func_808000B8_chtorpedo_sp44; /* offsets.py genstruct: fields from raw offsets on sp44; rename once understood */

void func_808000B8_chtorpedo(Actor *arg0) {
    BtIntPtr _fxairbub_entrypoint_1(f32 *, f32, f32, f32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    s32 func_800E1610(s32, f32, f32, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EFA98(f32[3], f32[3], f32);
    void *func_80100094(Actor *, u32);
    extern s32 D_80800840_chtorpedo[29];
    extern s32 D_808008B4_chtorpedo[16];
    void *sp44;
    f32 sp38[3];

    sp44 = func_80100094(arg0, 0);
    if (((Objtorpedo_func_808000B8_chtorpedo_sp44 *)sp44)->unk28 == 0) {
        func_800E1610(0, 20.0f, 0.6f, arg0->position);
        func_800EFA98(sp38, (f32 *)((u8 *)arg0 + 0x28), -70.0f);
        func_800EF04C(sp38, arg0->position);
        func_800BABB8(0, sp38, NULL, 1.0f, D_808008B4_chtorpedo);
        func_800EFA98(sp38, (f32 *)((u8 *)arg0 + 0x28), -50.0f);
        func_800EF04C(sp38, arg0->position);
        if (arg0->position[1] < ((Objtorpedo_func_808000B8_chtorpedo_sp44 *)sp44)->unk24) {
            func_800BABB8(_fxairbub_entrypoint_1(sp38, 100.0f, sp38[1] + 200.0f, 1.0f), sp38, arg0->position, 1.0f, D_80800840_chtorpedo);
        }
    }
}

void func_808001E0_chtorpedo(Actor *arg0, s32 arg1) {
    s32 _chlightfader_entrypoint_1(s32, f32, s32);
    s32 func_800C8A98(void);
    void func_800C8CB8(s32, f32 *);
    void func_800C8E54(s32, f32, f32);
    void func_800C8E84(s32, u32 *);
    void func_800CB840(s32, BtIntPtr);
    void func_800CB870(void);
    void func_800EF04C(f32 *, f32 *);
    void func_800EFA98(f32[3], f32[3], f32);
    int func_800F7A7C(BtIntPtr, s32, s32, s32, f32 *);
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    void func_80109BEC(BtIntPtr, f32, s32, s32, s32, BtIntPtr);
    s32 func_8010CC10(f32 *, f32);
    void func_8010CCE0(void);
    s32 func_8010CCEC(void);
    extern u32 D_80800950_chtorpedo[3];
    s32 sp4C;
    s32 pad;
    f32 sp3C[3];
    s32 current;

    if (arg1 != arg0->unk70_10) {
        func_80101FDC(arg0, arg1);
        if (arg0->unk70_10 == 3) {
            sp4C = func_800C8A98();
            func_800C8E84(sp4C, D_80800950_chtorpedo);
            func_800C8CB8(sp4C, arg0->position);
            func_800C8E54(sp4C, 300.0f, 750.0f);
            func_800CB840(6, arg0);
            func_80109BEC(arg0->position, 150.0f, 2, 0, 0, arg0->unk0);
            if (func_8010CC10(arg0->position, 150.0f)) {
                func_800EFA98(sp3C, (f32 *)&arg0->actorData[4], -200.0f);
                func_800EF04C(sp3C, arg0->position);
                func_8010CCE0();
                current = func_8010CCEC();
                while (current != -1) {
                    func_800F7A7C(current, *(s8 *)func_80100094(arg0, 0), 1, 7, sp3C);
                    current = func_8010CCEC();
                }
            }
            _chlightfader_entrypoint_1(sp4C, 1.0f, 1);
            func_800CB870();
            func_808000B8_chtorpedo(arg0);
        }
    }
}

void func_80800350_chtorpedo(Actor *arg0) {
    void func_800F1A88(f32 *, f32 *);
    f32 sp18[2];

    func_800F1A88((f32 *)((s8 *)arg0 + 0x28), sp18);
    arg0->rotation[0] = -sp18[0];
    arg0->rotation[1] = sp18[1];
}    typedef struct { u8 pad0[0x2C]; s32 (*unk2C)(s32, s32, s32); s32 unk30; } Objtorpedo_func_80800394_chtorpedo_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

void func_80800394_chtorpedo(s32 *arg0) {
    void *func_80100094(Actor *, u32);
    void *temp_v0;

    temp_v0 = func_80100094(arg0, 0);
    if ((((Objtorpedo_func_80800394_chtorpedo_temp_v0 *)temp_v0)->unk2C) != NULL) {
        (((Objtorpedo_func_80800394_chtorpedo_temp_v0 *)temp_v0)->unk2C)(*arg0, 5, (((Objtorpedo_func_80800394_chtorpedo_temp_v0 *)temp_v0)->unk30));
    }
}

void func_808003DC_chtorpedo(Actor *arg0) {
    void _sumissilehome_entrypoint_6(Actor *, void *);
    void func_800CB840(s32, BtIntPtr);
    void func_800CB870(void);
    u8 *func_800CD820(u8 *, f32 *, f32 *, f32);
    f32 func_800D8FF8(void);
    void func_800EE7F8(f32 *, f32 *);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    void func_8010A570(Actor *);
    void func_8010A590(Actor *);
    void func_8010AA78(s32 *);
    s32 func_8010B990(Actor *, s32);
    s32 func_8010D350(f32 *, f32 *, f32, s32);
    struct TorpedoData {
        s8 unk0;
        u8 pad1[0x13];
        f32 position[3];
        f32 unk20;
    };
    f32 sp44;
    f32 sp40;
    BtIntPtr sp3C;
    s32 sp38;
    s32 sp34;
    struct TorpedoData *data;
    s32 pad;

    data = func_80100094(arg0, 0);
    sp44 = data->unk20;
    sp40 = func_800D8FF8();
    switch (arg0->unk70_10) {
        case 2:
            _sumissilehome_entrypoint_6(arg0, data);
            sp38 = func_8010B990(arg0, 0x100004);
            if (sp38 == 0x20) {
                func_8010AA78(arg0->position);
            }
            func_80800350_chtorpedo(arg0);
            arg0->rotation[2] += sp40 * 1200.0f;
            func_80800000_chtorpedo(arg0, data);
            func_8010A590(arg0);
            func_800CB840(6, arg0);
            sp3C = func_800CD820(arg0->unk0, data->position, arg0->position, 40.0f);
            func_800CB870();
            func_8010A570(arg0);
            sp34 = sp3C != 0;
            if (func_8010D350(data->position, arg0->position, 40.0f, data->unk0) != -1) {
                sp34 = 1;
            }
            if (sp38 == 0x20 || sp34 != 0 || sp44 > 3.0f) {
                func_808001E0_chtorpedo(arg0, 3);
            }
            break;
        case 3:
            func_800FFAB0(arg0);
            break;
    }
    data->unk20 = sp44 + sp40;
    func_800EE7F8(data->position, arg0->position);
}

Unk80132ED0 *chtorpedo_entrypoint_0(f32 *arg0, f32 *arg1, f32 *arg2, s32 (*arg3)(Unk80132ED0 *, s32, s32), s32 arg4, f32 arg5) {
    void _sumissilehome_entrypoint_0(Actor *, void *);
    void _sumissilehome_entrypoint_1(Actor *, void *, s32);
    void _sumissilehome_entrypoint_2(Actor *, void *, f32);
    void _sumissilehome_entrypoint_3(Actor *, void *, s32);
    void _sumissilehome_entrypoint_4(Actor *, void *, s32);
    void _sumissilehome_entrypoint_5(Actor *, void *, f32, f32);
    void *func_800C6A7C(f32[3], f32[3], f32[3], u32);
    s32 func_800EA05C();
    s32 func_800EA068(s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF368(f32 *, f32);
    void func_800EFB24(void *, void *, void *);
    void *func_80100094(Actor *, u32);
    Actor *func_80108474(u32, f32 *, s32);
    void func_8010A570(Actor *);
    struct TorpedoData {
        u8 pad0[0x14];
        f32 position[3];
        f32 unk20;
        f32 unk24;
        s32 unk28;
        s32 (*unk2C)(Unk80132ED0 *, s32, s32);
        s32 unk30;
    };
    struct TorpedoActorData {
        f32 unk0[4];
        f32 velocity[3];
        f32 unk1C;
    };
    struct TorpedoData *data;
    f32 sp30[3];
    Actor *actor;
    f32 sp20[3];

    if (func_800C6A7C(arg1, arg0, sp30, 0x20020) != NULL) {
        func_800EFB24(sp20, arg1, arg0);
        func_800EF368(sp20, 1.0f);
        func_800EF04C(arg0, sp20);
    }
    actor = func_80108474(0x168, arg0, 0);
    data = func_80100094(actor, 0);
    ((struct TorpedoActorData *)actor->actorData)->unk1C = 0.0f;
    func_800EE7F8(((struct TorpedoActorData *)actor->actorData)->velocity, arg2);
    func_80800350_chtorpedo(actor);
    func_800EE7F8(data->position, arg0);
    data->unk20 = 0.0f;
    data->unk2C = arg3;
    data->unk30 = arg4;
    data->unk24 = arg5;
    data->unk28 = 0;
    func_8010A570(actor);
    _sumissilehome_entrypoint_0(actor, data);
    _sumissilehome_entrypoint_3(actor, data, arg4);
    switch (func_800EA05C()) {
        case 0x181:
            _sumissilehome_entrypoint_1(actor, data, 0x1C7);
            break;
        default:
            if (func_800EA068(0x20) != 0) {
                _sumissilehome_entrypoint_4(actor, data, 1);
            }
            break;
    }
    _sumissilehome_entrypoint_2(actor, data, 4000.0f);
    _sumissilehome_entrypoint_5(actor, data, 4000.0f, 1200.0f);
    func_808001E0_chtorpedo(actor, 2);
    return actor->unk0;
}

s32 func_80800720_chtorpedo(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    void func_800FFAB0(Actor *);
    void func_80109EEC(s16 *, s32);
    struct TorpedoData {
        u8 pad0[0x28];
        s32 unk28;
        s32 (*unk2C)(Unk80132ED0 *, s32, s32);
        s32 unk30;
    } *data;

    data = func_80100094(arg0, 0);
    switch (arg1) {
        case 0x2C:
            data->unk2C = NULL;
            func_800FFAB0(arg0);
            break;
        case 5:
            func_808001E0_chtorpedo(arg0, 3);
            break;
        case 0x95:
            func_80109EEC(arg0, 0x10);
            break;
        case 0x78:
            if (data->unk2C != NULL) {
                data->unk2C(arg0->unk0, 0x78, data->unk30);
                data->unk2C = NULL;
            }
            func_800FFAB0(arg0);
            break;
        case 0x98:
            data->unk28 = 1;
            break;
        default:
            return 0;
    }
    return 1;
}

OSThread *chtorpedo_entrypoint_1(void)
{
    extern ActorData D_8080095C_chtorpedo[];

    return (OSThread *) D_8080095C_chtorpedo;
}
/* data_to_c.py: from asm/data/overlays/ch/torpedo.data.s */
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
OSThread *func_80108ED0(void);
void func_80107C2C();
s32 D_80800840_chtorpedo[29] BT_DATA(4, overlays_ch_torpedo, 0x0) = { 786467, 2818560, 41943085, 1310760, 2228244, 1966115, 3146778, 786477, 2818432, 33554477, 3276870, 2228257, 2490414, 3802650, 786487, 2818304, 25165869, 4587600, 2228264, 3473472, 4982554, 786492, 2949200, 5898283, 8388864, 2228285, 4194378, 5834778, 0 };
s32 D_808008B4_chtorpedo[16] BT_DATA(4, overlays_ch_torpedo, 0x74) = { 101711901, 165019669, 1638553, 3276802, 1445888, 1966110, 1966094, 3276860, 1638400, 34, 10027212, 25166336, 2752520, 524467, 11730959, 0 };
s32 D_808008F4_chtorpedo[9] BT_DATA(4, overlays_ch_torpedo, 0xB4) = { 2818150, 9175074, 786444, 1835036, 2949080, -2555944, 2621480, 2621722, 0 };
s32 D_80800918_chtorpedo[14] BT_DATA(4, overlays_ch_torpedo, 0xD8) = { 2228275, 6684928, 23461931, 7536755, 1572864, 1254912, 637534242, 2490419, 10027187, 2949080, -2555944, 2621480, 2621722, 0 };
u32 D_80800950_chtorpedo[3] BT_DATA(4, overlays_ch_torpedo, 0x110) = { 0xFF, 0xC0, 0x40 };
ActorData D_8080095C_chtorpedo [1] BT_DATA(4, overlays_ch_torpedo, 0x11C) = { { 634, 360, 1575, 1, 0, (void (*)(struct Actor *))func_808003DC_chtorpedo, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 4, (void (*)(struct Actor *))func_80800394_chtorpedo, (BtIntPtr)func_80108ED0, 52, 0, 0, (void (*)(void *, long, void *, long, void *))func_80107C2C, 0, 0, (void (*)(struct Actor *, long, long))func_80800720_chtorpedo, 0 } };
