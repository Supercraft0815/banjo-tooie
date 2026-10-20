#include "common.h"

void func_80102424(Actor *, s32);

void func_80800000_chfriendlystonehead(s32 arg0)
{
    func_80102424(arg0,1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/friendlystonehead/func_80800020_chfriendlystonehead.s")

/* extern */

void func_80800160_chfriendlystonehead(void **arg0, s32 arg1) {
    s32 func_800DF744(s32, u32);
    s32 func_80101870(void **, s32);
    func_800DF744(3, (u32) ((*(s32 *)((s8 *)(*arg0) + (0x28))) << 0x12) >> 0x1F);
    func_80101870(arg0, arg1);
}

s32 func_808001A8_chfriendlystonehead(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _gcdialogcamera_entrypoint_3(s32 *, f32);
    void func_808006C4_chfriendlystonehead(Actor *, s32, s32);
    extern s32 D_80800968_chfriendlystonehead;

    switch (arg1) {
    case 0x2E:
        func_80102424(arg0, 3);
        break;
    case 0x2F:
        func_808006C4_chfriendlystonehead(arg0, ((s16 *)&arg2)[0], ((s16 *)&arg2)[1]);
        break;
    case 0x52:
        _gcdialogcamera_entrypoint_3(&D_80800968_chfriendlystonehead, arg0->scale);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_80800238_chfriendlystonehead(Actor *arg0) {
    struct { u8 pad[0x28]; u32 : 18; u32 flag : 1; u32 : 13; } *flags;
    if (func_8010C9B0((f32 *) ((s8 *) arg0 + 4), 0x1F4) != 0) {
        func_80102424(arg0, 2);
        flags = (void *) arg0->unk0;
        flags->flag = 1;
    }
}

void func_80800284_chfriendlystonehead(Actor *arg0) {
    if (func_8010C9B0((f32 *) ((s8 *) arg0 + 4), 0x1F4) == 0) {
        func_80102424(arg0, 5);
    }
}

/* extern */

void func_808002BC_chfriendlystonehead(void *arg0) {
    s32 func_80102BF8(void *, s32, s32, s32);
    f32 func_8010CD28();
    (*(f32 *)((s8 *)(arg0) + (0x54))) = func_8010CD28();
    func_80102BF8(arg0, 0x3DCCCCCD, 0x40800000, 0x42F00000);
}

/* extern */

void func_808002F8_chfriendlystonehead(void) {
    s32 func_800DA524(s32);
    func_800DA524(0x425);
    func_800DA524(0x426);
    func_800DA524(0x427);
}

void func_80800328_chfriendlystonehead(Actor *arg0) {
    s32 _capod_entrypoint_13(s32, s32, s32, s32);
    s32 _subaddiedialog_entrypoint_8(s32, void *, s32 *, s32 *, s32);
    s32 func_800D0A9C(u32, u32);
    s32 func_800DA298(s32);
    s32 func_800DA9E4(s32, s32);
    void func_80800830_chfriendlystonehead(Actor *, s16);
    extern s32 D_808008C0_chfriendlystonehead;
    extern s32 D_80800978_chfriendlystonehead;
    s32 var_v1;

    var_v1 = func_800DA298(0x9CB) != 0;
    if (var_v1 != 0) {
        var_v1 = func_800DA298(0x5F) != 0;
    }
    if ((var_v1 != 0) && (func_800D0A9C(3, 1) == 0)) {
        func_80800830_chfriendlystonehead(arg0, 0xF20);
        _capod_entrypoint_13(arg0->unk0, 0, 1, 0x2010);
        return;
    }
    if (func_800DA9E4(0x9CA, 0) != 0) {
        func_80800830_chfriendlystonehead(arg0, 0xF22);
        return;
    }
    if (func_800DA9E4(0x9CB, 0) != 0) {
        func_808002F8_chfriendlystonehead();
        if (func_800DA298(0x5E) == 0) {
            func_80800830_chfriendlystonehead(arg0, 0xF1E);
            return;
        }
        if (func_800DA298(0x5F) == 0) {
            func_80800830_chfriendlystonehead(arg0, 0xF1F);
        }
    } else {
        _subaddiedialog_entrypoint_8(arg0, arg0->position, &D_80800978_chfriendlystonehead, &D_808008C0_chfriendlystonehead, 4);
    }
}

void func_80800444_chfriendlystonehead(Actor *arg0) {
    s32 _subaddiedialog_entrypoint_8(s32, void *, s32 *, s32 *, s32);
    s32 func_800D0A9C(u32, u32);
    s32 func_800DA298(s32);
    s32 func_800DA9E4(s32, s32);
    void func_80800830_chfriendlystonehead(Actor *, s16);
    extern s32 D_808008E0_chfriendlystonehead;
    extern s32 D_80800988_chfriendlystonehead;
    s32 var_v1;

    var_v1 = func_800DA298(0xA17) != 0;
    if (var_v1 != 0) {
        var_v1 = func_800DA298(0x369) != 0;
    }
    if ((var_v1 != 0) && (func_800D0A9C(0x44, 1) == 0)) {
        func_80800830_chfriendlystonehead(arg0, 0x127E);
        return;
    }
    if (func_800DA9E4(0xA16, 0) != 0) {
        func_80800830_chfriendlystonehead(arg0, 0x1280);
        return;
    }
    if (func_800DA9E4(0xA17, 0) != 0) {
        if (func_800DA298(0x368) == 0) {
            func_80800830_chfriendlystonehead(arg0, 0x127C);
            return;
        }
        if (func_800DA298(0x369) == 0) {
            func_80800830_chfriendlystonehead(arg0, 0x127D);
        }
    } else {
        _subaddiedialog_entrypoint_8(arg0, arg0->position, &D_80800988_chfriendlystonehead, &D_808008E0_chfriendlystonehead, 5);
    }
}

s32 func_80800540_chfriendlystonehead(Actor *arg0) {
    s32 func_800EA05C(void);
    u32 func_800F54E4(void);
    s32 func_800F64A4(s32, s32);
    s32 func_800DA564(s32, s32);
    s32 func_800DA7A8(s32, s32, s32);
    s32 func_800DC128(s32, s32);
    s32 _subaddiedialog_entrypoint_7(s32, s32, s32 *);
    extern u16 D_80800908_chfriendlystonehead[][2];
    extern s32 D_80800998_chfriendlystonehead;
    extern u16 D_8080099C_chfriendlystonehead;
    extern u16 D_8080099E_chfriendlystonehead;
    extern u16 D_808009A4_chfriendlystonehead;
    u16 text;
    u16 secondary;
    s32 index;

    switch (func_800EA05C()) {
        case 0xBB:
            func_80800328_chfriendlystonehead(arg0);
            return 1;
        case 0x12D:
            func_80800444_chfriendlystonehead(arg0);
            return 1;
    }
    index = arg0->unk74_7;
    index--;
    text = D_80800908_chfriendlystonehead[index][1];
    if (func_800F64A4(func_800F54E4(), 0x1000)) {
        secondary = 0xF5A;
    } else {
        secondary = D_80800908_chfriendlystonehead[index][0];
    }
    if (text == 0xF30) {
        if (!func_800DA564(0x32B, 2)) {
            func_800DA7A8(0x32B, func_800DC128(0, 3) + 1, 2);
        }
        text += func_800DA564(0x32B, 2) - 1;
    }
    D_8080099C_chfriendlystonehead = text;
    D_808009A4_chfriendlystonehead = secondary;
    D_8080099E_chfriendlystonehead = text;
    return _subaddiedialog_entrypoint_7((s32)arg0, (s32)arg0->position, &D_80800998_chfriendlystonehead);
}

/* extern */

void func_80800680_chfriendlystonehead(s32 *arg0, s32 arg1) {
    s32 _capod_entrypoint_13(s32, s32, s32, s32);
    s32 func_800C01A8(s32, s32);
    func_800C01A8(0x6B, 0);
    _capod_entrypoint_13(*arg0, 0, arg1, 0x2010);
}

void func_808006C4_chfriendlystonehead(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _capod_entrypoint_13(s32, s32, s32, s32);
    s32 func_800C01A8(s32, s32);
    s32 func_800D1000(s32, s32, s32 *, s32, s32);
    s32 func_800DA544(s32);

    switch (arg1) {
        case 0xF1E:
            func_800DA544(0x5E);
            func_80800680_chfriendlystonehead((s32 *)arg0, 8);
            break;
        case 0xF1F:
            func_800DA544(0x5F);
            func_80800680_chfriendlystonehead((s32 *)arg0, 0xA);
            break;
        case 0xF19:
            func_800DA544(0x576);
            func_80800680_chfriendlystonehead((s32 *)arg0, 6);
            break;
        case 0xF20:
            func_800D1000(3, 1, NULL, 1, 0);
            break;
        case 0x127C:
            func_800DA544(0x368);
            func_80800680_chfriendlystonehead((s32 *)arg0, 2);
            break;
        case 0x127D:
            func_800DA544(0x369);
            func_80800680_chfriendlystonehead((s32 *)arg0, 4);
            break;
        case 0x1277:
            func_800DA544(0x577);
            func_80800680_chfriendlystonehead((s32 *)arg0, 0);
            break;
        case 0x127E:
            func_800D1000(0x44, 1, NULL, 1, 0);
            func_800C01A8(0x64, 0);
            _capod_entrypoint_13(arg0->unk0, NULL, 6, 0x2010);
            break;
    }
}

/* extern */

void func_80800830_chfriendlystonehead(Actor *arg0, s16 arg1) {
    struct Flags { u8 pad[0x2A]; u8 low : 2; u8 flag : 1; u8 high : 5; };

    _subaddiedialog_entrypoint_11(arg0->unk0, arg1, 0xE, (f32 *)((s8 *)arg0 + 4), 0x35);
    func_80102424(arg0, 6);
    ((struct Flags *)arg0->unk0)->flag = 1;
}

OSThread *chfriendlystonehead_entrypoint_0(void)
{
    extern u8 D_808009B4_chfriendlystonehead[];

    return (OSThread *) D_808009B4_chfriendlystonehead;
}
