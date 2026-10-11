#include "threads.h"
#include "types.h"
#include "core1/1E2D890.h"

// .data
extern s32 D_8003F5F0;

// .bss
typedef struct {
    s32 unk0[2];
} unkD_800799C0;

typedef struct {
    s32 unk0[14];
} unkD_800799E0;

typedef struct {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    f32 unk8;
    f32 unkC;
} unkD_80079AF8;

extern unkD_800799C0 D_800799C0[4];
extern unkD_800799E0 D_800799E0[4];
extern unkD_80079AF8 D_80079AF8[4];

// si_mesg
extern OSMesg D_80079B38;
// joy_mesg
extern OSMesg D_80079B3C;
// controllers
extern OSContPad D_80079B40[4];
// another contpad?
extern OSContPad D_80079B58;
// si_mesg_queue
extern OSMesgQueue D_80079B60;
// joy_mesg_queue
extern OSMesgQueue D_80079B78;
// controller_statuses
extern OSContStatus D_80079B90[4];
extern volatile s32 D_80079BA0;
extern OSThread D_80079BA8;

// This should be much larger than 0x10 bytes. Maybe they had a second struct for threads that don't use
// SR_FR, since those will never save or load the odd float register values on context switch.
extern __OSThreadOddFpStorage D_80079D58;

// bitpattern
extern u8 D_80079D68;
extern u8 D_80079D6C[];
// joy_thread_stack
extern u64 D_80079D70[JOY_THREAD_STACK_SIZE / sizeof(u64)];

extern OSMesgQueue D_80079F70;
extern OSMesg D_80079F88[6];

void func_800165F0(void);
void func_80016934(s32 arg0);
void func_80016A48(void);
void func_80016864(void);
void func_800169B4(void);
void func_80016A04(void);

f32 func_80015D60(s32 arg0, s32 arg1, s32 arg2) {
    extern s32 D_8007DB54;
    s32 bits[2];
    f32 scale;

    bits[0] = 0xE955CCDD - D_8007DB54;
    scale = *(f32 *)&bits[0];
    if (arg0 > 0) {
        arg0 = arg2 < arg0 ? arg2 : (arg0 < arg1 ? arg1 : arg0);
        arg0 = ((arg0 - arg1) * 0x50) / (arg2 - arg1);
    } else if (arg0 < 0) {
        arg0 = arg0 < -arg2 ? -arg2 : (-arg1 < arg0 ? -arg1 : arg0);
        arg0 = ((arg0 + arg1) * 0x50) / (arg2 - arg1);
    }
    scale *= (f32)arg0;
    return scale;
}

void func_80015E80(s32 arg0, void *arg1) {
    unkD_800799E0 *temp_v0;

    temp_v0 = &D_800799E0[arg0];
    (*(s32 *)((s8 *)(arg1) + (0))) = (s32) temp_v0->unk0[0];
    (*(s32 *)((s8 *)(arg1) + (4))) = (s32) temp_v0->unk0[1];
    (*(s32 *)((s8 *)(arg1) + (8))) = (s32) temp_v0->unk0[2];
    (*(s32 *)((s8 *)(arg1) + (0xC))) = (s32) temp_v0->unk0[3];
    (*(s32 *)((s8 *)(arg1) + (0x10))) = (s32) temp_v0->unk0[4];
    (*(s32 *)((s8 *)(arg1) + (0x14))) = (s32) temp_v0->unk0[5];
}

void func_80015ECC(s32 arg0, void *arg1) {
    extern s32 D_80079AC0;
    (*(s32 *)((s8 *)(arg1) + (0))) = (s32) (*(s32 *)((s8 *)(&D_80079AC0) + (0)));
    (*(s32 *)((s8 *)(arg1) + (4))) = (s32) (*(s32 *)((s8 *)(&D_80079AC0) + (4)));
    (*(s32 *)((s8 *)(arg1) + (8))) = (s32) (*(s32 *)((s8 *)(&D_80079AC0) + (8)));
    (*(s32 *)((s8 *)(arg1) + (0xC))) = (s32) (*(s32 *)((s8 *)(&D_80079AC0) + (0xC)));
    (*(s32 *)((s8 *)(arg1) + (0x10))) = (s32) (*(s32 *)((s8 *)(&D_80079AC0) + (0x10)));
    (*(s32 *)((s8 *)(arg1) + (0x14))) = (s32) (*(s32 *)((s8 *)(&D_80079AC0) + (0x14)));
}

