#include "core2/1E6F080.h"

s32 func_800961A0(s32 *arg0, s32 arg1)
{
    ((u8 *) arg0[0x25])[0xA2] = arg1;
}

void func_800961AC(PlayerState *arg0, s32 arg1) {
    void func_80097858(void *);
    void func_8009788C(void *);
    void _bahitspline_entrypoint_0();
    void _bahitspline_entrypoint_1(PlayerState *, s32);
    s32 state;
    void *data;

    data = *(void **)((s8 *)arg0 + 0x94);
    state = *(s32 *)((s8 *)data + 0x9C);
    switch (state) {
    case 7:
        func_80097858(arg0);
        data = *(void **)((s8 *)arg0 + 0x94);
        break;
    case 10:
        _bahitspline_entrypoint_0(arg0, arg1);
        data = *(void **)((s8 *)arg0 + 0x94);
        break;
    }
    *(s32 *)((s8 *)data + 0x9C) = arg1;
    switch (arg1) {
    case 7:
        func_8009788C(arg0);
        return;
    case 10:
        _bahitspline_entrypoint_1(arg0, arg1);
        return;
    }
}

void func_80096254(s32 *arg0, s32 arg1)
{
    ((s32 *) arg0[0x25])[0x2A] = arg1;
}

void func_80096260(PlayerState *arg0) {
    if (func_800C84B0(func_80096628(arg0)) == 0x18) {
        func_80096254((s32 *) arg0, 4);
        return;
    }
    func_80096254((s32 *) arg0, 2);
}

void func_800962B0(PlayerState *arg0, s32 arg1) {
    void func_800C68D4(s8 *arg0, s32 arg1);
    func_800C68D4(*(*(s8 ***)((s8 *)(arg0) + (0x94))), arg1);
}

/* extern */

f32 func_800962D4(void *arg0) {
    f32 func_8009C150();
    f32 func_800C6784(void *);
    f32 sp1C;

    sp1C = func_8009C150();
    return sp1C - func_800C6784(*(*(void ***)((s8 *)(arg0) + (0x94))));
}

/* extern */

f32 func_8009630C(PlayerState *arg0) {
    f32 func_8009C150(PlayerState *);
    f32 func_800C6784(void *);
    f32 func_800C67D8(f32 *);
    f32 func_800F0E00(f32, f32);
    s32 pad;
    f32 sp20;
    f32 sp1C;

    sp1C = func_8009C150(arg0);
    sp20 = func_800C6784(*(*(void ***)((s8 *)arg0 + 0x94)));
    return sp1C - func_800F0E00(sp20, func_800C67D8(*(*(f32 ***)((s8 *)arg0 + 0x94))));
}

f32 func_80096364(PlayerState *arg0) {
    f32 func_800C6784(void *);
    return func_800C6784(*(*(void ***)((u8 *)arg0 + 0x94)));
}

s32 func_80096388(PlayerState *arg0)
{
    return (*(s32 **)((u8 *)arg0 + 0x94))[39];
}

/* extern */

void func_80096394(PlayerState *arg0, f32 *arg1) {
    void func_800EE7F8(f32 *, f32 *);
    func_800EE7F8(arg1, (f32 *)(*(u8 **)((u8 *)arg0 + 0x94) + 0x90));
}

void func_800963C0(PlayerState *arg0, f32 *arg1) {
    void func_800C675C(void *arg0, f32 *arg1);
    func_800C675C(*(*(u8 ***)((s8 *)(arg0) + (0x94))), arg1);
}

void func_800963E4(PlayerState *arg0) {
    f32 func_80013A7C(f32);
    s32 pad;
    f32 sp1C[2];
    func_800963C0(arg0, sp1C);
    func_80013A7C(sp1C[1]);
}

int func_8009640C(PlayerState *arg0) {
    u8 *ptr;

    ptr = *(u8 **)((u8 *)arg0 + 0x94);
    return ptr[0x18] == 0 && ptr[0x56] != 0;
}

s32 func_80096434(PlayerState *arg0)
{
    return (*(s32 **)((u8 *)arg0 + 0x94))[29];
}

/* extern */

void func_80096440(PlayerState *arg0, f32 *arg1) {
    void func_800EE7F8(f32 *, f32 *);
    func_800EE7F8(arg1, (f32 *)(*(u8 **)((u8 *)arg0 + 0x94) + 0x44));
}

