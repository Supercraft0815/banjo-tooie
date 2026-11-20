#ifndef __GC_DIALOG_STATE_H__
#define __GC_DIALOG_STATE_H__
#include "common.h"

#ifdef BT_NATIVE
typedef struct {
    s16 unk0; s16 unk2; f32 vec[3]; s32 unk10; s16 unk14; u16 pad16;
    s32 unk18;
    s32 unk1C; s32 unk20; s32 unk24;
    s32 unk28;
} GcDialogRequest;

typedef struct {
    u8 pad0[0x100];
    s32 unk100;
    s32 unk104[2]; s32 unk10C[2];
    u8 unk114[2];
    u8 unk116[2];
    s16 unk118[2];
    union {
        struct { BT_BITFIELD_ORDER(u8 mode:2; u8 rest:4; u8 state:2;, u8 state:2; u8 rest:4; u8 mode:2;); };
        struct { BT_BITFIELD_ORDER(u8 a:2; u8 c:4; u8 b:2;, u8 b:2; u8 c:4; u8 a:2;); };
        struct { u8 unused:2; u8 busy:1; u8 spare:5; };
    } unk11C[2];
    u8 pad11E[2];
    s32 unk120[2];
    s16 unk128; s16 unk12A;
    s32 unk12C;
    u8 pad130[0x28];
    s8 unk158;
    s8 unk159;
    s16 unk15A;
    union {
        u32 flags15C;
        /* The guest stores words big-endian. A little-endian host uses the byte order of its word bitfields. */
        struct {
#ifdef BT_NATIVE_LE_MEMORY
            BT_BITFIELD_ORDER(u8 status15C; u8 count15D; u8 flagBytes15E[2];,
                              u8 flagBytes15E[2]; u8 count15D; u8 status15C;);
#else
            u8 status15C; u8 count15D; u8 flagBytes15E[2];
#endif
        };
        struct {
            BT_BITFIELD_ORDER(u32 unused:16; u32 flag7:1; u32 flag6:1; u32 flag5:1; u32 flag4:1; u32 flag3:1; u32 flag2:1; u32 flag1:1; u32 flag0:1; u32 mode0:2; u32 mode1:2; u32 mode2:2; u32 mode3:2;,
                              u32 mode3:2; u32 mode2:2; u32 mode1:2; u32 mode0:2; u32 flag0:1; u32 flag1:1; u32 flag2:1; u32 flag3:1; u32 flag4:1; u32 flag5:1; u32 flag6:1; u32 flag7:1; u32 unused:16;);
        };
        struct {
            BT_BITFIELD_ORDER(u32 queueUnused:18; u32 queueRest:12; u32 queued:1; u32 decremented:1;,
                              u32 decremented:1; u32 queued:1; u32 queueRest:12; u32 queueUnused:18;);
        };
        struct {
            BT_BITFIELD_ORDER(u32 unused15c:8; u32 numBoxes:8; u32 top:1; u32 active:1; u32 unused1:2; u32 fast:1; u32 unused2:1; u32 low:2; u32 opened:2; u32 cleared:2; u32 pending:2; u32 other:2;,
                              u32 other:2; u32 pending:2; u32 cleared:2; u32 opened:2; u32 low:2; u32 unused2:1; u32 fast:1; u32 unused1:2; u32 active:1; u32 top:1; u32 numBoxes:8; u32 unused15c:8;);
        };
    };
    s8 unk160;
    union { u8 nibbleByte; struct { BT_BITFIELD_ORDER(u8 nibble1 : 4; u8 nibble0 : 4;, u8 nibble0 : 4; u8 nibble1 : 4;); }; };
    s16 unk162;
    s16 unk164;
    s8 unk166;
    u8 unk167;
    s32 unk168;
    s32 unk16C;
    s32 unk170;
    s32 unk174;
    s32 unk178;
    s32 unk17C;
    s8 unk180;
    u8 pad181[3];
    GcDialogRequest entries[4];
} GcDialogState;
#else
typedef struct {
    u8 pad0[0x100];
    s32 unk100;
    s32 unk104[2];
    s32 unk10C[2];
    s8 unk114[2];
    s8 unk116[2];
    s16 unk118[2];
    struct { BT_BITFIELD_ORDER(u8 a:2, u8 c : 4); u8 b:2; BT_BITFIELD_ORDER(u8 c:4, u8 a : 2); } unk11C[2];
    u8 pad11E[2];
    s32 unk120[2];
    u8 pad128[0x30];
    s8 unk158; s8 unk159; s16 unk15A;
    s8 unk15C; s8 unk15D;
    u16 flag7:1; u32 flag6:1; u32 flag5:1; u32 flag4:1; u8 flag3:1; u32 flag2:1; u32 flag1:1; u32 flag0:1;
    u8 mode3:2; u8 mode2:2; u8 mode1:2; u32 mode0:2;
    s8 unk160; u8 nibble1:4; u16 nibble0:4;
    s16 unk162; s16 unk164; s8 unk166; u8 pad167;
    s32 unk168; s32 unk16C; s32 unk170; s32 unk174; s32 unk178; s32 unk17C;
    s8 unk180; u8 pad181[3];
    struct { s16 unk0; s16 unk2; f32 vec[3]; s32 unk10; s16 unk14; u8 pad16[2]; s32 unk18; s32 unk1C; s32 unk20; s32 unk24; s32 unk28; } entries[4];
} GcDialogState;
#endif
#if defined(BT_NATIVE)
#if defined(BT_ILP32)
_Static_assert(sizeof(void *) == 4, "guest dialog pointer width");
#endif
_Static_assert(offsetof(GcDialogState, unk104) == 0x104, "guest dialog text list offset");
_Static_assert(offsetof(GcDialogState, unk10C) == 0x10C, "guest dialog text buffer offset");
_Static_assert(offsetof(GcDialogState, unk120) == 0x120, "guest dialog box offset");
_Static_assert(offsetof(GcDialogState, unk12C) == 0x12C, "guest dialog third box offset");
_Static_assert(offsetof(GcDialogState, unk168) == 0x168, "guest dialog caller offset");
_Static_assert(offsetof(GcDialogState, entries) == 0x184, "guest dialog request queue offset");
_Static_assert(sizeof(GcDialogRequest) == 0x2C, "guest dialog request size");
_Static_assert(sizeof(GcDialogState) == 0x234, "O32 dialog extent");
#endif
#ifdef BT_NATIVE
typedef struct {
    void *source; void *textEntries[2]; void *textData[2]; void *boxes[3]; void *caller;
    s32 (*callbacks[3])(void *, s16, s8);
    struct { void *actor; void *callback; void *callback2; void *callback3; } requests[4];
} GcDialogNativeState;
#if defined(BT_ILP32)
typedef struct { GcDialogState state; u8 padding[0xC]; } GcDialogStateStorage;
extern GcDialogStateStorage gc_dialog_state_storage __asm__("D_801288B0");
#define gc_dialog_state (gc_dialog_state_storage.state)
#else
extern GcDialogState gc_dialog_state;
#endif
#if !defined(BT_ILP32)
extern GcDialogNativeState gc_dialog_native_state;
#endif
static inline void *gc_dialog_text_entry(GcDialogState *s, s32 i) {
#if !defined(BT_ILP32)
    return gc_dialog_native_state.textEntries[i];
#else
    return (void *)(BtIntPtr)s->unk104[i];
#endif
}
static inline void gc_dialog_set_text_entry(GcDialogState *s, s32 i, void *p) {
#if !defined(BT_ILP32)
    gc_dialog_native_state.textEntries[i] = p;
#else
    s->unk104[i] = (s32)(BtIntPtr)p;
#endif
}
static inline void *gc_dialog_text_data(GcDialogState *s, s32 i) {
#if !defined(BT_ILP32)
    return gc_dialog_native_state.textData[i];
#else
    return (void *)(BtIntPtr)s->unk10C[i];
#endif
}
static inline void gc_dialog_set_text_data(GcDialogState *s, s32 i, void *p) {
#if !defined(BT_ILP32)
    gc_dialog_native_state.textData[i] = p;
#else
    s->unk10C[i] = (s32)(BtIntPtr)p;
#endif
}
static inline void *gc_dialog_box(GcDialogState *s, s32 i) {
#if !defined(BT_ILP32)
    return gc_dialog_native_state.boxes[i];
#else
    return (void *)(BtIntPtr)(i < 2 ? s->unk120[i] : s->unk12C);
#endif
}
static inline void gc_dialog_set_box(GcDialogState *s, s32 i, void *p) {
#if !defined(BT_ILP32)
    gc_dialog_native_state.boxes[i] = p;
#else
    if (i < 2) s->unk120[i] = (s32)(BtIntPtr)p; else s->unk12C = (s32)(BtIntPtr)p;
#endif
}
static inline void *gc_dialog_caller(GcDialogState *s) {
#if !defined(BT_ILP32)
    return gc_dialog_native_state.caller;
#else
    return (void *)(BtIntPtr)s->unk168;
#endif
}
static inline void gc_dialog_set_caller(GcDialogState *s, void *p) {
#if !defined(BT_ILP32)
    gc_dialog_native_state.caller = p;
#else
    s->unk168 = (s32)(BtIntPtr)p;
#endif
}
static inline s32 (*gc_dialog_callback(GcDialogState *s, s32 slot))(void *, s16, s8) {
#if !defined(BT_ILP32)
    (void)s; return gc_dialog_native_state.callbacks[slot];
#else
    s32 raw = slot == 0 ? s->unk170 : (slot == 1 ? s->unk174 : s->unk178);
    return (s32 (*)(void *, s16, s8))(BtIntPtr)raw;
#endif
}
static inline void gc_dialog_set_callback(GcDialogState *s, s32 slot, s32 (*p)(void *, s16, s8)) {
#if !defined(BT_ILP32)
    (void)s; gc_dialog_native_state.callbacks[slot] = p;
#else
    if (slot == 0) s->unk170 = (s32)(BtIntPtr)p;
    else if (slot == 1) s->unk174 = (s32)(BtIntPtr)p;
    else s->unk178 = (s32)(BtIntPtr)p;
#endif
}
static inline void *gc_dialog_source(GcDialogState *s) {
#if !defined(BT_ILP32)
    (void)s; return gc_dialog_native_state.source;
#else
    return (void *)(BtIntPtr)s->unk100;
#endif
}
static inline void gc_dialog_set_source(GcDialogState *s, void *p) {
#if !defined(BT_ILP32)
    (void)s; gc_dialog_native_state.source = p;
#else
    s->unk100 = (s32)(BtIntPtr)p;
#endif
}
static inline void *gc_dialog_request_actor(GcDialogState *s, s32 i) {
#if !defined(BT_ILP32)
    (void)s; return gc_dialog_native_state.requests[i].actor;
#else
    return (void *)(BtIntPtr)s->entries[i].unk10;
#endif
}
static inline void gc_dialog_set_request_actor(GcDialogState *s, s32 i, void *p) {
#if !defined(BT_ILP32)
    (void)s; gc_dialog_native_state.requests[i].actor = p;
#else
    s->entries[i].unk10 = (s32)(BtIntPtr)p;
#endif
}
static inline void *gc_dialog_request_callback(GcDialogState *s, s32 i, s32 slot) {
#if !defined(BT_ILP32)
    (void)s;
    if (slot == 0) return gc_dialog_native_state.requests[i].callback;
    if (slot == 1) return gc_dialog_native_state.requests[i].callback2;
    return gc_dialog_native_state.requests[i].callback3;
#else
    return (void *)(BtIntPtr)(slot == 0 ? s->entries[i].unk1C : (slot == 1 ? s->entries[i].unk20 : s->entries[i].unk24));
#endif
}
static inline void gc_dialog_set_request_callback(GcDialogState *s, s32 i, s32 slot, void *p) {
#if !defined(BT_ILP32)
    (void)s;
    if (slot == 0) gc_dialog_native_state.requests[i].callback = p;
    else if (slot == 1) gc_dialog_native_state.requests[i].callback2 = p;
    else gc_dialog_native_state.requests[i].callback3 = p;
#else
    if (slot == 0) s->entries[i].unk1C = (s32)(BtIntPtr)p;
    else if (slot == 1) s->entries[i].unk20 = (s32)(BtIntPtr)p;
    else s->entries[i].unk24 = (s32)(BtIntPtr)p;
#endif
}
#endif
#ifdef BT_NATIVE
#define GC_DIALOG_BASE BT_DATA_FIELD(&gc_dialog_state, &D_801288B0)
#define GC_DIALOG_FIELD(field, guest) BT_DATA_FIELD(gc_dialog_state.field, guest)
#ifdef BT_NATIVE
#define D_801288B0 (*((s32 *)&gc_dialog_state))
#define D_801288B8 (*((s32 *)((u8 *)&gc_dialog_state + 8)))
#define D_801289DC gc_dialog_box(&gc_dialog_state, 2)
#define D_80128A0C gc_dialog_state.flags15C
#define D_80128A11 gc_dialog_state.nibbleByte
#define D_80128A12 gc_dialog_state.unk162
#define D_80128A18 gc_dialog_caller(&gc_dialog_state)
#define D_80128A30 gc_dialog_state.unk180
#endif
#endif
#endif
