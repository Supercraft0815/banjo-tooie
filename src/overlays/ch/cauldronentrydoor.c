#include "ch/cauldronentrydoor.h"

/* extern */

void func_80800000_chcauldronentrydoor(Actor *arg0) {
    s32 _chdoormake_entrypoint_4(Actor *, s32, s32);
    void _chdoormake_entrypoint_5(Actor *, f32);
    void _chdoormake_entrypoint_6(Actor *, s32);
    void _chdoormake_entrypoint_8(void *, u32);
    BT_IDO_ONLY(s32 _chdoormake_entrypoint_9(Actor *, s32, s32, s32);) BT_NATIVE_ONLY(void _chdoormake_entrypoint_9(Actor *, s32, u16, s32);)
    s32 _glcutDll_entrypoint_19(s32);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    s32 func_80104004(Actor *, f32 *, f32 *);
    void func_8010A800(Actor *, s32);
    f32 *temp_s1;

    temp_s1 = func_80100094(arg0, 1);
    if (_chdoormake_entrypoint_4(arg0, 1, 0x58E) != 0) {
        _chdoormake_entrypoint_5(arg0, 1.0f);
        _chdoormake_entrypoint_6(arg0, 0x40000000);
        _chdoormake_entrypoint_8(arg0, 0xB);
        _chdoormake_entrypoint_9(arg0, 0, 0x56, 0x14);
    }
    func_8010A800(arg0, 0);
    func_80104004(arg0, temp_s1, temp_s1 + 3);
    temp_s1[5] = temp_s1[2] + 40.0f;
    if (_glcutDll_entrypoint_19(0x5B) != 0) {
        func_800FFAB0(arg0);
    }
}

void func_808000C8_chcauldronentrydoor(Actor *arg0) {
    void _chdoor_entrypoint_0(BtIntPtr arg0);
    s32 _chelectricfence_entrypoint_2(Actor *, u8 *, u8 *);
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    s32 func_800D9078(f32 *);
    s32 func_800DA298(s32);
    int func_800DC298(f32);
    void *func_80100094(Actor *, u32);
    void func_8010A590(Actor *);
    extern u32 D_80800520_chcauldronentrydoor[];
    u8 *temp_v0;

    _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, D_80800520_chcauldronentrydoor);
    if (func_800D9078((f32 *)&arg0->actorData[4]) != 0) {
        func_8010A590(arg0);
    }
    if (arg0->unk7C_12 && func_800DA298(0x436) != 0 && func_800DC298(0.2f) != 0) {
        temp_v0 = func_80100094(arg0, 1);
        _chelectricfence_entrypoint_2(arg0, temp_v0, temp_v0 + 0xC);
    }
    _chdoor_entrypoint_0(arg0);
}

s32 func_80800168_chcauldronentrydoor(Actor *arg0, s32 arg1, void *arg2) {
    s32 _chdoor_entrypoint_1(BtIntPtr, s32, BtIntPtr);
    void _chelectricfence_entrypoint_1(Actor *, f32 *);
    f32 func_800EC75C(void *, f32 *);
    void func_800FC6B0(u32);
    void func_8010A570(Actor *);
    f32 sp20[4];
    void **marker = &arg2;

    switch (arg1) {
        case 7:
            func_800FC6B0(0xE);
            return _chdoor_entrypoint_1(arg0, arg1, *marker);
        case 0x3F:
            func_800EC75C(*marker, sp20);
            _chelectricfence_entrypoint_1(arg0, sp20);
            func_8010A570(arg0);
            *(f32 *)&arg0->actorData[4] = 0.2f;
            return 1;
        default:
            return 0;
    }
}                typedef struct { u8 pad0[0x18]; f32 unk18; f32 unk1C; f32 unk20; u8 pad24[0x20]; f32 unk44; u8 pad48[0x26]; u16 unk6E; } Objcauldronentrydoor_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void func_808001FC_chcauldronentrydoor(void *arg0) {
    s32 func_800DA298(s32);
    (((Objcauldronentrydoor_arg0 *)arg0)->unk6E) = (u16) ((((Objcauldronentrydoor_arg0 *)arg0)->unk6E) & 0xFE00);
    (((Objcauldronentrydoor_arg0 *)arg0)->unk18) = 0.0f;
    if (func_800DA298(0x436) != 0) {
        (((Objcauldronentrydoor_arg0 *)arg0)->unk1C) = 360.0f;
    } else {
        (((Objcauldronentrydoor_arg0 *)arg0)->unk1C) = 270.0f;
    }
    (((Objcauldronentrydoor_arg0 *)arg0)->unk20) = 0.5f;
    (((Objcauldronentrydoor_arg0 *)arg0)->unk44) = (f32) (((Objcauldronentrydoor_arg0 *)arg0)->unk1C);
}

