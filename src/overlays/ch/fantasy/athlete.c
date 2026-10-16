#include "common.h"
#include "core2/1E9A960.h"
#include "core2/1EB5980.h"
#include "core2/1EDB4D0.h"

extern u16 D_80803034_chfantasyathlete[][4];

/* extern */

void func_80800000_chfantasyathlete(s32 arg0, s32 arg1) {
    s32 func_800C78CC(s32);
    s32 func_800DA9E4(s32, s32);
    if (arg1 != 0) {
        if (func_800DA9E4(0xA51, 1) == 0) {
            func_800C78CC(1);
        }
    } else if (func_800DA9E4(0xA51, 0) != 0) {
        func_800C78CC(0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/athlete/func_80800060_chfantasyathlete.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/athlete/func_80800314_chfantasyathlete.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/athlete/func_8080094C_chfantasyathlete.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/athlete/func_80801114_chfantasyathlete.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/athlete/func_808011E4_chfantasyathlete.s")

/* extern */

void func_808015D8_chfantasyathlete(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 *arg4) {
    s32 func_800EE780(s32, s32, s32);
    f32 func_800EEAD4(s32, s32);
    s32 func_800EF2A0(s32);
    s32 func_800EF334(s32, s32);
    s32 func_800EFB24(s32, s32, s32);
    func_800EFB24(arg3, arg0, arg1);
    func_800EF2A0(arg3);
    func_800EE780(arg2, arg1, arg0);
    func_800EF334(arg2, 0x3F000000);
    *arg4 = func_800EEAD4(arg1, arg0) * 0.5f;
}

struct AthletePaths {
        u8 pad0[0x78];
        s32 unk78[7];
        f32 unk94[7];
};

void func_80801654_chfantasyathlete(s32 arg0, struct AthletePaths *data) {
    s32 _gccubesearch_entrypoint_9(s32, Prop **, s32);
    s32 _gspropctrl_entrypoint_8(Prop *);
    void _gspropctrl_entrypoint_11(Prop *, f32[3]);
    s32 _gspropctrl_entrypoint_12(Prop *);
    s32 _glsplinefind_entrypoint_3(f32 *);
    Prop *props[10];
    s32 i;
    s32 index;
    f32 position[3];
    s32 count;

    count = _gccubesearch_entrypoint_9(0x479, props, 10);
    for (i = 0; i < count; i++) {
            index = _gspropctrl_entrypoint_8(props[i]) - 50;
            _gspropctrl_entrypoint_11(props[i], position);
            data->unk94[index] = (f32)_gspropctrl_entrypoint_12(props[i]);
            data->unk78[index] = _glsplinefind_entrypoint_3(position);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/athlete/func_80801718_chfantasyathlete.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/athlete/func_808018B8_chfantasyathlete.s")

void func_80801974_chfantasyathlete(Actor *arg0) {
    switch (D_80803034_chfantasyathlete[arg0->unk70_10][0]) {
    case 0x3F9:
        if ((func_80101E14(arg0, 0.06f) != 0) || (func_80101E14(arg0, 0.26f) != 0) || (func_80101E14(arg0, 0.46f) != 0)) {
            func_800C4140(((u32) (u16) (func_800DC178(1.1f, 1.2f) * 1023.0f) << 0x15) + 0x1B5E23, arg0->position, 0x04B000FA);
        }
        if ((func_80101E14(arg0, 0.17f) != 0) || (func_80101E14(arg0, 0.37f) != 0) || (func_80101E14(arg0, 0.57f) != 0)) {
            func_800C4140(((u32) (u16) (func_800DC178(1.1f, 1.2f) * 1023.0f) << 0x15) + 0x1B5E24, arg0->position, 0x04B000FA);
        }
        if (func_80101E14(arg0, 0.7f) != 0) {
            func_800C4140(((u32) (u16) (func_800DC178(0.95f, 1.05f) * 1023.0f) << 0x15) + 0x1B5E26, arg0->position, 0x04B000FA);
            return;
        }
    default:
        return;
    case 0x3FA:
        if ((func_80101E14(arg0, 0.45f) != 0) || (func_80101E14(arg0, 0.95f) != 0)) {
            func_800C4140(((u32) (u16) (func_800DC178(0.9f, 1.1f) * 1023.0f) << 0x15) + 0x1F4404, arg0->position, 0x04B000FA);
        }
        if (func_80101E14(arg0, 0.4f) != 0) {
            func_800C4140(((u32) (u16) (func_800DC178(1.25f, 1.35f) * 1023.0f) << 0x15) + 0xBBD8A, arg0->position, 0x04B000FA);
        }
        if (func_80101E14(arg0, 0.9f) != 0) {
            func_800C4140(((u32) (u16) (func_800DC178(1.25f, 1.35f) * 1023.0f) << 0x15) + 0x1F58B, arg0->position, 0x04B000FA);
            return;
        }
        break;
    case 0x3FD:
        if (func_80101E14(arg0, 0.05f) != 0) {
            func_800C4140(((u32) (u16) (func_800DC178(0.95f, 1.05f) * 1023.0f) << 0x15) + 0x1B5E26, arg0->position, 0x04B000FA);
        }
        if (func_80101E14(arg0, 0.42f) != 0) {
            func_800C4140(((u32) (u16) (func_800DC178(0.75f, 0.85f) * 1023.0f) << 0x15) + 0x1B5E1F, arg0->position, 0x04B000FA);
        }
        if (func_80101E14(arg0, 0.66f) != 0) {
            func_800C4140(((u32) (u16) (func_800DC178(0.75f, 0.85f) * 1023.0f) << 0x15) + 0x1B5E1F, arg0->position, 0x04B000FA);
            return;
        }
        break;
    case 0x3FE:
        if (func_80101E14(arg0, 0.32f) != 0) {
            func_800C4140(((u32) (u16) (func_800DC178(0.55f, 0.65f) * 1023.0f) << 0x15) + 0x1B5E1E, arg0->position, 0x04B000FA);
            return;
        }
        if (func_80101E14(arg0, 0.1f) != 0) {
            func_800C4140(((u32) (u16) (func_800DC178(0.95f, 1.05f) * 1023.0f) << 0x15) + 0x1B5E25, arg0->position, 0x04B000FA);
            return;
        }
        break;
    case 0x3FC:
        if (func_80101E14(arg0, 0.1f) != 0) {
            func_800C4140(((u32) (u16) (func_800DC178(1.1f, 1.2f) * 1023.0f) << 0x15) + 0x138E23, arg0->position, 0x04B000FA);
        }
        if (func_80101E14(arg0, 0.17f) != 0) {
            func_800C4140(0x7FF38CD5, arg0->position, 0x04B000FA);
        }
        if (func_80101E14(arg0, 0.7f) != 0) {
            func_800C4140(((u32) (u16) (func_800DC178(1.25f, 1.35f) * 1023.0f) << 0x15) + 0x9C58B, arg0->position, 0x04B000FA);
            return;
        }
        break;
    case 0x3FF:
        if ((func_80101E14(arg0, 0.1f) != 0) || (func_80101E14(arg0, 0.42f) != 0) || (func_80101E14(arg0, 0.6f) != 0)) {
            func_800C4140(0x665B5E1F, arg0->position, 0x04B000FA);
            return;
        }
        break;
    case 0x400:
        if (func_80101E14(arg0, 0.34f) != 0) {
            func_800C4140(((u32) (u16) (func_800DC178(0.55f, 0.65f) * 1023.0f) << 0x15) + 0x1B5E1E, arg0->position, 0x04B000FA);
        }
        break;
    }
}


#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/athlete/func_80802730_chfantasyathlete.s")

void func_80802950_chfantasyathlete(Actor *arg0) {
    void func_80102BAC(Actor*, f32, f32, f32);
    void func_80102CCC(void *arg0);
    func_80102BAC(arg0, 0.2f, 0.1f, 10.0f);
    func_80102CCC(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fantasy/athlete/func_8080298C_chfantasyathlete.s")

void func_80802C18_chfantasyathlete(Actor *arg0, Unk80132ED0 *arg1, s32 arg2, s32 arg3) {
    void _capod_entrypoint_2(Unk80132ED0 *, u32, s32);
    void _capod_entrypoint_6(Unk80132ED0 *, s32, s32);

    switch (arg0->actorData[0]) {
        case 0:
            _capod_entrypoint_2(arg0->unk0, 0x2B, 0x10);
        case 1:
            arg0->actorData[0] = 2;
        case 2:
            _capod_entrypoint_6(arg1, arg2, arg3);
            break;
    }
}

void func_80802C94_chfantasyathlete(Actor *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_2(Unk80132ED0 *, u32, s32);
    void _capod_entrypoint_7(s32, s32);
    s32 _capod_entrypoint_8(s32);
    void _gcdialogcamera_entrypoint_6(Unk80132ED0 *);
    void _gcdialogcamera_entrypoint_8(void);

    switch (arg0->actorData[0]) {
        case 0:
            _capod_entrypoint_2(arg0->unk0, 0x2B, 0);
        case 2:
            _capod_entrypoint_8(1);
            arg0->actorData[0] = 1;
            arg1 = 2;
            arg2 = 1;
            _gcdialogcamera_entrypoint_6(arg0->unk0);
            _gcdialogcamera_entrypoint_8();
        case 1:
            _capod_entrypoint_7(arg1, arg2);
            break;
    }
}

/* extern */

void func_80802D38_chfantasyathlete(void *arg0) {
    s32 _capod_entrypoint_3(s32, void *);
    if ((*(s32 *)((s8 *)(arg0) + (0x18))) != 0) {
        _capod_entrypoint_3(0, arg0);
        (*(s32 *)((s8 *)(arg0) + (0x18))) = 0;
    }
}

/* extern */

void func_80802D74_chfantasyathlete(u8 *arg0) {
    void func_80802C94_chfantasyathlete(Actor *, s32, s32);
    if ((*(s32 *)((s8 *)(arg0) + (0x18))) != 1) {
        func_80802C94_chfantasyathlete(arg0, 2, 0);
    }
}

/* extern */

void func_80802DA8_chfantasyathlete(s32 arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 func_80800314_chfantasyathlete(s32);
    if (_glcutDll_entrypoint_20() != 0) {
        func_80800314_chfantasyathlete(arg0);
    }
}

OSThread *chfantasyathlete_entrypoint_0(void)
{
    extern u8 D_808031B4_chfantasyathlete[];

    return (OSThread *) D_808031B4_chfantasyathlete;
}
