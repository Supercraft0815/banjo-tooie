#include "common.h"

typedef struct {
    f32 unk0;
    f32 unk4;
    u8 rgb[3];
    u8 unkB[3];
    u8 unkE[3];
    u8 unk11;
} ColorTransition;     

void func_800C5770(void) {
}

void func_800C5778(void){
    extern ColorTransition D_8012AA20;

    D_8012AA20.unk11 = 0;
    D_8012AA20.unk0 = D_8012AA20.unk4 = 0.0f;
    D_8012AA20.unkE[0] = D_8012AA20.unkE[1] = D_8012AA20.unkE[2] = 0xFF;
    D_8012AA20.unkB[0] = D_8012AA20.unkB[1] = D_8012AA20.unkB[2] = 0xFF;
    D_8012AA20.rgb[0] = D_8012AA20.rgb[1] = D_8012AA20.rgb[2] = 0xFF;
}

void func_800C57C0(void) {
    void func_800BF48C(s32 r,s32 g,s32 b);
    extern ColorTransition D_8012AA20;
    func_800BF48C((D_8012AA20.rgb[0]), (D_8012AA20.rgb[1]), (D_8012AA20.rgb[2]));
}

void func_800C57F0(void) {
    extern ColorTransition D_8012AA20;

    void func_800C57C0(void);
    f32 func_800F10B4(f32 val, f32 in_min, f32 in_max, f32 out_min, f32 out_max);
    f32 func_800F0E00(f32 arg0, f32 arg1);
    f32 func_800D8FF8(void);

    s32 i;

    if (D_8012AA20.unk11 != 0) {
        D_8012AA20.unk0 = func_800F0E00(0.0f, D_8012AA20.unk0 - func_800D8FF8());
        for(i = 0; i < 3; i++){
            D_8012AA20.rgb[i] = func_800F10B4(D_8012AA20.unk0, D_8012AA20.unk4, 0.0f,D_8012AA20.unkE[i], D_8012AA20.unkB[i]);
        }
        func_800C57C0();
        if (D_8012AA20.unk0 == 0.0f) {
            D_8012AA20.unk11 = 0;
        }
    }
}

void func_800C5968(s32 red, s32 blue, s32 green, f32 arg3) {
    extern ColorTransition D_8012AA20;

    void func_800C57C0(void);

    if (arg3 != 0.0f) {
        D_8012AA20.unk11 = 1;
        D_8012AA20.unk0 = arg3;
        D_8012AA20.unk4 = arg3;
        D_8012AA20.unkB[0] = red;
        D_8012AA20.unkB[1] = blue;
        D_8012AA20.unkB[2] = green;
        D_8012AA20.unkE[0] = D_8012AA20.rgb[0];
        D_8012AA20.unkE[1] = D_8012AA20.rgb[1];
        D_8012AA20.unkE[2] = D_8012AA20.rgb[2];
        return;
    }
    else{
        D_8012AA20.unk11 = 0;
        D_8012AA20.rgb[0] = red;
        D_8012AA20.rgb[1] = blue;
        D_8012AA20.rgb[2] = green;
        func_800C57C0();
    }
}

/* extern */

void func_800C59F0(s32 arg0, s32 arg1, s32 arg2) {
    void func_800C5968(s32, s32, s32, f32);
    func_800C5968(arg0, arg1, arg2, 0.0f);
}

void func_800C5A10(u8 *arg0, s32 arg1) {
    if (arg1 == 1) {
        arg0[0x93] = 5;
    }
    if (arg1 == 4) {
        arg0[0x92] = 1;
    }
    arg0[0x94] = arg1;
}

