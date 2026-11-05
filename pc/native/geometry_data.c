#include "native_geometry.h"
#include "memory.h"
#include <limits.h>
static u16 geo_u16(const u8 *p) {return (u16)p[0]<<8|p[1];}
static u32 geo_u32(const u8 *p) {return (u32)geo_u16(p)<<16|geo_u16(p+2);}
static void geo_half(u8 *p) {u16 value=geo_u16(p);rare_memcpy(p,&value,2);}
static void geo_word(u8 *p) {u32 value=geo_u32(p);rare_memcpy(p,&value,4);}
static int geo_display(u16 index,u32 count) {return (s16)index>=0 && index<count;}
static int geo_bone(s32 index,s32 bones) {return index>=-1 && index<bones;}
static int geo_branch(u8 *marks,u32 available,u32 position,u32 extent,s32 branch,int optional) {
    if(!branch)return optional;
    if(branch<0 || (u32)branch<extent || (branch&3) || (u32)branch>available-position-8)return 0;
    u32 target=(position+(u32)branch)/4;if(marks[target]==2)return 0;
    marks[target]=1;return 1;
}
static u32 geo_extent(const u8 *p,u32 remaining,u32 op) {
    static const u8 minimum[]={24,40,12,12,8,12,12,12,32,8,24,8,12,24,20,16,12,16,48,8,8,12,12,16,48};
    if(op>=25 || remaining<minimum[op])return 0;
    u32 size=minimum[op];
    if(op==5 || op==22) {
        size=10;
        do {if(remaining-size<2)return 0;size+=2;}while(geo_u16(p+size-2));
    } else if(op==12 || op==21) {
        s32 count=(s16)geo_u16(p+8);if(count<0 || (u32)count>(remaining-12)/4)return 0;
        size=12+(u32)count*4;
    } else if(op==15)size=13+p[10];
    return size<=remaining ? size : 0;
}
static int geo_validate(const u8 *p,u32 op,u32 extent,u32 display_count,s32 bones) {
    u32 float_start=0,float_end=0;
    if(op==0 || op==10){float_start=12;float_end=24;}
    else if(op==1){float_start=8;float_end=32;}
    else if(op==8){float_start=8;float_end=28;}
    for(u32 j=float_start;j<float_end;j+=4)if((geo_u32(p+j)&0x7F800000u)==0x7F800000u)return 0;
    if(op==1 && (p[33]&2) && !geo_bone((s8)p[32],bones))return 0;
    if(op==2 && !geo_bone((s8)p[9],bones))return 0;
    if(op==10 && !geo_bone((s16)geo_u16(p+10),bones))return 0;
    if(op==14 && !geo_bone((s16)geo_u16(p+18),bones))return 0;
    if(op==12 && geo_u16(p+10)>=60)return 0;
    if(op==21)for(u32 j=12;j<extent;j+=4)if(!geo_bone((s16)geo_u16(p+j),bones))return 0;
    if(op==3 || op==17){if(!geo_display(geo_u16(p+8),display_count))return 0;}
    if(op==7 && !geo_display(geo_u16(p+10),display_count))return 0;
    if(op==5 || op==22)for(u32 j=8;j<extent-2;j+=2)if(!geo_display(geo_u16(p+j),display_count))return 0;
    if(op==17 || op==23)for(int j=10;j<14;j+=2)if((s16)geo_u16(p+j)<0)return 0;
    if(op==23 && (s16)geo_u16(p+8)<0)return 0;
    if(op==21 && (s16)geo_u16(p+10)<0)return 0;
    if(op==21)for(u32 j=14;j<extent;j+=4)if((s16)geo_u16(p+j)<0)return 0;
    if(op==18 || op==24) {
        for(int j=20;j<46;j+=2)if((s16)geo_u16(p+j)<0)return 0;
        if(!geo_display(geo_u16(p+8),display_count))return 0;
        int i=1;while(i<6 && geo_u16(p+8+i*2)){if(!geo_display(geo_u16(p+8+i*2),display_count))return 0;++i;}
        if(i==6)return 0;
    }
    return 1;
}
static void geo_convert(u8 *p,u32 op,u32 extent) {
    u32 half_start=0,half_end=0,word_start=0,word_end=0;
    switch(op) {
        case 0:half_start=8;half_end=12;word_start=12;word_end=24;break;
        case 1:half_start=34;half_end=36;word_start=8;word_end=32;geo_word(p+36);break;
        case 3:half_start=8;half_end=10;break;
        case 5:case 22:half_start=8;half_end=extent;break;
        case 6:case 16:word_start=8;word_end=12;break;
        case 7:half_start=10;half_end=12;break;
        case 8:word_start=8;word_end=32;break;
        case 10:half_start=8;half_end=12;word_start=12;word_end=24;break;
        case 12:half_start=8;half_end=12;word_start=12;word_end=extent;break;
        case 13:half_start=8;half_end=22;break;
        case 14:half_start=8;half_end=20;break;
        case 15:half_start=8;half_end=10;break;
        case 17:case 23:half_start=8;half_end=16;break;
        case 18:case 24:half_start=8;half_end=48;break;
        case 21:half_start=8;half_end=extent;break;
    }
    for(u32 j=half_start;j<half_end;j+=2)geo_half(p+j);
    for(u32 j=word_start;j<word_end;j+=4)geo_word(p+j);
    geo_word(p);geo_word(p+4);
}
int native_geometry_decode(u8 *commands,u32 size,u32 display_count,s32 bones) {
    if(!commands || size<8 || size>INT_MAX || (uintptr_t)commands%4)return 0;
    u32 slots=size/4+(size%4!=0);u8 *marks=heap_alloc(slots);rare_memset(marks,0,slots);marks[0]=1;
    int valid=1;
    for(u32 position=0;position+8<=size && valid;position+=4) {
        if(marks[position/4]!=1)continue;
        const u8 *p=commands+position;u32 op=geo_u32(p),extent=geo_extent(p,size-position,op);
        if(!extent || !geo_validate(p,op,extent,display_count,bones)){valid=0;break;}
        marks[position/4]=3;
        for(u32 j=1;j<(extent+3)/4;++j) {if(marks[position/4+j]){valid=0;break;}marks[position/4+j]=2;}
        if(!valid)break;
        valid=geo_branch(marks,size,position,extent,(s32)geo_u32(p+4),1);
        switch(op) {
            case 0:valid&=geo_branch(marks,size,position,extent,(s16)geo_u16(p+8),1);break;
            case 1:valid&=geo_branch(marks,size,position,extent,(s16)geo_u16(p+34),1);valid&=geo_branch(marks,size,position,extent,(s32)geo_u32(p+36),1);break;
            case 2:valid&=geo_branch(marks,size,position,extent,p[8],1);break;
            case 6:valid&=geo_branch(marks,size,position,extent,(s32)geo_u32(p+8),0);break;
            case 8:valid&=geo_branch(marks,size,position,extent,(s32)geo_u32(p+28),1);break;
            case 12:for(u32 j=12;j<extent;j+=4)valid&=geo_branch(marks,size,position,extent,(s32)geo_u32(p+j),0);break;
            case 13:valid&=geo_branch(marks,size,position,extent,(s16)geo_u16(p+20),1);break;
            case 14:valid&=geo_branch(marks,size,position,extent,(s16)geo_u16(p+16),1);break;
            case 15:valid&=geo_branch(marks,size,position,extent,(s16)geo_u16(p+8),0);break;
        }
    }
    if(valid)for(u32 position=0;position+8<=size;position+=4)if(marks[position/4]==3) {
        u8 *p=commands+position;u32 op=geo_u32(p);geo_convert(p,op,geo_extent(p,size-position,op));
    }
    heap_free(marks);return valid;
}
