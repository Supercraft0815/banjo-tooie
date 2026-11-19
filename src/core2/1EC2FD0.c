#include "common.h"
#if defined(BT_NATIVE) && !defined(BT_ILP32)
#include "native_world_grid.h"
#include "native_block_pool.h"
#include "native_spawn_queue.h"
#include "memory.h"
u8 *D_80132DB0, *D_80132DB4;
void func_800EA370(void);
void func_800EA390(void);
void func_800EA398(void);
s32 func_800EA3A0(void);
s32 func_800EA09C(void);
void func_800EA45C(void);
void func_800EA51C(void);
f32 func_800DC0C0(void);
void *_gccubesearch_entrypoint_17(s32,void *);
#endif

void func_800E96E0()
{
    func_800EA3A0();
    func_800EBB6C();
}

void func_800E9708()
{
    func_800EA370();
}

#if defined(BT_NATIVE) && !defined(BT_ILP32)
void func_800E9728(void) {
    func_800EA390();func_800EB70C();
    D_80132DB0=(u8 *)func_800B42FC(sizeof(Prop),10);
    D_80132DB4=(u8 *)func_800B42FC(sizeof(NativeMarkerProp),10);
}
#else
void func_800E9728(void) {
    s32 func_800B42FC(s32, s32);
    s32 func_800EA390();
    void func_800EB70C(void);
    extern s32 D_80132DB0;
    extern s32 D_80132DB4;
    func_800EA390();
    func_800EB70C();
    D_80132DB0 = func_800B42FC(0x14, 0xA);
    D_80132DB4 = func_800B42FC(0xC, 0xA);
}
#endif

#if defined(BT_NATIVE) && !defined(BT_ILP32)
void func_800E9774(void) {
    func_800EA398();func_800EB750();
    func_800B42DC(D_80132DB0);D_80132DB0=NULL;
    func_800B42DC(D_80132DB4);D_80132DB4=NULL;
}
#else
void func_800E9774(void) {
    s32 func_800B42DC(s32);
    s32 func_800EA398();
    s32 func_800EB750();
    extern s32 D_80132DB0;
    extern s32 D_80132DB4;
    func_800EA398();
    func_800EB750();
    func_800B42DC(D_80132DB0);
    D_80132DB0 = 0;
    func_800B42DC(D_80132DB4);
    D_80132DB4 = 0;
}
#endif

/* extern */

#if defined(BT_NATIVE) && !defined(BT_ILP32)
void func_800E97C0(void) {
    if (func_800EA09C()!=1) { func_800EA45C();func_800A5CFC();func_800EA51C(); }
}
#else
void func_800E97C0(void) {
    s32 func_800A5CFC();
    s32 func_800EA09C();
    s32 func_800EA45C();
    s32 func_800EA51C();
    if (func_800EA09C() != 1) {
        func_800EA45C();
        func_800A5CFC();
        func_800EA51C();
    }
}
#endif

#if defined(BT_NATIVE) && !defined(BT_ILP32)
NativeMarkerProp *func_800E9804(NativeWorldCell *cube) {
    u8 *old_pool=D_80132DB4;
    s16 old_start=cube->dynamic[0];
    NativeMarkerProp *prop=(void *)func_800B3CDC(&D_80132DB4,cube->dynamic);
    prop->flags &= ~1u;
    if (old_pool!=D_80132DB4) func_800BE4C4();
    else if (old_start!=cube->dynamic[0]) func_800E9CF4(cube);
    return prop;
}
#else
void *func_800E9804(s16 *arg0) {
    BT_IDO_ONLY(s32 func_800B3CDC();) BT_NATIVE_ONLY(s16 *func_800B3CDC(u8 **, void *);)
    s32 func_800BE4C4();
    void func_800E9CF4(s16 *);
    extern s32 D_80132DB4;
    void *result;
    s32 oldList;
    s32 oldCount;

    oldList = D_80132DB4;
    oldCount = arg0[2];
    BT_IDO_ONLY(result = (void *)func_800B3CDC(&D_80132DB4, arg0 + 2, arg0);) BT_NATIVE_ONLY(result = (void *)func_800B3CDC((u8 **)&D_80132DB4, arg0 + 2);)
    ((u8 *)result)[0xB] &= 0xFFFE;
    if (oldList != D_80132DB4) {
        func_800BE4C4();
    } else if (oldCount != arg0[2]) {
        func_800E9CF4(arg0);
    }
    return result;
}
#endif

