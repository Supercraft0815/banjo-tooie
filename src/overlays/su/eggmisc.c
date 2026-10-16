#include "common.h"

s32 sueggmisc_entrypoint_0(Unk80132ED0 *arg0) {
    void *func_80100368(void *);
    Actor *func_80106790(Unk80132ED0 *);

    if (!(*(u16 *)&arg0->unk18 & 1)) {
        return 0;
    }
    switch ((s32)(arg0->unk24 >> 22)) {
    case 0x16D:
    case 0x26C:
    case 0x26D:
    case 0x26E:
        return 1;
    case 0x26F:
    case 0x270:
        return (arg0->unk24 >> 22) == *(s16 *)func_80100368(func_80106790(arg0));
    default:
        return 0;
    }
}

/* extern */

void sueggmisc_entrypoint_2(s32, s32);

void sueggmisc_entrypoint_1(Actor *arg0) {
    s32 _gcegg_entrypoint_1(u32);
    s32 _gcegg_entrypoint_5(s32);
    void func_800F7664(s32, s32, s32);
    s32 temp_v0;
    s32 sp24;
    s32 sp1C;

    temp_v0 = _gcegg_entrypoint_1((u32) arg0->unk6C_9);
    sueggmisc_entrypoint_2((s32) arg0 + 4, temp_v0);
    sp1C = func_800F54E4();
    func_800F7664(sp1C, _gcegg_entrypoint_5(temp_v0), 1);
    func_800FFAB0(arg0);
}

/* extern */

void sueggmisc_entrypoint_2(s32 arg0, s32 arg1) {
    s32 _fxsparkle_entrypoint_1(s32, s32);
    s32 _gcegg_entrypoint_3(s32);
    s32 _gcegg_entrypoint_4(s32);
    s32 func_800FC660(s32);
    _fxsparkle_entrypoint_1(arg0, _gcegg_entrypoint_4(arg1));
    func_800FC660(_gcegg_entrypoint_3(arg1));
}

void sueggmisc_entrypoint_3(void) {
    func_800DA544(2609);
}
