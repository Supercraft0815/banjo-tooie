#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/intro/char/func_80800000_chintrochar.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/intro/char/func_808000FC_chintrochar.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/intro/char/func_808002FC_chintrochar.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/intro/char/func_80800398_chintrochar.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/intro/char/func_80800484_chintrochar.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/intro/char/func_80800540_chintrochar.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/intro/char/func_80800648_chintrochar.s")

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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/intro/char/func_80803418_chintrochar.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/intro/char/func_808034C4_chintrochar.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/intro/char/func_8080374C_chintrochar.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/intro/char/func_80803888_chintrochar.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/intro/char/func_80803990_chintrochar.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/intro/char/func_80803A78_chintrochar.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/intro/char/func_80803D0C_chintrochar.s")

OSThread *chintrochar_entrypoint_0(void)
{
    extern u8 D_8080532C_chintrochar[];

    return (OSThread *) D_8080532C_chintrochar;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/intro/char/func_80803E98_chintrochar.s")

void func_80803F24_chintrochar(Actor *arg0, u8 *arg1, s32 arg2) { void func_800DBEFC(s32 *, s32, s32); void func_80103014(u8 *); extern s32 D_80805374_chintrochar[]; if (arg0->unk7C_12) { func_800DBEFC(*(s32 **)((u8 *)arg0->unk0 + 4), D_80805374_chintrochar[arg2], (s32)(arg1 + 4)); } func_80103014(arg1); }

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/intro/char/func_80803F7C_chintrochar.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/intro/char/func_80804054_chintrochar.s")

void func_80804238_chintrochar(s32 *arg0) {
    s32 _glid_entrypoint_0(s32, s32, s32 *, s32);
    s32 func_801065A4();
    s32 _chintrochar_entrypoint_1();
    s32 sp1C;
    sp1C = func_801065A4();
    if (sp1C != 0) {
        _glid_entrypoint_0(sp1C, 1, (s32 *)_chintrochar_entrypoint_1, *arg0);
        _glid_entrypoint_0(sp1C, 2, (s32 *)_chintrochar_entrypoint_1, *arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/intro/char/chintrochar_entrypoint_1.s")
