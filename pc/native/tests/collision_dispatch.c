#include "native_collision.h"
#include <stdio.h>
#include <stdlib.h>
#define CHECK(x) do {if(!(x)){fprintf(stderr,"%s:%d: %s\n",__FILE__,__LINE__,#x);exit(1);}}while(0)
static void *hits[2],*models[2];
static int enabled[2],calls,order[16],model_calls;
static void *query(int id,f32 *end,f32 *normal) {
    CHECK(calls<16);order[calls++]=id;
    if(!enabled[id])return NULL;
    end[1]=10+id;normal[0]=id;normal[1]=1;normal[2]=0;return hits[id];
}
static void *line0(f32 *a,f32 *b,f32 *out,u32 flags) {CHECK(a && flags==0x123);return query(0,b,out);}
static void *line1(f32 *a,f32 *b,f32 *out,u32 flags) {CHECK(a && flags==0x123);return query(1,b,out);}
static void *sweep0(f32 *a,f32 *b,f32 radius,f32 *out,s32 flags,u32 mode) {CHECK(a && radius==7 && flags==0x123 && mode==4);return query(0,b,out);}
static void *sweep1(f32 *a,f32 *b,f32 radius,f32 *out,s32 flags,u32 mode) {CHECK(a && radius==7 && flags==0x123 && mode==4);return query(1,b,out);}
static void *sphere0(f32 *a,f32 radius,f32 *out,u32 flags) {CHECK(radius==7 && flags==0x123);return query(0,a,out);}
static void *sphere1(f32 *a,f32 radius,f32 *out,u32 flags) {CHECK(radius==7 && flags==0x123);return query(1,a,out);}
static void *model0(void) {++model_calls;return models[0];}
static void *model1(void) {++model_calls;return models[1];}
int main(void) {
    f32 a[3]={0},b[3]={1,2,3},normal[3]={0},height=999;
    for(int i=0;i<2;++i){hits[i]=malloc(1);models[i]=malloc(1);CHECK(hits[i] && models[i]);}
    CHECK(!func_800C6A7C(a,b,normal,0x123) && !func_800C69FC());
    CHECK(!func_800C696C(a,100,-100,0x123,&height) && height==999 && func_800C6920(a,100,-100,0x123)==100);
    CHECK(func_800C6A28(line0,sweep0,sphere0,model0));CHECK(func_800C6A28(line1,sweep1,sphere1,model1));
    for(int first=0;first<2;++first)for(int second=0;second<2;++second) {
        enabled[0]=first;enabled[1]=second;
        for(int kind=0;kind<3;++kind) {
            calls=model_calls=0;
            void *hit=kind==0 ? func_800C6A7C(a,b,normal,0x123) : kind==1 ? func_800C6B78(a,b,7,normal,0x123,4) : func_800C6C94(a,7,normal,0x123);
            int last=second ? 1 : first ? 0 : -1;
            CHECK(calls==2 && order[0]==0 && order[1]==1 && model_calls==first+second);
            CHECK(hit==(last<0 ? NULL : hits[last]) && func_800C69FC()==(last<0 ? NULL : models[last]));
            if(last>=0)CHECK(normal[0]==last && normal[1]==1);
        }
    }
    calls=0;CHECK(func_800C696C(a,100,-100,0x123,&height) && height==11);calls=0;CHECK(func_800C6920(a,100,-100,0x123)==11);
    func_800C6A68();CHECK(!func_800C69FC());
    CHECK(func_800C6A28(line0,NULL,NULL,model0));CHECK(func_800C6A08(line1,NULL,NULL));
    calls=0;CHECK(func_800C6A7C(a,b,normal,0x123)==hits[1] && !func_800C69FC());
    CHECK(!func_800C6B78(a,b,7,normal,0x123,4) && !func_800C6C94(a,7,normal,0x123));
    func_800C6A68();for(int i=0;i<8;++i)CHECK(func_800C6A08(line0,NULL,NULL));
    CHECK(!func_800C6A28(line1,sweep1,sphere1,model1));calls=0;CHECK(func_800C6A7C(a,b,normal,0x123)==hits[0] && calls==8);
    func_800C6A68();calls=0;CHECK(!func_800C6A7C(a,b,normal,0x123) && !calls && !func_800C69FC());
    CHECK(func_800C6A28(NULL,NULL,NULL,model0));CHECK(!func_800C6A7C(a,b,normal,0x123));func_800C6A60();func_800C6A68();
    for(int i=0;i<2;++i){free(hits[i]);free(models[i]);}
    puts("Native collision dispatcher: line/sweep/sphere routing, hit ownership, capacity and reset passed.");return 0;
}
