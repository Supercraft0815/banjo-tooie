#include "common.h"

OSThread *chstonepillar_entrypoint_0(void)
{
    extern u8 D_808013F0_chstonepillar[];

    return (OSThread *) D_808013F0_chstonepillar;
}

OSThread *chstonepillar_entrypoint_1(void)
{
    extern u8 D_80801438_chstonepillar[];

    return (OSThread *) D_80801438_chstonepillar;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stonepillar/func_80800018_chstonepillar.s")

void func_808001FC_chstonepillar(s32 arg0)
{
    _subaddiefade_entrypoint_14();
    func_80800EE0_chstonepillar(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stonepillar/func_80800224_chstonepillar.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stonepillar/func_8080031C_chstonepillar.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stonepillar/func_80800390_chstonepillar.s")

void func_808003F4_chstonepillar(Actor *arg0, s32 arg1) {
    void func_800DF744(s32, s32);
    void *func_80100094(Actor *, u32);
    s32 func_801015D0(Actor *);
    void func_80101808(Actor *, s32 (*)(Actor *));
    s32 var_s0;

    for (var_s0 = 0; var_s0 != 5; var_s0++) {
        func_800DF744(var_s0 + 1, 0);
    }
    func_800DF744(((u8 *)func_80100094(arg0, 0))[0x2E] + 1, 1);
    func_80101808(arg0, func_801015D0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stonepillar/func_80800474_chstonepillar.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stonepillar/func_80800520_chstonepillar.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stonepillar/func_808005B4_chstonepillar.s")

void func_808006AC_chstonepillar(Unk80132ED0 **arg0) {
    void _capod_entrypoint_13(Unk80132ED0*, Unk80132ED0*, s16, u32);
    s32 func_800DA298(s32);
    s32 func_800DA564(s32, s32);
    extern s16 D_80801480_chstonepillar[];
    if (func_800DA298(0x9D5) != 0) {
        _capod_entrypoint_13(*arg0, NULL, D_80801480_chstonepillar[func_800DA564(0x9CD, 3)], 0x810U);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stonepillar/func_80800704_chstonepillar.s")

void func_808007C8_chstonepillar(Actor *arg0) {
    Actor *_subaddiefind_entrypoint_2(s32, s32 *);
    Actor *_subaddiefind_entrypoint_3(s32, s32 *);
    void *func_80100094(Actor *, u32);
    void func_800EE7F8(f32 *, f32 *);
    Actor *actor;
    f32 *data;
    f32 *other;
    s32 iterator;

    data = func_80100094(arg0, 0);
    actor = _subaddiefind_entrypoint_2(arg0->unk6C_9, &iterator);
    if (actor != NULL) {
        do {
            if (actor != arg0) {
                other = func_80100094(actor, 0);
                if (((s16 *)other)[0x16] == ((s16 *)data)[0x16] + 1) {
                    func_800EE7F8(data + 3, other);
                }
            }
            actor = _subaddiefind_entrypoint_3(arg0->unk6C_9, &iterator);
        } while (actor != NULL);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stonepillar/func_80800870_chstonepillar.s")

void func_80800ADC_chstonepillar(Actor *arg0, s32 arg1) {
    void _glcutDll_entrypoint_17(void);
    s32 _glcutDll_entrypoint_19(u32);
    s32 func_800DA524(s32);
    s32 func_800DA7A8(s32, s32, s32);
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    s16 *sp1C;

    sp1C = func_80100094(arg0, 0);
    func_800DA524(0x9D5);
    if (arg1 != 0) {
        func_800DA7A8(0x9CD, sp1C[0x16] + 1, 3);
    }
    func_80101FDC(arg0, 1);
    if (_glcutDll_entrypoint_19(0xB) != 0) {
        _glcutDll_entrypoint_17();
    }
}

s32 func_80800B58_chstonepillar(Actor *arg0) {
    s32 *_fxgenlist_entrypoint_0(void);
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800D1218(u32, u32, f32 *);
    void func_800D1254(u32, u32, f32 *);
    void *func_80100094(Actor *, u32);
    void func_80800BDC_chstonepillar(f32 *);
    f32 position[3];
    f32 *saved;

    saved = func_80100094(arg0, 0);
    func_800D1218(8, 1, position);
    func_800BBCB8(position, position, 1.0f, 0xE, _fxgenlist_entrypoint_0());
    position[1] += 40.0f;
    func_80800BDC_chstonepillar(position);
    func_800D1254(8, 1, saved);
    return 0;
}

void func_80800BDC_chstonepillar(f32 *arg0) {
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    extern s32 D_80801498_chstonepillar;
    func_800BBCB8(arg0, 0, 1.0f, 1, &D_80801498_chstonepillar);
}

void func_80800C10_chstonepillar(f32 *arg0) {
    s32 func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    extern s32 D_808014B8_chstonepillar;
    func_800BBCB8(arg0, arg0, 1.0f, 3, &D_808014B8_chstonepillar);
}

void func_80800C44_chstonepillar(Actor *arg0) {
    f32 func_800136E4(f32);
    s32 func_800D0B68(u32, u32);
    void func_800EE7F8(f32 *, f32 *);
    void *func_80100094(Actor *, u32);
    u8 *data;

    data = func_80100094(arg0, 0);
    arg0->rotation[1] = func_800136E4((f32)(3 - *(s16 *)(data + 0x2C)) * 72.0f);
    if (func_800D0B68(8, 1) != 0) {
        *(s16 *)(data + 0x2C) = -1;
    }
    func_800EE7F8(arg0->position, (f32 *)arg0->actorData);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stonepillar/func_80800CC8_chstonepillar.s")

/* extern */

void func_80800DA4_chstonepillar(s32 arg0) {
    s32 func_800DA298(s32);
    s32 func_800DA544(s32);
    if (func_800DA298(0x9D8) == 0) {
        func_800DA544(0x9D8);
    }
}

/* extern */

int func_80800DD8_chstonepillar(Actor *arg0) {
    s32 func_800DA298(s32);
    void* func_80100094(Actor*, u32);
    s32 func_800DA564(s32, s32);
    u8 *sp1C;
    int temp_v1;
    int value;

    sp1C = func_80100094(arg0, 0U);
    value = func_800DA564(0x9CD, 3);
    temp_v1 = *(s16 *)(sp1C + 0x2C);
    return value == temp_v1 &&
        func_800DA298(temp_v1 + 0x65C) == 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stonepillar/func_80800E30_chstonepillar.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stonepillar/func_80800EE0_chstonepillar.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stonepillar/func_80800FE0_chstonepillar.s")

/* extern */

void func_808010CC_chstonepillar(s32 arg0) {
    s32 _glcutDll_entrypoint_6(s32, s32);
    s32 func_800DA298(s32);
    s32 func_800EA05C();
    s32 func_800F54E4();
    s32 func_800F6CC8(s32);
    if ((func_800DA298(0x9D9) == 0) && (func_800EA05C() != 0xB9) && (func_800F6CC8(func_800F54E4()) == 0)) {
        _glcutDll_entrypoint_6(0xB9, 0xB);
    }
}

/* extern */

s32 func_8080112C_chstonepillar(Actor *arg0) {
    void* func_80100094(Actor*, u32);
    s32 func_800DA564(s32, s32);
    u8 *sp1C;

    sp1C = func_80100094(arg0, 0U);
    if (func_800DA564(0x9CD, 3) == (*(s16 *)((s8 *)(sp1C) + (0x2C)))) {
        return 1;
    }
    return 0;
}

/* extern */

void func_80801174_chstonepillar(Actor *arg0) {
    s32 func_800DA524(s32);
    s32 func_800DA7A8(s32, s32, s32);
    void func_80101FDC(Actor *, u32);
    func_800DA7A8(0x9CD, 0, 3);
    func_800DA7A8(0x9CD, 0, 3);
    func_800DA524(0x9D6);
    func_800DA524(0x9D5);
    func_80101FDC(arg0, 1);
}

void func_808011CC_chstonepillar(Actor *arg0, u32 arg1, f32 arg2, f32 arg3) {
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    void func_80018820(s32, f32, f32);
    f32 *data;

    if (arg1 != arg0->unk70_10) {
        func_80101FDC(arg0, arg1);
        data = func_80100094(arg0, 0);
        data[9] = arg2;
        arg0->unk58 = 0.3f;
        func_80018820(0, 3.0f, arg3);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/stonepillar/func_80801238_chstonepillar.s")

void func_80801374_chstonepillar(Actor *arg0, s32 arg1)
{
  s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
  extern u32 D_808014F0_chstonepillar;
  u32 temp_a2;
  temp_a2 = arg1 == ((((u16) (*((u16 *) (((s8 *) arg0) + 0x72)))) & 0xFFFFFFFF) >> 0xA);
  if ((temp_a2 != 0) || ((temp_a2 == 0) && (arg0->unk5F != 0)))
  {
    _subaddieaudioloop_entrypoint_4(arg0, NULL, temp_a2, &D_808014F0_chstonepillar);
  }
}
