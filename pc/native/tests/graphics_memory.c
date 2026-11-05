#include "native_render.h"
#include "native_graphics_memory.h"
#include "native_assets.h"
#include "core2/1EAF950.h"
#include "memory.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define CHECK(x) do {if(!(x)){fprintf(stderr,"%s:%d: %s\n",__FILE__,__LINE__,#x);exit(1);}}while(0)
s32 func_8001211C(void) {return 100;}

static void test_ranges(void) {
    NativeGraphicsMemory memory={0};u8 first[128],second[64];
    CHECK(!native_graphics_register(NULL,first,sizeof(first)));
    CHECK(!native_graphics_register(&memory,NULL,1) && !native_graphics_register(&memory,first,0));
    CHECK(!native_graphics_register(&memory,first,SIZE_MAX));
    u32 a=native_graphics_register(&memory,first,sizeof(first));
    u32 b=native_graphics_register(&memory,second,sizeof(second));
    CHECK(a==0x10000000 && b==a+128 && memory.count==2);
    CHECK(native_graphics_register(&memory,first+16,32)==a+16 && memory.count==2);
    CHECK(!native_graphics_register(&memory,first+120,16) && memory.count==2);
    CHECK(native_graphics_address(&memory,first+120,8)==a+120);
    CHECK(!native_graphics_address(&memory,first+120,9) && !native_graphics_address(&memory,first,0));
    CHECK(native_graphics_resolve(&memory,a+120,8)==first+120);
    CHECK(!native_graphics_resolve(&memory,a+120,9) && !native_graphics_resolve(&memory,b+64,1));
    CHECK(!native_graphics_resolve(&memory,a,SIZE_MAX) && !native_graphics_resolve(&memory,a,0));
    CHECK(!native_graphics_resolve(&memory,0x01000000,1));
    CHECK(native_graphics_segment(&memory,1,a+16));
    CHECK(native_graphics_resolve(&memory,0x01000008,8)==first+24);
    CHECK(native_graphics_resolve(&memory,0x01000068,8)==first+120);
    /* A segment must not escape into the next registered allocation. */
    CHECK(!native_graphics_resolve(&memory,0x01000070,1));
    CHECK(!native_graphics_resolve(&memory,0x01FFFFFF,1));
    CHECK(!native_graphics_segment(&memory,16,a) && !native_graphics_segment(&memory,2,0x01000000));
    CHECK(!native_graphics_segment(&memory,1,0x7FFFFFFF) && memory.segments[1]==a+16);
    CHECK(native_graphics_segment(&memory,1,0) && !native_graphics_resolve(&memory,0x01000000,1));
    CHECK(!native_graphics_bind(&memory));CHECK(native_graphics_pointer(first+17)==a+17);
    CHECK(osVirtualToPhysical(first)==a && OS_K0_TO_PHYSICAL(first)==a && OS_K1_TO_PHYSICAL(first)==a);
    CHECK(BT_GFX_ADDRESS(0x01000020)==0x01000020 && BT_GFX_ADDRESS(first+20)==a+20);
    CHECK(!native_graphics_pointer(NULL));
    NativeGraphicsMemory other={0};CHECK(native_graphics_bind(&other)==&memory);
    CHECK(native_graphics_bind(&memory)==&other);
    native_graphics_reset(&memory);CHECK(memory.capacity>=32 && !memory.count && !memory.segments[1]);
    CHECK(!native_graphics_address(&memory,first,1) && !native_graphics_resolve(&memory,a,1));
    memory.next=0x7FFFFFF8;CHECK(!native_graphics_register(&memory,first,9));
    CHECK(native_graphics_register(&memory,first,8)==0x7FFFFFF8);
    CHECK(native_graphics_segment(&memory,15,0x7FFFFFF8));
    CHECK(native_graphics_resolve(&memory,0x0F000007,1)==first+7);
    CHECK(!native_graphics_resolve(&memory,0x0F000008,1) && !native_graphics_register(&memory,second,1));
    native_graphics_reset(&memory);
    for(unsigned i=0;i<128;++i)CHECK(native_graphics_register(&memory,first+i,1)==0x10000000+i*8);
    CHECK(memory.count==128 && memory.capacity>=128);
    CHECK(!native_graphics_register(&memory,first,sizeof(first)));
    for(unsigned i=0;i<128;++i)CHECK(native_graphics_resolve(&memory,0x10000000+i*8,1)==first+i);
    native_graphics_dispose(&memory);CHECK(!native_graphics_bind(NULL) && !memory.ranges && !memory.count && !memory.capacity);
}

