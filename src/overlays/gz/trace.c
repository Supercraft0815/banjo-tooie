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

void func_808000E8_gztrace(u8 *arg0, u8 *arg1, s32 arg2, u8 arg3, s32 arg4) {
    s32 i;
    s32 j;
    s32 len;
    s32 size;

    len = func_808000B8_gztrace(arg1);
    size = arg2 + arg4 + 1;
    if (size >= len) {
        func_80800038_gztrace(arg0, arg1);
        for (i = len; i < size; i++) {
            arg0[i] = ' ';
        }
    } else {
        for (i = 0; i < arg2; i++) {
            arg0[i] = arg1[i];
        }
        arg0[i++] = arg3;
        for (j = len - arg4; i < size; i++, j++) {
            arg0[i] = *(j + arg1);
        }
    }
    arg0[size] = 0;
}

u8 *func_80800290_gztrace(BtIntPtr arg0, s32 arg1, u8 *arg2) {
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

void func_808003D0_gztrace(u8 *arg0) {
    struct TraceHeader {
        s16 count0, count2, count4, count6, count8, countA, countC;
        u8 countE;
    };
    struct TraceHeader *header = (struct TraceHeader *)arg0;
    extern struct TraceData B_80800A70_gztrace;
    struct TraceData *trace;

    trace = &B_80800A70_gztrace;

    trace->count = *(s16 *)(arg0 + 0x2C);
    trace->tableCount = *(s16 *)(arg0 + 8);
    trace->base = arg0;
    trace->data18 = trace->base + 0x34;
    trace->table = trace->base + 0x38;
    trace->data1C = (u8 *)((BtIntPtr)arg0 + header->count8 * 4 + 0x38);
    trace->data10 = (u8 *)((((BtIntPtr)trace->data1C + header->countE) + 3) & ~3);
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

s32 func_808004B0_gztrace(s32 *arg0, u32 *arg1, s32 *arg2, s32 *arg3, BtUIntPtr arg4) {
    s32 done;
    u32 stack;
    u32 ra;
    BtUIntPtr cursor;
    u32 instruction;
    u32 upper;
    u32 opcode;
    BtUIntPtr address;

    stack = (u32)*arg0;
    cursor = *arg1;
    ra = *arg1;
    *arg3 = ra - 8;
    done = 0;
    while (done == 0) {
        instruction = *(u32 *)cursor; cursor += 4;
        upper = instruction >> 16;
        switch (upper) {
        case 0x8FBF:
            address = stack;
            address += (s16)instruction;
            arg4 = *(u32 *)address;
            break;
        case 0x27BD:
            stack += ((s16)instruction >> 2) * 4;
            break;
        case 0x3E0:
            done = 1;
            break;
        }
    }
    instruction = *(u32 *)cursor;
    if ((instruction >> 16) == 0x27BD) {
        stack += ((s16)instruction >> 2) * 4;
    }
    *arg1 = arg4;
    *arg0 = (s32)stack;
    if (arg4 != 0) {
        instruction = *(u32 *)(arg4 - 8);
        opcode = instruction >> 26;
        switch (opcode) {
        case 3:
            *arg2 = 0x80000000U + ((instruction - 0x0C000000U) << 2);
            return 1;
        case 0:
            if ((instruction & 0x3F) == 9) {
                *arg2 = 0;
                return 1;
            }
            break;
        default:
            return 0;
        }
    }
    return 0;
}

s32 func_808005C4_gztrace(u32 arg0, BtIntPtr arg1, u32 arg2, s32 arg3, s32 arg4) {
    extern struct TraceData B_80800A70_gztrace;
    extern u8 B_80800AA8_gztrace[];
    extern u8 B_80800ABA_gztrace, B_80800ABD_gztrace, B_80800AC3_gztrace;
    extern u8 B_80800ACD_gztrace, B_80800AD5_gztrace, B_80800AD6_gztrace;
    extern s32 overlay_syscalls, overlay_syscalls_end;
    struct Overlay *func_80081AA4(void *);
    void func_8001D37C(BtIntPtr, ...);
    s32 func_808004B0_gztrace(s32 *, u32 *, s32 *, s32 *, BtUIntPtr);
    s32 sp5C;
    s32 sp58;
    s32 address;
    s32 first;
    s32 second;
    s32 count;
    u8 *overlay;

    count = 0;
    if (func_808004B0_gztrace(&arg1, &arg0, &sp5C, &sp58, arg2)) {
        do {
            first = sp5C;
            second = sp58;
            if (sp5C != 0) {
                address = sp5C;
            } else {
                address = sp58;
            }
            overlay = (u8 *)func_80081AA4((void *)address);
            if (overlay != NULL) {
                func_808003D0_gztrace(overlay);
                func_808000E8_gztrace(B_80800AA8_gztrace, B_80800A70_gztrace.data1C, 13, 0x7E, 2);
                if (arg3 == 0) {
                    if (first != 0 && (first < (BtIntPtr)&overlay_syscalls || (BtIntPtr)&overlay_syscalls_end < first)) {
                        first -= (BtIntPtr)B_80800A70_gztrace.data20;
                    }
                    second -= (BtIntPtr)B_80800A70_gztrace.data20;
                }
            } else {
                func_808000E8_gztrace(B_80800AA8_gztrace, "core", 13, 0x7E, 2);
            }
            switch (arg3) {
                case 0:
                    func_80800068_gztrace(B_80800AA8_gztrace, " (********,********) ");
                    func_80800290_gztrace(((s32 *)arg1)[0], 4, &B_80800ABA_gztrace);
                    func_80800290_gztrace(((s32 *)arg1)[1], 4, &B_80800AC3_gztrace);
                    break;
                case 1:
                    func_80800068_gztrace(B_80800AA8_gztrace, " SP: ********    PC: ");
                    func_80800290_gztrace(arg1, 4, &B_80800ABD_gztrace);
                    break;
            }
            if (sp5C != 0) {
                func_80800290_gztrace(first, 4, &B_80800ACD_gztrace);
            } else {
                func_80800068_gztrace(&B_80800ACD_gztrace, " (*f)() ");
            }
            func_80800068_gztrace(&B_80800AD5_gztrace, "-********");
            func_80800290_gztrace(second, 4, &B_80800AD6_gztrace);
            B_80800AA8_gztrace[0x36] = 0;
            if (arg4 == 0) {
                func_8001D37C("%s\n", B_80800AA8_gztrace);
            }
            count++;
        } while (count < 16 && func_808004B0_gztrace(&arg1, &arg0, &sp5C, &sp58, arg2)); BT_NATIVE_ONLY(return 0;)
    }
}

void gztrace_entrypoint_0(void) {
}

void gztrace_entrypoint_1(OSThread *arg0, s32 arg1, s32 arg2, s32 arg3) {
    void func_8001D37C(BtIntPtr arg0, ...);
    s32 func_808004B0_gztrace(s32 *, u32 *, s32 *, s32 *, BtUIntPtr);
    s32 func_808005C4_gztrace(u32, BtIntPtr, u32, s32, s32);
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
/* data_to_c.py: from asm/data/overlays/gz/trace.data.s */
u8 D_80800A30_gztrace[62] BT_DATA(4, overlays_gz_trace, 0x0) = { 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x00 };

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
struct TraceData B_80800A70_gztrace BT_DATA(16, bss_gz_trace, 0x0);
u8 B_80800AA8_gztrace [ 18 ] BT_DATA(4, bss_gz_trace, 0x38);
u8 B_80800ABA_gztrace BT_DATA(4, bss_gz_trace, 0x4A);
u8 B_80800ACD_gztrace BT_DATA(4, bss_gz_trace, 0x5D);
#endif
