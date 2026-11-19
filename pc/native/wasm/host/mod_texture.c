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
    uint32_t rice_texture, rice_palette;
    int rice_format, rice_size, rice_priority, package_rank;
    unsigned char is_rice;
    char path[512];
    int base_w, base_h;
    int w, h;
    uint32_t *pixels;
} ModTexture;
static ModTexture *indexed;
static size_t indexed_n, indexed_cap;
static char rice_rom_id[32];
static int current_package_rank;

void bt_mod_texture_shutdown(void) {
    for (size_t i = 0; i < indexed_n; i++)
        stbi_image_free(indexed[i].pixels);
    free(indexed);
    indexed = NULL;
    indexed_n = indexed_cap = 0;
}

int bt_mod_texture_active(void) { return indexed_n != 0; }

static int ascii_case_equal(const char *a, const char *b) {
    while (*a && *b) {
        if (tolower((unsigned char)*a++) != tolower((unsigned char)*b++)) return 0;
    }
    return !*a && !*b;
}

static int rice_suffix(const char *s) {
    if (ascii_case_equal(s, "all.png")) return 0;
    if (ascii_case_equal(s, "ciByRGBA.png")) return 1;
    if (ascii_case_equal(s, "allciByRGBA.png")) return 2;
    return -1;
}

static int parse_rice_name(const char *leaf, uint32_t *crc, uint32_t *pal, int *fmt, int *siz,
                           int *priority) {
    char prefix[40];
    int n, f, z, suffix;
    uint32_t c, p = 0;
    if (!rice_rom_id[0]) return 0;
    n = snprintf(prefix, sizeof prefix, "%s#", rice_rom_id);
    if (n <= 0 || (size_t)n >= sizeof prefix) return 0;
    for (int i = 0; i < n; i++)
        if (tolower((unsigned char)leaf[i]) != tolower((unsigned char)prefix[i])) return 0;
    const char *q = leaf + n;
    if (strlen(q) < 8 + 1 + 1 + 1 + 1 + 7) return 0;
    for (int i = 0; i < 8; i++) if (!isxdigit((unsigned char)q[i])) return 0;
    if (q[8] != '#' || !isxdigit((unsigned char)q[9]) || q[10] != '#' ||
        !isxdigit((unsigned char)q[11])) return 0;
    char field[9];
    memcpy(field, q, 8); field[8] = 0;
    c = (uint32_t)strtoul(field, NULL, 16);
    f = (int)strtoul(q + 9, NULL, 16);
    z = (int)strtoul(q + 11, NULL, 16);
    q += 12;
    if (*q == '#') {
        q++;
        for (int i = 0; i < 8; i++) if (!isxdigit((unsigned char)q[i])) return 0;
        if (q[8] != '_') return 0;
        memcpy(field, q, 8); field[8] = 0;
        p = (uint32_t)strtoul(field, NULL, 16);
        q += 9;
    } else if (*q == '_') q++;
    else return 0;
    suffix = rice_suffix(q);
    if (suffix < 0) return 0;
    *crc = c; *pal = p; *fmt = f; *siz = z; *priority = suffix;
    return 1;
}

static int index_png(const char *path, const char *leaf) {
    char key[17] = {0};
    unsigned named_w, named_h;
    uint32_t rice_texture = 0, rice_palette = 0;
    int rice_format = 0, rice_size = 0, rice_priority = 0, is_rice = 0;
    int end = 0, w, h, channels;
    if (sscanf(leaf, "%16[0123456789abcdefABCDEF]_%5ux%5u.png%n", key, &named_w, &named_h, &end) != 3 ||
        strlen(key) != 16 || !end || leaf[end] || !named_w || !named_h) {
        if (!parse_rice_name(leaf, &rice_texture, &rice_palette, &rice_format, &rice_size, &rice_priority))
            return 1;
        is_rice = 1;
        named_w = named_h = 0;
    }
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
    *entry = (ModTexture){.hash = is_rice ? 0 : strtoull(key, NULL, 16),
                          .rice_texture = rice_texture, .rice_palette = rice_palette,
                          .rice_format = rice_format, .rice_size = rice_size,
                          .rice_priority = rice_priority, .package_rank = current_package_rank,
                          .is_rice = (unsigned char)is_rice, .base_w = (int)named_w,
                          .base_h = (int)named_h, .w = w, .h = h};
    memcpy(entry->path, path, strlen(path) + 1);
    return 1;
}

void bt_mod_texture_init(const char *order) { bt_mod_texture_init_rom(order, NULL); }

