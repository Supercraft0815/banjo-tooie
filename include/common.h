#ifndef __COMMON_H__
#define __COMMON_H__

#include "types.h"
// A function address stored in a data table: a 32-bit word on the N64, pointer-sized natively.
#ifdef BT_NATIVE
typedef __UINTPTR_TYPE__ BtFnWord;
#else
typedef u32 BtFnWord;
#endif
// data_to_c.py definitions: natively module m's data stays one block at the N64 offsets o
// (bt-datagroup), so code that reaches a table through its neighbour still finds it (wasm build only)
#ifdef BT_ILP32
#define BT_DATA(n, m, o) __attribute__((aligned(n), section(".btgroup." #m "." #o)))
#else
#define BT_DATA(n, m, o)
#endif
#include "bt_native.h"
// Native code that only the LP64 build keeps (the ILP32 build compiles the original code instead),
// and `#include BT_LP64_HEADER("native_x.h")` for a native-only header inside an #ifdef BT_NATIVE.
#if defined(BT_NATIVE) && !defined(BT_ILP32)
#define BT_LP64_ONLY(code) code
#define BT_LP64_HEADER(h) h
#else
#define BT_LP64_ONLY(code)
#define BT_LP64_HEADER(h) "bt_empty.h"
#endif
#ifdef BT_NATIVE
#include "gameflags.h"
typedef struct ActorData *(*NativeActorFactory)(void);
typedef struct Prop Prop;
#endif

// This hacky structure allows coords to be accessed using
// coord->x, coord->y and coord->z, but also as
// coord->f[0], coord->f[1] and coord->f[2].
// In some places code only matches when using the float array.
typedef union {
    struct {
        f32 x;
        f32 y;
        f32 z;
    } pos;
    f32 f[3];
} Vec3f;

// size: unknown
typedef struct {
    /* 0x00 */ u32* unk0;
    /* 0x04 */ u32* unk4;
#ifdef BT_NATIVE
    union { u32 *unk8; OSThread *(*callback)(void); };
#else
    /* 0x08 */ u32* unk8;
#endif
#ifdef BT_NATIVE
    union { uintptr_t unkC; struct NativeMarkerCollision *(*collision)(void); };
#else
    /* 0x0C */ u32 unkC;
#endif
    /* 0x10 */ u32 unk10;
    /* 0x14 */ u16 unk14;
    /* 0x16 */ u16 unk16;
    /* 0x18 */ u32 unk18;
#ifdef BT_NATIVE
    union {
        struct { u32 unk1C, unk20; };
        struct { s16 cube_index; s16 model_center[3]; };
    };
#else
    /* 0x1C */ u32 unk1C;
    /* 0x20 */ u32 unk20;
#endif
    /* 0x24 */ u32 unk24;
    /* 0x28 */ u32 unk28;
    /* 0x2C */ u32 unk2C;
} Unk80132ED0;
#ifndef BT_NATIVE
typedef char bt_assert_marker[(sizeof(Unk80132ED0) == 0x30) ? 1 : -1];
#endif

