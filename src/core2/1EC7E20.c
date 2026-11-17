#include "common.h"

/* extern */

typedef struct { u8 pad0[0x24]; BtIntPtr unk24; u8 pad28[0x4]; BtIntPtr unk2C; } Obj1EC7E20_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */ void func_800EE530(void *arg0) {
    BtIntPtr defrag(BtIntPtr);
    (((Obj1EC7E20_arg0 *)arg0)->unk2C) = defrag((((Obj1EC7E20_arg0 *)arg0)->unk2C));
}

void func_800EE55C(u8 *arg0) {
    BtIntPtr defrag(BtIntPtr);
    s32 sp1C;

    sp1C = (s32) ((((Obj1EC7E20_arg0 *)arg0)->unk2C) - (((Obj1EC7E20_arg0 *)arg0)->unk24)) >> 2;
    (((Obj1EC7E20_arg0 *)arg0)->unk24) = defrag((((Obj1EC7E20_arg0 *)arg0)->unk24));
    (((Obj1EC7E20_arg0 *)arg0)->unk2C) = (((Obj1EC7E20_arg0 *)arg0)->unk24) + (sp1C * 4);
}

/* extern */

void func_800EE5AC(void *arg0) {
    BtIntPtr defrag(BtIntPtr);
    (((Obj1EC7E20_arg0 *)arg0)->unk24) = defrag((((Obj1EC7E20_arg0 *)arg0)->unk24));
}

BtIntPtr func_800EE5D8(BtIntPtr arg0) {
    BtIntPtr defrag(BtIntPtr);
    BtUIntPtr vector_begin(s32);
    BtUIntPtr vector_end(s32);
    extern s32 D_80127EF8;
    BtIntPtr var_a3;
    BtIntPtr temp_v0;
    BtUIntPtr sp1C;
    BtUIntPtr temp_v0_2;
    BtUIntPtr var_v1;

    temp_v0 = defrag(arg0);
    var_a3 = temp_v0;
    if ((D_80127EF8 != 0) && (temp_v0 != arg0)) {
        sp1C = vector_end(D_80127EF8);
        temp_v0_2 = vector_begin(D_80127EF8);
        var_v1 = temp_v0_2;
        if (temp_v0_2 < sp1C) {
            do {
                if (arg0 == *(s32 *)var_v1) {
                    *(s32 *)var_v1 = var_a3;
                }
                var_v1 += 0xA8;
            } while (var_v1 < sp1C);
        }
    }
    return var_a3;
}

void func_800EE670(void) {
    BtUIntPtr vector_begin(s32);
    s32 vector_defrag(s32);
    BtUIntPtr vector_end(s32);
    extern s32 (*D_80123590[])(s32);
    extern s32 D_80127EF8;
    s32 (*temp_v0_2)(s32);
    BtUIntPtr temp_s2;
    BtUIntPtr temp_v0;
    BtUIntPtr var_s0;

    if (D_80127EF8 != 0) {
        temp_s2 = vector_end(D_80127EF8);
        temp_v0 = vector_begin(D_80127EF8);
        var_s0 = temp_v0;
        if (temp_v0 < temp_s2) {
            do {
                temp_v0_2 = D_80123590[*(u8 *)(var_s0 + 6)];
                if (temp_v0_2 != NULL) {
                    temp_v0_2(var_s0 + 8);
                }
                var_s0 += 0xA8;
            } while (var_s0 < temp_s2);
        }
        D_80127EF8 = vector_defrag(D_80127EF8);
    }
}

void func_800EE718(void) {
    void _idbounce_entrypoint_6(void);
    extern u8 D_80135483;
    if (D_80135483 != 0) {
        _idbounce_entrypoint_6();
    }
}

void func_800EE748(void) {
    void _idbounce_entrypoint_7(void);
    extern u8 D_80135483;
    if (D_80135483 != 0) {
        _idbounce_entrypoint_7();
    }
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
u8 D_80135483 BT_DATA(4, bss_core2bss2_2, 0x25E3);
#endif
