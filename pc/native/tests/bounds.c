#include "core2/bounds.h"
#include <stdio.h>

void func_800CBB70(s32 index, s32 enabled);
s32 func_800CBBC0(s32 index);
s32 func_800CBBE0(s32 index);
s32 func_800CBC3C(void *position);
void *func_800CC63C(s32 index, s32 item);

#define CHECK(expr) do { if (!(expr)) { fprintf(stderr, "line %d: %s\n", __LINE__, #expr); return 1; } } while (0)

int main(void) {
    BoundContext *context = &D_8012AE80;
    s16 point[3] = {120, 30, -95};
    s16 far[3] = {152, 30, -95}, bridge[3] = {136, 30, -95};
    f32 inside[3] = {120, 30, -95};
    f32 outside[3] = {175, 30, -95};
    _gcboundDll_entrypoint_0(context);
    CHECK(context->enabled[199] == 1);
    func_800CBB70(199, 0);
    CHECK(context->enabled[198] == 1 && context->enabled[199] == 0);
    _gcboundDll_entrypoint_1(context);
    _gcboundDll_entrypoint_3(context, 3, point, 10, 20, 0, 0, 0);
    _gcboundDll_entrypoint_4(context, 4, point, 10, 1, 20);
    _gcboundDll_entrypoint_5(context, 5, point, 10, 20, 0, 0);
    _gcboundDll_entrypoint_3(context, 3, far, 10, 20, 0, 0, 0);
    _gcboundDll_entrypoint_3(context, 3, bridge, 10, 20, 0, 0, 0);
    CHECK(context->groups[0].count == 2);
    _gcboundDll_entrypoint_7(context);
    _gcboundDll_entrypoint_6(context);
    _gcboundDll_entrypoint_8(context);
    for (int i = 0; i < 3; ++i) {
        CHECK(context->groups[i].count == 1);
        CHECK(context->groups[i].entries != NULL);
    }
    CHECK(func_800CBBC0(0) == 4 && func_800CBBE0(0) == 5);
    f32 *item = func_800CC63C(0, 0);
    CHECK(item[0] == point[0] && item[1] == point[1] && item[2] == point[2]);
    CHECK(((f32 *)func_800CC63C(0, 1))[0] == bridge[0]);
    CHECK(((f32 *)func_800CC63C(0, 2))[0] == far[0]);
    CHECK(func_800CBC3C(inside) == 0 && func_800CBC3C(outside) == -1);
    _gcboundDll_entrypoint_2(context);
    CHECK(context->pool == NULL);
    for (int i = 0; i < 3; ++i) {
        CHECK(context->groups[i].count == 0 && context->groups[i].entries == NULL);
    }
    return 0;
}
