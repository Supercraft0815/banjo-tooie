#include "common.h"

void func_80800000_chintrochar(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    void *_suexpression_entrypoint_7(Actor *, s32, s16);
    void _suexpression_entrypoint_12(void *, f32, f32);
    void _suexpression_entrypoint_3(s32, s32 *, s32 *, s32 *);
    void _suexpression_entrypoint_6(void *, s32, s32, s32, s32);
    void _suexpression_entrypoint_5(void *, s32);
    s16 func_8001B668(s32, s32);
    void *func_8001B798(s16);
    extern u16 D_80804790_chintrochar[][16];
    s16 *data;
    u16 *config;
    u32 flags;
    s32 size0;
    s32 size1;
    s32 size2;
    s16 handle;
    void *buffer;
    void *result;
    u16 *entry;

    data = func_80100094(arg0, 2);
    config = D_80804790_chintrochar[arg0->unk74_7];
    entry = config;
    handle = (s16)entry[-0x31D];
    flags = *(u32 *)&entry[-0x318];
    _suexpression_entrypoint_7(arg0, 1, handle);
    if (flags & 0x40000) {
        _suexpression_entrypoint_12(func_80100094(arg0, 1), 160.0f, 120.0f);
    }
    if (flags & 0x2000) {
        _suexpression_entrypoint_3(0x7B, &size0, &size1, &size2);
        handle = func_8001B668(0, size0 + size1 + size2);
        data[0x63] = handle;
        result = func_8001B798(data[0x63]);
        buffer = result;
        _suexpression_entrypoint_6(result, 0x7B, size2, size0, size1);
        _suexpression_entrypoint_5(buffer, 2);
    }
}

s32 func_808000FC_chintrochar(Actor *arg0) {
    s32 _subaddieDll_entrypoint_0(Actor *);
    void _subaddiefade_entrypoint_11(Actor *, s32 *);
    void func_80108658(void *, s32, s32, void *);
    void func_8010A63C(Actor *);
    void func_8010A800(Actor *, s32);
    extern u16 D_80804790_chintrochar[][16];
    struct IntroFlags {
        u8 pad0[0x70];
        u8 pad70 : 7;
        u8 flag70 : 1;
        u8 pad71 : 2;
        u8 flag71 : 1;
        u8 pad71low : 5;
        u8 pad72[5];
        u8 pad77 : 4;
        u8 mode : 4;
        u8 pad78[3];
        u8 pad7B : 6;
        u8 flag7B : 1;
        u8 pad7B0 : 1;
        u8 pad7C[0x18];
        u8 pad94 : 1;
        u8 flag94 : 1;
        u8 pad94low : 6;
    };
    s32 flags;
    s32 flags2;
    s32 color[3];

    flags = *(u32 *)&D_80804790_chintrochar[arg0->unk74_7][-0x31C] & 0x3FFFFFFF;
    flags2 = *(u32 *)&D_80804790_chintrochar[arg0->unk74_7][-0x31A] & 0x3FFFFFFF;
    if (flags & 0x400) {
        _subaddieDll_entrypoint_0(arg0);
    }
    if (flags2 & 0x80800000) {
        ((struct IntroFlags *)arg0)->flag94 = 1;
    }
    if (flags & 0x800000) {
        ((struct IntroFlags *)arg0)->flag71 = 1;
    }
    if (flags & 8) {
        ((struct IntroFlags *)arg0)->flag70 = 1;
    }
    if (flags2 & 0x80000010) {
        ((struct IntroFlags *)arg0)->flag7B = 1;
        color[0] = ((u8 *)D_80804790_chintrochar[arg0->unk74_7])[-0x62C];
        color[1] = ((u8 *)D_80804790_chintrochar[arg0->unk74_7])[-0x62B];
        color[2] = ((u8 *)D_80804790_chintrochar[arg0->unk74_7])[-0x62A];
        _subaddiefade_entrypoint_11(arg0, color);
    }
    if (flags & 0x20000) {
        func_8010A800(arg0, 2);
    }
    if (flags & 0x400000) {
        func_8010A800(arg0, 3);
    }
    if (flags & 0x100) {
        ((struct IntroFlags *)arg0)->mode = 1;
    }
    func_80108658(arg0, flags, flags2, NULL);
    if (flags & 0x20000) {
        func_8010A800(arg0, 2);
    } else if (flags & 0x400000) {
        func_8010A800(arg0, 3);
    } else {
        func_8010A800(arg0, 0);
    }
    if (flags & 0x800) {
        func_8010A63C(arg0);
    }
}

void func_808002FC_chintrochar(Actor *arg0) {
    s16 func_800AE020(void);
    u8 *func_800DBFF8(void);
    s32 func_80105DFC(Actor *);
    extern u32 func_80804158_chintrochar[][8];
    u32 flags;

    flags = func_80804158_chintrochar[arg0->unk74_7][0] & 0x3FFFFFFF;
    if (flags & 0x40) {
        arg0->unk0->unk4 = func_800DBFF8();
    }
    if (flags & 0x1000) {
        func_80105DFC(arg0);
    }
    if (flags & 0x20) {
        *(s16 *)&arg0->unk0->unk10 = func_800AE020();
    }
}

void func_80800398_chintrochar(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    u32 *_gldbstring_entrypoint_0(u32 *, u32);
    u32 *_gldbstring_entrypoint_1(u32 *, s16);
    void _gldbstring_entrypoint_2(s32);
    void func_800E715C(u8 *, u8 *);
    u8 *data;
    u32 *text;
    s32 index;

    data = func_80100094(arg0, 2);
    text = _gldbstring_entrypoint_0(NULL, 0x186C);
    index = arg0->unk74_7 - 0x32;
    if (index != 3) {
        if (index == 0xC) {
            func_800E715C(data, _gldbstring_entrypoint_1(text, 0));
            func_800E715C(data + 0x40, _gldbstring_entrypoint_1(text, 1));
        }
    } else {
        func_800E715C(data, _gldbstring_entrypoint_1(text, 2));
        func_800E715C(data + 0x40, _gldbstring_entrypoint_1(text, 4));
        func_800E715C(data + 0x80, _gldbstring_entrypoint_1(text, 5));
    }
    _gldbstring_entrypoint_2(0x186C);
}

void func_80800484_chintrochar(Actor *arg0) {
    s32 func_800DA544(s32);
    s32 func_80103140(Actor *, u32, u16);
    void func_80800000_chintrochar(Actor *);
    s32 func_808000FC_chintrochar();
    void func_80800398_chintrochar(Actor *);
    void func_80803E98_chintrochar(Actor *);
    extern u16 D_80804790_chintrochar[][16];
    extern u32 func_80804160_chintrochar[][8];
    s32 temp_s1;
    u16 *temp_v0;

    temp_s1 = func_80804160_chintrochar[arg0->unk74_7][0];
#ifdef BT_NATIVE
    ((s32 (*)())func_808000FC_chintrochar)();
#else
    func_808000FC_chintrochar();
#endif
    temp_v0 = D_80804790_chintrochar[arg0->unk74_7];
    func_80103140(arg0, temp_v0[-0x320], temp_v0[-0x31F]);
    if (temp_s1 & 0x40) {
        func_80800000_chintrochar(arg0);
    }
    if (temp_s1 & 0x1000) {
        func_80800398_chintrochar(arg0);
    }
    if (temp_s1 & 0x10000) {
        func_80803E98_chintrochar(arg0);
    }
    if (temp_s1 & 0x80000) {
        func_800DA544(0xD);
    }
}

