#ifdef BT_NATIVE
#include "native_map_sections.h"
#include "native_lagoontop_data.inc"
void gcmapsects_lagoontop_entrypoint_0(void) {
    gcmapsects_entrypoint_10(sizeof(lagoon_sections)/sizeof(*lagoon_sections));
    for(unsigned i=0;i<sizeof(lagoon_sections)/sizeof(*lagoon_sections);++i) {
        const NativeMapSectionConfig *s=lagoon_sections+i;
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
        } else if (position[1] < 5050.0f && !func_800E3E8C(lagoon_points[0], 1250.0f)) {
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
        } else if (position[1] > 5150.0f && !func_800E3E8C(lagoon_points[1], 1000.0f)) {
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
        } else if (!(arg0->sections[4].flags & SEC_COLLIDABLE) && !func_800E3E8C(lagoon_points[2], 450.0f)) {
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
        arg0->section_flags[S_SECONDARY] = func_800E3E8C(lagoon_points[3], 982.0f);
    }
    if ((arg0->sections[0].flags & SEC_COLLIDABLE)) {
        arg0->sections[1].flags |= SEC_COLLIDABLE;
    }
}

#else
#include "common.h"

void gcmapsects_lagoontop_entrypoint_0(void) { void _gcmapsects_entrypoint_0(s32, s32, void *, void *, void *, f32); void _gcmapsects_entrypoint_1(s32, s32); void _gcmapsects_entrypoint_2(s32, s32); void _gcmapsects_entrypoint_3(s32, s32); void _gcmapsects_entrypoint_10(s32); void _gcmapsects_entrypoint_12(void (*)(u8 *)); void _gcmapsects_lagoontop_entrypoint_1(u8 *); extern s16 D_80800630_gcmapsects_lagoontop[]; extern s16 D_8080063C_gcmapsects_lagoontop[]; extern s16 D_80800648_gcmapsects_lagoontop[]; extern s16 D_8080070C_gcmapsects_lagoontop[]; extern s16 D_8080071C_gcmapsects_lagoontop[]; extern s32 D_80800720_gcmapsects_lagoontop; extern s32 D_80800724_gcmapsects_lagoontop; s16 *section; s16 *scale; u32 limit; s32 i; s16 *rotation; _gcmapsects_entrypoint_10(5); i = 0; do { _gcmapsects_entrypoint_0(D_80800630_gcmapsects_lagoontop[i * 22 + 19], D_80800630_gcmapsects_lagoontop[i * 22 + 20], &D_80800630_gcmapsects_lagoontop[i * 22], &D_8080063C_gcmapsects_lagoontop[i * 22], &D_80800648_gcmapsects_lagoontop[i * 22], D_80800630_gcmapsects_lagoontop[i * 22 + 18]); i++; } while ((void *)&D_80800648_gcmapsects_lagoontop[i * 22] < (void *)&D_80800724_gcmapsects_lagoontop); section = D_8080070C_gcmapsects_lagoontop; i = 0; do { _gcmapsects_entrypoint_3(section[0], section[1]); section += 2; i++; limit = (u32)i < 4; } while (limit); section = D_8080071C_gcmapsects_lagoontop; do { _gcmapsects_entrypoint_1(*section, 0); _gcmapsects_entrypoint_2(*section, 0); section++; } while ((void *)section != &D_80800720_gcmapsects_lagoontop); _gcmapsects_entrypoint_12(_gcmapsects_lagoontop_entrypoint_1); }

void gcmapsects_lagoontop_entrypoint_1(u8 *arg0) {
    typedef struct {
        u8 pad[0x4C];
        u32 visible : 1;
        u32 active : 1;
        u32 remaining : 30;
        u8 tail[8];
    } Section;
    f32 func_800136E4(f32);
    f32 func_80013728(f32);
    void func_800E39A8(s32, s32);
    u8 func_800E3E8C(void *, f32);
    extern s32 D_80800720_gcmapsects_lagoontop;
    extern s32 D_8080072C_gcmapsects_lagoontop;
    extern s32 D_80800738_gcmapsects_lagoontop;
    extern s32 D_80800744_gcmapsects_lagoontop;
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
        } else if (position[1] < 5050.0f && !func_800E3E8C(&D_80800720_gcmapsects_lagoontop, 1250.0f)) {
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
        } else if (position[1] > 5150.0f && !func_800E3E8C(&D_8080072C_gcmapsects_lagoontop, 1000.0f)) {
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
        } else if (!(*(Section **)(arg0 + 0x68))[4].active && !func_800E3E8C(&D_80800738_gcmapsects_lagoontop, 450.0f)) {
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
        arg0[0x7E] = func_800E3E8C(&D_80800744_gcmapsects_lagoontop, 982.0f);
    }
    if ((*(Section **)(arg0 + 0x68))[0].active) {
        (*(Section **)(arg0 + 0x68))[1].active = 1;
    }
}

#endif
