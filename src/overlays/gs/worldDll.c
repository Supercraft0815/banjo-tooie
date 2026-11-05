#include "common.h"

#ifdef BT_NATIVE
#include "native_gsfile.h"
#include "native_world_load.h"
#include <stdio.h>
#include <stdlib.h>

s32 gsworldDll_entrypoint_0(s32 map,s32 mode) {
    void func_8001A2B0(void);
    void _cadbio_entrypoint_0(GsFile *);
    void func_800BDC68(void *),func_800BDC90(void *),func_800C90F4(void *);
    GsFile *world;
    s32 success;
    (void)mode;
    func_8001A2B0();world=_gsmaker_entrypoint_2(map);
    if(!world)return 0;
    while(!world->failed && !_gsmaker_entrypoint_16(world,0)) {
        if(_gsmaker_entrypoint_16(world,2) || _gsmaker_entrypoint_16(world,5))continue;
        if(_gsmaker_entrypoint_16(world,1))func_800BDC68(world);
        else if(_gsmaker_entrypoint_16(world,4))func_800C90F4(world);
        else if(_gsmaker_entrypoint_16(world,6))_cadbio_entrypoint_0(world);
        else if(_gsmaker_entrypoint_16(world,7))func_800BDC90(world);
        else world->failed=1;
    }
    success=!world->failed;_gsmaker_entrypoint_0(world);return success;
}
#else
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

#endif

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

/* extern */

void gsworldDll_entrypoint_2(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 _chbounce_entrypoint_0();
    s32 _gcgoto_entrypoint_13();
    s32 _gcsectionDll_entrypoint_2(s32);
    s32 _gcstatusDll_entrypoint_11();
    s32 _gcwater_entrypoint_0();
    s32 _glcutDll_entrypoint_4();
    s32 _gldialog_entrypoint_2();
    s32 _glhittableDll_entrypoint_0();
    s32 _glintrosyncDll_entrypoint_6(s32);
    s32 _idworldmake_entrypoint_4();
    s32 func_800A5124(s16);
    void func_800A5320(void);
    void func_800A55E0(void);
    void func_800A5AB0(void);
    void func_800A5C04(void);
    void func_800A5C28(void);
    void func_800A5C94(void);
    void func_800A9EC0(s32);
    void func_800AB980(void);
    void func_800B5028(void);
    void func_800B5884(void);
    void func_800B5B04(void);
    void func_800B5DFC(void);
    void func_800B7D14(void);
    s32 func_800BC690();
    s32 func_800BD570();
    void func_800BF444(void);
    void func_800BF68C(void);
    s32 func_800BFCBC();
    s32 func_800BFF4C();
    s32 func_800C00BC();
    void func_800C5778(void);
    void func_800C6A68(void);
    void func_800C73A4(void);
    s32 func_800C7A58();
    s32 func_800C90AC();
    s32 func_800CB988();
    void func_800D298C(void);
    void func_800D2CD0(void);
    s32 func_800D5250();
    s32 func_800D7418();
    s32 func_800D8800();
    void func_800D8870(void);
    s32 func_800D9FFC();
    s32 func_800DA048();
    void func_800E1788(void);
    void func_800E829C(void);
    s32 func_800E8A60();
    void func_800E9728(void);
    void func_800EA334(s32);
    void func_800EA34C(s32);
    s32 func_800EBB94();
    s32 func_800F73C4(s32);
    s32 func_800FA010();
    s32 func_800FE740();
    s32 func_8010052C();
    s32 func_80100B3C();
    s32 func_8010D790();

    (*(u16 *)((s8 *)(arg0) + (0xE))) = (*(u16 *)((s8 *)(arg0) + (2)));
    (*(s16 *)((s8 *)(arg0) + (0))) = 3;
    (*(u16 *)((s8 *)(arg0) + (2))) = arg1;
    (*(s32 *)((s8 *)(arg0) + (4))) = _gcsectionDll_entrypoint_2(arg1);
    (*(s16 *)((s8 *)(arg0) + (8))) = (s16) arg2;
    func_800A9EC0((s32) arg1);
    func_800D8800();
    func_800BC690();
    func_800E829C();
    func_800E8A60();
    func_800EA334(1);
    func_800EA34C(1);
    func_800D9FFC();
    func_800A5320();
    func_800D298C();
    func_800A5AB0();
    func_8010052C();
    func_80100B3C();
    func_800C6A68();
    _idworldmake_entrypoint_4();
    func_800C90AC();
    func_800BF444();
    _gcwater_entrypoint_0();
    func_800C5778();
    _gldialog_entrypoint_2();
    func_800D8870();
    func_800A5C04();
    func_800EBB94();
    func_800E9728();
    _gcgoto_entrypoint_13();
    func_800C7A58();
    func_800A55E0();
    func_800B5028();
    func_800B5884();
    func_800B5B04();
    func_800B7D14();
    func_800BFCBC();
    func_800BFF4C();
    func_800AB980();
    func_800CB988();
    func_800BD570();
    func_800FA010();
    if (arg3 != 0xF) {
#ifdef BT_NATIVE
        if(!gsworldDll_entrypoint_0(arg1,arg3)) {
            fprintf(stderr,"Banjo-Tooie native world: loading map %d failed\n",arg1);
            abort();
        }
#else
        gsworldDll_entrypoint_0((s32) arg1, arg3);
#endif
    }
    func_800BF68C();
    func_800D2CD0();
    func_800D5250();
    func_800C00BC();
    func_800DA048();
    _glintrosyncDll_entrypoint_6((s32) arg1);
    func_800D7418();
    _glhittableDll_entrypoint_0();
    func_8010D790();
    func_800A5C28();
    func_800F73C4(_gcstatusDll_entrypoint_11());
    func_800E1788();
    func_800FE740();
    func_800C73A4();
    _chbounce_entrypoint_0();
    func_800A5124((*(s16 *)((s8 *)(arg0) + (8))));
    func_800B5DFC();
    func_800A5C94();
    _glcutDll_entrypoint_4();
}

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

#ifdef BT_NATIVE
#define WORLD_FILENAME const char *
#else
#define WORLD_FILENAME s32
#endif
void func_8080054C_gsworldDll(s32 arg0, s32 arg1, WORLD_FILENAME arg2) {
}
void gsworldDll_entrypoint_4(void *arg0) {
    func_8080054C_gsworldDll(1, (s32) (*(u16 *)((s8 *)(arg0) + (2))), (WORLD_FILENAME) "world.gs");
}
