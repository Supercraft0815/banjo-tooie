#include "common.h"

f32 func_80800000_chfantasyonion(Actor *arg0) {
    void *func_800BEF00(f32 *a,f32 *b,f32 *out,u32 flags);
    u8 func_800E8714(s32);
    void func_800E8830(u8, f32[3]);
    void func_800E8870(u8, f32);
    void func_800EE7F8(f32 *, f32 *);
    f32 sp34[3];
    f32 sp28[3];
    f32 sp1C[3];

    func_800EE7F8(sp28, arg0->position);
    func_800EE7F8(sp34, arg0->position);
    sp34[1] += 250.0f;
    sp28[1] -= 1400.0f;
    func_800BEF00(sp34, sp28, sp1C, 0);
    if (arg0->actorData[0] == 0) {
        arg0->actorData[0] = func_800E8714(1);
        func_800E8870(arg0->actorData[0], 300.0f);
    }
    func_800E8830(arg0->actorData[0], sp28);
    return sp28[1];
}

void func_808000BC_chfantasyonion(Actor *arg0) {
    s32 _glsplinefind_entrypoint_3(f32 *);
    void func_800C7A68(void *arg0, f32 arg1, f32 *arg2);
    BtIntPtr func_800D7520(s32);
    void func_800D8648(s32, f32 *);
    f32 func_800DC0C0(void);
    int func_800EEDE8(f32 *, f32 *, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F13C4(f32, f32);
    void func_80101EE4(Actor *, f32);
    void func_80101FDC(Actor *, u32);
    void func_80105634(Actor *);
    int func_8010568C(Actor *, s32);
    typedef struct {
        u8 actorPrefix[0x74];
        BT_BITFIELD_ORDER(u32 upperFlags : 27, u32 lowerFlags : 4);
        u32 unk74_4 : 1;
        BT_BITFIELD_ORDER(u32 lowerFlags : 4, u32 upperFlags : 27);
    } OnionFlags;
    f32 sp44[3];
    f32 sp38[3];

    if (func_8010568C(arg0, 0)) {
        func_80105634(arg0);
        ((OnionFlags *)arg0)->unk74_4 = 0;
        if (arg0->rotation[1] > 99.0f) {
            arg0->unk64_20 = 1;
        } else {
            arg0->unk64_20 = 0;
        }
        ((f32 *)arg0->actorData)[3] = func_800F10B4(
            func_800F13C4(arg0->rotation[1], 100.0f), 0.0f, 99.0f,
            0.0f, (f32)((s32)arg0->unk74_7 / 10));
        ((f32 *)arg0->actorData)[7] = (f32)_glsplinefind_entrypoint_3(arg0->position);
        func_800C7A68(func_800D7520((s32)((f32 *)arg0->actorData)[7]), 0.0f, sp44);
        func_800C7A68(func_800D7520((s32)((f32 *)arg0->actorData)[7]), 1.0f, sp38);
        if (func_800EEDE8(sp44, sp38, 200.0f)) {
            arg0->unk64_19 = 1;
            func_800D8648((s32)((f32 *)arg0->actorData)[7], sp38);
        } else {
            arg0->unk64_19 = 0;
        }
        func_80101FDC(arg0, 2);
    }
    ((f32 *)arg0->actorData)[4] = func_80800000_chfantasyonion(arg0);
    func_80101EE4(arg0, func_800DC0C0());
}                typedef struct { s32 unk0; u8 pad4[0x4]; f32 unk8; u8 padC[0xC]; s32 unk18; u8 pad1C[0x8]; f32 unk24; f32 unk28; f32 unk2C; f32 unk30; f32 unk34; u8 pad38[0x10]; f32 unk48; } Objonion_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void func_80800254_chfantasyonion(u8 *arg0) {
    s32 _plsu_entrypoint_3(BtIntPtr);
    f32 func_80013970(f32);
    s32 func_80015178(u32);
    s32 func_80015184();
    void func_800C7A68(void *arg0, f32 arg1, f32 *arg2);
    BtIntPtr func_800D7520(s32);
    s32 func_800D90A4(u8 *);
    void func_800EE7F8(f32 *, f32 *);
    s32 func_800EF04C(f32 *, f32 *);
    s32 func_800EF3DC(f32 *, u8 *);
    s32 func_800EF934(f32 *, f32 *, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F1DF4(f32 *, f32 *);
    BtIntPtr func_800F54E4();
    s32 func_800F5A00(BtIntPtr, f32 *);
    s32 func_800F5B38(BtIntPtr, f32 *);
    s32 func_800F5C94(BtIntPtr);
    s32 func_800F79DC(BtIntPtr, s32, BtIntPtr);
    s32 func_800F832C(BtIntPtr, f32 *);
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(void) func_800F8418(BtIntPtr, f32 *);
    s32 func_80102BAC(u8 *, s32, s32, s32);
    f32 func_80800000_chfantasyonion(Actor *);
    typedef struct {
        u8 pad[0x64];
        BT_BITFIELD_ORDER(u32 : 11, u32  : 19);
        BT_BITFIELD_ORDER(u32 direction : 1, u32 locked : 1);
        BT_BITFIELD_ORDER(u32 locked : 1, u32 direction : 1);
        BT_BITFIELD_ORDER(u32 : 19, u32  : 11);
        u8 pad68[8];
        BT_BITFIELD_ORDER(u32 : 16, u32  : 10);
        u32 state : 6;
        BT_BITFIELD_ORDER(u32 : 10, u32  : 16);
        BT_BITFIELD_ORDER(u32 : 16, char : 0);
        BT_BITFIELD_ORDER(u32 duration : 9, u32  : 7);
        BT_BITFIELD_ORDER(u32 : 7, u32 duration : 9);
        BT_BITFIELD_ORDER(u32 : 8, u32  : 16);
        BT_BITFIELD_ORDER(u32 saved : 4, char : 0);
        BT_BITFIELD_ORDER(u32 : 20, u32  : 20; u32 saved : 4; u32  : 8);
    } OnionBits;
    s32 sp6C;
    f32 sp60[3];
    f32 sp5C;
    f32 sp58;
    f32 sp4C[3];
    u32 sp48;
    f32 sp44;
    f32 sp38[3];
    f32 temp_f0;

    sp6C = _plsu_entrypoint_3((((Objonion_arg0 *)arg0)->unk0));
    if (sp6C != -1) {
        if ((-1.0f == (((Objonion_arg0 *)arg0)->unk2C)) && (0.0f == (((Objonion_arg0 *)arg0)->unk30))) {
            ((OnionBits *)arg0)->saved = func_80015184();
            func_80015178(4U);
            (((Objonion_arg0 *)arg0)->unk30) = 3.0f;
        }
        if (func_800F5C94(sp6C) != 0xC) {
            func_800F79DC(sp6C, 4, (((Objonion_arg0 *)arg0)->unk0));
            sp6C = -1;
        }
        if (sp6C != -1) {
            func_800F5A00(func_800F54E4(), sp60);
            func_800EF3DC(sp60, arg0 + 4);
            sp5C = (((Objonion_arg0 *)arg0)->unk48);
        }
    } else if (-1.0f != (((Objonion_arg0 *)arg0)->unk2C)) {
        func_80015178(((OnionBits *)arg0)->saved);
    }
    switch (((OnionBits *)arg0)->state) {
    case 1:
        break;
    case 2:
        sp48 = ((OnionBits *)arg0)->direction;
        func_800EE7F8(sp4C, (f32 *)(arg0 + 4));
        if (func_800D90A4(arg0 + 0x24) != 0) {
            if (!((OnionBits *)arg0)->locked) {
                ((OnionBits *)arg0)->direction = !((OnionBits *)arg0)->direction;
            }
            (((Objonion_arg0 *)arg0)->unk24) = (f32) ((s32)((OnionBits *)arg0)->duration / 10);
        }
        temp_f0 = (f32) ((s32)((OnionBits *)arg0)->duration / 10);
        if (((OnionBits *)arg0)->direction) {
            sp58 = func_800F10B4((((Objonion_arg0 *)arg0)->unk24), 0.0f, temp_f0, 0.0f, 1.0f);
        } else {
            sp58 = func_800F10B4((((Objonion_arg0 *)arg0)->unk24), 0.0f, temp_f0, 1.0f, 0.0f);
        }
        func_800C7A68(func_800D7520((s32) (((Objonion_arg0 *)arg0)->unk34)), sp58, (f32 *)(arg0 + 4));
        if (sp48 != 0) {
            (*(f32 *)(arg0 + 0x54)) = func_800F1DF4(sp4C, (f32 *)(arg0 + 4));
        } else {
            (*(f32 *)(arg0 + 0x54)) = func_800F1DF4((f32 *)(arg0 + 4), sp4C);
        }
        func_80102BAC(arg0, 0x3D4CCCCD, 0x3C23D70A, 0x40800000);
        break;
    }
    if (func_800D90A4(arg0 + 0x30) == 0) {
        sp44 = func_800F10B4((((Objonion_arg0 *)arg0)->unk30), 3.0f, 0.0f, 1.0f, 0.0f);
        temp_f0 = func_80013970(sp44 * 2160.0f);
        (((Objonion_arg0 *)arg0)->unk8) += temp_f0 * (20.0f * sp44);
    }
    if (sp6C != -1) {
        sp5C -= (((Objonion_arg0 *)arg0)->unk48);
        func_800F5B38(func_800F54E4(), sp38);
        sp38[1] -= sp5C;
        func_800F832C(func_800F54E4(), sp38);
        func_800EF934(sp60, sp60, -sp5C);
        func_800EF04C(sp60, (f32 *)(arg0 + 4));
        func_800F8418(func_800F54E4(), sp60);
    }
    (((Objonion_arg0 *)arg0)->unk2C) = (f32) sp6C;
    (((Objonion_arg0 *)arg0)->unk28) = func_80800000_chfantasyonion(arg0);
}

void func_80800624_chfantasyonion(Actor *arg0, void *arg1) {
    BtIntPtr func_800D674C(s32);
    void *func_800DE498(void *, f32 *, f32 *, f32, f32 *, BtIntPtr);
    void func_800DF830(s32);
    s32 func_800E88E4(u8);
    void func_800EFA4C(f32 *, f32, f32, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_80101870(Actor* arg0, void* arg1);
    extern f32 D_80800748_chfantasyonion[3];
    f32 sp34[3];
    f32 sp30;

    if (func_800E88E4(((u8 *)arg0->actorData)[3]) != 0) {
        sp30 = ((f32 *)arg0->actorData)[4];
        func_800EFA4C(sp34, arg0->position[0], sp30, arg0->position[2]);
        func_800DF830(0);
        func_800DE498(arg1, sp34, D_80800748_chfantasyonion,
            func_800F10B4(arg0->position[1] - sp30, 1400.0f, 0.0f, 0.25f, 1.0f),
            NULL, func_800D674C(0x637));
    }
    func_80101870(arg0, arg1);
}

/* extern */

void func_808006E0_chfantasyonion(void *arg0) {
    BT_IDO_ONLY(s32 func_800E87E0(s32, void *);) BT_NATIVE_ONLY(void func_800E87E0(u8);)
    s32 temp_v0;

    temp_v0 = (((Objonion_arg0 *)arg0)->unk18);
    if (temp_v0 != 0) {
        BT_IDO_ONLY(func_800E87E0(temp_v0 & 0xFF, arg0);) BT_NATIVE_ONLY(func_800E87E0((u8)temp_v0);)
        (((Objonion_arg0 *)arg0)->unk18) = 0;
    }
}

OSThread *chfantasyonion_entrypoint_0(void)
{
    extern ActorData D_80800754_chfantasyonion[];

    return (OSThread *) D_80800754_chfantasyonion;
}
/* data_to_c.py: from asm/data/overlays/ch/fantasy/onion.data.s */
extern u8 D_80800730_chfantasyonion[];
void func_80105834(Actor*);
OSThread *func_80108ED0(void);
void func_80107C2C();
u8 D_80800730_chfantasyonion[24] BT_DATA(4, overlays_ch_fantasy_onion, 0x0) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xA6, 0x66, 0x66, 0x04, 0x0A, 0x00, 0x01, 0x3F, 0xA6, 0x66, 0x66, 0x04, 0x0A, 0x00, 0x01 };
f32 D_80800748_chfantasyonion [ 3 ] BT_DATA(4, overlays_ch_fantasy_onion, 0x18) = { 0.0f, 0.0f, 0.0f };
ActorData D_80800754_chfantasyonion [1] BT_DATA(4, overlays_ch_fantasy_onion, 0x24) = { { 344, 1151, 2207, 1, (void *)D_80800730_chfantasyonion, (void (*)(struct Actor *))func_80800254_chfantasyonion, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80800624_chfantasyonion, 0, 0, 0, 0, 128, 2080, (void (*)(struct Actor *))func_808006E0_chfantasyonion, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_808000BC_chfantasyonion, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32736, 17410, 0, 0 } };
