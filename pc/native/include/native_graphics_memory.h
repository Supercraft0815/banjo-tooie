#ifndef BT_NATIVE_GRAPHICS_MEMORY_H
#define BT_NATIVE_GRAPHICS_MEMORY_H
#include <stddef.h>
#include <stdint.h>

typedef struct {const unsigned char *host;uint32_t address,size;} NativeGraphicsRange;
typedef struct {
    NativeGraphicsRange *ranges;
    uint32_t count,capacity,next,segments[16];
} NativeGraphicsMemory;

/* Zero-initialize. Registered storage must remain alive until its batch finishes. */
uint32_t native_graphics_register(NativeGraphicsMemory *,const void *,size_t);
uint32_t native_graphics_address(const NativeGraphicsMemory *,const void *,size_t);
const void *native_graphics_resolve(const NativeGraphicsMemory *,uint32_t,size_t);
int native_graphics_segment(NativeGraphicsMemory *,unsigned,uint32_t);
void native_graphics_reset(NativeGraphicsMemory *);
void native_graphics_dispose(NativeGraphicsMemory *);
NativeGraphicsMemory *native_graphics_bind(NativeGraphicsMemory *);

/* SDK command macros cannot report failure; unregistered pointers fail loudly. */
uint32_t native_graphics_pointer(const void *);
uint32_t native_graphics_numeric(uintptr_t);
#define BT_GFX_ADDRESS(value) _Generic((value), \
    char:native_graphics_numeric,signed char:native_graphics_numeric,unsigned char:native_graphics_numeric, \
    short:native_graphics_numeric,unsigned short:native_graphics_numeric, \
    int:native_graphics_numeric,unsigned int:native_graphics_numeric, \
    long:native_graphics_numeric,unsigned long:native_graphics_numeric, \
    long long:native_graphics_numeric,unsigned long long:native_graphics_numeric, \
    default:native_graphics_pointer)(value)
#endif
