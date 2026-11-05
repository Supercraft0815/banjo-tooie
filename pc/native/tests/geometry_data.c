#include "native_geometry.h"
#include "memory.h"
#include <stdio.h>
#include <stdlib.h>
#define CHECK(x) do {if(!(x)){fprintf(stderr,"%s:%d: %s\n",__FILE__,__LINE__,#x);exit(1);}}while(0)
static void put(u8 *p,u32 v,int width) {for(int i=0;i<width;++i)p[i]=v>>((width-1-i)*8);}
static u32 word(u8 *p) {u32 value;rare_memcpy(&value,p,4);return value;}
static u16 half(u8 *p) {u16 value;rare_memcpy(&value,p,2);return value;}
static void fixture(u8 *p,u32 op) {
    rare_memset(p,0,256);put(p,op,4);put(p+4,128,4);put(p+128,4,4);
    switch(op) {
        case 0:put(p+8,128,2);put(p+10,1,2);for(int j=12;j<24;j+=4)put(p+j,0x3FC00000,4);break;
        case 1:for(int j=8;j<32;j+=4)put(p+j,0x3FC00000,4);p[32]=1;p[33]=2;put(p+34,128,2);put(p+36,128,4);break;
        case 2:p[8]=128;p[9]=2;break;
        case 3:put(p+8,2,2);break;
        case 5:case 22:put(p+8,1,2);put(p+10,3,2);break;
        case 6:put(p+8,128,4);break;
        case 7:p[8]=0x12;p[9]=0x34;put(p+10,2,2);break;
        case 8:for(int j=8;j<28;j+=4)put(p+j,0x3FC00000,4);put(p+28,128,4);break;
        case 10:put(p+8,7,2);put(p+10,1,2);for(int j=12;j<24;j+=4)put(p+j,0x3FC00000,4);break;
        case 12:put(p+8,2,2);put(p+10,59,2);put(p+12,128,4);put(p+16,128,4);break;
        case 13:for(int j=8;j<20;j+=2)put(p+j,0xFFFE,2);put(p+20,128,2);break;
        case 14:put(p+8,0xFFFE,2);put(p+14,20,2);put(p+16,128,2);put(p+18,1,2);break;
        case 15:put(p+8,128,2);p[10]=2;p[11]=3;p[12]=1;p[13]=3;p[14]=7;break;
        case 16:put(p+8,2,4);break;
        case 17:put(p+8,2,2);put(p+10,3,2);put(p+12,4,2);put(p+14,1,2);break;
        case 18:case 24:put(p+8,1,2);put(p+10,3,2);put(p+20,2,2);put(p+32,3,2);put(p+44,4,2);put(p+46,1,2);break;
        case 21:put(p+8,2,2);put(p+10,3,2);put(p+12,0xFFFF,2);put(p+14,2,2);put(p+16,1,2);put(p+18,3,2);break;
        case 23:put(p+8,2,2);put(p+10,3,2);put(p+12,4,2);put(p+14,1,2);break;
    }
}
static void test_commands(void) {
    u64 storage[32];u8 *p=(void *)storage;
    for(u32 op=0;op<25;++op) {
        fixture(p,op);CHECK(native_geometry_decode(p,136,10,3));CHECK(word(p)==op && word(p+4)==128 && word(p+128)==4);
        if(op==0 || op==10)CHECK(word(p+12)==0x3FC00000 && half(p+10)==1);
        if(op==1)CHECK(word(p+28)==0x3FC00000 && p[32]==1 && p[33]==2 && half(p+34)==128 && word(p+36)==128);
        if(op==2)CHECK(p[8]==128 && p[9]==2);
        if(op==5 || op==22)CHECK(half(p+8)==1 && half(p+10)==3 && !half(p+12));
        if(op==6)CHECK(word(p+8)==128);
        if(op==7)CHECK(p[8]==0x12 && p[9]==0x34 && half(p+10)==2);
        if(op==8)CHECK(word(p+24)==0x3FC00000 && word(p+28)==128);
        if(op==12)CHECK(half(p+8)==2 && half(p+10)==59 && word(p+12)==128 && word(p+16)==128);
        if(op==13)CHECK(half(p+8)==0xFFFE && half(p+20)==128);
        if(op==14)CHECK(half(p+8)==0xFFFE && half(p+16)==128 && half(p+18)==1);
        if(op==15)CHECK(half(p+8)==128 && p[10]==2 && p[11]==3 && p[12]==1 && p[13]==3 && p[14]==7);
        if(op==16)CHECK(word(p+8)==2);
        if(op==17 || op==23)CHECK(half(p+8)==2 && half(p+10)==3 && half(p+12)==4 && half(p+14)==1);
        if(op==18 || op==24)CHECK(half(p+8)==1 && half(p+20)==2 && half(p+32)==3 && half(p+44)==4 && half(p+46)==1);
        if(op==21)CHECK(half(p+12)==0xFFFF && half(p+14)==2 && half(p+16)==1 && half(p+18)==3);
    }
}
static void unchanged(u8 *p,u32 size) {
    u8 saved[256];rare_memcpy(saved,p,256);CHECK(!native_geometry_decode(p,size,10,3));
    for(int i=0;i<256;++i)CHECK(p[i]==saved[i]);
}
static void test_invalid(void) {
    u64 storage[32];u8 *p=(void *)storage;
    for(int size=0;size<136;++size){fixture(p,12);unchanged(p,size);}
    u32 cases[][4]={{3,0,25,4},{3,4,4,4},{3,4,130,4},{3,4,0xFFFFFFFC,4},{3,4,256,4},{3,128,25,4},
        {3,8,10,2},{3,8,0xFFFF,2},{0,12,0x7F800000,4},{1,28,0x7FC00000,4},{1,32,3,1},{2,9,3,1},
        {6,8,0,4},{6,8,4,4},{6,8,0xFFFFFFFC,4},{12,8,0xFFFF,2},{12,10,60,2},{12,12,16,4},{12,12,0,4},
        {12,16,132,4},{15,10,250,1},{18,18,9,2},{21,8,0xFFFF,2},{21,12,3,2},{24,8,11,2},{17,12,0xFFFF,2},{21,14,0xFFFF,2},{24,44,0xFFFF,2}};
    for(unsigned i=0;i<sizeof(cases)/sizeof(*cases);++i) {
        fixture(p,cases[i][0]);put(p+cases[i][1],cases[i][2],cases[i][3]);
        if(cases[i][0]==18)for(int j=12;j<20;j+=2)put(p+j,9,2);
        unchanged(p,136);
    }
    fixture(p,5);put(p+4,0,4);for(int j=10;j<136;j+=2)put(p+j,1,2);unchanged(p,136);
    fixture(p,3);put(p+8,0xFFFF,2);CHECK(!native_geometry_decode(p,136,70000,3));
    CHECK(!native_geometry_decode(p,0xFFFFFFFFu,10,3));
    CHECK(!native_geometry_decode(NULL,136,10,3) && !native_geometry_decode(p+1,135,10,3));
}
int main(void) {test_commands();test_invalid();puts("native geometry graph validation and scalar decoding passed");return 0;}