static void test_sdk(void) {
    NativeGraphicsMemory memory={0};
    struct {Mtx matrices[2];Gfx list[2];Vtx vertices[3];Vp viewport;LookAt look;Light light;u16 texture[16];} data={0};
    u32 address=native_graphics_register(&memory,&data,sizeof(data));CHECK(address);
    CHECK(!native_graphics_bind(&memory));
    mlMtxIdent();mlMtxTranslate(12,-34,56);mlMtxApply(data.matrices);
    struct {Gfx commands[13];u64 guard;} output={.guard=0xABCDEF0123456789ULL};Gfx *cursor=output.commands;
    Mtx *matrices=data.matrices;Gfx *list=data.list;Vtx *vertices=data.vertices;
    gSPMatrix(cursor++,matrices++,G_MTX_MODELVIEW|G_MTX_LOAD|G_MTX_PUSH);
    gSPDisplayList(cursor++,list++);gSPBranchList(cursor++,list);
    gSPVertex(cursor++,vertices++,2,0);gSPViewport(cursor++,&data.viewport);
    gSPSegment(cursor++,1,data.vertices);gSPLight(cursor++,&data.light,1);
    gSPLookAt(cursor++,&data.look);
    gDPSetTextureImage(cursor++,G_IM_FMT_RGBA,G_IM_SIZ_16b,4,data.texture);
    gDPSetColorImage(cursor++,G_IM_FMT_RGBA,G_IM_SIZ_16b,4,data.texture);
    gDPSetDepthImage(cursor++,data.texture);gSPEndDisplayList(cursor++);
    CHECK(cursor==output.commands+13 && matrices==data.matrices+1 && list==data.list+1 && vertices==data.vertices+1);
    CHECK(output.guard==0xABCDEF0123456789ULL);
    u32 expected[]={0xDA380002,0xDE000000,0xDE010000,0x01002004,0xDC080008,0xDB060004,
        0xDC08060A,0xDC08000A,0xDC08030A,0xFD100003,0xFF100003,0xFE000000,0xDF000000};
    const void *pointers[]={data.matrices,data.list,data.list+1,data.vertices,&data.viewport,data.vertices,
        &data.light,&data.look.l[0],&data.look.l[1],data.texture,data.texture,data.texture};
    for(int i=0;i<13;++i)CHECK(output.commands[i].words.w0==expected[i]);
    for(int i=0;i<12;++i)CHECK(native_graphics_resolve(&memory,output.commands[i].words.w1,1)==pointers[i]);
    CHECK(native_graphics_resolve(&memory,output.commands[0].words.w1,sizeof(Mtx))==data.matrices);
    f32 decoded[4][4];guMtxL2F(decoded,(Mtx *)native_graphics_resolve(&memory,output.commands[0].words.w1,sizeof(Mtx)));
    CHECK(decoded[3][0]==12 && decoded[3][1]==-34 && decoded[3][2]==56 && decoded[3][3]==1);
    CHECK(native_graphics_segment(&memory,1,output.commands[5].words.w1));
    CHECK(native_graphics_resolve(&memory,0x01000010,sizeof(Vtx))==data.vertices+1);
    native_graphics_dispose(&memory);
}