void func_80800540_chintrochar(Actor *arg0) {
    s16 _anseq_entrypoint_6(void);
    void _chanim_entrypoint_7(Actor *, s16);
    s16 _chblink_entrypoint_1(s32);
    u32 *func_80100074(Actor *, u32, u32);
    void *func_80100094(Actor *, u32);
    void func_80105BE0(Actor *, s32);
    void func_80108B04(Actor *, u32);
    extern u16 D_80804790_chintrochar[][16];
    s16 *data;
    u32 flags;
    u16 *config;
    s32 index;

    arg0->unk64_19 = 1;
    index = arg0->unk74_7;
    config = D_80804790_chintrochar[index];
    flags = *(u32 *)&config[-0x318];
    _chanim_entrypoint_7(arg0, (s16)config[-0x31E]);
    func_80100074(arg0, 2, 0x10C);
    data = func_80100094(arg0, 2);
    data[0x60] = _anseq_entrypoint_6();
    *(s32 *)&data[0x64] = 0;
    func_80800484_chintrochar(arg0);
    func_80105BE0(arg0, 1);
    if (flags & 1) {
        data[0x61] = _chblink_entrypoint_1(0);
    } else {
        data[0x61] = 0;
    }
    if (flags & 0x400) {
        data[0x62] = _chblink_entrypoint_1(1);
    } else if (flags & 0x4000) {
        data[0x62] = _chblink_entrypoint_1(2);
    } else {
        data[0x62] = 0;
    }
    func_80108B04(arg0, 0);
}

void func_80800648_chintrochar(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    void _anseq_entrypoint_5(s32);
    void _chanim_entrypoint_6(Actor *);
    s32 _chblink_entrypoint_3(s16);
    void func_8001B754(s16);
    void func_800ADFE0(s16);
    extern u32 func_80804158_chintrochar[][8];
    s16 *data;
    s16 handle;
    u32 flags;

    data = func_80100094(arg0, 2);
    flags = func_80804158_chintrochar[arg0->unk74_7][0] & 0x3FFFFFFF;
    if (flags & 0x20) {
        handle = *(s16 *)&arg0->unk0->unk10;
        if (handle != 0) {
            func_800ADFE0(handle);
            *(s16 *)&arg0->unk0->unk10 = 0;
        }
    }
    _chanim_entrypoint_6(arg0);
    handle = data[0x60];
    if (handle != 0) {
        _anseq_entrypoint_5(handle);
    }
    handle = data[0x61];
    if (handle != 0) {
        _chblink_entrypoint_3(handle);
    }
    handle = data[0x62];
    if (handle != 0) {
        _chblink_entrypoint_3(handle);
    }
    handle = data[0x63];
    if (handle != 0) {
        func_8001B754(handle);
    }
}

