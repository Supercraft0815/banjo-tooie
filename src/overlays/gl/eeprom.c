#include "common.h"

typedef struct { u8 pad0[0xF0]; s32 unkF0; } Objeeprom_D_8007DA60; /* offsets.py genstruct: fields from raw offsets on &D_8007DA60; rename once understood */ s32 gleeprom_entrypoint_0(void) {
    extern s32 D_8007DA60;
    return (((Objeeprom_D_8007DA60 *)&D_8007DA60)->unkF0) ^ 0xBD1F0416;
}

/* extern */

s32 gleeprom_entrypoint_1(s32 arg0, u8 *arg1, s32 arg2) {
    OSMesgQueue *func_80016928();
    void func_80016934(s32 arg0);
    s32 sp18;
    s32 temp_v0;

    func_80016934(3);
    temp_v0 = osEepromLongWrite(func_80016928(), (arg0 / 8) & 0xFF, arg1, arg2);
    sp18 = temp_v0;
    func_80016934(0);
    return temp_v0;
}

/* extern */

s32 gleeprom_entrypoint_2(s32 arg0, u8 *arg1, s32 arg2) {
    OSMesgQueue *func_80016928();
    void func_80016934(s32 arg0);
    s32 sp18;
    s32 temp_v0;

    func_80016934(3);
    temp_v0 = osEepromLongRead(func_80016928(), (arg0 / 8) & 0xFF, arg1, arg2);
    sp18 = temp_v0;
    func_80016934(0);
    return temp_v0;
}
