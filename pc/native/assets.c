#include "native_assets.h"
#include "native_model.h"
#include "core2/animation_resource.h"
#include "memory.h"
#include "overlays/gl/dbDll.h"
#include <stdio.h>
#include <stdlib.h>
#include <zlib.h>

static FILE *archive;
static u32 *entries;
static s32 asset_count;
static u32 payload_start;

static u32 read_be32(const u8 *data) {
    return (u32)data[0] << 24 | (u32)data[1] << 16 | (u32)data[2] << 8 | data[3];
}

int native_asset_model_animation(s32 id, const void *model, NativeModelAnimationChannel output[7]) {
    s32 size = native_asset_cached_size(id), i;
    const u8 *bytes = model;
    u32 offset;
    if (!model || !output || size < 0x30) return -1;
    offset = ((const u32 *)model)[11];
    if (!offset) return 0;
    if (offset > (u32)size || 56 > (u32)size - offset) return -1;
    for (i = 0; i < 7; ++i) {
        bytes = (const u8 *)model + offset + i * 8;
        output[i].step = (u16)bytes[0] << 8 | bytes[1];
        output[i].count = (u16)bytes[2] << 8 | bytes[3];
        output[i].rate_bits = read_be32(bytes + 4);
    }
    return 1;
}

int native_assets_open(const char *path) {
    FILE *file;
    long size;
    u8 header[8];
    u32 count, base, i, previous = 0;
    u32 *table;
    if (!path || archive) return 0;
    file = fopen(path, "rb");
    if (!file) return 0;
    if (fseek(file, 0, SEEK_END) || (size = ftell(file)) < 8 ||
        size > 64 * 1024 * 1024 || fseek(file, 0, SEEK_SET) ||
        fread(header, 1, sizeof(header), file) != sizeof(header)) {
        fclose(file);
        return 0;
    }
    count = read_be32(header);
    base = 8 + count * 4;
    if (count < 2 || count > 0x4000 || base > (u32)size) {
        fclose(file);
        return 0;
    }
    table = malloc(count * sizeof(*table));
    if (!table || fread(table, sizeof(*table), count, file) != count) {
        free(table);
        fclose(file);
        return 0;
    }
    for (i = 0; i < count; ++i) {
        u32 word = read_be32((u8 *)&table[i]);
        u32 offset = word >> 6;
        if (offset < previous || offset > (u32)size - base) {
            free(table);
            fclose(file);
            return 0;
        }
        table[i] = word;
        previous = offset;
    }
    archive = file;
    entries = table;
    asset_count = count - 1;
    payload_start = base;
    func_800D5D70();
    return 1;
}

void native_assets_close(void) {
    native_assets_shutdown();
    if (!archive) return;
    fclose(archive);
    free(entries);
    archive = NULL;
    entries = NULL;
    asset_count = 0;
    payload_start = 0;
}

s32 native_asset_count(void) { return asset_count; }

u32 native_asset_flags(BtIntPtr id) {
    return id >= 0 && id < asset_count ? entries[id] & 63 : UINT32_MAX;
}

s32 native_asset_packed_size(s32 id) {
    if (id < 0 || id >= asset_count) return -1;
    return (entries[id + 1] >> 6) - (entries[id] >> 6);
}

s32 native_asset_rom_offset(s32 id) {
    if (id < 0 || id >= asset_count) return -1;
    /* Preserve logical cartridge addresses for game callers; no host pointer is encoded. */
    return 0x5180 + payload_start + (entries[id] >> 6);
}

void *native_asset_load(s32 id, s32 *size) {
    s32 packed_size = native_asset_packed_size(id);
    u32 flags = native_asset_flags(id);
    u8 *packed, *data;
    s32 output_size;
    if (!archive || !size || packed_size <= 0) return NULL;
    packed = heap_alloc((packed_size + 1) & ~1);
    if (packed_size & 1) packed[packed_size] = 0;
    if (fseek(archive, payload_start + (entries[id] >> 6), SEEK_SET) ||
        fread(packed, 1, packed_size, archive) != (size_t)packed_size) {
        heap_free(packed);
        return NULL;
    }
    if ((flags & 15) == 10)
        func_808000E8_gldbDll((s32 *)packed, id - 0x955, packed_size);
    data = packed;
    output_size = (packed_size + 1) & ~1;
    if ((flags & 16) || (flags & 15) == 10) {
        z_stream stream = {0};
        int result;
        if (packed_size < 3) { heap_free(packed); return NULL; }
        output_size = ((u32)packed[0] << 8 | packed[1]) * 16;
        if (!output_size) { heap_free(packed); return NULL; }
        data = heap_alloc(output_size);
        rare_memset(data, 0, output_size);
        stream.next_in = packed + 2;
        stream.avail_in = packed_size - 2;
        stream.next_out = data;
        stream.avail_out = output_size;
        result = inflateInit2(&stream, -15);
        if (result == Z_OK) {
            result = inflate(&stream, Z_FINISH);
            inflateEnd(&stream);
        }
        heap_free(packed);
        if (result != Z_STREAM_END) { heap_free(data); return NULL; }
    }
    if ((flags & 15) == 0 && !native_model_decode(data, output_size)) {
        heap_free(data);
        return NULL;
    }
    if ((flags & 15) == 9) {
        /* Music sequence: u32 division, u32 track count, u32 track offsets; the tracks are bytes. */
        u32 tracks = output_size >= 8 ? read_be32(data + 4) : UINT32_MAX;
        if (tracks > 32 || (u32)output_size < (2 + tracks) * 4) { heap_free(data); return NULL; }
        for (u32 i = 0; i < 2 + tracks; ++i) { u32 word = read_be32(data + i * 4); rare_memcpy(data + i * 4, &word, 4); }
    }
    if ((flags & 15) == 6) {
        s16 *animation = native_animation_decode(data, output_size);
        heap_free(data);
        if (!animation) return NULL;
        data = (u8 *)animation;
    }
    *size = output_size;
    return data;
}

s32 native_asset_read_into(s32 id, void *destination, s32 capacity) {
    s32 size;
    void *data;
    if (!destination || capacity < 0) return 0;
    data = native_asset_load(id, &size);
    if (!data) return 0;
    if (capacity < size) { heap_free(data); return 0; }
    rare_memcpy(destination, data, size);
    heap_free(data);
    if ((native_asset_flags(id) & 16) || (native_asset_flags(id) & 15) == 10) {
        func_800D5FDC(size);
        return size;
    }
    return (size + 15) & ~15;
}
