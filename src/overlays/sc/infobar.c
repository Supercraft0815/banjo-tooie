#include "common.h"
#include "infobar_tables.h"
extern InfobarEntry D_808008B0_scinfobar[99];         typedef struct { u8 unk0; u8 pad1[0x1]; u8 unk2; u8 pad3[0x1]; s16 unk4; s16 unk6; u8 pad8[0x4]; f32 unkC; u8 pad10[0x4]; f32 unk14; u8 pad18[0x4]; s32 unk1C; u8 pad20[0xC]; s16 unk2C; s16 unk2E; s16 unk30; u8 unk32; } Objinfobar_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_80800000_scinfobar(void *arg0, s32 arg1) {
    u8 func_800E8B74(u32);
    void func_800E8D28(u8, f32);
    void func_800E8D5C(u8, void *, s16);

    f32 sp1C;

    if (INFOBAR_FIXED_VALUE(D_808008B0_scinfobar[arg1]) != 0) {
        sp1C = (f32) INFOBAR_FIXED_VALUE(D_808008B0_scinfobar[arg1]) * 0.00390625f;
        (((Objinfobar_arg0 *)arg0)->unk32) = func_800E8B74(D_808008B0_scinfobar[arg1].id);
        if (D_808008B0_scinfobar[arg1].data != 0) {
            func_800E8D5C((((Objinfobar_arg0 *)arg0)->unk32), D_808008B0_scinfobar[arg1].data, 0);
        }
        func_800E8D28((((Objinfobar_arg0 *)arg0)->unk32), sp1C);
        return;
    }
    (((Objinfobar_arg0 *)arg0)->unk32) = 0U;
}

void func_808000B0_scinfobar(void *arg0) {
    s16 temp_v0;

    (((Objinfobar_arg0 *)arg0)->unk30) = 0;
    temp_v0 = (((Objinfobar_arg0 *)arg0)->unk30);
    (((Objinfobar_arg0 *)arg0)->unk2E) = temp_v0;
    (((Objinfobar_arg0 *)arg0)->unk2C) = temp_v0;
}

void func_808000C4_scinfobar(u32 *arg0, s32 temp_a1) {
    BT_IDO_ONLY(void func_800E8C08();) BT_NATIVE_ONLY(void func_800E8C08(u8);)
    void scinfobar_entrypoint_3(void *, s32);
    void scinfobar_entrypoint_8(u32 *, s32);
    void scinfobar_entrypoint_9(u32 *, s32);

    temp_a1 = ((Objinfobar_arg0 *)arg0)->unk32;
    ((Objinfobar_arg0 *)arg0)->unk4 = ((Objinfobar_arg0 *)arg0)->unk6;
    ((Objinfobar_arg0 *)arg0)->unk6 = -1;
    *(s8 *)((s8 *)arg0 + 2) = 0;
    if (temp_a1 != 0) {
        func_800E8C08((u8)temp_a1);
    }
    func_80800000_scinfobar(arg0, ((Objinfobar_arg0 *)arg0)->unk4);
    scinfobar_entrypoint_8(arg0, ((Objinfobar_arg0 *)arg0)->unk2C);
    scinfobar_entrypoint_9(arg0, ((Objinfobar_arg0 *)arg0)->unk2E);
    scinfobar_entrypoint_3(arg0, ((Objinfobar_arg0 *)arg0)->unk30);
    func_808000B0_scinfobar(arg0);
}


void func_80800144_scinfobar(u8 *arg0, s32 arg1) {
    extern InfobarStyle D_80800D54_scinfobar[9];
    void scinfobar_entrypoint_10(void *, s32);
    s32 index;

    s32 (*callback)(u8 *, s32);
    if (arg1 != arg0[0]) {
        if (arg0[2] != 0 && arg0[0] == arg0[2]) {
            func_808000C4_scinfobar((u32 *)arg0, arg1);
        }
        *(u8 *)arg0 = arg1;
        switch (arg1) {
        case 0x65:
            if (((Objinfobar_arg0 *)arg0)->unk2 != 0) {
                index = ((Objinfobar_arg0 *)arg0)->unk30;
            } else {
                index = ((Objinfobar_arg0 *)arg0)->unk1C;
            }
            callback = D_80800D54_scinfobar[index].value;
            if (callback != NULL) {
                scinfobar_entrypoint_10(arg0, callback(arg0, arg1));
            }
            break;
        case 0x66:
            ((Objinfobar_arg0 *)arg0)->unk14 = 1.0f;
            break;
        case 0x64:
            ((Objinfobar_arg0 *)arg0)->unk14 = 0.0f;
            break;
        case 0x67:
            break;
        }
    }
}    typedef struct { s8 unk0; s8 unk1; s8 unk2; s8 unk3; s16 unk4; s16 unk6; u8 pad8[0x2]; s8 unkA; u8 padB[0x9]; f32 unk14; u8 pad18[0x8]; s32 unk20; s32 unk24; s32 unk28; } Objinfobar_scinfobar_entrypoint_0_ptr; /* offsets.py genstruct: fields from raw offsets on ptr; rename once understood */

