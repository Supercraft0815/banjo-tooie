#include "core2/1EC3810.h"
#ifdef BT_NATIVE
// Prototypes for 1EC3810_collision_native.inc, before the calls below declare them implicitly.
#include "native_world_collision.h"
#include "native_collision_geometry.h"
#include "native_actor_model.h"
#include "core2/1EAF950.h"
#endif

extern u16 D_80132DC2;
extern s32 D_80132DC0;

void func_800E9F20(s32 arg0, s32 arg1) {
    s32 _sufade_entrypoint_1(s32);
    s32 func_800A7180();
    s32 func_800A8EF0(s32, s32);
    s32 func_800B525C(s32);
    s32 func_800B52EC(s32);
    s32 func_800B7BB0();
    s32 func_800BC8F8(s32);
    s32 func_800BC948(s32);
#ifndef BT_NATIVE
    s32 func_800BD594(s32);
#endif
    s32 func_800BE9B0();
    s32 func_800BE9E4(s32);
    s32 func_800BEA24(s32);
    s32 func_800BF3E4();
    s32 func_800BFD6C(s32, s32);
    s32 func_800D2A44(s32);
    s32 func_800E44FC(s32);
#ifndef BT_NATIVE
    s32 func_800EB51C(s32, s32);
#endif
    s32 func_800F5008(s32);
    s32 func_800F50D0(s32);
    s32 func_800F51CC();
    extern s32 D_80127EF4;
    extern s16 D_80132DCC;
    s32 temp_v0;

    temp_v0 = func_800A7180();
    if (D_80132DCC == 0) {
        func_800E44FC(temp_v0);
        return;
    }
    func_800BE9B0();
    func_800BFD6C(temp_v0, arg0);
    func_800E44FC(temp_v0);
    func_800D2A44(temp_v0);
    func_800BC8F8(temp_v0);
    func_800BE9E4(temp_v0);
    func_800BD594(temp_v0);
    func_800EB51C(1, temp_v0);
    func_800EB51C(5, temp_v0);
    func_800F5008(temp_v0);
    func_800EB51C(0, temp_v0);
    func_800B525C(temp_v0);
    if (func_800BF3E4() != 0) {
        func_800BEA24(temp_v0);
    }
    func_800B7BB0();
    func_800F50D0(temp_v0);
    func_800EB51C(2, temp_v0);
    func_800B52EC(temp_v0);
    func_800BC948(temp_v0);
    func_800EB51C(6, temp_v0);
    if (D_80127EF4 != 0) {
        _sufade_entrypoint_1(temp_v0);
    }
    func_800A8EF0(temp_v0, arg0);
    func_800F51CC();
}

// Get World Section
MapId func_800EA05C(void) 
{
	return D_80132DC2;
}

s32 func_800EA068(s32 arg0) {
    s32 _gcsectionDll_entrypoint_3(s32, s32);
    extern s32 D_80132DC4;
    return _gcsectionDll_entrypoint_3(D_80132DC4, arg0);
}

s32 func_800EA090(void) {
    extern s16 D_80132DC8;

    return D_80132DC8;
}

s32 func_800EA09C(void) {
    return *(s16 *)((u8 *)&D_80132DC0 + 0);
}

void func_800EA0A8()
{
    _gsworldDll_entrypoint_1(&D_80132DC0);
}

/* extern */

void func_800EA0CC(s32 arg0, s32 arg1, s32 arg2) {
    s32 _cothemedll_entrypoint_0();
    s32 _gsworldDll_entrypoint_2(s32 *, s32, s32, s32);
    s32 func_800BF8BC(s32);
    s32 func_800C0064(s32);
    s32 func_800DBB5C();
    _cothemedll_entrypoint_0();
    func_800DBB5C();
    func_800BF8BC(arg0);
    func_800C0064(arg0);
    _gsworldDll_entrypoint_2(&D_80132DC0, arg0, arg1, arg2);
}

void func_800EA124()
{
    _gsworldDll_entrypoint_4(&D_80132DC0);
}

/* extern */

void func_800EA148(s32 arg0) {
    s32 _gsworldDll_entrypoint_3(s32 *, s32);
    _gsworldDll_entrypoint_3(&D_80132DC0, arg0);
}

