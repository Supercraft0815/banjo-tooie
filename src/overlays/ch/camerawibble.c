#include "common.h"

OSThread *chcamerawibble_entrypoint_0(void)
{
    extern u8 D_808000E0_chcamerawibble[];

    return (OSThread *) D_808000E0_chcamerawibble;
}

void func_8080000C_chcamerawibble(void *arg0) {
    *(f32 *)((u8 *)arg0 + 0x24) = (f32)((u32)*(u16 *)((u8 *)arg0 + 0x76) >> 7) * 10.0f;
    *(f32 *)((u8 *)arg0 + 0x54) = *(f32 *)((u8 *)arg0 + 0x38);
}

void func_8080006C_chcamerawibble();

void func_8080004C_chcamerawibble()
{
    func_8080006C_chcamerawibble();
}

void func_8080006C_chcamerawibble(Actor *arg0) {
    f32 func_80013970(f32);
    void func_800C4B90(s32, f32, f32);
    f32 func_800D8FF8(void);
    f32 temp_f2;
    f32 delta;

    temp_f2 = func_80013970(arg0->unk58) * arg0->unk54;
    func_800C4B90(0, temp_f2, -temp_f2);
    delta = func_800D8FF8();
    arg0->unk58 += delta * ((f32 *)arg0->actorData)[3];
}
