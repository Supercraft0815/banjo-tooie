#include "common.h"

OSThread *chscorepoints_entrypoint_0(void)
{
    extern u8 D_808003C0_chscorepoints[];

    return (OSThread *) D_808003C0_chscorepoints;
}

/* extern */

void func_8080000C_chscorepoints(Actor *arg0) {
    void func_800E6DB4(char *, s32);
    s32 func_800E7188(u8 *);
    void func_800E73D4(s8 *);
    void func_800FC660(u32);
    u32 *func_80100074(Actor *, u32, u32);
    void *func_80100094(Actor *, u32);
    void rare_memcpy(void *, void *, int);
    char sp28[32];
    s32 sp24;

    func_800E73D4(sp28);
    func_800E6DB4(sp28, arg0->actorData[4]);
    sp24 = func_800E7188(sp28);
    func_80100074(arg0, 0, sp24 + 1);
    rare_memcpy(func_80100094(arg0, 0), sp28, sp24 + 1);
    arg0->unk58 = 0.8f;
    if (arg0->actorData[5] & 1) {
        if ((s32)arg0->actorData[4] < 0) {
            func_800FC660(0xF);
            return;
        }
        func_800FC660(0xE);
    }
}

void func_808000BC_chscorepoints(Actor *arg0) {
    void _subaddiefade_entrypoint_3(Actor *);
    f32 func_80013970(f32);
    f32 func_800D8FF8(void);
    s32 func_800D9078(f32 *);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    void func_80101FDC(Actor *, u32);
    s32 sp2C;

    switch (arg0->unk70_10) {
        case 1:
            sp2C = func_800D9078(&arg0->unk58);
            *(f32 *)&arg0->actorData[6] = func_80013970(func_800F12D4(arg0->unk58, 0.0f, 0.8f, 0.0f, 720.0f)) * 50.0f;
            if (sp2C != 0) {
                _subaddiefade_entrypoint_3(arg0);
                func_80101FDC(arg0, 2);
            }
            break;
        case 2:
            *(f32 *)&arg0->actorData[6] = 0.0f;
            arg0->position[1] += func_800D8FF8() * 120.0f;
            break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/scorepoints/func_8080019C_chscorepoints.s")

/* extern */

void chscorepoints_entrypoint_1(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 func_800D3DA4(s32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    Actor *func_80108474(u32, f32 *, s32);
    f32 sp1C[3];
    Actor *sp18;

    func_800EFA4C(sp1C, (f32) arg2, (f32) arg3, (f32) arg4);
    sp18 = func_80108474(0x14E, sp1C, 0);
    sp18->actorData[4] = arg0;
    sp18->actorData[5] = arg5;
    *(s32 *)&sp18->unk54 = arg1;
    *(s32 *)&sp18->unk50 = func_800D3DA4(arg1) + 0xC29;
}

void chscorepoints_entrypoint_2(s32 arg0, s32 arg1, void *arg2, s32 arg3) {
    s32 _chbaddiesetup_entrypoint_6(s32 *, s32, s32, s32, s32, s32, s32);
    extern s32 _chscorepoints_entrypoint_1;
    _chbaddiesetup_entrypoint_6(&_chscorepoints_entrypoint_1, arg0, arg1, (s32) (*(f32 *)((s8 *)(arg2) + (0))), (s32) (*(f32 *)((s8 *)(arg2) + (4))), (s32) (*(f32 *)((s8 *)(arg2) + (8))), arg3);
}
