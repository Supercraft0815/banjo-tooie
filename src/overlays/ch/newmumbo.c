#include "common.h"

extern u32 D_80801A18_chnewmumbo[];
void func_80105834(Actor *);
void *func_80107C2C(s32 *, s32, void *, s32, void *);
void func_808004E8_chnewmumbo();
void func_808007FC_chnewmumbo(Actor *arg0, s32 arg1);
void func_8080092C_chnewmumbo(Actor *arg0);
void func_8080172C_chnewmumbo(Actor* arg0);
void func_80801760_chnewmumbo(Actor *arg0);

u32 D_80801990_chnewmumbo[] = {
    0x00130441, 0x00161770, 0x00000000,
};

u32 D_8080199C_chnewmumbo[] = {
    0x00130442, 0x00161770, 0x00000000,
};

u32 D_808019A8_chnewmumbo[] = {
    0x0013054D, 0x00164650, 0x00000000,
};

u32 D_808019B4_chnewmumbo[] = {
    0x00130404, 0x00165DC0, 0x00000000,
};

u32 D_808019C0_chnewmumbo[] = {
    0x00130404, 0x00180000,
};

u32 D_808019C8_chnewmumbo[] = {
    0x00130511, 0x00164650, 0x00000000,
};

u32 D_808019D4_chnewmumbo[] = {
    0x0013062B, 0x000D00F3, 0x010C0016, 0x46500000,
};

u32 D_808019E4_chnewmumbo[] = {
    0x001305AF, 0x000D00F3, 0x010C0016, 0x46500000,
};

f32 D_808019F4_chnewmumbo[] = {
    0.0f, -30.0f, -275.0f,
};

u32 D_80801A00_chnewmumbo[] = {
    0x00000000, 0x42860000, 0xC3DC0000,
};

u32 D_80801A0C_chnewmumbo[] = {
    0x00000000, 0xC2880000, 0xC2C80000,
};

u32 D_80801A18_chnewmumbo[] = {
    0x00000000, 0x00000000, 0x40400000, 0x01AF0001,
    0x40400000, 0x01AF0001, 0x40DAA7F0, 0x03010001,
    0x40C0F5C3, 0x00B50001, 0x40400000, 0x01AF0001,
    0x40800000, 0x01B00002, 0x3FC00000, 0x01B10002,
    0x40751EB8, 0x01B20001, 0x40470A3D, 0x00FD0002,
    0x40DAA7F0, 0x03010001, 0x40DAA7F0, 0x03010001,
    0x40DAA7F0, 0x03010001, 0x3FB33333, 0x01B30002,
    0x40400000, 0x01AF0001, 0x40400000, 0x01AF0001,
    0x40400000, 0x01AF0001, 0x407D70A4, 0x00CE0002,
    0x3FE66666, 0x00CF0202, 0x40C0F5C3, 0x00B50001,
};

u32 D_80801AB8_chnewmumbo[] = {
    0x43988000, 0x436B0000, 0x436B0000, 0x43070000,
};

u32 D_80801AC8_chnewmumbo[] = {
    0x00000000, 0x00000000, 0xC3C80000,
};

u32 D_80801AD4_chnewmumbo[] = {
    0x00000000, 0xC2880000, 0xC2B40000,
};

u32 D_80801AE0_chnewmumbo[] = {
    0x3EF5A858, 0x3F051EB8, 0x3F0F5C29, 0xBF800000,
};

u32 D_80801AF0_chnewmumbo[] = {
    0x3E8F9DB2, 0x3EEB851F, 0xBF800000,
};

u32 D_80801AFC_chnewmumbo[] = {
    0xC2820000, 0x42480000, 0xC4080000,
};

u32 D_80801B08_chnewmumbo[] = {
    0x42820000, 0x428C0000, 0xC3CD0000,
};

u32 D_80801B14_chnewmumbo[] = {
    0x02250190, 0x06650001, (u32)D_80801A18_chnewmumbo, (u32)func_8080092C_chnewmumbo,
    (u32)func_80105834, (u32)func_808007FC_chnewmumbo, 0x00000000, 0x00000000,
    0x00000000, 0x20080164, (u32)func_8080172C_chnewmumbo, 0x00000000,
    0x00280000, (u32)func_80801760_chnewmumbo, (u32)func_80107C2C, 0x80000002,
    (u32)func_808004E8_chnewmumbo, 0x00000000, 0x00000000,
};

void *func_80100094(Actor *, u32);

