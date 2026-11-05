#include "native_map.h"
#include "memory.h"
#include "map_dependencies.h"
#include <stdio.h>
#include <stdlib.h>
#define CHECK(x) do {if(!(x)){fprintf(stderr,"%s:%d: %s\n",__FILE__,__LINE__,#x);exit(1);}}while(0)
/* Rendering, camera/player input and asynchronous asset scheduling are test boundaries. */
int map_test_flags,map_test_mode,map_test_state;
int map_test_lights,map_test_modules,map_test_instances;
int map_test_busy,map_test_player_active,map_test_frustum=1,map_test_async_ready=1,map_test_sound;
void *map_test_glid5_vertices,*map_test_glid6_vertices;
int map_test_hidden,map_test_instance_enabled;
float map_test_camera[3],map_test_rotation[3],map_test_player[3];
s32 func_800EA068(s32 mask) {return map_test_flags&mask;}
s32 func_800A946C(void) {return map_test_mode;}
s32 func_800DA298(s32 flag) {CHECK(flag==0x360);return map_test_state;}
void _dblight_entrypoint_0(void *data,void *vertices,s32 *color) {CHECK(data && vertices && color);}
void _dblight_entrypoint_1(void *data,void *vertices,void *normals) {CHECK(data && vertices);}
void *_rtlight_entrypoint_1(void *data,void *vertices,void *normals) {CHECK(data && vertices);++map_test_lights;return heap_alloc(8);}
void _rtlight_entrypoint_0(void *state) {CHECK(state && map_test_lights>0);--map_test_lights;heap_free(state);}
void *_vpmodule_entrypoint_0(void *data,void *vertices,s32 *color) {CHECK(data && vertices && color);++map_test_modules;return heap_alloc(8);}
void _vpmodule_entrypoint_1(void *state,void *data) {CHECK(state && data && map_test_modules>0);--map_test_modules;heap_free(state);}
void *_glidmake_entrypoint_5(u16 id,void *section) {CHECK(id);++map_test_instances;return heap_alloc(8);}
void _glidmake_entrypoint_4(void *state) {CHECK(state && map_test_instances>0);--map_test_instances;heap_free(state);}
void _glid_entrypoint_6(void *state,void *vertices) {CHECK(state && vertices);map_test_glid6_vertices=vertices;}
void _idworldmake_entrypoint_0(void *state,s32 mode) {CHECK(state && (mode==1 || mode==2));}
void _idworldmake_entrypoint_2(void *state) {CHECK(state && map_test_instances>0);}
void _glid_entrypoint_5(void *state,void *vertices) {CHECK(state && vertices);map_test_glid5_vertices=vertices;}
s32 func_800DB9B0(void) {return map_test_busy;}
s32 func_800E4AF0(s32 id) {return 0;}
void func_800E4BB8(s32 id) {CHECK(id);}
s32 func_800E488C(s32 id) {CHECK(id);return map_test_async_ready;}
void func_800E3980(f32 *out) {for(int i=0;i<3;++i)out[i]=map_test_camera[i];}
void func_800E39A8(f32 *position,f32 *rotation) {for(int i=0;i<3;++i){position[i]=map_test_camera[i];rotation[i]=map_test_rotation[i];}}
s32 func_800E3E8C(f32 *center,f32 radius) {CHECK(center && radius>=0);return map_test_frustum;}
s32 func_800E3D0C(f32 *lower,f32 *upper) {CHECK(lower && upper);return map_test_frustum;}
void func_8008FE68(f32 *out) {for(int i=0;i<3;++i)out[i]=map_test_player[i];}
s32 func_80090128(void) {return map_test_player_active;}
u32 func_800F54E4(void) {return 7;}
void func_800F4CC0(s32 player) {CHECK(player==7);--map_test_sound;}
void func_800F4CEC(s32 player,u32 sound) {CHECK(player==7 && sound==0x77);++map_test_sound;}

void _idworldmake_entrypoint_5(void *state,s32 enabled) {CHECK(state && map_test_instances>0);++map_test_hidden;map_test_instance_enabled=enabled;}
