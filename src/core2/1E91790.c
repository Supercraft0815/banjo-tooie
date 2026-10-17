#include "core2/1E91790.h"
#include "common.h"

/* Operand order matches the game's display-list packing. */
#define textLoadTile(pkt, cmd, tile, uls, ult, lrs, lrt) { \
    Gfx *_g = (Gfx *)(pkt); \
    _g->words.w0 = _SHIFTL(cmd, 24, 8) | _SHIFTL(ult, 0, 12) | _SHIFTL(uls, 12, 12); \
    _g->words.w1 = _SHIFTL(tile, 24, 3) | _SHIFTL(lrt, 0, 12) | _SHIFTL(lrs, 12, 12); \
}

typedef struct {
    u8 imgWidth;
    u8 unk1;
    u8 width;
    u8 height;
    s32 offset;
} FontGlyph;

void *func_800B8148(u8 *ch);
FontGlyph *func_800B0D6C(void *font, s32 ch);
u8 *func_800B0D60(void *font);
f32 func_800DC178(f32, f32);

void func_800B7EA0(s32 arg0, s32 arg1) {
    void func_800AF614(Gfx **gfx, s16 *texture, s32 frameIndex, s32 tmem, s32 tile, s32 cms, s32 cmt, s32 *width, s32 *height);
    s32 sp38[2];
    s32 sp34;

    func_800AF614((Gfx **) arg0, (s16 *) func_800D674C(arg1), 0, 0x100, 1, 2, 2, &sp38[0], &sp34);
    D_801282C0.data[0xA] = (u8) sp38[0];
    D_801282C0.data[0xB] = (u8) sp34;
}

void func_800B7F14(Gfx **arg0) {
    s32 func_800D3724(s32);
    extern s32 D_8011A630;

    { Gfx *g = (*arg0)++; g->words.w0 = 0xDE000000; g->words.w1 = (u32)((u8 *)&D_8011A630 - (u8 *)0x80000000); }
    { Gfx *g = (*arg0)++;
    g->words.w0 = 0xE3001201;
    if (D_801282C0.data[6] == 1) {
        g->words.w1 = 0x2000;
    } else {
        g->words.w1 = 0;
    }
    }
    { Gfx *g = (*arg0)++;
    g->words.w0 = 0xFA000000;
    g->words.w1 = ((u32)D_801282C0.data[3] & 0xFF) | (u32)(((D_801282C0.data[1] & 0xFF) << 16) | ((D_801282C0.data[2] & 0xFF) << 8) | ((D_801282C0.data[0] & 0xFF) << 24)); }
    if (D_801282C0.data[9] != 0) {
        { Gfx *g = (*arg0)++;
        g->words.w0 = 0xE3000A01; g->words.w1 = 0x100000; }
        { Gfx *g = (*arg0)++;
        g->words.w0 = 0xFC117E03; g->words.w1 = 0xFF0FF3FF; }
        { Gfx *g = (*arg0)++;
        g->words.w0 = 0xE200001C; g->words.w1 = 0x0C184A40; }
        func_800B7EA0((s32)arg0, D_801282C0.data[9] + 0xC24);
    } else {
        { Gfx *g = (*arg0)++;
        g->words.w0 = 0xE3000A01; g->words.w1 = 0; }
        { Gfx *g = (*arg0)++;
        g->words.w0 = 0xFC119623; g->words.w1 = 0xFF2FFFFF; }
        { Gfx *g = (*arg0)++;
        g->words.w0 = 0xE200001C; g->words.w1 = 0x504A40; }
    }
    D_801282C0.data[5] = 1;
    D_801282C0.data[0xC] = func_800D3724(D_801282C0.data[6]);
}

void func_800B80D0(Gfx **arg0) {
    Gfx *g = (*arg0)++;
    g->words.w0 = 0xFA000000;
    g->words.w1 = ((u32)D_801282C0.data[3] & 0xFF) | (u32)(((D_801282C0.data[1] & 0xFF) << 16) | ((D_801282C0.data[2] & 0xFF) << 8) | ((D_801282C0.data[0] & 0xFF) << 24));
}

