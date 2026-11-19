#include "common.h"

/* extern */

void func_80800000_chhagstraindoor(Actor *arg0) {
    s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_5(Actor *, f32);
    void _chdoormake_entrypoint_6(Actor *, s32);
    void _chdoormake_entrypoint_8(void *, u32);
    BT_IDO_ONLY(s32 _chdoormake_entrypoint_9(Actor *, s32, s32, s32);) BT_NATIVE_ONLY(void _chdoormake_entrypoint_9(Actor *, s32, u16, s32);)
    void func_800EFD24(f32 [3]);
    void func_80103014(u8 *);
    f32 sp2C;

    sp2C = 0.0f;
    func_800EFD24(arg0->position);
    func_80103014(arg0);
    if (arg0->unk74_7 == 0x32) {
        sp2C = 180.0f;
    }
    if (_chdoormake_entrypoint_3(arg0, sp2C, 0.0f, 600.0f, 0x21, 0x403) != 0) {
        _chdoormake_entrypoint_6(arg0, 0x408CCCCD);
        _chdoormake_entrypoint_5(arg0, 3.0f);
        if (arg0->unk74_7 == 0x32) {
            _chdoormake_entrypoint_8(arg0, 0xD);
            _chdoormake_entrypoint_9(arg0, 0, 1, 0x10);
        }
    }
}

/* extern */

void func_808000D4_chhagstraindoor(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _chdoor_entrypoint_1(BtIntPtr, s32, BtIntPtr);
    s32 func_80103140(Actor *, u32, u16);

    if (arg1 == 0x95) {
        func_80103140(arg0, ((arg0->unk74_7 == 0x32) ? 0x94F : 0x950) & 0xFFFF, 0);
    }
    _chdoor_entrypoint_1((BtIntPtr)arg0, arg1, arg2);
}

OSThread *chhagstraindoor_entrypoint_0(void)
{
    extern ActorData D_80800150_chhagstraindoor[];

    return (OSThread *) D_80800150_chhagstraindoor;
}
/* data_to_c.py: from asm/data/overlays/ch/hagstraindoor.data.s */
void _chdoor_entrypoint_0();
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
ActorData D_80800150_chhagstraindoor [1] BT_DATA(4, overlays_ch_hagstraindoor, 0x0) = { { 881, 908, -1, 1, 0, (void (*)(struct Actor *))_chdoor_entrypoint_0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 3072, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800000_chhagstraindoor, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 11266, (void (*)(struct Actor *, long, long))func_808000D4_chhagstraindoor, 0 } };
