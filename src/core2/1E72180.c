#include "common.h"

s32 func_80098890() 
{
    return 0x1C;
} typedef struct { u8 pad0[0xB8]; union { void * unkB8; s32 * unkB8_s32p; }; union { f32 * unkBC; s8 * unkBC_s8p; u8 * unkBC_u8p; }; u8 padC0[0x98]; s32 unk158; u8 pad15C[0x28]; s32 unk184; } Obj1E72180_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_80098898(void *arg0) {
    void func_800BED18(s32 *, s32 *);
    s32 func_800EA05C();
    void func_800EE84C(f32 *, s32 *);
    extern s16 D_80117EC0;
    s32 sp3C[3];
    s32 sp30[3];
    s32 sp2C;
    s16 *var_v1;

    sp2C = func_800EA05C();
    func_800BED18(sp30, sp3C);
    func_800EE84C(((Obj1E72180_arg0 *)arg0)->unkBC + 3, sp30);
    func_800EE84C(((Obj1E72180_arg0 *)arg0)->unkBC, sp3C);
    for (var_v1 = &D_80117EC0; var_v1[0] != 0 && sp2C != var_v1[0]; var_v1 += 7) {
    }
    (((Obj1E72180_arg0 *)arg0)->unkBC)[3] -= var_v1[1];
    (((Obj1E72180_arg0 *)arg0)->unkBC)[4] -= var_v1[2];
    (((Obj1E72180_arg0 *)arg0)->unkBC)[5] -= var_v1[3];
    (((Obj1E72180_arg0 *)arg0)->unkBC)[0] += var_v1[4];
    (((Obj1E72180_arg0 *)arg0)->unkBC)[1] += var_v1[5];
    (((Obj1E72180_arg0 *)arg0)->unkBC)[2] += var_v1[6];
    (((Obj1E72180_arg0 *)arg0)->unkBC_s8p)[0x18] = 0;
    (((Obj1E72180_arg0 *)arg0)->unkBC_s8p)[0x19] = 0;
}

void func_800989E4(void *arg0) {
    struct player_state_s;
    void _gcfrontend_entrypoint_12(void);
    void baphysics_set_type(void *self, s32 type);
    s32 func_8008DAA8(void *);
    void func_8009C128(struct player_state_s *, f32[3]);
    void func_800A05DC(struct player_state_s *);
    s32 func_800A3274(void *);
    s32 func_800BF6B8(void);
    s32 func_800D3948(void);
    s32 func_800D395C(void);
    int func_800EFED0(f32[3], f32[3], f32[3]);
    void func_800F7B9C(BtIntPtr, u32);
    u8 func_800F8B88(void);
    f32 position[3];
    s32 mode;
    s32 flag1;
    s32 flag2;

    if (!func_8008DAA8(arg0)) {
        return;
    }
    if ((((Obj1E72180_arg0 *)arg0)->unkBC_u8p)[0x19]) {
        return;
    }
    mode = func_800BF6B8();
    if (mode == 1) {
        return;
    }
    func_8009C128(arg0, position);
    if (mode == 2 || !func_800EFED0(((Obj1E72180_arg0 *)arg0)->unkBC + 3,
                                   ((Obj1E72180_arg0 *)arg0)->unkBC, position)) {
        if ((((Obj1E72180_arg0 *)arg0)->unkBC_u8p)[0x18] == 0) {
            (((Obj1E72180_arg0 *)arg0)->unkBC_u8p)[0x18] = 1;
            if (func_800D3948() || func_800D395C()) {
                _gcfrontend_entrypoint_12();
                return;
            }
            flag1 = 0;
            flag2 = 0;
            switch (func_800A3274(arg0)) {
                case 0x11:
                    flag1 = 1;
                    break;
                case 0xB:
                    if (func_800F8B88() == 3) {
                        flag2 = 1;
                    }
                    break;
            }
            if (flag1) {
                func_800F7B9C(((Obj1E72180_arg0 *)arg0)->unk184, 0x1F);
            } else if (flag2) {
                func_800F7B9C(((Obj1E72180_arg0 *)arg0)->unk184, 0x88);
            } else {
                func_800A05DC(arg0);
            }
        } else {
            baphysics_set_type(arg0, 7);
        }
    }
}

