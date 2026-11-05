#include "native_gsfile.h"
#include "native_assets.h"
#include "core2/1EAF950.h"
#include "memory.h"
#include <stdio.h>
#include <stdlib.h>

#define CHECK(condition) do { if (!(condition)) { \
    fprintf(stderr, "%s:%d: %s\n", __FILE__, __LINE__, #condition); \
    exit(1); } } while (0)

/* The resource loaders and both cache layers are real; only their clock is fixed. */
s32 func_8001211C(void) { return 100; }

static const u8 wire[] = {
    17, 0xAB, 18, 0, 1, 0xFE, 0xFF,
    19, 0xBF, 0xC0, 0, 0,
    20, 0x80, 0, 0, 0, 0x7F, 0xC1, 0x23, 0x45,
    21, 0x89, 0xAB, 0xCD, 0xEF,
    22, 0, 0, 0, 1, 0x80, 0, 0, 0,
    23, 0x55, 0xAA, 24, 0xFE, 0xDC,
    25, 0, 1, 0x80, 0, 0
};

static void check_equal(const void *a, const void *b, s32 length) {
    const u8 *left = a, *right = b;
    s32 i;
    for (i = 0; i < length; ++i) CHECK(left[i] == right[i]);
}

static void values(GsFile *file, int writing) {
    u8 byte = 0xAB, bytes[] = {0, 1, 0xFE, 0xFF}, raw[] = {0x55, 0xAA};
    f32 scalar = -1.5f;
    u32 floats[] = {0x80000000, 0x7FC12345}, integer = 0x89ABCDEF;
    s32 integers[] = {1, INT32_MIN};
    u16 half = 0xFEDC, halves[] = {1, 0x8000};
    if (!writing) {
        byte = 0; scalar = 0; integer = 0; half = 0;
        rare_memset(bytes, 0, sizeof(bytes)); rare_memset(raw, 0, sizeof(raw));
        rare_memset(floats, 0, sizeof(floats)); rare_memset(integers, 0, sizeof(integers));
        rare_memset(halves, 0, sizeof(halves));
        CHECK(!gsmaker_entrypoint_16(file, 88) && file->last_expected == 17);
        CHECK(!gsmaker_entrypoint_16(file, 99) && file->last_expected == 17);
    }
    CHECK(gsmaker_entrypoint_17(file, 17, &byte));
    CHECK(gsmaker_entrypoint_18(file, 18, bytes, sizeof(bytes)));
    CHECK(gsmaker_entrypoint_19(file, 19, &scalar));
    CHECK(gsmaker_entrypoint_20(file, 20, floats, 2));
    CHECK(gsmaker_entrypoint_21(file, 21, &integer));
    CHECK(gsmaker_entrypoint_22(file, 22, integers, 2));
    CHECK(gsmaker_entrypoint_23(file, 23, raw, sizeof(raw)));
    CHECK(gsmaker_entrypoint_24(file, 24, &half));
    CHECK(gsmaker_entrypoint_25(file, 25, halves, 2));
    CHECK(gsmaker_entrypoint_16(file, 0));
    CHECK(!file->failed && file->last_expected == -1);
    CHECK(byte == 0xAB && bytes[0] == 0 && bytes[1] == 1 && bytes[2] == 0xFE && bytes[3] == 0xFF);
    CHECK(scalar == -1.5f && floats[0] == 0x80000000 && floats[1] == 0x7FC12345);
    CHECK(integer == 0x89ABCDEF && integers[0] == 1 && integers[1] == INT32_MIN);
    CHECK(raw[0] == 0x55 && raw[1] == 0xAA && half == 0xFEDC && halves[0] == 1 && halves[1] == 0x8000);
}

