// Guest side of libultra. Threads, message queues, events, timers and the VI run
// on the host (host/os.c, host/vi.c), which reads and writes the guest's OSThread,
// OSMesgQueue and OSTimer structs in place. PI DMA, the controller and the EEPROM
// are guest code over a few host calls.
#include <ultra64.h>
_Noreturn void bt_unported(const char *name); // guest/libc.c
#include "bt_guest.h"

void BT_HOST(osCreateThread)(OSThread *, OSId, void (*)(void *), void *, void *, OSPri);
void BT_HOST(osStartThread)(OSThread *);
void BT_HOST(osStopThread)(OSThread *);
void BT_HOST(osDestroyThread)(OSThread *);
void BT_HOST(osYieldThread)(void);
OSPri BT_HOST(osGetThreadPri)(OSThread *);
OSId BT_HOST(osGetThreadId)(OSThread *);
void BT_HOST(osSetThreadPri)(OSThread *, OSPri);
s32 BT_HOST(osSendMesg)(OSMesgQueue *, OSMesg, s32);
s32 BT_HOST(osJamMesg)(OSMesgQueue *, OSMesg, s32);
s32 BT_HOST(osRecvMesg)(OSMesgQueue *, OSMesg *, s32);
void BT_HOST(osSetEventMesg)(OSEvent, OSMesgQueue *, OSMesg);
void BT_HOST(event)(OSEvent);
OSIntMask BT_HOST(osSetIntMask)(OSIntMask);
u64 BT_HOST(osGetTime)(void);
int BT_HOST(osSetTimer)(OSTimer *, u64, u64, OSMesgQueue *, OSMesg);
int BT_HOST(osStopTimer)(OSTimer *);
void BT_HOST(osInitialize)(void);
void BT_HOST(osViSetEvent)(OSMesgQueue *, OSMesg, u32);
void BT_HOST(osViSetMode)(OSViMode *);
void BT_HOST(osViBlack)(u32);
void BT_HOST(osViSwapBuffer)(void *);
void *BT_HOST(osViGetCurrentFramebuffer)(void);
void *BT_HOST(osViGetNextFramebuffer)(void);
u32 BT_HOST(osViGetCurrentLine)(void);
s32 BT_HOST(rom_read)(u32 dev, void *dst, u32 n);
u32 BT_HOST(pad_read)(void); // buttons << 16 | (u8)stick_x << 8 | (u8)stick_y

// Values libultra keeps in low memory (0x80000300..) on the N64.
s32 osTvType = OS_TV_NTSC;
s32 osResetType = 0;
s32 osRomType = 0;
void *osRomBase = (void *)0xB0000000;
u32 osMemSize = 0x800000;
u32 osViClock = VI_NTSC_CLOCK;
s32 osAppNMIBuffer[16];

void osCreateThread(OSThread *t, OSId id, void (*entry)(void *), void *arg, void *sp, OSPri pri) { host_osCreateThread(t, id, entry, arg, sp, pri); }
void osStartThread(OSThread *t) { host_osStartThread(t); }
void osStopThread(OSThread *t) { host_osStopThread(t); }
void osDestroyThread(OSThread *t) { host_osDestroyThread(t); }
void osYieldThread(void) { host_osYieldThread(); }
OSPri osGetThreadPri(OSThread *t) { return host_osGetThreadPri(t); }
OSId osGetThreadId(OSThread *t) { return host_osGetThreadId(t); }
void osSetThreadPri(OSThread *t, OSPri pri) { host_osSetThreadPri(t, pri); }

void osCreateMesgQueue(OSMesgQueue *mq, OSMesg *msg, s32 count) {
    mq->mtqueue = NULL;
    mq->fullqueue = NULL;
    mq->validCount = 0;
    mq->first = 0;
    mq->msgCount = count;
    mq->msg = msg;
}

s32 osSendMesg(OSMesgQueue *mq, OSMesg msg, s32 flag) { return host_osSendMesg(mq, msg, flag); }
s32 osJamMesg(OSMesgQueue *mq, OSMesg msg, s32 flag) { return host_osJamMesg(mq, msg, flag); }
s32 osRecvMesg(OSMesgQueue *mq, OSMesg *msg, s32 flag) { return host_osRecvMesg(mq, msg, flag); }
void osSetEventMesg(OSEvent e, OSMesgQueue *mq, OSMesg msg) { host_osSetEventMesg(e, mq, msg); }

