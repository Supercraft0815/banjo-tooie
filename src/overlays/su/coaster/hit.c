#include "common.h"

OSThread *sucoasterhit_entrypoint_0(void)
{
    extern BtFnWord D_80800CB0_sucoasterhit[5];

    return (OSThread *) D_80800CB0_sucoasterhit;
}

/* extern */

void func_8080000C_sucoasterhit(Unk80132ED0 *arg0, Unk80132ED0 *arg1) {
    s32 _subaddierouteDll_entrypoint_6(Actor *arg0, void *arg1, s32 arg2, s32 arg3, f32 arg4, s32 arg5, s32 arg6);
    s32 _sucoaster_entrypoint_9(void *, s32, s32);
    s32 func_800D9058(f32);
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    struct ActorFlags {
        u8 padding[0x64];
        BT_BITFIELD_ORDER(u32 upper64 : 2, u32 lower64 : 29);
        u32 flag64 : 1;
        BT_BITFIELD_ORDER(u32 lower64 : 29, u32 upper64 : 2);
        u8 padding68[0xC];
        BT_BITFIELD_ORDER(u32 upper74 : 7, u32 lower74 : 24);
        u32 flag74 : 1;
        BT_BITFIELD_ORDER(u32 lower74 : 24, u32 upper74 : 7);
        BT_BITFIELD_ORDER(u32 upper78 : 29, char : 0);
        BT_BITFIELD_ORDER(u32 flag78 : 1, u32 lower78 : 2);
        BT_BITFIELD_ORDER(u32 lower78 : 2, u32 flag78 : 1; u32 upper78 : 29);
    };
    struct Data {
        u8 padding[0x16];
        u8 unk16;
    };
    u32 temp_t6;
    struct Data *sp30;
    Actor *temp_v0;

    temp_v0 = func_80106790(arg0);
    sp30 = func_80100094(temp_v0, 0);
    if (!((struct ActorFlags *)temp_v0)->flag78 && !((struct ActorFlags *)temp_v0)->flag74) {
        temp_v0->unk6C_0 = func_800D9058(2.0f);
        temp_t6 = temp_v0->unk70_10;
        if ((temp_t6 != 2) && (temp_t6 != 9) && (temp_t6 != 0xE) && !((struct ActorFlags *)temp_v0)->flag64 && (_sucoaster_entrypoint_9(temp_v0, 3, 3) != 0) && ((arg1->unk24 >> 22) == 0)) {
            _subaddierouteDll_entrypoint_6(temp_v0, sp30, sp30->unk16, 0, 1.0f, 0x46, 0x78);
        }
    }
}

/* extern */

void func_80800114_sucoasterhit(Unk80132ED0 *arg0, Unk80132ED0 *arg1) {
    s32 _sucoaster_entrypoint_9(void *, s32, s32);
    void *func_80100094(Actor *, u32);
    int func_801021BC(Actor *, s32);
    Actor *func_80106790(Unk80132ED0 *);
    struct ActorFlags {
        u8 padding[0x78];
        BT_BITFIELD_ORDER(u32 upper : 29, u32 lower : 2);
        u32 flag : 1;
        BT_BITFIELD_ORDER(u32 lower : 2, u32 upper : 29);
    };
    struct DataFlags {
        u8 padding[0x18];
        BT_BITFIELD_ORDER(u8 upper : 4, u8 lower : 3);
        u8 flag : 1;
        BT_BITFIELD_ORDER(u8 lower : 3, u8 upper : 4);
    };
    Actor *actor;
    struct DataFlags *data;

    actor = func_80106790(arg0);
    if (!((struct ActorFlags *)actor)->flag) {
        data = func_80100094(actor, 0);
        if ((arg1->unk24 >> 22) == 0x27D) {
            if (actor->unk70_10 != 0xF) {
                _sucoaster_entrypoint_9(actor, 0xF, 4);
            }
            data->flag = 1;
        } else if (func_801021BC(actor, 0xB)) {
            _sucoaster_entrypoint_9(actor, 0xB, 4);
        }
    }
}

/* extern */

