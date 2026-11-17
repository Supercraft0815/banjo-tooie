#include "common.h"

typedef struct { u8 pad0[0x4]; s16 unk4; u8 unk6; } Objworld_func_80800000_idworld_var_v1; /* offsets.py genstruct: fields from raw offsets on var_v1; rename once understood */ BtIntPtr func_80800000_idworld(s32 arg0, s32 arg1) {
    void * vector_begin(void *vec);
    void * vector_end(void *vec);
    extern s32 D_80127EF8;
    s32 pad;
    BtUIntPtr sp20;
    BtIntPtr sp1C = D_80127EF8;
    BtUIntPtr temp_v0;
    BtUIntPtr var_v1;

    if (sp1C == 0) {
        return 0;
    }
    sp20 = vector_end(sp1C);
    temp_v0 = vector_begin(D_80127EF8);
    var_v1 = temp_v0;
    if (temp_v0 < sp20) {
loop_3:
        if ((arg1 == (((Objworld_func_80800000_idworld_var_v1 *)var_v1)->unk6)) && (arg0 == (((Objworld_func_80800000_idworld_var_v1 *)var_v1)->unk4))) {
            return var_v1;
        }
        var_v1 += 0xA8;
        if (var_v1 >= sp20) {
            goto block_7;
        }
        goto loop_3;
    }
block_7:
    return NULL;
}

/* extern */

BtIntPtr idworld_entrypoint_0(s32 arg0) {
    BtIntPtr func_80800000_idworld(s32, s32);
    BtIntPtr temp_v0;
    BtIntPtr var_v1;

    temp_v0 = func_80800000_idworld(arg0, 6);
    if (temp_v0 != 0) {
        var_v1 = temp_v0 + 8;
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

/* extern */

BtIntPtr idworld_entrypoint_1(s32 arg0) {
    BtIntPtr func_80800000_idworld(s32, s32);
    BtIntPtr temp_v0;
    BtIntPtr var_v1;

    temp_v0 = func_80800000_idworld(arg0, 8);
    if (temp_v0 != 0) {
        var_v1 = temp_v0 + 8;
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

/* extern */

BtIntPtr idworld_entrypoint_2(s32 arg0) {
    BtIntPtr func_80800000_idworld(s32, s32);
    BtIntPtr temp_v0;
    BtIntPtr var_v1;

    temp_v0 = func_80800000_idworld(arg0, 12);
    if (temp_v0 != 0) {
        var_v1 = temp_v0 + 8;
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

/* extern */

BtIntPtr idworld_entrypoint_3(s32 arg0) {
    BtIntPtr func_80800000_idworld(s32, s32);
    BtIntPtr temp_v0;
    BtIntPtr var_v1;

    temp_v0 = func_80800000_idworld(arg0, 2);
    if (temp_v0 != 0) {
        var_v1 = temp_v0 + 8;
    } else {
        var_v1 = 0;
    }
    return var_v1;
}    typedef struct { s32 unk0; s16 unk4; u8 unk6; } Objworld_idworld_entrypoint_4_var_v1; /* offsets.py genstruct: fields from raw offsets on var_v1; rename once understood */

BtIntPtr idworld_entrypoint_4(BtIntPtr arg0, s32 arg1) {
    void * vector_begin(void *vec);
    void * vector_end(void *vec);
    extern s32 D_80127EF8;
    s32 pad;
    BtUIntPtr sp20;
    BtIntPtr sp1C = D_80127EF8;
    BtUIntPtr temp_v0;
    BtUIntPtr var_v1;

    if (sp1C == 0) {
        return 0;
    }
    sp20 = vector_end(sp1C);
    temp_v0 = vector_begin(D_80127EF8);
    var_v1 = temp_v0;
    if (temp_v0 < sp20) {
loop_4:
        if (((((Objworld_idworld_entrypoint_4_var_v1 *)var_v1)->unk6) == 0xA) && (arg0 == (((Objworld_idworld_entrypoint_4_var_v1 *)var_v1)->unk0)) && (arg1 == (((Objworld_idworld_entrypoint_4_var_v1 *)var_v1)->unk4))) {
            return var_v1 + 8;
        }
        var_v1 += 0xA8;
        if (var_v1 >= sp20) {
            goto block_9;
        }
        goto loop_4;
    }
block_9:
    return NULL;
}    typedef struct { u8 pad0[0x8]; BtIntPtr unk8; } Objworld_D_80127EF0; /* offsets.py genstruct: fields from raw offsets on &D_80127EF0; rename once understood */

void idworld_entrypoint_5(void) {
    void * vector_begin(void *vec);
    void * vector_end(void *vec);
    extern s32 D_80127EF0;
    extern void (*D_808002C0_idworld[])(u32, s32, s32);
    BtUIntPtr end;
    BtUIntPtr begin;
    BtUIntPtr item;

    end = vector_end(((Objworld_D_80127EF0 *)&D_80127EF0)->unk8);
    begin = vector_begin(((Objworld_D_80127EF0 *)&D_80127EF0)->unk8);
    item = begin;
    if (begin < end) {
        do {
            if (*(u8 *)(item + 7) != 0) {
                D_808002C0_idworld[*(u8 *)(item + 6)](item + 8, *(s32 *)item, *(s16 *)(item + 4));
            }
            item += 0xA8;
        } while (item < end);
    }
}
/* data_to_c.py: from asm/data/overlays/id/world.data.s */
void _idlight_entrypoint_3();
void _idscroll_entrypoint_3();
void func_800EE108();
void _idwater_entrypoint_4();
void _idglow_entrypoint_3();
void _idwave_entrypoint_3();
void _idglowa_entrypoint_4();
void _idflash_entrypoint_3();
void _idflasha_entrypoint_4();
void func_800EC9E0();
void _idwibble_entrypoint_3();
void _idbounce_entrypoint_5();
void _idtwinkle_entrypoint_5();
void _idflame_entrypoint_4();
void _idtwinklea_entrypoint_2();
void _idtwinklecolour_entrypoint_5();
void ( * D_808002C0_idworld [16] ) ( u32 , s32 , s32 ) BT_DATA(4, overlays_id_world, 0x0) = { (void (*)(unsigned long, long, long))_idlight_entrypoint_3, (void (*)(unsigned long, long, long))_idscroll_entrypoint_3, (void (*)(unsigned long, long, long))func_800EE108, (void (*)(unsigned long, long, long))_idwater_entrypoint_4, (void (*)(unsigned long, long, long))_idglow_entrypoint_3, (void (*)(unsigned long, long, long))_idwave_entrypoint_3, (void (*)(unsigned long, long, long))_idglowa_entrypoint_4, (void (*)(unsigned long, long, long))_idflash_entrypoint_3, (void (*)(unsigned long, long, long))_idflasha_entrypoint_4, (void (*)(unsigned long, long, long))func_800EC9E0, (void (*)(unsigned long, long, long))_idwibble_entrypoint_3, (void (*)(unsigned long, long, long))_idbounce_entrypoint_5, (void (*)(unsigned long, long, long))_idtwinkle_entrypoint_5, (void (*)(unsigned long, long, long))_idflame_entrypoint_4, (void (*)(unsigned long, long, long))_idtwinklea_entrypoint_2, (void (*)(unsigned long, long, long))_idtwinklecolour_entrypoint_5 };
