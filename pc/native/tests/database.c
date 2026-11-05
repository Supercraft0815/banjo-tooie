#include "native_assets.h"
#include "overlays/gl/dbDll.h"
#include "memory.h"
#include <stdio.h>
#include <stdlib.h>

#define CHECK(condition) do { if (!(condition)) { \
    fprintf(stderr, "%s:%d: %s\n", __FILE__, __LINE__, #condition); \
    exit(1); } } while (0)

static void check_bytes(const void *actual, const void *expected, int size) {
    const u8 *a = actual, *b = expected;
    int i;
    for (i = 0; i < size; ++i) CHECK(a[i] == b[i]);
}

static void test_keys(void) {
    static const u8 keys[3][14] = {
        {0xd3,0x71,0x1f,0x9f,0x91,0x71,0x7b,0xf9,0xf9,0xf9,0xf9,0xf9,0xf9,0xf9},
        {0xd8,0xc6,0x84,0xe6,0xee,0x6e,0xc0,0x4e,0x6e,0xc6,0x2a,0x8c,0xbf,0x9f},
        {0xd0,0x4e,0x40,0x4e,0xb7,0x17,0x15,0x55,0x5a,0x8c,0xa8,0xc6,0xb5,0x55}
    };
    static const s32 seeds[3] = {0xa0, 0xa1, 0x1a9};
    u8 response[16];
    u32 buffer[9];
    u8 *bytes = (u8 *)buffer;
    int i, j;
    for (i = 0; i < 3; ++i) {
        func_80800000_gldbDll(response, seeds[i]);
        check_bytes(response, keys[i], 14);
        CHECK(response[15] == 0);
        for (j = 0; j < sizeof(buffer); ++j) bytes[j] = j;
        func_808000E8_gldbDll((s32 *)buffer, seeds[i], 31);
        for (j = 0; j < 31; ++j) CHECK(bytes[j] == (j ^ keys[i][j % 14]));
        for (j = 31; j < sizeof(buffer); ++j) CHECK(bytes[j] == j);
        func_808000E8_gldbDll((s32 *)buffer, seeds[i], 31);
        for (j = 0; j < sizeof(buffer); ++j) CHECK(bytes[j] == j);
    }
}

int main(int argc, char **argv) {
    int id, count = 0;
    CHECK(argc == 2 || argc == 3);
    test_keys();
    CHECK(native_assets_open(argv[1]));
    for (id = 0; id < native_asset_count(); ++id) {
        s32 size = -1;
        u8 *data, *cached;
        if (func_800D58FC(id) != 10) continue;
        data = (u8 *)gldbDll_entrypoint_0(id, &size);
        if (!data) fprintf(stderr, "Failed database asset %#x\n", id);
        CHECK(data && size > 0 && size % 16 == 0);
        cached = func_800D5B34(id);
        CHECK(cached && func_800D5944() == size);
        check_bytes(data, cached, size);
        if (argc == 3) {
            int i;
            u8 destination[32] = {42};
            CHECK(id == 0x9f5 && size == 32);
            check_bytes(data, "Native database fixture", 23);
            for (i = 23; i < size; ++i) CHECK(data[i] == 0);
            CHECK(!native_asset_read_into(id, destination, 31) && destination[0] == 42);
            func_800D5FDC(0);
            CHECK(native_asset_read_into(id, destination, 32) == 32);
            CHECK(func_800D5944() == 32);
            check_bytes(destination, data, 32);
        }
        CHECK(func_800D56C4(cached) == 0);
        heap_free(data);
        count++;
    }
    CHECK(count > 0);
    native_assets_close();
    printf("Decoded %d encrypted databases through native C\n", count);
    return 0;
}