void func_808001C8_sucoasterhit(Unk80132ED0 *arg0, BtIntPtr arg1) {
    Actor* func_80106790(Unk80132ED0 *);
    s32 _sucoaster_entrypoint_9(void *, s32, s32);
    struct Flags {
        u8 padding[0x78];
        BT_BITFIELD_ORDER(u32 upper : 29, u32 lower : 2);
        u32 flag : 1;
        BT_BITFIELD_ORDER(u32 lower : 2, u32 upper : 29);
    };
    Actor *temp_v0;

    temp_v0 = func_80106790(arg0);
    if (!((struct Flags *)temp_v0)->flag) {
        _sucoaster_entrypoint_9(temp_v0, 0xC, 5);
    }
}

/* extern */

s32 func_80800208_sucoasterhit(BtIntPtr arg0, void *arg1, BtIntPtr arg2, s32 *arg3, s32 *arg4) {
    s32 func_800F0E28(s32, s32, ...);
    struct HitData {
        u8 padding[0x24];
        BT_BITFIELD_ORDER(u32 id : 10, u32 lower : 22);
        BT_BITFIELD_ORDER(u32 lower : 22, u32 id : 10);
    };
    s32 temp_a1;
    s32 temp_v1;
    int temp_a2;

    temp_v1 = ((struct HitData *)arg1)->id ^ 0x27D;
    temp_a2 = ((struct HitData *)arg1)->id == 0;
    if (temp_v1 == 0) {
        *arg3 *= 2;
        return 7;
    }
    if (*arg4 == 0) {
        temp_a1 = *arg3;
        if ((temp_a1 != 0) || (temp_a2 != 0)) {
            *arg3 = func_800F0E28(1, temp_a1, temp_a2);
        } else {
            *arg3 = 0;
        }
    }
    return 0;
}

