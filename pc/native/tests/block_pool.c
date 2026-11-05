#include "native_block_pool.h"
#include <stdio.h>
#include <stdlib.h>
#define CHECK(x) do { if (!(x)) { fprintf(stderr,"%s:%d: %s\n",__FILE__,__LINE__,#x); exit(1); } } while(0)
typedef struct { uintptr_t pointer; u32 id, value; } Payload;
static s16 ranges[20][2];
static Payload expected[20][80];
static u32 seed=12345,serial;
static u32 random_word(void) { seed=seed*1664525u+1013904223u;return seed; }
static void validate(u8 *pool) {
    u8 owned[4096]={0};
    s32 total=((s16 *)pool)[1];CHECK(total>0 && total<4096);
    owned[0]=1;
    for(int i=0;i<20;++i) {
        Payload *items=func_800B42A0(pool,ranges[i]);
        CHECK((items==NULL)==(ranges[i][1]==0));
        if(items) CHECK((uintptr_t)items%_Alignof(Payload)==0);
        for(int j=0;j<ranges[i][1];++j) {
            int index=ranges[i][0]+j;
            CHECK(index>0 && index<total && !owned[index]);owned[index]=1;
            CHECK(items[j].pointer==expected[i][j].pointer && items[j].id==expected[i][j].id && items[j].value==expected[i][j].value);
        }
    }
    s16 *free=func_800B39D0(pool,0);
    for(int steps=0;*free;++steps) {
        CHECK(steps<total && *free>0 && *free<total);
        int start=*free;free=func_800B39D0(pool,start);
        CHECK(free[1]>0 && start+free[1]<=total);
        for(int j=0;j<free[1];++j) { CHECK(!owned[start+j]);owned[start+j]=1; }
    }
    for(int i=0;i<total;++i) CHECK(owned[i]);
}
int main(void) {
    u8 *pool=(void *)func_800B42FC(sizeof(Payload),0);
    CHECK(!func_800B4374((void *)pool));validate(pool);
    for(int step=0;step<12000;++step) {
        int which=random_word()%20, mode=(random_word()>>16)%5, count=ranges[which][1];
        if(mode<2 && count<80) {
            Payload *item=(void *)func_800B3CDC(&pool,ranges[which]);
            *item=(Payload){.pointer=(uintptr_t)&expected[which][count],.id=++serial,.value=random_word()};
            expected[which][count]=*item;
        } else if(mode==2 && count) {
            int index=random_word()%count;
            func_800B3FD0(&pool,ranges[which],index);
            for(int i=index;i<count-1;++i) expected[which][i]=expected[which][i+1];
        } else if(mode==3) func_800B422C(&pool,ranges[which]);
        else if(count) func_800B4134(&pool,ranges[which]);
        if(step%83==0) func_800B4354(&pool);
        validate(pool);
    }
    for(int i=0;i<20;++i) func_800B422C(&pool,ranges[i]);
    func_800B4354(&pool);validate(pool);CHECK(((s16 *)pool)[1]==1);
    func_800B39E8(pool);validate(pool);
    func_800B4290(ranges[0]);func_800B3FD0(&pool,ranges[0],0);validate(pool);
    func_800B42DC(pool);
    puts("Native block pool: 12000 mixed append/remove/compact/release operations passed");return 0;
}