s32 func_800EA170(void) {
    s32 _idworld_entrypoint_5();
    s32 _sulights_entrypoint_9();
    void func_8001B50C(void);
    void func_8008B850(void);
    void func_800A1450(void);
    s16 func_800A8184(void);
    void func_800A8E9C(void);
    void func_800ABA9C(void);
    void func_800B50F0(void);
    void func_800B592C(void);
    void func_800B7E38(void);
    void func_800BF710(void);
    void func_800BF7E0(void);
    void func_800BFCC4(s32);
    void func_800BFF70(void);
    void func_800C0438(void);
    void func_800C57F0(void);
    void func_800C718C(void);
    void func_800C7494(void);
    void func_800C8A08(void);
    s32 func_800CE628();
    void func_800CF264(void);
    void func_800D154C(void);
    void func_800D2574(void);
    void func_800D5270(void);
#ifndef BT_NATIVE
    s32 func_800D6E54(s32);
#endif
    void func_800D8744(void);
    s32 func_800DAE9C();
    s32 func_800DBC68();
    s32 func_800E1804();
    void func_800E8A68(void);
    void func_800E97C0(void);
    s32 func_800EE718();
    s32 func_800EE748();
    s32 func_800F84FC();
    s32 func_800FA2C0();
    s32 func_800FFBE4();
    s32 func_800FFBEC();
    s32 func_800FFD10(s32);
#ifndef BT_NATIVE
    s32 func_80100534();
#endif
#ifndef BT_NATIVE
    s32 func_80100C74();
#endif
    s32 func_8010D7EC();
    extern struct Vector *D_80127EF0;
    extern s32 D_80127EF8;
    extern s16 D_80132DCA;
    func_800C718C();
    func_800D8744();
    func_800FA2C0();
    if (func_800A8184() != 4) {
        func_800B7E38();
    }
    if (D_80132DCA == 0) {
        return 1;
    } else {
        func_800FFBE4();
        func_800EE718();
        if (D_80127EF8 != 0) {
            _idworld_entrypoint_5();
        }
        func_800E97C0();
        func_8010D7EC();
        func_800EE748();
        func_800F84FC();
        func_800BF710();
        func_800B592C();
        func_8008B850();
        func_800E1804();
        func_800A8E9C();
        func_800CF264();
        func_800CE628();
        func_800D2574();
        if (func_800EA09C() == 2) {
            func_800A1450();
            func_800DAE9C();
        }
        func_800C57F0();
        if (D_80127EF0 != 0) {
            _sulights_entrypoint_9();
        }
        func_800BFCC4(1);
        func_8001B50C();
        func_800D6E54(1);
        func_800ABA9C();
        func_800BFF70();
        func_800B50F0();
        func_800DBC68();
        func_800E8A68();
        func_800D5270();
        func_800C0438();
        func_800FFD10(1);
        func_800C7494();
        func_80100534();
        func_80100C74();
        func_800FFBEC();
        func_800BF7E0();
        func_800C8A08();
        func_800D154C();
    }
    return 1;
}

void func_800EA334(s32 arg0) {
    extern s16 D_80132DCA;
    *(s16 *)((u8 *)&D_80132DCA + 0) = arg0;
}

s32 func_800EA340(void) {
    extern s16 D_80132DCA;

    return D_80132DCA;
}

void func_800EA34C(s32 arg0) {
    extern s16 D_80132DCC;
    *(s16 *)((u8 *)&D_80132DCC + 0) = arg0;
}

s32 func_800EA358(void) {
    extern s16 D_80132DCC;

    return D_80132DCC;
}

u32 func_800EA364(void) {
    extern u16 D_80132DCE;
    return *(u16 *)((u8 *)&D_80132DCE + 0);
}

void func_800EA370()
{
    func_800EA3A0();
}

#include "1EC3810_prop_hooks.inc"

int func_800EA3A0(void) {
    extern s32 D_80132DD0;
    extern f32 D_80132DD8;
    extern f32 D_80132E78;
    void func_800EFD24(f32 *);
    f32 *var_s1;
    s32 *var_s0;
    f32 *end;

    end = &D_80132E78; var_s0 = &D_80132DD0; var_s1 = &D_80132DD8;
    do {
        func_800EFD24(var_s1);
        var_s1 += 5;
        var_s0 += 5;
        var_s0[0] = 0;
        var_s0[1] = 0;
    } while (var_s1 != end);
}

void func_800EA400(s32 arg0, u8 *arg1, s32 arg2, s32 arg3) {
    extern s32 D_80132DD0;
    func_800EE7F8((f32 *)((u8 *)&D_80132DD0 + arg0 * 0x14 + 8), (f32 *)arg2);
    *(u8 **)((u8 *)&D_80132DD0 + arg0 * 0x14 + 0x14) = arg1;
    *(s32 *)((u8 *)&D_80132DD0 + arg0 * 0x14 + 0x18) = arg3;
}

void func_800EA45C(void) {
    void func_800D8B80(s16, s32, f32 *, f32 *, f32, s32, u16 *, u8 *, f32 *);
    void func_800F5A00(s32, f32 *);
#ifndef BT_NATIVE
    u8 *func_80103C94(Actor *);
#endif
    Actor *func_80106790(Unk80132ED0 *);
    extern s32 D_80132DD0;
    struct Entry { Unk80132ED0 *marker; u16 *indices; f32 position[3]; };
    s32 var_s1;
    f32 sp60[3];
    Actor *temp_s0;

    for (var_s1 = 0; var_s1 != 8; var_s1++) {
        if (((struct Entry *)&D_80132DD0)[var_s1 + 1].marker != NULL) {
            temp_s0 = func_80106790(((struct Entry *)&D_80132DD0)[var_s1 + 1].marker);
            func_800F5A00(var_s1, sp60);
            func_800D8B80(((s16 *)&temp_s0->pad80)[0], var_s1, temp_s0->position, temp_s0->rotation, temp_s0->scale, 0, ((struct Entry *)&D_80132DD0)[var_s1 + 1].indices, func_80103C94(temp_s0), ((struct Entry *)&D_80132DD0)[var_s1].position);
        }
    }
}

