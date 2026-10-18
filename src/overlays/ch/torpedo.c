#include "common.h"

void func_80800000_chtorpedo(u8 *arg0, u8 *arg1)
{
  s32 _fxairbub_entrypoint_1(f32 *, f32, f32, f32);
  s32 _fxdlsmoke_entrypoint_0(u8 *);
  s32 *new_var;
  s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
  extern s32 D_808008F4_chtorpedo;
  extern s32 D_80800918_chtorpedo;
  f32 temp_f0;
  u8 *temp_s0;
  u8 *temp_s0_2;
  temp_f0 = *((f32 *) (((s8 *) arg0) + 8));
  temp_s0 = arg0 + 4;
  if ((*((f32 *) (((s8 *) arg0) + 8))) < (*((f32 *) (((s8 *) arg1) + 0x24))))
  {
    temp_s0_2 = arg0 + 4;
 new_var = &D_808008F4_chtorpedo; func_800BABB8(_fxairbub_entrypoint_1(temp_s0_2, 5.0f, (*((f32 *) (((s8 *) arg0) + 8))) + 200.0f, 1.0f), temp_s0_2, 0, 1.0f, new_var); return;
  }
  func_800BABB8(_fxdlsmoke_entrypoint_0(temp_s0), temp_s0, 0, 1.0f, &D_80800918_chtorpedo);
}

void func_808000B8_chtorpedo(Actor *arg0) {
    s32 _fxairbub_entrypoint_1(f32 *, f32, f32, f32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    s32 func_800E1610(s32, f32, f32, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EFA98(f32[3], f32[3], f32);
    void *func_80100094(Actor *, u32);
    extern s32 D_80800840_chtorpedo;
    extern s32 D_808008B4_chtorpedo;
    void *sp44;
    f32 sp38[3];

    sp44 = func_80100094(arg0, 0);
    if (*(s32 *)((u8 *)sp44 + 0x28) == 0) {
        func_800E1610(0, 20.0f, 0.6f, arg0->position);
        func_800EFA98(sp38, (f32 *)((u8 *)arg0 + 0x28), -70.0f);
        func_800EF04C(sp38, arg0->position);
        func_800BABB8(0, sp38, NULL, 1.0f, &D_808008B4_chtorpedo);
        func_800EFA98(sp38, (f32 *)((u8 *)arg0 + 0x28), -50.0f);
        func_800EF04C(sp38, arg0->position);
        if (arg0->position[1] < *(f32 *)((u8 *)sp44 + 0x24)) {
            func_800BABB8(_fxairbub_entrypoint_1(sp38, 100.0f, sp38[1] + 200.0f, 1.0f), sp38, arg0->position, 1.0f, &D_80800840_chtorpedo);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/torpedo/func_808001E0_chtorpedo.s")

void func_80800350_chtorpedo(Actor *arg0) {
    void func_800F1A88(f32 *, f32 *);
    f32 sp18[2];

    func_800F1A88((f32 *)((s8 *)arg0 + 0x28), sp18);
    arg0->rotation[0] = -sp18[0];
    arg0->rotation[1] = sp18[1];
}

/* extern */

void func_80800394_chtorpedo(s32 *arg0) {
    void *func_80100094(Actor *, u32);
    void *temp_v0;

    temp_v0 = func_80100094(arg0, 0);
    if ((*(s32 (**)(s32, s32, s32))((s8 *)(temp_v0) + (0x2C))) != NULL) {
        (*(s32 (**)(s32, s32, s32))((s8 *)(temp_v0) + (0x2C)))(*arg0, 5, (*(s32 *)((s8 *)(temp_v0) + (0x30))));
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/torpedo/func_808003DC_chtorpedo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/torpedo/chtorpedo_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/torpedo/func_80800720_chtorpedo.s")

OSThread *chtorpedo_entrypoint_1(void)
{
    extern u8 D_8080095C_chtorpedo[];

    return (OSThread *) D_8080095C_chtorpedo;
}
