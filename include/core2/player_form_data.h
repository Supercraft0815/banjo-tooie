#ifndef CORE2_PLAYER_FORM_DATA_H
#define CORE2_PLAYER_FORM_DATA_H

#include <ultra64.h>

typedef struct { s16 map; u8 first, second; } PlayerMapRule;

typedef struct {
    s16 sounds[4], alternate_sounds[4];
    s16 sound_commands[8], particle_commands[24];
    u8 render_order[4], alternate_render_order[12];
    s16 maps[8];
    PlayerMapRule map_rules[44];
    s16 splash_commands[16];
    f32 dimensions[20][3], radii[20][2];
    /* Camera type zero shares the bits of the twentieth form's scale in retail. */
    union {
        struct { f32 scale[20]; s32 sizes[8]; } form;
        struct { f32 prefix[19]; s32 sizes[9]; } camera;
    } lookup;
#if defined(BT_NATIVE) && !defined(BT_ILP32)
    struct NativeCameraDatabase *database;
#else
    s32 database;
#endif
    u32 padding[3];
} PlayerFormData;

extern PlayerFormData player_form_data;
#endif
