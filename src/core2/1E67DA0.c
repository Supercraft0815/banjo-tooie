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

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E67DA0/func_8008E530.s")

void func_8008E618(PlayerState *self) {
    struct Entry {
        u8 pad0[8];
        u8 *(*callback)(void);
        u8 padC[14];
        u16 player : 11;
        u16 low1A : 5;
        u8 pad1C[14];
        u8 high2A : 5;
        u8 flag : 1;
        u8 low2A : 2;
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
    *(s32 *)((u8 *)self->unkC + 0x18) = -1;
}

/* extern */

void func_8008E6BC(void *arg0) {
    s32 func_800EBFF4(s32);
    func_800EBFF4(*(*(s32 **)((s8 *)(arg0) + (0xC))));
    *(*(s32 **)((s8 *)(arg0) + (0xC))) = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E67DA0/func_8008E6F0.s")

s32 func_8008E92C(void *arg0)
{
    return *(s32 *) ((u8 *) *(void **) ((u8 *) arg0 + 0xC) + 0x18);
}

s32 func_8008E938(void *arg0)
{
    return *(s32 *) *(void **) ((u8 *) arg0 + 0xC);
}

void func_8008E944(PlayerState *arg0) {
    void *temp_v0;

    temp_v0 = *(void **) *(void **)((u8 *)arg0 + 0xC);
    (*(u8 *)((s8 *)(temp_v0) + (0x2A))) = (u8) ((*(u8 *)((s8 *)(temp_v0) + (0x2A))) & 0xFFFD);
}

void func_8008E95C(PlayerState *arg0) {
    struct Flags {
        u8 pad[0x28];
        unsigned int upper : 22;
        unsigned int flag : 1;
        unsigned int rest : 9;
    } *flags;

    flags = *(void **) *(void **)((u8 *)arg0 + 0xC);
    flags->flag = 1;
}

s32 func_8008E974(u8 *arg0) {
    struct Flags { unsigned int pad : 22; signed int flag : 1; unsigned int rest : 9; };
    return ((struct Flags *)((u8 *)**(u8 ***)((u8 *)arg0 + 0xC) + 0x28))->flag ? 1 : 0;
}

void func_8008E9A0(void *arg0, s32 arg1)
{
    ((s32 *) *(void **) ((u8 *) arg0 + 0xC))[1] = arg1;
}

s32 func_8008E9AC(void *arg0)
{
    return ((s32 *) *(void **) ((u8 *) arg0 + 0xC))[1];
}

s32 func_8008E9B8(PlayerState *arg0, s32 **arg1) {
    *arg1 = func_8008E4B8(arg0);
    return 3;
}

void func_8008E9E4(void *arg0, s32 arg1, s32 arg2) {
    s32 _glhittableDll_entrypoint_5(s32);
    s32 _glhittableDll_entrypoint_6(s32);
    s32 _glhittableDll_entrypoint_8();
    s32 _glhittableDll_entrypoint_9(s32);
    void _bamotor_entrypoint_1(PlayerState *, f32, f32, f32);
    s32 baflag_set(PlayerState *, s32);
    void func_8009AD14(void *, s32);
    u32 func_8009BD44(void *);
    void func_8009E7C8(PlayerState *, s32);
    s32 func_800A1718(PlayerState *);
    void func_800A17A8(PlayerState *, s32);
    s32 func_800D3948(void);
    s32 func_800F0D90(s32, s32, s32);
    PlayerState *func_800F53D0(s32);
    u32 func_800F54E4(void);
    s32 func_800F6774(s32);
    s32 func_800F6C1C(s32);
    void func_800F76B0(s32, s32, s32);
    void func_800F79DC(s32, s32, s32);
    s32 func_800F9184(void);
    void *func_80100368(void *);
    s32 func_8010108C(void *, s32, s32);
    Actor *func_80106790(Unk80132ED0 *);
    void func_801096C8(void *, s32);
    extern f32 D_80124B70;
    extern f32 D_80124B74;
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
    sp28 = (u32)*(u16 *)((u8 *)arg0 + 0x1A) >> 5;
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
                _bamotor_entrypoint_1(sp20, 0.8f, (f32)sp34 + D_80124B70, 0.3f);
                break;
            case 2:
                sp34 = func_800F0D90(sp34, 1, 5) - 1;
                if ((result = func_8010108C(sp24, 0x50, (sp34 << 16) | (sp28 & 0xFFFF))) > 0) {
                    sp34 = func_800F0D90(result - 1, 0, 4);
                }
                func_800F79DC(sp28, sp34 + 3, arg1);
                _bamotor_entrypoint_1(sp20, 1.0f, (f32)sp34 + D_80124B74, 0.5f);
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
