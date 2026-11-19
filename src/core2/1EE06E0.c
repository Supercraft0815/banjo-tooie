#include "common.h"
#include "core2/baddie_states.h"
#include "shared_actor_effects.inc"
void func_80106DF0(void) {
    void * freelist_new(s32 element_size, s32 capacity);
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
    BtIntPtr freelist_defrag(BtIntPtr);
    extern s32 D_80136F00;
    if (D_80136F00 != 0) {
        D_80136F00 = freelist_defrag(D_80136F00);
    }
}

/* extern */

BtIntPtr func_80106E88(Actor *arg0) {
    void *func_80100368(void *);
    BtIntPtr func_80107320(Actor *);
    BtIntPtr var_v1;
    s32 sp1C;

    sp1C = 0;
    var_v1 = sp1C;
    if ((BT_DATA_FIELD(((ActorData *)func_80100368(arg0))->unk44, *(s32 *)((s8 *)func_80100368(arg0) + 0x44)) != 0) && (arg0->pad6C_21 != 0)) {
        var_v1 = func_80107320(arg0);
    }
    return var_v1;
}

void func_80106EE0(void *arg0) {
    void freelist_erase(void *list, s32 index);
    extern s32 D_80136F00;
    struct {
        u8 pad[0x94];
        BT_BITFIELD_ORDER(u32 unk94_0 : 2, u32 unk94_12 : 20);
        u32 index : 10;
        BT_BITFIELD_ORDER(u32 unk94_12 : 20, u32 unk94_0 : 2);
    } *entry = arg0;

    if (entry->index != 0) {
        freelist_erase(D_80136F00, entry->index);
        entry->index = 0;
    }
}

/* extern */

void *func_80106F30(void *arg0) {
    extern s32 D_80136F00;
    void * freelist_at(void *list, s32 index);
    struct {
        u8 pad[0x94];
        BT_BITFIELD_ORDER(u32 unk94_0 : 2, u32 unk94_12 : 20);
        u32 index : 10;
        BT_BITFIELD_ORDER(u32 unk94_12 : 20, u32 unk94_0 : 2);
    } *entry = arg0;
    if (entry->index == 0) {
        return NULL;
    }
    return freelist_at(D_80136F00, entry->index);
}    typedef struct { u8 pad0[0x4]; s16 unk4; u8 pad6[0x4]; s16 unkA; } Obj1EE06E0_func_80106F70_entry; /* offsets.py genstruct: fields from raw offsets on entry; rename once understood */

void func_80106F70(Actor *arg0) {
    s32 func_80107070(Actor *, u32);
    s32 func_80107784(void *, void *);
    s32 func_80107858(Actor *, u8 *);
    s32 func_801078AC(BtIntPtr, f32 *);
    s32 _subaddiefade_entrypoint_0(Actor *);
    void func_800EE88C(f32 *, s16 *);
    s32 func_8010CAC0(f32 *, u32);
    void *entry;
    f32 position[3];

    entry = func_80106F30(arg0);
    switch (((Obj1EE06E0_func_80106F70_entry *)entry)->unkA) {
    case 1:
        if (func_80107858(arg0, entry)) {
            func_80107070(arg0, 4);
        }
        break;
    case 2:
        if (!_subaddiefade_entrypoint_0(arg0)) {
            func_80107070(arg0, 3);
        }
        break;
    case 3:
        if (func_801078AC((BtIntPtr)arg0, entry)) {
            func_800EE88C(position, &((Obj1EE06E0_func_80106F70_entry *)entry)->unk4);
            if (!func_8010CAC0(position, 200)) {
                func_80107070(arg0, 4);
            }
        }
        break;
    case 4:
        if (func_80107784(arg0, entry)) {
            func_80107070(arg0, 0);
        }
        break;
    }
}    typedef struct { u8 pad0[0xA]; s16 unkA; } Obj1EE06E0_func_80107070_sp24; /* offsets.py genstruct: fields from raw offsets on sp24; rename once understood */ typedef struct { u8 pad0[0xA]; s16 unkA; } Obj1EE06E0_func_80107070_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

