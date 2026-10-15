#include "common.h"

/* extern */

s32 func_80800000_chmumboskullfakearchpanellava(void) {
    s32 func_800EA05C();
    if (func_800EA05C() == 0x134) {
        return 0x39C;
    }
    if (func_800EA05C() == 0xEF) {
        return 0x39D;
    }
    return 0;
}

/* extern */

void func_80800054_chmumboskullfakearchpanellava(s32 arg0) {
    s32 func_800DA298(s32);
    s32 func_800FFAB0(s32);
    s32 func_80800000_chmumboskullfakearchpanellava();
    if (func_800DA298(func_80800000_chmumboskullfakearchpanellava()) != 0) {
        func_800FFAB0(arg0);
    }
}

s32 func_8080008C_chmumboskullfakearchpanellava(Actor *arg0, s32 arg1, s32 arg2) {
    void _chexploder_entrypoint_3(void *, void *, u32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    void func_800C4AF0(f32 *, void *);
    s32 func_800DA544(s32);
    extern s32 D_80800160_chmumboskullfakearchpanellava;
    extern s32 D_808001CC_chmumboskullfakearchpanellava;
    f32 *temp_s0;
    s32 result;

    if (arg1 == 0x40) {
        temp_s0 = arg0->position;
        _chexploder_entrypoint_3(arg0, temp_s0, 0xC);
        func_800BABB8(0, temp_s0, temp_s0, arg0->scale, &D_80800160_chmumboskullfakearchpanellava);
        func_800C4AF0(temp_s0, &D_808001CC_chmumboskullfakearchpanellava);
        func_800DA544(func_80800000_chmumboskullfakearchpanellava());
        result = 1;
    } else {
        return 0;
    }
    return result;
}

OSThread *chmumboskullfakearchpanellava_entrypoint_0(void)
{
    extern u8 D_808001E0_chmumboskullfakearchpanellava[];

    return (OSThread *) D_808001E0_chmumboskullfakearchpanellava;
}

/* extern */

void func_8080012C_chmumboskullfakearchpanellava(s32 arg0) {
    s32 func_800EFD24(s32);
    func_800EFD24(arg0 + 0x4);
}

OSThread *chmumboskullfakearchpanellava_entrypoint_1(void)
{
    extern u8 D_80800228_chmumboskullfakearchpanellava[];

    return (OSThread *) D_80800228_chmumboskullfakearchpanellava;
}
