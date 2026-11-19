#include "core2/1EC3810.h"
#ifdef BT_NATIVE
#include "vector.h" // prototypes for 1EC3810_collision_native.inc follow (LP64 only)
#include BT_LP64_HEADER("native_world_collision.h")
#include BT_LP64_HEADER("native_collision_geometry.h")
#include BT_LP64_HEADER("native_actor_model.h")
#include BT_LP64_HEADER("core2/1EAF950.h")
#endif
#include "core2/1EB2130.h"
extern u16 D_80132DC2;
extern s32 D_80132DC0;

void func_800E9F20(s32 arg0, s32 arg1) {
    void _sufade_entrypoint_1(BtIntPtr arg0);
    Gfx **func_800A7180(void);
    void func_800A8EF0(BtIntPtr arg0, s32 arg1);
    void func_800B525C(BtIntPtr arg0);
    void func_800B52EC(BtIntPtr arg0);
    void func_800B7BB0(void);
    int func_800BC8F8(void *frame);
    int func_800BC948(void *frame);
#if !defined(BT_NATIVE) || defined(BT_ILP32)
    s32 func_800BD594(s32);
#endif
    void func_800BE9B0(void);
    void func_800BE9E4(BtIntPtr mode);
    void func_800BEA24(BtIntPtr mode);
    s32 func_800BF3E4();
    void func_800BFD6C(BtIntPtr arg0, s32 arg1);
    void func_800D2A44(Gfx **output);
    int func_800E44FC(void *frame);
#if !defined(BT_NATIVE) || defined(BT_ILP32)
    s32 func_800EB51C(s32, s32);
#endif
    void func_800F5008(BtIntPtr arg0);
    void func_800F50D0(BtIntPtr arg0);
    void func_800F51CC(void);
    extern BT_NATIVE_ONLY(struct Vector *) BT_IDO_ONLY(s32) D_80127EF4;
    extern s16 D_80132DCC;
    BtIntPtr temp_v0;

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
    s32 _gcsectionDll_entrypoint_3(BtIntPtr, s32);
    extern s32 D_80132DC4;
    return _gcsectionDll_entrypoint_3(D_80132DC4, arg0);
}

s32 func_800EA090(void) {
    extern s16 D_80132DC8;

    return D_80132DC8;
}    typedef struct { s16 unk0; } Obj1EC3810_D_80132DC0; /* offsets.py genstruct: fields from raw offsets on &D_80132DC0; rename once understood */

s32 func_800EA09C(void) {
    return *&((Obj1EC3810_D_80132DC0 *)&D_80132DC0)->unk0;
}

void func_800EA0A8(BT_PASS2(s32 bt_a0, s32 bt_a1))
{
    _gsworldDll_entrypoint_1(&D_80132DC0);
}

/* extern */

void func_800EA0CC(s32 arg0, s32 arg1, s32 arg2) {
    s32 _cothemedll_entrypoint_0();
    void _gsworldDll_entrypoint_2(void *arg0, s32 arg1, s32 arg2, s32 arg3);
    s32 func_800BF8BC(s32);
    void func_800C0064(s32 arg0);
    void func_800DBB5C(void);
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
    void _gsworldDll_entrypoint_3(s16 *arg0, s32 arg1);
    _gsworldDll_entrypoint_3(&D_80132DC0, arg0);
}

s32 func_800EA170(void) {
    void _idworld_entrypoint_5(void);
    void _sulights_entrypoint_9(void);
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
#if !defined(BT_NATIVE) || defined(BT_ILP32)
    s32 func_800D6E54(s32);
#endif
    void func_800D8744(void);
    void func_800DAE9C(void);
    void func_800DBC68(void);
    void func_800E1804(void);
    void func_800E8A68(void);
    void func_800E97C0(void);
    void func_800EE718(void);
    void func_800EE748(void);
    void func_800F84FC(void);
    void func_800FA2C0(void);
    void func_800FFBE4(void);
    void func_800FFBEC(void);
    void func_800FFD10(s32 mode);
#if !defined(BT_NATIVE) || defined(BT_ILP32)
    s32 func_80100534();
#endif
#if !defined(BT_NATIVE) || defined(BT_ILP32)
    s32 func_80100C74();
#endif
    void func_8010D7EC(void);
    extern struct Vector *D_80127EF0;
    extern struct Vector *D_80127EF8;
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
}    typedef struct { s16 unk0; } Obj1EC3810_D_80132DCA; /* offsets.py genstruct: fields from raw offsets on &D_80132DCA; rename once understood */

void func_800EA334(s32 arg0) {
    extern s16 D_80132DCA;
    ((Obj1EC3810_D_80132DCA *)&D_80132DCA)->unk0 = arg0;
}

s32 func_800EA340(void) {
    extern s16 D_80132DCA;

    return D_80132DCA;
}    typedef struct { s16 unk0; } Obj1EC3810_D_80132DCC; /* offsets.py genstruct: fields from raw offsets on &D_80132DCC; rename once understood */

