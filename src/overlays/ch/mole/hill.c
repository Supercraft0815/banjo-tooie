#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mole/hill/func_80800000_chmolehill.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mole/hill/func_80800088_chmolehill.s")

void func_80800160_chmolehill(u8 *arg0) {
    typedef struct { s32 values[5]; } AnimationTimes;
    typedef struct { u8 high : 4; u8 enabled : 1; u8 low : 3; } ActorFlags;
    s32 _subaddieaudioquick_entrypoint_2(u8 *, u8 *, s32 *);
    s32 anctrl_getPlaybackType(s32);
    s32 chmolehill_entrypoint_1(u8 *, s32);
    s32 chmolehill_entrypoint_2(u8 *, s32);
    s32 func_8008F8B0();
    s32 func_80101E14(u8 *, s32);
    s32 func_80101E4C(u8 *, s32 *);
    s32 func_801022E4(u8 *);
    s32 func_80104248(u8 *);
    s32 func_80800000_chmolehill(u8 *);
    s32 func_80800088_chmolehill(u8 *);
    extern s32 D_80800AC0_chmolehill;
    extern s32 D_80800ACC_chmolehill;
    extern s32 D_80800ADC_chmolehill;
    extern AnimationTimes D_80800B5C_chmolehill;
    s32 sp3C;
    s32 temp_v0;

    sp3C = 0;
    ((ActorFlags *)(arg0 + 0x65))->enabled = 0;
    switch (arg0[0x79] >> 4) {                       /* switch 1 */
    case 0:                                         /* switch 1 */
    case 2:                                         /* switch 1 */
    case 5:                                         /* switch 1 */
    case 6:                                         /* switch 1 */
        break;
    case 7:                                         /* switch 1 */
        chmolehill_entrypoint_1(arg0, 0);
        chmolehill_entrypoint_2(arg0, 0xD);
        break;
    case 1:                                         /* switch 1 */
        func_80800088_chmolehill(arg0);
        if (((*(s32 *)((s8 *)(arg0) + (0x3C))) != 0) && (func_80800000_chmolehill(arg0) != 0)) {
            func_8008F8B0();
            chmolehill_entrypoint_1(arg0, 0);
            chmolehill_entrypoint_2(arg0, 2);
        }
        break;
    case 3:                                         /* switch 1 */
        func_80800088_chmolehill(arg0);
        if (((*(s32 *)((s8 *)(arg0) + (0x3C))) != 0) && (func_80800000_chmolehill(arg0) != 0)) {
            func_8008F8B0();
            chmolehill_entrypoint_1(arg0, 0);
            chmolehill_entrypoint_2(arg0, 7);
        }
        break;
    case 4:                                         /* switch 1 */
        chmolehill_entrypoint_1(arg0, 0);
        chmolehill_entrypoint_2(arg0, 8);
        break;
    }
    switch ((u32)*(u16 *)(arg0 + 0x72) >> 10) {
    case 2:
    case 7:
        break;
    case 10:
        ((ActorFlags *)(arg0 + 0x65))->enabled = 1;
        break;
    case 9:
        ((ActorFlags *)(arg0 + 0x65))->enabled = 1;
        break;
    }
    if (((*(s16 *)((s8 *)(arg0) + (0x8C))) != 0) && (anctrl_getPlaybackType(func_80104248(arg0)) != 3)) {
        temp_v0 = func_801022E4(arg0);
        switch (temp_v0) {                          /* switch 2 */
        case 0x229:                                 /* switch 2 */
            if (func_80101E14(arg0, 0x3E9374BC) != 0) {
                _subaddieaudioquick_entrypoint_2(arg0, arg0 + 4, &D_80800AC0_chmolehill);
            } else if ((func_80101E14(arg0, 0x3F30A3D7) != 0) || (func_80101E14(arg0, 0x3F428F5C) != 0)) {
                sp3C = 1;
            }
            break;
        case 0x22A:                                 /* switch 2 */
            if (func_80101E14(arg0, 0x3E23D70A) != 0) {
                _subaddieaudioquick_entrypoint_2(arg0, arg0 + 4, &D_80800AC0_chmolehill);
            } else if ((func_80101E14(arg0, 0x3F5C28F6) != 0) || (func_80101E14(arg0, 0x3F7AE148) != 0)) {
                sp3C = 1;
            }
            break;
        case 0x22B:                                 /* switch 2 */
            if (func_80101E14(arg0, 0x3E4CCCCD) != 0) {
                _subaddieaudioquick_entrypoint_2(arg0, arg0 + 4, &D_80800ACC_chmolehill);
            }
            break;
        case 0x22C:                                 /* switch 2 */
            if (func_80101E14(arg0, 0x3EF5C28F) != 0) {
                _subaddieaudioquick_entrypoint_2(arg0, arg0 + 4, &D_80800AC0_chmolehill);
            } else if ((func_80101E14(arg0, 0x3F36AE7D) != 0) || (func_80101E14(arg0, 0x3F6F0069) != 0)) {
                sp3C = 1;
            }
            break;
        case 0x22E: {                               /* switch 2 */
            AnimationTimes sp24;
            sp24 = D_80800B5C_chmolehill;
            if (func_80101E14(arg0, 0x3D23D70A) != 0) {
                _subaddieaudioquick_entrypoint_2(arg0, arg0 + 4, &D_80800AC0_chmolehill);
            } else if (func_80101E4C(arg0, sp24.values) != 0) {
                sp3C = 1;
            }
            break;
        }
        }
    }
    if (sp3C != 0) {
        _subaddieaudioquick_entrypoint_2(arg0, arg0 + 4, &D_80800ADC_chmolehill);
    }
}