void func_80098B4C(void *arg0, s32 arg1) {
    (*(s8 *)((s8 *)((*(void **)((s8 *)(arg0) + (0xBC)))) + (0x19))) = (s8) (arg1 == 0);
}

/* extern */

void func_80098B5C(void *arg0, BtIntPtr arg1, BtIntPtr arg2) {
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    func_800EE7F8(arg1, (*(s32 *)((s8 *)(arg0) + (0xBC))) + 0xC);
    func_800EE7F8(arg2, (*(s32 *)((s8 *)(arg0) + (0xBC))));
}

s32 func_80098BA0() 
{
    return 0xC;
}

/* extern */

void func_80098BA8(void *arg0, BtIntPtr arg1) {
    s32 func_80091E80(void *, s32);
    void func_80092444(void *arg0, void *arg1);
    if (func_80091E80(arg0, 1) != 0) {
        func_80092444(arg0, arg1);
    }
}

/* extern */

void func_80098BE0(void *arg0 BT_PASS2(, s32 bt_a1) BT_PASS2(, s32 bt_a2)) {
    void _baeggcursor_entrypoint_1(void *arg0);
    void _bsfirstp_entrypoint_37(void *arg0);
    s32 func_8009AD78(void *, s32);
    s32 func_800A9420(s32);
    if (func_800A9420((((Obj1E72180_arg0 *)arg0)->unk184)) != 0) {
        if (func_8009AD78(arg0, 8) != 0) {
            _baeggcursor_entrypoint_1(arg0);
        }
        if (func_8009AD78(arg0, 0xB) != 0) {
            _bsfirstp_entrypoint_37(arg0);
        }
    }
}

/* extern */

