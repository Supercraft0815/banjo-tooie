#include "common.h"

/* extern */

f32 suexpression_entrypoint_0(u8 arg0) {
    void *func_80800CF4_suexpression(s32);
    void *temp_v0;

    temp_v0 = func_80800CF4_suexpression(arg0);
    if (temp_v0 == NULL) {
        return 0.0f;
    }
    return (f32) *(s16 *) temp_v0;
}

u8 suexpression_entrypoint_1(u8 arg0) {
    void *func_80800CF4_suexpression(s32 arg0);
    void *temp_v0;

    temp_v0 = func_80800CF4_suexpression(arg0);
    if (temp_v0 == NULL) {
        return 0U;
    }
    return *((u8 *) temp_v0 + 4);
}

s32 suexpression_entrypoint_2(u8 arg0, void *arg1, f32 *arg2) {
    void *func_80800CF4_suexpression(s32);
    Actor *func_80106790(Unk80132ED0 *);
    void func_80103DFC(Actor *, f32 *);
    void func_800DBEFC(s32 *, s32, f32 *);
    s32 pad;
    s16 *sp18;
    Actor *actor;

    sp18 = func_80800CF4_suexpression(arg0);
    actor = func_80106790(arg1);
    if (sp18 == NULL) {
        func_80103DFC(actor, arg2);
    } else if (sp18[1] != 0) {
        if (actor->unk7C_12) {
            func_800DBEFC(((Unk80132ED0 *)arg1)->unk4, sp18[1], arg2);
        } else {
            arg2[0] = actor->position[0];
            arg2[1] = sp18[0] * actor->scale + actor->position[1];
            arg2[2] = actor->position[2];
        }
    } else {
        arg2[0] = actor->position[0];
        arg2[1] = sp18[0] * actor->scale + actor->position[1];
        arg2[2] = actor->position[2];
    } BT_NATIVE_ONLY(return 0;)
}

/* extern */

void suexpression_entrypoint_3(s16 arg0, s32 *arg1, s32 *arg2, s32 *arg3) {
    s32 _suexpressjoint_entrypoint_0(s16);
    s32 _suexpressmorph_entrypoint_0(s16);
    *arg3 = 0x14;
    *arg1 = _suexpressmorph_entrypoint_0(arg0);
    *arg2 = _suexpressjoint_entrypoint_0(arg0);
    *arg3 = (*arg3 + 3) & 0x7FFFFFFC;
    *arg1 = (*arg1 + 3) & 0x7FFFFFFC;
    *arg2 = (*arg2 + 3) & 0x7FFFFFFC;
}    typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s8 unk10; s8 unk11; s8 unk12; s8 unk13; u8 pad14[0x81]; u8 unk95; } Objexpression_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void suexpression_entrypoint_4(u8 *arg0, s16 arg1) {
    s32 _suexpressjoint_entrypoint_1(u8 *, s16, s16 *);
    s32 _suexpressmorph_entrypoint_3(u8 *, s16, s16 *);
    s16 temp_v0;
    s16 temp_v0_2;

    temp_v0 = (((Objexpression_arg0 *)arg0)->unk2);
    if (temp_v0 != 0) {
        _suexpressmorph_entrypoint_3((u8 *)((s8 *)arg0 + temp_v0), arg1, (s16 *)arg0);
    }
    temp_v0_2 = (((Objexpression_arg0 *)arg0)->unk0);
    if (temp_v0_2 != 0) {
        _suexpressjoint_entrypoint_1((u8 *)((s8 *)arg0 + temp_v0_2), arg1, (s16 *)arg0);
    }
}

/* extern */

void suexpression_entrypoint_5(BT_IDO_ONLY(u8 *arg0) BT_PASS2(u8 *arg0, s32 bt_a1)) {
    s32 _suexpressmorph_entrypoint_4(BT_IDO_ONLY(void *) BT_PASS2(void *, s32));
    s16 temp_v0;

    temp_v0 = (((Objexpression_arg0 *)arg0)->unk2);
    if (temp_v0 != 0) {
        _suexpressmorph_entrypoint_4(BT_IDO_ONLY((void *)((s8 *)arg0 + temp_v0)) BT_PASS2((void *)((s8 *)arg0 + temp_v0), bt_a1));
    }
}

/* extern */

