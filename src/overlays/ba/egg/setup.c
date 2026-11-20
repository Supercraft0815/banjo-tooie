#include "core2/1ECD170.h"
typedef struct player_state_s PlayerState; 

s32 baeggsetup_entrypoint_0() 
{
    return 0x28;
}

/* extern */

s32 func_80800008_baeggsetup(void *arg0) {
    s32 func_8009E674(void *, s32);
    s32 result;
    result = func_8009E674(arg0, 2);
    return result == 0;
} typedef struct { u8 pad0[0x70]; union { f32 * unk70; u8 * unk70_u8p; }; } Objsetup_baeggsetup_entrypoint_1_self; /* offsets.py genstruct: fields from raw offsets on self; rename once understood */

void baeggsetup_entrypoint_1(s32 arg0) {
    void func_800EE7F8(f32 *, f32 *);
    u8 *func_800F53D0(BtIntPtr);
    void _bababykaz_entrypoint_13(u8 *);
    void _cheggnormal_entrypoint_1(f32 *, f32 *, f32 *, s32);
    void _cheggfire_entrypoint_1(f32 *, f32 *, f32 *, s32);
    void _cheggice_entrypoint_1(f32 *, f32 *, f32 *, s32);
    void _chegggrenade_entrypoint_2(f32 *, f32 *, f32 *, s32);
    Actor *_cheggclockwork_entrypoint_1(f32 *, f32 *, f32 *, s32, s32);
    void _chegggolden_entrypoint_1(f32 *, f32 *, f32 *, s32);
    f32 sp54[3];
    f32 sp48[3];
    f32 sp3C[3];
    u8 *self;

    self = func_800F53D0(arg0);
    func_800EE7F8(sp54, ((Objsetup_baeggsetup_entrypoint_1_self *)self)->unk70);
    func_800EE7F8(sp3C, ((Objsetup_baeggsetup_entrypoint_1_self *)self)->unk70 + 3);
    func_800EE7F8(sp48, ((Objsetup_baeggsetup_entrypoint_1_self *)self)->unk70 + 6);
    switch ((((Objsetup_baeggsetup_entrypoint_1_self *)self)->unk70_u8p)[0x24]) {
    case 1:
        _cheggnormal_entrypoint_1(sp54, sp3C, sp48, arg0);
        return;
    case 2:
        _cheggfire_entrypoint_1(sp54, sp3C, sp48, arg0);
        return;
    case 3:
        _cheggice_entrypoint_1(sp54, sp3C, sp48, arg0);
        return;
    case 4:
        _chegggrenade_entrypoint_2(sp54, sp3C, sp48, arg0);
        return;
    case 5:
        _bababykaz_entrypoint_13(self);
        _cheggclockwork_entrypoint_1(sp54, sp3C, sp48, arg0, func_80800008_baeggsetup(self));
        return;
    case 7:
        _chegggolden_entrypoint_1(sp54, sp3C, sp48, arg0);
    }
}

void baeggsetup_entrypoint_2(PlayerState *arg0, s32 arg1, f32 arg2, f32 arg3) {
    s32 _chbaddiesetup_entrypoint_1(s32 *, BtIntPtr);
    f32 func_800136E4(f32);
    void func_80094C0C(PlayerState *, s32);
    void func_8009C128(PlayerState *, f32[3]);
    f32 func_800DC0C0(void);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EEB9C(f32[3], f32, f32);
    void func_800EF04C(f32 *, f32 *);
    BT_IDO_ONLY(void func_800F3E84();)
#ifndef BT_NATIVE
    extern s32 _baeggsetup_entrypoint_1;
#endif
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];
    f32 sp28[3];
    f32 temp_f0;
    f32 temp_f2;

    func_80094C0C(arg0, arg1);
    func_8009C128(arg0, sp28);
    sp28[1] += arg2;
    func_800EE7F8(sp4C, sp28);
    func_800F3E84(arg0, sp40);
    temp_f2 = sp40[1];
    sp40[1] = func_800136E4(temp_f2 + 180.0f);
    func_800EEB9C(sp34, sp40[1], arg3);
    func_800EF04C(sp28, sp34);
    temp_f0 = func_800DC0C0();
    temp_f2 = sp40[1];
    temp_f2 += (temp_f0 * 6.0f) - 3.0f;
    sp40[1] = temp_f2;
    func_800EEB9C(sp34, temp_f2, 200.0f);
    sp34[1] = (func_800DC0C0() * 20.0f) + 700.0f;
    func_800EE7F8(*(f32 **)((u8 *)arg0 + 0x70), sp4C);
    func_800EE7F8(*(f32 **)((u8 *)arg0 + 0x70) + 3, sp28);
    func_800EE7F8(*(f32 **)((u8 *)arg0 + 0x70) + 6, sp34);
    (*(u8 **)((u8 *)arg0 + 0x70))[0x24] = arg1;
    _chbaddiesetup_entrypoint_1(&_baeggsetup_entrypoint_1, *(s32 *)((u8 *)arg0 + 0x184));
}

