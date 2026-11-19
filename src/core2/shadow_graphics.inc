/* Render the framebuffer mask in black, using primitive alpha for the shadow. */
typedef struct { s32 color[4]; } ShadowColor;

s16 D_8011A2E0[10] BT_DATA(2, shadow_graphics, 0) = {
    0xDE, 0xDF, 0xE0, 0xC6, 0xC8, 0xC9, 0x12E, 0x12F, 0x130, -1,
};

Gfx D_8011A2F8[11] BT_DATA(8, shadow_graphics, 0x18) = {
    gsDPPipeSync(),
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_FOG | G_LIGHTING |
                          G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineLERP(0, 0, 0, 0, 1, TEXEL0, PRIMITIVE, 0,
                       0, 0, 0, 0, 1, TEXEL0, PRIMITIVE, 0),
    gsDPSetTextureFilter(G_TF_POINT),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetColorDither(G_CD_DISABLE),
    gsDPSetAlphaCompare(G_AC_THRESHOLD),
    gsSPEndDisplayList(),
};

Gfx D_8011A350[6] BT_DATA(8, shadow_graphics, 0x70) = {
    gsDPPipeSync(),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTexturePersp(G_TP_PERSP),
    gsDPSetColorDither(G_CD_MAGICSQ),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsSPEndDisplayList(),
};

ShadowColor D_8011A380 BT_DATA(4, shadow_graphics, 0xA0) = {{0, 0, 0, 255}};
ShadowColor D_8011A390 BT_DATA(4, shadow_graphics, 0xB0) = {{0, 0, 0, 0}};

#if defined(BT_NATIVE) && !defined(BT_ILP32)
#define SHADOW_SUBLIST(list) (list)
#else
#define SHADOW_SUBLIST(list) ((list) - 0x10000000)
#endif