void func_8009646C(u8 *arg0, f32 *arg1) {
    void func_800EE7F8(f32 *, f32 *);
    f32 *var_s1;
    s32 var_s0;

    var_s0 = 0;
    var_s1 = arg1;
    do {
        func_800EE7F8(var_s1, (f32 *)(*(u8 **)(arg0 + 0x94) + var_s0 + 0x20));
        var_s0 += 0xC;
        var_s1 += 3;
    } while (var_s0 != 0x24);
}

s32 func_800964D0(PlayerState *arg0)
{
    return (*(s32 **)((u8 *)arg0 + 0x94))[42];
}

f32 func_800964DC(PlayerState *arg0) {
    f32 func_800C67D8(f32 *arg0);
    return func_800C67D8(*(*(f32 ***)((s8 *)arg0 + 0x94)));
}

s32 func_80096500(PlayerState *arg0)
{
    return (*(u8 **)((u8 *)arg0 + 0x94))[0xA1];
}

s32 func_8009650C(PlayerState *arg0)
{
    return (*(u8 **)((u8 *)arg0 + 0x94))[0x55];
}

u32 func_80096518(PlayerState *arg0)
{
    return (*(u8 **)((u8 *)arg0 + 0x94))[0x56];
}

u32 func_80096524(PlayerState *arg0)
{
    return (*(u8 **)((u8 *)arg0 + 0x94))[0xA0];
}

s32 func_80096530(void *arg0) {
    return (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x94)))) + (0xA3))) == 3;
}

/* extern */

s32 func_80096544(PlayerState *arg0) {
    s32 func_800C670C(s32);
    return func_800C670C(*(*(s32 **)((s8 *)(arg0) + (0x94))));
}

/* extern */

s32 func_80096568(void *arg0, s32 arg1) {
    s32 func_800C6744(s32);
    return arg1 == (func_800C6744(*(*(s32 **)((s8 *)(arg0) + (0x94)))) & 0x1F00);
}

/* extern */

s32 func_8009659C(void *arg0, s32 arg1) {
    s32 func_800C6744(s32);
    return func_800C6744(*(*(s32 **)((s8 *)(arg0) + (0x94)))) & arg1;
}

u8 func_800965C8(void *arg0)
{
    return (*(u8 **)((u8 *)arg0 + 0x94))[0xA4];
}

s32 func_800965D4(void *arg0)
{
    return (*(s32 **)((u8 *)arg0 + 0x94))[0x14];
}

/* extern */

void func_800965E0(void *arg0) {
    s32 func_800C67F8(s32);
    func_800C67F8(*(*(s32 **)((s8 *)(arg0) + (0x94))));
}

/* extern */

void func_80096604(void *arg0) {
    s32 func_800C6840(s32);
    func_800C6840(*(*(s32 **)((s8 *)(arg0) + (0x94))));
}

/* extern */

s32 func_80096628(PlayerState *arg0) {
    s32 func_800C6744(s32);
    return func_800C6744(*(*(s32 **)((s8 *)(arg0) + (0x94))));
}

/* extern */

void func_8009664C(void *arg0) {
    s32 func_800C674C(s32);
    func_800C674C(*(*(s32 **)((s8 *)(arg0) + (0x94))));
}

/* extern */

void func_80096670(void *arg0) {
    s32 func_800C67C8(s32);
    func_800C67C8(*(*(s32 **)((s8 *)(arg0) + (0x94))));
}

void func_80096694(PlayerState* a0)
{
    func_800C84B0(func_80096628(a0));
}

/* extern */

s32 func_800966BC(void *arg0) {
    s32 func_800C67E0(s32);
    return func_800C67E0(*(*(s32 **)((s8 *)(arg0) + (0x94))));
}

/* extern */

s32 func_800966E0(void *arg0) {
    s32 func_800C67E8(s32);
    return func_800C67E8(*(*(s32 **)((s8 *)(arg0) + (0x94))));
}

/* extern */

void func_80096704(void *arg0) {
    s32 func_800C5B84(s32);
    func_800C5B84(*(*(s32 **)((s8 *)(arg0) + (0x94))));
}

/* extern */