static void test_memory_streams(void) {
    GsFile *writer = gsmaker_entrypoint_5(), *reader;
    void *buffer;
    s32 size, i;
    u32 value;
    values(writer, 1);
    gsmaker_entrypoint_6(writer, &buffer, &size);
    CHECK(size == sizeof(wire));
    check_equal(buffer, wire, size);
    reader = gsmaker_entrypoint_4(buffer, size);
    CHECK(reader->base_ptr == buffer);
    values(reader, 0);
    CHECK(reader->current_ptr == reader->end_ptr);
    CHECK(!gsmaker_entrypoint_16(reader, 0) && reader->failed);
    gsmaker_entrypoint_0(reader);
    check_equal(buffer, wire, size); /* Borrowed buffers survive stream destruction. */
    heap_free(buffer);

    writer = gsmaker_entrypoint_5();
    for (i = 0; i < 4097; ++i) {
        value = 0xDEADBEEF ^ (u32)i;
        gsmaker_entrypoint_11(writer, &value);
    }
    gsmaker_entrypoint_6(writer, &buffer, &size);
    CHECK(size == 4097 * 4);
    for (i = 0; i < 4097; ++i) {
        const u8 *bytes = (u8 *)buffer + 4 * i;
        value = 0xDEADBEEF ^ (u32)i;
        CHECK(bytes[0] == (value >> 24) && bytes[1] == ((value >> 16) & 255));
        CHECK(bytes[2] == ((value >> 8) & 255) && bytes[3] == (value & 255));
    }
    reader = gsmaker_entrypoint_4(buffer, size);
    for (i = 0; i < 4097; ++i) {
        value = 0;
        gsmaker_entrypoint_11(reader, &value);
        CHECK(value == (0xDEADBEEF ^ (u32)i));
    }
    CHECK(!reader->failed);
    gsmaker_entrypoint_0(reader); heap_free(buffer);
    gsmaker_entrypoint_0(gsmaker_entrypoint_5()); /* Abandoned writer owns its allocation. */
    writer = gsmaker_entrypoint_5();
    gsmaker_entrypoint_6(writer, &buffer, &size);
    CHECK(buffer && size == 0); heap_free(buffer);
}

static void test_invalid_streams(void) {
    u8 bytes[] = {21, 0x12, 0x34, 0x56}, output[8], unaligned[9];
    u32 value = 0xCAFEBABE;
    GsFile *file;
    void *buffer = bytes;
    s32 size = 42, i;
    CHECK(!gsmaker_entrypoint_4(NULL, 1) && !gsmaker_entrypoint_4(bytes, -1));
    CHECK(!gsmaker_entrypoint_16(NULL, 0)); gsmaker_entrypoint_0(NULL);
    file = gsmaker_entrypoint_4(NULL, 0);
    gsmaker_entrypoint_13(file, NULL, 0); CHECK(!file->failed);
    CHECK(!gsmaker_entrypoint_16(file, 0) && file->failed); gsmaker_entrypoint_0(file);
    file = gsmaker_entrypoint_4(bytes, sizeof(bytes));
    CHECK(!gsmaker_entrypoint_21(file, 21, &value) && file->failed && value == 0xCAFEBABE);
    CHECK(file->current_ptr == file->base_ptr + 1);
    CHECK(!gsmaker_entrypoint_16(file, 0)); gsmaker_entrypoint_0(file);
    for (i = 0; i < 4; ++i) {
        file = gsmaker_entrypoint_4(bytes, 4);
        rare_memset(output, 0xAA, sizeof(output));
        if (i == 0) gsmaker_entrypoint_13(file, output, -1);
        if (i == 1) gsmaker_entrypoint_12(file, output, INT32_MAX);
        if (i == 2) gsmaker_entrypoint_15(file, output, -1);
        if (i == 3) gsmaker_entrypoint_13(file, NULL, 1);
        CHECK(file->failed && file->current_ptr == bytes && output[0] == 0xAA);
        gsmaker_entrypoint_0(file);
    }
    file = gsmaker_entrypoint_5();
    gsmaker_entrypoint_7(file, bytes);
    gsmaker_entrypoint_13(file, bytes, INT32_MAX); /* Detect overflow before copying. */
    CHECK(file->failed);
    gsmaker_entrypoint_6(file, &buffer, &size); CHECK(!buffer && size == 0);
    file = gsmaker_entrypoint_4(bytes, 4);
    gsmaker_entrypoint_6(file, &buffer, &size); CHECK(!buffer && size == 0 && bytes[0] == 21);
    file = gsmaker_entrypoint_5();
    gsmaker_entrypoint_6(file, NULL, &size); CHECK(size == 0);

    /* Scalar conversion must allow unaligned host destinations and sources. */
    file = gsmaker_entrypoint_4(bytes, 4);
    gsmaker_entrypoint_11(file, unaligned + 1);
    rare_memcpy(&value, unaligned + 1, 4); CHECK(value == 0x15123456);
    gsmaker_entrypoint_0(file);
    file = gsmaker_entrypoint_5();
    gsmaker_entrypoint_11(file, unaligned + 1);
    gsmaker_entrypoint_6(file, &buffer, &size);
    CHECK(size == 4); check_equal(buffer, bytes, 4); heap_free(buffer);
}

