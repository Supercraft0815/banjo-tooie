#include "common.h"

OSThread *chbigtopticket_entrypoint_0(void)
{
    extern u8 D_80800120_chbigtopticket[];

    return (OSThread *) D_80800120_chbigtopticket;
}

void func_8080000C_chbigtopticket(s32 arg0) 
{
}
void func_80800014_chbigtopticket(u8 *arg0) {
    f32 func_800D8FF8(void);
    s32 func_80103110(void *, u32);
    (*(f32 *)((s8 *)(arg0) + (0x48))) = (f32) ((*(f32 *)((s8 *)(arg0) + (0x48))) - (func_800D8FF8() * 175.0f));
    func_80103110(arg0, 0U);
}

/* extern */

void func_80800058_chbigtopticket(void *arg0) {
    s32 func_80101870();
    s32 func_80103110(void *, u32);
    func_80101870();
    func_80103110(arg0, (u32) ((*(s32 *)((s8 *)(arg0) + (0x7C))) << 0x13) >> 0x1F);
}

/* extern */

s32 func_8080008C_chbigtopticket(Actor *arg0, s32 arg1, s32 arg2) {
    void _fxsparkle_entrypoint_1(f32 *, u32);
    void _sudialog_entrypoint_0(s32, s32);
    void func_800D0BD4(s32, u32);
    void func_800D1844(s32);
    void func_800FC6B0(u32);
    void func_800FFAB0(Actor *);
    void func_8010A570(Actor *);
    switch (arg1) {
        case 0x3E:
            _sudialog_entrypoint_0(0x19F, 4);
            func_800D0BD4(*(s32 *)&arg0->unk54, 8);
            func_800D1844(0x4D);
            func_800FC6B0(0x73);
            _fxsparkle_entrypoint_1(arg0->position, 0x11);
            func_8010A570(arg0);
            func_800FFAB0(arg0);
            return 1;
        case 0x13:
            *(s32 *)&arg0->unk54 = arg2;
            break;
        default:
            return 0;
    }
    return 1;
}
