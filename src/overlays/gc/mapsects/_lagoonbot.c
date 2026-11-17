#if defined(BT_NATIVE) && !defined(BT_ILP32) // ILP32 runs the original code
#include "native_map_sections.h"
#include "native_lagoonbot_data.inc"
void gcmapsects_lagoonbot_entrypoint_0(void) {
    gcmapsects_entrypoint_10(sizeof(lagoon_sections)/sizeof(*lagoon_sections));
    for(unsigned i=0;i<sizeof(lagoon_sections)/sizeof(*lagoon_sections);++i) {
        const NativeMapSectionConfig *s=lagoon_sections+i;
        gcmapsects_entrypoint_0(s->assets[0],s->assets[1],s->position,s->minimum,s->maximum,s->height);
    }
    for(unsigned i=0;i<sizeof(lagoon_links)/sizeof(*lagoon_links);++i)gcmapsects_entrypoint_3(lagoon_links[i][0],lagoon_links[i][1]);
    for(unsigned i=0;i<sizeof(lagoon_disabled)/sizeof(*lagoon_disabled);++i) {
        gcmapsects_entrypoint_1(lagoon_disabled[i],0);gcmapsects_entrypoint_2(lagoon_disabled[i],0);
    }
    gcmapsects_entrypoint_12(gcmapsects_lagoonbot_entrypoint_1);
    gcmapsects_entrypoint_14(2);
}

void gcmapsects_lagoonbot_entrypoint_1(NativeMap *arg0) {
    f32 func_800136E4(f32);
    f32 func_80013728(f32);
    void func_800E39A8(f32 *, f32 *);
    s32 func_800E3E8C(f32 *, f32);
    f32 position[3];
    f32 rotation[3];
    u8 active;

    func_800E39A8(position, rotation);
    rotation[0] = func_80013728(rotation[0]);
    rotation[1] = func_800136E4(rotation[1]);
    active = arg0->section_flags[S_SECONDARY];
    if (active && ((position[1] < 8000.0f && rotation[0] < -20.0f) ||
                   (position[1] < 6000.0f && rotation[0] < 0.0f))) {
        active = arg0->section_flags[S_SECONDARY] = 0;
    }
    if (active && position[1] < 4000.0f && rotation[0] >= 0.0f) {
        arg0->section_flags[S_SECONDARY] = func_800E3E8C(lagoon_points[0], 982.0f);
    }
}

#else
#include "common.h"

void gcmapsects_lagoonbot_entrypoint_0(void) {
    void _gcmapsects_entrypoint_0(s32, s32, void *, void *, void *, f32);
    void _gcmapsects_entrypoint_1(s32, s32);
    void _gcmapsects_entrypoint_2(s32, s32);
    void _gcmapsects_entrypoint_3(s32, s32);
    void _gcmapsects_entrypoint_10(s32);
    void _gcmapsects_entrypoint_12(void (*)(u8 *));
    void _gcmapsects_entrypoint_14(s32);
    void _gcmapsects_lagoonbot_entrypoint_1(u8 *);
    extern s16 D_80800230_gcmapsects_lagoonbot[];
    extern s16 D_8080023C_gcmapsects_lagoonbot[];
    extern s16 D_80800248_gcmapsects_lagoonbot[];
    extern s16 D_808002E0_gcmapsects_lagoonbot[];
    extern s16 D_808002EC_gcmapsects_lagoonbot[];
    extern s32 D_808002F4_gcmapsects_lagoonbot;
    extern s32 D_808002F8_gcmapsects_lagoonbot[2];
    s16 *section;
    u32 limit;
    s32 i;

    _gcmapsects_entrypoint_10(4);
    i = 0;
    do {
        _gcmapsects_entrypoint_0(D_80800230_gcmapsects_lagoonbot[i * 22 + 19],
                                 D_80800230_gcmapsects_lagoonbot[i * 22 + 20],
                                 &D_80800230_gcmapsects_lagoonbot[i * 22],
                                 &D_8080023C_gcmapsects_lagoonbot[i * 22],
                                 &D_80800248_gcmapsects_lagoonbot[i * 22],
                                 D_80800230_gcmapsects_lagoonbot[i * 22 + 18]);
        i++;
    } while ((void *)&D_80800248_gcmapsects_lagoonbot[i * 22] < (void *)D_808002F8_gcmapsects_lagoonbot);
    section = D_808002E0_gcmapsects_lagoonbot;
    i = 0;
    do {
        _gcmapsects_entrypoint_3(section[0], section[1]);
        section += 2;
        i++;
        limit = (u32)i < 3;
    } while (limit);
    /* IDO schedules this initialization differently if the loop starts on a new line. */
    section = D_808002EC_gcmapsects_lagoonbot; do {
        _gcmapsects_entrypoint_1(*section, 0);
        _gcmapsects_entrypoint_2(*section, 0);
        section++;
    } while ((void *)section != &D_808002F4_gcmapsects_lagoonbot);
    _gcmapsects_entrypoint_12(_gcmapsects_lagoonbot_entrypoint_1);
    _gcmapsects_entrypoint_14(2);
}