s32 func_80015F0C(s32 controller, s32 combo) {
    return D_800799C0[controller].unk0[combo];
}

void func_80015F28(s32 arg0, void *arg1) {
    unkD_800799E0 *temp_v0;

    temp_v0 = &D_800799E0[arg0];
    (*(s32 *)((s8 *)(arg1) + (0))) = (s32) temp_v0->unk0[6];
    (*(s32 *)((s8 *)(arg1) + (4))) = (s32) temp_v0->unk0[7];
    (*(s32 *)((s8 *)(arg1) + (8))) = (s32) temp_v0->unk0[8];
}

void func_80015F5C(s32 arg0, void *arg1) {
    extern s32 D_80079AC0;
    (*(s32 *)((s8 *)(arg1) + (0))) = (s32) (*(s32 *)((s8 *)(&D_80079AC0) + (0x18)));
    (*(s32 *)((s8 *)(arg1) + (4))) = (s32) (*(s32 *)((s8 *)(&D_80079AC0) + (0x1C)));
    (*(s32 *)((s8 *)(arg1) + (8))) = (s32) (*(s32 *)((s8 *)(&D_80079AC0) + (0x20)));
}

s32 func_80015F84(s32 arg0) {
    extern s32 D_80079A14;
    return *(s32 *)((u8 *)&D_80079A14 + ((arg0 * 7) * 8));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2D890/func_80015FA0.s")

void func_80015FFC(s32 arg0, void *arg1) {
    unkD_800799E0 *temp_v0;

    temp_v0 = &D_800799E0[arg0];
    (*(s32 *)((s8 *)(arg1) + (0))) = (s32) temp_v0->unk0[9];
    (*(s32 *)((s8 *)(arg1) + (4))) = (s32) temp_v0->unk0[0xA];
    (*(s32 *)((s8 *)(arg1) + (8))) = (s32) temp_v0->unk0[0xB];
    (*(s32 *)((s8 *)(arg1) + (0xC))) = (s32) temp_v0->unk0[0xC];
}

void func_80016038(s32 arg0, void *arg1) {
    extern s32 D_80079AC0;
    (*(s32 *)((s8 *)(arg1) + (0))) = (s32) (*(s32 *)((s8 *)(&D_80079AC0) + (0x24)));
    (*(s32 *)((s8 *)(arg1) + (4))) = (s32) (*(s32 *)((s8 *)(&D_80079AC0) + (0x28)));
    (*(s32 *)((s8 *)(arg1) + (8))) = (s32) (*(s32 *)((s8 *)(&D_80079AC0) + (0x2C)));
    (*(s32 *)((s8 *)(arg1) + (0xC))) = (s32) (*(s32 *)((s8 *)(&D_80079AC0) + (0x30)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2D890/func_80016068.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2D890/func_8001608C.s")

void func_800165F0(void) {
    func_80016934(0);
    if (D_80079B90[0].errno == 0) {
        osContGetReadData(D_80079B40);
    }
}

void func_8001662C(void) {
    while (TRUE) {
        osRecvMesg(&D_80079B60, NULL, OS_MESG_BLOCK);
        if (D_80079BA0 == 1) {
            func_800165F0();
        }
        else {
            osSendMesg(&D_80079B78, NULL, OS_MESG_NOBLOCK);
        }
    }
}

// joy_thread_entry
void func_800166DC(UNUSED void* arg0) {
    s32 eeprom_type = osEepromProbe(&D_80079B60);
    func_80016864();
    func_80014DC4();
    if (eeprom_type < EEPROM_TYPE_16K) {
        D_80079B90[0].errno = 8;
    }
    func_8001662C();
}

// joy_init
void func_80016734(void) {
    osCreateMesgQueue(&D_80079B60, &D_80079B38, 1);
    osCreateMesgQueue(&D_80079B78, &D_80079B3C, 1);
    func_8001DCB0(&D_80079BA8, &D_80079D58, THREAD_ID_JOY, func_800166DC, NULL, &D_80079D70[JOY_THREAD_STACK_SIZE / sizeof(u64)], JOY_THREAD_PRI);
    osSetEventMesg(OS_EVENT_SI, &D_80079B60, &D_80079B38);
    osContInit(&D_80079B60, &D_80079D68, D_80079B90);
    osStartThread(&D_80079BA8);
}

u8 func_800167F4(void) {
    return D_80079B90[0].errno;
}

u8 func_80016800(s32 arg0) {
    return D_80079D6C[arg0];
}

void func_80016810(void) {
    if (MQ_GET_COUNT(&D_80079F70) == 1) {
        func_80016934(1);
        osStopThread(&D_80079BA8);
        osContStartReadData(&D_80079B60);
        osStartThread(&D_80079BA8);
    }
}

void func_80016864(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 4; i++) {
        D_80079AF8[i].unk0 = 0;
        D_80079AF8[i].unk2 = 0;
        D_80079AF8[i].unk4 = 0;
        D_80079AF8[i].unk6 = 0;
        D_80079AF8[i].unk8 = 0.0f;
        D_80079AF8[i].unkC = 0.0f;
        
        for (j = 0; j < (s32)ARRLEN(D_800799C0[i].unk0); j++) {
            D_800799C0[i].unk0[j] = 0;
        }
        
        for (j = 0; j < ARRLEN(D_800799E0[i].unk0); j++) {
            D_800799E0[i].unk0[j] = 0;
        }
    }
}

void func_8001690C(s32 arg0, s32 arg1) {
    D_800799E0[arg0].unk0[6] = arg1;
}

OSMesgQueue* func_80016928(void) {
    return &D_80079B78;
}

void func_80016934(s32 arg0) {
    s32 temp_a0;

    if (arg0 == 0) {
        func_80016A48();
    } else {
        func_80016A04();
    }
    temp_a0 = __osDisableInt();
    if (arg0 != 0 || MQ_GET_COUNT(&D_80079F70) == 1) {
        D_80079BA0 = arg0;
    }
    __osRestoreInt(temp_a0);
}

OSContPad* func_800169A8(void) {
    return &D_80079B58;
}

void func_800169B4(void) {
    D_8003F5F0 = 1;
    osCreateMesgQueue(&D_80079F70, D_80079F88, ARRLEN(D_80079F88));
    osSendMesg(&D_80079F70, NULL, OS_MESG_NOBLOCK);
}

void func_80016A04(void) {
    if (D_8003F5F0 == 0) {
        func_800169B4();
    }
    osRecvMesg(&D_80079F70, NULL, OS_MESG_BLOCK);
}

void func_80016A48() {
    osSendMesg(&D_80079F70, NULL, OS_MESG_NOBLOCK);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2D890/func_80016A74.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core1/1E2D890/func_80016B30.s")

s32 func_80016B54(s32 arg0, s32 arg1) {
    extern s32 D_800799F8[][14];
    return D_800799F8[arg0][arg1];
}

s32 func_80016B78(s32 arg0, s32 arg1) {
    extern s32 D_80079A04[][14];
    return D_80079A04[arg0][arg1];
}

s32 func_80016B9C(s32 arg0, u16 arg1) {
    return D_80079AF8[arg0].unk0 & arg1;
}

s32 func_80016BBC(s32 arg0, u16 arg1) {
    extern u16 D_80079AFC[][8];
    return D_80079AFC[arg0][0] & arg1;
}

void func_80016BDC(s32 arg0) {
    osContSetCh((u8) arg0);
}
