#include "common.h"

/* extern */

typedef struct { u8 pad0[0x8]; f32 unk8; u8 padC[0x20]; f32 unk2C; } Objarchgrill_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */ void func_80800000_chlavaarchgrill(void *arg0) {
    s32 func_800DA7A8(s32, s32, s32, void *);
    void func_8010A800(void **arg0, s32 arg1);
    (((Objarchgrill_arg0 *)arg0)->unk2C) = (f32) (((Objarchgrill_arg0 *)arg0)->unk8);
    func_800DA7A8(0xA1A, 0, 3, arg0);
    func_8010A800(arg0, 2);
}
typedef struct { u8 id; u16 event; u8 value; u8 state; u8 nextState; u8 animation; u8 action; u8 flag; } GrillEntry;
s32 func_80800044_chlavaarchgrill(Actor *arg0, s32 arg1, s32 arg2) {











    typedef struct {
    f32 timer;
    }
    GrillData;
    extern GrillEntry D_80800610_chlavaarchgrill[12];
    s32 _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    s32 _capod_entrypoint_14(void);
    s32 func_800DA564(s32, s32);
    s32 func_800DA7A8();
    s32 func_80101180(s32, s32, BtIntPtr);
    void func_80101FDC(Actor *actor,u32 state);
    s32 result[3];
    s32 flag;
    s32 count;
    GrillEntry *entry;
    s16 animation;
    Actor *x;
     flag = func_800DA564(0xA1A, 3);
    count = 12;
    for (entry = D_80800610_chlavaarchgrill;
    entry < D_80800610_chlavaarchgrill + count;
    entry++) {
    if (entry->id != arg0->unk74_7) {
    continue;
    }
    if (arg1 != entry->event) {
    continue;
    }
    if (entry->state == arg0->unk70_10 && arg2 == entry->value && flag == entry->flag) {
    result[0] = 1;
    x = arg0;
    if (flag) { arg0 = (Actor *)((BtIntPtr)arg0 * 1); }
    func_80101FDC(x, entry->nextState);
    goto apply_animation;
apply_animation:
    animation = entry->animation;
    if (animation != 0) {
    if (entry->value != 0) {
    _capod_entrypoint_14();
    _capod_entrypoint_13(arg0->unk0, NULL, entry->animation, 0x2010);
    result[0] = 4;
    }
    else {
    _capod_entrypoint_13(arg0->unk0, NULL, animation, 0x10);
    }
    }
    switch (entry->action) {
    case 1: ((GrillData *)arg0->actorData)->timer = 0.75f;
    break;
    case 2: func_800DA7A8(0xA1A, 1, 3);
    func_80101180(0x288, 0x61, 0);
    break;
    case 3: ((GrillData *)arg0->actorData)->timer = 0.75f;
    func_800DA7A8(0xA1A, 2, 3);
    break;
    case 4: func_800DA7A8(0xA1A, 3, 3);
    func_80101180(0x288, 0x5D, 0);
    break;
    case 5: ((GrillData *)arg0->actorData)->timer = 0.75f;
    func_800DA7A8(0xA1A, 4, 3);
    break;
    }
    return result[0];
    }
    }
    return 0;
    }

/* extern */

void func_80800288_chlavaarchgrill(u8 *arg0, s32 arg1) {
    s32 func_800D9078(BtIntPtr);
    void func_80101FDC(Actor *actor,u32 state);
    if (func_800D9078(arg0 + 0x18) != 0) {
        func_80101FDC(arg0, arg1);
        (((Actor *)arg0)->unk58) = 2.0f;
    }
}

