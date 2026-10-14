#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/newmumbo/func_80800000_chnewmumbo.s")

void func_8080009C_chnewmumbo(Actor *arg0) {
    void _capod_entrypoint_3(u32);
    u8 *sp1C[1];
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    if ((*(u8 *)((s8 *)(temp_v0) + 0x24)) != 0) {
        sp1C[0] = temp_v0;
        _capod_entrypoint_3(0U);
        temp_v0 = sp1C[0];
        (*(s8 *)((s8 *)(temp_v0) + 0x24)) = 0;
    }
}

void func_808000DC_chnewmumbo(Actor *arg0, u32 arg1, u32 arg2) {
    arg0->unk74_30 = 1;
    _subaddiedialog_entrypoint_11(arg0->unk0, arg1, arg2, arg0->position, 0x10U);
}

s32 func_8080011C_chnewmumbo(void) {
    s32 func_800DA298(s32);
    s32 func_800EA05C();

    if (func_800DA298(0x9C5) == 0) {
        return 0;
    }
    switch (func_800EA05C()) {
        case 0xB7: return 0x37F;
        case 0xD9: return 0x380;
        case 0x176: return 0x381;
        case 0xEF: return 0x382;
        case 0x171: return 0x383;
        case 0x172: return 0x387;
        case 0x134: return 0x384;
        case 0x13E:
        case 0x13F: return 0x385;
        case 0x156: return 0x386;
    }
    return 0;
}

void func_80800210_chnewmumbo(s32 *arg0) {
    s32 func_8008F8B0();
    s32 func_8008F8D8(s32);
    s32 func_8008F904(s32 *, s32);
    s32 func_8008F938(s32);
    s32 func_8008F990(s32 *, s32);
    extern s32 D_80801A0C_chnewmumbo;
    extern s32 func_8010D5DC;
    func_8008F8B0();
    func_8008F8D8(1);
    func_8008F938(1);
    func_8008F904(&func_8010D5DC, *arg0);
    func_8008F990(&D_80801A0C_chnewmumbo, 0x43480000);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/newmumbo/func_80800264_chnewmumbo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/newmumbo/func_808004E8_chnewmumbo.s")

/* extern */

void func_8080073C_chnewmumbo(Actor *arg0, s32 arg1) {
    s32 _plsu_entrypoint_1(s32);
    u32 func_800F54E4(void);
    void func_800F7B9C(s32, u32);
    void func_800F8300();
    if (!arg0->unk64_19) {
        if (arg1 != 0) {
            func_800F7B9C(_plsu_entrypoint_1(1), 0x8D);
        }
        func_800F8300(func_800F54E4(), 2, arg0->position);
        arg0->unk64_19 = 1;
    }
}

void func_808007B0_chnewmumbo(u8 *arg0) {
    struct Flags { unsigned int : 12; unsigned int active : 1; unsigned int : 18; };
    u32 func_800F54E4(void);
    void func_800F82D4(s32, s32);
    if (((struct Flags *)(arg0 + 0x64))->active) {
        func_800F82D4(func_800F54E4(), 0);
        arg0[0x65] &= 0xFFF7;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/newmumbo/func_808007FC_chnewmumbo.s")

void func_80800878_chnewmumbo(s32 arg0)
{
    func_80800264_chnewmumbo(arg0,0xE);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/newmumbo/func_80800898_chnewmumbo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/newmumbo/func_8080092C_chnewmumbo.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/newmumbo/func_808014FC_chnewmumbo.s")

void chnewmumbo_entrypoint_0(Actor *arg0, f32 *arg1) { func_800EE7F8(arg1, (f32 *)((u8 *)func_80100094(arg0, 0U) + 4)); }

void func_8080172C_chnewmumbo(Actor* arg0) 
{
    if (func_80100094(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/newmumbo/func_80801760_chnewmumbo.s")

OSThread *chnewmumbo_entrypoint_1(void)
{
    extern u8 D_80801B14_chnewmumbo[];

    return (OSThread *) D_80801B14_chnewmumbo;
}
