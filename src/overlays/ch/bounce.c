#include "common.h"

void *func_80100094(Actor *, u32);

void chbounce_entrypoint_0(void) {
    extern f32 D_8012716C;
    f32 *temp_v0 = (f32 *)(u32)((u8 *)&D_8012716C + 28);
    temp_v0[0] = 0.0f;
    temp_v0[1] = 1.0f;
    temp_v0[2] = 0.0;
}

void chbounce_entrypoint_1(void) {
}

void chbounce_entrypoint_2(f32 arg0) {
    extern f32 D_8012716C;
    *(f32 *)((u8 *)&D_8012716C + 28) = arg0;
}

void chbounce_entrypoint_3(f32 arg0) {
    extern f32 D_8012716C;
    *(f32 *)((u8 *)&D_8012716C + 36) = arg0;
}

void chbounce_entrypoint_4(Actor *arg0, s32 *arg1) {
    void func_800EE84C(f32 dst[3], s32 src[3]);
    void chbounce_entrypoint_6(Actor *arg0, u32 arg1);
    f32 position[3];

    func_800EE84C(position, arg1);
    chbounce_entrypoint_6(arg0, (u32) position);
}

/* extern */

s32 func_80800078_chbounce(void) {
    u32 _gclevel_entrypoint_3(u32);
    s32 func_800D3E40(s32);
    s32 func_800DA9E4(s32, s32);
    f32 func_800DC0C0(void);
    s32 func_800EA068(s32);
    f32 sp24;
    s32 sp20;
    s32 sp1C;

    sp24 = func_800DC0C0();
    sp20 = _gclevel_entrypoint_3(0x10);
    sp1C = _gclevel_entrypoint_3(0x12);
    if (func_800D3E40(9) != 0) {
        return 0x229;
    }
    if (func_800EA068(0x8000) != 0) {
        return 0x229;
    }
    if ((sp20 == 0) && (sp1C == 0)) {
        return 0x229;
    }
    if (sp20 != 0) {
        if (func_800DA9E4(0x31, 1) == 0) {
            return 0x197;
        }
        if (sp24 < 0.049987793f) {
            return 0x197;
        }
        goto block_12;
    }
block_12:
    if (sp1C != 0) {
        if (func_800DA9E4(0x30, 1) == 0) {
            return 0x196;
        }
        if (sp24 < 0.049987793f) {
            return 0x196;
        }
        goto block_17;
    }
block_17:
    return 0x229;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bounce/func_80800190_chbounce.s")

void chbounce_entrypoint_5(s32 arg0, u8 *arg1) {
    extern s32 D_80801000_chbounce;
    u32* func_80800190_chbounce(Actor*, u32, u32);
    *(f32 *)((u8 *)&D_80801000_chbounce + arg0 * 0x24) = *(f32 *)(arg1 + 0x48);
    func_80800190_chbounce((Actor *)arg0, (u32)(arg1 + 4), (u32)arg1);
}

void chbounce_entrypoint_6(Actor *arg0, u32 arg1) {
    u32* func_80800190_chbounce(Actor*, u32, u32);
    func_80800190_chbounce(arg0, arg1, 0U);
}

s32 chbounce_entrypoint_7(s32 arg0, f32 *arg1, s32 arg2) {
    extern s16 D_80800FE2_chbounce;
    u32 *func_80800190_chbounce(Actor *, u32, u32);
    Actor *actor;
    struct {
        u8 pad[0x28];
        s16 sound;
        s16 volume;
        f32 pitch;
    } *data;

    *(s16 *)((u8 *)&D_80800FE2_chbounce + arg0 * 0x24) = arg2;
    actor = (Actor *)func_80800190_chbounce((Actor *)arg0, (u32)arg1, 0U);
    data = func_80100094(actor, 2U);
    switch (arg2) {
        case 0x1C9:
        case 0x1CA:
        case 0x1CB:
        case 0x1CC:
        case 0x1F4:
            data->sound = 0x404;
            data->pitch = 1.8f;
            data->volume = 0x4E20;
            break;
        case 0x136:
        case 0x3C6:
            data->sound = 0x404;
            data->pitch = 1.8f;
            data->volume = 0x4E20;
            break;
        case 0x21F:
            break;
        case 0x513:
            data->sound = 0x3E9;
            data->pitch = 1.0f;
            data->volume = 0x3E80;
            break;
        case 0x517:
            data->sound = 0x53D;
            data->pitch = 1.6f;
            data->volume = 0x3E80;
            break;
    }
    return (s32)actor;
}

s32 func_808007B8_chbounce(Actor *arg0, f32 *arg1, f32 *arg2, f32 *arg3, s32 arg4) {
    s32 *func_800BEF00(f32 *, f32 *, f32 *, s32);
    s32 func_800BF0E0(f32 *, f32 *, f32, f32 *, s32, s32);
    void *func_800C6A7C(f32 *, f32 *, f32 *, u32);
    void *func_800C6B78(f32 *, f32 *, f32, f32 *, s32, u32);
    s32 func_800CC338(f32 *, s32, s32);
    f32 func_800EC708(Unk80132ED0 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF2A0(f32 *);
    void func_800EFB24(void *, void *, void *);
    u32 func_8010A654(void ***, s32);
    u32 func_8010A698(void ***);
    s32 result;
    f32 radius;
    s32 pad[2];
    s32 saved;
    s32 index;
    struct { u8 pad[0x32]; u16 flags; } *data;
    struct {
        u8 pad[0x70];
        u32 sector : 7;
        u32 reserved : 15;
        u32 triangle : 6;
        u32 flags : 4;
    } *collision = (void *)arg0;

    data = func_80100094(arg0, 2);
    if (data->flags & 0x80) {
        if (arg0->unk70_25 != 0) {
            index = func_800CC338(arg2, arg0->unk70_25 - 1, collision->triangle - 1);
            if (index == -1) {
                func_800EFB24(arg3, arg2, arg1);
                func_800EF2A0(arg3);
                func_800EE7F8(arg2, arg1);
                return 1;
            }
            collision->triangle = index + 1;
        }
    }
    radius = func_800EC708(arg0->unk0) * 0.6666667f;
    arg1[1] += radius;
    arg2[1] += radius;
    if (arg4) {
        result = func_800BF0E0(arg1, arg2, radius, arg3, 3, arg0->unk14);
        if (result == 0) {
            result = (s32)func_800BEF00(arg1, arg2, arg3, arg0->unk14);
            if (result != 0) {
                func_800EF04C(arg2, arg3);
            }
        }
    } else {
        saved = func_8010A698(arg0);
        func_8010A654(arg0, 0);
        result = (s32)func_800C6B78(arg1, arg2, radius, arg3, 3, arg0->unk14);
        func_8010A654(arg0, saved);
        if (result == 0) {
            result = (s32)func_800C6A7C(arg1, arg2, arg3, arg0->unk14);
            if (result != 0) {
                func_800EF04C(arg2, arg3);
            }
        }
    }
    arg1[1] -= radius;
    arg2[1] -= radius;
    return result;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bounce/chbounce_entrypoint_8.s")

/* extern */

s32 chbounce_entrypoint_9(Actor *arg0) {
    return (s32) ((s8 *) func_80100094(arg0, 2U) + 0xC);
}

s32 chbounce_entrypoint_10(Actor *arg0) {
    return ((u32) (*(u32 *)((s8 *)(func_80100094(arg0, 2U)) + (0x24))) >> 0x1F) == 0;
}

void func_80800F74_chbounce(Actor *arg0) {
    u32* func_80100074(Actor*, u32, u32);
    (*(u8 *)((s8 *)(arg0) + (0x7B))) = (u8) ((*(u8 *)((s8 *)(arg0) + (0x7B))) & 0xFFF7);
    func_80100074(arg0, 2U, 0U);
}
