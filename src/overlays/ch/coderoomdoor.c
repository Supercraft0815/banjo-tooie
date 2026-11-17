#include "common.h"

OSThread *chcoderoomdoor_entrypoint_0(void)
{
    extern ActorData D_808000E0_chcoderoomdoor[];

    return (OSThread *) D_808000E0_chcoderoomdoor;
}

s32 func_8080000C_chcoderoomdoor(Actor *arg0, s32 arg1, s32 arg2) {
    f32 sp34[3];
    f32 *sp2C[2];
    extern s32 D_80800128_chcoderoomdoor[];
    extern u8 D_80800170_chcoderoomdoor[];
    void _chexploder_entrypoint_3(void *, void *, u32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    void func_800DA544(s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);

    switch (arg1) {
        case 0x40: {
            func_800EE7F8(sp34, arg0->position);
            func_800EF1B8(sp34, arg0->rotation[1], -100.0f);
            _chexploder_entrypoint_3(arg0, sp34, 15);
            break;
        }
        case 0x90: {
            sp2C[0] = arg0->position; func_800BABB8(0, sp2C[0], sp2C[0], 1.0f, D_80800128_chcoderoomdoor);
            _subaddieaudioquick_entrypoint_2(arg0, sp2C[0], D_80800170_chcoderoomdoor);
            func_800DA544(0x366);
            break;
        }
        default:
            return 0;
    }
    return 1;
}
/* data_to_c.py: from asm/data/overlays/ch/coderoomdoor.data.s */
void func_80102EC0();
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
OSThread *func_80108ED0(void);
void func_80107C2C();
ActorData D_808000E0_chcoderoomdoor [1] BT_DATA(4, overlays_ch_coderoomdoor, 0x0) = { { 409, 272, 1617, 1, 0, (void (*)(struct Actor *))func_80102EC0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 870, 0, 0, 2048, 0, (BtIntPtr)func_80108ED0, 0, 0, 0, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 10240, (void (*)(struct Actor *, long, long))func_8080000C_chcoderoomdoor, 0 } };
s32 D_80800128_chcoderoomdoor [18] BT_DATA(4, overlays_ch_coderoomdoor, 0x48) = { 84934685, 165478443, 50332672, 2228736, 41944576, 134217749, 153, 1638400, 458796, -1310700, -1310700, 2621460, 2143412, -1264582646, -13107175, -13107000, 4915400, 85590016 };
u8 D_80800170_chcoderoomdoor [16] BT_DATA(4, overlays_ch_coderoomdoor, 0x90) = { 0, 0x13, 4, 0xF4, 0, 0x18, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
