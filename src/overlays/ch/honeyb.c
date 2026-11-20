#include "common.h"

void func_80102424(Actor *, s32);

OSThread *chhoneyb_entrypoint_0(void)
{
    extern ActorData D_80801020_chhoneyb[];

    return (OSThread *) D_80801020_chhoneyb;
}

OSThread *chhoneyb_entrypoint_1(void)
{
    extern ActorData D_80801068_chhoneyb[];

    return (OSThread *) D_80801068_chhoneyb;
}

void func_80800018_chhoneyb(Actor *arg0, u32 arg1, u32 arg2) {
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    _subaddiedialog_entrypoint_11(arg0->unk0, arg1, arg2, arg0->position, 0x9BU);
    func_80102424(arg0, 2);
}

void func_80800058_chhoneyb(void *arg0) {
    s32 _gcextra_entrypoint_1();
    void _subaddieitem_entrypoint_1(s8 *arg0, s32 arg1);
    void *func_80100094(Actor *, u32);
    s32 func_80800B58_chhoneyb();
    s32 func_80800B78_chhoneyb();
    s32 func_80800B98_chhoneyb(s32);
    s32 total;
    s32 i;

    *(s32 *)((u8 *)arg0 + 0x28) = 0;
    *(s32 *)((u8 *)arg0 + 0x2C) = 0;
    i = func_80800B78_chhoneyb() + 1;
    if (_gcextra_entrypoint_1() >= i) {
        do {
            total = func_80800B58_chhoneyb();
            if (total - *(s32 *)((u8 *)arg0 + 0x2C) >= func_80800B98_chhoneyb(i)) {
                *(s32 *)((u8 *)arg0 + 0x28) += 1;
                *(s32 *)((u8 *)arg0 + 0x2C) += func_80800B98_chhoneyb(i);
            }
            i++;
        } while (_gcextra_entrypoint_1() >= i);
    }
    _subaddieitem_entrypoint_1((BtIntPtr)func_80100094(arg0, 1) + 0x18, *(s32 *)((u8 *)arg0 + 0x2C));
}

/* extern */

void func_8080011C_chhoneyb(void *arg0) {
    s32 func_8008FC28();
    void func_80090708(s32 arg0);
    void func_800FC6B0(u32 track_id);
    s32 temp_v0;

    func_80090708(2);
    func_80102424(arg0, 3);
    (*(f32 *)((s8 *)(arg0) + (0x34))) = 1.0f;
    (((Actor *)arg0)->unk58) = 0.25f;
    temp_v0 = func_8008FC28();
    (*(s32 *)((s8 *)(arg0) + (0x30))) = temp_v0;
    (*(s32 *)((s8 *)(arg0) + (0x24))) = (s32) ((*(s32 *)((s8 *)(arg0) + (0x28))) + temp_v0);
    (*(u8 *)((s8 *)(arg0) + (0x74))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x74))) & 0xFFBF);
    func_800FC6B0(0xA);
}

