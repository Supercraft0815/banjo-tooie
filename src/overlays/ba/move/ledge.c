#include "common.h"

s32 bamoveledge_entrypoint_0() 
{
    return 0x4;
}

void bamoveledge_entrypoint_1(s32 arg0) 
{
}
void bamoveledge_entrypoint_2(s32 arg0) 
{
}
/* extern */

void bamoveledge_entrypoint_3(s32 arg0) {
    void func_8009B98C(void *, f32 *);
    void func_8009BB24(void *, f32 *);
    void func_8009BC08(void *, f32 *);
    f32 func_800D8FF8();
    void func_800EF04C(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    f32 sp2C[3];
    f32 sp20[3];

    func_8009BC08((void *)arg0, sp20);
    func_8009BB24(arg0, sp2C);
    func_800EF334(sp2C, func_800D8FF8());
    func_800EF04C(sp20, sp2C);
    func_8009B98C((void *)arg0, sp20);
}