void gcmapsects_lagoonbot_entrypoint_1(u8 *arg0) {
    f32 func_800136E4(f32);
    f32 func_80013728(f32);
    void func_800E39A8(s32, s32);
    u8 func_800E3E8C(void *, f32);
    extern s32 D_808002F4_gcmapsects_lagoonbot;
    f32 position[3];
    f32 rotation[3];
    u8 active;

    func_800E39A8((s32)position, (s32)rotation);
    rotation[0] = func_80013728(rotation[0]);
    rotation[1] = func_800136E4(rotation[1]);
    active = arg0[0x7E];
    if (active && ((position[1] < 8000.0f && rotation[0] < -20.0f) ||
                   (position[1] < 6000.0f && rotation[0] < 0.0f))) {
        active = arg0[0x7E] = 0;
    }
    if (active && position[1] < 4000.0f && rotation[0] >= 0.0f) {
        arg0[0x7E] = func_800E3E8C(&D_808002F4_gcmapsects_lagoonbot, 982.0f);
    }
}

#endif
/* data_to_c.py: from asm/data/overlays/gc/mapsects/_lagoonbot.data.s */
s16 D_80800230_gcmapsects_lagoonbot [6] BT_DATA(4, overlays_gc_mapsects__lagoonbot, 0x0) = { 17914, 0, -14895, 24576, 17302, 0 };
s16 D_8080023C_gcmapsects_lagoonbot [6] BT_DATA(4, overlays_gc_mapsects__lagoonbot, 0xC) = { 17827, 20480, -14884, -26624, -14991, 16384 };
s16 D_80800248_gcmapsects_lagoonbot [76] BT_DATA(4, overlays_gc_mapsects__lagoonbot, 0x18) = { 17938, -25600, -14938, 30720, 17719, 0, 7500, 1838, 0, 0, 18015, 28672, -14908, -8192, -14961, -16384, 17981, -29696, -14861, 2048, -14852, -24576, 18023, -7168, -14944, 30720, -15498, 0, 7500, 1839, 0, 0, 17924, -12288, -14854, 0, -14848, 8192, 17696, -24576, -14797, -20480, -14775, 22528, 17981, -29696, -14947, -18432, -14991, 16384, 7500, 1841, 0, 0, 17982, -24576, -14995, -32768, 17835, -8192, 17853, 28672, -14921, -22528, -15498, 0, 18051, -4608, -15452, -32768, 17966, -4096, -1425, 1842, 1848, 0 };
s16 D_808002E0_gcmapsects_lagoonbot [6] BT_DATA(4, overlays_gc_mapsects__lagoonbot, 0xB0) = { 0, 2, 2, 1, 1, 3 };
s16 D_808002EC_gcmapsects_lagoonbot [4] BT_DATA(4, overlays_gc_mapsects__lagoonbot, 0xBC) = { 2, 3, 0, 1 };
s32 D_808002F4_gcmapsects_lagoonbot BT_DATA(4, overlays_gc_mapsects__lagoonbot, 0xC4) = -972206080;
s32 D_808002F8_gcmapsects_lagoonbot[2] BT_DATA(4, overlays_gc_mapsects__lagoonbot, 0xC8) = { 1169879040, -984838144 };
