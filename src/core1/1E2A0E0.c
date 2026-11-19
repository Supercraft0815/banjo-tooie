#include "common.h"
#include "core1/audio_config_data.h"
struct AudioConfig {
    s32 maxVVoices, maxPVoices, maxUpdates, unkC;
    s32 *(*dmaproc)(s32 **);
    ALHeap *heap;
    s32 outputRate;
    s8 fxType;
    s32 *params;
};

s32 D_8006A150;
ALGlobals D_8006A158;
struct AudioConfig D_8006A1A8;
struct AudioVolume {
    s16 master;
    s16 channels[2];
};
struct AudioVolume D_8006A1CC;
s8 D_8006A1D2;
Acmd D_8006A1D8[2][2500];
s16 D_80073E18[3][1840];

void func_800125B0(void) {
    extern ALHeap D_80046A78;
    extern u8 D_80046A88[];
    extern u32 osViClock;
    void bzero(void *, int);
    void func_8001268C(void);
    void func_800DC380(void);
    void func_80016C00(void);
    BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_80012F0C(s32);
    BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_80012F34(s32, s32);
    void func_80012EA0(void);
    ALHeap *heap;

    bzero(D_80046A88, 0x22A00);
    heap = &D_80046A78;
    heap->base = D_80046A88;
    heap->len = 0x22A00;
    heap->cur = heap->base;
    heap->count = 0;
    switch ((s32)osTvType) {
        case 0:
        case 1:
            osViClock = 0x02E6D354;
            break;
        case 2:
            osViClock = 0x02E6025C;
            break;
    }
#if defined(BT_NATIVE) && !defined(BT_ILP32) // ILP32 runs the original code
    // Audio is not ported yet: create the queues other modules talk to, but no
    // synthesizer and no audio thread.
    {
        extern u8 D_80045BB8[];
        extern OSMesg D_80045BD0[];
        extern OSMesgQueue D_80045BF0;
        extern OSMesg D_80045C08[];
        extern u8 D_80069488[];
        extern OSMesg D_800694A0[];
        osCreateMesgQueue((OSMesgQueue *)D_80069488, D_800694A0, 50);
        osCreateMesgQueue(&D_80045BF0, D_80045C08, 8);
        osCreateMesgQueue((OSMesgQueue *)D_80045BB8, D_80045BD0, 8);
    }
#else
    func_8001268C();
    func_800DC380();
    func_80016C00();
    func_80012F0C(4);
    func_80012F34(0, 4);
    func_80012F34(1, 4);
    func_80012EA0();
#endif
}    typedef struct { u8 pad0[0x4]; s32 unk4; } Obj1E2A0E0_D_80069A40; /* offsets.py genstruct: fields from raw offsets on &D_80069A40; rename once understood */

#if !defined(BT_NATIVE) || defined(BT_ILP32) // synthesizer setup and audio thread: see the native note in func_800125B0