void func_80098C48(void *arg0) {
    void _baattach_entrypoint_4(void *self);
    void _bababykaz_entrypoint_2(void *self);
    void _bacough_entrypoint_3(void *self);
    void _badeathmatch_entrypoint_1(void *arg0);
    void _badrone_entrypoint_32(void *self);
    void _badronemem_entrypoint_3(void *arg0);
    void _baduo_entrypoint_6(void *arg0);
    void _badust_entrypoint_11(void *arg0);
    void _baeggcursor_entrypoint_5(void *arg0);
    void _bafpctrl_entrypoint_8(void *arg0);
    void _bahold_entrypoint_1(u8 *arg0);
    void _bainvisible_entrypoint_3(BtIntPtr arg0);
    void _bamum_entrypoint_2(void *arg0);
    void _bapackctrl_entrypoint_3(BtIntPtr arg0);
    void _basetup_entrypoint_4(BtIntPtr arg0);
    void _bashoes_entrypoint_4(void *arg0);
    void _basquash_entrypoint_2(void *arg0);
    void _bastatemem_entrypoint_3(void* arg0);
    void _batranslate_entrypoint_2(void *self);
    void baanim_init(void *self);
    void baflag_clearAll(void *self);
    void bainput_init(void *self);
    void bakey_init(void *self);
    void baroll_reset(void *self);
    void bastatetimerlist_init(void *self);
    void bastick_reset(void *self);
    void func_8008E618(void *self);
    void func_80090938(void *self);
    void func_8009105C(void *arg0);
    void func_80091E20(u8 *arg0);
    void func_80091EC8(void *arg0);
    void func_80092898(void *arg0);
    void func_80094644(void *arg0);
    void func_80094F38(u8 *arg0);
    void func_80095068(void *player);
    void func_800955CC(void *arg0);
    void func_80095AD0(s32 *arg0);
    void func_80098408(u8 *arg0);
    void func_80098538(u8 *arg0);
    void func_8009AC6C(u8 *arg0);
    s32 func_8009AD90();
    void func_8009B4FC(void *arg0);
    void func_8009BD50(void *arg0);
    void func_8009BF04(void *arg0);
    void func_8009C038(void *arg0);
    void func_8009CBFC(void *arg0);
    void func_8009CC90(void *arg0);
    void func_8009CF98(void *arg0);
    void func_8009D4D8(void *arg0);
    void func_8009E390(void *arg0);
    void func_8009E7AC(void *arg0);
    void func_8009FE78(void *arg0);
    void func_800A0C44(void *arg0);
    void func_800A0FF0(void *arg0);
    void func_800A16F4(void *arg0);
    void func_800A1F78(void *arg0);
    void func_800A21C8(void *arg0);
    void func_800A2D94(void *arg0);
    void func_800A3820(void *arg0);
    void func_800A4168(u8 *arg0);
    (*(s8 *)((s8 *)((((Obj1E72180_arg0 *)arg0)->unkB8_s32p)) + (8))) = 1;
    func_8009AD90();
    _badronemem_entrypoint_3(arg0);
    _bastatemem_entrypoint_3(arg0);
    func_800A3820(arg0);
    *(((Obj1E72180_arg0 *)arg0)->unkB8_s32p) = 0;
    bakey_init(arg0);
    func_8009FE78(arg0);
    func_8009C038(arg0);
    _badrone_entrypoint_32(arg0);
    _badust_entrypoint_11(arg0);
    func_800955CC(arg0);
    baflag_clearAll(arg0);
    func_800A0FF0(arg0);
    bastick_reset(arg0);
    bainput_init(arg0);
    _bainvisible_entrypoint_3(arg0);
    func_80098408(arg0);
    func_8009CBFC(arg0);
    func_8009E7AC(arg0);
    func_800A16F4(arg0);
    func_80091E20(arg0);
    func_80094644(arg0);
    _baeggcursor_entrypoint_5(arg0);
    _bafpctrl_entrypoint_8(arg0);
    _bapackctrl_entrypoint_3(arg0);
    _bababykaz_entrypoint_2(arg0);
    func_800A4168(arg0);
    _bacough_entrypoint_3(arg0);
    func_80091EC8(arg0);
    _badeathmatch_entrypoint_1(arg0);
    _baduo_entrypoint_6(arg0);
    _baattach_entrypoint_4(arg0);
    func_80098898(arg0);
    func_8009AC6C(arg0);
    func_8009B4FC(arg0);
    func_8009BD50(arg0);
    func_8009BF04(arg0);
    func_80098538(arg0);
    func_8009CC90(arg0);
    baroll_reset(arg0);
    func_8009CF98(arg0);
    func_80094F38(arg0);
    func_800A0C44(arg0);
    func_80095068(arg0);
    func_80090938(arg0);
    func_8009105C(arg0);
    bastatetimerlist_init(arg0);
    _bahold_entrypoint_1(arg0);
    func_80095AD0(arg0);
    _bamum_entrypoint_2(arg0);
    baanim_init(arg0);
    func_800A21C8(arg0);
    func_80092898(arg0);
    func_8008E618(arg0);
    _basetup_entrypoint_4(arg0);
    func_8009D4D8(arg0);
    func_800A1F78(arg0);
    _bashoes_entrypoint_4(arg0);
    func_8009E390(arg0);
    _basquash_entrypoint_2(arg0);
    func_800A2D94(arg0);
    _batranslate_entrypoint_2(arg0);
}    typedef struct { u8 pad0[0xB8]; u8 * unkB8; u8 padBC[0xC8]; s32 unk184; } Obj1E72180_func_80098E64_self; /* offsets.py genstruct: fields from raw offsets on self; rename once understood */

