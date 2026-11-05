#include "native_texture.h"
#include "memory.h"
static u16 texture_half(const u8 *p) {return (u16)p[0]<<8|p[1];}
static u32 texture_word(const u8 *p) {return (u32)texture_half(p)<<16|texture_half(p+2);}
int native_texture_validate(const void *data,u32 available) {
    const u8 *p=data;
    if(!p || available<8 || (uintptr_t)p%4)return 0;
    u32 size=texture_word(p),count=texture_half(p+4),header=8+8*count;
    int external=texture_half(p+6)&0x100;
    if(count>32767 || header>available || size>64u*1024*1024)return 0;
    if(!external && size && (size<header || size>available))return 0;
    if(count && (!size || (!external && size==header)))return 0;
    for(u32 i=0;i<count;++i) {
        const u8 *entry=p+8+i*8;
        u32 offset=texture_word(entry);
        if(external ? offset>0x7FFFFFFFu-0x1EF6 : offset>=size-header)return 0;
    }
    return 1;
}
int native_texture_decode(void *data,u32 available) {
    u8 *p=data;if(!native_texture_validate(data,available))return 0;
    u32 size=texture_word(p);u16 count=texture_half(p+4),flags=texture_half(p+6);
    rare_memcpy(p,&size,4);rare_memcpy(p+4,&count,2);rare_memcpy(p+6,&flags,2);
    for(u32 i=0;i<count;++i) {
        u8 *entry=p+8+i*8;u32 offset=texture_word(entry);u16 format=texture_half(entry+4);
        rare_memcpy(entry,&offset,4);rare_memcpy(entry+4,&format,2);
    }
    return 1;
}
