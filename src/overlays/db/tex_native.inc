#include "native_texture.h"
#include "native_assets.h"
#include "memory.h"
void *dbtex_entrypoint_0(void *data) {
    NativeModelTextures *source=data;
    if(!source || !(source->flags&0x100))return NULL;
    u32 header=sizeof(*source)+source->count*sizeof(*source->entries);
    if(source->count>32767 || source->size>64u*1024*1024)return NULL;
    NativeModelTextures *result=heap_alloc(header+source->size);
    rare_memcpy(result,source,header);u8 *pixels=(u8 *)result+header;u32 used=0;
    for(u32 i=0;i<source->count;++i) {
        u32 id=source->entries[i].offset;
        if(id>0x7FFFFFFFu-0x1EF6)goto failed;
        id+=0x1EF6;
        if((native_asset_flags(id)&31)!=19)goto failed;
        s32 size;void *texture=native_asset_load(id,&size);
        if(!texture)goto failed;
        if(size<0 || (u32)size>source->size-used){heap_free(texture);goto failed;}
        rare_memcpy(pixels+used,texture,size);heap_free(texture);
        result->entries[i].offset=used;used+=size;
    }
    if(used!=source->size)goto failed;
    result->size=header+used;result->flags&=~0x100;
    return result;
failed:
    heap_free(result);return NULL;
}
void dbtex_entrypoint_1(void *data) {heap_free(data);}
