#include "common.h"

s16 func_80800000_chcredits(s32 arg0) {
    extern s32 D_8012760D;
    extern s16 D_80801208_chcredits[];
    extern s16 D_808012C0_chcredits[];
    s32 offset = arg0 << 3;
    if ((*(u8 *)((s8 *)(&D_8012760D) + (4))) == 2) {
        return *(s16 *)((u8 *)D_808012C0_chcredits + offset);
    }
    return *(s16 *)((u8 *)D_80801208_chcredits + offset);
}

s16 func_8080003C_chcredits(s32 arg0) {
    extern s32 D_8012760D;
    extern s16 D_80801202_chcredits[];
    extern s16 D_808012BA_chcredits[];
    s32 offset = arg0 << 3;
    if ((*(u8 *)((s8 *)(&D_8012760D) + (4))) == 2) {
        return *(s16 *)((u8 *)D_808012BA_chcredits + offset);
    }
    return *(s16 *)((u8 *)D_80801202_chcredits + offset);
}

s32 func_80800078_chcredits(void) {
    extern s32 D_8012760D;
    u8 *ptr = (u8 *)(u32)((s8 *)&D_8012760D + 3);
    if (ptr[1] == 2) {
        return ptr[0] >= 0x51U;
    }
    return ptr[0] >= 0x16U;
}

void func_808000B4_chcredits(s32 arg0) {
    extern s32 D_8012760D;
    s8 *ptr = (s8 *)(u32)((s8 *)&D_8012760D + 3);
    ptr[1] = arg0;
    ptr[0] = 0;
}

void func_808000C8_chcredits()
{
    _glcutDll_entrypoint_17();
}

s32 func_808000E8_chcredits(void) { s32 _gcfrontend_entrypoint_9(s32); extern volatile u8 D_80127610[]; volatile u8 *ptr = D_80127610; switch (ptr[2]) { case 0: switch (ptr[1]) { case 0: func_808000B4_chcredits(1); break; case 1: func_808000C8_chcredits(); break; } break; case 1: _gcfrontend_entrypoint_9(0x85); ptr = D_80127610; switch (ptr[1]) { case 0: func_808000B4_chcredits(2); break; case 2: func_808000C8_chcredits(); break; } break; case 2: switch (ptr[1]) { case 0: func_808000B4_chcredits(1); break; case 1: func_808000B4_chcredits(2); break; case 2: func_808000C8_chcredits(); break; } break; } }

void chcredits_entrypoint_0(s32 arg0) { s32 func_800DA544(s32); s32 func_808000E8_chcredits(); extern s32 D_8012760D; volatile s8 *ptr; ptr = (s8 *)(u32)((s8 *)&D_8012760D + 3); ptr[1] = 0; ptr[2] = arg0; func_808000E8_chcredits(); func_800DA544(0x650); _glcutDll_entrypoint_0(); _glcutDll_entrypoint_7(func_80800000_chcredits(-1)); _glcutDll_entrypoint_22(0x8C); _glcutDll_entrypoint_16(); }

s32 chcredits_entrypoint_1(void) {
    extern volatile u8 D_80127610[];
    volatile u8 *ptr = D_80127610;
    if (ptr[1] == 2) {
        return func_8080003C_chcredits(ptr[0]);
    }
    return -1;
}

void func_808002A4_chcredits(s32 *arg0) { void func_80800710_chcredits(s32 *, s32); void func_808003E8_chcredits(s32 *, s32); extern s32 D_8012760D; if ((*(u8 *)((s8 *)(&D_8012760D) + 3)) == 0) { func_80800710_chcredits(arg0, 2); } else { func_80800710_chcredits(arg0, 3); } func_808003E8_chcredits(arg0, func_8080003C_chcredits(*(u8 *)((s8 *)(&D_8012760D) + 3))); }

void func_80800300_chcredits(s32 *arg0) {
    void _capod_entrypoint_14(void);
    void _glcutDll_entrypoint_24(u32, u32, u32);
    s32 func_800EA05C();
    s32 func_808000E8_chcredits();
    extern s32 D_8012760D;
    extern volatile u8 D_80127610[];
    volatile struct { s32 map; } saved;
    s32 map;
    s32 current;
    u8 *ptr;
    if (func_80800078_chcredits() != 0) {
        func_808000E8_chcredits();
        return;
    }
    map = func_80800000_chcredits(*(u8 *)((s8 *)&D_8012760D + 3));
    ptr = (u8 *)D_80127610;
    ptr[0] = ptr[0] + (saved.map = map, 1);
    current = func_800EA05C();
    map = saved.map;
    if (current != map) {
        _glcutDll_entrypoint_24(map, -1, -1);
        return;
    }
    _capod_entrypoint_14();
    func_808002A4_chcredits(arg0);
}