void suexpression_entrypoint_6(u8 *arg0, s16 arg1, s32 arg2, s32 arg3, s32 arg4) {
    void _suexpressjoint_entrypoint_2(void *arg0, s16 arg1);
    void _suexpressmorph_entrypoint_5(s16 *arg0, s16 arg1);
    s16 temp_v0;
    s16 temp_v0_2;

    if (arg3 == 0) {
        (((Objexpression_arg0 *)arg0)->unk2) = 0;
    } else {
        (((Objexpression_arg0 *)arg0)->unk2) = arg2;
    }
    if (arg4 == 0) {
        (((Objexpression_arg0 *)arg0)->unk0) = 0;
    } else {
        (((Objexpression_arg0 *)arg0)->unk0) = (s16) (arg2 + arg3);
    }
    temp_v0 = (((Objexpression_arg0 *)arg0)->unk2);
    if (temp_v0 != 0) {
        _suexpressmorph_entrypoint_5((u8 *)((s8 *)arg0 + temp_v0), arg1);
    }
    temp_v0_2 = (((Objexpression_arg0 *)arg0)->unk0);
    if (temp_v0_2 != 0) {
        _suexpressjoint_entrypoint_2((u8 *)((s8 *)arg0 + temp_v0_2), arg1);
    }
    (((Objexpression_arg0 *)arg0)->unk6) = 0;
    (((Objexpression_arg0 *)arg0)->unk4) = 0;
    (((Objexpression_arg0 *)arg0)->unkA) = 0;
    (((Objexpression_arg0 *)arg0)->unk8) = 0;
    (((Objexpression_arg0 *)arg0)->unk10) = 0x4B;
    (((Objexpression_arg0 *)arg0)->unk11) = 0x4B;
    (((Objexpression_arg0 *)arg0)->unk12) = 1;
    (((Objexpression_arg0 *)arg0)->unkE) = 0;
    (((Objexpression_arg0 *)arg0)->unk13) = 0;
    (((Objexpression_arg0 *)arg0)->unkC) = arg1;
}

void *suexpression_entrypoint_7(Actor *arg0, s32 arg1, s16 arg2) {
    u32 *func_80100074(Actor *, u32, u32);
    struct ExpressionFlags {
        u8 unused;
        u8 high : 4;
        u8 index : 2;
        u8 low : 2;
    };
    void *data;
    s32 sp28;
    s32 sp24;
    s32 sp20;

    suexpression_entrypoint_3(arg2, &sp28, &sp24, &sp20);
    data = func_80100074(arg0, arg1, sp24 + sp28 + sp20);
    suexpression_entrypoint_6(data, arg2, sp20, sp28, sp24);
    ((struct ExpressionFlags *)&arg0->pad94)->index = arg1 + 1;
    return data;
}

/* extern */

void suexpression_entrypoint_8(void *arg0, s32 arg1) {
    u32 *func_80100074(Actor *, u32, u32);
    void *func_80100094();
    if (func_80100094() != 0) {
        func_80100074(arg0, arg1, 0);
    }
    (((Objexpression_arg0 *)arg0)->unk95) = (u8) ((((Objexpression_arg0 *)arg0)->unk95) & 0xFFF3);
}

void suexpression_entrypoint_9(void *arg0) {
    *(u8 *)((u8 *)arg0 + 0x12) = 0;
}

