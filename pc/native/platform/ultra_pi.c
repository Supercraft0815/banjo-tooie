// Parallel interface: cartridge DMA reads from the original ROM image (big-endian .z64).
#include <stdio.h>
#include <stdlib.h>
#include <ultra64.h>
#include "native_os.h"

static unsigned char *rom;
static u32 rom_size;
static OSPiHandle cart_handle;

s32 osTvType = OS_TV_NTSC;
s32 osResetType = 0;
void *osRomBase;
u32 osViClock = 48681812; // VI_NTSC_CLOCK
s32 osAppNMIBuffer[16];

void bt_rom_open(const char *path) {
    FILE *f = fopen(path, "rb");
    long n;
    if (!f) {
        fprintf(stderr, "bt_native: cannot open ROM %s (pass the .z64 path as first argument)\n", path);
        exit(1);
    }
    fseek(f, 0, SEEK_END);
    n = ftell(f);
    fseek(f, 0, SEEK_SET);
    rom = malloc((size_t)n);
    if (!rom || fread(rom, 1, (size_t)n, f) != (size_t)n) {
        fprintf(stderr, "bt_native: cannot read ROM %s\n", path);
        exit(1);
    }
    fclose(f);
    rom_size = (u32)n;
    if (rom[0] != 0x80 || rom[1] != 0x37) {
        fprintf(stderr, "bt_native: %s is not a big-endian .z64 ROM\n", path);
        exit(1);
    }
}

const unsigned char *bt_rom_data(u32 *size) {
    if (size) *size = rom_size;
    return rom;
}

static void rom_read(u32 dev, void *dst, u32 n) {
    dev &= 0x0FFFFFFF; // cartridge domain addresses (0x10000000 + offset) or plain offsets
    if (!rom) {
        fprintf(stderr, "bt_native: ROM read before bt_rom_open\n");
        abort();
    }
    if (dev > rom_size || n > rom_size - dev) {
        fprintf(stderr, "bt_native: ROM read 0x%x+0x%x beyond the image\n", dev, n);
        abort();
    }
    __builtin_memcpy(dst, rom + dev, n);
}

void osCreatePiManager(OSPri pri, OSMesgQueue *cmdQ, OSMesg *cmdBuf, s32 cmdMsgCnt) {
    (void)pri; (void)cmdQ; (void)cmdBuf; (void)cmdMsgCnt;
}

// DMA completes immediately; the completion message goes to the caller's queue.
s32 osPiStartDma(OSIoMesg *mb, s32 pri, s32 direction, u32 devAddr, void *vAddr, u32 nbytes, OSMesgQueue *mq) {
    (void)pri;
    if (direction != OS_READ) {
        fprintf(stderr, "bt_native: PI write to 0x%x is not supported\n", devAddr);
        abort();
    }
    rom_read(devAddr, vAddr, nbytes);
    if (mb) {
        mb->hdr.pri = pri;
        mb->hdr.retQueue = mq;
        mb->dramAddr = vAddr;
        mb->devAddr = devAddr;
        mb->size = nbytes;
        mb->piHandle = &cart_handle;
    }
    bt_os_post(mq, (OSMesg)mb);
    return 0;
}

s32 osEPiStartDma(OSPiHandle *h, OSIoMesg *mb, s32 direction) {
    (void)h;
    return osPiStartDma(mb, mb->hdr.pri, direction, mb->devAddr, mb->dramAddr, mb->size, mb->hdr.retQueue);
}

OSPiHandle *osCartRomInit(void) {
    return &cart_handle;
}

u32 osPiGetStatus(void) {
    return 0;
}

s32 osPiReadIo(u32 devAddr, u32 *data) {
    unsigned char b[4];
    rom_read(devAddr, b, 4);
    *data = (u32)b[0] << 24 | (u32)b[1] << 16 | (u32)b[2] << 8 | b[3];
    return 0;
}
