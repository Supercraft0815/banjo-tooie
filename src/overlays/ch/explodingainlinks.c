#include "common.h"

OSThread *chexplodingchainlinks_entrypoint_0(void)
{
    extern ActorData D_80800170_chexplodingchainlinks[];

    return (OSThread *) D_80800170_chexplodingchainlinks;
}

void func_8080000C_chexplodingchainlinks(s32 arg0) 
{
}
void func_80800014_chexplodingchainlinks(s32 arg0)
{
    _subaddieDll_entrypoint_7(arg0,0xB);
}

void func_80800034_chexplodingchainlinks(Actor *arg0, void *arg1) {
    void func_800E3A58(f32 *);
    void func_80101870(Actor *, void *);
    f32 sp1C[3];

    func_800E3A58(sp1C);
    arg0->rotation[1] = sp1C[1];
    func_80101870(arg0, arg1);
}

int func_80800070_chexplodingchainlinks(BtIntPtr arg0, s32 arg1, volatile s32 arg2) {
    void func_80101038(f32 *);
    void *func_80101080(void);
    Actor *func_80106790(Unk80132ED0 *);
    void func_8080010C_chexplodingchainlinks(BtIntPtr, f32 *);
    void _chexploder_entrypoint_3(void *, void *, u32);
    void _chexploder_entrypoint_6(Actor *, f32, f32);
    f32 sp24[3];
    int result = 1;

    switch (arg1) {
    case 5:
        func_80101038(sp24);
        func_8080010C_chexplodingchainlinks(arg0, sp24);
        _chexploder_entrypoint_3(arg0, sp24, 8);
        result = 1;
        break;
    case 0x90:
        _chexploder_entrypoint_6(func_80106790(func_80101080()), 300.0f, 400.0f);
        result = 1;
        break;
    default:
        return 0;
        break;
    }
    return result;
}

void func_8080010C_chexplodingchainlinks(BtIntPtr arg0, f32 *arg1) {
    BtIntPtr func_800BBCB8(f32 *arg0, f32 *arg1, f32 arg2, s32 arg3, s32 *arg4);
    void func_800EE7F8(f32 *, f32 *);
    extern s32 D_808001B8_chexplodingchainlinks[14];
    f32 sp24[3];

    func_800EE7F8(sp24, (f32 *)(arg0 + 4));
    sp24[1] = arg1[1];
    func_800BBCB8(sp24, sp24, 0.8f, 4, D_808001B8_chexplodingchainlinks);
}
/* data_to_c.py: from asm/data/overlays/ch/explodingainlinks.data.s */
void func_80105834(Actor*);
void func_80107C2C();
ActorData D_80800170_chexplodingchainlinks [1] BT_DATA(4, overlays_ch_explodingainlinks, 0x0) = { { 344, 1139, 1980, 1, 0, (void (*)(struct Actor *))func_80800014_chexplodingchainlinks, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80800034_chexplodingchainlinks, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, (void (*)(struct Actor *))func_8080000C_chexplodingchainlinks, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 2, (void (*)(struct Actor *, long, long))func_80800070_chexplodingchainlinks, 0 } };
s32 D_808001B8_chexplodingchainlinks[14] BT_DATA(4, overlays_ch_explodingainlinks, 0x48) = { 1903074, 2228262, 2490393, 1638439, 200, 240, 1376256, 13369387, 21758387, 2949370, 26214414, 655380, 1834008, -52428800 };
