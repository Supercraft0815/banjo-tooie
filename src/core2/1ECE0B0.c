#include "core2/1ECE0B0.h"
#include "core2/1EC3810.h"
#ifdef BT_NATIVE
#include "core2/1ECD170.h"
#include "vector.h"

typedef struct {
    u8 mode, overridePosition, flagsCleared, pad3, flag4, flag5, pad6[2];
    f32 position10[3];
    f32 yaw;
    f32 position11[3];
    s32 map;
} PlayerReturnState;
Vector *D_801354F0;
PlayerReturnState D_801354F8;
_Static_assert(sizeof(PlayerReturnState) == 0x28, "player return state");

void func_800F3BB0(PlayerState *, f32[3]);
#endif

BT_IDO_ONLY(extern) PlayerRegistry D_80135490;
extern s32 func_800966BC(void *);
extern f32 func_800964DC(PlayerState *);
extern f32 func_8009C150(PlayerState *);
extern s32 func_8009E674(PlayerState *, s32);
BT_IDO_ONLY(extern u8 D_801354DA;)

BT_IDO_ONLY(extern u32 D_801354DC;)
BT_IDO_ONLY(extern u8 D_801354F8;)
BT_IDO_ONLY(extern u8 D_801354F9;)
BT_IDO_ONLY(extern u8 D_801354FC;)
BT_IDO_ONLY(extern u8 D_801354FD;)

BT_IDO_ONLY(extern f32 D_8013550C;)

void func_800F47C0(void (*arg0)(PlayerState *)) {
    BT_IDO_ONLY(extern u8 D_801354B0[];)
    PlayerState **current;
    PlayerState **end;
    PlayerState *player;

    current = (end = BT_DATA_FIELD(D_80135490.players + 8, (PlayerState **)D_801354B0), D_80135490.players);
    do {
        player = *current;
        if (player != NULL && player->unk17C != 0) {
            arg0(player);
        }
        current++;
    } while (current != end);
}

void func_800F482C(s32 arg0) {
    void func_800A91F4(s32);
    BT_LP64_ONLY(void) BT_IDO_ONLY(s32) BT_ILP32_ONLY(s32) func_800F3880(PlayerState *);
    PlayerState **current;
    s32 i;

    current = D_80135490.players;
    i = 0;
    do {
        if (*current != NULL && (arg0 == 0 || func_800A3274(*current) == arg0)) {
            func_800F3880(*current);
            func_800A91F4(i);
            *current = NULL;
        }
        i++;
        current++;
    } while (i != 8);
}

void func_800F48BC(BtIntPtr arg0, f32 *arg1) {
    f32 func_800D8FF8(void);
    void func_800EFA20(void *, void *, f32);
    f32 sp2C[3];
    f32 sp20[3];
    PlayerState *sp1C;

    sp1C = D_80135490.players[arg0];
    func_800F4200(sp1C, sp2C);
    func_800EFA20(sp20, arg1, func_800D8FF8());
    func_800EF04C(sp2C, sp20);
    func_800F4648(sp1C, sp2C);
}

void func_800F4924(BtIntPtr arg0,s32 a1)
{
    func_800A17A8(D_80135490.players[arg0],a1);
}

void func_800F4950(BT_IDO_ONLY(s32 arg0) BT_PASS2(s32 arg0, BT_PASS2(s32 bt_a1, void *bt_a2)))
{
    _baattach_entrypoint_2(BT_IDO_ONLY(D_80135490.players[arg0]) BT_PASS2(D_80135490.players[arg0], BT_PASS2(bt_a1, bt_a2)));
}

void func_800F497C(BtIntPtr arg0)
{
    _badrone_entrypoint_5(D_80135490.players[arg0]);
}

void func_800F49A8(BtIntPtr arg0, s32 arg1)
{
    _badrone_entrypoint_10(D_80135490.players[arg0], arg1);
}

#ifdef BT_NATIVE
void func_800F49D4(BtIntPtr arg0, BaDroneCallback arg1, uintptr_t arg2)
#else
void func_800F49D4(s32 arg0,void* arg1,s32 arg2)
#endif
{
    _badrone_entrypoint_11(D_80135490.players[arg0],arg1,arg2);
}

void func_800F4A00(BtIntPtr arg0, s32 arg1)
{
    _badrone_entrypoint_12(D_80135490.players[arg0], arg1);
}

void func_800F4A2C(BtIntPtr arg0, f32 *arg1)
{
    _badrone_entrypoint_13(D_80135490.players[arg0], arg1);
}

void func_800F4A58(BtIntPtr arg0, f32 *arg1, f32 arg2) {
    _badrone_entrypoint_14(D_80135490.players[arg0], arg1, arg2);
}

void func_800F4A8C(BtIntPtr arg0, f32 *arg1, f32 arg2) {
    _badrone_entrypoint_15(D_80135490.players[arg0], arg1, arg2);
}

