#include "common.h"

OSThread *chbonfirecavern_entrypoint_0(void)
{
    extern u8 D_80800200_chbonfirecavern[];

    return (OSThread *) D_80800200_chbonfirecavern;
}

/* extern */

void func_8080000C_chbonfirecavern(Actor *arg0) {
    void _chfirefx_entrypoint_2(Actor *, f32, f32, s32, s32);
    void _chfirefx_entrypoint_6(Actor *, s32, s32);
    void func_80102FDC(Actor *, f32);
    _chfirefx_entrypoint_2(arg0, arg0->scale, (f32)arg0->unk74_7, 30, 5);
    _chfirefx_entrypoint_6(arg0, 500, 4000);
    func_80102FDC(arg0, 1.0f);
}

s32 func_80800080_chbonfirecavern(Actor *arg0, s32 arg1, volatile s32 arg2) {
    s32 _chfirefx_entrypoint_5(Actor *, s32, s32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 func_800BABB8(s32, f32[3], f32[3], f32, s32[]);
    s32 func_8010114C(s32, s32, s32);
    s32 func_80101FDC(u8 *, s32);
    void func_8010A570(Actor *);
    extern s32 D_80800248_chbonfirecavern[];
    extern s32 D_808002A0_chbonfirecavern;
    s32 other;
    f32 *position;

    switch (arg1) {
        case 0x40:
            if (((u16 *)*(s32 *)&arg2)[12] & 1) {
                func_8010114C(*(s32 *)&arg2, 0x92, 0);
            }
            func_80101FDC(arg0, 2);
            break;
        case 0x3F:
            other = arg2;
            if (((u16 *)other)[12] & 1) {
                func_8010114C(other, 0x92, 0);
            }
            position = arg0->position;
            if (arg0->unk70_10 == 2) {
                _subaddieaudioquick_entrypoint_2(arg0, position, &D_808002A0_chbonfirecavern);
                func_800BABB8(0, position, NULL, 1.0f, D_80800248_chbonfirecavern);
            }
            func_80101FDC(arg0, 1);
            func_8010A570(arg0);
            ((f32 *)arg0->actorData)[3] = 6.0f;
            break;
        default:
            return _chfirefx_entrypoint_5(arg0, arg1, arg2);
    }
    return 1;
}

void func_80800190_chbonfirecavern(u8 *arg0)
{
  s32 _chfirefx_entrypoint_3(u8 *);
  s32 func_800D9078(s32);
  s32 func_80101FDC(u8 *, s32);
  s32 func_8010A590(u8 *);
  s32 sp24;
  sp24 = func_800D9078(arg0 + 0x24);
  _chfirefx_entrypoint_3(arg0);
  if ((sp24 != 0) && (((((((u16) (*((u16 *) (((s8 *) arg0) + 0x72)))) & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF) >> 0xA) == 1))
  {
    func_80101FDC(arg0, 2);
    func_8010A590(arg0);
  }
}
