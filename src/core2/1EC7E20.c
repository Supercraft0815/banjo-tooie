#include "common.h"
#include "core2/world_effect.h"

/* extern */

#ifdef BT_NATIVE
void func_800EE530(void *data) {
    void *defrag(void *);
    TwinkleEffect *effect = data;
    effect->particles = defrag(effect->particles);
}

void func_800EE55C(void *data) {
    void *defrag(void *);
    BounceEffect *effect = data;
    s32 count = effect->end - effect->begin;
    effect->begin = defrag(effect->begin);
    effect->end = effect->begin + count;
}

void func_800EE5AC(void *data) {
    void *defrag(void *);
    TwinkleColorEffect *effect = data;
    effect->particles = defrag(effect->particles);
}

#else
typedef struct { u8 pad0[0x24]; BtIntPtr unk24; u8 pad28[0x4]; BtIntPtr unk2C; } Obj1EC7E20_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */ void func_800EE530(void *arg0) {
    BtIntPtr defrag(BtIntPtr);
    (((Obj1EC7E20_arg0 *)arg0)->unk2C) = defrag((((Obj1EC7E20_arg0 *)arg0)->unk2C));
}

void func_800EE55C(void *arg0) {
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

#endif

BtIntPtr func_800EE5D8(BtIntPtr arg0) {
    BT_NATIVE_ONLY(void *defrag(void *);) BT_IDO_ONLY(BtIntPtr defrag(BtIntPtr);)
    BtUIntPtr vector_begin(struct Vector *);
    BtUIntPtr vector_end(struct Vector *);
    BtIntPtr var_a3;
    BtIntPtr temp_v0;
    BtUIntPtr sp1C;
    BtUIntPtr temp_v0_2;
    BtUIntPtr var_v1;

    temp_v0 = (BtIntPtr)defrag(BT_DATA_FIELD((void *)arg0, arg0));
    var_a3 = temp_v0;
    if ((D_80127EF8 != 0) && (temp_v0 != arg0)) {
        sp1C = vector_end(D_80127EF8);
        temp_v0_2 = vector_begin(D_80127EF8);
        var_v1 = temp_v0_2;
        if (temp_v0_2 < sp1C) {
            do {
                if (arg0 == ((WorldEffect *)var_v1)->owner) {
                    ((WorldEffect *)var_v1)->owner = var_a3;
                }
                var_v1 += sizeof(WorldEffect);
            } while (var_v1 < sp1C);
        }
    }
    return var_a3;
}

void func_800EE670(void) {
    BtUIntPtr vector_begin(struct Vector *);
    struct Vector *vector_defrag(struct Vector *);
    BtUIntPtr vector_end(struct Vector *);
    WorldEffectDefrag temp_v0_2;
    BtUIntPtr temp_s2;
    BtUIntPtr temp_v0;
    BtUIntPtr var_s0;

    if (D_80127EF8 != 0) {
        temp_s2 = vector_end(D_80127EF8);
        temp_v0 = vector_begin(D_80127EF8);
        var_s0 = temp_v0;
        if (temp_v0 < temp_s2) {
            do {
                temp_v0_2 = D_80123590[((WorldEffect *)var_s0)->type];
                if (temp_v0_2 != NULL) {
                    temp_v0_2(((WorldEffect *)var_s0)->data);
                }
                var_s0 += sizeof(WorldEffect);
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

WorldEffectDefrag D_80123590[16] BT_DATA(4, world_effect_defrag, 0) = {
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, func_800EE55C, func_800EE530, NULL, NULL, func_800EE5AC
};
