#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EB3D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EB51C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EB5E0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EB70C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EB750.s")

void func_800EB7A8(void) {
    s32 vector_defrag(s32);
    extern s32 D_80132E80;
    extern s16 D_80132E9C;
    s32 *var_s0;
    s32 temp_a0;
    var_s0 = &D_80132E80; do { temp_a0 = *var_s0;
        if (temp_a0 != 0) {
            *var_s0 = vector_defrag(temp_a0);
        }
        var_s0++;
    } while (var_s0 != (s32 *)(&D_80132E9C));
}

void func_800EB800(void)
{
  s32 vector_clear(s32);
  extern s32 D_80132E80;
  s32 *var_s0;
  s32 temp_a0;
  extern s16 D_80132E9C;
 do { var_s0 = &D_80132E80; do { temp_a0 = *var_s0; if (temp_a0 != 0) { vector_clear(temp_a0); } var_s0++; } while (var_s0 != ((s32 *) (&D_80132E9C))); } while (0);
}

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

void func_800EBB94(void) {
    extern s32 D_80132ED0;
    struct {
        u16 records[200][24];
        s8 flags[25];
    } *state = (void *)&D_80132ED0;
    s32 i;

    for (i = 0; i < 25; i++) {
        state->flags[i] = 0;
    }
    for (i = 0; i < 200; i++) {
        state->records[i][9] &= 1;
    }
}

void func_800EBC04(void) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EBC0C.s")

void func_800EBCD0(u8 **arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 func_800E9AC0(s32, s32);
    s32 func_800EBC0C(s32, s32, void *, s32);
    volatile struct {
        u16 pad[3];
        u16 saved;
        u32 tail[2];
    } local;
    u8 *temp_a1;
    s32 result;

    temp_a1 = *arg0;
    local.saved = (*(u16 *)((s8 *)(temp_a1) + (0xA)));
    result = func_800E9AC0(arg2, (s32) temp_a1);
    func_800EBC0C(arg3, arg1, arg0, result);
    (*(u16 *)((s8 *)(*arg0) + (0xA))) = local.saved;
}

/* extern */

void func_800EBD2C(u8 *arg0, s32 arg1, s32 arg2) {
    s32 func_800BDB9C(s32);
    void func_800EBCD0(u8 **, s32, s32, s32);
    s32 pad;
    s32 sp18;

    sp18 = func_800BDB9C(*(s16 *)((s8 *) arg0 + 0x1C));
    pad = 0;
    func_800EBCD0(arg0, arg1, sp18, func_800BDB9C(arg2));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EC4CC0/func_800EBD78.s")

void func_800EBE24(void *arg0) {
    extern s32 D_80123554;
    extern s32 D_80132ED0;
    u8 *base;
    s32 temp_v0;
    u8 *temp_v1;

    base = (u8 *) &D_80132ED0;
    temp_v0 = (s32) arg0 - (s32) base;
    *(u16 *) ((s8 *) arg0 + 0x12) &= 1;
    temp_v1 = base;
    temp_v1 += temp_v0 / 48 >> 3;
    *(temp_v1 + 0x2580) = *(temp_v1 + 0x2580) & *((s32 *) &D_80123554 + (temp_v0 / 48 & 7));
}

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
    s32 func_800BDB9C(s32);
    s32 func_800E9AC0(s32, s32);
    void func_800EBE24(void *);
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
