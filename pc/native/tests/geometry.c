#include "native_geometry.h"
#include "native_model_lighting.h"
#include "native_vector_table.h"
#include "native_zones.h"
#include "native_camera_frame.h"
#include "native_assets.h"
#include "core2/1EAF950.h"
#include "memory.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define CHECK(x) do {if(!(x)){fprintf(stderr,"%s:%d: %s\n",__FILE__,__LINE__,#x);exit(1);}}while(0)
s32 func_8001211C(void) {return 100;}
void func_80019AA0(MtxF *,MtxF *);
static Gfx packets[8192],modes[16];static Mtx matrices[2048];static f32 camera[25],position[3];
static NativeGraphicsMemory memory;
static NativeDisplayList *display;
static NativeVertexList *vertices;static NativeVertexLight colors[16];static s8 normals[64];
static NativeBoneMatrices *bones;static NativeVectorTable attachments;static u8 zones[16],marks[2];
static NativeModelLightList *lights;
static void put(u8 *p,u32 value,int width) {for(int i=0;i<width;++i)p[i]=value>>((width-1-i)*8);}
static void fixture(u8 *p,u32 op) {
    rare_memset(p,0,256);put(p,op,4);put(p+4,160,4);
    for(int i=0;i<3;++i){put(p+128+i*16,3,4);put(p+136+i*16,i+1,2);}
    switch(op) {
        case 0:put(p+8,128,2);put(p+10,1,2);put(p+12,0x3F800000,4);break;
        case 1:put(p+28,0x3F800000,4);put(p+34,128,2);put(p+36,144,4);break;
        case 2:p[8]=128;break;
        case 3:put(p+8,2,2);break;
        case 5:case 22:put(p+8,1,2);put(p+10,2,2);break;
        case 6:put(p+8,128,4);break;
        case 7:put(p+10,2,2);break;
        case 8:put(p+8,0x42C80000,4);put(p+28,128,4);break;
        case 10:put(p+8,7,2);put(p+12,0x3F800000,4);put(p+16,0x40000000,4);put(p+20,0x40400000,4);break;
        case 12:put(p+8,2,2);put(p+10,7,2);put(p+12,128,4);put(p+16,144,4);break;
        case 13:for(int j=0;j<3;++j){put(p+8+j*2,0xFFFF,2);put(p+14+j*2,1,2);}put(p+20,128,2);break;
        case 14:put(p+14,2,2);put(p+16,128,2);put(p+18,0xFFFF,2);break;
        case 15:put(p+8,128,2);p[10]=1;p[11]=2;p[12]=1;break;
        case 16:put(p+8,1,4);break;
        case 17:put(p+8,2,2);put(p+12,2,2);put(p+14,1,2);break;
        case 18:case 24:put(p+8,1,2);put(p+10,2,2);put(p+20,1,2);put(p+22,1,2);put(p+32,1,2);put(p+34,1,2);put(p+46,1,2);break;
        case 21:put(p+8,2,2);put(p+14,2,2);put(p+16,1,2);put(p+18,2,2);break;
        case 23:put(p+10,2,2);put(p+12,2,2);put(p+14,1,2);break;
    }
}
static NativeGeometryContext setup(unsigned mode) {
    native_graphics_reset(&memory);CHECK(native_graphics_register(&memory,matrices,sizeof(matrices)));
    CHECK(native_graphics_register(&memory,display->commands,8*sizeof(Gfx)));CHECK(native_graphics_register(&memory,modes,sizeof(modes)));
    func_800DE318();func_800DF4B0(mode);func_800DF4A4(display);func_800DF72C(bones);func_800DF818(vertices);func_800DF720(colors);func_800DF824(normals);
    func_800DF738(&attachments);func_800DF83C(marks);func_800DF7C4(7,3);
    native_render.data.scale=1;native_render.data.position=position;native_render.data.zones=zones;
    rare_memset(camera,0,sizeof(camera));camera[2]=10;
    for(int i=0;i<4;++i)camera[12+i*4]=-100000;
    rare_memset(position,0,sizeof(position));rare_memset(&attachments,0,sizeof(attachments));zones[0]=1;zones[14]=1;marks[0]=1;marks[1]=0;
    for(int i=0;i<16;++i) {
        for(int c=0;c<4;++c){colors[i].color[c]=255;vertices->vertices[i].v.cn[c]=255;normals[i*4+c]=c ? 0 : 127;}
        vertices->vertices[i].v.tc[0]=vertices->vertices[i].v.tc[1]=-77;
    }
    mlMtxIdent();mlMtx_push_duplicate();func_8010EF70(&native_render.data,0,0,camera);func_8010E2C4(&native_render.data,0,lights,0);
    NativeGeometryContext context={.gfx=packets,.gfx_end=packets+8192,.mtx=matrices,.mtx_end=matrices+2048,.memory=&memory,.camera=camera,
        .mode_list=modes,.mode_count=16,.vertex_callback=func_8010E4C4,.remaining_commands=1000000};mlMtxGet(&context.base);return context;
}
static int packet_id(Gfx *packet) {
    if(packet->words.w0==0xDA380002){CHECK(native_graphics_resolve(&memory,packet->words.w1,sizeof(Mtx)));return -1;}
    if(packet->words.w0==0xD8380002){CHECK(packet->words.w1==64);return -2;}
    CHECK(packet->words.w0==0xDE000000);const Gfx *list=native_graphics_resolve(&memory,packet->words.w1,sizeof(Gfx));CHECK(list);
    for(int i=0;i<8;++i)if(list==display->commands+i)return i;
    CHECK(list==modes+13 || list==modes);return list==modes+13 ? 13 : 0;
}
static void expect(NativeGeometryContext *context,const int *values,unsigned count) {
    CHECK(context->gfx-packets==count);
    for(unsigned i=0;i<count;++i)CHECK(packet_id(packets+i)==values[i]);
}
static void test_opcodes(void) {
    static const int orders[25][6]={{-1,1,-2,3},{1,2,3},{-1,1,-2,3},{2,3},{3},{1,-1,2,3},{1,3},{2,3},{1,3},{3},{3},{3},{1,2,3},{1,3},{1,3},{1,3},{13,3},{2,3},{1,-1,2,3},{3},{3},{3},{1,-1,2,-1,3},{3},{1,-1,2,-1,3}};
    static const u8 counts[]={4,3,4,2,1,4,2,2,2,1,1,1,3,2,2,2,2,2,4,1,1,1,5,1,5};
    u64 storage[32];u8 *p=(void *)storage;
    for(unsigned mode=0;mode<3;++mode)for(unsigned op=0;op<25;++op) {
        NativeGeometryContext context=setup(mode);fixture(p,op);CHECK(native_geometry_decode(p,172,8,2));
        MtxF *before=mlMtx_get_stack_pointer();CHECK(native_geometry_execute(&context,p,172));CHECK(before==mlMtx_get_stack_pointer());
        if((mode && (op==2 || op==5 || op>=18)) || (mode==2 && op==15)){int tail[]={3};expect(&context,tail,1);}
        else expect(&context,orders[op],counts[op]);
        if(op==10)CHECK(attachments.vectors[7][0]==(mode ? 1 : 6) && attachments.vectors[7][1]==2 && attachments.vectors[7][2]==3);
        if(op==15)CHECK(marks[1]==(mode!=2));
        if(op==2 && !mode) {f32 matrix[4][4];guMtxL2F(matrix,matrices);CHECK(matrix[3][0]==5 && matrix[3][1]==0 && matrix[3][3]==1);}
        if(op==17 || (!mode && (op==18 || op==21 || op==23 || op==24))) {
            CHECK(vertices->vertices[0].v.cn[0]==127 && vertices->vertices[0].v.cn[1]==63 && vertices->vertices[0].v.cn[2]==31);
            if(op!=21)CHECK(vertices->vertices[0].v.tc[0]==1984 && vertices->vertices[0].v.tc[1]==992);
        }
    }
}
static void test_branches(void) {
    u64 storage[32];u8 *p=(void *)storage;int tail[]={3},front[]={2,3},back[]={1,3},reverse[]={2,1,3};
    NativeGeometryContext context=setup(0);fixture(p,1);p[33]=1;CHECK(native_geometry_decode(p,172,8,2));
    CHECK(native_geometry_execute(&context,p,172));expect(&context,front,2);
    context=setup(0);camera[2]=-10;CHECK(native_geometry_execute(&context,p,172));expect(&context,back,2);
    context=setup(0);camera[2]=-10;p[33]=0;CHECK(native_geometry_execute(&context,p,172));expect(&context,reverse,3);
    context=setup(0);fixture(p,12);CHECK(native_geometry_decode(p,172,8,2));func_800DF744(7,2);
    CHECK(native_geometry_execute(&context,p,172));expect(&context,front,2);
    context=setup(0);func_800DF744(7,0);CHECK(native_geometry_execute(&context,p,172));expect(&context,tail,1);
    context=setup(0);fixture(p,8);CHECK(native_geometry_decode(p,172,8,2));camera[2]=100;
    CHECK(native_geometry_execute(&context,p,172));expect(&context,back,2);
    context=setup(0);camera[2]=101;CHECK(native_geometry_execute(&context,p,172));expect(&context,tail,1);
    context=setup(0);camera[2]=0;CHECK(native_geometry_execute(&context,p,172));expect(&context,tail,1);
    context=setup(0);native_render.unknown_short[0]=2;CHECK(native_geometry_execute(&context,p,172));expect(&context,tail,1);
    context.gfx=packets;CHECK(native_geometry_execute(&context,p,172));expect(&context,back,2);
    for(int op=13;op<=14;++op) {
        context=setup(0);fixture(p,op);CHECK(native_geometry_decode(p,172,8,2));camera[9]=1;camera[12]=10;camera[0]=-10;
        CHECK(native_geometry_execute(&context,p,172));expect(&context,tail,1);
        MtxF reflection={.m={{1,0,0,0},{0,1,0,0},{0,0,1,0},{-30,0,0,1}}};context.reflection=&reflection;context.gfx=packets;
        CHECK(native_geometry_execute(&context,p,172));expect(&context,back,2);
    }
    context=setup(0);fixture(p,15);CHECK(native_geometry_decode(p,172,8,2));zones[14]=0;
    CHECK(native_geometry_execute(&context,p,172));expect(&context,tail,1);CHECK(!marks[1]);
    p[11]=1;context.gfx=packets;CHECK(native_geometry_execute(&context,p,172));expect(&context,back,2);CHECK(marks[1]);
    context=setup(2);fixture(p,10);CHECK(native_geometry_decode(p,172,8,2));position[0]=100;
    CHECK(native_geometry_execute(&context,p,172));CHECK(attachments.vectors[7][0]==101);
}
static void test_limits(void) {
    u64 storage[32];u8 *p=(void *)storage;NativeGeometryContext context=setup(0);
    fixture(p,0);CHECK(native_geometry_decode(p,172,8,2));MtxF *before=mlMtx_get_stack_pointer();
    context.gfx_end=context.gfx;CHECK(!native_geometry_execute(&context,p,172));CHECK(mlMtx_get_stack_pointer()==before);
    context=setup(0);context.mtx_end=context.mtx;CHECK(!native_geometry_execute(&context,p,172));CHECK(mlMtx_get_stack_pointer()==before);
    context=setup(0);context.remaining_commands=1;CHECK(!native_geometry_execute(&context,p,172));CHECK(mlMtx_get_stack_pointer()==before);
    context=setup(0);native_graphics_reset(&memory);CHECK(!native_geometry_execute(&context,p,172));CHECK(mlMtx_get_stack_pointer()==before);
    context=setup(0);CHECK(!native_geometry_execute(&context,p,7));CHECK(!native_geometry_execute(&context,p+1,171));
    *(u32 *)p=25;CHECK(!native_geometry_execute(&context,p,172));
    fixture(p,17);CHECK(native_geometry_decode(p,172,8,2));*(s16 *)(p+12)=17;CHECK(!native_geometry_execute(&context,p,172));
    *(s16 *)(p+12)=2;func_8010F270();CHECK(!native_geometry_execute(&context,p,172));
    context=setup(0);fixture(p,6);CHECK(native_geometry_decode(p,172,8,2));*(u32 *)(p+8)=4;CHECK(!native_geometry_execute(&context,p,172));
    context=setup(0);fixture(p,0);CHECK(native_geometry_decode(p,172,8,2));context.gfx_end=packets+1;
    packets[1].words.w0=0xABCDEF12;CHECK(!native_geometry_execute(&context,p,172));CHECK(packets[1].words.w0==0xABCDEF12 && mlMtx_get_stack_pointer()==before);
    context=setup(0);fixture(p,0);put(p+128,2,4);p[136]=16;p[137]=0;CHECK(native_geometry_decode(p,172,8,2));
    context.mtx_end=matrices+1;matrices[1].m[0][0]=0x12345678;
    CHECK(!native_geometry_execute(&context,p,172));CHECK(matrices[1].m[0][0]==0x12345678 && mlMtx_get_stack_pointer()==before);
    u32 deep[31*3+3]={0};
    for(int i=0;i<31;++i){deep[i*3]=2;((u8 *)(deep+i*3))[8]=12;}
    deep[31*3]=3;context=setup(0);CHECK(!native_geometry_execute(&context,(u8 *)deep,sizeof(deep)));CHECK(mlMtx_get_stack_pointer()==before);
}
static void test_matrix_and_projection(void) {
    NativeGeometryContext context=setup(0);MtxF *before=mlMtx_get_stack_pointer();
    MtxF parent={.m={{2,0,0,9},{0,3,0,8},{0,0,4,7},{10,20,30,6}}};
    MtxF local={.m={{0,1,0,9},{-1,0,0,8},{0,0,1,7},{5,6,7,6}}};
    MtxF expected={.m={{0,3,0,0},{-2,0,0,0},{0,0,4,0},{20,38,58,1}}};
    func_80019AA0(&parent,&local);MtxF *product=mlMtx_get_stack_pointer();CHECK(product==before+1);
    for(int r=0;r<4;++r)for(int c=0;c<4;++c)CHECK(product->m[r][c]==expected.m[r][c]);mlMtxPop();
    MtxF rotation={.m={{0,1,0,0},{-1,0,0,0},{0,0,1,0},{0,0,0,1}}};s32 first=0;
    CHECK(native_texture_projection_apply(&native_render.data,&rotation.m[0][0],&first,1));
    CHECK(first==1 && vertices->vertices[0].v.tc[0]==992 && vertices->vertices[0].v.tc[1]==1984);
    first=16;CHECK(!native_texture_projection_apply(&native_render.data,&rotation.m[0][0],&first,1) && first==16);
    NativeRenderData other=native_render.data;first=0;CHECK(!native_texture_projection_apply(&other,&rotation.m[0][0],&first,1));
    context=setup(0);normals[0]=-128;first=0;CHECK(native_texture_projection_apply(&native_render.data,&context.base.m[0][0],&first,1));
    CHECK(vertices->vertices[0].v.tc[0]==-7 && vertices->vertices[0].v.tc[1]==992);
    for(int i=0;i<3;++i)camera[i]=position[i];func_8010EF70(&native_render.data,0,0,camera);first=0;
    CHECK(native_texture_projection_apply(&native_render.data,&context.base.m[0][0],&first,1));CHECK(vertices->vertices[0].v.tc[0]==992 && vertices->vertices[0].v.tc[1]==992);
    CHECK(!native_model_modes(0));CHECK(native_model_modes(0x182)==native_model_modes(2) && native_model_modes(0x180)==native_model_modes(0x80));
    const s16 flags[]={2,0x80,0x100};
    for(unsigned i=0;i<3;++i) {
        Gfx *list=native_model_modes(flags[i]);CHECK(list && list[0].words.w0>>24==G_SETTILE && list[12].words.w0==0xDF000000 && list[23].words.w0==0xDF000000);
    }
}
static void test_callback_modes(void) {
    u64 storage[32];
    u8 *commands=(u8 *)storage;
    for(int mode=0;mode<5;++mode) {
        NativeGeometryContext context=setup(0);
        context.vertex_callback=NULL;
        fixture(commands,17);
        commands[14]=0;
        CHECK(native_geometry_decode(commands,172,8,2));
        func_800DF660(mode,1,mode==1 ? (uintptr_t)lights : 0,255);
        CHECK(native_geometry_execute(&context,commands,172));
        CHECK(!context.vertex_callback);
        if(mode==0)CHECK(vertices->vertices[0].v.tc[0]!=-77 || vertices->vertices[0].v.tc[1]!=-77);
        if(mode==1)CHECK(vertices->vertices[0].v.cn[0]==127 && vertices->vertices[0].v.cn[1]==63);
        func_800DF660(0,0,0,255);
    }
}
static void initialize(void) {
    func_800DF38C();display=heap_alloc(sizeof(*display)+8*sizeof(Gfx));display->header[0]=8;
    vertices=heap_alloc(sizeof(*vertices)+16*sizeof(Vtx));vertices->count_flags=32;
    NativeSkeleton *s=heap_alloc(sizeof(*s)+2*sizeof(NativeBone));s->count=2;
    bones=func_800ADF98();func_800ADCD0(&bones,s);bones->matrices[0].m[3][0]=5;bones->matrices[1].m[3][1]=6;heap_free(s);
    lights=func_800B3310(0);s32 ambient[3]={128,64,32};func_800B38A8(lights,ambient);
}
static void test_archive(const char *path) {
    CHECK(native_assets_open(path));unsigned models=0,draws=0,commands=0,matrix_count=0;
    for(int id=0;id<native_asset_count();++id) {
        if((native_asset_flags(id)&15)!=0 || native_asset_packed_size(id)<=0)continue;
        u8 *model=(void *)func_800D674C(id);CHECK(model);
        NativeSkeleton *s=(NativeSkeleton *)func_800B27E0(model);if(s)func_800ADCD0(&bones,s);
        NativeVertexList *v=func_800B2840(model);NativeDisplayList *list=func_800B2714(model);
        u32 count=func_800B2344(v),offset=*(u32 *)(model+4),size=native_asset_cached_size(id);
        NativeCamera model_camera;func_800CA440(&model_camera);
        f32 distance=fmaxf(100,3*func_800B2354(v));func_800CA5F8(&model_camera,v->center[0],v->center[1],v->center[2]+distance);func_800CAF34(&model_camera);
        CHECK(offset && offset<size);NativeVertexLight *model_colors=heap_alloc(count*sizeof(*model_colors));
        u8 *model_zones=*(u32 *)(model+32) ? model+*(u32 *)(model+32) : NULL;
        u8 *zone_marks=model_zones ? heap_alloc(*model_zones+1) : NULL;
        if(zone_marks){rare_memset(zone_marks,0,*model_zones+1);*zone_marks=*model_zones;}
        for(unsigned mode=0;mode<3;++mode) {
            NativeGeometryContext context=setup(mode);context.camera=model_camera.values;native_render.data.display_list=list;native_render.data.vertices=v;
            native_render.data.animation=s ? bones : NULL;native_render.data.normals=*(u32 *)(model+56) ? (s8 *)(model+*(u32 *)(model+56)) : NULL;
            native_render.data.animated_vertices=*(u32 *)(model+40) ? model+*(u32 *)(model+40) : NULL;
            native_render.data.colors=model_colors;native_render.data.zones=model_zones;native_render.zone_override=zone_marks;native_render.attachments=NULL;
            for(u32 i=0;i<count;++i)for(int c=0;c<4;++c)model_colors[i].color[c]=v->vertices[i].v.cn[c];
            native_graphics_reset(&memory);CHECK(native_graphics_register(&memory,matrices,sizeof(matrices)));
            if(list->header[0])CHECK(native_graphics_register(&memory,list->commands,list->header[0]*sizeof(Gfx)));
            context.mode_list=native_model_modes(func_800B270C((s16 *)model));context.mode_count=24;
            if(context.mode_list)CHECK(native_graphics_register(&memory,context.mode_list,24*sizeof(Gfx)));
            func_800E42B4(&model_camera);
            NativeGraphicsContext frame={context.gfx,context.mtx,context.gfx_end,context.mtx_end,&memory};
            CHECK(func_800E44FC(&frame));context.gfx=frame.gfx;context.mtx=frame.mtx;
            if(model_zones)dbzone_entrypoint_1(model_zones,context.camera,1,position);
            for(int i=1;i<60;++i)func_800DF744(i,-2147483647);
            func_8010EF70(&native_render.data,0,0,context.camera);func_8010E2C4(&native_render.data,0,lights,0);
            MtxF *before=mlMtx_get_stack_pointer();
            if(!native_geometry_execute(&context,model+offset,size-offset)) {
                fprintf(stderr,"model %d mode %u geometry execution failed after %u commands, %td packets, %td matrices\n",id,mode,1000000-context.remaining_commands,context.gfx-packets,context.mtx-matrices);exit(1);
            }
            CHECK(mlMtx_get_stack_pointer()==before);
            for(Gfx *p=packets;p<context.gfx;++p) {
                if(p->words.w0==0xDA380002 || p->words.w0==0xDA380003 || p->words.w0==0xDA380007)CHECK(native_graphics_resolve(&memory,p->words.w1,sizeof(Mtx)));
                else if(p->words.w0==0xDE000000)CHECK(native_graphics_resolve(&memory,p->words.w1,sizeof(Gfx)));
                else if(p==packets)CHECK(p->words.w0==0xDB0E0000 && p->words.w1>0 && p->words.w1<=0xFFFF);
                else CHECK(p->words.w0==0xD8380002 && p->words.w1==64);
            }
            ++draws;commands+=context.gfx-packets;matrix_count+=context.mtx-matrices;
        }
        ++models;func_8010F270();func_8010E7F4();func_800E4628();func_800E42B4(NULL);native_graphics_reset(&memory);heap_free(model_colors);heap_free(zone_marks);
        func_800D62E4(id);func_800D6CEC(id);func_800D5E74();func_800D5E74();
    }
    native_assets_shutdown();CHECK(models && commands);
    printf("Executed %u original models in %u mode passes: %u graphics packets and %u matrices.\n",models,draws,commands,matrix_count);
}
int main(int argc,char **argv) {
    initialize();test_opcodes();test_branches();test_limits();test_matrix_and_projection();test_callback_modes();if(argc==2)test_archive(argv[1]);else CHECK(argc==1);func_8010F270();func_8010E7F4();
    native_graphics_dispose(&memory);func_800B3370(lights);func_800ADF5C(bones);heap_free(vertices);heap_free(display);func_800DF35C();
    puts("native geometry dispatch, transforms, culling, zones, lighting and packet order passed");return 0;
}
