#include "common.h"

/* extern */

void func_80800000_chjigsawdance(Actor *arg0) {
    s32 func_800C8A98();
    void func_800C8CB8(s32, f32[3]);
    void func_800CF9E4(s32 arg0, s32 arg1, s32 arg2);
    s32 func_800CFA70(s32, s32);
    if (func_800CFA70((s32)arg0->unk50, 1) != -1) {
        arg0->unk6C_0 = func_800C8A98();
        func_800CF9E4((s32)arg0->unk50, 1, arg0->unk6C_0);
        func_800C8CB8(arg0->unk6C_0, arg0->position);
        return;
    }
    arg0->unk6C_0 = 0;
}

void func_808000AC_chjigsawdance(Actor *arg0) {
    void func_800C8B84(s32);
    if (arg0->unk6C_0 != 0) {
        func_800C8B84(arg0->unk6C_0);
        arg0->unk6C_0 = 0;
    }
}

typedef struct anctrl_s AnimCtrl;
f32 anctrl_getAnimTimer(AnimCtrl *);
int anctrl_getIndex(AnimCtrl *);
void anctrl_setDuration(AnimCtrl *, f32);
void anctrl_setIndex();
void anctrl_setSmoothTransition(AnimCtrl *, s32);
void anctrl_setStart(AnimCtrl *, f32);
void anctrl_start(AnimCtrl *);
AnimCtrl *func_8008FD20(void);
AnimCtrl *func_80104248(void *);

void func_808000F0_chjigsawdance(Actor *arg0) {
    void func_8008FE94(s32, f32 *);
    f32 func_80090010(void);
    void func_800C8B84(s32);
    void func_800C8CB8(s32, f32 *);
    f32 func_80101F24(Actor *);
    void func_8010D254(f32 *);
    AnimCtrl *playerControl;
    AnimCtrl *control;
    f32 position[3];

    if (arg0->unk6C_0 != 0) {
        if (func_80101F24(arg0) > 0.85f) {
            func_800C8B84(arg0->unk6C_0);
            arg0->unk6C_0 = 0;
        } else {
            func_8008FE94(7, position);
            func_800C8CB8(arg0->unk6C_0, position);
        }
    }
    switch (arg0->unk70_10) {
    case 1:
        break;
    case 2:
        func_8010D254(arg0->position);
        arg0->rotation[1] = func_80090010();
        playerControl = func_8008FD20();
        control = func_80104248(arg0);
        anctrl_setSmoothTransition(control, 0);
        anctrl_setIndex(control, anctrl_getIndex(playerControl));
        anctrl_setStart(control, anctrl_getAnimTimer(playerControl));
        anctrl_setDuration(control, 1000.0f);
        anctrl_start(control);
        break;
    case 3:
        playerControl = func_8008FD20();
        control = func_80104248(arg0);
        anctrl_setSmoothTransition(control, 0);
        anctrl_setStart(control, anctrl_getAnimTimer(playerControl));
        anctrl_setDuration(control, 1000.0f);
        anctrl_start(control);
        break;
    case 4:
        func_8010D254(arg0->position);
        arg0->rotation[1] = func_80090010();
        playerControl = func_8008FD20();
        control = func_80104248(arg0);
        anctrl_setSmoothTransition(control, 0);
        anctrl_setStart(control, anctrl_getAnimTimer(playerControl));
        anctrl_setDuration(control, 1000.0f);
        anctrl_start(control);
        break;
    }
}    typedef struct { u8 pad0[0x50]; f32 unk50; } Objdance_arg0; /* offsets.py genstruct: fields from raw offsets on arg0; rename once understood */

void chjigsawdance_entrypoint_0(void *arg0, s32 arg1) {
    (((Objdance_arg0 *)arg0)->unk50) = (f32) arg1;
}

void chjigsawdance_entrypoint_1(Actor *arg0, s32 arg1) {
    f32 anctrl_getAnimTimer(struct anctrl_s *);
    void anctrl_setDuration(struct anctrl_s *, f32);
    void anctrl_setPlaybackType(struct anctrl_s *, s32);
    void anctrl_setSmoothTransition(struct anctrl_s *, s32);
    void anctrl_setStart(struct anctrl_s *, f32);
    void anctrl_start(struct anctrl_s *);
    struct anctrl_s *func_8008FD20(void);
    f32 func_80090010(void);
    void func_800C8B84(s32);
    void func_800FFA88(Unk80132ED0 *);
    void func_80101FDC(Actor *, u32);
    struct anctrl_s *func_80104248(void *);
    void func_8010D254(f32 *);
    struct anctrl_s *control;

    switch (arg1) {
    case 3:
        if (arg0->unk70_10 == 1) {
            func_80101FDC(arg0, 2);
            anctrl_setPlaybackType(func_80104248(arg0), 1);
        }
        break;
    case 2:
        func_80101FDC(arg0, 3);
        break;
    case 1:
        func_80101FDC(arg0, 4);
        break;
    case 4:
        func_8010D254(arg0->position);
        arg0->rotation[1] = func_80090010();
        control = func_80104248(arg0);
        anctrl_setSmoothTransition(control, 0);
        anctrl_setStart(control, anctrl_getAnimTimer(func_8008FD20()));
        anctrl_setDuration(control, 1000.0f);
        anctrl_start(control);
        break;
    case 5:
        if (arg0->unk6C_0 != 0) {
            func_800C8B84(arg0->unk6C_0);
            arg0->unk6C_0 = 0;
        }
        func_800FFA88(arg0->unk0);
        break;
    }
}

OSThread *chjigsawdance_entrypoint_2(void)
{
    extern ActorData D_80800488_chjigsawdance[];

    return (OSThread *) D_80800488_chjigsawdance;
}
/* data_to_c.py: from asm/data/overlays/ch/jigsaw/dance.data.s */
extern u8 D_80800460_chjigsawdance[];
void func_80105834(Actor*);
void func_80101870(Actor* arg0, void* arg1);
void func_80107C2C();
u8 D_80800460_chjigsawdance[40] BT_DATA(4, overlays_ch_jigsaw_dance, 0x0) = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0xC0, 0x00, 0x00, 0x00, 0x76, 0x00, 0x00, 0x3F, 0xC0, 0x00, 0x00, 0x00, 0x76, 0x00, 0x00, 0x40, 0xA0, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00 };
ActorData D_80800488_chjigsawdance [1] BT_DATA(4, overlays_ch_jigsaw_dance, 0x28) = { { 104, 556, 1551, 1, (void *)D_80800460_chjigsawdance, (void (*)(struct Actor *))func_808000F0_chjigsawdance, (void (*)(struct Actor *))func_80105834, (void (*)(long, long))func_80101870, 0, 0, 0, 0, 0, 4, (void (*)(struct Actor *))func_808000AC_chjigsawdance, 0, 0, 0, (void (*)(struct Actor *))func_80800000_chjigsawdance, (void (*)(void *, long, void *, long, void *))func_80107C2C, -32768, 2, 0, 0 } };
