#include "common.h"

void func_80105834(Actor *);
void *func_80107C2C(s32 *, s32, void *, s32, void *);
void func_80800000_chfactoryempspell(Actor *arg0);
s32 func_80800630_chfactoryempspell(Actor *arg0, s32 arg1, void *arg2);
void func_80800C7C_chfactoryempspell();
void func_80801FE0_chfactoryempspell(void *arg0);

u32 D_80802170_chfactoryempspell[] = {
    0x00130527, 0x001636B0, 0x000100C8, 0x17700000,
};

u32 D_80802180_chfactoryempspell[] = {
    0xC5A28000, 0xC4228000, 0x442F0000,
};

u32 D_8080218C_chfactoryempspell[] = {
    0x45A28000, 0x45098000, 0x45960000,
};

u32 D_80802198_chfactoryempspell[] = {
    0xC5B9F000, 0xC1A00000, 0x457A0000,
};

u32 D_808021A4_chfactoryempspell[] = {
    0x00000000, 0x42B40000, 0x00000000,
};

u32 D_808021B0_chfactoryempspell[] = {
    0x00000000, 0x43870000, 0x00000000,
};

u32 D_808021BC_chfactoryempspell[] = {
    0xC505C000, 0x44A8C000, 0x454B2000, 0x45584000,
    0x44A8C000, 0x454B2000,
};

u32 D_808021D4_chfactoryempspell[] = {
    0xC505C000, 0x43660000, 0x454B2000, 0x45584000,
    0x43660000, 0x454B2000,
};

u32 D_808021EC_chfactoryempspell[] = {
    0xC505C000, 0x44A8C000, 0x45947000, 0x45584000,
    0x44A8C000, 0x45947000,
};

u32 D_80802204_chfactoryempspell[] = {
    0xC505C000, 0x43660000, 0x45947000, 0x45584000,
    0x43660000, 0x45947000,
};

u32 D_8080221C_chfactoryempspell[] = {
    0x00000000, 0x00000000, 0x00000000,
};

u32 D_80802228_chfactoryempspell[] = {
    0x42B40000, 0x00000000, 0x00000000,
};

u32 D_80802234_chfactoryempspell[] = {
    0x43870000, 0x00000000, 0x00000000,
};

u32 D_80802240_chfactoryempspell[] = {
    0x001D09C9, 0x002B0200, 0x03000022, 0x02000280,
    0x06000800, 0x00161000, 0x00150000, 0x00330019,
    0x00000007, 0x002CFFEC, 0x00140014, 0x00140028,
    0x00140020, 0x60606080, 0x00000000,
};

u32 D_8080227C_chfactoryempspell[] = {
    0x001D09CD, 0x001BFC18, 0xFCE0002D, 0x015E02EE,
    0x00161000, 0x00270000, 0x00C80000, 0x01900022,
    0x0019001E, 0x00000000, 0x00150000, 0x0099000E,
    0x00000032, 0x002B0100, 0x0180002F, 0x00800080,
    0x00000033, 0x004C0000, 0x00660000,
};

u32 D_808022C8_chfactoryempspell[] = {
    0xC5160000, 0x44A8C000, 0x454E4000, 0x45610000,
    0x44A8C000, 0x454E4000,
};

u32 D_808022E0_chfactoryempspell[] = {
    0xC5160000, 0x43660000, 0x454E4000, 0x45610000,
    0x43660000, 0x454E4000,
};

u32 D_808022F8_chfactoryempspell[] = {
    0xC5160000, 0x44A8C000, 0x4592E000, 0x45610000,
    0x44A8C000, 0x4592E000,
};

u32 D_80802310_chfactoryempspell[] = {
    0xC5160000, 0x43660000, 0x4592E000, 0x45610000,
    0x43660000, 0x4592E000,
};

u32 D_80802328_chfactoryempspell[] = {
    0x001D09CD, 0x001BFC18, 0xFCE0002D, 0x015E02EE,
    0x00161000, 0x00270000, 0x00C80000, 0x01900022,
    0x0019001E, 0x00000000, 0x00150000, 0x0099000E,
    0x00000032, 0x002B0080, 0x00B3002F, 0x00800080,
    0x00000033, 0x004C0000, 0x00660000,
};

u32 D_80802374_chfactoryempspell[] = {
    0x0013052E, 0x000A00CC, 0x00167FFF, 0x00000000,
};

u32 D_80802384_chfactoryempspell[] = {
    0x00000000, 0x00000000, 0x458CA000,
};

u32 D_80802390_chfactoryempspell[] = {
    0x00000000, 0x00000000, 0x458FC000,
};

u32 D_8080239C_chfactoryempspell[] = {
    0x00000000, 0x00000000, 0x455AC000,
};

u32 D_808023A8_chfactoryempspell[] = {
    0x00000000, 0x00000000, 0x45548000,
};

u32 D_808023B4_chfactoryempspell[] = {
    0x00000000, 0x44548000, 0x457A0000,
};

u32 D_808023C0_chfactoryempspell[] = {
    0xC51C4000, 0x44A8C000, 0x454E4000,
};

u32 D_808023CC_chfactoryempspell[] = {
    0xC51C4000, 0x43660000, 0x454E4000,
};

u32 D_808023D8_chfactoryempspell[] = {
    0xC51C4000, 0x44A8C000, 0x4592E000,
};

u32 D_808023E4_chfactoryempspell[] = {
    0xC51C4000, 0x43660000, 0x4592E000,
};

u32 D_808023F0_chfactoryempspell[] = {
    0x000000C8, 0x000000C8, 0x000000FF,
};

u32 D_808023FC_chfactoryempspell[] = {
    0x0000003C, 0x0000003C, 0x0000003C,
};

u32 D_80802408_chfactoryempspell[] = {
    0x001304C0, 0x00020016, 0x59D80000,
};

