#include "common.h"

typedef struct { s16 unk0; s16 text; s8 ability; s8 unk5; u8 padding[2]; } TrainingLesson;

void func_80800000_chmole_training(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    void _gcnewoption_entrypoint_6(Actor *arg0, volatile s16 arg1);
    if (func_80100094(arg0, 0U) != NULL) {
        _gcnewoption_entrypoint_6(arg0, 0);
    }
}

void func_80800034_chmole_training(Actor *arg0, s32 arg1)
{
  void *func_80100094(Actor *, u32);
  void _gcnewoption_entrypoint_1(u8 *arg0, BtIntPtr arg1);
  u32 temp_t6;
  temp_t6 = (u16) (*((u16 *) (((s8 *) arg0) + 0x72)));
  temp_t6 = temp_t6 >> 0xA;
  if (((temp_t6 == 5) || (temp_t6 == 7)) || (temp_t6 == 6))
  {
    _gcnewoption_entrypoint_1(func_80100094(arg0, 0U), arg1);
  }
}

void func_80800088_chmole_training(Actor *arg0) {
    void _gcnewoption_entrypoint_0(void *arg0);
    void _gcnewoption_entrypoint_6(Actor *arg0, volatile s16 arg1);
    s32 _sumole_entrypoint_17(Actor* arg0, s16 message, s32 arg2, s32 arg3);
    void _sumole_entrypoint_19(void *, s32);
    int func_800C6E38(s32);
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    void func_80800270_chmole_training(Actor *);
    void func_808003D4_chmole_training(void *);
    void func_80800A48_chmole_training(Actor *);
    void func_80800BA8_chmole_training(Actor *);
    void func_80800C28_chmole_training(void *);
    void func_80800C3C_chmole_training(void *);
    extern TrainingLesson D_80800E30_chmole_training[27];

    s32 ability;

    if (arg0->unk3C != NULL) {
        switch (arg0->unk70_10) {
        case 1:
            func_80800270_chmole_training(arg0);
            return;
        case 2:
            func_808003D4_chmole_training(arg0);
            return;
        case 3:
            arg0->unk70_10 = 4;
            return;
        case 4:
            func_80800A48_chmole_training(arg0);
            return;
        case 5:
            _gcnewoption_entrypoint_0(func_80100094(arg0, 0));
            return;
        case 7:
            _gcnewoption_entrypoint_6(arg0, 0);
            ability = D_80800E30_chmole_training[(s32)arg0->unk54].ability;
            if (ability != -1 && !func_800C6E38(ability)) {
                func_80101FDC(arg0, 8);
                return;
            }
            func_80101FDC(arg0, 10);
            return;
        case 6:
            _gcnewoption_entrypoint_6(arg0, 0);
            func_80101FDC(arg0, 11);
            return;
        case 10:
            if (_sumole_entrypoint_17(arg0, D_80800E30_chmole_training[(s32)arg0->unk54].text, -1, 0)) {
                _sumole_entrypoint_19(arg0, 0);
                func_80101FDC(arg0, 12);
                return;
            }
            break;
        case 9:
            func_80800BA8_chmole_training(arg0);
            return;
        case 11:
            func_80800C28_chmole_training(arg0);
            return;
        case 12:
            func_80800C3C_chmole_training(arg0);
            return;
        case 13:
            _sumole_entrypoint_19(arg0, 0);
            arg0->unk70_10 = 12;
            break;
        }
    }
}

void func_80800270_chmole_training(Actor *arg0) {
    s32 _sumole_entrypoint_1(Actor *, s32, s32, s32);
    s32 _sumole_entrypoint_6(Actor *, s32, f32);
    s32 func_8008FD70(void);
    s32 func_800DA298(s32);
    void func_80101FDC(Actor *, u32);

    switch ((u32)arg0->unk54) {
    case 6:
        if (func_800DA298(0x53) == 0) {
            if (_sumole_entrypoint_6(arg0, -1, 350.0f) != 0) {
                func_80101FDC(arg0, 2);
                return;
            }
        } else {
            if ((func_8008FD70() & 0x701) &&
                (_sumole_entrypoint_1(arg0, -1, 0, 0) != 0)) {
                func_80101FDC(arg0, 2);
                return;
            }
        }
        break;
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 7:
        if ((func_8008FD70() & 0x701) &&
            (_sumole_entrypoint_1(arg0, -1, 0, 0) != 0)) {
            func_80101FDC(arg0, 2);
        }
        break;
    }
}

