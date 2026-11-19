#include "common.h"
#include "memory.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define CHECK(condition) do { if (!(condition)) { \
    fprintf(stderr, "asset decoder line %d: %s\n", __LINE__, #condition); exit(1); \
} } while (0)

enum { asset_count = 4, bank_size = 32768, dma_size = 0x1800 };
static u8 rom[asset_count][bank_size], expected[asset_count][bank_size];
static size_t raw_size[asset_count];
static int reads[asset_count], writebacks;

s32 func_800E488C(s32 asset);
s32 func_800E4AF0(s32 asset);
s32 func_800E4BB8(s32 asset);
void *func_800E4BF4(s32 asset);
void func_800E4C7C(void);
void func_800E4CE8(void);

s32 func_800D5A6C(s32 asset) {
    CHECK(asset >= 1 && asset <= asset_count);
    return asset * bank_size;
}

void func_8001311C(u8 *out, s32 offset) {
    int bank = offset / bank_size - 1;
    int start = offset % bank_size;
    CHECK(bank >= 0 && bank < asset_count && start + dma_size <= bank_size);
    reads[bank]++;
    for (int i = 0; i < dma_size; i++) out[i] = rom[bank][start + i];
}

void osWritebackDCache(void *ptr, s32 size) {
    CHECK(ptr && size > 0);
    writebacks++;
}

static size_t load(const char *path, u8 *dst) {
    FILE *stream = fopen(path, "rb");
    CHECK(stream);
    size_t size = fread(dst, 1, bank_size, stream);
    CHECK(size && size < bank_size && !ferror(stream));
    CHECK(fclose(stream) == 0);
    return size;
}

int main(int argc, char **argv) {
    CHECK(argc == 1 + 2 * asset_count);
    for (int i = 0; i < asset_count; i++) {
        load(argv[1 + 2 * i], rom[i]);
        raw_size[i] = load(argv[2 + 2 * i], expected[i]);
        CHECK(!func_800E4AF0(i + 1));
        CHECK(!func_800E488C(i + 1));
        CHECK(func_800E4AF0(i + 1));
    }
    CHECK(!func_800E488C(9));
    CHECK(!func_800E4AF0(9));
    func_800E4C7C();
    for (int i = asset_count - 1; i >= 0; i--) {
        u8 *asset = func_800E4BF4(i + 1);
        CHECK((uintptr_t)asset > UINT32_MAX);
        CHECK(!func_800E4AF0(i + 1));
        for (size_t pos = 0; pos < raw_size[i]; pos++) CHECK(asset[pos] == expected[i][pos]);
        heap_free(asset);
    }
    CHECK(writebacks == asset_count && reads[0] > 1);
    CHECK(!func_800E488C(2));
    CHECK(func_800E4BB8(2));
    CHECK(!func_800E4BB8(2));
    func_800E4CE8();
    return 0;
}
