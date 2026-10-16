#include "common.h"

/* extern */

void subaddieDll_entrypoint_0(void *arg0) {
    void func_80103014(u8 *);
    u32 func_8010A654(void ***, s32);
    u32 func_8010A698(void ***);
    s32 sp1C;
    struct Flags {
        u8 pad[0x10];
        u32 upper : 31;
        u32 enabled : 1;
    } *flags;

    if (!(((Actor *)arg0)->unk0->unk10 & 1)) {
        sp1C = func_8010A698(arg0);
        flags = (void *)((Actor *)arg0)->unk0;
        flags->enabled = 1;
        func_80103014(arg0);
        func_8010A654(arg0, sp1C);
    }
}

/* extern */

void subaddieDll_entrypoint_1(Actor *arg0) {
    s32 subaddieDll_entrypoint_2(Actor *, f32 (*)[3]);
    subaddieDll_entrypoint_2(arg0, &arg0->position);
}

/* extern */

s32 subaddieDll_entrypoint_2(Actor *arg0, f32 (*arg1)[3]) {
    s32 func_800CBC3C();
    s32 func_800CC338(f32 (*)[3], s32, s32);
    struct BaddieFlags {
        u8 pad[0x70];
        u32 index : 7;
        u32 unused : 15;
        u32 value : 6;
        u32 lower : 4;
    } *flags = (void *)arg0;

    flags->index = func_800CBC3C(arg1) + 1;
    if (flags->index == 0) {
        return 0;
    }
    flags->value = func_800CC338(arg1, flags->index - 1, 0) + 1;
    return 1;
}

/* extern */

s32 subaddieDll_entrypoint_3(Actor *arg0) {
    s32 func_800CC338(f32 (*)[3], s32, s32);
    struct BaddieFlags {
        u8 pad[0x70];
        u32 index : 7;
        u32 unused : 15;
        u32 value : 6;
        u32 lower : 4;
    } *flags = (void *)arg0;
    s32 value;
    s32 result;

    if (flags->index == 0 || (value = flags->value) == 0) {
        return 0;
    }
    result = func_800CC338(&arg0->position, flags->index - 1, value - 1);
    if (result != -1) {
        flags->value = result + 1;
        return 1;
    }
    return 0;
}

/* extern */

void subaddieDll_entrypoint_4(void *arg0, s32 arg1) {
    void *func_80100368();
    if (arg1 != 0) {
        (*(u16 *)((s8 *)(arg0) + (0x7C))) = 0U;
        return;
    }
    (*(u16 *)((s8 *)(arg0) + (0x7C))) = (u16) (*(u16 *)((s8 *)(func_80100368()) + (0x18)));
}

/* extern */

s32 subaddieDll_entrypoint_5(Actor *arg0, Unk80132ED0 *arg1) {
    s32 func_800F52B8(s32, Unk80132ED0 *);
    Unk80132ED0 *func_800F55D0(s32);
    u32 temp_t8;
    s32 sp1C;

    if ((arg1->unk24 >> 0x16) != 0) {
        return 0;
    }
    temp_t8 = (u32)((u16 *)&arg1->unk18)[1] >> 5;
    sp1C = temp_t8;
    if (func_800F52B8(temp_t8, arg0->unk0) != 0xB) {
        return 0;
    }
    if (func_800F55D0(sp1C) != arg0->unk0) {
        return 0;
    }
    return 1;
}

void func_80800260_subaddieDll(Actor *arg0, s32 arg1) {
    f32 temp_f0;
    s32 var_v0;

    if (func_8001210C(1) != 0) {
        var_v0 = arg1;
    } else {
        var_v0 = -arg1;
    }
    temp_f0 = (f32)var_v0;
    arg0->position[0] += temp_f0;
    arg0->position[2] += temp_f0;
}

/* extern */

s32 subaddieDll_entrypoint_6(Actor *arg0, s32 arg1) {
    s32 func_800F52B8(s32, Unk80132ED0 *);
    s32 func_800F54E4();
    if (func_800F52B8(func_800F54E4(), arg0->unk0) != 0xB) {
        return 1;
    }
    func_80800260_subaddieDll(arg0, arg1);
    return 0;
}

void subaddieDll_entrypoint_7(Actor *arg0, s32 arg1)
{
    func_80800260_subaddieDll(arg0, arg1);
}

s32 subaddieDll_entrypoint_8(s32 arg0) {
    Actor* func_80106790(Unk80132ED0 *);
    void func_8010A570(Actor*);
    Actor *volatile sp1C;
    Actor *temp_v0;

    temp_v0 = func_80106790((Unk80132ED0 *) arg0);
    sp1C = temp_v0;
    func_8010A570(temp_v0);
    return (s32) sp1C;
}

/* extern */

void subaddieDll_entrypoint_9(s32 arg0, s32 arg1) {
    s32 func_800DA544(s32);
    s32 subaddieDll_entrypoint_8(s32);
    func_800DA544(arg1);
    subaddieDll_entrypoint_8(arg0);
}

void subaddieDll_entrypoint_10(s32 arg0, s16 *arg1) {
    void _gccubesearch_entrypoint_7(s32 *, s16 **, s32);
    s32 query[2];
    s16 *results[3];
    s32 first;
    s32 second;
    s32 i;
    s16 *out;

    query[0] = arg0;
    query[1] = -1;
    _gccubesearch_entrypoint_7(query, results, 2);
    i = 0;
    out = arg1;
    do {
        first = *(s16 *)((u8 *)results[0] + i);
        second = *(s16 *)((u8 *)results[1] + i);
        i += 4;
        if (first < second) {
            out[0] = first;
        } else {
            out[0] = second;
        }
        if (second < first) {
            out[2] = first;
        } else {
            out[2] = second;
        }
        out++;
    } while (i != 8);
}

/* extern */

s32 subaddieDll_entrypoint_11(Actor *arg0, s32 arg1, s32 arg2) {
    s32 func_800CC338(f32 (*)[3], s32, s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    struct BaddieFlags {
        u8 pad[0x70];
        u32 index : 7;
        u32 unused : 15;
        u32 value : 6;
        u32 lower : 4;
    };
    f32 sp1C[3];
    s32 pad;

    if (((struct BaddieFlags *)arg0)->index == 0) {
        return 1;
    }
    func_800EE7F8(sp1C, arg0->position);
    func_800EF1B8(sp1C, (f32) arg1, (f32) arg2);
    if (func_800CC338(&sp1C, ((struct BaddieFlags *)arg0)->index - 1, ((struct BaddieFlags *)arg0)->value - 1) == -1) {
        return 0;
    }
    return 1;
}

/* extern */

void subaddieDll_entrypoint_12(void *arg0, void *arg1) {
    s16 func_800DC128(s16, s16, void *);
    (*(s16 *)((s8 *)(arg1) + (0))) = func_800DC128((*(s16 *)((s8 *)(arg0) + (0))), (*(s16 *)((s8 *)(arg0) + (4))), arg0);
    (*(s16 *)((s8 *)(arg1) + (2))) = func_800DC128((*(s16 *)((s8 *)(arg0) + (2))), (*(s16 *)((s8 *)(arg0) + (6))), arg0);
}
