/* Per-slot animation state. IDO uses the original symbols for pointers to fields and rows. */
typedef struct {
    s16 homeX, homeY;
    u8 direction, style;
    s16 x, y;
    s8 dx, dy;
    u8 state;
    s8 frame, type;
    u8 pad0F, flag, flag11, mode, pad13;
    f32 timer;
    BT_NATIVE_ONLY(void *) BT_IDO_ONLY(s32) handle;
} HudInfoEntry;

HudInfoEntry D_80123880[48] BT_DATA(4, hud_info_entries, 0) = {
    {22, 24, 0, 0},
    {22, 24, 3, 3},
    {282, 24, 2, 2},
    {282, 50, 2, 2},
    {282, 76, 2, 2},
    {282, 102, 2, 2},
    {282, 128, 2, 2},
    {282, 154, 2, 2},
    {282, 180, 2, 2},
    {282, 206, 2, 2},
    {135, 206, 1, 0},
    {22, 206, 0, 0},
    {22, 24, 3, 0},
    {97, 24, 3, 0},
    {172, 24, 3, 0},
    {247, 24, 3, 0},
    {134, 115, 0, 0},
    {22, 63, 0, 0},
    {22, 89, 0, 0},
    {22, 115, 0, 0},
    {22, 141, 0, 0},
    {22, 167, 0, 0},
    {282, 63, 2, 2},
    {282, 89, 2, 2},
    {282, 115, 2, 2},
    {282, 141, 2, 2},
    {282, 167, 2, 2},
    {28, 63, 0, 0},
    {28, 99, 0, 0},
    {28, 135, 0, 0},
    {28, 171, 0, 0},
    {276, 63, 2, 2},
    {276, 99, 2, 2},
    {276, 135, 2, 2},
    {276, 171, 2, 2},
    {247, 206, 1, 0},
    {22, 206, 1, 0},
    {134, 206, 1, 0},
    {22, 206, 1, 0},
    {247, 206, 1, 0},
    {97, 206, 1, 0},
    {172, 206, 1, 0},
    {278, 170, 2, 2},
    {22, 206, 0, 0},
    {282, 206, 2, 2},
    {22, 170, 0, 0},
    {22, 180, 0, 0},
    {135, 115, 3, 0},
};

s8 D_80123DC0[10] BT_DATA(1, hud_info_entries, 0x540) = {21, 17, 13, 10, 7, 5, 3, 2, -1, -1};

#if defined(BT_NATIVE) && !defined(BT_ILP32)
void _scinfobar_entrypoint_3(void *, s32);
void _scinfobar_entrypoint_8(u32 *, s32);
#define HUD_STYLE(handle, style) _scinfobar_entrypoint_3((handle), (style))
#define HUD_RELEASE(handle, savedA1) _scinfobar_entrypoint_1((handle), (savedA1))
#else
#define HUD_STYLE(handle, style) _scinfobar_entrypoint_3(handle)
#define HUD_RELEASE(handle, savedA1) _scinfobar_entrypoint_1(handle)
#endif
