#include "common.h"

s32 chbubble_entrypoint_0(void *arg0, f32 *position, f32 *offset, f32 scale, f32 distance) {
    typedef struct {
        Gfx *gfx;
        Mtx *mtx;
        Vtx *vtx;
    } RenderContext;
    s32 func_80014F00(void);
    void func_800191F8(f32, f32, f32);
    void func_800AF614(Gfx **, s32, s32, s32, s32, s32, s32, s32 *, s32 *);
    s32 func_800D674C(s32);
    void func_800E3980(f32 *);
    void *func_800E401C(void);
    void func_800E4140(f32 *, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800EEB40(f32 *, f32 *);
    void mlMtxApply(Mtx *);
    void mlMtxSet(void *);
    s32 texture;
    f32 camera[3];
    f32 translation[3];
    f32 screen[2];
    s32 x;
    s32 y;
    s32 width;
    s32 height;
    s32 textureWidth;
    s32 textureHeight;
    Gfx *gfx;
    Vtx *vtx;

    gfx = ((RenderContext *)arg0)->gfx;
    vtx = ((RenderContext *)arg0)->vtx;
    func_800E3980(camera);
    if (distance > 0.0f && distance * distance < func_800EEB40(position, camera)) {
        return 0;
    }
    func_800EE7F8(translation, position);
    mlMtxSet(func_800E401C());
    func_800191F8(translation[0], translation[1], translation[2]);
    mlMtxApply(((RenderContext *)arg0)->mtx);
    {
        Gfx *p = gfx++;
        p->words.w0 = 0xDA380002;
        p->words.w1 = (u32)((RenderContext *)arg0)->mtx + 0x80000000;
    }
    ((RenderContext *)arg0)->mtx++;
    width = (s32)(offset[0] * 200.0f * scale);
    height = (s32)(offset[1] * 200.0f * scale);
    func_800E4140(position, screen);
    x = (s32)(screen[0] + offset[0] * 25.0f);
    y = (s32)(screen[1] + offset[1] * 25.0f);
    if (x < 0) {
        x = 0;
    } else if (x > 272) {
        x = 272;
    }
    if (y < 0) {
        y = 0;
    } else if (y > 196) {
        y = 196;
    }
    gDPPipeSync(gfx++);
    gSPClearGeometryMode(gfx++, 0x3F0005);
    gSPSetGeometryMode(gfx++, 0x200005);
    gSPTexture(gfx++, 0x8000, 0x8000, 0, 0, 1);
    gDPSetTextureLOD(gfx++, G_TL_TILE);
    gDPSetCycleType(gfx++, G_CYC_2CYCLE);
    gDPSetCombine(gfx++, 0x2219FF, 0xFFFFFE38);
    gDPSetRenderMode(gfx++, 0x0C184A50, 0);
    func_800AF614(&gfx, func_800D674C(0x9CC), 0, 0, 0, 0, 0, &textureWidth, &textureHeight);
    texture = func_80014F00();
    gDPSetTextureImage(gfx++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 304, (u32)((u16 *)texture + y * 304 + (x & 0xFFFC)) + 0x80000000);
    {
        Gfx *p = gfx++;
        p->words.w0 = 0xF5101280;
        p->words.w1 = 0x07080200;
    }
    gDPLoadSync(gfx++);
    {
        Gfx *p = gfx++;
        p->words.w0 = 0xF4000000;
        p->words.w1 = 0x0708C07C;
    }
    gDPPipeSync(gfx++);
    {
        Gfx *p = gfx++;
        p->words.w0 = 0xF5101280;
        p->words.w1 = 0x01080200;
    }
    gDPSetTileSize(gfx++, 1, (3 - x % 4) << 2, 0, ((3 - x % 4) + 31) << 2, 31 << 2);
    gSPVertex(gfx++, vtx, 8, 0);
    gSP2Triangles(gfx++, 0, 1, 3, 0, 0, 3, 2, 0);
    func_800AF614(&gfx, func_800D674C(0x9CB), 0, 0, 0, 2, 2, &textureWidth, &textureHeight);
    gDPPipeSync(gfx++);
    gDPSetCombine(gfx++, 0x109804, 0x3FFDFFF8);
    gDPSetPrimColor(gfx++, 0, 0, 0x50, 0xF0, 0xFF, 0xFF);
    gSP2Triangles(gfx++, 7, 4, 5, 0, 6, 4, 7, 0);
    gDPPipeSync(gfx++);
    gDPSetTextureLUT(gfx++, G_TT_NONE);
    gSPPopMatrix(gfx++, G_MTX_MODELVIEW);
    for (y = 0; y < 2; y++) {
        for (x = 0; x < 2; x++) {
            vtx->v.ob[0] = (width >> 1) - x * width;
            vtx->v.ob[1] = (height >> 1) - y * height;
            vtx->v.ob[2] = 0;
            vtx->v.tc[0] = ((1 - x) * 31) << 6;
            vtx->v.tc[1] = (y * 31) << 6;
            *(u32 *)vtx->v.cn = 0xB4F0FFA0;
            vtx++;
        }
    }
    for (y = 0; y < 2; y++) {
        for (x = 0; x < 2; x++) {
            vtx->v.ob[0] = (width >> 1) - x * width;
            vtx->v.ob[1] = (height >> 1) - y * height;
            vtx->v.ob[2] = 0;
            vtx->v.tc[0] = ((x ^ 1) * (textureWidth - 1)) << 6;
            vtx->v.tc[1] = ((textureHeight - 1) * y) << 6;
            *(u32 *)vtx->v.cn = 0xFFFFFFFF;
            vtx++;
        }
    }
    ((RenderContext *)arg0)->gfx = gfx;
    ((RenderContext *)arg0)->vtx = vtx;
    return 1;
}