s32 baeggsetup_entrypoint_3(s32 arg0, s32 arg1, u8 *arg2, u8 *arg3, u8 *arg4) {
    u8 *func_800F53D0(BtIntPtr);
    void _bababykaz_entrypoint_13(u8 *);
    Actor *_cheggclockwork_entrypoint_1(f32 *, f32 *, f32 *, s32, s32);
    s32 _cheggfire_entrypoint_2(u8 *, u8 *, u8 *, s32);
    s32 _chegggolden_entrypoint_2(u8 *, u8 *, u8 *, s32);
    s32 _chegggrenade_entrypoint_3(u8 *, u8 *, u8 *, s32);
    s32 _cheggice_entrypoint_2(u8 *, u8 *, u8 *, s32);
    s32 _cheggnormal_entrypoint_2(u8 *, u8 *, u8 *, s32);
    s32 _cheggproximity_entrypoint_1(u8 *, u8 *, u8 *, s32);
    u8 *player;

    player = func_800F53D0(arg0);
    switch (arg1) {
    case 1:
        _cheggnormal_entrypoint_2(arg2, arg3, arg4, arg0);
        BT_NATIVE_ONLY(return 0;) return;
    case 2:
        _cheggfire_entrypoint_2(arg2, arg3, arg4, arg0);
        BT_NATIVE_ONLY(return 0;) return;
    case 3:
        _cheggice_entrypoint_2(arg2, arg3, arg4, arg0);
        BT_NATIVE_ONLY(return 0;) return;
    case 4:
        _chegggrenade_entrypoint_3(arg2, arg3, arg4, arg0);
        BT_NATIVE_ONLY(return 0;) return;
    case 5:
        _bababykaz_entrypoint_13(player);
        _cheggclockwork_entrypoint_1(arg2, arg3, arg4, arg0, func_80800008_baeggsetup(player));
        BT_NATIVE_ONLY(return 0;) return;
    case 7:
        _chegggolden_entrypoint_2(arg2, arg3, arg4, arg0);
        BT_NATIVE_ONLY(return 0;) return;
    case 6:
        _cheggproximity_entrypoint_1(arg2, arg3, arg4, arg0);
    default:
        BT_NATIVE_ONLY(return 0;) return;
    }
}    typedef struct { u8 pad0[0x24]; u8 unk24; } Objsetup_baeggsetup_entrypoint_4_temp_a2; /* offsets.py genstruct: fields from raw offsets on temp_a2; rename once understood */

/* extern */

void baeggsetup_entrypoint_4(s32 arg0) {
    s32 baeggsetup_entrypoint_3(s32, s32, u8 *, u8 *, u8 *);
    u8 *func_800F53D0();
    u8 *temp_a2;

    temp_a2 = (*(u8 **)((s8 *)(func_800F53D0()) + (0x70)));
    baeggsetup_entrypoint_3(arg0, (((Objsetup_baeggsetup_entrypoint_4_temp_a2 *)temp_a2)->unk24), temp_a2, temp_a2 + 0xC, temp_a2 + 0x18);
}

void baeggsetup_entrypoint_5(PlayerState *arg0, s32 arg1, f32 arg2, f32 arg3) {
    s32 _chbaddiesetup_entrypoint_1(s32 *, BtIntPtr);
    void func_80094C0C(PlayerState *, s32);
    void func_8009C128(PlayerState *, f32[3]);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EEB9C(f32[3], f32, f32);
    void func_800EF04C(f32 *, f32 *);
    BT_IDO_ONLY(void func_800F3E84();)
#ifndef BT_NATIVE
    extern s32 _baeggsetup_entrypoint_4;
#endif
    f32 sp44[3];
    f32 sp38[3];
    f32 sp2C[3];
    f32 sp20[3];

    func_80094C0C(arg0, arg1);
    func_8009C128(arg0, sp20);
    sp20[1] += arg2;
    func_800EE7F8(sp44, sp20);
    func_800F3E84(arg0, sp38);
    func_800EEB9C(sp2C, sp38[1] * 1.0f, arg3);
    func_800EF04C(sp20, sp2C);
    func_800EEB9C(sp2C, sp38[1] *= 1.0f, 800.0f);
    sp2C[1] = 0.0f;
    func_800EE7F8(*(f32 **)((s8 *)arg0 + 0x70), sp44);
    func_800EE7F8(*(f32 **)((s8 *)arg0 + 0x70) + 3, sp20);
    func_800EE7F8(*(f32 **)((s8 *)arg0 + 0x70) + 6, sp2C);
    *(s8 *)(*(u8 **)((s8 *)arg0 + 0x70) + 0x24) = arg1;
    _chbaddiesetup_entrypoint_1(&_baeggsetup_entrypoint_4, *(s32 *)((s8 *)arg0 + 0x184));
} typedef struct { u8 pad0[0x70]; union { f32 * unk70; u8 * unk70_u8p; }; u8 pad74[0x110]; s32 unk184; } Objsetup_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void baeggsetup_entrypoint_6(u8 *arg0, s32 arg1, f32 *arg2, f32 *arg3, f32 *arg4) {
    s32 _chbaddiesetup_entrypoint_1(s32 *, BtIntPtr);
    void func_80094C0C();
    void func_800EE7F8(f32 *, f32 *);
#ifndef BT_NATIVE
    extern s32 _baeggsetup_entrypoint_4;
#endif
    func_80094C0C();
    func_800EE7F8((((Objsetup_arg0 *)arg0)->unk70), arg2);
    func_800EE7F8((((Objsetup_arg0 *)arg0)->unk70) + 3, arg3);
    func_800EE7F8((((Objsetup_arg0 *)arg0)->unk70) + 6, arg4);
    (*(s8 *)((s8 *)((((Objsetup_arg0 *)arg0)->unk70_u8p)) + (0x24))) = (s8) arg1;
    _chbaddiesetup_entrypoint_1(&_baeggsetup_entrypoint_4, (((Objsetup_arg0 *)arg0)->unk184));
}

