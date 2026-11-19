#include "common.h"

/* extern */

typedef struct { u8 pad0[0x38]; f32 unk38; } Objboggy_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */ void func_80800000_chboggy(void *arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 func_800DA298(s32);
    void func_80101FDC(Actor *, u32);
    (((Objboggy_arg0 *)arg0)->unk38) = 0.18f;
    if ((func_800DA298(0x439) != 0) || (_glcutDll_entrypoint_20() != 0)) {
        func_80101FDC(arg0, 3);
    }
}

void func_80800054_chboggy(Actor *arg0, s32 arg1, s32 arg2) {
    u8 _subaddiedialog_entrypoint_9();
    void func_800DA544(s32 index);
    u32 func_800F54E4(void);
    void func_800F82D4(BtIntPtr, s32);
    void func_80101FDC(Actor *, u32);
    extern s32 D_80800790_chboggy[14];
    extern s32 D_808007C8_chboggy[14];
    s32 first;
    s32 second;

    first = _subaddiedialog_entrypoint_9(arg0, arg1, D_80800790_chboggy, 7);
    second = _subaddiedialog_entrypoint_9(arg0, arg1, D_808007C8_chboggy, 7);
    if (first == 1) {
        func_80101FDC(arg0, 1);
        func_800DA544(0x447);
        return;
    }
    if (second == 1) {
        func_800F82D4(func_800F54E4(), 0);
    }
}