#if defined(BT_NATIVE) && !defined(BT_ILP32)
Prop *func_800E9898(NativeWorldCell *cube) {
    return (void *)func_800B3CDC(&D_80132DB0,cube->models);
}
#else
void *func_800E9898(s32 arg0) {
    BT_IDO_ONLY(s32 func_800B3CDC(s32 *, s32);) BT_NATIVE_ONLY(s16 *func_800B3CDC(u8 **, void *);)
    extern s32 D_80132DB0;
    return (void *)func_800B3CDC(BT_NATIVE_ONLY((u8 **)) &D_80132DB0, BT_NATIVE_ONLY((void *)) arg0);
}
#endif

/* extern */

#if defined(BT_NATIVE) && !defined(BT_ILP32)
NativeMarkerProp *func_800E98C0(NativeWorldCell *cube) {
    NativeMarkerProp *prop=func_800E9804(cube);
    prop->sprite &= ~2u;
    prop->flags=(prop->flags & 0x20) | 0x10 | (((u16)(func_800DC0C0()*32.0f) & 31)<<6);
    return prop;
}
#else
void *func_800E98C0(s32 arg0) {
    typedef struct {
        u8 pad0[3];
        BT_BITFIELD_ORDER(u8 reserved0 : 6, u8 reserved1 : 1);
        u8 isMirrored : 1;
        BT_BITFIELD_ORDER(u8 reserved1 : 1, u8 reserved0 : 6);
        u8 pad4[6];
        BT_BITFIELD_ORDER(u16 frame : 5, u16 isActorProp : 1);
        BT_BITFIELD_ORDER(u16 random : 5, u16 isModelProp : 1);
        BT_BITFIELD_ORDER(u16 reserved2 : 1, u16 flag4 : 1);
        BT_BITFIELD_ORDER(u16 flag10 : 1, u16 flag8 : 1);
        BT_BITFIELD_ORDER(u16 flag8 : 1, u16 flag10 : 1);
        BT_BITFIELD_ORDER(u16 flag4 : 1, u16 reserved2 : 1);
        BT_BITFIELD_ORDER(u16 isModelProp : 1, u16 random : 5);
        BT_BITFIELD_ORDER(u16 isActorProp : 1, u16 frame : 5);
    } SpriteProp;
    f32 func_800DC0C0(void);
    void *func_800E9804();
    SpriteProp *sp1C;

    sp1C = func_800E9804(arg0);
    sp1C->isActorProp = 0;
    sp1C->isModelProp = 0;
    sp1C->frame = 0;
    sp1C->isMirrored = 0;
    sp1C->random = func_800DC0C0() * 32.0f;
    sp1C->flag8 = 0;
    sp1C->flag4 = 0;
    sp1C->flag10 = 1;
    return sp1C;
}
#endif

#if defined(BT_NATIVE) && !defined(BT_ILP32)
NativeMarkerProp *func_800E99E0(NativeWorldCell *cube) {
    NativeMarkerProp *prop=func_800E9804(cube);
    prop->flags=(prop->flags & ~0xCu) | 0x11;
    return prop;
}
#else
void *func_800E99E0(BT_PARAM_OR_VOID(s16 *bt_a0)) {
    typedef struct {
        u8 pad[0xB];
        BT_BITFIELD_ORDER(u8 reserved : 3, u8 flag1 : 1);
        BT_BITFIELD_ORDER(u8 flag10 : 1, u8 reserved2 : 1);
        BT_BITFIELD_ORDER(u8 flag8 : 1, u8 flag4 : 1);
        BT_BITFIELD_ORDER(u8 flag4 : 1, u8 flag8 : 1);
        BT_BITFIELD_ORDER(u8 reserved2 : 1, u8 flag10 : 1);
        BT_BITFIELD_ORDER(u8 flag1 : 1, u8 reserved : 3);
    } Flags;
    void *func_800E9804();
    Flags *p;
    p = func_800E9804(BT_NATIVE_ONLY(bt_a0));
    p->flag1 = 1;
    p->flag8 = 0;
    p->flag4 = 0;
    p->flag10 = 1;
    return p;
}
#endif

