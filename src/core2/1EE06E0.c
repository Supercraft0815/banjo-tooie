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

/* extern */

s32 func_80106E88(Actor *arg0) {
    void *func_80100368(void *);
    s32 func_80107320(Actor *);
    s32 var_v1;
    s32 sp1C;

    sp1C = 0;
    var_v1 = sp1C;
    if (((*(s32 *)((s8 *)(func_80100368(arg0)) + (0x44))) != 0) && (arg0->pad6C_21 != 0)) {
        var_v1 = func_80107320(arg0);
    }
    return var_v1;
}

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

/* extern */

void func_80107200(void *arg0) {
    void func_800EE940(s16 dst[3], f32 src[3]);
    struct {
        f32 timer;
        s16 position[3];
        s16 state;
        u32 flags : 12;
        u32 value : 12;
        u32 pad : 8;
        s16 unk10;
        s16 rotation;
    } *entry;
    struct {
        u8 pad0[4];
        f32 position[3];
        u8 pad10[0x34];
        f32 rotation[3];
        u8 pad50[0x20];
        u32 flags : 7;
        u32 pad70 : 15;
        u32 value : 6;
        u32 pad73 : 4;
    } *actor = arg0;

    entry = func_80106F30(arg0);
    if (entry != NULL) {
        func_800EE940(entry->position, actor->position);
        entry->value = actor->value;
        entry->flags = actor->flags;
        entry->rotation = (s32)actor->rotation[1];
        entry->state = 0;
        entry->timer = 0.0f;
    }
}

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

s32 func_80107320(Actor *arg0) {
    struct IndexField {
        u8 pad[0x94];
        u16 upper : 2;
        u16 index : 10;
        u16 lower : 4;
    };
    extern s32 D_80136F00;
    s32 sp1C;
    void *sp18;
    sp1C = 0;
    sp18 = freelist_next(&D_80136F00, &sp1C);
    bzero(sp18, 0x18);
    ((struct IndexField *)arg0)->index = sp1C;
    func_80107200(arg0);
    return (s32) sp18;
}

/* extern */

s32 func_80107388(void) {
    void *func_80100368();
    return (*(s32 *)((s8 *)(func_80100368()) + (0x44)));
}

/* extern */

void func_801073AC(s32 arg0, s32 arg1) { s32 func_8010108C(); s32 func_80102424(s32, s32); s32 func_80107388(void); func_80102424(arg0, *(s16 *)(func_80107388() + arg1 * 4)); func_8010108C(arg0, 0x8F, arg1); }

s32 func_801073F8(s32 arg0, s32 arg1, s32 arg2) { s32 func_80107388(); s32 var_v1; if ((*(s16 *)((s8 *)(func_80107388(arg0) + (arg1 * 4)) + 2)) & arg2) { var_v1 = 1; } else { var_v1 = 0; } return var_v1; }

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EE06E0/func_80107448.s")

void func_8010754C(void *arg0, void *arg1) {
    struct ActorFields {
        u8 pad0[4];
        f32 position[3];
        u8 pad10[0x38];
        f32 rotation;
        u8 pad4C[0x24];
        u32 flags : 7;
        u32 pad70 : 15;
        u32 index : 6;
        u32 pad73 : 4;
    };
    struct EntryFields {
        u8 pad0[4];
        s16 position[3];
        u16 padA;
        u32 flags : 12;
        u32 index : 12;
        u32 padF : 8;
        s16 pad10;
        s16 rotation;
    };
    void func_800EE88C(f32 *, s16 *);
    void func_80103014(u8 *);
    struct ActorFields *actor = arg0;
    struct EntryFields *entry = arg1;

    func_800EE88C(actor->position, entry->position);
    actor->index = entry->index;
    actor->flags = entry->flags;
    actor->rotation = entry->rotation;
    func_80103014((u8 *)actor);
}

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
