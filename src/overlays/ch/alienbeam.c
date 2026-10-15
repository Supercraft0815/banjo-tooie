#include "common.h"

OSThread *chalienbeam_entrypoint_0(void)
{
    extern u8 D_808001A0_chalienbeam[];

    return (OSThread *) D_808001A0_chalienbeam;
}

/* extern */

void func_8080000C_chalienbeam(Actor *arg0) {
    s32 _subaddiefade_entrypoint_1(Actor *, s32);
    void func_800EE7F8(f32 *, f32 *);
    struct BeamFlags {
        u8 unk78;
        u8 unk79;
        u8 state : 2;
        u8 rest : 6;
    };

    func_800EE7F8((f32 *)&arg0->actorData[0], arg0->position);
    arg0->position[1] += 600.0f;
    func_800EE7F8((f32 *)&arg0->actorData[4], arg0->position);
    arg0->unk58 = 3.0f;
    ((struct BeamFlags *)&arg0->unk78)->state = 2;
    _subaddiefade_entrypoint_1(arg0, 0xC0);
}

/* extern */

void func_80102424(Actor *, s32);

void func_80800088_chalienbeam(Actor *arg0) {
    u8 func_800D9078(f32 *);
    void func_800EFE50(f32 *, f32 *, f32 *, f32);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    s32 sp2C;

    if (arg0->unk70_10 == 1) {
        sp2C = func_800D9078(&arg0->unk58);
        func_800EFE50(arg0->position, (f32 *)&arg0->actorData[4], (f32 *)&arg0->actorData[0], func_800F12D4(arg0->unk58, 0.0f, 3.0f, 1.0f, 0.0f));
        if (sp2C != 0) {
            func_80102424(arg0, 2);
        }
    }
}

/* extern */

s32 func_80800110_chalienbeam(Actor *arg0, s32 arg1, s32 arg2) {
    switch (arg1) {
    case 0x4F:
        _subaddiefade_entrypoint_3(arg0);
        func_80102424(arg0, 3);
        break;
    default:
        return 0;
    }
    return 1;
}
void func_8080015C_chalienbeam(Actor *arg0, void *arg1) {
    void func_800E3A58(f32 *);
    void func_80101870(Actor *, void *);
    f32 sp1C[3];

    func_800E3A58(sp1C);
    arg0->rotation[1] = sp1C[1];
    func_80101870(arg0, arg1);
}
