#include "common.h"

void gsworldDll_entrypoint_0(s32 arg0, s32 arg1) {
    void func_8001A2B0(void);
    s32 _gsmaker_entrypoint_2(s32);
    s32 _gsmaker_entrypoint_16(s32, s32);
    void _gsmaker_entrypoint_0(s32);
    void _cadbio_entrypoint_0(s32);
    void func_800BDC68(s32);
    void func_800BDC90(s32);
    void func_800C90F4(s32);
    s32 world;

    func_8001A2B0();
    world = _gsmaker_entrypoint_2(arg0);
    while (_gsmaker_entrypoint_16(world, 0) == 0) {
        if (_gsmaker_entrypoint_16(world, 2) == 0) {
            if (_gsmaker_entrypoint_16(world, 1) != 0) {
                func_800BDC68(world);
            } else if (_gsmaker_entrypoint_16(world, 4) != 0) {
                func_800C90F4(world);
            } else if (_gsmaker_entrypoint_16(world, 5) == 0) {
                if (_gsmaker_entrypoint_16(world, 6) != 0) {
                    _cadbio_entrypoint_0(world);
                } else if (_gsmaker_entrypoint_16(world, 7) != 0) {
                    func_800BDC90(world);
                }
            }
        }
    }
    _gsmaker_entrypoint_0(world);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gs/worldDll/gsworldDll_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gs/worldDll/gsworldDll_entrypoint_2.s")

/* extern */

void gsworldDll_entrypoint_3(s16 *arg0, s32 arg1) {
    void func_8001A2B0(void);
    void func_800A5104(s32, s32);
    void func_800B5654(s32, s32);
    void func_800C2A5C(s32, s32);
    void func_800C7574(s32, s32);
    void func_800FE8BC(s32, s32);
    func_8001A2B0();
    func_800A5104(*arg0, arg1);
    func_800C2A5C(*arg0, arg1);
    func_800FE8BC(*arg0, arg1);
    func_800C7574(*arg0, arg1);
    func_800B5654(*arg0, arg1);
    *arg0 = arg1;
}

void func_8080054C_gsworldDll(s32 arg0, s32 arg1, s32 arg2) {
}
void gsworldDll_entrypoint_4(void *arg0) {
    func_8080054C_gsworldDll(1, (s32) (*(u16 *)((s8 *)(arg0) + (2))), (s32) "world.gs");
}
