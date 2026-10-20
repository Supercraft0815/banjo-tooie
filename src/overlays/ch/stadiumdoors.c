#include "common.h"

void func_80800000_chstadiumdoors(Actor *arg0) {
    s32 func_800DA298(s32);
    s32 _gcfrontend_entrypoint_9(s32);

    switch (arg0->unk74_7) {
        case 0x33:
            if (func_800DA298(0x576)) {
                arg0->unk70_10 = 3;
                arg0->rotation[1] = -85.0f;
                _gcfrontend_entrypoint_9(0x60);
            }
            break;
        case 0x34:
            if (func_800DA298(0x5E)) {
                arg0->unk70_10 = 3;
                arg0->rotation[1] = -85.0f;
                _gcfrontend_entrypoint_9(0x61);
            }
            break;
        case 0x35:
            if (func_800DA298(0x5F)) {
                arg0->unk70_10 = 3;
                arg0->rotation[1] = -85.0f;
                _gcfrontend_entrypoint_9(0x62);
            }
            break;
    }
}

void func_808000FC_chstadiumdoors(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    void func_800C4140(u32, f32 *, u32);
    s32 func_800DA298(s32);
    void func_80102B2C(Actor *, f32);
    s32 func_80102CF4(Actor *, s32);
    extern u32 D_80800270_chstadiumdoors;

    switch (arg0->unk70_10) {
        case 1:
            switch (arg0->unk74_7) {
                case 0x33:
                    if (func_800DA298(0x576)) {
                        arg0->unk70_10 = 2;
                        arg0->unk54 = -85.0f;
                    }
                    break;
                case 0x34:
                    if (func_800DA298(0x5E)) {
                        arg0->unk70_10 = 2;
                        arg0->unk54 = -85.0f;
                    }
                    break;
                case 0x35:
                    if (func_800DA298(0x5F)) {
                        arg0->unk70_10 = 2;
                        arg0->unk54 = -85.0f;
                    }
                    break;
            }
            break;
        case 2:
            _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, &D_80800270_chstadiumdoors);
            if (func_80102CF4(arg0, 0x3F800000) == 0) {
                func_80102B2C(arg0, 1.0f);
            } else {
                func_800C4140(0x665194CC, arg0->position, 0x138809C4);
                arg0->unk70_10 = 3;
            }
            break;
    }
}

OSThread *chstadiumdoors_entrypoint_0(void)
{
    extern u8 D_80800280_chstadiumdoors[];

    return (OSThread *) D_80800280_chstadiumdoors;
}
