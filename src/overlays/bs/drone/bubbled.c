#include "overlays/bs/drone/bubbled.h"
#include "overlays/ba/drone.h"
#include "overlays/ba/data.h"
#include "core2/1E72EA0.h"
#include "core2/1E76CC0.h"
#include "core2/1E77A20.h"
#include "core2/1E78BF0.h"
#include "core2/1EB2840.h"
#include "core2/1ECA640.h"
#include "core2/1EDA900.h"
BT_LP64_ONLY(void baanim_playForDuration_loopSmooth(PlayerState *, AssetId, f32);)
s32 func_80800000_bsdronebubbled(PlayerState *self) {
    s32 result;
    result = func_8010114C(self->drone->marker, 0x2C, self->unk184);
    self->drone->marker = NULL;
    return result;
}

void bsdronebubbled_entrypoint_0(PlayerState *self) {
    if (self->drone->marker != NULL) {
        func_80800000_bsdronebubbled(self);
    }
}

void bsdronebubbled_entrypoint_1(PlayerState *self) {
    f32 duration;
    AssetId animation;

    _badata_entrypoint_0(self, &animation, &duration);
    baanim_playForDuration_loopSmooth(self, animation, duration);
    self->drone->unk44 = duration;
    self->drone->unk40 = 0.0f;
    func_8009FFD8(self, 1, 1, 3, 7);
    func_8009D9D4(self);
}

void bsdronebubbled_entrypoint_2(PlayerState *self) {
    switch (func_8009E6EC(self)) {
    case 0x21:
        func_80099B94(self);
        break;
    case 0x6F:
        func_8009E830(self, 1);
        break;
    case 0x70:
        bs_setState(self, _badata_entrypoint_34(self));
        break;
    case 0x7B:
        self->drone->unk40 = func_800F13F0(1.0f, self->drone->unk40 + 0.2f);
        break;
    default:
        func_80099B94(self);
        break;
    }
}

void bsdronebubbled_entrypoint_3(PlayerState *self) {
    f32 duration;
    s32 pad;
    AnimCtrl *control;

    duration = self->drone->unk44;
    func_800F1574(&self->drone->unk40, func_800D8FF8() * 0.8333333f);
    control = baanim_getAnimCtrlPtr(self); anctrl_setDuration(control, func_800F1214(self->drone->unk40, duration, duration * 0.33333334f));
}

void bsdronebubbled_entrypoint_4(PlayerState *self) {
}

void bsdronebubbled_entrypoint_5(PlayerState *self) {
    f32 duration;
    AssetId animation;

    _badata_entrypoint_0(self, &animation, &duration);
    duration = duration + duration;
    baanim_playForDuration_loopSmooth(self, animation, duration);
    func_8009FFD8(self, 1, 1, 3, 7);
}

void bsdronebubbled_entrypoint_6(PlayerState *self) {
    func_80099B94(self);
}

void bsdronebubbled_entrypoint_7(PlayerState *self) {
}
