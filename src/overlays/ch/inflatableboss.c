#include "common.h"

OSThread *chinflatableboss_entrypoint_0(void)
{
    extern BtFnWord D_80802E50_chinflatableboss[];

    return (OSThread *) D_80802E50_chinflatableboss;
}

void func_8080000C_chinflatableboss(Actor *arg0) {
    typedef struct {
        f32 position[3];
        s32 id;
        s32 unk10;
        s32 unk14;
    } BossMarker;
    typedef struct {
        u8 unk0[8];
        u8 unk8[0x14];
        f32 position1[3];
        f32 position2[3];
        f32 position3[3];
        u8 unk40[8];
        f32 positions[3][3];
        s32 count6C;
        BossMarker markers70[20];
        s32 count250;
        BossMarker markers254[20];
        u8 unk434[0x60];
        u8 unk494;
        u8 unk495;
        u8 unk496;
        u8 unk497;
        u8 unk498;
        u8 unk499[3];
        u8 unk49C;
    } BossData;
    s32 _chcredits_entrypoint_1(void);
    s32 _chintrotext_entrypoint_2(s32);
    s32 _glcutDll_entrypoint_20(void);
    void _plcamera_entrypoint_8(s32 *arg0);
    void _subaddieDll_entrypoint_10(s32, void *);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    s32 _subaddiemarker_entrypoint_0(Actor *, s32, BossMarker *, s32);
    s32 _subaddiemarker_entrypoint_1(Actor *, s32, s32, BossMarker *, s32);
    void *_suexpression_entrypoint_7(Actor *arg0, s32 arg1, s16 arg2);
    s32 func_800D395C(void);
    s32 func_800DA298(s32);
    void func_800DA524(s32);
    void func_800DA544(s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800F497C(BtIntPtr);
    void func_800F49D4(BtIntPtr, void *, BtIntPtr);
    void func_800F4A58(BtIntPtr, f32 *, f32);
    BtUIntPtr func_800F54E4(void);
    void func_800F608C(BtIntPtr, s32);
    s32 func_800F64A4(BtIntPtr, s32);
    void func_800F8294(BtIntPtr, f32 *);
    void func_800F8300(BtIntPtr, s32, f32 *);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    void func_80102FDC(Actor *, f32);
    void func_80109FE8(Actor *, s32);
    void func_8010A85C(u8 *, s32);
    void func_80800F84_chinflatableboss(Actor *, s32);
    void func_8080183C_chinflatableboss(Actor *);
    void func_80802A00_chinflatableboss(Actor *, u32, u32);
    void func_80802AD8_chinflatableboss(Actor *, s32, s32);
    extern s16 D_80802D8C_chinflatableboss[];
    void func_8010D5DC(s32, s32);
    BossData *data;
    s32 i;
    BossMarker markers[3];
    s32 j;
    s32 k;
    s32 count;
    BossMarker *marker;
    BtIntPtr player;
    s32 pad;
    f32 *volatile position;

    data = func_80100094(arg0, 0);
    func_800DA524(1);
    func_800DA524(2);
    func_800DA524(4);
    func_800DA524(3);
    func_800DA524(5);
    if (func_800DA298(0x9C) && !_glcutDll_entrypoint_20()) {
        func_800DA544(3);
        _chintrotext_entrypoint_2(1);
        func_800FFAB0(arg0);
        return;
    }
    func_80102FDC(arg0, 1.4f);
    data->unk494 = 1;
    data->unk495 = D_80802D8C_chinflatableboss[0];
    ((f32 *)arg0->actorData)[4] = 0.35f;
    func_80109FE8(arg0, 0);
    func_800EE7F8(data->position1, position = arg0->position);
    func_800EE7F8(data->position2, position);
    func_800EE7F8(data->position3, position);
    for (i = 0; i != 12; i++) {
        func_80802AD8_chinflatableboss(arg0, i, 1);
    }
    _subaddieDll_entrypoint_10(0x154, data->unk0);
    _subaddieDll_entrypoint_10(0x320, data->unk8);
    func_8080183C_chinflatableboss(arg0);
    func_8010A85C((u8 *)arg0, 2);
    _suexpression_entrypoint_7(arg0, 1, 0x3A);
    data->count6C = _subaddiemarker_entrypoint_1(arg0, 0x437, 0x32, data->markers70, 20);
    data->count250 = _subaddiemarker_entrypoint_1(arg0, 0x437, 0x35, data->markers254, 20);
    count = _subaddiemarker_entrypoint_0(arg0, 0x3DA, markers, 20);
    j = 0;
    if (count > 0) {
        do {
            k = 0;
            if (count > 0) {
                marker = markers;
                do {
                    if (j + 0x32 == marker->id) {
                        break;
                    }
                    k++;
                    marker++;
                } while (k != count);
            }
            func_800EE7F8(data->positions[j], markers[k].position);
            j++;
        } while (j < count);
    }
    if (func_800DA298(0x17F)) {
        data->unk498 = 5;
    } else {
        data->unk498 = 1;
    }
    if (!func_800F64A4(func_800F54E4(), 1)) {
        data->unk498 = 0;
    }
    if (_glcutDll_entrypoint_20()) {
        func_8010A85C((u8 *)arg0, 1);
        func_80800F84_chinflatableboss(arg0, _chcredits_entrypoint_1() == 0x36 ? 0x12 : 0x13);
        return;
    }
    if (data->unk498 == 5) {
        player = func_800F54E4();
        data->unk49C = 1;
        data->unk496 = 1;
        func_800F608C(player, 1);
        func_800F8294(player, data->positions[1]);
        func_800F8300(player, 2, position);
        func_800F497C(player);
        _plcamera_entrypoint_8(player);
        func_800DA544(2);
        func_80802A00_chinflatableboss(arg0, 0x22, 0x20);
        _subaddiedialog_entrypoint_11(arg0->unk0, 0x1087, 0x107, position, 0x3A);
        func_80800F84_chinflatableboss(arg0, 3);
        func_8010A85C((u8 *)arg0, 1);
        return;
    }
    if (func_800D395C()) {
        arg0->unk64_16 = 1;
        data->unk498 = 2;
        func_800F497C(func_800F54E4());
        func_800F49D4(func_800F54E4(), func_8010D5DC, (BtIntPtr)arg0->unk0);
        func_800F4A58(func_800F54E4(), data->positions[0], 300.0f);
        func_80802A00_chinflatableboss(arg0, 0x2F, 0x20);
    } else {
        arg0->unk64_16 = 0;
        _chintrotext_entrypoint_2(1);
    }
}

void func_80800408_chinflatableboss(Actor *arg0) {
    void _suexpression_entrypoint_8(Actor *, u32);
    s32 func_800BA2C4(void *);
    void *func_80100094(Actor *, u32);
    u8 *sp2C;
    void *temp_a0;
    void *temp_a0_2;
    s32 var_s1;
    u8 *var_s0;

    sp2C = func_80100094(arg0, 0);
    _suexpression_entrypoint_8(arg0, 1);
    var_s1 = 0;
    var_s0 = sp2C;
    do {
        temp_a0 = *(void **)(var_s0 + 0x43C);
        if (temp_a0 != NULL) {
            *(s32 *)(var_s0 + 0x43C) = func_800BA2C4(temp_a0);
        }
        var_s1 += 4;
        var_s0 += 4;
    } while (var_s1 != 0x30);
    temp_a0_2 = *(void **)(sp2C + 0x434);
    if (temp_a0_2 != NULL) {
        *(s32 *)(sp2C + 0x434) = func_800BA2C4(temp_a0_2);
    }
}

struct anctrl_s;
void func_808004A0_chinflatableboss(Actor *arg0) {
    typedef struct {
        u8 unk0[0x1C];
        f32 position1[3];
        f32 position2[3];
        f32 position3[3];
        u8 unk40[0x3F4];
        s32 effect;
        u8 unk438[0x5D];
        u8 remaining;
        u8 unk496[6];
        u8 unk49C;
    } BossData;
    void _gcfrontend_entrypoint_10(void);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 _subaddieaudioquick_entrypoint_3(Actor *, f32 *, u32 *, f32);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    s32 _subaddieskeleton_entrypoint_3(Unk80132ED0 *, s32, f32 *);
    void _suexpression_entrypoint_10(u32 *, Unk80132ED0 *, BtUIntPtr);
    struct anctrl_s *func_80104248(void *);
    void func_8008B1C8(struct anctrl_s *, f32);
    void func_800C4AF0(f32 *, void *);
    void func_800C4B64(f32);
    s32 func_800D395C(void);
    s32 func_800D9078(f32 *);
    void func_800DA544(s32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    u32 func_800FDC28(u32);
    void *func_80100094(Actor *, u32);
    s32 func_80101DDC(Actor *);
    s32 func_80101E14(Actor *, f32);
    void func_80102BF8(void *, f32, f32, f32);
    s32 func_80102CF4(Actor *, f32);
    f32 func_80102D78(Actor *, f32 *);
    void func_80108B04(Actor *, u32);
    f32 func_8010CD28(Actor *);
    void func_80800F84_chinflatableboss(Actor *, s32);
    void func_8080183C_chinflatableboss(Actor *);
    void func_80801B04_chinflatableboss(Actor *);
    s32 func_80801CB4_chinflatableboss(Actor *);
    s32 func_8080200C_chinflatableboss(Actor *, f32 *, f32 *);
    void func_80802058_chinflatableboss(Actor *);
    void func_80802264_chinflatableboss(Actor *, f32, f32, f32 *, s16);
    void func_80802450_chinflatableboss(Actor *);
    void func_808024BC_chinflatableboss(Actor *);
    void func_8080267C_chinflatableboss(Actor *);
    s32 func_8080272C_chinflatableboss(Actor *);
    void func_80802910_chinflatableboss(Actor *);
    void func_808029AC_chinflatableboss(Actor *);
    void func_80802A9C_chinflatableboss(Actor *);
    extern f32 D_80802E98_chinflatableboss[];
    extern f32 D_80802EA0_chinflatableboss[];
    extern f32 D_80802EB4_chinflatableboss[];
    extern u32 D_80802EC4_chinflatableboss[];
    extern u32 D_80802ED0_chinflatableboss[];
    extern u32 D_80802EDC_chinflatableboss[];
    extern u32 D_80802EE8_chinflatableboss[];
    BossData *data;
    s32 pad[2];
    f32 position[3];

    data = func_80100094(arg0, 0);
    func_80802058_chinflatableboss(arg0);
    _suexpression_entrypoint_10(func_80100094(arg0, 1), arg0->unk0, 0);
    func_8080272C_chinflatableboss(arg0);
    func_808029AC_chinflatableboss(arg0);
    switch (arg0->unk70_10) {
        case 2:
            func_80802264_chinflatableboss(arg0, 0.3f, 0.3f, D_80802E98_chinflatableboss, 2);
            func_80802264_chinflatableboss(arg0, 0.3f, 0.5f, D_80802EA0_chinflatableboss, 5);
            if (func_80101DDC(arg0)) {
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x1082, 0x106, arg0->position, 0x3A);
                func_80800F84_chinflatableboss(arg0, 3);
                func_8008B1C8(func_80104248(arg0), 0.8f);
            }
            break;
        case 4:
            func_80802264_chinflatableboss(arg0, 0.5f, 0.8f, D_80802EB4_chinflatableboss, 4);
            if (func_80101E14(arg0, 0.5f)) {
                func_800DA544(4);
            }
            if (func_80101DDC(arg0)) {
                if (data->unk49C) {
                    func_80802910_chinflatableboss(arg0);
                } else {
                    _subaddiedialog_entrypoint_11(arg0->unk0, 0x1083, 0x106, arg0->position, 0x3A);
                    func_80800F84_chinflatableboss(arg0, 5);
                    func_8008B1C8(func_80104248(arg0), 0.8f);
                }
            }
            break;
        case 9:
            arg0->unk54 = func_8010CD28(arg0);
            func_80102BF8(arg0, 0.1f, 3.0f, 90.0f);
            if (func_800D9078(&arg0->unk58)) {
                func_8080183C_chinflatableboss(arg0);
                func_808024BC_chinflatableboss(arg0);
                arg0->unk54 = func_80102D78(arg0, (f32 *)arg0->actorData);
            }
            break;
        case 10:
            arg0->unk54 = func_8010CD28(arg0);
            func_80102BF8(arg0, 0.1f, 3.0f, 90.0f);
            if (func_80102CF4(arg0, 8.0f)) {
                func_80800F84_chinflatableboss(arg0, 11);
            }
            break;
        case 6:
            if (!arg0->unk74_30) {
                func_80801B04_chinflatableboss(arg0);
            }
            break;
        case 7:
            if (func_800D9078(&arg0->unk58)) {
                func_808024BC_chinflatableboss(arg0);
            }
            break;
        case 8:
            if (!arg0->unk74_30) {
                func_80801B04_chinflatableboss(arg0);
            }
            break;
        case 11:
            arg0->unk54 = func_8010CD28(arg0);
            func_80102BF8(arg0, 0.1f, 3.0f, 90.0f);
            if (func_80101E14(arg0, 0.3f)) {
                func_800C4B64(func_800F10B4(arg0->scale, 1.4f, 0.19913846f, 0.9f, 1.2f));
                _subaddieaudioquick_entrypoint_2(arg0, data->position1, D_80802EC4_chinflatableboss);
            } else if (func_80101E14(arg0, 0.45f)) {
                func_80108B04(arg0, 1);
                arg0->unk58 = 1.0f;
                data->remaining--;
            } else if (func_80101E14(arg0, 0.999f) && data->remaining == 0) {
                func_8080183C_chinflatableboss(arg0);
                func_808024BC_chinflatableboss(arg0);
                arg0->unk54 = func_80102D78(arg0, (f32 *)arg0->actorData);
            }
            break;
        case 12:
            if (func_80101E14(arg0, 0.25f)) {
                func_800C4B64(func_800F10B4(arg0->scale, 1.4f, 0.19913846f, 1.0f, 1.4f) * 0.8f);
                _subaddieaudioquick_entrypoint_2(arg0, data->position1, D_80802ED0_chinflatableboss);
            }
            if (func_80101DDC(arg0)) {
                func_80800F84_chinflatableboss(arg0, 13);
            }
            break;
        case 13:
            func_80802450_chinflatableboss(arg0);
            if (func_80101DDC(arg0)) {
                if (!func_80801CB4_chinflatableboss(arg0)) {
                    func_80800F84_chinflatableboss(arg0, 14);
                } else {
                    func_808024BC_chinflatableboss(arg0);
                }
            }
            break;
        case 15:
            _subaddieaudioquick_entrypoint_3(arg0, arg0->position, D_80802EDC_chinflatableboss, 0.03f);
            if (func_80101E14(arg0, 0.06f)) {
                _subaddieskeleton_entrypoint_3(arg0->unk0, 7, position);
                data->effect = func_8080200C_chinflatableboss(arg0, position, data->position2);
            }
            if (func_80101E14(arg0, 0.43f)) {
                func_800C4AF0(data->position3, D_80802EE8_chinflatableboss);
            }
            if (func_80101DDC(arg0)) {
                func_800FDC28(0);
                func_800DA544(3);
                if (func_800D395C()) {
                    func_80800F84_chinflatableboss(arg0, 16);
                    func_80802A9C_chinflatableboss(arg0);
                    _gcfrontend_entrypoint_10();
                } else {
                    func_800DA544(0x9C);
                    func_80108B04(arg0, 3);
                    func_80800F84_chinflatableboss(arg0, 16);
                }
            }
            break;
        case 18:
            func_80802264_chinflatableboss(arg0, 0.5f, 0.8f, D_80802EB4_chinflatableboss, 4);
            if (func_80101DDC(arg0)) {
                func_80800F84_chinflatableboss(arg0, 19);
            }
            break;
    }
    func_8080267C_chinflatableboss(arg0);
}

s32 func_80800A98_chinflatableboss(Actor *arg0, s32 arg1, s32 arg2) {
    typedef struct {
        u8 pad0[0x1C];
        f32 position1[3];
        u8 pad28[0x20];
        f32 positions[3][3];
        u8 pad6C[0x41B];
        u8 parts[12];
        u8 unk493;
        u8 unk494;
        u8 unk495;
        u8 unk496;
        u8 unk497;
        u8 unk498;
        u8 unk499;
        u8 unk49A;
        u8 unk49B;
        u8 unk49C;
        u8 unk49D;
    }
    BossData;
    typedef union {
        s32 word;
        s16 halves[2];
        u8 *pointer;
    }
    BossEvent;
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    s32 func_800D395C(void);
    void func_800F497C(BtIntPtr);
    void func_800F49A8(BtIntPtr, s32);
    void func_800F49D4(BtIntPtr, void *, BtIntPtr);
    void func_800F4A58(BtIntPtr, f32 *, f32);
    BtUIntPtr func_800F54E4(void);
    void func_800F8300(BtIntPtr, s32, f32 *);
    u32 func_800FDC28(u32);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    void func_80101010(f32 *);
    void func_80101074(void *);
    s32 func_80101180(s32, s32, BtIntPtr);
    void func_80108B04(Actor *, u32);
    void func_80800F84_chinflatableboss(Actor *, s32);
    void func_808010BC_chinflatableboss(Actor *, s32);
    void func_80801164_chinflatableboss(Actor *, s32);
    void func_80801418_chinflatableboss(Actor *, u8 *);
    void func_80801958_chinflatableboss(Actor *, s32, s32);
    void func_80801AD8_chinflatableboss(Actor *, s32, s32);
    void func_80801D38_chinflatableboss(Actor *);
    void func_80801DE0_chinflatableboss(Actor *);
    void func_80801EA0_chinflatableboss(Actor *);
    void func_80801F4C_chinflatableboss(Actor *);
    s32 func_80802590_chinflatableboss(Actor *, f32 *, s32);
    void func_80802A00_chinflatableboss(Actor *, u32, u32);
    void func_8010D5DC(s32, s32);
    extern f32 B_80803020_chinflatableboss[12][3];
    BossData *data;
    BtIntPtr player;
    s32 i;
    s32 count;
    data = func_80100094(arg0, 0);
    switch (arg1) {
    case 0xB:
        switch (arg2) {
        case 20:
            func_80800F84_chinflatableboss(arg0, 0x11);
            func_80802A00_chinflatableboss(arg0, 0x31, 0x10);
            func_80101180(0x46E, 7, 0);
            return 4;
        case 49:
            data->unk49D = 0;
            func_800FFAB0(arg0);
        default:
        normal_hit:
            return 3;
        case 3:
            if (data->unk49C == 0) {
                func_80802A00_chinflatableboss(arg0, 0xC, 0x20);
                return 4;
            }
            goto normal_hit;
        case 10:
            data->unk49D = 0;
            goto normal_hit;
        case 12:
        case 25:
        case 34:
            data->unk49A = 1;
            goto normal_hit;
        case 8:
            func_80108B04(arg0, 2);
            func_80802A00_chinflatableboss(arg0, 0xA, 0x10);
            return 4;
        }
        break;
    case 0x2E:
        func_80801958_chinflatableboss(arg0, ((BossEvent *)&arg2)->halves[0], ((BossEvent *)&arg2)->halves[1]);
        break;
    case 0x2F:
        func_80801AD8_chinflatableboss(arg0, ((BossEvent *)&arg2)->halves[0], ((BossEvent *)&arg2)->halves[1]);
        break;
    case 0x3D:
        switch (arg2) {
        case 0:
            func_80801DE0_chinflatableboss(arg0);
            break;
        case 1:
            func_80801D38_chinflatableboss(arg0);
            break;
        case 2:
            func_80801EA0_chinflatableboss(arg0);
            break;
        case 3:
            func_80801F4C_chinflatableboss(arg0);
            break;
        }
        break;
    case 0x32:
        if (data->unk498 == 2) {
            data->unk498 = 3;
            data->unk49A = 0;
            func_800F497C(func_800F54E4());
            func_800F49D4(func_800F54E4(), &func_8010D5DC, arg0->unk0);
            func_800F4A58(func_800F54E4(), data->positions[1], 300.0f);
            func_80802A00_chinflatableboss(arg0, 0x19, 0x20);
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x10CC, 0x44, arg0->position, 0x3A);
            func_80101180(0x46E, 8, 0);
        } else {
            data->unk499 = 1;
            func_800F8300(func_800F54E4(), 2, arg0->position);
        }
        break;
    case 0x3F:
        func_808010BC_chinflatableboss(arg0, ((BossEvent *)&arg2)->word);
        break;
    case 0x40:
        func_80801164_chinflatableboss(arg0, ((BossEvent *)&arg2)->word);
        break;
    case 6:
        func_80101010(data->position1);
        break;
    case 10:
        player = func_800F54E4();
        arg0->unk64_16 = 1;
        data->unk498 = 2;
        func_800F497C(player);
        func_800F49A8(player, 1);
        func_800F49D4(player, &func_8010D5DC, arg0->unk0);
        func_800F4A58(player, data->positions[0], 300.0f);
        func_80802A00_chinflatableboss(arg0, 0x2F, 0x20);
        break;
    case 0x95:
        if (data->unk496) {
            data->unk496 = 0;
            func_800FDC28(1);
        }
        break;
    case 0x96:
        if (!func_800D395C()) {
            return 0;
        }
        _subaddiedialog_entrypoint_11(arg0->unk0, 0xCEB, 0x146, arg0->position, 0x3A);
        break;
    case 0x9F:
        func_800FDC28(0);
        func_80800F84_chinflatableboss(arg0, 5);
        break;
    case 0x1F:
        func_80801418_chinflatableboss(arg0, ((BossEvent *)&arg2)->pointer);
        break;
    case 0xA2:
        count = 0;
        if (!arg0->unk7C_12) {
            return 0;
        }
        for (i = 0; i < 12; i++) {
            if (data->parts[i] == 1) {
                func_80802590_chinflatableboss(arg0, B_80803020_chinflatableboss[count], i + 3);
                count++;
            }
        }
        func_80101074(B_80803020_chinflatableboss);
        return count;
    default:
        return 0;
    }
    return 1;
}

