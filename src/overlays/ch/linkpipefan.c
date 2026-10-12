#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/linkpipefan/func_80800000_chlinkpipefan.s")

void func_80800080_chlinkpipefan(u8 *arg0) {
    s32 _glid_entrypoint_0(s32, s32, s32 *, s32);
    void _subaddieaudioloop_entrypoint_0(Actor *, f32);
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    f32 func_800136E4(f32);
    void func_800C4208(s32, f32, u32, f32 *, f32, f32);
    f32 func_800D8FF8(void);
    s32 func_800D90A4(f32 *);
    s32 func_800D90F8(f32 *, f32);
    s32 func_800D91EC(u8 *, f32);
    f32 func_800DC178(f32, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F13C4(f32, f32);
    f32 func_800F1FF0(f32, f32, f32, f32, f32);
    s32 func_801065A4();
    void func_8010A654(u8 *, u32);
    void func_808003B4_chlinkpipefan(u8 *, s32);
    extern u32 D_80800910_chlinkpipefan;
    extern s32 _chlinkpipefan_entrypoint_0;
    struct counter {
        u32 : 23;
        u32 value : 9;
    };

    switch ((u32)*(u16 *)(arg0 + 0x72) >> 10) {
        case 1:
            *(f32 *)(arg0 + 0x4C) = func_800F1FF0(*(f32 *)(arg0 + 0x4C), 0.0f, 0.1f, 0.1f, 3.0f);
            break;
        case 2:
            if (func_800D91EC(arg0 + 0x34, 1.5f)) {
                *(f32 *)(arg0 + 0x54) = 450.0f;
            } else {
                *(f32 *)(arg0 + 0x54) = func_800F10B4(*(f32 *)(arg0 + 0x34), 1.5f, 0, 450.0f, 0);
            }
            break;
        case 3:
            if (func_800D90F8((f32 *)(arg0 + 0x34), 0.75f)) {
                if (func_800D90A4((f32 *)(arg0 + 0x58))) {
                    func_808003B4_chlinkpipefan(arg0, 2);
                }
            } else {
                *(f32 *)(arg0 + 0x54) = func_800F10B4(*(f32 *)(arg0 + 0x34), 1.5f, 0, 450.0f, 0);
            }
            break;
        case 4:
            if (func_800D90A4((f32 *)(arg0 + 0x34))) {
                *(f32 *)(arg0 + 0x54) = 0.0f;
                if (func_800D90A4((f32 *)(arg0 + 0x58))) {
                    func_808003B4_chlinkpipefan(arg0, 2);
                }
            } else {
                *(f32 *)(arg0 + 0x54) = func_800F10B4(*(f32 *)(arg0 + 0x34), 1.5f, 0, 450.0f, 0);
            }
            break;
    }
    *(f32 *)(arg0 + 0x24) = *(f32 *)(arg0 + 0x4C);
    *(f32 *)(arg0 + 0x4C) = func_800136E4(*(f32 *)(arg0 + 0x4C) + *(f32 *)(arg0 + 0x54) * func_800D8FF8());
    if (func_800F13C4(*(f32 *)(arg0 + 0x24), 90.0f) > func_800F13C4(*(f32 *)(arg0 + 0x4C), 90.0f)) {
        if (*(f32 *)(arg0 + 0x54) > 225.0f) {
            func_800C4208(0x3FF, func_800F10B4(*(f32 *)(arg0 + 0x54), 225.0f, 450.0f, 0.3f, 0.6f) + func_800DC178(-0.05f, 0.05f), 0x4A38, (f32 *)(arg0 + 4), 200.0f, 1500.0f);
        }
    }
    if (*(f32 *)(arg0 + 0x54) != 0.0f) {
        _subaddieaudioloop_entrypoint_4((Actor *)arg0, (f32 *)(arg0 + 4), 1, &D_80800910_chlinkpipefan);
        _subaddieaudioloop_entrypoint_0((Actor *)arg0, func_800F10B4(*(f32 *)(arg0 + 0x54), 225.0f, 450.0f, 0.4f, 0.8f));
    }
    if (((struct counter *)(arg0 + 0x6C))->value != 0) {
        ((struct counter *)(arg0 + 0x6C))->value--;
    }
    if (func_801065A4(arg0)) {
        _glid_entrypoint_0(func_801065A4(arg0), 1, &_chlinkpipefan_entrypoint_0, *(s32 *)arg0);
    }
    func_8010A654(arg0, ((u32)*(u16 *)(arg0 + 0x72) >> 10) == 4);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/linkpipefan/func_808003B4_chlinkpipefan.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/linkpipefan/chlinkpipefan_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/linkpipefan/func_80800638_chlinkpipefan.s")

OSThread *chlinkpipefan_entrypoint_1(void)
{
    extern u8 D_808009C8_chlinkpipefan[];

    return (OSThread *) D_808009C8_chlinkpipefan;
}
