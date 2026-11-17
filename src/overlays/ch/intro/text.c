#include "ch/introtext.h"

OSThread *chintrotext_entrypoint_0(void)
{
    extern u8 D_808007D0_chintrotext[];

    return (OSThread *) D_808007D0_chintrotext;
}

void func_8080000C_chintrotext(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    struct IntroTextData {
        s16 count;
        u8 pad2[0x14];
        s16 offsets[10];
        s16 textIds[10];
    } *data;
    u8 *text;
    s32 i;
    s32 j;
    s32 c;
    s32 hash = '#';
    s32 newline = '\n';

    text = func_80100094(arg0, 0);
    data = func_80100094(arg0, 1);
    data->offsets[0] = 0;
    data->count = 1;
    data->textIds[0] = 0xC26;
    for (i = 0; text[i] != 0; i++) {
        c = text[i];
        if (hash == c) {
            for (j = i + 1; text[j] != 0; j++) {
                text[j - 1] = text[j];
            }
            text[j - 1] = 0;
            data->textIds[data->count - 1] = 0xC25;
            c = text[i];
        }
        if (newline == c) {
            data->offsets[data->count] = i + 1;
            data->textIds[data->count] = 0xC26;
            data->count++;
            text[i] = 0;
            if (data->count == 9) {
                break;
            }
        }
    }
    func_800DA544(FLAG2_6AD_CURRENTLY_SHOWING_INTROTEXT);
}

void func_80800130_chintrotext(s32 arg0)
{
    func_800DA524(FLAG2_6AD_CURRENTLY_SHOWING_INTROTEXT);
}

void func_80800154_chintrotext(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s32 func_800D9078(f32 *);
    s32 func_800C954C(void);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    void _subaddiefade_entrypoint_1(void *arg0, s32 arg1);
    void func_800FFAB0(Actor *);
    void func_8080051C_chintrotext(Actor *, s32);
    struct IntroTextData {
        s16 count;
        s16 y[10];
        s16 offsets[10];
        s16 textIds[10];
        u8 alignment;
        u8 style;
    } *data;
    struct IntroTextStyle {
        f32 fadeIn;
        f32 duration;
        f32 fadeOut;
        s32 spacing;
    union {
        struct IntroTextStyle *style;
        struct IntroTextData *lines;
    } work;
    s32 i;
    s32 y;
    };
    extern f32 D_808007A0_chintrotext[][4];
    s32 expired;
    s32 spacing;
    union {
        struct IntroTextStyle *style;
        struct IntroTextData *lines;
    } work;
    s32 i;
    s32 y;

    data = func_80100094(arg0, 1);
    expired = func_800D9078(&arg0->unk58);
    work.style = (struct IntroTextStyle *)D_808007A0_chintrotext[data->style];
    spacing = work.style->spacing;
    switch (arg0->unk70_10) {
        case 1: {
            work.lines = func_80100094(arg0, 1);
            switch (work.lines->alignment) {
                case 0:
                    y = (228 - work.lines->count * spacing) >> 1;
                    y += 2.5f * spacing;
                    goto position_lines;
                case 1:
                    y = (114 - work.lines->count * spacing) >> 1;
                    goto position_lines;
                case 2:
                    y = (228 - work.lines->count * spacing) >> 1;
                    goto position_lines;
            }
position_lines:
            for (i = 0; i < work.lines->count; i++) {
                work.lines->y[i] = i * spacing + y;
            }
            func_8080051C_chintrotext(arg0, 2);
            break;
        }
        case 2:
            func_800DA544(FLAG2_6AD_CURRENTLY_SHOWING_INTROTEXT);
            if (func_800C954C() == 0) {
                func_8080051C_chintrotext(arg0, 3);
            }
            break;
        case 3:
            func_800DA544(FLAG2_6AD_CURRENTLY_SHOWING_INTROTEXT);
            _subaddiefade_entrypoint_1(arg0, (s32)func_800F12D4(arg0->unk58, 0, D_808007A0_chintrotext[data->style][0], 255.0f, 0.0f));
            if (expired) {
                func_8080051C_chintrotext(arg0, 4);
            }
            break;
        case 4:
            func_800DA544(FLAG2_6AD_CURRENTLY_SHOWING_INTROTEXT);
            if (expired) {
                func_8080051C_chintrotext(arg0, 5);
            }
            break;
        case 5:
            _subaddiefade_entrypoint_1(arg0, (s32)func_800F12D4(arg0->unk58, 0, work.style->fadeOut, 0.0f, 255.0f));
            if (expired) {
                func_800FFAB0(arg0);
            }
            break;
    }
}

