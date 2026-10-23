#include "common.h"

f32 func_80800000_idbounce(void) {
    s32 func_8008FD48();

    switch (func_8008FD48()) {
        case 0x11:
            return 0.1f;
        case 0xA:
            return 0.7f;
        case 0xB:
            return 0.4f;
        default:
            return 1.0f;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/bounce/idbounce_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/bounce/idbounce_entrypoint_1.s")

void idbounce_entrypoint_2(u8 *arg0, u32 arg1, u8 *arg2, s32 arg3, u8 *arg4) {
    s32 func_800F54E4(void);
    void func_800F83E4(s32, f32);
    extern s32 D_8013546C;
    f32 temp_f30;
    f32 originY;
    f32 sp74;
    f32 temp_f24;
    f32 sp6C;
    f32 sp68;
    f32 *temp_v0;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f26;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 var_f12;
    f32 var_f20;
    f32 var_f20_2;
    s32 temp_s5;
    u32 temp_s6;
    u32 var_s1;
    s32 temp_v0_2;
    u32 temp_s3;
    u8 *var_s2;
    u8 *var_s4;

    temp_f30 = (*(f32 *)((s8 *)(arg4) + (4)));
    originY = (*(f32 *)((s8 *)(arg4) + (8)));
    sp74 = (*(f32 *)((s8 *)(arg4) + (0xC)));
    temp_f24 = (*(f32 *)((s8 *)(arg4) + (0x20)));
    sp6C = (*(f32 *)((s8 *)(arg4) + (0x40)));
    var_s1 = arg1;
    sp68 = (*(f32 *)((s8 *)(arg4) + (0x44)));
    var_s2 = arg2;
    var_s4 = arg0;
    temp_s5 = (*(u8 *)((s8 *)(arg4) + (0))) == 2;
    temp_s6 = (arg3 * 0x10) + arg1;
    temp_f26 = (*(f32 *)((s8 *)(arg4) + (0x1C)));
    temp_s3 = (u32)((u8 *)&D_8013546C + 0x14);
    while (var_s1 < temp_s6) {
            var_f12 = (*(f32 *)((s8 *)(arg4) + (0x38)));
            var_f20 = 0.0f;
            if (*(u8 *)(temp_s3 + 1) != 0) {
                temp_f0 = (f32) (*(s16 *)((s8 *)(var_s2) + (0))) - temp_f30;
                temp_f2 = (f32) (*(s16 *)((s8 *)(var_s2) + (4))) - sp74;
                temp_f0_2 = sqrtf((temp_f0 * temp_f0) + (temp_f2 * temp_f2));
                temp_f2_2 = (*(f32 *)((s8 *)(arg4) + (0x34)));
                var_f12 = temp_f0_2;
                if (temp_f0_2 < temp_f2_2) {
                    var_f20 = 0.0f - temp_f24;
                } else if (temp_f0_2 < (*(f32 *)((s8 *)(arg4) + (0x38)))) {
                    var_f20 -= temp_f24 * (1.0f - ((temp_f0_2 - temp_f2_2) * (*(f32 *)((s8 *)(arg4) + (0x3C)))));
                }
            }
            temp_v0 = (*(f32 **)((s8 *)(arg4) + (0x28)));
            temp_f0_3 = *temp_v0;
            var_f20 += ((f32) ((*(s16 *)((s8 *)(var_s4) + (2))) - (*(s16 *)((s8 *)(var_s2) + (2)))) * sp6C) - (temp_f0_3 * sp68);
            *temp_v0 += var_f20 * temp_f26;
            (*(s16 *)((s8 *)(var_s1) + (2))) = (s16) (s32) ((*(*(f32 **)((s8 *)(arg4) + (0x28))) * temp_f26) + (f32) (*(s16 *)((s8 *)(var_s2) + (2))));
            if (*(u8 *)(temp_s3 + 1) != 0) {
                temp_v0_2 = *(u8 *)(temp_s3 + 2);
                if ((temp_v0_2 == 0) && (var_f12 < (*(f32 *)((s8 *)(arg4) + (0x34))))) {
                    temp_f0_4 = *(*(f32 **)((s8 *)(arg4) + (0x28)));
                    if (temp_f0_4 < 0.0f) {
                        var_f20_2 = temp_f0_4 / (*(f32 *)((s8 *)(arg4) + (0x50)));
                    } else {
                        temp_f2_3 = (*(f32 *)((s8 *)(arg4) + (0x50)));
                        if (temp_f0_4 < (10.0f * temp_f2_3)) {
                            var_f20_2 = -1.0f;
                        } else if ((*(f32 *)((s8 *)(arg4) + (0x48))) < temp_f0_4) {
                            temp_f0_4 *= (*(f32 *)((s8 *)(arg4) + (0x4C)));
                            var_f20_2 = temp_f0_4;
                        } else {
                            var_f20_2 = temp_f0_4 / temp_f2_3;
                        }
                    }
                    if (temp_v0_2 == 0) {
                        if (var_f20_2 > 2000.0f) {
                            var_f20_2 = 2000.0f;
                        }
                        func_800F83E4(func_800F54E4(), var_f20_2);
                        *(u8 *)(temp_s3 + 2) = 1U;
                    }
                }
            }
            var_s4 += 0x10;
            if ((temp_s5 != 0) && ((*(s16 *)((s8 *)(var_s1) + (2))) < 0)) {
                (*(s16 *)((s8 *)(var_s1) + (2))) = 0;
            }
            var_s1 += 0x10;
            var_s2 += 0x10;
            (*(f32 **)((s8 *)(arg4) + (0x28))) = (f32 *) ((*(f32 **)((s8 *)(arg4) + (0x28))) + 1);
    }
}

s32 *func_80800874_idbounce(s32 arg0) {
    extern s32 D_80800E50_idbounce[];
    s32 *var_v1 = D_80800E50_idbounce;
    while (-1 != *var_v1) {
        if (arg0 == *var_v1) {
            break;
        }
        var_v1 += 8;
    }
    return var_v1;
}

/* extern */

int func_808008B4_idbounce(void) {
    s32 func_800F54E4();
    s32 func_800F55FC(s32);
    s32 func_800F6C5C(s32);
    s32 sp1C;
    s32 temp_v0;

    temp_v0 = func_800F54E4();
    sp1C = temp_v0;
    if (func_800F6C5C(temp_v0) == 0) {
        return 0;
    }
    if (!(func_800F55FC(sp1C) & 0x8000)) {
        return 0;
    }
    return 1;
}

void idbounce_entrypoint_3(void *arg0) {
    void heap_free(void *);
    extern u8 D_80135480[];
    u8 *state;

    heap_free(*(void **)((u8 *)arg0 + 0x24));
    state = D_80135480;
    state[3]--;
}

void idbounce_entrypoint_4(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 *func_80800874_idbounce(s32 arg0);
    s16 _glidmake_entrypoint_3(s32, s32);
    void *heap_alloc(s32);
    s32 func_80106314(void);
    Actor *func_80106790(Unk80132ED0 *);
    void func_800EE7F8(f32 *, f32 *);
    s32 func_800EA05C(void);
    extern u8 D_80135480[];
    f32 *sp2C;
    s32 sp28;
    Actor *sp24;
    Actor *temp_v0;
    s32 map;
    u8 *counter;

    sp2C = func_80800874_idbounce(arg1);
    sp28 = _glidmake_entrypoint_3(arg2, arg3);
    *(f32 **)((u8 *)arg0 + 0x24) = heap_alloc(sp28 * 4);
    *(f32 **)((u8 *)arg0 + 0x2C) = *(f32 **)((u8 *)arg0 + 0x24) + sp28;
    *(f32 **)((u8 *)arg0 + 0x28) = *(f32 **)((u8 *)arg0 + 0x24);
    while (*(f32 **)((u8 *)arg0 + 0x28) < *(f32 **)((u8 *)arg0 + 0x2C)) {
        **(f32 **)((u8 *)arg0 + 0x28) = 0.0f;
        (*(f32 **)((u8 *)arg0 + 0x28))++;
    }
    *(f32 *)((u8 *)arg0 + 0x20) = 0.0f;
    *(f32 *)((u8 *)arg0 + 0x30) = -sp2C[1] / -2700.0f;
    *(f32 *)((u8 *)arg0 + 0x34) = sp2C[2];
    *(f32 *)((u8 *)arg0 + 0x38) = sp2C[3];
    *(f32 *)((u8 *)arg0 + 0x40) = sp2C[4];
    *(f32 *)((u8 *)arg0 + 0x44) = sp2C[5];
    *(f32 *)((u8 *)arg0 + 0x48) = sp2C[6];
    *(f32 *)((u8 *)arg0 + 0x4C) = sp2C[7];
    if (arg4 == 4) {
        temp_v0 = func_80106790(func_80106314());
        sp24 = temp_v0;
        *(f32 *)((u8 *)arg0 + 0x50) = 1.0f / temp_v0->scale;
        func_800EE7F8((f32 *)((u8 *)arg0 + 0x54), temp_v0->position);
        switch (sp24->unk6C_9) {
            case 0x34C:
                *(s8 *)arg0 = 2;
                break;
            case 0x47E:
            case 0x4C4:
            case 0x4C5:
            case 0x4C6:
            case 0x4C7:
            case 0x50B:
            case 0x50C:
            case 0x531:
                *(s8 *)arg0 = 3;
                break;
            default:
                *(s8 *)arg0 = 1;
                break;
        }
    } else {
        *(f32 *)((u8 *)arg0 + 0x5C) = 0.0f;
        *(f32 *)((u8 *)arg0 + 0x58) = 0.0f;
        *(f32 *)((u8 *)arg0 + 0x54) = 0.0f;
        map = func_800EA05C();
        if (map != 0xE2 && map != 0xE4 && map != 0xE5 && map != 0xF8 && map != 0x138) {
            *(f32 *)((u8 *)arg0 + 0x50) = 0.0f;
            *(s8 *)arg0 = 0;
        } else {
            *(s8 *)arg0 = 3;
            *(f32 *)((u8 *)arg0 + 0x50) = 1.0f;
        }
    }
    if (*(f32 *)((u8 *)arg0 + 0x50)) {
        *(f32 *)((u8 *)arg0 + 0x30) *= *(f32 *)((u8 *)arg0 + 0x50);
        *(f32 *)((u8 *)arg0 + 0x34) *= *(f32 *)((u8 *)arg0 + 0x50);
        *(f32 *)((u8 *)arg0 + 0x38) *= *(f32 *)((u8 *)arg0 + 0x50);
        *(f32 *)((u8 *)arg0 + 0x40) *= *(f32 *)((u8 *)arg0 + 0x50);
        *(f32 *)((u8 *)arg0 + 0x44) *= *(f32 *)((u8 *)arg0 + 0x50);
        *(f32 *)((u8 *)arg0 + 0x48) *= *(f32 *)((u8 *)arg0 + 0x50);
        *(f32 *)((u8 *)arg0 + 0x4C) /= *(f32 *)((u8 *)arg0 + 0x50);
    }
    counter = D_80135480;
    *(f32 *)((u8 *)arg0 + 0x3C) = 1.0f / (sp2C[3] - sp2C[2]);
    counter[3]++;
}

void idbounce_entrypoint_5(void *arg0, s32 arg1, s32 arg2) {
    f32 func_800D8FF8(void);
    s32 func_800F54E4(void);
    void func_800F5A00(s32, f32 *);
    void func_800F5D70(s32, f32 *);
    void func_800EF3DC(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    s32 _glid_entrypoint_0(s32, s32, s32 *, s32);
    s32 _glid_entrypoint_1(s32, s32, s32 *, s32);
    extern s32 _idbounce_entrypoint_0;
    extern s32 _idbounce_entrypoint_1;
    extern s32 _idbounce_entrypoint_2;
    extern s32 D_8013546C;
    f32 sp34[3];

    *(f32 *)((u8 *)arg0 + 0x1C) = func_800D8FF8();
    func_800F5A00(func_800F54E4(), (f32 *)((u8 *)arg0 + 4));
    func_800EF3DC((f32 *)((u8 *)arg0 + 4), (f32 *)((u8 *)arg0 + 0x54));
    if (*(f32 *)((u8 *)arg0 + 0x50) != 0.0f) {
        func_800EF334((f32 *)((u8 *)arg0 + 4), *(f32 *)((u8 *)arg0 + 0x50));
    }
    *(f32 *)((u8 *)arg0 + 0x20) =
        -*(f32 *)((u8 *)arg0 + 0x30) * func_80800000_idbounce() * -2700.0f;
    if (*((u8 *)&D_8013546C + 0x14) != 0) {
        func_800F5D70(func_800F54E4(), sp34);
        *(f32 *)((u8 *)arg0 + 0x20) -=
            (*(f32 *)((u8 *)arg0 + 0x30) * func_80800000_idbounce() * sp34[1]) /
            *(f32 *)((u8 *)arg0 + 0x1C);
    }
    *(s32 *)((u8 *)arg0 + 0x28) = *(s32 *)((u8 *)arg0 + 0x24);
    switch (*(u8 *)arg0) {
        case 0:
            _glid_entrypoint_0(arg1, arg2, &_idbounce_entrypoint_0, (s32)arg0);
            break;
        case 1:
            _glid_entrypoint_0(arg1, arg2, &_idbounce_entrypoint_1, (s32)arg0);
            break;
        case 2:
        case 3:
            _glid_entrypoint_1(arg1, arg2, &_idbounce_entrypoint_2, (s32)arg0);
            break;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/id/bounce/idbounce_entrypoint_6.s")

void idbounce_entrypoint_7(void) {
    s32 func_800F54E4(void);
    void func_800F83E4(s32, f32);
    extern u8 D_80135480[];
    if (D_80135480[1] != 0 && D_80135480[2] == 0) {
        func_800F83E4(func_800F54E4(), -1.0f);
    }
}
