#include "common.h"

extern s32 D_8012AE80;

BtIntPtr func_800CB890(s16 *arg0) {
    extern u8 *D_8012AF60;
    void *func_800B42A0(u8 *data, s16 *range);
    return func_800B42A0(D_8012AF60, arg0 + 12);
}

BtIntPtr func_800CB8BC(s16 *arg0) {
    return arg0[13] * 0x18 + func_800CB890(arg0);
}

BtIntPtr func_800CB8F0(s16 *arg0)
{
    return func_800CB890(arg0);
}

BtIntPtr func_800CB910(s16 *arg0) {
    return ((*(u32 *)arg0 >> 9) * 0x18) + func_800CB8F0(arg0);
}

void *func_800CB948(s16 *arg0)
{
    BT_NATIVE_ONLY(return) func_800CB910(arg0);
}

BtIntPtr func_800CB968(s16 *arg0)
{
    return func_800CB8BC(arg0);
}

void func_800CB988()
{
    _gcboundDll_entrypoint_0(&D_8012AE80);
}

void func_800CB9AC(void) {
}

void func_800CB9B4()
{
    _gcboundDll_entrypoint_1(&D_8012AE80);
}

void func_800CB9D8()
{
    _gcboundDll_entrypoint_2(&D_8012AE80);
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800CB9FC()
{
    BT_NATIVE_ONLY(return) _gcboundDll_entrypoint_6(&D_8012AE80);
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800CBA20()
{
    BT_NATIVE_ONLY(return) _gcboundDll_entrypoint_7(&D_8012AE80);
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800CBA44()
{
    BT_NATIVE_ONLY(return) _gcboundDll_entrypoint_8(&D_8012AE80);
}

/* extern */

void func_800CBA68(s32 arg0, BtIntPtr arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    void _gcboundDll_entrypoint_3(u8 *arg0, s32 arg1, s16 *arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7);
    _gcboundDll_entrypoint_3(&D_8012AE80, arg0, arg1, arg2, arg3, arg4, arg5, arg6);
}

/* extern */

void func_800CBAC8(s32 arg0, BtIntPtr arg1, s32 arg2, s32 arg3, s32 arg4) {
    void _gcboundDll_entrypoint_4(u8 *arg0, s32 arg1, s16 *arg2, s32 arg3, s32 arg4, s32 arg5);
    _gcboundDll_entrypoint_4(&D_8012AE80, arg0, arg1, arg2, arg3, arg4);
}

/* extern */

void func_800CBB18(s32 arg0, BtIntPtr arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    void _gcboundDll_entrypoint_5(u8 *arg0, s32 arg1, s16 *arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
    _gcboundDll_entrypoint_5(&D_8012AE80, arg0, arg1, arg2, arg3, arg4, arg5);
}

void func_800CBB70(s32 arg0, s32 arg1) {
    extern s32 D_8012AE98;
    *(s8 *)((u8 *)&D_8012AE98 + arg0) = arg1;
}

void func_800CBB80(s32 arg0, s32 arg1) {
    extern s32 D_8012AE8C;
    struct Entry {
        u16 prefix;
        u8 other : 7;
        u8 flag : 1;
        u8 rest[25];
    } *entry;

    entry = (struct Entry *)(D_8012AE8C + arg0 * 0x1C);
    if (arg1 != 0) {
        entry->flag = 1;
        return;
    }
    entry->flag = 0;
}

s32 func_800CBBC0(s32 arg0) {
    extern s32 D_8012AE8C;
    s32 *entry;
    entry = (s32 *)(D_8012AE8C + arg0 * 0x1C);
    return entry[5];
}

s32 func_800CBBE0(s32 arg0) {
    extern s32 D_8012AE94;
    s32 *entry;
    entry = (s32 *)(D_8012AE94 + arg0 * 0x1C);
    return entry[5];
}

s32 func_800CBC00(s32 arg0) {
    extern s32 D_8012AE94;
    return (*(u16 *)((s8 *)(func_800CB8F0((arg0 * 0x1C) + D_8012AE94)) + (0x14))) & 1;
}

s32 func_800CBC3C(void *arg0) {
    f32 func_800EFC7C(void *, void *);
    struct Entry { s32 words[7]; };
    struct Table { s32 count; struct Entry *entries; };
    f32 y, radius, positionY;
    BtUIntPtr end, item;
    struct Entry *entry;

    for (entry = ((struct Table *)&D_8012AE80)->entries;
         entry < ((struct Table *)&D_8012AE80)->count + ((struct Table *)&D_8012AE80)->entries;
         entry++) {
        end = func_800CB910((s16 *)entry);
        for (item = func_800CB8F0((s16 *)entry); item < end; item += 0x18) {
            y = *(f32 *)(item + 4);
            radius = *(s16 *)(item + 0xE);
            positionY = ((f32 *)arg0)[1];
            if (y - radius < positionY && positionY < y + radius &&
                func_800EFC7C((void *)item, arg0) < *(f32 *)(item + 0x10)) {
                return entry - ((struct Table *)&D_8012AE80)->entries;
            }
        }
    }
    return -1;
}

/* extern */

s32 func_800CBD84(f32 *arg0) {
    s32 func_800CBC3C();
    s32 func_800CC4D4(f32 *, BtIntPtr);
    s32 sp1C;
    s32 var_a1;

#ifdef BT_NATIVE
    var_a1 = ((s32 (*)())func_800CBC3C)();
#else
    var_a1 = func_800CBC3C();
#endif
    if (var_a1 != -1) {
        if (func_800CC4D4(arg0, (sp1C = var_a1)) != -1) {
            return -1;
        }
        var_a1 = sp1C;
    }
    return var_a1;
}

s32 func_800CBDD4(BtIntPtr positionAddress, s32 arg1, s32 arg2) {
    f32 func_800EFC7C(void *, void *);
    struct Entry {
        s16 index;
        u8 flags;
        u8 pad;
        f32 position[3];
        f32 radius;
        s32 enabledIndex;
        s32 tail;
    };
    struct Item {
        f32 position[3];
        s16 pad;
        s16 extent;
        f32 radius;
        u32 unused : 12;
        u32 flags : 3;
        u32 rest : 17;
    };
    struct Table {
        s32 pad[2];
        s32 count;
        struct Entry *entries;
        s32 tail[2];
        u8 enabled[1];
    };
    f32 *arg0 = (f32 *)positionAddress;
    f32 half, upper, lower;
    f32 y, positionY, extent;
    struct Item *item, *end;
    struct Entry *entry;

    half = arg1 * 0.5f;
    upper = arg0[1] + half;
    lower = arg0[1] - half;
    for (entry = ((struct Table *)&D_8012AE80)->entries;
         entry < ((struct Table *)&D_8012AE80)->count + ((struct Table *)&D_8012AE80)->entries;
         entry++) {
        if (!(entry->flags & 1)) {
            continue;
        }
            if (func_800EFC7C(entry->position, arg0) < entry->radius) {
                end = (struct Item *)func_800CB910((s16 *)entry);
                if (!((struct Table *)&D_8012AE80)->enabled[entry->enabledIndex]) {
                    continue;
                }
                if (arg2 & 1) {
                    for (item = (struct Item *)func_800CB8F0((s16 *)entry); item < end; item++) {
                        if (item->flags & arg2) {
                            y = item->position[1];
                            if (y <= upper && lower < y &&
                                func_800EFC7C(item, arg0) < item->radius) {
                                return entry - ((struct Table *)&D_8012AE80)->entries;
                            }
                        }
                    }
                } else {
                    for (item = (struct Item *)func_800CB8F0((s16 *)entry); item < end; item++) {
                        if ((item->flags & arg2) &&
                            ((item->flags & 2) ||
                             (y = item->position[1], positionY = arg0[1], extent = item->extent,
                              y - extent <= positionY && positionY < y + extent)) &&
                            func_800EFC7C(item, arg0) < item->radius) {
                            return entry - ((struct Table *)&D_8012AE80)->entries;
                        }
                    }
                }
            }
    }
    return -1;
}

s32 func_800CC078(BtIntPtr positionAddress) {
    f32 func_800EFC7C(void *, void *);
    struct Entry {
        s16 index;
        u8 flags;
        u8 pad;
        f32 position[3];
        f32 radius;
        s32 enabledIndex;
        s32 tail;
    };
    struct Item {
        f32 position[3];
        s16 pad;
        s16 extent;
        f32 radius;
        u32 unused : 12;
        u32 flags : 3;
        u32 rest : 17;
    };
    struct Table {
        s32 pad[4];
        s32 count;
        struct Entry *entries;
    };
    struct Entry *entry;
    struct Item *item;
    struct Item *end;
    f32 y, extent, positionY;
    f32 *arg0 = (f32 *)positionAddress;

    for (entry = ((struct Table *)&D_8012AE80)->entries;
         entry < ((struct Table *)&D_8012AE80)->count + ((struct Table *)&D_8012AE80)->entries;
         entry++) {
        if (func_800EFC7C(entry->position, arg0) < entry->radius) {
            end = (struct Item *)func_800CB910((s16 *)entry);
            for (item = (struct Item *)func_800CB8F0((s16 *)entry); item < end; item++) {
                switch (item->flags) {
                    case 0:
                        if (func_800EFC7C(item, arg0) < item->radius) {
                            return entry - ((struct Table *)&D_8012AE80)->entries;
                        }
                        break;
                    case 1:
                        y = item->position[1];
                        extent = item->extent;
                        positionY = arg0[1];
                        if (y - extent < positionY && positionY < y + extent &&
                            func_800EFC7C(item, arg0) < item->radius) {
                            return entry - ((struct Table *)&D_8012AE80)->entries;
                        }
                        break;
                    case 2:
                        if (item->position[1] - item->extent < arg0[1] &&
                            func_800EFC7C(item, arg0) < item->radius) {
                            return entry - ((struct Table *)&D_8012AE80)->entries;
                        }
                        break;
                    case 3:
                        if (arg0[1] < item->position[1] + item->extent &&
                            func_800EFC7C(item, arg0) < item->radius) {
                            return entry - ((struct Table *)&D_8012AE80)->entries;
                        }
                        break;
                }
            }
        }
    }
    return -1;
}

s32 func_800CC338(f32 *arg0, s32 arg1, s32 arg2) {
    s32 func_800CC4D4(f32 *, BtIntPtr);
    f32 func_800EFC7C(void *, void *);
    extern s32 D_8012AE84;
    s32 pad[2];
    s8 *start;
    f32 y;
    f32 center;
    f32 extent;
    s16 *region;
    s8 *cur;
    BtUIntPtr end;

    region = (s16 *)(arg1 * 0x1C + D_8012AE84);
    if (func_800CC4D4(arg0, arg1) != -1) {
        return -1;
    }
    start = (s8 *)func_800CB8F0(region);
    y = arg0[1];
    cur = start + arg2 * 0x18;
    center = *(f32 *)(cur + 4);
    extent = *(s16 *)(cur + 0xE);
    if (center - extent < y && y < center + extent &&
        func_800EFC7C(cur, arg0) < *(f32 *)(cur + 0x10)) {
        return arg2;
    }
    end = func_800CB910(region);
    for (cur = start; (BtUIntPtr)cur < end; cur += 0x18) {
        center = *(f32 *)(cur + 4);
        y = arg0[1];
        extent = *(s16 *)(cur + 0xE);
        if (center - extent < y && y < center + extent &&
            func_800EFC7C(cur, arg0) < *(f32 *)(cur + 0x10)) {
            return (cur - start) / 24;
        }
    }
    return -1;
}

s32 func_800CC4D4(f32 *arg0, BtIntPtr arg1) {
    extern s32 D_8012AE84;
    f32 func_800EFC7C(void *, void *);
    s32 pad[3];
    s8 *start;
    f32 center;
    f32 y;
    f32 extent;
    s8 *cur;

    cur = (s8 *)(D_8012AE84 + arg1 * 0x1C);
    if (*(u8 *)(cur + 3) == 0) {
        return -1;
    }
    start = func_800CB948((s16 *)cur);
    arg1 = func_800CB968((s16 *)cur);
    for (cur = start; (BtUIntPtr)cur < (u32)arg1; cur += 0x18) {
        center = *(f32 *)(cur + 4);
        extent = *(s16 *)(cur + 0xE);
        y = arg0[1];
        if (center - extent < y && y < center + extent &&
            func_800EFC7C(cur, arg0) < *(f32 *)(cur + 0x10)) {
            return (cur - start) / 24;
        }
    }
    return -1;
}

s32 func_800CC5E8()
{
    return D_8012AE80;
}

u32 func_800CC5F4(s32 arg0) { extern s32 D_8012AE84; return (u32)*(u32 *)(D_8012AE84 + arg0 * 0x1C) >> 9; }

u8 func_800CC61C(s32 arg0) {
    extern s32 D_8012AE84;
    return (*(u8 *)((s8 *)(((arg0 * 0x1C) + D_8012AE84)) + (3)));
}

void *func_800CC63C(s32 arg0, s32 arg1)
{
    extern s32 D_8012AE84;
    return (s8 *)func_800CB8F0((arg0 * 0x1C) + D_8012AE84) + (arg1 * 0x18);
}

void *func_800CC684(s32 arg0, s32 arg1)
{
    extern s32 D_8012AE84;
    return (s8 *)func_800CB948((arg0 * 0x1C) + D_8012AE84) + (arg1 * 0x18);
}

/* extern */

s32 func_800CC6CC(BT_PARAM_OR_VOID(s32 bt_a0) BT_PASS2(, s32 bt_a1)) {
    void *func_800CC63C();
#ifdef BT_NATIVE
    return (*(u16 *)((s8 *)(((void * (*)(s32, s32))func_800CC63C)(bt_a0, bt_a1)) + (0x14))) & 1;
#else
    return (*(u16 *)((s8 *)(func_800CC63C()) + (0x14))) & 1;
#endif
}

s32 func_800CC6F4(BtIntPtr arg0, s32 arg1, s32 arg2) {
    typedef struct {
        f32 position[3];
        s16 unkC;
        s16 height;
        f32 radius;
        u32 unk14 : 12;
        u32 type : 3;
        u32 unk14_15 : 17;
    } Region;
    extern s32 D_8012AE94;
    f32 func_800EFC7C(void *, void *);
    s16 *group;
    Region *cur;
    Region *base;
    Region *end;

    group = (s16 *)(arg1 * 0x1C + D_8012AE94);
    base = (Region *)func_800CB8F0(group);
    cur = base + arg2;
    switch (cur->type) {
        case 0:
            if (func_800EFC7C(cur->position, (void *)arg0) < cur->radius) {
                return arg2;
            }
            break;
        case 1:
            if (cur->position[1] - cur->height < ((f32 *)arg0)[1] &&
                ((f32 *)arg0)[1] < cur->position[1] + cur->height &&
                func_800EFC7C(cur->position, (void *)arg0) < cur->radius) {
                return arg2;
            }
            break;
        case 2:
            if (cur->position[1] - cur->height < ((f32 *)arg0)[1] &&
                func_800EFC7C(cur->position, (void *)arg0) < cur->radius) {
                return arg2;
            }
            break;
        case 3:
            if (((f32 *)arg0)[1] < cur->position[1] + cur->height &&
                func_800EFC7C(cur->position, (void *)arg0) < cur->radius) {
                return arg2;
            }
            break;
    }

    end = (Region *)func_800CB910(group);
    for (cur = base; cur < end; cur++) {
        switch (cur->type) {
            case 0:
                if (func_800EFC7C(cur->position, (void *)arg0) < cur->radius) {
                    return cur - base;
                }
                break;
            case 1:
                if (cur->position[1] - cur->height < ((f32 *)arg0)[1] &&
                    ((f32 *)arg0)[1] < cur->position[1] + cur->height &&
                    func_800EFC7C(cur->position, (void *)arg0) < cur->radius) {
                    return cur - base;
                }
                break;
            case 2:
                if (cur->position[1] - cur->height < ((f32 *)arg0)[1] &&
                    func_800EFC7C(cur->position, (void *)arg0) < cur->radius) {
                    return cur - base;
                }
                break;
            case 3:
                if (((f32 *)arg0)[1] < cur->position[1] + cur->height &&
                    func_800EFC7C(cur->position, (void *)arg0) < cur->radius) {
                    return cur - base;
                }
                break;
        }
    }
    return -1;
}

s32 func_800CCAB0(BtIntPtr arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    typedef struct {
        f32 position[3];
        s16 unkC;
        s16 height;
        f32 radius_squared;
        u32 unk14 : 12;
        u32 flags : 3;
        u32 unk16 : 17;
    } Entry;
    typedef struct {
        s32 pad0[3];
        u8 *regions;
        s32 pad10[2];
        u8 active[1];
    } State;
    f32 func_800EFC7C(void *, void *);
    f32 upper;
    f32 lower;
    Entry *start;
    Entry *end;
    Entry *entry;
    u8 *region;

    region = (u8 *)(arg1 * 0x1C + (BtIntPtr)((State *)&D_8012AE80)->regions);
    if (!(region[2] & 1)) {
        return -1;
    }
    if (!((State *)&D_8012AE80)->active[*(s32 *)(region + 0x14)]) {
        return -1;
    }
    start = (Entry *)func_800CB8F0((s16 *)region);
    entry = arg2 + start;
    upper = ((f32 *)arg0)[1] + arg3 * 0.5f;
    lower = ((f32 *)arg0)[1] - arg3 * 0.5f;
    if (arg4 & 1) {
        if ((entry->flags & arg4) && entry->position[1] <= upper &&
            lower < entry->position[1] &&
            func_800EFC7C(entry->position, (void *)arg0) < entry->radius_squared) {
            return arg2;
        }
    } else {
        if ((entry->flags & arg4) && ((entry->flags & 2) ||
            (entry->position[1] - entry->height <= ((f32 *)arg0)[1] &&
             ((f32 *)arg0)[1] < entry->position[1] + entry->height)) &&
            func_800EFC7C(entry->position, (void *)arg0) < entry->radius_squared) {
            return arg2;
        }
    }
    end = (Entry *)func_800CB910((s16 *)region);
    if (arg4 & 1) {
        for (entry = start; entry < end; entry++) {
            if ((entry->flags & arg4) && entry->position[1] <= upper &&
                lower < entry->position[1] &&
                func_800EFC7C(entry->position, (void *)arg0) < entry->radius_squared) {
                return entry - start;
            }
        }
    } else {
        for (entry = start; entry < end; entry++) {
            if ((entry->flags & arg4) && ((entry->flags & 2) ||
                (entry->position[1] - entry->height <= ((f32 *)arg0)[1] &&
                 ((f32 *)arg0)[1] < entry->position[1] + entry->height)) &&
                func_800EFC7C(entry->position, (void *)arg0) < entry->radius_squared) {
                return entry - start;
            }
        }
    }
    return -1;
}

s32 func_800CCDF4(BtIntPtr arg0, s32 *arg1, s32 *arg2, s32 arg3, s32 arg4) {
    s32 func_800CBDD4(BtIntPtr, s32, s32);
    s32 func_800CCAB0(BtIntPtr, s32, s32, s32, s32);
    s32 temp_v0;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;

    if (*arg1 == -1) {
        temp_v0 = func_800CBDD4(arg0, arg3, arg4);
        *arg1 = temp_v0;
        if (temp_v0 == -1) {
            *arg2 = -1;
            return 0;
        }
    }
    temp_v0_3 = func_800CCAB0(arg0, *arg1, *arg2 == -1 ? 0 : *arg2, arg3, arg4);
    *arg2 = temp_v0_3;
    if (temp_v0_3 >= 0) {
        return 1;
    }
    temp_v0_4 = func_800CBDD4(arg0, arg3, arg4);
    *arg1 = temp_v0_4;
    if (temp_v0_4 == -1) {
        *arg2 = -1;
        return 0;
    }
    temp_v0_5 = func_800CCAB0(arg0, *arg1, 0, arg3, arg4);
    *arg2 = temp_v0_5;
    if (temp_v0_5 >= 0) {
        return 1;
    }
    *arg1 = -1;
    return 0;
}

/* extern */

s32 func_800CCEF4(BtIntPtr arg0, s32 *arg1, s32 *arg2, s32 arg3) {
    s32 func_800CC078(BtIntPtr);
    s32 func_800CC6F4(BtIntPtr, s32, s32);
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 var_a2;

    if (*arg1 == -1) {
        temp_v0 = func_800CC078(arg0);
        *arg1 = temp_v0;
        if (temp_v0 == -1) {
            *arg2 = -1;
            return 0;
        }
    }
    temp_v0_3 = func_800CC6F4(arg0, *arg1, *arg2 == -1 ? 0 : *arg2);
    *arg2 = temp_v0_3;
    if (temp_v0_3 >= 0) {
        return 1;
    }
    temp_v0_4 = func_800CC078(arg0);
    *arg1 = temp_v0_4;
    if (temp_v0_4 == -1) {
        *arg2 = -1;
        return 0;
    }
    temp_v0_5 = func_800CC6F4(arg0, *arg1, 0);
    *arg2 = temp_v0_5;
    if (temp_v0_5 >= 0) {
        return 1;
    }
    *arg1 = -1;
    return 0;
}    typedef struct { u8 pad0[0x4]; BtIntPtr unk4; u8 pad8[0x4]; BtIntPtr unkC; u8 pad10[0x4]; BtIntPtr unk14; u8 pad18[0xC8]; BtIntPtr unkE0; } Obj1EA5180_D_8012AE80; /* offsets.py genstruct: fields from raw offsets on &D_8012AE80; rename once understood */

void func_800CCFEC(void) {
    BtIntPtr defrag(BtIntPtr);
    extern s32 D_8012AE80;
    if ((((Obj1EA5180_D_8012AE80 *)&D_8012AE80)->unk4) != 0) {
        (((Obj1EA5180_D_8012AE80 *)&D_8012AE80)->unk4) = defrag((((Obj1EA5180_D_8012AE80 *)&D_8012AE80)->unk4));
    }
    if ((((Obj1EA5180_D_8012AE80 *)&D_8012AE80)->unkC) != 0) {
        (((Obj1EA5180_D_8012AE80 *)&D_8012AE80)->unkC) = defrag((((Obj1EA5180_D_8012AE80 *)&D_8012AE80)->unkC));
    }
    if ((((Obj1EA5180_D_8012AE80 *)&D_8012AE80)->unk14) != 0) {
        (((Obj1EA5180_D_8012AE80 *)&D_8012AE80)->unk14) = defrag((((Obj1EA5180_D_8012AE80 *)&D_8012AE80)->unk14));
    }
    if ((((Obj1EA5180_D_8012AE80 *)&D_8012AE80)->unkE0) != 0) {
        (((Obj1EA5180_D_8012AE80 *)&D_8012AE80)->unkE0) = defrag((((Obj1EA5180_D_8012AE80 *)&D_8012AE80)->unkE0));
    }
}    typedef struct { u8 pad0[0xC]; s16 unkC; s16 unkE; } Obj1EA5180_func_800CD08C_temp_a1; /* offsets.py genstruct: fields from raw offsets on temp_a1; rename once understood */

void func_800CD08C(s32 arg0, f32 *arg1) {
    s32 func_800DC128(s32, s32);
    f32 func_800DC178(f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    extern f32 D_80125990;
    extern s32 D_8012AE84;
    f32 temp_f20;
    f32 temp_f24;
    s16 *temp_a0;
    s16 temp_v0;
    BtIntPtr temp_s2;
    u32 temp_s7;
    void *temp_a1;

    temp_a0 = (arg0 * 0x1C) + D_8012AE84;
    temp_s7 = *(u32 *)temp_a0 >> 9;
    temp_s2 = func_800CB8F0(temp_a0);
    temp_f24 = D_80125990;
    do {
        temp_a1 = (func_800DC128(0, temp_s7) * 0x18) + temp_s2;
        func_800EE7F8(arg1, temp_a1);
        temp_f20 = func_800DC178(0.0f, temp_f24);
        func_800EF1B8(arg1, temp_f20, func_800DC178(0.0f, (f32) ((((Obj1EA5180_func_800CD08C_temp_a1 *)temp_a1)->unkC) - 5)));
        temp_v0 = (((Obj1EA5180_func_800CD08C_temp_a1 *)temp_a1)->unkE);
        arg1[1] += func_800DC178((f32) (5 - temp_v0), (f32) (temp_v0 - 5));
    } while (func_800CC4D4(arg1, arg0) != -1);
}    typedef struct { u8 pad0[0x4]; f32 unk4; } Obj1EA5180_arg1; /* offsets.py genstruct: fields from raw offsets on arg1; rename once understood */

/* extern */

void func_800CD1E0(s32 arg0, u8 *arg1, f32 arg2) {
    func_800CD08C(arg0, arg1);
    if ((((Obj1EA5180_arg1 *)arg1)->unk4) < arg2) {
        (((Obj1EA5180_arg1 *)arg1)->unk4) = arg2;
    }
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
s32 D_8012AE80 BT_DATA(4, bss_core2bss1_1, 0x3A0);
s32 D_8012AE84 BT_DATA(4, bss_core2bss1_1, 0x3A4);
s32 D_8012AE8C BT_DATA(4, bss_core2bss1_1, 0x3AC);
s32 D_8012AE94 BT_DATA(4, bss_core2bss1_1, 0x3B4);
s32 D_8012AE98 BT_DATA(4, bss_core2bss1_1, 0x3B8);
u8 * D_8012AF60 BT_DATA(4, bss_core2bss1_1, 0x480);
#endif
