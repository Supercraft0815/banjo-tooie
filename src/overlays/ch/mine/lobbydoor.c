#include "common.h"

void func_808000A8_chminelobbydoor(BtIntPtr);
void func_8080000C_chminelobbydoor(BtIntPtr);
s32 func_8080018C_chminelobbydoor(Actor *, s32, s32);
void func_80101870(Actor *, void *);
void func_80105834(Actor *);
void *func_80107C2C(s32 *, s32, void *, s32, void *);

BtFnWord D_808001F0_chminelobbydoor[] = {
    0x00AC02B9, 0x08500004, 0, (BtFnWord)func_808000A8_chminelobbydoor,
    (BtFnWord)func_80105834, (BtFnWord)func_80101870, 0, 0,
    0, 0x40020800, 0, 0,
    0, (BtFnWord)func_8080000C_chminelobbydoor, (BtFnWord)func_80107C2C, 0x80082412,
    (BtFnWord)func_8080018C_chminelobbydoor, 0
};
s32 D_80800238_chminelobbydoor = 0x190;
s16 D_8080023C_chminelobbydoor[] = {
    0x0FAA, 0x0FAA, 0, 0x0101, 0x120A, 0, 0x003F, 0,
    0x000A, 0x4000, 0, 0, 0, 0, 0, 0, 0, 0
};


OSThread *chminelobbydoor_entrypoint_0(void)
{

    return (OSThread *) D_808001F0_chminelobbydoor;
}

/* extern */

void func_8080000C_chminelobbydoor(BtIntPtr arg0) {
    s32 _chdoormake_entrypoint_3(BtIntPtr, f32, f32, f32, s32, s32);
    void _chdoormake_entrypoint_5(Actor *arg0, f32 arg1);
    void _chdoormake_entrypoint_8(Actor *arg0, u32 arg1);
    s32 func_8009E958();
    s32 func_800D0A9C(s32, s32);
    s32 func_800EA090();
    void func_80101FDC(Actor *actor,u32 state);
    if ((func_800EA090() == 1) && ((func_800D0A9C(0xF, 1) == 0) || (func_8009E958() != 1))) {
        func_80101FDC(arg0, 1);
    }
    if (_chdoormake_entrypoint_3(arg0, 0.0f, 90.0f, 200.0f, 8, -1) != 0) {
        _chdoormake_entrypoint_5(arg0, 1.5f);
        _chdoormake_entrypoint_8(arg0, 14);
    }
}

void func_808000A8_chminelobbydoor(BtIntPtr arg0)
{
    void func_808000D0_chminelobbydoor(Actor *);
    void _chdoor_entrypoint_0(BtIntPtr);

    func_808000D0_chminelobbydoor((Actor *)arg0);
    _chdoor_entrypoint_0(arg0);
}

void func_808000D0_chminelobbydoor(Actor *arg0) {
    int func_800C6E38(s32);
    u32 _subaddiedialog_entrypoint_7(void *arg0, f32 *arg1, void *arg2);
    s32 state;
    s32 i;

    state = func_800C6E38(0x15) ? 1 : 0;
    state += func_800C6E38(0x1A) ? 2 : 0;
    switch (state) {
        case 0:
        case 2:
            break;
        case 1:
            for (i = 0; i < 1; i = 1) {
                D_8080023C_chminelobbydoor[i] = 0xF9F;
                D_8080023C_chminelobbydoor[i + 1] = 0xFA0;
            }
            break;
        case 3:
            for (i = 0; i < 1; i = 1) {
                D_8080023C_chminelobbydoor[i] = 0xFA1;
                D_8080023C_chminelobbydoor[i + 1] = 0xFA1;
            }
            break;
    }
    _subaddiedialog_entrypoint_7(arg0, arg0->position, &D_80800238_chminelobbydoor);
}

/* extern */

s32 func_8080018C_chminelobbydoor(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _chdoor_entrypoint_1(BtIntPtr, s32, BtIntPtr);
    s32 func_8010108C(Actor *, s32, BtIntPtr);
    if (arg1 == 0x2E) {
        if (*(s16 *) &arg2 == 0xFA1) {
            func_8010108C(arg0, 7, 0);
            return 1;
        }
        return 1;
    }
    return _chdoor_entrypoint_1((BtIntPtr) arg0, arg1, arg2);
}
