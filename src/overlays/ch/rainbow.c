#include "common.h"
#ifdef BT_NATIVE
#include "core2/particle_script.h"
#endif

/* extern */

void func_80800000_chrainbow(s32 arg0) {
    s32 func_800DA298(s32);
    s32 func_80800270_chrainbow(BtIntPtr, s32);

    func_80800270_chrainbow(arg0, func_800DA298(0x1E1) ? 0xD : 1);
}

void func_8080003C_chrainbow(Actor *arg0) {
    void _glid_entrypoint_0(u8 *arg0, s32 arg1, s32 (*arg2)(s16, u8 *, u8 *, s16, s32), BtIntPtr arg3);
    int func_800D91EC(f32 *, f32);
    s32 func_800DA298(s32);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void func_80103110(void *, s32);
    BtIntPtr func_801065A4(void *);
    s32 func_80800270_chrainbow(BtIntPtr, s32);
    void func_80800838_chrainbow(Actor *);
    void _chrainbow_entrypoint_0(s32, Vtx *, Vtx *, s32, Unk80132ED0 *);

    switch (arg0->unk70_10) {
    case 1:
        if (func_801065A4(arg0)) {
            func_80103110(arg0, 0);
        }
        break;
    case 2:
        if (func_800DA298(0x9DE)) {
            func_80800270_chrainbow((BtIntPtr)arg0, 3);
        }
        break;
    case 3:
        if (func_800D91EC(&arg0->unk58, 5.0f)) {
            func_80800270_chrainbow((BtIntPtr)arg0, 4);
        }
        break;
    case 4:
        if (func_800D91EC(&arg0->unk58, 6.5f)) {
            func_80800270_chrainbow((BtIntPtr)arg0, 5);
        }
        ((f32 *)arg0->actorData)[7] = func_800F10B4(arg0->unk58, 5.0f, 6.5f, 0.0f, 1.0f);
        break;
    case 5:
        if (func_800D91EC(&arg0->unk58, 10.5f)) {
            func_80800270_chrainbow((BtIntPtr)arg0, 6);
        }
        break;
    case 6:
        if (func_800D91EC(&arg0->unk58, 13.5f)) {
            func_80800270_chrainbow((BtIntPtr)arg0, 7);
        }
        break;
    case 8:
        if (func_800D91EC(&arg0->unk58, 18.5f)) {
            func_80800270_chrainbow((BtIntPtr)arg0, 9);
        }
        break;
    case 12:
        if (func_800D91EC(&arg0->unk58, 20.5f)) {
            func_80800270_chrainbow((BtIntPtr)arg0, 13);
        }
        ((f32 *)arg0->actorData)[7] = func_800F10B4(arg0->unk58, 18.5f, 20.5f, 1.0f, 0.0f);
        break;
    case 13:
        if (func_801065A4(arg0) && !arg0->unk64_20) {
            arg0->unk64_20 = 1;
            _glid_entrypoint_0(func_801065A4(arg0), 1, &_chrainbow_entrypoint_0, (BtIntPtr)arg0->unk0);
        }
        break;
    }
    func_80800838_chrainbow(arg0);
    if (func_801065A4(arg0)) {
        _glid_entrypoint_0(func_801065A4(arg0), 1, _chrainbow_entrypoint_0, (BtIntPtr)arg0->unk0);
    }
}

