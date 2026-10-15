#include "common.h"

void func_80800000_chchuffyglow(Actor *arg0, s32 arg1) {
    typedef struct { f32 v[3]; } GlowVector;
    s32 _subaddiefade_entrypoint_0(Actor *);
    void func_8008B304(s32);
    s32 func_8008B4D4(struct anctrl_s *);
    void func_800D93A0(f32[4], f32[3]);
    void *func_800DE448(f32 *, f32 *, f32, f32 *, s32);
    void func_800DF410(s32);
    void func_800DF41C(s32);
    void func_800DF830(s32);
    void func_800DFF2C(u8 **, s32, f32[4]);
    void func_800DFFA0(s32 *, s32, s32);
    void *func_80100094(Actor *, u32);
    void func_80102780(void *, void *);
    s32 func_8010347C(Unk80132ED0 *);
    struct anctrl_s *func_80104248(void *);
    extern GlowVector D_80800550_chchuffyglow;
    extern GlowVector D_8080055C_chchuffyglow;
    GlowVector sp7C = D_80800550_chchuffyglow;
    GlowVector sp70 = D_8080055C_chchuffyglow;
    f32 sp60[4];
    struct anctrl_s *temp_s0;
    s32 temp_s3;
    s32 temp_v0;
    s32 var_s0;
    s32 var_s1;
    s32 var_s2;

    temp_s0 = func_80104248(arg0);
    temp_s3 = (s32)func_80100094(arg0, 0);
    func_80102780(arg0, sp70.v);
    func_8008B304((s32)temp_s0);
    temp_v0 = func_8008B4D4(temp_s0);
    func_800DFFA0((s32 *)temp_v0, 3, temp_s3);
    var_s0 = 0;
    var_s1 = temp_s3 + 0xC;
    var_s2 = temp_s3 + 0x48;
    do {
        func_800DFFA0((s32 *)temp_v0, (var_s0 + 0x2A), var_s1);
        func_800D93A0(sp60, (f32 *)var_s2);
        func_800DFF2C((u8 **)temp_v0, (var_s0 + 0x2A), sp60);
        var_s0 += 1;
        var_s1 += 0xC;
        var_s2 += 0x10;
    } while (var_s0 != 5);
    func_800DF830(2);
    func_800DF410(_subaddiefade_entrypoint_0(arg0));
    func_800DF41C(temp_v0);
    func_800DE448(sp7C.v, sp70.v, arg0->scale, NULL, func_8010347C(arg0->unk0));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/uffyglow/func_80800180_chchuffyglow.s")

void func_80800484_chchuffyglow(s32 arg0) 
{
}
void func_8080048C_chchuffyglow(s32 arg0) {
    s32 _subaddiefade_entrypoint_1(s32, s32);
    _subaddiefade_entrypoint_1(arg0, 0);
    ((Actor *)arg0)->unk58 = 5.0f;
    ((Actor *)arg0)->unk64_20 = 1;
}

/* extern */

void chchuffyglow_entrypoint_0(s32 arg0) {
    s32 *func_80106790();
    void *func_801084B0(s32, s32 **);
    s32 *sp24;
    s32 pad[2];

    sp24 = func_80106790();
    (*(s32 *)((s8 *)(func_801084B0(0x30E, &sp24)) + (0x3C))) = (s32) *sp24;
}

OSThread *chchuffyglow_entrypoint_1(void)
{
    extern u8 D_808005B0_chchuffyglow[];

    return (OSThread *) D_808005B0_chchuffyglow;
}
