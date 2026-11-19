#include "common.h"
#include "core2/world_effect.h"

struct Vector;

extern struct IdWorldmakeEntry {
    void (*create)(void *, s32, void *, s32, s32);
    void (*destroy)(void *);
} D_80800AB0_idworldmake[];

void func_80800000_idworldmake(BtIntPtr arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    struct Vector *vector_new(u32, u32);
    void *vector_push_back(struct Vector **);
    WorldEffect *entry;

    if (D_80127EF8 == 0) {
        D_80127EF8 = vector_new(sizeof(WorldEffect), 2);
    }
    entry = vector_push_back(&D_80127EF8);
    entry->type = arg2;
    entry->owner = arg0;
    entry->id = arg1;
    entry->active = 1;
    D_80800AB0_idworldmake[entry->type].create(entry->data, arg3, (void *)arg0, entry->id, arg4);
}    typedef struct { s16 unk0; } Objworldmake_idworldmake_entrypoint_0_var_s2; /* offsets.py genstruct: fields from raw offsets on var_s2; rename once understood */

/* extern */

void idworldmake_entrypoint_0(BtIntPtr arg0, s32 arg1) {
    s16 *_glidmake_entrypoint_1(BT_NATIVE_ONLY(void *));
    void func_80800000_idworldmake(BtIntPtr, s32, s32, s32, s32);
    s16 *sp34;
    s16 *temp_v0;
    s16 *var_s2;
    s16 temp_a1;
    s32 var_s3;

    temp_v0 = _glidmake_entrypoint_1(BT_NATIVE_ONLY((void *)arg0));
    sp34 = temp_v0;
    var_s2 = temp_v0 + 1;
    var_s3 = 0;
    if (*temp_v0 > 0) {
        do {
            temp_a1 = (((Objworldmake_idworldmake_entrypoint_0_var_s2 *)var_s2)->unk0);
            if ((temp_a1 >= 0x65) && (temp_a1 < 0xC8)) {
                func_80800000_idworldmake(arg0, temp_a1, 1, temp_a1 - 0x64, arg1);
            } else if ((temp_a1 >= 0xC8) && (temp_a1 < 0x12C)) {
                func_80800000_idworldmake(arg0, temp_a1, 0, temp_a1 - 0xC8, arg1);
            } else if ((temp_a1 >= 0x12C) && (temp_a1 < 0x190)) {
                func_80800000_idworldmake(arg0, temp_a1, 3, temp_a1 - 0x12C, arg1);
            } else if ((temp_a1 >= 0x190) && (temp_a1 < 0x1F4)) {
                func_80800000_idworldmake(arg0, temp_a1, 2, temp_a1 - 0x190, arg1);
            } else if ((temp_a1 >= 0x1F4) && (temp_a1 < 0x258)) {
                func_80800000_idworldmake(arg0, temp_a1, 4, temp_a1 - 0x1F4, arg1);
            } else if ((temp_a1 >= 0x258) && (temp_a1 < 0x2BC)) {
                func_80800000_idworldmake(arg0, temp_a1, 2, temp_a1 - 0x258, arg1);
            } else if ((temp_a1 >= 0x2BC) && (temp_a1 < 0x320)) {
                func_80800000_idworldmake(arg0, temp_a1, 5, temp_a1 - 0x2BC, arg1);
            } else if ((temp_a1 >= 0x320) && (temp_a1 < 0x384)) {
                func_80800000_idworldmake(arg0, temp_a1, 6, temp_a1 - 0x320, arg1);
            } else if ((temp_a1 >= 0x384) && (temp_a1 < 0x3E8)) {
                func_80800000_idworldmake(arg0, temp_a1, 8, temp_a1 - 0x384, arg1);
            } else if ((temp_a1 >= 0x3E8) && (temp_a1 < 0x44C)) {
                func_80800000_idworldmake(arg0, temp_a1, 7, temp_a1 - 0x3E8, arg1);
            } else if ((temp_a1 >= 0x44C) && (temp_a1 < 0x4B0)) {
                func_80800000_idworldmake(arg0, temp_a1, 9, temp_a1 - 0x44C, arg1);
            } else if ((temp_a1 >= 0x4B0) && (temp_a1 < 0x6A4)) {
                func_80800000_idworldmake(arg0, temp_a1, 0xA, temp_a1 - 0x4B0, arg1);
            } else if ((temp_a1 >= 0x6A4) && (temp_a1 < 0x708)) {
                func_80800000_idworldmake(arg0, temp_a1, 0xB, temp_a1 - 0x6A4, arg1);
            } else if ((temp_a1 >= 0x708) && (temp_a1 < 0x76C)) {
                func_80800000_idworldmake(arg0, temp_a1, 0xC, temp_a1 - 0x708, arg1);
            } else if ((temp_a1 >= 0x76C) && (temp_a1 < 0x7D0)) {
                func_80800000_idworldmake(arg0, temp_a1, 0xD, temp_a1 - 0x76C, arg1);
            } else if ((temp_a1 >= 0x7D0) && (temp_a1 < 0x834)) {
                func_80800000_idworldmake(arg0, temp_a1, 0xE, temp_a1 - 0x7D0, arg1);
            } else if ((temp_a1 >= 0x834) && (temp_a1 < 0x898)) {
                func_80800000_idworldmake(arg0, temp_a1, 0xA, temp_a1 - 0x4B0, arg1);
            } else if ((temp_a1 >= 0x898) && (temp_a1 < 0x8FC)) {
                func_80800000_idworldmake(arg0, temp_a1, 0xF, temp_a1 - 0x898, arg1);
            }
            var_s3 += 1;
            var_s2 += var_s2[1];
            var_s2 += 2;
        } while (var_s3 < *sp34);
    }
}    typedef struct { s16 unk0; s16 unk2; } Objworldmake_idworldmake_entrypoint_1_var_s3; /* offsets.py genstruct: fields from raw offsets on var_s3; rename once understood */

