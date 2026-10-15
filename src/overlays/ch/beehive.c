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

s32 func_80800180_chbeehive(Actor *arg0) {
    s32 _subaddieaudioquick_entrypoint_0(u8, s32);
    s32 func_800C2E04(void);
    void func_800C301C(u8, s32);
    void func_800C3058(u8, s32);
    void func_800C31DC(u8, f32);
    void func_800C330C(u8, s32);
    void func_800C3584(u8, f32, f32);
    void func_800C35E8(u8, f32[3]);
    void func_800C3BDC(u8);
    void func_800C3CE8(u8);
    s32 func_80101E4C(Actor *, f32 *);
    f32 func_80101F24(Actor *);
    extern f32 D_80800364_chbeehive;
    struct {
        u8 prefix[0x70];
        u32 unused : 31;
        u32 active : 1;
    } *flags = (void *)arg0;
    u8 index;

    if (func_80101E4C(arg0, &D_80800364_chbeehive) != 0) {
        index = arg0->unk5F;
        if (index == 0) {
            arg0->unk5F = func_800C2E04();
            func_800C301C(arg0->unk5F, 0x447);
            func_800C3058(arg0->unk5F, 0x2EE0);
            func_800C35E8(arg0->unk5F, arg0->position);
            func_800C3584(arg0->unk5F, 300.0f, 1500.0f);
        }
        index = arg0->unk5F;
        if (index != 0) {
            func_800C3CE8(index);
            func_800C31DC(arg0->unk5F, func_80101F24(arg0) + 0.5f);
            func_800C330C(arg0->unk5F, 3);
            _subaddieaudioquick_entrypoint_0(arg0->unk5F, flags->active);
            func_800C3BDC(arg0->unk5F);
        }
    }
    return;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/beehive/func_80800268_chbeehive.s")

OSThread *chbeehive_entrypoint_0(void)
{
    extern u8 D_80800374_chbeehive[];

    return (OSThread *) D_80800374_chbeehive;
}
