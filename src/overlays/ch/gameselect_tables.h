#include "core2/actor_animation_entry.h"
#include "gc/newoption_state.h"

typedef struct {
    s16 model, value;
} GameSelectModel;
typedef struct {
    s16 text, id, value;
} SelectEntry;
#if defined(BT_NATIVE) && !defined(BT_ILP32)
#define GAME_SELECT_OPTION_DISPATCH_PARAMS(a0, a1, a2) Actor *a0, void *a1, s32 a2
#define GAME_SELECT_ROW6_OPEN_PARAMS(a0, a1) Actor *a0, void *a1, s32 item, s32 event
#define GAME_SELECT_ROW5_OPEN_PARAMS(a0, a1) Actor *a0, void *a1, s32 item, s32 event
#define GAME_SELECT_ROW6_SELECT_PARAMS(a0, a1, a2) Actor *a0, void *a1, s32 a2
#define GAME_SELECT_ROW5_SELECT_PARAMS(a0, a1, a2) Actor *a0, void *a1, s32 a2
#define GAME_SELECT_ROW6_EVENT5_PARAMS(a0, a1, a2) Actor *a0, void *a1, s32 a2
#define GAME_SELECT_ROW5_EVENT5_PARAMS(a0, a1, a2) Actor *a0, void *a1, s32 a2
#define GAME_SELECT_ROW6_EVENT_PARAMS(a0, a1, a2) Actor *a0, void *a1, s32 a2, s32 event
#define GAME_SELECT_ROW6_EVENT3_PARAMS(a0, a1, a2) u8 *a0, void *a1, s32 a2
#define GAME_SELECT_ROW5_EVENT_PARAMS(a0, a1, a2) Actor *a0, void *a1, s32 a2, s32 event
#define GAME_SELECT_ROW6_OPTION_SET(a0, a1, a2) BtIntPtr a0, s32 a1, s32 a2
#define GAME_SELECT_ROW5_OPTION_SET(a0, a1, a2) BtIntPtr a0, s32 a1, s32 a2
#else
#define GAME_SELECT_OPTION_DISPATCH_PARAMS(a0, a1, a2) Actor *a0, BtIntPtr a1, s32 a2
#define GAME_SELECT_ROW6_OPEN_PARAMS(a0, a1) s32 a0, s32 a1
#define GAME_SELECT_ROW5_OPEN_PARAMS(a0, a1) Actor *a0, BtIntPtr a1
#define GAME_SELECT_ROW6_SELECT_PARAMS(a0, a1, a2) Actor *a0, s32 a1, s32 a2
#define GAME_SELECT_ROW5_SELECT_PARAMS(a0, a1, a2) Actor *a0, OptionState *a1, s32 a2
#define GAME_SELECT_ROW6_EVENT5_PARAMS(a0, a1, a2) Actor *a0, s32 a1, s32 a2
#define GAME_SELECT_ROW5_EVENT5_PARAMS(a0, a1, a2) Actor *a0, s32 a1, s32 a2
#define GAME_SELECT_ROW6_EVENT_PARAMS(a0, a1, a2) s32 a0, s32 a1, s32 a2
#define GAME_SELECT_ROW6_EVENT3_PARAMS(a0, a1, a2) u8 *a0, s32 a1, s32 a2
#define GAME_SELECT_ROW5_EVENT_PARAMS(a0, a1, a2) s32 a0, s32 a1, s32 a2
#define GAME_SELECT_ROW6_OPTION_SET(a0, a1, a2) s32 a0, s32 a1, s32 a2
#define GAME_SELECT_ROW5_OPTION_SET(a0, a1, a2) BtIntPtr a0, s32 a1, s32 a2
#endif
typedef void (*GameSelectEventCallback)(
    BT_PARAM_OR_VOID(BT_PASS2(Actor *, BT_PASS2(void *, BT_PASS2(s32, s32)))));
typedef s32 (*GameSelectInit)(Actor *);
typedef void (*GameSelectExit)(BT_PARAM_OR_VOID(void *));
typedef s32 (*GameSelectChange)(Actor *, s32, s32 *);
typedef void (*GameSelectOpen)(Actor *, void *, s32, s32);
#if defined(BT_NATIVE) && !defined(BT_ILP32)
typedef s32 (*GameSelectSelect)(Actor *, void *, s32);
typedef void (*GameSelectEvent5)(Actor *, void *, s32);
#else
typedef s32 (*GameSelectSelect)(Actor *, BtIntPtr, s32);
typedef void (*GameSelectEvent5)(Actor *, s32, s32);
#endif
typedef void (*GameSelectEvent3)(Actor *, void *, s32);
typedef void (*GameSelectGetOption)(Actor *, s32 *);
typedef struct {
    GameSelectInit init;
    GameSelectExit exit;
    GameSelectChange change;
    GameSelectOpen open;
    GameSelectSelect select;
    GameSelectEvent5 onEvent5;
    GameSelectEvent3 onEvent3;
    GameSelectEventCallback onEvent2;
    GameSelectOpen onEventFF, onEventFC;
    GameSelectGetOption getOption;
    GameSelectEventCallback onEvent7, onEvent6;
} GameSelectState;
typedef struct {
    s32 id;
    void (*callback)(void *);
} GameSelectAction;
typedef struct {
    GameSelectAction enter[6], resume[5];
    s16 color[4];
} GameSelectActions;
typedef struct {
    u8 count, first, option;
    s8 firstOffset;
    s16 title, description;
    u8 *icons;
} GameSelectMenu;

extern GameSelectModel D_80807DB0_chgameselect[8];
extern GameSelectState D_80807DD0_chgameselect[10];
extern GameSelectModel D_808080A8_chgameselect[8];
extern ActorData D_80807FD8_chgameselect;
extern ActorData D_80808038_chgameselect;
extern ActorData D_808080C8_chgameselect;
extern ActorData D_80808298_chgameselect;
extern ActorData D_808082E0_chgameselect;
extern ActorData D_80808328_chgameselect;
extern ActorData D_808084B4_chgameselect;
extern ActorData D_80808504_chgameselect;
extern ActorAnimationEntry D_80808020_chgameselect[3];
extern ActorAnimationEntry D_80808080_chgameselect[5];
extern f32 D_80808110_chgameselect[8][11];
extern u16 D_80808270_chgameselect[8];
extern u8 D_80808280_chgameselect[8];
extern f32 D_80808288_chgameselect[4];
extern GameSelectActions D_80808370_chgameselect;
extern s16 D_808083D0_chgameselect[4];
extern s16 D_808083D8_chgameselect[4];
extern s16 D_808083E0_chgameselect[4];
extern s16 D_808084FC_chgameselect[4];
extern SelectEntry D_808083E8_chgameselect[3];
extern u8 D_808083FC_chgameselect[3];
extern u8 D_80808400_chgameselect[3];
extern u8 D_80808404_chgameselect[4];
extern u8 D_80808408_chgameselect[4];
extern u8 D_8080840C_chgameselect[5];
extern u8 D_80808414_chgameselect[5];
extern u8 D_8080841C_chgameselect[8];
extern GameSelectMenu D_80808424_chgameselect[12];
