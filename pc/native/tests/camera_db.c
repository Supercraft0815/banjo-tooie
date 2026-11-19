#include "native_camera_db.h"
#include "native_assets.h"
#include "memory.h"
#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#define CHECK(x) do { if (!(x)) { fprintf(stderr,"%s:%d: %s\n",__FILE__,__LINE__,#x);exit(1); } } while(0)

/* Initial camera pose and external player callbacks are controlled boundaries. */
void func_800E3980(f32 *v) {v[0]=10;v[1]=20;v[2]=30;}
void func_800E3A58(f32 *v) {v[0]=40;v[1]=50;v[2]=60;}
s32 func_8001211C(void) {return 100;}
static s16 slot;
static PlayerState player;
static void *event_token,*data_token;
static int routed;
s16 *func_800A93E4(s32 index) {CHECK(index==123);return &slot;}
PlayerState *func_80110014(s16 *entry) {CHECK(entry==&slot);return &player;}
void _ncbaspline_entrypoint_5(PlayerState *p,void *event,void *data) {CHECK(p==&player && event==event_token && data==data_token);routed|=1;}
void _ncbaspline_entrypoint_6(PlayerState *p,void *event,void *data) {CHECK(p==&player && event==event_token && data==data_token);routed|=2;}

static void equal(const void *a,const void *b,int size) {
    const u8 *x=a,*y=b;for(int i=0;i<size;++i)CHECK(x[i]==y[i]);
}
static const int sizes[]={0,44,24,52,24,44,52,4,48};
static const int vector_offsets[3][9]={
    {-1,0,0,0,-1,0,0,-1,0}, {-1,-1,12,-1,-1,12,12,-1,12}, {-1,28,-1,36,-1,-1,-1,-1,-1}};
static const int pair_offsets[2][9]={{-1,12,-1,12,-1,-1,-1,-1,-1},{-1,20,-1,20,-1,-1,-1,-1,-1}};
static const int float_offsets[6][9]={
    {-1,-1,-1,-1,-1,24,28,-1,-1},{-1,-1,-1,-1,-1,28,32,-1,28},
    {-1,-1,-1,-1,-1,32,36,-1,32},{-1,-1,-1,28,-1,-1,24,-1,-1},
    {-1,-1,-1,32,-1,-1,-1,-1,-1},{-1,-1,-1,-1,16,-1,-1,-1,-1}};
static const int int_offsets[5][9]={
    {-1,-1,-1,-1,0,-1,-1,-1,-1},{-1,-1,-1,-1,8,-1,44,0,40},
    {-1,-1,-1,-1,12,-1,-1,-1,-1},{-1,40,-1,48,4,36,40,-1,36},
    {-1,-1,-1,-1,20,-1,-1,-1,-1}};
static const int half_offsets[]={-1,-1,-1,-1,-1,40,48,-1,44};

static void check_defaults(int type,const u8 *record) {
    u8 expected[52]={0};
    f32 position[]={10,20,30},rotation[]={40,50,60};
    f32 pairs[2][2]={{1.75f,3.75f},{2.75f,12.0f}};
    f32 scalars[]={150,40,1,1000,1000,0};
    if(type==1 || type==2 || type==3 || type==5) rare_memcpy(expected,position,12);
    if(type==2 || type==5) rare_memcpy(expected+12,rotation,12);
    if(type==1 || type==3) rare_memcpy(expected+vector_offsets[2][type],rotation,12);
    for(int field=0;field<2;++field)
        if(pair_offsets[field][type]>=0)rare_memcpy(expected+pair_offsets[field][type],pairs[field],8);
    for(int field=0;field<6;++field)
        if(float_offsets[field][type]>=0)rare_memcpy(expected+float_offsets[field][type],scalars+field,4);
    if(half_offsets[type]>=0){s16 value=-1;rare_memcpy(expected+half_offsets[type],&value,2);}
    if(type==1){s32 flags=2;rare_memcpy(expected+40,&flags,4);}
    if(type==4){s32 value=10;rare_memcpy(expected,&value,4);}
    if(type==7){s32 value=1;rare_memcpy(expected,&value,4);}
    equal(record,expected,sizes[type]);
}