void func_80096728(void *arg0) {
    s32 func_800C5BC4(s32);
    s32 temp_a1;

    temp_a1 = *(*(s32 **)((s8 *)(arg0) + (0x94)));
    if (temp_a1 != 0) {
        *(*(s32 **)((s8 *)(arg0) + (0x94))) = func_800C5BC4(temp_a1);
    }
}

/* extern */

void func_80096768(PlayerState *arg0) {
    void func_8009C128(PlayerState *, f32[3]);
    void func_800D4D5C(s32, void *);
    f32 sp1C[3];

    func_8009C128(arg0, sp1C);
    func_800D4D5C((s32) sp1C, *(void **)((s8 *)arg0 + 0x94));
}

/* extern */

void func_8009679C(void *arg0) {
    s32 func_800C68DC(s32);
    func_800C68DC(*(*(s32 **)((s8 *)(arg0) + (0x94))));
}

s32 func_800967C0()
{
    return 0x28;
}

struct CollisionHits {
        s32 count;
        struct {
            f32 distance;
            f32 start[3];
            f32 end[3];
            f32 normal[3];
            f32 point[3];
        } entries[1];
};

void func_800967C8(f32 *arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    s32 func_800BEE40(f32 *, f32 *, f32 *, f32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EE97C(f32 *, f32 *, f32 *);
    f32 func_800EEAA4(f32 *, f32 *);
    f32 func_800EEAD4(f32 *, f32 *);
    f32 func_800EEF94(f32 *);
    void func_800EF2A0(f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800EFB24(void *, void *, void *);
    extern struct CollisionHits D_80126E30;
    f32 dot;
    f32 t;
    f32 origin;
    f32 projection;
    f32 hit[3];
    f32 distance;
    f32 direction[3];
    f32 normal[3];
    s32 i;
    f32 up[3];
    f32 horizontal[3];
    f32 difference[3];
    f32 offset[3];
    f32 numerator;
    f32 plane;

    func_800EFB24(difference, arg1, arg0);
    func_800EFA4C(up, 0.0f, 1.0f, 0.0f);
    func_800EFA4C(horizontal, difference[0], 0.0f, difference[2]);
    func_800EF2A0(horizontal);
    func_800EE97C(normal, horizontal, up);
    dot = func_800EEAA4(arg3, normal);
    if (dot > 0.0f) return;
    if (dot == 0.0f) return;
    plane = func_800EEAA4(normal, arg0);
    origin = func_800EEAA4(normal, arg2);
    numerator = plane - origin;
    t = numerator / dot;
    if (origin < plane) return;
    for (i = 0; i < 3; i++) {
        hit[i] = arg2[i] + arg3[i] * t;
    }
    func_800EFA4C(direction, difference[0], 0.0f, difference[2]);
    func_800EF2A0(direction);
    func_800EFA4C(offset, hit[0] - arg0[0], 0.0f, hit[2] - arg0[2]);
    projection = func_800EEAA4(offset, direction);
    if (projection < 0.0f) return;
    if (func_800EEF94(difference) < projection) return;
    if (!func_800BEE40(arg0, arg1, normal, 0.028f)) return;
    distance = func_800EEAD4(arg2, hit);
    if (D_80126E30.entries[0].distance < distance) return;
    if (distance < D_80126E30.entries[0].distance) {
        D_80126E30.count = 0;
    }
    D_80126E30.entries[D_80126E30.count].distance = distance;
    func_800EE7F8(D_80126E30.entries[D_80126E30.count].start, arg0);
    func_800EE7F8(D_80126E30.entries[D_80126E30.count].end, arg1);
    func_800EE7F8(D_80126E30.entries[D_80126E30.count].normal, normal);
    func_800EE7F8(D_80126E30.entries[D_80126E30.count].point, hit);
    D_80126E30.count++;
}

extern s16 D_80126D20[];
extern struct CollisionHits D_80126E30;
extern f32 D_80126E38, D_80126E3C, D_80126E40;
extern f32 D_80126E44, D_80126E48, D_80126E4C;
extern f32 D_80126E50[3], D_80126E5C[3];
s32 func_80096ACC(f32 *arg0, f32 *arg1, s32 arg2, s32 arg3) {
    s32 func_800BED70(f32 *, f32 *, s16 (**)[3], s32, f32);
    void func_800EE88C(f32 *, s16 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EFB24(void *, void *, void *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 mlAbsF(f32);
    s16 (*triangle)[3];
    s32 j;
    s16 (*end)[3];
    s32 pad;
    f32 low[3];
    f32 high[3];
    f32 difference[3];
    f32 vertices[3][3];
    s32 i;
    f32 *out;
    f32 distance;

    func_800EFB24(difference, arg1, arg0);
    for (j = 0; j < 3; j++) {
        if (arg0[j] < arg1[j]) low[j] = arg0[j];
        else low[j] = arg1[j];
    }
    for (j = 0; j < 3; j++) {
        if (arg0[j] > arg1[j]) high[j] = arg0[j];
        else high[j] = arg1[j];
    }
    end = (s16 (*)[3])D_80126D20;
    high[1] += 100.0f;
    if (!func_800BED70(low, high, &end, 15, 0.98f)) return 0;
    D_80126E30.count = 0;
    D_80126E30.entries[0].distance = 100000.0f;
    for (triangle = (s16 (*)[3])D_80126D20; (u32)triangle < (u32)end; triangle += 3) {
        for (i = 0; i < 3; i++) {
            func_800EE88C(vertices[i], triangle[i]);
        }
        func_800967C8(vertices[0], vertices[1], arg0, difference);
        func_800967C8(vertices[1], vertices[2], arg0, difference);
        func_800967C8(vertices[2], vertices[0], arg0, difference);
    }
    if (D_80126E30.entries[0].distance == 100000.0f) return 0;
    func_800EE7F8((f32 *)arg2, D_80126E30.entries[0].point);
    func_800EE7F8((f32 *)arg3, D_80126E30.entries[0].normal);
    distance = mlAbsF(D_80126E30.entries[0].start[0] - D_80126E30.entries[0].end[0]);
    if (mlAbsF(D_80126E30.entries[0].start[2] - D_80126E30.entries[0].end[2]) < distance) {
        ((f32 *)arg2)[1] = func_800F10B4(((f32 *)arg2)[0], D_80126E30.entries[0].start[0], D_80126E30.entries[0].end[0], D_80126E30.entries[0].start[1], D_80126E30.entries[0].end[1]);
    } else {
        ((f32 *)arg2)[1] = func_800F10B4(((f32 *)arg2)[2], D_80126E30.entries[0].start[2], D_80126E30.entries[0].end[2], D_80126E30.entries[0].start[1], D_80126E30.entries[0].end[1]);
    }
    return 1;
}

/* extern */

s32 func_80096DD4(s32 arg0, s32 arg1, f32 *arg2, f32 *arg3) {
    void func_800EE7F8(f32 *, f32 *);
    s32 func_80096ACC(f32 *, f32 *, s32, s32);
    f32 sp24[5];
    f32 sp18;

    func_800EE7F8(sp24 + 2, arg2);
    func_800EE7F8(&sp18, arg3);
    if (func_80096ACC(sp24 + 2, &sp18, arg0, arg1) == 0) {
        return 0;
    }
    return 1;
}

s32 func_80096E30(f32 *arg0, f32 *arg1, f32 *arg2, f32 arg3, f32 arg4, f32 arg5) {
    void func_800EE780(f32 *, f32 *, f32 *);
    f32 func_800EEAA4(f32 *, f32 *);
    int func_800EECE0(f32 *, f32 *);
    void func_800EF2A0(f32 *);
    void func_800EF334(f32 *, f32);
    void func_800EF368(f32 *, f32);
    void func_800EF934(f32 *, f32 *, f32);
    void func_800EFA20(void *, void *, f32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800EFE50(f32 *, f32 *, f32 *, f32);
    s32 result;
    f32 spB8[3];
    f32 spAC[3];
    f32 spA0[3];
    f32 sp94[3];
    f32 sp88[3];
    f32 sp7C[3];
    f32 sp70[3];
    f32 sp64[3];
    f32 sp58[3];
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];
    f32 sp28[3];
    f32 sp1C[3];

    func_800EFA20(sp28, arg0, arg4);
    func_800EE780(sp1C, arg2, sp28);
    func_800EFA20(sp28, arg0, arg3);
    func_800EF934(sp7C, sp28, -arg5);
    func_800EF934(sp34, sp28, arg5);
    func_800EFA4C(sp88, sp28[2], sp28[1], -sp28[0]);
    func_800EFA4C(sp40, -sp28[2], sp28[1], sp28[0]);
    func_800EF368(sp88, 30.0f);
    func_800EF368(sp40, 30.0f);
    func_800EE780(sp94, sp1C, sp88);
    func_800EE780(sp4C, sp1C, sp40);
    func_800EE780(spB8, sp94, sp7C);
    func_800EE780(sp70, sp4C, sp34);
    if (func_80096DD4((s32)spA0, (s32)spAC, (s32)sp94, (s32)spB8) == 0) {
        return 0;
    }
    if (func_80096DD4((s32)sp58, (s32)sp64, (s32)sp4C, (s32)sp70) == 0) {
        return 1;
    }
    if (func_800EEAA4(spAC, sp64) <= 0.1f) {
        return 4;
    }
    func_800EFE50(arg1, spA0, sp58, 0.5f);
    func_800EE780(arg0, spAC, sp64);
    func_800EF334(arg0, -0.5f);
    func_800EF2A0(arg0);
    if (func_800EECE0(spAC, sp64) != 0) {
        result = 2;
    } else {
        result = 3;
    }
    return result;
}

int func_8009700C(s32 arg0, f32 *arg1, f32 *arg2, f32 arg3, f32 arg4) {
    void func_800EFA4C(f32 *, f32, f32, f32);
    void *func_800C6A7C(f32 *, f32 *, f32 *, u32);
    f32 sp2C[3];
    f32 sp20[3];

    func_800EFA4C(sp20, arg2[0], arg2[1] + arg3, arg2[2]);
    func_800EFA4C(sp2C, arg2[0], arg2[1] + arg4, arg2[2]);
    if (func_800C6A7C(sp20, sp2C, arg1, 0x420025) != 0) {
        return 1;
    }
    return 0;
}

/* extern */

s32 func_800970A4(f32 *arg0, f32 *arg1, f32 arg2) {
    void func_800EE7B4(f32 dst[3], f32 a[3], f32 b[3], f32 scale);
    void *func_800C6A7C(f32 arg0[3], f32 arg1[3], f32 arg2[3], u32 flags);
    s32 var_v1;
    f32 sp28[3];
    f32 sp1C[3];

    func_800EE7B4(sp28, arg0, arg1, arg2);
    if (func_800C6A7C(arg0, sp28, sp1C, 0x420025) != 0) {
        var_v1 = 1;
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

s32 func_80097104(PlayerState *arg0, f32 *arg1, f32 arg2) {
    void func_8009BB24(void *, f32 *);
    void func_800EE97C(f32 *, f32 *, f32 *);
    f32 func_800EEAA4(f32 *, f32 *);
    void func_800EF2A0(f32 *);
    void func_800EFA20(void *, void *, f32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800EFB24(void *, void *, void *);
    f32 sp6C[3];
    f32 sp60[3];
    f32 sp54[3];
    f32 sp48[3];
    f32 sp3C[3];
    f32 sp30[3];
    f32 sp18;
    f32 sp28;
    f32 sp1C[3];

    func_800EFA20(sp6C, *(f32 **)((u8 *)arg0 + 0x98), arg2);
    func_800EFB24(sp60, arg1, sp6C);
    func_800EFA4C(sp48, 0.0f, 1.0f, 0.0f);
    func_800EE97C(sp3C, *(f32 **)((u8 *)arg0 + 0x98), sp48);
    func_800EFA20(sp30, sp3C, -1.0f);
    func_8009BB24(arg0, sp1C);
    sp1C[1] = 0.0f;
    func_800EF2A0(sp1C);
    sp28 = func_800EEAA4(sp3C, sp1C);
    func_800EFA4C(sp54, sp60[0], sp60[1] - 50.0f, sp60[2]);
    if (sp28 > 0.0f) {
        sp18 = arg2 + 4.0f;
        if (func_800970A4(sp60, sp3C, sp18)) {
            return 0;
        }
        if (func_800970A4(sp54, sp3C, sp18)) {
            return 0;
        }
    }
    if (sp28 < 0.0f) {
        sp18 = -(arg2 + 4.0f);
        if (func_800970A4(sp60, sp3C, sp18)) {
            return 0;
        }
        if (func_800970A4(sp54, sp3C, sp18)) {
            return 0;
        }
    }
    return 1;
}

s32 func_800972BC(PlayerState *arg0, f32 *arg1) {
    void func_800EE7F8(f32 *, f32 *);
    void func_800EFA20(void *, void *, f32);
    void func_800EFB24(void *, void *, void *);
    f32 var_f0;
    f32 sp60;
    f32 sp5C;
    f32 sp50[3];
    f32 sp44[3];
    f32 sp38[3];
    f32 sp2C[3];

    func_800EE7F8(sp50, arg1);
    func_80095870(arg0, &sp5C, &sp60);
    sp50[1] += sp5C - sp60;
    if ((*(u8 **)((u8 *)arg0 + 0x98))[0x24]) {
        var_f0 = 15.0f;
    } else {
        var_f0 = 0.0f;
    }
    switch (func_80096E30(*(f32 **)((u8 *)arg0 + 0x98), sp44, sp50,
                         sp60 + 30.0f, -sp60 * 0.5f,
                         var_f0)) {
    case 0:
        (*(u8 **)((u8 *)arg0 + 0x98))[0x25] = 2;
        return 0;
    case 1:
        (*(u8 **)((u8 *)arg0 + 0x98))[0x25] = 3;
        return 0;
    case 4:
        (*(u8 **)((u8 *)arg0 + 0x98))[0x25] = 3;
        return 0;
    case 2:
        (*(u8 **)((u8 *)arg0 + 0x98))[0x24] = 1;
        break;
    case 3:
        (*(u8 **)((u8 *)arg0 + 0x98))[0x24] = 0;
        break;
    }
    func_800EE7F8(*(f32 **)((u8 *)arg0 + 0x98) + 3, sp44);
    if (func_80097104(arg0, sp44, sp60) == 0) {
        return 0;
    }
    func_800EFA20(sp2C, *(f32 **)((u8 *)arg0 + 0x98), sp60 + -18.0f);
    func_800EFB24(sp50, sp44, sp2C);
    sp50[1] = (sp44[1] - sp5C) + -43.0f;
    if (func_8009700C((s32)arg0, sp38, sp50, sp60 * 0.75f + sp5C, -50.0f) != 0) {
        if (sp38[1] > 0.0f) {
            (*(u8 **)((u8 *)arg0 + 0x98))[0x25] = 4;
        } else {
            (*(u8 **)((u8 *)arg0 + 0x98))[0x25] = 5;
        }
        return 0;
    }
    func_800EE7F8(*(f32 **)((u8 *)arg0 + 0x98) + 6, sp50);
    (*(u8 **)((u8 *)arg0 + 0x98))[0x25] = 1;
    return 1;
}

/* extern */

f32 func_800974FC(PlayerState *arg0) {
    s32 func_800F1EA4(s32, f32 *);
    f32 sp1C;

    func_800F1EA4((*(s32 *)((s8 *)(arg0) + (0x98))), &sp1C);
    return sp1C;
}

s32 func_80097524(PlayerState *arg0)
{
    return (*(u8 **)((u8 *)arg0 + 0x98))[0x25];
}

s32 func_80097530(PlayerState *arg0) {
    void *func_800C6A7C(f32 [3], f32 [3], f32 [3], u32);
    void *func_800C6C94(f32 [3], f32, f32 [3], u32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    void func_800EFA20(void *, void *, f32);
    f32 sp54;
    f32 sp50;
    f32 sp44[3];
    f32 sp38[3];
    f32 sp2C[3];
    f32 sp20[3];

    func_80095870(arg0, &sp50, &sp54);
    func_800EFA20(sp2C, *(void **)((u8 *)arg0 + 0x98), 25.0f);
    func_800EF04C(sp2C, *(f32 **)((u8 *)arg0 + 0x98) + 3);
    func_800EFA4C(sp44, sp2C[0], sp2C[1] + 6.0f, sp2C[2]);
    func_800EFA4C(sp38, sp2C[0], sp2C[1] + sp50 + sp54 + 5.0f, sp2C[2]);
    if (func_800C6A7C(sp44, sp38, sp20, 0x420025) != 0) {
        return 0;
    }
    func_800EFA4C(sp44, sp2C[0], sp2C[1] + sp50, sp2C[2]);
    if (func_800C6C94(sp44, sp54 + 5.0f, sp20, 0x420025) != 0) {
        return 0;
    }
    func_800EFA4C(sp44, sp2C[0], (sp2C[1] + sp50) - sp54 * 0.75f, sp2C[2]);
    if (func_800C6C94(sp44, sp54 + 5.0f, sp20, 0x420025) != 0) {
        return 0;
    }
    return 1;
}

s32 func_800976DC(PlayerState *arg0) {
    s32 bastatetimer_isActive(PlayerState *, s32);
    void func_8009C128(PlayerState *, f32 [3]);
    void func_800EFB24(void *, void *, void *);
    void func_800EF2A0(f32 [3]);
    void func_800F0410(f32 [3], f32 [3][3], f32 [3]);
    f32 sp74;
    f32 sp70;
    f32 sp64[3];
    f32 sp58[3];
    f32 sp4C[3];
    f32 sp28[3][3];
    f32 *temp_v0;

    if (bastatetimer_isActive(arg0, 7) != 0) {
        return 0;
    }
    if (func_8009650C(arg0) == 0) {
        return 0;
    }
    func_80096440(arg0, sp58);
    if (sp58[1] > 0.028f && sp58[1] < 0.98f) {
        return 0;
    }
    func_8009C128(arg0, sp64);
    func_80095870(arg0, &sp70, &sp74);
    sp64[1] += sp70;
    func_8009646C((u8 *)arg0, sp28[0]);
    func_800F0410(sp4C, sp28, sp64);
    func_800EFB24(*(f32 **)((u8 *)arg0 + 0x98), sp4C, sp64);
    (*(f32 **)((u8 *)arg0 + 0x98))[1] = 0.0f;
    func_800EF2A0(*(f32 **)((u8 *)arg0 + 0x98));
    temp_v0 = *(f32 **)((u8 *)arg0 + 0x98);
    if (temp_v0[0] == 0.0f && temp_v0[2] == 0.0f) {
        return 0;
    }
    *((s8 *)temp_v0 + 0x24) = 1;
    func_8009C128(arg0, sp64);
    if (func_800972BC(arg0, sp64) == 0) {
        return 0;
    }
    return func_800972BC(arg0, *(f32 **)((u8 *)arg0 + 0x98) + 6);
}

/* extern */

void func_80097858(void *arg0) {
    s32 bastatetimer_set(void *, s32, f32);
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x98)))) + (0x24))) = 1;
    bastatetimer_set(arg0, 7, 0.2f);
}

void func_8009788C(void *arg0) {
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x98)))) + (0x24))) = 1;
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x98)))) + (0x26))) = 1;
}

