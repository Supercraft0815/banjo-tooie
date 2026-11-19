#include "core2/1EAAD80.h"
#include <stdio.h>

void func_800D154C(void);
void func_800D15CC(void);
s32 func_800D1C70(void);
void func_800D1C78(u8 *bytes, u32 length);
void func_800D1DFC(u8 *bytes);

s32 func_8001210C(s32 mask) { return mask == 0x3ff ? 0x1ff : 0; }

#define CHECK(expr) do { if (!(expr)) { fprintf(stderr, "line %d: %s\n", __LINE__, #expr); return 1; } } while (0)

int main(void) {
    u8 input[42], output[42];
    CHECK(func_800D1C70() == sizeof(input));
    func_800D1510();
    func_800D1DFC(output);
    for (size_t i = 0; i < sizeof(output); ++i) CHECK(output[i] == 0);
    for (size_t i = 0; i < sizeof(input); ++i) input[i] = (u8)(0x80 + 13 * i);
    func_800D1C78(input, sizeof(input));
    for (int i = 0; i < 3; ++i) {
        func_800D154C();
        func_800D15CC();
        func_800D1DFC(output);
        for (size_t j = 0; j < sizeof(output); ++j) CHECK(output[j] == input[j]);
    }
    func_800D1C78(input, 5);
    func_800D1DFC(output);
    for (size_t i = 0; i < sizeof(output); ++i) CHECK(output[i] == (i < 4 ? input[i] : 0));
    func_800D1604();
    func_800D15CC();
    return 0;
}
