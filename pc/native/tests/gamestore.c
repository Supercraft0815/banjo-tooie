#define _POSIX_C_SOURCE 200809L
#include "common.h"
#include "threads.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define CHECK(expr) do { if (!(expr)) { fprintf(stderr, "line %d: %s\n", __LINE__, #expr); abort(); } } while (0)

s32 glgamestore_entrypoint_0(s32 slot, BtIntPtr buffer);
s32 glgamestore_entrypoint_1(s32 slot, BtIntPtr buffer);
s32 glgamestore_entrypoint_2(s32 slot, BtIntPtr buffer);
s32 glgamestore_entrypoint_3(s32 slot, BtIntPtr buffer);
s32 glgamestore_entrypoint_4(s32 slot);
s32 glgamestore_entrypoint_5(s32 slot);

u64 D_80079D70[JOY_THREAD_STACK_SIZE64];
static u8 eeprom[0x800], payload[0x1C0], received[0x1C0];
static int io_error, checksum_error, global_valid, crc_calls, reads, writes;
static void *expected_buffer;
static s32 expected_len;

s32 gleeprom_entrypoint_2(s32 offset, u8 *dst, s32 len) {
    CHECK(dst == expected_buffer && len == expected_len);
    CHECK(offset >= 0 && len >= 0 && offset + len <= sizeof(eeprom));
    ++reads;
    if (!io_error) memcpy(dst, eeprom + offset, len);
    return io_error;
}

s32 gleeprom_entrypoint_1(s32 offset, u8 *src, s32 len) {
    CHECK(len == 8 || (src == expected_buffer && len == expected_len));
    CHECK(offset >= 0 && len >= 0 && offset + len <= sizeof(eeprom));
    ++writes;
    if (!io_error) memcpy(eeprom + offset, src, len);
    return io_error;
}

s32 glcrc_entrypoint_1(void *src, BtIntPtr len) {
    CHECK(src == expected_buffer && len == expected_len);
    ++crc_calls;
    return checksum_error;
}

s32 glglobaldata_entrypoint_1(u8 *src) {
    CHECK(src == expected_buffer);
    return global_valid;
}

int main(void) {
    for (unsigned i = 0; i < sizeof(payload); ++i) payload[i] = (u8)(0x41 + i);
    if (sizeof(void *) == 8) CHECK((uintptr_t)payload > UINT32_MAX);
    s32 medium = 2;
    memcpy((u8 *)D_80079D70 + 0x1ec, &medium, sizeof(medium));
    for (int slot = 0; slot < 4; ++slot) {
        expected_len = sizeof(payload);
        expected_buffer = payload;
        CHECK(glgamestore_entrypoint_2(slot, (BtIntPtr)payload) == 0);
        CHECK(memcmp(eeprom + 0x100 + slot * 0x1c0, payload, sizeof(payload)) == 0);
        expected_buffer = received;
        CHECK(glgamestore_entrypoint_0(slot, (BtIntPtr)received) == 0);
        CHECK(memcmp(received, payload, sizeof(payload)) == 0);
        CHECK(glgamestore_entrypoint_4(slot) == 0);
        CHECK(!memcmp(eeprom + 0x100 + slot * 0x1c0, (u8[8]){0}, 8));
        CHECK(eeprom[0x108 + slot * 0x1c0] == payload[8]);
    }
    for (int slot = 0; slot < 2; ++slot) {
        expected_len = 0x80;
        expected_buffer = payload;
        CHECK(glgamestore_entrypoint_3(slot, (BtIntPtr)payload) == 0);
        CHECK(!memcmp(eeprom + slot * 0x80, payload, 0x80));
        expected_buffer = received;
        global_valid = 1;
        CHECK(glgamestore_entrypoint_1(slot, (BtIntPtr)received) == 0);
        global_valid = 0;
        CHECK(glgamestore_entrypoint_1(slot, (BtIntPtr)received) == 2);
        CHECK(glgamestore_entrypoint_5(slot) == 0);
        CHECK(!memcmp(eeprom + slot * 0x80, (u8[8]){0}, 8));
    }
    CHECK(reads == 8 && crc_calls == 8 && writes == 12);
    expected_len = sizeof(received);
    checksum_error = 1;
    CHECK(glgamestore_entrypoint_0(0, (BtIntPtr)received) == 3);
    io_error = 1;
    CHECK(glgamestore_entrypoint_0(0, (BtIntPtr)received) == 2 && crc_calls == 9);
    CHECK(glgamestore_entrypoint_2(0, (BtIntPtr)received) == 1);
    medium = 0;
    memcpy((u8 *)D_80079D70 + 0x1ec, &medium, sizeof(medium));
    CHECK(glgamestore_entrypoint_2(0, (BtIntPtr)received) == 0 && writes == 13);
    return 0;
}