s32 func_80800270_chrainbow(BtIntPtr actor, s32 arg1) {
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    void _chglowbo_entrypoint_6(void);
    void _fxrain_entrypoint_7(BtIntPtr arg0);
    void _fxrain_entrypoint_8(u8 *arg0);
    void _subaddieDll_entrypoint_0(void *arg0);
    BtIntPtr func_800B7C54(void);
    void func_800DA524(s32 index);
    void func_800DA544(s32 index);
    u32 *func_80100074(Actor *, u32, u32);
    s32 func_80101180(s32, s32, BtIntPtr);
    void func_80101FDC(Actor *, u32);
    void func_80103110(void *, s32);
    void func_8010A63C(Actor *);
    void func_80800440_chrainbow(Actor *);
    Actor *arg0 = (Actor *)actor;

    switch (arg1) {
    case 1:
        func_80103110(arg0, 0);
        arg0->unk64_20 = 0;
        arg0->unk64_16 = 0;
        arg0->unk58 = 0.0f;
        ((f32 *)arg0->actorData)[7] = 0.0f;
        break;
    case 2:
        func_80800440_chrainbow(arg0);
        func_800DA524(0x9DF);
        break;
    case 3:
        func_80101180(0x2B0, 0xBB, 0xC);
        _capod_entrypoint_13(arg0->unk0, arg0->unk0, 9, 0x810);
        arg0->unk58 = 0.0f;
        break;
    case 4:
        _fxrain_entrypoint_7(func_800B7C54());
        _chglowbo_entrypoint_6();
        func_800DA544(0x580);
        break;
    case 8:
        arg0->unk64_16 = 1;
        ((f32 *)arg0->actorData)[7] = 1.0f;
        _capod_entrypoint_13(arg0->unk0, arg0->unk0, 0xC, 0x4810);
        _subaddieDll_entrypoint_0(arg0);
        break;
    case 12:
        arg0->unk58 = 18.5f;
        _capod_entrypoint_13(arg0->unk0, arg0->unk0, 0x5A, 0x2810);
        break;
    case 13:
        _fxrain_entrypoint_8(func_800B7C54());
        func_800DA524(0x9DE);
        func_800DA544(0x9DF);
        func_800DA544(0x1E1);
        func_80100074(arg0, 0, 0);
        _subaddieDll_entrypoint_0(arg0);
        func_8010A63C(arg0);
        arg0->unk64_20 = 0;
        ((f32 *)arg0->actorData)[7] = 0.0f;
        arg0->unk58 = 20.5f;
        func_80103110(arg0, 0);
        break;
    }
    func_80101FDC(arg0, arg1); BT_NATIVE_ONLY(return 0;)
}

void func_80800440_chrainbow(Actor *arg0) {
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EEC70(void *, f32, f32, f32);
    void func_800EFD24(f32 *);
    u32 *func_80100074(Actor *, u32, u32);
    f32 func_80103EAC(Actor *);
    f32 func_80103EF4(Actor *);
    struct RainbowPart {
        s8 active;
        f32 value;
        f32 velocity[3];
        f32 position[3];
    };
    struct RainbowPart *part;
    s32 i;
    f32 offset[3];
    f32 position[3];

    part = (struct RainbowPart *)func_80100074(arg0, 0, 0xC0);
    for (i = 0; i < 6; i++) {
        part[i].active = 1;
        func_800EFD24(part[i].velocity);
        part[i].value = 0.0f;
        func_800EEC70(offset, arg0->rotation[0], arg0->rotation[1] - 90.0f, func_80103EAC(arg0));
        position[0] = arg0->position[0] + offset[0];
        position[1] = arg0->position[1] - func_80103EF4(arg0);
        position[2] = arg0->position[2] + offset[2];
        func_800EEC70(offset, arg0->rotation[0], arg0->rotation[1] - 180.0f, arg0->scale * 800.0f * ((f32)i / 5.0f));
        func_800EE780(part[i].position, position, offset);
    }
}

void func_808005E0_chrainbow(BtIntPtr arg0, s32 arg1) {
    BtIntPtr func_800B53A4(s32);
    BT_IDO_ONLY(s32 func_800BA3FC(BtIntPtr, s32);) BT_NATIVE_ONLY(void func_800BA3FC(BtIntPtr, s32);)
    BT_IDO_ONLY(BtIntPtr func_800BABB8(BtIntPtr, BtIntPtr, BtIntPtr, s32, s32 *);)
    extern s32 D_80800FD0_chrainbow[13];
    BtIntPtr sp24;
    BtIntPtr temp_v0;

    temp_v0 = func_800B53A4(1);
    sp24 = temp_v0;
    func_800BA3FC(temp_v0, arg1 + 0x9DF);
    func_800BABB8(sp24, BT_NATIVE_ONLY((f32 *))(arg0), 0, BT_DATA_FIELD(1.0f, 0x3F800000), BT_NATIVE_ONLY((s16 *))D_80800FD0_chrainbow);
}

