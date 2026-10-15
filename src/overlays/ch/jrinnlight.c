#include "common.h"

void func_80800000_chjrinnlight(u8 *arg0) {
    void func_800C8B84(s32);
    s32 temp_a1;

    temp_a1 = (*(s32 *)((s8 *)(arg0) + (0x58)));
    if (temp_a1 != 0) {
        func_800C8B84(temp_a1);
        (*(s32 *)((s8 *)(arg0) + (0x58))) = 0;
    }
}

/* extern */

s32 func_80800038_chjrinnlight(Actor *arg0, s32 arg1, s32 arg2) {
    s32 func_800C8A98();
    void func_800C8CB8(s32, f32[3]);
    void func_800C8E54(s32, f32, f32);
    void func_800C8F64(s32, s32);
    void func_800C8FB0(s32, u32, u32, u32);
    s32 func_800DA298(s32);
    s32 temp_v0;

    if (arg1 == 0x95) {
        if (func_800DA298(0x3A9) != 0) {
            temp_v0 = func_800C8A98();
            *(s32 *)&arg0->unk58 = temp_v0;
            func_800C8CB8(temp_v0, arg0->position);
            func_800C8E54(*(s32 *)&arg0->unk58, 500.0f, 700.0f);
            func_800C8FB0(*(s32 *)&arg0->unk58, 0xFF, 0xFF, 0xFF);
            func_800C8F64(*(s32 *)&arg0->unk58, 0xB);
            return 1;
        } else {
            *(s32 *)&arg0->unk58 = 0;
        }
    } else {
        return 0;
    }
    return 1;
}

OSThread *chjrinnlight_entrypoint_0(void)
{
    extern u8 D_808000F0_chjrinnlight[];

    return (OSThread *) D_808000F0_chjrinnlight;
}
