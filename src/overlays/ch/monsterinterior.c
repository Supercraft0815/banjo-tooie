#include "common.h"

void func_80101870(Actor *, void *);
void func_801018A4(Actor *, BtIntPtr);
void func_80105834(Actor *);
void *func_80107C2C(s32 *, s32, void *, s32, void *);
OSThread *func_80108ED0(void);
void func_8080003C_chmonsterinterior(Actor *arg0);
void func_808000BC_chmonsterinterior(Actor *arg0);
s32 func_808002D4_chmonsterinterior(Actor *arg0, s32 arg1, s32 arg2);
void func_8080060C_chmonsterinterior(Actor *arg0);
void func_80800DA4_chmonsterinterior(Actor *arg0);
void func_80800E0C_chmonsterinterior(Actor *);
void func_8080101C_chmonsterinterior(Actor *arg0, s32 arg1);
s32 func_80801050_chmonsterinterior(Actor *arg0, s32 arg1, s32 arg2);
void func_808013D0_chmonsterinterior(Actor *arg0);
void func_808014E8_chmonsterinterior();
void func_808017E8_chmonsterinterior(s32 arg0);
s32 func_808017F0_chmonsterinterior(Actor *arg0, s32 arg1, Unk80132ED0 *volatile arg2);

s16 D_80801E50_chmonsterinterior[] = {
    0x0003, 0x0002, 0x0001, 0x0000,
};

u8 D_80801E58_chmonsterinterior[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x3F, 0x80, 0x00, 0x00, 0x03, 0x61, 0x00, 0x4A,
    0x40, 0x80, 0x00, 0x00, 0x03, 0x62, 0x00, 0x09,
    0x3F, 0x80, 0x00, 0x00, 0x03, 0x61, 0x00, 0x92,
    0x3F, 0x80, 0x00, 0x00, 0x03, 0x61, 0x00, 0x09,
};

BtFnWord D_80801E80_chmonsterinterior[] = {
    0x01580451, 0x00000001,
    0x00000000, (BtFnWord)func_808000BC_chmonsterinterior,
    (BtFnWord)func_80105834, (BtFnWord)func_80101870,
    0x00000000, 0x00000000,
    0x00000000, 0x00000001,
    (BtFnWord)func_8080060C_chmonsterinterior, 0x00000000,
    0x05440000, (BtFnWord)func_8080003C_chmonsterinterior,
    (BtFnWord)func_80107C2C, 0x80000602,
    (BtFnWord)func_808002D4_chmonsterinterior, 0x00000000,
};

BtFnWord D_80801EC8_chmonsterinterior[] = {
    0x01580455, 0xFFFF0001,
    0x00000000, (BtFnWord)func_80800E0C_chmonsterinterior,
    (BtFnWord)func_80105834, (BtFnWord)func_8080101C_chmonsterinterior,
    0x00000000, 0x00000000,
    0x00000000, 0x00400401,
    (BtFnWord)func_8080060C_chmonsterinterior, 0x00000000,
    0x05440000, (BtFnWord)func_80800DA4_chmonsterinterior,
    (BtFnWord)func_80107C2C, 0x80000402,
    (BtFnWord)func_80801050_chmonsterinterior, 0x00000000,
};

BtFnWord D_80801F10_chmonsterinterior[] = {
    0x02A60452, 0xFFFF0001,
    0x00000000, (BtFnWord)func_808014E8_chmonsterinterior,
    (BtFnWord)func_80105834, (BtFnWord)func_801018A4,
    0x00000000, 0x00000000,
    0x00000000, 0x00000124,
    (BtFnWord)func_808017E8_chmonsterinterior, (BtFnWord)func_80108ED0,
    0x002C0000, (BtFnWord)func_808013D0_chmonsterinterior,
    (BtFnWord)func_80107C2C, 0x80241001,
    (BtFnWord)func_808017F0_chmonsterinterior, 0x00000000,
};

BtFnWord D_80801F58_chmonsterinterior[] = {
    0x02A60453, 0xFFFF0001,
    0x00000000, (BtFnWord)func_808014E8_chmonsterinterior,
    (BtFnWord)func_80105834, (BtFnWord)func_801018A4,
    0x00000000, 0x00000000,
    0x00000000, 0x00000124,
    (BtFnWord)func_808017E8_chmonsterinterior, (BtFnWord)func_80108ED0,
    0x002C0000, (BtFnWord)func_808013D0_chmonsterinterior,
    (BtFnWord)func_80107C2C, 0x80241001,
    (BtFnWord)func_808017F0_chmonsterinterior, 0x00000000,
};

BtFnWord D_80801FA0_chmonsterinterior[] = {
    0x02A60454, 0xFFFF0001,
    0x00000000, (BtFnWord)func_808014E8_chmonsterinterior,
    (BtFnWord)func_80105834, (BtFnWord)func_801018A4,
    0x00000000, 0x00000000,
    0x00000000, 0x00000124,
    (BtFnWord)func_808017E8_chmonsterinterior, (BtFnWord)func_80108ED0,
    0x002C0000, (BtFnWord)func_808013D0_chmonsterinterior,
    (BtFnWord)func_80107C2C, 0x80241001,
    (BtFnWord)func_808017F0_chmonsterinterior, 0x00000000,
};

u16 D_80801FE8_chmonsterinterior[] = {
    0x0806, 0x0804, 0x0805, 0x0000,
};

