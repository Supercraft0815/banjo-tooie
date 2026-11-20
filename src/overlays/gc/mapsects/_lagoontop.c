#if defined(BT_NATIVE) && !defined(BT_ILP32) // ILP32 runs the original code
#include "native_map_sections.h"
#include "native_lagoontop_data.inc"
void gcmapsects_lagoontop_entrypoint_0(void) {
    gcmapsects_entrypoint_10(sizeof(lagoonTopSections)/sizeof(*lagoonTopSections));
    for(unsigned i=0;i<sizeof(lagoonTopSections)/sizeof(*lagoonTopSections);++i) {
        const MapSectionConfig *s=lagoonTopSections+i;
        gcmapsects_entrypoint_0(s->assets[0],s->assets[1],s->position,s->minimum,s->maximum,s->height);
    }
    for(unsigned i=0;i<sizeof(lagoon_links)/sizeof(*lagoon_links);++i)gcmapsects_entrypoint_3(lagoon_links[i][0],lagoon_links[i][1]);
    for(unsigned i=0;i<sizeof(lagoon_disabled)/sizeof(*lagoon_disabled);++i) {
        gcmapsects_entrypoint_1(lagoon_disabled[i],0);gcmapsects_entrypoint_2(lagoon_disabled[i],0);
    }
    gcmapsects_entrypoint_12(gcmapsects_lagoontop_entrypoint_1);
}

void gcmapsects_lagoontop_entrypoint_1(NativeMap *arg0) {
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
    if ((arg0->sections[1].flags & SEC_VISIBLE)) {
        if (position[1] < 5100.0f) {
            arg0->sections[1].flags &= ~SEC_VISIBLE;
            arg0->sections[1].flags &= ~SEC_COLLIDABLE;
        }
        if (position[2] > -5800.0f && rotation[1] > 95.0f && rotation[1] < 240.0f) {
            arg0->sections[1].flags &= ~SEC_VISIBLE;
            arg0->sections[1].flags &= ~SEC_COLLIDABLE;
        }
    }
    if ((arg0->sections[0].flags & SEC_VISIBLE)) {
        if (position[1] < 4200.0f && rotation[0] < 0.0f) {
            arg0->sections[0].flags &= ~SEC_VISIBLE;
        } else if (position[1] < 5050.0f && !func_800E3E8C(lagoonTopPoints[0], 1250.0f)) {
            arg0->sections[0].flags &= ~SEC_VISIBLE;
            arg0->sections[0].flags &= ~SEC_COLLIDABLE;
        }
    }
    if ((arg0->sections[4].flags & SEC_VISIBLE) && position[1] > 4300.0f) {
        arg0->sections[4].flags &= ~SEC_VISIBLE;
        arg0->sections[4].flags &= ~SEC_COLLIDABLE;
    }
    if ((arg0->sections[2].flags & SEC_VISIBLE)) {
        if (position[2] > 0.0f && rotation[1] > 160.0f && rotation[1] < 320.0f) {
            arg0->sections[2].flags &= ~SEC_VISIBLE;
            arg0->sections[2].flags &= ~SEC_COLLIDABLE;
        } else if (position[1] > 5150.0f && !func_800E3E8C(lagoonTopPoints[1], 1000.0f)) {
            arg0->sections[2].flags &= ~SEC_VISIBLE;
            arg0->sections[2].flags &= ~SEC_COLLIDABLE;
        } else if (position[0] > -4700.0f && position[1] < 10000.0f) {
            arg0->sections[2].flags &= ~SEC_VISIBLE;
            arg0->sections[2].flags &= ~SEC_COLLIDABLE;
        }
    }
    if ((arg0->sections[4].flags & SEC_VISIBLE)) {
        if (position[2] > 4000.0f) {
            if (rotation[1] > 90.0f && rotation[1] < 270.0f) {
                arg0->sections[4].flags &= ~SEC_VISIBLE;
                arg0->sections[4].flags &= ~SEC_COLLIDABLE;
            }
        } else if (!(arg0->sections[4].flags & SEC_COLLIDABLE) && !func_800E3E8C(lagoonTopPoints[2], 450.0f)) {
            arg0->sections[4].flags &= ~SEC_VISIBLE;
            arg0->sections[4].flags &= ~SEC_COLLIDABLE;
        }
    }
    active = arg0->section_flags[S_SECONDARY];
    if (active && ((position[1] < 8000.0f && rotation[0] < -20.0f) ||
                   (position[1] < 6000.0f && rotation[0] < 0.0f))) {
        active = arg0->section_flags[S_SECONDARY] = 0;
    }
    if (active && position[1] < 4000.0f && rotation[0] >= 0.0f) {
        arg0->section_flags[S_SECONDARY] = func_800E3E8C(lagoonTopPoints[3], 982.0f);
    }
    if ((arg0->sections[0].flags & SEC_COLLIDABLE)) {
        arg0->sections[1].flags |= SEC_COLLIDABLE;
    }
}