u8 *func_800C5A38(void) {
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_800EFD24(f32 *);
    void *heap_alloc(s32);


    struct allocation {
        s32 model;
        s16 a[3];
        s16 b;
        s32 c;
        s16 d[3];
        s16 e;
        s32 f;
        f32 vectors[3][3];
        u8 colors[3][4];
        f32 v4C[3];
        f32 v58[3];
        f32 v64[3];
        f32 x, y, z;
        s32 f7C, f80, f84, f88;
        s16 f8C;
        u8 f8E, f8F, f90, f91, f92, f93, f94, f95;
        u8 pad[6];
        u8 f9C;
    } *this;
    int i;
    s32 j;
    u8 *ptr;

    this = heap_alloc(sizeof(*this));
    func_800EFD24(this->v4C);
    func_800EFD24(this->v58);
    for (i = 0; i < 36; i += 12) {
        func_800EFD24((f32 *)((u8 *)this + 0x1C + i));
    }
    i = 0;
    j = i;
    ptr = (u8 *)this;
    do {
        j++;
        ptr += 4;
        ptr[0x3D] = 0xFF;
        ptr[0x3E] = 0xFF;
        ptr[0x3F] = 0xFF;
        ptr[0x3C] = 0xFF;
    } while (j < 3);
    j = 0;
    ptr = (u8 *)this;
    do {
        j++;
        ptr += 2;
        *(s16 *)(ptr + 2) = 0;
        *(s16 *)(ptr + 0xE) = 0;
    } while (j != 3);
    this->e = 0;
    this->f = 0;
    this->c = 0;
    this->b = this->e;
    func_800EFA4C(this->v64, 0.0f, 1.0f, 0.0f);
    this->x = -18000.0f;
    this->f7C = 0;
    this->f8C = 0;
    this->y = -19000.0f;
    this->f80 = this->f7C;
    this->f8E = 0;
    this->f90 = this->f8E;
    this->f8F = 0;
    this->f91 = this->f8F;
    this->f84 = this->f80;
    this->model = 0;
    this->f88 = 0x1F00;
    this->f95 = 0;
    this->f9C = 0;
    this->f94 = 0;
    this->z = 100.0f;
    func_800C5A10((u8 *)this, 1);
    return (u8 *)this;
}

void func_800C5B84(BtIntPtr arg0)
{
    func_800C5A10(arg0,1);
}

void func_800C5BA4(void* arg0) 
{
    heap_free(arg0);
}
void* func_800C5BC4(void* arg0) 
{
    return defrag(arg0);
}                   typedef struct { u8 pad0[0xC]; f32 unkC; s32 unk10; s16 unk14; u8 pad16[0x2]; void * unk18; } Obj1E9F060_arg4; /* offsets.py genstruct: fields from raw offsets on arg4; rename once understood */
BtIntPtr func_800C5BE4(f32 *arg0, f32 arg1, f32 arg2, u32 arg3, void *arg4) {
    s32 *func_800BEF00(f32[3], f32[3], f32[3], s32);
    void *func_800C6A7C(f32[3], f32[3], f32[3], u32);
    void *func_800C69FC(void);
    void func_800EE7F8(f32 *, f32 *);
    f32 sp34[3];
    f32 sp28[3];
    s32 *sp24;

    func_800EE7F8(sp34, arg0);
    sp34[1] = sp34[1] + arg1;
    func_800EE7F8(sp28, arg0);
    sp28[1] = sp28[1] + arg2;
    if (arg3 == 0x1F00) {
        sp24 = func_800BEF00(sp34, sp28, arg4, arg3);
    } else {
        sp24 = func_800C6A7C(sp34, sp28, arg4, arg3);
    }
    if (sp24 != NULL) {
        ((Obj1E9F060_arg4 *)arg4)->unk10 = sp24[2];
        ((Obj1E9F060_arg4 *)arg4)->unk14 = 0;
    } else {
        ((Obj1E9F060_arg4 *)arg4)->unk10 = 0;
        ((Obj1E9F060_arg4 *)arg4)->unk14 = 0;
    }
    ((Obj1E9F060_arg4 *)arg4)->unkC = sp28[1];
    ((Obj1E9F060_arg4 *)arg4)->unk18 = func_800C69FC();
    return sp24;
}

