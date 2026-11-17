#include "common.h"

OSThread *chfireimp_entrypoint_0(void)
{
    extern ActorData D_808001F8_chfireimp[];

    return (OSThread *) D_808001F8_chfireimp;
}

/* extern */

void func_8080000C_chfireimp(s32 arg0) {
    s32 _sucoasterfly_entrypoint_1(BtIntPtr, s32);
    f32 *_sucoasterfly_entrypoint_5(BtIntPtr);
    s32 func_8010A3E8(s32, s32);
    if (_sucoasterfly_entrypoint_1(arg0, 4) != 0) {
        *_sucoasterfly_entrypoint_5(arg0) = 3.4f;
    }
    func_8010A3E8(arg0, 0x3F266666);
}

void func_8080005C_chfireimp(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void _sucoasterfly_entrypoint_3(Actor *arg0);
    f32 *_sucoasterfly_entrypoint_5(BtIntPtr);
    s32 func_800D90A4(f32 *);
    f32 func_800DC178(f32, f32);
    s32 func_800EFFB4(f32[3], f32, f32[3]);
    void func_8010D640(BtIntPtr);
    extern s32 D_80800240_chfireimp[8];
    f32 *sp2C;
    s32 var_v1;
    f32 sp1C[3];

    sp2C = _sucoasterfly_entrypoint_5(arg0);
    var_v1 = 1;
    _sucoasterfly_entrypoint_3(arg0);
    switch (arg0->unk70_10) {
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
        var_v1 = 0;
        break;
    }
    if ((var_v1 != 0) && (func_800D90A4(sp2C) != 0)) {
        func_8010D640(sp1C);
        if (func_800EFFB4(arg0->position, 1800.0f, sp1C) != 0) {
            *sp2C = func_800DC178(2.4f, 3.4f);
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800240_chfireimp);
        }
    }
}
/* data_to_c.py: from asm/data/overlays/ch/fire/imp.data.s */
extern u8 D_80800170_chfireimp[];
void func_80105834(Actor*);
void _sucoasterfly_entrypoint_6();
void _sucoasterfly_entrypoint_2();
OSThread *_sucoasterfly_entrypoint_0(void);
void func_80107C2C();
s32 _sucoasterfly_entrypoint_4(Actor *arg0, s32 arg1, s32 arg2);
u8 D_80800170_chfireimp[136] BT_DATA(4, overlays_ch_fire_imp, 0x0) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x01, 0x5A, 0x00, 0x01, 0x40, 0x80, 0x00, 0x00, 0x01, 0x89, 0x00, 0x01, 0x40, 0x80, 0x00, 0x00, 0x01, 0x89, 0x00, 0x01, 0x40, 0x80, 0x00, 0x00, 0x01, 0x89, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0xC0, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x40, 0xC0, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x40, 0x00, 0x00, 0x00, 0x01, 0x5A, 0x00, 0x01, 0x40, 0x00, 0x00, 0x00, 0x01, 0x5A, 0x00, 0x01, 0x3F, 0x00, 0x00, 0x00, 0x01, 0x65, 0x00, 0x02, 0x3E, 0x4C, 0xCC, 0xCD, 0x03, 0xCD, 0x00, 0x01, 0x40, 0x00, 0x00, 0x00, 0x00, 0xF7, 0x00, 0x02, 0x40, 0x00, 0x00, 0x00, 0x00, 0xF7, 0x00, 0x84, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x80, 0x00, 0x00, 0x01, 0x89, 0x00, 0x01, 0x40, 0x80, 0x00, 0x00, 0x01, 0x89, 0x00, 0x01 };
ActorData D_808001F8_chfireimp [1] BT_DATA(4, overlays_ch_fire_imp, 0x88) = { { 685, 1122, 1720, 1, (void *)D_80800170_chfireimp, (void (*)(struct Actor *))func_8080005C_chfireimp, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))_sucoasterfly_entrypoint_6, 163840000, 1065353216, 0, 0, 807, 4905, (void (*)(struct Actor *))_sucoasterfly_entrypoint_2, (BtIntPtr)_sucoasterfly_entrypoint_0, 0, 0, (void (*)(struct Actor *))func_8080000C_chfireimp, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32718, 16477, (void (*)(struct Actor *, long, long))_sucoasterfly_entrypoint_4, -2146286236 } };
s32 D_80800240_chfireimp[8] BT_DATA(4, overlays_ch_fire_imp, 0xD0) = { 1246780, 852211, 17563649, 26216200, 0, 0, 0, 0 };