u16 D_80801FF0_chmonsterinterior[] = {
    0x099F, 0x099E, 0x099D, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x00FF, 0x0000, 0x0000,
    0x0000, 0x00FF, 0x0000, 0x0000,
    0x0000, 0x00FF, 0x0000, 0x0000,
    0x0000, 0x0000,
};

s32 D_8080201C_chmonsterinterior[] = {
    0x001304B2, 0x000D00A6,
    0x00C00001, 0x03200898,
    0x00000000,
};

u32 D_80802030_chmonsterinterior[] = {
    0x0013060F, 0x000D00F3,
    0x010C0001, 0x03200898,
    0x00000000,
};

s32 D_80802044_chmonsterinterior[] = {
    0x00161200, 0x00150000,
    0x00CC002B, 0x00B300CC,
    0x002200CC, 0x01330080,
    0x0099002D, 0x02580320,
    0x0027FF38, 0xFF3800C8,
    0x00C8000E, 0x00190032,
    0x001BFC18, 0xFCE00000,
};

s32 D_8080207C_chmonsterinterior[] = {
    0x0013041F, 0x0018000D,
    0x00F3010C, 0x00000000,
};

s16 D_8080208C_chmonsterinterior[] = {
    0x0922, 0x0921, 0x0920, 0x0000,
    0x0000, 0x0000, 0x0000, 0x0000,
    0x0000, 0x0000,
};

OSThread *chmonsterinterior_entrypoint_0(void)
{

    return (OSThread *) D_80801E80_chmonsterinterior;
}

OSThread *chmonsterinterior_entrypoint_1(void)
{

    return (OSThread *) D_80801EC8_chmonsterinterior;
}

OSThread *chmonsterinterior_entrypoint_2(void)
{

    return (OSThread *) D_80801F10_chmonsterinterior;
}

OSThread *chmonsterinterior_entrypoint_3(void)
{

    return (OSThread *) D_80801F58_chmonsterinterior;
}

OSThread *chmonsterinterior_entrypoint_4(void)
{

    return (OSThread *) D_80801FA0_chmonsterinterior;
}

void func_8080003C_chmonsterinterior(Actor *arg0) {
    void _susubgame_entrypoint_0(BtIntPtr arg0, u8 *arg1, s32 arg2);
    void _susubgame_entrypoint_11(s32 arg0);
    BtUIntPtr func_800F54E4(void);
    s32 func_800F6438(BtUIntPtr);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    u32 *data;

    data = func_80100094(arg0, 0);
    if (func_800F6438(func_800F54E4()) == 0) {
        func_800FFAB0(arg0);
        return;
    }
    *data = 0;
    _susubgame_entrypoint_0(arg0, data + 4, 0);
    _susubgame_entrypoint_11(0);
    arg0->unk6C_0 = 0;
}

void func_808000BC_chmonsterinterior(Actor *arg0) {
    BT_IDO_ONLY(s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);) BT_NATIVE_ONLY(s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s16);)
    void _susubgame_entrypoint_5(Actor *, void *, s32, s32, s32);
    s32 _susubgame_entrypoint_9(void);
    s32 func_800CEAD0(s32);
    s32 func_800D0B68(u32, u32);
    s32 func_800D2498(u32, s32, u32);
    int func_800D9154(f32 *, f32);
    f32 func_800DC0C0(void);
    f32 func_800DC178(f32, f32);
    BtUIntPtr func_800F54E4(void);
    void func_800F7C0C(BtIntPtr, s32, f32);
    void func_800F8300();
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    void func_80108B04(Actor *, u32);
    s32 func_80800C38_chmonsterinterior(Actor *, s32 *);
    s32 *data;
    BtIntPtr player;
    u32 animation;
    f32 random;

    data = func_80100094(arg0, 0);
    switch (arg0->unk70_10) {
    case 1:
        break;
    case 3:
        player = func_800F54E4();
        func_800D2498(0xF7, data[0], 0);
        if (func_800CEAD0(arg0->unk6C_0)) {
            data[2] = func_80800C38_chmonsterinterior(arg0, &data[3]);
            func_800F8300(player, 2, 0);
            func_800F7C0C(player, 0x5F, 0.0f);
            func_80101FDC(arg0, 4);
        } else if (func_800D9154(&arg0->unk58, func_800DC178(0.5f, 1.0f))) {
            random = func_800DC0C0();
            if (random < 0.166666f) {
                animation = 0;
            } else if (random < 0.5f) {
                animation = 1;
            } else {
                animation = 2;
            }
            func_80108B04(arg0, animation);
        }
        break;
    case 4:
        if (_susubgame_entrypoint_9()) {
            _susubgame_entrypoint_5(arg0, &data[4], 5, 1, 0);
            _subaddiedialog_entrypoint_11(arg0->unk0, data[2], data[3], NULL, 0xB3);
            func_80101FDC(arg0, 5);
        }
        break;
    case 7:
        if (func_800D0B68(0x2E, 1)) {
            func_800F8300(func_800F54E4(), 2, 0);
            data[2] = 0xCEB;
            data[3] = 0x46;
            func_80101FDC(arg0, 4);
        }
        break;
    }
}