s32 func_808000EC_chboggy(Actor *arg0, s32 arg1, s32 arg2) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    BtIntPtr func_800D10D4(u32, u32, f32 *, s32, BtIntPtr);
    void func_800DF3E0(void);
    void func_800DF744(s32, s32);
    s32 func_801015D0(Actor *);
    void func_80101FDC(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    f32 *_chbounce_entrypoint_9(Actor *);
    extern s32 D_80800820_chboggy[4];

    switch (arg1) {
        case 0x2E:
            func_80800054_chboggy(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
            break;
        case 0x1F:
            func_800DF3E0();
            func_801015D0(arg0);
            func_800DF744(3, arg0->unk70_10 == 1 ? 1 : 2);
            break;
        case 0x7D:
            func_80101FDC(arg0, 2);
            break;
        case 0x3D:
            if (arg2 == 0x22B) {
                _subaddieaudioquick_entrypoint_2(arg0, (f32 *)&arg0->actorData[4], D_80800820_chboggy);
                ((f32 *)arg0->actorData)[1] -= 60.0f;
                _chbounce_entrypoint_9(func_80106790((Unk80132ED0 *)func_800D10D4(0x40, 1, (f32 *)arg0->actorData, 0, 0)))[1] = 0.0f;
            }
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800220_chboggy(Actor *arg0) {
    s32 _sudeflect_entrypoint_0(f32 *arg0, f32 arg1, f32 arg2, s32 arg3);
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    s32 _subaddieaudioquick_entrypoint_4(Actor *arg0, f32 *arg1, void *arg2, f32 *arg3);
    s32 _subaddiedialog_entrypoint_8(BtIntPtr, void *, s32 *, s32 *, s32);
    void func_80800554_chboggy(BtIntPtr);
    s32 func_800DA298(s32);
    void func_800DA544(s32 index);
    s32 func_800902E4(f32 *, f32, s32, Actor **);
    u32 func_800F54E4(void);
    s32 func_800F640C(BtIntPtr, s32);
    s32 func_8008FE14(void);
    s32 func_80090818(void);
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(void) func_80090768(f32 *);
    void func_800D1824(s32);
    void func_800F8300();
    s32 func_80101E14(Actor *, f32);
    s32 func_800D0B68(u32, u32);
    s32 func_800D0A9C(u32, u32);
    void func_80108B04(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    extern u32 D_808006A0_chboggy[4]; extern u32 D_808006B0_chboggy[2]; extern u32 D_808006B8_chboggy[4];
    extern u32 D_808006C8_chboggy[4]; extern u32 D_808006D8_chboggy[4]; extern u32 D_808006E8_chboggy[4];
    extern u32 D_808006F8_chboggy[3]; extern u32 D_80800704_chboggy[3]; extern u32 D_80800710_chboggy[4];
    extern u32 D_80800720_chboggy[4]; extern u32 D_80800730_chboggy[4]; extern u32 D_80800740_chboggy[3];
    extern u32 D_8080074C_chboggy[5]; extern u32 D_80800760_chboggy[4];
    extern s32 D_80800790_chboggy[14]; extern s32 D_808007C8_chboggy[14];
    extern s32 D_80800800_chboggy[4]; extern s32 D_80800810_chboggy[4];

    _sudeflect_entrypoint_0(arg0->position, 175.0f, 175.0f, 14);
    func_80800554_chboggy((BtIntPtr)arg0);
    switch (arg0->unk70_10) {
        case 1:
            _subaddieaudioquick_entrypoint_3(arg0, (f32 *)&arg0->actorData[4], D_808006A0_chboggy, 0.1298f);
            _subaddieaudioquick_entrypoint_4(arg0, (f32 *)&arg0->actorData[4], D_80800704_chboggy, D_80800740_chboggy);
            _subaddieaudioquick_entrypoint_3(arg0, (f32 *)&arg0->actorData[4], D_80800710_chboggy, 0.42f);
            _subaddieaudioquick_entrypoint_3(arg0, (f32 *)&arg0->actorData[4], D_808006F8_chboggy, 0.58f);
            _subaddieaudioquick_entrypoint_4(arg0, (f32 *)&arg0->actorData[4], D_808006C8_chboggy, D_8080074C_chboggy);
            if (func_800DA298(0x447)) {
                func_800902E4(arg0->position, 400.0f, 0x4D7, &arg0);
                if ((func_800F640C(func_800F54E4(), 0x4D7) || func_8008FE14() == 0x4D7) && func_80090818()) {
                    func_80090768((f32 *)arg0->actorData);
                    func_800D1824(0x51);
                    func_800F8300(func_800F54E4(), 2, arg0->position);
                }
            }
            if (func_800DA298(0x439)) {
                func_800DA544(0x437);
            }
            _subaddiedialog_entrypoint_8((BtIntPtr)arg0, arg0->position, D_80800800_chboggy, D_80800790_chboggy, 7);
            break;
        case 2:
            _subaddieaudioquick_entrypoint_3(arg0, (f32 *)&arg0->actorData[4], D_808006B0_chboggy, 0.05f);
            _subaddieaudioquick_entrypoint_4(arg0, (f32 *)&arg0->actorData[4], D_808006E8_chboggy, D_80800760_chboggy);
            _subaddieaudioquick_entrypoint_4(arg0, (f32 *)&arg0->actorData[4], D_808006B8_chboggy, D_80800730_chboggy);
            if (func_80101E14(arg0, 0.6f) && !func_800D0B68(0x40, 1) && !func_800D0A9C(0x40, 1)) {
                func_80108B04(arg0, 0x22B);
            }
            if (func_80101E14(arg0, 0.99f)) {
                func_80101FDC(arg0, 3);
            }
            break;
        case 3:
            _subaddieaudioquick_entrypoint_3(arg0, (f32 *)&arg0->actorData[4], D_808006D8_chboggy, 0.22f);
            _subaddieaudioquick_entrypoint_4(arg0, (f32 *)&arg0->actorData[4], D_808006B8_chboggy, D_80800720_chboggy);
            _subaddiedialog_entrypoint_8((BtIntPtr)arg0, arg0->position, D_80800810_chboggy, D_808007C8_chboggy, 7);
            break;
    }
}

void func_80800504_chboggy(Actor *arg0, s32 arg1) {
    struct Flags { BT_BITFIELD_ORDER(u32 pad : 19, u32 rest : 12); u32 active : 1; BT_BITFIELD_ORDER(u32 rest : 12, u32 pad : 19); };
    void func_800DBEFC(s32 *, s32, BtIntPtr);
    void func_801018A4(Actor *, BtIntPtr);
    OSThread * func_80104130(void);
    func_801018A4(arg0, arg1);
    if (((struct Flags *)((s8 *)arg0 + 0x7C))->active) {
        func_800DBEFC((s32 *)func_80104130(), 4, (BtIntPtr)arg0 + 0x18);
    }
}

void func_80800554_chboggy(BtIntPtr arg0) {
    f32 _idglowa_entrypoint_1(BtIntPtr);
    BtIntPtr _idworld_entrypoint_0(s32);
    void func_800C36F4(u8, s32);
    void func_800C3A40(u8, f32, f32, f32);
    void func_800C3BDC(u8);
    u8 func_800C4350(u8 index, f32 *position, s32 *command_list);
    s32 func_800DA298(s32);
    void func_800DA524(s32 index);
    void func_800DA544(s32 index);
    extern s32 D_80800830_chboggy[4];
    s32 temp_f8;
    s32 sp24;
    u8 sp1F;
    BtIntPtr temp_v0;
    s32 var_v1;
    u8 temp_v0_2;

    temp_v0 = _idworld_entrypoint_0(0x35C);
    if (temp_v0 != 0) {
        temp_f8 = (s32) (_idglowa_entrypoint_1(temp_v0) * 32.0f);
        var_v1 = temp_f8;
        if (temp_f8 == 0x13) {
            sp24 = temp_f8;
            func_800DA544(0xA2E);
            var_v1 = sp24;
        }
        if ((var_v1 == 0x12) && (func_800DA298(0xA2E) != 0)) {
            temp_v0_2 = func_800C4350(0, 0, D_80800830_chboggy);
            sp1F = temp_v0_2;
            func_800C36F4(temp_v0_2, 1);
            func_800C3A40(sp1F, 1.0f, 1.4f, 1.0f);
            func_800C3BDC(sp1F);
            func_800DA524(0xA2E);
        }
    }
}

OSThread *chboggy_entrypoint_0(void)
{
    extern ActorData D_80800840_chboggy[];

    return (OSThread *) D_80800840_chboggy;
}

void func_80800634_chboggy(Actor *arg0) {
    arg0->rotation[0] = (f32)arg0->unk74_7;
    arg0->rotation[2] = arg0->scale * 100.0f;
    arg0->scale = 2.0f;
}

OSThread *chboggy_entrypoint_1(void)
{
    extern ActorData D_80800888_chboggy[];

    return (OSThread *) D_80800888_chboggy;
}
/* data_to_c.py: from asm/data/overlays/ch/boggy.data.s */
extern u8 D_80800770_chboggy[];
void func_80105834(Actor*);
void func_80107C2C();
void func_80102EC0();
void func_80101870(Actor* arg0, void* arg1);
u32 D_808006A0_chboggy[4] BT_DATA(4, overlays_ch_boggy, 0x0) = { 0x13049E, 0xA00CC, 0x163A98, 0 };
u32 D_808006B0_chboggy[2] BT_DATA(4, overlays_ch_boggy, 0x10) = { 0x1304A4, 0x180000 };
u32 D_808006B8_chboggy[4] BT_DATA(4, overlays_ch_boggy, 0x18) = { 0x130402, 0xD00CC, 0xE60016, 0x3A980000 };
u32 D_808006C8_chboggy[4] BT_DATA(4, overlays_ch_boggy, 0x28) = { 0x130402, 0xD00CC, 0xE60016, 0x23280000 };
u32 D_808006D8_chboggy[4] BT_DATA(4, overlays_ch_boggy, 0x38) = { 0x13049F, 0xD00CC, 0xE60016, 0x3A980000 };
u32 D_808006E8_chboggy[4] BT_DATA(4, overlays_ch_boggy, 0x48) = { 0x130430, 0xA00E6, 0x162710, 0 };
u32 D_808006F8_chboggy[3] BT_DATA(4, overlays_ch_boggy, 0x58) = { 0x130613, 0x163A98, 0 };
u32 D_80800704_chboggy[3] BT_DATA(4, overlays_ch_boggy, 0x64) = { 0x1305BB, 0x163A98, 0 };
u32 D_80800710_chboggy[4] BT_DATA(4, overlays_ch_boggy, 0x70) = { 0x130663, 0xA00CC, 0x162328, 0 };
u32 D_80800720_chboggy[4] BT_DATA(4, overlays_ch_boggy, 0x80) = { 0x3E4B0F28, 0x3E843FE6, 0x3EA2F838, 0xBF800000 };
u32 D_80800730_chboggy[4] BT_DATA(4, overlays_ch_boggy, 0x90) = { 0x3E40D1B7, 0x3E69C77A, 0x3E895E9E, 0xBF800000 };
u32 D_80800740_chboggy[3] BT_DATA(4, overlays_ch_boggy, 0xA0) = { 0x3E75C28F, 0x3EB33333, 0xBF800000 };
u32 D_8080074C_chboggy[5] BT_DATA(4, overlays_ch_boggy, 0xAC) = { 0x3F384B5E, 0x3F4A36E3, 0x3F59930C, 0x3F63D07D, 0xBF800000 };
u32 D_80800760_chboggy[4] BT_DATA(4, overlays_ch_boggy, 0xC0) = { 0x3EB33333, 0x3EF0A3D7, 0x3F07AE14, 0xBF800000 };
u8 D_80800770_chboggy[32] BT_DATA(4, overlays_ch_boggy, 0xD0) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0x10, 0x00, 0x00, 0x04, 0x41, 0x00, 0x01, 0x41, 0x10, 0x00, 0x00, 0x04, 0x42, 0x00, 0x02, 0x40, 0xAC, 0xCC, 0xCD, 0x04, 0x43, 0x00, 0x01 };
s32 D_80800790_chboggy[14] BT_DATA(4, overlays_ch_boggy, 0xF0) = { 1, 314507520, 1, 314573312, 512, 316408064, 512, 314573312, 1024, 316473600, 1024, 316539392, -73729, 302711552 };
s32 D_808007C8_chboggy[14] BT_DATA(4, overlays_ch_boggy, 0x128) = { 1, 314638592, 1, 314704384, 512, 314638592, 512, 314704384, 1024, 314638592, 1024, 314704384, -73729, 302711552 };
s32 D_80800800_chboggy[4] BT_DATA(4, overlays_ch_boggy, 0x160) = { 70713344, 26214471, 12, 56885248 };
s32 D_80800810_chboggy[4] BT_DATA(4, overlays_ch_boggy, 0x170) = { 70844416, 26214471, 12, 56885248 };
s32 D_80800820_chboggy[4] BT_DATA(4, overlays_ch_boggy, 0x180) = { 1246256, 655667, 1474492, 0 };
s32 D_80800830_chboggy[4] BT_DATA(4, overlays_ch_boggy, 0x190) = { 50724883, 107347991, 524297000, 983040 };
ActorData D_80800840_chboggy [1] BT_DATA(4, overlays_ch_boggy, 0x1A0) = { { 889, 1189, 2289, 1, (void *)D_80800770_chboggy, (void (*)(struct Actor *))func_80800220_chboggy, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80800504_chboggy, 0, 0, 0, 0, 0, 1290, 0, 0, 20, 0, (void (*)(struct Actor *))func_80800000_chboggy, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 13318, (void (*)(struct Actor *, long, long))func_808000EC_chboggy, 0 } };
ActorData D_80800888_chboggy [1] BT_DATA(4, overlays_ch_boggy, 0x1E8) = { { 344, 1328, 1518, 1, 0, (void (*)(struct Actor *))func_80102EC0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 2, 2048, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800634_chboggy, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 11266, 0, 0 } };
