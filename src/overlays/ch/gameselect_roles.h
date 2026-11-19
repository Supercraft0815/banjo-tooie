#ifndef CH_GAMESELECT_ROLES_H
#define CH_GAMESELECT_ROLES_H

#ifdef BT_NATIVE
s32 _glsavegame_entrypoint_2(s32);
s32 _glsavegame_entrypoint_9(s32);
void func_800D37C0(s32);
void _gcstatusDll_entrypoint_5(s32);
#endif

#if defined(BT_NATIVE) && !defined(BT_ILP32)
#include "memory.h"

s32 _gcnewoption_entrypoint_38(u8 *, s32);
s32 _gcnewoption_entrypoint_39(u8 *);
void _glsavegame_entrypoint_0(void);
void _glsavegame_entrypoint_1(void);
s32 _glsavegame_entrypoint_3(void);
void func_800D37D4(void);
void func_800FC660(u32);

void _gczoombox_entrypoint_0(void *);
void _gczoombox_entrypoint_2(u8 *, BtIntPtr);
u32 _gczoombox_entrypoint_3(u8 *);
void _gczoombox_entrypoint_4(u8 *);
u8 *_gczoombox_entrypoint_5(s32, s32, s32, s32, BtIntPtr);
s32 _gczoombox_entrypoint_7(u8 *, s32, char **);
int _gczoombox_entrypoint_8(u8 *, char *);
void _gczoombox_entrypoint_9(void *);
void _gczoombox_entrypoint_10(void *);
void _gczoombox_entrypoint_11(void *);
void _gczoombox_entrypoint_12(void *);
void _gczoombox_entrypoint_15(void *);
void _gczoombox_entrypoint_16(void *);
void _gczoombox_entrypoint_17(void *);
void _gczoombox_entrypoint_18(void *);
void _gczoombox_entrypoint_19(void *);
void _gczoombox_entrypoint_26(void *, s32, f32, f32, s32);
void _gczoombox_entrypoint_27(void *, void *);
int _gczoombox_entrypoint_32(u8 *);
s32 _gczoombox_entrypoint_34(void *);

typedef struct {
    u8 *entries[4];
    char *texts[4];
    char *buffer;
    s16 winner;
    s16 initialized;
} GameSelectPanel;

u32 *func_80100074(Actor *, u32, u32);
static inline GameSelectPanel *game_select_panel_init(Actor *actor) {
    GameSelectPanel *panel = (GameSelectPanel *)func_80100074(actor, 0, sizeof(*panel));
    if (panel) *panel = (GameSelectPanel){0};
    return panel;
}

typedef struct GameSelectBoxData {
    u8 *box;
    u32 *strings;
    char first[0x40];
    char second[0x40];
} GameSelectBoxData;

static inline void game_select_box_init(Actor *actor, u8 *box) {
    actor->game_select_box_data = heap_alloc(sizeof(GameSelectBoxData));
    *actor->game_select_box_data = (GameSelectBoxData){ .box = box };
}

static inline void game_select_box_release(Actor *actor) {
    heap_free(actor->game_select_box_data);
    actor->game_select_box_data = NULL;
}

typedef struct GameSelectRootData {
    Unk80132ED0 *children[5];
} GameSelectRootData;

_Static_assert(sizeof(GameSelectRootData) <= 0x100, "GameSelect root allocation");
#define GAME_SELECT_LP64(native, original) native
#define GAME_SELECT_ORIGINAL(code)
#define GAME_SELECT_BOX(actor) ((actor)->game_select_box_data->box)
#define GAME_SELECT_FIRST_TEXT(actor) ((actor)->game_select_box_data->first)
#define GAME_SELECT_SECOND_TEXT(actor) ((actor)->game_select_box_data->second)

static inline void game_select_root_init(Actor *actor, GameSelectRootData *data) {
    actor->game_select_root_data = data;
    if (data) *data = (GameSelectRootData){0};
}

static inline GameSelectRootData *game_select_root_detach(Actor *actor) {
    GameSelectRootData *data = actor->game_select_root_data;
    actor->game_select_root_data = NULL;
    return data;
}

static inline Unk80132ED0 *game_select_root_child(Actor *actor, unsigned slot) {
    return actor->game_select_root_data ? actor->game_select_root_data->children[slot - 3] : NULL;
}

static inline void game_select_root_set_child(Actor *actor, unsigned slot, Unk80132ED0 *marker) {
    if (actor->game_select_root_data) actor->game_select_root_data->children[slot - 3] = marker;
}
#else
#define GAME_SELECT_LP64(native, original) original
#define GAME_SELECT_ORIGINAL(code) code
#define GAME_SELECT_BOX(actor) ((actor)->actorData[4])
#define GAME_SELECT_FIRST_TEXT(actor) ((char *)(actor)->actorData[3])
#define GAME_SELECT_SECOND_TEXT(actor) ((char *)(actor)->actorData[7])
#define game_select_root_child(actor, slot) ((Unk80132ED0 *)((Actor *)(actor))->actorData[slot])
#endif
#endif