void suexpression_entrypoint_10(void *arg0, Unk80132ED0 *arg1, f32 *arg2) {
    void _suexpressjoint_entrypoint_3(BtIntPtr arg0, void *arg1, s32 arg2);
    void _suexpressmorph_entrypoint_1(void *);
    void func_8008FE94(s32, f32 *);
    f32 func_800EEB40(f32 *, f32 *);
    Actor *func_80106790(Unk80132ED0 *);
    s32 func_8010D23C(void);
    void suexpression_entrypoint_15(void *, void *, f32 *);
    void suexpression_entrypoint_16(void *, BtIntPtr);
    struct ExpressionHeader {
        s16 joint;
        s16 morph;
    };
    f32 position[3];
    Actor *actor;

    if (((struct ExpressionHeader *)arg0)->joint != 0) {
        _suexpressjoint_entrypoint_3(arg1, (u8 *)arg0 + ((struct ExpressionHeader *)arg0)->joint, *((u8 *)arg0 + 0x12));
    }
    if (((struct ExpressionHeader *)arg0)->morph != 0) {
        _suexpressmorph_entrypoint_1((u8 *)arg0 + ((struct ExpressionHeader *)arg0)->morph);
    }
    if (((Objexpression_arg0 *)arg0)->unk4 != 0 ||
        ((Objexpression_arg0 *)arg0)->unk6 != 0 ||
        ((Objexpression_arg0 *)arg0)->unk8 != 0 ||
        ((Objexpression_arg0 *)arg0)->unkA != 0) {
        if (arg2 != NULL) {
            suexpression_entrypoint_15(arg0, arg1, arg2);
        } else if (func_8010D23C() != 0 && *((u8 *)arg0 + 0x13) == 0) {
            actor = func_80106790(arg1);
            func_8008FE94(5, position);
            if (((Objexpression_arg0 *)arg0)->unkE == 0 ||
                func_800EEB40(actor->position, position) <
                    (f32)(((Objexpression_arg0 *)arg0)->unkE * ((Objexpression_arg0 *)arg0)->unkE)) {
                suexpression_entrypoint_15(arg0, arg1, position);
            } else {
                suexpression_entrypoint_16(arg0, (BtIntPtr)arg1);
            }
        } else {
            suexpression_entrypoint_16(arg0, (BtIntPtr)arg1);
        }
        if (*((u8 *)arg0 + 0x13) == 1) {
            *((u8 *)arg0 + 0x13) = 0;
        }
    }
    *((u8 *)arg0 + 0x12) = 1;
}

/* extern */

void suexpression_entrypoint_11(BT_IDO_ONLY(u8 *arg0) BT_PASS2(u8 *arg0, void *bt_a1)) {
    s32 _suexpressmorph_entrypoint_2(BT_IDO_ONLY(void *) BT_PASS2(void *, void *));
    s16 temp_v0;

    temp_v0 = (((Objexpression_arg0 *)arg0)->unk2);
    if (temp_v0 != 0) {
        _suexpressmorph_entrypoint_2(BT_IDO_ONLY((void *)((s8 *)arg0 + temp_v0)) BT_PASS2((void *)((s8 *)arg0 + temp_v0), bt_a1));
    }
}

void suexpression_entrypoint_12(void *arg0, f32 arg1, f32 arg2) {
    (((Objexpression_arg0 *)arg0)->unk6) = (s16) (s32) arg1;
    (((Objexpression_arg0 *)arg0)->unkA) = (s16) (s32) arg2;
}

void suexpression_entrypoint_13(void *arg0, f32 *arg1, f32 *arg2) {
    *arg1 = (f32) (((Objexpression_arg0 *)arg0)->unk4);
    *arg2 = (f32) (((Objexpression_arg0 *)arg0)->unk8);
}

void suexpression_entrypoint_14(void *arg0, f32 arg1, f32 arg2) {
    (((Objexpression_arg0 *)arg0)->unk10) = (s8) (u32) (100.0f * arg1);
    (((Objexpression_arg0 *)arg0)->unk11) = (s8) (u32) (100.0f * arg2);
}

/* extern */

