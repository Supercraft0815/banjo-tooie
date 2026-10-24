#include "common.h"

void func_801018A4(Actor *, s32);
void func_80105834(Actor *);
void *func_80107C2C(s32 *, s32, void *, s32, void *);
void func_80800000_chdinofamilymother(Actor *arg0);
void func_808000A0_chdinofamilymother(Actor *arg0);
s32 func_80800218_chdinofamilymother(void *arg0, s32 arg1, s32 arg2);
extern u32 D_80801340_chdinofamilymother[];

u32 D_80801340_chdinofamilymother[] = {
    0x00000000,
};

u16 D_80801344_chdinofamilymother[] = {
    0x0000, 0x0000, 0x40E0, 0x0000,
    0x03AC, 0x0001, 0x40E0, 0x0000,
    0x03AC, 0x0001, 0x40E0, 0x0000,
    0x03AC, 0x0001, 0x40E0, 0x0000,
    0x03AC, 0x0001, 0x40E0, 0x0000,
    0x03AC, 0x0001, 0x40E0, 0x0000,
    0x03AD, 0x0001, 0x40E0, 0x0000,
    0x03AD, 0x0001, 0x40E0, 0x0000,
    0x03AD, 0x0001, 0x40E0, 0x0000,
    0x03AD, 0x0001, 0x40E0, 0x0000,
    0x03AD, 0x0001,
};

s32 D_80801398_chdinofamilymother = 0x015D04B0;

s16 D_8080139C_chdinofamilymother[] = {
    0x17BA, 0x17C0, 0x0000, 0x0601,
    0x120B, 0x0000, 0x0065, 0x0000,
    0x000C, 0x203C, 0x0000, 0x0000,
};

s32 D_808013B4_chdinofamilymother = 0x015D04B0;

s16 D_808013B8_chdinofamilymother[] = {
    0x17BB, 0x17C0, 0x0000, 0x0601,
    0x120B, 0x0000, 0x0065, 0x0000,
    0x000C, 0x203C, 0x0000, 0x0000,
};

s32 D_808013D0_chdinofamilymother[] = {
    0xC4480000, 0x00000000, 0xC50FC000,
};

s32 D_808013DC_chdinofamilymother[] = {
    0x44160000, 0x44160000, 0x442F0000, 0x43480000,
};

u32 D_808013EC_chdinofamilymother[] = {
    0xC3FA0000, 0x00000000, 0xC4E10000,
};

u32 D_808013F8_chdinofamilymother[] = {
    0x43B90000, 0x00000000, 0xC4F1E000,
};

s32 D_80801404_chdinofamilymother[] = {
    0x001D09C9, 0x00161004, 0x002B0100, 0x01800022,
    0x00800100, 0x02000400, 0x00150033, 0x00330019,
    0x00000007, 0x002CFFD8, 0x0028FFD8, 0x00280050,
    0x00280020, 0x8C7828A0, 0x00000000,
};

s32 D_80801440_chdinofamilymother[] = {
    0x001D08A3, 0x00161400, 0x002B0180, 0x02000022,
    0x01800100, 0x00330080, 0x00150019, 0x00E6001B,
    0xFF38FED4, 0x00270064, 0x006400C8, 0x00C8000D,
    0x00320000,
};

u32 D_80801474_chdinofamilymother[] = {
    0x01280290, 0x08990001, (u32)D_80801340_chdinofamilymother, (u32)func_808000A0_chdinofamilymother,
    (u32)func_80105834, (u32)func_801018A4, 0x13880000, 0x40000000,
    0x00000000, 0x00000528, 0x00000000, 0x00000000,
    0x00000000, (u32)func_80800000_chdinofamilymother, (u32)func_80107C2C, 0x80007406,
    (u32)func_80800218_chdinofamilymother, 0x00000000, 0x00000000,
};

