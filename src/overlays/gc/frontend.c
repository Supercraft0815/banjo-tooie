#include "common.h"
#include "core2/1EB3750.h"

typedef struct { u16 opcode; s16 value; } GCFrontendCommand;

typedef struct {
    s32 count;
    GCFrontendCommand *commands;
} GCFrontendScript;

typedef struct {
    s16 map;
    s16 exit;
    GCFrontendScript script;
    u8 state;
    u8 control;
    u8 padding[2];
} GCFrontendScene;

typedef struct {
    u8 start;
    u8 count;
    s16 firstFlag;
    GCFrontendScene *scenes;
    s16 *lookup;
} GCFrontendRange;
extern GCFrontendScript D_808008FC_gcfrontend[4];
extern GCFrontendScene D_80800C9C_gcfrontend[7];
extern GCFrontendRange D_80800D80_gcfrontend[4];
extern s16 D_80800DB0_gcfrontend[16][4];

void gcfrontend_entrypoint_0(void) {
    void func_800D3970(void);
    u8 gcfrontend_entrypoint_4(s32);
    u8 gcfrontend_entrypoint_5(s32);
    void gcfrontend_entrypoint_9(s32);
    s32 sp28[2];
    s32 temp_v0;
    s32 var_s0;
    s32 var_s1;

    func_800D3970();
    sp28[0] = gcfrontend_entrypoint_5(3);
    temp_v0 = gcfrontend_entrypoint_4(3);
    var_s0 = 0;
    if (temp_v0 > 0) {
        var_s1 = sp28[0];
        do {
            gcfrontend_entrypoint_9(var_s1);
            var_s0 += 1;
            var_s1 += 1;
        } while (var_s0 < temp_v0);
    }
}

s32 gcfrontend_entrypoint_1(s32 arg0) {
    s32 var_s0;
    s32 temp_s1;
    GCFrontendRange *temp_v0;

    temp_v0 = &D_80800D80_gcfrontend[arg0];
    var_s0 = temp_v0->firstFlag;
    temp_s1 = temp_v0->count + var_s0;
    if (var_s0 < temp_s1) {
loop_1:
        if (func_800DA298(var_s0) != 0) {
            return 1;
        }
        var_s0 += 1;
        if (var_s0 >= temp_s1) {
            goto block_4;
        }
        goto loop_1;
    }
block_4:
    return 0;
}

int gcfrontend_entrypoint_2(void) {
    s32 gcfrontend_entrypoint_1(s32);
    return gcfrontend_entrypoint_1(0) || gcfrontend_entrypoint_1(1) || gcfrontend_entrypoint_1(2);
}

s32 gcfrontend_entrypoint_3(s32 arg0) {
    s32 func_80800450_gcfrontend();
    GCFrontendRange *temp_v1;

    temp_v1 = &D_80800D80_gcfrontend[func_80800450_gcfrontend()];
    return func_800DA298((temp_v1->firstFlag + arg0) - temp_v1->start);
}

u8 gcfrontend_entrypoint_4(s32 arg0) {
    return D_80800D80_gcfrontend[arg0].count;
}

u8 gcfrontend_entrypoint_5(s32 arg0) {
    return D_80800D80_gcfrontend[arg0].start;
}

u8 gcfrontend_entrypoint_6(s32 arg0) {
    s32 func_80800450_gcfrontend();
    GCFrontendRange *temp_v1;

    temp_v1 = &D_80800D80_gcfrontend[func_80800450_gcfrontend()];
    return temp_v1->scenes[arg0 - temp_v1->start].state;
}

