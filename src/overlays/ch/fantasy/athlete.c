#include "common.h"

extern u8 D_80803030_chfantasyathlete[];
void func_801018A4(Actor *, s32);
void *func_80107C2C(s32 *, s32, void *, s32, void *);
OSThread *func_80108ED0(void);
void func_80800060_chfantasyathlete();
s32 func_80800314_chfantasyathlete(s32 arg0);
s32 func_808011E4_chfantasyathlete(Actor *arg0, s32 arg1, s32 arg2);
void func_80802DA8_chfantasyathlete(s32 arg0);

u32 D_808031B0_chfantasyathlete[] = {
    0x00000000,
};

u32 D_808031B4_chfantasyathlete[] = {
    0x01580477, 0x089E0001,
    (u32)D_80803030_chfantasyathlete, (u32)func_80802DA8_chfantasyathlete,
    (u32)func_80800314_chfantasyathlete, (u32)func_801018A4,
    0x0BB80000, 0x3FC00000,
    0x00000000, 0x00840100,
    0x00000000, (u32)func_80108ED0,
    0x00B00000, (u32)func_80800060_chfantasyathlete,
    (u32)func_80107C2C, 0x84004402,
    (u32)func_808011E4_chfantasyathlete, 0x00000000,
    0x00000000,
};
#include "core2/1E9A960.h"
#include "core2/1EB5980.h"
#include "core2/1EDB4D0.h"

extern u16 D_80803034_chfantasyathlete[][4];

/* extern */

void func_80800000_chfantasyathlete(s32 arg0, s32 arg1) {
    s32 func_800C78CC(s32);
    s32 func_800DA9E4(s32, s32);
    if (arg1 != 0) {
        if (func_800DA9E4(0xA51, 1) == 0) {
            func_800C78CC(1);
        }
    } else if (func_800DA9E4(0xA51, 0) != 0) {
        func_800C78CC(0);
    }
}

struct AthletePaths {
        u8 pad0[0x78];
        s32 unk78[7];
        f32 unk94[7];
};

void func_80800060_chfantasyathlete(Actor *arg0) {
    s32 _gccubesearch_entrypoint_9(s32, Prop **, s32);
    s32 _glcutDll_entrypoint_20(void);
    void _gspropctrl_entrypoint_11(Prop *, f32[3]);
    s32 func_800D0A9C(u32, u32);
    s32 func_800DA298(s32);
    s32 func_800DA524(s32);
    s32 func_800EA090(void);
    u32 func_800F54E4(void);
    void func_800F608C(s32, s32);
    void func_800FFA88(Unk80132ED0 *);
    void *func_80100094(Actor *, u32);
    void func_8080094C_chfantasyathlete(Actor *, s32);
    void func_808015D8_chfantasyathlete(f32 *, f32 *, f32 *, f32 *, f32 *);
    void func_80801654_chfantasyathlete(s32, struct AthletePaths *);
    struct AthletePaths *data;
    Prop *props[2];
    f32 position[3];

    if (_glcutDll_entrypoint_20() != 0) {
        func_8080094C_chfantasyathlete(arg0, 0x22);
        return;
    }
    data = func_80100094(arg0, 0);
    if (func_800D0A9C(0x48, 1) == 0) {
        func_80801654_chfantasyathlete((s32)arg0, data);
        _gccubesearch_entrypoint_9(0x47B, props, 2);
        _gspropctrl_entrypoint_11(props[0], position);
        _gspropctrl_entrypoint_11(props[1], (f32 *)&data->pad0[0x50]);
        func_808015D8_chfantasyathlete(position, (f32 *)&data->pad0[0x50], (f32 *)&data->pad0[0x68], (f32 *)&data->pad0[0x5C], (f32 *)&data->pad0[0x74]);
        if (func_800DA298(0x3DD) != 0) {
            if (func_800EA090() != 0x18) {
                func_8080094C_chfantasyathlete(arg0, 0x16);
            }
        } else {
            _gccubesearch_entrypoint_9(0x47A, props, 2);
            _gspropctrl_entrypoint_11(props[0], (f32 *)&data->pad0[0x28]);
            _gspropctrl_entrypoint_11(props[1], position);
            func_808015D8_chfantasyathlete(position, (f32 *)&data->pad0[0x28], (f32 *)&data->pad0[0x40], (f32 *)&data->pad0[0x34], (f32 *)&data->pad0[0x4C]);
            if (func_800DA298(0x3DC) != 0) {
                if (func_800EA090() != 0x17) {
                    func_8080094C_chfantasyathlete(arg0, 8);
                }
            } else {
                _gccubesearch_entrypoint_9(0x478, props, 2);
                _gspropctrl_entrypoint_11(props[1], (f32 *)data->pad0);
                _gspropctrl_entrypoint_11(props[0], position);
                func_808015D8_chfantasyathlete(position, (f32 *)data->pad0, (f32 *)&data->pad0[0x18], (f32 *)&data->pad0[0xC], (f32 *)&data->pad0[0x24]);
                func_8080094C_chfantasyathlete(arg0, 1);
            }
        }
        if (func_800EA090() == 0x17) {
            func_800F608C(func_800F54E4(), 3);
            if (func_800DA298(0x6D6) != 0) {
                if (func_800DA298(0x6D7) != 0) {
                    func_8080094C_chfantasyathlete(arg0, 0xF);
                } else {
                    func_8080094C_chfantasyathlete(arg0, 0xE);
                }
                func_800DA524(0x6D6);
                return;
            }
            func_8080094C_chfantasyathlete(arg0, 0xB);
            return;
        }
        if (func_800EA090() == 0x18) {
            if (func_800DA298(0x6D6) != 0) {
                if (func_800DA298(0x6D7) != 0) {
                    func_8080094C_chfantasyathlete(arg0, 0x1D);
                } else {
                    func_8080094C_chfantasyathlete(arg0, 0x1C);
                }
                func_800DA524(0x6D6);
                return;
            }
            func_8080094C_chfantasyathlete(arg0, 0x19);
        }
    } else {
        func_800FFA88(arg0->unk0);
    }
}

