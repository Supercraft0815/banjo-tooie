#include "common.h"
#include "core2/particle_internal.h"
#include "fill_rectangle_setup.inc"
void func_800BBD60(void *arg0, BtIntPtr arg1) {
    BtIntPtr func_800D674C(s32);
    void *func_800DE448(f32 *, f32 *, f32, f32 *, BtIntPtr);
    void func_800DF5D8(u32, u32, u32, s32);
    void func_800DF830(s32);
    BtIntPtr image;
    f32 pos[3];
    u8 *entry;
    s32 visible;
    struct Flags { BT_BITFIELD_ORDER(u8 visible : 1, u8 rest : 7); BT_BITFIELD_ORDER(u8 rest : 7, u8 visible : 1); };

    image = func_800D674C(*(u16 *)((u8 *)arg0 + 2));
    entry = (u8 *)((ParticleEmitter *)arg0)->begin;
    while (entry < (u8 *)((ParticleEmitter *)arg0)->end) {
        pos[0] = (f32)(*(s16 *)(entry + 6) + *(s16 *)((u8 *)arg0 + 0xC));
        pos[1] = (f32)(*(s16 *)(entry + 8) + *(s16 *)((u8 *)arg0 + 0xE));
        pos[2] = (f32)(*(s16 *)(entry + 0xA) + *(s16 *)((u8 *)arg0 + 0x10));
        func_800DF5D8(*((u8 *)arg0 + 0x80), *((u8 *)arg0 + 0x81), *((u8 *)arg0 + 0x82),
            (s32)(*(f32 *)(entry + 0xC) * (f32)(u32)*((u8 *)arg0 + 0x83)));
        func_800DF830(*((u8 *)arg0 + 0x53));
        visible = func_800DE448(pos, (f32 *)(entry + 0x10), (f32)*(s16 *)(entry + 0x30) * 0.00390625f, NULL, image) ? 1 : 0;
        ((struct Flags *)(entry + 0x39))->visible |= visible;
        entry += 0x3C;
    }
}           typedef struct { u8 pad0[0x60]; f32 unk60; u8 pad64[0x8]; f32 unk6C; } Obj1E95650_func_800BBED8_var_s0; /* offsets.py genstruct: fields from raw offsets on var_s0; rename once understood */ typedef struct { u16 unk0; u16 unk2; u8 pad4[0x6]; u8 unkA; u8 padB[0x1]; s16 unkC; s16 unkE; s16 unk10; u8 pad12[0x41]; u8 unk53; u8 pad54[0x8]; f32 unk5C; u8 pad60[0x20]; u8 unk80; u8 unk81; u8 unk82; u8 unk83; u8 pad84[0x8]; u8 * unk8C; u8 * unk90; } Obj1E95650_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void func_800BBED8(void *arg0, f32 arg1, f32 *arg2) {
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F13C4(f32, f32);
    f32 mlAbsF(f32);
    f32 *temp_s1;
    f32 temp_f20;
    f32 temp_f2;
    f32 value;
    s32 var_s2;
    u8 *var_s0;

    temp_f20 = (((Obj1E95650_arg0 *)arg0)->unk5C) * 0.5f;
    var_s0 = arg0;
    var_s2 = 0;
    do {
        temp_s1 = (f32 *)((s8 *)arg2 + var_s2);
        if ((((Obj1E95650_func_800BBED8_var_s0 *)var_s0)->unk6C) != 0.0f) {
            value = mlAbsF(func_800F13C4((((Obj1E95650_func_800BBED8_var_s0 *)var_s0)->unk60) + arg1, (((Obj1E95650_arg0 *)arg0)->unk5C)) - temp_f20);
            temp_f2 = (((Obj1E95650_func_800BBED8_var_s0 *)var_s0)->unk6C);
            *temp_s1 *= func_800F10B4(value, 0.0f, temp_f20, 1.0f - temp_f2, temp_f2 + 1.0f);
        }
        var_s2 += 4;
        var_s0 += 4;
    } while (var_s2 != 0xC);
}

