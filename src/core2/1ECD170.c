#include "core2/1ECD170.h"

void func_800F3880(s32 arg0)
{
    func_80098E64();
    heap_free(arg0);
}
struct player_state_s;
int func_800F38A8(struct player_state_s *arg0, s32 arg1) {
    s32 func_800F3ED0(void *);
    s32 func_800F40EC(struct player_state_s *);
    return (((arg1 & 4) != 0) && (func_800F40EC(arg0) == 2)) ||
           (((arg1 & 2) != 0) && (func_800F40EC(arg0) == 1)) ||
           (((arg1 & 1) != 0) && (func_800F3ED0(arg0) == 0xA));
}

s32 func_800F3930(struct player_state_s *arg0, s32 arg1, s32 arg2) {
    int baflag_isTrue(struct player_state_s *, s32);
    s32 bs_getCurrentState(struct player_state_s *);
    s32 func_8008EF3C(struct player_state_s *, s32);
    s32 func_8009CA70(struct player_state_s *, s32, s32);
    s32 func_800A9C98(void);
    s32 func_800F64A4(s32, s32);
    int func_800F6774(u32);
    s32 func_800F6CC8(s32);
    s32 func_800F9184(void);
    int player_isStable(struct player_state_s *);
    s32 sp24;
    sp24 = func_800F38A8(arg0, arg2);
    if (func_800F9184() != 0) {
    return 0;
    }
    if (func_800F6774(*(s32 *)((s8 *)arg0 + 0x184)) == 0) {
    return 0;
    }
    if (func_800F6CC8(*(s32 *)((s8 *)arg0 + 0x184)) != 0) {
    return 0;
    }
    if (func_8008EF3C(arg0, 0) == 0x13) {
    return 0;
    }
    if ((player_isStable(arg0) == 0) && (sp24 == 0)) {
    return 0;
    }
    if (func_800F64A4(*(s32 *)((s8 *)arg0 + 0x184), 0x12000) != 0) {
    return 0;
    }
    if (func_800F64A4(*(s32 *)((s8 *)arg0 + 0x184), arg1) == 0) {
    return 0;
    }
    if (baflag_isTrue(arg0, 0x3F) != 0) {
    return 0;
    }
    if (func_8009CA70(arg0, bs_getCurrentState(arg0), 0x20) != 0) {
    return 0;
    }
    if (func_800A9C98() != 0) {
    return 0;
    }
    return 1;

}

/* extern */

struct player_state_s;
s32 func_800F3A78(struct player_state_s *arg0, s32 arg1, s32 arg2) {
    int func_8009C128(void *, f32[3]);
    f32 bastick_distance(struct player_state_s *);
    s32 func_8009E674(struct player_state_s *, s32);
    s32 func_800A9C98(void);
    int func_800F38A8(struct player_state_s *, s32);
    s32 func_800F3930(struct player_state_s *, s32, s32);
    s32 func_800F5FA8(s32);
    s32 sp24;

    if (func_800F3930(arg0, arg1, arg2) == 0) {
        return 0;
    }
    if (func_8009E674(arg0, 0x8000) != 0) {
        return 0;
    }
    sp24 = func_800F38A8(arg0, arg2);
    if ((bastick_distance(arg0) != 0.0f) && (sp24 == 0)) {
        return 0;
    }
    if (func_800F5FA8((*(s32 *)((s8 *)(arg0) + (0x184)))) == 0) {
        return 0;
    }
    if (func_800A9C98() != 0) {
        return 0;
    }
    return 1;
}

typedef struct player_state_s PlayerState;
f32 func_800F3B3C(PlayerState *arg0, f32 *arg1, s32 arg2) {
    void func_8009E154(PlayerState *, s32, f32 *);
    s32 func_8008E9B8(PlayerState *, s32 **);
    s32 *sp1C;

    func_8009E154(arg0, arg2, arg1);
    func_8008E9B8(arg0, &sp1C);
    return (f32)sp1C[arg2];
}

void func_800F3B90(PlayerState *arg0, f32 *arg1) {
    func_800F3B3C(arg0, arg1, 0U);
}

#ifdef BT_NATIVE
void func_800F3BB0(s32 bt_a0, s32 bt_a1)
#else
void func_800F3BB0()
#endif
{
#ifdef BT_NATIVE
    int func_8009C128(void *, f32[3]);
    ((int (*)())func_8009C128)();
#else
    func_8009C128();
#endif
}