void func_8080063C_chrainbow(Actor *arg0, f32 arg1, s32 arg2) {
    f32 func_800138D0(f32);
    f32 func_800DC0C0(void);
    s32 func_800DC128(s32, s32);
    void func_800EEC70(void *, f32, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    f32 func_800F1214(f32, f32, f32);
    f32 func_80103EAC(Actor *);
    f32 func_80103EF4(Actor *);
    f32 offset[3];
    f32 position[3];
    f32 result[3];
    f32 t;
    f32 *resultPtr;
    s32 color;
    s32 i;

    resultPtr = result;
    i = 0;
    if (arg2 > 0) {
        do {
            t = func_800F1214(func_800DC0C0(), 1.0f, arg1);
            color = func_800DC128(0, 6);
            func_800EEC70(offset, arg0->rotation[0], arg0->rotation[1] - 90.0f, func_80103EAC(arg0));
            position[0] = arg0->position[0] + func_800F1214(t, -offset[0], offset[0]);
            position[1] = (arg0->position[1] - func_80103EF4(arg0)) + func_800138D0(func_800F1214(t, 90.0f, 270.0f)) * -func_80103EF4(arg0);
            position[2] = arg0->position[2] + func_800F1214(t, -offset[2], offset[2]);
            func_800EEC70(resultPtr, arg0->rotation[0], arg0->rotation[1] - 180.0f, arg0->scale * 800.0f * ((f32)color / 5.0f));
            func_800EF04C(resultPtr, position);
            func_808005E0_chrainbow((BtIntPtr)resultPtr, color);
            i++;
        } while (i != arg2);
    }
}

void func_80800838_chrainbow(Actor *arg0) {
    void func_800EE7F8(f32 *, f32 *);
    void func_800EEB9C(f32 *, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    f32 (*data)[8];
    s32 i;
    f32 offset[3];
    f32 t;
    f32 height;
    f32 angle;
    f32 offset2[3];
    f32 t2;
    f32 height2;
    f32 distance2;
    f32 angle2;
    f32 (*entry)[8];
    f32 *position;

    data = func_80100094(arg0, 0);
    switch (arg0->unk70_10) {
    case 3:
    case 4:
    case 5:
        {
            t = func_800F10B4(arg0->unk58, 0.0f, 10.5f, 0.0f, 1.0f);
            height = func_800F10B4(arg0->unk58, 0.0f, 5.0f, 0.0f, 200.0f);
            angle = func_800F10B4(arg0->unk58, 0.0f, 10.5f, 360.0f, 720.0f);
            for (i = 0, entry = data, position = &data[0][2]; i != 6; i++, entry++, position += 8) {
                func_800EE7F8(position, func_80106790(arg0->unk3C)->position);
                func_800EEB9C(offset, 2.0f * (t * angle) + (f32)i * 60.0f, 100.0f);
                func_800EF04C(position, offset);
                (*entry)[3] += height;
                func_808005E0_chrainbow((BtIntPtr)position, i);
            }
        }
        break;
    case 6:
        {
            t2 = func_800F10B4(arg0->unk58, 10.5f, 13.5f, 0.0f, 1.0f);
            height2 = t2 * 1000.0f + 200.0f;
            distance2 = t2 * 1000.0f + 100.0f;
            angle2 = 2.0f * (t2 * 720.0f);
            for (i = 0, entry = data, position = &data[0][2]; i != 6; i++, entry++, position += 8) {
                func_800EE7F8(position, func_80106790(arg0->unk3C)->position);
                t2 = (f32)i * 60.0f;
                func_800EEB9C(offset2, angle2 + t2, distance2);
                func_800EF04C(position, offset2);
                (*entry)[3] += height2;
                func_808005E0_chrainbow((BtIntPtr)position, i);
            }
        }
        break;
    case 8:
        func_8080063C_chrainbow(arg0, 0.0f, 4);
        break;
    }
}

/* extern */

void chrainbow_entrypoint_0(s32 arg0, Vtx *arg1, Vtx *arg2, s32 arg3, Unk80132ED0 *arg4) {
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    Actor *func_80106790(Unk80132ED0 *);
    f32 x;
    f32 lower;
    f32 upper;
    Vtx *end;
    Actor *actor;

    actor = func_80106790(arg4);
    upper = func_800F10B4(actor->unk58, 13.5f, 18.0f, -3200.0f, 3200.0f);
    lower = func_800F10B4(actor->unk58, 14.0f, 18.5f, -3200.0f, 3200.0f);
    end = arg2 + arg3;
    if (arg2 < end) {
        do {
        x = arg1->v.ob[0];
        if (x < lower) {
            arg2->v.cn[3] = arg1->v.cn[3];
        } else if (x < upper) {
            arg2->v.cn[3] = (u32)func_800F10B4(x, lower, upper, arg1->v.cn[3], 0.0f);
        } else {
            arg2->v.cn[3] = 0;
        }
        arg2++;
        arg1++;
        } while (arg2 < end);
    }
}

void func_80800CD4_chrainbow(BtIntPtr arg0) {
    s32 _subaddiefind_entrypoint_4(s32, u8 **, s32);
    s32 func_8010114C(BtIntPtr, s32, BtIntPtr);
    s32 func_80800270_chrainbow(BtIntPtr, s32);
    u8 *actors[3];
    s32 found;
    s32 index;

    index = _subaddiefind_entrypoint_4(0x480, &actors[0], 3) - 1;
    found = 0;
    for (; index >= 0; index--) {
        if (func_8010114C((BtIntPtr)((Actor *)actors[index])->unk0, 0x4B, 0) != 0) {
            found = 1;
            break;
        }
    }
    if (found != 0) {
        func_80800270_chrainbow(arg0, 0xB);
        return;
    }
    func_80800270_chrainbow(arg0, 0xC);
}

s32 func_80800D88_chrainbow(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _capod_entrypoint_14(void);
    void _subaddieDll_entrypoint_4(void *arg0, s32 arg1);
    Actor *_subaddiefind_entrypoint_2(s32, BtIntPtr);
    s32 func_800DA298(s32);
    void func_80103110(void *, s32);
    Actor *actor;

    switch (arg1) {
    case 0xB:
        _capod_entrypoint_14();
        if (arg2 == 9) {
            if (func_800DA298(0x1E1) != 0) {
                func_80800CD4_chrainbow((BtIntPtr)arg0);
                return 4;
            }
            func_80800270_chrainbow((BtIntPtr)arg0, 8);
            return 4;
        }
        if (arg2 == 0xC) {
            func_80800CD4_chrainbow((BtIntPtr)arg0);
        }
        return 4;
    case 0x4B:
        if (arg2 == 0xC) {
            func_80800270_chrainbow((BtIntPtr)arg0, 2);
            _subaddieDll_entrypoint_4(arg0, 1);
            func_80103110(arg0, 1);
            return 1;
        }
        return 0;
    case 0x4C:
        func_80800CD4_chrainbow((BtIntPtr)arg0);
        return 1;
    case 0x95:
        actor = _subaddiefind_entrypoint_2(0x2B0, 0);
        if (actor != NULL) {
            arg0->unk3C = actor->unk0;
        }
        return 1;
    default:
        return 0;
    }
}
struct RainbowValues { s32 values[3]; };
void func_80800EB4_chrainbow(Actor *arg0, void *arg1) {
    void func_800B99CC(BtIntPtr, s32, BtIntPtr);
    f32 func_800F1214(f32, f32, f32);
    void func_80101870(Actor *, void *);
    struct RainbowValues sp24;
    extern struct RainbowValues D_80801004_chrainbow;
    u32 temp_t6;

    func_80101870(arg0, arg1);
    temp_t6 = arg0->unk70_10;
    if ((temp_t6 != 1) && (temp_t6 != 0xD)) {
        sp24 = D_80801004_chrainbow;
        func_800B99CC((BtIntPtr)arg1, (s32)func_800F1214(*(f32 *)&arg0->actorData[7], 0.0f, 100.0f), (BtIntPtr)&sp24);
    }
}

OSThread *chrainbow_entrypoint_1(void)
{
    extern ActorData D_80801010_chrainbow[];

    return (OSThread *) D_80801010_chrainbow;
}
/* data_to_c.py: from asm/data/overlays/ch/rainbow.data.s */
void func_80105834(Actor*);
void func_80108ED0();
void func_80107C2C();
s32 D_80800FD0_chrainbow[13] BT_DATA(4, overlays_ch_rainbow, 0x0) = { 1446404, 1834608, -39321566, 3342412, 0, 1376256, 10027051, 4980889, 3080320, 8388608, 3342387, 192, 18481152 };
struct RainbowValues D_80801004_chrainbow BT_DATA(4, overlays_ch_rainbow, 0x34) = { { 0, 0, 0 } };
ActorData D_80801010_chrainbow [1] BT_DATA(4, overlays_ch_rainbow, 0x40) = { { 357, 1038, 2254, 1, 0, (void (*)(struct Actor *))func_8080003C_chrainbow, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80800EB4_chrainbow, 20000, 0, 0, 0, 2, 4096, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_80800000_chrainbow, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1026, (void (*)(struct Actor *, long, long))func_80800D88_chrainbow, 0 } };
