#include "common.h"

OSThread *chtntminecelldoor_entrypoint_0(void)
{
    extern u8 D_80800140_chtntminecelldoor[];

    return (OSThread *) D_80800140_chtntminecelldoor;
}

void func_8080000C_chtntminecelldoor(s32 arg0)
{
    _subaddiefade_entrypoint_14();
    func_8010A63C(arg0);
}
s32 func_80800034_chtntminecelldoor(Actor *arg0, s32 arg1, volatile s32 arg2) {
    void _chexploder_entrypoint_3(void *, void *, u32);
    void _chtntdetonator_entrypoint_1(Actor *, s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    void func_808000F4_chtntminecelldoor(s32);
    f32 sp1C[3];

    switch (arg1) {
    case 5:
        func_800EE7F8(sp1C, arg0->position);
        func_800EF1B8(sp1C, arg0->rotation[1], 100.0f);
        sp1C[1] += 25.0f;
        _chexploder_entrypoint_3(arg0, sp1C, 0x28);
        break;
    case 0x90:
        func_808000F4_chtntminecelldoor((s32)arg0);
        break;
    case 0x95:
        _chtntdetonator_entrypoint_1(arg0, 0x85);
        break;
    default:
        return 0;
    }
    return 1;
}

/* extern */

void func_808000F4_chtntminecelldoor(s32 arg0) {
    s32 _chexploder_entrypoint_12(s32, s32);
    s32 _chexploder_entrypoint_13(s32, s32);
    s32 func_800DA544(s32);
    s32 func_80101080();
    s32 func_80106790(s32);
    s32 sp1C;
    s32 temp_v0;

    temp_v0 = func_80106790(func_80101080());
    sp1C = temp_v0;
    _chexploder_entrypoint_13(temp_v0, 1);
    _chexploder_entrypoint_12(sp1C, 0x3C);
    func_800DA544(0x85);
}
