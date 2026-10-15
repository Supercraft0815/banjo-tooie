#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gs/propsDll/gspropsDll_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gs/propsDll/gspropsDll_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gs/propsDll/gspropsDll_entrypoint_2.s")

s32 func_808004E0_gspropsDll(Prop *arg0) {
    switch (arg0->unk6_1) {
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
        return 0;
    default:
        return 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gs/propsDll/func_80800524_gspropsDll.s")

/* extern */

void gspropsDll_entrypoint_3(s16 *arg0) {
    void aligned4_memcpy(void *, void *, int);
    s32 func_800BDBC4(s32);
    void *func_800E9A24(s32);
    void func_800EE8CC(s32 *, s16 *);
    s32 func_80800524_gspropsDll(s32);
    typedef struct {
        u8 pad[0x12];
        u8 reserved : 7;
        u8 enabled : 1;
    } PropFlags;
    s32 sp2C;
    s32 sp20[3];
    PropFlags *sp1C;

    func_800EE8CC(sp20, arg0);
    sp2C = func_800BDBC4((s32)sp20);
    sp1C = func_800E9A24(sp2C);
    aligned4_memcpy(sp1C, arg0, 0x14);
    if (!((*(s32 *)((s8 *)(sp1C) + (4))) & 1)) {
        sp1C->enabled = 1;
    }
    func_80800524_gspropsDll(sp2C);
}

/* extern */

void gspropsDll_entrypoint_4(s16 *arg0) {
    void aligned4_memcpy(void *, void *, int);
    s32 func_800BDBC4(s32);
    void *func_800E98C0(s32);
    void func_800EE8CC(s32 *, s16 *);
    typedef struct {
        u8 pad[8];
        u32 reserved : 26;
        u32 flag5 : 1;
        u32 flag4 : 1;
        u32 reserved2 : 2;
        u32 flag1 : 1;
        u32 reserved3 : 1;
    } PropFlags;
    s32 sp2C;
    s32 sp20[3];
    PropFlags *sp1C;

    func_800EE8CC(sp20, arg0 + 2);
    sp2C = func_800BDBC4((s32)sp20);
    sp1C = func_800E98C0(sp2C);
    aligned4_memcpy(sp1C, arg0, 0xC);
    sp1C->flag4 = 1;
    if (sp1C->flag1) {
        sp1C->flag5 = 0;
    }
}