void func_800F3BD0(void *self, s32 arg1, f32 dst[3]) {
    void func_80092D44(void *, f32 *);
    void func_80092E5C(void *, f32 *);
    void func_80092C00(void *, f32 *);
    void func_80092C24(void *, f32 *);
    void func_80092C48(void *, f32 *);
    int func_800A3274(PlayerState *);
    s32 func_800F40EC(struct player_state_s *);
    s32 func_800F6720();
    void func_80092DC0(void *, f32 *);
    void func_8009C188(u8 *, s32);
    void func_80092D9C(void *, f32 *);


    switch (arg1) {
        case 1:
            func_80092D44(self, dst);
            break;
        case 2:
            func_80092E5C(self, dst);
            break;
        case 3:
            func_80092C00(self, dst);
            break;
        case 4:
            func_80092C24(self, dst);
            break;
        case 6:
            func_80092C48(self, dst);
            break;
        case 5:
            func_8009C128(self, dst);
            switch (func_800A3274(self)) {
                case 0x2:
                    dst[1] += 85.0f;
                    break;
                case 0xF:
                    dst[1] += 90.0f;
                    break;
                case 0x6:
                    dst[1] += 85.0f;
                    break;
                case 0x7:
                    dst[1] += 130.0f;
                    break;
                case 0xE:
                    dst[1] += 575.0f;
                    break;
                case 0x10:
                    dst[1] += 130.0f;
                    break;
                case 0xC:
                    dst[1] += 45.0f;
                    break;
                case 0x11:
                    dst[1] += 40.0f;
                    break;
                case 0x12:
                    dst[1] += 130.0f;
                    break;
                case 0x13:
                    dst[1] += 400.0f;
                    break;
                case 0xB:
                    dst[1] += 55.0f;
                    break;
                case 0x1:
                    if (func_800F40EC(self) == 2 || func_800F6720(*(s32 *)((u8 *)self + 0x184))) {
                        dst[1] += 70.0f;
                    } else {
                        dst[1] += 100.0f;
                    }
                    break;
                default:
                    dst[1] += 100.0f;
                    break;
            }
            break;
        case 7:
            func_80092DC0(self, dst);
            break;
        case 8:
            func_8009C188((u8 *)self, (s32)dst);
            break;
        case 9:
            func_80092D9C(self, dst);
            break;
        case 0:
        default:
            func_800F3BB0(self, dst);
            break;
    }
}

/* extern */

void func_800F3E84(s32 arg0, void *arg1) {
    f32 baroll_get(s32);
    f32 func_8009BFCC();
    f32 yaw_get(s32);
    (*(f32 *)((s8 *)(arg1) + (0))) = func_8009BFCC();
    (*(f32 *)((s8 *)(arg1) + (4))) = yaw_get(arg0);
    (*(f32 *)((s8 *)(arg1) + (8))) = baroll_get(arg0);
}

s32 func_800F3ED0(void *arg0) {
    s32 _bashoes_entrypoint_1(PlayerState *);
    int baflag_isTrue(PlayerState *, s32);
    s32 bastatetimer_isActive(PlayerState *, s32);
    s32 bs_getCurrentState(PlayerState *);
    s32 func_8008EF3C(PlayerState *, s32);
    s16 func_8009CBDC(PlayerState *, s32);
    s32 func_8009E674(PlayerState *, s32);
    s32 state;

    state = bs_getCurrentState(arg0);
    if (baflag_isTrue(arg0, 0x1B)) {
        return 0xD;
    }
    if (baflag_isTrue(arg0, 0x17)) {
        return 4;
    }
    if (func_8009CBDC(arg0, state) == 9) {
        return 0xA;
    }
    if (func_8009CBDC(arg0, state) == 0x12) {
        return 0xC;
    }
    if (func_8009CBDC(arg0, state) == 0x13) {
        return 0xE;
    }
    if (func_8009CBDC(arg0, state) == 8) {
        return 9;
    }
    if (func_8009CBDC(arg0, state) == 0xA) {
        return 5;
    }
    if (baflag_isTrue(arg0, 9)) {
        return 1;
    }
    if (func_8009E674(arg0, 0x80)) {
        switch (_bashoes_entrypoint_1(arg0)) {
            case 3: return 6;
            case 4: return 0x10;
            case 5: return 0xF;
        }
    }
    switch (state) {
        case 0xE:
        case 0x34:
        case 0x3C:
        case 0x3F:
        case 0x41:
        case 0x44:
        case 0x120:
            return 1;
        case 0x1A:
        case 0x1B:
        case 0x1C:
        case 0x1D:
        case 0x1E:
        case 0xA4:
        case 0xA5:
            return 3;
        case 8:
        case 0x15:
        case 0x16:
        case 0x17:
        case 0x45:
            if (bastatetimer_isActive(arg0, 3)) {
                return 6;
            }
            return 8;
        case 0xB:
            return 2;
        default:
            if (func_8008EF3C(arg0, 0)) {
                return 0xB;
            }
            return 0;
    }
}

