#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/deflect/sudeflect_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/deflect/sudeflect_entrypoint_1.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/deflect/sudeflect_entrypoint_2.s")

extern struct {
    s32 entries[9];
    s32 count;
} B_80801020_sudeflect;

s32 sudeflect_entrypoint_3(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 func_800F4E5C(s32, s32, s32, s32, s32);
    s32 func_800F6438(u32);
    s32 var_s0;
    s32 var_s2;

    var_s2 = 0;
    B_80801020_sudeflect.count = 0;
    if (arg4 & 2) {
        var_s0 = 0;
        do {
            if ((func_800F6438(var_s0) != 0) && (func_800F4E5C(var_s0, arg0, arg1, arg2, arg3) != 0)) {
                B_80801020_sudeflect.entries[B_80801020_sudeflect.count + 1] = var_s0;
                B_80801020_sudeflect.count++;
                var_s2 |= 2;
            }
            var_s0 += 1;
        } while (var_s0 != 8);
    }
    return var_s2;
}

void sudeflect_entrypoint_4(s32 arg0, f32 *arg1) {
    int func_800F7700(s32, s32, f32 *);
    s32 func_80800630_sudeflect(s32);
    s32 temp_s0;
    s32 var_s1;

    for (var_s1 = 0; var_s1 < B_80801020_sudeflect.count; var_s1++) {
        temp_s0 = B_80801020_sudeflect.entries[var_s1 + 1];
        if (func_80800630_sudeflect(temp_s0) != 0) {
            func_800F7700(temp_s0, arg0, arg1);
        }
    }
}

/* extern */

s32 func_80800630_sudeflect(s32 arg0) {
    s32 func_800F52B8(s32, s32);
    s32 func_800F5410(s32);
    s32 func_800F6720();
    s32 temp_v0;

    if (func_800F6720() != 0) {
        return 1;
    }
    if (func_800F5410(arg0) == 0x11) {
        return 1;
    }
    temp_v0 = func_800F52B8(arg0, 0);
    if ((temp_v0 == 1) || (temp_v0 == 0xB)) {
        return 1;
    }
    return 0;
}

s32 func_808006A4_sudeflect(f32 *arg0, f32 arg1, f32 arg2) {
    s32 _sueggmisc_entrypoint_0();
    s32 func_800E9E88(s32);
    u32 func_800E9EB4(s16 *);
    void func_800EE7F8(f32 *, f32 *);
    s32 func_800F0008(f32 *, f32, f32 *, f32);
    s32 func_8010108C(Actor *, s32, s32);
    Actor *func_80106790(Unk80132ED0 *);
    struct EggProp {
        Unk80132ED0 *marker;
        s32 unk4;
        u32 flags;
    } *entry, *end;
    f32 radius;
    f32 position[3];
    Unk80132ED0 *marker;
    Actor *actor;
    s32 count;
    s16 **list;
    s16 *cell;

    radius = 38.0f;
    list = (s16 **)B_80801020_sudeflect.entries[0];
    count = 0;
    func_800EE7F8(position, arg0);
    position[1] += arg1;
    cell = *list;
    if (cell != NULL) {
        do {
            entry = (struct EggProp *)func_800E9E88((s32)cell);
            end = (struct EggProp *)func_800E9EB4(*list);
            if (entry < end) {
                do {
                if (entry->flags & 1) {
                marker = entry->marker;
                if (_sueggmisc_entrypoint_0(marker) != 0) {
                    actor = func_80106790(marker);
                    if (!actor->unk64_17 && func_800F0008(position, arg2, actor->position, radius)) {
                        count++;
                        func_8010108C(actor, 5, 0);
                    }
                }
                }
                entry++;
                } while (entry < end);
            }
            cell = list[1];
            list++;
        } while (cell != NULL);
    }
    return count;
}