BtIntPtr func_800C5CC0(f32 *this, f32 arg1, f32 arg2, u32 arg3, void *arg4) {
    BtIntPtr func_800C5BE4(f32 *, f32, f32, u32, void *);
    f32 mlAbsF(f32);
    BtIntPtr phi_v1;

    if (mlAbsF(arg2 - arg1) > 500.0f) {
        if (arg1 < arg2) {
            phi_v1 = func_800C5BE4(this, arg1, arg1 + 500.0f, arg3, arg4);
            if (phi_v1 == 0) {
                phi_v1 = func_800C5BE4(this, arg1 + 500.0f - 1.0f, arg2, arg3, arg4);
            }
        } else {
            phi_v1 = func_800C5BE4(this, arg1, arg1 - 500.0f, arg3, arg4);
            if (phi_v1 == 0) {
                phi_v1 = func_800C5BE4(this, arg1 - 500.0f + 1.0f, arg2, arg3, arg4);
            }
        }
    } else {
        phi_v1 = func_800C5BE4(this, arg1, arg2, arg3, arg4);
    }
    return phi_v1;
}    typedef struct { s32 unk0; u8 pad4[0x4C]; f32 unk50; u8 pad54[0x1C]; f32 unk70; f32 unk74; f32 unk78; s32 unk7C; s32 unk80; u8 pad84[0x8]; s16 unk8C; u8 unk8E; u8 unk8F; u8 pad90[0x5]; u8 unk95; u8 pad96[0x2]; f32 unk98; u8 unk9C; } Obj1E9F060_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

s32 func_800C5E14(void *arg0) {
    f32 temp_f0;
    f32 temp_f2;
    int temp_v0;

    temp_v0 = (((Obj1E9F060_arg0 *)arg0)->unk8F);
    if (temp_v0 == 0) {
        return 2;
    }
    if ((temp_v0 != 0) && ((((Obj1E9F060_arg0 *)arg0)->unk8E) == 0)) {
        return 4;
    }
    temp_f0 = (((Obj1E9F060_arg0 *)arg0)->unk74);
    if (temp_f0 < (((Obj1E9F060_arg0 *)arg0)->unk50)) {
        return 2;
    }
    temp_f2 = temp_f0 - (((Obj1E9F060_arg0 *)arg0)->unk70);
    if (temp_f2 < -20.0f) {
        return 2;
    }
    if (temp_f2 > 100.0f) {
        return 4;
    }
    return 3;
}

/* extern */

void func_800C5EB8(void *arg0, f32 arg1, s32 arg2, s32 arg3, void *arg4, s32 arg5, void *arg6) {
    void func_800AAAE0(u8 *arg0);
    void func_800AAD28(f32 *arg0);
    void func_800EE7F8();
    void func_800FB508(void *, void *);
    if (arg6 != 0) {
        func_800AAD28((u8 *)arg0 + 0x1C);
        func_800AAAE0((u8 *)arg0 + 0x40);
        func_800FB508((u8 *)arg0 + 4, arg6);
    }
    (*(s8 *)((s8 *)(arg0) + (0x8E))) = 1;
    (((Obj1E9F060_arg0 *)arg0)->unk7C) = arg2;
    (((Obj1E9F060_arg0 *)arg0)->unk8C) = (s16) arg3;
    (((Obj1E9F060_arg0 *)arg0)->unk70) = arg1;
    (((Obj1E9F060_arg0 *)arg0)->unk0) = arg5;
    func_800EE7F8((u8 *)arg0 + 0x64, arg4);
}

void func_800C5F40(void *ptr, void *arg1, void *triangle) {
    void func_800C5EB8(void *, f32, s32, s32, void *, s32, void *);
    u8 *data = arg1;
    func_800C5EB8(ptr, *(f32 *)(data + 0xC), *(s32 *)(data + 0x10), *(s16 *)(data + 0x14), data, *(s32 *)(data + 0x18), triangle);
}

void func_800C5F8C(void *ptr) {
    extern u8 D_8011A890[];
    void func_800C5EB8(void *, f32, s32, s32, void *, s32, void *);
    func_800C5EB8(ptr, -18000.0f, 0, 0, D_8011A890, 0, NULL);
}    typedef struct { u8 pad0[0x8]; s32 unk8; } Obj1E9F060_func_800C5FCC_triangle; /* offsets.py genstruct: fields from raw offsets on triangle; rename once understood */