void func_80800000_chnewmumbo(Actor *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_2(Unk80132ED0 *, u32, s32);
    void _capod_entrypoint_7(s32, s32);
    s32 _capod_entrypoint_8(s32);
    void _gcdialogcamera_entrypoint_6(Unk80132ED0 *);
    void _gcdialogcamera_entrypoint_8(void);
    u8 *data;

    data = func_80100094(arg0, 0U);
    switch (data[0x24]) {
        case 0:
            _capod_entrypoint_2(arg0->unk0, 0xA, 0);
        case 1:
            _capod_entrypoint_8(1);
            data[0x24] = 2;
            _gcdialogcamera_entrypoint_6(arg0->unk0);
            _gcdialogcamera_entrypoint_8();
        case 2:
            _capod_entrypoint_7(arg1, arg2);
            break;
    }
}

void func_8080009C_chnewmumbo(Actor *arg0) {
    void _capod_entrypoint_3(u32);
    u8 *sp1C[1];
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    if ((*(u8 *)((s8 *)(temp_v0) + 0x24)) != 0) {
        sp1C[0] = temp_v0;
        _capod_entrypoint_3(0U);
        temp_v0 = sp1C[0];
        (*(s8 *)((s8 *)(temp_v0) + 0x24)) = 0;
    }
}

void func_808000DC_chnewmumbo(Actor *arg0, u32 arg1, u32 arg2) {
    arg0->unk74_30 = 1;
    _subaddiedialog_entrypoint_11(arg0->unk0, arg1, arg2, arg0->position, 0x10U);
}

s32 func_8080011C_chnewmumbo(void) {
    s32 func_800DA298(s32);
    s32 func_800EA05C();

    if (func_800DA298(0x9C5) == 0) {
        return 0;
    }
    switch (func_800EA05C()) {
        case 0xB7: return 0x37F;
        case 0xD9: return 0x380;
        case 0x176: return 0x381;
        case 0xEF: return 0x382;
        case 0x171: return 0x383;
        case 0x172: return 0x387;
        case 0x134: return 0x384;
        case 0x13E:
        case 0x13F: return 0x385;
        case 0x156: return 0x386;
    }
    return 0;
}

void func_80800210_chnewmumbo(s32 *arg0) {
    s32 func_8008F8B0();
    s32 func_8008F8D8(s32);
    s32 func_8008F904(s32 *, s32);
    s32 func_8008F938(s32);
    s32 func_8008F990(s32 *, s32);
    extern s32 func_8010D5DC;
    func_8008F8B0();
    func_8008F8D8(1);
    func_8008F938(1);
    func_8008F904(&func_8010D5DC, *arg0);
    func_8008F990(&(*(s32 *)D_80801A0C_chnewmumbo), 0x43480000);
}