OSIntMask osSetIntMask(OSIntMask mask) { return host_osSetIntMask(mask); }
u32 __osDisableInt(void) { return osSetIntMask(OS_IM_NONE) != OS_IM_NONE; }
void __osRestoreInt(u32 enabled) { if (enabled) osSetIntMask(OS_IM_ALL); }
u32 __osGetSR_2(void) { return SR_IBIT5; } // no PRE-NMI pending

OSTime osGetTime(void) { return host_osGetTime(); }
u32 osGetCount(void) { return (u32)host_osGetTime(); }
int osSetTimer(OSTimer *t, OSTime countdown, OSTime interval, OSMesgQueue *mq, OSMesg msg) { return host_osSetTimer(t, countdown, interval, mq, msg); }
int osStopTimer(OSTimer *t) { return host_osStopTimer(t); }

void osInitialize(void) { host_osInitialize(); }
u32 osGetMemSize(void) { return osMemSize; }

// The host has coherent caches and no TLB.
void osWritebackDCache(void *p, s32 n) { (void)p; (void)n; }
void osWritebackDCacheAll(void) {}
void osInvalDCache(void *p, s32 n) { (void)p; (void)n; }
void osInvalICache(void *p, s32 n) { (void)p; (void)n; }
void osMapTLBRdb(void) {}
void osUnmapTLBAll(void) {}

// Video interface.
void osCreateViManager(OSPri pri) { (void)pri; }
void osViSetEvent(OSMesgQueue *mq, OSMesg msg, u32 retrace) { host_osViSetEvent(mq, msg, retrace); }
void osViSetMode(OSViMode *mode) { host_osViSetMode(mode); }
void osViBlack(u8 black) { host_osViBlack(black); }
void osViSetSpecialFeatures(u32 f) { (void)f; }
void osViSetXScale(f32 s) { (void)s; }
void osViSetYScale(f32 s) { (void)s; }
void osViSwapBuffer(void *fb) { host_osViSwapBuffer(fb); }
void *osViGetCurrentFramebuffer(void) { return host_osViGetCurrentFramebuffer(); }
void *osViGetNextFramebuffer(void) { return host_osViGetNextFramebuffer(); }
u32 osViGetCurrentLine(void) { return host_osViGetCurrentLine(); }

// Parallel interface: DMA from the ROM image completes at once.
static OSPiHandle cart_handle;

void osCreatePiManager(OSPri pri, OSMesgQueue *cmdQ, OSMesg *cmdBuf, s32 cmdMsgCnt) {
    (void)pri; (void)cmdQ; (void)cmdBuf; (void)cmdMsgCnt;
}

s32 osPiStartDma(OSIoMesg *mb, s32 pri, s32 direction, u32 devAddr, void *vAddr, u32 nbytes, OSMesgQueue *mq) {
    if (direction != OS_READ) bt_unported("osPiStartDma (write)");
    host_rom_read(devAddr, vAddr, nbytes);
    if (mb) {
        mb->hdr.pri = pri;
        mb->hdr.retQueue = mq;
        mb->dramAddr = vAddr;
        mb->devAddr = devAddr;
        mb->size = nbytes;
        mb->piHandle = &cart_handle;
    }
    if (mq) osSendMesg(mq, (OSMesg)mb, OS_MESG_NOBLOCK);
    return 0;
}

s32 osEPiStartDma(OSPiHandle *h, OSIoMesg *mb, s32 direction) {
    (void)h;
    return osPiStartDma(mb, mb->hdr.pri, direction, mb->devAddr, mb->dramAddr, mb->size, mb->hdr.retQueue);
}

OSPiHandle *osCartRomInit(void) { return &cart_handle; }
u32 osPiGetStatus(void) { return 0; }

s32 osPiReadIo(u32 devAddr, u32 *data) {
    u8 b[4];
    host_rom_read(devAddr, b, 4);
    *data = (u32)b[0] << 24 | (u32)b[1] << 16 | (u32)b[2] << 8 | b[3];
    return 0;
}

// Serial interface: controller 1 from the host, the 16 Kbit EEPROM in a file.
s32 osContInit(OSMesgQueue *mq, u8 *bitpattern, OSContStatus *status) {
    (void)mq;
    *bitpattern = 1;
    for (int i = 0; i < MAXCONTROLLERS; i++) {
        status[i].type = i == 0 ? CONT_TYPE_NORMAL : 0;
        status[i].status = 0;
        status[i].errno = i == 0 ? 0 : CONT_NO_RESPONSE_ERROR;
    }
    return 0;
}

s32 osContSetCh(u8 ch) { (void)ch; return 0; }

s32 osContStartReadData(OSMesgQueue *mq) {
    (void)mq;
    host_event(OS_EVENT_SI); // the read completes at once, like the SI interrupt
    return 0;
}

