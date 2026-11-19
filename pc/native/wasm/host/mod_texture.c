#include "mod_texture.h"
#define STB_IMAGE_IMPLEMENTATION
#define STBI_ONLY_PNG
#include "../../third_party/stb_image.h"
#include <dirent.h>
#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#ifdef _WIN32
#include <direct.h>
#endif
#include <zlib.h>

static const unsigned char signature[8] = {137, 80, 78, 71, 13, 10, 26, 10};
typedef struct {
    uint64_t hash;
    char path[512];
    int base_w, base_h;
    int w, h;
    uint32_t *pixels;
} ModTexture;
static ModTexture *indexed;
static size_t indexed_n, indexed_cap;

void bt_mod_texture_shutdown(void) {
    for (size_t i = 0; i < indexed_n; i++)
        stbi_image_free(indexed[i].pixels);
    free(indexed);
    indexed = NULL;
    indexed_n = indexed_cap = 0;
}

int bt_mod_texture_active(void) { return indexed_n != 0; }

static int index_png(const char *path, const char *leaf) {
    char key[17] = {0};
    unsigned named_w, named_h;
    int end = 0, w, h, channels;
    if (sscanf(leaf, "%16[0123456789abcdefABCDEF]_%5ux%5u.png%n", key, &named_w, &named_h, &end) != 3 ||
        strlen(key) != 16 || !end || leaf[end] || !named_w || !named_h)
        return 1;
    if (!stbi_info(path, &w, &h, &channels) || w < 1 || h < 1 || w > UINT16_MAX || h > UINT16_MAX)
        return 1;
    if (indexed_n == indexed_cap) {
        size_t cap = indexed_cap ? indexed_cap * 2 : 32;
        if (cap < indexed_cap || cap > SIZE_MAX / sizeof *indexed)
            return 0;
        ModTexture *next = realloc(indexed, cap * sizeof *indexed);
        if (!next)
            return 0;
        indexed = next;
        indexed_cap = cap;
    }
    ModTexture *entry = &indexed[indexed_n++];
    *entry = (ModTexture){.hash = strtoull(key, NULL, 16), .base_w = (int)named_w,
                          .base_h = (int)named_h, .w = w, .h = h};
    memcpy(entry->path, path, strlen(path) + 1);
    return 1;
}

void bt_mod_texture_init(const char *order) {
    bt_mod_texture_shutdown();
    while (order && *order) {
        const char *end = strchr(order, ',');
        size_t n = end ? (size_t)(end - order) : strlen(order);
        char dirpath[96];
        if (!n || n > 63)
            return;
        for (size_t i = 0; i < n; i++)
            if (!(isalnum((unsigned char)order[i]) || order[i] == '_' || order[i] == '-'))
                return;
        snprintf(dirpath, sizeof dirpath, "mods/%.*s/textures", (int)n, order);
        DIR *dir = opendir(dirpath);
        if (dir) {
            struct dirent *entry;
            while ((entry = readdir(dir))) {
                char path[512];
                if (entry->d_name[0] == '.' ||
                    snprintf(path, sizeof path, "%s/%s", dirpath, entry->d_name) >= (int)sizeof path)
                    continue;
                if (!index_png(path, entry->d_name)) {
                    closedir(dir);
                    return;
                }
            }
            closedir(dir);
        }
        if (!end)
            break;
        order = end + 1;
    }
}

static void put_be32(unsigned char *p, uint32_t v) {
    p[0] = v >> 24;
    p[1] = v >> 16;
    p[2] = v >> 8;
    p[3] = v;
}

static int write_chunk(FILE *f, const char type[4], const void *data, size_t size) {
    unsigned char word[4];
    uLong crc;
    if (size > UINT32_MAX || size > UINT_MAX)
        return 0;
    put_be32(word, (uint32_t)size);
    if (fwrite(word, 1, sizeof word, f) != sizeof word || fwrite(type, 1, 4, f) != 4 ||
        (size && fwrite(data, 1, size, f) != size))
        return 0;
    crc = crc32(0L, Z_NULL, 0);
    crc = crc32(crc, (const Bytef *)type, 4);
    if (size)
        crc = crc32(crc, (const Bytef *)data, (uInt)size);
    put_be32(word, (uint32_t)crc);
    return fwrite(word, 1, sizeof word, f) == sizeof word;
}