#if defined(BT_NATIVE) && !defined(BT_ILP32)
Prop *func_800E9A24(NativeWorldCell *cube) {
    Prop *prop=func_800E9898(cube);
    prop->flags6=0x32u<<7;
    prop->ItemID=prop->unkA=0;
    prop->flagsC=0;
    prop->unk12=(prop->unk12 & 0xFC00) | 0x100;
    return prop;
}
#else
void *func_800E9A24(s32 arg0) {
    typedef struct {
    u8 pad[6];
    BT_BITFIELD_ORDER(u16 value : 9, u8 flag7 : 1);
    u8 flags7 : 6;
    BT_BITFIELD_ORDER(u8 flag7 : 1, u16 value : 9);
    u16 value8;
    u8 valueA;
    u8 valueB;
    u32 valueC;
    u8 pad10[2];
    BT_BITFIELD_ORDER(u16 reserved12 : 6, u16 flag13f : 2);
    BT_BITFIELD_ORDER(u16 flag12b : 1, u16 flag13e : 2);
    BT_BITFIELD_ORDER(u16 flag12a : 1, u16 flag13d : 1);
    BT_BITFIELD_ORDER(u16 flag13a : 1, u16 flag13c : 1);
    u16 flag13b : 1;
    BT_BITFIELD_ORDER(u16 flag13c : 1, u16 flag13a : 1);
    BT_BITFIELD_ORDER(u16 flag13d : 1, u16 flag12a : 1);
    BT_BITFIELD_ORDER(u16 flag13e : 2, u16 flag12b : 1);
    BT_BITFIELD_ORDER(u16 flag13f : 2, u16 reserved12 : 6);
   
    } Data;
    Data *p = func_800E9898(arg0);
    p->value = 0x32;
    p->valueB = 0;
    p->valueA = 0;
    p->value8 = 0;
    p->valueC = 0;
    p->flags7 = 0;
    p->flag7 = 0;
    p->flag12b = 0;
    p->flag12a = 1;
    p->flag13a = 0;
    p->flag13b = 0;
    p->flag13c = 0;
    p->flag13d = 0;
    p->flag13e = 0;
    p->flag13f = 0;
    return p;
}
#endif

#if defined(BT_NATIVE) && !defined(BT_ILP32)
u32 func_800E9AC0(NativeWorldCell *cube,NativeMarkerProp *prop) {
    u8 *old_pool=D_80132DB4;
    s16 old_start=cube->dynamic[0];
    uintptr_t offset=(uintptr_t)prop-(uintptr_t)func_800E9E88(cube);
    u32 model;
    if (offset%sizeof(*prop) || offset/sizeof(*prop)>=(u32)cube->dynamic[1]) return 0;
    model=(prop->flags>>1)&1;
    func_800B3FD0(&D_80132DB4,cube->dynamic,offset/sizeof(*prop));
    if (old_pool!=D_80132DB4) func_800BE4C4();
    else if (old_start+1!=cube->dynamic[0]) func_800E9CF4(cube);
    return model;
}
#else
u32 func_800E9AC0(s16 *arg0, void *arg1) {
    void func_800B3FD0(u8 **, void *, s32);
    s32 func_800BE4C4();
    void func_800E9CF4(s16 *);
    s32 func_800E9E88(s32);
    extern s32 D_80132DB4;
    typedef struct {
        s32 words[2];
        BT_BITFIELD_ORDER(u32 unused : 30, u32 last : 1);
        u32 flag : 1;
        BT_BITFIELD_ORDER(u32 last : 1, u32 unused : 30);
    } Entry;
    u32 sp24;
    s32 index;
    s32 sp1C;
    s32 sp18;

    sp24 = ((Entry *)arg1)->flag;
    index = ((s32)arg1 - func_800E9E88((s32)arg0)) / 12;
    sp1C = D_80132DB4;
    sp18 = arg0[2];
    func_800B3FD0((u8 **)&D_80132DB4, arg0 + 2, index);
    if (sp1C != D_80132DB4) {
        func_800BE4C4();
    } else if (sp18 + 1 != arg0[2]) {
        func_800E9CF4(arg0);
    }
    return sp24;
}
#endif

