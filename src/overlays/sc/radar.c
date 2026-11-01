#include "common.h"

struct player_state_s;

struct RadarPoint { u8 data[16]; };
struct Radar {
    u8 pad[8];
    u8 alpha;
    u8 pad9;
    s16 asset;
    s16 count;
    s16 count2;
    struct RadarPoint points[6];
    struct RadarPoint points2[8];
};


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

void func_8080074C_scradar(void *arg0, u8 arg1, u8 arg2, u8 arg3) {
    ((u8 *)arg0)[0] = arg1;
    ((u8 *)arg0)[1] = arg2;
    ((u8 *)arg0)[2] = arg3;
}

/* extern */

s32 func_80800768_scradar(s32 arg0) {
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

void scradar_entrypoint_0(void) {
    u8 _gcstatusDll_entrypoint_16(s32 arg0);
    s32 func_80092258(void *arg0);
    void func_800A8A04(s32 arg0, s32 *arg1, s32 *arg2, s32 *arg3, s32 *arg4);
    s32 func_800A940C(s32 arg0);
    s32 func_800A9420(s32 arg0);
    s32 func_800A946C(void);
    struct player_state_s *func_800F53D0(s32 arg0);
    void func_800F5A00(s32, f32 *);
    f32 func_800F5F24(u32 arg0);
    s32 func_800F6438(u32 arg0);
    extern struct Radar B_80800E50_scradar[];
    extern s16 D_80800E30_scradar[];
    extern u8 D_80800E3C_scradar[][2];
    struct Radar *radar;
    struct Radar *initEntry;
    struct Radar *listEntry;
    struct RadarPoint *point;
    s32 i;
    s32 j;
    s32 player;
    s32 listIndex;
    s32 buffers;
    f32 angle;
    s32 x;
    s32 y;
    s32 w;
    s32 h;
    f32 pos[3];
    s32 mode = 0;
    u32 team;
    u8 alpha;
    buffers = func_800A946C();
    if (func_80800768_scradar(0) == 4) {
        mode = 1;
    }
    i = 0;
    if (buffers > 0) {
        do {
            team = _gcstatusDll_entrypoint_16(i);
            /* The indexed byte offset preserves IDO alias information for this table. */
            initEntry = (struct Radar *)((u8 *)B_80800E50_scradar + i * sizeof(struct Radar));
            initEntry->count = 1;
            initEntry->asset = D_80800E30_scradar[team];
            initEntry->count2 = 0;
            initEntry->alpha = D_80800E3C_scradar[team][mode];
            i++;
        } while (i != buffers);
    }
    for (player = 0; player < 8; player++) {
        if (func_800F6438(player)) {
            i = func_800A940C(player);
            listIndex = 0;
            team = _gcstatusDll_entrypoint_16(i);
            alpha = func_80092258(func_800F53D0(player));
            if (buffers > 0) {
                listEntry = B_80800E50_scradar;
                do {
                    if ((u32)_gcstatusDll_entrypoint_16(listIndex) == team) {
                        if ((listIndex == i) && func_800A9420(player)) {
                            point = &listEntry->points[0];
                            point->data[11] = 0xC0;
                        }
                        else {
                            point = (struct RadarPoint *) ((((listEntry->count++) << 4) + ((u8 *) listEntry)) + 0x10);
                            point->data[11] = 0x60;
                        }
                    }
                    else {
                        point = (struct RadarPoint *) ((((listEntry->count2++) << 4) + ((u8 *) listEntry)) + 0x70);
                        point->data[11] = alpha;
                    }
                    listIndex++;
                    listEntry++;
                    point->data[13] = player;
                } while (listIndex != buffers);
            }
        }
    }

    i = 0;
    if (buffers > 0) {
        do {
            radar = &B_80800E50_scradar[i];
            func_800A8A04(i, &x, &y, &w, &h);
            *((s32 *) (&radar->pad[0])) = ((w + x) - 25) << 2;
            *((s32 *) (&radar->pad[4])) = ((h + y) - 19) << 2;
            point = &radar->points[0];
            if (radar->count) {
                *((s16 *) (&radar->points[0].data[4])) = 0;
                *((s16 *) (&radar->points[0].data[6])) = 0;
                radar->points[0].data[12] = 0;
                func_800F5A00(radar->points[0].data[13], pos);
                angle = func_800F5F24(point->data[13]) + 180.0f;
                for (j = 1; j < radar->count; j++) {
                    point = (struct RadarPoint *) ((((u8 *) radar) + (j << 4)) + 0x10);
                    func_808007D4_scradar(point, pos, angle);
                    func_8080074C_scradar(&point->data[8], 255, 255, 255);
                }

                for (j = 0; j < radar->count2; j++) {
                    point = (struct RadarPoint *) ((((u8 *) radar) + (j << 4)) + 0x70);
                    func_8080074C_scradar(&point->data[8], 255, 32, 32);
                    func_808007D4_scradar(point, pos, angle);
                }

            }
            i++;
        } while (i != buffers);
    }
}

void scradar_entrypoint_1(Gfx **arg0) {
    s32 func_800A7180(void);
    s32 func_800A946C(void);
    void func_800B9990(Gfx **);
    s32 func_800D674C(s32);
    void func_800E2434(s32);
    void func_800E253C(f32);
    void func_800E257C(s32);
    s32 func_800E30E0(s32, s32, s32, void *);
    extern struct Radar B_80800E50_scradar[];
    Gfx *gfx;
    struct Radar *entry;
    struct Radar *entry2;
    s16 n;
    s32 buffers;
    s32 count;
    s32 j;
    s32 i;

    count = func_800A946C();
    for (i = 0; i < count; i++) {
        entry = &B_80800E50_scradar[i];
        if (entry->count != 0) {
            func_800E253C(1.25f);
            func_800E257C(entry->alpha);
            func_800E2434(1);
            buffers = func_800A7180();
            func_800E30E0(buffers, func_800D674C(entry->asset), 0, entry);
        }
    }
    func_800B9990(arg0);
    for (i = 0; i < count; i++) {
        entry2 = &B_80800E50_scradar[i];
        entry = entry2;
        if (entry2->count != 0) {
            for (j = 0; j < entry->count; j++) {
                func_80800000_scradar(arg0, entry2, (u8 *)entry2 + (j << 4) + 0x10);
            }
            for (j = 0; j < entry->count2; j++) {
                func_80800000_scradar(arg0, entry2, (u8 *)entry2 + (j << 4) + 0x70);
            }
        }
    }
    gDPPipeSync((*arg0)++);
    gDPSetCycleType((*arg0)++, G_CYC_2CYCLE);
}
