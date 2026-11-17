#include "common.h"

OSThread *chfactoryworkerwear_entrypoint_0(void)
{
    extern ActorData D_80800438_chfactoryworkerwear[];

    return (OSThread *) D_80800438_chfactoryworkerwear;
}

void func_8080000C_chfactoryworkerwear(Actor *arg0, s32 arg1) {
    f32 func_800136E4(f32);
    void func_800EE7F8(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);
    s32 func_801032B0(Actor *, u16, u16);
    void func_8010A800(Actor *, s32);
    f32 *data;

    data = func_80100094(arg0, 0);
    switch (arg1) {
    case 2:
        data[0] = arg0->scale;
        func_800EE7F8(data + 1, arg0->position);
        func_8010A800(arg0, 1);
        break;
    case 3:
        func_800EE7F8(arg0->position, data + 4);
        arg0->rotation[1] = func_800136E4(arg0->rotation[1] + 180.0f);
        arg0->scale = 1.0f;
        break;
    case 4:
        arg0->rotation[2] = 0.0f;
        arg0->scale = 0.4f;
        func_801032B0(arg0, 0x83C, arg0->unk0->unk16);
        break;
    }
    func_80102424(arg0, arg1);
}

void func_80800100_chfactoryworkerwear(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    (*(s8 *)((s8 *)(func_80100094(arg0, 0U)) + (0x24))) = 0;
}

void func_80800124_chfactoryworkerwear(s32 arg0) 
{
}
void func_8080012C_chfactoryworkerwear(Actor *arg0) {
    f32 func_80013970(f32);
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    f32 func_800D8FF8(void);
    void func_800EFE50(f32 *, f32 *, f32 *, f32);
    f32 func_800F1214(f32, f32, f32);
    void *func_80100094(Actor *, u32);
    extern s32 D_80800480_chfactoryworkerwear[12];
    f32 *data;

    data = func_80100094(arg0, 0);
    switch (arg0->unk70_10) {
    case 1:
        break;
    case 2:
        func_800EFE50(arg0->position, data + 1, data + 4, data[7]);
        arg0->scale = func_800F1214(data[7], data[0], 0.4f);
        break;
    case 3:
        arg0->rotation[2] += data[8] * func_800D8FF8();
        break;
    case 4:
        func_800BBCB8(arg0->position, NULL, 1.0f, 5, D_80800480_chfactoryworkerwear);
        func_800EFE50(arg0->position, data + 1, data + 4, data[7]);
        arg0->position[1] += func_80013970(data[7] * 180.0f) * 30.0f;
        arg0->scale = func_800F1214(data[7], data[0], 0.4f);
        break;
    }
}

void func_80800260_chfactoryworkerwear(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    void func_8080000C_chfactoryworkerwear();

    *(s8 *)((u8 *)func_80100094(arg0, 0U) + 0x24) = arg1;
    switch (arg1) {
    case 1:
#ifdef BT_NATIVE
        ((void (*)())func_8080000C_chfactoryworkerwear)(arg0, 2, arg1);
#else
        func_8080000C_chfactoryworkerwear(arg0, 2, arg1);
#endif
        return;
    case 2:
#ifdef BT_NATIVE
        ((void (*)())func_8080000C_chfactoryworkerwear)(arg0, 3, arg1);
#else
        func_8080000C_chfactoryworkerwear(arg0, 3, arg1);
#endif
        return;
    case 3:
#ifdef BT_NATIVE
        ((void (*)())func_8080000C_chfactoryworkerwear)(arg0, 4, arg1);
#else
        func_8080000C_chfactoryworkerwear(arg0, 4, arg1);
#endif
        return;
    }
}    typedef struct { u8 pad0[0x1C]; f32 unk1C; } Objworkerwear_func_808002E4_chfactoryworkerwear_sp1C; /* offsets.py genstruct: fields from raw offsets on sp1C; rename once understood */

/* extern */

void func_808002E4_chfactoryworkerwear(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    f32 func_80101068(void);
    void func_80101038(f32 *arg0);
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    sp1C = temp_v0;
    func_80101038(temp_v0 + 0x10);
    (((Objworkerwear_func_808002E4_chfactoryworkerwear_sp1C *)sp1C)->unk1C) = func_80101068();
}    typedef struct { u8 pad0[0x20]; f32 unk20; } Objworkerwear_func_80800320_chfactoryworkerwear_sp1C; /* offsets.py genstruct: fields from raw offsets on sp1C; rename once understood */

void func_80800320_chfactoryworkerwear(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    f32 func_80101068(void);
    u8 *sp1C;

    sp1C = func_80100094(arg0, 0U);
    (((Objworkerwear_func_80800320_chfactoryworkerwear_sp1C *)sp1C)->unk20) = func_80101068();
}

/* extern */

s32 func_80800350_chfactoryworkerwear(Actor *arg0, s32 arg1, s32 arg2) {
    void func_800FFA88(Unk80132ED0 *);
    void func_80800260_chfactoryworkerwear(Actor *, s32);
    switch (arg1) {                                 /* switch 1; irregular */
    case 33:                                        /* switch 1 */
        switch (((s16 *)&arg2)[0]) {                 /* switch 2; irregular */
        case 1:                                     /* switch 2 */
            func_80800260_chfactoryworkerwear(arg0, ((s16 *)&arg2)[1]);
            break;
        case 2:                                     /* switch 2 */
            func_80800320_chfactoryworkerwear(arg0);
            break;
        case 3:                                     /* switch 2 */
            func_808002E4_chfactoryworkerwear(arg0);
            break;
        }
        break;
    case 44:                                        /* switch 1 */
        func_800FFA88(arg0->unk0);
        break;
    }
    return 0;
}
/* data_to_c.py: from asm/data/overlays/ch/factory/workerwear.data.s */
extern u8 D_80800410_chfactoryworkerwear[];
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
u8 D_80800410_chfactoryworkerwear[40] BT_DATA(4, overlays_ch_factory_workerwear, 0x0) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3E, 0xCC, 0xCC, 0xCD, 0x03, 0x5D, 0x00, 0x01, 0x3E, 0xCC, 0xCC, 0xCD, 0x02, 0xA0, 0x00, 0x01, 0x3F, 0x19, 0x99, 0x9A, 0x02, 0xA1, 0x00, 0x01, 0x3E, 0xCC, 0xCC, 0xCD, 0x02, 0xA0, 0x00, 0x01 };
ActorData D_80800438_chfactoryworkerwear [1] BT_DATA(4, overlays_ch_factory_workerwear, 0x28) = { { 638, 569, 2109, 1, (void *)D_80800410_chfactoryworkerwear, (void (*)(struct Actor *))func_8080012C_chfactoryworkerwear, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 1065353216, 0, 0, 16384, 288, (void (*)(struct Actor *))func_80800124_chfactoryworkerwear, 0, 40, 0, (void (*)(struct Actor *))func_80800100_chfactoryworkerwear, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 9234, (void (*)(struct Actor *, long, long))func_80800350_chfactoryworkerwear, 0 } };
s32 D_80800480_chfactoryworkerwear[12] BT_DATA(4, overlays_ch_factory_workerwear, 0x70) = { 1903082, 1376307, 8388622, 3276860, 2555904, 13107200, 16384036, 2293795, 2424842, 655403, 4980812, 0 };