#if defined(BT_NATIVE) && !defined(BT_ILP32)
void func_800E9B74(NativeWorldCell *cube,Prop *prop) {
    uintptr_t offset=(uintptr_t)prop-(uintptr_t)func_800E9D68(cube);
    size_t index=offset/sizeof(*prop);
    if (offset%sizeof(*prop) || index>=(u32)cube->models[1]) return;
    if (index<func_800E9DD4(cube)) --*func_800BE5C4(cube);
    func_800B3FD0(&D_80132DB0,cube->models,index);
}
#else
void func_800E9B74(s16 *arg0, s32 arg1) {
    void func_800B3FD0(u8 **, void *, s32);
    u8 *func_800BE5C4(u8 *);
    Prop *func_800E9D68(s16 *);
    u8 func_800E9DD4(u8 *);
    extern s32 D_80132DB0;
    s32 sp1C;
    u8 *temp_v0;

    sp1C = (arg1 - (s32)func_800E9D68(arg0)) / 20;
    if (sp1C < func_800E9DD4((u8 *)arg0)) {
        temp_v0 = func_800BE5C4((u8 *)arg0);
        *temp_v0 -= 1;
    }
    func_800B3FD0((u8 **)&D_80132DB0, arg0, sp1C);
}
#endif

#if !defined(BT_NATIVE) || defined(BT_ILP32)
Prop *func_800E9D68(s16 *);
#endif
#if defined(BT_NATIVE) && !defined(BT_ILP32)
Prop *func_800E9BF4(NativeWorldCell *cube,s32 index) {
    return index<0 || index>=cube->models[1] ? NULL : func_800E9D68(cube)+index;
}
#else
s32 func_800E9BF4(s16 *arg0, s32 arg1) { if ((arg1 < 0) || (arg1 >= arg0[1])) return 0; return (s32)func_800E9D68(arg0) + arg1 * 20; }
#endif

#if defined(BT_NATIVE) && !defined(BT_ILP32)
void func_800E9C44(NativeWorldCell *cube) {
    NativeMarkerProp *prop=func_800E9E88(cube), *end=func_800E9EB4(cube);
    if (prop) {
        u8 *old_pool=D_80132DB4;
        for (;prop<end;++prop) if (prop->flags&1) {
            prop->marker->unk0=NULL;
            func_800EBE24(prop->marker);
        }
        func_800B422C(&D_80132DB4,cube->dynamic);
        if (old_pool!=D_80132DB4) func_800BE4C4();
    }
    func_800B422C(&D_80132DB0,cube->models);
    *func_800BE5C4(cube)=0;
}
#else
void func_800E9C44(s16 *arg0) {
    void func_800B422C(u8 **, s16 *);
    u8 *func_800BE5C4(u8 *);
    void func_800EBE24(void *);
    s32 func_800E9E88(s32);
    u32 func_800E9EB4(s16 *);
    extern s32 D_80132DB0;
    extern s32 D_80132DB4;
    s32 entry;
    u32 end;

    if (func_800E9E88((s32)arg0) != 0) {
        entry = func_800E9E88((s32)arg0);
        end = func_800E9EB4(arg0);
        if ((u32)entry < end) {
            do {
                if (*(s32 *)(entry + 8) & 1) {
                    func_800EBE24(*(void **)entry);
                }
                entry += 12;
            } while ((u32)entry < end);
        }
        func_800B422C((u8 **)&D_80132DB4, arg0 + 2);
    }
    func_800B422C((u8 **)&D_80132DB0, arg0);
    *func_800BE5C4((u8 *)arg0) = 0;
}
#endif

#if defined(BT_NATIVE) && !defined(BT_ILP32)
void func_800E9CF4(NativeWorldCell *cube) {
    NativeMarkerProp *prop=func_800E9E88(cube), *end=func_800E9EB4(cube);
    for (;prop && prop<end;++prop) if (prop->flags&1) prop->marker->unk0=(u32 *)prop;
}
#else
void func_800E9CF4(s16 *arg0) {
    s32 func_800E9E88(s32);
    u32 func_800E9EB4(s16 *);
    s32 start;
    s32 entry;
    u32 end;

    if (arg0[3] != 0) {
        start = func_800E9E88((s32)arg0);
        end = func_800E9EB4(arg0);
        entry = start;
        if ((u32)entry < end) {
            do {
                if ((*(s32 *)(entry + 8) & 1) == 1) {
                    **(s32 **)entry = entry;
                }
                entry += 12;
            } while ((u32)entry < end);
        }
    }
}
#endif

#if defined(BT_NATIVE) && !defined(BT_ILP32)
Prop *func_800E9D68(NativeWorldCell *cube) { return func_800B42A0(D_80132DB0,cube->models); }
#else
Prop *func_800E9D68(s16 *arg0) {
    s32 func_800B42A0(s32, s32);
    extern s32 D_80132DB0;
    return (Prop *)func_800B42A0(D_80132DB0, (s32)arg0);
}
#endif

