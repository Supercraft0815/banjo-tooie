#include "common.h"

void func_80800000_chfactorytrashbelt(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    f32 func_800138D0(f32);
    f32 func_800D91B8(f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_800F48BC(BtIntPtr, f32 *);
    BtUIntPtr func_800F54E4(void);
    void func_800F5A00(BtIntPtr, f32 *);
    s32 func_800F6C5C(BtIntPtr);
    extern u32 D_808005C0_chfactorytrashbelt[5];
    f32 pos[3];
    f32 wave;
    f32 time;
    f32 period;

    func_800F5A00(func_800F54E4(), pos);
    if (pos[0] < 500.0f && pos[0] > -500.0f &&
        pos[2] < 600.0f && pos[2] > -600.0f &&
        func_800F6C5C(func_800F54E4())) {
        wave = func_800138D0(func_800F10B4(pos[0], -700.0f, 700.0f, 0.0f, 1.5f) * 360.0f * 7.0f);
        func_800EFA4C(pos, 200.0f / (arg0->unk74_7 / 70.0f), wave * 1.5f * 5.0f, 0.0f);
        func_800F48BC(func_800F54E4(), pos);
    }
    _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, D_808005C0_chfactorytrashbelt);
    time = func_800D91B8(&arg0->unk58);
    period = arg0->unk74_7 / 70.0f;
    if (period <= time) {
        arg0->unk58 -= period;
    }
}
struct Vector { f32 v[3]; };
void func_808001EC_chfactorytrashbelt(Actor *arg0, void *arg1) {
    f32 func_800138D0(f32);
    void *func_800DE498(void *, f32 *, f32 *, f32, f32 *, BtIntPtr);
    void func_800DF47C(s32, BtIntPtr);
    void func_800DF830(s32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void *func_80100094(Actor *, u32);
    void func_801017D0(Actor *);
    BtIntPtr func_8010347C(Unk80132ED0 *);

    extern struct Vector D_808005D4_chfactorytrashbelt;
    extern struct Vector D_808005E0_chfactorytrashbelt;
    f32 fraction;
    f32 offset;
    s32 *data;
    s32 i;

    data = func_80100094(arg0, 0);
    offset = func_800F10B4(arg0->unk58, 0.0f, arg0->unk74_7 / 70.0f, 0.0f, 200.0f);
    for (i = 0; i < 7; i++) {
        struct Vector pos = D_808005D4_chfactorytrashbelt;
        struct Vector rot = D_808005E0_chfactorytrashbelt;
        pos.v[0] += i * 200.0f + offset;
        fraction = func_800F10B4(pos.v[0], -700.0f, 700.0f, 0.0f, 1.0f);
        pos.v[1] = arg0->position[1] + func_800138D0(fraction * 360.0f * 7.0f) * 1.5f;
        rot.v[0] = func_800138D0(fraction * 360.0f * 7.0f);
        *data = i;
        func_800DF830(1);
        func_800DF47C(func_801017D0, arg0);
        func_800DE498(arg1, pos.v, rot.v, 1.0f, NULL, func_8010347C(arg0->unk0));
    }
}

s32 func_8080041C_chfactorytrashbelt(Actor *arg0, s32 arg1, volatile s32 arg2) {
    void func_800DF660(s32 type,uintptr_t a,uintptr_t b,s32 alpha);
    void func_800DF720(BtIntPtr);
    void func_800DF818(BtIntPtr);
    void *func_80100094(Actor *, u32);
    BtIntPtr func_80100A74(s16, s32);
    BtIntPtr func_80100AC4(s16);
    s16 func_80100D24(void *model,s32 asset,s32 buffers,s32 packed,s32 palette,s32 *color);
    void func_80100E18(s16);
    struct { s32 index; s16 handles[7]; } *data;
    s32 i;
    s32 j;
    s32 k;
    BtIntPtr value;
    s16 handle;

    data = func_80100094(arg0, 0);
    switch (arg1) {
    case 0x95:
        for (i = 0; i < 7; i++) {
            data->handles[i] = 0;
        }
        break;
    case 0x29:
        value = *(s32 *)&arg2;
        for (j = 0; j < 7; j++) {
            data->handles[j] = func_80100D24(value, arg0->unk0->unk14, 1, 1, arg0->unk0->unk16, 0);
        }
        break;
    case 0x2A:
        for (k = 0; k < 7; k++) {
            if (data->handles[k] != 0) {
                func_80100E18(data->handles[k]);
                data->handles[k] = 0;
            }
        }
        break;
    case 0x1F:
        handle = data->handles[data->index];
        func_800DF818(func_80100A74(handle, 0));
        func_800DF660(2, -2, 0, arg0->alpha);
        func_800DF720(func_80100AC4(handle));
        break;
    default:
        return 0;
    }
    return 1;
}

OSThread *chfactorytrashbelt_entrypoint_0(void)
{
    extern ActorData D_808005EC_chfactorytrashbelt[];

    return (OSThread *) D_808005EC_chfactorytrashbelt;
}
/* data_to_c.py: from asm/data/overlays/ch/factory/trashbelt.data.s */
void func_80105834(Actor*);
void func_80107C2C();
u32 D_808005C0_chfactorytrashbelt[5] BT_DATA(4, overlays_ch_factory_trashbelt, 0x0) = { 0x130527, 0xA0080, 0x164650, 0x100C8, 0x17700000 };
struct Vector D_808005D4_chfactorytrashbelt BT_DATA(4, overlays_ch_factory_trashbelt, 0x14) = { { -700.0f, 0.0f, 0.0f } };
struct Vector D_808005E0_chfactorytrashbelt BT_DATA(4, overlays_ch_factory_trashbelt, 0x20) = { { 0.0f, 90.0f, 0.0f } };
ActorData D_808005EC_chfactorytrashbelt [1] BT_DATA(4, overlays_ch_factory_trashbelt, 0x2C) = { { 344, 1027, 2173, 1, 0, (void (*)(struct Actor *))func_80800000_chfactorytrashbelt, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_808001EC_chfactorytrashbelt, 0, 0, 0, 0, 0, 1024, 0, 0, 20, 0, 0, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1026, (void (*)(struct Actor *, long, long))func_8080041C_chfactorytrashbelt, 0 } };
