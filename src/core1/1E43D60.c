#include "common.h"

Acmd *func_8002C230(s32 arg0, Acmd *arg1) {
    typedef struct {
        s16 frequency;
        s16 cutoff;
        u32 unknown4;
        s16 coefficients[16];
        s32 dirty;
        void *left;
        void *right;
    } Filter;
    typedef struct {
        u8 unknown[0x44];
        Filter *filter;
    } FxBus;
    typedef struct {
        u32 unknown0;
        Acmd *(*render)(s32, Acmd *, s32);
    } Renderer;
    typedef struct {
        u8 unknown0[0x30];
        Renderer *renderer;
        FxBus *buses;
        u32 unknown38;
        s32 count;
        s32 rate;
    } Synth;
    void func_80028C04(void *, f32);
    extern Synth *D_800411F4;
    extern u8 D_8007EA33[], D_8007EA34[];
    Acmd *commands = arg1;
    s32 i;

    aClearBuffer(commands++, 0x4E0, 0x2E0);
    for (i = 0; i < D_800411F4->count; i++) {
        commands = D_800411F4->renderer->render(arg0, commands, i);
        if (D_8007EA33[i]) {
            if (D_8007EA34[i]) {
                aMix(commands++, 0, 0x8000, 0x7C0, 0x4E0);
            } else {
                aMix(commands++, 0, 0x7FFF, 0x7C0, 0x650);
            }
        } else {
            if (D_8007EA34[i]) {
                aMix(commands++, 0, 0x8000, 0x7C0, 0x650);
            } else {
                aMix(commands++, 0, 0x7FFF, 0x7C0, 0x650);
            }
            aMix(commands++, 0, 0x7FFF, 0x7C0, 0x4E0);
        }
        if (D_800411F4->buses[i].filter->cutoff > 0) {
            Filter *filter = D_800411F4->buses[i].filter;
            if (filter->dirty) {
                func_80028C04(filter, (f32)D_800411F4->rate);
            }
            aLoadADPCM(commands++, 0x20, osVirtualToPhysical(filter->coefficients));
            aPoleFilter(commands++, 0, 0x4E0, _SHIFTL(osVirtualToPhysical(filter->left) & 0xFFFFFF, 0, 24));
            aPoleFilter(commands++, 0, 0x650, _SHIFTL(osVirtualToPhysical(filter->right) & 0xFFFFFF, 0, 24));
            filter->dirty = 0;
        }
    }
    return commands;
}
