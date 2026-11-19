#include "core2/1E82660.h"

#if defined(BT_NATIVE) && !defined(BT_ILP32)
#include "native_camera.h"

typedef struct PlayerCameraController PlayerCameraController;
static struct {
    s16 players, views;
    u8 controllerUsers[4];
    s16 controllerId[8];
    s32 viewId[8];
    NativeCamera *camera[8];
    PlayerCameraController *controller[8];
} playerViews;

BtIntPtr _gcsectionDll_entrypoint_2(s32);
s32 _gcsectionDll_entrypoint_3(BtIntPtr, s32);
void _gcstatusDll_entrypoint_1(s32);
u8 _gcstatusDll_entrypoint_11(void);
s32 func_800A877C(s32);
s32 func_800A87FC(s32);
BtIntPtr func_800A88C4(s32, BtIntPtr, BtIntPtr);
BtIntPtr func_800A8948(s32);
BtIntPtr func_800A8984(s32);
void *func_8010FB34(void *, s32);
void func_8010FBD4(void *);
s32 func_8010FC38(u8 *);
void func_8010FAEC(BtIntPtr, void *);
void func_8010FE00(void *, s32, s32);
s32 func_8010FE34(BtIntPtr, s32);
void func_80110164(u8 *);
s32 func_800F6438(BtUIntPtr);
f32 func_800EEB40(f32 *, f32 *);
void func_800EE7F8(f32 *, f32 *);
void *func_80110068(void *, void *);
void func_800A91F4(s32);
s32 func_800A9420(s32);

void func_800A8D70(s32 section, s32 unused) {
    _gcstatusDll_entrypoint_1(section);
    playerViews.views = _gcsectionDll_entrypoint_3(_gcsectionDll_entrypoint_2(section), 0x20)
        ? _gcstatusDll_entrypoint_11() : 1;
    for (s32 i = 0; i < playerViews.views; i++) func_800A877C(i);
    for (s32 i = 0; i < 8; i++) {
        playerViews.controllerId[i] = -1;
        playerViews.camera[i] = NULL;
        playerViews.viewId[i] = 0;
    }
    for (s32 i = 0; i < 4; i++) playerViews.controllerUsers[i] = 0;
    playerViews.players = 0;
}

void func_800A8E9C(void) {
    for (s32 i = 0; i < 8; i++) {
        if (playerViews.controller[i]) func_8010FC38((u8 *)playerViews.controller[i]);
    }
}

void func_800A8EF0(BtIntPtr displayList, s32 view) {
    for (s32 i = 0; i < 8; i++) {
        if (playerViews.controller[i] && playerViews.viewId[i] == view)
            func_8010FAEC(displayList, playerViews.controller[i]);
    }
}

void func_800A8F68(void) {
    for (s32 i = 0; i < 8; i++) func_800A91F4(i);
    while (playerViews.views) {
        func_800A87FC(playerViews.views - 1);
        playerViews.views--;
    }
}

s32 func_800A8FDC(void) {
    func_800A877C(playerViews.views);
    return playerViews.views++;
}

s32 func_800A9010(void) {
    for (s32 i = 0; i < 4; i++) if (!playerViews.controllerUsers[i]) return i;
    return -1;
}

s32 func_800A907C(s32 player, s32 controller, s32 view) {
    if (controller == -1) controller = func_800A9010();
    if (controller == -1) return -1;
    if (playerViews.camera[player]) return playerViews.controllerId[player];
    if (view == -1) view = controller;
    if (view >= playerViews.views) view = playerViews.views - 1;
    playerViews.players++;
    playerViews.controllerId[player] = controller;
    playerViews.controllerUsers[controller]++;
    playerViews.camera[player] = func_800CA334();
    playerViews.controller[player] = func_8010FB34(playerViews.camera[player], player);
    playerViews.viewId[player] = view;
    if (playerViews.controllerUsers[controller] == 1)
        func_800A88C4(view, (BtIntPtr)playerViews.camera[player], 0);
    return controller;
}

void func_800A91A8(s32 player) {
    if (player >= 0 && playerViews.controllerId[player] != -1)
        func_800A88C4(playerViews.controllerId[player], (BtIntPtr)playerViews.camera[player], player);
}

