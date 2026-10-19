#include "common.h"

void bahitspline_entrypoint_0(void *self)
{
    void func_80095870(void *, f32 *, f32 *);
    s32 func_8009588C(s32 *);
    void func_8009C0F8(void *, f32 *);
    s32 func_8009C21C(u8 *);
    void *func_800C6C94(f32 *, f32, f32 *, u32);
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EFA20(void *, void *, f32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800EFB24(void *, void *, void *);
    void *func_800FAB50(f32 *, f32 *, f32 *, u32, f32);
    void *triangle;
    f32 height;
    f32 radius;
    f32 position[3];
    f32 center[3];
    f32 normal[3];
    f32 end[3];
    f32 collision[3];
    u32 flags;
    f32 offset[3];

    func_80095870(self, &height, &radius);
    func_8009C128(self, position);
    func_800EFA4C(center, position[0], position[1] + height, position[2]);
    func_800EE7F8(collision, center);
    flags = func_8009588C(self);
    triangle = func_800C6C94(collision, radius, normal, flags);
    if (triangle != NULL) {
        func_800EFA20(offset, normal, radius * 1.01f);
        func_800EE780(end, collision, offset);
        if (func_800FAB50(end, collision, normal, flags, radius) != NULL) {
            func_800EFB24(offset, collision, center);
            func_800EF04C(position, offset);
            func_8009C0F8(self, position);
            func_8009C21C(self);
        }
    }
}

void bahitspline_entrypoint_1(s32 arg0) 
{
}
void bahitspline_entrypoint_2(void *arg0)
{
}
