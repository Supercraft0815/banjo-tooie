#include "common.h"

/* extern */

typedef struct { u8 pad0[0x48]; s32 unk48; u8 pad4C[0xC]; f32 unk58; } Objplatuegrill_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */ void func_80800000_chplatuegrill(void *arg0) {
    s32 _chdoormake_entrypoint_3(void *, s32, s32, f32, s32, s32);
    s32 _chdoormake_entrypoint_5(void *, s32);
    s32 _chdoormake_entrypoint_6(void *, s32);
    s32 _chdoormake_entrypoint_8(void *, s32);
    s32 _chdoormake_entrypoint_9(void *, s32, s32, s32);
    f32 func_80103EF4();
    _chdoormake_entrypoint_3(arg0, (((Objplatuegrill_arg0 *)arg0)->unk48), 0x42B40000, func_80103EF4() * 1.1f, 1, 0x3EA);
    _chdoormake_entrypoint_5(arg0, 0x40000000);
    _chdoormake_entrypoint_6(arg0, 0x40800000);
    _chdoormake_entrypoint_8(arg0, 2);
    _chdoormake_entrypoint_9(arg0, 0, 0x10, 0x10);
}

OSThread *chplatuegrill_entrypoint_0(void)
{
    extern ActorData D_808001D0_chplatuegrill[];

    return (OSThread *) D_808001D0_chplatuegrill;
}

/* extern */

void func_808000A0_chplatuegrill(void *arg0) {
    s32 func_800DA298(s32);
    void func_80102424(Actor *, s32);
    if (func_800DA298(0x3EA) != 0) {
        (((Objplatuegrill_arg0 *)arg0)->unk58) = 0.0f;
        func_80102424(arg0, 2);
    }
}

/* extern */

void func_808000DC_chplatuegrill(Actor *arg0) {
    s32 func_80101180(s32, s32, BtIntPtr);
    s32 func_80101DDC(Actor *);
    void func_80102424(Actor *, s32);
    void func_80103110(Actor *, u32);
    u32 temp_t6;

    temp_t6 = arg0->unk70_10;
    if (temp_t6 != 2) {
        if ((temp_t6 == 3) && (func_80101DDC(arg0) != 0)) {
            func_80102424(arg0, 2);
            func_80101180(0x518, 7, 0);
        }
    } else {
        func_80103110(arg0, 0);
    }
}

/* extern */

s32 func_80800148_chplatuegrill(Actor *arg0, s32 arg1, s32 arg2) {
    void func_800FC660(u32);
    void func_80102424(Actor *, s32);
    void func_80103110(Actor *, u32);
    if (arg1 == 0x40) {
        if (arg0->unk70_10 == 1) {
            func_80103110(arg0, 1);
            func_80102424(arg0, 3);
            func_800FC660(0xE);
        }
        return 1;
    }
    return 0;
}

OSThread *chplatuegrill_entrypoint_1(void)
{
    extern ActorData D_80800238_chplatuegrill[];

    return (OSThread *) D_80800238_chplatuegrill;
}
/* data_to_c.py: from asm/data/overlays/ch/platuegrill.data.s */
void _chdoor_entrypoint_0();
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
OSThread *func_80108ED0(void);
void func_80107C2C();
s32 _chdoor_entrypoint_1(Actor *arg0, s32 arg1, BtIntPtr arg2);
extern u8 D_80800218_chplatuegrill[];
ActorData D_808001D0_chplatuegrill [1] BT_DATA(4, overlays_ch_platuegrill, 0x0) = { { 344, 1304, 2410, 1, 0, (void (*)(struct Actor *))_chdoor_entrypoint_0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 8000, 0, 1002, 0, 0, 3072, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_80800000_chplatuegrill, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 9218, (void (*)(struct Actor *, long, long))_chdoor_entrypoint_1, 0 } };
u8 D_80800218_chplatuegrill[32] BT_DATA(4, overlays_ch_platuegrill, 0x48) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3E, 0xCC, 0xCC, 0xCD, 0x00, 0x8E, 0x00, 0x44, 0x3E, 0xCC, 0xCC, 0xCD, 0x00, 0x8E, 0x00, 0x02, 0x3C, 0x23, 0xD7, 0x0A, 0x00, 0x8E, 0x00, 0x02 };
ActorData D_80800238_chplatuegrill [1] BT_DATA(4, overlays_ch_platuegrill, 0x68) = { { 273, 1305, 2459, 1, (void *)D_80800218_chplatuegrill, (void (*)(struct Actor *))func_808000DC_chplatuegrill, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 5000, 0, 0, 0, 0, 2088, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_808000A0_chplatuegrill, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32766, 9216, (void (*)(struct Actor *, long, long))func_80800148_chplatuegrill, 0 } };
