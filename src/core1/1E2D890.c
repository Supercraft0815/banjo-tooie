#include "threads.h"
#include "types.h"
#include "core1/1E2D890.h"
#include "core1/core1_runtime_data.h"
#ifdef BT_NATIVE
void func_80014DC4(void);
u32 __osDisableInt(void);
void __osRestoreInt(u32);
#endif

// .data
BT_IDO_ONLY(extern s32 D_8003F5F0;)

// .bss
typedef struct {
    s32 unk0[2];
} unkD_800799C0;

typedef struct {
    s32 held[14];
} ControllerButtonFrames;

typedef struct {
    u16 current, previous, pressed, released;
    f32 stick_x, stick_y;
} ControllerSnapshot;

extern unkD_800799C0 D_800799C0[4];
extern ControllerButtonFrames D_800799E0[4], D_80079AC0;
extern ControllerSnapshot D_80079AF8[4];
#ifdef BT_NATIVE
_Static_assert(sizeof(ControllerButtonFrames) == 0x38, "controller button timers");
_Static_assert(sizeof(ControllerSnapshot) == 0x10, "controller snapshot");
_Static_assert(sizeof(OSContStatus[4]) == 0x10, "controller status array");
#ifdef BT_ILP32
_Static_assert(sizeof(OSMesgQueue) == 0x18, "controller queue");
#endif
#endif

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
    ControllerButtonFrames *temp_v0;

    temp_v0 = &D_800799E0[arg0];
    (*(s32 *)((s8 *)(arg1) + (0))) = (s32) temp_v0->held[0];
    (*(s32 *)((s8 *)(arg1) + (4))) = (s32) temp_v0->held[1];
    (*(s32 *)((s8 *)(arg1) + (8))) = (s32) temp_v0->held[2];
    (*(s32 *)((s8 *)(arg1) + (0xC))) = (s32) temp_v0->held[3];
    (*(s32 *)((s8 *)(arg1) + (0x10))) = (s32) temp_v0->held[4];
    (*(s32 *)((s8 *)(arg1) + (0x14))) = (s32) temp_v0->held[5];
}

void func_80015ECC(s32 arg0, void *arg1) {
    (*(s32 *)((s8 *)(arg1) + (0))) = (s32) D_80079AC0.held[0];
    (*(s32 *)((s8 *)(arg1) + (4))) = (s32) D_80079AC0.held[1];
    (*(s32 *)((s8 *)(arg1) + (8))) = (s32) D_80079AC0.held[2];
    (*(s32 *)((s8 *)(arg1) + (0xC))) = (s32) D_80079AC0.held[3];
    (*(s32 *)((s8 *)(arg1) + (0x10))) = (s32) D_80079AC0.held[4];
    (*(s32 *)((s8 *)(arg1) + (0x14))) = (s32) D_80079AC0.held[5];
}

s32 func_80015F0C(s32 controller, s32 combo) {
    return D_800799C0[controller].unk0[combo];
}

void func_80015F28(s32 arg0, void *arg1) {
    ControllerButtonFrames *temp_v0;

    temp_v0 = &D_800799E0[arg0];
    (*(s32 *)((s8 *)(arg1) + (0))) = (s32) temp_v0->held[6];
    (*(s32 *)((s8 *)(arg1) + (4))) = (s32) temp_v0->held[7];
    (*(s32 *)((s8 *)(arg1) + (8))) = (s32) temp_v0->held[8];
}

void func_80015F5C(s32 arg0, void *arg1) {
    (*(s32 *)((s8 *)(arg1) + (0))) = (s32) D_80079AC0.held[6];
    (*(s32 *)((s8 *)(arg1) + (4))) = (s32) D_80079AC0.held[7];
    (*(s32 *)((s8 *)(arg1) + (8))) = (s32) D_80079AC0.held[8];
}

s32 func_80015F84(s32 arg0) {
    BT_IDO_ONLY(extern s32 D_80079A14;)
    return BT_DATA_FIELD(D_800799E0[arg0].held[13], *(s32 *)((u8 *)&D_80079A14 + ((arg0 * 7) * 8)));
}

s32 func_80015FA0(s32 arg0) {
    BT_IDO_ONLY(extern s32 D_80079A14;)
    BT_IDO_ONLY(extern s32 D_80079AF4;)
    BT_IDO_ONLY(extern u8 D_80079B93;)
    extern u8 D_80079D69;
    s32 var_v1;

    if ((D_80079D69 == 0) || (BT_DATA_FIELD(D_80079B90[0].errno, D_80079B93) != 0)) {
        return 0U;
    }
    if (arg0 != 0) {
        var_v1 = BT_DATA_FIELD(D_800799E0[arg0].held[13], *(s32 *)((u8 *)&D_80079A14 + ((arg0 * 7) * 8)));
    } else {
        var_v1 = BT_DATA_FIELD(D_80079AC0.held[13], D_80079AF4);
    }
    return var_v1;
}