void func_8001268C(void) {
    struct DMAState {
        ALLink link;
        s32 unk8, unkC, heap;
    };
    struct AudioInfo {
        u8 *data;
        s32 unk4;
        s16 unk8;
        struct AudioInfo *self;
    };
    void func_80020D80(s32, s32);
    void func_80020E40(ALLink *, ALLink *);
    s32 func_80020EE4(s32, s32, void *, s32, s32);
    void func_800128C0(void *);
    s32 *func_80012D4C(s32 **);
    BT_IDO_ONLY(extern s32 D_8003CA44[];)
    extern s32 D_800459E0[];
    extern OSThread D_800459F8;
    extern __OSThreadOddFpStorage D_80045BA8;
    extern u8 D_80045BB8[];
    extern OSMesg D_80045BD0[];
    extern OSMesgQueue D_80045BF0;
    extern OSMesg D_80045C08[];
    extern ALHeap D_80046A78;
    extern u8 D_80069488[];
    extern OSMesg D_800694A0[];
    extern s32 D_80069A40;
    extern struct DMAState D_80069A54;
    extern u8 D_80076938[];
    struct DMAState *dma, *next;
    int i;
    s32 *cmd, *info;
    u8 *buffer, *samples;

    osCreateMesgQueue((OSMesgQueue *)D_80069488, D_800694A0, 50);
    osCreateMesgQueue(&D_80045BF0, D_80045C08, 8);
    osCreateMesgQueue((OSMesgQueue *)D_80045BB8, D_80045BD0, 8);
    D_8006A1D2 = 0;
    D_8006A1A8.maxVVoices = 24;
    D_8006A1A8.maxPVoices = 24;
    D_8006A1A8.maxUpdates = 128;
    D_8006A1A8.unkC = 1;
    D_8006A1A8.dmaproc = func_80012D4C;
    D_8006A1A8.fxType = 6;
    D_8006A1A8.params = BT_DATA_FIELD(core1_audio_config.effect_params, D_8003CA44);
    D_8006A1A8.heap = &D_80046A78;
    D_8006A1A8.outputRate = osAiSetFrequency(22050);
    func_80020D80((s32)&D_8006A158, (s32)&D_8006A1A8);
    ((Obj1E2A0E0_D_80069A40 *)&D_80069A40)->unk4 = 0;
    D_80069A40 = 0;
    for (i = 0; i < 89; i++) {
        dma = (struct DMAState *)((u8 *)&D_80069A40 + i * sizeof(struct DMAState));
        func_80020E40((ALLink *)((u8 *)&D_80069A54 + i * sizeof(struct DMAState)), &dma->link);
        ((s32 *)((u8 *)&D_80069A40 + i * sizeof(struct DMAState)))[4] = func_80020EE4(0, 0, D_8006A1A8.heap, 1, 0x200);
    }
    ((s32 *)((u8 *)&D_80069A40 + i * sizeof(struct DMAState)))[4] = func_80020EE4(0, 0, D_8006A1A8.heap, 1, 0x200);
    i = 0;
    do {
        D_800459E0[i] = (s32)((u8 *)D_8006A1D8 + i * 0x4E20);
        i++;
    } while ((u8 *)D_8006A1D8 + i * 0x4E20 < (u8 *)D_80073E18);
    i = 0;
    do {
        D_800459E0[i + 2] = func_80020EE4(0, 0, D_8006A1A8.heap, 1, 0x10);
        ((struct AudioInfo *)D_800459E0[i + 2])->unk8 = 0;
        ((struct AudioInfo *)D_800459E0[i + 2])->self = (struct AudioInfo *)D_800459E0[i + 2];
        ((struct AudioInfo *)D_800459E0[i + 2])->data = (u8 *)D_80073E18 + i * 0xE60;
        i++;
    } while (D_80076938 != (u8 *)D_80073E18 + i * 0xE60);
    func_8001DCB0(&D_800459F8, &D_80045BA8, 4, func_800128C0, NULL, &D_80046A78, 50);
}

// audio_thread_entry
void func_800128C0(void *arg) {
    s32 func_800129FC(s32, s32);
    void func_80012B74(s32);
    void func_800E96B0(s32);
    BT_IDO_ONLY(extern OSMesg D_8003CC5C;)
    BT_IDO_ONLY(extern s32 D_8003CC60;)
    extern s32 D_800459E0[];
    extern u8 D_80045BB8[];
    extern OSMesgQueue D_80045BF0;
    extern u32 D_8006A148;
    s32 skip_handle_done_mesg = 1;

    while (TRUE) {
        osRecvMesg(D_80045BB8, NULL, OS_MESG_BLOCK);
        if (func_800129FC(D_800459E0[(s32)D_8006A148 % 3 + 2], BT_DATA_FIELD(core1_audio_config.last_task, D_8003CC60))) {
            if (skip_handle_done_mesg == 0) {
                osRecvMesg(&D_80045BF0, &BT_DATA_FIELD(core1_audio_config.completed_task, D_8003CC5C), OS_MESG_BLOCK);
                func_80012B74(((s32 *)BT_DATA_FIELD(core1_audio_config.completed_task, D_8003CC5C))[1]);
                BT_DATA_FIELD(core1_audio_config.last_task, D_8003CC60) = ((s32 *)BT_DATA_FIELD(core1_audio_config.completed_task, D_8003CC5C))[1];
            } else {
                skip_handle_done_mesg--;
            }
        }
        func_800E96B0(1);
    }
}