void gcfrontend_entrypoint_7(s32 arg0, s32 arg1) {
    void func_800D3CF8(s32);
    void func_800D3D10(s32);
    s32 func_80800450_gcfrontend(s32);
    void func_80800738_gcfrontend(void *, BtIntPtr, s32, s32);
    s32 result;
    s32 mode;
    s32 rangeIndex;
    BT_IDO_ONLY(extern GCFrontendRange D_80800DA4_gcfrontend;)
    BtIntPtr secondary;
    GCFrontendScene *base;
    GCFrontendRange *range;
    GCFrontendScene *volatile entry;

    result = func_80800450_gcfrontend(arg0);
    if (result < 4) {
        secondary = 0;
        rangeIndex = result;
        func_800D3CF8(arg0);
        range = &D_80800D80_gcfrontend[rangeIndex];
        mode = 2;
        base = range->scenes;
        arg0 -= range->start;
        if (rangeIndex != 2) {
            secondary = (BtIntPtr)&base[arg0].script;
        }
        entry = &base[arg0]; if (range == BT_DATA_FIELD(&D_80800D80_gcfrontend[3], &D_80800DA4_gcfrontend)) {
            mode = 3;
        }
        func_800D3D10(arg1);
        func_80800738_gcfrontend(entry, secondary, 0, mode);
    }
}

s32 func_808002DC_gcfrontend(s32 arg0, s32 arg1) {
    void func_80800738_gcfrontend(void *, BtIntPtr, s32, s32);
    GCFrontendScene *temp_v0;

    temp_v0 = &D_80800C9C_gcfrontend[arg0 - 0xA0];
    func_80800738_gcfrontend(temp_v0, (BtIntPtr)&temp_v0->script, temp_v0->control, arg1); BT_NATIVE_ONLY(return 0;)
}

void gcfrontend_entrypoint_8(s32 arg0, s32 arg1) {
    s32 func_808002DC_gcfrontend(s32, s32);
    s32 var_a1;

    if (arg1 != 0) {
        var_a1 = 1;
    } else {
        var_a1 = 0;
    }
    func_808002DC_gcfrontend(arg0, var_a1);
}

void gcfrontend_entrypoint_9(s32 arg0) {
    s32 func_80800450_gcfrontend();
    GCFrontendRange *temp_v1;

    temp_v1 = &D_80800D80_gcfrontend[func_80800450_gcfrontend()];
    func_800DA544((temp_v1->firstFlag + arg0) - temp_v1->start);
}

void gcfrontend_entrypoint_10(void) {
    void func_800D3CF8(s32);
    s32 func_808002DC_gcfrontend(s32, s32);
    func_800D3CF8(0);
    func_808002DC_gcfrontend(0xA0, -1);
}

void gcfrontend_entrypoint_11(void) {
    void gcfrontend_entrypoint_7(s32, s32);
    u32 func_800D3D04(void);
    gcfrontend_entrypoint_7(func_800D3D04(), 0);
}

void gcfrontend_entrypoint_12(void) {
    void func_800AA00C(void);
    void func_800AA074(void);
    func_800AA074();
    func_800AA00C();
    gcfrontend_entrypoint_10();
}

void gcfrontend_entrypoint_13(void) {
    void func_800D37D4(void);
    s32 func_808002DC_gcfrontend(s32, s32);
    func_800D37D4();
    func_808002DC_gcfrontend(0xA6, -1);
}

s32 func_80800450_gcfrontend(s32 arg0) {
    int i;
    int end;
    int start;
    for (i = 0; i < 4; i++) {
        end = D_80800D80_gcfrontend[i].start + D_80800D80_gcfrontend[i].count;
        start = D_80800D80_gcfrontend[i].start;
        if (arg0 >= start && arg0 < end) {
            return i;
        }
    }
    return 4;
}

