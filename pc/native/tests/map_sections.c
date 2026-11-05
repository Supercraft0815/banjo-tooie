#include "native_map_sections.h"
#include "native_map_runtime.h"
#include "native_assets.h"
#include "core2/1EAF950.h"
#include "map_dependencies.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define CHECK(x) do {if(!(x)){fprintf(stderr,"%s:%d: %s\n",__FILE__,__LINE__,#x);exit(1);}}while(0)
static s32 level;
s32 func_800EA05C(void) {return level;}
s32 func_8001211C(void) {return 100;}
void func_800F0524(f32 *,f32 *,f32 *);
f32 func_800F0C68(f32 *,f32 *,f32,f32);

/* Observe the still-unported renderer and collision backend at their typed boundaries. */
static int draws,draw_side,primary_changes,collisions,hit_on=1;
static void *draw_vertices,*draw_textures,*collision_token;
static int drawing_mode,swap_vertices=1,light_updates,module_updates,module_draws,instance_commands,module_commands,vpl_mode=1;
static int base_queries,section_queries,random_calls,switch_calls;
static void *draw_vectors,*draw_zones;
static u32 draw_color[4];
s32 func_800EA340(void) {return swap_vertices;}
f32 func_800DC178(f32 a,f32 b) {CHECK(a==-1 && b==1);++random_calls;return 0;}
void func_800DF738(void *data) {draw_vectors=data;}
void func_800DF83C(void *data) {draw_zones=data;}
void func_800DF5D8(u32 r,u32 g,u32 b,s32 a) {draw_color[0]=r;draw_color[1]=g;draw_color[2]=b;draw_color[3]=a;}
void _rtlight_entrypoint_2(void *state,void *vertices,void *normals,s32 copies) {
    CHECK(state && vertices && normals && (copies==1 || copies==2));++light_updates;
}
void _vpmodule_entrypoint_2(void *state,void *data) {CHECK(state && data);++module_updates;}
void _vpmodule_entrypoint_3(void *state,void *data,void *vertices) {CHECK(state && data && vertices);++module_draws;}
s32 _vpmodule_entrypoint_4(void *state,void *data,s32 a,s32 b) {CHECK(state && data && a==4 && b==7);++module_commands;return 1;}
void _idworldmake_entrypoint_6(void *state,s32 a,s32 b) {CHECK(state && a==4 && b==7);++instance_commands;}
void _idworldmake_entrypoint_7(void *state,s32 a,s32 b) {CHECK(state && a==4 && b==7);++instance_commands;}
void *_dbvpl_entrypoint_0(void *data,s32 index) {CHECK(data && !index);return vpl_mode ? data : NULL;}
void func_800BFF28(void) {--primary_changes;}
void func_800BFF4C(void) {++primary_changes;}
void func_800DF744(s32 index,s32 value) {CHECK(index>0 && index<60 && value==native_map.switches[index]);++switch_calls;}
void func_800DF830(s32 side) {CHECK(side==1 || side==2);draw_side=side;}
void func_800DF7E8(u8 animation) {CHECK(animation);}
void func_800DF440(s32 mode) {CHECK(!mode);}
f32 func_800DF428(f32 distance) {CHECK(distance==29999);return distance;}
void func_800DF4B0(s32 mode) {CHECK(mode==1 || mode==2);drawing_mode=mode;}
void func_800DF7DC(void *textures) {CHECK(textures);draw_textures=textures;}
void func_800DF818(void *vertices) {CHECK(vertices);draw_vertices=vertices;}
void *func_800DE448(f32 *position,f32 *rotation,f32 scale,f32 *pivot,void *model) {
    CHECK(!rotation && scale==1 && !pivot && model && draw_textures);
    if(drawing_mode==2)CHECK(position && draw_vertices==func_800B2840(model));
    else CHECK(!position && model==native_map.layers[draw_side-1].model && draw_vertices==func_800BEB64(draw_side-1));
    ++draws;return NULL;
}
static void *collision(void *mesh,void *vertices,f32 *position) {
    CHECK(mesh && vertices && position);++collisions;
    return !hit_on || collisions==hit_on ? collision_token : NULL;
}
s32 func_800AD2C8(void *mesh,void *vertices,f32 *a,f32 *b,f32 *position,s16 (**out)[3],s32 flags,f32 scale) {
    CHECK(a && b && out && flags==123 && scale==2);return collision(mesh,vertices,position)!=NULL;
}
s32 func_800AD894(void *mesh,void *vertices,f32 *a,f32 *b,f32 *out,f32 *position,f32 radius) {
    CHECK(a && b && out && radius==4);return collision(mesh,vertices,position)!=NULL;
}
void *func_800AB868(void *mesh,void *vertices,f32 *position,f32 *rotation,f32 scale,f32 *a,f32 *b,f32 *out,s32 flags) {
    CHECK(!rotation && scale==1 && a && b && out);++section_queries;return collision(mesh,vertices,position);
}
void *func_800AC848(void *mesh,void *vertices,f32 *position,f32 *rotation,f32 scale,f32 *a,f32 *b,f32 radius,f32 *out,s32 flags,s32 mode) {
    CHECK(!rotation && scale==1 && a && b && out && radius==4 && flags==123 && mode==5);return collision(mesh,vertices,position);
}
void *func_800AD1AC(void *mesh,void *vertices,f32 *position,f32 *rotation,f32 scale,f32 *a,f32 radius,f32 *out,u32 flags) {
    CHECK(!rotation && scale==1 && a && out && radius==4 && flags==123);return collision(mesh,vertices,position);
}
void *func_800AB0BC(void *mesh,void *vertices,f32 *a,f32 *b,f32 *out,u32 flags) {
    f32 origin[3]={0};++base_queries;CHECK(a && b && out);
    void *hit=collision(mesh,vertices,origin);if(hit){b[1]=42;out[0]=0;out[1]=1;out[2]=0;}return hit;
}
void *func_800AC638(void *mesh,void *vertices,f32 *a,f32 *b,f32 radius,f32 *out,s32 flags,u32 mode) {
    f32 origin[3]={0};++base_queries;CHECK(a && b && out && radius==4 && flags==123 && mode==5);return collision(mesh,vertices,origin);
}
void *func_800AC978(void *mesh,void *vertices,f32 *a,f32 radius,f32 *out,u32 flags) {
    f32 origin[3]={0};++base_queries;CHECK(a && out && radius==4 && flags==123);return collision(mesh,vertices,origin);
}
static int callbacks;
static void update(NativeMap *map) {CHECK(map==&native_map);++callbacks;}
static void add_section(u16 primary,u16 secondary,f32 x) {
    f32 origin[3]={x,0,0},lower[3]={x-100,-100,-100},upper[3]={x+100,100,100};
    gcmapsects_entrypoint_0(primary,secondary,origin,lower,upper,5000);
}
static void test_geometry(void) {
    CHECK(gcmapsects_entrypoint_15(&native_map));gcmapsects_entrypoint_10(2);
    add_section(0,0,0);add_section(0,0,1000);gcmapsects_entrypoint_3(0,1);
    NativeMapSection *s=native_map.sections;
    CHECK(s[0].minimum[0]==-150 && s[0].maximum[0]==150 && fabsf(s[0].radius-sqrtf(67500))<0.001f);
    CHECK(s[0].neighbors[0]==1 && s[1].neighbors[0]==0 && s[0].neighbors[1]==255);
    gcmapsects_entrypoint_3(-1,0);gcmapsects_entrypoint_1(-1,0);gcmapsects_entrypoint_2(2,0);
    f32 point[3]={0},height=0;
    CHECK(gcmapsects_entrypoint_4(point)==0 && gcmapsects_entrypoint_7(point)==0);
    CHECK(gcmapsects_entrypoint_6(&native_map,point,&height) && height==5000);
    point[0]=-150;CHECK(gcmapsects_entrypoint_4(point)==-1);point[0]=0;
    s[0].height=100;CHECK(!gcmapsects_entrypoint_6(&native_map,point,&height));
    CHECK(!gcmapsects_entrypoint_5(0) && gcmapsects_entrypoint_5(-1));
    CHECK(func_80800DC8_gcmapsects(&native_map,0,point)==0);
    CHECK(gcmapsects_entrypoint_5(0) && (s[1].flags&(SEC_VISIBLE|SEC_ACTIVE))==(SEC_VISIBLE|SEC_ACTIVE));
    CHECK(!(s[1].flags&SEC_COLLIDABLE));s[0].hidden[0]=1;func_808013C0_gcmapsects(&native_map,0);
    CHECK(!(s[1].flags&SEC_VISIBLE));
    map_test_frustum=0;CHECK(!func_80801174_gcmapsects(&native_map,1));map_test_frustum=1;
    CHECK(func_80801174_gcmapsects(&native_map,1));
    gcmapsects_entrypoint_1(0,0);gcmapsects_entrypoint_2(0,0);CHECK(!(s[0].flags&(SEC_PRIMARY|SEC_SECONDARY)));
    gcmapsects_entrypoint_12(update);CHECK(native_map.section_update==update);
    native_map.section_flags[S_MODE]=1;map_test_player_active=1;
    gcmapsects_entrypoint_9(&native_map);CHECK(callbacks==1 && native_map.selected_section==0 && !gcmapsects_entrypoint_24(&native_map));
    map_test_player[0]=10000;gcmapsects_entrypoint_9(&native_map);CHECK(gcmapsects_entrypoint_24(&native_map));
    map_test_busy=1;gcmapsects_entrypoint_9(&native_map);CHECK(map_test_sound==1 && !native_map.section_flags[S_READY]);
    map_test_busy=0;gcmapsects_entrypoint_9(&native_map);CHECK(!map_test_sound && native_map.section_flags[S_READY]);
    map_test_player_active=0;map_test_player[0]=0;
    native_map.section_flags[S_PREVIOUS_PRIMARY]=1;gcmapsects_entrypoint_11(0,0);
    for(int i=0;i<2;++i){gcmapsects_entrypoint_1(i,0);gcmapsects_entrypoint_2(i,0);}
    gcmapsects_entrypoint_9(&native_map);gcmapsects_entrypoint_17(&native_map);CHECK(primary_changes==-1 && !native_map.layers[1].enabled);
    gcmapsects_entrypoint_11(1,1);gcmapsects_entrypoint_9(&native_map);gcmapsects_entrypoint_17(&native_map);CHECK(!primary_changes && native_map.layers[1].enabled);
    add_section(0,0,0);CHECK(native_map.sections_failed && native_map.section_count==2);
    gcmapsects_entrypoint_16(&native_map);gcmapsects_entrypoint_16(&native_map);CHECK(!native_map.sections && !native_map.section_update);
    gcmapsects_entrypoint_10(255);for(int i=0;i<255;++i)add_section(0,0,i*1000);
    CHECK(native_map.section_count==255);gcmapsects_entrypoint_16(&native_map);
    native_map.sections_failed=0;gcmapsects_entrypoint_10(256);CHECK(native_map.sections_failed && !native_map.sections);
    f32 triangle[9]={0,0,0,10,0,0,0,0,10},above[3]={2,7,3},projected[3],direction[3]={0,3,4};
    func_800F0524(projected,triangle,above);CHECK(projected[0]==2 && projected[1]==0 && projected[2]==3);
    CHECK(fabsf(func_800F0C68(NULL,direction,3,4)-0.6f)<0.00001f && fabsf(direction[1]-0.6f)<0.00001f && fabsf(direction[2]-0.8f)<0.00001f);
}
static void test_resources(const char *archive) {
    CHECK(native_assets_open(archive));CHECK(gcmapsects_entrypoint_15(&native_map));gcmapsects_entrypoint_10(2);
    add_section(0x1CF9,0x1CFA,0);add_section(0x1CF9,0,1000);
    void *base=func_800D674C(0x1CF9);CHECK(base && func_800D70F8(0x1CF9,1));
    native_map.sections[0].flags|=SEC_ACTIVE;native_map.sections[1].flags|=SEC_ACTIVE;
    func_80800B58_gcmapsects(&native_map);CHECK(func_800D7138(0x1CF9)==3);
    func_80800A08_gcmapsects(&native_map,1);CHECK(func_800D7138(0x1CF9)==3 && func_800D7138(0x1CFA)==1 && native_map.sections[0].textures[0] && native_map.sections[1].textures[0]);
    gcmapsects_entrypoint_14(3);func_808005D0_gcmapsects(&native_map,0,base);CHECK(map_test_instances==2);
    NativeMapSection *s=native_map.sections;s[0].flags|=SEC_COLLIDABLE|SEC_VISIBLE;s[1].flags|=SEC_COLLIDABLE;
    collision_token=malloc(1);CHECK(collision_token);
    f32 a[3]={0},b[3]={1,2,3},out[3];s16 (*vertices)[3]=NULL;
    CHECK(gcmapsects_entrypoint_20(&native_map,a,b,&vertices,123,2) && collisions==1);
    collisions=0;CHECK(gcmapsects_entrypoint_21(&native_map,a,b,out,4) && collisions==1);
    collisions=0;CHECK(gcmapsects_entrypoint_22(&native_map,a,b,out,123)==collision_token && native_map.collision_model==base && collisions==1);
    collisions=0;hit_on=2;CHECK(gcmapsects_entrypoint_25(&native_map,0,a,b,out,123)==collision_token && !native_map.collision_model);
    collisions=0;hit_on=1;CHECK(gcmapsects_entrypoint_25(&native_map,0,a,b,out,0x1F00)==collision_token && !native_map.collision_model && collisions==1);
    collisions=0;hit_on=2;CHECK(gcmapsects_entrypoint_23(&native_map,a,b,4,out,123,5)==collision_token && native_map.collision_model==base && collisions==2);
    collisions=0;hit_on=1;CHECK(gcmapsects_entrypoint_26(&native_map,a,4,out,123)==collision_token && native_map.collision_model==base);
    collisions=0;hit_on=99;CHECK(!gcmapsects_entrypoint_22(&native_map,a,b,out,123) && !native_map.collision_model && collisions==3);
    gcmapsects_entrypoint_18(&native_map,0);CHECK(draws==1 && draw_side==1);
    gcmapsects_entrypoint_19(&native_map,0);CHECK(draws==2 && draw_side==2);
    CHECK(gcmapsects_entrypoint_27(0) && !gcmapsects_entrypoint_27(1));free(collision_token);
    gcmapsects_entrypoint_16(&native_map);CHECK(!map_test_instances && func_800D7138(0x1CF9)==1 && func_800D6B0C(0x1CF9)==base);
    func_800D70F8(0x1CF9,0);func_800D6CEC(0x1CF9);CHECK(!func_800D73CC(0x1CF9));
    gcmapsects_entrypoint_10(1);add_section(0x1CFB,0,0);s=native_map.sections;s->flags|=SEC_ACTIVE|SEC_VISIBLE|SEC_COLLIDABLE;
    map_test_async_ready=0;func_80800B58_gcmapsects(&native_map);CHECK(!(s->flags&(SEC_VISIBLE|SEC_COLLIDABLE)) && !s->pinned[0]);
    map_test_async_ready=1;func_80800B58_gcmapsects(&native_map);CHECK(s->pinned[0]);gcmapsects_entrypoint_16(&native_map);
    level=0x1A7;CHECK(!gcmapsects_entrypoint_15(&native_map) && native_map.sections_failed);
    gcmapsects_entrypoint_16(&native_map);CHECK(!map_test_instances);native_assets_close();
}
static void test_runtime(const char *archive) {
    native_map=(NativeMap){0};level=0xA4;map_test_flags=0x80;map_test_mode=0;
    CHECK(native_assets_open(archive));func_800C6A68();CHECK(func_800BF8BC(level) && func_800BF444());
    CHECK(!func_800BF444() && native_map.layers[0].model);
    CHECK(func_800BF704()==&native_map && func_800BEC10()==native_map.vectors && func_800BEC1C()==native_map.zone_state);
    for(int i=0;i<2;++i) {
        CHECK(func_800BEB28(i)==native_map.layers[i].model && func_800BEB64(i)==native_map.layers[i].vertices[0]);
        CHECK(func_800BEC28(i)==native_map.layers[i].zones && func_800BEBD4(i)==func_800B27A0(native_map.layers[i].model));
        CHECK(!func_800BEA88(i) && func_800BEB98(i)==1);
    }
    CHECK(!func_800BEB28(-1) && !func_800BEB64(2) && !func_800BEC28(2));
    CHECK(func_800BF3E4() && !func_800BFAA4() && !func_800BF8B0() && !func_800BF6B8());
    f32 a[3]={0},b[3]={0,10,0},out[3],height;
    CHECK(!func_800BEAAC(a,&height));func_800BEAF4();func_800BF710();func_800BE9B0();
    CHECK(func_800BFA1C(a,NULL));a[0]=native_map.minimum[0]-100;CHECK(func_800BFA1C(a,NULL));
    a[0]-=1;CHECK(!func_800BFA1C(a,NULL));a[0]=0;
    collision_token=malloc(1);CHECK(collision_token);
    for(int kind=0;kind<3;++kind)for(int hit=0;hit<4;++hit) {
        hit_on=hit==3 ? 99 : hit;collisions=base_queries=0;
        void *result=kind==0 ? func_800C6A7C(a,b,out,123) : kind==1 ? func_800C6B78(a,b,4,out,123,5) : func_800C6C94(a,4,out,123);
        CHECK(collisions==2 && base_queries==2);
        void *owner=hit==3 ? NULL : native_map.layers[hit==1 ? 0 : 1].model;
        CHECK(result==(hit==3 ? NULL : collision_token) && func_800C69FC()==owner && func_800BEB4C()==owner);
    }
    hit_on=1;collisions=base_queries=0;CHECK(func_800BEF00(a,b,out,0x1F00)==collision_token && base_queries==1 && func_800BEB4C()==native_map.layers[1].model);
    func_800BF4A4(1,0);hit_on=1;collisions=0;s16 (*triangles)[3]=NULL;
    CHECK(func_800BED70(a,b,&triangles,123,2));collisions=0;CHECK(func_800BEE40(a,b,out,4));
    hit_on=0;random_calls=0;CHECK(func_800BEA64(a)==42 && func_800BED50(a)==42 && !random_calls);
    hit_on=99;collisions=random_calls=0;CHECK(func_800BE600(a,123)==0 && collisions==26 && random_calls==100);
    hit_on=0;a[1]=0;b[1]=10;CHECK(func_800BF340(a,b,out,123,2)==collision_token && b[1]==40);
    gcmapsects_entrypoint_10(1);add_section(0x1CF9,0,0);native_map.sections[0].flags|=SEC_COLLIDABLE|SEC_ACTIVE;
    func_80800A08_gcmapsects(&native_map,1);CHECK(func_800BFAA4()==1 && func_800BF8B0()==1 && func_800BF6B8()==1);
    native_map.section_flags[S_PLAYER_TESTED]=1;native_map.selected_section=-1;CHECK(func_800BF6B8()==2);
    a[1]=0;CHECK(func_800BEAAC(a,&height) && height==5000);
    func_800BEAF4();CHECK(!native_map.section_flags[S_READY]);
    func_800BF4A4(0,0);collisions=0;hit_on=1;CHECK(func_800BED70(a,b,&triangles,123,2));
    collisions=0;CHECK(func_800BEE40(a,b,out,4));
    func_800BF4A4(0,1);func_800BF4A4(1,1);collisions=base_queries=section_queries=0;
    CHECK(func_800BEF00(a,b,out,123)==collision_token && base_queries==1 && section_queries==2);
    CHECK(func_800BEB4C()==native_map.layers[0].model);
    native_map.section_flags[S_MODE]=1;native_map.section_flags[S_FORCE_ALL]=1;func_800BF710();CHECK(native_map.section_flags[S_READY]);
    func_800BE9B0();gcmapsects_entrypoint_16(&native_map);
    native_map.config.clone[0]=native_map.config.clone[1]=1;func_800BF68C();
    CHECK(func_800BEA88(0) && func_800BEB98(0)==2 && native_map.lighting_type==-1);
    CHECK(func_800BF8E4()==2);vpl_mode=0;native_map.lighting_type=-1;CHECK(func_800BF8E4()==1);
    vpl_mode=1;native_map.lighting_type=-1;CHECK(func_800BF8E4()==2);
    func_800BF7E0();CHECK(light_updates==2 && module_updates==2);
    func_800BF48C(12,34,56);func_800BF744(59,1234);func_800BF744(60,999);func_800BF744(-1,999);
    CHECK(native_map.switches[0]==59 && native_map.switches[59]==1234);
    draws=switch_calls=module_draws=0;NativeVertexList *first=native_map.layers[0].vertices[0],*second=native_map.layers[0].vertices[1];
    func_800BE9E4(0);CHECK(draws==1 && module_draws==1 && switch_calls==59 && native_map.layers[0].index==1);
    CHECK(draw_vertices==first && map_test_glid6_vertices==first && map_test_glid5_vertices==second);
    CHECK(draw_vectors==native_map.vectors && draw_zones==native_map.zone_state && draw_color[0]==12 && draw_color[1]==34 && draw_color[2]==56 && draw_color[3]==255);
    swap_vertices=0;func_800BE9E4(0);CHECK(native_map.layers[0].index==1 && draw_vertices==second);
    swap_vertices=1;func_800BE9E4(0);CHECK(native_map.layers[0].index==0 && map_test_glid5_vertices==first);
    func_800BEA24(0);CHECK(draw_side==2 && native_map.layers[1].index==1);
    int hidden=map_test_hidden,before=draws;func_800BF4DC(0,0);func_800BF4DC(0,0);func_800BE9E4(0);
    CHECK(map_test_hidden==hidden+1 && draws==before && !map_test_instance_enabled);func_800BF4DC(0,1);CHECK(map_test_hidden==hidden+2 && map_test_instance_enabled==1);
    func_800BF544(0,4,7);func_800BF99C(0,4,7);CHECK(instance_commands==2 && module_commands==1);
    void *model=native_map.layers[0].model;func_800BF58C();CHECK(native_map.layers[0].model==model && func_800BEB64(0)==first);
    func_800BEB58(collision_token);CHECK(func_800BEB4C()==collision_token);
    free(collision_token);func_800BF420();func_800BF420();func_800C6A68();
    CHECK(!native_map.layers[0].model && !map_test_instances && !map_test_lights && !map_test_modules);
    for(int i=0;i<8;++i)CHECK(func_800C6A08(NULL,NULL,NULL));
    CHECK(!func_800BF444() && !native_map.layers[0].model && !native_map.vectors);
    func_800C6A68();level=-1;CHECK(!func_800BF444());level=0xA8;CHECK(!func_800BF444());
    CHECK(!func_800D73CC(0x1CF9) && !func_800D73CC(0x1CFA));native_assets_close();
}
static void test_lagoons(const char *archive) {
    CHECK(native_assets_open(archive));int sections=0;
    for(level=0x1A7;level<=0x1A9;++level) {
        func_800C6A68();CHECK(func_800BF444());CHECK(native_map.section_count==(level==0x1A7 ? 5 : 4));
        CHECK(native_map.section_update && native_map.section_flags[S_FORCE_ALL]);
        for(int i=0;i<native_map.section_count;++i) {
            NativeMapSection *s=native_map.sections+i;++sections;
            for(int side=0;side<2;++side)if(s->assets[side])CHECK(s->pinned[side] && s->textures[side] && func_800D7138(s->assets[side])>0);
            for(int k=0;k<3;++k)map_test_camera[k]=map_test_player[k]=s->center[k];
            map_test_player_active=1;func_800BF710();CHECK(!native_map.sections_failed);
        }
        map_test_camera[1]=3000;map_test_rotation[0]=-30;native_map.section_flags[S_SECONDARY]=1;
        native_map.section_update(&native_map);CHECK(!native_map.section_flags[S_SECONDARY]);
        map_test_rotation[0]=0;map_test_frustum=0;native_map.section_flags[S_SECONDARY]=1;
        native_map.section_update(&native_map);CHECK(!native_map.section_flags[S_SECONDARY]);
        if(level==0x1A7) {
            for(int i=0;i<5;++i)native_map.sections[i].flags=SEC_VISIBLE|SEC_COLLIDABLE|SEC_ACTIVE;
            map_test_camera[0]=0;map_test_camera[1]=4500;map_test_camera[2]=0;map_test_rotation[1]=180;
            native_map.section_update(&native_map);
            for(int i=0;i<5;++i)if(i!=3)CHECK(!(native_map.sections[i].flags&(SEC_VISIBLE|SEC_COLLIDABLE)));
            CHECK(native_map.sections[3].flags==(SEC_VISIBLE|SEC_COLLIDABLE|SEC_ACTIVE));
            for(int i=0;i<5;++i)CHECK(native_map.sections[i].flags&SEC_ACTIVE);
            native_map.sections[0].flags=SEC_COLLIDABLE;native_map.section_update(&native_map);
            CHECK(native_map.sections[1].flags&SEC_COLLIDABLE);
        }
        map_test_frustum=1;func_800BF420();func_800C6A68();CHECK(!map_test_instances && !native_map.sections);
        func_800D5E74();func_800D5E74();
    }
    native_assets_close();CHECK(sections==13);puts("All 13 original lagoon sections loaded, updated and released.");
}
int main(int argc,char **argv) {
    CHECK(argc==2 || argc==3);test_geometry();
    if(argc==3)test_lagoons(argv[1]);else {test_resources(argv[1]);test_runtime(argv[1]);}
    puts("Native map runtime/sections: loading, collision routing, draw state, transitions and cleanup passed.");return 0;
}
