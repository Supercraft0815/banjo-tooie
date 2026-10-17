#include "common.h"

OSThread *chtempleinternaldoor_entrypoint_0(void)
{
    extern u8 D_808001C0_chtempleinternaldoor[];

    return (OSThread *) D_808001C0_chtempleinternaldoor;
}

void func_8080000C_chtempleinternaldoor(Actor *arg0) {
    extern u8 D_8012762C;
    extern f32 D_8080020C_chtempleinternaldoor[][2];
    s32 _chdoormake_entrypoint_3(Actor *, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_5(Actor *, f32);
    s32 _chdoormake_entrypoint_7(u8 *, s32);
    void _chdoormake_entrypoint_8(void *, u32);
    void func_80101FDC(Actor *, u32);
    s32 index = arg0->unk74_7 - 0x32;
    s32 flags;
    f32 distance;

    switch (index) {
        default:
            flags = 0x1060A;
            break;
        case 0:
            flags = 0;
            break;
        case 1:
        case 10:
        case 11:
            if (D_8012762C == 0x1B) {
                flags = 0;
                break;
            }
            func_80101FDC(arg0, 4);
            flags = 0;
            break;
    }
    distance = D_8080020C_chtempleinternaldoor[index][0];
    if (_chdoormake_entrypoint_3(arg0, 0.0f, 90.0f, distance, flags, -1)) {
        _chdoormake_entrypoint_5(arg0, 2.0f);
        _chdoormake_entrypoint_7(arg0, 0x40A00000);
        _chdoormake_entrypoint_8(arg0, 5);
    }
}

/* extern */

void func_808000F8_chtempleinternaldoor(u8 *arg0) {
    s32 _chdoor_entrypoint_0();
    s32 _chdoormake_entrypoint_7(u8 *, s32);
    _chdoor_entrypoint_0();
    if (((u32) (*(u16 *)((s8 *)(arg0) + (0x72))) >> 0xA) == 1) {
        _chdoormake_entrypoint_7(arg0, 0x40A00000);
    }
}

/* extern */

void func_80800138_chtempleinternaldoor(s32 arg0, s32 arg1, s32 arg2) {
    s32 _chdoor_entrypoint_1(s32, s32, s32);
    s32 func_80800178_chtempleinternaldoor();
    if (arg1 == 0x95) {
        func_80800178_chtempleinternaldoor();
    }
    _chdoor_entrypoint_1(arg0, arg1, arg2);
}

s32 func_80800178_chtempleinternaldoor(Actor *arg0) {
    extern u8 D_80800208_chtempleinternaldoor[];
    u32 index = arg0->unk74_7 - 0x32;
    func_80103140(arg0, *(u16 *)(D_80800208_chtempleinternaldoor + index * 8), arg0->unk0->unk16);
}
