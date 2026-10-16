#include "common.h"

extern s32 D_808008B0_scinfobar;

void func_80800000_scinfobar(void *arg0, s32 arg1) {
    u8 func_800E8B74(u32);
    void func_800E8D28(u8, f32);
    void func_800E8D5C(u8, void *, s16);
    struct InfobarEntry {
        s16 id;
        s16 pad;
        s32 value;
        void *data;
    };
    f32 sp1C;

    if ((((struct InfobarEntry *)&D_808008B0_scinfobar)[arg1].value << 17 >> 17) != 0) {
        sp1C = (f32) (((struct InfobarEntry *)&D_808008B0_scinfobar)[arg1].value << 17 >> 17) * 0.00390625f;
        (*(u8 *)((s8 *)(arg0) + (0x32))) = func_800E8B74(((struct InfobarEntry *)&D_808008B0_scinfobar)[arg1].id);
        if (((struct InfobarEntry *)&D_808008B0_scinfobar)[arg1].data != 0) {
            func_800E8D5C((*(u8 *)((s8 *)(arg0) + (0x32))), ((struct InfobarEntry *)&D_808008B0_scinfobar)[arg1].data, 0);
        }
        func_800E8D28((*(u8 *)((s8 *)(arg0) + (0x32))), sp1C);
        return;
    }
    (*(u8 *)((s8 *)(arg0) + (0x32))) = 0U;
}