void func_800B811C(Gfx **arg0) {
    extern s32 D_8011A668;
    extern s8 D_801282C5;
    Gfx *v1 = (*arg0)++; v1->words.w0 = 0xDE000000; v1->words.w1 = (u32)((u8 *)&D_8011A668 - (u8 *)0x80000000); D_801282C5 = 0;
}

void *func_800B8148(u8 *ch) {
    s32 func_800B0D58(s16 *);
    s16 *func_800D3524(s32);
    s32 func_800D35D0();
    extern s32 D_801282D0;
    s32 sp1C;
    s16 *temp_v0;

    sp1C = func_800D35D0((u8) D_801282C6, *ch);
    if (sp1C == -1) {
        return NULL;
    }
    temp_v0 = func_800D3524((u8) D_801282C6);
    if (temp_v0 == NULL) {
        return NULL;
    }
    D_801282D0 = func_800B0D58(temp_v0);
    *ch = (u8) sp1C;
    return temp_v0;
}

s32 func_800B81CC(Gfx **gfx, s32 x, s32 y, u8 ch) {
    void *font;
    FontGlyph *glyph;
    Gfx *g;
    u8 *tex;
    f32 fx, fy, w, h;

    font = func_800B8148(&ch);
    if (font == NULL) {
        return 0;
    }
    glyph = func_800B0D6C(font, ch);
    tex = func_800B0D60(font) + glyph->offset;
    g = *gfx;
    /* IDO scheduling requires each load/sync trio to stay on one source line. */
    if (D_801282C0.unk10 == 0x800) {
        gDPSetTextureImage(g++, G_IM_FMT_RGBA, G_IM_SIZ_32b, glyph->imgWidth, tex + 0x80000000);
        gDPSetTile(g++, G_IM_FMT_RGBA, G_IM_SIZ_32b, ((glyph->width * 2 + 7) >> 3), 0, G_TX_LOADTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
        gDPLoadSync(g++); textLoadTile(g++, G_LOADTILE, G_TX_LOADTILE, 0, 0, (glyph->width - 1) << 2, (glyph->height - 1) << 2); gDPPipeSync(g++);
        gDPSetTile(g++, G_IM_FMT_RGBA, G_IM_SIZ_32b, ((glyph->width * 2 + 7) >> 3), 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
        textLoadTile(g++, G_SETTILESIZE, G_TX_RENDERTILE, 0, 0, (glyph->width - 1) << 2, (glyph->height - 1) << 2);
    } else if (D_801282C0.unk10 == 0x200) {
        gDPSetTextureImage(g++, G_IM_FMT_IA, G_IM_SIZ_16b, glyph->imgWidth, tex + 0x80000000);
        gDPSetTile(g++, G_IM_FMT_IA, G_IM_SIZ_16b, ((glyph->width * 2 + 7) >> 3), 0, G_TX_LOADTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
        gDPLoadSync(g++); textLoadTile(g++, G_LOADTILE, G_TX_LOADTILE, 0, 0, (glyph->width - 1) << 2, (glyph->height - 1) << 2); gDPPipeSync(g++);
        gDPSetTile(g++, G_IM_FMT_IA, G_IM_SIZ_16b, ((glyph->width * 2 + 7) >> 3), 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
        textLoadTile(g++, G_SETTILESIZE, G_TX_RENDERTILE, 0, 0, (glyph->width - 1) << 2, (glyph->height - 1) << 2);
    } else if (D_801282C0.unk10 == 0x100) {
        gDPSetTextureImage(g++, G_IM_FMT_IA, G_IM_SIZ_8b, glyph->imgWidth, tex + 0x80000000);
        gDPSetTile(g++, G_IM_FMT_IA, G_IM_SIZ_8b, ((glyph->width + 7) >> 3), 0, G_TX_LOADTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
        gDPLoadSync(g++); textLoadTile(g++, G_LOADTILE, G_TX_LOADTILE, 0, 0, (glyph->width - 1) << 2, (glyph->height - 1) << 2); gDPPipeSync(g++);
        gDPSetTile(g++, G_IM_FMT_IA, G_IM_SIZ_8b, ((glyph->width + 7) >> 3), 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
        textLoadTile(g++, G_SETTILESIZE, G_TX_RENDERTILE, 0, 0, (glyph->width - 1) << 2, (glyph->height - 1) << 2);
    } else if (D_801282C0.unk10 == 0x40) {
        gDPSetTextureImage(g++, G_IM_FMT_I, G_IM_SIZ_8b, glyph->imgWidth, tex + 0x80000000);
        gDPSetTile(g++, G_IM_FMT_I, G_IM_SIZ_8b, ((glyph->width + 7) >> 3), 0, G_TX_LOADTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
        gDPLoadSync(g++); textLoadTile(g++, G_LOADTILE, G_TX_LOADTILE, 0, 0, (glyph->width - 1) << 2, (glyph->height - 1) << 2); gDPPipeSync(g++);
        gDPSetTile(g++, G_IM_FMT_I, G_IM_SIZ_8b, ((glyph->width + 7) >> 3), 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
        textLoadTile(g++, G_SETTILESIZE, G_TX_RENDERTILE, 0, 0, (glyph->width - 1) << 2, (glyph->height - 1) << 2);
    } else if (D_801282C0.unk10 == 0x20) {
        gDPSetTextureImage(g++, G_IM_FMT_I, G_IM_SIZ_8b, (glyph->imgWidth >> 1), tex + 0x80000000);
        gDPSetTile(g++, G_IM_FMT_I, G_IM_SIZ_8b, (((glyph->width >> 1) + 7) >> 3), 0, G_TX_LOADTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
        gDPLoadSync(g++); textLoadTile(g++, G_LOADTILE, G_TX_LOADTILE, 0, 0, (glyph->width - 1) << 1, (glyph->height - 1) << 2); gDPPipeSync(g++);
        gDPSetTile(g++, G_IM_FMT_I, G_IM_SIZ_4b, (((glyph->width >> 1) + 7) >> 3), 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
        textLoadTile(g++, G_SETTILESIZE, G_TX_RENDERTILE, 0, 0, (glyph->width - 1) << 2, (glyph->height - 1) << 2);
    } else {
        return 0;
    }
    fx = x;
    w = glyph->width * D_801282C0.value;
    h = glyph->height * D_801282C0.value;
    if (D_801282C0.data[7] == 0 || D_801282C0.data[8] == 0) {
        fx -= w * 0.5f;
    }
    fy = y - glyph->unk1 * 0.5f;
    if (D_801282C0.data[4] != 0) {
        fx += func_800DC178(-2.0f, 2.0f);
        fy += func_800DC178(-2.0f, 2.0f);
    }
    /* Keep these rectangle command statements on separate source lines. */
    {
        Gfx *rect = g++;

        rect->words.w0 = _SHIFTL(G_TEXRECT, 24, 8)
            | _SHIFTL(MAX((s16)(s32)((fx + w) * 4.0f), 0), 12, 12)
            | _SHIFTL(MAX((s16)(s32)((fy + h) * 4.0f), 0), 0, 12);
        rect->words.w1 = _SHIFTL(G_TX_RENDERTILE, 24, 3)
            | _SHIFTL(MAX((s16)(s32)(fx * 4.0f), 0), 12, 12)
            | _SHIFTL(MAX((s16)(s32)(fy * 4.0f), 0), 0, 12);
        gImmp1(g++, G_RDPHALF_1,
            _SHIFTL(0 - (((s16)(s32)(fx * 4.0f) < 0)
                ? (((s16)(s32)(1024.0f / D_801282C0.value) < 0)
                    ? MAX(((s16)(s32)(fx * 4.0f) * (s16)(s32)(1024.0f / D_801282C0.value)) >> 7, 0)
                    : MIN(((s16)(s32)(fx * 4.0f) * (s16)(s32)(1024.0f / D_801282C0.value)) >> 7, 0)) : 0), 16, 16)
            | _SHIFTL(0 - (((s32)(fy * 4.0f) < 0)
                ? (((s16)(s32)(1024.0f / D_801282C0.value) < 0)
                    ? MAX(((s16)(s32)(fy * 4.0f) * (s16)(s32)(1024.0f / D_801282C0.value)) >> 7, 0)
                    : MIN(((s16)(s32)(fy * 4.0f) * (s16)(s32)(1024.0f / D_801282C0.value)) >> 7, 0)) : 0), 0, 16));
        gImmp1(g++, G_RDPHALF_2,
            _SHIFTL((s32)(1024.0f / D_801282C0.value), 16, 16)
            | _SHIFTL((s32)(1024.0f / D_801282C0.value), 0, 16));
    }
    *gfx = g;
    return w;
}

#undef textLoadTile

#ifndef NON_MATCHING
void func_800B8C50(void) {
    D_801282C0.data[2] = 0xFF;
    D_801282C0.data[1] = D_801282C0.data[2];
    D_801282C0.data[0] = D_801282C0.data[1];
    D_801282C0.data[3] = D_801282C0.data[0];
    D_801282C0.data[9] = 0;
    D_801282C0.data[7] = D_801282C0.data[9];
    D_801282C0.data[4] = D_801282C0.data[7];
    D_801282C0.data[6] = D_801282C0.data[4];
    D_801282C0.value = 1.0f;
}
#else
//Reset Text Parameters
void func_800B8C50(void)
{
	D_801282C0.data[2] = 0xFF;
	D_801282C0.data[1] = 0xFF;
	D_801282C0.data[0] = 0xFF;
	D_801282C0.data[3] = 0xFF;
	D_801282C0.data[9] = 0; //Color
	D_801282C0.data[7] = 0; 
	D_801282C0.data[4] = 0; //Shakiness
	D_801282C0.data[6] = 0; //Font
	D_801282C0.value = 1.0f; //Size
}
#endif

//Set Text Transparency
void func_800B8C8C(s32 Transparency)
{
	D_801282C0.data[3] = Transparency;
}

//Set Text Font
void func_800B8C98(s32 Font)
{
	D_801282C0.data[6] = Font;
}

//Set Text Shakiness
void func_800B8CA4(s32 shakiness)
{
	D_801282C0.data[4] = shakiness;
}

void func_800B8CB0(s32 unk)
{
	D_801282C0.data[7] = unk;
}

void func_800B8CBC(s8 arg0, s8 arg1, s8 arg2)
{
	D_801282C0.data[0] = arg0;
	D_801282C0.data[1] = arg1;
	D_801282C0.data[2] = arg2;
}

//Set Text Color
void func_800B8CE0(s32 color)
{
	D_801282C0.data[9] = color-0xC24;
}

//Set Text Size
void func_800B8CF0(f32 size)
{
	D_801282D4 = size;
}

s32 func_800B8CFC(u8 *arg0) {
    int func_800D36C4(s32, s32);
    s32 func_800E7188(u8 *);
    s32 temp_v0;
    s32 var_s1;
    s32 var_s2;
    s32 var_s3;

    var_s2 = 0;
    var_s3 = 0;
    for (var_s1 = 0; var_s1 < func_800E7188(arg0); var_s1++) {
        temp_v0 = func_800D36C4(D_801282C0.data[6], arg0[var_s1]);
        var_s2 = (s32) ((f32) var_s2 + ((f32) (temp_v0 + var_s3) * 0.5f));
        var_s3 = temp_v0;
    }
    return (s32) ((f32) var_s2 * D_801282C0.value);
}

void func_800B8DEC(Gfx **arg0, s32 arg1, s32 arg2, u8 arg3) {
    arg3 = (u8) arg3;
    if (D_801282C0.data[0xC] != 0) {
        D_801282C0.data[8] = 0;
        func_800B81CC(arg0, arg1, arg2, arg3);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E91790/func_800B8E28.s")

/* extern */

void func_800B8F88(s32 arg0, s32 arg1, u8 *arg2) {
    s32 func_800B8E28(s32, s32, s32, u8 *);
    func_800B8E28(arg0, (s32) (0x130 - func_800B8CFC(arg2)) / 2, arg1, arg2);
}

void func_800B8FE0(void) {
    extern s32 D_8012712C;

    D_8012712C = 0;
}

void func_800B8FEC(void) {
    s32 heap_free(void *);
    extern s32 D_80127128;
    if ((*(void **)((s8 *)(&D_80127128) + (0))) != NULL) {
        heap_free((*(void **)((s8 *)((*(void **)((s8 *)(&D_80127128) + (0)))) + (0x1C))));
        heap_free((*(void **)((s8 *)(&D_80127128) + (0))));
        (*(void **)((s8 *)(&D_80127128) + (0))) = NULL;
        (*(s32 *)((s8 *)(&D_80127128) + (4))) = 0;
    }
}

void func_800B9038(void) {
    typedef struct {
        f32 position[3];
        f32 velocity[3];
        u8 mode;
        void *particles;
    } Emitter;
    typedef struct {
        Emitter *emitter;
        s32 unk4;
        s32 unk8;
        s32 unkC;
    } State;
    void *heap_alloc(s32);
    extern s32 D_80127128;

    func_800B8FEC();
    ((State *)&D_80127128)->emitter = heap_alloc(sizeof(Emitter));
    ((State *)&D_80127128)->emitter->position[0] = ((State *)&D_80127128)->emitter->position[1] = ((State *)&D_80127128)->emitter->position[2] = 0.0f;
    ((State *)&D_80127128)->emitter->velocity[0] = ((State *)&D_80127128)->emitter->velocity[1] = ((State *)&D_80127128)->emitter->velocity[2] = 0.0f;
    ((State *)&D_80127128)->unkC = 0;
    ((State *)&D_80127128)->emitter->particles = heap_alloc(0x960);
    ((State *)&D_80127128)->emitter->mode = 0;
}

void func_800B90C8(void) {
    extern s32 D_80127128;
    if (D_80127128) ((u8 *)D_80127128)[0x18] = 1;
}

void func_800B90E8(void) {
    extern s32 D_80127128;
    if (D_80127128) ((u8 *)D_80127128)[0x18] = 2;
}

void func_800B9108(s32 arg0) {
    typedef struct { f32 position[3]; f32 velocity[3]; } Particle;
    typedef struct { f32 position[3]; f32 velocity[3]; u8 mode; Particle *particles; } Emitter;
    typedef struct { Emitter *emitter; s32 count; } State;
    s32 aligned4_memcpy(void *, void *, s32);
    extern s32 D_80127128;
    ((State *)&D_80127128)->count = ((State *)&D_80127128)->count - 1;
    if (arg0 < ((State *)&D_80127128)->count) {
        aligned4_memcpy(((State *)&D_80127128)->emitter->particles + arg0,
                        ((State *)&D_80127128)->emitter->particles + ((State *)&D_80127128)->count, sizeof(Particle));
    }
}

void func_800B9170(void) {
    typedef struct {
        f32 position[3];
        f32 velocity[3];
    } Particle;
    typedef struct {
        f32 position[3];
        f32 velocity[3];
        u8 mode;
        Particle *particles;
    } Emitter;
    typedef struct {
        Emitter *emitter;
        s32 count;
        s32 unk8;
        s32 index;
        f32 position[3];
        f32 floor;
    } State;
    extern s32 D_80127128;
    extern f32 D_80127138[3];
    extern f32 D_801256A0;
    extern f32 D_801256A4;
    extern f32 D_801256A8;
    s32 func_8001211C(void);
    void func_8008FE68(f32 *);
    s32 func_800A5490(void);
    void func_800B9108(s32);
    f32 func_800D8FF8(void);
    f32 func_800DC0C0(void);
    f32 func_800E3A80(void);
    s32 func_800E3F8C(f32, f32, f32);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EEAD4(f32 *, f32 *);
    f32 func_800EEFD4(f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF934(f32 *, f32 *, f32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    f32 temp_f20;
    s32 sp68;
    s32 var_v1;
    s32 sp60;
    Particle *sp5C;
    f32 sp58;
    f32 sp4C[3];
    f32 var_f20;
    s32 sp44;
    Particle *sp40;

    if (((State *)&D_80127128)->emitter != NULL) {
        if (func_800A5490() != 0) {
            ((State *)&D_80127128)->count = 0;
            return;
        }
        temp_f20 = func_800D8FF8();
        sp60 = (func_8001211C() & 1) * 2;
        func_8008FE68(D_80127138);
        ((State *)&D_80127128)->emitter->velocity[0] = ((State *)&D_80127128)->position[0] - ((State *)&D_80127128)->emitter->position[0];
        ((State *)&D_80127128)->emitter->velocity[1] = ((State *)&D_80127128)->position[1] - ((State *)&D_80127128)->emitter->position[1];
        ((State *)&D_80127128)->emitter->velocity[2] = ((State *)&D_80127128)->position[2] - ((State *)&D_80127128)->emitter->position[2];
        ((State *)&D_80127128)->emitter->position[0] = ((State *)&D_80127128)->position[0];
        ((State *)&D_80127128)->emitter->position[1] = ((State *)&D_80127128)->position[1];
        ((State *)&D_80127128)->emitter->position[2] = ((State *)&D_80127128)->position[2];
        ((State *)&D_80127128)->floor = ((State *)&D_80127128)->position[1] - 300.0f;

        for (sp68 = 0; sp68 < ((State *)&D_80127128)->count; sp68++) {
            sp5C = ((State *)&D_80127128)->emitter->particles + sp68;
            for (var_v1 = 0; var_v1 < 3; var_v1++) {
                sp5C->position[var_v1] += sp5C->velocity[var_v1] * temp_f20;
            }
            sp5C->velocity[sp60] += (func_800DC0C0() * 30.0f) - 15.0f;
        }
        ((State *)&D_80127128)->index++;
        if (((State *)&D_80127128)->index < ((State *)&D_80127128)->count) {
            sp5C = &((State *)&D_80127128)->emitter->particles[((State *)&D_80127128)->index];
            if (func_800EEAD4(sp5C->position, D_80127138) > D_801256A0) {
                func_800B9108(((State *)&D_80127128)->index);
            }
        } else {
            ((State *)&D_80127128)->index = 0;
        }
        if (((State *)&D_80127128)->emitter->mode == 1) {
            if (((State *)&D_80127128)->count < 100) {
                sp40 = ((State *)&D_80127128)->emitter->particles + ((State *)&D_80127128)->count;
                ((State *)&D_80127128)->count++;
                sp58 = func_800DC178(100.0f, D_801256A4);
                func_800EFA4C(sp4C, 0.0f, func_800DC0C0() * 200.0f + 200.0f, -sp58);
                if (func_800EEFD4(((State *)&D_80127128)->emitter->velocity) < 25.0f) {
                    var_f20 = 100.0f;
                } else {
                    var_f20 = 70.0f;
                }
                func_800EF934(sp4C, sp4C, func_800E3A80() + func_800DC178(-var_f20, var_f20));
                func_800EF04C(sp4C, D_80127138);
                if (sp58 < D_801256A8) {
                    for (sp44 = 0; sp44 < 5 && func_800E3F8C(sp4C[0], sp4C[1] - 10.0f, sp4C[2]); sp44++) {
                        sp4C[1] += 200.0f;
                    }
                }
                func_800EE7F8(sp40->position, sp4C);
                func_800EFA4C(sp40->velocity, 0.0f, func_800DC178(-150.0f, -50.0f), 0.0f);
            }
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E91790/func_800B956C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E91790/func_800B97A4.s")