void func_800BBFDC(void *arg0, BtIntPtr arg1) {
    void func_800BBED8(void *, f32, f32 *);
    BtIntPtr func_800D674C(s32);
    void func_800E2440(s32, s32, s32);
    void func_800E24B4(s32);
    void func_800E24D8(s32);
    void func_800E24F8(s32, s32, s32);
    void func_800E2530(f32);
    void func_800E2588(u32);
    void func_800E2594(BtUIntPtr arg0, void *arg1);
    BT_IDO_ONLY(s32 func_800E2720(BtIntPtr, s32, s32, f32 *, f32 *, s32);) BT_NATIVE_ONLY(s32 func_800E2720(u8 *, s32, s32, f32 *, f32 *, s32);)
    s32 func_800E28A4(u8 *arg0, s32 arg1, s32 arg2, f32 *arg3, f32 *arg4, f32 *arg5, s32 arg6);
    void func_800E2A14(BtIntPtr arg0);
    void func_800EFA4C(f32 *, f32, f32, f32);
    struct DrawFlags { BT_BITFIELD_ORDER(u8 drawn : 1, u8 rest : 7); BT_BITFIELD_ORDER(u8 rest : 7, u8 drawn : 1); };
    BtIntPtr temp_s0;
    f32 sp78[3];
    f32 sp6C[3];
    f32 sp60[3];
    s32 var_s4;
    u8 *var_s0;

    temp_s0 = func_800D674C((*(u16 *)((s8 *)(arg0) + (2))));
    var_s4 = ((*(u16 *)arg0) & 0x800) ? 1 : 0;
    if (!((*(u16 *)arg0) & 0x20) && (((*(u8 *)((s8 *)(arg0) + (0x80))) != 0xFF) || ((*(u8 *)((s8 *)(arg0) + (0x81))) != 0xFF) || ((*(u8 *)((s8 *)(arg0) + (0x82))) != 0xFF) || ((*(u8 *)((s8 *)(arg0) + (0x83))) != 0xFF))) {
        func_800E2588((*(u8 *)((s8 *)(arg0) + (0x53))));
        func_800E24F8((*(u8 *)((s8 *)(arg0) + (0x80))), (*(u8 *)((s8 *)(arg0) + (0x81))), (*(u8 *)((s8 *)(arg0) + (0x82))));
        func_800E2440(
            (*(u8 *)((u8 *)arg0 + 0x80)) < 8 ? 0 : (*(u8 *)((u8 *)arg0 + 0x80)) - 8,
            (*(u8 *)((u8 *)arg0 + 0x81)) < 8 ? 0 : (*(u8 *)((u8 *)arg0 + 0x81)) - 8,
            (*(u8 *)((u8 *)arg0 + 0x82)) < 8 ? 0 : (*(u8 *)((u8 *)arg0 + 0x82)) - 8);
        func_800E24B4(0);
    } else {
        func_800E2588((*(u8 *)((s8 *)arg0 + 0x53)) ? 2 : 0);
    }
    func_800E24D8((*(u16 *)arg0) & 0x200 ? 1 : 0);
    func_800E2594(arg1, temp_s0);
    if ((*(u16 *)((s8 *)(arg0) + (0))) & 1) {
        func_800EFA4C(sp6C, 90.0f, 0.0f, 0.0f);
    }
    var_s0 = (u8 *)((ParticleEmitter *)arg0)->begin;
    if (var_s0 < (u8 *)((ParticleEmitter *)arg0)->end) {
        do {
            sp78[0] = (f32) ((*(s16 *)((s8 *)(var_s0) + (6))) + (*(s16 *)((s8 *)(arg0) + (0xC))));
            sp78[1] = (f32) ((*(s16 *)((s8 *)(var_s0) + (8))) + (*(s16 *)((s8 *)(arg0) + (0xE))));
            sp78[2] = (f32) ((*(s16 *)((s8 *)(var_s0) + (0xA))) + (*(s16 *)((s8 *)(arg0) + (0x10))));
            sp60[0] = sp60[1] = sp60[2] = (f32) (*(s16 *)((s8 *)(var_s0) + (0x30))) * 0.00390625f;
            if ((*(f32 *)((s8 *)(arg0) + (0x5C))) != 0.0f) {
                func_800BBED8(arg0, (*(f32 *)((s8 *)(var_s0) + (0x1C))), sp60);
            }
            if ((*(u16 *)((s8 *)(arg0) + (0))) & 1) {
                ((struct DrawFlags *)((u8 *)var_s0 + 0x39))->drawn |= func_800E28A4(arg1, (s16) (*(s16 *)((s8 *)(var_s0) + (0x2C))) >> 8, var_s4, sp78, sp6C, sp60, (s32) ((*(f32 *)((s8 *)(var_s0) + (0xC))) * (f32) (u32) (*(u8 *)((s8 *)(arg0) + (0x83)))));
            } else {
                func_800E2530((*(f32 *)((s8 *)(var_s0) + (0x18))));
                ((struct DrawFlags *)((u8 *)var_s0 + 0x39))->drawn |= func_800E2720(BT_NATIVE_ONLY((u8 *)) arg1, (s16) (*(s16 *)((s8 *)(var_s0) + (0x2C))) >> 8, var_s4, sp78, sp60, (s32) ((*(f32 *)((s8 *)(var_s0) + (0xC))) * (f32) (u32) (*(u8 *)((s8 *)(arg0) + (0x83)))));
            }
            var_s0 += 0x3C;
        } while (var_s0 < (u8 *)((ParticleEmitter *)arg0)->end);
    }
    func_800E2A14(arg1);
}

