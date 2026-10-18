#include "common.h"

s32 func_80800000_chfactorydrums(Actor *arg0) {
    s32 _subaddiefind_entrypoint_4(s32, u8 **, s32);
    s32 func_800CC338(s32 *, s32, s32);
    union DrumActor {
        Actor actor;
        struct {
            u8 pad[0x70];
            u32 group : 7;
            u32 unused : 15;
            u32 point : 6;
            u32 rest : 4;
        } path;
        struct {
            Unk80132ED0 *unk0;
            s32 position[3];
        } coordinates;
    };
    u8 *actors[10];
    s32 count;
    s32 total = 0;
    s32 i;

    count = _subaddiefind_entrypoint_4(0x3FF, actors, 10);
    for (i = 0; i < count; i++) {
        if (func_800CC338(((union DrumActor *)actors[i])->coordinates.position,
                ((union DrumActor *)arg0)->path.group - 1,
                ((union DrumActor *)arg0)->path.point - 1) != 0) {
            total++;
        }
    }
    count = _subaddiefind_entrypoint_4(0x3F0, actors, 10);
    for (i = 0; i < count; i++) {
        if (((union DrumActor *)actors[i])->actor.unk70_10 == 5) {
            if (func_800CC338(((union DrumActor *)actors[i])->coordinates.position,
                    ((union DrumActor *)arg0)->path.group - 1,
                    ((union DrumActor *)arg0)->path.point - 1) != 0) {
                total++;
            }
        }
    }
    return total < ((s32)arg0->unk74_7 - 50);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/drums/func_80800130_chfactorydrums.s")

/* extern */

void func_808002B8_chfactorydrums(Actor *arg0) {
    s32 _subaddiejoy_entrypoint_6(u8 *, s32);
    s32 func_8001210C(s32);
    s32 func_800D90A4(f32 *);
    f32 func_800DC178(f32, f32);
    void func_80102424(Actor *, s32);
    s32 func_80800000_chfactorydrums(Actor *);
    union FactoryDrumsActor {
        Actor actor;
        struct {
            u8 pad[0x64];
            u32 pad64_30 : 2;
            u32 unk64_29 : 1;
        } flags;
    };
    union FactoryDrumsActor *drum = (union FactoryDrumsActor *)arg0;
    if (drum->flags.unk64_29) {
        if ((func_8001210C(7) != 0) && (arg0->unk74_7 != 0x32) && (func_80800000_chfactorydrums(arg0) != 0) && (_subaddiejoy_entrypoint_6((u8 *)arg0, 1) != 0)) {
            func_80102424(arg0, 5);
        }
    } else if ((func_800D90A4(&arg0->unk58) != 0) && (func_8001210C(7) != 0)) {
        if ((arg0->unk74_7 != 0x32) && (func_80800000_chfactorydrums(arg0) != 0)) {
            func_80102424(arg0, 5);
        }
        arg0->unk58 = func_800DC178(3.0f, 5.0f);
    }
}

void func_808003A8_chfactorydrums(Actor *arg0) {
    void _subaddierouteDll_entrypoint_3(Actor*, void*, f32*);
    void* func_80100094(Actor*, u32);
    _subaddierouteDll_entrypoint_3(arg0, func_80100094(arg0, 0U), arg0->position);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/drums/func_808003DC_chfactorydrums.s")

void chfactorydrums_entrypoint_0(s32 arg0, s32 arg1) {
    s32 func_800BBCB8(s32, s32, s32, s32, s32 *);
    extern s32 D_808011CC_chfactorydrums;
    func_800BBCB8(arg1, 0, 0x3F800000, 1, &D_808011CC_chfactorydrums);
}

void chfactorydrums_entrypoint_1(s32 arg0, s32 arg1) {
    s32 func_800BBCB8(s32, s32, s32, s32, s32 *);
    extern s32 D_80801208_chfactorydrums;
    func_800BBCB8(arg1, 0, 0x3F800000, 1, &D_80801208_chfactorydrums);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/drums/func_80800CD0_chfactorydrums.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/factory/drums/func_80800D90_chfactorydrums.s")

OSThread *chfactorydrums_entrypoint_2(void)
{
    extern u8 D_8080125C_chfactorydrums[];

    return (OSThread *) D_8080125C_chfactorydrums;
}
