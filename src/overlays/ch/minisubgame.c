#include "common.h"

OSThread *chminisubgame_entrypoint_0(void)
{
    extern u8 D_80801424_chminisubgame[];

    return (OSThread *) D_80801424_chminisubgame;
}

OSThread *chminisubgame_entrypoint_1(void)
{
    extern u8 D_8080146C_chminisubgame[];

    return (OSThread *) D_8080146C_chminisubgame;
}

void func_80800018_chminisubgame(Actor *arg0) {
    s32 _gccubesearch_entrypoint_9(s32, Prop **, s32);
    void _gspropctrl_entrypoint_11(Prop *, f32[3]);
    s32 _susubgame_entrypoint_0(Actor *, u32 *, s32);
    s32 _susubgame_entrypoint_11(s32);
    void *func_80100094(Actor *, u32);
    extern Prop *B_80801590_chminisubgame[];
    u32 *data;
    Prop **prop;
    s32 count;
    s32 i;
    f32 *position;

    data = func_80100094(arg0, 0U);
    count = _gccubesearch_entrypoint_9(0x1C0, B_80801590_chminisubgame, 0x3C);
    arg0->actorData[6] = count;
    i = 0;
    if (count > 0) {
        prop = B_80801590_chminisubgame;
        position = (f32 *)data;
        do {
            _gspropctrl_entrypoint_11(*prop, position);
            i++;
            prop++;
            position += 3;
        } while (i < (s32)arg0->actorData[6]);
    }
    _susubgame_entrypoint_0(arg0, data + 0xC3, 0);
    _susubgame_entrypoint_11(0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/minisubgame/func_808000C8_chminisubgame.s")

void func_80800430_chminisubgame(Actor *arg0) {
    s32 _susubgame_entrypoint_11(s32);
    s32 _susubgame_entrypoint_2(void *, s32);
    s32 _susubgame_entrypoint_4(void *, s32);
    void* func_80100094(Actor*, u32);
    u8 *sp1C;

    sp1C = func_80100094(arg0, 0U);
    _susubgame_entrypoint_11(0);
    if (_susubgame_entrypoint_2(arg0, (s32) (sp1C + 0x30C)) != 0) {
        _susubgame_entrypoint_4(arg0, (s32) (sp1C + 0x30C));
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/minisubgame/func_80800484_chminisubgame.s")

void func_80800A64_chminisubgame(Actor *arg0, s32 arg1) {
    void* func_80100094(Actor*, u32);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    arg0->actorData[5] -= 1;
    (*(s8 *)((s8 *)((temp_v0 + arg1)) + (0x2D0))) = 2;
}

s32 func_80800AAC_chminisubgame(Actor *arg0) {
    void func_8008FE68(f32 *);
    s32 func_800DC128(s32, s32);
    f32 func_800EEAD4(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    f32 (*data)[3];
    f32 position[3];
    s32 index;
    s32 i;

    data = func_80100094(arg0, 0U);
    func_8008FE68(position);
    for (i = 0; i < (s32)arg0->actorData[6]; i++) {
        index = func_800DC128(0, arg0->actorData[6]);
        if (func_800EEAD4(data[index], position) > 1200.0f) {
            if (2 == ((u8 *)data)[index + 0x2D0]) {
                ((u8 *)data)[index + 0x2D0] = 0;
            } else if (((u8 *)data)[index + 0x2D0] == 0) {
                return index;
            }
        }
    }
    return -1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/minisubgame/func_80800BA8_chminisubgame.s")

/* extern */

void func_80800EC8_chminisubgame(Actor *arg0) {
    f32 func_80013970(f32);
    f32 func_800D8FF8(void);
    s32 func_800D9078(f32 *);
    s32 func_800DA298(s32);
    void func_800E3980(f32 *);
    void func_80102424(Actor *, s32);
    void func_80102BF8(void *, f32, f32, f32);
    f32 func_80102D78(Actor *, f32 *);
    s32 func_8010C9B0(f32 *, s32);
    void func_8010D600(s32);
    s32 func_80801058_chminisubgame(Actor *, s32, s32);
    f32 sp34[3];
    f32 sp28[3];
    u32 state;

    state = arg0->unk70_10;
    if (state != 1) {
        if (state != 2) {
            if (state == 3) {
                if ((s32)arg0->actorData[7] >= 0) {
                    func_800E3980(sp34);
                    arg0->unk54 = func_80102D78(arg0, sp34);
                    func_80102BF8(arg0, 0.1f, 4.0f, 180.0f);
                }
                if (func_800DA298(0) == 0) {
                    func_80102424(arg0, 1);
                }
            }
        } else {
            goto block_9;
        }
    } else {
        if (arg0->unk58 < 5.0f) {
            func_80102424(arg0, 2);
        }
block_9:
        func_8010D600((s32)sp28);
        arg0->unk54 = func_80102D78(arg0, sp28);
        func_80102BF8(arg0, 0.1f, 4.0f, 180.0f);
        ((f32 *)arg0->actorData)[4] += (240.0f + (arg0->unk58 / ((f32 *)arg0->actorData)[5]) * -120.0f) * func_800D8FF8();
        arg0->position[1] = ((f32 *)arg0->actorData)[6] + func_80013970(((f32 *)arg0->actorData)[4]) * arg0->unk50;
        if (func_800D9078(&arg0->unk58) || func_8010C9B0(arg0->position, (s32)((f32 *)arg0->actorData)[3])) {
            func_80801058_chminisubgame(arg0, 0x3E, 0);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/minisubgame/func_80801058_chminisubgame.s")

void func_808011DC_chminisubgame(u8 *arg0, s32 arg1, s32 arg2) {
    s32 func_800B53A4(s32);
    void func_800BA22C(s32, s32);
    void func_800BA670(s32, s32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    extern s32 D_808014B4_chminisubgame;
    s32 sp24;
    f32 *temp_a1;
    s32 temp_v0;

    temp_v0 = func_800B53A4(arg2);
    sp24 = temp_v0;
    func_800BA670(temp_v0, arg1);
    temp_a1 = arg0 + 4;
    func_800BABB8(sp24, temp_a1, temp_a1, (*(f32 *)((s8 *)(arg0) + (0x38))), &D_808014B4_chminisubgame);
    func_800BA22C(sp24, arg2);
}

void func_80801248_chminisubgame(Actor *arg0) {
    s32 func_80090270();
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    void func_800C4AF0(f32 *, void *);
    s32 func_800CEAD0(s32);
    s32 func_800DA298(s32);
    s32 func_800E1610(s32, f32, f32, f32 *);
    extern s32 D_808014F0_chminisubgame;
    extern s32 D_80801534_chminisubgame;
    extern s32 D_80801578_chminisubgame;
    f32 *position;

    if (func_80090270() == 0 && (func_800DA298(0) != 0 || func_800CEAD0(0) == 0)) {
        position = arg0->position;
        func_800E1610(0, 20.0f, 0.6f, position);
        func_800C4AF0(position, &D_80801578_chminisubgame);
    }
    position = arg0->position;
    func_808011DC_chminisubgame((u8 *)arg0, arg0->unk6C_0 * 3 + 0x9A4, 2);
    func_808011DC_chminisubgame((u8 *)arg0, arg0->unk6C_0 * 3 + 0x9A5, 6);
    func_808011DC_chminisubgame((u8 *)arg0, arg0->unk6C_0 * 3 + 0x9A6, 4);
    func_800BABB8(0, position, NULL, 1.0f, &D_808014F0_chminisubgame);
    func_800BABB8(0, position, NULL, 1.0f, &D_80801534_chminisubgame);
}