void func_80015FFC(s32 arg0, void *arg1) {
    ControllerButtonFrames *temp_v0;

    temp_v0 = &D_800799E0[arg0];
    (*(s32 *)((s8 *)(arg1) + (0))) = (s32) temp_v0->held[9];
    (*(s32 *)((s8 *)(arg1) + (4))) = (s32) temp_v0->held[0xA];
    (*(s32 *)((s8 *)(arg1) + (8))) = (s32) temp_v0->held[0xB];
    (*(s32 *)((s8 *)(arg1) + (0xC))) = (s32) temp_v0->held[0xC];
}

void func_80016038(s32 arg0, void *arg1) {
    (*(s32 *)((s8 *)(arg1) + (0))) = (s32) D_80079AC0.held[9];
    (*(s32 *)((s8 *)(arg1) + (4))) = (s32) D_80079AC0.held[10];
    (*(s32 *)((s8 *)(arg1) + (8))) = (s32) D_80079AC0.held[11];
    (*(s32 *)((s8 *)(arg1) + (0xC))) = (s32) D_80079AC0.held[12];
}

void func_80016068(u32 arg0, f32 *arg1) {
    ControllerSnapshot *temp_v0;

    temp_v0 = &D_80079AF8[arg0];
    (*(f32 *)((s8 *)(arg1) + (0))) = temp_v0->stick_x;
    (*(f32 *)((s8 *)(arg1) + (4))) = (f32) temp_v0->stick_y;
}

