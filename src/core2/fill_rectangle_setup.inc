/* Set up the fill-cycle RDP state used by the viewport rectangle functions. */
Gfx D_8011A730[5] BT_DATA(8, fill_rectangle_setup, 0) = {
    gsDPPipeSync(),
    gsDPPipelineMode(G_PM_NPRIMITIVE),
    gsDPSetCycleType(G_CYC_FILL),
    gsDPSetRenderMode(G_RM_NOOP, G_RM_NOOP2),
    gsSPEndDisplayList(),
};
#if defined(BT_NATIVE) && !defined(BT_ILP32)
#define FILL_RECT_LIST(list) (list)
#else
#define FILL_RECT_LIST(list) ((u8 *)(list) - 0x80000000)
#endif
