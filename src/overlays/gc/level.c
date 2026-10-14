#include "gc/level.h"

extern u8 D_8012762C;
extern s8 D_8012762D;
extern u8 D_808003C0_gclevel[];

void func_8080016C_gclevel(s32, s32, s32, s32);
s32 func_80800270_gclevel(s32, s32, s32);

void gclevel_entrypoint_0(s32 arg0, s32 arg1)
{
    s32 sp1C;
    s32 sp18;

    sp1C = D_8012762C;
    sp18 = gclevel_entrypoint_2(arg0);
    if (func_800A824C() != 0)
    {
        func_800A8240();
        return;
    }
    if (func_80800270_gclevel(arg0, arg1, sp18) != 0)
    {
        D_8012762D = sp18;
    }
    _cosectionstor_entrypoint_0();
    func_800A13A0();
    func_800CE524();
    func_800CEF7C();
    func_800DA104();
    func_8009E9A8();
    func_8080016C_gclevel(sp1C, sp18, arg0, arg1);
    func_800C75E8();
}

void gclevel_entrypoint_1(void)
{
    if (func_800A824C() == 0)
    {
        func_8009E9A0();
        func_800CF2B0();
        func_800CE7DC();
        _cosectionstor_entrypoint_1();
        func_800C75C0();
    }
}

s32 gclevel_entrypoint_2(s32 arg0)
{
    return D_8012762C = _gcsectionDll_entrypoint_4(arg0);
}

/* extern */

u32 gclevel_entrypoint_3(void) {
    void *func_80800314_gclevel();
    void *temp_v0;

    temp_v0 = func_80800314_gclevel();
    if (temp_v0 == NULL) {
        return 1U;
    }
    return func_800DA298((enum flag_e) (*(u16 *)((s8 *)(temp_v0) + (2))));
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/gc/level/func_8080016C_gclevel.s")

s32 gclevel_entrypoint_4(s32 arg0)
{
    if (D_8012762C >= 0xD && D_8012762C < 0x1C)
    {
        return (D_808003C0_gclevel[D_8012762C - 0xD]) & arg0;
    }
    return 0;
}

/* extern */

s32 func_80800270_gclevel(s32 arg0, s32 arg1, s32 arg2) {
    void *func_80800314_gclevel(s32);
    s32 temp_v1;
    void *temp_v0;

    temp_v0 = func_80800314_gclevel(arg2);
    if (temp_v0 == NULL) {
        return 1;
    } else {
        temp_v1 = (*(s16 *)((s8 *)(temp_v0) + (4)));
        if (temp_v1 == -1) {
            func_800DA544((enum flag_e) (*(u16 *)((s8 *)(temp_v0) + (2))));
            goto done;
        } else {
        if ((arg0 == temp_v1) && ((arg1 == (*(s8 *)((s8 *)(temp_v0) + (6)))) || (arg1 == (*(s8 *)((s8 *)(temp_v0) + (7)))))) {
            func_800DA544((enum flag_e) (*(u16 *)((s8 *)(temp_v0) + (2))));
            goto done;
        } else {
            return func_800DA298((enum flag_e) (*(u16 *)((s8 *)(temp_v0) + (2))));
        }
        }
    }
done:
    return 1;
}

void *func_80800314_gclevel(s32 arg0) {
    struct LevelEntry {
        s16 id;
        s16 flag;
        s32 unk4;
    };
    extern struct LevelEntry D_808003D0_gclevel[];
    struct LevelEntry *entry;
    s32 i;

    for (i = 0; i < 10; i++) {
        entry = &D_808003D0_gclevel[i];
        if (arg0 == entry->id) {
            return entry;
        }
    }
    return NULL;
}
