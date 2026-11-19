#include "1EA78C0_types.h"
#include "prop_flag_mapping.inc"


void func_800CDFD0(void **arg0) {
    s32 _gspropctrl_entrypoint_0(void *);
    s32 _gspropctrl_entrypoint_1(void *, s32 *);
    s32 *func_800BDD24(s32 *);
    int func_800CE1A8(void *, void *, s32);
    s32 func_800CE21C(s32);
    void func_800D5318(void *, BtIntPtr);
    s32 func_800DAB54(s32 *, s32);
    u32 func_800E9D68(BtUIntPtr);
    s32 func_800E9DD4(BtUIntPtr);
    void func_800EC370(void **, void *);
    extern s32 D_8012B020;
    s32 pad;
    s32 position[3];
    s32 center[3];
    BtUIntPtr end;
    BtUIntPtr prop;
    s16 shortPosition[3];
    u32 *cells;
    struct PropFlags { u8 padding[19]; BT_BITFIELD_ORDER(u8 flag : 1, u8 rest : 7); BT_BITFIELD_ORDER(u8 rest : 7, u8 flag : 1); };
    s32 id;
    s32 radius;
    s32 cell;

    id = func_800CE21C(((Obj1EA78C0_arg0 *)arg0)->unk24 >> 22);
    if (id != -1 && func_800DAB54(&D_8012B020, id) == 1) {
        func_800EC370(arg0, shortPosition);
        position[0] = shortPosition[0];
        position[1] = shortPosition[1];
        position[2] = shortPosition[2];
        cells = (u32 *)func_800BDD24(position);
        if (*cells != 0) {
        do {
            prop = func_800E9D68(*cells);
            end = prop + func_800E9DD4(*cells) * 0x14;
            while (prop < end) {
                if (_gspropctrl_entrypoint_0((void *)prop) == id) {
                    radius = _gspropctrl_entrypoint_1((void *)prop, center);
                    if (center[1] - radius < position[1] && position[1] < center[1] + radius) {
                        if (((struct PropFlags *)prop)->flag) {
                            if (func_800CE1A8(position, center, radius)) {
                                func_800D5318((void *)prop, (BtIntPtr)arg0);
                            }
                        } else if (center[0] - radius < position[0] && position[0] < center[0] + radius &&
                                   center[2] - radius < position[2] && position[2] < center[2] + radius) {
                            func_800D5318((void *)prop, (BtIntPtr)arg0);
                        }
                    }
                }
                prop += 0x14;
            }
            cells++;
        } while (*cells != 0);
        }
    }
}                                     typedef struct { s32 unk0; u8 pad4[0x4]; s32 unk8; } Obj1EA78C0_arg1; /* offsets.py genstruct: fields from raw offsets on arg1; rename once understood */

int func_800CE1A8(void *arg0, void *arg1, s32 arg2) {

    s32 temp_a0;
    s32 temp_a1;
    s32 temp_a3;
    s32 temp_f16;
    s32 temp_t0;
    s32 temp_v1;

    temp_f16 = (s32) ((f32) arg2 * 1.4142135f);
    temp_v1 = ((((Obj1EA78C0_arg0 *)arg0)->unk0) - (((Obj1EA78C0_arg1 *)arg1)->unk0)) + temp_f16;
    temp_a3 = (((Obj1EA78C0_arg0 *)arg0)->unk8) - (((Obj1EA78C0_arg1 *)arg1)->unk8);
    temp_t0 = temp_v1 + temp_a3;
    temp_a0 = temp_v1 - temp_a3;
    temp_a1 = temp_f16 * 2;
    if ((temp_t0 < 0) || (temp_a1 < temp_t0)) {
        return 0;
    }
    return temp_a0 > 0 && temp_a0 < temp_a1;
}

s32 func_800CE21C(s32 arg0) {
    extern PropFlagMapping D_8011AA10[7];
    s32 i;

    for (i = 0; i < 7; i++) {
        if (arg0 == D_8011AA10[i].propId) {
            return D_8011AA10[i].flagIndex;
        }
    }
    return -1;
}

void func_800CE2DC(void) {
    void func_800DAA8C(void *bitfield, s32 arg1, s32 length);
    extern s32 D_8012B020;
    func_800DAA8C(&D_8012B020, 7, 2);
}    typedef struct { u8 pad0[0x4]; s32 unk4; u8 pad8[0x2]; u8 unkA; } Obj1EA78C0_func_800CE308_var_s0; /* offsets.py genstruct: fields from raw offsets on var_s0; rename once understood */

void func_800CE308(void) {
    void func_800BE52C(void *begin, void *end);
    void func_800DAAF8(void *bitfield, s32 index, s32 set);
    void func_800DAB8C(void *bitfield, s32 set);
    u32 func_800E9D68(BtUIntPtr);
    void * func_800E9D90(void *cube);
    s32 func_800E9DD4(BtUIntPtr);
    extern s32 D_8012B020;
    BtUIntPtr sp34;
    u32 sp30;
    BtUIntPtr var_s0;
    BtUIntPtr var_s1;

    func_800DAB8C(&D_8012B020, 0);
    func_800BE52C(&sp34, &sp30);
    for (; sp34 < sp30; sp34 += 8) {
        if (func_800E9DD4(sp34) != 0) {
            var_s0 = func_800E9D68(sp34);
            var_s1 = func_800E9D90(sp34);
            if (var_s0 < var_s1) {
                do {
                    if (!((((Obj1EA78C0_func_800CE308_var_s0 *)var_s0)->unk4) & 1)) {
                        func_800DAAF8(&D_8012B020, ((Obj1EA78C0_func_800CE308_var_s0 *)var_s0)->unkA, 1);
                    }
                    var_s0 += 0x14;
                } while (var_s0 < var_s1);
            }
        }
    }
}
