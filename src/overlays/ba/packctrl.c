#include "common.h"

void bapackctrl_entrypoint_5(BtIntPtr arg0, s32 arg1);
void func_800EFD24(f32 *);

s32 bapackctrl_entrypoint_0() 
{
    return 0x20;
}

void func_80800008_bapackctrl(u8 *arg0) {
    s32 bapackctrl_entrypoint_1(u8 *);
    void func_800984F0(u8 *, f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    f32 sp1C[3];

    if (bapackctrl_entrypoint_1(arg0)) {
        func_800EFA4C(sp1C, 1.7f, 1.7f, 2.6f);
    } else {
        func_800EFA4C(sp1C, 1.0f, 1.0f, 1.0f);
    }
    func_800984F0(arg0, sp1C);
}

/* extern */

s32 bapackctrl_entrypoint_1(u8 *arg0) {
    s32 func_8009EA58();
    return func_8009EA58();
}

void bapackctrl_entrypoint_2(BtIntPtr arg0)
{
    bapackctrl_entrypoint_5(arg0,0);
}

void bapackctrl_entrypoint_3(BtIntPtr arg0) {
    void func_80800008_bapackctrl(u8 *);
    f32 temp_f0;
    BtIntPtr temp_v0;

    temp_v0 = *(s32 *) (arg0 + 0xD8);
    temp_f0 = *(f32 *) (temp_v0 + 0xC);
    *(f32 *) (temp_v0 + 8) = temp_f0;
    *(f32 *) (*(s32 *) (arg0 + 0xD8) + 4) = temp_f0;
    *(f32 *) (*(s32 *) (arg0 + 0xD8) + 0) = temp_f0;
    func_800EFD24(*(s32 *) (arg0 + 0xD8) + 0x10);
    func_80800008_bapackctrl(arg0);
    *(s8 *) (*(s32 *) (arg0 + 0xD8) + 0x1C) = 0;
    bapackctrl_entrypoint_5(arg0, 1);
}

/* extern */

void bapackctrl_entrypoint_4(BtIntPtr arg0, s32 arg1) {
    void func_8009EADC(s32 arg0);
    void func_80800008_bapackctrl(u8 *);
    func_8009EADC(arg1);
    func_80800008_bapackctrl(arg0);
}

void bapackctrl_entrypoint_5(BtIntPtr arg0, s32 arg1) {
    void func_80098480(u8 *, s32, s32);
    void func_80098494(void *, f32, f32, f32, f32);
    void func_800984CC(void *, f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800EFD24(f32 *);
    f32 temp_f0;
    f32 *temp_v0;

    *(u8 *)(*(s32 *)(arg0 + 0xD8) + 0x1C) = arg1;
    switch (arg1) {
    case 0:
        func_80098480((u8 *)arg0, 0, 0);
        break;
    case 1:
        func_80098480((u8 *)arg0, 0, 0);
        break;
    case 2:
        func_80098480((u8 *)arg0, 1, 0);
        (*(f32 **)(arg0 + 0xD8))[0] = 80.0f;
        (*(f32 **)(arg0 + 0xD8))[1] = 13.0f;
        (*(f32 **)(arg0 + 0xD8))[2] = 50.0f;
        (*(f32 **)(arg0 + 0xD8))[3] = 40.0f;
        break;
    case 3:
        func_80098480((u8 *)arg0, 1, 1);
        (*(f32 **)(arg0 + 0xD8))[0] = 80.0f;
        (*(f32 **)(arg0 + 0xD8))[1] = 13.0f;
        (*(f32 **)(arg0 + 0xD8))[2] = 50.0f;
        (*(f32 **)(arg0 + 0xD8))[3] = 40.0f;
        func_800EFA4C(*(f32 **)(arg0 + 0xD8) + 4, 0.0f, -0.2f, -0.4f);
        break;
    case 4:
        func_80098480((u8 *)arg0, 1, 1);
        (*(f32 **)(arg0 + 0xD8))[0] = 50.0f;
        (*(f32 **)(arg0 + 0xD8))[1] = 13.0f;
        (*(f32 **)(arg0 + 0xD8))[2] = 50.0f;
        (*(f32 **)(arg0 + 0xD8))[3] = 40.0f;
        func_800EFA4C(*(f32 **)(arg0 + 0xD8) + 4, 0.0f, -0.2f, -0.4f);
        break;
    case 5:
        func_80098480((u8 *)arg0, 1, 1);
        (*(f32 **)(arg0 + 0xD8))[3] = 0.0f;
        temp_v0 = *(f32 **)(arg0 + 0xD8);
        temp_f0 = temp_v0[3];
        temp_v0[2] = temp_f0;
        (*(f32 **)(arg0 + 0xD8))[1] = temp_f0;
        (*(f32 **)(arg0 + 0xD8))[0] = temp_f0;
        func_800EFD24(*(f32 **)(arg0 + 0xD8) + 4);
        break;
    }
    temp_v0 = *(f32 **)(arg0 + 0xD8);
    func_80098494((void *)arg0, temp_v0[0], temp_v0[1], temp_v0[2], temp_v0[3]);
    func_800984CC((void *)arg0, *(f32 **)(arg0 + 0xD8) + 4);
}
