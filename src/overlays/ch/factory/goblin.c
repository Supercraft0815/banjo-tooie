#include "common.h"

OSThread *chfactorygoblin_entrypoint_0(void)
{
    extern ActorData D_80800298_chfactorygoblin[];

    return (OSThread *) D_80800298_chfactorygoblin;
}

/* extern */

void func_8080000C_chfactorygoblin(u8 *arg0) {
    void func_8010A3E8(void *arg0, f32 arg1);
    s32 _sucoaster_entrypoint_0(void *, s32);
    _sucoaster_entrypoint_0(arg0, 0);
    func_8010A3E8(arg0, 0.75f);
}

/* extern */

void func_8080003C_chfactorygoblin(BtIntPtr arg0, s32 arg1, s32 arg2) {
    s32 _sucoaster_entrypoint_21(Actor *arg0, s32 arg1, s32 arg2);
    s32 func_8080007C_chfactorygoblin();
    if (arg1 == 0xB6) {
        func_8080007C_chfactorygoblin();
    }
    _sucoaster_entrypoint_21(arg0, arg1, arg2);
}

s32 func_8080007C_chfactorygoblin(Actor *arg0) {
    BtIntPtr func_800B53A4(s32);
    BT_IDO_ONLY(BtIntPtr) BT_NATIVE_ONLY(void) func_800BABB8(BtIntPtr, f32[3], f32[3], f32, s32[]);
    s32 func_800DC128(s32, s32);
    void func_800EE7F8(f32 *, f32 *);
    void func_800EEB9C(f32[3], f32, f32);
    void func_800EF04C(f32 *, f32 *);
    void func_800EF1B8(f32 *, f32, f32);
    extern s32 D_808002E0_chfactorygoblin[16];
    f32 sp84[3];
    f32 sp78[3];
    f32 sp6C[3];
    BtIntPtr temp_s3;
    s32 temp_s4;
    s32 var_s1;

    temp_s4 = func_800DC128(6, 8);
    func_800EE7F8(sp84, arg0->position);
    func_800EF1B8(sp84, arg0->rotation[1], arg0->scale * 200.0f);
    func_800EE7F8(sp78, sp84);
    sp78[1] -= 5.0f;
    temp_s3 = func_800B53A4(temp_s4);
    var_s1 = 0;
    if (temp_s4 > 0) {
        do {
            func_800EEB9C(sp6C, (f32)var_s1 * (360.0f / (f32)temp_s4), 20.0f);
            func_800EF04C(sp6C, sp84);
            func_800BABB8(temp_s3, sp6C, sp78, arg0->scale * 0.5f, D_808002E0_chfactorygoblin);
            var_s1++;
        } while (var_s1 != temp_s4);
    } BT_NATIVE_ONLY(return 0;)
}
/* data_to_c.py: from asm/data/overlays/ch/factory/goblin.data.s */
extern u8 D_80800200_chfactorygoblin[];
void _sucoaster_entrypoint_2();
void func_80105834(Actor*);
void _sucoaster_entrypoint_20();
void _sucoaster_entrypoint_1();
OSThread *_sucoasterhit_entrypoint_0(void);
void func_80107C2C();
u8 D_80800200_chfactorygoblin[152] BT_DATA(4, overlays_ch_factory_goblin, 0x0) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x60, 0x00, 0x00, 0x03, 0x4E, 0x00, 0x01, 0x40, 0x60, 0x00, 0x00, 0x03, 0x4E, 0x00, 0x01, 0x3F, 0xA6, 0x66, 0x66, 0x03, 0x48, 0x00, 0x01, 0x3F, 0x4C, 0xCC, 0xCD, 0x03, 0x49, 0x00, 0x01, 0x3F, 0xA6, 0x66, 0x66, 0x03, 0x48, 0x00, 0x01, 0x3F, 0xA6, 0x66, 0x66, 0x03, 0x48, 0x00, 0x01, 0x3F, 0x80, 0x00, 0x00, 0x03, 0x4A, 0x00, 0x02, 0x3F, 0x4C, 0xCC, 0xCD, 0x03, 0x49, 0x00, 0x01, 0x3F, 0x80, 0x00, 0x00, 0x03, 0x4B, 0x00, 0x02, 0x3F, 0x4C, 0xCC, 0xCD, 0x03, 0x49, 0x00, 0x01, 0x3E, 0xCC, 0xCC, 0xCD, 0x03, 0x4D, 0x00, 0x02, 0x3F, 0xC0, 0x00, 0x00, 0x03, 0x4C, 0x00, 0x02, 0x3F, 0xC0, 0x00, 0x00, 0x03, 0x4C, 0x00, 0x84, 0x40, 0x60, 0x00, 0x00, 0x03, 0x4E, 0x00, 0x01, 0x40, 0x60, 0x00, 0x00, 0x03, 0x4E, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x60, 0x00, 0x00, 0x03, 0x4E, 0x00, 0x01, 0x3F, 0x4C, 0xCC, 0xCD, 0x03, 0x49, 0x00, 0x01 };
ActorData D_80800298_chfactorygoblin [1] BT_DATA(4, overlays_ch_factory_goblin, 0x98) = { { 806, 963, 2047, 1, (void *)D_80800200_chfactorygoblin, (void (*)(struct Actor *))_sucoaster_entrypoint_2, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))_sucoaster_entrypoint_20, 196608000, 1070386381, 0, 0, 17157, 809, (void (*)(struct Actor *))_sucoaster_entrypoint_1, (BtIntPtr)_sucoasterhit_entrypoint_0, 0, 0, (void (*)(struct Actor *))func_8080000C_chfactorygoblin, (void (*)(void *, long, void *, long, void *))func_80107C2C, -31694, 20509, (void (*)(struct Actor *, long, long))func_8080003C_chfactorygoblin, -2146286256 } };
s32 D_808002E0_chfactorygoblin[16] BT_DATA(4, overlays_ch_factory_goblin, 0xE0) = { 1903074, 1442562, 1376256, 12582955, 10027212, 2228300, 5832742, 3342381, 29491750, 720916, 1966090, 27, -52363864, 18481152, 0, 0 };