void func_80800264_chnewmumbo(Actor *arg0, s32 arg1) {
    struct MumboFlags {
        u8 pad[0x70];
        u32 : 9;
        u32 enabled : 1;
        u32 : 22;
        u32 : 28;
        u32 mode : 4;
        u16 pad78;
        u16 : 2;
        u16 flags : 2;
        u16 : 12;
    };
    s32 func_800DA298(s32);
    s32 func_800DA9E4(s32, s32);
    void func_80090590(s32, f32 *);
    void func_8080073C_chnewmumbo(Actor *, s32);
    s32 _suexpression_entrypoint_12(void *, f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    u8 *data;

    data = func_80100094(arg0, 0);
    if (arg0->unk70_10 == 6) {
        ((struct MumboFlags *)arg0)->mode = 1;
    }
    if (func_800DA298(0x9C6)) {
        func_80102424(arg0, arg1);
        switch (arg0->unk70_10) {
        case 1:
            data[1] = 1;
            data[2] = 0;
            break;
        case 2:
        case 3:
        case 4:
            func_80800210_chnewmumbo((s32 *)arg0);
            break;
        case 5:
            func_8080073C_chnewmumbo(arg0, func_80090178(1));
            func_80800000_chnewmumbo(arg0, 2, 1);
            break;
        case 6:
            ((struct MumboFlags *)arg0)->mode = 1;
            arg0->unk7A_11 = 3;
            ((struct MumboFlags *)arg0)->flags = 3;
            arg0->unk6C_0 = 0;
            ((struct MumboFlags *)arg0)->enabled = 1;
            break;
        case 7:
            ((struct MumboFlags *)arg0)->mode = 1;
            if (!func_800DA9E4(0x7D, 1)) {
                func_808000DC_chnewmumbo(arg0, 0x11D6, 7);
            } else {
                func_808000DC_chnewmumbo(arg0, 0x11E4, 7);
            }
            _suexpression_entrypoint_12(func_80100094(arg0, 1), 60.0f, 0.0f);
            break;
        case 8:
            if (func_800D1A04(0x48) > 0) {
                func_808000DC_chnewmumbo(arg0, 0x11D7, 0x46);
            } else {
                func_808000DC_chnewmumbo(arg0, 0x11DA, 7);
            }
            break;
        case 18:
            data[1] = 0;
            func_800EE7F8(arg0->position, D_808019F4_chnewmumbo);
            break;
        case 19:
            data[2] = 1;
            data[1] = 0;
            break;
        case 14:
            func_8080009C_chnewmumbo(arg0);
            func_800904C8(0x8D);
            func_80090590(0x3C, arg0->position);
            data[0] = 1;
            if (!func_800DA9E4(0x429, 1)) {
                func_80800000_chnewmumbo(arg0, 5, 1);
                func_808000DC_chnewmumbo(arg0, 0x11E6, 15);
            }
            break;
        case 10:
        case 11:
            data[1] = 1;
            data[2] = 0;
            func_8080009C_chnewmumbo(arg0);
            break;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/newmumbo/func_808004E8_chnewmumbo.s")

/* extern */

void func_8080073C_chnewmumbo(Actor *arg0, s32 arg1) {
    s32 _plsu_entrypoint_1(s32);
    u32 func_800F54E4(void);
    void func_800F7B9C(s32, u32);
    void func_800F8300();
    if (!arg0->unk64_19) {
        if (arg1 != 0) {
            func_800F7B9C(_plsu_entrypoint_1(1), 0x8D);
        }
        func_800F8300(func_800F54E4(), 2, arg0->position);
        arg0->unk64_19 = 1;
    }
}

void func_808007B0_chnewmumbo(u8 *arg0) {
    struct Flags { unsigned int : 12; unsigned int active : 1; unsigned int : 18; };
    u32 func_800F54E4(void);
    void func_800F82D4(s32, s32);
    if (((struct Flags *)(arg0 + 0x64))->active) {
        func_800F82D4(func_800F54E4(), 0);
        arg0[0x65] &= 0xFFF7;
    }
}

void func_808007FC_chnewmumbo(Actor *arg0, s32 arg1) {
    void func_800DBEFC(s32 *, s32, s32);
    void func_801017D0(Actor *);
    void func_80101808(Actor *, void (*)(Actor *));
    u8 *data;
    u8 *sp1C;

    data = func_80100094(arg0, 0);
    if (data[0] == 0) {
        sp1C = data;
        func_80101808(arg0, func_801017D0);
        if (sp1C[1] != 0 && arg0->unk7C_12) {
            func_800DBEFC(arg0->unk0->unk4, 0xB, (s32)(sp1C + 4));
        }
    }
}

void func_80800878_chnewmumbo(s32 arg0)
{
    func_80800264_chnewmumbo(arg0,0xE);
}

void func_80800898_chnewmumbo(Actor *arg0) {
    s32 i;
    f32 target;
    f32 current;
    f32 delta;

    for (i = 0; i != 3; i++) {
        target = ((f32 *)D_80801A00_chnewmumbo)[i];
        current = arg0->position[i];
        if (target != current) {
            delta = (target - current) * 0.25f;
            arg0->position[i] = current + delta;
        }
    }
    if (arg0->rotation[1] != 0.0f) {
        arg0->rotation[1] *= 0.25f;
    }
    if (arg0->rotation[0] != 0.0f) {
        arg0->rotation[0] *= 0.25f;
    }
}

void func_8080092C_chnewmumbo(Actor *arg0) {
    s32 _chjujubagfx_entrypoint_2(void);
    s32 _plsu_entrypoint_1(s32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 _subaddiedialog_entrypoint_3(f32 *, s32, s32, s32, s32);
    s32 _subaddiedialog_entrypoint_6(f32 *, s32, s32, s32, s32);
    void _suexpression_entrypoint_10(u32 *, Unk80132ED0 *, u32);
    s32 _suexpression_entrypoint_12(void *, f32, f32);
    f32 func_80013728(f32);
    s32 func_8008FB10(f32 *, f32, f32, f32);
    s32 func_8008FD70(void);
    Unk80132ED0 *func_8008FDEC(void);
    s32 func_8008FE14(void);
    f32 func_8008FEF0(void);
    f32 func_80090010(void);
    s32 func_80090248(void);
    s32 func_800902E4(f32 *, f32, s32, Actor **);
    void func_80090658(s32);
    s32 func_80090768(f32 *);
    s32 func_80090818(void);
    s32 func_800C0638(void);
    void func_800D175C(s32, s32);
    void func_800D1824(s32);
    f32 func_800D8FF8(void);
    s32 func_800DA298(s32);
    s32 func_800DA544(s32);
    int func_800DC298(f32);
    void func_800EE7F8(f32 *, f32 *);
    s32 func_800EFED0(f32 *, f32 *, f32 *);
    s32 func_800F6D24(s32);
    void func_800F7B9C(s32, u32);
    void func_800F8804(s32, f32 *);
    void func_800FC6B0(s32);
    s32 func_80101DDC(Actor *);
    s32 func_80101E14(Actor *, f32);
    s32 func_80101E4C(Actor *, f32 *);
    Actor *func_80106790(Unk80132ED0 *);
    s32 func_8010C9FC(f32 *, s32, s32, s32);
    void func_8010D254(f32 *);
    s32 func_8010D278(void);
    struct Vector { f32 v[3]; };
    struct MumboActorData { f32 position[3]; f32 timer; };
    struct MumboData { u8 unk0, unk1, unk2, unk3; f32 position[3]; };
    struct MumboFlags {
        u8 prefix[0x74];
        u32 pad74_4 : 28;
        u32 animationMode : 4;
        u32 pad78_14 : 18;
        u32 eyeDirection : 2;
        u32 eyeFrame : 3;
        u32 pad78_0 : 9;
    };
    struct Vector sp6C = (*(struct Vector *)D_80801AD4_chnewmumbo);
    f32 sp60[3];
    struct MumboData *sp5C;
    s32 sp58;
    f32 sp4C[3];
    Actor *sp48;
    s32 sp44;
    f32 sp38[3];
    f32 sp2C[3];

    sp5C = func_80100094(arg0, 0U);
    if (func_800C0638() != 0) { ((struct MumboActorData *)arg0->actorData)->timer = 1.5; }
    else if (((struct MumboActorData *)arg0->actorData)->timer > 0.0f) {
        ((struct MumboActorData *)arg0->actorData)->timer -= func_800D8FF8();
    }
    if (!func_800DA298(func_8080011C_chnewmumbo()) && ((struct MumboActorData *)arg0->actorData)->timer <= 0.0f) {
        func_800D1824(0x48);
    }
    if (func_8010D278() == 0xD) {
        func_8010D254(sp4C);
        sp58 = _plsu_entrypoint_1(1);
        if (func_800F6D24(sp58)) {
            func_800F8804(sp58, sp4C);
        }
    }
    if (sp5C->unk0 == 0) {
        func_8008FB10(arg0->position, arg0->scale * 150.0f, arg0->scale * -75.0f, arg0->scale * 100.0f);
    }
    func_8010D254(sp60);
    _suexpression_entrypoint_10(func_80100094(arg0, 1U), arg0->unk0, 0);
    switch (arg0->unk70_10) {
    case 19:
        switch (func_8008FD70()) {
        case 1:
            if (!arg0->unk74_30 && _subaddiedialog_entrypoint_6(arg0->position, (s32)arg0->rotation[1], 750, 90, 6)) {
                func_80800264_chnewmumbo(arg0, 4);
            }
            break;
        case 0x200:
        case 0x400:
            if (!arg0->unk74_30 && _subaddiedialog_entrypoint_6(arg0->position, (s32)arg0->rotation[1], 750, 90, 6)) {
                func_80800000_chnewmumbo(arg0, 2, 1);
                func_808000DC_chnewmumbo(arg0, 0x11EB, 0xF);
            }
            break;
        }
        break;
    case 1:
        ((struct MumboFlags *)arg0)->animationMode = 2;
        if (func_80101E14(arg0, 0.3f)) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, ((u8 *)D_80801990_chnewmumbo));
        } else if (func_80101E14(arg0, 0.7f)) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, ((u8 *)D_8080199C_chnewmumbo));
        }
        switch (func_8008FD70()) {
        case 1:
        case 0x200:
        case 0x400:
            if (_subaddiedialog_entrypoint_3(arg0->position, (s32)arg0->rotation[1], 500, 90, 6)) {
                func_80800264_chnewmumbo(arg0, 2);
            }
            break;
        }
        break;
    case 2:
        if (func_80101E14(arg0, 0.3f)) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, ((u8 *)D_80801990_chnewmumbo));
        } else if (func_80101E14(arg0, 0.7f)) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, ((u8 *)D_8080199C_chnewmumbo));
        }
        break;
    case 5:
        if (func_80101E14(arg0, 0.999f)) {
            func_80800264_chnewmumbo(arg0, 6);
        }
        break;
    case 6:
        if (func_80101E14(arg0, 0.2f)) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, ((u8 *)D_808019A8_chnewmumbo));
        }
        if (arg0->unk6C_0 < 100) {
            arg0->unk6C_0++;
            if (arg0->unk6C_0 < 20) {
                arg0->unk7A_11 = 3;
            } else if (arg0->unk6C_0 < 40) {
                arg0->unk7A_11 = 2;
            } else if (arg0->unk6C_0 < 60) {
                arg0->unk7A_11 = 1;
            } else {
                arg0->unk7A_11 = 0;
                ((struct MumboFlags *)arg0)->eyeDirection = 1;
            }
        } else if (func_800DC298(0.3f) && arg0->unk7A_11 < 3) {
            ((struct MumboFlags *)arg0)->eyeDirection = 1;
        } else if (func_800DC298(0.05f) && arg0->unk7A_11 > 0) {
            ((struct MumboFlags *)arg0)->eyeDirection = 2;
        }
        if (func_80101E14(arg0, 0.999f)) {
            switch (func_8008FD70()) {
            case 1:
                func_80800264_chnewmumbo(arg0, 7);
                break;
            case 0x200:
            case 0x400:
                func_808007B0_chnewmumbo(arg0);
                func_808000DC_chnewmumbo(arg0, 0x11EB, 0xF);
                func_80800264_chnewmumbo(arg0, 11);
                break;
            default:
                func_80800264_chnewmumbo(arg0, 11);
                break;
            }
        }
        break;
    case 7:
        if (func_80101E14(arg0, 0.999f)) {
            func_80800264_chnewmumbo(arg0, 8);
        }
        break;
    case 8:
        if (!func_800DA298(func_8080011C_chnewmumbo())) {
            switch (sp5C->unk3) {
            case 0:
                break;
            case 1:
                func_808007B0_chnewmumbo(arg0);
                func_80090658(1);
                sp5C->unk3 = 2;
                break;
            case 2:
                if (arg0->unk7C_12 && func_800902E4(arg0->position, 750.0f, 0x29F, &arg0)
                    && func_8008FE14() == 0x29F && func_80090818()) {
                    arg0->unk3C = func_8008FDEC();
                    func_80090768(sp5C->position);
                    sp5C->unk3 = 3;
                }
                break;
            case 3:
                sp48 = func_80106790(arg0->unk3C);
                func_800EE7F8((f32 *)sp48->actorData, sp5C->position);
                sp48->unk74_30 = 1;
                sp48->unk64_19 = 1;
                sp5C->unk3 = 4;
                func_8080073C_chnewmumbo(arg0, 1);
                func_80090658(0);
                break;
            case 4:
                func_80800264_chnewmumbo(arg0, 13);
                sp5C->unk3 = 0;
                break;
            }
        }
        break;
    case 13:
        if (func_80101E14(arg0, 0.7f)) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, ((u8 *)D_808019C0_chnewmumbo));
            _chjujubagfx_entrypoint_2();
        }
        if (func_80101E14(arg0, 0.999f)) {
            func_800FC6B0(0x10);
            func_80800264_chnewmumbo(arg0, 17);
            func_80800000_chnewmumbo(arg0, 2, 1);
            func_800DA544(func_8080011C_chnewmumbo());
            func_800D175C(0x48, -1);
        }
        break;
    case 17:
        if (func_80101E14(arg0, 0.05f)) {
            func_800DA544(0x9F3);
        } else if (func_80101DDC(arg0)) {
            func_80800264_chnewmumbo(arg0, 18);
        } else if (func_80101E14(arg0, 0.87f)) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, ((u8 *)D_808019B4_chnewmumbo));
        } else if (func_80101E14(arg0, 0.76f)) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, ((u8 *)D_808019C8_chnewmumbo));
        } else if (func_80101E4C(arg0, ((f32 *)D_80801AE0_chnewmumbo))) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, ((u8 *)D_808019D4_chnewmumbo));
        }
        break;
    case 18:
        if (func_80101E14(arg0, 0.79f)) {
            sp5C->unk2 = 1;
        } else if (func_80101E14(arg0, 0.999f)) {
            func_80800878_chnewmumbo(arg0);
        } else if (func_80101E4C(arg0, ((f32 *)D_80801AF0_chnewmumbo))) {
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, ((u8 *)D_808019E4_chnewmumbo));
        }
        break;
    case 14:
        if (!func_8010C9FC(arg0->position, 450, 500, 150)) {
            func_80800264_chnewmumbo(arg0, 15);
        }
        break;
    case 15:
        if (func_800EFED0(((f32 *)D_80801AFC_chnewmumbo), ((f32 *)D_80801B08_chnewmumbo), sp60) && func_80090248()) {
            func_8010D254(sp38);
            func_800F7B9C(_plsu_entrypoint_1(1), 0x3D);
            sp5C->unk0 = 0;
            func_80800264_chnewmumbo(arg0, 16);
            func_800EE7F8(arg0->position, sp38);
            func_808007B0_chnewmumbo(arg0);
        }
        break;
    case 16:
        arg0->rotation[1] = func_80013728(func_80090010());
        arg0->rotation[0] = func_8008FEF0();
        func_80800264_chnewmumbo(arg0, 9);
        break;
    case 9:
        func_80800898_chnewmumbo(arg0);
        if (func_80101E14(arg0, 0.21f)) {
            sp5C->unk2 = 0;
        }
        if (func_80101E14(arg0, 0.83f)) {
            sp5C->unk1 = 1;
        }
        if (func_80101DDC(arg0)) {
            func_80800264_chnewmumbo(arg0, 10);
            _suexpression_entrypoint_12(func_80100094(arg0, 1U), 0.0f, 0.0f);
        }
        break;
    case 10:
        func_8010D254(sp2C);
        func_80800898_chnewmumbo(arg0);
        func_80800264_chnewmumbo(arg0, 11);
        break;
    case 11:
        switch (func_8008FD70()) {
        case 1:
            if (!arg0->unk74_30 && _subaddiedialog_entrypoint_6(arg0->position, (s32)arg0->rotation[1], 750, 90, 6)) {
                func_80800264_chnewmumbo(arg0, 3);
            }
            break;
        case 0x200:
        case 0x400:
            if (!arg0->unk74_30 && _subaddiedialog_entrypoint_6(arg0->position, (s32)arg0->rotation[1], 750, 90, 6)) {
                func_80800000_chnewmumbo(arg0, 2, 1);
                func_808000DC_chnewmumbo(arg0, 0x11EB, 0xF);
            }
            break;
        }
        break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/newmumbo/func_808014FC_chnewmumbo.s")

