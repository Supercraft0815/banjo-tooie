#include "core2/1E67DA0.h"

s32 func_8008E4B0(void) {
    return sizeof(BaUnknownC);
}

s32 *func_8008E4B8(PlayerState *self) {
    s32 i;
    for (i = 0; i < 3; i++) {
        self->unkC->unkC[i] = (s32)func_8009E138(self, i);
    }
    return self->unkC->unkC;
}

void func_8008E530(PlayerState *self, Unk80132ED0 *marker) {
    struct MarkerFlags {
        u8 pad0[0x18];
        u16 flags;
    };
    struct ActorFlags {
        u8 pad0[0x78];
        BT_BITFIELD_ORDER(u32 high : 28, u32 low : 3);
        u32 bounce : 1;
        BT_BITFIELD_ORDER(u32 low : 3, u32 high : 28);
    };
    Actor *func_80106790(Unk80132ED0 *);
    s32 _chbounce_entrypoint_10(Actor *);
    s32 _glhittableDll_entrypoint_2(s32);
    s32 _glhittableDll_entrypoint_3(void *, Unk80132ED0 *, s32);
    s32 _glhittableDll_entrypoint_4(BtIntPtr arg0, u32 *arg1);
    s32 _glhittableDll_entrypoint_8();
    s32 func_800F424C();
    void func_800EB210(void *, void *, s32);
    Actor *actor;
    s32 hit;

    if ((!(((struct MarkerFlags *)marker)->flags & 1)
         || ((actor = func_80106790(marker), !actor->unk64_17)
             && (!((struct ActorFlags *)actor)->bounce
                 || !_chbounce_entrypoint_10(actor))))
        && ((hit = _glhittableDll_entrypoint_4(*(void **)self->unkC, marker), func_800F424C(self))
            || !_glhittableDll_entrypoint_2(hit)
            || !_glhittableDll_entrypoint_8(hit))
        && !_glhittableDll_entrypoint_3(*(void **)self->unkC, marker, hit)) {
        func_800EB210(marker, *(void **)self->unkC, 0);
    }
}

void func_8008E618(PlayerState *self) {
    struct Entry {
        u8 pad0[8];
        u8 *(*callback)(void);
        u8 padC[14];
        BT_BITFIELD_ORDER(u16 player : 11, u16 low1A : 5);
        BT_BITFIELD_ORDER(u16 low1A : 5, u16 player : 11);
        u8 pad1C[14];
        BT_BITFIELD_ORDER(u8 high2A : 5, u8 low2A : 2);
        u8 flag : 1;
        BT_BITFIELD_ORDER(u8 low2A : 2, u8 high2A : 5);
    };
    void func_8009C128(PlayerState *, f32[3]);
    void *func_800EBFD4(f32 *, s32, u32);
    u8 *func_8008ED70(void);
    void baflag_clear(PlayerState *, int);
    f32 position[3];

    func_8009C128(self, position);
    *(struct Entry **)self->unkC = func_800EBFD4(position, 1, 0);
    (*(struct Entry **)self->unkC)->flag = 1;
    (*(struct Entry **)self->unkC)->callback = func_8008ED70;
    (*(struct Entry **)self->unkC)->player = self->unk184;
    baflag_clear(self, 8);
    self->unkC->unk18 = -1;
} typedef struct { u8 pad0[0xC]; union { s32 * unkC; void * unkC_voidp; }; u8 pad10[0xA]; u16 unk1A; } Obj1E67DA0_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

/* extern */

void func_8008E6BC(void *arg0) {
    void func_800EBFF4(void *data);
    func_800EBFF4(*(((Obj1E67DA0_arg0 *)arg0)->unkC));
    *(((Obj1E67DA0_arg0 *)arg0)->unkC) = 0;
}

