#include "core2/1E7D460.h"

s32 func_800A3B70() 
{
    return 0x40;
}

/* extern */

void func_800A3B78(PlayerState *arg0, s32 arg1) {
    s32 func_801106A8(PlayerState *, s32);
    PlayerState *temp_v0;

    temp_v0 = func_800A4CA8(arg0);
    if (temp_v0 != NULL) {
        func_801106A8(temp_v0, arg1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7D460/func_800A3BA8.s")

/* extern */

void func_800A3D78(u8 *arg0, s32 arg1, s32 arg2) {
    s32 func_800A3BA8(s32, s32);
    u8 *temp_v0;

    temp_v0 = (*(u8 **)((s8 *)(arg0) + (0x38)));
    if (arg1 != (*(u8 *)((s8 *)(temp_v0) + (2)))) {
        (*(u8 *)((s8 *)(temp_v0) + (2))) = arg1;
        func_800A3BA8((s32)arg0, arg2);
    }
}

u32 func_800A3DAC(void *arg0) {
    return *(u8 *)((u8 *)*(void **)((u8 *)arg0 + 56) + 2);
}

/* extern */

void func_800A3DB8(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 func_800A3BA8(s32, s32);
    void func_800A59B8(s32, s32 *, s32 *, s32 *, s32 *, s32 *, s32 *, s32 *, s32 *, s32 *);
    u8 *temp_v0;

    temp_v0 = (*(u8 **)((s8 *)(arg0) + (0x38)));
    if ((arg1 != (*(u8 *)((s8 *)(temp_v0) + (1)))) || (arg2 != (*(s16 *)((s8 *)(temp_v0) + (0x34)))) || (arg3 != (*(u8 *)((s8 *)(temp_v0) + (0x39))))) {
        (*(u8 *)((s8 *)(temp_v0) + (1))) = (u8) arg1;
        temp_v0 = (*(u8 **)((s8 *)(arg0) + (0x38)));
        func_800A59B8((*(u8 *)((s8 *)(temp_v0) + (1))), (s32 *)(temp_v0 + 8), (s32 *)(temp_v0 + 0xC), (s32 *)(temp_v0 + 0x10), (s32 *)(temp_v0 + 0x14), (s32 *)(temp_v0 + 0x18), (s32 *)(temp_v0 + 0x1C), (s32 *)(temp_v0 + 0x20), (s32 *)(temp_v0 + 0x24), (s32 *)(temp_v0 + 0x28));
        (*(s16 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x38)))) + (0x34))) = (s16) arg2;
        (*(u8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x38)))) + (0x39))) = (u8) arg3;
        if ((func_800A3DAC(arg0) == 3) && ((temp_v0 = (*(u8 **)((s8 *)(arg0) + (0x38))), ((*(s32 *)((s8 *)(temp_v0) + (0x20))) == 0)) || ((*(u8 *)((s8 *)(temp_v0) + (0x39))) != 0))) {
            func_800A3D78(arg0, 2, arg4);
            return;
        }
        func_800A3BA8((s32)arg0, arg4);
    }
}

/* extern */

void func_800A3EC8(PlayerState *arg0, s32 arg1) {
    s32 func_80110D08(PlayerState *, u8, PlayerState *);
    if (arg1 != (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x38)))) + (7)))) {
        (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x38)))) + (7))) = arg1;
        func_80110D08(func_800A4CA8(arg0), (*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x38)))) + (7))), arg0);
    }
}

/* extern */

void func_800A3F14(PlayerState *arg0, s32 arg1) {
    void func_80090C28(PlayerState *, s32);
    u8 *temp_v0;

    temp_v0 = (*(void **)((s8 *)(arg0) + (0x38)));
    if (arg1 != temp_v0[6]) {
        switch (temp_v0[6]) {                          /* switch 1; irregular */
        case 5:                                     /* switch 1 */
            func_80090C28(arg0, 1);
            break;
        case 7:                                     /* switch 1 */
            func_800A3D78(arg0, (*(u8 *)((s8 *)(temp_v0) + (0x3A))), 1);
            (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x38)))) + (0x3A))) = 0;
            break;
        }
        switch (arg1) {                             /* switch 2; irregular */
        case 2:                                     /* switch 2 */
            func_800A3B78(arg0, 0x13);
            break;
        case 7:                                     /* switch 2 */
            func_800A3B78(arg0, 0x1A);
            (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x38)))) + (0x3A))) = func_800A3DAC(arg0);
            func_800A3D78(arg0, 4U, 1);
            break;
        case 8:                                     /* switch 2 */
            func_800A3B78(arg0, 0x18);
            break;
        case 6:                                     /* switch 2 */
            func_800A3B78(arg0, 2);
            break;
        }
        (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x38)))) + (6))) = (s8) arg1;
    }
}

/* extern */