void func_8080071C_chintrochar(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    s16 *_anseq_entrypoint_9(s16);
    void _anseq_entrypoint_0(s16 *);
    void _anseq_entrypoint_2(s16 *, f32, void *, s32, s32);
    void _anseq_entrypoint_3(s16 *, f32, void *, s32, s32, s32);
    void _anseq_entrypoint_7(s16 *, s32);
    void _inantab_entrypoint_2();
    void _indrv_audio_entrypoint_0();
    extern f32 D_80805270_chintrochar[3];
    extern f32 D_8080527C_chintrochar[3];
    extern f32 D_80805288_chintrochar[7];
    extern f32 D_808052A4_chintrochar[2];
    extern f32 D_808052AC_chintrochar[2];
    extern f32 D_808052B4_chintrochar[3];
    extern f32 D_808052C0_chintrochar[6];
    extern f32 D_808052D8_chintrochar[4];
    extern f32 D_808052E8_chintrochar[4];

    void *intro_data;
    s16 *sequence;
    /* Callbacks reload this addressable 32-bit marker from the stack. */
    s32 marker;

    intro_data = func_80100094(arg0, 2);
    sequence = _anseq_entrypoint_9(*(s16 *)((u8 *)intro_data + 0xC0));
    marker = (s32)arg0->unk0;
    _anseq_entrypoint_0(sequence);
    /* Empty cases preserve the original IDO jump-table partitioning. */
    switch (arg1) {
    case 0x39D:
    case 0x39E:
    case 0x39F:
    case 0x3A0:
    case 0x3A1:
    case 0x3A2:
    case 0x3A3:
    case 0x3A4:
    case 0x3A5:
    case 0x3A6:
    case 0x3A7:
    case 0x3A8:
    case 0x3A9:
    case 0x3AA:
    case 0x409:
    case 0x40A:
    case 0x40B:
    case 0x40E:
    case 0x412:
    case 0x413:
    case 0x416:
    case 0x419:
    case 0x41B:
    case 0x41D:
    case 0x41F:
    case 0x423:
    case 0x424:
    case 0x448:
    case 0x449:
    case 0x44A:
    case 0x44B:
    case 0x44D:
    case 0x44E:
    case 0x452:
    case 0x453:
    case 0x454:
    case 0x456:
    case 0x458:
    case 0x459:
    case 0x45D:
    case 0x461:
    case 0x464:
    case 0x469:
    case 0x46D:
    case 0x46F:
    case 0x471:
    case 0x472:
    case 0x473:
    case 0x475:
    case 0x476:
    case 0x477:
    case 0x478:
    case 0x479:
    case 0x47A:
    case 0x47B:
    case 0x47C:
    case 0x47D:
    case 0x47E:
    case 0x47F:
    case 0x480:
    case 0x481:
    case 0x482:
    case 0x483:
    case 0x484:
    case 0x485:
    case 0x486:
    case 0x487:
    case 0x488:
    case 0x489:
    case 0x48A:
    case 0x48B:
    case 0x48D:
    case 0x48E:
    case 0x48F:
    case 0x490:
    case 0x491:
    case 0x493:
    case 0x494:
    case 0x495:
    case 0x496:
    case 0x497:
    case 0x498:
    case 0x499:
    case 0x49A:
    case 0x49B:
    case 0x49C:
    case 0x49D:
    case 0x49E:
    case 0x49F:
    case 0x4A0:
    case 0x4A1:
    case 0x4A2:
    case 0x4A3:
    case 0x4A4:
    case 0x4A5:
    case 0x4A6:
    case 0x4A7:
    case 0x4A8:
    case 0x4A9:
    case 0x4AA:
    case 0x4AB:
    case 0x4AC:
    case 0x4AD:
    case 0x4AE:
    case 0x4AF:
    case 0x4DD:
    case 0x4DE:
    case 0x4DF:
    case 0x4E0:
    case 0x4E1:
    case 0x4E2:
    case 0x4E3:
    case 0x4E4:
    case 0x4E5:
    case 0x4E6:
    case 0x4E7:
    case 0x4E8:
    case 0x4E9:
    case 0x4EA:
    case 0x4EB:
    case 0x4EE:
    case 0x4EF:
    case 0x4F0:
    case 0x4F3:
    case 0x4F5:
    case 0x4F6:
    case 0x4F7:
    case 0x4F8:
    case 0x4F9:
    case 0x4FA:
    case 0x4FB:
    case 0x4FD:
    case 0x4FF:
    case 0x503:
    case 0x504:
    case 0x505:
    case 0x506:
    case 0x507:
    case 0x508:
    case 0x509:
    case 0x50B:
    case 0x50C:
    case 0x50D:
    case 0x50F:
    case 0x510:
    case 0x514:
    case 0x515:
    case 0x516:
    case 0x517:
    case 0x518:
    case 0x51A:
    case 0x51B:
    case 0x51C:
    case 0x51D:
    case 0x51E:
    case 0x520:
    case 0x522:
    case 0x524:
    case 0x525:
    case 0x526:
    case 0x527:
    case 0x528:
    case 0x529:
    case 0x52A:
    case 0x52B:
    case 0x52C:
    case 0x52D:
    case 0x52E:
    case 0x52F:
    case 0x530:
    case 0x531:
    case 0x532:
    case 0x534:
    case 0x537:
    case 0x539:
    case 0x53A:
    case 0x53C:
    case 0x53D:
    case 0x53E:
    case 0x53F:

    case 0xB3:
    case 0x1E7:
    case 0x408:
    case 0x445:
    case 0x4DB:
        break;
    /* Keep each table loop on one line to preserve IDO scheduling. */
    case 0x39B:
        { s32 i; for (i = 0; i < ARRLEN(D_80805270_chintrochar); i++) { _anseq_entrypoint_2(sequence, D_80805270_chintrochar[i], _inantab_entrypoint_2, *(s32 *)&marker, 0); } }
        { s32 i; for (i = 0; i < ARRLEN(D_8080527C_chintrochar); i++) { _anseq_entrypoint_2(sequence, D_8080527C_chintrochar[i], _inantab_entrypoint_2, *(s32 *)&marker, 1); } }
        break;
    case 0x39C:
        _anseq_entrypoint_3(sequence, 0.2942f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 6, -1);
        _anseq_entrypoint_3(sequence, 0.9053f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 7, -1);
        break;
    case 0x264:
        _anseq_entrypoint_2(sequence, 0.0295f, _inantab_entrypoint_2, *(s32 *)&marker, 0);
        _anseq_entrypoint_2(sequence, 0.5199f, _inantab_entrypoint_2, *(s32 *)&marker, 1);
        break;
    case 0x44C:
        _anseq_entrypoint_3(sequence, 0.5425f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0xA, -1);
        _anseq_entrypoint_3(sequence, 0.6254f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0xA, -1);
        break;
    case 0x455:
        _anseq_entrypoint_3(sequence, 0.1078f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0xB, -1);
        _anseq_entrypoint_3(sequence, 0.2643f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0xC, -1);
        _anseq_entrypoint_3(sequence, 0.294f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0xD, -1);
        break;
    case 0x4F2:
        _anseq_entrypoint_3(sequence, 0.0957f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x88, -1);
        _anseq_entrypoint_3(sequence, 0.1513f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x88, -1);
        _anseq_entrypoint_3(sequence, 0.2234f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x88, -1);
        _anseq_entrypoint_3(sequence, 0.3048f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x89, -1);
        _anseq_entrypoint_3(sequence, 0.3715f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x89, -1);
        break;
    case 0x4F4:
        _anseq_entrypoint_3(sequence, 0.1268f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x8A, -1);
        _anseq_entrypoint_3(sequence, 0.855f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x8B, -1);
        _anseq_entrypoint_3(sequence, 0.9178f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x8C, -1);
        break;
    case 0x422:
        _anseq_entrypoint_3(sequence, 0.8051f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x77, -1);
        break;
    case 0x474:
        { s32 i; for (i = 0; i < ARRLEN(D_80805288_chintrochar); i++) { _anseq_entrypoint_3(sequence, D_80805288_chintrochar[i], _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x64, -1); } }
        break;
    case 0x40C:
        _anseq_entrypoint_3(sequence, 0.5316f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0xE, -1);
        _anseq_entrypoint_3(sequence, 0.02f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0xF, -1);
        break;
    case 0x40D:
        { s32 i; for (i = 0; i < ARRLEN(D_808052A4_chintrochar); i++) { _anseq_entrypoint_3(sequence, D_808052A4_chintrochar[i], _indrv_audio_entrypoint_0, *(s32 *)&marker, 0xE, -1); } }
        { s32 i; for (i = 0; i < ARRLEN(D_808052AC_chintrochar); i++) { _anseq_entrypoint_3(sequence, D_808052AC_chintrochar[i], _indrv_audio_entrypoint_0, *(s32 *)&marker, 0xF, -1); } }
        _anseq_entrypoint_3(sequence, 0.17f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x10, -1);
        break;
    case 0x463:
        _anseq_entrypoint_3(sequence, 0.5708f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x11, -1);
        break;
    case 0x466:
        _anseq_entrypoint_3(sequence, 0.1f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x13, -1);
        _anseq_entrypoint_3(sequence, 0.536f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0xB0, -1);
        _anseq_entrypoint_3(sequence, 0.5727f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0xB1, -1);
        _anseq_entrypoint_3(sequence, 0.6092f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0xB2, -1);
        break;
    case 0x48C:
        _anseq_entrypoint_3(sequence, 0.01f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x78, -1);
        _anseq_entrypoint_3(sequence, 0.58f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x67, -2);
        _anseq_entrypoint_3(sequence, 0.7f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0xB0, -2);
        _anseq_entrypoint_3(sequence, 0.73f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0xB1, -2);
        _anseq_entrypoint_3(sequence, 0.76f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0xB2, -2);
        break;
    case 0x521:
        _anseq_entrypoint_3(sequence, 0.2218f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0xAE, -1);
        _anseq_entrypoint_3(sequence, 0.3564f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x7D, -1);
        _anseq_entrypoint_3(sequence, 0.4507f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0xAF, -1);
        _anseq_entrypoint_3(sequence, 0.7054f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x7E, -1);
        break;
    case 0x536:
        _anseq_entrypoint_3(sequence, 0.0469f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x9F, -1);
        _anseq_entrypoint_3(sequence, 0.1034f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0xA0, -1);
        _anseq_entrypoint_3(sequence, 0.1074f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x9C, -1);
        _anseq_entrypoint_3(sequence, 0.2039f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0xA0, -1);
        _anseq_entrypoint_3(sequence, 0.2079f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x9D, -1);
        _anseq_entrypoint_3(sequence, 0.3116f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0xA0, -1);
        _anseq_entrypoint_3(sequence, 0.3156f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x9E, -1);
        _anseq_entrypoint_3(sequence, 0.441f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0xA1, -1);
        _anseq_entrypoint_3(sequence, 0.445f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x9C, -1);
        _anseq_entrypoint_3(sequence, 0.6096f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0xA1, -1);
        _anseq_entrypoint_3(sequence, 0.6136f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x9D, -1);
        _anseq_entrypoint_3(sequence, 0.7606f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0xA1, -1);
        _anseq_entrypoint_3(sequence, 0.7646f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x9E, -1);
        _anseq_entrypoint_3(sequence, 0.9055f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0xA2, -1);
        _anseq_entrypoint_3(sequence, 0.9095f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x83, -1);
        break;
    case 0xB4:
        _anseq_entrypoint_2(sequence, 0.2262f, _inantab_entrypoint_2, *(s32 *)&marker, 0);
        _anseq_entrypoint_2(sequence, 0.7165f, _inantab_entrypoint_2, *(s32 *)&marker, 1);
        break;
    case 0x462:
        _anseq_entrypoint_2(sequence, 0.2262f, _inantab_entrypoint_2, *(s32 *)&marker, 0);
        _anseq_entrypoint_2(sequence, 0.7165f, _inantab_entrypoint_2, *(s32 *)&marker, 1);
        break;
    case 0x465:
        { s32 i; for (i = 0; i < ARRLEN(D_808052B4_chintrochar); i++) { _anseq_entrypoint_3(sequence, D_808052B4_chintrochar[i], _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x17, -1); } }
        break;
    case 0x467:
        _anseq_entrypoint_3(sequence, 0.0423f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x18, -1);
        _anseq_entrypoint_3(sequence, 0.174f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x19, -1);
        _anseq_entrypoint_3(sequence, 0.2292f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x19, -1);
        break;
    case 0x468:
        _anseq_entrypoint_3(sequence, 0.6787f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x1A, -1);
        _anseq_entrypoint_3(sequence, 0.9612f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x1B, -1);
        _anseq_entrypoint_3(sequence, 0.9668f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x19, -1);
        _anseq_entrypoint_3(sequence, 0.98f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x1C, -1);
        break;
    case 0x46A:
        _anseq_entrypoint_3(sequence, 0.109f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x1D, -1);
        _anseq_entrypoint_3(sequence, 0.2597f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x19, -1);
        _anseq_entrypoint_3(sequence, 0.22806f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x19, -1);
        break;
    case 0x470:
        _anseq_entrypoint_3(sequence, 0.4592f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x1E, -1);
        break;
    case 0x51F:
        _anseq_entrypoint_3(sequence, 0.0588f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x90, -1);
        _anseq_entrypoint_3(sequence, 0.063f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x9C, -1);
        _anseq_entrypoint_3(sequence, 0.2207f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x90, -1);
        _anseq_entrypoint_3(sequence, 0.226f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x9E, -1);
        _anseq_entrypoint_3(sequence, 0.3848f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x90, -1);
        _anseq_entrypoint_3(sequence, 0.389f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x9D, -1);
        _anseq_entrypoint_3(sequence, 0.5445f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x90, -1);
        _anseq_entrypoint_3(sequence, 0.5495f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x9C, -1);
        _anseq_entrypoint_3(sequence, 0.7007f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x90, -1);
        _anseq_entrypoint_3(sequence, 0.7059f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x9D, -1);
        _anseq_entrypoint_3(sequence, 0.8867f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x91, -1);
        _anseq_entrypoint_3(sequence, 0.8907f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x83, -1);
        break;
    case 0x46B:
        { s32 i; for (i = 0; i < ARRLEN(D_808052C0_chintrochar); i++) { _anseq_entrypoint_3(sequence, D_808052C0_chintrochar[i], _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x1F, -1); } }
        break;
    case 0x46C:
        _anseq_entrypoint_3(sequence, 0.0384f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x20, -1);
        break;
    case 0x46E:
        _anseq_entrypoint_3(sequence, 0.8038f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x21, -1);
        break;
    case 0x513:
        _anseq_entrypoint_3(sequence, 0.2147f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x93, -1);
        _anseq_entrypoint_3(sequence, 0.8433f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x94, -1);
        break;
    case 0x519:
        _anseq_entrypoint_3(sequence, 0.7f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0xA6, -1);
        _anseq_entrypoint_3(sequence, 0.9152f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x97, -1);
        _anseq_entrypoint_3(sequence, 0.9152f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0xAA, -1);
        break;
    case 0x511:
        _anseq_entrypoint_3(sequence, 0.6686f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x98, -1);
        break;
    case 0x512:
        _anseq_entrypoint_3(sequence, 0.8164f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x99, -1);
        _anseq_entrypoint_3(sequence, 0.9059f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x99, -1);
        _anseq_entrypoint_3(sequence, 0.9972f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x99, -1);
        _anseq_entrypoint_3(sequence, 0.1483f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x99, -1);
        _anseq_entrypoint_3(sequence, 0.2543f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x99, -1);
        break;
    case 0x4B0:
        _anseq_entrypoint_2(sequence, 0.0556f, _inantab_entrypoint_2, *(s32 *)&marker, 0);
        _anseq_entrypoint_2(sequence, 0.5594f, _inantab_entrypoint_2, *(s32 *)&marker, 1);
        break;
    case 0x3AB:
        _anseq_entrypoint_3(sequence, 0.1312f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x22, -1);
        _anseq_entrypoint_3(sequence, 0.1602f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x22, -1);
        _anseq_entrypoint_3(sequence, 0.2172f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x22, -1);
        _anseq_entrypoint_3(sequence, 0.2306f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x5B, -1);
        _anseq_entrypoint_3(sequence, 0.2512f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x22, -1);
        _anseq_entrypoint_3(sequence, 0.2578f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x22, -1);
        _anseq_entrypoint_3(sequence, 0.2725f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x5B, -1);
        _anseq_entrypoint_3(sequence, 0.2827f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x22, -1);
        _anseq_entrypoint_3(sequence, 0.2913f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x22, -1);
        _anseq_entrypoint_3(sequence, 0.2948f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x22, -1);
        _anseq_entrypoint_3(sequence, 0.3109f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x5B, -1);
        _anseq_entrypoint_3(sequence, 0.3176f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x22, -1);
        _anseq_entrypoint_3(sequence, 0.3433f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x22, -1);
        _anseq_entrypoint_3(sequence, 0.3539f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x22, -1);
        _anseq_entrypoint_3(sequence, 0.378f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x5B, -1);
        _anseq_entrypoint_3(sequence, 0.4003f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x22, -1);
        _anseq_entrypoint_3(sequence, 0.4154f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x22, -1);
        break;
    case 0x410:
        _anseq_entrypoint_3(sequence, 0.2456f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x22, -1);
        _anseq_entrypoint_3(sequence, 0.2613f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x22, -1);
        _anseq_entrypoint_3(sequence, 0.2664f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x22, -1);
        _anseq_entrypoint_3(sequence, 0.2777f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x5B, -1);
        _anseq_entrypoint_3(sequence, 0.2883f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x22, -1);
        _anseq_entrypoint_3(sequence, 0.2965f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x22, -1);
        _anseq_entrypoint_3(sequence, 0.3141f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x5B, -1);
        _anseq_entrypoint_3(sequence, 0.348f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x22, -1);
        _anseq_entrypoint_3(sequence, 0.3668f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x5B, -1);
        _anseq_entrypoint_3(sequence, 0.3908f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x22, -1);
        _anseq_entrypoint_3(sequence, 0.4052f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x22, -1);
        break;
    case 0x40F:
        _anseq_entrypoint_3(sequence, 0.6331f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x27, -1);
        _anseq_entrypoint_3(sequence, 0.6818f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x27, -1);
        _anseq_entrypoint_3(sequence, 0.7217f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x27, -1);
        _anseq_entrypoint_3(sequence, 0.7217f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x27, -1);
        break;
    case 0x411:
        _anseq_entrypoint_3(sequence, 0.6963f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x29, -1);
        _anseq_entrypoint_3(sequence, 0.99f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x2B, -1);
        break;
    case 0x447:
        _anseq_entrypoint_3(sequence, 0.0f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x2C, -1);
        _anseq_entrypoint_3(sequence, 0.35f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x2D, -1);
        _anseq_entrypoint_3(sequence, 0.4363f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x2E, -1);
        _anseq_entrypoint_3(sequence, 0.7912f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x30, -1);
        break;
    case 0x414:
        _anseq_entrypoint_2(sequence, 0.6171f, _inantab_entrypoint_2, *(s32 *)&marker, 0);
        _anseq_entrypoint_2(sequence, 0.0604f, _inantab_entrypoint_2, *(s32 *)&marker, 1);
        break;
    case 0x415:
        _anseq_entrypoint_2(sequence, 0.6171f, _inantab_entrypoint_2, *(s32 *)&marker, 0);
        _anseq_entrypoint_2(sequence, 0.0604f, _inantab_entrypoint_2, *(s32 *)&marker, 1);
        break;
    case 0x417:
        _anseq_entrypoint_3(sequence, 0.2363f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x35, -1);
        _anseq_entrypoint_3(sequence, 0.2363f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x5C, -1);
        break;
    case 0x418:
        _anseq_entrypoint_3(sequence, 0.7346f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x36, -1);
        break;
    case 0x41C:
        _anseq_entrypoint_3(sequence, 0.65f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x37, -1);
        break;
    case 0x421:
        _anseq_entrypoint_3(sequence, 0.0f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x38, -1);
        break;
    case 0x425:
        _anseq_entrypoint_3(sequence, 0.0976f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x39, -1);
        break;
    case 0x457:
        _anseq_entrypoint_3(sequence, 0.5518f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x3A, -1);
        _anseq_entrypoint_3(sequence, 0.6288f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x3A, -1);
        _anseq_entrypoint_3(sequence, 0.7087f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x3A, -1);
        _anseq_entrypoint_3(sequence, 0.9147f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x3C, -1);
        break;
    case 0x45A:
        _anseq_entrypoint_3(sequence, 0.3607f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x3B, -1);
        _anseq_entrypoint_3(sequence, 0.6853f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x3D, -1);
        _anseq_entrypoint_3(sequence, 0.7503f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x3D, -1);
        _anseq_entrypoint_3(sequence, 0.805f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x3D, -1);
        break;
    case 0x45E:
        _anseq_entrypoint_3(sequence, 0.3607f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x3B, -1);
        _anseq_entrypoint_3(sequence, 0.6853f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x3D, -1);
        _anseq_entrypoint_3(sequence, 0.7503f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x3D, -1);
        _anseq_entrypoint_3(sequence, 0.805f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x3D, -1);
        break;
    case 0x50E:
        _anseq_entrypoint_3(sequence, 0.3607f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x3B, -1);
        _anseq_entrypoint_3(sequence, 0.6853f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x3D, -1);
        _anseq_entrypoint_3(sequence, 0.7503f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x3D, -1);
        _anseq_entrypoint_3(sequence, 0.805f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x3D, -1);
        break;
    case 0x4F1:
        _anseq_entrypoint_3(sequence, 0.2404f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x82, -1);
        break;
    case 0x41A:
        _anseq_entrypoint_2(sequence, 0.4917f, _inantab_entrypoint_2, *(s32 *)&marker, 0);
        _anseq_entrypoint_2(sequence, 0.9823f, _inantab_entrypoint_2, *(s32 *)&marker, 1);
        break;
    case 0x41E:
        _anseq_entrypoint_3(sequence, 0.0435f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x40, -1);
        _anseq_entrypoint_3(sequence, 0.3748f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x41, -1);
        break;
    case 0x420:
        _anseq_entrypoint_3(sequence, 0.1112f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x42, -1);
        break;
    case 0x45B:
        _anseq_entrypoint_3(sequence, 0.0f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x45, -1);
        break;
    case 0x45C:
        _anseq_entrypoint_3(sequence, 0.3423f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x46, -1);
        _anseq_entrypoint_3(sequence, 0.6316f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x47, -1);
        _anseq_entrypoint_3(sequence, 0.9195f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x47, -1);
        break;
    case 0x501:
        _anseq_entrypoint_7(sequence, 1);
        _anseq_entrypoint_3(sequence, 0.7473f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x80, -1);
        break;
    case 0x446:
        _anseq_entrypoint_3(sequence, 0.3201f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x48, -1);
        _anseq_entrypoint_3(sequence, 0.661f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x48, -1);
        break;
    case 0x44F:
        _anseq_entrypoint_2(sequence, 0.0f, _inantab_entrypoint_2, *(s32 *)&marker, 0);
        _anseq_entrypoint_2(sequence, 0.5f, _inantab_entrypoint_2, *(s32 *)&marker, 1);
        break;
    case 0x450:
        _anseq_entrypoint_3(sequence, 0.7324f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x4C, -1);
        { s32 i; for (i = 0; i < ARRLEN(D_808052D8_chintrochar); i++) { _anseq_entrypoint_2(sequence, D_808052D8_chintrochar[i], _inantab_entrypoint_2, *(s32 *)&marker, 0); } }
        { s32 i; for (i = 0; i < ARRLEN(D_808052E8_chintrochar); i++) { _anseq_entrypoint_2(sequence, D_808052E8_chintrochar[i], _inantab_entrypoint_2, *(s32 *)&marker, 1); } }
        break;
    case 0x451:
        _anseq_entrypoint_3(sequence, 0.0352f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x4D, -1);
        _anseq_entrypoint_3(sequence, 0.0623f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x4E, -1);
        _anseq_entrypoint_3(sequence, 0.0623f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x4F, -1);
        _anseq_entrypoint_3(sequence, 0.4408f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x52, -1);
        break;
    case 0x492:
        _anseq_entrypoint_3(sequence, 0.6206f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x53, -1);
        _anseq_entrypoint_3(sequence, 0.6861f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x53, -1);
        _anseq_entrypoint_3(sequence, 0.7631f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x53, -1);
        _anseq_entrypoint_3(sequence, 0.9322f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x55, -1);
        break;
    case 0x4FC:
        _anseq_entrypoint_3(sequence, 0.3064f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x79, -1);
        break;
    case 0x4FE:
        _anseq_entrypoint_3(sequence, 0.2319f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x7A, -1);
        break;
    case 0x500:
        _anseq_entrypoint_7(sequence, 1);
        _anseq_entrypoint_3(sequence, 0.3456f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x7B, -1);
        break;
    case 0x190:
        _anseq_entrypoint_3(sequence, 0.55f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x66, -1);
        break;
    case 0x1E6:
        _anseq_entrypoint_2(sequence, 0.0f, _inantab_entrypoint_2, *(s32 *)&marker, 0);
        _anseq_entrypoint_2(sequence, 0.5f, _inantab_entrypoint_2, *(s32 *)&marker, 1);
        break;
    case 0x1E9:
        _anseq_entrypoint_3(sequence, 0.1f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x65, -1);
        break;
    case 0x45F:
        _anseq_entrypoint_2(sequence, 0.401f, _inantab_entrypoint_2, *(s32 *)&marker, 0);
        _anseq_entrypoint_2(sequence, 0.8978f, _inantab_entrypoint_2, *(s32 *)&marker, 1);
        break;
    case 0x460:
        _anseq_entrypoint_3(sequence, 0.7838f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x59, -1);
        _anseq_entrypoint_3(sequence, 0.8626f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x5A, -1);
        break;
    case 0x538:
        _anseq_entrypoint_3(sequence, 0.0567f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0xA7, -1);
        _anseq_entrypoint_3(sequence, 0.0567f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x9D, -1);
        _anseq_entrypoint_3(sequence, 0.2458f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0xA8, -1);
        _anseq_entrypoint_3(sequence, 0.2458f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0xA0, -1);
        _anseq_entrypoint_3(sequence, 0.2458f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x9C, -1);
        _anseq_entrypoint_3(sequence, 0.3446f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0xA8, -1);
        _anseq_entrypoint_3(sequence, 0.3446f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x9E, -1);
        _anseq_entrypoint_3(sequence, 0.3446f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0xA0, -1);
        _anseq_entrypoint_3(sequence, 0.4654f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0xA8, -1);
        _anseq_entrypoint_3(sequence, 0.4654f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x9C, -1);
        _anseq_entrypoint_3(sequence, 0.4654f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0xA0, -1);
        _anseq_entrypoint_3(sequence, 0.5848f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0xA8, -1);
        _anseq_entrypoint_3(sequence, 0.5848f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x9D, -1);
        _anseq_entrypoint_3(sequence, 0.5848f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0xA0, -1);
        _anseq_entrypoint_3(sequence, 0.6758f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0xA8, -1);
        _anseq_entrypoint_3(sequence, 0.6758f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x9E, -1);
        _anseq_entrypoint_3(sequence, 0.6758f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0xA0, -1);
        _anseq_entrypoint_3(sequence, 0.8244f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0xA9, -1);
        _anseq_entrypoint_3(sequence, 0.8244f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x9C, -1);
        _anseq_entrypoint_3(sequence, 0.8244f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0xA2, -1);
        break;
    case 0x523:
        _anseq_entrypoint_3(sequence, 0.5449f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x78, -1);
        break;
    case 0x4DC:
        _anseq_entrypoint_3(sequence, 0.01f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0xA2, -1);
        _anseq_entrypoint_3(sequence, 0.31f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x83, -2);
        break;
    case 0x4EC:
        _anseq_entrypoint_3(sequence, 0.0459f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x84, -1);
        _anseq_entrypoint_3(sequence, 0.8119f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x85, -1);
        _anseq_entrypoint_3(sequence, 0.8661f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x85, -1);
        break;
    case 0x4ED:
        _anseq_entrypoint_3(sequence, 0.7114f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x86, -1);
        break;
    case 0x502:
        _anseq_entrypoint_3(sequence, 0.2169f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x8D, -1);
        _anseq_entrypoint_3(sequence, 0.5548f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x8F, -1);
        break;
    case 0x533:
        _anseq_entrypoint_3(sequence, 0.0621f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0xA3, -1);
        _anseq_entrypoint_3(sequence, 0.1569f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0xA4, -1);
        _anseq_entrypoint_3(sequence, 0.5547f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0xA4, -1);
        _anseq_entrypoint_3(sequence, 0.91f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0xA5, -4);
        _anseq_entrypoint_3(sequence, 0.91f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0xAB, -4);
        break;
    case 0x535:
        _anseq_entrypoint_3(sequence, 0.65f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0xA5, -1);
        _anseq_entrypoint_3(sequence, 0.65f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0xAB, -1);
        break;
    case 0x50A:
        _anseq_entrypoint_3(sequence, 0.1049f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x9B, -1);
        _anseq_entrypoint_3(sequence, 0.2766f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x9B, -1);
        _anseq_entrypoint_3(sequence, 0.4496f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0x9B, -1);
        break;
    case 0x53B:
        _anseq_entrypoint_3(sequence, 0.1744f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0xAC, -1);
        _anseq_entrypoint_3(sequence, 0.6107f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0xAC, -1);
        break;
    case 0x540:
        _anseq_entrypoint_3(sequence, 0.66f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0xB3, -1);
        break;
    case 0x541:
        _anseq_entrypoint_3(sequence, 0.1273f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0xB4, -1);
        _anseq_entrypoint_3(sequence, 0.2008f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0xB4, -1);
        _anseq_entrypoint_3(sequence, 0.2438f, _indrv_audio_entrypoint_0, *(s32 *)&marker, 0xB4, -1);

        break;
    }
}

