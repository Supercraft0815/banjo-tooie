#include "core2/1ECE0B0.h"

extern PlayerState* D_80135490[];
extern s32 func_800966BC(void *);
extern f32 func_800964DC(PlayerState *);
extern f32 func_8009C150(PlayerState *);
extern s32 func_8009E674(PlayerState *, s32);
extern u8 D_801354DA;

extern u32 D_801354DC;
extern u8 D_801354F8;
extern u8 D_801354F9;
extern u8 D_801354FC;
extern u8 D_801354FD;

extern f32 D_8013550C;

void func_800F9400(s32 arg0) {
    s32 func_800C964C(s32);
    if ((arg0 == 0xA) || (arg0 == 1)) {
        func_800C964C(0xC);
        return;
    }
    func_800C964C(0xE);
}

/* extern */

void func_800F9444(s32 arg0) {
    s32 func_800C964C(s32);
    if ((arg0 == 0xA) || (arg0 == 1)) {
        func_800C964C(0xD);
        return;
    }
    func_800C964C(0xF);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED2CF0/func_800F9488.s")

s32 func_800F99E8(void) {
    extern u8 D_80135520;
    return D_80135520 != 1;
}

s32 func_800F99FC(void) {
    extern u8 D_80135520;
    if (D_80135520 == 0xE) {
        return 1;
    }
    return 0;
}

void func_800F9A24(void) {
    func_800F9488(NULL);
}

void func_800F9A44(void) {
    extern u8 D_80135520;
    D_80135520 = 0;
    func_800F9488(1);
}

void func_800F9A6C(void) {
    if (_plsu_entrypoint_2() != 0) {
        func_800F9488(2);
        return;
    }
    func_800F9488(4);
}

void func_800F9AAC(s32 arg0, s32 arg1) {
    extern u8 D_80135520;
    (&D_80135520)[1] = arg0;
    (&D_80135520)[2] = arg1;
    func_800F9488(0xB);
}

void func_800F9ADC()
{
    func_800F9488(0xC);
}

void func_800F9AFC(void) {
    s32 _plsu_entrypoint_1(s32);
    u32 sp20[2];
    s32 sp1C;

    func_800F93C4(&sp20[0], (s32 *) &sp20[1]);
    sp1C = _plsu_entrypoint_1(func_800F929C());
    func_800F8128(sp1C);
    func_800F8EBC(sp1C);
    func_800F8268(sp1C, 1, 1);
}

/* extern */

void func_800F9B54(void) {
    s32 _plsu_entrypoint_1(s32);
    u32 sp1C;
    s32 sp18;

    sp1C = func_800F54E4();
    sp18 = _plsu_entrypoint_1(0x11);
    func_800F8128((s32) sp1C);
    func_800F8268((s32) sp1C, 1, 1);
    func_800F82C0(sp18);
}

void func_800F9BA4()
{
    func_800D9240(0x11);
}

void func_800F9BC4(void) {
    extern u8 D_80135520;
    void func_800BEAF4(void);

    if (func_800F8B88() == 3) {
        if (func_800DB9B0() == 0) {
            switch (D_80135520) {
                case 0xD:
                case 0xE:
                case 0xF:
                case 0x10:
                case 0x11:
                case 0x12:
                case 0x13:
                    break;
                default:
                    func_800BEAF4();
                    func_800F9488(0x12);
                    break;
            }
        }
    }
}

void func_800F9C38(void) { if (func_800F8B88() == 3) func_800F9488(0x13); }

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1ED2CF0/func_800F9C6C.s")