void suexpression_entrypoint_15(void *arg0, void *arg1, f32 *arg2) {
    f32 func_80013728(f32);
    f32 func_800F0E7C(f32, f32);
    f32 func_800F1828(f32 *, f32 *);
    s32 func_800F1E6C(f32 *, f32 *, f32 *);
    s32 suexpression_entrypoint_2(u8, void *, f32 *);
    f32 sp54;
    f32 sp50;
    f32 yaw;
    f32 pitch;
    f32 sp3C[3];
    f32 limit;

    yaw = (f32) (((Unk80132ED0 *)arg1)->unk28 >> 23);
    pitch = (f32) ((u32)*(u16 *)((s8 *)arg1 + 0x26) >> 7);
    suexpression_entrypoint_2(*(u8 *)((s8 *)arg0 + 0xD), arg1, sp3C);
    func_800F1E6C(sp3C, arg2, &sp54);
    yaw = func_80013728(yaw);
    sp54 = func_800F0E7C(sp54, yaw);
    if (sp54 < ((Objexpression_arg0 *)arg0)->unk6 + yaw && yaw - ((Objexpression_arg0 *)arg0)->unk6 < sp54 && ((Objexpression_arg0 *)arg0)->unk6 != 0) {
        if (((Objexpression_arg0 *)arg0)->unk4 + yaw < sp54 && ((Objexpression_arg0 *)arg0)->unk4 < ((Objexpression_arg0 *)arg0)->unk6) {
            ((Objexpression_arg0 *)arg0)->unk4 += (sp54 - (((Objexpression_arg0 *)arg0)->unk4 + yaw)) * 0.1f;
        }
        if (sp54 < ((Objexpression_arg0 *)arg0)->unk4 + yaw && -((Objexpression_arg0 *)arg0)->unk6 < ((Objexpression_arg0 *)arg0)->unk4) {
            ((Objexpression_arg0 *)arg0)->unk4 -= (((Objexpression_arg0 *)arg0)->unk4 + yaw - sp54) * 0.1f;
        }
        sp50 = func_800F1828(sp3C, arg2);
        pitch = func_80013728(pitch);
        sp50 = func_800F0E7C(sp50, pitch);
        if (sp50 < ((Objexpression_arg0 *)arg0)->unkA + pitch && pitch - ((Objexpression_arg0 *)arg0)->unkA < sp50 && ((Objexpression_arg0 *)arg0)->unkA != 0) {
            if (((Objexpression_arg0 *)arg0)->unk8 + pitch < sp50 && ((Objexpression_arg0 *)arg0)->unk8 < ((Objexpression_arg0 *)arg0)->unkA) {
                ((Objexpression_arg0 *)arg0)->unk8 += (sp50 - (((Objexpression_arg0 *)arg0)->unk8 + pitch)) * 0.1f;
            }
            if (sp50 < ((Objexpression_arg0 *)arg0)->unk8 + pitch && -((Objexpression_arg0 *)arg0)->unkA < ((Objexpression_arg0 *)arg0)->unk8) {
                ((Objexpression_arg0 *)arg0)->unk8 -= (((Objexpression_arg0 *)arg0)->unk8 + pitch - sp50) * 0.1f;
            }
        }
        if (((Objexpression_arg0 *)arg0)->unkA * 1.5f + pitch <= sp50 || sp50 <= pitch - ((Objexpression_arg0 *)arg0)->unkA * 1.5f) {
            ((Objexpression_arg0 *)arg0)->unk8 *= 0.97f;
        }
    }
    if (((Objexpression_arg0 *)arg0)->unk6 * 1.5f + yaw <= sp54 || sp54 <= yaw - ((Objexpression_arg0 *)arg0)->unk6 * 1.5f) {
        ((Objexpression_arg0 *)arg0)->unk4 *= 0.97f;
        ((Objexpression_arg0 *)arg0)->unk8 *= 0.97f;
    }
}

void suexpression_entrypoint_16(void *arg0, BtIntPtr arg1) {
    (((Objexpression_arg0 *)arg0)->unk4) = (s16) (s32) ((f32) (((Objexpression_arg0 *)arg0)->unk4) * 0.97f);
    (((Objexpression_arg0 *)arg0)->unk8) = (s16) (s32) ((f32) (((Objexpression_arg0 *)arg0)->unk8) * 0.97f);
}

void suexpression_entrypoint_17(s16 *arg0, s32 arg1) {
    arg0[7] = arg1;
}

void suexpression_entrypoint_18(s8 *arg0, s32 arg1) {
    arg0[19] = arg1;
}

/* extern */

