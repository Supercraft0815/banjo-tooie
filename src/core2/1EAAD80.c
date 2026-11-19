#include "core2/1EAAD80.h"
#include "memory.h"
#ifdef BT_NATIVE
// The counters are stored XORed with the code bytes of func_800D1A04 (0x800D1A04..0x800D1AAC);
// natively the code is not MIPS, so they come from this copy of the N64 halfwords.
static const s16 func_800D1A04_code[84] = {
    0x27BD, 0xFFE8, 0xAFBF, 0x0014, 0x0C03, 0x45B1, 0x0000, 0x0000, 0x0002, 0x7080, 0x3C0F, 0x8012,
    0x01EE, 0x7821, 0x85EF, 0xAF52, 0x2401, 0xFFFE, 0x0040, 0x1825, 0x15E1, 0x0003, 0x8FBF, 0x0014,
    0x1000, 0x000B, 0x2402, 0x03E7, 0x3C18, 0x8013, 0x8F18, 0xB250, 0x0003, 0xC840, 0x0003, 0x58C0,
    0x3C0C, 0x800D, 0x018B, 0x6021, 0x0319, 0x4021, 0x8509, 0x0000, 0x858C, 0x1A04, 0x0189, 0x1026,
    0x03E0, 0x0008, 0x27BD, 0x0018, 0x27BD, 0xFFE8, 0xAFBF, 0x0014, 0x0C03, 0x45B1, 0x0000, 0x0000,
    0x3C05, 0x8012, 0x24A5, 0xAF50, 0x0002, 0x7080, 0x00AE, 0x7821, 0x85E3, 0x0002, 0x2401, 0xFFFE,
    0x0040, 0x2025, 0x1061, 0x0006, 0x8FBF, 0x0014, 0x2401, 0xFFFF, 0x1461, 0x0005, 0x0004, 0xC080,
};
#define CODE_800D1A04 func_800D1A04_code
#else
#define CODE_800D1A04 func_800D1A04
#endif

typedef struct { s16 *values; s32 heapSide; } CounterStorage;
extern CounterStorage D_8012B250;
typedef struct { s16 hudItem; s16 maximum; } CounterDefinition; extern CounterDefinition D_8011AF50[21];
BT_IDO_ONLY(extern struct { s16 value; s16 padding; } D_8011AF52[];)

void func_800D1490(void) {
    s32 i;

    for (i = 0; i < 21; i++) {
        D_8012B250.values[i] = ((s16 *)&CODE_800D1A04)[i * 4];
    }
}

/* extern */

void func_800D1510(void) {
    D_8012B250.heapSide = 0;
    D_8012B250.values = heap_alloc_sided(0x2A, D_8012B250.heapSide);
    func_800D1490();
}

void func_800D154C(void) {
    s32 func_8001210C(s32);
    s16 *oldValues;
    void *temp_v0;
    s32 var_a1;

    if (func_8001210C(0x3FF) == 0x1FF) {
        oldValues = D_8012B250.values;
        var_a1 = ++D_8012B250.heapSide;
        if (var_a1 == 3) {
            D_8012B250.heapSide = 0;
            var_a1 = 0;
        }
        temp_v0 = heap_alloc_sided(0x2A, var_a1);
        D_8012B250.values = temp_v0;
        rare_memcpy(temp_v0, oldValues, 0x2A);
        heap_free(oldValues);
    }
}

void func_800D15CC(void) {
    if (D_8012B250.values != NULL) {
        D_8012B250.values = defrag(D_8012B250.values);
    }
}

void func_800D1604(void) {
    heap_free(D_8012B250.values);
    D_8012B250.values = NULL;
}



void func_800D162C(void) {
    void func_800D2770(s32, s32);
    s16 *var_s1;
    s32 var_s0;
    s32 var_s2;

    var_s1 = (s16 *)D_8011AF50; var_s0 = 0; var_s2 = 0; do { func_800D2770(*var_s1, *(s16 *)((s8 *)D_8012B250.values + var_s0) ^ *(s16 *)((s8 *)&CODE_800D1A04 + var_s2)); var_s0 += 2; var_s1 += 2; var_s2 += 8; } while (var_s0 != 0x2A);
}

