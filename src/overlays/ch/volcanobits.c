#include "common.h"

OSThread *chvolcanobits_entrypoint_0(void)
{
    extern ActorData D_80801154_chvolcanobits[];

    return (OSThread *) D_80801154_chvolcanobits;
}

OSThread *chvolcanobits_entrypoint_1(void)
{
    extern ActorData D_8080119C_chvolcanobits[];

    return (OSThread *) D_8080119C_chvolcanobits;
}

OSThread *chvolcanobits_entrypoint_2(void)
{
    extern ActorData D_808011E4_chvolcanobits[];

    return (OSThread *) D_808011E4_chvolcanobits;
}

OSThread *chvolcanobits_entrypoint_3(void)
{
    extern ActorData D_8080122C_chvolcanobits[];

    return (OSThread *) D_8080122C_chvolcanobits;
}

void func_80800030_chvolcanobits(Actor *arg0) {
    struct VolcanoBitsData {
        struct { s32 index; f32 speed; f32 height; } entries[8];
        s32 count;
        f32 timer;
    };
    Prop *props[8];
    s32 i;
    s32 count;
    s32 index;
    struct VolcanoBitsData *data;
    f32 position[3];
    void *func_80100094(Actor *, u32);
    s32 _gccubesearch_entrypoint_9(s32, Prop **, s32);
    void func_800EE88C(f32 *, s16 *);
    s32 func_800CBC3C(f32 *);
    f32 func_800DC178(f32, f32);

    data = func_80100094(arg0, 0);
    count = _gccubesearch_entrypoint_9(0x154, &props[0], 8);
    data->count = 0;
    for (i = 0; i < count; i++) {
        func_800EE88C(position, props[i]->position);
        index = func_800CBC3C(position);
        if (index != -1) {
            data->entries[data->count].height = position[1];
            data->entries[data->count].speed = func_800DC178(3.0f, 5.0f);
            data->entries[data->count].index = index;
            data->count++;
        }
    }
    data->timer = 6.4f;
}

void func_80800170_chvolcanobits(Actor *arg0) {
    struct VolcanoBitsData {
        s32 unk0;
        f32 points[7][3];
        u8 pad58[8];
        s32 count;
        f32 extra[3];
    };
    s32 i;
    f32 *point;
    struct { s16 index; s16 kind; } entry, extraEntry;
    struct VolcanoBitsData *data;
    void *func_80100094(Actor *, u32);
    s32 func_800D9078(f32 *);
    void func_80108B04(Actor *, u32);
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    s32 func_800EA05C(void);
    s32 _glcutDll_entrypoint_19(s32);
    extern u32 D_80801274_chvolcanobits[5];

    data = func_80100094(arg0, 0);
    i = 0;
    point = data->points[0];
    while (i < data->count) {
        if (func_800D9078(point)) {
            entry.index = i;
            entry.kind = 0;
            func_80108B04(arg0, *(u32 *)&entry);
        }
        i++;
        point += 3;
    }
    _subaddieaudioloop_entrypoint_4(arg0, NULL, 1, D_80801274_chvolcanobits);
    switch (func_800EA05C()) {
    case 0x129:
        if (_glcutDll_entrypoint_19(0x70) && func_800D9078(data->extra)) {
            extraEntry.index = -1;
            extraEntry.kind = 1;
            func_80108B04(arg0, *(u32 *)&extraEntry);
        }
    case 0x133:
        return;
    }
}

