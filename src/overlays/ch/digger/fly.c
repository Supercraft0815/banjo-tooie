#include "common.h"
#include "core2/baddie_states.h"

OSThread *chdiggerfly_entrypoint_0(void)
{
    extern ActorData D_808000F8_chdiggerfly[];

    return (OSThread *) D_808000F8_chdiggerfly;
}

OSThread *chdiggerfly_entrypoint_1(void)
{
    extern ActorData D_80800140_chdiggerfly[];

    return (OSThread *) D_80800140_chdiggerfly;
}    typedef struct { u8 pad0[0x38]; f32 unk38; } Objfly_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void func_80800018_chdiggerfly(void *arg0) {
    s32 _sucoasterfly_entrypoint_1(BtIntPtr, s32);
    void func_80102FDC(void *, f32);
    void func_8010A3E8(void *, f32);
    _sucoasterfly_entrypoint_1((BtIntPtr)arg0, 0);
    func_80102FDC(arg0, (((Objfly_arg0 *)arg0)->unk38) * 0.75f);
    func_8010A3E8(arg0, 0.75f);
}
/* data_to_c.py: from asm/data/overlays/ch/digger/fly.data.s */
extern u8 D_80800070_chdiggerfly[];
void _sucoasterfly_entrypoint_3();
void func_80105834(Actor*);
void _sucoasterfly_entrypoint_6();
void _sucoasterfly_entrypoint_2();
OSThread *_sucoasterfly_entrypoint_0(void);
void func_80107C2C();
s32 _sucoasterfly_entrypoint_4(Actor *arg0, s32 arg1, s32 arg2);
u8 D_80800070_chdiggerfly[136] BT_DATA(4, overlays_ch_digger_fly, 0x0) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3E, 0xCC, 0xCC, 0xCD, 0x01, 0x90, 0x00, 0x01, 0x3E, 0xCC, 0xCC, 0xCD, 0x01, 0x90, 0x00, 0x01, 0x3F, 0x0A, 0x3D, 0x71, 0x01, 0x90, 0x00, 0x01, 0x3E, 0xCC, 0xCC, 0xCD, 0x01, 0x90, 0x00, 0x01, 0x3E, 0xE6, 0x66, 0x66, 0x05, 0x28, 0x00, 0x02, 0x3E, 0xB8, 0x51, 0xEC, 0x05, 0x29, 0x00, 0x01, 0x3E, 0xCC, 0xCC, 0xCD, 0x01, 0x90, 0x00, 0x01, 0x3F, 0x0A, 0x3D, 0x71, 0x01, 0x90, 0x00, 0x01, 0x3F, 0x0A, 0x3D, 0x71, 0x01, 0x90, 0x00, 0x01, 0x3F, 0x14, 0x7A, 0xE1, 0x05, 0x2A, 0x00, 0x02, 0x3E, 0xA8, 0xF5, 0xC3, 0x05, 0x2B, 0x01, 0x01, 0x3E, 0xC2, 0x8F, 0x5C, 0x05, 0x2C, 0x00, 0x02, 0x3E, 0xC2, 0x8F, 0x5C, 0x05, 0x2C, 0x00, 0x84, 0x3F, 0x0A, 0x3D, 0x71, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x0A, 0x3D, 0x71, 0x01, 0x90, 0x00, 0x01, 0x3F, 0x0A, 0x3D, 0x71, 0x01, 0x90, 0x00, 0x01 };
ActorData D_808000F8_chdiggerfly [1] BT_DATA(4, overlays_ch_digger_fly, 0x88) = { { 420, 307, 1630, 1, (void *)D_80800070_chdiggerfly, (void (*)(struct Actor *))_sucoasterfly_entrypoint_3, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))_sucoasterfly_entrypoint_6, 163840000, 1073741824, 0, 0, 805, 809, (void (*)(struct Actor *))_sucoasterfly_entrypoint_2, (BtIntPtr)_sucoasterfly_entrypoint_0, 0, 0, (void (*)(struct Actor *))func_80800018_chdiggerfly, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32718, 16413, (void (*)(struct Actor *, long, long))_sucoasterfly_entrypoint_4, (BtIntPtr)&D_80124550[5] } };
ActorData D_80800140_chdiggerfly [1] BT_DATA(4, overlays_ch_digger_fly, 0xD0) = { { 421, 308, 1630, 1, (void *)D_80800070_chdiggerfly, (void (*)(struct Actor *))_sucoasterfly_entrypoint_3, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))_sucoasterfly_entrypoint_6, 163840000, 1073741824, 0, 0, 805, 809, (void (*)(struct Actor *))_sucoasterfly_entrypoint_2, (BtIntPtr)_sucoasterfly_entrypoint_0, 0, 0, (void (*)(struct Actor *))func_80800018_chdiggerfly, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32750, 16405, (void (*)(struct Actor *, long, long))_sucoasterfly_entrypoint_4, (BtIntPtr)&D_80124550[5] } };
