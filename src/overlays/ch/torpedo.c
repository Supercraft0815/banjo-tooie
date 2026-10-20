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

void func_808001E0_chtorpedo(Actor *arg0, s32 arg1) {
    s32 _chlightfader_entrypoint_1(s32, f32, s32);
    s32 func_800C8A98(void);
    void func_800C8CB8(s32, f32 *);
    void func_800C8E54(s32, f32, f32);
    void func_800C8E84(s32, u32 *);
    void func_800CB840(s32, s32);
    void func_800CB870(void);
    void func_800EF04C(f32 *, f32 *);
    void func_800EFA98(f32[3], f32[3], f32);
    int func_800F7A7C(s32, s32, s32, s32, f32 *);
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    void func_80109BEC(s32, f32, s32, s32, s32, s32);
    s32 func_8010CC10(f32 *, f32);
    void func_8010CCE0(void);
    s32 func_8010CCEC(void);
    extern u32 D_80800950_chtorpedo;
    s32 sp4C;
    s32 pad;
    f32 sp3C[3];
    s32 current;

    if (arg1 != arg0->unk70_10) {
        func_80101FDC(arg0, arg1);
        if (arg0->unk70_10 == 3) {
            sp4C = func_800C8A98();
            func_800C8E84(sp4C, &D_80800950_chtorpedo);
            func_800C8CB8(sp4C, arg0->position);
            func_800C8E54(sp4C, 300.0f, 750.0f);
            func_800CB840(6, arg0);
            func_80109BEC(arg0->position, 150.0f, 2, 0, 0, arg0->unk0);
            if (func_8010CC10(arg0->position, 150.0f)) {
                func_800EFA98(sp3C, (f32 *)&arg0->actorData[4], -200.0f);
                func_800EF04C(sp3C, arg0->position);
                func_8010CCE0();
                current = func_8010CCEC();
                while (current != -1) {
                    func_800F7A7C(current, *(s8 *)func_80100094(arg0, 0), 1, 7, sp3C);
                    current = func_8010CCEC();
                }
            }
            _chlightfader_entrypoint_1(sp4C, 1.0f, 1);
            func_800CB870();
            func_808000B8_chtorpedo(arg0);
        }
    }
}

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

s32 func_80800720_chtorpedo(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    void func_800FFAB0(Actor *);
    void func_80109EEC(s16 *, s32);
    struct TorpedoData {
        u8 pad0[0x28];
        s32 unk28;
        s32 (*unk2C)(Unk80132ED0 *, s32, s32);
        s32 unk30;
    } *data;

    data = func_80100094(arg0, 0);
    switch (arg1) {
        case 0x2C:
            data->unk2C = NULL;
            func_800FFAB0(arg0);
            break;
        case 5:
            func_808001E0_chtorpedo(arg0, 3);
            break;
        case 0x95:
            func_80109EEC(arg0, 0x10);
            break;
        case 0x78:
            if (data->unk2C != NULL) {
                data->unk2C(arg0->unk0, 0x78, data->unk30);
                data->unk2C = NULL;
            }
            func_800FFAB0(arg0);
            break;
        case 0x98:
            data->unk28 = 1;
            break;
        default:
            return 0;
    }
    return 1;
}

OSThread *chtorpedo_entrypoint_1(void)
{
    extern u8 D_8080095C_chtorpedo[];

    return (OSThread *) D_8080095C_chtorpedo;
}