s32 func_8080027C_chvolcanobits(Actor *arg0, s32 arg1, s32 arg2) {
    void func_800CD08C(s32, f32 *);
    void func_800CF2D4(s32);
    f32 func_800DC178(f32, f32);
    int func_800DC298(f32);
    s32 func_800EA05C(void);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void *func_80100094(Actor *, u32);
    void func_80102FDC(Actor *, f32);
    Actor *func_80108528(s32, f32 *, s32, Actor **);
    struct Entry {
        s32 id;
        f32 timer;
        f32 height;
    };
    struct Params {
        s16 index;
        s16 mode;
    };
    struct Entry *data;
    Actor *actor;
    f32 pos[3];
    s32 index;

    data = func_80100094(arg0, 0);
    switch (arg1) {
    case 0x3D:
        switch (((struct Params *)&arg2)->mode) {
        case 0:
            index = ((struct Params *)&arg2)->index;
            func_800CD08C(((struct Entry *)((u8 *)data + index * 0xC))->id, pos);
            pos[1] = ((struct Entry *)((u8 *)data + index * 0xC))->height;
            ((struct Entry *)((u8 *)data + index * 0xC))->timer = func_800DC178(3.0f, 5.0f);
            actor = func_80108528(0x425, pos, 0, &arg0);
            func_800EFA4C((f32 *)&actor->actorData[4], func_800DC178(-200.0f, 200.0f), func_800DC178(600.0f, 1200.0f), func_800DC178(-200.0f, 200.0f));
            func_80102FDC(actor, func_800DC178(0.8f, 1.2f));
            actor->unk54 = (func_800DC298(0.5f) ? 1.0f : -1.0f) * func_800DC178(100.0f, 200.0f);
            actor->unk50 = (func_800DC298(0.5f) ? 1.0f : -1.0f) * func_800DC178(60.0f, 120.0f);
            actor->unk64_20 = func_800DC298(0.6f);
            actor->unk58 = func_800DC178(0.8f, 1.2f);
            break;
        case 1:
            func_800EFA4C(pos, 250.0f, -815.0f, -400.0f);
            actor = func_80108528(0x425, pos, 0, &arg0);
            func_800EFA4C((f32 *)&actor->actorData[4], 0.0f, 1200.0f, 0.0f);
            func_80102FDC(actor, func_800DC178(0.8f, 1.2f));
            actor->unk54 = (func_800DC298(0.5f) ? 1.0f : -1.0f) * func_800DC178(100.0f, 200.0f);
            actor->unk50 = (func_800DC298(0.5f) ? 1.0f : -1.0f) * func_800DC178(60.0f, 120.0f);
            actor->unk64_20 = 1;
            actor->unk64_19 = 1;
            actor->unk58 = 2.0f;
            break;
        }
        break;
    case 0x95:
        if (func_800EA05C() == 0x133) {
            func_800CF2D4(5);
            arg0->unk64_20 = 1;
        }
        break;
    default:
        return 0;
    }
    return 1;
}

void func_8080061C_chvolcanobits(u8 *arg0) {
    struct Flags {
        u8 pad[0x64];
        unsigned int : 11;
        unsigned int active : 1;
        unsigned int : 20;
    };
    void func_800CF494(void);
    if (((struct Flags *)arg0)->active) {
        func_800CF494();
        arg0[0x65] &= 0xFFEF;
    }
}

