#include "core1/trig_tables.h"
#include <stdio.h>

f32 func_80013AAC(f32);
f32 func_800138D0(f32);

static void dump(const void *table, size_t size) {
    const unsigned char *bytes = table;
    for (size_t i = 0; i < size; ++i) printf("%02x", bytes[i]);
}

int main(void) {
    if (func_80013AAC(-1.0f) != -90.0f || func_80013AAC(1.0f) != 90.0f ||
        func_80013AAC(0.0f) != 0.0f || func_800138D0(0.0f) != 1.0f) return 1;
    dump(D_8003CC90, sizeof(D_8003CC90));
    dump(&D_8003CCA0, sizeof(D_8003CCA0));
    dump(D_8003D3A0, sizeof(D_8003D3A0));
    return 0;
}