static void test_look_at(void) {
    NativeGraphicsMemory memory={0};struct {Mtx matrix;LookAt look;u64 guard;} data={.guard=0xABCDEF0123456789ULL};
    CHECK(sizeof(LookAt)==32 && native_graphics_register(&memory,&data,sizeof(data)));native_graphics_bind(&memory);
    for(int i=0;i<40;++i) {
        f32 eye[3]={8,-12,16},target[3]={8+i-20,-12+(i%7)-3,16-i-1};
        if(!i){target[0]=8;target[1]=-12;target[2]=15;}
        func_80013C80(&data.matrix,&data.look,eye[0],eye[1],eye[2],target[0],target[1],target[2],0,1,0);
        double forward[3],right[3],up[3],length=0;
        for(int c=0;c<3;++c){forward[c]=eye[c]-target[c];length+=forward[c]*forward[c];}
        length=sqrt(length);for(int c=0;c<3;++c)forward[c]/=length;
        length=sqrt(forward[0]*forward[0]+forward[2]*forward[2]);right[0]=forward[2]/length;right[1]=0;right[2]=-forward[0]/length;
        up[0]=forward[1]*right[2];up[1]=forward[2]*right[0]-forward[0]*right[2];up[2]=-forward[1]*right[0];
        f32 matrix[4][4];guMtxL2F(matrix,&data.matrix);
        for(int column=0;column<3;++column) {
            const double *axis=column==0 ? right : column==1 ? up : forward;double translation=0;
            for(int c=0;c<3;++c){CHECK(fabs(matrix[c][column]-axis[c])<0.0001);translation-=eye[c]*axis[c];}
            CHECK(fabs(matrix[3][column]-translation)<0.0001 && matrix[column][3]==0);
        }
        for(int c=0;c<3;++c) {
            int r=(int)fmin(right[c]*128,127),u=(int)fmin(up[c]*128,127);
            CHECK(abs(data.look.l[0].l.dir[c]-r)<=1 && abs(data.look.l[1].l.dir[c]-u)<=1);
            CHECK(data.look.l[0].l.col[c]==0 && data.look.l[0].l.colc[c]==0);
            CHECK(data.look.l[1].l.col[c]==(c==1 ? 128 : 0) && data.look.l[1].l.colc[c]==data.look.l[1].l.col[c]);
        }
        CHECK(matrix[3][3]==1 && data.guard==0xABCDEF0123456789ULL);
        if(!i)CHECK(data.look.l[0].l.dir[0]==127 && data.look.l[1].l.dir[1]==127 && matrix[3][2]==-16);
        Gfx packets[2],*cursor=packets;gSPLookAt(cursor++,&data.look);CHECK(cursor==packets+2);
        CHECK(packets[0].words.w0==0xDC08000A && packets[1].words.w0==0xDC08030A);
        CHECK(native_graphics_resolve(&memory,packets[0].words.w1,16)==&data.look.l[0]);
        CHECK(native_graphics_resolve(&memory,packets[1].words.w1,16)==&data.look.l[1]);
    }
    native_graphics_dispose(&memory);
}

static void test_archive(const char *path) {
    CHECK(native_assets_open(path));NativeGraphicsMemory memory={0};unsigned models=0,loads=0,vertices=0;
    native_graphics_bind(&memory);
    for(int id=0;id<native_asset_count();++id) {
        if((native_asset_flags(id)&15)!=0 || native_asset_packed_size(id)<=0)continue;
        u8 *model=(void *)func_800D674C(id);CHECK(model);
        NativeDisplayList *list=func_800B2714(model);NativeVertexList *v=func_800B2840(model);
        u32 count=func_800B2344(v);
        if(count)CHECK(native_graphics_segment(&memory,1,native_graphics_register(&memory,v->vertices,count*sizeof(Vtx))));
        if(list->header[0]) {
            CHECK(native_graphics_register(&memory,list->commands,list->header[0]*sizeof(Gfx)));
            Gfx command;gSPDisplayList(&command,list->commands);
            CHECK(native_graphics_resolve(&memory,command.words.w1,sizeof(Gfx))==list->commands);
        }
        for(u32 i=0;i<list->header[0];++i) {
            Gfx command=list->commands[i];
            if(command.words.w0>>24!=G_VTX)continue;
            u32 n=(command.words.w0>>12)&255,offset=command.words.w1&0xFFFFFFu;
            CHECK(command.words.w1>>24==1 && n && offset%sizeof(Vtx)==0);
            if(offset/sizeof(Vtx)>count || n>count-offset/sizeof(Vtx)) {
                fprintf(stderr,"model %d packet %u: vertex offset %u count %u exceeds %u\n",id,i,offset,n,count);exit(1);
            }
            CHECK(native_graphics_resolve(&memory,command.words.w1,n*sizeof(Vtx))==(u8 *)v->vertices+offset);
            ++loads;vertices+=n;
        }
        ++models;native_graphics_reset(&memory);
        func_800D62E4(id);func_800D6CEC(id);func_800D5E74();func_800D5E74();
    }
    native_graphics_dispose(&memory);native_assets_shutdown();CHECK(models && loads && vertices);
    printf("Mapped %u original models: %u vertex-load packets / %u vertex references.\n",models,loads,vertices);
}

int main(int argc,char **argv) {
    test_ranges();test_sdk();test_look_at();if(argc==2)test_archive(argv[1]);else CHECK(argc==1);
    puts("native graphics pointer registration, segmented addressing and SDK packets passed");return 0;
}