void func_800C5FCC(void *arg0, f32 value, BtIntPtr triangle) {
    void func_800FB508(void *, void *);
    if (((Obj1E9F060_arg0 *)arg0)->unk9C != 0) {
        value = ((Obj1E9F060_arg0 *)arg0)->unk98;
    }
    if (triangle != 0) {
        func_800FB508((u8 *)arg0 + 0x10, (void *)triangle);
    }
    if (triangle != 0) {
        ((Obj1E9F060_arg0 *)arg0)->unk80 = ((Obj1E9F060_func_800C5FCC_triangle *)triangle)->unk8;
    }
    ((Obj1E9F060_arg0 *)arg0)->unk8F = 1;
    ((Obj1E9F060_arg0 *)arg0)->unk74 = value;
}

void func_800C6038(void *ptr) {
    void func_800C5FCC(void *, f32, BtIntPtr);
    func_800C5FCC(ptr, -19000.0f, 0);
}

void func_800C6060(u8 *arg0) {
    s32 func_800DA298(s32);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_800F0E00(f32, f32);

    f32 sp64;
    f32 sp48[7];
    BtIntPtr triangle;
    f32 sp38[3];
    const s32 mask = 0x20020;
    s32 sp30;

    sp30 = 0;
    func_800EE7F8(sp38, (f32 *)(arg0 + 0x4C));
    sp64 = *(f32 *)(arg0 + 0x78);
    if (func_800DA298(0x6B5)) {
        triangle = func_800C5CC0(sp38, func_800F0E00(*(f32 *)(arg0 + 0x5C) - *(f32 *)(arg0 + 0x50), 150.0f) + 10.0f, -5.0f, *(u32 *)(arg0 + 0x88), sp48);
        if (triangle != 0 || arg0[0x9C] != 0) {
            func_800C5FCC(arg0, sp48[3], triangle);
            sp30 = 1;
        }
    }
    triangle = func_800C5CC0(sp38, sp64, -1300.0f, *(u32 *)(arg0 + 0x84), sp48);
    if (triangle == 0) {
        func_800C5F8C(arg0);
        if (!sp30) {
            func_800C6038(arg0);
        } else if (*(f32 *)(arg0 + 0x50) < *(f32 *)(arg0 + 0x74)) {
            func_800C5A10(arg0, 3);
        }
    } else {
        if (*(s32 *)(triangle + 8) & 0x20020U) {
            func_800C5FCC(arg0, sp48[3], triangle);
            if ((*(f32 *)(arg0 + 0x70) < *(f32 *)(arg0 + 0x74)) && (*(f32 *)(arg0 + 0x50) < *(f32 *)(arg0 + 0x74))) {
                func_800C5A10(arg0, 3);
            }
            triangle = func_800C5CC0(sp38, sp64, -450.0f, mask | *(u32 *)(arg0 + 0x84), sp48);
            if (triangle == 0) {
                func_800C5F8C(arg0);
            } else if (sp48[1] >= 0.0f) {
                func_800C5F40(arg0, sp48, (void *)triangle);
            }
        } else {
            if ((sp48[1] < 0.0f) && !(*(s32 *)(triangle + 8) & 0x10000)) {
                sp64 = sp48[3] - sp38[1];
                triangle = func_800C5CC0(sp38, sp64 - 1.0f, sp64 - 1.3e+03f, *(u32 *)(arg0 + 0x84) | mask, sp48);
                if (triangle != 0) {
                    func_800C5F40(arg0, sp48, (void *)triangle);
                } else {
                    func_800C5F8C(arg0);
                }
            } else {
                func_800C5F40(arg0, sp48, (void *)triangle);
                if (sp30) {
                    func_800C5A10(arg0, 3);
                } else {
                    func_800C6038(arg0);
                }
            }
        }
    }
}

