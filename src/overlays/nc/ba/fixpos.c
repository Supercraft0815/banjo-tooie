#include "common.h"

s32 ncbafixpos_entrypoint_0() 
{
    return 0x1C;
}

void ncbafixpos_entrypoint_1(u8 *arg0) {
    s32 func_801124D0(s32, s32);
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x20)))) + (0x1A))) = 1;
    func_801124D0((s32) arg0, 1);
}

void ncbafixpos_entrypoint_2(s32 arg0) 
{
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/nc/ba/fixpos/func_8080003C_ncbafixpos.s")

/* extern */

struct player_state_s;
void ncbafixpos_entrypoint_3(struct player_state_s *arg0) {
    void func_800EE7F8(f32 *, f32 *);
    void func_80110790(s32, f32 *);
    void func_801107F0(void *, f32 *);
    void func_80110A68(s32, s32, s32);
    void func_80111AE0(struct player_state_s *, f32 *);
    void func_80112524(struct player_state_s *, f32 *);
    void func_8011329C(struct player_state_s *);
    f32 func_8080003C_ncbafixpos(struct player_state_s *);
    f32 sp4C[3];
    f32 sp40[3];
    f32 sp34[3];
    f32 sp28[3];
    u8 *temp_v0;

    if (*(u8 *)(*(u8 **)((u8 *)arg0 + 0x20) + 0x1A) == 0) {
        func_801107F0(arg0, sp40);
        func_800EE7F8(sp28, (f32 *)(*(u8 **)((u8 *)arg0 + 0x20) + 0xC));
        sp40[0] = *(f32 *)(*(u8 **)((u8 *)arg0 + 0x20));
        sp40[2] = *(f32 *)(*(u8 **)((u8 *)arg0 + 0x20) + 8);
        temp_v0 = *(u8 **)((u8 *)arg0 + 0x20);
        if (*(u8 *)(temp_v0 + 0x18) != 0) {
            sp40[1] = *(f32 *)(temp_v0 + 4);
        } else {
            sp40[1] = func_8080003C_ncbafixpos(arg0);
        }
        func_80111AE0(arg0, sp40);
        if (*(u8 *)(*(u8 **)((u8 *)arg0 + 0x20) + 0x19) != 0) {
            func_8011329C(arg0);
        }
        func_80112524(arg0, sp4C);
        func_80110A68((s32)arg0, (s32)sp34, (s32)sp4C);
        func_80110790((s32)arg0, sp34);
    }
}

/* extern */

void ncbafixpos_entrypoint_4(u8 *arg0, s32 arg1) {
    s32 _cadbfunc_entrypoint_0(u8 *);
    s32 _cadbfunc_entrypoint_29(s32, s32 *);
    s32 _cadbfunc_entrypoint_4(u8 *);
    s32 _cadbfunc_entrypoint_6(s32 *, s32 *);
    s32 _cadbfunc_entrypoint_8(s32 *, s32 *);
    s32 func_800A5800(s32);
    s32 func_80111B8C(u8 *, s32, s32);
    s32 func_80112570(u8 *, u8 *, s32);
    s32 sp2C;
    s32 sp28;
    s32 sp24;

    func_800A5800(arg1);
    _cadbfunc_entrypoint_29(2, &sp24);
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x20)))) + (0x18))) = (s8) sp24;
    _cadbfunc_entrypoint_29(1, &sp24);
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x20)))) + (0x19))) = (s8) sp24;
    _cadbfunc_entrypoint_4((*(u8 **)((s8 *)(arg0) + (0x20))) + 0xC);
    _cadbfunc_entrypoint_0((*(u8 **)((s8 *)(arg0) + (0x20))));
    _cadbfunc_entrypoint_6(&sp2C, &sp28);
    func_80111B8C(arg0, sp2C, sp28);
    _cadbfunc_entrypoint_8(&sp2C, &sp28);
    (*(s8 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0x20)))) + (0x1A))) = 0;
    func_80112570(arg0, (*(u8 **)((s8 *)(arg0) + (0x20))) + 0xC, 0x42C80000);
}
