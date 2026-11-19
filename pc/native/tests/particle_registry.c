#include "core2/particle_internal.h"
#include <stdio.h>
#include <stdlib.h>

void func_800B5028(void);
void func_800B5054(void);
BtIntPtr func_800B53A4(s32 capacity);
void func_800B5450(void *emitter);
void *func_800B5548(void *emitter);
void func_800BA544(ParticleEmitter *emitter, BtIntPtr callback);
extern ParticleEmitter **D_80127F10;
extern s16 D_80127F18;

static size_t move_size;
void *heap_alloc(s32 size) { return malloc(size > 0 ? (size_t)size : 1); }
void *heap_realloc(void *p, BtIntPtr size) { return realloc(p, size > 0 ? (size_t)size : 1); }
void heap_free(void *p) { free(p); }
void *defrag(void *p) {
    void *moved = malloc(move_size);
    if (!moved) abort();
    for (size_t i = 0; i < move_size; ++i) ((u8 *)moved)[i] = ((u8 *)p)[i];
    free(p);
    return moved;
}
void rare_memset(void *p, u8 value, int size) {
    for (int i = 0; i < size; ++i) ((u8 *)p)[i] = value;
}

f32 func_800DC178(f32 lower, f32 upper) { return (lower + upper) * 0.5f; }

static void on_bounce(ParticleEmitter *emitter, f32 *position) {
    emitter->state = 1;
    position[0] = 12.0f;
}

#define CHECK(x) do { if (!(x)) { fprintf(stderr, "line %d: %s\n", __LINE__, #x); return 1; } } while (0)

int main(void) {
    ParticleEmitter *first, *second, *moved;
    f32 position[3] = {0};
    int unknown;
    func_800B5028();
    func_800B5450(&unknown);
    first = (ParticleEmitter *)func_800B53A4(3);
    second = (ParticleEmitter *)func_800B53A4(1);
    if (sizeof(void *) > 4) CHECK((BtUIntPtr)first > 0xffffffffu);
    CHECK(D_80127F18 == 2 && D_80127F10[0] == first && D_80127F10[1] == second);
    CHECK(first->begin == first->particles && first->capacity == first->particles + 3);
    CHECK(second->managed && second->end == second->particles);
    first->end++;
    first->particles[0].scale = 0x125;
    func_800BA544(first, (BtIntPtr)on_bounce);
    move_size = offsetof(ParticleEmitter, particles) + sizeof(Particle) * 3;
    moved = func_800B5548(first);
    CHECK(D_80127F10[0] == moved && moved->begin == moved->particles);
    CHECK(moved->end == moved->begin + 1 && moved->capacity == moved->begin + 3);
    CHECK(moved->particles[0].scale == 0x125 && moved->on_bounce == on_bounce);
    moved->on_bounce(moved, position);
    CHECK(moved->state == 1 && position[0] == 12.0f);
    func_800B5450(&unknown);
    CHECK(D_80127F18 == 2);
    func_800B5450(moved);
    CHECK(D_80127F18 == 1 && D_80127F10[0] == second);
    func_800B5054();
    CHECK(D_80127F18 == 0 && D_80127F10 == NULL);
    return 0;
}
