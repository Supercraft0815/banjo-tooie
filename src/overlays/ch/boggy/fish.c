#include "common.h"

/* extern */

typedef struct { u8 pad0[0x24]; u32 unk24; } Objfish_arg1; /* offsets.py genstruct: fields from raw offsets on arg1; rename once understood */ void func_80800000_chboggyfish(s32 *arg0, void *arg1) {
    void func_800D1844(s32 arg0);
    void func_800DA544(s32 index);
    u32 func_800F54E4(void);
    void func_800F6388(BtIntPtr arg0, s32 arg1);
    void func_800FC6B0(u32 track_id);
    void func_800FFA88(Unk80132ED0 *marker);
    if (((u32) (((Objfish_arg1 *)arg1)->unk24) >> 0x16) == 0) {
        func_800F6388(func_800F54E4(), 0x4BA);
        func_800D1844(0x51);
        func_800FC6B0(0xE);
        func_800DA544(0x438);
        func_800FFA88(*arg0);
    }
}

s32 func_80800064_chboggyfish(Actor *arg0, s32 arg1, void *volatile arg2) {
    BT_IDO_ONLY(u8 func_800D731C(s32);) BT_NATIVE_ONLY(s32 func_800D731C(s32);)
    s32 func_800DA298(s32);
    s32 func_800DBE60(u8, s32, s32);
    void func_800FFAB0(Actor *);
    s32 func_801015D0(Actor *);
    s32 _glcutDll_entrypoint_20();
    u8 index;
    s32 value;

    switch (arg1) {
        case 0x3E:
            func_80800000_chboggyfish((s32 *)arg0, arg2);
            break;
        case 0x1F:
            func_801015D0(arg0);
            if (index = func_800D731C(arg0->unk0->unk14)) {
                value = (s32)((f32 *)arg0->actorData)[4];
                func_800DBE60(index, 0, value);
                func_800DBE60(index, 1, value);
                func_800DBE60(index, 2, value);
                func_800DBE60(index, 3, value);
            }
            break;
        case 0x95:
            if (func_800DA298(0x438) && !_glcutDll_entrypoint_20()) {
                func_800FFAB0(arg0);
                return 0;
            }
            ((f32 *)arg0->actorData)[4] = 0.0f;
            ((f32 *)arg0->actorData)[5] = 0.5f;
            break;
        default:
            return 0;
    }
    return 1;
}                  typedef struct { u8 pad0[0x28]; f32 unk28; f32 unk2C; } Objfish_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void func_8080018C_chboggyfish(void *arg0) {
    (((Objfish_arg0 *)arg0)->unk28) += (((Objfish_arg0 *)arg0)->unk2C);
    if ((((Objfish_arg0 *)arg0)->unk28) <= 0.0f) {
        (((Objfish_arg0 *)arg0)->unk28) = 0.0f;
        (((Objfish_arg0 *)arg0)->unk2C) = (f32) (0.0f - (((Objfish_arg0 *)arg0)->unk2C));
    }
    if ((((Objfish_arg0 *)arg0)->unk28) >= 4.0f) {
        (((Objfish_arg0 *)arg0)->unk28) = 4.0f;
        (((Objfish_arg0 *)arg0)->unk2C) = (f32) (0.0f - (((Objfish_arg0 *)arg0)->unk2C));
    }
}

OSThread *chboggyfish_entrypoint_0(void)
{
    extern ActorData D_80800220_chboggyfish[];

    return (OSThread *) D_80800220_chboggyfish;
}
/* data_to_c.py: from asm/data/overlays/ch/boggy/fish.data.s */
extern u8 D_80800210_chboggyfish[];
void func_80105834(Actor*);
void func_801018A4();
OSThread *func_80108ED0(void);
void func_80107C2C();
u8 D_80800210_chboggyfish[16] BT_DATA(4, overlays_ch_boggy_fish, 0x0) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x99, 0x99, 0x9A, 0x04, 0x44, 0x00, 0x49 };
ActorData D_80800220_chboggyfish [1] BT_DATA(4, overlays_ch_boggy_fish, 0x10) = { { 890, 1210, 2298, 1, (void *)D_80800210_chboggyfish, (void (*)(struct Actor *))func_8080018C_chboggyfish, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_801018A4, 0, 0, 0, 0, 0, 0, 0, (BtIntPtr)func_80108ED0, 0, 20, 0, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32704, 21508, (void (*)(struct Actor *, long, long))func_80800064_chboggyfish, 0 } };