s32 func_800D16C4(s32 arg0)
{
    return arg0 - 0x40;
}

void func_800D16CC(s32 arg0, s32 arg1) {
    s32 index;
    s16 limit;

    index = arg0 * 4;
    limit = BT_DATA_FIELD(D_8011AF50[arg0].maximum, *(s16 *)((u8 *)D_8011AF52 + index));
    if (limit == -2) {
        D_8012B250.values[arg0] = *(s16 *)((u8 *)&CODE_800D1A04 + index * 2) ^ 0x3E7;
        return;
    }
    if (arg1 < 0) {
        arg1 = 0;
    }
    if ((limit >= 0) && (limit < arg1)) {
        arg1 = limit;
    }
    D_8012B250.values[arg0] = *(s16 *)((u8 *)&CODE_800D1A04 + index * 2) ^ arg1;
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800D175C(s32 arg0, s32 arg1) {
    void func_800D16CC(s32, s32);
    s32 func_800D24E8(s32, s32, u32);
    register s32 index;

    index = func_800D16C4(arg0);
    func_800D16CC(index, (D_8012B250.values[index] ^ ((s16 *)&CODE_800D1A04)[index * 4]) + arg1);
    BT_NATIVE_ONLY(return) func_800D24E8(D_8011AF50[index].hudItem, D_8012B250.values[index] ^ ((s16 *)&CODE_800D1A04)[index * 4], 0);
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800D1804(s32 arg0) {
    func_800D175C(arg0, -1); BT_NATIVE_ONLY(return 0;)
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800D1824(s32 arg0)
{
    func_800D175C(arg0,0); BT_NATIVE_ONLY(return 0;)
}

void func_800D1844(s32 arg0)
{
    func_800D175C(arg0,1);
}

void func_800D1864(u32 arg0, u32 arg1, u32 arg2) {
    void func_800D16CC(s32, s32);
    s32 func_800D2498(u32, s32, u32);
    void func_800D2770(s32, s32);
    s32 index;

    index = func_800D16C4(arg0);
    func_800D16CC(index, arg1);
    if (arg2 != 0) {
        func_800D2498(D_8011AF50[index].hudItem, D_8012B250.values[index] ^ ((s16 *)&CODE_800D1A04)[index * 4], D_8011AF50[index].maximum);
    } else {
        func_800D2770(D_8011AF50[index].hudItem, D_8012B250.values[index] ^ ((s16 *)&CODE_800D1A04)[index * 4]);
    }
}

void func_800D192C(s32 arg0, u32 arg1) {
    func_800D1864((u32) arg0, func_800D1A04(arg0), arg1);
}

void func_800D1960(s32 arg0, s32 arg1, s32 arg2) {
    void func_800D16CC(s32, s32);
    s32 index;
    u32 value;

    index = func_800D16C4(arg0);
    if (arg1 <= 0 && arg1 != -2) {
        arg1 = 1;
    }
    D_8011AF50[index].maximum = arg1;
    if (arg2 != 0) {
        value = func_800D1A6C(arg0);
    } else {
        value = D_8012B250.values[index] ^ ((s16 *)&CODE_800D1A04)[index * 4];
    }
    func_800D16CC(index, value);
}

s32 func_800D1A04(s32 a0) {
    s32 index;

    index = func_800D16C4(a0);
    if (BT_DATA_FIELD(D_8011AF50[index].maximum, D_8011AF52[index].value) == -2) {
        return 0x3E7;
    }
    return D_8012B250.values[index] ^ ((s16 *)&CODE_800D1A04)[index * 4];
}

u32 func_800D1A6C(u32 arg0) {
    s16 temp_v1;
    s32 temp_v0;

    temp_v0 = func_800D16C4((s32) arg0);
    temp_v1 = D_8011AF50[temp_v0].maximum;
    if (temp_v1 != -2) {
        if (temp_v1 == -1) {
            return 0x32U;
        }
    } else {
        return 0x3E7U;
    }
    return D_8011AF50[temp_v0].maximum;
}

s32 func_800D1ACC(s32 arg0) {
    switch (arg0) {
    case 0x40:
        return 100;
    case 0x41:
        return 50;
    case 0x42:
        return 50;
    case 0x43:
        return 25;
    case 0x44:
        return 10;
    case 0x46:
        return 100;
    case 0x47:
        return 10;
    default:
        break;
    }
    return 0;
}

s32 func_800D1B34(s32 arg0) {
    switch (arg0) {
    case 0x29F:
        return 0x48;
    case 0x523:
        return 0x54;
    case 0x1D9:
        return 0x4F;
    case 0x3CA:
        return 0x4B;
    case 0x3CB:
        return 0x4C;
    case 0x40D:
    case 0x481:
        return 0x50;
    case 0x4E2:
        return 0x4D;
    case 0x4E3:
        return 0x4A;
    case 0x4E4:
        return 0x4E;
    case 0x4BA:
    case 0x4D7:
        return 0x51;
    case 0x515:
    case 0x516:
        return 0x52;
    case 0x4B7:
        return 0x49;
    default:
        return 0;
    }
}

s32 func_800D1C38(s32 arg0) {
    return func_800D1A04(arg0) == 0;
}

s32 func_800D1C5C(u32 arg0) {
    BT_IDO_ONLY(extern s16 D_8011AE50[];)
    return BT_DATA_FIELD(D_8011AF50[arg0 - 0x40].hudItem, *(s16 *)((u8 *)D_8011AE50 + (arg0 << 2)));
}

s32 func_800D1C70() 
{
    return 0x2A;
}

void func_800D1C78(u8 *arg0, u32 arg1) {
    s32 i;
    s32 value;
    s32 count;

    func_800D1490();
    count = arg1 >> 1;
    if (count >= 0x16) {
        count = 0x15;
    }
    for (i = 0; i < count; i++) {
        value = (arg0[i * 2] << 8) | arg0[i * 2 + 1];
        D_8012B250.values[i] = ((s16 *)&CODE_800D1A04)[i * 4] ^ value;
    }
}

void func_800D1DFC(u8 *arg0) {
    s32 i;

    for (i = 0; i < 0x15; i++) {
        arg0[i * 2] = ((D_8012B250.values[i] ^ ((s16 *)&CODE_800D1A04)[i * 4]) >> 8) & 0xFF;
        arg0[i * 2 + 1] = (D_8012B250.values[i] ^ ((s16 *)&CODE_800D1A04)[i * 4]) & 0xFF;
    }
}

/* extern */

s32 func_800D1F34(u8 *arg0, register s32 arg1) {
    extern s32 _glgamedata_entrypoint_3(u8 *, s32, s32 *, u32 *);
    s32 sp24;
    u32 sp20;
    u8 *temp_v1;
    u32 result;

    if (_glgamedata_entrypoint_3(arg0, 4, &sp24, &sp20) != 0) {
        arg1 -= 0x40;
        if ((s32) (sp20 >> 1) < arg1) {
            return -1;
        }
        temp_v1 = arg0 + sp24 + (arg1 * 2);
        result = (temp_v1[0] << 8) | temp_v1[1];
        return result;
    }
    return -1;
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
CounterStorage D_8012B250 BT_DATA(4, bss_core2bss1_1_counter_tail, 0xD0);
#endif

CounterDefinition D_8011AF50[21] = {
    {0xD1, 100},
    {0xD2, 50},
    {0xD3, 50},
    {0xD4, 25},
    {0xD5, 10},
    {0x11A, 0},
    {0xD7, 100},
    {0xD8, 10},
    {0xD9, 16},
    {0xDA, 25},
    {0xDB, 25},
    {0xDC, 5},
    {0xDD, 5},
    {0xDE, 4},
    {0xDF, 30},
    {0xE0, 1},
    {0xED, 2},
    {0x108, 1},
    {0x109, 2},
    {0x10C, 1},
    {0x10D, 1},
};
