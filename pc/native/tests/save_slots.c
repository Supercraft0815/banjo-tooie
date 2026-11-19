#include "common.h"
#include "memory.h"
#include <stdio.h>

void glsavegame_entrypoint_0(void);
void glsavegame_entrypoint_1(void);
s32 glsavegame_entrypoint_2(s32 slot);
s32 glsavegame_entrypoint_3(void);
u8 *glsavegame_entrypoint_4(s32 slot);
void glsavegame_entrypoint_6(s8 *slot);
s32 glsavegame_entrypoint_7(s32 slot);
s32 glsavegame_entrypoint_8(s32 slot);
s32 glsavegame_entrypoint_9(s32 slot);
s32 glsavegame_entrypoint_10(s32 destination, s32 source);

static u8 files[4][0x1C0];
static u8 progress;
static int writeFailures, writes;

s32 glgamestore_entrypoint_0(s32 file, BtIntPtr buffer) {
    aligned4_memcpy((void *)buffer, files[file], sizeof(files[file]));
    return files[file][0] ? 0 : 2;
}

s32 glgamestore_entrypoint_2(s32 file, BtIntPtr buffer) {
    ++writes;
    if (writeFailures) {
        --writeFailures;
        return 1;
    }
    aligned4_memcpy(files[file], (void *)buffer, sizeof(files[file]));
    return 0;
}

s32 glgamestore_entrypoint_4(s32 file) {
    rare_memset(files[file], 0, sizeof(files[file]));
    return 0;
}

void glgamedata_entrypoint_1(void *buffer) {
    s8 slot;
    u8 *data = buffer;
    glsavegame_entrypoint_6(&slot);
    data[0] = 1;
    data[1] = slot;
    data[2] = progress;
}

void glgamedata_entrypoint_2(BtIntPtr buffer) { progress = ((u8 *)buffer)[2]; }

s32 glgamedata_entrypoint_3(u8 *buffer, s32 field, s32 *offset, u32 *size) {
    *offset = 1;
    *size = 1;
    return field == 2 && buffer[0];
}

s32 glgamedata_entrypoint_4(u8 *buffer) { return buffer[0] != 0; }
s32 glgamedata_entrypoint_5(s32 *buffer) { return 0; }
void glgamedata_entrypoint_6(u8 *buffer) { rare_memset(buffer, 0, sizeof(files[0])); }

#define CHECK(expr) do { if (!(expr)) { fprintf(stderr, "line %d: %s\n", __LINE__, #expr); return 1; } } while (0)

int main(void) {
    s8 selected;
    files[1][0] = files[2][0] = 1;
    files[1][1] = 2;
    files[1][2] = 51;
    files[2][1] = 3;
    files[2][2] = 76;
    glsavegame_entrypoint_0();
    CHECK(!glsavegame_entrypoint_2(0) && glsavegame_entrypoint_3());
    CHECK(glsavegame_entrypoint_4(1)[2] == 51 && glsavegame_entrypoint_4(2)[2] == 76);
    CHECK(glsavegame_entrypoint_8(1) == 0 && progress == 51);
    progress = 95;
    writeFailures = 3;
    CHECK(glsavegame_entrypoint_7(0) == 1 && writes == 3);
    CHECK(glsavegame_entrypoint_8(0) != 0 && !files[3][0]);
    writeFailures = 2;
    CHECK(glsavegame_entrypoint_7(0) == 0 && writes == 6 && files[3][2] == 95);
    CHECK(glsavegame_entrypoint_8(0) == 0 && progress == 95);
    glsavegame_entrypoint_6(&selected);
    CHECK(selected == 0);
    CHECK(glsavegame_entrypoint_10(0, 1) == 0 && glsavegame_entrypoint_4(0)[2] == 51);
    CHECK(glsavegame_entrypoint_9(2) == 0 && !glsavegame_entrypoint_2(2));
    glsavegame_entrypoint_1();
    glsavegame_entrypoint_0();
    CHECK(glsavegame_entrypoint_4(0)[2] == 51 && glsavegame_entrypoint_4(1)[2] == 51);
    CHECK(!glsavegame_entrypoint_2(2));
    glsavegame_entrypoint_1();
    return 0;
}
