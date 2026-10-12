#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/musicmenu/func_80800000_chmusicmenu.s")

s32 func_808000B4_chmusicmenu(s32 arg0) {
    if (arg0 < 9) {
        return arg0 + 0x1851;
    }
    return arg0 + 0x1860;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/musicmenu/func_808000D0_chmusicmenu.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/musicmenu/func_8080021C_chmusicmenu.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/musicmenu/func_80800400_chmusicmenu.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/musicmenu/func_80800560_chmusicmenu.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/musicmenu/func_80800610_chmusicmenu.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/musicmenu/func_80800714_chmusicmenu.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/musicmenu/func_8080079C_chmusicmenu.s")

void func_80800930_chmusicmenu(u8 *arg0, s32 arg1) {
    s32 _capod_entrypoint_21(s32, s32, s32, s32);
    s32 _capod_entrypoint_22();
    s32 _gccubesearch_entrypoint_12(s32 *, s32, u8 *);
    s32 _gcnewoption_entrypoint_10(s32, s32);
    s32 _gcnewoption_entrypoint_11(s32);
    void _gcnewoption_entrypoint_14(s32, s32, s32, s32, f32);
    s32 _gcnewoption_entrypoint_4(u8 *, s32, s32 *, s32, s32);
    void _gcnewoption_entrypoint_40(s32, s32, s32, s32, f32, f32);
    s32 _gcnewoption_entrypoint_6(u8 *, s32);
    s32 _gcnewoption_entrypoint_8(s32, s32);
    s32 _gcnewoption_entrypoint_9(s32, s32);
    s32 func_8008F8B0();
    s32 func_8008F8D8(s32);
    s32 func_8008F904(s32 *, s32);
    s32 func_8008F938(s32);
    s32 func_8008F990(s32 *, s32);
    s32 func_800F54E4();
    s32 func_800F82D4(s32, s32);
    s32 func_800F8300(s32, s32, u8 *);
    s32 func_80100094(u8 *, s32);
    s32 func_80101238(s32, s32);
    s32 func_80102424(u8 *, s32);
    s32 func_808000D0_chmusicmenu(u8 *, s32);
    void func_80800714_chmusicmenu(u8 *);
    extern u8 D_808014F8_chmusicmenu[];
    extern s32 _gcnewoption_entrypoint_35;
    extern s32 func_8010D5DC;
    s32 sp44;
    s32 sp40;
    s32 sp34[3];
    s32 value;

    switch ((u32)*(u16 *)(arg0 + 0x72) >> 10) {
        case 2:
            _gcnewoption_entrypoint_6(arg0, 1);
            break;
        case 1:
            _gcnewoption_entrypoint_6(arg0, 1);
            *(s32 *)(arg0 + 0x18) = -1;
            arg0[0x65] &= 0xFFF7;
            if (arg1 == 3) {
                _capod_entrypoint_22();
                func_80101238(0x6E, 0);
            }
            break;
        case 5:
            func_800F8300(func_800F54E4(), 2, arg0 + 4);
            _capod_entrypoint_21(*(s32 *)arg0, *(s32 *)arg0, 0x11, 4);
            *(s32 *)(arg0 + 0x28) = 0;
            *(f32 *)(arg0 + 0x58) = 10.0f;
            break;
    }
    func_80102424(arg0, arg1);
    switch ((u32)*(u16 *)(arg0 + 0x72) >> 10) {
        case 1:
            _gcnewoption_entrypoint_4(arg0, 1, &_gcnewoption_entrypoint_35, 0, 0x1850);
            sp44 = func_80100094(arg0, 1);
            _gcnewoption_entrypoint_40(sp44, 0x41, 0x22, 0x20, 0.8f, 1.0f);
            _gcnewoption_entrypoint_8(sp44, 5);
            _gcnewoption_entrypoint_9(sp44, 0xC);
            _gcnewoption_entrypoint_10(sp44, 0);
            func_808000D0_chmusicmenu(arg0, sp44);
            _gcnewoption_entrypoint_14(sp44, 0, 1, 3, 4.0f);
            _gcnewoption_entrypoint_11(sp44);
            return;
        case 2:
            _gcnewoption_entrypoint_4(arg0, 1, &_gcnewoption_entrypoint_35, 0, func_808000B4_chmusicmenu(*(s32 *)(arg0 + 0x30)));
            sp40 = func_80100094(arg0, 1);
            _gcnewoption_entrypoint_40(sp40, 0x41, 0x22, 0x20, 0.8f, 1.0f);
            value = D_808014F8_chmusicmenu[*(s32 *)(arg0 + 0x30) * 8];
            _gcnewoption_entrypoint_8(sp40, value < 5 ? value : 5);
            _gcnewoption_entrypoint_9(sp40, D_808014F8_chmusicmenu[*(s32 *)(arg0 + 0x30) * 8]);
            _gcnewoption_entrypoint_10(sp40, 2);
            func_808000D0_chmusicmenu(arg0, sp40);
            _gcnewoption_entrypoint_14(sp40, 0, 1, 3, 4.0f);
            if (*(s32 *)(arg0 + 0x1C) == *(s32 *)(arg0 + 0x30)) {
                value = *(s32 *)(arg0 + 0x20);
                if (value != -1) {
                    *(s32 *)(arg0 + 0x18) = value;
                }
            }
            _gcnewoption_entrypoint_11(sp40);
            return;
        case 4:
            *(s32 *)(arg0 + 0x20) = -1;
            *(s32 *)(arg0 + 0x1C) = -1;
            return;
        case 3:
            func_800F82D4(func_800F54E4(), 0);
            func_80800714_chmusicmenu(arg0);
            *(s32 *)(arg0 + 0x20) = -1;
            *(s32 *)(arg0 + 0x1C) = -1;
            *(s32 *)(arg0 + 0x30) = -1;
            return;
        case 5:
            _gccubesearch_entrypoint_12(sp34, 0x299, arg0 + 4);
            func_8008F8B0();
            func_8008F8D8(1);
            func_8008F904(&func_8010D5DC, *(s32 *)arg0);
            func_8008F938(1);
            func_8008F990(sp34, 0x43C80000);
            return;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/musicmenu/func_80800CBC_chmusicmenu.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/musicmenu/func_80800DA4_chmusicmenu.s")

/* extern */

void func_80800F50_chmusicmenu(u8 *arg0) {
    s32 _gcnewoption_entrypoint_6(u8 *, s32);
    void func_80800714_chmusicmenu(u8 *);
    u32 temp_t6;

    func_80800714_chmusicmenu(arg0);
    temp_t6 = (u32) ((Actor *) arg0)->unk70_10;
    if ((temp_t6 == 1) || (temp_t6 == 2)) {
        _gcnewoption_entrypoint_6(arg0, 1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/musicmenu/func_80800F98_chmusicmenu.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/musicmenu/func_80801040_chmusicmenu.s")

OSThread *chmusicmenu_entrypoint_0(void)
{
    extern u8 D_8080157C_chmusicmenu[];

    return (OSThread *) D_8080157C_chmusicmenu;
}

OSThread *chmusicmenu_entrypoint_1(void)
{
    extern u8 D_808015C4_chmusicmenu[];

    return (OSThread *) D_808015C4_chmusicmenu;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/musicmenu/func_808010C4_chmusicmenu.s")

OSThread *chmusicmenu_entrypoint_2(void)
{
    extern u8 D_8080160C_chmusicmenu[];

    return (OSThread *) D_8080160C_chmusicmenu;
}