void func_80098E64(void *self) {
    s32 func_800A3274(void *);
    s32 baflag_isTrue(void *, s32);
    void func_800A3410(void *, s32);
    void func_800F8EBC(s32);
    s32 bs_getCurrentState(void *);
    s16 func_8009CBDC(BtIntPtr, s32);
    s32 func_8008DAA8(void *);
    void func_8009E880(void);
    s32 func_800A81C4(void);
    s32 func_800EA068(s32);
    s32 _bashoes_entrypoint_6();
    s32 func_8008E39C();
    f32 bastatetimer_get(void *, s32);
    s32 func_8009E674(void *, s32);
    void func_8009EAD0(s32);
    void func_8009EB0C(f32);
    s32 _bashoes_entrypoint_1();
    void func_8009EAF4(s32);
    void func_8009E9D8(s32);
    void func_8009E9FC(f32);
    s32 func_8009E71C(void *, s32);
    void func_8009EB18(s32);
    void bs_setState(void *self, s32 nextState);
    void _baattach_entrypoint_3(void *);
    void func_8008E6BC(void *);
    void func_80091054(BtIntPtr arg0);
    void _bababykaz_entrypoint_1(void *);
    void bastatetimerlist_free(void *);
    void _baeggcursor_entrypoint_4(void *);
    void func_80094538(void *);
    void func_80092A1C(void *);
    void func_800A22A8(BtIntPtr arg0);
    void baanim_free(void *);
    void func_80095C10(void *);
    void _bahold_entrypoint_2(BtIntPtr arg0);
    void _bamum_entrypoint_1(BtIntPtr arg0);
    void _basetup_entrypoint_3(BtIntPtr arg0);
    void func_8009D5E0(void *);
    void func_800A2058(BtIntPtr arg0);
    void _bashoes_entrypoint_3(BtIntPtr arg0);
    void _basquash_entrypoint_1(BtIntPtr arg0);
    void func_800A2D70(void *);
    void _batranslate_entrypoint_1(void *);
    void _bastatemem_entrypoint_2(BtIntPtr arg0);
    void _badronemem_entrypoint_2(BtIntPtr arg0);
    void _bapackctrl_entrypoint_2(BtIntPtr arg0);
    void _baduo_entrypoint_5(BtIntPtr arg0);
    void func_8009E388(BtIntPtr arg0);
    void _bafpctrl_entrypoint_7(BtIntPtr arg0);
    void func_80091E18(BtIntPtr arg0);
    void bakey_free(void *);
    void _bacough_entrypoint_2(void *);
    void _badeathmatch_entrypoint_2(void *);
    void func_80091EA8(BtIntPtr arg0);
    void _bainvisible_entrypoint_4(void *);
    void func_8009AD88(BtIntPtr arg0);
    void func_800A4160(BtIntPtr arg0);
    s32 unused;
    s32 state;
    f32 timer;
    s32 flag;
    int active;

    if (func_800A3274(self) == 0xE && baflag_isTrue(self, 0x40)) {
        func_800A3410(self, 0xD);
        func_800F8EBC(((Obj1E72180_func_80098E64_self *)self)->unk184);
    }
    state = func_8009CBDC((BtIntPtr)self, bs_getCurrentState(self));
    if (func_8008DAA8(self)) {
        func_8009E880();
        if (func_800A81C4() || func_800EA068(0x800)) {
            _bashoes_entrypoint_6(self, 1);
        }
        timer = 0.0f;
        flag = 0;
        if (func_8008E39C(self)) {
            timer = bastatetimer_get(self, 3);
            flag = 1;
        } else if (func_8009E674(self, 0x40)) {
            flag = 1;
        }
        if (flag) {
            func_8009EAD0(2);
        }
        func_8009EB0C(timer);
        func_8009EAF4(_bashoes_entrypoint_1(self));
        func_8009E9D8(func_800A3274(self));
        func_8009E9FC(0.0f);
        switch (state) {
            case 8:
                func_8009E9FC(bastatetimer_get(self, 2));
                break;
            case 9:
                if (func_800A3274(self) == 6) {
                    func_8009EAD0(4);
                }
                break;
            case 18:
                func_8009EAD0(3);
                break;
            case 19:
                func_8009EAD0(6);
                break;
            case 20:
                func_8009EAD0(7);
                break;
        }
    }
    active = func_8009E71C(self, 5) ? 1 : 0;
    active &= func_800EA068(8) ? 1 : 0;
    func_8009EB18(active);
    bs_setState((BtIntPtr)self, 0x5A);
    _baattach_entrypoint_3(self);
    func_8008E6BC(self);
    func_80091054(self);
    _bababykaz_entrypoint_1(self);
    bastatetimerlist_free(self);
    _baeggcursor_entrypoint_4(self);
    func_80094538(self);
    func_80092A1C(self);
    func_800A22A8(self);
    baanim_free(self);
    func_80095C10(self);
    _bahold_entrypoint_2(self);
    _bamum_entrypoint_1(self);
    _basetup_entrypoint_3(self);
    func_8009D5E0(self);
    func_800A2058(self);
    _bashoes_entrypoint_3(self);
    _basquash_entrypoint_1(self);
    func_800A2D70(self);
    _batranslate_entrypoint_1(self);
    _bastatemem_entrypoint_2(self);
    _badronemem_entrypoint_2(self);
    _bapackctrl_entrypoint_2(self);
    _baduo_entrypoint_5(self);
    func_8009E388(self);
    _bafpctrl_entrypoint_7(self);
    func_80091E18(self);
    bakey_free(self);
    _bacough_entrypoint_2(self);
    _badeathmatch_entrypoint_2(self);
    func_80091EA8(self);
    _bainvisible_entrypoint_4(self);
    func_8009AD88(self);
    func_800A4160(self);
    (((Obj1E72180_func_80098E64_self *)self)->unkB8)[8] = 0;
}

