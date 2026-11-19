/* Blend the fog color with the framebuffer using its own alpha. */
Gfx D_8011A6E0[9] BT_DATA(8, fog_rectangle_setup, 0) = {
    gsDPPipeSync(),
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_FOG | G_LIGHTING |
                          G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH),
    gsSPTexture(0, 0, 0, G_TX_RENDERTILE, G_OFF),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPPipelineMode(G_PM_NPRIMITIVE),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPSetCombineLERP(0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0),
    gsDPSetRenderMode(GBL_c1(G_BL_CLR_FOG, G_BL_A_FOG, G_BL_CLR_MEM, G_BL_1MA),
                      GBL_c2(G_BL_CLR_FOG, G_BL_A_FOG, G_BL_CLR_MEM, G_BL_1MA) |
                      IM_RD | CVG_DST_SAVE | FORCE_BL),
    gsSPEndDisplayList(),
};
#if defined(BT_NATIVE) && !defined(BT_ILP32)
#define FOG_RECT_LIST(list) (list)
#else
#define FOG_RECT_LIST(list) ((u8 *)(list) - 0x80000000)
#endif