// size: unknown
// Plain members sharing a word swap only where memory itself is little-endian; the ILP32 guest keeps
// N64 byte order, while its bitfields still follow BT_NATIVE_LITTLE_ENDIAN (clang allocates from bit 0).
#if defined(BT_NATIVE_LITTLE_ENDIAN) && !defined(BT_ILP32)
#define BT_NATIVE_LE_MEMORY 1
#endif
typedef struct Actor {
    /* 0x00 */ Unk80132ED0* unk0;
    /* 0x04 */ f32 position[3];
#ifdef BT_NATIVE
    union { u32 *pointerToSyscallEntry; NativeActorFactory factory; };
#else
    /* 0x10 */ u32* pointerToSyscallEntry;
#endif
    /* 0x14 */ u32 unk14;
    /* 0x18 */ u32 actorData[8]; //Cast this array to struct in actor
    /* 0x38 */ f32 scale;
    /* 0x3C */ Unk80132ED0 *unk3C;
#ifdef BT_NATIVE
    union { s32 pad40; Unk80132ED0 *parent_marker; };
#else
    /* 0x40 */ s32 pad40;
#endif
    /* 0x44 */ f32 rotation[3];
    /* 0x50 */ f32 unk50;
    /* 0x54 */ f32 unk54;
    /* 0x58 */ f32 unk58;
#ifdef BT_NATIVE
    union { struct { u8 pad5C, pad5D, pad5E; }; u8 health[3]; };
#else
    /* 0x5C */ u8 pad5C;
    /* 0x5D */ u8 pad5D;
    /* 0x5E */ u8 pad5E;
#endif
    /* 0x5F */ u8 unk5F;
#ifdef BT_NATIVE
    union {
        s32 pad60;
        struct {
#ifdef BT_NATIVE_LE_MEMORY
            s16 horizontal_radius; s16 vertex_handle;
#else
            s16 vertex_handle; s16 horizontal_radius;
#endif
        };
    };
#else
    /* 0x60 */ s32 pad60;
#endif
#ifdef BT_NATIVE
    union {
        u32 flags64;
        struct {
#endif
#ifdef BT_NATIVE_LITTLE_ENDIAN
            u32 unk64_0 : 16;
            u32 unk64_16 : 1;
            u32 unk64_17 : 1;
            u32 unk64_18 : 1;
            u32 unk64_19 : 1;
            u32 unk64_20 : 1;
            u32 unk64_21 : 1;
            u32 unk64_22 : 1;
            u32 unk64_23 : 1;
            u32 unk64_24 : 1;
            u32 unk64_25 : 1;
            u32 unk64_26 : 1;
            u32 unk64_27 : 1;
            u32 unk64_28 : 1;
            u32 unk64_29 : 1;
            u32 pad64_30 : 2;
#else
    /* 0x64 */ u32 pad64_30 : 2;
    /* 0x64 */ u32 unk64_29 : 1; // byte 0x64 & 0x20
    /* 0x64 */ u32 unk64_28 : 1;
    /* 0x64 */ u32 unk64_27 : 1;
    /* 0x64 */ u32 unk64_26 : 1;
    /* 0x64 */ u32 unk64_25 : 1;
    /* 0x64 */ u32 unk64_24 : 1;
    /* 0x64 */ u32 unk64_23 : 1;
    /* 0x64 */ u32 unk64_22 : 1;
    /* 0x64 */ u32 unk64_21 : 1;
    /* 0x64 */ u32 unk64_20 : 1;
    /* 0x64 */ u32 unk64_19 : 1; // flags & 0x80000
    /* 0x64 */ u32 unk64_18 : 1;
    /* 0x64 */ u32 unk64_17 : 1;
    /* 0x64 */ u32 unk64_16 : 1;
    /* 0x64 */ u32 unk64_0 : 16;
#endif
#ifdef BT_NATIVE
        };
    };
#endif
#ifdef BT_NATIVE
    union {
        s32 pad68;
        struct {
#ifdef BT_NATIVE_LE_MEMORY
            u16 model_radius; u16 center_radius;
#else
            u16 center_radius; u16 model_radius;
#endif
        };
    };
#else
    /* 0x68 */ s32 pad68;
#endif
#ifdef BT_NATIVE
    union {
        u32 flags6C;
        struct {
#endif
#ifdef BT_NATIVE_LITTLE_ENDIAN
            u32 unk6C_0 : 9;
            u32 unk6C_9 : 12;
            u32 pad6C_21 : 11;
#else
    /* 0x6C */ u32 pad6C_21 : 11;
    /* 0x6C */ u32 unk6C_9 : 12;
    /* 0x6C */ u32 unk6C_0 : 9; // if accessed directly: unk6C & 0x1FF, if assigned: ((u16)valueToAssign & 0x1FF) | (unk6E & 0xFE00);
#endif
#ifdef BT_NATIVE
        };
    };
#endif
#ifdef BT_NATIVE
    union {
        u32 flags70;
        struct {
#endif
#ifdef BT_NATIVE_LITTLE_ENDIAN
            u32 unk70_0 : 1;
            u32 pad70_1 : 9;
            u32 unk70_10 : 6;
            u32 pad70_16 : 9;
            u32 unk70_25 : 7;
#else
    /* 0x70 */ u32 unk70_25: 7; // unk70 >> 25
    /* 0x70 */ u32 pad70_16: 9;
    /* 0x70 */ u32 unk70_10: 6; // unk72 >> 10
    /* 0x70 */ u32 pad70_1: 9;
    /* 0x70 */ u32 unk70_0: 1; // unk70 & 1
#endif
#ifdef BT_NATIVE
        };
    };
#endif
#ifdef BT_NATIVE
    union {
        u32 flags74;
        struct {
#endif
#ifdef BT_NATIVE_LITTLE_ENDIAN
            u32 pad74_0 : 7;
            u32 unk74_7 : 9;
            u32 pad74_16 : 1;
            u32 unk74_17 : 1;
            u32 pad74_18 : 11;
            u32 unk74_29 : 1;
            u32 unk74_30 : 1;
            u32 pad74_31 : 1;
#else
    /* 0x74 */ u32 pad74_31 : 1;
    /* 0x74 */ u32 unk74_30 : 1; // unk74 & 0x40000000
    /* 0x74 */ u32 unk74_29 : 1; // unk74 & 0x20000000
    /* 0x74 */ u32 pad74_18 : 11;
    /* 0x74 */ u32 unk74_17 : 1;
    /* 0x74 */ u32 pad74_16 : 1;
    /* 0x74 */ u32 unk74_7 : 9; // unk76 >> 7
    /* 0x74 */ u32 pad74_0 : 7;
#endif
#ifdef BT_NATIVE
        };
    };
#endif
    /* 0x78 */ u8 unk78;
#ifdef BT_NATIVE
    union {
        u8 flags79;
        struct {
#endif
#ifdef BT_NATIVE_LITTLE_ENDIAN
            u8 unk79_0 : 1;
            u8 unk79_1 : 1;
            u8 unk79_2 : 1;
            u8 unk79_3 : 1;
            u8 unk79_4 : 4;
#else
    /* 0x79 */ u8 unk79_4 : 4;
    /* 0x79 */ u8 unk79_3 : 1;
    /* 0x79 */ u8 unk79_2 : 1;
    /* 0x79 */ u8 unk79_1 : 1;
    /* 0x79 */ u8 unk79_0 : 1;
#endif
#ifdef BT_NATIVE
        };
    };
#endif
#ifdef BT_NATIVE
    union {
        u16 flags7A;
        struct {
#endif
#ifdef BT_NATIVE_LITTLE_ENDIAN
            u16 pad7A_0 : 5;
            u16 unk7A_5 : 1;
            u16 pad7A_7 : 2;
            u16 unk7A_8 : 1;
            u16 unk7A_11 : 3;
            u16 pad7A_15 : 4;
#else
    /* 0x7A */ u16 pad7A_15 : 4;
    /* 0x7A */ u16 unk7A_11 : 3;
    /* 0x7A */ u16 unk7A_8 : 1;
    /* 0x7A */ u16 pad7A_7 : 2;
    /* 0x7A */ u16 unk7A_5:1;
    /* 0x7A */ u16 pad7A_0:5;
#endif
#ifdef BT_NATIVE
        };
    };
#endif
#ifdef BT_NATIVE
    union {
        u32 flags7C;
        struct {
#endif
#ifdef BT_NATIVE_LITTLE_ENDIAN
            u32 unk7C_0 : 12;
            u32 unk7C_12 : 1;
            u32 pad7C_13 : 15;
            u32 unk7C_28 : 1;
            u32 pad7C_29 : 3;
#else
    /* 0x7C */ u32 pad7C_29 : 3;
    /* 0x7C */ u32 unk7C_28 : 1;
    /* 0x7C */ u32 pad7C_13 : 15;
    /* 0x7C */ u32 unk7C_12 : 1; // unk7C & 0x1000
    /* 0x7C */ u32 unk7C_0 : 12; // unk7C & 0xFFF
#endif
#ifdef BT_NATIVE
        };
    };
#endif
#ifdef BT_NATIVE
    union {
        u32 pad80;
        struct {
#ifdef BT_NATIVE_LE_MEMORY
            u16 buffer_handle0; u16 attachment_handle;
#else
            u16 attachment_handle; u16 buffer_handle0;
#endif
        };
    };
#else
    /* 0x80 */ u32 pad80;
#endif
#ifdef BT_NATIVE
    union {
        u32 pad84;
        struct {
#ifdef BT_NATIVE_LE_MEMORY
            u16 buffer_handle2, buffer_handle1;
#else
            u16 buffer_handle1, buffer_handle2;
#endif
        };
    };
#else
    /* 0x84 */ u32 pad84;
#endif
#ifdef BT_NATIVE
    union {
        u32 pad88;
        struct {
#ifdef BT_NATIVE_LE_MEMORY
            s16 model_y_max; s16 model_y_min;
#else
            s16 model_y_min; s16 model_y_max;
#endif
        };
    };
#else
    /* 0x88 */ u32 pad88;
#endif
#ifdef BT_NATIVE
    union {
        u32 pad8C;
        struct {
#ifdef BT_NATIVE_LE_MEMORY
            s16 expression_handle; s16 animation_handle;
#else
            s16 animation_handle; s16 expression_handle;
#endif
        };
    };
#else
    /* 0x8C */ u32 pad8C;
#endif
    /* 0x90 */ u32 pad90;
    /* 0x94 */ u32 pad94;
#ifdef BT_NATIVE
    union { struct { u8 pad98, pad99, pad9A, alpha; }; u8 color[4]; };
#else
    /* 0x98 */ u8 pad98;
    /* 0x99 */ u8 pad99;
    /* 0x9A */ u8 pad9A;
    /* 0x9B */ u8 alpha;
#endif
#if defined(BT_NATIVE) && !defined(BT_ILP32)
    union {
        struct GameSelectRootData *game_select_root_data;
        struct GameSelectBoxData *game_select_box_data;
    };
#endif
} Actor;
#ifndef BT_NATIVE
typedef char bt_assert_actor[(sizeof(Actor) == 0x9C) ? 1 : -1];
#endif