void func_80800000_chdinofamilymother(Actor *arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 func_800DA298(s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_808005EC_chdinofamilymother(Actor *, s32);

    if (_glcutDll_entrypoint_20() != 0) {
        func_808005EC_chdinofamilymother(arg0, 0xA);
    } else if ((func_800DA298(0x15E) != 0) &&
               (func_800DA298(0x189) == 0) &&
               (func_800DA298(0x15F) != 0) &&
               (func_800DA298(0x8A) != 0)) {
        func_808005EC_chdinofamilymother(arg0, 9);
    }
    func_800EE7F8((f32 *)arg0->actorData, arg0->position);
    arg0->actorData[7] = 0;
    ((f32 *)arg0->actorData)[1] = 0.0f;
}

void func_808000A0_chdinofamilymother(Actor *arg0) {
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, u32, u32, f32 *, u32);
    s32 _subaddiedialog_entrypoint_4(f32 *, s32, s32);
    s32 _subaddiedialog_entrypoint_7(s32, s32, s32 *);
    s32 func_800DA298(s32);
    s32 func_800F5410(s32);
    u32 func_800F54E4(void);
    void func_808008E4_chdinofamilymother(s32);
    void func_8080096C_chdinofamilymother(Actor *);
    void func_8080119C_chdinofamilymother(Actor *, s32, s32, s32);





    switch (arg0->unk70_10) {
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
        break;
    case 1:
        if (func_800DA298(0x8A) != 0) {
            if (func_800F5410(func_800F54E4()) == 0xB) {
                D_808013B8_chdinofamilymother[0] = 0x1814;
            }
            if (_subaddiedialog_entrypoint_7((s32)arg0, (s32)arg0->actorData, &D_808013B4_chdinofamilymother) != 0) {
                func_8080119C_chdinofamilymother(arg0, 2, 0, 0);
            }
        } else {
            switch (func_800F5410(func_800F54E4())) {
            case 10:
                D_8080139C_chdinofamilymother[0] = 0x1812;
                break;
            case 11:
                D_8080139C_chdinofamilymother[0] = 0x1813;
                break;
            }
            if (_subaddiedialog_entrypoint_7((s32)arg0, (s32)arg0->actorData, &D_80801398_chdinofamilymother) != 0) {
                func_8080119C_chdinofamilymother(arg0, 2, 0, 0);
            }
        }
        break;
    case 9:
        if (_subaddiedialog_entrypoint_4((f32 *)arg0->actorData, 0x4B0, 0) != 0) {
            _subaddiedialog_entrypoint_11(arg0->unk0, 0x17C6, 0xC, (f32 *)arg0->actorData, 0x65);
        }
        break;
    }
    func_808008E4_chdinofamilymother((s32)arg0);
    func_8080096C_chdinofamilymother(arg0);
}

