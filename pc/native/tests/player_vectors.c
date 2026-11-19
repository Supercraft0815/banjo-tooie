#include <stdint.h>
#include "core2/1E7BFA0.h"

int main(void) {
    PlayerState player = {0};
    f32 fields[14] = {0};
    f32 values[3] = {-2.5f, 16.0f, 0.125f};
    f32 result[3] = {0};
    void (*write_vector[])(PlayerState *, f32 *) = {
        func_800A34AC, func_800A34F0, func_800A3514
    };
    void (*read_vector[])(PlayerState *, f32 *) = {
        func_800A32C4, func_800A33A0, func_800A33CC, func_800A3328
    };
    player.unkA0 = fields;
    if (sizeof(void *) > 4 && (uintptr_t)fields <= UINT32_MAX) return 1;
    for (int i = 0; i < 3; i++) {
        values[0] -= 1.0f;
        write_vector[i](&player, values);
        for (int j = 0; j < 3; j++) if (fields[3 * i + j] != values[j]) return 2;
        read_vector[i](&player, result);
        for (int j = 0; j < 3; j++) if (result[j] != values[j]) return 3;
    }
    for (int j = 0; j < 3; j++) fields[11 + j] = -values[j];
    read_vector[3](&player, result);
    for (int j = 0; j < 3; j++) if (result[j] != fields[11 + j]) return 4;
    return fields[9] != 0.0f || fields[10] != 0.0f;
}