/* extern */

void func_80803388_chintrochar(Actor *volatile arg0, s32 *arg1) {
    void *func_800C6A7C(f32 [3], f32 [3], f32 [3], u32);
    s32 func_800C84B0(s32);
    void func_800EE7F8(f32 *, f32 *);
    f32 sp3C[3];
    f32 sp30[3];
    f32 sp24[3];
    f32 *position[2];
    s32 *temp_v0;

    position[0] = arg0->position;
    func_800EE7F8(sp30, position[0]);
    func_800EE7F8(sp3C, position[0]);
    sp30[1] -= 100.0f;
    sp3C[1] += 100.0f;
    temp_v0 = func_800C6A7C(sp3C, sp30, sp24, arg0->unk14);
    if (temp_v0 != NULL) {
        arg1[0x33] = func_800C84B0(temp_v0[2]);
    }
}

void func_80803418_chintrochar(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    s32 _fxstep_entrypoint_15(s32, s32, s32 *, s32 *, f32 *);
    void func_800C4B64(f32);
    void func_800C4B70(s32);
    void func_800C4B7C(s32);
    s32 func_8010D930(s32, s32, f32 *, s32 *);
    extern s32 D_808052F8_chintrochar;
    s32 *sp34;
    s32 sp30;
    f32 sp2C;
    s32 sp28;
    s32 var_a1;

    sp34 = func_80100094(arg0, 2);
    func_80803388_chintrochar(arg0, sp34);
    if (arg1 == 0) {
        var_a1 = 0;
    } else {
        var_a1 = 1;
    }
    if (_fxstep_entrypoint_15(sp34[0x33], var_a1, &sp30, &sp28, &sp2C) != 0) {
        func_800C4B64(sp2C);
        func_800C4B70(sp28);
        func_800C4B7C(sp30);
        var_a1 = arg0->unk70_0;
        func_8010D930(2, var_a1, arg0->position, &D_808052F8_chintrochar);
    }
}

