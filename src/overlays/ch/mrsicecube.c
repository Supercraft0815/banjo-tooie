#include "common.h"

OSThread *chmrsicecube_entrypoint_0(void)
{
    extern u8 D_8080099C_chmrsicecube[];

    return (OSThread *) D_8080099C_chmrsicecube;
}

OSThread *chmrsicecube_entrypoint_1(void)
{
    extern u8 D_808009E4_chmrsicecube[];

    return (OSThread *) D_808009E4_chmrsicecube;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mrsicecube/func_80800018_chmrsicecube.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mrsicecube/func_808000BC_chmrsicecube.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mrsicecube/func_80800260_chmrsicecube.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mrsicecube/func_808003BC_chmrsicecube.s")

s32 *func_8080043C_chmrsicecube(u8 *arg0, s32 arg1, f32 *arg2) {
    s32 *_subaddiefind_entrypoint_0(s32, s32, s32, s32);
    void func_800EE7F8(f32 *, f32 *);
    s32 *temp_v0;

    temp_v0 = _subaddiefind_entrypoint_0((s32)(arg0 + 4), arg1, -1, 0);
    if (temp_v0 != NULL) {
        func_800EE7F8(arg2, (f32 *)(temp_v0 + 1));
    }
    return temp_v0;
}

Unk80132ED0 *func_8080048C_chmrsicecube(u8 *arg0, s32 arg1, f32 *arg2) {
    Prop *_gccubesearch_entrypoint_6(s32 *, f32 *);
    Unk80132ED0 *_subaddiefind_entrypoint_12(s32);
    void func_800EE88C(f32 *, s16 *);
    extern s32 D_80800A3C_chmrsicecube;
    Prop *prop;
    Unk80132ED0 *actor;

    D_80800A3C_chmrsicecube = arg1;
    prop = _gccubesearch_entrypoint_6(&D_80800A3C_chmrsicecube, (f32 *)(arg0 + 4));
    if (prop == NULL) {
        return NULL;
    }
    actor = _subaddiefind_entrypoint_12(*(u32 *)&prop->unk10 >> 21);
    if (actor != NULL) {
        func_800EE88C(arg2, prop->position);
    }
    return actor;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mrsicecube/func_80800508_chmrsicecube.s")

void func_80800634_chmrsicecube(s32 arg0) {
    s32 _subaddiedialog_entrypoint_8(s32, void *, s32 *, s32 *, s32);
    extern s32 D_808008F0_chmrsicecube;
    extern s32 D_80800A44_chmrsicecube;
    _subaddiedialog_entrypoint_8(arg0, (s8 *)arg0 + 4, &D_80800A44_chmrsicecube, &D_808008F0_chmrsicecube, 4);
}

void func_8080066C_chmrsicecube(u8 *arg0, u8 *arg1)
{
  void func_800EE7F8(f32 *, f32 *);
  func_800EE7F8((f32 *)arg1, (f32 *)(arg0 + 4));
  *((f32 *) (((s8 *) arg1) + 4)) += (*((f32 *) (((s8 *) arg0) + 0x38))) * 100.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mrsicecube/func_808006C4_chmrsicecube.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mrsicecube/func_80800818_chmrsicecube.s")

void func_80800898_chmrsicecube(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    extern u32 D_80800AB8_chmrsicecube;
    _subaddieaudioquick_entrypoint_3(arg0, arg0->position, &D_80800AB8_chmrsicecube, 0.1f);
}
