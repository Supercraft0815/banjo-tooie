#include "common.h"
#include "attract_command.inc"
int func_800D3770(void) {
    extern u8 D_8012762C;
    extern s8 D_8012B3F1;
    s32 level;
    int flag;

    level = D_8012762C;
    flag = level >= 0xF && level < 0x1C;
    if (level == 0x11) {
        flag = 0;
    }
    return (D_8012B3F1 + 1) && flag;
}    typedef struct { s8 unk0; s8 unk1; u8 unk2; u8 unk3; u8 pad4[0x2]; s16 unk6; s8 unk8; u8 unk9; u8 unkA; u8 unkB; } Obj1EAD060_D_8012B3F0; /* offsets.py genstruct: fields from raw offsets on &D_8012B3F0; rename once understood */

void func_800D37C0(s32 arg0) {
    extern s32 D_8012B3F0;
    (((Obj1EAD060_D_8012B3F0 *)&D_8012B3F0)->unk0) = arg0;
    (((Obj1EAD060_D_8012B3F0 *)&D_8012B3F0)->unk1) = arg0;
}

void func_800D37D4(void) {
    extern s32 D_8012B3F0;
    (((Obj1EAD060_D_8012B3F0 *)&D_8012B3F0)->unk1) = -1;
    (((Obj1EAD060_D_8012B3F0 *)&D_8012B3F0)->unk0) = (s8) (((Obj1EAD060_D_8012B3F0 *)&D_8012B3F0)->unk1);
}    typedef struct { s8 unk0; } Obj1EAD060_D_8012B3F1; /* offsets.py genstruct: fields from raw offsets on &D_8012B3F1; rename once understood */

s32 func_800D37F0(void) {
    extern s8 D_8012B3F1;
    return *&((Obj1EAD060_D_8012B3F1 *)&D_8012B3F1)->unk0;
}

void func_800D37FC(void) {
    void _glgamedata_entrypoint_2(BtIntPtr);
    s32 _glsavegame_entrypoint_8(s32 arg0);
    void func_8001B754(s16);
    void *func_8001B798(s16);
    void func_800D3C70(void);
    extern s32 D_8012B3F0;

    if ((((Obj1EAD060_D_8012B3F0 *)&D_8012B3F0)->unk9) == 3) {
        _glgamedata_entrypoint_2(func_8001B798((((Obj1EAD060_D_8012B3F0 *)&D_8012B3F0)->unk6)));
        func_8001B754((((Obj1EAD060_D_8012B3F0 *)&D_8012B3F0)->unk6));
        (((Obj1EAD060_D_8012B3F0 *)&D_8012B3F0)->unk1) = (((Obj1EAD060_D_8012B3F0 *)&D_8012B3F0)->unk8);
        (((Obj1EAD060_D_8012B3F0 *)&D_8012B3F0)->unk3) = (((Obj1EAD060_D_8012B3F0 *)&D_8012B3F0)->unkB);
        (((Obj1EAD060_D_8012B3F0 *)&D_8012B3F0)->unk2) = (((Obj1EAD060_D_8012B3F0 *)&D_8012B3F0)->unkA);
        (((Obj1EAD060_D_8012B3F0 *)&D_8012B3F0)->unk9) = 0;
        (((Obj1EAD060_D_8012B3F0 *)&D_8012B3F0)->unk8) = -1;
        (((Obj1EAD060_D_8012B3F0 *)&D_8012B3F0)->unk6) = 0;
    }
    if ((((Obj1EAD060_D_8012B3F0 *)&D_8012B3F0)->unk0) != -1) {
        _glsavegame_entrypoint_8((((Obj1EAD060_D_8012B3F0 *)&D_8012B3F0)->unk0));
        (((Obj1EAD060_D_8012B3F0 *)&D_8012B3F0)->unk0) = -1;
    }
    func_800D3C70();
}