s32 func_800129FC(s32 arg0, s32 arg1) {
    Acmd *func_80021574(Acmd *, s32 *, s16 *, s32);
    void func_8001A148(s32, s32, s32, s32);
    void func_80012D84(void);
    extern s32 D_800459E0[];
    extern OSMesgQueue D_80045BF0;
    static s32 sampleAdjustmentCooldown;
    struct AudioBuffer {
        void *data;
        s16 samples;
        s32 task;
    };
    s16 *outbuffer;
    Acmd *command_list_end;
    s32 command_list_len;
    u32 remaining;
    s32 ret;

    ret = 0;
    outbuffer = (s16 *)osVirtualToPhysical(((struct AudioBuffer *)arg0)->data);
    func_80012D84();
    remaining = osAiGetLength() >> 2;
    if (arg1) {
        ret = osAiSetNextBuffer(((struct AudioBuffer *)arg1)->data, 4 * ((struct AudioBuffer *)arg1)->samples);
    }
    if (ret == -1) {
        return 0;
    }
    if (((s32)remaining < 0x5C) && !sampleAdjustmentCooldown) {
        ((struct AudioBuffer *)arg0)->samples = 0x398;
        sampleAdjustmentCooldown = 2;
    } else if (((s32)remaining >= 0x115) && !sampleAdjustmentCooldown) {
        ((struct AudioBuffer *)arg0)->samples = 0x228;
        sampleAdjustmentCooldown = 2;
    } else {
        ((struct AudioBuffer *)arg0)->samples = 0x2E0;
        if (sampleAdjustmentCooldown) {
            sampleAdjustmentCooldown--;
        }
    }
    command_list_end = func_80021574((Acmd *)D_800459E0[D_8006A150], &command_list_len, outbuffer, ((struct AudioBuffer *)arg0)->samples);
    if (command_list_len == 0) {
        return 0;
    } else {
        func_8001A148(D_800459E0[D_8006A150], (s32)command_list_end, (s32)&D_80045BF0, (s32)&((struct AudioBuffer *)arg0)->task);
        D_8006A150 ^= 1;
        return 1;
    }
}

void func_80012B74(s32 arg0) {
    BT_IDO_ONLY(extern s32 D_8003CC64[1];)
    s32 i;
    if (((osAiGetLength() >> 2) == 0) && (BT_DATA_FIELD(core1_audio_config.ai_buffer, D_8003CC64)[0] == 0)) {
        for (i = 0; i < 1; i = 1) {
            BT_DATA_FIELD(core1_audio_config.ai_buffer, D_8003CC64)[i] = 0;
        }
    }
} typedef struct { u8 unk0; u8 pad1[0x3]; union { struct dma_node * unk4; void * unk4_voidp; }; union { void * unk8; s32 * unk8_s32p; struct dma_node * unk8_structdma_nodep; }; } Obj1E2A0E0_D_80069A30; /* offsets.py genstruct: fields from raw offsets on &D_80069A30; rename once understood */

s32 func_80012BB4(s32 addr, s32 len, void *state) {
    void func_80020E40(ALLink *, ALLink *);
    void func_80020E74(ALLink *);
    extern u8 D_80069488[];
    extern OSIoMesg D_80069580[];
    extern s32 D_80069A30;
    extern u32 D_8006A148;
    extern u32 D_8006A14C;
    struct dma_node {
        ALLink link;
        u32 addr;
        u32 time;
        void *heap;
    };
    void *dest_vaddr;
    s32 low_bit;
    s32 addr_end;
    struct dma_node *node, *head, *prev;

    head = ((Obj1E2A0E0_D_80069A30 *)&D_80069A30)->unk4;
    prev = NULL;
    for (node = head; node != NULL; node = (struct dma_node *)node->link.next) {
        addr_end = node->addr + 0x200;
        if (node->addr > addr) {
            break;
        }
        prev = node;
        if (addr + len <= addr_end) {
            node->time = D_8006A148;
            low_bit = (s32)node->heap + (addr - node->addr);
            return osVirtualToPhysical((void *)low_bit);
        }
    }
    node = ((Obj1E2A0E0_D_80069A30 *)&D_80069A30)->unk8_structdma_nodep;
    if (node == NULL) {
        return osVirtualToPhysical(head);
    }
    ((Obj1E2A0E0_D_80069A30 *)&D_80069A30)->unk8_structdma_nodep = (struct dma_node *)node->link.next;
    func_80020E74(&node->link);
    if (prev != NULL) {
        func_80020E40(&node->link, &prev->link);
    } else {
        head = ((Obj1E2A0E0_D_80069A30 *)&D_80069A30)->unk4;
        if (head != NULL) {
            ((Obj1E2A0E0_D_80069A30 *)&D_80069A30)->unk4 = node;
            node->link.next = (ALLink *)head;
            node->link.prev = NULL;
            head->link.prev = (ALLink *)node;
        } else {
            ((Obj1E2A0E0_D_80069A30 *)&D_80069A30)->unk4 = node;
            node->link.next = NULL;
            node->link.prev = NULL;
        }
    }
    dest_vaddr = node->heap;
    low_bit = addr & 1;
    addr -= low_bit;
    node->addr = addr;
    node->time = D_8006A148;
    osPiStartDma(&D_80069580[D_8006A14C++], OS_MESG_PRI_HIGH, OS_READ, addr,
                 dest_vaddr, 0x200, (OSMesgQueue *)D_80069488);
    return osVirtualToPhysical(dest_vaddr) + low_bit;
}

