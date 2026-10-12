#include "common.h"

void func_80106DF0(void) {
    s32 freelist_new(s32, s32);
    extern s32 D_80136F00;
    D_80136F00 = freelist_new(0x18, 12);
}

void func_80106E18(void) {
    s32 freelist_free(s32);
    extern s32 D_80136F00;
    if (D_80136F00 != 0) {
        freelist_free(D_80136F00);
        D_80136F00 = 0;
    }
}

void func_80106E50(void) {
    s32 freelist_defrag(s32);
    extern s32 D_80136F00;
    if (D_80136F00 != 0) {
        D_80136F00 = freelist_defrag(D_80136F00);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_80106E88.s")

void func_80106EE0(void *arg0) {
    s32 freelist_erase(s32, s32);
    extern s32 D_80136F00;
    struct {
        u8 pad[0x94];
        u32 unk94_0 : 2;
        u32 index : 10;
        u32 unk94_12 : 20;
    } *entry = arg0;

    if (entry->index != 0) {
        freelist_erase(D_80136F00, entry->index);
        entry->index = 0;
    }
}

/* extern */

void *func_80106F30(void *arg0) {
    extern s32 D_80136F00;
    void *freelist_at(s32, s32);
    struct {
        u8 pad[0x94];
        u32 unk94_0 : 2;
        u32 index : 10;
        u32 unk94_12 : 20;
    } *entry = arg0;
    if (entry->index == 0) {
        return NULL;
    }
    return freelist_at(D_80136F00, entry->index);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_80106F70.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_80107070.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_80107200.s")

/* extern */

s32 func_801072A8(void) {
    void *func_80106F30();
    void *temp_v0;

    temp_v0 = func_80106F30();
    if (temp_v0 == NULL) {
        return 0;
    }
    return (*(s16 *)((s8 *)(temp_v0) + (0xA))) != 0;
}

/* extern */

s32 func_801072E4(void) {
    void *func_80106F30();
    void *temp_v0;

    temp_v0 = func_80106F30();
    if (temp_v0 == NULL) {
        return 0;
    }
    return (*(s16 *)((s8 *)(temp_v0) + (0xA))) == 4;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_80107320.s")

/* extern */

s32 func_80107388(void) {
    void *func_80100368();
    return (*(s32 *)((s8 *)(func_80100368()) + (0x44)));
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_801073AC.s")

s32 func_801073F8(s32 arg0, s32 arg1, s32 arg2) { s32 func_80107388(); s32 var_v1; if ((*(s16 *)((s8 *)(func_80107388(arg0) + (arg1 * 4)) + 2)) & arg2) { var_v1 = 1; } else { var_v1 = 0; } return var_v1; }

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_80107448.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_8010754C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_801075E4.s")

/* extern */

void func_80107750(s32 arg0, s32 arg1) {
    s32 _subaddiefade_entrypoint_5();
    s32 func_8010A570(s32);
    s32 func_8010A624(s32);
    _subaddiefade_entrypoint_5();
    func_8010A570(arg0);
    func_8010A624(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_80107784.s")

/* extern */

s32 func_80107858(Actor *arg0, u8 *arg1) {
    s32 func_801073F8(s32, s32, s32);
    s32 func_801078DC(Actor *, u8 *);
    if (func_801073F8((s32)arg0, (*(s16 *)((s8 *)(arg1) + (0xA))), 2) == 0) {
        func_801078DC(arg0, arg1 + 0x14);
    }
    if (_subaddiefade_entrypoint_0(arg0) == 0) {
        return 1;
    }
    return 0;
}

/* extern */

s32 func_801078AC(s32 arg0, s32 arg1) {
    s32 func_800D90A4(s32);
    if (func_800D90A4(arg1) != 0) {
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_801078DC.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_80107A80.s")

s32 func_80107B70(s32 arg0, f32 *arg1) {
    void func_800EE88C(f32 dst[3], s16 src[3]);
    void *func_80106F30();
    u8 *temp_v0;

    temp_v0 = func_80106F30(arg0);
    if (temp_v0 == NULL) {
        return 0;
    }
    func_800EE88C(arg1, temp_v0 + 4);
    return 1;
}

void func_80107BB0(void) {
    s32 _gccubesearch_entrypoint_9(s32, s32 *, s32);
    f32 _gspropmarker_entrypoint_3(s32);
    extern f32 D_80136F10;
    s32 sp20[4];
    s32 pad[2];

    if (_gccubesearch_entrypoint_9(0x4F0, sp20, 4) > 0) {
        D_80136F10 = _gspropmarker_entrypoint_3(sp20[0]);
        return;
    }
    D_80136F10 = 1.0f;
}

f32 func_80107C00(void) {
    extern f32 D_80136F10;
    return *(f32 *)((u8 *)&D_80136F10 + 0);
}
