#include "common.h"

void subaddiecustomhits_entrypoint_0(void **arg0, s32 arg1) {
    void func_800EC358(void *, s32);

    func_800EC358(*arg0, arg1);
    (*(u8 *)((s8 *)(arg0) + (0x74))) = (u8) (((*(u8 *)((s8 *)(arg0) + (0x74))) & 0xFF7F) | 0x80);
}

OSThread *subaddiecustomhits_entrypoint_1(void)
{
    extern u8 D_80800350_subaddiecustomhits[];

    return (OSThread *) D_80800350_subaddiecustomhits;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/customhits/subaddiecustomhits_entrypoint_2.s")

/* extern */

s32 subaddiecustomhits_entrypoint_3(Actor *arg0, f32 arg1[3], f32 arg2) {
    s32 func_800EFFB4(f32 *, f32, f32 *);
    void func_80103DFC(Actor *, f32 *);
    f32 sp1C[3];

    func_80103DFC(arg0, sp1C);
    return func_800EFFB4(sp1C, (f32)(u16)arg0->pad68 * arg0->scale + arg2, arg1) == 0;
}

/* extern */

s32 subaddiecustomhits_entrypoint_4(Actor *arg0, f32 *arg1, f32 *arg2) {
    s32 func_8001211C(void);
    void func_800EE7F8(f32 *, f32 *);
    f32 func_80103F38(Actor *, f32 *);
    OSThread *func_80104124(void);
    struct {
        f32 position[3];
        f32 value;
        s32 id;
        s32 frame;
    } *hit;
    f32 value;
    struct MarkerId {
        u8 pad[0x12];
        u16 id : 15;
        u16 flag : 1;
    };

    hit = (void *)func_80104124();
    if (hit->id == ((struct MarkerId *)arg0->unk0)->id) {
        if (func_8001211C() == hit->frame) {
            func_800EE7F8(arg1, hit->position);
            if (arg2 != NULL) {
                *arg2 = hit->value;
            }
            return 1;
        }
    }
    value = func_80103F38(arg0, arg1);
    if (arg2 != NULL) {
        *arg2 = value;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/customhits/subaddiecustomhits_entrypoint_5.s")