s32 func_800F40EC(PlayerState *arg0) {
    s32 _bsjump_entrypoint_16(PlayerState *);
    s32 bs_getCurrentState(PlayerState *);
    f32 func_80096364(PlayerState *);
    f32 func_800964DC(PlayerState *);
    s32 func_80096544(PlayerState *);
    s32 func_8009CA70(PlayerState *, s32, s32);
    int func_800A3274(PlayerState *);
    s32 sp24;
    f32 sp20;

    sp24 = bs_getCurrentState(arg0);
    if (func_800A3274(arg0) == 0xC) {
        if (func_80096544(arg0) == 0) {
            return 0;
        }
        sp20 = func_800964DC(arg0);
        if (sp20 - func_80096364(arg0) < 50.0f) {
            return 0;
        }
    }
    if (func_8009CA70(arg0, sp24, 1) || func_8009CA70(arg0, sp24, 0x40000)) {
        return 1;
    }
    if (sp24 == 5) {
        if (_bsjump_entrypoint_16(arg0)) {
            return 1;
        }
        return 0;
    } else if (func_8009CA70(arg0, sp24, 2)) {
        return 2;
    }
    return 0;
}

void func_800F4200(u8 *arg0, f32 *arg1) {
    int func_8009C128(void *, f32[3]);
    void func_8009C1CC(u8 *, f32[3]);
    void func_800EE780(f32 *, f32 *, f32 *);
    f32 sp24[3];
    f32 sp18[3];

    func_8009C128(arg0, sp24);
    func_8009C1CC(arg0, sp18);
    func_800EE780(arg1, sp24, sp18);
}

s32 func_800F4244(s32 *arg0) {
    return arg0[95];
}

s32 func_800F424C(void *arg0) {
    s32 func_8008DAA8(void *);
    s32 func_8008E124(struct player_state_s *);
    s32 func_8008E974(u8 *);
    s32 func_8009E674(struct player_state_s *, s32);
    s32 func_800F5410(s32);
    u32 func_800F54E4(void);
    s32 func_800F6D24(s32);
    int func_800F8004(s32);
    s32 temp_v0;
    s32 sp24;
    s32 sp1C;
    s32 temp_v0_2;

    if (*(s32 *)((u8 *)arg0 + 0x17C) == 0) {
        return 0;
    }
    if (func_8009E674(arg0, 4) != 0) {
        return 0;
    }
    if (func_8009E674(arg0, 0x2000) != 0) {
        return 0;
    }
    if (func_8008E124(arg0) != 0) {
        return 0;
    }
    if (func_8008E974(arg0) == 0) {
        return 0;
    }
    if (func_800F8004(*(s32 *)((u8 *)arg0 + 0x184)) != 0) {
        return 0;
    }
    if (func_8008DAA8(arg0) == 0) {
        temp_v0 = func_800F54E4();
        if (temp_v0 != -1) {
            sp24 = temp_v0;
            sp1C = func_800F5410(temp_v0) == 0x11;
            temp_v0_2 = func_800F6D24(sp24);
            if (sp1C != 0 && temp_v0_2 != 0) {
                return 0;
            }
        }
    }
    return 1;
}

s32 func_800F4354(s32 arg0) {
    typedef struct {
        s32 value;
        s32 (*callback)(s32);
    } CacheEntry;
    extern CacheEntry D_801235D0[];

    if (D_801235D0[arg0].value >= 0) {
        return D_801235D0[arg0].value;
    }
    D_801235D0[arg0].value = D_801235D0[arg0].callback(arg0);
    return D_801235D0[arg0].value;
}

/* extern */

u8 *func_800F43A8(s32 arg0) {
    void func_800F44DC(void *, s32);
    s32 func_80098C48(u8 *);
    s32 func_800F4354(s32);
    void *heap_alloc(s32);
    void *heap_realloc(void *, s32);
    s32 temp_v0;
    s32 temp_v0_3;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_a2;
    s32 var_a2_2;
    s32 var_s1;
    s32 var_s1_2;
    u32 var_s0;
    u8 *temp_v0_2;
    u8 *var_s2;

    var_s1 = 0x19C;
    var_s2 = heap_alloc(0x19C);
    for (var_s0 = 0; var_s0 < 0x56U; var_s0++) {
        temp_v0 = func_800F4354(var_s0);
        var_s1 += temp_v0 + (temp_v0 % 4 ? 4 - temp_v0 % 4 : 0L);
        temp_v0_2 = heap_realloc(var_s2, var_s1);
        var_s2 = temp_v0_2;
    }
    bzero(var_s2, var_s1);
    var_s1_2 = 0x19C;
    var_s0 = 0;
    do {
        *(u8 **)((u32)var_s2 + (var_s0 << 2)) = var_s2 + var_s1_2;
        temp_v0_3 = func_800F4354(var_s0);
        var_s1_2 += temp_v0_3 + (temp_v0_3 % 4 ? 4 - temp_v0_3 % 4 : 0L);
        var_s0 += 1;
    } while (var_s0 <= 0x55U);
    (*(s32 *)((s8 *)(var_s2) + (0x180))) = 0;
    (*(s32 *)((s8 *)(var_s2) + (0x184))) = arg0;
    func_80098C48(var_s2);
    func_800F44DC(var_s2, 1);
    return var_s2;
}

