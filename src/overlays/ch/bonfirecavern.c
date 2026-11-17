#include "common.h"

OSThread *chbonfirecavern_entrypoint_0(void)
{
    extern ActorData D_80800200_chbonfirecavern[];

    return (OSThread *) D_80800200_chbonfirecavern;
}

/* extern */

void func_8080000C_chbonfirecavern(Actor *arg0) {
    void _chfirefx_entrypoint_2(Actor *, f32, f32, s32, s32);
    void _chfirefx_entrypoint_6(Actor *arg0, s16 arg1, s16 arg2);
    void func_80102FDC(Actor *, f32);
    _chfirefx_entrypoint_2(arg0, arg0->scale, (f32)arg0->unk74_7, 30, 5);
    _chfirefx_entrypoint_6(arg0, 500, 4000);
    func_80102FDC(arg0, 1.0f);
}

s32 func_80800080_chbonfirecavern(Actor *arg0, s32 arg1, volatile s32 arg2) {
    s32 _chfirefx_entrypoint_5(Actor *, s32, s32);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    s32 func_8010114C(BtIntPtr, s32, BtIntPtr);
    void func_80101FDC(Actor *actor,u32 state);
    void func_8010A570(Actor *);
    extern s32 D_80800248_chbonfirecavern[];
    extern s32 D_808002A0_chbonfirecavern[8];
    BtIntPtr other;
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
                _subaddieaudioquick_entrypoint_2(arg0, position, D_808002A0_chbonfirecavern);
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
}    typedef struct { u8 pad0[0x72]; u16 unk72; } Objbonfirecavern_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_80800190_chbonfirecavern(u8 *arg0)
{
  void _chfirefx_entrypoint_3(Actor *arg0);
  s32 func_800D9078(BtIntPtr);
  void func_80101FDC(Actor *actor,u32 state);
  void func_8010A590(Actor *arg0);
  s32 sp24;
  sp24 = func_800D9078(arg0 + 0x24);
  _chfirefx_entrypoint_3(arg0);
  if ((sp24 != 0) && (((((((u16) (((Objbonfirecavern_arg0 *)arg0)->unk72)) & 0xFFFFFFFF) & 0xFFFFFFFF) & 0xFFFFFFFF) >> 0xA) == 1))
  {
    func_80101FDC(arg0, 2);
    func_8010A590(arg0);
  }
}
/* data_to_c.py: from asm/data/overlays/ch/bonfirecavern.data.s */
void func_80105834(Actor*);
void _chfirefx_entrypoint_4();
OSThread *func_80108ED0(void);
void func_80107C2C();
ActorData D_80800200_chbonfirecavern [1] BT_DATA(4, overlays_ch_bonfirecavern, 0x0) = { { 785, 937, 1787, 2, 0, (void (*)(struct Actor *))func_80800190_chbonfirecavern, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))_chfirefx_entrypoint_4, 0, 0, 0, 0, 0, 1024, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_8080000C_chbonfirecavern, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 17408, (void (*)(struct Actor *, long, long))func_80800080_chbonfirecavern, 0 } };
s32 D_80800248_chbonfirecavern [22] BT_DATA(4, overlays_ch_bonfirecavern, 0x48) = { 269484061, 165478422, 33554476, 250, 0, 22937600, 1769572, 9830411, 300, 3342326, 2146496, -1061158878, 33555097, 20119910, 1376281, 10027050, 786457, 13369600, 2621340, -6553500, 6553640, 30146560 };
s32 D_808002A0_chbonfirecavern[8] BT_DATA(4, overlays_ch_bonfirecavern, 0xA0) = { 1246428, 852147, 13369365, 128, 6684673, 52432800, 0, 0 };
