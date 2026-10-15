#include "common.h"

s32 *dbvpl_entrypoint_0(u8 *arg0, s32 arg1) {
    s32 i = 0;
    s32 count = *(s32 *)(arg0 + 0x2C);
    u8 *entry = arg0;
    s32 *p;
    if (count > 0) {
loop:
        i++;
        p = (s32 *)(arg0 + *(s32 *)(entry + 0x30));
        if (arg1 == *p) return p;
        entry += 4;
        count = *(s32 *)(arg0 + 0x2C);
        if (i < count) goto loop;
    }
    return 0;
}

void dbvpl_entrypoint_1(s32 arg0, u8 *arg1, u8 *arg2, s32 *arg3) {
    u8 *func_800B2324(u8 *, u8 **, u8 **);
    u8 *begin;
    u8 *end[2];
    u8 *dst;
    s32 i;

    func_800B2324(arg2, &begin, end);
    for (arg2 = begin; arg2 < end[0]; arg2 += 16) {
        arg0 = *(u16 *)(arg2 + 6) & 0x7FFF;
        if (arg0 != 0x7FFF) {
            dst = arg1 + arg0 * 16;
            if (arg3[0] != 255 || arg3[1] != 255 || arg3[2] != 255) {
                for (i = 0; i < 3; i++) {
                    arg2[i + 12] = (arg2[i + 12] * arg3[i]) >> 8;
                }
            }
            aligned8_memcpy(dst, arg2, 16);
            *(u16 *)(dst + 6) &= 0x8000;
            *(u16 *)(dst + 6) |= ((arg2 - begin) >> 4) & 0x7FFF;
        }
    }
}
