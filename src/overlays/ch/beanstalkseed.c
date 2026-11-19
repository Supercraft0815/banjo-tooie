#include "common.h"

/* extern */

typedef struct { BtIntPtr unk0; u8 pad4[0x72]; u16 unk76; } Objbeanstalkseed_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */ void func_80800000_chbeanstalkseed(void *arg0) {
    s32 func_800DA298(s32);
    void func_800FFA88(Unk80132ED0 *marker);
    if (func_800DA298(((u32) (((Objbeanstalkseed_arg0 *)arg0)->unk76) >> 7) + 0x33D) != 0) {
        func_800FFA88((((Objbeanstalkseed_arg0 *)arg0)->unk0));
    }
}
struct Times5 { f32 value[5]; }; struct Times3 { f32 value[3]; };
void func_8080003C_chbeanstalkseed(Actor *arg0) {


    extern struct Times5 D_80800BE0_chbeanstalkseed;
    extern struct Times3 D_80800BF4_chbeanstalkseed;
    s32 func_80101E4C(Actor *, f32 *);
    f32 func_800DC178(f32, f32);
    void func_800C4140(u32, f32 *, u32);
    struct Times5 first = D_80800BE0_chbeanstalkseed;
    struct Times3 second = D_80800BF4_chbeanstalkseed;
    if (func_80101E4C(arg0, first.value)) {
        func_800C4140(((u16)(func_800DC178(0.95f, 1.05f) * 1023.0f) << 21) + 0xDABF0, arg0->position, 0x3E800FA);
    } else if (func_80101E4C(arg0, second.value)) {
        func_800C4140(((u16)(func_800DC178(0.95f, 1.05f) * 1023.0f) << 21) + 0xDACD5, arg0->position, 0x3E800FA);
    }
}

s32 func_8080026C_chbeanstalkseed(u8 *arg0, s32 arg1, s32 arg2)
{
  u32 _subaddiedialog_entrypoint_11(Unk80132ED0* arg0, u32 DialogId, u32 arg2, f32* CameraTarget, s16 arg4);
  void func_800D1844(s32 arg0);
  s32 func_800DA298(s32);
  void func_800DA544(s32 index);
  s32 func_800F5410(BtIntPtr);
  s32 *new_var;
  u32 func_800F54E4(void);
  void func_800FC6B0(u32 track_id);
  void func_800FFA88(Unk80132ED0 *marker);
  if (arg1 == 0x3E)
  {
    new_var = &((Objbeanstalkseed_arg0 *)arg0)->unk0;
    func_800DA544(((((u16) (((Objbeanstalkseed_arg0 *)arg0)->unk76)) & 0xFFFFFFFFu) >> 7) + 0x33D);
    func_800FC6B0(0);
    func_800D1844(0x50);
    if ((func_800DA298(0x6BE) == 0) && (func_800F5410(func_800F54E4()) == 1))
    {
      _subaddiedialog_entrypoint_11(((Objbeanstalkseed_arg0 *)arg0)->unk0, 0x1430, 6, arg0 + 4, 0xC);
      func_800DA544(0x6BE);
    }
    func_800FFA88(*new_var);
    return 1 ^ 0;
  }
  return 0;
}

OSThread *chbeanstalkseed_entrypoint_0(void)
{
    extern ActorData D_80800C00_chbeanstalkseed[];

    return (OSThread *) D_80800C00_chbeanstalkseed;
}

/* extern */

