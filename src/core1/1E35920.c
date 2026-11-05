#include "common.h"

extern OSMesgQueue *func_80016928(void);
extern void func_80016934(s32);
extern u8 *func_8001B798(s16);
extern OSThread *func_80012598(void);
extern void func_8001DCB0(OSThread *, void *, s32, void (*)(void *), void *, void *, s32);
extern s32 __osSiGetAccess(void);
extern void __osSiRelAccess(void);
extern s32 __osSiRawStartDma(s32, void *);

extern u8 __osContLastCmd;
u8 D_8007D850[0x40];
OSMesg D_8007D890[2];
OSMesgQueue D_8007D898;
OSThread D_8007D8B0;
u8 D_8007DA60[0x110];
s16 D_8007DB70[4];
u8 D_8007DB78;
u8 D_8007DB79;

void func_8001DE64(void *arg);
void func_8001DEE8(void);
void cic_send_challenge(u8 *challenge, OSMesgQueue *queue);
void cic_read_response(OSMesgQueue *queue);
void func_8001E170(u8 *response);

void func_8001DDF0(void) {
    osCreateMesgQueue(&D_8007D898, D_8007D890, 1);
    func_8001DCB0(&D_8007D8B0, D_8007DA60, 3, func_8001DE64, NULL, D_8007DB70, 0x1E);
    osStartThread(&D_8007D8B0);
}

#ifdef BT_NATIVE
#include "native_cic.h"

void func_8001DE64(void *arg) {
    // The two IPL3 words read on the N64 hold their expected values; the host has no IPL3.
    D_8007DB79 = 0;
    func_8001DEE8();
}

// The PIF's CIC exchange becomes the pure C CIC-6105 response.
void func_8001DEE8(void) {
    s16 request;
    s32 i;
    u8 response[16];
    u8 *buffer;

    D_8007DB78 = 0;
    while (TRUE) {
        osRecvMesg(&D_8007D898, NULL, OS_MESG_BLOCK);
        D_8007DB78--;
        request = D_8007DB70[0];
        for (i = 0; i < 3; i++) {
            D_8007DB70[i] = D_8007DB70[i + 1];
        }
        func_80016934(5);
        buffer = func_8001B798(request);
        native_cic_response(buffer, response);
        for (i = 0; i < 0x10; i++) {
            buffer[i] = response[i];
        }
        func_80016934(0);
    }
}
#else
void func_8001DE64(void *arg) {
    s32 pad[2];
    s32 first = *(s32 *)0xA02FB1F4;
    s32 second = *(s32 *)0xA02FE1C0;

    if (osTvType == 0) {
        osSetThreadPri(func_80012598(), 0);
    }
    D_8007DB79 = (first ^ 0xAD090010) | (second ^ 0xAD170014);
    func_8001DEE8();
}

void func_8001DEE8(void) {
    OSMesgQueue *queue = func_80016928();
    s16 request;
    s32 i;

    D_8007DB78 = 0;
    while (TRUE) {
        osRecvMesg(&D_8007D898, NULL, OS_MESG_BLOCK);
        D_8007DB78--;
        request = D_8007DB70[0];
        for (i = 0; i < 4; i++) {
            D_8007DB70[i] = D_8007DB70[i + 1];
        }
        func_80016934(5);
        cic_send_challenge(func_8001B798(request), queue);
        osRecvMesg(queue, NULL, OS_MESG_BLOCK);
        cic_read_response(queue);
        osRecvMesg(queue, NULL, OS_MESG_BLOCK);
        func_80016934(0);
        func_8001E170(func_8001B798(request));
    }
}
#endif

void func_8001E010(void) {
    if (D_8007DB78 != 0) {
        osSendMesg(&D_8007D898, NULL, OS_MESG_NOBLOCK);
    }
}

void cic_send_challenge(u8 *challenge, OSMesgQueue *queue) {
    s32 i;

    for (i = 0; i < 0x2E; i++) {
        D_8007D850[i] = 0xFF;
    }
    D_8007D850[0x2E] = 0xF;
    D_8007D850[0x2F] = 0xF;
    for (i = 0; i < 0x10; i++) {
        D_8007D850[0x30 + i] = challenge[i];
    }
    __osSiGetAccess();
    __osContLastCmd = 0xFE;
    osWritebackDCache(D_8007D850, 0x40);
    __osSiRawStartDma(OS_WRITE, D_8007D850);
    __osSiRelAccess();
}

void cic_read_response(OSMesgQueue *queue) {
    __osSiGetAccess();
    __osContLastCmd = 0xFE;
    osInvalDCache(D_8007D850, 0x40);
    __osSiRawStartDma(OS_READ, D_8007D850);
    __osSiRelAccess();
}

void func_8001E170(u8 *response) {
    s32 i;

    for (i = 0; i < 0x10; i++) {
        response[i] = D_8007D850[0x30 + i];
    }
}

s32 func_8001E1B8(s16 request) {
    if (D_8007DB78 == 4) {
        return FALSE;
    }
    D_8007DB70[D_8007DB78] = request;
    D_8007DB78++;
    return TRUE;
}

u8 func_8001E204(void) {
    return D_8007DB79;
}
