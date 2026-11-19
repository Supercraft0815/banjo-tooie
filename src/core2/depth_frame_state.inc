/* The retail BSS block holds the list, ten projection snapshots and the current sample bank. */
#if defined(BT_NATIVE) && !defined(BT_ILP32)
typedef struct {
    f32 a, b;
    s32 active;
} DepthSnapshot;
static struct {
    FreeList *list;
    DepthSnapshot depth[2][5];
    s32 index;
} depthFrameState;
#define DEPTH_STATE (&depthFrameState)
#define DEPTH_LIST (depthFrameState.list)
#define DEPTH_INDEX (depthFrameState.index)
#define DEPTH_RETAIL(decl)
#define DEPTH_FIELD(host, retail) host
#else
#define DEPTH_STATE ((State *)&D_8012D600)
#define DEPTH_LIST D_8012D600
#define DEPTH_INDEX D_8012D67C
#define DEPTH_RETAIL(decl) decl
#define DEPTH_FIELD(host, retail) retail
#endif