void func_800A91F4(s32 player) {
    if (player < 0 || playerViews.controllerId[player] == -1) return;
    s32 id = playerViews.controllerId[player];
    func_8010FBD4(playerViews.controller[player]);
    playerViews.controller[player] = NULL;
    for (s32 view = 0; view < 4; view++) {
        if ((NativeCamera *)func_800A8984(view) == playerViews.camera[player]) func_800A8948(view);
    }
    func_800CA364(playerViews.camera[player]);
    playerViews.camera[player] = NULL;
    playerViews.controllerUsers[id]--;
    playerViews.controllerId[player] = -1;
    playerViews.players--;
}

void func_800A92A8(s32 first, s32 second) {
    for (s32 i = 0; i < 8; i++) {
        if (playerViews.controller[i]) func_8010FE00(playerViews.controller[i], first, second);
    }
}

void func_800A9318(s32 mode) {
    for (s32 i = 0; i < 8; i++) {
        if (playerViews.controller[i]) func_8010FE34((BtIntPtr)playerViews.controller[i], mode);
    }
}

void func_800A9378(void) {
    for (s32 i = 0; i < 8; i++) {
        if (playerViews.controller[i] && func_800A9420(i)) func_80110164((u8 *)playerViews.controller[i]);
    }
}

BtIntPtr func_800A93E4(BtIntPtr player) { return (BtIntPtr)playerViews.controller[player]; }
BtIntPtr func_800A93F8(s32 player) { return (BtIntPtr)playerViews.camera[player]; }
s32 func_800A940C(s32 player) { return playerViews.viewId[player]; }
s32 func_800A9420(s32 player) {
    return playerViews.camera[player] == (NativeCamera *)func_800A8984(playerViews.viewId[player]);
}
s32 func_800A9460(void) { return playerViews.players; }
s32 func_800A946C(void) { return playerViews.views; }

s32 func_800A9478(s32 view) {
    s32 result = -1;
    for (s32 i = 0; i < 8; i++) {
        if (func_800F6438(i) && view == playerViews.viewId[i]) {
            if (func_800A9420(i)) return i;
            result = i;
        }
    }
    return result;
}

void func_800A9514(f32 *nearest, f32 *position) {
    f32 best = 3.4028235e+38f;
    for (s32 i = 0; i < 8; i++) {
        if (playerViews.camera[i]) {
            f32 candidate[3];
            func_800CA7E4(playerViews.camera[i], candidate);
            f32 distance = func_800EEB40(candidate, position);
            if (distance < best) {
                best = distance;
                func_800EE7F8(nearest, candidate);
            }
        }
    }
}

void func_800A95C4(s32 unused0, s32 unused1, s32 unused2) {
    for (s32 i = 0; i < 8; i++) {
        NativeCamera *old = playerViews.camera[i];
        if (old) {
            BtUIntPtr address = (BtUIntPtr)old;
            u8 attached[4];
            for (s32 view = 0; view < 4; view++) attached[view] = (NativeCamera *)func_800A8984(view) == old;
            playerViews.camera[i] = func_800CA384(old);
            if ((BtUIntPtr)playerViews.camera[i] != address) {
                for (s32 view = 0; view < 4; view++) {
                    if (attached[view]) func_800A88C4(view, (BtIntPtr)playerViews.camera[i], 0);
                }
            }
        }
        if (playerViews.controller[i]) {
            playerViews.controller[i] = func_80110068(playerViews.controller[i], playerViews.camera[i]);
        }
    }
}

s32 func_800A965C(void) { return 4 - playerViews.views; }
s32 func_800A9670(s32 *ids) {
    s32 count = 0;
    for (s32 i = 0; i < 4; i++) if (!playerViews.controllerUsers[i]) ids[count++] = i;
    return count;
}
s32 func_800A96F0(s32 controller) {
    for (s32 i = 0; i < 8; i++) if (playerViews.controllerId[i] == controller) return i;
    return -1;
}
s32 func_800A9768(s32 controller) {
    s32 player = func_800A96F0(controller);
    return player >= 0 ? playerViews.viewId[player] : -1;
}
#endif
