#ifndef BT_MOD_ASSETS_H
#define BT_MOD_ASSETS_H
#include <stdint.h>

uint32_t bt_mod_asset_read(uint32_t id, void *destination, uint32_t capacity);
void bt_mod_asset_dump(uint32_t id, const void *bytes, uint32_t size);
#endif
