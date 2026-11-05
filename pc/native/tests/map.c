#include "native_map.h"
#include "native_texture.h"
#include "native_vector_table.h"
#include "native_zones.h"
#include "native_lights.h"
#include "native_assets.h"
#include "core2/1EAF950.h"
#include "map_dependencies.h"
#include "memory.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define CHECK(x) do {if(!(x)){fprintf(stderr,"%s:%d: %s\n",__FILE__,__LINE__,#x);exit(1);}}while(0)
static s32 level;
s32 func_800EA05C(void) {return level;}
s32 func_8001211C(void) {return 100;}

static void test_tables(void) {
    int count=0;
    for(const NativeMapConfig *p=native_map_configs;p->id;++p) {
        CHECK(gcmapDll_entrypoint_0(p->id) && func_80800000_gcmapDll(p->id)==p);++count;
    }
    CHECK(count==228 && !gcmapDll_entrypoint_0(0) && !func_80800000_gcmapDll(-1));
    level=0xB8;CHECK(gcmapDll_entrypoint_5()==1500);level=0x181;CHECK(gcmapDll_entrypoint_5()==2600);
    level=-1;CHECK(gcmapDll_entrypoint_5()==1300);
    CHECK(func_80800000_gcmapDll(0xA4)->assets[0]==0x1CF9 && func_80800000_gcmapDll(0xA4)->assets[1]==0x1CFA);
    for(int i=0;i<2;++i) {
        map_test_state=i;level=0x160;gcmapDll_entrypoint_2(&native_map);
        CHECK(native_map.switches[0]==4 && native_map.switches[1]==!i && native_map.switches[2]==i && native_map.switches[3]==!i && native_map.switches[4]==i);
    }
    level=0x18D;gcmapDll_entrypoint_2(&native_map);CHECK(native_map.switches[1]==0 && native_map.switches[2]==0 && native_map.switches[3]==1 && native_map.switches[4]==0);
    level=0xA1;gcmapDll_entrypoint_2(&native_map);CHECK(native_map.switches[1]==0 && native_map.switches[2]==1);
    level=0xA7;gcmapDll_entrypoint_2(&native_map);CHECK(native_map.switches[1]==1 && native_map.switches[2]==0);
    native_map=(NativeMap){0};
}
static void test_vectors(void) {
    NativeVectorTable *table=func_800DBFF8();f32 a[3],value[3]={3,4,0};s32 b[3];
    CHECK(table && sizeof(*table)==280 && !table->header);
    for(int i=0;i<23;++i){func_800DBEFC(table,i,a);CHECK(!a[0] && !a[1] && !a[2]);}
    func_800DC028(table,22,value);func_800DBF38(table,22,b);CHECK(b[0]==3 && b[1]==4 && b[2]==0);
    func_800DBF74(table,0,22,a);CHECK(fabsf(a[0]-0.6f)<0.00001f && fabsf(a[1]-0.8f)<0.00001f && a[2]==0);
    CHECK(func_800DC060(table)==table);func_800DBEB0(table);func_800DBEFC(table,22,a);CHECK(!a[0] && !a[1]);
    func_800DC028(table,-1,value);func_800DC028(table,23,value);func_800DBFD8(table);
}
static void test_zones(u8 *zones,u8 *state) {
    f32 point[3]={5,5,5},origin[3]={0},outside[3]={30,0,0};u8 ids[3]={255,255,255};
    CHECK(*zones==2 && *state==2 && !glzone_entrypoint_4(state,1));
    CHECK(dbzone_entrypoint_3(zones,point)==0 && dbzone_entrypoint_4(zones,point,ids)==2 && ids[0]==0 && ids[1]==1 && ids[2]==255);
    CHECK(dbzone_entrypoint_2(zones,point,1) && !dbzone_entrypoint_2(zones,point,2));
    CHECK(glzone_entrypoint_5(zones,point,2)==2 && glzone_entrypoint_5(zones,point,0)==1);
    CHECK(!glzone_entrypoint_5(zones,outside,2));
    dbzone_entrypoint_1(zones,point,1,origin);CHECK(dbzone_entrypoint_0(zones,ids,2));
    glzone_entrypoint_3((s8 *)state,2);CHECK(glzone_entrypoint_4(state,2)==1 && glzone_entrypoint_6(state,ids,2));
    glzone_entrypoint_2(state);CHECK(!glzone_entrypoint_6(state,ids,2));
    dbzone_entrypoint_1(zones,outside,1,origin);CHECK(!dbzone_entrypoint_0(zones,ids,2));
    dbzone_entrypoint_1(zones,point,0,origin);CHECK(!dbzone_entrypoint_0(zones,ids,2));
    point[0]=NAN;CHECK(dbzone_entrypoint_3(zones,point)==-1 && !dbzone_entrypoint_4(zones,point,ids));
}
static void test_loading(const char *path) {
    CHECK(native_assets_open(path));func_800C90AC();level=0xA4;map_test_flags=0x80;
    CHECK(gcmapDll_entrypoint_6(&native_map,level) && native_map.layers[0].texture && native_map.layers[1].texture);
    NativeModelTextures *first_texture=native_map.layers[0].texture,*second_texture=native_map.layers[1].texture;
    CHECK(first_texture->size==48 && first_texture->count==1 && !first_texture->flags);
    for(int i=0;i<32;++i)CHECK(((u8 *)(first_texture->entries+1))[i]==0x51 && ((u8 *)(second_texture->entries+1))[i]==0xA2);
    NativeModelTextures *source=func_800B27FC(func_800D674C(0x1CF9));u32 original=source->entries[0].offset;
    source->entries[0].offset=0x7FFFFFFF;CHECK(!gcmapDll_entrypoint_6(&native_map,level));source->entries[0].offset=original;
    CHECK(native_map.layers[0].texture==first_texture && native_map.layers[1].texture==second_texture);
    source->flags=source->count=0;source->size=0;
    CHECK(gcmapDll_entrypoint_6(&native_map,level) && !native_map.layers[0].texture && native_map.layers[1].texture);
    source->flags=0x100;source->count=1;source->size=32;
    CHECK(gcmapDll_entrypoint_6(&native_map,level));first_texture=native_map.layers[0].texture;second_texture=native_map.layers[1].texture;
    CHECK(!gcmapDll_entrypoint_6(&native_map,0xA8) && native_map.layers[0].texture && native_map.layers[1].texture);
    CHECK(native_map.layers[0].texture==first_texture && native_map.layers[1].texture==second_texture);
    CHECK(gcmapDll_entrypoint_3(&native_map) && !native_map.section_count && !native_map.section_update);
    CHECK(!gcmapDll_entrypoint_3(&native_map));
    CHECK(native_map.config.id==level && native_map.layers[0].model && native_map.layers[1].model);
    CHECK(func_800D7138(0x1CF9)==1 && func_800D7138(0x1CFA)==1);
    CHECK(native_map.minimum[0]==-1000 && native_map.maximum[1]==5000 && native_map.combined_minimum[0]==-4000 && native_map.combined_maximum[2]==10000);
    CHECK(native_map.zone_state && native_map.vectors && native_map.color[2]==255 && native_map.layers[0].collides);
    s32 lower[3],upper[3];func_800BECE0(lower,upper);CHECK(lower[0]==-1000 && upper[2]==6000 && func_800BECCC()==-2000);
    func_800BED18(lower,upper);CHECK(lower[0]==-4000 && upper[1]==9000);
    native_map.config.padding[0]=-1;native_map.config.padding[5]=2;
    func_800BEC4C(lower,upper,1000);CHECK(lower[0]==-3 && lower[1]==-3 && lower[2]==-4 && upper[0]==4 && upper[2]==8);
    test_zones(native_map.layers[0].zones,native_map.zone_state);
    native_map.config.clone[0]=native_map.config.clone[1]=1;gcmapDll_entrypoint_1(&native_map);
    CHECK(map_test_lights==2 && map_test_modules==2 && map_test_instances==2);
    CHECK(native_map.layers[0].vertices[1]!=native_map.layers[0].vertices[0]);
    gcmapDll_entrypoint_4(&native_map);gcmapDll_entrypoint_4(&native_map);
    CHECK(!native_map.vectors && !native_map.layers[0].model && !map_test_lights && !map_test_modules && !map_test_instances);
    CHECK(!func_800D73CC(0x1CF9) && !func_800D73CC(0x1CFA));
    func_800D5E74();func_800D5E74();
    level=0xA8;CHECK(!gcmapDll_entrypoint_3(&native_map) && !native_map.layers[0].model && !func_800D73CC(0x1CFB));
    level=-1;CHECK(!gcmapDll_entrypoint_3(&native_map) && !gcmapDll_entrypoint_6(&native_map,level));
    level=0xA1;map_test_mode=3;CHECK(gcmapDll_entrypoint_3(&native_map));
    native_lighting.primary_color[0]=128;native_lighting.primary_color[1]=64;native_lighting.primary_color[2]=256;
    gcmapDll_entrypoint_1(&native_map);CHECK(!native_map.layers[0].light && !native_map.layers[0].module && !native_map.layers[0].instances);
    CHECK(native_map.layers[0].vertices[0]->vertices[0].v.cn[0]==100 && native_map.layers[0].vertices[0]->vertices[0].v.cn[1]==25);
    gcmapDll_entrypoint_4(&native_map);
    level=0x159;CHECK(gcmapDll_entrypoint_3(&native_map) && native_map.minimum[0]==-100 && native_map.maximum[2]==100);
    gcmapDll_entrypoint_4(&native_map);func_800C90D0();native_assets_close();
    for(int i=0;i<3;++i) {
        native_map.config.id=0x1A7+i;func_808005A8_gcmapDll(&native_map);
        CHECK(native_map.minimum[1]==(i==0 ? -6000 : i==1 ? -8000 : -12000));
    }
}
int main(int argc,char **argv) {
    CHECK(argc==2);test_tables();test_vectors();test_loading(argv[1]);
    puts("Native map metadata, model loading, bounds, zones, lighting integration and cleanup passed.");return 0;
}