u32 D_80802414_chfactoryempspell[] = {
    0x015803EE, 0x088A0001, 0x00000000, (u32)func_80800000_chfactoryempspell,
    (u32)func_80105834, (u32)func_80800C7C_chfactoryempspell, 0x1F400000, 0x00000000,
    0x00000000, 0x08020400, (u32)func_80801FE0_chfactoryempspell, 0x00000000,
    0x00000070, 0x00000000, (u32)func_80107C2C, 0x80000402,
    (u32)func_80800630_chfactoryempspell, 0x00000000, 0x00000000,
};

void func_80800000_chfactoryempspell(Actor *arg0) {
    s32 _capod_entrypoint_13(s32, s32, s32, s32);
    void _chglowbo_entrypoint_6(void);
    s32 _chmrtannoy_entrypoint_0(void);
    void _subaddieDll_entrypoint_4(Actor *, u32);
    u8 _subaddieaudioloop_entrypoint_3(u8);
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0 *, s32, s32, f32 *, s32);
    Actor *_subaddiefind_entrypoint_2(s32, s32 *);
    Actor *_subaddiefind_entrypoint_3(s32, s32 *);
    s32 _sumumbofx_entrypoint_1(void *, s32);
    void _sumumbofx_entrypoint_15(void *, f32);
    void _sumumbofx_entrypoint_16(void *, f32);
    void _sumumbofx_entrypoint_17(void *, f32);
    void _sumumbofx_entrypoint_18(void *, f32);
    void _sumumbofx_entrypoint_20(void *, f32);
    f32 _sumumbofx_entrypoint_26(void *);
    s32 _sumumbofx_entrypoint_27(void *);
    void _sumumbofx_entrypoint_5(void *, f32);
    s16 func_800CEA84(s32);
    s32 func_800CEAA8();
    s32 func_800DA298(s32);
    s32 func_800DA524(s32);
    s32 func_800DA544(s32);
    void *func_80100094(Actor *, u32);
    s32 func_80101180(s32, s32, s32);
    void func_80101FDC(Actor *, u32);
    void func_80800A08_chfactoryempspell(Actor *);
    void func_80801130_chfactoryempspell(Actor *, void *, f32);
    void func_808012C0_chfactoryempspell(f32, f32);
    void func_808016AC_chfactoryempspell(Actor *);
    void func_80801844_chfactoryempspell(Actor *);
    void func_80801AB4_chfactoryempspell(Actor *);
    void func_80801C00_chfactoryempspell(Actor *, f32);
    void func_80801E48_chfactoryempspell(Actor *);
    void func_80801E9C_chfactoryempspell(Actor *, f32);
    void func_80801F30_chfactoryempspell(Actor *);

    func_80800A08_chfactoryempspell(arg0);
    switch (arg0->unk70_10) {
    case 1:
        break;
    case 2: {
        void *fx;
        if (func_800DA298(0x9DE)) {
            func_80801F30_chfactoryempspell(arg0);
            fx = func_80100094(arg0, 0);
            _sumumbofx_entrypoint_15(fx, 3.0f);
            _capod_entrypoint_13(*(s32 *)arg0, 0, 10, 0x810);
            arg0->unk64_20 = 0;
            func_800DA544(0xA05);
            func_80101180(0x2B0, 0xBB, 0xB);
            func_80101FDC(arg0, 3);
            func_800DA544(0x57F);
        }
        break;
    }
    case 3: {
        void *fx = func_80100094(arg0, 0);
        func_80801130_chfactoryempspell(arg0, fx, 1.0f);
        func_80801C00_chfactoryempspell(arg0, 1.0f);
        if (_sumumbofx_entrypoint_27(fx)) {
            _sumumbofx_entrypoint_18(fx, 3.0f);
            func_80101FDC(arg0, 4);
        }
        break;
    }
    case 4: {
        void *fx = func_80100094(arg0, 0);
        func_80801130_chfactoryempspell(arg0, fx, 0.75f);
        _sumumbofx_entrypoint_5(fx, 1.5f);
        func_80801C00_chfactoryempspell(arg0, _sumumbofx_entrypoint_26(fx));
        if (_sumumbofx_entrypoint_27(fx)) {
            _sumumbofx_entrypoint_17(fx, 5.0f);
            func_80101FDC(arg0, 5);
        }
        break;
    }
    case 5: {
        s32 search;
        Actor *first = _subaddiefind_entrypoint_2(0x3BA, &search);
        Actor *second = _subaddiefind_entrypoint_3(0x3BA, &search);
        void *fx = func_80100094(arg0, 0);
        func_80801130_chfactoryempspell(arg0, fx, *(f32 *)((u8 *)first + 0x34));
        func_80801C00_chfactoryempspell(arg0, *(f32 *)((u8 *)first + 0x34));
        if (first->unk70_10 == 3) {
            func_80101FDC(first, 5);
            *(f32 *)((u8 *)first + 0x34) = 1.0f;
            func_80101FDC(second, 5);
            *(f32 *)((u8 *)second + 0x34) = 1.0f;
            func_80101FDC(arg0, 6);
            _sumumbofx_entrypoint_20(fx, 5.0f);
        }
        break;
    }
    case 6: {
        void *fx = func_80100094(arg0, 0);
        func_80801130_chfactoryempspell(arg0, fx, 1.0f);
        func_808012C0_chfactoryempspell(0.1f, 0.1f);
        func_80801E9C_chfactoryempspell(arg0, 1.0f);
        func_80801C00_chfactoryempspell(arg0, 1.0f);
        if (_sumumbofx_entrypoint_27(fx)) {
            arg0->unk64_19 = 1;
            func_80101FDC(arg0, 7);
            _sumumbofx_entrypoint_20(fx, 5.0f);
        }
        break;
    }
    case 7: {
        s32 search;
        Actor *first = _subaddiefind_entrypoint_2(0x3BA, &search);
        Actor *second = _subaddiefind_entrypoint_3(0x3BA, &search);
        void *fx = func_80100094(arg0, 0);
        f32 amount = 1.0f - _sumumbofx_entrypoint_26(fx);
        *(f32 *)((u8 *)first + 0x34) = amount;
        *(f32 *)((u8 *)second + 0x34) = amount;
        func_80801130_chfactoryempspell(arg0, fx, amount);
        func_808012C0_chfactoryempspell(0.2f, 0.2f);
        func_80801E9C_chfactoryempspell(arg0, amount);
        func_80801C00_chfactoryempspell(arg0, 1.0f);
        if (_sumumbofx_entrypoint_27(fx)) {
            _chmrtannoy_entrypoint_0();
            _subaddiedialog_entrypoint_11(*(Unk80132ED0 **)arg0, 0x1339, 4, (f32 *)((u8 *)arg0 + 4), 0);
            func_800DA544(0x9DF);
            _chglowbo_entrypoint_6();
            func_808016AC_chfactoryempspell(arg0);
            func_80101FDC(arg0, 8);
        }
        break;
    }
    case 8: {
        s32 search;
        Actor *first = _subaddiefind_entrypoint_2(0x3BA, &search);
        void *fx = func_80100094(arg0, 0);
        func_80801130_chfactoryempspell(arg0, fx, *(f32 *)((u8 *)first + 0x34));
        func_808012C0_chfactoryempspell(0.07f, 0.05f);
        func_80801844_chfactoryempspell(arg0);
        func_80801E9C_chfactoryempspell(arg0, *(f32 *)((u8 *)first + 0x34));
        if (func_800CEAA8(0)) {
            func_80101FDC(arg0, 9);
        }
        break;
    }
    case 9: {
        s32 search;
        Actor *first = _subaddiefind_entrypoint_2(0x3BA, &search);
        void *fx = func_80100094(arg0, 0);
        func_80801130_chfactoryempspell(arg0, fx, *(f32 *)((u8 *)first + 0x34));
        func_808012C0_chfactoryempspell(0.07f, 0.05f);
        func_80801844_chfactoryempspell(arg0);
        func_80801E9C_chfactoryempspell(arg0, *(f32 *)((u8 *)first + 0x34));
        if (!func_800DA298(0xA05) || func_800CEA84(0) < 2.0f) {
            *((u8 *)arg0 + 0x28) = _subaddieaudioloop_entrypoint_3(*((u8 *)arg0 + 0x28));
            _sumumbofx_entrypoint_16(fx, 2.0f);
            func_80101FDC(arg0, 10);
        }
        break;
    }
    case 10: {
        s32 search;
        Actor *first = _subaddiefind_entrypoint_2(0x3BA, &search);
        void *fx = func_80100094(arg0, 0);
        func_80801130_chfactoryempspell(arg0, fx, *(f32 *)((u8 *)first + 0x34));
        func_80801C00_chfactoryempspell(arg0, *(f32 *)((u8 *)first + 0x34));
        func_80801844_chfactoryempspell(arg0);
        if (_sumumbofx_entrypoint_27(fx)) {
            if (!func_800DA298(0x329)) {
                func_808012C0_chfactoryempspell(1.0f, 1.0f);
            }
            func_80801AB4_chfactoryempspell(arg0);
            func_80801E48_chfactoryempspell(arg0);
            arg0->unk64_19 = 0;
            func_80101FDC(arg0, 11);
        }
        break;
    }
    case 11: {
        s32 search;
        Actor *first = _subaddiefind_entrypoint_2(0x3BA, &search);
        Actor *second = _subaddiefind_entrypoint_3(0x3BA, &search);
        _sumumbofx_entrypoint_1(arg0, 0);
        func_80101FDC(first, 1);
        func_80101FDC(second, 1);
        *(f32 *)((u8 *)first + 0x58) = 1.2f;
        *(f32 *)((u8 *)second + 0x58) = 1.2f;
        _subaddieDll_entrypoint_4(arg0, 0);
        func_800DA524(0x9DE);
        func_80101FDC(arg0, 1);
        break;
    }
    }
}

