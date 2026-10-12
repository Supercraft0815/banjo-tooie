#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EB3D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EB51C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EB5E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EB70C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EB750.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EB7A8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EB800.s")

s32 func_800EB854(void) {
    extern s16 D_80132E9C;

    return D_80132E9C;
}

void func_800EB860(s32 arg0, s32 arg1) {
    extern s32 D_80132EA0;
    (*(s32 *)((s8 *)(&D_80132EA0) + (0x20))) = arg0;
    (*(s32 *)((s8 *)(&D_80132EA0) + (0x24))) = arg1;
}

void func_800EB874(void)
{
    extern s32 D_80132EC0;

    D_80132EC0 = 0;
}

void func_800EB880(s32 *arg0, s32 arg1, s32 arg2) {
    extern s32 D_80132EA0;
    s32 *dst = &D_80132EA0;
    dst[0] = arg0[0];
    dst[1] = arg0[1];
    dst[2] = arg0[2];
    dst[4] = arg1;
    dst[5] = 0;
    dst[3] = arg2 * arg2;
    dst[6] = 0;
    dst[7] = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EB8C0.s")

s32 func_800EBB30(s32 *arg0, s32 *arg1) {
    extern s32 D_80132EA0;
    *arg0 = (*(s32 *)((s8 *)(&D_80132EA0) + (0x14)));
    *arg1 = (*(s32 *)((s8 *)(&D_80132EA0) + (0x18)));
    return (*(s32 *)((s8 *)(&D_80132EA0) + (0x1C)));
}

OSThread *func_800EBB50(void)
{
    extern u8 D_80123540[];

    return (OSThread *) D_80123540;
}

void func_800EBB5C(void) {
    extern s32 D_8013546C;
    D_8013546C = 0x6B7;
}

void func_800EBB6C(void) {
}

s32 func_800EBB74(void) {
    extern s32 D_80132ED0;
    return (s32)&D_80132ED0 ? 1 : 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EBB94.s")

void func_800EBC04(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EBC0C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EBCD0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EBD2C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EBD78.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EBE24.s")

/* extern */

void func_800EBE74(s32 arg0, void *arg1, s32 arg2) {
    s32 func_800BDBC4(s32);
    s32 func_800BDC44();
    s32 func_800EBC0C(s32, s32, void *, s32);
    s32 var_v0;

    if ((*(s32 *)((s8 *)(arg1) + (0x10))) & 1) {
        var_v0 = func_800BDC44();
    } else {
        var_v0 = func_800BDBC4(arg0);
    }
    func_800EBC0C(var_v0, arg0, arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EBED4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EBF8C.s")

void func_800EBFD4(s32 arg0, s32 *arg1, u32 arg2) {
    Actor*  func_800EBF8C(s32, s32*, u32, Prop*);
    func_800EBF8C(arg0, arg1, arg2, NULL);
}

/* extern */

void func_800EBFF4(void *arg0) {
    s32 func_800BDB9C(s16);
    s32 func_800E9AC0(s32, s32);
    s32 func_800EBE24(void *);
    func_800E9AC0(func_800BDB9C((*(s16 *)((s8 *)(arg0) + (0x1C)))), (*(s32 *)((s8 *)(arg0) + (0))));
    func_800EBE24(arg0);
}

void func_800EC030(void **arg0, void *arg1) {
    (*(s16 *)((s8 *)(*arg0) + (4))) = (s16) (*(s32 *)((s8 *)(arg1) + (0)));
    (*(s16 *)((s8 *)(*arg0) + (6))) = (s16) (*(s32 *)((s8 *)(arg1) + (4)));
    (*(s16 *)((s8 *)(*arg0) + (8))) = (s16) (*(s32 *)((s8 *)(arg1) + (8)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EC058.s")

/* extern */

void func_800EC0EC(f32 *arg0, s32 arg1) {
    void func_800EE904(s32 dst[3], f32 src[3]);
    s32 func_800EC058(s32 *, s32);
    s32 sp1C[3];

    func_800EE904(sp1C, arg0);
    func_800EC058(sp1C, arg1);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EC124.s")

void func_800EC340(void *arg0, s32 arg1) {
    struct Fields {
        u8 pad[26];
        u16 upper : 11;
        u16 lower : 5;
    };
    ((struct Fields *)arg0)->upper = arg1;
}

void func_800EC358(s32 *arg0, s32 arg1) {
    arg0[3] = arg1;
}

void func_800EC360(s16 *arg0, s32 arg1) {
    arg0[10] = arg1;
}

void func_800EC368(s16 *arg0, s32 arg1) {
    arg0[11] = arg1;
}

void func_800EC370(void **arg0, void *arg1) {
    (*(s16 *)((s8 *)(arg1) + (0))) = (s16) (*(s16 *)((s8 *)(*arg0) + (4)));
    (*(s16 *)((s8 *)(arg1) + (2))) = (s16) (*(s16 *)((s8 *)(*arg0) + (6)));
    (*(s16 *)((s8 *)(arg1) + (4))) = (s16) (*(s16 *)((s8 *)(*arg0) + (8)));
}

void func_800EC398(s32 *arg0, f32 *arg1) {
    void func_800EE88C(f32 dst[3], s16 src[3]);
    func_800EE88C(arg1, *arg0 + 4);
}

void func_800EC3C4(void *arg0) {
    (*(s32 (**)())((s8 *)(arg0) + (8)))();
}

/* extern */

s32 func_800EC3E8(u8 *arg0) {
    void *func_800D674C(s32);
    s32 temp_a1;

    temp_a1 = (*(u16 *)((s8 *)(arg0) + (0x14)));
    if ((temp_a1 == 0) || (temp_a1 == 0xFFFF)) {
        return 0;
    }
    return (s32)func_800D674C(temp_a1);
}

/* extern */

s32 func_800EC428(void *arg0) {
    void *func_800D674C(s32);
    s32 func_801039E4(void *);
    s32 temp_a0;

    if ((*(u16 *)((s8 *)(arg0) + (0x18))) & 1) {
        return func_801039E4(arg0);
    }
    temp_a0 = (*(u16 *)((s8 *)(arg0) + (0x14)));
    if ((temp_a0 == 0) || (temp_a0 == 0xFFFF)) {
        return 0;
    }
    return (s32)func_800D674C(temp_a0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EC48C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EC504.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EC5C0.s")

f32 func_800EC708(void **marker) {
    f32 func_800EC5C0(void *, void *);
    void func_800EC504(void);
    void func_800EC48C(void);
    typedef struct { u8 pad0[8]; u32 reserved : 30; u32 isModel : 1; u32 flag : 1; } PropView;
    PropView *prop = *marker;
    if (prop->isModel) return func_800EC5C0(prop, func_800EC504);
    else return func_800EC5C0(prop, func_800EC48C);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EC75C.s")

/* extern */

void func_800EC7D4(Unk80132ED0 *arg0, s32 arg1) {
    Actor* func_80106790(Unk80132ED0 *);
    s32 func_8010A79C(Actor *, s32);
    func_8010A79C(func_80106790(arg0), arg1);
}

int func_800EC800(void *arg0) {
    return ((*(u16 *)((u8 *)arg0 + 0x18) & 1) != 0)
        && (*(u16 *)((u8 *)arg0 + 0x14) != 0);
}

void func_800EC828(void) {
    extern s32 D_80132ED0;
    (*(s32 *)((s8 *)(&D_80132ED0) + (0x259C)))--;
    if ((*(s32 *)((s8 *)(&D_80132ED0) + (0x259C))) < 0x6B7) {
        (*(s32 *)((s8 *)(&D_80132ED0) + (0x259C))) = 0x7FFF;
    }
}

s32 func_800EC854(void) {
    extern s32 D_80132ED0;
    s32 temp_t6;
    s32 temp_v1;

    temp_v1 = (*(s32 *)((s8 *)(&D_80132ED0) + (0x259C)));
    (*(s32 *)((s8 *)(&D_80132ED0) + (0x259C)))++;
    if ((*(s32 *)((s8 *)(&D_80132ED0) + (0x259C))) >= 0x8000) {
        (*(s32 *)((s8 *)(&D_80132ED0) + (0x259C))) = 0x6B7;
    }
    return temp_v1;
}
