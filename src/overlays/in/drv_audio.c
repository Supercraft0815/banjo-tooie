#include "common.h"

void func_80800000_indrv_audio(void *arg0, s32 arg1, s32 *arg2) {
    s32 *func_8008FFE8(void);
    void func_800C3AE0(u8, f32);
    void func_800C3BDC(u8 id);
    u8 func_800C4350();
    void func_800DBEFC(s32 *, s32, f32 *);
    void func_800EE88C(f32 *, s16 *);
    f32 func_800F1DF4(f32 *, f32 *);
    int func_800F20BC(f32, f32, f32);
    void func_8010FFB0(s32 *, f32 *, f32 *);
    extern s32 D_80801478_indrv_audio;
    f32 sp3C[3];
    u8 sp3B;
    f32 sp2C[3];
    f32 sp20[3];

    if (arg1 >= 0) {
        func_800DBEFC(((s32 **)arg0)[1], arg1, sp3C);
    } else {
        func_800EE88C(sp3C, *(s16 **)arg0 + 2);
    }
    sp3B = func_800C4350(0, sp3C, &D_80801478_indrv_audio);
    func_800C4350(sp3B & 0xFF, sp3C, arg2);
    func_8010FFB0(func_8008FFE8(), sp2C, sp20);
    if (func_800F20BC(sp20[1], func_800F1DF4(sp3C, sp2C), 50.0f) == 0) {
        func_800C3AE0(sp3B, 0.25f);
    }
    func_800C3BDC(sp3B);
}

void func_808000BC_indrv_audio(BtIntPtr arg0, s32 *arg1) {
    void func_800C3BDC(u8 id);
    u8 func_800C4350(s32, BtIntPtr, s32 *);
    extern s32 D_80801478_indrv_audio;
    u8 sp1F;
    u8 temp_v0;

    temp_v0 = func_800C4350(0, 0, &D_80801478_indrv_audio);
    sp1F = temp_v0;
    func_800C4350(temp_v0 & 0xFF, 0, arg1);
    func_800C3BDC(sp1F);
}

void indrv_audio_entrypoint_0(Unk80132ED0 *arg0, s32 arg1, s32 arg2) {
    struct AudioEntry {
        u16 id;
        s32 *data;
    };
    extern struct AudioEntry D_808014A4_indrv_audio[];
    extern struct AudioEntry D_80801A4C_indrv_audio;
    Actor *func_80106790(Unk80132ED0 *);
    s32 func_800DA298(s32);
    struct AudioEntry *entry;
    entry = D_808014A4_indrv_audio; do {
        if (arg1 == entry->id) {
            switch (arg2) {
                case -3:
                    if (func_80106790(arg0)->unk7C_12) {
                        func_80800000_indrv_audio(arg0, -2, entry->data);
                    }
                    break;
                case -2:
                    func_808000BC_indrv_audio((BtIntPtr)arg0, entry->data);
                    break;
                case -4:
                    if (func_800DA298(0xE) != 0) {
                        func_80800000_indrv_audio(arg0, -1, entry->data);
                    }
                    break;
                default:
                    func_80800000_indrv_audio(arg0, arg2, entry->data);
                    break;
            }
        }
        entry++;
    } while (entry != &D_80801A4C_indrv_audio);
}
