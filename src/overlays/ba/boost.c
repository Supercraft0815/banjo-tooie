#include "common.h"

#include "overlays/ba/boost.h"

s32 baboost_entrypoint_0(void) {
    return sizeof(BaBoost);
}

s32 baboost_entrypoint_1(PlayerState *self) {
    s32 count;
    s32 i;

    count = 0;
    for (i = 0; i < 5; i++) {
        if (self->boost->unk8[i] != 0.0f) {
            count++;
        }
    }
    return count;
}

s32 baboost_entrypoint_2(PlayerState *self, f32 arg1);
s32 baboost_entrypoint_2(PlayerState *self, f32 arg1) {
    f32 threshold;
    s32 i;

    i = 0;
    threshold = arg1 - 0.25f;
    while (i < 5) {
        if (threshold < self->boost->unk8[i]) {
            self->boost->unk4 = arg1;
            return 0;
        }
        i++;
    }
    for (i = 0; i < 5; i++) {
        if (self->boost->unk8[i] == 0.0f) {
            self->boost->unk8[i] = arg1;
            return 1;
        }
    }
    self->boost->unk4 = arg1;
    return 0;
}

void baboost_entrypoint_3(PlayerState *self) {
    s32 i;

    for (i = 0; i < 5; i++) {
        self->boost->unk8[i] = self->boost->unk8[i] = 0.0f;
    }
    self->boost->unk0 = self->boost->unk4 = 0.0;
}

void baboost_entrypoint_4(PlayerState *self, s32 arg1) {
    self->boost->unk0 = arg1;
    if(self->boost->unk0 == 0) {
        _baboost_entrypoint_3(self);
    }
} 

void baboost_entrypoint_5(PlayerState *self) {
    s32 i;
    f32 tmp_f2;
    if (self->boost->unk0){
        for ( i = 0; i < 5; i++) {
            func_800D9078(&self->boost->unk8[i]);
        }
        if (self->boost->unk4 != 0.0f) {
            tmp_f2 = self->boost->unk4;
            self->boost->unk4 = 0.0f;
            baboost_entrypoint_2(self, tmp_f2);
        }
    }
}
