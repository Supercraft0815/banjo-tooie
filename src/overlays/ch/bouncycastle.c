#include "common.h"

OSThread *chbouncycastle_entrypoint_0(void)
{
    extern u8 D_80800930_chbouncycastle[];

    return (OSThread *) D_80800930_chbouncycastle;
}

OSThread *chbouncycastle_entrypoint_1(void)
{
    extern u8 D_80800978_chbouncycastle[];

    return (OSThread *) D_80800978_chbouncycastle;
}

OSThread *chbouncycastle_entrypoint_2(void)
{
    extern u8 D_808009C0_chbouncycastle[];

    return (OSThread *) D_808009C0_chbouncycastle;
}

OSThread *chbouncycastle_entrypoint_3(void)
{
    extern u8 D_80800A08_chbouncycastle[];

    return (OSThread *) D_80800A08_chbouncycastle;
}

/* extern */

void chbouncycastle_entrypoint_4(Actor *arg0) {
    struct anctrl_s;
    void func_8008B304(s32);
    s32 func_8008B4D4(struct anctrl_s *);
    void func_800DF41C(s32);
    void func_800DF818(s32);
    void func_800DF830(s32);
    void *func_80100094(Actor *, u32);
    s32 func_801039E4(s32);
    s32 func_80103CDC(u8 *, u8 *);
    void func_80103D48(void **);
    void func_80103D70(void **);
    struct anctrl_s *func_80104248(void *);
    struct RenderFlags {
        u8 pad0[0x70];
        u32 pad70_25 : 7;
        u32 flag24 : 1;
        u32 pad70_22 : 2;
        u32 flag21 : 1;
        u32 pad70_0 : 21;
    };
    s32 pad;
    Unk80132ED0 *sp28;
    s32 *sp24;
    struct anctrl_s *sp20;

    sp28 = (Unk80132ED0 *)func_801039E4((s32)arg0->unk0);
    sp24 = func_80100094(arg0, 0);
    func_80103D48((void **)arg0);
    *sp24 = sp28->unk28;
    if (*(s16 *)&arg0->pad8C != 0 && (arg0->unk70_10 == 2 || arg0->unk79_4 != 0)) {
        sp20 = func_80104248(arg0);
        func_8008B304((s32)sp20);
        func_800DF41C(func_8008B4D4(sp20));
    } else {
        sp28->unk28 = 0;
    }
    if (arg0->unk79_4 != 1 && (((struct RenderFlags *)arg0)->flag24 || ((struct RenderFlags *)arg0)->flag21)) {
        func_800DF818(func_80103CDC((u8 *)arg0, (u8 *)sp28));
    }
    func_800DF830(1);
    func_80103D70((void **)arg0);
    arg0->unk7C_12 = 1;
}

/* extern */