#ifdef BT_NATIVE
s32 func_80800328_chbeanstalkseed(Actor *actor) {
#else
s32 func_80800328_chbeanstalkseed(void) {
#endif
    s32 func_800D1A04(s32);
    u32 func_800F54E4(void);
    s32 func_800F64A4(BtIntPtr, s32);
    s32 func_800F66F0(BtIntPtr);
    s32 func_800F6720(BtIntPtr);
    s32 func_8010C500(BT_NATIVE_ONLY(Actor *));
    if (func_8010C500(BT_NATIVE_ONLY(actor)) == 0) {
        return 0;
    }
    if (func_800D1A04(0x50) == 0) {
        return 0;
    }
    if (func_800F64A4(func_800F54E4(), 0x201) == 0) {
        return 0;
    }
    if (func_800F6720(func_800F54E4()) != 0) {
        return 0;
    }
    if (func_800F66F0(func_800F54E4()) != 0) {
        return 0;
    }
    return 1;
}

void func_808003D8_chbeanstalkseed(Actor *arg0) {
    void _subaddieDll_entrypoint_4(void *arg0, s32 arg1);
    Actor *_subaddiefind_entrypoint_2(s32, BtIntPtr);
    void _subaddieitem_entrypoint_0(BtIntPtr, BtUIntPtr, s32, s32);
    void _subaddieitem_entrypoint_2(BtIntPtr);
    s32 _subaddieitem_entrypoint_3(Actor *, f32 *, void *);
    f32 func_80013970(f32);
    void func_800C3F48(u32);
    s32 func_800D91EC(f32 *, f32);
    s32 func_800F0064(f32 *, f32, f32 *);
    f32 func_800F10B4(f32, f32, f32, f32, f32);
    f32 func_800F13C4(f32, f32);
    u32 func_800F54E4(void);
    void func_800F7F50(BtIntPtr, f32 *, f32 *, f32, s32, s32);
    void func_800FFA88(Unk80132ED0 *marker);
    u32 *func_80100074(Actor *, u32, u32);
    void *func_80100094(Actor *, u32);
    void *func_801000D8(Actor *actor,s32 slot,s32 size);
    void func_80101FDC(Actor *, u32);
    void func_8010C964(Actor *);
    void func_8010D254(f32 *);
    s32 func_80800328_chbeanstalkseed();
    void func_80800804_chbeanstalkseed(Actor *, s32);
    f32 remainder;
    f32 scale;
    s32 i;

    switch ((u32)*(u16 *)((u8 *)arg0 + 0x72) >> 10) {
    case 1: {
        BtIntPtr item;
#ifdef BT_NATIVE
        if (((s32 (*)())func_80800328_chbeanstalkseed)(arg0) != 0) {
#else
        if (func_80800328_chbeanstalkseed(arg0) != 0) {
#endif
            item = func_801000D8(arg0, 1, 0x14);
            _subaddieitem_entrypoint_0(item, 0x481, 1000, 0);
            _subaddieitem_entrypoint_2(item);
            func_80101FDC(arg0, 2);
        }
        return;
    }
    case 2: {
        Actor *seed;
        if (_subaddieitem_entrypoint_3(arg0, (f32 *)((u8 *)arg0 + 4), func_80100094(arg0, 1)) != 0) {
            seed = _subaddiefind_entrypoint_2(0x481, 0);
            if (seed != NULL) {
                *(f32 *)((u8 *)arg0 + 0x48) = *(f32 *)((u8 *)seed + 0x48);
                func_800FFA88(*(s32 *)seed);
            }
            func_80800804_chbeanstalkseed(arg0, 3);
            func_80100074(arg0, 1, 0);
        }
        break;
    }
    case 3:
        func_8010C964(arg0);
        return;
    case 4: {
        f32 phase;
        if (func_800D91EC((f32 *)((u8 *)arg0 + 0x58), 6.0f) != 0) {
            func_80800804_chbeanstalkseed(arg0, 5);
            return;
        }
        scale = 0.00001f;
        for (i = 0; i < 8; i++) {
            if (*(f32 *)((u8 *)arg0 + 0x58) < 0.75f * (f32)i) {
                continue;
            }
            if (0.75f * (f32)(i + 1) < *(f32 *)((u8 *)arg0 + 0x58)) {
                scale += 0.125f;
            } else {
                phase = func_800F13C4(*(f32 *)((u8 *)arg0 + 0x58), 0.75f);
                scale += func_80013970(func_800F10B4(phase, 0.0f, 0.75f, 0.0f, 90.0f)) * 0.125f;
            }
        }
        *(f32 *)((u8 *)arg0 + 0x24) = *(f32 *)((u8 *)arg0 + 0x54);
        *(f32 *)((u8 *)arg0 + 0x54) = scale;
        *(f32 *)((u8 *)arg0 + 0x38) = func_800F10B4(*(f32 *)((u8 *)arg0 + 0x58), 0.0f, 6.0f, 0.0f, 1.0f) * scale;
        remainder = func_800F13C4(*(f32 *)((u8 *)arg0 + 0x24), 0.125f);
        if (func_800F13C4(*(f32 *)((u8 *)arg0 + 0x54), 0.125f) < remainder) {
            if (*(f32 *)((u8 *)arg0 + 0x58) < 5.8f) {
                func_800C3F48(((u16)(func_800F10B4(*(f32 *)((u8 *)arg0 + 0x58), 0.0f, 6.0f, 0.5f, 1.0f) * 1023.0f) << 21) + 0x1B5C1D);
                return;
            }
        }
        break;
    }
    case 5: {
        f32 position[3];
        func_8010D254(position);
        if (func_800F0064(position, *(f32 *)((u8 *)arg0 + 0x38) * 150.0f, (f32 *)((u8 *)arg0 + 4)) != 0 &&
            *(f32 *)((u8 *)arg0 + 8) < position[1] && position[1] <= *(f32 *)((u8 *)arg0 + 0x2C)) {
            _subaddieDll_entrypoint_4(arg0, 1);
            remainder = *(f32 *)((u8 *)arg0 + 0x38) * func_800F10B4(position[1], *(f32 *)((u8 *)arg0 + 8), *(f32 *)((u8 *)arg0 + 0x2C), 100.0f, 75.0f);
            func_800F7F50(func_800F54E4(), (f32 *)((u8 *)arg0 + 4), (f32 *)((u8 *)arg0 + 0x28), remainder, 1, 1);
            return;
        }
        _subaddieDll_entrypoint_4(arg0, 0);
        break;
    }
    }
}

void func_80800804_chbeanstalkseed(Actor *arg0, s32 arg1) {
    s32 _capod_entrypoint_13(BtIntPtr arg0, BtIntPtr arg1, s32 arg2, s32 arg3);
    void _subaddieDll_entrypoint_4(void *arg0, s32 arg1);
    void func_800C3F48(u32);
    void func_800DA544(s32 index);
    void func_80102424(Actor *, s32);
    s32 func_80103140(Actor *, u32, u16);
    void func_8010A63C(Actor *);

    switch (arg1) {
    case 1:
        arg0->unk64_16 = 0;
        break;
    case 3:
        arg0->unk64_16 = 1;
        func_80103140(arg0, 0x8CF, arg0->unk0->unk16);
        func_800DA544(arg0->unk74_7 + 0x323);
        break;
    case 4:
        _subaddieDll_entrypoint_4(arg0, 1);
        func_80103140(arg0, 0x8DD, arg0->unk0->unk16);
        arg0->unk58 = 0.0f;
        arg0->scale = 0.01f;
        _capod_entrypoint_13(arg0->unk0, NULL, arg0->unk74_7 * 2 - 0x58, 0x6810);
        arg0->unk54 = 1.0f;
        func_800C3F48(0x3FFB5C1D);
        break;
    case 5:
        func_800DA544(arg0->unk74_7 + 0x325);
        _subaddieDll_entrypoint_4(arg0, 0);
        arg0->scale = 1.0f;
        func_8010A63C(arg0);
        break;
    }
    func_80102424(arg0, arg1);
}
struct Rotation { f32 v[3]; };
void func_80800950_chbeanstalkseed(Actor *arg0, void *arg1) {
    BtIntPtr func_800D674C(s32);
    void *func_800DE498(void *, f32 *, f32 *, f32, f32 *, BtIntPtr);
    void func_800DF830(s32);
    void func_80101870(Actor *, void *);

    extern struct Rotation D_80800C48_chbeanstalkseed;
    struct Rotation rotation;

    switch (arg0->unk70_10) {
    case 1:
    case 2:
        break;
    case 4:
        func_80101870(arg0, arg1);
        if (arg0->unk7C_12) {
            rotation = D_80800C48_chbeanstalkseed;
            func_800DF830(1);
            func_800DE498(arg1, arg0->position, rotation.v, 1.0f, NULL, func_800D674C(0x8CF));
        }
        break;
    default:
        func_80101870(arg0, arg1);
        break;
    }
}

s32 func_80800A0C_chbeanstalkseed(Actor *arg0, s32 arg1, s32 arg2) {
    s32 _capod_entrypoint_14(void);
    s32 func_800DA298(s32);
    void func_800EE7F8(f32 *, f32 *);
    s32 func_80101180(s32, s32, BtIntPtr);
    s32 seed;

    switch (arg1) {
    case 0xB:
        _capod_entrypoint_14();
        func_80101180(0x40E, 0x4C, 0);
        return 4;
    case 0x4B:
        if (arg0->unk70_10 == 3) {
            func_80800804_chbeanstalkseed(arg0, 4);
            return 1;
        }
        return 0;
    case 0x95:
        func_800EE7F8((f32 *)&arg0->actorData[4], arg0->position);
        ((f32 *)arg0->actorData)[5] += 2412.0f * arg0->scale * 0.8f;
        seed = arg0->unk74_7;
        if (seed >= 0x33 || seed < 0x35) {
            if (func_800DA298(seed + 0x325)) {
                func_80800804_chbeanstalkseed(arg0, 5);
                return 1;
            }
            if (func_800DA298(arg0->unk74_7 + 0x323)) {
                func_80800804_chbeanstalkseed(arg0, 3);
                return 1;
            }
            func_80800804_chbeanstalkseed(arg0, 1);
        }
        return 1;
    default:
        return 0;
    }
}

OSThread *chbeanstalkseed_entrypoint_1(void)
{
    extern ActorData D_80800C54_chbeanstalkseed[];

    return (OSThread *) D_80800C54_chbeanstalkseed;
}
/* data_to_c.py: from asm/data/overlays/ch/beanstalkseed.data.s */
extern u8 D_80800BD0_chbeanstalkseed[];
void func_80105834(Actor*);
void func_80101870 ( Actor * , void * );
void func_80108ED0();
void func_80107C2C();
u8 D_80800BD0_chbeanstalkseed[16] BT_DATA(4, overlays_ch_beanstalkseed, 0x0) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x7B, 0x85, 0x1F, 0x01, 0xFC, 0x00, 0x01 };
struct Times5 D_80800BE0_chbeanstalkseed BT_DATA(4, overlays_ch_beanstalkseed, 0x10) = { { 0.07f, 0.2f, 0.57f, 0.7f, -1.0f } };
struct Times3 D_80800BF4_chbeanstalkseed BT_DATA(4, overlays_ch_beanstalkseed, 0x24) = { { 0.37f, 0.87f, -1.0f } };
ActorData D_80800C00_chbeanstalkseed [1] BT_DATA(4, overlays_ch_beanstalkseed, 0x30) = { { 295, 1037, 2255, 1, (void *)D_80800BD0_chbeanstalkseed, (void (*)(struct Actor *))func_8080003C_chbeanstalkseed, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 65536000, 0, 0, 0, 128, 0, 0, (BtIntPtr)func_80108ED0, 0, 0, (void (*)(struct Actor *))func_80800000_chbeanstalkseed, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 9216, (void (*)(struct Actor *, long, long))func_8080026C_chbeanstalkseed, 0 } };
struct Rotation D_80800C48_chbeanstalkseed BT_DATA(4, overlays_ch_beanstalkseed, 0x78) = { { 0.0f, 0.0f, 0.0f } };
ActorData D_80800C54_chbeanstalkseed [1] BT_DATA(4, overlays_ch_beanstalkseed, 0x84) = { { 344, 1152, 2269, 1, 0, (void (*)(struct Actor *))func_808003D8_chbeanstalkseed, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80800950_chbeanstalkseed, 131072000, 0, 0, 0, 2, 1057, 0, (BtIntPtr)func_80108ED0, 0, 0, 0, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32736, 9218, (void (*)(struct Actor *, long, long))func_80800A0C_chbeanstalkseed, 0 } };