void func_8008E6F0(PlayerState *arg0) {
    struct Flags {
        u8 pad[0x28];
        BT_BITFIELD_ORDER(unsigned int upper : 22, unsigned int rest : 9);
        unsigned int flag : 1;
        BT_BITFIELD_ORDER(unsigned int rest : 9, unsigned int upper : 22);
    };
    void func_8009C128(PlayerState *, f32[3]);
    void func_800EC0EC(f32 *, void **);
    void baflag_clear(PlayerState *, int);
    int baflag_isTrue(PlayerState *, s32);
    s32 func_80091E80(u8 *, s32);
    s32 func_8008DAA8(void *);
    s32 func_800EA068(s32);
    BtUIntPtr func_800F54E4(void);
    s32 func_800F5410(BtIntPtr);
    s32 func_800F6D24(BtIntPtr);
    u8 func_800F8B88(void);
    void _bsfirstp_entrypoint_14(PlayerState *);
    void func_800CB840(s32, BtIntPtr);
    void func_800CB870(void);
    s32 func_800CDBA8(void *, f32 (*)[3], f32 *, s32);
    BtIntPtr func_800CDFA8(s32, s32 *);
    extern f32 D_80126CE0[][3];
    extern f32 D_80126D08[];
    f32 position[3];
    BtIntPtr map;
    s32 mode;
    s32 enabled;
    s32 other;
    s32 flag;
    s32 count;
    s32 i;
    s32 index;
    s32 j;
    Unk80132ED0 *marker;
    f32 radius;

    func_8009C128(arg0, position);
    func_800EC0EC(position, *(void ***)arg0->unkC);
    baflag_clear(arg0, 8);
    if ((*(struct Flags **)arg0->unkC)->flag && func_80091E80((u8 *)arg0, 8)) {
        if (!func_800EA068(0x20)) {
            if (!func_8008DAA8(arg0)) {
                map = func_800F54E4();
                mode = func_800F5410(map);
                if (mode != 9) {
                    if (mode != 0xB) {
                        if (mode != 0x11) return;
                        if (func_800F6D24(map)) return;
                    } else {
                        if (func_800F8B88() != 3) return;
                        if (func_800F6D24(map)) return;
                    }
                }
            }
        } else {
            enabled = func_800EA068(8);
            other = func_800EA068(0x4000);
            flag = baflag_isTrue(arg0, 0x3B);
            if (enabled && other && flag) {
                _bsfirstp_entrypoint_14(arg0);
            }
        }
        func_800CB840(1, arg0->unk184);
        for (i = 0; i != 3; i++) {
            radius = func_8009E138(arg0, i);
            if (radius == 0.0f) break;
            D_80126D08[i] = radius;
            func_8009E154(arg0, i, D_80126CE0[i]);
        }
        count = func_800CDBA8(*(void **)arg0->unkC, D_80126CE0, D_80126D08, i);
        for (j = 0; j < count; j++) {
            marker = (Unk80132ED0 *)func_800CDFA8(j, &index);
            arg0->unkC->unk18 = index;
            func_8008E530(arg0, marker);
        }
        func_800CB870();
        arg0->unkC->unk18 = -1;
    }
}

s32 func_8008E92C(void *arg0)
{
    return *(s32 *) ((u8 *) *(void **) ((u8 *) arg0 + 0xC) + 0x18);
}

BtIntPtr func_8008E938(void *arg0)
{
    return *(s32 *) *(void **) ((u8 *) arg0 + 0xC);
}    typedef struct { u8 pad0[0x2A]; u8 unk2A; } Obj1E67DA0_func_8008E944_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void func_8008E944(PlayerState *arg0) {
    void *temp_v0;

    temp_v0 = *(void **) *(void **)((u8 *)arg0 + 0xC);
    (((Obj1E67DA0_func_8008E944_temp_v0 *)temp_v0)->unk2A) = (u8) ((((Obj1E67DA0_func_8008E944_temp_v0 *)temp_v0)->unk2A) & 0xFFFD);
}

void func_8008E95C(PlayerState *arg0) {
    struct Flags {
        u8 pad[0x28];
        BT_BITFIELD_ORDER(unsigned int upper : 22, unsigned int rest : 9);
        unsigned int flag : 1;
        BT_BITFIELD_ORDER(unsigned int rest : 9, unsigned int upper : 22);
    } *flags;

    flags = *(void **) *(void **)((u8 *)arg0 + 0xC);
    flags->flag = 1;
}

s32 func_8008E974(u8 *arg0) {
    struct Flags { BT_BITFIELD_ORDER(unsigned int pad : 22, unsigned int rest : 9); signed int flag : 1; BT_BITFIELD_ORDER(unsigned int rest : 9, unsigned int pad : 22); };
    return ((struct Flags *)((u8 *)**(u8 ***)((u8 *)arg0 + 0xC) + 0x28))->flag ? 1 : 0;
}

void func_8008E9A0(void *arg0, s32 arg1)
{
    ((s32 *) *&((Obj1E67DA0_arg0 *)arg0)->unkC_voidp)[1] = arg1;
}

s32 func_8008E9AC(void *arg0)
{
    return ((s32 *) *(void **) ((u8 *) arg0 + 0xC))[1];
}

s32 func_8008E9B8(PlayerState *arg0, s32 **arg1) {
    *arg1 = func_8008E4B8(arg0);
    return 3;
}