void func_80800294_sucoasterhit(Unk80132ED0 *arg0, BtIntPtr arg1, s32 arg2) {
    Actor *func_80106790(Unk80132ED0 *);
    void *func_80100094(Actor *, u32);
    s32 _glhittableDll_entrypoint_10(s32);
    s32 _glhittableDll_entrypoint_7(s32);
    s32 _glhittableDll_entrypoint_9(s32);
    s32 _glhittableDll_entrypoint_6(s32);
    s32 _glhittableDll_entrypoint_8();
    s32 func_800F70EC(u32);
    s32 func_800F6C1C(u32);
    s32 func_800F0E28(s32, s32, ...);
    s32 _sueggmisc_entrypoint_0();
    void _suegg_entrypoint_18(Actor *, f32 *);
    void _suegg_entrypoint_19(Actor *, f32 *);
    void func_800F57F0(BtUIntPtr, f32 *);
    void func_800F5D70(BtUIntPtr, f32 *);
    f32 func_800EEFD4(f32[3]);
    f32 func_800F5F24(BtUIntPtr);
    void func_800EEB9C(f32[3], f32, f32);
    void func_800EC398(Unk80132ED0 *, f32 *);
    void func_800EFD24(f32[3]);
    f32 func_800F1DF4(f32[3], f32[3]);
    int func_800F1EA4(f32[3], f32 *);
    f32 func_800DC178(f32, f32);
    f32 func_800136E4(f32);
    void _chbounce_entrypoint_3(f32);
    void _chbounce_entrypoint_2(f32);
    void _chbounce_entrypoint_5(BtIntPtr, void *);
    void func_80109600(Actor *, Unk80132ED0 *);
    void _chflamer_entrypoint_1(void *, void *);
    void func_800EC370(void **, void *);
    void _chfreezy_entrypoint_1(void *, s16 *);
    void func_8010965C(Actor *);
    s32 func_8010A430(Actor *);
    u32 func_800F54E4(void);
    void func_800EB860(s32 (*filter)(s16 *, uintptr_t), uintptr_t data);
    s32 func_80108EF4(void *arg0, s32 arg1);
    f32 func_800EC708(Unk80132ED0 *);
    Actor *_chbaddiesetup_entrypoint_10(s32 id, s32 x, s32 y, s32 z, s32 yaw);
    void _chbaddiesetup_entrypoint_5(void *, BtIntPtr, s32, s32, s32, s32);
    void func_800EB874(void);
    s32 func_8010D930(s32 arg0, s32 arg1, f32 *arg2, s32 *arg3);
    void _subaddiejoy_entrypoint_10(void *, f32, f32);
    extern s16 D_80800CC4_sucoasterhit[11];
    struct MarkerFields {
        u8 padding[0x18];
        BT_BITFIELD_ORDER(u32 upper18 : 11, u32 lower18 : 5);
        BT_BITFIELD_ORDER(u32 mode : 4, u32 player : 11);
        u32 bit16 : 1;
        BT_BITFIELD_ORDER(u32 player : 11, u32 mode : 4);
        BT_BITFIELD_ORDER(u32 lower18 : 5, u32 upper18 : 11);
        u32 unk1C;
        u32 unk20;
        BT_BITFIELD_ORDER(u32 id : 10, u32 lower24 : 22);
        BT_BITFIELD_ORDER(u32 lower24 : 22, u32 id : 10);
    };
    struct DataFlags {
        u8 padding[0x19];
        BT_BITFIELD_ORDER(u8 upper : 2, u8 lower : 5);
        u8 flag : 1;
        BT_BITFIELD_ORDER(u8 lower : 5, u8 upper : 2);
    };
    struct HitVitals { u8 pad[0x5C]; u8 health[3]; };
    Actor *sp9C;
    s32 sp98;
    s32 sp94;
    s32 sp90;
    s32 sp8C;
    s32 sp88;
    s32 sp84;
    s32 sp80;
    s32 sp7C;
    s32 sp78;
    struct DataFlags *sp74;
    u32 sp70;
    f32 sp6C;
    f32 sp60[3];
    f32 sp54[3];
    f32 sp50;
    f32 sp4C;
    Actor *sp48;
    s32 sp3C[3];
    f32 sp38;
    f32 sp34;
    s32 pad30;

    sp9C = func_80106790(arg0);
    sp98 = _glhittableDll_entrypoint_10(arg2);
    sp94 = _glhittableDll_entrypoint_7(arg2);
    sp90 = _glhittableDll_entrypoint_9(arg2);
    sp8C = _glhittableDll_entrypoint_6(arg2);
    sp78 = ((struct MarkerFields *)arg1)->id == 0;
    sp74 = func_80100094(sp9C, 0);
    if (!sp78 || ((sp70 = ((struct MarkerFields *)arg1)->player,
                   func_800F70EC(sp70)) && func_800F6C1C(sp70)) ||
        !_glhittableDll_entrypoint_8(arg2)) {
        sp88 = func_80800208_sucoasterhit(sp9C, arg1, &sp94, &sp90, &sp8C);
        if ((u32)sp90 != 0) {
            if (sp88 & 1) {
                sp7C = sp90;
            } else {
                sp7C = 100 / sp90;
            }
            ((struct HitVitals *)sp9C)->health[sp8C] = func_800F0E28(0, ((struct HitVitals *)sp9C)->health[sp8C] - sp7C);
            if (((struct HitVitals *)sp9C)->health[sp8C] && !(sp88 & 1) && *(s32 *)&sp90 >= 2) {
                sp94 /= 2;
            }
            sp84 = sp8C == 2 && ((struct HitVitals *)sp9C)->health[sp8C] == 0;
            if ((sp88 & 4) && !sp84) {
                sp94 = 0;
            }
            if (sp94 != 0) {
                if (_sueggmisc_entrypoint_0(arg1)) {
                    sp48 = func_80106790(arg1);
                    _suegg_entrypoint_18(sp48, sp60);
                    _suegg_entrypoint_19(sp48, sp54);
                } else if (sp78) {
                    func_800F57F0(((struct MarkerFields *)arg1)->player, sp60);
                    func_800F5D70(((struct MarkerFields *)arg1)->player, sp54);
                    if (func_800EEFD4(sp54) < 100.0f) {
                        func_800EEB9C(sp54, func_800F5F24(((struct MarkerFields *)arg1)->player), 200.0f);
                    }
                } else {
                    func_800EC398(arg1, sp60);
                    func_800EFD24(sp54);
                }
                sp4C = func_800F1DF4(sp60, sp9C->position);
                if (!func_800F1EA4(sp54, &sp50)) {
                    sp50 = sp4C;
                }
                sp50 += func_800DC178(-30.0f, 30.0f);
                sp6C = func_800136E4(sp50);
                _chbounce_entrypoint_3(sp6C);
                _chbounce_entrypoint_2(sp6C);
                _chbounce_entrypoint_5(sp94 + 15, sp9C);
                sp9C->rotation[1] = sp9C->unk54 = func_800136E4(sp6C + 180.0f);
            }
            sp80 = !(sp88 & 2) || sp84;
            if (sp80) {
                switch (sp8C) {
                    case 2:
                        func_80109600(sp9C, arg1);
                        if (((struct MarkerFields *)arg1)->id == 0x26D) {
                            _chflamer_entrypoint_1(sp9C, arg1);
                        }
                        break;
                    case 1:
                        func_80109600(sp9C, arg1);
                        if (((struct MarkerFields *)arg1)->id == 0x26E) {
                            func_800EC370(arg1, sp3C);
                            _chfreezy_entrypoint_1(sp9C, sp3C);
                        }
                        break;
                }
            }
            if (sp90 && sp9C->unk70_10 == 9 && ((struct MarkerFields *)sp9C->unk0)->mode == 1) {
                func_8010965C(sp9C);
                sp74->flag = 1;
            }
            if (((struct HitVitals *)sp9C)->health[sp8C] == 0 || sp8C != 0) {
                if (((struct HitVitals *)sp9C)->health[sp8C] != 0) {
                    sp8C--;
                }
                if (sp8C != 2) {
                    ((struct HitVitals *)sp9C)->health[sp8C] = 99;
                }
                if (sp8C == 2 && sp98 && func_8010A430(sp9C)) {
                    sp38 = func_800F5F24(func_800F54E4());
                    func_800EB860(func_80108EF4, sp9C);
                    sp34 = sp9C->position[1] + func_800EC708(arg0);
                    _chbaddiesetup_entrypoint_5(_chbaddiesetup_entrypoint_10, sp98 + 2,
                        *(s32 *)&sp9C->position[0], *(s32 *)&sp34, *(s32 *)&sp9C->position[2], *(s32 *)&sp38);
                    func_800EB874();
                }
                switch (sp8C) {
                    case 0:
                        func_8080000C_sucoasterhit(sp9C->unk0, arg1);
                        break;
                    case 1:
                        func_80800114_sucoasterhit(sp9C->unk0, arg1);
                        break;
                    case 2:
                        func_808001C8_sucoasterhit(sp9C->unk0, arg1);
                        break;
                }
            }
            if (sp80) {
                func_8010D930(1, sp9C->unk70_0, sp9C->position, (s32 *)D_80800CC4_sucoasterhit);
                _subaddiejoy_entrypoint_10(sp9C, 1.0f, 0.25f);
            }
        }
    }
}

