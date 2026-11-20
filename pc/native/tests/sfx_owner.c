#include "core1/sfx_player.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct sfx_source_s SfxSource;
extern SfxSource *func_800C1414(unsigned char);
extern unsigned char func_800C145C(void);
extern void func_800C13E4(void);
extern unsigned char *func_800C1430(int);
extern SfxState *func_800C1448(int);
extern void func_800C1568(int);
extern void func_800C16A4(unsigned char);
extern void func_800C157C(void);
extern int func_800C15BC(void);

#define CHECK(x) do { if (!(x)) { fprintf(stderr, "sfx owner: %s failed at %d\n", #x, __LINE__); return 1; } } while (0)

static SfxPlayer player;
static SfxSound sound;
static int sound_refs;
SfxPlayer *D_800411DC = &player;
SfxState *D_800411D0, *D_800411D4, *D_800411D8;
SfxVoiceCount sfx_voice_count;
f32 D_8011A870, D_8011A874 = 1, D_8011A878 = 1;

u32 osSetIntMask(u32 mask) { return mask; }
u8 *func_800E9320(s32 bank, s32 index) {
    if (bank != 0 || index != 0) abort();
    return (u8 *)&sound;
}
void func_800E9070(BtIntPtr ptr, s32 bank) {
    if (ptr != (BtIntPtr)&sound || bank != 0) abort();
    ++sound_refs;
}
void func_800E90A4(BtIntPtr ptr, s32 bank) {
    if (ptr != (BtIntPtr)&sound || bank != 0) abort();
    --sound_refs;
}
f32 func_80027170(s32 cents) { (void)cents; return 1.0f; }

void func_800263C0(ALEventQueue *, ALEventListItem *, s32);
s32 func_8002645C(ALEventQueue *, SfxEvent *);
void func_800DC3D4(s32, f32, u16, u8, u8, BtIntPtr);
void func_800C191C(s32, s32);
void func_800C1950(s32, s32);
void func_800C1984(s32, s32, s32);
void func_800DC4D4(SfxState *);
void func_800205D0(SfxState *);

static int check_voice_events(void) {
    SfxState voice = {0};
    ALEventListItem items[8];
    SfxEvent event;
    int slot = func_800C15BC();
    CHECK(slot == 1);
    CHECK((uintptr_t)&voice > UINT32_MAX);
    func_800263C0(&player.queue, items, 8);
    D_800411D8 = &voice;
    func_800DC3D4(0, 1, 30000, 64, 0, (BtIntPtr)func_800C1430(slot));
    CHECK(sound_refs == 1 && voice.sound == &sound && voice.handle != NULL);
    CHECK(*voice.handle == &voice && func_800C1448(slot) == &voice);
    CHECK(player.lastStarted == &voice && D_800411D0 == &voice && D_800411D4 == &voice);
    CHECK(func_8002645C(&player.queue, &event) == 1 && event.type == 1 && event.state == &voice);
    func_800C191C(slot, 49);
    func_800C1950(slot, 0x3f860000);
    func_800C1984(slot, 40000, 1);
    func_800DC4D4(&voice);
    CHECK(func_8002645C(&player.queue, &event) == 0 && event.type == 4 && event.state == &voice && event.value.data == 49);
    CHECK(func_8002645C(&player.queue, &event) == 0 && event.type == 0x10 && event.state == &voice && event.value.pitch == 1.046875f);
    CHECK(func_8002645C(&player.queue, &event) == 0 && event.type == 8 && event.state == &voice && event.value.data == 32767);
    CHECK(func_8002645C(&player.queue, &event) == 0 && event.type == 0x400 && event.state == &voice);
    func_800205D0(&voice);
    CHECK(voice.handle == NULL && !func_800C1448(slot) && D_800411D8 == &voice && sound_refs == 0);
    func_800C1568(slot);
    CHECK(func_800C15BC() == slot);
    func_800C157C();
    return 0;
}

int main(void) {
    SfxState voices[16];
    int i;
    uintptr_t first = (uintptr_t)func_800C1414(0);
    uintptr_t stride = (uintptr_t)func_800C1414(1) - first;

    CHECK(first > UINT32_MAX);
    CHECK(stride > 0x80);
    for (i = 1; i < 60; ++i) {
        CHECK((uintptr_t)func_800C1414(i) - (uintptr_t)func_800C1414(i - 1) == stride);
    }
    CHECK((uintptr_t)func_800C1414(59) - first == 59 * stride);

    func_800C13E4();
    for (i = 1; i < 60; ++i) CHECK(func_800C145C() == i);
    CHECK(func_800C145C() == 0);
    func_800C13E4();
    CHECK(func_800C145C() == 1);
    func_800C13E4();
    CHECK(func_800C145C() == 1);
    func_800C16A4(1);
    CHECK(func_800C145C() == 1);

    for (i = 1; i <= 16; ++i) {
        unsigned char *slot;
        CHECK(func_800C15BC() == i);
        slot = func_800C1430(i);
        *(SfxState **)slot = &voices[i - 1];
        CHECK(func_800C1448(i) == &voices[i - 1]);
    }
    CHECK(func_800C15BC() == 0);
    func_800C1568(7);
    *(SfxState **)func_800C1430(7) = NULL;
    CHECK(func_800C15BC() == 7);
    func_800C157C();
    for (i = 1; i <= 16; ++i) {
        CHECK(func_800C1448(i) == NULL);
    }
    return check_voice_events();
}