struct anctrl_s;
void func_80800F84_chinflatableboss(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    void func_80102424(Actor *, s32);
    struct anctrl_s *func_80104248(void *);
    void func_8008B1C8(struct anctrl_s *, f32);
    s32 func_80801C7C_chinflatableboss(Actor *);
    void func_80802A00_chinflatableboss(Actor *, u32, u32);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    void func_8010A570(Actor *);
    extern s16 D_80802D8C_chinflatableboss[];
    u8 *sp2C;

    sp2C = func_80100094(arg0, 0);
    func_80102424(arg0, arg1);
    switch (arg1) {
        case 11:
            func_8008B1C8(func_80104248(arg0), 0.8f);
            sp2C[0x495] = D_80802D8C_chinflatableboss[func_80801C7C_chinflatableboss(arg0)];
            break;
        case 13:
            func_8008B1C8(func_80104248(arg0), 0.8f);
            *(f32 *)(sp2C + 0x44) = arg0->scale;
            break;
        case 14:
            func_80802A00_chinflatableboss(arg0, 0x2B, 0x30);
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x1084, 0x10C, arg0->position, 0x3A);
            func_8010A570(arg0);
            func_8008B1C8(func_80104248(arg0), 0.8f);
            break;
        case 16:
            arg0->unk64_16 = 0;
            break;
    }
}

