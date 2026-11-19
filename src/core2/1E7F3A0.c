#include "common.h"
#include "camera_map_settings.inc"
void func_800A5AB0(void) {
    typedef CameraMapSettings Entry;
    typedef LevelCameraSettings Level;
    extern Entry D_8011A1B0[1];
    extern Level D_8011A1BC[];
    extern CameraMapSettings *D_80127100;
    extern u8 D_8012762C;
    s32 func_800EA05C();
    s32 i;
    s32 level = D_8012762C;
    s32 map;
    Entry *entries = D_8011A1B0;
    Entry *scan;

    for (i = 0; D_8011A1BC[i].id != 0; i++) {
        if (level == D_8011A1BC[i].id) {
            entries = D_8011A1BC[i].entries;
        }
    }
    map = func_800EA05C();
    for (i = 0; entries[i].map != 0; i++) {
        if (map == entries[i].map) {
            break;
        }
    }
    D_80127100 = &entries[i];
}

s8 func_800A5B6C(void) {
    extern CameraMapSettings *D_80127100;
    return D_80127100->first;
}

s8 func_800A5B7C(void) {
    extern CameraMapSettings *D_80127100;
    return D_80127100->second;
}

f32 func_800A5B8C(void) {
    extern CameraMapSettings *D_80127100;
    return D_80127100->factor;
}

u8 func_800A5B9C(void) {
    extern CameraMapSettings *D_80127100;
    return D_80127100->option[0];
}

u8 func_800A5BAC(void) {
    extern CameraMapSettings *D_80127100;
    return D_80127100->option[1];
}

u8 func_800A5BBC(void) {
    extern CameraMapSettings *D_80127100;
    return D_80127100->option[2];
}

u8 func_800A5BCC(void) {
    extern CameraMapSettings *D_80127100;
    return D_80127100->option[3];
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
CameraMapSettings *D_80127100 BT_DATA(4, bss_core2bss1_0_1, 0xA0);
#endif
