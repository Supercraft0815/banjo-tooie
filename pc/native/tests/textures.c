#include "native_texture.h"
#include "native_model.h"
#include "native_render.h"
#include "native_graphics_memory.h"
#include "native_assets.h"
#include "memory.h"
#include <stdio.h>
#include <stdlib.h>
#define CHECK(x) do {if(!(x)){fprintf(stderr,"%s:%d: %s\n",__FILE__,__LINE__,#x);exit(1);}}while(0)
s32 func_8001211C(void) {return 100;}
static void put(u8 *p,u32 value,int width) {for(int i=0;i<width;++i)p[i]=value>>((width-1-i)*8);}
static void fixture(u8 *p) {
    rare_memset(p,0,64);put(p,64,4);put(p+4,2,2);
    put(p+8,4,4);put(p+12,0x8001,2);p[14]=8;p[15]=4;
    put(p+16,24,4);put(p+20,8,2);p[22]=32;p[23]=0;
    for(int i=24;i<64;++i)p[i]=i;
}
static void test_decode(void) {
    u64 storage[8],saved[8];u8 *p=(void *)storage;fixture(p);
    CHECK(native_texture_validate(p,64) && native_texture_decode(p,64));
    NativeModelTextures *block=(void *)p;
    CHECK(block->size==64 && block->count==2 && !block->flags);
    CHECK(block->entries[0].offset==4 && block->entries[0].format==0x8001 && block->entries[0].width==8);
    CHECK(block->entries[1].offset==24 && block->entries[1].format==8 && !block->entries[1].height);
    for(int i=24;i<64;++i)CHECK(p[i]==i);
    CHECK(!dbtex_entrypoint_0(block));dbtex_entrypoint_1(NULL);
    const u32 mutations[][3]={{0,65,4},{0,23,4},{0,0,4},{4,32768,2},{4,8,2},{8,40,4},{16,0xFFFFFFFFu,4}};
    for(unsigned i=0;i<sizeof(mutations)/sizeof(*mutations);++i) {
        fixture(p);put(p+mutations[i][0],mutations[i][1],mutations[i][2]);rare_memcpy(saved,p,64);
        CHECK(!native_texture_decode(p,64));for(int j=0;j<64;++j)CHECK(p[j]==((u8 *)saved)[j]);
    }
    for(u32 size=0;size<64;++size){fixture(p);rare_memcpy(saved,p,64);CHECK(!native_texture_decode(p,size));for(int j=0;j<64;++j)CHECK(p[j]==((u8 *)saved)[j]);}
    CHECK(!native_texture_decode(NULL,64) && !native_texture_decode(p+1,63));
    rare_memset(p,0,64);CHECK(native_texture_decode(p,8));
    fixture(p);put(p,96,4);put(p+6,0x100,2);CHECK(native_texture_decode(p,24));CHECK(block->size==96 && block->flags==0x100);
    fixture(p);put(p+6,0x100,2);put(p+8,0x7FFFFFFFu,4);CHECK(!native_texture_validate(p,64));
}
static void test_expansion_failures(void) {
    struct {u32 size;u16 count,flags;NativeTextureEntry entries[2];} block={0};
    block.size=32;block.count=1;block.flags=0x100;block.entries[0]=(NativeTextureEntry){0x7FFFFFFF,8,4,8};
    CHECK(!dbtex_entrypoint_0(&block));block.entries[0].offset=0;
    block.size=1;CHECK(!dbtex_entrypoint_0(&block));block.size=64u*1024*1024+1;CHECK(!dbtex_entrypoint_0(&block));
    block.size=64;block.count=2;block.entries[1]=(NativeTextureEntry){0x7FFFFFFF,8,4,8};
    CHECK(!dbtex_entrypoint_0(&block));CHECK(block.entries[0].offset==0 && block.entries[1].offset==0x7FFFFFFF && block.flags==0x100);
}
static void test_archive(const char *path) {
    CHECK(native_assets_open(path));test_expansion_failures();
    unsigned models=0,expanded=0,inline_blocks=0,entries=0,loads=0,references=0;u32 total=0;
    NativeGraphicsMemory memory={0};
    for(int id=0;id<native_asset_count();++id) {
        if((native_asset_flags(id)&15) || native_asset_packed_size(id)<=0)continue;
        s32 size;u8 *model=native_asset_load(id,&size);CHECK(model);++models;
        NativeModelTextures *source=func_800B27FC(model);CHECK(source);entries+=source->count;
        NativeModelTextures *copy=dbtex_entrypoint_0(source),*textures=copy ? copy : source;
        u32 header=sizeof(*textures)+textures->count*sizeof(*textures->entries);
        u32 payload=textures->size ? textures->size-header : 0;
        const u8 *pixels=(const u8 *)textures+header;
        if(source->flags&0x100) {
            CHECK(copy && !(copy->flags&0x100) && copy->count==source->count);++expanded;
            u32 offset=0;
            for(u32 i=0;i<source->count;++i) {
                s32 length;u8 *original=native_asset_load(source->entries[i].offset+0x1EF6,&length);CHECK(original);
                CHECK(copy->entries[i].offset==offset && copy->entries[i].format==source->entries[i].format && copy->entries[i].width==source->entries[i].width && copy->entries[i].height==source->entries[i].height);
                CHECK(length>0 && (u32)length<=payload-offset);
                for(s32 j=0;j<length;++j)CHECK(pixels[offset+j]==original[j]);
                offset+=length;++loads;heap_free(original);
            }
            CHECK(offset==payload && source->size==payload);total+=payload;
        } else {CHECK(!copy);++inline_blocks;}
        if(payload) {
            u32 address=native_graphics_register(&memory,pixels,payload);CHECK(address && native_graphics_segment(&memory,2,address));
            u32 offset=((u32 *)model)[3];NativeDisplayList *display=(void *)(model+offset);
            if(offset)for(u32 i=0;i<display->header[0];++i) {
                Gfx *packet=display->commands+i;
                if((packet->words.w0>>24)==0xFD && (packet->words.w1>>24)==2) {
                    CHECK(native_graphics_resolve(&memory,packet->words.w1,1));++references;
                }
            }
        }
        native_graphics_reset(&memory);dbtex_entrypoint_1(copy);heap_free(model);
    }
    native_graphics_dispose(&memory);native_assets_shutdown();CHECK(models && expanded);
    printf("Checked %u model texture blocks (%u inline, %u expanded), %u descriptors, %u external loads / %u bytes, %u image references.\n",models,inline_blocks,expanded,entries,loads,total,references);
}
int main(int argc,char **argv) {CHECK(argc==2);test_decode();test_archive(argv[1]);puts("native texture metadata, original external payloads and segmented image references passed");return 0;}
