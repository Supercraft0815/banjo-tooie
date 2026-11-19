#include "common.h"
#include "attract_command.inc"

typedef struct {
    s8 pending_slot;
    s8 current_slot;
    u8 game_mode;
    u8 mode_option;
    u8 option4;
    u8 option5;
    s16 backup_handle;
    s8 saved_slot;
    u8 backup_state;
    u8 saved_game_mode;
    u8 saved_option;
} AttractSaveState;

#ifdef BT_NATIVE
AttractSaveState D_8012B3F0;
_Static_assert(sizeof(AttractSaveState) == 12, "attract save state");
#else
extern AttractSaveState D_8012B3F0;
#endif

int func_800D3770(void) {
    extern u8 D_8012762C;
    BT_IDO_ONLY(extern s8 D_8012B3F1;)
    s32 level;
    int flag;

    level = D_8012762C;
    flag = level >= 0xF && level < 0x1C;
    if (level == 0x11) {
        flag = 0;
    }
    return (BT_DATA_FIELD(D_8012B3F0.current_slot, D_8012B3F1) + 1) && flag;
}

void func_800D37C0(s32 arg0) {
    D_8012B3F0.pending_slot = arg0;
    D_8012B3F0.current_slot = arg0;
}

void func_800D37D4(void) {
    D_8012B3F0.current_slot = -1;
    D_8012B3F0.pending_slot = (s8) D_8012B3F0.current_slot;
}

s32 func_800D37F0(void) {
    BT_IDO_ONLY(extern s8 D_8012B3F1;)
    return BT_DATA_FIELD(D_8012B3F0.current_slot, D_8012B3F1);
}

void func_800D37FC(void) {
    void _glgamedata_entrypoint_2(BtIntPtr);
    s32 _glsavegame_entrypoint_8(s32 arg0);
    void func_8001B754(s16);
    void *func_8001B798(s16);
    void func_800D3C70(void);

    if (D_8012B3F0.backup_state == 3) {
        _glgamedata_entrypoint_2(func_8001B798(D_8012B3F0.backup_handle));
        func_8001B754(D_8012B3F0.backup_handle);
        D_8012B3F0.current_slot = D_8012B3F0.saved_slot;
        D_8012B3F0.mode_option = D_8012B3F0.saved_option;
        D_8012B3F0.game_mode = D_8012B3F0.saved_game_mode;
        D_8012B3F0.backup_state = 0;
        D_8012B3F0.saved_slot = -1;
        D_8012B3F0.backup_handle = 0;
    }
    if (D_8012B3F0.pending_slot != -1) {
        _glsavegame_entrypoint_8(D_8012B3F0.pending_slot);
        D_8012B3F0.pending_slot = -1;
    }
    func_800D3C70();
}

void func_800D389C(void) {
    void _glgamedata_entrypoint_1(void *arg0);
    s32 _glsavegame_entrypoint_7(s32 arg0);
    s16 func_8001B668(s32, s32);
    void *func_8001B798(s16);

    if (func_800D3770() != 0) {
        _glsavegame_entrypoint_7(D_8012B3F0.current_slot);
    }
    if (D_8012B3F0.backup_state == 1) {
        D_8012B3F0.backup_handle = func_8001B668(0, 0x1C0);
        _glgamedata_entrypoint_1(func_8001B798(D_8012B3F0.backup_handle));
        D_8012B3F0.saved_slot = D_8012B3F0.current_slot;
        D_8012B3F0.saved_option = (u8) D_8012B3F0.mode_option;
        D_8012B3F0.saved_game_mode = (u8) D_8012B3F0.game_mode;
        D_8012B3F0.current_slot = -1;
        D_8012B3F0.backup_state = 2U;
    }
}

s32 func_800D3934(void) {
    BT_IDO_ONLY(extern s8 D_8012B3F2;)
    return BT_DATA_FIELD(D_8012B3F0.game_mode, *(u8 *)&D_8012B3F2) == 1;
}

s32 func_800D3948(void) {
    BT_IDO_ONLY(extern s8 D_8012B3F2;)
    return BT_DATA_FIELD(D_8012B3F0.game_mode, *(u8 *)&D_8012B3F2) == 3;
}

s32 func_800D395C(void) {
    BT_IDO_ONLY(extern s8 D_8012B3F2;)
    return BT_DATA_FIELD(D_8012B3F0.game_mode, *(u8 *)&D_8012B3F2) == 2;
}

void func_800D3970(void) { void func_800D37D4(void); void func_800D3A14(s32); void func_800D3CF8(s32); void func_800D3D10(s32); func_800D37D4(); func_800D3A14(1); func_800D3CF8(0); func_800D3D10(1); }

void func_800D39A8(void) {
    s16 func_800B2DC0(s32, s32);
    extern s16 D_8012B3FC;
    D_8012B3FC = func_800B2DC0(sizeof(AttractCommand), 1);
}

void func_800D39D0(s32 arg0) {
    BT_IDO_ONLY(extern s8 D_8012B3F2;)
    BT_DATA_FIELD(D_8012B3F0.game_mode, D_8012B3F2) = arg0;
}

void func_800D39DC(s32 arg0) {
    BtIntPtr func_800D3B6C(s32, AttractCallback, s32, s32, s32);
    if (arg0 >= 0) {
        func_800D3B6C(1, (AttractCallback) func_800D39D0, arg0, 0, 0);
    }
}

void func_800D3A14(s32 arg0) {
    BT_IDO_ONLY(extern s8 D_8012B3F3;)
    BT_DATA_FIELD(D_8012B3F0.mode_option, D_8012B3F3) = arg0;
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
    BT_IDO_ONLY(extern s8 D_8012B3F3;)
    return (u8)BT_DATA_FIELD(D_8012B3F0.mode_option, D_8012B3F3);
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
}

void func_800D3CF8(s32 arg0) {
    BT_IDO_ONLY(extern s8 D_8012B3F4;)
    BT_DATA_FIELD(D_8012B3F0.option4, D_8012B3F4) = arg0;
}

u32 func_800D3D04(void) {
    BT_IDO_ONLY(extern s8 D_8012B3F4;)
    return BT_DATA_FIELD(D_8012B3F0.option4, *(u8 *)&D_8012B3F4);
}

void func_800D3D10(s32 arg0) {
    BT_IDO_ONLY(extern s8 D_8012B3F5;)
    BT_DATA_FIELD(D_8012B3F0.option5, D_8012B3F5) = arg0;
}

u32 func_800D3D1C(void) {
    BT_IDO_ONLY(extern s8 D_8012B3F5;)
    return BT_DATA_FIELD(D_8012B3F0.option5, *(u8 *)&D_8012B3F5);
}

s32 func_800D3D28(void) {
    if (D_8012B3F0.backup_state != 0) {
        return 0;
    }
    D_8012B3F0.backup_state = 1U;
    return 1;
}

int func_800D3D58(void) { switch (D_8012B3F0.backup_state) { case 1: D_8012B3F0.backup_state = 0; return 1; case 2: D_8012B3F0.backup_state = 3; return 1; default: return 0; } }

/* extern */

s32 func_800D3DA4(s32 arg0) {
    s32 func_800F54F0(BtIntPtr);
    return func_800F54F0(arg0);
}
