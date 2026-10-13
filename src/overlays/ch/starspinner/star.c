#include "common.h"

OSThread *chstarspinnerstar_entrypoint_0(void)
{
    extern u8 D_808006B0_chstarspinnerstar[];

    return (OSThread *) D_808006B0_chstarspinnerstar;
}

void func_8080000C_chstarspinnerstar(Actor *arg0) {
    s32 _chstarspinnerctrl_entrypoint_4(Actor *, f32 *, s32);
    s32 _glcutDll_entrypoint_20(void);
    void _subaddieaudioloop_entrypoint_0(Actor *, f32);
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    f32 func_800136E4(f32);
    void func_800C4B64(f32);
    f32 func_800D8FF8(void);
    s32 func_800DA298(s32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_80101FDC(Actor *, u32);
    s32 func_80800454_chstarspinnerstar(Actor *, f32);
    f32 *func_80800660_chstarspinnerstar(s32);
    extern u32 D_808006F8_chstarspinnerstar[];
    f32 dt;
    s32 enabled;
    s32 playing;

    dt = func_800D8FF8();
    enabled = func_800DA298(0xEA) || _glcutDll_entrypoint_20();
    arg0->actorData[6] = _chstarspinnerctrl_entrypoint_4(arg0, func_80800660_chstarspinnerstar((s32)arg0), arg0->actorData[6]);
    switch (arg0->unk70_10) {
        case 1:
            if (enabled && arg0->unk64_20) {
                func_80101FDC(arg0, 2);
                arg0->unk58 = 1.5f;
            }
            break;
        case 2: {
            ((f32 *)arg0->actorData)[7] = ((f32 *)arg0->actorData)[4] * (f32)(func_800DA298(0x679) ? 30 : 80);
            arg0->rotation[1] = func_800136E4(dt * ((f32 *)arg0->actorData)[7] + arg0->rotation[1]);
            func_80800454_chstarspinnerstar(arg0, dt);
            if (!arg0->unk64_20 || !enabled) {
                arg0->unk58 -= dt;
                if (arg0->unk58 < 0.0f || !enabled) {
                    if (((f32 *)arg0->actorData)[5] > 0.0f) {
                        ((f32 *)arg0->actorData)[5] = -((f32 *)arg0->actorData)[5];
                    }
                    func_80101FDC(arg0, 3);
                }
            } else {
                arg0->unk58 = 1.5f;
            }
            break;
        }
        case 3: {
            ((f32 *)arg0->actorData)[7] = ((f32 *)arg0->actorData)[4] * (f32)(func_800DA298(0x679) ? 30 : 80);
            arg0->rotation[1] = func_800136E4(dt * ((f32 *)arg0->actorData)[7] + arg0->rotation[1]);
            if (func_80800454_chstarspinnerstar(arg0, dt)) {
                arg0->position[1] = ((f32 *)arg0->actorData)[1];
                func_80101FDC(arg0, 1);
            }
            if (arg0->unk64_20 && enabled) {
                func_80101FDC(arg0, 2);
                arg0->unk58 = 1.5f;
            }
            break;
        }
    }
    arg0->unk64_20 = 0;
    playing = enabled && (s32)arg0->unk70_10 >= 2;
    if (playing || (!playing && arg0->unk5F)) {
        f32 pitch;
        pitch = func_800F10B4(arg0->position[1] - ((f32 *)arg0->actorData)[1], 0.0f, 1900.0f, 0.8f, 1.2f);
        func_800C4B64(pitch);
        _subaddieaudioloop_entrypoint_4(arg0, arg0->position, playing, D_808006F8_chstarspinnerstar);
        _subaddieaudioloop_entrypoint_0(arg0, pitch);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/starspinner/star/func_80800320_chstarspinnerstar.s")

/* extern */

s32 func_808003F8_chstarspinnerstar(Actor *arg0, s32 arg1, volatile s32 arg2) {
    void func_808005F8_chstarspinnerstar(void **arg0, s32 arg1);
    switch (arg1) {
    case 0x91:
        arg0->unk64_20 = 1;
        break;
    case 0x1F:
        func_808005F8_chstarspinnerstar((void **)arg0, arg2);
        break;
    default:
        return 0;
    }
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/starspinner/star/func_80800454_chstarspinnerstar.s")

/* extern */

void func_808005F8_chstarspinnerstar(void **arg0, s32 arg1) {
    s32 _glcutDll_entrypoint_20();
    u8 func_800D731C(u16);
    s32 func_800DA298(s32);
    s32 func_800DBE60(u8, s32, s32);
    s32 func_801015D0();
    u8 sp1F;
    u8 temp_v0;

    func_801015D0();
    temp_v0 = func_800D731C((*(u16 *)((s8 *)(*arg0) + (0x14))));
    sp1F = temp_v0;
    if ((temp_v0 != 0) && (func_800DA298(0xEA) == 0) && (_glcutDll_entrypoint_20() == 0)) {
        func_800DBE60(sp1F, 0, 0);
    }
}

f32 *func_80800660_chstarspinnerstar(s32 arg0) {
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    extern f32 B_80800710_chstarspinnerstar;
    f32 *position;
    func_800EE7F8(&B_80800710_chstarspinnerstar, arg0 + 4);
    position = &B_80800710_chstarspinnerstar;
    position[1] = position[1];
    return position;
}
