#include "common.h"

OSThread *ch1pfreeze_entrypoint_0(void)
{
    extern u8 D_80800420_ch1pfreeze[];

    return (OSThread *) D_80800420_ch1pfreeze;
}

void func_8080000C_ch1pfreeze(s32 arg0) 
{
}
/* extern */

void *func_80100094(Actor *, u32);
void func_80800014_ch1pfreeze(Actor *arg0) { if ((s32) arg0->unk70_10 < 4) { func_800F7B9C(*(s32 *)func_80100094(arg0, 0), 0xF); } }

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/1pfreeze/func_80800054_ch1pfreeze.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/1pfreeze/func_8080014C_ch1pfreeze.s")

s32 func_80800294_ch1pfreeze(Actor *arg0, s32 arg1, s32 arg2) {
    void func_808002D0_ch1pfreeze(Actor *, s32);
    switch (arg1) {
        case 0x4:
            func_808002D0_ch1pfreeze(arg0, 0x4);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_808002D0_ch1pfreeze(Actor *arg0, s32 arg1) {
    void func_800EFA88(void *, s32, s32, s32);
    void func_80103110(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    void _sufreezy_entrypoint_4(Unk80132ED0 *, s32);
    struct {
        s32 unk0;
        s32 color[3];
        s32 unk10;
        f32 unk14;
        f32 unk18;
        f32 unk1C;
    } *data;

    data = func_80100094(arg0, 0);
    switch (arg1) {
        case 2:
            func_800EFA88(data->color, 0x80, 0xC0, 0xFF);
            data->unk10 = 0;
            data->unk14 = 0.25f;
            data->unk18 = 0.25f;
            data->unk1C = 0.0f;
            break;
        case 3:
            func_80103110(arg0, 0);
            break;
        case 4:
            _sufreezy_entrypoint_4(arg0->unk0, 8);
            data->unk14 = 0.25f;
            data->unk18 = 0.25f;
            func_80103110(arg0, 1);
            break;
    }
    func_80101FDC(arg0, arg1);
}

/* extern */

s32 ch1pfreeze_entrypoint_1(s32 arg0) {
    f32 func_800F5F24(u32);
    Actor *sp2C;
    f32 sp20[3];
    void *temp_v0;
    void func_808002D0_ch1pfreeze(Actor *, s32);

    func_800F5A00(arg0, sp20);
    sp2C = func_80108474(0x2C5, sp20, 0);
    temp_v0 = func_80100094(sp2C, 0);
    *(s32 *)temp_v0 = arg0;
    *(f32 *)((s8 *)sp2C + 0x48) = func_800F5F24(arg0);
    func_808002D0_ch1pfreeze(sp2C, 2);
    return (*(s32 *)((s8 *)sp2C + 0));
}
