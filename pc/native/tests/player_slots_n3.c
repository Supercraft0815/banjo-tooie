#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "overlays/ba/playerstate.h"

typedef struct { int size; int (*measure)(void); } SizeEntry;
extern SizeEntry D_801235D0[86];
extern unsigned char *func_800F43A8(int);
extern void func_800F3880(PlayerState *);
extern void func_800920C8(void *);
static void *allocated, *initialised, *reset_player, *camera_player, *freed;
static int camera_mode;
void *heap_alloc(int n) { allocated = malloc((size_t)n); return allocated; }
void heap_free(void *p) { freed = p; free(p); }
void func_80098C48(void *p) { initialised = p; }
void func_80098E64(void *p) { reset_player = p; }
short *func_800A4C88(void *p) { static short camera; camera_player = p; return &camera; }
void func_8010F9C0(intptr_t p, int mode) { if (p) camera_mode = mode; }
static int negative_size(void) { return -2; }
int main(void) {
    for (int i = 0; i < 86; i++) if (D_801235D0[i].size != -1 || !D_801235D0[i].measure) return 2;
    D_801235D0[0].size = INT32_MAX;
    if (func_800F43A8(3) || allocated) return 8;
    int (*measure)(void) = D_801235D0[0].measure;
    D_801235D0[0].measure = negative_size;
    D_801235D0[0].size = -1;
    if (func_800F43A8(3) || allocated) return 9;
    D_801235D0[0].measure = measure;
    D_801235D0[0].size = -1;
    PlayerState *p = (PlayerState *)func_800F43A8(3);
    if (!p || (uintptr_t)p <= UINT32_MAX || p != allocated || p != initialised || p != camera_player || camera_mode != 2) return 3;
    uintptr_t expected = (uintptr_t)p + ((sizeof(*p) + 16 + 7) & ~(size_t)7);
    for (int i = 0; i < 86; i++) {
        int size = D_801235D0[i].size;
        if (size < 0 || (uintptr_t)p->component_slots[i] != expected || expected % 8) { fprintf(stderr, "slot %d size %d failed\n", i, size); return 4; }
        expected += ((size_t)size + 7) & ~(size_t)7;
    }
    if (p->unk184 != 3 || p->unk17C != 1 || p->model != p->component_slots[20] || D_801235D0[20].size < 0x10c) return 5;
    unsigned char *model = p->model;
    float (*matrix)[4] = (float (*)[4])(model + 0xcc);
    float *in = (float *)(model + 0x50), *out = (float *)(model + 0x64);
    matrix[0][0] = matrix[1][1] = matrix[2][2] = 1.0f;
    matrix[3][0] = 1.0f; matrix[3][1] = 2.0f; matrix[3][2] = 3.0f;
    in[0] = 4.0f; in[1] = 5.0f; in[2] = 6.0f;
    func_800920C8(p);
    if (out[0] != 5.0f || out[1] != 7.0f || out[2] != 9.0f) return 6;
    printf("player=%p model=%p real_sizes=86 aligned_slots=86 matrix=%g,%g,%g\n", (void *)p, (void *)model, out[0], out[1], out[2]);
    void *address = p;
    func_800F3880(p);
    if (reset_player != address || freed != address) return 7;
    puts("initialisation, reset, camera and heap use test doubles; reset implementation remains untested");
    return 0;
}