s32 func_80800218_chdinofamilymother(void *arg0, s32 arg1, s32 arg2) {
    s32 _gcdialogcamera_entrypoint_0(s32, s32);
    s32 _gcdialogcamera_entrypoint_3(s32 *, f32);
    s32 _gcdialogcamera_entrypoint_4(s32 *);
    void _glcutDll_entrypoint_17(void);
    s32 _glcutDll_entrypoint_23(void);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, u32, u32, f32 *, u32);
    s32 func_800DA298(s32);
    void func_800DF744(s32, s32);
    s32 func_801015D0(Actor *);
    void func_808005EC_chdinofamilymother(Actor *, s32);
    void func_8080119C_chdinofamilymother(Actor *, s32, s32, s32);
    void func_80801228_chdinofamilymother(void *);



    s32 low;
    u32 high;
    s16 dialog_id;

    if (arg1 == 0xB) {
        goto event_b;
    }
    dialog_id = *(s16 *)&arg2;
    switch (arg1) {
    case 0x1F:
        func_801015D0(arg0);
        if (((u16 (*)[4])D_80801344_chdinofamilymother)[(u32)*(u16 *)((u8 *)arg0 + 0x72) >> 10][0] != 0x3AC) {
            func_800DF744(2, 1);
            func_800DF744(3, 2);
            return 1;
        } else {
            func_800DF744(3, 1);
        }
        return 1;
    case 0x2E:
        switch (dialog_id) {
        case 0x17BA:
        case 0x17BB:
        case 0x1812:
        case 0x1813:
        case 0x1814:
            func_808005EC_chdinofamilymother(arg0, 2);
            return 1;
        case 0x17BC:
        case 0x1815:
            func_808005EC_chdinofamilymother(arg0, 3);
            return 1;
        case 0x17BD:
            func_808005EC_chdinofamilymother(arg0, 4);
            return 1;
        case 0x17BE:
        case 0x1816:
        case 0x1817:
            func_808005EC_chdinofamilymother(arg0, 5);
            return 1;
        case 0x17BF:
        case 0x17C0:
            func_808005EC_chdinofamilymother(arg0, 1);
            return 1;
        case 0x17C1:
        case 0x180A:
            func_808005EC_chdinofamilymother(arg0, 7);
            return 1;
        case 0x17C2:
        case 0x17C6:
        case 0x1818:
            func_808005EC_chdinofamilymother(arg0, 9);
            if (_glcutDll_entrypoint_23()) {
                _glcutDll_entrypoint_17();
                return 1;
            }
            goto dialog_done;
        case 0x1208:
            func_80801228_chdinofamilymother(arg0);
            return 1;
        case 0x17C3:
        case 0x17C4:
        case 0x17C5:
            func_808005EC_chdinofamilymother(arg0, 1);
            return 1;
        }
        func_80801228_chdinofamilymother(arg0);
    dialog_done:
        return 1;
    event_b:
        switch (arg2) {
        case 9:
            func_808005EC_chdinofamilymother(arg0, 9);
            break;
        case 0:
        case 2:
        case 4:
            func_8080119C_chdinofamilymother(arg0, 2, 1, 0);
            break;
        }
        return 4;
    case 0x52:
        _gcdialogcamera_entrypoint_4(D_808013D0_chdinofamilymother);
        _gcdialogcamera_entrypoint_3(D_808013DC_chdinofamilymother, *(f32 *)((u8 *)arg0 + 0x38));
        return 3;
    case 0x57:
        low = arg2 & 0xFFFF;
        high = (u32)(arg2 & 0xFFFF0000) >> 16;
        if (_gcdialogcamera_entrypoint_0(low, high)) {
            func_8080119C_chdinofamilymother(arg0, low, high, 0);
            return 2;
        }
        return 1;
    case 0x33:
        if (func_800DA298(0x15E) && !func_800DA298(0x189) && func_800DA298(0x15F) && func_800DA298(0x8A)) {
            func_808005EC_chdinofamilymother(arg0, 6);
            return 1;
        }
        func_808005EC_chdinofamilymother(arg0, 8);
        switch (arg2) {
        case 0:
            _subaddiedialog_entrypoint_11(*(Unk80132ED0 **)arg0, 0x17C3, 0xC, (f32 *)((u8 *)arg0 + 0x18), 0x65);
            break;
        case 1:
            _subaddiedialog_entrypoint_11(*(Unk80132ED0 **)arg0, 0x17C4, 0xC, (f32 *)((u8 *)arg0 + 0x18), 0x65);
            func_8080119C_chdinofamilymother(arg0, 3, 1, 0x2000);
            break;
        case 2:
            _subaddiedialog_entrypoint_11(*(Unk80132ED0 **)arg0, 0x17C5, 0xC, (f32 *)((u8 *)arg0 + 0x18), 0x65);
            break;
        }
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/dino/familymother/func_808005EC_chdinofamilymother.s")

void func_808008E4_chdinofamilymother(s32 arg0) {
    typedef struct { s32 x, y, z; } Vec;
    s32 func_8010C93C(s32, s32 *, s32);


    Vec sp24 = (*(Vec *)D_808013EC_chdinofamilymother);
    Vec sp18 = (*(Vec *)D_808013F8_chdinofamilymother);
    func_8010C93C(arg0, &sp24, 0x3DCCCCCD);
    func_8010C93C(arg0, &sp18, 0x3E99999A);
}

void func_8080096C_chdinofamilymother(Actor *arg0) {



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

    if (((u16 (*)[4])D_80801344_chdinofamilymother)[(u32)*(u16 *)((u8 *)arg0 + 0x72) >> 10][0] == 0x3AC) {
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


    return (OSThread *) D_80801474_chdinofamilymother;
}