void func_800978A4(PlayerState *arg0) {
    void baphysics_set_vertical_velocity(PlayerState *, f32);
    s32 func_800972BC(PlayerState *, f32 *);
    void func_8009C0F8(void *, f32 *);
    void func_8009C128(PlayerState *, f32[3]);
    void func_8009C15C(PlayerState *, f32 *);
    void func_800EE7F8(f32 *, f32 *);
    f32 sp3C[3];
    f32 sp30[3];
    f32 sp24[3];
    u8 *temp_v0;

    func_8009C15C(arg0, sp3C);
    temp_v0 = *(u8 **)((u8 *)arg0 + 0x98);
    if (temp_v0[0x26] != 0) {
        temp_v0[0x26] = 0;
        func_800EE7F8(sp30, (f32 *)(*(u8 **)((u8 *)arg0 + 0x98) + 0x18));
    } else {
        func_8009C128(arg0, sp30);
    }
    func_800EE7F8(sp24, *(f32 **)((u8 *)arg0 + 0x98));
    if (func_800972BC(arg0, sp30) != 0) {
        func_800EE7F8(sp30, (f32 *)(*(u8 **)((u8 *)arg0 + 0x98) + 0x18));
        baphysics_set_vertical_velocity(arg0, 1.0f);
    } else {
        func_800EE7F8(sp30, sp3C);
        func_800EE7F8(*(f32 **)((u8 *)arg0 + 0x98), sp24);
    }
    func_8009C0F8(arg0, sp30);
}
