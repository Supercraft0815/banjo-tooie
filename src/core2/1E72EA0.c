#include "core2/1E72EA0.h"

s32 func_800995B0(void) {
    return sizeof(BaUnknownC0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E72EA0/func_800995B8.s")

/* extern */

s32 func_800996E0(s32 arg0) {
    s32 func_800A1718();
    s32 func_800A17A8(s32, s32);
    s32 temp_v0;

    temp_v0 = func_800A1718();
    if (temp_v0 < 2) {
        func_800A17A8(arg0, -temp_v0);
        return 0;
    }
    func_800A17A8(arg0, 1 - temp_v0);
    return 1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E72EA0/func_80099730.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E72EA0/func_800997BC.s")

/* extern */

void func_80099840(PlayerState *arg0, s32 arg1) {
    s32 _badata_entrypoint_20(PlayerState *);
    s32 _badata_entrypoint_26(PlayerState *);
    s32 func_800A1718(PlayerState *);
    s32 temp_v0;
    s32 var_a0;

    temp_v0 = func_800A1718(arg0);
    var_a0 = arg1 == 0;
    if (var_a0 != 0) {
        var_a0 = temp_v0 != 0;
    }
    if (var_a0 != 0) {
        _badata_entrypoint_26(arg0);
        return;
    }
    _badata_entrypoint_20(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E72EA0/func_8009989C.s")

void func_80099970(PlayerState *arg0) {
    void func_8009ACF4(void *, f32);
    void func_8009AD04(void *, f32);
    void func_8009AD14(void *, s32);
    void func_8009AD20(void *, s32);
    void func_8009AD44(PlayerState *, f32 *);
    s32 func_8009E7C8(PlayerState *, s32);
    s32 temp_a1;
    s32 offset;
    u8 *entry;

    entry = (u8 *)arg0->unkC0;
    offset = 0;
    do {
        if (*(s32 *)(entry + 0x4C) != 0) {
            func_8009ACF4(arg0, *(f32 *)(entry + 0x28));
            func_8009AD04(arg0, *(f32 *)((u8 *)arg0->unkC0 + offset + 0x2C));
            func_8009AD14(arg0, *(s32 *)((u8 *)arg0->unkC0 + offset + 0x3C));
            func_8009AD20(arg0, *(s32 *)((u8 *)arg0->unkC0 + offset + 0x40));
            func_8009AD44(arg0, (f32 *)((u8 *)arg0->unkC0 + offset + 0x30));
            entry = (u8 *)arg0->unkC0 + offset;
            temp_a1 = *(s32 *)(entry + 0x4C);
            *(s32 *)(entry + 0x4C) = 0;
            func_8009E7C8(arg0, temp_a1);
            return;
        }
        offset += 0x28;
        entry += 0x28;
    } while (offset != 0xC8);
}

f32 func_80099A34(PlayerState *self) {
    return self->unkC0->unk0;
}

f32 func_80099A40(PlayerState *self) {
    return self->unkC0->unk4;
}

s32 func_80099A4C(PlayerState *self) {
    return self->unkC0->unk14;
}

s32 func_80099A58(PlayerState *self) {
    return self->unkC0->unk18;
}

s32 func_80099A64(PlayerState *self) {
    return self->unkC0->unk1C;
}

s32 func_80099A70(PlayerState *self) {
    return self->unkC0->unk20;
}


void func_80099A7C(PlayerState *arg0, f32 *arg1) { s32 func_800EE7F8(); func_800EE7F8(arg1, arg0->unkC0->pad8); return; }

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E72EA0/func_80099AA8.s")

/* extern */

void func_80099B54(PlayerState *arg0) {
    s32 _badata_entrypoint_33(PlayerState *);
    s32 func_8009EAE8(u32);
    void *func_80106790(s32);
    func_8009EAE8((u32) ((*(s32 *)((s8 *)(func_80106790(func_80099A4C(arg0))) + (0x6C))) << 0xB) >> 0x14);
    _badata_entrypoint_33(arg0);
}

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E72EA0/func_80099B94.s")

#pragma GLOBAL_ASM("asm/nonmatchings/core2/1E72EA0/func_8009AB78.s")

/* extern */

void func_8009AC6C(u8 *arg0) {
    s32 func_800EFD24(u8 *, u8 *);
    s32 temp_v0;

    (*(s32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0xC0)))) + (0x18))) = 0;
    (*(s32 *)((s8 *)((*(u8 **)((s8 *)(arg0) + (0xC0)))) + (0x14))) = 0;
    func_800EFD24((*(u8 **)((s8 *)(arg0) + (0xC0))) + 8, arg0);
    {
        s32 i;
        for (i = 0; i < 5; i++) {
            *(s32 *)(*(u8 **)(arg0 + 0xC0) + 0x4C + i * 0x28) = 0;
        }
    }
}

void func_8009ACF4(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 192) + 0) = arg1;
}

void func_8009AD04(void *arg0, f32 arg1) {
    *(f32 *)((u8 *)*(void **)((u8 *)arg0 + 192) + 4) = arg1;
}

void func_8009AD14(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 192) + 20) = arg1;
}

void func_8009AD20(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 192) + 24) = arg1;
}

void func_8009AD2C(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 192) + 28) = arg1;
}

void func_8009AD38(void *arg0, s32 arg1) {
    *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 192) + 32) = arg1;
}

/* extern */

void func_8009AD44(PlayerState *arg0, f32 *arg1) {
    s32 func_800EE7F8();
    func_800EE7F8(arg0->unkC0->pad8, arg1);
}
