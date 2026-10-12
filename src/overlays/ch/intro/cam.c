#include "common.h"

s32 _capod_entrypoint_17(f32);
void _indrv_audio_entrypoint_0(Unk80132ED0 *, s32, s32);

void func_80800000_chintrocam(Actor *arg0) { arg0->unk6C_0 = func_800EA05C(); _capod_entrypoint_13(arg0->unk0, NULL, (u32) (s32) arg0->rotation[1], 0x6822); }

void func_80800054_chintrocam(s32 arg0) 
{
}
void func_8080005C_chintrocam(Actor *arg0) {
    u32 temp_t7;

    temp_t7 = arg0->unk6C_0;
    switch (temp_t7) {
    case 0x17E:
    case 0x199:
        break;
    case 0xA1:
        if (_capod_entrypoint_17(1.0f) != 0) {
            _indrv_audio_entrypoint_0(arg0->unk0, 0x5D, -2);
            return;
        }
        return;
    case 0xA2:
        if (_capod_entrypoint_17(1.0f) != 0) {
            _indrv_audio_entrypoint_0(arg0->unk0, 0x5D, -2);
        }
        if (_capod_entrypoint_17(1400.0f) != 0) {
            _indrv_audio_entrypoint_0(arg0->unk0, 0x24, -2);
            return;
        }
        break;
    case 0xA3:
        if (_capod_entrypoint_17(1.0f) != 0) {
            _indrv_audio_entrypoint_0(arg0->unk0, 0x5D, -2);
        }
        if (_capod_entrypoint_17(1.0f) != 0) {
            _indrv_audio_entrypoint_0(arg0->unk0, 0x25, -2);
        }
        if (_capod_entrypoint_17(2300.0f) != 0) {
            _indrv_audio_entrypoint_0(arg0->unk0, 0x28, -2);
        }
        if (_capod_entrypoint_17(2800.0f) != 0) {
            _indrv_audio_entrypoint_0(arg0->unk0, 0x2A, -2);
            return;
        }
        break;
    case 0xA4:
        if (_capod_entrypoint_17(1.0f) != 0) {
            _indrv_audio_entrypoint_0(arg0->unk0, 0x5D, -2);
        }
        if (_capod_entrypoint_17(4200.0f) != 0) {
            _indrv_audio_entrypoint_0(arg0->unk0, 0x68, -2);
        }
        if (_capod_entrypoint_17(4200.0f) != 0) {
            _indrv_audio_entrypoint_0(arg0->unk0, 0x69, -2);
        }
        if (_capod_entrypoint_17(4195.0f) != 0) {
            _indrv_audio_entrypoint_0(arg0->unk0, 0x6A, -2);
            return;
        }
        break;
    case 0xA5:
        if (_capod_entrypoint_17(1.0f) != 0) {
            _indrv_audio_entrypoint_0(arg0->unk0, 0x5D, -2);
        }
        if (_capod_entrypoint_17(550.0f) != 0) {
            _indrv_audio_entrypoint_0(arg0->unk0, 0x56, -2);
            return;
        }
        break;
    case 0xA6:
        if (_capod_entrypoint_17(1.0f) != 0) {
            _indrv_audio_entrypoint_0(arg0->unk0, 0x5D, -2);
        }
        if (_capod_entrypoint_17(3085.0f) != 0) {
            _indrv_audio_entrypoint_0(arg0->unk0, 0x2F, -2);
        }
        if (_capod_entrypoint_17(3200.0f) != 0) {
            _indrv_audio_entrypoint_0(arg0->unk0, 0x31, -2);
        }
        if (_capod_entrypoint_17(3400.0f) != 0) {
            _indrv_audio_entrypoint_0(arg0->unk0, 0x32, -2);
            return;
        }
        break;
    case 0xA9:
        if (_capod_entrypoint_17(1.0f) != 0) {
            _indrv_audio_entrypoint_0(arg0->unk0, 0x63, -2);
            return;
        }
        break;
    case 0xAC:
        if (_capod_entrypoint_17(2100.0f) != 0) {
            _indrv_audio_entrypoint_0(arg0->unk0, 0x5E, -2);
        }
        if (_capod_entrypoint_17(2640.0f) != 0) {
            _indrv_audio_entrypoint_0(arg0->unk0, 0x5F, -2);
        }
        if (_capod_entrypoint_17(2640.0f) != 0) {
            _indrv_audio_entrypoint_0(arg0->unk0, 0x60, -2);
        }
        if (_capod_entrypoint_17(2640.0f) != 0) {
            _indrv_audio_entrypoint_0(arg0->unk0, 0x61, -2);
        }
        if (_capod_entrypoint_17(2650.0f) != 0) {
            _indrv_audio_entrypoint_0(arg0->unk0, 0x62, -2);
            return;
        }
        break;
    case 0x18E:
        if (_capod_entrypoint_17(1000.0f) != 0) {
            _indrv_audio_entrypoint_0(arg0->unk0, 0x6B, -2);
            return;
        }
        break;
    case 0x18C:
        if (_capod_entrypoint_17(1.0f) != 0) {
            _indrv_audio_entrypoint_0(arg0->unk0, 0x6C, -2);
        }
        if (_capod_entrypoint_17(2900.0f) != 0) {
            _indrv_audio_entrypoint_0(arg0->unk0, 0x6D, -2);
        }
        if (_capod_entrypoint_17(9250.0f) != 0) {
            _indrv_audio_entrypoint_0(arg0->unk0, 0x6E, -2);
        }
        if (_capod_entrypoint_17(9250.0f) != 0) {
            _indrv_audio_entrypoint_0(arg0->unk0, 0x6F, -2);
        }
        if (_capod_entrypoint_17(9450.0f) != 0) {
            _indrv_audio_entrypoint_0(arg0->unk0, 0x75, -2);
        }
        if (_capod_entrypoint_17(9450.0f) != 0) {
            _indrv_audio_entrypoint_0(arg0->unk0, 0x76, -2);
            return;
        }
        break;
    case 0x18F:
        if (_capod_entrypoint_17(1.0f) != 0) {
            _indrv_audio_entrypoint_0(arg0->unk0, 0x70, -2);
        }
        if (_capod_entrypoint_17(830.0f) != 0) {
            _indrv_audio_entrypoint_0(arg0->unk0, 0x71, -2);
            return;
        }
        break;
    case 0x190:
        if (_capod_entrypoint_17(1.0f) != 0) {
            _indrv_audio_entrypoint_0(arg0->unk0, 0x72, -2);
            return;
        }
        break;
    case 0x194:
        if (_capod_entrypoint_17(3500.0f) != 0) {
            _indrv_audio_entrypoint_0(arg0->unk0, 0x70, -2);
        }
        if (_capod_entrypoint_17(3500.0f) != 0) {
            _indrv_audio_entrypoint_0(arg0->unk0, 0x6E, -2);
        }
        if (_capod_entrypoint_17(3500.0f) != 0) {
            _indrv_audio_entrypoint_0(arg0->unk0, 0x6F, -2);
        }
        if (_capod_entrypoint_17(4200.0f) != 0) {
            _indrv_audio_entrypoint_0(arg0->unk0, 0x75, -2);
        }
        if (_capod_entrypoint_17(4220.0f) != 0) {
            _indrv_audio_entrypoint_0(arg0->unk0, 0x76, -2);
            return;
        }
        break;
    case 0x197:
        if (_capod_entrypoint_17(1.0f) != 0) {
            _indrv_audio_entrypoint_0(arg0->unk0, 0x70, -2);
        }
        if (_capod_entrypoint_17(1.0f) != 0) {
            _indrv_audio_entrypoint_0(arg0->unk0, 0x6E, -2);
        }
        if (_capod_entrypoint_17(625.0f) != 0) {
            _indrv_audio_entrypoint_0(arg0->unk0, 0x71, -2);
            return;
        }
        break;
    case 0x198:
        if (_capod_entrypoint_17(1.0f) != 0) {
            _indrv_audio_entrypoint_0(arg0->unk0, 0x71, -2);
        }
        if (_capod_entrypoint_17(320.0f) != 0) {
            _indrv_audio_entrypoint_0(arg0->unk0, 0x6E, -2);
            return;
        }
        break;
    case 0x195:
        if (_capod_entrypoint_17(2900.0f) != 0) {
            _indrv_audio_entrypoint_0(arg0->unk0, 0x70, -2);
        }
        if (_capod_entrypoint_17(2900.0f) != 0) {
            _indrv_audio_entrypoint_0(arg0->unk0, 0x6E, -2);
        }
        if (_capod_entrypoint_17(2930.0f) != 0) {
            _indrv_audio_entrypoint_0(arg0->unk0, 0x6F, -2);
        }
        if (_capod_entrypoint_17(2950.0f) != 0) {
            _indrv_audio_entrypoint_0(arg0->unk0, 0x75, -2);
        }
        if (_capod_entrypoint_17(2970.0f) != 0) {
            _indrv_audio_entrypoint_0(arg0->unk0, 0x76, -2);
            return;
        }
        break;
    case 0x193:
        if (_capod_entrypoint_17(150.0f) != 0) {
            _indrv_audio_entrypoint_0(arg0->unk0, 0x73, -2);
        }
        if (_capod_entrypoint_17(150.0f) != 0) {
            _indrv_audio_entrypoint_0(arg0->unk0, 0x74, -2);
            return;
        }
        break;
    case 0x196:
        if (_capod_entrypoint_17(4800.0f) != 0) {
            _indrv_audio_entrypoint_0(arg0->unk0, 0xAD, -2);
        }
        break;
    }
}


s32 func_808008EC_chintrocam(s32 arg0, s32 arg1, s32 arg2) 
{
    return 0;
}
OSThread *chintrocam_entrypoint_0(void)
{
    extern u8 D_80800A20_chintrocam[];

    return (OSThread *) D_80800A20_chintrocam;
}