void func_800EA34C(s32 arg0) {
    extern s16 D_80132DCC;
    ((Obj1EC3810_D_80132DCC *)&D_80132DCC)->unk0 = arg0;
}

s32 func_800EA358(void) {
    extern s16 D_80132DCC;

    return D_80132DCC;
}    typedef struct { u16 unk0; } Obj1EC3810_D_80132DCE; /* offsets.py genstruct: fields from raw offsets on &D_80132DCE; rename once understood */

u32 func_800EA364(void) {
    extern u16 D_80132DCE;
    return *&((Obj1EC3810_D_80132DCE *)&D_80132DCE)->unk0;
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(int) func_800EA370()
{
    BT_NATIVE_ONLY(return) func_800EA3A0();
}

#include "1EC3810_prop_hooks.inc"

#if defined(BT_NATIVE) && !defined(BT_ILP32)
static struct {
    f32 position[3];
    Unk80132ED0 *marker;
    u16 *indices;
} world_contacts[8];

int func_800EA3A0(void) {
    for (int i = 0; i < 8; i++) world_contacts[i] = (typeof(world_contacts[0])){0};
    return 0;
}

void func_800EA400(s32 slot, Unk80132ED0 *marker, f32 *position, void *indices) {
    if ((u32)slot >= 8) return;
    func_800EE7F8(world_contacts[slot].position, position);
    world_contacts[slot].marker = marker;
    world_contacts[slot].indices = indices;
}
#else
int func_800EA3A0(void) {
    extern s32 D_80132DD0;
    extern f32 D_80132DD8;
    extern f32 D_80132E78;
    void func_800EFD24(f32 *);
    BT_NATIVE_ONLY(s32 result = 0;) f32 *var_s1;
    s32 *var_s0;
    f32 *end;

    end = &D_80132E78; var_s0 = &D_80132DD0; var_s1 = &D_80132DD8;
    do {
        func_800EFD24(var_s1);
        var_s1 += 5;
        var_s0 += 5;
        var_s0[0] = 0;
        var_s0[1] = 0;
    } while (var_s1 != end); BT_NATIVE_ONLY(return result;)
}

void func_800EA400(s32 arg0, u8 *arg1, BtIntPtr arg2, s32 arg3) {
    extern s32 D_80132DD0;
    func_800EE7F8((f32 *)((u8 *)&D_80132DD0 + arg0 * 0x14 + 8), (f32 *)arg2);
    *(u8 **)((u8 *)&D_80132DD0 + arg0 * 0x14 + 0x14) = arg1;
    *(s32 *)((u8 *)&D_80132DD0 + arg0 * 0x14 + 0x18) = arg3;
}
#endif

void func_800EA45C(void) {
    BT_IDO_ONLY(void func_800D8B80(s16, s32, f32 *, f32 *, f32, s32, u16 *, u8 *, f32 *);)
    BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F5A00(BtIntPtr, f32 *);
#if !defined(BT_NATIVE) || defined(BT_ILP32)
    u8 *func_80103C94(Actor *);
#endif
    Actor *func_80106790(Unk80132ED0 *);
    extern s32 D_80132DD0;
#if defined(BT_NATIVE) && !defined(BT_ILP32)
#define CONTACT_FIELD(i, field) world_contacts[i].field
#define CONTACT_POSITION(i) world_contacts[i].position
#else
    struct Entry { Unk80132ED0 *marker; u16 *indices; f32 position[3]; };
#define CONTACT_FIELD(i, field) ((struct Entry *)&D_80132DD0)[(i) + 1].field
#define CONTACT_POSITION(i) ((struct Entry *)&D_80132DD0)[i].position
#endif
    s32 var_s1;
    f32 sp60[3];
    Actor *temp_s0;

    for (var_s1 = 0; var_s1 != 8; var_s1++) {
        if (CONTACT_FIELD(var_s1, marker) != NULL) {
            temp_s0 = func_80106790(CONTACT_FIELD(var_s1, marker));
            func_800F5A00(var_s1, sp60);
            func_800D8B80(BT_DATA_FIELD((s16)temp_s0->attachment_handle, ((s16 *)&temp_s0->pad80)[0]), var_s1, temp_s0->position, temp_s0->rotation, temp_s0->scale, 0, CONTACT_FIELD(var_s1, indices), func_80103C94(temp_s0), CONTACT_POSITION(var_s1));
        }
    }
}    typedef struct { u8 pad0[0x14]; s32 unk14; } Obj1EC3810_func_800EA51C_var_s2; /* offsets.py genstruct: fields from raw offsets on var_s2; rename once understood */

void func_800EA51C(void) {
    BT_IDO_ONLY(s32 func_800D89C8(s16, s32, f32 *, f32 *, f32, s32, BtIntPtr, f32 *, f32 *);)
    BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F5A00(BtIntPtr, f32 *);
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(void) func_800F8418(BtIntPtr, f32 *);
#if !defined(BT_NATIVE) || defined(BT_ILP32)
    u8 *func_80103C94(Actor *);
#endif
    Actor *func_80106790(Unk80132ED0 *);
    extern s32 D_80132DD0;
    s32 *var_s2;
    f32 sp60[3];
    Unk80132ED0 *temp_a0;
    s32 var_s1;
    Actor *temp_s0;

#if !defined(BT_NATIVE) || defined(BT_ILP32)
    var_s2 = &D_80132DD0;
#endif
    var_s1 = 0;
    do {
#if defined(BT_NATIVE) && !defined(BT_ILP32)
        temp_a0 = world_contacts[var_s1].marker;
#else
        temp_a0 = *(Unk80132ED0 **)&var_s2[5];
#endif
        if (temp_a0 != 0) {
            temp_s0 = func_80106790(temp_a0);
            func_800F5A00(var_s1, sp60);
            if (func_800D89C8(BT_DATA_FIELD((s16)temp_s0->attachment_handle, *(s16 *)&temp_s0->pad80), var_s1, temp_s0->position, temp_s0->rotation, temp_s0->scale, 0, func_80103C94(temp_s0), sp60, sp60) != 0) {
                sp60[1] -= 10.0f;
                func_800F8418(var_s1, sp60);
            }
#if defined(BT_NATIVE) && !defined(BT_ILP32)
            world_contacts[var_s1].marker = NULL;
#else
            (((Obj1EC3810_func_800EA51C_var_s2 *)var_s2)->unk14) = 0;
#endif
        }
        var_s1 += 1;
#if !defined(BT_NATIVE) || defined(BT_ILP32)
        var_s2 += 5;
#endif
    } while (var_s1 != 8);
}

#include "1EC3810_collision.inc"

/* extern */

s32 func_800EB15C(void *arg0) {
    s32 func_800D3948(void);
    u32 func_800F54E4(void);
    s32 func_800F6774(BtUIntPtr);
#if !defined(BT_NATIVE) || defined(BT_ILP32)
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
}    typedef struct { u8 pad0[0xC]; s32 (*unkC)(void *, s32, s32); } Obj1EC3810_func_800EB2DC_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

#include "marker_hit_callbacks.h"

void func_800EB2DC(void *arg0, BtIntPtr arg1, s32 arg2) {
    struct Flags { u32 pad[10]; BT_BITFIELD_ORDER(unsigned int :22, unsigned int  : 9); unsigned int enabled:1; BT_BITFIELD_ORDER(unsigned int :9, unsigned int  : 22); };
    s32 func_800EB15C(void *);
    void *func_800EC3C4(void *);
    void *temp_v0;

    if ((func_800EB15C(arg0) != 0) && MARKER_HIT_LAYOUT((((Unk80132ED0 *)arg0)->unk28 >> 9) & 1, ((struct Flags *)arg0)->enabled)) {
        temp_v0 = func_800EC3C4(arg0);
        if ((arg0 != NULL) && (MARKER_HIT_LAYOUT(((MarkerHitMethods *)temp_v0)->impact, ((Obj1EC3810_func_800EB2DC_temp_v0 *)temp_v0)->unkC) != NULL)) {
            MARKER_HIT_LAYOUT(((MarkerHitMethods *)temp_v0)->impact(arg0, (void *)arg1, arg2), ((Obj1EC3810_func_800EB2DC_temp_v0 *)temp_v0)->unkC(arg0, arg1, arg2));
        }
    }
}

s32 func_800EB350(Actor *arg0, f32 *arg1, f32 *arg2) {
    s32 func_800AAEF4(f32 *, f32, f32 *, f32 *);
    void func_80103328(Actor *);


    func_80103328(arg0);
    return func_800AAEF4(arg0->position, (f32)(u16)arg0->pad68 * arg0->scale * 1.1f, arg1, arg2) == 0;
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
struct Vector * D_80127EF0 BT_DATA(4, bss_core2bss1_0_2, 0x750);
struct Vector *D_80127EF4 BT_DATA(4, bss_core2bss1_0_2, 0x754);
struct Vector *D_80127EF8 BT_DATA(4, bss_core2bss1_0_2, 0x758);
s32 D_80132DC0 BT_DATA(4, bss_core2bss2_1_reset_tail, 0x860);
u16 D_80132DC2 BT_DATA(4, bss_core2bss2_1_reset_tail, 0x862);
s32 D_80132DC4 BT_DATA(4, bss_core2bss2_1_reset_tail, 0x864);
s16 D_80132DC8 BT_DATA(4, bss_core2bss2_1_reset_tail, 0x868);
s16 D_80132DCA BT_DATA(4, bss_core2bss2_1_reset_tail, 0x86A);
s16 D_80132DCC BT_DATA(4, bss_core2bss2_1_reset_tail, 0x86C);
u16 D_80132DCE BT_DATA(4, bss_core2bss2_1_reset_tail, 0x86E);
s32 D_80132DD0 BT_DATA(4, bss_core2bss2_1_reset_tail, 0x870);
f32 D_80132DD8 BT_DATA(4, bss_core2bss2_1_reset_tail, 0x878);
f32 D_80132E78 BT_DATA(4, bss_core2bss2_1_reset_tail, 0x918);
#endif
