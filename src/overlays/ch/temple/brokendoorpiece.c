#include "common.h"

void func_80800000_chtemplebrokendoorpiece(s32 arg0) 
{
}
void func_80800008_chtemplebrokendoorpiece(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    void func_800DA544(GameFlag);
    extern s32 D_80800100_chtemplebrokendoorpiece;
    extern s32 D_80800114_chtemplebrokendoorpiece;
    func_800BABB8(0, arg0->position, arg0->position, arg0->scale, &D_80800114_chtemplebrokendoorpiece);
    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80800100_chtemplebrokendoorpiece);
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
    extern u8 D_8080015C_chtemplebrokendoorpiece[];

    return (OSThread *) D_8080015C_chtemplebrokendoorpiece;
}
