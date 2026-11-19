#include <stdint.h>
#include "core2/1E7BFA0.h"

#include "core2/1E75920.h"

void func_8009C038(PlayerState *);
void func_8009C08C(PlayerState *);
void func_8009C15C(PlayerState *, f32[3]);
void func_8009C188(PlayerState *, f32[3]);

static int position_history(void) {
    PlayerState player = {0};
    f32 storage[12], out[3];
    f32 position[] = {8.25f, -7.5f, 0.125f};

    player.unkE4 = storage;
    func_8009C038(&player);
    func_8009C0BC(&player, position);
    func_8009C15C(&player, out);
    for (int i = 0; i < 3; i++) if (out[i] != position[i]) return 5;
    storage[0] = 91;
    func_8009C1F8(&player, position);
    func_8009C08C(&player);
    func_8009C128(&player, out);
    if (out[0] != 91 || storage[3] != 91) return 6;
    func_8009C188(&player, out);
    for (int i = 0; i < 3; i++) if (out[i] != position[i] || storage[i + 9] != 0) return 7;
    return 0;
}

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
    if (fields[9] != 0.0f || fields[10] != 0.0f) return 5;
    return position_history();
}
