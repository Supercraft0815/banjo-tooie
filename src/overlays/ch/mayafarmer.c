#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mayafarmer/func_80800000_chmayafarmer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mayafarmer/func_808000B0_chmayafarmer.s")

/* extern */

void func_80800138_chmayafarmer(void *arg0) {
    s32 _capod_entrypoint_3(s32, void *);
    if ((*(s32 *)((s8 *)(arg0) + (0x6C))) & 0x1FF) {
        _capod_entrypoint_3(0, arg0);
        (*(u16 *)((s8 *)(arg0) + (0x6E))) = (u16) ((*(u16 *)((s8 *)(arg0) + (0x6E))) & 0xFE00);
    }
}

void func_80800180_chmayafarmer(u8 *arg0, u32 arg1, s32 arg2) {
    struct Flags { u8 pad[0x74]; u8 high : 1; u8 flag : 1; u8 low : 6; };
    s32 _subaddiedialog_entrypoint_11(Unk80132ED0*, u32, u32, f32*, u32);
    arg2 |= 4;
    _subaddiedialog_entrypoint_11((*(Unk80132ED0 **)((s8 *)(arg0) + (0))), arg1, arg2, arg0 + 4, 0x2AU);
    ((struct Flags *)arg0)->flag = 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mayafarmer/func_808001CC_chmayafarmer.s")

s32 func_80800228_chmayafarmer(u8 *arg0, s32 arg1, s32 arg2) {
    struct FarmerState {
        u8 pad[0x74];
        u32 flags : 16;
        u32 count : 9;
        u32 other : 7;
    };
    s32 _gcdialogcamera_entrypoint_3(s32 *, f32);
    s32 _suexpression_entrypoint_12(void *, s32, s32);
    s32 _suexpression_entrypoint_7(Actor *, s32, s32);
    void func_800C01A8(s16, s32);
    u32 func_800C07F4(void);
    s32 func_800CBC3C(u8 *);
    s32 func_800CD08C(s32, u8 *);
    s32 func_800D1000(s32, s32, s32 *, s32, s32);
    s32 func_800DA544(s32);
    f32 func_800DC178(f32, f32);
    void *func_80100094(Actor *, u32);
    s32 *func_80108528(s32, u8 *, s32, u8 **);
    void func_80108B04(Actor *, u32);
    void func_80800000_chmayafarmer(u8 *, s32, s32);
    void func_808000B0_chmayafarmer(u8 *, s32, s32, s32);
    void func_808001CC_chmayafarmer(u8 *, s32);
    extern s32 D_8080125C_chmayafarmer[];
    extern u8 D_8080126C_chmayafarmer[];
    s32 count;
    s32 i;

    switch (arg1) {
        default:
            return 0;
        case 0x95:
            _suexpression_entrypoint_7((Actor *)arg0, 1, 0x2A);
            _suexpression_entrypoint_12(func_80100094((Actor *)arg0, 1), 0x42A00000, 0x41F00000);
            func_80108B04((Actor *)arg0, 0);
            break;
        case 0x11:
            if (((u32)*(u16 *)(arg0 + 0x72) >> 10) == 1) {
                func_808001CC_chmayafarmer(arg0, 3);
            }
            break;
        case 0x2E:
            arg0[0x74] &= 0xFFBF;
            if (*(s16 *)&arg2 != 0xF06) {
                if (*(s16 *)&arg2 == 0xF07) {
                    func_800C01A8(0x64, 0);
                    func_808000B0_chmayafarmer(arg0, 4, 0x2010, *(s32 *)arg0);
                    func_800D1000(4, 1, 0, 1, 0);
                }
            } else {
                func_80800138_chmayafarmer(arg0);
            }
            break;
        case 0x2F:
            if ((*(s16 *)&arg2 == 0xF06) && (func_800C07F4() == 0)) {
                func_800DA544(5);
            }
            break;
        case 0xB:
            switch (arg2) {
                case 0xF:
                    func_80800000_chmayafarmer(arg0, 2, 1);
                    return 4;
                case 4:
                    func_80800138_chmayafarmer(arg0);
                    return 4;
            }
            return 3;
        case 0x52:
            _gcdialogcamera_entrypoint_3(D_8080125C_chmayafarmer, *(f32 *)(arg0 + 0x38));
            break;
        case 0x40:
            ((struct FarmerState *)arg0)->count--;
            if ((s32)((struct FarmerState *)arg0)->count <= 0) {
                func_808001CC_chmayafarmer(arg0, 4);
            }
            break;
        case 0x3D:
            count = func_800CBC3C(D_8080126C_chmayafarmer);
            if ((s32)((struct FarmerState *)arg0)->count > 8) {
                ((struct FarmerState *)arg0)->count = 8;
            }
            for (i = 0; i < (s32)((struct FarmerState *)arg0)->count; i++) {
                func_800CD08C(count, D_8080126C_chmayafarmer);
                func_80108528(0x2F8, D_8080126C_chmayafarmer, (s32)func_800DC178(0.0f, 360.0f), &arg0)[15] = *(s32 *)arg0;
            }
            break;
    }
    return 1;
}

void func_80800520_chmayafarmer(Actor* arg0) 
{
    _suexpression_entrypoint_8(arg0, 1);
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mayafarmer/func_80800540_chmayafarmer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mayafarmer/func_8080085C_chmayafarmer.s")

OSThread *chmayafarmer_entrypoint_0(void)
{
    extern u8 D_80801278_chmayafarmer[];

    return (OSThread *) D_80801278_chmayafarmer;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mayafarmer/func_808008F8_chmayafarmer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mayafarmer/func_808009A0_chmayafarmer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mayafarmer/func_80800B9C_chmayafarmer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mayafarmer/func_80800C58_chmayafarmer.s")

/* extern */

void func_80800D18_chmayafarmer(u8 *arg0) {
    s32 func_800CC63C(s32, s32);
    s32 func_800EE7F8(u8 *, s32);
    u32 temp_v0;

    temp_v0 = (*(u32 *)((s8 *)(arg0) + (0x70)));
    func_800EE7F8(arg0 + 0x18, func_800CC63C((temp_v0 >> 0x19) - 1, ((u32) (temp_v0 << 0x16) >> 0x1A) - 1));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mayafarmer/func_80800D60_chmayafarmer.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mayafarmer/func_80801040_chmayafarmer.s")

void func_808010DC_chmayafarmer(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_4(Actor*, f32*, u32, u32*);
    extern u32 D_808012E8_chmayafarmer;
    _subaddieaudioloop_entrypoint_4(arg0, (f32 *) ((u8 *) arg0 + 4), 1U, &D_808012E8_chmayafarmer);
}

OSThread *chmayafarmer_entrypoint_1(void)
{
    extern u8 D_808012FC_chmayafarmer[];

    return (OSThread *) D_808012FC_chmayafarmer;
}
