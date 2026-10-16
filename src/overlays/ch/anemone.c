#include "common.h"

OSThread *chanemone_entrypoint_0(void)
{
    extern u8 D_808008D8_chanemone[];

    return (OSThread *) D_808008D8_chanemone;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anemone/func_8080000C_chanemone.s")

/* extern */

void func_80800260_chanemone(Actor *arg0) { s32 _subaddiesect_entrypoint_1(Actor *);
    s32 _subaddiesect_entrypoint_2(void *, s32, s32);
    f32 func_800DC178(f32, f32);
    void func_80102FDC(Actor *, f32);
    s32 temp_v0;

    func_80102FDC(arg0, arg0->scale * 0.5f); arg0->unk54 = 0.0f; ((f32 *)arg0->actorData)[4] = 0.0f; arg0->unk50 = 0.0f; ((f32 *)arg0->actorData)[5] = 0.0f; ((f32 *)arg0->actorData)[7] = func_800DC178(0.5f, 2.0f); temp_v0 = _subaddiesect_entrypoint_1(arg0); arg0->actorData[6] = temp_v0; _subaddiesect_entrypoint_2(arg0, temp_v0, 0);
}

s32 func_808002E8_chanemone(Actor *arg0, s32 arg1, volatile s32 arg2) {
    void func_808005A0_chanemone(Actor *, s32);
    void _subaddiecustomhits_entrypoint_0(Actor *, void *);
    void func_800E0AFC(void *, u8, f32, f32, f32, f32);
    s32 func_8010262C(Unk80132ED0 *, u32);
    extern s32 _chanemone_entrypoint_1;
    s32 model;

    switch (arg1) {
        case 0x3F:
            func_808005A0_chanemone(arg0, arg2);
            return 1;
        case 0x95:
            _subaddiecustomhits_entrypoint_0(arg0, &_chanemone_entrypoint_1);
            return 1;
        case 0x9C:
            model = func_8010262C(arg0->unk0, 1);
            if (model != 0) {
                func_800E0AFC((void *)model, 0x64, 1.0f,
                    ((f32 *)arg0->actorData)[5], ((f32 *)arg0->actorData)[4], 0.0f);
                return 1;
            }
            break;
        default:
            return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anemone/func_808003A8_chanemone.s")

void func_808005A0_chanemone(Actor *arg0, s32 arg1) {
    s32 _subaddieDll_entrypoint_4(void *, s32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    void func_80102424(Actor *, s32);
    void func_8010A570(Actor *);
    extern s32 D_80800954_chanemone;
    u32 state;

    if ((s32)arg0->unk6C_0 == 1) {
        state = arg0->unk70_10;
        if (state == 1) {
            goto activate;
        }
        if (state == 3) {
            goto extend;
        }
        if (state == 4) {
activate:
            _subaddieaudioquick_entrypoint_2(arg0, arg0->position, &D_80800954_chanemone);
            func_80102424(arg0, 2);
            _subaddieDll_entrypoint_4(arg0, 1);
            func_8010A570(arg0);
            goto done;
        }
        goto done;
extend:
        arg0->unk58 = 6.0f;
    }
done:;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/anemone/func_80800648_chanemone.s")

OSThread *chanemone_entrypoint_1(void)
{
    extern u8 D_80800964_chanemone[];

    return (OSThread *) D_80800964_chanemone;
}
