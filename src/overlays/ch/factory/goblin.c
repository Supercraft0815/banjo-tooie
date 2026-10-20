#include "common.h"

OSThread *chfactorygoblin_entrypoint_0(void)
{
    extern u8 D_80800298_chfactorygoblin[];

    return (OSThread *) D_80800298_chfactorygoblin;
}

/* extern */

void func_8080000C_chfactorygoblin(u8 *arg0) {
    void func_8010A3E8(void *arg0, f32 arg1);
    s32 _sucoaster_entrypoint_0(void *, s32);
    _sucoaster_entrypoint_0(arg0, 0);
    func_8010A3E8(arg0, 0.75f);
}

/* extern */

void func_8080003C_chfactorygoblin(s32 arg0, s32 arg1, s32 arg2) {
    s32 _sucoaster_entrypoint_21(s32, s32, s32);
    s32 func_8080007C_chfactorygoblin();
    if (arg1 == 0xB6) {
        func_8080007C_chfactorygoblin();
    }
    _sucoaster_entrypoint_21(arg0, arg1, arg2);
}

s32 func_8080007C_chfactorygoblin(Actor *arg0) {
    s32 func_800B53A4(s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    s32 func_800DC128(s32, s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EEB9C(f32[3], f32, f32);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    extern s32 D_808002E0_chfactorygoblin;
    f32 sp84[3];
    f32 sp78[3];
    f32 sp6C[3];
    s32 temp_s3;
    s32 temp_s4;
    s32 var_s1;

    temp_s4 = func_800DC128(6, 8);
    func_800EE7F8(sp84, arg0->position);
    func_800EF1B8(sp84, arg0->rotation[1], arg0->scale * 200.0f);
    func_800EE7F8(sp78, sp84);
    sp78[1] -= 5.0f;
    temp_s3 = func_800B53A4(temp_s4);
    var_s1 = 0;
    if (temp_s4 > 0) {
        do {
            func_800EEB9C(sp6C, (f32)var_s1 * (360.0f / (f32)temp_s4), 20.0f);
            func_800EF04C(sp6C, sp84);
            func_800BABB8(temp_s3, sp6C, sp78, arg0->scale * 0.5f, &D_808002E0_chfactorygoblin);
            var_s1++;
        } while (var_s1 != temp_s4);
    }
}
