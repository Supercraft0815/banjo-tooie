#include "native_render.h"
#include "native_graphics_memory.h"
#include "native_assets.h"
#include "memory.h"
#include <stdio.h>
#include <stdlib.h>
#define CHECK(x) do {if(!(x)){fprintf(stderr,"%s:%d: %s\n",__FILE__,__LINE__,#x);exit(1);}}while(0)
s32 func_8001211C(void) {return 100;}
static void test_modes(void) {
    CHECK(native_model_render_modes(4,255)==native_model_render_banks[0]);
    CHECK(native_model_render_modes(4,0)==native_model_render_banks[3]);
    const int banks[4][2]={{0,3},{1,4},{2,5},{6,7}};NativeGraphicsMemory memory={0};
    for(int depth=0;depth<4;++depth)for(int translucent=0;translucent<2;++translucent) {
        Gfx *list=native_model_render_modes(depth,translucent ? 254 : 255);
        CHECK(list==native_model_render_banks[banks[depth][translucent]]);
        CHECK(native_graphics_segment(&memory,3,native_graphics_register(&memory,list,sizeof(native_model_render_banks[0]))));
        for(int i=0;i<NATIVE_MODEL_RENDER_PACKETS;i+=2) {
            CHECK(native_graphics_resolve(&memory,0x03000000+i*sizeof(Gfx),2*sizeof(Gfx))==list+i);
            CHECK(list[i].words.w0==0xE200001C && list[i+1].words.w0==0xDF000000 && !list[i+1].words.w1);
        }
        CHECK(!native_graphics_resolve(&memory,0x03000000+sizeof(native_model_render_banks[0]),sizeof(Gfx)));
    }
    CHECK(!native_model_render_modes(-1,255) && !native_model_render_modes(5,0));
    Gfx custom[4]={0};func_800DF848(custom,custom+2);
    CHECK(native_render.depth_mode==4 && native_model_render_modes(4,255)==custom && native_model_render_modes(4,128)==custom+2);
    func_800DE318();CHECK(native_model_render_modes(4,255)==custom);
    func_800DF848(NULL,NULL);CHECK(!native_model_render_modes(4,255) && !native_model_render_modes(4,0));
    func_800DF848(native_model_render_banks[0],native_model_render_banks[3]);func_800DE318();native_graphics_dispose(&memory);
}
static void dump(const Gfx *packets,unsigned count) {
    for(unsigned i=0;i<count;++i)printf("%08X %08X\n",packets[i].words.w0,packets[i].words.w1);
}
static void test_archive(const char *path) {
    CHECK(native_assets_open(path));NativeGraphicsMemory memory={0};unsigned models=0,references=0;
    for(int id=0;id<native_asset_count();++id) {
        if((native_asset_flags(id)&15) || native_asset_packed_size(id)<=0)continue;
        s32 size;u8 *model=native_asset_load(id,&size);CHECK(model);
        NativeDisplayList *display=func_800B2714(model);CHECK(display);
        for(int bank=0;bank<8;++bank) {
            Gfx *modes=native_model_render_banks[bank];
            CHECK(native_graphics_segment(&memory,3,native_graphics_register(&memory,modes,sizeof(native_model_render_banks[0]))));
            for(u32 i=0;i<display->header[0];++i) {
                Gfx *packet=display->commands+i;
                if(packet->words.w0>>24!=G_DL || packet->words.w1>>24!=3)continue;
                CHECK((packet->words.w1&15)==0);
                const Gfx *target=native_graphics_resolve(&memory,packet->words.w1,2*sizeof(Gfx));CHECK(target);
                CHECK(target->words.w0==0xE200001C && target[1].words.w0==0xDF000000 && !target[1].words.w1);++references;
            }
        }
        ++models;heap_free(model);
    }
    native_graphics_dispose(&memory);native_assets_shutdown();CHECK(models && references);
    printf("Resolved %u original model render-mode references across 8 banks and %u models.\n",references,models);
}
int main(int argc,char **argv) {
    CHECK(argc==1 || argc==2);test_modes();
    if(argc==2)test_archive(argv[1]);
    else {
        for(int bank=0;bank<8;++bank)dump(native_model_render_banks[bank],NATIVE_MODEL_RENDER_PACKETS);
        dump(native_model_render_restore,3);dump(native_model_modes(2),24);dump(native_model_modes(0x80),24);dump(native_model_modes(0x100),24);
    }
    return 0;
}
