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

/* extern */

void gsworldDll_entrypoint_1(void *arg0) {
    s32 _chbounce_entrypoint_1();
    s32 _gccollectDll_entrypoint_5();
    s32 _gcgoto_entrypoint_12();
    s32 _glcutDll_entrypoint_5();
    s32 _gldialog_entrypoint_3();
    s32 _idworldmake_entrypoint_3();
    s32 _subaddierouteDll_entrypoint_0();
    s32 _sufade_entrypoint_2();
    s32 _sulights_entrypoint_8();
    s32 func_800A5630();
    s32 func_800A5CC4();
    s32 func_800AB9D0();
    s32 func_800B5054();
    s32 func_800B5824();
    s32 func_800B5AD4();
    s32 func_800B5E04();
    s32 func_800B7CC4();
    s32 func_800BC8A0();
    s32 func_800BD5DC();
    s32 func_800BF420();
    s32 func_800BFCB4();
    s32 func_800BFF28();
    s32 func_800C00E0();
    s32 func_800C5770();
    s32 func_800C6A60();
    s32 func_800C7500();
    s32 func_800C7A60();
    s32 func_800C90D0();
    s32 func_800CB9AC();
    s32 func_800D2970();
    s32 func_800D2E4C();
    s32 func_800D743C();
    s32 func_800D8800();
    s32 func_800D8898();
    s32 func_800DBB24();
    s32 func_800E1748();
    s32 func_800E4CE8();
    s32 func_800E86DC();
    s32 func_800E8B04();
    s32 func_800E9774();
    s32 func_800EA148(s32);
    s32 func_800EBC04();
    s32 func_800F732C();
    s32 func_800FA660();
    s32 func_800FF038(u16);
    s32 func_800FFDBC();
    s32 func_80100610();
    s32 func_80100B4C();
    s32 func_8010D89C();
    _gccollectDll_entrypoint_5();
    func_800EA148(3);
    func_800C00E0();
    _sufade_entrypoint_2();
    _subaddierouteDll_entrypoint_0();
    func_800C7500();
    func_800D8800();
    func_800D743C();
    func_800A5CC4();
    func_800D8898();
    _glcutDll_entrypoint_5();
    func_800F732C();
    func_800B5E04();
    func_800FA660();
    _chbounce_entrypoint_1();
    func_800E1748();
    func_800A5630();
    func_800B5AD4();
    func_800B5824();
    func_800B5054();
    func_800B7CC4();
    _gcgoto_entrypoint_12();
    func_800BD5DC();
    func_800CB9AC();
    func_800C5770();
    func_800BF420();
    func_800BFCB4();
    func_800C90D0();
    func_800BFF28();
    _idworldmake_entrypoint_3();
    func_80100610();
    func_80100B4C();
    _sulights_entrypoint_8();
    func_800C7A60();
    func_800AB9D0();
    func_800FFDBC();
    func_8010D89C();
    func_800E4CE8();
    func_800E9774();
    func_800C6A60();
    func_800D2E4C();
    func_800EBC04();
    _gldialog_entrypoint_3();
    func_800FF038((*(u16 *)((s8 *)(arg0) + (2))));
    func_800DBB24();
    func_800E8B04();
    func_800D2970();
    func_800E86DC();
    func_800BC8A0();
}

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
