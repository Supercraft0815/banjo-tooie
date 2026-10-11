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

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/sc/radar/func_80800768_scradar.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/sc/radar/func_808007D4_scradar.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/sc/radar/scradar_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/sc/radar/scradar_entrypoint_1.s")
