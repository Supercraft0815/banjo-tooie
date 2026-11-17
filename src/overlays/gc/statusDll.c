#include "common.h"

typedef struct StatusState {
    s32 value;
    s8 state;
    s8 pad5[4];
    s8 flag;
    s8 padA[5];
    s8 fieldF;
    s8 field10;
    s8 field11;
    u8 pad12[14];
} StatusState;

StatusState D_8012B400;

void gcstatusDll_entrypoint_0(void)
{
    void gcstatusDll_entrypoint_3(s32, s32);
    void gcstatusDll_entrypoint_6(s32, s32);
    extern u8 D_80800230_gcstatusDll[4][2];
    s32 var_s0;
    StatusState *temp_s3;
    temp_s3 = &D_8012B400;
    temp_s3->state = 2;
    for (var_s0 = 0; var_s0 != 4; var_s0++)
    {
      gcstatusDll_entrypoint_3(var_s0, D_80800230_gcstatusDll[var_s0][0]);
      gcstatusDll_entrypoint_6(var_s0, D_80800230_gcstatusDll[var_s0][1]);
    }

    temp_s3 = &D_8012B400;
    temp_s3->flag = 1;
    temp_s3->fieldF = 0;
    temp_s3->field10 = 0;
    temp_s3->field11 = 2;
    temp_s3->value = 0x173;
}    typedef struct { u8 pad0[0x4]; s32 unk4; s8 unk8; u8 pad9[0x4]; s8 unkD; u8 padE[0x4]; s8 unk12; s8 unk13; s8 unk14; s8 unk15; } ObjstatusDll_D_8012B3FC; /* offsets.py genstruct: fields from raw offsets on &D_8012B3FC; rename once understood */


void gcstatusDll_entrypoint_1(s32 arg0) {
    extern s32 D_8012B3FC;
    ((ObjstatusDll_D_8012B3FC *)&D_8012B3FC)->unk4 = arg0;
}

void gcstatusDll_entrypoint_2(s32 arg0) {
    extern s32 D_8012B3FC;
    ((ObjstatusDll_D_8012B3FC *)&D_8012B3FC)->unk8 = arg0;
}

void gcstatusDll_entrypoint_3(s32 arg0, s32 arg1) {
    extern s32 D_8012B3FC;
    *(s8 *)((u8 *)&D_8012B3FC + 9 + arg0) = arg1;
}

void gcstatusDll_entrypoint_4(s32 arg0) {
    extern s32 D_8012B3FC;
    ((ObjstatusDll_D_8012B3FC *)&D_8012B3FC)->unkD = arg0;
}

void gcstatusDll_entrypoint_5(s32 arg0) {
    extern s32 D_8012B3FC;
    ((ObjstatusDll_D_8012B3FC *)&D_8012B3FC)->unk12 = arg0;
}

void gcstatusDll_entrypoint_6(s32 arg0, s32 arg1) {
    extern s32 D_8012B3FC;
    *(s8 *)((u8 *)&D_8012B3FC + 14 + arg0) = arg1;
}

void gcstatusDll_entrypoint_7(s32 arg0) {
    extern s32 D_8012B3FC;
    ((ObjstatusDll_D_8012B3FC *)&D_8012B3FC)->unk13 = arg0;
}

void gcstatusDll_entrypoint_8(s32 arg0) {
    extern s32 D_8012B3FC;
    ((ObjstatusDll_D_8012B3FC *)&D_8012B3FC)->unk14 = arg0;
}

void gcstatusDll_entrypoint_9(s32 arg0) {
    extern s32 D_8012B3FC;
    ((ObjstatusDll_D_8012B3FC *)&D_8012B3FC)->unk15 = arg0;
}

u8 gcstatusDll_entrypoint_10(void) {
    extern s32 D_8012B3FC;
    return (*(u8 *)((s8 *)(&D_8012B3FC) + (8)));
}

u8 gcstatusDll_entrypoint_11(void) {
    extern u8 D_8012762C;
    extern s32 D_8012B3FC;
    u8 value = *((u8 *)&D_8012B3FC + 8);
    if (D_8012762C != 0x1B) {
        return 1U;
    }
    return value;
}

s32 gcstatusDll_entrypoint_12(void) {
    extern s32 D_8012B3FC;
    return *&((ObjstatusDll_D_8012B3FC *)&D_8012B3FC)->unk4;
}

u8 gcstatusDll_entrypoint_13(s32 arg0) {
    extern s32 D_8012B3FC;
    return *((u8 *)&D_8012B3FC + 9 + arg0);
}

u8 gcstatusDll_entrypoint_14(void) {
    extern s32 D_8012B3FC;
    u8 result;
    result = *((u8 *)&D_8012B3FC + 13);
    return result;
}

u8 gcstatusDll_entrypoint_15(void) {
    extern s32 D_8012B3FC;
    return (*(u8 *)((s8 *)(&D_8012B3FC) + (18)));
}

u8 gcstatusDll_entrypoint_16(BtIntPtr arg0) {
    extern s32 D_8012B3FC;
    return *((u8 *)&D_8012B3FC + 14 + arg0);
}

u8 gcstatusDll_entrypoint_17(void) {
    extern s32 D_8012B3FC;
    u8 result;
    result = *((u8 *)&D_8012B3FC + 19);
    return result;
}

u8 gcstatusDll_entrypoint_18(void) {
    extern s32 D_8012B3FC;
    u8 result;
    result = *((u8 *)&D_8012B3FC + 20);
    return result;
}

u8 gcstatusDll_entrypoint_19(void) {
    extern s32 D_8012B3FC;
    u8 result;
    result = *((u8 *)&D_8012B3FC + 21);
    return result;
}

s32 gcstatusDll_entrypoint_20(void) {
    s32 func_800D3948(void);
    u8 status;

    if (func_800D3948() != 0) {
        status = gcstatusDll_entrypoint_14();
        switch (status) {
        case 3:
        case 5:
            return 1;
        case 0:
        case 1:
        case 2:
        case 4:
        case 6:
        default:
            break;
        }
    }
    return 0;
}
/* data_to_c.py: from asm/data/overlays/gc/statusDll.data.s */
u8 D_80800230_gcstatusDll [ 4 ] [ 2 ] BT_DATA(4, overlays_gc_statusDll, 0x0) = { { 1, 0 }, { 2, 1 }, { 4, 2 }, { 5, 3 } };

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
s32 D_8012B3FC BT_DATA(4, bss_core2bss1_2, 0x16C);
#endif
