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

void func_80800054_chmumboskullfakearchpanellava(BtIntPtr arg0) {
    s32 func_800DA298(s32);
    void func_800FFAB0(Actor *actor);
    s32 func_80800000_chmumboskullfakearchpanellava();
    if (func_800DA298(func_80800000_chmumboskullfakearchpanellava()) != 0) {
        func_800FFAB0(arg0);
    }
}

s32 func_8080008C_chmumboskullfakearchpanellava(Actor *arg0, s32 arg1, s32 arg2) {
    void _chexploder_entrypoint_3(void *, void *, u32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    void func_800C4AF0(f32 *, void *);
    void func_800DA544(s32 index);
    extern s32 D_80800160_chmumboskullfakearchpanellava[27];
    extern s32 D_808001CC_chmumboskullfakearchpanellava[5];
    f32 *temp_s0;
    s32 result;

    if (arg1 == 0x40) {
        temp_s0 = arg0->position;
        _chexploder_entrypoint_3(arg0, temp_s0, 0xC);
        func_800BABB8(0, temp_s0, temp_s0, arg0->scale, D_80800160_chmumboskullfakearchpanellava);
        func_800C4AF0(temp_s0, D_808001CC_chmumboskullfakearchpanellava);
        func_800DA544(func_80800000_chmumboskullfakearchpanellava());
        result = 1;
    } else {
        return 0;
    }
    return result;
}

OSThread *chmumboskullfakearchpanellava_entrypoint_0(void)
{
    extern ActorData D_808001E0_chmumboskullfakearchpanellava[];

    return (OSThread *) D_808001E0_chmumboskullfakearchpanellava;
}

/* extern */

void func_8080012C_chmumboskullfakearchpanellava(BtIntPtr arg0) {
    void func_800EFD24(f32 vec[3]);
    func_800EFD24(arg0 + 0x4);
}

OSThread *chmumboskullfakearchpanellava_entrypoint_1(void)
{
    extern ActorData D_80800228_chmumboskullfakearchpanellava[];

    return (OSThread *) D_80800228_chmumboskullfakearchpanellava;
}
/* data_to_c.py: from asm/data/overlays/ch/mumbo/skullfakearchpanellava.data.s */
void func_80102EC0();
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
OSThread *func_80108ED0(void);
void func_80107C2C();
s32 D_80800160_chmumboskullfakearchpanellava[27] BT_DATA(4, overlays_ch_mumbo_skullfakearchpanellava, 0x0) = { 101711901, 165478443, 33555200, 2228608, 33555584, 100663317, 38, 1638400, 458797, 3276900, 2154151, 1908408330, -6553575, -6553500, 4915300, 102373648, 1902240, 1310765, 26215000, 1834208, -39321566, 11731148, 11731123, 1966130, 3276813, 4921626, 0 };
s32 D_808001CC_chmumboskullfakearchpanellava[5] BT_DATA(4, overlays_ch_mumbo_skullfakearchpanellava, 0x6C) = { 1246227, 655590, 1469792, 72036, 425984000 };
ActorData D_808001E0_chmumboskullfakearchpanellava [1] BT_DATA(4, overlays_ch_mumbo_skullfakearchpanellava, 0x80) = { { 172, 640, 2274, 1, 0, (void (*)(struct Actor *))func_80102EC0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 4096, 2048, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_80800054_chmumboskullfakearchpanellava, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 11264, (void (*)(struct Actor *, long, long))func_8080008C_chmumboskullfakearchpanellava, 0 } };
ActorData D_80800228_chmumboskullfakearchpanellava [1] BT_DATA(4, overlays_ch_mumbo_skullfakearchpanellava, 0xC8) = { { 172, 1173, 2275, 1, 0, 0, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 4096, 3072, 0, 0, 0, 0, (void (*)(struct Actor *))func_8080012C_chmumboskullfakearchpanellava, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 11266, 0, 0 } };