typedef struct ActorData {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    void *unk8;
    void (*unkC_func)(Actor* actor);
    void (*unk10_func)(Actor* actor);
#if defined(BT_NATIVE) && !defined(BT_ILP32)
    union {
        void (*unk14_func)(s32, s32);
        void (*draw_actor)(Actor *, BtIntPtr);
    };
#else
    void (*unk14_func)(s32 arg0, s32 arg1);
#endif
    s32 unk18;
#ifdef BT_NATIVE
    union { s32 unk1C; f32 shadow_scale; };
#else
    s32 unk1C;
#endif
    s16 unk20;
    s16 unk22;
    s16 unk24;
    s16 unk26;
    void (*unk28_func)(Actor* actor);
#ifdef BT_NATIVE
    union { BtIntPtr unk2C; OSThread *(*marker_callback)(void); };
#else
    BtIntPtr unk2C;
#endif
    s16 unk30;
    s16 unk32;
    void (*unk34_func)(Actor* actor);
#ifdef BT_NATIVE
    Actor *(*unk38_func)(s32 *, s32, struct ActorData *, NativeActorFactory, Prop *);
#else
    void (*unk38_func)(void* arg0, s32 arg1, void* arg2, s32 arg3, void* arg4); // argument types unknown currently
#endif
    s16 unk3C;
    s16 unk3E;
#ifdef BT_NATIVE
    intptr_t (*unk40_func)(Actor* actor, s32 message, uintptr_t data);
#else
    void (*unk40_func)(Actor* actor, s32 arg1, s32 arg2);
#endif
    BtIntPtr unk44; /* read as a word (1EE06E0.c); baddies hold a pointer to their own data here */
} ActorData; /* 0x48: an actor descriptor, as the overlays' data holds it */