void func_808003EC_chintrotext(Actor *arg0, u32 *arg1) {
    void *func_80100094(Actor *, u32);
    int func_800A819C(void);
    void _fxkern_entrypoint_1(u32 *, u32, u32 *);
    void _fxkern_entrypoint_2(void);
    void _fxkern_entrypoint_3(f32);
    s32 _subaddiefade_entrypoint_0(Actor *);
    void func_800B8C8C(s32);
    void func_800B8CE0(s32);
    BtIntPtr func_800E71B8(BtIntPtr);
    struct IntroTextData {
        s16 count;
        s16 y[10];
        s16 offsets[10];
        s16 textIds[10];
    } *data;
    s32 i;
    f32 scale;

    data = func_80100094(arg0, 1);
    if ((s32)arg0->unk70_10 >= 3 && func_800A819C() != 0) {
        _fxkern_entrypoint_2();
        func_800B8C8C(_subaddiefade_entrypoint_0(arg0));
        for (i = 0; i < data->count; i++) {
            func_800B8CE0(data->textIds[i]);
            if (data->textIds[i] == 0xC25) {
                scale = 0.75f;
            } else {
                scale = 1.0f;
            }
            _fxkern_entrypoint_3(scale);
            _fxkern_entrypoint_1(arg1, data->y[i],
                (u32 *)func_800E71B8((BtIntPtr)func_80100094(arg0, 0) + data->offsets[i]));
        }
    }
}

void func_8080051C_chintrotext(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    void _subaddiefade_entrypoint_1(void *arg0, s32 arg1);
    extern f32 D_808007A0_chintrotext[][4];
    extern f32 D_808007A4_chintrotext[][4];
    extern f32 D_808007A8_chintrotext[][4];
    struct IntroTextData {
        u8 unk0[0x3F];
        u8 unk3F;
    } *data;

    data = func_80100094(arg0, 1);
    func_80101FDC(arg0, arg1);
    switch (arg1) {
        case 2:
            _subaddiefade_entrypoint_1(arg0, 0);
            func_800DA544(FLAG2_6AD_CURRENTLY_SHOWING_INTROTEXT);
            break;
        case 3:
            arg0->unk58 = D_808007A0_chintrotext[data->unk3F][0];
            break;
        case 4:
            arg0->unk58 = D_808007A4_chintrotext[data->unk3F][0];
            break;
        case 5:
            func_800DA524(FLAG2_6AD_CURRENTLY_SHOWING_INTROTEXT);
            arg0->unk58 = D_808007A8_chintrotext[data->unk3F][0];
            break;
    }
}

void chintrotext_entrypoint_1(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 _chbaddiesetup_entrypoint_4(s32 *, s32, s32, s32, s32);
    s32 func_800A9C98();
#ifdef BT_NATIVE
    void chintrotext_entrypoint_3(s32 arg0, s16 arg1, s32 arg2, s32 arg3);
#else
    extern s32 _chintrotext_entrypoint_3;
#endif
    if (func_800A9C98() == 0) {
        _chbaddiesetup_entrypoint_4(&_chintrotext_entrypoint_3, arg0, arg1, arg3, arg2);
    }
}

/* extern */

s32 chintrotext_entrypoint_2(s32 arg0) {
    s32 _gcintrotext_entrypoint_2(s32, s32 *, s32 *);
    s32 sp24;
    s32 sp20;
    s32 temp_v0;

    temp_v0 = _gcintrotext_entrypoint_2(-1, &sp24, &sp20);
    if ((temp_v0 != -1) && ((arg0 != 0) || (temp_v0 > 0))) {
        chintrotext_entrypoint_1(sp24, sp20, 0, 0);
        return 1;
    }
    return 0;
}

/* extern */

void chintrotext_entrypoint_3(s32 arg0, s16 arg1, s32 arg2, s32 arg3) {
    u32 *_gldbstring_entrypoint_0(u32 *, u32);
    u32 *_gldbstring_entrypoint_1(u32 *, s16);
    void _gldbstring_entrypoint_2(s32);
    void func_800E715C(u8 *, u8 *);
    s32 func_800E7188(u8 *);
    void func_800EFD24(f32 [3]);
    u32 *func_80100074(Actor *, u32, u32);
    void *func_80100094(Actor *, u32);
    Actor *func_80108474(u32, f32 *, s32);
    f32 sp2C[3];
    Actor *sp28;
    struct {
        u8 unk0[0x3E];
        s8 unk3E;
        s8 unk3F;
    } *sp24;
    u32 *sp20;

    func_800EFD24(sp2C);
    sp28 = func_80108474(0x3B0, sp2C, 0);
    if (sp28 != 0) {
        sp24 = func_80100094(sp28, 1);
        sp20 = _gldbstring_entrypoint_1(_gldbstring_entrypoint_0(0, arg0), arg1);
        func_80100074(sp28, 0, func_800E7188((u8 *)sp20) + 1);
        func_800E715C(func_80100094(sp28, 0), (u8 *)sp20);
        _gldbstring_entrypoint_2(arg0);
        sp24->unk3E = arg2;
        sp24->unk3F = arg3;
    }
}