void func_8001608C(void) {
    s32 _glrecord_entrypoint_0(OSContPad *, s32 *);
    s32 func_800A9CAC(void);
    void func_800A9CDC(void);
    void func_800D8FA0(s32 arg0);
    f32 func_800DC0C0(void);
    extern u8 D_80079D69;
    s32 j;
    s32 i;
    s32 pri;
    s32 lag;
    u32 curr_buttons;

    pri = osGetThreadPri(&D_80079BA8);
    osSetThreadPri(&D_80079BA8, 0);
    D_80079B58.stick_x = D_80079B40[0].stick_x;
    D_80079B58.stick_y = D_80079B40[0].stick_y;
    D_80079B58.button = D_80079B40[0].button;
    if (func_800A9CAC() != 0) {
        if (_glrecord_entrypoint_0(D_80079B40, &lag) == 0) {
            func_800A9CDC();
        } else {
            func_800D8FA0(lag);
        }
    }
    func_800DC0C0();
    for (i = 0; i < 4; i++) {
        if (D_80079B40[i].errno & 8) {
            D_80079D6C[i] = 0;
        } else {
            D_80079D6C[i] = 1;
        }
        if ((D_80079B40[i].button & 0x20) && (D_80079B40[i].button & 0x10)) {
            if (D_80079B40[i].button & 0x4000) {
                D_800799C0[i].unk0[0]++;
            } else {
                D_800799C0[i].unk0[0] = 0;
            }
        } else {
            for (j = 0; j < 2; j++) {
                D_800799C0[i].unk0[j] = 0;
            }
        }
        if (D_80079B40[i].button & 0x8000) {
            D_800799E0[i].held[0]++;
        } else {
            D_800799E0[i].held[0] = 0;
        }
        if (D_80079B40[i].button & 0x4000) {
            D_800799E0[i].held[1]++;
        } else {
            D_800799E0[i].held[1] = 0;
        }
        if (D_80079B40[i].button & 0x2) {
            D_800799E0[i].held[2]++;
        } else {
            D_800799E0[i].held[2] = 0;
        }
        if (D_80079B40[i].button & 0x4) {
            D_800799E0[i].held[3]++;
        } else {
            D_800799E0[i].held[3] = 0;
        }
        if (D_80079B40[i].button & 0x8) {
            D_800799E0[i].held[4]++;
        } else {
            D_800799E0[i].held[4] = 0;
        }
        if (D_80079B40[i].button & 0x1) {
            D_800799E0[i].held[5]++;
        } else {
            D_800799E0[i].held[5] = 0;
        }
        if (D_80079B40[i].button & 0x2000) {
            D_800799E0[i].held[6]++;
        } else {
            D_800799E0[i].held[6] = 0;
        }
        if (D_80079B40[i].button & 0x20) {
            D_800799E0[i].held[7]++;
        } else {
            D_800799E0[i].held[7] = 0;
        }
        if (D_80079B40[i].button & 0x10) {
            D_800799E0[i].held[8]++;
        } else {
            D_800799E0[i].held[8] = 0;
        }
        if (D_80079B40[i].button & 0x800) {
            D_800799E0[i].held[9]++;
        } else {
            D_800799E0[i].held[9] = 0;
        }
        if (D_80079B40[i].button & 0x400) {
            D_800799E0[i].held[10]++;
        } else {
            D_800799E0[i].held[10] = 0;
        }
        if (D_80079B40[i].button & 0x200) {
            D_800799E0[i].held[11]++;
        } else {
            D_800799E0[i].held[11] = 0;
        }
        if (D_80079B40[i].button & 0x100) {
            D_800799E0[i].held[12]++;
        } else {
            D_800799E0[i].held[12] = 0;
        }
        if (D_80079B40[i].button & 0x1000) {
            D_800799E0[i].held[13]++;
        } else {
            D_800799E0[i].held[13] = 0;
        }
        if (i == 0) {
            if (D_80079B58.button & 0x8000) {
                D_80079AC0.held[0]++;
            } else {
                D_80079AC0.held[0] = 0;
            }
            if (D_80079B58.button & 0x4000) {
                D_80079AC0.held[1]++;
            } else {
                D_80079AC0.held[1] = 0;
            }
            if (D_80079B58.button & 0x2) {
                D_80079AC0.held[2]++;
            } else {
                D_80079AC0.held[2] = 0;
            }
            if (D_80079B58.button & 0x4) {
                D_80079AC0.held[3]++;
            } else {
                D_80079AC0.held[3] = 0;
            }
            if (D_80079B58.button & 0x8) {
                D_80079AC0.held[4]++;
            } else {
                D_80079AC0.held[4] = 0;
            }
            if (D_80079B58.button & 0x1) {
                D_80079AC0.held[5]++;
            } else {
                D_80079AC0.held[5] = 0;
            }
            if (D_80079B58.button & 0x2000) {
                D_80079AC0.held[6]++;
            } else {
                D_80079AC0.held[6] = 0;
            }
            if (D_80079B58.button & 0x20) {
                D_80079AC0.held[7]++;
            } else {
                D_80079AC0.held[7] = 0;
            }
            if (D_80079B58.button & 0x10) {
                D_80079AC0.held[8]++;
            } else {
                D_80079AC0.held[8] = 0;
            }
            if (D_80079B58.button & 0x800) {
                D_80079AC0.held[9]++;
            } else {
                D_80079AC0.held[9] = 0;
            }
            if (D_80079B58.button & 0x400) {
                D_80079AC0.held[10]++;
            } else {
                D_80079AC0.held[10] = 0;
            }
            if (D_80079B58.button & 0x200) {
                D_80079AC0.held[11]++;
            } else {
                D_80079AC0.held[11] = 0;
            }
            if (D_80079B58.button & 0x100) {
                D_80079AC0.held[12]++;
            } else {
                D_80079AC0.held[12] = 0;
            }
            if (D_80079B58.button & 0x1000) {
                D_80079AC0.held[13]++;
            } else {
                D_80079AC0.held[13] = 0;
            }
            if ((D_80079B58.button & 0x20) && (D_80079B58.button & 0x10)) {
                if (D_80079B58.button & 0x4000) {
                    D_800799C0[i].unk0[1]++;
                } else {
                    D_800799C0[i].unk0[1] = 0;
                }
            }
        }
        j = D_80079AF8[i].current;
        curr_buttons = D_80079B40[i].button;
        D_80079AF8[i].current = curr_buttons;
        D_80079AF8[i].pressed = (u16)~j & curr_buttons;
        D_80079AF8[i].released = ~curr_buttons & j;
        D_80079AF8[i].previous = j;
        D_80079AF8[i].stick_x = func_80015D60(D_80079B40[i].stick_x, 7, 0x3B);
        D_80079AF8[i].stick_y = func_80015D60(D_80079B40[i].stick_y, 7, 0x3D);
    }
    D_80079D69 = 1;
    osSetThreadPri(&D_80079BA8, pri);
}

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
    s32 eeprom_type = osEepromProbe(&D_80079B60); BT_NATIVE_ONLY(((s32 *)D_80079D70)[0x1EC / 4] = eeprom_type;)  // N64 frame slot, read by gldbDll
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
    func_8001DCB0(&D_80079BA8, &D_80079D58, THREAD_ID_JOY, func_800166DC, NULL, BT_NATIVE_ONLY((u8 *)D_80079D70 + 0x1D0) BT_IDO_ONLY(&D_80079D70[JOY_THREAD_STACK_SIZE / sizeof(u64)]), JOY_THREAD_PRI);
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
        D_80079AF8[i].current = 0;
        D_80079AF8[i].previous = 0;
        D_80079AF8[i].pressed = 0;
        D_80079AF8[i].released = 0;
        D_80079AF8[i].stick_x = 0.0f;
        D_80079AF8[i].stick_y = 0.0f;
        
        for (j = 0; j < (s32)ARRLEN(D_800799C0[i].unk0); j++) {
            D_800799C0[i].unk0[j] = 0;
        }
        
        for (j = 0; j < ARRLEN(D_800799E0[i].held); j++) {
            D_800799E0[i].held[j] = 0;
        }
    }
}