#else
#include "common.h"
#include "gc/map_section_config.h"
void gcmapsects_lagoontop_entrypoint_0(void) { BT_NATIVE_ONLY(extern MapSectionConfig lagoonTopSections[5];) BT_IDO_ONLY(void _gcmapsects_entrypoint_0(s32, s32, void *, void *, void *, f32);) BT_NATIVE_ONLY(void _gcmapsects_entrypoint_0(s16, s16, f32 *, f32 *, f32 *, f32);) BT_IDO_ONLY(void _gcmapsects_entrypoint_1(s32, s32);) BT_NATIVE_ONLY(void _gcmapsects_entrypoint_1(s16, s32);) BT_IDO_ONLY(void _gcmapsects_entrypoint_2(s32, s32);) BT_NATIVE_ONLY(void _gcmapsects_entrypoint_2(s16, s32);) BT_IDO_ONLY(void _gcmapsects_entrypoint_3(s32, s32);) BT_NATIVE_ONLY(void _gcmapsects_entrypoint_3(s16, s16);) void _gcmapsects_entrypoint_10(s32); void _gcmapsects_entrypoint_12(void (*)(u8 *)); void _gcmapsects_lagoontop_entrypoint_1(u8 *); extern s16 D_80800630_gcmapsects_lagoontop[]; extern s16 D_8080063C_gcmapsects_lagoontop[]; extern s16 D_80800648_gcmapsects_lagoontop[]; extern s16 D_8080070C_gcmapsects_lagoontop[]; extern s16 D_8080071C_gcmapsects_lagoontop[BT_NATIVE_ONLY(2)]; extern s32 D_80800720_gcmapsects_lagoontop; extern s32 D_80800724_gcmapsects_lagoontop[2]; s16 *section; s16 *scale; u32 limit; s32 i; s16 *rotation; _gcmapsects_entrypoint_10(5); i = 0; do { _gcmapsects_entrypoint_0(BT_DATA_FIELD(lagoonTopSections[i].assets[0], D_80800630_gcmapsects_lagoontop[i * 22 + 19]), BT_DATA_FIELD(lagoonTopSections[i].assets[1], D_80800630_gcmapsects_lagoontop[i * 22 + 20]), BT_DATA_FIELD(lagoonTopSections[i].position, &D_80800630_gcmapsects_lagoontop[i * 22]), BT_DATA_FIELD(lagoonTopSections[i].minimum, &D_8080063C_gcmapsects_lagoontop[i * 22]), BT_DATA_FIELD(lagoonTopSections[i].maximum, &D_80800648_gcmapsects_lagoontop[i * 22]), BT_DATA_FIELD(lagoonTopSections[i].height, D_80800630_gcmapsects_lagoontop[i * 22 + 18])); i++; } while (BT_DATA_FIELD(i < 5, (void *)&D_80800648_gcmapsects_lagoontop[i * 22] < (void *)D_80800724_gcmapsects_lagoontop)); section = D_8080070C_gcmapsects_lagoontop; i = 0; do { _gcmapsects_entrypoint_3(section[0], section[1]); section += 2; i++; limit = (u32)i < 4; } while (limit); section = D_8080071C_gcmapsects_lagoontop; do { _gcmapsects_entrypoint_1(*section, 0); _gcmapsects_entrypoint_2(*section, 0); section++; } while (BT_DATA_FIELD(section != D_8080071C_gcmapsects_lagoontop + ARRLEN(D_8080071C_gcmapsects_lagoontop), (void *)section != &D_80800720_gcmapsects_lagoontop)); _gcmapsects_entrypoint_12(_gcmapsects_lagoontop_entrypoint_1); }