void *scinfobar_entrypoint_0(s32 arg0, s32 arg1, s32 arg2) {
    void *heap_alloc(s32);
    void scinfobar_entrypoint_3(void *, s32);
    void scinfobar_entrypoint_10(void *, s32);
    void *ptr;

    ptr = heap_alloc(0x34);
    ((Objinfobar_scinfobar_entrypoint_0_ptr *)ptr)->unk0 = 0x64;
    ((Objinfobar_scinfobar_entrypoint_0_ptr *)ptr)->unk2 = 0;
    ((Objinfobar_scinfobar_entrypoint_0_ptr *)ptr)->unk4 = arg0;
    ((Objinfobar_scinfobar_entrypoint_0_ptr *)ptr)->unk6 = -1;
    ((Objinfobar_scinfobar_entrypoint_0_ptr *)ptr)->unk1 = arg1;
    ((Objinfobar_scinfobar_entrypoint_0_ptr *)ptr)->unk3 = 0;
    ((Objinfobar_scinfobar_entrypoint_0_ptr *)ptr)->unkA = 0;
    ((Objinfobar_scinfobar_entrypoint_0_ptr *)ptr)->unk14 = 0.0f;
    scinfobar_entrypoint_3(ptr, arg2);
    scinfobar_entrypoint_10(ptr, 0xD8);
    ((Objinfobar_scinfobar_entrypoint_0_ptr *)ptr)->unk24 = 0;
    ((Objinfobar_scinfobar_entrypoint_0_ptr *)ptr)->unk28 = 0;
    ((Objinfobar_scinfobar_entrypoint_0_ptr *)ptr)->unk20 = 0;
    func_808000B0_scinfobar(ptr);
    func_80800000_scinfobar(ptr, arg0);
    return ptr;
}

/* extern */

void scinfobar_entrypoint_1(void *arg0, s32 temp_a1) {
    BT_IDO_ONLY(void func_800E8C08();) BT_NATIVE_ONLY(void func_800E8C08(u8);)
    void heap_free(void *memory);

    temp_a1 = (((Objinfobar_arg0 *)arg0)->unk32);
    if (temp_a1 != 0) {
        BT_IDO_ONLY(func_800E8C08(temp_a1 & 0xFF, temp_a1, arg0);) BT_NATIVE_ONLY(func_800E8C08((u8)temp_a1);)
    }
    heap_free(arg0);
}

void scinfobar_entrypoint_2(u8 *arg0) {
    f32 func_800D8FF8(void);
    void func_80800144_scinfobar(u8 *, s32);
    f32 delta;

    delta = func_800D8FF8();
    switch (*arg0) {
        case 0x64:
        case 0x66:
            break;
        case 0x65:
            *(f32 *)(arg0 + 0x14) += delta * *(f32 *)(arg0 + 0x18);
            if (*(f32 *)(arg0 + 0x14) > 1.0f) {
                func_80800144_scinfobar(arg0, 0x66);
            }
            break;
        case 0x67:
            *(f32 *)(arg0 + 0x14) -= delta * *(f32 *)(arg0 + 0x18);
            if (*(f32 *)(arg0 + 0x14) < 0.0f) {
                func_80800144_scinfobar(arg0, 0x64);
            }
            break;
    }
    arg0[0xA] = 0;
}