void baeggsetup_entrypoint_7(u8 *arg0, s32 *arg1) {
    s32 _chbaddiesetup_entrypoint_1(s32 *, BtIntPtr);
    _chbaddiesetup_entrypoint_1(arg1, (((Objsetup_arg0 *)arg0)->unk184));
}

void baeggsetup_entrypoint_8(PlayerState *arg0, s32 arg1) {
    s32 func_8010D930();
    void func_8009C128(PlayerState *, f32[3]);
    void func_8009DAAC(s32 *, f32 *);
    void func_800C4B64(f32);
    void func_800C4B70(s32);
    void func_800C4B7C(s32);
    extern s32 D_80800860_baeggsetup[4];
    s32 sound;
    f32 volume;
    s32 pad;
    f32 position[3];

    sound = 0;
    volume = 1.0f;
    switch (arg1) {
    case 1: sound = 0x443E; break;
    case 2: sound = 0x4590; break;
    case 3: sound = 0x4597; break;
    case 4: sound = 0x4591; break;
    case 5: sound = 0x458F; break;
    case 6: sound = 0x458F; break;
    case 7: sound = 0x443E; break;
    }
    if (sound != 0) {
        func_8009C128(arg0, position);
        func_8009DAAC(&sound, &volume);
        func_800C4B64(volume);
        func_800C4B70(0x7FFF);
        func_800C4B7C(sound);
        func_8010D930(0xB, -1, position, D_80800860_baeggsetup);
    }
}

void baeggsetup_entrypoint_9(PlayerState *arg0) {
    s32 func_80094510(PlayerState *);
    s32 func_8010D930();
    void func_8009C128(PlayerState *, f32[3]);
    void func_8009DAAC(s32 *, f32 *);
    void func_800C4B64(f32);
    void func_800C4B70(s32);
    void func_800C4B7C(s32);
    extern s32 D_80800860_baeggsetup[4];
    s32 sound;
    f32 volume;
    s32 pad;
    f32 position[3];

    sound = 0;
    volume = 1.4f;
    switch (func_80094510(arg0)) {
    case 1: sound = 0x42B; break;
    case 2: sound = 0x42B; break;
    case 3: sound = 0x42B; break;
    case 4: sound = 0x42B; break;
    case 5: sound = 0x42B; break;
    case 6: sound = 0x42B; break;
    case 7: sound = 0x42B; break;
    }
    if (sound != 0) {
        func_8009C128(arg0, position);
        func_8009DAAC(&sound, &volume);
        func_800C4B64(volume);
        func_800C4B70(0x6D60);
        func_800C4B7C(sound);
        func_8010D930(0xB, -1, position, D_80800860_baeggsetup);
    }
}

void baeggsetup_entrypoint_10(void *arg0) {
    void func_800C4B64(f32);
    void func_800C4B70(s32 arg0);
    void func_800C4B7C(s32 arg0);
    void func_8009C128(PlayerState *, f32[3]);
    s32 func_8010D930(s32, s32, u8 *, s32 *);
    extern s32 D_80800860_baeggsetup[4];
    f32 sp1C[3];
    s32 pad;

    func_8009C128(arg0, sp1C);
    func_800C4B64(1.0f);
    func_800C4B70(0x7FFF);
    func_800C4B7C(0x4A5);
    func_8010D930(0xA, -1, sp1C, D_80800860_baeggsetup);
}
/* data_to_c.py: from asm/data/overlays/ba/egg/setup.data.s */
s32 D_80800860_baeggsetup[4] BT_DATA(4, overlays_ba_egg_setup, 0x0) = { 2162717, 1966100, 0, 0 };