s32 func_808002D4_chmonsterinterior(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _chintrotext_entrypoint_2(s32);
    s32 _glcutDll_entrypoint_20(void);
    BT_IDO_ONLY(s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);) BT_NATIVE_ONLY(s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s16);)
    s32 _susubgame_entrypoint_3(void *, BtIntPtr, s32, u32);
    s32 _susubgame_entrypoint_4(void *, BtIntPtr);
    void _susubgame_entrypoint_5(Actor *, void *, s32, s32, s32);
    void _susubgame_entrypoint_6(Actor *, void *, s32, s32, BtIntPtr);
    s32 func_800D395C(void);
    s32 func_800DA9E4(s32, s32);
    void func_800F49D4(BtIntPtr, void *, BtIntPtr);
    BtUIntPtr func_800F54E4(void);
    void func_800F7B9C(BtIntPtr, u32);
    int func_800F7C58(BtIntPtr arg0, s32 arg1, s32 arg2);
    void func_800F82D4(BtIntPtr, s32);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    void func_8080068C_chmonsterinterior(Actor *);
    void func_8080078C_chmonsterinterior(Actor *arg0, s32 arg1, s32 arg2);
    s32 func_808009C0_chmonsterinterior(Actor *arg0, s32 arg1, s32 arg2);
    void func_80800A44_chmonsterinterior(Actor *arg0, s32 arg1);
    void _bsfirstp_entrypoint_18(s32 arg0, s32 arg1);
    BtIntPtr data;
    BtIntPtr player;
    s32 text;

    data = (BtIntPtr)func_80100094(arg0, 0);
    switch (arg1) {
        default:
            return 0;
        case 0x2E:
            func_8080078C_chmonsterinterior(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
            return 1;
        case 0x30:
            return func_808009C0_chmonsterinterior(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
        case 0x3D:
            func_80800A44_chmonsterinterior(arg0, arg2);
            return 1;
        case 0xB:
            if (arg2 == 6) {
                _susubgame_entrypoint_4(arg0, data + 0x10);
                func_800F7B9C(func_800F54E4(), 0x62);
                func_800F82D4(func_800F54E4(), 0);
                func_80101FDC(arg0, 7);
                return 4;
            }
            return 3;
        case 0x49:
            player = func_800F54E4();
            if (((u32)*(u16 *)((u8 *)arg0 + 0x72) >> 10) != 1) {
                return 0;
            }
            if (_glcutDll_entrypoint_20()) {
                func_800FFAB0(arg0);
                return 0;
            }
            if (!func_800DA9E4(0x370, 1)) {
                func_800F49D4(player, _bsfirstp_entrypoint_18, 0);
                _susubgame_entrypoint_6(arg0, data + 0x10, 0, 0x20, 0);
                _chintrotext_entrypoint_2(1);
            } else {
                func_800F49D4(player, NULL, 0);
                func_800F7B9C(player, 0x8F);
                func_800F7B9C(player, 0x63);
                func_800F7C58(player, 0x61, 0);
                _susubgame_entrypoint_5(arg0, data + 0x10, 5, 1, 0);
                _subaddiedialog_entrypoint_11(*(Unk80132ED0 **)arg0, 0xCEC, 0x46, NULL, 0xB3);
                func_800F82D4(func_800F54E4(), 2);
            }
            func_80101FDC(arg0, 2);
            return 1;
        case 0x77:
            text = func_800D395C() ? 0x181A : 0x17F2;
            _subaddiedialog_entrypoint_11(*(Unk80132ED0 **)arg0, text, 0x46, NULL, 0xB3);
            func_800F82D4(func_800F54E4(), 2);
            return 1;
        case 0x57:
            return _susubgame_entrypoint_3(arg0, data + 0x10, arg2 & 0xFFFF, (u32)(arg2 & 0xFFFF0000) >> 16);
        case 0x59:
            text = arg2;
            if (text != 0xCEB) {
                if (text == 0xCEC) {
                    func_8080068C_chmonsterinterior(arg0);
                    _susubgame_entrypoint_4(arg0, data + 0x10);
                }
            } else {
                _susubgame_entrypoint_4(arg0, data + 0x10);
            }
            return 1;
    }
}

void func_8080060C_chmonsterinterior(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 func_800CEAA8(s32);
    void func_800CE88C(s32, s32);
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(u8) _susubgame_entrypoint_2(void *, BtIntPtr);
    s32 _susubgame_entrypoint_4(void *, BtIntPtr);
    s32 data[2];

    data[1] = func_80100094(arg0, 0);
    if (func_800CEAA8(arg0->unk6C_0) != 0) {
        func_800CE88C(arg0->unk6C_0, 0);
    }
    data[0] = data[1] + 0x10;
    if (_susubgame_entrypoint_2(arg0, data[0]) != 0) {
        _susubgame_entrypoint_4(arg0, data[0]);
    }
}

/* extern */

void func_8080068C_chmonsterinterior(Actor *arg0) {
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(u8) _gcstatusDll_entrypoint_11();
    s32 _subaddiemulti_entrypoint_2();
    void func_800CE88C(s32, s32);
    void func_800CE8D8(s32, f32, s32);
    s32 func_800D3948(void);
    void func_800F7B9C(BtIntPtr, u32);
    void func_800F7C0C(BtIntPtr, s32, f32);
    u32 func_800FDC28(u32);
    void func_80101FDC(Actor *, u32);
    s32 var_s0;
    s32 duration = 60;

    _subaddiemulti_entrypoint_2();
    func_80101FDC(arg0, 3);
    var_s0 = 0;
    if (_gcstatusDll_entrypoint_11() > 0) {
        do {
            if (func_800D3948() == 0) {
                func_800F7B9C(var_s0, 0x73);
                func_800F7C0C(var_s0, 0x5F, -1.0f);
            } else {
                func_800F7C0C(var_s0, 0x5F, -1.0f);
            }
            var_s0 += 1;
        } while (var_s0 < _gcstatusDll_entrypoint_11());
    }
    func_800CE8D8(arg0->unk6C_0, duration, 60);
    func_800CE88C(arg0->unk6C_0, 1);
    arg0->unk58 = 0.01f;
    func_800FDC28(0xC);
}

void func_8080078C_chmonsterinterior(Actor *arg0, s32 arg1, s32 arg2) {
    void _gcfrontend_entrypoint_10(void);
    void _gcfrontend_entrypoint_11(void);
    void _gcfrontend_entrypoint_9(s32 arg0);
    void _gcgoto_entrypoint_1(u32 a0, u32 a1);
    BT_IDO_ONLY(s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);) BT_NATIVE_ONLY(s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s16);)
    void _susubgame_entrypoint_5(Actor *, void *, s32, s32, s32);
    void _susubgame_entrypoint_6(Actor *, void *, s32, s32, BtIntPtr);
    void func_800D1000(u32 arg0, u32 arg1, f32* arg2, u32 arg3, Unk80132ED0* arg4);
    s32 func_800D395C(void);
    BtUIntPtr func_800F54E4(void);
    void func_800F82D4(BtIntPtr, s32);
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    void func_80108B04(Actor *, u32);
    void func_80108BD4(Actor *, s32);
    s32 *data;

    data = func_80100094(arg0, 0);
    switch (arg1) {
        case 0x17F2:
        case 0x181A:
            if (arg2 > 0) {
                _susubgame_entrypoint_6(arg0, &data[4], 3, 0x20, 0);
                _subaddiedialog_entrypoint_11(arg0->unk0, 0x17F3, 0x44, NULL, 0xB3);
                func_80108B04(arg0, 0);
            } else {
                _subaddiedialog_entrypoint_11(arg0->unk0, 0xCEC, 7, NULL, 0xB3);
            }
            _gcfrontend_entrypoint_9(0x6B);
            return;
        case 0x17F3:
            _susubgame_entrypoint_5(arg0, &data[4], 5, 1, 0);
            _subaddiedialog_entrypoint_11(arg0->unk0, 0xCEC, 7, NULL, 0xB3);
            return;
        case 0xCEB:
            func_800F82D4(func_800F54E4(), 0);
            func_80101FDC(arg0, 6);
            if (func_800D395C() != 0) {
                if (arg2 > 0) {
                    _gcfrontend_entrypoint_11();
                    return;
                }
                _gcfrontend_entrypoint_10();
                return;
            }
            if (arg2 > 0) {
                _gcgoto_entrypoint_1(0x123, 1);
                return;
            }
            func_80108BD4(arg0, 0xCEB);
            return;
        case 0xCEC:
            func_80108BD4(arg0, 0xCEC);
            return;
        case 0x17FA:
            _susubgame_entrypoint_6(arg0, &data[4], 6, 0x20, 0);
            func_800D1000(0x2E, 1, NULL, 1, 0);
            return;
        case 0x17F7:
        case 0x1807:
        case 0x1808:
        case 0x1809:
            _subaddiedialog_entrypoint_11(arg0->unk0, 0xCEB, 0x46, NULL, 0xB3);
            return;
    }
}

