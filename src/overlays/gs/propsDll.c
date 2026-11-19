#if defined(BT_NATIVE) && !defined(BT_ILP32)
#include "native_map_props.h"
#include "native_actor.h"

void gspropsDll_entrypoint_0(NativeWorldCell *cell, Prop **output, s32 *count) {
    Prop *prop = cell ? func_800E9D68(cell) : NULL;
    Prop *end = cell ? func_800E9D90(cell) : NULL;
    for (; prop && prop < end; ++prop)
        if (prop->unk6_1 == 6) output[(*count)++] = prop;
}

void gspropsDll_entrypoint_1(Prop **props, s32 count) {
    s32 i, j, position[3];
    Prop *temp, *prop;
    Actor *actor;
    u32 flags;
    for (i = 0; i < count; ++i) {
        for (j = 0; j < i; ++j) {
            if (props[i]->ItemID < props[j]->ItemID) {
                temp = props[j]; props[j] = props[i]; props[i] = temp;
            }
        }
    }
    for (i = 0; i < count; ++i) {
        prop = props[i];
        for (j = 0; j < 3; ++j) position[j] = prop->position[j];
        flags = ((u32)prop->unk10 << 16) | prop->unk12;
        actor = func_80108DC0(prop->ItemID, position, prop->FlagOrRotation,
                              flags >> 21, (flags << 11) >> 21, prop);
        if (actor) {
            actor->unk74_7 = prop->unk6_7;
            actor->unk7A_5 = 1;
            func_80102FDC(actor, _gspropmarker_entrypoint_3(prop));
        }
    }
}

