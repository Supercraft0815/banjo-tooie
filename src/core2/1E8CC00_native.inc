#include "native_model_lighting.h"
#include "native_lights.h"
#include "memory.h"
#include <limits.h>
#include <math.h>
NativeModelLightList *func_800B3310(s32 capacity) {
    if(capacity<0 || capacity>(INT_MAX-(s32)sizeof(NativeModelLightList))/(s32)sizeof(NativeModelLight))return NULL;
    NativeModelLightList *list=heap_alloc(sizeof(*list)+capacity*sizeof(NativeModelLight));
    func_800B38C8(list);list->capacity=capacity;list->used=list->entries;list->end=list->entries+capacity;return list;
}
void func_800B3370(void *list) {heap_free(list);}
NativeModelLight *func_800B3390(NativeModelLightList *list,f32 distance) {
    NativeModelLight *entry=list->entries;
    while(entry<list->used && !(distance<entry->distance))++entry;
    if(entry==list->used){if(list->used==list->end)return NULL;return list->used++;}
    if(list->used==list->end)--list->used;
    rare_memmove(entry+1,entry,(list->used-entry)*sizeof(*entry));++list->used;return entry;
}
s32 func_800B3494(NativeModelLightList *list,f32 *position,f32 radius) {
    list->used=list->entries;
    for(s32 id=func_800C8760(0,1);id;id=func_800C878C(id,0,1)) {
        f32 light_position[3],range[3],delta[3];s32 color[3];
        func_800C8800(id,light_position);func_800C8898(id,range);
        for(int i=0;i<3;++i)delta[i]=light_position[i]-position[i];
        f32 distance=sqrtf(delta[0]*delta[0]+delta[1]*delta[1]+delta[2]*delta[2]);
        if(range[1]+radius<=distance)continue;
        NativeModelLight *entry=func_800B3390(list,distance);if(!entry)continue;
        entry->distance=distance;
        /* A coincident point light has no direction; avoid NaNs in vertex colors. */
        f32 inverse=distance>0 ? 1.0f/distance : 0;
        for(int i=0;i<3;++i)entry->direction[i]=delta[i]*inverse;
        distance-=radius;func_800C8900(id,color);
        if(distance<=range[0])for(int i=0;i<3;++i)entry->color[i]=color[i];
        else {f32 scale=1-(distance-range[0])*range[2];for(int i=0;i<3;++i)entry->color[i]=color[i]*scale;}
    }
    return func_800B3784(list);
}
int func_800B36C0(NativeModelLightList *list,f32 *direction,s32 *color,f32 distance) {
    if(list->used==list->end)return 0;
    for(int i=0;i<3;++i){list->used->direction[i]=direction[i];list->used->color[i]=color[i];}
    list->used->distance=distance;++list->used;return 1;
}
void func_800B3748(NativeModelLightList *list) {f32 direction[3];s32 color[3];func_800C8960(color,direction);func_800B36C0(list,direction,color,500);}
s32 func_800B3784(NativeModelLightList *list) {return list->used-list->entries;}
void func_800B37A4(NativeModelLightList *list,NativeModelLight **start,NativeModelLight **end) {*start=list->entries;*end=list->used;}
void func_800B37B8(NativeModelLightList *list,s32 *out) {for(int i=0;i<3;++i)out[i]=list->ambient[i];}
void func_800B37E4(NativeModelLightList *to,NativeModelLightList *from) {
    s32 count=func_800B3784(from),limit=to->end-to->entries;if(count>limit)count=limit;
    rare_memmove(to->entries,from->entries,count*sizeof(NativeModelLight));to->used=to->entries+count;
    for(int i=0;i<3;++i)to->ambient[i]=from->ambient[i];
}
void func_800B388C(NativeModelLightList *list,s32 count) {
    if(count<0)count=0;if(count>list->capacity)count=list->capacity;
    list->end=list->entries+count;if(list->used>list->end)list->used=list->end;
}
void func_800B38A8(NativeModelLightList *list,s32 *color) {for(int i=0;i<3;++i)list->ambient[i]=color[i];}
void func_800B38C8(NativeModelLightList *list) {func_800C87B8(list->ambient);}
NativeModelLightList *func_800B38E8(NativeModelLightList *list) {return list;}