static void test_asset_streams(void) {
    GsFile *files[15], *file;
    s32 i;
    CHECK(!gsmaker_entrypoint_1(3));
    for (i = 0; i < 15; ++i) {
        files[i] = gsmaker_entrypoint_1(1);
        CHECK(files[i] && func_800D7138(1) == i + 1);
    }
    CHECK(!gsmaker_entrypoint_1(1) && func_800D7138(1) == 15);
    CHECK(!gsmaker_entrypoint_1(-1) && !gsmaker_entrypoint_1(INT32_MAX));
    CHECK(!gsmaker_entrypoint_1(native_asset_count()));
    CHECK(!gsmaker_entrypoint_3(INT32_MAX, 1) && !gsmaker_entrypoint_3(INT32_MIN, -1));
    CHECK(!gsmaker_entrypoint_1(3) && func_800D7138(1) == 15);
    for (i = 0; i < 15; ++i) {
        CHECK(files[i]->asset_base_ptr == files[0]->asset_base_ptr);
        values(files[i], 0);
    }
    for (i = 14; i >= 0; --i) {
        gsmaker_entrypoint_0(files[i]);
        CHECK(i ? func_800D7138(1) == i : !func_800D73CC(1));
    }
    file = gsmaker_entrypoint_3(1, 1); CHECK(file); values(file, 0); gsmaker_entrypoint_0(file);
    file = gsmaker_entrypoint_2(0xAD); CHECK(file && file->asset_id == 0xA02);
    values(file, 0); gsmaker_entrypoint_0(file);
    CHECK(!func_800D73CC(1) && !func_800D73CC(2) && !func_800D73CC(0xA02));
    CHECK(func_800D674C(1));
    for (i = 0; i < 15; ++i) func_800D71F4(1);
    CHECK(func_800D7138(1) == 0 && !gsmaker_entrypoint_1(1));
    for (i = 0; i < 15; ++i) CHECK(func_800D721C(1, 0));
    CHECK(func_800D6CEC(1) == 0);
}

static void test_archive(void) {
    s32 id, count = 0, size;
    for (id = 0; id < native_asset_count(); ++id) {
        GsFile *file;
        void *expected, *actual;
        if ((native_asset_flags(id) & 15) != 10) continue;
        expected = native_asset_load(id, &size); CHECK(expected && size > 0);
        file = gsmaker_entrypoint_2(id - 0x955); CHECK(file);
        CHECK(file->end_ptr - file->asset_base_ptr == size);
        actual = heap_alloc(size);
        gsmaker_entrypoint_13(file, actual, size); CHECK(!file->failed);
        check_equal(actual, expected, size);
        CHECK(!gsmaker_entrypoint_16(file, 0) && file->failed);
        gsmaker_entrypoint_0(file); heap_free(actual); heap_free(expected);
        CHECK(!func_800D73CC(id)); ++count;
    }
    CHECK(count > 0); printf("Read %d original database assets through gs/maker.\n", count);
}

int main(int argc, char **argv) {
    CHECK(argc >= 2);
    test_memory_streams(); test_invalid_streams();
    CHECK(native_assets_open(argv[1]));
    if (argc == 3) test_asset_streams(); else test_archive();
    native_assets_shutdown();
    puts("Native game stream serialization, bounds and asset ownership passed.");
    return 0;
}