void osContGetReadData(OSContPad *data) {
    u32 pad = host_pad_read();
    data[0].button = pad >> 16;
    data[0].stick_x = (s8)(pad >> 8);
    data[0].stick_y = (s8)pad;
    data[0].errno = 0;
    for (int i = 1; i < MAXCONTROLLERS; i++) {
        data[i].button = 0;
        data[i].stick_x = data[i].stick_y = 0;
        data[i].errno = CONT_NO_RESPONSE_ERROR;
    }
}

s32 osPfsInit(OSMesgQueue *mq, OSPfs *pfs, int channel) { (void)mq; (void)pfs; (void)channel; return PFS_ERR_NOPACK; }
s32 osMotorInit(OSMesgQueue *mq, OSPfs *pfs, int channel) { (void)mq; (void)pfs; (void)channel; return PFS_ERR_NOPACK; }

#include "stdio.h"
#define EEPROM_SIZE (EEP16K_MAXBLOCKS * EEPROM_BLOCK_SIZE)
#define EEPROM_PATH "bt_eeprom.bin" // shortcut: save file in the working directory, move to a user data dir with the SDL frontend
static u8 eeprom[EEPROM_SIZE];
static int eeprom_loaded;

static void eeprom_load(void) {
    FILE *f;
    if (eeprom_loaded) return;
    eeprom_loaded = 1;
    f = fopen(EEPROM_PATH, "rb");
    if (!f) return; // new save: zeros
    if (fread(eeprom, 1, EEPROM_SIZE, f) != EEPROM_SIZE) fprintf(stderr, "bt_native: %s is short\n", EEPROM_PATH);
    fclose(f);
}

s32 osEepromProbe(OSMesgQueue *mq) { (void)mq; return EEPROM_TYPE_16K; }

static int eeprom_range(u8 block, int n) { return n >= 0 && block * EEPROM_BLOCK_SIZE + n <= EEPROM_SIZE; }

s32 osEepromLongRead(OSMesgQueue *mq, u8 block, u8 *buf, int n) {
    (void)mq;
    if (!eeprom_range(block, n)) return -1;
    eeprom_load();
    __builtin_memcpy(buf, eeprom + block * EEPROM_BLOCK_SIZE, n);
    return 0;
}

s32 osEepromLongWrite(OSMesgQueue *mq, u8 block, u8 *buf, int n) {
    FILE *f;
    (void)mq;
    if (!eeprom_range(block, n)) return -1;
    eeprom_load();
    __builtin_memcpy(eeprom + block * EEPROM_BLOCK_SIZE, buf, n);
    f = fopen(EEPROM_PATH, "wb");
    if (!f || fwrite(eeprom, 1, EEPROM_SIZE, f) != EEPROM_SIZE) {
        fprintf(stderr, "bt_native: cannot write %s\n", EEPROM_PATH);
        if (f) fclose(f);
        return -1;
    }
    fclose(f);
    return 0;
}

// RCP: the host runs each task (host/rcp.c) and raises SP (and DP for graphics) at once.
void BT_HOST(rcp_task)(OSTask *t);
void osSpTaskLoad(OSTask *t) { (void)t; }
void osSpTaskStartGo(OSTask *t) { host_rcp_task(t); }
void osSpTaskYield(void) {}
OSYieldResult osSpTaskYielded(OSTask *t) { (void)t; return 0; }
u32 osDpGetStatus(void) { return 0; } // never busy
void osDpSetStatus(u32 status) { (void)status; }

// Audio interface: the host plays the buffers (host/ai.c).
u32 BT_HOST(ai_frequency)(u32);
void BT_HOST(ai_buffer)(void *, u32);
u32 BT_HOST(ai_length)(void);
s32 osAiSetFrequency(u32 freq) { return (s32)host_ai_frequency(freq); }
s32 osAiSetNextBuffer(void *buf, u32 size) { host_ai_buffer(buf, size); return 0; }
u32 osAiGetLength(void) { return host_ai_length(); }
u32 osAiGetStatus(void) { return 0; }

// Entry from the host: the boot context runs on its own guest stack.
static u64 boot_stack[0x10000];
u32 bt_guest_boot_stack_top(void) { return (u32)&boot_stack[0x10000]; }

void func_80012030(void *unused); // core1 entrypoint (src/core1/1E29B60.c)
int native_assets_open(const char *path);
void bt_guest_start(void) {
    // The asset archive (banjotooie.ld: assets_ROM_START..assets_ROM_END of the US ROM).
    if (!native_assets_open("rom:5180-1a14580")) bt_unported("asset archive (ROM is not the US version?)");
    func_80012030(NULL);
}
