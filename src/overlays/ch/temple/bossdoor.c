#include "common.h"

OSThread *chtemplebossdoor_entrypoint_0(void)
{
    extern u8 D_808001C0_chtemplebossdoor[];

    return (OSThread *) D_808001C0_chtemplebossdoor;
}

void func_8080000C_chtemplebossdoor(Actor *arg0) {
    s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_5(Actor *, f32);
    void _chdoormake_entrypoint_8(void *, u32);
    s32 _chdoormake_entrypoint_9(Actor *, s32, s32, s32);
    s32 func_800D035C(s32);
    void func_800FFA88(Unk80132ED0 *);
    s32 required;
    s32 dialog = 0;

    switch (arg0->unk74_7 - 50) {
        case 0:
            required = 10;
            break;
        case 1:
            required = 20;
            dialog = 2;
            break;
    }
    if (func_800D035C(5) < required) {
        if (_chdoormake_entrypoint_3(arg0, 0.0f, 90.0f, 190.0f, 0x40, -1)) {
            _chdoormake_entrypoint_5(arg0, 1.5f);
            _chdoormake_entrypoint_8(arg0, 5);
            _chdoormake_entrypoint_9(arg0, 0, dialog, 0x30);
        }
    } else {
        func_800FFA88(arg0->unk0);
    }
}

s32 func_808000E8_chtemplebossdoor(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _chdoor_entrypoint_1(Actor *, s32, s32);
    void _capod_entrypoint_14(void);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, u32, u32, f32 *, u32);
    void func_800FFA88(Unk80132ED0 *);
    void func_80108BD4(Actor *, s32);
    s32 temp;
    s32 dialog;

    switch (arg1) {
        case 7:
            temp = arg0->unk74_7 - 50;
            if (arg2 != temp) {
                return 0;
            }
            if (temp != 0) {
                dialog = 0xF3B;
            } else {
                dialog = 0xF3A;
            }
            _subaddiedialog_entrypoint_11(arg0->unk0, dialog, 0x106, arg0->position, 0xB2);
            break;
        case 0x2E:
            func_80108BD4(arg0, 0);
            return 1;
        case 0x59:
            _capod_entrypoint_14();
            func_800FFA88(arg0->unk0);
            return 1;
    }
    return _chdoor_entrypoint_1(arg0, arg1, arg2);
}
