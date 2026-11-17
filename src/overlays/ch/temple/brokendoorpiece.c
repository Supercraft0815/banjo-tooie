#include "common.h"

void func_80800000_chtemplebrokendoorpiece(s32 arg0) 
{
}
void func_80800008_chtemplebrokendoorpiece(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    void func_800DA544(GameFlag);
    extern s32 D_80800100_chtemplebrokendoorpiece[5];
    extern s32 D_80800114_chtemplebrokendoorpiece[18];
    func_800BABB8(0, arg0->position, arg0->position, arg0->scale, D_80800114_chtemplebrokendoorpiece);
    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800100_chtemplebrokendoorpiece);
    func_800DA544(0xC9);
}
/* extern */

int func_80800068_chtemplebrokendoorpiece(Actor *arg0, s32 arg1, s32 arg2) {
    void _chexploder_entrypoint_3(void *, void *, u32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    f32 position[3];
    int result;

    if (arg1 == 0x40) {
        func_800EE7F8(position, arg0->position);
        func_800EF1B8(position, arg0->rotation[1], 400.0f);
        position[1] -= 100.0f;
        _chexploder_entrypoint_3(arg0, position, 0xC);
        func_80800008_chtemplebrokendoorpiece(arg0);
        result = 1;
    } else {
        return 0;
    }
    return result;
}

OSThread *chtemplebrokendoorpiece_entrypoint_0(void)
{
    extern ActorData D_8080015C_chtemplebrokendoorpiece[];

    return (OSThread *) D_8080015C_chtemplebrokendoorpiece;
}
/* data_to_c.py: from asm/data/overlays/ch/temple/brokendoorpiece.data.s */
void func_80102EC0();
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
OSThread *func_80108ED0(void);
void func_80107C2C();
s32 D_80800100_chtemplebrokendoorpiece[5] BT_DATA(4, overlays_ch_temple_brokendoorpiece, 0x0) = { 1246227, 655590, 1469792, 66786, 163840000 };
s32 D_80800114_chtemplebrokendoorpiece[18] BT_DATA(4, overlays_ch_temple_brokendoorpiece, 0x14) = { 84934685, 165478443, 50332672, 2228736, 41944576, 134217749, 153, 1638400, 458796, -1310700, -1310700, 2621460, 2130612, -1264582646, -13107175, -13107000, 4915400, 85590016 };
ActorData D_8080015C_chtemplebrokendoorpiece [1] BT_DATA(4, overlays_ch_temple_brokendoorpiece, 0x5C) = { { 407, 298, 1622, 1, 0, (void (*)(struct Actor *))func_80102EC0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 201, 0, 0, 3072, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_80800000_chtemplebrokendoorpiece, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 11264, (void (*)(struct Actor *, long, long))func_80800068_chtemplebrokendoorpiece, 0 } };