void func_80800870_sucoasterhit(Actor *arg0, Actor *arg1, s32 arg2, s32 arg3) {
    void *_sucoasterdata_entrypoint_1(u32);
    s32 func_800C2FDC(u8);
    void func_800C301C(u8, s32);
    void func_800C3058(u8, s32);
    void func_800C31DC(u8, f32);
    void func_800C3BDC(u8);
    BT_IDO_ONLY(u8 func_800C4350(s32, f32[3], s32 *);) BT_NATIVE_ONLY(u8 func_800C4350(u8, f32 *, s32 *);)
    f32 func_800DC178(f32, f32);
    extern s16 D_80800CDC_sucoasterhit[6];
    struct SoundData {
        s16 pad[2];
        s16 id;
        s16 rate;
        s16 volume;
    };
    u8 *data;
    f32 volume;

    data = _sucoasterdata_entrypoint_1(arg1->actorData[0] >> 28);
    if (((struct SoundData *)((BtUIntPtr)data + (arg2 << 3)))->id != 0) {
        if (arg3 != 0) {
            if (arg0->unk5F == 0) {
                arg0->unk5F = func_800C4350(arg0->unk5F, arg0->position, (s32 *)D_80800CDC_sucoasterhit);
                volume = func_800DC178(-0.05f, 0.05f);
                arg1 = (Actor *)((BtUIntPtr)data + (arg2 << 3));
                volume += ((struct SoundData *)arg1)->volume * 0.00390625f;
                func_800C301C(arg0->unk5F, ((struct SoundData *)arg1)->id);
                func_800C3058(arg0->unk5F, ((struct SoundData *)arg1)->rate);
                func_800C31DC(arg0->unk5F, volume);
            }
            if (arg0->unk5F != 0) {
                func_800C4350(arg0->unk5F, arg0->position, NULL);
                func_800C3BDC(arg0->unk5F);
            }
        } else {
            if (arg0->unk5F != 0) {
                func_800C2FDC(arg0->unk5F);
                arg0->unk5F = 0;
            }
        }
    }
}

