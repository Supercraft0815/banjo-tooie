#include "common.h"

s32 func_80800000_gztrace(u32 arg0) {
    if ((arg0 < 0x80000000U) || (arg0 >= 0x80800001U) || (arg0 & 3)) {
        return 0;
    }
    return 1;
}

void func_80800038_gztrace(u8 *arg0, u8 *arg1) {
    while ((*arg0++ = *arg1++) != 0) {
    }
}

void func_80800068_gztrace(u8 *arg0, u8 *arg1) {
    u8 *dest;
    s32 c;

    dest = arg0;
    while ((c = *dest++) != 0) {
    }
    dest--;
    while ((c = *arg1, *dest++ = c, arg1++, c != 0)) {
    }
}

s32 func_808000B8_gztrace(u8 *arg0) {
    s32 len;
    u8 *p;

    len = 0;
    p = arg0;
    while (*p != 0) {
        len++;
        p++;
    }
    return len;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gz/trace/func_808000E8_gztrace.s")

u8 *func_80800290_gztrace(s32 arg0, s32 arg1, u8 *arg2) {
    s32 i;
    u8 *dest;
    u8 *bytes;

    bytes = (u8 *)&arg0;
    dest = arg2;
    for (i = 4 - arg1; i < 4; i++) {
        *dest = (bytes[i] >> 4) + '0';
        if (*dest >= ':') {
            *dest += 0x27;
        }
        dest++;
        *dest = (bytes[i] & 0xF) + '0';
        if (*dest >= ':') {
            *dest += 0x27;
        }
        dest++;
    }
    return dest;
}

void func_808003D0_gztrace(u8 *arg0) {
    struct TraceHeader {
        s16 count0, count2, count4, count6, count8, countA, countC;
        u8 countE;
    };
    struct TraceHeader *header = (struct TraceHeader *)arg0;
    struct TraceData {
        s32 count;
        u8 *base;
        u8 *table;
        s32 tableCount;
            u8 *data10;
        u8 *data14;
        u8 *data18;
        u8 *data1C;
        u8 *data20;
        u8 *data24;
        u8 *data28;
        u8 *data2C;
        u8 *data30;
    };
    extern struct TraceData B_80800A70_gztrace;
    struct TraceData *trace;

    trace = &B_80800A70_gztrace;

    trace->count = *(s16 *)(arg0 + 0x2C);
    trace->tableCount = *(s16 *)(arg0 + 8);
    trace->base = arg0;
    trace->data18 = trace->base + 0x34;
    trace->table = trace->base + 0x38;
    trace->data1C = (u8 *)((s32)arg0 + header->count8 * 4 + 0x38);
    trace->data10 = (u8 *)((((s32)trace->data1C + header->countE) + 3) & ~3);
    trace->data14 = trace->data10 + *(s16 *)(arg0 + 0xA) * 2;
    *(s32 *)&trace->data14 += 3;
    *(s32 *)&trace->data14 &= ~3;
    trace->data20 = trace->data14 + *(s16 *)(arg0 + 0xC) * 4;
    *(s32 *)&trace->data20 += 0xF;
    *(s32 *)&trace->data20 &= ~0xF;
    trace->data24 = trace->data20 + *(s16 *)arg0 * 0x10;
    trace->data28 = trace->data24 + *(s16 *)(arg0 + 2) * 0x10;
    trace->data2C = trace->data28 + *(s16 *)(arg0 + 4) * 0x10;
    trace->data30 = trace->data2C + *(s16 *)(arg0 + 6) * 0x10;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gz/trace/func_808004B0_gztrace.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gz/trace/func_808005C4_gztrace.s")

void gztrace_entrypoint_0(void) {
}

void gztrace_entrypoint_1(OSThread *arg0, s32 arg1, s32 arg2, s32 arg3) {
    void func_8001D37C(s32 arg0, ...);
    s32 func_808004B0_gztrace(s32 *, u32 *, s32 *, s32 *, u32);
    s32 func_808005C4_gztrace(u32, s32, u32, s32, s32);
    u32 ra;
    u32 pc;
    s32 sp;
    s32 unused40;
    s32 unused3C;

    pc = arg0->context.pc;
    sp = arg0->context.sp;
    ra = arg0->context.ra;
    func_8001D37C("Stack trace: %s\n\nSP = %08X, PC = %08X, RA = %08X\n\n",
                 arg2 == 0 ? "Work-Station" : "N64", sp, pc, ra);
    if (func_80800000_gztrace(pc) == 0) {
        pc = ra;
        ra = 0;
        if (func_80800000_gztrace(pc) == 0) {
            func_8001D37C("Unable to trace, invalid PC,RA!\n");
            return;
        }
    }
    while (arg1--) {
        func_808004B0_gztrace(&sp, &pc, &unused40, &unused3C, ra);
        ra = 0;
    }
    func_808005C4_gztrace(pc, sp, ra, arg2, arg3);
}