s32 func_80800630_chfactoryempspell(Actor *arg0, s32 arg1, void *arg2) {
    typedef union {
        s32 word;
        s16 half;
        void *resource;
    } MessageValue;
    typedef struct {
        u8 pad0[8];
        s8 active;
        u8 pad9[11];
    } SpellEffect;
    typedef struct {
        SpellEffect effects[3];
        u8 pad3C[16];
        s32 current;
        s16 handles[15];
    } SpellData;
    void _subaddieDll_entrypoint_4(Actor *, u32);
    Actor *_subaddiefind_entrypoint_2(s32, s32 *);
    Actor *_subaddiefind_entrypoint_3(s32, s32 *);
    void _sumumbofx_entrypoint_17(void *, f32);
    void _sumumbofx_entrypoint_4(void *);
    void _sumumbofx_entrypoint_3(void *, f32);
    s32 func_800DA298(s32);
    void func_800DA3B8(s32, s32);
    void func_800DF660(s32, s32, s32, s32);
    void func_800DF720(s32);
    void func_800DF818(s32);
    void *func_80100094(Actor *, u32);
    void func_80101FDC(Actor *, u32);
    s32 func_80100A74(s16, s32);
    s32 func_80100AC4(s16);
    s16 func_80100D24(void *, u16, s32, s32, s32, s32);
    void func_80100E18(s16);
    void func_80801038_chfactoryempspell(Actor *);
    void func_80801F30_chfactoryempspell(Actor *);
    SpellData *data;
    s32 index;
    Actor *first;
    Actor *second;
    void *fx;
    s32 i;
    void *resource;
    s32 j;
    s32 k;
    s32 pad40;
    s16 handle;

    data = func_80100094(arg0, 1);
    switch (arg1) {
    case 0x2E:
        if (((MessageValue *)&arg2)->half == 0x1339) {
            func_80801038_chfactoryempspell(arg0);
        }
        return 1;
    case 0x30:
        if (((MessageValue *)&arg2)->half == 0x1339) {
            return 0x2D;
        }
    case 0xB:
        if (((MessageValue *)&arg2)->word == 0xA) {
            func_80801038_chfactoryempspell(arg0);
        }
        return 3;
    case 0x4B:
        _subaddieDll_entrypoint_4(arg0, 1);
        func_80101FDC(arg0, 2);
        return 1;
    case 0x95:
        func_800DA3B8(0x9DE, func_800DA298(0xA06) || func_800DA298(0xA05));
        if (func_800DA298(0xA05)) {
            first = _subaddiefind_entrypoint_2(0x3BA, &index);
            second = _subaddiefind_entrypoint_3(0x3BA, &index);
            func_80801F30_chfactoryempspell(arg0);
            func_80101FDC(arg0, 9);
            func_80101FDC(first, 5);
            func_80101FDC(second, 5);
            fx = func_80100094(arg0, 0);
            _sumumbofx_entrypoint_17(fx, 5.0f);
            _sumumbofx_entrypoint_4(fx);
            _sumumbofx_entrypoint_3(fx, 10.0f);
            *(f32 *)((u8 *)first + 0x34) = 0.0f;
            *(f32 *)((u8 *)second + 0x34) = 0.0f;
            *((s8 *)arg0 + 0x28) = 0;
            for (i = 0; i < 3; i++) {
                data->effects[i].active = 0;
            }
            arg0->unk5F = 0;
            arg0->unk64_19 = 1;
            *(f32 *)((u8 *)arg0 + 0x2C) = 2.0f;
        } else {
            arg0->unk64_19 = 0;
            *(f32 *)((u8 *)arg0 + 0x2C) = -2.0f;
            func_80101FDC(arg0, 1);
        }
        *(f32 *)((u8 *)arg0 + 0x24) = 0.0f;
        for (index = 0; index < 15; index++) {
            data->handles[index] = 0;
        }
        return 1;
    case 0x29:
        resource = ((MessageValue *)&arg2)->resource;
        for (j = 0; j < 15; j++) {
            data->handles[j] = func_80100D24(resource,
                arg0->unk0->unk14, 1, 1,
                arg0->unk0->unk16, 0);
        }
        return 1;
    case 0x2A:
        for (k = 0; k < 15; k++) {
            if (data->handles[k] != 0) {
                func_80100E18(data->handles[k]);
                data->handles[k] = 0;
            }
        }
        return 1;
    case 0x1F:
        handle = data->handles[data->current];
        func_800DF818(func_80100A74(handle, 0));
        func_800DF660(2, -1, 0, arg0->alpha);
        func_800DF720(func_80100AC4(handle));
        return 1;
    case 0xB9:
        *(f32 *)((u8 *)arg0 + 0x2C) = 0.0f;
        *(f32 *)((u8 *)arg0 + 0x30) = 1.0f;
        return 1;
    case 0xBA:
        *(f32 *)((u8 *)arg0 + 0x30) = 0;
        return 1;
    }
    return 0;
}

