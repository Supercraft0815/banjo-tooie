#include "common.h"
struct PreloadEntry { s16 first; s16 second; };
typedef struct { u8 pad0[0x184]; s32 unk184; } Objpreload_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */ void func_80800000_bapreload(void *arg0, s32 arg1, s16 *arg2, s16 *arg3) {
    s32 func_800A940C(s32);
    s32 func_800EA068(s32);
    extern struct PreloadEntry D_808002F0_bapreload[4];
    extern struct PreloadEntry D_80800300_bapreload[4];
    extern struct PreloadEntry D_80800310_bapreload[4];
    extern struct PreloadEntry D_80800320_bapreload[4];

    struct PreloadEntry *table;
    s32 index;

    switch (arg1) {
    case 6:
        table = D_80800310_bapreload;
        break;
    case 12:
        table = D_80800320_bapreload;
        break;
    case 11:
        table = D_80800300_bapreload;
        break;
    case 1:
        table = D_808002F0_bapreload;
        break;
    case 17:
        *arg2 = 0x60E;
        *arg3 = 0;
        return;
    default:
        *arg2 = 0x607;
        *arg3 = 0;
        return;
    }
    if (func_800EA068(0x20) != 0) {
        index = func_800A940C(((Objpreload_arg0 *)arg0)->unk184);
    } else {
        index = ((Objpreload_arg0 *)arg0)->unk184;
    }
    table += index;
    *arg2 = table->first;
    *arg3 = table->second;
}

void bapreload_entrypoint_0(void *arg0, s32 arg1, s16 *arg2, s16 *arg3) {
    s32 func_8009EA2C(void);
    s32 func_800D3948(void);
    extern u8 D_8012762C;
    extern struct PreloadEntry D_808002A0_bapreload[20];
    if (func_800D3948() != 0) {
        func_80800000_bapreload(arg0, arg1, arg2, arg3);
        return;
    }
    if (arg1 == 0xB) {
        if (func_8009EA2C() != 0) {
            *arg2 = 0x83A;
        } else {
            *arg2 = 0x61C;
        }
        *arg3 = 0;
        return;
    }
    *arg2 = D_808002A0_bapreload[arg1].first;
    *arg3 = 0;
    if (*arg2 == 0) {
        if (D_8012762C == 0xD) {
            *arg2 = 0;
            return;
        }
        *arg2 = 0x607;
    }
}

s32 bapreload_entrypoint_1(s32 arg0, s32 *arg1) {
    s32 func_8009EA2C(void);
    extern struct PreloadEntry D_808002A0_bapreload[20];
    s32 var_v1;
    var_v1 = D_808002A0_bapreload[arg0].second;
    *arg1 = 0;
    switch (arg0) {
    case 0xB:
        if (func_8009EA2C() != 0) {
            var_v1 = 0x62E;
        }
        break;
    case 1:
    case 0xA:
        if (func_8009EA2C() != 0) {
            *arg1 = 1;
        }
        break;
    }
    return var_v1;
}
#include "preload_data.inc"
