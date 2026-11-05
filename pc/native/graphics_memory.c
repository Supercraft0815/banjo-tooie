#include "native_graphics_memory.h"
#include "memory.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/* Keep all 16 N64 segments below the direct-reference address space. */
#define GRAPHICS_BASE UINT32_C(0x10000000)
#define GRAPHICS_END UINT32_C(0x80000000)
static NativeGraphicsMemory *bound_memory;

uint32_t native_graphics_address(const NativeGraphicsMemory *memory,const void *host,size_t size) {
    uintptr_t start=(uintptr_t)host;
    if(!memory || !host || !size || size>UINTPTR_MAX-start)return 0;
    for(uint32_t i=0;i<memory->count;++i) {
        const NativeGraphicsRange *range=&memory->ranges[i];uintptr_t base=(uintptr_t)range->host;
        if(start>=base && start-base<range->size && size<=range->size-(start-base))
            return range->address+(uint32_t)(start-base);
    }
    return 0;
}

uint32_t native_graphics_register(NativeGraphicsMemory *memory,const void *host,size_t size) {
    uintptr_t start=(uintptr_t)host;
    if(!memory || !host || !size || size>UINTPTR_MAX-start || size>GRAPHICS_END-GRAPHICS_BASE)return 0;
    uint32_t existing=native_graphics_address(memory,host,size);
    if(existing)return existing;
    /* Reject expanding/overlapping registrations: existing packet addresses cannot move. */
    for(uint32_t i=0;i<memory->count;++i) {
        uintptr_t base=(uintptr_t)memory->ranges[i].host;
        if(start<base+memory->ranges[i].size && base<start+size)return 0;
    }
    uint32_t next=memory->next ? memory->next : GRAPHICS_BASE;
    uint64_t end=(uint64_t)next+((size+7u)&~UINT64_C(7));
    if(end>GRAPHICS_END)return 0;
    if(memory->count==memory->capacity) {
        uint32_t capacity=memory->capacity ? memory->capacity*2u : 32u;
        if(capacity<memory->capacity || capacity>INT_MAX/sizeof(*memory->ranges))return 0;
        memory->ranges=heap_realloc(memory->ranges,capacity*sizeof(*memory->ranges));memory->capacity=capacity;
    }
    memory->ranges[memory->count++]=(NativeGraphicsRange){host,next,(uint32_t)size};memory->next=(uint32_t)end;
    return next;
}

const void *native_graphics_resolve(const NativeGraphicsMemory *memory,uint32_t address,size_t size) {
    if(!memory || !size)return NULL;
    uint32_t offset=0;
    if(address<GRAPHICS_BASE) {
        offset=address&0xFFFFFFu;address=memory->segments[address>>24];
        if(!address)return NULL;
    }
    for(uint32_t i=0;i<memory->count;++i) {
        const NativeGraphicsRange *range=&memory->ranges[i];
        if(address>=range->address && address-range->address<range->size) {
            uint64_t displacement=(uint64_t)(address-range->address)+offset;
            if(displacement<range->size && size<=range->size-displacement)return range->host+displacement;
            return NULL;
        }
    }
    return NULL;
}

int native_graphics_segment(NativeGraphicsMemory *memory,unsigned segment,uint32_t base) {
    if(!memory || segment>=16 || (base && (base<GRAPHICS_BASE || !native_graphics_resolve(memory,base,1))))return 0;
    memory->segments[segment]=base;return 1;
}

void native_graphics_reset(NativeGraphicsMemory *memory) {
    memory->count=0;memory->next=GRAPHICS_BASE;
    for(unsigned i=0;i<16;++i)memory->segments[i]=0;
}

void native_graphics_dispose(NativeGraphicsMemory *memory) {
    if(bound_memory==memory)bound_memory=NULL;
    heap_free(memory->ranges);*memory=(NativeGraphicsMemory){0};
}

NativeGraphicsMemory *native_graphics_bind(NativeGraphicsMemory *memory) {
    NativeGraphicsMemory *previous=bound_memory;bound_memory=memory;return previous;
}

static void graphics_address_error(void) {
    fputs("Banjo-Tooie native graphics: unregistered pointer or invalid numeric address\n",stderr);abort();
}

uint32_t native_graphics_pointer(const void *host) {
    if(!host)return 0;
    uint32_t address=native_graphics_address(bound_memory,host,1);
    if(!address)graphics_address_error();
    return address;
}

uint32_t native_graphics_numeric(uintptr_t address) {
    if(address>UINT32_MAX)graphics_address_error();
    return (uint32_t)address;
}

u32 osVirtualToPhysical(void *host) {return native_graphics_pointer(host);}