int func_80800274_chcauldronentrydoor(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    s32 func_800DA298(s32);
    void func_800DA544(s32 index);
    void func_800FC6B0(u32);
    s32 temp_v1;
    s32 var_v0;
    s32 var_v0_2;

    if (arg1 == 0x95) {
        arg0->rotation[0] = *(f32 *)&arg0->actorData[1];
        return 1;
    }
    if (func_800DA298(0x436) != 0) {
        return 0;
    }
    var_v0 = 0;
    if (arg1 >= 0x68) {
        temp_v1 = arg1 - 0x68;
        if (arg1 < 0x6C) {
            if (temp_v1 & 2) {
                var_v0_2 = 2;
            } else {
                var_v0_2 = 1;
            }
            arg0->unk6C_0 = (arg0->unk6C_0 & (3 - var_v0_2)) + ((temp_v1 & 1) * var_v0_2);
            if (arg0->unk6C_0 == 3) {
                func_800DA544(0x436);
                _capod_entrypoint_13(arg0->unk0, 0, 4, 0x10);
                func_800FC6B0(0xE);
            }
            return 1;
        }
    }
    return var_v0;
}

void func_80800370_chcauldronentrydoor(s32 arg0) 
{
}
void chcauldronentrydoor_entrypoint_0(BT_NATIVE_ONLY(s32 bt_a0))
{
    func_800E1720();
}

void func_80800398_chcauldronentrydoor(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_800C9DE4(f32, void *, s32);
    s32 func_800E15CC(s32, f32, f32);
    void func_80101FDC(Actor *, u32);
    void _chcauldronentrydoor_entrypoint_0(BT_PARAM_OR_VOID(s32 bt_a0));
    extern u32 D_80800534_chcauldronentrydoor[];
    extern u32 D_80800540_chcauldronentrydoor[];

    if (arg0->unk6C_0 == 3) {
        switch (arg0->unk70_10) {
            case 1:
                *(f32 *)&arg0->actorData[0] += 1.0f;
                if (*(f32 *)&arg0->actorData[0] > 25.0f) {
                    func_80101FDC(arg0, 2);
                }
                break;
            case 2:
                if (*(f32 *)&arg0->actorData[1] < 360.0f) {
                    *(f32 *)&arg0->actorData[1] += *(f32 *)&arg0->actorData[2];
                    *(f32 *)&arg0->actorData[2] *= 1.16f;
                    if (*(f32 *)&arg0->actorData[1] > 360.0f) {
                        *(f32 *)&arg0->actorData[1] = 360.0f;
                    }
                    _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, D_80800540_chcauldronentrydoor);
                } else {
                    func_80101FDC(arg0, 3);
                    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800534_chcauldronentrydoor);
                    func_800C9DE4(0.7f, _chcauldronentrydoor_entrypoint_0, func_800E15CC(0, 20.0f, 1.0f));
                }
                break;
        }
    }
    arg0->rotation[0] = *(f32 *)&arg0->actorData[1];
}

OSThread *chcauldronentrydoor_entrypoint_1(void)
{
    extern ActorData D_80800550_chcauldronentrydoor[];

    return (OSThread *) D_80800550_chcauldronentrydoor;
}

OSThread *chcauldronentrydoor_entrypoint_2(void)
{
    extern ActorData D_80800598_chcauldronentrydoor[];

    return (OSThread *) D_80800598_chcauldronentrydoor;
}
/* data_to_c.py: from asm/data/overlays/ch/cauldronentrydoor.data.s */
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
OSThread *func_80108ED0(void);
void func_80107C2C();
u32 D_80800520_chcauldronentrydoor [5] BT_DATA(4, overlays_ch_cauldronentrydoor, 0x0) = { 0x1305B7, 0xE00F3, 0x10C0019, 0x167FBC, 0 };
u32 D_80800534_chcauldronentrydoor [3] BT_DATA(4, overlays_ch_cauldronentrydoor, 0x14) = { 0x1304C7, 0x180002, 0 };
u32 D_80800540_chcauldronentrydoor [4] BT_DATA(4, overlays_ch_cauldronentrydoor, 0x20) = { 0x130507, 0x180002, 0xA008C, 0 };
ActorData D_80800550_chcauldronentrydoor [1] BT_DATA(4, overlays_ch_cauldronentrydoor, 0x30) = { { 817, 917, 2285, 1, 0, (void (*)(struct Actor *))func_808000C8_chcauldronentrydoor, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 1422, 0, 0, 7168, (void (*)(struct Actor *))func_80800370_chcauldronentrydoor, (BtIntPtr)func_80108ED0, 0, 24, (void (*)(struct Actor *))func_80800000_chcauldronentrydoor, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1024, (void (*)(struct Actor *, long, long))func_80800168_chcauldronentrydoor, 0 } };
ActorData D_80800598_chcauldronentrydoor [1] BT_DATA(4, overlays_ch_cauldronentrydoor, 0x78) = { { 172, 1183, 2286, 1, 0, (void (*)(struct Actor *))func_80800398_chcauldronentrydoor, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 3072, (void (*)(struct Actor *))func_80800370_chcauldronentrydoor, 0, 0, 0, (void (*)(struct Actor *))func_808001FC_chcauldronentrydoor, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1026, (void (*)(struct Actor *, long, long))func_80800274_chcauldronentrydoor, 0 } };