void func_800D389C(void) {
    void _glgamedata_entrypoint_1(void *arg0);
    s32 _glsavegame_entrypoint_7(s32 arg0);
    s16 func_8001B668(s32, s32);
    void *func_8001B798(s16);
    extern s32 D_8012B3F0;

    if (func_800D3770() != 0) {
        _glsavegame_entrypoint_7((((Obj1EAD060_D_8012B3F0 *)&D_8012B3F0)->unk1));
    }
    if ((((Obj1EAD060_D_8012B3F0 *)&D_8012B3F0)->unk9) == 1) {
        (((Obj1EAD060_D_8012B3F0 *)&D_8012B3F0)->unk6) = func_8001B668(0, 0x1C0);
        _glgamedata_entrypoint_1(func_8001B798((((Obj1EAD060_D_8012B3F0 *)&D_8012B3F0)->unk6)));
        (((Obj1EAD060_D_8012B3F0 *)&D_8012B3F0)->unk8) = (((Obj1EAD060_D_8012B3F0 *)&D_8012B3F0)->unk1);
        (((Obj1EAD060_D_8012B3F0 *)&D_8012B3F0)->unkB) = (u8) (((Obj1EAD060_D_8012B3F0 *)&D_8012B3F0)->unk3);
        (((Obj1EAD060_D_8012B3F0 *)&D_8012B3F0)->unkA) = (u8) (((Obj1EAD060_D_8012B3F0 *)&D_8012B3F0)->unk2);
        (((Obj1EAD060_D_8012B3F0 *)&D_8012B3F0)->unk1) = -1;
        (((Obj1EAD060_D_8012B3F0 *)&D_8012B3F0)->unk9) = 2U;
    }
}

s32 func_800D3934(void) {
    extern s8 D_8012B3F2;
    return (u8) D_8012B3F2 == 1;
}

s32 func_800D3948(void) {
    extern s8 D_8012B3F2;
    return (u8) D_8012B3F2 == 3;
}

s32 func_800D395C(void) {
    extern s8 D_8012B3F2;
    return (u8) D_8012B3F2 == 2;
}

void func_800D3970(void) { void func_800D37D4(void); void func_800D3A14(s32); void func_800D3CF8(s32); void func_800D3D10(s32); func_800D37D4(); func_800D3A14(1); func_800D3CF8(0); func_800D3D10(1); }

void func_800D39A8(void) {
    s16 func_800B2DC0(s32, s32);
    extern s16 D_8012B3FC;
    D_8012B3FC = func_800B2DC0(sizeof(AttractCommand), 1);
}    typedef struct { s8 unk0; } Obj1EAD060_D_8012B3F2; /* offsets.py genstruct: fields from raw offsets on &D_8012B3F2; rename once understood */

void func_800D39D0(s32 arg0) {
    extern s8 D_8012B3F2;
    ((Obj1EAD060_D_8012B3F2 *)&D_8012B3F2)->unk0 = arg0;
}

void func_800D39DC(s32 arg0) {
    BtIntPtr func_800D3B6C(s32, AttractCallback, s32, s32, s32);
    if (arg0 >= 0) {
        func_800D3B6C(1, (AttractCallback) func_800D39D0, arg0, 0, 0);
    }
}    typedef struct { s8 unk0; } Obj1EAD060_D_8012B3F3; /* offsets.py genstruct: fields from raw offsets on &D_8012B3F3; rename once understood */

void func_800D3A14(s32 arg0) {
    extern s8 D_8012B3F3;
    ((Obj1EAD060_D_8012B3F3 *)&D_8012B3F3)->unk0 = arg0;
}

void func_800D3A20(s32 arg0) {
    BtIntPtr func_800D3B6C(s32, AttractCallback, s32, s32, s32);
    void func_800DA544(GameFlag);
    func_800D3B6C(1, (AttractCallback) ATTRACT_GAME_FLAG, arg0, 0, 0);
}

void func_800D3A54(s32 arg0, s32 arg1) {
    BtIntPtr func_800D3B6C(s32, AttractCallback, s32, s32, s32);
    void func_800C70B0(s32, s32);
    func_800D3B6C(2, (AttractCallback) func_800C70B0, arg0, arg1, 0);
}

void func_800D3A88(void) {
    BtIntPtr func_800D3B6C(s32, AttractCallback, s32, s32, s32);
    void func_800C7010(void);
    func_800D3B6C(0, (AttractCallback) func_800C7010, 0, 0, 0);
}

void func_800D3ABC(s32 arg0, s32 arg1) {
    BtIntPtr func_800D3B6C(s32, AttractCallback, s32, s32, s32);
    void func_800D1864(u32, u32, u32);
    func_800D3B6C(3, (AttractCallback) func_800D1864, arg0, arg1, 0);
}

void func_800D3AF0(s32 arg0) {
    BtIntPtr func_800D3B6C(s32, AttractCallback, s32, s32, s32);
    void func_800D1864(u32, u32, u32);
    func_800D3B6C(3, (AttractCallback) func_800D1864, arg0, 0x3E8, 0);
}

void func_800D3B24(void) {
    BtIntPtr func_800D3B6C(s32, AttractCallback, s32, s32, s32);
    void func_800DC324(s32 arg0);
    func_800D3B6C(1, (AttractCallback) func_800DC324, osGetCount(), 0, 0);
}

u32 func_800D3B60(void) {
    extern s8 D_8012B3F3;
    return (u8)D_8012B3F3;
}

