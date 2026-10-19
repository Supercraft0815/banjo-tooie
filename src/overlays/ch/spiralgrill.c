#include "common.h"

OSThread *chspiralgrill_entrypoint_0(void)
{
    extern u8 D_80800180_chspiralgrill[];

    return (OSThread *) D_80800180_chspiralgrill;
}

void func_8080000C_chspiralgrill(Actor *arg0) {
    void func_80109EEC(s16 *arg0, s32 arg1);
    void func_8010A800(Actor*, s32);
    func_8010A800(arg0, 0);
    func_80109EEC((s16 *) arg0, 0x40);
}

s32 func_8080003C_chspiralgrill(Actor *arg0, s32 arg1, s32 arg2) {
    void _capod_entrypoint_13(Unk80132ED0 *, Unk80132ED0 *, u32, u32);
    s32 _chexploder_entrypoint_14(Actor *, s32);
    void _chexploder_entrypoint_3(void *, void *, u32);
    s32 _chexploder_entrypoint_6(Actor *, f32, f32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    Actor *_subaddiefind_entrypoint_2(s32, s32);
    s32 func_800DA544(s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    void *func_80101080(void);
    Actor *func_80106790(Unk80132ED0 *);
    extern u8 D_808001C8_chspiralgrill[];
    f32 position[3];
    s32 type;
    Actor *found;
    Actor *exploder;

    switch (arg1) {
    case 0x40:
        type = 0x10;
        func_800EE7F8(position, arg0->position);
        func_800EF1B8(position, arg0->rotation[1], 300.0f);
        position[1] += 120.0f;
        _chexploder_entrypoint_3(arg0, position, 0xC);
        found = _subaddiefind_entrypoint_2(0x51A, 0);
        if (found != NULL) {
            type = 0x11;
        }
        _capod_entrypoint_13(found != NULL ? found->unk0 : arg0->unk0,
                            arg0->unk0, 0x1A, type);
        func_800DA544(0x33);
        break;
    case 0x90:
        exploder = func_80106790(func_80101080());
        _subaddieaudioquick_entrypoint_2(arg0, arg0->position, D_808001C8_chspiralgrill);
        _chexploder_entrypoint_6(exploder, 600.0f, 800.0f);
        _chexploder_entrypoint_14(exploder, 3);
        break;
    default:
        return 0;
    }
    return 1;
}