uint64_t bt_mod_texture_hash(int format, int size, int width, int height, const uint32_t *rgba) {
    const unsigned char *p = (const unsigned char *)rgba;
    uint64_t h = UINT64_C(14695981039346656037);
    uint32_t meta[4] = {(uint32_t)format, (uint32_t)size, (uint32_t)width, (uint32_t)height};
    for (int i = 0; i < 4; i++)
        for (int b = 0; b < 4; b++)
            h = (h ^ (unsigned char)(meta[i] >> (b * 8))) * UINT64_C(1099511628211);
    for (size_t i = 0, n = (size_t)width * height * 4; i < n; i++)
        h = (h ^ p[i]) * UINT64_C(1099511628211);
    return h;
}

static int png_write(const char *path, int w, int h, const uint32_t *rgba) {
    if (w <= 0 || h <= 0 || w > 1024 || h > 1024)
        return 0; /* GPU tiles are at most 1024 by 1024. */
    size_t raw_size = ((size_t)w * 4 + 1) * h;
    unsigned char *raw = malloc(raw_size), *compressed = NULL, chunk[13];
    uLongf compressed_size;
    FILE *f = NULL;
    if (!raw)
        return 0;
    for (int y = 0; y < h; y++) {
        raw[(size_t)y * (w * 4 + 1)] = 0;
        memcpy(raw + (size_t)y * (w * 4 + 1) + 1, (const unsigned char *)rgba + (size_t)y * w * 4,
               (size_t)w * 4);
    }
    compressed_size = compressBound((uLong)raw_size);
    compressed = malloc(compressed_size);
    if (!compressed || compress2(compressed, &compressed_size, raw, (uLong)raw_size, Z_BEST_SPEED) != Z_OK)
        goto done;
    f = fopen(path, "wb");
    if (!f)
        goto done;
    if (fwrite(signature, 1, sizeof signature, f) != sizeof signature)
        goto done;
    put_be32(chunk, (uint32_t)w);
    put_be32(chunk + 4, (uint32_t)h);
    chunk[8] = 8;
    chunk[9] = 6;
    chunk[10] = chunk[11] = chunk[12] = 0;
    int ok = write_chunk(f, "IHDR", chunk, sizeof chunk) &&
             write_chunk(f, "IDAT", compressed, (size_t)compressed_size) && write_chunk(f, "IEND", NULL, 0) &&
             !ferror(f);
    if (fclose(f))
        ok = 0;
    f = NULL;
    if (!ok) {
        remove(path);
        goto done;
    }
    free(raw);
    free(compressed);
    return 1;
done:
    if (f) {
        fclose(f);
        remove(path);
    }
    free(raw);
    free(compressed);
    return 0;
}

static int path_for(char *out, size_t cap, const char *dir, uint64_t hash, int w, int h) {
    int n = snprintf(out, cap, "%s/%016llx_%dx%d.png", dir, (unsigned long long)hash, w, h);
    return n > 0 && (size_t)n < cap;
}
void bt_mod_texture_dump(uint64_t hash, int w, int h, const uint32_t *rgba) {
    const char *dir = getenv("BT_TEX_DUMP");
    char path[1024];
    if (!dir || !*dir || !path_for(path, sizeof path, dir, hash, w, h))
        return;
    FILE *f = fopen(path, "rb");
    if (f) {
        fclose(f);
        return;
    }
#ifdef _WIN32
    _mkdir(dir);
#else
    mkdir(dir, 0777);
#endif
    png_write(path, w, h, rgba);
}
uint32_t *bt_mod_texture_load(uint64_t hash, int w, int h, int *rw, int *rh) {
    if (w <= 0 || h <= 0 || !rw || !rh)
        return NULL;
    for (size_t i = 0; i < indexed_n; i++) {
        ModTexture *entry = &indexed[i];
        if (entry->hash != hash || entry->base_w != w || entry->base_h != h ||
            entry->w % w || entry->h % h || entry->w / w < 2 ||
            entry->w / w != entry->h / h)
            continue;
        if (!entry->pixels) {
            int width, height;
            uint32_t *pixels = (uint32_t *)stbi_load(entry->path, &width, &height, NULL, 4);
            if (!pixels || width != entry->w || height != entry->h) {
                stbi_image_free(pixels);
                continue;
            }
            entry->pixels = pixels;
        }
        *rw = entry->w;
        *rh = entry->h;
        return entry->pixels;
    }
    return NULL;
}