typedef struct ActorDataX { /* descriptors with two more words */
    ActorData base;
    void (*unk48_func)(Actor* actor, s32 arg1, s32 arg2);
    s32 unk4C;
} ActorDataX;

#ifdef BT_NATIVE
typedef struct Prop {
#else
typedef struct {
#endif
    /* 0x0 */ s16 position[3];
#ifdef BT_NATIVE
    union {
        u16 flags6;
        struct {
#ifdef BT_NATIVE_LITTLE_ENDIAN
            u16 unk6_0 : 1, unk6_1 : 6, unk6_7 : 9;
#else
            u16 unk6_7 : 9, unk6_1 : 6, unk6_0 : 1;
#endif
        };
    };
#else
    /* 0x6 */ u16 unk6_7 : 9;
    /* 0x6 */ u16 unk6_1 : 6; //unk4 << 0x19 >> 0x1A
    /* 0x6 */ u16 unk6_0 : 1; //unk6 >> 0x7 << 0x7
#endif
    /* 0x8 */ u16 ItemID;
    /* 0x0A */ u16 unkA; //0xA
#ifdef BT_NATIVE
    union {
        u32 flagsC;
        struct {
#ifdef BT_NATIVE_LITTLE_ENDIAN
            u32 unkC_0 : 23, FlagOrRotation : 9;
#else
            u32 FlagOrRotation : 9, unkC_0 : 23;
#endif
        };
    };
#else
    /* 0x0C */ u32 FlagOrRotation : 9; //unkC >> 0x17
    /* 0x0C */ u32 unkC_0 : 23; //0xC
#endif
    /* 0x10 */ u16 unk10; //0x10
    /* 0x12 */ u16 unk12; //0x12
} Prop;


#endif // __COMMON_H__
