#include "common.h"

OSThread *chspotlight_entrypoint_0(void)
{
    extern u8 D_808009B0_chspotlight[];

    return (OSThread *) D_808009B0_chspotlight;
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/spotlight/func_8080000C_chspotlight.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/spotlight/func_80800210_chspotlight.s")

/* extern */

void func_8080047C_chspotlight(Actor *arg0) {
    void func_800D93A0(f32[4], f32[3]);
    void func_800DF41C(s32);
    void func_800DF744(s32, s32);
    void func_800DFF2C(u8 **, s32, f32[4]);
    void func_800EFA4C(f32 *, f32, f32, f32);
    void *func_80100094(Actor *, u32);
    s32 func_801015D0(Actor *);
    s32 func_801040D0(void);
    s32 *sp3C;
    s32 sp38;
    f32 sp2C[3];
    f32 sp1C[4];

    sp3C = func_80100094(arg0, 0);
    sp38 = func_801040D0();
    func_801015D0(arg0);
    func_800DF41C(sp38);
    func_800EFA4C(sp2C, arg0->rotation[0] + 90.0f, 0.0f, 0.0f);
    func_800D93A0(sp1C, sp2C);
    func_800DFF2C((u8 **)sp38, 1, sp1C);
    func_800DF744(1, sp3C[9]);
}

/* extern */

void func_80800518_chspotlight(u8 *arg0, s32 arg1) {
    s32 pad[2];
    void* func_800DE448(f32* position, f32* arg1, f32 scale, f32* arg3, s32 arg4);
    void func_800DF47C(s32 arg0, s32 arg1);
    extern s32 func_801017D0;
    void func_80102780(void *arg0, void *arg1);
    s32 func_8010347C(s32);
    f32 sp2C;

    func_80102780(arg0, &sp2C);
    sp2C = 0.0f;
    func_800DF47C((s32) &func_801017D0, (s32) arg0);
    func_800DE448(arg0 + 4, &sp2C, (*(f32 *)((s8 *)(arg0) + (0x38))), NULL, func_8010347C((*(s32 *)((s8 *)(arg0) + (0)))));
}

/* extern */

void func_80800580_chspotlight(Actor *arg0) {
    f32 func_800D8FF8(void);
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    f32 *sp1C;
    Actor *sp18;
    f32 temp_f0;

    sp1C = func_80100094(arg0, 0);
    sp18 = func_80106790(arg0->unk3C);
    temp_f0 = func_800D8FF8();
    sp1C[10] += sp1C[11] * temp_f0;
    sp1C[12] += sp1C[13] * temp_f0;
    sp1C[14] = ((f32 *)sp18->actorData)[4] * 1500.0f;
}

void func_80800600_chspotlight(Actor *arg0, f32 arg1) {
    void func_800C8CB8(s32, f32[3]);
    void func_800C8E84(s32, u32[3]);
    f32 func_800EEAD4(f32 *, f32 *);
    void func_800EEC30(f32 *, f32, f32, f32);
    void func_800EF04C(f32 *, f32 *);
    int func_800F3214(void *, void *, void *, f32);
    void *func_80100094(Actor *, u32);
    extern u32 D_80800998_chspotlight[3];
    extern u32 D_808009A4_chspotlight[3];
    typedef struct {
        s32 light;
        f32 position[3];
        f32 direction[3];
    } SpotlightData;
    SpotlightData *data;
    u32 sp30[3];
    f32 distance;

    data = func_80100094(arg0, 0);
    distance = func_800EEAD4(arg0->position, data->position);
    func_800EEC30(data->direction, -arg0->rotation[0], arg0->rotation[1], distance);
    func_800EF04C(data->direction, arg0->position);
    if (data->light != 0) {
        func_800F3214(sp30, D_80800998_chspotlight, D_808009A4_chspotlight, arg1);
        func_800C8E84(data->light, sp30);
        func_800C8CB8(data->light, data->direction);
    }
}

void func_808006B8_chspotlight(Actor *arg0) {
    void func_800C8D4C(s32, f32 *);
    void *func_80100094(Actor *, u32);
    Actor *func_80106790(Unk80132ED0 *);
    extern f32 D_80800990_chspotlight[];
    s32 *sp24;
    f32 sp1C[2];
    Actor *temp_v0_2;

    sp24 = func_80100094(arg0, 0);
    if (*sp24 != 0) {
        temp_v0_2 = func_80106790(arg0->unk3C);
        sp1C[0] = D_80800990_chspotlight[0] * ((f32 *)temp_v0_2->actorData)[4];
        sp1C[1] = D_80800990_chspotlight[1] * ((f32 *)temp_v0_2->actorData)[4];
        func_800C8D4C(*sp24, sp1C);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/spotlight/func_80800730_chspotlight.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/ch/spotlight/func_808007F4_chspotlight.s")

/* extern */

s32 func_808008A4_chspotlight(void *arg0) {
    s32 func_800DA298(s32);
    if ((*(s32 *)((s8 *)(arg0) + (0x3C))) == 0) {
        return 0;
    }
    if (func_800DA298(3) != 0) {
        return 0;
    }
    return 1;
}

/* extern */

s32 *func_808008EC_chspotlight(u8 *arg0) {
    s32 *_subaddiefind_entrypoint_0(s32, s32, s32, s32);
    s32 *temp_v0;

    temp_v0 = _subaddiefind_entrypoint_0(arg0 + 4, 0x13C, -1, 0);
    if (temp_v0 != NULL) {
        (*(s32 *)((s8 *)(arg0) + (0x3C))) = (s32) *temp_v0;
    }
    return temp_v0;
}

u32 func_80800934_chspotlight(s32 unused, s32 arg1, s32 arg2) {
    void func_8080047C_chspotlight(Actor *);

    if (arg1 == 0x1F) {
        func_8080047C_chspotlight((Actor *) unused);
        return 1;
    }
    return 0;
}
