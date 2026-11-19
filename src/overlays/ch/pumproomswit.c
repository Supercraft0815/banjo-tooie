#include "common.h"
#include "core2/switch_animations.h"
OSThread *chpumproomswitch_entrypoint_0(void)
{
    extern ActorData D_80800380_chpumproomswitch[];

    return (OSThread *) D_80800380_chpumproomswitch;
}

OSThread *chpumproomswitch_entrypoint_1(void)
{
    extern ActorData D_808003C8_chpumproomswitch[];

    return (OSThread *) D_808003C8_chpumproomswitch;
}

/* extern */

void func_80800018_chpumproomswitch(void *arg0) {
    s32 _chswitch_entrypoint_7(BtIntPtr, s32);
    void _chswitch_entrypoint_8(s32 *arg0, s32 arg1);
    void _chswitch_entrypoint_9(void *arg0);
    s32 func_800DA298(s32);
    void func_800DA544(s32 index);
    void func_80103110(void *, s32);
    s32 func_8080016C_chpumproomswitch(u8 *);
    Actor *actor = arg0;

    if (func_800DA298(0xB2) != 0) {
        func_800DA544(func_8080016C_chpumproomswitch(arg0));
    }
    _chswitch_entrypoint_7(arg0, func_8080016C_chpumproomswitch(arg0));
    _chswitch_entrypoint_8(arg0, actor->unk74_7 == 0x32 ? 0x400 : 0x200);
    if (func_800DA298(0xB2) != 0) {
        _chswitch_entrypoint_9(arg0);
        func_80103110(arg0, 0);
    }
}

/* extern */

void func_808000BC_chpumproomswitch(void *arg0, s32 arg1, s32 arg2) {
    s32 _chswitch_entrypoint_10(BtIntPtr, s32, s32);
    s32 func_800DA298(s32);
    s32 func_80101180(s32, s32, BtIntPtr);
    void func_80103110(void *, s32);
    s32 func_801032B0(Actor *, u16, u16);
    Actor *actor = arg0;

    if (arg1 != 7) {
        if (arg1 == 0x95) {
            func_801032B0(actor, actor->unk74_7 == 0x32 ? 0x7B9 : 0x7B8, actor->unk0->unk16);
            if (func_800DA298(0xB2) != 0) {
                func_80103110(arg0, 0);
            }
        }
    } else {
        func_80101180(0x3D2, 0xA, 0);
    }
    _chswitch_entrypoint_10(arg0, arg1, arg2);
}                 typedef struct { u8 pad0[0x58]; f32 unk58; u8 pad5C[0x1A]; u16 unk76; } Objpumproomswit_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

s32 func_8080016C_chpumproomswitch(u8 *arg0) {
    u32 value = ((Objpumproomswit_arg0 *)arg0)->unk76;
    s32 result = 0x9E7;
    return ((value & 0xFFFF) >> 7 == 0x32) ? 0x9E6 : result;
}

/* extern */

void func_80800194_chpumproomswitch(void *arg0) {
    s32 _glcutDll_entrypoint_19(s32);
    s32 func_800DA298(s32);
    void func_80101FDC(Actor *, u32);
    (((Objpumproomswit_arg0 *)arg0)->unk58) = 0.0f;
    if ((func_800DA298(0xB2) != 0) || (_glcutDll_entrypoint_19(0x20) != 0)) {
        func_80101FDC(arg0, 2);
    }
}

void func_808001E4_chpumproomswitch(Actor *arg0) {
    void func_800C31DC(u8, f32);
    u8 func_800C4350(u8 index, f32 *position, s32 *command_list);
    s32 func_800D9078(f32 *arg0);
    s32 func_800EA05C();
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    extern s32 D_80800410_chpumproomswitch[5];
    extern s32 D_80800424_chpumproomswitch[7];
    s32 *var_a2;

    if (arg0->unk70_10 == 2) {
        if (arg0->unk5F == 0) {
            if (func_800EA05C() == 0xE3) {
                var_a2 = D_80800410_chpumproomswitch;
            } else {
                var_a2 = D_80800424_chpumproomswitch;
            }
            arg0->unk5F = func_800C4350(0U, arg0->position, var_a2);
        }
        func_800D9078(&arg0->unk58);
        func_800C31DC(arg0->unk5F, func_800F12D4(arg0->unk58, 0.0f, 3.5f, 1.0f, 0.3f));
        func_800C4350(arg0->unk5F, NULL, NULL);
    }
}

s32 func_808002A0_chpumproomswitch(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    s32 _capod_entrypoint_14(void);
    void _glcutDll_entrypoint_6(u32, u32);
    s32 func_800DA298(s32);
    void func_80101FDC(Actor *, u32);

    switch (arg1) {
        case 10:
            if (arg0->unk70_10 == 1 && func_800DA298(0x9E6) != 0 && func_800DA298(0x9E7) != 0) {
                arg0->unk58 = 3.5f;
                func_80101FDC(arg0, 2);
                _capod_entrypoint_13(arg0->unk0, NULL, 0, 0x10);
            }
            break;
        case 11:
            _capod_entrypoint_14();
            _glcutDll_entrypoint_6(0xE1, 0x20);
            return 4;
        default:
            return 0;
    }
    return 1;
}
/* data_to_c.py: from asm/data/overlays/ch/pumproomswit.data.s */

void _chswitch_entrypoint_6();
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
void func_8010A730();
ActorData D_80800380_chpumproomswitch [1] BT_DATA(4, overlays_ch_pumproomswit, 0x0) = { { 835, 843, 1976, 1, (void *)BT_DATA_FIELD(D_8011A220, (u8 *)D_8011A1BC + 0x64), (void (*)(struct Actor *))_chswitch_entrypoint_6, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 16384, 2060, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800018_chpumproomswitch, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 11282, (void (*)(struct Actor *, long, long))func_808000BC_chpumproomswitch, 0 } };
ActorData D_808003C8_chpumproomswitch [1] BT_DATA(4, overlays_ch_pumproomswit, 0x48) = { { 816, 978, 0, 1, 0, (void (*)(struct Actor *))func_808001E4_chpumproomswitch, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_8010A730, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800194_chpumproomswitch, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1538, (void (*)(struct Actor *, long, long))func_808002A0_chpumproomswitch, 0 } };
s32 D_80800410_chpumproomswitch[5] BT_DATA(4, overlays_ch_pumproomswit, 0x90) = { 33947667, 78905366, 786432001, 32771500, 0 };
s32 D_80800424_chpumproomswitch[7] BT_DATA(4, overlays_ch_pumproomswit, 0xA4) = { 33947667, 78905366, 524288001, 52433300, 0, 0, 0 };
