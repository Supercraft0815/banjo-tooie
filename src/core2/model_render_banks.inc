/* Segment 3 contains 29 two-packet material display lists per render bank.
 * The cartridge reserves 464 packets per bank. Only the first 58 are addressable by models. */
#if defined(BT_MODEL_BANKS_HOST) || !defined(BT_NATIVE) || defined(BT_ILP32)
#define MODEL_MODE(first, second) gsDPSetRenderMode(first, second), gsSPEndDisplayList()
#define MATERIALS(first, depth, opaque, aa_opaque, trans, aa_trans) \
    MODEL_MODE(first, (opaque) | (depth)), MODEL_MODE(first, (aa_opaque) | (depth)), \
    MODEL_MODE(first, (trans) | (depth)), MODEL_MODE(first, (aa_trans) | (depth)), \
    MODEL_MODE(first, (trans) | (depth)), MODEL_MODE(first, (aa_trans) | (depth))
#define MATERIAL_BANK(opaque, aa_opaque, trans, aa_trans, write, read, tail) \
    MATERIALS(G_RM_PASS, write, opaque, aa_opaque, trans, aa_trans), \
    MATERIALS(G_RM_PASS, read, opaque, aa_opaque, trans, aa_trans), \
    MATERIALS(G_RM_FOG_SHADE_A, write, opaque, aa_opaque, trans, aa_trans), \
    MATERIALS(G_RM_FOG_SHADE_A, read, opaque, aa_opaque, trans, aa_trans), \
    MODEL_MODE(G_RM_PASS, G_RM_AA_XLU_SURF2 | CVG_DST_SAVE | (tail)), \
    MODEL_MODE(G_RM_PASS, G_RM_ZB_XLU_DECAL2), MODEL_MODE(G_RM_PASS, G_RM_AA_ZB_XLU_DECAL2), \
    MODEL_MODE(G_RM_FOG_SHADE_A, G_RM_ZB_XLU_DECAL2), MODEL_MODE(G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_DECAL2)
#ifdef BT_MODEL_BANKS_HOST
Gfx native_model_render_banks[8][NATIVE_MODEL_RENDER_PACKETS] = {
#define BEGIN_BANK(name, offset) {
#define END_BANK },
#else
#define BEGIN_BANK(name, offset) Gfx name[464] BT_DATA(8, model_render_banks, offset) = {
#define END_BANK };
#endif

BEGIN_BANK(D_8011B9B0, 0)
    MATERIAL_BANK(G_RM_OPA_SURF2, G_RM_AA_OPA_SURF2, G_RM_XLU_SURF2, G_RM_AA_XLU_SURF2,
                  0, 0, 0)
END_BANK
BEGIN_BANK(D_8011C830, 3712)
    MATERIAL_BANK(G_RM_OPA_SURF2, G_RM_AA_OPA_SURF2, G_RM_XLU_SURF2, G_RM_AA_XLU_SURF2,
                  Z_CMP | Z_UPD, Z_CMP, Z_CMP)
END_BANK
BEGIN_BANK(D_8011D6B0, 7424)
    MATERIAL_BANK(G_RM_OPA_SURF2, G_RM_AA_OPA_SURF2, G_RM_XLU_SURF2, G_RM_AA_XLU_SURF2,
                  Z_CMP, Z_CMP, Z_CMP)
END_BANK
BEGIN_BANK(D_8011E530, 11136)
    MATERIAL_BANK(G_RM_XLU_SURF2, G_RM_AA_XLU_SURF2, G_RM_XLU_SURF2, G_RM_AA_XLU_SURF2,
                  0, 0, 0)
END_BANK
BEGIN_BANK(D_8011F3B0, 14848)
    MATERIAL_BANK(G_RM_XLU_SURF2, G_RM_AA_XLU_SURF2, G_RM_XLU_SURF2, G_RM_AA_XLU_SURF2,
                  Z_CMP | Z_UPD, Z_CMP, Z_CMP)
END_BANK
BEGIN_BANK(D_80120230, 18560)
    MATERIAL_BANK(G_RM_XLU_SURF2, G_RM_AA_XLU_SURF2, G_RM_XLU_SURF2, G_RM_AA_XLU_SURF2,
                  Z_CMP, Z_CMP, Z_CMP)
END_BANK
BEGIN_BANK(D_801210B0, 22272)
    MATERIAL_BANK(G_RM_ZB_OPA_DECAL2, G_RM_AA_ZB_OPA_DECAL2, G_RM_ZB_XLU_DECAL2, G_RM_AA_ZB_XLU_DECAL2,
                  0, 0, Z_CMP)
END_BANK
BEGIN_BANK(D_80121F30, 25984)
    MATERIAL_BANK(G_RM_ZB_XLU_DECAL2, G_RM_AA_ZB_XLU_DECAL2, G_RM_ZB_XLU_DECAL2, G_RM_AA_ZB_XLU_DECAL2,
                  0, 0, Z_CMP)
END_BANK

#ifdef BT_MODEL_BANKS_HOST
};
#endif
#undef BEGIN_BANK
#undef END_BANK
#undef MATERIAL_BANK
#undef MATERIALS
#undef MODEL_MODE
#endif