static void test_fields(void) {
    s32 (*vector_get[])(f32 *)={cadbfunc_entrypoint_0,cadbfunc_entrypoint_2,cadbfunc_entrypoint_4};
    s32 (*vector_set[])(f32 *)={cadbfunc_entrypoint_1,cadbfunc_entrypoint_3,cadbfunc_entrypoint_5};
    s32 (*pair_get[])(f32 *,f32 *)={cadbfunc_entrypoint_6,cadbfunc_entrypoint_8};
    s32 (*pair_set[])(f32,f32)={cadbfunc_entrypoint_7,cadbfunc_entrypoint_9};
    s32 (*float_get[])(f32 *)={cadbfunc_entrypoint_10,cadbfunc_entrypoint_12,cadbfunc_entrypoint_14,cadbfunc_entrypoint_18,cadbfunc_entrypoint_20,cadbfunc_entrypoint_32};
    s32 (*float_set[])(f32)={cadbfunc_entrypoint_11,cadbfunc_entrypoint_13,cadbfunc_entrypoint_15,cadbfunc_entrypoint_19,cadbfunc_entrypoint_21,cadbfunc_entrypoint_33};
    s32 (*int_get[])(s32 *)={cadbfunc_entrypoint_22,cadbfunc_entrypoint_24,cadbfunc_entrypoint_26,cadbfunc_entrypoint_30,cadbfunc_entrypoint_34};
    s32 (*int_set[])(s32)={cadbfunc_entrypoint_23,cadbfunc_entrypoint_25,cadbfunc_entrypoint_27,cadbfunc_entrypoint_31,cadbfunc_entrypoint_35};
    func_800A55E0();CHECK(func_800A58F0()==126 && func_800A5898()==-1);
    for(int type=1;type<=8;++type) {
        CHECK(func_800A57EC(type)==sizes[type]);func_800A58A8(type,type);
        CHECK(func_800A5854(type)==type && func_800A5904(type) && func_800A587C()==type);
        u8 *record=func_800A586C();CHECK(record==func_800A5790(type,0));
        check_defaults(type,record);
        u8 expected[52];rare_memcpy(expected,record,sizes[type]);
        f32 input[3]={1.25f,-2.5f,3.75f},output[3];
        for(int field=0;field<3;++field) {
            int offset=vector_offsets[field][type],valid=offset>=0;
            output[0]=output[1]=output[2]=99;
            CHECK(vector_set[field](input)==valid && vector_get[field](output)==valid);
            if(valid) {equal(output,input,12);rare_memcpy(expected+offset,input,12);}else CHECK(output[0]==99);
            equal(record,expected,sizes[type]);
        }
        for(int field=0;field<2;++field) {
            int offset=pair_offsets[field][type],valid=offset>=0;output[0]=output[1]=99;
            CHECK(pair_set[field](input[0],input[1])==valid && pair_get[field](output,output+1)==valid);
            if(valid) {equal(output,input,8);rare_memcpy(expected+offset,input,8);}else CHECK(output[0]==99 && output[1]==99);
            equal(record,expected,sizes[type]);
        }
        for(int field=0;field<6;++field) {
            int offset=float_offsets[field][type],valid=offset>=0;output[0]=99;
            CHECK(float_set[field](input[0])==valid && float_get[field](output)==valid);
            if(valid){CHECK(output[0]==input[0]);rare_memcpy(expected+offset,input,4);}else CHECK(output[0]==99);
            equal(record,expected,sizes[type]);
        }
        for(int field=0;field<5;++field) {
            int offset=int_offsets[field][type],valid=offset>=0;s32 value=0x12345678,actual=-77;
            CHECK(int_set[field](value)==valid && int_get[field](&actual)==valid);
            if(valid){CHECK(actual==value);rare_memcpy(expected+offset,&value,4);}else CHECK(actual==-77);
            equal(record,expected,sizes[type]);
        }
        s16 half=-123,actual=99;int offset=half_offsets[type],valid=offset>=0;
        CHECK(cadbfunc_entrypoint_17(half)==valid && cadbfunc_entrypoint_16(&actual)==valid);
        if(valid){CHECK(actual==half);rare_memcpy(expected+offset,&half,2);}else CHECK(actual==99);
        equal(record,expected,sizes[type]);
        s32 flags=0x12345678,boolean=99;valid=int_offsets[3][type]>=0;
        CHECK(cadbfunc_entrypoint_28(0x81,1)==valid && cadbfunc_entrypoint_29(1,&boolean)==valid);
        if(valid){flags|=0x81;CHECK(boolean==1);rare_memcpy(expected+int_offsets[3][type],&flags,4);}else CHECK(boolean==99);
        equal(record,expected,sizes[type]);CHECK(cadbfunc_entrypoint_28(0x80,0)==valid);
        if(valid){CHECK(cadbfunc_entrypoint_29(0x80,&boolean) && !boolean);flags&=~0x80;rare_memcpy(expected+int_offsets[3][type],&flags,4);}
        equal(record,expected,sizes[type]);
    }
    CHECK(!func_800A5800(-1) && !func_800A587C());f32 out=99;
    CHECK(!cadbfunc_entrypoint_0(&out) && out==99 && !cadbfunc_entrypoint_11(7));
    CHECK(!func_800A5790(0,0) && !func_800A5790(9,0) && !func_800A5790(1,1));
    func_800A5654();CHECK(func_800A5898()==-1 && !func_800A586C());
    func_800A56A4();for(int i=1;i<=8;++i)CHECK(!func_800A5854(i));
    func_800A5630();func_800A5630();CHECK(!D_80119540 && !func_800A58F0());
}

