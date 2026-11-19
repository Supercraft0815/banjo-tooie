#ifndef __GC_NEWOPTION_STATE_H__
#define __GC_NEWOPTION_STATE_H__

#include "common.h"

#if defined(BT_NATIVE) && !defined(BT_ILP32)
typedef void (*OptionStateCallback)(void *context, void *optionState, s32 selected, s32 event);
typedef struct {
	u8 *box;
	u8 *boxes[29];
	u32 *text;
	OptionStateCallback callback;
	void *context;
} OptionStateNativePointers;
typedef struct {
	u8 data[0x260];
	OptionStateNativePointers native;
} OptionState;
_Static_assert(__builtin_offsetof(OptionState, native) == 0x260, "OptionState LP64 sidecar offset");
_Static_assert(sizeof(OptionStateNativePointers) == 0x108, "OptionState LP64 pointers");
_Static_assert(sizeof(OptionState) == 0x368, "OptionState LP64 extent");

static inline u8 *optionstate_native_box(void *state) { return ((OptionState *)state)->native.box; }
static inline void optionstate_native_set_box(void *state, u8 *box) { ((OptionState *)state)->native.box = box; }
static inline u8 *optionstate_native_item_box(void *state, s32 index) { return ((OptionState *)state)->native.boxes[index]; }
static inline s32 optionstate_native_item_box_index(void *state, const void *slot) { return (s32)(((const u8 *)slot - ((const u8 *)state + 0x3C)) / 4); }
static inline u8 *optionstate_native_item_box_slot(void *state, const void *slot) { return optionstate_native_item_box(state, optionstate_native_item_box_index(state, slot)); }
static inline void optionstate_native_set_item_box(void *state, s32 index, u8 *box) { ((OptionState *)state)->native.boxes[index] = box; }
static inline void optionstate_native_set_item_box_slot(void *state, const void *slot, u8 *box) { optionstate_native_set_item_box(state, optionstate_native_item_box_index(state, slot), box); }
static inline u32 *optionstate_native_text(void *state) { return ((OptionState *)state)->native.text; }
static inline void optionstate_native_set_text(void *state, u32 *text) { ((OptionState *)state)->native.text = text; }
static inline OptionStateCallback optionstate_native_callback(void *state) { return ((OptionState *)state)->native.callback; }
static inline void optionstate_native_set_callback(void *state, OptionStateCallback callback) { ((OptionState *)state)->native.callback = callback; }
static inline void *optionstate_native_context(void *state) { return ((OptionState *)state)->native.context; }
static inline void optionstate_native_set_context(void *state, void *context) { ((OptionState *)state)->native.context = context; }
#else
typedef struct {
	u8 data[0x260];
} OptionState;
#endif


#endif