s32 func_80107070(Actor *arg0, u32 arg1) {
    void * func_80106F30(void *arg0);
    void func_801073AC(BtIntPtr arg0, s32 arg1);
    s32 func_801073F8(BtIntPtr arg0, s32 arg1, s32 arg2);
    void func_80107448(void *arg0, f32 *arg1);
    void func_8010754C(void *arg0, void *arg1);
    void func_801075E4(Actor *arg0, void *arg1);
    void func_80107750(BtIntPtr arg0, BtIntPtr arg1);
    void _subaddieaudioquick_entrypoint_2();
    void func_80103110(void *arg0, s32 arg1);
    extern s16 D_801244F0[6];
    f32 *sp24;
    f32 *temp_v0;

    temp_v0 = func_80106F30(arg0);
    sp24 = temp_v0;
    if (temp_v0 == NULL) {
        return 0;
    }
    if (arg1 == (((Obj1EE06E0_func_80107070_temp_v0 *)temp_v0)->unkA)) {
        return 1;
    }
    switch (arg1) {
    case 0:
        func_80103110(arg0, 1);
        break;
    case 1:
        _subaddieaudioquick_entrypoint_2(arg0, (u8 *)arg0 ->position, D_801244F0, arg1);
        if (func_801073F8((BtIntPtr) arg0, 1, 1) == 0) {
            func_80103110(arg0, 0);
        }
        func_80107750((BtIntPtr) arg0, (BtIntPtr) sp24);
        break;
    case 2:
        if (func_801073F8((BtIntPtr) arg0, 2, 1) == 0) {
            func_80103110(arg0, 0);
        }
        func_80107750((BtIntPtr) arg0, (BtIntPtr) sp24);
        break;
    case 3:
        if (func_801073F8((BtIntPtr) arg0, 3, 1) == 0) {
            func_80103110(arg0, 0);
        }
        func_80107448(arg0, sp24);
        break;
    case 4:
        if (func_801073F8((BtIntPtr) arg0, 4, 1) == 0) {
            func_80103110(arg0, 0);
        }
        func_8010754C(arg0, sp24);
        func_801075E4(arg0, sp24);
        break;
    }
    func_801073AC((BtIntPtr) arg0, (s32) arg1);
    (((Obj1EE06E0_func_80107070_sp24 *)sp24)->unkA) = (s16) arg1;
    return 1;
}

/* extern */