static void test_insertion(void) {
    func_800A5608(256);
    for(int id=255;id>=0;--id) {func_800A58A8(id,7);CHECK(func_800A5898()==id);CHECK(cadbfunc_entrypoint_25(id*123));}
    CHECK(D_80119540->counts[6]==256 && !cadbmgrDll_entrypoint_2(D_80119540,7,256));
    for(int id=0;id<256;++id) {s32 value=-1;CHECK(func_800A5800(id) && D_80119540->entries[id].index==id);CHECK(cadbfunc_entrypoint_24(&value) && value==id*123);}
    CHECK(!cadbmgrDll_entrypoint_2(D_80119540,0,256) && !cadbmgrDll_entrypoint_2(D_80119540,9,256));
    CHECK(!cadbmgrDll_entrypoint_2(D_80119540,1,-1) && !cadbmgrDll_entrypoint_2(D_80119540,1,257));
    CHECK(!cadbmgrDll_entrypoint_2(D_80119540,1,0));
    CHECK(cadbmgrDll_entrypoint_2(D_80119540,2,256));
    f32 v[]={9,8,7};CHECK(cadbfunc_entrypoint_1(v));CHECK(cadbmgrDll_entrypoint_2(D_80119540,2,255)==0);
    func_800A5630();func_800A5608(20);
    for(int id=20;id>=0;id-=5) {func_800A58A8(id,2);v[0]=id;CHECK(cadbfunc_entrypoint_1(v));}
    CHECK(func_800A5800(20));CHECK(cadbfunc_entrypoint_0(v) && v[0]==20);
    func_800A5630();func_800A5608(-1);CHECK(!D_80119540);
    func_800A5608(INT32_MAX);CHECK(!D_80119540);
}

