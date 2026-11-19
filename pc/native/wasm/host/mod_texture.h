#ifndef BT_MOD_TEXTURE_H
#define BT_MOD_TEXTURE_H
#include <stdint.h>
#include <stddef.h>
uint64_t bt_mod_texture_hash(int format, int size, int width, int height, const uint32_t *rgba);
void bt_mod_texture_dump(uint64_t hash, int width, int height, const uint32_t *rgba);
void bt_mod_texture_init(const char *order);
void bt_mod_texture_shutdown(void);
int bt_mod_texture_active(void);
uint32_t *bt_mod_texture_load(uint64_t hash, int width, int height, int *replacement_width, int *replacement_height);
#endif
