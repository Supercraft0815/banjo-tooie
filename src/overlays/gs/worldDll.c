#include "common.h"

#if defined(BT_NATIVE) && !defined(BT_ILP32)
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

typedef struct { s16 unk0; u16 unk2; BtIntPtr unk4; s16 unk8; u8 padA[0x4]; u16 unkE; } ObjworldDll_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */ void gsworldDll_entrypoint_1(BT_IDO_ONLY(void *arg0) BT_PASS2(void *arg0, s32 bt_a1)) {
    void _chbounce_entrypoint_1(void);
    void _gccollectDll_entrypoint_5(void);
    void _gcgoto_entrypoint_12(void);
    void _glcutDll_entrypoint_5(void);
    void _gldialog_entrypoint_3(void);
    void _idworldmake_entrypoint_3(void);
    void _subaddierouteDll_entrypoint_0(void);
    void _sufade_entrypoint_2(void);
    void _sulights_entrypoint_8(void);
    void func_800A5630(void);
    void func_800A5CC4(void);
    void func_800AB9D0(void);
    void func_800B5054(void);
    void func_800B5824(void);
    void func_800B5AD4(void);
    void func_800B5E04(void);
    void func_800B7CC4(void);
    void func_800BC8A0(void);
    void func_800BD5DC();
    void func_800BF420(void);
    void func_800BFCB4(void);
    void func_800BFF28();
    void func_800C00E0(void);
    void func_800C5770(void);
    void func_800C6A60(void);
    void func_800C7500(void);
    void func_800C7A60(void);
    void func_800C90D0(void);
    void func_800CB9AC(void);
    void func_800D2970(void);
    void func_800D2E4C(void);
    void func_800D743C();
    void func_800D8800(void);
    void func_800D8898(void);
    void func_800DBB24(void);
    void func_800E1748(void);
    void func_800E4CE8(void);
    void func_800E86DC(void);
    void func_800E8B04(void);
    void func_800E9774(void);
    void func_800EA148(s32 arg0);
    void func_800EBC04(void);
    void func_800F732C(void);
    void func_800FA660(void);
    void func_800FF038(s32 arg0);
    void func_800FFDBC(void);
    void func_80100610(void);
    void func_80100B4C(void);
    void func_8010D89C(void);
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
    func_800FF038((((ObjworldDll_arg0 *)arg0)->unk2));
    func_800DBB24();
    func_800E8B04();
    func_800D2970();
    func_800E86DC();
    func_800BC8A0();
}

/* extern */

void gsworldDll_entrypoint_2(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    void _chbounce_entrypoint_0(void);
    void _gcgoto_entrypoint_13(void);
    BtIntPtr _gcsectionDll_entrypoint_2(s32);
    u8 _gcstatusDll_entrypoint_11(void);
    void _gcwater_entrypoint_0(void);
    void _glcutDll_entrypoint_4(void);
    void _gldialog_entrypoint_2(void);
    void _glhittableDll_entrypoint_0(void);
    void _glintrosyncDll_entrypoint_6(s32 arg0);
    void _idworldmake_entrypoint_4(void);
    void func_800A5124();
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
    void func_800BC690(void);
    void func_800BD570();
    s32 func_800BF444(void);
    void func_800BF68C(void);
    void func_800BFCBC(void);
    void func_800BFF4C();
    void func_800C00BC();
    void func_800C5778(void);
    void func_800C6A68(void);
    void func_800C73A4(void);
    void func_800C7A58(void);
    void func_800C90AC(void);
    void func_800CB988();
    void func_800D298C(void);
    void func_800D2CD0(void);
    void func_800D5250();
    void func_800D7418();
    void func_800D8800(void);
    void func_800D8870(void);
    void func_800D9FFC(void);
    void func_800DA048(void);
    void func_800E1788(void);
    void func_800E829C(void);
    void func_800E8A60(void);
    void func_800E9728(void);
    void func_800EA334(s32);
    void func_800EA34C(s32);
    void func_800EBB94(void);
    void func_800F73C4(s32 arg0);
    void func_800FA010(void);
    void func_800FE740(void);
    void func_8010052C(void);
    void func_80100B3C(void);
    void func_8010D790(void);

    (((ObjworldDll_arg0 *)arg0)->unkE) = (((ObjworldDll_arg0 *)arg0)->unk2);
    (((ObjworldDll_arg0 *)arg0)->unk0) = 3;
    (((ObjworldDll_arg0 *)arg0)->unk2) = arg1;
    (((ObjworldDll_arg0 *)arg0)->unk4) = _gcsectionDll_entrypoint_2(arg1);
    (((ObjworldDll_arg0 *)arg0)->unk8) = (s16) arg2;
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
#if defined(BT_NATIVE) && !defined(BT_ILP32)
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
    func_800A5124((((ObjworldDll_arg0 *)arg0)->unk8));
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

#if defined(BT_NATIVE) && !defined(BT_ILP32)
#define WORLD_FILENAME const char *
#else
#define WORLD_FILENAME s32
#endif
void func_8080054C_gsworldDll(s32 arg0, s32 arg1, WORLD_FILENAME arg2) {
}
void gsworldDll_entrypoint_4(void *arg0) {
    func_8080054C_gsworldDll(1, (s32) (((ObjworldDll_arg0 *)arg0)->unk2), (WORLD_FILENAME) "world.gs");
}
