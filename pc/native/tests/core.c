#include <stdio.h>
#include <stdlib.h>
#include "memory.h"
#include "vector.h"
#include "freelist.h"
#include "overlays/ba/flag.h"

#define CHECK(condition) do { if (!(condition)) { \
    fprintf(stderr, "%s:%d: %s\n", __FILE__, __LINE__, #condition); \
    exit(1); } } while (0)

_Static_assert(sizeof(u32) == 4 && sizeof(s32) == 4, "N64 word widths");
_Static_assert(sizeof(u64) == 8 && sizeof(s64) == 8, "N64 doubleword widths");
_Static_assert(sizeof(uintptr_t) == sizeof(void *), "Host pointer width");
_Static_assert(sizeof(f32) == 4 && sizeof(f64) == 8, "Floating point widths");

static void test_memory(void) {
    u32 words[6] = {1, 2, 3, 4, 5, 6};
    u32 copy[6] = {0};
    aligned4_memcpy(copy, words, sizeof(words));
    CHECK(copy[0] == 1 && copy[5] == 6);
    aligned4_memmove(words + 1, words, 4 * sizeof(u32));
    CHECK(words[0] == 1 && words[1] == 1 && words[4] == 4 && words[5] == 6);
    rare_memmove(words, words + 1, 4 * sizeof(u32));
    CHECK(words[0] == 1 && words[3] == 4);
    rare_memset(copy, 0, sizeof(copy));
    CHECK(copy[0] == 0 && copy[5] == 0);
    rare_memcpy(copy, words, sizeof(words));
    CHECK(copy[3] == words[3] && copy[5] == words[5]);
}

static void test_vector(void) {
    Vector *vec = vector_new(sizeof(void *), 0);
    int objects[40];
    s32 i;
    for (i = 0; i < 40; i++) {
        *(void **)vector_push_back(&vec) = &objects[i];
    }
    CHECK(vector_size(vec) == 40);
    for (i = 0; i < 40; i++) CHECK(*(void **)vector_at(vec, i) == &objects[i]);
    *(void **)vector_insert(&vec, 3) = &objects[39];
    CHECK(*(void **)vector_at(vec, 4) == &objects[3]);
    vector_erase(vec, 3);
    CHECK(vector_size(vec) == 40 && *(void **)vector_at(vec, 3) == &objects[3]);
    vector_erase_unordered(vec, 2);
    CHECK(*(void **)vector_at(vec, 2) == &objects[39]);
    vec = vector_defrag(vec);
    CHECK(vector_index_of(vec, vector_at(vec, 7)) == 7);
    CHECK(vector_end(vec) == vector_at(vec, vector_size(vec)));
    vector_pop_back_n(vec, 2);
    CHECK(vector_size(vec) == 37);
    vector_clear(vec);
    CHECK(vector_size(vec) == 0);
    vector_free(vec);
}

static void test_handles(void) {
    s16 handle = func_800B2DC0(sizeof(u32), 0);
    s32 i;
    CHECK(handle != 0);
    /* Force reallocations, including the formerly stale pointer in insert. */
    for (i = 0; i < 30; i++) *(u32 *)func_800B2C1C(handle, 0) = i;
    for (i = 0; i < 30; i++)
        CHECK(*(u32 *)vector_at(func_800B2890(handle), i) == (u32)(29 - i));
    func_800B2D48(handle);
    for (i = 0; i < 300; i++) {
        handle = func_800B2DC0(sizeof(u32), 1);
        CHECK(handle != 0);
        func_800B2D48(handle);
    }
}

static void test_freelist_pointer_alignment(void) {
    FreeList *list=freelist_new(sizeof(void *)+1,0);
    s32 indices[25];
    for(int i=0;i<25;++i) {
        void **slot=freelist_next(&list,&indices[i]);
        CHECK((uintptr_t)slot % _Alignof(void *)==0);
        *slot=&indices[i];
    }
    for(int i=0;i<25;++i) CHECK(*(void **)freelist_at(list,indices[i])==&indices[i]);
    freelist_free(list);
}

static void test_freelist(void) {
    FreeList *list = freelist_new(sizeof(u32), 1);
    s32 indices[25];
    s32 i;
    for (i = 0; i < 25; i++) *(u32 *)freelist_next(&list, &indices[i]) = 100 + i;
    CHECK(freelist_used_count(list) == 25);
    freelist_erase(list, indices[7]);
    CHECK(!freelist_is_element_alive(list, indices[7]));
    CHECK(freelist_used_count(list) == 24);
    *(u32 *)freelist_next(&list, &i) = 1234;
    CHECK(i == indices[7] && *(u32 *)freelist_at(list, i) == 1234);
    list = freelist_defrag(list);
    freelist_clear(list);
    CHECK(freelist_used_count(list) == 0);
    freelist_free(list);
}

static void test_player_flags(void) {
    PlayerState player = {0};
    BaFlag flags = {{0}};
    player.flag = &flags;
    CHECK(baflag_getStuctSize() == sizeof(flags));
    baflag_set(&player, BA_FLAG_12_HAS_FLAPPED);
    CHECK(baflag_isTrue(&player, BA_FLAG_12_HAS_FLAPPED));
    CHECK(baflag_isFalse(&player, BA_FLAG_1_ON_FLIGHT_PAD));
    baflag_clearAll(&player);
    CHECK(baflag_isFalse(&player, BA_FLAG_12_HAS_FLAPPED));
}

int main(void) {
    test_memory();
    test_vector();
    test_handles();
    test_freelist();
    test_freelist_pointer_alignment();
    test_player_flags();
    puts("Native C source tests passed: memory, vectors, handles, freelists, player flags");
    return 0;
}
