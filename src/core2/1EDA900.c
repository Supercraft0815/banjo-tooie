#include "core2/1EDA900.h"
extern void *D_80135A80;

void func_80101010(s32 arg0) {
    s32 func_800EE7F8(s32 *, s32);
    extern s32 D_80135A70;
    func_800EE7F8(&D_80135A70, arg0);
}

void func_80101038(f32 *arg0) {
    s32 func_800EE7F8();
    extern s32 D_80135A70;
    func_800EE7F8(arg0, &D_80135A70);
}

void func_8010105C(f32 arg0) {
    extern f32 D_80135A7C;
    *(f32 *)((u8 *)&D_80135A7C + 0) = arg0;
}

f32 func_80101068(void) {
    extern f32 D_80135A7C;
    return *(f32 *)((u8 *)&D_80135A7C + 0);
}

void func_80101074(void *arg0)
{
    D_80135A80 = arg0;
}

void *func_80101080()
{
    return D_80135A80;
}

/* extern */

s32 func_8010108C(Actor *arg0, s32 arg1, s32 arg2) {
    typedef struct {
        u32 pad0[16];
        s32 (*unk40)(Actor *, s32, s32);
    } ActorCallbacks;
    typedef struct {
        u32 pad0[29];
        u32 pad74_31 : 3;
        u32 unk74_28 : 1;
        u32 pad74_0 : 28;
    } ActorFlags;
    void func_800819B4(void *);
    s32 func_80081D34(s32);
    s32 func_80081D80(s32);
    void *func_80100368(void *);
    s32 unused;
    s32 var_a1;
    s32 var_v1;
    s32 temp_v0;

    if (((ActorFlags *)arg0)->unk74_28) {
        temp_v0 = func_80081D34((s32)arg0->pointerToSyscallEntry);
        if (temp_v0 != 0) {
            var_v1 = func_80081D80(temp_v0);
        } else {
            var_v1 = 0;
        }
        var_a1 = ((ActorCallbacks *)func_80100368(arg0))->unk40(arg0, arg1, arg2);
        if ((temp_v0 != 0) && (var_v1 == 0) && (var_a1 <= 0)) {
            func_800819B4(arg0->pointerToSyscallEntry);
        }
        return var_a1;
    }
    return -1;
}

s32 func_8010114C(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_8010108C();
    return func_8010108C(func_80106790(arg0), arg1, arg2);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDA900/func_80101180.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDA900/func_80101238.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDA900/func_801012D0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1EDA900/func_801013A8.s")