void func_808034C4_chintrochar(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    s16 *_anseq_entrypoint_9(s16);
    void _anseq_entrypoint_8(s16 *, struct anctrl_s *);
    void func_8010588C(Actor *);
    void func_80803F7C_chintrochar(Actor *);
    void func_80803F24_chintrochar(Actor *, u8 *, s32);
    Actor *func_80106790(Unk80132ED0 *);
    s32 func_801022E4(Actor *);
    struct anctrl_s *func_80104248(void *);
    void _chblink_entrypoint_2(s16);
    void _chanim_entrypoint_9(Actor *);
    void _chanim_entrypoint_1(Unk80132ED0 *, s32, s32);
    s32 func_800DA298(s32);
    s32 func_8008FFE8();
    void func_8010FFB0(f32 **, f32 *, f32 *);
    void _suexpression_entrypoint_10(u32 *, Unk80132ED0 *, u32);
    void *func_8001B798(s16);
    s32 _subaddiefade_entrypoint_0(Actor *);
    s32 _chbadshad_entrypoint_1(Actor *, f32 *, f32);
    extern u32 func_80804160_chintrochar[][8];
    extern f32 func_8080416C_chintrochar[][8];
    struct IntroUpdateData {
        u8 pad[0xC0];
        s16 sequence;
        s16 blink1;
        s16 blink2;
        s16 expression;
        s32 state;
        u8 padCC[0x38];
        Unk80132ED0 *markers[2];
    };
    struct IntroUpdateData *data;
    s16 *sequence;
    s32 flags;
    s32 state;
    s32 i;
    f32 position[3];
    f32 rotation[3];
    f32 shadow;

    data = func_80100094(arg0, 2);
    sequence = _anseq_entrypoint_9(data->sequence);
    flags = func_80804160_chintrochar[arg0->unk74_7][0];
    func_8010588C(arg0);
    if (flags & 0x100) {
        arg0->rotation[0] = 0.0f;
    }
    if (flags & 0x10000) {
        func_80803F7C_chintrochar(arg0);
    }
    if (flags & 0x20000) {
        for (i = 0; i < 2; i++) {
            func_80803F24_chintrochar(arg0, func_80106790(data->markers[i]), i);
        }
    }
    state = func_801022E4(arg0);
    if (state != data->state) {
        data->state = state;
        func_8080071C_chintrochar(arg0, state);
    }
    _anseq_entrypoint_8(sequence, func_80104248(arg0));
    if (data->blink1 != 0) {
        _chblink_entrypoint_2(data->blink1);
    }
    if (data->blink2 != 0) {
        _chblink_entrypoint_2(data->blink2);
    }
    _chanim_entrypoint_9(arg0);
    if (flags & 0x80000) {
        _chanim_entrypoint_1(arg0->unk0, 0xD, func_800DA298(0xD));
    }
    if (flags & 0x40) {
        if (flags & 0x40000) {
            func_8010FFB0(func_8008FFE8(), position, rotation);
            _suexpression_entrypoint_10(func_80100094(arg0, 1), arg0->unk0, position);
        } else {
            _suexpression_entrypoint_10(func_80100094(arg0, 1), arg0->unk0, 0);
        }
    }
    if (data->expression != 0) {
        _suexpression_entrypoint_10(func_8001B798(data->expression), arg0->unk0, 0);
    }
    if (_subaddiefade_entrypoint_0(arg0) == 0) {
        arg0->unk64_16 = 0;
    } else {
        arg0->unk64_16 = arg0->unk64_19;
    }
    shadow = func_8080416C_chintrochar[arg0->unk74_7][0];
    if (shadow > 0.0f) {
        _chbadshad_entrypoint_1(arg0, arg0->position, shadow);
    }
}