void func_80800194_chhoneyb(Actor *arg0) {
    void _subaddieitem_entrypoint_0(BtIntPtr, BtUIntPtr, s32, s32);
    s32 _subaddiemarker_entrypoint_0(Actor *, s32, f32 *, s32);
    void _susubgame_entrypoint_0(BtIntPtr arg0, u8 *arg1, s32 arg2);
    void _susubgame_entrypoint_12(void *arg0, void *arg1);
    void func_800A16BC(s32);
    void func_800EE7F8(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    void func_80800058_chhoneyb(void *);
    extern s32 D_808010B0_chhoneyb[4];
    f32 sp28[6];

    if (_subaddiemarker_entrypoint_0(arg0, 0x1C1, sp28, 1) != 0) {
        func_800EE7F8((f32 *)arg0->actorData, sp28);
    }
    _subaddieitem_entrypoint_0((s8 *)func_80100094(arg0, 1) + 0x18, 0x4B7, 0x258, 3);
    func_80800058_chhoneyb(arg0);
    _susubgame_entrypoint_0(arg0, func_80100094(arg0, 1), 0);
    _susubgame_entrypoint_12(func_80100094(arg0, 1), D_808010B0_chhoneyb);
    func_800A16BC(1);
}

/* extern */

void func_80800240_chhoneyb(BtIntPtr arg0) {
    BtIntPtr _suexpression_entrypoint_20();
    void _suexpression_entrypoint_8(void *arg0, s32 arg1);
    u8 _susubgame_entrypoint_2(BtIntPtr arg0, u8 *arg1);
    s32 _susubgame_entrypoint_4(BtIntPtr, BtIntPtr);
    void *func_80100094(Actor *, u32);
    if (_suexpression_entrypoint_20(BT_NATIVE_ONLY((void *)arg0)) != 0) {
        _suexpression_entrypoint_8(arg0, 0);
    }
    if (_susubgame_entrypoint_2(arg0, func_80100094(arg0, 1)) != 0) {
        _susubgame_entrypoint_4(arg0, func_80100094(arg0, 1));
    }
}

void func_808002AC_chhoneyb(Actor *arg0) {
    s32 _gcextra_entrypoint_1(void);
    s32 _glcutDll_entrypoint_20(void);
    s32 _subaddiedialog_entrypoint_5(f32 *, u32, u32, u32);
    s32 _subaddieitem_entrypoint_3(Actor *, f32 *, void *);
    s32 _sudeflect_entrypoint_1(f32 *arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4);
    s32 _susubgame_entrypoint_5(BtIntPtr arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4);
    void func_80090708(s32 arg0);
    void func_8008FBE0(u32);
    void func_800C3FC0(s32, f32, s32);
    void func_800D1824(s32);
    s32 func_800D2498(u32, s32, u32);
    int func_800D27F4(s32);
    f32 func_800D8FF8(void);
    s32 func_800D9078(f32 *);
    s32 func_800DA298(s32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_800FA9F4(s32, s32);
    void *func_80100094(Actor *, u32);
    void func_80103DFC(Actor *, f32 *);
    void func_8080062C_chhoneyb(void *);
    void func_80800680_chhoneyb(s32 *);
    void func_80800744_chhoneyb(Actor *, s32, s32);
    void func_80800B2C_chhoneyb(Actor *);
    s32 func_80800B78_chhoneyb(void);
    s32 func_80800C0C_chhoneyb(void);
    typedef struct {
        s32 unk0[3];
        s32 total;
        s32 pending;
        s32 unk14;
        s32 current;
        union {
            f32 value;
            s32 bits;
        } progress;
    } HoneybData;
    f32 sp34[3];

    func_80800680_chhoneyb((s32 *)arg0);
    _sudeflect_entrypoint_1(arg0->position, 400.0f, 0.0f, 80.0f, 0xE);
    func_80800B2C_chhoneyb(arg0);
    func_8008FBE0(arg0->unk70_10 == 1);
    switch (arg0->unk70_10) {
        case 1:
            if (_glcutDll_entrypoint_20() == 0) {
                func_800D1824(0x49);
                if (((HoneybData *)arg0->actorData)->pending == 0) {
                    if (func_80800B78_chhoneyb() < _gcextra_entrypoint_1()) {
                        func_800D2498(0x107, func_80800C0C_chhoneyb(), 0);
                    }
                }
            }
            if (_subaddiedialog_entrypoint_5(arg0->position, 0x258, 0x3C, 0) != 0) {
                if (func_80800B78_chhoneyb() >= _gcextra_entrypoint_1()) {
                    _susubgame_entrypoint_5(arg0, func_80100094(arg0, 1), 3, 0, 0);
                    func_80800018_chhoneyb(arg0, 0x1521, 0xF);
                } else if (func_800DA298(0) != 0) {
                    func_80800744_chhoneyb(arg0, 0x1519, 0);
                } else {
                    _susubgame_entrypoint_5(arg0, func_80100094(arg0, 1), 3, 0, 0);
                    func_80800018_chhoneyb(arg0, 0x1519, 0xF);
                }
            }
            break;
        case 4:
            if (arg0->unk74_29) {
                _susubgame_entrypoint_5(arg0, func_80100094(arg0, 1), 3, 0, 0);
                func_80800018_chhoneyb(arg0, 0x1518, 0xF);
            }
            break;
        case 5:
            func_80103DFC(arg0, sp34);
            if (_subaddieitem_entrypoint_3(arg0, sp34, (s8 *)func_80100094(arg0, 1) + 0x18) != 0) {
                func_80800018_chhoneyb(arg0, 0x1553, 0xF);
            }
            break;
        case 3:
            func_800FA9F4(0, ((HoneybData *)arg0->actorData)->progress.bits);
            func_800D2498(0x119, ((HoneybData *)arg0->actorData)->current, ((HoneybData *)arg0->actorData)->total);
            if (func_800D27F4(0x119) != 0) {
                if (((HoneybData *)arg0->actorData)->progress.value < 1.0f) {
                    ((HoneybData *)arg0->actorData)->progress.value += func_800D8FF8() * 2;
                    if (((HoneybData *)arg0->actorData)->progress.value > 1.0f) {
                        ((HoneybData *)arg0->actorData)->progress.value = 1.0f;
                        func_800C3FC0(0x66C, func_800F10B4(((HoneybData *)arg0->actorData)->current, 1.0, 10.0f, 0.8f, 1.5f), 0x7D00);
                    }
                }
                if (func_800D9078(&arg0->unk58) != 0) {
                    if (((HoneybData *)arg0->actorData)->current >= ((HoneybData *)arg0->actorData)->total) {
                        func_8080062C_chhoneyb(arg0);
                        func_80090708(0);
                        func_80102424(arg0, 1);
                        return;
                    }
                    ((HoneybData *)arg0->actorData)->current++;
                    ((HoneybData *)arg0->actorData)->progress.value = 0.0f;
                    arg0->unk58 = 0.75f;
                }
            }
            break;
    }
}

/* extern */

s32 func_80800B78_chhoneyb(void);

void func_8080062C_chhoneyb(void *arg0) {
    void _gcextra_entrypoint_2(s32);
    s32 func_8008FD48();
    void func_800A1658(s32);
    void func_80101180(s32, s32, BtIntPtr);
    void func_80800058_chhoneyb(void *);
    _gcextra_entrypoint_2(*(s32 *)((s8 *)arg0 + 0x28));
    func_800A1658(func_8008FD48());
    func_80800058_chhoneyb(arg0);
    func_80101180(0x4B8, 0x23, func_80800B78_chhoneyb());
}

/* extern */

void func_80800680_chhoneyb(s32 *arg0) {
    void _suexpression_entrypoint_10(void *arg0, Unk80132ED0 *arg1, f32 *arg2);
    void _suexpression_entrypoint_18(s8 *arg0, s32 arg1);
    BtIntPtr _suexpression_entrypoint_20();
    f32 func_80101F24(s32 *);
    s32 func_801022E4(s32 *);
    s32 func_80102320(s32 *, s32, s32);
    BtIntPtr sp1C;
    s32 sp18;
    f32 temp_f0;
    BtIntPtr temp_v0;

    temp_v0 = _suexpression_entrypoint_20(BT_NATIVE_ONLY(arg0));
    sp1C = temp_v0;
    sp18 = 0;
    if (temp_v0 != 0) {
        if ((func_801022E4(arg0) == 0x4AD) && ((temp_f0 = func_80101F24(arg0), (temp_f0 < 0.12f)) || (temp_f0 > 0.97f) || (func_80102320(arg0, 0x3F0CCCCD, 0x3F333333) != 0))) {
            sp18 = 1;
        }
        if (sp18 != 0) {
            _suexpression_entrypoint_18(sp1C, 1);
        }
        _suexpression_entrypoint_10(sp1C, *arg0, 0);
    }
}

void func_80800744_chhoneyb(Actor *arg0, s32 arg1, s32 arg2) {
    void func_800DA544(GameFlag);
    void _subaddieitem_entrypoint_2(BtIntPtr);
    s32 _susubgame_entrypoint_4(BtIntPtr, BtIntPtr);
    s32 _susubgame_entrypoint_5(BtIntPtr arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4);
    void *func_80100094(Actor *, u32);
    s32 func_80800BD8_chhoneyb(void);
    u32 sp2C;
    u32 sp28;
    u32 temp_v0;

    sp2C = 0;
    sp28 = 0xF;
    switch (arg1) {
    case 0x1518:
        func_800DA544(0x4E9);
    case 0x1519:
        func_800DA544(0);
        temp_v0 = arg0->actorData[4];
        if (temp_v0 == 0) {
            if (func_80800BD8_chhoneyb() == 1) {
                sp2C = 0x151F;
            } else {
                sp2C = 0x1520;
            }
        } else if (temp_v0 == 1) {
            sp2C = 0x151A;
        } else {
            sp2C = 0x151B;
        }
        _susubgame_entrypoint_5(arg0, func_80100094(arg0, 1), 3, 1, 0);
        break;
    case 0x151A:
    case 0x151B:
        sp2C = 0x151C;
        break;
    case 0x151C:
        if (arg2 == 1) {
            sp2C = 0x151D;
        } else {
            sp2C = 0x151E;
        }
        sp28 = 0x4E;
        break;
    case 0x151D:
        _subaddieitem_entrypoint_2((BtIntPtr)func_80100094(arg0, 1) + 0x18);
        _susubgame_entrypoint_5(arg0, func_80100094(arg0, 1), 2, 1, 0);
        func_80102424(arg0, 5);
        break;
    case 0x1553:
        _susubgame_entrypoint_4((BtIntPtr)arg0, (BtIntPtr)func_80100094(arg0, 1));
        func_8080011C_chhoneyb(arg0);
        break;
    default:
        _susubgame_entrypoint_4((BtIntPtr)arg0, (BtIntPtr)func_80100094(arg0, 1));
        func_80102424(arg0, 1);
        break;
    }
    if (sp2C != 0) {
        func_80800018_chhoneyb(arg0, sp2C, sp28);
    }
}

/* extern */

s32 func_80800920_chhoneyb(u8 *arg0, s32 arg1, s32 arg2) {
    s32 func_80800BD8_chhoneyb();
    s32 var_v0;

    if (arg1 == 0x1520) {
        return func_80800BD8_chhoneyb();
    }
    if (arg1 == 0x151B) {
        return (*(s32 *)((s8 *)(arg0) + (0x28)));
    } else {
        return -1;
    }
}

s32 func_80800968_chhoneyb(Actor *arg0, s32 arg1, s32 arg2) {
    void _gcdialogcamera_entrypoint_3(u32 *, f32);
    s32 _glcutDll_entrypoint_20(void);
    void *_suexpression_entrypoint_7(Actor *arg0, s32 arg1, s16 arg2);
    void _suexpression_entrypoint_12(void *, f32, f32);
    s32 _susubgame_entrypoint_3(Actor *, void *, u32, u32);
    void _susubgame_entrypoint_6(Actor *, void *, s32, s32, BtIntPtr);
    void func_8008F8B0(void);
    void func_8008F8D8(s32);
    void func_8008F904(void *, Unk80132ED0 *);
    void func_8008F990(f32 *, f32);
    void func_800904C8(s32);
    s32 func_800DA298(s32);
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);
    extern u32 D_808010C0_chhoneyb[4];
    extern s32 func_8010D5DC;

    switch (arg1) {
    case 0x2E:
        func_80800744_chhoneyb(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
        break;
    case 0x30:
        return func_80800920_chhoneyb((u8 *)arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
    case 0x32:
        func_800904C8(0x8D);
        arg0->unk74_29 = 1;
        break;
    case 0x52:
        _gcdialogcamera_entrypoint_3(D_808010C0_chhoneyb, arg0->scale);
        break;
    case 0xB:
        return 3;
    case 0x95:
        _suexpression_entrypoint_12(_suexpression_entrypoint_7(arg0, 0, 0x9B), 60.0f, 20.0f);
        if (!func_800DA298(0x4E9) && !_glcutDll_entrypoint_20()) {
            func_8008F8B0();
            func_8008F904(&func_8010D5DC, arg0->unk0);
            func_8008F8D8(1);
            func_8008F990((f32 *)arg0->actorData, 300.0f);
            _susubgame_entrypoint_6(arg0, func_80100094(arg0, 1), 1, 0x60, 0);
            func_80102424(arg0, 4);
        }
        break;
    case 0x57:
        return _susubgame_entrypoint_3(arg0, func_80100094(arg0, 1), arg2 & 0xFFFF, (u32)(arg2 & 0xFFFF0000) >> 16);
    default:
        return 0;
    }
    return 1;
}

void func_80800B2C_chhoneyb(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_4(Actor*, f32*, u32, u32*);
    extern u32 D_808010D0_chhoneyb[8];
    _subaddieaudioloop_entrypoint_4(arg0, &arg0->position[0], 1U, D_808010D0_chhoneyb);
}

s32 func_80800B58_chhoneyb()
{
    return func_800D1A04(0x49);
}

s32 func_80800B78_chhoneyb()
{
    s32 _gcextra_entrypoint_0();
    return _gcextra_entrypoint_0();
}

/* extern */

s32 func_80800B98_chhoneyb(s32 arg0) {
    s32 _gcextra_entrypoint_1();
    if ((arg0 <= 0) || (_gcextra_entrypoint_1() < arg0)) {
        return -1;
    }
    return (arg0 * 2) - 1;
}

s32 func_80800BD8_chhoneyb(void) {
    s32 result;

    result = func_80800B98_chhoneyb(func_80800B78_chhoneyb() + 1);
    return result - func_80800B58_chhoneyb();
}

s32 func_80800C0C_chhoneyb(void) {
    BT_NATIVE_ONLY(return) func_80800B98_chhoneyb(func_80800B78_chhoneyb() + 1);
}

void func_80800C34_chhoneyb(u8 *arg0) {
    void func_8010A3E8(void *arg0, f32 arg1);
    func_8010A3E8(arg0, 0.7f);
}

void func_80800C58_chhoneyb(BT_NATIVE_ONLY(s32 bt_a0))
{
    func_8010C964();
}

/* extern */

s32 func_80800C78_chhoneyb(void *arg0, s32 arg1, void *volatile arg2) {
    s32 _glcutDll_entrypoint_20();
    void _subaddiefade_entrypoint_3(Actor *);
    void func_800DF744(s32, s32);
    void func_800FFAB0(Actor *);
    void func_8010DC50(s32);
    void func_8010DCB4(s32);
    void func_8010DD20(Actor *arg0, s32 arg1, Unk80132ED0 *arg2);
    Actor *actor = arg0;

    switch (arg1) {
    case 0x95:
        if (func_80800B78_chhoneyb() >= (s32)actor->unk74_7 - 0x32 ||
            _glcutDll_entrypoint_20(actor)) {
            func_800FFAB0(actor);
        }
        break;
    case 0x29:
        func_8010DC50(2);
        break;
    case 0x2A:
        func_8010DCB4(2);
        break;
    case 0x1F:
        func_8010DD20(arg0, 2, arg2);
        func_800DF744(3, 0);
        break;
    case 0x23:
        if ((BtIntPtr)arg2 >= (s32)actor->unk74_7 - 0x32) {
            _subaddiefade_entrypoint_3(actor);
        }
        break;
    default:
        return 0;
    }
    return 1;
}

#include "honeyb_hud.inc"
/* data_to_c.py: from asm/data/overlays/ch/honeyb.data.s */
extern u8 D_80800FF0_chhoneyb[];
void func_80102EC0();
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
void func_801018A4();
u8 D_80800FF0_chhoneyb[48] BT_DATA(4, overlays_ch_honeyb, 0x0) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0xD5, 0x70, 0xA4, 0x04, 0xAD, 0x00, 0x00, 0x40, 0xD5, 0x70, 0xA4, 0x04, 0xAD, 0x00, 0x00, 0x40, 0xD5, 0x70, 0xA4, 0x04, 0xAD, 0x00, 0x00, 0x40, 0xD5, 0x70, 0xA4, 0x04, 0xAD, 0x00, 0x00, 0x40, 0xD5, 0x70, 0xA4, 0x04, 0xAD, 0x00, 0x00 };
ActorData D_80801020_chhoneyb [1] BT_DATA(4, overlays_ch_honeyb, 0x30) = { { 344, 1200, 2328, 1, (void *)D_80800FF0_chhoneyb, (void (*)(struct Actor *))func_808002AC_chhoneyb, (void (*)(struct Actor *))func_80102EC0, (void (*)(long, long))func_80101870, 0, 1068708659, 0, 0, 0, 288, (void (*)(struct Actor *))func_80800240_chhoneyb, 0, 0, 44, (void (*)(struct Actor *))func_80800194_chhoneyb, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 9218, (void (*)(struct Actor *, long, long))func_80800968_chhoneyb, 0 } };
ActorData D_80801068_chhoneyb [1] BT_DATA(4, overlays_ch_honeyb, 0x78) = { { 344, 1208, 1797, 1, 0, (void (*)(struct Actor *))func_80800C58_chhoneyb, (void (*)(struct Actor *))func_80102EC0, (void (*)(long, long))func_801018A4, 0, 1070386381, 0, 0, 128, 0, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800C34_chhoneyb, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 9346, (void (*)(struct Actor *, long, long))func_80800C78_chhoneyb, 0 } };
s32 D_808010B0_chhoneyb[4] BT_DATA(4, overlays_ch_honeyb, 0xC0) = { 1138819072, 1132068864, 1128792064, 1128792064 };
u32 D_808010C0_chhoneyb[4] BT_DATA(4, overlays_ch_honeyb, 0xD0) = { 0x43E10000, 0x437A0000, 0x43480000, 0x43480000 };
u32 D_808010D0_chhoneyb[8] BT_DATA(4, overlays_ch_honeyb, 0xE0) = { 0x13049B, 0x161388, 0xE00E6, 0x1190180, 0, 0, 0, 0 };