BtIntPtr func_800D3B6C(s32 arg0, AttractCallback arg1, s32 arg2, s32 arg3, s32 arg4) {
    extern s16 D_8012B3FC;
    void* func_800B2A58(s16 arg0);
    AttractCommand *temp_v0;

    temp_v0 = func_800B2A58(D_8012B3FC);
    temp_v0->count = (s8) arg0;
    temp_v0->callback.zero = arg1;
    temp_v0->args[0] = arg2;
    temp_v0->args[1] = arg3;
    temp_v0->args[2] = arg4;
    return (BtIntPtr) temp_v0;
}

void func_800D3BC8(void *arg0) {
    AttractCommand *entry = arg0;
    /* Each queued callback uses its declared arity. In O32 the same address
     * occupies one word. Native builds store a full function pointer. */
    BT_NATIVE_ONLY(_Static_assert(sizeof(entry->callback) == sizeof(void (*)(void)),
                                  "command callback width");)


    switch (entry->count) {
        case 0:
            entry->callback.zero();
            break;
        case 1:
            entry->callback.one(entry->args[0]);
            break;
        case 2:
            entry->callback.two(entry->args[0], entry->args[1]);
            break;
        case 3:
            entry->callback.three(entry->args[0], entry->args[1], entry->args[2]);
            break;
    }
}

void func_800D3C70(void) {
    struct Vector;
    struct Vector *func_800B2890(s16);
    void *vector_begin(struct Vector *);
    void *vector_end(struct Vector *);
    void func_800B2D48(s16);
    extern s16 D_8012B3FC;
    struct Vector *vec;
    u8 *entry;
    u8 *end;

    if (D_8012B3FC != 0) {
        vec = func_800B2890(D_8012B3FC);
        entry = vector_begin(vec);
        end = vector_end(vec);
        while (entry < end) {
            func_800D3BC8(entry);
            entry += sizeof(AttractCommand);
        }
        func_800B2D48(D_8012B3FC);
        D_8012B3FC = 0;
    }
}    typedef struct { s8 unk0; } Obj1EAD060_D_8012B3F4; /* offsets.py genstruct: fields from raw offsets on &D_8012B3F4; rename once understood */

void func_800D3CF8(s32 arg0) {
    extern s8 D_8012B3F4;
    ((Obj1EAD060_D_8012B3F4 *)&D_8012B3F4)->unk0 = arg0;
}

u32 func_800D3D04(void) {
    extern s8 D_8012B3F4;
    return *(u8 *)&D_8012B3F4;
}    typedef struct { s8 unk0; } Obj1EAD060_D_8012B3F5; /* offsets.py genstruct: fields from raw offsets on &D_8012B3F5; rename once understood */

void func_800D3D10(s32 arg0) {
    extern s8 D_8012B3F5;
    ((Obj1EAD060_D_8012B3F5 *)&D_8012B3F5)->unk0 = arg0;
}

u32 func_800D3D1C(void) {
    extern s8 D_8012B3F5;
    return *(u8 *)&D_8012B3F5;
}

s32 func_800D3D28(void) {
    extern s32 D_8012B3F0;
    if ((((Obj1EAD060_D_8012B3F0 *)&D_8012B3F0)->unk9) != 0) {
        return 0;
    }
    (((Obj1EAD060_D_8012B3F0 *)&D_8012B3F0)->unk9) = 1U;
    return 1;
}

int func_800D3D58(void) { extern s32 D_8012B3F0; switch (((Obj1EAD060_D_8012B3F0 *)&D_8012B3F0)->unk9) { case 1: (((Obj1EAD060_D_8012B3F0 *)&D_8012B3F0)->unk9) = 0; return 1; case 2: (((Obj1EAD060_D_8012B3F0 *)&D_8012B3F0)->unk9) = 3; return 1; default: return 0; } }

/* extern */

s32 func_800D3DA4(s32 arg0) {
    s32 func_800F54F0(BtIntPtr);
    return func_800F54F0(arg0);
}

#ifdef BT_NATIVE
/* bss_to_c.py: native definitions of asm .bss labels */
#include "bt_data.h"
s32 D_8012B3F0 BT_DATA(4, bss_core2bss1_2, 0x160);
s8 D_8012B3F1 BT_DATA(4, bss_core2bss1_2, 0x161);
s8 D_8012B3F2 BT_DATA(4, bss_core2bss1_2, 0x162);
s8 D_8012B3F3 BT_DATA(4, bss_core2bss1_2, 0x163);
s8 D_8012B3F4 BT_DATA(4, bss_core2bss1_2, 0x164);
s8 D_8012B3F5 BT_DATA(4, bss_core2bss1_2, 0x165);
#endif
