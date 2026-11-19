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

#ifdef BT_NATIVE
typedef struct {
    s32 count;
    s32 current;
    s32 split_vertical;
    s32 half_width;
    s32 half_height;
} ViewportLayoutState;

ViewportLayoutState D_80127670;
#define VIEWPORT_DRAW_INDEX D_80127670.current
#define VIEWPORT_COUNT D_80127670.count
#define VIEWPORT_CURRENT D_80127670.current
#define VIEWPORT_SPLIT_VERTICAL D_80127670.split_vertical
#define VIEWPORT_HALF_WIDTH D_80127670.half_width
#define VIEWPORT_HALF_HEIGHT D_80127670.half_height
#else
#define VIEWPORT_DRAW_INDEX (((s32 *)&D_80127670)[1])
#define VIEWPORT_COUNT D_80127670
#define VIEWPORT_CURRENT D_80127674
#define VIEWPORT_SPLIT_VERTICAL (((Obj1E80A70_D_80127670 *)&D_80127670)->unk8)
#define VIEWPORT_HALF_WIDTH (((Obj1E80A70_D_80127670 *)&D_80127670)->unkC)
#define VIEWPORT_HALF_HEIGHT (((Obj1E80A70_D_80127670 *)&D_80127670)->unk10)
#endif