void func_80800A08_chfactoryempspell(Actor *arg0) {
    void _subaddieaudioloop_entrypoint_0(Actor *, f32);
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    f32 func_800138D0(f32);
    f32 func_800D8FF8(void);
    int func_800D90F8(f32 *, f32);
    int func_800D91EC(f32 *, f32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    f32 func_800F0D50(f32, f32, f32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_800F48BC(s32, f32 *);
    u32 func_800F54E4(void);
    void func_800F5A00(s32, f32 *);
    s32 func_800F6C5C(s32);
    f32 mlAbsF(f32);
    f32 position[3];
    f32 speed;
    f32 phase;

    if (((f32 *)arg0->actorData)[6] == 0.0f) {
        func_800F5A00(func_800F54E4(), position);
        if (arg0->unk64_19) {
            func_800D91EC(&((f32 *)arg0->actorData)[5], 2.0f);
        } else {
            func_800D90F8(&((f32 *)arg0->actorData)[5], -2.0f);
        }
        ((f32 *)arg0->actorData)[3] += func_800D8FF8() * ((f32 *)arg0->actorData)[5];
        phase = ((f32 *)arg0->actorData)[3];
        if (phase >= 2.6666667f) {
            ((f32 *)arg0->actorData)[3] = phase - 2.6666667f;
        } else if (phase < 0.0f) {
            ((f32 *)arg0->actorData)[3] = phase + 2.6666667f;
        }
        if (position[2] >= 3700.0f && position[2] <= 4300.0f && position[1] < 0.0f && func_800F6C5C(func_800F54E4())) {
            speed = ((f32 *)arg0->actorData)[5] * 297.49997f;
            func_800EFA4C(position, speed, func_800138D0(func_800F10B4(position[0], -5950.0f, 5950.0f, 0.0f, 1.5f) * 360.0f * 15.0f) * 1.5f * 5.0f, 0.0f);
            func_800F48BC(func_800F54E4(), position);
        }
        position[0] = func_800F0D50(position[0], -5950.0f, 5950.0f);
        position[1] = -20.0f;
        position[2] = 4000.0f;
        _subaddieaudioloop_entrypoint_4(arg0, position, 1, D_80802170_chfactoryempspell);
        _subaddieaudioloop_entrypoint_0(arg0, func_800F10B4(mlAbsF(((f32 *)arg0->actorData)[5]), 2.0f, 0.0f, 0.55f, 0.4f));
    }
}

void func_80800C7C_chfactoryempspell(Actor *arg0, void *arg1) {
    typedef struct {
        f32 x;
        f32 y;
        u8 pad8[8];
        u32 first : 7;
        u32 second : 7;
        u32 flag : 1;
        u32 rest : 17;
    } Effect;
    typedef struct {
        Effect effects[3];
        u8 pad3C[16];
        s32 current;
    } SpellData;
    s32 _sumumbofx_entrypoint_8(u8 *, s32);
    s32 _sumumbofx_entrypoint_9(u8 *, s32);
    f32 func_800138D0(f32);
    struct ImageStruct *func_800D674C(s32);
    s32 func_800DC128(s32, s32);
    void *func_800DE498(void *, f32 *, f32 *, f32, f32 *, s32);
    void func_800DF47C(s32, s32);
    void func_800DF744(s32, s32);
    void func_800DF830(s32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    int func_800EFED0(f32 *, f32 *, f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    u32 func_800F54E4(void);
    void func_800F5A00(s32, f32 *);
    void *func_80100094(Actor *, u32);
    void func_801017D0(Actor *);
    u8 *func_801039E4(Unk80132ED0 *);
    f32 camera[3];
    f32 min[3];
    f32 max[3];
    SpellData *data;
    u8 *fx;
    f32 pos[3];
    s32 model;
    s32 i;

    *(Vec3f *)min = *(Vec3f *)D_80802180_chfactoryempspell;
    *(Vec3f *)max = *(Vec3f *)D_8080218C_chfactoryempspell;
    func_800F5A00(func_800F54E4(), camera);
    if (func_800EFED0(min, max, camera)) {
        data = func_80100094(arg0, 1);
        fx = func_80100094(arg0, 0);
        *(Vec3f *)pos = *(Vec3f *)D_80802198_chfactoryempspell;
        model = (s32)func_801039E4(arg0->unk0);
        pos[0] += func_800F10B4(((f32 *)arg0->actorData)[3], 0.0f, 2.6666667f, 0.0f, 793.3333f);
        for (i = 0; i < 15; i++) {
            f32 phase;
            f32 rot[3];
            phase = func_800F10B4(pos[0], -5950.0f, 5950.0f, 0.0f, 1.5f);
            *(Vec3f *)rot = *(Vec3f *)D_808021A4_chfactoryempspell;
            pos[1] = func_800138D0(phase * 360.0f * 15.0f) * 1.5f + -20.0f;
            rot[0] = func_800138D0(phase * 360.0f * 15.0f);
            data->current = i;
            func_800DF830(1);
            func_800DF47C((s32)func_801017D0, (s32)arg0);
            func_800DE498(arg1, pos, rot, 1.0f, NULL, model);
            pos[0] += 793.3333f;
        }
        if (fx != NULL) {
            _sumumbofx_entrypoint_9(fx, (s32)arg1);
            _sumumbofx_entrypoint_8(fx, (s32)arg1);
        }
        if (arg0->unk70_10 == 9) {
            f32 effectRot[3];
            f32 effectPos[3];
            *(Vec3f *)effectRot = *(Vec3f *)D_808021B0_chfactoryempspell;
            model = (s32)func_800D674C(0x8D3);
            for (i = 0; i < 3; i++) {
                func_800EFA4C(effectPos, data->effects[i].x,
                    func_800F10B4(data->effects[i].first, data->effects[i].second, 0.0f, data->effects[i].y, 1600.0f), 4000.0f);
                if (data->effects[i].flag) {
                    effectRot[2] = 180.0f;
                } else {
                    effectRot[2] = 0.0f;
                }
                func_800DF744(1, func_800DC128(1, 4));
                func_800DF830(2);
                func_800DE498(arg1, effectPos, effectRot, 1.5f, NULL, model);
            }
        }
    }
}

void func_80801038_chfactoryempspell(Actor *arg0) {
    void func_800CE88C(s32, s32);
    void func_800CE8D8(s32, f32, s32);
    void func_800CE928(s32, s32, s32);
    extern s32 _chfactoryempspell_entrypoint_0;
    if (arg0->unk64_20) {
        func_800CE8D8(0, 45.0f, 0x2D);
        func_800CE928(0, (s32)&_chfactoryempspell_entrypoint_0, (s32)arg0->unk0);
        func_800CE88C(0, 1);
        return;
    }
    arg0->unk64_20 = 1;
}

/* extern */

void chfactoryempspell_entrypoint_0(s32 arg0, s32 arg1) {
    s32 _chmrtannoy_entrypoint_0();
    s32 func_800C0534(s32, s32, s32, s32, s32, s32, s32, s32);
    s32 func_800DA298(s32);
    s32 func_800DA524(s32);
    s32 func_800EA05C();
    if (func_800DA298(0x329) == 0) {
        _chmrtannoy_entrypoint_0();
        func_800C0534(0x133A, 4, 0, 0, 0, 0, 0, 0xA3);
    }
    if (func_800EA05C() != 0x10B) {
        func_800DA524(0x9DE);
    }
    func_800DA524(0xA05);
}

void func_80801130_chfactoryempspell(Actor *arg0, void *arg1, f32 arg2) {
    s32 _sumumbofx_entrypoint_14(void *);
    s32 _sumumbofx_entrypoint_6(void *, f32, f32, s32, s32, u8 *, f32 *, f32 *);
    void func_800E3980(f32 *);
    f32 position[3];
    s32 side;

    func_800E3980(position);
    if (position[0] < 0.0f) {
        side = 0;
    } else {
        side = 1;
    }
    _sumumbofx_entrypoint_6(arg1, 500.0f * arg2, 300.0f, 0, 0xA, ((u8 *)D_8080221C_chfactoryempspell), ((f32 (*)[3])D_808021BC_chfactoryempspell)[side], ((f32 *)D_80802228_chfactoryempspell));
    _sumumbofx_entrypoint_6(arg1, 500.0f * arg2, 300.0f, 0xA, 0x14, ((u8 *)D_8080221C_chfactoryempspell), ((f32 (*)[3])D_808021D4_chfactoryempspell)[side], ((f32 *)D_80802228_chfactoryempspell));
    _sumumbofx_entrypoint_6(arg1, 500.0f * arg2, 300.0f, 0x14, 0x1E, ((u8 *)D_8080221C_chfactoryempspell), ((f32 (*)[3])D_808021EC_chfactoryempspell)[side], ((f32 *)D_80802234_chfactoryempspell));
    _sumumbofx_entrypoint_6(arg1, 500.0f * arg2, 300.0f, 0x1E, 0x28, ((u8 *)D_8080221C_chfactoryempspell), ((f32 (*)[3])D_80802204_chfactoryempspell)[side], ((f32 *)D_80802234_chfactoryempspell));
    _sumumbofx_entrypoint_14(arg1);
}

void func_808012C0_chfactoryempspell(f32 arg0, f32 arg1) {
    void func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    f32 func_800DC0C0(void);
    void func_800E3980(f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    f32 position[3];
    f32 random;
    s32 side;

    func_800E3980(position);
    if (position[0] < 0.0f) {
        side = 0;
    } else {
        side = 1;
    }
    random = func_800DC0C0();
    if (random < arg0) {
        func_800BBCB8(((f32 (*)[3])D_808022C8_chfactoryempspell)[side], NULL, 1.0f, 1, &(*(s32 *)D_80802240_chfactoryempspell));
    }
    if (random < arg1) {
        func_800EFA4C(position, ((f32 (*)[3])D_808022C8_chfactoryempspell)[side][0] + 100.0f, ((f32 (*)[3])D_808022C8_chfactoryempspell)[side][1] - 30.0f, ((f32 (*)[3])D_808022C8_chfactoryempspell)[side][2] - 50.0f);
        func_800BBCB8(((f32 (*)[3])D_808022C8_chfactoryempspell)[side], position, 1.0f, 2, &(*(s32 *)D_8080227C_chfactoryempspell));
    }
    random = func_800DC0C0();
    if (random < arg0) {
        func_800BBCB8(((f32 (*)[3])D_808022E0_chfactoryempspell)[side], NULL, 1.0f, 1, &(*(s32 *)D_80802240_chfactoryempspell));
    }
    if (random < arg1) {
        func_800EFA4C(position, ((f32 (*)[3])D_808022E0_chfactoryempspell)[side][0] + 100.0f, ((f32 (*)[3])D_808022E0_chfactoryempspell)[side][1] - 30.0f, ((f32 (*)[3])D_808022E0_chfactoryempspell)[side][2] - 50.0f);
        func_800BBCB8(((f32 (*)[3])D_808022E0_chfactoryempspell)[side], position, 1.0f, 2, &(*(s32 *)D_8080227C_chfactoryempspell));
    }
    random = func_800DC0C0();
    if (random < arg0) {
        func_800BBCB8(((f32 (*)[3])D_808022F8_chfactoryempspell)[side], NULL, 1.0f, 1, &(*(s32 *)D_80802240_chfactoryempspell));
    }
    if (random < arg1) {
        func_800EFA4C(position, ((f32 (*)[3])D_808022F8_chfactoryempspell)[side][0] + 100.0f, ((f32 (*)[3])D_808022F8_chfactoryempspell)[side][1] - 30.0f, ((f32 (*)[3])D_808022F8_chfactoryempspell)[side][2] + 50.0f);
        func_800BBCB8(((f32 (*)[3])D_808022F8_chfactoryempspell)[side], position, 1.0f, 2, &(*(s32 *)D_8080227C_chfactoryempspell));
    }
    random = func_800DC0C0();
    if (random < arg0) {
        func_800BBCB8(((f32 (*)[3])D_80802310_chfactoryempspell)[side], NULL, 1.0f, 1, &(*(s32 *)D_80802240_chfactoryempspell));
    }
    if (random < arg1) {
        func_800EFA4C(position, ((f32 (*)[3])D_80802310_chfactoryempspell)[side][0] + 100.0f, ((f32 (*)[3])D_80802310_chfactoryempspell)[side][1] - 30.0f, ((f32 (*)[3])D_80802310_chfactoryempspell)[side][2] + 50.0f);
        func_800BBCB8(((f32 (*)[3])D_80802310_chfactoryempspell)[side], position, 1.0f, 2, &(*(s32 *)D_8080227C_chfactoryempspell));
    }
}

void func_808016AC_chfactoryempspell(Actor *arg0) {
    u8 _subaddieaudioloop_entrypoint_3(u8);
    s32 func_800C8A98(void);
    void func_800C8CB8(s32, f32 *);
    void func_800C8E54(s32, f32, f32);
    void func_800C8F64(s32, s32);
    void func_800C8FB0(s32, u32, u32, u32);
    s32 func_800DC128(s32, s32);
    f32 func_800DC178(f32, f32);
    void *func_80100094(Actor *, u32);
    struct {
        f32 x;
        f32 y;
        u8 audio;
        u8 pad9[3];
        s32 handle;
        u16 first : 7;
        u16 second : 7;
        u16 flag : 1;
        u16 last : 1;
        u8 pad12[2];
    } *entry;
    s32 pad;
    f32 position[3];
    s32 i;
    s32 random;
    void *data;

    data = func_80100094(arg0, 1);
    i = 0;
    entry = data;
    do {
        random = func_800DC128(0, 9);
        entry->second = random;
        entry->first = random;
        entry->audio = _subaddieaudioloop_entrypoint_3(entry->audio);
        entry->x = position[0] = func_800DC178(-2400.0f, 3600.0f);
        entry->y = position[1] = func_800DC178(200.0f, 1400.0f);
        entry->flag = func_800DC128(0, 2);
        entry->handle = func_800C8A98();
        func_800C8E54(entry->handle, 400.0f, 500.0f);
        func_800C8FB0(entry->handle, 200, 200, 255);
        func_800C8F64(entry->handle, 1);
        position[2] = 4000.0f;
        func_800C8CB8(entry->handle, position);
        i += 0x14;
        entry++;
    } while (i != 0x3C);
}

void func_80801844_chfactoryempspell(Actor *arg0) {
    u8 _subaddieaudioloop_entrypoint_3(u8);
    s8 _subaddieaudioloop_entrypoint_7(u8, f32 *, u8, s32 *, s32);
    void func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    void func_800C8CB8(s32, f32 *);
    s32 func_800DC128(s32, s32);
    f32 func_800DC178(f32, f32);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void *func_80100094(Actor *, u32);
    struct {
        f32 x;
        f32 y;
        u8 audio;
        u8 pad9[3];
        s32 handle;
        u16 first : 7;
        u16 second : 7;
        u16 flag : 1;
        u16 last : 1;
        u8 pad12[2];
    } *entry;
    s32 i;
    s32 random;
    void *data;

    data = func_80100094(arg0, 1);
    for (i = 0, entry = data; i != 0x3C; i += 0x14, entry++) {
        if (entry->first-- == 0) {
            random = func_800DC128(0, 9);
            entry->second = random;
            entry->first = random;
            entry->audio = _subaddieaudioloop_entrypoint_3(entry->audio);
            entry->x = ((f32 *)D_80802384_chfactoryempspell)[0] = ((f32 *)D_80802390_chfactoryempspell)[0] = ((f32 *)D_8080239C_chfactoryempspell)[0] = ((f32 *)D_808023A8_chfactoryempspell)[0] = func_800DC178(-2400.0f, 3600.0f);
            entry->y = ((f32 *)D_80802384_chfactoryempspell)[1] = ((f32 *)D_80802390_chfactoryempspell)[1] = ((f32 *)D_8080239C_chfactoryempspell)[1] = ((f32 *)D_808023A8_chfactoryempspell)[1] = func_800DC178(200.0f, 1400.0f);
            entry->flag = func_800DC128(0, 2);
            func_800BBCB8(((f32 *)D_80802384_chfactoryempspell), ((f32 *)D_80802390_chfactoryempspell), 1.0f, 2, &(*(s32 *)D_80802328_chfactoryempspell));
            func_800BBCB8(((f32 *)D_8080239C_chfactoryempspell), ((f32 *)D_808023A8_chfactoryempspell), 1.0f, 2, &(*(s32 *)D_80802328_chfactoryempspell));
            ((f32 *)D_80802384_chfactoryempspell)[2] = 4000.0f;
            func_800C8CB8(entry->handle, ((f32 *)D_80802384_chfactoryempspell));
        } else {
            func_800EFA4C(((f32 *)D_808023B4_chfactoryempspell), entry->x, entry->y, 4000.0f);
            func_800C8CB8(entry->handle, ((f32 *)D_808023B4_chfactoryempspell));
            entry->audio = _subaddieaudioloop_entrypoint_7(entry->audio, ((f32 *)D_808023B4_chfactoryempspell), 1, &(*(s32 *)D_80802374_chfactoryempspell), arg0->unk70_0);
        }
    }
}

void func_80801AB4_chfactoryempspell(Actor *arg0) {
    u8 _subaddieaudioloop_entrypoint_3(u8);
    void func_800C8B84(volatile s32);
    void *func_80100094(Actor *, u32);
    struct {
        u8 pad0[8];
        u8 audio;
        u8 pad9[3];
        s32 handle;
        u8 active : 7;
        u8 flag : 1;
        u8 pad11[3];
    } *entry;
    s32 i;
    u8 audio;
    void *data;

    data = func_80100094(arg0, 1);
    i = 0;
    entry = data;
    do {
        if (entry->handle != 0) {
            func_800C8B84(entry->handle);
        }
        audio = _subaddieaudioloop_entrypoint_3(entry->audio);
        i++;
        entry++;
        entry[-1].audio = audio;
        entry[-1].active = 0;
    } while (i != 3);
}

/* extern */

void func_80801B2C_chfactoryempspell(Actor *arg0) {
    s32 func_800C8A98(void);
    void func_800C8CB8(s32, f32[3]);
    void func_800C8E54(s32, f32, f32);
    void func_800C8F64(s32, s32);
    void func_800C8FB0(s32, u32, u32, u32);
    u32 func_800F54E4(void);
    void func_800F5A00(s32, f32 *);
    void *func_80100094(Actor *, u32);
    s32 var_s1;
    struct {
        u8 pad[0x3C];
        s32 handles[4];
    } *var_s0;
    f32 sp44[3];

    var_s0 = func_80100094(arg0, 1);
    var_s1 = 0;
    do {
        func_800F5A00(func_800F54E4(), sp44);
        var_s0->handles[var_s1] = func_800C8A98();
        func_800C8E54(var_s0->handles[var_s1], 300.0f, 400.0f);
        func_800C8FB0(var_s0->handles[var_s1], 0x50, 0xFF, 0xFF);
        func_800C8F64(var_s0->handles[var_s1], 1);
        func_800C8CB8(var_s0->handles[var_s1], sp44);
        var_s1++;
    } while (var_s1 != 4);
}

void func_80801C00_chfactoryempspell(Actor *arg0, f32 arg1) {
    void func_800C8CB8(s32, f32 *);
    void func_800C8D4C(s32, f32 *);
    void func_800C8E84(s32, u32 *);
    void func_800EFE50(f32 *, f32 *, f32 *, f32);
    f32 func_800F1214(f32, f32, f32);
    int func_800F3214(void *, void *, void *, f32);
    u32 func_800F54E4(void);
    void func_800F5A00(s32, f32 *);
    void *func_80100094(Actor *, u32);
    struct {
        u8 pad[0x3C];
        s32 handles[4];
    } *data;
    f32 sp68[3];
    s32 i;
    f32 sp58[3];
    f32 sp4C[3];
    u32 sp40[3];
    s32 j;
    f32 sp34[2];

    data = func_80100094(arg0, 1);
    switch (arg0->unk70_10) {
    case 3:
        func_800F5A00(func_800F54E4(), sp68);
        sp68[1] += 200.0f;
        for (i = 0; i < 4; i++) {
            func_800C8CB8(data->handles[i], sp68);
        }
        break;
    case 4:
        func_800F5A00(func_800F54E4(), sp58);
        func_800EFE50(sp4C, sp58, ((f32 *)D_808023C0_chfactoryempspell), arg1);
        func_800C8CB8(data->handles[0], sp4C);
        func_800EFE50(sp4C, sp58, ((f32 *)D_808023CC_chfactoryempspell), arg1);
        func_800C8CB8(data->handles[1], sp4C);
        func_800EFE50(sp4C, sp58, ((f32 *)D_808023D8_chfactoryempspell), arg1);
        func_800C8CB8(data->handles[2], sp4C);
        func_800EFE50(sp4C, sp58, ((f32 *)D_808023E4_chfactoryempspell), arg1);
        func_800C8CB8(data->handles[3], sp4C);
        break;
    case 5:
        func_800C8CB8(data->handles[0], ((f32 *)D_808023C0_chfactoryempspell));
        func_800C8CB8(data->handles[1], ((f32 *)D_808023CC_chfactoryempspell));
        func_800C8CB8(data->handles[2], ((f32 *)D_808023D8_chfactoryempspell));
        func_800C8CB8(data->handles[3], ((f32 *)D_808023E4_chfactoryempspell));
        break;
    case 10:
        func_800F3214(sp40, ((u32 *)D_808023F0_chfactoryempspell), ((u32 *)D_808023FC_chfactoryempspell), arg1);
        sp34[0] = func_800F1214(arg1, 300.0f, 0.0f);
        sp34[1] = func_800F1214(arg1, 400.0f, 0.0f);
        for (j = 0; j < 4; j++) {
            func_800C8D4C(data->handles[j], sp34);
            func_800C8E84(data->handles[j], sp40);
        }
        break;
    case 11:
        break;
    }
}

void func_80801E48_chfactoryempspell(Actor *arg0) {
    void func_800C8B84(volatile s32);
    void* func_80100094(Actor*, u32);
    s32 var_s0;
    u8 *var_s1;
    u8 *temp_v0;

    temp_v0 = func_80100094(arg0, 1U);
    var_s0 = 0;
    var_s1 = temp_v0;
    do {
        func_800C8B84((*(s32 *)((s8 *)(var_s1) + (0x3C))));
        var_s0 += 4;
        var_s1 += 4;
    } while (var_s0 != 0x10);
}

void func_80801E9C_chfactoryempspell(Actor *arg0, f32 arg1) {
    s8 _subaddieaudioloop_entrypoint_7(u8, f32 *, u8, s32 *, s32);
    void func_800C31DC(u8, f32);
    f32 func_800DC0C0(void);
    f32 func_800F1214(f32, f32, f32);
    typedef struct {
        s32 pad[10];
        u8 sound;
        u8 pad29[0x47];
        u32 pad70_1 : 31;
        u32 active : 1;
    } EmpSpellData;
    s32 pad;
    volatile f32 volume;

    ((EmpSpellData *)arg0)->sound = _subaddieaudioloop_entrypoint_7(((EmpSpellData *)arg0)->sound, arg0->position, 1, &(*(s32 *)D_80802408_chfactoryempspell), ((EmpSpellData *)arg0)->active);
    volume = func_800F1214(arg1, 1.0f, 0.8f);
    func_800C31DC(((EmpSpellData *)arg0)->sound, func_800DC0C0() * 0.1f + volume);
}

/* extern */

void func_80801F30_chfactoryempspell(Actor *arg0) {
    s16 _chmumbopad_entrypoint_0(s32);
    s32 _sumumbofx_entrypoint_0(s32, s32, s32, s16);
    s32 _sumumbofx_entrypoint_2(s32);
    s32 _sumumbofx_entrypoint_24(s32, s32);
    void _sumumbofx_entrypoint_25(void *, s32, s32 *);
    s32 _sumumbofx_entrypoint_28(void *, f32 *, f32, f32);
    void *func_80100094(Actor *, u32);
    void func_808016AC_chfactoryempspell(Actor *);
    void func_80801B2C_chfactoryempspell(Actor *);
    s32 sp2C[3];
    s32 pad;
    void *sp24;

    sp2C[0] = 0;
    sp2C[1] = 0;
    sp2C[2] = 0;
    _sumumbofx_entrypoint_0(arg0, 0, 0x28, _chmumbopad_entrypoint_0(0xB));
    sp24 = func_80100094(arg0, 0);
    _sumumbofx_entrypoint_2(sp24);
    _sumumbofx_entrypoint_24(sp24, 0x3F000000);
    _sumumbofx_entrypoint_25(sp24, 0x8C, sp2C);
    func_80801B2C_chfactoryempspell(arg0);
    func_808016AC_chfactoryempspell(arg0);
    _sumumbofx_entrypoint_28(sp24, arg0->position, 4000.0f, 5000.0f);
}

/* extern */

void func_80801FE0_chfactoryempspell(void *arg0) {
    s32 _subaddieaudioloop_entrypoint_2();
    u8 _subaddieaudioloop_entrypoint_3(u8);
    s32 _sumumbofx_entrypoint_1(void *, s32);
    void func_80801AB4_chfactoryempspell(Actor *);
    _subaddieaudioloop_entrypoint_2();
    (*(u8 *)((s8 *)(arg0) + (0x28))) = _subaddieaudioloop_entrypoint_3((*(u8 *)((s8 *)(arg0) + (0x28))));
    func_80801AB4_chfactoryempspell(arg0);
    if ((*(s16 *)((s8 *)(arg0) + (0x82))) != 0) {
        _sumumbofx_entrypoint_1(arg0, 0);
    }
}

OSThread *chfactoryempspell_entrypoint_1(void)
{
    return (OSThread *) ((u8 *)D_80802414_chfactoryempspell);
}
