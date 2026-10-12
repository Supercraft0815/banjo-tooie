#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EADCF0/func_800D4400.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EADCF0/func_800D4534.s")

void func_800D4564()
{
    func_800AAD28();
}

void func_800D4584(void *arg0, f32 arg1[3], f32 arg2[3], f32 arg3[3])
{
    typedef struct {
        s16 vertices[3];
        s16 pad;
        u32 flags;
    } Collision;
    typedef struct {
        f32 position[3];
        f32 previous[3];
        Collision *triangle;
        f32 normal[3];
        f32 center[3];
        f32 previousCenter[3];
        Collision *wall;
        f32 wallNormal[3];
        f32 unused[6];
        f32 matrix[3][3];
        s32 flag;
    } Step;
    typedef struct {
        f32 *object;
        f32 height;
        f32 radius;
        s32 unkC;
        s32 unk10;
        s32 flags;
        s32 unk18;
        Collision *triangle;
        f32 matrix[3][3];
        f32 normal[3];
        s32 unk50;
        u8 blocked;
        u8 count;
        u8 flag;
    } State;
    extern f32 D_80125B28, D_80125B2C, D_80125B30, D_80125B34;
    f32 func_800C673C(f32 *);
    void *func_800C6B78(f32 *, f32 *, f32, f32 *, s32, u32);
    void func_800D4400(void *, void *, f32 *);
    s32 func_800D4534(f32 [3][3], void *);
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    s32 func_800EEF24(f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF2A0(f32 *);
    void func_800EF368(f32 *, f32);
    void func_800EFA20(void *, void *, f32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800EFB24(void *, void *, void *);
    void func_800F0410(f32 *, f32 [3][3], f32 *);
    void func_800F0524(f32 *, f32 [3][3], f32 *);
    s32 func_800F0CB4(f32 *, f32 *, f32 [3][3], f32 *);
    void *func_800FABF4(f32 *, f32 *, f32 *, u32, f32, f32);
    void func_800FAE44(f32 *, f32 *, f32, f32, s32, u32);
    void func_800FAF78(f32 *, f32 *, f32 *, f32 *, f32 *);
    void *func_800FB434(f32 *, f32 *, f32, f32, f32 *, s32, u32);
    f32 mlAbsF(f32);
    f32 offset[3];
    f32 oldY;
    f32 fallback[3];
    f32 dot;
    f32 delta[3];
    f32 start[3];
    s32 flags;
    f32 saved[3];
    s32 i;
    Step steps[5];
    Step *previous;
    Step *current;
    f32 threshold;
    s32 adjust;
    f32 intersection[3];
    f32 up[3];
    f32 scale;
    f32 scaleWork[2];
    f32 oldPosition[3];
    f32 projected[3];
    f32 direction[3];
    State *state = arg0;

    if (func_800DA298(0x664)) {
        return;
    }
    flags = state->flags;
    func_800FAE44(arg1, fallback, state->radius, state->height, 1, flags | 0x20020);
    for (i = 0; i < 5; i++) {
        current = &steps[i];
        previous = i ? &steps[i - 1] : NULL;
        if (i) {
            func_800EE7F8(current->position, previous->position);
            func_800EE7F8(current->previous, previous->previous);
        } else {
            func_800EE7F8(current->position, arg2);
            func_800EE7F8(current->previous, arg1);
        }
        func_800EE7F8(saved, current->position);
        func_800EFB24(delta, current->position, current->previous);
        if (delta[0] * delta[0] + delta[1] * delta[1] + delta[2] * delta[2] > 100.0f) {
            oldY = current->position[1];
            current->wall = func_800FABF4(current->previous, current->position,
                current->wallNormal, flags | 0x20020, state->radius - 1.0f, state->height);
            if (current->wall) {
                func_800EF2A0(delta);
                dot = delta[0] * current->wallNormal[0] + delta[1] * current->wallNormal[1]
                    + delta[2] * current->wallNormal[2];
                if (dot > 0) {
                    current->wall = NULL;
                    func_800EE7F8(current->position, saved);
                }
            }
            if (current->wall && current->wallNormal[1] >= 0
                && current->wallNormal[1] < D_80125B28) {
                if (state->object) {
                    threshold = func_800C673C(state->object) - 1.0f;
                    if (threshold <= mlAbsF(oldY - current->position[1])) {
                        current->wall = func_800FABF4(current->previous, current->position,
                            current->wallNormal, flags | 0x20020, state->radius - 1.0f, state->height);
                        oldY = current->position[1];
                    }
                }
                current->position[1] = oldY;
            }
        } else {
            current->wall = NULL;
        }
        if (state->object) {
            func_800D4400(state, current, arg3);
        }
        current->flag = state->flag;
        current->previousCenter[0] = current->previous[0];
        current->previousCenter[1] = current->previous[1] + state->height;
        current->previousCenter[2] = current->previous[2];
        current->center[0] = current->position[0];
        current->center[1] = current->position[1] + state->height;
        current->center[2] = current->position[2];
        current->triangle = func_800C6B78(current->previousCenter, current->center,
            state->radius, current->normal, 3, flags | 0x20020);
        if (!current->triangle) {
            break;
        }
        func_800D4564(state->matrix);
        state->count++;
        state->triangle = current->triangle;
        func_800EE7F8(state->normal, current->normal);
        if (i == 2 && current->triangle == steps[0].triangle
            && current->triangle != previous->triangle) {
            func_800EE780(delta, current->normal, previous->normal);
            func_800EF2A0(delta);
            func_800EE7F8(current->normal, delta);
        }
        if (i == 2 && current->triangle == steps[0].triangle
            && current->triangle == previous->triangle
            && func_800D4534(current->matrix, current->triangle)) {
            func_800F0524(delta, current->matrix, current->position);
            func_800EFB24(offset, current->position, delta);
            func_800EF368(offset, state->radius + 1);
            delta[0] += offset[0];
            delta[1] += offset[1];
            delta[2] += offset[2];
            if (!(current->triangle->flags & 0x10000)) {
                current->triangle = func_800FB434(delta, current->position, state->height,
                    state->radius, current->normal, 3, flags | 0x20020);
            } else {
                func_800EE7F8(current->position, delta);
            }
        }
        if (!current->flag && current->triangle && arg3[1] < 0.0f
            && mlAbsF(current->normal[1]) < D_80125B2C
            && func_800D4534(current->matrix, current->triangle)) {
            func_800F0524(delta, current->matrix, current->position);
            func_800EFA20(offset, current->normal, state->radius + 1);
            func_800EE780(start, delta, offset);
            current->triangle = func_800FB434(start, delta, state->height,
                state->radius, current->normal, 3, flags | 0x20020);
            current->position[0] = delta[0];
            current->position[2] = delta[2];
        }
        if (current->normal[1] > D_80125B30 && state->radius != state->height
            && func_800D4534(current->matrix, current->triangle)) {
            adjust = 1;
            func_800EE7F8(intersection, current->position);
            func_800EFA4C(up, 0.0f, 1.0f, 0.0f);
            if (func_800F0CB4(intersection, up, current->matrix, current->normal)
                && mlAbsF(current->position[1] - intersection[1]) < D_80125B34) {
                adjust = 0;
            }
            if (adjust) {
                func_800EE7F8(oldPosition, current->previous);
                func_800F0410(projected, current->matrix, current->center);
                func_800EFB24(direction, oldPosition, projected);
                direction[1] = 0.0f;
                func_800EF2A0(direction);
                if (func_800EEF24(direction)) {
                    func_800EE7F8(current->normal, direction);
                    func_800EE7F8(current->previous, arg1);
                    scale = i + 1;
                    func_800EF368(direction, scale * scale * 2);
                    func_800EF04C(current->position, direction);
                    func_800EF04C(current->center, direction);
                }
            }
        }
        if (func_800EEF24(current->normal)) {
            func_800FAF78(current->previous, current->position, current->previousCenter,
                current->center, current->normal);
        }
    }
    if (i == 5 && !state->flag && state->triangle && arg2[1] < arg1[1]) {
        state->blocked = 1;
    }
    if (i == 5) {
        func_800EE7F8(arg2, fallback);
    } else {
        func_800EE7F8(arg2, current->position);
    }
}

/* extern */

void func_800D4D5C(s32 arg0, void *arg1) {
    s32 func_800C65E0(s32);
    s32 func_800C68AC(s32, s32);
    s32 func_800C68CC(s32, s32);
    s32 func_800EA600(s32);
    s32 func_800EA614();
    func_800EA600((*(s32 *)((s8 *)(arg1) + (0xC))));
    (*(s32 (**)(void *))((s8 *)(arg1) + (0x10)))(arg1);
    func_800C68AC((*(s32 *)((s8 *)(arg1) + (0))), arg0);
    func_800C68CC((*(s32 *)((s8 *)(arg1) + (0))), (*(s32 *)((s8 *)(arg1) + (0x14))));
    func_800C65E0((*(s32 *)((s8 *)(arg1) + (0))));
    func_800EA614();
}
