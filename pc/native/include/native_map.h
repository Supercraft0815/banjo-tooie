#ifndef BT_NATIVE_MAP_H
#define BT_NATIVE_MAP_H
#include "native_model.h"

#include "overlays/gc/mapDll_config.h"
typedef MapConfig NativeMapConfig;
_Static_assert(sizeof(NativeMapConfig)==14,"map configuration layout");
typedef struct {
    void *collision,*instances,*light,*model;
    NativeVertexList *vertices[2];
    void *vpl,*module,*zones,*texture;
    u8 animation,index,collides,enabled;
} NativeMapLayer;
typedef struct NativeMap NativeMap;
typedef struct NativeMapSection NativeMapSection;
struct NativeMap {
    NativeMapLayer layers[2];
    NativeMapConfig config;
    NativeMapSection *sections;
    void (*section_update)(NativeMap *);
    f32 section_distance;
    s16 selected_section;
    u8 section_capacity,section_count,section_flags[12];
    s8 lighting_type;
    u8 color[3];
    s32 switches[60];
    void *vectors,*zone_state;
    s32 minimum[3],maximum[3],combined_minimum[3],combined_maximum[3];
    void *collision_model;
    u8 sections_failed;
};
extern NativeMap native_map;
extern const NativeMapConfig native_map_configs[];
extern const s16 native_map_cell_sizes[][2];

const NativeMapConfig *func_80800000_gcmapDll(s32);
s32 gcmapDll_entrypoint_0(s32);
void gcmapDll_entrypoint_1(NativeMap *);
void func_8080045C_gcmapDll(NativeMap *,s32,s32 *,s32 *);
void func_808005A8_gcmapDll(NativeMap *);
void func_80800668_gcmapDll(NativeMap *,const s16 (*)[2],s32);
void gcmapDll_entrypoint_2(NativeMap *);
s32 gcmapDll_entrypoint_3(NativeMap *);
void func_80800A94_gcmapDll(NativeMap *,s32);
void gcmapDll_entrypoint_4(NativeMap *);
s16 gcmapDll_entrypoint_5(void);
s32 gcmapDll_entrypoint_6(NativeMap *,s32);
void func_800BEC4C(s32 *,s32 *,s32);
f32 func_800BECCC(void);
void func_800BECE0(s32 *,s32 *);
void func_800BED18(s32 *,s32 *);
#endif
