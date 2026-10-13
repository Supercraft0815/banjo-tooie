#include "common.h"

OSThread *charmouredcaveman_entrypoint_0(void)
{
    extern u8 D_80800B20_charmouredcaveman[];

    return (OSThread *) D_80800B20_charmouredcaveman;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/armouredcaveman/func_8080000C_charmouredcaveman.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/armouredcaveman/func_808000EC_charmouredcaveman.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/armouredcaveman/func_80800370_charmouredcaveman.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/armouredcaveman/func_80800640_charmouredcaveman.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/armouredcaveman/func_8080072C_charmouredcaveman.s")

void func_808008B0_charmouredcaveman(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    void func_80018820(s32, f32, f32);
    s32 func_800E15CC(s32, f32, f32);
    extern u32 D_80800C08_charmouredcaveman, D_80800C14_charmouredcaveman;
    f32 *position[1];

    position[0] = arg0->position;
    _subaddieaudioquick_entrypoint_3(arg0, position[0], &D_80800C08_charmouredcaveman, 0.3f);
    if (_subaddieaudioquick_entrypoint_3(arg0, position[0], &D_80800C14_charmouredcaveman, 0.5f)) {
        func_80018820(0, 1.0f, 0.4f);
        func_800E15CC(0, 20.0f, 0.85f);
    }
}

void func_8080092C_charmouredcaveman(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    extern u32 D_80800C20_charmouredcaveman;
    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80800C20_charmouredcaveman, 0.1f);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/armouredcaveman/func_8080095C_charmouredcaveman.s")

/* extern */

void func_808009D4_charmouredcaveman(Actor *arg0) {
    void func_8080095C_charmouredcaveman(void);
    if (arg0->unk70_10 != 3) {
        if (arg0->unk70_10 == 4) {
            arg0->unk64_19 = 1;
            return;
        }
        func_8080095C_charmouredcaveman();
    }
}
