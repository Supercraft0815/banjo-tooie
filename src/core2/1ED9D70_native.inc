#include "native_vertex_cache.h"
#include "core2/1EAF950.h"
#include "memory.h"
#include <limits.h>

s32 func_8001211C(void);
static struct { s32 stride,capacity,frame; void *data; } scratch[5]={{.stride=3},{.stride=4},{.stride=12},{.stride=12},{.stride=6}};
static FreeList *vertex_entries,*packed_entries;
static s32 unique_palette=0x3667;

void *func_80100480(s32 type,s32 count) {
    if(type<0 || type>=5 || count<0 || count>INT_MAX/scratch[type].stride) return NULL;
    if(!scratch[type].data || scratch[type].capacity<count) {
        scratch[type].data=heap_realloc(scratch[type].data,count*scratch[type].stride);
        scratch[type].capacity=count;
    }
    scratch[type].frame=func_8001211C();return scratch[type].data;
}
void func_8010052C(void) { }
void func_80100534(void) {
    s32 frame=func_8001211C();
    for(s32 i=0;i<5;++i) if(scratch[i].data && frame-scratch[i].frame>=31) {
        heap_free(scratch[i].data);scratch[i].data=NULL;scratch[i].capacity=scratch[i].frame=0;
    }
}
void func_801005B8(void) { }
void func_80100610(void) {
    for(s32 i=0;i<5;++i) {
        if(scratch[i].data) heap_free(scratch[i].data);
        scratch[i].data=NULL;scratch[i].capacity=scratch[i].frame=0;
    }
}
void func_80100670(void) { func_80100610(); }
NativeVertexCacheEntry *func_80100690(s32 *index) {
    if(!vertex_entries) vertex_entries=freelist_new(sizeof(NativeVertexCacheEntry),2);
    return freelist_next(&vertex_entries,index);
}
NativePackedVertexEntry *func_801006E0(s32 *index) {
    if(!packed_entries) packed_entries=freelist_new(sizeof(NativePackedVertexEntry),2);
    return freelist_next(&packed_entries,index);
}
int func_8010072C(s32 *color,u8 *packed) {
    return color ? color[0]==packed[0] && color[1]==packed[1] && color[2]==packed[2] : packed[0]==255 && packed[1]==255 && packed[2]==255;
}
s32 func_801007B8(void *model,s32 asset,s32 palette,s32 *color) {
    s32 index;
    if(packed_entries) for(index=1;index<freelist_capacity(packed_entries);++index) {
        if(!freelist_is_element_alive(packed_entries,index)) continue;
        NativePackedVertexEntry *entry=freelist_at(packed_entries,index);
        if(entry->asset==asset && entry->palette==palette && func_8010072C(color,entry->color)) { ++entry->refs;return index; }
    }
    NativePackedVertexEntry *entry=func_801006E0(&index);
    void *image=palette ? (void *)func_800D674C(palette) : NULL;
    entry->data=_glpackvtx_entrypoint_0(func_800B2840(model),image,color);
    entry->asset=asset;entry->palette=palette;entry->refs=1;
    for(s32 i=0;i<3;++i) entry->color[i]=color ? color[i] : 255;
    return index;
}
void func_80100938(s32 index) {
    NativePackedVertexEntry *entry=freelist_at(packed_entries,index);
    if(--entry->refs) return;
    _glpackvtx_entrypoint_1(entry->data);entry->data=NULL;entry->asset=0;
    freelist_erase(packed_entries,index);
    if(!freelist_used_count(packed_entries)) { freelist_free(packed_entries);packed_entries=NULL; }
}
void func_801009C4(NativeVertexCacheEntry *entry,s32 index) {
    for(s32 i=0;i<2;++i) if(entry->vertices[i]) func_800B23E0(entry->vertices[i]);
    if(entry->packed)func_80100938(entry->packed);
    entry->active=0;freelist_erase(vertex_entries,index);
    if(!freelist_used_count(vertex_entries)) {freelist_free(vertex_entries);vertex_entries=NULL;}
}
void *func_80100A74(s16 index,s32 buffer) {
    if(!vertex_entries || index<=0 || index>=freelist_capacity(vertex_entries) || !freelist_is_element_alive(vertex_entries,index) || buffer<0 || buffer>1)return NULL;
    NativeVertexCacheEntry *entry=freelist_at(vertex_entries,index);
    return entry->active ? entry->vertices[buffer] : NULL;
}
void *func_80100AC4(s16 index) {
    if(!vertex_entries || index<=0 || index>=freelist_capacity(vertex_entries) || !freelist_is_element_alive(vertex_entries,index))return NULL;
    NativeVertexCacheEntry *entry=freelist_at(vertex_entries,index);
    if(!entry->packed)return NULL;
    NativePackedVertexEntry *packed=freelist_at(packed_entries,entry->packed);
    return packed->refs ? packed->data : NULL;
}
void func_80100B3C(void) {unique_palette=0x3667;}
void func_80100B4C(void) {
    func_80100C74();func_80100C74();
    for(s32 i=1;vertex_entries && i<freelist_capacity(vertex_entries);++i)
        if(freelist_is_element_alive(vertex_entries,i))func_801009C4(freelist_at(vertex_entries,i),i);
    if(vertex_entries){freelist_free(vertex_entries);vertex_entries=NULL;}
    if(packed_entries) {
        for(s32 i=1;i<freelist_capacity(packed_entries);++i)if(freelist_is_element_alive(packed_entries,i)) {
            NativePackedVertexEntry *entry=freelist_at(packed_entries,i);_glpackvtx_entrypoint_1(entry->data);
        }
        freelist_free(packed_entries);packed_entries=NULL;
    }
}
void func_80100C74(void) {
    for(s32 i=1;vertex_entries && i<freelist_capacity(vertex_entries);++i)if(freelist_is_element_alive(vertex_entries,i)) {
        NativeVertexCacheEntry *entry=freelist_at(vertex_entries,i);
        if(entry->age && !--entry->age)func_801009C4(entry,i);
    }
}
s16 func_80100D24(void *model,s32 asset,s32 buffers,s32 packed,s32 palette,s32 *color) {
    if(!model || buffers<0 || buffers>2)return 0;
    s32 index;NativeVertexCacheEntry *entry=func_80100690(&index);
    NativeVertexList *list=func_800B2840(model);
    for(s32 i=0;i<2;++i) {
        entry->vertices[i]=i<buffers ? func_800B2400(list,0) : NULL;
        if(entry->vertices[i])entry->vertices[i]->count_flags|=1;
    }
    entry->packed=packed ? func_801007B8(model,asset,palette,color) : 0;
    entry->active=1;entry->age=0;return index;
}
void func_80100E18(s16 index) {
    NativeVertexCacheEntry *entry=freelist_at(vertex_entries,index);entry->age=2;
}
void func_80100E54(void) { }
void func_80100F0C(s16 index,void *palette) {
    NativeVertexCacheEntry *entry=freelist_at(vertex_entries,index);
    if(!entry->packed)return;
    NativePackedVertexEntry *packed=freelist_at(packed_entries,entry->packed);
    if(!packed->refs)return;
    s32 asset=packed->asset;
    if(packed->palette<0x3666) {
        func_80100938(entry->packed);
        packed=func_801006E0(&entry->packed);
    } else _glpackvtx_entrypoint_1(packed->data);
    void *model=func_800D674C(asset);
    packed->data=_glpackvtx_entrypoint_0(func_800B2840(model),palette,NULL);
    packed->asset=asset;packed->palette=unique_palette++;packed->refs=1;
    for(s32 i=0;i<3;++i)packed->color[i]=255;
}
