#include "native_collision_geometry.h"
#include "native_map_sections.h"
#include "native_assets.h"
#include "native_texture.h"
#include "core2/1EAF950.h"
#include "memory.h"

s32 func_800EA05C(void),func_800DB9B0(void),func_80090128(void);
void func_8008FE68(f32 *),func_800E3980(f32 *);
f32 func_800EEAD4(f32 *,f32 *);
int func_800EFED0(f32 *,f32 *,f32 *);
s32 func_800EFFB4(f32 *,f32,f32 *),func_800E3D0C(f32 *,f32 *),func_800E3E8C(f32 *,f32);
void _glidmake_entrypoint_4(void *),_idworldmake_entrypoint_2(void *);
void *_glidmake_entrypoint_5(s32 arg0, f32 *arg1);
void _idworldmake_entrypoint_0(void *,s32),_glid_entrypoint_5(void *,void *);
s32 func_800E488C(s32),func_800E4AF0(s32);
void func_800E4BB8(s32),func_800F4CC0(BtIntPtr),func_800F4CEC(BtIntPtr,u32);
BtUIntPtr func_800F54E4(void);
void func_800BF4DC(s32,s32),func_800BFF28(void),func_800BFF4C(void),func_800BF774(void);
void *func_800DE448(f32 *,f32 *,f32,f32 *,void *);
f32 func_800DF428(f32);
void func_800DF440(s32),func_800DF4B0(s32),func_800DF7DC(void *),func_800DF7E8(u8),func_800DF818(void *),func_800DF830(s32);