void func_8009919C(void *arg0, BtIntPtr arg1, s32 arg2) {
    (*(s32 *)((s8 *)((((Obj1E72180_arg0 *)arg0)->unkB8)) + (0))) = arg1;
    (*(s32 *)((s8 *)((((Obj1E72180_arg0 *)arg0)->unkB8)) + (4))) = arg2;
}    typedef struct { void (*unk0)(s32); s32 unk4; } Obj1E72180_func_800991B0_temp_v0; /* offsets.py genstruct: fields from raw offsets on temp_v0; rename once understood */

void func_800991B0(void *arg0)
{
  void _bacough_entrypoint_5(void *self);
  void _badeathmatch_entrypoint_3(void *arg0);
  void _baduo_entrypoint_13(void *arg0);
  void _badust_entrypoint_13(void *arg0);
  s32 _baeggcursor_entrypoint_11(void *);
  void _bafpctrl_entrypoint_15(void *arg0);
  void _bahold_entrypoint_3(void *arg0);
  void _bainvisible_entrypoint_6(BtIntPtr arg0);
  void _bamum_entrypoint_3();
  void _bashoes_entrypoint_13(void *arg0);
  void _basquash_entrypoint_4(void *arg0);
  void _batranslate_entrypoint_4(void *self);
  void baanim_update(void *self);
  void bainput_update(void *self);
  void bakey_update(void *self);
  void baroll_update(void *self);
  void bastatetimerlist_update(void *self);
  void bastick_update(void *self);
  s32 func_8008DAA8(void *);
  s32 func_8008E124(void *);
  s32 func_8008E454(void *);
  void func_8008E6F0(void *arg0);
  void func_80090A4C(void *arg0);
  void func_80091110(void *arg0);
  s32 func_80091E80(void *, s32);
  void func_80091F30(void *);
  void func_80092AB0(void *arg0);
  void func_80093448(void *arg0);
  s32 func_80094864(void *);
  void func_800951F4(void *player);
  void func_8009561C(void *arg0);
  void func_80095C94(void *self);
  void func_800987CC(void *arg0);
  void func_800989E4(void *);
  void func_80099970(void *arg0);
  s32 func_8009AD78(void *, s32);
  void func_8009B590(void *arg0);
  void func_8009BDE4(BtIntPtr arg0);
  void func_8009BF34(void *arg0);
  void func_8009C08C(void *arg0);
  void func_8009C25C(void *arg0);
  void func_8009CF04(void *arg0);
  s32 func_8009D088(void *);
  void func_8009E83C(void *arg0);
  void func_800A0DDC(void *arg0);
  void func_800A10A0(void *arg0);
  void func_800A18E8(void *arg0);
  void func_800A2060(void *arg0);
  void func_800A2534(s32 *arg0);
  void func_800A3A80(void *arg0);
  void func_800A4B08(void *arg0);
  s32 func_800D3E40(s32);
  s32 func_800DA298(s32);
  s32 func_800EA068(s32);
  s32 sp24;
  s32 sp20;
  void *temp_v0;
  void (*temp_v1)(s32);
  sp24 = func_800EA068(8) == 0;
  sp20 = func_800DA298(0x6B5);
  if (func_80091E80(arg0, 0x20) != 0)
  {
    func_80092AB0(arg0);
    func_80099970(arg0);
    func_8009CF04(arg0);
    bastatetimerlist_update(arg0);
    func_800A0DDC(arg0);
    bakey_update(arg0);
    bastick_update(arg0);
    bainput_update(arg0);
    if (func_8009AD78(arg0, 2) != 0)
    {
      _baduo_entrypoint_13(arg0);
    }
    func_8009E83C(arg0);
    if ((func_80091E80(arg0, 2) != 0) && (func_8008E454(arg0) != 0))
    {
      func_8009B590(arg0);
    }
    if (func_8009AD78(arg0, 6) != 0)
    {
      _batranslate_entrypoint_4(arg0);
    }
    func_8009C25C(arg0);
    if (sp24 != 0)
    {
      func_8009561C(arg0);
    }
    func_80095C94(arg0);
    if (func_80091E80(arg0, 2) != 0)
    {
      func_8009BF34(arg0);
      baroll_update(arg0);
      func_8009D088(arg0);
    }
    if (sp20 != 0)
    {
      func_80091110(arg0);
    }
    if (func_80091E80(arg0, 0x10) != 0)
    {
      baanim_update(arg0);
    }
    func_800A2060(arg0);
    if (sp24 != 0)
    {
      func_800987CC(arg0);
    }
    if (func_8009AD78(arg0, 4) != 0)
    {
      func_80090A4C(arg0);
    }
    if (sp24 != 0)
    {
      func_800951F4(arg0);
    }
    if (func_8009AD78(arg0, 3))
    {
      _badust_entrypoint_13(arg0);
    }
    func_8009C08C(arg0);
    func_8008E6F0(arg0);
    if (func_8009AD78(arg0, 0xE) != 0)
    {
      _bahold_entrypoint_3(arg0);
    }
    func_800A10A0(arg0);
    func_8009BDE4(arg0);
    func_800A3A80(arg0);
    func_800A4B08(arg0);
    if ((((Obj1E72180_arg0 *)arg0)->unk158) == 0)
    {
      func_80094864(arg0);
    }
    else
    {
      _badeathmatch_entrypoint_3(arg0);
    }
    if (func_8009AD78(arg0, 9) != 0)
    {
      _bacough_entrypoint_5(arg0);
    }
    if (func_8009AD78(arg0, 8) != 0)
    {
      _baeggcursor_entrypoint_11(arg0);
    }
    if (func_8009AD78(arg0, 0xC) != 0)
    {
      _bainvisible_entrypoint_6(arg0);
    }
    if (func_8009AD78(arg0, 5) != 0)
    {
      _bamum_entrypoint_3(arg0);
    }
    if (func_8009AD78(arg0, 7) != 0)
    {
      _bafpctrl_entrypoint_15(arg0);
    }
    if (func_8009AD78(arg0, 0xA) != 0)
    {
      _basquash_entrypoint_4(arg0);
    }
    if (func_8009AD78(arg0, 0xD) != 0)
    {
      _bashoes_entrypoint_13(arg0);
    }
    func_80093448(arg0);
    func_800A2534(arg0);
    if (((func_800D3E40(4) != 0) && (func_8008DAA8(arg0) != 0)) && (func_8008E124(arg0) == 0))
    {
      func_800A18E8(arg0);
    }
    func_80091F30(arg0);
    temp_v0 = ((Obj1E72180_arg0 *)arg0)->unkB8;
    temp_v1 = ((Obj1E72180_func_800991B0_temp_v0 *)temp_v0)->unk0;
    if (temp_v1 != NULL)
    {
      temp_v1(((Obj1E72180_func_800991B0_temp_v0 *)temp_v0)->unk4);
      *((void (**)(s32)) (((s8 *) (((Obj1E72180_arg0 *)arg0)->unkB8)) + 0)) = NULL;
    }
    func_800989E4(arg0);
  }
}

/* extern */

void func_80099544(void *arg0) {
    s32 baanim_defrag();
    void bakey_defrag(void *self);
    void func_800934C4(void *arg0);
    void func_80096728(void *arg0);
    void func_800A266C(u8 *arg0);
    void func_800A300C(void *arg0);
    if ((*(u8 *)((s8 *)((((Obj1E72180_arg0 *)arg0)->unkB8)) + (8))) != 0) {
        baanim_defrag();
        func_800934C4(arg0);
        func_80096728(arg0);
        func_800A300C(arg0);
        bakey_defrag(arg0);
        func_800A266C(arg0);
    }
}
