#include "mod_assets.h"
#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#ifdef _WIN32
#include <direct.h>
#define mkdir(path, mode) _mkdir(path)
#endif

#define MOD_ASSET_MAX (64u * 1024u * 1024u)

static int package_name(const char *name, size_t n) {
    if (!n || n > 63)
        return 0;
    for (size_t i = 0; i < n; i++)
        if (!(isalnum((unsigned char)name[i]) || name[i] == '_' || name[i] == '-'))
            return 0;
    return 1;
}

uint32_t bt_mod_asset_read(uint32_t id, void *dst, uint32_t capacity) {
    const char *order = getenv("BT_MOD_ORDER");
    char path[512], package[64];
    if (!order || !*order || id >= 0x4000)
        return 0;
    while (*order) {
        const char *end = strchr(order, ',');
        size_t n = end ? (size_t)(end - order) : strlen(order);
        if (!package_name(order, n))
            return 0;
        memcpy(package, order, n);
        package[n] = 0;
        snprintf(path, sizeof path, "mods/%s/assets/%08x.bin", package, id);
        FILE *f = fopen(path, "rb");
        if (f) {
            long size;
            if (fseek(f, 0, SEEK_END) || (size = ftell(f)) <= 0 || (unsigned long)size > MOD_ASSET_MAX ||
                fseek(f, 0, SEEK_SET)) {
                fclose(f);
                return 0;
            }
            if (!dst && !capacity) {
                fclose(f);
                return (uint32_t)size;
            }
            if (!dst || (uint32_t)size > capacity) {
                fclose(f);
                return 0;
            }
            void *bytes = malloc((size_t)size);
            if (!bytes) {
                fclose(f);
                return 0;
            }
            size_t got = fread(bytes, 1, (size_t)size, f);
            fclose(f);
            if (got == (size_t)size)
                memcpy(dst, bytes, got);
            free(bytes);
            return got == (size_t)size ? (uint32_t)size : 0;
        }
        if (!end)
            break;
        order = end + 1;
    }
    return 0;
}

void bt_mod_asset_dump(uint32_t id, const void *src, uint32_t size) {
    const char *dir = getenv("BT_ASSET_DUMP");
    char path[512];
    if (!dir || !*dir || id >= 0x4000 || !src || !size)
        return;
    if (mkdir(dir, 0777) && errno != EEXIST)
        return;
    if (snprintf(path, sizeof path, "%s/%08x.bin", dir, id) >= (int)sizeof path)
        return;
    FILE *f = fopen(path, "rb");
    if (f) {
        fclose(f);
        return;
    }
    f = fopen(path, "wb");
    if (!f)
        return;
    int ok = fwrite(src, 1, size, f) == size;
    if (fclose(f) != 0 || !ok)
        remove(path);
}
