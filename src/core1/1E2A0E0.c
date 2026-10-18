#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2A0E0/func_800125B0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2A0E0/func_8001268C.s")

// audio_thread_entry
void func_800128C0(void *arg) {
    s32 func_800129FC(s32, s32);
    void func_80012B74(s32);
    void func_800E96B0(s32);
    extern OSMesg D_8003CC5C;
    extern s32 D_8003CC60;
    extern s32 D_800459E0[];
    extern u8 D_80045BB8[];
    extern OSMesgQueue D_80045BF0;
    extern u32 D_8006A148;
    s32 skip_handle_done_mesg = 1;

    while (TRUE) {
        osRecvMesg(D_80045BB8, NULL, OS_MESG_BLOCK);
        if (func_800129FC(D_800459E0[(s32)D_8006A148 % 3 + 2], D_8003CC60)) {
            if (skip_handle_done_mesg == 0) {
                osRecvMesg(&D_80045BF0, &D_8003CC5C, OS_MESG_BLOCK);
                func_80012B74(((s32 *)D_8003CC5C)[1]);
                D_8003CC60 = ((s32 *)D_8003CC5C)[1];
            } else {
                skip_handle_done_mesg--;
            }
        }
        func_800E96B0(1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2A0E0/func_800129FC.s")

void func_80012B74(s32 arg0) {
    extern s32 D_8003CC64[1];
    s32 i;
    if (((osAiGetLength() >> 2) == 0) && (D_8003CC64[0] == 0)) {
        for (i = 0; i < 1; i = 1) {
            D_8003CC64[i] = 0;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2A0E0/func_80012BB4.s")

s32 *func_80012D4C(s32 **arg0) {
    extern s32 D_80069A30;
    extern s32 D_80069A40;
    extern s32 func_80012BB4;
    if ((*(u8 *)((s8 *)(&D_80069A30) + (0))) == 0) {
        (*(s32 *)((s8 *)(&D_80069A30) + (4))) = 0;
        (*(s32 **)((s8 *)(&D_80069A30) + (8))) = &D_80069A40;
        (*(u8 *)((s8 *)(&D_80069A30) + (0))) = 1U;
    }
    *arg0 = &D_80069A30;
    return &func_80012BB4;
}

void func_80012D84(void) {
    void func_80020E40(ALLink *, ALLink *);
    void func_80020E74(ALLink *);
    extern u8 D_80069488[];
    extern s32 D_80069A30;
    extern u32 D_8006A148;
    extern u32 D_8006A14C;
    OSMesg msg[2];
    u32 i;
    void *next;
    void *node;

    msg[0] = NULL;
    i = 0;
    if (D_8006A14C != 0) {
        do {
            osRecvMesg((OSMesgQueue *)D_80069488, msg, OS_MESG_NOBLOCK);
            i++;
        } while (i < D_8006A14C);
    }
    node = *(void **)((u8 *)&D_80069A30 + 4);
    if (node != NULL) {
        do {
            next = *(void **)node;
            if ((u32)(*(s32 *)((u8 *)node + 0xC) + 1) < D_8006A148) {
                if (node == *(void **)((u8 *)&D_80069A30 + 4)) {
                    *(void **)((u8 *)&D_80069A30 + 4) = *(void **)node;
                }
                func_80020E74(node);
                if (*(void **)((u8 *)&D_80069A30 + 8) != NULL) {
                    func_80020E40(node, *(void **)((u8 *)&D_80069A30 + 8));
                } else {
                    *(void **)((u8 *)&D_80069A30 + 8) = node;
                    *(void **)node = NULL;
                    *(void **)((u8 *)node + 4) = NULL;
                }
            }
            node = next;
        } while (next != NULL);
    }
    D_8006A14C = 0;
    D_8006A148++;
}

void func_80012EA0(void) {
    extern s32 D_8003CA40;
    extern OSThread D_800459F8;
    if (D_8003CA40 == 0) {
        D_8003CA40 = 1;
        osStartThread(&D_800459F8);
    }
}

void *func_80012EDC(void) {
    extern u8 D_80046A78[];

    return D_80046A78;
}

void *func_80012EE8(void) {
    extern u8 D_80069488[];

    return D_80069488;
}

void *func_80012EF4(void) {
    extern u8 D_80069568[];

    return D_80069568;
}

void *func_80012F00(void) {
    extern u8 D_80045BB8[];
    return D_80045BB8;
}

void func_80012F0C(s32 arg0) {
    s32 func_80021A00(s32);
    extern s16 D_8006A1CC;
    D_8006A1CC = arg0;
    func_80021A00(arg0 & 0xFF);
}

void func_80012F34(s32 arg0, s32 arg1) {
    s32 func_80021AD0();
    extern s32 D_8006A1CE;
    *(((volatile s16 *)&D_8006A1CE) + arg0) = arg1;
    func_80021AD0();
}

void *func_80012F60(void) {
    extern u8 D_8007695C[];
    return D_8007695C;
}

void *func_80012F6C(void) {
    extern u8 D_80076940[];
    return D_80076940;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2A0E0/rom_dma_read.s")

void func_8001311C(u8 *arg0, s32 arg1) {
    extern s32 D_8003CC70;
    extern u8 D_80076940[];
    extern u8 D_8007695C[];
    osWritebackDCache(arg0, 0x1800);
    D_8003CC70++;
    osPiStartDma((OSIoMesg *) D_80076940, 0, 0, arg1, arg0, 0x1800, (OSMesgQueue *) D_8007695C);
    osRecvMesg((OSMesgQueue *) D_8007695C, NULL, 1);
    D_8003CC70--;
    osInvalDCache(arg0, 0x1800);
}

void func_800131C0(void) {
    extern u8 D_8007695C[];
    extern u8 *D_80076958;
    extern u8 *D_80076978;
    extern OSMesgQueue D_800769B8;
    osCreateMesgQueue((OSMesgQueue *) D_8007695C, &D_80076958, 1);
    osCreateMesgQueue(&D_800769B8, &D_80076978, 0x10);
    osCreatePiManager(0x96, &D_800769B8, &D_80076978, 0x10);
}

void func_80013224(u32 arg0, void *arg1, s32 arg2) {
    extern s32 D_8003CC70;
    extern s32 D_800769CC[];
    extern s32 D_800769D0[];
    extern u8 D_80076940[];
    extern u8 D_8007695C[];

    D_8003CC70++;
    D_800769CC[D_8003CC70] = (s32) arg1;
    D_800769D0[D_8003CC70] = arg2;
    osWritebackDCache(arg1, arg2);
    osPiStartDma((OSIoMesg *) D_80076940, 0, 0, arg0, arg1, arg2, (OSMesgQueue *) D_8007695C);
}

void func_800132BC(void) {
    extern u8 D_8007695C[];
    extern s32 D_8003CC70;
    extern s32 D_800769CC[];
    extern s32 D_800769D0[];

    osRecvMesg((OSMesgQueue *) D_8007695C, NULL, 1);
    osInvalDCache(D_800769CC[D_8003CC70], D_800769D0[D_8003CC70]);
    D_8003CC70 -= 1;
}

void func_80013324(u32 arg0, void *arg1, s32 arg2)
{
    func_80013224(arg0, arg1, arg2);
    func_800132BC();
}

void func_8001334C(void) {
    extern s32 D_8003CC70;
    if (D_8003CC70 > 0) {
        do {
            func_800132BC();
        } while (D_8003CC70 > 0);
    }
}
