// The game's memory and its 32-bit "physical" addresses.
//
// N64 code hands 32-bit RDRAM addresses to the RSP, DMA and segment tables
// (osVirtualToPhysical, K0_TO_PHYS). On the host, every game allocation comes
// from an arena inside the executable's .bss, so statics and heap blocks all lie
// within 256 MB of the image start. The physical address is 0x80000000 plus the
// offset from that start (above the segmented and graphics-registry ranges, see
// graphics_memory.c); consumers (display lists, audio lists) map it back.
#ifndef __wasm__
#include <mach-o/getsect.h>
#include <mach-o/ldsyms.h>
#endif
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <ultra64.h>
#include "native_rdram.h"

#define ARENA_SIZE (192u << 20)
#define PHYS_BASE 0x80000000u
#define PHYS_SPAN 0x10000000u
#define ALIGN 16u

// Boundary-tag first-fit allocator. Every block starts with its size and the size
// of the previous block; free blocks also hold free-list links.
typedef struct Block {
    size_t size;      // including this header; bit 0 = used
    size_t prev_size; // 0 for the first block
} Block;
typedef struct FreeBlock {
    Block b;
    struct FreeBlock *next, *prev;
} FreeBlock;

static _Alignas(4096) unsigned char arena[ARENA_SIZE];
static FreeBlock *free_list;
static int arena_ready;

#define BLOCK_SIZE(b) ((b)->size & ~(size_t)1)
#define USED(b) ((b)->size & 1)
#define NEXT(b) ((Block *)((unsigned char *)(b) + BLOCK_SIZE(b)))
#define PREV(b) ((Block *)((unsigned char *)(b) - (b)->prev_size))
#define END ((Block *)(arena + ARENA_SIZE - sizeof(Block)))
#define MIN_BLOCK sizeof(FreeBlock)

static void list_remove(FreeBlock *f) {
    if (f->prev) f->prev->next = f->next; else free_list = f->next;
    if (f->next) f->next->prev = f->prev;
}

static void list_push(FreeBlock *f) {
    f->prev = NULL;
    f->next = free_list;
    if (free_list) free_list->prev = f;
    free_list = f;
}

static void arena_init(void) {
    FreeBlock *f = (FreeBlock *)arena;
    f->b.size = ARENA_SIZE - sizeof(Block);
    f->b.prev_size = 0;
    END->size = 1; // sentinel: a used block of size 0
    END->prev_size = f->b.size;
    list_push(f);
    arena_ready = 1;
}

static int in_arena(const void *p) {
    return (const unsigned char *)p >= arena && (const unsigned char *)p < arena + ARENA_SIZE;
}
static void fail(const char *what) {
    fprintf(stderr, "bt_native rdram: %s\n", what);
    abort();
}

#ifdef BT_HEAP_CHECK
// Debug aid: walks every block and the free list; aborts at the first broken header.
static void heap_check(const char *where) {
    Block *b = (Block *)arena;
    size_t prev = 0;
    if (!arena_ready) return;
    while (b != END) {
        if ((unsigned char *)b < arena || (unsigned char *)b >= (unsigned char *)END || b->prev_size != prev || BLOCK_SIZE(b) < MIN_BLOCK) {
            fprintf(stderr, "bt_native rdram: heap broken at %p (%s), previous block %p\n", (void *)b, where, (void *)((unsigned char *)b - prev));
            abort();
        }
        prev = BLOCK_SIZE(b);
        b = NEXT(b);
    }
    for (FreeBlock *f = free_list; f; f = f->next)
        if (!in_arena(f) || USED(&f->b)) { fprintf(stderr, "bt_native rdram: free list broken at %p (%s)\n", (void *)f, where); abort(); }
}
#else
#define heap_check(where)
#endif

void *bt_alloc(size_t n) {
    heap_check("alloc");
    size_t need = (n + sizeof(Block) + ALIGN - 1) & ~(size_t)(ALIGN - 1);
    if (!arena_ready) arena_init();
    if (need < MIN_BLOCK) need = MIN_BLOCK;
    for (FreeBlock *f = free_list; f; f = f->next) {
        size_t size = BLOCK_SIZE(&f->b);
        if (size < need) continue;
        list_remove(f);
        if (size - need >= MIN_BLOCK) {
            Block *rest = (Block *)((unsigned char *)f + need);
            rest->size = size - need;
            rest->prev_size = need;
            NEXT(rest)->prev_size = rest->size;
            list_push((FreeBlock *)rest);
            size = need;
        }
        f->b.size = size | 1;
        return (unsigned char *)f + sizeof(Block);
    }
    fail("arena exhausted");
    return NULL;
}


void bt_free(void *p) {
    Block *b;
    if (!p) return;
    heap_check("free");
    if (!in_arena(p)) { free(p); return; } // host allocations handed over by tests
    b = (Block *)((unsigned char *)p - sizeof(Block));
    if (!USED(b)) fail("double free");
    b->size &= ~(size_t)1;
    if (!USED(NEXT(b))) { // merge the following free block
        Block *n = NEXT(b);
        list_remove((FreeBlock *)n);
        b->size += n->size;
    }
    if (b->prev_size && !USED(PREV(b))) { // merge into the preceding free block
        Block *prev = PREV(b);
        list_remove((FreeBlock *)prev);
        prev->size += b->size;
        b = prev;
    }
    NEXT(b)->prev_size = b->size;
    list_push((FreeBlock *)b);
}

size_t bt_alloc_size(const void *p) {
    const Block *b = (const Block *)((const unsigned char *)p - sizeof(Block));
    return BLOCK_SIZE(b) - sizeof(Block);
}

void *bt_realloc(void *p, size_t n) {
    void *q;
    size_t old;
    if (!p) return bt_alloc(n);
    if (!in_arena(p)) return realloc(p, n);
    old = bt_alloc_size(p);
    if (n <= old) return p;
    q = bt_alloc(n);
    __builtin_memcpy(q, p, old);
    bt_free(p);
    return q;
}

#ifdef __wasm__
// ILP32 build (pc/native/wasm): guest memory starts at 0x80000000, so a pointer is its own address.
u32 bt_phys(const void *p) { return (u32)(uintptr_t)p; }
int bt_is_phys(u32 phys) { return phys >= PHYS_BASE && phys - PHYS_BASE < PHYS_SPAN; }
void *bt_host(u32 phys) {
    if (!bt_is_phys(phys)) {
        fprintf(stderr, "bt_native rdram: 0x%08x is not a physical address\n", phys);
        abort();
    }
    return (void *)(uintptr_t)phys;
}
#else
// Physical addresses: offsets from the Mach-O header of the executable.
static const unsigned char *image_base(void) {
    return (const unsigned char *)&_mh_execute_header;
}

u32 bt_phys(const void *p) {
    uintptr_t d = (uintptr_t)p - (uintptr_t)image_base();
    if (p == NULL) return 0;
    if ((uintptr_t)p < (uintptr_t)image_base() || d >= PHYS_SPAN) {
        fprintf(stderr, "bt_native rdram: %p is not game memory (stack or libc heap?)\n", p);
        abort();
    }
    return PHYS_BASE + (u32)d;
}

int bt_is_phys(u32 phys) {
    return phys >= PHYS_BASE && phys - PHYS_BASE < PHYS_SPAN;
}

void *bt_host(u32 phys) {
    if (!bt_is_phys(phys)) {
        fprintf(stderr, "bt_native rdram: 0x%08x is not a physical address\n", phys);
        abort();
    }
    return (void *)(image_base() + (phys - PHYS_BASE));
}
#endif
