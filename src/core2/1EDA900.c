#include "core2/1EDA900.h"
Actor *func_80106790(Unk80132ED0 *);
extern void *D_80135A80;
extern f32 D_80135A70[3];
void func_800EE7F8(f32 *, f32 *);

void func_80101010(f32 *arg0) {
    func_800EE7F8(D_80135A70, arg0);
}

void func_80101038(f32 *arg0) {
    func_800EE7F8(arg0, D_80135A70);
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
    return func_8010108C(func_80106790((Unk80132ED0 *)arg0), arg1, arg2);
}

s32 func_80101180(s32 arg0, s32 arg1, s32 arg2) {
    s32 func_801067C4(s32 *);
    s32 func_8010682C(s32 *);
    Actor *var_v0;
    s32 sp38[1];
    s32 temp_v0;
    s32 var_s0;

    var_s0 = 0;
    var_v0 = (Actor *)func_801067C4(sp38);
    while (var_v0 != NULL) {
        if (!var_v0->unk64_17 && (arg0 == var_v0->unk6C_9)) {
            temp_v0 = func_8010108C(var_v0, arg1, arg2);
            if ((temp_v0 > 0) && (var_s0 == 0)) {
                var_s0 = temp_v0;
            }
        }
        var_v0 = (Actor *)func_8010682C(sp38);
    }
    return var_s0;
}

/* extern */

s32 func_80101238(s32 arg0, s32 arg1) {
    s32 func_801067C4(s32 *);
    s32 func_8010682C(s32 *);
    Actor *var_v0;
    s32 sp30[1];
    s32 temp_v0;
    s32 var_s0;

    var_s0 = 0;
    var_v0 = (Actor *)func_801067C4(sp30);
    while (var_v0 != NULL) {
        if (!var_v0->unk64_17) {
            temp_v0 = func_8010108C(var_v0, arg0, arg1);
            if ((temp_v0 > 0) && (var_s0 == 0)) {
                var_s0 = temp_v0;
            }
        }
        var_v0 = (Actor *)func_8010682C(sp30);
    }
    return var_s0;
}

s32 func_801012D0(f32 *arg0, f32 arg1, s32 arg2, s32 arg3) {
    f32 func_800EEB40(f32 *, f32 *);
    s32 func_801067C4(s32 *);
    s32 func_8010682C(s32 *);
    Actor *var_s0;
    s32 sp40[1];
    s32 temp_v0;
    s32 var_s1;

    var_s1 = 0;
    arg1 *= arg1;
    var_s0 = (Actor *)func_801067C4(sp40);
    while (var_s0 != NULL) {
        if (!var_s0->unk64_17 && (func_800EEB40(var_s0->position, arg0) < arg1)) {
            temp_v0 = func_8010108C(var_s0, arg2, arg3);
            if ((temp_v0 > 0) && (var_s1 == 0)) {
                var_s1 = temp_v0;
            }
        }
        var_s0 = (Actor *)func_8010682C(sp40);
    }
    return var_s1;
}

s32 func_801013A8(f32 *arg0, s32 arg1, s32 arg2) {
    void *func_800BDC44(void);
    s32 func_800BDC5C(void);
    s32 *func_800BE3F8(u8 *);
    s32 func_800E9E88(s32);
    u32 func_800E9EB4(s16 *);
    f32 func_800EEB40(f32 *, f32 *);
    typedef struct {
        Unk80132ED0 *marker;
        s32 unk4;
        u32 flags;
    } Entry;
    s32 result;
    s32 *cubes;
    Entry *entry;
    /* The original leaves last undefined when no per-cube entry supplies a result. */
    s32 last;
    Entry *end;
    Entry *globalEnd;
    s32 marker;
    void *cube;
    Actor *actor;

    cubes = func_800BE3F8((u8 *)arg0);
    result = 0;
    if (*cubes != 0) {
        do {
            entry = (Entry *)func_800E9E88(*cubes);
            end = (Entry *)func_800E9EB4((s16 *)*cubes);
            for (; entry < end; entry++) {
                if (!(entry->flags & 1)) {
                    continue;
                }
                marker = (s32)entry->marker;
                if (!(((u16 *)&((Unk80132ED0 *)marker)->unk18)[0] & 1)) {
                    continue;
                }
                last = func_8010114C(marker, arg1, arg2);
                if (last <= 0) {
                    continue;
                }
                if (result == 0) {
                    result = last;
                }
            }
            cubes++;
        } while (*cubes != 0);
    }
    cube = func_800BDC44();
    entry = (Entry *)func_800E9E88((s32)cube);
    globalEnd = (Entry *)func_800E9EB4((s16 *)cube);
    while (entry < globalEnd) {
        if (entry->flags & 1) {
            if (((u16 *)&entry->marker->unk18)[0] & 1) {
                f32 distance;
                s32 radius;
                actor = func_80106790(entry->marker);
                distance = func_800EEB40(actor->position, arg0);
                radius = func_800BDC5C();
                if (distance < (f32)func_800BDC5C() * 1.5f * (1.5f * (f32)radius)) {
                    func_8010108C(actor, arg1, arg2);
                    if (last > 0 && result == 0) {
                        result = last;
                    }
                }
            }
        }
        entry++;
    }
    return result;
}