s32 func_808009C0_chmonsterinterior(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    s16 func_800D211C(s32);
    s32 *data;

    data = func_80100094(arg0, 0);
    switch (arg1) {
        case 0x17F7:
            return *data;
        case 0x17F3:
            return 0x4B;
        case 0x1808:
        case 0x181A:
            return func_800D211C(0x85);
        default:
            return 0;
    }
}

void func_80800A44_chmonsterinterior(Actor *arg0, s32 arg1) {
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(u8) _susubgame_entrypoint_2(void *, BtIntPtr);
    void func_800CD08C(s32, f32 *);
    s32 func_800D3948(void);
    s32 func_800DC128(s32, s32);
    void func_800EE7F8(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    void func_80105138(u8 *, BtIntPtr, f32, f32, BtIntPtr);
    Actor *func_80108528(s32, f32 *, s32, Actor **);
    void func_80800BC8_chmonsterinterior(u8 **, s32);
    struct SpawnFlags {
        u8 pad[0x70];
        BT_BITFIELD_ORDER(u8 pad70 : 7, u8 flag : 1);
        BT_BITFIELD_ORDER(u8 flag : 1, u8 pad70 : 7);
    };
    Actor *spawned;
    f32 position[3];
    f32 height;
    s32 pad;
    s32 mode;
    void *data;

    if (arg1 == 0 || arg1 == 1 || arg1 == 2) {
        mode = func_800D3948();
        data = func_80100094(arg0, 0);
        if (_susubgame_entrypoint_2(arg0, (BtIntPtr)data + 0x10)) {
            func_800EE7F8(position, arg0->position);
        } else {
            func_800CD08C(arg0->unk70_25 - 1, position);
        }
        position[1] = arg0->position[1];
        func_80105138((u8 *)arg0, (BtIntPtr)position, 200.0f, -200.0f, (BtIntPtr)&height);
        position[1] = height;
        spawned = func_80108528(arg1 + 0x452, position, func_800DC128(0, 0x167), &arg0);
        spawned->unk3C = arg0->unk0;
        spawned->unk64_20 = mode;
        spawned->actorData[5] = arg1;
        spawned->unk6C_0 = arg0->unk6C_0;
        spawned->unk64_19 = _susubgame_entrypoint_2(arg0, (BtIntPtr)data + 0x10);
        ((struct SpawnFlags *)spawned)->flag = mode == 0;
        func_80800BC8_chmonsterinterior((u8 **)spawned, arg1);
    }
}

void func_80800BC8_chmonsterinterior(u8 **arg0, s32 arg1) {
    s32 func_800D3948(void);
    s32 func_801032B0(Actor *actor,u16 id,u16 palette);
    if (func_800D3948() != 0) {
        func_801032B0(arg0, D_80801FF0_chmonsterinterior[arg1], *(u16 *)(*arg0 + 0x16));
        return;
    }
    func_801032B0(arg0, D_80801FE8_chmonsterinterior[arg1], *(u16 *)(*arg0 + 0x16));
}

s32 func_80800C38_chmonsterinterior(Actor *arg0, s32 *arg1) {
    s32 func_800D0A9C(u32, u32);
    s32 func_800D2054(s32, s32, s32);
    s32 func_800D395C(void);
    void func_800FC6B0(u32);
    u32 func_800FDC28(u32);
    void *func_80100094(Actor *, u32);
    void *data;
    s32 count;
    s32 result;
    s32 available;
    s32 choice;
    s32 completed;
    s32 flag;
    s32 mode;
    s32 state;

    data = func_80100094(arg0, 0);
    count = *(s32 *)data;
    flag = func_800D0A9C(0x2E, 1);
    mode = func_800D395C();
    state = func_800D2054(0, 0x85, count);
    available = (state == 1) && (flag || mode);
    choice = ((count >= 0x4B) != 0) && !flag && !mode;
    completed = choice;
    func_800FDC28(0);
    func_800FC6B0(choice || available ? 0x16 : 0x17);
    *arg1 = 6;
    if (completed) {
        result = 0x17FA;
    } else if (available) {
        result = 0x17F7;
    } else if (!func_800D395C()) {
        if (flag) {
            if (state == 0) {
                result = 0x1809;
            } else {
                result = 0x1808;
            }
        } else {
            result = 0x1807;
        }
    } else {
        result = 0xCEB;
        *arg1 = 0x46;
    }
    return result;
}

/* extern */

void func_80800DA4_chmonsterinterior(Actor *arg0) {
    void _subaddiemulti_entrypoint_3(s32);
    void* func_80100094(Actor*, u32);
    void _sumultiscore_entrypoint_3(u8 *arg0);
    s32 _sumultiscore_entrypoint_4(u8 *, s32, s32, s32);
    u8 *sp1C;

    sp1C = func_80100094(arg0, 0U);
    _subaddiemulti_entrypoint_3(0xA);
    arg0->unk6C_0 = 5;
    _sumultiscore_entrypoint_3(sp1C + 0x28);
    _sumultiscore_entrypoint_4(sp1C + 0x28, 8, 0, 1);
}

void func_80800E0C_chmonsterinterior(Actor *arg0) {
    struct Multi;
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(u8) _gcstatusDll_entrypoint_11(void);
    BT_IDO_ONLY(s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);) BT_NATIVE_ONLY(s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s16);)
    s32 _subaddiefind_entrypoint_9(s32);
    void _sumultiscore_entrypoint_6(struct Multi *);
    void _susubgame_entrypoint_5(Actor *, void *, s32, s32, s32);
    s32 _susubgame_entrypoint_9(void);
    s32 func_800C954C(void);
    s32 func_800CEAD0(s32);
    int func_800D9154(f32 *, f32);
    s32 func_800DA298(s32);
    f32 func_800DC0C0(void);
    f32 func_800DC178(f32, f32);
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    void func_80108B04(Actor *, u32);
    void func_808011BC_chmonsterinterior(Actor *);
    s32 *data;
    f32 random;
    s32 count;
    s32 value;
    s32 activeCount;

    data = func_80100094(arg0, 0);
    _sumultiscore_entrypoint_6((struct Multi *)(data + 10));
    /* Reuse disjoint values to preserve IDO's original register allocation. */
    value = arg0->unk70_10;
    switch (value) {
        case 1:
            if ((!func_800C954C()) && (!func_800DA298(0x6AD))) {
                _subaddiedialog_entrypoint_11(arg0->unk0, 0xCEC, 7, NULL, 0xB3);
                func_80101FDC(arg0, 2);
            }
            break;
        case 3:
            if (func_800CEAD0(arg0->unk6C_0)) {
                func_808011BC_chmonsterinterior(arg0);
                break;
            }
            activeCount = _subaddiefind_entrypoint_9(0x453);
            value = _subaddiefind_entrypoint_9(0x452);
            count = value + _subaddiefind_entrypoint_9(0x454);
            if ((count + activeCount) < 5) {
                if (func_800D9154(&arg0->unk58, func_800DC178(0.5f, 1.0f) / _gcstatusDll_entrypoint_11())) {
                    random = func_800DC0C0();
                    if (random < 0.25f) {
                        count = 0;
                    } else if (random < 0.6f) {
                        count = 1;
                    } else {
                        count = 2;
                    }
                    func_80108B04(arg0, count);
                }
            }
            break;
        case 4:
            if (_susubgame_entrypoint_9()) {
                _susubgame_entrypoint_5(arg0, data + 4, 5, 1, 0);
                _subaddiedialog_entrypoint_11(arg0->unk0, data[2], data[3], NULL, 0xB3);
                func_80101FDC(arg0, 5);
            }
            break;
    }
}

