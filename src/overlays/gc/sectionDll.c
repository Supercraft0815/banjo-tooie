#include "common.h"

typedef struct { s16 map; s16 flags; u8 section; u8 pad; } SectionEntry;

void gcsectionDll_entrypoint_0(s32 arg0, s32 arg1) {
    s32 _gclevel_entrypoint_2();
    u8 _gcstatusDll_entrypoint_11(void);
    void func_8001A578(s32 arg0);
    void func_800A13B0(s32 arg0);
    void func_800F9178(void);
    BtIntPtr gcsectionDll_entrypoint_2(s32);
    s32 gcsectionDll_entrypoint_3(BtIntPtr, s32);
    s32 temp_v0;

    temp_v0 = _gclevel_entrypoint_2();
    if ((temp_v0 >= 0xF) && (temp_v0 < 0x20)) {
        if (gcsectionDll_entrypoint_3(gcsectionDll_entrypoint_2(arg0), 0x20) != 0) {
            func_8001A578(_gcstatusDll_entrypoint_11());
        } else if (arg0 == 0x189) {
            func_8001A578(0);
        }
        func_800F9178();
        func_800A13B0(arg0);
    }
}

void gcsectionDll_entrypoint_1(s32 arg0) {
    s32 _glglobalsettings_entrypoint_2();
    void func_80018634(void);
    s32 func_8001A63C(void);
    void func_800C0A2C(void);
    void func_800D389C();
    extern u8 D_8012762C;
    s32 temp_v0;

    temp_v0 = D_8012762C;
    if (arg0 != 0) {
        func_800D389C();
        _glglobalsettings_entrypoint_2();
    }
    if ((temp_v0 > 0) && (temp_v0 < 0x20)) {
        func_8001A63C();
    }
    func_80018634();
    func_800C0A2C();
}

s16 *func_808000F0_gcsectionDll(s32 arg0, s32 arg1) {
    extern SectionEntry D_80800210_gcsectionDll[228];
    SectionEntry *p = &D_80800210_gcsectionDll[1];
    while (p->map != 0) {
        if (arg0 == p->map) return &p->map;
        p++;
    }
    if (arg1 != 0) return NULL;
    return NULL;
}

 BtIntPtr gcsectionDll_entrypoint_2(s32 arg0) {
    extern SectionEntry D_80800210_gcsectionDll[228];
    return ((BtIntPtr) func_808000F0_gcsectionDll(arg0, 0) - (BtIntPtr) &D_80800210_gcsectionDll) / 6;
}

s32 gcsectionDll_entrypoint_3(BtIntPtr arg0, s32 arg1) {
    extern SectionEntry D_80800210_gcsectionDll[228];
    return (D_80800210_gcsectionDll[arg0].flags & arg1) ? 1 : 0;
}

u8 gcsectionDll_entrypoint_4(s32 arg0) {
    return (*(u8 *)((s8 *)(func_808000F0_gcsectionDll(arg0, 0)) + (4)));
}

/* extern */
s32 gcsectionDll_entrypoint_5(s32 arg0) {
    if (func_808000F0_gcsectionDll(arg0, 1) != 0) {
        return 1;
    }
    return 0;
}
#include "sectionDll_data.inc"
