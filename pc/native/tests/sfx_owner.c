#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct sfx_source_s SfxSource;
extern SfxSource *func_800C1414(unsigned char);
extern unsigned char func_800C145C(void);
extern void func_800C13E4(void);
extern unsigned char *func_800C1430(int);
extern int func_800C1448(int);
extern void func_800C1568(int);
extern void func_800C16A4(unsigned char);
extern void func_800C157C(void);
extern int func_800C15BC(void);

#define CHECK(x) do { if (!(x)) { fprintf(stderr, "sfx owner: %s failed at %d\n", #x, __LINE__); return 1; } } while (0)

int main(void) {
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
        ((int *)slot)[0] = 0x5000 + i;
        ((int *)slot)[1] = 1;
        CHECK(func_800C1448(i) == 0x5000 + i);
    }
    CHECK(func_800C15BC() == 0);
    func_800C1568(7);
    CHECK(((int *)func_800C1430(7))[1] == 0);
    func_800C157C();
    for (i = 1; i <= 16; ++i) {
        CHECK(((int *)func_800C1430(i))[0] == 0);
        CHECK(((int *)func_800C1430(i))[1] == 0);
    }
    return 0;
}
