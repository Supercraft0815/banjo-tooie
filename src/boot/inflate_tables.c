#include "core1/inflate_tables.h"
#include "bt_data.h"

s32 D_80004240 BT_DATA(4, boot_inflate_state, 0) = 0;
s32 D_80004244 BT_DATA(4, boot_inflate_state, 4) = 0;

const InflateTables boot_inflate_tables BT_DATA(2, boot_inflate, 0) = {
    BT_INFLATE_MASK_BITS,
    BT_INFLATE_LENGTH_BASE,
    BT_INFLATE_DISTANCE_BASE,
    BT_INFLATE_CODE_LENGTH_ORDER,
    BT_INFLATE_LENGTH_EXTRA_BITS,
    BT_INFLATE_DISTANCE_EXTRA_BITS,
};
