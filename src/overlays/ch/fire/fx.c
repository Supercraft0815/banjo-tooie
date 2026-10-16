#include "common.h"

OSThread *chfirefx_entrypoint_0(void)
{
    extern u8 D_80801200_chfirefx[];

    return (OSThread *) D_80801200_chfirefx;
}

OSThread *chfirefx_entrypoint_1(void)
{
    extern u8 D_80801248_chfirefx[];

    return (OSThread *) D_80801248_chfirefx;
}

/* extern */

typedef union {
    Actor actor;
    struct {
        u8 pad0[0x74];
        u32 pad74_7 : 25;
        u32 unk74_6 : 1;
        u32 pad74_0 : 6;
    } flags;
} ChFireFxActor;

void func_80800018_chfirefx(ChFireFxActor *arg0) {
    void chfirefx_entrypoint_2(Actor *, f32, f32, s32, s32);
    s32 var_v0;

    var_v0 = 0xD;
    if (arg0->flags.unk74_6) {
        var_v0 = 0x2D;
    }
    arg0->flags.unk74_6 = 0;
    chfirefx_entrypoint_2(&arg0->actor, arg0->actor.scale, (f32)arg0->actor.unk74_7, (s32)arg0->actor.rotation[1], var_v0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fire/fx/chfirefx_entrypoint_2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fire/fx/chfirefx_entrypoint_3.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fire/fx/chfirefx_entrypoint_4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fire/fx/chfirefx_entrypoint_5.s")

void chfirefx_entrypoint_6(Actor *arg0, s16 arg1, s16 arg2) {
    void* func_80100094(Actor*, u32);
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    (*(s16 *)((s8 *)(temp_v0) + (0x14))) = arg1;
    (*(s16 *)((s8 *)(temp_v0) + (0x16))) = arg2;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fire/fx/func_80800884_chfirefx.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fire/fx/func_80800AA8_chfirefx.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fire/fx/func_80800C18_chfirefx.s")

/* extern */

void func_80800E9C_chfirefx(Actor *arg0) {
    Actor *_subaddielink_entrypoint_4(u8 *);
    void *func_80100094(Actor *, u32);
    void func_80800AA8_chfirefx(Actor *);
    void func_8080116C_chfirefx(Actor *, Unk80132ED0 **);
    Actor *temp_v0;

    temp_v0 = _subaddielink_entrypoint_4((u8 *)func_80100094(arg0, 0U) + 0x18);
    if ((temp_v0 == NULL) || (arg0->unk70_10 != 2)) {
        func_80800AA8_chfirefx(arg0);
        return;
    }
    func_8080116C_chfirefx(temp_v0, &arg0->unk0);
}

void func_80800F00_chfirefx(Actor *arg0) {
    s32 _subaddielink_entrypoint_0(u8 *);
    void *func_80100094(Actor *, u32);
    s32 *sp2C;
    s32 var_s0;
    u8 *var_s1;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 0U);
    var_s0 = 0;
    var_s1 = temp_v0 + 8;
    sp2C = (s32 *)temp_v0;
    do {
        _subaddielink_entrypoint_0(var_s1);
        var_s0 += 8;
        var_s1 += 8;
    } while (var_s0 != 0x80);
    sp2C[1] = 0;
    sp2C[0] = (s32)arg0->rotation[1];
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/fire/fx/func_80800F7C_chfirefx.s")

void func_8080116C_chfirefx(Actor *arg0, Unk80132ED0 **arg1)
{
  s32 _subaddielink_entrypoint_1(void *, Unk80132ED0 *);
  void *func_80100094(Actor *, u32);
  void func_80103110(Actor *, u32);
  s32 *temp_v0;
  temp_v0 = func_80100094(arg0, 0U);
  _subaddielink_entrypoint_1((((u8 *) temp_v0) + ((temp_v0[1]++) * 8)) + ((0, 8)), *arg1);
  func_80103110(arg0, 1U);
}