void func_800A4030(void *arg0) {
    s32 func_800A4074(u8 *, s32);
    if ((*(u8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x38)))) + (6))) == 9) {
        func_800A4074(arg0, 9);
        return;
    }
    func_800A4074(arg0, 2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7D460/func_800A4074.s")

void func_800A4160(s32 arg0) 
{
}
/* extern */

void func_800A4168(u8 *arg0) {
    s32 func_800A4074(u8 *, s32);
    (*(s32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x38)))) + (0x3C))) = 0;
    func_800A4074(arg0, 2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7D460/func_800A4190.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7D460/func_800A4338.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7D460/func_800A4878.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7D460/func_800A4978.s")

void func_800A4A14(s32 arg0) { if (func_800A4338() != 0) return; func_800A4190(arg0); func_800A4878(arg0); }

void func_800A4A4C(s32 arg0)
{
    func_800A4190();
    func_800A4878(arg0);
}
#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7D460/func_800A4A74.s")

void func_800A4AD0(PlayerState *arg0) { if (_ncbaspline_entrypoint_8(func_800A4CA8(arg0))) func_800A3F14(arg0, 2); }

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E7D460/func_800A4B08.s")

/* extern */

f32 *func_800A4C48(PlayerState *arg0) {
    f32 *func_800A93F8(s32);
    return func_800A93F8(arg0->unk184);
}

/* extern */

int func_800A4C68(void *arg0) {
    s32 func_800A940C(s32);
    return func_800A940C((*(s32 *)((s8 *)(arg0) + (0x184))));
}

/* extern */

s16 *func_800A4C88(void *arg0) {
    s16 *func_800A93E4(s32);
    return func_800A93E4((*(s32 *)((s8 *)(arg0) + (0x184))));
}

/* extern */

PlayerState *func_800A4CA8(PlayerState *arg0) {
    PlayerState *func_80110014(s16 *);
    PlayerState *var_v1;
    s16 *temp_v0;

    temp_v0 = func_800A4C88(arg0);
    if (temp_v0 != NULL) {
        var_v1 = func_80110014(temp_v0);
    } else {
        var_v1 = NULL;
    }
    return var_v1;
}

/* extern */

void func_800A4CE8(PlayerState *arg0, s32 arg1) {
    s32 func_800CA7E4(f32 *, s32);
    func_800CA7E4(func_800A4C48(arg0), arg1);
}

/* extern */

void func_800A4D14(PlayerState *arg0, s32 arg1) {
    s32 func_800CA9D8(f32 *, s32);
    func_800CA9D8(func_800A4C48(arg0), arg1);
}

s32 func_800A4D40(void *arg0) {
    s32 func_8010FAE4(s16 *);
    return func_8010FAE4(func_800A4C88(arg0)) == 2;
}

/* extern */

void func_800A4D6C(u8 *arg0, f32 arg1, f32 arg2) {
    s32 func_800A3BA8(s32, s32);
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x38)))) + (0x2C))) = arg1;
    (*(f32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x38)))) + (0x30))) = arg2;
    func_800A3BA8((s32)arg0, 1);
}

void func_800A4DA4(PlayerState *arg0, s32 arg1) {
    u8 temp_v0;

    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x38)))) + (0))) = (s8) arg1;
    temp_v0 = (*(u8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x38)))) + (6)));
    if ((temp_v0 != 4) && (temp_v0 != 5)) {
        func_800A3F14((s32)arg0, 1);
        func_800A3B78(arg0, arg1);
    }
}

void func_800A4DFC(PlayerState *arg0, s32 arg1) {
    func_800A3F14((s32)arg0, 3);
    func_800A3B78(arg0, arg1);
}

void func_800A4E30(PlayerState *arg0) {
    u8 temp_v0;

    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x38)))) + (0))) = 0;
    temp_v0 = (*(u8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x38)))) + (6)));
    if ((temp_v0 != 4) && (temp_v0 != 5)) {
        func_800A3F14((s32)arg0, 2);
    }
}

void func_800A4E74(s32 arg0)
{
    func_800A3F14(arg0,0x5);
}

s32 func_800A4E94(void *arg0) { func_800A3F14((s32)arg0, 9); func_80110BF0(func_800A4CA8(arg0)); }

s32 func_800A4EC8(void *arg0) { func_800A3F14((s32)arg0, 2); func_80110C2C(func_800A4CA8(arg0)); }

/* extern */

void func_800A4EFC(void *arg0, f32 arg1) {
    s32 func_80090E30(PlayerState *);
    f32 mlAbsF(f32);
    f32 sp34[3];
    s32 var_a3;
    f32 *var_v1;
    s32 var_v0;
    void *temp_v0;

    if (arg0 != NULL) {
        temp_v0 = (*(void **)((s8 *)(arg0) + (0x38)));
        if ((*(u8 *)((s8 *)(temp_v0) + (4))) == 0) {
            sp34[0] = mlAbsF(arg1 - (f32) (*(s32 *)((s8 *)(temp_v0) + (8))));
            sp34[1] = mlAbsF(arg1 - (f32) (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x38)))) + (0x14))));
            sp34[2] = mlAbsF(arg1 - (f32) (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x38)))) + (0x20))));
            var_a3 = 0;
            var_v0 = 1;
            var_v1 = &sp34[1];
            do {
                if (*var_v1 < sp34[var_a3]) {
                    var_a3 = var_v0;
                }
                var_v0 += 1;
                var_v1++;
            } while (var_v0 != 3);
            func_800A3D78(arg0, var_a3 + 1, func_80090E30(arg0));
        }
    }
}

/* extern */

void func_800A5004(void *arg0) {
    s32 func_800A4E94(void *);
    s32 func_800CA334();
    if ((*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x38)))) + (0x3C))) == 0) {
        (*(s32 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x38)))) + (0x3C))) = func_800CA334();
        func_800A4E94(arg0);
    }
}

/* extern */

void func_800A5044(u8 *arg0) {
    s32 func_800A4EC8(void *);
    s32 func_800CA364(s32);
    if ((*(s32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x38)))) + (0x3C))) != 0) {
        func_800A4EC8(arg0);
        func_800CA364((*(s32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x38)))) + (0x3C))));
        (*(s32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x38)))) + (0x3C))) = 0;
    }
}

s32 func_800A5090(void *arg0) {
    return *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 56) + 60);
}

void func_800A509C(void *arg0) {
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0x38)))) + (0x3B))) = 1;
}
