#include "common.h"

/* extern */

typedef struct { u8 pad0[0x28]; f32 unk28; } Objroargrill_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */ void func_80800000_chdinoroargrill(void *arg0) {
    void func_8010A800(void **arg0, s32 arg1);
    (((Objroargrill_arg0 *)arg0)->unk28) = 0.0f;
    func_8010A800(arg0, 0);
}

void func_80800028_chdinoroargrill(Actor *arg0) {
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    void _chdoor_entrypoint_0(BtIntPtr arg0);
    s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_8(void *, u32);
    void func_80101FDC(Actor *, u32);
    s32 func_80102F44(void *);
    s32 func_8010C710(Actor *);
    extern u8 D_80800250_chdinoroargrill[];
    Unk80132ED0 *temp_a0;

    if (D_80800250_chdinoroargrill[(s32) *(f32 *)&arg0->actorData[4]] == 0) {
        if (func_80102F44(arg0) == 0) {
            func_80101FDC(arg0, 3);
            arg0->unk58 = 1.9f;
            temp_a0 = arg0->unk0;
            _capod_entrypoint_13(temp_a0, temp_a0, 0x4C, 0x810);
            if (_chdoormake_entrypoint_3(arg0, 0.0f, 90.0f, arg0->scale * 170.0f, 0, -1) != 0) {
                _chdoormake_entrypoint_8(arg0, 0xE);
            }
        }
        _chdoor_entrypoint_0(arg0);
        return;
    }
    if (func_8010C710(arg0) >= 0xC5C11) {
        *(f32 *)&arg0->actorData[4] = 0.0f;
    }
}

s32 func_80800124_chdinoroargrill(Actor *arg0, s32 arg1, s32 arg2) {
    void func_800DA544(GameFlag);
    void func_800FC63C(u32, u32);
    void func_800FFAB0(Actor *);
    extern u8 D_80800250_chdinoroargrill[];

    switch (arg1) {
        case 0xB:
            if (arg2 == 0x4C) {
                func_800DA544(0xA22);
                func_800FFAB0(arg0);
            }
            return 3;
        case 0x1D:
        case 0x1E:
            if (D_80800250_chdinoroargrill[(s32)*(f32 *)&arg0->actorData[4]] != 0) {
                if (arg1 == D_80800250_chdinoroargrill[(s32)*(f32 *)&arg0->actorData[4]]) {
                    *(f32 *)&arg0->actorData[4] += 1.0f;
                    if (D_80800250_chdinoroargrill[(s32)*(f32 *)&arg0->actorData[4]] == 0) {
                        func_800FC63C(0x10, -1);
                        return 1;
                    }
                } else {
                    *(f32 *)&arg0->actorData[4] = 0.0f;
                }
            }
            return 1;
        case 0x95:
            arg0->unk79_2 = 0;
            return 1;
        default:
            return 0;
    }
}

OSThread *chdinoroargrill_entrypoint_0(void)
{
    extern ActorData D_80800258_chdinoroargrill[];

    return (OSThread *) D_80800258_chdinoroargrill;
}
/* data_to_c.py: from asm/data/overlays/ch/dino/roargrill.data.s */
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
u8 D_80800250_chdinoroargrill [8] BT_DATA(4, overlays_ch_dino_roargrill, 0x0) = { 0x1D, 0x1D, 0x1E, 0x1D, 0x1E, 0x1E, 0, 0 };
ActorData D_80800258_chdinoroargrill [1] BT_DATA(4, overlays_ch_dino_roargrill, 0x8) = { { 172, 1186, 1988, 1, 0, (void (*)(struct Actor *))func_80800028_chdinoroargrill, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 2594, 0, 16384, 2048, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800000_chdinoroargrill, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 9234, (void (*)(struct Actor *, long, long))func_80800124_chdinoroargrill, 0 } };
