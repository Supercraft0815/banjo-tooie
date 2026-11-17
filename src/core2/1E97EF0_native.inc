#include "native_collision_geometry.h"
#include "native_map_runtime.h"
#include "native_map_sections.h"
#include "native_vector_table.h"
#include "memory.h"
void _glid_entrypoint_5(void *,void *),_glid_entrypoint_6(void *,void *);
void _vpmodule_entrypoint_2(void *,void *),_vpmodule_entrypoint_3(void *,void *,void *);
s32 _vpmodule_entrypoint_4(s32 arg0, u8 *arg1, s32 arg2, s32 arg3);
void _idworldmake_entrypoint_5(void *,s32),_idworldmake_entrypoint_6(void *,s32,s32),_idworldmake_entrypoint_7(void *,s32,s32);
void _rtlight_entrypoint_2(u8 *arg0, void *arg1, s32 arg2, s32 arg3);
void *_dbvpl_entrypoint_0(void *,s32);
s32 func_800EA340(void);
void *func_800DE448(f32 *,f32 *,f32,f32 *,void *);
f32 func_800DF428(f32),func_800DC178(f32,f32);
void func_800DF440(s32),func_800DF4B0(s32),func_800DF5D8(u32,u32,u32,s32);
void func_800DF738(void *),func_800DF744(s32,s32),func_800DF7DC(void *),func_800DF7E8(u8),func_800DF818(void *),func_800DF830(s32),func_800DF83C(void *);
void func_800EE7F8(f32 *,f32 *),func_800EFB24(void *,void *,void *),func_800EF368(f32 *,f32),func_800EF04C(f32 *,f32 *),func_800EF3DC(f32 *,f32 *);

