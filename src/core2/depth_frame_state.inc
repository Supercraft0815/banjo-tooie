/* The retail BSS block holds the list, ten projection snapshots and the current sample bank. */
#ifdef BT_NATIVE
typedef struct {
    f32 a, b;
    s32 active;
} DepthSnapshot;
typedef struct {
    FreeList *list;
    DepthSnapshot depth[2][5];
    s32 index;
} DepthFrameState;
DepthFrameState D_8012D600;
#ifdef BT_ILP32
_Static_assert(sizeof(DepthFrameState) == 0x80, "depth frame banks");
_Static_assert(__builtin_offsetof(DepthFrameState, index) == 0x7C, "depth read bank");
#endif
#define DEPTH_STATE (&D_8012D600)
#define DEPTH_LIST (D_8012D600.list)
#define DEPTH_INDEX (D_8012D600.index)
#define DEPTH_RETAIL(decl)
#define DEPTH_FIELD(host, retail) host
#else
#define DEPTH_STATE ((State *)&D_8012D600)
#define DEPTH_LIST D_8012D600
#define DEPTH_INDEX D_8012D67C
#define DEPTH_RETAIL(decl) decl
#define DEPTH_FIELD(host, retail) retail
#endif