void bt_mod_texture_init_rom(const char *order, const char *rom_id) {
    bt_mod_texture_shutdown();
    rice_rom_id[0] = 0;
    if (rom_id && *rom_id) {
        size_t n = strlen(rom_id);
        while (n && rom_id[n - 1] == ' ') n--;
        if (n && n < sizeof rice_rom_id) {
            int valid = 1;
            for (size_t i = 0; i < n; i++) {
                unsigned char c = (unsigned char)rom_id[i];
                if (!isprint(c) || c == '/' || c == '\\' || c == '#') { valid = 0; break; }
                rice_rom_id[i] = c == ':' ? '-' : (char)c;
            }
            if (valid) rice_rom_id[n] = 0;
            else rice_rom_id[0] = 0;
        }
    }
    current_package_rank = 0;
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
        current_package_rank++;
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
static ModTexture *find_hash(uint64_t hash, int w, int h) {
    for (size_t i = 0; i < indexed_n; i++) {
        ModTexture *entry = &indexed[i];
        if (entry->is_rice || entry->hash != hash || entry->base_w != w || entry->base_h != h ||
            entry->w % w || entry->h % h || entry->w / w < 2 || entry->w / w != entry->h / h)
            continue;
        return entry;
    }
    return NULL;
}

static ModTexture *find_rice(uint32_t texture_crc, uint32_t palette_crc, int format, int size,
                             int width, int height) {
    int package = INT_MAX, key_rank = INT_MAX, suffix_rank = INT_MAX;
    ModTexture *best = NULL;
    for (size_t i = 0; i < indexed_n; i++) {
        ModTexture *entry = &indexed[i];
        if (!entry->is_rice || entry->rice_texture != texture_crc ||
            entry->rice_format != format || entry->rice_size != size ||
            entry->w % width || entry->h % height || entry->w / width < 2 ||
            entry->w / width != entry->h / height) continue;
        if (entry->rice_palette && entry->rice_palette != palette_crc) continue;
        int candidate_key_rank = entry->rice_palette ? 0 : 1;
        if (entry->package_rank < package ||
            (entry->package_rank == package && candidate_key_rank < key_rank) ||
            (entry->package_rank == package && candidate_key_rank == key_rank && entry->rice_priority < suffix_rank)) {
            package = entry->package_rank;
            key_rank = candidate_key_rank;
            suffix_rank = entry->rice_priority;
            best = entry;
        }
    }
    return best;
}

static uint32_t *load_entry(ModTexture *entry, int *rw, int *rh) {
    if (!entry) return NULL;
    if (!entry->pixels) {
        int width, height;
        uint32_t *pixels = (uint32_t *)stbi_load(entry->path, &width, &height, NULL, 4);
        if (!pixels || width != entry->w || height != entry->h) {
            stbi_image_free(pixels);
            return NULL;
        }
        entry->pixels = pixels;
    }
    *rw = entry->w; *rh = entry->h;
    if (entry->is_rice && (getenv("BT_RICE_TRACE") || getenv("BT_RICE_HIT_TRACE")))
        fprintf(stderr, "bt_rice: hit=%s %dx%d package=%d suffix=%d\n", entry->path, entry->w, entry->h,
                entry->package_rank, entry->rice_priority);
    return entry->pixels;
}

uint32_t *bt_mod_texture_load(uint64_t hash, int w, int h, int *rw, int *rh) {
    if (w <= 0 || h <= 0 || !rw || !rh) return NULL;
    return load_entry(find_hash(hash, w, h), rw, rh);
}

uint32_t *bt_mod_texture_load_best(uint64_t hash, int width, int height, int rice_valid,
                                   uint32_t texture_crc, uint32_t palette_crc, int format, int size,
                                   int *rw, int *rh, int *rice_selected) {
    if (rice_selected) *rice_selected = 0;
    if (width <= 0 || height <= 0 || !rw || !rh) return NULL;
    ModTexture *native = find_hash(hash, width, height);
    ModTexture *rice = rice_valid ? find_rice(texture_crc, palette_crc, format, size, width, height) : NULL;
    ModTexture *best = rice && (!native || rice->package_rank < native->package_rank) ? rice : native;
    if (!best) return NULL;
    if (rice_selected) *rice_selected = best->is_rice;
    return load_entry(best, rw, rh);
}


int bt_mod_texture_rice_tmem_unpack(const uint8_t *tmem, size_t tmem_size, uint32_t base, uint32_t row_bytes,
                                      int width, int height, int size, uint8_t *out, size_t out_size, int *stride_out) {
    if (!tmem || !tmem_size || !out || !stride_out || size < 0 || size > 3 ||
        width <= 0 || height <= 0 || width > (INT_MAX >> size) || (size == 0 && (width & 1))) return 0;
    size_t stride = ((size_t)width << size) >> 1;
    if (row_bytes < (size == 3 ? ((size_t)width * 2) : stride) ||
        stride > SIZE_MAX / (size_t)height || out_size < stride * (size_t)height) return 0;
    for (int y = 0; y < height; y++) {
        uint32_t row = base + (uint32_t)y * row_bytes;
        uint32_t swizzle = y & 1 ? 4 : 0;
        if (size == 0) {
            for (int x = 0; x < width; x++) {
                size_t a = (size_t)((row + (uint32_t)(x >> 1)) ^ swizzle) % tmem_size;
                uint8_t v = tmem[a];
                size_t d = (size_t)y * stride + (size_t)(x >> 1);
                if (x & 1) out[d] |= v & 0x0f;
                else out[d] = v & 0xf0;
            }
        } else if (size == 1) {
            for (int x = 0; x < width; x++) {
                size_t a = (size_t)((row + (uint32_t)x) ^ swizzle) % tmem_size;
                out[(size_t)y * stride + (size_t)x] = tmem[a];
            }
        } else if (size == 2) {
            for (int x = 0; x < width; x++) {
                uint32_t a = (row + (uint32_t)x * 2) ^ swizzle;
                size_t d = (size_t)y * stride + (size_t)x * 2;
                out[d] = tmem[(size_t)a % tmem_size];
                out[d + 1] = tmem[(size_t)(a + 1) % tmem_size];
            }
        } else {
            for (int x = 0; x < width; x++) {
                uint32_t a = ((row + (uint32_t)x * 2) ^ swizzle) & 0x7ff;
                size_t d = (size_t)y * stride + (size_t)x * 4;
                out[d] = tmem[a];
                out[d + 1] = tmem[a + 1];
                out[d + 2] = tmem[a | 0x800];
                out[d + 3] = tmem[(a + 1) | 0x800];
            }
        }
    }
    *stride_out = (int)stride;
    return 1;
}

uint32_t bt_mod_texture_rice_crc32(const uint8_t *data, int width, int height, int size, int stride) {
    if (!data || width <= 0 || height <= 0 || size < 0 || size > 3) return 0;
    int line = (width << size) >> 1;
    if (line < 4 || stride < line) return 0;
    uint32_t crc = 0;
    for (int y = height - 1; y >= 0; y--) {
        uint32_t last = 0;
        for (int x = line - 4; x >= 0; x -= 4) {
            const uint8_t *p = data + (size_t)y * stride + x;
            uint32_t word = (uint32_t)p[0] | (uint32_t)p[1] << 8 | (uint32_t)p[2] << 16 | (uint32_t)p[3] << 24;
            last = word ^ (uint32_t)x;
            crc = (crc << 4 | crc >> 28) + last;
        }
        crc += last ^ (uint32_t)y;
    }
    return crc;
}

int bt_mod_texture_rice_max_index(const uint8_t *data, int width, int height, int size, int stride) {
    if (!data || width <= 0 || height <= 0 || stride <= 0) return -1;
    int maximum = 0;
    if (size == 0) {
        for (int y = 0; y < height; y++) for (int x = 0; x < width / 2; x++) {
            uint8_t v = data[(size_t)y * stride + x];
            if ((v >> 4) > maximum) maximum = v >> 4;
            if ((v & 15) > maximum) maximum = v & 15;
        }
    } else if (size == 1) {
        for (int y = 0; y < height; y++) for (int x = 0; x < width; x++)
            if (data[(size_t)y * stride + x] > maximum) maximum = data[(size_t)y * stride + x];
    } else return -1;
    return maximum;
}

uint32_t bt_mod_texture_rice_palette_crc(const uint8_t *palette, int max_index, int size) {
    if (!palette || max_index < 0 || max_index > (size == 0 ? 15 : 255)) return 0;
    return bt_mod_texture_rice_crc32(palette, max_index + 1, 1, 2, size == 0 ? 32 : 512);
}

uint32_t *bt_mod_texture_load_rice(uint32_t texture_crc, uint32_t palette_crc,
                                   int format, int size, int width, int height,
                                   int *rw, int *rh) {
    if (width <= 0 || height <= 0 || !rw || !rh) return NULL;
    return load_entry(find_rice(texture_crc, palette_crc, format, size, width, height), rw, rh);
}