void func_8080065C_chvolcanobits(s32 arg0) 
{
}
void func_80800664_chvolcanobits(Actor *arg0 BT_PASS2(, s32 bt_a1)) {
    void _chexploder_entrypoint_3(void *, void *, u32);
    s32 _chlightfader_entrypoint_1(s32, f32, s32);
    s32 *_fxgenlist_entrypoint_2(void);
    void _subaddieaudioquick_entrypoint_2(Actor *, f32[3], void *);
    s32 func_8001210C(s32);
    f32 func_800136E4(f32);
    BtIntPtr func_800B5BE4(s32);
    BtIntPtr func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    BtIntPtr func_800BBCB8(f32 *, f32 *, f32, s32, s32 *);
    s32 func_800BFA1C();
    void func_800C8E54(s32, f32, f32);
    void func_800C8E84(s32, u32 *);
    f32 func_800D8FF8(void);
    s32 func_800D9078(f32 *);
    void func_800EE7F8(f32 *, f32 *);
    void func_800FFAB0(Actor *);
    void func_80101FDC(Actor *, u32);
    s32 func_8010B990(Actor *, s32);
    void func_80800914_chvolcanobits(Actor *);
    extern s32 D_80801100_chvolcanobits[3];
    extern s32 D_80801288_chvolcanobits[5];
    extern s32 D_8080129C_chvolcanobits[4];
    extern s32 D_808012AC_chvolcanobits[16];
    f32 dt;
    f32 position[3];
    f32 *pos;

    dt = func_800D8FF8();
    arg0->rotation[1] = func_800136E4(arg0->rotation[1] + arg0->unk54 * dt);
    arg0->rotation[0] = func_800136E4(arg0->rotation[0] + arg0->unk50 * dt);
    pos = arg0->position;
    if (arg0->unk70_10 == 1) {
        if (func_800BFA1C(pos) == 0 && ((f32 *)arg0->actorData)[5] < 0.0f) {
            func_800FFAB0(arg0);
            return;
        }
        ((f32 *)arg0->actorData)[5] -= dt * 800.0f;
        func_80800914_chvolcanobits(arg0);
        if ((func_8010B990(arg0, 0x400007) & 0x20) ||
            (arg0->unk64_20 && func_800D9078(&arg0->unk58))) {
            func_800C8E54(arg0->actorData[0], 400.0f, 1000.0f);
            func_800C8E84(arg0->actorData[0], (u32 *)D_80801100_chvolcanobits);
            arg0->actorData[0] = _chlightfader_entrypoint_1(arg0->actorData[0], 1.8f, 2);
            func_800BBCB8(pos, NULL, 1.0f, 1, _fxgenlist_entrypoint_2());
            _subaddieaudioquick_entrypoint_2(arg0, pos,
                arg0->unk64_19 ? D_8080129C_chvolcanobits : D_80801288_chvolcanobits);
            func_800EE7F8(position, pos);
            position[1] -= arg0->scale * 10.0f;
            _chexploder_entrypoint_3(arg0, position, 0x1C);
            func_80101FDC(arg0, 2);
        }
        if (func_8001210C(1) == 0) {
            func_800BABB8(func_800B5BE4(0x18), pos, NULL, 1.0f, D_808012AC_chvolcanobits);
        }
    }
}    typedef struct { u8 pad0[0x18]; s32 unk18; } Objvolcanobits_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_8080086C_chvolcanobits(u8 *arg0) {
    void func_800C8B84(s32);
    s32 temp_a1;

    temp_a1 = (((Objvolcanobits_arg0 *)arg0)->unk18);
    if (temp_a1 != 0) {
        func_800C8B84(temp_a1);
        (((Objvolcanobits_arg0 *)arg0)->unk18) = 0;
    }
}

/* extern */

s32 func_808008A4_chvolcanobits(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _chexploder_entrypoint_6(BtIntPtr, s32, s32);
    void _subaddiefade_entrypoint_3(Actor *);
    Unk80132ED0 *func_80101080(void);
    Actor *func_80106790(Unk80132ED0 *);
    Actor *sp1C;
    Actor *temp_v0;

    if (arg1 == 0x90) {
        temp_v0 = func_80106790(func_80101080());
        sp1C = temp_v0;
        _chexploder_entrypoint_6((BtIntPtr)temp_v0, 0x44960000, 0x44AF0000);
        _subaddiefade_entrypoint_3(sp1C);
        return 1;
    }
    if (arg1 == 0x95) {
        arg0->actorData[0] = 0;
        return 1;
    }
    return 0;
}

