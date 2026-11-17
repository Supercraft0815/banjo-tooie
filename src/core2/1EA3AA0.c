#if defined(BT_NATIVE) && !defined(BT_ILP32) // ILP32 runs the original code
#include "1EA3AA0_native.inc"
#else
#include "core2/1EA3AA0.h"

void func_800CA1B0(void *arg0) {
    void func_800EF934(f32 dst[3], f32 src[3], f32 yaw);
    void func_800EFA4C(f32 *arg0, f32 arg1, f32 arg2, f32 arg3);
    f32 *vec[1];
    register f32 *temp;

    vec[0] = (f32 *)((u8 *)arg0 + 0xF8);
    func_800EFA4C(vec[0], -1.0f, 0.0f, 0.0f);
    temp = vec[0];
    func_800EF934(temp, temp, *(f32 *)((u8 *)arg0 + 0xE8) * (*(f32 *)((u8 *)arg0 + 0xE4) * 0.5f));
}   typedef struct { f32 unk0; f32 unk4; f32 unk8; u8 padC[0xC]; f32 unk18; f32 unk1C; f32 unk20; u8 pad24[0xC0]; f32 unkE4; f32 unkE8; f32 unkEC; f32 unkF0; f32 unkF4; f32 unkF8; u8 padFC[0x8]; f32 unk104; u8 pad108[0x8]; f32 unk110; f32 unk114; f32 unk118; f32 unk11C; f32 unk120; f32 unk124; u8 pad128[0x3C]; f32 unk164; } Obj1EA3AA0_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_800CA218(void *arg0, f32 arg1) {
    void func_800EF8BC(f32 dst[3], f32 src[3], f32 pitch);
    void func_800EF934(f32 dst[3], f32 src[3], f32 yaw);
    void func_800EFA4C(f32 *arg0, f32 arg1, f32 arg2, f32 arg3);
    f32 *vec[1];
    register f32 *temp;

    vec[0] = &((Obj1EA3AA0_arg0 *)arg0)->unk104;
    func_800EFA4C(vec[0], 0.0f, 1.0f, 0.0f);
    temp = vec[0];
    func_800EF8BC(temp, temp, arg1);
    vec[0] = &((Obj1EA3AA0_arg0 *)arg0)->unkF8;
    func_800EFA4C(vec[0], -1.0f, 0.0f, 0.0f);
    temp = vec[0];
    func_800EF934(temp, temp, ((Obj1EA3AA0_arg0 *)arg0)->unkE8 * arg1);
}

void func_800CA2A8(void *arg0, f32 arg1) {
    f32 func_800137F4(f32);
    f32 func_80013788(void);
    void func_800EF2A0(f32[3]);
    f32 temp_f0;
    f32 temp_f2;

    *(f32 *)((u8 *)arg0 + 0x110) = 0.0f;
    temp_f0 = func_800137F4(arg1);
    *(f32 *)((u8 *)arg0 + 0x120) = temp_f0;
    *(f32 *)((u8 *)arg0 + 0x114) = -temp_f0;
    temp_f2 = -func_80013788();
    *(f32 *)((u8 *)arg0 + 0x124) = temp_f2;
    *(f32 *)((u8 *)arg0 + 0x118) = temp_f2;
    *(f32 *)((u8 *)arg0 + 0x11C) = *(f32 *)((u8 *)arg0 + 0xE8) * *(f32 *)((u8 *)arg0 + 0x120);
    func_800EF2A0((f32 *)((u8 *)arg0 + 0x11C));
}