void func_800C6320(u8 *arg0) {
    void func_800EE7F8();
    f32 sp44[7];
    BtIntPtr triangle;
    s32 state;
    f32 sp30[3];
    f32 distance;

    func_800EE7F8(sp30, (f32 *)(arg0 + 0x4C));
    triangle = func_800C5CC0(sp30, *(f32 *)(arg0 + 0x78), -1300.0f, *(u32 *)(arg0 + 0x84) | 0x20020, sp44);
    if ((triangle != 0) && (sp44[1] >= 0.0f)) {
        func_800C5F40(arg0, sp44, (void *)triangle);
    }
    distance = *(f32 *)(arg0 + 0x74) - sp30[1];
    triangle = func_800C5CC0(sp30, distance + 50.0f, distance - 50.0f, *(u32 *)(arg0 + 0x88), sp44);
    if ((triangle != 0) || (arg0[0x9C] != 0)) {
        func_800C5FCC(arg0, sp44[3], triangle);
    }
    state = func_800C5E14(arg0);
    if (state != 3) {
        func_800C5A10(arg0, state);
    }
}

void func_800C6420(u8 *arg0) {
    s32 func_8001210C(s32);
    void func_800EE7F8(f32 *, f32 *);
    f32 sp4C[7];
    s32 sp48;
    BtIntPtr triangle;
    s32 sp40;
    s32 state;
    f32 sp30[3];
    f32 distance;

    func_800EE7F8(sp30, (f32 *)(arg0 + 0x4C));
    sp48 = (*(f32 *)(arg0 + 0x50) - *(f32 *)(arg0 + 0x70) > 120.0f) ? 1 : 0;
    sp40 = func_8001210C(1);
    if ((sp48 == 0) || (sp40 != 0)) {
        if (sp48 != 0) {
            arg0[0x8F] = arg0[0x91];
        }
        triangle = func_800C5CC0(sp30, *(f32 *)(arg0 + 0x78), -390.0f, *(u32 *)(arg0 + 0x84) | 0x20020, sp4C);
        if (triangle != 0) {
            if (sp4C[1] >= 0.0f) {
                func_800C5F40(arg0, sp4C, (void *)triangle);
            }
        } else {
            func_800C5F8C(arg0);
        }
    }
    if ((sp48 == 0) || (sp40 == 0)) {
        if (sp48 != 0) {
            arg0[0x8E] = arg0[0x90];
        }
        distance = *(f32 *)(arg0 + 0x74) - sp30[1];
        triangle = func_800C5CC0(sp30, distance + 140.0f, distance - 140.0f, *(u32 *)(arg0 + 0x88), sp4C);
        if ((triangle != 0) || (arg0[0x9C] != 0)) {
            func_800C5FCC(arg0, sp4C[3], triangle);
            arg0[0x92] = 1U;
        } else if (arg0[0x92] != 0) {
            arg0[0x92] = 0U;
            arg0[0x8F] = 1U;
        }
    }
    state = func_800C5E14(arg0);
    if (state != 4) {
        func_800C5A10(arg0, state);
    }
}

void func_800C65E0(u8 *arg0) {
    void func_800C6060(u8 *);
    void func_800C6420(u8 *);
    void func_800EE7F8(f32 *, f32 *);
    f32 sp3C[7];
    BtIntPtr triangle;
    u8 state;
    u8 initialState;

    initialState = arg0[0x94];
    state = initialState;
    arg0[0x90] = arg0[0x8E];
    arg0[0x91] = arg0[0x8F];
    arg0[0x8E] = arg0[0x8F] = 0U;
    if ((state == 1) || (arg0[0x93] != 0)) {
        arg0[0x93]--;
        triangle = func_800C5BE4((f32 *)(arg0 + 0x4C), -100.0f, 7000.0f, *(u32 *)(arg0 + 0x88), sp3C);
        if (triangle != 0) {
            func_800C5FCC(arg0, sp3C[3], triangle);
        }
        if (triangle != 0) {
            func_800C5A10(arg0, 3);
        } else {
            func_800C5A10(arg0, 2);
        }
        state = arg0[0x94];
    }
    switch (state) {
        case 2:
            func_800C6060(arg0);
            break;
        case 3:
            func_800C6320(arg0);
            break;
        case 4:
            func_800C6420(arg0);
            break;
    }
    func_800EE7F8((f32 *)(arg0 + 0x58), (f32 *)(arg0 + 0x4C));
}