void func_808000B0_scinfobar(void *arg0) {
    s16 temp_v0;

    (*(s16 *)((s8 *)(arg0) + (0x30))) = 0;
    temp_v0 = (*(s16 *)((s8 *)(arg0) + (0x30)));
    (*(s16 *)((s8 *)(arg0) + (0x2E))) = temp_v0;
    (*(s16 *)((s8 *)(arg0) + (0x2C))) = temp_v0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/sc/infobar/func_808000C4_scinfobar.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/sc/infobar/func_80800144_scinfobar.s")

void *scinfobar_entrypoint_0(s32 arg0, s32 arg1, s32 arg2) {
    void *heap_alloc(s32);
    void scinfobar_entrypoint_3(void *, s32);
    void scinfobar_entrypoint_10(void *, s32);
    void *ptr;

    ptr = heap_alloc(0x34);
    *(s8 *)((s8 *)ptr + 0) = 0x64;
    *(s8 *)((s8 *)ptr + 2) = 0;
    *(s16 *)((s8 *)ptr + 4) = arg0;
    *(s16 *)((s8 *)ptr + 6) = -1;
    *(s8 *)((s8 *)ptr + 1) = arg1;
    *(s8 *)((s8 *)ptr + 3) = 0;
    *(s8 *)((s8 *)ptr + 0xA) = 0;
    *(f32 *)((s8 *)ptr + 0x14) = 0.0f;
    scinfobar_entrypoint_3(ptr, arg2);
    scinfobar_entrypoint_10(ptr, 0xD8);
    *(s32 *)((s8 *)ptr + 0x24) = 0;
    *(s32 *)((s8 *)ptr + 0x28) = 0;
    *(s32 *)((s8 *)ptr + 0x20) = 0;
    func_808000B0_scinfobar(ptr);
    func_80800000_scinfobar(ptr, arg0);
    return ptr;
}

/* extern */

void scinfobar_entrypoint_1(void *arg0) {
    s32 func_800E8C08(s32, u8, void *);
    s32 heap_free(void *);
    u8 temp_a1;

    temp_a1 = (*(u8 *)((s8 *)(arg0) + (0x32)));
    if (temp_a1 != 0) {
        func_800E8C08(temp_a1 & 0xFF, temp_a1, arg0);
    }
    heap_free(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/sc/infobar/scinfobar_entrypoint_2.s")

void scinfobar_entrypoint_3(void *arg0, s32 arg1) {
    struct Entry { f32 value; f32 rest[2]; };
    extern struct Entry D_80800D5C_scinfobar[];
    if (*(u8 *)((s8 *)arg0 + 2) != 0) {
        *(s16 *)((s8 *)arg0 + 0x30) = arg1;
        return;
    }
    *(s32 *)((s8 *)arg0 + 0x1C) = arg1;
    *(f32 *)((s8 *)arg0 + 0xC) = D_80800D5C_scinfobar[arg1].value;
}

void scinfobar_entrypoint_4(s32 *arg0, s32 arg1) {
    arg0[10] = arg1;
}

void scinfobar_entrypoint_5(s8 *arg0, s32 arg1) {
    arg0[10] = arg1;
}

/* extern */

void scinfobar_entrypoint_6(u8 *arg0, s32 arg1) {
    void func_80800144_scinfobar(u8 *, s32);
    if (arg1 != 0) {
        if (*arg0 != 0x66) {
            func_80800144_scinfobar(arg0, 0x65);
        }
    } else if (*arg0 != 0x64) {
        func_80800144_scinfobar(arg0, 0x67);
    }
}

s32 scinfobar_entrypoint_7(void *arg0, s32 arg1) {
    u8 temp_v0;

    if ((*(u8 *)((s8 *)(arg0) + (2))) != 0) {
        return 0;
    }
    if ((arg1 == (*(s16 *)((s8 *)(arg0) + (4)))) || (arg1 == (*(s16 *)((s8 *)(arg0) + (6))))) {
        return 1;
    }
    temp_v0 = (*(u8 *)((s8 *)(arg0) + (0)));
    (*(s16 *)((s8 *)(arg0) + (6))) = arg1;
    if ((temp_v0 == 0x66) || (temp_v0 == 0x65)) {
        (*(u8 *)((s8 *)(arg0) + (2))) = 0x67U;
    } else {
        (*(u8 *)((s8 *)(arg0) + (2))) = 0x65U;
    }
    return 1;
}

void scinfobar_entrypoint_8(u32 *arg0, s32 arg1) {
    if (((u8 *)arg0)[2] != 0) {
        ((s16 *)arg0)[22] = arg1;
        return;
    }
    arg0[8] = arg1;
}

void scinfobar_entrypoint_9(u32 *arg0, s32 arg1) {
    if (((u8 *)arg0)[2] != 0) {
        ((s16 *)arg0)[23] = arg1;
        return;
    }
    arg0[9] = arg1;
}

void scinfobar_entrypoint_10(void *arg0, s32 arg1) {
    struct InfobarEntry10 { s16 pad[4]; s16 value; s16 pad2; f32 rate; f32 factor; f32 pad3; f32 duration; };
    struct InfobarEntry10 *p = arg0;
    p->value = arg1;
    p->factor = (f32) arg1 / (24.0f * p->rate);
    p->duration = 250.0f / (f32) arg1;
}

s32 scinfobar_entrypoint_11(void *arg0) {
    struct InfobarEntry11 { s16 pad[4]; s16 value; s16 pad2[5]; f32 factor; };
    struct InfobarEntry11 *p = arg0;
    return (s32)(p->factor * (f32)p->value);
}

s32 scinfobar_entrypoint_12(s16 *arg0) {
    return arg0[4];
}

f32 scinfobar_entrypoint_13(f32 *arg0)
{
    return arg0[5];
}

s32 scinfobar_entrypoint_14(s32 *arg0) {
    return arg0[10];
}

u32 scinfobar_entrypoint_15(u8 *arg0) {
    return arg0[1];
}

s32 scinfobar_entrypoint_16(s16 *arg0) {
    return arg0[2];
}

u32 scinfobar_entrypoint_17(u8 *arg0) {
    return arg0[10];
}

f32 scinfobar_entrypoint_18(f32 *arg0) {
    return arg0[3];
}

s32 scinfobar_entrypoint_19(s32 *arg0) {
    return arg0[8];
}

s32 scinfobar_entrypoint_20(s32 *arg0) {
    return arg0[9];
}

s32 scinfobar_entrypoint_21(u8 *arg0) {
    return *arg0 == 100;
}

s32 scinfobar_entrypoint_22(u8 *arg0) {
    return *arg0 == 102;
}

s32 scinfobar_entrypoint_23(u8 *arg0) {
    return *arg0 == 101;
}

void func_80800608_scinfobar(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    void _fxdialog_entrypoint_2(f32);
    void _fxdialog_entrypoint_4(s32, s32, s32, f32, f32, s32, s32);
    s32 func_800E8C58(u8);
    extern s32 D_808008B0_scinfobar;
    union { struct { s16 temp; void *value; } fields; f64 alignment; } entry;

    if ((arg1 >= 0) && (arg1 < 0x64) && (arg1 != 0)) {
        entry.fields.value = (arg1 * 0xC) + (s8 *)&D_808008B0_scinfobar;
        entry.fields.temp = *(s16 *)((s8 *)entry.fields.value + 4);
        if (entry.fields.temp != 0) {
            _fxdialog_entrypoint_2((f32) entry.fields.temp * 0.00390625f);
        }
        arg2 = arg5 != 0 ? func_800E8C58(arg5) : 0;
        _fxdialog_entrypoint_4(arg0, (*(s16 *)((s8 *)(entry.fields.value) + (0))), arg2, (f32) (*(s8 *)((s8 *)(entry.fields.value) + (2))), (f32) (*(s8 *)((s8 *)(entry.fields.value) + (3))), arg4, (u32) (*(u16 *)((s8 *)(entry.fields.value) + (6))) >> 0xF);
    }
}

/* extern */

void func_808006EC_scinfobar(s32 arg0, void *arg1, s32 arg2, s32 arg3) {
    s32 _fxdialog_entrypoint_0();
    s32 _fxdialog_entrypoint_1(s32, s32);
    void _fxdialog_entrypoint_2(f32);
    s32 _fxdialog_entrypoint_3(s32, f32, u8, s32);
    _fxdialog_entrypoint_0();
    _fxdialog_entrypoint_1(arg2, arg3);
    _fxdialog_entrypoint_2((*(f32 *)((s8 *)(arg1) + (0xC))));
    _fxdialog_entrypoint_3(arg0, (f32) (*(s16 *)((s8 *)(arg1) + (8))) * (*(f32 *)((s8 *)(arg1) + (0x14))), (*(u8 *)((s8 *)(arg1) + (1))), 0xFF);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/sc/infobar/scinfobar_entrypoint_24.s")