static void test_stream(void) {
    GsFile *writer=gsmaker_entrypoint_5();void *bytes;s32 size,maximum=7;
    CHECK(gsmaker_entrypoint_21(writer,20,&maximum));
    for(s32 type=8;type>=1;--type) {
        s32 id=type-1,value=1234;f32 v[3]={4.25f,-5.5f,6.75f};s16 h=-234;
        CHECK(gsmaker_entrypoint_21(writer,1,&id) && gsmaker_entrypoint_21(writer,2,&type));
        for(int tag=3;tag<=19;++tag) {
            if(tag==10) CHECK(gsmaker_entrypoint_24(writer,tag,&h));
            else if((tag>=13 && tag<=16)||tag==19) CHECK(gsmaker_entrypoint_21(writer,tag,&value));
            else CHECK(gsmaker_entrypoint_20(writer,tag,v,tag<=5?3:tag<=7?2:1));
        }
        CHECK(gsmaker_entrypoint_16(writer,0));
    }
    CHECK(gsmaker_entrypoint_16(writer,0));gsmaker_entrypoint_6(writer,&bytes,&size);
    GsFile *reader=gsmaker_entrypoint_4(bytes,size);cadbio_entrypoint_0(reader);
    CHECK(!reader->failed && reader->current_ptr==reader->end_ptr && func_800A58F0()==8);
    for(int i=0;i<8;++i) {
        CHECK(func_800A5800(i) && func_800A587C()==i+1);f32 v[3];
        if(vector_offsets[0][i+1]>=0) CHECK(cadbfunc_entrypoint_0(v) && v[0]==4.25f && v[1]==-5.5f && v[2]==6.75f);
    }
    gsmaker_entrypoint_0(reader);func_800A5630();
    for(int length=0;length<size;++length) {
        reader=gsmaker_entrypoint_4(bytes,length);cadbio_entrypoint_0(reader);
        CHECK(reader->failed && !D_80119540);gsmaker_entrypoint_0(reader);
    }
    heap_free(bytes);
    u8 empty[]={0},bad[][12]={{99},{1,0,0,0,0,2,0,0,0,9},{2,0,0,0,1},{20,0xFF,0xFF,0xFF,0xFF},{1,0,0,0,0,0,0},{3,0,0,0,0}};
    reader=gsmaker_entrypoint_4(empty,1);cadbio_entrypoint_0(reader);CHECK(!reader->failed && func_800A58F0()==126);gsmaker_entrypoint_0(reader);func_800A5630();
    for(int i=0;i<6;++i) {reader=gsmaker_entrypoint_4(bad[i],12);cadbio_entrypoint_0(reader);CHECK(reader->failed && !D_80119540);gsmaker_entrypoint_0(reader);}
}

static void test_archive(const char *path) {
    CHECK(native_assets_open(path));int files=0,nodes=0;
    for(s32 id=0;id<native_asset_count();++id) {
        if((native_asset_flags(id)&15)!=10)continue;
        GsFile *file=gsmaker_entrypoint_1(id);CHECK(file);
        if(file->asset_base_ptr[0]!=6){gsmaker_entrypoint_0(file);continue;}
        CHECK(gsmaker_entrypoint_16(file,6));cadbio_entrypoint_0(file);
        if(file->failed)fprintf(stderr,"Camera asset %x failed at byte %td\n",id,file->asset_current_ptr-file->asset_base_ptr);
        CHECK(!file->failed && D_80119540);
        for(int i=0;i<func_800A58F0();++i)if(func_800A5854(i)){CHECK(func_800A5800(i));++nodes;}
        func_800A5630();gsmaker_entrypoint_0(file);++files;
    }
    CHECK(files>0 && nodes>0);native_assets_shutdown();printf("Loaded %d original camera sections with %d records.\n",files,nodes);
}
int main(int argc,char **argv) {
    test_fields();test_insertion();test_stream();
    Unk80132ED0 marker={0};Prop prop={0};marker.unk18=0xace0001f|(123<<5);data_token=&marker;event_token=&prop;
    func_800A5550(&prop,&marker);func_800A5598(&prop,&marker);CHECK(routed==3);
    CHECK(argc==1 || argc==2);if(argc==2)test_archive(argv[1]);
    puts("Native camera database: eight types, field layouts, insertion, stream bounds and cleanup passed.");return 0;
}
