#include "common.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define CHECK(x) do { if (!(x)) { fprintf(stderr, "%s:%d: %s\n", __FILE__, __LINE__, #x); exit(1); } } while (0)

static BtIntPtr expected_player;
static int predicate_seen;
static int shoes_seen;
static int sound_seen;

s32 func_8008E39C(BtIntPtr player) {
    CHECK(player == expected_player);
    predicate_seen++;
    return 1;
}

int _bashoes_entrypoint_6(void *player, s32 shoe_state) {
    CHECK((BtIntPtr)(uintptr_t)player == expected_player);
    CHECK(shoe_state == 2);
    shoes_seen++;
    return 0;
}

void func_800F9A6C(void) { sound_seen++; }
void baduo_entrypoint_12(BtIntPtr);

int main(void) {
    expected_player = (BtIntPtr)UINT64_C(0x12345678AABBCCDD);
    baduo_entrypoint_12(expected_player);
    CHECK(predicate_seen == 1 && shoes_seen == 1 && sound_seen == 1);
    return 0;
}