s32 sucoasterhit_entrypoint_1(Actor *arg0) {
    void _sucoaster_entrypoint_22(void *arg0);
    s32 _sucoaster_entrypoint_9(void *, s32, s32);
    s32 func_8001210C(s32);
    void *func_80100094(Actor *, u32);
    void func_80102190(void *, s32);
    s32 func_80800AEC_sucoasterhit(Actor *, void *);
    struct HitFlags {
        u8 padding[0x18];
        BT_BITFIELD_ORDER(u32 upper : 4, u32 lower : 27);
        u32 hit : 1;
        BT_BITFIELD_ORDER(u32 lower : 27, u32 upper : 4);
    };
    Actor *data;
    s32 active;
    s32 hit;

    data = func_80100094(arg0, 0);
    hit = (data->actorData[0] << 4) >> 31;
    active = hit || arg0->unk58 > 0.0f;
    if (hit != 0) {
        arg0->unk58 = 0.7f;
    }
    ((struct HitFlags *)data)->hit = 0;
    func_80800870_sucoasterhit(arg0, data, 4, active);
    if (active == 0) {
        func_80102190(arg0, 0);
        _sucoaster_entrypoint_9(arg0, 3, 9);
        return 1;
    }
    arg0->position[0] += func_8001210C(1) != 0 ? -10.0f : 10.0f;
    arg0->position[2] += func_8001210C(1) != 0 ? 10.0f : -10.0f;
    _sucoaster_entrypoint_22(arg0);
    func_80800AEC_sucoasterhit(arg0, data);
    return 0;
}

s32 func_80800AEC_sucoasterhit(Actor *arg0, void *arg1) {
    s32 _subaddievolume_entrypoint_0(Actor *, f32 *, s32, s32, s32 *);
    BtIntPtr func_800B5BE4(s32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s16[]);
    f32 func_80103F38(Actor *, f32 *);
    extern s16 D_80800CE8_sucoasterhit[21];
    extern s16 D_80800D14_sucoasterhit[7];
    struct HitData {
        u8 padding[0x14];
        u8 volume;
    };
    f32 sp60[20][3];
    f32 sp54[3];
    s32 temp_s3;
    s32 var_s0;
    BtIntPtr sp48;
    s32 sp44;

    sp44 = ((struct HitData *)arg1)->volume;
    temp_s3 = _subaddievolume_entrypoint_0(arg0, sp60[0], 1, 5, &sp44);
    ((struct HitData *)arg1)->volume = sp44;
    if (temp_s3 > 0) {
        func_80103F38(arg0, sp54);
        sp48 = func_800B5BE4(0x12);
        func_800BABB8(sp48, NULL, NULL, 1.0f, D_80800CE8_sucoasterhit);
    }
    for (var_s0 = 0; var_s0 < temp_s3; var_s0++) {
        func_800BABB8(sp48, sp60[var_s0], sp54, 1.0f, D_80800D14_sucoasterhit);
    }
    return temp_s3 >= 0;
}

/* extern */

void sucoasterhit_entrypoint_2(Actor *arg0) {
    void _subaddiejoy_entrypoint_10(void *, f32, f32);
    void *_sucoasterdata_entrypoint_1(u32);
    void func_80018820(s32, f32, f32);
    s32 func_800E1610(s32, f32, f32, f32 *);
    void *func_80100094(Actor *, u32);
    s32 func_8010108C();
    struct CoasterData {
        u8 padding[0x44];
        u32 flags;
    };
    Actor *data;
    struct CoasterData *coaster;
    data = func_80100094(arg0, 0);
    coaster = _sucoasterdata_entrypoint_1(data->actorData[0] >> 28);
    if (coaster->flags & 2) {
        func_800E1610(0, 12.0f, 0.85f, arg0->position);
        func_80018820(0, 1.5f, 0.4f);
        _subaddiejoy_entrypoint_10(arg0, 1.5f, 0.6f);
        func_8010108C(arg0, 0xB6, 0);
    }
}
#include "hit_data.inc"
