#include "common.h"

OSThread *charea51gate_entrypoint_0(void)
{
    extern ActorData D_80800290_charea51gate[];

    return (OSThread *) D_80800290_charea51gate;
}                typedef struct { u8 pad0[0x20]; f32 unk20; u8 pad24[0xC]; f32 unk30; } Objarea51gate_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_8080000C_charea51gate(BtIntPtr arg0) {
    s32 func_80104004(BtIntPtr, BtIntPtr, BtIntPtr);
    void func_8010A800(Actor*, s32);
    func_80104004(arg0, arg0 + 0x18, arg0 + 0x28);
    (((Objarea51gate_arg0 *)arg0)->unk30) = (f32) ((((Objarea51gate_arg0 *)arg0)->unk20) + 40.0f);
    func_8010A800((Actor *) arg0, 2);
}

/* extern */

void func_80800054_charea51gate(Actor *arg0) {
    int func_800DC298(f32);
    s32 _chelectricfence_entrypoint_2(Actor *, u8 *, u8 *);
    if (arg0->unk7C_12 && (func_800DC298(0.15f) != 0)) {
        _chelectricfence_entrypoint_2(arg0, (u8 *)arg0 + 0x18, (u8 *)arg0 + 0x28);
    }
}

s32 func_808000A0_charea51gate(Actor *arg0, s32 arg1, s32 *volatile arg2) {
    void _chelectricfence_entrypoint_1(Actor *, f32 *);
    void _chexploder_entrypoint_4(Actor *arg0, s16 *arg1, s32 arg2);
    s32 func_8001210C(s32);
    void func_800EC398(Unk80132ED0 *, f32 *);
    BtUIntPtr func_800F54E4(void);
    s32 func_800F6438(BtUIntPtr);
    s32 func_800F64A4(BtIntPtr, s32);
    s32 func_800F79DC(BtIntPtr, s32, BtIntPtr);
    void func_80109EF4(void *, s32);
    void func_80109F08(void *, s32);
    void func_80800228_charea51gate(BtIntPtr);
    struct GateMarker {
        u8 pad0[0x1A];
        u16 flagIndex : 11;
        u16 pad1A : 5;
        u32 pad1C[2];
        u32 kind : 10;
        u32 pad24 : 22;
    } *marker;
    f32 position[3];
    s32 enabled;
    s32 active;
    s32 pad[2];

    switch (arg1) {
        case 0x3E:
            enabled = 1;
            marker = (struct GateMarker *)arg2;
            func_800EC398((Unk80132ED0 *)marker, position);
            if (marker->kind == 0) {
                if (func_800F64A4(marker->flagIndex, 0x8000) == 0) {
                    func_800F79DC(marker->flagIndex, 5, (BtIntPtr)arg0->unk0);
                } else {
                    enabled = func_8001210C(3) == 0;
                }
            }
            if (enabled) {
                _chelectricfence_entrypoint_1(arg0, position);
            }
            return 1;
        case 0x40:
            _chexploder_entrypoint_4(arg0, **(s32 **)&arg2 + 4, 2);
            break;
        case 0x90:
            func_80800228_charea51gate((BtIntPtr)arg0);
            break;
        case 0x95:
            active = func_800F6438(func_800F54E4()) != 0;
            if (active) {
                active = func_800F64A4(func_800F54E4(), 0x8000) == 0;
            }
            if (active) {
                func_80109EF4(arg0, 1);
            } else {
                func_80109F08(arg0, 1);
            }
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800228_charea51gate(BtIntPtr arg0) {
    void _chexploder_entrypoint_12(Actor *arg0, s32 arg1);
    void _subaddieaudioquick_entrypoint_2(Actor *arg0, f32 arg1[3], void *arg2);
    void func_800DA544(s32 index);
    void func_800FFAB0(Actor *actor);
    BtIntPtr func_80101080();
    BtIntPtr func_80106790(BtIntPtr);
    extern s32 D_808002D8_charea51gate[6];
    _chexploder_entrypoint_12(func_80106790(func_80101080()), 0x3C);
    _subaddieaudioquick_entrypoint_2(arg0, arg0 + 4, D_808002D8_charea51gate);
    func_800FFAB0(arg0);
    func_800DA544(0xA7);
}
/* data_to_c.py: from asm/data/overlays/ch/area51gate.data.s */
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
OSThread *func_80108ED0(void);
void func_80107C2C();
ActorData D_80800290_charea51gate [1] BT_DATA(4, overlays_ch_area51gate, 0x0) = { { 679, 834, 1920, 1, 0, (void (*)(struct Actor *))func_80800054_charea51gate, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 393216000, 0, 167, 0, 0, 3072, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_8080000C_charea51gate, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 9216, (void (*)(struct Actor *, long, long))func_808000A0_charea51gate, 0 } };
s32 D_808002D8_charea51gate[6] BT_DATA(4, overlays_ch_area51gate, 0x48) = { 1246408, 655590, 1572864, 0, 0, 0 };
