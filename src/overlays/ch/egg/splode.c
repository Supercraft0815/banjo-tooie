#include "common.h"

OSThread *cheggsplode_entrypoint_0(void)
{
    extern ActorData D_80800994_cheggsplode[];

    return (OSThread *) D_80800994_cheggsplode;
}

void func_8080000C_cheggsplode(Actor *volatile arg0, s32 arg1) {
    s32 _gcegg_entrypoint_7(s32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    void func_800C8E54(s32, f32, f32);
    void func_800CB840(s32, BtIntPtr);
    void func_800CB870(void);
    s32 func_800D3948(void);
    f32 func_800D8FF8(void);
    s32 func_800F6BE4(BtIntPtr);
    int func_800F7A7C(BtIntPtr, s32, s32, s32, f32 *);
    void *func_80100094(Actor *, u32);
    void func_80109C4C(BtIntPtr, f32, s32, BtIntPtr, s32, BtIntPtr, s32);
    s32 func_8010CC10(f32 *, f32);
    void func_8010CCE0(void);
    s32 func_8010CCEC(void);
    void func_80800778_cheggsplode(Actor *, BtIntPtr);
    s32 func_808007D4_cheggsplode(BtIntPtr, s32);
    extern s32 D_80800820_cheggsplode[];
    extern s32 D_80800868_cheggsplode[];
    extern s32 D_808008E0_cheggsplode[];
    f32 radius;
    f32 previous;
    f32 progress;
    struct EggSplodeData {
    s32 unk0;
    s16 unk4;
    s16 unk6;
    f32 unk8;
    f32 unkC;
    s32 unk10;
    }
    *data;
    s32 id;
    s32 egg;
    s32 owner;
    Actor **actor = (Actor **)&arg0;
    data = func_80100094((*actor), 0);
    previous = data->unk8;
    data->unk8 += func_800D8FF8();
    progress = data->unk8 * 2.2222223f;
    if (data->unk8 > 0.12f && previous < 0.12f) {
    func_800BABB8(0, (*actor)->position, NULL, 1.0f, D_80800820_cheggsplode);
    func_800BABB8(0, (*actor)->position, NULL, 1.0f, D_80800868_cheggsplode);
    if (func_800D3948() == 0) {
    func_800BABB8(0, (*actor)->position, NULL, 1.0f, D_808008E0_cheggsplode);
    }
    }
    if (progress > 1.0f) {
    progress = 1.0f;
    (*actor)->unk70_10 = 5;
    }
    radius = (data->unkC - 50.0f) * progress + 50.0f;
    if (data->unk6 == 0 && func_800F6BE4(data->unk0) != 0 && func_8010CC10((*actor)->position, radius) != 0) {
    owner = data->unk0;
    egg = _gcegg_entrypoint_7(data->unk4);
    func_8010CCE0();
    id = func_8010CCEC();
    while (id != -1) {
    if (func_808007D4_cheggsplode((BtIntPtr)(*actor), id) != 0) {
    func_800F7A7C(id, owner, egg, 5, (*actor)->position);
    func_80800778_cheggsplode((*actor), id);
    }
    id = func_8010CCEC();
    }
    }
    if (data->unk6 == 0) {
    func_800CB840(7, (BtIntPtr)(*actor));
    func_80109C4C((BtIntPtr)(*actor)->position, radius, 2, 0, 0, (BtIntPtr)(*actor)->unk0, arg1);
    func_800CB870();
    }
    if (data->unk10 != 0) {
    func_800C8E54(data->unk10, 1.5f * radius, 3.5f * radius);
    }
    }

s32 func_808002A8_cheggsplode(Actor *arg0, s32 arg1, s32 arg2) {
    s8 func_800BF8E4(void);
    s32 func_800C8A98(void);
    void func_800C8CB8(s32, f32 *);
    void func_800C8E84(s32, u32 *);
    s32 func_800D3948(void);
    void *func_80100094(Actor *, u32);
    extern u32 D_808009DC_cheggsplode[3];
    struct EggSplodeData {
        s32 unk0;
        s16 unk4;
        s16 unk6;
        f32 unk8;
        f32 unkC;
        s32 unk10;
    } *sp1C;
    s32 temp_v0;
    s32 var_v0;

    sp1C = func_80100094(arg0, 0);
    switch (arg1) {
        case 0x9F:
            if (func_800D3948() == 0) {
                sp1C->unk6 = 1;
            }
            return 1;
        case 0x95:
            if (func_800BF8E4() > 0) {
                temp_v0 = func_800C8A98();
                sp1C->unk10 = temp_v0;
                func_800C8E84(temp_v0, D_808009DC_cheggsplode);
                func_800C8CB8(sp1C->unk10, arg0->position);
            }
            return 1;
        default:
            return 0;
    }
}

void func_8080035C_cheggsplode(Actor *arg0) {
    s32 _chlightfader_entrypoint_1(s32, f32, s32);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    struct EggSplodeData {
        s32 unk0;
        s16 unk4;
        s16 unk6;
        f32 unk8;
        f32 unkC;
        s32 unk10;
    } *data;

    data = func_80100094(arg0, 0);
    switch (arg0->unk70_10) {
        case 2:
        case 3:
            func_8080000C_cheggsplode(arg0, 0x26F);
            return;
        case 4:
            func_8080000C_cheggsplode(arg0, 0x270);
            return;
        case 5:
            if (data->unk10 != 0) {
                data->unk10 = _chlightfader_entrypoint_1(data->unk10, 1.0f, 2);
            }
            func_800FFAB0(arg0);
            return;
    }
}

void func_8080041C_cheggsplode(Actor *arg0) {
    void func_800187B4(s32, f32, f32, f32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    s32 func_800E1610(s32, f32, f32, f32 *);
    BtUIntPtr func_800F54E4(void);
    s32 func_800F54F0(BtIntPtr);
    s32 func_800F6BE4(BtIntPtr);
    void *func_80100094(Actor *, u32);
    s32 func_8010D930(s32, s32, f32 *, s32 *);
    void func_808006F0_cheggsplode(Actor *);
    void func_80800778_cheggsplode(Actor *, BtIntPtr);
    extern s32 D_808008B0_cheggsplode[12];
    extern s32 D_80800980_cheggsplode[5];
    struct EggSplodeData {
        s32 unk0;
        s16 unk4;
        s16 unk6;
        f32 unk8;
        f32 unkC;
        s32 unk10;
    } *sp34;
    BtIntPtr var_s1;

    sp34 = func_80100094(arg0, 0);
    var_s1 = sp34->unk0;
    if (func_800F6BE4(var_s1) == 0) {
        var_s1 = func_800F54E4();
    }
    sp34->unk8 = 0.0f;
    func_800E1610(0, 20.0f, 0.6f, arg0->position);
    func_800187B4(func_800F54F0(var_s1), 0.85f, 0.45f, 0.6f);
    arg0->position[1] += 60.0f;
    func_800BABB8(0, arg0->position, NULL, 1.0f, D_808008B0_cheggsplode);
    if (sp34->unk4 != 5) {
        func_808006F0_cheggsplode(arg0);
    }
    func_8010D930(6, -1, arg0->position, D_80800980_cheggsplode);
    sp34->unk10 = 0;
    if (func_800F6BE4(var_s1) != 0) {
        func_80800778_cheggsplode(arg0, var_s1);
    }
}

/* extern */

f32 func_80800548_cheggsplode(s32 arg0) {
    s32 func_800F693C(BtIntPtr);
    s32 func_800F6BE4(BtIntPtr);
    if (func_800F6BE4(arg0) != 0) {
        return func_800F693C(arg0) != 0 ? 250.0f : 190.0f;
    }
    return 190.0f;
}

void cheggsplode_entrypoint_1(Actor **arg0, s32 arg1, s32 arg2) {
    Actor *func_801084B0(BtIntPtr, Actor **);
    void *func_80100094(Actor *, u32);
    Actor *actor;
    struct EggSplodeData {
        s32 unk0;
        s16 unk4;
        s16 unk6;
        f32 unk8;
        f32 unkC;
    } *data;

    actor = func_801084B0(0x2B2, arg0);
    data = func_80100094(actor, 0);
    data->unk6 = 0;
    data->unk4 = arg2;
    data->unk0 = arg1;
    if (arg2 != 4) {
        if (arg2 == 6) {
            actor->unk70_10 = 3;
            data->unkC = 350.0f;
        }
    } else {
        actor->unk70_10 = 2;
        data->unkC = func_80800548_cheggsplode(arg1);
    }
}

void cheggsplode_entrypoint_2(f32 *arg0, f32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Actor *func_80108474(u32, f32 *, s32);
    void *func_80100094(Actor *, u32);
    Actor *actor;
    struct EggSplodeData {
        s32 unk0;
        s16 unk4;
        s16 unk6;
        f32 unk8;
        f32 unkC;
    } *data;

    actor = func_80108474(0x2B2, arg0, (s32)arg1);
    data = func_80100094(actor, 0);
    data->unk0 = arg2;
    data->unk4 = arg3;
    data->unk6 = arg4 == 0;
    if (arg3 == 5) {
        actor->unk70_10 = 4;
        data->unkC = func_80800548_cheggsplode(arg2);
    }
}

void func_808006F0_cheggsplode(Actor *arg0) {
    BtIntPtr func_800B53A4(s32);
    void func_800BA22C(BtIntPtr, s32);
    void func_800BA670(BtIntPtr, s32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    extern s32 D_808009E8_cheggsplode[18];
    u16 var_v0;
    BtIntPtr temp_a0;

    temp_a0 = func_800B53A4(6);
    var_v0 = arg0->unk70_10 == 3 ? 0x875 : 0x9B1;
    func_800BA670(temp_a0, var_v0);
    func_800BABB8(temp_a0, arg0->position, arg0->position, 0.25f, D_808009E8_cheggsplode);
    func_800BA22C(temp_a0, 6);
}

/* extern */

void func_80800778_cheggsplode(Actor *arg0, BtIntPtr arg1) {
    s32 func_800D3948();
    s32 func_800F6BE4(BtIntPtr);
    s32 func_800F6CC8(BtIntPtr);
    void *func_80100094(Actor *, u32);
    if ((func_800D3948() == 0) && (func_800F6BE4(arg1) != 0) && (func_800F6CC8(arg1) != 0)) {
        (*(s16 *)((s8 *)(func_80100094(arg0, 0)) + (6))) = 1;
    }
}

/* extern */

s32 func_808007D4_cheggsplode(BtIntPtr arg0, s32 arg1) {
    s32 func_800F6478(BtIntPtr);
    if (func_800F6478(arg1) == 0) {
        return 0;
    }
    return 1;
}
/* data_to_c.py: from asm/data/overlays/ch/egg/splode.data.s */
void func_80105834(Actor*);
void func_8010A730();
void func_80107C2C();
s32 D_80800820_cheggsplode [18] BT_DATA(4, overlays_ch_egg_splode, 0x0) = { 118489117, 165019669, 131225, 1445888, 1966130, 3276814, 7209080, 2490368, 65436, 0, 6553625, 65537, 2228377, 13369753, 33554474, 655370, 8388748, 983040 };
s32 D_80800868_cheggsplode [18] BT_DATA(4, overlays_ch_egg_splode, 0x48) = { 84934685, 165019669, 131225, 1445888, 1966130, 3276814, 1966140, 2490368, 65436, 0, 6553625, 0, 2228377, 13369856, 46923818, 524296, 6684774, 983040 };
s32 D_808008B0_cheggsplode[12] BT_DATA(4, overlays_ch_egg_splode, 0x90) = { 17825821, 165019669, 131276, 1445888, 1966130, 3276825, 0, 2228428, 13370240, 58720299, 5832793, 18481152 };
s32 D_808008E0_cheggsplode [40] BT_DATA(4, overlays_ch_egg_splode, 0xC0) = { 68157469, 165412908, -2621390, -2621400, 6553640, 1376276, 6684704, -559451794, 2228480, 25166336, 50331670, 268435480, 3, 0, 2818764, 63701025, 0, 10, -6553560, 65436, 2621440, 18481185, 0, 5898250, 6553640, 100, 2621440, 18481185, 0, 11796490, 40, -6553600, 2686876, 18481185, 0, 17694730, 40, 6553600, 2621540, 18481152 };
s32 D_80800980_cheggsplode[5] BT_DATA(4, overlays_ch_egg_splode, 0x160) = { 1246227, 1572877, 15925516, 66536, 327680000 };
ActorData D_80800994_cheggsplode [1] BT_DATA(4, overlays_ch_egg_splode, 0x174) = { { 362, 690, 0, 1, 0, (void (*)(struct Actor *))func_8080035C_cheggsplode, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_8010A730, 0, 0, 0, 0, 0, 0, 0, 0, 20, 0, (void (*)(struct Actor *))func_8080041C_cheggsplode, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1538, (void (*)(struct Actor *, long, long))func_808002A8_cheggsplode, 0 } };
u32 D_808009DC_cheggsplode[3] BT_DATA(4, overlays_ch_egg_splode, 0x1BC) = { 0xFF, 0xC0, 0x40 };
s32 D_808009E8_cheggsplode[18] BT_DATA(4, overlays_ch_egg_splode, 0x1C8) = { 18022422, 335544341, 204, 262348, 458753, 2818201, 13369378, 16777472, 6684825, 917514, 1310765, 78644600, 1834008, -78643161, 13107400, 26214800, 0, 0 };