/* extern */

void func_8080038C_chcredits(void) {
    void _gcfrontend_entrypoint_10(void);
    s32 _gcgoto_entrypoint_1(s32, s32);
    s32 func_800D395C();
    s32 func_800EA05C();
    s32 temp_v0;

    temp_v0 = func_800EA05C();
    if ((temp_v0 == 0x19C) || (temp_v0 == 0x19D)) {
        if (func_800D395C() != 0) {
            _gcfrontend_entrypoint_10();
            return;
        }
        _gcgoto_entrypoint_1(0x194, 0);
    }
}

/* extern */

void func_808003E8_chcredits(s32 *arg0, s32 arg1) {
    s32 _capod_entrypoint_13(s32, s32, s32, s32);
    s32 _capod_entrypoint_21(s32, s32, s32, s32);
    s32 func_800A5854(s32);
    s32 temp_v0;

    temp_v0 = func_800A5854(arg1);
    if (temp_v0 != 2) {
        if ((temp_v0 == 5) || (temp_v0 == 6) || (temp_v0 == 8)) {
            _capod_entrypoint_13(*arg0, 0, arg1, 0x834);
        }
    } else {
        _capod_entrypoint_21(*arg0, 0, arg1, 0x814);
    }
}

void func_80800464_chcredits(Actor *arg0) {
    u32 *_gldbstring_entrypoint_0(u32 *, u32);
    u32 *_gldbstring_entrypoint_1(u32 *, s16);
    void _gldbstring_entrypoint_2(s32);
    void func_800E715C(u8 *, u8 *);
    void *func_80100094(Actor *, u32);
    extern volatile u8 D_80127610[];
    extern s8 D_80801204_chcredits[];
    extern s8 D_808012BC_chcredits[];
    extern s8 D_808012BD_chcredits[];
    extern s8 D_808012BE_chcredits[];
    extern u8 R_808011B0_chcredits[];
    extern u8 R_808011B4_chcredits[];
    extern u8 R_808011B8_chcredits[];
    extern u8 R_808011BC_chcredits[];
    extern u8 R_808011C0_chcredits[];
    u8 *buffer;
    u32 *strings;
    s32 asset;
    void *text;
    s32 i;

    buffer = func_80100094(arg0, 0);
    if (((u8 *)D_80127610)[1] == 2) {
        asset = D_808012BC_chcredits[((u8 *)D_80127610)[0] * 8] + 0x1B86;
        if (D_808012BC_chcredits[((u8 *)D_80127610)[0] * 8] >= 0) {
            strings = _gldbstring_entrypoint_0(NULL, asset);
            for (i = 0; i != 2; i++) {
                text = _gldbstring_entrypoint_1(strings, i);
                if (text != NULL) {
                    func_800E715C(buffer + i * 0x80, text);
                } else {
                    func_800E715C(buffer + i * 0x80, R_808011B0_chcredits);
                }
            }
            _gldbstring_entrypoint_2(asset);
        } else {
            for (i = 0; i != 2; i++) {
                func_800E715C(buffer + i * 0x80, R_808011B4_chcredits);
            }
        }
        asset = D_808012BD_chcredits[((u8 *)D_80127610)[0] * 8] + 0x1B88;
        strings = _gldbstring_entrypoint_0(NULL, asset);
        text = _gldbstring_entrypoint_1(strings, D_808012BE_chcredits[((u8 *)D_80127610)[0] * 8]);
        func_800E715C(buffer + 0x100, text);
        _gldbstring_entrypoint_2(asset);
    } else {
        asset = D_80801204_chcredits[((u8 *)D_80127610)[0] * 8] + 0x1B68;
        if (D_80801204_chcredits[((u8 *)D_80127610)[0] * 8] >= 0) {
            strings = _gldbstring_entrypoint_0(NULL, asset);
            for (i = 0; i != 2; i++) {
                text = _gldbstring_entrypoint_1(strings, i);
                if (text != NULL) {
                    func_800E715C(buffer + i * 0x80, text);
                } else {
                    func_800E715C(buffer + i * 0x80, R_808011B8_chcredits);
                }
            }
            _gldbstring_entrypoint_2(asset);
        } else {
            for (i = 0; i != 2; i++) {
                func_800E715C(buffer + i * 0x80, R_808011BC_chcredits);
            }
        }
        asset = ((u8 *)D_80127610)[0] + 0x1B6F;
        strings = _gldbstring_entrypoint_0(NULL, asset);
        for (i = 0; i != 3; i++) {
            text = _gldbstring_entrypoint_1(strings, i);
            if (text != NULL) {
                func_800E715C(buffer + (i + 2) * 0x80, text);
            } else {
                func_800E715C(buffer + (i + 2) * 0x80, R_808011C0_chcredits);
            }
        }
        _gldbstring_entrypoint_2(asset);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/credits/func_80800710_chcredits.s")

void func_80800800_chcredits(void *arg0) {
    typedef struct {
        u8 pad0[0x34];
        f32 timer1;
        u8 pad38[0x20];
        f32 timer2;
        u8 pad5C[0x12];
        u16 flags6E : 7;
        u16 alpha : 9;
        unsigned int flags70 : 16;
        unsigned int state : 6;
        unsigned int flags72 : 10;
    } CreditsActor;
    void chcredits_entrypoint_0(s32);
    void func_80015ECC(s32, void *);
    s32 func_800C954C(void);
    f32 func_800D8FF8(void);
    s32 func_800DA9E4(s32, s32);
    s32 func_800EA05C(void);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_80800300_chcredits(s32 *arg0);
    void func_8080038C_chcredits(void);
    void func_80800710_chcredits(s32 *, s32);
    f32 delta;
    s32 buttons[6];
    CreditsActor *self = arg0;

    delta = func_800D8FF8();
    if ((s32)self->state >= 3 && (s32)self->state <= 5) {
        /* Preserve IDO's original argument setup order. */
        if (!buttons) {}
        func_80015ECC(0, buttons);
        if (buttons[1] == 1) {
            func_808000C8_chcredits();
        }
    }
    switch (self->state) {
    case 2:
        if (self->timer1 <= 0) {
            func_80800710_chcredits(arg0, 3);
            return;
        }
        self->timer1 -= delta;
        return;
    case 3:
        if (self->timer2 <= 0) {
            func_80800710_chcredits(arg0, 4);
            self->alpha = 255;
            return;
        }
        self->timer2 -= delta;
        self->alpha = func_800F10B4(self->timer2, 0.75f, 0.0f, 0.0f, 255.0f);
        return;
    case 4:
        if (self->timer2 <= 0) {
            func_80800710_chcredits(arg0, 5);
            return;
        }
        self->timer2 -= delta;
        return;
    case 5:
        if (self->timer2 <= 0) {
            func_80800300_chcredits(arg0);
            self->alpha = 0;
            return;
        }
        self->timer2 -= delta;
        self->alpha = func_800F10B4(self->timer2, 0.75f, 0.0f, 255.0f, 0.0f);
        return;
    case 7:
        if (func_800C954C() == 0) {
            switch (func_800EA05C()) {
            case 0x19C:
                if (func_800DA9E4(0x650, 0) != 0) {
                    func_8080038C_chcredits();
                    return;
                }
                chcredits_entrypoint_0(0);
                return;
            case 0x19D:
                if (func_800DA9E4(0x650, 0) != 0) {
                    func_8080038C_chcredits();
                    return;
                }
                chcredits_entrypoint_0(1);
                return;
            }
        }
        return;
    case 6:
        if (self->timer1 <= 0) {
            func_80800710_chcredits(arg0, 8);
            return;
        }
        self->timer1 -= delta;
        break;
    case 8:
        break;
    }
}

void func_80800BCC_chcredits(s32 arg0) 
{
}
/* extern */

void func_80800BD4_chcredits(s32 *arg0) {
    s32 func_800DA9E4(s32, s32);
    s32 func_800EA05C();
    void func_800EFA4C(f32 *, f32, f32, f32);
    void func_80800710_chcredits(s32 *, s32);
    struct {
        s32 marker;
        f32 position[3];
        u8 pad10[0x6A];
        u8 flags7A : 2;
    } *actor = (void *)arg0;
    s32 temp_v0;
    f32 zero = 0.0f;

    actor->flags7A = 0;
    func_800EFA4C(actor->position, zero, zero, zero);
    temp_v0 = func_800EA05C();
    if ((temp_v0 == 0x19C) || (temp_v0 == 0x19D)) {
        if (func_800DA9E4(0x650, 0) != 0) {
            func_80800710_chcredits(arg0, 6);
        } else {
            func_80800710_chcredits(arg0, 7);
        }
        func_808003E8_chcredits(arg0, 0);
        return;
    }
    func_808002A4_chcredits(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/credits/func_80800C84_chcredits.s")

/* extern */

void func_80800E4C_chcredits(s32 arg0, s32 arg1, Gfx **arg2, s32 arg3) {
    s32 _glglobalsettings_entrypoint_3();
    void func_800B80D0(Gfx **);
    void func_800B8C8C(s32);
    void func_800B8CBC(u8, u8, u8);
    void func_800B8CF0(f32);
    s32 func_800B8CFC(s32);
    s32 func_800B8E28(Gfx **, s32, s32, s32);
    f32 var_f20;
    s32 sp28;
    s32 sp24;
    f32 divisor = 2.0f;

    if (_glglobalsettings_entrypoint_3() != 0) {
        var_f20 = 0.95f;
    } else {
        var_f20 = 1.0f;
    }
    sp28 = (s32) ((304.0f - ((f32) func_800B8CFC(arg0) * var_f20)) / divisor);
    func_800B8C8C(arg3);
    func_800B8CBC(0, 0, 0);
    func_800B8CF0(var_f20);
    func_800B80D0(arg2);
    sp24 = arg1 + 1;
    func_800B8E28(arg2, sp28 + 1, sp24, arg0);
    func_800B8CBC(0xFF, 0xFF, 0xFF);
    func_800B8CF0(var_f20);
    func_800B80D0(arg2);
    func_800B8E28(arg2, sp28, sp24, arg0);
}

s32 func_80800F50_chcredits(Actor *arg0, Gfx **arg1) {
    void func_800B7F14(Gfx **);
    void func_800B811C(Gfx **);
    void func_800B8C50(void);
    void func_800B8CB0(s32);
    s32 func_800E7188(u8 *);
    void *func_80100094(Actor *, u32);
    extern s32 D_8012760D;
    s32 text;
    s32 i;
    s32 titleY;
    s32 bodyY;

    text = (s32)func_80100094(arg0, 0);
    func_800B8C50();
    func_800B7F14(arg1);
    func_800B8CB0(1);
    if (((u8 *)&D_8012760D)[4] == 2) {
        titleY = 0xA0;
        bodyY = 0xAF;
        if (func_800E7188((u8 *)(text + 0x80))) {
            titleY = 0x91;
        }
    } else {
        titleY = 0x55;
        bodyY = 0x78;
    }
    if (func_800E7188((u8 *)text)) {
        if (func_800E7188((u8 *)(text + 0x80))) {
            func_80800E4C_chcredits((s32)text, (s32)((f32)titleY - 7.5f), arg1, arg0->unk6C_0);
            func_80800E4C_chcredits(text + 0x80, (s32)((f32)titleY + 7.5f), arg1, arg0->unk6C_0);
        } else {
            func_80800E4C_chcredits((s32)text, titleY, arg1, arg0->unk6C_0);
        }
    }
    for (i = 0; i < 3; i++) {
        if (func_800E7188((u8 *)(text + (i + 2) * 0x80))) {
            func_80800E4C_chcredits(text + (i + 2) * 0x80, i * 15 + bodyY, arg1, arg0->unk6C_0);
        }
    }
    func_800B811C(arg1);
}

void func_80801108_chcredits(Actor *arg0, Gfx **arg1) {
    void func_800B99CC(Gfx **, s32, s32 *);
    s32 func_80800C84_chcredits(Actor *, Gfx **);
    s32 func_80800F50_chcredits(Actor *, Gfx **);
    extern s32 D_80801590_chcredits;
    s32 var_a1;

    if (!arg0->unk64_19) {
        var_a1 = 0xFF - arg0->unk6C_0;
        if (var_a1 >= 0xF6) {
            var_a1 = 0xFF;
        } else if (var_a1 < 0xA) {
            var_a1 = 0;
        }
        func_800B99CC(arg1, var_a1, &D_80801590_chcredits);
    }
    func_80800F50_chcredits(arg0, arg1);
    func_80800C84_chcredits(arg0, arg1);
}

OSThread *chcredits_entrypoint_2(void)
{
    extern u8 D_8080159C_chcredits[];

    return (OSThread *) D_8080159C_chcredits;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/credits/R_808011B0_chcredits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/credits/R_808011B4_chcredits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/credits/R_808011B8_chcredits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/credits/R_808011BC_chcredits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/credits/R_808011C0_chcredits.s")