void func_80800148_chbouncycastle(void **arg0) {
    s32 _glidmake_entrypoint_4(s32);
    s32 _glidmake_entrypoint_5(u16, s32);
    s32 func_8010647C(void **, s32);
    s32 func_801065A4();
    s32 temp_v0;

    temp_v0 = func_801065A4();
    if (temp_v0 != 0) {
        _glidmake_entrypoint_4(temp_v0);
    }
    func_8010647C(arg0, _glidmake_entrypoint_5((*(u16 *)((s8 *)(*arg0) + (0x14))), 0));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bouncycastle/func_80800198_chbouncycastle.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bouncycastle/func_80800254_chbouncycastle.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/bouncycastle/func_80800308_chbouncycastle.s")

/* extern */

void func_8080045C_chbouncycastle(Actor *arg0) {
    s32 _subaddiemarker_entrypoint_0(Actor *, s32, f32 *, s32);
    s32 func_800DA298(s32);
    s32 func_800EA05C();
    void *func_80100094(Actor *, u32);
    void func_80101EE4(Actor *, f32);
    void func_80102424(Actor *, s32);
    void func_80108A30(s32, void *, f32, s32);
    void func_8010A624(Actor *);
    struct {
        s32 unk0;
        f32 position[3];
        s32 unk10;
        f32 unk14;
    } *sp24;

    sp24 = func_80100094(arg0, 0);
    _subaddiemarker_entrypoint_0(arg0, 0x154, sp24->position, 1);
    if (func_800DA298(0xB2) == 0) {
        func_80102424(arg0, 1);
        func_80101EE4(arg0, 0.21590909f);
    } else {
        func_80108A30(0x210, sp24->position, sp24->unk14, sp24->unk10);
        func_80102424(arg0, 3);
    }
    arg0->unk79_4 = 3;
    if (func_800EA05C() != 0xE1) {
        func_8010A624(arg0);
    }
}

void func_8080051C_chbouncycastle(Actor *arg0) {
    u8 _subaddieaudioquick_entrypoint_1(Actor *, f32 *);
    s32 func_800C3868(s32, f32, f32, f32, f32);
    u8 func_800C4350(s32, f32[3], s32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    s32 func_80101E14(Actor *, f32);
    extern s32 D_80800A50_chbouncycastle;
    extern f32 D_80800A5C_chbouncycastle[4];
    f32 temp_f20;
    f32 *var_s2;
    f32 *temp_s0;
    u8 temp_v0;
    s32 var_s1;
    s32 count = sizeof(D_80800A5C_chbouncycastle) / sizeof(f32);
    s32 *audio_params = &D_80800A50_chbouncycastle;

    for (var_s1 = 0, var_s2 = D_80800A5C_chbouncycastle; var_s1 < count; var_s1++, var_s2++) {
        if (func_80101E14(arg0, *var_s2) != 0) {
            temp_s0 = arg0->position;
            temp_f20 = func_800F10B4((f32) var_s1, 0.0f, (f32) (count - 1), 0.3f, 0.5f);
            temp_v0 = _subaddieaudioquick_entrypoint_1(arg0, temp_s0);
            func_800C3868(temp_v0 & 0xFF, 0.15f, 0.25f, temp_f20, temp_f20 + 0.12f);
            func_800C4350(temp_v0 & 0xFF, temp_s0, audio_params);
        }
    }
}

/* extern */

void func_80800670_chbouncycastle(u8 *arg0) {
    s32 func_800CBB80(s32, s32);
    s32 func_800CBDD4(s32, s32, s32);
    s32 func_800DA298(s32);
    s32 temp_v0;

    temp_v0 = func_800CBDD4(arg0 + 4, 0x64, 1);
    (*(s32 *)((s8 *)(arg0) + (0x28))) = temp_v0;
    if (temp_v0 != -1) {
        func_800CBB80((*(s32 *)((s8 *)(arg0) + (0x28))), func_800DA298(0xB2));
    }
}

void func_808006C4_chbouncycastle(Actor *arg0) {
    s32 func_800D1000(s32, s32, s32 *, s32, s32);
    s32 func_800D9078(f32 *);
    void func_80101FDC(Actor *, u32);

    switch (arg0->unk70_10) {
        case 2:
            if (func_800D9078(&arg0->unk58) != 0) {
                func_800D1000(0x19, 1, NULL, 1, 0);
                func_80101FDC(arg0, 1);
            }
            break;
        case 3:
            if (func_800D9078(&arg0->unk58) != 0) {
                func_800D1000(0x15, 1, NULL, 1, 0);
                func_80101FDC(arg0, 1);
            }
            break;
    }
}

s32 func_80800774_chbouncycastle(Actor *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    s32 _glcutDll_entrypoint_19(u32);
    void func_80101FDC(Actor *, u32);

    if (arg1 == 0x49) {
        if (_glcutDll_entrypoint_19(0x22) != 0) {
            _capod_entrypoint_13(arg0->unk0, NULL, 0xF, 0x2910);
            func_80101FDC(arg0, 2);
            arg0->unk58 = 0.15f;
            return 1;
        }
        if (_glcutDll_entrypoint_19(0x21) != 0) {
            _capod_entrypoint_13(arg0->unk0, NULL, 0xC, 0x2910);
            func_80101FDC(arg0, 3);
            arg0->unk58 = 0.15f;
            return 1;
        }
    }
    return 0;
}

void func_80800828_chbouncycastle(s32 arg0) 
{
}
/* extern */

s32 func_80800830_chbouncycastle(Actor *arg0, s32 arg1, s32 arg2) {
    void func_800BF744(s32, s32);
    void func_8010A624(Actor *);
    s32 func_8010D278();
    s32 var_v1;
    s32 var_a0;

    if (arg1 == 0x95) {
        var_v1 = arg0->unk6C_9 == 0x3C7 ? 1 : 0xB;
        if (arg0->unk6C_9 == 0x3C7) {
            var_a0 = 2;
        } else {
            var_a0 = 1;
        }
        if (func_8010D278() == var_v1) {
            func_800BF744(var_a0, 0);
            func_8010A624(arg0);
            arg0->unk64_16 = 0;
            return 1;
        }
        func_800BF744(var_a0, 1);
        return 1;
    }
    return 0;
}