s32 func_80800314_chfantasyathlete(s32 arg0) {
    s32 _gcgoto_entrypoint_1(s32, s32);
    s32 func_80016B30(s32, s32);
    s32 func_800D90A4(f32 *);
    s32 func_800DA298(s32);
    s32 func_800DA544(s32);
    s32 func_800EA05C(void);
    s32 func_800F5410(s32);
    f32 func_800F549C(s32, int);
    u32 func_800F54E4(void);
    void func_800F5A00(s32, f32 *);
    s32 func_800F5C94(s32);
    s32 func_800F64A4(s32, s32);
    int func_800F6720(s32);
    s32 func_800F6C5C(s32);
    s32 func_800FCCD4(s32);
    void func_800FFA88(Unk80132ED0 *);
    void *func_80100094(Actor *, u32);
    void func_80105834(Actor *);
    s32 func_80105A5C(Actor *);
    f32 func_80105B0C(Actor *, f32);
    void func_8010C908(s32, s32);
    s32 func_8010C9B0(f32 *, s32);
    void func_8080094C_chfantasyathlete(Actor *, s32);
    s32 func_80801114_chfantasyathlete(s32, f32 *, f32 *, f32 *, f32, f32 *, f32 *);
    void func_80801718_chfantasyathlete(Actor *);
    void func_80801974_chfantasyathlete(Actor *);
    s32 func_80802730_chfantasyathlete(Actor *, s32, s32, s16, s16, s32);
    s32 func_80802950_chfantasyathlete(Actor *);
    s32 func_8080298C_chfantasyathlete(Actor *, f32 *, f32 *, f32 *, f32);
    void func_80802D38_chfantasyathlete(void *);
    f32 *data;
    s32 text1;
    s32 text2;
    f32 position[3];

    data = func_80100094((Actor *)arg0, 0);
    switch (((Actor *)arg0)->unk70_10) {
        case 1:
            text1 = 0;
            switch (func_800F5410(func_800F54E4())) {
                case 1:
                    text1 = 0x13E0;
                    text2 = 0x13E1;
                    break;
                case 10:
                    text1 = 0x1454;
                    text2 = 0x13E1;
                    break;
                case 11:
                    text1 = 0x1455;
                    text2 = 0x1456;
                    break;
            }
            if (text1 != 0) {
                func_80802730_chfantasyathlete((Actor *)arg0, 0x3D9, 0x1F4, text1, text2, 0);
            }
            if (!func_800F6720(func_800F54E4()) && func_800DA298(0x3D9)) {
                func_800F5A00(func_800F54E4(), position);
                if (func_80801114_chfantasyathlete((s32)arg0, data + 3, data + 6, data, data[9], position, (f32 *)&((Actor *)arg0)->actorData[5])) {
                    func_8080094C_chfantasyathlete((Actor *)arg0, 2);
                }
            }
            break;
        case 2:
            if (func_800F6C5C(func_800F54E4())) {
                func_8080094C_chfantasyathlete((Actor *)arg0, 3);
            }
            break;
        case 3:
            if (func_800D90A4(&((Actor *)arg0)->unk58)) {
                func_8080094C_chfantasyathlete((Actor *)arg0, 4);
            }
            break;
        case 4:
            func_80802730_chfantasyathlete((Actor *)arg0, 0, 0, 0x13E2, 0, 0);
            break;
        case 5:
            if (func_80802950_chfantasyathlete((Actor *)arg0)) {
                func_8080094C_chfantasyathlete((Actor *)arg0, ((Actor *)arg0)->unk70_10 + 1);
            }
            break;
        case 6:
        case 7:
        case 20:
        case 21:
            func_80801718_chfantasyathlete((Actor *)arg0);
            func_80105834((Actor *)arg0);
            if (func_80105A5C((Actor *)arg0)) {
                func_8080094C_chfantasyathlete((Actor *)arg0, ((Actor *)arg0)->unk70_10 + 1);
            }
            break;
        case 8:
            if (func_800F64A4(func_800F54E4(), 0x200) && func_800F5C94(func_800F54E4()) == 12) {
                if (func_800D90A4(&((Actor *)arg0)->unk58)) {
                    func_80802730_chfantasyathlete((Actor *)arg0, 0, 0x1F4, func_800DA298(0x341) ? 0x1435 : 0x1434, 0, 1);
                }
            } else {
                ((Actor *)arg0)->unk58 = 2.0f;
                func_80802730_chfantasyathlete((Actor *)arg0, 0x3DA, 0x1F4, 0x13E3, 0x13E4, 0);
            }
            break;
        case 11:
            ((Actor *)arg0)->unk54 = func_80105B0C((Actor *)arg0, 0.0f);
            func_80802950_chfantasyathlete((Actor *)arg0);
            break;
        case 12:
            if (func_8080298C_chfantasyathlete((Actor *)arg0, data + 13, data + 16, data + 10, data[19])) {
                func_8080094C_chfantasyathlete((Actor *)arg0, 13);
                func_800DA544(0x341);
            }
            break;
        case 14:
            func_80802730_chfantasyathlete((Actor *)arg0, 0, 0, 0x13E7, 0, 1);
            break;
        case 15:
            func_80802730_chfantasyathlete((Actor *)arg0, 0, 0, 0x13E6, 0, 0);
            break;
        case 17:
            if (func_80802950_chfantasyathlete((Actor *)arg0)) {
                func_8080094C_chfantasyathlete((Actor *)arg0, 18);
            }
            break;
        case 18:
            if (!func_8010C9B0(((Actor *)arg0)->position, 500) || func_80016B30(0, 1)) {
                func_8080094C_chfantasyathlete((Actor *)arg0, 8);
            }
            break;
        case 19:
            if (func_80802950_chfantasyathlete((Actor *)arg0)) {
                func_8080094C_chfantasyathlete((Actor *)arg0, 20);
            }
            break;
        case 22:
            if (func_800F549C(func_800F54E4(), 3) > 0.0f) {
                func_80802730_chfantasyathlete((Actor *)arg0, 0x448, 500, 0x1437, 0x1437, 1);
            } else {
                func_80802730_chfantasyathlete((Actor *)arg0, 0x3DB, 500, 0x13E8, 0x13E9, 1);
            }
            break;
        case 25:
            ((Actor *)arg0)->unk54 = func_80105B0C((Actor *)arg0, 0.0f);
            func_80802950_chfantasyathlete((Actor *)arg0);
            break;
        case 26:
            if (func_8080298C_chfantasyathlete((Actor *)arg0, data + 23, data + 26, data + 20, data[29])) {
                func_8080094C_chfantasyathlete((Actor *)arg0, 27);
            }
            break;
        case 27:
            if (!func_800FCCD4(0x16) && !func_800FCCD4(0x17)) {
                _gcgoto_entrypoint_1(func_800EA05C(), 0x18);
            }
            break;
        case 28:
            func_80802730_chfantasyathlete((Actor *)arg0, 0, 0, 0x13EC, 0, 1);
            break;
        case 29:
            func_80802730_chfantasyathlete((Actor *)arg0, 0, 0, 0x13EB, 0, 0);
            break;
        case 31:
            if (func_80802950_chfantasyathlete((Actor *)arg0)) {
                func_8080094C_chfantasyathlete((Actor *)arg0, 32);
            }
            break;
        case 32:
            if (!func_8010C9B0(((Actor *)arg0)->position, 500) || func_80016B30(0, 1)) {
                func_8080094C_chfantasyathlete((Actor *)arg0, 22);
            }
            break;
        case 33:
            func_80801718_chfantasyathlete((Actor *)arg0);
            func_80105834((Actor *)arg0);
            if (func_80105A5C((Actor *)arg0)) {
                func_80802D38_chfantasyathlete((Actor *)arg0);
                func_80800000_chfantasyathlete((s32)arg0, 0);
                func_800FFA88(((Actor *)arg0)->unk0);
            }
            break;
        case 34:
            if (func_80101DDC((Actor *)arg0)) {
                func_8080094C_chfantasyathlete((Actor *)arg0, 35);
            }
            break;
    }
    func_8010C908((s32)arg0, (s32)((Actor *)arg0)->position);
    func_80801974_chfantasyathlete((Actor *)arg0);
}

