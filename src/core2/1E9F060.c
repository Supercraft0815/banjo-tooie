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
    s32 func_800BF48C(u8, u8, u8);
    extern ColorTransition D_8012AA20;
    func_800BF48C((*(u8 *)((s8 *)(&D_8012AA20) + (8))), (*(u8 *)((s8 *)(&D_8012AA20) + (9))), (*(u8 *)((s8 *)(&D_8012AA20) + (0xA))));
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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9F060/func_800C5A38.s")

void func_800C5B84(s32 arg0)
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
}
#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9F060/func_800C5BE4.s")

s32 func_800C5CC0(s32 this, f32 arg1, f32 arg2, u32 arg3, s32 arg4) {
    s32 func_800C5BE4(s32, f32, f32, u32, s32);
    f32 mlAbsF(f32);
    s32 phi_v1;

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
}

s32 func_800C5E14(void *arg0) {
    f32 temp_f0;
    f32 temp_f2;
    int temp_v0;

    temp_v0 = (*(u8 *)((s8 *)(arg0) + (0x8F)));
    if (temp_v0 == 0) {
        return 2;
    }
    if ((temp_v0 != 0) && ((*(u8 *)((s8 *)(arg0) + (0x8E))) == 0)) {
        return 4;
    }
    temp_f0 = (*(f32 *)((s8 *)(arg0) + (0x74)));
    if (temp_f0 < (*(f32 *)((s8 *)(arg0) + (0x50)))) {
        return 2;
    }
    temp_f2 = temp_f0 - (*(f32 *)((s8 *)(arg0) + (0x70)));
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
    s32 func_800AAAE0(s32);
    s32 func_800AAD28(s32);
    s32 func_800EE7F8();
    void func_800FB508(void *, void *);
    if (arg6 != 0) {
        func_800AAD28((u8 *)arg0 + 0x1C);
        func_800AAAE0((u8 *)arg0 + 0x40);
        func_800FB508((u8 *)arg0 + 4, arg6);
    }
    (*(s8 *)((s8 *)(arg0) + (0x8E))) = 1;
    (*(s32 *)((s8 *)(arg0) + (0x7C))) = arg2;
    (*(s16 *)((s8 *)(arg0) + (0x8C))) = (s16) arg3;
    (*(f32 *)((s8 *)(arg0) + (0x70))) = arg1;
    (*(s32 *)((s8 *)(arg0) + (0))) = arg5;
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
}

void func_800C5FCC(void *arg0, f32 value, s32 triangle) {
    void func_800FB508(void *, void *);
    if (*(u8 *)((u8 *)arg0 + 0x9C) != 0) {
        value = *(f32 *)((u8 *)arg0 + 0x98);
    }
    if (triangle != 0) {
        func_800FB508((u8 *)arg0 + 0x10, (void *)triangle);
    }
    if (triangle != 0) {
        *(s32 *)((u8 *)arg0 + 0x80) = *(s32 *)((u8 *)triangle + 8);
    }
    *(u8 *)((u8 *)arg0 + 0x8F) = 1;
    *(f32 *)((u8 *)arg0 + 0x74) = value;
}

void func_800C6038(void *ptr) {
    void func_800C5FCC(void *, f32, s32);
    func_800C5FCC(ptr, -19000.0f, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9F060/func_800C6060.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9F060/func_800C6320.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9F060/func_800C6420.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9F060/func_800C65E0.s")

u32 func_800C6704(u8 *arg0) {
    return arg0[142];
}

u8 func_800C670C(void *arg0) {
    extern f32 D_801258AC;
    if (D_801258AC == (*(f32 *)((s8 *)(arg0) + (0x74)))) {
        return 0U;
    }
    return (*(u8 *)((s8 *)(arg0) + (0x8F)));
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
    s32 func_800EE7F8();
    func_800EE7F8(arg1, (u8 *)arg0 + 0x64);
}

f32 func_800C6784(void *arg0) {
    f32 temp_f2;

    if ((*(u8 *)((s8 *)(arg0) + (0x95))) != 0) {
        temp_f2 = (*(f32 *)((s8 *)(arg0) + (0x74))) - 15.0f;
        if ((*(f32 *)((s8 *)(arg0) + (0x70))) < temp_f2) {
            return temp_f2;
        }
    }
    return (*(f32 *)((s8 *)(arg0) + (0x70)));
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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E9F060/func_800C6840.s")

void func_800C68A0(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)arg0 + 120) = arg1;
}

/* extern */

void func_800C68AC(s32 arg0) {
    s32 func_800EE7F8(s32);
    func_800EE7F8(arg0 + 0x4C);
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
