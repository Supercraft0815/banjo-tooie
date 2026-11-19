#include "common.h"

#include "core2/1E6A190.h"

typedef struct {
    f32 delay;
    u8 eye;
    f32 duration;
} EyeSequenceStep;

EyeSequenceStep D_80117CC0[5] BT_DATA(4, player_eye_sequences, 0x0) = {
    {0.3f, 1, 0.1f},
    {0.034f, 0, 0.1f},
    {0.3f, 1, 0.1f},
    {0.034f, 0, 0.1f},
    {1.0f, 4, 0.0f},
};

EyeSequenceStep D_80117CFC[11] BT_DATA(4, player_eye_sequences, 0x3c) = {
    {2.0f, 1, 0.1f},
    {0.034f, 0, 0.1f},
    {5.0f, 1, 0.06f},
    {0.034f, 0, 0.06f},
    {0.2f, 1, 0.09f},
    {0.034f, 0, 0.09f},
    {1.0f, 1, 0.1f},
    {0.034f, 0, 0.1f},
    {5.0f, 1, 0.1f},
    {0.034f, 0, 0.1f},
    {1.0f, 4, 0.0f},
};

EyeSequenceStep D_80117D80[3] BT_DATA(4, player_eye_sequences, 0xc0) = {
    {0.0f, 1, 0.1f},
    {0.034f, 0, 0.1f},
    {0.0f, 4, 0.0f},
};

s32 func_800908A0(void) {
    return sizeof(BaUnknown20);
}

EyeSequenceStep *func_800908A8(s32 arg0) {
    switch (arg0) {
    case 0:
        return D_80117D80;

    case 1:
        return D_80117CFC;
    
    case 2:
        return D_80117CC0;

    default:
        return NULL;
    }
}

void func_800908F0(PlayerState *self, s32 arg1) {
    self->unk20->unk9 = arg1;
    if (arg1 == 1) {
        func_8009ADF0(self, 4, 0);
    } else {
        func_8009ADF0(self, 4, 1);
    }
}

void func_80090938(PlayerState *self) {
    self->unk20->unk0 = 0;
    self->unk20->unk4 = 0.0f;
    self->unk20->unk8 = 0;
    self->unk20->unk9 = 0;
    func_800908F0(self, 1);

}

void func_8009097C(PlayerState *self, s32 arg1) {
    self->unk20->unk0 = arg1;
    self->unk20->unk8 = 0;
    self->unk20->unk4 = func_800908A8(arg1)->delay;
    func_800908F0(self, 2);
}

void func_800909CC(PlayerState *self) {
    func_8009097C(self, 1);
}

void func_800909EC(PlayerState *self) {
    func_8009097C(self, 0);
}

void func_80090A0C(PlayerState *self) {
    func_8009097C(self, 2);
}

void func_80090A2C(PlayerState *self) {
    func_800908F0(self, 1);
}

void func_80090A4C(PlayerState *arg0) {
    void func_800950FC(PlayerState *, s32, f32);
    f32 mlAbsF(f32);
    f32 remaining;
    EyeSequenceStep *entry;

    remaining = func_800D8FF8();
    while (remaining > 0.0f) {
        arg0->unk20->unk4 -= remaining;
        if (arg0->unk20->unk4 > 0.0f) {
            return;
        }
        remaining = mlAbsF(arg0->unk20->unk4);
        entry = func_800908A8(arg0->unk20->unk0) + arg0->unk20->unk8;
        func_800950FC(arg0, entry->eye, entry->duration);
        entry++;
        if (entry->eye == 4) {
            if (entry->delay == 0.0f) {
                func_800908F0(arg0, 1);
                return;
            }
            entry = func_800908A8(arg0->unk20->unk0);
            arg0->unk20->unk8 = 0;
        } else {
            arg0->unk20->unk8++;
        }
        arg0->unk20->unk4 = entry->delay;
    }
}
