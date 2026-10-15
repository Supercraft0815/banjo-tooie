#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lagoon/fish/func_80800000_chlagoonfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lagoon/fish/func_808001A0_chlagoonfish.s")

void func_80800240_chlagoonfish(Actor *arg0) { func_80100074(arg0, 0U, 0U); }

void func_80800264_chlagoonfish(Actor *arg0)
{
    func_80800240_chlagoonfish(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lagoon/fish/func_80800284_chlagoonfish.s")

/* extern */

typedef union {
    Actor actor;
    struct {
        u8 pad0[0x70];
        u32 unk70_25 : 7;
        u32 pad70_10 : 15;
        u32 unk70_4 : 6;
        u32 pad70_0 : 4;
    } fish;
} LagoonFishActor;

s32 func_808002F8_chlagoonfish(LagoonFishActor *arg0) {
    s32 func_800CC338(f32 (*)[3], s32, s32);
    void func_800EEC30(f32 *, f32, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    f32 sp24[3];
    s32 result;

    func_800EEC30(sp24, arg0->actor.rotation[0], arg0->actor.rotation[1], 200.0f);
    func_800EF04C(sp24, arg0->actor.position);
    result = func_800CC338(&sp24, arg0->fish.unk70_25 - 1, arg0->fish.unk70_4 - 1);
    if (result != -1) {
        arg0->fish.unk70_4 = result + 1;
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lagoon/fish/func_8080038C_chlagoonfish.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lagoon/fish/func_80800908_chlagoonfish.s")

/* extern */

void func_808009FC_chlagoonfish(u8 *arg0) {
    s32 func_800CC63C(s32, s32);
    s32 func_800EE7F8(u8 *, s32);
    u32 temp_v0;

    temp_v0 = (*(u32 *)((s8 *)(arg0) + (0x70)));
    func_800EE7F8(arg0 + 0x18, func_800CC63C((temp_v0 >> 0x19) - 1, ((u32) (temp_v0 << 0x16) >> 0x1A) - 1));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/lagoon/fish/func_80800A44_chlagoonfish.s")

int func_80800AE0_chlagoonfish(Actor *arg0, s32 arg1, u8 *arg2) {
    s32 func_80103140(Actor *, u32, u16);
    extern u8 D_8012762C;
    switch (arg1) {
        case 0x95:
            if (D_8012762C == 0x15) {
                func_80103140(arg0, 0x698U, arg0->unk0->unk16);
            }
            break;
        default:
            return 0;
    }
    return 1;
}

OSThread *chlagoonfish_entrypoint_0(void)
{
    extern u8 D_80800B70_chlagoonfish[];

    return (OSThread *) D_80800B70_chlagoonfish;
}