void gspropsDll_entrypoint_2(NativeWorldCell *cell, s32 pass) {
    void func_800CBA68(s32 arg0, BtIntPtr arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
    void func_800CBAC8(s32 arg0, BtIntPtr arg1, s32 arg2, s32 arg3, s32 arg4);
    void func_800CBB18(s32 arg0, BtIntPtr arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
    Prop *prop = cell ? func_800E9D68(cell) : NULL;
    Prop *end = cell ? func_800E9D90(cell) : NULL;
    for (; prop && prop < end; ++prop) {
        u32 flags = ((u32)prop->unk10 << 16) | prop->unk12;
        s32 size = prop->unk6_7, duration = prop->FlagOrRotation * 5;
        s32 selected = (flags >> 6) & 1;
        if (!duration) duration = 300;
        if (flags & 32) size *= 5;
        if (prop->unk6_1 == 7 && selected == (pass != 0)) {
            func_800CBA68(prop->ItemID, prop, size, duration,
                         flags >> 21, (flags >> 9) & 1, selected);
        }
        if (!pass) {
            if (prop->unk6_1 == 9)
                func_800CBAC8(prop->ItemID, prop, size, flags & 3, duration);
            else if (prop->unk6_1 == 12)
                func_800CBB18(prop->ItemID, prop, size, duration, flags & 3, (flags >> 9) & 1);
        }
    }
}

s32 func_808004E0_gspropsDll(Prop *prop) {
    return prop->unk6_1 < 6 || prop->unk6_1 > 12;
}

s32 func_80800524_gspropsDll(NativeWorldCell *cell) {
    s32 i, j, movable = 0;
    Prop *props = func_800E9D68(cell), temp;
    for (i = 0; i < cell->models[1]; ++i) {
        if (func_808004E0_gspropsDll(props + i)) {
            ++movable;
            for (j = i; j > 0 && func_808004E0_gspropsDll(props + j) &&
                 !func_808004E0_gspropsDll(props + j - 1); --j) {
                temp = props[j]; props[j] = props[j - 1]; props[j - 1] = temp;
            }
        }
    }
    *func_800BE5C4(cell) = movable;
    return movable;
}

void gspropsDll_entrypoint_3(Prop *source) {
    s32 position[3], i;
    NativeWorldCell *cell;
    Prop *prop;
    for (i = 0; i < 3; ++i) position[i] = source->position[i];
    cell = func_800BDBC4(position);
    prop = func_800E9A24(cell);
    *prop = *source;
    if (!(prop->flags6 & 1)) prop->unk12 |= 0x100;
    func_80800524_gspropsDll(cell);
}

void gspropsDll_entrypoint_4(NativeMarkerProp *source) {
    s32 position[3], i;
    NativeMarkerProp *prop;
    for (i = 0; i < 3; ++i) position[i] = source->position[i];
    prop = func_800E98C0(func_800BDBC4(position));
    *prop = *source;
    prop->flags |= 16;
    if (prop->flags & 2) prop->flags &= ~32;
}
#else
#include "common.h"

void gspropsDll_entrypoint_0(s16 *arg0, Prop **arg1, s32 *arg2) {
    Prop *func_800E9D68(s16 *);
    u32 func_800E9D90(s16 *);
    Prop *start;
    u32 end;
    Prop *prop;

    if (arg0 != NULL && arg0[1] != 0) {
        start = func_800E9D68(arg0);
        end = func_800E9D90(arg0);
        prop = start;
        if ((u32)prop < end) {
            do {
                if (prop->unk6_1 == 6) {
                    arg1[*arg2] = prop;
                    *arg2 += 1;
                }
                prop++;
            } while ((u32)prop < end);
        }
    }
}

void gspropsDll_entrypoint_1(Prop **arg0, s32 arg1) {
    f32 _gspropmarker_entrypoint_3(Prop *);
    void func_80102FDC(void *, f32);
    Actor *func_80108DC0(s32, s32 *, u32, s32, s32, Prop *);
    s32 i;
    s32 j;
    Prop *temp;
    s32 position[3];
    Prop *prop;
    Actor *actor;

    for (i = 0; i < arg1; i++) {
        for (j = 0; j < i; j++) {
            if ((u32)arg0[i]->ItemID < (u32)arg0[j]->ItemID) {
                temp = arg0[j];
                arg0[j] = arg0[i];
                arg0[i] = temp;
            }
        }
    }
    for (i = 0; i < arg1; i++) {
        prop = arg0[i];
        position[0] = prop->position[0];
        position[1] = prop->position[1];
        position[2] = prop->position[2];
        actor = func_80108DC0(prop->ItemID, position, prop->FlagOrRotation,
                            *(u32 *)&prop->unk10 >> 21,
                            (*(u32 *)&prop->unk10 << 11) >> 21, prop);
        if (actor != NULL) {
            actor->unk74_7 = prop->unk6_7;
            actor->unk7A_5 = 1;
            func_80102FDC(actor, _gspropmarker_entrypoint_3(prop));
        }
    }
}

void gspropsDll_entrypoint_2(s16 *arg0, s32 arg1) {
    Prop *func_800E9D68(s16 *);
    u32 func_800E9D90(s16 *);
    void func_800CBA68(s32, s32, s32, s32, s32, s32, s32);
    void func_800CBAC8(s32, s32, s32, s32, s32);
    void func_800CBB18(s32, s32, s32, s32, s32, s32);
    Prop *prop;
    u32 end;
    s32 size;
    s32 duration;
    u32 flags;
    u32 flag6;
    s32 enabled;
    s32 selected;

    if (arg0 != NULL && arg0[1] != 0) {
        prop = func_800E9D68(arg0);
        end = func_800E9D90(arg0);
        for (; (u32)prop < end; prop++) {
            if (prop->unk6_1 == 7) {
                selected = arg1 ? 1 : 0;
                flags = *(u32 *)&prop->unk10;
                flag6 = (flags << 25) >> 31;
                enabled = flag6 ? 1 : 0;
                if (enabled == selected) {
                    size = prop->unk6_7;
                    duration = prop->FlagOrRotation * 5;
                    if (duration == 0) duration = 300;
                    if ((flags << 26) >> 31) size *= 5;
                    func_800CBA68(prop->ItemID, (s32)prop, size, duration,
                                 flags >> 21, (flags << 22) >> 31, flag6);
                }
            }
            if (arg1 == 0) {
                u32 type = prop->unk6_1;
                if (type == 9) {
                    s32 size2;
                    s32 duration2;
                    flags = *(u32 *)&prop->unk10;
                    size2 = prop->unk6_7;
                    duration2 = prop->FlagOrRotation * 5;
                    if (duration2 == 0) duration2 = 300;
                    if ((flags << 26) >> 31) size2 *= 5;
                    func_800CBAC8(prop->ItemID, (s32)prop, size2, flags & 3, duration2);
                } else {
                switch (type) {
                case 10:
                    break;
                case 12: {
                    s32 size3;
                    s32 duration3;
                    size3 = prop->unk6_7;
                    flags = *(u32 *)&prop->unk10;
                    duration3 = prop->FlagOrRotation * 5;
                    if (duration3 == 0) duration3 = 300;
                    if ((flags << 26) >> 31) size3 *= 5;
                    func_800CBB18(prop->ItemID, (s32)prop, size3, duration3,
                                 flags & 3, (flags << 22) >> 31);
                    break;
                }
                default:
                    break;
                }
                }
            }
        }
    }
}

s32 func_808004E0_gspropsDll(Prop *arg0) {
    switch (arg0->unk6_1) {
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
        return 0;
    default:
        return 1;
    }
}

s32 func_80800524_gspropsDll(s32 arg0) {
    void aligned4_memcpy(void *, void *, int);
    u8 *func_800BE5C4(u8 *);
    s32 func_800E9BF4(s16 *, s32);
    s32 count;
    s32 i;
    s32 j;
    s32 movable;
    Prop temp;

    count = ((s16 *)arg0)[1];
    movable = 0;
    i = 0;
    if (count > 0) {
        do {
            if (func_808004E0_gspropsDll((Prop *)func_800E9BF4((s16 *)arg0, i))) {
                movable++;
                for (j = i; j > 0 &&
                     func_808004E0_gspropsDll((Prop *)func_800E9BF4((s16 *)arg0, j)) &&
                     !func_808004E0_gspropsDll((Prop *)func_800E9BF4((s16 *)arg0, j - 1)); j--) {
                    aligned4_memcpy(&temp, (void *)func_800E9BF4((s16 *)arg0, j), 0x14);
                    aligned4_memcpy((void *)func_800E9BF4((s16 *)arg0, j),
                                    (void *)func_800E9BF4((s16 *)arg0, j - 1), 0x14);
                    aligned4_memcpy((void *)func_800E9BF4((s16 *)arg0, j - 1), &temp, 0x14);
                }
            }
            i++;
        } while (i != count);
    }
    BT_IDO_ONLY(*func_800BE5C4((u8 *)arg0) = movable;) BT_NATIVE_ONLY({ u8 *result = func_800BE5C4((u8 *)arg0); *result = movable; return (s32)result; })
}

/* extern */

BT_IDO_ONLY(void) BT_NATIVE_ONLY(s32) gspropsDll_entrypoint_3(s16 *arg0) {
    void aligned4_memcpy(void *, void *, int);
    s32 func_800BDBC4(s32);
    void *func_800E9A24(s32);
    void func_800EE8CC(s32 *, s16 *);
    s32 func_80800524_gspropsDll(s32);
    typedef struct {
        u8 pad[0x12];
        BT_BITFIELD_ORDER(u8 reserved : 7, u8 enabled : 1);
        BT_BITFIELD_ORDER(u8 enabled : 1, u8 reserved : 7);
    } PropFlags;
    s32 sp2C;
    s32 sp20[3];
    PropFlags *sp1C;

    func_800EE8CC(sp20, arg0);
    sp2C = func_800BDBC4((s32)sp20);
    sp1C = func_800E9A24(sp2C);
    aligned4_memcpy(sp1C, arg0, 0x14);
    if (!((*(s32 *)((s8 *)(sp1C) + (4))) & 1)) {
        sp1C->enabled = 1;
    }
    BT_NATIVE_ONLY(return) func_80800524_gspropsDll(sp2C);
}

/* extern */

void gspropsDll_entrypoint_4(s16 *arg0) {
    void aligned4_memcpy(void *, void *, int);
    s32 func_800BDBC4(s32);
    void *func_800E98C0(s32);
    void func_800EE8CC(s32 *, s16 *);
    typedef struct {
        u8 pad[8];
        BT_BITFIELD_ORDER(u32 reserved : 26, u32 reserved3 : 1);
        BT_BITFIELD_ORDER(u32 flag5 : 1, u32 flag1 : 1);
        BT_BITFIELD_ORDER(u32 flag4 : 1, u32 reserved2 : 2);
        BT_BITFIELD_ORDER(u32 reserved2 : 2, u32 flag4 : 1);
        BT_BITFIELD_ORDER(u32 flag1 : 1, u32 flag5 : 1);
        BT_BITFIELD_ORDER(u32 reserved3 : 1, u32 reserved : 26);
    } PropFlags;
    s32 sp2C;
    s32 sp20[3];
    PropFlags *sp1C;

    func_800EE8CC(sp20, arg0 + 2);
    sp2C = func_800BDBC4((s32)sp20);
    sp1C = func_800E98C0(sp2C);
    aligned4_memcpy(sp1C, arg0, 0xC);
    sp1C->flag4 = 1;
    if (sp1C->flag1) {
        sp1C->flag5 = 0;
    }
}

#endif