void idworldmake_entrypoint_1(BtIntPtr arg0, s32 arg1, volatile unsigned int arg2, s32 arg3)
{
  s16 *_glidmake_entrypoint_1(BT_NATIVE_ONLY(void *));
  void func_80800000_idworldmake(BtIntPtr, s32, s32, s32, s32);
  s16 *sp3C;
  s16 *temp_v0;
  s16 *var_s3;
  s16 temp_a1;
  s32 var_s4;
  temp_v0 = _glidmake_entrypoint_1(BT_NATIVE_ONLY((void *)arg0));
  sp3C = temp_v0;
  var_s3 = temp_v0;
  var_s3 = var_s3 + 1;
  var_s4 = 0;
  if ((*temp_v0) > 0)
  {
    do
    {
      temp_a1 = ((Objworldmake_idworldmake_entrypoint_1_var_s3 *)var_s3)->unk0;
      if (arg2 == temp_a1)
      {
        if ((arg1 >= 0x65) && (arg1 < 0xC8))
        {
          func_80800000_idworldmake(arg0, temp_a1, 1, arg1 - 0x64, arg3);
        }
        else
          if ((arg1 >= 0xC8) && (arg1 < 0x12C))
        {
          func_80800000_idworldmake(arg0, temp_a1, 0, arg1 - 0xC8, arg3);
        }
        else
          if ((arg1 >= 0x12C) && (arg1 < 0x190))
        {
          func_80800000_idworldmake(arg0, temp_a1, 3, arg1 - 0x12C, arg3);
        }
        else
          if ((arg1 >= 0x190) && (arg1 < 0x1F4))
        {
          func_80800000_idworldmake(arg0, temp_a1, 2, arg1 - 0x190, arg3);
        }
        else
          if ((arg1 >= 0x1F4) && (arg1 < 0x258))
        {
          func_80800000_idworldmake(arg0, temp_a1, 4, arg1 - 0x1F4, arg3);
        }
        else
          if ((arg1 >= 0x258) && (arg1 < 0x2BC))
        {
          func_80800000_idworldmake(arg0, temp_a1, 2, arg1 - 0x258, arg3);
        }
        else
          if ((arg1 >= 0x320) && (arg1 < 0x384))
        {
          func_80800000_idworldmake(arg0, temp_a1, 6, arg1 - 0x320, arg3);
        }
        else
          if ((arg1 >= 0x384) && (arg1 < 0x3E8))
        {
          func_80800000_idworldmake(arg0, temp_a1, 8, arg1 - 0x384, arg3);
        }
        else
          if ((arg1 >= 0x3E8) && (arg1 < 0x44C))
        {
          func_80800000_idworldmake(arg0, temp_a1, 7, arg1 - 0x3E8, arg3);
        }
        else
          if ((arg1 >= 0x44C) && (arg1 < 0x4B0))
        {
          func_80800000_idworldmake(arg0, temp_a1, 9, arg1 - 0x44C, arg3);
        }
        else
          if ((arg1 >= 0x6A4) && (arg1 < 0x708))
        {
          func_80800000_idworldmake(arg0, temp_a1, 0xB, arg1 - 0x6A4, arg3);
        }
        else
          if ((arg1 >= 0x708) && (arg1 < 0x76C))
        {
          func_80800000_idworldmake(arg0, temp_a1, 0xC, arg1 - 0x708, arg3);
        }
        else
          if ((arg1 >= 0x76C) && (arg1 < 0x7CF))
        {
          func_80800000_idworldmake(arg0, temp_a1, 0xD, arg1 - 0x76C, arg3);
        }
        else
          if ((arg1 >= 0x2BC) && (arg1 < 0x320))
        {
          func_80800000_idworldmake(arg0, temp_a1, 5, arg1 - 0x2BC, arg3);
        }
        else
          if ((arg1 >= 0x4B0) && (arg1 < 0x6A4))
        {
          func_80800000_idworldmake(arg0, temp_a1, 0xA, arg1 - 0x4B0, arg3);
        }
        else
          if ((arg1 >= 0x898) && (arg1 < 0x8FC))
        {
          func_80800000_idworldmake(arg0, temp_a1, 0xF, arg1 - 0x898, arg3);
        }
      }
      var_s4 += 1;
      var_s3 += ((Objworldmake_idworldmake_entrypoint_1_var_s3 *)var_s3)->unk2;
      var_s3 += 2;
    }
    while (var_s4 < (*sp3C));
  }
}    typedef struct { s32 unk0; } Objworldmake_idworldmake_entrypoint_2_var_s0; /* offsets.py genstruct: fields from raw offsets on var_s0; rename once understood */ typedef struct { u8 pad0[0x8]; BtIntPtr unk8; } Objworldmake_D_80127EF0; /* offsets.py genstruct: fields from raw offsets on &D_80127EF0; rename once understood */

