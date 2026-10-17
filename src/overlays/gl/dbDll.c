#include "common.h"

void func_80800000_gldbDll(u8 *arg0, s32 arg1) {
    OSMesgQueue *func_80016928();
    void func_80016934(s32);
    void cic_send_challenge(s8 *, OSMesgQueue *);
    void cic_read_response(OSMesgQueue *);
    void func_8001E170(u8 *);
    s8 challenge[20];
    OSMesgQueue *queue;
    s32 i;
    u16 value;

    queue = func_80016928();
    for (i = 0; i < 14; i += 2) {
        value = (arg1 >> i) | (arg1 << (16 - i));
        challenge[i] = value;
        challenge[i + 1] = value & 0xFF00;
    }
    challenge[14] = 0;
    challenge[15] = 2;
    for (i = 0; i != 16; i++) {
        arg0[i] = 0;
    }
    func_80016934(5);
    cic_send_challenge(challenge, queue);
    osRecvMesg(queue, NULL, 1);
    cic_read_response(queue);
    osRecvMesg(queue, NULL, 1);
    func_8001E170(arg0);
    func_80016934(0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/dbDll/func_808000E8_gldbDll.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gl/dbDll/gldbDll_entrypoint_0.s")

void gldbDll_entrypoint_1(void) {
    s32 _gleeprom_entrypoint_0(void);
    s32 _glreflight_entrypoint_0();
    void func_800DA544(GameFlag);
    s32 i;

    for (i = 0; i < 32; i += 8) {
        func_800DA544(((_gleeprom_entrypoint_0() & (0xFF << i)) >> i) + 0x9C4);
    }
    for (i = 0; i != 32; i += 8) {
        func_800DA544(((_glreflight_entrypoint_0() & (0xFF << i)) >> i) + 0x9C4);
    }
}

void gldbDll_entrypoint_2(void) {
    s32 _gleeprom_entrypoint_0(void);
    s32 _glreflight_entrypoint_0();
    void func_800DA3B8(s32, s32);
    extern s32 D_80079D70;
    s32 flags;
    s32 eeprom;
    s32 i;

    eeprom = _gleeprom_entrypoint_0();
    flags = *(s32 *)((s8 *)&D_80079D70 + 0x1EC) | _glreflight_entrypoint_0() | eeprom;
    for (i = 0; i < 8; i++) {
        func_800DA3B8(i + 0x648, (u32)((1 << i) & flags) >> i);
    }
    for (i = 8; i < 0x10; i++) {
        func_800DA3B8(i + 0x658, (u32)((1 << i) & flags) >> i);
    }
    for (i = 0x10; i < 0x18; i++) {
        func_800DA3B8(i + 0x670, (u32)((1 << i) & flags) >> i);
    }
    for (i = 0x18; i != 0x20; i++) {
        func_800DA3B8(i + 0x680, (u32)((1 << i) & flags) >> i);
    }
}