void func_800F4AC0(BtIntPtr arg0, f32 *arg1, f32 arg2) {
    _badrone_entrypoint_16(D_80135490.players[arg0], arg1, arg2);
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F4AF4(s32 arg0 BT_PASS2(, s32 bt_a1))
{
    BT_NATIVE_ONLY(return) func_800A4DA4(D_80135490.players[arg0] BT_PASS2(, bt_a1));
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F4B20(BtIntPtr arg0)
{
    BT_NATIVE_ONLY(return) func_800A4E30(D_80135490.players[arg0]);
}

/* extern */

s32 func_800F4B4C(s32 arg0) {
    s32 var_v1;

    if (func_8009E674(D_80135490.players[arg0], 0x200000) != 0) {
        var_v1 = 0;
    } else {
        var_v1 = 1;
    }
    return var_v1;
}

s32 func_800F4B8C(BtUIntPtr a0, u32 a1, s32 a2)
{
    return func_800F3930(D_80135490.players[a0],a1,a2);
}

s32 func_800F4BB8(BtUIntPtr arg0, u32 arg1, s32 arg2)
{
    return func_800F3A78(D_80135490.players[arg0],arg1,arg2);
}

/* extern */

s32 func_800F4BE4(BtIntPtr arg0) {
    s32 func_8009E674(PlayerState *, s32);
    s32 var_v1;

    if (func_8009E674(D_80135490.players[arg0], 0x20000) != 0) {
        var_v1 = 0;
    } else {
        var_v1 = 1;
    }
    return var_v1;
}

s32 func_800F4C24(BtIntPtr arg0) {
    s32 bs_getCurrentState(PlayerState *);
    s32 func_800F6D24(BtIntPtr);
    s32 func_800F68B8(BtIntPtr);
    s32 func_800F6CC8(BtIntPtr);
    PlayerState *sp1C;
    s32 temp_v0;

    sp1C = D_80135490.players[arg0];
    if (func_800F6D24(arg0) != 0) {
        return 0;
    }
    if (func_800F68B8(arg0) != 0) {
        return 0;
    }
    if (func_800F6CC8(arg0) != 0) {
        return 0;
    }
    temp_v0 = bs_getCurrentState(sp1C);
    if ((temp_v0 == 0xED) || (temp_v0 == 0x157)) {
        return 0;
    }
    return 1;
}

void func_800F4CC0(BtIntPtr arg0)
{
    func_80091E6C(D_80135490.players[arg0]);
}

void func_800F4CEC(BtIntPtr arg0,u32 arg1)
{
    func_80091E48(D_80135490.players[arg0],arg1);
}

/* extern */

s32 func_800F4D18(BtIntPtr arg0, f32 *arg1, f32 *arg2) {
    s32 func_8009F678(PlayerState *, f32 *, f32 *, f32);
    f32 func_800A3048(PlayerState *);
    PlayerState *sp1C;

    sp1C = D_80135490.players[arg0];
    BT_NATIVE_ONLY(return) func_8009F678(sp1C, arg1, arg2, func_800A3048(sp1C) * 1000.0f);
}

void func_800F4D74(BtIntPtr arg0, f32 *arg1, f32 arg2, f32 arg3, f32 arg4) {
    s32 func_8009F678(PlayerState *, f32 *, f32 *, f32);
    f32 func_800A3048(PlayerState *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    f32 sp34[3];
    f32 sp28[3];
    PlayerState *sp24;

    sp24 = D_80135490.players[arg0];
    func_800EFA4C(sp34, arg1[0] - arg2, arg1[1] - arg3, arg1[2] - arg4);
    func_800EFA4C(sp28, arg1[0] + arg2, arg1[1] + arg3, arg1[2] + arg4);
    func_8009F678(sp24, sp34, sp28, func_800A3048(sp24) * 1000.0f);
}

/* extern */

s32 func_800F4E5C(s32 arg0, BtIntPtr arg1, BtIntPtr arg2, BtIntPtr arg3, BtIntPtr arg4) {
    s32 func_8009F440(PlayerState *, BtIntPtr, BtIntPtr, BtIntPtr, BtIntPtr, f32);
    f32 func_800A3048(PlayerState *);
    PlayerState *sp24;

    sp24 = D_80135490.players[arg0];
    return func_8009F440(sp24, arg1, arg2, arg3, arg4, func_800A3048(sp24) * 1000.0f);
}

/* extern */

s32 func_800F4EC8(BtUIntPtr arg0, BtIntPtr arg1, f32 arg2, f32 arg3, f32 arg4) {
    s32 func_8009F860(PlayerState *, BtIntPtr, f32, f32, f32, f32);
    f32 func_800A3048(PlayerState *);
    PlayerState *sp24;

    sp24 = D_80135490.players[arg0];
    return func_8009F860(sp24, arg1, arg2, arg3, arg4, func_800A3048(sp24) * 1000.0f);
}

/* extern */

s32 func_800F4F34(BtUIntPtr arg0, f32 *arg1, f32 arg2, f32 arg3) {
    s32 func_8009FA20(PlayerState *, f32 *, f32, f32, f32);
    f32 func_800A3048(PlayerState *);
    PlayerState *sp24;

    sp24 = D_80135490.players[arg0];
    return func_8009FA20(sp24, arg1, arg2, arg3, func_800A3048(sp24) * 1000.0f);
}

void func_800F4F98(BT_IDO_ONLY(s32 arg0) BT_PASS2(s32 arg0, s32 bt_a1))
{
    _baattach_entrypoint_5(BT_IDO_ONLY(D_80135490.players[arg0]) BT_PASS2(D_80135490.players[arg0], bt_a1));
}

/* extern */

void func_800F4FC4(void) {
    s32 _plsu_entrypoint_1(s32);
    s32 func_80101180(s32, s32, BtIntPtr);
    s32 temp_v0;

    temp_v0 = _plsu_entrypoint_1(0x11);
    if (temp_v0 != -1) {
        func_800F7B9C(temp_v0, 0x1FU);
    }
    func_80101180(0x15E, 0x2C, 0);
}

void func_800F5008(BtIntPtr arg0) {
    s32 func_80092258(void *);
    void func_80098BA8(void *, BtIntPtr);
    BT_IDO_ONLY(extern u8 D_801354B0[];)
    s32 index;
    PlayerState *temp_s0;
    s32 var_s2;
    s32 result;
    s32 sentinel;

    for (index = 0, var_s2 = 0, sentinel = 0xFF; index < 8; index++) {
        temp_s0 = D_80135490.players[index];
        if ((temp_s0 != NULL) && (temp_s0->unk17C != 0)) {
            result = func_80092258(temp_s0);
            if (sentinel == result) {
                func_80098BA8(temp_s0, arg0);
            } else {
                BT_DATA_FIELD(D_80135490.draw_order[var_s2], D_80135490.players[var_s2 + 10]) = temp_s0;
                var_s2++;
            }
        }
    }
    BT_DATA_FIELD(D_80135490.draw_count, *(u8 *)((u8 *)D_80135490.players + 0x48)) = var_s2;
}

void func_800F50D0(BtIntPtr arg0) {
    void _bainvisible_entrypoint_9(void **arg0, s32 arg1, void *arg2);
    void func_80098BA8(void *, BtIntPtr);
    BT_IDO_ONLY(s32) BT_NATIVE_ONLY(BtIntPtr) func_800A8984(s32);
    s32 func_800A89F8();
    void func_800CA7E4(BtIntPtr, s32 *);
    BT_IDO_ONLY(extern s32 D_801354B8;)
    s32 sp38[4];
    s32 var_s0;

    if (BT_DATA_FIELD(D_80135490.draw_count, (*(u8 *)((s8 *)(D_80135490.players) + (0x48)))) != 0) {
        func_800CA7E4(func_800A8984(func_800A89F8()), sp38);
        _bainvisible_entrypoint_9(BT_DATA_FIELD((void **)D_80135490.draw_order, &D_801354B8), BT_DATA_FIELD(D_80135490.draw_count, (*(u8 *)((s8 *)(D_80135490.players) + (0x48)))), sp38);
        for (var_s0 = 0; var_s0 < (s32) BT_DATA_FIELD(D_80135490.draw_count, (*(u8 *)((s8 *)(D_80135490.players) + (0x48)))); var_s0++) {
            func_80098BA8(BT_DATA_FIELD(D_80135490.draw_order[var_s0], D_80135490.players[var_s0 + 10]), arg0);
        }
    }
}

void func_800F5184(void) {
    void func_80093528(PlayerState *);
    func_800F47C0(&func_80093528);
}

void func_800F51A8(void) {
    void func_80093584(PlayerState *);
    func_800F47C0(&func_80093584);
}

void func_800F51CC(void) {
    void func_80098BE0(PlayerState *);
    func_800F47C0(&func_80098BE0);
}

void func_800F51F0(s32 arg0 BT_PASS2(, BT_PASS2(f32 *bt_a1, f32 *bt_a2)))
{
    BT_NATIVE_ONLY(void func_80093504(void *, f32 *, f32 *);)
    func_80093504(D_80135490.players[arg0] BT_PASS2(, BT_PASS2(bt_a1, bt_a2)));
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F521C(s32 arg0, s32 arg1) {
    PlayerState *sp1C;
    sp1C = D_80135490.players[arg0];
    bs_setState((BtIntPtr)sp1C, _badata_entrypoint_35(sp1C));
    BT_NATIVE_ONLY(return) func_800F457C(sp1C, arg1);
}

s32 func_800F5268(s32 arg0) {
    s32 _bafpctrl_entrypoint_4();
    s32 _bafpctrl_entrypoint_5(PlayerState *);

    if (_bafpctrl_entrypoint_4(D_80135490.players[arg0]) != 3) {
        return 0;
    }
    if (&_bafpctrl_entrypoint_5 != NULL) {
        return 2;
    }
    return 1;
}

s32 func_800F52B8(BtIntPtr arg0, Unk80132ED0 *arg1)
{
    return func_8008EF3C(D_80135490.players[arg0], arg1);
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F52E4(s32 arg0 BT_PASS2(, s32 bt_a1))
{
    BT_NATIVE_ONLY(return) func_8008F4F0(D_80135490.players[arg0] BT_PASS2(, bt_a1));
}

s32 func_800F5310(void) {
    s32 count = 0;
    s32 i;

    for (i = 0; i < 8; i++) {
        if (D_80135490.players[i] != NULL) {
            count++;
        }
    }
    return count;
}

AnimCtrl* func_800F5378(s32 arg0)
{
    return baanim_getAnimCtrlPtr(D_80135490.players[arg0]);
}

void func_800F53A4(s32 arg0)
{
    func_8008E938(D_80135490.players[arg0]);
}

PlayerState *func_800F53D0(BtIntPtr arg0) {
    return D_80135490.players[arg0];
}

PlayerState *func_800F53E4(s32 arg0) {
    if ((arg0 >= 0) && (arg0 < 8)) {
        return D_80135490.players[arg0];
    }
    return NULL;
}

s32 func_800F5410(BtIntPtr arg0)
{
    return func_800A3274(D_80135490.players[arg0]);
}

s32 func_800F543C(BtIntPtr arg0)
{
    return ALLOW_SHIFT(func_800A3274(D_80135490.players[arg0]));
}

void func_800F5470(s32 arg0 BT_PASS2(, s32 bt_a1))
{
    func_80098590(D_80135490.players[arg0] BT_PASS2(, bt_a1));
}

/* extern */

f32 func_800F549C(BtIntPtr arg0, int arg1) {
    f32 bastatetimer_get(PlayerState *, int);
    PlayerState *temp_a2;

    temp_a2 = D_80135490.players[arg0];
    if (temp_a2 != NULL) {
        return bastatetimer_get(temp_a2, arg1);
    }
    return 0.0f;
}

//Get Which Character is in Control
u32 func_800F54E4(void)
{
	return BT_DATA_FIELD(D_80135490.current_player, D_801354DC);
}

s32 func_800F54F0(BtIntPtr arg0)
{
    return bakey_getControllerIndex(D_80135490.players[arg0]);
}

/* extern */

void func_800F551C(s32 arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    void func_800A3148(PlayerState *arg0, f32 *arg1, f32 *arg2, f32 *arg3);
    &arg0;
    func_800A3148(D_80135490.players[arg0], arg1, arg2, arg3);
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F554C(s32 arg0)
{ BT_NATIVE_ONLY(f32 func_80092BDC();)
    BT_IDO_ONLY(func_80092BDC(D_80135490.players[arg0]);) BT_NATIVE_ONLY(return ((union { f32 f; s32 i; }){ .f = func_80092BDC(D_80135490.players[arg0]) }).i;)
}

s32 func_800F5578(BtIntPtr arg0)
{
    return func_800A1718(D_80135490.players[arg0]);
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F55A4(BtIntPtr arg0)
{
    BT_NATIVE_ONLY(return) func_800A1760(D_80135490.players[arg0]);
}

Unk80132ED0 *func_800F55D0(BtIntPtr arg0)
{
    BtIntPtr func_800965D4(void *arg0);
    return func_800965D4(D_80135490.players[arg0]);
}

s32 func_800F55FC(BtIntPtr arg0)
{
    return func_80096628(D_80135490.players[arg0]);
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F5628(BtIntPtr arg0)
{ BT_NATIVE_ONLY(f32 func_80096364();)
    BT_IDO_ONLY(func_80096364(D_80135490.players[arg0]);) BT_NATIVE_ONLY(return ((union { f32 f; s32 i; }){ .f = func_80096364(D_80135490.players[arg0]) }).i;)
}

void func_800F5654(s32 arg0)
{
    func_80096670(D_80135490.players[arg0]);
}

void func_800F5680(s32 arg0 BT_PASS2(, s32 bt_a1))
{
    func_800963C0(D_80135490.players[arg0] BT_PASS2(, bt_a1));
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F56AC(BtIntPtr arg0)
{
    BT_NATIVE_ONLY(return) func_80096694(D_80135490.players[arg0]);
}

Unk80132ED0* func_800F56D8(BtIntPtr arg0)
{
    return _bahold_entrypoint_5(D_80135490.players[arg0]);
}

u32 func_800F5704(s32 arg0) {
    Unk80132ED0 *temp_v0;
    Actor *actor;

    temp_v0 = _bahold_entrypoint_5(D_80135490.players[arg0]);
    if (temp_v0 != NULL) {
        actor = func_80106790(temp_v0);
        return (u32) actor->unk6C_9;
    }
    return 0;
}

u32 func_800F5754(s32 arg0) {
    Unk80132ED0 *temp_v0;

    temp_v0 = _bahold_entrypoint_5(D_80135490.players[arg0]);
    if (temp_v0 != NULL) {
        return (u32) temp_v0->unk24 >> 22;
    }
    return 0;
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F5794(BtIntPtr arg0 BT_PASS2(, BT_PASS2(s32 bt_a1, s32 bt_a2)))
{ BT_NATIVE_ONLY(f32 func_800F3B3C();)
    BT_IDO_ONLY(func_800F3B3C(D_80135490.players[arg0]);) BT_NATIVE_ONLY(return ((union { f32 f; s32 i; }){ .f = func_800F3B3C(D_80135490.players[arg0] BT_PASS2(, BT_PASS2(bt_a1, bt_a2))) }).i;)
}

/* extern */

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F57C0(BtIntPtr arg0) {
    s32 func_8008E9B8(PlayerState *, s32 **);
    s32 *sp18[2];

    BT_NATIVE_ONLY(return) func_8008E9B8(D_80135490.players[arg0], sp18);
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F57F0(BtIntPtr arg0 BT_PASS2(, s32 bt_a1))
{ BT_NATIVE_ONLY(f32 func_800F3B90();)
    BT_IDO_ONLY(func_800F3B90(D_80135490.players[arg0]);) BT_NATIVE_ONLY(return ((union { f32 f; s32 i; }){ .f = func_800F3B90(D_80135490.players[arg0] BT_PASS2(, bt_a1)) }).i;)
}

s32 func_800F581C(BtIntPtr arg0) {
    s32 func_80096434(PlayerState *);
    s32 func_8009650C(PlayerState *);
    PlayerState *temp_a0;
    s32 pad;
    s32 var_v1;

    temp_a0 = D_80135490.players[arg0];
    if (func_8009650C(temp_a0) != 0) {
        var_v1 = func_80096434(temp_a0);
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

void func_800F586C(BtIntPtr arg0 BT_PASS2(, BT_PASS2(s32 bt_a1, s32 bt_a2)))
{
    func_80098B5C(D_80135490.players[arg0] BT_PASS2(, BT_PASS2(bt_a1, bt_a2)));
}

s32 func_800F5898(void)
{
	return 8;
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F58A0(s32 arg0)
{ BT_NATIVE_ONLY(f32 _bswalk_entrypoint_0();)
    BT_IDO_ONLY(_bswalk_entrypoint_0(D_80135490.players[arg0]);) BT_NATIVE_ONLY(return ((union { f32 f; s32 i; }){ .f = _bswalk_entrypoint_0(D_80135490.players[arg0]) }).i;)
}

#ifdef BT_NATIVE
void func_800F58CC(s32 arg0, s32 bt_a1)
#else
void func_800F58CC(s32 arg0)
#endif
{
    func_80096394(D_80135490.players[arg0]);
}

s32 func_800F58F8(BtIntPtr arg0)
{
    return func_800A3354(D_80135490.players[arg0]);
}

s32 func_800F5924(BtIntPtr arg0)
{
    return func_800A3360(D_80135490.players[arg0]);
}

/* extern */

void func_800F5950(s32 arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    void func_800A3148(PlayerState *arg0, f32 *arg1, f32 *arg2, f32 *arg3);
    f32 sp24;
    f32 sp20;
    f32 sp1C;

    func_800A3148(D_80135490.players[arg0], &sp24, &sp20, &sp1C);
    *arg1 = (sp1C * 0.5f) + sp20;
    *arg2 = sp20 - (sp1C * 0.5f);
    *arg3 = sp24;
}

void func_800F59D4(s32 arg0)
{
    _bapackctrl_entrypoint_1(D_80135490.players[arg0]);
}

void func_800F5A00(BtIntPtr arg0,f32* a1)
{
    func_800F3BB0(D_80135490.players[arg0],a1);
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F5A2C(BtIntPtr arg0 BT_PASS2(, BT_PASS2(s32 bt_a1, s32 bt_a2)))
{
    BT_NATIVE_ONLY(return) func_800F3BD0(D_80135490.players[arg0] BT_PASS2(, BT_PASS2(bt_a1, bt_a2)));
}

void func_800F5A58(s32 index, s32 position[3]) {
    f32 pos[3];
    func_800F3BB0(D_80135490.players[index], pos);
    position[0] = (s32)pos[0];
    position[1] = (s32)pos[1];
    position[2] = (s32)pos[2];
}

f32 func_800F5AD0(s32 arg0) {
    return 4.0f;
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F5AE0(s32 arg0)
{ BT_NATIVE_ONLY(f32 func_8009BFCC();)
    BT_IDO_ONLY(func_8009BFCC(D_80135490.players[arg0]);) BT_NATIVE_ONLY(return ((union { f32 f; s32 i; }){ .f = func_8009BFCC(D_80135490.players[arg0]) }).i;)
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F5B0C(BtIntPtr arg0)
{
    BT_NATIVE_ONLY(return) func_8009CC68(D_80135490.players[arg0]);
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F5B38(BtIntPtr arg0, f32 *arg1)
{
    BT_NATIVE_ONLY(return) func_800F3E84(D_80135490.players[arg0], arg1);
}

f32 func_800F5B64(s32 arg0, f32 *arg1) {
    void func_80095870(void *arg0, f32 *arg1, f32 *arg2);
    f32 sp24;
    f32 sp20;
    PlayerState *temp_a0;

    temp_a0 = D_80135490.players[arg0];
    func_80095870(temp_a0, &sp20, &sp24);
    func_8009C128(temp_a0, arg1);
    arg1[1] += sp20;
    return sp24;
}

f32 func_80092B8C(PlayerState *, f32 *);

BT_IDO_ONLY(void) BT_NATIVE_ONLY(f32) func_800F5BC4(BtIntPtr arg0, f32 *arg1)
{
    BT_NATIVE_ONLY(return) func_80092B8C(D_80135490.players[arg0], arg1);
}

f32 func_800F5BF0(BtIntPtr arg0, f32 *arg1) {
    f32 sp2C;
    f32 sp20[3];
    PlayerState *sp1C;

    sp1C = D_80135490.players[arg0];
    sp2C = func_80092B8C(sp1C, arg1);
    func_8009C128(sp1C, sp20);
    func_800EF04C(arg1, sp20);
    return sp2C;
}

/* extern */

f32 func_800F5C44(BtIntPtr arg0) {
    f32 _basnowball_entrypoint_4(PlayerState *);
    volatile PlayerState *sp1C;
    sp1C = D_80135490.players[arg0];
    if (func_800A3274((PlayerState *)sp1C) != TRANSFORM_2_SNOWBALL) {
        return 0.0f;
    }
    return _basnowball_entrypoint_4((PlayerState *)sp1C);
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F5C94(BtIntPtr arg0)
{
    BT_NATIVE_ONLY(return) func_800F3ED0(D_80135490.players[arg0]);
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F5CC0(s32 arg0)
{ BT_NATIVE_ONLY(f32 bastick_getAngle();)
    BT_IDO_ONLY(bastick_getAngle(D_80135490.players[arg0]);) BT_NATIVE_ONLY(return ((union { f32 f; s32 i; }){ .f = bastick_getAngle(D_80135490.players[arg0]) }).i;)
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F5CEC(s32 arg0)
{ BT_NATIVE_ONLY(f32 bastick_distance();)
    BT_IDO_ONLY(bastick_distance(D_80135490.players[arg0]);) BT_NATIVE_ONLY(return ((union { f32 f; s32 i; }){ .f = bastick_distance(D_80135490.players[arg0]) }).i;)
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F5D18(BtIntPtr arg0)
{
    BT_NATIVE_ONLY(return) func_800F40EC(D_80135490.players[arg0]);
}

void func_800F5D44(BtIntPtr arg0, f32* arg1)
{
    func_800A33CC(D_80135490.players[arg0],arg1);
}

#ifdef BT_NATIVE
void func_800F5D70(BtIntPtr arg0, f32 *bt_a1)
#else
void func_800F5D70(s32 arg0)
#endif
{
    BT_NATIVE_ONLY(void func_8009BB24(PlayerState *, f32 *);)
    func_8009BB24(D_80135490.players[arg0] BT_PASS2(, bt_a1));
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F5D9C(BtIntPtr arg0 BT_PASS2(, s32 bt_a1))
{
    BT_NATIVE_ONLY(return) func_800F4200(D_80135490.players[arg0] BT_PASS2(, bt_a1));
}

/* extern */

void func_800F5DC8(BtIntPtr arg0, f32 rotation[3]) {
    f32 func_8009BFD8(PlayerState *);
    f32 baroll_getIdeal(PlayerState *);
    volatile PlayerState *sp1C;

    sp1C = D_80135490.players[arg0];
    rotation[0] = func_8009BFD8((PlayerState *)sp1C);
    rotation[1] = yaw_getIdeal((PlayerState *)sp1C);
    rotation[2] = baroll_getIdeal((PlayerState *)sp1C);
}

void func_800F5E24(s32 arg0)
{
    func_800966BC(D_80135490.players[arg0]);
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F5E50(BtIntPtr arg0)
{
    BT_NATIVE_ONLY(return) func_800966E0(D_80135490.players[arg0]);
}

void func_800F5E7C(BtIntPtr arg0) {
    PlayerState *sp1C;
    sp1C = D_80135490.players[arg0];
    if (func_80096544(sp1C) != 0) {
        func_800964DC(sp1C);
        return;
    }
    func_8009C150(sp1C);
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F5ECC(s32 arg0)
{
    BT_NATIVE_ONLY(return) func_800A4C68(D_80135490.players[arg0]);
}

BT_NATIVE_ONLY(s16 *func_800A4C88(void *);) BT_IDO_ONLY(void) BT_NATIVE_ONLY(BtIntPtr) func_800F5EF8(BT_IDO_ONLY(BtIntPtr) BT_NATIVE_ONLY(u32) arg0)
{
    BT_NATIVE_ONLY(return (BtIntPtr)) func_800A4C88(D_80135490.players[arg0]);
}

f32 func_800F5F24(BtUIntPtr arg0)
{
    return yaw_get(D_80135490.players[arg0]);
}

f32 func_800F5F50(s32 arg0)
{
    return yaw_getIdeal(D_80135490.players[arg0]);
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(f32) func_800F5F7C(BtIntPtr arg0)
{
    BT_NATIVE_ONLY(return) func_8009C150(D_80135490.players[arg0]);
}

s32 func_800F5FA8(s32 arg0) {
    bakey_setState(D_80135490.players[arg0], BUTTON_B, 2);
    return 1;
}

s32 func_800F5FE0(BtIntPtr arg0) {
    bakey_setState(D_80135490.players[arg0], BUTTON_B, 0);
    return 1;
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F6018(s32 arg0) {
    BT_NATIVE_ONLY(return) bakey_setState(D_80135490.players[arg0], BUTTON_A, 2);
}

void func_800F604C(BtIntPtr arg0, s32 arg1) {
    func_8009EAD0(arg1);
    bs_setState(arg0, _badata_entrypoint_35(arg0));
    func_8009EAD0(1);
}

void func_800F608C(BtIntPtr arg0, s32 arg1) {
    PlayerState *self = D_80135490.players[arg0];

    switch (arg1) {
        case 1:
            bs_setState(self, _badata_entrypoint_35(self));
            break;
        case 2:
            func_800F604C(self, 4);
            break;
        case 3:
            func_800F604C(self, 3);
            break;
        case 4:
            func_800F604C(self, 2);
            break;
        case 5:
            func_800F604C(self, 5);
            break;
    }
}

s32 func_800F6140(s32 arg0) {
    s32 func_800A907C(s32, s32, s32);
    BtIntPtr func_800A93E4(BtIntPtr);
    BtIntPtr func_800A93F8(s32);
    s32 func_800A9768(s32);
    u8 *func_800F43A8(s32);
    BT_IDO_ONLY(extern u8 D_801354B0[];)
    s32 controller[2];
    PlayerState **player;
    s32 result;
    s32 index;

    player = D_80135490.players;
    index = 0;
    do {
        if (*player == NULL) {
            result = func_800A907C(index, arg0, -1);
            controller[0] = result;
            func_800A9768(result);
            func_800A93F8(index);
            func_800A93E4(index);
            *player = func_800F43A8(index);
            BT_DATA_FIELD(D_80135490.active, D_801354B0)[index] = 0;
            bakey_setControllerIndex(*player, controller[0]);
            return index;
        }
        index++;
        player++;
    } while (index != 8);
    return 0;
}

s32 func_800F61E4(void) {
    return func_800F6140(-1);
}

s32 func_800F6204(s32 arg0)
{
    BT_NATIVE_ONLY(return) func_800F6140(arg0);
}

s32 func_800F6224(s32 arg0)
{
  s32 func_800A907C(s32, s32, s32);
  void func_800A92A8(s32, s32);
  u8 *func_800F43A8(s32);
  BT_IDO_ONLY(void func_800F452C();)
  f32 position[3];
  s32 pad;
  PlayerState *player;
  PlayerState *source;
  s32 controller;
  s32 index;
 index = 0; loop: if (D_80135490.players[index] == NULL) { source = D_80135490.players[arg0];
    controller = bakey_getControllerIndex(source);
    controller = func_800A907C(index, controller, -1);
    player = func_800F43A8(index);
    D_80135490.players[index] = player;
    bakey_setControllerIndex(player, controller);
    func_800F3BB0(source, position);
    func_800F452C(player, position);
    yaw_setIdeal(player, yaw_getIdeal(source));
    yaw_applyIdeal(player);
    func_800A92A8(2, 2);
    return index;
  }

  index++;
  if (index == 8)
  {
    return 0;
  }
  goto loop;
}

BT_IDO_ONLY(void func_800F452C();)

PlayerState *func_800F6308(s32 arg0, s32 arg1, BT_IDO_ONLY(s32) BT_NATIVE_ONLY(f32 *) arg2) {
    s32 func_800A8FDC(void);
    s32 func_800A907C(s32, s32, s32);
    void func_800A92A8(s32, s32);
    u8 *func_800F43A8(s32);
    PlayerState *player;

    func_800A907C(arg0, arg1, func_800A8FDC());
    player = func_800F43A8(arg0);
    D_80135490.players[arg0] = player;
    bakey_setControllerIndex(player, arg1);
    func_800F452C(player, arg2);
    func_800A92A8(2, 2);
    return player;
}

void func_800F6388(BtIntPtr arg0, s32 arg1)
{
    func_8008F788(D_80135490.players[arg0],arg1);
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F63B4(s32 arg0 BT_PASS2(, s32 bt_a1))
{
    BT_NATIVE_ONLY(return) func_8008F7B4(D_80135490.players[arg0] BT_PASS2(, bt_a1));
}

void func_800F63E0(BtIntPtr arg0, u32 arg1)
{
    func_8008F854(D_80135490.players[arg0],arg1);
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F640C(BtIntPtr arg0 BT_PASS2(, s32 bt_a1))
{
    BT_NATIVE_ONLY(return) func_8008F828(D_80135490.players[arg0] BT_PASS2(, bt_a1));
}

s32 func_800F6438(BtUIntPtr arg0) {
    s32 func_800F4244(s32 *arg0);
    PlayerState *temp_a1;

    temp_a1 = D_80135490.players[arg0];
    if (temp_a1 == NULL) {
        return 0;
    }
    return func_800F4244((s32 *) temp_a1);
}

s32 func_800F6478(BtIntPtr arg0)
{
    return func_800F424C(D_80135490.players[arg0]);
}

//Tranformation Type is a bitfield so you can check multiple transformations at once
s32 func_800F64A4(BtIntPtr characterIndex, AllowedTransformation transformationType)
{
    return func_800F543C(characterIndex) & transformationType ? 1 : 0;
}

/* extern */

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F64DC(BtIntPtr arg0) {
    s32 bs_getCurrentState(PlayerState *);
    s32 func_8009CA70(PlayerState *, s32, s32);
    volatile PlayerState *sp1C;

    sp1C = D_80135490.players[arg0];
    BT_NATIVE_ONLY(return) func_8009CA70((PlayerState *)sp1C, bs_getCurrentState((PlayerState *)sp1C), 0x400000);
}

/* extern */

s32 func_800F651C(BtIntPtr arg0) {
    f32 baphysics_get_target_horizontal_velocity(PlayerState *);
    s32 bs_getCurrentState(PlayerState *);
    PlayerState *sp1C;

    sp1C = D_80135490.players[arg0];
    if (baphysics_get_target_horizontal_velocity(sp1C) == 0.0f) {
        return 1;
    }
    if (bs_getCurrentState(sp1C) == 1) {
        return 1;
    }
    return func_8009E674(sp1C, 0x1000);
}

/* extern */

s32 func_800F6590(BtIntPtr arg0) {
    s32 bs_getCurrentState(PlayerState *);
    s16 func_8009CBDC(PlayerState *arg0, s32 arg1);
    PlayerState *temp_a0;

    temp_a0 = D_80135490.players[arg0];
    return func_8009CBDC(temp_a0, bs_getCurrentState(temp_a0)) == 0xA;
}

s32 func_800F65D0(BtIntPtr arg0) {
    extern u8 D_8012762C;
    s32 result;
    if (D_8012762C == 0x1B) {
        result = 1;
    } else {
        result = arg0 == BT_DATA_FIELD(D_80135490.current_player, D_801354DC);
    }
    return result;
}

/* extern */

s32 func_800F6604(BtIntPtr arg0) {
    s32 _bacough_entrypoint_1(PlayerState *);
    return _bacough_entrypoint_1(D_80135490.players[arg0]) == 2;
}

s32 func_800F6634(s32 arg0)
{
	return 0;
}

int func_800F6640(s32 arg0) {
    s32 func_80091E80(PlayerState *, s32);
    u32 func_80092EA4(u32 *);
    PlayerState *self;

    self = D_80135490.players[arg0];
    return func_80092EA4((u32 *)self) && func_80091E80(self, 1);
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F6690(s32 arg0)
{
    BT_NATIVE_ONLY(return) func_80092EB0(D_80135490.players[arg0]);
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F66BC(s32 arg0, BtIntPtr arg1, f32 arg2) {
    int func_8008DAE8(PlayerState *player, f32 *target, f32 tolerance);
    BT_NATIVE_ONLY(return) func_8008DAE8(D_80135490.players[arg0], arg1, arg2);
}

/* extern */

s32 func_800F66F0(BtIntPtr arg0) {
    s32 bs_getCurrentState(PlayerState *);
    return bs_getCurrentState(D_80135490.players[arg0]) == 0x6F;
}

int func_800F6720(BtIntPtr arg0) {
    s32 func_8008DE74(PlayerState *);
    s32 func_8009E71C(PlayerState *, s32);
    PlayerState *self;

    self = D_80135490.players[arg0];
    return func_8009E71C(self, 9) || func_8008DE74(self);
}

int func_800F6774(BtUIntPtr arg0) {
    int func_800A8264(void);
    s32 func_800F6D24(BtIntPtr);
    int func_800F8088(BtIntPtr);
    s32 func_800F68B8(BtIntPtr);
    s32 func_800F6CC8(BtIntPtr);
    return func_800F6D24(arg0) == 0
        && func_800F8088(arg0) == 0
        && func_800F68B8(arg0) == 0
        && func_800F6CC8(arg0) == 0
        && func_800A8264() == 0;
}

/* extern */

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F67EC(BtIntPtr arg0) {
    s32 bs_getCurrentState(PlayerState *);
    s32 func_8009CA70(PlayerState *, s32, s32);
    PlayerState *sp1C;

    sp1C = D_80135490.players[arg0];
    BT_NATIVE_ONLY(return) func_8009CA70(sp1C, bs_getCurrentState(sp1C), 0x200);
}

s32 func_800F682C(s32 arg0) {
    u32 func_8009BD44(void *);
    s32 func_800F6478(BtIntPtr);
    s32 func_800F6C1C(s32);
    s32 func_800F6D24(BtIntPtr);

    if (func_800F6D24(arg0) != 0) {
        return 0;
    }
    if (func_800F6478(arg0) == 0) {
        return 0;
    }
    if (func_8009BD44(D_80135490.players[arg0]) == 3) {
        return 0;
    }
    if (func_800F6C1C(arg0) == 0) {
        return 0;
    }
    return 1;
}

/* extern */

s32 func_800F68B8(BtIntPtr arg0) {
    s32 func_8009E674(PlayerState *, s32);
    PlayerState *sp1C;
    s32 pad[1];

    sp1C = D_80135490.players[arg0];
    if (func_8009E674(sp1C, 8) != 0) {
        return _badrone_entrypoint_3(sp1C) == 1;
    }
    return 0;
}

/* extern */

s32 func_800F690C(BtIntPtr arg0) {
    s32 baflag_isTrue(PlayerState *, s32);
    return baflag_isTrue(D_80135490.players[arg0], 0x17);
}

s32 func_800F693C(BtIntPtr arg0) {
    s32 func_8008DD70(PlayerState *);
    return func_8008DD70(D_80135490.players[arg0]);
}

int func_800F6968(s32 arg0) {
    PlayerState *self;
    s32 pad;
    f32 height;
    s32 result;

    self = D_80135490.players[arg0];
    height = func_800964DC(self);
    result = height - func_8009C150(self) > 4.0f;
    return result && (func_800966BC(self) & 0x2000);
}

int func_800F69E8(s32 arg0) {
    PlayerState *self;

    self = D_80135490.players[arg0];
    return player_isStable(self) && func_8009659C(self, 0x2000);
}

s32 func_800F6A38(BtIntPtr arg0) {
    PlayerState *self;
    s32 result;

    self = D_80135490.players[arg0];
    if (player_inWater(self) == 0) {
        return 0;
    }
    if ((func_800966BC(self) & 0x22000) == 0x22000) {
        result = 1;
    } else {
        result = 0;
    }
    return result;
}

/* extern */

int func_800F6AA4(BtIntPtr arg0) {
    s32 bs_getCurrentState(PlayerState *);
    s32 state;

    state = bs_getCurrentState(D_80135490.players[arg0]);
    return state == 0x1B
        || state == 0x1C
        || state == 0x1D
        || state == 0x1E
        || state == 0x1A
        || state == 0xA4
        || state == 0xA5;
}

u8 func_800F6B34(void) {
	return BT_DATA_FIELD(D_80135490.resetting, D_801354DA);
}

int func_800F6B40(BtIntPtr arg0) {
    if (func_800F690C(arg0)) {
        return 1;
    }
    return _ncba1p_entrypoint_10(func_800A4CA8(D_80135490.players[arg0])) == 3;
}

int func_800F6B94(BtIntPtr arg0) {
    PlayerState *temp_a0;
    s32 pad;

    temp_a0 = D_80135490.players[arg0];
    return (func_800A3274(temp_a0) == TRANSFORM_2_SNOWBALL) && (func_800A1718(temp_a0) >= 5);
}

s32 func_800F6BE4(BtIntPtr arg0) {
    if ((arg0 >= 0) && (arg0 < 8) && (D_80135490.players[arg0] != NULL)) {
        return 1;
    }
    return 0;
}

/* extern */

s32 func_800F6C1C(s32 arg0) {
    s32 bs_getCurrentState(PlayerState *);
    void (*func_8009CB44(PlayerState *arg0, s32 arg1))(PlayerState *);
    PlayerState *temp_a0;

    temp_a0 = D_80135490.players[arg0];
    return func_8009CB44(temp_a0, bs_getCurrentState(temp_a0)) != 0;
}

s32 func_800F6C5C(BtIntPtr arg0)
{
    return player_isStable(D_80135490.players[arg0]);
}

/* extern */

s32 func_800F6C88(BtIntPtr arg0) {
    s32 bs_getCurrentState(PlayerState *);
    s16 func_8009CBDC(PlayerState *arg0, s32 arg1);
    PlayerState *temp_a0;

    temp_a0 = D_80135490.players[arg0];
    return func_8009CBDC(temp_a0, bs_getCurrentState(temp_a0)) == 0x2;
}

/* extern */

s32 func_800F6CC8(BtIntPtr arg0) {
    s32 func_8009E674(PlayerState *, s32);
    if (func_8009E674(D_80135490.players[arg0], 4) != 0) {
        return 1;
    }
    if (func_800F8B64() != 0) {
        return 1;
    }
    return 0;
}

s32 func_800F6D24(BtIntPtr arg0)
{
    return func_8008E124(D_80135490.players[arg0]);
}

int func_800F6D50(s32 arg0) {
    PlayerState *self;

    self = D_80135490.players[arg0];
    return func_8008E124(self) && func_8009E674(self, 0x10);
}

/* extern */

s32 func_800F6DA0(BtIntPtr arg0) {
    s32 bs_getCurrentState(PlayerState *);
    s16 func_8009CBDC(PlayerState *arg0, s32 arg1);
    PlayerState *temp_a0;

    temp_a0 = D_80135490.players[arg0];
    return func_8009CBDC(temp_a0, bs_getCurrentState(temp_a0)) == 0x12;
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F6DE0(BT_NATIVE_ONLY(s32 bt_a0))
{
    BT_NATIVE_ONLY(return) _bsbabykaz_entrypoint_14(BT_NATIVE_ONLY(bt_a0));
}

/* extern */

s32 func_800F6E00(BtIntPtr arg0) {
    s32 bs_getCurrentState(PlayerState *);
    s32 func_8009CA70(PlayerState *, s32, s32);
    volatile PlayerState *sp1C;

    sp1C = D_80135490.players[arg0];
    BT_NATIVE_ONLY(return) func_8009CA70((PlayerState *)sp1C, bs_getCurrentState((PlayerState *)sp1C), 0x100000);
}

/* extern */

s32 func_800F6E40(BtIntPtr arg0) {
    s32 bs_getCurrentState(PlayerState *);
    s16 func_8009CBDC(PlayerState *arg0, s32 arg1);
    PlayerState *temp_a0;

    temp_a0 = D_80135490.players[arg0];
    return func_8009CBDC(temp_a0, bs_getCurrentState(temp_a0)) == 0x13;
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F6E80(s32 arg0)
{
    BT_NATIVE_ONLY(return) func_800A336C(D_80135490.players[arg0]);
}

s32 func_800F6EAC(s32 arg0) {
    s32 func_8009E674(PlayerState *, s32);
    PlayerState *temp_a0;
    s32 pad[1];

    temp_a0 = D_80135490.players[arg0];
    if (func_8009E674(temp_a0, 8) != 0) {
        return _badrone_entrypoint_3(temp_a0) == 9;
    }
    return 0;
}

s32 func_800F6F00(s32 arg0) {
    s32 _badata_entrypoint_14(PlayerState *);
    extern void func_800F58CC();
    extern void func_800F5D70();
    f32 sp2C[3];
    f32 sp20[3];
    s32 pad[2];

    if (_badata_entrypoint_14(D_80135490.players[arg0]) == 0) {
        return 1;
    }
#ifdef BT_NATIVE
    ((void (*)())func_800F58CC)(arg0, sp2C);
#else
    func_800F58CC(arg0, sp2C);
#endif
    if ((0.0f != sp2C[0]) || (0.0f != sp2C[2])) {
        return 0;
    }
    if (func_800F6C5C(arg0) == 0) {
        return 0;
    }
#ifdef BT_NATIVE
    ((void (*)())func_800F5D70)(arg0, sp20);
#else
    func_800F5D70(arg0, sp20);
#endif
    if (func_800F55FC(arg0) & 0x8000) {
        if ((sp20[1] < 0.0f) && (sp20[1] >= -1.0f)) {
            return 1;
        }
        return 0;
    }
    if (-1.0f != sp20[1]) {
        return 0;
    }
    return 1;
}

/* extern */

s32 func_800F7018(BtIntPtr arg0) {
    s32 bs_getCurrentState(PlayerState *);
    s16 func_8009CBDC(PlayerState *arg0, s32 arg1);
    PlayerState *temp_a0;

    temp_a0 = D_80135490.players[arg0];
    return func_8009CBDC(temp_a0, bs_getCurrentState(temp_a0)) == 0x8;
}

/* extern */

s32 func_800F7058(BtIntPtr arg0) {
    s32 _bashoes_entrypoint_1(PlayerState *);
    s32 func_8009E674(PlayerState *, s32);
    PlayerState *temp_a0;
    s32 pad[1];

    temp_a0 = D_80135490.players[arg0];
    if (func_8009E674(temp_a0, 0x80) != 0) {
        return _bashoes_entrypoint_1(temp_a0) == 3 ? 2 : 1;
    }
    return 0;
}

/* extern */

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F70BC(BtIntPtr arg0) {
    s32 func_8009E71C(PlayerState *, s32);
    BT_NATIVE_ONLY(return) func_8009E71C(D_80135490.players[arg0], 0xE);
}

/* extern */

s32 func_800F70EC(s32 arg0) {
    u32 func_8009BD44(void *);
    return func_8009BD44(D_80135490.players[arg0]) != 3;
}

/* extern */

s32 func_800F711C(s32 arg0) {
    s32 func_8009E674(PlayerState *, s32);
    return func_8009E674(D_80135490.players[arg0], 8) == 0;
}

/* extern */

s32 func_800F7150(BtIntPtr arg0) {
    s32 func_80094510(PlayerState *);
    return func_80094510(D_80135490.players[arg0]) == 0x7;
}

s32 func_800F7180(s32 arg0) {
    s32 func_8009E674(PlayerState *, s32);
    PlayerState *temp_a0;
    s32 pad[1];

    temp_a0 = D_80135490.players[arg0];
    if (func_8009E674(temp_a0, 8) != 0) {
        return _badrone_entrypoint_3(temp_a0) == 14;
    }
    return 0;
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F71D4(BtIntPtr arg0)
{
    BT_NATIVE_ONLY(return) func_8008E37C(D_80135490.players[arg0]);
}

/* extern */

s32 func_800F7200(BtIntPtr arg0, f32 arg1[3], f32 arg2, s32 arg3, Actor **arg4) {
    s32 func_8008DDEC(PlayerState *, f32[3], f32);
    s32 func_8008F568(BtIntPtr, s32, Actor **);
    PlayerState *sp1C;

    sp1C = D_80135490.players[arg0];
    if ((arg2 < 0.0f) || (func_8008DDEC(sp1C, arg1, arg2) != 0)) {
        return func_8008F568(sp1C, arg3, arg4);
    }
    return 0;
}

/* extern */

s32 func_800F7270(s32 arg0, f32 arg1[3], f32 arg2, f32 arg3, s32 arg4, Actor **arg5) {
    int func_8008DEA4(PlayerState *, f32[3], f32);
    if (func_8008DEA4(D_80135490.players[arg0], arg1, arg3) != 0) {
        return func_800F7200(arg0, arg1, arg2, arg4, arg5);
    }
    return 0;
}

/* extern */

int func_800F72DC(BtIntPtr arg0) {
    s32 baflag_isTrue(PlayerState *, s32);
    s32 func_8009640C(PlayerState *);
    PlayerState *temp_a0;

    temp_a0 = D_80135490.players[arg0];
    return (func_8009640C(temp_a0) != 0) || (baflag_isTrue(temp_a0, 0x26) != 0);
}

/* extern */

void func_800F732C(void) {
    void func_800F482C(s32);
    BT_DATA_FIELD(D_80135490.resetting, D_801354DA) = 1;
    func_800F482C(0x11);
    func_800F482C(0);
    BT_DATA_FIELD(D_80135490.resetting, D_801354DA) = 0;
}

void func_800F7364(s32 arg0) {
    void func_80092AA4(PlayerState* arg0);
    PlayerState *temp_a1;

    temp_a1 = D_80135490.players[arg0];
    if (temp_a1 != NULL) {
        func_80092AA4(temp_a1);
    }
}

/* extern */

void func_800F739C(s32 arg0, s32 arg1) {
    void func_800C7074(s32 arg0, s32 arg1);
    func_800C7074(arg1, 1);
}

void func_800F73C4(s32 arg0) {
    int func_800DB9B0(void);
    u8 _glcutDll_entrypoint_1(void);
    s32 _plsu_entrypoint_1(s32);
    s32 func_800F5898(void);
    void func_800F80D8(u32);
    u8 func_800F8B88(void);
    s32 func_800F99E8(void);
    void func_800F8B94(void);
    BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F7E64(s32, s32);
    BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F8128(s32);
    void _basetup_entrypoint_2(struct player_state_s *arg0);
    s32 i;
    s32 count;
    s32 banjo;
    s32 kazooie;
    s32 selected;
    s32 j;

    D_80135490.resetting = 0;
    D_80135490.updating = 0;
    for (i = 0; i < 8; i++) {
        D_80135490.players[i] = NULL;
        if (&D_80135490.players[i]) {}
        D_80135490.active[i] = 0;
    }
    D_80135490.previous_mode = -1;
    D_80135490.previous_player = D_80135490.previous_mode;
    func_800F80D8(0);
    if (func_800DB9B0() == 0 && _glcutDll_entrypoint_1() == 0 && func_800F99E8() == 0) {
        i = 0;
        if (arg0 > 0) {
            do {
                func_800F61E4();
                i++;
            } while (i != arg0);
        }
    }
    i = 0;
    func_800F8B94();
    count = 0;
    for (; i < func_800F5898(); i++) {
        if (func_800F6BE4(i) != 0) {
            count++;
        }
    }
    if (count == 0) {
        func_800F7E64(func_800F61E4(), 4);
    }
    if (func_800F8B88() == 2) {
        banjo = _plsu_entrypoint_1(0xA);
        kazooie = _plsu_entrypoint_1(0xB);
        if (banjo != -1 && kazooie != -1) {
            if (func_800F65D0(kazooie) != 0) {
                selected = kazooie;
            } else if (func_800F65D0(banjo) != 0) {
                selected = banjo;
            } else {
                selected = _plsu_entrypoint_1(0x11);
            }
            func_800F8128(selected);
        }
    }
    for (j = 0; j < 8; j++) {
        if (D_80135490.players[j] != NULL) {
            _basetup_entrypoint_2(D_80135490.players[j]);
        }
    }
}

void func_800F759C(s32 arg0) {
    void func_800A91F4(s32);
    BT_LP64_ONLY(void) BT_IDO_ONLY(s32) BT_ILP32_ONLY(s32) func_800F3880(PlayerState *);
    s32 func_80101238(s32, s32);
    BT_IDO_ONLY(extern u8 D_801354B0[];)
    BT_IDO_ONLY(extern u8 D_801354D9;)
    PlayerState **sp24[1];
    PlayerState *player;

    if (BT_DATA_FIELD(D_80135490.updating, D_801354D9) != 0) {
        func_800F82C0(arg0);
        return;
    }
    func_80101238(0xB5, arg0);
    player = D_80135490.players[arg0];
    sp24[0] = &D_80135490.players[arg0];
    func_800F3880(player);
    func_800A91F4(arg0);
    *sp24[0] = NULL;
    BT_DATA_FIELD(D_80135490.active, D_801354B0)[arg0] = 0;
}

void func_800F7620(BtIntPtr arg0, f32 arg1, f32 arg2, f32 arg3) {
    void _bamotor_entrypoint_1(PlayerState *, f32, f32, f32);
    _bamotor_entrypoint_1(D_80135490.players[arg0], arg1, arg2, arg3);
}

void func_800F7664(s32 arg0, s32 arg1, s32 arg2) { void func_8009AD20(void *, s32); void func_8009AD2C(void *, s32); s32 func_8009E7C8(PlayerState *, s32); PlayerState *sp1C; sp1C = D_80135490.players[arg0]; func_8009AD20(sp1C, arg1); func_8009AD2C(sp1C, arg2); func_8009E7C8(sp1C, 0x7D); }

/* extern */
s32 func_800F76B0(BtIntPtr arg0, s32 arg1, BtIntPtr arg2) {
    void func_8009AD14(void *, BtIntPtr);
    void func_8009AD20(void *, s32);
    s32 func_8009E7C8(PlayerState *, s32);
    PlayerState *temp_a0;

    temp_a0 = D_80135490.players[arg0];
    func_8009AD20(temp_a0, arg1);
    func_8009AD14(temp_a0, arg2);
    return func_8009E7C8(temp_a0, 0x24) == 2;
}

/* extern */
int func_800F7700(BtIntPtr arg0, s32 arg1, f32 *arg2) { void func_8009AD20(void *, s32); void func_8009AD44(void *, void *); s32 func_8009E7C8(PlayerState *, s32); PlayerState *sp1C; sp1C = D_80135490.players[arg0]; func_8009AD20(sp1C, arg1); func_8009AD44(sp1C, arg2); return func_8009E7C8(sp1C, 0x23) == 2; }

int func_800F7750(BtIntPtr arg0, f32 *arg1, f32 arg2, f32 arg3, s32 arg4) {
    void func_8009ACF4(void *, f32);
    void func_8009AD04(void *, f32);
    void func_8009AD20(void *, s32);
    void func_8009AD44(void *, void *);
    s32 func_8009E7C8(PlayerState *, s32);
    s32 sp24;
    PlayerState *temp_s0;

    temp_s0 = D_80135490.players[arg0];
    if (arg4 != 0) {
        sp24 = 0x98;
    } else {
        sp24 = 0x2D;
    }
    func_8009ACF4(temp_s0, arg2);
    func_8009AD04(temp_s0, arg3);
    func_8009AD20(temp_s0, 0xE);
    func_8009AD44(temp_s0, arg1);
    return func_8009E7C8(temp_s0, sp24) == 2;
}

/* extern */

void func_800F77E8(BtIntPtr arg0, f32 *arg1) {
    int func_800F7750(BtIntPtr, f32 *, f32, f32, s32);
    func_800F7750(arg0, arg1, 840.0f, -1500.0f, 0);
}

/* extern */

void func_800F7814(BtIntPtr arg0, f32 *arg1) {
    int func_800F7750(BtIntPtr, f32 *, f32, f32, s32);
    func_800F7750(arg0, arg1, 840.0f, -1500.0f, 1);
}

/* extern */

s32 func_800F7844(BtUIntPtr arg0, f32 *arg1, f32 arg2, f32 arg3) { int func_800F7750(BtIntPtr, f32 *, f32, f32, s32); return func_800F7750(arg0, arg1, arg2, arg3, 0); }

s32 func_800F7874(s32 arg0, BtIntPtr arg1, void *arg2) {
    void func_8009AD14(void *, BtIntPtr);
    void func_8009AD44(void *, void *);
    s32 func_8009E7C8(PlayerState *, s32);
    PlayerState *temp_a0;

    temp_a0 = D_80135490.players[arg0];
    func_8009AD44(temp_a0, arg2);
    func_8009AD14(temp_a0, arg1);
    return func_8009E7C8(temp_a0, 0x66) == 2;
}

void func_800F78C8(s32 arg0,s32 arg1)
{
    func_800F7C58(arg0,0x17,arg1);
}

int func_800F78EC(BtIntPtr moving, f32 *target, f32 verticalSpeed, f32 horizontalSpeed) { void func_8009ACF4(void *, f32); void func_8009AD04(void *, f32); void func_8009AD20(void *, s32); void func_8009AD44(void *, void *); s32 func_8009E7C8(PlayerState *, s32); PlayerState *sp1C; sp1C = D_80135490.players[moving]; func_8009ACF4(sp1C, verticalSpeed); func_8009AD04(sp1C, horizontalSpeed); func_8009AD20(sp1C, 0xE); func_8009AD44(sp1C, target); return func_8009E7C8(sp1C, 0x68) == 2; }

 s32 func_800F798C(BtIntPtr, s32, s32);
BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F796C(BtIntPtr arg0,s32 arg1)
{
    BT_NATIVE_ONLY(return) func_800F798C(arg0,arg1,0x1);
}

/* extern */
s32 func_800F798C(BtIntPtr arg0, s32 arg1, s32 arg2) { void func_8009AD20(void *, s32); void func_8009AD2C(void *, s32); s32 func_8009E7C8(PlayerState *, s32); PlayerState *sp1C; sp1C = D_80135490.players[arg0]; func_8009AD20(sp1C, arg1); func_8009AD2C(sp1C, arg2); return func_8009E7C8(sp1C, 0x1F) == 2; }

/* extern */
s32 func_800F79DC(BtIntPtr arg0, s32 arg1, BtIntPtr arg2) {
    void func_8009AD14(void *, BtIntPtr);
    void func_8009AD20(void *, s32);
    s32 func_8009E7C8(PlayerState *, s32);
    PlayerState *temp_a0;

    temp_a0 = D_80135490.players[arg0];
    func_8009AD20(temp_a0, arg1);
    func_8009AD14(temp_a0, arg2);
    return func_8009E7C8(temp_a0, 0x21) == 2;
}

/* extern */
int func_800F7A2C(BtIntPtr arg0, s32 arg1, f32 *arg2) { void func_8009AD20(void *, s32); void func_8009AD44(void *, void *); s32 func_8009E7C8(PlayerState *, s32); PlayerState *sp1C; sp1C = D_80135490.players[arg0]; func_8009AD20(sp1C, arg1); func_8009AD44(sp1C, arg2); return func_8009E7C8(sp1C, 0x20) == 2; }

int func_800F7A7C(BtIntPtr arg0, s32 arg1, s32 arg2, s32 arg3, f32 *arg4) { void func_8009AD20(void *, s32); void func_8009AD2C(void *, s32); void func_8009AD38(void *, s32); void func_8009AD44(void *, void *); s32 func_8009E7C8(PlayerState *, s32); PlayerState *sp1C; sp1C = D_80135490.players[arg0]; func_8009AD38(sp1C, arg1); func_8009AD20(sp1C, arg2); func_8009AD2C(sp1C, arg3); func_8009AD44(sp1C, arg4); return func_8009E7C8(sp1C, 0x4E) == 2; }

/* extern */

void func_800F7AF4(s32 arg0, f32 *arg1) {
    int func_800F7B1C(s32, f32 *, f32, f32);
    func_800F7B1C(arg0, arg1, 840.0f, -1500.0f);
}

int func_800F7B1C(s32 moving, f32 *target, f32 verticalSpeed, f32 horizontalSpeed) { void func_8009ACF4(void *, f32); void func_8009AD04(void *, f32); void func_8009AD20(void *, s32); void func_8009AD44(void *, void *); s32 func_8009E7C8(PlayerState *, s32); PlayerState *sp1C; sp1C = D_80135490.players[moving]; func_8009ACF4(sp1C, verticalSpeed); func_8009AD04(sp1C, horizontalSpeed); func_8009AD20(sp1C, 0x10); func_8009AD44(sp1C, target); return func_8009E7C8(sp1C, 0x2E) == 2; }
BT_NATIVE_ONLY(s32 bt_native_func_800F7B9C(BtIntPtr, u32) __asm__("func_800F7B9C");)
BT_IDO_ONLY(void func_800F7B9C) BT_NATIVE_ONLY(s32 bt_native_func_800F7B9C)(BtIntPtr arg0,u32 a1)
{
    s32 func_8009E7C8(PlayerState *, s32);
    BT_NATIVE_ONLY(return) func_8009E7C8(D_80135490.players[arg0],a1);
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F7BC8(BtIntPtr arg0, s32 arg1, Unk80132ED0 *arg2) {
    void func_8009AD14(void *, BtIntPtr);
    s32 func_8009E7C8(PlayerState *, s32);
    volatile PlayerState *sp1C;

    sp1C = D_80135490.players[arg0];
    func_8009AD14((void *)sp1C, (BtIntPtr)arg2);
    BT_NATIVE_ONLY(return) func_8009E7C8(sp1C, arg1);
}

s32 func_800F7C0C(BtIntPtr arg0, s32 arg1, f32 arg2) {
    void func_8009ACF4(void *, f32);
    s32 func_8009E7C8(PlayerState *, s32);
    volatile PlayerState *sp1C;
    sp1C = D_80135490.players[arg0];
    func_8009ACF4((void *)sp1C, arg2);
    BT_NATIVE_ONLY(return) func_8009E7C8(sp1C, arg1);
}

int func_800F7C58(BtIntPtr arg0, s32 arg1, s32 arg2) {
    void func_8009AD20(void *, s32);
    s32 func_8009E7C8(PlayerState *, s32);
    volatile PlayerState *sp1C;

    sp1C = D_80135490.players[arg0];
    func_8009AD20((void *)sp1C, arg2);
    return func_8009E7C8(sp1C, arg1);
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F7C9C(BtIntPtr arg0, s32 arg1, s32 arg2, s32 arg3) {
    void func_8009AD20(void *, s32);
    void func_8009AD2C(void *, s32);
    s32 func_8009E7C8(PlayerState *, s32);
    volatile PlayerState *sp1C;

    sp1C = D_80135490.players[arg0];
    func_8009AD20((void *)sp1C, arg2);
    func_8009AD2C((void *)sp1C, arg3);
    BT_NATIVE_ONLY(return) func_8009E7C8(sp1C, arg1);
}

s32 func_800F7CF4(BtIntPtr arg0, s32 arg1, void *arg2) {
    void func_8009AD44(void *, void *);
    s32 func_8009E7C8(PlayerState *, s32);
    volatile PlayerState *sp1C;

    sp1C = D_80135490.players[arg0];
    func_8009AD44((void *)sp1C, arg2);
    return func_8009E7C8(sp1C, arg1);
}

s32 func_800F7D38(BtIntPtr arg0, s32 arg1, void *arg2, f32 arg3) {
    void func_8009AD44(void *, void *);
    void func_8009ACF4(void *, f32);
    s32 func_8009E7C8(PlayerState *, s32);
    volatile PlayerState *sp1C;
    sp1C = D_80135490.players[arg0];
    func_8009AD44((void *)sp1C, arg2);
    func_8009ACF4((void *)sp1C, arg3);
    return func_8009E7C8(sp1C, arg1);
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F7D90(BtIntPtr arg0, s32 arg1, void *arg2, s32 arg3) {
    void func_8009AD44(void *, void *);
    void func_8009AD20(void *, s32);
    s32 func_8009E7C8(PlayerState *, s32);
    volatile PlayerState *sp1C;
    sp1C = D_80135490.players[arg0];
    func_8009AD44((void *)sp1C, arg2);
    func_8009AD20((void *)sp1C, arg3);
    BT_NATIVE_ONLY(return) func_8009E7C8(sp1C, arg1);
}

/* extern */
s32 func_800F7DE8(s32 arg0, s32 arg1, s32 arg2) {
    void func_8009AD14(void *, BtIntPtr);
    void func_8009AD20(void *, s32);
    s32 func_8009E7C8(PlayerState *, s32);
    PlayerState *sp1C;

    sp1C = D_80135490.players[arg0];
    func_8009AD20(sp1C, arg2);
    func_8009AD14(sp1C, arg1);
    return func_8009E7C8(sp1C, 0x48) == 2;
}

s32 func_800F7E3C(BtIntPtr arg0, s32 arg1) {
    return func_800F7C58(arg0, 0x84, arg1) == 2;
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F7E64(s32 arg0, s32 arg1) {
    volatile PlayerState *sp1C;

    sp1C = D_80135490.players[arg0];
    func_800A3410((PlayerState *)sp1C, arg1);
    BT_NATIVE_ONLY(return) func_80092778((PlayerState *)sp1C);
}

/* extern */

void func_800F7E9C(s32 arg0, s32 arg1) {
    void func_800A4E74(BtIntPtr arg0);
    if (arg1 != 0) {
        func_800A4E74(D_80135490.players[arg0]);
    }
}

void func_800F7ECC(BtIntPtr arg0, s32 arg1, f32 arg2) {
    void bastatetimer_set(void *self, s32 id, f32 arg2);
    bastatetimer_set(D_80135490.players[arg0], arg1, arg2);
}

/* extern */

void func_800F7F00(BtIntPtr arg0, BtIntPtr arg1, BtIntPtr arg2, f32 arg3, s32 arg4, s32 arg5, f32 arg6) {
    void func_80098778(PlayerState *, BtIntPtr, BtIntPtr, f32, s32, s32, f32);
    func_80098778(D_80135490.players[arg0], arg1, arg2, arg3, arg4, arg5, arg6);
}

/* extern */

void func_800F7F50(BtIntPtr arg0, void *arg1, void *arg2, f32 arg3, s32 arg4, s32 arg5) {
    void func_80098730(u8 *, BtIntPtr, BtIntPtr, f32, s32, s32);
    func_80098730(D_80135490.players[arg0], arg1, arg2, arg3, arg4, arg5);
}

/* extern */

s32 func_800F7F98(BtIntPtr arg0, u32 arg1) {
    s32 bastick_func_8009F18C(PlayerState *, s32);
    PlayerState *sp1C;

    sp1C = D_80135490.players[arg0];
    if (arg1 != 0) {
        bakey_func_80091C14(sp1C, 1);
        return bastick_func_8009F18C(sp1C, 1);
    }
    bakey_func_80091C14(sp1C, 0);
    return bastick_func_8009F18C(sp1C, 0);
}

/* extern */

int func_800F8004(BtIntPtr arg0) {
    s32 bastick_func_8009EEF8(PlayerState *);
    s32 bastick_func_8009F1A4(PlayerState *);
    int keys;
    int stick;
    PlayerState *player;

    player = D_80135490.players[arg0];
    keys = bakey_getBitfield(player) || bakey_func_80091964(player);
    stick = bastick_func_8009F1A4(player) || bastick_func_8009EEF8(player);
    return keys && stick;
}

/* extern */

int func_800F8088(BtIntPtr arg0) {
    s32 bastick_func_8009F1A4(PlayerState *);
    int bitfield;
    s32 stick;
    PlayerState *player;
    s32 pad[2];

    player = D_80135490.players[arg0];
    bitfield = bakey_getBitfield(player);
    stick = bastick_func_8009F1A4(player);
    return bitfield && stick;
}

void func_800F80D8(u32 arg0) {
	BT_DATA_FIELD(D_80135490.current_player, D_801354DC) = arg0;
}

void func_800F80E4(BtIntPtr arg0, u32 arg1) {
    void func_800947EC(PlayerState *, s32, s32);
    s32 var_a2;
    PlayerState *player = D_80135490.players[arg0];

    if (arg1 != 0) {
        var_a2 = 0;
    } else {
        var_a2 = 1;
    }
    func_800947EC(player, 1, var_a2);
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F8128(s32 arg0)
{
    func_800F80D8(arg0);
    BT_NATIVE_ONLY(return) func_800A91A8(arg0);
}
BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F8150(BtIntPtr arg0 BT_PASS2(, s32 bt_a1))
{
    BT_NATIVE_ONLY(return) func_80093370(D_80135490.players[arg0] BT_PASS2(, bt_a1));
}

void func_800F817C(s32 arg0 BT_PASS2(, s32 bt_a1))
{
    func_8009337C(D_80135490.players[arg0] BT_PASS2(, bt_a1));
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F81A8(s32 arg0 BT_PASS2(, s32 bt_a1))
{
    BT_NATIVE_ONLY(return) func_800A1870(D_80135490.players[arg0] BT_PASS2(, bt_a1));
}

void func_800F81D4(BtIntPtr arg0 BT_PASS2(, s32 bt_a1))
{
    _bafpctrl_entrypoint_12(D_80135490.players[arg0] BT_PASS2(, bt_a1));
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F8200(s32 arg0 BT_PASS2(, s32 bt_a1))
{
    BT_NATIVE_ONLY(return) func_800F4524(D_80135490.players[arg0] BT_PASS2(, bt_a1));
}

/* extern */

void func_800F822C(BtIntPtr arg0, f32 arg1, f32 arg2) {
    void _bahold_entrypoint_7(PlayerState *, f32, f32);
    _bahold_entrypoint_7(D_80135490.players[arg0], arg1, arg2);
}

void func_800F8268(s32 arg0,s32 a1, s32 a2)
{
    func_800A38F0(D_80135490.players[arg0],a1,a2);
}

void func_800F8294(BtIntPtr arg0,f32* a1)
{
    func_800F452C(D_80135490.players[arg0],a1);
}

void func_800F82C0(s32 arg0) {
    BT_IDO_ONLY(extern u8 D_801354B0[];)
    BT_DATA_FIELD(D_80135490.active, D_801354B0)[arg0] = 1;
}
BT_NATIVE_ONLY(s32 bt_native_func_800F82D4(BtIntPtr, s32) __asm__("func_800F82D4");)
BT_IDO_ONLY(void func_800F82D4) BT_NATIVE_ONLY(s32 bt_native_func_800F82D4)(BtIntPtr arg0,s32 arg1)
{
    BT_NATIVE_ONLY(return) func_800F457C(D_80135490.players[arg0],arg1);
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F8300(BtIntPtr arg0 BT_PASS2(, BT_PASS2(s32 bt_a1, s32 bt_a2)))
{
    BT_NATIVE_ONLY(return) func_800F45B0(D_80135490.players[arg0] BT_PASS2(, BT_PASS2(bt_a1, bt_a2)));
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F832C(BtIntPtr arg0,f32* a1)
{
    BT_NATIVE_ONLY(return) func_800F45E0(D_80135490.players[arg0],a1);
}

/* extern */

void func_800F8358(s32 arg0, s32 arg1) {
    void _baduo_entrypoint_7(PlayerState *arg0, s32 arg1);
    _baduo_entrypoint_7(D_80135490.players[arg0], 3);
}

void func_800F838C(s32 arg0 BT_PASS2(, BT_PASS2(s32 actor_id, Actor *actor)))
{
    BT_NATIVE_ONLY(void func_8008F748(PlayerState *, s32, Actor *);) func_8008F748(D_80135490.players[arg0] BT_PASS2(, BT_PASS2(actor_id, actor)));
}

void func_800F83B8(s32 arg0 BT_PASS2(, f32 *source))
{
    func_800A3514(D_80135490.players[arg0] BT_PASS2(, source));
}

void func_800F83E4(BtIntPtr arg0, f32 arg1) {
    void baphysics_set_vertical_velocity(PlayerState *arg0, f32 arg1);
    baphysics_set_vertical_velocity(D_80135490.players[arg0], arg1);
}

void func_800F8418(BtIntPtr arg0 BT_PASS2(, f32 *position))
{
    func_800F4648(D_80135490.players[arg0] BT_PASS2(, position));
}

void func_800F8444(BtIntPtr arg0, f32 *arg1) {
    void baroll_setIdeal(PlayerState *, f32);
    void func_8009BF5C(PlayerState *, f32);
    PlayerState *sp1C;

    sp1C = D_80135490.players[arg0];
    func_8009BF5C(sp1C, (((Vec3f *)arg1)->pos.x));
    yaw_setIdeal(sp1C, (((Vec3f *)arg1)->pos.y));
    baroll_setIdeal(sp1C, (((Vec3f *)arg1)->pos.z));
}

void func_800F849C(s32 arg0, f32 arg1) {
    void func_8009BD18(PlayerState *arg0, f32 arg1);
    func_8009BD18(D_80135490.players[arg0], arg1);
}

void func_800F84D0(s32 arg0 BT_PASS2(, s32 bt_a1))
{
    func_8009659C(D_80135490.players[arg0] BT_PASS2(, bt_a1));
}

BT_IDO_ONLY(extern u8 D_801354B0[];)
s32 func_800D5240(void);
void func_800A1658(s32);
void func_800F9198(void);
void func_800F468C(PlayerState *);

void func_800F84FC(void) {
    f32 a;
    f32 b;
    f32 c;
    f32 pos[3];
    s32 i;
    s32 j;
    s32 k;
    BtIntPtr mode;
    s32 sub;

    for (i = 0; i < 8; i++) {
        if (D_80135490.players[i] != NULL && func_800F5924(i)) {
            func_800F5A00(i, (f32 *)&pos);
            func_800F5950(i, &a, &b, &c);
            for (j = 0; j < 8; j++) {
                if (D_80135490.players[j] != NULL && i != j && func_800F58F8(j)) {
                    func_800F4EC8(j, (BtIntPtr)&pos, a, b, c);
                }
            }
        }
    }
    D_80135490.updating = 1;
    for (k = 0; k < 8; k++) {
        if (D_80135490.players[k] != NULL) {
            func_800F468C(D_80135490.players[k]);
        }
    }
    D_80135490.updating = 0;
    func_800F9198();
    mode = func_800F54E4();
    sub = func_800F5410(mode);
    if (D_80135490.previous_player != -1 && (mode != D_80135490.previous_player || sub != D_80135490.previous_mode) && !func_800D5240()) {
        func_800A1658(sub);
    }
    for (k = 0; k < 8; k++) {
        if (D_80135490.active[k]) {
            func_800F759C(k);
        }
    }
    D_80135490.previous_player = mode;
    D_80135490.previous_mode = sub;
}

void func_800F86C4(s32 arg0, s32 arg1) {
    BT_DATA_FIELD(D_80135490.previous_player, (*(s16 *)((s8 *)(D_80135490.players) + (0x50)))) = arg0;
    BT_DATA_FIELD(D_80135490.previous_mode, (*(s16 *)((s8 *)(D_80135490.players) + (0x52)))) = arg1;
}

void func_800F86D8(void)
{
    PlayerState *func_800F46D8(PlayerState *);
    BT_IDO_ONLY(extern u8 D_801354B0[];)
    PlayerState **var_s0;
    PlayerState *temp_a0;
 var_s0 = D_80135490.players; do { temp_a0 = *var_s0;
    if (temp_a0 != NULL)
    {
      *var_s0 = func_800F46D8(temp_a0);
    }
    var_s0++;
  }
  while (var_s0 != BT_DATA_FIELD(D_80135490.players + 8, (PlayerState **) D_801354B0));
}

/* extern */

s32 func_800F8730(s32 arg0, s32 arg1) {
    void _surestart_entrypoint_0(s32);
    s32 func_8009E7C8(PlayerState *, s32);
    void func_800A3538(void *, s32);
    PlayerState *sp1C;
    s32 sp18;

    sp1C = D_80135490.players[arg0];
    func_800A3538(sp1C, arg1);
    sp18 = func_8009E7C8(sp1C, 0xA) == 2;
    if ((sp18 != 0) && (func_800F5410(arg0) != arg1)) {
        _surestart_entrypoint_0(arg1);
    }
    return sp18;
}

s32 func_800F87A4(s32 arg0) {
    s32 func_8009E7C8(PlayerState *, s32);
    PlayerState *sp1C;

    sp1C = D_80135490.players[arg0];
    if ((func_800F56D8(arg0) != NULL) && (func_8009E674(sp1C, 0x400) != 0)) {
        return func_8009E7C8(sp1C, 0x16) == 2;
    }
    return 0;
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F8804(s32 arg0 BT_PASS2(, s32 bt_a1))
{
    BT_NATIVE_ONLY(return) func_8009CD70(D_80135490.players[arg0] BT_PASS2(, bt_a1));
}

void func_800F8830(PlayerState *arg0)
{
    s32 func_8009E7C8(PlayerState *, s32);
    func_8009E7C8(arg0,0x99);
}

void func_800F8850(void) {
    func_800F47C0(func_800F8830);
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F8874(s32 arg0)
{
    BT_NATIVE_ONLY(return) func_8009224C(D_80135490.players[arg0]);
}

void *func_800F88A0(s32 arg0) {
    BT_IDO_ONLY(BtUIntPtr vector_begin(s32);)
    BT_IDO_ONLY(BtUIntPtr vector_end(s32);)
    BT_IDO_ONLY(extern s32 D_801354F0;)
    BT_NATIVE_ONLY(u8 *) BT_IDO_ONLY(BtUIntPtr) sp1C;
    BT_NATIVE_ONLY(u8 *) BT_IDO_ONLY(BtUIntPtr) temp_v0;
    BT_NATIVE_ONLY(u8 *) BT_IDO_ONLY(BtUIntPtr) var_v1;
    BT_NATIVE_ONLY(void *) BT_IDO_ONLY(u32) result;

    sp1C = vector_begin(D_801354F0);
    temp_v0 = vector_end(D_801354F0);
    result = 0;
    for (var_v1 = sp1C; var_v1 < temp_v0; var_v1 += 0x3C) {
        if (arg0 == *(u8 *)var_v1) {
            return (void *)var_v1;
        }
    }
    return (void *)result;
}

s32 func_800F8914(u8 *arg0, BtIntPtr arg1) {
    void _plcamera_entrypoint_14(s32 *arg0, BtIntPtr arg1, BtIntPtr arg2);
    s32 func_800EA090(void);
    s32 func_800F9214();
    s32 result;
    func_800F5A00(arg1, (f32 *)(arg0 + 0x24));
    func_800F5B38(arg1, (f32 *)(arg0 + 0x30));
    _plcamera_entrypoint_14(arg1, (BtIntPtr)(arg0 + 4), (BtIntPtr)(arg0 + 0x10));
    *(s8 *)(arg0 + 2) = func_800F9214(arg1);
    *(s8 *)arg0 = func_800F5410(arg1);
    *(s8 *)(arg0 + 1) = func_800F65D0(arg1);
    *(s16 *)(arg0 + 0x22) = func_800EA05C();
    *(s8 *)(arg0 + 0x21) = func_800EA090();
    *(s8 *)(arg0 + 0x20) = 2;
    *(s8 *)(arg0 + 0x1D) = func_800F58F8(arg1);
    result = func_800F5924(arg1);
    *(s8 *)(arg0 + 0x1C) = result;
    return result;
}

s32 func_800F89BC(void) {
    if (BT_DATA_FIELD(D_801354F8.mode, D_801354F8) == 2) {
        return 0xB;
    }
    return 1;
}

s32 func_800F89E4(s32 arg0, f32 *arg1) {
    void func_800EE7F8(f32 *, f32 *);
    BT_IDO_ONLY(extern s32 D_80135500;)
    BT_IDO_ONLY(extern s32 D_80135510;)
    BT_IDO_ONLY(extern s32 D_8013551C;)
    s32 sp1C;

    if (arg0 == 0xA) {
        func_800EE7F8(arg1, BT_DATA_FIELD(D_801354F8.position10, (f32 *)&D_80135500));
        sp1C = BT_DATA_FIELD(D_801354F8.map, D_8013551C);
    } else if (arg0 == 0xB) {
        func_800EE7F8(arg1, BT_DATA_FIELD(D_801354F8.position11, (f32 *)&D_80135510));
        sp1C = BT_DATA_FIELD(D_801354F8.map, D_8013551C);
    }
    return sp1C;
}

f32 func_800F8A50(void)
{
	return BT_DATA_FIELD(D_801354F8.yaw, D_8013550C);
}

/* extern */

s16 func_800F8A5C(BT_PARAM_OR_VOID(s32 bt_a0)) {
    void *func_800F88A0();
#ifdef BT_NATIVE
    return (*(s16 *)((s8 *)(func_800F88A0(bt_a0)) + (0x22)));
#else
    return (*(s16 *)((s8 *)(func_800F88A0()) + (0x22)));
#endif
}

/* extern */

u8 func_800F8A80(BT_PARAM_OR_VOID(s32 bt_a0)) {
    void *func_800F88A0();
#ifdef BT_NATIVE
    return (*(u8 *)((s8 *)(func_800F88A0(bt_a0)) + (0x21)));
#else
    return (*(u8 *)((s8 *)(func_800F88A0()) + (0x21)));
#endif
}    typedef struct { u8 unk0; u8 unk1; } Obj1ECE0B0_func_800F8AA4_var_v1; /* offsets.py genstruct: fields from raw offsets on var_v1; rename once understood */

s32 func_800F8AA4(void) {
    BT_IDO_ONLY(BtUIntPtr vector_begin(s32);)
    BT_IDO_ONLY(BtUIntPtr vector_end(s32);)
    BT_IDO_ONLY(extern s32 D_801354F0;)
    BT_NATIVE_ONLY(u8 *) BT_IDO_ONLY(BtUIntPtr) sp1C;
    BT_NATIVE_ONLY(u8 *) BT_IDO_ONLY(BtUIntPtr) temp_v0;
    BT_NATIVE_ONLY(u8 *) BT_IDO_ONLY(BtUIntPtr) var_v1;
    s32 result;

    sp1C = vector_begin(D_801354F0);
    temp_v0 = vector_end(D_801354F0);
    result = 0;
    for (var_v1 = sp1C; var_v1 < temp_v0; var_v1 += 0x3C) {
        if ((((Obj1ECE0B0_func_800F8AA4_var_v1 *)var_v1)->unk1) != 0) {
            return (((Obj1ECE0B0_func_800F8AA4_var_v1 *)var_v1)->unk0);
        }
    }
    return result;
}

void func_800F8B0C(s32 arg0, f32 *arg1) { void *func_800F88A0(); void func_800EE7F8(f32 *, f32 *); func_800EE7F8(arg1, (f32 *)((u8 *)func_800F88A0(arg0) + 0x24)); }

void func_800F8B38(s32 arg0, f32 *arg1) { void *func_800F88A0(); void func_800EE7F8(f32 *, f32 *); func_800EE7F8(arg1, (f32 *)((u8 *)func_800F88A0(arg0) + 0x30)); }

s32 func_800F8B64(void) {
	return (s32)BT_DATA_FIELD(D_801354F8.overridePosition, D_801354F9);
}

u8 func_800F8B70(void) {
	return BT_DATA_FIELD(D_801354F8.flag4, D_801354FC);
}

u8 func_800F8B7C(void)
{
	return BT_DATA_FIELD(D_801354F8.flag5, D_801354FD);
}

u8 func_800F8B88(void) {
	return BT_DATA_FIELD(D_801354F8.mode, D_801354F8);
}

void func_800F8B94(void) {
    BT_IDO_ONLY(extern s32 D_801354F0;)
    BT_IDO_ONLY(extern s32 D_80135500;)
    BT_IDO_ONLY(extern s32 D_80135510;)
    BT_IDO_ONLY(BtUIntPtr vector_begin(s32);)
    BT_IDO_ONLY(BtUIntPtr vector_end(s32);)
    s32 func_800F8D80(s32, u8 *);
    u8 *entry;
    u8 *begin;
    u8 *end;
    s32 player;

    begin = (u8 *)vector_begin(D_801354F0);
    end = (u8 *)vector_end(D_801354F0);
    for (entry = begin; entry < end; entry += 0x3C) {
        if (func_800EA05C() == *(s16 *)(entry + 0x22)) {
            player = func_800F6204(0);
            func_800F7E64(player, entry[0]);
            func_800F8268(player, entry[0x1D], entry[0x1C]);
            if (BT_DATA_FIELD(D_801354F8.overridePosition, (&D_801354F8)[1]) && (entry[0] == 10 || entry[0] == 11)) {
                func_800F8294(player, entry[0] == 10 ? BT_DATA_FIELD(D_801354F8.position10, (f32 *)&D_80135500) : BT_DATA_FIELD(D_801354F8.position11, (f32 *)&D_80135510));
            } else {
                func_800F8294(player, (f32 *)(entry + 0x24));
            }
            func_800F832C(player, (f32 *)(entry + 0x30));
            if (entry[1]) {
                func_800F80D8(player);
            }
            if (BT_DATA_FIELD(D_801354F8.mode, D_801354F8) != 1 && (entry[0] == 10 || entry[0] == 11)) {
                func_800F8358(player, 1);
            }
            switch (entry[2]) {
                case 1:
                    break;
                case 2:
                    func_800F608C(player, 2);
                    break;
            }
            if (entry[1]) {
                func_800F8D80(player, entry);
            }
        }
    }
}

/* extern */

void func_800F8D50(s32 arg0, s32 arg1) {
    void *func_800F88A0();
    s32 func_800F8D80(s32, u8 *);
    func_800F8D80(arg0, func_800F88A0(arg1));
}

s32 func_800F8D80(s32 arg0, u8 *arg1) {
    s32 _plcamera_entrypoint_12(s32, u8 *, u8 *, u8 *);
    return _plcamera_entrypoint_12(arg0, arg1 + 4, arg1 + 0x10, arg1);
}

/* extern */

s32 func_800F8DA8(BT_PARAM_OR_VOID(s32 bt_a0)) {
    void *func_800F88A0();
    s32 var_v1;

#ifdef BT_NATIVE
    if (func_800F88A0(bt_a0) != 0) {
#else
    if (func_800F88A0() != 0) {
#endif
        var_v1 = 1;
    } else {
        var_v1 = 0;
    }
    return var_v1;
}

void func_800F8DD8(void) {
    void func_800F9A24(void);
    BT_IDO_ONLY(void vector_free(void *vec);)
    BT_IDO_ONLY(extern s32 D_801354F0;)
    func_800F9A24();
    vector_free(D_801354F0);
    D_801354F0 = 0;
}
BT_IDO_ONLY(typedef struct { u8 unk0; s8 unk1; u8 pad2[0x2]; s8 unk4; s8 unk5; u8 pad6[0xE]; f32 unk14; u8 pad18[0xC]; s32 unk24; } Obj1ECE0B0_D_801354F8;)

void func_800F8E08(void) {
    void func_800EFD24(f32 vec[3]);
    void func_800F9A44(void);
    BT_IDO_ONLY(void * vector_new(u32 element_size, u32 count);)
    BT_IDO_ONLY(extern s32 D_801354F0;)
    BT_IDO_ONLY(extern s32 D_80135500;)
    BT_IDO_ONLY(extern s32 D_80135510;)
    BT_IDO_ONLY(extern s32 D_8013551C;)
    D_801354F0 = vector_new(0x3C, 2);
    (BT_DATA_FIELD(D_801354F8.overridePosition, ((Obj1ECE0B0_D_801354F8 *)&D_801354F8)->unk1)) = 0;
    (BT_DATA_FIELD(D_801354F8.flag4, ((Obj1ECE0B0_D_801354F8 *)&D_801354F8)->unk4)) = 0;
    (BT_DATA_FIELD(D_801354F8.flag5, ((Obj1ECE0B0_D_801354F8 *)&D_801354F8)->unk5)) = 0;
    (BT_DATA_FIELD(D_801354F8.mode, ((Obj1ECE0B0_D_801354F8 *)&D_801354F8)->unk0)) = 0;
    func_800F911C(1);
    func_800EFD24(BT_DATA_FIELD(D_801354F8.position10, &D_80135500));
    func_800EFD24(BT_DATA_FIELD(D_801354F8.position11, &D_80135510));
    BT_DATA_FIELD(D_801354F8.map, D_8013551C) = 0;
    func_800F9A44();
}

/* extern */

s32 func_800F8E78(s32 arg0) {
    BT_IDO_ONLY(extern s32 D_801354F0;)
    void *func_800F88A0();
    BT_IDO_ONLY(void vector_erase(void *vec, u32 index);)
    BT_IDO_ONLY(s32 vector_index_of(void *vec, void *element);)
    void *var_v0;

    var_v0 = func_800F88A0(arg0);
    if (var_v0 != NULL) {
        vector_erase(D_801354F0, vector_index_of(D_801354F0, var_v0));
    } BT_NATIVE_ONLY(return 0;)
}

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) func_800F8EBC(s32 a0)
{
    BT_NATIVE_ONLY(return) func_800F8E78(func_800F5410(a0));
}

/* extern */

s32 func_800F8EE4(s32 arg0) {
    BT_IDO_ONLY(extern s32 D_801354F0;)
    void *func_800F88A0();
    s32 func_800F8914(u8 *, BtIntPtr);
    BT_IDO_ONLY(u8 *vector_push_back(s32 *);)
    u8 *temp_v0;

    temp_v0 = func_800F88A0(func_800F5410(arg0));
    if (temp_v0 != NULL) {
        return func_800F8914(temp_v0, arg0);
    }
    return func_800F8914(vector_push_back(&D_801354F0), arg0);
}

void func_800F8F3C(void) {
    void func_800EE7F8(f32 *, f32 *);
    void func_800EFA4C(f32 *, f32, f32, f32);
    BT_IDO_ONLY(BtUIntPtr vector_begin(s32);)
    BT_IDO_ONLY(BtUIntPtr vector_end(s32);)
    BT_IDO_ONLY(extern s32 D_801354F0;)
    BT_IDO_ONLY(extern s32 D_80135500;)
    BT_IDO_ONLY(extern s32 D_80135510;)
    BT_NATIVE_ONLY(u8 *) BT_IDO_ONLY(BtUIntPtr) begin;
    BT_NATIVE_ONLY(u8 *) BT_IDO_ONLY(BtUIntPtr) end;
    BT_NATIVE_ONLY(u8 *) BT_IDO_ONLY(BtUIntPtr) entry;

    if (BT_DATA_FIELD(D_801354F8.mode, D_801354F8) == 2 && D_801354F0 != 0) {
        begin = vector_begin(D_801354F0);
        end = vector_end(D_801354F0);
        for (entry = begin; entry < end; entry += 0x3C) {
            if (*(u8 *)entry == 0xA) {
                func_800EE7F8((f32 *)(entry + 0x24), BT_DATA_FIELD(D_801354F8.position10, (f32 *)&D_80135500));
                *(s16 *)(entry + 0x22) = BT_DATA_FIELD(D_801354F8.map, ((Obj1ECE0B0_D_801354F8 *)&D_801354F8)->unk24);
                func_800EFA4C((f32 *)(entry + 0x30), 0.0f, BT_DATA_FIELD(D_801354F8.yaw, ((Obj1ECE0B0_D_801354F8 *)&D_801354F8)->unk14), 0.0f);
            } else if (*(u8 *)entry == 0xB) {
                func_800EE7F8((f32 *)(entry + 0x24), BT_DATA_FIELD(D_801354F8.position11, (f32 *)&D_80135510));
                *(s16 *)(entry + 0x22) = BT_DATA_FIELD(D_801354F8.map, ((Obj1ECE0B0_D_801354F8 *)&D_801354F8)->unk24);
                func_800EFA4C((f32 *)(entry + 0x30), 0.0f, BT_DATA_FIELD(D_801354F8.yaw, ((Obj1ECE0B0_D_801354F8 *)&D_801354F8)->unk14), 0.0f);
            }
        }
    }
}

void func_800F9070(s32 arg0, s32 arg1) {
    void *func_800F88A0();
    (*(s8 *)((s8 *)(func_800F88A0(arg0)) + (1))) = (s8) arg1;
}

void func_800F9098(s32 arg0, f32 *arg1) {
    void func_800EE7F8(f32 *, f32 *);
    BT_IDO_ONLY(extern s32 D_80135500;)
    BT_IDO_ONLY(extern s32 D_80135510;)
    BT_IDO_ONLY(extern s32 D_8013551C;)
    if (arg0 == 0xA) {
        func_800EE7F8(BT_DATA_FIELD(D_801354F8.position10, (f32 *)&D_80135500), arg1);
    } else if (arg0 == 0xB) {
        func_800EE7F8(BT_DATA_FIELD(D_801354F8.position11, (f32 *)&D_80135510), arg1);
    }
    BT_DATA_FIELD(D_801354F8.map, D_8013551C) = func_800EA05C();
}
BT_IDO_ONLY(typedef struct { f32 unk0; } Obj1ECE0B0_D_8013550C;)

void func_800F90EC(f32 arg0) {
    BT_IDO_ONLY(extern f32 D_8013550C;)
    BT_DATA_FIELD(D_801354F8.yaw, ((Obj1ECE0B0_D_8013550C *)&D_8013550C)->unk0) = arg0;
}

void func_800F90F8(s32 arg0) {
	BT_DATA_FIELD(D_801354F8.overridePosition, D_801354F9) = arg0;
}

void func_800F9104(s32 arg0) {
    BT_IDO_ONLY(extern u8 D_801354FC;)
    BT_DATA_FIELD(D_801354F8.flag4, D_801354FC) = arg0;
}

void func_800F9110(s32 arg0) {
    BT_IDO_ONLY(extern u8 D_801354FD;)
    BT_DATA_FIELD(D_801354F8.flag5, D_801354FD) = arg0;
}

void func_800F911C(s32 arg0) {
    void func_800CF840(s32 arg0);
    if (BT_DATA_FIELD(D_801354F8.mode, D_801354F8) == 3) {
        func_800CF840(0);
    }
    if ((BT_DATA_FIELD(D_801354F8.mode, D_801354F8) = arg0) == 3) {
        func_800CF840(1);
    }
}

void func_800F9178(void)
{
    BT_IDO_ONLY(extern u8 D_801354FA;)

    BT_DATA_FIELD(D_801354F8.flagsCleared, D_801354FA) = 0;
}

s32 func_800F9184(void) {
    BT_IDO_ONLY(extern u8 D_801354FA;)
    return BT_DATA_FIELD(D_801354F8.flagsCleared, D_801354FA) == 0;
}

void func_800F9198(void) {
    void func_800F9C6C(void);
    BT_IDO_ONLY(extern u8 D_801354FA;)
    if (BT_DATA_FIELD(D_801354F8.flagsCleared, D_801354FA) == 0) {
        func_800F90F8(0);
        func_800F9104(0);
        func_800F9110(0);
        BT_DATA_FIELD(D_801354F8.flagsCleared, D_801354FA) = 1;
    }
    func_800F9C6C();
}

void func_800F91EC(void) {
    BT_IDO_ONLY(void * vector_defrag(void *vec);)
    BT_IDO_ONLY(extern s32 D_801354F0;)
    D_801354F0 = vector_defrag(D_801354F0);
}

/* extern */

#ifdef BT_NATIVE
s32 func_800F9214(s32 bt_a0) {
#else
s32 func_800F9214(void) {
#endif
    BT_IDO_ONLY(int func_800F6720();) BT_NATIVE_ONLY(int func_800F6720(BtIntPtr);)
#ifdef BT_NATIVE
    if (func_800F6720(bt_a0) != 0) {
#else
    if (func_800F6720() != 0) {
#endif
        return 2;
    }
    return 1;
}

void func_800F9240(f32 *arg0, s32 arg1) {
    void func_800EFA4C(f32 *, f32, f32, f32);
    f32 sp1C[3];

    func_800F5A00(arg1, sp1C);
    sp1C[0] += 200.0f;
    func_800EFA4C(arg0, sp1C[0], sp1C[1], sp1C[2] + 200.0f);
}

s32 func_800F929C(void) {
    if (func_800F8B88() == 2) {
        return 0xB;
    }
    return 1;
}

void func_800F92CC(u32 *arg0, s32 *arg1, s32 *arg2, s32 *arg3) {
    s32 _plsu_entrypoint_1(s32);
    BtUIntPtr temp_v0;
    s32 temp_v0_2;

    temp_v0 = func_800F54E4();
    *arg0 = temp_v0;
    temp_v0_2 = func_800F5410((s32) temp_v0);
    *arg1 = temp_v0_2;
    switch (temp_v0_2) {
        case 10:
            *arg3 = 11;
            break;
        case 11:
            *arg3 = 10;
            break;
    }
    *arg2 = _plsu_entrypoint_1(*arg3);
}

void func_800F9354(u32 *arg0, s32 *arg1, s32 *arg2) {
    BtUIntPtr temp_v0;
    s32 temp_v0_2;

    temp_v0 = func_800F54E4();
    *arg0 = temp_v0;
    temp_v0_2 = func_800F5410((s32) temp_v0);
    *arg1 = temp_v0_2;
    switch (temp_v0_2) {
        case 10:
            *arg2 = 11;
            break;
        case 11:
            *arg2 = 10;
            break;
    }
}

void func_800F93C4(u32 *arg0, s32 *arg1) {
    BtUIntPtr temp_v0;

    temp_v0 = func_800F54E4();
    *arg0 = temp_v0;
    *arg1 = func_800F5410((s32) temp_v0);
}

/* extern */