void func_808002D0_chlavaarchgrill(Actor *arg0) {
    s32 func_800D9078();
    void func_80101FDC(Actor *actor,u32 state);
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    extern u32 D_80800688_chlavaarchgrill[];
    extern u32 D_80800698_chlavaarchgrill[];
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    s32 sp30;

    switch (arg0->unk70_10) {
    case 2:
        func_80800288_chlavaarchgrill((u8 *)arg0, 3);
        break;
    case 3:
        sp3C = func_800D9078(&arg0->unk58);
        arg0->position[1] = func_800F12D4(arg0->unk58, 0.0f, 2.0f, ((f32 *)arg0->actorData)[5] + ((190.0f * arg0->scale) / 2), ((f32 *)arg0->actorData)[5]);
        _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, D_80800688_chlavaarchgrill);
        if (sp3C) {
            func_80101FDC(arg0, 4);
        }
        break;
    case 5:
        func_80800288_chlavaarchgrill((u8 *)arg0, 6);
        break;
    case 6:
        sp38 = func_800D9078(&arg0->unk58);
        arg0->position[1] = func_800F12D4(arg0->unk58, 0.0f, 2.0f, ((f32 *)arg0->actorData)[5] + (190.0f * arg0->scale), ((f32 *)arg0->actorData)[5] + ((190.0f * arg0->scale) / 2));
        _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, D_80800688_chlavaarchgrill);
        if (sp38) {
            func_80101FDC(arg0, 7);
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800698_chlavaarchgrill);
        }
        break;
    case 8:
        func_80800288_chlavaarchgrill((u8 *)arg0, 9);
        break;
    case 9:
        sp34 = func_800D9078(&arg0->unk58);
        arg0->position[1] = func_800F12D4(arg0->unk58, 2.0f, 0.0f, ((f32 *)arg0->actorData)[5] + ((190.0f * arg0->scale) / 2), ((f32 *)arg0->actorData)[5]);
        _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, D_80800688_chlavaarchgrill);
        if (sp34) {
            func_80101FDC(arg0, 1);
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_80800698_chlavaarchgrill);
        }
        break;
    case 10:
        if (func_800D9078((f32 *)arg0->actorData)) {
            func_80101FDC(arg0, 11);
            arg0->unk58 = 4.0f;
        }
        break;
    case 11:
        sp30 = func_800D9078(&arg0->unk58);
        arg0->position[1] = func_800F12D4(arg0->unk58, 0.0f, 4.0f, ((f32 *)arg0->actorData)[5] + (190.0f * arg0->scale), ((f32 *)arg0->actorData)[5]);
        _subaddieaudioloop_entrypoint_4(arg0, arg0->position, 1, D_80800688_chlavaarchgrill);
        if (sp30) {
            func_80101FDC(arg0, 12);
        }
        break;
    }
}

OSThread *chlavaarchgrill_entrypoint_0(void)
{
    extern ActorData D_808006A4_chlavaarchgrill[];

    return (OSThread *) D_808006A4_chlavaarchgrill;
}
/* data_to_c.py: from asm/data/overlays/ch/lava/archgrill.data.s */
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
GrillEntry D_80800610_chlavaarchgrill [ 12 ] BT_DATA(4, overlays_ch_lava_archgrill, 0x0) = { { 0x32, 0xB, 0x20, 7, 7, 0x1E, 2, 0 }, { 0x32, 0xB, 0x3F, 7, 7, 0x1E, 2, 0 }, { 0x33, 0xB, 0x1E, 7, 7, 0x1C, 4, 2 }, { 0x32, 0x63, 0, 1, 2, 0x20, 1, 0 }, { 0x32, 0x64, 0, 4, 8, 0x3F, 1, 0 }, { 0x32, 0x61, 0, 4, 5, 0x3F, 1, 0 }, { 0x33, 0x61, 0, 1, 2, 0, 3, 1 }, { 0x33, 0x61, 0, 1, 2, 0x1E, 1, 2 }, { 0x33, 0x62, 0, 4, 8, 0x40, 1, 2 }, { 0x33, 0x5D, 0, 4, 5, 0x40, 1, 2 }, { 0x33, 0xB, 0x40, 7, 7, 0x1C, 4, 2 }, { 0x34, 0x5D, 0, 1, 0xA, 0, 5, 3 } };
u32 D_80800688_chlavaarchgrill [4] BT_DATA(4, overlays_ch_lava_archgrill, 0x78) = { 0x130507, 0x180002, 0xA008C, 0 };
u32 D_80800698_chlavaarchgrill [3] BT_DATA(4, overlays_ch_lava_archgrill, 0x88) = { 0x1304C7, 0x180002, 0 };
ActorData D_808006A4_chlavaarchgrill [1] BT_DATA(4, overlays_ch_lava_archgrill, 0x94) = { { 172, 648, 2264, 1, 0, (void (*)(struct Actor *))func_808002D0_chlavaarchgrill, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 2048, 0, 0, 0, 0, (void (*)(struct Actor *))func_80800000_chlavaarchgrill, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 2, (void (*)(struct Actor *, long, long))func_80800044_chlavaarchgrill, 0 } };