void idworldmake_entrypoint_2(BtIntPtr arg0) {
    BtUIntPtr vector_begin(struct Vector *);
    BtUIntPtr vector_end(struct Vector *);
    void vector_erase(void *vec, u32 index);
    s32 vector_index_of(void *vec, void *element);
    extern s32 D_80127EF0;
    BtUIntPtr var_s0;
    BtUIntPtr var_v1;
    var_v1 = vector_end(BT_DATA_FIELD(D_80127EF8, (((Objworldmake_D_80127EF0 *)&D_80127EF0)->unk8)));
    var_s0 = vector_begin(BT_DATA_FIELD(D_80127EF8, (((Objworldmake_D_80127EF0 *)&D_80127EF0)->unk8))); if (var_s0 < var_v1) { do { if (arg0 == (((WorldEffect *)var_s0)->owner)) { D_80800AB0_idworldmake[((WorldEffect *)var_s0)->type].destroy(((WorldEffect *)var_s0)->data); vector_erase(BT_DATA_FIELD(D_80127EF8, (((Objworldmake_D_80127EF0 *)&D_80127EF0)->unk8)), vector_index_of(BT_DATA_FIELD(D_80127EF8, (((Objworldmake_D_80127EF0 *)&D_80127EF0)->unk8)), (void *) var_s0)); var_s0 = vector_begin(BT_DATA_FIELD(D_80127EF8, (((Objworldmake_D_80127EF0 *)&D_80127EF0)->unk8))); var_v1 = vector_end(BT_DATA_FIELD(D_80127EF8, (((Objworldmake_D_80127EF0 *)&D_80127EF0)->unk8))); } var_s0 += sizeof(WorldEffect); } while (var_s0 < var_v1); } }

