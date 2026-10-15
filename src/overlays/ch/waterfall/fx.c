#include "common.h"

OSThread *chwaterfallfx_entrypoint_0(void)
{
    extern u8 D_80800410_chwaterfallfx[];

    return (OSThread *) D_80800410_chwaterfallfx;
}

typedef struct WaterfallFxActor {
    Unk80132ED0 *unk0;
    f32 position[3];
    u32 *pointerToSyscallEntry;
    u32 unk14;
    struct {
        f32 start[3];
        s32 count;
        f32 end[3];
        f32 length;
    } data;
    f32 scale;
    Unk80132ED0 *unk3C;
    s32 pad40;
    f32 rotation[3];
    f32 unk50;
    s32 unk54;
    f32 unk58;
    u8 pad5C[8];
    u32 pad64_21 : 11;
    u32 unk64_20 : 1;
    u32 pad64_0 : 20;
    s32 pad68;
    s32 pad6C;
    union {
        u32 value;
        struct {
            u32 pad : 31;
            u32 active : 1;
        } bits;
    } unk70;
    u32 pad74_16 : 16;
    u32 unk74_7 : 9;
    u32 pad74_0 : 7;
} WaterfallFxActor;

void func_8080000C_chwaterfallfx(Actor *arg0) {
    void func_800EE780(f32 *, f32 *, f32 *);
    void func_800EE8E8(f32 *, f32 *);
    f32 func_800EEAD4(f32 *, f32 *);
    void func_800EF334(f32 *, f32);
    void func_800EFB24(void *, void *, void *);
    void func_800F22B4(void *, f32);
    void func_800F23AC(void *, void *);
    struct WaterfallData {
        f32 start[3];
        s32 count;
        f32 end[3];
        f32 length;
    };
    f32 sp48[2];
    f32 sp40[2];
    f32 sp34[3];
    f32 distance;

    func_800F22B4(sp48, arg0->rotation[1]);
    func_800F23AC(sp40, sp48);
    func_800EE8E8(sp34, sp40);
    func_800EF334(sp34, arg0->unk74_7);
    func_800EE780(((struct WaterfallData *)arg0->actorData)->end, arg0->position, sp34);
    func_800EFB24(((struct WaterfallData *)arg0->actorData)->start, arg0->position, sp34);
    distance = func_800EEAD4(((struct WaterfallData *)arg0->actorData)->end, ((struct WaterfallData *)arg0->actorData)->start);
    ((struct WaterfallData *)arg0->actorData)->length = 0.6f * distance;
    *(s32 *)&arg0->unk54 = 0;
    arg0->unk64_20 = ((WaterfallFxActor *)arg0)->unk70.value & 1;
    ((WaterfallFxActor *)arg0)->unk70.bits.active = 0;
    ((struct WaterfallData *)arg0->actorData)->count = (s32)(distance / 25.0f + 8.0f);
    arg0->unk58 = 0.0f;
    arg0->unk50 = ((struct WaterfallData *)arg0->actorData)->count * 1.5f;
}

void func_80800148_chwaterfallfx(Actor *arg0) {
    s32 _subaddieaudioloop_entrypoint_5(s32, s32, s32, s32, s32 *);
    void func_800C3058(u8, s32);
    s32 func_808001F8_chwaterfallfx(Actor *);
    extern s32 D_80800458_chwaterfallfx;
    u8 temp_a0;

    _subaddieaudioloop_entrypoint_5((s32)arg0, (s32)arg0->position, 1, 0xC80, &D_80800458_chwaterfallfx);
    temp_a0 = arg0->unk5F;
    if (temp_a0 != 0) {
        if (!arg0->unk64_19) {
            func_800C3058(temp_a0, 0x2AF8);
            arg0->unk64_19 = 1;
        }
    } else {
        arg0->unk64_19 = 0;
    }
    if (!arg0->unk64_20) {
        func_808001F8_chwaterfallfx(arg0);
    }
}

s32 func_808001E4_chwaterfallfx(s32 arg0, s32 arg1, s32 arg2) 
{
    return 0;
}
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/waterfall/fx/func_808001F8_chwaterfallfx.s")
