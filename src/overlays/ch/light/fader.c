#include "common.h"

OSThread *chlightfader_entrypoint_0(void)
{
    extern u8 D_808003A0_chlightfader[];

    return (OSThread *) D_808003A0_chlightfader;
}

void func_8080000C_chlightfader(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/light/fader/func_80800014_chlightfader.s")

s32 chlightfader_entrypoint_1(s32 arg0, s32 arg1, s32 arg2) {
    void _chbaddiesetup_entrypoint_3(s32 *, s32, s32, s32);
    void func_800C8B84(s32);
    s32 func_800C954C(void);
    extern s32 _chlightfader_entrypoint_2;
    if (func_800C954C() == 0) {
        _chbaddiesetup_entrypoint_3(&_chlightfader_entrypoint_2, arg0, arg1, arg2);
    } else {
        func_800C8B84(arg0);
    }
    return 0;
}

/* extern */

void chlightfader_entrypoint_2(s32 arg0, f32 arg1, s32 arg2) {
    void func_800C8800(s32, f32 *);
    void func_800C883C(s32, void *);
    void func_800C8900(s32, u8 *);
    u8 func_800C89A8(s32);
    void *func_80100094(Actor *, u32);
    Actor *func_80108474(u32, f32 *, s32);
    Actor *sp5C;
    f32 *duration_arg = &arg1;
    f32 sp54;
    f32 sp48[3];
    f32 duration;
    s32 var_s0;
    struct {
        s32 source;
        f32 duration;
        s32 mode;
        s32 flag;
        f32 value;
        struct {
            s32 unk0;
            f32 unk4;
            u8 unk8[12];
        }
        lights[2];
    }
    *temp_s5;
    Actor *temp_v0;
    u8 *var_s1;
    u8 *var_s2;
    sp54 = *duration_arg;
    func_800C8800(arg0, sp48);
    temp_v0 = func_80108474(0x33C, sp48, 0);
    sp5C = temp_v0;
    temp_s5 = func_80100094(temp_v0, 0);
    temp_s5->flag = func_800C89A8(arg0);
    var_s0 = 0;
    var_s1 = temp_s5->lights[0].unk8;
    var_s2 = (u8 *)&temp_s5->lights[0];
    do {
        func_800C8900(arg0, var_s1);
        func_800C883C(arg0, var_s2);
        var_s0 += 0x14;
        var_s1 += 0x14;
        var_s2 += 0x14;
    }
    while (var_s0 != 0x28);
    duration = sp54;
    temp_s5->source = arg0;
    temp_s5->duration = duration;
    temp_s5->mode = arg2;
    temp_s5->value = temp_s5->lights[1].unk4;
    sp5C->unk58 = duration;
}
