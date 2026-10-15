#include "common.h"

OSThread *chvolcanobits_entrypoint_0(void)
{
    extern u8 D_80801154_chvolcanobits[];

    return (OSThread *) D_80801154_chvolcanobits;
}

OSThread *chvolcanobits_entrypoint_1(void)
{
    extern u8 D_8080119C_chvolcanobits[];

    return (OSThread *) D_8080119C_chvolcanobits;
}

OSThread *chvolcanobits_entrypoint_2(void)
{
    extern u8 D_808011E4_chvolcanobits[];

    return (OSThread *) D_808011E4_chvolcanobits;
}

OSThread *chvolcanobits_entrypoint_3(void)
{
    extern u8 D_8080122C_chvolcanobits[];

    return (OSThread *) D_8080122C_chvolcanobits;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/volcanobits/func_80800030_chvolcanobits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/volcanobits/func_80800170_chvolcanobits.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/volcanobits/func_8080027C_chvolcanobits.s")

void func_8080061C_chvolcanobits(u8 *arg0) {
    struct Flags {
        u8 pad[0x64];
        unsigned int : 11;
        unsigned int active : 1;
        unsigned int : 20;
    };
    void func_800CF494(void);
    if (((struct Flags *)arg0)->active) {
        func_800CF494();
        arg0[0x65] &= 0xFFEF;
    }
}

void func_8080065C_chvolcanobits(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/volcanobits/func_80800664_chvolcanobits.s")

void func_8080086C_chvolcanobits(u8 *arg0) {
    void func_800C8B84(s32);
    s32 temp_a1;

    temp_a1 = (*(s32 *)((s8 *)(arg0) + (0x18)));
    if (temp_a1 != 0) {
        func_800C8B84(temp_a1);
        (*(s32 *)((s8 *)(arg0) + (0x18))) = 0;
    }
}

/* extern */

s32 func_808008A4_chvolcanobits(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _chexploder_entrypoint_6(s32, s32, s32);
    void _subaddiefade_entrypoint_3(Actor *);
    Unk80132ED0 *func_80101080(void);
    Actor *func_80106790(Unk80132ED0 *);
    Actor *sp1C;
    Actor *temp_v0;

    if (arg1 == 0x90) {
        temp_v0 = func_80106790(func_80101080());
        sp1C = temp_v0;
        _chexploder_entrypoint_6((s32)temp_v0, 0x44960000, 0x44AF0000);
        _subaddiefade_entrypoint_3(sp1C);
        return 1;
    }
    if (arg1 == 0x95) {
        arg0->actorData[0] = 0;
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/volcanobits/func_80800914_chvolcanobits.s")

/* extern */

void func_808009A8_chvolcanobits(Actor *arg0) {
    s32 _chswitch_entrypoint_7(s32, s32);
    s32 _chswitch_entrypoint_9(s32);
    s32 _subaddiefind_entrypoint_10(Actor *, s32, u32);
    void *func_8080108C_chvolcanobits(void *);
    void *sp24;
    sp24 = func_8080108C_chvolcanobits(arg0);
    _subaddiefind_entrypoint_10(arg0, 0x42A, arg0->unk74_7);
    _chswitch_entrypoint_7((s32) arg0, *(s16 *)((s8 *)sp24 + 6));
    _chswitch_entrypoint_9((s32) arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/volcanobits/func_80800A04_chvolcanobits.s")

void func_80800AEC_chvolcanobits(Actor *arg0) {
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    void* func_80100094(Actor*, u32);
    func_800EE7F8(func_80100094(arg0, 0U), arg0->position);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/volcanobits/func_80800B20_chvolcanobits.s")

/* extern */

int func_80800C5C_chvolcanobits(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _capod_entrypoint_13(s32, s32, s32, s32);
    void func_800187B4(s32, f32, f32, f32);
    void func_800E1378(s32);
    void func_800E13F0(s32, f32);
    void func_800E1410(s32, f32, f32);
    s32 func_800E1540(s32);
    void func_80101FDC(Actor *, u32);
    void func_80103110(void *, s32);
    s32 func_80800EF0_chvolcanobits(void *);
    void *func_8080108C_chvolcanobits(void *);
    s32 sp20[2];
    s32 temp_v0;
    void *temp_s0;

    if (arg1 == 0xA) {
        temp_s0 = func_8080108C_chvolcanobits(arg0);
        temp_v0 = func_800E1540(0);
        sp20[0] = temp_v0;
        func_800E1378(temp_v0);
        func_800E13F0(sp20[0], 5.0f);
        func_800E1410(sp20[0], -5.0f, (*(f32 *)temp_s0) * 0.95f);
        func_800187B4(0, 3.0f, 1.0f, (*(f32 *)temp_s0) * 0.95f);
        func_80101FDC(arg0, 2);
        func_80103110(arg0, 1);
        arg0->unk58 = *(f32 *)temp_s0;
        if (*(s16 *)((s8 *)temp_s0 + 8) != -1) {
            _capod_entrypoint_13((s32)arg0->unk0, 0, *(s16 *)((s8 *)temp_s0 + 8), 0x10);
        }
        return 1;
    }
    if (arg1 == 0x95) {
        func_80800EF0_chvolcanobits(arg0);
        return 1;
    }
    return 0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/volcanobits/func_80800D6C_chvolcanobits.s")

/* extern */

void chvolcanobits_entrypoint_4(s32 arg0, s16 *arg1, s16 *arg2, s32 arg3, Unk80132ED0 *arg4) {
    Actor *func_80106790(Unk80132ED0 *);
    Actor *actor;
    s16 *end;
    s32 i;

    actor = func_80106790(arg4);
    end = (s16 *)(arg3 * 16 + (u32)arg2);
    while (arg2 < end) {
        for (i = 0; i < 3; i++) {
            arg2[i] = arg1[i] + actor->position[i];
        }
        arg2 += 8;
        arg1 += 8;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/volcanobits/func_80800EF0_chvolcanobits.s")

void func_80801040_chvolcanobits(u8 *arg0) {
    s32 _glid_entrypoint_0(s32, s32, s32 *, s32);
    s32 func_800BEA88(s32);
    extern s32 _chvolcanobits_entrypoint_4;
    s32 temp_v0;

    temp_v0 = func_800BEA88(0);
    if (temp_v0 != 0) {
        _glid_entrypoint_0(temp_v0, ((u32) (*(u16 *)((s8 *)(arg0) + (0x76))) >> 7) - 0x31, &_chvolcanobits_entrypoint_4, (*(s32 *)((s8 *)(arg0) + (0))));
    }
}

void *func_8080108C_chvolcanobits(void *arg0) {
    extern s32 D_8080110C_chvolcanobits;
    u32 index = *(u16 *)((u8 *)arg0 + 0x76);
    index = (index >> 7) - 0x32;
    return (void *)((u8 *)&D_8080110C_chvolcanobits + index * 12);
}