void func_80800914_chvolcanobits(Actor *arg0) {
    s32 func_800C8A98(void);
    void func_800C8CB8(s32, f32 *);
    void func_800C8E54(s32, f32, f32);
    void func_800C8E84(s32, u32 *);
    f32 func_800DC178(f32, f32);
    void func_800F2F60(void *, void *, f32);
    extern s32 D_80801100_chvolcanobits[3];
    u32 sp2C[3];
    s32 temp_v0;
    s32 var_a2;

    var_a2 = arg0->actorData[0];
    if (var_a2 == 0) {
        temp_v0 = func_800C8A98();
        arg0->actorData[0] = temp_v0;
        func_800C8E54(temp_v0, 200.0f, 800.0f);
        var_a2 = arg0->actorData[0];
    }
    func_800C8CB8(var_a2, arg0->position);
    func_800F2F60(sp2C, D_80801100_chvolcanobits, func_800DC178(0.8f, 1.0f));
    func_800C8E84(arg0->actorData[0], sp2C);
}    typedef struct { u8 pad0[0x6]; s16 unk6; } Objvolcanobits_func_808009A8_chvolcanobits_sp24; /* offsets.py genstruct: fields from raw offsets on sp24; rename once understood */

/* extern */

void func_808009A8_chvolcanobits(Actor *arg0) {
    s32 _chswitch_entrypoint_7(BtIntPtr, s32);
    void _chswitch_entrypoint_9(void *arg0);
    s32 _subaddiefind_entrypoint_10(Actor *, s32, u32);
    void *func_8080108C_chvolcanobits(void *);
    void *sp24;
    sp24 = func_8080108C_chvolcanobits(arg0);
    _subaddiefind_entrypoint_10(arg0, 0x42A, arg0->unk74_7);
    _chswitch_entrypoint_7((BtIntPtr) arg0, ((Objvolcanobits_func_808009A8_chvolcanobits_sp24 *)sp24)->unk6);
    _chswitch_entrypoint_9((BtIntPtr) arg0);
}

s32 func_80800A04_chvolcanobits(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _chswitch_entrypoint_10(BtIntPtr, s32, s32);
    s32 func_800D1000(s32, s32, s32 *, s32, BtIntPtr);
    void func_800DF744(s32, s32);
    s32 func_8010114C(BtIntPtr, s32, BtIntPtr);
    s32 func_801015D0(Actor *);
    s32 i;
    s32 selected;

    switch (arg1) {
        case 7:
            if (arg0->unk74_7 == 0x37) {
                func_800D1000(0x3E, 1, NULL, 1, 0);
            }
            func_8010114C((BtIntPtr) arg0->unk3C, 0xA, 0);
            break;
        case 31:
            selected = arg0->unk74_7 - 0x32;
            func_801015D0(arg0);
            for (i = 0; i < 6; i++) {
                func_800DF744(i + 1, selected == i);
            }
            break;
        default:
            return _chswitch_entrypoint_10((BtIntPtr) arg0, arg1, arg2);
    }
    return 1;
}

void func_80800AEC_chvolcanobits(Actor *arg0) {
    void func_800EE7F8(f32 dst[3], f32 src[3]);
    void* func_80100094(Actor*, u32);
    func_800EE7F8(func_80100094(arg0, 0U), arg0->position);
}