u32 func_800C6704(u8 *arg0) {
    return arg0[142];
}

u8 func_800C670C(void *arg0) {

    if (-19000.0f == (((Obj1E9F060_arg0 *)arg0)->unk74)) {
        return 0U;
    }
    return (((Obj1E9F060_arg0 *)arg0)->unk8F);
}

f32 func_800C673C(f32 *arg0) {
    return arg0[30];
}

s32 func_800C6744(s32 *arg0) {
    return arg0[31];
}

s32 func_800C674C(s16 *arg0) {
    return arg0[70];
}

u32 func_800C6754(u8 *arg0) {
    return arg0[149];
}

void func_800C675C(void *arg0, f32 *arg1) {
    void func_800EE7F8();
    func_800EE7F8(arg1, (u8 *)arg0 + 0x64);
}

f32 func_800C6784(void *arg0) {
    f32 temp_f2;

    if ((((Obj1E9F060_arg0 *)arg0)->unk95) != 0) {
        temp_f2 = (((Obj1E9F060_arg0 *)arg0)->unk74) - 15.0f;
        if ((((Obj1E9F060_arg0 *)arg0)->unk70) < temp_f2) {
            return temp_f2;
        }
    }
    return (((Obj1E9F060_arg0 *)arg0)->unk70);
}

s32 func_800C67C8(s32 *arg0) {
    return arg0[0];
}

u32 func_800C67D0(u8 *arg0) {
    return arg0[156];
}

f32 func_800C67D8(f32 *arg0) {
    return arg0[29];
}

s32 func_800C67E0(s32 *arg0) {
    return arg0[32];
}

void *func_800C67E8(void *arg0) {
    return (u8 *) arg0 + 0x10;
}

void *func_800C67F0(void *arg0) {
    return (u8 *) arg0 + 4;
}

void func_800C67F8(u8 *arg0, u8 *arg1) {
    s32 i;
    for (i = 0; i < 3; i++) {
        arg1[i * 4] = arg0[i * 4 + 0x40];
        arg1[i * 4 + 1] = arg0[i * 4 + 0x41];
        arg1[i * 4 + 2] = arg0[i * 4 + 0x42];
        arg1[i * 4 + 3] = arg0[i * 4 + 0x43];
    }
}

void func_800C6840(f32 *arg0, f32 *arg1) {
    void func_800EE7F8();
    s32 var_s0;
    f32 *var_s1;
    f32 *var_s2;

    var_s0 = 0;
    var_s1 = arg1;
    var_s2 = arg0 + 7;
    do {
        func_800EE7F8(var_s1, var_s2);
        var_s0 += 0xC;
        var_s1 += 3;
        var_s2 += 3;
    } while (var_s0 != 0x24);
}

void func_800C68A0(void *arg0, f32 arg1) {
    ((Obj1E9F060_arg0 *)arg0)->unk78 = arg1;
}

/* extern */

void func_800C68AC(s32 arg0 BT_PASS2(, s32 bt_a1)) {
    void func_800EE7F8();
    func_800EE7F8(arg0 + 0x4C BT_PASS2(, bt_a1));
}

void func_800C68CC(s32 *arg0, s32 arg1) {
    arg0[33] = arg1;
}

void func_800C68D4(s8 *arg0, s32 arg1) {
    arg0[149] = arg1;
}

void func_800C68DC(s8 *arg0) {
    arg0[147] = 1;
}

void func_800C68E8(s8 *arg0, s32 arg1, f32 arg2) {
    if ((*(u8 *)(arg0 + 0x9C) != 0) && (arg1 == 0)) {
        arg0[0x93] = 1;
    }
    if (arg1 != 0) {
        (*(f32 *)(arg0 + 0x98)) = arg2;
    }
    (*(u8 *)(arg0 + 0x9C)) = arg1;
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
ColorTransition D_8012AA20 BT_DATA(16, bss_core2bss1_0_2_tail, 0x0);
#endif
