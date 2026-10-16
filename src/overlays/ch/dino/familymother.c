#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/familymother/func_80800000_chdinofamilymother.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/familymother/func_808000A0_chdinofamilymother.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/familymother/func_80800218_chdinofamilymother.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/familymother/func_808005EC_chdinofamilymother.s")

void func_808008E4_chdinofamilymother(s32 arg0) {
    typedef struct { s32 x, y, z; } Vec;
    s32 func_8010C93C(s32, s32 *, s32);
    extern Vec D_808013EC_chdinofamilymother;
    extern Vec D_808013F8_chdinofamilymother;
    Vec sp24 = D_808013EC_chdinofamilymother;
    Vec sp18 = D_808013F8_chdinofamilymother;
    func_8010C93C(arg0, &sp24, 0x3DCCCCCD);
    func_8010C93C(arg0, &sp18, 0x3E99999A);
}

void func_8080096C_chdinofamilymother(Actor *arg0) {
    extern u16 D_80801344_chdinofamilymother[][4];
    extern s32 D_80801404_chdinofamilymother[];
    extern s32 D_80801440_chdinofamilymother[];
    void _subaddieskeleton_entrypoint_0(Actor *, s32, f32 *);
    void func_800BA1D0(s32, f32 *, f32 *, s32);
    void func_800BA450(s32, s32, s32, s32, s32, s32, s32);
    void func_800BA670(s32, s32);
    void func_800BA930(s32, s32, s32, s32, s32, s32, s32);
    void func_800BAA60(u8 *, s32, s16, s16);
    s32 func_800BABB8(s32, f32 *, s32, f32, s32 *);
    s32 func_800BBCB8(f32 *, s32, f32, s32, s32 *);
    s32 func_800BEF00(f32 *, f32 *, f32 *, s32);
    void func_800C4140(s32, f32 *, s32);
    f32 func_800DC0C0(void);
    f32 func_800DC178(f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    s32 func_80101E14(Actor *, f32);

    if (D_80801344_chdinofamilymother[(u32)*(u16 *)((u8 *)arg0 + 0x72) >> 10][0] == 0x3AC) {
        if (func_80101E14(arg0, 0.23f) || func_80101E14(arg0, 0.57f) ||
            func_80101E14(arg0, 0.79f) || func_80101E14(arg0, 0.94f) ||
            func_80101E14(arg0, 0.99f)) {
            f32 position[3];
            f32 velocity[3];
            s32 emitter;
            s32 debris;

            emitter = func_800B53A4(2);
            debris = func_800B53A4(3);
            _subaddieskeleton_entrypoint_0(arg0, 0x35, position);
            _subaddieskeleton_entrypoint_0(arg0, 0x37, velocity);
            func_800BABB8(emitter, position, 0, 1.0f, D_80801404_chdinofamilymother);
            func_800BA1D0(emitter, position, velocity, 2);
            velocity[1] -= 50.0f;
            func_800BA670(debris, func_800DC0C0() < 0.5f ? 0x8A2 : 0x8A3);
            func_800BAA60((u8 *)debris, (s32)velocity, 100, 200);
            velocity[1] += 50.0f;
            func_800BABB8(debris, velocity, 0, 1.0f, D_80801440_chdinofamilymother);
            func_800BA22C(debris, 3);
            func_800C4140(0x59957C4B, velocity, 0x0BB80190);
        }
        if (func_80101E14(arg0, 0.92f)) {
            f32 start[3];
            f32 end[3];
            f32 normal[3];
            s32 emitter;

            emitter = func_800B53A4(6);
            _subaddieskeleton_entrypoint_0(arg0, 0x10, start);
            func_800EE7F8(end, start);
            end[1] -= 300.0f;
            func_800BEF00(start, end, normal, 0);
            func_800BA670(emitter, func_800DC0C0() < 0.5f ? 0x8A2 : 0x8A3);
            func_800BA930(emitter, -350, 150, -200, -300, 200, -150);
            func_800BA450(emitter, 100, -100, 50, 175, -200, 100);
            func_800BABB8(emitter, end, 0, 1.0f, D_80801440_chdinofamilymother);
            func_800BA22C(emitter, 6);
            func_800BBCB8(end, 0, 1.0f, 3, D_80801404_chdinofamilymother);
            func_800C4140(0x4CAEA44B, end, 0x0BB80190);
        } else if (func_80101E14(arg0, 0.1f) || func_80101E14(arg0, 0.18f) ||
                   func_80101E14(arg0, 0.25f)) {
            f32 start[3];
            f32 end[3];
            f32 normal[3];

            _subaddieskeleton_entrypoint_0(arg0, 0x10, start);
            func_800EE7F8(end, start);
            end[1] -= 300.0f;
            func_800BEF00(start, end, normal, 0);
            func_800BBCB8(end, 0, 1.0f, 1, D_80801404_chdinofamilymother);
            func_800C4140(0x4CAEA44B, end, 0x0BB80190);
        }
        if (func_80101E14(arg0, 0.42f)) {
            f32 position[3];

            _subaddieskeleton_entrypoint_0(arg0, 0x2B, position);
            func_800C4140(((u16)(func_800DC178(0.45f, 0.55f) * 1023.0f) << 21) + 0xBBCCA,
                          position, 0x0BB80190);
        }
        if (func_80101E14(arg0, 0.772f)) {
            f32 position[3];

            _subaddieskeleton_entrypoint_0(arg0, 0x2B, position);
            func_800C4140(((u16)(func_800DC178(0.75f, 0.85f) * 1023.0f) << 21) + 0xBBCCA,
                          position, 0x0BB80190);
        }
    } else {
        if (func_80101E14(arg0, 0.025f) || func_80101E14(arg0, 0.19f) ||
            func_80101E14(arg0, 0.36f) || func_80101E14(arg0, 0.52f) ||
            func_80101E14(arg0, 0.7f) || func_80101E14(arg0, 0.85f)) {
            f32 position[3];

            _subaddieskeleton_entrypoint_0(arg0, 0x37, position);
            func_800BBCB8(position, 0, 1.0f, 1, D_80801404_chdinofamilymother);
            func_800C4140(0x4CB57C4B, position, 0x0BB80190);
        }
        if (func_80101E14(arg0, 0.5f) || func_80101E14(arg0, 0.7f)) {
            f32 start[3];
            f32 end[3];
            f32 normal[3];
            s32 emitter;

            emitter = func_800B53A4(6);
            _subaddieskeleton_entrypoint_0(arg0, 0x10, start);
            func_800EE7F8(end, start);
            end[1] -= 300.0f;
            func_800BEF00(start, end, normal, 0);
            func_800BA930(emitter, 150, 150, 300, 200, 200, 350);
            func_800BA450(emitter, -50, -100, -100, -100, -200, -175);
            func_800BABB8(emitter, end, 0, 1.0f, D_80801440_chdinofamilymother);
            func_800BA22C(emitter, 6);
            func_800BBCB8(end, 0, 1.0f, 1, D_80801404_chdinofamilymother);
            func_800C4140(0x3FEDAC11, end, 0x0BB80190);
        }
    }
}

void func_80801118_chdinofamilymother(Actor *arg0, Unk80132ED0 *arg1, s32 arg2, s32 arg3) {
    void _capod_entrypoint_2(Unk80132ED0 *, u32, s32);
    void _capod_entrypoint_6(Unk80132ED0 *, s32, s32);

    switch (arg0->actorData[7]) {
        case 0:
            _capod_entrypoint_2(arg0->unk0, 0x27, arg3 | 0x10);
        case 1:
            arg0->actorData[7] = 2;
        case 2:
            _capod_entrypoint_6(arg1, arg2, arg3);
            break;
    }
}

void func_8080119C_chdinofamilymother(Actor *arg0, s32 arg1, s32 arg2, s32 arg3) {
    void _capod_entrypoint_2(Unk80132ED0 *, u32, s32);
    void _capod_entrypoint_7(s32, s32);
    s32 _capod_entrypoint_8(s32);
    void _gcdialogcamera_entrypoint_6(Unk80132ED0 *);
    void _gcdialogcamera_entrypoint_8(void);

    switch (arg0->actorData[7]) {
        case 0:
            _capod_entrypoint_2(arg0->unk0, 0x27, arg3 | 0x10);
        case 2:
            _capod_entrypoint_8(1);
            arg0->actorData[7] = 1;
            _gcdialogcamera_entrypoint_6(arg0->unk0);
            _gcdialogcamera_entrypoint_8();
        case 1:
            _capod_entrypoint_7(arg1, arg2);
            break;
    }
}

/* extern */

void func_80801228_chdinofamilymother(void *arg0) {
    s32 _capod_entrypoint_3(s32, void *);
    if ((*(s32 *)((s8 *)(arg0) + (0x34))) != 0) {
        _capod_entrypoint_3(0, arg0);
        (*(s32 *)((s8 *)(arg0) + (0x34))) = 0;
    }
}

OSThread *chdinofamilymother_entrypoint_0(void)
{
    extern u8 D_80801474_chdinofamilymother[];

    return (OSThread *) D_80801474_chdinofamilymother;
}