s32 *func_80012D4C(s32 **arg0) {
    extern s32 D_80069A30;
    extern s32 D_80069A40;
    extern s32 func_80012BB4(s32, s32, void *);
    if ((((Obj1E2A0E0_D_80069A30 *)&D_80069A30)->unk0) == 0) {
        (*(s32 *)((s8 *)(&D_80069A30) + (4))) = 0;
        (((Obj1E2A0E0_D_80069A30 *)&D_80069A30)->unk8_s32p) = &D_80069A40;
        (((Obj1E2A0E0_D_80069A30 *)&D_80069A30)->unk0) = 1U;
    }
    *arg0 = &D_80069A30;
    return &func_80012BB4;
}    typedef struct { u8 pad0[0x4]; void * unk4; u8 pad8[0x4]; s32 unkC; } Obj1E2A0E0_func_80012D84_node; /* offsets.py genstruct: fields from raw offsets on node; rename once understood */

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
    node = ((Obj1E2A0E0_D_80069A30 *)&D_80069A30)->unk4_voidp;
    if (node != NULL) {
        do {
            next = *(void **)node;
            if ((u32)(((Obj1E2A0E0_func_80012D84_node *)node)->unkC + 1) < D_8006A148) {
                if (node == ((Obj1E2A0E0_D_80069A30 *)&D_80069A30)->unk4_voidp) {
                    ((Obj1E2A0E0_D_80069A30 *)&D_80069A30)->unk4_voidp = *(void **)node;
                }
                func_80020E74(node);
                if (((Obj1E2A0E0_D_80069A30 *)&D_80069A30)->unk8 != NULL) {
                    func_80020E40(node, ((Obj1E2A0E0_D_80069A30 *)&D_80069A30)->unk8);
                } else {
                    ((Obj1E2A0E0_D_80069A30 *)&D_80069A30)->unk8 = node;
                    *(void **)node = NULL;
                    ((Obj1E2A0E0_func_80012D84_node *)node)->unk4 = NULL;
                }
            }
            node = next;
        } while (next != NULL);
    }
    D_8006A14C = 0;
    D_8006A148++;
}

#endif

void func_80012EA0(void) {
    BT_IDO_ONLY(extern s32 D_8003CA40;)
    extern OSThread D_800459F8;
    if (BT_DATA_FIELD(core1_audio_config.dma_initialized, D_8003CA40) == 0) {
        BT_DATA_FIELD(core1_audio_config.dma_initialized, D_8003CA40) = 1;
        osStartThread(&D_800459F8);
    }
}