void func_80800520_gcfrontend(GCFrontendScript *arg0) {
    void func_800D3A14(s32);
    void func_800D3A20(s32);
    void func_800D3A54(s32, s32);
    void func_800D3A88(void);
    void func_800D3AF0(s32);
    int func_800DC298(f32);
    s16 value;
    BtIntPtr offset;
    GCFrontendCommand *entry;
    int count;
    int end;

    count = arg0->count;
    offset = 0;
    if (count > 0) {
      do {
        entry = (GCFrontendCommand *)((u8 *)arg0->commands + offset);
        value = entry->value;
        switch (entry->opcode) {
            case 0:
                func_800D3A54(value, 1);
                count = arg0->count;
                end = count * (s32)sizeof(*entry);
                break;
            case 1:
                func_800D3A88();
                count = arg0->count;
                end = count * (s32)sizeof(*entry);
                break;
            case 2:
                func_800D3AF0(value);
                count = arg0->count;
                end = count * (s32)sizeof(*entry);
                break;
            case 3:
                func_800D3A14(value);
                count = arg0->count;
                end = count * (s32)sizeof(*entry);
                break;
            case 4:
                func_800D3A20(value);
                count = arg0->count;
                end = count * (s32)sizeof(*entry);
                break;
            case 5:
                func_80800520_gcfrontend(&D_808008FC_gcfrontend[value]);
                count = arg0->count;
                end = count * (s32)sizeof(*entry);
                break;
            case 6:
                func_800D3A54(value, 0);
                count = arg0->count;
                end = count * (s32)sizeof(*entry);
                break;
            case 7:
                if (func_800DC298(0.5f)) {
                    func_800D3A20(value);
                } else {
                    func_800D3A20(value + 1);
                }
                count = arg0->count;
                end = count * (s32)sizeof(*entry);
                break;
            default:
                end = count * (s32)sizeof(*entry);
                break;
        }
        offset += sizeof(*entry);
      } while (offset < end);
    }
}

void func_8080068C_gcfrontend(s32 *arg0, s32 *arg1) {
    void func_800D3A20(s32);
    u32 func_800D3D04(void);
    u32 func_800D3D1C(void);
    s16 (*entry)[4];
    s16 (*end)[4];
    u32 current;
    s16 value;

    if (func_800D3D1C() == 0) {
        current = func_800D3D04();
        entry = D_80800DB0_gcfrontend; end = D_80800DB0_gcfrontend + 16;
        do {
            if (current == (*entry)[0]) {
                func_800D3A20((*entry)[1]);
                value = (*entry)[2];
                if (value != 0) {
                    *arg0 = value;
                }
                value = (*entry)[3];
                if (value != 0) {
                    *arg1 = value;
                }
            }
            entry++;
        } while (entry != end);
    }
}

/* extern */

void func_80800738_gcfrontend(void *arg0, BtIntPtr arg1, s32 arg2, s32 arg3) {
    void func_800A791C(s32 arg0, s32 arg1, s32 arg2);
    void func_800D39A8(void);
    void func_800D39DC(s32 arg0);
    void func_800D3B24(void);
    void func_800EA334(s32 arg0);
    void func_80800520_gcfrontend(GCFrontendScript *);
    void func_8080068C_gcfrontend(s32 *, s32 *);
    s32 sp1C;
    s32 sp18;

    sp1C = (s32) ((GCFrontendScene *)arg0)->exit;
    sp18 = (s32) ((GCFrontendScene *)arg0)->map;
    func_800D39A8();
    func_800D39DC(arg3);
    if (arg1 != 0) {
        func_800D3B24();
        func_80800520_gcfrontend((GCFrontendScript *)arg1);
        func_8080068C_gcfrontend(&sp18, &sp1C);
    }
    if (arg2 == 0) {
        func_800EA334(0);
    }
    func_800A791C(sp18, sp1C, 1);
} 

s16 gcfrontend_entrypoint_14(s32 arg0) {
    s32 func_80800450_gcfrontend();
    GCFrontendRange *temp_v1;
#ifdef BT_NATIVE
    temp_v1 = &D_80800D80_gcfrontend[((s32 (*)())func_80800450_gcfrontend)()];
#else
    temp_v1 = &D_80800D80_gcfrontend[func_80800450_gcfrontend()];
#endif
    return temp_v1->lookup[arg0 - temp_v1->start];
}
#include "frontend_data.inc"
