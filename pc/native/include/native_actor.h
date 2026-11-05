#ifndef BT_NATIVE_ACTOR_H
#define BT_NATIVE_ACTOR_H
#include "common.h"
#include "freelist.h"
#include "vector.h"

typedef union {
    u32 value;
    struct {
#ifdef BT_NATIVE_LITTLE_ENDIAN
        u32 b0 : 1;
        u32 b1 : 1;
        u32 b2 : 1;
        u32 b3 : 1;
        u32 b4 : 1;
        u32 b5 : 1;
        u32 b6 : 1;
        u32 b7 : 1;
        u32 b8 : 1;
        u32 b9 : 1;
        u32 b10 : 1;
        u32 b11 : 1;
        u32 b12 : 1;
        u32 b13 : 1;
        u32 b14 : 1;
        u32 b15 : 1;
        u32 b16 : 1;
        u32 b17 : 1;
        u32 b18 : 1;
        u32 b19 : 1;
        u32 b20 : 1;
        u32 b21 : 1;
        u32 b22 : 1;
        u32 b23 : 1;
        u32 b24 : 1;
        u32 b25 : 1;
        u32 b26 : 1;
        u32 b27 : 1;
        u32 b28 : 1;
        u32 b29 : 1;
        u32 b30 : 1;
        u32 b31 : 1;
#else
        u32 b31 : 1;
        u32 b30 : 1;
        u32 b29 : 1;
        u32 b28 : 1;
        u32 b27 : 1;
        u32 b26 : 1;
        u32 b25 : 1;
        u32 b24 : 1;
        u32 b23 : 1;
        u32 b22 : 1;
        u32 b21 : 1;
        u32 b20 : 1;
        u32 b19 : 1;
        u32 b18 : 1;
        u32 b17 : 1;
        u32 b16 : 1;
        u32 b15 : 1;
        u32 b14 : 1;
        u32 b13 : 1;
        u32 b12 : 1;
        u32 b11 : 1;
        u32 b10 : 1;
        u32 b9 : 1;
        u32 b8 : 1;
        u32 b7 : 1;
        u32 b6 : 1;
        u32 b5 : 1;
        u32 b4 : 1;
        u32 b3 : 1;
        u32 b2 : 1;
        u32 b1 : 1;
        u32 b0 : 1;
#endif
    };
    struct {
#ifdef BT_NATIVE_LITTLE_ENDIAN
        u32 low4:4, middle12:12, high16:16;
#else
        u32 high16:16, middle12:12, low4:4;
#endif
    };
} NativeActorBits32;
_Static_assert(sizeof(NativeActorBits32) == 4, "actor flag word size");

typedef union {
    u16 value;
    struct {
#ifdef BT_NATIVE_LITTLE_ENDIAN
        u16 b0 : 1;
        u16 b1 : 1;
        u16 b2 : 1;
        u16 b3 : 1;
        u16 b4 : 1;
        u16 b5 : 1;
        u16 b6 : 1;
        u16 b7 : 1;
        u16 b8 : 1;
        u16 b9 : 1;
        u16 b10 : 1;
        u16 b11 : 1;
        u16 b12 : 1;
        u16 b13 : 1;
        u16 b14 : 1;
        u16 b15 : 1;
#else
        u16 b15 : 1;
        u16 b14 : 1;
        u16 b13 : 1;
        u16 b12 : 1;
        u16 b11 : 1;
        u16 b10 : 1;
        u16 b9 : 1;
        u16 b8 : 1;
        u16 b7 : 1;
        u16 b6 : 1;
        u16 b5 : 1;
        u16 b4 : 1;
        u16 b3 : 1;
        u16 b2 : 1;
        u16 b1 : 1;
        u16 b0 : 1;
#endif
    };
    struct {
#ifdef BT_NATIVE_LITTLE_ENDIAN
        u16 low14:14, high2:2;
#else
        u16 high2:2, low14:14;
#endif
    };
} NativeActorBits16;
_Static_assert(sizeof(NativeActorBits16) == 2, "actor flag word size");

typedef struct {
    u32 first;
    f32 timer, elapsed, time, previous, speed;
    u32 flags18;
    f32 duration, delay;
    u32 flags24, flags28;
    f32 pod, start_speed, end_speed, start, end;
    u32 angles40, angles44;
} NativeActorPathState;
_Static_assert(sizeof(NativeActorPathState) == 0x48, "path-state word layout");