void func_800BC358(void *arg0, BtIntPtr arg1, s32 arg2) {
    void func_800BBD60(void *, BtIntPtr);

    if (((*(u16 *)arg0 & 4) ^ arg2) == 0) {
        switch (((Obj1E95650_arg0 *)arg0)->unkA) {
        case 0:
            func_800BBD60(arg0, arg1);
            break;
        case 7:
            func_800BBFDC(arg0, arg1);
            break;
        }
    }
}

/* extern */

void func_800BC3B8(void *arg0, s32 arg1) {
    void func_800BC358(void *, BtIntPtr, s32);
    func_800BC358(arg0, arg1, 4);
    func_800BC358(arg0, arg1, 0);
}

void* func_800BC3F0(void* arg0) 
{
    BT_NATIVE_ONLY(void *defrag(void *);) return defrag(arg0);
}
void func_800BC410(Gfx **arg0, s32 arg1, s32 arg2, s32 arg3) {
    void func_800BC474(Gfx **, s32, s32, s32, s32, s32, s32, s32);
    void func_800E7FCC(s32* arg0);
    s32 sp[4];

    func_800E7FCC(sp);
    func_800BC474(arg0, sp[0], sp[1], sp[2], sp[3], arg1, arg2, arg3);
}

void func_800BC474(Gfx **arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {

    gSPDisplayList((*arg0)++, FILL_RECT_LIST(D_8011A730));
    gDPSetFillColor((*arg0)++,
        (u32)(((arg5 << 8) & 0xF800) | ((arg6 << 3) & 0x7C0) | ((arg7 >> 2) & 0x3E) | 1) << 16 |
        (((arg5 << 8) & 0xF800) | ((arg6 << 3) & 0x7C0) | ((arg7 >> 2) & 0x3E) | 1));
    gDPFillRectangle((*arg0)++,
        (arg1 > 0 ? arg1 : 0),
        (arg2 > 0 ? arg2 : 0),
        (arg1 + arg3 - 1 > 0 ? arg1 + arg3 - 1 : 0),
        (arg2 + arg4 - 1 > 0 ? arg2 + arg4 - 1 : 0));
}

/* extern */

void func_800BC580(Gfx **arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    void func_800BC474(Gfx **, s32, s32, s32, s32, s32, s32, s32);
    func_800BC474(arg0, arg1, arg2, arg3, arg4, 0, 0, 0);
}

void func_800BC5B0(Gfx **arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {

    gSPDisplayList((*arg0)++, FILL_RECT_LIST(D_8011A730));
    gDPSetFillColor((*arg0)++, 0xFFFCFFFC);
    gDPFillRectangle((*arg0)++,
        (arg1 > 0 ? arg1 : 0),
        (arg2 > 0 ? arg2 : 0),
        (arg1 + arg3 - 1 > 0 ? arg1 + arg3 - 1 : 0),
        (arg2 + arg4 - 1 > 0 ? arg2 + arg4 - 1 : 0));
}