void func_8080374C_chintrochar(Actor *arg0, s32 arg1) {
    void *func_80100094(Actor *, u32);
    void *func_8001B798(s16);
    void _suexpression_entrypoint_19(void *, Actor *);
    s32 func_8010262C(Unk80132ED0 *, u32);
    void func_800E0AFC(void *, u8, f32, f32, f32, f32);
    extern u32 func_80804160_chintrochar[][8];
    extern s16 D_80805308_chintrochar[];
    extern s16 D_8080530E_chintrochar[];
    extern s16 D_80805310_chintrochar[];
    extern s16 D_80805316_chintrochar[];
    s16 *data;
    f32 *values;
    s32 model;
    s16 *entry;
    s32 i;

    data = func_80100094(arg0, 2);
    if (data[0x63] != 0) {
        _suexpression_entrypoint_19(func_8001B798(data[0x63]), arg0);
    }
    if (func_80804160_chintrochar[arg0->unk74_7][0] & 0x10000) {
        model = func_8010262C(arg0->unk0, 6);
        if (model != 0) {
            values = func_80100094(arg0, 2);
            for (i = 0; i < 3; i++) {
                func_800E0AFC(model, D_80805308_chintrochar[i], -1.0f, values[0x34], 0.0f, 0.0f);
            }
            for (i = 0; i < 3; i++) {
                func_800E0AFC(model, D_80805310_chintrochar[i], -1.0f, values[0x35], 0.0f, 0.0f);
            }
        }
    }
}

