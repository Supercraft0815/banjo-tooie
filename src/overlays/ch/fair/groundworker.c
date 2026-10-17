#include "common.h"

OSThread *chfairgroundworker_entrypoint_0(void)
{
    extern u8 D_80800308_chfairgroundworker[];

    return (OSThread *) D_80800308_chfairgroundworker;
}

OSThread *chfairgroundworker_entrypoint_1(void)
{
    extern u8 D_80800350_chfairgroundworker[];

    return (OSThread *) D_80800350_chfairgroundworker;
}

OSThread *chfairgroundworker_entrypoint_2(void)
{
    extern u8 D_80800398_chfairgroundworker[];

    return (OSThread *) D_80800398_chfairgroundworker;
}

OSThread *chfairgroundworker_entrypoint_3(void)
{
    extern u8 D_808003E0_chfairgroundworker[];

    return (OSThread *) D_808003E0_chfairgroundworker;
}

/* extern */

void func_80800030_chfairgroundworker(Actor *arg0) {
    s32 _sucoaster_entrypoint_0(void *, s32);
    void func_80102FDC(Actor *, f32);
    void func_8010A3E8(void *, f32);
    struct GroundworkerFlags { u32 : 15; u32 active : 1; u32 : 16; };
    _sucoaster_entrypoint_0(arg0, 0);
    func_80102FDC(arg0, arg0->scale * 0.85f);
    func_8010A3E8(arg0, 0.7f);
    ((struct GroundworkerFlags *)&arg0->pad94)->active = 1;
}

void func_80800098_chfairgroundworker(Actor *arg0) {
    s32 _chbadshad_entrypoint_3(Actor *, u8 *, s32, f32, s32 *);
    s32 _sucoaster_entrypoint_2();
    extern s32 D_80800428_chfairgroundworker;
    _sucoaster_entrypoint_2();
    if (arg0->unk7C_12) {
        _chbadshad_entrypoint_3(arg0, (u8 *)arg0 + 4, 3, arg0->scale * 1.5294117f, &D_80800428_chfairgroundworker);
    }
}

/* extern */

void func_808000FC_chfairgroundworker(s32 arg0, s32 arg1, s32 arg2) {
    s32 _sucoaster_entrypoint_21(s32, s32, s32);
    void func_8080013C_chfairgroundworker();
    if (arg1 == 0xB6) {
        func_8080013C_chfairgroundworker();
    }
    _sucoaster_entrypoint_21(arg0, arg1, arg2);
}

void func_8080013C_chfairgroundworker(Actor *arg0) {
    s32 func_800B53A4(s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EEB9C(f32[3], f32, f32);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    extern s32 D_80800430_chfairgroundworker;
    s32 temp_s3;
    f32 sp60[3];
    f32 sp54[3];
    s32 var_s0;

    func_800EE7F8(sp54, arg0->position);
    func_800EF1B8(sp54, arg0->rotation[1], arg0->scale * 300.0f);
    temp_s3 = func_800B53A4(5);
    for (var_s0 = 0; var_s0 != 5; var_s0++) {
        func_800EEB9C(sp60, (f32)var_s0 * 72.0f, 5.0f);
        func_800EF04C(sp60, sp54);
        func_800BABB8(temp_s3, sp60, sp54, 1.0f, &D_80800430_chfairgroundworker);
    }
}
