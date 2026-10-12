#include "common.h"

s32 func_800AF5A0(s16 *arg0) {
    return arg0[0];
}

s32 func_800AF5A8(s16 *arg0) {
    return arg0[1];
}

void func_800AF5B0(void *arg0, s32 *arg1, s32 *arg2) {
    *arg1 = (s32) (*(s16 *)((s8 *)(arg0) + (4)));
    *arg2 = (s32) (*(s16 *)((s8 *)(arg0) + (6)));
}

void func_800AF5C4(void *arg0, s32 *arg1, s32 *arg2) {
    *arg1 = (s32) (*(s16 *)((s8 *)(arg0) + (8)));
    *arg2 = (s32) (*(s16 *)((s8 *)(arg0) + (0xA)));
}

u8 *func_800AF5D8(s16 *arg0) {
    u8 *result = (u8 *)arg0;
    result += arg0[9];
    return result;
}

void *func_800AF5E4(void *arg0) {
    struct OffsetHeader {
        u8 padding[0x14];
        s32 offset;
    };
    return (u8 *)arg0 + ((struct OffsetHeader *)arg0)->offset;
}

void *func_800AF5F0(void *arg0)
{
    struct OffsetHeader {
        u8 padding[0x18];
        s32 offset;
    };

    return (u8 *)arg0 + ((struct OffsetHeader *)arg0)->offset;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E88E90/func_800AF5FC.s")

typedef struct {
    s16 unk0[3];
    s16 paletteOffset;
    s32 textureOffset;
} TextureFrame;

u8 *func_800AF5D8(s16 *texture);
TextureFrame *func_800AF5FC(s16 *texture, s32 frame);

void func_800AF614(Gfx **gfx, s16 *texture, s32 frameIndex, s32 tmem, s32 tile, s32 cms, s32 cmt, s32 *width, s32 *height) {
    TextureFrame *frame;
    u8 *data;
    s32 masks;
    s32 maskt;
    s32 size;

    frame = func_800AF5FC(texture, frameIndex);
    data = func_800AF5D8(texture) + frame->textureOffset;
    *width = texture[4];
    *height = texture[5];

    if (texture[1] & 1) {
        gDPSetTextureLUT((*gfx)++, G_TT_RGBA16);
        gDPLoadTLUT_pal16((*gfx)++, 0, data + frame->paletteOffset);
    } else if (texture[1] & 4) {
        gDPSetTextureLUT((*gfx)++, G_TT_RGBA16);
        gDPLoadTLUT_pal256((*gfx)++, data + frame->paletteOffset);
    }
    if ((*width & 7) == 0) {
        size = *width - 1;
        masks = 0;
        while (size != 0) {
            masks++;
            size >>= 1;
        }
    } else {
        masks = 0;
    }
    if ((*height & 7) == 0) {
        size = *height - 1;
        maskt = 0;
        while (size != 0) {
            maskt++;
            size >>= 1;
        }
    } else {
        maskt = 0;
    }
    /* Keep the expanded image and pipe-sync stores on separate lines for IDO scheduling. */
    if (texture[1] & 0x800) {
        {
            Gfx *g = (*gfx)++;
            g->words.w0 = _SHIFTL(G_SETTIMG, 24, 8) | _SHIFTL(G_IM_FMT_RGBA, 21, 3) | _SHIFTL(G_IM_SIZ_32b_LOAD_BLOCK, 19, 2);
            g->words.w1 = (u32)data;
        }
        gDPSetTile((*gfx)++, G_IM_FMT_RGBA, G_IM_SIZ_32b_LOAD_BLOCK, 0, tmem, G_TX_LOADTILE, 0, cmt, maskt, 0, cms, masks, 0);
        gDPLoadSync((*gfx)++);
        gDPLoadBlock((*gfx)++, G_TX_LOADTILE, 0, 0, (((*width * *height + G_IM_SIZ_32b_INCR) >> G_IM_SIZ_32b_SHIFT) - 1), CALC_DXT(*width, G_IM_SIZ_32b_BYTES));
        {
            Gfx *g = (*gfx)++;
            g->words.w1 = 0;
            g->words.w0 = _SHIFTL(G_RDPPIPESYNC, 24, 8);
        }
        gDPSetTile((*gfx)++, G_IM_FMT_RGBA, G_IM_SIZ_32b, ((*width * G_IM_SIZ_32b_LINE_BYTES + 7) >> 3), tmem, tile, 0, cmt, maskt, 0, cms, masks, 0);
        gDPSetTileSize((*gfx)++, tile, 0, 0, (*width - 1) << 2, (*height - 1) << 2);
    } else if (texture[1] & 0x400) {
        {
            Gfx *g = (*gfx)++;
            g->words.w0 = _SHIFTL(G_SETTIMG, 24, 8) | _SHIFTL(G_IM_FMT_RGBA, 21, 3) | _SHIFTL(G_IM_SIZ_16b_LOAD_BLOCK, 19, 2);
            g->words.w1 = (u32)data;
        }
        gDPSetTile((*gfx)++, G_IM_FMT_RGBA, G_IM_SIZ_16b_LOAD_BLOCK, 0, tmem, G_TX_LOADTILE, 0, cmt, maskt, 0, cms, masks, 0);
        gDPLoadSync((*gfx)++);
        gDPLoadBlock((*gfx)++, G_TX_LOADTILE, 0, 0, (((*width * *height + G_IM_SIZ_16b_INCR) >> G_IM_SIZ_16b_SHIFT) - 1), CALC_DXT(*width, G_IM_SIZ_16b_BYTES));
        {
            Gfx *g = (*gfx)++;
            g->words.w1 = 0;
            g->words.w0 = _SHIFTL(G_RDPPIPESYNC, 24, 8);
        }
        gDPSetTile((*gfx)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, ((*width * G_IM_SIZ_16b_LINE_BYTES + 7) >> 3), tmem, tile, 0, cmt, maskt, 0, cms, masks, 0);
        gDPSetTileSize((*gfx)++, tile, 0, 0, (*width - 1) << 2, (*height - 1) << 2);
    } else if (texture[1] & 0x200) {
        {
            Gfx *g = (*gfx)++;
            g->words.w0 = _SHIFTL(G_SETTIMG, 24, 8) | _SHIFTL(G_IM_FMT_IA, 21, 3) | _SHIFTL(G_IM_SIZ_16b_LOAD_BLOCK, 19, 2);
            g->words.w1 = (u32)data;
        }
        gDPSetTile((*gfx)++, G_IM_FMT_IA, G_IM_SIZ_16b_LOAD_BLOCK, 0, tmem, G_TX_LOADTILE, 0, cmt, maskt, 0, cms, masks, 0);
        gDPLoadSync((*gfx)++);
        gDPLoadBlock((*gfx)++, G_TX_LOADTILE, 0, 0, (((*width * *height + G_IM_SIZ_16b_INCR) >> G_IM_SIZ_16b_SHIFT) - 1), CALC_DXT(*width, G_IM_SIZ_16b_BYTES));
        {
            Gfx *g = (*gfx)++;
            g->words.w1 = 0;
            g->words.w0 = _SHIFTL(G_RDPPIPESYNC, 24, 8);
        }
        gDPSetTile((*gfx)++, G_IM_FMT_IA, G_IM_SIZ_16b, ((*width * G_IM_SIZ_16b_LINE_BYTES + 7) >> 3), tmem, tile, 0, cmt, maskt, 0, cms, masks, 0);
        gDPSetTileSize((*gfx)++, tile, 0, 0, (*width - 1) << 2, (*height - 1) << 2);
    } else if (texture[1] & 4) {
        {
            Gfx *g = (*gfx)++;
            g->words.w0 = _SHIFTL(G_SETTIMG, 24, 8) | _SHIFTL(G_IM_FMT_CI, 21, 3) | _SHIFTL(G_IM_SIZ_8b_LOAD_BLOCK, 19, 2);
            g->words.w1 = (u32)data;
        }
        gDPSetTile((*gfx)++, G_IM_FMT_CI, G_IM_SIZ_8b_LOAD_BLOCK, 0, tmem, G_TX_LOADTILE, 0, cmt, maskt, 0, cms, masks, 0);
        gDPLoadSync((*gfx)++);
        gDPLoadBlock((*gfx)++, G_TX_LOADTILE, 0, 0, (((*width * *height + G_IM_SIZ_8b_INCR) >> G_IM_SIZ_8b_SHIFT) - 1), CALC_DXT(*width, G_IM_SIZ_8b_BYTES));
        {
            Gfx *g = (*gfx)++;
            g->words.w1 = 0;
            g->words.w0 = _SHIFTL(G_RDPPIPESYNC, 24, 8);
        }
        gDPSetTile((*gfx)++, G_IM_FMT_CI, G_IM_SIZ_8b, ((*width * G_IM_SIZ_8b_LINE_BYTES + 7) >> 3), tmem, tile, 0, cmt, maskt, 0, cms, masks, 0);
        gDPSetTileSize((*gfx)++, tile, 0, 0, (*width - 1) << 2, (*height - 1) << 2);
    } else if (texture[1] & 0x100) {
        {
            Gfx *g = (*gfx)++;
            g->words.w0 = _SHIFTL(G_SETTIMG, 24, 8) | _SHIFTL(G_IM_FMT_IA, 21, 3) | _SHIFTL(G_IM_SIZ_8b_LOAD_BLOCK, 19, 2);
            g->words.w1 = (u32)data;
        }
        gDPSetTile((*gfx)++, G_IM_FMT_IA, G_IM_SIZ_8b_LOAD_BLOCK, 0, tmem, G_TX_LOADTILE, 0, cmt, maskt, 0, cms, masks, 0);
        gDPLoadSync((*gfx)++);
        gDPLoadBlock((*gfx)++, G_TX_LOADTILE, 0, 0, (((*width * *height + G_IM_SIZ_8b_INCR) >> G_IM_SIZ_8b_SHIFT) - 1), CALC_DXT(*width, G_IM_SIZ_8b_BYTES));
        {
            Gfx *g = (*gfx)++;
            g->words.w1 = 0;
            g->words.w0 = _SHIFTL(G_RDPPIPESYNC, 24, 8);
        }
        gDPSetTile((*gfx)++, G_IM_FMT_IA, G_IM_SIZ_8b, ((*width * G_IM_SIZ_8b_LINE_BYTES + 7) >> 3), tmem, tile, 0, cmt, maskt, 0, cms, masks, 0);
        gDPSetTileSize((*gfx)++, tile, 0, 0, (*width - 1) << 2, (*height - 1) << 2);
    } else if (texture[1] & 0x40) {
        {
            Gfx *g = (*gfx)++;
            g->words.w0 = _SHIFTL(G_SETTIMG, 24, 8) | _SHIFTL(G_IM_FMT_I, 21, 3) | _SHIFTL(G_IM_SIZ_8b_LOAD_BLOCK, 19, 2);
            g->words.w1 = (u32)data;
        }
        gDPSetTile((*gfx)++, G_IM_FMT_I, G_IM_SIZ_8b_LOAD_BLOCK, 0, tmem, G_TX_LOADTILE, 0, cmt, maskt, 0, cms, masks, 0);
        gDPLoadSync((*gfx)++);
        gDPLoadBlock((*gfx)++, G_TX_LOADTILE, 0, 0, (((*width * *height + G_IM_SIZ_8b_INCR) >> G_IM_SIZ_8b_SHIFT) - 1), CALC_DXT(*width, G_IM_SIZ_8b_BYTES));
        {
            Gfx *g = (*gfx)++;
            g->words.w1 = 0;
            g->words.w0 = _SHIFTL(G_RDPPIPESYNC, 24, 8);
        }
        gDPSetTile((*gfx)++, G_IM_FMT_I, G_IM_SIZ_8b, ((*width * G_IM_SIZ_8b_LINE_BYTES + 7) >> 3), tmem, tile, 0, cmt, maskt, 0, cms, masks, 0);
        gDPSetTileSize((*gfx)++, tile, 0, 0, (*width - 1) << 2, (*height - 1) << 2);
    } else if (texture[1] & 1) {
        {
            Gfx *g = (*gfx)++;
            g->words.w0 = _SHIFTL(G_SETTIMG, 24, 8) | _SHIFTL(G_IM_FMT_RGBA, 21, 3) | _SHIFTL(G_IM_SIZ_16b, 19, 2);
            g->words.w1 = (u32)data;
        }
        gDPSetTile((*gfx)++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, tmem, G_TX_LOADTILE, 0, cmt, maskt, 0, cms, masks, 0);
        gDPLoadSync((*gfx)++);
        gDPLoadBlock((*gfx)++, G_TX_LOADTILE, 0, 0, (((*width * *height + 3) >> 2) - 1), CALC_DXT_4b(*width));
        {
            Gfx *g = (*gfx)++;
            g->words.w1 = 0;
            g->words.w0 = _SHIFTL(G_RDPPIPESYNC, 24, 8);
        }
        gDPSetTile((*gfx)++, G_IM_FMT_RGBA, G_IM_SIZ_4b, (((*width >> 1) + 7) >> 3), tmem, tile, 0, cmt, maskt, 0, cms, masks, 0);
        gDPSetTileSize((*gfx)++, tile, 0, 0, (*width - 1) << 2, (*height - 1) << 2);
    } else if (texture[1] & 0x80) {
        {
            Gfx *g = (*gfx)++;
            g->words.w0 = _SHIFTL(G_SETTIMG, 24, 8) | _SHIFTL(G_IM_FMT_IA, 21, 3) | _SHIFTL(G_IM_SIZ_16b, 19, 2);
            g->words.w1 = (u32)data;
        }
        gDPSetTile((*gfx)++, G_IM_FMT_IA, G_IM_SIZ_16b, 0, tmem, G_TX_LOADTILE, 0, cmt, maskt, 0, cms, masks, 0);
        gDPLoadSync((*gfx)++);
        gDPLoadBlock((*gfx)++, G_TX_LOADTILE, 0, 0, (((*width * *height + 3) >> 2) - 1), CALC_DXT_4b(*width));
        {
            Gfx *g = (*gfx)++;
            g->words.w1 = 0;
            g->words.w0 = _SHIFTL(G_RDPPIPESYNC, 24, 8);
        }
        gDPSetTile((*gfx)++, G_IM_FMT_IA, G_IM_SIZ_4b, (((*width >> 1) + 7) >> 3), tmem, tile, 0, cmt, maskt, 0, cms, masks, 0);
        gDPSetTileSize((*gfx)++, tile, 0, 0, (*width - 1) << 2, (*height - 1) << 2);
    } else if (texture[1] & 0x20) {
        {
            Gfx *g = (*gfx)++;
            g->words.w0 = _SHIFTL(G_SETTIMG, 24, 8) | _SHIFTL(G_IM_FMT_I, 21, 3) | _SHIFTL(G_IM_SIZ_16b, 19, 2);
            g->words.w1 = (u32)data;
        }
        gDPSetTile((*gfx)++, G_IM_FMT_I, G_IM_SIZ_16b, 0, tmem, G_TX_LOADTILE, 0, cmt, maskt, 0, cms, masks, 0);
        gDPLoadSync((*gfx)++);
        gDPLoadBlock((*gfx)++, G_TX_LOADTILE, 0, 0, (((*width * *height + 3) >> 2) - 1), CALC_DXT_4b(*width));
        {
            Gfx *g = (*gfx)++;
            g->words.w1 = 0;
            g->words.w0 = _SHIFTL(G_RDPPIPESYNC, 24, 8);
        }
        gDPSetTile((*gfx)++, G_IM_FMT_I, G_IM_SIZ_4b, (((*width >> 1) + 7) >> 3), tmem, tile, 0, cmt, maskt, 0, cms, masks, 0);
        gDPSetTileSize((*gfx)++, tile, 0, 0, (*width - 1) << 2, (*height - 1) << 2);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E88E90/func_800B0CFC.s")
