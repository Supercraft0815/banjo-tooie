#include "common.h"

OSThread *chmrsboggyhome_entrypoint_0(void)
{
    extern ActorData D_808001F0_chmrsboggyhome[];

    return (OSThread *) D_808001F0_chmrsboggyhome;
}

/* extern */

void func_8080000C_chmrsboggyhome(BtIntPtr arg0) {
    s32 _glcutDll_entrypoint_20();
    s32 func_800DA298(s32);
    void func_800FFAB0(Actor *actor);
    void func_80102424(Actor *, s32);
    if (_glcutDll_entrypoint_20() != 0) {
        func_80102424(arg0, 3);
        return;
    }
    if (func_800DA298(0x1CD) == 0) {
        func_800FFAB0(arg0);
    }
}

/* extern */

void func_8080005C_chmrsboggyhome(Actor *arg0) {
    s32 _sudeflect_entrypoint_1(f32 *arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4);
    void _suexpression_entrypoint_10(u32 *, Unk80132ED0 *, BtUIntPtr);
    u32 *_suexpression_entrypoint_20(Actor *);
    void func_80800174_chmrsboggyhome(BtIntPtr);
    _sudeflect_entrypoint_1(arg0->position, 200.0f, 0.0f, 100.0f, 0xA);
    _suexpression_entrypoint_10(_suexpression_entrypoint_20(arg0), arg0->unk0, 0);
    if (arg0->unk70_10 == 1) {
        func_80800174_chmrsboggyhome(arg0);
    }
}

void func_808000D0_chmrsboggyhome(Actor* arg0) 
{
    _suexpression_entrypoint_8(arg0, 1);
}
s32 func_808000F0_chmrsboggyhome(Actor *arg0, s32 arg1, s32 arg2) {
    void func_80102424(Actor *, s32);
    void *_suexpression_entrypoint_7(Actor *arg0, s32 arg1, s16 arg2);
    void _suexpression_entrypoint_12(void *, f32, f32);
    void _suexpression_entrypoint_17(s16 *arg0, s32 arg1);
    void *expression;
    s32 *data = &arg2;

    switch (arg1) {
        case 0x2E:
            func_80102424(arg0, 1);
            break;
        case 0x95:
            expression = _suexpression_entrypoint_7(arg0, 1, 0x3E);
            _suexpression_entrypoint_12(expression, 60.0f, 20.0f);
            _suexpression_entrypoint_17(expression, 1000);
            break;
        default:
            return 0;
    }
    return 1;
}

void func_80800174_chmrsboggyhome(BtIntPtr arg0) {
    s32 _subaddiedialog_entrypoint_8(BtIntPtr, void *, s32 *, s32 *, s32);
    extern s32 D_808001B0_chmrsboggyhome[8];
    extern s32 D_80800238_chmrsboggyhome[6];
    _subaddiedialog_entrypoint_8(arg0, (s8 *)arg0 + 4, D_80800238_chmrsboggyhome, D_808001B0_chmrsboggyhome, 4);
}
/* data_to_c.py: from asm/data/overlays/ch/mrsboggyhome.data.s */
extern u8 D_808001D0_chmrsboggyhome[];
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
s32 D_808001B0_chmrsboggyhome[8] BT_DATA(4, overlays_ch_mrsboggyhome, 0x0) = { 513, 314245376, 1537, 314311168, 1024, 314245376, -73729, 302711552 };
u8 D_808001D0_chmrsboggyhome[32] BT_DATA(4, overlays_ch_mrsboggyhome, 0x20) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x06, 0x66, 0x66, 0x03, 0xEE, 0x00, 0x00, 0x40, 0x06, 0x66, 0x66, 0x03, 0xEE, 0x00, 0x00, 0x40, 0x06, 0x66, 0x66, 0x03, 0xEE, 0x00, 0x01 };
ActorData D_808001F0_chmrsboggyhome [1] BT_DATA(4, overlays_ch_mrsboggyhome, 0x40) = { { 344, 1072, 1719, 1, (void *)D_808001D0_chmrsboggyhome, (void (*)(struct Actor *))func_8080005C_chmrsboggyhome, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 1071644672, 0, 0, 0, 288, (void (*)(struct Actor *))func_808000D0_chmrsboggyhome, 0, 0, 0, (void (*)(struct Actor *))func_8080000C_chmrsboggyhome, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 1026, (void (*)(struct Actor *, long, long))func_808000F0_chmrsboggyhome, 0 } };
s32 D_80800238_chmrsboggyhome[6] BT_DATA(4, overlays_ch_mrsboggyhome, 0x88) = { 9109504, 26214462, 12, 104595968, 0, 0 };