void chmolehill_entrypoint_0(s32 arg0)
{
  s32 _chmoley_entrypoint_1(void *, u32);
  void *func_80106790();
  void *func_801084B0(s32, void **);
  s32 func_80108944(void *, void *);
  void *sp24;
  void *sp20;
  void *temp_v0;
  sp24 = func_80106790();
  temp_v0 = func_801084B0(0x18F, &sp24);
  sp20 = temp_v0;
  *((s32 *) (((s8 *) sp24) + 0x3C)) = (s32) (*((s32 *) (((s8 *) temp_v0) + 0)));
  *((s32 *) (((s8 *) temp_v0) + 0x3C)) = (s32) (*((s32 *) (((s8 *) sp24) + 0)));
  func_80108944(temp_v0, sp24);
  _chmoley_entrypoint_1(sp20, ((unsigned long) ((u16) (*((u16 *) (((s8 *) sp24) + 0x72))))) >> 0xA);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mole/hill/func_8080058C_chmolehill.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mole/hill/chmolehill_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mole/hill/chmolehill_entrypoint_2.s")

s32 chmolehill_entrypoint_3(Actor *arg0) {
    switch (arg0->unk70_10) {
    case 0:
    case 1:
    case 3:
    case 11:
        return 0;
    case 7:
    case 8:
    case 9:
        return 0;
    case 2:
    case 4:
    case 5:
    case 6:
    case 10:
        return 1;
    }
    return 0;
}

/* extern */

void *func_80100094(Actor *, u32);

void chmolehill_entrypoint_4(Actor *arg0, s32 arg1) { *(s32 *)func_80100094(arg0, 0U) = arg1; }

/* extern */

s32 chmolehill_entrypoint_5(Actor *arg0) {
    void *func_80100094(Actor *, u32);
    return *(s32 *) func_80100094(arg0, 0U);
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mole/hill/func_80800884_chmolehill.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/mole/hill/func_808009A0_chmolehill.s")

OSThread *chmolehill_entrypoint_6(void)
{
    extern u8 D_80800B70_chmolehill[];

    return (OSThread *) D_80800B70_chmolehill;
}