void func_800EE7F8(f32 *, f32 *);
void chnewmumbo_entrypoint_0(Actor *arg0, f32 *arg1) { func_800EE7F8(arg1, (f32 *)((u8 *)func_80100094(arg0, 0U) + 4)); }

void func_8080172C_chnewmumbo(Actor* arg0) 
{
    if (func_80100094(arg0,1) != 0)
    {
        _suexpression_entrypoint_8(arg0, 1);
    }
}
void func_80801760_chnewmumbo(Actor *arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 _suexpression_entrypoint_7(Actor *, s32, s32);
    s32 func_800DA298(s32);
    s32 func_8010D278();
    s8 *data;

    data = func_80100094(arg0, 0U);
    func_800EE7F8(arg0->position, ((f32 *)D_80801A00_chnewmumbo));
    arg0->scale = 0.5f;
    _suexpression_entrypoint_7(arg0, 1, 0x10);
    if (func_8010D278() == 0xD) {
        *data = 1;
        func_80800264_chnewmumbo(arg0, 0xF);
    } else {
        *data = 0;
        if (func_800DA298(func_8080011C_chnewmumbo()) || _glcutDll_entrypoint_20()) {
            func_800EE7F8(arg0->position, ((f32 *)D_808019F4_chnewmumbo));
            func_80800264_chnewmumbo(arg0, 0x13);
        } else if (func_800DA298(0x7D)) {
            func_80800264_chnewmumbo(arg0, 0xA);
        } else {
            func_80800264_chnewmumbo(arg0, 1);
        }
    }
    arg0->rotation[0] = 0.0f;
}

OSThread *chnewmumbo_entrypoint_1(void)
{
    return (OSThread *) ((u8 *)D_80801B14_chnewmumbo);
}
