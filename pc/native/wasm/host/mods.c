#include <stdlib.h>
#include "guest.h"
#include "mod_assets.h"

u32 w2c_env_asset_override(struct w2c_env *env, u32 id, u32 dst, u32 capacity) {
    (void)env;
    if (!dst) return capacity ? 0 : bt_mod_asset_read(id, NULL, 0);
    if (!capacity || dst > bt_inst.w2c_memory.size || capacity > bt_inst.w2c_memory.size - dst) return 0;
    return bt_mod_asset_read(id, G_range(dst, capacity), capacity);
}

void w2c_env_asset_dump(struct w2c_env *env, u32 id, u32 src, u32 size) {
    (void)env;
    if (getenv("BT_ASSET_DUMP") && src && src <= bt_inst.w2c_memory.size && size <= bt_inst.w2c_memory.size - src)
        bt_mod_asset_dump(id, G_range(src, size), size);
}
