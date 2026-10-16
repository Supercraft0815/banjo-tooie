#include "common.h"

OSThread *chexplodingchainlinks_entrypoint_0(void)
{
    extern u8 D_80800170_chexplodingchainlinks[];

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

int func_80800070_chexplodingchainlinks(s32 arg0, s32 arg1, volatile s32 arg2) {
    void func_80101038(f32 *);
    void *func_80101080(void);
    Actor *func_80106790(Unk80132ED0 *);
    void func_8080010C_chexplodingchainlinks(s32, f32 *);
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

void func_8080010C_chexplodingchainlinks(s32 arg0, f32 *arg1) {
    void func_800BBCB8(f32[3], f32[3], f32, s32, s32 *);
    void func_800EE7F8(f32 *, f32 *);
    extern s32 D_808001B8_chexplodingchainlinks;
    f32 sp24[3];

    func_800EE7F8(sp24, (f32 *)(arg0 + 4));
    sp24[1] = arg1[1];
    func_800BBCB8(sp24, sp24, 0.8f, 4, &D_808001B8_chexplodingchainlinks);
}
