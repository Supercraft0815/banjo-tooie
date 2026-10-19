#include "common.h"

OSThread *changlerbossbubble_entrypoint_0(void)
{
    extern u8 D_808005D0_changlerbossbubble[];

    return (OSThread *) D_808005D0_changlerbossbubble;
}

/* extern */

void func_8080000C_changlerbossbubble(void *arg0) {
    s32 func_800EC75C(s32, s32 *);
    s32 func_800EFD4C(s32);
    s32 sp1C[3];

    func_800EC75C((*(s32 *)((s8 *)(arg0) + (0))), sp1C);
    func_800EFD4C((*(s32 *)((s8 *)(arg0) + (0))) + 0x1E);
    (*(f32 *)((s8 *)(arg0) + (0x34))) = 0.75f;
}

void func_80800054_changlerbossbubble(Actor *arg0) {
    void func_80015E80(s32, void *);
    f32 func_800D8FF8(void);
    s32 func_800D9078(f32 *);
    s32 func_800EFD4C(s32);
    s32 func_800F54F0(s32);
    void func_800F7B9C(s32, u32);
    s32 func_8010114C(s32, s32, s32);
    s32 func_8010B990(Actor *, s32);
    void func_80800334_changlerbossbubble(Actor *);
    void func_80800450_changlerbossbubble(u8 *);
    s32 buttons[6];
    s32 controller;
    typedef struct {
        f32 timer;
        s32 count;
    } BubbleData;
    s32 marker;

    arg0->unk58 += func_800D8FF8();
    func_800EFD4C((s32)((s16 *)&arg0->unk0->unk1C + 1));
    goto dispatch;
dispatch:
    switch (arg0->unk70_10) {
        case 1:
            if (func_8010B990(arg0, 0x400007) & 0x20) {
                func_80800334_changlerbossbubble(arg0);
            }
            break;
        case 2:
            controller = func_800F54F0(arg0->unk6C_0);
            func_80800450_changlerbossbubble((u8 *)arg0);
            func_80015E80(controller, buttons);
            if (buttons[0] == 1 || buttons[1] == 1) {
                ((BubbleData *)arg0->actorData)->count++;
                if (((BubbleData *)arg0->actorData)->count >= 10) {
                    func_800F7B9C(arg0->unk6C_0, 0x70);
                    return;
                }
                func_800F7B9C(arg0->unk6C_0, 0x7B);
            }
            if (func_800D9078(&((BubbleData *)arg0->actorData)->timer)) {
                marker = (s32)arg0->unk3C;
                if (marker != 0) {
                    func_8010114C(marker, 10, 0);
                }
            }
            break;
    }
}

/* extern */

s32 func_80800194_changlerbossbubble(s32 arg0) {
    s32 func_800F64A4(s32, s32);
    s32 func_800F6D24(s32);
    s32 func_800F8B88();
    if (func_800F64A4(arg0, 0xA01) == 0) {
        return 0;
    }
    if (func_800F6D24(arg0) == 0) {
        return 1;
    }
    if (func_800F8B88() == 3) {
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anglerboss/bubble/func_80800200_changlerbossbubble.s")

void func_80800334_changlerbossbubble(Actor *arg0) {
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 func_800B53A4(s32);
    void func_800BA22C(s32, s32);
    void func_800BA568(s16 *, s16);
    void func_800BA7C4(void *, f32, f32);
    void func_800BA7FC(void *, f32, f32);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    s32 func_800DC128(s32, s32);
    void func_800FFA88(Unk80132ED0 *);
    extern s32 D_80800618_changlerbossbubble;
    extern s32 D_80800668_changlerbossbubble;
    s32 sp3C;
    f32 temp_f20;
    s32 temp_v0_2;

    _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80800668_changlerbossbubble);
    sp3C = func_800DC128(3, 4);
    temp_v0_2 = func_800B53A4(sp3C);
    temp_f20 = arg0->scale;
    func_800BABB8(temp_v0_2, arg0->position, arg0->position, 1.0f, &D_80800618_changlerbossbubble);
    func_800BA568(temp_v0_2, (s16) (arg0->position[1] + 1000.0f));
    func_800BA7C4(temp_v0_2, 0.25f * temp_f20, 0.6f * temp_f20);
    func_800BA7FC(temp_v0_2, 0.1f * temp_f20, 0.2f * temp_f20);
    func_800BA22C(temp_v0_2, sp3C);
    func_800FFA88(arg0->unk0);
}

/* extern */

void func_80800450_changlerbossbubble(u8 *arg0) {
    s32 func_800F5BF0(s32, u8 *, u8 *);
    func_800F5BF0((*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF, arg0 + 4, arg0);
}

/* extern */

void func_80800480_changlerbossbubble(Actor *arg0, s32 arg1) {
    s32 _chbubble_entrypoint_0(s32, f32 *, f32 *, f32, f32);
    f32 func_800138D0(f32);
    f32 func_80013970(f32);
    void func_800E3980(f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EEBF0(f32 *, f32 *, f32);
    void func_800EF04C(f32 *, f32 *);
    f32 func_800F13C4(f32, f32);
    s32 func_800F18FC(f32 *, f32 *, f32 *);
    f32 sp44[3];
    f32 sp38[3];
    f32 sp30[2];

    func_800EE7F8(sp38, arg0->position);
    func_800E3980(sp44);
    func_800F18FC(sp38, sp44, sp30);
    func_800EEBF0(sp44, sp30, 75.0f);
    func_800EF04C(sp38, sp44);
    sp30[0] = func_80013970((func_800F13C4(arg0->unk58, *(f32 *)&arg0->actorData[7]) / *(f32 *)&arg0->actorData[7]) * 360.0f) * 0.1f + 1.0f;
    sp30[1] = func_800138D0((func_800F13C4(arg0->unk58, *(f32 *)&arg0->actorData[7]) / *(f32 *)&arg0->actorData[7]) * 360.0f) * 0.15f + 1.0f;
    arg0->unk7C_12 = _chbubble_entrypoint_0(arg1, sp38, sp30, arg0->scale, 0.0f);
}