void func_8080094C_chfantasyathlete(Actor *arg0, s32 arg1) {
    s32 _gcgoto_entrypoint_1(s32, s32);
    s32 _subaddieDll_entrypoint_4(void *, s32);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 func_800D1000(s32, s32, f32 *, s32, s32);
    void func_800DA3B8(s32, s32);
    s32 func_800DA524(s32);
    s32 func_800DA544(s32);
    s32 func_800EA05C(void);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EEB9C(f32 *, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    u32 func_800F54E4(void);
    void func_800F5A00(s32, f32 *);
    s32 func_800F7B9C(s32, s32);
    void func_800F82D4(s32, s32);
    void func_800FC6B0(u32);
    u32 func_800FDC28(u32);
    void *func_80100094(Actor *, u32);
    void func_8010573C(Actor *, f32);
    f32 func_8010CD28(Actor *);
    void func_808018B8_chfantasyathlete(Actor *, struct AthletePaths *, s32, u8);
    void func_80802C18_chfantasyathlete(Actor *, Unk80132ED0 *, s32, s32);
    void func_80802C94_chfantasyathlete(Actor *, s32, s32);
    void func_80802D38_chfantasyathlete(void *);
    extern f32 D_80803150_chfantasyathlete[3];
    struct AthletePaths *sp64;
    f32 sp60;
    f32 sp54[3];
    f32 sp48[3];
    f32 sp44;
    f32 sp38[3];
    f32 sp2C[3];

    sp64 = func_80100094(arg0, 0);
    if (arg0->unk70_10 == 22) {
        func_80800000_chfantasyathlete((s32)arg0, 1);
    }
    switch (arg1) {
    case 1:
        ((f32 *)arg0->actorData)[5] = 1.0f;
        func_808018B8_chfantasyathlete(arg0, sp64, 0, 10);
        ((f32 *)arg0->actorData)[6] = 0.0f;
        ((f32 *)arg0->actorData)[3] = 0.0f;
        break;
    case 2:
        func_800FC6B0(0x10);
        break;
    case 3:
        func_800DA544(0x3DC);
        arg0->unk58 = 0.0f;
        break;
    case 5:
        sp60 = arg0->rotation[1];
        func_80802C18_chfantasyathlete(arg0, arg0->unk0, 0x3B, 0x2810);
        _subaddieDll_entrypoint_4(arg0, 1);
        func_8010573C(arg0, 0.0f);
        arg0->unk54 = arg0->rotation[1];
        arg0->rotation[1] = sp60;
        break;
    case 6:
        ((f32 *)arg0->actorData)[6] = 750.0f;
        break;
    case 7:
        func_808018B8_chfantasyathlete(arg0, sp64, 1, 6);
        func_80802C18_chfantasyathlete(arg0, arg0->unk0, 0x3C, 0x2810);
        ((f32 *)arg0->actorData)[6] = 800.0f;
        ((f32 *)arg0->actorData)[3] = 800.0f;
        break;
    case 8:
        if (arg0->unk70_10 == 7) {
            func_808018B8_chfantasyathlete(arg0, sp64, 2, 5);
        } else {
            func_808018B8_chfantasyathlete(arg0, sp64, 2, 10);
        }
        _subaddieDll_entrypoint_4(arg0, 0);
        ((f32 *)arg0->actorData)[6] = 0.0f;
        ((f32 *)arg0->actorData)[3] = 0.0f;
        arg0->unk58 = 2.0f;
        func_80802D38_chfantasyathlete(arg0);
        break;
    case 9:
        arg0->unk79_4 = 2;
        _subaddiedialog_entrypoint_11(arg0->unk0, 0x1412, 0xF, arg0->position, 0x6B);
        break;
    case 10:
        func_80802D38_chfantasyathlete(arg0);
        func_800DA524(0x6D6);
        _gcgoto_entrypoint_1(func_800EA05C(), 0x17);
        break;
    case 11:
        func_800F5A00(func_800F54E4(), sp48);
        func_800EEB9C(sp54, 65.0f, 200.0f);
        func_800EF04C(sp54, sp48);
        func_808018B8_chfantasyathlete(arg0, sp64, 2, 6);
        _subaddiedialog_entrypoint_11(arg0->unk0, 0x13E5, 0xF, sp54, 0x6B);
        func_80802C94_chfantasyathlete(arg0, 2, 0);
        _subaddieDll_entrypoint_4(arg0, 1);
        func_800F7B9C(func_800F54E4(), 0x7F);
        break;
    case 12:
        arg0->unk64_20 = 0;
        arg0->unk64_19 = 0;
        ((f32 *)arg0->actorData)[5] = 1.0f;
        ((f32 *)arg0->actorData)[7] = 1.0f;
        ((f32 *)arg0->actorData)[6] = 1050.0f;
        func_800FDC28(0x13);
        func_80802D38_chfantasyathlete(arg0);
        break;
    case 13:
        func_800DA3B8(0x6D7, !arg0->unk64_19);
        func_800DA544(0x6D6);
        _gcgoto_entrypoint_1(func_800EA05C(), 0x17);
        break;
    case 14:
        func_808018B8_chfantasyathlete(arg0, sp64, 2, 10);
        arg0->rotation[1] = func_8010CD28(arg0);
        break;
    case 15:
        func_800DA544(0x3DD);
        func_808018B8_chfantasyathlete(arg0, sp64, 2, 10);
        arg0->rotation[1] = func_8010CD28(arg0);
        break;
    case 16:
        _subaddiedialog_entrypoint_11(arg0->unk0, 0x1413, 0xF, arg0->position, 0x6B);
        func_800F7B9C(func_800F54E4(), 0x80);
        break;
    case 17:
        arg0->unk54 = sp64->unk94[2];
        func_80802D38_chfantasyathlete(arg0);
        break;
    case 19:
        sp44 = arg0->rotation[1];
        func_808018B8_chfantasyathlete(arg0, sp64, 3, 5);
        arg0->unk54 = arg0->rotation[1];
        arg0->rotation[1] = sp44;
        func_80802C18_chfantasyathlete(arg0, arg0->unk0, 0x3D, 0x2811);
        break;
    case 20:
        _subaddieDll_entrypoint_4(arg0, 1);
        ((f32 *)arg0->actorData)[3] = 0.0f;
        ((f32 *)arg0->actorData)[6] = 750.0f;
        break;
    case 21:
        func_80802C18_chfantasyathlete(arg0, arg0->unk0, 0x3E, 0x2811);
        func_808018B8_chfantasyathlete(arg0, sp64, 4, 6);
        ((f32 *)arg0->actorData)[6] = 750.0f;
        ((f32 *)arg0->actorData)[3] = 750.0f;
        func_800F7B9C(func_800F54E4(), 0x80);
        break;
    case 22:
        _subaddieDll_entrypoint_4(arg0, 0);
        if (arg0->unk70_10 == 21) {
            func_808018B8_chfantasyathlete(arg0, sp64, 5, 5);
        } else {
            func_808018B8_chfantasyathlete(arg0, sp64, 5, 10);
        }
        ((f32 *)arg0->actorData)[6] = 0.0f;
        ((f32 *)arg0->actorData)[3] = 0.0f;
        func_80800000_chfantasyathlete((s32)arg0, 0);
        func_80802D38_chfantasyathlete(arg0);
        break;
    case 23:
        arg0->unk79_4 = 2;
        _subaddiedialog_entrypoint_11(arg0->unk0, 0x1414, 0xF, arg0->position, 0x6B);
        break;
    case 24:
        func_80802D38_chfantasyathlete(arg0);
        func_800DA524(0x6D6);
        _gcgoto_entrypoint_1(func_800EA05C(), 0x18);
        break;
    case 25:
        func_800F5A00(func_800F54E4(), sp2C);
        func_800EEB9C(sp38, 335.0f, 200.0f);
        func_800EF04C(sp38, sp2C);
        func_808018B8_chfantasyathlete(arg0, sp64, 5, 6);
        _subaddiedialog_entrypoint_11(arg0->unk0, 0x13EA, 0xF, sp38, 0x6B);
        break;
    case 26:
        func_80802D38_chfantasyathlete(arg0);
        arg0->unk64_20 = 0;
        arg0->unk64_19 = 0;
        ((f32 *)arg0->actorData)[5] = 1.0f;
        ((f32 *)arg0->actorData)[7] = 1.0f;
        _subaddieDll_entrypoint_4(arg0, 1);
        ((f32 *)arg0->actorData)[3] = 0.0f;
        ((f32 *)arg0->actorData)[6] = 1400.0f;
        func_800FDC28(0x13);
        break;
    case 27:
        func_800DA3B8(0x6D7, !arg0->unk64_19);
        func_800DA544(0x6D6);
        _gcgoto_entrypoint_1(func_800EA05C(), 0x18);
        break;
    case 28:
        func_808018B8_chfantasyathlete(arg0, sp64, 5, 10);
        arg0->rotation[1] = func_8010CD28(arg0);
        break;
    case 29:
        func_808018B8_chfantasyathlete(arg0, sp64, 5, 10);
        arg0->rotation[1] = func_8010CD28(arg0);
        break;
    case 30:
        func_800F82D4(func_800F54E4(), 0);
        _subaddiedialog_entrypoint_11(arg0->unk0, 0x1415, 0xF, arg0->position, 0x6B);
        break;
    case 31:
        arg0->unk54 = sp64->unk94[5];
        break;
    case 32:
        func_80802D38_chfantasyathlete(arg0);
        break;
    case 33:
        func_800D1000(0x48, 1, arg0->position, 0, 0);
        func_80802C18_chfantasyathlete(arg0, arg0->unk0, 0x40, 0x2830);
        func_808018B8_chfantasyathlete(arg0, sp64, 6, 5);
        _subaddieDll_entrypoint_4(arg0, 1);
        arg0->unk58 = 1.0f;
        ((f32 *)arg0->actorData)[3] = 0.0f;
        ((f32 *)arg0->actorData)[6] = 700.0f;
        break;
    case 34:
        func_800EE7F8(arg0->position, D_80803150_chfantasyathlete);
        break;
    }
    func_80102424(arg0, arg1);
}

s32 func_80801114_chfantasyathlete(s32 arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 arg4, f32 *arg5, f32 *arg6) {
    void func_800EF2A0(f32 vec[3]);
    void func_800EFB24(void *, void *, void *);
    int func_800F00A4(f32 point[3], f32 radius, f32 upper, f32 lower, f32 center[3]);
    f32 func_800F1CF0(f32 *, f32 *);
    f32 temp_f0;
    f32 sp28[3];
    s32 var_v0;
    s32 var_v1;

    if (func_800F00A4(arg2, arg4, 1000.0f, 0.0f, arg5) != 0) {
        func_800EFB24(sp28, arg5, arg3);
        func_800EF2A0(sp28);
        temp_f0 = func_800F1CF0(arg1, sp28);
        var_v0 = 0;
        if (temp_f0 >= 0.0f) {
            var_v0 = 1;
        }
        var_v1 = var_v0;
        if (var_v0 != 0) {
            var_v1 = 0;
            if (*arg6 <= 0.0f) {
                var_v1 = 1;
            }
        }
        *arg6 = temp_f0;
        return var_v1;
    }
    *arg6 = 1.0f;
    return 0;
}

s32 func_808011E4_chfantasyathlete(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _gcdialogcamera_entrypoint_0(s32, s32);
    void _gcdialogcamera_entrypoint_3(f32 *, f32);
    void func_800C01A8(s16, s32);
    void func_800DF744(s32, s32);
    s32 func_801015D0(Actor *);
    f32 func_80103EAC(Actor *);
    f32 func_80103EF4(Actor *);
    void func_8080094C_chfantasyathlete(Actor *, s32);
    void func_80802C94_chfantasyathlete(Actor *, s32, s32);
    void func_80802D38_chfantasyathlete(void *);
    f32 camera[4];
    s32 low;
    u32 high;
    struct {
        s16 id;
        s16 result;
    } *dialog;

    switch (arg1) {
    case 0x2E:
        arg0->unk79_4 = 3;
        dialog = (void *)&arg2;
        switch (dialog->id) {
        case 0x13E2:
            func_8080094C_chfantasyathlete(arg0, 5);
            break;
        case 0x1434:
        case 0x1435:
            if (dialog->result == 1) {
                func_8080094C_chfantasyathlete(arg0, 0xA);
            } else {
                func_8080094C_chfantasyathlete(arg0, 9);
            }
            break;
        case 0x1412:
            func_8080094C_chfantasyathlete(arg0, 8);
            break;
        case 0x1411:
            func_8080094C_chfantasyathlete(arg0, 8);
            break;
        case 0x13E5:
            func_8080094C_chfantasyathlete(arg0, 0xC);
            break;
        case 0x13E7:
            if (dialog->result == 1) {
                func_8080094C_chfantasyathlete(arg0, 0xB);
            } else {
                func_8080094C_chfantasyathlete(arg0, 0x10);
            }
            break;
        case 0x1413:
            func_8080094C_chfantasyathlete(arg0, 0x11);
            break;
        case 0x13E6:
            func_800C01A8(0x6B, 0x4000);
            func_8080094C_chfantasyathlete(arg0, 0x13);
            break;
        case 0x13E8:
        case 0x13E9:
        case 0x1437:
            if (dialog->result == 1) {
                func_8080094C_chfantasyathlete(arg0, 0x18);
            } else {
                func_8080094C_chfantasyathlete(arg0, 0x17);
            }
            break;
        case 0x1414:
            func_8080094C_chfantasyathlete(arg0, 0x16);
            break;
        case 0x13EA:
            func_8080094C_chfantasyathlete(arg0, 0x1A);
            break;
        case 0x13EC:
            if (dialog->result == 1) {
                func_8080094C_chfantasyathlete(arg0, 0x19);
            } else {
                func_8080094C_chfantasyathlete(arg0, 0x1E);
            }
            break;
        case 0x1415:
            func_8080094C_chfantasyathlete(arg0, 0x20);
            break;
        case 0x13EB:
            func_8080094C_chfantasyathlete(arg0, 0x21);
            break;
        case 0x13E0:
        case 0x13E1:
        case 0x13E3:
        case 0x13E4:
        case 0x1454:
        case 0x1455:
        case 0x1456:
            func_80802D38_chfantasyathlete(arg0);
            break;
        default:
            break;
        }
        return 1;
    case 0x52:
        camera[0] = func_80103EF4(arg0);
        camera[1] = func_80103EAC(arg0);
        camera[2] = func_80103EAC(arg0);
        camera[3] = camera[0] * 0.25f;
        _gcdialogcamera_entrypoint_3(camera, arg0->scale);
        return 1;
    case 0x57:
        low = arg2 & 0xFFFF;
        high = (arg2 & 0xFFFF0000) >> 16;
        if (_gcdialogcamera_entrypoint_0(low, high)) {
            func_80802C94_chfantasyathlete(arg0, low, high);
            return 2;
        }
        return 1;
    case 0x1F:
        func_801015D0(arg0);
        switch (D_80803034_chfantasyathlete[arg0->unk70_10][0]) {
        case 0x3F9:
        case 0x3FA:
        case 0x3FD:
        case 0x3FE:
            func_800DF744(3, 0);
            func_800DF744(4, 1);
            break;
        case 0x3FB:
        case 0x3FC:
        case 0x3FF:
        case 0x400:
            func_800DF744(3, 1);
            func_800DF744(4, 2);
            break;
        }
        return 1;
    }
    return 0;
}

/* extern */

void func_808015D8_chfantasyathlete(f32 *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4) {
    s32 func_800EE780(s32, s32, s32);
    f32 func_800EEAD4(s32, s32);
    void func_800EF2A0(f32 vec[3]);
    s32 func_800EF334(s32, s32);
    void func_800EFB24(void *, void *, void *);
    func_800EFB24(arg3, arg0, arg1);
    func_800EF2A0(arg3);
    func_800EE780(arg2, arg1, arg0);
    func_800EF334(arg2, 0x3F000000);
    *arg4 = func_800EEAD4(arg1, arg0) * 0.5f;
}

void func_80801654_chfantasyathlete(s32 arg0, struct AthletePaths *data) {
    s32 _gccubesearch_entrypoint_9(s32, Prop **, s32);
    s32 _gspropctrl_entrypoint_8(Prop *);
    void _gspropctrl_entrypoint_11(Prop *, f32[3]);
    s32 _gspropctrl_entrypoint_12(Prop *);
    s32 _glsplinefind_entrypoint_3(f32 *);
    Prop *props[10];
    s32 i;
    s32 index;
    f32 position[3];
    s32 count;

    count = _gccubesearch_entrypoint_9(0x479, props, 10);
    for (i = 0; i < count; i++) {
            index = _gspropctrl_entrypoint_8(props[i]) - 50;
            _gspropctrl_entrypoint_11(props[i], position);
            data->unk94[index] = (f32)_gspropctrl_entrypoint_12(props[i]);
            data->unk78[index] = _glsplinefind_entrypoint_3(position);
    }
}

void func_80801718_chfantasyathlete(Actor *arg0) {
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F15F8(f32, f32, f32);
    f32 func_800F3780(f32, u8 *, s16);
    void func_80105A9C(Actor *, f32);
    struct AthleteCurve6 { f32 points[6][2]; };
    struct AthleteCurve5 { f32 points[5][2]; };
    extern struct AthleteCurve6 D_8080315C_chfantasyathlete;
    extern struct AthleteCurve5 D_8080318C_chfantasyathlete;
    struct AthleteCurve6 sp60;
    struct AthleteCurve5 sp38;

    ((f32 *)arg0->actorData)[3] = func_800F15F8(((f32 *)arg0->actorData)[3], ((f32 *)arg0->actorData)[6], 50.0f);
    switch (D_80803034_chfantasyathlete[arg0->unk70_10][0]) {
    case 0x3FA:
        sp60 = D_8080315C_chfantasyathlete;
        func_80101CDC(arg0, func_800F10B4(((f32 *)arg0->actorData)[3], 250.0f, 1000.0f, 1.25f, 0.5f));
        func_80105A9C(arg0, ((f32 *)arg0->actorData)[3] * func_800F3780(func_80101F24(arg0), (u8 *)&sp60, 6));
        break;
    case 0x3FC:
        sp38 = D_8080318C_chfantasyathlete;
        func_80101CDC(arg0, func_800F10B4(((f32 *)arg0->actorData)[3], 250.0f, 800.0f, 1.5f, 0.75f));
        func_80105A9C(arg0, ((f32 *)arg0->actorData)[3] * func_800F3780(func_80101F24(arg0), (u8 *)&sp38, 5));
        break;
    }
}

void func_808018B8_chfantasyathlete(Actor *arg0, struct AthletePaths *arg1, s32 arg2, u8 arg3) {
    void func_800C7A68(struct Unk800C7A68 *, f32, f32 *);
    void *func_800D7520(s32);
    void func_801058C4(Actor *, s32, f32, u32);
    if (arg3 & 2) {
        func_800C7A68(func_800D7520(arg1->unk78[arg2]), 0.0f, arg0->position);
    }
    func_801058C4(arg0, arg1->unk78[arg2], 0.0f, (arg3 & 2) ? 0 : 1);
    if (arg3 & 8) {
        arg0->rotation[1] = arg1->unk94[arg2];
    }
}

void func_80801974_chfantasyathlete(Actor *arg0) {
    switch (D_80803034_chfantasyathlete[arg0->unk70_10][0]) {
    case 0x3F9:
        if ((func_80101E14(arg0, 0.06f) != 0) || (func_80101E14(arg0, 0.26f) != 0) || (func_80101E14(arg0, 0.46f) != 0)) {
            func_800C4140(((u32) (u16) (func_800DC178(1.1f, 1.2f) * 1023.0f) << 0x15) + 0x1B5E23, arg0->position, 0x04B000FA);
        }
        if ((func_80101E14(arg0, 0.17f) != 0) || (func_80101E14(arg0, 0.37f) != 0) || (func_80101E14(arg0, 0.57f) != 0)) {
            func_800C4140(((u32) (u16) (func_800DC178(1.1f, 1.2f) * 1023.0f) << 0x15) + 0x1B5E24, arg0->position, 0x04B000FA);
        }
        if (func_80101E14(arg0, 0.7f) != 0) {
            func_800C4140(((u32) (u16) (func_800DC178(0.95f, 1.05f) * 1023.0f) << 0x15) + 0x1B5E26, arg0->position, 0x04B000FA);
            return;
        }
    default:
        return;
    case 0x3FA:
        if ((func_80101E14(arg0, 0.45f) != 0) || (func_80101E14(arg0, 0.95f) != 0)) {
            func_800C4140(((u32) (u16) (func_800DC178(0.9f, 1.1f) * 1023.0f) << 0x15) + 0x1F4404, arg0->position, 0x04B000FA);
        }
        if (func_80101E14(arg0, 0.4f) != 0) {
            func_800C4140(((u32) (u16) (func_800DC178(1.25f, 1.35f) * 1023.0f) << 0x15) + 0xBBD8A, arg0->position, 0x04B000FA);
        }
        if (func_80101E14(arg0, 0.9f) != 0) {
            func_800C4140(((u32) (u16) (func_800DC178(1.25f, 1.35f) * 1023.0f) << 0x15) + 0x1F58B, arg0->position, 0x04B000FA);
            return;
        }
        break;
    case 0x3FD:
        if (func_80101E14(arg0, 0.05f) != 0) {
            func_800C4140(((u32) (u16) (func_800DC178(0.95f, 1.05f) * 1023.0f) << 0x15) + 0x1B5E26, arg0->position, 0x04B000FA);
        }
        if (func_80101E14(arg0, 0.42f) != 0) {
            func_800C4140(((u32) (u16) (func_800DC178(0.75f, 0.85f) * 1023.0f) << 0x15) + 0x1B5E1F, arg0->position, 0x04B000FA);
        }
        if (func_80101E14(arg0, 0.66f) != 0) {
            func_800C4140(((u32) (u16) (func_800DC178(0.75f, 0.85f) * 1023.0f) << 0x15) + 0x1B5E1F, arg0->position, 0x04B000FA);
            return;
        }
        break;
    case 0x3FE:
        if (func_80101E14(arg0, 0.32f) != 0) {
            func_800C4140(((u32) (u16) (func_800DC178(0.55f, 0.65f) * 1023.0f) << 0x15) + 0x1B5E1E, arg0->position, 0x04B000FA);
            return;
        }
        if (func_80101E14(arg0, 0.1f) != 0) {
            func_800C4140(((u32) (u16) (func_800DC178(0.95f, 1.05f) * 1023.0f) << 0x15) + 0x1B5E25, arg0->position, 0x04B000FA);
            return;
        }
        break;
    case 0x3FC:
        if (func_80101E14(arg0, 0.1f) != 0) {
            func_800C4140(((u32) (u16) (func_800DC178(1.1f, 1.2f) * 1023.0f) << 0x15) + 0x138E23, arg0->position, 0x04B000FA);
        }
        if (func_80101E14(arg0, 0.17f) != 0) {
            func_800C4140(0x7FF38CD5, arg0->position, 0x04B000FA);
        }
        if (func_80101E14(arg0, 0.7f) != 0) {
            func_800C4140(((u32) (u16) (func_800DC178(1.25f, 1.35f) * 1023.0f) << 0x15) + 0x9C58B, arg0->position, 0x04B000FA);
            return;
        }
        break;
    case 0x3FF:
        if ((func_80101E14(arg0, 0.1f) != 0) || (func_80101E14(arg0, 0.42f) != 0) || (func_80101E14(arg0, 0.6f) != 0)) {
            func_800C4140(0x665B5E1F, arg0->position, 0x04B000FA);
            return;
        }
        break;
    case 0x400:
        if (func_80101E14(arg0, 0.34f) != 0) {
            func_800C4140(((u32) (u16) (func_800DC178(0.55f, 0.65f) * 1023.0f) << 0x15) + 0x1B5E1E, arg0->position, 0x04B000FA);
        }
        break;
    }
}


s32 func_80802730_chfantasyathlete(Actor *arg0, s32 arg1, s32 arg2, s16 arg3, s16 arg4, s32 arg5) {
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    s32 func_80016B30(s32, s32);
    s32 func_800DA298(s32);
    s32 func_800DA544(s32);
    u32 func_800F54E4(void);
    s32 func_800F6C5C(s32);
    s32 func_8010C9B0(f32 *, s32);
    f32 func_8010CD28(Actor *);
    s32 func_80802950_chfantasyathlete(Actor *);
    void func_80802D74_chfantasyathlete(u8 *);
    s32 flags;
    s32 ready;
    s32 pad[2];
    f32 *volatile position;

    flags = (arg5 ? 0x40 : 1) | 0xE;
    switch (arg0->unk79_4) {
    case 0:
        ready = arg2 ? func_8010C9B0(arg0->position, arg2) : 1;
        if (ready && func_800F6C5C(func_800F54E4())) {
            arg0->unk54 = func_8010CD28(arg0);
            arg0->unk50 = arg0->rotation[1];
            if (arg1) {
                if (func_800DA298(arg1)) {
                    if (func_80016B30(0, 1)) {
                        arg0->unk79_4 = 1;
                        _subaddiedialog_entrypoint_11(arg0->unk0, arg4, flags, arg0->position, 0x6B);
                        func_80802D74_chfantasyathlete((u8 *)arg0);
                        return 1;
                    }
                } else {
                    arg0->unk79_4 = 1;
                    position = arg0->position;
                    func_800DA544(arg1);
                    _subaddiedialog_entrypoint_11(arg0->unk0, arg3, flags, position, 0x6B);
                    func_80802D74_chfantasyathlete((u8 *)arg0);
                    return 1;
                }
            } else {
                arg0->unk79_4 = 1;
                _subaddiedialog_entrypoint_11(arg0->unk0, arg3, flags, arg0->position, 0x6B);
                func_80802D74_chfantasyathlete((u8 *)arg0);
                return 1;
            }
        }
        return 0;
    case 1:
        if (func_80802950_chfantasyathlete(arg0)) {
            arg0->unk79_4 = 2;
        }
        return 1;
    case 2:
        return 1;
    case 3:
        arg0->unk54 = arg0->unk50;
        if (func_80802950_chfantasyathlete(arg0)) {
            arg0->unk79_4 = 0;
            return 0;
        }
        return 1;
    }
    return 0;
}

s32 func_80802950_chfantasyathlete(Actor *arg0) {
    void func_80102BAC(Actor*, f32, f32, f32);
    void func_80102CCC(void *arg0);
    func_80102BAC(arg0, 0.2f, 0.1f, 10.0f);
    func_80102CCC(arg0);
}

s32 func_8080298C_chfantasyathlete(Actor *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 arg4) {
    u32 func_800F54E4(void);
    void func_800F5A00(s32, f32 *);
    s32 func_800F6C5C(s32);
    void func_800F7ECC(s32, s32, f32);
    void func_800FC6B0(u32);
    s32 func_800FCCD4(s32);
    u32 func_800FDC28(u32);
    void func_80105834(Actor *);
    f32 position[3];

    func_80801718_chfantasyathlete(arg0);
    func_80105834(arg0);
    func_800F5A00(func_800F54E4(), position);
    if (!arg0->unk64_19) {
        if (position[1] < arg2[1] - 150.0f && !func_800F6C5C(func_800F54E4())) {
            func_800F7ECC(func_800F54E4(), 3, 0.0f);
            func_800FDC28(0);
            if (!arg0->unk64_20) {
                func_800FC6B0(0x17);
                arg0->unk64_19 = 1;
            }
            return 1;
        }
        if (func_80801114_chfantasyathlete((s32)arg0, arg1, arg2, arg3, arg4, position, (f32 *)&arg0->actorData[5])) {
            func_800FDC28(0);
            func_800FC6B0(0x16);
            arg0->unk64_20 = 1;
        }
    }
    if (!arg0->unk64_20) {
        if (position[1] < arg2[1] - 150.0f && !func_800F6C5C(func_800F54E4())) {
            func_800F7ECC(func_800F54E4(), 3, 0.0f);
            func_800FDC28(0);
            func_800FC6B0(0x17);
            arg0->unk64_19 = 1;
            return 1;
        }
        if (func_80801114_chfantasyathlete((s32)arg0, arg1, arg2, arg3, arg4, arg0->position, (f32 *)&arg0->actorData[7])) {
            func_800FDC28(0);
            func_800FC6B0(0x17);
            arg0->unk64_19 = 1;
        }
    }
    if (arg0->unk64_20 || arg0->unk64_19) {
        func_800F7ECC(func_800F54E4(), 3, 0.0f);
        *(f32 *)&arg0->actorData[3] *= 0.9f;
        if (!func_800FCCD4(0x16) && !func_800FCCD4(0x17)) {
            return 1;
        }
        return 0;
    }
    return 0;
}

void func_80802C18_chfantasyathlete(Actor *arg0, Unk80132ED0 *arg1, s32 arg2, s32 arg3) {
    void _capod_entrypoint_2(Unk80132ED0 *, u32, s32);
    void _capod_entrypoint_6(Unk80132ED0 *, s32, s32);

    switch (arg0->actorData[0]) {
        case 0:
            _capod_entrypoint_2(arg0->unk0, 0x2B, 0x10);
        case 1:
            arg0->actorData[0] = 2;
        case 2:
            _capod_entrypoint_6(arg1, arg2, arg3);
            break;
    }
}

void func_80802C94_chfantasyathlete(Actor *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_2(Unk80132ED0 *, u32, s32);
    void _capod_entrypoint_7(s32, s32);
    s32 _capod_entrypoint_8(s32);
    void _gcdialogcamera_entrypoint_6(Unk80132ED0 *);
    void _gcdialogcamera_entrypoint_8(void);

    switch (arg0->actorData[0]) {
        case 0:
            _capod_entrypoint_2(arg0->unk0, 0x2B, 0);
        case 2:
            _capod_entrypoint_8(1);
            arg0->actorData[0] = 1;
            arg1 = 2;
            arg2 = 1;
            _gcdialogcamera_entrypoint_6(arg0->unk0);
            _gcdialogcamera_entrypoint_8();
        case 1:
            _capod_entrypoint_7(arg1, arg2);
            break;
    }
}

/* extern */

void func_80802D38_chfantasyathlete(void *arg0) {
    s32 _capod_entrypoint_3(s32, void *);
    if ((*(s32 *)((s8 *)(arg0) + (0x18))) != 0) {
        _capod_entrypoint_3(0, arg0);
        (*(s32 *)((s8 *)(arg0) + (0x18))) = 0;
    }
}

/* extern */

void func_80802D74_chfantasyathlete(u8 *arg0) {
    void func_80802C94_chfantasyathlete(Actor *, s32, s32);
    if ((*(s32 *)((s8 *)(arg0) + (0x18))) != 1) {
        func_80802C94_chfantasyathlete(arg0, 2, 0);
    }
}

/* extern */

void func_80802DA8_chfantasyathlete(s32 arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 func_80800314_chfantasyathlete(s32);
    if (_glcutDll_entrypoint_20() != 0) {
        func_80800314_chfantasyathlete(arg0);
    }
}

OSThread *chfantasyathlete_entrypoint_0(void)
{


    return (OSThread *) D_808031B4_chfantasyathlete;
}