void func_80803888_chintrochar(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    void func_80103D48(void **);
    s32 func_80103D70(void **);
    void _chanim_entrypoint_8(Actor *);
    void _chblink_entrypoint_4(s16);
    void _suexpression_entrypoint_11(void *, Actor *);
    void *func_8001B798(s16);
    s32 func_801015D0(Actor *);
    void func_800DF830(s32);
    extern u32 func_80804160_chintrochar[][8];
    s16 *data;
    u32 flags;
    s16 blink0;
    s16 blink1;
    s16 expression;

    data = func_80100094(arg0, 2);
    flags = func_80804160_chintrochar[arg0->unk74_7][0];
    func_80103D48(&arg0->unk0);
    _chanim_entrypoint_8(arg0);
    blink0 = data[0x61];
    if (blink0 != 0) {
        _chblink_entrypoint_4(blink0);
    }
    blink1 = data[0x62];
    if (blink1 != 0) {
        _chblink_entrypoint_4(blink1);
    }
    func_801015D0(arg0);
    expression = data[0x63];
    if (expression != 0) {
        _suexpression_entrypoint_11(func_8001B798(expression), arg0);
    }
    if (flags & 0x10) {
        func_800DF830(2);
    } else if (flags & 8) {
        func_800DF830(0);
    } else if (flags & 0x20) {
        func_800DF830(3);
    }
    func_80103D70(&arg0->unk0);
}

void func_80803990_chintrochar(Actor *arg0, Gfx **arg1) {
    void *func_80100094(Actor *, u32);
    s32 _subaddiefade_entrypoint_0(Actor *);
    void func_800B7F14(Gfx **);
    void func_800B811C(Gfx **);
    void func_800B8C50(void);
    void func_800B8C8C(s32);
    void func_800B8C98(s32);
    void func_800B8CB0(s32);
    void func_800B8F88(s32, s32, u8 *);
    u8 *data[1];
    u8 *text;

    data[0] = func_80100094(arg0, 2);
    func_800B8C50();
    func_800B8C8C(_subaddiefade_entrypoint_0(arg0));
    func_800B8C98(0);
    func_800B8CB0(1);
    func_800B7F14(arg1);
    switch (arg0->unk74_7 - 0x32) {
        case 0xC:
            func_800B8F88(arg1, 0xB6, text = data[0]);
            func_800B8F88(arg1, 0xC2, text + 0x40);
            break;
        case 3:
            text = data[0];
            func_800B8F88(arg1, 0xB6, text);
            func_800B8F88(arg1, 0xC2, text + 0x40);
            func_800B8F88(arg1, 0xCE, text + 0x80);
            break;
    }
    func_800B811C(arg1);
}