typedef struct {
    void *model;
    Vector *items;
} NativeActorItems;
typedef struct {
    void *model;
    s16 type, id;
    _Alignas(void *) u8 data[0xA0];
} NativeActorItem;
typedef struct {
    void (*create)(void *, s32, void *, s32, s32);
    void (*update)(void *, void *, s32);
    void (*destroy)(void *);
    void (*defrag)(void *);
} NativeActorItemType;
extern NativeActorItemType D_80124440[];

void func_80105410(void);
void func_80105438(void);
void func_8010545C(void);
void *func_80105494(Actor *);
s32 func_801054D4(Actor *);
void *func_8010556C(Actor *);
void func_80105634(Actor *);
int func_8010568C(Actor *, s32);
void func_801056EC(Actor *, f32);
void func_8010573C(Actor *, f32);
void func_80105834(Actor *);
void func_80105854(Actor *);
void func_8010588C(Actor *);
void func_801058C4(Actor *, s32, f32, u32);
s32 func_80105998(Actor *, f32);
s32 func_80105A5C(Actor *);
void func_80105A9C(Actor *, f32);
f32 func_80105AC4(Actor *);
f32 func_80105AE8(Actor *);
f32 func_80105B0C(Actor *, s32);
void func_80105BAC(Actor *);
void func_80105BE0(Actor *, s32);
void func_80105C20(void);
void func_80105C48(void);
void func_80105CD0(void);
void func_80105DFC(Actor *);
void func_801060E4(s16);
void func_80106138(void *);
void func_801061D8(Actor *);
Unk80132ED0 *func_80106314(void);
void *func_80106320(Actor *, s32, s32, s32);
void *func_801063C0(void *);
void func_801063EC(s16, void *);
void func_8010647C(void *, void *);
void *func_8010649C(void *, s32);
void *func_80106520(s32);
void *func_801065A4(void *);
void func_801065E0(void);
void func_80106608(void);
void func_80106630(void);
void *func_80106668(s32 *);
void func_801066C0(s32);
s32 func_80106730(void);
Actor *func_80106768(s32);
Actor *func_80106790(Unk80132ED0 *);
Actor *func_801067C4(s32 *);
Actor *func_8010682C(s32 *);
Actor *func_801068A8(s32 *);
Actor *func_80106920(s32 *);
s32 func_801069A4(Unk80132ED0 *);
int func_80102EC8(Actor *, f32 (*)[3]);
s32 func_80102F14(void *);
s32 func_80102F44(void *);
s32 func_80102F74(void *, s32);
s32 func_80102FA0(ActorData *, s32);
void func_80102FDC(void *, f32);
void func_80102FE8(void *, s32);
void func_80103014(u8 *);
void func_80103040(Actor *);
void func_80103110(void *, s32);
OSThread *func_80107C20(void);
Actor *func_80107C2C(s32 *, s32, ActorData *, NativeActorFactory, Prop *);
Actor *func_80108454(s32, s32 *, u32);
Actor *func_80108474(u32, f32 *, s32);
Actor *func_801084B0(s32, Actor **);
Actor *func_80108528(s32, f32 [3], s32, Actor **);
Actor *func_8010856C(s32, f32 *, f32 *);
Actor *func_801085CC(s32, s16 *, u32);
s32 func_80108618(Actor *, s32);
void func_80108658(void *, s32, s32, void *);
void func_801088A8(void *, s32, s32, void *);
void func_80108944(Actor *, Actor *);
void func_80108A30(s32, void *, f32, s32);
void func_80108A8C(u32, s32, s32, s32, s32, s32);
void func_80108B04(Actor *, u32);
void func_80108B44(uintptr_t, uintptr_t, uintptr_t);
void func_80108B8C(uintptr_t, uintptr_t, uintptr_t);
void func_80108BD4(Actor *, u32);
void func_80108C14(void);
Actor *func_80108C90(s32, s32 *, u32, Prop *);
void *func_80108CF4(s32);
Actor *func_80108DC0(s32, s32 *, u32, s32, s32, Prop *);
#endif
