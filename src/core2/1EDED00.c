#include "common.h"
extern s32 D_80136ED8;

void func_80105410(void) {
    s32 freelist_new(s32, s32);
    extern s32 D_80136EC0;
    D_80136EC0 = freelist_new(0x48, 8);
}

void func_80105438(void) {
    s32 freelist_free(s32);
    extern s32 D_80136EC0;
    freelist_free(D_80136EC0);
}

void func_8010545C(void) {
    s32 freelist_defrag(s32);
    extern s32 D_80136EC0;
    if (D_80136EC0 != 0) {
        D_80136EC0 = freelist_defrag(D_80136EC0);
    }
}

void *func_80105494(Actor *arg0) {
    extern s32 D_80136EC0;
    void *freelist_at(s32, s32);
    if (arg0->unk7C_0 == 0) {
        return NULL;
    }
    return freelist_at(D_80136EC0, arg0->unk7C_0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_801054D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_8010556C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_80105634.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_8010568C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_801056EC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_8010573C.s")

void func_80105834()
{
    func_801054D4();
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_80105854.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_8010588C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_801058C4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_80105998.s")

/* extern */

s32 func_80105A5C(Actor *arg0) {
    void *func_80105494(Actor *);

    return (*(f32 *)((s8 *)func_80105494(arg0) + 0xC)) == 1.0f;
}

void func_80105A9C(Actor *arg0, f32 arg1) {
    void *func_80105494(Actor *);
    (*(f32 *)((s8 *)(func_80105494(arg0)) + 0x14)) = arg1;
}

/* extern */

f32 func_80105AC4(Actor *arg0) {
    void *func_80105494(Actor *);
    return (*(f32 *)((s8 *)(func_80105494(arg0)) + (0x14)));
}

/* extern */

f32 func_80105AE8(Actor *arg0) {
    void *func_80105494(Actor *);
    return (*(f32 *)((s8 *)(func_80105494(arg0)) + (0xC)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_80105B0C.s")

void func_80105BAC(Actor *arg0) {
    void *func_80105494(Actor *);
    struct {
        u8 pad[0x18];
        u8 flag : 1;
        u8 rest : 7;
    } *temp_v0;

    temp_v0 = func_80105494(arg0);
    if (temp_v0 != NULL) {
        temp_v0->flag = 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_80105BE0.s")

void func_80105C20(void) {
    s32 freelist_new(s32, s32);
    extern s32 D_80136ED0;
    D_80136ED0 = freelist_new(0x8, 0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_80105C48.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_80105CD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_80105DFC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_801060E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_80106138.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_801061D8.s")

s32 func_80106314()
{
    return D_80136ED8;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_80106320.s")

void func_801063C0(void *arg0) {
    void *freelist_at(s32, s32);
    extern s32 D_80136ED0;
    freelist_at(D_80136ED0, (*(s16 *)((s8 *)(arg0) + (0x90))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_801063EC.s")

/* extern */

void func_8010647C(void *arg0) {
    s32 func_801063EC(s16);
    func_801063EC((*(s16 *)((s8 *)(arg0) + (0x90))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_8010649C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_80106520.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDED00/func_801065A4.s")