void gcmapsects_lagoontop_entrypoint_1(u8 *arg0) {
    typedef struct {
        u8 pad[0x4C];
        BT_BITFIELD_ORDER(u32 visible : 1, u32 remaining : 30);
        u32 active : 1;
        BT_BITFIELD_ORDER(u32 remaining : 30, u32 visible : 1);
        u8 tail[8];
    } Section;
    f32 func_800136E4(f32);
    f32 func_80013728(f32);
    void func_800E39A8(s32, s32);
    BT_IDO_ONLY(u8 func_800E3E8C(void *, f32);) BT_NATIVE_ONLY(s32 func_800E3E8C(f32 *, f32);)
    BT_NATIVE_ONLY(extern f32 lagoonTopPoints[4][3];) BT_IDO_ONLY(extern s32 D_80800720_gcmapsects_lagoontop;)
    extern s32 D_8080072C_gcmapsects_lagoontop[3];
    extern s32 D_80800738_gcmapsects_lagoontop[3];
    extern s32 D_80800744_gcmapsects_lagoontop[3];
    f32 position[3];
    f32 rotation[3];
    u8 active;

    func_800E39A8((s32)position, (s32)rotation);
    rotation[0] = func_80013728(rotation[0]);
    rotation[1] = func_800136E4(rotation[1]);
    if ((*(Section **)(arg0 + 0x68))[1].visible) {
        if (position[1] < 5100.0f) {
            (*(Section **)(arg0 + 0x68))[1].visible = 0;
            (*(Section **)(arg0 + 0x68))[1].active = 0;
        }
        if (position[2] > -5800.0f && rotation[1] > 95.0f && rotation[1] < 240.0f) {
            (*(Section **)(arg0 + 0x68))[1].visible = 0;
            (*(Section **)(arg0 + 0x68))[1].active = 0;
        }
    }
    if ((*(Section **)(arg0 + 0x68))[0].visible) {
        if (position[1] < 4200.0f && rotation[0] < 0.0f) {
            (*(Section **)(arg0 + 0x68))[0].visible = 0;
        } else if (position[1] < 5050.0f && !func_800E3E8C(BT_DATA_FIELD(lagoonTopPoints[0], &D_80800720_gcmapsects_lagoontop), 1250.0f)) {
            (*(Section **)(arg0 + 0x68))[0].visible = 0;
            (*(Section **)(arg0 + 0x68))[0].active = 0;
        }
    }
    if ((*(Section **)(arg0 + 0x68))[4].visible && position[1] > 4300.0f) {
        (*(Section **)(arg0 + 0x68))[4].visible = 0;
        (*(Section **)(arg0 + 0x68))[4].active = 0;
    }
    if ((*(Section **)(arg0 + 0x68))[2].visible) {
        if (position[2] > 0.0f && rotation[1] > 160.0f && rotation[1] < 320.0f) {
            (*(Section **)(arg0 + 0x68))[2].visible = 0;
            (*(Section **)(arg0 + 0x68))[2].active = 0;
        } else if (position[1] > 5150.0f && !func_800E3E8C(BT_DATA_FIELD(lagoonTopPoints[1], D_8080072C_gcmapsects_lagoontop), 1000.0f)) {
            (*(Section **)(arg0 + 0x68))[2].visible = 0;
            (*(Section **)(arg0 + 0x68))[2].active = 0;
        } else if (position[0] > -4700.0f && position[1] < 10000.0f) {
            (*(Section **)(arg0 + 0x68))[2].visible = 0;
            (*(Section **)(arg0 + 0x68))[2].active = 0;
        }
    }
    if ((*(Section **)(arg0 + 0x68))[4].visible) {
        if (position[2] > 4000.0f) {
            if (rotation[1] > 90.0f && rotation[1] < 270.0f) {
                (*(Section **)(arg0 + 0x68))[4].visible = 0;
                (*(Section **)(arg0 + 0x68))[4].active = 0;
            }
        } else if (!(*(Section **)(arg0 + 0x68))[4].active && !func_800E3E8C(BT_DATA_FIELD(lagoonTopPoints[2], D_80800738_gcmapsects_lagoontop), 450.0f)) {
            (*(Section **)(arg0 + 0x68))[4].visible = 0;
            (*(Section **)(arg0 + 0x68))[4].active = 0;
        }
    }
    active = arg0[0x7E];
    if (active && ((position[1] < 8000.0f && rotation[0] < -20.0f) ||
                   (position[1] < 6000.0f && rotation[0] < 0.0f))) {
        active = arg0[0x7E] = 0;
    }
    if (active && position[1] < 4000.0f && rotation[0] >= 0.0f) {
        arg0[0x7E] = BT_NATIVE_ONLY((u8)) func_800E3E8C(BT_DATA_FIELD(lagoonTopPoints[3], D_80800744_gcmapsects_lagoontop), 982.0f);
    }
    if ((*(Section **)(arg0 + 0x68))[0].active) {
        (*(Section **)(arg0 + 0x68))[1].active = 1;
    }
}

#endif
/* data_to_c.py: from asm/data/overlays/gc/mapsects/_lagoontop.data.s */
#include "lagoon_top_sections.inc"
s16 D_8080070C_gcmapsects_lagoontop [8] BT_DATA(4, overlays_gc_mapsects__lagoontop, 0xDC) = { 1, 0, 0, 2, 2, 4, 2, 3 };
s16 D_8080071C_gcmapsects_lagoontop [2] BT_DATA(4, overlays_gc_mapsects__lagoontop, 0xEC) = { 3, 4 };
f32 lagoonTopPoints[4][3] BT_DATA(4, overlays_gc_mapsects__lagoontop, 0xF0) = {
    {-9044.0f, 5050.0f, -3273.0f},
    {-9044.0f, 5150.0f, -3273.0f},
    {-6767.0f, -520.0f, -103.0f},
    {-9044.0f, 5982.0f, -3273.0f}, };
