/* Left, top, width and height in half-screen units, including split-screen gutters. */
typedef union {
    s16 bounds[9][4];
    s64 alignment;
} ViewportLayoutTable;

ViewportLayoutTable D_8011A420 BT_DATA(8, viewport_layout, 0) = {{
    {0, 0, 2, 2},
    {0, 0, 2, 1},
    {0, 1, 2, 1},
    {0, 0, 1, 1},
    {1, 0, 1, 1},
    {0, 1, 1, 1},
    {1, 1, 1, 1},
    {0, 0, 1, 2},
    {1, 0, 1, 2},
}};

#if defined(BT_NATIVE) && !defined(BT_ILP32)
extern s32 D_80127678;
static s32 viewportHalfWidth, viewportHalfHeight;
#define VIEWPORT_SPLIT_VERTICAL D_80127678
#define VIEWPORT_HALF_WIDTH viewportHalfWidth
#define VIEWPORT_HALF_HEIGHT viewportHalfHeight
#else
#define VIEWPORT_SPLIT_VERTICAL (((Obj1E80A70_D_80127670 *)&D_80127670)->unk8)
#define VIEWPORT_HALF_WIDTH (((Obj1E80A70_D_80127670 *)&D_80127670)->unkC)
#define VIEWPORT_HALF_HEIGHT (((Obj1E80A70_D_80127670 *)&D_80127670)->unk10)
#endif