void func_80800B20_chvolcanobits(Actor *arg0) {
    s32 func_800C2FDC(u8);
    s32 func_800D9078(f32 *);
    s32 func_800DA544(s32);
    void func_800EFE50(f32 *, f32 *, f32 *, f32);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    void func_80101FDC(Actor *, u32);
    void func_80103110(void *, s32);
    Actor *func_80106790(Unk80132ED0 *);
    void func_80800D6C_chvolcanobits(Actor *);
    void func_80801040_chvolcanobits(u8 *);
    void *func_8080108C_chvolcanobits(void *);
    struct { f32 duration; s16 unk4; s16 flag; } *sp2C;
    s32 sp28;

    sp2C = func_8080108C_chvolcanobits(arg0);
    switch (arg0->unk70_10) {
        case 1:
        case 3:
            if (--arg0->unk79_4 == 0) {
                func_80103110(arg0, 0);
            }
            break;
        case 2:
            sp28 = func_800D9078(&arg0->unk58);
            func_800EFE50(arg0->position, (f32 *)&arg0->actorData[4],
                (f32 *)arg0->actorData,
                func_800F12D4(arg0->unk58, 0.0f, sp2C->duration, 1.0f, 0.0f));
            if (arg0->unk3C != NULL) {
                func_80106790(arg0->unk3C)->position[1] = arg0->position[1] + arg0->unk54;
            }
            if (sp28 != 0) {
                func_800DA544(sp2C->flag);
                arg0->unk79_4 = 2;
                func_80101FDC(arg0, 3);
                func_800C2FDC(arg0->unk5F);
                arg0->unk5F = 0;
            } else {
                func_80800D6C_chvolcanobits(arg0);
            }
            break;
    }
    func_80801040_chvolcanobits((u8 *)arg0); BT_NATIVE_ONLY(return 0;)
}    typedef struct { u8 pad0[0x8]; s16 unk8; } Objvolcanobits_func_80800C5C_chvolcanobits_temp_s0; /* offsets.py genstruct: fields from raw offsets on temp_s0; rename once understood */

/* extern */

int func_80800C5C_chvolcanobits(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _capod_entrypoint_13(BtIntPtr, BtIntPtr, s32, s32);
    void func_800187B4(s32, f32, f32, f32);
    void func_800E1378(s32);
    void func_800E13F0(s32, f32);
    void func_800E1410(s32, f32, f32);
    s32 func_800E1540(s32);
    void func_80101FDC(Actor *, u32);
    void func_80103110(void *, s32);
    s32 func_80800EF0_chvolcanobits(void *);
    void *func_8080108C_chvolcanobits(void *);
    s32 sp20[2];
    s32 temp_v0;
    void *temp_s0;

    if (arg1 == 0xA) {
        temp_s0 = func_8080108C_chvolcanobits(arg0);
        temp_v0 = func_800E1540(0);
        sp20[0] = temp_v0;
        func_800E1378(temp_v0);
        func_800E13F0(sp20[0], 5.0f);
        func_800E1410(sp20[0], -5.0f, (*(f32 *)temp_s0) * 0.95f);
        func_800187B4(0, 3.0f, 1.0f, (*(f32 *)temp_s0) * 0.95f);
        func_80101FDC(arg0, 2);
        func_80103110(arg0, 1);
        arg0->unk58 = *(f32 *)temp_s0;
        if (((Objvolcanobits_func_80800C5C_chvolcanobits_temp_s0 *)temp_s0)->unk8 != -1) {
            _capod_entrypoint_13((BtIntPtr)arg0->unk0, 0, ((Objvolcanobits_func_80800C5C_chvolcanobits_temp_s0 *)temp_s0)->unk8, 0x10);
        }
        return 1;
    }
    if (arg1 == 0x95) {
        func_80800EF0_chvolcanobits(arg0);
        return 1;
    }
    return 0;
}

void func_80800D6C_chvolcanobits(Actor *arg0) {
    void _subaddieaudioloop_entrypoint_1(u8 *, s32);
    s32 _subaddieaudioloop_entrypoint_4(Actor *, f32 *, u32, u32 *);
    f32 func_800F12D4(f32, f32, f32, f32, f32);
    void *func_80100094(Actor *, u32);
    void *func_8080108C_chvolcanobits(void *);
    extern u32 D_808012EC_chvolcanobits[5];
    if (_subaddieaudioloop_entrypoint_4(arg0, func_80100094(arg0, 0), 1, D_808012EC_chvolcanobits)) {
        _subaddieaudioloop_entrypoint_1((u8 *)arg0, (s32)func_800F12D4(arg0->unk58, 0.0f, *(f32 *)func_8080108C_chvolcanobits(arg0) * 0.6f, 32767.0f, 22000.0f));
    }
}

/* extern */

