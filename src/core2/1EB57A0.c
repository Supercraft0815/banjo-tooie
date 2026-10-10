#include "common.h"

/* extern */

void func_800DBEB0(s32 arg0) {
    s32 func_800EFD24(u32);
    u32 temp_s1;
    u32 var_s0;

    var_s0 = arg0 + 4;
    temp_s1 = arg0 + 0x118;
    if (var_s0 < temp_s1) {
        do {
            func_800EFD24(var_s0);
            var_s0 += 0xC;
        } while (var_s0 < temp_s1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB57A0/func_800DBEFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB57A0/func_800DBF38.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB57A0/func_800DBF74.s")

void func_800DBFD8(void* arg0) 
{
    heap_free(arg0);
}
u8 *func_800DBFF8(void) {
    void* heap_alloc(s32 size);
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = heap_alloc(0x118);
    sp1C = temp_v0;
    func_800DBEB0((s32) temp_v0);
    return sp1C;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB57A0/func_800DC028.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EB57A0/func_800DC060.s")