static NativeMapSection *map_section(NativeMap *map,s32 index) {
    return index>=0 && index<map->section_count ? map->sections+index : NULL;
}
static int section_pin(NativeMap *map,NativeMapSection *s,int side) {
    u16 id=s->assets[side];
    if(!id || s->pinned[side])return 1;
    if(!native_asset_can_pin(id) || !func_800D674C(id) || !func_800D70F8(id,1)) {
        map->sections_failed=1;return 0;
    }
    s->pinned[side]=1;if(!side)s->flags|=SEC_PINNED;return 1;
}
void gcmapsects_entrypoint_0(s16 first,s16 second,const f32 *position,const f32 *lower,const f32 *upper,f32 height) {
    NativeMap *map=&native_map;
    if(map->section_count>=map->section_capacity){map->sections_failed=1;return;}
    NativeMapSection *s=map->sections+map->section_count++;
    *s=(NativeMapSection){0};
    for(int i=0;i<3;++i) {
        s->position[i]=position[i];s->minimum[i]=lower[i]-50;s->maximum[i]=upper[i]+50;
        s->center[i]=(s->minimum[i]+s->maximum[i])*0.5f;
    }
    s->radius=func_800EEAD4(s->center,s->minimum);s->height=height;s->assets[0]=first;s->assets[1]=second;
    for(int i=0;i<4;++i)s->neighbors[i]=s->hidden[i]=255;
    s->flags=SEC_PRIMARY|SEC_SECONDARY;
}
void func_80800250_gcmapsects(NativeMap *map,s32 index) {
    NativeMapSection *s=map_section(map,index);if(!s)return;
    for(int i=0;i<2;++i)if(s->assets[i] && !s->textures[i]) {
        void *model=func_800D674C(s->assets[i]);
        if(!model){map->sections_failed=1;continue;}
        NativeModelTextures *block=func_800B27FC(model);
        s->textures[i]=dbtex_entrypoint_0(block);
        if(block && (block->flags&0x100) && !s->textures[i])map->sections_failed=1;
        func_800D6CEC(s->assets[i]);
    }
}
void func_8080035C_gcmapsects(NativeMap *map,s32 index) {
    NativeMapSection *s=map_section(map,index);if(!s)return;
    for(int i=0;i<2;++i)if(s->textures[i]){_dbtex_entrypoint_1(s->textures[i]);s->textures[i]=NULL;}
}
void func_808003F4_gcmapsects(NativeMap *map,s32 index) {
    NativeMapSection *s=map_section(map,index);if(!s)return;
    s->flags&=~(SEC_ACTIVE|SEC_VISIBLE|SEC_PINNED);
    for(int i=0;i<2;++i) {
        if(s->pinned[i]){func_800D70F8(s->assets[i],0);s->pinned[i]=0;}
        if(s->assets[i] && func_800D73CC(s->assets[i]))func_800D6CEC(s->assets[i]);
    }
    if(s->assets[0] && func_800E4AF0(s->assets[0]))func_800E4BB8(s->assets[0]);
    func_808005D0_gcmapsects(map,index,NULL);
}
void func_808005D0_gcmapsects(NativeMap *map,s32 index,void *model) {
    NativeMapSection *s=map_section(map,index);if(!s)return;
    if(!model) {
        for(int i=0;i<2;++i)if(s->instances[i]) {
            _idworldmake_entrypoint_2(s->instances[i]);_glidmake_entrypoint_4(s->instances[i]);s->instances[i]=NULL;
        }
        return;
    }
    for(int i=0;i<2;++i)if(s->assets[i] && (map->section_flags[S_INSTANCES]&(1<<i)) && !s->instances[i]) {
        void *asset=i ? func_800D674C(s->assets[i]) : model;
        if(asset && func_800B274C(asset))s->instances[i]=_glidmake_entrypoint_5(s->assets[i],s);
        if(s->instances[i])_idworldmake_entrypoint_0(s->instances[i],2);
    }
    for(int i=0;i<2;++i)if(s->instances[i]) {
        void *asset=i ? func_800D674C(s->assets[i]) : model;
        if(asset)_glid_entrypoint_5(s->instances[i],func_800B2840(asset));
    }
}
void gcmapsects_entrypoint_1(s16 index,s32 value) {
    NativeMapSection *s=map_section(&native_map,index);if(s)s->flags=(s->flags&~SEC_PRIMARY)|((value&1)*SEC_PRIMARY);
}
void gcmapsects_entrypoint_2(s16 index,s32 value) {
    NativeMapSection *s=map_section(&native_map,index);if(s)s->flags=(s->flags&~SEC_SECONDARY)|(value&1);
}
void gcmapsects_entrypoint_3(s16 a,s16 b) {
    NativeMapSection *first=map_section(&native_map,a),*second=map_section(&native_map,b);
    if(!first || !second)return;
    for(int i=0;i<4;++i)if(first->neighbors[i]==255){first->neighbors[i]=b;break;}
    for(int i=0;i<4;++i)if(second->neighbors[i]==255){second->neighbors[i]=a;break;}
}
void func_80800A08_gcmapsects(NativeMap *map,s32 all) {
    for(int i=0;i<map->section_count;++i) {
        NativeMapSection *s=map->sections+i;
        if((s->flags&SEC_ACTIVE) || all)for(int side=0;side<2;++side) {
            if(s->assets[side] && !func_800D73CC(s->assets[side]))func_800D5B24();
            section_pin(map,s,side);
        }
        func_80800250_gcmapsects(map,i);
    }
    if(!func_800DB9B0())map->section_flags[S_READY]=1;
}
void func_80800B58_gcmapsects(NativeMap *map) {
    for(int i=0;i<map->section_count;++i) {
        NativeMapSection *s=map->sections+i;
        if((s->flags&SEC_ACTIVE) && s->assets[0] && !s->pinned[0]) {
            if(func_800D73CC(s->assets[0]) || func_800E488C(s->assets[0]))section_pin(map,s,0);
            else s->flags&=~(SEC_VISIBLE|SEC_COLLIDABLE);
        }
    }
}
void func_80800C54_gcmapsects(NativeMap *map) {
    for(int i=0;i<map->section_count;++i){func_808003F4_gcmapsects(map,i);func_8080035C_gcmapsects(map,i);}
}
s32 gcmapsects_entrypoint_4(f32 *point) {
    for(int i=0;i<native_map.section_count;++i)if(func_800EFED0(native_map.sections[i].minimum,native_map.sections[i].maximum,point))return i;
    return -1;
}
u32 gcmapsects_entrypoint_5(s32 index) {
    NativeMapSection *s=map_section(&native_map,index);
    return !s || !!(s->flags&SEC_COLLIDABLE);
}
static void section_visible(NativeMap *map,NativeMapSection *s) {
    s->flags|=SEC_VISIBLE|SEC_ACTIVE;
    if(s->flags&SEC_PRIMARY)map->section_flags[S_PRIMARY]=1;
    if(s->flags&SEC_SECONDARY)map->section_flags[S_SECONDARY]=1;
    for(int i=0;i<4 && s->neighbors[i]!=255;++i) {
        NativeMapSection *neighbor=map_section(map,s->neighbors[i]);
        if(neighbor)neighbor->flags|=SEC_VISIBLE|SEC_ACTIVE;
    }
}
s32 func_80800DC8_gcmapsects(NativeMap *map,s32 index,f32 *point) {
    NativeMapSection *s=map_section(map,index);
    if(s && func_800EFFB4(s->center,s->radius,point) && func_800EFED0(s->minimum,s->maximum,point)) {
        section_visible(map,s);s->flags|=SEC_COLLIDABLE;return index;
    }
    return -1;
}
s32 gcmapsects_entrypoint_6(NativeMap *map,f32 *point,f32 *out) {
    f32 height=-1;NativeMapSection *s=map_section(map,map->selected_section);
    if(s && func_800EFED0(s->minimum,s->maximum,point))height=s->height;
    else for(int i=0;i<map->section_count;++i) {
        s=map->sections+i;
        if(func_800EFFB4(s->center,s->radius,point) && func_800EFED0(s->minimum,s->maximum,point) && s->height!=-1 && (height==-1 || height<s->height))height=s->height;
    }
    if(height==-1 || (height-2000<point[1] && point[1]<height+2000))return 0;
    *out=height;return 1;
}
s32 func_80801174_gcmapsects(NativeMap *map,s32 index) {
    NativeMapSection *s=map_section(map,index);if(!s)return 0;
    if(s->flags&SEC_VISIBLE)return 1;
    if(func_800E3E8C(s->center,s->radius) && func_800E3D0C(s->minimum,s->maximum)){section_visible(map,s);return 1;}
    return 0;
}
s32 func_80801320_gcmapsects(NativeMap *map,s32 index,f32 *point) {
    NativeMapSection *s=map_section(map,index);if(!s)return 0;
    if(s->flags&SEC_COLLIDABLE)return 1;
    if(func_800EFFB4(s->center,s->radius,point)){s->flags|=SEC_ACTIVE|SEC_COLLIDABLE;return 1;}
    return 0;
}
void func_808013C0_gcmapsects(NativeMap *map,s32 index) {
    NativeMapSection *s=map_section(map,index);if(!s || !(s->flags&SEC_COLLIDABLE))return;
    for(int i=0;i<4 && s->hidden[i]!=255;++i) {
        NativeMapSection *hidden=map_section(map,s->hidden[i]);if(hidden)hidden->flags&=~SEC_VISIBLE;
    }
}
s32 gcmapsects_entrypoint_7(f32 *point) {
    NativeMapSection *s=map_section(&native_map,native_map.selected_section);
    if(s && func_800EFED0(s->minimum,s->maximum,point))return native_map.selected_section;
    for(int i=0;i<native_map.section_count;++i) {
        s=native_map.sections+i;if(func_800EFFB4(s->center,s->radius,point) && func_800EFED0(s->minimum,s->maximum,point))return i;
    }
    return -1;
}
void gcmapsects_entrypoint_8(NativeMap *map) {map->section_flags[S_READY]=0;}
void func_80801554_gcmapsects(NativeMap *map) {
    f32 point[3];func_8008FE68(point);if(!func_80090128())return;
    if(!map->section_flags[S_FRUSTUM]) {
        s32 selected=-1;
        for(int i=0;i<map->section_count;++i){s32 hit=func_80800DC8_gcmapsects(map,i,point);if(hit!=-1)selected=hit;}
        map->selected_section=selected;map->section_flags[S_PLAYER_TESTED]=1;
    } else for(int i=0;i<map->section_count;++i)func_80801320_gcmapsects(map,i,point);
}
void func_80801640_gcmapsects(NativeMap *map) {
    f32 point[3];func_800E3980(point);
    if(!map->section_flags[S_FRUSTUM]) {
        for(int i=0;i<map->section_count;++i)func_80800DC8_gcmapsects(map,i,point);
    } else {
        for(int i=0;i<map->section_count;++i){func_80801174_gcmapsects(map,i);func_80801320_gcmapsects(map,i,point);}
        for(int i=0;i<map->section_count;++i)func_808013C0_gcmapsects(map,i);
    }
}
void func_80801724_gcmapsects(NativeMap *map,s32 mode) {
    if(map->section_flags[S_MODE]==2)func_800F4CC0(func_800F54E4());
    map->section_flags[S_MODE]=mode;
    if(map->section_flags[S_MODE]==2)func_800F4CEC(func_800F54E4(),0x77);
}
void gcmapsects_entrypoint_9(NativeMap *map) {
    map->section_flags[S_PRIMARY]=map->section_flags[S_FORCE_PRIMARY];map->section_flags[S_SECONDARY]=map->section_flags[S_FORCE_SECONDARY];
    for(int i=0;i<map->section_count;++i) {
        NativeMapSection *s=map->sections+i;
        u8 previous=(s->flags&SEC_ACTIVE) ? SEC_PREVIOUS : 0;
        s->flags=(s->flags&~(SEC_VISIBLE|SEC_COLLIDABLE|SEC_PREVIOUS|SEC_ACTIVE))|previous|(map->section_flags[S_FORCE_ALL]&1)*SEC_ACTIVE;
    }
    if(map->section_flags[S_MODE]==1 && func_800DB9B0())func_80801724_gcmapsects(map,2);
    else if(map->section_flags[S_MODE]==2 && !func_800DB9B0())func_80801724_gcmapsects(map,1);
    if(map->section_flags[S_MODE]==1){func_80801554_gcmapsects(map);func_80801640_gcmapsects(map);}
    else if(map->section_flags[S_MODE]==2)map->section_flags[S_READY]=0;
    if(map->section_update)map->section_update(map);
    for(int i=0;i<map->section_count;++i)if(!(map->sections[i].flags&SEC_ACTIVE))func_808003F4_gcmapsects(map,i);
    if(!map->section_flags[S_READY])func_80800A08_gcmapsects(map,map->section_flags[S_FORCE_ALL]);
    else func_80800B58_gcmapsects(map);
    for(int i=0;i<map->section_count;++i)if(map->sections[i].flags&SEC_ACTIVE)func_808005D0_gcmapsects(map,i,func_800D6B0C(map->sections[i].assets[0]));
}
void gcmapsects_entrypoint_10(s32 capacity) {
    if(capacity<0 || capacity>255){native_map.sections_failed=1;return;}
    if(native_map.sections)gcmapsects_entrypoint_16(&native_map);
    native_map.section_capacity=capacity;
    if(capacity){native_map.sections=heap_alloc(capacity*sizeof(NativeMapSection));rare_memset(native_map.sections,0,capacity*sizeof(NativeMapSection));}
}
void gcmapsects_entrypoint_11(s32 a,s32 b) {native_map.section_flags[S_FORCE_PRIMARY]=a;native_map.section_flags[S_FORCE_SECONDARY]=b;}
void gcmapsects_entrypoint_12(void (*callback)(NativeMap *)) {native_map.section_update=callback;}
void gcmapsects_entrypoint_13(s32 value) {native_map.section_flags[S_FRUSTUM]=value;}
void gcmapsects_entrypoint_14(s32 value) {native_map.section_flags[S_INSTANCES]=value;}
s32 gcmapsects_entrypoint_15(NativeMap *map) {
    if(map!=&native_map)return 0;
    if(map->sections)gcmapsects_entrypoint_16(map);
    map->sections=NULL;map->section_capacity=map->section_count=map->sections_failed=0;
    rare_memset(map->section_flags,0,sizeof(map->section_flags));
    map->section_flags[S_PRIMARY]=map->section_flags[S_SECONDARY]=map->section_flags[S_PREVIOUS_PRIMARY]=1;
    map->section_flags[S_MODE]=3;map->selected_section=-1;map->section_update=NULL;map->section_distance=0;
    switch(func_800EA05C()) {
        case 0x1A7:gcmapsects_lagoontop_entrypoint_0();map->section_flags[S_FORCE_ALL]=1;break;
        case 0x1A8:gcmapsects_lagoonmid_entrypoint_0();map->section_flags[S_FORCE_ALL]=1;break;
        case 0x1A9:gcmapsects_lagoonbot_entrypoint_0();map->section_flags[S_FORCE_ALL]=1;break;
    }
    if(map->section_count)func_80801724_gcmapsects(map,1);
    for(int i=0;i<map->section_count;++i) {
        NativeMapSection *s=map->sections+i;
        s->flags=(s->flags&~(SEC_VISIBLE|SEC_PREVIOUS|SEC_ACTIVE))|SEC_COLLIDABLE|((s->flags&SEC_ACTIVE) ? SEC_PREVIOUS : 0)|(map->section_flags[S_FORCE_ALL]&1)*SEC_ACTIVE;
    }
    func_80800A08_gcmapsects(map,map->section_flags[S_FORCE_ALL]);
    return !map->sections_failed;
}
void gcmapsects_entrypoint_16(NativeMap *map) {
    func_80800C54_gcmapsects(map);heap_free(map->sections);map->sections=NULL;
    map->section_count=map->section_capacity=0;map->section_update=NULL;map->section_flags[S_READY]=0;
    map->section_flags[S_PRIMARY]=map->section_flags[S_SECONDARY]=1;map->section_flags[S_UNUSED]=0;map->section_flags[S_MODE]=3;map->section_distance=0;
}
void gcmapsects_entrypoint_17(NativeMap *map) {
    func_80801640_gcmapsects(map);
    if(map->section_flags[S_PREVIOUS_PRIMARY]!=map->section_flags[S_PRIMARY]) {
        if(map->section_flags[S_PRIMARY])func_800BFF4C();else func_800BFF28();
        map->section_flags[S_PREVIOUS_PRIMARY]=map->section_flags[S_PRIMARY];
    }
    func_800BF4DC(1,map->section_flags[S_SECONDARY]);
}
static void section_draw(NativeMap *map,int side) {
    for(int i=0;i<map->section_count;++i) {
        NativeMapSection *s=map->sections+i;
        if(!(s->flags&SEC_VISIBLE) || !s->assets[side])continue;
        void *model=func_800D674C(s->assets[side]);if(!model)continue;
        void *vertices=func_800B2840(model);func_800BF774();func_800DF830(side+1);
        if(!side){s32 animation=func_800D731C(s->assets[0]);if(animation)func_800DF7E8(animation);}
        if(side){func_800DF440(0);func_800DF428(29999);}
        func_800DF7DC(s->textures[side]);func_800DF818(vertices);
        if(!side){func_800DF440(0);func_800DF428(29999);}
        func_800DF4B0(2);
        if(!func_800DE448(s->position,NULL,1,NULL,model))func_800D62E4(s->assets[side]);
    }
}
void gcmapsects_entrypoint_18(NativeMap *map,s32 mode) {(void)mode;section_draw(map,0);}
void gcmapsects_entrypoint_19(NativeMap *map,s32 mode) {(void)mode;section_draw(map,1);}
s32 gcmapsects_entrypoint_20(NativeMap *map,f32 *a,f32 *b,s16 (**out)[3],s32 flags,f32 scale) {
    for(int i=0;i<map->section_count;++i)if(map->sections[i].flags&SEC_COLLIDABLE) {
        NativeMapSection *s=map->sections+i;void *model=func_800D674C(s->assets[0]);if(!model)return 0;
        return func_800AD2C8(func_800B2720(model),func_800B2840(model),a,b,s->position,out,flags,scale);
    }
    return 0;
}
s32 gcmapsects_entrypoint_21(NativeMap *map,f32 *a,f32 *b,f32 *out,f32 radius) {
    for(int i=0;i<map->section_count;++i)if(map->sections[i].flags&SEC_COLLIDABLE) {
        NativeMapSection *s=map->sections+i;void *model=func_800D674C(s->assets[0]);if(!model)return 0;
        return func_800AD894(func_800B2720(model),func_800B2840(model),a,b,out,s->position,radius);
    }
    return 0;
}
void *gcmapsects_entrypoint_22(NativeMap *map,f32 *a,f32 *b,f32 *out,s32 flags) {
    void *result=NULL;if(!map->section_count)return NULL;map->collision_model=NULL;
    for(int i=0;i<map->section_count;++i)if(map->sections[i].flags&SEC_COLLIDABLE) {
        result=gcmapsects_entrypoint_25(map,i,a,b,out,flags);if(map->collision_model)break;
    }
    return result;
}
void *gcmapsects_entrypoint_23(NativeMap *map,f32 *a,f32 *b,f32 radius,f32 *out,s32 flags,s32 mode) {
    if(!map->section_count)return NULL;map->collision_model=NULL;
    for(int i=0;i<map->section_count;++i)if(map->sections[i].flags&SEC_COLLIDABLE) {
        NativeMapSection *s=map->sections+i;void *model=func_800D674C(s->assets[0]);if(!model)continue;
        func_800D62E4(s->assets[0]);
        void *hit=func_800AC848(func_800B2720(model),func_800B2840(model),s->position,NULL,1,a,b,radius,out,flags,mode);
        if(hit){map->collision_model=model;return hit;}
    }
    return NULL;
}
int gcmapsects_entrypoint_24(NativeMap *map) {return map->section_flags[S_PLAYER_TESTED] && map->selected_section==-1;}
void *gcmapsects_entrypoint_25(NativeMap *map,s32 index,f32 *a,f32 *b,f32 *out,s32 flags) {
    NativeMapSection *s=map_section(map,index);if(!s)return NULL;map->collision_model=NULL;
    void *model=func_800D674C(s->assets[0]);if(!model)return NULL;
    func_800D62E4(s->assets[0]);
    void *hit=NULL;
    if((flags&0x1F00)!=0x1F00)hit=func_800AB868(func_800B2720(model),func_800B2840(model),s->position,NULL,1,a,b,out,flags);
    if(hit){map->collision_model=model;return hit;}
    if(s->assets[1]) {
        model=func_800D674C(s->assets[1]);if(!model)return NULL;func_800D62E4(s->assets[1]);
        void *collision=func_800B2720(model);
        if(collision)hit=func_800AB868(collision,func_800B2840(model),s->position,NULL,1,a,b,out,flags);
    }
    return hit;
}
void *gcmapsects_entrypoint_26(NativeMap *map,f32 *position,f32 radius,f32 *out,u32 flags) {
    if(!map->section_count)return NULL;map->collision_model=NULL;
    for(int i=0;i<map->section_count;++i)if(map->sections[i].flags&SEC_COLLIDABLE) {
        NativeMapSection *s=map->sections+i;void *model=func_800D674C(s->assets[0]);if(!model)continue;
        func_800D62E4(s->assets[0]);
        void *hit=func_800AD1AC(func_800B2720(model),func_800B2840(model),s->position,NULL,1,position,radius,out,flags);
        if(hit){map->collision_model=model;return hit;}
    }
    return NULL;
}
s32 gcmapsects_entrypoint_27(s32 index) {
    NativeMapSection *s=map_section(&native_map,index);
    if(s && (s->flags&SEC_VISIBLE) && func_800D6B0C(s->assets[0])){func_800D62E4(s->assets[0]);return 1;}
    return 0;
}