#if defined(BT_NATIVE) && !defined(BT_ILP32)
Prop *func_800E9D90(NativeWorldCell *cube) {
    Prop *begin=func_800E9D68(cube);
    return begin ? begin+cube->models[1] : NULL;
}
#else
u32 func_800E9D90(s16 *arg0) { return arg0[1] * 20 + (u32)func_800E9D68(arg0); }
#endif

#if defined(BT_NATIVE) && !defined(BT_ILP32)
s32 func_800E9DC4(NativeWorldCell *cube) { return cube->models[1]; }
#else
s32 func_800E9DC4(s16 *arg0) {
    return arg0[1];
}
#endif

#if defined(BT_NATIVE) && !defined(BT_ILP32)
s32 func_800E9DCC(NativeWorldCell *cube) { return cube->dynamic[1]; }
#else
s32 func_800E9DCC(s16 *arg0) {
    return arg0[3];
}
#endif

/* extern */

#if defined(BT_NATIVE) && !defined(BT_ILP32)
u8 func_800E9DD4(NativeWorldCell *cube) { return *func_800BE5C4(cube); }
#else
u8 func_800E9DD4(u8 *arg0) {
    u8 *func_800BE5C4(u8 *);
    return *func_800BE5C4(arg0);
}
#endif

#if defined(BT_NATIVE) && !defined(BT_ILP32)
void func_800E9DF8(void) {
    u8 *moved;
    D_80132DB0=defrag(D_80132DB0);
    moved=defrag(D_80132DB4);
    if (moved!=D_80132DB4) { D_80132DB4=moved;func_800BE4C4(); }
}
#else
void func_800E9DF8(void) {
    s32 defrag(s32);
    s32 func_800BE4C4(s32 *);
    extern s32 D_80132DB0;
    extern s32 D_80132DB4;
    s32 temp_v0;
    s32 *ptr;

    D_80132DB0 = defrag(D_80132DB0);
    temp_v0 = defrag(D_80132DB4);
    ptr = (s32 *)((u32)&D_80132DB4 | 0);
    if (temp_v0 != *ptr) {
        *ptr = temp_v0;
        func_800BE4C4(ptr);
    }
}
#endif

/* extern */

#if defined(BT_NATIVE) && !defined(BT_ILP32)
void func_800E9E4C(NativeWorldCell *cube,s32 unused) {
    (void)unused;
    func_800B4290(cube->dynamic);func_800B4290(cube->models);*func_800BE5C4(cube)=0;
}
#else
void func_800E9E4C(u8 *arg0, s32 arg1) {
    void func_800B4290(void *arg0);
    u8 *func_800BE5C4();
    func_800B4290(arg0 + 4);
    func_800B4290(arg0);
    *func_800BE5C4(arg0) = 0;
}
#endif

#if defined(BT_NATIVE) && !defined(BT_ILP32)
NativeMarkerProp *func_800E9E88(NativeWorldCell *cube) { return func_800B42A0(D_80132DB4,cube->dynamic); }
#else
s32 func_800E9E88(s32 arg0) {
    extern s32 D_80132DB4;
    s32 func_800B42A0(s32, s32);
    return func_800B42A0(D_80132DB4, arg0 + 4);
}
#endif

#if defined(BT_NATIVE) && !defined(BT_ILP32)
NativeMarkerProp *func_800E9EB4(NativeWorldCell *cube) {
    NativeMarkerProp *begin=func_800E9E88(cube);
    return begin ? begin+cube->dynamic[1] : NULL;
}
#else
u32 func_800E9EB4(s16 *arg0) { return arg0[3] * 12 + (u32)func_800E9E88((s32)arg0); }
#endif

/* extern */

#if defined(BT_NATIVE) && !defined(BT_ILP32)
void func_800E9EE8(s32 id) {
    NativeWorldCell *cube;
    Prop *prop=_gccubesearch_entrypoint_17(id,&cube);
    if (prop) func_800E9B74(cube,prop);
}
#else
void func_800E9EE8(s32 arg0) {
    s32 _gccubesearch_entrypoint_17(s32, s32);
    void func_800E9B74(s16 *, s32);
    s32 temp_v0;
    s16 *sp18;

    temp_v0 = _gccubesearch_entrypoint_17(arg0, (s32) &sp18);
    if (temp_v0 != 0) {
        func_800E9B74(sp18, temp_v0);
    }
}
#endif

/* No named reader survives for these original data words. */
u32 D_80123530[4] BT_DATA(4, world_grid_tail, 0) = {0};