void func_808010BC_chinflatableboss(Actor *arg0, s32 arg1) {
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    s32 func_800DA298(s32);
    void func_800DA544(s32);
    void *func_80100094(Actor *, u32);
    u8 *sp2C;
    u32 state;
    s32 index;
    Unk80132ED0 *marker;

    sp2C = func_80100094(arg0, 0);
    if (func_800DA298(5) == 0) {
        marker = arg0->unk0;
        state = (marker->unk18 << 11) >> 28;
        index = state;
        if ((s32)state >= 3 && (s32)state < 15) {
            index -= 3;
            if ((sp2C + index)[0x487] != 2) {
            _subaddiedialog_entrypoint_11(marker, 0x1086, 0x10E, arg0->position, 0x3A);
            func_800DA544(5);
            arg0->unk74_30 = 1;
            }
        }
    }
}

void func_80801164_chinflatableboss(Actor *arg0, s32 arg1) {
    typedef struct {
        u8 unk0[0x43C];
        s32 effects[12];
        u8 unk46C[0x1B];
        u8 states[12];
        u8 unk493;
    } BossData;
    void *func_80100094(Actor *, u32);
    s32 func_80802590_chinflatableboss(Actor *, f32 *, s32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_808012EC_chinflatableboss(Actor *, f32[3], s32);
    void func_80801904_chinflatableboss(Actor *, s32, f32 *);
    s32 func_80801FC0_chinflatableboss(u8 *, f32 *, f32 *);
    void func_80802AD8_chinflatableboss(Actor *, s32, s32);
    struct anctrl_s *func_80104248(void *);
    void func_8008B1C8(struct anctrl_s *, f32);
    s32 func_80801CB4_chinflatableboss(Actor *);
    void func_800DA544(s32);
    u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
    void func_80802A00_chinflatableboss(Actor *, u32, u32);
    extern u8 D_80802F08_chinflatableboss[];
    BossData *sp54;
    s32 sp50;
    f32 sp44[3];
    f32 sp38[3];
    s32 sp34;
    u32 state;
    s32 count;

    sp54 = func_80100094(arg0, 0);
    state = (arg0->unk0->unk18 << 11) >> 28;
    sp50 = state;
    if ((s32)state >= 3 && (s32)state < 15) {
        sp50 -= 3;
        if (sp54->states[sp50] != 2) {
            sp34 = func_80802590_chinflatableboss(arg0, sp44, state);
            _subaddieaudioquick_entrypoint_2(arg0, sp44, D_80802F08_chinflatableboss);
            func_808012EC_chinflatableboss(arg0, sp44, sp34);
            func_80801904_chinflatableboss(arg0, sp50, sp38);
            sp54->effects[sp50] = func_80801FC0_chinflatableboss((u8 *)arg0, sp44, sp38);
            func_80802AD8_chinflatableboss(arg0, sp50, 2);
            func_80800F84_chinflatableboss(arg0, 12);
            func_8008B1C8(func_80104248(arg0), 0.8f);
            sp54->unk493 = 1;
            count = func_80801CB4_chinflatableboss(arg0);
            if (count != 0) {
                if (count == 11) {
                    func_800DA544(5);
                    _subaddiedialog_entrypoint_11(arg0->unk0, 0x1085, 0x10E, arg0->position, 0x3A);
                    func_80802A00_chinflatableboss(arg0, 0x2D, 0x20);
                    arg0->unk74_30 = 1;
                }
            } else {
                func_800DA544(0);
                func_80802A00_chinflatableboss(arg0, 0x29, 0x30);
            }
        }
    }
}

void func_808012EC_chinflatableboss(Actor *arg0, f32 arg1[3], s32 arg2) {
    void func_800BA22C(BtIntPtr, s32);
    void func_800BA670(BtIntPtr, s32);
    void func_800BA714(void *, s16, s16);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF368(f32 *, f32);
    void func_800EFB24(void *, void *, void *);
    void func_80801904_chinflatableboss(Actor *, s32, f32 *);
    extern s16 D_80802F14_chinflatableboss[];
    extern s32 D_80802F2C_chinflatableboss[];
    f32 sp34[3];
    f32 sp28[3];
    BtIntPtr sp24;

    func_80801904_chinflatableboss(arg0, ((arg0->unk0->unk18 << 11) >> 28) - 3, sp28);
    func_800EFB24(sp34, arg1, sp28);
    func_800EF368(sp34, arg2 * 0.5f);
    func_800EF04C(sp34, arg1);
    sp24 = func_800BABB8(0, arg1, sp34, arg0->scale, D_80802F2C_chinflatableboss);
    func_800BA714(sp24, arg2 * 0.4f, arg2 * 0.6f);
    func_800BA670(sp24, D_80802F14_chinflatableboss[((arg0->unk0->unk18 << 11) >> 28) - 3]);
    func_800BA22C(sp24, 8);
}

void func_80801418_chinflatableboss(Actor *arg0, u8 *arg1) {
    typedef struct {
        u8 pad[0x478];
        u8 visibility[15];
    } BossRenderData;
    s32 _subaddiefade_entrypoint_0(Actor *);
    void _suexpression_entrypoint_19(void *, Actor *);
    void func_800DF660(s32 type,uintptr_t a,uintptr_t b,s32 alpha);
    void func_800DF720(BtIntPtr);
    void func_800DF72C(BtIntPtr);
    void func_800DF738(BtIntPtr);
    void func_800DF744(s32, s32);
    void func_800DF818(BtIntPtr);
    void func_800DF830(s32);
    void *func_80100094(Actor *, u32);
    BtIntPtr func_80100AC4(s16);
    void func_80101934(Actor *);
    BtIntPtr func_80103CDC(u8 *, u8 *);
    void func_80103D48(void **);
    s32 func_80103D70(void **);
    void *func_801040A8(Actor *);
    OSThread *func_80104130(void);
    void func_8080267C_chinflatableboss(Actor *);
    s32 i;
    BossRenderData *data;

    data = func_80100094(arg0, 0);
    func_80103D48(arg0);
    _suexpression_entrypoint_19(func_80100094(arg0, 1), arg0);
    if (!arg0->unk64_20) {
        func_8080267C_chinflatableboss(arg0);
    }
    func_800DF72C(func_801040A8(arg0));
    func_800DF830(1);
    func_800DF738(func_80104130());
    func_800DF818(func_80103CDC(arg0, arg1));
    func_800DF660(2, arg0->pad7A_7, 0, _subaddiefade_entrypoint_0(arg0));
    func_800DF720(func_80100AC4(*(s16 *)&arg0->pad60));
    func_80101934(arg0);
    func_80103D70(arg0);
    for (i = 0; i != 15; i++) {
        func_800DF744(i + 3, data->visibility[i]);
    }
    arg0->unk7C_12 = 1;
    arg0->unk64_20 = 0;
}

void func_80801554_chinflatableboss(Actor *arg0, s32 arg1) {
    typedef struct {
        u8 pad0[0x1C];
        f32 position1[3];
        f32 position2[3];
        f32 position3[3];
        u8 pad40[0x3F4];
        void *effect;
        s32 pad438;
        void *effects[12];
    } BossData;
    typedef struct {
        u8 pad0[0x10];
        f32 scale;
    } BossActorData;
    s32 _subaddiefade_entrypoint_0(Actor *);
    s32 func_800AE630(u8 *, u8 *, s32, f32 *);
    u8 *func_800B27E0(u8 *);
    void func_800BC358(void *, BtIntPtr, s32);
    struct ImageStruct;
    struct ImageStruct *func_800D674C(s32);
    void func_800DBEFC(s32 *, s32, f32 *);
    void *func_800DE448(f32 *, f32 *, f32, f32 *, u8 *);
    void func_800DF410(s32);
    void func_800DF830(s32);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    void func_800EF5A0(f32 *, f32 *, f32, f32, f32);
    void func_800EFD24(f32 *);
    void *func_80100094(Actor *, u32);
    void func_801017D0(Actor *);
    s32 func_80101808(void *, s32 *);
    void *func_801040A8(Actor *);
    OSThread *func_80104130(void);
    BossData *data;
    s32 i;
    u8 *model;
    void *transforms;
    f32 rotation[3];
    f32 position[3];
    u8 *mesh;
    void *image;

    data = func_80100094(arg0, 0);
    model = func_80101808(arg0, func_801017D0);
    if (arg0->unk7C_12) {
        transforms = func_80104130();
        func_800DBEFC(transforms, 4, data->position1);
        func_800DBEFC(transforms, 5, data->position2);
        func_800DBEFC(transforms, 6, data->position3);
    }
    if (model && (s32)arg0->unk70_10 < 16) {
        mesh = func_800B27E0(model);
        image = func_800D674C(0x637);
        func_800EFD24(rotation);
        if (func_800AE630(func_801040A8(arg0), mesh, 12, position)) {
            func_800EF334(position, ((BossActorData *)arg0->actorData)->scale);
            func_800EF5A0(position, arg0->rotation, position[0], position[1], position[2]);
            func_800EF04C(position, arg0->position);
            position[1] = arg0->position[1];
            func_800DF410(_subaddiefade_entrypoint_0(arg0));
            func_800DF830(3);
            func_800DE448(position, rotation, ((BossActorData *)arg0->actorData)->scale * 9.0f, 0, image);
        }
        if (func_800AE630(func_801040A8(arg0), mesh, 26, position)) {
            func_800EF334(position, ((BossActorData *)arg0->actorData)->scale);
            func_800EF5A0(position, arg0->rotation, position[0], position[1], position[2]);
            func_800EF04C(position, arg0->position);
            position[1] = arg0->position[1];
            func_800DF410(_subaddiefade_entrypoint_0(arg0));
            func_800DF830(3);
            func_800DE448(position, rotation, ((BossActorData *)arg0->actorData)->scale * 9.0f, 0, image);
        }
        func_800DF410(_subaddiefade_entrypoint_0(arg0));
        func_800DF830(3);
        func_800DE448(arg0->position, rotation, ((BossActorData *)arg0->actorData)->scale * 1.4f * 9.0f, 0, image);
    }
    for (i = 0; i < 12; i++) {
        if (data->effects[i]) {
            func_800BC358(data->effects[i], arg1, 0);
        }
    }
    if (data->effect) {
        func_800BC358(data->effect, arg1, 0);
    }
}

void func_8080183C_chinflatableboss(Actor *arg0) {
    typedef struct {
        u8 points[2][8];
        f32 position[3];
        u8 unk1C[0x478];
        u8 unk494;
        u8 unk495[2];
        u8 unk497;
    } BossData;
    typedef struct {
        f32 position[3];
    } BossActorData;
    void *func_80100094(Actor *, u32);
    void _subaddieDll_entrypoint_12(void *, s16 *);
    f32 func_800DC178(f32, f32);
    BossData *data;
    s16 point[2];
    void *source;

    data = func_80100094(arg0, 0);
    data->unk494 ^= 1;
    if (data->unk494) {
        source = data->points[0];
    } else {
        source = data->points[1];
    }
    _subaddieDll_entrypoint_12(source, point);
    data->position[0] = point[0];
    data->position[1] = arg0->position[1];
    data->position[2] = point[1];
    ((BossActorData *)arg0->actorData)->position[0] = func_800DC178(0.0f, 1000.0f);
    ((BossActorData *)arg0->actorData)->position[1] = arg0->position[1];
    ((BossActorData *)arg0->actorData)->position[2] = func_800DC178(0.0f, 1000.0f);
    data->unk497 = 1;
}

void func_80801904_chinflatableboss(Actor *arg0, s32 arg1, f32 *arg2) {
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    void* func_80100094(Actor*, u32);
    f32 *var_a1;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    if ((arg1 >= 3) && (arg1 < 6)) {
        var_a1 = temp_v0 + 0x34;
    } else {
        var_a1 = temp_v0 + 0x28;
    }
    func_800EE7F8(arg2, var_a1);
}

void func_80801958_chinflatableboss(Actor *arg0, s32 arg1, s32 arg2) {
    void _chintrotext_entrypoint_1(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    void _gcfrontend_entrypoint_10(void);
    void _gcfrontend_entrypoint_11(void);
    void func_8008B1C8(struct anctrl_s *, f32);
    void func_801020DC(void *, s32);
    void func_80102FDC(Actor *, f32);
    struct anctrl_s *func_80104248(void *);
    void func_8080267C_chinflatableboss(Actor *);
    void func_80802910_chinflatableboss(Actor *);
    void func_80802A00_chinflatableboss(Actor *, u32, u32);

    switch (arg1) {
        case 0x1082:
            _chintrotext_entrypoint_1(0x18B9, 3, 1, 0);
        case 0x1087:
            func_80800F84_chinflatableboss(arg0, 4);
            func_8008B1C8(func_80104248(arg0), 0.8f);
            func_80802A00_chinflatableboss(arg0, 3U, 0x20U);
            break;
        case 0x1083:
            func_80802910_chinflatableboss(arg0);
            break;
        case 0x1085:
        case 0x1086:
            arg0->unk74_30 = 0;
            break;
        case 0x1084:
            func_801020DC(arg0, 0);
            func_80102FDC(arg0, arg0->scale * 4.0f);
            func_80800F84_chinflatableboss(arg0, 0xF);
            func_8080267C_chinflatableboss(arg0);
            func_80802A00_chinflatableboss(arg0, 0xBU, 0x38U);
            break;
        case 0xCEB:
            if (arg2 > 0) {
                _gcfrontend_entrypoint_11();
            } else {
                _gcfrontend_entrypoint_10();
            }
            break;
        case 0x10CC:
            return;
    }
    func_8008B1C8(func_80104248(arg0), 0.8f);
}

void func_80801AD8_chinflatableboss(Actor *arg0, s32 arg1, s32 arg2) {
    void func_80108B04(Actor*, u32);
    if (arg1 == 0x1085) {
        func_80108B04(arg0, 0U);
    }
}

void func_80801B04_chinflatableboss(Actor *arg0) {
    typedef struct {
        u8 unk0[0x10];
        f32 position[3];
        u8 unk1C[0x24];
        f32 unk40;
        u8 unk44[0x44F];
        u8 unk493;
        u8 unk494[3];
        u8 unk497;
    } BossData;
    typedef struct {
        f32 position[3];
        f32 unkC;
    } BossActorData;
    void *func_80100094(Actor *, u32);
    f32 func_80102D78(Actor *, f32 *);
    f32 func_800D8FF8(void);
    f32 func_800F15F8(f32, f32, f32);
    void func_80102BF8(void *, f32, f32, f32);
    f32 func_80101F24(Actor *);
    f32 func_800F3780(f32, u8 *, s16);
    s32 func_8010C3A8(Actor *, u32, f32);
    int func_800F0064(f32 *, f32, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800DC178(f32, f32);
    struct anctrl_s *func_80104248(void *);
    void func_8008B1C8(struct anctrl_s *, f32);
    extern u8 D_80802F68_chinflatableboss[];
    BossData *data;

    data = func_80100094(arg0, 0);
    arg0->unk54 = func_80102D78(arg0, ((BossActorData *)arg0->actorData)->position);
    ((BossActorData *)arg0->actorData)->unkC = func_800F15F8(((BossActorData *)arg0->actorData)->unkC, data->unk40, func_800D8FF8() * 200.0f);
    func_80102BF8(arg0, 0.1f, 3.0f, 60.0f);
    func_8010C3A8(arg0, 5, func_800F3780(func_80101F24(arg0), D_80802F68_chinflatableboss, 5));
    if (func_800F0064(((BossActorData *)arg0->actorData)->position, 400.0f, arg0->position)) {
        if (data->unk497) {
            func_80800F84_chinflatableboss(arg0, 7);
            func_800EE7F8(((BossActorData *)arg0->actorData)->position, data->position);
            data->unk497 = 0;
            arg0->unk58 = func_800DC178(4.0f, 6.0f);
        } else if (data->unk493 == 0) {
            func_80800F84_chinflatableboss(arg0, 9);
            arg0->unk58 = func_800DC178(6.0f, 8.0f);
        } else {
            func_80800F84_chinflatableboss(arg0, 10);
        }
        func_8008B1C8(func_80104248(arg0), 0.8f);
    }
}

/* extern */

s32 func_80801C7C_chinflatableboss(Actor *arg0) {
    s32 func_80801CB4_chinflatableboss(Actor *);
    return (s32) (0xC - func_80801CB4_chinflatableboss(arg0)) / 2;
}

s32 func_80801CB4_chinflatableboss(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 remaining;
    s32 i;
    u8 *data;

    data = func_80100094(arg0, 0U);
    remaining = 12;
    for (i = 0; i < 12; i++) {
        if (data[0x487 + i] == 2) {
            remaining--;
        }
    }
    return remaining;
}

void func_80801D38_chinflatableboss(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    void func_80102FDC(Actor *, f32);
    Actor *func_80108528(s32, f32[3], s32, Actor **);
    extern f32 D_80802D98_chinflatableboss[];
    u8 *sp24;
    Actor *sp20;
    s32 sp1C;

    sp24 = func_80100094(arg0, 0);
    sp1C = func_80801C7C_chinflatableboss(arg0);
    sp20 = func_80108528(0x13D, (f32 *)(sp24 + 0x1C), 0, &arg0);
    func_80102FDC(sp20, arg0->scale);
    sp20->unk3C = arg0->unk0;
    sp20->unk6C_0 = func_80801CB4_chinflatableboss(arg0);
    sp20->unk58 = D_80802D98_chinflatableboss[sp1C];
}

void func_80801DE0_chinflatableboss(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    Actor *func_80108528(s32, f32[3], s32, Actor **);
    void _chappearfx_entrypoint_1(Actor *, u32, u32, f32);
    s32 func_800DA298(s32);
    void func_800DA544(s32);
    void func_80802A00_chinflatableboss(Actor *, u32, u32);
    void func_80802A9C_chinflatableboss(Actor *);
    void func_80801EA0_chinflatableboss(Actor *);
    u8 *data;

    data = func_80100094(arg0, 0);
    _chappearfx_entrypoint_1(func_80108528(0x13E, (f32 *)(data + 0x254), (s32)*(f32 *)(data + 0x264), &arg0), 0x22, 0, 1.0f);
    func_80108528(0x36E, (f32 *)(data + 0x254), (s32)*(f32 *)(data + 0x264), &arg0);
    if (func_800DA298(0x6AC) == 0) {
        func_800DA544(0x6AC);
        func_80802A00_chinflatableboss(arg0, 8, 0x30);
    } else {
        func_80802A9C_chinflatableboss(arg0);
        func_80801EA0_chinflatableboss(arg0);
    }
}

void func_80801EA0_chinflatableboss(Actor *arg0) {
    typedef struct {
        f32 position[3];
        f32 unkC;
        f32 rotation;
        f32 unk14;
    } BossSpawn;
    typedef struct {
        u8 pad0[0x6C];
        s32 count;
        BossSpawn spawns[20];
    } BossSpawns;
    void *func_80100094(Actor *, u32);
    Actor *func_80108474(u32, f32 *, s32);
    void _chappearfx_entrypoint_2(Actor *, s32, s32, f32);
    s32 i;
    BossSpawns *data;

    data = func_80100094(arg0, 0);
    for (i = 0; i < data->count; i++) {
        _chappearfx_entrypoint_2(func_80108474(0x234, data->spawns[i].position, (s32)data->spawns[i].rotation), 0x20, 2, 1.0f);
    }
}

/* extern */

void func_80801F4C_chinflatableboss(Actor *arg0) {
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    Actor* func_80106790(Unk80132ED0 *);
    BtIntPtr func_800D10D4(s32, s32, f32 *, s32, BtIntPtr);
    void func_80802A2C_chinflatableboss(Actor *, Unk80132ED0 *, u32, u32);
    f32 sp2C[3];
    BtIntPtr sp28;
    Unk80132ED0 *sp24;

    sp24 = arg0->unk0;
    func_800EE7F8(sp2C, arg0->position);
    sp2C[1] = 5000.0f;
    sp28 = func_800D10D4(0x17, 1, sp2C, 0, 0);
    func_80802A2C_chinflatableboss(func_80106790(sp24), (Unk80132ED0 *)sp28, 0x14, 0x438);
}

s32 func_80801FC0_chinflatableboss(u8 *arg0, f32 *arg1, f32 *arg2) {
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    extern s32 D_80802F90_chinflatableboss[];
    BT_NATIVE_ONLY(return) func_800BABB8(0, arg1, arg2, (((Actor *)arg0)->scale) * 0.75f, &D_80802F90_chinflatableboss);
}

s32 func_8080200C_chinflatableboss(Actor *arg0, f32 *arg1, f32 *arg2) {
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    extern s32 D_80802FC4_chinflatableboss[];
    BT_NATIVE_ONLY(return) func_800BABB8(0, arg1, arg2, (arg0->scale) * 0.75f, &D_80802FC4_chinflatableboss);
}

void func_80802058_chinflatableboss(Actor *arg0) {
    typedef struct {
        u8 pad0[0x28];
        f32 position[3];
        u8 pad34[0x400];
        s32 effect;
        u8 sound;
        u8 pad439[3];
        s32 effects[12];
        u8 sounds[12];
    } BossData;
    s8 _subaddieaudioloop_entrypoint_7(u8, f32 *, s32, s32 *, s32);
    s32 _subaddieskeleton_entrypoint_3(Unk80132ED0 *, s32, f32 *);
    s32 func_800BA198(void *);
    int func_800BA28C(void *);
    s32 func_800BA2C4(void *);
    void func_800BBD18(s32, f32 *, f32 *, f32, s32 *);
    void *func_80100094(Actor *, u32);
    f32 func_80101F24(Actor *);
    s32 func_80802590_chinflatableboss(Actor *, f32 *, s32);
    extern s32 D_80802FF8_chinflatableboss[];
    s32 *effects;
    u8 *sounds;
    s32 i;
    BossData *data;
    f32 sp6C[3];
    f32 sp60[3];
    f32 sp54[3];
    s32 effect;

    data = func_80100094(arg0, 0);
    effects = data->effects;
    sounds = data->sounds;
    i = 0;
    do {
        if (*effects != 0 || *sounds != 0) {
            func_80801904_chinflatableboss(arg0, i + 3, sp60);
            func_80802590_chinflatableboss(arg0, sp6C, i + 3);
            effect = *effects;
            *sounds = _subaddieaudioloop_entrypoint_7(*sounds, sp6C,
                effect != 0 && func_800BA198((void *)effect) >= 8,
                &D_80802FF8_chinflatableboss, arg0->unk70_0);
            effect = *effects;
            if (effect != 0) {
                func_800BBD18(effect, sp6C, sp60, arg0->scale, NULL);
                if (func_800BA28C((void *)*effects)) {
                    data->effects[i] = func_800BA2C4((void *)*effects);
                }
            }
        }
        i++;
        effects++;
        sounds++;
    } while (i != 12);
    if (data->effect != 0 || data->sound != 0) {
        _subaddieskeleton_entrypoint_3(arg0->unk0, 7, sp54);
        data->sound = _subaddieaudioloop_entrypoint_7(data->sound, sp54,
            data->effect != 0 && func_80101F24(arg0) < 0.43f,
            &D_80802FF8_chinflatableboss, arg0->unk70_0);
        if (data->effect != 0) {
            func_800BBD18(data->effect, sp54, data->position, arg0->scale, NULL);
            if (func_800BA28C((void *)data->effect)) {
                data->effect = func_800BA2C4((void *)data->effect);
            }
        }
    }
}

void func_80802264_chinflatableboss(Actor *arg0, f32 arg1, f32 arg2, f32 *arg3, s16 arg4) {
    u8 _subaddieaudioquick_entrypoint_1(Actor *, f32 *);
    void func_800C3868(u8, f32, f32, f32, f32);
    u8 func_800C4350(u8, f32[3], s32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    s32 func_80101E14(Actor *, f32);
    extern s32 D_80803008_chinflatableboss[];
    f32 temp_f20;
    f32 *var_s1;
    f32 *temp_s0;
    u8 temp_v0;
    int var_s2;
    var_s2 = 0;
    if (arg4 > 0) {
    var_s1 = arg3; do { if (func_80101E14(arg0, *var_s1) != 0) {
    temp_s0 = arg0->position;
    temp_f20 = func_800F10B4((f32) var_s2, 0.0f, (f32) arg4, arg1, arg2);
    temp_v0 = _subaddieaudioquick_entrypoint_1(arg0, temp_s0);
    func_800C3868(temp_v0, 0.15f, 0.25f, temp_f20, temp_f20 + 0.12f);
    func_800C4350(temp_v0, temp_s0, &D_80803008_chinflatableboss);
    }
    var_s2++;
    var_s1++;
    }
    while (var_s2 < arg4);
    }
    }

f32 func_808023B0_chinflatableboss(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    f32 result;
    s32 i;
    u8 *data;

    data = func_80100094(arg0, 0);
    result = 1.4f;
    for (i = 0; i < 12; i++) {
        if (data[0x487 + i] == 2) {
            result *= 0.85f;
        }
    }
    return result;
}

/* extern */

void func_80802450_chinflatableboss(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    f32 func_80101F24(Actor *);
    void func_80102FDC(Actor *, f32);
    f32 func_808023B0_chinflatableboss(Actor *);
    Actor *sp1C;
    f32 sp18;

    sp1C = func_80100094(arg0, 0);
    sp18 = sp1C->rotation[0] - func_808023B0_chinflatableboss(arg0);
    func_80102FDC(arg0, sp1C->rotation[0] - (func_80101F24(arg0) * sp18));
}

void func_808024BC_chinflatableboss(Actor *arg0) {
    typedef struct {
        u8 unk0[0x40];
        f32 duration;
        u8 unk44[0x453];
        u8 unk497;
    } BossData;
    void *func_80100094(Actor *, u32);
    void func_80101CDC(Actor *, f32);
    struct anctrl_s *func_80104248(void *);
    void func_8008B1C8(struct anctrl_s *, f32);
    void func_80800F84_chinflatableboss(Actor *, s32);
    extern s16 D_80802D80_chinflatableboss[];
    BossData *sp24;
    f32 duration;

    sp24 = func_80100094(arg0, 0);
    sp24->duration = D_80802D80_chinflatableboss[func_80801C7C_chinflatableboss(arg0)];
    *(f32 *)&arg0->actorData[3] = 0.0f;
    func_80800F84_chinflatableboss(arg0, sp24->unk497 != 0 ? 6 : 8);
    duration = ((f32)D_80802D80_chinflatableboss[0] / sp24->duration) * 5.0f;
    func_80101CDC(arg0, duration);
    func_8008B1C8(func_80104248(arg0), 0.8f);
}

s32 func_80802590_chinflatableboss(Actor *arg0, f32 *arg1, s32 arg2) {
    s32 func_800AE0B8(s32 *);
    s32 func_800B0D80(u8 *arg0, s32 arg1, f32 *arg2, f32 *arg3, f32 arg4, f32 *arg5, BtIntPtr arg6, f32 *arg7, f32 *arg8);
    u8 *func_800B2824(u8 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    u8 *func_801039E4(Unk80132ED0 *);
    void *func_801040A8(Actor *);
    f32 sp4C[3];
    f32 sp48;
    u8 *sp44;

    if (func_800AE0B8(func_801040A8(arg0)) == 0) {
        func_800EE7F8(arg1, arg0->position);
        return 0;
    }
    sp44 = func_801039E4(arg0->unk0);
    func_800EFA4C(sp4C, 0.0f, arg0->rotation[1], 0.0f);
    if (func_800B0D80(func_800B2824(sp44), arg2, arg0->position, sp4C, arg0->scale, 0, func_801040A8(arg0), arg1, &sp48) == 0) {
        func_800EE7F8(arg1, arg0->position);
        return 0;
    }
    return (s32)sp48;
}

/* extern */

void func_8080267C_chinflatableboss(Actor *arg0) {
    struct Marker { u8 pad0[0x10]; s16 animIndex; };
    void *func_8008AEDC(void *);
    void func_8008B304(BtIntPtr);
    void func_8008C200(s16, BtIntPtr, BtIntPtr);
    s32 *func_8008C27C(void *);
    u8 *func_800B27E0(u8 *);
    void func_800DFBE0(s32 *, s32, f32 *);
    u8 *func_801039E4(Unk80132ED0 *);
    struct anctrl_s *func_80104248(void *);
    f64 pad;
    struct anctrl_s *sp34;
    f32 sp28[3];
    u8 *sp24;

    sp34 = func_80104248(arg0);
    if (arg0->unk64_16) {
        sp24 = func_801039E4(arg0->unk0);
        sp24 = func_800B27E0(sp24);
        func_8008B304(sp34);
        func_8008C200(((struct Marker *)arg0->unk0)->animIndex, sp24, func_8008AEDC(sp34));
        sp24 = func_8008AEDC(sp34);
        func_800DFBE0(func_8008C27C(sp24), 3, sp28);
        ((f32 *)arg0->actorData)[4] = sp28[0] * arg0->scale;
        arg0->unk64_20 = 1;
    }
}

s32 func_8080272C_chinflatableboss(Actor *arg0) {
    void func_8008B1C8(struct anctrl_s *, f32);
    void func_800DA544(s32);
    void func_800F497C(BtIntPtr);
    void func_800F49D4(BtIntPtr, void *, BtIntPtr);
    void func_800F4A58(BtIntPtr, f32 *, f32);
    BtUIntPtr func_800F54E4(void);
    void func_800F82D4(BtIntPtr, s32);
    u32 func_800FDC28(u32);
    void *func_80100094(Actor *, u32);
    struct anctrl_s *func_80104248(void *);
    void func_8010A85C(u8 *, s32);
    void func_8010D5DC(s32, s32);
    void func_80800F84_chinflatableboss(Actor *, s32);
    void func_80802A00_chinflatableboss(Actor *, u32, u32);
    struct InflatableSequenceData {
        u8 prefix[0x60];
        f32 position[3];
        u8 unknown6C[0x42C];
        u8 state;
        u8 flag499;
        u8 flag49A;
        u8 flag49B;
    } *data;

    data = func_80100094(arg0, 0);
    switch (data->state) {
    case 1:
        break;
    case 3:
        if (data->flag49A && data->flag499) {
            if (!data->flag49B) {
                func_800DA544(2);
                func_80800F84_chinflatableboss(arg0, 2);
                func_8008B1C8(func_80104248(arg0), 0.8f);
                func_8010A85C((u8 *)arg0, 1);
                func_80802A00_chinflatableboss(arg0, 1, 0x20);
                data->flag49B = 1;
                func_800FDC28(1);
            }
            if (arg0->unk70_10 == 4) {
                data->flag49A = data->flag499 = 0;
                func_800F82D4(func_800F54E4(), 0);
                func_800F497C(func_800F54E4());
                func_800F49D4(func_800F54E4(), func_8010D5DC, (BtIntPtr)arg0->unk0);
                func_800F4A58(func_800F54E4(), data->position, 400.0f);
                data->state = 4;
            }
        }
        break;
    case 5:
        if (arg0->unk70_10 == 4) {
            data->flag49A = 0;
            data->flag499 = 1;
            func_800F82D4(func_800F54E4(), 0);
            func_800F497C(func_800F54E4());
            func_800F49D4(func_800F54E4(), func_8010D5DC, (BtIntPtr)arg0->unk0);
            func_800F4A58(func_800F54E4(), data->position, 400.0f);
            data->state = 4;
        }
        break;
    case 6:
        break;
    }
    return 0;
}

void func_80802910_chinflatableboss(Actor *arg0) {
    void _gcfrontend_entrypoint_9(s32 arg0);
    void func_800A51C0(void);
    void func_800DA544(s32);
    BtUIntPtr func_800F54E4(void);
    void func_800F82D4(BtIntPtr, s32);
    u32 func_800FDC28(u32);
    void *func_80100094(Actor *, u32);
    void func_80109FE8(Actor *, s32);
    void func_8010A590(Actor *);
    void func_808024BC_chinflatableboss(Actor *);
    void func_80802A9C_chinflatableboss(Actor *);
    u8 *sp24;

    sp24 = func_80100094(arg0, 0);
    func_800FDC28(4);
    func_80802A9C_chinflatableboss(arg0);
    func_800A51C0();
    func_808024BC_chinflatableboss(arg0);
    func_800DA544(1);
    func_800DA544(0x17F);
    _gcfrontend_entrypoint_9(0x25);
    func_800F82D4(func_800F54E4(), 0);
    sp24[0x498] = 6;
    func_8010A590(arg0);
    func_80109FE8(arg0, 1);
}

/* extern */

void func_808029AC_chinflatableboss(Actor *arg0) {
    s32 func_800D2498(s32, s32, s32);
    s32 func_800DA298(s32);
    s32 func_80801CB4_chinflatableboss(Actor *);
    if ((func_800DA298(1) != 0) && (func_800DA298(3) == 0)) {
        func_800D2498(0xEC, func_80801CB4_chinflatableboss(arg0), 0);
    }
}

void func_80802A00_chinflatableboss(Actor *arg0, u32 arg1, u32 arg2) {
    void func_80802A2C_chinflatableboss(Actor *, Unk80132ED0 *, u32, u32);

    func_80802A2C_chinflatableboss(arg0, arg0->unk0, arg1, arg2);
}    typedef struct { u8 pad0[0x49D]; u8 unk49D; } Objinflatableboss_func_80802A2C_chinflatableboss_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */ typedef struct { u8 pad0[0x49D]; s8 unk49D; } Objinflatableboss_func_80802A2C_chinflatableboss_sp1C; /* offsets.py genstruct: fields from raw offsets on sp1C; rename once understood */

void func_80802A2C_chinflatableboss(Actor *arg0, Unk80132ED0 *arg1, u32 arg2, u32 arg3) {
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    s32 _capod_entrypoint_14(void);
    void* func_80100094(Actor*, u32);
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    sp1C = temp_v0;
    if ((((Objinflatableboss_func_80802A2C_chinflatableboss_temp_v0 *)temp_v0)->unk49D) != 0) {
        arg3 |= 0x2000;
        _capod_entrypoint_14();
    }
    _capod_entrypoint_13(arg1, arg0->unk0, arg2, arg3);
    (((Objinflatableboss_func_80802A2C_chinflatableboss_sp1C *)sp1C)->unk49D) = 1;
}    typedef struct { u8 pad0[0x49D]; u8 unk49D; } Objinflatableboss_func_80802A9C_chinflatableboss_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void func_80802A9C_chinflatableboss(Actor *arg0) {
    s32 _capod_entrypoint_14(void);
    void* func_80100094(Actor*, u32);
    u8 *sp1C[1];
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    if ((((Objinflatableboss_func_80802A9C_chinflatableboss_temp_v0 *)temp_v0)->unk49D) != 0) {
        sp1C[0] = temp_v0;
        _capod_entrypoint_14();
        temp_v0 = sp1C[0];
        (*(s8 *)((s8 *)(temp_v0) + (0x49D))) = 0;
    }
}    typedef struct { u8 pad0[0x478]; s8 unk478; u8 pad479[0xE]; s8 unk487; } Objinflatableboss_func_80802AD8_chinflatableboss_temp_v1; /* offsets.py genstruct: fields from raw offsets on temp_v1; rename once understood */ typedef struct { u8 pad0[0x478]; s8 unk478; s8 unk479; } Objinflatableboss_func_80802AD8_chinflatableboss_temp_v1_2; /* offsets.py genstruct: fields from raw offsets on temp_v1_2; rename once understood */

void func_80802AD8_chinflatableboss(Actor *arg0, s32 arg1, s32 arg2) {
    void* func_80100094(Actor*, u32);
    u8 *temp_v0;
    u8 *temp_v1;
    u8 *temp_v1_2;

    temp_v0 = func_80100094(arg0, 0U);
    temp_v1 = temp_v0 + arg1;
    (((Objinflatableboss_func_80802AD8_chinflatableboss_temp_v1 *)temp_v1)->unk487) = (s8) arg2;
    if (arg1 >= 9) {
        arg1 = arg1 + arg1;
        arg1 -= 9;
        temp_v1_2 = temp_v0 + arg1;
        (((Objinflatableboss_func_80802AD8_chinflatableboss_temp_v1_2 *)temp_v1_2)->unk478) = (s8) arg2;
        (((Objinflatableboss_func_80802AD8_chinflatableboss_temp_v1_2 *)temp_v1_2)->unk479) = (s8) arg2;
    } else {
        (((Objinflatableboss_func_80802AD8_chinflatableboss_temp_v1 *)temp_v1)->unk478) = (s8) arg2;
    }
}

void func_80105834();
OSThread *func_80108ED0(void);
void func_80107C2C();
s16 D_80802D80_chinflatableboss[] = {
    0x0190, 0x01F4, 0x0258, 0x02BC, 0x0320, 0x0384,
};
s16 D_80802D8C_chinflatableboss[] = {
    0x0001, 0x0001, 0x0002, 0x0002, 0x0003, 0x0003,
};
f32 D_80802D98_chinflatableboss[] = {
    3.0f, 2.79999995f, 2.5999999f, 2.4000001f,
    2.20000005f, 2.0f,
};
u32 D_80802DB0_chinflatableboss[] = {
    0x00000000, 0x00000000, 0x41100000, 0x02040044,
    0x41100000, 0x02040002, 0x40900000, 0x02080001,
    0x40F00000, 0x02050002, 0x40900000, 0x02020001,
    0x40A00000, 0x02030001, 0x40900000, 0x02020001,
    0x40A00000, 0x02030001, 0x40900000, 0x02020001,
    0x40900000, 0x02020001, 0x3FE66666, 0x02090001,
    0x40000000, 0x02060002, 0x40400000, 0x02020002,
    0x40900000, 0x02020001, 0x40CCCCCD, 0x020A0002,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x40F00000, 0x02050002, 0x40900000, 0x02020001,
};
BtFnWord D_80802E50_chinflatableboss[] = {
    0x018E013C, 0x07940001, (BtFnWord)D_80802DB0_chinflatableboss, (BtFnWord)func_808004A0_chinflatableboss,
    (BtFnWord)func_80105834, (BtFnWord)func_80801554_chinflatableboss, 0x00000000, 0x00000000,
    0x00000000, 0x3000042A, (BtFnWord)func_80800408_chinflatableboss, (BtFnWord)func_80108ED0,
    0x04A00000, (BtFnWord)func_8080000C_chinflatableboss, (BtFnWord)func_80107C2C, 0x80200402,
    (BtFnWord)func_80800A98_chinflatableboss, 0x00000000,
};
f32 D_80802E98_chinflatableboss[] = {
    0.0500000007f, 0.219999999f,
};
f32 D_80802EA0_chinflatableboss[] = {
    0.349999994f, 0.430000007f, 0.550000012f, 0.639999986f,
    0.74000001f,
};
f32 D_80802EB4_chinflatableboss[] = {
    0.00999999978f, 0.150000006f, 0.400000006f, 0.699999988f,
};
u32 D_80802EC4_chinflatableboss[] = {
    0x001304FF, 0x0018001D, 0x00020000,
};
u32 D_80802ED0_chinflatableboss[] = {
    0x001304FE, 0x0018001D, 0x00020000,
};
u32 D_80802EDC_chinflatableboss[] = {
    0x001304B1, 0x00180002, 0x00000000,
};
u32 D_80802EE8_chinflatableboss[] = {
    0x001304FD, 0x00176D60, 0x7D0001F4, 0x00150000,
    0x033300A3, 0x000E0100, 0x014C0180, 0x00020000,
};
u8 D_80802F08_chinflatableboss[] = {
    0x00, 0x13, 0x04, 0xFB, 0x00, 0x18, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00,
};
s16 D_80802F14_chinflatableboss[] = {
    0x079A, 0x0798, 0x0799, 0x0798, 0x0797,
    0x0797, 0x0799, 0x0797, 0x0797, 0x0798, 0x0799, 0x079A,
};
s32 D_80802F2C_chinflatableboss[] = {
    0x01130810, 0x002200C0, 0x00D90073, 0x008C0015,
    0x00000099, 0x0027FE0C, 0xFE0C01F4, 0x01F4002D,
    0x06A40898, 0x001BFC18, 0xFB500005, 0x00000016,
    0x0204002B, 0x04000500, 0x00000000,
};
u8 D_80802F68_chinflatableboss[] = {
    0x00, 0x00, 0x00, 0x00, 0x3F, 0x19, 0x99, 0x9A, 0x3E, 0x80, 0x00, 0x00, 0x3F, 0x80, 0x00, 0x00,
    0x3F, 0x00, 0x00, 0x00, 0x3F, 0x19, 0x99, 0x9A, 0x3F, 0x40, 0x00, 0x00, 0x3F, 0x80, 0x00, 0x00,
    0x3F, 0x80, 0x00, 0x00, 0x3F, 0x19, 0x99, 0x9A,
};
s32 D_80802F90_chinflatableboss[] = {
    0x01130A1C, 0x001D09DD, 0x00160200, 0x002D05DC,
    0x07080022, 0x02800300, 0x07000880, 0x00150000,
    0x0099002A, 0x00000000, 0x00CC00E6, 0x00280500,
    0x00000000,
};
s32 D_80802FC4_chinflatableboss[] = {
    0x0113141C, 0x001D09DD, 0x00160200, 0x002D04B0,
    0x05DC0022, 0x01800200, 0x04000500, 0x00150000,
    0x0099002A, 0x00000000, 0x00660080, 0x0028051E,
    0x00000000,
};
s32 D_80802FF8_chinflatableboss[] = {
    0x001304DC, 0x0018000D, 0x01190133, 0x00020000,
};
s32 D_80803008_chinflatableboss[] = {
    0x000F0013, 0x04FA0018, 0x00020011, 0x00000000,
    0x00000000, 0x00000000,
};

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
f32 B_80803020_chinflatableboss [ 12 ] [ 3 ] BT_DATA(16, bss_ch_inflatableboss, 0x0);
#endif
