#include "common.h"

OSThread *chbigtopticket_entrypoint_0(void)
{
    extern ActorData D_80800120_chbigtopticket[];

    return (OSThread *) D_80800120_chbigtopticket;
}

void func_8080000C_chbigtopticket(s32 arg0) 
{
}                typedef struct { u8 pad0[0x48]; f32 unk48; u8 pad4C[0x30]; s32 unk7C; } Objbigtopticket_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */
void func_80800014_chbigtopticket(u8 *arg0) {
    f32 func_800D8FF8(void);
    void func_80103110(void *arg0, s32 arg1);
    (((Objbigtopticket_arg0 *)arg0)->unk48) = (f32) ((((Objbigtopticket_arg0 *)arg0)->unk48) - (func_800D8FF8() * 175.0f));
    func_80103110(arg0, 0U);
}

/* extern */

void func_80800058_chbigtopticket(void *arg0 BT_PASS2(, s32 bt_a1)) {
    s32 func_80101870();
    void func_80103110(void *arg0, s32 arg1);
    func_80101870();
    func_80103110(arg0, (u32) ((((Objbigtopticket_arg0 *)arg0)->unk7C) << 0x13) >> 0x1F);
}

/* extern */

s32 func_8080008C_chbigtopticket(Actor *arg0, s32 arg1, s32 arg2) {
    void _fxsparkle_entrypoint_1(f32 *, u32);
    s32 _sudialog_entrypoint_0(s32 arg0, s32 arg1);
    void func_800D0BD4(s32, u32);
    void func_800D1844(s32);
    void func_800FC6B0(u32);
    void func_800FFAB0(Actor *);
    void func_8010A570(Actor *);
    switch (arg1) {
        case 0x3E:
            _sudialog_entrypoint_0(0x19F, 4);
            func_800D0BD4(*(s32 *)&arg0->unk54, 8);
            func_800D1844(0x4D);
            func_800FC6B0(0x73);
            _fxsparkle_entrypoint_1(arg0->position, 0x11);
            func_8010A570(arg0);
            func_800FFAB0(arg0);
            return 1;
        case 0x13:
            *(s32 *)&arg0->unk54 = arg2;
            break;
        default:
            return 0;
    }
    return 1;
}
/* data_to_c.py: from asm/data/overlays/ch/bigtopticket.data.s */
void func_80105834(Actor*);
OSThread *func_80108ED0(void);
void func_80107C2C();
ActorData D_80800120_chbigtopticket [1] BT_DATA(4, overlays_ch_bigtopticket, 0x0) = { { 809, 966, 1983, 1, 0, (void (*)(struct Actor *))func_80800014_chbigtopticket, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80800058_chbigtopticket, 0, 1065353216, 0, 0, 16388, 4, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_8080000C_chbigtopticket, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 6164, (void (*)(struct Actor *, long, long))func_8080008C_chbigtopticket, 0 } };