/* extern */

void func_808003D4_chmole_training(void *arg0) {
    void _sumole_entrypoint_19(void *, s32);
    s32 func_800DA298(s32);
    void func_800DA3B8(s32, s32);

    switch ((u32) (((Actor *)arg0)->unk54)) {
    case 6:
        if (func_800DA298(0x53) == 0) {
            func_800DA3B8(0x53, 1);
            return;
        }
    default:
        return;
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 7:
        _sumole_entrypoint_19(arg0, 3);
        (*(u8 *)((s8 *)(arg0) + (0x72))) = (u8) (((*(u8 *)((s8 *)(arg0) + (0x72))) & 0xFF03) | 0xC);
        break;
    }
}

/* extern */

void func_808004D0_chmole_training(Actor *arg0, BtIntPtr arg1) {
    void _gcnewoption_entrypoint_12(void *a0, u32 optionIndex, s16 textIndex);

    switch ((u32)arg0->unk54) {
    case 1:
        _gcnewoption_entrypoint_12(arg1, 0, 0xA);
        _gcnewoption_entrypoint_12(arg1, 1, 0x15);
        _gcnewoption_entrypoint_12(arg1, 2, 0x16);
        return;
    case 2:
        _gcnewoption_entrypoint_12(arg1, 0, 0xB);
        _gcnewoption_entrypoint_12(arg1, 1, 0xC);
        _gcnewoption_entrypoint_12(arg1, 2, 0x1A);
        return;
    case 4:
        _gcnewoption_entrypoint_12(arg1, 0, 0x17);
        _gcnewoption_entrypoint_12(arg1, 1, 0x18);
        _gcnewoption_entrypoint_12(arg1, 2, 0x19);
        return;
    case 0:
        _gcnewoption_entrypoint_12(arg1, 0, 0x14);
        _gcnewoption_entrypoint_12(arg1, 1, 0xD);
        return;
    case 3:
        _gcnewoption_entrypoint_12(arg1, 0, 0xE);
        _gcnewoption_entrypoint_12(arg1, 1, 0xF);
        return;
    case 7:
        _gcnewoption_entrypoint_12(arg1, 0, 0x10);
        _gcnewoption_entrypoint_12(arg1, 1, 0x11);
        return;
    case 5:
        _gcnewoption_entrypoint_12(arg1, 0, 0x12);
        _gcnewoption_entrypoint_12(arg1, 1, 0x13);
        /* fallthrough */
    default:
        return;
    }
}

