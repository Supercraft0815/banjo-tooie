#ifndef BT_MOD_TEXTURE_H
#define BT_MOD_TEXTURE_H
#include <stdint.h>
#include <stddef.h>
uint64_t bt_mod_texture_hash(int format, int size, int width, int height, const uint32_t *rgba);
void bt_mod_texture_dump(uint64_t hash, int width, int height, const uint32_t *rgba);
void bt_mod_texture_init(const char *order);
void bt_mod_texture_init_rom(const char *order, const char *rom_id);
int bt_mod_texture_rice_tmem_unpack(const uint8_t *tmem, size_t tmem_size, uint32_t base, uint32_t row_bytes,
                                      int width, int height, int size, uint8_t *out, size_t out_size, int *stride);
uint32_t bt_mod_texture_rice_crc32(const uint8_t *data, int width, int height, int size, int stride);
int bt_mod_texture_rice_max_index(const uint8_t *data, int width, int height, int size, int stride);
uint32_t bt_mod_texture_rice_palette_crc(const uint8_t *palette, int max_index, int size);
uint32_t *bt_mod_texture_load_rice(uint32_t texture_crc, uint32_t palette_crc, int format, int size, int width, int height, int *replacement_width, int *replacement_height);
uint32_t *bt_mod_texture_load_best(uint64_t hash, int width, int height, int rice_valid,
                                   uint32_t texture_crc, uint32_t palette_crc, int format, int size,
                                   int *replacement_width, int *replacement_height, int *rice_selected);
void bt_mod_texture_shutdown(void);
int bt_mod_texture_active(void);
uint32_t *bt_mod_texture_load(uint64_t hash, int width, int height, int *replacement_width, int *replacement_height);
#endif