void suexpression_entrypoint_19(u8 *arg0, Actor *arg1) {
    void _suexpressjoint_entrypoint_4(void *joint, void *actor);
    void func_800E0AFC(void *, u8, f32, f32, f32, f32);
    BtIntPtr func_8010262C(Unk80132ED0 *, u32);
    BtIntPtr sp2C;
    BtIntPtr temp_v0_2;
    BtIntPtr temp_v0;

    temp_v0 = func_8010262C(arg1->unk0, suexpression_entrypoint_1((*(u8 *)((s8 *)(arg0) + (0xD)))));
    sp2C = temp_v0;
    if (temp_v0 != 0) {
        temp_v0_2 = (*(s16 *)((s8 *)(arg0) + (0)));
        if (temp_v0_2 != 0) {
            _suexpressjoint_entrypoint_4((u8 *)((BtIntPtr)arg0 + temp_v0_2), arg1);
        }
        if ((*(s16 *)(arg0 + 4) != 0) || ((*(s16 *)((s8 *)(arg0) + (6))) != 0) || ((*(s16 *)((s8 *)(arg0) + (8))) != 0) || ((*(s16 *)((s8 *)(arg0) + (0xA))) != 0)) {
            func_800E0AFC((void *)sp2C, 0x12, 1.0f, (f32) ((*(u8 *)((s8 *)(arg0) + (0x11))) * -(*(s16 *)((s8 *)(arg0) + (8)))) * 0.01f, (f32) ((*(u8 *)((s8 *)(arg0) + (0x10))) * (*(s16 *)(arg0 + 4))) * 0.01f, 0.0f);
            func_800E0AFC((void *)sp2C, 1, 1.0f, (f32) ((0x64 - (*(u8 *)((s8 *)(arg0) + (0x11)))) * -(*(s16 *)((s8 *)(arg0) + (8)))) * 0.01f, (f32) ((0x64 - (*(u8 *)((s8 *)(arg0) + (0x10)))) * (*(s16 *)((s8 *)(arg0) + (4)))) * 0.01f, 0.0f);
        }
    }
}

void *suexpression_entrypoint_20(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    u32 temp_t7;

    temp_t7 = (arg0->pad94 << 0xC) >> 0x1E;
    if (temp_t7 != 0) {
        return func_80100094(arg0, temp_t7 - 1);
    }
    return NULL;
}

void *func_80800CF4_suexpression(s32 arg0) {
    extern s32 D_80800D60_suexpression[300];
    u32 temp_v1;

    temp_v1 = arg0 - 0xC;
    if (temp_v1 >= 0xC6U) {
        return NULL;
    }
    return (u8 *) D_80800D60_suexpression + temp_v1 * 6;
}
/* data_to_c.py: from asm/data/overlays/su/expression.data.s */
s32 D_80800D60_suexpression[300] BT_DATA(4, overlays_su_expression, 0x0) = { 0, 0, 0, 0, 120, 0, 5898249, 134217793, 512, 4259840, 33554497, 512, 4259840, 33554497, 512, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 167772160, 0, 0, 0, 0, 0, 0, 0, 7864320, 120, 327680, 11796488, 33554532, 512, 6553600, 33554532, 512, 6553600, 33554532, 512, 13107200, 33554632, 512, 3932160, 33554522, 0, 5898240, 90, 0, 11796491, 33554682, 0, 8192000, 33554582, 512, 58982406, 50331748, 512, 6553600, 33554572, 512, 11796480, 33554632, 512, 62259204, 50331648, 0, 45875207, 150995064, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2560, 0, 0, 0, 11796480, 33554582, 512, 15728640, 33554612, 512, 9175040, 33554672, 512, 11796480, 33554832, 0, 2621440, 33554432, 0, 0, 33554432, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13107200, 33554632, 0, 13762560, 33554432, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 33554432, 1536, 4259840, 33554497, 512, 4259840, 33554497, 512, 4259840, 33554432, 2304, 0, 150995034, 2048, 0, 0, 768, 0, 50331648, 0, 0, 0, 0, 0, 50331648, 1536, 0, 100663296, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5242880, 0, 0, 6553600, 33554532, 512, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9830400, 33554522, 512, 5898240, 33554532, 512, 0, 400, 512, 0, 0, 0, 0, 0, 0, 5242880, 80, 0, 5242880, 33554432, 0, 7864320, 250, 512, 7864320, 150, 0, 9830400, 150, 0, 9830400, 150, 2048, 0, 200, 0, 16384000, 50331748, 1536, 6553600, 33554532, 512, 0, 0, 0, 0, 0, 0, 32768000, 33554482, 512, 9830400, 33554532, 512, 6553600, 33554532, 512, 0, 0, 0, 5898240, 33554552, 0, 7864320, 33554632, 512, 5898240, 33554582, 512, 7864320, 33554552, 0, 3276800, 33554482, 512, 5898240, 33554552, 0, 7864320, 33554632, 512, 5898240, 33554582, 512, 7864320, 33554552, 0, 3276800, 33554482, 512, 0, 0, 0 };