void idworldmake_entrypoint_3(void) {
    BtUIntPtr vector_begin(struct Vector *);
    BtUIntPtr vector_end(struct Vector *);
    void vector_free(struct Vector *);
    BtUIntPtr temp_s1;
    BtUIntPtr temp_v0;
    BtUIntPtr var_s0;

    if (D_80127EF8 != 0) {
        temp_s1 = vector_end(D_80127EF8);
        temp_v0 = vector_begin(D_80127EF8);
        var_s0 = temp_v0;
        if (temp_v0 < temp_s1) {
            do {
                D_80800AB0_idworldmake[((WorldEffect *)var_s0)->type].destroy(((WorldEffect *)var_s0)->data);
                var_s0 += sizeof(WorldEffect);
            } while (var_s0 < temp_s1);
        }
        vector_free(D_80127EF8);
        D_80127EF8 = 0;
    }
}

void idworldmake_entrypoint_4(void) {
}    typedef struct { s32 unk0; u8 pad4[0x3]; s8 unk7; } Objworldmake_idworldmake_entrypoint_5_var_v1; /* offsets.py genstruct: fields from raw offsets on var_v1; rename once understood */

void idworldmake_entrypoint_5(BtIntPtr arg0, s32 arg1) {
    BtUIntPtr vector_begin(struct Vector *);
    BtUIntPtr vector_end(struct Vector *);
    BtUIntPtr temp_v0;
    BtUIntPtr sp18;
    BtUIntPtr var_v1;

    sp18 = vector_end(D_80127EF8);
    temp_v0 = vector_begin(D_80127EF8);
    var_v1 = temp_v0;
    if (temp_v0 < sp18) {
        do {
            if (arg0 == (((WorldEffect *)var_v1)->owner)) {
                (((WorldEffect *)var_v1)->active) = (s8) arg1;
            }
            var_v1 += sizeof(WorldEffect);
        } while (var_v1 < sp18);
    }
}    typedef struct { s32 unk0; u8 pad4[0x2]; u8 unk6; s8 unk7; } Objworldmake_idworldmake_entrypoint_6_var_v1; /* offsets.py genstruct: fields from raw offsets on var_v1; rename once understood */

void idworldmake_entrypoint_6(BtIntPtr arg0, s32 arg1, s32 arg2) {
    BtUIntPtr vector_begin(struct Vector *);
    BtUIntPtr vector_end(struct Vector *);
    BtUIntPtr temp_v0;
    BtUIntPtr sp20;
    BtUIntPtr var_v1;

    sp20 = vector_end(D_80127EF8);
    temp_v0 = vector_begin(D_80127EF8);
    var_v1 = temp_v0;
    if (temp_v0 < sp20) {
        do {
            if ((arg0 == (((WorldEffect *)var_v1)->owner)) && !((1 << (((WorldEffect *)var_v1)->type)) & arg2)) {
                (((WorldEffect *)var_v1)->active) = (s8) arg1;
            }
            var_v1 += sizeof(WorldEffect);
        } while (var_v1 < sp20);
    }
}    typedef struct { s32 unk0; s16 unk4; u8 pad6[0x1]; s8 unk7; } Objworldmake_idworldmake_entrypoint_7_var_v1; /* offsets.py genstruct: fields from raw offsets on var_v1; rename once understood */