void func_800CA314(s32 arg0,s32 arg1)
{
    aligned4_memcpy(arg0,arg1,0x168);
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800CA440(void *);

u8 *func_800CA334(void) {
    void* heap_alloc(s32 size);
    u8 *sp1C;
    u8 *temp_v0;

    temp_v0 = heap_alloc(0x168);
    sp1C = temp_v0;
    func_800CA440(temp_v0);
    return sp1C;
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800CA364(void* arg0) 
{
    heap_free(arg0); BT_NATIVE_ONLY(return 0;)
}
void* func_800CA384(void* arg0) 
{
    return defrag(arg0);
}
void func_800CA3A4(s32 arg0, f32 arg1) {
    void func_800EF04C(f32[3], f32[3]);
    void func_800EF4E4(f32[3], f32, f32, f32, f32, f32);
    f32 sp24[3];

    func_800EF4E4(sp24, (((Obj1EA3AA0_arg0 *)arg0)->unk18), (((Obj1EA3AA0_arg0 *)arg0)->unk1C), 0.0f, 0.0f, arg1);
    func_800EF04C((f32 *) arg0, sp24);
}

void func_800CA3F4(f32 *arg0, f32 *arg1, f32 arg2) {
    void func_800EF04C(f32[3], f32[3]);
    void func_800EF368(f32 vec[3], f32 target_length);
    void func_800EFB24(void *arg0, void *arg1, void *arg2);
    f32 sp1C[3];

    func_800EFB24(sp1C, arg0, arg1);
    func_800EF368(sp1C, arg2);
    func_800EF04C(arg1, sp1C);
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800CA440(void *arg0) {
    f32 func_800139F8(f32);
    void func_800CA5F8(f32 *, f32, f32, f32);
    void func_800CA688(s32, f32, f32, f32);
    void func_800CA6C0(void *, f32, f32);
    void func_800CA6F0(void *, f32);
    s32 func_800CAF34(s32);
    extern f32 D_80125970;
    f32 sp20;

    func_800CA5F8(arg0, 0.0f, 0.0f, 0.0f);
    func_800CA688((s32)arg0, 0.0f, 0.0f, 0.0f);
    func_800CA6C0(arg0, 1.0f, 10000.0f);
    func_800CA6F0(arg0, 1.0f);
    (((Obj1EA3AA0_arg0 *)arg0)->unkE4) = 40.0f;
    sp20 = (((Obj1EA3AA0_arg0 *)arg0)->unkE4) * 0.5f;
    (((Obj1EA3AA0_arg0 *)arg0)->unkF4) = 1.0f / func_800139F8(sp20);
    (((Obj1EA3AA0_arg0 *)arg0)->unkE8) = D_80125970;
    func_800CA218(arg0, sp20);
    func_800CA2A8(arg0, sp20);
    BT_NATIVE_ONLY(return) func_800CAF34((s32)arg0);
}

/* extern */

void func_800CA510(void *arg0, f32 arg1) {
    void func_800CA1B0(void *);
    void func_800CA2A8(void *, f32);
    (((Obj1EA3AA0_arg0 *)arg0)->unkE8) = arg1;
    func_800CA1B0(arg0);
    func_800CA2A8(arg0, (((Obj1EA3AA0_arg0 *)arg0)->unkE4) * 0.5f);
}

/* extern */

void func_800CA558(void *arg0, f32 arg1) {
    f32 func_800139F8(f32);
    void func_800CA218(void *, f32);
    void func_800CA2A8(void *, f32);
    f32 sp18;

    sp18 = arg1 * 0.5f;
    (((Obj1EA3AA0_arg0 *)arg0)->unkE4) = arg1;
    (((Obj1EA3AA0_arg0 *)arg0)->unkF4) = (f32) (1.0f / func_800139F8(sp18));
    func_800CA218(arg0, sp18);
    func_800CA2A8(arg0, sp18);
}

void func_800EE7F8();

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800CA5B8(BT_PASS2(s32 bt_a0, s32 bt_a1))
{
    func_800EE7F8(BT_PASS2(bt_a0, bt_a1)); BT_NATIVE_ONLY(return 0;)
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800CA5D8(BT_PASS2(s32 bt_a0, s32 bt_a1))
{
    BT_NATIVE_ONLY(return) func_800EE84C(BT_PASS2(bt_a0, bt_a1));
}

void func_800CA5F8(f32 *arg0, f32 arg1, f32 arg2, f32 arg3) {
    void func_800EFA4C(f32[3], f32, f32, f32);
    func_800EFA4C(arg0, arg1, arg2, arg3);
}

void func_800CA628(f32 *arg0, f32 *arg1, f32 *arg2) {
    s32 i;

    for (i = 0; i < 3; i++) {
        arg0[i] = arg1[i];
        arg0[i + 6] = arg2[i];
    }
}

void func_800CA668(s32 arg0 BT_PASS2(, s32 bt_a1)) { func_800EE7F8(arg0 + 0x18 BT_PASS2(, bt_a1)); }

void func_800CA688(s32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    void func_800EFA4C(f32[3], f32, f32, f32);
    func_800EFA4C(arg0 + 0x18, arg1, arg2, arg3);
}

void func_800CA6C0(void *arg0, f32 arg1, f32 arg2) {
    (((Obj1EA3AA0_arg0 *)arg0)->unkEC) = arg1;
    (((Obj1EA3AA0_arg0 *)arg0)->unkF0) = arg2;
}

void func_800CA6D4(void *arg0, f32 *arg1, f32 *arg2) {
    *arg1 = (((Obj1EA3AA0_arg0 *)arg0)->unkEC);
    *arg2 = (((Obj1EA3AA0_arg0 *)arg0)->unkF0);
}

f32 func_800CA6E8(f32 *arg0) {
    return arg0[89];
}

void func_800CA6F0(void *arg0, f32 arg1) {
    ((Obj1EA3AA0_arg0 *)arg0)->unk164 = arg1;
}

f32 func_800CA6FC(f32 *arg0) {
    return arg0[58];
}

f32 func_800CA704(s32 arg0, s32 arg1, s32 arg2) {
    f32 func_800EEAA4(f32 *, f32 *);
    void func_800EFB24(void *, void *, void *);
    func_800EFB24((void *)arg2, (void *)arg1, (void *)arg0);
    return func_800EEAA4((f32 *)(arg0 + 0xC), (f32 *)arg2);
}

void func_800CA740(void *arg0, f32 *arg1) {
    func_800EE7F8(arg1, (u8 *)arg0 + 0xC);
}

/* extern */

void func_800CA768(s32 arg0, s32 arg1) {
    s32 func_800EEAD4(s32, s32, s32);
    func_800EEAD4(arg1, arg0, arg1);
}

f32 func_800CA794(f32 *arg0) {
    return arg0[57];
}

f32 func_800CA79C(f32 *arg0) {
    return arg0[61];
}

void *func_800CA7A4(void *arg0) {
    return (void *) ((u8 *) arg0 + 0x64);
}

void *func_800CA7AC(void *arg0) {
    return (void *) ((u8 *) arg0 + 0xA4);
}

f32 func_800CA7B4(f32 *arg0) {
    return arg0[59];
}

void func_800CA7BC(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4) {
    *arg1 = (((Obj1EA3AA0_arg0 *)arg0)->unkE4);
    *arg2 = (((Obj1EA3AA0_arg0 *)arg0)->unkE8);
    *arg3 = (((Obj1EA3AA0_arg0 *)arg0)->unkEC);
    *arg4 = (((Obj1EA3AA0_arg0 *)arg0)->unkF0);
}

void func_800CA7E4(s32 arg0, s32 *arg1) { func_800EE7F8(arg1, (s32 *)arg0); }    typedef struct { s32 unk0; s32 unk4; s32 unk8; } Obj1EA3AA0_arg1; /* offsets.py genstruct: fields from raw offsets on arg1; rename once understood */

void func_800CA810(void *arg0, void *arg1) {
    (((Obj1EA3AA0_arg1 *)arg1)->unk0) = (s32) ((f32) (s32) ((((Obj1EA3AA0_arg0 *)arg0)->unk0) * 500.0f) / 500.0f);
    (((Obj1EA3AA0_arg1 *)arg1)->unk4) = (s32) ((f32) (s32) ((((Obj1EA3AA0_arg0 *)arg0)->unk4) * 500.0f) / 500.0f);
    (((Obj1EA3AA0_arg1 *)arg1)->unk8) = (s32) ((f32) (s32) ((((Obj1EA3AA0_arg0 *)arg0)->unk8) * 500.0f) / 500.0f);
}

void func_800CA8B4(f32 *arg0, f32 *arg1, f32 *arg2) {
    s32 i;

    for (i = 0; i < 3; i++) {
        arg1[i] = arg0[i];
        arg2[i] = arg0[i + 6];
    }
}

void func_800CA8F4(f32 *arg0, f32 *arg1, f32 *arg2) {
    s32 i;

    for (i = 0; i < 3; i++) {
        arg1[i] = arg0[i];
        arg2[i] = arg0[i + 3];
    }
}

void func_800CA934(void *arg0, void *arg1) {
    (*(s16 *)((s8 *)(arg1) + (0))) = (s16) (s32) ((f32) (s32) ((((Obj1EA3AA0_arg0 *)arg0)->unk0) * 500.0f) / 500.0f);
    (*(s16 *)((s8 *)(arg1) + (2))) = (s16) (s32) ((f32) (s32) ((((Obj1EA3AA0_arg0 *)arg0)->unk4) * 500.0f) / 500.0f);
    (*(s16 *)((s8 *)(arg1) + (4))) = (s16) (s32) ((f32) (s32) ((((Obj1EA3AA0_arg0 *)arg0)->unk8) * 500.0f) / 500.0f);
}

void func_800CA9D8(f32 *arg0, f32 *arg1) {
    func_800EE7F8(arg1, arg0 + 6);
}

void func_800CAA00(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    *arg1 = (((Obj1EA3AA0_arg0 *)arg0)->unk18);
    *arg2 = (((Obj1EA3AA0_arg0 *)arg0)->unk1C);
    *arg3 = (((Obj1EA3AA0_arg0 *)arg0)->unk20);
}

f32 func_800CAA1C(f32 *arg0) {
    return arg0[7];
}

#include "1EA3AA0_culling.inc"

s32 func_800CAD9C(void *arg0, f32 arg1, f32 arg2, f32 arg3) {
    f32 *p = arg0;

    if ((p[9] * arg1 + p[10] * arg2 + p[11] * arg3 + p[12] <= 0.0f) &&
        (p[13] * arg1 + p[14] * arg2 + p[15] * arg3 + p[16] <= 0.0f) &&
        (p[17] * arg1 + p[18] * arg2 + p[19] * arg3 + p[20] <= 0.0f) &&
        (p[21] * arg1 + p[22] * arg2 + p[23] * arg3 + p[24] <= 0.0f)) {
        return 1;
    }
    return 0;
}

int func_800CAEA4(void *arg0, f32 arg1, f32 arg2, f32 arg3) {
    f32 *p = arg0;
    return p[17] * arg1 + p[18] * arg2 + p[19] * arg3 + p[20] <= 0.0f;
}

f32 func_800CAF00(f32 *arg0, f32 arg1) {
    f32 func_800136E4(f32);
    return func_800136E4(arg0[7] + arg1 + 90.0f);
}

s32 func_800CAF34(s32 arg0) {
    void func_80019224(f32 *, f32 *);
    void func_80019480(f32 *, f32, f32, f32);
    void func_800D93A0(f32[4], f32[3]);
    void func_800D9624(f32 *, f32 *);
    void func_800D965C(f32[4], f32[16]);
    f32 func_800EEAA4(f32 *, f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    f32 sp40[4];
    f32 sp30[4];

    func_800D93A0(sp40, (f32 *)(arg0 + 0x18));
    func_800D965C(sp40, (f32 *)(arg0 + 0x64));
    func_800D9624(sp30, sp40);
    func_800D965C(sp30, (f32 *)(arg0 + 0xA4));
    mlMtxSet((MtxF *)(arg0 + 0x64));
    func_800EFA4C((f32 *)(arg0 + 0xC), 0.0f, 0.0f, -1.0f);
    func_80019224((f32 *)(arg0 + 0xC), (f32 *)(arg0 + 0xC));
    func_80019224((f32 *)(arg0 + 0x24), (f32 *)(arg0 + 0xF8));
    func_80019480((f32 *)(arg0 + 0x34), -*(f32 *)(arg0 + 0xF8), *(f32 *)(arg0 + 0xFC), *(f32 *)(arg0 + 0x100));
    func_80019224((f32 *)(arg0 + 0x44), (f32 *)(arg0 + 0x104));
    func_80019480((f32 *)(arg0 + 0x54), *(f32 *)(arg0 + 0x104), -*(f32 *)(arg0 + 0x108), *(f32 *)(arg0 + 0x10C));
    *(f32 *)(arg0 + 0x30) = -func_800EEAA4((f32 *)arg0, (f32 *)(arg0 + 0x24));
    *(f32 *)(arg0 + 0x40) = -func_800EEAA4((f32 *)arg0, (f32 *)(arg0 + 0x34));
    *(f32 *)(arg0 + 0x50) = -func_800EEAA4((f32 *)arg0, (f32 *)(arg0 + 0x44));
    *(f32 *)(arg0 + 0x60) = -func_800EEAA4((f32 *)arg0, (f32 *)(arg0 + 0x54));
    func_80019480((f32 *)(arg0 + 0x128), -*(f32 *)(arg0 + 0x11C), -*(f32 *)(arg0 + 0x120), *(f32 *)(arg0 + 0x124));
    func_80019224((f32 *)(arg0 + 0x134), (f32 *)(arg0 + 0x11C));
    func_80019224((f32 *)(arg0 + 0x140), (f32 *)(arg0 + 0x110));
    func_80019480((f32 *)(arg0 + 0x14C), -*(f32 *)(arg0 + 0x11C), *(f32 *)(arg0 + 0x120), *(f32 *)(arg0 + 0x124));
    func_80019480((f32 *)(arg0 + 0x158), *(f32 *)(arg0 + 0x11C), -*(f32 *)(arg0 + 0x120), *(f32 *)(arg0 + 0x124)); BT_NATIVE_ONLY(return 0;)
}

void func_800CB0E8(u8 *arg0, f32 *arg1, s32 arg2) { void func_800EE7F8(f32 *, f32 *); func_800EE7F8(arg1, (f32 *)(arg0 + 0x128 + (arg2 * 12))); }

u16 func_800CB124(s32 arg0, MtxF *arg1) {
    void func_800F274C(MtxF *);
    extern f32 D_80125974, D_80125978, D_8012597C, D_80125980;
    s32 i, j;
    f32 near;
    f32 far;
    f32 depth;
    u16 norm;

    near = *(f32 *)(arg0 + 0xEC);
    far = *(f32 *)(arg0 + 0xF0);
    if (near < 1.0f) {
        near = 1.0f;
    }
    if (far < near + 100.0f) {
        far = near + 100.0f;
    }
    depth = (2 * near * far / (near - far)) * 0.5f;
    if (D_80125974 < depth || depth < D_80125978) {
        if (D_80125974 < depth) {
            depth = D_8012597C;
        } else {
            depth = D_80125980;
        }
        near = (-(depth / 0.5f) * far) / (2 * far - depth / 0.5f);
    }
    func_800F274C(arg1);
    arg1->m[0][0] = *(f32 *)(arg0 + 0xF4) / *(f32 *)(arg0 + 0xE8);
    arg1->m[1][1] = *(f32 *)(arg0 + 0xF4);
    arg1->m[2][2] = (near + far) / (near - far);
    arg1->m[2][3] = -1.0f;
    arg1->m[3][2] = 2.0f * near * far / (near - far);
    arg1->m[3][3] = 0.0f;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            arg1->m[i][j] *= 0.5f;
        }
    }
    if (near + far <= 2.0f) {
        norm = 0xFFFF;
    } else {
        norm = (u32)(131072.0f / (near + far));
        if (norm <= 0) {
            norm = 1;
        }
    }
    return norm;
}

#endif