void func_800EA51C(void) {
    s32 func_800D89C8(s16, s32, f32 *, f32 *, f32, s32, s32, f32 *, f32 *);
    void func_800F5A00(s32, f32 *);
    s32 func_800F8418(s32, f32 *);
#ifndef BT_NATIVE
    u8 *func_80103C94(Actor *);
#endif
    Actor *func_80106790(Unk80132ED0 *);
    extern s32 D_80132DD0;
    s32 *var_s2;
    f32 sp60[3];
    Unk80132ED0 *temp_a0;
    s32 var_s1;
    Actor *temp_s0;

    var_s2 = &D_80132DD0;
    var_s1 = 0;
    do {
        temp_a0 = *(Unk80132ED0 **)&var_s2[5];
        if (temp_a0 != 0) {
            temp_s0 = func_80106790(temp_a0);
            func_800F5A00(var_s1, sp60);
            if (func_800D89C8(*(s16 *)&temp_s0->pad80, var_s1, temp_s0->position, temp_s0->rotation, temp_s0->scale, 0, func_80103C94(temp_s0), sp60, sp60) != 0) {
                sp60[1] -= 10.0f;
                func_800F8418(var_s1, sp60);
            }
            (*(s32 *)((s8 *)(var_s2) + (0x14))) = 0;
        }
        var_s1 += 1;
        var_s2 += 5;
    } while (var_s1 != 8);
}

#include "1EC3810_collision.inc"

/* extern */

s32 func_800EB15C(void *arg0) {
    s32 func_800D3948(void);
    u32 func_800F54E4(void);
    s32 func_800F6774(u32);
#ifndef BT_NATIVE
    s32 func_80102F74(Unk80132ED0 *, s32);
#endif
    Actor *func_80106790(Unk80132ED0 *);
    Unk80132ED0 *marker = arg0;
    if (marker->unk18 & 1) {
        return 0;
    }
    if ((marker->unk24 >> 22) == 0) {
        return 1;
    }
    if (func_800D3948() == 0 && func_800F6774(func_800F54E4()) == 0) {
        if ((((u16 *)&marker->unk18)[0] & 1) && func_80102F74(func_80106790(marker), 0x88000000) != 0) {
            return 1;
        }
        return 0;
    }
    return 1;
}

void func_800EB210(void *arg0, void *arg1, s32 arg2) {
    struct Callbacks {
        void (*first)(void *, void *);
        void (*second)(void *, void *);
        void (*third)(void *, void *);
    };
    void *func_800EC3C4(void *);
    struct Callbacks *callbacks;

    if (func_800EB15C(arg0) != 0) {
        callbacks = func_800EC3C4(arg0);
        switch (arg2) {
            case 0:
                if (callbacks->first != NULL) {
                    callbacks->first(arg0, arg1);
                }
                break;
            case 1:
                if (callbacks->second != NULL) {
                    callbacks->second(arg0, arg1);
                }
                break;
            case 2:
                if (callbacks->third != NULL) {
                    callbacks->third(arg0, arg1);
                }
                break;
        }
    }
}

/* extern */

void func_800EB2DC(void *arg0, s32 arg1, s32 arg2) {
    struct Flags { u32 pad[10]; unsigned int :22; unsigned int enabled:1; unsigned int :9; };
    s32 func_800EB15C(void *);
    void *func_800EC3C4(void *);
    void *temp_v0;

    if ((func_800EB15C(arg0) != 0) && ((struct Flags *)arg0)->enabled) {
        temp_v0 = func_800EC3C4(arg0);
        if ((arg0 != NULL) && ((*(s32 (**)(void *, s32, s32))((s8 *)(temp_v0) + (0xC))) != NULL)) {
            (*(s32 (**)(void *, s32, s32))((s8 *)(temp_v0) + (0xC)))(arg0, arg1, arg2);
        }
    }
}

s32 func_800EB350(Actor *arg0, f32 *arg1, f32 *arg2) {
    s32 func_800AAEF4(f32 *, f32, f32 *, f32 *);
    void func_80103328(Actor *);
    extern f32 D_80125E5C;

    func_80103328(arg0);
    return func_800AAEF4(arg0->position, (f32)(u16)arg0->pad68 * arg0->scale * D_80125E5C, arg1, arg2) == 0;
}
