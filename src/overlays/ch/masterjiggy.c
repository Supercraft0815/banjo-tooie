#include "common.h"

OSThread *chmasterjiggy_entrypoint_0(void)
{
    extern u8 D_8080164C_chmasterjiggy[];

    return (OSThread *) D_8080164C_chmasterjiggy;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/masterjiggy/func_8080000C_chmasterjiggy.s")

void func_808001A8_chmasterjiggy(s32 arg0) 
{
}
/* extern */

void func_808001B0_chmasterjiggy(s32 arg0) {
    s32 _sujiggy_entrypoint_8();
    _sujiggy_entrypoint_8();
}

s32 func_808001D0_chmasterjiggy(Unk80132ED0 **arg0, s32 arg1) {
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    extern s16 D_80801620_chmasterjiggy[];
    s16 *entry = (s16 *)((s8 *)D_80801620_chmasterjiggy + arg1 * 4);
    return _subaddiedialog_entrypoint_11(*arg0, entry[0], entry[1], (f32 *)((s8 *)arg0 + 4), 0x97);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/masterjiggy/func_80800220_chmasterjiggy.s")

/* extern */

int func_80800374_chmasterjiggy(s32 arg0) {
    s32 func_8008FD48();
    void func_8008FE68(f32 *);
    f32 sp1C[3];

    func_8008FE68(sp1C);
    return sp1C[0] >= 1576.0f && func_8008FD48() == 1;
}

int func_808003D4_chmasterjiggy(s32 arg0) {
    s32 func_80016B30(s32, s32);
    s32 func_80090080();
    return func_80090080() && (func_80016B30(0, 1) == 1);
}

/* extern */

void func_80800414_chmasterjiggy(s32 arg0) {
    s32 func_800DA298(s32);
    s32 func_800DA544(s32);
    s32 func_808001D0_chmasterjiggy(Unk80132ED0 **, s32);
    s32 func_80800220_chmasterjiggy(s32, s32);
    int func_80800374_chmasterjiggy();
    int func_808003D4_chmasterjiggy(s32);
    if (func_80800374_chmasterjiggy() != 0) {
        if ((func_800DA298(0x533) == 0) && (func_808001D0_chmasterjiggy(arg0, 3) != 0)) {
            func_800DA544(0x533);
        }
        if (func_808003D4_chmasterjiggy(arg0) != 0) {
            func_80800220_chmasterjiggy(arg0, 3);
        }
    }
}

/* extern */

void func_8080047C_chmasterjiggy(s32 arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 _sujiggy_entrypoint_0();
    s32 _sujiggy_entrypoint_2(s32);
    s32 func_800C0638();
    s32 func_800D035C(s32);
    s32 func_800D2498(s32, s32, s32);
    s32 func_800DA298(s32);
    if ((func_800C0638() == 0) && (func_800DA298(0xD4E) == 0) && (_glcutDll_entrypoint_20() == 0)) {
        func_800D2498(0x10E, func_800D035C(1), 0);
        func_800D2498(0x106, _sujiggy_entrypoint_2(_sujiggy_entrypoint_0()), 0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/masterjiggy/func_808004FC_chmasterjiggy.s")

/* extern */

void func_80800704_chmasterjiggy(s32 *arg0, s32 arg1, s32 arg2) {
    s32 _capod_entrypoint_13(s32, s32, s32, s32);
    s32 _capod_entrypoint_14();
    _capod_entrypoint_14();
    _capod_entrypoint_13(*arg0, 0, arg2, 0x2030);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/masterjiggy/func_80800744_chmasterjiggy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/masterjiggy/func_808007F0_chmasterjiggy.s")

OSThread *chmasterjiggy_entrypoint_1(void)
{
    extern u8 D_808016F8_chmasterjiggy[];

    return (OSThread *) D_808016F8_chmasterjiggy;
}

void func_8080095C_chmasterjiggy(void *arg0) {
    (*(f32 *)((s8 *)(arg0) + (0x38))) = 1.0f;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/masterjiggy/func_8080096C_chmasterjiggy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/masterjiggy/func_80800A40_chmasterjiggy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/masterjiggy/func_80800C08_chmasterjiggy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/masterjiggy/func_80800DDC_chmasterjiggy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/masterjiggy/func_80800E58_chmasterjiggy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/masterjiggy/func_80801030_chmasterjiggy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/masterjiggy/func_808010E4_chmasterjiggy.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/masterjiggy/chmasterjiggy_entrypoint_2.s")

void func_80801448_chmasterjiggy(s32 *arg0) {
    s32 _glid_entrypoint_0(s32, s32, s32 *, s32);
    s32 func_800BEA88(s32);
    extern s32 _chmasterjiggy_entrypoint_2;
    _glid_entrypoint_0(func_800BEA88(0), 1, &_chmasterjiggy_entrypoint_2, *arg0);
}

/* extern */

void func_80801488_chmasterjiggy(Actor *arg0) {
    typedef struct {
        f32 amount;
        s32 unused[5];
        s32 handle;
    } MasterJiggyData;
    void func_800E13F0(s32, f32);
    s32 func_800E15CC(s32, f32, f32);
    s32 func_800E1720(s32);
    f32 var_f0;
    s32 var_v1;

    var_f0 = ((MasterJiggyData *)arg0->actorData)->amount;
    if (var_f0 > 0.0f) {
        var_v1 = ((MasterJiggyData *)arg0->actorData)->handle;
        if (var_v1 == 0) {
            var_v1 = func_800E15CC(0, 0.0f, 1.0f) + 1;
            ((MasterJiggyData *)arg0->actorData)->handle = var_v1;
            var_f0 = ((MasterJiggyData *)arg0->actorData)->amount;
        }
        func_800E13F0(var_v1 - 1, var_f0 * 10.0f);
        return;
    }
    var_v1 = ((MasterJiggyData *)arg0->actorData)->handle;
    if (var_v1 != 0) {
        func_800E1720(var_v1 - 1);
        ((MasterJiggyData *)arg0->actorData)->handle = 0;
    }
}
