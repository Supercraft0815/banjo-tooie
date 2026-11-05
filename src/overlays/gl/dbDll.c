#include "common.h"
#include "overlays/gl/dbDll.h"
#ifdef BT_NATIVE
#include "native_cic.h"
#include "native_assets.h"
#endif

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

#ifndef BT_NATIVE
    queue = func_80016928();
#endif
    for (i = 0; i < 14; i += 2) {
#ifdef BT_NATIVE
        value = ((u32)arg1 >> i) | ((u32)arg1 << (16 - i));
#else
        value = (arg1 >> i) | (arg1 << (16 - i));
#endif
        challenge[i] = value;
        challenge[i + 1] = value & 0xFF00;
    }
    challenge[14] = 0;
    challenge[15] = 2;
    for (i = 0; i != 16; i++) {
        arg0[i] = 0;
    }
#ifdef BT_NATIVE
    native_cic_response((u8 *)challenge, arg0);
#else
    func_80016934(5);
    cic_send_challenge(challenge, queue);
    osRecvMesg(queue, NULL, 1);
    cic_read_response(queue);
    osRecvMesg(queue, NULL, 1);
    func_8001E170(arg0);
    func_80016934(0);
#endif
}

void func_808000E8_gldbDll(s32 *arg0, s32 arg1, s32 arg2) {
    u8 response[16];
    s32 i;

    func_80800000_gldbDll(response, arg1);
    for (i = 0; i < arg2; i++) {
        ((u8 *)arg0)[i] = ((u8 *)arg0)[i] ^ response[i % 14];
    }
}

/* extern */

s32 *gldbDll_entrypoint_0(s32 arg0, s32 *arg1) {
#ifdef BT_NATIVE
    return native_asset_load(arg0, arg1);
#else
    s32 func_8001C2AC(u8 *, u8 *);
    s32 func_800D5A6C(s32);
    s32 func_800D5DB8(s32);
    void func_808000E8_gldbDll(s32 *, s32, s32);
    void *heap_alloc(s32);
    void heap_free(void *);
    void rom_dma_read(u8 *, u8 *, u32);
    s32 size;
    s32 rounded;
    s32 buffer;

    rounded = func_800D5DB8(arg0);
    size = rounded;
    if (rounded & 1) {
        rounded++;
    }
    buffer = (s32)heap_alloc(rounded);
    rom_dma_read((u8 *)buffer, (u8 *)func_800D5A6C(arg0), rounded);
    func_808000E8_gldbDll((s32 *)buffer, arg0 - 0x955, size);
    size = *(s32 *)buffer;
    size >>= 16;
    size <<= 4;
    *arg1 = size;
    size = (s32)heap_alloc(size);
    func_8001C2AC((u8 *)buffer, (u8 *)size);
    heap_free((void *)buffer);
    return (s32 *)size;
#endif
}

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