void idworldmake_entrypoint_7(BtIntPtr arg0, s32 arg1, s32 arg2) {
    BtUIntPtr vector_begin(struct Vector *);
    BtUIntPtr vector_end(struct Vector *);
    BtUIntPtr temp_v0;
    BtUIntPtr sp20;
    BtUIntPtr var_v1;

    sp20 = vector_end(D_80127EF8);
    temp_v0 = vector_begin(D_80127EF8);
    var_v1 = temp_v0;
    if (temp_v0 < sp20) {
        do {
            if ((arg0 == (((WorldEffect *)var_v1)->owner)) && (arg1 == (((WorldEffect *)var_v1)->id))) {
                (((WorldEffect *)var_v1)->active) = (s8) arg2;
            }
            var_v1 += sizeof(WorldEffect);
        } while (var_v1 < sp20);
    }
}
void _idlight_entrypoint_2(void *, s32, void *, s32, s32);
void _idlight_entrypoint_1(void *);
void _idscroll_entrypoint_2(void *, s32, void *, s32, s32);
void _idscroll_entrypoint_1(void *);
void func_800EDB20(void *, s32, void *, s32, s32);
void func_800EDAF4(void *);
void _idwater_entrypoint_3(void *, s32, void *, s32, s32);
void _idwater_entrypoint_2(void *);
void _idglow_entrypoint_2(void *, s32, void *, s32, s32);
void _idglow_entrypoint_1(void *);
void _idwave_entrypoint_2(void *, s32, void *, s32, s32);
void _idwave_entrypoint_1(void *);
void _idglowa_entrypoint_3(void *, s32, void *, s32, s32);
void _idglowa_entrypoint_2(void *);
void _idflash_entrypoint_2(void *, s32, void *, s32, s32);
void _idflash_entrypoint_1(void *);
void _idflasha_entrypoint_3(void *, s32, void *, s32, s32);
void _idflasha_entrypoint_2(void *);
void func_800EC898(void *, s32, void *, s32, s32);
void func_800EC890(void *);
void _idwibble_entrypoint_2(void *, s32, void *, s32, s32);
void _idwibble_entrypoint_1(void *);
void _idbounce_entrypoint_4(void *, s32, void *, s32, s32);
void _idbounce_entrypoint_3(void *);
void _idtwinkle_entrypoint_4(void *, s32, void *, s32, s32);
void _idtwinkle_entrypoint_3(void *);
void _idflame_entrypoint_3(void *, s32, void *, s32, s32);
void _idflame_entrypoint_2(void *);
void _idtwinklea_entrypoint_0(void *, s32, void *, s32, s32);
void _idtwinklea_entrypoint_1(void *);
void _idtwinklecolour_entrypoint_4(void *, s32, void *, s32, s32);
void _idtwinklecolour_entrypoint_3(void *);

struct IdWorldmakeEntry D_80800AB0_idworldmake[16] BT_DATA(4, overlays_id_worldmake, 0x0) = {
    {_idlight_entrypoint_2, _idlight_entrypoint_1},
    {_idscroll_entrypoint_2, _idscroll_entrypoint_1},
    {func_800EDB20, func_800EDAF4},
    {_idwater_entrypoint_3, _idwater_entrypoint_2},
    {_idglow_entrypoint_2, _idglow_entrypoint_1},
    {_idwave_entrypoint_2, _idwave_entrypoint_1},
    {_idglowa_entrypoint_3, _idglowa_entrypoint_2},
    {_idflash_entrypoint_2, _idflash_entrypoint_1},
    {_idflasha_entrypoint_3, _idflasha_entrypoint_2},
    {func_800EC898, func_800EC890},
    {_idwibble_entrypoint_2, _idwibble_entrypoint_1},
    {_idbounce_entrypoint_4, _idbounce_entrypoint_3},
    {_idtwinkle_entrypoint_4, _idtwinkle_entrypoint_3},
    {_idflame_entrypoint_3, _idflame_entrypoint_2},
    {_idtwinklea_entrypoint_0, _idtwinklea_entrypoint_1},
    {_idtwinklecolour_entrypoint_4, _idtwinklecolour_entrypoint_3},
};
