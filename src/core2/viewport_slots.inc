/* The four player slots are followed by the shared view in slot four. */
#if defined(BT_NATIVE) && !defined(BT_ILP32)
static unk_D_80127688 viewportSlots[5];
typedef unk_D_80127688 ViewportReleaseEntry;
#define VIEWPORT_DEFAULT_CAMERA viewportSlots[4].camera
#define VIEWPORT_CURRENT D_80127674
#define VIEWPORT_RELEASE_BEGIN viewportSlots
#define VIEWPORT_RELEASE_END (viewportSlots + 5)
#define VIEWPORT_RELEASE_HANDLE(entry) ((entry)->unk0)
#else
#define viewportSlots D_80127688
typedef s32 ViewportReleaseEntry[3];
#define VIEWPORT_DEFAULT_CAMERA D_801276BC
#define VIEWPORT_CURRENT (((s32 *)&D_80127670)[1])
#define VIEWPORT_RELEASE_BEGIN ((ViewportReleaseEntry *)((s8 *)&D_801276BC - 0x34))
#define VIEWPORT_RELEASE_END ((ViewportReleaseEntry *)&D_801276C4)
#define VIEWPORT_RELEASE_HANDLE(entry) ((entry)[0][0])
#endif
