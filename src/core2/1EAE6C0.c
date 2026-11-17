#include "core2/1EAE6C0.h"

extern s32 D_8012B420;
s32 func_800D4DD0(s32 arg0) {
    if (D_8012B420 != 0) {
        switch (arg0) {
        case 10:
            arg0 = 1;
            break;
        case 4:
        case 11:
            arg0 = 0;
            break;
        }
    }
    return arg0;
}

/* extern */

void func_800D4E18(s32 arg0, s32 arg1) { s32 func_800D4E7C(s32); void func_800D4FB8(s32, s32); if (arg0 == 9) { arg0 = 1; } if (arg1 < 0) { func_800FC660(0x74U); } func_800D4FB8(arg0, func_800D4E7C(arg0) + arg1); }

s32 func_800D4E7C(s32 arg0) {
    s32 func_800D4DD0(s32);
    extern u8 D_8011B641[];
    s32 index;

    if (arg0 == 9) {
        arg0 = 1;
    }
    index = func_800D4DD0(arg0);
    return D_8011B641[index * 3];
}

u8 func_800D4EB8(s32 arg0) {
    s32 func_800D4DD0(s32);
    extern u8 D_8011B642[];
    s32 index;

    if (arg0 == 9) {
        arg0 = 1;
    }
    index = func_800D4DD0(arg0);
    return D_8011B642[index * 3];
}

s32 func_800D4EF4(s32 arg0) {
    switch (arg0) {
        case 1: return 5;
        case 2: return 5;
        case 6: return 3;
        case 7: return 6;
        case 8: return 5;
        case 10: return 3;
        case 11: return 2;
        case 12: return 5;
        case 13: return 4;
        case 14: return 0;
        case 15: return 4;
        case 16: return 0;
        case 17: return 0;
        case 18: return 4;
        case 19: return 0;
        default: break;
    }
    return 0;
}

s32 func_800D4F9C(s32 arg0) {
    if (arg0 == 2) {
        return 0;
    }
    return 1;
}

void func_800D4FB8(s32 arg0, s32 arg1) {
    s32 func_800D4DD0(s32);
    extern u8 D_8011B640[];
    s32 index;
    u8 *entry;
    if (arg0 == 9) {
        arg0 = 1;
    }
    index = func_800D4DD0(arg0);
    if (arg1 < 0) {
        entry = &D_8011B640[index * 3];
        arg1 = 0;
    } else {
        entry = &D_8011B640[index * 3];
        arg0 = entry[2];
        if (arg0 < arg1) {
            arg1 = arg0;
        }
    }
    entry[1] = arg1;
}

void func_800D5034(s32 arg0, s32 arg1) {
    typedef struct { u8 kind, value, maximum; } InventoryEntry;
    extern u8 D_8011B640[];
    s32 value;
    s32 maximum;

    if (arg1 == 9) {
        arg1 = 1;
    }
    value = ((InventoryEntry *)D_8011B640)[arg1].value;
    maximum = ((InventoryEntry *)D_8011B640)[arg1].maximum;
    switch (arg1) {
        case 1:
            switch (arg0) {
                case 0:
                case 2:
                case 6:
                case 7:
                case 8:
                case 12:
                case 15:
                case 16:
                case 18:
                case 19:
                    value = maximum;
                    break;
                case 10:
                case 11:
                    value = ((InventoryEntry *)D_8011B640)[10].value + ((InventoryEntry *)D_8011B640)[11].value;
                    break;
            }
            break;
        case 2:
            value = 1;
            break;
        case 6:
        case 7:
        case 8:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
            value = maximum;
            break;
        case 10:
        case 11:
            if ((arg0 == 0) != 0) {
                value = maximum;
                func_800D4FB8(arg1 == 10 ? 11 : 10, value);
            } else {
                value = ((InventoryEntry *)D_8011B640)[arg0].value / 2;
                if (arg1 == 10) {
                    value += ((InventoryEntry *)D_8011B640)[arg0].value % 2;
                }
                if (value == 0) {
                    value = 1;
                }
            }
            break;
    }
    func_800D4FB8(arg1, value);
}

void func_800D517C(void) {
    s32 _gcextra_entrypoint_0();
    s32 func_800D4EF4(s32);
    extern u8 D_8011B640[];
    u8 *entry;
    s32 extra;
    s32 i;
    s32 value;

    extra = _gcextra_entrypoint_0();
    D_8012B420 = 0;
    entry = D_8011B640;
    i = 0;
    do {
        value = func_800D4EF4(i);
        if (value != 0 && func_800D4F9C(i) != 0) {
            value += extra;
        }
        i++;
        entry += 3;
        entry[-1] = value;
        entry[-2] = value;
    } while (i != 0x14);
}

u8 func_800D5210(s32 arg0) {
    extern u8 D_8011B640[];

    if (arg0 == 9) {
        arg0 = 1;
    }
    return D_8011B640[arg0 * 3];
}    typedef struct { s32 unk0; } Obj1EAE6C0_D_8012B420; /* offsets.py genstruct: fields from raw offsets on &D_8012B420; rename once understood */

void func_800D5234(s32 arg0) {
    extern s32 D_8012B420;
    ((Obj1EAE6C0_D_8012B420 *)&D_8012B420)->unk0 = arg0;
}

s32 func_800D5240(void) {
    extern s32 D_8012B420;
    return *&((Obj1EAE6C0_D_8012B420 *)&D_8012B420)->unk0;
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
s32 D_8012B420 BT_DATA(16, bss_core2bss1_2_status_tail, 0x0);
#endif
