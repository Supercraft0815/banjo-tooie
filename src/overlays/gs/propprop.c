#include "common.h"

typedef struct { s32 unk0; s32 unk4; s32 unk8; } Objpropprop_arg1; /* offsets.py genstruct: fields from raw offsets on arg1; rename once understood */ typedef struct { u8 pad0[0x4]; s16 unk4; s16 unk6; s16 unk8; } Objpropprop_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */ void gspropprop_entrypoint_0(void *arg0, void *arg1) {
    (((Objpropprop_arg1 *)arg1)->unk0) = (s32) (((Objpropprop_arg0 *)arg0)->unk4);
    (((Objpropprop_arg1 *)arg1)->unk4) = (s32) (((Objpropprop_arg0 *)arg0)->unk6);
    (((Objpropprop_arg1 *)arg1)->unk8) = (s32) (((Objpropprop_arg0 *)arg0)->unk8);
}

/* extern */

f32 func_8080001C_gspropprop(BT_PARAM_OR_VOID(u16 *prop)) {
    BT_IDO_ONLY(s32 _gsproplookup_entrypoint_1();) BT_NATIVE_ONLY(s16 _gsproplookup_entrypoint_1(u16 *);)
    s32 func_800B0CFC(BtIntPtr);
    BtIntPtr func_800BFC94(s32);
    return (f32) func_800B0CFC(func_800BFC94(_gsproplookup_entrypoint_1(BT_NATIVE_ONLY(prop))));
}

/* extern */

f32 func_80800050_gspropprop(BT_PARAM_OR_VOID(u16 *prop)) {
    BT_IDO_ONLY(s32 _gsproplookup_entrypoint_0();) BT_NATIVE_ONLY(s16 _gsproplookup_entrypoint_0(u16 *);)
    f32 func_800B2354(BtIntPtr);
    BtIntPtr func_800B2840(BtIntPtr);
    s32 func_800BFC34(s32);
    return func_800B2354(func_800B2840(func_800BFC34(_gsproplookup_entrypoint_0(BT_NATIVE_ONLY(prop)))));
}

f32 gspropprop_entrypoint_1(void *arg0) {
    typedef struct {
        BT_BITFIELD_ORDER(u32 pad0 : 22, u32 pad3 : 2);
        u32 scale : 8;
        BT_BITFIELD_ORDER(u32 pad3 : 2, u32 pad0 : 22);
        u8 pad4[4];
        BT_BITFIELD_ORDER(u32 pad8 : 16, u32 padB2 : 1);
        BT_BITFIELD_ORDER(u32 scale2 : 8, u32 flag : 1);
        u32 padB : 6;
        BT_BITFIELD_ORDER(u32 flag : 1, u32 scale2 : 8);
        BT_BITFIELD_ORDER(u32 padB2 : 1, u32 pad8 : 16);
    } Prop;
    Prop *prop = arg0;

    if (prop->flag) {
        return func_80800050_gspropprop(BT_NATIVE_ONLY(arg0)) * 0.5f * prop->scale2 * 0.01f;
    } else {
        return func_8080001C_gspropprop(BT_NATIVE_ONLY(arg0)) * 0.5f * prop->scale * 0.01f;
    }
}

