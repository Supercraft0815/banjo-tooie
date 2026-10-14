#include "common.h"

OSThread *chdippy_entrypoint_0(void)
{
    extern u8 D_80801580_chdippy[];

    return (OSThread *) D_80801580_chdippy;
}

OSThread *chdippy_entrypoint_1(void)
{
    extern u8 D_808015C8_chdippy[];

    return (OSThread *) D_808015C8_chdippy;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dippy/func_80800018_chdippy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dippy/func_808000D8_chdippy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dippy/func_80800374_chdippy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dippy/func_8080047C_chdippy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dippy/func_80800530_chdippy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dippy/func_80800654_chdippy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dippy/func_80800800_chdippy.s")

void func_80800948_chdippy(s32 *arg0) {
    s32 _subaddieaudioquick_entrypoint_3(s32 *, s32 *, s32 *, s32);
    s32 _subaddieskeleton_entrypoint_3(s32, s32, s32 *);
    extern s32 D_80801480_chdippy;
    s32 sp1C[3];

    _subaddieskeleton_entrypoint_3(*arg0, 5, sp1C);
    _subaddieaudioquick_entrypoint_3(arg0, sp1C, &D_80801480_chdippy, 0x3ECCCCCD);
}

void func_80800990_chdippy(s32 *arg0) {
    s32 _subaddieaudioquick_entrypoint_3(s32 *, s32 *, s32 *, s32);
    s32 _subaddieskeleton_entrypoint_3(s32, s32, s32 *);
    extern s32 D_80801490_chdippy;
    s32 sp1C[3];

    _subaddieskeleton_entrypoint_3(*arg0, 5, sp1C);
    _subaddieaudioquick_entrypoint_3(arg0, sp1C, &D_80801490_chdippy, 0x3E19999A);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dippy/func_808009D8_chdippy.s")

void chdippy_entrypoint_2(s32 arg0, s32 arg1) {
    s32 func_800BBCB8(s32, s32, s32, s32, s32 *);
    extern s32 D_808014B0_chdippy;
    func_800BBCB8(arg1, 0, 0x3F99999A, 1, &D_808014B0_chdippy);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dippy/func_80800CBC_chdippy.s")

void func_80800D44_chdippy(u8 *arg0) {
    struct Flags {
        u8 pad[0x64];
        unsigned int : 11;
        unsigned int active : 1;
        unsigned int : 20;
    };
    void _capod_entrypoint_14(void);
    if (((struct Flags *)arg0)->active) {
        _capod_entrypoint_14();
        arg0[0x65] &= 0xFFEF;
    }
}

void func_80800D84_chdippy(void *arg0) {
    (*(u8 *)((s8 *)(arg0) + (0x65))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x65))) & 0xFFFE);
    (*(f32 *)((s8 *)(arg0) + (0x1C))) = (f32) (*(f32 *)((s8 *)(arg0) + (8)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dippy/func_80800D9C_chdippy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dippy/func_80801110_chdippy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dippy/func_80801200_chdippy.s")

/* extern */

void chdippy_entrypoint_3(s32 arg0, Vtx *arg1, Vtx *arg2, s32 arg3, Unk80132ED0 *arg4) {
    Actor *func_80106790(Unk80132ED0 *);
    s16 offset;
    Vtx *end;

    offset = *(f32 *)&func_80106790(arg4)->actorData[0];
    end = arg2 + arg3;
    if (arg2 < end) {
        do {
            arg2++;
            arg1++;
            arg2[-1].v.ob[1] = arg1[-1].v.ob[1] + offset;
        } while (arg2 < end);
    }
}
