#include "common.h"

void func_80800000_scradar(Gfx **arg0, void *arg1, void *arg2) {
    typedef struct {
        f32 offset;
        s16 x;
        s16 y;
        u8 r, g, b, a;
        u8 type;
    } Radar;
    typedef struct { u32 x, y; } Origin;
    s32 func_8001210C(s32);
    s32 x;
    s32 y;
    Radar *radar = arg2;

    x = (radar->x + ((Origin *)arg1)->x) & ~3;
    y = (radar->y + ((Origin *)arg1)->y) & ~3;
    gDPPipeSync((*arg0)++);
    switch (radar->type) {
    case 0:
        gDPSetFogColor((*arg0)++, 255, 255, 255, 128);
        gSPTextureRectangle((*arg0)++, x - 4, y, x + 8, y + 4, 0, 0, 0, 256, 256);
        gSPTextureRectangle((*arg0)++, x, y - 4, x + 4, y + 8, 0, 0, 0, 256, 256);
        break;
    case 1:
    {
        s32 alpha = radar->a;
        gDPSetColor((*arg0)++, G_SETFOGCOLOR,
                    _SHIFTL(radar->b >> 2, 8, 8) | _SHIFTL(radar->r >> 2, 24, 8) |
                    _SHIFTL(radar->g >> 2, 16, 8) | (((alpha >> 1) + (alpha >> 2)) & 255));
        gSPTextureRectangle((*arg0)++, x - 8, y - 8, x + 8, y + 8, 0, 0, 0, 256, 256);
        gDPPipeSync((*arg0)++);
        gDPSetColor((*arg0)++, G_SETFOGCOLOR, _SHIFTL(radar->b, 8, 8) | _SHIFTL(radar->r, 24, 8) | _SHIFTL(radar->g, 16, 8) | _SHIFTL(alpha, 0, 8));
        gSPTextureRectangle((*arg0)++, x - 4, y - 4, x + 4, y + 4, 0, 0, 0, 256, 256);
        break;
    }
    case 2:
        if (func_8001210C(4)) {
            gDPSetColor((*arg0)++, G_SETFOGCOLOR, _SHIFTL(radar->b, 8, 8) | _SHIFTL(radar->r, 24, 8) | _SHIFTL(radar->g, 16, 8) | _SHIFTL(radar->a, 0, 8));
            gSPTextureRectangle((*arg0)++, x - 4, y, x + 8, y + 4, 0, 0, 0, 256, 256);
            gSPTextureRectangle((*arg0)++, x, y - 4, x + 4, y + 8, 0, 0, 0, 256, 256);
        }
        break;
    case 4:
    {
        s32 offset = radar->offset * 8.0f;
        gDPSetFogColor((*arg0)++, 0, 0, 0, radar->a >> 1);
        gSPTextureRectangle((*arg0)++, x - 6, y - 14, x + 6, y + 14, 0, 0, 0, 256, 256);
        gSPTextureRectangle((*arg0)++, x - 10, y + offset - 6, x + 10, y + offset + 6, 0, 0, 0, 256, 256);
        gDPPipeSync((*arg0)++);
    }
        /* fallthrough */
    case 3:
    {
        s32 offset = radar->offset * 8.0f;
        gDPSetColor((*arg0)++, G_SETFOGCOLOR, _SHIFTL(radar->b, 8, 8) | _SHIFTL(radar->r, 24, 8) | _SHIFTL(radar->g, 16, 8) | _SHIFTL(radar->a, 0, 8));
        gSPTextureRectangle((*arg0)++, x - 2, y - 10, x + 2, y + 10, 0, 0, 0, 256, 256);
        gSPTextureRectangle((*arg0)++, x - 6, y + offset - 2, x + 6, y + offset + 2, 0, 0, 0, 256, 256);
        break;
    }
    }
}

void func_8080074C_scradar(void *arg0, s8 arg1, s8 arg2, s8 arg3) {
    (*(s8 *)((s8 *)(arg0) + (0))) = arg1;
    (*(s8 *)((s8 *)(arg0) + (1))) = arg2;
    (*(s8 *)((s8 *)(arg0) + (2))) = arg3;
}

/* extern */

s32 func_80800768_scradar(s32 arg0) {
    struct player_state_s;
    s32 func_8009E674(struct player_state_s *, s32);
    struct player_state_s *func_800F53D0(s32);
    s32 func_800F5410(s32);

    switch (func_800F5410(arg0)) {
    case 0xC:
        return 3;
    case 6:
        return 4;
    default:
        if (func_8009E674(func_800F53D0(arg0), 0x20) != 0) {
            return 2;
        }
        return 1;
    }
}

void func_808007D4_scradar(void *arg0, f32 *arg1, f32 arg2) {
    f32 func_800136E4(f32);
    f32 func_80013788();
    f32 func_800137F4(f32);
    f32 func_80013B70(f32, f32, f32);
    void func_800EFB24(void *, void *, void *);
    f32 func_800F0DC0(f32, f32);
    void func_800F5A00(s32, f32 *);
    f32 sqrtf(f32);
    s32 player;
    f32 pos[3];
    f32 distance;
    f32 angle;

    player = *((u8 *)arg0 + 0xD);
    func_800F5A00(player, pos);
    func_800EFB24(pos, arg1, pos);
    distance = sqrtf(pos[0] * pos[0] + pos[2] * pos[2]);
    angle = func_800136E4(func_80013B70(pos[0], pos[2], distance) - arg2);
    if (distance > 5000.0f) {
        distance = 5000.0f;
    }
    distance *= 0.01f;
    *(s16 *)((u8 *)arg0 + 4) = (s32)(-func_800137F4(angle) * distance);
    *(s16 *)((u8 *)arg0 + 6) = (s32)(-func_80013788() * distance);
    *((u8 *)arg0 + 0xC) = func_80800768_scradar(player);
    switch (*((u8 *)arg0 + 0xC)) {
    default:
        angle = 0.0f;
        break;
    case 1:
    case 2:
        angle = 0.0f;
        break;
    case 3:
    case 4:
        angle = func_800F0DC0(pos[1] * 0.001f, 1.0f);
        break;
    }
    *(f32 *)arg0 = angle;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/sc/radar/scradar_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/sc/radar/scradar_entrypoint_1.s")