void func_80107200(void *arg0) {
    void func_800EE940(s16 dst[3], f32 src[3]);
    struct {
        f32 timer;
        s16 position[3];
        s16 state;
        BT_BITFIELD_ORDER(u32 flags : 12, u32 pad : 8);
        u32 value : 12;
        BT_BITFIELD_ORDER(u32 pad : 8, u32 flags : 12);
        s16 unk10;
        s16 rotation;
    } *entry;
    struct {
        u8 pad0[4];
        f32 position[3];
        u8 pad10[0x34];
        f32 rotation[3];
        u8 pad50[0x20];
        BT_BITFIELD_ORDER(u32 flags : 7, u32 pad73 : 4);
        BT_BITFIELD_ORDER(u32 pad70 : 15, u32 value : 6);
        BT_BITFIELD_ORDER(u32 value : 6, u32 pad70 : 15);
        BT_BITFIELD_ORDER(u32 pad73 : 4, u32 flags : 7);
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
}    typedef struct { u8 pad0[0xA]; s16 unkA; } Obj1EE06E0_func_801072A8_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

s32 func_801072A8(void *arg0) {
    void *temp_v0;

    temp_v0 = func_80106F30(arg0);
    if (temp_v0 == NULL) {
        return 0;
    }
    return (((Obj1EE06E0_func_801072A8_temp_v0 *)temp_v0)->unkA) != 0;
}    typedef struct { u8 pad0[0xA]; s16 unkA; } Obj1EE06E0_func_801072E4_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

/* extern */

s32 func_801072E4(void *arg0) {
    void *temp_v0;

    temp_v0 = func_80106F30(arg0);
    if (temp_v0 == NULL) {
        return 0;
    }
    return (((Obj1EE06E0_func_801072E4_temp_v0 *)temp_v0)->unkA) == 4;
}

BtIntPtr func_80107320(Actor *arg0) {
    struct IndexField {
        u8 pad[0x94];
        BT_BITFIELD_ORDER(u16 upper : 2, u16 lower : 4);
        u16 index : 10;
        BT_BITFIELD_ORDER(u16 lower : 4, u16 upper : 2);
    };
    extern s32 D_80136F00;
    s32 sp1C;
    void *sp18;
    sp1C = 0;
    sp18 = freelist_next(&D_80136F00, &sp1C);
    bzero(sp18, 0x18);
    ((struct IndexField *)arg0)->index = sp1C;
    func_80107200(arg0);
    return (BtIntPtr) sp18;
}

/* extern */

#ifdef BT_NATIVE
BaddieState *func_80107388(Actor *actor) {
    void *func_80100368(void *);
    ActorData *descriptor = func_80100368(actor);
    return (BaddieState *)descriptor->unk44;
}
#else
s32 func_80107388(void) {
    void *func_80100368();
    return (*(s32 *)((s8 *)(func_80100368()) + (0x44)));
}
#endif

/* extern */

#ifdef BT_NATIVE
void func_801073AC(BtIntPtr arg0, s32 arg1) {
    intptr_t func_8010108C(Actor *, s32, uintptr_t);
    void func_80102424(Actor *, s32);
    Actor *actor = (Actor *)arg0;
    func_80102424(actor, func_80107388(actor)[arg1].state);
    func_8010108C(actor, 0x8F, arg1);
}
#else
void func_801073AC(s32 arg0, s32 arg1) { s32 func_8010108C(); s32 func_80102424(s32, s32); s32 func_80107388(void); func_80102424(arg0, *(s16 *)(func_80107388() + arg1 * 4)); func_8010108C(arg0, 0x8F, arg1); }
#endif

#ifdef BT_NATIVE
s32 func_801073F8(BtIntPtr arg0, s32 arg1, s32 arg2) {
    return (func_80107388((Actor *)arg0)[arg1].flags & arg2) != 0;
}
#else
s32 func_801073F8(s32 arg0, s32 arg1, s32 arg2) { s32 func_80107388(); s32 var_v1; if ((*(s16 *)((s8 *)(func_80107388(arg0) + (arg1 * 4)) + 2)) & arg2) { var_v1 = 1; } else { var_v1 = 0; } return var_v1; }
#endif

void func_80107448(void *arg0, f32 *arg1) {
    void func_80104580(Actor *);
    void func_8010754C(void *, void *);
    void func_8010A570(Actor *);
    void func_8010A624(void ***);
    f32 func_80107A80(void);
    struct ActorFields {
        u8 pad0[0x5C];
        u8 colors[3];
        u8 pad5F[5];
        BT_BITFIELD_ORDER(u32 flag31 : 1, u32 pad64_0 : 16);
        BT_BITFIELD_ORDER(u32 flag30 : 1, u32 flag16 : 1);
        BT_BITFIELD_ORDER(u32 pad64_25 : 5, u32 pad64_17 : 7);
        u32 flag24 : 1;
        BT_BITFIELD_ORDER(u32 pad64_17 : 7, u32 pad64_25 : 5);
        BT_BITFIELD_ORDER(u32 flag16 : 1, u32 flag30 : 1);
        BT_BITFIELD_ORDER(u32 pad64_0 : 16, u32 flag31 : 1);
        u8 pad68[8];
        BT_BITFIELD_ORDER(u32 pad70_17 : 15, u32 pad70_0 : 16);
        u32 flag70_16 : 1;
        BT_BITFIELD_ORDER(u32 pad70_0 : 16, u32 pad70_17 : 15);
        BT_BITFIELD_ORDER(u32 pad74_25 : 7, char : 0);
        BT_BITFIELD_ORDER(u32 flag74_24 : 1, u32 pad74_0 : 20);
        BT_BITFIELD_ORDER(u32 pad74_21 : 3, u32 flag74_20 : 1);
        BT_BITFIELD_ORDER(u32 flag74_20 : 1, u32 pad74_21 : 3);
        BT_BITFIELD_ORDER(u32 pad74_0 : 20, u32 flag74_24 : 1; u32 pad74_25 : 7);
        u8 pad78;
        u8 flags79;
        u8 pad7A[2];
        BT_BITFIELD_ORDER(u32 pad7C_13 : 19, u32 pad7C_0 : 12);
        u32 flag7C_12 : 1;
        BT_BITFIELD_ORDER(u32 pad7C_0 : 12, u32 pad7C_13 : 19);
    } *actor = arg0;
    s32 i;

    if (func_801073F8(arg0, 3, 4) == 0) {
        actor->flag74_20 = 0;
        actor->flag16 = actor->flag74_20;
        actor->flag7C_12 = 0;
    }
    actor->flag74_24 = 0;
    actor->flag24 = 0;
    actor->flags79 = (u8)(actor->flags79 & 0xFFFC);
    actor->flag31 = 0;
    actor->flag30 = 0;
    actor->flag70_16 = 0;
    func_8010A570(arg0);
    func_8010A624(arg0);
    func_80104580(arg0);
    func_8010754C(arg0, arg1);
    for (i = 0; i != 3; i++) {
        actor->colors[i] = 0x63;
    }
    *arg1 = func_80107A80();
}

void func_8010754C(void *arg0, void *arg1) {
    struct ActorFields {
        u8 pad0[4];
        f32 position[3];
        u8 pad10[0x38];
        f32 rotation;
        u8 pad4C[0x24];
        BT_BITFIELD_ORDER(u32 flags : 7, u32 pad73 : 4);
        BT_BITFIELD_ORDER(u32 pad70 : 15, u32 index : 6);
        BT_BITFIELD_ORDER(u32 index : 6, u32 pad70 : 15);
        BT_BITFIELD_ORDER(u32 pad73 : 4, u32 flags : 7);
    };
    struct EntryFields {
        u8 pad0[4];
        s16 position[3];
        u16 padA;
        BT_BITFIELD_ORDER(u32 flags : 12, u32 padF : 8);
        u32 index : 12;
        BT_BITFIELD_ORDER(u32 padF : 8, u32 flags : 12);
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

void func_801075E4(Actor *arg0, void *arg1) {
    struct ActorFlags {
        u8 pad0[0x64];
        BT_BITFIELD_ORDER(u32 flag31 : 1, u32 pad29 : 30);
        u32 flag30 : 1;
        BT_BITFIELD_ORDER(u32 pad29 : 30, u32 flag31 : 1);
        u8 pad68[8];
        BT_BITFIELD_ORDER(u32 pad70 : 15, u32 pad71 : 16);
        u32 flag16 : 1;
        BT_BITFIELD_ORDER(u32 pad71 : 16, u32 pad70 : 15);
        BT_BITFIELD_ORDER(u32 pad74 : 11, char : 0);
        BT_BITFIELD_ORDER(u32 flag20 : 1, u32 pad75 : 20);
        BT_BITFIELD_ORDER(u32 pad75 : 20, u32 flag20 : 1; u32 pad74 : 11);
    };
    struct Settings {
        u8 pad0[0x1C];
        f32 unk1C;
    };
    struct Entry {
        f32 unk0;
        u8 pad4[0x10];
        s16 unk14;
    };
    void *func_80100368(void *);
    s32 func_80102FA0(Actor *, s32);
    void _subaddiefade_entrypoint_2(void *arg0);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    extern s16 D_801244FC[6];
    void *settings;
    struct ActorFlags *flags = (void *)arg0;
    struct Entry *entry = arg1;

    settings = func_80100368(arg0);
    func_8010754C(arg0, arg1);
    if (func_801073F8((BtIntPtr)arg0, 3, 4) == 0) {
        _subaddiefade_entrypoint_2(arg0);
        arg0->unk64_16 = 1;
        if (((struct Settings *)settings)->unk1C != 0.0f) {
            flags->flag20 = 1;
        } else {
            flags->flag20 = 0;
        }
        entry->unk0 = 0.0;
    } else {
        entry->unk0 = 1.8f;
    }
    flags->flag31 = func_80102FA0(settings, 0x80000004);
    flags->flag30 = func_80102FA0(settings, 0x80000008);
    arg0->unk14 |= 0x80000;
    flags->flag16 = func_80102FA0(settings, 0x80001000);
    entry->unk14 = 0;
    if (func_801073F8((BtIntPtr)arg0, 4, 2) == 0) {
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_801244FC);
    }
}

/* extern */

void func_80107750(BtIntPtr arg0, BtIntPtr arg1) {
    s32 _subaddiefade_entrypoint_5();
    void func_8010A570(Actor *);
    void func_8010A624(void ***);
    _subaddiefade_entrypoint_5();
    func_8010A570(arg0);
    func_8010A624(arg0);
}

s32 _subaddiefade_entrypoint_0(Actor *);

s32 func_80107784(void *arg0, void *arg1) {
    struct Entry {
        f32 timer;
        u8 pad4[6];
        s16 unkA;
        u8 padC[8];
        u8 unk14[1];
    };
    s32 func_800D90A4(f32 *);
    s32 func_80102F74(Unk80132ED0 *, s32);
    s32 func_801078DC(Actor *, u8 *);
    void func_8010A590(Actor *);
    void func_8010A63C(Actor *);
    struct Entry *entry = arg1;
    Actor *actor = arg0;

    if (func_801073F8((BtIntPtr)arg0, entry->unkA, 2) == 0) {
        func_801078DC(arg0, entry->unk14);
    }
    if (_subaddiefade_entrypoint_0(arg0) == 0xFF && func_800D90A4(&entry->timer) != 0) {
        actor->unk64_24 = func_80102F74(arg0, 0x80000001);
        if (func_80102F74(arg0, 0x80000002) == 0) {
            func_8010A590(arg0);
        }
        if (func_80102F74(arg0, 0x800) != 0) {
            func_8010A63C(arg0);
        }
        return 1;
    }
    return 0;
}    typedef struct { u8 pad0[0xA]; s16 unkA; } Obj1EE06E0_arg1; /* offsets.py genstruct: fields from raw offsets on arg1; rename once understood */

/* extern */

s32 func_80107858(Actor *arg0, u8 *arg1) {
    s32 func_801073F8(BtIntPtr, s32, s32);
    s32 func_801078DC(Actor *, u8 *);
    if (func_801073F8((BtIntPtr)arg0, (((Obj1EE06E0_arg1 *)arg1)->unkA), 2) == 0) {
        func_801078DC(arg0, arg1 + 0x14);
    }
    if (_subaddiefade_entrypoint_0(arg0) == 0) {
        return 1;
    }
    return 0;
}

/* extern */

s32 func_801078AC(BtIntPtr arg0, f32 *arg1) {
    s32 func_800D90A4(f32 *);
    if (func_800D90A4(arg1) != 0) {
        return 1;
    }
    return 0;
}

s32 func_801078DC(Actor *arg0, u8 *arg1) {
    s32 _subaddievolume_entrypoint_0(Actor *, f32 *, s32, s32, s32 *);
    BtIntPtr func_800B5BE4(s32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s16[]);
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    void func_800EF368(f32 *, f32);
    void func_800EFB24(void *, void *, void *);
    f32 func_80103F38(Actor *, f32 *);
    extern s16 D_80124508[23];
    extern s16 D_80124538[5];
    f32 points[20][3];
    f32 position[3];
    s32 count;
    s32 i;
    BtIntPtr effect;
    s32 index;
    f32 delta[3];
    f32 end[3];

    index = *(s16 *)arg1;
    count = _subaddievolume_entrypoint_0(arg0, points[0], 3, 20, &index);
    *(s16 *)arg1 = index;
    if (count > 0) {
        func_80103F38(arg0, position);
        effect = func_800B5BE4(0x11);
        func_800BABB8(effect, NULL, NULL, 1.0f, D_80124508);
    }
    for (i = 0; i < count; i++) {
        func_800EFB24(delta, points[i], position);
        func_800EF368(delta, 40.0f);
        func_800EF04C(points[i], delta);
        func_800EFB24(delta, position, points[i]);
        func_800EF334(delta, -1.0f);
        func_800EE780(end, points[i], delta);
        func_800BABB8(effect, points[i], end, 1.0f, D_80124538);
    }
    return count >= 0;
}

f32 func_80107A80(void) {
    extern u8 D_8012762C;
    switch (D_8012762C) {
    case 19:
        return 80 * 0.5f;
    case 16:
        return 60 * 0.5f;
    case 15:
        return 56 * 0.5f;
    case 18:
        return 52 * 0.5f;
    case 20:
        return 48 * 0.5f;
    case 21:
        return 44 * 0.5f;
    case 22:
        return 40 * 0.5f;
    case 23:
        return 36 * 0.5f;
    case 24:
        return 33 * 0.5f;
    case 25:
        return 28 * 0.5f;
    case 26:
        return 60 * 0.5f;
    default:
        return 60 * 0.5f;
    }
}

s32 func_80107B70(BtIntPtr arg0, f32 *arg1) {
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
    f32 _gspropmarker_entrypoint_3(void *context);
    extern f32 D_80136F10;
    s32 sp20[4];
    s32 pad[2];

    if (_gccubesearch_entrypoint_9(0x4F0, sp20, 4) > 0) {
        D_80136F10 = _gspropmarker_entrypoint_3(sp20[0]);
        return;
    }
    D_80136F10 = 1.0f;
}    typedef struct { f32 unk0; } Obj1EE06E0_D_80136F10; /* offsets.py genstruct: fields from raw offsets on &D_80136F10; rename once understood */

f32 func_80107C00(void) {
    extern f32 D_80136F10;
    return *&((Obj1EE06E0_D_80136F10 *)&D_80136F10)->unk0;
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
s32 D_80136F00 BT_DATA(4, bss_core2bss2_2_music_tail, 0x14E0);
f32 D_80136F10 BT_DATA(4, bss_core2bss2_2_music_tail, 0x14F0);
#endif
