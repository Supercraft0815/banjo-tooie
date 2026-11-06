// Serial interface: controller 1 and the 16 Kbit EEPROM (saved to bt_eeprom.bin).
// Controller reads finish at once and post the SI event, like the real interrupt.
#include <pthread.h>
#include <stdio.h>
#include <ultra64.h>
#include "native_os.h"
#include "native_si.h"

#define EEPROM_SIZE (EEP16K_MAXBLOCKS * EEPROM_BLOCK_SIZE)
#define EEPROM_PATH "bt_eeprom.bin" // shortcut: save file in the working directory, move to a user data dir with the SDL frontend

static pthread_mutex_t pad_lock = PTHREAD_MUTEX_INITIALIZER;
static OSContPad pad;
static u8 eeprom[EEPROM_SIZE];
static int eeprom_loaded;

void bt_si_set_pad(u16 buttons, s8 stick_x, s8 stick_y) {
    pthread_mutex_lock(&pad_lock);
    pad.button = buttons;
    pad.stick_x = stick_x;
    pad.stick_y = stick_y;
    pthread_mutex_unlock(&pad_lock);
}

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

s32 osContSetCh(u8 ch) {
    (void)ch;
    return 0;
}

s32 osContStartReadData(OSMesgQueue *mq) {
    (void)mq;
    bt_os_event(OS_EVENT_SI);
    return 0;
}

void osContGetReadData(OSContPad *data) {
    pthread_mutex_lock(&pad_lock);
    data[0] = pad;
    pthread_mutex_unlock(&pad_lock);
    data[0].errno = 0;
    for (int i = 1; i < MAXCONTROLLERS; i++) {
        data[i] = (OSContPad){0};
        data[i].errno = CONT_NO_RESPONSE_ERROR;
    }
}

// No Controller Pak or Rumble Pak.
s32 osPfsInit(OSMesgQueue *mq, OSPfs *pfs, int channel) {
    (void)mq; (void)pfs; (void)channel;
    return PFS_ERR_NOPACK;
}

s32 osMotorInit(OSMesgQueue *mq, OSPfs *pfs, int channel) {
    (void)mq; (void)pfs; (void)channel;
    return PFS_ERR_NOPACK;
}

static void eeprom_load(void) {
    FILE *f;
    if (eeprom_loaded) return;
    eeprom_loaded = 1;
    f = fopen(EEPROM_PATH, "rb");
    if (!f) return; // new save: zeros
    if (fread(eeprom, 1, EEPROM_SIZE, f) != EEPROM_SIZE) fprintf(stderr, "bt_native: %s is short\n", EEPROM_PATH);
    fclose(f);
}

s32 osEepromProbe(OSMesgQueue *mq) {
    (void)mq;
    return EEPROM_TYPE_16K;
}

static int eeprom_range(u8 block, int n) {
    return n >= 0 && block * EEPROM_BLOCK_SIZE + n <= EEPROM_SIZE;
}

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
        perror("bt_native: cannot write " EEPROM_PATH);
        if (f) fclose(f);
        return -1;
    }
    fclose(f);
    return 0;
}
