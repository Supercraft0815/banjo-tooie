#include "core1/inflate_tables.h"
#include "bt_data.h"

const InflateTables core1_inflate_tables BT_DATA(2, core1_inflate, 0) = {
    BT_INFLATE_MASK_BITS,
    BT_INFLATE_LENGTH_BASE,
    BT_INFLATE_DISTANCE_BASE,
    BT_INFLATE_CODE_LENGTH_ORDER,
    BT_INFLATE_LENGTH_EXTRA_BITS,
    BT_INFLATE_DISTANCE_EXTRA_BITS,
};