void gspropprop_entrypoint_2(void *prop) {
    typedef struct {
        s16 frameCnt;
        u8 pad2[14];
        struct {
            BT_BITFIELD_ORDER(u32 bit31 : 4, u32 unused : 21);
            BT_BITFIELD_ORDER(u32 bit27 : 3, u32 bit22 : 2);
            u32 bit24 : 2;
            BT_BITFIELD_ORDER(u32 bit22 : 2, u32 bit27 : 3);
            BT_BITFIELD_ORDER(u32 unused : 21, u32 bit31 : 4);
        } unk10;
    } Sprite;
    typedef struct {
        u8 pad0[3];
        BT_BITFIELD_ORDER(u8 pad3 : 6, u8 pad3b : 1);
        u8 isMirrored : 1;
        BT_BITFIELD_ORDER(u8 pad3b : 1, u8 pad3 : 6);
        u8 pad4[6];
        BT_BITFIELD_ORDER(u8 frame : 5, u8 padA : 3);
        BT_BITFIELD_ORDER(u8 padA : 3, u8 frame : 5);
        BT_BITFIELD_ORDER(u8 padB : 2, char : 0);
        BT_BITFIELD_ORDER(u8 actorMirrored : 1, u8 padBb : 5);
        BT_BITFIELD_ORDER(u8 padBb : 5, u8 actorMirrored : 1; u8 padB : 2);
    } SpriteProp;
    BT_IDO_ONLY(s32 _gsproplookup_entrypoint_1();) BT_NATIVE_ONLY(s16 _gsproplookup_entrypoint_1(u16 *);)
    s32 func_8001211C();
    BtIntPtr func_800BFC94(s32);
    void *func_800EC3E8(void *data);
    Sprite *var_v0;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 sp3C;
    s32 frame_count;
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 var_t5;
    s32 var_v1;

    var_v0 = ((u32)(((u16 *)prop)[5]) & 1)
        ? (Sprite *)func_800EC3E8(*(s32 *)prop)
        : (Sprite *)func_800BFC94(_gsproplookup_entrypoint_1(prop));
    if ((var_v0 != NULL) && (var_v0->unk10.bit27 != 0)) {
        sp48 = var_v0->unk10.bit31;
        sp44 = var_v0->unk10.bit27;
        sp40 = var_v0->unk10.bit24;
        sp3C = var_v0->unk10.bit22;
        frame_count = var_v0->frameCnt;
        sp34 = (sp44 == 1) || (sp44 == 2U);
        sp30 = (sp44 == 3) ? frame_count : (frame_count - sp34) * 2;
        sp2C = (s32)((((u32)(((u16 *)prop)[5]) << 0x15) >> 0x1B) * sp30) / 32;
        var_v1 = (((func_8001211C() % (sp30 * sp48)) / sp48) + sp2C) % sp30;
        var_t5 = 0;
        switch (sp40) {
            default:
                sp40 = 0;
                break;
            case 1:
                sp40 = (((((u32)(((u16 *)prop)[5]) << 0x15) >> 0x1B) & 2)) ? 1 : 0;
                break;
            case 2:
                sp40 = 1;
                break;
            case 3:
                sp40 = (((u32)(((u16 *)prop)[1]) << 0x1E) >> 0x1F);
                break;
        }
        switch (sp44) {
            case 4:
                var_t5 = frame_count <= var_v1;
            case 1:
                sp3C = frame_count <= var_v1;
                break;
            case 2:
                var_t5 = frame_count <= var_v1;
            default:
                switch (sp3C) {
                    case 1:
                        sp3C = ((((u32)(((u16 *)prop)[5]) << 0x15) >> 0x1B) & 1) ? 1 : 0;
                        break;
                    case 2:
                        sp3C = 1;
                        break;
                    default:
                        if (((u32)(((u16 *)prop)[5])) & 1) {
                            sp3C = (((u32)(((u32 *)prop)[2]) << 0x1A) >> 0x1F);
                        } else {
                            sp3C = (((u32)(((u16 *)prop)[1]) << 0x1E) >> 0x1F);
                        }
                        if (1) break;
                }
                break;
        }
        if (sp3C ^ sp40 ^ var_t5) {
            var_v1 = sp30 - var_v1;
        }
        var_v1 += sp34 ? sp40 : -sp40;
        var_v1 = (var_v1 < 0) ? var_v1 + frame_count : var_v1 % frame_count;
        ((SpriteProp *)prop)->frame = var_v1;
        if ((u32)(((u16 *)prop)[5]) & 1) {
            ((SpriteProp *)prop)->actorMirrored = sp3C;
        } else {
            ((SpriteProp *)prop)->isMirrored = sp3C;
        }
    }
}

/* extern */

void gspropprop_entrypoint_3(void *arg0, BtIntPtr arg1) {
    typedef struct {
        u32 pad0[2];
        BT_BITFIELD_ORDER(u32 pad8 : 30, u32 padB : 1);
        u32 isModel : 1;
        BT_BITFIELD_ORDER(u32 padB : 1, u32 pad8 : 30);
    } Prop;
    BT_IDO_ONLY(s32 _gsproplookup_entrypoint_0();) BT_NATIVE_ONLY(s16 _gsproplookup_entrypoint_0(u16 *);)
    BT_IDO_ONLY(s32 _gsproplookup_entrypoint_1();) BT_NATIVE_ONLY(s16 _gsproplookup_entrypoint_1(u16 *);)
    void func_800BFAD0(BtIntPtr, f32 *, f32 *, f32, s32);
    void func_800BFB58(BtIntPtr, void *, f32, s32, s32, s32, s32, s32, s32);
    void func_800EE88C(f32 *, s16 *);
    f32 sp54[3];
    f32 sp48[3];
    s32 model;
    s32 sprite;

    func_800EE88C(sp54, (s16 *)arg0 + 2);
    if (((Prop *)arg0)->isModel) {
        model = _gsproplookup_entrypoint_0(arg0);
        sp48[0] = 0.0f;
        sp48[1] = 2.0f * (u32)((u8 *)arg0)[2];
        sp48[2] = 2.0f * (u32)((u8 *)arg0)[3];
        func_800BFAD0(arg1, sp54, sp48, (u32)((u8 *)arg0)[10] * 0.01f, model);
    } else {
        sprite = _gsproplookup_entrypoint_1(arg0);
        func_800BFB58(arg1, sp54, (f32)(*(u32 *)arg0 << 22 >> 24) * 0.01f, sprite,
            ((u16 *)arg0)[0] & 7, (u32)((u16 *)arg0)[1] >> 13,
            *(u32 *)arg0 << 19 >> 29, *(u32 *)arg0 << 30 >> 31,
            (u32)((u16 *)arg0)[5] >> 11);
    }
}