s32 func_808007F4_sudeflect(f32 *arg0, f32 arg1, f32 arg2, f32 arg3) {
    s32 _sueggmisc_entrypoint_0();
    s32 func_800E9E88(s32);
    u32 func_800E9EB4(s16 *);
    s32 func_8010108C(Actor *, s32, s32);
    Actor *func_80106790(Unk80132ED0 *);
    s32 func_80800E44_sudeflect(f32 *, f32, f32, f32, f32 *, f32);
    struct EggProp {
        Unk80132ED0 *marker;
        s32 unk4;
        u32 flags;
    } *entry, *end;
    Unk80132ED0 *marker;
    Actor *actor;
    s32 count;
    s16 **list;
    s16 *cell;

    count = 0;
    for (list = (s16 **)B_80801020_sudeflect.entries[0]; (cell = *list) != NULL; list++) {
        entry = (struct EggProp *)func_800E9E88((s32)cell);
        end = (struct EggProp *)func_800E9EB4(*list);
        for (; entry < end; entry++) {
            if (!(entry->flags & 1)) {
                continue;
            }
            marker = entry->marker;
            if (!_sueggmisc_entrypoint_0(marker)) {
                continue;
            }
            actor = func_80106790(marker);
            if (!actor->unk64_17 && func_80800E44_sudeflect(arg0, arg1, arg2, arg3, actor->position, 38.0f)) {
                count++;
                func_8010108C(actor, 5, 0);
            }
        }
    }
    return count;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/deflect/func_80800940_sudeflect.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/deflect/func_80800A98_sudeflect.s")

s32 func_80800BEC_sudeflect(f32 *arg0, f32 *arg1) {
    s32 _sueggmisc_entrypoint_0();
    s32 func_800E9E88(s32);
    u32 func_800E9EB4(s16 *);
    s32 func_8010108C(Actor *, s32, s32);
    Actor *func_80106790(Unk80132ED0 *);
    s32 func_80800ECC_sudeflect(f32 *, f32 *, f32 *, f32);
    struct EggProp {
        Unk80132ED0 *marker;
        s32 unk4;
        u32 flags;
    } *entry, *end;
    Unk80132ED0 *marker;
    Actor *actor;
    s32 count;
    s16 **list;
    s16 *cell;

    list = (s16 **)B_80801020_sudeflect.entries[0];
    cell = *list;
    count = 0;
    if (cell != NULL) {
        do {
            entry = (struct EggProp *)func_800E9E88((s32)cell);
            end = (struct EggProp *)func_800E9EB4(*list);
            if (entry < end) {
                do {
                    if (entry->flags & 1) {
                        marker = entry->marker;
                        if (_sueggmisc_entrypoint_0(marker) != 0) {
                            actor = func_80106790(marker);
                            if (!actor->unk64_17 && func_80800ECC_sudeflect(arg0, arg1, actor->position, 38.0f)) {
                                count++;
                                func_8010108C(actor, 5, 0);
                            }
                        }
                    }
                    entry++;
                } while (entry < end);
            }
            cell = list[1];
            list++;
        } while (cell != NULL);
    }
    return count;
}

s32 func_80800D14_sudeflect(f32 *arg0, f32 *arg1) {
    s32 func_800E9E88(s32);
    u32 func_800E9EB4(s16 *);
    s32 func_8010108C(Actor *, s32, s32);
    Actor *func_80106790(Unk80132ED0 *);
    s32 func_80800ECC_sudeflect(f32 *, f32 *, f32 *, f32);
    struct DeflectProp {
        Unk80132ED0 *marker;
        s32 unk4;
        u32 flags;
    } *entry, *end;
    Unk80132ED0 *marker;
    Actor *actor;
    s32 count;
    s16 **list;
    s16 *cell;

    list = (s16 **)B_80801020_sudeflect.entries[0];
    cell = *list;
    count = 0;
    if (cell != NULL) {
        do {
            entry = (struct DeflectProp *)func_800E9E88((s32)cell);
            end = (struct DeflectProp *)func_800E9EB4(*list);
            if (entry < end) {
                do {
                    if (entry->flags & 1) {
                        marker = entry->marker;
                        if ((marker->unk24 >> 22) == 0x27A) {
                            actor = func_80106790(marker);
                            if (!actor->unk64_17 && func_80800ECC_sudeflect(arg0, arg1, actor->position, 40.0f)) {
                                count++;
                                func_8010108C(actor, 5, -1);
                            }
                        }
                    }
                    entry++;
                } while (entry < end);
            }
            cell = list[1];
            list++;
        } while (cell != NULL);
    }
    return count;
}

/* extern */

s32 func_80800E44_sudeflect(f32 *arg0, f32 arg1, f32 arg2, f32 arg3, f32 *arg4, f32 arg5) {
    int func_800F0064(f32 *, f32, f32 *);
    f32 temp_f0;

    temp_f0 = arg4[1] - arg0[1];
    if (arg1 < (temp_f0 - arg5)) {
        return 0;
    }
    if ((temp_f0 + arg5) < arg2) {
        return 0;
    }
    return func_800F0064(arg0, arg3 + arg5, arg4);
}

s32 func_80800ECC_sudeflect(f32 *arg0, f32 *arg1, f32 *arg2, f32 arg3) {
    void func_800EE7F8(f32 *, f32 *);
    f32 b;
    f32 a;
    f32 min[3];
    f32 max[3];
    s32 i;

    func_800EE7F8(min, arg2);
    func_800EE7F8(max, arg2);
    for (i = 0; i < 3; i++) {
        min[i] -= arg3;
        max[i] += arg3;
    }
    if (arg1[1] <= min[1] || max[1] <= arg0[1]) {
        return 0;
    }
    b = max[0] - arg0[0];
    a = min[0] - arg1[0];
    if (a >= 0.0f || b <= 0.0f) {
        return 0;
    }
    b = max[2] - arg0[2];
    a = min[2] - arg1[2];
    if (a >= 0.0f || b <= 0.0f) {
        return 0;
    }
    return 1;
}