void func_8080101C_chmonsterinterior(Actor *arg0, s32 arg1) {
    void* func_80100094(Actor*, u32);
    void _sumultiscore_entrypoint_12(BtIntPtr arg0, BtIntPtr arg1, s32 arg2);
    _sumultiscore_entrypoint_12((BtIntPtr)func_80100094(arg0, 0U) + 0x28, arg1, 1);
}

s32 func_80801050_chmonsterinterior(Actor *arg0, s32 arg1, s32 arg2) {
    void func_80801114_chmonsterinterior(Actor *, s32, s32);
    s32 func_80801180_chmonsterinterior(Actor *, s32, s32);
    void func_80800A44_chmonsterinterior(Actor *, s32);
    s32 _subaddiemulti_entrypoint_1(s32, s32);
    void func_800BF544(s32, s32, s32);

    switch (arg1) {
    case 0x2E:
        func_80801114_chmonsterinterior(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
        break;
    case 0x30:
        return func_80801180_chmonsterinterior(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
    case 0x3D:
        func_80800A44_chmonsterinterior(arg0, arg2);
        break;
    case 0x95:
        _subaddiemulti_entrypoint_1(0, 0);
        func_800BF544(0, 0, 0);
        func_800BF544(1, 0, 0);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80801114_chmonsterinterior(Actor *arg0, s32 arg1, s32 arg2) {
    void _gcfrontend_entrypoint_10(void);
    s32 _subaddiemulti_entrypoint_2();
    void func_80101FDC(Actor *, u32);
    switch (arg1) {
    case 0xCEC:
        func_8080068C_chmonsterinterior(arg0);
        return;
    case 0x17F8:
    case 0x17F9:
        _subaddiemulti_entrypoint_2();
        func_80101FDC(arg0, 6);
        _gcfrontend_entrypoint_10();
        return;
    }
}

s32 func_80801180_chmonsterinterior(Actor *arg0, s32 arg1, s32 arg2) {
    void* func_80100094(Actor*, u32);
    if (arg1 == 0x17F8) {
        return (*(s32 *)((s8 *)(func_80100094(arg0, 0U)) + (4))) + 1;
    }
    return 0;
}

void func_808011BC_chmonsterinterior(Actor *arg0) {
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(u8) _gcstatusDll_entrypoint_11();
    s32 _subaddiemulti_entrypoint_1(s32, s32);
    void _sumultiscore_entrypoint_11(u8 *, s32, s32, f32);
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(s16) _sumultiscore_entrypoint_8(void *, s32, s32);
    void func_800AA20C(s32, s32);
    void func_800FC6B0(u32);
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    s32 temp;
    s32 scores[8];
    s32 *data;
    s32 max;
    s32 i;
    s32 j;
    s32 k;
    s32 dialog;

    data = func_80100094(arg0, 0);
    max = -1;
    for (j = 0; j < _gcstatusDll_entrypoint_11(); j++) {
        scores[j] = _sumultiscore_entrypoint_8(data + 10, j, 8);
        if (max < scores[j]) {
            max = scores[j];
        }
        func_800AA20C(j, scores[j]);
    }
    for (j = 0; j < _gcstatusDll_entrypoint_11(); j++) {
        if (max == scores[j]) {
            _sumultiscore_entrypoint_11((u8 *)(data + 10), j, 8, 3.0f);
        }
    }
    for (i = 1; i < _gcstatusDll_entrypoint_11(); i++) {
        for (k = i; k > 0 && scores[k - 1] < scores[k]; k--) {
            temp = scores[k];
            scores[k] = scores[k - 1];
            scores[k - 1] = temp;
        }
    }
    func_800FC6B0(0x16);
    if (scores[0] != scores[1]) {
        for (k = 0; _sumultiscore_entrypoint_8(data + 10, k, 8) != scores[0]; k++) {
        }
        data[1] = k;
        dialog = 0x17F8;
    } else {
        dialog = 0x17F9;
    }
    _subaddiemulti_entrypoint_1(0, 0);
    func_80101FDC(arg0, 4);
    data[2] = dialog;
    data[3] = 6;
}

void func_808013D0_chmonsterinterior(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    void func_8010A3E8(void *, f32);
    f32 func_80801ADC_chmonsterinterior(s32, f32 *);
    f32 func_80801B7C_chmonsterinterior(s32);
    f32 func_800DC178(f32, f32);
    void func_80102FDC(void *, f32);
    s32 _subaddieDll_entrypoint_1(Actor *);
    void _subaddierouteDll_entrypoint_3(Actor *, void *, f32 *);
    void _subaddierouteDll_entrypoint_1(Actor *);
    s32 func_8010D930(s32, s32, f32 *, s32 *);
    typedef struct {
        s32 pad[10];
        f32 unk28;
        s32 kind;
        f32 unk30;
        s32 pad34[15];
        u32 flags;
    } MonsterInteriorData;
    register s32 *data;
    register s32 kind;

    data = func_80100094(arg0, 0);
    kind = arg0->actorData[5];
    func_8010A3E8(arg0, 0.3f);
    data[3] = 0;
    arg0->position[1] -= 250.0f;
    ((MonsterInteriorData *)arg0)->unk28 = 0.6f;
    ((MonsterInteriorData *)arg0)->unk30 = func_80801ADC_chmonsterinterior(kind, (f32 *)&data[10]);
    arg0->unk58 = func_80801B7C_chmonsterinterior(kind);
    func_80102FDC(arg0, func_800DC178(0.6f, 0.8f));
    _subaddieDll_entrypoint_1(arg0);
    _subaddierouteDll_entrypoint_3(arg0, data, arg0->position);
    _subaddierouteDll_entrypoint_1(arg0);
    if (arg0->unk64_19) {
        arg0->unk64_24 = 0;
        arg0->unk58 = 5.5f;
    }
    func_8010D930(4, ((MonsterInteriorData *)arg0)->flags & 1, arg0->position, D_8080201C_chmonsterinterior);
}

void func_808014E8_chmonsterinterior(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    f32 func_800D8FF8(void);
    s32 func_800CEAD0(s32);
    void func_8010A570(Actor *);
    void func_80101FDC(Actor *, u32);
    void _subaddiefade_entrypoint_3(Actor *);
    s32 func_80801C1C_chmonsterinterior(u8 *);
    s32 func_80801C78_chmonsterinterior(u8 *);
    void func_8010C93C(BtIntPtr, BtIntPtr, f32);
    f32 _subaddiejoy_entrypoint_9(void *, void *, s32);
    void func_80102BF8(void *, f32, f32, f32);
    s32 func_8010C3A8(Actor *, u32, f32);
    s32 _subaddierouteDll_entrypoint_4(Actor *);
    s32 _subaddierouteDll_entrypoint_7(Actor *, void *, f32, f32, f32, s32);
    BT_IDO_ONLY(void _subaddierouteDll_entrypoint_6(Actor *, void *, u32, s32, f32, s32, s32);) BT_NATIVE_ONLY(s32 _subaddierouteDll_entrypoint_6(Actor *, void *, s32, s32, f32, s32, s32);)
    void _subaddierouteDll_entrypoint_5(Actor *, void *, u32, f32, f32, f32);
    f32 func_800F15F8(f32, f32, f32);
    s32 func_8010B990(Actor *, s32);
    BT_IDO_ONLY(u8) BT_NATIVE_ONLY(s32) func_800D9078(f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    s32 func_8010D930(s32, s32, f32 *, s32 *);
    void func_800FFAB0(Actor *);
    typedef struct {
        u16 pad0[3];
        u16 unk6;
        s32 unk8;
        s32 unkC;
        s32 pad10[6];
        f32 unk28;
    } RouteData;
    typedef struct {
        f32 pad0[9];
        f32 unk24;
        f32 unk28;
        s32 kind;
        f32 unk30;
    } MonsterData;
    RouteData *data;
    f32 dt;
    f32 joy;

    data = func_80100094(arg0, 0);
    dt = func_800D8FF8();
    if (arg0->unk70_10 != 4 && func_800CEAD0(arg0->unk6C_0) && !arg0->unk64_19) {
        func_8010A570(arg0);
        func_80101FDC(arg0, 4);
        _subaddiefade_entrypoint_3(arg0);
    }
    switch (arg0->unk70_10) {
        case 1:
            if (func_80801C1C_chmonsterinterior((u8 *)arg0)) {
                func_80101FDC(arg0, 2);
            }
            break;
        case 2:
            func_8010C93C((BtIntPtr)arg0, (BtIntPtr)arg0->position, 1.0f);
            if (arg0->unk64_29) {
                joy = _subaddiejoy_entrypoint_9(arg0, &arg0->unk54, 3);
                ((MonsterData *)arg0)->unk24 = data->unk28 * 1.4f;
                func_80102BF8(arg0, 0.2f, 8.0f, 600.0f);
                func_8010C3A8(arg0, 0x200025, joy);
            } else {
                if (_subaddierouteDll_entrypoint_4(arg0)) {
                    _subaddierouteDll_entrypoint_7(arg0, data, arg0->rotation[1], arg0->unk54, 400.0f, 0x4802);
                    data->unkC = data->unk6;
                }
                _subaddierouteDll_entrypoint_6(arg0, data, data->unkC, 0x3F, 0.4f, 20, 40);
                _subaddierouteDll_entrypoint_5(arg0, data, data->unkC, 0.2f, 4.0f, 200.0f);
                ((MonsterData *)arg0)->unk24 = func_800F15F8(((MonsterData *)arg0)->unk24, ((MonsterData *)arg0)->unk30, dt * 800.0f);
                if (!arg0->unk64_19) {
                    func_8010B990(arg0, 0x325);
                }
            }
            if (func_800D9078(&arg0->unk58)) {
                func_80101FDC(arg0, 3);
                ((MonsterData *)arg0)->unk28 = 0.6f;
                arg0->unk64_24 = 0;
            }
            break;
        case 3:
            if (!arg0->unk64_19 && func_800F10B4(((MonsterData *)arg0)->unk28, 0.0f, 0.6f, 1.0f, 0.0f) > 0.3f) {
                func_8010D930(5, arg0->unk70_0, arg0->position, D_80802030_chmonsterinterior);
                arg0->unk64_19 = 1;
            }
            if (func_80801C78_chmonsterinterior((u8 *)arg0)) {
                func_800FFAB0(arg0);
            }
            break;
        case 4:
            break;
    }
}

void func_808017E8_chmonsterinterior(s32 arg0) 
{
}
s32 func_808017F0_chmonsterinterior(Actor *arg0, s32 arg1, Unk80132ED0 *volatile arg2) {
    void func_80101074(void *);
    s32 func_801015D0(Actor *);
    void func_8010DC50(s32);
    void func_8010DCB4(s32);
    int func_8010DD20(u8 *, s32, u8 *);
    void func_80801930_chmonsterinterior(Actor *, Unk80132ED0 *);
    Unk80132ED0 *data;

    switch (arg1) {
        case 0x40:
            func_80801930_chmonsterinterior(arg0, arg2);
            break;
        case 0x99:
            func_80101074(arg0->unk64_20 ? NULL : D_80801E58_chmonsterinterior);
            break;
        case 0x1F:
            data = arg2;
            if (arg0->unk64_20) {
                func_8010DD20((u8 *)arg0, arg0->unk6C_9 - 0x44B, (u8 *)data);
            } else {
                func_801015D0(arg0);
            }
            break;
        case 0x29:
            if (arg0->unk64_20) {
                func_8010DC50(arg0->unk6C_9 - 0x44B);
            }
            break;
        case 0x2A:
            if (arg0->unk64_20) {
                func_8010DCB4(arg0->unk6C_9 - 0x44B);
            }
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80801930_chmonsterinterior(Actor *arg0, Unk80132ED0 *arg1) {
    void _chscorepoints_entrypoint_2(s32, BtIntPtr, f32 *, s32);
    BtIntPtr _subaddiemulti_entrypoint_5(Unk80132ED0 *);
    void _sumultiscore_entrypoint_7(u8 *, BtIntPtr, s32, s32);
    BtIntPtr func_800B53A4(s32);
    void func_800BA22C(BtIntPtr, s32);
    void func_800BA670(BtIntPtr, s32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    s32 func_800D3948(void);
    s32 func_800DC128(s32, s32);
    void func_800FFAB0(Actor *);
    void *func_80100094(Actor *, u32);
    s32 func_8010114C(BtIntPtr, s32, BtIntPtr);
    void func_80103DFC(Actor *, f32 *);
    Actor *func_80106790(Unk80132ED0 *);
    s32 func_8010D930(s32, s32, f32 *, s32 *);
    s32 pad;
    s32 *data;
    s32 count;
    BtIntPtr emitter;
    BtIntPtr player;
    f32 position[3];
    f32 scorePosition[3];

    data = func_80100094(func_80106790(arg0->unk3C), 0);
    if (func_800D3948() != 0) {
        count = 2;
    } else {
        count = func_800DC128(6, 8);
    }
    emitter = func_800B53A4(count);
    player = _subaddiemulti_entrypoint_5(arg1);
    func_80103DFC(arg0, position);
    func_800BABB8(emitter, position, position, 1.0f, D_80802044_chmonsterinterior);
    func_800BA670(emitter, D_8080208C_chmonsterinterior[arg0->actorData[5]]);
    func_800BA22C(emitter, count);
    if (func_800D3948() != 0) {
        _sumultiscore_entrypoint_7((u8 *)&data[10], player, 8, D_80801E50_chmonsterinterior[arg0->actorData[5]]);
    } else {
        *data += D_80801E50_chmonsterinterior[arg0->actorData[5]];
    }
    func_8010D930(1, arg0->unk70_0, position, D_8080207C_chmonsterinterior);
    func_80103DFC(arg0, scorePosition);
    _chscorepoints_entrypoint_2(D_80801E50_chmonsterinterior[arg0->actorData[5]], player, scorePosition, 1);
    func_800FFAB0(arg0);
    if (*(u16 *)&arg1->unk18 & 1) {
        func_8010114C((BtIntPtr)arg1, 0x98, 0);
    }
}

f32 func_80801ADC_chmonsterinterior(s32 arg0, f32 *arg1) {
    f32 func_800DC178(f32, f32);
    switch (arg0) {
    case 0:
        *arg1 = 600.0f;
        return func_800DC178(500.0f, 600.0f);
    case 1:
        *arg1 = 450.0f;
        return func_800DC178(350.0f, 450.0f);
    case 2:
        *arg1 = 300.0f;
        return func_800DC178(200.0f, 300.0f);
    default:
        return -1.0f;
    }
}

f32 func_80801B7C_chmonsterinterior(s32 arg0) {
    f32 func_800DC178(f32, f32);
    switch (arg0) {
    case 0:
        return func_800DC178(2.5f, 3.0f);
    case 1:
        return func_800DC178(3.0f, 3.5f);
    case 2:
        return func_800DC178(3.5f, 4.5f);
    default:
        return -1.0f;
    }
}

/* extern */
s32 func_80801C1C_chmonsterinterior(u8 *arg0) {
    BT_IDO_ONLY(u8) BT_NATIVE_ONLY(s32) func_800D9078(f32 *);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    s32 sp24;
    s32 temp_v0;

    temp_v0 = func_800D9078((f32 *) (arg0 + 0x28));
    sp24 = temp_v0;
    (((Actor *)arg0)->position[1]) = func_800F12D4((*(f32 *)((s8 *)(arg0) + (0x28))), 0.0f, 0.6f, 0.0f, -250.0f);
    return sp24;
}

/* extern */

s32 func_80801C78_chmonsterinterior(u8 *arg0) {
    BT_IDO_ONLY(u8) BT_NATIVE_ONLY(s32) func_800D9078(f32 *);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    s32 sp28;

    sp28 = func_800D9078((f32 *) (arg0 + 0x28));
    (((Actor *)arg0)->position[1]) = func_800F12D4((*(f32 *)((s8 *)(arg0) + (0x28))), 0.0f, 0.6f, -250.0f, 0.0f);
    return sp28;
}