void func_80803A78_chintrochar(Actor *arg0, Gfx **arg1) {
    void *func_800DE448(f32 *, f32 *, f32, f32 *, u8 *);
    void *func_800DF944(void *, f32 *, f32, f32, f32 *, s32, void *);
    void func_800DF440(s32);
    void func_800DF464(f32);
    void func_800DF47C(s32, s32);
    void func_800DF4CC(s32);
    void func_800E39A8(f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF5A0(f32 *, f32 *, f32, f32, f32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_801017D0(Actor *);
    int func_80101970(Actor *);
    s32 func_8010347C(Unk80132ED0 *);
    u8 *func_801039E4(Unk80132ED0 *);
    extern u32 func_80804160_chintrochar[][8];
    extern f32 func_80804168_chintrochar[][8];
    struct IntroCoords { f32 values[2]; };
    extern struct IntroCoords D_80805318_chintrochar;
    u32 flags;
    f32 orientation[3];

    flags = func_80804160_chintrochar[arg0->unk74_7][0];
    if (flags & 2) {
        if (flags & 0x8000) {
            struct IntroCoords coords = D_80805318_chintrochar;
            switch (arg0->unk74_7 - 0x32) {
                case 3:
                case 4:
                    coords.values[1] -= 20.0f;
                    break;
            }
            if (!(flags & 4)) {
                if (arg0->rotation[1] != 0) {
                    func_800EFA4C(orientation, 0.0f, arg0->rotation[1], 0.0f);
                    func_800DF4CC(orientation);
                }
            }
            func_800DF47C(func_801017D0, arg0);
            func_800DF944(arg1, coords.values, 0.0f, arg0->scale * 0.35f, NULL, 1, func_8010347C(arg0->unk0));
        } else {
            f32 position[3];
            f32 rotation[3];
            f32 offset[3];
            func_800E39A8(position, rotation);
            func_800EF5A0(offset, rotation, 0, 0, -1000.0f);
            func_800EF04C(offset, position);
            func_800DF47C(func_801017D0, arg0);
            if (flags & 4) {
                func_800DE448(offset, rotation, arg0->scale, NULL, func_801039E4(arg0->unk0));
            } else {
                func_800DE448(offset, arg0->rotation, arg0->scale, NULL, func_801039E4(arg0->unk0));
            }
        }
    } else {
        struct IntroRenderFlags { u32 unused : 1; u32 flag : 1; };
        struct IntroRenderFlags *renderFlags = (void *)&arg0->pad94;
        if (renderFlags->flag) {
            func_800DF440(0);
        } else {
            func_80101970(arg0);
        }
        if (flags & 0x200) {
            func_800DF464(func_80804168_chintrochar[arg0->unk74_7][0]);
        }
        func_800DF47C(func_801017D0, arg0);
        func_800DE448(arg0->position, arg0->rotation, arg0->scale, NULL, func_801039E4(arg0->unk0));
    }
    if (flags & 0x1000) {
        func_80803990_chintrochar(arg0, arg1);
    }
}

s32 func_80803D0C_chintrochar(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    void func_80102FDC(void *, f32);
    void func_80103110(void *, s32);
    Actor *func_80108528(s32, f32 *, s32, Actor **);
    extern u32 func_80804160_chintrochar[][8];
    s32 i;
    u8 *data;
    Actor *child;
    u32 flags;
    s32 *message;

    message = &arg2;
    switch (arg1) {
        case 0x29:
            func_808002FC_chintrochar(arg0);
            break;
        case 0x9C:
            func_8080374C_chintrochar(arg0, *message);
            break;
        case 0x1F:
            func_80803888_chintrochar(arg0);
            break;
        case 0x5A:
            switch (arg2) {
                case 0:
                case 1:
                    func_80803418_chintrochar(arg0, *message);
                    break;
            }
            break;
        case 0x3D:
            flags = func_80804160_chintrochar[arg0->unk74_7][0];
            if (flags & 0x20000) {
                data = func_80100094(arg0, 2);
                for (i = 0; i < 2; i++) {
                    child = func_80108528(0x50A, arg0->position, 0xA, &arg0);
                    ((Unk80132ED0 **)(data + 0x104))[i] = child->unk0;
                    func_80103110(child, 1);
                    func_80102FDC(child, 1.5f);
                }
            }
            break;
        default:
            return 0;
    }
    return 1;
}

OSThread *chintrochar_entrypoint_0(void)
{
    extern u8 D_8080532C_chintrochar[];

    return (OSThread *) D_8080532C_chintrochar;
}

void func_80803E98_chintrochar(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    void func_800EE7F8(f32 *, f32 *);
    u8 *data;
    s32 i;

    data = func_80100094(arg0, 2);
    for (i = 0; i < 2; i++) {
        ((f32 *)(data + 0xD0))[i] = 0.0f;
    }
    func_800EE7F8((f32 *)(data + 0xF4), (f32 *)((u8 *)arg0 + 4));
    func_800EE7F8((f32 *)(data + 0xE4), (f32 *)((u8 *)arg0 + 4));
    *(f32 *)(data + 0x100) = *(f32 *)((u8 *)arg0 + 0x48);
    *(f32 *)(data + 0xF0) = *(f32 *)((u8 *)arg0 + 0x48);
}

void func_80803F24_chintrochar(Actor *arg0, u8 *arg1, s32 arg2) { void func_800DBEFC(s32 *, s32, f32 *); void func_80103014(u8 *); extern s32 D_80805374_chintrochar[]; if (arg0->unk7C_12) { func_800DBEFC(*(s32 **)((u8 *)arg0->unk0 + 4), D_80805374_chintrochar[arg2], (f32 *)(arg1 + 4)); } func_80103014(arg1); }

void func_80803F7C_chintrochar(Actor *arg0) {
    void func_800DBEFC(s32 *, s32, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800F1DF4(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    void func_80804054_chintrochar(Actor *, s32, f32, f32 *);
    void func_80804238_chintrochar(s32 *);
    extern f32 D_8080537C_chintrochar[];
    extern f32 D_80805388_chintrochar[];
    u8 *data;
    f32 sp28[3];

    data = func_80100094(arg0, 2);
    if (arg0->unk7C_12) {
        func_800DBEFC(*(s32 **)((u8 *)arg0->unk0 + 4), 7, (f32 *)(data + 0xE4));
        func_800DBEFC(*(s32 **)((u8 *)arg0->unk0 + 4), 8, sp28);
        *(f32 *)(data + 0xF0) = func_800F1DF4(sp28, (f32 *)(data + 0xF4));
    }
    func_80804054_chintrochar(arg0, 0, -1.0f, D_80805388_chintrochar);
    func_80804054_chintrochar(arg0, 1, 1.0f, D_8080537C_chintrochar);
    func_80804238_chintrochar((s32 *)arg0);
    func_800EE7F8((f32 *)(data + 0xF4), (f32 *)(data + 0xE4));
    *(f32 *)(data + 0x100) = *(f32 *)(data + 0xF0);
}

void func_80804054_chintrochar(Actor *actor, s32 index, f32 orientation, f32 *offset) {
    void *func_80100094(Actor *, u32);
    f32 func_800D8FF8(void);
    f32 func_800EEAD4(f32 *, f32 *);
    s32 func_800EECE0(f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF934(f32 *, f32 *, f32);
    f32 func_800F1DCC(f32, f32);
    u8 *data;
    f32 dt;
    f32 current[3];
    f32 previous[3];
    f32 distance;
    f32 direction;
    f32 phaseDelta;
    f32 angleDelta;
    s32 phase;

    data = func_80100094(actor, 2);
    dt = func_800D8FF8();
    func_800EF934(current, offset, *(f32 *)(data + 0xF0));
    func_800EF04C(current, (f32 *)(data + 0xE4));
    func_800EF934(previous, offset, *(f32 *)(data + 0x100));
    func_800EF04C(previous, (f32 *)(data + 0xF4));
    distance = func_800EEAD4(current, previous);
    if (func_800EECE0((f32 *)((u8 *)actor + 4), (f32 *)(data + 0xF4))) {
        direction = (func_800F1DCC(*(f32 *)(data + 0x100), *(f32 *)(data + 0xF0)) <= 0.0f ? 1.0f : -1.0f) * orientation;
    } else {
        direction = 1.0;
    }
    phaseDelta = distance * 12.0f * direction * 64.0f * dt;
    ((f32 *)(data + 0xD8))[index] += phaseDelta;
    phase = (s32)((f32 *)(data + 0xD8))[index];
    if (phase >= 0x2000) {
        ((f32 *)(data + 0xD8))[index] -= 8192.0f;
    } else if (phase < 0) {
        ((f32 *)(data + 0xD8))[index] += 8192.0f;
    }
    ((s16 *)(data + 0xE0))[index] = (s32)((f32 *)(data + 0xD8))[index];
    angleDelta = distance * 0.01333333366f * direction * 57.29578018f;
    ((f32 *)(data + 0xD0))[index] += angleDelta;
}

void func_80804238_chintrochar(s32 *arg0) {
    s32 _glid_entrypoint_0(s32, s32, s32 *, s32);
    s32 func_801065A4();
#ifdef BT_NATIVE
    void chintrochar_entrypoint_1(s32 arg0, Vtx *arg1, Vtx *arg2, s32 arg3, Unk80132ED0 *arg4);
#else
    s32 _chintrochar_entrypoint_1();
#endif
    s32 sp1C;
    sp1C = func_801065A4();
    if (sp1C != 0) {
        _glid_entrypoint_0(sp1C, 1, (s32 *)_chintrochar_entrypoint_1, *arg0);
        _glid_entrypoint_0(sp1C, 2, (s32 *)_chintrochar_entrypoint_1, *arg0);
    }
}

void chintrochar_entrypoint_1(s32 arg0, Vtx *arg1, Vtx *arg2, s32 arg3, Unk80132ED0 *arg4) {
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    s16 *data;
    s32 offset;
    Vtx *end;

    data = func_80100094(func_80106790(arg4), 2);
    switch (arg0) {
    case 1:
        offset = data[0x70];
        end = arg1 + arg3;
        while (arg1 < end) {
            arg2++;
            arg2[-1].v.tc[1] = (arg1++)->v.tc[1] + offset;
        }
        break;
    case 2:
        offset = data[0x71];
        end = arg1 + arg3;
        while (arg1 < end) {
            arg2++;
            arg2[-1].v.tc[1] = (arg1++)->v.tc[1] + offset;
        }
        break;
    }
}