/* extern */

void func_800F44DC(void *arg0, s32 arg1) {
    s32 func_800A4C88();
    void func_8010F9C0(s32, s32);
    s32 var_a1;
    s32 temp_a0;

    (*(s32 *)((s8 *)(arg0) + (0x17C))) = arg1;
    temp_a0 = func_800A4C88();
    if (arg1 != 0) {
        var_a1 = 2;
    } else {
        var_a1 = 1;
    }
    func_8010F9C0(temp_a0, var_a1);
}

void func_800F4524(s32 *arg0, s32 arg1) {
    arg0[96] = arg1;
}

/* extern */

void func_800F452C(s32 arg0) {
    s32 func_80095C94(s32);
    s32 func_8009C0BC();
    s32 func_800A10A0(s32);
    s32 func_800A380C(s32);
    s32 func_800A4030(s32);
    s32 func_800A4B08(s32);
    func_8009C0BC();
    func_80095C94(arg0);
    func_800A10A0(arg0);
    func_800A4030(arg0);
    func_800A4B08(arg0);
    func_800A380C(arg0);
}

/* extern */

void func_800F457C(void *arg0, s32 arg1) {
    struct player_state_s;
    void func_8009CCA4(struct player_state_s *arg0);
    void func_8009CCFC(s32 *arg0, s32 arg1);
    if (arg1 == 0) {
        func_8009CCA4(arg0);
        return;
    }
    func_8009CCFC(arg0, arg1);
}

s32 func_800F45B0(s32 arg0, s32 arg1, s32 arg2) {
    void func_8009CCFC(s32 *, s32);
    s32 func_8009CD70(s32, s32);
    func_8009CCFC(arg0, arg1);
    func_8009CD70(arg0, arg2);
}

/* extern */

struct player_state_s;
void func_800F45E0(struct player_state_s *arg0, f32 *arg1) {
    void func_8009BF5C(struct player_state_s *, f32);
    void yaw_setIdeal(struct player_state_s *, f32);
    void baroll_setIdeal(struct player_state_s *, f32);
    void yaw_applyIdeal(struct player_state_s *);
    void baroll_applyIdeal(struct player_state_s *);
    void func_8009BFBC(void *);
    func_8009BF5C(arg0, arg1[0]);
    yaw_setIdeal(arg0, arg1[1]);
    baroll_setIdeal(arg0, arg1[2]);
    func_8009BFBC(arg0);
    yaw_applyIdeal(arg0);
    baroll_applyIdeal(arg0);
}

void func_800F4648(void *arg0, f32 arg1[3]) {
    f32 sp24[3];
    f32 sp18[3];

    func_8009C128(arg0, sp24);
    func_800EFB24(sp18, arg1, sp24);
    func_8009C1F8(arg0, sp18);
}

/* extern */

void func_800F468C(void *arg0) {
    s32 func_800991B0(void *);
    s32 func_800EA09C();
    if (((*(s32 *)((s8 *)(arg0) + (0x17C))) != 0) && ((*(s32 *)((s8 *)(arg0) + (0x180))) == 0) && (func_800EA09C() == 2)) {
        func_800991B0(arg0);
    }
}

void *func_800F46D8(void *arg0) {
    void *defrag(void *);
    void func_80099544(void *);
    struct {
        void *old;
        s32 offset;
        s32 i;
    } relocation;

    func_80099544(arg0);
    relocation.old = arg0;
    arg0 = defrag(arg0);
    if (relocation.old == arg0) {
        return arg0;
    } else {
        relocation.offset = (u8 *)arg0 - (u8 *)relocation.old;
        for (relocation.i = 0; relocation.i < 0x56; relocation.i++) {
            *(s32 *)((s32)arg0 + (relocation.i << 2)) += relocation.offset;
        }
    }
    return arg0;
}