static NativeMapLayer *map_layer(s32 i) {return i>=0 && i<2 ? native_map.layers+i : NULL;}
f32 func_800BE600(f32 point[3],s32 flags) {
    f32 normal[3],start[3],end[3];
    for(int i=0;i<3;++i)start[i]=end[i]=point[i];
    start[1]+=200;end[1]-=2000;
    if(func_800BEF00(start,end,normal,flags))return end[1];
    for(s32 lower=1000,upper=150;lower!=51000;lower+=2000,upper+=300) {
        for(int i=0;i<3;++i)start[i]=end[i]=point[i];
        start[0]+=func_800DC178(-1,1);start[1]+=upper;start[2]+=func_800DC178(-1,1);
        end[0]+=func_800DC178(-1,1);end[1]-=lower;end[2]+=func_800DC178(-1,1);
        if(func_800BEF00(start,end,normal,flags))return end[1];
    }
    return 0;
}
void func_800BE7F8(s32 mode,s32 index) {
    NativeMapLayer *s=map_layer(index);(void)mode;
    if(!s || !s->model || !s->enabled)return;
    func_800BF774();func_800DF738(native_map.vectors);
    if(!index)func_800DF83C(native_map.zone_state);
    func_800DF830(index+1);if(s->animation)func_800DF7E8(s->animation);
    func_800DF5D8(native_map.color[0],native_map.color[1],native_map.color[2],255);
    func_800DF7DC(s->texture);func_800DF818(s->vertices[s->index]);func_800DF428(29999);
    func_800DF440(0);func_800DF4B0(1);func_800DE448(NULL,NULL,1,NULL,s->model);
    if(s->module)_vpmodule_entrypoint_3(s->module,s->vpl,s->vertices[s->index]);
    if(s->vertices[1] && func_800EA340()) {
        if(s->instances)_glid_entrypoint_6(s->instances,s->vertices[s->index]);
        s->index^=1;
        if(s->instances)_glid_entrypoint_5(s->instances,s->vertices[s->index]);
    }
}
void func_800BE9B0(void) {if(native_map.section_count)gcmapsects_entrypoint_17(&native_map);}
void func_800BE9E4(BtIntPtr mode) {func_800BE7F8(mode,0);if(native_map.section_count)gcmapsects_entrypoint_18(&native_map,mode);}
void func_800BEA24(BtIntPtr mode) {func_800BE7F8(mode,1);if(native_map.section_count)gcmapsects_entrypoint_19(&native_map,mode);}
f32 func_800BEA64(f32 *point) {return func_800BE600(point,0x20020);}
void *func_800BEA88(s32 i) {NativeMapLayer *s=map_layer(i);return s ? s->instances : NULL;}
s32 func_800BEAAC(f32 *point,f32 *height) {return native_map.section_count ? gcmapsects_entrypoint_6(&native_map,point,height) : 0;}
void func_800BEAF4(void) {if(native_map.section_count)gcmapsects_entrypoint_8(&native_map);}
void *func_800BEB28(s32 i) {NativeMapLayer *s=map_layer(i);return s ? s->model : NULL;}
void *func_800BEB4C(void) {return native_map.collision_model;}
void func_800BEB58(void *model) {native_map.collision_model=model;}
NativeVertexList *func_800BEB64(s32 i) {NativeMapLayer *s=map_layer(i);return s ? s->vertices[s->index] : NULL;}
s32 func_800BEB98(s32 i) {NativeMapLayer *s=map_layer(i);return s && s->vertices[1] ? 2 : 1;}
u8 *func_800BEBD4(s32 i) {void *model=func_800BEB28(i);return model ? func_800B27A0(model) : NULL;}
void *func_800BEC10(void) {return native_map.vectors;}
void *func_800BEC1C(void) {return native_map.zone_state;}
void *func_800BEC28(s32 i) {NativeMapLayer *s=map_layer(i);return s ? s->zones : NULL;}
#include "1E97EF0_bounds.inc"
f32 func_800BED50(f32 *point) {return func_800BE600(point,0x1F00);}
s32 func_800BED70(f32 *a,f32 *b,s16 (**out)[3],s32 flags,f32 scale) {
    NativeMapLayer *s=native_map.layers;f32 origin[3]={0};s32 hit;
    if(s->collides && (hit=func_800AD2C8(s->collision,s->vertices[s->index],a,b,origin,out,flags,scale)))return hit;
    return native_map.section_count ? gcmapsects_entrypoint_20(&native_map,a,b,out,flags,scale) : 0;
}
s32 func_800BEE40(f32 *a,f32 *b,f32 *out,f32 radius) {
    NativeMapLayer *s=native_map.layers;f32 origin[3]={0};
    if(s->collides && func_800AD894(s->collision,s->vertices[s->index],a,b,out,origin,radius))return 1;
    return native_map.section_count ? gcmapsects_entrypoint_21(&native_map,a,b,out,radius) : 0;
}
void *func_800BEF00(f32 *a,f32 *b,f32 *out,u32 flags) {
    NativeMapLayer *primary=native_map.layers,*secondary=primary+1;void *result=NULL,*hit;
    native_map.collision_model=NULL;
    if(secondary->collides) {
        if((flags&0x1F00)!=0x1F00) {
            if(native_map.section_count)result=gcmapsects_entrypoint_22(&native_map,a,b,out,flags);
            if(!result && primary->collides)result=func_800AB0BC(primary->collision,primary->vertices[primary->index],a,b,out,flags);
        }
        hit=func_800AB0BC(secondary->collision,secondary->vertices[secondary->index],a,b,out,flags);
        if(hit){native_map.collision_model=secondary->model;return hit;}
        if(native_map.section_count) {
            hit=gcmapsects_entrypoint_22(&native_map,a,b,out,flags);if(hit)return hit;
        }
        if(result)native_map.collision_model=primary->model;
        return result;
    }
    if(native_map.section_count)result=gcmapsects_entrypoint_22(&native_map,a,b,out,flags);
    if(!result && primary->collides)result=func_800AB0BC(primary->collision,primary->vertices[primary->index],a,b,out,flags);
    if(result)native_map.collision_model=primary->model;
    return result;
}
void *func_800BF0E0(f32 *a,f32 *b,f32 radius,f32 *out,s32 flags,u32 mode) {
    NativeMapLayer *primary=native_map.layers,*secondary=primary+1;void *result=NULL,*hit;
    native_map.collision_model=NULL;
    if(native_map.section_count)result=gcmapsects_entrypoint_23(&native_map,a,b,radius,out,flags,mode);
    if(!result && primary->collides)result=func_800AC638(primary->collision,primary->vertices[primary->index],a,b,radius,out,flags,mode);
    if(result)native_map.collision_model=primary->model;
    if(!secondary->collides)return result;
    hit=func_800AC638(secondary->collision,secondary->vertices[secondary->index],a,b,radius,out,flags,mode);
    if(hit){native_map.collision_model=secondary->model;return hit;}return result;
}
void *func_800BF228(f32 *point,f32 radius,f32 *out,u32 flags) {
    NativeMapLayer *primary=native_map.layers,*secondary=primary+1;void *result=NULL,*hit;
    native_map.collision_model=NULL;
    if(native_map.section_count)result=gcmapsects_entrypoint_26(&native_map,point,radius,out,flags);
    if(!result && primary->collides)result=func_800AC978(primary->collision,primary->vertices[primary->index],point,radius,out,flags);
    if(result)native_map.collision_model=primary->model;
    if(!secondary->collides)return result;
    hit=func_800AC978(secondary->collision,secondary->vertices[secondary->index],point,radius,out,flags);
    if(hit){native_map.collision_model=secondary->model;return hit;}return result;
}
void *func_800BF340(f32 *a,f32 *b,f32 *out,s32 flags,f32 extend) {
    f32 delta[3],end[3];func_800EE7F8(end,b);func_800EFB24(delta,end,a);func_800EF368(delta,extend);func_800EF04C(end,delta);
    void *hit=func_800BEF00(a,end,out,flags);if(!hit)return NULL;
    func_800EF3DC(end,delta);func_800EE7F8(b,end);return hit;
}
int func_800BF3E4(void) {return (native_map.config.assets[0] || native_map.section_count) && native_map.config.assets[1];}
void func_800BF420(void) {gcmapDll_entrypoint_4(&native_map);}
s32 func_800BF444(void) {
    if(!gcmapDll_entrypoint_3(&native_map))return 0;
    if(func_800C6A28(func_800BEF00,func_800BF0E0,func_800BF228,func_800BEB4C))return 1;
    gcmapDll_entrypoint_4(&native_map);return 0;
}
void func_800BF48C(s32 r,s32 g,s32 b) {native_map.color[0]=r;native_map.color[1]=g;native_map.color[2]=b;}
void func_800BF4A4(s32 i,s32 enabled) {NativeMapLayer *s=map_layer(i);if(s && s->collision)s->collides=enabled;}
void func_800BF4DC(s32 i,s32 enabled) {
    NativeMapLayer *s=map_layer(i);if(!s)return;
    if(enabled!=s->enabled && s->instances)_idworldmake_entrypoint_5(s->instances,enabled);s->enabled=enabled;
}
void func_800BF544(s32 i,s32 a,s32 b) {NativeMapLayer *s=map_layer(i);if(s && s->instances)_idworldmake_entrypoint_6(s->instances,a,b);}
void func_800BF58C(void) {
    /* Native heap allocations never move, including nested instance/module allocations. */
}
void func_800BF68C(void) {gcmapDll_entrypoint_1(&native_map);native_map.lighting_type=-1;}
s32 func_800BF6B8(void) {return native_map.section_count ? (gcmapsects_entrypoint_24(&native_map) ? 2 : 1) : 0;}
void *func_800BF704(void) {return &native_map;}
void func_800BF710(void) {if(native_map.section_count)gcmapsects_entrypoint_9(&native_map);}
void func_800BF744(s32 i,s32 value) {
    if(i<=0 || i>=60)return;native_map.switches[i]=value;if(native_map.switches[0]<i)native_map.switches[0]=i;
}
void func_800BF774(void) {for(int i=1;i<=native_map.switches[0];++i)func_800DF744(i,native_map.switches[i]);}
void func_800BF7E0(void) {
    for(int i=0;i<2;++i)if(native_map.layers[i].light)_rtlight_entrypoint_2(native_map.layers[i].light,func_800BEB64(i),func_800BEBD4(i),func_800BEB98(i));
    for(int i=0;i<2;++i)if(native_map.layers[i].module)_vpmodule_entrypoint_2(native_map.layers[i].module,native_map.layers[i].vpl);
}
u32 func_800BF8B0(void) {return native_map.section_count;}
s32 func_800BF8BC(s32 id) {return gcmapDll_entrypoint_6(&native_map,id);}
s8 func_800BF8E4(void) {
    if(native_map.lighting_type==-1) {
        native_map.lighting_type=0;
        for(int i=0;i<2;++i) {
            NativeMapLayer *s=native_map.layers+i;
            if(s->light)native_map.lighting_type=1;
            if(s->module && _dbvpl_entrypoint_0(s->vpl,0))native_map.lighting_type=2;
        }
    }
    return native_map.lighting_type;
}
void func_800BF99C(s32 i,s32 a,s32 b) {
    NativeMapLayer *s=map_layer(i);if(!s)return;
    if(s->module)_vpmodule_entrypoint_4(s->module,s->vpl,a,b);
    if(s->instances)_idworldmake_entrypoint_7(s->instances,a,b);
}
s32 func_800BFA1C(f32 *point,s32 *unused) {
    (void)unused;
    for(int i=0;i<3;++i)if(point[i]<native_map.minimum[i]-100.0f || native_map.maximum[i]+100.0f<point[i])return 0;
    return 1;
}
u8 func_800BFAA4(void) {return native_map.section_count;}