void *func_80012EDC(void) {
    extern ALHeap D_80046A78;

    return &D_80046A78;
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

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_80012F0C(s32 arg0) {
    BT_IDO_ONLY(s32 func_80021A00(s32);) BT_NATIVE_ONLY(void func_80021A00(u8);)
    D_8006A1CC.master = arg0;
    func_80021A00(arg0 & 0xFF); BT_NATIVE_ONLY(return 0;)
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_80012F34(s32 arg0, s32 arg1) {
    BT_IDO_ONLY(s32 func_80021AD0();) BT_NATIVE_ONLY(void func_80021AD0(s32, s32);)
    *(((volatile s16 *)D_8006A1CC.channels) + arg0) = arg1;
    BT_IDO_ONLY(func_80021AD0();) BT_NATIVE_ONLY(func_80021AD0(arg0, arg1); return 0;)
}

void *func_80012F60(void) {
    extern u8 D_8007695C[];
    return D_8007695C;
}

void *func_80012F6C(void) {
    extern u8 D_80076940[];
    return D_80076940;
}

void rom_dma_read(u8 *arg0, BtIntPtr arg1, s32 arg2) {
    BT_IDO_ONLY(extern s32 D_8003CC70;)
    extern u8 D_80076940[];
    extern u8 D_8007695C[];
    s32 i;
    s32 chunks;

    osWritebackDCache(arg0, arg2);
    i = 0;
    chunks = arg2 / 0x20000;
    for (; i < chunks;) {
        BT_DATA_FIELD(core1_audio_config.dma_pending, D_8003CC70)++;
        osPiStartDma((OSIoMesg *) D_80076940, 0, 0, arg1, arg0, 0x20000, (OSMesgQueue *) D_8007695C);
        osRecvMesg((OSMesgQueue *) D_8007695C, NULL, 1);
        arg1 += 0x20000;
        arg0 += 0x20000;
        i++;
        BT_DATA_FIELD(core1_audio_config.dma_pending, D_8003CC70)--;
    }
    BT_DATA_FIELD(core1_audio_config.dma_pending, D_8003CC70)++;
    osPiStartDma((OSIoMesg *) D_80076940, 0, 0, arg1, arg0, arg2 % 0x20000, (OSMesgQueue *) D_8007695C);
    osRecvMesg((OSMesgQueue *) D_8007695C, NULL, 1);
    BT_DATA_FIELD(core1_audio_config.dma_pending, D_8003CC70)--;
    osInvalDCache(arg0, arg2);
}

void func_8001311C(u8 *arg0, s32 arg1) {
    BT_IDO_ONLY(extern s32 D_8003CC70;)
    extern u8 D_80076940[];
    extern u8 D_8007695C[];
    osWritebackDCache(arg0, 0x1800);
    BT_DATA_FIELD(core1_audio_config.dma_pending, D_8003CC70)++;
    osPiStartDma((OSIoMesg *) D_80076940, 0, 0, arg1, arg0, 0x1800, (OSMesgQueue *) D_8007695C);
    osRecvMesg((OSMesgQueue *) D_8007695C, NULL, 1);
    BT_DATA_FIELD(core1_audio_config.dma_pending, D_8003CC70)--;
    osInvalDCache(arg0, 0x1800);
}

void func_800131C0(void) {
    extern u8 D_8007695C[];
    extern u8 *D_80076958;
    extern u8 *D_80076978;
    extern OSMesgQueue D_800769B8;
    osCreateMesgQueue((OSMesgQueue *) D_8007695C, (OSMesg *)&D_80076958, 1);
    osCreateMesgQueue(&D_800769B8, (OSMesg *)&D_80076978, 0x10);
    osCreatePiManager(0x96, &D_800769B8, (OSMesg *)&D_80076978, 0x10);
}

#ifdef BT_NATIVE
// The N64 keeps the destination/length stack in two overlapping s32 arrays.
static void *native_dma_dst[8];
static s32 native_dma_len[8];

void func_80013224(u32 arg0, void *arg1, s32 arg2) {
    BT_IDO_ONLY(extern s32 D_8003CC70;)
    extern u8 D_80076940[];
    extern u8 D_8007695C[];

    BT_DATA_FIELD(core1_audio_config.dma_pending, D_8003CC70)++;
    native_dma_dst[BT_DATA_FIELD(core1_audio_config.dma_pending, D_8003CC70)] = arg1;
    native_dma_len[BT_DATA_FIELD(core1_audio_config.dma_pending, D_8003CC70)] = arg2;
    osPiStartDma((OSIoMesg *) D_80076940, 0, 0, arg0, arg1, arg2, (OSMesgQueue *) D_8007695C);
}

void func_800132BC(void) {
    extern u8 D_8007695C[];
    BT_IDO_ONLY(extern s32 D_8003CC70;)

    osRecvMesg((OSMesgQueue *) D_8007695C, NULL, 1);
    osInvalDCache(native_dma_dst[BT_DATA_FIELD(core1_audio_config.dma_pending, D_8003CC70)], native_dma_len[BT_DATA_FIELD(core1_audio_config.dma_pending, D_8003CC70)]);
    BT_DATA_FIELD(core1_audio_config.dma_pending, D_8003CC70) -= 1;
}
#else
void func_80013224(u32 arg0, void *arg1, s32 arg2) {
    BT_IDO_ONLY(extern s32 D_8003CC70;)
    extern s32 D_800769CC[];
    extern s32 D_800769D0[];
    extern u8 D_80076940[];
    extern u8 D_8007695C[];

    BT_DATA_FIELD(core1_audio_config.dma_pending, D_8003CC70)++;
    D_800769CC[BT_DATA_FIELD(core1_audio_config.dma_pending, D_8003CC70)] = (s32) arg1;
    D_800769D0[BT_DATA_FIELD(core1_audio_config.dma_pending, D_8003CC70)] = arg2;
    osWritebackDCache(arg1, arg2);
    osPiStartDma((OSIoMesg *) D_80076940, 0, 0, arg0, arg1, arg2, (OSMesgQueue *) D_8007695C);
}

void func_800132BC(void) {
    extern u8 D_8007695C[];
    BT_IDO_ONLY(extern s32 D_8003CC70;)
    extern s32 D_800769CC[];
    extern s32 D_800769D0[];

    osRecvMesg((OSMesgQueue *) D_8007695C, NULL, 1);
    osInvalDCache(D_800769CC[BT_DATA_FIELD(core1_audio_config.dma_pending, D_8003CC70)], D_800769D0[BT_DATA_FIELD(core1_audio_config.dma_pending, D_8003CC70)]);
    BT_DATA_FIELD(core1_audio_config.dma_pending, D_8003CC70) -= 1;
}
#endif

void func_80013324(u32 arg0, void *arg1, s32 arg2)
{
    func_80013224(arg0, arg1, arg2);
    func_800132BC();
}

void func_8001334C(void) {
    BT_IDO_ONLY(extern s32 D_8003CC70;)
    if (BT_DATA_FIELD(core1_audio_config.dma_pending, D_8003CC70) > 0) {
        do {
            func_800132BC();
        } while (BT_DATA_FIELD(core1_audio_config.dma_pending, D_8003CC70) > 0);
    }
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
u8 D_80076940 [ 24 ] BT_DATA(16, bss_core1bss1_0_audio_frame_tail, 0x0);
u8 * D_80076958 BT_DATA(4, bss_core1bss1_0_audio_frame_tail, 0x18);
u8 D_8007695C [ 28 ] BT_DATA(4, bss_core1bss1_0_audio_frame_tail, 0x1C);
u8 * D_80076978 BT_DATA(4, bss_core1bss1_0_audio_frame_tail, 0x38);
OSMesgQueue D_800769B8 BT_DATA(4, bss_core1bss1_0_audio_frame_tail, 0x78);
s32 D_800459E0 [ 6 ] BT_DATA(16, bss_core1bss1_0_startup_tail, 0x0);
OSThread D_800459F8 BT_DATA(8, bss_core1bss1_0_startup_tail, 0x18);
__OSThreadOddFpStorage D_80045BA8 BT_DATA(8, bss_core1bss1_0_startup_tail, 0x1C8);
u8 D_80045BB8 [ 24 ] BT_DATA(4, bss_core1bss1_0_startup_tail, 0x1D8);
OSMesg D_80045BD0 [ 8 ] BT_DATA(4, bss_core1bss1_0_startup_tail, 0x1F0);
OSMesgQueue D_80045BF0 BT_DATA(4, bss_core1bss1_0_startup_tail, 0x210);
OSMesg D_80045C08 [ 924 ] BT_DATA(4, bss_core1bss1_0_startup_tail, 0x228);
ALHeap D_80046A78 BT_DATA(4, bss_core1bss1_0_startup_tail, 0x1098);
u8 D_80046A88 [ 141824 ] BT_DATA(4, bss_core1bss1_0_startup_tail, 0x10A8);
u8 D_80069488 [ 24 ] BT_DATA(4, bss_core1bss1_0_startup_tail, 0x23AA8);
OSMesg D_800694A0 [ 50 ] BT_DATA(4, bss_core1bss1_0_startup_tail, 0x23AC0);
u8 D_80069568 [ 24 ] BT_DATA(4, bss_core1bss1_0_startup_tail, 0x23B88);
OSIoMesg D_80069580 [ 50 ] BT_DATA(4, bss_core1bss1_0_startup_tail, 0x23BA0);
s32 D_80069A30 BT_DATA(4, bss_core1bss1_0_startup_tail, 0x24050);
s32 D_80069A40 BT_DATA(4, bss_core1bss1_0_startup_tail, 0x24060);
u32 D_8006A148 BT_DATA(4, bss_core1bss1_0_startup_tail, 0x24768);
u32 D_8006A14C BT_DATA(4, bss_core1bss1_0_startup_tail, 0x2476C);
#endif
