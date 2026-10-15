#include "common.h"

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/store/subaddiestore_entrypoint_0.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/store/subaddiestore_entrypoint_1.s")

s32 func_80800260_subaddiestore(Unk80132ED0 *arg0) {
    typedef struct {
        u8 pad0[0x64];
        u32 pad64:14;
        u32 flag64:1;
        u32 rest64:17;
        u32 pad68[2];
        u32 pad70:14;
        u32 flag70:1;
        u32 rest70:17;
        u32 pad74:14;
        u32 flag74:1;
        u32 rest74:17;
    } StoreFlags;
    s32 _glcutDll_entrypoint_8(void);
    int func_800DB9B0(void);
    s32 func_800EA05C(void);
    s32 func_80102F74(Unk80132ED0 *, s32);
    s32 sp1C[3];
    s32 var_a0;

    if (*(u32 **)arg0 == NULL) {
        return 0;
    }
    if (!((StoreFlags *)arg0)->flag74 || ((StoreFlags *)arg0)->flag64) {
        return 0;
    }
    if (((StoreFlags *)arg0)->flag70) {
        var_a0 = func_800DB9B0() != 0;
        if (var_a0 != 0) {
            sp1C[0] = _glcutDll_entrypoint_8();
            var_a0 = func_800EA05C() != sp1C[0];
        }
        var_a0 = var_a0 ? 1 : 0;
        return var_a0;
    } else {
        if (func_80102F74(arg0, 0x80) != 0) {
            return 2;
        }
        return arg0 != NULL ? 1 : 1;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/store/func_80800330_subaddiestore.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/store/func_808003AC_subaddiestore.s")

u8 *func_808004FC_subaddiestore(u8 *arg0, u8 *arg1) {
    typedef struct {
        u8 pad0[0x10];
        u32 pad10:16;
        u32 id:15;
        u32 flag10:1;
        u32 pad14;
        u32 pad18:31;
        u32 flag18:1;
        u32 pad1C[2];
        u32 index:10;
        u32 pad24:22;
        u32 pad28:21;
        u32 flag28a:1;
        u32 flag28b:1;
        u32 value28:8;
        u32 pad2B:1;
    } Marker;
    typedef struct {
        u8 body[0x9C];
        u8 animFlag:1;
        u8 flag28a:1;
        u8 flag28b:1;
        u32 index:10;
        u8 playback:3;
        u32 animIndex:14;
        u8 flag9F:1;
        u8 pad9F:1;
        f32 duration;
        u16 timer;
        u16 transition;
        u16 start;
        u16 end;
        u8 loop:1;
        u32 id:15;
        u8 hasAnim:1;
        u8 value28:6;
        u32 flag10:1;
        u32 flag18:1;
        u8 padAF:7;
    } Saved;
    typedef struct { u8 data[0x48]; } Extra48;
    typedef struct { u8 data[0x18]; } Extra18;
    f32 anctrl_getAnimTimer(s32);
    s32 anctrl_getIndex(s32);
    s32 anctrl_getPlaybackType(s32);
    u8 *func_8001B798(s16);
    s32 func_8001B7B8(s16);
    void func_8008B238(s32, f32 *, f32 *);
    s32 func_8008B28C(s32);
    s32 func_8008B29C(s32);
    f32 func_8008B2AC(s32);
    f32 func_8008B2D4(s32);
    s32 func_80104248(u8 *);
    u8 *func_80105494(u8 *);
    u8 *func_80106F30(u8 *);
    s32 func_8010A698(u8 *);
    s32 func_80800260_subaddiestore(Unk80132ED0 *);
    s32 func_80800F98_subaddiestore(u8 *);
    void rare_memcpy(void *, void *, int);
    Extra48 *first;
    Extra18 *second;
    f32 start;
    f32 end;
    s16 handle;
    u8 *base;
    s32 *sizes;
    u8 *out;
    s32 anim;
    s32 size;
    s32 i;
    u8 *entry;

    if (func_80800260_subaddiestore((Unk80132ED0 *)arg0) != 1) {
        return arg1;
    }
    rare_memcpy(arg1, arg0, 0x9C);
    *(s16 *)(arg1 + 0x60) = 0;
    arg1[0x75] &= ~4;
    arg1[0x64] &= ~4;
    arg1[0x5F] = 0;
    *(s32 *)(arg1 + 0x40) = 0;
    *(s32 *)(arg1 + 0x3C) = 0;
    *(s16 *)(arg1 + 0x90) = 0;
    *(s16 *)(arg1 + 0x80) = 0;
    *(s16 *)(arg1 + 0x8E) = 0;
    arg1[0x73] &= ~8;
    arg1[0x74] &= ~0x80;
    ((Saved *)arg1)->index = (*(Marker **)arg0)->index;
    ((Saved *)arg1)->id = (*(Marker **)arg0)->id;
    ((Saved *)arg1)->flag28a = (*(Marker **)arg0)->flag28a;
    ((Saved *)arg1)->flag28b = (*(Marker **)arg0)->flag28b;
    ((Saved *)arg1)->flag9F = func_8010A698(arg0);
    ((Saved *)arg1)->value28 = (*(Marker **)arg0)->value28;
    ((Saved *)arg1)->flag10 = (*(Marker **)arg0)->flag10;
    ((Saved *)arg1)->flag18 = (*(Marker **)arg0)->flag18;
    if (*(s16 *)(arg0 + 0x8C) != 0) {
        anim = func_80104248(arg0);
        ((Saved *)arg1)->animIndex = anctrl_getIndex(anim);
        ((Saved *)arg1)->playback = anctrl_getPlaybackType(anim);
        ((Saved *)arg1)->loop = func_8008B28C(anim);
        ((Saved *)arg1)->animFlag = func_8008B29C(anim);
        *(f32 *)(arg1 + 0xA0) = func_8008B2AC(anim);
        func_8008B238(anim, &start, &end);
        *(s16 *)(arg1 + 0xA8) = (u32)(start * 32768.0f);
        *(s16 *)(arg1 + 0xAA) = (u32)(end * 32768.0f);
        *(s16 *)(arg1 + 0xA4) = (u32)(anctrl_getAnimTimer(anim) * 32768.0f);
        *(s16 *)(arg1 + 0xA6) = (u32)(func_8008B2D4(anim) * 32768.0f);
    }
    if (*(s16 *)(arg0 + 0x8C) != 0) {
        ((Saved *)arg1)->hasAnim = 1;
    } else {
        ((Saved *)arg1)->hasAnim = 0;
    }
    *(s16 *)(arg1 + 0x8C) = 0;
    *(s32 *)arg1 = 0;
    base = arg1 + 0xB0;
    entry = base;
    out = entry;
    if (*(s32 *)(arg0 + 0x7C) & 0xFFF) {
        first = (Extra48 *)out;
        rare_memcpy(out, func_80105494(arg0), 0x48);
        out = (u8 *)(first + 1);
    }
    second = (Extra18 *)out;
    if ((*(u32 *)(arg0 + 0x94) << 2) >> 22) {
        rare_memcpy(out, func_80106F30(arg0), 0x18);
        out = (u8 *)(second + 1);
    }
    if (func_80800F98_subaddiestore(arg0) != 0) {
        sizes = (s32 *)out;
        out += 0xC;
        entry = arg0;
        i = 0;
        do {
            handle = *(s16 *)(entry + 0x82);
            if (handle != 0) {
                size = func_8001B7B8(handle);
                *sizes = size;
                rare_memcpy(out, func_8001B798(*(s16 *)(entry + 0x82)), size);
                out += size;
            } else {
                *sizes = 0;
            }
            i += 4;
            entry += 2;
            sizes++;
        } while (i != 0xC);
    }
    return out;
}

/* extern */

u32 *func_80800AD8_subaddiestore(void *arg0, u32 *arg1) {
    s32 func_80800260_subaddiestore();
    if (func_80800260_subaddiestore() != 2) {
        return arg1;
    }
    *arg1 = (u32) (*(u32 *)((s8 *)(arg0) + (0x6C))) >> 0x15;
    return arg1 + 1;
}

void func_80800B24_subaddiestore(u8 *arg0, u8 *arg1) {
    typedef struct {
        u8 pad0[0x10];
        u32 pad10:16;
        u32 id:15;
        u32 flag10:1;
        u32 pad14;
        u32 pad18:31;
        u32 flag18:1;
        u32 pad1C[2];
        u32 index:10;
        u32 pad24:22;
        u32 pad28:21;
        u32 flag28a:1;
        u32 flag28b:1;
        u32 value28:8;
        u32 pad2B:1;
    } Marker;
    typedef struct {
        u8 body[0x9C];
        u8 animFlag:1;
        u8 flag28a:1;
        u8 flag28b:1;
        u32 index:10;
        u32 playback:3;
        u32 animIndex:14;
        u8 flag9F:1;
        u8 pad9F:1;
        f32 duration;
        u16 timer;
        u16 transition;
        u16 start;
        u16 end;
        u8 loop:1;
        u32 id:15;
        u8 hasAnim:1;
        u8 value28:6;
        u32 flag10:1;
        u32 flag18:1;
        u8 padAF:7;
    } Saved;
    typedef struct { u8 data[0x48]; } Extra48;
    typedef struct { u8 data[0x18]; } Extra18;
    void anctrl_setDuration(s32, f32);
    void anctrl_setIndex(s32, s32);
    s32 anctrl_setPlaybackType(s32, s32);
    void anctrl_setSmoothTransition(s32, s32);
    void anctrl_setSubrange(s32, f32, f32);
    s32 anctrl_start(s32);
    s16 func_8001B668(s32, s32);
    s32 func_8001B754(s16);
    u8 *func_8001B798(s16);
    void func_8008B10C(s32, f32);
    void func_8008B188(s32, s32);
    void func_8008B2DC(s32, f32);
    f32 func_800F0D50(f32, f32, f32);
    s32 func_80103014(u8 *);
    s32 func_80104248(u8 *);
    s32 func_801042B8(u8 *);
    void func_80104328(u8 *);
    u8 *func_8010556C(u8 *);
    void func_80105634(u8 *);
    u8 *func_80106E88(u8 *);
    void func_80106EE0(u8 *);
    void func_8010A654(u8 *, u32);
    s32 func_80800F98_subaddiestore(u8 *);
    void rare_memcpy(void *, void *, int);
    Extra48 *first;
    Extra18 *second;
    s32 pad[7];
    f32 timer;
    f32 transition;
    f32 start;
    f32 end;
    s32 padEnd;
    u8 *out;
    s32 *sizes;
    u8 *entry;
    s32 offset;
    s32 i;
    s32 anim;
    u32 playback;
    s16 handle;

    *(u32 *)arg0 = *(u32 *)arg1;
    out = arg0 + 0xB0;
    *(s16 *)(arg0 + 0x8C) = *(s16 *)(arg1 + 0x8C);
    if (*(u32 *)(arg1 + 0x7C) & 0xFFF) {
        func_80105634(arg1);
    }
    if ((*(u32 *)(arg1 + 0x94) << 2) >> 22) {
        func_80106EE0(arg1);
    }
    if (*(u32 *)(arg0 + 0x7C) & 0xFFF) {
        *(u16 *)(arg0 + 0x7E) &= 0xF000;
        first = (Extra48 *)out;
        rare_memcpy(func_8010556C(arg0), out, 0x48);
        out = (u8 *)(first + 1);
    }
    if ((*(u32 *)(arg0 + 0x94) << 2) >> 22) {
        *(u16 *)(arg0 + 0x94) &= 0xC00F;
        second = (Extra18 *)out;
        rare_memcpy(func_80106E88(arg0), out, 0x18);
        out = (u8 *)(second + 1);
    }
    if (func_80800F98_subaddiestore(arg0) != 0) {
        sizes = (s32 *)out;
        out += 0xC;
        offset = 0;
        entry = arg1;
        i = 0;
        do {
            handle = *(s16 *)(entry + 0x82);
            if (handle != 0) {
                func_8001B754(handle);
                *(s16 *)(entry + 0x82) = 0;
            }
            if (*sizes > 0) {
                *(s16 *)(arg0 + offset + 0x82) = func_8001B668(0, *sizes);
                rare_memcpy(func_8001B798(*(s16 *)(arg0 + offset + 0x82)), out, *sizes);
                out = *sizes + out;
            }
            i += 4;
            offset += 2;
            entry += 2;
            sizes++;
        } while (i != 0xC);
    }
    rare_memcpy(arg1, arg0, 0x9C);
    if (*(s16 *)(arg1 + 0x8C) != 0 || ((Saved *)arg0)->hasAnim) {
        anim = func_80104248(arg1);
        if (((Saved *)arg0)->hasAnim) {
            if (anim == 0) {
                anim = func_801042B8(arg1);
            }
            if (((Saved *)arg0)->playback != 0) {
                anctrl_setPlaybackType(anim, ((Saved *)arg0)->playback);
            }
            anctrl_setIndex(anim, ((Saved *)arg0)->animIndex);
            func_8008B188(anim, ((Saved *)arg0)->loop);
            anctrl_setSmoothTransition(anim, ((Saved *)arg0)->animFlag);
            anctrl_setDuration(anim, ((Saved *)arg0)->duration);
            start = (u32)((Saved *)arg0)->start * 0.000030517578125f;
            end = (u32)((Saved *)arg0)->end * 0.000030517578125f;
            timer = func_800F0D50((u32)((Saved *)arg0)->timer * 0.000030517578125f, start, end);
            transition = func_800F0D50((u32)((Saved *)arg0)->transition * 0.000030517578125f, start, end);
            func_8008B10C(anim, timer);
            anctrl_setSubrange(anim, start, end);
            anctrl_start(anim);
            func_8008B2DC(anim, transition);
            func_8008B10C(anim, timer);
        } else {
            func_80104328(arg1);
        }
    }
    (*(Marker **)arg1)->id = ((Saved *)arg0)->id;
    func_8010A654(arg1, ((Saved *)arg0)->flag9F);
    (*(Marker **)arg1)->flag28a = ((Saved *)arg0)->flag28a;
    (*(Marker **)arg1)->flag28b = ((Saved *)arg0)->flag28b;
    arg1[0x7E] &= ~0x80;
    arg1[0x7E] &= 0xEF;
    (*(Marker **)arg1)->value28 = ((Saved *)arg0)->value28;
    (*(Marker **)arg1)->flag10 = ((Saved *)arg0)->flag10;
    (*(Marker **)arg1)->flag18 = ((Saved *)arg0)->flag18;
    func_80103014(arg1);
}

s32 func_80800F98_subaddiestore(u8 *arg0) {
    s32 var_v1;
    for (var_v1 = 0; var_v1 < 3; var_v1++) {
        if (((s16 *)(arg0 + 0x82))[var_v1] != 0) {
            return 1;
        }
    }
    return 0;
}

/* extern */

u8 *func_80800FD0_subaddiestore(u8 *arg0) {
    u8 *var_a1;
    u8 *temp_v0;

    temp_v0 = arg0 + 0xB0;
    var_a1 = temp_v0;
    if ((*(s32 *)((s8 *)(arg0) + (0x7C))) & 0xFFF) {
        var_a1 = temp_v0 + 0x48;
    }
    if (((u32) ((*(s32 *)((s8 *)(arg0) + (0x94))) * 4) >> 0x16) != 0) {
        var_a1 += 0x18;
    }
    if (func_80800F98_subaddiestore(arg0) != 0) {
        s32 var_v0;
        temp_v0 = var_a1;
        var_a1 += 0xC;
        for (var_v0 = 0; var_v0 < 3; var_v0++) {
            var_a1 = ((s32 *)temp_v0)[var_v0] + var_a1;
        }
    }
    return var_a1;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/su/baddie/store/func_80801054_subaddiestore.s")
