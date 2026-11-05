#include "native_lights.h"
#include "memory.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define CHECK(x) do {if(!(x)){fprintf(stderr,"%s:%d: %s\n",__FILE__,__LINE__,#x);exit(1);}}while(0)
s32 func_8001211C(void){return 100;}
static NativeLight *light(s32 id){return vector_at(native_lighting.entries,id-1);}
static u32 observed(NativeLight *entry,s32 mask){CHECK(entry==light(1) && mask==77);return 1;}
static void test_lifecycle(void) {
    func_800C90D0();func_800C90AC();CHECK(func_800C911C()==&native_lighting && !func_800C8BF4());
    s32 values[3];f32 output[3],zero[3]={0};func_800C87B8(values);CHECK(!values[0]&&!values[1]&&!values[2]);
    func_800C87DC(values);CHECK(values[0]==255 && values[1]==255 && values[2]==255);
    func_800C8960(values,output);CHECK(values[0]==255 && output[0]==0 && output[1]==1 && output[2]==0);
    CHECK(!func_800C9128(zero));
    CHECK(func_800C8A98()==1 && func_800C8A98()==2 && func_800C8BF4()==2);
    CHECK(light(1)->range[0]==150 && light(1)->range[1]==3000 && fabsf(light(1)->inverse_range-1.0f/2850)<1e-7f);
    CHECK(func_800C89A8(1)==11 && func_800C9044(1)==1 && !func_800C8C18());
    CHECK(func_800C85A0(observed,77)==1 && func_800C8760(0,1)==1 && func_800C878C(1,0,1)==2);
    CHECK(!func_800C878C(2,0,1) && !func_800C8760(1,1) && !func_800C8760(3,1));
    CHECK(func_800C8760(2,1)==1);func_800C8A08();CHECK(!func_800C8760(2,1));
    f32 position[3]={-2.75f,13.5f,100};func_800C8CB8(1,position);func_800C8800(1,output);
    CHECK(output[0]==-2 && output[1]==13 && output[2]==100 && func_800C89D8(1));
    func_800C8A08();func_800C8CB8(1,position);CHECK(!func_800C89D8(1));
    func_800C8E54(1,200,100);func_800C8898(1,output);CHECK(output[0]==200 && output[1]==201 && output[2]==1);
    func_800C8E54(1,100,100);func_800C883C(1,output);CHECK(output[0]==100 && output[1]==101);
    func_800C8FB0(1,256,42,0xFFFFFFFF);func_800C8900(1,values);CHECK(values[0]==0 && values[1]==42 && values[2]==255);
    func_800C8A08();func_800C8FE0(1,0);CHECK(!func_800C9044(1) && light(1)->disabled && light(1)->dirty);
    func_800C8900(1,values);CHECK(!values[0]&&!values[1]&&!values[2]);CHECK(func_800C8760(2,1)==1);
    func_800C8A08();CHECK(func_800C8760(0,1)==2);func_800C8FE0(1,1);CHECK(light(1)->dirty);
    func_800C8F64(1,4);CHECK(func_800C89A8(1)==4);
    func_800C8B84(1);CHECK(light(1)->dirty==2 && light(1)->position[1]==-16000);
    func_800C8A08();CHECK(!func_800C89A8(1) && func_800C8A98()==1);
    CHECK(gclightsDll_entrypoint_4()==1 && light(1)->permanent && !light(2)->mask);
    CHECK(gclightsDll_entrypoint_4()==2 && func_800C8C18()==2);
    f32 far[3]={1000,0,0};func_800C8CB8(1,far);func_800C8CB8(2,zero);
    CHECK(func_800C9128(zero)==2);func_800C8FE0(2,0);CHECK(func_800C9128(zero)==1);
    func_800C9074();CHECK(func_800C9128(zero)==1);
    const int expected[]={0,1,10,9,6,5,3,7,8,2,11,16,17,18,20,21,24,25};
    for(int i=0;i<18;++i)CHECK(func_800C84B0(i<<8)==expected[i]);
    CHECK(func_800C84B0(0x1F00)==1 && func_800C84B0(0x20100)==4);
    CHECK(!func_800C89A8(0) && !func_800C89D8(99) && !func_800C9044(-1));
    func_800C90D0();func_800C90D0();CHECK(!native_lighting.entries && !func_800C8BF4());
}
static void write_light(GsFile *w,f32 *position,int flag) {
    f32 range[2]={100,1000};s32 rgb[3]={10,20,30};u8 mask=9;
    CHECK(gsmaker_entrypoint_16(w,1) && gsmaker_entrypoint_20(w,2,position,3) && gsmaker_entrypoint_20(w,3,range,2) && gsmaker_entrypoint_22(w,4,rgb,3));
    if(flag)CHECK(gsmaker_entrypoint_17(w,7,&mask));
}
static void test_stream(void) {
    GsFile *w=gsmaker_entrypoint_5(),*r;void *buffer;s32 size,color[3]={20,30,40};f32 position[3]={100,200,300},direction[3]={3,0,4};
    CHECK(gsmaker_entrypoint_16(w,5) && gsmaker_entrypoint_22(w,4,color,3));
    color[0]=50;color[1]=60;color[2]=70;CHECK(gsmaker_entrypoint_16(w,6)&&gsmaker_entrypoint_22(w,4,color,3));
    color[0]=80;color[1]=90;color[2]=100;CHECK(gsmaker_entrypoint_16(w,9)&&gsmaker_entrypoint_20(w,2,direction,3)&&gsmaker_entrypoint_22(w,4,color,3));
    write_light(w,position,1);CHECK(gsmaker_entrypoint_16(w,8));position[0]=-200;write_light(w,position,0);
    CHECK(gsmaker_entrypoint_16(w,10)&&gsmaker_entrypoint_22(w,4,color,3)&&gsmaker_entrypoint_16(w,0));
    gsmaker_entrypoint_6(w,&buffer,&size);r=gsmaker_entrypoint_4(buffer,size);func_800C90F4(r);
    CHECK(!r->failed && r->current_ptr==r->end_ptr && func_800C8BF4()==3 && func_800C8C18()==3);
    CHECK(native_lighting.ambient[0]==20 && native_lighting.primary_color[1]==60 && native_lighting.secondary_color[2]==100);
    CHECK(fabsf(native_lighting.secondary_direction[0]-0.6f)<1e-6f && fabsf(native_lighting.secondary_direction[2]-0.8f)<1e-6f);
    CHECK(light(1)->mask==9 && light(3)->mask==13 && light(2)->dirty==2);
    func_800C8A08();CHECK(func_800C8C18()==2 && !light(2)->mask);gsmaker_entrypoint_0(r);func_800C90D0();
    for(int length=0;length<size;++length){r=gsmaker_entrypoint_4(buffer,length);func_800C90F4(r);CHECK(r->failed && !native_lighting.entries);gsmaker_entrypoint_0(r);}
    heap_free(buffer);
    u8 bad[][4]={{99},{1,0},{5,0},{6,0},{9,0}};
    for(int i=0;i<5;++i){r=gsmaker_entrypoint_4(bad[i],4);func_800C90F4(r);CHECK(r->failed && !native_lighting.entries);gsmaker_entrypoint_0(r);}
    w=gsmaker_entrypoint_5();position[0]=NAN;write_light(w,position,0);CHECK(gsmaker_entrypoint_16(w,0));gsmaker_entrypoint_6(w,&buffer,&size);
    r=gsmaker_entrypoint_4(buffer,size);func_800C90F4(r);CHECK(r->failed && !native_lighting.entries);gsmaker_entrypoint_0(r);heap_free(buffer);
    u8 empty[]={10,0};r=gsmaker_entrypoint_4(empty,2);func_800C90F4(r);CHECK(!r->failed && !func_800C8BF4());gsmaker_entrypoint_0(r);func_800C90D0();
}
int main(void){test_lifecycle();test_stream();puts("Native lighting: shared game C, stream parsing, queries, dirty flags and lifetime passed.");return 0;}
