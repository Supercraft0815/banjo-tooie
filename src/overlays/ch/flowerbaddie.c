#include "common.h"

OSThread *chflowerbaddie_entrypoint_0(void)
{
    extern u8 D_80800C14_chflowerbaddie[];

    return (OSThread *) D_80800C14_chflowerbaddie;
}

void func_8080000C_chflowerbaddie(Actor *arg0) {
    void _subaddierouteDll_entrypoint_3(Actor*, void*, f32*);
    void* func_80100094(Actor*, u32);
    _subaddierouteDll_entrypoint_3(arg0, func_80100094(arg0, 0U), arg0->position);
    (*(f32 *)((s8 *)(arg0) + (0x24))) = 600.0f;
    arg0->unk64_20 = 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flowerbaddie/func_8080005C_chflowerbaddie.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flowerbaddie/func_80800380_chflowerbaddie.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flowerbaddie/func_80800610_chflowerbaddie.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flowerbaddie/func_808006A0_chflowerbaddie.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flowerbaddie/func_808007F0_chflowerbaddie.s")

/* extern */

s32 func_808008D4_chflowerbaddie(Actor *arg0) {
    s32 _subaddierouteDll_entrypoint_4(Actor *);
    Unk80132ED0 *_suchase_entrypoint_0(void);
    s32 func_8010C668(Actor *, f32 *, f32, f32);
    s32 func_8010C9FC(f32 *, s32, s32, s32);
    union FlowerBaddieActor {
        Actor actor;
        struct {
            u32 reserved[25];
            u32 : 2;
            u32 blocked : 1;
            u32 : 29;
        } flags;
    };

    if (((union FlowerBaddieActor *)arg0)->flags.blocked) {
        return 0;
    }
    if (_subaddierouteDll_entrypoint_4(arg0) == 0) {
        return 0;
    }
    if (func_8010C9FC(arg0->position, 0x3E8, 0x1F4, -0x32) == 0) {
        return 1;
    }
    if (func_8010C668(arg0, arg0->position, 1000.0f, -200.0f) == 0) {
        return 1;
    }
    return _suchase_entrypoint_0() != arg0->unk0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flowerbaddie/func_80800980_chflowerbaddie.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/flowerbaddie/func_808009F0_chflowerbaddie.s")
