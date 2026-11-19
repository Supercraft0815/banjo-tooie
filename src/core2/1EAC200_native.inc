#include "native_fog.h"
#include "native_world_grid.h"
#include "native_camera_frame.h"
#include "memory.h"
#include <limits.h>
#include <math.h>
static struct {
    u8 count,color_sent;
    struct {u8 active;s16 color[4];f32 start,end;} entries[2];
    s16 color[4],*layers;s32 layer_count;
} fog;
#include "fog_configs.inc"
void func_800D2910(s32 index,const NativeFogConfig *config) {
    if(!config || index<0 || index>=2)return;
    fog.entries[index].active=1;
    for(int i=0;i<4;++i)fog.entries[index].color[i]=config->color[i];
    fog.entries[index].start=config->start;fog.entries[index].end=config->end;++fog.count;
}
void func_800D2970(void) {fog.entries[0].active=fog.entries[1].active=fog.count=fog.color_sent=0;}
void native_fog_load_map(s32 map) {
    func_800D2970();
    for(unsigned i=0;D_8011B530[i].map!=-1;++i)if(D_8011B530[i].map==map) {
        if(D_8011B530[i].flags&1)func_800D2910(0,D_8011B530+i);
        if(D_8011B530[i].flags&2)func_800D2910(1,D_8011B530+i);
    }
}
void func_800D298C(void) {s32 func_800EA05C(void);native_fog_load_map(func_800EA05C());}
static s32 fog_word(f32 value) {
    /* Preserve MIPS invalid-conversion behavior before the original s16 clamp. */
    return isfinite(value) && value>=-2147483648.0f && value<2147483648.0f ? (s32)value : INT_MIN;
}
void native_fog_apply(Gfx **output,s32 visible) {
    s32 func_800F0D90(s32,s32,s32);
    if(!fog.count || !output || !*output || !func_800E42A8())return;
    s32 index;
    if(fog.entries[1].active && visible)index=1;
    else if(fog.entries[0].active && !visible)index=0;
    else return;
    f32 near,far;func_800E3CB8(&near,&far);f32 scale=far-near;
    if(far==near)return;
    for(int i=0;i<4;++i)fog.color[i]=fog.entries[index].color[i];
    f32 start=fog.entries[index].start,end=fog.entries[index].end;
    s32 mult=0,offset=0;
    if(!(far<start)) {
        scale=(2.0f*far)/scale;
        f32 first=(1.0f-near/start)*scale-1.0f;
        scale=1.0f/((1.0f-near/end)*scale-1.0f-first);
        mult=fog_word(256.0f*scale);offset=fog_word(-256.0f*first*scale);
    }
    Gfx *packet=(*output)++;packet->words.w0=0xDB080000;
    packet->words.w1=((u32)(func_800F0D90(mult,-0x7FFF,0x7FFF)&0xFFFF)<<16)|(func_800F0D90(offset,-0x7FFF,0x7FFF)&0xFFFF);
    func_800D2CC4();
}
void func_800D2A44(Gfx **output) {
    s32 func_800A89F8(void),func_800A9478(s32),func_800F6BE4(BtIntPtr),func_8010FFD8(s16 *);
    s16 *func_800A93E4(BtIntPtr);
    if(!fog.count)return;
    s32 camera=func_800A9478(func_800A89F8());
    native_fog_apply(output,func_800F6BE4(camera) ? func_8010FFD8(func_800A93E4(camera)) : 1);
}
void func_800D2C54(Gfx **output) {
    if(fog.color_sent || !output || !*output)return;
    gDPSetFogColor((*output)++,fog.color[0],fog.color[1],fog.color[2],fog.color[3]);fog.color_sent=1;
}
void func_800D2CC4(void) {fog.color_sent=0;}
void func_800D2CD0(void) {
    s32 dimensions[3],strides[3];NativeWorldCell *begin,*end;
    func_800BE58C(dimensions,strides);func_800BE52C(&begin,&end);func_800D2E4C();
    if(!begin || dimensions[0]<=0 || dimensions[1]<=0 || dimensions[2]<=0 || strides[0]<=0 || strides[1]<=0 || dimensions[1]>INT_MAX/2)return;
    s64 last=(s64)dimensions[0]-1+(s64)(dimensions[1]-1)*strides[0]+(s64)(dimensions[2]-1)*strides[1];
    if(last>=end-begin)return;
    fog.layer_count=dimensions[1];fog.layers=heap_alloc(fog.layer_count*sizeof(*fog.layers));
    rare_memset(fog.layers,0,fog.layer_count*sizeof(*fog.layers));
    for(s32 y=0;y<dimensions[1];++y)for(s32 x=0;x<dimensions[0];++x)for(s32 z=0;z<dimensions[2];++z) {
        NativeWorldCell *cell=begin+x+(size_t)strides[0]*y+(size_t)strides[1]*z;
        if(func_800E9D68(cell))fog.layers[y]+=func_800E9DC4(cell);
    }
}
void func_800D2E4C(void) {heap_free(fog.layers);fog.layers=NULL;fog.layer_count=0;}
s32 func_800D2E90(s32 index) {return index>=0 && index<fog.layer_count && fog.layers[index]!=0;}
void func_800D2EE4(void) {if(fog.layers)fog.layers=defrag(fog.layers);}