void func_8008E9E4(void *arg0, BtIntPtr arg1, s32 arg2) {
    s32 _glhittableDll_entrypoint_5(s32);
    s32 _glhittableDll_entrypoint_6(s32);
    s32 _glhittableDll_entrypoint_8();
    s32 _glhittableDll_entrypoint_9(s32);
    void _bamotor_entrypoint_1(PlayerState *, f32, f32, f32);
    void baflag_set(void *self, s32 id);
    void func_8009AD14(void *, BtIntPtr);
    u32 func_8009BD44(void *);
    s32 func_8009E7C8(PlayerState *arg0, s32 arg1);
    s32 func_800A1718(PlayerState *);
    void func_800A17A8(PlayerState *, s32);
    s32 func_800D3948(void);
    s32 func_800F0D90(s32, s32, s32);
    PlayerState *func_800F53D0(BtIntPtr);
    BtUIntPtr func_800F54E4(void);
    s32 func_800F6774(BtIntPtr);
    s32 func_800F6C1C(s32);
    s32 func_800F76B0(BtIntPtr arg0, s32 arg1, BtIntPtr arg2);
    s32 func_800F79DC(BtIntPtr arg0, s32 arg1, BtIntPtr arg2);
    s32 func_800F9184(void);
    void *func_80100368(void *);
    s32 func_8010108C(void *, s32, BtIntPtr);
    Actor *func_80106790(Unk80132ED0 *);
    void func_801096C8(void *, s32);


    struct HitFlags {
        u8 pad[0x5C];
        u8 flags[1];
    };
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    u32 sp28;
    void *sp24;
    PlayerState *sp20;
    s32 sp1C;
    register s32 result;

    sp1C = (func_800D3948() == 0 || func_800F6774(func_800F54E4()) != 0) && func_800F9184() == 0;
    sp30 = _glhittableDll_entrypoint_8(arg2);
    sp2C = 0;
    sp24 = func_80106790((Unk80132ED0 *)arg1);
    sp28 = (u32)*&((Obj1E67DA0_arg0 *)arg0)->unk1A >> 5;
    sp20 = func_800F53D0(sp28);
    if (_glhittableDll_entrypoint_9(arg2) != 0) {
        baflag_set(sp20, 8);
    }
    if ((func_8009BD44(sp20) != 3 && func_800F6C1C(sp28) != 0) || sp30 == 0) {
        sp34 = _glhittableDll_entrypoint_5(arg2);
        if (sp34 > 0 && sp34 < 6) {
            sp2C = 2;
            sp30 = sp30 - 1 < 0 ? 0 : sp30 - 1;
        }
        if (sp34 >= 7 && sp34 < 12 &&
            (_glhittableDll_entrypoint_9(arg2) < 2 ||
             (_glhittableDll_entrypoint_6(arg2) != -1 &&
              ((struct HitFlags *)sp24)->flags[_glhittableDll_entrypoint_6(arg2)] != 0))) {
            sp2C = 1;
        }
        if (sp30 != 0 && sp1C != 0) {
            if (_glhittableDll_entrypoint_8(arg2) == 3) {
                func_800A17A8(sp20, -999);
            } else {
                func_800A17A8(sp20, -sp30);
            }
        }
        if (func_800A1718(sp20) == 0) {
            sp2C = 2;
        }
        if (sp2C != 2 || sp1C != 0) {
            switch (sp2C) {
            case 0:
                func_8009AD14(sp20, arg1);
                func_8009E7C8(sp20, 0x72);
                break;
            case 1:
                sp34 = func_800F0D90(sp34, 7, 11) - 7;
                if ((result = func_8010108C(sp24, 0x50, (sp34 << 16) | (sp28 & 0xFFFF))) > 0) {
                    sp34 = func_800F0D90(result - 1, 0, 4);
                }
                func_800F76B0(sp28, sp34 + 8, arg1);
                _bamotor_entrypoint_1(sp20, 0.8f, (f32)sp34 + 0.2f, 0.3f);
                break;
            case 2:
                sp34 = func_800F0D90(sp34, 1, 5) - 1;
                if ((result = func_8010108C(sp24, 0x50, (sp34 << 16) | (sp28 & 0xFFFF))) > 0) {
                    sp34 = func_800F0D90(result - 1, 0, 4);
                }
                func_800F79DC(sp28, sp34 + 3, arg1);
                _bamotor_entrypoint_1(sp20, 1.0f, (f32)sp34 + 0.3f, 0.5f);
                if (*(s32 *)((u8 *)func_80100368(sp24) + 0x24) & 0x03000000) {
                    func_801096C8(sp24, **(s32 **)((u8 *)sp20 + 0xC));
                }
                break;
            }
        }
    }
}

extern u8 D_80117CAC[];

u8 *func_8008ED70(void)
{
    return D_80117CAC;
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
f32 D_80126CE0 [ 3 ] [ 3 ] BT_DATA(16, bss_core2bss1_sound_tail, 0x0);
f32 D_80126D08 [ 6 ] BT_DATA(4, bss_core2bss1_sound_tail, 0x28);
#endif
