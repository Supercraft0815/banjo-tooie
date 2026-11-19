#include "common.h"
#include "core2/baddie_states.h"

OSThread *chzubba_entrypoint_0(void)
{
    extern ActorData D_80800178_chzubba[];

    return (OSThread *) D_80800178_chzubba;
}

/* extern */

void func_8080000C_chzubba(s32 arg0) {
    s32 _sucoasterfly_entrypoint_1(BtIntPtr, s32);
    s32 func_8010A3E8(s32, s32);
    _sucoasterfly_entrypoint_1(arg0, 0);
    func_8010A3E8(arg0, 0x3F266666);
}

void func_80800040_chzubba(Actor *arg0) {
    void _subaddieaudioloop_entrypoint_5(Actor *, f32 *, u32, s32, u32 *);
    void _sucoasterfly_entrypoint_3(Actor *);
    extern u32 D_808001C0_chzubba[8];
    u32 var_a2;

    _sucoasterfly_entrypoint_3(arg0);
    switch (arg0->unk70_10) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        var_a2 = 1;
        break;
    default:
        var_a2 = 0;
        break;
    }
    /* Keep this condition: IDO otherwise moves the default assignment. */
    if ((func_80800040_chzubba && func_80800040_chzubba) && func_80800040_chzubba) {}
    if (arg0) {}
    _subaddieaudioloop_entrypoint_5(arg0, arg0->position, var_a2, -1, D_808001C0_chzubba);
}
/* data_to_c.py: from asm/data/overlays/ch/zubba.data.s */
extern u8 D_808000F0_chzubba[];
void func_80105834(Actor*);
void _sucoasterfly_entrypoint_6();
void _sucoasterfly_entrypoint_2();
OSThread *_sucoasterfly_entrypoint_0(void);
void func_80107C2C();
s32 _sucoasterfly_entrypoint_4(Actor *arg0, s32 arg1, s32 arg2);
u8 D_808000F0_chzubba[136] BT_DATA(4, overlays_ch_zubba, 0x0) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x26, 0x66, 0x66, 0x03, 0xCB, 0x00, 0x01, 0x3F, 0x26, 0x66, 0x66, 0x03, 0xCB, 0x00, 0x01, 0x3F, 0x26, 0x66, 0x66, 0x03, 0xCB, 0x00, 0x01, 0x3F, 0x26, 0x66, 0x66, 0x03, 0xCB, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x26, 0x66, 0x66, 0x03, 0xCC, 0x00, 0x01, 0x3F, 0x26, 0x66, 0x66, 0x03, 0xCC, 0x00, 0x01, 0x3F, 0x26, 0x66, 0x66, 0x03, 0xCB, 0x00, 0x01, 0x3F, 0x26, 0x66, 0x66, 0x03, 0xCB, 0x00, 0x01, 0x3F, 0x00, 0x00, 0x00, 0x01, 0x65, 0x00, 0x02, 0x3E, 0x4C, 0xCC, 0xCD, 0x03, 0xCD, 0x00, 0x01, 0x3F, 0x80, 0x00, 0x00, 0x03, 0xCE, 0x00, 0x02, 0x3F, 0x80, 0x00, 0x00, 0x03, 0xCE, 0x00, 0x84, 0x3F, 0x26, 0x66, 0x66, 0x03, 0xCB, 0x00, 0x01, 0x3F, 0x26, 0x66, 0x66, 0x03, 0xCB, 0x00, 0x01, 0x3F, 0x26, 0x66, 0x66, 0x03, 0xCB, 0x00, 0x01 };
ActorData D_80800178_chzubba [1] BT_DATA(4, overlays_ch_zubba, 0x88) = { { 682, 531, 2143, 1, (void *)D_808000F0_chzubba, (void (*)(struct Actor *))func_80800040_chzubba, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))_sucoasterfly_entrypoint_6, 163840000, 1065353216, 0, 0, 807, 809, (void (*)(struct Actor *))_sucoasterfly_entrypoint_2, (BtIntPtr)_sucoasterfly_entrypoint_0, 0, 0, (void (*)(struct Actor *))func_8080000C_chzubba, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32718, 16413, (void (*)(struct Actor *, long, long))_sucoasterfly_entrypoint_4, (BtIntPtr)&D_80124550[5] } };
u32 D_808001C0_chzubba[8] BT_DATA(4, overlays_ch_zubba, 0xD0) = { 0x13049B, 0x161770, 0xE00E6, 0x1190180, 0, 0, 0, 0 };