void chmole_training_entrypoint_0(Unk80132ED0 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    void func_80101FDC(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    extern s16 D_80800F08_chmole_training[];
    extern s16 D_80800F10_chmole_training[];
    extern s16 D_80800F18_chmole_training[];
    extern s16 D_80800F20_chmole_training[];
    extern s16 D_80800F24_chmole_training[];
    extern s16 D_80800F28_chmole_training[];
    extern s16 D_80800F2C_chmole_training[];
    Actor *actor;

    actor = func_80106790(arg0);
    switch (arg3) {
    case 3:
        switch ((u32) actor->unk54) {
        case 1:
            actor->unk54 = D_80800F08_chmole_training[arg2];
            break;
        case 2:
            actor->unk54 = D_80800F10_chmole_training[arg2];
            break;
        case 4:
            actor->unk54 = D_80800F18_chmole_training[arg2];
            break;
        case 0:
            actor->unk54 = D_80800F20_chmole_training[arg2];
            break;
        case 3:
            actor->unk54 = D_80800F24_chmole_training[arg2];
            break;
        case 7:
            actor->unk54 = D_80800F28_chmole_training[arg2];
            break;
        case 5:
            actor->unk54 = D_80800F2C_chmole_training[arg2];
            break;
        }
        func_80101FDC(actor, 7);
        break;
    case 0:
        func_808004D0_chmole_training(actor, arg1);
        break;
    case 2:
        func_80101FDC(actor, 6);
        break;
    }
}

/* extern */

void func_808008E4_chmole_training(BtIntPtr arg0, BtIntPtr arg1, s32 arg2) {
    void _gcnewoption_entrypoint_31(BtIntPtr, s32, s16);
    BT_IDO_ONLY(void) BT_NATIVE_ONLY(int) _gcnewoption_entrypoint_32(void *arg0, s16 arg1);
    s32 func_800DA298(s32);
    s32 var_s0;

    _gcnewoption_entrypoint_32(arg1, (s16) (func_800DA298(0x578) ? 0xF : 0x9E));
    var_s0 = 0;
    if (arg2 > 0) {
        do {
            _gcnewoption_entrypoint_31(arg1, var_s0, (s16) ((var_s0 & 1) ? 0xD : 0xC));
            var_s0 += 1;
        } while (var_s0 != arg2);
    }
}

void func_80800988_chmole_training(Actor *arg0, s32 arg1, s32 arg2) {
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    void _gcnewoption_entrypoint_4(Actor *arg0, volatile s16 arg1, BtIntPtr arg2, BtIntPtr arg3, s32 arg4);
    void _gcnewoption_entrypoint_8(s16 *arg0, s32 arg1);
    void _gcnewoption_entrypoint_9(s16 *arg0, s32 arg1);
    void _gcnewoption_entrypoint_10(void *arg0, s32 arg1);
    void _gcnewoption_entrypoint_11(s16 *arg0);
    void _gcnewoption_entrypoint_14(void *arg0, s16 arg1, s16 arg2, s16 arg3, f32 arg4);
#ifndef BT_NATIVE
    extern s32 _chmole_training_entrypoint_0;
#endif
    BtIntPtr option;

    _gcnewoption_entrypoint_4(arg0, 0, &_chmole_training_entrypoint_0, 0, 0x184A);
    option = func_80100094(arg0, 0);
    _gcnewoption_entrypoint_8(option, arg1);
    _gcnewoption_entrypoint_9(option, arg2);
    _gcnewoption_entrypoint_10(option, 0);
    func_808008E4_chmole_training(arg0, option, arg2);
    _gcnewoption_entrypoint_14(option, 0, 1, 3, 4.0f);
    _gcnewoption_entrypoint_11(option);
    func_80101FDC(arg0, 5);
}

void func_80800A48_chmole_training(Actor *arg0) {
    void func_80101FDC(Actor *, u32);

    switch ((u32) arg0->unk54) {
    case 1:
        func_80800988_chmole_training(arg0, 3, 3);
        return;
    case 2:
        func_80800988_chmole_training(arg0, 3, 3);
        return;
    case 4:
        func_80800988_chmole_training(arg0, 3, 3);
        return;
    case 0:
        func_80800988_chmole_training(arg0, 2, 2);
        return;
    case 3:
        func_80800988_chmole_training(arg0, 2, 2);
        return;
    case 7:
        func_80800988_chmole_training(arg0, 2, 2);
        return;
    case 5:
        func_80800988_chmole_training(arg0, 2, 2);
        return;
    case 6:
        func_80101FDC(arg0, 4);
        return;
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
        func_80101FDC(arg0, 4);
    default:
        return;
    }
}

void func_80800BA8_chmole_training(Actor *arg0) {
    switch ((s32) arg0->unk54) {
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 26:
        arg0->unk54 = (f32) (s32) arg0->rotation[1];
        arg0->unk70_10 = 4;
        return;
    default:
        arg0->unk70_10 = 11;
        return;
    }
}

void func_80800C28_chmole_training(void *arg0) {
    (*(u8 *)((s8 *)(arg0) + (0x72))) = (u8) (((*(u8 *)((s8 *)(arg0) + (0x72))) & 0xFF03) | 0x34);
}

void func_80800C3C_chmole_training(void *arg0) {
    (((Actor *)arg0)->unk54) = (s32) (((Actor *)arg0)->rotation[1]);
    (*(u8 *)((s8 *)(arg0) + (0x72))) = (u8) (((*(u8 *)((s8 *)(arg0) + (0x72))) & 0xFF03) | 4);
}

void func_80800C70_chmole_training(Actor *arg0) {
    void _sumole_entrypoint_0(Actor*, u32);
    arg0->unk54 = (f32) (s32) arg0->rotation[1];
    _sumole_entrypoint_0(arg0, 1U);
}

OSThread *chmole_training_entrypoint_1(void)
{
    extern ActorData D_80800F30_chmole_training[1];
    return (OSThread *) D_80800F30_chmole_training;
}
#include "_training_data.inc"