void chvolcanobits_entrypoint_4(s32 arg0, s16 *arg1, s16 *arg2, s32 arg3, Unk80132ED0 *arg4) {
    Actor *func_80106790(Unk80132ED0 *);
    Actor *actor;
    s16 *end;
    s32 i;

    actor = func_80106790(arg4);
    end = (s16 *)(arg3 * 16 + (BtUIntPtr)arg2);
    while (arg2 < end) {
        for (i = 0; i < 3; i++) {
            arg2[i] = arg1[i] + actor->position[i];
        }
        arg2 += 8;
        arg1 += 8;
    }
}

s32 func_80800EF0_chvolcanobits(void *arg0) {
    s32 _subaddiefind_entrypoint_10(Actor *, s32, u32);
    s32 func_800DA298(s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EFD24(f32 *);
    void func_800FFAB0(Actor *);
    void func_80101FDC(Actor *, u32);
    void func_80103110(void *, s32);
    Actor *func_80106790(Unk80132ED0 *);
    void func_80801040_chvolcanobits(u8 *);
    void *func_8080108C_chvolcanobits(void *);
    struct { f32 duration; s16 height; s16 flag; } *sp34;
    Actor *sp30;

    sp34 = func_8080108C_chvolcanobits(arg0);
    sp30 = NULL;
    _subaddiefind_entrypoint_10(arg0, 0x429, ((Actor *)arg0)->unk74_7 + 1);
    func_800EFD24(((Actor *)arg0)->position);
    func_800EFD24((f32 *)((Actor *)arg0)->actorData);
    func_800EFD24((f32 *)&((Actor *)arg0)->actorData[4]);
    ((f32 *)((Actor *)arg0)->actorData)[5] -= sp34->height;
    if (((Actor *)arg0)->unk3C != NULL) {
        sp30 = func_80106790(((Actor *)arg0)->unk3C);
    }
    if (sp30 != NULL) {
        ((Actor *)arg0)->unk54 = sp30->position[1] - ((Actor *)arg0)->position[1];
    }
    if (func_800DA298(sp34->flag)) {
        func_800EE7F8(((Actor *)arg0)->position, (f32 *)((Actor *)arg0)->actorData);
        func_80101FDC(arg0, 3);
        func_800FFAB0(arg0);
    } else {
        func_800EE7F8(((Actor *)arg0)->position, (f32 *)&((Actor *)arg0)->actorData[4]);
        func_80101FDC(arg0, 1);
        func_80103110(arg0, 1);
        ((Actor *)arg0)->unk79_4 = 2;
    }
    if (sp30 != NULL) {
        sp30->position[1] = ((Actor *)arg0)->position[1] + ((Actor *)arg0)->unk54;
    }
    ((Actor *)arg0)->unk5F = 0;
    func_80801040_chvolcanobits((u8 *)arg0); BT_NATIVE_ONLY(return 0;)
}

void func_80801040_chvolcanobits(u8 *arg0) {
    s32 _glid_entrypoint_0(BtIntPtr, s32, s32 *, BtIntPtr);
    BtIntPtr func_800BEA88(s32);
#ifndef BT_NATIVE
    extern s32 _chvolcanobits_entrypoint_4;
#endif
    BtIntPtr temp_v0;

    temp_v0 = func_800BEA88(0);
    if (temp_v0 != 0) {
        _glid_entrypoint_0(temp_v0, ((u32) (*(u16 *)((s8 *)(arg0) + (0x76))) >> 7) - 0x31, &_chvolcanobits_entrypoint_4, (*(s32 *)((s8 *)(arg0) + (0))));
    }
}

void *func_8080108C_chvolcanobits(void *arg0) {
    extern s32 D_8080110C_chvolcanobits[18];
    u32 index = *(u16 *)((u8 *)arg0 + 0x76);
    index = (index >> 7) - 0x32;
    return (void *)((u8 *)D_8080110C_chvolcanobits + index * 12);
}
/* data_to_c.py: from asm/data/overlays/ch/volcanobits.data.s */
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
OSThread *func_80108ED0(void);
extern u8 D_8011A270[];
void _chswitch_entrypoint_6();
void func_801018A4();
void func_8010A730();
s32 D_80801100_chvolcanobits[3] BT_DATA(4, overlays_ch_volcanobits, 0x0) = { 255, 255, 255 };
s32 D_8080110C_chvolcanobits[18] BT_DATA(4, overlays_ch_volcanobits, 0xC) = { 1082130432, 39322396, 0, 1084227584, 58983197, 196608, 1084227584, 62259998, 393216, 1077936128, 32768799, 589824, 1084227584, 62260000, 720896, 1084227584, 58983201, 983040 };
ActorData D_80801154_chvolcanobits [1] BT_DATA(4, overlays_ch_volcanobits, 0x54) = { { 822, 1060, 0, 1, 0, (void (*)(struct Actor *))func_80800170_chvolcanobits, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 0, (void (*)(struct Actor *))func_8080061C_chvolcanobits, 0, 104, 0, (void (*)(struct Actor *))func_80800030_chvolcanobits, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1538, (void (*)(struct Actor *, long, long))func_8080027C_chvolcanobits, 0 } };
ActorData D_8080119C_chvolcanobits [1] BT_DATA(4, overlays_ch_volcanobits, 0x9C) = { { 823, 1061, 1979, 1, 0, (void (*)(struct Actor *))func_80800664_chvolcanobits, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 0, (void (*)(struct Actor *))func_8080086C_chvolcanobits, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_8080065C_chvolcanobits, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 17410, (void (*)(struct Actor *, long, long))func_808008A4_chvolcanobits, 0 } };
ActorData D_808011E4_chvolcanobits [1] BT_DATA(4, overlays_ch_volcanobits, 0xE4) = { { 835, 1065, 2373, 1, (void *)D_8011A270, (void (*)(struct Actor *))_chswitch_entrypoint_6, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_801018A4, 0, 0, 0, 0, 16384, 2060, 0, 0, 0, 0, (void (*)(struct Actor *))func_808009A8_chvolcanobits, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32760, 11282, (void (*)(struct Actor *, long, long))func_80800A04_chvolcanobits, 0 } };
ActorData D_8080122C_chvolcanobits [1] BT_DATA(4, overlays_ch_volcanobits, 0x12C) = { { 344, 1066, 0, 1, 0, (void (*)(struct Actor *))func_80800B20_chvolcanobits, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_8010A730, 0, 0, 0, 0, 0, 4, 0, 0, 12, 0, (void (*)(struct Actor *))func_80800AEC_chvolcanobits, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 3586, (void (*)(struct Actor *, long, long))func_80800C5C_chvolcanobits, 0 } };
u32 D_80801274_chvolcanobits[5] BT_DATA(4, overlays_ch_volcanobits, 0x174) = { 0x130483, 0xE0040, 0x590019, 0x180014, 0 };
s32 D_80801288_chvolcanobits[5] BT_DATA(4, overlays_ch_volcanobits, 0x188) = { 1246227, 852108, 10878977, 52432800, 0 };
s32 D_8080129C_chvolcanobits[4] BT_DATA(4, overlays_ch_volcanobits, 0x19C) = { 1246227, 655641, 1572866, 0 };
s32 D_808012AC_chvolcanobits[16] BT_DATA(4, overlays_ch_volcanobits, 0x1AC) = { 1903069, 1446400, 3276802, 1376256, 13369378, 30147072, 4980838, 2818201, 13369371, 19661100, 1572864, 6400, 419430423, 8388640, -8388480, 18481152 };
u32 D_808012EC_chvolcanobits[5] BT_DATA(4, overlays_ch_volcanobits, 0x1EC) = { 0x1304A9, 0x1655F0, 0x20000, 0, 0 };