void scinfobar_entrypoint_3(void *arg0, s32 arg1) {

    extern InfobarStyle D_80800D54_scinfobar[9];
    if (((Objinfobar_arg0 *)arg0)->unk2 != 0) {
        ((Objinfobar_arg0 *)arg0)->unk30 = arg1;
        return;
    }
    ((Objinfobar_arg0 *)arg0)->unk1C = arg1;
    ((Objinfobar_arg0 *)arg0)->unkC = D_80800D54_scinfobar[arg1].scale;
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

    if ((((Objinfobar_arg0 *)arg0)->unk2) != 0) {
        return 0;
    }
    if ((arg1 == (((Objinfobar_arg0 *)arg0)->unk4)) || (arg1 == (((Objinfobar_arg0 *)arg0)->unk6))) {
        return 1;
    }
    temp_v0 = (((Objinfobar_arg0 *)arg0)->unk0);
    (((Objinfobar_arg0 *)arg0)->unk6) = arg1;
    if ((temp_v0 == 0x66) || (temp_v0 == 0x65)) {
        (((Objinfobar_arg0 *)arg0)->unk2) = 0x67U;
    } else {
        (((Objinfobar_arg0 *)arg0)->unk2) = 0x65U;
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

void func_80800608_scinfobar(BtIntPtr arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    void _fxdialog_entrypoint_2(f32);
    void _fxdialog_entrypoint_4(BtIntPtr, s32, s32, f32, f32, s32, s32);
    s32 func_800E8C58(u8);
    extern InfobarEntry D_808008B0_scinfobar[99];
    union { struct { s16 temp; InfobarEntry *value; } fields; f64 alignment; } entry;

    if ((arg1 >= 0) && (arg1 < 0x64) && (arg1 != 0)) {
        entry.fields.value = &D_808008B0_scinfobar[arg1];
        entry.fields.temp = entry.fields.value->value.parts.scale;
        if (entry.fields.temp != 0) {
            _fxdialog_entrypoint_2((f32) entry.fields.temp * 0.00390625f);
        }
        arg2 = arg5 != 0 ? func_800E8C58(arg5) : 0;
        _fxdialog_entrypoint_4(
            arg0,
            entry.fields.value->id,
            arg2,
            (f32) entry.fields.value->x,
            (f32) entry.fields.value->y,
            arg4,
            (u32) entry.fields.value->value.parts.flags >> 0xF
        );
    }
}      

/* extern */

void func_808006EC_scinfobar(BtIntPtr arg0, void *arg1, s32 arg2, s32 arg3) {
    void _fxdialog_entrypoint_0(void);
    void _fxdialog_entrypoint_1(s32 arg0, s32 arg1);
    void _fxdialog_entrypoint_2(f32);
    BT_IDO_ONLY(void) BT_NATIVE_ONLY(void *) _fxdialog_entrypoint_3(BtIntPtr arg0, f32 arg1, s32 arg2, s32 arg3);
    _fxdialog_entrypoint_0();
    _fxdialog_entrypoint_1(arg2, arg3);
    _fxdialog_entrypoint_2((*(f32 *)((s8 *)(arg1) + (0xC))));
    _fxdialog_entrypoint_3(arg0, (f32) (*(s16 *)((s8 *)(arg1) + (8))) * (*(f32 *)((s8 *)(arg1) + (0x14))), (*(u8 *)((s8 *)(arg1) + (1))), 0xFF);
}               typedef struct { u8 unk0; u8 unk1; u8 unk2; u8 pad3[0x1]; s16 unk4; s16 unk6; s16 unk8; u8 padA[0x2]; f32 unkC; u8 pad10[0x4]; f32 unk14; u8 pad18[0x4]; s32 unk1C; u8 pad20[0x12]; u8 unk32; } Objinfobar_arg1; /* offsets.py genstruct: fields from raw offsets on arg1; rename once understood */

void scinfobar_entrypoint_24(BtIntPtr arg0, void *arg1, s32 arg2, s32 arg3) {
    extern InfobarStyle D_80800D54_scinfobar[9];
    s32 var_v0;
    s32 temp_v0_2;
    func_808006EC_scinfobar(arg0, arg1, arg2, arg3);
    if ((((Objinfobar_arg1 *)arg1)->unk0) != 0x64) {
        if (D_80800D54_scinfobar[((Objinfobar_arg1 *)arg1)->unk1C].draw != NULL) {
            (D_80800D54_scinfobar[((Objinfobar_arg1 *)arg1)->unk1C].draw)(arg0, arg1, arg2, arg3);
        }
    }
    var_v0 = ((Objinfobar_arg1 *)arg1)->unk2;
    if (var_v0 == 0) {
        goto normal;
    }
    temp_v0_2 = var_v0;
    var_v0 = ((Objinfobar_arg1 *)arg1)->unk0 - var_v0;
    if (var_v0 != 0) {
        goto normal;
    }
    {
        var_v0 = (s32) ((((Objinfobar_arg1 *)arg1)->unk14) * 255.0f);
        if (temp_v0_2 == 0x65) {
            var_v0 = 0xFF - var_v0;
        }
        func_80800608_scinfobar(arg0, (s32) (((Objinfobar_arg1 *)arg1)->unk4), arg2, arg3, var_v0, (s32) (((Objinfobar_arg1 *)arg1)->unk32));
        func_80800608_scinfobar(arg0, (s32) (((Objinfobar_arg1 *)arg1)->unk6), arg2, arg3, 0xFF - var_v0, 0);
        return;
    }
normal:
    {
        func_80800608_scinfobar(arg0, (s32) (((Objinfobar_arg1 *)arg1)->unk4), arg2, arg3, 0xFF, (s32) (((Objinfobar_arg1 *)arg1)->unk32));
    }
}
#include "infobar_data.inc"
