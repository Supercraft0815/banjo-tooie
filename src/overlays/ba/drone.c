#include "overlays/ba/drone.h"
#include "overlays/ba/data.h"
#include "overlays/ba/flag.h"
#include "overlays/ba/move/goto.h"
#include "core2/1E66990.h"
#include "player.h"
#ifdef BT_NATIVE
#include "core2/1EC8070.h"
#else
void func_800EE7F8(f32 *, f32 *);
void func_800EFD24(f32 *, PlayerState *);
#endif

s32 func_8009BAF4(void *);
f32 func_800EEFFC(void *);
void func_800EFB24(void *, void *, void *);

#ifndef BT_NATIVE
typedef char BaDroneSizeCheck[sizeof(BaDrone) == 0x4C ? 1 : -1];
typedef char BaDroneOffsetCheck[offsetof(PlayerState, drone) == 0x54 ? 1 : -1];
#endif

s32 badrone_entrypoint_0(void) {
    return sizeof(BaDrone);
}

u8 badrone_entrypoint_1(PlayerState *self) {
    extern u8 D_80800630_badrone[];
    return D_80800630_badrone[self->drone->type];
}

void badrone_entrypoint_2(PlayerState *self, f32 output[3]) {
    func_800EE7F8(output, self->drone->look_at);
}

s32 badrone_entrypoint_3(PlayerState *self) {
    return self->drone->type;
}

void badrone_entrypoint_4(PlayerState *self) {
    BaDrone *drone;
    drone = self->drone;
    drone->type = drone->pending_type;
}

void badrone_entrypoint_5(PlayerState *self) {
    self->drone->unk4 = 0;
    self->drone->unk5 = 1;
    self->drone->unk8 = 1.0f;
#ifdef BT_NATIVE
    func_800EFD24(self->drone->destination);
#else
    /* Keep IDO's original unused argument and register allocation. */
    func_800EFD24(self->drone->destination, self);
#endif
    self->drone->unkC = 1.0f;
    self->drone->callback = NULL;
}

void badrone_entrypoint_6(PlayerState *self) {
    BaDroneCallback callback;
    BaDrone *drone;
    drone = self->drone;
    callback = drone->callback;
    if (callback != NULL) {
        callback(drone->callback_context, self->unk184, self);
    }
}

u32 badrone_entrypoint_7(PlayerState *self) {
    return self->drone->unk4;
}

void badrone_entrypoint_8(PlayerState *self, f32 destination[3], f32 *arg2, f32 *arg3) {
    func_800EE7F8(destination, self->drone->destination);
    *arg2 = self->drone->unk8;
    *arg3 = self->drone->unkC;
}

u32 badrone_entrypoint_9(PlayerState *self) {
    return self->drone->unk5;
}

void badrone_entrypoint_10(PlayerState *self, s32 value) {
    self->drone->unk4 = value;
}

void badrone_entrypoint_11(PlayerState *self, BaDroneCallback callback, uintptr_t context) {
    self->drone->callback = callback;
    self->drone->callback_context = context;
}

void badrone_entrypoint_12(PlayerState *self, s32 value) {
    self->drone->unk5 = value;
}

void badrone_entrypoint_13(PlayerState *self, f32 destination[3]) {
    func_800EE7F8(self->drone->destination, destination);
    if (self->drone->type == 1 && func_8009BAF4(self) == 0xC) {
        _bamovegoto_entrypoint_12(self, destination);
    }
}

void badrone_entrypoint_14(PlayerState *self, f32 destination[3], f32 arg2) {
    func_800EE7F8(self->drone->destination, destination);
    self->drone->unkC = arg2;
    self->drone->unk8 = 0.0f;
    self->drone->pending_type = 1;
    bs_setState(self, _badata_entrypoint_21(self));
}

void badrone_entrypoint_15(PlayerState *self, f32 destination[3], f32 arg2) {
    func_800EE7F8(self->drone->destination, destination);
    self->drone->unk8 = arg2;
    self->drone->unkC = 0.0f;
    self->drone->pending_type = 1;
    bs_setState(self, _badata_entrypoint_21(self));
}

void badrone_entrypoint_16(PlayerState *self, f32 destination[3], f32 speed) {
    f32 position[3];
    f32 delta[3];
    func_8009C128(self, position);
    func_800EFB24(delta, destination, position);
    badrone_entrypoint_15(self, destination, func_800EEFFC(delta) / speed);
}

BanjoStateId func_80800348_badrone(PlayerState *self, s32 type) {
    self->drone->pending_type = type;
    return _badata_entrypoint_21(self);
}

BanjoStateId badrone_entrypoint_17(PlayerState *self) {
    self->drone->pending_type = 7;
    return _badata_entrypoint_23(self);
}

BanjoStateId badrone_entrypoint_18(PlayerState *self, Unk80132ED0 *marker) {
    self->drone->marker = marker;
    return func_80800348_badrone(self, 0xC);
}

BanjoStateId badrone_entrypoint_19(PlayerState *self) {
    return func_80800348_badrone(self, 0xD);
}

BanjoStateId badrone_entrypoint_20(PlayerState *self, f32 target[3], s32 arg2) {
    self->drone->unk30 = arg2;
    func_800EE7F8(self->drone->target, target);
    return func_80800348_badrone(self, 8);
}

BanjoStateId badrone_entrypoint_21(PlayerState *self) {
    self->drone->pending_type = 15;
    return _badata_entrypoint_22(self);
}

BanjoStateId badrone_entrypoint_22(PlayerState *self, f32 target[3]) {
    func_800EE7F8(self->drone->target, target);
    return func_80800348_badrone(self, 0xB);
}

BanjoStateId badrone_entrypoint_23(PlayerState *self, f32 target[3]) {
    func_800EE7F8(self->drone->target, target);
    return func_80800348_badrone(self, 0xA);
}

BanjoStateId badrone_entrypoint_24(PlayerState *self) {
    return func_80800348_badrone(self, 2);
}

BanjoStateId badrone_entrypoint_25(PlayerState *self) {
    return func_80800348_badrone(self, 9);
}

BanjoStateId badrone_entrypoint_26(PlayerState *self) {
    self->drone->pending_type = 3;
    return _badata_entrypoint_23(self);
}

BanjoStateId badrone_entrypoint_27(PlayerState *self) {
    return func_80800348_badrone(self, 6);
}

BanjoStateId badrone_entrypoint_28(PlayerState *self) {
    baflag_clear(self, BA_FLAG_19);
    return func_80800348_badrone(self, 4);
}

BanjoStateId badrone_entrypoint_29(PlayerState *self) {
    return func_80800348_badrone(self, 0xE);
}

int badrone_entrypoint_30(PlayerState *self) {
    return badrone_entrypoint_3(self) == 2 && !player_inWater(self);
}

s32 badrone_entrypoint_31(PlayerState *self) {
    if (self->drone->type == 1) {
        return 1;
    }
    return 0;
}

void badrone_entrypoint_32(PlayerState *self) {
    BaDrone *drone;
    self->drone->pending_type = 0;
    drone = self->drone;
    drone->type = drone->pending_type;
}

void badrone_entrypoint_33(PlayerState *self, f32 look_at[3]) {
    func_800EE7F8(self->drone->look_at, look_at);
}
