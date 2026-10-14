#include "common.h"

void func_80800000_chbeehive(Actor *arg0) {
    s32 _subaddiesect_entrypoint_1(Actor *);
    void _subaddiesect_entrypoint_2(Actor *, s32, s32);
    void func_800EE7F8(f32 *, f32 *);
    s32 sector;

    func_800EE7F8((f32 *)&arg0->actorData[4], arg0->position);
    arg0->unk50 = arg0->rotation[1];
    sector = _subaddiesect_entrypoint_1(arg0);
    arg0->actorData[0] = sector;
    arg0->unk74_7 = arg0->unk74_7 - 50;
    if (sector != -1) {
        _subaddiesect_entrypoint_2(arg0, sector, 0);
    }
}

/* extern */
void func_80800078_chbeehive(Actor *arg0) {
    s32 _subaddiesect_entrypoint_0(Actor*, s32, s32);
    s32 func_80800180_chbeehive(Actor *);
    u32 temp_a1;
    struct {
        u32 upper : 29;
        u32 active : 1;
        u32 lower : 2;
    } *flags = (void *)&arg0->unk78;
    if (!flags->active && ((temp_a1 = arg0->actorData[0], (temp_a1 == -1U)) || (_subaddiesect_entrypoint_0(arg0, temp_a1, 11) != 0))) {
        func_80800180_chbeehive(arg0);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/beehive/func_808000CC_chbeehive.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/beehive/func_80800180_chbeehive.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/beehive/func_80800268_chbeehive.s")

OSThread *chbeehive_entrypoint_0(void)
{
    extern u8 D_80800374_chbeehive[];

    return (OSThread *) D_80800374_chbeehive;
}