void func_8001690C(s32 arg0, s32 arg1) {
    D_800799E0[arg0].held[6] = arg1;
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

s32 func_80016A74(u32 arg0, f32 *arg1) {
    f32 func_80013B70(f32, f32, f32);
    f32 stick[2];
    f32 length;
    f32 angle = -1.0f;

    func_80016068(arg0, stick);
    length = sqrtf(stick[0] * stick[0] + stick[1] * stick[1]);
    if (length != 0.0f) {
        angle = func_80013B70(stick[1], stick[0], length);
    }
    if (arg1 != NULL) {
        if (length > 1.0f) {
            *arg1 = 1.0f;
        } else {
            *arg1 = length;
        }
    }
    return (s32) angle;
}

s32 func_80016B30(s32 arg0, s32 arg1) {
    return D_800799E0[arg0].held[arg1];
}

s32 func_80016B54(s32 arg0, s32 arg1) {
    BT_IDO_ONLY(extern s32 D_800799F8[][14];)
    return BT_DATA_FIELD(D_800799E0[arg0].held[6 + arg1], D_800799F8[arg0][arg1]);
}

s32 func_80016B78(s32 arg0, s32 arg1) {
    BT_IDO_ONLY(extern s32 D_80079A04[][14];)
    return BT_DATA_FIELD(D_800799E0[arg0].held[9 + arg1], D_80079A04[arg0][arg1]);
}

s32 func_80016B9C(s32 arg0, u16 arg1) {
    return D_80079AF8[arg0].current & arg1;
}

s32 func_80016BBC(s32 arg0, u16 arg1) {
    BT_IDO_ONLY(extern u16 D_80079AFC[][8];)
    return BT_DATA_FIELD(D_80079AF8[arg0].pressed, D_80079AFC[arg0][0]) & arg1;
}

void func_80016BDC(s32 arg0) {
    osContSetCh((u8) arg0);
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
unkD_800799C0 D_800799C0 [ 4 ] BT_DATA(4, bss_core1bss1_0_audio_frame_tail, 0x3080);
ControllerButtonFrames D_800799E0 [ 4 ] BT_DATA(4, bss_core1bss1_0_audio_frame_tail, 0x30A0);
ControllerButtonFrames D_80079AC0 BT_DATA(4, bss_core1bss1_0_audio_frame_tail, 0x3180);
ControllerSnapshot D_80079AF8 [ 4 ] BT_DATA(4, bss_core1bss1_0_audio_frame_tail, 0x31B8);
OSMesg D_80079B38 BT_DATA(4, bss_core1bss1_0_audio_frame_tail, 0x31F8);
OSMesg D_80079B3C BT_DATA(4, bss_core1bss1_0_audio_frame_tail, 0x31FC);
OSContPad D_80079B40 [ 4 ] BT_DATA(4, bss_core1bss1_0_audio_frame_tail, 0x3200);
OSContPad D_80079B58 BT_DATA(4, bss_core1bss1_0_audio_frame_tail, 0x3218);
OSMesgQueue D_80079B60 BT_DATA(4, bss_core1bss1_0_audio_frame_tail, 0x3220);
OSMesgQueue D_80079B78 BT_DATA(4, bss_core1bss1_0_audio_frame_tail, 0x3238);
OSContStatus D_80079B90 [ 4 ] BT_DATA(4, bss_core1bss1_0_audio_frame_tail, 0x3250);
volatile s32 D_80079BA0 BT_DATA(4, bss_core1bss1_0_audio_frame_tail, 0x3260);
OSThread D_80079BA8 BT_DATA(8, bss_core1bss1_0_audio_frame_tail, 0x3268);
__OSThreadOddFpStorage D_80079D58 BT_DATA(8, bss_core1bss1_0_audio_frame_tail, 0x3418);
u8 D_80079D68 BT_DATA(4, bss_core1bss1_0_audio_frame_tail, 0x3428);
u8 D_80079D69 BT_DATA(4, bss_core1bss1_0_audio_frame_tail, 0x3429);
u8 D_80079D6C [ 4 ] BT_DATA(4, bss_core1bss1_0_audio_frame_tail, 0x342C);
u64 D_80079D70 [ JOY_THREAD_STACK_SIZE / sizeof ( u64 ) ] BT_DATA(8, bss_core1bss1_0_audio_frame_tail, 0x3430);
OSMesgQueue D_80079F70 BT_DATA(4, bss_core1bss1_0_audio_frame_tail, 0x3630);
OSMesg D_80079F88 [ 6 ] BT_DATA(4, bss_core1bss1_0_audio_frame_tail, 0x3648);
#endif
