#if defined(BT_NATIVE) && !defined(BT_ILP32) // ILP32 runs the original code
#include "native_map_sections.h"
#include "native_lagoonbot_data.inc"
void gcmapsects_lagoonbot_entrypoint_0(void) {
    gcmapsects_entrypoint_10(sizeof(lagoonBottomSections)/sizeof(*lagoonBottomSections));
    for(unsigned i=0;i<sizeof(lagoonBottomSections)/sizeof(*lagoonBottomSections);++i) {
        const MapSectionConfig *s=lagoonBottomSections+i;
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
        arg0->section_flags[S_SECONDARY] = func_800E3E8C(lagoonBottomPoint, 982.0f);
    }
}

#else
#include "common.h"
#include "gc/map_section_config.h"
void gcmapsects_lagoonbot_entrypoint_0(void) { BT_NATIVE_ONLY(extern MapSectionConfig lagoonBottomSections[4];)
    BT_IDO_ONLY(void _gcmapsects_entrypoint_0(s32, s32, void *, void *, void *, f32);) BT_NATIVE_ONLY(void _gcmapsects_entrypoint_0(s16, s16, f32 *, f32 *, f32 *, f32);)
    BT_IDO_ONLY(void _gcmapsects_entrypoint_1(s32, s32);) BT_NATIVE_ONLY(void _gcmapsects_entrypoint_1(s16, s32);)
    BT_IDO_ONLY(void _gcmapsects_entrypoint_2(s32, s32);) BT_NATIVE_ONLY(void _gcmapsects_entrypoint_2(s16, s32);)
    BT_IDO_ONLY(void _gcmapsects_entrypoint_3(s32, s32);) BT_NATIVE_ONLY(void _gcmapsects_entrypoint_3(s16, s16);)
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
        _gcmapsects_entrypoint_0(BT_DATA_FIELD(lagoonBottomSections[i].assets[0], D_80800230_gcmapsects_lagoonbot[i * 22 + 19]),
                                 BT_DATA_FIELD(lagoonBottomSections[i].assets[1], D_80800230_gcmapsects_lagoonbot[i * 22 + 20]),
                                 BT_DATA_FIELD(lagoonBottomSections[i].position, &D_80800230_gcmapsects_lagoonbot[i * 22]),
                                 BT_DATA_FIELD(lagoonBottomSections[i].minimum, &D_8080023C_gcmapsects_lagoonbot[i * 22]),
                                 BT_DATA_FIELD(lagoonBottomSections[i].maximum, &D_80800248_gcmapsects_lagoonbot[i * 22]),
                                 BT_DATA_FIELD(lagoonBottomSections[i].height, D_80800230_gcmapsects_lagoonbot[i * 22 + 18]));
        i++;
    } while (BT_DATA_FIELD(i < (s32)ARRLEN(lagoonBottomSections), (void *)&D_80800248_gcmapsects_lagoonbot[i * 22] < (void *)D_808002F8_gcmapsects_lagoonbot));
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
    } while (BT_DATA_FIELD(section != D_808002EC_gcmapsects_lagoonbot + 4, (void *)section != &D_808002F4_gcmapsects_lagoonbot));
    _gcmapsects_entrypoint_12(_gcmapsects_lagoonbot_entrypoint_1);
    _gcmapsects_entrypoint_14(2);
}

void gcmapsects_lagoonbot_entrypoint_1(u8 *arg0) {
    f32 func_800136E4(f32);
    f32 func_80013728(f32);
    void func_800E39A8(s32, s32);
    BT_IDO_ONLY(u8 func_800E3E8C(void *, f32);) BT_NATIVE_ONLY(s32 func_800E3E8C(f32 *, f32);)
    BT_NATIVE_ONLY(extern f32 lagoonBottomPoint[3];) BT_IDO_ONLY(extern s32 D_808002F4_gcmapsects_lagoonbot;)
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
        arg0[0x7E] = BT_NATIVE_ONLY((u8)) func_800E3E8C(BT_DATA_FIELD(lagoonBottomPoint, &D_808002F4_gcmapsects_lagoonbot), 982.0f);
    }
}

#endif
/* data_to_c.py: from asm/data/overlays/gc/mapsects/_lagoonbot.data.s */
#include "lagoon_bottom_sections.inc"


s16 D_808002E0_gcmapsects_lagoonbot [6] BT_DATA(4, overlays_gc_mapsects__lagoonbot, 0xB0) = { 0, 2, 2, 1, 1, 3 };
s16 D_808002EC_gcmapsects_lagoonbot [4] BT_DATA(4, overlays_gc_mapsects__lagoonbot, 0xBC) = { 2, 3, 0, 1 };
f32 lagoonBottomPoint[3] BT_DATA(4, overlays_gc_mapsects__lagoonbot, 0xC4) = {-9044.0f, 5982.0f, -3273.0f};
